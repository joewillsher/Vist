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
        guard let type = self.type, type.isTrivial() else {
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
        guard let type = self.type, type.isTrivial() else {
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

extension Type {
    func isTrivial() -> Bool {
        return
            isConceptType() ||
                ((self as? NominalType)?.members.contains {
                    $0.type is ConceptType ||
                        $0.type.isHeapAllocated ||
                        $0.type.isTrivial()
                    } ?? false)
    }
}

extension IndirectAccessor {
    
    /// Emit VIR which ends this val's lifetime
    func emitDestruction(module: Module) throws {
        switch storedType {
        case let type as NominalType:
            for member in type.members {
                
                let ptr = try module.builder.build(StructElementPtrInst(object: lValueReference(),
                                                                        property: member.name,
                                                                        irName: member.name))
                switch member.type {
                case let type where type.isConceptType():
                    try module.builder.build(DestroyAddrInst(addr: ptr))
                case let type where type.isHeapAllocated:
                    // release the box
                    try module.builder.build(ReleaseInst(val: ptr, unowned: false))
                case let type where type.isStructType():
                    // destruct the struct elements
                    try ptr.accessor.emitDestruction(module: module)
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
    func emitCopyConstruction(into outAccessor: IndirectAccessor, module: Module) throws {
        
        
        switch storedType {
        case let type as NominalType where type.isTrivial():
            
            for member in type.members {
                let ptr = try module.builder.build(StructElementPtrInst(object: lValueReference(),
                                                                        property: member.name))
                let outPtr = try module.builder.build(StructElementPtrInst(object: outAccessor.lValueReference(),
                                                                           property: member.name))
                switch member.type {
                case let type where type.isHeapAllocated:
                    // if we need to retaun it
                    try module.builder.build(RetainInst(val: ptr))
                    try module.builder.build(CopyAddrInst(addr: ptr, out: outPtr))
                    
                case let type where type.isStructType() && type.isTrivial():
                    // copy-construct the struct elements into the struct ptr
                    try ptr.accessor.emitCopyConstruction(into: outPtr.accessor, module: module)
                    
                default:
                    // concepts and trivial structs
                    try module.builder.build(CopyAddrInst(addr: ptr, out: outPtr))
                }
                
            }
        default:
            // if it isnt a nominal type, shallow copy the entire thing
            try module.builder.build(CopyAddrInst(addr: lValueReference(), out: outAccessor.lValueReference()))
        }
    }
    
}
