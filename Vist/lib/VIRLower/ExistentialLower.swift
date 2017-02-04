//
//  ExistentialLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ExistentialConstructInst : VIRLower {
    
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        
        guard let ty = value.type?.getBasePointeeType() else { fatalError() }
        assert(!ty.isConceptType())
        let structType: NominalType = try ty.isStructType() ? ty.getAsStructType() : ty.getAsClassType()
        
        let exMemory = try igf.builder.buildAlloca(type: Runtime.existentialObjectType.importedCanType(in: module))
        // in mem -- if a class, use the shared ptr, if a struct alloc stack space and store
        let structMemory = try ty.isClassType() ? value.loweredValue! : {
            let mem = try igf.builder.buildAlloca(type: structType.importedCanType(in: module))
            try igf.builder.buildStore(value: value.loweredValue!, in: mem)
            return mem
        }()
        let mem = try igf.builder.buildBitcast(value: structMemory, to: .opaquePointer)
        
        return try ExistentialConstructInst.gen(instance: mem,
                                                out: exMemory,
                                                structType: structType,
                                                existentialType: existentialType,
                                                isLocal: isLocal,
                                                module: module,
                                                igf: &igf)
    }
    
    static func gen(instance mem: LLVMValue,
                    out exMemory: LLVMValue,
                    structType: NominalType,
                    existentialType: ConceptType,
                    isLocal: Bool,
                    module: Module,
                    igf: inout IRGenFunction) throws -> LLVMValue {
        let type = try structType.getLLVMTypeMetadata(igf: &igf, module: module)
        let conf = try [structType.generateConformanceMetadata(concept: existentialType, igf: &igf, module: module).loweredValue!]
        let wtType = Runtime.witnessTableType.ptrType().importedCanType(in: module)
        let confs = try LLVMValue.constGlobalArray(of: wtType, vals: conf, name: "_g_cmd_\(structType.name)_conf_\(existentialType.name)", igf: igf)
        let nonLocal = LLVMValue.constBool(value: !isLocal)
        let size = LLVMValue.constInt(value: conf.count, size: 32)
        
        let ref = module.getRuntimeFunction(.constructExistential, igf: &igf)
        try igf.builder.buildCall(function: ref, args: [confs, size, mem, type, nonLocal, exMemory])
        
        let exType = existentialType.importedCanType(in: module).getPointerType()
        return try igf.builder.buildBitcast(value: exMemory, to: exType)
    }
}


extension ExistentialWitnessInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        
        let i = existentialType.methods.index(where: {$0.name == methodName})!
        
        let fnType = existentialType.methods[i].type
            .asMethodWithOpaqueParent()
            .cannonicalType(module: module)
            .importedType(in: module)
        
        let ref = module.getRuntimeFunction(.getWitnessMethod, igf: &igf)
        
        let conformanceIndex = LLVMValue.constInt(value: 0, size: 32), methodIndex = LLVMValue.constInt(value: i, size: 32)
        let functionPointer = try igf.builder.buildCall(function: ref, args: [existential.loweredValue!, conformanceIndex, methodIndex])
        
        let functionType = BuiltinType.pointer(to: fnType).lowered(module: module)
        return try igf.builder.buildBitcast(value: functionPointer, to: functionType, name: irName) // fntype*
    }
}

extension ExistentialProjectPropertyInst : VIRLower {
    
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        
        guard
            case let aliasType as ModuleType = existential.memType,
            case let conceptType as ConceptType = aliasType.targetType,
            let propertyPtrType = type else { fatalError() }
        
        // index of property in the concept's table
        // use this to look up the index in self by getting the ixd from the runtime's array
        let i = try conceptType.index(ofMemberNamed: propertyName)
        
        let exType = Runtime.existentialObjectType.importedCanType(in: module).getPointerType()
        let ex = try igf.builder.buildBitcast(value: existential.loweredValue!, to: exType)
        let conformanceIndex = LLVMValue.constInt(value: 0, size: 32), propertyIndex = LLVMValue.constInt(value: i, size: 32)
        
        let ref = module.getRuntimeFunction(.getPropertyProjection, igf: &igf)
        let instanceMemberPtr = try igf.builder.buildCall(function: ref, args: [ex, conformanceIndex, propertyIndex])

        let elementPtrType = propertyPtrType.lowered(module: module) // ElTy*.Type
        return try igf.builder.buildBitcast(value: instanceMemberPtr, to: elementPtrType, name: irName.+"ptr")  // ElTy*
    }
}



extension ExistentialProjectInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let exType = Runtime.existentialObjectType.importedCanType(in: module).getPointerType()
        let ex = try igf.builder.buildBitcast(value: existential.loweredValue!, to: exType)
        
        let ref = module.getRuntimeFunction(.getBufferProjection, igf: &igf)
        return try igf.builder.buildCall(function: ref, args: [ex])
    }
}

extension ExistentialExportBufferInst : VIRLower {
    func virLower(igf: inout IRGenFunction) throws -> LLVMValue {
        let ref = module.getRuntimeFunction(.exportExistentialBuffer, igf: &igf)
        return try igf.builder.buildCall(function: ref, args: [existential.loweredValue!])
    }
}






extension NominalType {
    
    @discardableResult
    func getTypeMetadata(igf: inout IRGenFunction, module: Module) throws -> TypeDeclMetadata {
        
        let confs: [WitnessTableMetadata]
        if let s = getConcreteNominalType(), !s.isConceptType(), !s.isRuntimeType() {
            confs = try concepts.map { concept in
                try self.generateConformanceMetadata(concept: concept, igf: &igf, module: module)
            }
        } else {
            confs = []
        }
    
        let size = instanceRawType(module: module).size(unit: .bytes, igf: igf)
        let moduleType = module.type(named: name)!
        
        return try TypeDeclMetadata(conformances: confs, size: size, typeName: mangleTypeName(), isRefCounted: isHeapAllocated,
                                    destructor: moduleType.destructor?.loweredFunction, copyConstructor: moduleType.copyConstructor?.loweredFunction,
                                    deinit: moduleType.deinitialiser?.loweredFunction, module: module, igf: &igf)
    }
    
    @discardableResult
    func getLLVMTypeMetadata(igf: inout IRGenFunction, module: Module) throws -> LLVMValue {
        return try getTypeMetadata(igf: &igf, module: module).loweredValue
    }
    
    
    private func mangleTypeName() -> String {
        return name
    }
    
    @discardableResult
    func generateConformanceMetadata(concept: ConceptType,
                                     igf: inout IRGenFunction,
                                     module: Module) throws -> WitnessTableMetadata {
        
        let offsets = try concept
            .existentialWitnessOffsets(structType: self, module: module, igf: &igf)
        let valueWitnesses = try concept
            .existentialValueWitnesses(structType: self, module: module, igf: &igf)
        
        return try WitnessTableMetadata(concept: concept.getTypeMetadata(igf: &igf, module: module),
                                        witnesses: valueWitnesses, offsets: offsets,
                                        conformingTypeName: mangleTypeName(), module: module, igf: &igf)
    }
}


private extension ConceptType {
    
    func existentialWitnessOffsets(structType: NominalType, module: Module, igf: inout IRGenFunction) throws -> [Int] {
        let conformingType = structType.lowered(module: module) as LLVMType
        
        // a table of offsets
        return try requiredProperties
            .map { propName, _, _ in try structType.index(ofMemberNamed: propName) }
            .map { index in conformingType.offsetOfElement(at: index, module: igf.module) }
    }
    
    func existentialValueWitnesses(structType: NominalType, module: Module, igf: inout IRGenFunction) throws -> [LLVMFunction] {
        
        guard let table = module.witnessTables.first(where: { $0.concept == self && $0.type == structType }) else { return [] }
        
        return try requiredFunctions
            .map { methodName, _, _ in
                try LLVMFunction(ref: table.getWitness(name: methodName, module: module).loweredValue!._value!)
            }
    }
    
}


