//
//  ExistentialLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ExistentialConstructInst : VIRLower {
    
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        
        guard let structType = try value.memType?.getAsStructType() else { fatalError() }
        
        let ref = module.getOrAddRuntimeFunction(named: "vist_constructExistential", IGF: &IGF)
        
        let mem = try IGF.builder.buildBitcast(value: value.loweredValue!, to: LLVMType.opaquePointer)
        let conf = try structType.generateConformanceMetadata(&IGF, concept: existentialType).metadata
       
        let ex = try IGF.builder.buildCall(ref, args: [conf, mem])
        
        let exType = existentialType.usingTypesIn(module).lowerType(module).getPointerType()
        let bc = try IGF.builder.buildBitcast(value: ex, to: exType)
        
        return try IGF.builder.buildLoad(from: bc, name: irName)
    }
}

extension ExistentialWitnessInst : VIRLower {
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        
        let i = try existentialType.indexOf(methodNamed: methodName, argTypes: argTypes)
        let fnType = try existentialType
            .methodType(methodNamed: methodName, argTypes: argTypes)
            .withOpaqueParent().cannonicalType(module)
            .usingTypesIn(module)
        
        let ref = module.getOrAddRuntimeFunction(named: "vist_getWitnessMethod", IGF: &IGF)
        
        let exType = Runtime.existentialObjectType.lowerType(module).getPointerType()
        let conformanceIndex = LLVMValue.constInt(0, size: 32), methodIndex = LLVMValue.constInt(i, size: 32)
        let ex = try IGF.builder.buildBitcast(value: existential.loweredValue!, to: exType)
        let functionPointer = try IGF.builder.buildCall(ref, args: [ex, conformanceIndex, methodIndex])
        
        let functionType = BuiltinType.pointer(to: fnType).lowerType(module)
        return try IGF.builder.buildBitcast(value: functionPointer, to: functionType, name: irName) // fntype*
    }
}


extension ExistentialProjectInst : VIRLower {
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        let p = try IGF.builder.buildStructGEP(existential.loweredValue!, index: 0, name: irName.map { "\($0).projection" })
        let v = try IGF.builder.buildLoad(from: p)
        return try IGF.builder.buildBitcast(value: v, to: LLVMType.opaquePointer, name: irName)
    }
}




extension NominalType {
    
    func getTypeMetadata(inout IGF: IRGenFunction) throws -> TypeMetadata {
        
        if let g = IGF.module.typeMetadata[name] {
            return g
        }
        
        var conformances: [UnsafeMutablePointer<ConceptConformance>] = []
        
        // if its a struct, we can emit the conformance tables
        if case let s as StructType = self {
            conformances = try concepts
                .map { concept in try s.generateConformanceMetadata(&IGF, concept: concept).conformance }
                .map { UnsafeMutablePointer.allocInit($0) }
        }
        
        let utf8 = name.nulTerminatedUTF8
        let base = utf8.withUnsafeBufferPointer { buffer -> UnsafeMutablePointer<CChar> in
            let b = UnsafeMutablePointer<CChar>.alloc(utf8.count)
            b.assignFrom(UnsafeMutablePointer<CChar>(buffer.baseAddress), count: utf8.count)
            return b
        }
        let md = TypeMetadata(conceptConformanceArr: &conformances,
                              conceptConformanceArrCount: Int32(conformances.count),
                              name: base)
        IGF.module.typeMetadata[name] = md
        
        return md
    }
    
    func getLLVMTypeMetadata(inout IGF: IRGenFunction) throws -> LLVMValue {
        
        let metadataName = "_g\(name)s"
        
        if let g = IGF.module.global(named: metadataName) {
            return g.value
        }
        return try getTypeMetadata(&IGF).getConstMetadata(&IGF, name: metadataName)
    }
    
}



extension StructType {
    
    func generateConformanceMetadata(inout IGF: IRGenFunction, concept: ConceptType) throws -> (conformance: ConceptConformance, metadata: LLVMValue) {
        
        var valueWitnesses = try concept.existentialValueWitnesses(self, IGF: &IGF).map(UnsafeMutablePointer.allocInit)
        var witnessTable = WitnessTable(witnessArr: &valueWitnesses, witnessArrCount: Int32(valueWitnesses.count))
        
        var witnessOffsets = try concept.existentialWitnessOffsets(self, IGF: &IGF)
        var metadata = try concept.getTypeMetadata(&IGF)
        let c = ConceptConformance(concept: &metadata,
                                   propWitnessOffsetArr: &witnessOffsets,
                                   propWitnessOffsetArrCount: Int32(witnessOffsets.count),
                                   witnessTable: &witnessTable)
        
        let md = try c.getConstMetadata(&IGF, name: "_g\(name)conf\(concept.name)")
        
        return (c, md)
    }
}

extension UnsafeMutablePointer {
    static func allocInit(val: Memory) -> UnsafeMutablePointer<Memory> {
        let v = UnsafeMutablePointer<Memory>.alloc(1)
        v.initialize(val)
        return v
    }
}


private extension ConceptType {
    
    func existentialWitnessOffsets(structType: StructType, inout IGF: IRGenFunction) throws -> [Int32] {
        let conformingType = structType.lowerType(Module()) as LLVMType
        
        // a table of offsets
        return try requiredProperties
            .map { propName, _, _ in try structType.indexOfMemberNamed(propName) }
            .map { index in Int32(conformingType.offsetOfElement(index: index, module: IGF.module)) } // make 'get offset' an extension on aggregate types
    }
    
    func existentialValueWitnesses(structType: StructType, inout IGF: IRGenFunction) throws -> [ValueWitness] {
        return requiredFunctions
            .map { methodName, type, mutating in
                ValueWitness(witness:
                    structType.ptrToMethod(named: methodName,
                        type: type.withParent(structType, mutating: mutating),
                        IGF: &IGF).unsafePointer
                )
            }
    }
    
}
















extension ExistentialPropertyInst : VIRLower {
    
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        
        guard case let aliasType as TypeAlias = existential.memType, case let conceptType as ConceptType = aliasType.targetType, let propertyType = type else { fatalError() }
        
        // index of property in the concept's table
        // use this to look up the index in self by getting the ixd from the runtime's array
        let i = try conceptType.indexOfMemberNamed(propertyName)
        let index = LLVMValue.constInt(i, size: 32) // i32
        
        let llvmName = irName.map { "\($0)." } ?? ""
        
        let i32PtrType = BuiltinType.pointer(to: BuiltinType.int(size: 32)).lowerType(module) as LLVMType
        let arr = try IGF.builder.buildStructGEP(existential.loweredValue!, index: 0, name: "\(llvmName)metadata_ptr") // [n x i32]*
        let propertyMetadataBasePtr = try IGF.builder.buildBitcast(value: arr, to: i32PtrType, name: "\(llvmName)metadata_base_ptr") // i32*
        
        let pointerToArrayElement = try IGF.builder.buildGEP(propertyMetadataBasePtr, index: index) // i32*
        let offset = try IGF.builder.buildLoad(from: pointerToArrayElement) // i32
        
        let elementPtrType = propertyType.lowerType(module).getPointerType() // ElTy*.Type
        let structElementPointer = try IGF.builder.buildStructGEP(existential.loweredValue!, index: 2, name: "\(llvmName)element_pointer") // i8**
        let opaqueInstancePointer = try IGF.builder.buildLoad(from: structElementPointer, name: "\(llvmName)opaque_instance_pointer")  // i8*
        let instanceMemberPtr = try IGF.builder.buildGEP(opaqueInstancePointer, index: offset)
        let elPtr = try IGF.builder.buildBitcast(value: instanceMemberPtr, to: elementPtrType, name: "\(llvmName)ptr")  // ElTy*
        
        return try IGF.builder.buildLoad(from: elPtr, name: irName)
    }
}

private extension ConceptType {
        
    /// Returns the metadata array map, which transforms the protocol's properties
    /// to an element in the `type`. Type `[n * i32]`
    func existentialPropertyMetadataFor(structType: StructType, inout IGF: IRGenFunction, module: Module) throws -> LLVMValue {
        
        let conformingType = structType.lowerType(module) as LLVMType
        
        // a table of offsets
        let offsets = try requiredProperties
            .map { propName, _, _ in try structType.indexOfMemberNamed(propName) }
            .map { index in conformingType.offsetOfElement(index: index, module: IGF.module) } // make 'get offset' an extension on aggregate types
            .map { LLVMValue.constInt($0, size: 32) }
        
        return try IGF.builder.buildArray(offsets,
                                          elType: BuiltinType.int(size: 32).lowerType(module))
    }
    
    /// Returns the metadata array of function pointers. Type `[n * i8*]`
    func existentialMethodMetadataFor(structType: StructType, inout IGF: IRGenFunction, module: Module) throws -> LLVMValue {
        
        let opaquePtrType = BuiltinType.opaquePointer
        
        let ptrs = try requiredFunctions
            .map { methodName, type, mutating in
                try structType.ptrToMethodNamed(methodName, type: type.withParent(structType, mutating: mutating), module: module)
            }
            .map { ptr in
                try IGF.builder.buildBitcast(value: ptr.function, to: opaquePtrType.lowerType(module), name: ptr.name)
        }
        
        return try IGF.builder.buildArray(ptrs,
                                          elType: opaquePtrType.lowerType(module))
    }
}

