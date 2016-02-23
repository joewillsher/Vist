//
//  Ty.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol Ty: Printable {
    /// The type used in IR -- A vanilla type, agnostic of module
    /// if it is a builtin type. For structs, existentials etc
    /// this returns the globally named typealias
    func globalType(module: LLVMModuleRef) -> LLVMTypeRef
    
    /// Name used in mangling function signatures
    var mangledName: String { get }
    
    /// The explicit name of this type. The same as the
    /// mangled name, unless the mangled name uses a different
    /// naming system, like the builtin types
    var explicitName: String { get }
}

extension Ty {
    // implement default behaviour
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

// MARK: Cannonical equality functions, compares their module-agnostic type info

@warn_unused_result
func == <T: Ty> (lhs: T, rhs: T) -> Bool {
    return lhs.globalType(nil) == rhs.globalType(nil)
}
@warn_unused_result
func == <T: Ty> (lhs: Ty?, rhs: T) -> Bool {
    return lhs?.globalType(nil) == rhs.globalType(nil)
}

@warn_unused_result
func != (lhs: Ty, rhs: Ty) -> Bool {
    return !(lhs == rhs)
}

@warn_unused_result
func == (lhs: Ty, rhs: Ty) -> Bool {
    switch (lhs, rhs) {
    case (let l as StorageType, let r as ConceptType):
        return l.models(r)
    case (let l as ConceptType, let r as StorageType):
        return r.models(l)
    default:
        return lhs.globalType(nil) == rhs.globalType(nil)
    }
}

