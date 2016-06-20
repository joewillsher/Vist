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
    static var minOptLevel: OptLevel = .low
    
    func run(on function: Function) throws {
        
        for case let allocInst as AllocInst in function.instructions where allocInst.isRegisterPromotable() {
            
            let stores = allocInst.stores()
            precondition(stores.count == 1,
                         "Mem2Reg only works with one store isnt, this should have been enforced in `AllocInst.isRegisterPromotable`")
            let store = stores[0]
            guard let storedValue = store.value.value else {
                throw OptError.invalidValue(store)
            }
            
            for load in allocInst.loads() {
                load.replaceAllUses(with: storedValue)
                try load.eraseFromParent()
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
    func isRegisterPromotable() -> Bool {
        for use in uses {
            guard use.user is LoadInst || use.user is StoreInst else { return false }
        }
//        return true
        
        // for now we only do it if there is 1 store
        guard stores().count <= 1 else { return false }
        
        return true
    }
}
