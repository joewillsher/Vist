//
//  CopyElision.swift
//  Vist
//
//  Created by Josef Willsher on 31/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


enum CopyElisionPass : OptimisationPass {
    
    typealias PassTarget = Function
    // mandatory opt
    static let minOptLevel: OptLevel = .off
    static let name = "copy-elision"
    
    static let maxAttempts = 10
    
    static func run(on function: Function) throws {
        
        for block in function.dominator.analysis {
            
            instPass: for inst in block.instructions {
                
                switch inst {
                case let construct as ExistentialConstructInst:
                    // %2 = existential_construct %1: #Int in #Any 	// user: %3
                    // %3 = load %2: #*Any 	// user: %5
                    // %4 = alloc #Any 	// users: %5, %14, %15, %7
                    // store %3 in %4: #*Any // id: %5
                    //  - can be replaced with just the `existential_construct`
                    //    when there are no other uses of %2
                    guard construct.uses.count == 1, case let load as LoadInst = construct.uses.first?.user else {
                        continue instPass
                    }
                    guard load.uses.count == 1, case let store as StoreInst = load.uses.first?.user else {
                        continue instPass
                    }
                    guard case let alloc as AllocInst = store.address.value else {
                        continue instPass
                    }
                    try store.eraseFromParent()
                    try load.eraseFromParent()
                    try alloc.eraseFromParent(replacingAllUsesWith: construct)
                    
                case let copyAddr as CopyAddrInst:
                    // %2 = existential_construct %1: #Int in #Any 	// users: %11, %12, %4
                    // %3 = alloc #Any 	// users: %4, %6, %9, %10
                    // copy_addr %2: #*Any to %3: #*Any // id: %4
                    // %5 = alloc #Any 	// users: %6, %7
                    // copy_addr %3: #*Any to %5: #*Any // id: %6
                    // %7 = load %5: #*Any 	// user: %8
                    //  - a copy_addr inst who's only use is another copy_addr insts
                    //    can be folded to just 1 copy_addr
                    guard case let alloc as AllocInst = copyAddr.outAddr.value else {
                        continue instPass
                    }
                    // cannot elide copy_addr insts on ref counting insts, as this changes the semantics
                    guard !copyAddr.outAddr.memType!.isClassType() else {
                        continue instPass
                    }
                    for use in alloc.uses {
                        switch use.user {
                        case is CopyAddrInst, is DestroyAddrInst, is DeallocStackInst:
                            break // okay
                        default:
                            continue instPass
                        }
                    }
                    
                    // remove the alloc's deallocation insts
                    for use in alloc.uses where use.user is DestroyAddrInst || use.user is DeallocStackInst {
                        try use.user?.eraseFromParent()
                    }
                    // remove the alloc and replace with the copy inst's source memory
                    try alloc.eraseFromParent(replacingAllUsesWith: copyAddr.addr.value)
                    // erase the copy
                    try copyAddr.eraseFromParent()
                    
                default:
                    break
                }
                
            }
            
        }
        
        
    }
}
