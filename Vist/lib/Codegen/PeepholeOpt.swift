//
//  PeepholeOpt.swift
//  Vist
//
//  Created by Josef Willsher on 25/09/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol PeepholePass {
    /// The size of the moving window
    var windowSize: Int { get }
    /// Run the optimisation
    func run<Insts : Collection>(on: Insts) throws -> [MCInst]?
        where Insts.Iterator.Element == MCInst, Insts.IndexDistance == Int
}

struct PeepholePassManager {
    let function: MCFunction
    
    func runPasses() throws {
        
        try run(pass: CallStackAlignmentPass(function: function))
        try run(pass: DeadMoveRemovalPass())
        
    }
    
    private func run<Pass : PeepholePass>(pass: Pass) throws {
        guard function.insts.count >= pass.windowSize else { return }
        
        var i = 0
        
        while i < function.insts.count-pass.windowSize {
            let window = i ..< i+pass.windowSize
            guard let replace = try pass.run(on: function.insts[window]) else {
                i += 1
                continue
            }
            function.insts.replaceSubrange(window, with: replace)
            i = window.endIndex
        }
    }
}



struct CallStackAlignmentPass : PeepholePass {
    let function: MCFunction
    
    var windowSize: Int { return 1 }
    
    func run<Insts : Collection>(on insts: Insts) throws -> [MCInst]?
        where Insts.Iterator.Element == MCInst, Insts.IndexDistance == Int
    {
        assert(insts.count == windowSize)
        guard let call = insts.first, case .call = call else { return nil }
        
        // calculate stack offset
        var offset = 8
        for index in 0..<function.insts.index(of: call)! {
            switch function.insts[index] {
            case .push(let reg as TargetRegister): offset += reg.size
            case .pop(let reg as TargetRegister): offset -= reg.size
            case .sub(X86Register.rsp, .imm(let val)): offset += val
            case .add(X86Register.rsp, .imm(let val)): offset -= val
            default: break
            }
        }
        guard offset % 16 != 0 else { return [call] }
        
        return [.sub(X86Register.rsp, .imm(8)), call, .add(X86Register.rsp, .imm(8))]
    }
}

struct DeadMoveRemovalPass : PeepholePass {
    var windowSize: Int { return 1 }
    
    func run<Insts : Collection>(on insts: Insts) throws -> [MCInst]?
        where Insts.Iterator.Element == MCInst, Insts.IndexDistance == Int
    {
        assert(insts.count == windowSize)
        guard let mov = insts.first, case .mov(let src, let dest) = mov else { return nil }
        
        if src == dest {
            return []
        }
        return [mov]
    }
}

