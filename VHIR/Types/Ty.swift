//
//  Ty.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol Ty: Printable, VHIRElement {
    
    /// Name used in mangling function signatures
    var mangledName: String { get }
    
    func lowerType(module: Module) -> LLVMTypeRef
    /// Replaces the function's memeber types with the module's typealias
    func usingTypesIn(module: Module) -> Ty
    
    
    /// Old type lowering function, dont call this outside of irgen
    func lowerType(m: LLVMModuleRef) -> LLVMValueRef
    
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
    
    func lowerType(m: LLVMModuleRef) -> LLVMValueRef {
        return lowerType(Module())
    }
}

extension BuiltinType: Equatable {}
extension FnType: Equatable {}

@warn_unused_result
func == (lhs: StructType, rhs: StructType) -> Bool {
    return lhs.name == rhs.name
}

func lowerType(module: LLVMModuleRef) -> Ty throws -> LLVMValueRef {
    return { val in
        return val.lowerType(module)
    }
}

// MARK: Cannonical equality functions, compares their module-agnostic type info

@warn_unused_result
func == (lhs: Ty?, rhs: Ty) -> Bool {
    if let l = lhs { return l == rhs } else { return false }
}
@warn_unused_result
func == (lhs: Ty?, rhs: Ty?) -> Bool {
    if let l = lhs, let r = rhs { return l == r } else { return false }
}
@warn_unused_result
func != (lhs: Ty?, rhs: Ty) -> Bool {
    if let l = lhs { return l != rhs } else { return false }
}
@warn_unused_result
func == (lhs: StructMember, rhs: StructMember) -> Bool {
    return lhs.name == rhs.name && lhs.type == rhs.type
}
@warn_unused_result
func == (lhs: StructMethod, rhs: StructMethod) -> Bool {
    return lhs.name == rhs.name && lhs.type == rhs.type
}
@warn_unused_result
func == (lhs: BuiltinType, rhs: BuiltinType) -> Bool {
    return lhs.explicitName == rhs.explicitName
}
@warn_unused_result
func == (lhs: FnType, rhs: FnType) -> Bool {
    return lhs.params.elementsEqual(rhs.params, isEquivalent: ==) && lhs.returns == rhs.returns
}
@warn_unused_result
func == (lhs: TupleType, rhs: TupleType) -> Bool {
    return lhs.members.elementsEqual(rhs.members, isEquivalent: ==)
}
@warn_unused_result
func == (lhs: TypeAlias, rhs: TypeAlias) -> Bool {
    return lhs.targetType == rhs.targetType
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
    case (let l as StorageType, let r as GenericType):
        return l.validSubstitutionFor(r)
    case (let l as GenericType, let r as StorageType):
        return r.validSubstitutionFor(l)
        
    case let (l as FnType, r as FnType):
        return r == l
    case (let lhs as StorageType, let rhs as StorageType):
        return lhs.name == rhs.name && lhs.members.elementsEqual(rhs.members, isEquivalent: ==) && lhs.methods.elementsEqual(rhs.methods, isEquivalent: ==)
    case let (l as BuiltinType, r as BuiltinType):
        return l == r
    case let (l as TupleType, r as TupleType):
        return l == r
    case let (l as TypeAlias, r as TypeAlias):
        return l == r
    default:
        return false
    }
}

