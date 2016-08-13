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
    
    var isHeapAllocated: Bool { get }
}

extension NominalType {
    
    var prettyName: String { return name }
    
    func index(ofMemberNamed memberName: String) throws -> Int {
        guard let i = members.index(where: { $0.name == memberName }) else {
            throw semaError(.noPropertyNamed(type: self.name, property: memberName))
        }
        return i
    }
    
    func index(ofMethodNamed methodName: String, argTypes: [Type]) throws -> Int {
        guard let i = methods.index(where: {
            $0.name == methodName && $0.type.params.elementsEqual(argTypes, by: ==)
        }) else {
            throw semaError(.noMethodNamed(type: self.name, property: methodName))
        }
        return i
    }
    
    func propertyType(name: String) throws -> Type {
        return try members[index(ofMemberNamed: name)].type
    }
    func propertyIsMutable(name: String) throws -> Bool {
        return try members[index(ofMemberNamed: name)].isMutable
    }
    func methodType(methodNamed name: String, argTypes types: [Type]) throws -> FunctionType {
        let t = try methods[index(ofMethodNamed: name, argTypes: types)]
        return t.type.asMethod(withSelf: self, mutating: t.mutating)
    }
    
    /// Returns whether a type models a concept
    func models(concept: ConceptType) -> Bool {
        // TODO: explicit, opt into methods, this should be a check in sema
        for conceptFn in concept.requiredFunctions where !methods.contains(where: {
            $0.name.demangleName() == conceptFn.name.demangleName() && $0.type == conceptFn.type
        }) {
            return false
        }
        for conceptProp in concept.requiredProperties where !members.contains(where: {
            $0.name == conceptProp.name && $0.type == conceptProp.type // TODO: property type *satisfies* concept type, not is equal to
        }) {
            return false
        }
        return true
    }
    func validSubstitutionFor(generic: GenericType) -> Bool {
        return generic.concepts.map(models).contains(false)
    }
    
    func generatorFunction() -> FunctionType? {
        return methods.first { method in method.name.demangleName() == "generate" && method.type.isGeneratorFunction }?.type
    }
    
    func refCountedBox(module: Module) -> Type {
        return StructType(members: [("object", BuiltinType.pointer(to: importedType(in: module)), true),
                                    ("refCount", BuiltinType.int(size: 32), false)],
                          methods: methods,
                          name: "\(name).refcounted",
                          concepts: concepts,
                          isHeapAllocated: true)
            .importedType(in: module)
    }
}

func == (lhs: StructMember, rhs: StructMember) -> Bool {
    return lhs.name == rhs.name && lhs.type == rhs.type
}

func == (lhs: StructMethod, rhs: StructMethod) -> Bool {
    return lhs.name == rhs.name && lhs.type == rhs.type
}
