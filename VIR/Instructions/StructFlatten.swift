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
        
        var instanceMembers: [String: Value] = [:]
        
        for inst in function.instructions {
            instCheck: switch inst {
                // If we have a struct
            case let extractInst as StructExtractInst:
                guard case let initInst as StructInitInst = extractInst.object.value, initInst.isFlattenable() else { break instCheck }
                
                // get a map of struct member( name)s and the applied operand's value
                for (member, arg) in zip(initInst.structType.members, initInst.args) {
                    instanceMembers[member.name] = arg.value
                }
                
                for extract in initInst.extracts() {
                    let member = instanceMembers[extract.propertyName]!
                    // replace the extract inst with the value
                    try extract.eraseFromParent(replacingAllUsesWith: member)
                }
                
                try initInst.eraseFromParent()
                
                
                /*
                 We can simplify struct memory, preds:
                 - Memory is struct type
                 - All insts are load/store/gep
                 - All gep instructions *only have* load/stores using them
                 */
            case let allocInst as AllocInst:
                // The memory must be of a struct type
                guard let storedType = try? allocInst.storedType.getAsStructType() else { break instCheck }
                
                // Check the memory's uses
                for use in allocInst.uses {
                    // (nonnull user)
                    guard case let user as Inst = use.user else { break instCheck }
                    
                    switch user {
                    // We allow all loads
                    case is LoadInst:
                        let structMembers = storedType.members.map { member in
                            Operand(instanceMembers[member.name]!)
                        }
                        let val = StructInitInst(type: storedType,
                                                 operands: structMembers,
                                                 irName: nil)
                        try inst.parentBlock!.insert(inst: val, after: user)
                        try user.eraseFromParent(replacingAllUsesWith: val)
                        
                    // we allow stores...
                    case let store as StoreInst:
                        // ... if we are storing a struct init ...
                        guard case let initInst as StructInitInst = store.value.value else { break instCheck }
                        
                        // ...so record the members
                        for (member, arg) in zip(initInst.structType.members, initInst.args) {
                            instanceMembers[member.name] = arg.value
                        }
                        try initInst.eraseFromParent()
                        
                    // If the memory is used by a GEP inst...
                    case let gep as StructElementPtrInst:
                        for use in user.uses {
                            // ...the user must be a load/store -- we cannot optimise
                            // if a GEP pointer is passed as a func param, for exmaple
                            switch use.user {
                            case let load as LoadInst:
                                let member = instanceMembers[gep.propertyName]!
                                try load.eraseFromParent(replacingAllUsesWith: member)
                                
                            case let store as StoreInst:
                                instanceMembers[gep.propertyName] = store.value.value!
                                try store.eraseFromParent()
                                
                            default:
                                break instCheck
                            }
                        }
                        
                    // The memory can only be stored into, loaded from, or GEP'd
                    default:
                        break instCheck
                    }
                }
                
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
