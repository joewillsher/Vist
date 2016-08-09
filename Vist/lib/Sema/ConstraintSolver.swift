//
//  ConstraintSolver.swift
//  Vist
//
//  Created by Josef Willsher on 05/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class TypeVariable : Type {
    private let id: Int
    private(set) var constraints: [TypeConstraint] = []
    
    private init(_ id: Int) { self.id = id }
    
    var mangledName: String { return "tv\(id)" }
    var prettyName: String { return "$\(id)" }
    
    func lowered(module: Module) -> LLVMType { fatalError() }
    func importedType(in module: Module) -> Type { return self }
    func isInModule() -> Bool { fatalError() }
    var vir: String { return prettyName }
    
    func canAddConstraint(_ constraint: Type, solver: ConstraintSolver) -> Bool {
        if let solved = solver.solveConstraints(variable: self, satisfying: constraint) {
            return solver.typeSatisfies(solved, constraint: constraint) // a satisfiable constraint already exists for this type
        }
        return true
    }
    
    func addConstraint(_ typeConstraint: Type, solver: ConstraintSolver) throws {
        
        //// if this type variable has already been solved, we return
        //// whether this type is substitutable
        //if let solved = solver.solveConstraints(variable: self) {
        //    try solved.addConstraint(constraint, solver: solver)
        //    return
        //}
        
        for case .sameVariable(let other) in self.constraints {
            try other.addConstraint(typeConstraint, solver: solver)
        }
        
        if case let variable as TypeVariable = typeConstraint {
            variable.constraints.append(.sameVariable(self))
            constraints.append(.sameVariable(variable))
        }
        else if constraints.isEmpty {
            constraints.append(.disjoin([.equal(typeConstraint)]))
        }
        else {
            // update constraints
            constraints = constraints.map { constraint in
                let candidates = constraint.candidates() ?? []
                let newConstraint = TypeConstraint(type: typeConstraint)
                if candidates.isEmpty {
                    return newConstraint
                }
                else {
                    return .disjoin(candidates.map(TypeConstraint.init(type:)) + [newConstraint])
                }
            }
        }
    }
}
extension Type {
    // For normal types adding a constraint doesn't make sense. Because we have a concrete type
    // we instead check whehter they are substitutable
    func addConstraint(_ constraint: Type, solver: ConstraintSolver) throws {
        guard solver.typeSatisfies(self, constraint: constraint) else {
            throw SemaError.couldNotAddConstraint(constraint: constraint, to: self)
        }
    }
    func canAddConstraint(_ constraint: Type, solver: ConstraintSolver) -> Bool {
        return solver.typeSatisfies(self, constraint: constraint)
    }
}
extension FunctionType {
    func addConstraint(_ constraint: Type, solver: ConstraintSolver) throws {
        switch constraint {
        // if we are constraining this function to a type variable
        case let variable as TypeVariable:
            guard solver.typeSatisfies(self, constraint: variable) else {
                throw SemaError.couldNotAddConstraint(constraint: variable, to: self)
            }
            
        // if it is constrained to another function, check the params & return
        case let constraint as FunctionType:
            for (param, paramConstraint) in zip(self.params, constraint.params) {
                guard solver.typeSatisfies(param, constraint: paramConstraint) else {
                    throw SemaError.couldNotAddConstraint(constraint: constraint, to: self)
                }
            }
            guard solver.typeSatisfies(self.returns, constraint: constraint) else {
                throw SemaError.couldNotAddConstraint(constraint: constraint, to: self)
            }
            
        default:
            throw SemaError.couldNotAddConstraint(constraint: constraint, to: self)
        }
    }
    func canAddConstraint(_ constraint: Type, solver: ConstraintSolver) -> Bool {
        // can only constrain a function to another function or type variable
        switch constraint {
            // if we are constraining this function to a type variable
        case let variable as TypeVariable:
            return solver.typeSatisfies(self, constraint: variable)
            
            // if it is constrained to another function, check the params & return
        case let constraint as FunctionType:
            for (param, paramConstraint) in zip(self.params, constraint.params) {
                guard param.canAddConstraint(paramConstraint, solver: solver) else {
                    return false
                }
            }
            return returns.canAddConstraint(constraint.returns, solver: solver)
            
        default:
            return false
        }
        
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
    
    /// Try to repalce any type variables in `type`
    func solveConstraints(_ type: Type, satisfying: Type? = nil) throws -> Type {
        switch (type, satisfying) {
        case (let variable as TypeVariable, _):
            guard let solved = solveConstraints(variable: variable, satisfying: satisfying) else {
                throw semaError(.unsatisfiableConstraints(constraints: variable.constraints))
            }
            return solved
            
        case (let fn as FunctionType, let subst as FunctionType):
            return FunctionType(params: try zip(fn.params, subst.params).map(solveConstraints(_:satisfying:)),
                                returns: try solveConstraints(fn.returns, satisfying: subst.returns),
                                callingConvention: fn.callingConvention)
        default:
            return type
        }
    }
    /// - parameter satisfying: Can the constraints resolve to this type
    /// - returns: the type this was able to be constrained to
    func solveConstraints(variable: TypeVariable, satisfying: Type? = nil) -> Type? {
        
        if let solved = solvedConstraints[variable] {
            return solved
        }

        for constraint in variable.constraints {
            if let solved = constraint.solveConstraints(variable: variable, satisfying: satisfying, solver: self) {
                // cache answer
                solvedConstraints[variable] = solved
                return solved
            }
        }
        return nil
    }
}
extension TypeConstraint {
    
    /// - returns: the type this was able to be constrained to
    func solveConstraints(variable: TypeVariable, satisfying: Type?, solver: ConstraintSolver) -> Type? {
        
        switch self {
        case .disjoin(let set):
            // a disjoin set lists possibilities; if any one matches then we have a match
            for constraint in set {
                // is there a constraint in this set which is satisfiable?
                if let solved = constraint.solveConstraints(variable: variable, satisfying: satisfying, solver: solver) {
                    return solved
                }
            }
            
        case .equal(let concrete):
            // if the checker is requiring we satisfy one particular type, check that
            if let requirement = satisfying {
                guard solver.typeSatisfies(concrete, constraint: requirement) else { break }
            }
            return concrete
        case .sameVariable(let solved):
            guard let otherVariable = solver.solveConstraints(variable: solved, satisfying: satisfying) else { break }
            return otherVariable
        }
        
        return nil
    }
    
}



enum TypeConstraint {
    case equal(Type), sameVariable(TypeVariable)
    indirect case disjoin([TypeConstraint])
    
    init(overloads: [TypeConstraint]) {
        if overloads.count == 1 { self = overloads[0] }
        self = .disjoin(overloads)
    }
    init(type: Type) {
        if case let tv as TypeVariable = type {
            self = .sameVariable(tv)
        }
        else {
            self = .equal(type)
        }
    }
    
    var name: String {
        switch self {
        case .equal(let ty): return ty.prettyName
        case .sameVariable(let variable): return variable.prettyName
        case .disjoin(let overloads): return overloads.map { $0.name }.joined(separator: " or ")
        }
    }
    
    func candidates() -> [Type] {
        switch self {
        case .equal(let t): return [t]
        case .sameVariable(let tv): return [tv]
        case .disjoin(let constraints): return constraints.flatMap { $0.candidates() }
        }
    }
}

/*
extension _Typed {
    
    /// Rewrites any type variables in this node
    func rewriteType(to type: Type, solver: ConstraintSolver) throws -> Type {
        guard let ty = self._type else { throw semaError(.typeNotFound) }
        let subst = try solver.solveConstraints(ty, satisfying: type)
        self._type = subst
        return subst
    }
}
*/
