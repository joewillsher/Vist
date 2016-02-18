//
//  Ty.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol Ty: Printable {
    func globalType(module: LLVMModuleRef) -> LLVMTypeRef
    
    /// Name used in mangling function signatures
    var mangledName: String { get }
    var explicitName: String { get }
}

extension Ty {
    var explicitName: String {
        return mangledName
    }
}

extension BuiltinType: Equatable {}
extension FnType: Equatable {}


@warn_unused_result
func == (lhs: StructType, rhs: StructType) -> Bool {
    return lhs.name == rhs.name
}



func globalType(module: LLVMModuleRef) -> Ty throws -> LLVMValueRef {
    return { val in
        return val.globalType(module)
    }
}



@warn_unused_result
func == <T: Ty> (lhs: T, rhs: T) -> Bool {
    return lhs.globalType(nil) == rhs.globalType(nil)
}
@warn_unused_result
func == <T: Ty> (lhs: Ty?, rhs: T) -> Bool {
    return lhs?.globalType(nil) == rhs.globalType(nil)
}
@warn_unused_result
func == (lhs: Ty, rhs: Ty) -> Bool {
    return lhs.globalType(nil) == rhs.globalType(nil)
}
@warn_unused_result
func != (lhs: Ty, rhs: Ty) -> Bool {
    return lhs.globalType(nil) != rhs.globalType(nil)
}
@warn_unused_result
func == (lhs: [Ty], rhs: [Ty]) -> Bool {
    if lhs.isEmpty && rhs.isEmpty { return true }
    if lhs.count != rhs.count { return false }
    
    for (l,r) in zip(lhs,rhs) {
        switch (l, r) {
        case (let l as StorageType, let r as ConceptType):
            return l.models(r)
        case (let l as ConceptType, let r as StorageType):
            return r.models(l)
        default:
            return l == r
        }
    }
    return false
}




