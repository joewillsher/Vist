//
//  Type.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

private var emptyModule = LLVMModuleCreateWithName("___null___")

protocol Type : Printable, VHIRElement {
    
    /// Name used in mangling function signatures
    var mangledName: String { get }
    
    func lowerType(module: Module) -> LLVMTypeRef
    /// Replaces the function's memeber types with the module's typealias
    func usingTypesIn(module: Module) -> Type
    
    /// The explicit name of this type. The same as the
    /// mangled name, unless the mangled name uses a different
    /// naming system, like the builtin types
    var explicitName: String { get }
}

extension Type {
    // implement default behaviour
    var explicitName: String {
        return mangledName
    }
    
    /// the size in bytes of this lowered type
    func size(module: Module) -> Int {
        let dataLayout = LLVMCreateTargetData(LLVMGetDataLayout(emptyModule))
        return Int(LLVMSizeOfTypeInBits(dataLayout, lowerType(module))) / 8
    }
}


// MARK: Cannonical equality functions, compares their module-agnostic type info

@warn_unused_result
func == (lhs: Type?, rhs: Type) -> Bool {
    if let l = lhs { return l == rhs } else { return false }
}
@warn_unused_result
func == (lhs: Type?, rhs: Type?) -> Bool {
    if let l = lhs, let r = rhs { return l == r } else { return false }
}
@warn_unused_result
func != (lhs: Type?, rhs: Type) -> Bool {
    if let l = lhs { return l != rhs } else { return false }
}

@warn_unused_result
func == (lhs: Type, rhs: Type) -> Bool {
    switch (lhs, rhs) {
    case (let l as StorageType, let r as ConceptType):
        return l.models(r)
    case (let l as ConceptType, let r as StorageType):
        return r.models(l)
    case (let l as StorageType, let r as GenericType):
        return l.validSubstitutionFor(r)
    case (let l as GenericType, let r as StorageType):
        return r.validSubstitutionFor(l)
        
    case let (l as FunctionType, r as FunctionType):
        return r == l
    case (let lhs as StorageType, let rhs as StorageType):
        return lhs.name == rhs.name
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

@warn_unused_result
func != (lhs: Type, rhs: Type) -> Bool {
    return !(lhs == rhs)
}

