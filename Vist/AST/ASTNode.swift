//
//  ASTNode.swift
//  Vist
//
//  Created by Josef Willsher on 20/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol ASTNode : Printable {}

// make this generic when protocols with associated type requirements can be used existentially
// use behaviour delegates (when released in swift 3) to make `let (delated) type: Ty { get }`
/// AST walker node
//protocol Typed {
//    var type: Ty? { get set }
//}


final class AST : ASTNode {
    var exprs: [ASTNode]
    
    init(exprs: [ASTNode]) {
        self.exprs = exprs
    }
    
    var type: Ty? = nil
}









protocol _Typed {
    var _type: Ty? { get set }
}

protocol Typed : _Typed {
    typealias Type: Ty
    var type: Type? { get set }
}

extension Typed {
    var _type: Ty? {
        get {
            return type as? Ty
        }
        set {
            if case let t as Type = newValue {
                type = t
            }
            else {
                if newValue == nil { fatalError("new value nil") }
                fatalError("associated type requirement specifies `\(Type.self)` type. provided value was `\(newValue.dynamicType)`")
            }
        }
    }
}




///// SomeType provides a method to return a Ty
//protocol SomeType {
//    func getType() -> Ty
//}
//
//// All Ty objects conform by returning self
//extension SomeType where Self : Ty {
//    func getType() -> Ty {
//        return self
//    }
//}
//
//
//protocol AnyType : Ty {
//    
//    init()
//    init<Type where Type : Ty>(_ s: Type)
//    
//    /// Some type object is a `Ty` behind a `.getType()`
//    var type: SomeType? { get set }
//    
//    /// Returns the Ty object inside the SomeType
//    func getType() -> Ty?
//}
//
//extension AnyType {
//    
//    init<Type where Type : Ty>(_ s: Type) {
//        self.init()
//        type = s
//    }
//    
//    func getType() -> Ty? {
//        return type?.getType()
//    }
//}
//
//
//// AnyType forwards its methods/properties to its SomeType wrapper
//extension AnyType {
//    func ir() -> LLVMTypeRef {
//        return getType()!.ir()
//    }
//    var debugDescription: String {
//        return getType()!.debugDescription
//    }
//}
//
//// TODO: work this out
//extension Typed where Type : AnyType {
//    
//    func getType() -> Ty? {
//        return type?.getType()
//    }
//}










