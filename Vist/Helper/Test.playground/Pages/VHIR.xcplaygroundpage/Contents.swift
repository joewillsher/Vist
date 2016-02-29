//: [Previous](@previous)

protocol VHIR: class {
    var vhir: String { get }
}

enum VHIRError: ErrorType {
    case noFunctionBody, instNotInBB, cannotMoveBuilderHere, noParentBlock, noParamNamed(String)
}


/// The module type, functions get put into this
final class Module: VHIR {
    private var functions: [Function] = []
}

/// A VHIR function, has a type and ismade of a series
/// of basic blocks
final class Function: VHIR {
    var name: String
    var type: FunctionType
    var paramNames: [String]
    private var blocks: [BasicBlock]?
    
    init(name: String, type: FunctionType, paramNames: [String]) {
        self.name = name
        self.type = type
        self.paramNames = paramNames
    }
    
    var hasBody: Bool { return (blocks?.count != 0) ?? false }
    
    func getEntryBlock() throws -> BasicBlock {
        guard let first = blocks?.first else { throw VHIRError.noFunctionBody }
        return first
    }
    func getLastBlock() throws -> BasicBlock {
        guard let last = blocks?.last else { throw VHIRError.noFunctionBody }
        return last
    }
    
    func paramNamed(name: String) throws -> Value {
        guard let p = try blocks?.first?.paramNamed(name) else { throw VHIRError.noParamNamed(name) }
        return p
    }
    
    
}

/// A collection of instructions
///
/// Params are passed into the phi nodes as
/// parameters ala swift
final class BasicBlock: VHIR {
    var name: String
    var parameters: [Value]?
    var instructions: [Inst]
    var parentFunction: Function
    
    init(name: String, parameters: [Value]?, parentFunction: Function) {
        self.name = name
        self.parameters = parameters
        self.instructions = []
        self.parentFunction = parentFunction
    }
    
    func addInstruction(instr: Inst) throws {
        instructions.append(instr)
    }
    
    func indexOfInst(inst: Inst) -> Int? {
        return instructions.indexOf { $0 === inst }
    }
    func indexOfVal(val: Value) -> Int? {
        return instructions.indexOf { $0 === val }
    }

    
    func paramNamed(name: String) throws -> Value {
        guard let i = parameters?.indexOf({$0.irName == name}), let p = parameters?[i] else { throw VHIRError.noParamNamed(name) }
        return p
    }
}

/// A value, instruction results, literals, etc
protocol Value: VHIR {
    var irName: String? { get set }
    var type: Type? { get }
    var parentBlock: BasicBlock? { get }
}
/// An instruction o
protocol Inst: Value {
    var args: [Value] { get }
    var type: Type? { get }
    var instName: String { get }
}

extension Value {
    
    func getInstNumber() -> String? {
        guard let blocks = parentBlock?.parentFunction.blocks else { return nil }
        
        var count = 0
        blockLoop: for block in blocks {
            for inst in block.instructions {
                if inst === self { break blockLoop }
                if inst.irName == nil { count += 1 }
            }
        }
        
        return String(count)
    }
    
}


protocol Type: VHIR {
}

final class BBParam: Value {
    var irName: String?
    var type: Type?
    var parentBlock: BasicBlock?
    
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
    let l: Value, r: Value
    var irName: String?
    
    var args: [Value] { return [l, r] }
    var type: Type? { return l.type }
    let instName: String
    var parentBlock: BasicBlock?
    
    init(name: String, l: Value, r: Value, irName: String? = nil, block: BasicBlock?) {
        self.instName = name
        self.l = l
        self.r = r
        self.irName = irName
        self.parentBlock = block
    }
}

final class ReturnInst: Inst {
    var value: Value
    var irName: String?
    
    var args: [Value] { return [value] }
    var type: Type? = nil
    var instName: String = "return"
    var parentBlock: BasicBlock?
    
    init(value: Value, parentBlock: BasicBlock?) {
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
    var parentBlock: BasicBlock?

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
    var name: String {
        get {
            return irName ?? getInstNumber() ?? "<null>"
        }
        set {
            irName = newValue
        }
    }

    var vhir: String {
        return valueName
    }
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





final class Builder {
    var module: Module
    var position: Int?
    var block: BasicBlock?
    var function: Function?
    
    init(module: Module) {
        self.module = module
    }
}

extension Module {
    func getBuilder() -> Builder { return Builder(module: self) }

    func addFunction(name: String, type: FunctionType, paramNames: [String]) throws -> Function {
        let f = Function(name: name, type: type, paramNames: paramNames)
        functions.append(f)
        return f
    }
}


extension Builder {
    
    func setInsertPoint(node: VHIR) throws {
        switch node {
        case let f as Function:
            guard let b = try? f.getLastBlock() else {
                function = f; return
            }
            block = b
            position = b.instructions.endIndex
            
        case let b as BasicBlock:
            block = b
            position = b.instructions.endIndex
            
        case let i as Inst:
            guard let p = i.parentBlock?.indexOfInst(i) else { throw VHIRError.instNotInBB }
            block = i.parentBlock
            position = p
            
        default:
            throw VHIRError.cannotMoveBuilderHere
        }
    }
    
    func addBasicBlock(name: String, params: [Value]? = nil) throws -> BasicBlock {
        if let function = function, let _ = function.blocks {
            let bb = BasicBlock(name: name, parameters: params, parentFunction: function)
            function.blocks?.append(bb)
            block = bb
            return bb
        }
        else if let function = function {
            let fnParams = zip(function.paramNames, function.type.params).map(BBParam.init).map { $0 as Value }
            let bb = BasicBlock(name: name, parameters: fnParams + (params ?? []), parentFunction: function)
            function.blocks = [bb]
            block = bb
            return bb
        }
        throw VHIRError.noFunctionBody
    }
    
    func createBinaryInst(name: String, l: Value, r: Value, irName: String? = nil) throws -> BinaryInst {
        guard let p = block else { throw VHIRError.noParentBlock }
        let i = BinaryInst(name: name, l: l, r: r, irName: irName, block: p)
        try p.addInstruction(i)
        return i
    }
    
    func createReturnInst(value: Value) throws -> ReturnInst {
        guard let p = block else { throw VHIRError.noParentBlock }
        let r = ReturnInst(value: value, parentBlock: p)
        try p.addInstruction(r)
        return r
    }
    
}



let module = Module()
let builder = module.getBuilder()


let fnType = FunctionType(params: [IntType(size: 64), IntType(size: 64)], returns: IntType(size: 64))
let fn = try module.addFunction("add", type: fnType, paramNames: ["a", "b"])

try builder.setInsertPoint(fn)
try builder.addBasicBlock("entry")
let s = try builder.createBinaryInst("iadd", l: try fn.paramNamed("a"), r: try fn.paramNamed("b"), irName: nil)
let t = try builder.createBinaryInst("iadd", l: s, r: try fn.paramNamed("b"), irName: nil)
let w = try builder.createBinaryInst("iadd", l: s, r: t, irName: nil)
try builder.createReturnInst(w)
s.name = "foo"

print(module.vhir)
/*
 func @add : (%Int64, %Int64) -> %Int64 {
 #entry(%a: %Int64, %b: %Int64):
	%meme = $iadd %a: %Int64, %b: %Int64
	return %meme
 }
*/











//: [Next](@next)
