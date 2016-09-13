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
    /// Move edges
    var moves: Set<IGNode> = []
    
    /// - returns: whether this node is move related iff it is not frozen
    var isMoveRelated: Bool { return !moves.isEmpty && allowsMoves }
    
    /// If true the node can be considered move related, if false
    /// the node has been *frozen*
    private var allowsMoves = true
    
    /// - precondition: There exists an edge to node
    func edgeIsMoveRelated(_ node: IGNode) -> Bool {
        return moves.contains(node)
    }
    
    init(reg: AIRRegisterHash) { self.reg = reg }
    
    /// The order of this node: the number of interference edges
    var order: Int { return interferences.count }
    
    func freezeMoves() { allowsMoves = false }
    func unfreezeMoves() { allowsMoves = true }
}

extension IGNode : Hashable {
    var hashValue: Int { return reg.hashValue }
    static func == (l: IGNode, r: IGNode) -> Bool { return l.hashValue == r.hashValue }
}


/// A graph representing interferences of register live ranges. Nodes in
/// this graph are registers, and edges are interferences. An edge between
/// two nodes means they cannot be positioned in the came CPU register.
final class InterferenceGraph {
    
    private(set) var nodeMap: [AIRRegisterHash: IGNode] = [:]
    var nodes: Set<IGNode> { return Set(nodeMap.values) }
    
    var defs: [AIRRegisterHash: Set<MCInst>] = [:], uses: [AIRRegisterHash: Set<MCInst>] = [:]
    /// When an inst has its input registers changed, it's hash changes. `replacedInsts` maps
    /// the old inst hash (which is the value stored in the graph's `defs` and `uses` maps)
    /// to the new inst
    var replacedInsts: [MCInst: MCInst] = [:]
    
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
        
        // construct the graph from the liveness info
        for (_, live) in liveIn {
            // all values which are alive into this node
            var list = Array(live)
            
            // for every element in the array
            while let reg = list.popLast() {
                // record it is live at the same time
                // as all the ones before it
                for other in list {
                    recordInterference(reg, with: other)
                }
            }
        }
        
        for (dest, src) in allMoveEdges {
            recordMoveEdge(dest, src)
        }
        
        // add all registers with no interferences
        for unused in allUsed where !nodeMap.values.contains(where: {$0.reg == unused}) {
            nodeMap[unused] = IGNode(reg: unused)
        }
        
    }
    
    func getUpdatedInst(_ inst: MCInst) -> MCInst {
        var i = inst
        while let mapped = replacedInsts[i] {
            i = mapped
        }
        return i
    }
}

private extension InterferenceGraph {
    
    /// Creates a node
    func createNode(for reg: AIRRegisterHash) -> IGNode {
        if let node = nodeMap[reg] { return node }
        let node = IGNode(reg: reg)
        nodeMap[reg] = node
        return node
    }
    
    func recordInterference(_ reg1: AIRRegisterHash, with reg2: AIRRegisterHash) {
        let node1 = createNode(for: reg1), node2 = createNode(for: reg2)
        addEdge(node1, node2)
    }
    func recordMoveEdge(_ reg1: AIRRegisterHash, _ reg2: AIRRegisterHash) {
        let node1 = createNode(for: reg1), node2 = createNode(for: reg2)
        addMoveEdge(node1, node2)
    }
    
    /// - precondition: The nodes are already in the graph
    func addEdge(_ node1: IGNode, _ node2: IGNode) {
        node1.interferences.insert(node2)
        node2.interferences.insert(node1)
    }
    /// - precondition: The nodes are already in the graph
    func addMoveEdge(_ node1: IGNode, _ node2: IGNode) {
        node1.moves.insert(node2)
        node2.moves.insert(node1)
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
        for edge in node.moves {
            edge.moves.remove(node)
        }
        // remove all nodes which have this key or an alias
        if let node = nodeMap[node.reg] {
            for n in nodeMap where node == n.value {
                nodeMap.removeValue(forKey: n.key)
            }
        }
    }
    func reinsert(_ node: IGNode) {
        for edge in node.interferences {
            addEdge(node, edge)
        }
        for edge in node.moves {
            addMoveEdge(node, edge)
        }
        nodeMap[node.reg] = node
    }
    /// Combines these nodes
    /// - note: removes `u` from the graph
    /// - returns: the resulting node
    func combine(_ u: IGNode, _ v: IGNode, allocator: ColouringRegisterAllocator) -> IGNode {
        // rewire up the edges
        for interference in u.interferences {
            addEdge(v, interference)
        }
        for move in u.moves where move != v {
            addMoveEdge(v, move)
        }
        // unhook all uses of u
        allocator.remove(u)
        // a lookup for u will yield v's node
        nodeMap[u.reg] = v
        return v
    }
    
}

extension InterferenceGraph : CustomStringConvertible {
    var description: String {
        return nodes.map { node in node.description }.joined(separator: "\n")
    }
}

extension IGNode : CustomStringConvertible {
    var description: String {
        return "\(reg.hashValue):\n  int: \(interferences.map { String($0.reg.hashValue) }.joined(separator: ","))\n  mov: \(moves.map { String($0.reg.hashValue) }.joined(separator: ","))\n  hasmove: \(allowsMoves)"

    }
}

