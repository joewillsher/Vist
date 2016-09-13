//
//  ColouringRegisterAllocator.swift
//  Vist
//
//  Created by Josef Willsher on 09/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension MCFunction {
    
    func allocateRegisters(builder: AIRBuilder) throws {
        let allocator = ColouringRegisterAllocator(function: self, target: X8664Machine.self, builder: builder)
        try allocator.run()
    }
}


/// Allocates registers for a function; uses [iterated register 
/// coalescing](http://www.cse.iitm.ac.in/~krishna/cs6013/george.pdf)
final class ColouringRegisterAllocator {
    let function: MCFunction
    var interferenceGraph: InterferenceGraph
    let target: TargetMachine.Type, builder: AIRBuilder
    
    init(function: MCFunction, target: TargetMachine.Type, builder: AIRBuilder) {
        self.function = function
        self.precoloured = function.precoloured
        self.builder = builder
        self.target = target
        self.interferenceGraph = InterferenceGraph(function: function)
    }
    
    // TODO: set this up; params and return must be precoloured and we can't move them
    //       when coalescing
    fileprivate var precoloured: [AIRRegisterHash: TargetRegister] = [:]
    
    /// Maps a register to the reg it was mapped into
    fileprivate var coalescedMap: [AIRRegisterHash: AIRRegisterHash] = [:]
    fileprivate var colouredNodes: [AIRRegisterHash: TargetRegister] = [:]
    
    var freezeWorklist: Set<IGNode> = []
    var simplifyWorklist: Set<IGNode> = []
    var spillWorklist: Set<IGNode> = []
    /// moves able to be coalesced
    var worklistMoves: Set<IGNode> = []
    
    var frozenMoves: Set<IGNode> = []
    var selectStack: [IGNode] = []
    fileprivate var spilled: Set<IGNode> = []
    
    private func recalculateInterference() {
        interferenceGraph = InterferenceGraph(function: function)
    }
    
    func run() throws {

        for node in interferenceGraph.nodes {
            if node.order >= k {
                spillWorklist.insert(node)
            } else if node.isMoveRelated {
                freezeWorklist.insert(node)
            } else {
                simplifyWorklist.insert(node)
            }
            
            if node.isMoveRelated {
                worklistMoves.insert(node)
            }
        }
        
        while true {
            if let simplifyWorkitem = simplifyWorklist.popFirst() {
                simplify(simplifyWorkitem)
            }
            else if let move = worklistMoves.popFirst() {
                if conservativeCoalesce(move) {
                    removeCoalescedLoads()
                }
            }
            else if let toFreeze = freezeWorklist.popFirst() {
                freeze(toFreeze)
            }
            else if !spillWorklist.isEmpty {
                selectSpill()
            }
            else {
                break
            }
        }
        //assert(interferenceGraph.nodes.isEmpty)
        
        select()
        
        if !spilled.isEmpty {
            // rewrite program
            _ = insertSpills()
            // reset initial lists
            precoloured = colouredNodes
            colouredNodes.removeAll()
            coalescedMap.removeAll()
            frozenMoves.removeAll()
            // try again
            recalculateInterference()
            try run()
            return
        }
        
        updateRegUse()
        print(function)
        
    }
}

extension ColouringRegisterAllocator {
    
    func insertSpills() -> Set<AIRRegisterHash> {
        
        var spilledLocs: Set<AIRRegisterHash> = []
        
        while let spill = spilled.popFirst() {
            
            let rbp = target.basePtr
            let size = 8 // size of this register, should be calculated
            function.stackSize += size
            let offset = -function.stackSize
            
            let spillReg = builder.getRegister()
            let stackMemory = MCInstAddressingMode.offsetMem(rbp, offset)
            spilledLocs.insert(spillReg.hash)
            
            for use in interferenceGraph.uses[spill.reg]! {
                let index = function.insts.index(of: interferenceGraph.getUpdatedInst(use))!
                // write a load from stack before the use
                
                function.insts[index].rewriteRegisters(interferenceGraph) { reg in
                    reg.hash == spill.reg ? spillReg : reg
                }
                
                let fetch = MCInst.mov(dest: .reg(spillReg), src: stackMemory)
                function.insts.insert(fetch, at: index)
            }
            
            for def in interferenceGraph.defs[spill.reg]! {
                let index = function.insts.index(of: interferenceGraph.getUpdatedInst(def))!
                
                function.insts[index].rewriteRegisters(interferenceGraph) { reg in
                    reg.hash == spill.reg ? spillReg : reg
                }
                
                // write back to stack after the def
                let store = MCInst.mov(dest: stackMemory, src: .reg(spillReg))
                function.insts.insert(store, at: index+1)
            }
            
        }
        
        return spilledLocs
    }
    
}


private extension ColouringRegisterAllocator {
    
    func spillCost(of node: IGNode) -> Int {
        let uses = 1 // TODO: this should depend on
        var order = node.order
        // TODO: if it is just loaded from it is cheaper to spill
        let canBeRematerialised = false
        if canBeRematerialised { order /= 2 }
        // cost is inversely proportional to the number of uses
        // and proportional to the order
        return order / uses
    }
    
    private func cost(of a: IGNode, isLessThan b: IGNode) -> Bool {
        return spillCost(of: a) < spillCost(of: b)
    }
    
    /// possible spill
    func selectSpill() {
        let spill = spillWorklist.min(by: cost(of:isLessThan:))!
        spillWorklist.remove(spill)
        
        simplifyWorklist.insert(spill)
        spill.freezeMoves()
    }
    
    /// To freeze a node, we  
    func freeze(_ frozen: IGNode) {
        simplifyWorklist.insert(frozen)
        frozenMoves.insert(frozen)
        frozen.freezeMoves()
    }
    /// enable moves
    func unfreeze(_ node: IGNode) {
        worklistMoves.insert(node)
        node.unfreezeMoves()
    }

    
    func removeCoalescedLoads() {
        
        var removalSet: [Int] = []
        
        for (index, inst) in function.insts.enumerated() {
            guard case .mov(.reg(let dest), .reg(let src)) = inst else {
                continue
            }
            guard src.hash == coalescedMap[dest.hash] || dest.hash == coalescedMap[src.hash] else {
                continue
            }
            // remove the inst if it was
            removalSet.append(index)
            // `coalesced` is the val, remove for the key
        }
        guard !removalSet.isEmpty else { return }
        // remove these insts working backwards
        for i in removalSet.reversed() {
            function.insts.remove(at: i)
        }
//        coalescedMap.removeAll()
        interferenceGraph = InterferenceGraph(function: function)
    }
    
    func updateRegUse() {
        for i in 0..<function.insts.count {
            function.insts[i].rewriteRegisters(interferenceGraph) { reg in
                colouredNodes[reg.hash]!
            }
        }
    }
    
    var k: Int { return target.availiableRegisters }
    
    func simplify(_ node: IGNode) {
        if !isPrecoloured(node) {
            selectStack.append(node)
        }
        remove(node)
        // simplfy nodes this is connected to
        for edge in node.interferences.subtracting(selectStack) where edge.order < k {
            simplifyWorklist.insert(edge)
        }
    }
    
    /// Combine these nodes
    /// - returns: the resulting node
    func combine(_ u: IGNode, _ v: IGNode) -> IGNode? {
        var u = u, v = v
        // u is going to be removed; which we can't do if it is precoloured
        if isPrecoloured(u) {
            swap(&u, &v)
        }
        // if both nodes are precoloured, bail on combine
        if isPrecoloured(u) {
            u.freezeMoves()
            return nil
        }
        freezeWorklist.remove(u)
        spillWorklist.remove(u)
        
        // record the coalesce
        coalescedMap[u.reg] = v.reg
        // combine the nodes
        let result = interferenceGraph.combine(u, v, allocator: self)
        
        if !isPrecoloured(result), result.order >= k, freezeWorklist.contains(result) {
            spillWorklist.insert(freezeWorklist.remove(result)!)
        }
        if result.order < k, !result.isMoveRelated {
            simplifyWorklist.insert(result)
        }
        return result
    }
    
    func conservativeCoalesce(_ node: IGNode) -> Bool {
        var hadCoalesce = false
        
        for moveEdge in node.moves.subtracting(node.interferences).intersection(worklistMoves) {
            
            let significantInterferences = node.interferences.union(moveEdge.interferences)
                .filter { $0.interferences.count >= k }
            guard significantInterferences.count < k else {
                moveEdge.unfreezeMoves()
                continue
            }
            guard let combined = combine(node, moveEdge) else { continue }
            hadCoalesce = true
            // if the resulting node is no longer move related it will be available for the next round of simplification
            if !combined.isMoveRelated { break }
        }
        return hadCoalesce
    }
    
    func isPrecoloured(_ node: IGNode) -> Bool {
        return precoloured.keys.contains(getAlias(node))
    }
    /// - returns: the reg hash representing `node`, taking into account
    ///            coalesced moves
    func getAlias(_ node: IGNode) -> AIRRegisterHash {
        return coalescedMap[node.reg] ?? node.reg
    }
    
    func select() {
        
        colouredNodes = precoloured
        
        while let workitem = selectStack.popLast() {
            interferenceGraph.reinsert(workitem)
            // if we can constrain it to a precoloured node
            if let precoloured = precoloured[getAlias(workitem)] {
                colouredNodes[workitem.reg] = precoloured
            }
            else {
                // The colours we cannot assign to this node
                let interferingColours = workitem.interferences.flatMap { colouredNodes[$0.reg]?.hash }
                // get the first colour in the priority list that doesn't interfere
                guard let colour = target.gpr.first(where: { !interferingColours.contains($0.hash) }) else {
                    // spill if no colour availiable
                    spilled.insert(workitem)
                    continue
                }
                colouredNodes[workitem.reg] = colour
            }
        }
        
        for coalesced in coalescedMap {
            colouredNodes[coalesced.key] = colouredNodes[coalesced.value]
        }
        
        // [.rdi, .rsi, .rdx, .rcx]
        // 2. spill
        // 3. conservative coalesce
        // 4. freezing and full algorithm
    }
}

extension ColouringRegisterAllocator {
    /// Decrement degree
    func remove(_ node: IGNode) {
        
        for edge in node.interferences {
            if edge.order == k {
                unfreeze(node)
                spillWorklist.remove(edge)
                
                if edge.isMoveRelated {
                    freezeWorklist.insert(edge)
                } else {
                    simplifyWorklist.insert(edge)
                }
            }
        }
        
        interferenceGraph.remove(node)
    }
    
}



