//
//  SelectionDAG.swift
//  Vist
//
//  Created by Josef Willsher on 06/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


enum TargetRegister {
    /// General purpose registers
    case GPR
}

struct TargetMachine {
    let nativeIntSize: Int
}


extension Module {
    
    func emitAIR(builder: AIRBuilder) throws {
        
        for function in functions {
            let ps = try function.params?.map { try $0.lowerVIRToAIR(builder: builder) as! AIRFunction.Param } ?? []
            let airFn = AIRFunction(name: function.name, type: function.type.machineType(), params: ps)
            function.airFunction = airFn
        }
        
        for function in functions where function.hasBody {
            for bb in function.dominator.analysis {
                let airBB = AIRBlock()
                builder.insertPoint.block = airBB
                function.airFunction!.blocks.append(airBB)
                
                for case let inst as AIRLower & Inst in bb.instructions {
                    let air = try inst.lowerVIRToAIR(builder: builder)
                    inst.updateUsesWithAIR(air)
                }
                
                // tests below
                guard airBB.insts.count > 1 else { continue }
                
                for s in function.airFunction!.blocks[0].insts {
                    print(s.air)
                }
                
                let dag = SelectionDAG()
                dag.build(block: airBB)
                try dag.runInstructionSelection()
                
            }
            
            
        }
        
        
    }
    
}


extension AIRValue {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        fatalError()
    }
}
extension AIRFunction.Param {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        return DAGNode(op: .load, args: [dag.buildDAGNode(for: register)])
    }
}
extension AIRRegister {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        return DAGNode(op: .reg(self), args: [])
    }
}

extension IntImm {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        return DAGNode(op: .int(value), args: [])
    }
}

extension RetOp {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        let out = DAGNode(op: .store, args: [dag.buildDAGNode(for: result), dag.buildDAGNode(for: val.val)])
        return DAGNode(op: .ret, args: [], chainParent: out)
    }
}
extension BuiltinOp {
    func dagNode(dag: SelectionDAG) -> DAGNode {
        return DAGNode(op: .add, args: args.map { dag.buildDAGNode(for: $0.val) })
    }
}

final class SelectionDAG {
    
    var rootNode: DAGNode!
    let entryNode: DAGNode
    var allNodes: [DAGNode] = []
    
    init() {
        entryNode = DAGNode(op: .entry, args: [])
    }
    
    private var map: [Int: DAGNode] = [:]
    
    func node(for op: AIROp) -> DAGNode? {
        return map[op.hashValue]
    }
    
    func buildDAGNode(for val: AIRValue) -> DAGNode {
        if case let op as AIROp = val {
            if let already = self.node(for: op) { return already }
        }
        let v = val.dagNode(dag: self)
        allNodes.append(v)
        if case let op as AIROp = val { map[op.hashValue] = v }
        return v
    }
    
    func build(block: AIRBlock) {
        
        // loop over insts
        for op in block.insts {
            // get the value of the args, from the tree if already added
            let args: [DAGNode] = op.args.map { arg in
                guard case let op as AIROp = arg.val else { return buildDAGNode(for: arg.val) }
                if let already = self.node(for: op) { return already }
                return buildDAGNode(for: op)
            }
            // if we have a matching op in the tree, use that
            
            var alreadyNode: DAGNode? = nil
            for node in allNodes {
                if node.op == op.dagOp, args.count == node.args.count, args.elementsEqual(node.args, by: ===) {
                    alreadyNode = node
                    break
                }
            }
            let node = alreadyNode ?? buildDAGNode(for: op)
            map[op.hashValue] = node
            
            if node.op.hasSideEffects {
                rootNode = node
            }
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
        default: return false
        }
    }
}

final class DAGNode {
    
    let op: SelectionDAGOp
    
    let args: [DAGNode]
    var children: [DAGNode] = []
    
    init(op: SelectionDAGOp, args: [DAGNode], chainParent: DAGNode? = nil) {
        self.op = op
        self.args = args
        for arg in args {
            arg.children.append(self)
        }
        self.chainParent = chainParent
    }
    
    var chainParent: DAGNode? {
        willSet(newParent) {
            newParent?.chainChild = self
            chainParent?.chainChild = nil
        }
    }
    weak var chainChild: DAGNode?
    
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
        switch (self) {
        case (.entry): return "entry"
        case (.add): return "add"
        case (.reg(let a)): return "reg \(a.air)"
        case (.int(let a)): return "int \(a)"
        case (.load): return "load"
        case (.store): return "store"
        case (.ret): return "ret"
        case (.call): return "call"
        }
    }
}

extension DAGNode : CustomStringConvertible {
    var description: String {
        return "op=\(op), args=\(args.map { $0.op.description }.joined(separator: ", ")), parent=\(chainParent?.op.description ?? "nil"), children=\(children.map { $0.op.description }.joined(separator: ", "))"
    }
}




