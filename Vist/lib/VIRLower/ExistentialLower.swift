//
//  ExistentialLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ExistentialConstructInst : VIRLower {
    
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        guard let structType = try value.memType?.getAsStructType() else { fatalError() }
        
        let ref = module.getRuntimeFunction(.constructExistential, IGF: &IGF)
        
        let mem = try IGF.builder.buildBitcast(value: value.loweredValue!, to: LLVMType.opaquePointer)
        let conf = try structType.generateConformanceMetadata(concept: existentialType, IGF: &IGF, module: module).metadata
       
        let ex = try IGF.builder.buildCall(function: ref, args: [conf, mem])
        
        let exType = existentialType.importedType(in: module).lowered(module: module).getPointerType()
        let bc = try IGF.builder.buildBitcast(value: ex, to: exType)
        
        return try IGF.builder.buildLoad(from: bc, name: irName)
    }
}

extension ExistentialWitnessInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        
        let i = try existentialType.index(ofMethodNamed: methodName, argTypes: argTypes)
        let fnType = try existentialType
            .methodType(methodNamed: methodName, argTypes: argTypes)
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

extension OpenExistentialPropertyInst : VIRLower {
    
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
        
        let ref = module.getRuntimeFunction(.getPropertyOffset, IGF: &IGF)
        let offset = try IGF.builder.buildCall(function: ref, args: [ex, conformanceIndex, propertyIndex])

        let elementPtrType = propertyPtrType.lowered(module: module) // ElTy*.Type
        let structElementPointer = try IGF.builder.buildStructGEP(ofAggregate: existential.loweredValue!, index: 0, name: irName.+"element_pointer") // i8**
        let opaqueInstancePointer = try IGF.builder.buildLoad(from: structElementPointer, name: irName.+"opaque_instance_pointer")  // i8*
        let instanceMemberPtr = try IGF.builder.buildGEP(ofAggregate: opaqueInstancePointer, index: offset)
        return try IGF.builder.buildBitcast(value: instanceMemberPtr, to: elementPtrType, name: irName.+"ptr")  // ElTy*
    }
}



extension ExistentialProjectInst : VIRLower {
    func virLower(IGF: inout IRGenFunction) throws -> LLVMValue {
        let p = try IGF.builder.buildStructGEP(ofAggregate: existential.loweredValue!, index: 0, name: irName.+"projection")
        let v = try IGF.builder.buildLoad(from: p)
        return try IGF.builder.buildBitcast(value: v, to: LLVMType.opaquePointer, name: irName)
    }
}




extension NominalType {
    
    func getTypeMetadata(IGF: inout IRGenFunction, module: Module) throws -> TypeMetadata {
        
        if let g = IGF.module.typeMetadata[name] {
            return g
        }
        
        var conformances: [UnsafeMutablePointer<ConceptConformance>?] = []
        
        // if its a struct, we can emit the conformance tables
        if case let s as StructType = self {
            conformances = try concepts
                .map { concept in try s.generateConformanceMetadata(concept: concept, IGF: &IGF, module: module).conformance }
                .map (UnsafeMutablePointer.allocInit(value:))
        }
        
        let utf8 = UnsafePointer<Int8>(Array(name.nulTerminatedUTF8).copyBuffer())
        let c = conformances.copyBuffer()
        
        let md = TypeMetadata(conceptConformanceArr: c,
                              conceptConformanceArrCount: Int32(conformances.count),
                              name: utf8)
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
            .existentialValueWitnesses(structType: self, IGF: &IGF)
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
        
        let witnesses = try concept.existentialWitnessOffsets(structType: self, IGF: &IGF)
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
    
    func existentialWitnessOffsets(structType: StructType, IGF: inout IRGenFunction) throws -> [Int32] {
        let conformingType = structType.lowered(module: Module()) as LLVMType
        
        // a table of offsets
        return try requiredProperties
            .map { propName, _, _ in try structType.index(ofMemberNamed: propName) }
            .map { index in Int32(conformingType.offsetOfElement(at: index, module: IGF.module)) } // make 'get offset' an extension on aggregate types
    }
    
    func existentialValueWitnesses(structType: StructType, IGF: inout IRGenFunction) throws -> [ValueWitness] {
        return requiredFunctions
            .map { methodName, type, mutating in
                ValueWitness(witness:
                    structType.ptrToMethod(named: methodName,
                                           type: type.asMethod(withSelf: structType, mutating: mutating),
                                           IGF: &IGF).unsafePointer!
                )
            }
    }
    
}


