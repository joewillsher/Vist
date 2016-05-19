//
//  NominalType.swift
//  Vist
//
//  Created by Josef Willsher on 16/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

typealias StructMember = (name: String, type: Type, isMutable: Bool)
typealias StructMethod = (name: String, type: FunctionType, mutating: Bool)

/// A type which can have elements looked up by name,
/// for example structs and existential protocols
protocol NominalType : class, Type {
    /// User visible type name
    var name: String { get }
    
    var members: [StructMember] { get }
    var methods: [StructMethod] { get }
        
    /// Name this type is given at the global scope of IR
    var irName: String { get }
    
    var concepts: [ConceptType] { get }
    
    var heapAllocated: Bool { get }
}

extension NominalType {
    
    func indexOfMemberNamed(name: String) throws -> Int {
        guard let i = members.indexOf({ $0.name == name }) else {
            throw semaError(.noPropertyNamed(type: self.name, property: name))
        }
        return i
    }
    
    func indexOf(methodNamed name: String, argTypes: [Type]) throws -> Int {
        guard let i = methods.indexOf({
            $0.name == name && $0.type.params.elementsEqual(argTypes, isEquivalent: ==)
        }) else {
            throw semaError(.noPropertyNamed(type: self.name, property: name))
        }
        return i
    }
    func ptrToMethod(named name: String, type: FunctionType, inout IGF: IRGenFunction) -> LLVMFunction {
        return IGF.module.function(named: name.mangle(type))!
    }
    
    func ptrToMethodNamed(name: String, type: FunctionType, module: Module) throws -> LLVMFunction {
        guard let function = module.functionNamed(name.mangle(type)) else { fatalError() }
        return function.loweredFunction!
    }
    
    func propertyType(name: String) throws -> Type {
        return members[try indexOfMemberNamed(name)].type
    }
    func propertyIsMutable(name: String) throws -> Bool {
        return members[try indexOfMemberNamed(name)].isMutable
    }
    func methodType(methodNamed name: String, argTypes types: [Type]) throws -> FunctionType {
        let t =  methods[try indexOf(methodNamed: name, argTypes: types)]
        return t.type.withParent(self, mutating: t.mutating)
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
    
    func generatorFunction() -> FunctionType? {
        return methods.find { method in method.name == "generate" && method.type.isGeneratorFunction }?.type
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
