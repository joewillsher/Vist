//
//  FnType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


struct FnType : Ty {
    let params: [Ty]
    let returns: Ty
    
    func ir() -> LLVMTypeRef {
        
        let r: LLVMTypeRef
        if let _ = returns as? FnType {
            r = BuiltinType.Pointer(to: returns).ir()
        }
        else {
            r = returns.ir()
        }
        
        return LLVMFunctionType(
            r,
            nonVoid.map{$0.ir()}.ptr(),
            UInt32(nonVoid.count),
            LLVMBool(false))
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
}
