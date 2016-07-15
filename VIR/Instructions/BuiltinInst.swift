//
//  BuiltinInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 A call to a builtin VIR function
 
 `%a = builtin i_add %1:%Builtin.Int %2:$Builtin.Int`
 */
final class BuiltinInstCall : InstBase {
    override var type: Type? { return returnType }
    let inst: BuiltinInst
    var instName: String { return inst.rawValue }
    var returnType: Type
    
    convenience init(inst: BuiltinInst, args: [Value], irName: String? = nil) throws {
        
        guard args.count == inst.expectedNumOperands else {
            throw VIRError.builtinIncorrectOperands(inst: inst, recieved: args.count)
        }
        guard let retTy = try inst.returnType(params: args.map(getType(of:))) else {
            throw VIRError.noType(#file)
        }
        
        self.init(inst: inst, retType: retTy, operands: args.map(Operand.init), irName: irName)
    }
    
    private init(inst: BuiltinInst, retType: Type, operands: [Operand], irName: String?) {
        self.inst = inst
        self.returnType = retType
        super.init(args: operands, irName: irName)
    }
    
    static func trapInst() -> BuiltinInstCall { return try! BuiltinInstCall(inst: .trap, args: [], irName: nil) }
    
    // utils for bin instructions
    lazy var lhs: LLVMValue! = { return self.args[0].loweredValue }()
    lazy var rhs: LLVMValue! = { return self.args[1].loweredValue }()
    
    override var instVIR: String {
        let a = args.map{$0.valueName}
        let w = a.joined(separator: ", ")
        switch inst {
        case .condfail:
            return "cond_fail \(w)"
        default:
            return "\(name) = builtin \(instName) \(w)\(useComment)"
        }
    }
    
    override var hasSideEffects: Bool {
        switch inst {
        case .condfail, .memcpy, .trap, .opaquestore, .heapfree: return true
        default: return false
        }
    }
    override var isTerminator: Bool {
        switch inst {
        case .trap: return true
        default: return false
        }
    }
    
    override func copyInst() -> BuiltinInstCall {
        return BuiltinInstCall(inst: inst, retType: returnType, operands: args.map { $0.formCopy() }, irName: irName)
    }
}

/// A builtin VIR function. Each can be called in Vist code (stdlib only)
/// by doing Builtin.intrinsic
enum BuiltinInst : String {
    case iadd = "i_add", isub = "i_sub", imul = "i_mul", idiv = "i_div", irem = "i_rem", ieq = "i_eq", ineq = "i_neq", beq = "b_eq"
    case iaddoverflow = "i_add_overflow"
    case condfail = "cond_fail"
    case ilte = "i_cmp_lte", igte = "i_cmp_gte", ilt = "i_cmp_lt", igt = "i_cmp_gt"
    case ishl = "i_shl", ishr = "i_shr", iand = "i_and", ior = "i_or", ixor = "i_xor"
    case and = "b_and", or = "b_or"
    
    case expect, trap
    case allocstack = "stack_alloc", allocheap = "heap_alloc", heapfree = "heap_free", memcpy = "mem_copy", opaquestore = "opaque_store"
    case advancepointer = "advance_pointer", opaqueload = "opaque_load"
    
    case fadd = "f_add", fsub = "f_sub", fmul = "f_mul", fdiv = "f_div", frem = "f_rem", feq = "f_eq", fneq = "f_neq"
    case flte = "f_cmp_lte", fgte = "f_cmp_gte", flt = "f_cmp_lt", fgt = "f_cmp_gt"
    
    case trunc8 = "trunc_int_8", trunc16 = "trunc_int_16", trunc32 = "trunc_int_32"
    
    var expectedNumOperands: Int {
        switch  self {
        case .memcpy: return 3
        case .iadd, .isub, .imul, .idiv, .iaddoverflow, .irem, .ilte, .igte, .ilt, .igt,
             .expect, .ieq, .ineq, .ishr, .ishl, .iand, .ior, .ixor, .fgt, .and, .or,
             .fgte, .flt, .flte, .fadd, .fsub, .fmul, .fdiv, .frem, .feq, .fneq, .beq,
             .opaquestore, .advancepointer:
            return 2
        case .condfail, .allocstack, .allocheap, .heapfree, .opaqueload, .trunc8, .trunc16, .trunc32:
            return 1
        case .trap:
            return 0
        }
    }
    func returnType(params: [Type]) -> Type? {
        switch self {
        case .iadd, .isub, .imul:
            return TupleType(members: [params.first!, Builtin.boolType]) // overflowing arithmetic
            
        case .idiv, .iaddoverflow, .irem, .ishl, .ishr, .iand, .ior,
             .ixor, .fadd, .fsub, .fmul, .fdiv, .frem, .feq, .fneq:
            return params.first // normal arithmetic
            
        case .ilte, .igte, .ilt, .igt, .flte, .fgte, .flt,
             .fgt, .expect, .ieq, .ineq, .and, .or, .beq:
            return Builtin.boolType // bool ops
           
        case .allocstack, .allocheap, .advancepointer:
            return Builtin.opaquePointerType
            
        case .opaqueload, .trunc8:
            return BuiltinType.int(size: 8)
        case .trunc16:
            return BuiltinType.int(size: 16)
        case .trunc32:
            return BuiltinType.int(size: 32)
            
        case .condfail, .trap, .memcpy, .heapfree, .opaquestore:
            return Builtin.voidType // void return
        }
    }
}

