/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Subtarget Enumeration Source Fragment                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_SUBTARGETINFO_ENUM
#undef GET_SUBTARGETINFO_ENUM
namespace llvm {
namespace AMDGPU {
enum : uint64_t {
  Feature64BitPtr = 0,
  FeatureCFALUBug = 1,
  FeatureCIInsts = 2,
  FeatureCaymanISA = 3,
  FeatureDisable = 4,
  FeatureDumpCode = 5,
  FeatureDumpCodeLower = 6,
  FeatureEnableHugeScratchBuffer = 7,
  FeatureEnableLoadStoreOpt = 8,
  FeatureEnableUnsafeDSOffsetFolding = 9,
  FeatureEvergreen = 10,
  FeatureFP32Denormals = 11,
  FeatureFP64 = 12,
  FeatureFP64Denormals = 13,
  FeatureFastFMAF32 = 14,
  FeatureFetchLimit8 = 15,
  FeatureFetchLimit16 = 16,
  FeatureFlatAddressSpace = 17,
  FeatureGCN = 18,
  FeatureGCN1Encoding = 19,
  FeatureGCN3Encoding = 20,
  FeatureIRStructurizer = 21,
  FeatureISAVersion7_0_0 = 22,
  FeatureISAVersion7_0_1 = 23,
  FeatureISAVersion8_0_0 = 24,
  FeatureISAVersion8_0_1 = 25,
  FeatureIfCvt = 26,
  FeatureLDSBankCount16 = 27,
  FeatureLDSBankCount32 = 28,
  FeatureLocalMemorySize0 = 29,
  FeatureLocalMemorySize32768 = 30,
  FeatureLocalMemorySize65536 = 31,
  FeatureNorthernIslands = 32,
  FeaturePromoteAlloca = 33,
  FeatureR600 = 34,
  FeatureR600ALUInst = 35,
  FeatureR700 = 36,
  FeatureSGPRInitBug = 37,
  FeatureSeaIslands = 38,
  FeatureSouthernIslands = 39,
  FeatureVGPRSpilling = 40,
  FeatureVertexCache = 41,
  FeatureVolcanicIslands = 42,
  FeatureWavefrontSize16 = 43,
  FeatureWavefrontSize32 = 44,
  FeatureWavefrontSize64 = 45
};
}
} // end llvm namespace
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV AMDGPUFeatureKV[] = {
  { "64BitPtr", "Specify if 64-bit addressing should be used", { AMDGPU::Feature64BitPtr }, { } },
  { "DumpCode", "Dump MachineInstrs in the CodeEmitter", { AMDGPU::FeatureDumpCode }, { } },
  { "EVERGREEN", "EVERGREEN GPU generation", { AMDGPU::FeatureEvergreen }, { AMDGPU::FeatureFetchLimit16, AMDGPU::FeatureLocalMemorySize32768 } },
  { "HasVertexCache", "Specify use of dedicated vertex cache", { AMDGPU::FeatureVertexCache }, { } },
  { "NORTHERN_ISLANDS", "NORTHERN_ISLANDS GPU generation", { AMDGPU::FeatureNorthernIslands }, { AMDGPU::FeatureFetchLimit16, AMDGPU::FeatureWavefrontSize64, AMDGPU::FeatureLocalMemorySize32768 } },
  { "R600", "R600 GPU generation", { AMDGPU::FeatureR600 }, { AMDGPU::FeatureR600ALUInst, AMDGPU::FeatureFetchLimit8, AMDGPU::FeatureLocalMemorySize0 } },
  { "R600ALUInst", "Older version of ALU instructions encoding", { AMDGPU::FeatureR600ALUInst }, { } },
  { "R700", "R700 GPU generation", { AMDGPU::FeatureR700 }, { AMDGPU::FeatureFetchLimit16, AMDGPU::FeatureLocalMemorySize0 } },
  { "SEA_ISLANDS", "SEA_ISLANDS GPU generation", { AMDGPU::FeatureSeaIslands }, { AMDGPU::Feature64BitPtr, AMDGPU::FeatureFP64, AMDGPU::FeatureLocalMemorySize65536, AMDGPU::FeatureWavefrontSize64, AMDGPU::FeatureGCN, AMDGPU::FeatureFlatAddressSpace, AMDGPU::FeatureGCN1Encoding, AMDGPU::FeatureCIInsts } },
  { "SOUTHERN_ISLANDS", "SOUTHERN_ISLANDS GPU generation", { AMDGPU::FeatureSouthernIslands }, { AMDGPU::Feature64BitPtr, AMDGPU::FeatureFP64, AMDGPU::FeatureLocalMemorySize32768, AMDGPU::FeatureWavefrontSize64, AMDGPU::FeatureGCN, AMDGPU::FeatureGCN1Encoding, AMDGPU::FeatureLDSBankCount32 } },
  { "VOLCANIC_ISLANDS", "VOLCANIC_ISLANDS GPU generation", { AMDGPU::FeatureVolcanicIslands }, { AMDGPU::Feature64BitPtr, AMDGPU::FeatureFP64, AMDGPU::FeatureLocalMemorySize65536, AMDGPU::FeatureWavefrontSize64, AMDGPU::FeatureFlatAddressSpace, AMDGPU::FeatureGCN, AMDGPU::FeatureGCN3Encoding, AMDGPU::FeatureCIInsts, AMDGPU::FeatureLDSBankCount32 } },
  { "caymanISA", "Use Cayman ISA", { AMDGPU::FeatureCaymanISA }, { } },
  { "cfalubug", "GPU has CF_ALU bug", { AMDGPU::FeatureCFALUBug }, { } },
  { "ci-insts", "Additional intstructions for CI+", { AMDGPU::FeatureCIInsts }, { } },
  { "disable-ifcvt", "Disable the if conversion pass", { AMDGPU::FeatureIfCvt }, { } },
  { "disable-irstructurizer", "Disable IR Structurizer", { AMDGPU::FeatureIRStructurizer }, { } },
  { "dumpcode", "Dump MachineInstrs in the CodeEmitter", { AMDGPU::FeatureDumpCodeLower }, { } },
  { "fast-fmaf", "Assuming f32 fma is at least as fast as mul + add", { AMDGPU::FeatureFastFMAF32 }, { } },
  { "fetch16", "Limit the maximum number of fetches in a clause to 16", { AMDGPU::FeatureFetchLimit16 }, { } },
  { "fetch8", "Limit the maximum number of fetches in a clause to 8", { AMDGPU::FeatureFetchLimit8 }, { } },
  { "flat-address-space", "Support flat address space", { AMDGPU::FeatureFlatAddressSpace }, { } },
  { "fp32-denormals", "Enable single precision denormal handling", { AMDGPU::FeatureFP32Denormals }, { } },
  { "fp64", "Enable double precision operations", { AMDGPU::FeatureFP64 }, { } },
  { "fp64-denormals", "Enable double precision denormal handling", { AMDGPU::FeatureFP64Denormals }, { AMDGPU::FeatureFP64 } },
  { "gcn", "GCN or newer GPU", { AMDGPU::FeatureGCN }, { } },
  { "gcn1-encoding", "Encoding format for SI and CI", { AMDGPU::FeatureGCN1Encoding }, { } },
  { "gcn3-encoding", "Encoding format for VI", { AMDGPU::FeatureGCN3Encoding }, { } },
  { "huge-scratch-buffer", "Enable scratch buffer sizes greater than 128 GB", { AMDGPU::FeatureEnableHugeScratchBuffer }, { } },
  { "isaver7.0.0", "Instruction set version number", { AMDGPU::FeatureISAVersion7_0_0 }, { } },
  { "isaver7.0.1", "Instruction set version number", { AMDGPU::FeatureISAVersion7_0_1 }, { } },
  { "isaver8.0.0", "Instruction set version number", { AMDGPU::FeatureISAVersion8_0_0 }, { } },
  { "isaver8.0.1", "Instruction set version number", { AMDGPU::FeatureISAVersion8_0_1 }, { } },
  { "ldsbankcount16", "The number of LDS banks per compute unit.", { AMDGPU::FeatureLDSBankCount16 }, { } },
  { "ldsbankcount32", "The number of LDS banks per compute unit.", { AMDGPU::FeatureLDSBankCount32 }, { } },
  { "load-store-opt", "Enable SI load/store optimizer pass", { AMDGPU::FeatureEnableLoadStoreOpt }, { } },
  { "localmemorysize0", "The size of local memory in bytes", { AMDGPU::FeatureLocalMemorySize0 }, { } },
  { "localmemorysize32768", "The size of local memory in bytes", { AMDGPU::FeatureLocalMemorySize32768 }, { } },
  { "localmemorysize65536", "The size of local memory in bytes", { AMDGPU::FeatureLocalMemorySize65536 }, { } },
  { "promote-alloca", "Enable promote alloca pass", { AMDGPU::FeaturePromoteAlloca }, { } },
  { "sgpr-init-bug", "VI SGPR initilization bug requiring a fixed SGPR allocation size", { AMDGPU::FeatureSGPRInitBug }, { } },
  { "unsafe-ds-offset-folding", "Force using DS instruction immediate offsets on SI", { AMDGPU::FeatureEnableUnsafeDSOffsetFolding }, { } },
  { "vgpr-spilling", "Enable spilling of VGPRs to scratch memory", { AMDGPU::FeatureVGPRSpilling }, { } },
  { "wavefrontsize16", "The number of threads per wavefront", { AMDGPU::FeatureWavefrontSize16 }, { } },
  { "wavefrontsize32", "The number of threads per wavefront", { AMDGPU::FeatureWavefrontSize32 }, { } },
  { "wavefrontsize64", "The number of threads per wavefront", { AMDGPU::FeatureWavefrontSize64 }, { } }
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV AMDGPUSubTypeKV[] = {
  { "", "Select the  processor", { AMDGPU::FeatureR600, AMDGPU::FeatureVertexCache }, { } },
  { "SI", "Select the SI processor", { AMDGPU::FeatureSouthernIslands, AMDGPU::FeatureFastFMAF32 }, { } },
  { "barts", "Select the barts processor", { AMDGPU::FeatureNorthernIslands, AMDGPU::FeatureVertexCache, AMDGPU::FeatureCFALUBug }, { } },
  { "bonaire", "Select the bonaire processor", { AMDGPU::FeatureSeaIslands, AMDGPU::FeatureLDSBankCount32, AMDGPU::FeatureISAVersion7_0_0 }, { } },
  { "caicos", "Select the caicos processor", { AMDGPU::FeatureNorthernIslands, AMDGPU::FeatureCFALUBug }, { } },
  { "carrizo", "Select the carrizo processor", { AMDGPU::FeatureVolcanicIslands, AMDGPU::FeatureISAVersion8_0_1 }, { } },
  { "cayman", "Select the cayman processor", { AMDGPU::FeatureNorthernIslands, AMDGPU::FeatureFP64, AMDGPU::FeatureCaymanISA }, { } },
  { "cedar", "Select the cedar processor", { AMDGPU::FeatureEvergreen, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize32, AMDGPU::FeatureCFALUBug }, { } },
  { "cypress", "Select the cypress processor", { AMDGPU::FeatureEvergreen, AMDGPU::FeatureFP64, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize64 }, { } },
  { "fiji", "Select the fiji processor", { AMDGPU::FeatureVolcanicIslands, AMDGPU::FeatureISAVersion8_0_1 }, { } },
  { "hainan", "Select the hainan processor", { AMDGPU::FeatureSouthernIslands }, { } },
  { "hawaii", "Select the hawaii processor", { AMDGPU::FeatureSeaIslands, AMDGPU::FeatureFastFMAF32, AMDGPU::FeatureLDSBankCount32, AMDGPU::FeatureISAVersion7_0_1 }, { } },
  { "iceland", "Select the iceland processor", { AMDGPU::FeatureVolcanicIslands, AMDGPU::FeatureSGPRInitBug, AMDGPU::FeatureISAVersion8_0_0 }, { } },
  { "juniper", "Select the juniper processor", { AMDGPU::FeatureEvergreen, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize64 }, { } },
  { "kabini", "Select the kabini processor", { AMDGPU::FeatureSeaIslands, AMDGPU::FeatureLDSBankCount16 }, { } },
  { "kaveri", "Select the kaveri processor", { AMDGPU::FeatureSeaIslands, AMDGPU::FeatureLDSBankCount32, AMDGPU::FeatureISAVersion7_0_0 }, { } },
  { "mullins", "Select the mullins processor", { AMDGPU::FeatureSeaIslands, AMDGPU::FeatureLDSBankCount16 }, { } },
  { "oland", "Select the oland processor", { AMDGPU::FeatureSouthernIslands }, { } },
  { "pitcairn", "Select the pitcairn processor", { AMDGPU::FeatureSouthernIslands }, { } },
  { "r600", "Select the r600 processor", { AMDGPU::FeatureR600, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize64 }, { } },
  { "r630", "Select the r630 processor", { AMDGPU::FeatureR600, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize32 }, { } },
  { "redwood", "Select the redwood processor", { AMDGPU::FeatureEvergreen, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize64, AMDGPU::FeatureCFALUBug }, { } },
  { "rs880", "Select the rs880 processor", { AMDGPU::FeatureR600, AMDGPU::FeatureWavefrontSize16 }, { } },
  { "rv670", "Select the rv670 processor", { AMDGPU::FeatureR600, AMDGPU::FeatureFP64, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize64 }, { } },
  { "rv710", "Select the rv710 processor", { AMDGPU::FeatureR700, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize32 }, { } },
  { "rv730", "Select the rv730 processor", { AMDGPU::FeatureR700, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize32 }, { } },
  { "rv770", "Select the rv770 processor", { AMDGPU::FeatureR700, AMDGPU::FeatureFP64, AMDGPU::FeatureVertexCache, AMDGPU::FeatureWavefrontSize64 }, { } },
  { "stoney", "Select the stoney processor", { AMDGPU::FeatureVolcanicIslands, AMDGPU::FeatureISAVersion8_0_1 }, { } },
  { "sumo", "Select the sumo processor", { AMDGPU::FeatureEvergreen, AMDGPU::FeatureWavefrontSize64, AMDGPU::FeatureCFALUBug }, { } },
  { "tahiti", "Select the tahiti processor", { AMDGPU::FeatureSouthernIslands, AMDGPU::FeatureFastFMAF32 }, { } },
  { "tonga", "Select the tonga processor", { AMDGPU::FeatureVolcanicIslands, AMDGPU::FeatureSGPRInitBug, AMDGPU::FeatureISAVersion8_0_0 }, { } },
  { "turks", "Select the turks processor", { AMDGPU::FeatureNorthernIslands, AMDGPU::FeatureVertexCache, AMDGPU::FeatureCFALUBug }, { } },
  { "verde", "Select the verde processor", { AMDGPU::FeatureSouthernIslands }, { } }
};

#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#ifndef NDEBUG
#define DBGFIELD(x) x,
#else
#define DBGFIELD(x)
#endif

// Functional units for "R600_VLIW5_Itin"
namespace R600_VLIW5_ItinFU {
  const unsigned ALU_X = 1 << 0;
  const unsigned ALU_Y = 1 << 1;
  const unsigned ALU_Z = 1 << 2;
  const unsigned ALU_W = 1 << 3;
  const unsigned TRANS = 1 << 4;
  const unsigned ALU_NULL = 1 << 5;
}

// Functional units for "R600_VLIW4_Itin"
namespace R600_VLIW4_ItinFU {
  const unsigned ALU_X = 1 << 0;
  const unsigned ALU_Y = 1 << 1;
  const unsigned ALU_Z = 1 << 2;
  const unsigned ALU_W = 1 << 3;
  const unsigned ALU_NULL = 1 << 4;
}

extern const llvm::InstrStage AMDGPUStages[] = {
  { 0, 0, 0, llvm::InstrStage::Required }, // No itinerary
  { 1, R600_VLIW5_ItinFU::ALU_X | R600_VLIW5_ItinFU::ALU_Y | R600_VLIW5_ItinFU::ALU_Z | R600_VLIW5_ItinFU::ALU_W | R600_VLIW5_ItinFU::TRANS, -1, (llvm::InstrStage::ReservationKinds)0 }, // 1
  { 1, R600_VLIW5_ItinFU::ALU_NULL, -1, (llvm::InstrStage::ReservationKinds)0 }, // 2
  { 1, R600_VLIW5_ItinFU::ALU_X | R600_VLIW5_ItinFU::ALU_Y | R600_VLIW5_ItinFU::ALU_Z | R600_VLIW5_ItinFU::ALU_W, -1, (llvm::InstrStage::ReservationKinds)0 }, // 3
  { 1, R600_VLIW5_ItinFU::TRANS, -1, (llvm::InstrStage::ReservationKinds)0 }, // 4
  { 1, R600_VLIW5_ItinFU::ALU_X, -1, (llvm::InstrStage::ReservationKinds)0 }, // 5
  { 1, R600_VLIW4_ItinFU::ALU_X | R600_VLIW4_ItinFU::ALU_Y | R600_VLIW4_ItinFU::ALU_Z | R600_VLIW4_ItinFU::ALU_W, -1, (llvm::InstrStage::ReservationKinds)0 }, // 6
  { 1, R600_VLIW4_ItinFU::ALU_NULL, -1, (llvm::InstrStage::ReservationKinds)0 }, // 7
  { 0, 0, 0, llvm::InstrStage::Required } // End stages
};
extern const unsigned AMDGPUOperandCycles[] = {
  0, // No itinerary
  0 // End operand cycles
};
extern const unsigned AMDGPUForwardingPaths[] = {
 0, // No itinerary
 0 // End bypass tables
};

static const llvm::InstrItinerary R600_VLIW5_Itin[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 1, 2, 0, 0 }, // 1 AnyALU
  { 1, 2, 3, 0, 0 }, // 2 NullALU
  { 1, 3, 4, 0, 0 }, // 3 VecALU
  { 1, 2, 3, 0, 0 }, // 4 NullALU_WriteVMEM
  { 1, 4, 5, 0, 0 }, // 5 TransALU
  { 1, 2, 3, 0, 0 }, // 6 NullALU_WriteLDS
  { 1, 2, 3, 0, 0 }, // 7 NullALU_Write32Bit
  { 1, 5, 6, 0, 0 }, // 8 XALU
  { 1, 2, 3, 0, 0 }, // 9 NullALU_WriteSALU
  { 1, 2, 3, 0, 0 }, // 10 NullALU_WriteBarrier
  { 1, 2, 3, 0, 0 }, // 11 NullALU_WriteSMEM
  { 1, 2, 3, 0, 0 }, // 12 NullALU_Write32Bit_WriteSALU
  { 1, 2, 3, 0, 0 }, // 13 NullALU_WriteDoubleAdd
  { 1, 2, 3, 0, 0 }, // 14 NullALU_Write64Bit
  { 1, 2, 3, 0, 0 }, // 15 NullALU_WriteQuarterRate32
  { 1, 2, 3, 0, 0 }, // 16 NullALU_WriteFloatFMA
  { 1, 2, 3, 0, 0 }, // 17 NullALU_WriteDouble
  { 1, 2, 3, 0, 0 }, // 18 NullALU_WriteFloatFMA_WriteSALU
  { 1, 2, 3, 0, 0 }, // 19 NullALU_WriteDouble_WriteSALU
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary R600_VLIW4_Itin[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 6, 7, 0, 0 }, // 1 AnyALU
  { 1, 7, 8, 0, 0 }, // 2 NullALU
  { 1, 6, 7, 0, 0 }, // 3 VecALU
  { 1, 7, 8, 0, 0 }, // 4 NullALU_WriteVMEM
  { 1, 7, 8, 0, 0 }, // 5 TransALU
  { 1, 7, 8, 0, 0 }, // 6 NullALU_WriteLDS
  { 1, 7, 8, 0, 0 }, // 7 NullALU_Write32Bit
  { 0, 0, 0, 0, 0 }, // 8 XALU
  { 1, 7, 8, 0, 0 }, // 9 NullALU_WriteSALU
  { 1, 7, 8, 0, 0 }, // 10 NullALU_WriteBarrier
  { 1, 7, 8, 0, 0 }, // 11 NullALU_WriteSMEM
  { 1, 7, 8, 0, 0 }, // 12 NullALU_Write32Bit_WriteSALU
  { 1, 7, 8, 0, 0 }, // 13 NullALU_WriteDoubleAdd
  { 1, 7, 8, 0, 0 }, // 14 NullALU_Write64Bit
  { 1, 7, 8, 0, 0 }, // 15 NullALU_WriteQuarterRate32
  { 1, 7, 8, 0, 0 }, // 16 NullALU_WriteFloatFMA
  { 1, 7, 8, 0, 0 }, // 17 NullALU_WriteDouble
  { 1, 7, 8, 0, 0 }, // 18 NullALU_WriteFloatFMA_WriteSALU
  { 1, 7, 8, 0, 0 }, // 19 NullALU_WriteDouble_WriteSALU
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, Cycles}
extern const llvm::MCWriteProcResEntry AMDGPUWriteProcResTable[] = {
  { 0,  0}, // Invalid
  { 6,  1}, // #1
  { 3,  1}, // #2
  { 5,  1}, // #3
  { 4,  1}, // #4
  { 1,  1}, // #5
  { 4,  1}, // #6
  { 5,  1} // #7
}; // AMDGPUWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry AMDGPUWriteLatencyTable[] = {
  { 0,  0}, // Invalid
  {450,  0}, // #1 WriteVMEM
  {32,  0}, // #2 WriteLDS
  { 1,  0}, // #3 Write32Bit_WriteSALU_WriteFloatFMA
  {500,  0}, // #4 WriteBarrier
  {10,  0}, // #5 WriteSMEM
  { 1,  0}, // #6 Write32Bit_WriteFloatFMA
  { 1,  0}, // #7 WriteSALU
  { 2,  0}, // #8 WriteDoubleAdd_Write64Bit
  { 4,  0}, // #9 WriteQuarterRate32_WriteDouble
  { 4,  0}, // #10 WriteDouble
  { 1,  0}, // #11 WriteSALU
  { 8,  0}, // #12 WriteDoubleAdd
  {16,  0}, // #13 WriteFloatFMA_WriteDouble
  {16,  0}, // #14 WriteFloatFMA_WriteDouble
  { 1,  0} // #15 WriteSALU
}; // AMDGPUWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry AMDGPUReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // AMDGPUReadAdvanceTable

// {Name, NumMicroOps, BeginGroup, EndGroup, WriteProcResIdx,#, WriteLatencyIdx,#, ReadAdvanceIdx,#}
static const llvm::MCSchedClassDesc SIFullSpeedModelSchedClasses[] = {
  {DBGFIELD("InvalidSchedClass")  65535, 0, 0,  0, 0,  0, 0,  0, 0},
  {DBGFIELD("AnyALU")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #1
  {DBGFIELD("NullALU")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #2
  {DBGFIELD("VecALU")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #3
  {DBGFIELD("NullALU_WriteVMEM")  1, 0, 0,  1, 1,  1, 1,  0, 0}, // #4
  {DBGFIELD("TransALU")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #5
  {DBGFIELD("NullALU_WriteLDS")   1, 0, 0,  2, 1,  2, 1,  0, 0}, // #6
  {DBGFIELD("NullALU_Write32Bit") 1, 0, 0,  3, 1,  3, 1,  0, 0}, // #7
  {DBGFIELD("XALU")               0, 0, 0,  0, 0,  0, 0,  0, 0}, // #8
  {DBGFIELD("NullALU_WriteSALU")  1, 0, 0,  4, 1,  3, 1,  0, 0}, // #9
  {DBGFIELD("NullALU_WriteBarrier") 1, 0, 0,  5, 1,  4, 1,  0, 0}, // #10
  {DBGFIELD("NullALU_WriteSMEM")  1, 0, 0,  2, 1,  5, 1,  0, 0}, // #11
  {DBGFIELD("NullALU_Write32Bit_WriteSALU") 2, 0, 0,  6, 2,  6, 2,  0, 0}, // #12
  {DBGFIELD("NullALU_WriteDoubleAdd") 1, 0, 0,  3, 1,  8, 1,  0, 0}, // #13
  {DBGFIELD("NullALU_Write64Bit") 1, 0, 0,  3, 1,  8, 1,  0, 0}, // #14
  {DBGFIELD("NullALU_WriteQuarterRate32") 1, 0, 0,  3, 1,  9, 1,  0, 0}, // #15
  {DBGFIELD("NullALU_WriteFloatFMA") 1, 0, 0,  3, 1,  3, 1,  0, 0}, // #16
  {DBGFIELD("NullALU_WriteDouble") 1, 0, 0,  3, 1,  9, 1,  0, 0}, // #17
  {DBGFIELD("NullALU_WriteFloatFMA_WriteSALU") 2, 0, 0,  6, 2,  6, 2,  0, 0}, // #18
  {DBGFIELD("NullALU_WriteDouble_WriteSALU") 2, 0, 0,  6, 2, 10, 2,  0, 0} // #19
}; // SIFullSpeedModelSchedClasses

// {Name, NumMicroOps, BeginGroup, EndGroup, WriteProcResIdx,#, WriteLatencyIdx,#, ReadAdvanceIdx,#}
static const llvm::MCSchedClassDesc SIQuarterSpeedModelSchedClasses[] = {
  {DBGFIELD("InvalidSchedClass")  65535, 0, 0,  0, 0,  0, 0,  0, 0},
  {DBGFIELD("AnyALU")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #1
  {DBGFIELD("NullALU")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #2
  {DBGFIELD("VecALU")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #3
  {DBGFIELD("NullALU_WriteVMEM")  1, 0, 0,  1, 1,  1, 1,  0, 0}, // #4
  {DBGFIELD("TransALU")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #5
  {DBGFIELD("NullALU_WriteLDS")   1, 0, 0,  2, 1,  2, 1,  0, 0}, // #6
  {DBGFIELD("NullALU_Write32Bit") 1, 0, 0,  3, 1,  3, 1,  0, 0}, // #7
  {DBGFIELD("XALU")               0, 0, 0,  0, 0,  0, 0,  0, 0}, // #8
  {DBGFIELD("NullALU_WriteSALU")  1, 0, 0,  4, 1,  3, 1,  0, 0}, // #9
  {DBGFIELD("NullALU_WriteBarrier") 1, 0, 0,  5, 1,  4, 1,  0, 0}, // #10
  {DBGFIELD("NullALU_WriteSMEM")  1, 0, 0,  2, 1,  5, 1,  0, 0}, // #11
  {DBGFIELD("NullALU_Write32Bit_WriteSALU") 2, 0, 0,  6, 2,  6, 2,  0, 0}, // #12
  {DBGFIELD("NullALU_WriteDoubleAdd") 1, 0, 0,  3, 1, 12, 1,  0, 0}, // #13
  {DBGFIELD("NullALU_Write64Bit") 1, 0, 0,  3, 1,  8, 1,  0, 0}, // #14
  {DBGFIELD("NullALU_WriteQuarterRate32") 1, 0, 0,  3, 1,  9, 1,  0, 0}, // #15
  {DBGFIELD("NullALU_WriteFloatFMA") 1, 0, 0,  3, 1, 13, 1,  0, 0}, // #16
  {DBGFIELD("NullALU_WriteDouble") 1, 0, 0,  3, 1, 13, 1,  0, 0}, // #17
  {DBGFIELD("NullALU_WriteFloatFMA_WriteSALU") 2, 0, 0,  6, 2, 14, 2,  0, 0}, // #18
  {DBGFIELD("NullALU_WriteDouble_WriteSALU") 2, 0, 0,  6, 2, 14, 2,  0, 0} // #19
}; // SIQuarterSpeedModelSchedClasses

static const llvm::MCSchedModel NoSchedModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  0, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  nullptr}; // No Itinerary

static const llvm::MCSchedModel R600_VLIW5_ItinModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  1, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  R600_VLIW5_Itin};

// {Name, NumUnits, SuperIdx, IsBuffered}
static const llvm::MCProcResourceDesc SIFullSpeedModelProcResources[] = {
  {DBGFIELD("InvalidUnit")     0, 0, 0},
  {DBGFIELD("HWBranch")        1, 0, 0}, // #1
  {DBGFIELD("HWExport")        7, 0, 0}, // #2
  {DBGFIELD("HWLGKM")          31, 0, 0}, // #3
  {DBGFIELD("HWSALU")          1, 0, 0}, // #4
  {DBGFIELD("HWVALU")          1, 0, 0}, // #5
  {DBGFIELD("HWVMEM")          15, 0, 0}  // #6
};

static const llvm::MCSchedModel SIFullSpeedModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  2, // Processor ID
  SIFullSpeedModelProcResources,
  SIFullSpeedModelSchedClasses,
  7,
  20,
  nullptr}; // No Itinerary

// {Name, NumUnits, SuperIdx, IsBuffered}
static const llvm::MCProcResourceDesc SIQuarterSpeedModelProcResources[] = {
  {DBGFIELD("InvalidUnit")     0, 0, 0},
  {DBGFIELD("HWBranch")        1, 0, 0}, // #1
  {DBGFIELD("HWExport")        7, 0, 0}, // #2
  {DBGFIELD("HWLGKM")          31, 0, 0}, // #3
  {DBGFIELD("HWSALU")          1, 0, 0}, // #4
  {DBGFIELD("HWVALU")          1, 0, 0}, // #5
  {DBGFIELD("HWVMEM")          15, 0, 0}  // #6
};

static const llvm::MCSchedModel SIQuarterSpeedModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  3, // Processor ID
  SIQuarterSpeedModelProcResources,
  SIQuarterSpeedModelSchedClasses,
  7,
  20,
  nullptr}; // No Itinerary

static const llvm::MCSchedModel R600_VLIW4_ItinModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  4, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  R600_VLIW4_Itin};

// Sorted (by key) array of itineraries for CPU subtype.
extern const llvm::SubtargetInfoKV AMDGPUProcSchedKV[] = {
  { "", (const void *)&R600_VLIW5_ItinModel },
  { "SI", (const void *)&SIFullSpeedModel },
  { "barts", (const void *)&R600_VLIW5_ItinModel },
  { "bonaire", (const void *)&SIQuarterSpeedModel },
  { "caicos", (const void *)&R600_VLIW5_ItinModel },
  { "carrizo", (const void *)&SIQuarterSpeedModel },
  { "cayman", (const void *)&R600_VLIW4_ItinModel },
  { "cedar", (const void *)&R600_VLIW5_ItinModel },
  { "cypress", (const void *)&R600_VLIW5_ItinModel },
  { "fiji", (const void *)&SIQuarterSpeedModel },
  { "hainan", (const void *)&SIQuarterSpeedModel },
  { "hawaii", (const void *)&SIFullSpeedModel },
  { "iceland", (const void *)&SIQuarterSpeedModel },
  { "juniper", (const void *)&R600_VLIW5_ItinModel },
  { "kabini", (const void *)&SIQuarterSpeedModel },
  { "kaveri", (const void *)&SIQuarterSpeedModel },
  { "mullins", (const void *)&SIQuarterSpeedModel },
  { "oland", (const void *)&SIQuarterSpeedModel },
  { "pitcairn", (const void *)&SIQuarterSpeedModel },
  { "r600", (const void *)&R600_VLIW5_ItinModel },
  { "r630", (const void *)&R600_VLIW5_ItinModel },
  { "redwood", (const void *)&R600_VLIW5_ItinModel },
  { "rs880", (const void *)&R600_VLIW5_ItinModel },
  { "rv670", (const void *)&R600_VLIW5_ItinModel },
  { "rv710", (const void *)&R600_VLIW5_ItinModel },
  { "rv730", (const void *)&R600_VLIW5_ItinModel },
  { "rv770", (const void *)&R600_VLIW5_ItinModel },
  { "stoney", (const void *)&SIQuarterSpeedModel },
  { "sumo", (const void *)&R600_VLIW5_ItinModel },
  { "tahiti", (const void *)&SIFullSpeedModel },
  { "tonga", (const void *)&SIQuarterSpeedModel },
  { "turks", (const void *)&R600_VLIW5_ItinModel },
  { "verde", (const void *)&SIQuarterSpeedModel }
};
#undef DBGFIELD
static inline MCSubtargetInfo *createAMDGPUMCSubtargetInfoImpl(const Triple &TT, StringRef CPU, StringRef FS) {
  return new MCSubtargetInfo(TT, CPU, FS, AMDGPUFeatureKV, AMDGPUSubTypeKV, 
                      AMDGPUProcSchedKV, AMDGPUWriteProcResTable, AMDGPUWriteLatencyTable, AMDGPUReadAdvanceTable, 
                      AMDGPUStages, AMDGPUOperandCycles, AMDGPUForwardingPaths);
}

} // end llvm namespace
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::AMDGPUSubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  const FeatureBitset& Bits = getFeatureBits();
  if (Bits[AMDGPU::Feature64BitPtr]) Is64bit = true;
  if (Bits[AMDGPU::FeatureCFALUBug]) CFALUBug = true;
  if (Bits[AMDGPU::FeatureCIInsts]) CIInsts = true;
  if (Bits[AMDGPU::FeatureCaymanISA]) CaymanISA = true;
  if (Bits[AMDGPU::FeatureDisable]) FeatureDisable = true;
  if (Bits[AMDGPU::FeatureDumpCode]) DumpCode = true;
  if (Bits[AMDGPU::FeatureDumpCodeLower]) DumpCode = true;
  if (Bits[AMDGPU::FeatureEnableHugeScratchBuffer]) EnableHugeScratchBuffer = true;
  if (Bits[AMDGPU::FeatureEnableLoadStoreOpt]) EnableLoadStoreOpt = true;
  if (Bits[AMDGPU::FeatureEnableUnsafeDSOffsetFolding]) EnableUnsafeDSOffsetFolding = true;
  if (Bits[AMDGPU::FeatureEvergreen] && Gen < AMDGPUSubtarget::EVERGREEN) Gen = AMDGPUSubtarget::EVERGREEN;
  if (Bits[AMDGPU::FeatureFP32Denormals]) FP32Denormals = true;
  if (Bits[AMDGPU::FeatureFP64]) FP64 = true;
  if (Bits[AMDGPU::FeatureFP64Denormals]) FP64Denormals = true;
  if (Bits[AMDGPU::FeatureFastFMAF32]) FastFMAF32 = true;
  if (Bits[AMDGPU::FeatureFetchLimit8] && TexVTXClauseSize < 8) TexVTXClauseSize = 8;
  if (Bits[AMDGPU::FeatureFetchLimit16] && TexVTXClauseSize < 16) TexVTXClauseSize = 16;
  if (Bits[AMDGPU::FeatureFlatAddressSpace]) FlatAddressSpace = true;
  if (Bits[AMDGPU::FeatureGCN]) IsGCN = true;
  if (Bits[AMDGPU::FeatureGCN1Encoding]) GCN1Encoding = true;
  if (Bits[AMDGPU::FeatureGCN3Encoding]) GCN3Encoding = true;
  if (Bits[AMDGPU::FeatureIRStructurizer]) EnableIRStructurizer = false;
  if (Bits[AMDGPU::FeatureISAVersion7_0_0] && IsaVersion < ISAVersion7_0_0) IsaVersion = ISAVersion7_0_0;
  if (Bits[AMDGPU::FeatureISAVersion7_0_1] && IsaVersion < ISAVersion7_0_1) IsaVersion = ISAVersion7_0_1;
  if (Bits[AMDGPU::FeatureISAVersion8_0_0] && IsaVersion < ISAVersion8_0_0) IsaVersion = ISAVersion8_0_0;
  if (Bits[AMDGPU::FeatureISAVersion8_0_1] && IsaVersion < ISAVersion8_0_1) IsaVersion = ISAVersion8_0_1;
  if (Bits[AMDGPU::FeatureIfCvt]) EnableIfCvt = false;
  if (Bits[AMDGPU::FeatureLDSBankCount16] && LDSBankCount < 16) LDSBankCount = 16;
  if (Bits[AMDGPU::FeatureLDSBankCount32] && LDSBankCount < 32) LDSBankCount = 32;
  if (Bits[AMDGPU::FeatureLocalMemorySize0] && LocalMemorySize < 0) LocalMemorySize = 0;
  if (Bits[AMDGPU::FeatureLocalMemorySize32768] && LocalMemorySize < 32768) LocalMemorySize = 32768;
  if (Bits[AMDGPU::FeatureLocalMemorySize65536] && LocalMemorySize < 65536) LocalMemorySize = 65536;
  if (Bits[AMDGPU::FeatureNorthernIslands] && Gen < AMDGPUSubtarget::NORTHERN_ISLANDS) Gen = AMDGPUSubtarget::NORTHERN_ISLANDS;
  if (Bits[AMDGPU::FeaturePromoteAlloca]) EnablePromoteAlloca = true;
  if (Bits[AMDGPU::FeatureR600] && Gen < AMDGPUSubtarget::R600) Gen = AMDGPUSubtarget::R600;
  if (Bits[AMDGPU::FeatureR600ALUInst]) R600ALUInst = false;
  if (Bits[AMDGPU::FeatureR700] && Gen < AMDGPUSubtarget::R700) Gen = AMDGPUSubtarget::R700;
  if (Bits[AMDGPU::FeatureSGPRInitBug]) SGPRInitBug = true;
  if (Bits[AMDGPU::FeatureSeaIslands] && Gen < AMDGPUSubtarget::SEA_ISLANDS) Gen = AMDGPUSubtarget::SEA_ISLANDS;
  if (Bits[AMDGPU::FeatureSouthernIslands] && Gen < AMDGPUSubtarget::SOUTHERN_ISLANDS) Gen = AMDGPUSubtarget::SOUTHERN_ISLANDS;
  if (Bits[AMDGPU::FeatureVGPRSpilling]) EnableVGPRSpilling = true;
  if (Bits[AMDGPU::FeatureVertexCache]) HasVertexCache = true;
  if (Bits[AMDGPU::FeatureVolcanicIslands] && Gen < AMDGPUSubtarget::VOLCANIC_ISLANDS) Gen = AMDGPUSubtarget::VOLCANIC_ISLANDS;
  if (Bits[AMDGPU::FeatureWavefrontSize16] && WavefrontSize < 16) WavefrontSize = 16;
  if (Bits[AMDGPU::FeatureWavefrontSize32] && WavefrontSize < 32) WavefrontSize = 32;
  if (Bits[AMDGPU::FeatureWavefrontSize64] && WavefrontSize < 64) WavefrontSize = 64;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct AMDGPUGenSubtargetInfo : public TargetSubtargetInfo {
  explicit AMDGPUGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS);
public:
  unsigned resolveSchedClass(unsigned SchedClass,  const MachineInstr *DefMI, const TargetSchedModel *SchedModel) const override;
  DFAPacketizer *createDFAPacketizer(const InstrItineraryData *IID) const;
};
} // end llvm namespace
#endif // GET_SUBTARGETINFO_HEADER


#ifdef GET_SUBTARGETINFO_CTOR
#undef GET_SUBTARGETINFO_CTOR
#include "llvm/CodeGen/TargetSchedule.h"
namespace llvm {
extern const llvm::SubtargetFeatureKV AMDGPUFeatureKV[];
extern const llvm::SubtargetFeatureKV AMDGPUSubTypeKV[];
extern const llvm::SubtargetInfoKV AMDGPUProcSchedKV[];
extern const llvm::MCWriteProcResEntry AMDGPUWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry AMDGPUWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry AMDGPUReadAdvanceTable[];
extern const llvm::InstrStage AMDGPUStages[];
extern const unsigned AMDGPUOperandCycles[];
extern const unsigned AMDGPUForwardingPaths[];
AMDGPUGenSubtargetInfo::AMDGPUGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo(TT, CPU, FS, makeArrayRef(AMDGPUFeatureKV, 45), makeArrayRef(AMDGPUSubTypeKV, 33), 
                        AMDGPUProcSchedKV, AMDGPUWriteProcResTable, AMDGPUWriteLatencyTable, AMDGPUReadAdvanceTable, 
                        AMDGPUStages, AMDGPUOperandCycles, AMDGPUForwardingPaths) {}

unsigned AMDGPUGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // AMDGPUGenSubtargetInfo::resolveSchedClass
} // end llvm namespace
#endif // GET_SUBTARGETINFO_CTOR

