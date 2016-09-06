//
//  MachineFunction.swift
//  Vist
//
//  Created by Josef Willsher on 04/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct MCFunction {
    
}

//typealias MachineInstBundle = [MCInst]

enum X86Op {
    case mov
}

private protocol OpOrder { }
private protocol MCInst {
    associatedtype Ins : OpOrder
    associatedtype Outs : OpOrder
}

struct GPR : Reg {
}

private struct Unary<R: Reg> : OpOrder {
}
private struct Binary<R1: Reg, R2: Reg> : OpOrder {
}
private struct Identity : OpOrder {}

private struct IADD64 : MCInst {
    typealias Ins = Binary<GPR, GPR>
    typealias Outs = Identity
}
private struct IADD64RR : MCInst {
    typealias Ins = Binary<GPR, GPR>
    typealias Outs = Unary<GPR>
}

private struct RET : MCInst {
    typealias Ins = Identity
    typealias Outs = Identity
}



