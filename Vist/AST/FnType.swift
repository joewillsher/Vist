//
//  FnType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


struct FnType : Ty {
    let params: [Ty], returns: Ty
    var metadata: [String]
    
    func ir() -> LLVMTypeRef {
        
        let r: LLVMTypeRef
        if case _ as FnType = returns {
            r = BuiltinType.Pointer(to: returns).ir()
        }
        else {
            r = returns.ir()
        }
        
        return LLVMFunctionType(r,
            nonVoid.map{$0.ir()}.ptr(),
            UInt32(nonVoid.count),
            false)
    }
    
    init(params: [Ty], returns: Ty = BuiltinType.Void, metadata: [String] = []) {
        self.params = params
        self.returns = returns
        self.metadata = metadata
    }
    
    static func taking(params: Ty..., ret: Ty = BuiltinType.Void) -> FnType {
        return FnType(params: params, returns: ret)
    }
    static func returning(ret: Ty) -> FnType {
        return FnType(params: [], returns: ret)
    }
    
    var nonVoid: [Ty]  {
        return params.filter { if case BuiltinType.Void = $0 { return false } else { return true } }
    }
    
    func addMetadata(call: LLVMValueRef) {
        
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
    
}





