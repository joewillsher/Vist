//
//  ColouringRegisterAllocator.swift
//  Vist
//
//  Created by Josef Willsher on 09/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension MCFunction {
    
    func allocateRegisters() throws {
        let allocator = ColouringRegisterAllocator(function: self, target: X86Register.self)
        try allocator.run()
    }
}


/// Allocates registers for a function; uses [iterated register 
/// coalescing](http://www.cse.iitm.ac.in/~krishna/cs6013/george.pdf)
final class ColouringRegisterAllocator {
    let function: MCFunction
    var interferenceGraph: InterferenceGraph
    let target: TargetMachine
    
    init<Target : TargetRegister>(function: MCFunction, target: Target.Type) {
        self.function = function
        self.precoloured = function.precoloured
        self.interferenceGraph = InterferenceGraph(function: function)
        self.target = TargetMachine(reg: target)
    }
    
    // TODO: set this up; params and return must be precoloured and we can't move them
    //       when coalescing
    fileprivate var precoloured: [AIRRegisterHash: TargetRegister] = [:]
    
    fileprivate var worklist: [IGNode] = []
    fileprivate var coalesceWorklist: Set<IGNode> = []
    
    /// Maps a register to the reg it was mapped into
    fileprivate var coalescedMap: [AIRRegisterHash: AIRRegisterHash] = [:]
    
    fileprivate var concreteRegisters: [AIRRegisterHash: TargetRegister] = [:]
    
    func run() throws {
        
        repeat {
            aggressiveCoalesce()
        } while removeCoalescedLoads()
        
        simplify()
        
        select()
        updateRegUse()
        
    }
}

private extension ColouringRegisterAllocator {
    
    func removeCoalescedLoads() -> Bool {
        
        var removalSet: [Int] = []
        
        for (index, inst) in function.insts.enumerated() {
            guard case .mov(let dest, let src) = inst else {
                continue
            }
            guard src.hash == coalescedMap[dest.hash] || dest.hash == coalescedMap[src.hash] else {
                continue
            }
            // remove the inst if it was
            removalSet.append(index)
            // `coalesced` is the val, remove for the key
        }
        guard !removalSet.isEmpty else { return false }
        // remove these insts working backwards
        for i in removalSet.reversed() {
            function.insts.remove(at: i)
        }
//        coalescedMap.removeAll()
        interferenceGraph = InterferenceGraph(function: function)
        return true
    }
    
    func updateRegUse() {
        
        for i in 0..<function.insts.count {
            function.insts[i].updateRegisters(concreteRegisters: concreteRegisters)
        }
        
    }
    
    func coalesce() {
        
    }
    func simplify() {
        // Simplify: color the graph using a simple heuristic [Kempe 1879]. Suppose the graph G contains 
        // a node m with fewer than K neighbors, where K is the number of registers on the machine. Let G′ be
        // the graph G − {m} obtained by removing m. If G′ can be colored, then so can G, for when adding m to 
        // the colored graph G′ the neighbors of m have at most K − 1 colors among them; so a free color can always
        // be found for m. This leads naturally to a stack-based algorithm for coloring: repeatedly remove (and 
        // push on a stack) nodes of degree less than K. Each such simplification will decrease the degrees of other
        // nodes, leading to more opportunity for simplification.
        
        for node in interferenceGraph.nodes {
            simplify(node: node)
        }
    }
    
    var k: Int { return target.register.availiableRegisters }
    
    func simplify(node: IGNode) {
        guard (node.order < k && !worklist.contains(node)) || isPrecoloured(node) else { return }
        
        if !isPrecoloured(node) {
            worklist.append(node)
        }
        interferenceGraph.remove(node)
        // simplfy nodes this is connected to
        for edge in node.interferences {
            simplify(node: edge)
        }
    }
    
    /// Combine these nodes
    func combine(_ u: IGNode, _ v: IGNode) {
        var u = u, v = v
        // u is going to be removed; which we can't do if it is precoloured
        if isPrecoloured(u) {
            swap(&u, &v)
        }
        // if both nodes are precoloured, bail on combine
        if isPrecoloured(u) {
            return
        }
        
        // record the coalesce
        coalescedMap[u.reg] = v.reg
        // combine the nodes
        interferenceGraph.combine(u, v)
    }
    
    /// Chaitin style aggressive coalescing pass
    func aggressiveCoalesce() {
        
        coalesceWorklist = interferenceGraph.nodes
        
        while let node = coalesceWorklist.popFirst() {
            for nonInterferingMoveEdge in node.moves.subtracting(node.interferences).intersection(coalesceWorklist) {
                combine(node, nonInterferingMoveEdge)
            }
        }
        
    }
    
    func isPrecoloured(_ node: IGNode) -> Bool {
        return precoloured.keys.contains(getRepresentingReg(node))
    }
    /// - returns: the reg hash representing `node`, taking into account
    ///            coalesced moves
    func getRepresentingReg(_ node: IGNode) -> AIRRegisterHash {
        return coalescedMap[node.reg] ?? node.reg
    }
    
    func select() {
        
        concreteRegisters = precoloured
        
        var regs = target.register.gpr
        func getReg() -> TargetRegister { return regs.popLast()! }
        
        for workitem in worklist.reversed() {
            concreteRegisters[workitem.reg] = precoloured[getRepresentingReg(workitem)] ?? getReg()
            interferenceGraph.reinsert(workitem)
        }
        
        for coalesced in coalescedMap {
            concreteRegisters[coalesced.key] = concreteRegisters[coalesced.value]
        }
        
    }
    
}

