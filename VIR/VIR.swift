//
//  VIR.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Able to be printed as a VIR instruction
protocol VIRElement {
    /// VIR code to print
    var vir: String { get }
}

enum VIRError : Error {
    case noFunctionBody, hasBody, instNotInBB, bbNotInFn, cannotMoveBuilderHere, noParentBlock, noParamNamed(String), noUse, noType(StaticString), noModule
    case notGenerator(Any.Type), paramsNotTyped, wrongBlockParams
    case builtinIncorrectOperands(inst: BuiltinInst, recieved: Int)
    case noMangledName
    
    case notStructType(Type), notConceptType(Type), notTupleType(Type)
}

// instruction
// %identifier
// #type
// @function
// $basicblock

extension Collection where Iterator.Element : VIRElement {
    func virValueTuple() -> String {
        let a = map { $0.vir }        
        return "(\(a.joined(separator: ", ")))"
    }
}
extension Collection where Iterator.Element == Type {
    func virTypeTuple() -> String {
        let a = map { $0.vir }
        return "(\(a.joined(separator: ", ")))"
    }
    func virTypeStruct() -> String {
        let a = map { "\($0.vir)" }
        return "{ \(a.joined(separator: ", ")) }"
    }
}


extension Operand : VIRElement {
    /// `%1: %Int`
    var valueName: String {
        return "\(value?.name ?? "<NULL>")\(type.map { ": \($0.vir)" } ?? "")"
    }
    var name: String {
        return value?.name ?? "<NULL>"
    }
    var vir: String {
        return valueName
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
        let p = (parameters?.count ?? 0) > 0 ? parameters?.map({ $0.vir }) : nil
        let pString = p.map { "(\($0.joined(separator: ", ")))"} ?? ""
        let i = instructions.map { $0.vir }
        let iString = "\n  \(i.joined(separator: "\n  "))\n"
        let preds = predecessors.map { $0.name }
        let predComment = predecessors.isEmpty ? "" : "\t\t\t// preds: \(preds.joined(separator: ", "))"
        return "$\(name)\(pString):\(predComment)\(iString)"
    }
}
extension Function {
    var vir: String {
        let b = blocks?.map { $0.vir }
        let bString = b.map { " {\n\($0.joined(separator: "\n"))}" } ?? ""
        
        let params = self.params.map { zip(type.params, $0).map {
            ($1.convention?.name.appending(" ") ?? "") + $0.vir
            } } ?? type.params.map { "#\($0.prettyName)" }
        return "func @\(name) : \(type.callingConvention.name) (\(params.joined(separator: ", "))) -> \(type.returns.vir)\(bString)"
    }
}

extension Module {
    var vir: String {
        let t = typeList.values.map { $0.declVIR }
        let f = functions.map { $0.vir }
        let g = globalValues.map { "global \($0.vir)" }
        let w = witnessTables.map { $0.vir }
        return
            "\n" +
            t.joined(separator: "\n") +
            "\n\n" +
            g.joined(separator: "\n") +
            "\n\n" +
            f.joined(separator: "\n\n") +
            "\n\n" +
            w.joined(separator: "\n") +
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
        return "#\(explicitName)"
    }
}
extension NominalType {
    var vir: String {
        return members.map { $0.type }.virTypeStruct()
    }
}
extension ConceptType {
    var vir: String {
        let l = members.map { $0.type }.virTypeStruct()
        return l + " <\(requiredFunctions.map { "@\($0.name)::\($0.type.prettyName)" }.joined(separator: ", "))>"
    }
}
extension TupleType {
    var vir: String {
        return members.virTypeTuple()
    }
}
extension ModuleType {
    var declVIR: String {
        return "type #\(name) = \(label)\(targetType.vir)\(witnesses)"
    }
    var vir: String {
        return "#\(name)"
    }
    private var label: String {
        switch targetType {
        case is ConceptType: return "existential "
        case is ClassType: return "refcounted "
        default: return ""
        }
    }
    private var witnesses: String {
        let ws = [copyConstructor, deinitialiser, destructor].flatMap {$0}
        if ws.isEmpty { return "" }
        return " { \(ws.map { "\($0.name.demangleName()): @\($0.name)" }.joined(separator: ", ")) }"
    }
}


extension Inst {
    var useComment: String {
        let u = uses.map { $0.user?.name ?? "nil" }
        return uses.isEmpty ? "" : " \t// user\(uses.count == 1 ? "" : "s"): \(u.joined(separator: ", "))"
    }
}


/// Dump the LLVM type of a value
func LLVMDumpTypeOf(_ val: LLVMValueRef?) {
    LLVMDumpType(LLVMTypeOf(val!))
}


