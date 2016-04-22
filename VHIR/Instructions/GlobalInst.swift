//
//  GlobalInst.swift
//  Vist
//
//  Created by Josef Willsher on 20/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


final class GlobalValue : LValue {
    
    init(name: String, type: Type) {
        self.globalType = type
        self.globalName = name
    }
    
    var globalType: Type, globalName: String
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
    
    weak var parentBlock: BasicBlock? = nil
    
    var uses: [Operand] = []

    /// A global value's lifetime, the global value cannot exist out 
    /// of this range. Useful for the optimiser to lower global 
    /// vars when inlining functions to stack storage
    /// - note: lifetime valid `]start end]`
    final class Lifetime {
        let start: Inst, end: Inst
        private var owningFunction: Function
        init(start: Inst, end: Inst, owningFunction: Function) {
            self.start = start
            self.end = end
            self.owningFunction = owningFunction
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
    var vhir: String { return "\(name): \(globalType)" }
}
extension GlobalValue : Hashable, Equatable {
    var hashValue: Int { return name.hashValue }
}
func == (lhs: GlobalValue, rhs: GlobalValue) -> Bool {
    return lhs.globalName == rhs.globalName
}



