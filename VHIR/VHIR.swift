//
//  VHIR.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Able to be printed as a VHIR instruction
protocol VHIRElement: CustomDebugStringConvertible {
    /// VHIR code to print
    var vhir: String { get }
}

extension VHIRElement {
    var debugDescription: String { return vhir }
}

enum VHIRError: ErrorType {
    case noFunctionBody, hasBody, instNotInBB, bbNotInFn, cannotMoveBuilderHere, noParentBlock, noParamNamed(String), noUse, noType, noModule
    case notGenerator, paramsNotTyped, wrongBlockParams
    case builtinIncorrectOperands(inst: BuiltinInst, recieved: Int)
}

// instruction
// %identifier
// @function
// $basicblock

extension CollectionType where Generator.Element : VHIRElement {
    func vhirValueTuple() -> String {
        let a = map { $0.vhir }
        return "(\(a.joinWithSeparator(", ")))"
    }
}
extension CollectionType where Generator.Element == Ty {
    func vhirTypeTuple() -> String {
        let a = map { $0.vhir }
        return "(\(a.joinWithSeparator(", ")))"
    }
    func vhirTypeStruct() -> String {
        let a = map { "\($0.vhir)" }
        return "{ \(a.joinWithSeparator(", ")) }"
    }
}


extension Value {
    var valueName: String {
        return "\(name)\(type.map { ": \($0.vhir)" } ?? "")"
    }
    var vhir: String {
        return valueName
    }
}
extension BasicBlock {
    var vhir: String {
        let p = parameters?.count > 0 ? parameters?.map({ $0.vhir }) : nil
        let pString = p.map { "(\($0.joinWithSeparator(", ")))"} ?? ""
        let i = instructions.map { $0.vhir }
        let iString = "\n  \(i.joinWithSeparator("\n  "))\n"
        let preds = predecessors.map { $0.name }
        let predComment = predecessors.isEmpty ? "" : "\t\t\t// preds: \(preds.joinWithSeparator(", "))"
        return "$\(name)\(pString):\(predComment)\(iString)"
    }
}
extension Function {
    var vhir: String {
        let b = blocks?.map { $0.vhir }
        let bString = b.map { " {\n\($0.joinWithSeparator("\n"))}" } ?? ""
        let conv = type.callingConvention.name
        return "func @\(name) : &\(conv) \(type.vhir)\(bString)"
    }
}

extension Module {
    var vhir: String {
        let t = typeList.map { $0.declVHIR }
        let f = functions.map { $0.vhir }
        return "\n" + t.joinWithSeparator("\n") + "\n\n" + f.joinWithSeparator("\n\n")
    }
}







extension FnType {
    var vhir: String {
        return "\(params.vhirTypeTuple()) -> \(returns.vhir)"
    }
}
extension BuiltinType {
    var vhir: String {
        return "%\(explicitName)"
    }
}
extension StorageType {
    var vhir: String {
        return members.map { $0.type }.vhirTypeStruct()
    }
}
extension TupleType {
    var vhir: String {
        return members.vhirTypeTuple()
    }
}
extension TypeAlias {
    var declVHIR: String {
        return "type %\(name) = \(targetType.vhir)"
    }
    var vhir: String {
        return "%\(name)"
    }
}


extension Inst {
    var useComment: String {
        let u = uses.map { $0.user?.name ?? "" }
        return uses.isEmpty ? "" : " \t// user\(uses.count == 1 ? "" : "s"): \(u.joinWithSeparator(", "))"
    }
}


