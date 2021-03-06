//
//  Flatten.swift
//  Vist
//
//  Created by Josef Willsher on 22/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 ## See through struct and tuple construct, extract, and GEP insts
 
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
enum AggrFlattenPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "aggr-flatten"
    
    static let maxAttempts = 10
    
    static func run(on function: Function) throws {
        guard function.hasBody else { return }
        
        // First remove all variable insts
        
        let tree = function.dominator.analysis
        
        // run the opt pass while it still wants change
        for block in tree where !block.instructions.isEmpty {
            var attempt = 0
            
            while let tryAgainBlock = try runAggrOpt(block), attempt < maxAttempts {
                attempt += 1
                if tryAgainBlock != block {
                    try optimiseAncestors(of: block, tree: tree)
                }
            }
        }
        
    }
    
    private static func optimiseAncestors(of block: BasicBlock, tree: DominatorTree) throws {
        for ancestor in tree.ancestors(of: tree.getNode(for: block)) {
            if let again = try runAggrOpt(ancestor.block) {
                try optimiseAncestors(of: again, tree: tree)
            }
        }
    }
    
    
    /// - returns: if not nil, the inst to try optimising again from
    private static func runAggrOpt(_ block: BasicBlock) throws -> BasicBlock? {
        
        for thisInst in block.instructions {
            
            var returnAndGoAgainInst: Inst?
            
            var inst = thisInst
            
            if case let variable as VariableInst = inst,
                case let i as Inst = variable.value.value {
                inst = i
            } else if case let variable as VariableAddrInst = inst,
                case let i as Inst = variable.addr.value {
                inst = i
            }
            
            
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
                    
                    // if the element is a tuple/struct -- we may have missed an optimisation
                    // opportunity; try again from there after flattening this
                    if case let inst as TupleCreateInst = member {
                        returnAndGoAgainInst = inst
                    }
                    else if case let inst as StructInitInst = member  {
                        returnAndGoAgainInst = inst
                    }
                    
                }
                // If all struct users have been removed and it has not, remove the init
                if initInst.uses.isEmpty {
                    try initInst.eraseFromParent()
                    OptStatistics.structInitsFlattened += 1
                }
                
            case let createInst as TupleCreateInst:
                var tupleMembers = createInst.args.map { $0.value! }
                
                for case let extract as TupleExtractInst in createInst.uses.map({$0.user}) {
                    let member = tupleMembers[extract.elementIndex]
                    // replace the extract inst with the member
                    try extract.eraseFromParent(replacingAllUsesWith: member)
                    
                    // if the element is a tuple/struct -- we may have missed an optimisation
                    // opportunity; try again from there after flattening this
                    if case let inst as TupleCreateInst = member {
                        returnAndGoAgainInst = inst
                    }
                    else if case let inst as StructInitInst = member  {
                        returnAndGoAgainInst = inst
                    }
                }
                
                // If all struct users have been removed and it has not, remove the init
                if inst.uses.isEmpty {
                    try inst.eraseFromParent()
                    OptStatistics.tupleInitsFlattened += 1
                }
                
                // If we hit a struct or tuple which takes an struct/tuple init
                // try again from that point
            case let ex as StructExtractInst:
                guard case let create as StructInitInst = ex.object.value else { break instCheck }
                returnAndGoAgainInst = create
            case let ex as TupleExtractInst:
                guard case let create as TupleCreateInst = ex.tuple.value else { break instCheck }
                returnAndGoAgainInst = create
                                
                /*
                 We can simplify struct memory insts, given:
                 - Memory is struct type
                 - All insts are load/store/gep
                 - All gep instructions *only have* load/stores using them
                 */
            case let allocInst as AllocInst:
                // The memory must be of a struct/tuple type
                guard let storedType = allocInst.storedType.getAggregateType() else { break instCheck }
                guard allocInst.isFlattenable() else {
                    break instCheck
                }
                
                // TODO: create a dominator tree
                var structMembers: [String: Value] = [:]
                var tupleMembers: [Int: Value] = [:]
                var uses = allocInst.uses
                
                // Check the memory's uses
                for use in uses {
                    let user = use.user!
                    switch user {
                    // We allow stores...
                    case let store as StoreInst:
                        
                        guard case let initInst as Inst = store.value.value else { break instCheck }
                        // ...so record the members for use by gep insts...
                        switch initInst {
                        case let initInst as StructInitInst:
                            for (member, arg) in zip(initInst.structType.members, initInst.args) {
                                structMembers[member.name] = arg.value
                            }
                        case let createInst as TupleCreateInst:
                            for (index, arg) in zip(0..<createInst.tupleType.members.count, createInst.args) {
                                tupleMembers[index] = arg.value
                            }
                        default:
                            break instCheck
                        }
                        
                        // ...and remove this inst
                        try initInst.eraseFromParent()
                        try store.eraseFromParent()
                        
                    // If the memory is used by a GEP inst...
                    case let gep as StructElementPtrInst:
                        
                        // if the element of the tuple is a struct, we may have missed
                        // an optimisation opportunity, make sure we go back go back over it
                        if gep.propertyType.isTupleType(),
                            case let mem as Inst = gep.object.value {
                            returnAndGoAgainInst = mem
                        }

                        for use in user.uses {
                            // ...the user must be a load/store -- we cannot optimise
                            // if a GEP pointer is passed as a func arg for exmaple
                            switch use.user {
                            case let load as LoadInst:
                                let member = structMembers[gep.propertyName]!
                                try load.eraseFromParent(replacingAllUsesWith: member)
                                
                            case let store as StoreInst:
                                structMembers[gep.propertyName] = store.value.value!
                                try store.eraseFromParent()
                                
                            default:
                                break instCheck
                                // TODO: how do we recover if we have already replaced a StoreInst
                            }
                        }
                        try gep.eraseFromParent()
                        
                    case let gep as TupleElementPtrInst:
                        
                        // if the element of the tuple is a struct, we may have missed
                        // an optimisation opportunity, make sure we go back go back over it
                        if gep.elementType.isStructType(),
                            case let mem as Inst = gep.tuple.value {
                            returnAndGoAgainInst = mem
                        }
                        
                        for use in user.uses {
                            // ...the user must be a load/store -- we cannot optimise
                            // if a GEP pointer is passed as a func arg for exmaple
                            switch use.user {
                            case let load as LoadInst:
                                let member = tupleMembers[gep.elementIndex]!
                                try load.eraseFromParent(replacingAllUsesWith: member)
                                
                            case let store as StoreInst:
                                tupleMembers[gep.elementIndex] = store.value.value!
                                try store.eraseFromParent()
                                
                            default:
                                break instCheck
                                // TODO: how do we recover if we have already replaced a StoreInst
                            }
                        }
                        try gep.eraseFromParent()
                        
                    // We allow all loads
                    case is LoadInst:
                        
                        let val: Inst
                        switch storedType {
                        case .struct(let structType):
                            let structMembers = structType.members.map { member in
                                Operand(structMembers[member.name]!)
                            }
                            val = StructInitInst(type: structType,
                                                 operands: structMembers,
                                                 irName: nil)
                        case .tuple(let tupleType):
                            let members = (0..<tupleType.members.count).map {
                                tupleMembers[$0]!
                            }
                            val = TupleCreateInst(type: tupleType, elements: members)
                        }
                        
                        try user.parentBlock!.insert(inst: val, after: user)
                        try user.eraseFromParent(replacingAllUsesWith: val)
                        
                        // remove the deallocation
                    case is DeallocStackInst:
                        try use.user?.eraseFromParent()
                        
                    case let addr as VariableAddrInst:
                        uses.append(contentsOf: addr.uses)
                        try addr.eraseFromParent()
                        
                    // The memory can only be stored into, loaded from, or GEP'd
                    default:
                        break instCheck
                    }
                }
                
                try allocInst.eraseFromParent()
                OptStatistics.aggrMemoryFlattened += 1
                
                
            default:
                continue
            }
            
            if let i = returnAndGoAgainInst {
                return i.parentBlock!
            }
            
        }
        
        return nil
    }
}

private enum AggregateType {
    case `struct`(StructType), tuple(TupleType)
}

private extension Type {
    func getAggregateType() -> AggregateType? {
        return (try? getAsStructType()).map({.`struct`($0)})
            ?? (try? getAsTupleType()).map({.tuple($0)})
    }
}

extension Inst {
    func isFlattenable() -> Bool {
        var hasHadStore = false
        
        for use in uses {
            let user = use.user!
            switch user {
            // We allow stores...
            case let store as StoreInst:
                
                // we can only optimise out memory we store into once
                guard !hasHadStore else { return false }
                hasHadStore = true
                
                guard case let initInst as Inst = store.value.value else { return false }
                switch initInst {
                case is StructInitInst, is TupleCreateInst:
                    break
                default:
                    return false
                }
                
            case is TupleElementPtrInst, is StructElementPtrInst:
                for use in user.uses {
                    switch use.user {
                    case is LoadInst, is StoreInst:
                        break
                    default:
                        return false
                    }
                }
                
            // We allow all loads
            case is LoadInst:
                break
            case is DeallocStackInst:
                break
            // The memory can only be stored into, loaded from, or GEP'd
            default:
                return false
            }
        }
        
        return true
    }
}

extension OptStatistics {
    static var structInitsFlattened = 0
    static var tupleInitsFlattened = 0
    static var aggrMemoryFlattened = 0
}

