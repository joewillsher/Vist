//
//  StorageType.swift
//  Vist
//
//  Created by Josef Willsher on 16/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

typealias StructMember = (name: String, type: Ty, mutable: Bool)
typealias StructMethod = (name: String, type: FnType)

/// A type which can have elements looked up by name,
/// for example structs and existential protocols
protocol StorageType : Ty {
    /// User visible type name
    var name: String { get }
    
    var members: [StructMember] { get }
    var methods: [StructMethod] { get }
        
    /// Name this type is given at the global scope of IR
    var irName: String { get }
    
    var heapAllocated: Bool { get }
}

extension StorageType {
        
    func indexOfMemberNamed(name: String) throws -> Int {
        guard let i = members.indexOf({ $0.name == name }) else {
            throw semaError(.noPropertyNamed(type: self.name, property: name))
        }
        return i
    }
    
    func indexOf(methodNamed name: String, argTypes: [Ty]) throws -> Int {
        guard let i = methods.indexOf({ $0.name == name && $0.type.params.elementsEqual(argTypes, isEquivalent: ==)})
            else { throw semaError(.noPropertyNamed(type: self.name, property: name)) }
        return i
    }
    
    func ptrToMethodNamed(name: String, type: FnType, module: Module) throws -> LLVMValueRef {
        guard let function = module.functionNamed(name.mangle(type)) else { fatalError() }
        return function.loweredFunction
    }
    
    func propertyType(name: String) throws -> Ty {
        return members[try indexOfMemberNamed(name)].type
    }
    func propertyMutable(name: String) throws -> Bool {
        return members[try indexOfMemberNamed(name)].mutable
    }
    func methodType(methodNamed name: String, argTypes types: [Ty]) throws -> FnType {
        let t =  methods[try indexOf(methodNamed: name, argTypes: types)].type
        return t.withParent(self)
    }
    
    /// Returns whether a type models a concept
    func models(concept: ConceptType) -> Bool {
        // TODO: explicit, opt into methods, this should be a check in sema
        for f in concept.requiredFunctions where !methods.contains({ $0.name == f.name && $0.type == f.type }) { return false }
        for p in concept.requiredProperties where !members.contains({ $0.name == p.name && $0.type == p.type }) { return false }
        return true
    }
    func validSubstitutionFor(generic: GenericType) -> Bool {
        return generic.concepts.map(models).contains(false)
    }
    
    func generatorFunction() -> FnType? {
        return methods.find { method in (method.name == "generate") && method.type.params.isEmpty && (method.type.returns != BuiltinType.void) }?.type
    }
}


@warn_unused_result
func == (lhs: StructMember, rhs: StructMember) -> Bool {
    return lhs.name == rhs.name && lhs.type == rhs.type
}
@warn_unused_result
func == (lhs: StructMethod, rhs: StructMethod) -> Bool {
    return lhs.name == rhs.name && lhs.type == rhs.type
}
