//
//  ColouringRegisterAllocator.swift
//  Vist
//
//  Created by Josef Willsher on 09/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension MCFunction {
    
    func allocateRegisters(builder: AIRBuilder) throws {
        let allocator = ColouringRegisterAllocator(function: self, target: target, builder: builder)
        try allocator.run()
    }
}


/// Allocates registers for a function; uses [iterated register 
/// coalescing](http://www.cse.iitm.ac.in/~krishna/cs6013/george.pdf)
/// See also: [the webkit implementation](
// https://trac.webkit.org/browser/trunk/Source/JavaScriptCore/b3/air/AirIteratedRegisterCoalescing.cpp)
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
    
    /// Maps a register to the reg it was mapped into
    fileprivate var coalescedMap: [AIRRegisterHash: AIRRegisterHash] = [:]
    /// Nodes which have been removed from the graph in a coalesce step
    fileprivate var coalescedNodes: Set<IGNode> = []
    
    /// Virtual registers which are already constrained to target registers, for
    /// example by calling conventions
    fileprivate var precoloured: [AIRRegisterHash: TargetRegister] = [:]
    /// The mapping from virtual registers to target registers
    fileprivate var coloured: [AIRRegisterHash: TargetRegister] = [:]
    
    /// low-degree move-related nodes.
    fileprivate var freezeWorklist: Set<IGNode> = []
    /// low-degree non-move-related nodes
    fileprivate var simplifyWorklist: Set<IGNode> = []
    /// high-degree nodes
    fileprivate var spillWorklist: Set<IGNode> = []
    /// moves enabled for possible coalescing. Unlike the Lal George paper, we keep track
    /// of which moves are active in the nodes.
    var worklistMoves: Set<IGMove> = []
    var activeMoves: Set<IGMove> = []
    var frozenMoves: Set<IGMove> = []
    var constrainedMoves: Set<IGMove> = []
    
    /// stack containing temporaries removed from the graph
    fileprivate var selectStack: [IGNode] = []
    
    /// Nodes marked for spilling
    fileprivate var spilled: Set<IGNode> = []
    
    private func recalculateInterference() {
        interferenceGraph = InterferenceGraph(function: function)
    }
    
    func run() throws {
        
        // MkWorklist
        worklistMoves = interferenceGraph.allMoves
        for node in interferenceGraph.nodes.values {
            if node.order >= k {
                spillWorklist.insert(node)
            } else if isMoveRelated(node) {
                freezeWorklist.insert(node)
            } else {
                simplifyWorklist.insert(node)
            }
        }
        
        while true {
            if let simplifyWorkitem = simplifyWorklist.popFirst() {
                simplify(simplifyWorkitem)
            }
            else if let move = worklistMoves.popFirst() {
                if coalesce(move) {
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
        assert(interferenceGraph.nodes.isEmpty)
        
        // select registers
        select()
        
        // if there were spills
        guard spilled.isEmpty else {
            // rewrite program
            insertSpills()
            // reset initial lists
            coloured.removeAll()
            activeMoves.removeAll()
            constrainedMoves.removeAll()
            frozenMoves.removeAll()
            // try again
            recalculateInterference()
            try run()
            return
        }
        // rewrite the function
        updateRegUse()
        
    }
    
    func isMoveRelated(_ node: IGNode) -> Bool {
        return worklistMoves.union(activeMoves).contains { move in move.hasMember(node) }
    }
    
    func moves(of node: IGNode) -> Set<IGMove> {
        return Set(worklistMoves.union(activeMoves).filter { move in move.hasMember(node) })
    }
    /// All move edges
    func allMoves(of node: IGNode) -> Set<IGMove> {
        return Set(worklistMoves.union(activeMoves).union(frozenMoves).filter { move in move.hasMember(node) })
    }
    
}

extension ColouringRegisterAllocator {
    
    /// Places the spilled nodes
    func insertSpills() {
        
        let rbp = target.basePtr
        let size = target.wordSize/8 // size of this register == the stack space we need
        
        while let spill = spilled.popFirst() {
            // alloc more stack space
            function.stackSize += size
            let offset = -function.stackSize
            
            // this is the reg with the short lifes, we load/store when the spilled
            // register's value is needed
            let spillReg = builder.getRegister()
            let stackMemory = MCInstAddressingMode.offsetMem(rbp, offset)
            
            for use in interferenceGraph.uses[getAlias(spill)]! {
                let index = function.insts.index(of: interferenceGraph.getUpdatedInst(use))!
                
                // rewrite the use's register with our reg which gets its val from the stack
                function.insts[index].rewriteRegisters(interferenceGraph) { reg in
                    reg.hash == spill.reg ? spillReg : reg
                }
                
                // write a load from stack before the use
                let fetch = MCInst.mov(dest: .reg(spillReg), src: stackMemory)
                function.insts.insert(fetch, at: index)
            }
            
            for def in interferenceGraph.defs[getAlias(spill)]! {
                let index = function.insts.index(of: interferenceGraph.getUpdatedInst(def))!
                
                // again, rewrite the def to write into the reg about to be stored to the stack
                function.insts[index].rewriteRegisters(interferenceGraph) { reg in
                    reg.hash == spill.reg ? spillReg : reg
                }
                
                // write back to stack after the def
                let store = MCInst.mov(dest: stackMemory, src: .reg(spillReg))
                function.insts.insert(store, at: index+1)
            }
            
        }
    }
    
    /// A score of how desirable this reg is to spill. Higher means it 
    /// is a better candidate
    func spillScore(of node: IGNode) -> Double {
        // don't spill precoloured nodes
        guard !isPrecoloured(node) else { return 0 }
        let uses = Double(interferenceGraph.uses[getAlias(node)]!.count)
        var order = Double(node.order)
        // TODO: if it is just loaded from it is cheaper to spill
        let canBeRematerialised = false //interferenceGraph.defs[getAlias(node)]!.count == 1
        if canBeRematerialised { order *= 2.0 }
        // score is inversely proportional to the number of uses
        // and proportional to the order
        return order / uses
    }
    
    private func score(of a: IGNode, isLessThan b: IGNode) -> Bool {
        return spillScore(of: a) < spillScore(of: b)
    }
    
    /// possible spill: we select a spill from the `spillWorklist` and freeze its moves
    func selectSpill() {
        let spill = spillWorklist.max(by: score(of:isLessThan:))!
        // freeze this node
        spillWorklist.remove(spill)
        freeze(spill)
    }
    
    /// Select the registers, and producing actual spills if that fails
    func select() {
        // we know the colour of the precoloured nodes
        coloured = precoloured
        
        // in reverse order we readd the selectStack nodes back to the graph. When we removed
        // them in the simplify phase we guaranteed the rest of the graph was colourable 
        // with k-1 registers.
        while let workitem = selectStack.popLast() {
            interferenceGraph.reinsert(workitem)
            // if we can constrain it to a precoloured node
            if let precoloured = precoloured[getAlias(workitem)] {
                coloured[workitem.reg] = precoloured
            }
            else {
                // The colours we cannot assign to this node
                // = the set of nodes this node interferes with in the graph
                let interferingColours = Set(workitem.interferences
                    .flatMap { coloured[getAlias($0)]?.hash })
                // get the first colour in the priority list that doesn't interfere
                guard let colour = availiableRegisters.first(where: { !interferingColours.contains($0.hash) }) else {
                    // spill if no colour availiable
                    spilled.insert(workitem)
                    continue
                }
                coloured[getAlias(workitem)] = colour
            }
        }
        
        // update the aliases
        for coalesced in coalescedMap {
            coloured[coalesced.key] = coloured[coalesced.value]
        }
        
    }
    
    /// The registers associated with the precoloured nodes
    private var precolouredRegister: Set<AIRRegisterHash> {
        return Set(precoloured.map { $0.value.hash })
    }
    /// Registers provided by this target
    var availiableRegisters: [TargetRegister] {
        return (precoloured.map { $0.value }) + (target.gpr.map { $0 as TargetRegister })
    }
    
}


private extension ColouringRegisterAllocator {
    
    /// We set the node's moves as frozen and add it to the simplifyWorklist
    func freeze(_ frozen: IGNode) {
        simplifyWorklist.insert(frozen)
        // freeze moves
        for move in moves(of: frozen) {
            freezeMove(move)
            let edge = move.other(frozen)
            if !isMoveRelated(edge), edge.order < k {
                freezeWorklist.remove(edge)
                simplifyWorklist.insert(edge)
            }
        }
    }
    
    /// enable moves for this node, adding it back to the moveWorklist
    func unfreeze(_ node: IGNode) {
        for move in moves(of: node).intersection(activeMoves) {
            activeMoves.remove(move)
            worklistMoves.insert(move)
        }
    }
    
    func freezeMove(_ move: IGMove) {
        worklistMoves.remove(move)
        activeMoves.remove(move)
        frozenMoves.insert(move)
    }
    func setActiveMove(_ move: IGMove) {
        worklistMoves.remove(move)
        frozenMoves.remove(move)
        activeMoves.insert(move)
    }
    
    /// The number of registers in the target machine; the number of
    /// colours we have to assign to the graph
    var k: Int { return Set(availiableRegisters.map { $0.hash }).count }
    
    /// Remove `node` from the graph. The algorithm relies on
    /// the simplify phase removing nodes from the graph without
    /// affecting the colourability; so node must either be precoloured
    /// or have order < k.
    func simplify(_ node: IGNode) {
        if !isPrecoloured(node) {
            selectStack.append(node)
        }
        remove(node)
    }
    
    func coalesce(_ move: IGMove) -> Bool {
        let node = move.src, moveEdge = move.dest
        var u = getAliasNode(node), v = getAliasNode(moveEdge)
        if isPrecoloured(v) { swap(&u, &v) }
        
        if u == v {
            let res = combineNonMove(u, v)
            addWorkList(res)
        }
            // if theyre both precoloured or interfere
        else if isPrecoloured(v) || u.interferences.contains(v) {
            constrainMove(IGMove(src: u, dest: v))
            addWorkList(u); addWorkList(v)
        }
        else if canBeSafelyCoalesced(u, v) {
            let res = combine(u, v)
            addWorkList(res)
            return true
        }
        else {
            setActiveMove(IGMove(src: u, dest: v))
        }
        return false
    }
    
    /// Combine the nodes, removing the move inst; both `u` and `v`
    /// get the identity of `u`.
    /// - note: `v` is removed from the graph and the coalescedMap has a value
    ///         `u` for the key `v`
    /// - returns: the resulting node
    func combine(_ u: IGNode, _ v: IGNode) -> IGNode {
        //var u = u, v = v
        freezeWorklist.remove(v)
        spillWorklist.remove(v)
        
        // update move lists
        for m in worklistMoves where m.hasMember(v) {
            worklistMoves.insert(IGMove(src: worklistMoves.remove(m)!.other(v), dest: u))
        }
        for m in frozenMoves where m.hasMember(v) {
            frozenMoves.insert(IGMove(src: frozenMoves.remove(m)!.other(v), dest: u))
        }
        for m in activeMoves where m.hasMember(v) {
            activeMoves.insert(IGMove(src: activeMoves.remove(m)!.other(v), dest: u))
        }
        
        // record the coalesce
        // combine the nodes
        let result = interferenceGraph.combine(u, v, allocator: self)
        coalescedNodes.insert(v)
        coalescedMap[v.reg] = result.reg
        
        // if we increased the order of the node to >= k, we mark as spilled
        if result.order >= k, let spill = freezeWorklist.remove(result) {
            spillWorklist.insert(spill)
        }
        return result
    }
    
    func combineNonMove(_ u: IGNode, _ v: IGNode) -> IGNode {
        freezeWorklist.remove(v)
        spillWorklist.remove(v)
        return u
    }
    
    /// Sets a move as constrained -- it cannot be removed
    func constrainMove(_ move: IGMove) {
        constrainedMoves.insert(move)
    }
    
    /// When a move is coalesced, it may no longer be move related and can be added
    /// to the simplify worklist by addWorkList
    func addWorkList(_ node: IGNode) {
        if !isMoveRelated(node), /*!isPrecoloured(node),*/ node.order < k {
            freezeWorklist.remove(node)
            simplifyWorklist.insert(node)
        }
    }
    
    /// Can `u` and `v` be coalesced without affecting the colourability of the graph
    func canBeSafelyCoalesced(_ u: IGNode, _ v: IGNode) -> Bool {
        assert(!isPrecoloured(v))
        return isPrecoloured(u) ?
            precoloredCoalescingHeuristic(u, v) :
            conservativeHeuristic(u, v)
    }
    
    /// Can `u` and `v` be coalesced given `u` is precoloured
    func precoloredCoalescingHeuristic(_ u: IGNode, _ v: IGNode) -> Bool {
        // If any adjacent of the non-coloured node is not an adjacent of the coloured node AND has a degree >= K
        // there is a risk that this node needs to have the same colour as our precolored node.
        precondition(isPrecoloured(u))
        return !adjacent(v).contains { t in
            !(t.order < k || isPrecoloured(t) || adjacent(t).contains(u))
        }
    }
    
    /// Can `u` and `v` be coalesced using Brigg's conservative coalescing algorithm.
    /// - If the number of combined adjacent node with a degree >= K is less than K,
    ///   it is safe to combine the two nodes.
    func conservativeHeuristic(_ u: IGNode, _ v: IGNode) -> Bool {
        assert(!isPrecoloured(u))
        return adjacent(u).union(adjacent(v))
            .filter { $0.interferences.count >= k }
            .count < k
    }
    
}

private extension ColouringRegisterAllocator {
    
    /// Rewrite the function to remove coalesced moves
    func removeCoalescedLoads() {
        
        var removalSet: [Int] = []
        
        for (index, inst) in function.insts.enumerated() {
            guard case .mov(.reg(let dest), .reg(let src)) = inst else {
                continue
            }
            guard src.hash == coalescedMap[dest.hash] || dest.hash == coalescedMap[src.hash] else {
                continue
            }
            removalSet.append(index)
        }
        guard !removalSet.isEmpty else { return }
        // remove these insts working backwards
        for i in removalSet.reversed() {
            function.insts.remove(at: i)
        }
    }
    
    /// Rewrite the function with the coloured registers
    func updateRegUse() {
        for i in 0..<function.insts.count {
            function.insts[i].rewriteRegisters(interferenceGraph) { reg in
                coloured[reg.hash] ?? reg
            }
        }
    }
    
    func adjacent(_ node: IGNode) -> Set<IGNode> {
        return node.interferences.subtracting(selectStack).subtracting(coalescedNodes)
    }
    
    
    func isPrecoloured(_ node: IGNode) -> Bool {
        return precoloured.keys.contains(getAlias(node))
    }
    /// - returns: the reg hash representing `node`, taking into account
    ///            coalesced moves
    func getAlias(_ node: IGNode) -> AIRRegisterHash {
        return coalescedMap[node.reg] ?? node.reg
    }
    func getAliasNode(_ node: IGNode) -> IGNode {
        return interferenceGraph.nodes[getAlias(node)]!
    }
    
}

extension ColouringRegisterAllocator {
    /// Decrement degree
    func remove(_ node: IGNode) {
        assert(interferenceGraph.contains(node))
        
        // we haven't removed the node yet
        for edge in adjacent(node) where edge.order == k {
            // if the edge has k neighbours, it will have <k
            // when we remove it, update lists
            unfreeze(edge)
            for m in adjacent(edge) { unfreeze(m) }
            spillWorklist.remove(edge)
            
            if isMoveRelated(edge) {
                freezeWorklist.insert(edge)
            } else {
                simplifyWorklist.insert(edge)
            }
        }
        
        interferenceGraph.remove(node)
        
        // update move sets
        for m in worklistMoves where m.hasMember(node) { worklistMoves.remove(m) }
        for m in frozenMoves where m.hasMember(node) { frozenMoves.remove(m) }
        for m in activeMoves where m.hasMember(node) { activeMoves.remove(m) }
        // update node sets
        simplifyWorklist.remove(node)
        freezeWorklist.remove(node)
    }
    
}



