//
//  FnType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct FnType : Ty {
    var params: [Ty], returns: Ty
    var metadata: [String]
    let callingConvention: CallingConvention
    
    init(params: [Ty], returns: Ty = BuiltinType.void, metadata: [String] = [], callingConvention: CallingConvention = .thin) {
        self.params = params
        self.returns = returns
        self.metadata = metadata
        self.callingConvention = callingConvention
    }
    
    enum CallingConvention {
        case thin
        case method(selfType: Ty)
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
    
}


extension FnType {
    
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
    func usingTypesIn(module: Module) -> Ty {
        let params = self.params.map { $0.usingTypesIn(module) }
        let returns = self.returns.usingTypesIn(module)
        let convention = self.callingConvention.usingTypesIn(module)
        return FnType(params: params, returns: returns, metadata: metadata, callingConvention: convention)
    }
    

    /// The type used by the IR -- it uses info from the calling convention
    /// to construct the type which should be used in IR
    func vhirType(module: Module) -> FnType {
        
        let ret: Ty
        if case let s as StructType = returns where s.heapAllocated {
            ret = s.refCountedBox(module)
        }
        else {
            ret = returns
        }
        
        switch callingConvention {
        case .thin:
            return FnType(params: params,
                          returns: ret,
                          metadata: metadata,
                          callingConvention: .thin)
        case .method(let selfType):
            let selfPtr = BuiltinType.pointer(to: selfType)
            return FnType(params: [selfPtr] + params,
                          returns: returns,
                          metadata: metadata,
                          callingConvention: .method(selfType: selfType))
        }
    }
    
    static func taking(params: Ty..., ret: Ty = BuiltinType.void) -> FnType {
        return FnType(params: params, returns: ret)
    }
    static func returning(ret: Ty) -> FnType {
        return FnType(params: [], returns: ret)
    }
    
    var nonVoid: [Ty]  {
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
        return FnType(params: params, returns: returns, metadata: metadata, callingConvention: .method(selfType: parent))
    }
    /// Returns a version of this type, but with a parent of type i8 (so ptrs to it are i8*)
    func withOpaqueParent() -> FnType {
        return FnType(params: params, returns: returns, metadata: metadata, callingConvention: .method(selfType: BuiltinType.int(size: 8)))
    }
}

extension FnType : Equatable { }

@warn_unused_result
func == (lhs: FnType, rhs: FnType) -> Bool {
    return lhs.params.elementsEqual(rhs.params, isEquivalent: ==) && lhs.returns == rhs.returns
}






