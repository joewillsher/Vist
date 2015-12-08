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
namespace PPC {
enum : uint64_t {
  DeprecatedDST = 0,
  Directive32 = 1,
  Directive64 = 2,
  Directive440 = 3,
  Directive601 = 4,
  Directive602 = 5,
  Directive603 = 6,
  Directive604 = 7,
  Directive620 = 8,
  Directive750 = 9,
  Directive970 = 10,
  Directive7400 = 11,
  DirectiveA2 = 12,
  DirectiveE500mc = 13,
  DirectiveE5500 = 14,
  DirectivePwr3 = 15,
  DirectivePwr4 = 16,
  DirectivePwr5 = 17,
  DirectivePwr5x = 18,
  DirectivePwr6 = 19,
  DirectivePwr6x = 20,
  DirectivePwr7 = 21,
  DirectivePwr8 = 22,
  Feature64Bit = 23,
  Feature64BitRegs = 24,
  FeatureAltivec = 25,
  FeatureBPERMD = 26,
  FeatureBookE = 27,
  FeatureCMPB = 28,
  FeatureCRBits = 29,
  FeatureDirectMove = 30,
  FeatureE500 = 31,
  FeatureExtDiv = 32,
  FeatureFCPSGN = 33,
  FeatureFPCVT = 34,
  FeatureFPRND = 35,
  FeatureFRE = 36,
  FeatureFRES = 37,
  FeatureFRSQRTE = 38,
  FeatureFRSQRTES = 39,
  FeatureFSqrt = 40,
  FeatureFusion = 41,
  FeatureHTM = 42,
  FeatureICBT = 43,
  FeatureISEL = 44,
  FeatureInvariantFunctionDescriptors = 45,
  FeatureLDBRX = 46,
  FeatureLFIWAX = 47,
  FeatureMFOCRF = 48,
  FeatureMFTB = 49,
  FeatureMSYNC = 50,
  FeatureP8Altivec = 51,
  FeatureP8Crypto = 52,
  FeatureP8Vector = 53,
  FeaturePOPCNTD = 54,
  FeaturePPC4xx = 55,
  FeaturePPC6xx = 56,
  FeaturePartwordAtomic = 57,
  FeatureQPX = 58,
  FeatureRecipPrec = 59,
  FeatureSPE = 60,
  FeatureSTFIWX = 61,
  FeatureVSX = 62
};
}
} // end llvm namespace
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV PPCFeatureKV[] = {
  { "64bit", "Enable 64-bit instructions", { PPC::Feature64Bit }, { } },
  { "64bitregs", "Enable 64-bit registers usage for ppc32 [beta]", { PPC::Feature64BitRegs }, { } },
  { "altivec", "Enable Altivec instructions", { PPC::FeatureAltivec }, { } },
  { "booke", "Enable Book E instructions", { PPC::FeatureBookE }, { PPC::FeatureICBT } },
  { "bpermd", "Enable the bpermd instruction", { PPC::FeatureBPERMD }, { } },
  { "cmpb", "Enable the cmpb instruction", { PPC::FeatureCMPB }, { } },
  { "crbits", "Use condition-register bits individually", { PPC::FeatureCRBits }, { } },
  { "crypto", "Enable POWER8 Crypto instructions", { PPC::FeatureP8Crypto }, { PPC::FeatureP8Altivec } },
  { "direct-move", "Enable Power8 direct move instructions", { PPC::FeatureDirectMove }, { PPC::FeatureVSX } },
  { "e500", "Enable E500/E500mc instructions", { PPC::FeatureE500 }, { } },
  { "extdiv", "Enable extended divide instructions", { PPC::FeatureExtDiv }, { } },
  { "fcpsgn", "Enable the fcpsgn instruction", { PPC::FeatureFCPSGN }, { } },
  { "fpcvt", "Enable fc[ft]* (unsigned and single-precision) and lfiwzx instructions", { PPC::FeatureFPCVT }, { } },
  { "fprnd", "Enable the fri[mnpz] instructions", { PPC::FeatureFPRND }, { } },
  { "fre", "Enable the fre instruction", { PPC::FeatureFRE }, { } },
  { "fres", "Enable the fres instruction", { PPC::FeatureFRES }, { } },
  { "frsqrte", "Enable the frsqrte instruction", { PPC::FeatureFRSQRTE }, { } },
  { "frsqrtes", "Enable the frsqrtes instruction", { PPC::FeatureFRSQRTES }, { } },
  { "fsqrt", "Enable the fsqrt instruction", { PPC::FeatureFSqrt }, { } },
  { "fusion", "Target supports add/load integer fusion.", { PPC::FeatureFusion }, { } },
  { "htm", "Enable Hardware Transactional Memory instructions", { PPC::FeatureHTM }, { } },
  { "icbt", "Enable icbt instruction", { PPC::FeatureICBT }, { } },
  { "invariant-function-descriptors", "Assume function descriptors are invariant", { PPC::FeatureInvariantFunctionDescriptors }, { } },
  { "isel", "Enable the isel instruction", { PPC::FeatureISEL }, { } },
  { "ldbrx", "Enable the ldbrx instruction", { PPC::FeatureLDBRX }, { } },
  { "lfiwax", "Enable the lfiwax instruction", { PPC::FeatureLFIWAX }, { } },
  { "mfocrf", "Enable the MFOCRF instruction", { PPC::FeatureMFOCRF }, { } },
  { "msync", "Has only the msync instruction instead of sync", { PPC::FeatureMSYNC }, { PPC::FeatureBookE } },
  { "partword-atomics", "Enable l[bh]arx and st[bh]cx.", { PPC::FeaturePartwordAtomic }, { } },
  { "popcntd", "Enable the popcnt[dw] instructions", { PPC::FeaturePOPCNTD }, { } },
  { "power8-altivec", "Enable POWER8 Altivec instructions", { PPC::FeatureP8Altivec }, { PPC::FeatureAltivec } },
  { "power8-vector", "Enable POWER8 vector instructions", { PPC::FeatureP8Vector }, { PPC::FeatureVSX, PPC::FeatureP8Altivec } },
  { "ppc4xx", "Enable PPC 4xx instructions", { PPC::FeaturePPC4xx }, { } },
  { "ppc6xx", "Enable PPC 6xx instructions", { PPC::FeaturePPC6xx }, { } },
  { "qpx", "Enable QPX instructions", { PPC::FeatureQPX }, { } },
  { "recipprec", "Assume higher precision reciprocal estimates", { PPC::FeatureRecipPrec }, { } },
  { "spe", "Enable SPE instructions", { PPC::FeatureSPE }, { } },
  { "stfiwx", "Enable the stfiwx instruction", { PPC::FeatureSTFIWX }, { } },
  { "vsx", "Enable VSX instructions", { PPC::FeatureVSX }, { PPC::FeatureAltivec } }
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV PPCSubTypeKV[] = {
  { "440", "Select the 440 processor", { PPC::Directive440, PPC::FeatureISEL, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureICBT, PPC::FeatureBookE, PPC::FeatureMSYNC, PPC::FeatureMFTB }, { } },
  { "450", "Select the 450 processor", { PPC::Directive440, PPC::FeatureISEL, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureICBT, PPC::FeatureBookE, PPC::FeatureMSYNC, PPC::FeatureMFTB }, { } },
  { "601", "Select the 601 processor", { PPC::Directive601 }, { } },
  { "602", "Select the 602 processor", { PPC::Directive602, PPC::FeatureMFTB }, { } },
  { "603", "Select the 603 processor", { PPC::Directive603, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "603e", "Select the 603e processor", { PPC::Directive603, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "603ev", "Select the 603ev processor", { PPC::Directive603, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "604", "Select the 604 processor", { PPC::Directive604, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "604e", "Select the 604e processor", { PPC::Directive604, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "620", "Select the 620 processor", { PPC::Directive620, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "7400", "Select the 7400 processor", { PPC::Directive7400, PPC::FeatureAltivec, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "7450", "Select the 7450 processor", { PPC::Directive7400, PPC::FeatureAltivec, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "750", "Select the 750 processor", { PPC::Directive750, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "970", "Select the 970 processor", { PPC::Directive970, PPC::FeatureAltivec, PPC::FeatureMFOCRF, PPC::FeatureFSqrt, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureSTFIWX, PPC::Feature64Bit, PPC::FeatureMFTB }, { } },
  { "a2", "Select the a2 processor", { PPC::DirectiveA2, PPC::FeatureICBT, PPC::FeatureBookE, PPC::FeatureMFOCRF, PPC::FeatureFCPSGN, PPC::FeatureFSqrt, PPC::FeatureFRE, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureFRSQRTES, PPC::FeatureRecipPrec, PPC::FeatureSTFIWX, PPC::FeatureLFIWAX, PPC::FeatureFPRND, PPC::FeatureFPCVT, PPC::FeatureISEL, PPC::FeaturePOPCNTD, PPC::FeatureCMPB, PPC::FeatureLDBRX, PPC::Feature64Bit, PPC::FeatureMFTB }, { } },
  { "a2q", "Select the a2q processor", { PPC::DirectiveA2, PPC::FeatureICBT, PPC::FeatureBookE, PPC::FeatureMFOCRF, PPC::FeatureFCPSGN, PPC::FeatureFSqrt, PPC::FeatureFRE, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureFRSQRTES, PPC::FeatureRecipPrec, PPC::FeatureSTFIWX, PPC::FeatureLFIWAX, PPC::FeatureFPRND, PPC::FeatureFPCVT, PPC::FeatureISEL, PPC::FeaturePOPCNTD, PPC::FeatureCMPB, PPC::FeatureLDBRX, PPC::Feature64Bit, PPC::FeatureQPX, PPC::FeatureMFTB }, { } },
  { "e500mc", "Select the e500mc processor", { PPC::DirectiveE500mc, PPC::FeatureSTFIWX, PPC::FeatureICBT, PPC::FeatureBookE, PPC::FeatureISEL, PPC::FeatureMFTB }, { } },
  { "e5500", "Select the e5500 processor", { PPC::DirectiveE5500, PPC::FeatureMFOCRF, PPC::Feature64Bit, PPC::FeatureSTFIWX, PPC::FeatureICBT, PPC::FeatureBookE, PPC::FeatureISEL, PPC::FeatureMFTB }, { } },
  { "g3", "Select the g3 processor", { PPC::Directive750, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "g4", "Select the g4 processor", { PPC::Directive7400, PPC::FeatureAltivec, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "g4+", "Select the g4+ processor", { PPC::Directive7400, PPC::FeatureAltivec, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFTB }, { } },
  { "g5", "Select the g5 processor", { PPC::Directive970, PPC::FeatureAltivec, PPC::FeatureMFOCRF, PPC::FeatureFSqrt, PPC::FeatureSTFIWX, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::Feature64Bit, PPC::FeatureMFTB, PPC::DeprecatedDST }, { } },
  { "generic", "Select the generic processor", { PPC::Directive32, PPC::FeatureMFTB }, { } },
  { "ppc", "Select the ppc processor", { PPC::Directive32, PPC::FeatureMFTB }, { } },
  { "ppc64", "Select the ppc64 processor", { PPC::Directive64, PPC::FeatureAltivec, PPC::FeatureMFOCRF, PPC::FeatureFSqrt, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureSTFIWX, PPC::Feature64Bit, PPC::FeatureMFTB }, { } },
  { "ppc64le", "Select the ppc64le processor", { PPC::DirectivePwr7, PPC::FeatureAltivec, PPC::FeatureVSX, PPC::FeatureMFOCRF, PPC::FeatureFCPSGN, PPC::FeatureFSqrt, PPC::FeatureFRE, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureFRSQRTES, PPC::FeatureRecipPrec, PPC::FeatureSTFIWX, PPC::FeatureLFIWAX, PPC::FeatureFPRND, PPC::FeatureFPCVT, PPC::FeatureISEL, PPC::FeaturePOPCNTD, PPC::FeatureCMPB, PPC::FeatureLDBRX, PPC::Feature64Bit, PPC::FeatureBPERMD, PPC::FeatureExtDiv, PPC::FeatureMFTB, PPC::DeprecatedDST, PPC::DirectivePwr8, PPC::FeatureP8Altivec, PPC::FeatureP8Vector, PPC::FeatureP8Crypto, PPC::FeatureHTM, PPC::FeatureDirectMove, PPC::FeatureICBT, PPC::FeaturePartwordAtomic, PPC::FeatureFusion }, { } },
  { "pwr3", "Select the pwr3 processor", { PPC::DirectivePwr3, PPC::FeatureAltivec, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureMFOCRF, PPC::FeatureSTFIWX, PPC::Feature64Bit }, { } },
  { "pwr4", "Select the pwr4 processor", { PPC::DirectivePwr4, PPC::FeatureAltivec, PPC::FeatureMFOCRF, PPC::FeatureFSqrt, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureSTFIWX, PPC::Feature64Bit, PPC::FeatureMFTB }, { } },
  { "pwr5", "Select the pwr5 processor", { PPC::DirectivePwr5, PPC::FeatureAltivec, PPC::FeatureMFOCRF, PPC::FeatureFSqrt, PPC::FeatureFRE, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureFRSQRTES, PPC::FeatureSTFIWX, PPC::Feature64Bit, PPC::FeatureMFTB, PPC::DeprecatedDST }, { } },
  { "pwr5x", "Select the pwr5x processor", { PPC::DirectivePwr5x, PPC::FeatureAltivec, PPC::FeatureMFOCRF, PPC::FeatureFSqrt, PPC::FeatureFRE, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureFRSQRTES, PPC::FeatureSTFIWX, PPC::FeatureFPRND, PPC::Feature64Bit, PPC::FeatureMFTB, PPC::DeprecatedDST }, { } },
  { "pwr6", "Select the pwr6 processor", { PPC::DirectivePwr6, PPC::FeatureAltivec, PPC::FeatureMFOCRF, PPC::FeatureFCPSGN, PPC::FeatureFSqrt, PPC::FeatureFRE, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureFRSQRTES, PPC::FeatureRecipPrec, PPC::FeatureSTFIWX, PPC::FeatureLFIWAX, PPC::FeatureCMPB, PPC::FeatureFPRND, PPC::Feature64Bit, PPC::FeatureMFTB, PPC::DeprecatedDST }, { } },
  { "pwr6x", "Select the pwr6x processor", { PPC::DirectivePwr5x, PPC::FeatureAltivec, PPC::FeatureMFOCRF, PPC::FeatureFCPSGN, PPC::FeatureFSqrt, PPC::FeatureFRE, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureFRSQRTES, PPC::FeatureRecipPrec, PPC::FeatureSTFIWX, PPC::FeatureLFIWAX, PPC::FeatureCMPB, PPC::FeatureFPRND, PPC::Feature64Bit, PPC::FeatureMFTB, PPC::DeprecatedDST }, { } },
  { "pwr7", "Select the pwr7 processor", { PPC::DirectivePwr7, PPC::FeatureAltivec, PPC::FeatureVSX, PPC::FeatureMFOCRF, PPC::FeatureFCPSGN, PPC::FeatureFSqrt, PPC::FeatureFRE, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureFRSQRTES, PPC::FeatureRecipPrec, PPC::FeatureSTFIWX, PPC::FeatureLFIWAX, PPC::FeatureFPRND, PPC::FeatureFPCVT, PPC::FeatureISEL, PPC::FeaturePOPCNTD, PPC::FeatureCMPB, PPC::FeatureLDBRX, PPC::Feature64Bit, PPC::FeatureBPERMD, PPC::FeatureExtDiv, PPC::FeatureMFTB, PPC::DeprecatedDST }, { } },
  { "pwr8", "Select the pwr8 processor", { PPC::DirectivePwr7, PPC::FeatureAltivec, PPC::FeatureVSX, PPC::FeatureMFOCRF, PPC::FeatureFCPSGN, PPC::FeatureFSqrt, PPC::FeatureFRE, PPC::FeatureFRES, PPC::FeatureFRSQRTE, PPC::FeatureFRSQRTES, PPC::FeatureRecipPrec, PPC::FeatureSTFIWX, PPC::FeatureLFIWAX, PPC::FeatureFPRND, PPC::FeatureFPCVT, PPC::FeatureISEL, PPC::FeaturePOPCNTD, PPC::FeatureCMPB, PPC::FeatureLDBRX, PPC::Feature64Bit, PPC::FeatureBPERMD, PPC::FeatureExtDiv, PPC::FeatureMFTB, PPC::DeprecatedDST, PPC::DirectivePwr8, PPC::FeatureP8Altivec, PPC::FeatureP8Vector, PPC::FeatureP8Crypto, PPC::FeatureHTM, PPC::FeatureDirectMove, PPC::FeatureICBT, PPC::FeaturePartwordAtomic, PPC::FeatureFusion }, { } }
};

#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#ifndef NDEBUG
#define DBGFIELD(x) x,
#else
#define DBGFIELD(x)
#endif

// Functional units for "PPC440Itineraries"
namespace PPC440ItinerariesFU {
  const unsigned P440_DISS1 = 1 << 0;
  const unsigned P440_DISS2 = 1 << 1;
  const unsigned P440_FRACC = 1 << 2;
  const unsigned P440_IRACC = 1 << 3;
  const unsigned P440_IEXE1 = 1 << 4;
  const unsigned P440_IEXE2 = 1 << 5;
  const unsigned P440_IWB = 1 << 6;
  const unsigned P440_LRACC = 1 << 7;
  const unsigned P440_JEXE1 = 1 << 8;
  const unsigned P440_JEXE2 = 1 << 9;
  const unsigned P440_JWB = 1 << 10;
  const unsigned P440_AGEN = 1 << 11;
  const unsigned P440_CRD = 1 << 12;
  const unsigned P440_LWB = 1 << 13;
  const unsigned P440_FEXE1 = 1 << 14;
  const unsigned P440_FEXE2 = 1 << 15;
  const unsigned P440_FEXE3 = 1 << 16;
  const unsigned P440_FEXE4 = 1 << 17;
  const unsigned P440_FEXE5 = 1 << 18;
  const unsigned P440_FEXE6 = 1 << 19;
  const unsigned P440_FWB = 1 << 20;
  const unsigned P440_LWARX_Hold = 1 << 21;
}

// Pipeline forwarding pathes for itineraries "PPC440Itineraries"
namespace PPC440ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned P440_GPR_Bypass = 1 << 0;
  const unsigned P440_FPR_Bypass = 1 << 1;
}

// Functional units for "G3Itineraries"
namespace G3ItinerariesFU {
  const unsigned G3_IU1 = 1 << 0;
  const unsigned G3_IU2 = 1 << 1;
  const unsigned G3_FPU1 = 1 << 2;
  const unsigned G3_BPU = 1 << 3;
  const unsigned G3_SRU = 1 << 4;
  const unsigned G3_SLU = 1 << 5;
}

// Functional units for "G4Itineraries"
namespace G4ItinerariesFU {
  const unsigned G4_IU1 = 1 << 0;
  const unsigned G4_IU2 = 1 << 1;
  const unsigned G4_SLU = 1 << 2;
  const unsigned G4_SRU = 1 << 3;
  const unsigned G4_BPU = 1 << 4;
  const unsigned G4_FPU1 = 1 << 5;
  const unsigned G4_VIU1 = 1 << 6;
  const unsigned G4_VIU2 = 1 << 7;
  const unsigned G4_VPU = 1 << 8;
  const unsigned G4_VFPU = 1 << 9;
}

// Functional units for "G4PlusItineraries"
namespace G4PlusItinerariesFU {
  const unsigned G4P_IU1 = 1 << 0;
  const unsigned G4P_IU2 = 1 << 1;
  const unsigned G4P_IU3 = 1 << 2;
  const unsigned G4P_IU4 = 1 << 3;
  const unsigned G4P_BPU = 1 << 4;
  const unsigned G4P_SLU = 1 << 5;
  const unsigned G4P_FPU1 = 1 << 6;
  const unsigned G4P_VFPU = 1 << 7;
  const unsigned G4P_VIU1 = 1 << 8;
  const unsigned G4P_VIU2 = 1 << 9;
  const unsigned G4P_VPU = 1 << 10;
}

// Functional units for "G5Itineraries"
namespace G5ItinerariesFU {
  const unsigned G5_IU1 = 1 << 0;
  const unsigned G5_IU2 = 1 << 1;
  const unsigned G5_SLU = 1 << 2;
  const unsigned G5_BPU = 1 << 3;
  const unsigned G5_FPU1 = 1 << 4;
  const unsigned G5_FPU2 = 1 << 5;
  const unsigned G5_VFPU = 1 << 6;
  const unsigned G5_VIU1 = 1 << 7;
  const unsigned G5_VIU2 = 1 << 8;
  const unsigned G5_VPU = 1 << 9;
}

// Functional units for "PPCA2Itineraries"
namespace PPCA2ItinerariesFU {
  const unsigned A2_XU = 1 << 0;
  const unsigned A2_FU = 1 << 1;
}

// Functional units for "PPCE500mcItineraries"
namespace PPCE500mcItinerariesFU {
  const unsigned E500_DIS0 = 1 << 0;
  const unsigned E500_DIS1 = 1 << 1;
  const unsigned E500_SFX0 = 1 << 2;
  const unsigned E500_SFX1 = 1 << 3;
  const unsigned E500_BU = 1 << 4;
  const unsigned E500_CFX_DivBypass = 1 << 5;
  const unsigned E500_CFX_0 = 1 << 6;
  const unsigned E500_LSU_0 = 1 << 7;
  const unsigned E500_FPU_0 = 1 << 8;
}

// Pipeline forwarding pathes for itineraries "PPCE500mcItineraries"
namespace PPCE500mcItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E500_CR_Bypass = 1 << 0;
  const unsigned E500_GPR_Bypass = 1 << 1;
  const unsigned E500_FPR_Bypass = 1 << 2;
}

// Functional units for "PPCE5500Itineraries"
namespace PPCE5500ItinerariesFU {
  const unsigned E5500_DIS0 = 1 << 0;
  const unsigned E5500_DIS1 = 1 << 1;
  const unsigned E5500_SFX0 = 1 << 2;
  const unsigned E5500_SFX1 = 1 << 3;
  const unsigned E5500_BU = 1 << 4;
  const unsigned E5500_CFX_DivBypass = 1 << 5;
  const unsigned E5500_CFX_0 = 1 << 6;
  const unsigned E5500_CFX_1 = 1 << 7;
  const unsigned E5500_LSU_0 = 1 << 8;
  const unsigned E5500_FPU_0 = 1 << 9;
}

// Pipeline forwarding pathes for itineraries "PPCE5500Itineraries"
namespace PPCE5500ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned E5500_CR_Bypass = 1 << 0;
  const unsigned E5500_GPR_Bypass = 1 << 1;
  const unsigned E5500_FPR_Bypass = 1 << 2;
}

// Functional units for "P8Itineraries"
namespace P8ItinerariesFU {
  const unsigned P8_DU1 = 1 << 0;
  const unsigned P8_DU2 = 1 << 1;
  const unsigned P8_DU3 = 1 << 2;
  const unsigned P8_DU4 = 1 << 3;
  const unsigned P8_DU5 = 1 << 4;
  const unsigned P8_DU6 = 1 << 5;
  const unsigned P8_DU7 = 1 << 6;
  const unsigned P8_DU8 = 1 << 7;
  const unsigned P8_LU1 = 1 << 8;
  const unsigned P8_LU2 = 1 << 9;
  const unsigned P8_LSU1 = 1 << 10;
  const unsigned P8_LSU2 = 1 << 11;
  const unsigned P8_FXU1 = 1 << 12;
  const unsigned P8_FXU2 = 1 << 13;
  const unsigned P8_FPU1 = 1 << 14;
  const unsigned P8_FPU2 = 1 << 15;
  const unsigned P8_CRU = 1 << 16;
  const unsigned P8_BRU = 1 << 17;
}

// Functional units for "P7Itineraries"
namespace P7ItinerariesFU {
  const unsigned P7_DU1 = 1 << 0;
  const unsigned P7_DU2 = 1 << 1;
  const unsigned P7_DU3 = 1 << 2;
  const unsigned P7_DU4 = 1 << 3;
  const unsigned P7_DU5 = 1 << 4;
  const unsigned P7_DU6 = 1 << 5;
  const unsigned P7_LS1 = 1 << 6;
  const unsigned P7_LS2 = 1 << 7;
  const unsigned P7_FX1 = 1 << 8;
  const unsigned P7_FX2 = 1 << 9;
  const unsigned P7_VS1 = 1 << 10;
  const unsigned P7_VS2 = 1 << 11;
  const unsigned P7_CRU = 1 << 12;
  const unsigned P7_BRU = 1 << 13;
}

extern const llvm::InstrStage PPCStages[] = {
  { 0, 0, 0, llvm::InstrStage::Required }, // No itinerary
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC | PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1 | PPC440ItinerariesFU::P440_JEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2 | PPC440ItinerariesFU::P440_JEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IWB | PPC440ItinerariesFU::P440_JWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 1-5
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 6-10
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_AGEN, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_CRD, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 11-15
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_AGEN, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_CRD, -1, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPC440ItinerariesFU::P440_LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 16-20
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 33, PPC440ItinerariesFU::P440_IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 21-25
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE3, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE4, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE5, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE6, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 26-34
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE3, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE4, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE5, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE6, -1, (llvm::InstrStage::ReservationKinds)0 },   { 25, PPC440ItinerariesFU::P440_FWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 35-43
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE3, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE4, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE5, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE6, -1, (llvm::InstrStage::ReservationKinds)0 },   { 13, PPC440ItinerariesFU::P440_FWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 44-52
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FRACC, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_AGEN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_JEXE1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_FEXE2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_CRD, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_JEXE2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::P440_FEXE3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::P440_LWB, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::P440_JWB, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, PPC440ItinerariesFU::P440_IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 53-68
  { 1, PPC440ItinerariesFU::P440_DISS1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPC440ItinerariesFU::P440_LWARX_Hold, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_AGEN, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_CRD, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 69-75
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_IEXE2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPC440ItinerariesFU::P440_IWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 76-80
  { 1, PPC440ItinerariesFU::P440_DISS1 | PPC440ItinerariesFU::P440_DISS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LRACC, -1, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPC440ItinerariesFU::P440_AGEN, 1, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPC440ItinerariesFU::P440_CRD, 1, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPC440ItinerariesFU::P440_LWB, -1, (llvm::InstrStage::ReservationKinds)0 }, // 81-85
  { 1, G3ItinerariesFU::G3_IU1 | G3ItinerariesFU::G3_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 86
  { 1, G3ItinerariesFU::G3_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 87
  { 1, G3ItinerariesFU::G3_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 88
  { 3, G3ItinerariesFU::G3_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 89
  { 2, G3ItinerariesFU::G3_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 90
  { 19, G3ItinerariesFU::G3_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 91
  { 1, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 92
  { 31, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 93
  { 17, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 94
  { 2, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 95
  { 2, G3ItinerariesFU::G3_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 96
  { 34, G3ItinerariesFU::G3_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 97
  { 3, G3ItinerariesFU::G3_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 98
  { 3, G3ItinerariesFU::G3_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 99
  { 5, G3ItinerariesFU::G3_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 100
  { 6, G3ItinerariesFU::G3_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 101
  { 3, G3ItinerariesFU::G3_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 102
  { 8, G3ItinerariesFU::G3_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 103
  { 2, G3ItinerariesFU::G3_IU1 | G3ItinerariesFU::G3_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 104
  { 1, G4ItinerariesFU::G4_IU1 | G4ItinerariesFU::G4_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 105
  { 1, G4ItinerariesFU::G4_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 106
  { 4, G4ItinerariesFU::G4_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 107
  { 1, G4ItinerariesFU::G4_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 108
  { 2, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 109
  { 19, G4ItinerariesFU::G4_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 110
  { 1, G4ItinerariesFU::G4_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 111
  { 31, G4ItinerariesFU::G4_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 112
  { 17, G4ItinerariesFU::G4_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 113
  { 2, G4ItinerariesFU::G4_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 114
  { 3, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 115
  { 34, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 116
  { 3, G4ItinerariesFU::G4_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 117
  { 3, G4ItinerariesFU::G4_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 118
  { 1, G4ItinerariesFU::G4_VIU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 119
  { 8, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 120
  { 5, G4ItinerariesFU::G4_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 121
  { 6, G4ItinerariesFU::G4_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 122
  { 3, G4ItinerariesFU::G4_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 123
  { 1, G4ItinerariesFU::G4_VPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 124
  { 5, G4ItinerariesFU::G4_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 125
  { 8, G4ItinerariesFU::G4_SRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 126
  { 2, G4ItinerariesFU::G4_IU1 | G4ItinerariesFU::G4_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 127
  { 1, G4PlusItinerariesFU::G4P_IU1 | G4PlusItinerariesFU::G4P_IU2 | G4PlusItinerariesFU::G4P_IU3 | G4PlusItinerariesFU::G4P_IU4, -1, (llvm::InstrStage::ReservationKinds)0 }, // 128
  { 1, G4PlusItinerariesFU::G4P_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 129
  { 4, G4PlusItinerariesFU::G4P_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 130
  { 2, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 131
  { 3, G4PlusItinerariesFU::G4P_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 132
  { 23, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 133
  { 5, G4PlusItinerariesFU::G4P_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 134
  { 35, G4PlusItinerariesFU::G4P_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 135
  { 21, G4PlusItinerariesFU::G4P_FPU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 136
  { 3, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 137
  { 0, G4PlusItinerariesFU::G4P_IU1 | G4PlusItinerariesFU::G4P_IU2 | G4PlusItinerariesFU::G4P_IU3 | G4PlusItinerariesFU::G4P_IU4, -1, (llvm::InstrStage::ReservationKinds)0 }, // 138
  { 4, G4PlusItinerariesFU::G4P_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 139
  { 37, G4PlusItinerariesFU::G4P_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 140
  { 4, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 141
  { 5, G4PlusItinerariesFU::G4P_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 142
  { 1, G4PlusItinerariesFU::G4P_VIU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 143
  { 35, G4PlusItinerariesFU::G4P_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 144
  { 2, G4PlusItinerariesFU::G4P_VPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 145
  { 2, G4PlusItinerariesFU::G4P_IU1 | G4PlusItinerariesFU::G4P_IU2 | G4PlusItinerariesFU::G4P_IU3 | G4PlusItinerariesFU::G4P_IU4, -1, (llvm::InstrStage::ReservationKinds)0 }, // 146
  { 2, G4PlusItinerariesFU::G4P_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 147
  { 2, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 148
  { 1, G5ItinerariesFU::G5_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 149
  { 8, G5ItinerariesFU::G5_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 150
  { 3, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 151
  { 4, G5ItinerariesFU::G5_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 152
  { 3, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 153
  { 68, G5ItinerariesFU::G5_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 154
  { 36, G5ItinerariesFU::G5_IU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 155
  { 6, G5ItinerariesFU::G5_FPU1 | G5ItinerariesFU::G5_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 156
  { 8, G5ItinerariesFU::G5_FPU1 | G5ItinerariesFU::G5_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 157
  { 33, G5ItinerariesFU::G5_FPU1 | G5ItinerariesFU::G5_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 158
  { 40, G5ItinerariesFU::G5_FPU1 | G5ItinerariesFU::G5_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 159
  { 40, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 160
  { 11, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 161
  { 5, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 162
  { 64, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 163
  { 2, G5ItinerariesFU::G5_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 164
  { 2, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 165
  { 3, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 166
  { 6, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 167
  { 10, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 168
  { 2, G5ItinerariesFU::G5_VIU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 169
  { 35, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 170
  { 3, G5ItinerariesFU::G5_BPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 171
  { 8, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 172
  { 5, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 173
  { 7, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 174
  { 4, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 175
  { 3, G5ItinerariesFU::G5_VPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 176
  { 4, G5ItinerariesFU::G5_SLU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 177
  { 1, G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 178
  { 1, G5ItinerariesFU::G5_IU1 | G5ItinerariesFU::G5_IU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 179
  { 2, G5ItinerariesFU::G5_VFPU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 180
  { 1, PPCA2ItinerariesFU::A2_XU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 181
  { 1, PPCA2ItinerariesFU::A2_FU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 182
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500_SFX0 | PPCE500mcItinerariesFU::E500_SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 183-184
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 185-186
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 187-188
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 14, PPCE500mcItinerariesFU::E500_CFX_DivBypass, -1, (llvm::InstrStage::ReservationKinds)0 }, // 189-191
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500mcItinerariesFU::E500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 192-193
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE500mcItinerariesFU::E500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 194-195
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 68, PPCE500mcItinerariesFU::E500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 196-197
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 38, PPCE500mcItinerariesFU::E500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 198-199
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE500mcItinerariesFU::E500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 200-201
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500_SFX0 | PPCE500mcItinerariesFU::E500_SFX1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 202-204
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, PPCE500mcItinerariesFU::E500_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 205-206
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 8, PPCE500mcItinerariesFU::E500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 207-208
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE500mcItinerariesFU::E500_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 209-210
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500mcItinerariesFU::E500_SFX0 | PPCE500mcItinerariesFU::E500_SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 211-212
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 213-214
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 215-216
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE500mcItinerariesFU::E500_LSU_0, 0, (llvm::InstrStage::ReservationKinds)0 }, // 217-218
  { 1, PPCE500mcItinerariesFU::E500_DIS0 | PPCE500mcItinerariesFU::E500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE500mcItinerariesFU::E500_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 219-220
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_SFX0 | PPCE5500ItinerariesFU::E5500_SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 221-222
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_BU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 223-224
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 225-226
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 26, PPCE5500ItinerariesFU::E5500_CFX_DivBypass, -1, (llvm::InstrStage::ReservationKinds)0 }, // 227-229
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 16, PPCE5500ItinerariesFU::E5500_CFX_DivBypass, -1, (llvm::InstrStage::ReservationKinds)0 }, // 230-232
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 233-234
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 31, PPCE5500ItinerariesFU::E5500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 235-236
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 16, PPCE5500ItinerariesFU::E5500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 237-238
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, PPCE5500ItinerariesFU::E5500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 239-240
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_SFX0 | PPCE5500ItinerariesFU::E5500_SFX1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 241-243
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE5500ItinerariesFU::E5500_LSU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 244-245
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, PPCE5500ItinerariesFU::E5500_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 246-247
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 248-249
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE5500ItinerariesFU::E5500_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 250-251
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, PPCE5500ItinerariesFU::E5500_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 252-253
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 7, PPCE5500ItinerariesFU::E5500_FPU_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 254-255
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::E5500_CFX_0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 256-257
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 258-260
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_CFX_0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::E5500_CFX_1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 261-263
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::E5500_SFX0 | PPCE5500ItinerariesFU::E5500_SFX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 264-265
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, PPCE5500ItinerariesFU::E5500_LSU_0, 0, (llvm::InstrStage::ReservationKinds)0 }, // 266-267
  { 1, PPCE5500ItinerariesFU::E5500_DIS0 | PPCE5500ItinerariesFU::E5500_DIS1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, PPCE5500ItinerariesFU::E5500_SFX0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 268-269
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 270-271
  { 1, P8ItinerariesFU::P8_DU7 | P8ItinerariesFU::P8_DU8, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_BRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 272-273
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU1 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 274-275
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 276-277
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_CRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 278-279
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 280-281
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 23, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 282-283
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 15, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 284-285
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU1 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 286-287
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_BRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 288-290
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 291-295
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 296-299
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU5, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 300-306
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 307-308
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 309-312
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 313-316
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 317-321
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU5, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 322-330
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2 | P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 331-334
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_CRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 335-336
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 337-339
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 340-341
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU2 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 342-343
  { 1, P8ItinerariesFU::P8_DU1 | P8ItinerariesFU::P8_DU2 | P8ItinerariesFU::P8_DU3 | P8ItinerariesFU::P8_DU4 | P8ItinerariesFU::P8_DU5 | P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU1 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 344-346
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FPU1 | P8ItinerariesFU::P8_FPU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 347-351
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU5, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 352-359
  { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 360-362
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LU1 | P8ItinerariesFU::P8_LU2 | P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 363-366
  { 1, P8ItinerariesFU::P8_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU5, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_LSU1 | P8ItinerariesFU::P8_LSU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P8ItinerariesFU::P8_FXU1 | P8ItinerariesFU::P8_FXU2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 367-375
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2 | P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 376-377
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 378-379
  { 1, P7ItinerariesFU::P7_DU5 | P7ItinerariesFU::P7_DU6, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_BRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 380-381
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1 | P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 382-383
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_CRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 384-385
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 386-387
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 68, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 388-390
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 36, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 391-393
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1 | P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 394-395
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_BRU, -1, (llvm::InstrStage::ReservationKinds)0 }, // 396-398
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 399-403
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 404-407
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 408-414
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 415-418
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 419-423
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 424-431
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 432-434
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 435-436
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_CRU, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 437-442
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 443-444
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 445-446
  { 1, P7ItinerariesFU::P7_DU1 | P7ItinerariesFU::P7_DU2 | P7ItinerariesFU::P7_DU3 | P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1 | P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 447-449
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_VS1 | P7ItinerariesFU::P7_VS2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 450-454
  { 1, P7ItinerariesFU::P7_DU1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU3, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_DU4, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_LS1 | P7ItinerariesFU::P7_LS2, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, P7ItinerariesFU::P7_FX1 | P7ItinerariesFU::P7_FX2, -1, (llvm::InstrStage::ReservationKinds)0 }, // 455-461
  { 0, 0, 0, llvm::InstrStage::Required } // End stages
};
extern const unsigned PPCOperandCycles[] = {
  0, // No itinerary
  2,   0,   0, // 1-3
  2,   0,   0, // 4-6
  4,   0, // 7-8
  2,   0,   0, // 9-11
  4,   0,   0, // 12-14
  1,   1, // 15-16
  5,   1,   1, // 17-19
  36,   0,   0, // 20-22
  6,   0,   0, // 23-25
  6,   0,   0, // 26-28
  6,   0,   0, // 29-31
  31,   0,   0, // 32-34
  19,   0,   0, // 35-37
  6,   0,   0,   0, // 38-41
  4,   1,   1, // 42-44
  2,   0,   0,   0, // 45-48
  4,   1,   1, // 49-51
  5,   2,   1,   1, // 52-55
  5,   2,   1,   1, // 56-59
  5,   1,   1, // 60-62
  5,   2,   1,   1, // 63-66
  5,   2,   1,   1, // 67-70
  4,   1,   1, // 71-73
  4,   1,   1, // 74-76
  4,   1,   1, // 77-79
  4,   1,   1, // 80-82
  4,   0,   0, // 83-85
  4,   0, // 86-87
  6,   0, // 88-89
  3,   0,   0, // 90-92
  3,   0, // 93-94
  2,   0, // 95-96
  6,   0, // 97-98
  1,   1,   1, // 99-101
  4,   0,   0, // 102-104
  6,   0, // 105-106
  3,   0,   0, // 107-109
  2,   0, // 110-111
  5,   0, // 112-113
  4,   0,   0, // 114-116
  4,   0,   0, // 117-119
  4,   0,   0, // 120-122
  1,   1,   1, // 123-125
  2,   1,   1,   1, // 126-129
  4,   0, // 130-131
  2,   0,   0, // 132-134
  2,   0,   0, // 135-137
  4,   1,   1, // 138-140
  2,   1,   1,   1, // 141-144
  4,   1,   1, // 145-147
  4,   1,   1, // 148-150
  2,   1,   1,   1, // 151-154
  2,   1,   1,   1, // 155-158
  2,   0, // 159-160
  1,   0,   0, // 161-163
  2,   0,   0, // 164-166
  6,   0,   0, // 167-169
  2,   0,   0, // 170-172
  1,   0,   0, // 173-175
  1,   0,   0, // 176-178
  6,   0,   0, // 179-181
  71,   0,   0, // 182-184
  39,   0,   0, // 185-187
  6,   0,   0, // 188-190
  6,   0,   0, // 191-193
  5,   0,   0, // 194-196
  72,   0,   0, // 197-199
  59,   0,   0, // 200-202
  6,   0,   0,   0, // 203-206
  69,   0,   0, // 207-209
  65,   0,   0, // 210-212
  16,   0,   0, // 213-215
  2,   0,   0,   0, // 216-219
  16, // 220
  82,   0,   0, // 221-223
  6,   8,   0,   0, // 224-227
  6,   8,   0,   0, // 228-231
  6,   0,   0, // 232-234
  6,   0,   0, // 235-237
  7,   0,   0, // 238-240
  7,   9,   0,   0, // 241-244
  7,   9,   0,   0, // 245-248
  6,   0,   0, // 249-251
  6,   8,   0,   0, // 252-255
  6,   8,   0,   0, // 256-259
  5,   0,   0, // 260-262
  6,   0, // 263-264
  6,   0, // 265-266
  4,   0, // 267-268
  1,   0, // 269-270
  4,   0, // 271-272
  0,   0,   0, // 273-275
  6, // 276
  1,   0,   0, // 277-279
  6,   0, // 280-281
  16,   0, // 282-283
  5,   0,   0, // 284-286
  5,   0,   0, // 287-289
  6,   0,   0, // 290-292
  0,   0,   0, // 293-295
  2,   0,   0,   0, // 296-299
  16, // 300
  2,   0,   0, // 301-303
  2,   0,   0, // 304-306
  2,   0,   0, // 307-309
  2,   0,   0, // 310-312
  82,   0,   0, // 313-315
  2,   0,   0,   0, // 316-319
  0,   0,   0, // 320-322
  82,   0,   0, // 323-325
  2,   0,   0,   0, // 326-329
  2,   0,   0,   0, // 330-333
  2,   0, // 334-335
  2,   0, // 336-337
  4,   1,   1, // 338-340
  4,   1,   1, // 341-343
  4,   1, // 344-345
  5,   1,   1, // 346-348
  4,   1,   1, // 349-351
  6,   1, // 352-353
  6,   1, // 354-355
  17,   1,   1, // 356-358
  11,   1,   1, // 359-361
  13,   1,   1, // 362-364
  11,   1,   1, // 365-367
  71,   1,   1, // 368-370
  41,   1,   1, // 371-373
  13,   1,   1,   1, // 374-377
  6,   1, // 378-379
  4,   1,   1,   1, // 380-383
  6,   1,   1, // 384-386
  6,   1, // 387-388
  6,   1, // 389-390
  7,   1,   1, // 391-393
  7,   1,   1, // 394-396
  7,   1,   1, // 397-399
  6,   1, // 400-401
  6,   1, // 402-403
  6,   1, // 404-405
  7,   1, // 406-407
  4,   1, // 408-409
  8,   1, // 410-411
  4,   1, // 412-413
  11, // 414
  7,   1, // 415-416
  8,   1, // 417-418
  7,   1, // 419-420
  7,   1, // 421-422
  6,   1, // 423-424
  4,   1,   1, // 425-427
  4,   1, // 428-429
  11,   1,   1, // 430-432
  5,   1, // 433-434
  5,   1, // 435-436
  7,   1,   1, // 437-439
  7,   1,   1, // 440-442
  7,   1,   1, // 443-445
  6,   1,   1, // 446-448
  6,   1,   1, // 449-451
  4,   1,   1, // 452-454
  4,   1,   1, // 455-457
  6,   1, // 458-459
  6,   1, // 460-461
  5,   1, // 462-463
  5,   2,   2, // 464-466
  5,   2,   2, // 467-469
  5,   2, // 470-471
  6,   2,   2, // 472-474
  5,   2,   2, // 475-477
  7,   2, // 478-479
  7,   2, // 480-481
  30,   2,   2, // 482-484
  20,   2,   2, // 485-487
  11,   2,   2, // 488-490
  11,   2,   2, // 491-493
  11,   2,   2, // 494-496
  39,   2,   2, // 497-499
  24,   2,   2, // 500-502
  11,   2,   2,   2, // 503-506
  7,   2, // 507-508
  5,   2,   2,   2, // 509-512
  7,   2,   2, // 513-515
  7,   2, // 516-517
  7,   2, // 518-519
  7,   2, // 520-521
  7,   2, // 522-523
  7,   2, // 524-525
  7,   2, // 526-527
  8,   2,   2, // 528-530
  8,   2,   2, // 531-533
  8,   2,   2, // 534-536
  7,   2, // 537-538
  7,   2, // 539-540
  7,   2, // 541-542
  8,   2, // 543-544
  5,   2, // 545-546
  9,   2, // 547-548
  5, // 549
  11, // 550
  8,   2, // 551-552
  9,   2, // 553-554
  8,   2, // 555-556
  7,   2, // 557-558
  5,   2,   2, // 559-561
  5, // 562
  11,   2,   2, // 563-565
  6,   2, // 566-567
  8,   2,   2, // 568-570
  8,   2,   2, // 571-573
  9,   2,   2, // 574-576
  8,   2,   2, // 577-579
  7,   2,   2, // 580-582
  7,   2,   2, // 583-585
  6,   2,   2, // 586-588
  5,   2,   2, // 589-591
  5,   2,   2, // 592-594
  6,   2,   2, // 595-597
  7,   2, // 598-599
  7,   2, // 600-601
  7,   2, // 602-603
  7,   2, // 604-605
  7,   2, // 606-607
  7,   2, // 608-609
  6,   2, // 610-611
  1,   1,   1, // 612-614
  1,   1,   1, // 615-617
  3,   1,   1, // 618-620
  6,   1,   1, // 621-623
  1,   1,   1, // 624-626
  3,   1,   1, // 627-629
  2,   1,   1, // 630-632
  23,   1,   1, // 633-635
  15,   1,   1, // 636-638
  5,   1,   1, // 639-641
  5,   1,   1, // 642-644
  8,   1,   1, // 645-647
  33,   1,   1, // 648-650
  27,   1,   1, // 651-653
  5,   1,   1,   1, // 654-657
  44,   1,   1, // 658-660
  32,   1,   1, // 661-663
  1,   1,   1,   1, // 664-667
  3,   1,   1, // 668-670
  2,   2,   1,   1, // 671-674
  3,   3,   1,   1, // 675-678
  2,   1,   1, // 679-681
  3,   1,   1, // 682-684
  2,   2,   1,   1, // 685-688
  3,   3,   1,   1, // 689-692
  3,   1,   1, // 693-695
  3,   3,   1,   1, // 696-699
  3,   3,   1,   1, // 700-703
  3,   1,   1, // 704-706
  4,   4,   1,   1, // 707-710
  4,   4,   1,   1, // 711-714
  2,   1,   1, // 715-717
  3,   1,   1, // 718-720
  3,   1,   1, // 721-723
  6,   1, // 724-725
  3,   1, // 726-727
  1,   1,   1, // 728-730
  2,   1,   1, // 731-733
  3,   1, // 734-735
  4,   1, // 736-737
  4,   1,   1, // 738-740
  4,   1,   1, // 741-743
  4,   1,   1, // 744-746
  3,   1,   1, // 747-749
  1,   1,   1, // 750-752
  2,   1,   1,   1, // 753-756
  1,   1,   1, // 757-759
  1,   1,   1, // 760-762
  1,   1,   1, // 763-765
  1,   1,   1, // 766-768
  1,   1,   1, // 769-771
  2,   1,   1,   1, // 772-775
  2,   1,   1,   1, // 776-779
  1,   1, // 780-781
  1,   1, // 782-783
  6,   1,   1, // 784-786
  1,   1,   1, // 787-789
  1,   1,   1, // 790-792
  3,   1,   1, // 793-795
  6,   1,   1, // 796-798
  1,   1,   1, // 799-801
  3,   1,   1, // 802-804
  2,   1,   1, // 805-807
  68,   1,   1, // 808-810
  36,   1,   1, // 811-813
  5,   1,   1, // 814-816
  5,   1,   1, // 817-819
  8,   1,   1, // 820-822
  33,   1,   1, // 823-825
  27,   1,   1, // 826-828
  5,   1,   1,   1, // 829-832
  44,   1,   1, // 833-835
  32,   1,   1, // 836-838
  1,   1,   1,   1, // 839-842
  3,   1,   1, // 843-845
  2,   2,   1,   1, // 846-849
  3,   3,   1,   1, // 850-853
  2,   1,   1, // 854-856
  3,   1,   1, // 857-859
  2,   2,   1,   1, // 860-863
  3,   3,   1,   1, // 864-867
  3,   1,   1, // 868-870
  3,   3,   1,   1, // 871-874
  3,   3,   1,   1, // 875-878
  3,   1,   1, // 879-881
  4,   4,   1,   1, // 882-885
  4,   4,   1,   1, // 886-889
  2,   1,   1, // 890-892
  3,   1,   1, // 893-895
  3,   1,   1, // 896-898
  6,   1, // 899-900
  3,   1, // 901-902
  1,   1,   1, // 903-905
  2,   1,   1, // 906-908
  3,   1, // 909-910
  4,   1, // 911-912
  4,   1,   1, // 913-915
  4,   1,   1, // 916-918
  4,   1,   1, // 919-921
  3,   1,   1, // 922-924
  1,   1,   1, // 925-927
  2,   1,   1,   1, // 928-931
  1,   1,   1, // 932-934
  1,   1,   1, // 935-937
  1,   1,   1, // 938-940
  1,   1,   1, // 941-943
  1,   1,   1, // 944-946
  1,   1,   1, // 947-949
  2,   1,   1,   1, // 950-953
  2,   1,   1,   1, // 954-957
  1,   1, // 958-959
  1,   1, // 960-961
  6,   1,   1, // 962-964
  0 // End operand cycles
};
extern const unsigned PPCForwardingPaths[] = {
 0, // No itinerary
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 1-3
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 4-6
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 7-8
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 9-11
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 12-14
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 15-16
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 17-19
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 20-22
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 23-25
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 26-28
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 29-31
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 32-34
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 35-37
PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, PPC440ItinerariesBypass::P440_FPR_Bypass, // 38-41
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 42-44
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::NoBypass, // 45-48
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 49-51
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 52-55
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 56-59
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 60-62
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 63-66
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 67-70
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 71-73
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 74-76
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 77-79
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 80-82
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 83-85
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 86-87
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 88-89
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 90-92
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 93-94
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 95-96
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 97-98
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 99-101
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 102-104
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 105-106
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 107-109
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 110-111
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 112-113
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 114-116
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 117-119
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 120-122
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 123-125
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 126-129
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 130-131
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 132-134
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 135-137
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 138-140
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 141-144
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 145-147
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0, // 148-150
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 151-154
PPC440ItinerariesBypass::NoBypass, PPC440ItinerariesBypass::P440_GPR_Bypass,  0,  0, // 155-158
PPC440ItinerariesBypass::P440_GPR_Bypass, PPC440ItinerariesBypass::P440_GPR_Bypass, // 159-160
 0,  0,  0, // 161-163
 0,  0,  0, // 164-166
 0,  0,  0, // 167-169
 0,  0,  0, // 170-172
 0,  0,  0, // 173-175
 0,  0,  0, // 176-178
 0,  0,  0, // 179-181
 0,  0,  0, // 182-184
 0,  0,  0, // 185-187
 0,  0,  0, // 188-190
 0,  0,  0, // 191-193
 0,  0,  0, // 194-196
 0,  0,  0, // 197-199
 0,  0,  0, // 200-202
 0,  0,  0,  0, // 203-206
 0,  0,  0, // 207-209
 0,  0,  0, // 210-212
 0,  0,  0, // 213-215
 0,  0,  0,  0, // 216-219
 0, // 220
 0,  0,  0, // 221-223
 0,  0,  0,  0, // 224-227
 0,  0,  0,  0, // 228-231
 0,  0,  0, // 232-234
 0,  0,  0, // 235-237
 0,  0,  0, // 238-240
 0,  0,  0,  0, // 241-244
 0,  0,  0,  0, // 245-248
 0,  0,  0, // 249-251
 0,  0,  0,  0, // 252-255
 0,  0,  0,  0, // 256-259
 0,  0,  0, // 260-262
 0,  0, // 263-264
 0,  0, // 265-266
 0,  0, // 267-268
 0,  0, // 269-270
 0,  0, // 271-272
 0,  0,  0, // 273-275
 0, // 276
 0,  0,  0, // 277-279
 0,  0, // 280-281
 0,  0, // 282-283
 0,  0,  0, // 284-286
 0,  0,  0, // 287-289
 0,  0,  0, // 290-292
 0,  0,  0, // 293-295
 0,  0,  0,  0, // 296-299
 0, // 300
 0,  0,  0, // 301-303
 0,  0,  0, // 304-306
 0,  0,  0, // 307-309
 0,  0,  0, // 310-312
 0,  0,  0, // 313-315
 0,  0,  0,  0, // 316-319
 0,  0,  0, // 320-322
 0,  0,  0, // 323-325
 0,  0,  0,  0, // 326-329
 0,  0,  0,  0, // 330-333
 0,  0, // 334-335
 0,  0, // 336-337
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 338-340
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 341-343
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 344-345
PPCE500mcItinerariesBypass::E500_CR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 346-348
PPCE500mcItinerariesBypass::E500_CR_Bypass, PPCE500mcItinerariesBypass::E500_CR_Bypass, PPCE500mcItinerariesBypass::E500_CR_Bypass, // 349-351
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 352-353
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 354-355
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 356-358
PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, // 359-361
PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, // 362-364
PPCE500mcItinerariesBypass::E500_CR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, // 365-367
PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, // 368-370
PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, // 371-373
PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_FPR_Bypass, // 374-377
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 378-379
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_CR_Bypass, // 380-383
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 384-386
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 387-388
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 389-390
PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 391-393
PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 394-396
PPCE500mcItinerariesBypass::E500_FPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 397-399
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 400-401
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 402-403
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 404-405
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 406-407
PPCE500mcItinerariesBypass::E500_CR_Bypass, PPCE500mcItinerariesBypass::E500_CR_Bypass, // 408-409
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_CR_Bypass, // 410-411
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_CR_Bypass, // 412-413
PPCE500mcItinerariesBypass::E500_FPR_Bypass, // 414
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 415-416
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_CR_Bypass, // 417-418
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 419-420
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 421-422
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 423-424
PPCE500mcItinerariesBypass::E500_CR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass,  0, // 425-427
PPCE500mcItinerariesBypass::E500_CR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 428-429
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::NoBypass, // 430-432
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 433-434
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 435-436
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 437-439
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 440-442
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 443-445
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 446-448
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 449-451
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 452-454
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 455-457
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 458-459
PPCE500mcItinerariesBypass::NoBypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 460-461
PPCE500mcItinerariesBypass::E500_GPR_Bypass, PPCE500mcItinerariesBypass::E500_GPR_Bypass, // 462-463
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 464-466
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 467-469
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 470-471
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 472-474
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 475-477
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 478-479
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 480-481
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 482-484
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 485-487
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 488-490
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 491-493
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 494-496
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 497-499
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 500-502
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 503-506
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 507-508
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 509-512
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 513-515
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 516-517
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 518-519
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 520-521
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 522-523
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 524-525
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 526-527
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 528-530
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 531-533
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 534-536
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 537-538
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 539-540
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 541-542
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 543-544
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 545-546
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 547-548
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 549
PPCE5500ItinerariesBypass::E5500_FPR_Bypass, // 550
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 551-552
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_CR_Bypass, // 553-554
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 555-556
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 557-558
PPCE5500ItinerariesBypass::E5500_CR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass,  0, // 559-561
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 562
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::NoBypass, // 563-565
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 566-567
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 568-570
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 571-573
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 574-576
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 577-579
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 580-582
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 583-585
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 586-588
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 589-591
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 592-594
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 595-597
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 598-599
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 600-601
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 602-603
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 604-605
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 606-607
PPCE5500ItinerariesBypass::NoBypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 608-609
PPCE5500ItinerariesBypass::E5500_GPR_Bypass, PPCE5500ItinerariesBypass::E5500_GPR_Bypass, // 610-611
 0,  0,  0, // 612-614
 0,  0,  0, // 615-617
 0,  0,  0, // 618-620
 0,  0,  0, // 621-623
 0,  0,  0, // 624-626
 0,  0,  0, // 627-629
 0,  0,  0, // 630-632
 0,  0,  0, // 633-635
 0,  0,  0, // 636-638
 0,  0,  0, // 639-641
 0,  0,  0, // 642-644
 0,  0,  0, // 645-647
 0,  0,  0, // 648-650
 0,  0,  0, // 651-653
 0,  0,  0,  0, // 654-657
 0,  0,  0, // 658-660
 0,  0,  0, // 661-663
 0,  0,  0,  0, // 664-667
 0,  0,  0, // 668-670
 0,  0,  0,  0, // 671-674
 0,  0,  0,  0, // 675-678
 0,  0,  0, // 679-681
 0,  0,  0, // 682-684
 0,  0,  0,  0, // 685-688
 0,  0,  0,  0, // 689-692
 0,  0,  0, // 693-695
 0,  0,  0,  0, // 696-699
 0,  0,  0,  0, // 700-703
 0,  0,  0, // 704-706
 0,  0,  0,  0, // 707-710
 0,  0,  0,  0, // 711-714
 0,  0,  0, // 715-717
 0,  0,  0, // 718-720
 0,  0,  0, // 721-723
 0,  0, // 724-725
 0,  0, // 726-727
 0,  0,  0, // 728-730
 0,  0,  0, // 731-733
 0,  0, // 734-735
 0,  0, // 736-737
 0,  0,  0, // 738-740
 0,  0,  0, // 741-743
 0,  0,  0, // 744-746
 0,  0,  0, // 747-749
 0,  0,  0, // 750-752
 0,  0,  0,  0, // 753-756
 0,  0,  0, // 757-759
 0,  0,  0, // 760-762
 0,  0,  0, // 763-765
 0,  0,  0, // 766-768
 0,  0,  0, // 769-771
 0,  0,  0,  0, // 772-775
 0,  0,  0,  0, // 776-779
 0,  0, // 780-781
 0,  0, // 782-783
 0,  0,  0, // 784-786
 0,  0,  0, // 787-789
 0,  0,  0, // 790-792
 0,  0,  0, // 793-795
 0,  0,  0, // 796-798
 0,  0,  0, // 799-801
 0,  0,  0, // 802-804
 0,  0,  0, // 805-807
 0,  0,  0, // 808-810
 0,  0,  0, // 811-813
 0,  0,  0, // 814-816
 0,  0,  0, // 817-819
 0,  0,  0, // 820-822
 0,  0,  0, // 823-825
 0,  0,  0, // 826-828
 0,  0,  0,  0, // 829-832
 0,  0,  0, // 833-835
 0,  0,  0, // 836-838
 0,  0,  0,  0, // 839-842
 0,  0,  0, // 843-845
 0,  0,  0,  0, // 846-849
 0,  0,  0,  0, // 850-853
 0,  0,  0, // 854-856
 0,  0,  0, // 857-859
 0,  0,  0,  0, // 860-863
 0,  0,  0,  0, // 864-867
 0,  0,  0, // 868-870
 0,  0,  0,  0, // 871-874
 0,  0,  0,  0, // 875-878
 0,  0,  0, // 879-881
 0,  0,  0,  0, // 882-885
 0,  0,  0,  0, // 886-889
 0,  0,  0, // 890-892
 0,  0,  0, // 893-895
 0,  0,  0, // 896-898
 0,  0, // 899-900
 0,  0, // 901-902
 0,  0,  0, // 903-905
 0,  0,  0, // 906-908
 0,  0, // 909-910
 0,  0, // 911-912
 0,  0,  0, // 913-915
 0,  0,  0, // 916-918
 0,  0,  0, // 919-921
 0,  0,  0, // 922-924
 0,  0,  0, // 925-927
 0,  0,  0,  0, // 928-931
 0,  0,  0, // 932-934
 0,  0,  0, // 935-937
 0,  0,  0, // 938-940
 0,  0,  0, // 941-943
 0,  0,  0, // 944-946
 0,  0,  0, // 947-949
 0,  0,  0,  0, // 950-953
 0,  0,  0,  0, // 954-957
 0,  0, // 958-959
 0,  0, // 960-961
 0,  0,  0, // 962-964
 0 // End bypass tables
};

static const llvm::InstrItinerary PPC440Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 1, 6, 1, 4 }, // 1 IIC_IntSimple
  { 1, 1, 6, 4, 7 }, // 2 IIC_IntGeneral
  { 1, 6, 11, 7, 9 }, // 3 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 4 IIC_VecFP
  { 1, 1, 6, 9, 12 }, // 5 IIC_IntCompare
  { 1, 6, 11, 12, 15 }, // 6 IIC_BrCR
  { 1, 11, 16, 15, 17 }, // 7 IIC_LdStDCBF
  { 1, 16, 21, 17, 20 }, // 8 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 9 IIC_IntDivD
  { 1, 21, 26, 20, 23 }, // 10 IIC_IntDivW
  { 1, 26, 35, 23, 26 }, // 11 IIC_FPGeneral
  { 1, 26, 35, 26, 29 }, // 12 IIC_FPAddSub
  { 1, 26, 35, 29, 32 }, // 13 IIC_FPCompare
  { 1, 35, 44, 32, 35 }, // 14 IIC_FPDivD
  { 1, 44, 53, 35, 38 }, // 15 IIC_FPDivS
  { 1, 26, 35, 38, 42 }, // 16 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPSqrtS
  { 1, 11, 16, 42, 45 }, // 19 IIC_LdStICBI
  { 1, 1, 6, 45, 49 }, // 20 IIC_IntISEL
  { 1, 53, 69, 0, 0 }, // 21 IIC_SprISYNC
  { 1, 69, 76, 49, 52 }, // 22 IIC_LdStLWARX
  { 1, 16, 21, 52, 56 }, // 23 IIC_LdStLoadUpd
  { 1, 16, 21, 56, 60 }, // 24 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 25 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 26 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 27 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 28 IIC_LdStLDUX
  { 1, 16, 21, 60, 63 }, // 29 IIC_LdStLFD
  { 1, 11, 16, 63, 67 }, // 30 IIC_LdStLFDU
  { 1, 11, 16, 67, 71 }, // 31 IIC_LdStLFDUX
  { 1, 11, 16, 71, 74 }, // 32 IIC_LdStLHA
  { 1, 11, 16, 74, 77 }, // 33 IIC_LdStLHAU
  { 1, 11, 16, 77, 80 }, // 34 IIC_LdStLHAUX
  { 1, 11, 16, 80, 83 }, // 35 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLWA
  { 1, 6, 11, 83, 86 }, // 37 IIC_BrMCR
  { 1, 6, 11, 86, 88 }, // 38 IIC_SprMFCR
  { 1, 76, 81, 88, 90 }, // 39 IIC_SprMFSPR
  { 1, 6, 11, 90, 93 }, // 40 IIC_IntMFFS
  { 1, 6, 11, 93, 95 }, // 41 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 42 IIC_SprMFCRF
  { 1, 6, 11, 95, 97 }, // 43 IIC_SprMFSR
  { 1, 76, 81, 97, 99 }, // 44 IIC_SprMFTB
  { 1, 16, 21, 99, 102 }, // 45 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 46 IIC_VecGeneral
  { 1, 81, 86, 0, 0 }, // 47 IIC_LdStSync
  { 1, 6, 11, 102, 105 }, // 48 IIC_BrMCRX
  { 1, 76, 81, 105, 107 }, // 49 IIC_SprMTSPR
  { 1, 6, 11, 107, 110 }, // 50 IIC_IntMTFSB0
  { 1, 6, 11, 110, 112 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 1, 76, 81, 112, 114 }, // 53 IIC_SprMTSR
  { 1, 6, 11, 114, 117 }, // 54 IIC_IntMulHW
  { 1, 6, 11, 117, 120 }, // 55 IIC_IntMulHWU
  { 0, 0, 0, 0, 0 }, // 56 IIC_IntMulHD
  { 1, 6, 11, 120, 123 }, // 57 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 58 IIC_VecPerm
  { 1, 11, 16, 123, 126 }, // 59 IIC_LdStSTFD
  { 1, 11, 16, 126, 130 }, // 60 IIC_LdStSTFDU
  { 1, 6, 11, 130, 132 }, // 61 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 62 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 63 IIC_IntRotateD
  { 0, 0, 0, 0, 0 }, // 64 IIC_IntRotateDI
  { 1, 1, 6, 132, 135 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 1, 6, 135, 138 }, // 70 IIC_IntShift
  { 1, 69, 76, 138, 141 }, // 71 IIC_LdStSTWCX
  { 1, 16, 21, 141, 145 }, // 72 IIC_LdStStoreUpd
  { 1, 16, 21, 145, 148 }, // 73 IIC_LdStSTD
  { 1, 69, 76, 148, 151 }, // 74 IIC_LdStSTDCX
  { 1, 16, 21, 151, 155 }, // 75 IIC_LdStSTDU
  { 1, 16, 21, 155, 159 }, // 76 IIC_LdStSTDUX
  { 0, 0, 0, 0, 0 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 1, 6, 11, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 6, 11, 159, 161 }, // 82 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary G3Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 86, 87, 0, 0 }, // 1 IIC_IntSimple
  { 1, 86, 87, 0, 0 }, // 2 IIC_IntGeneral
  { 1, 87, 88, 0, 0 }, // 3 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 4 IIC_VecFP
  { 1, 86, 87, 0, 0 }, // 5 IIC_IntCompare
  { 1, 88, 89, 0, 0 }, // 6 IIC_BrCR
  { 1, 89, 90, 0, 0 }, // 7 IIC_LdStDCBF
  { 1, 90, 91, 0, 0 }, // 8 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 9 IIC_IntDivD
  { 1, 91, 92, 0, 0 }, // 10 IIC_IntDivW
  { 1, 92, 93, 0, 0 }, // 11 IIC_FPGeneral
  { 1, 92, 93, 0, 0 }, // 12 IIC_FPAddSub
  { 1, 92, 93, 0, 0 }, // 13 IIC_FPCompare
  { 1, 93, 94, 0, 0 }, // 14 IIC_FPDivD
  { 1, 94, 95, 0, 0 }, // 15 IIC_FPDivS
  { 1, 95, 96, 0, 0 }, // 16 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPSqrtS
  { 1, 89, 90, 0, 0 }, // 19 IIC_LdStICBI
  { 0, 0, 0, 0, 0 }, // 20 IIC_IntISEL
  { 1, 96, 97, 0, 0 }, // 21 IIC_SprISYNC
  { 1, 89, 90, 0, 0 }, // 22 IIC_LdStLWARX
  { 1, 90, 91, 0, 0 }, // 23 IIC_LdStLoadUpd
  { 1, 90, 91, 0, 0 }, // 24 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 25 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 26 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 27 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 28 IIC_LdStLDUX
  { 1, 90, 91, 0, 0 }, // 29 IIC_LdStLFD
  { 1, 90, 91, 0, 0 }, // 30 IIC_LdStLFDU
  { 1, 90, 91, 0, 0 }, // 31 IIC_LdStLFDUX
  { 1, 90, 91, 0, 0 }, // 32 IIC_LdStLHA
  { 1, 90, 91, 0, 0 }, // 33 IIC_LdStLHAU
  { 1, 90, 91, 0, 0 }, // 34 IIC_LdStLHAUX
  { 1, 97, 98, 0, 0 }, // 35 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLWA
  { 1, 88, 89, 0, 0 }, // 37 IIC_BrMCR
  { 1, 88, 89, 0, 0 }, // 38 IIC_SprMFCR
  { 1, 98, 99, 0, 0 }, // 39 IIC_SprMFSPR
  { 1, 92, 93, 0, 0 }, // 40 IIC_IntMFFS
  { 1, 88, 89, 0, 0 }, // 41 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 42 IIC_SprMFCRF
  { 1, 98, 99, 0, 0 }, // 43 IIC_SprMFSR
  { 1, 98, 99, 0, 0 }, // 44 IIC_SprMFTB
  { 1, 90, 91, 0, 0 }, // 45 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 46 IIC_VecGeneral
  { 1, 89, 90, 0, 0 }, // 47 IIC_LdStSync
  { 1, 88, 89, 0, 0 }, // 48 IIC_BrMCRX
  { 1, 96, 97, 0, 0 }, // 49 IIC_SprMTSPR
  { 1, 99, 100, 0, 0 }, // 50 IIC_IntMTFSB0
  { 1, 88, 89, 0, 0 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 1, 96, 97, 0, 0 }, // 53 IIC_SprMTSR
  { 1, 100, 101, 0, 0 }, // 54 IIC_IntMulHW
  { 1, 101, 102, 0, 0 }, // 55 IIC_IntMulHWU
  { 0, 0, 0, 0, 0 }, // 56 IIC_IntMulHD
  { 1, 102, 103, 0, 0 }, // 57 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 58 IIC_VecPerm
  { 1, 90, 91, 0, 0 }, // 59 IIC_LdStSTFD
  { 1, 90, 91, 0, 0 }, // 60 IIC_LdStSTFDU
  { 1, 96, 97, 0, 0 }, // 61 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 62 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 63 IIC_IntRotateD
  { 0, 0, 0, 0, 0 }, // 64 IIC_IntRotateDI
  { 1, 86, 87, 0, 0 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 86, 87, 0, 0 }, // 70 IIC_IntShift
  { 1, 103, 104, 0, 0 }, // 71 IIC_LdStSTWCX
  { 1, 90, 91, 0, 0 }, // 72 IIC_LdStStoreUpd
  { 0, 0, 0, 0, 0 }, // 73 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 74 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 75 IIC_LdStSTDU
  { 0, 0, 0, 0, 0 }, // 76 IIC_LdStSTDUX
  { 0, 0, 0, 0, 0 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 1, 98, 99, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 104, 105, 0, 0 }, // 82 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary G4Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 105, 106, 0, 0 }, // 1 IIC_IntSimple
  { 1, 105, 106, 0, 0 }, // 2 IIC_IntGeneral
  { 1, 106, 107, 0, 0 }, // 3 IIC_BrB
  { 1, 107, 108, 0, 0 }, // 4 IIC_VecFP
  { 1, 105, 106, 0, 0 }, // 5 IIC_IntCompare
  { 1, 108, 109, 0, 0 }, // 6 IIC_BrCR
  { 1, 109, 110, 0, 0 }, // 7 IIC_LdStDCBF
  { 1, 109, 110, 0, 0 }, // 8 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 9 IIC_IntDivD
  { 1, 110, 111, 0, 0 }, // 10 IIC_IntDivW
  { 1, 111, 112, 0, 0 }, // 11 IIC_FPGeneral
  { 1, 111, 112, 0, 0 }, // 12 IIC_FPAddSub
  { 1, 111, 112, 0, 0 }, // 13 IIC_FPCompare
  { 1, 112, 113, 0, 0 }, // 14 IIC_FPDivD
  { 1, 113, 114, 0, 0 }, // 15 IIC_FPDivS
  { 1, 111, 112, 0, 0 }, // 16 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPSqrtS
  { 1, 109, 110, 0, 0 }, // 19 IIC_LdStICBI
  { 0, 0, 0, 0, 0 }, // 20 IIC_IntISEL
  { 1, 114, 115, 0, 0 }, // 21 IIC_SprISYNC
  { 1, 115, 116, 0, 0 }, // 22 IIC_LdStLWARX
  { 1, 109, 110, 0, 0 }, // 23 IIC_LdStLoadUpd
  { 1, 109, 110, 0, 0 }, // 24 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 25 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 26 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 27 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 28 IIC_LdStLDUX
  { 1, 109, 110, 0, 0 }, // 29 IIC_LdStLFD
  { 1, 109, 110, 0, 0 }, // 30 IIC_LdStLFDU
  { 1, 109, 110, 0, 0 }, // 31 IIC_LdStLFDUX
  { 1, 109, 110, 0, 0 }, // 32 IIC_LdStLHA
  { 1, 109, 110, 0, 0 }, // 33 IIC_LdStLHAU
  { 1, 109, 110, 0, 0 }, // 34 IIC_LdStLHAUX
  { 1, 116, 117, 0, 0 }, // 35 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLWA
  { 1, 108, 109, 0, 0 }, // 37 IIC_BrMCR
  { 1, 108, 109, 0, 0 }, // 38 IIC_SprMFCR
  { 1, 117, 118, 0, 0 }, // 39 IIC_SprMFSPR
  { 1, 118, 119, 0, 0 }, // 40 IIC_IntMFFS
  { 1, 108, 109, 0, 0 }, // 41 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 42 IIC_SprMFCRF
  { 1, 117, 118, 0, 0 }, // 43 IIC_SprMFSR
  { 1, 108, 109, 0, 0 }, // 44 IIC_SprMFTB
  { 1, 109, 110, 0, 0 }, // 45 IIC_LdStStore
  { 1, 119, 120, 0, 0 }, // 46 IIC_VecGeneral
  { 1, 120, 121, 0, 0 }, // 47 IIC_LdStSync
  { 1, 108, 109, 0, 0 }, // 48 IIC_BrMCRX
  { 1, 114, 115, 0, 0 }, // 49 IIC_SprMTSPR
  { 1, 118, 119, 0, 0 }, // 50 IIC_IntMTFSB0
  { 1, 108, 109, 0, 0 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 1, 114, 115, 0, 0 }, // 53 IIC_SprMTSR
  { 1, 121, 122, 0, 0 }, // 54 IIC_IntMulHW
  { 1, 122, 123, 0, 0 }, // 55 IIC_IntMulHWU
  { 0, 0, 0, 0, 0 }, // 56 IIC_IntMulHD
  { 1, 123, 124, 0, 0 }, // 57 IIC_IntMulLI
  { 1, 124, 125, 0, 0 }, // 58 IIC_VecPerm
  { 1, 109, 110, 0, 0 }, // 59 IIC_LdStSTFD
  { 1, 109, 110, 0, 0 }, // 60 IIC_LdStSTFDU
  { 1, 114, 115, 0, 0 }, // 61 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 62 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 63 IIC_IntRotateD
  { 0, 0, 0, 0, 0 }, // 64 IIC_IntRotateDI
  { 1, 105, 106, 0, 0 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 105, 106, 0, 0 }, // 70 IIC_IntShift
  { 1, 125, 126, 0, 0 }, // 71 IIC_LdStSTWCX
  { 1, 109, 110, 0, 0 }, // 72 IIC_LdStStoreUpd
  { 0, 0, 0, 0, 0 }, // 73 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 74 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 75 IIC_LdStSTDU
  { 0, 0, 0, 0, 0 }, // 76 IIC_LdStSTDUX
  { 0, 0, 0, 0, 0 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 1, 126, 127, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 127, 128, 0, 0 }, // 82 IIC_IntTrapW
  { 1, 119, 120, 0, 0 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary G4PlusItineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 128, 129, 0, 0 }, // 1 IIC_IntSimple
  { 1, 128, 129, 0, 0 }, // 2 IIC_IntGeneral
  { 1, 129, 130, 0, 0 }, // 3 IIC_BrB
  { 1, 130, 131, 0, 0 }, // 4 IIC_VecFP
  { 1, 128, 129, 0, 0 }, // 5 IIC_IntCompare
  { 1, 131, 132, 0, 0 }, // 6 IIC_BrCR
  { 1, 132, 133, 0, 0 }, // 7 IIC_LdStDCBF
  { 1, 132, 133, 0, 0 }, // 8 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 9 IIC_IntDivD
  { 1, 133, 134, 0, 0 }, // 10 IIC_IntDivW
  { 1, 134, 135, 0, 0 }, // 11 IIC_FPGeneral
  { 1, 134, 135, 0, 0 }, // 12 IIC_FPAddSub
  { 1, 134, 135, 0, 0 }, // 13 IIC_FPCompare
  { 1, 135, 136, 0, 0 }, // 14 IIC_FPDivD
  { 1, 136, 137, 0, 0 }, // 15 IIC_FPDivS
  { 1, 134, 135, 0, 0 }, // 16 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPSqrtS
  { 1, 137, 138, 0, 0 }, // 19 IIC_LdStICBI
  { 0, 0, 0, 0, 0 }, // 20 IIC_IntISEL
  { 1, 138, 139, 0, 0 }, // 21 IIC_SprISYNC
  { 1, 132, 133, 0, 0 }, // 22 IIC_LdStLWARX
  { 1, 132, 133, 0, 0 }, // 23 IIC_LdStLoadUpd
  { 1, 132, 133, 0, 0 }, // 24 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 25 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 26 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 27 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 28 IIC_LdStLDUX
  { 1, 139, 140, 0, 0 }, // 29 IIC_LdStLFD
  { 1, 139, 140, 0, 0 }, // 30 IIC_LdStLFDU
  { 1, 139, 140, 0, 0 }, // 31 IIC_LdStLFDUX
  { 1, 132, 133, 0, 0 }, // 32 IIC_LdStLHA
  { 1, 132, 133, 0, 0 }, // 33 IIC_LdStLHAU
  { 1, 132, 133, 0, 0 }, // 34 IIC_LdStLHAUX
  { 1, 140, 141, 0, 0 }, // 35 IIC_LdStLMW
  { 1, 132, 133, 0, 0 }, // 36 IIC_LdStLWA
  { 1, 131, 132, 0, 0 }, // 37 IIC_BrMCR
  { 1, 131, 132, 0, 0 }, // 38 IIC_SprMFCR
  { 1, 141, 142, 0, 0 }, // 39 IIC_SprMFSPR
  { 1, 134, 135, 0, 0 }, // 40 IIC_IntMFFS
  { 1, 137, 138, 0, 0 }, // 41 IIC_SprMFMSR
  { 0, 0, 0, 0, 0 }, // 42 IIC_SprMFCRF
  { 1, 141, 142, 0, 0 }, // 43 IIC_SprMFSR
  { 1, 142, 143, 0, 0 }, // 44 IIC_SprMFTB
  { 1, 132, 133, 0, 0 }, // 45 IIC_LdStStore
  { 1, 143, 144, 0, 0 }, // 46 IIC_VecGeneral
  { 1, 144, 145, 0, 0 }, // 47 IIC_LdStSync
  { 1, 131, 132, 0, 0 }, // 48 IIC_BrMCRX
  { 1, 131, 132, 0, 0 }, // 49 IIC_SprMTSPR
  { 1, 134, 135, 0, 0 }, // 50 IIC_IntMTFSB0
  { 1, 131, 132, 0, 0 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 1, 131, 132, 0, 0 }, // 53 IIC_SprMTSR
  { 1, 141, 142, 0, 0 }, // 54 IIC_IntMulHW
  { 1, 141, 142, 0, 0 }, // 55 IIC_IntMulHWU
  { 0, 0, 0, 0, 0 }, // 56 IIC_IntMulHD
  { 1, 137, 138, 0, 0 }, // 57 IIC_IntMulLI
  { 1, 145, 146, 0, 0 }, // 58 IIC_VecPerm
  { 1, 132, 133, 0, 0 }, // 59 IIC_LdStSTFD
  { 1, 132, 133, 0, 0 }, // 60 IIC_LdStSTFDU
  { 1, 128, 129, 0, 0 }, // 61 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 62 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 63 IIC_IntRotateD
  { 0, 0, 0, 0, 0 }, // 64 IIC_IntRotateDI
  { 1, 128, 129, 0, 0 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 146, 147, 0, 0 }, // 70 IIC_IntShift
  { 1, 132, 133, 0, 0 }, // 71 IIC_LdStSTWCX
  { 1, 132, 133, 0, 0 }, // 72 IIC_LdStStoreUpd
  { 1, 132, 133, 0, 0 }, // 73 IIC_LdStSTD
  { 1, 132, 133, 0, 0 }, // 74 IIC_LdStSTDCX
  { 1, 132, 133, 0, 0 }, // 75 IIC_LdStSTDU
  { 1, 132, 133, 0, 0 }, // 76 IIC_LdStSTDUX
  { 0, 0, 0, 0, 0 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 1, 132, 133, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 146, 147, 0, 0 }, // 82 IIC_IntTrapW
  { 1, 147, 148, 0, 0 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary G5Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 148, 149, 0, 0 }, // 1 IIC_IntSimple
  { 1, 148, 149, 0, 0 }, // 2 IIC_IntGeneral
  { 1, 149, 150, 0, 0 }, // 3 IIC_BrB
  { 1, 150, 151, 0, 0 }, // 4 IIC_VecFP
  { 1, 151, 152, 0, 0 }, // 5 IIC_IntCompare
  { 1, 152, 153, 0, 0 }, // 6 IIC_BrCR
  { 1, 153, 154, 0, 0 }, // 7 IIC_LdStDCBF
  { 1, 153, 154, 0, 0 }, // 8 IIC_LdStLoad
  { 1, 154, 155, 0, 0 }, // 9 IIC_IntDivD
  { 1, 155, 156, 0, 0 }, // 10 IIC_IntDivW
  { 1, 156, 157, 0, 0 }, // 11 IIC_FPGeneral
  { 1, 156, 157, 0, 0 }, // 12 IIC_FPAddSub
  { 1, 157, 158, 0, 0 }, // 13 IIC_FPCompare
  { 1, 158, 159, 0, 0 }, // 14 IIC_FPDivD
  { 1, 158, 159, 0, 0 }, // 15 IIC_FPDivS
  { 1, 156, 157, 0, 0 }, // 16 IIC_FPFused
  { 1, 159, 160, 0, 0 }, // 17 IIC_FPSqrtD
  { 1, 159, 160, 0, 0 }, // 18 IIC_FPSqrtS
  { 1, 160, 161, 0, 0 }, // 19 IIC_LdStICBI
  { 0, 0, 0, 0, 0 }, // 20 IIC_IntISEL
  { 1, 160, 161, 0, 0 }, // 21 IIC_SprISYNC
  { 1, 161, 162, 0, 0 }, // 22 IIC_LdStLWARX
  { 1, 153, 154, 0, 0 }, // 23 IIC_LdStLoadUpd
  { 1, 153, 154, 0, 0 }, // 24 IIC_LdStLoadUpdX
  { 1, 153, 154, 0, 0 }, // 25 IIC_LdStLD
  { 1, 161, 162, 0, 0 }, // 26 IIC_LdStLDARX
  { 1, 153, 154, 0, 0 }, // 27 IIC_LdStLDU
  { 1, 153, 154, 0, 0 }, // 28 IIC_LdStLDUX
  { 1, 153, 154, 0, 0 }, // 29 IIC_LdStLFD
  { 1, 162, 163, 0, 0 }, // 30 IIC_LdStLFDU
  { 1, 162, 163, 0, 0 }, // 31 IIC_LdStLFDUX
  { 1, 162, 163, 0, 0 }, // 32 IIC_LdStLHA
  { 1, 162, 163, 0, 0 }, // 33 IIC_LdStLHAU
  { 1, 162, 163, 0, 0 }, // 34 IIC_LdStLHAUX
  { 1, 163, 164, 0, 0 }, // 35 IIC_LdStLMW
  { 1, 162, 163, 0, 0 }, // 36 IIC_LdStLWA
  { 1, 164, 165, 0, 0 }, // 37 IIC_BrMCR
  { 1, 165, 166, 0, 0 }, // 38 IIC_SprMFCR
  { 1, 166, 167, 0, 0 }, // 39 IIC_SprMFSPR
  { 1, 167, 168, 0, 0 }, // 40 IIC_IntMFFS
  { 1, 166, 167, 0, 0 }, // 41 IIC_SprMFMSR
  { 1, 165, 166, 0, 0 }, // 42 IIC_SprMFCRF
  { 1, 153, 154, 0, 0 }, // 43 IIC_SprMFSR
  { 1, 168, 169, 0, 0 }, // 44 IIC_SprMFTB
  { 1, 153, 154, 0, 0 }, // 45 IIC_LdStStore
  { 1, 169, 170, 0, 0 }, // 46 IIC_VecGeneral
  { 1, 170, 171, 0, 0 }, // 47 IIC_LdStSync
  { 1, 171, 172, 0, 0 }, // 48 IIC_BrMCRX
  { 1, 172, 173, 0, 0 }, // 49 IIC_SprMTSPR
  { 1, 156, 157, 0, 0 }, // 50 IIC_IntMTFSB0
  { 1, 153, 154, 0, 0 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 1, 153, 154, 0, 0 }, // 53 IIC_SprMTSR
  { 1, 173, 174, 0, 0 }, // 54 IIC_IntMulHW
  { 1, 173, 174, 0, 0 }, // 55 IIC_IntMulHWU
  { 1, 174, 175, 0, 0 }, // 56 IIC_IntMulHD
  { 1, 175, 176, 0, 0 }, // 57 IIC_IntMulLI
  { 1, 176, 177, 0, 0 }, // 58 IIC_VecPerm
  { 1, 177, 178, 0, 0 }, // 59 IIC_LdStSTFD
  { 1, 177, 178, 0, 0 }, // 60 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprRFI
  { 1, 178, 179, 0, 0 }, // 62 IIC_IntRFID
  { 1, 148, 149, 0, 0 }, // 63 IIC_IntRotateD
  { 1, 148, 149, 0, 0 }, // 64 IIC_IntRotateDI
  { 1, 175, 176, 0, 0 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 148, 149, 0, 0 }, // 70 IIC_IntShift
  { 1, 161, 162, 0, 0 }, // 71 IIC_LdStSTWCX
  { 1, 153, 154, 0, 0 }, // 72 IIC_LdStStoreUpd
  { 1, 153, 154, 0, 0 }, // 73 IIC_LdStSTD
  { 1, 161, 162, 0, 0 }, // 74 IIC_LdStSTDCX
  { 1, 153, 154, 0, 0 }, // 75 IIC_LdStSTDU
  { 1, 153, 154, 0, 0 }, // 76 IIC_LdStSTDUX
  { 1, 179, 180, 0, 0 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 1, 153, 154, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 179, 180, 0, 0 }, // 82 IIC_IntTrapW
  { 1, 180, 181, 0, 0 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary PPCA2Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 181, 182, 161, 164 }, // 1 IIC_IntSimple
  { 1, 181, 182, 164, 167 }, // 2 IIC_IntGeneral
  { 1, 181, 182, 167, 170 }, // 3 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 4 IIC_VecFP
  { 1, 181, 182, 170, 173 }, // 5 IIC_IntCompare
  { 1, 181, 182, 173, 176 }, // 6 IIC_BrCR
  { 1, 181, 182, 176, 179 }, // 7 IIC_LdStDCBF
  { 1, 181, 182, 179, 182 }, // 8 IIC_LdStLoad
  { 1, 181, 182, 182, 185 }, // 9 IIC_IntDivD
  { 1, 181, 182, 185, 188 }, // 10 IIC_IntDivW
  { 1, 182, 183, 188, 191 }, // 11 IIC_FPGeneral
  { 1, 182, 183, 191, 194 }, // 12 IIC_FPAddSub
  { 1, 182, 183, 194, 197 }, // 13 IIC_FPCompare
  { 1, 182, 183, 197, 200 }, // 14 IIC_FPDivD
  { 1, 182, 183, 200, 203 }, // 15 IIC_FPDivS
  { 1, 182, 183, 203, 207 }, // 16 IIC_FPFused
  { 1, 182, 183, 207, 210 }, // 17 IIC_FPSqrtD
  { 1, 182, 183, 210, 213 }, // 18 IIC_FPSqrtS
  { 1, 181, 182, 213, 216 }, // 19 IIC_LdStICBI
  { 1, 181, 182, 216, 220 }, // 20 IIC_IntISEL
  { 1, 181, 182, 220, 221 }, // 21 IIC_SprISYNC
  { 1, 181, 182, 221, 224 }, // 22 IIC_LdStLWARX
  { 1, 181, 182, 224, 228 }, // 23 IIC_LdStLoadUpd
  { 1, 181, 182, 228, 232 }, // 24 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 25 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 26 IIC_LdStLDARX
  { 1, 181, 182, 232, 235 }, // 27 IIC_LdStLDU
  { 1, 181, 182, 235, 238 }, // 28 IIC_LdStLDUX
  { 1, 181, 182, 238, 241 }, // 29 IIC_LdStLFD
  { 1, 181, 182, 241, 245 }, // 30 IIC_LdStLFDU
  { 1, 181, 182, 245, 249 }, // 31 IIC_LdStLFDUX
  { 1, 181, 182, 249, 252 }, // 32 IIC_LdStLHA
  { 1, 181, 182, 252, 256 }, // 33 IIC_LdStLHAU
  { 1, 181, 182, 256, 260 }, // 34 IIC_LdStLHAUX
  { 0, 0, 0, 0, 0 }, // 35 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLWA
  { 1, 181, 182, 260, 263 }, // 37 IIC_BrMCR
  { 1, 181, 182, 263, 265 }, // 38 IIC_SprMFCR
  { 1, 181, 182, 265, 267 }, // 39 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 40 IIC_IntMFFS
  { 1, 181, 182, 267, 269 }, // 41 IIC_SprMFMSR
  { 1, 181, 182, 269, 271 }, // 42 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 43 IIC_SprMFSR
  { 1, 181, 182, 271, 273 }, // 44 IIC_SprMFTB
  { 1, 181, 182, 273, 276 }, // 45 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 46 IIC_VecGeneral
  { 1, 181, 182, 276, 277 }, // 47 IIC_LdStSync
  { 1, 181, 182, 277, 280 }, // 48 IIC_BrMCRX
  { 1, 181, 182, 280, 282 }, // 49 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 50 IIC_IntMTFSB0
  { 1, 181, 182, 282, 284 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMTSR
  { 1, 181, 182, 284, 287 }, // 54 IIC_IntMulHW
  { 1, 181, 182, 287, 290 }, // 55 IIC_IntMulHWU
  { 0, 0, 0, 0, 0 }, // 56 IIC_IntMulHD
  { 1, 181, 182, 290, 293 }, // 57 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 58 IIC_VecPerm
  { 1, 181, 182, 293, 296 }, // 59 IIC_LdStSTFD
  { 1, 181, 182, 296, 300 }, // 60 IIC_LdStSTFDU
  { 1, 181, 182, 300, 301 }, // 61 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 62 IIC_IntRFID
  { 1, 181, 182, 301, 304 }, // 63 IIC_IntRotateD
  { 1, 181, 182, 304, 307 }, // 64 IIC_IntRotateDI
  { 1, 181, 182, 307, 310 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 181, 182, 310, 313 }, // 70 IIC_IntShift
  { 1, 181, 182, 313, 316 }, // 71 IIC_LdStSTWCX
  { 1, 181, 182, 316, 320 }, // 72 IIC_LdStStoreUpd
  { 1, 181, 182, 320, 323 }, // 73 IIC_LdStSTD
  { 1, 181, 182, 323, 326 }, // 74 IIC_LdStSTDCX
  { 1, 181, 182, 326, 330 }, // 75 IIC_LdStSTDU
  { 1, 181, 182, 330, 334 }, // 76 IIC_LdStSTDUX
  { 1, 181, 182, 334, 336 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 181, 182, 336, 338 }, // 82 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary PPCE500mcItineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 183, 185, 338, 341 }, // 1 IIC_IntSimple
  { 1, 183, 185, 341, 344 }, // 2 IIC_IntGeneral
  { 1, 185, 187, 344, 346 }, // 3 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 4 IIC_VecFP
  { 1, 183, 185, 346, 349 }, // 5 IIC_IntCompare
  { 1, 185, 187, 349, 352 }, // 6 IIC_BrCR
  { 1, 187, 189, 352, 354 }, // 7 IIC_LdStDCBF
  { 1, 187, 189, 354, 356 }, // 8 IIC_LdStLoad
  { 0, 0, 0, 0, 0 }, // 9 IIC_IntDivD
  { 1, 189, 192, 356, 359 }, // 10 IIC_IntDivW
  { 1, 192, 194, 359, 362 }, // 11 IIC_FPGeneral
  { 1, 194, 196, 362, 365 }, // 12 IIC_FPAddSub
  { 1, 192, 194, 365, 368 }, // 13 IIC_FPCompare
  { 1, 196, 198, 368, 371 }, // 14 IIC_FPDivD
  { 1, 198, 200, 371, 374 }, // 15 IIC_FPDivS
  { 1, 194, 196, 374, 378 }, // 16 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPSqrtS
  { 1, 187, 189, 378, 380 }, // 19 IIC_LdStICBI
  { 1, 183, 185, 380, 384 }, // 20 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 21 IIC_SprISYNC
  { 1, 200, 202, 384, 387 }, // 22 IIC_LdStLWARX
  { 2, 202, 205, 387, 389 }, // 23 IIC_LdStLoadUpd
  { 2, 202, 205, 389, 391 }, // 24 IIC_LdStLoadUpdX
  { 0, 0, 0, 0, 0 }, // 25 IIC_LdStLD
  { 0, 0, 0, 0, 0 }, // 26 IIC_LdStLDARX
  { 0, 0, 0, 0, 0 }, // 27 IIC_LdStLDU
  { 0, 0, 0, 0, 0 }, // 28 IIC_LdStLDUX
  { 1, 187, 189, 391, 394 }, // 29 IIC_LdStLFD
  { 2, 202, 205, 394, 397 }, // 30 IIC_LdStLFDU
  { 2, 202, 205, 397, 400 }, // 31 IIC_LdStLFDUX
  { 1, 187, 189, 400, 402 }, // 32 IIC_LdStLHA
  { 1, 202, 205, 402, 404 }, // 33 IIC_LdStLHAU
  { 1, 202, 205, 404, 406 }, // 34 IIC_LdStLHAUX
  { 1, 187, 189, 406, 408 }, // 35 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLWA
  { 1, 185, 187, 408, 410 }, // 37 IIC_BrMCR
  { 1, 205, 207, 410, 412 }, // 38 IIC_SprMFCR
  { 1, 183, 185, 412, 414 }, // 39 IIC_SprMFSPR
  { 1, 207, 209, 414, 415 }, // 40 IIC_IntMFFS
  { 1, 209, 211, 415, 417 }, // 41 IIC_SprMFMSR
  { 1, 205, 207, 417, 419 }, // 42 IIC_SprMFCRF
  { 1, 209, 211, 419, 421 }, // 43 IIC_SprMFSR
  { 1, 209, 211, 421, 423 }, // 44 IIC_SprMFTB
  { 1, 187, 189, 423, 425 }, // 45 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 46 IIC_VecGeneral
  { 1, 187, 189, 0, 0 }, // 47 IIC_LdStSync
  { 1, 183, 185, 425, 428 }, // 48 IIC_BrMCRX
  { 1, 183, 185, 428, 430 }, // 49 IIC_SprMTSPR
  { 1, 207, 209, 430, 433 }, // 50 IIC_IntMTFSB0
  { 1, 211, 213, 433, 435 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 1, 213, 215, 435, 437 }, // 53 IIC_SprMTSR
  { 1, 215, 217, 437, 440 }, // 54 IIC_IntMulHW
  { 1, 215, 217, 440, 443 }, // 55 IIC_IntMulHWU
  { 0, 0, 0, 0, 0 }, // 56 IIC_IntMulHD
  { 1, 215, 217, 443, 446 }, // 57 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 58 IIC_VecPerm
  { 1, 187, 189, 446, 449 }, // 59 IIC_LdStSTFD
  { 2, 202, 205, 449, 452 }, // 60 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 62 IIC_IntRFID
  { 0, 0, 0, 0, 0 }, // 63 IIC_IntRotateD
  { 0, 0, 0, 0, 0 }, // 64 IIC_IntRotateDI
  { 1, 183, 185, 452, 455 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 183, 185, 455, 458 }, // 70 IIC_IntShift
  { 1, 187, 189, 458, 460 }, // 71 IIC_LdStSTWCX
  { 2, 202, 205, 460, 462 }, // 72 IIC_LdStStoreUpd
  { 0, 0, 0, 0, 0 }, // 73 IIC_LdStSTD
  { 0, 0, 0, 0, 0 }, // 74 IIC_LdStSTDCX
  { 0, 0, 0, 0, 0 }, // 75 IIC_LdStSTDU
  { 0, 0, 0, 0, 0 }, // 76 IIC_LdStSTDUX
  { 0, 0, 0, 0, 0 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 1, 217, 219, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 219, 221, 462, 464 }, // 82 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary PPCE5500Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 221, 223, 464, 467 }, // 1 IIC_IntSimple
  { 1, 221, 223, 467, 470 }, // 2 IIC_IntGeneral
  { 1, 223, 225, 470, 472 }, // 3 IIC_BrB
  { 0, 0, 0, 0, 0 }, // 4 IIC_VecFP
  { 1, 221, 223, 472, 475 }, // 5 IIC_IntCompare
  { 1, 223, 225, 475, 478 }, // 6 IIC_BrCR
  { 1, 225, 227, 478, 480 }, // 7 IIC_LdStDCBF
  { 1, 225, 227, 480, 482 }, // 8 IIC_LdStLoad
  { 1, 227, 230, 482, 485 }, // 9 IIC_IntDivD
  { 1, 230, 233, 485, 488 }, // 10 IIC_IntDivW
  { 1, 233, 235, 488, 491 }, // 11 IIC_FPGeneral
  { 1, 233, 235, 491, 494 }, // 12 IIC_FPAddSub
  { 1, 233, 235, 494, 497 }, // 13 IIC_FPCompare
  { 1, 235, 237, 497, 500 }, // 14 IIC_FPDivD
  { 1, 237, 239, 500, 503 }, // 15 IIC_FPDivS
  { 1, 233, 235, 503, 507 }, // 16 IIC_FPFused
  { 0, 0, 0, 0, 0 }, // 17 IIC_FPSqrtD
  { 0, 0, 0, 0, 0 }, // 18 IIC_FPSqrtS
  { 1, 225, 227, 507, 509 }, // 19 IIC_LdStICBI
  { 1, 221, 223, 509, 513 }, // 20 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 21 IIC_SprISYNC
  { 1, 239, 241, 513, 516 }, // 22 IIC_LdStLWARX
  { 2, 241, 244, 516, 518 }, // 23 IIC_LdStLoadUpd
  { 2, 241, 244, 518, 520 }, // 24 IIC_LdStLoadUpdX
  { 1, 225, 227, 520, 522 }, // 25 IIC_LdStLD
  { 1, 239, 241, 522, 524 }, // 26 IIC_LdStLDARX
  { 2, 241, 244, 524, 526 }, // 27 IIC_LdStLDU
  { 2, 241, 244, 526, 528 }, // 28 IIC_LdStLDUX
  { 2, 225, 227, 528, 531 }, // 29 IIC_LdStLFD
  { 2, 241, 244, 531, 534 }, // 30 IIC_LdStLFDU
  { 2, 241, 244, 534, 537 }, // 31 IIC_LdStLFDUX
  { 1, 225, 227, 537, 539 }, // 32 IIC_LdStLHA
  { 2, 241, 244, 539, 541 }, // 33 IIC_LdStLHAU
  { 2, 241, 244, 541, 543 }, // 34 IIC_LdStLHAUX
  { 1, 244, 246, 543, 545 }, // 35 IIC_LdStLMW
  { 0, 0, 0, 0, 0 }, // 36 IIC_LdStLWA
  { 1, 223, 225, 545, 547 }, // 37 IIC_BrMCR
  { 1, 246, 248, 547, 549 }, // 38 IIC_SprMFCR
  { 1, 248, 250, 549, 550 }, // 39 IIC_SprMFSPR
  { 1, 233, 235, 550, 551 }, // 40 IIC_IntMFFS
  { 1, 250, 252, 551, 553 }, // 41 IIC_SprMFMSR
  { 1, 246, 248, 553, 555 }, // 42 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 43 IIC_SprMFSR
  { 1, 252, 254, 555, 557 }, // 44 IIC_SprMFTB
  { 1, 225, 227, 557, 559 }, // 45 IIC_LdStStore
  { 0, 0, 0, 0, 0 }, // 46 IIC_VecGeneral
  { 1, 225, 227, 0, 0 }, // 47 IIC_LdStSync
  { 1, 248, 250, 559, 562 }, // 48 IIC_BrMCRX
  { 1, 221, 223, 562, 563 }, // 49 IIC_SprMTSPR
  { 1, 254, 256, 563, 566 }, // 50 IIC_IntMTFSB0
  { 1, 256, 258, 566, 568 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMTSR
  { 1, 258, 261, 568, 571 }, // 54 IIC_IntMulHW
  { 1, 258, 261, 571, 574 }, // 55 IIC_IntMulHWU
  { 1, 261, 264, 574, 577 }, // 56 IIC_IntMulHD
  { 1, 261, 264, 577, 580 }, // 57 IIC_IntMulLI
  { 0, 0, 0, 0, 0 }, // 58 IIC_VecPerm
  { 1, 225, 227, 580, 583 }, // 59 IIC_LdStSTFD
  { 2, 241, 244, 583, 586 }, // 60 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 62 IIC_IntRFID
  { 1, 264, 266, 586, 589 }, // 63 IIC_IntRotateD
  { 1, 221, 223, 589, 592 }, // 64 IIC_IntRotateDI
  { 1, 221, 223, 592, 595 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 264, 266, 595, 598 }, // 70 IIC_IntShift
  { 1, 225, 227, 598, 600 }, // 71 IIC_LdStSTWCX
  { 2, 241, 244, 600, 602 }, // 72 IIC_LdStStoreUpd
  { 1, 225, 227, 602, 604 }, // 73 IIC_LdStSTD
  { 1, 225, 227, 604, 606 }, // 74 IIC_LdStSTDCX
  { 2, 241, 244, 606, 608 }, // 75 IIC_LdStSTDU
  { 2, 241, 244, 608, 610 }, // 76 IIC_LdStSTDUX
  { 0, 0, 0, 0, 0 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 1, 266, 268, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 268, 270, 610, 612 }, // 82 IIC_IntTrapW
  { 0, 0, 0, 0, 0 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary P8Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 270, 272, 612, 615 }, // 1 IIC_IntSimple
  { 1, 270, 272, 615, 618 }, // 2 IIC_IntGeneral
  { 1, 272, 274, 618, 621 }, // 3 IIC_BrB
  { 1, 274, 276, 621, 624 }, // 4 IIC_VecFP
  { 1, 276, 278, 624, 627 }, // 5 IIC_IntCompare
  { 1, 278, 280, 627, 630 }, // 6 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 7 IIC_LdStDCBF
  { 1, 280, 282, 630, 633 }, // 8 IIC_LdStLoad
  { 1, 282, 284, 633, 636 }, // 9 IIC_IntDivD
  { 1, 284, 286, 636, 639 }, // 10 IIC_IntDivW
  { 1, 286, 288, 639, 642 }, // 11 IIC_FPGeneral
  { 1, 286, 288, 642, 645 }, // 12 IIC_FPAddSub
  { 1, 286, 288, 645, 648 }, // 13 IIC_FPCompare
  { 1, 286, 288, 648, 651 }, // 14 IIC_FPDivD
  { 1, 286, 288, 651, 654 }, // 15 IIC_FPDivS
  { 1, 286, 288, 654, 658 }, // 16 IIC_FPFused
  { 1, 286, 288, 658, 661 }, // 17 IIC_FPSqrtD
  { 1, 286, 288, 661, 664 }, // 18 IIC_FPSqrtS
  { 0, 0, 0, 0, 0 }, // 19 IIC_LdStICBI
  { 1, 288, 291, 664, 668 }, // 20 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 21 IIC_SprISYNC
  { 1, 291, 296, 668, 671 }, // 22 IIC_LdStLWARX
  { 1, 296, 300, 671, 675 }, // 23 IIC_LdStLoadUpd
  { 1, 296, 300, 675, 679 }, // 24 IIC_LdStLoadUpdX
  { 1, 280, 282, 679, 682 }, // 25 IIC_LdStLD
  { 1, 300, 307, 682, 685 }, // 26 IIC_LdStLDARX
  { 1, 296, 300, 685, 689 }, // 27 IIC_LdStLDU
  { 1, 296, 300, 689, 693 }, // 28 IIC_LdStLDUX
  { 1, 307, 309, 693, 696 }, // 29 IIC_LdStLFD
  { 1, 309, 313, 696, 700 }, // 30 IIC_LdStLFDU
  { 1, 309, 313, 700, 704 }, // 31 IIC_LdStLFDUX
  { 1, 313, 317, 704, 707 }, // 32 IIC_LdStLHA
  { 1, 317, 322, 707, 711 }, // 33 IIC_LdStLHAU
  { 1, 322, 331, 711, 715 }, // 34 IIC_LdStLHAUX
  { 1, 280, 282, 715, 718 }, // 35 IIC_LdStLMW
  { 1, 331, 335, 718, 721 }, // 36 IIC_LdStLWA
  { 1, 335, 337, 721, 724 }, // 37 IIC_BrMCR
  { 1, 278, 280, 724, 726 }, // 38 IIC_SprMFCR
  { 0, 0, 0, 0, 0 }, // 39 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 40 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 41 IIC_SprMFMSR
  { 1, 278, 280, 726, 728 }, // 42 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 43 IIC_SprMFSR
  { 0, 0, 0, 0, 0 }, // 44 IIC_SprMFTB
  { 1, 337, 340, 728, 731 }, // 45 IIC_LdStStore
  { 1, 274, 276, 731, 734 }, // 46 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 47 IIC_LdStSync
  { 1, 340, 342, 734, 736 }, // 48 IIC_BrMCRX
  { 1, 340, 342, 736, 738 }, // 49 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 50 IIC_IntMTFSB0
  { 0, 0, 0, 0, 0 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMTSR
  { 1, 276, 278, 738, 741 }, // 54 IIC_IntMulHW
  { 1, 276, 278, 741, 744 }, // 55 IIC_IntMulHWU
  { 0, 0, 0, 0, 0 }, // 56 IIC_IntMulHD
  { 1, 276, 278, 744, 747 }, // 57 IIC_IntMulLI
  { 1, 342, 344, 747, 750 }, // 58 IIC_VecPerm
  { 1, 344, 347, 750, 753 }, // 59 IIC_LdStSTFD
  { 1, 347, 352, 753, 757 }, // 60 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 62 IIC_IntRFID
  { 1, 276, 278, 757, 760 }, // 63 IIC_IntRotateD
  { 0, 0, 0, 0, 0 }, // 64 IIC_IntRotateDI
  { 1, 276, 278, 760, 763 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 276, 278, 763, 766 }, // 70 IIC_IntShift
  { 1, 352, 360, 766, 769 }, // 71 IIC_LdStSTWCX
  { 0, 0, 0, 0, 0 }, // 72 IIC_LdStStoreUpd
  { 1, 360, 363, 0, 0 }, // 73 IIC_LdStSTD
  { 1, 352, 360, 769, 772 }, // 74 IIC_LdStSTDCX
  { 1, 363, 367, 772, 776 }, // 75 IIC_LdStSTDU
  { 1, 367, 376, 776, 780 }, // 76 IIC_LdStSTDUX
  { 1, 276, 278, 780, 782 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 276, 278, 782, 784 }, // 82 IIC_IntTrapW
  { 1, 274, 276, 784, 787 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary P7Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 376, 378, 787, 790 }, // 1 IIC_IntSimple
  { 1, 378, 380, 790, 793 }, // 2 IIC_IntGeneral
  { 1, 380, 382, 793, 796 }, // 3 IIC_BrB
  { 1, 382, 384, 796, 799 }, // 4 IIC_VecFP
  { 1, 378, 380, 799, 802 }, // 5 IIC_IntCompare
  { 1, 384, 386, 802, 805 }, // 6 IIC_BrCR
  { 0, 0, 0, 0, 0 }, // 7 IIC_LdStDCBF
  { 1, 386, 388, 805, 808 }, // 8 IIC_LdStLoad
  { 1, 388, 391, 808, 811 }, // 9 IIC_IntDivD
  { 1, 391, 394, 811, 814 }, // 10 IIC_IntDivW
  { 1, 394, 396, 814, 817 }, // 11 IIC_FPGeneral
  { 1, 394, 396, 817, 820 }, // 12 IIC_FPAddSub
  { 1, 394, 396, 820, 823 }, // 13 IIC_FPCompare
  { 1, 394, 396, 823, 826 }, // 14 IIC_FPDivD
  { 1, 394, 396, 826, 829 }, // 15 IIC_FPDivS
  { 1, 394, 396, 829, 833 }, // 16 IIC_FPFused
  { 1, 394, 396, 833, 836 }, // 17 IIC_FPSqrtD
  { 1, 394, 396, 836, 839 }, // 18 IIC_FPSqrtS
  { 0, 0, 0, 0, 0 }, // 19 IIC_LdStICBI
  { 1, 396, 399, 839, 843 }, // 20 IIC_IntISEL
  { 0, 0, 0, 0, 0 }, // 21 IIC_SprISYNC
  { 1, 399, 404, 843, 846 }, // 22 IIC_LdStLWARX
  { 1, 404, 408, 846, 850 }, // 23 IIC_LdStLoadUpd
  { 1, 408, 415, 850, 854 }, // 24 IIC_LdStLoadUpdX
  { 1, 386, 388, 854, 857 }, // 25 IIC_LdStLD
  { 1, 399, 404, 857, 860 }, // 26 IIC_LdStLDARX
  { 1, 404, 408, 860, 864 }, // 27 IIC_LdStLDU
  { 1, 408, 415, 864, 868 }, // 28 IIC_LdStLDUX
  { 1, 386, 388, 868, 871 }, // 29 IIC_LdStLFD
  { 1, 404, 408, 871, 875 }, // 30 IIC_LdStLFDU
  { 1, 404, 408, 875, 879 }, // 31 IIC_LdStLFDUX
  { 1, 415, 419, 879, 882 }, // 32 IIC_LdStLHA
  { 1, 419, 424, 882, 886 }, // 33 IIC_LdStLHAU
  { 1, 424, 432, 886, 890 }, // 34 IIC_LdStLHAUX
  { 1, 386, 388, 890, 893 }, // 35 IIC_LdStLMW
  { 1, 415, 419, 893, 896 }, // 36 IIC_LdStLWA
  { 1, 380, 382, 896, 899 }, // 37 IIC_BrMCR
  { 1, 384, 386, 899, 901 }, // 38 IIC_SprMFCR
  { 0, 0, 0, 0, 0 }, // 39 IIC_SprMFSPR
  { 0, 0, 0, 0, 0 }, // 40 IIC_IntMFFS
  { 0, 0, 0, 0, 0 }, // 41 IIC_SprMFMSR
  { 1, 384, 386, 901, 903 }, // 42 IIC_SprMFCRF
  { 0, 0, 0, 0, 0 }, // 43 IIC_SprMFSR
  { 0, 0, 0, 0, 0 }, // 44 IIC_SprMFTB
  { 1, 432, 435, 903, 906 }, // 45 IIC_LdStStore
  { 1, 435, 437, 906, 909 }, // 46 IIC_VecGeneral
  { 0, 0, 0, 0, 0 }, // 47 IIC_LdStSync
  { 1, 437, 443, 909, 911 }, // 48 IIC_BrMCRX
  { 1, 443, 445, 911, 913 }, // 49 IIC_SprMTSPR
  { 0, 0, 0, 0, 0 }, // 50 IIC_IntMTFSB0
  { 0, 0, 0, 0, 0 }, // 51 IIC_SprMTMSR
  { 0, 0, 0, 0, 0 }, // 52 IIC_SprMTMSRD
  { 0, 0, 0, 0, 0 }, // 53 IIC_SprMTSR
  { 1, 378, 380, 913, 916 }, // 54 IIC_IntMulHW
  { 1, 378, 380, 916, 919 }, // 55 IIC_IntMulHWU
  { 0, 0, 0, 0, 0 }, // 56 IIC_IntMulHD
  { 1, 378, 380, 919, 922 }, // 57 IIC_IntMulLI
  { 1, 445, 447, 922, 925 }, // 58 IIC_VecPerm
  { 1, 447, 450, 925, 928 }, // 59 IIC_LdStSTFD
  { 1, 450, 455, 928, 932 }, // 60 IIC_LdStSTFDU
  { 0, 0, 0, 0, 0 }, // 61 IIC_SprRFI
  { 0, 0, 0, 0, 0 }, // 62 IIC_IntRFID
  { 1, 378, 380, 932, 935 }, // 63 IIC_IntRotateD
  { 0, 0, 0, 0, 0 }, // 64 IIC_IntRotateDI
  { 1, 378, 380, 935, 938 }, // 65 IIC_IntRotate
  { 0, 0, 0, 0, 0 }, // 66 IIC_SprSLBIA
  { 0, 0, 0, 0, 0 }, // 67 IIC_SprSLBIE
  { 0, 0, 0, 0, 0 }, // 68 IIC_SprSLBMFEE
  { 0, 0, 0, 0, 0 }, // 69 IIC_SprSLBMTE
  { 1, 378, 380, 938, 941 }, // 70 IIC_IntShift
  { 1, 399, 404, 941, 944 }, // 71 IIC_LdStSTWCX
  { 0, 0, 0, 0, 0 }, // 72 IIC_LdStStoreUpd
  { 1, 432, 435, 944, 947 }, // 73 IIC_LdStSTD
  { 1, 399, 404, 947, 950 }, // 74 IIC_LdStSTDCX
  { 1, 419, 424, 950, 954 }, // 75 IIC_LdStSTDU
  { 1, 455, 462, 954, 958 }, // 76 IIC_LdStSTDUX
  { 1, 378, 380, 958, 960 }, // 77 IIC_IntTrapD
  { 0, 0, 0, 0, 0 }, // 78 IIC_SprTLBIA
  { 0, 0, 0, 0, 0 }, // 79 IIC_SprTLBIE
  { 0, 0, 0, 0, 0 }, // 80 IIC_SprTLBIEL
  { 0, 0, 0, 0, 0 }, // 81 IIC_SprTLBSYNC
  { 1, 378, 380, 960, 962 }, // 82 IIC_IntTrapW
  { 1, 382, 384, 962, 965 }, // 83 IIC_VecFPCompare
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, Cycles}
extern const llvm::MCWriteProcResEntry PPCWriteProcResTable[] = {
  { 0,  0}, // Invalid
}; // PPCWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry PPCWriteLatencyTable[] = {
  { 0,  0}, // Invalid
}; // PPCWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry PPCReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // PPCReadAdvanceTable

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

static const llvm::MCSchedModel PPC440Model = {
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  5, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  1, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPC440Itineraries};

static const llvm::MCSchedModel G3ItinerariesModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  2, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  G3Itineraries};

static const llvm::MCSchedModel G4ItinerariesModel = {
  MCSchedModel::DefaultIssueWidth,
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  MCSchedModel::DefaultLoadLatency,
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  3, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  G4Itineraries};

static const llvm::MCSchedModel G4PlusItinerariesModel = {
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
  G4PlusItineraries};

static const llvm::MCSchedModel G5Model = {
  4, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  3, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  16, // MispredictPenalty
  0, // PostRAScheduler
  1, // CompleteModel
  5, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  G5Itineraries};

static const llvm::MCSchedModel PPCA2Model = {
  1, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  6, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  13, // MispredictPenalty
  0, // PostRAScheduler
  1, // CompleteModel
  6, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCA2Itineraries};

static const llvm::MCSchedModel PPCE500mcModel = {
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  5, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  7, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE500mcItineraries};

static const llvm::MCSchedModel PPCE5500Model = {
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  6, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  MCSchedModel::DefaultMispredictPenalty,
  0, // PostRAScheduler
  1, // CompleteModel
  8, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  PPCE5500Itineraries};

static const llvm::MCSchedModel P8Model = {
  8, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  60, // LoopMicroOpBufferSize
  3, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  16, // MispredictPenalty
  0, // PostRAScheduler
  1, // CompleteModel
  9, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  P8Itineraries};

static const llvm::MCSchedModel P7Model = {
  6, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  40, // LoopMicroOpBufferSize
  3, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  16, // MispredictPenalty
  0, // PostRAScheduler
  1, // CompleteModel
  10, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  P7Itineraries};

// Sorted (by key) array of itineraries for CPU subtype.
extern const llvm::SubtargetInfoKV PPCProcSchedKV[] = {
  { "440", (const void *)&PPC440Model },
  { "450", (const void *)&PPC440Model },
  { "601", (const void *)&G3ItinerariesModel },
  { "602", (const void *)&G3ItinerariesModel },
  { "603", (const void *)&G3ItinerariesModel },
  { "603e", (const void *)&G3ItinerariesModel },
  { "603ev", (const void *)&G3ItinerariesModel },
  { "604", (const void *)&G3ItinerariesModel },
  { "604e", (const void *)&G3ItinerariesModel },
  { "620", (const void *)&G3ItinerariesModel },
  { "7400", (const void *)&G4ItinerariesModel },
  { "7450", (const void *)&G4PlusItinerariesModel },
  { "750", (const void *)&G4ItinerariesModel },
  { "970", (const void *)&G5Model },
  { "a2", (const void *)&PPCA2Model },
  { "a2q", (const void *)&PPCA2Model },
  { "e500mc", (const void *)&PPCE500mcModel },
  { "e5500", (const void *)&PPCE5500Model },
  { "g3", (const void *)&G3ItinerariesModel },
  { "g4", (const void *)&G4ItinerariesModel },
  { "g4+", (const void *)&G4PlusItinerariesModel },
  { "g5", (const void *)&G5Model },
  { "generic", (const void *)&G3ItinerariesModel },
  { "ppc", (const void *)&G3ItinerariesModel },
  { "ppc64", (const void *)&G5Model },
  { "ppc64le", (const void *)&P8Model },
  { "pwr3", (const void *)&G5Model },
  { "pwr4", (const void *)&G5Model },
  { "pwr5", (const void *)&G5Model },
  { "pwr5x", (const void *)&G5Model },
  { "pwr6", (const void *)&G5Model },
  { "pwr6x", (const void *)&G5Model },
  { "pwr7", (const void *)&P7Model },
  { "pwr8", (const void *)&P8Model }
};
#undef DBGFIELD
static inline MCSubtargetInfo *createPPCMCSubtargetInfoImpl(const Triple &TT, StringRef CPU, StringRef FS) {
  return new MCSubtargetInfo(TT, CPU, FS, PPCFeatureKV, PPCSubTypeKV, 
                      PPCProcSchedKV, PPCWriteProcResTable, PPCWriteLatencyTable, PPCReadAdvanceTable, 
                      PPCStages, PPCOperandCycles, PPCForwardingPaths);
}

} // end llvm namespace
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::PPCSubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  const FeatureBitset& Bits = getFeatureBits();
  if (Bits[PPC::DeprecatedDST]) DeprecatedDST = true;
  if (Bits[PPC::Directive32] && DarwinDirective < PPC::DIR_32) DarwinDirective = PPC::DIR_32;
  if (Bits[PPC::Directive64] && DarwinDirective < PPC::DIR_64) DarwinDirective = PPC::DIR_64;
  if (Bits[PPC::Directive440] && DarwinDirective < PPC::DIR_440) DarwinDirective = PPC::DIR_440;
  if (Bits[PPC::Directive601] && DarwinDirective < PPC::DIR_601) DarwinDirective = PPC::DIR_601;
  if (Bits[PPC::Directive602] && DarwinDirective < PPC::DIR_602) DarwinDirective = PPC::DIR_602;
  if (Bits[PPC::Directive603] && DarwinDirective < PPC::DIR_603) DarwinDirective = PPC::DIR_603;
  if (Bits[PPC::Directive604] && DarwinDirective < PPC::DIR_603) DarwinDirective = PPC::DIR_603;
  if (Bits[PPC::Directive620] && DarwinDirective < PPC::DIR_603) DarwinDirective = PPC::DIR_603;
  if (Bits[PPC::Directive750] && DarwinDirective < PPC::DIR_750) DarwinDirective = PPC::DIR_750;
  if (Bits[PPC::Directive970] && DarwinDirective < PPC::DIR_970) DarwinDirective = PPC::DIR_970;
  if (Bits[PPC::Directive7400] && DarwinDirective < PPC::DIR_7400) DarwinDirective = PPC::DIR_7400;
  if (Bits[PPC::DirectiveA2] && DarwinDirective < PPC::DIR_A2) DarwinDirective = PPC::DIR_A2;
  if (Bits[PPC::DirectiveE500mc] && DarwinDirective < PPC::DIR_E500mc) DarwinDirective = PPC::DIR_E500mc;
  if (Bits[PPC::DirectiveE5500] && DarwinDirective < PPC::DIR_E5500) DarwinDirective = PPC::DIR_E5500;
  if (Bits[PPC::DirectivePwr3] && DarwinDirective < PPC::DIR_PWR3) DarwinDirective = PPC::DIR_PWR3;
  if (Bits[PPC::DirectivePwr4] && DarwinDirective < PPC::DIR_PWR4) DarwinDirective = PPC::DIR_PWR4;
  if (Bits[PPC::DirectivePwr5] && DarwinDirective < PPC::DIR_PWR5) DarwinDirective = PPC::DIR_PWR5;
  if (Bits[PPC::DirectivePwr5x] && DarwinDirective < PPC::DIR_PWR5X) DarwinDirective = PPC::DIR_PWR5X;
  if (Bits[PPC::DirectivePwr6] && DarwinDirective < PPC::DIR_PWR6) DarwinDirective = PPC::DIR_PWR6;
  if (Bits[PPC::DirectivePwr6x] && DarwinDirective < PPC::DIR_PWR6X) DarwinDirective = PPC::DIR_PWR6X;
  if (Bits[PPC::DirectivePwr7] && DarwinDirective < PPC::DIR_PWR7) DarwinDirective = PPC::DIR_PWR7;
  if (Bits[PPC::DirectivePwr8] && DarwinDirective < PPC::DIR_PWR8) DarwinDirective = PPC::DIR_PWR8;
  if (Bits[PPC::Feature64Bit]) Has64BitSupport = true;
  if (Bits[PPC::Feature64BitRegs]) Use64BitRegs = true;
  if (Bits[PPC::FeatureAltivec]) HasAltivec = true;
  if (Bits[PPC::FeatureBPERMD]) HasBPERMD = true;
  if (Bits[PPC::FeatureBookE]) IsBookE = true;
  if (Bits[PPC::FeatureCMPB]) HasCMPB = true;
  if (Bits[PPC::FeatureCRBits]) UseCRBits = true;
  if (Bits[PPC::FeatureDirectMove]) HasDirectMove = true;
  if (Bits[PPC::FeatureE500]) IsE500 = true;
  if (Bits[PPC::FeatureExtDiv]) HasExtDiv = true;
  if (Bits[PPC::FeatureFCPSGN]) HasFCPSGN = true;
  if (Bits[PPC::FeatureFPCVT]) HasFPCVT = true;
  if (Bits[PPC::FeatureFPRND]) HasFPRND = true;
  if (Bits[PPC::FeatureFRE]) HasFRE = true;
  if (Bits[PPC::FeatureFRES]) HasFRES = true;
  if (Bits[PPC::FeatureFRSQRTE]) HasFRSQRTE = true;
  if (Bits[PPC::FeatureFRSQRTES]) HasFRSQRTES = true;
  if (Bits[PPC::FeatureFSqrt]) HasFSQRT = true;
  if (Bits[PPC::FeatureFusion]) HasFusion = true;
  if (Bits[PPC::FeatureHTM]) HasHTM = true;
  if (Bits[PPC::FeatureICBT]) HasICBT = true;
  if (Bits[PPC::FeatureISEL]) HasISEL = true;
  if (Bits[PPC::FeatureInvariantFunctionDescriptors]) HasInvariantFunctionDescriptors = true;
  if (Bits[PPC::FeatureLDBRX]) HasLDBRX = true;
  if (Bits[PPC::FeatureLFIWAX]) HasLFIWAX = true;
  if (Bits[PPC::FeatureMFOCRF]) HasMFOCRF = true;
  if (Bits[PPC::FeatureMFTB]) FeatureMFTB = true;
  if (Bits[PPC::FeatureMSYNC]) HasOnlyMSYNC = true;
  if (Bits[PPC::FeatureP8Altivec]) HasP8Altivec = true;
  if (Bits[PPC::FeatureP8Crypto]) HasP8Crypto = true;
  if (Bits[PPC::FeatureP8Vector]) HasP8Vector = true;
  if (Bits[PPC::FeaturePOPCNTD]) HasPOPCNTD = true;
  if (Bits[PPC::FeaturePPC4xx]) IsPPC4xx = true;
  if (Bits[PPC::FeaturePPC6xx]) IsPPC6xx = true;
  if (Bits[PPC::FeaturePartwordAtomic]) HasPartwordAtomics = true;
  if (Bits[PPC::FeatureQPX]) HasQPX = true;
  if (Bits[PPC::FeatureRecipPrec]) HasRecipPrec = true;
  if (Bits[PPC::FeatureSPE]) HasSPE = true;
  if (Bits[PPC::FeatureSTFIWX]) HasSTFIWX = true;
  if (Bits[PPC::FeatureVSX]) HasVSX = true;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct PPCGenSubtargetInfo : public TargetSubtargetInfo {
  explicit PPCGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS);
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
extern const llvm::SubtargetFeatureKV PPCFeatureKV[];
extern const llvm::SubtargetFeatureKV PPCSubTypeKV[];
extern const llvm::SubtargetInfoKV PPCProcSchedKV[];
extern const llvm::MCWriteProcResEntry PPCWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry PPCWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry PPCReadAdvanceTable[];
extern const llvm::InstrStage PPCStages[];
extern const unsigned PPCOperandCycles[];
extern const unsigned PPCForwardingPaths[];
PPCGenSubtargetInfo::PPCGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo(TT, CPU, FS, makeArrayRef(PPCFeatureKV, 39), makeArrayRef(PPCSubTypeKV, 34), 
                        PPCProcSchedKV, PPCWriteProcResTable, PPCWriteLatencyTable, PPCReadAdvanceTable, 
                        PPCStages, PPCOperandCycles, PPCForwardingPaths) {}

unsigned PPCGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // PPCGenSubtargetInfo::resolveSchedClass
} // end llvm namespace
#endif // GET_SUBTARGETINFO_CTOR

