//
//  InterferenceGraph.swift
//  Vist
//
//  Created by Josef Willsher on 09/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class IGNode : Hashable {
    let reg: AIRRegisterHash
    var interferences: Set<IGNode>
    
    init(reg: AIRRegisterHash, interferences: Set<IGNode>) {
        self.reg = reg
        self.interferences = interferences
    }
    
    var hashValue: Int { return reg.hashValue }
    static func == (l: IGNode, r: IGNode) -> Bool { return l.hashValue == r.hashValue }
}


final class InterferenceGraph {
    
    private(set) var nodes: [AIRRegisterHash: IGNode] = [:]
    
    private func getOrMakeNode(for reg: AIRRegisterHash) -> IGNode {
        if let node = nodes[reg] { return node }
        let node = IGNode(reg: reg, interferences: [])
        nodes[reg] = node
        return node
    }
    
    private func recordInterference(_ reg: AIRRegisterHash, with other: AIRRegisterHash) {
        let orig = getOrMakeNode(for: reg), new = getOrMakeNode(for: other)
        _ = orig.interferences.insert(new)
        _ = new.interferences.insert(orig)
    }
    
    init(function: MCFunction) {
        
        // Step 1: compute live ranges
        // http://www.cs.cornell.edu/courses/cs4120/2011fa/lectures/lec21-fa11.pdf
        
        var liveIn: [MCInst: Set<AIRRegisterHash>] = [:], liveOut: [MCInst: Set<AIRRegisterHash>] = [:]
        
        // flatten all blocks, TODO: take into
        var workList = function.insts
        
        for node in function.insts {
            liveIn[node] = []
            liveOut[node] = []
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
            
            // if changed the in set, add them to the worklist
            if nodeIn != liveIn[n] {
                for pred in predecessors() {
                    workList.append(pred)
                }
            }
            
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
        
        
    }
    
}

