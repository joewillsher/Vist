//
//  DAGMatching.swift
//  Vist
//
//  Created by Josef Willsher on 06/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// A pattern which matches an Op on the SelectionDAG
protocol OpPattern {
    /// Does this node have the correct op, if so we can descend down it
    /// to continue pattern matching
    static func opMatches(node: DAGNode) -> Bool
    
    /// Does this whole subtree match this pattern
    static func matches(subtree: DAGNode) -> Bool
}

/// A simple op pattern; it matches this node if the node represents
/// the operation `op`
private protocol SimpleOpPattern : OpPattern {
    static var op: SelectionDAGOp { get }
}

/// A binary simple op, this checks that the 2 operands match the
/// patterns PAT0 and PAT1
private protocol BinaryOpPattern : SimpleOpPattern {
    associatedtype PAT0 : OpPattern
    associatedtype PAT1 : OpPattern
    
    static var op: SelectionDAGOp { get }
}
/// A unary simple op, this checks that the single operand matches the
/// pattern PAT
private protocol UnaryOpPattern : SimpleOpPattern {
    associatedtype PAT : OpPattern
    static var op: SelectionDAGOp { get }
}

extension SimpleOpPattern {
    /// Does this node have the correct op, if so we can descend down it
    /// to continue pattern matching
    static func opMatches(node: DAGNode) -> Bool {
        return SelectionDAGOp.nodesMatch(op, node.op)
    }
}
extension BinaryOpPattern {
    static func matches(subtree: DAGNode) -> Bool {
        guard opMatches(node: subtree) else {
            return false
        }
        guard PAT0.opMatches(node: subtree.args[0]), PAT1.opMatches(node: subtree.args[1]) else {
            return false
        }
        return PAT0.matches(subtree: subtree.args[0]) && PAT1.matches(subtree: subtree.args[1])
    }
}
extension UnaryOpPattern {
    static func matches(subtree: DAGNode) -> Bool {
        guard opMatches(node: subtree) else { return false }
        return PAT.opMatches(node: subtree.args[0]) && PAT.matches(subtree: subtree.args[0])
    }
}

/// A commutative BinaryOpPattern, allows matching either of the two subtrees
private protocol CommutativeBinaryOpPattern : BinaryOpPattern { }

extension CommutativeBinaryOpPattern {
    static func matches(subtree: DAGNode) -> Bool {
        guard opMatches(node: subtree) else {
            return false
        }
        // check if the subtrees match in either direction
        guard PAT0.opMatches(node: subtree.args[0]), PAT1.opMatches(node: subtree.args[1]),
            PAT0.matches(subtree: subtree.args[0]), PAT1.matches(subtree: subtree.args[1])
            else {
                guard PAT0.opMatches(node: subtree.args[1]), PAT1.opMatches(node: subtree.args[0]) else {
                    return false
                }
                return PAT0.matches(subtree: subtree.args[1]) && PAT1.matches(subtree: subtree.args[0])
        }
        return true
    }
}

/// A pattern which matches a register node
protocol Reg : OpPattern {
}
extension Reg {
    static func opMatches(node: DAGNode) -> Bool {
        if case .reg = node.op { return true }
        return false
    }
    static func matches(subtree: DAGNode) -> Bool {
        // registers must only compare this node
        return opMatches(node: subtree)
    }
}


// MARK: Patterns

private class AddPattern<VAL0 : OpPattern, VAL1 : OpPattern> : CommutativeBinaryOpPattern {
    typealias PAT0 = VAL0
    typealias PAT1 = VAL1
    static var op: SelectionDAGOp { return .add }
}
private class StorePattern<DEST : Reg, SRC : OpPattern> : BinaryOpPattern {
    typealias PAT0 = DEST
    typealias PAT1 = SRC
    static var op: SelectionDAGOp { return .store }
}
private class LoadPattern<SRC : Reg> : UnaryOpPattern {
    typealias PAT = SRC
    static var op: SelectionDAGOp { return .load }
}

private class RetPattern : SimpleOpPattern {
    static var op: SelectionDAGOp { return .ret }
    static func matches(subtree: DAGNode) -> Bool {
        return opMatches(node: subtree)
    }
}

/// Matches any DAG subtree without checking it
struct AnyOpPattern : OpPattern {
    static func opMatches(node: DAGNode) -> Bool { return true }
    static func matches(subtree: DAGNode) -> Bool { return true }
}


/// A pattern which rewrites a subtree
protocol RewritingPattern {
    static func performRewrite(_: DAGNode, dag: SelectionDAG, emission: MCEmission) throws
}

/// A pattern which rewrites a data flow node, returns the out reg
protocol DataFlowRewritingPattern : RewritingPattern {
    static func rewrite(_: DAGNode, dag: SelectionDAG, emission: MCEmission) throws -> AIRRegister
}
/// A pattern which rewrites a side effecting node
protocol ControlFlowRewritingPattern : RewritingPattern {
    static func rewrite(_: DAGNode, dag: SelectionDAG, emission: MCEmission) throws
}

extension DataFlowRewritingPattern {
    static func performRewrite(_ node: DAGNode, dag: SelectionDAG, emission: MCEmission) throws {
        _ = try rewrite(node, dag: dag, emission: emission)
    }
}
extension ControlFlowRewritingPattern {
    static func performRewrite(_ node: DAGNode, dag: SelectionDAG, emission: MCEmission) throws {
        try rewrite(node, dag: dag, emission: emission)
    }
}


//     reg     ==>    reg
private class RegisterUseRewritingPattern :
    LoadPattern<GPR>,
    DataFlowRewritingPattern
{
    static func rewrite(_ node: DAGNode, dag: SelectionDAG, emission: MCEmission) -> AIRRegister {
        guard case .reg(let r) = op else { fatalError() }
        return r
    }
}

//      reg1  reg2
//        |    |
//      load  load     ==>    reg1    +   "addq reg1 reg2"
//         \  /                |
//          \/
//          add
//           |
private class IADD64RewritingPattern :
    AddPattern<LoadPattern<GPR>, LoadPattern<GPR>>,
    DataFlowRewritingPattern
{
    static func rewrite(_ add: DAGNode, dag: SelectionDAG, emission: MCEmission) -> AIRRegister {
        
        // get info about the registers
        let regs = add.args.map { load -> AIRRegister in
            guard case .reg(let r)? = load.args.first?.op else { fatalError() }
            return r
        }
        let r0 = regs[0], r1 = regs[1]
        // Rewrite the tree
        let replacement = DAGNode(op: .reg(r0), args: [])
        add.replace(with: replacement)
        // emit the asm
        emission.emit(MCInst.add(r0, r1))
        return r0 // return the out register
    }
}

//     ret     ==>    ❌   +   "retq"
private class RetRewritingPattern :
    RetPattern,
    ControlFlowRewritingPattern
{
    static func rewrite(_ node: DAGNode, dag: SelectionDAG, emission: MCEmission) {
        node.remove(dag: dag)
        emission.emit(MCInst.ret)
    }
}

//               |
//     destreg  val
//        \     /               |
//         \   /        ==>    val   +   "movq destreg val"
//         store
private class StoreRewritingPattern :
    StorePattern<GPR, AnyOpPattern>,
    ControlFlowRewritingPattern
{
    static func rewrite(_ store: DAGNode, dag: SelectionDAG, emission: MCEmission) throws {
        // get info about the dest
        guard case .reg(let dest) = store.args[0].op else { fatalError() }
        // Rewrite the tree
        
        try emission.withEmmited(store.args[1]) { reg in
            MCInst.mov(dest: dest, src: reg)
        }
        // rewrite this node with just the new
        store.remove(dag: dag)
    }
}


/// An object responsible for managing the emission of machine insts
final class MCEmission {
    
    var mcInsts: [MCInst] = []
    var dag: SelectionDAG
    
    init(dag: SelectionDAG) { self.dag = dag }
    
    func emit(_ op: MCInst) {
        if let wait = waitList.last {
            waitList.removeLast()
            waitList.append([op] + wait)
        }
        else {
            mcInsts.insert(op, at: 0)
        }
    }
    
    private var waitList: [[MCInst]] = []
    
    /// Emits the output register for this node, passes it to the callback
    /// which can use that to produce an inst. This inst is added to the final
    /// inst list so it comes after the preceeding insts.
    @discardableResult
    func withEmmited(_ node: DAGNode, closure: (AIRRegister) -> MCInst) throws {
        guard case let pattern as DataFlowRewritingPattern.Type = try node.match(emission: self) else { fatalError() }
        waitList.append([])
        defer { waitList.removeLast() }
        
        let reg = try pattern.rewrite(node, dag: dag, emission: self)
        let inst = closure(reg)
        
        mcInsts.insert(inst, at: 0)
        mcInsts.insert(contentsOf: waitList.last!, at: 0)
    }
}



extension SelectionDAG {
    
    /// - returns: An array of machine insts to represent this DAG
    func runInstructionSelection() throws -> [MCInst] {
        
        let emission = MCEmission(dag: self)
        var nodes = [rootNode!]
        
        // walk up from the DAG root, making sure to visit
        // any node before a chain parent
        while let node = nodes.last {
            nodes.removeLast()
            
            try node.match(emission: emission)
                .performRewrite(node, dag: self, emission: emission)
            
            if let r = node.chainParent {
                nodes.append(r)
            }
        }
        
        return emission.mcInsts
    }
    
    // known patterns
    fileprivate static let patterns: [(RewritingPattern & OpPattern).Type] = [
        IADD64RewritingPattern.self,
        RegisterUseRewritingPattern.self,
        RetRewritingPattern.self,
        StoreRewritingPattern.self,
        RegisterUseRewritingPattern.self
    ]
}

fileprivate extension DAGNode {
    
    /// - returns: a pattern which matches this subtree
    func match(emission: MCEmission) throws -> (RewritingPattern & OpPattern).Type {
        
        var matched: [(RewritingPattern & OpPattern).Type] = []
        
        for pattern in SelectionDAG.patterns {
            if pattern.matches(subtree: self) {
                matched.append(pattern)
            }
        }
        
        return matched.last!
    }
    
     func remove(dag: SelectionDAG) {
    for child in children {
            guard let i = child.args.index(where: {$0 === self}) else { continue }
            child.args.remove(at: i)
        }
        for child in chainChildren {
            if child.chainParent === self {
                child.chainParent = nil
            }
        }
    }

    func replace(with node: DAGNode) {
        for child in children {
            guard let i = child.args.index(where: {$0 === self}) else { continue }
            child.args[i] = node
        }
        for child in chainChildren {
            if child.chainParent === self {
                child.chainParent = node.op.hasSideEffects ? node : nil
            }
        }
    }
}


