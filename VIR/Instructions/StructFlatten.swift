//
//  StructFlatten.swift
//  Vist
//
//  Created by Josef Willsher on 20/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 See through struct construct & extract insts
 
 ```
 %0 = int_literal 1 	// user: %1
 %1 = struct %Int, (%0: #Builtin.Int64) 	// user: %4
 %2 = int_literal 2 	// user: %3
 %3 = struct %Int, (%2: #Builtin.Int64) 	// user: %5
 %4 = struct_extract %1: #Int, !value 	// user: %i_add
 %5 = struct_extract %3: #Int, !value 	// user: %i_add
 %i_add = builtin i_add %4: #Builtin.Int64, %5: #Builtin.Int64 	// users: %overflow, %value
 %overflow = tuple_extract %i_add: (#Builtin.Int64, #Builtin.Bool), !1 	// user: %6
 cond_fail %overflow: #Builtin.Bool
 %value = tuple_extract %i_add: (#Builtin.Int64, #Builtin.Bool), !0 	// user: %7
 ```
 becomes
 ```
 %0 = int_literal 1 	// user: %i_add
 %1 = int_literal 2 	// user: %i_add
 %i_add = builtin i_add %0: #Builtin.Int64, %1: #Builtin.Int64 	// users: %overflow, %value
 %overflow = tuple_extract %i_add: (#Builtin.Int64, #Builtin.Bool), !1 	// user: %2
 cond_fail %overflow: #Builtin.Bool
 %value = tuple_extract %i_add: (#Builtin.Int64, #Builtin.Bool), !0 	// user: %3
 ```
 */
enum StructFlattenPass : OptimisationPass {

    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "struct-flatten"
    
    static func run(on function: Function) throws {

        // TODO: mem2reg after a memory location isnt worked on
        //  currently we don't mem2reg an alloc if there are any
        //  non load/stores -- this means initialisers arent worked
        //  on by this pass
        
        for inst in function.instructions {
            switch inst {
                // If we have a struct
            case let initInst as StructInitInst where initInst.isFlattenable():
                // get a map of struct member( name)s and the applied operand's value
                let args = zip(initInst.structType.members, initInst.args).map { member, arg in
                    (name: member.name, val: arg.value)
                }
                
                for extract in initInst.extracts() {
                    guard // get the value of the looked up member
                        let element = args.first(where: { arg in arg.name == extract.propertyName }),
                        let val = element.val else { fatalError() }
                    // replace the extract inst with the value
                    try extract.eraseFromParent(replacingAllUsesWith: val)
                }
                
                try initInst.eraseFromParent()

            case let allocInst as AllocInst where allocInst.isTrivialStructStorage():
                break
                /*
                 We can simplify struct memory, preds:
                 - Memory is struct type
                 - All insts are load/store/gep
                 - All gep instructions *only have* load/stores using them
                 */
                
            default:
                break
            }
        }
    }
}

private extension StructInitInst {
    
    /// Can this `struct` inst be flattened.
    ///
    /// - returns: `true` if all uses of this inst are `struct_element` or
    ///            `struct_extract` instructions which can be trivially 
    ///            replaced by the operands of this `struct` inst
    func isFlattenable() -> Bool {
        
        for use in uses {
            guard use.user is StructExtractInst else { return false }
        }
        
        return true
    }

    /// The store instructions using self
    func extracts() -> [StructExtractInst] {
        return uses.flatMap { $0.user as? StructExtractInst }
    }
}

private extension AllocInst {
    
    /// Is this allocated memory simply used to store a struct
    ///
    /// - returns: `true` if all uses are `struct_element` insts which 
    ///            are stored into/loaded from which can be replaced by
    ///            forwarding the values or `load` instructions which 
    ///            can forward a whole `struct` init inst which can be
    ///            trivially replaced by the operands of the
    func isTrivialStructStorage() -> Bool {
        return false
    }
    
}
