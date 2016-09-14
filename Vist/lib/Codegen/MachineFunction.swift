//
//  MachineFunction.swift
//  Vist
//
//  Created by Josef Willsher on 04/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


enum MCInst {
    case add(AIRRegister, MCInstAddressingMode)
    case mov(dest: MCInstAddressingMode, src: MCInstAddressingMode)
    case ret
    
    var asm: String {
        switch self {
        case .add(let a, let b):        return "addq \(a.name), \(b.asm)"
        case .mov(let dest, let src):   return "movq \(dest.asm), \(src.asm)"
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
        case .ret: return []
        }
    }
    /// reg vals defined in this inst
    var def: Set<AIRRegisterHash> {
        // workaround for swift bug, this can be comma seperated
        switch self {
        case .add(let out, _):
            return [out.hash]
        case .mov(let out, _):
            // a move only is a def of the out register
            guard case .reg(let reg) = out else { return [] }
            return [reg.hash]
        case .ret: return []
        }
    }
    
    mutating func rewriteRegisters(_ graph: InterferenceGraph, _ rewrite: @noescape (AIRRegister) -> AIRRegister) {
        let hash = self
        switch self {
        case .add(let a, let b): self = .add(rewrite(a), b.rewriteRegisters(rewrite))
        case .mov(let dest, let src): self = .mov(dest: dest.rewriteRegisters(rewrite), src: src.rewriteRegisters(rewrite))
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


protocol TargetMachine {
    static var gpr: [X86Register] { get }
    
    static var returnRegister: X86Register { get }
    static func paramRegister(at: Int) -> X86Register
    
    static var stackPtr: X86Register { get }
    static var basePtr: X86Register { get }
    static var wordSize: Int { get }
}
extension TargetMachine {
    static var availiableRegisters: Int { return gpr.count }
}
struct X8664Machine : TargetMachine {
    static var returnRegister: X86Register { return .rax }
    static func paramRegister(at i: Int) -> X86Register { return [.rdi, .rsi, .rdx, .rcx][i] }
    
    static var stackPtr: X86Register { return .rsp }
    static var basePtr: X86Register { return .rbp }
    
    static var wordSize: Int { return 64 }
    
    /// General purpose registers
//    static let gpr: [X86Register] = [.rax, .rbx, .rcx, .rdx, .rdi, .rbp, .rsp,
//                                     .r8, .r9, .r10, .r11, .r12, .r13, .r14, .r15]
// 4 regs availiable for testing
    static let gpr: [X86Register] = [.rdi, .rsi, .r8]
}




final class MCFunction {
    var insts: [MCInst]
    var precoloured: [AIRRegisterHash: TargetRegister] = [:]
    
    var stackSize = 0
    
    init(dag: SelectionDAG) throws {
        self.insts = try dag.runInstructionSelection()
        self.precoloured = dag.precoloured
    }
}
struct GPR : Reg {}

protocol TargetRegister : AIRRegister {
}

enum X86Register : String, TargetRegister {
    // 64bit general purpose registers
    case rax, rbx, rcx, rdx, rdi, rsi, rbp, rsp
    case r8, r9, r10, r11, r12, r13, r14, r15
    // 32bit general purpose registers
    case eax, ebx, ecx, edx, edi, esi, ebp, esp
    case r8d, r9d, r10d, r11d, r12d, r13d, r14d, r15d
    // flag register
    case eflags, rflags
    // MMX
    case mm0, mm1, mm2, mm3, mm4, mm5, mm6, mm7
    // XMM
    case xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7
    case xmm8, xmm9, xmm10, xmm11, xmm12, xmm13, xmm14, xmm15
    
    var air: String { return "%\(rawValue)" }
    var name: String { return rawValue }
    var hash: AIRRegisterHash { return AIRRegisterHash(hashValue: rawValue.hashValue) }
    
}


extension MCFunction : CustomStringConvertible {
    var description: String {
        return insts.map { $0.description }.joined(separator: "\n")
    }
}

