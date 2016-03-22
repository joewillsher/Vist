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
protocol StorageType: Ty {
    /// User visible type name
    var name: String { get }
    
    var members: [StructMember] { get }
    var methods: [StructMethod] { get }
        
    /// Name this type is given at the global scope of IR
    var irName: String { get }
}

extension StorageType {
        
    func indexOfMemberNamed(name: String) throws -> Int {
        guard let i = members.indexOf({ $0.name == name }) else { throw semaError(.noPropertyNamed(type: self.name, property: name)) }
        return i
    }
    
    func indexOfMethodNamed(name: String, argTypes: [Ty]) throws -> Int {
        guard let i = methods.indexOf({ $0.name == name && $0.type.params.elementsEqual(argTypes, isEquivalent: ==)})
            else { throw semaError(.noPropertyNamed(type: self.name, property: name)) }
        return i
    }
    
    func ptrToMethodNamed(name: String, type: FnType, module: LLVMModuleRef) -> LLVMValueRef {
        return ptrToFunction(name.mangle(type.params, parentTypeName: self.name), type: type, module: module)
    }
    
    func propertyType(name: String) throws -> Ty {
        return members[try indexOfMemberNamed(name)].type
    }
    func propertyMutable(name: String) throws -> Bool {
        return members[try indexOfMemberNamed(name)].mutable
    }
    func getMethodType(methodName: String, argTypes types: [Ty]) -> FnType? {
        return methods.find { $0.name == methodName && $0.type.params.elementsEqual(types, isEquivalent: ==) }?.type
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
}


extension CollectionType where Generator.Element == StructMethod {
    
    /// Lowers `StructMethod`s to `StorageVariableMethod`s
    func lower(selfType selfType: StorageType, module: LLVMModuleRef) -> [StorageVariableMethod] {
        return map { (mangledName: $0.name.mangle($0.type.params, parentTypeName: selfType.name), type: $0.type.withParent(selfType).lowerType(module)) }
    }
}

extension CollectionType where Generator.Element == StructMember {
    
    /// Lowers `StructMember`s to `StorageVariableProperty`s
    func lower(module module: LLVMModuleRef) -> [StorageVariableProperty] {
        return map { (name: $0.name, irType: $0.type.lowerType(module)) }
    }

}


