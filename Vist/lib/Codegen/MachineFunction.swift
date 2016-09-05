//
//  MachineFunction.swift
//  Vist
//
//  Created by Josef Willsher on 04/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct MachineFunction {
    
}

typealias MachineInstBundle = [MachineInst]


enum X86Op {
    case mov
}

struct MachineInst {
    
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
                
                guard airBB.insts.count > 1 else { continue }
                
                let dag = SelectionDAG(block: airBB)
                
                print(dag)
                
            }
            
            
        }
        
        
    }
    
}


extension AIRValue {
    func dagNode() -> DAGNode {
        fatalError()
    }
}
extension AIRFunction.Param {
    func dagNode() -> DAGNode {
        return DAGNode(op: .load, args: [register.dagNode()])
    }
}
extension AIRRegister {
    func dagNode() -> DAGNode {
        return DAGNode(op: .reg(self), args: [])
    }
}

extension IntImm {
    func dagNode() -> DAGNode {
        return DAGNode(op: .int(value), args: [])
    }
}

extension RetOp {
    func dagNode() -> DAGNode {
        let out = DAGNode(op: .store, args: [result.dagNode(), val.val.dagNode()])
        return DAGNode(op: .ret, args: [], chainParent: out)
    }
}
extension BuiltinOp {
    func dagNode() -> DAGNode {
        return DAGNode(op: .mul, args: args.map { $0.val.dagNode() })
    }
}

final class SelectionDAG {
    
    let rootNode: DAGNode
    let entryNode: DAGNode
    
    init(block: AIRBlock) {
        entryNode = DAGNode(op: .entry, args: [])
        rootNode = block.insts.last!.dagNode()
        // TODO: emit for all side-effecting nodes, not just the last one
    }
    
}

enum SelectionDAGOp {
    case entry // < entry token or root
    // %0 = add %1 %2
    case mul
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




















