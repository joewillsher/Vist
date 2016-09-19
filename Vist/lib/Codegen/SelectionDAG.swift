//
//  SelectionDAG.swift
//  Vist
//
//  Created by Josef Willsher on 06/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension AIRValue {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        fatalError()
    }
}
extension AIRFunction.Param {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        // TODO: spill onto stack if too many params
        dag.precoloured[register.hash] = dag.target.paramRegister(at: index)
        return DAGNode(op: .load,
                       args: [dag.buildDAGNode(for: register)],
                       chainParent: dag.chainNode)
    }
}
extension AIRRegister {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        return DAGNode(op: .reg(self))
    }
}

extension IntImm {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        return DAGNode(op: .load,
                       args: [DAGNode(op: .int(value))],
                       chainParent: dag.chainNode)
    }
}

extension RetOp {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        dag.precoloured[result.hash] = dag.target.returnRegister
        let out = DAGNode(op: .store, args: [dag.buildDAGNode(for: result), dag.buildDAGNode(for: val.val)], chainParent: dag.chainNode).insert(into: dag)
        return DAGNode(op: .ret, chainParent: out)
    }
}
extension BuiltinOp {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        return DAGNode(op: .add, args: args.map { dag.buildDAGNode(for: $0.val) })
    }
}
extension AggregateImm {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        return DAGNode(op: .aggregate, args: elements.map { dag.buildDAGNode(for: $0) }, chainParent: dag.chainNode)
    }
}
extension StructExtractOp {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        return DAGNode(op: .aggregateExtract(index: index), args: [dag.buildDAGNode(for: self.aggr.val)], chainParent: dag.chainNode)
    }
}

final class SelectionDAG {
    
    var rootNode: DAGNode!
    let entryNode: DAGNode
    var allNodes: [DAGNode] = []
    let builder: AIRBuilder
    
    let target: TargetMachine.Type
    
    var precoloured: [AIRRegisterHash: TargetRegister] = [:]
    
    /// used in construction
    private var chainNode: DAGNode!
    
    init(builder: AIRBuilder, target: TargetMachine.Type) {
        self.entryNode = DAGNode(op: .entry)
        self.builder = builder
        self.target = target
    }
    
    // eew, hashing by AIR string
    private var map: [String: DAGNode] = [:]
    
    func buildDAGNode(for val: AIRValue) -> DAGNode {
        if let already = map[val.air] { return already }
        let v = val.dagNode(dag: self)
        map[val.air] = v
        allNodes.append(v)
        return v
    }
    
    func build(block: AIRBlock) {
        
        chainNode = entryNode
        defer { chainNode = nil }
        
        // loop over insts
        for op in block.insts {
            // get the value of the args, from the tree if already added
            let args: [DAGNode] = op.args.map { arg in
                buildDAGNode(for: arg.val)
            }
            // if we have a matching op in the tree, use that
            var alreadyNode: DAGNode? = nil
            for node in allNodes {
                if node.op == op.dagOp, args.count == node.args.count, args.elementsEqual(node.args, by: ===) {
                    alreadyNode = node
                    break
                }
            }
            // build a node if we don't
            let node = alreadyNode ?? buildDAGNode(for: op)
            
            // reroot the tree
            if node.op.hasSideEffects {
                rootNode = node
            }
            // root the next inst in this one
            chainNode = node
        }
    }
    
}

enum SelectionDAGOp {
    case entry // < entry token or root
    // %0 = add %1 %2
    case add
    case call
    // a reference to a register
    case reg(AIRRegister)
    case int(Int)
    /// load src
    case load
    /// store dest src
    case store
    
    case aggregate, aggregateExtract(index: Int)
    
    case ret
    
    var hasSideEffects: Bool {
        switch self {
        case .load, .store, .ret: return true
        default: return false
        }
    }
}
extension SelectionDAGOp : Equatable {
    static func == (l: SelectionDAGOp, r: SelectionDAGOp) -> Bool {
        switch (l, r) {
        case (.entry, .entry): return true
        case (.add, .add): return true
        case (.reg(let a), .reg(let b)): return a.air == b.air
        case (.int(let a), .int(let b)): return a == b
        case (.load, .load): return true
        case (.store, .store): return true
        case (.ret, .ret): return true
        case (.call, .call): return true
        case (.aggregate, .aggregate): return true
        case (.aggregateExtract(let a), .aggregateExtract(let b)): return a == b
        default: return false
        }
    }
    static func nodesMatch(_ l: SelectionDAGOp, _ r: SelectionDAGOp) -> Bool {
        switch (l, r) {
        case (.entry, .entry): return true
        case (.add, .add): return true
        case (.reg, .reg): return true
        case (.int, .int): return true
        case (.load, .load): return true
        case (.store, .store): return true
        case (.ret, .ret): return true
        case (.call, .call): return true
        case (.aggregate, .aggregate): return true
        case (.aggregateExtract, .aggregateExtract): return true
        default: return false
        }
    }
}

final class DAGNode {
    
    let op: SelectionDAGOp
    
    var args: [DAGNode]
    var children: [DAGNode] = []
    
    init(op: SelectionDAGOp, args: [DAGNode] = [], chainParent: DAGNode? = nil) {
        self.op = op
        self.args = args
        for arg in args {
            arg.children.append(self)
        }
        // update the chain
        self.chainParent = chainParent
        chainParent?.chainChildren.append(self)
    }
    
    var chainParent: DAGNode? {
        willSet(newParent) {
            newParent?.chainChildren.append(self)
            // TODO: update removal properly
            //chainParent?.chainChild = nil
        }
    }
    var chainChildren: [DAGNode] = []
    
    var glued: DAGNode? {
        didSet {
            if let chain = glued {
                chainParent = chain
            }
        }
    }
}

extension SelectionDAGOp : CustomStringConvertible {
    var description: String {
        switch self {
        case .entry: return "entry"
        case .add: return "add"
        case .reg(let a): return "reg \(a.air)"
        case .int(let a): return "int \(a)"
        case .load: return "load"
        case .store: return "store"
        case .ret: return "ret"
        case .call: return "call"
        case .aggregate: return "aggregate"
        case .aggregateExtract(let index): return "extract \(index)"
        }
    }
}

extension DAGNode : CustomStringConvertible {
    var description: String {
        return "op=\(op), args=\(args.map { $0.op.description }.joined(separator: ", ")), parent=\(chainParent?.op.description ?? "nil"), children=\(children.map { $0.op.description }.joined(separator: ", "))"
    }
}




