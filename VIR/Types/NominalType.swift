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
    
    func index(ofMemberNamed memberName: String) throws -> Int {
        guard let i = members.index(where: { $0.name == memberName }) else {
            throw semaError(.noPropertyNamed(type: self.name, property: memberName))
        }
        return i
    }
    
    func index(ofMethodNamed methodName: String, argTypes: [Type]) throws -> Int {
        guard let i = methods.index(where: {
            $0.name == methodName && $0.type.params.elementsEqual(argTypes, isEquivalent: ==)
        }) else {
            throw semaError(.noMethodNamed(type: self.name, property: methodName))
        }
        return i
    }
    func ptrToMethod(named name: String, type: FunctionType, IGF: inout IRGenFunction) -> LLVMFunction {
        return IGF.module.function(named: name.mangle(type: type))!
    }
    
    func ptrToMethodNamed(name: String, type: FunctionType, module: Module) throws -> LLVMFunction {
        guard let function = module.function(named: name.mangle(type: type)) else { fatalError() }
        return function.loweredFunction!
    }
    
    func propertyType(name: String) throws -> Type {
        return try members[index(ofMemberNamed: name)].type
    }
    func propertyIsMutable(name: String) throws -> Bool {
        return try members[index(ofMemberNamed: name)].isMutable
    }
    func methodType(methodNamed name: String, argTypes types: [Type]) throws -> FunctionType {
        let t =  methods[try index(ofMethodNamed: name, argTypes: types)]
        return t.type.asMethod(withSelf: self, mutating: t.mutating)
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
        return methods.first { method in method.name == "generate" && method.type.isGeneratorFunction }?.type
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
