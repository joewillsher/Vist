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
private class LoadPattern<DEST : Reg, SRC : OpPattern> : BinaryOpPattern {
    typealias PAT0 = DEST
    typealias PAT1 = SRC
    static var op: SelectionDAGOp { return .load }
}

private class RetPattern : SimpleOpPattern {
    static var op: SelectionDAGOp { return .ret }
    static func matches(subtree: DAGNode) -> Bool {
        return opMatches(node: subtree)
    }
}
private class IntImmPattern : OpPattern {
    static func opMatches(node: DAGNode) -> Bool {
        if case .int = node.op { return true }
        return false
    }
    static func matches(subtree: DAGNode) -> Bool {
        // registers must only compare this node
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


//         |
//  reg1  reg2
//     \  /
//     load     ==>    reg1    +   "movq reg1 reg2"
//       |               |
private class RegisterUseRewritingPattern :
    LoadPattern<GPR, GPR>,
    DataFlowRewritingPattern
{
    static func rewrite(_ load: DAGNode, dag: SelectionDAG, emission: MCEmission) throws -> AIRRegister {
        guard case .reg(let dest) = load.args[0].op, case .reg(let src) = load.args[1].op else { fatalError() }
        load.replace(with: load.args[0])
        emission.emit(.mov(dest: dest, src: src))
        return dest
    }
}

//     reg     ==>     reg
//      |               |
private class RegisterRewritingPattern :
    Reg,
    DataFlowRewritingPattern
{
    static func rewrite(_ load: DAGNode, dag: SelectionDAG, emission: MCEmission) throws -> AIRRegister {
        guard case .reg(let reg) = load.op else { fatalError() }
        return reg
    }
}

//   reg  int
//     \  /
//     load     ==>     reg    +   "movq reg $int"
//       |               |
private class IntImmUseRewritingPattern :
    LoadPattern<GPR, IntImmPattern>,
    DataFlowRewritingPattern
{
    static func rewrite(_ load: DAGNode, dag: SelectionDAG, emission: MCEmission) throws -> AIRRegister {
        guard case .reg(let dest) = load.args[0].op, case .int(let val) = load.args[1].op else { fatalError() }
        load.replace(with: load.args[0])
        emission.emit(.movImm(dest: dest, val: val))
        return dest
    }
}


//      val0  val1     ==>   val0    +   "addq reg0 reg1"
//         \  /                |
//          add
//           |
//  (commutative but the `load-reg1` pattern is always used
//   as the out register)
private class IADD64RewritingPattern :
    AddPattern<AnyOpPattern, AnyOpPattern>,
    DataFlowRewritingPattern
{
    static func rewrite(_ add: DAGNode, dag: SelectionDAG, emission: MCEmission) throws -> AIRRegister {
        
        return try emission.withEmmited(add.args[0]) { r0 in
            try emission.withEmmited(add.args[1]) { r1 in
                // emit the asm
                emission.emit(.add(r0, r1))
            }
            // Rewrite the tree to point to the out reg
            add.replace(with: DAGNode(op: .reg(r0), args: []))
        }
    }
}

//    r1  r2   int r3
//     \  |     | /
//      load  load     ==>     r1    +   "addq reg1 $int"
//         \  /                |
//          add
//           |
private class IADD64ImmRewritingPattern :
    AddPattern<AnyOpPattern, IntImmUseRewritingPattern>,
    DataFlowRewritingPattern
{
    static func rewrite(_ add: DAGNode, dag: SelectionDAG, emission: MCEmission) throws -> AIRRegister {
        
        // get the out register
        let dest: (index: Int, val: Int) = add.args.enumerated().flatMap {
            // get the dest reg of the move
            guard $0.1.args.count == 2, case .int(let r) = $0.1.args[1].op else { return nil }
            return ($0.0, r)
            }.first!
        // the index of the out reg
        let otherIndex = dest.index == 0 ? 1 : 0
        let val = dest.val
        
        return try emission.withEmmited(add.args[otherIndex]) { r1 in
            add.replace(with: DAGNode(op: .reg(r1), args: []))
            // emit the asm
            emission.emit(.addImm(dest: r1, val: val))
        }
    }
}


//     ret     ==>    ❌   +   "retq"
private class RetRewritingPattern :
    RetPattern,
    ControlFlowRewritingPattern
{
    static func rewrite(_ node: DAGNode, dag: SelectionDAG, emission: MCEmission) {
        node.remove(dag: dag)
        emission.emit(.ret)
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
        
        try emission.withEmmited(store.args[1]) { reg in
            emission.emit(.mov(dest: dest, src: reg))
        }
        // rewrite this node with just the new
        store.remove(dag: dag)
    }
}


/// An object responsible for managing the emission of machine insts
final class MCEmission {
    
    private var mcInsts: [MCInst] = []
    var dag: SelectionDAG
    let target: TargetRegister.Type
    var precoloured: [AIRRegisterHash: TargetRegister] = [:]
    
    init(dag: SelectionDAG, target: TargetRegister.Type) {
        self.dag = dag
        self.target = target
    }
    
    func emit(_ op: MCInst) {
        if let wait = waitList.last {
            waitList.removeLast()
            waitList.append([op] + wait)
        }
        else {
            mcInsts.insert(op, at: 0)
        }
    }
    func constrain(reg: AIRRegisterHash, to targetReg: TargetRegister) {
        
    }
    
    private var waitList: [[MCInst]] = []
    
    /// Emits the output register for this node, passes it to the callback
    /// which can use that to produce an inst. This inst is added to the final
    /// inst list so it comes after the preceeding insts.
    @discardableResult
    func withEmmited(_ node: DAGNode, closure: (AIRRegister) throws -> ()) throws -> AIRRegister {
        guard case let pattern as DataFlowRewritingPattern.Type = try node.match(emission: self) else { fatalError() }
        
        waitList.append([])
        let reg = try pattern.rewrite(node, dag: dag, emission: self)
        let added = waitList.removeLast()
        
        // add this value first, so its last in the list
        try closure(reg)
        // add each value needed for that in reverse order
        for added in added.reversed() {
            emit(added)
        }
        return reg
    }
}



extension SelectionDAG {
    
    /// - returns: An array of machine insts to represent this DAG
    func runInstructionSelection() throws -> [MCInst] {
        
        let emission = MCEmission(dag: self, target: target)
        var nodes = [rootNode!]
        
        // walk up from the DAG root, making sure to visit
        // any node before a chain parent
        while let node = nodes.popLast() {
            
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
        RegisterUseRewritingPattern.self,
        RegisterRewritingPattern.self,
        IntImmUseRewritingPattern.self,
        IADD64RewritingPattern.self,
        IADD64ImmRewritingPattern.self,
        RetRewritingPattern.self,
        StoreRewritingPattern.self,
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


