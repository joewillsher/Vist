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
        guard case let type as NominalType = self.type?.importedType(in: module), !type.isTrivial() else {
            return nil
        }
        
        let destroyVGF = VIRGenFunction(parent: gen, scope: VIRGenScope(module: module))
        
        let startInsert = destroyVGF.builder.insertPoint
        defer { destroyVGF.builder.insertPoint = startInsert }
        
        let fnType = FunctionType(params: [type.importedType(in: module).ptrType()],
                                  returns: BuiltinType.void,
                                  callingConvention: .runtime)
        let fnName = "destroy".mangle(type: fnType)
        let fn = try destroyVGF.builder.buildFunctionPrototype(name: fnName, type: fnType)
        try fn.defineBody(params: [(name: "self", convention: .inout)])
        
        let managedSelf = try fn.param(named: "self").managed(gen: destroyVGF)
        
        // create a call to the custom deinitialiser function, if there is one
        if let deinitFn = module.type(named: type.name)?.deinitialiser {
            try destroyVGF.builder.buildFunctionCall(function: deinitFn, args: [Operand(managedSelf.value)])
        }
        
        // destroy the value
        try managedSelf.emitDestruction(gen: destroyVGF)
        try destroyVGF.builder.buildReturnVoid()
        
        return fn
    }
    
    func emitImplicitCopyConstructorDecl(module: Module, gen: VIRGenFunction) throws -> Function? {
        
        // if any of the members need deallocating
        guard let type = self.type?.importedType(in: module), type.requiresCopyConstruction() else {
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

extension TypeAlias {
    func isTrivial() -> Bool { return targetType.isTrivial() }
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
extension ConceptType {
    func isTrivial() -> Bool { return false }
}
extension ClassType {
    func isTrivial() -> Bool {
        return false
    }
}
extension Type {
    // FIXME: BuiltinType.isTrivial uses this method, not the specific one
    func isTrivial() -> Bool {
        if case let b as BuiltinType = self, case .pointer(let to) = b, !to.isTrivial() { return false }
        return true
    }
    func requiresCopyConstruction() -> Bool { return !isTrivial() && !isClassType() }
}
extension BuiltinType {
    func isTrivial() -> Bool {
        if case .pointer(let ref) = self, !ref.isTrivial() { return false }
        return true
    }
}


private extension ManagedValue {
    
    /// Emit VIR which ends this val's lifetime -- it is responsible for destroying the members of the instance.
    /// This destruction should be called by the runtime in a dealloc function 
    func emitDestruction(gen: VIRGenFunction) throws {
        switch type.getBasePointeeType() {
        case let type as NominalType:
            let lval = try type.isClassType() ?
                gen.builder.buildUnmanagedLValue(ClassProjectInstanceInst(object: lValue), gen: gen).lValue :
                lValue
            for member in type.members {
                
                let ptr = try gen.builder.buildUnmanagedLValue(StructElementPtrInst(object: lval, property: member.name,
                                                                                    irName: member.name), gen: gen)
                switch member.type.getBasePointeeType() {
                case let type where type.isConceptType():
                    try gen.builder.build(DestroyAddrInst(addr: ptr.managedValue))
                case let type where type.isClassType():
                    // this must be of type `**Member`, as the member must have `*Member` type
                    assert(member.type == BuiltinType.pointer(to: type))
                    let member = try gen.builder.buildUnmanagedLValue(LoadInst(address: ptr.managedValue), gen: gen)
                    try gen.builder.build(ReleaseInst(object: member.lValue))
                case let type where type.isStructType():
                    // destruct the struct elements
                    try ptr.emitDestruction(gen: gen)
                default:
                    break
                }
            }
        case let type as TupleType:
//            for member in type.members {
//                
//            }
            // TODO: Important, emit destruction memberwise for tuples
            break
        default:
            break
        }
    }
    
    /// Emit VIR which creates a deep copy of this val
    func emitCopyConstruction(into outAccessor: ManagedValue, gen: VIRGenFunction) throws {
        assert(!type.isClassType())
        
        switch type {
        case let type as NominalType where !type.isTrivial():
            for member in type.members {
                let ptr = try gen.builder.buildUnmanagedLValue(StructElementPtrInst(object: lValue,
                                                                                    property: member.name), gen: gen)
                let outPtr = try gen.builder.buildUnmanagedLValue(StructElementPtrInst(object: outAccessor.lValue,
                                                                                       property: member.name), gen: gen)
                switch member.type.getBasePointeeType() {
                case let type where type.isClassType():
                    // if we need to retain it
                    let stored = try gen.builder.buildUnmanagedLValue(LoadInst(address: ptr.managedValue), gen: gen)
                    try gen.builder.build(RetainInst(object: stored.lValue))
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
