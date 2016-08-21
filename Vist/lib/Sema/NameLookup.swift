//
//  NameLookup.swift
//  Vist
//
//  Created by Josef Willsher on 13/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension Collection where
    Iterator.Element == (key: String, value: FunctionType)
{
    /// Look up the function from this mangled collection by the unmangled name and param types
    /// - returns: the mangled name and the type of the matching function
    func function(havingUnmangledName appliedName: String,
                  argTypes: [Type],
                  base: NominalType?,
                  solver: ConstraintSolver)
        -> Solution?
    {
        var solutions: [Solution] = []
        // type variables in the args means we have to search all overloads to
        // form the disjoin overload set
        let reqiresFullSweep = argTypes.contains(where: {$0 is TypeVariable})
        // the return type variable -- only used when we are sweeping the whole set
        let returnTv: TypeVariable! = reqiresFullSweep ? solver.getTypeVariable() : nil
        
        functionSearch: for (fnName, fnType) in self {
            
            // base names match and param counts are the same
            guard fnName.demangleName() == appliedName, argTypes.count == fnType.params.count else {
                continue functionSearch
            }
            // if it is a method, does the base satisfy the method's self type
            if let base = base {
                guard case .method(let parent) = fnType.callingConvention,
                    base.canAddConstraint(parent.selfType, solver: solver),
                    base == parent.selfType // Workaround: We need some way to prioritise Int.description over
                                            //             Printable.description; the @description_mPrintable
                                            //             function was getting chosen over the conformant
                    else { continue }
            }
            
            // arg types satisfy the params
            for (type, constraint) in zip(argTypes, fnType.params) {
                guard type.canAddConstraint(constraint, solver: solver) else {
                    continue functionSearch
                }
            }
            
            if reqiresFullSweep {
                // add the constraints
                for (type, constraint) in zip(argTypes, fnType.params) {
                    try! type.addConstraint(constraint, solver: solver)
                }
                try! returnTv.addConstraint(fnType.returns, solver: solver)
                
                if let base = base {
                    guard case .method(let parent) = fnType.callingConvention else { fatalError() }
                    try! parent.selfType.addConstraint(base, solver: solver)
                }
                
                let overload = (mangledName: appliedName.mangle(type: fnType), type: fnType)
                solutions.append(overload)
            }
            else {
                // if we are not using type variables, we can return the first
                // matching solution
                return (mangledName: appliedName.mangle(type: fnType), type: fnType)
            }
        }
        
        // if no overloads were found
        if solutions.isEmpty || !reqiresFullSweep { return nil }
        
        // the return type depends on the chosen overload
        let fnType = FunctionType(params: argTypes, returns: returnTv)
        // return the constrained solution
        return (mangledName: appliedName.mangle(type: fnType), type: fnType)
    }
}
