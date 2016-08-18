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
    private struct AllocStackPromoter {
        let function: Function
        let alloc: AllocInst
        
        init(function: Function, alloc: AllocInst) {
            self.function = function
            self.alloc = alloc
        }
        
        var lastStoreInBlock: [BasicBlock: StoreInst] = [:]
        /// The φ nodes we have placed in blocks
        var placedPhiNodes: [BasicBlock: Param] = [:]
        
        var dominatorTree: DominatorTree {
            return function.dominator.analsis
        }
    }
    
    static func run(on function: Function) throws {
        
        guard function.hasBody else { return }
        
        for case let varInst as VariableInst in function.instructions {
            let v = varInst.value.value!
            try varInst.eraseFromParent(replacingAllUsesWith: v)
        }
        
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
    /// - postcondition: self's `lastStoreInBlock` dictionary is an updated
    ///                  list of all live uses of `alloc`
    private mutating func pruneAllocUsage() throws {
        
        let blocks = alloc.uses.map { $0.user!.parentBlock! }
        
        for block in Set(blocks) {
            lastStoreInBlock[block] = try promoteAllocation(in: block)
        }
    }
    
    
    /// Scan the function and remove in-block usage of the AllocInst.
    /// Leave only the first load and the last store.
    /// - returns: the last store inst, which provides the value to
    ///            dominated nodes
    /// - postcondition: there is at most 1 load and store in `block`
    private func promoteAllocation(in block: BasicBlock) throws -> StoreInst? {
        
        var runningValue: Value? = nil
        var lastStore: StoreInst? = nil
        
        for inst in block.instructions {
            switch inst {
            case let loadInst as LoadInst where loadInst.address.value === alloc:
                
                // if we already have a running val, replace this load
                if let val = runningValue {
                    try loadInst.eraseFromParent(replacingAllUsesWith: val)
                }
                
            case let storeInst as StoreInst where storeInst.address.value === alloc:
                
                // this becomes the running val
                runningValue = storeInst.value.value
                
                // remove the last store
                if let last = lastStore {
                    try last.eraseFromParent()
                }
                // and update it
                lastStore = storeInst
                
            default:
                break
            }
        }
        
        return lastStore
    }
    
    
    /// Removes the alloc inst and replaces loads with the live in value in that block.
    /// - precondition: There is max 1 load or store per block,
    private func fixupMemoryUse() throws {
        
        // A block's load can be replaced by its live in value
        for load in loads() {
            try load.eraseFromParent(replacingAllUsesWith: getLiveInValue(of: load.parentBlock!)!)
        }
        
        // the stores can be removed; their value is being sent to the dominator
        // frontier nodes through the phis already
        for store in stores() {
            try store.eraseFromParent()
        }
        
        // we can erase the alloc inst
        try alloc.eraseFromParent()
    }
    
    /// Replalces every use of the alloc memory in the iterated join set of the tree with
    /// a phi node variable passed as a block param
    ///
    /// Phi placement algorithm detailed in [A Linear Tifme Algorgithm for Placing φ Nodes
    /// — Sreedhar and Gao.](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.8.1979&rep=rep1&type=pdf)
    private mutating func placeφ() throws {
        
        // - Initial priority queue is the set of sparse nodes (N_α)
        // - This collection must remain ordered increasing dom tree levels, and
        //   uses should work backwards through the priority queue
        var priorityQueue = sparseNodes()
            .sorted { $0.level <= $1.level }
        
        // all nodes visited, used to prevent re-walking subtrees
        var visited: Set<DominatorTree.Node> = []
        // list of blocks that require phi placement, these are
        // members of IDF(N_α)
        var phiBlocks: Set<DominatorTree.Node> = []
        
        // walk from the bottom of the dom tree up; in the order
        // of decreasing node depth
        while let x = priorityQueue.last {
            defer { priorityQueue.removeLast() }
            
            // A node 'y ∈ DF(x)' iff
            //  - there exists a 'z ∈ SubTree(x)'
            //  - with a 'z -> y' J-edge
            //  - where 'z.level ≤ y.level'
            
            // get nodes y in subtree of x
            for subtreeBlock in dominatorTree.subtree(from: x) {
                let y = dominatorTree.getNode(for: subtreeBlock)
                
                // get all edges 'z -> y'
                for pred in subtreeBlock.successors {
                    let z = dominatorTree.getNode(for: pred)
                    
                    // if z has already been visited, don't again
                    guard !visited.insert(z).inserted else {
                        continue
                    }
                    
                    // 'y -> z' is a J-edge if 'y !sdom z'
                    // ignore J-edges where 'z.level > y.level'
                    guard !dominatorTree.node(y, strictlyDominates: z), z.level <= y.level else {
                        continue
                    }
                    
                    // if this is the first visit, add it to the priority queue
                    if phiBlocks.insert(z).inserted {
                        // insert this node in the priority queue at the index of
                        // other element of the same level
                        let index = priorityQueue.index { $0.level >= z.level } ?? priorityQueue.endIndex
                        priorityQueue.insert(z, at: index)
                    }
                }
            }
        }
        
        // add BB args to all phi blocks
        try addBlockArguments(phis: phiBlocks)
    }
    
    private mutating func addBlockArguments(phis: Set<DominatorTree.Node>) throws {
        
        // - Add phi nodes to the dominator frontier nodes
        // - These are the closest nodes which are successors of `node` in the CFG which
        //   are not dominated by node, so they require a parameterised entry
        for phiNode in phis {
            // construct the φ param
            let name = alloc.unformattedName + ".reg"
            let phi = Param(paramName: name, type: alloc.memType!)
            phiNode.block.addParam(phi)
            placedPhiNodes[phiNode.block] = phi
            
            // for each predecessor of the DF node, we add that block's live out
            // value as a phi param of the block's break inst
            for application in phi.parentBlock!.applications where !application.breakInst!.hasPhiArg(phi) {
                let fromBlock = application.breakInst!.parentBlock!
                try application.breakInst!.addPhi(outgoingVal: getLiveOutValue(of: fromBlock)!,
                                                  phi: phi,
                                                  from: fromBlock)
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
            if let store = lastStoreInBlock[currentNode.block] {
                return store.value.value
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
    func sparseNodes() -> [DominatorTree.Node] {
        return stores()
            .map { store in dominatorTree.getNode(for: store.parentBlock!) }
            .filter { node in node.block !== alloc.parentBlock! }
    }
    
    /// The store instructions using self
    func stores() -> [StoreInst] {
        return alloc.uses.flatMap { $0.user as? StoreInst }
    }
    /// The store instructions using self
    func loads() -> [LoadInst] {
        return alloc.uses.flatMap { $0.user as? LoadInst }
    }
    
    /// Can this stack memory be promoted to register uses
    /// - note: returns true if the only uses are loads
    ///         and stores
    var isRegisterPromotable: Bool {
        for use in alloc.uses {
            guard use.user is LoadInst || use.user is StoreInst else { return false }
        }
        return true
    }
}
