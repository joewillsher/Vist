//
//  Print.swift
//  Vist
//
//  Created by Josef Willsher on 04/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


private let tab = "  "
private func * (a: Int, b: String) -> String {
    var l = String()
    l.reserveCapacity(a*b.characters.count)
    var c = 0
    while c < a {
        l += b
        c += 1
    }
    return l
}

protocol ASTPrintable {
    
    func _astDescription(indentLevel n: Int) -> _ASTPrintGroup

    var _astName: String { get }
}

extension ASTNode {
    
    func astDescription() -> String { return _astDescription(indentLevel: 0).desc(indentLevel: 0).desc }
    
    func dump() {
        print(astDescription())
    }
}

struct _ASTPrintGroup {
    let nodeName: String, parentIsTrivial: Bool
    let els: [(name: String, valueString: String)]
    
    func desc(indentLevel n: Int) -> (desc: String, isTrivial: Bool) {
        
        switch els.count {
        case 0:
            return (desc: "(\(nodeName))", isTrivial: true)
        case 1 where parentIsTrivial:
            let e = els[0]
            return (desc: "(\(nodeName): \(e.name)=\(e.valueString))", isTrivial: parentIsTrivial)
        case _:
            let s = els.map { el in "\((n+1)*tab)\(el.name)=\(el.valueString)," }.joinWithSeparator("\n")
            return (desc: "(\(nodeName):\n\(s)\n\(n*tab))",
                    isTrivial: false)

        }
        
    }
}

extension ASTPrintable {
    
    func _astDescription(indentLevel n: Int) -> _ASTPrintGroup {
        
        let children = Mirror(reflecting: self).children.filter { $0.label != "type" && $0.label != "_type" && $0.label != "parent" }
        
        let inside = children
            .flatMap { label, value -> (String, ASTPrintable)? in
                if let v = value as? ASTPrintable, let l = label {
                    return (l, v)
                }
                else { return nil }
            }
            .map { ($0.0, $0.1._astDescription(indentLevel: n+1)) }
        
        var isTrivial = true
        let s = inside.map { v -> (name: String, valueString: String) in
            let x = v.1.desc(indentLevel: n+1)
            if !x.isTrivial { isTrivial = false }
            return (name: v.0, valueString: x.desc)
        }
        
        return _ASTPrintGroup(nodeName: _astName, parentIsTrivial: isTrivial, els: s)
    }
}


extension Array : ASTPrintable {
    
    func _astDescription(indentLevel n: Int) -> _ASTPrintGroup {
        
        let des = flatMap { $0 as? ASTPrintable }
            .map { $0._astDescription(indentLevel: n+1) }
            .enumerate()
            .map { (name: "#\($0.index)", valueString: $0.element.desc(indentLevel: n+1).desc) }
        
        return _ASTPrintGroup(nodeName: _astName, parentIsTrivial: isEmpty, els: des)
    }
    
    var _astName: String { return "[]" }
    
}

extension AST : ASTPrintable {
    var _astName: String { return "AST" }
}
extension ConceptExpr : ASTPrintable {
    var _astName: String { return "concept_decl" }
}
extension StructExpr : ASTPrintable {
    var _astName: String { return "struct_decl" }
}
extension FuncDecl : ASTPrintable {
    var _astName: String { return "func_decl" }
}
extension VariableDeclGroup : ASTPrintable {
    var _astName: String { return "variable_decl_group" }
}
extension InitialiserDecl : ASTPrintable {
    var _astName: String { return "initialiser_decl" }
}
extension FunctionImplementationExpr : ASTPrintable {
    var _astName: String { return "func_impl_expr" }
}
extension FunctionCallExpr : ASTPrintable {
    var _astName: String { return "func_call_expr" }
}
extension VariableDecl : ASTPrintable {
    var _astName: String { return "variable_decl" }
}
extension IntegerLiteral : ASTPrintable {
    var _astName: String { return "int_literal" }
}
extension BooleanLiteral : ASTPrintable {
    var _astName: String { return "bool_literal" }
}
extension StringLiteral : ASTPrintable {
    var _astName: String { return "string_literal" }
}
extension FloatingPointLiteral : ASTPrintable {
    var _astName: String { return "float_literal" }
}
extension Int : ASTPrintable {
    var _astName: String { return "\(self)" }
}
extension UInt32 : ASTPrintable {
    var _astName: String { return "\(self)" }
}
extension Bool : ASTPrintable {
    var _astName: String { return "\(self)" }
}
extension String : ASTPrintable {
    var _astName: String { return "\"\(self)\"" }
}
extension Float : ASTPrintable {
    var _astName: String { return "\(self)" }
}
extension VoidExpr : ASTPrintable {
    var _astName: String { return "void_expr" }
}
extension NullExpr : ASTPrintable {
    var _astName: String { return "null" }
}
extension BinaryExpr : ASTPrintable {
    var _astName: String { return "binary_operator_expr" }
}
extension PrefixExpr : ASTPrintable {
    var _astName: String { return "prefix_operator_expr" }
}
extension PostfixExpr : ASTPrintable {
    var _astName: String { return "postfix_operator_expr" }
}
extension BlockExpr : ASTPrintable {
    var _astName: String { return "block_expr" }
}
extension ConditionalStmt : ASTPrintable {
    var _astName: String { return "if_stmt" }
}
extension ElseIfBlockStmt : ASTPrintable {
    var _astName: String { return "if_clause_stmt" }
}
extension VariableExpr : ASTPrintable {
    var _astName: String { return "variable_expr" }
}
extension TupleExpr : ASTPrintable {
    var _astName: String { return "tuple_expr" }
}
extension MutationExpr : ASTPrintable {
    var _astName: String { return "mutation_expr" }
}
extension PropertyLookupExpr : ASTPrintable {
    var _astName: String { return "property_lookup_expr" }
}
extension TupleMemberLookupExpr : ASTPrintable {
    var _astName: String { return "tuple_member_lookup_expr" }
}
extension ArrayExpr : ASTPrintable {
    var _astName: String { return "array_expr" }
}
extension ArraySubscriptExpr : ASTPrintable {
    var _astName: String { return "array_subscript_expr" }
}
extension MethodCallExpr : ASTPrintable {
    var _astName: String { return "method_call_expr" }
}
extension CommentExpr : ASTPrintable {
    var _astName: String { return "comment_expr" }
}
extension ForInLoopStmt : ASTPrintable {
    var _astName: String { return "for_in_loop_stmt" }
}
extension WhileLoopStmt : ASTPrintable {
    var _astName: String { return "while_loop_stmt" }
}
extension ReturnStmt : ASTPrintable {
    var _astName: String { return "return_stmt" }
}
extension YieldStmt : ASTPrintable {
    var _astName: String { return "yield_stmt" }
}
extension ClosureExpr : ASTPrintable {
    var _astName: String { return "closure_expr" }
}



