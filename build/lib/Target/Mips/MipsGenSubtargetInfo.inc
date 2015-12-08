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
namespace Mips {
enum : uint64_t {
  FeatureCnMips = 0,
  FeatureDSP = 1,
  FeatureDSPR2 = 2,
  FeatureDSPR3 = 3,
  FeatureEVA = 4,
  FeatureFP64Bit = 5,
  FeatureFPXX = 6,
  FeatureGP64Bit = 7,
  FeatureMSA = 8,
  FeatureMicroMips = 9,
  FeatureMips1 = 10,
  FeatureMips2 = 11,
  FeatureMips3 = 12,
  FeatureMips3_32 = 13,
  FeatureMips3_32r2 = 14,
  FeatureMips4 = 15,
  FeatureMips4_32 = 16,
  FeatureMips4_32r2 = 17,
  FeatureMips5 = 18,
  FeatureMips5_32r2 = 19,
  FeatureMips16 = 20,
  FeatureMips32 = 21,
  FeatureMips32r2 = 22,
  FeatureMips32r3 = 23,
  FeatureMips32r5 = 24,
  FeatureMips32r6 = 25,
  FeatureMips64 = 26,
  FeatureMips64r2 = 27,
  FeatureMips64r3 = 28,
  FeatureMips64r5 = 29,
  FeatureMips64r6 = 30,
  FeatureNaN2008 = 31,
  FeatureNoABICalls = 32,
  FeatureNoOddSPReg = 33,
  FeatureSingleFloat = 34,
  FeatureSoftFloat = 35,
  FeatureUseTCCInDIV = 36,
  FeatureVFPU = 37,
  ImplP5600 = 38
};
}
} // end llvm namespace
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV MipsFeatureKV[] = {
  { "cnmips", "Octeon cnMIPS Support", { Mips::FeatureCnMips }, { Mips::FeatureMips64r2 } },
  { "dsp", "Mips DSP ASE", { Mips::FeatureDSP }, { } },
  { "dspr2", "Mips DSP-R2 ASE", { Mips::FeatureDSPR2 }, { Mips::FeatureDSP } },
  { "dspr3", "Mips DSP-R3 ASE", { Mips::FeatureDSPR3 }, { Mips::FeatureDSP, Mips::FeatureDSPR2 } },
  { "eva", "Mips EVA ASE", { Mips::FeatureEVA }, { } },
  { "fp64", "Support 64-bit FP registers", { Mips::FeatureFP64Bit }, { } },
  { "fpxx", "Support for FPXX", { Mips::FeatureFPXX }, { } },
  { "gp64", "General Purpose Registers are 64-bit wide", { Mips::FeatureGP64Bit }, { } },
  { "micromips", "microMips mode", { Mips::FeatureMicroMips }, { } },
  { "mips1", "Mips I ISA Support [highly experimental]", { Mips::FeatureMips1 }, { } },
  { "mips16", "Mips16 mode", { Mips::FeatureMips16 }, { } },
  { "mips2", "Mips II ISA Support [highly experimental]", { Mips::FeatureMips2 }, { Mips::FeatureMips1 } },
  { "mips3", "MIPS III ISA Support [highly experimental]", { Mips::FeatureMips3 }, { Mips::FeatureMips2, Mips::FeatureMips3_32, Mips::FeatureMips3_32r2, Mips::FeatureGP64Bit, Mips::FeatureFP64Bit } },
  { "mips32", "Mips32 ISA Support", { Mips::FeatureMips32 }, { Mips::FeatureMips2, Mips::FeatureMips3_32, Mips::FeatureMips4_32 } },
  { "mips32r2", "Mips32r2 ISA Support", { Mips::FeatureMips32r2 }, { Mips::FeatureMips3_32r2, Mips::FeatureMips4_32r2, Mips::FeatureMips5_32r2, Mips::FeatureMips32 } },
  { "mips32r3", "Mips32r3 ISA Support", { Mips::FeatureMips32r3 }, { Mips::FeatureMips32r2 } },
  { "mips32r5", "Mips32r5 ISA Support", { Mips::FeatureMips32r5 }, { Mips::FeatureMips32r3 } },
  { "mips32r6", "Mips32r6 ISA Support [experimental]", { Mips::FeatureMips32r6 }, { Mips::FeatureMips32r5, Mips::FeatureFP64Bit, Mips::FeatureNaN2008 } },
  { "mips3_32", "Subset of MIPS-III that is also in MIPS32 [highly experimental]", { Mips::FeatureMips3_32 }, { } },
  { "mips3_32r2", "Subset of MIPS-III that is also in MIPS32r2 [highly experimental]", { Mips::FeatureMips3_32r2 }, { } },
  { "mips4", "MIPS IV ISA Support", { Mips::FeatureMips4 }, { Mips::FeatureMips3, Mips::FeatureMips4_32, Mips::FeatureMips4_32r2 } },
  { "mips4_32", "Subset of MIPS-IV that is also in MIPS32 [highly experimental]", { Mips::FeatureMips4_32 }, { } },
  { "mips4_32r2", "Subset of MIPS-IV that is also in MIPS32r2 [highly experimental]", { Mips::FeatureMips4_32r2 }, { } },
  { "mips5", "MIPS V ISA Support [highly experimental]", { Mips::FeatureMips5 }, { Mips::FeatureMips4, Mips::FeatureMips5_32r2 } },
  { "mips5_32r2", "Subset of MIPS-V that is also in MIPS32r2 [highly experimental]", { Mips::FeatureMips5_32r2 }, { } },
  { "mips64", "Mips64 ISA Support", { Mips::FeatureMips64 }, { Mips::FeatureMips5, Mips::FeatureMips32 } },
  { "mips64r2", "Mips64r2 ISA Support", { Mips::FeatureMips64r2 }, { Mips::FeatureMips64, Mips::FeatureMips32r2 } },
  { "mips64r3", "Mips64r3 ISA Support", { Mips::FeatureMips64r3 }, { Mips::FeatureMips64r2, Mips::FeatureMips32r3 } },
  { "mips64r5", "Mips64r5 ISA Support", { Mips::FeatureMips64r5 }, { Mips::FeatureMips64r3, Mips::FeatureMips32r5 } },
  { "mips64r6", "Mips64r6 ISA Support [experimental]", { Mips::FeatureMips64r6 }, { Mips::FeatureMips32r6, Mips::FeatureMips64r5, Mips::FeatureNaN2008 } },
  { "msa", "Mips MSA ASE", { Mips::FeatureMSA }, { } },
  { "nan2008", "IEEE 754-2008 NaN encoding", { Mips::FeatureNaN2008 }, { } },
  { "noabicalls", "Disable SVR4-style position-independent code", { Mips::FeatureNoABICalls }, { } },
  { "nooddspreg", "Disable odd numbered single-precision registers", { Mips::FeatureNoOddSPReg }, { } },
  { "p5600", "The P5600 Processor", { Mips::ImplP5600 }, { Mips::FeatureMips32r5 } },
  { "single-float", "Only supports single precision float", { Mips::FeatureSingleFloat }, { } },
  { "soft-float", "Does not support floating point instructions", { Mips::FeatureSoftFloat }, { } },
  { "use-tcc-in-div", "Force the assembler to use trapping", { Mips::FeatureUseTCCInDIV }, { } },
  { "vfpu", "Enable vector FPU instructions", { Mips::FeatureVFPU }, { } }
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV MipsSubTypeKV[] = {
  { "mips1", "Select the mips1 processor", { Mips::FeatureMips1 }, { } },
  { "mips2", "Select the mips2 processor", { Mips::FeatureMips2 }, { } },
  { "mips3", "Select the mips3 processor", { Mips::FeatureMips3 }, { } },
  { "mips32", "Select the mips32 processor", { Mips::FeatureMips32 }, { } },
  { "mips32r2", "Select the mips32r2 processor", { Mips::FeatureMips32r2 }, { } },
  { "mips32r3", "Select the mips32r3 processor", { Mips::FeatureMips32r3 }, { } },
  { "mips32r5", "Select the mips32r5 processor", { Mips::FeatureMips32r5 }, { } },
  { "mips32r6", "Select the mips32r6 processor", { Mips::FeatureMips32r6 }, { } },
  { "mips4", "Select the mips4 processor", { Mips::FeatureMips4 }, { } },
  { "mips5", "Select the mips5 processor", { Mips::FeatureMips5 }, { } },
  { "mips64", "Select the mips64 processor", { Mips::FeatureMips64 }, { } },
  { "mips64r2", "Select the mips64r2 processor", { Mips::FeatureMips64r2 }, { } },
  { "mips64r3", "Select the mips64r3 processor", { Mips::FeatureMips64r3 }, { } },
  { "mips64r5", "Select the mips64r5 processor", { Mips::FeatureMips64r5 }, { } },
  { "mips64r6", "Select the mips64r6 processor", { Mips::FeatureMips64r6 }, { } },
  { "octeon", "Select the octeon processor", { Mips::FeatureMips64r2, Mips::FeatureCnMips }, { } },
  { "p5600", "Select the p5600 processor", { Mips::ImplP5600 }, { } }
};

#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#ifndef NDEBUG
#define DBGFIELD(x) x,
#else
#define DBGFIELD(x)
#endif

// Functional units for "MipsGenericItineraries"
namespace MipsGenericItinerariesFU {
  const unsigned ALU = 1 << 0;
  const unsigned IMULDIV = 1 << 1;
}

extern const llvm::InstrStage MipsStages[] = {
  { 0, 0, 0, llvm::InstrStage::Required }, // No itinerary
  { 1, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 1
  { 2, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 2
  { 3, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 3
  { 17, MipsGenericItinerariesFU::IMULDIV, -1, (llvm::InstrStage::ReservationKinds)0 }, // 4
  { 38, MipsGenericItinerariesFU::IMULDIV, -1, (llvm::InstrStage::ReservationKinds)0 }, // 5
  { 4, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 6
  { 36, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 7
  { 23, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 8
  { 8, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 9
  { 7, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 10
  { 12, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 11
  { 54, MipsGenericItinerariesFU::ALU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 12
  { 1, MipsGenericItinerariesFU::IMULDIV, -1, (llvm::InstrStage::ReservationKinds)0 }, // 13
  { 0, 0, 0, llvm::InstrStage::Required } // End stages
};
extern const unsigned MipsOperandCycles[] = {
  0, // No itinerary
  0 // End operand cycles
};
extern const unsigned MipsForwardingPaths[] = {
 0, // No itinerary
 0 // End bypass tables
};

static const llvm::InstrItinerary MipsGenericItineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 1, 2, 0, 0 }, // 1 II_ABS
  { 1, 1, 2, 0, 0 }, // 2 II_ADDU
  { 1, 1, 2, 0, 0 }, // 3 II_ADDIU
  { 0, 0, 0, 0, 0 }, // 4 IIPseudo
  { 1, 1, 2, 0, 0 }, // 5 II_AND
  { 1, 1, 2, 0, 0 }, // 6 II_ANDI
  { 1, 1, 2, 0, 0 }, // 7 IIM16Alu
  { 1, 1, 2, 0, 0 }, // 8 II_B
  { 1, 1, 2, 0, 0 }, // 9 II_BADDU
  { 1, 1, 2, 0, 0 }, // 10 II_BCCZAL
  { 1, 1, 2, 0, 0 }, // 11 II_BBIT
  { 1, 1, 2, 0, 0 }, // 12 II_BC
  { 1, 1, 2, 0, 0 }, // 13 II_BC1F
  { 1, 1, 2, 0, 0 }, // 14 II_BC1FL
  { 1, 1, 2, 0, 0 }, // 15 II_BC1T
  { 1, 1, 2, 0, 0 }, // 16 II_BC1TL
  { 1, 1, 2, 0, 0 }, // 17 II_BCC
  { 1, 1, 2, 0, 0 }, // 18 II_BCCZ
  { 1, 1, 2, 0, 0 }, // 19 II_BCCZC
  { 1, 1, 2, 0, 0 }, // 20 II_BCCZALS
  { 1, 1, 2, 0, 0 }, // 21 II_CEIL
  { 1, 2, 3, 0, 0 }, // 22 II_CFC1
  { 1, 1, 2, 0, 0 }, // 23 II_CLO
  { 1, 1, 2, 0, 0 }, // 24 II_CLZ
  { 1, 2, 3, 0, 0 }, // 25 II_CTC1
  { 1, 1, 2, 0, 0 }, // 26 II_CVT
  { 1, 3, 4, 0, 0 }, // 27 II_C_CC_D
  { 1, 3, 4, 0, 0 }, // 28 II_C_CC_S
  { 1, 1, 2, 0, 0 }, // 29 II_DADD
  { 1, 1, 2, 0, 0 }, // 30 II_DADDIU
  { 1, 1, 2, 0, 0 }, // 31 II_DADDU
  { 1, 1, 2, 0, 0 }, // 32 II_EXT
  { 1, 1, 2, 0, 0 }, // 33 II_INS
  { 1, 2, 3, 0, 0 }, // 34 II_DMFC1
  { 1, 2, 3, 0, 0 }, // 35 II_DMTC1
  { 1, 4, 5, 0, 0 }, // 36 II_DMUL
  { 1, 4, 5, 0, 0 }, // 37 II_DMULT
  { 1, 4, 5, 0, 0 }, // 38 II_DMULTU
  { 1, 1, 2, 0, 0 }, // 39 II_POP
  { 1, 1, 2, 0, 0 }, // 40 II_DROTR
  { 0, 0, 0, 0, 0 }, // 41 II_DROTR32
  { 1, 1, 2, 0, 0 }, // 42 II_DROTRV
  { 1, 5, 6, 0, 0 }, // 43 II_DDIV
  { 1, 1, 2, 0, 0 }, // 44 II_DSLL
  { 0, 0, 0, 0, 0 }, // 45 II_DSLL32
  { 1, 1, 2, 0, 0 }, // 46 II_DSLLV
  { 1, 1, 2, 0, 0 }, // 47 II_DSRA
  { 0, 0, 0, 0, 0 }, // 48 II_DSRA32
  { 1, 1, 2, 0, 0 }, // 49 II_DSRAV
  { 1, 1, 2, 0, 0 }, // 50 II_DSRL
  { 0, 0, 0, 0, 0 }, // 51 II_DSRL32
  { 1, 1, 2, 0, 0 }, // 52 II_DSRLV
  { 1, 1, 2, 0, 0 }, // 53 II_DSUB
  { 1, 1, 2, 0, 0 }, // 54 II_DSUBU
  { 1, 5, 6, 0, 0 }, // 55 II_DDIVU
  { 1, 6, 7, 0, 0 }, // 56 II_ADD_D
  { 1, 6, 7, 0, 0 }, // 57 II_ADD_S
  { 1, 7, 8, 0, 0 }, // 58 II_DIV_D
  { 1, 8, 9, 0, 0 }, // 59 II_DIV_S
  { 1, 1, 2, 0, 0 }, // 60 II_FLOOR
  { 1, 2, 3, 0, 0 }, // 61 II_MOV_D
  { 1, 2, 3, 0, 0 }, // 62 II_MOV_S
  { 1, 9, 10, 0, 0 }, // 63 II_MUL_D
  { 1, 10, 11, 0, 0 }, // 64 II_MUL_S
  { 1, 1, 2, 0, 0 }, // 65 II_NEG
  { 1, 11, 12, 0, 0 }, // 66 II_SQRT_D
  { 1, 12, 13, 0, 0 }, // 67 II_SQRT_S
  { 1, 6, 7, 0, 0 }, // 68 II_SUB_D
  { 1, 6, 7, 0, 0 }, // 69 II_SUB_S
  { 1, 1, 2, 0, 0 }, // 70 II_J
  { 1, 1, 2, 0, 0 }, // 71 II_JAL
  { 1, 1, 2, 0, 0 }, // 72 II_JALR
  { 1, 1, 2, 0, 0 }, // 73 II_JALRS
  { 1, 1, 2, 0, 0 }, // 74 II_JALS
  { 1, 1, 2, 0, 0 }, // 75 II_JR
  { 1, 1, 2, 0, 0 }, // 76 II_JRADDIUSP
  { 1, 1, 2, 0, 0 }, // 77 II_JRC
  { 1, 1, 2, 0, 0 }, // 78 II_JALRC
  { 1, 3, 4, 0, 0 }, // 79 II_LB
  { 1, 3, 4, 0, 0 }, // 80 II_LBU
  { 1, 3, 4, 0, 0 }, // 81 II_LD
  { 1, 3, 4, 0, 0 }, // 82 II_LDC1
  { 1, 3, 4, 0, 0 }, // 83 II_LDL
  { 1, 3, 4, 0, 0 }, // 84 II_LDR
  { 1, 3, 4, 0, 0 }, // 85 II_LDXC1
  { 1, 3, 4, 0, 0 }, // 86 II_LH
  { 1, 3, 4, 0, 0 }, // 87 II_LHU
  { 1, 1, 2, 0, 0 }, // 88 II_LUI
  { 1, 3, 4, 0, 0 }, // 89 II_LUXC1
  { 1, 3, 4, 0, 0 }, // 90 II_LW
  { 1, 3, 4, 0, 0 }, // 91 II_LWC1
  { 1, 3, 4, 0, 0 }, // 92 II_LWL
  { 1, 3, 4, 0, 0 }, // 93 II_LWR
  { 0, 0, 0, 0, 0 }, // 94 II_LWU
  { 1, 3, 4, 0, 0 }, // 95 II_LWXC1
  { 1, 4, 5, 0, 0 }, // 96 II_MADD
  { 1, 4, 5, 0, 0 }, // 97 II_MADDU
  { 1, 9, 10, 0, 0 }, // 98 II_MADD_D
  { 1, 10, 11, 0, 0 }, // 99 II_MADD_S
  { 1, 2, 3, 0, 0 }, // 100 II_MFC1
  { 1, 2, 3, 0, 0 }, // 101 II_MFHC1
  { 1, 13, 14, 0, 0 }, // 102 II_MFHI_MFLO
  { 1, 2, 3, 0, 0 }, // 103 II_MOVF_D
  { 1, 1, 2, 0, 0 }, // 104 II_MOVF
  { 1, 2, 3, 0, 0 }, // 105 II_MOVF_S
  { 1, 1, 2, 0, 0 }, // 106 II_MOVN_D
  { 1, 1, 2, 0, 0 }, // 107 II_MOVN
  { 1, 1, 2, 0, 0 }, // 108 II_MOVN_S
  { 1, 2, 3, 0, 0 }, // 109 II_MOVT_D
  { 1, 1, 2, 0, 0 }, // 110 II_MOVT
  { 1, 2, 3, 0, 0 }, // 111 II_MOVT_S
  { 1, 2, 3, 0, 0 }, // 112 II_MOVZ_D
  { 1, 1, 2, 0, 0 }, // 113 II_MOVZ
  { 1, 2, 3, 0, 0 }, // 114 II_MOVZ_S
  { 1, 4, 5, 0, 0 }, // 115 II_MSUB
  { 1, 4, 5, 0, 0 }, // 116 II_MSUBU
  { 1, 9, 10, 0, 0 }, // 117 II_MSUB_D
  { 1, 10, 11, 0, 0 }, // 118 II_MSUB_S
  { 1, 2, 3, 0, 0 }, // 119 II_MTC1
  { 1, 2, 3, 0, 0 }, // 120 II_MTHC1
  { 1, 13, 14, 0, 0 }, // 121 II_MTHI_MTLO
  { 1, 4, 5, 0, 0 }, // 122 II_MUL
  { 1, 4, 5, 0, 0 }, // 123 II_MULT
  { 1, 4, 5, 0, 0 }, // 124 II_MULTU
  { 1, 9, 10, 0, 0 }, // 125 II_NMADD_D
  { 1, 10, 11, 0, 0 }, // 126 II_NMADD_S
  { 1, 9, 10, 0, 0 }, // 127 II_NMSUB_D
  { 1, 10, 11, 0, 0 }, // 128 II_NMSUB_S
  { 1, 1, 2, 0, 0 }, // 129 II_NOR
  { 1, 1, 2, 0, 0 }, // 130 II_OR
  { 1, 1, 2, 0, 0 }, // 131 II_ORI
  { 1, 1, 2, 0, 0 }, // 132 II_IndirectBranchPseudo
  { 1, 1, 2, 0, 0 }, // 133 II_ReturnPseudo
  { 1, 5, 6, 0, 0 }, // 134 II_DIV
  { 1, 5, 6, 0, 0 }, // 135 II_DIVU
  { 1, 1, 2, 0, 0 }, // 136 II_RDHWR
  { 1, 1, 2, 0, 0 }, // 137 II_ROUND
  { 1, 1, 2, 0, 0 }, // 138 II_ROTR
  { 1, 1, 2, 0, 0 }, // 139 II_ROTRV
  { 1, 1, 2, 0, 0 }, // 140 II_TRUNC
  { 1, 3, 4, 0, 0 }, // 141 II_RESTORE
  { 1, 1, 2, 0, 0 }, // 142 II_SB
  { 1, 1, 2, 0, 0 }, // 143 II_SD
  { 1, 1, 2, 0, 0 }, // 144 II_SDC1
  { 1, 1, 2, 0, 0 }, // 145 II_SDL
  { 1, 1, 2, 0, 0 }, // 146 II_SDR
  { 1, 1, 2, 0, 0 }, // 147 II_SDXC1
  { 0, 0, 0, 0, 0 }, // 148 II_SEB
  { 0, 0, 0, 0, 0 }, // 149 II_SEH
  { 1, 1, 2, 0, 0 }, // 150 II_SEQ_SNE
  { 1, 1, 2, 0, 0 }, // 151 II_SEQI_SNEI
  { 1, 1, 2, 0, 0 }, // 152 II_SH
  { 1, 1, 2, 0, 0 }, // 153 II_SLL
  { 1, 1, 2, 0, 0 }, // 154 II_SLLV
  { 0, 0, 0, 0, 0 }, // 155 II_SLT_SLTU
  { 0, 0, 0, 0, 0 }, // 156 II_SLTI_SLTIU
  { 1, 1, 2, 0, 0 }, // 157 II_SRA
  { 1, 1, 2, 0, 0 }, // 158 II_SRAV
  { 1, 1, 2, 0, 0 }, // 159 II_SRL
  { 1, 1, 2, 0, 0 }, // 160 II_SRLV
  { 1, 1, 2, 0, 0 }, // 161 II_SUBU
  { 1, 1, 2, 0, 0 }, // 162 II_SUXC1
  { 1, 1, 2, 0, 0 }, // 163 II_SW
  { 1, 1, 2, 0, 0 }, // 164 II_SWC1
  { 1, 1, 2, 0, 0 }, // 165 II_SWL
  { 1, 1, 2, 0, 0 }, // 166 II_SWR
  { 1, 1, 2, 0, 0 }, // 167 II_SWXC1
  { 1, 1, 2, 0, 0 }, // 168 II_SAVE
  { 0, 0, 0, 0, 0 }, // 169 II_WSBH
  { 1, 1, 2, 0, 0 }, // 170 II_XOR
  { 1, 1, 2, 0, 0 }, // 171 II_XORI
  { 0, 0, 0, 0, 0 }, // 172 ADD_A_B_ADD_A_D_ADD_A_H_ADD_A_W
  { 0, 0, 0, 0, 0 }, // 173 ADDS_A_B_ADDS_A_D_ADDS_A_H_ADDS_A_W_ADDS_S_B_ADDS_S_D_ADDS_S_H_ADDS_S_W_ADDS_U_B_ADDS_U_D_ADDS_U_H_ADDS_U_W
  { 0, 0, 0, 0, 0 }, // 174 ADDVI_B_ADDVI_D_ADDVI_H_ADDVI_W_ADDV_B_ADDV_D_ADDV_H_ADDV_W
  { 0, 0, 0, 0, 0 }, // 175 ASUB_S_B_ASUB_S_D_ASUB_S_H_ASUB_S_W_ASUB_U_B_ASUB_U_D_ASUB_U_H_ASUB_U_W
  { 0, 0, 0, 0, 0 }, // 176 AVER_S_B_AVER_S_D_AVER_S_H_AVER_S_W_AVER_U_B_AVER_U_D_AVER_U_H_AVER_U_W_AVE_S_B_AVE_S_D_AVE_S_H_AVE_S_W_AVE_U_B_AVE_U_D_AVE_U_H_AVE_U_W
  { 0, 0, 0, 0, 0 }, // 177 MOVE_V
  { 0, 0, 0, 0, 0 }, // 178 LDI_B_LDI_D_LDI_H_LDI_W
  { 0, 0, 0, 0, 0 }, // 179 AND_V_NOR_V_OR_V_XOR_V
  { 0, 0, 0, 0, 0 }, // 180 ANDI_B_NORI_B_ORI_B_XORI_B
  { 0, 0, 0, 0, 0 }, // 181 ST_B_ST_D_ST_H_ST_W
  { 0, 0, 0, 0, 0 }, // 182 LD_B_LD_D_LD_H_LD_W
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, Cycles}
extern const llvm::MCWriteProcResEntry MipsWriteProcResTable[] = {
  { 0,  0}, // Invalid
  { 5,  1}, // #1
  {12,  1}, // #2
  { 3,  1}, // #3
  { 8,  1}, // #4
  { 1,  1}, // #5
  { 4,  1}, // #6
  { 9,  1}, // #7
  { 1,  1}, // #8
  { 5,  1}, // #9
  {12,  1}, // #10
  {13,  1}, // #11
  { 5,  1}, // #12
  {10,  1}, // #13
  { 1,  1}, // #14
  { 7,  1}, // #15
  { 5,  1}, // #16
  { 6, 31}, // #17
  {10,  1}, // #18
  { 5,  1}, // #19
  { 6, 23}, // #20
  {10,  1}, // #21
  { 5,  1}, // #22
  { 6, 35}, // #23
  {10,  1}, // #24
  { 5,  1}, // #25
  { 6, 27}, // #26
  {10,  1}, // #27
  { 1,  1}, // #28
  {13,  1}, // #29
  { 1,  1}, // #30
  { 5,  1}, // #31
  {11,  1}, // #32
  {13,  1}, // #33
  { 1,  1}, // #34
  { 4,  1}, // #35
  {13,  1}, // #36
  { 1,  1}, // #37
  { 4,  1}, // #38
  { 7,  1}, // #39
  { 1,  1}, // #40
  { 5,  1}, // #41
  {10,  1}, // #42
  {13,  1}, // #43
  { 1,  1}, // #44
  { 2, 34}, // #45
  { 7,  1}, // #46
  { 1,  1}, // #47
  { 4,  3}, // #48
  {13,  1} // #49
}; // MipsWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry MipsWriteLatencyTable[] = {
  { 0,  0}, // Invalid
  { 1,  0}, // #1 P5600WriteFPUS_P5600WriteALU_P5600WriteJump_P5600WriteAL2_P5600WriteMoveOtherUnitsToFPU_P5600WriteStore_P5600WriteStoreFromOtherUnits_P5600WriteMSAShortLogic
  { 2,  0}, // #2 P5600WriteGPRFromBypass_P5600WriteAL2BitExt_P5600WriteJumpAndLink_P5600WriteStoreFromOtherUnits_P5600WriteAL2CondMov_P5600WriteAL2ShadowMov_P5600WriteMSAShortInt
  { 4,  0}, // #3 P5600WriteFPUL_P5600WriteLoad_P5600WriteLoadOtherUnitsToFPU_P5600WriteLoadShifted
  {31,  0}, // #4 P5600WriteFPUDivD
  {23,  0}, // #5 P5600WriteFPUDivS
  {35,  0}, // #6 P5600WriteFPUSqrtD
  {27,  0}, // #7 P5600WriteFPUSqrtS
  { 5,  0}, // #8 P5600WriteAL2MAdd_P5600WriteAL2Mult
  { 6,  0}, // #9 P5600WriteFPUL_MADDSUB
  { 3,  0}, // #10 P5600WriteAL2Mul
  {34,  0} // #11 P5600WriteAL2Div_P5600WriteAL2DivU
}; // MipsWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry MipsReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
  {0,  0,  5} // #1
}; // MipsReadAdvanceTable

// {Name, NumMicroOps, BeginGroup, EndGroup, WriteProcResIdx,#, WriteLatencyIdx,#, ReadAdvanceIdx,#}
static const llvm::MCSchedClassDesc MipsP5600ModelSchedClasses[] = {
  {DBGFIELD("InvalidSchedClass")  65535, 0, 0,  0, 0,  0, 0,  0, 0},
  {DBGFIELD("II_ABS")             1, 0, 0,  1, 2,  1, 1,  0, 0}, // #1
  {DBGFIELD("II_ADDU")            65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #2
  {DBGFIELD("II_ADDIU")           65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #3
  {DBGFIELD("IIPseudo")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #4
  {DBGFIELD("II_AND")             1, 0, 0,  3, 2,  1, 1,  0, 0}, // #5
  {DBGFIELD("II_ANDI")            65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #6
  {DBGFIELD("IIM16Alu")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #7
  {DBGFIELD("II_B")               1, 0, 0,  5, 3,  1, 1,  0, 0}, // #8
  {DBGFIELD("II_BADDU")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #9
  {DBGFIELD("II_BCCZAL")          1, 0, 0,  5, 3,  1, 1,  0, 0}, // #10
  {DBGFIELD("II_BBIT")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #11
  {DBGFIELD("II_BC")              0, 0, 0,  0, 0,  0, 0,  0, 0}, // #12
  {DBGFIELD("II_BC1F")            2, 0, 0,  8, 4,  2, 1,  0, 0}, // #13
  {DBGFIELD("II_BC1FL")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #14
  {DBGFIELD("II_BC1T")            2, 0, 0,  8, 4,  2, 1,  0, 0}, // #15
  {DBGFIELD("II_BC1TL")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #16
  {DBGFIELD("II_BCC")             1, 0, 0,  5, 3,  1, 1,  0, 0}, // #17
  {DBGFIELD("II_BCCZ")            1, 0, 0,  5, 3,  1, 1,  0, 0}, // #18
  {DBGFIELD("II_BCCZC")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #19
  {DBGFIELD("II_BCCZALS")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #20
  {DBGFIELD("II_CEIL")            1, 0, 0, 12, 2,  3, 1,  0, 0}, // #21
  {DBGFIELD("II_CFC1")            2, 0, 0,  8, 4,  2, 1,  0, 0}, // #22
  {DBGFIELD("II_CLO")             1, 0, 0, 14, 2,  1, 1,  0, 0}, // #23
  {DBGFIELD("II_CLZ")             1, 0, 0, 14, 2,  1, 1,  0, 0}, // #24
  {DBGFIELD("II_CTC1")            2, 0, 0,  8, 4,  1, 1,  0, 0}, // #25
  {DBGFIELD("II_CVT")             1, 0, 0, 12, 2,  3, 1,  0, 0}, // #26
  {DBGFIELD("II_C_CC_D")          1, 0, 0, 12, 2,  3, 1,  0, 0}, // #27
  {DBGFIELD("II_C_CC_S")          1, 0, 0, 12, 2,  3, 1,  0, 0}, // #28
  {DBGFIELD("II_DADD")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #29
  {DBGFIELD("II_DADDIU")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #30
  {DBGFIELD("II_DADDU")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #31
  {DBGFIELD("II_EXT")             1, 0, 0, 14, 2,  2, 1,  0, 0}, // #32
  {DBGFIELD("II_INS")             1, 0, 0, 14, 2,  2, 1,  0, 0}, // #33
  {DBGFIELD("II_DMFC1")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #34
  {DBGFIELD("II_DMTC1")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #35
  {DBGFIELD("II_DMUL")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #36
  {DBGFIELD("II_DMULT")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #37
  {DBGFIELD("II_DMULTU")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #38
  {DBGFIELD("II_POP")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #39
  {DBGFIELD("II_DROTR")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #40
  {DBGFIELD("II_DROTR32")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #41
  {DBGFIELD("II_DROTRV")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #42
  {DBGFIELD("II_DDIV")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #43
  {DBGFIELD("II_DSLL")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #44
  {DBGFIELD("II_DSLL32")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #45
  {DBGFIELD("II_DSLLV")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #46
  {DBGFIELD("II_DSRA")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #47
  {DBGFIELD("II_DSRA32")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #48
  {DBGFIELD("II_DSRAV")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #49
  {DBGFIELD("II_DSRL")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #50
  {DBGFIELD("II_DSRL32")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #51
  {DBGFIELD("II_DSRLV")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #52
  {DBGFIELD("II_DSUB")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #53
  {DBGFIELD("II_DSUBU")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #54
  {DBGFIELD("II_DDIVU")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #55
  {DBGFIELD("II_ADD_D")           1, 0, 0, 12, 2,  3, 1,  0, 0}, // #56
  {DBGFIELD("II_ADD_S")           1, 0, 0, 12, 2,  3, 1,  0, 0}, // #57
  {DBGFIELD("II_DIV_D")           1, 0, 0, 16, 3,  4, 1,  0, 0}, // #58
  {DBGFIELD("II_DIV_S")           1, 0, 0, 19, 3,  5, 1,  0, 0}, // #59
  {DBGFIELD("II_FLOOR")           1, 0, 0, 12, 2,  3, 1,  0, 0}, // #60
  {DBGFIELD("II_MOV_D")           1, 0, 0,  1, 2,  1, 1,  0, 0}, // #61
  {DBGFIELD("II_MOV_S")           1, 0, 0,  1, 2,  1, 1,  0, 0}, // #62
  {DBGFIELD("II_MUL_D")           1, 0, 0, 12, 2,  3, 1,  0, 0}, // #63
  {DBGFIELD("II_MUL_S")           1, 0, 0, 12, 2,  3, 1,  0, 0}, // #64
  {DBGFIELD("II_NEG")             1, 0, 0,  1, 2,  1, 1,  0, 0}, // #65
  {DBGFIELD("II_SQRT_D")          1, 0, 0, 22, 3,  6, 1,  0, 0}, // #66
  {DBGFIELD("II_SQRT_S")          1, 0, 0, 25, 3,  7, 1,  0, 0}, // #67
  {DBGFIELD("II_SUB_D")           1, 0, 0, 12, 2,  3, 1,  0, 0}, // #68
  {DBGFIELD("II_SUB_S")           1, 0, 0, 12, 2,  3, 1,  0, 0}, // #69
  {DBGFIELD("II_J")               1, 0, 0,  5, 3,  1, 1,  0, 0}, // #70
  {DBGFIELD("II_JAL")             1, 0, 0,  5, 3,  2, 1,  0, 0}, // #71
  {DBGFIELD("II_JALR")            1, 0, 0,  5, 3,  2, 1,  0, 0}, // #72
  {DBGFIELD("II_JALRS")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #73
  {DBGFIELD("II_JALS")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #74
  {DBGFIELD("II_JR")              1, 0, 0,  5, 3,  1, 1,  0, 0}, // #75
  {DBGFIELD("II_JRADDIUSP")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #76
  {DBGFIELD("II_JRC")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #77
  {DBGFIELD("II_JALRC")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #78
  {DBGFIELD("II_LB")              1, 0, 0, 28, 2,  3, 1,  0, 0}, // #79
  {DBGFIELD("II_LBU")             1, 0, 0, 28, 2,  3, 1,  0, 0}, // #80
  {DBGFIELD("II_LD")              0, 0, 0,  0, 0,  0, 0,  0, 0}, // #81
  {DBGFIELD("II_LDC1")            2, 0, 0, 30, 4,  3, 1,  0, 0}, // #82
  {DBGFIELD("II_LDL")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #83
  {DBGFIELD("II_LDR")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #84
  {DBGFIELD("II_LDXC1")           2, 0, 0, 30, 4,  3, 1,  0, 0}, // #85
  {DBGFIELD("II_LH")              1, 0, 0, 28, 2,  3, 1,  0, 0}, // #86
  {DBGFIELD("II_LHU")             1, 0, 0, 28, 2,  3, 1,  0, 0}, // #87
  {DBGFIELD("II_LUI")             1, 0, 0,  3, 2,  1, 1,  0, 0}, // #88
  {DBGFIELD("II_LUXC1")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #89
  {DBGFIELD("II_LW")              1, 0, 0, 28, 2,  3, 1,  0, 0}, // #90
  {DBGFIELD("II_LWC1")            2, 0, 0, 30, 4,  3, 1,  0, 0}, // #91
  {DBGFIELD("II_LWL")             1, 0, 0, 34, 3,  3, 1,  0, 0}, // #92
  {DBGFIELD("II_LWR")             1, 0, 0, 34, 3,  3, 1,  0, 0}, // #93
  {DBGFIELD("II_LWU")             1, 0, 0, 28, 2,  3, 1,  0, 0}, // #94
  {DBGFIELD("II_LWXC1")           2, 0, 0, 30, 4,  3, 1,  0, 0}, // #95
  {DBGFIELD("II_MADD")            1, 0, 0, 37, 3,  8, 1,  0, 0}, // #96
  {DBGFIELD("II_MADDU")           1, 0, 0, 37, 3,  8, 1,  0, 0}, // #97
  {DBGFIELD("II_MADD_D")          1, 0, 0, 12, 2,  9, 1,  1, 1}, // #98
  {DBGFIELD("II_MADD_S")          1, 0, 0, 12, 2,  9, 1,  1, 1}, // #99
  {DBGFIELD("II_MFC1")            2, 0, 0,  8, 4,  2, 1,  0, 0}, // #100
  {DBGFIELD("II_MFHC1")           2, 0, 0,  8, 4,  2, 1,  0, 0}, // #101
  {DBGFIELD("II_MFHI_MFLO")       1, 0, 0, 14, 2,  1, 1,  0, 0}, // #102
  {DBGFIELD("II_MOVF_D")          1, 0, 0,  1, 2,  1, 1,  0, 0}, // #103
  {DBGFIELD("II_MOVF")            2, 0, 0,  8, 4,  2, 1,  0, 0}, // #104
  {DBGFIELD("II_MOVF_S")          1, 0, 0,  1, 2,  1, 1,  0, 0}, // #105
  {DBGFIELD("II_MOVN_D")          2, 0, 0, 40, 4,  2, 1,  0, 0}, // #106
  {DBGFIELD("II_MOVN")            1, 0, 0, 37, 3,  2, 1,  0, 0}, // #107
  {DBGFIELD("II_MOVN_S")          2, 0, 0, 40, 4,  2, 1,  0, 0}, // #108
  {DBGFIELD("II_MOVT_D")          1, 0, 0,  1, 2,  1, 1,  0, 0}, // #109
  {DBGFIELD("II_MOVT")            2, 0, 0,  8, 4,  2, 1,  0, 0}, // #110
  {DBGFIELD("II_MOVT_S")          1, 0, 0,  1, 2,  1, 1,  0, 0}, // #111
  {DBGFIELD("II_MOVZ_D")          2, 0, 0, 40, 4,  2, 1,  0, 0}, // #112
  {DBGFIELD("II_MOVZ")            1, 0, 0, 37, 3,  2, 1,  0, 0}, // #113
  {DBGFIELD("II_MOVZ_S")          2, 0, 0, 40, 4,  2, 1,  0, 0}, // #114
  {DBGFIELD("II_MSUB")            1, 0, 0, 37, 3,  8, 1,  0, 0}, // #115
  {DBGFIELD("II_MSUBU")           1, 0, 0, 37, 3,  8, 1,  0, 0}, // #116
  {DBGFIELD("II_MSUB_D")          1, 0, 0, 12, 2,  9, 1,  1, 1}, // #117
  {DBGFIELD("II_MSUB_S")          1, 0, 0, 12, 2,  9, 1,  1, 1}, // #118
  {DBGFIELD("II_MTC1")            2, 0, 0,  8, 4,  1, 1,  0, 0}, // #119
  {DBGFIELD("II_MTHC1")           2, 0, 0,  8, 4,  1, 1,  0, 0}, // #120
  {DBGFIELD("II_MTHI_MTLO")       1, 0, 0, 37, 3,  8, 1,  0, 0}, // #121
  {DBGFIELD("II_MUL")             1, 0, 0, 14, 2, 10, 1,  0, 0}, // #122
  {DBGFIELD("II_MULT")            1, 0, 0, 14, 2,  8, 1,  0, 0}, // #123
  {DBGFIELD("II_MULTU")           1, 0, 0, 14, 2,  8, 1,  0, 0}, // #124
  {DBGFIELD("II_NMADD_D")         1, 0, 0, 12, 2,  9, 1,  1, 1}, // #125
  {DBGFIELD("II_NMADD_S")         1, 0, 0, 12, 2,  9, 1,  1, 1}, // #126
  {DBGFIELD("II_NMSUB_D")         1, 0, 0, 12, 2,  9, 1,  1, 1}, // #127
  {DBGFIELD("II_NMSUB_S")         1, 0, 0, 12, 2,  9, 1,  1, 1}, // #128
  {DBGFIELD("II_NOR")             1, 0, 0,  3, 2,  1, 1,  0, 0}, // #129
  {DBGFIELD("II_OR")              1, 0, 0,  3, 2,  1, 1,  0, 0}, // #130
  {DBGFIELD("II_ORI")             65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #131
  {DBGFIELD("II_IndirectBranchPseudo") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #132
  {DBGFIELD("II_ReturnPseudo")    0, 0, 0,  0, 0,  0, 0,  0, 0}, // #133
  {DBGFIELD("II_DIV")             1, 0, 0, 44, 3, 11, 1,  0, 0}, // #134
  {DBGFIELD("II_DIVU")            1, 0, 0, 44, 3, 11, 1,  0, 0}, // #135
  {DBGFIELD("II_RDHWR")           1, 0, 0, 14, 2,  2, 1,  0, 0}, // #136
  {DBGFIELD("II_ROUND")           1, 0, 0, 12, 2,  3, 1,  0, 0}, // #137
  {DBGFIELD("II_ROTR")            65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #138
  {DBGFIELD("II_ROTRV")           65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #139
  {DBGFIELD("II_TRUNC")           1, 0, 0, 12, 2,  3, 1,  0, 0}, // #140
  {DBGFIELD("II_RESTORE")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #141
  {DBGFIELD("II_SB")              1, 0, 0, 47, 3,  1, 1,  0, 0}, // #142
  {DBGFIELD("II_SD")              0, 0, 0,  0, 0,  0, 0,  0, 0}, // #143
  {DBGFIELD("II_SDC1")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #144
  {DBGFIELD("II_SDL")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #145
  {DBGFIELD("II_SDR")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #146
  {DBGFIELD("II_SDXC1")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #147
  {DBGFIELD("II_SEB")             65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #148
  {DBGFIELD("II_SEH")             65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #149
  {DBGFIELD("II_SEQ_SNE")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #150
  {DBGFIELD("II_SEQI_SNEI")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #151
  {DBGFIELD("II_SH")              1, 0, 0, 47, 3,  1, 1,  0, 0}, // #152
  {DBGFIELD("II_SLL")             65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #153
  {DBGFIELD("II_SLLV")            65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #154
  {DBGFIELD("II_SLT_SLTU")        65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #155
  {DBGFIELD("II_SLTI_SLTIU")      1, 0, 0,  3, 2,  1, 1,  0, 0}, // #156
  {DBGFIELD("II_SRA")             65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #157
  {DBGFIELD("II_SRAV")            65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #158
  {DBGFIELD("II_SRL")             65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #159
  {DBGFIELD("II_SRLV")            65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #160
  {DBGFIELD("II_SUBU")            1, 0, 0,  3, 2,  1, 1,  0, 0}, // #161
  {DBGFIELD("II_SUXC1")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #162
  {DBGFIELD("II_SW")              1, 0, 0, 47, 3,  1, 1,  0, 0}, // #163
  {DBGFIELD("II_SWC1")            2, 0, 0,  8, 4,  1, 1,  0, 0}, // #164
  {DBGFIELD("II_SWL")             1, 0, 0, 47, 3,  1, 1,  0, 0}, // #165
  {DBGFIELD("II_SWR")             1, 0, 0, 47, 3,  1, 1,  0, 0}, // #166
  {DBGFIELD("II_SWXC1")           2, 0, 0,  8, 4,  1, 1,  0, 0}, // #167
  {DBGFIELD("II_SAVE")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #168
  {DBGFIELD("II_WSBH")            0, 0, 0,  0, 0,  0, 0,  0, 0}, // #169
  {DBGFIELD("II_XOR")             1, 0, 0,  3, 2,  1, 1,  0, 0}, // #170
  {DBGFIELD("II_XORI")            65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #171
  {DBGFIELD("ADD_A_B_ADD_A_D_ADD_A_H_ADD_A_W") 1, 0, 0,  1, 2,  2, 1,  0, 0}, // #172
  {DBGFIELD("ADDS_A_B_ADDS_A_D_ADDS_A_H_ADDS_A_W_ADDS_S_B_ADDS_S_D_ADDS_S_H_ADDS_S_W_ADDS_U_B_ADDS_U_D_ADDS_U_H_ADDS_U_W") 1, 0, 0,  1, 2,  2, 1,  0, 0}, // #173
  {DBGFIELD("ADDVI_B_ADDVI_D_ADDVI_H_ADDVI_W_ADDV_B_ADDV_D_ADDV_H_ADDV_W") 1, 0, 0,  1, 2,  2, 1,  0, 0}, // #174
  {DBGFIELD("ASUB_S_B_ASUB_S_D_ASUB_S_H_ASUB_S_W_ASUB_U_B_ASUB_U_D_ASUB_U_H_ASUB_U_W") 1, 0, 0,  1, 2,  2, 1,  0, 0}, // #175
  {DBGFIELD("AVER_S_B_AVER_S_D_AVER_S_H_AVER_S_W_AVER_U_B_AVER_U_D_AVER_U_H_AVER_U_W_AVE_S_B_AVE_S_D_AVE_S_H_AVE_S_W_AVE_U_B_AVE_U_D_AVE_U_H_AVE_U_W") 1, 0, 0,  1, 2,  2, 1,  0, 0}, // #176
  {DBGFIELD("MOVE_V")             1, 0, 0,  1, 2,  1, 1,  0, 0}, // #177
  {DBGFIELD("LDI_B_LDI_D_LDI_H_LDI_W") 1, 0, 0,  1, 2,  1, 1,  0, 0}, // #178
  {DBGFIELD("AND_V_NOR_V_OR_V_XOR_V") 1, 0, 0,  1, 2,  1, 1,  0, 0}, // #179
  {DBGFIELD("ANDI_B_NORI_B_ORI_B_XORI_B") 1, 0, 0,  1, 2,  1, 1,  0, 0}, // #180
  {DBGFIELD("ST_B_ST_D_ST_H_ST_W") 2, 0, 0,  8, 4,  1, 1,  0, 0}, // #181
  {DBGFIELD("LD_B_LD_D_LD_H_LD_W") 2, 0, 0, 30, 4,  3, 1,  0, 0}, // #182
  {DBGFIELD("P5600WriteALU")      1, 0, 0,  3, 2,  1, 1,  0, 0}, // #183
  {DBGFIELD("P5600WriteAL2")      1, 0, 0, 14, 2,  1, 1,  0, 0} // #184
}; // MipsP5600ModelSchedClasses

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

static const llvm::MCSchedModel MipsGenericItinerariesModel = {
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
  MipsGenericItineraries};

// {Name, NumUnits, SuperIdx, IsBuffered}
static const llvm::MCProcResourceDesc MipsP5600ModelProcResources[] = {
  {DBGFIELD("InvalidUnit")     0, 0, 0},
  {DBGFIELD("P5600AGQ")        3, 0, 16}, // #1
  {DBGFIELD("P5600AL2Div")     1, 0, -1}, // #2
  {DBGFIELD("P5600ALQ")        1, 0, 16}, // #3
  {DBGFIELD("P5600CTISTD")     1, 0, -1}, // #4
  {DBGFIELD("P5600FPQ")        3, 0, 16}, // #5
  {DBGFIELD("P5600FPUDivSqrt") 2, 0, -1}, // #6
  {DBGFIELD("P5600IssueAL2")   1, 1, -1}, // #7, Super=P5600AGQ
  {DBGFIELD("P5600IssueALU")   1, 3, -1}, // #8, Super=P5600ALQ
  {DBGFIELD("P5600IssueCTISTD") 1, 1, -1}, // #9, Super=P5600AGQ
  {DBGFIELD("P5600IssueFPUL")  1, 5, -1}, // #10, Super=P5600FPQ
  {DBGFIELD("P5600IssueFPULoad") 1, 5, -1}, // #11, Super=P5600FPQ
  {DBGFIELD("P5600IssueFPUS")  1, 5, -1}, // #12, Super=P5600FPQ
  {DBGFIELD("P5600IssueLDST")  1, 1, -1}  // #13, Super=P5600AGQ
};

static const llvm::MCSchedModel MipsP5600Model = {
  2, // IssueWidth
  48, // MicroOpBufferSize
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  4, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  8, // MispredictPenalty
  0, // PostRAScheduler
  1, // CompleteModel
  2, // Processor ID
  MipsP5600ModelProcResources,
  MipsP5600ModelSchedClasses,
  14,
  185,
  nullptr}; // No Itinerary

// Sorted (by key) array of itineraries for CPU subtype.
extern const llvm::SubtargetInfoKV MipsProcSchedKV[] = {
  { "mips1", (const void *)&MipsGenericItinerariesModel },
  { "mips2", (const void *)&MipsGenericItinerariesModel },
  { "mips3", (const void *)&MipsGenericItinerariesModel },
  { "mips32", (const void *)&MipsGenericItinerariesModel },
  { "mips32r2", (const void *)&MipsGenericItinerariesModel },
  { "mips32r3", (const void *)&MipsGenericItinerariesModel },
  { "mips32r5", (const void *)&MipsGenericItinerariesModel },
  { "mips32r6", (const void *)&MipsGenericItinerariesModel },
  { "mips4", (const void *)&MipsGenericItinerariesModel },
  { "mips5", (const void *)&MipsGenericItinerariesModel },
  { "mips64", (const void *)&MipsGenericItinerariesModel },
  { "mips64r2", (const void *)&MipsGenericItinerariesModel },
  { "mips64r3", (const void *)&MipsGenericItinerariesModel },
  { "mips64r5", (const void *)&MipsGenericItinerariesModel },
  { "mips64r6", (const void *)&MipsGenericItinerariesModel },
  { "octeon", (const void *)&MipsGenericItinerariesModel },
  { "p5600", (const void *)&MipsP5600Model }
};
#undef DBGFIELD
static inline MCSubtargetInfo *createMipsMCSubtargetInfoImpl(const Triple &TT, StringRef CPU, StringRef FS) {
  return new MCSubtargetInfo(TT, CPU, FS, MipsFeatureKV, MipsSubTypeKV, 
                      MipsProcSchedKV, MipsWriteProcResTable, MipsWriteLatencyTable, MipsReadAdvanceTable, 
                      MipsStages, MipsOperandCycles, MipsForwardingPaths);
}

} // end llvm namespace
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::MipsSubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  const FeatureBitset& Bits = getFeatureBits();
  if (Bits[Mips::FeatureCnMips]) HasCnMips = true;
  if (Bits[Mips::FeatureDSP]) HasDSP = true;
  if (Bits[Mips::FeatureDSPR2]) HasDSPR2 = true;
  if (Bits[Mips::FeatureDSPR3]) HasDSPR3 = true;
  if (Bits[Mips::FeatureEVA]) HasEVA = true;
  if (Bits[Mips::FeatureFP64Bit]) IsFP64bit = true;
  if (Bits[Mips::FeatureFPXX]) IsFPXX = true;
  if (Bits[Mips::FeatureGP64Bit]) IsGP64bit = true;
  if (Bits[Mips::FeatureMSA]) HasMSA = true;
  if (Bits[Mips::FeatureMicroMips]) InMicroMipsMode = true;
  if (Bits[Mips::FeatureMips1] && MipsArchVersion < Mips1) MipsArchVersion = Mips1;
  if (Bits[Mips::FeatureMips2] && MipsArchVersion < Mips2) MipsArchVersion = Mips2;
  if (Bits[Mips::FeatureMips3] && MipsArchVersion < Mips3) MipsArchVersion = Mips3;
  if (Bits[Mips::FeatureMips3_32]) HasMips3_32 = true;
  if (Bits[Mips::FeatureMips3_32r2]) HasMips3_32r2 = true;
  if (Bits[Mips::FeatureMips4] && MipsArchVersion < Mips4) MipsArchVersion = Mips4;
  if (Bits[Mips::FeatureMips4_32]) HasMips4_32 = true;
  if (Bits[Mips::FeatureMips4_32r2]) HasMips4_32r2 = true;
  if (Bits[Mips::FeatureMips5] && MipsArchVersion < Mips5) MipsArchVersion = Mips5;
  if (Bits[Mips::FeatureMips5_32r2]) HasMips5_32r2 = true;
  if (Bits[Mips::FeatureMips16]) InMips16Mode = true;
  if (Bits[Mips::FeatureMips32] && MipsArchVersion < Mips32) MipsArchVersion = Mips32;
  if (Bits[Mips::FeatureMips32r2] && MipsArchVersion < Mips32r2) MipsArchVersion = Mips32r2;
  if (Bits[Mips::FeatureMips32r3] && MipsArchVersion < Mips32r3) MipsArchVersion = Mips32r3;
  if (Bits[Mips::FeatureMips32r5] && MipsArchVersion < Mips32r5) MipsArchVersion = Mips32r5;
  if (Bits[Mips::FeatureMips32r6] && MipsArchVersion < Mips32r6) MipsArchVersion = Mips32r6;
  if (Bits[Mips::FeatureMips64] && MipsArchVersion < Mips64) MipsArchVersion = Mips64;
  if (Bits[Mips::FeatureMips64r2] && MipsArchVersion < Mips64r2) MipsArchVersion = Mips64r2;
  if (Bits[Mips::FeatureMips64r3] && MipsArchVersion < Mips64r3) MipsArchVersion = Mips64r3;
  if (Bits[Mips::FeatureMips64r5] && MipsArchVersion < Mips64r5) MipsArchVersion = Mips64r5;
  if (Bits[Mips::FeatureMips64r6] && MipsArchVersion < Mips64r6) MipsArchVersion = Mips64r6;
  if (Bits[Mips::FeatureNaN2008]) IsNaN2008bit = true;
  if (Bits[Mips::FeatureNoABICalls]) NoABICalls = true;
  if (Bits[Mips::FeatureNoOddSPReg]) UseOddSPReg = false;
  if (Bits[Mips::FeatureSingleFloat]) IsSingleFloat = true;
  if (Bits[Mips::FeatureSoftFloat]) IsSoftFloat = true;
  if (Bits[Mips::FeatureUseTCCInDIV]) UseTCCInDIV = false;
  if (Bits[Mips::FeatureVFPU]) HasVFPU = true;
  if (Bits[Mips::ImplP5600] && ProcImpl < MipsSubtarget::CPU::P5600) ProcImpl = MipsSubtarget::CPU::P5600;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct MipsGenSubtargetInfo : public TargetSubtargetInfo {
  explicit MipsGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS);
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
extern const llvm::SubtargetFeatureKV MipsFeatureKV[];
extern const llvm::SubtargetFeatureKV MipsSubTypeKV[];
extern const llvm::SubtargetInfoKV MipsProcSchedKV[];
extern const llvm::MCWriteProcResEntry MipsWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry MipsWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry MipsReadAdvanceTable[];
extern const llvm::InstrStage MipsStages[];
extern const unsigned MipsOperandCycles[];
extern const unsigned MipsForwardingPaths[];
MipsGenSubtargetInfo::MipsGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo(TT, CPU, FS, makeArrayRef(MipsFeatureKV, 39), makeArrayRef(MipsSubTypeKV, 17), 
                        MipsProcSchedKV, MipsWriteProcResTable, MipsWriteLatencyTable, MipsReadAdvanceTable, 
                        MipsStages, MipsOperandCycles, MipsForwardingPaths) {}

unsigned MipsGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  switch (SchedClass) {
  case 2: // II_ADDU
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 3: // II_ADDIU
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 6: // II_ANDI
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 131: // II_ORI
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 138: // II_ROTR
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 139: // II_ROTRV
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 148: // II_SEB
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 149: // II_SEH
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 153: // II_SLL
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 154: // II_SLLV
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 155: // II_SLT_SLTU
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 157: // II_SRA
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 158: // II_SRAV
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 159: // II_SRL
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 160: // II_SRLV
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  case 171: // II_XORI
    if (SchedModel->getProcessorID() == 2) { // MipsP5600Model
      if ((1))
        return 183; // P5600WriteALU
      if ((0))
        return 184; // P5600WriteAL2
    }
    break;
  };
  report_fatal_error("Expected a variant SchedClass");
} // MipsGenSubtargetInfo::resolveSchedClass
} // end llvm namespace
#endif // GET_SUBTARGETINFO_CTOR

