//
//  MachineFunction.swift
//  Vist
//
//  Created by Josef Willsher on 04/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

enum MCInst {
    case add(AIRRegister, AIRRegister), addImm(dest: AIRRegister, val: Int)
    case mov(dest: AIRRegister, src: AIRRegister), movImm(dest: AIRRegister, val: Int)
    case ret
}

extension MCInst : CustomStringConvertible, Hashable {
    var description: String {
        switch self {
        case .add(let a, let b):        return "addq \(a.air), \(b.air)"
        case .addImm(let a, let b):     return "addq \(a.air), $\(b)"
        case .mov(let dest, let src):   return "movq \(dest.air), \(src.air)"
        case .movImm(let dest, let v):  return "movq \(dest.air), $\(v)"
        case .ret:                      return "retq"
        }
    }
    var hashValue: Int {
        return description.hashValue
    }
    static func == (l: MCInst, r: MCInst) -> Bool {
        return l.hashValue == r.hashValue
    }
    var isMove: Bool {
        switch self {
        case .mov, .movImm: return true
        default: return false
        }
    }
    
    mutating func updateRegisters(concreteRegisters: [AIRRegisterHash: TargetRegister]) {
        switch self {
        case .add(let a, let b):        self = .add(concreteRegisters[a.hash]!, concreteRegisters[b.hash]!)
        case .addImm(let a, let val):   self = .addImm(dest: concreteRegisters[a.hash]!, val: val)
        case .mov(let dest, let src):   self = .mov(dest: concreteRegisters[dest.hash]!, src: concreteRegisters[src.hash]!)
        case .movImm(let dest, let v):  self = .movImm(dest: concreteRegisters[dest.hash]!, val: v)
        default: break
        }
    }
    
    // used in live variable analysis
    
    /// regs with live values into this inst
    var used: Set<AIRRegisterHash> {
        switch self {
        case .add(let l, let r): return [l.hash, r.hash]
        case .addImm(let l, _): return [l.hash]
        case .mov(_, let src): return [src.hash]
        default: return []
        }
    }
    /// reg vals defined in this inst
    var def: Set<AIRRegisterHash> {
        // workaround for swift bug, this can be comma seperated
        switch self {
        case .add(let out, _): return [out.hash]
        case .mov(let out, _): return [out.hash]
        case .movImm(let out, _): return [out.hash]
        case .addImm(let out, _): return [out.hash]
        case .ret: return []
        }
    }
}


struct TargetMachine {
    let nativeIntSize: Int
    let register: TargetRegister.Type
    init(reg: TargetRegister.Type) {
        self.nativeIntSize = 64
        self.register = reg
    }
}

final class MCFunction {
    var insts: [MCInst]
    var precoloured: [AIRRegisterHash: TargetRegister] = [:]
    
    init(dag: SelectionDAG) throws {
        self.insts = try dag.runInstructionSelection()
        self.precoloured = dag.precoloured
    }
}
struct GPR : Reg {}

protocol TargetRegister : AIRRegister {
    static var gpr: [X86Register] { get }
    static var returnRegister: X86Register { get }
    static func paramRegister(at: Int) -> X86Register
}
extension TargetRegister {
    static var availiableRegisters: Int { return gpr.count }
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
    var hash: AIRRegisterHash { return AIRRegisterHash(hashValue: rawValue.hashValue) }
    
    /// General purpose registers
//    static let gpr: [X86Register] = [.rax, .rbx, .rcx, .rdx, .rdi, .rbp, .rsp,
//                                     .r8, .r9, .r10, .r11, .r12, .r13, .r14, .r15]
    // 4 regs availiable for testing
    static let gpr: [X86Register] = [.r8, .r9]
    
    static var returnRegister: X86Register { return .rax }
    static func paramRegister(at i: Int) -> X86Register { return [.rdi, .rsi, .rdx, .rcx][i] }
}

extension MCFunction : CustomStringConvertible {
    var description: String {
        return insts.map { $0.description }.joined(separator: "\n")
    }
}

