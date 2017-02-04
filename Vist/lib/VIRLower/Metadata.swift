//
//  Metadata.swift
//  Vist
//
//  Created by Josef Willsher on 12/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol RuntimeMetadata {
    var globalName: String { get }
    var loweredValue: LLVMValue! { get }
    func lowerMetadata(igf: inout IRGenFunction, module: Module) throws -> LLVMValue
}


/**
 struct TypeMetadata {
    ConceptConformance *_Nullable *_Nonnull conceptConformances;
    int32_t numConformances;
    
    TypeMetadata *_Nullable *_Nonnull genericParamList;
    
    int32_t size;
    const char *_Nonnull name;
    bool isRefCounted;
 */
struct TypeDeclMetadata : RuntimeMetadata {
    
    let conformances: [WitnessTableMetadata]
    let size: Int
    let typeName: String
    let isRefCounted: Bool
    let destructor: LLVMFunction?, copyConstructor: LLVMFunction?, `deinit`: LLVMFunction?
    
    let globalName: String
    var loweredValue: LLVMValue! = nil
    
    init(conformances: [WitnessTableMetadata], size: Int, typeName: String, isRefCounted: Bool,
         destructor: LLVMFunction?, copyConstructor: LLVMFunction?, `deinit`: LLVMFunction?,
         module: Module, igf: inout IRGenFunction) throws {
        self.conformances = conformances
        self.size = size
        self.typeName = typeName
        self.isRefCounted = isRefCounted
        self.destructor = destructor
        self.copyConstructor = copyConstructor
        self.`deinit` = `deinit`
        self.globalName = "_g\(typeName)_decl"
        self.loweredValue = try igf.module.globalMetadataMap[globalName]?.value ?? lowerMetadata(igf: &igf, module: module)
    }

    func lowerMetadata(igf: inout IRGenFunction, module: Module) throws -> LLVMValue {
        // get types used
        let declType = TypeDeclMetadata.loweredType.importedCanType(in: module)
        let wtType = WitnessTableMetadata.loweredType.importedCanType(in: module)
        
        // build val and construct
        let val = try LLVMBuilder.constAggregate(type: declType, elements: [
                LLVMValue.constGlobalArray(of: wtType.getPointerType(), vals: conformances.map { $0.loweredValue },
                                           name: "\(globalName)_confs", igf: igf),
                LLVMValue.constInt(value: conformances.count, size: 32),
                LLVMValue.constNull(type: .opaquePointer),
                LLVMValue.constInt(value: size, size: 32),
                igf.module.getCachedGlobalString(typeName, name: "\(globalName).\(typeName).metadataname", igf: &igf),
                LLVMValue.constBool(value: isRefCounted),
                destructor.map { try LLVMBuilder.constBitcast(value: $0.function, to: .opaquePointer) } ?? LLVMValue.constNull(type: .opaquePointer),
                `deinit`.map { try LLVMBuilder.constBitcast(value: $0.function, to: .opaquePointer) } ?? LLVMValue.constNull(type: .opaquePointer),
                copyConstructor.map { try LLVMBuilder.constBitcast(value: $0.function, to: .opaquePointer) } ?? LLVMValue.constNull(type: .opaquePointer),
            ])
        return igf.module.createCachedGlobal(value: val, name: globalName, igf: &igf).value
    }
    
    static let loweredType = Runtime.typeMetadataType
}

/**
 ```
struct WitnessTable {
    TypeMetadata *_Nonnull concept;
    
    WitnessTable *_Nullable *_Nonnull subtables;
    
    int32_t *_Nullable *_Nonnull propWitnessOffsets;  /// Offset of concept elements
    int32_t numOffsets;       /// Number of offsets in `propWitnessOffsets`
    
    void *_Nullable *_Nonnull witnesses;
    int32_t numWitnesses;
};
 ```
 */
struct WitnessTableMetadata : RuntimeMetadata {
    
    let concept: TypeDeclMetadata
    let propWitnessOffsets: [Int]
    let witnesses: [LLVMFunction]
    
    var loweredValue: LLVMValue! = nil
    let globalName: String
    
    init(concept: TypeDeclMetadata, witnesses: [LLVMFunction], offsets: [Int], conformingTypeName: String, module: Module, igf: inout IRGenFunction) throws {
        self.concept = concept
        self.witnesses = witnesses
        self.propWitnessOffsets = offsets
        self.globalName = "_g\(conformingTypeName)_conf_\(concept.typeName)"
        self.loweredValue = try igf.module.globalMetadataMap[globalName]?.value ?? lowerMetadata(igf: &igf, module: module)
    }
    
    
    func lowerMetadata(igf: inout IRGenFunction, module: Module) throws -> LLVMValue {
        // get types used
        let tableType = WitnessTableMetadata.loweredType.importedCanType(in: module)
        // build val and construct
        let val = try LLVMBuilder.constAggregate(type: tableType, elements: [
                LLVMBuilder.constBitcast(value: concept.loweredValue, to: .opaquePointer),
                LLVMValue.constNull(type: .opaquePointer),
                LLVMValue.constGlobalArray(of: LLVMType.intType(size: 32),
                                           vals: propWitnessOffsets.map { LLVMValue.constInt(value: $0, size: 32) },
                                           name: "\(globalName)_offs", igf: igf),
                LLVMValue.constInt(value: propWitnessOffsets.count, size: 32),
                LLVMValue.constGlobalArray(of: .opaquePointer,
                                           vals: witnesses.map { try LLVMBuilder.constBitcast(value: $0.function, to: .opaquePointer) },
                                           name: "\(globalName)_witnesses", igf: igf),
                LLVMValue.constInt(value: witnesses.count, size: 32),
            ])
        return igf.module.createCachedGlobal(value: val, name: globalName, igf: &igf).value
    }
    
    static let loweredType = Runtime.witnessTableType
}

