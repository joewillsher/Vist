//
//  InterferenceGraph.swift
//  Vist
//
//  Created by Josef Willsher on 09/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class IGNode {
    let reg: AIRRegisterHash
    /// Interference edges
    var interferences: Set<IGNode> = []
    
    init(reg: AIRRegisterHash) { self.reg = reg }
    
    /// The order of this node: the number of interference edges
    var order: Int { return interferences.count }
}

extension IGNode : Hashable {
    var hashValue: Int { return reg.hashValue }
    static func == (l: IGNode, r: IGNode) -> Bool { return l.hashValue == r.hashValue }
}

/// A move
struct IGMove {
    let src: IGNode, dest: IGNode
    init(_ src: IGNode, _ dest: IGNode) {
        self.src = src
        self.dest = dest
    }
    func hasMember(_ node: IGNode) -> Bool {
        return src == node || dest == node
    }
    func other(_ node: IGNode) -> IGNode {
        return node == src ? dest : src
    }
}


extension IGMove : Hashable {
    static func == (l: IGMove, r: IGMove) -> Bool {
        return (l.src == r.src && l.dest == r.dest) || (l.src == r.dest && l.dest == r.src)
    }
    var hashValue: Int {
        let ordered = [src.hashValue, dest.hashValue].sorted(by: <)
        let mask = MemoryLayout<Int>.size*4
        return (ordered[0] << mask) + (ordered[1] & (Int.max >> mask))
    }
}


/// A graph representing interferences of register live ranges. Nodes in
/// this graph are registers, and edges are interferences. An edge between
/// two nodes means they cannot be positioned in the came CPU register.
final class InterferenceGraph {
    
    var nodes: [AIRRegisterHash: IGNode] = [:]
    
    var defs: [AIRRegisterHash: Set<MCInst>] = [:], uses: [AIRRegisterHash: Set<MCInst>] = [:]
    /// When an inst has its input registers changed, it's hash changes. `replacedInsts` maps
    /// the old inst hash (which is the value stored in the graph's `defs` and `uses` maps)
    /// to the new inst
    var replacedInsts: [MCInst: MCInst] = [:]
    var allMoves: Set<IGMove> = []
    
    init(function: MCFunction) {
        // Step 1: compute live ranges
        // http://www.cs.cornell.edu/courses/cs4120/2011fa/lectures/lec21-fa11.pdf
        
        var liveIn: [MCInst: Set<AIRRegisterHash>] = [:], liveOut: [MCInst: Set<AIRRegisterHash>] = [:]
        var allUsed: Set<AIRRegisterHash> = [], allMoveEdges: [(AIRRegisterHash, AIRRegisterHash)] = []
        
        // flatten all blocks, TODO: take into
        var workList = function.insts
        
        for node in function.insts {
            liveIn[node] = []
            liveOut[node] = []
            // record all registers
            let regs = node.def.union(node.used)
            allUsed.formUnion(regs)
            if case .mov(.reg(let d), .reg(let s)) = node {
                allMoveEdges.append((d.hash, s.hash))
            }
            for reg in regs {
                defs[reg] = []
                uses[reg] = []
            }
        }
        
        while let n = workList.popLast() {
            
            // simple cheat impl: only works for 1 bb
            func successors() -> [MCInst] {
                guard let i = function.insts.index(where: {$0 == n}) else { return [] }
                let next = function.insts.index(after: i)
                guard next != function.insts.endIndex else { return [] }
                return [function.insts[next]]
            }
            // simple cheat impl: only works for 1 bb
            func predecessors() -> [MCInst] {
                guard let i = function.insts.index(where: {$0 == n}) else { return [] }
                let next = function.insts.index(before: i)
                guard i != function.insts.startIndex else { return [] }
                return [function.insts[next]]
            }
            
            var nodeOut: Set<AIRRegisterHash> = []
            // out[n] = ∪ of (for nʹ ∈ succ(n) do (in[nʹ]))
            for succ in successors() {
                guard let succLiveIn = liveIn[succ] else { continue }
                nodeOut.formUnion(succLiveIn)
            }
            
            // in[n] = use[n] ∪ (out[n] — def [n])
            let nodeIn = n.used.union(nodeOut.subtracting(n.def))
            
            // if changed the in set, add the preds to the worklist
            if nodeIn != liveIn[n] {
                for pred in predecessors() {
                    workList.append(pred)
                }
            }
            
            // record that this inst is a use/def of the args
            for def in n.def { defs[def]!.insert(n) }
            for use in n.used { uses[use]!.insert(n) }
            
            // set the lists
            liveIn[n] = nodeIn
            liveOut[n] = nodeOut
        }
        
        /// Utility calculates whether a reg isnt reserved
        func isGeneralPurposeReg(_ reg: AIRRegisterHash) -> Bool {
            return !function.target.reservedRegisters.map({$0.hash}).contains(reg)
        }

        // construct the graph from the liveness info
        for (_, live) in liveIn {
            // all values which are alive into this node
            var list = Array(live)
            
            // for every element in the array
            while let reg = list.popLast() {
                guard isGeneralPurposeReg(reg) else { continue }
                // record it is live at the same time
                // as all the ones before it
                for other in list {
                    guard isGeneralPurposeReg(other) else { continue }
                    recordInterference(reg, with: other)
                }
            }
        }
        
        for (dest, src) in allMoveEdges {
            guard isGeneralPurposeReg(dest), isGeneralPurposeReg(src) else { continue }
            let s = createNode(for: src), d = createNode(for: dest)
            allMoves.insert(IGMove(s, d))
        }
        
        // add all registers with no interferences
        for unused in allUsed where !nodes.values.contains(where: {$0.reg == unused}) && isGeneralPurposeReg(unused) {
            nodes[unused] = IGNode(reg: unused)
        }
        
    }
    
    func getUpdatedInst(_ inst: MCInst) -> MCInst {
        var i = inst
        while let mapped = replacedInsts[i] {
            i = mapped
        }
        return i
    }
    func contains(_ node: IGNode) -> Bool {
        return nodes.values.contains(node)
    }
}

private extension InterferenceGraph {
    
    /// Creates a node
    func createNode(for reg: AIRRegisterHash) -> IGNode {
        if let node = nodes[reg] { return node }
        let node = IGNode(reg: reg)
        nodes[reg] = node
        return node
    }
    
    func recordInterference(_ reg1: AIRRegisterHash, with reg2: AIRRegisterHash) {
        // add to graph
        let node1 = createNode(for: reg1), node2 = createNode(for: reg2)
        addEdge(node1, node2)
    }
    
    /// - precondition: The nodes are already in the graph
    func addEdge(_ node1: IGNode, _ node2: IGNode) {
        node1.interferences.insert(node2)
        node2.interferences.insert(node1)
    }
}

extension InterferenceGraph {

    /// Removes the node from the graph, preserves the node's interferences
    /// (so it can be added back) but removes all other node's interferences
    /// with it
    func remove(_ node: IGNode) {
        for edge in node.interferences {
            edge.interferences.remove(node)
        }
        nodes.removeValue(forKey: node.reg)
    }
    func reinsert(_ node: IGNode) {
        for edge in node.interferences {
            addEdge(node, edge)
        }
        nodes[node.reg] = node
    }
    
    /// Combines these nodes
    /// - note: removes `v` from the graph
    /// - returns: the resulting node: `u`
    func combine(_ u: IGNode, _ v: IGNode, allocator: ColouringRegisterAllocator) -> IGNode {
        // rewire up the edges
        for interference in v.interferences {
            addEdge(u, interference)
        }
        // unhook all uses of u
        allocator.remove(v)
        return u
    }
    
}

extension InterferenceGraph : CustomStringConvertible {
    var description: String {
        return nodes.map { node in node.value.description }.joined(separator: "\n")
    }
}

extension IGNode : CustomStringConvertible {
    var description: String {
        return "(\(reg.hashValue) \\== {\(interferences.map { String($0.reg.hashValue) }.joined(separator: ","))})"
    }
}
extension IGMove : CustomStringConvertible {
    var description: String {
        let ordered = [src.hashValue, dest.hashValue].sorted(by: <)
        return "{\(ordered[0]) : \(ordered[1])}"
    }
}

