//
//  BuiltinInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class BuiltinInstCall: InstBase {
    override var type: Ty? { return returnType }
    let inst: BuiltinInst
    var instName: String { return inst.rawValue }
    var returnType: Ty
    
    private init?(inst: BuiltinInst, args: [Operand], irName: String?) {
        self.inst = inst
        guard let argTypes = args.optionalMap({ $0.type }), let retTy = inst.returnType(params: argTypes) else { return nil }
        self.returnType = retTy
        super.init(args: args, irName: irName)
    }
    
    static func trapInst() -> BuiltinInstCall { return BuiltinInstCall(inst: .trap, args: [], irName: nil)! }
    
    // utils for bin instructions
    var l: Operand { return args[0] }
    var r: Operand { return args[1] }
    
    override var instVHIR: String {
        let a = args.map{$0.valueName}
        let w = a.joinWithSeparator(", ")
        switch inst {
        case .condfail:
            return "cond_fail \(w)"
        default:
            return "\(name) = builtin \(instName) \(w) \(useComment)"
        }
    }
    
    override var hasSideEffects: Bool {
        switch inst {
        case .condfail: return true
        default: return false
        }
    }
    
}

enum BuiltinInst: String {
    case iadd = "i_add", isub = "i_sub", imul = "i_mul", idiv = "i_div", irem = "i_rem", ieq = "i_eq", ineq = "i_neq"
    case iaddoverflow = "i_add_overflow"
    case condfail = "cond_fail"
    case ilte = "i_cmp_lte", igte = "i_cmp_gte", ilt = "i_cmp_lt", igt = "i_cmp_gt"
    case ishl = "i_shl", ishr = "i_shr", iand = "i_and", ior = "i_or", ixor = "i_xor"
    case expect, trap
    
    case fadd = "f_add", fsub = "f_sub", fmul = "f_mul", fdiv = "f_div", frem = "f_rem", feq = "f_eq", fneq = "f_neq"
    case flte = "f_cmp_lte", fgte = "f_cmp_gte", flt = "f_cmp_lt", fgt = "f_cmp_gt"
    
    var expectedNumOperands: Int {
        switch  self {
        case .iadd, .isub, .imul, .idiv, .iaddoverflow, .irem, .ilte, .igte, .ilt,
             .igt, .expect, .ieq, .ineq, .ishr, .ishl, .iand, .ior, .ixor, .fgt,
             .fgte, .flt, .flte, .fadd, .fsub, .fmul, .fdiv, .frem, .feq, .fneq: return 2
        case .condfail: return 1
        case .trap: return 0
        }
    }
    func returnType(params params: [Ty]) -> Ty? {
        switch self {
        case .iadd, .isub, .imul:
            return TupleType(members: [params.first!, Builtin.boolType]) // overflowing arithmetic
            
        case .idiv, .iaddoverflow, .irem, .ishl, .ishr, .iand, .ior, .ixor,
             .fadd, .fsub, .fmul, .fdiv, .frem, .feq, .fneq:
            return params.first // normal arithmetic
            
        case .ilte, .igte, .ilt, .igt, .flte, .fgte, .flt, .fgt, .expect, .ieq, .ineq:
            return Builtin.boolType // bool ops
            
        case .condfail, trap:
            return Builtin.voidType // void return
        }
    }
}


extension Builder {
    
    // change name back when not crashing
    // file bug
    func buildBuiltinInstructionCall(i: BuiltinInst, args: Operand..., irName: String? = nil) throws -> BuiltinInstCall {
        return try buildBuiltinInstruction(i, args: args, irName: irName)
    }
    
    func buildBuiltinInstruction(i: BuiltinInst, args: [Operand], irName: String? = nil) throws -> BuiltinInstCall {
        guard args.count == i.expectedNumOperands, let binInst = BuiltinInstCall(inst: i, args: args, irName: irName) else { throw VHIRError.builtinIncorrectOperands(inst: i, recieved: args.count) }
        return try _add(binInst)
    }
}