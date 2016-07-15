//
//  RegisterPromotionPass.swift
//  Vist
//
//  Created by Josef Willsher on 20/06/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 Promotes variables which aren't mutated to be a constant 
 passed in registers
 
 ```
 func @foo_tI : &thin (#Int) -> #Int {
$entry(%$0: #Int):
  %0 = alloc #Int 	// users: %1, %2
  store %$0 in %0: #*Int
  %2 = load %0: #*Int 	// user: %3
  return %2
}
 ```
 becomes
 ```
 func @foo_tI : &thin (#Int) -> #Int {
$entry(%$0: #Int):
  return %$0
}
 ```
*/
struct RegisterPromotionPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    
    static func run(on function: Function) throws {
        
        // http://llvm.org/docs/Passes.html#mem2reg-promote-memory-to-register
        // This file promotes memory references to be register references. It promotes alloca instructions which only
        // have loads and stores as uses. An alloca is transformed by using dominator frontiers to place phi nodes, then
        // traversing the function in depth-first order to rewrite loads and stores as appropriate. This is just the 
        // standard SSA construction algorithm to construct “pruned” SSA form.
        
        // TODO: Create a dominator tree, and move a block's value a BB param when removing the backing memory
        // http://pages.cs.wisc.edu/~fischer/cs701.f08/lectures/Lecture19.4up.pdf
        
        for case let allocInst as AllocInst in function.instructions where allocInst.isRegisterPromotable {
            
            let stores = allocInst.stores()
            precondition(stores.count <= 1,
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
//        return true
        
        // for now we only do it if there is 1 store
        // to do more requires constructing phi nodes/block applications
        guard stores().count <= 1 else { return false }
        
        return true
    }
}
