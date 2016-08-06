//
//  ConstraintSolver.swift
//  Vist
//
//  Created by Josef Willsher on 05/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class TypeVariable : Type {
    private let id: Int
    var constraints: [TypeConstraint] = []
    
    private init(_ id: Int) { self.id = id }
    
    var mangledName: String { return "tv\(id)" }
    var prettyName: String { return "$\(id)" }
    
    func lowered(module: Module) -> LLVMType { fatalError() }
    func importedType(in module: Module) -> Type { return self }
    func isInModule() -> Bool { fatalError() }
    var vir: String { return prettyName }
    
    func addConstraint(type: Type) -> Bool {
        //func addConstraint<TypedNode: Typed>(type: Type, update: (TypedNode) -> ()) {
        if case let concept as ConceptType = type {
            constraints.append(.satisfies(concept))
        }
        else if case let variable as TypeVariable = type {
            constraints.append(.sameVariable(variable))
        }
        else {
            constraints.append(.equal(type))
        }
        return true
    }
}

extension TypeVariable : Hashable {
    var hashValue: Int { return id }
    static func == (l: TypeVariable, r: TypeVariable) -> Bool {
        return l.id == r.id
    }
}
extension Type {
    // For normal types adding a constraint doesn't make sense. Because we have a concrete type
    // we instead check whehter they are substitutable
    func addConstraint(type: Type) -> Bool {
        guard type == self else { return false }
        return true
    }
}

final class ConstraintSolver {
    
    private var counter = 0
    func getTypeVariable() -> TypeVariable {
        defer { counter += 1 }
        return TypeVariable(counter)
    }
    
    private var solvedConstraints: [TypeVariable: Type] = [:]
}

extension ConstraintSolver {
    
    func solveConstraints(variable: TypeVariable) throws -> Type {
        if let solved = solvedConstraints[variable] {
            return solved
        }
        
        func update(_ type: Type) -> Type {
            solvedConstraints[variable] = type
            return type
        }
        
        for case .sameVariable(let solved) in variable.constraints {
            return update(solved)
        }
        for case .equal(let concrete) in variable.constraints {
            return update(concrete)
        }
        for case .satisfies(let concept) in variable.constraints {
            return update(concept)
        }
        
        // If couldnt substitute the type, throw
        throw semaError(.unsatisfiableConstraints(constraints: variable.constraints))
    }
}



enum TypeConstraint {
    case equal(Type), satisfies(ConceptType), sameVariable(TypeVariable)
    
    var name: String {
        switch self {
        case .equal(let ty): return ty.prettyName
        case .sameVariable(let variable): return variable.prettyName
        case .satisfies(let concept): return concept.prettyName
        }
    }
}
