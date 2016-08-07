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
    
    func canAddConstraint(_ constraint: Type, solver: ConstraintSolver) -> Bool {
        if let solved = try? solver.solveConstraints(variable: self) {
            return solver.typeSatisfies(solved, constraint: constraint)
        }
        return true
    }
    
    func addConstraint(_ constraint: Type, solver: ConstraintSolver, customError: Error?) throws {
        
        // if this type variable has already been solved, we return
        // whether this type is substitutable
        if let solved = try? solver.solveConstraints(variable: self) {
            try solved.addConstraint(constraint, solver: solver, customError: customError)
            return
        }
        
        if case let concept as ConceptType = constraint {
            constraints.append(.satisfies(concept))
        }
        else if case let variable as TypeVariable = constraint {
            constraints.append(.sameVariable(variable))
            variable.constraints.append(.sameVariable(self))
        }
        else {
            constraints.append(.equal(constraint))
        }
    }
}
extension Type {
    // For normal types adding a constraint doesn't make sense. Because we have a concrete type
    // we instead check whehter they are substitutable
    func addConstraint(_ constraint: Type, solver: ConstraintSolver, customError: Error?) throws {
        guard solver.typeSatisfies(self, constraint: constraint) else {
            throw SemaError.couldNotAddConstraint(constraint: constraint, to: self)
        }
    }
    func canAddConstraint(_ constraint: Type, solver: ConstraintSolver) -> Bool {
        return solver.typeSatisfies(self, constraint: constraint)
    }
}
extension TypeVariable : Hashable {
    var hashValue: Int { return id }
    static func == (l: TypeVariable, r: TypeVariable) -> Bool {
        return l.id == r.id
    }
}
final class ConstraintSolver {
    
    private var counter = 0
    func getTypeVariable() -> TypeVariable {
        defer { counter += 1 }
        return TypeVariable(counter)
    }
    
    private var solvedConstraints: [TypeVariable: Type] = [:]
    
    func solveConstraints(variable: TypeVariable) throws -> Type {
        // if already solved, return it
        if let solved = solvedConstraints[variable] {
            return solved
        }
        /// Caches the solution and returns it
        func update(_ type: Type) -> Type {
            solvedConstraints[variable] = type
            return type
        }
        
        for case .equal(let concrete) in variable.constraints {
            return update(concrete)
        }
        for case .satisfies(let concept) in variable.constraints {
            return update(concept)
        }
        for case .sameVariable(let solved) in variable.constraints {
            return try update(solveConstraints(variable: solved))
        }
        
        // If couldn't substitute the type, throw
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
