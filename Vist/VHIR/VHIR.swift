//
//  VHIR.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

//: [Previous](@previous)

protocol VHIR: class {
    var vhir: String { get }
}

enum VHIRError: ErrorType {
    case noFunctionBody, instNotInBB, cannotMoveBuilderHere, noParentBlock, noParamNamed(String)
}




protocol Type: VHIR {
}

final class BBParam: Value {
    var irName: String?
    var type: Type?
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    init(irName: String, type: Type) {
        self.irName = irName
        self.type = type
    }
}

final class IntType: Type {
    let size: Int
    
    init(size: Int) { self.size = size }
}
final class FunctionType: Type {
    let params: [Type], returns: Type
    
    init(params: [Type], returns: Type) {
        self.params = params
        self.returns = returns
    }
}

final class BinaryInst: Inst {
    let l: Operand, r: Operand
    var irName: String?
    
    var uses: [Operand] = []
    var args: [Operand] { return [l, r] }
    var type: Type? { return l.type }
    let instName: String
    weak var parentBlock: BasicBlock?
    
    init(name: String, l: Operand, r: Operand, irName: String? = nil) {
        self.instName = name
        self.l = l
        self.r = r
        self.irName = irName
    }
}

final class ReturnInst: Inst {
    var value: Operand
    var irName: String?
    
    var uses: [Operand] = []
    var args: [Operand] { return [value] }
    var type: Type? = nil
    var instName: String = "return"
    weak var parentBlock: BasicBlock?
    
    init(value: Operand, parentBlock: BasicBlock?) {
        self.value = value
        self.parentBlock = parentBlock
    }
    
    var vhir: String {
        return "return %\(value.name)"
    }
    
}


final class IntValue: Value {
    var irName: String?
    var type: Type? { return IntType(size: 64) }
    weak var parentBlock: BasicBlock?
    var uses: [Operand] = []
    
    init(irName: String, parentBlock: BasicBlock?) {
        self.irName = irName
        self.parentBlock = parentBlock
    }
}

// $instruction
// %identifier
// @function
// #basicblock

// MARK: VHIR gen, this is where I start making code to print

extension CollectionType where Generator.Element == Type {
    func typeTupleVHIR() -> String {
        let a = map { "\($0.vhir)" }
        return "(\(a.joinWithSeparator(", ")))"
    }
}


extension Value {
    var valueName: String {
        return "%\(name)\(type.map { ": \($0.vhir)" } ?? "")"
    }
}
extension Inst {
    var vhir: String {
        let a = args.map{$0.valueName}
        let w = a.joinWithSeparator(", ")
        return "%\(name) = $\(instName) \(w)"
    }
}
extension BasicBlock {
    var vhir: String {
        let p = parameters?.map { $0.vhir }
        let pString = p.map { "(\($0.joinWithSeparator(", ")))"} ?? ""
        let i = instructions.map { $0.vhir }
        let iString = "\n\t\(i.joinWithSeparator("\n\t"))\n"
        return "#\(name)\(pString):\(iString)"
    }
}
extension Function {
    var vhir: String {
        let b = blocks?.map { $0.vhir }
        let bString = b.map { " {\n\($0.joinWithSeparator("\n"))}" } ?? ""
        return "func @\(name) : \(type.vhir)\(bString)"
    }
}
extension IntType {
    var vhir: String { return "%Int\(size)" }
}
extension FunctionType {
    var vhir: String {
        return "\(params.typeTupleVHIR()) -> \(returns.vhir)"
    }
}
extension Module {
    var vhir: String {
        let f = functions.map { $0.vhir }
        return f.joinWithSeparator("\n\n")
    }
}






//: [Next](@next)
