//
//  FnType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct FnType : Type {
    var params: [Type], returns: Type
    var metadata: [String]
    let callingConvention: CallingConvention
    
    init(params: [Type], returns: Type = BuiltinType.void, metadata: [String] = [], callingConvention: CallingConvention = .thin, yieldType: Type? = nil) {
        self.params = params
        self.returns = returns
        self.metadata = metadata
        self.callingConvention = callingConvention
        self.yieldType = yieldType
    }
    
    enum CallingConvention {
        case thin
        case method(selfType: Type)
        //case thick(contextPtr: )
        
        var name: String {
            switch self {
            case .thin: return "thin"
            case .method: return "method"
            }
        }
        func usingTypesIn(module: Module) -> CallingConvention {
            switch self {
            case .thin: return self
            case .method(let selfType): return .method(selfType: selfType.usingTypesIn(module))
            }
        }
    }
    
    // Generator functions yield this type
    // use this field to store the return type as the producced signature is complicated
    var yieldType: Type?
    var isCanonicalType: Bool = false
}


extension FnType {
    // get the generator type of the function
    mutating func setGeneratorVariantType(yielding yieldType: Type) {
        guard case .method(let s) = callingConvention else { return }
        self = FnType(params: [BuiltinType.pointer(to: FnType(params: [yieldType], returns: BuiltinType.void, callingConvention: .thin, yieldType: nil))],
                      returns: BuiltinType.void, callingConvention: .method(selfType: s), yieldType: yieldType)
    }
    var isGeneratorFunction: Bool { return yieldType != nil }
    
    func lowerType(module: Module) -> LLVMTypeRef {
        
        let ret: LLVMTypeRef
        if case _ as FnType = returns {
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
        return FnType(params: params, returns: returns, metadata: metadata, callingConvention: convention, yieldType: yieldType)
    }
    
    
    /// The type used by the IR -- it lowers the calling convention
    func cannonicalType(module: Module) -> FnType {
        
        if isCanonicalType { return self }
        
        let ret: Type
        if case let s as StructType = returns where s.heapAllocated {
            ret = s.refCountedBox(module)
        }
        else {
            ret = returns
        }
        var t: FnType
        switch callingConvention {
        case .thin:
            t = FnType(params: params,
                          returns: ret,
                          metadata: metadata,
                          callingConvention: .thin,
                          yieldType: yieldType)
        case .method(let selfType):
            let selfPtr = BuiltinType.pointer(to: selfType)
            t = FnType(params: [selfPtr] + params,
                          returns: returns,
                          metadata: metadata,
                          callingConvention: .method(selfType: selfType),
                          yieldType: yieldType)
        }
        t.isCanonicalType = true
        return t
    }
    
    static func taking(params: Type..., ret: Type = BuiltinType.void) -> FnType {
        return FnType(params: params, returns: ret)
    }
    static func returning(ret: Type) -> FnType {
        return FnType(params: [], returns: ret)
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
        case .method(let selfType):
            conventionPrefix = "m" + selfType.mangledName
        case .thin:
            conventionPrefix = "t"
        }
        return conventionPrefix + params
            .map { $0.mangledName }
            .joinWithSeparator("")
    }
    
    /// Returns a version of this type, but with a defined parent
    func withParent(parent: StorageType) -> FnType {
        return FnType(params: params, returns: returns, metadata: metadata, callingConvention: .method(selfType: parent), yieldType: yieldType)
    }
    /// Returns a version of this type, but with a parent of type i8 (so ptrs to it are i8*)
    func withOpaqueParent() -> FnType {
        return FnType(params: params, returns: returns, metadata: metadata, callingConvention: .method(selfType: BuiltinType.int(size: 8)), yieldType: yieldType)
    }
}

extension FnType : Equatable { }

@warn_unused_result
func == (lhs: FnType, rhs: FnType) -> Bool {
    return lhs.params.elementsEqual(rhs.params, isEquivalent: ==) && lhs.returns == rhs.returns
}






