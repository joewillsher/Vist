//
//  Destructor.swift
//  Vist
//
//  Created by Josef Willsher on 23/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension TypeDecl {
    
    func emitImplicitDestructorDecl(module: Module, gen: VIRGenFunction) throws -> Function? {
        
        // if any of the members need deallocating
        guard let type = self.type, !type.isTrivial() else {
            return nil
        }
        
        let startInsert = gen.builder.insertPoint
        defer { gen.builder.insertPoint = startInsert }
        
        let fnType = FunctionType(params: [type.importedType(in: module).ptrType()],
                                  returns: BuiltinType.void,
                                  callingConvention: .runtime)
        let fnName = "destroy".mangle(type: fnType)
        let fn = try gen.builder.buildFunctionPrototype(name: fnName, type: fnType)
        try fn.defineBody(params: [(name: "self", convention: .inout)])
        
        let managedSelf = try fn.param(named: "self").managed(gen: gen)
        
        try managedSelf.emitDestruction(gen: gen)
        try gen.builder.buildReturnVoid()
        
        return fn
    }
    
    func emitImplicitCopyConstructorDecl(module: Module, gen: VIRGenFunction) throws -> Function? {
        
        // if any of the members need deallocating
        guard let type = self.type, !type.isTrivial() else {
            return nil
        }
        
        let startInsert = gen.builder.insertPoint
        defer { gen.builder.insertPoint = startInsert }
        
        let fnType = FunctionType(params: [type.importedType(in: module).ptrType(), type.importedType(in: module).ptrType()],
                                  returns: BuiltinType.void,
                                  callingConvention: .runtime)
        let fnName = "deepCopy".mangle(type: fnType)
        let fn = try gen.builder.buildFunctionPrototype(name: fnName, type: fnType)
        try fn.defineBody(params: [(name: "self", convention: .inout), (name: "out", convention: .inout)])
        
        let managedSelf = try fn.param(named: "self").managed(gen: gen)
        let managedOut = try fn.param(named: "out").managed(gen: gen)
        
        try managedSelf.emitCopyConstruction(into: managedOut, gen: gen)
        try gen.builder.buildReturnVoid()
        
        return fn
    }
}

extension ConceptType {
    func isTrivial() -> Bool {
        return false
    }
}
extension TypeAlias {
    func isTrivial() -> Bool {
        return targetType.isTrivial()
    }
}
extension NominalType {
    func isTrivial() -> Bool {
        if isHeapAllocated {
            return false
        }
        for member in members where !member.type.isTrivial() {
            return false
        }
        return true
    }
}
extension Type {
    func isTrivial() -> Bool {
        return true
    }
}


private extension ManagedValue {
    
    /// Emit VIR which ends this val's lifetime
    func emitDestruction(gen: VIRGenFunction) throws {
        switch type {
        case let type as NominalType:
            for member in type.members {
                
                let ptr = try gen.builder.buildUnmanagedLValue(StructElementPtrInst(object: lValue,
                                                                                    property: member.name,
                                                                                    irName: member.name), gen: gen)
                switch member.type {
                case let type where type.isConceptType():
                    try gen.builder.build(DestroyAddrInst(addr: ptr.managedValue))
                case let type where type.isHeapAllocated:
                    // release the box
                    try gen.builder.build(ReleaseInst(val: ptr.managedValue, unowned: false))
                case let type where type.isStructType():
                    // destruct the struct elements
                    try ptr.emitDestruction(gen: gen)
                default:
                    break
                }
            }
        case let type as TupleType:
            for member in type.members {
                
            }
            // TODO: Important, emit destruction memberwise for tuples
            break
        default:
            break
        }
    }
    
    /// Emit VIR which creates a deep copy of this val
    func emitCopyConstruction(into outAccessor: ManagedValue, gen: VIRGenFunction) throws {
        
        switch type {
        case let type as NominalType where type.isTrivial():
            
            for member in type.members {
                let ptr = try gen.builder.buildUnmanagedLValue(StructElementPtrInst(object: lValue,
                                                                                    property: member.name), gen: gen)
                let outPtr = try gen.builder.buildUnmanagedLValue(StructElementPtrInst(object: outAccessor.lValue,
                                                                                       property: member.name), gen: gen)
                switch member.type {
                case let type where type.isHeapAllocated:
                    // if we need to retaun it
                    try gen.builder.build(RetainInst(val: ptr.managedValue))
                    try gen.builder.build(CopyAddrInst(addr: ptr.managedValue, out: outPtr.managedValue))
                    
                case let type where type.isStructType() && type.isTrivial():
                    // copy-construct the struct elements into the struct ptr
                    try ptr.emitCopyConstruction(into: outPtr, gen: gen)
                    
                default:
                    // concepts and trivial structs
                    try gen.builder.build(CopyAddrInst(addr: ptr.managedValue, out: outPtr.managedValue))
                }
            }
        default:
            // if it isnt a nominal type, shallow copy the entire thing
            _ = try gen.builder.build(CopyAddrInst(addr: lValue, out: outAccessor.lValue))
        }
    }
    
}
