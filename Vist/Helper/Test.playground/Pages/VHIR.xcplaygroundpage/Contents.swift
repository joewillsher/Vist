//: [Previous](@previous)

protocol VHIR: class {
    var vhir: String { get }
}

enum VHIRError: ErrorType {
    
}



final class Function: VHIR {
    var name: String
    var type: Type
    private var blocks: [BasicBlock]?
    
    init(name: String, type: Type) {
        self.name = name
        self.type = type
    }
    
    var hasBody: Bool { return (blocks?.count != 0) ?? false }
    
    func addBB(bb: BasicBlock) throws {
        if let _ = blocks {
            blocks?.append(bb)
        }
        else {
            blocks = [bb]
        }
    }
}



final class Module: VHIR {
    private var functions: [Function] = []
}








protocol Inst: VHIR {
    var args: [Value] { get }
    var type: Type { get }
    var irName: String { get }
    var numUsers: Int { get set }
    var instName: String { get }
    var parentBlock: BasicBlock { get }
}
extension Inst {
    func addUser() {
        numUsers += 1
    }
    
    var irName: String {
        return String(numUsers)
    }
}

protocol  Value: VHIR {
    var name: String { get }
    var type: Type { get }
}


protocol Type: VHIR {
}



final class BasicBlock: VHIR {
    var name: String
    var parameters: [Value]?
    var instructions: [Inst]
    
    init(name: String, parameters: [Value]?) {
        self.name = name
        self.parameters = parameters
        self.instructions = []
    }
    
    func addInstruction(instr: Inst) throws {
        instructions.append(instr)
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
    
    var numUsers = 1
    var args: [Value] { return [l, r] }
    var type: Type { return l.type }
    let instName: String
    var parentBlock: BasicBlock
    
    init(name: String, l: Value, r: Value) {
        self.instName = name
        self.l = l
        self.r = r
    }
}

final class IntValue: Value {
    var name: String = "a"
    var type: Type { return IntType(size: 64) }
}

// $instruction
// %identifier
// @function
// #basicblock







extension CollectionType where Generator.Element == Type {
    func typeTupleVHIR() -> String {
        let a = map { "\($0.vhir)" }
        return "(\(a.joinWithSeparator(", ")))"
    }
}


extension Value {
    var vhir: String {
        return "%\(name): \(type.vhir)"
    }
}
extension Inst {
    var vhir: String {
        let a = args.map{$0.vhir}
        let w = a.joinWithSeparator(", ")
        return "$\(irName) = $\(instName) \(w)"
    }
}
extension BasicBlock {
    var vhir: String {
        let p = parameters?.map { $0.vhir }
        let pString = p.map { " \($0.joinWithSeparator(", "))"} ?? ""
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
    var position: Inst? = nil
    var parentBlock: BasicBlock? = nil
    
    init(module: Module) {
        self.module = module
    }
}

extension Module {
    func getBuilder() -> Builder { return Builder(module: self) }

    func addFunction(function: Function) throws {
        functions.append(function)
    }
}


extension Builder {
    
    func setInsertPoint(inst: Inst) {
        position = inst
        parentBlock =
    }
    
}






let fnType = FunctionType(params: [IntType(size: 64), IntType(size: 64)], returns: IntType(size: 64))
let inst = BinaryInst(name: "iadd", l: IntValue(), r: IntValue())
let bb = BasicBlock(name: "entry", parameters: nil)
let fn = Function(name: "add", type: fnType)

let module = Module()
try fn.addBB(bb)
try bb.addInstruction(inst)
try? module.addFunction(fn)


print(module.vhir)





















//: [Next](@next)
