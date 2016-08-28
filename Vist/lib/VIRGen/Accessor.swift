//
//  Accessor.swift
//  Vist
//
//  Created by Josef Willsher on 27/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// A type which constructs access to a non trivially accessed value
protocol Accessor {
    
//    func getManaged() -> ManagedValue
    
}


/// Provides access to a global value with backing memory
final class GlobalRefAccessor : Accessor {
    var mem: LValue
    unowned var module: Module
    init(memory: LValue, module: Module) {
        self.mem = memory
        self.module = module
    }
}

/// Provides access to a global value with backing memory which
/// is a pointer to the object. Global object has type storedType**
/// and loads are
final class GlobalIndirectRefAccessor : Accessor {
    var mem: LValue
    unowned var module: Module
    
    init(memory: LValue, module: Module) {
        self.mem = memory
        self.module = module
    }
    
    private lazy var memsubsc: LValue = { [unowned self] in
        let mem = try! self.module.builder.build(LoadInst(address: self.mem))
        return try! OpaqueLValue(rvalue: mem)
        }()
    
    // the object reference is stored in self.mem, load it from there
    func reference() throws -> LValue {
        return memsubsc
    }
    
    func aggregateReference() -> LValue {
        return memsubsc
    }
}


/// A Ref accessor whose accessor is evaluated on demand. Useful for values
/// which might not be used
final class LazyRefAccessor : Accessor {
    private var build: () throws -> LValue
    private lazy var val: LValue? = try? self.build()
    
    var mem: LValue {
        guard let v = val else { fatalError() }
        return v
    }
    
    init(fn: () throws -> LValue) { build = fn }
}

