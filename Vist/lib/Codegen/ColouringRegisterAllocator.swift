//
//  ColouringRegisterAllocator.swift
//  Vist
//
//  Created by Josef Willsher on 09/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension MCFunction {
    
    func allocateRegisters() throws {
        let allocator = ColouringRegisterAllocator(function: self)
        try allocator.run()
    }
}


/// Allocates registers for a function; uses [iterated register 
/// coalescing](http://www.cse.iitm.ac.in/~krishna/cs6013/george.pdf)
final class ColouringRegisterAllocator {
    let function: MCFunction
    var interferenceGraph: InterferenceGraph
    let target: TargetMachine
    
    init(function: MCFunction) {
        self.function = function
        self.interferenceGraph = InterferenceGraph(function: function)
        self.target = TargetMachine(nativeIntSize: 64, register: X86Register.self)
    }
    
    // TODO: set this up; params and return must be precoloured and we can't move them
    //       when coalescing
    fileprivate var precoloured: [AIRRegisterHash: TargetRegister] = [:]
    
    fileprivate var worklist: [IGNode] = []
    /// Maps a register to the reg it was mapped into
    fileprivate var coalescedMap: [AIRRegisterHash: AIRRegisterHash] = [:]
    
    fileprivate var concreteRegisters: [AIRRegisterHash: TargetRegister] = [:]
    
    func run() throws {
        
        repeat {
            aggressiveCoalesce()
        } while removeCoalescedLoads()
        
        simplify()
        
        select()
        
    }
}

private extension ColouringRegisterAllocator {
    
    func removeCoalescedLoads() -> Bool {
        
        var removalSet: [Int] = []
        
        for (index, inst) in function.insts.enumerated() {
            guard case .mov(let dest, let src) = inst else {
                continue
            }
            guard let _ = coalescedMap[dest.hash] ?? coalescedMap[src.hash] else {
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
        coalescedMap.removeAll()
        interferenceGraph = InterferenceGraph(function: function)
        return true
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
        guard node.order < k, !worklist.contains(node) else { return }
        
        worklist.append(node)
        interferenceGraph.remove(node)
        // simplfy nodes this is connected to
        for edge in node.interferences {
            simplify(node: edge)
        }
    }
    
    /// Combine these nodes
    func combine(_ u: IGNode, _ v: IGNode) {
        // record the coalesce
        coalescedMap[u.reg] = v.reg
        // combine the nodes
        interferenceGraph.combine(u, v)
    }
    
    /// Chaitin style aggressive coalescing pass
    func aggressiveCoalesce() {
        
        for node in interferenceGraph.nodes {
            for nonInterferingMoveEdge in node.moves.subtracting(node.interferences) {
                // don't try to recombine nodes which have already been combined
                guard coalescedMap[nonInterferingMoveEdge.reg] == nil else {
                    continue
                }
                combine(node, nonInterferingMoveEdge)
            }
        }
        
    }
    
    
    func select() {
        
        for (workitem, reg) in zip(worklist.reversed(), target.register.gpr) {
            concreteRegisters[workitem.reg] = reg
            interferenceGraph.reinsert(workitem)
        }
        
    }
    
}

