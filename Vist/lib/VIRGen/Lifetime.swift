//
//  Lifetime.swift
//  Vist
//
//  Created by Josef Willsher on 23/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


extension TypeDecl {
    
    func emitImplicitDestructorDecl(module: Module) throws -> Function? {
        
        // if any of the members need deallocating
        guard let type = self.type, type.needsDestructor() else {
            return nil
        }
        
        let startInsert = module.builder.insertPoint
        defer { module.builder.insertPoint = startInsert }
        
        let fnType = FunctionType(params: [type.importedType(in: module).ptrType()],
                                  returns: BuiltinType.void,
                                  callingConvention: .runtime)
        let fnName = "destroy".mangle(type: fnType)
        let fn = try module.builder.buildFunctionPrototype(name: fnName, type: fnType)
        try fn.defineBody(params: [(name: "self", convention: .inout)])
        
        let selfAccessor = try fn.param(named: "self").accessor() as! IndirectAccessor
        
        try selfAccessor.emitDestruction(module: module)
        try module.builder.buildReturnVoid()
        
        return fn
    }
    
    func emitImplicitCopyConstructorDecl(module: Module) throws -> Function? {
        
        // if any of the members need deallocating
        guard let type = self.type, type.needsDestructor() else {
            return nil
        }
        
        let startInsert = module.builder.insertPoint
        defer { module.builder.insertPoint = startInsert }
        
        let fnType = FunctionType(params: [type.importedType(in: module).ptrType(), type.importedType(in: module).ptrType()],
                                  returns: BuiltinType.void,
                                  callingConvention: .runtime)
        let fnName = "deepCopy".mangle(type: fnType)
        let fn = try module.builder.buildFunctionPrototype(name: fnName, type: fnType)
        try fn.defineBody(params: [(name: "self", convention: .inout), (name: "out", convention: .out)])
        
        let selfAccessor = try fn.param(named: "self").accessor() as! IndirectAccessor
        let outAccessor = try fn.param(named: "out").accessor() as! IndirectAccessor
        
        try selfAccessor.emitCopyConstruction(into: outAccessor, module: module)
        try module.builder.buildReturnVoid()
        
        return fn
    }
}

private extension Type {
    func needsDestructor() -> Bool {
        return
            isConceptType() ||
            ((self as? NominalType)?.members.contains {
            $0.type is ConceptType ||
                $0.type.isHeapAllocated ||
                $0.type.needsDestructor()
            } ?? false)
    }
}

extension IndirectAccessor {
    
    /// Emit VIR which ends this val's lifetime
    func emitDestruction(module: Module) throws {
        switch storedType {
        case let type as NominalType:
            for member in type.members {
                
                let ptr = try module.builder.build(inst: StructElementPtrInst(object: lValueReference(),
                                                                              property: member.name,
                                                                              irName: member.name))
                switch member.type {
                case let type where type.isConceptType():
                    try module.builder.build(inst: DestroyAddrInst(addr: ptr))
                case let type where type.isHeapAllocated:
                    // release the box
                    try module.builder.build(inst: ReleaseInst(val: ptr, unowned: false))
                case let type where type.isStructType():
                    // destruct the struct elements
                    try ptr.accessor.emitDestruction(module: module)
                default:
                    break
                }
            }
        default:
            break
        }
    }
    
    /// Emit VIR which creates a deep copy of this val
    func emitCopyConstruction(into outAccessor: IndirectAccessor, module: Module) throws {
        
        switch storedType {
        case let type as NominalType where type.needsDestructor():
            
            for member in type.members {
                let ptr = try module.builder.build(inst: StructElementPtrInst(object: lValueReference(),
                                                                              property: member.name,
                                                                              irName: member.name))
                /// The ptr to the value we load from to store into the target
                let valuePtr: LValue
                let outPtr = try module.builder.build(inst: StructElementPtrInst(object: outAccessor.lValueReference(),
                                                                                 property: member.name,
                                                                                 irName: member.name))
                switch member.type {
                case let type where type.isConceptType():
                    // if it is a concept, copy the buffer in the runtime
                    valuePtr = try module.builder.build(inst: CopyAddrInst(addr: ptr))
                    
                case let type where type.isHeapAllocated:
                    // if we need to retaun it
                    try module.builder.build(inst: RetainInst(val: ptr))
                    valuePtr = ptr
                    
                case let type where type.isStructType():
                    // copy-construct the struct elements into the struct ptr
                    try ptr.accessor.emitCopyConstruction(into: outPtr.accessor, module: module)
                    continue
                    
                default:
                    valuePtr = ptr
                }
                
                let val = try module.builder.build(inst: LoadInst(address: valuePtr))
                try module.builder.build(inst: StoreInst(address: outPtr, value: val))
            }
        default:
            // if it isnt a nominal type, shallow copy the entire thing
            let val = try module.builder.build(inst: LoadInst(address: reference()))
            try module.builder.build(inst: StoreInst(address: outAccessor.reference(), value: val))
        }
    }
    
}


extension Function {
    
    func insertDeallocations() throws {
        
        
        /*
         
         */
        
    }
    
}






