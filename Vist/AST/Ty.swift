//
//  Ty.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol Ty : Printable, CustomDebugStringConvertible {
    func ir() -> LLVMTypeRef
    func globalType(module: LLVMModuleRef) -> LLVMTypeRef
    
    var mangledTypeName: String { get }
}

extension Ty {
    
    var mangledTypeName: String {
        return "\(description).ty"
    }
    
    func globalType(module: LLVMModuleRef) -> LLVMTypeRef {
        return ir()
    }
    
}


extension BuiltinType : Equatable {}
extension FnType: Equatable {}


@warn_unused_result
func == (lhs: StructType, rhs: StructType) -> Bool {
    return lhs.name == rhs.name
}



func ir(val: Ty) throws -> LLVMValueRef {
    return val.ir()
}

func globalType(module: LLVMModuleRef) -> (Ty) throws -> LLVMValueRef {
    return { val in
        return val.globalType(module)
    }
}



@warn_unused_result
func == <T : Ty> (lhs: T, rhs: T) -> Bool {
    return lhs.ir() == rhs.ir()
}
@warn_unused_result
func == <T : Ty> (lhs: Ty?, rhs: T) -> Bool {
    return lhs?.ir() == rhs.ir()
}
@warn_unused_result
func == (lhs: Ty, rhs: Ty) -> Bool {
    return lhs.ir() == rhs.ir()
}
@warn_unused_result
func != (lhs: Ty, rhs: Ty) -> Bool {
    return lhs.ir() != rhs.ir()
}
@warn_unused_result
func == (lhs: [Ty], rhs: [Ty]) -> Bool {
    if lhs.isEmpty && rhs.isEmpty { return true }
    if lhs.count != rhs.count { return false }
    
    for (l,r) in zip(lhs,rhs) {
        if l == r { return true }
    }
    return false
}




