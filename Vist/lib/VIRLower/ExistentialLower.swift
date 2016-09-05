//
//  ExistentialLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ExistentialConstructInst : VIRLower {
    
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        guard let structType = try value.type?.getAsStructType() else { fatalError() }
        
        let exMemory = try IGF.builder.buildAlloca(type: Runtime.existentialObjectType.importedType(in: module).lowered(module: module))
        // in
        let structMemory = try IGF.builder.buildAlloca(type: structType.importedType(in: module).lowered(module: module))
        try IGF.builder.buildStore(value: value.loweredValue!, in: structMemory)
        let mem = try IGF.builder.buildBitcast(value: structMemory, to: .opaquePointer)
        
        return try ExistentialConstructInst.gen(instance: mem,
                                                out: exMemory,
                                                structType: structType,
                                                existentialType: existentialType,
                                                isLocal: isLocal,
                                                module: module,
                                                IGF: &IGF)
    }
    
    static func gen(instance mem: LLVMValue,
                    out exMemory: LLVMValue,
                    structType: StructType,
                    existentialType: ConceptType,
                    isLocal: Bool,
                    module: Module,
                    IGF: inout IRGenFunction) throws -> LLVMValue {
        let type = try structType.getLLVMTypeMetadata(IGF: &IGF, module: module)
        let conf = try structType.generateConformanceMetadata(concept: existentialType, IGF: &IGF, module: module).metadata
        let nonLocal = LLVMValue.constBool(value: !isLocal)
        
        let ref = module.getRuntimeFunction(.constructExistential, IGF: &IGF)
        try IGF.builder.buildCall(function: ref, args: [conf, mem, type, nonLocal, exMemory])
        
        let exType = existentialType.importedType(in: module).lowered(module: module).getPointerType()
        return try IGF.builder.buildBitcast(value: exMemory, to: exType)
    }
}


extension ExistentialWitnessInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        let i = existentialType.methods.index(where: {$0.name == methodName})!
        
        let fnType = existentialType.methods[i].type
            .asMethodWithOpaqueParent()
            .cannonicalType(module: module)
            .importedType(in: module)
        
        let ref = module.getRuntimeFunction(.getWitnessMethod, IGF: &IGF)
        
        let conformanceIndex = LLVMValue.constInt(value: 0, size: 32), methodIndex = LLVMValue.constInt(value: i, size: 32)
        let functionPointer = try IGF.builder.buildCall(function: ref, args: [existential.loweredValue!, conformanceIndex, methodIndex])
        
        let functionType = BuiltinType.pointer(to: fnType).lowered(module: module)
        return try IGF.builder.buildBitcast(value: functionPointer, to: functionType, name: irName) // fntype*
    }
}

extension ExistentialProjectPropertyInst : VIRLower {
    
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        guard
            case let aliasType as TypeAlias = existential.memType,
            case let conceptType as ConceptType = aliasType.targetType,
            let propertyPtrType = type else { fatalError() }
        
        // index of property in the concept's table
        // use this to look up the index in self by getting the ixd from the runtime's array
        let i = try conceptType.index(ofMemberNamed: propertyName)
        
        let exType = Runtime.existentialObjectType.importedType(in: module).lowered(module: module).getPointerType()
        let ex = try IGF.builder.buildBitcast(value: existential.loweredValue!, to: exType)
        let conformanceIndex = LLVMValue.constInt(value: 0, size: 32), propertyIndex = LLVMValue.constInt(value: i, size: 32)
        
        let ref = module.getRuntimeFunction(.getPropertyProjection, IGF: &IGF)
        let instanceMemberPtr = try IGF.builder.buildCall(function: ref, args: [ex, conformanceIndex, propertyIndex])

        let elementPtrType = propertyPtrType.lowered(module: module) // ElTy*.Type
        return try IGF.builder.buildBitcast(value: instanceMemberPtr, to: elementPtrType, name: irName.+"ptr")  // ElTy*
    }
}



extension ExistentialProjectInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let exType = Runtime.existentialObjectType.importedType(in: module).lowered(module: module).getPointerType()
        let ex = try IGF.builder.buildBitcast(value: existential.loweredValue!, to: exType)
        
        let ref = module.getRuntimeFunction(.getBufferProjection, IGF: &IGF)
        return try IGF.builder.buildCall(function: ref, args: [ex])
    }
}

extension ExistentialExportBufferInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let ref = module.getRuntimeFunction(.exportExistentialBuffer, IGF: &IGF)
        return try IGF.builder.buildCall(function: ref, args: [existential.loweredValue!])
    }
}






extension NominalType {
    
    func getTypeMetadata(IGF: inout IRGenFunction, module: Module) throws -> TypeMetadata {
        
        if let metadata = IGF.module.typeMetadata[name] {
            return metadata
        }
        
        var conformances: [UnsafeMutablePointer<ConceptConformance>?] = []
        
        // if its a struct, we can emit the conformance tables
        if case let s as StructType = getConcreteNominalType() {
            conformances = try concepts
                .map { concept in try s.generateConformanceMetadata(concept: concept, IGF: &IGF, module: module).conformance }
                .map (UnsafeMutablePointer.allocInit(value:))
        }
        
        let utf8 = UnsafePointer<Int8>(Array(name.nulTerminatedUTF8).copyBuffer())
        let c = conformances.copyBuffer()
        let size = lowered(module: module).size(unit: .bytes, IGF: IGF)
        
        let destructor = module.type(named: name)!.destructor?
            .buildFunctionPointer().loweredValue?
            ._value.map(UnsafeMutablePointer<Void>.init)
        let copyConstructor = module.type(named: name)!.copyConstructor?
            .buildFunctionPointer().loweredValue?
            ._value.map(UnsafeMutablePointer<Void>.init)
        
        let md = TypeMetadata(conceptConformanceArr: c,
                              conceptConformanceArrCount: Int32(conformances.count),
                              size: Int32(size),
                              name: utf8,
                              destructor: destructor,
                              copyConstructor: copyConstructor)
        IGF.module.typeMetadata[name] = md
        
        return md
    }
    
    func getLLVMTypeMetadata(IGF: inout IRGenFunction, module: Module) throws -> LLVMValue {
        
        let metadataName = "_g\(name)s"
        
        if let g = IGF.module.global(named: metadataName) {
            return g.value
        }
        return try getTypeMetadata(IGF: &IGF, module: module).getConstMetadata(IGF: &IGF, module: module, name: metadataName)
    }
    
}



extension StructType {
    
    func generateConformanceMetadata(concept: ConceptType, IGF: inout IRGenFunction, module: Module) throws -> (conformance: ConceptConformance, metadata: LLVMValue) {
        
        let valueWitnesses = try concept
            .existentialValueWitnesses(structType: self, module: module, IGF: &IGF)
            .map(UnsafeMutablePointer.allocInit(value:))
//        defer {
//            valueWitnesses.forEach {
//                $0?.deinitialize()
//                $0?.deallocateCapacity(1)
//            }
//        }
        
        let v = valueWitnesses.copyBuffer()
//        defer {
//            v.deinitialize()
//            v.deallocateCapacity(1)
//        }
        let witnessTable = UnsafeMutablePointer.allocInit(value:
            WitnessTable(witnessArr: v, witnessArrCount: Int32(valueWitnesses.count)))!
//        defer {
//            witnessTable.deinitialize()
//            witnessTable.deallocateCapacity(1)
//        }
        
        let witnesses = try concept.existentialWitnessOffsets(structType: self, module: module, IGF: &IGF)
            .map(UnsafeMutablePointer.allocInit(value:))
        let witnessOffsets = witnesses.copyBuffer()
        let metadata = try UnsafeMutablePointer.allocInit(value: concept.getTypeMetadata(IGF: &IGF, module: module))!
        
        let c = ConceptConformance(concept: metadata,
                                   propWitnessOffsetArr: witnessOffsets,
                                   propWitnessOffsetArrCount: Int32(witnesses.count),
                                   witnessTable: witnessTable)
        
        let md = try c.getConstMetadata(IGF: &IGF, module: module, name: "_g\(name)conf\(concept.name)")
        
        return (c, md)
    }
}

extension UnsafeMutablePointer {
    static func allocInit(value: Pointee) -> UnsafeMutablePointer<Pointee>? {
        let v = UnsafeMutablePointer<Pointee>.allocate(capacity: 1)
        v.initialize(to: value)
        return v
    }
}

extension Array {
    func copyBuffer() -> UnsafeMutablePointer<Element> {
        return withUnsafeBufferPointer { buffer in
            let b = UnsafeMutablePointer<Element>.allocate(capacity: count)
            b.assign(from: UnsafeMutablePointer(buffer.baseAddress!), count: count)
            return b
        }
    }
}


private extension ConceptType {
    
    func existentialWitnessOffsets(structType: StructType, module: Module, IGF: inout IRGenFunction) throws -> [Int32] {
        let conformingType = structType.lowered(module: module) as LLVMType
        
        // a table of offsets
        return try requiredProperties
            .map { propName, _, _ in try structType.index(ofMemberNamed: propName) }
            .map { index in Int32(conformingType.offsetOfElement(at: index, module: IGF.module)) } // make 'get offset' an extension on aggregate types
    }
    
    func existentialValueWitnesses(structType: StructType, module: Module, IGF: inout IRGenFunction) throws -> [Witness] {
        
        guard let table = module.witnessTables.first(where: { $0.concept == self && $0.type == structType }) else { return [] }
        
        return try requiredFunctions
            .map { methodName, _, _ in
                let val = try table.getWitness(name: methodName, module: module).loweredValue!._value!
                return Witness(witness: UnsafeMutablePointer<Void>(val))
            }
    }
    
}


