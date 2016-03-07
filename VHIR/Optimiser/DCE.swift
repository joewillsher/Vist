//
//  DCE.swift
//  Vist
//
//  Created by Josef Willsher on 07/03/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


enum OptLevel {
    case off, high
}



protocol FunctionPass {
    func runOn(function: Function) throws
    init(optLevel: OptLevel)
}
protocol ModulePass {
    func runOn(module: Module) throws
    init(optLevel: OptLevel)
}

extension ModulePass {
    static func create(optLevel: OptLevel, module: Module) throws {
        return try Self(optLevel: optLevel).runOn(module)
    }
}
extension FunctionPass {
    static func create(optLevel: OptLevel, function: Function) throws {
        return try Self(optLevel: optLevel).runOn(function)
    }
}


extension Module {
    
    func runPasses(optLevel: OptLevel) throws {
        
        for function in functions {
//            try DCEPass.create(optLevel, function: function)
        }
        
    }
}

final class DCEPass: FunctionPass {
    
    init(optLevel: OptLevel) {}
    
    func runOn(function: Function) throws {
        
        for bb in function.blocks ?? [] {
            for inst in bb.instructions where inst.uses.isEmpty {
                try inst.removeFromParent()
            }
        }
        
    }
    
}

final class DeadFunctionPass: ModulePass {
    
    init(optLevel: OptLevel) {}
    
    func runOn(module: Module) throws {
        for _ in module.functions {
            // remove function if no users
        }
    }
}



