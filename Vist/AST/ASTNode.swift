//
//  ASTNode.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol ASTNode : TypeProvider, Printable {}

// make this generic when protocols with associated type requirements can be used existentially
// use behaviour delegates (when released in swift 3) to make `let (delated) type: Ty { get }`
/// AST walker node
protocol Typed {
    var type: Ty? { get set }
}


final class AST : ASTNode {
    var exprs: [ASTNode]
    
    init(exprs: [ASTNode]) {
        self.exprs = exprs
    }
    
    var type: Ty? = nil
}


// other AST prptocols
protocol Sized : Expr {
    var size: UInt32 { get set }
}

protocol ExplicitlyTyped {
    var explicitType: String { get }
}

protocol Literal : Expr {
}
