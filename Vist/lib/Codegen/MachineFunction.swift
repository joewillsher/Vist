//
//  MachineFunction.swift
//  Vist
//
//  Created by Josef Willsher on 04/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum MCInst {
    // arithmetic
    case add(AIRRegister, MCInstAddressingMode)
    case sub(AIRRegister, MCInstAddressingMode)
    // move
    case mov(dest: MCInstAddressingMode, src: MCInstAddressingMode)
    // stack
    case push(AIRRegister), pop(AIRRegister)
    // proc
    case ret//, call(String)
    
    var asm: String {
        switch self {
        case .add(let a, let b):        return "addq \(a.name), \(b.asm)"
        case .sub(let a, let b):        return "subq \(a.name), \(b.asm)"
        case .mov(let dest, let src):   return "movq \(dest.asm), \(src.asm)"
        case .push(let reg):            return "pushq \(reg.name)"
        case .pop(let reg):             return "popq \(reg.name)"
        case .ret:                      return "retq"
        }
    }
    var _asm: String {
        switch self {
        case .add(let a, let b):        return "addq \(b._asm), %\(a.name)"
        case .sub(let a, let b):        return "subq \(b._asm), %\(a.name)"
        case .mov(let dest, let src):   return "movq \(src._asm), \(dest._asm)"
        case .push(let reg):            return "pushq %\(reg.name)"
        case .pop(let reg):             return "popq %\(reg.name)"
        case .ret:                      return "retq"
        }
    }
}

enum MCInstAddressingMode {
    case reg(AIRRegister), imm(Int), mem(AIRRegister), offsetMem(AIRRegister, Int)
}

extension MCInst {
    
    var isMove: Bool {
        guard case .mov = self else { return false }
        return true
    }
    
    /// regs with live values into this inst
    var used: Set<AIRRegisterHash> {
        switch self {
        case .add(let l, let r):
            guard let r = r.reg else { return [l.hash] }
            return [l.hash, r.hash]
        case  .sub(let l, let r):
            guard let r = r.reg else { return [l.hash] }
            return [l.hash, r.hash]
        case .mov(let dest, let src):
            // a move uses the src, and uses the dest if its a stack addr
            switch (dest, src) {
            case (.mem, _), (.offsetMem, _):
                guard let src = src.reg, let mem = dest.reg else { return [] }
                return [mem.hash, src.hash]
            case (_, _):
                guard let src = src.reg else { return [] }
                return [src.hash]
            }
        case .push(let reg), .pop(let reg):
            return [reg.hash]
        case .ret: return []
        }
    }
    /// reg vals defined in this inst
    var def: Set<AIRRegisterHash> {
        // workaround for swift bug, this can be comma seperated
        switch self {
        case .add(let out, _):
            return [out.hash]
        case .sub(let out, _):
            return [out.hash]
        case .mov(let out, _):
            // a move only is a def of the out register
            guard case .reg(let reg) = out else { return [] }
            return [reg.hash]
        case .ret, .push, .pop: return []
        }
    }
    
    mutating func rewriteRegisters(_ graph: InterferenceGraph, _ rewrite: @noescape (AIRRegister) -> AIRRegister) {
        let hash = self
        switch self {
        case .add(let a, let b): self = .add(rewrite(a), b.rewriteRegisters(rewrite))
        case .sub(let a, let b): self = .add(rewrite(a), b.rewriteRegisters(rewrite))
        case .mov(let dest, let src): self = .mov(dest: dest.rewriteRegisters(rewrite), src: src.rewriteRegisters(rewrite))
        case .push(let reg): self = .push(rewrite(reg))
        case .pop(let reg): self = .push(rewrite(reg))
        case .ret: break
        }
        if hash != self {
            graph.replacedInsts[hash] = self
        }
    }
}

extension MCInstAddressingMode {
    var asm: String {
        switch self {
        case .reg(let reg): return reg.name
        case .imm(let val): return String(val)
        case .mem(let mem): return "[\(mem.name)]"
        case .offsetMem(let mem, let offs): return "[\(mem.name)\(offs>=0 ? "+" : "-")\(abs(offs))]"
        }
    }
    var _asm: String {
        switch self {
        case .reg(let reg): return "%\(reg.name)"
        case .imm(let val): return "$\(val)"
        case .mem(let mem): return "(%\(mem.name))"
        case .offsetMem(let mem, let offs): return "\(offs>=0 ? "+" : "-")\(abs(offs))(%\(mem.name))"
        }
    }
    
    var reg: AIRRegister? {
        switch self {
        case .reg(let reg): return reg
        case .mem(let reg): return reg
        case .offsetMem(let reg, _): return reg
        case .imm: return nil
        }
    }
    func rewriteRegisters(_ rewrite: @noescape (AIRRegister) -> AIRRegister) -> MCInstAddressingMode {
        switch self {
        case .reg(let reg): return .reg(rewrite(reg))
        case .mem(let reg): return .mem(rewrite(reg))
        case .offsetMem(let reg, let offs): return .offsetMem(rewrite(reg), offs)
        case .imm(let val): return .imm(val)
        }
    }
}

extension MCInst : CustomStringConvertible, Hashable {
    var description: String { return asm }
    var hashValue: Int { return asm.hashValue }
    static func == (l: MCInst, r: MCInst) -> Bool { return l.hashValue == r.hashValue }
}

final class MCFunction {
    var label: String
    var insts: [MCInst]
    var precoloured: [AIRRegisterHash: TargetRegister] = [:]
    var target: TargetMachine.Type
    
    var stackSize = 0
    
    init(name: String, dag: SelectionDAG) throws {
        self.insts = try dag.runInstructionSelection()
        self.precoloured = dag.precoloured
        self.target = dag.target
        self.label = name
    }
}

enum MCSection {
    case data, text(functions: [MCFunction])
}

struct MCModule {
    let sections: [MCSection]
}

extension MCFunction : CustomStringConvertible {
    var description: String {
        return "_\(label):\n" + insts.map { "  \($0.description)" }.joined(separator: "\n")
    }
    var _asm: String {
        return "_\(label):\n" + insts.map { "  \($0._asm)" }.joined(separator: "\n")
    }
}

extension MCModule {
    
    /// The ASM the target wants -- doesn't use the Intel syntax, but
    /// the one clang likes as input
    var asm: String {
        return "\t.section\t__TEXT,__text,regular,pure_instructions\n" +
            sections.map { $0.asm }.joined(separator: "\n\n")
    }
}

extension MCSection {
    
    var asm: String {
        switch self {
        case .data:
            return "\t.section\t__TEXT,__const\n"
        case .text(let functions):
            return "\t.section\t__TEXT,__text,regular,pure_instructions\n" +
                functions.map { ".globl\t_\($0.label)\n" + $0._asm }.joined(separator: "\n")
        }
    }
}


