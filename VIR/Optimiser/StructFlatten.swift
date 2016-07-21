//
//  StructFlatten.swift
//  Vist
//
//  Created by Josef Willsher on 20/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 ## See through struct construct, extract, and GEP insts
 
 ```
 %0 = int_literal 1
 %1 = int_literal 2
 %2 = struct %Int, (%0: #Builtin.Int64)
 %3 = struct %Int, (%1: #Builtin.Int64)
 %4 = struct_extract %2: #Int, !value
 %5 = struct_extract %3: #Int, !value
 %i_add = builtin i_add %4: #Builtin.Int64, %5: #Builtin.Int64
 ```
 becomes
 ```
 %0 = int_literal 1
 %1 = int_literal 2
 %i_add = builtin i_add %0: #Builtin.Int64, %1: #Builtin.Int64
 ```
 
 It can also handle indirect struct memory
 ```
 %self = alloc #_Range
 %a = struct_element %self: #*_Range, !a
 %b = struct_element %self: #*_Range, !b
 store %$0 in %a: #*Int
 store %$1 in %b: #*Int
 %2 = load %self: #*_Range
 ```
 becomes
 ```
 %0 = struct %_Range, (%$0: #Int, %$1: #Int)
 ```
 */
enum StructFlattenPass : OptimisationPass {

    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "struct-flatten"
    
    static func run(on function: Function) throws {
        
        for inst in function.instructions {
            instCheck: switch inst {
                // If we have a struct
            case let initInst as StructInitInst:
                var instanceMembers: [String: Value] = [:]
                
                // record the struct members
                for (member, arg) in zip(initInst.structType.members, initInst.args) {
                    instanceMembers[member.name] = arg.value!
                }
                
                for case let extract as StructExtractInst in initInst.uses.map({$0.user}) {
                    let member = instanceMembers[extract.propertyName]!
                    // replace the extract inst with the member
                    try extract.eraseFromParent(replacingAllUsesWith: member)
                }
                
                // If all struct users have been removed, remove the init
                if initInst.uses.isEmpty {
                    try initInst.eraseFromParent()
                }
                /*
                 We can simplify struct memory insts, given:
                 - Memory is struct type
                 - All insts are load/store/gep
                 - All gep instructions *only have* load/stores using them
                 */
            case let allocInst as AllocInst:
                // The memory must be of a struct type
                guard let storedType = try? allocInst.storedType.getAsStructType() else { break instCheck }
                var instanceMembers: [String: Value] = [:]
                
                // Check the memory's uses
                for use in allocInst.uses {
                    let user = use.user!
                    switch user {
                    // We allow stores...
                    case let store as StoreInst:
                        // ...only if we are storing a struct init...
                        guard case let initInst as StructInitInst = store.value.value else { break instCheck }
                        
                        // ...so record the members for use by gep insts...
                        for (member, arg) in zip(initInst.structType.members, initInst.args) {
                            instanceMembers[member.name] = arg.value
                        }
                        // ...and remove this inst
                        try initInst.eraseFromParent()
                        
                    // If the memory is used by a GEP inst...
                    case let gep as StructElementPtrInst:
                        for use in user.uses {
                            // ...the user must be a load/store -- we cannot optimise
                            // if a GEP pointer is passed as a func arg for exmaple
                            switch use.user {
                            case let load as LoadInst:
                                let member = instanceMembers[gep.propertyName]!
                                try load.eraseFromParent(replacingAllUsesWith: member)
                                
                            case let store as StoreInst:
                                instanceMembers[gep.propertyName] = store.value.value!
                                try store.eraseFromParent()
                                
                            default:
                                break instCheck
                                // TODO: how do we recover if we have already replaced a StoreInst
                            }
                        }
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

/*
 ASM CASE STUDY: the initialiser of
 ```
 type _Range {
    let a: Int, b: Int
 }
 ```
 Has ASM before:
 ```
 ## BEFORE
 "_-URange_tII":
	.cfi_startproc
	pushq	%rbp
 Ltmp3:
 .cfi_def_cfa_offset 16
 Ltmp4:
 .cfi_offset %rbp, -16
	movq	%rsp, %rbp
 Ltmp5:
	.cfi_def_cfa_register %rbp
    movq	%rdi, -16(%rbp) ## Work
    movq	%rsi, -8(%rbp)  ## ...
    movq	-16(%rbp), %rax ## ...
    movq	%rsi, %rdx      ## return
	popq	%rbp
	retq
	.cfi_endproc
 ```
 becomes
 ```
 "_-URange_tII":
	pushq	%rbp
	movq	%rsp, %rbp
    movq	%rdi, %rax ## All the work done is this 1 reg move inst
    movq	%rsi, %rdx ## return
    popq	%rbp
	retq
 ```
 */

