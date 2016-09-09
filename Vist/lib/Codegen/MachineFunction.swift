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

struct MCFunction {
    let insts: [MCInst]
}
struct GPR : Reg {
}

