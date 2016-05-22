//
//  ExistentialLower.swift
//  Vist
//
//  Created by Josef Willsher on 22/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

extension ExistentialConstructInst : VIRLower {
    
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        
        guard case let aliasType as TypeAlias = value.memType, case let structType as StructType = aliasType.targetType else { fatalError() }
        
        let exType = existentialType.usingTypesIn(module).lowerType(module) as LLVMType
        let valueMem = try IGF.builder.buildAlloca(type: aliasType.lowerType(module)) // allocate the struct
        let ptr = try IGF.builder.buildAlloca(type: exType)
        
        let llvmName = irName.map { "\($0)." }
        
        let propArrayPtr = try IGF.builder.buildStructGEP(ptr, index: 0, name: "\(llvmName)prop_metadata") // [n x i32]*
        let methodArrayPtr = try IGF.builder.buildStructGEP(ptr, index: 1, name: "\(llvmName)method_metadata") // [n x i8*]*
        let structPtr = try IGF.builder.buildStructGEP(ptr, index: 2, name: "\(llvmName)opaque")  // i8**
        
        let propArr = try existentialType.existentialPropertyMetadataFor(structType, IGF: &IGF, module: module)
        try IGF.builder.buildStore(value: propArr, in: propArrayPtr)
        
        let methodArr = try existentialType.existentialMethodMetadataFor(structType, IGF: &IGF, module: module)
        try IGF.builder.buildStore(value: methodArr, in: methodArrayPtr)
        
        let v = try IGF.builder.buildLoad(from: value.loweredValue!)
        try IGF.builder.buildStore(value: v, in: valueMem)
        let opaqueValueMem = try IGF.builder.buildBitcast(value: valueMem, to: BuiltinType.opaquePointer.lowerType(module))
        try IGF.builder.buildStore(value: opaqueValueMem, in: structPtr)
        
        let ret = try IGF.builder.buildLoad(from: ptr, name: irName)
        
        
        
        
//        let ref = module.getOrAddRuntimeFunction(named: "vist_constructConceptConformance", IGF: &IGF)
        
        let conf = try structType.generateConformanceMetadata(&IGF, concept: existentialType)
        
//        var conformances = [UnsafeMutablePointer.allocInit(conf)]
//        let f = ExistentialObject(object: UnsafeMutablePointer(
//            value.loweredValue!._value // can't have non const values in metadata -- this needs to 
//                                       // either be a function call, or generate it non constly
//            ), conformanceArrCount: Int32(conformances.count), conformanceArr: &conformances)
//        try f.getConstMetadata(&IGF, name: "eee")
        
        return ret
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
                .map { concept in try s.generateConformanceMetadata(&IGF, concept: concept) }
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
    
    func generateConformanceMetadata(inout IGF: IRGenFunction, concept: ConceptType) throws -> ConceptConformance {
        
        var valueWitnesses = try concept.existentialValueWitnesses(self, IGF: &IGF)
        var witnessTable = WitnessTable(witnessArr: &valueWitnesses, witnessArrCount: Int32(valueWitnesses.count))
        
        var witnessOffsets = try concept.existentialWitnessOffsets(self, IGF: &IGF)
        var metadata = try concept.getTypeMetadata(&IGF)
        let c = ConceptConformance(concept: &metadata,
                                   propWitnessOffsetArr: &witnessOffsets,
                                   propWitnessOffsetArrCount: Int32(witnessOffsets.count),
                                   witnessTable: &witnessTable)
        
        let md = try c.getConstMetadata(&IGF, name: "_g\(name)conf\(concept.name)")
        
        return c
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

extension ExistentialUnboxInst : VIRLower {
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        let p = try IGF.builder.buildStructGEP(existential.loweredValue!, index: 2, name: name)
        return try IGF.builder.buildLoad(from: p, name: irName)
    }
}

extension ExistentialWitnessMethodInst : VIRLower {
    func virLower(inout IGF: IRGenFunction) throws -> LLVMValue {
        
        let llvmName = irName.map { "\($0)." } ?? ""
        let i = try existentialType.indexOf(methodNamed: methodName, argTypes: argTypes)
        let fnType = try existentialType
            .methodType(methodNamed: methodName, argTypes: argTypes)
            .withOpaqueParent().cannonicalType(module)
            .usingTypesIn(module)
        
        let index = LLVMValue.constInt(i, size: 32) // i32
        
        let opaquePtrType = LLVMType.opaquePointer.getPointerType()
        let arr = try IGF.builder.buildStructGEP(existential.loweredValue!, index: 1, name: "\(llvmName)witness_table_ptr") // [n x i8*]*
        let methodMetadataBasePtr = try IGF.builder.buildBitcast(value: arr, to: opaquePtrType, name: "\(llvmName)witness_table_base_ptr") // i8**
        
        let pointerToArrayElement = try IGF.builder.buildGEP(methodMetadataBasePtr, index: index)
        let functionPointer = try IGF.builder.buildLoad(from: pointerToArrayElement) // i8*
        
        let functionType = BuiltinType.pointer(to: fnType).lowerType(module) as LLVMType
        return try IGF.builder.buildBitcast(value: functionPointer, to: functionType, name: irName) // fntype*
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

