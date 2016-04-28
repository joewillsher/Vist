//
//  VIR.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Able to be printed as a VIR instruction
protocol VIRElement : CustomDebugStringConvertible {
    /// VIR code to print
    var vir: String { get }
}

extension VIRElement {
    var debugDescription: String { return vir }
}

enum VIRError : ErrorType {
    case noFunctionBody, hasBody, instNotInBB, bbNotInFn, cannotMoveBuilderHere, noParentBlock, noParamNamed(String), noUse, noType(StaticString), noModule
    case notGenerator, paramsNotTyped, wrongBlockParams
    case builtinIncorrectOperands(inst: BuiltinInst, recieved: Int)
}

// instruction
// %identifier
// @function
// $basicblock

extension CollectionType where Generator.Element : VIRElement {
    func virValueTuple() -> String {
        let a = map { $0.vir }        
        return "(\(a.joinWithSeparator(", ")))"
    }
}
extension CollectionType where Generator.Element == Type {
    func virTypeTuple() -> String {
        let a = map { $0.vir }
        return "(\(a.joinWithSeparator(", ")))"
    }
    func virTypeStruct() -> String {
        let a = map { "\($0.vir)" }
        return "{ \(a.joinWithSeparator(", ")) }"
    }
}


extension Value {
    /// `%1: %Int`
    var valueName: String {
        return "\(name)\(type.map { ": \($0.vir)" } ?? "")"
    }
    var vir: String {
        return valueName
    }
}
extension BasicBlock {
    var vir: String {
        let p = parameters?.count > 0 ? parameters?.map({ $0.vir }) : nil
        let pString = p.map { "(\($0.joinWithSeparator(", ")))"} ?? ""
        let i = instructions.map { $0.vir }
        let iString = "\n  \(i.joinWithSeparator("\n  "))\n"
        let preds = predecessors.map { $0.name }
        let predComment = predecessors.isEmpty ? "" : "\t\t\t// preds: \(preds.joinWithSeparator(", "))"
        return "$\(name)\(pString):\(predComment)\(iString)"
    }
}
extension Function {
    var vir: String {
        let b = blocks?.map { $0.vir }
        let bString = b.map { " {\n\($0.joinWithSeparator("\n"))}" } ?? ""
        let conv = type.callingConvention.name
        return "func @\(name) : \(conv) \(type.vir)\(bString)"
    }
}

extension Module {
    var vir: String {
        let t = typeList.map { $0.declVIR }
        let f = functions.map { $0.vir }
        let g = globalValues.map { "global \($0.vir)" }
        return
            "\n" +
            t.joinWithSeparator("\n") +
            "\n\n" +
            g.joinWithSeparator("\n") +
            "\n\n" +
            f.joinWithSeparator("\n\n") +
            "\n"
    }
}







extension FunctionType {
    var vir: String {
        return "\(params.virTypeTuple()) -> \(returns.vir)"
    }
}
extension BuiltinType {
    var vir: String {
        return "%\(explicitName)"
    }
}
extension NominalType {
    var vir: String {
        return members.map { $0.type }.virTypeStruct()
    }
}
extension ConceptType {
    var vir: String {
        let a = requiredProperties.map { "\($0.type.vir)" }
        return "existential < \(a.joinWithSeparator(", ")) >"
    }
}
extension TupleType {
    var vir: String {
        return members.virTypeTuple()
    }
}
extension TypeAlias {
    var declVIR: String {
        return "type %\(name) = \(targetType.vir)"
    }
    var vir: String {
        return "%\(name)"
    }
}


extension Inst {
    var useComment: String {
        let u = uses.map { $0.user?.name ?? "nil" }
        return uses.isEmpty ? "" : " \t// user\(uses.count == 1 ? "" : "s"): \(u.joinWithSeparator(", "))"
    }
}


func LLVMDumpTypeOf(val: LLVMValueRef) {
    LLVMDumpType(LLVMTypeOf(val))
}


