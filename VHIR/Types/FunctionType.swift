//
//  FunctionType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct FunctionType : Type {
    var params: [Type], returns: Type
    var metadata: [String]
    var callingConvention: CallingConvention
    
    init(params: [Type], returns: Type = BuiltinType.void, metadata: [String] = [], callingConvention: CallingConvention? = nil, yieldType: Type? = nil) {
        self.params = params
        self.returns = returns
        self.metadata = metadata
        // for some reason I cant use `callingConvention: CallingConvention = .thin` or it crashes
        self.callingConvention = callingConvention ?? .thin
        self.yieldType = yieldType
    }
    
    enum CallingConvention {
        case thin
        case method(selfType: Type, mutating: Bool)
//        case thickMethod(selfType: Type, mutating: Bool, capturing: [Type])
//        case thick(capturing: [Type])
        
        var name: String {
            switch self {
            case .thin: return "&thin"
            case .method: return "&method"
//            case .thickMethod: return "&thick &method"
//            case .thick: return "&thick"
            }
        }
        func usingTypesIn(module: Module) -> CallingConvention {
            switch self {
            case .thin: return self
            case .method(let selfType, let mutating):
                return .method(selfType: selfType.usingTypesIn(module),
                               mutating: mutating)
//            case .thick(let capturing):
//                return .thick(capturing: capturing.map { captureTy in captureTy.usingTypesIn(module) })
//            case .thickMethod(let selfType, let mutating, let capturing):
//                return .thickMethod(selfType: selfType.usingTypesIn(module),
//                                    mutating: mutating,
//                                    capturing: capturing.map { captureTy in captureTy.usingTypesIn(module) })
            }
        }
//        mutating func addCaptures(captures: Type...) {
//            
//            switch self {
//            case .thick(let c):
//                self = .thick(capturing: c + captures)
//            case .thin:
//                self = .thick(capturing: captures)
//            case .method(let s, let m):
//                self = .thickMethod(selfType: s, mutating: m, capturing: captures)
//            case .thickMethod(let s, let m, let c):
//                self = .thickMethod(selfType: s, mutating: m, capturing: c + captures)
//            }
//        }
    }
    
    // Generator functions yield this type
    // use this field to store the return type as the producced signature is complicated
    var yieldType: Type?
    var isCanonicalType: Bool = false
}


extension FunctionType {
    // get the generator type of the function
    mutating func setGeneratorVariantType(yielding yieldType: Type) {
        guard case .method(let s, let m) = callingConvention else { return }
        self = FunctionType(params: [BuiltinType.pointer(to:
                FunctionType(params: [yieldType],
                            returns: BuiltinType.void,
                            callingConvention: .thin,
                            yieldType: nil))],
                        returns: BuiltinType.void,
                        callingConvention: .method(selfType: s, mutating: m),
                        yieldType: yieldType)
    }
    var isGeneratorFunction: Bool { return yieldType != nil }
    
    func lowerType(module: Module) -> LLVMTypeRef {
        
        let ret: LLVMTypeRef
        if case _ as FunctionType = returns {
            ret = BuiltinType.pointer(to: returns).lowerType(module)
        }
        else {
            ret = returns.lowerType(module)
        }
        
        var members = nonVoid.map {$0.lowerType(module)}
        
        return LLVMFunctionType(ret, &members, UInt32(members.count), false)
    }
    
    /// Replaces the function's memeber types with the module's typealias
    func usingTypesIn(module: Module) -> Type {
        let params = self.params.map { $0.usingTypesIn(module) }
        let returns = self.returns.usingTypesIn(module)
        let convention = self.callingConvention.usingTypesIn(module)
        return FunctionType(params: params, returns: returns, metadata: metadata, callingConvention: convention, yieldType: yieldType)
    }
    
    
    /**
     The type used by the IR -- it lowers the calling convention
     
     The function arguments are lowered as follows:
     - Thick functions add their implicit context reference to the beginning
     of the paramether list
     - Methods add their implicit self parameter to the beginning of the param
     list. It is a pointer if the method is mutating or if self is a reference
     type. Otherwise self is passed by value
     */
    func cannonicalType(module: Module) -> FunctionType {
        
        if isCanonicalType { return self }
        
        let ret: Type
        if case let s as StructType = returns where s.heapAllocated {
            ret = s.refCountedBox(module)
        }
        else {
            ret = returns
        }
        
        var t: FunctionType = self
        t.returns = ret
        
        switch callingConvention {
        case .thin:
            break
//            
//        case .thick(let captured):
//            let captured = captured.map { BuiltinType.pointer(to: $0) as Type }
//            t.params.appendContentsOf(captured)
            
        case .method(let selfType, let mutating):
            // if ref type or mutating method pass self by ref
            let selfPtr = mutating || ((selfType as? StructType)?.heapAllocated ?? true)
                ? BuiltinType.pointer(to: selfType)
                : selfType
            t.params.insert(selfPtr, atIndex: 0)
//            
//        case .thickMethod(let selfType, let mutating, let captured):
//            let captured = captured.map { BuiltinType.pointer(to: $0) as Type }
//            let selfPtr = mutating || ((selfType as? StructType)?.heapAllocated ?? true)
//                ? BuiltinType.pointer(to: selfType)
//                : selfType
//            t.params.appendContentsOf(captured)
//            t.params.insert(selfPtr, atIndex: 0)
        }
        t.isCanonicalType = true
        return t
    }
    
    static func taking(params: Type..., ret: Type = BuiltinType.void) -> FunctionType {
        return FunctionType(params: params, returns: ret)
    }
    static func returning(ret: Type) -> FunctionType {
        return FunctionType(params: [], returns: ret)
    }
    
    var nonVoid: [Type]  {
        return params.filter { if case BuiltinType.void = $0 { return false } else { return true } }
    }
    
    func addMetadataTo(call: LLVMValueRef) {
        
        for metadata in self.metadata {
            
            let attrLength = UInt32(metadata.characters.count)
            var mdString = [LLVMMDString(metadata, attrLength)]
            let mdNode = LLVMMDNode(&mdString, 1)
            
            let kindID = LLVMGetMDKindID(metadata, attrLength)
            
            LLVMSetMetadata(call, kindID, mdNode)
        }
    }
    
    var mangledName: String {
        let conventionPrefix: String
        switch callingConvention {
        case .method(let selfType, _): // method
            conventionPrefix = "m" + selfType.mangledName
        case .thin: // thin
            conventionPrefix = "t"
//        case .thick(let capturing): // context & params
//            let n = capturing.map{$0.mangledName}
//            conventionPrefix = "c" + n.joinWithSeparator("") + "p"
//        case .thickMethod(let selfType, _, let capturing): // context & params
//            let n = capturing.map{$0.mangledName}
//            conventionPrefix = "m" + selfType.mangledName + "c" + n.joinWithSeparator("") + "p"
        }
        return conventionPrefix + params
            .map { $0.mangledName }
            .joinWithSeparator("")
    }
    
    /// Returns a version of this type, but with a defined parent
    func withParent(parent: StorageType, mutating: Bool) -> FunctionType {
        return FunctionType(params: params, returns: returns, metadata: metadata, callingConvention: .method(selfType: parent, mutating: mutating), yieldType: yieldType)
    }
    /// Returns a version of this type, but with a parent of type i8 (so ptrs to it are i8*)
    func withOpaqueParent() -> FunctionType {
        return FunctionType(params: params, returns: returns, metadata: metadata, callingConvention: .method(selfType: BuiltinType.int(size: 8), mutating: false), yieldType: yieldType)
    }
}

extension FunctionType : Equatable { }

@warn_unused_result
func == (lhs: FunctionType, rhs: FunctionType) -> Bool {
    return lhs.params.elementsEqual(rhs.params, isEquivalent: ==) && lhs.returns == rhs.returns
}






