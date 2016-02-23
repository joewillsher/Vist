//
//  FnType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


struct FnType: Ty {
    let params: [Ty], returns: Ty
    var metadata: [String]
    let selfType: Ty?
    
    func globalType(module: LLVMModuleRef) -> LLVMTypeRef {
        
        let r: LLVMTypeRef
        if case _ as FnType = returns {
            r = BuiltinType.pointer(to: returns).globalType(module)
        }
        else {
            r = returns.globalType(module)
        }
        
        let members = nonVoid.map{$0.globalType(module)}
        let selfRef = selfType.map { [BuiltinType.pointer(to: $0).globalType(module)] } ?? []
        let els = (selfRef + members).ptr()
        let count = nonVoid.count + selfRef.count
        defer { els.dealloc(count) }
        
        return LLVMFunctionType(r, els, UInt32(count), false)
    }
    
    init(params: [Ty], returns: Ty = BuiltinType.void, metadata: [String] = [], selfType: Ty? = nil) {
        self.params = params
        self.returns = returns
        self.metadata = metadata
        self.selfType = selfType
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
            let mdString = LLVMMDString(metadata, attrLength)
            
            let attrs = [mdString].ptr()
            defer { attrs.dealloc(1) }
            let mdNode = LLVMMDNode(attrs, 1)
            
            let kindID = LLVMGetMDKindID(metadata, attrLength)
            
            LLVMSetMetadata(call, kindID, mdNode)
        }
    }
    
    var mangledName: String {
        return params
            .map { $0.mangledName }
            .joinWithSeparator("_")
    }
    
    /// Returns a version of this type, but with a defined parent
    func withParent(parent: StorageType) -> FnType {
        return FnType(params: params, returns: returns, metadata: metadata, selfType: parent)
    }
    /// Returns a version of this type, but with a parent of type i8 (so ptrs to it are i8*)
    func withOpaqueParent() -> FnType {
        return FnType(params: params, returns: returns, metadata: metadata, selfType: BuiltinType.int(size: 8))
    }
}





