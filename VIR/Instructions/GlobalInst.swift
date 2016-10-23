//
//  GlobalInst.swift
//  Vist
//
//  Created by Josef Willsher on 20/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class GlobalValue : LValue {
    
    init(name: String, type: Type, module: Module) {
        self.globalType = type
        self.globalName = name
        self.module = module
    }
    
    var globalType: Type, globalName: String
    unowned var module: Module
    
    weak var parentBlock: BasicBlock? = nil
    var uses: [Operand] = []
    
    var lifetime: Lifetime? {
        willSet {
            // if setting to a value, tell the parent block to manage the lifetime
            if let lifetime = newValue {
                lifetime.owningFunction.insertGlobalLifetime(lifetime)
            }
                // otherwise we remove the old lifetime, if it was defined
            else if let oldLifetime = lifetime {
                oldLifetime.owningFunction.removeGlobalLifetime(oldLifetime)
            }
        }
    }

    /// A global value's lifetime, the global value cannot exist out 
    /// of this range. Useful for the optimiser to lower global 
    /// vars when inlining functions to stack storage
    /// - note: lifetime valid `]start end]` -- ie. lifetime range is
    ///         after start and end instructions
    final class Lifetime {
        let start: Operand, end: Operand
        let globalName: String
        fileprivate unowned let owningFunction: Function
        init(start: Inst, end: Inst, globalName: String, owningFunction: Function) {
            self.start = Operand(start)
            self.end = Operand(end)
            self.owningFunction = owningFunction
            self.globalName = globalName
        }
    }
    
}

extension GlobalValue {
    
    var memType: Type? { return globalType }
    var type: Type? { return BuiltinType.pointer(to: globalType) }
    
    var irName: String? {
        get { return globalName }
        set { }
    }
    var vir: String { return "\(name): \(globalType.prettyName)" }
    
    static func == (lhs: GlobalValue, rhs: GlobalValue) -> Bool {
        return lhs.globalName == rhs.globalName
    }
}
extension GlobalValue : Hashable, Equatable {
    var hashValue: Int { return name.hashValue }
}

