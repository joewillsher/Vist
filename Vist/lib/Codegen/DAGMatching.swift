//
//  DAGMatching.swift
//  Vist
//
//  Created by Josef Willsher on 06/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

private protocol OpPattern {
    /// Does this node have the correct op, if so we can descend down it
    /// to continue pattern matching
    static func opMatches(node: DAGNode) -> Bool
    
    /// Does this whole subtree match this pattern
    static func matches(subtree: DAGNode) -> Bool
}

extension OpPattern {
    //    static func match(subtree: DAGNode) -> DAGNode? {
    //        guard opMatches(node: subtree) else {
    //            return nil
    //        }
    //
    //    }
}

private protocol SimpleOpPattern : OpPattern {
    static var op: SelectionDAGOp { get }
}

private protocol BinaryOpPattern : SimpleOpPattern {
    associatedtype PAT0 : OpPattern
    associatedtype PAT1 : OpPattern
    
    static var op: SelectionDAGOp { get }
}
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

private struct AddPattern<VAL0 : OpPattern, VAL1 : OpPattern> : CommutativeBinaryOpPattern {
    private typealias PAT0 = VAL0
    private typealias PAT1 = VAL1
    static var op: SelectionDAGOp { return .add }
}
private struct StorePattern<DEST : Reg, SRC : OpPattern> : BinaryOpPattern {
    private typealias PAT0 = DEST
    private typealias PAT1 = SRC
    static var op: SelectionDAGOp { return .store }
}
private struct LoadPattern<SRC : Reg> : UnaryOpPattern {
    private typealias PAT = SRC
    static var op: SelectionDAGOp { return .load }
}

private struct RetPattern<VAL: OpPattern> : UnaryOpPattern {
    private typealias PAT = VAL
    static var op: SelectionDAGOp { return .ret }
    static func matches(subtree: DAGNode) -> Bool {
        guard opMatches(node: subtree) else {
            return false
        }
        return VAL.matches(subtree: subtree.chainParent!)
    }
}

/// Matches any DAG tree without checking it
struct AnyOpPattern : OpPattern {
    private static func opMatches(node: DAGNode) -> Bool { return true }
    private static func matches(subtree: DAGNode) -> Bool { return true }
}


private typealias IADD64RR_Pattern = StorePattern<GPR, AddPattern<RegisterUse_Pattern, RegisterUse_Pattern>>
private typealias IADD64_Pattern = AddPattern<RegisterUse_Pattern, RegisterUse_Pattern>

private typealias RET_Pattern<T : OpPattern> = RetPattern<StorePattern<GPR, T>>
private typealias RegisterUse_Pattern = LoadPattern<GPR>




extension SelectionDAG {
    
    func runInstructionSelection() throws {
        
        let r = RET_Pattern<AnyOpPattern>.matches(subtree: rootNode)
        let r1 = IADD64_Pattern.matches(subtree: rootNode.chainParent!.args[1])
        
        print(r, r1, rootNode)
        
    }
    
}






