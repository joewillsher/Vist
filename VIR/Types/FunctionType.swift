//
//  FunctionType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct FunctionType : Type {
    var params: [Type], returns: Type
    var metadata: [String] // TODO: remove this, we're not using it
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
        
        var name: String {
            switch self {
            case .thin: return "&thin"
            case .method: return "&method"
            }
        }
        func importedType(inModule module: Module) -> CallingConvention {
            switch self {
            case .thin: return self
            case .method(let selfType, let mutating):
                return .method(selfType: selfType.importedType(inModule: module),
                               mutating: mutating)
            }
        }
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
    
    func lowered(module: Module) -> LLVMType {
        
        let ret: LLVMType
        if returns is FunctionType {
            ret = returns.lowered(module: module).getPointerType()
        }
        else {
            ret = returns.lowered(module: module)
        }
        
        let params = nonVoidParams.map {$0.lowered(module: module)}
        
        return LLVMType.functionType(params: params, returns: ret)
    }
    
    /// Replaces the function's memeber types with the module's typealias
    func importedType(inModule module: Module) -> Type {
        let params = self.params.map { $0.importedType(inModule: module) }
        let returns = self.returns.importedType(inModule: module)
        let convention = self.callingConvention.importedType(inModule: module)
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
            ret = BuiltinType.pointer(to: s.refCountedBox(module: module))
        }
        else {
            ret = returns
        }
        
        var t: FunctionType = self
        t.returns = ret
        
        t.params = params.map { param in
            if case let s as StructType = param where s.heapAllocated {
                return BuiltinType.pointer(to: s.refCountedBox(module: module))
            }
            else { return param }
        }
        
        switch callingConvention {
        case .thin:
            break
            
        case .method(let selfType, _):
            t.params.insert(BuiltinType.pointer(to: selfType), at: 0)
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
    
    private var nonVoidParams: [Type]  {
        return params.filter { if case BuiltinType.void = $0 { return false } else { return true } }
    }
    
    var mangledName: String {
        let conventionPrefix: String
        switch callingConvention {
        case .method(let selfType, _): // method
            conventionPrefix = "m" + selfType.mangledName
        case .thin: // thin
            conventionPrefix = "t"
        }
        return conventionPrefix + params
            .map { $0.mangledName }
            .joined(separator: "")
    }
    
    /// Returns a version of this type, but with a defined parent
    func asMethod(withSelf parent: NominalType, mutating: Bool) -> FunctionType {
        return FunctionType(params: params, returns: returns, metadata: metadata, callingConvention: .method(selfType: parent, mutating: mutating), yieldType: yieldType)
    }
    /// Returns a version of this type, but with a parent of type i8 (so ptrs to it are i8*)
    func asMethodWithOpaqueParent() -> FunctionType {
        return FunctionType(params: params, returns: returns, metadata: metadata, callingConvention: .method(selfType: BuiltinType.int(size: 8), mutating: false), yieldType: yieldType)
    }
}

extension FunctionType : Equatable { }

@warn_unused_result
func == (lhs: FunctionType, rhs: FunctionType) -> Bool {
    return lhs.params.elementsEqual(rhs.params, isEquivalent: ==) && lhs.returns == rhs.returns
}






