//
//  RegisterPromotionPass.swift
//  Vist
//
//  Created by Josef Willsher on 20/06/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 ## Promotes variables which aren't mutated to be a constant
 passed in registers
 
 ```
 $entry(%$0: #Int):
   %0 = alloc #Int
   store %$0 in %0: #*Int
   %2 = load %0: #*Int
   return %2
 ```
 becomes
 ```
 $entry(%$0: #Int):
   return %$0
 ```
*/
struct RegisterPromotionPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    static let name = "mem2reg"
    
    let function: Function
    let dominatorTree: DominatorTree
    
    
    /// https://www.researchgate.net/profile/Jeanne_Ferrante/publication/225508360_Efficiently_computing_ph-nodes_on-the-fly/links/549458fd0cf22af911222521.pdf?origin=publication_detail
    /// http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.8.1979&rep=rep1&type=pdf
    /// https://github.com/apple/swift/blob/279726fe184400129664c3089160e00230cb485c/lib/SILOptimizer/Transforms/SILMem2Reg.cpp
    private init(function: Function) {
        self.function = function
        self.dominatorTree = function.dominator.analsis
        
        let frontierAnalysis = dominatorTree.dominatorFrontier()
        
        // 1 Compute DF sets for each node of the flow graph
        // 2 For each variable v, place trivial φ-functions in the nodes of
        //   the flow graph using the algorithm place-phi-function(v)
        // 3 Rename variables using the algorithm
        
        // φ-Placement Algorithm
        //  - The φ-placement algorithm picks the nodes ni with
        //    assignments to a variable
        //  - It places trivial φ-functions in all the nodes which are in
        //    DF(n_i), for each i
        //  - It uses a work list (i.e., queue) for this purpose
        
    }
    
    
    func placePhi() {
        
    }
}



extension RegisterPromotionPass {

    static func run(on function: Function) throws {
        
        //let pass = RegisterPromotionPass(function: function)
        
        // before handling memory, replace all VariableInst's with their values
        for case let varInst as VariableInst in function.instructions {
            let v = varInst.value.value!
            try varInst.eraseFromParent(replacingAllUsesWith: v)
        }
        
        // http://llvm.org/docs/Passes.html#mem2reg-promote-memory-to-register
        // This file promotes memory references to be register references. It promotes alloca instructions which only
        // have loads and stores as uses. An alloca is transformed by using dominator frontiers to place phi nodes, then
        // traversing the function in depth-first order to rewrite loads and stores as appropriate. This is just the 
        // standard SSA construction algorithm to construct “pruned” SSA form.
        
        // TODO: Create a dominator tree, and move a block's value a BB param when removing the backing memory
        // http://pages.cs.wisc.edu/~fischer/cs701.f08/lectures/Lecture19.4up.pdf
        
        for case let allocInst as AllocInst in function.instructions where allocInst.isRegisterPromotable {
            
            let stores = allocInst.stores()
            precondition(stores.count == 1,
                         "Mem2Reg currently only works with one store isnt, this should have been enforced in `AllocInst.isRegisterPromotable`")
            let store = stores[0]
            guard let storedValue = store.value.value else {
                throw OptError.invalidValue(store)
            }
            
            for load in allocInst.loads() {
                try load.eraseFromParent(replacingAllUsesWith: storedValue)
            }
            
            try store.eraseFromParent()
            try allocInst.eraseFromParent()
        }
    }
    
}



private extension AllocInst {
    
    /// The store instructions using self
    func stores() -> [StoreInst] {
        return uses.flatMap { $0.user as? StoreInst }
    }
    /// The store instructions using self
    func loads() -> [LoadInst] {
        return uses.flatMap { $0.user as? LoadInst }
    }
    
    /// Can this stack memory be promoted to register uses
    /// - note: returns true if the only uses are loads
    ///         and stores
    var isRegisterPromotable: Bool {
        for use in uses {
            guard use.user is LoadInst || use.user is StoreInst else { return false }
        }
        return true
    }
}
