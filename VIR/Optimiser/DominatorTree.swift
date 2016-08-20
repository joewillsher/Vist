//
//  DominatorTree.swift
//  Vist
//
//  Created by Josef Willsher on 14/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// An block x [dominates](https://en.wikipedia.org/wiki/Dominator_(graph_theory)) an
/// object y if every path in the CFG from the entry block to y must go through x.
final class DominatorTree : FunctionAnalysis {
    
    let function: Function
    private(set) var root: Node
    
    /// A node in the dom tree graph
    final class Node {
        /// The block
        let block: BasicBlock
        /// The block's immediate dominator
        let iDom: Node?
        /// The nodes dominated by `self`
        var children: Set<Node> = []
        let level: Int
        
        init(block: BasicBlock, iDom: Node?) {
            self.block = block
            self.iDom = iDom
            self.level = iDom?.level.advanced(by: 1) ?? 0
        }
    }
    
    typealias Base = Function
    
    /// Constructs a dominator tree from the CFG of `function`
    ///
    /// Uses the [Lengauer-Tarjan algorithm](https://www.cs.princeton.edu/courses/archive/fall03/cs528/handouts/a%20fast%20algorithm%20for%20finding.pdf)
    /// as implemented [here](http://staff.cs.upt.ro/~chirila/teaching/upt/c51-pt/aamcij/7113/Fly0143.html)
    static func get(_ function: Function) -> DominatorTree {
        let tree = DominatorTree(function: function,
                                 root: Node(block: function.entryBlock!, iDom: nil))
        
        /// The depth first search of the tree
        let dfs = DepthFirstSearchTree.get(function: function)
        
        // TODO: speed this up
        let idoms = dfs.nodes.reversed().flatMap { node in
            dfs.immediateDominator(of: node)
        }
        
        for (node, idom) in zip(dfs.nodes, idoms.reversed()) {
            tree.add(block: node, dominatedBy: idom)
        }
        return tree
    }
    
    private init(function: Function, root: Node) {
        self.function = function
        self.root = root
    }
    
    /// - returns: a subtree of `self` descending from `node`
    /// - note: the levels are the same as the original tree
    func subtree(from node: Node) -> DominatorTree {
        return DominatorTree(function: function, root: node)
    }
    
    func ancestors(of node: Node) -> [Node] {
        var ancs: [Node] = []
        ancs.reserveCapacity(node.level)
        
        var c = node
        while let idom = c.iDom {
            ancs.append(idom)
            c = idom
        }
        return ancs
    }
}

extension DominatorTree {
    
    func inst(_ inst: Inst, dominates other: Inst) throws -> Bool {
        
        guard let b1 = inst.parentBlock, let b2 = other.parentBlock else { return false }
        
        if b1 === b2 {
            return try b1.index(of: inst) < b1.index(of: other)
        }
        return block(b1, dominates: b2)
    }
    
    /// - returns: true if `block` dominates `other`, so all paths to `other` go
    ///            through `block`
    func block(_ block: BasicBlock, dominates other: BasicBlock) -> Bool {
        return node(getNode(for: block), dominates: getNode(for: other))
    }
    
    
    func node(_ node: Node, dominates other: Node) -> Bool {
        
        var currentNode = other
        
        while let iDom = currentNode.iDom {
            if iDom == node {
                return true
            }
            currentNode = iDom
        }
        
        return false
    }
    
    /// `node sdom other` if `node dom other` and `node != other`
    func node(_ node: Node, strictlyDominates other: Node) -> Bool {
        return node.block !== other.block && self.node(node, dominates: other)
    }

}


extension DominatorTree.Node {
    
    /// - returns: the node in this tree representing `block`
    fileprivate func getNode(for block: BasicBlock) -> DominatorTree.Node? {
        if self.block === block { return self }
        
        for child in children {
            if let found = child.getNode(for: block) { return found }
        }
        return nil
    }
}

extension DominatorTree.Node : Hashable {
    var hashValue: Int { return block.hashValue }
    static func == (l: DominatorTree.Node, r: DominatorTree.Node) -> Bool {
        return l.block == r.block
    }
}

extension DominatorTree {
    
    /// Adds `block` to `iDom`’s children
    func add(block: BasicBlock, dominatedBy iDom: BasicBlock) {
        
        let iDomNode = getNode(for: iDom)
        if block === iDom { return } // this is implied
        let child = Node(block: block, iDom: iDomNode)
        
        iDomNode.children.insert(child)
    }
    
    func getNode(for block: BasicBlock) -> Node {
        return root.getNode(for: block)!
    }
}


/// A [depth first spanning tree](http://pages.cs.wisc.edu/~fischer/cs701.f07/lectures/Lecture19.4up.pdf)
/// constructed from the CFG of `function`. 
///
/// A DFST is formed by walking along each of the CFG’s edges until the end is reached, then backtracking
/// until there is another branch, walking along it, and repeating.
///
/// ***
/// Suppose there is a CFG path from a to b but a is not an ancestor of b. This means that some edge on 
/// the path is not a spanning-tree edge, so b must have been reached in the depth-first search before a
/// was (otherwise, after visiting a the search would continue along tree edges to b). Thus, dfnum(a) > dfnum(b).
///
/// Therefore, if we know that there is a path from a to b, we can test whether a is an ancestor of b just
/// by comparing the dfnum's of a and b.
/// 
/// [Source](http://staff.cs.upt.ro/~chirila/teaching/upt/c51-pt/aamcij/7113/Fly0143.html)
private struct DepthFirstSearchTree {
    
    /// The ordered list of basic block nodes
    var nodes: [BasicBlock] = []
    
    static func get(function: Function) -> DepthFirstSearchTree {
        var dfs = DepthFirstSearchTree()
        function.entryBlock!.doDepthFirstSearch(search: &dfs)
        return dfs
    }
    
    func contains(block: BasicBlock) -> Bool {
        return nodes.contains { $0 === block }
    }
    
    /// The `dfnum` function
    /// - returns: `block`'s index in the DFST
    func index(of block: BasicBlock) -> Int? {
        return nodes.index { $0 === block }
    }
    
    func node(_ l: BasicBlock, predecesses r: BasicBlock) -> Bool {
        return index(of: l)! < index(of: r)!
    }
}

// Ancestors & semidominators
extension DepthFirstSearchTree {
    
    /// - returns: whether `a` has ancestor `b` in the DFST
    private func node(_ a: BasicBlock, hasAncestor b: BasicBlock) -> Bool {
        return node(b, predecesses: a) && b.existsPath(to: a)
    }
    
    /// Nodes which are ancestors of `block` in the DFST: they occur above `block`
    private func ancestors(of block: BasicBlock) -> [BasicBlock] {
        
        var ancestors: [BasicBlock] = []
        
        for cand in nodes[0..<index(of: block)!] where node(block, hasAncestor: cand) {
            ancestors.append(cand)
        }
        
        return ancestors
    }
    
    /// `s` is the node of smallest dfnum having apathto `n` whose nodes (not counting `s` and `n`)
    /// are not ancestors of `n`. This description of semidominators does not explicitly say that
    /// `s` must be an ancestor of `n`, but of course any nonancestor with a path to `n` would have
    /// a higher dfnum than `n`'s own parent in the spanning tree, which itself has a path to `n` with
    /// no nonancestor internal nodes (actually, no internal nodes at all).
    ///
    /// - parameter block: `n`: the node who's semidominator we will find
    /// - returns: `s`: the semidominator of `block`
    func semidominator(of block: BasicBlock) -> BasicBlock {
        
        var candidates: [BasicBlock] = []
        
        // To find the semidominator of a node n, consider all predecessors v of n in the CFG.
        for pred in block.predecessors {
            
            // If pred is a proper ancestor of block in the spanning tree (so dfnum(pred) < dfnum(block)),
            // then pred is a candidate for semi(block).
            if node(pred, predecesses: block) {
                candidates.append(pred)
            }
                // If pred is a nonancestor of block (so dfnum(pred) > dfnum(block)),
                // then for each u that is an ancestor of pred (or u = pred), let semi(u) be a candidate for semi(block).
            else {
                for u in [pred] + pred.predecessors where !node(u, predecesses: block) {
                    candidates.append(semidominator(of: u))
                }
            }
        }
        
        return candidates
            .min(by: node(_:predecesses:))
            ?? block
    }
    
    /// Return the path through the DFST from `block` to `other`
    /// - returns: the path, excluding `other` and `block`
    func path(from block: BasicBlock, to other: BasicBlock) -> [BasicBlock]? {
        let behind = ancestors(of: other)
        if behind.isEmpty { return [] }
        guard let index = behind.index(where: {$0 === block}) else { return nil }
        
        return Array(behind[behind.index(after: index)..<behind.endIndex])
    }
}

// immediate dominators
extension DepthFirstSearchTree {
    
    /// On the spanning-tree path below semi(block) and above or including block,
    /// let y be the node with the smallest-numbered semidominator (minimum 
    /// dfnum(semi(y))). Then:
    /// ```
    /// idom(block) := semidom(y) === semidom(block) ?
    ///                     semidom(block) :
    ///                     idom(y)
    /// ```
    func immediateDominator(of block: BasicBlock) -> BasicBlock? {
        
        guard block.isReachableFromRoot(dfst: self) else { return nil }
        
        let semidom = semidominator(of: block)
        // Search the DFST path from the semidom to the node
        let searchPath = path(from: semidom, to: block)!
        
        // If the path is empty, the semidominator is the immediate dominator
        if searchPath.isEmpty { return semidom }
        
        // get list of `y`s along with their computed semidominators
        let subSemidominators = searchPath.map { y in
            (node: y, semidominator: semidominator(of: y))
        }
        // this is the first semidominator of y, in the form (y, semidom(y))
        let y = subSemidominators
            .min { node($0.semidominator, predecesses: $1.semidominator) }!
        
        if y.semidominator === semidom {
            return y.semidominator
        }
        
        return immediateDominator(of: y.node)
    }
    
}

extension BasicBlock {
    
    /// Searches `self`'s successors for `other`
    fileprivate func existsPath(to other: BasicBlock) -> Bool {
        var searched: [BasicBlock] = []
        return _existsPath(to: other, searched: &searched)
    }
    // recursive searches through successors, checking not to get
    // stuck in a loop
    private func _existsPath(to other: BasicBlock, searched: inout [BasicBlock]) -> Bool {
        for succ in successors where !searched.contains(where: {$0 === succ}) {
            searched.append(succ)
            if succ === other || succ._existsPath(to: other, searched: &searched) {
                return true
            }
        }
        
        return false
    }
    
    /// Constructs the DFST into `search`
    fileprivate func doDepthFirstSearch(search: inout DepthFirstSearchTree) {
        
        // add self
        search.nodes.append(self)
        
        for succ in successors where !search.contains(block: succ) {
            succ.doDepthFirstSearch(search: &search)
        }
    }
    
    var isJoinNode: Bool {
        // join(S) = the set of all nodes n, such that there are at least two non-null
        // paths in the flow graph that start at two distinct nodes in S and converge at n
        return predecessors.count > 1
        // because I only implement 1 break per block we can simply check pred count
    }
    
    fileprivate func isReachableFromRoot(dfst: DepthFirstSearchTree) -> Bool {
        return dfst.nodes.contains(self)
    }
}

extension DominatorTree : Sequence {
    
    /// When iterating over a dominator tree, we want to iterate through each level of the 
    /// tree before descending to the children
    func makeIterator() -> AnyIterator<BasicBlock> {
        
        var siblings: [DominatorTree.Node] = [root]
        var children: [DominatorTree.Node] = []
        
        return AnyIterator {
            // while we have a sibling entry
            guard let currentNode = siblings.last else { return nil }
            siblings.removeLast() // remove it
            // if siblings is *now* empty we add any children to this list
            
            // add this node's children to the child list
            children.append(contentsOf: currentNode.children)
            
            if siblings.isEmpty {
                // set the children list to be the current iter level
                siblings = children
                children.removeAll()
            }
            
            // and the value of this iteration is the node's block
            return currentNode.block
        }
    }
    
}

extension DominatorTree.Node {
    func getDescendants() -> [DominatorTree.Node] {
        return [self] + children.flatMap { $0.getDescendants() }
    }
}

extension BasicBlock : Hashable {
    var hashValue: Int { return name.hashValue }
    
    static func ==(l: BasicBlock, r: BasicBlock) -> Bool {
        return l === r
    }
}

extension DominatorTree : CustomStringConvertible {
    var description: String {
        return root.describe(indent: 0)
    }
}
extension DominatorTree.Node {
    private func describe(indent: Int) -> String {
        return "\(indent*"  ")-\(block.name)\n" +
            children.map { $0.describe(indent: indent+1) }.joined(separator: "")
    }
}

