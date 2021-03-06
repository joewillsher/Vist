//
//  RegisterPromotionPass.swift
//  Vist
//
//  Created by Josef Willsher on 20/06/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 ## Promotes variables to be passed in registers
 
 ```
 var x = 1
 x = 100
 if cond {
    print x
    x = 2
 } else {
    x = 30
 }
 print x
 ```
 
 ```
func @test_tB : &thin (#Bool) -> #Builtin.Void {
$entry(%cond: #Bool):
  %0 = int_literal 1
  %1 = struct %Int, (%0: #Builtin.Int64)
  %2 = alloc #Int
  store %1 in %2: #*Int
  %4 = int_literal 100
  %5 = struct %Int, (%4: #Builtin.Int64)
  store %5 in %2: #*Int
  %7 = struct_extract %cond: #Bool, !value
  cond_break %7: #Builtin.Bool, $entry.true0, $entry.false0

$entry.true0:			// preds: entry
  %12 = load %2: #*Int
  %13 = call @print_tI (%12: #Int)
  %14 = int_literal 2
  %15 = struct %Int, (%14: #Builtin.Int64)
  store %15 in %2: #*Int
  break $entry.exit

$entry.false0:			// preds: entry
  %18 = int_literal 30
  %19 = struct %Int, (%18: #Builtin.Int64)
  store %19 in %2: #*Int
  break $entry.exit
 
$entry.exit:			// preds: entry.true0, entry.false0
  %9 = load %2: #*Int
  %10 = call @print_tI (%9: #Int)
  return ()
}
 ```
 
 becomes
 
 ```
func @test_tB : &thin (#Bool) -> #Builtin.Void {
$entry(%cond: #Bool):
  %0 = int_literal 100
  %1 = struct %Int, (%0: #Builtin.Int64)
  %2 = struct_extract %cond: #Bool, !value
  cond_break %2: #Builtin.Bool, $entry.true0, $entry.false0

$entry.true0:			// preds: entry
  %6 = call @print_tI (%1: #Int)
  %7 = int_literal 2
  %8 = struct %Int, (%7: #Builtin.Int64)
  break $entry.exit(%8: #Int)

$entry.false0:			// preds: entry
  %10 = int_literal 30
  %11 = struct %Int, (%10: #Builtin.Int64)
  break $entry.exit(%11: #Int)
 
$entry.exit(%2.reg: #Int):			// preds: entry.false0, entry.true0
  %4 = call @print_tI (%2.reg: #Int)
  return ()
}
 ```
*/
enum RegisterPromotionPass : OptimisationPass {
    
    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .low
    static let name = "mem2reg"
    
    /// https://www.researchgate.net/profile/Jeanne_Ferrante/publication/225508360_Efficiently_computing_ph-nodes_on-the-fly/links/549458fd0cf22af911222521.pdf?origin=publication_detail
    /// http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.8.1979&rep=rep1&type=pdf
    /// https://github.com/apple/swift/blob/279726fe184400129664c3089160e00230cb485c/lib/SILOptimizer/Transforms/SILMem2Reg.cpp
    fileprivate struct AllocStackPromoter {
        let function: Function
        let alloc: AllocInst
        
        init(function: Function, alloc: AllocInst) {
            self.function = function
            self.alloc = alloc
        }
        
        var lastStoredValueInBlock: [BasicBlock: Value] = [:]
        /// The φ nodes we have placed in blocks
        var placedPhiNodes: [BasicBlock: Param] = [:]
        
        var dominatorTree: DominatorTree {
            return function.dominator.analysis
        }
    }
    
    static func run(on function: Function) throws {
        
        guard function.hasBody else { return }
        
        for block in function.blocks! {
            for case let allocInst as AllocInst in block.instructions {
                var promoter = AllocStackPromoter(function: function, alloc: allocInst)
                try promoter.run()
            }
        }
    }
}

extension RegisterPromotionPass.AllocStackPromoter {
    
    mutating func run() throws {
        // TODO: all uses are in a block! globals not allowed
        guard isRegisterPromotable else { return }
        
        // remove in-block use of the values
        try pruneAllocUsage()
        // place phi nodes in the correct join nodes
        try placeφ()
        // remove alloc, stores, loads
        try fixupMemoryUse()
    }
    
    /// - returns: the last stores in each block
    /// - postcondition: self's `lastStoredValueInBlock` dictionary is an updated
    ///                  list of all live uses of `alloc`
    private mutating func pruneAllocUsage() throws {
        for block in alloc.useBlocks {
            lastStoredValueInBlock[block] = try promoteAllocation(in: block)
        }
    }
    
    
    /// Scan the function and remove in-block usage of the AllocInst.
    /// Leave only the first load and the last store.
    /// - returns: the last store inst, which provides the value to
    ///            dominated nodes
    /// - postcondition: there is at most 1 load and store in `block`
    private func promoteAllocation(in block: BasicBlock) throws -> Value? {
        
        var runningValue: Value? = nil
        var lastStore: Inst? = nil
        
        for inst in block.instructions {
            switch inst {
            case let loadInst as LoadInst:
                // if we already have a running val, replace this load
                if let val = runningValue {
                    try replaceLoad(loadInst, with: val)
                }
                
            case let storeInst as StoreInst where storeInst.address.lValue!.isLValueOrProjection(of: alloc):
                // this becomes the running val
                runningValue = storeInst.value.value
                
                // remove the last store
                if let last = lastStore {
                    try last.eraseFromParent()
                    OptStatistics.storesPromotedToPhiUse += 1
                }
                // and update it
                lastStore = storeInst
                
            case let copyInst as CopyAddrInst where copyInst.outAddr.lValue!.isLValueOrProjection(of: alloc):
                // this becomes the running val
                let load = LoadInst(address: copyInst.addr.lValue!)
                try copyInst.parentBlock!.insert(inst: load, after: copyInst)
                runningValue = load
                
                // remove the last store
                if let last = lastStore {
                    try last.eraseFromParent()
                    OptStatistics.storesPromotedToPhiUse += 1
                }
                // and update it
                lastStore = copyInst
                
            default:
                break
            }
        }
        
        return runningValue
    }
    
    
    /// Removes the alloc inst and replaces loads with the live in value in that block.
    /// - precondition: There is max 1 load or store per block,
    private func fixupMemoryUse() throws {
        
        // for all load insts in the fn, check if it is uses `alloc` or a 
        // projection thereof
        for block in dominatorTree {
            for case let load as LoadInst in block.instructions {
                try replaceLoad(load, with: getLiveInValue(of: load.parentBlock!)!)
            }
        }
        // remove deallocations
        for dealloc in alloc.deallocInsts {
            try dealloc.eraseFromParent()
        }
        
        // the stores can be removed; their value is being sent to the dominator
        // frontier nodes through the phis already
        for mutation in alloc.mutations() {
            try removeMutation(mutation)
        }
        // replace copy_addr use insts (which dont mutate the alloc) with a store of the value
        // use the live out value of the block, as the copy_addr is the only mutation in
        // this block
        for copy in alloc.copyAddrInsts() {
            let store = try StoreInst(address: copy.outAddr.lValue!, value: getLiveOutValue(of: copy.parentBlock!)!)
            try copy.parentBlock!.insert(inst: store, after: copy)
            try copy.eraseFromParent()
        }
        
        // we can erase the alloc inst
        try alloc.eraseFromParent()
        OptStatistics.allocationsPromotedToPhi += 1
    }
    
    
    /// If this load is an access of `alloc` or a projection of `alloc` then
    /// replace its uses with `value` or a member access of `value`
    /// - parameter value: returns the value we use to replace, lazily evaluated
    ///                    if `load` is an access/projection of `alloc`
    func replaceLoad(_ load: LoadInst, with value: @autoclosure () throws -> Value) throws {
        var op = load.address.value
        var projection: [Inst] = []
        
        allocLoop: while !(op is AllocInst) {
            switch op {
            case let structElement as StructElementPtrInst:
                projection.append(structElement)
                op = structElement.object.value!
            case let tupleElement as TupleElementPtrInst:
                projection.append(tupleElement)
                op = tupleElement.tuple.value!
            case let addr as VariableAddrInst:
                projection.append(addr)
                op = addr.addr.value!
            default:
                break allocLoop
            }
        }
        
        // must be the same memory
        guard op === alloc else { return }
        
        var v = try value()
        var p = load.predecessorOrSelf()
        
        for proj in projection {
            switch proj {
            case let gep as StructElementPtrInst:
                let el = try StructExtractInst(object: v, property: gep.propertyName)
                try p.parentBlock!.insert(inst: el, at: p)
                v = el
                p = el
            case let gep as TupleElementPtrInst:
                let el = try TupleExtractInst(tuple: v, index: gep.elementIndex)
                try p.parentBlock!.insert(inst: el, after: p)
                v = el
                p = el
            case let addr as VariableAddrInst:
                let variable = VariableInst(value: v, irName: addr.irName)
                try p.parentBlock!.insert(inst: variable, after: p)
                v = variable
                p = variable
            default: fatalError()
            }
            if proj.uses.isEmpty { try proj.eraseFromParent() }
        }
        
        try load.eraseFromParent(replacingAllUsesWith: v)
        OptStatistics.loadsPromotedToPhiUse += 1
    }
    
    /// This removes any mutation of `alloc`, or a projection thereof
    func removeMutation(_ mutation: Inst) throws {
        var op: Value
        switch mutation {
        case let store as StoreInst: op = store.address.value!
        case let copy as CopyAddrInst: op = copy.outAddr.value!
        default: return
        }
        var projection: [Inst] = []
        
        allocLoop: while !(op is AllocInst) {
            switch op {
            case let structElement as StructElementPtrInst:
                projection.append(structElement)
                op = structElement.object.value!
            case let tupleElement as TupleElementPtrInst:
                projection.append(tupleElement)
                op = tupleElement.tuple.value!
            case let addr as VariableAddrInst:
                projection.append(addr)
                op = addr.addr.value!
            default:
                break allocLoop
            }
        }
        
        // must be the same memory
        guard op === alloc else { return }
        
        try mutation.eraseFromParent()
        
        // walk back through projection, removing it if it is now unused
        for proj in projection.reversed() {
            if proj.uses.isEmpty { try proj.eraseFromParent() }
        }
        
        OptStatistics.storesPromotedToPhiUse += 1
    }
    
    
    /// Replaces every use of the alloc memory in the iterated join set of the tree with
    /// a phi node variable passed as a block param
    ///
    /// Phi placement algorithm detailed in [A Linear Tifme Algorgithm for Placing φ Nodes
    /// — Sreedhar and Gao.](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.8.1979&rep=rep1&type=pdf)
    private mutating func placeφ() throws {
        
        // - Initial priority queue is the set of sparse nodes (N_α)
        // - This collection must remain ordered increasing dom tree levels, and
        //   uses should work backwards through the priority queue
        let sparseSet = sparseNodes()
        var priorityQueue = sparseSet
            .sorted { $0.level <= $1.level }
        
        // all nodes visited, used to prevent re-walking subtrees
        var visited: Set<DominatorTree.Node> = []
        // list of blocks that require phi placement, these are
        // members of IDF(N_α)
        var phiBlocks: Set<DominatorTree.Node> = []
        let allocNode = dominatorTree.getNode(for: alloc.parentBlock!)
        
        // walk from the bottom of the dom tree up; in the order
        // of decreasing node depth
        while let rootNode = priorityQueue.popLast() {
            // A node 'y ∈ DF(x)' iff
            //  - there exists a 'z ∈ SubTree(x)'
            //  - with a 'z -> y' J-edge
            //  - where 'z.level ≤ y.level'
            
            // get nodes z in subtree of x
            for subtreeBlock in dominatorTree.subtree(from: rootNode) {
                let z = dominatorTree.getNode(for: subtreeBlock)
                
                // if we have already visited this subnode, because we are traversing
                // the tree from the bottom up, we know its IDF has been added to the
                // set of phi nodes
                guard visited.insert(z).inserted else { continue }
                
                // get all edges 'z -> y'
                for succBlock in subtreeBlock.successors {
                    let succ = dominatorTree.getNode(for: succBlock)
                    
                    guard
                        // 'z -> y' is a J-edge if 'z !sdom y'
                        !dominatorTree.node(z, strictlyDominates: succ),
                        // we only want J-edges where 'y.level <= root.level'
                        succ.level <= rootNode.level,
                        // the alloc must dominate this phi
                        dominatorTree.node(allocNode, dominates: succ)
                        else { continue }
                    
                    // if this is the first visit, and isnt in N_α, add it to the priority queue
                    if phiBlocks.insert(succ).inserted, !sparseSet.contains(succ) {
                        // insert this node in the priority queue at the index of
                        // other element of the same level
                        let index = priorityQueue.index { $0.level >= succ.level } ?? priorityQueue.endIndex
                        priorityQueue.insert(succ, at: index)
                    }
                }
            }
        }
        
        // add BB args to all phi blocks
        try addBlockArguments(phis: phiBlocks)
    }
    
    private static var count = 0
    
    private mutating func addBlockArguments(phis: Set<DominatorTree.Node>) throws {
        
        // - Add phi nodes to the dominator frontier nodes
        // - These are the closest nodes which are successors of `node` in the CFG which
        //   are not dominated by node, so they require a parameterised entry
        for phiNode in phis {
            // rename
            let name = alloc.unformattedName + ".reg.\(RegisterPromotionPass.AllocStackPromoter.count)"
            RegisterPromotionPass.AllocStackPromoter.count += 1 // FIXME: Hack
            // construct the φ param
            let phi = Param(paramName: name, type: alloc.memType!)
            phiNode.block.addParam(phi)
            placedPhiNodes[phiNode.block] = phi
            OptStatistics.phiNodesPlaced += 1
            
            // for each predecessor of the DF node, we add that block's live out
            // value as a phi param of the block's break inst
            for application in phi.parentBlock!.applications where !application.breakInst!.hasPhiArg(phi) {
                let fromBlock = application.breakInst!.parentBlock!
                try application.breakInst!.addPhi(outgoingVal: getLiveOutValue(of: fromBlock)!,
                                                  phi: phi, from: fromBlock)
            }
        }
    }

}

fileprivate extension RegisterPromotionPass.AllocStackPromoter {
    
    /// Get the value for this AllocStack variable that is
    /// flowing into `block`
    func getLiveInValue(of block: BasicBlock) throws -> Value? {
        
        // if we have a phi node, use that
        for param in block.parameters ?? [] {
            if let phi = placedPhiNodes[block], phi === param {
                return param
            }
        }
        
        // otherwise return the dominator's
        guard let iDom = dominatorTree.getNode(for: block).iDom else {
            return nil
        }
        return try getLiveOutValue(of: iDom.block)
    }
    
    /// Get the value for this Alloc variable that is
    /// flowing out of block.
    func getLiveOutValue(of block: BasicBlock) throws -> Value? {
        
        // walk up the dominator tree.
        var node: DominatorTree.Node? = dominatorTree.getNode(for: block)
        while let currentNode = node {
            defer { node = currentNode.iDom }
            
            // stores must come after the phi, use that if found
            if let value = lastStoredValueInBlock[currentNode.block] {
                return value
            }
            
            // else if we have a phi node, use that
            for param in block.parameters ?? [] {
                if let phi = placedPhiNodes[block], phi === param {
                    return param
                }
            }
        }
        
        return nil
    }
    
    /// A set of the sparse nodes `N_α` in the tree; these are the nodes which
    /// represent non identity transferrence of the value of the alloc inst
    /// - note: Each node containing a store (apart from the node with 
    ///         the allocation) is an element N_α
    func sparseNodes() -> Set<DominatorTree.Node> {
        return Set(alloc.mutations()
            .map { store in dominatorTree.getNode(for: store.parentBlock!) }
            .filter { node in node.block !== alloc.parentBlock! })
    }
    
    /// The store instructions using self
    func stores() -> [StoreInst] {
        return alloc.uses.flatMap { $0.user as? StoreInst }
    }
    
    /// Can this stack memory be promoted to register uses
    /// - note: returns true if the only uses are loads
    ///         and stores
    var isRegisterPromotable: Bool {
        return alloc.isRegisterPromotable
    }
}
private extension Inst where Self : LValue {
    var isRegisterPromotable: Bool {
        for use in uses {
            switch use.user {
            case is LoadInst, is StoreInst, is DeallocStackInst:
                continue
            case is CopyAddrInst:
                guard memType?.isTrivial() ?? false else { return false }
            case is StructElementPtrInst, is TupleElementPtrInst:
                for use in use.user!.uses {
                    guard use.user is LoadInst else { return false }
                }
            case let addr as VariableAddrInst:
                if !addr.isRegisterPromotable { return false }
            default:
                return false
            }
        }
        return true
    }
    var useBlocks: Set<BasicBlock> {
        return Set(uses.flatMap { use -> [BasicBlock] in
            let user = use.user!
            switch user {
            case is VariableAddrInst, is StructElementPtrInst, is TupleElementPtrInst:
                let l = user as! LValue & Inst
                return [l.parentBlock!] + l.useBlocks
            default:
                return [user.parentBlock!]
            }
            })
    }
    /// the values modified by this inst
    func mutations() -> [Inst] {
        return uses.map { use -> [Inst] in
            if case let proj as VariableAddrInst = use.user { return proj.mutations() }
            if case let s as StoreInst = use.user, s.address.value === self { return [s] }
            if case let s as CopyAddrInst = use.user, s.outAddr.value === self { return [s] }
            return []
        }.flatMap { $0 }
    }
    func copyAddrInsts() -> [CopyAddrInst] {
        return uses.map { use -> [CopyAddrInst] in
            if case let proj as VariableAddrInst = use.user { return proj.copyAddrInsts() }
            if case let s as CopyAddrInst = use.user { return [s] }
            return []
        }.flatMap { $0 }
    }
}
extension LValue {
    func isLValueOrProjection(of lval: LValue) -> Bool {
        if case let v as VariableAddrInst = self {
            return v.addr.lValue!.isLValueOrProjection(of: lval)
        }
        return lval === self
    }
}
private extension AllocInst {
    var deallocInsts: [Inst] {
        return uses.flatMap {
            switch $0.user {
            case is DeallocStackInst, is DestroyAddrInst:
                return $0.user
            default:
                return nil
            }
        }
    }
}

extension OptStatistics {
    static var phiNodesPlaced = 0
    static var allocationsPromotedToPhi = 0
    static var storesPromotedToPhiUse = 0
    static var loadsPromotedToPhiUse = 0
}
