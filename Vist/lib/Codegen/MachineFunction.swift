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

extension MCInst : CustomStringConvertible {
    var description: String {
        switch self {
        case .add(let a, let b):        return "addq \(a.air), \(b.air)"
        case .addImm(let a, let b):     return "addq \(a.air), $\(b)"
        case .mov(let dest, let src):   return "movq \(dest.air), \(src.air)"
        case .movImm(let dest, let v):  return "movq \(dest.air), $\(v)"
        case .ret:                      return "retq"
        }
    }
}

struct MCFunction {
    
}
struct GPR : Reg {
}

