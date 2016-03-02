//
//  VHIR.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol VHIR {
    /// VHIR code to print
    var vhir: String { get }
}

enum VHIRError: ErrorType {
    case noFunctionBody, instNotInBB, cannotMoveBuilderHere, noParentBlock, noParamNamed(String), noUse, noType, noModule
    case notGenerator, paramsNotTyped
}

// instruction
// %identifier
// @function
// $basicblock


private extension CollectionType where Generator.Element : VHIR {
    func vhirValueTuple() -> String {
        let a = map { $0.vhir }
        return "(\(a.joinWithSeparator(", ")))"
    }
}
private extension CollectionType where Generator.Element == Ty {
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
        return "$\(name)\(pString):\(iString)"
    }
}
extension Function {
    var vhir: String {
        let b = blocks?.map { $0.vhir }
        let bString = b.map { " {\n\($0.joinWithSeparator("\n"))}" } ?? ""
        return "func @\(name) : \(type.vhir)\(bString)"
    }
}

extension Module {
    var vhir: String {
        let t = typeList.map { $0.declVHIR }
        let f = functions.map { $0.vhir }
        return t.joinWithSeparator("\n") + "\n\n" + f.joinWithSeparator("\n\n")
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
        let u = uses.map { $0.user!.name }
        return uses.isEmpty ? "" : " \t// uses: \(u.joinWithSeparator(", "))"
    }
}


extension IntLiteralInst {
    var vhir: String {
        return "\(name) = int_literal \(value.value) \(useComment)"
    }
}
extension StructInitInst {
    var vhir: String {
        return "\(name) = struct %\(type!.explicitName) \(args.vhirValueTuple()) \(useComment)"
    }
}
extension ReturnInst {
    var vhir: String {
        return "return \(value.name)"
    }
}
extension VariableInst {
    var vhir: String {
        return "variable_decl \(name) = \(value.valueName) \(useComment)"
    }
}
extension FunctionCallInst {
    var vhir: String {
        return "\(name) = call @\(function.name) \(args.vhirValueTuple()) \(useComment)"
    }
}
extension BuiltinBinaryInst {
    var vhir: String {
        let a = args.map{$0.valueName}
        let w = a.joinWithSeparator(", ")
        return "\(name) = \(instName) \(w) \(useComment)"
    }
}


