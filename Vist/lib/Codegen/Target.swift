//
//  Target.swift
//  Vist
//
//  Created by Josef Willsher on 21/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol TargetMachine {
    static var generalPurposeRegisters: [X86Register] { get }
    
    static var reservedRegisters: [X86Register] { get }
    static var callerSaveRegisters: [X86Register] { get }
    static var calleeSaveRegisters: [X86Register] { get }
    
    static var returnRegister: X86Register { get }
    static func paramRegister(at: Int) -> X86Register
    
    static var stackPtr: X86Register { get }
    static var basePtr: X86Register { get }
    static var wordSize: Int { get }
}
extension TargetMachine {
    static var availiableRegisters: Int { return generalPurposeRegisters.count }
}
struct X8664Machine : TargetMachine {
    static var returnRegister: X86Register { return .rax }
    static func paramRegister(at i: Int) -> X86Register { return [.rdi, .rsi, .rdx, .rcx][i] }
    
    static var stackPtr: X86Register { return .rsp }
    static var basePtr: X86Register { return .rbp }
    
    static var wordSize: Int { return 64 }
    
    /// General purpose registers
    static let generalPurposeRegisters: [X86Register] = [.rax, .rcx, .rdx, .rsi, .rdi, .r8, .r9, .r10, .r11,
                                                        .rbx, .r12, .r13, .r14, .r15]
//     // 4 regs availiable for testing
//    static let generalPurposeRegisters: [X86Register] = [.rdi, .rsi, .rax /*, .r8*/ ]
    static let reservedRegisters: [X86Register] = [.rsp, .rbp]
    static let callerSaveRegisters: [X86Register] = [.rax, .rcx, .rdx, .rsi, .rdi, .r8, .r9, .r10, .r11]
    static let calleeSaveRegisters: [X86Register] = [.rbx, .r12, .r13, .r14, .r15]
    
    // return: rax
    // parameters: rdi, rsi, rdx, rcx, r8d, r9d
    // caller save: rax, rcx, rdx, rsi, rdi, r8-r11
    // callee save: rbx, rbp, rsp, r12-r15
}


protocol TargetRegister : AIRRegister {
    var size: Int { get }
}
extension TargetRegister {
    var size: Int { return 8 }
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



