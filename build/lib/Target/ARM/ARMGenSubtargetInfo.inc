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
namespace ARM {
enum : uint64_t {
  ARMv2 = 0,
  ARMv2a = 1,
  ARMv3 = 2,
  ARMv3m = 3,
  ARMv4 = 4,
  ARMv4t = 5,
  ARMv5t = 6,
  ARMv5te = 7,
  ARMv5tej = 8,
  ARMv6 = 9,
  ARMv6j = 10,
  ARMv6k = 11,
  ARMv6kz = 12,
  ARMv6m = 13,
  ARMv6sm = 14,
  ARMv6t2 = 15,
  ARMv7a = 16,
  ARMv7em = 17,
  ARMv7k = 18,
  ARMv7m = 19,
  ARMv7r = 20,
  ARMv7s = 21,
  ARMv8a = 22,
  ARMv81a = 23,
  ARMv82a = 24,
  FeatureAClass = 25,
  FeatureAvoidMOVsShOp = 26,
  FeatureAvoidPartialCPSR = 27,
  FeatureCRC = 28,
  FeatureCrypto = 29,
  FeatureD16 = 30,
  FeatureDB = 31,
  FeatureDSP = 32,
  FeatureFP16 = 33,
  FeatureFPARMv8 = 34,
  FeatureFullFP16 = 35,
  FeatureHWDiv = 36,
  FeatureHWDivARM = 37,
  FeatureHasRAS = 38,
  FeatureHasSlowFPVMLx = 39,
  FeatureLongCalls = 40,
  FeatureMClass = 41,
  FeatureMP = 42,
  FeatureNEON = 43,
  FeatureNEONForFP = 44,
  FeatureNaClTrap = 45,
  FeatureNoARM = 46,
  FeatureNoMovt = 47,
  FeaturePerfMon = 48,
  FeaturePref32BitThumb = 49,
  FeatureRClass = 50,
  FeatureReserveR9 = 51,
  FeatureSlowFPBrcc = 52,
  FeatureStrictAlign = 53,
  FeatureT2XtPk = 54,
  FeatureThumb2 = 55,
  FeatureTrustZone = 56,
  FeatureVFP2 = 57,
  FeatureVFP3 = 58,
  FeatureVFP4 = 59,
  FeatureVFPOnlySP = 60,
  FeatureVMLxForwarding = 61,
  FeatureVirtualization = 62,
  FeatureZCZeroing = 63,
  HasV4TOps = 64,
  HasV5TEOps = 65,
  HasV5TOps = 66,
  HasV6KOps = 67,
  HasV6MOps = 68,
  HasV6Ops = 69,
  HasV6T2Ops = 70,
  HasV7Ops = 71,
  HasV8Ops = 72,
  HasV8_1aOps = 73,
  HasV8_2aOps = 74,
  IWMMXT = 75,
  IWMMXT2 = 76,
  ModeSoftFloat = 77,
  ModeThumb = 78,
  ProcA5 = 79,
  ProcA7 = 80,
  ProcA8 = 81,
  ProcA9 = 82,
  ProcA12 = 83,
  ProcA15 = 84,
  ProcA17 = 85,
  ProcA35 = 86,
  ProcA53 = 87,
  ProcA57 = 88,
  ProcA72 = 89,
  ProcKrait = 90,
  ProcR4 = 91,
  ProcR5 = 92,
  ProcR7 = 93,
  ProcSwift = 94,
  XScale = 95
};
}
} // end llvm namespace
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV ARMFeatureKV[] = {
  { "32bit", "Prefer 32-bit Thumb instrs", { ARM::FeaturePref32BitThumb }, { } },
  { "a12", "Cortex-A12 ARM processors", { ARM::ProcA12 }, { } },
  { "a15", "Cortex-A15 ARM processors", { ARM::ProcA15 }, { } },
  { "a17", "Cortex-A17 ARM processors", { ARM::ProcA17 }, { } },
  { "a35", "Cortex-A35 ARM processors", { ARM::ProcA35 }, { } },
  { "a5", "Cortex-A5 ARM processors", { ARM::ProcA5 }, { } },
  { "a53", "Cortex-A53 ARM processors", { ARM::ProcA53 }, { } },
  { "a57", "Cortex-A57 ARM processors", { ARM::ProcA57 }, { } },
  { "a7", "Cortex-A7 ARM processors", { ARM::ProcA7 }, { } },
  { "a72", "Cortex-A72 ARM processors", { ARM::ProcA72 }, { } },
  { "a8", "Cortex-A8 ARM processors", { ARM::ProcA8 }, { } },
  { "a9", "Cortex-A9 ARM processors", { ARM::ProcA9 }, { } },
  { "aclass", "Is application profile ('A' series)", { ARM::FeatureAClass }, { } },
  { "armv2", "ARMv2 architecture", { ARM::ARMv2 }, { } },
  { "armv2a", "ARMv2a architecture", { ARM::ARMv2a }, { } },
  { "armv3", "ARMv3 architecture", { ARM::ARMv3 }, { } },
  { "armv3m", "ARMv3m architecture", { ARM::ARMv3m }, { } },
  { "armv4", "ARMv4 architecture", { ARM::ARMv4 }, { } },
  { "armv4t", "ARMv4t architecture", { ARM::ARMv4t }, { ARM::HasV4TOps } },
  { "armv5t", "ARMv5t architecture", { ARM::ARMv5t }, { ARM::HasV5TOps } },
  { "armv5te", "ARMv5te architecture", { ARM::ARMv5te }, { ARM::HasV5TEOps } },
  { "armv5tej", "ARMv5tej architecture", { ARM::ARMv5tej }, { ARM::HasV5TEOps } },
  { "armv6", "ARMv6 architecture", { ARM::ARMv6 }, { ARM::HasV6Ops } },
  { "armv6-m", "ARMv6m architecture", { ARM::ARMv6m }, { ARM::HasV6MOps, ARM::FeatureNoARM, ARM::FeatureDB, ARM::FeatureMClass } },
  { "armv6j", "ARMv7a architecture", { ARM::ARMv6j }, { ARM::ARMv6 } },
  { "armv6k", "ARMv6k architecture", { ARM::ARMv6k }, { ARM::HasV6KOps } },
  { "armv6kz", "ARMv6kz architecture", { ARM::ARMv6kz }, { ARM::HasV6KOps, ARM::FeatureTrustZone } },
  { "armv6s-m", "ARMv6sm architecture", { ARM::ARMv6sm }, { ARM::HasV6MOps, ARM::FeatureNoARM, ARM::FeatureDB, ARM::FeatureMClass } },
  { "armv6t2", "ARMv6t2 architecture", { ARM::ARMv6t2 }, { ARM::HasV6T2Ops, ARM::FeatureDSP } },
  { "armv7-a", "ARMv7a architecture", { ARM::ARMv7a }, { ARM::HasV7Ops, ARM::FeatureNEON, ARM::FeatureDB, ARM::FeatureDSP, ARM::FeatureAClass } },
  { "armv7-m", "ARMv7m architecture", { ARM::ARMv7m }, { ARM::HasV7Ops, ARM::FeatureThumb2, ARM::FeatureNoARM, ARM::FeatureDB, ARM::FeatureHWDiv, ARM::FeatureMClass } },
  { "armv7-r", "ARMv7r architecture", { ARM::ARMv7r }, { ARM::HasV7Ops, ARM::FeatureDB, ARM::FeatureDSP, ARM::FeatureHWDiv, ARM::FeatureRClass } },
  { "armv7e-m", "ARMv7em architecture", { ARM::ARMv7em }, { ARM::HasV7Ops, ARM::FeatureThumb2, ARM::FeatureNoARM, ARM::FeatureDB, ARM::FeatureHWDiv, ARM::FeatureMClass, ARM::FeatureDSP, ARM::FeatureT2XtPk } },
  { "armv7k", "ARMv7a architecture", { ARM::ARMv7k }, { ARM::ARMv7a } },
  { "armv7s", "ARMv7a architecture", { ARM::ARMv7s }, { ARM::ARMv7a } },
  { "armv8-a", "ARMv8a architecture", { ARM::ARMv8a }, { ARM::HasV8Ops, ARM::FeatureAClass, ARM::FeatureDB, ARM::FeatureFPARMv8, ARM::FeatureNEON, ARM::FeatureDSP, ARM::FeatureTrustZone, ARM::FeatureMP, ARM::FeatureVirtualization, ARM::FeatureCrypto, ARM::FeatureCRC } },
  { "armv8.1-a", "ARMv81a architecture", { ARM::ARMv81a }, { ARM::HasV8_1aOps, ARM::FeatureAClass, ARM::FeatureDB, ARM::FeatureFPARMv8, ARM::FeatureNEON, ARM::FeatureDSP, ARM::FeatureTrustZone, ARM::FeatureMP, ARM::FeatureVirtualization, ARM::FeatureCrypto, ARM::FeatureCRC } },
  { "armv8.2-a", "ARMv82a architecture", { ARM::ARMv82a }, { ARM::HasV8_2aOps, ARM::FeatureAClass, ARM::FeatureDB, ARM::FeatureFPARMv8, ARM::FeatureNEON, ARM::FeatureDSP, ARM::FeatureTrustZone, ARM::FeatureMP, ARM::FeatureVirtualization, ARM::FeatureCrypto, ARM::FeatureCRC } },
  { "avoid-movs-shop", "Avoid movs instructions with shifter operand", { ARM::FeatureAvoidMOVsShOp }, { } },
  { "avoid-partial-cpsr", "Avoid CPSR partial update for OOO execution", { ARM::FeatureAvoidPartialCPSR }, { } },
  { "crc", "Enable support for CRC instructions", { ARM::FeatureCRC }, { } },
  { "crypto", "Enable support for Cryptography extensions", { ARM::FeatureCrypto }, { ARM::FeatureNEON } },
  { "d16", "Restrict FP to 16 double registers", { ARM::FeatureD16 }, { } },
  { "db", "Has data barrier (dmb / dsb) instructions", { ARM::FeatureDB }, { } },
  { "dsp", "Supports DSP instructions in ARM and/or Thumb2", { ARM::FeatureDSP }, { } },
  { "fp-armv8", "Enable ARMv8 FP", { ARM::FeatureFPARMv8 }, { ARM::FeatureVFP4 } },
  { "fp-only-sp", "Floating point unit supports single precision only", { ARM::FeatureVFPOnlySP }, { } },
  { "fp16", "Enable half-precision floating point", { ARM::FeatureFP16 }, { } },
  { "fullfp16", "Enable full half-precision floating point", { ARM::FeatureFullFP16 }, { ARM::FeatureFPARMv8 } },
  { "hwdiv", "Enable divide instructions", { ARM::FeatureHWDiv }, { } },
  { "hwdiv-arm", "Enable divide instructions in ARM mode", { ARM::FeatureHWDivARM }, { } },
  { "iwmmxt", "ARMv5te architecture", { ARM::IWMMXT }, { ARM::ARMv5te } },
  { "iwmmxt2", "ARMv5te architecture", { ARM::IWMMXT2 }, { ARM::ARMv5te } },
  { "krait", "Qualcomm ARM processors", { ARM::ProcKrait }, { } },
  { "long-calls", "Generate calls via indirect call instructions", { ARM::FeatureLongCalls }, { } },
  { "mclass", "Is microcontroller profile ('M' series)", { ARM::FeatureMClass }, { } },
  { "mp", "Supports Multiprocessing extension", { ARM::FeatureMP }, { } },
  { "nacl-trap", "NaCl trap", { ARM::FeatureNaClTrap }, { } },
  { "neon", "Enable NEON instructions", { ARM::FeatureNEON }, { ARM::FeatureVFP3 } },
  { "neonfp", "Use NEON for single precision FP", { ARM::FeatureNEONForFP }, { } },
  { "no-movt", "Don't use movt/movw pairs for 32-bit imms", { ARM::FeatureNoMovt }, { } },
  { "noarm", "Does not support ARM mode execution", { ARM::FeatureNoARM }, { ARM::ModeThumb } },
  { "perfmon", "Enable support for Performance Monitor extensions", { ARM::FeaturePerfMon }, { } },
  { "r4", "Cortex-R4 ARM processors", { ARM::ProcR4 }, { } },
  { "r5", "Cortex-R5 ARM processors", { ARM::ProcR5 }, { } },
  { "r7", "Cortex-R7 ARM processors", { ARM::ProcR7 }, { } },
  { "ras", "Has return address stack", { ARM::FeatureHasRAS }, { } },
  { "rclass", "Is realtime profile ('R' series)", { ARM::FeatureRClass }, { } },
  { "reserve-r9", "Reserve R9, making it unavailable as GPR", { ARM::FeatureReserveR9 }, { } },
  { "slow-fp-brcc", "FP compare + branch is slow", { ARM::FeatureSlowFPBrcc }, { } },
  { "slowfpvmlx", "Disable VFP / NEON MAC instructions", { ARM::FeatureHasSlowFPVMLx }, { } },
  { "soft-float", "Use software floating point features.", { ARM::ModeSoftFloat }, { } },
  { "strict-align", "Disallow all unaligned memory access", { ARM::FeatureStrictAlign }, { } },
  { "swift", "Swift ARM processors", { ARM::ProcSwift }, { } },
  { "t2xtpk", "Enable Thumb2 extract and pack instructions", { ARM::FeatureT2XtPk }, { } },
  { "thumb-mode", "Thumb mode", { ARM::ModeThumb }, { } },
  { "thumb2", "Enable Thumb2 instructions", { ARM::FeatureThumb2 }, { } },
  { "trustzone", "Enable support for TrustZone security extensions", { ARM::FeatureTrustZone }, { } },
  { "v4t", "Support ARM v4T instructions", { ARM::HasV4TOps }, { } },
  { "v5t", "Support ARM v5T instructions", { ARM::HasV5TOps }, { ARM::HasV4TOps } },
  { "v5te", "Support ARM v5TE, v5TEj, and v5TExp instructions", { ARM::HasV5TEOps }, { ARM::HasV5TOps } },
  { "v6", "Support ARM v6 instructions", { ARM::HasV6Ops }, { ARM::HasV5TEOps } },
  { "v6k", "Support ARM v6k instructions", { ARM::HasV6KOps }, { ARM::HasV6Ops } },
  { "v6m", "Support ARM v6M instructions", { ARM::HasV6MOps }, { ARM::HasV6Ops } },
  { "v6t2", "Support ARM v6t2 instructions", { ARM::HasV6T2Ops }, { ARM::HasV6MOps, ARM::HasV6KOps, ARM::FeatureThumb2 } },
  { "v7", "Support ARM v7 instructions", { ARM::HasV7Ops }, { ARM::HasV6T2Ops, ARM::FeaturePerfMon } },
  { "v8", "Support ARM v8 instructions", { ARM::HasV8Ops }, { ARM::HasV7Ops } },
  { "v8.1a", "Support ARM v8.1a instructions", { ARM::HasV8_1aOps }, { ARM::HasV8Ops } },
  { "v8.2a", "Support ARM v8.2a instructions", { ARM::HasV8_2aOps }, { ARM::HasV8_1aOps } },
  { "vfp2", "Enable VFP2 instructions", { ARM::FeatureVFP2 }, { } },
  { "vfp3", "Enable VFP3 instructions", { ARM::FeatureVFP3 }, { ARM::FeatureVFP2 } },
  { "vfp4", "Enable VFP4 instructions", { ARM::FeatureVFP4 }, { ARM::FeatureVFP3, ARM::FeatureFP16 } },
  { "virtualization", "Supports Virtualization extension", { ARM::FeatureVirtualization }, { ARM::FeatureHWDiv, ARM::FeatureHWDivARM } },
  { "vmlx-forwarding", "Has multiplier accumulator forwarding", { ARM::FeatureVMLxForwarding }, { } },
  { "xscale", "ARMv5te architecture", { ARM::XScale }, { ARM::ARMv5te } },
  { "zcz", "Has zero-cycle zeroing instructions", { ARM::FeatureZCZeroing }, { } }
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV ARMSubTypeKV[] = {
  { "arm1020e", "Select the arm1020e processor", { ARM::ARMv5te }, { } },
  { "arm1020t", "Select the arm1020t processor", { ARM::ARMv5t }, { } },
  { "arm1022e", "Select the arm1022e processor", { ARM::ARMv5te }, { } },
  { "arm10e", "Select the arm10e processor", { ARM::ARMv5te }, { } },
  { "arm10tdmi", "Select the arm10tdmi processor", { ARM::ARMv5t }, { } },
  { "arm1136j-s", "Select the arm1136j-s processor", { ARM::ARMv6 }, { } },
  { "arm1136jf-s", "Select the arm1136jf-s processor", { ARM::ARMv6, ARM::FeatureVFP2, ARM::FeatureHasSlowFPVMLx }, { } },
  { "arm1156t2-s", "Select the arm1156t2-s processor", { ARM::ARMv6t2 }, { } },
  { "arm1156t2f-s", "Select the arm1156t2f-s processor", { ARM::ARMv6t2, ARM::FeatureVFP2, ARM::FeatureHasSlowFPVMLx }, { } },
  { "arm1176jz-s", "Select the arm1176jz-s processor", { ARM::ARMv6kz }, { } },
  { "arm1176jzf-s", "Select the arm1176jzf-s processor", { ARM::ARMv6kz, ARM::FeatureVFP2, ARM::FeatureHasSlowFPVMLx }, { } },
  { "arm710t", "Select the arm710t processor", { ARM::ARMv4t }, { } },
  { "arm720t", "Select the arm720t processor", { ARM::ARMv4t }, { } },
  { "arm7tdmi", "Select the arm7tdmi processor", { ARM::ARMv4t }, { } },
  { "arm7tdmi-s", "Select the arm7tdmi-s processor", { ARM::ARMv4t }, { } },
  { "arm8", "Select the arm8 processor", { ARM::ARMv4 }, { } },
  { "arm810", "Select the arm810 processor", { ARM::ARMv4 }, { } },
  { "arm9", "Select the arm9 processor", { ARM::ARMv4t }, { } },
  { "arm920", "Select the arm920 processor", { ARM::ARMv4t }, { } },
  { "arm920t", "Select the arm920t processor", { ARM::ARMv4t }, { } },
  { "arm922t", "Select the arm922t processor", { ARM::ARMv4t }, { } },
  { "arm926ej-s", "Select the arm926ej-s processor", { ARM::ARMv5te }, { } },
  { "arm940t", "Select the arm940t processor", { ARM::ARMv4t }, { } },
  { "arm946e-s", "Select the arm946e-s processor", { ARM::ARMv5te }, { } },
  { "arm966e-s", "Select the arm966e-s processor", { ARM::ARMv5te }, { } },
  { "arm968e-s", "Select the arm968e-s processor", { ARM::ARMv5te }, { } },
  { "arm9e", "Select the arm9e processor", { ARM::ARMv5te }, { } },
  { "arm9tdmi", "Select the arm9tdmi processor", { ARM::ARMv4t }, { } },
  { "cortex-a12", "Select the cortex-a12 processor", { ARM::ARMv7a, ARM::ProcA12, ARM::FeatureHasRAS, ARM::FeatureTrustZone, ARM::FeatureVMLxForwarding, ARM::FeatureT2XtPk, ARM::FeatureVFP4, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureAvoidPartialCPSR, ARM::FeatureVirtualization, ARM::FeatureMP }, { } },
  { "cortex-a15", "Select the cortex-a15 processor", { ARM::ARMv7a, ARM::ProcA15, ARM::FeatureHasRAS, ARM::FeatureTrustZone, ARM::FeatureT2XtPk, ARM::FeatureVFP4, ARM::FeatureMP, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureAvoidPartialCPSR, ARM::FeatureVirtualization }, { } },
  { "cortex-a17", "Select the cortex-a17 processor", { ARM::ARMv7a, ARM::ProcA17, ARM::FeatureHasRAS, ARM::FeatureTrustZone, ARM::FeatureMP, ARM::FeatureVMLxForwarding, ARM::FeatureT2XtPk, ARM::FeatureVFP4, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureAvoidPartialCPSR, ARM::FeatureVirtualization }, { } },
  { "cortex-a35", "Select the cortex-a35 processor", { ARM::ARMv8a, ARM::ProcA35, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureT2XtPk, ARM::FeatureCrypto, ARM::FeatureCRC }, { } },
  { "cortex-a5", "Select the cortex-a5 processor", { ARM::ARMv7a, ARM::ProcA5, ARM::FeatureHasRAS, ARM::FeatureTrustZone, ARM::FeatureSlowFPBrcc, ARM::FeatureHasSlowFPVMLx, ARM::FeatureVMLxForwarding, ARM::FeatureT2XtPk, ARM::FeatureMP, ARM::FeatureVFP4 }, { } },
  { "cortex-a53", "Select the cortex-a53 processor", { ARM::ARMv8a, ARM::ProcA53, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureT2XtPk, ARM::FeatureCrypto, ARM::FeatureCRC }, { } },
  { "cortex-a57", "Select the cortex-a57 processor", { ARM::ARMv8a, ARM::ProcA57, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureT2XtPk, ARM::FeatureCrypto, ARM::FeatureCRC }, { } },
  { "cortex-a7", "Select the cortex-a7 processor", { ARM::ARMv7a, ARM::ProcA7, ARM::FeatureHasRAS, ARM::FeatureTrustZone, ARM::FeatureSlowFPBrcc, ARM::FeatureHasSlowFPVMLx, ARM::FeatureVMLxForwarding, ARM::FeatureT2XtPk, ARM::FeatureMP, ARM::FeatureVFP4, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureVirtualization }, { } },
  { "cortex-a72", "Select the cortex-a72 processor", { ARM::ARMv8a, ARM::ProcA72, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureT2XtPk, ARM::FeatureCrypto, ARM::FeatureCRC }, { } },
  { "cortex-a8", "Select the cortex-a8 processor", { ARM::ARMv7a, ARM::ProcA8, ARM::FeatureHasRAS, ARM::FeatureTrustZone, ARM::FeatureSlowFPBrcc, ARM::FeatureHasSlowFPVMLx, ARM::FeatureVMLxForwarding, ARM::FeatureT2XtPk }, { } },
  { "cortex-a9", "Select the cortex-a9 processor", { ARM::ARMv7a, ARM::ProcA9, ARM::FeatureHasRAS, ARM::FeatureTrustZone, ARM::FeatureVMLxForwarding, ARM::FeatureT2XtPk, ARM::FeatureFP16, ARM::FeatureAvoidPartialCPSR, ARM::FeatureMP }, { } },
  { "cortex-m0", "Select the cortex-m0 processor", { ARM::ARMv6m }, { } },
  { "cortex-m0plus", "Select the cortex-m0plus processor", { ARM::ARMv6m }, { } },
  { "cortex-m1", "Select the cortex-m1 processor", { ARM::ARMv6m }, { } },
  { "cortex-m3", "Select the cortex-m3 processor", { ARM::ARMv7m }, { } },
  { "cortex-m4", "Select the cortex-m4 processor", { ARM::ARMv7em, ARM::FeatureVFP4, ARM::FeatureVFPOnlySP, ARM::FeatureD16 }, { } },
  { "cortex-m7", "Select the cortex-m7 processor", { ARM::ARMv7em, ARM::FeatureFPARMv8, ARM::FeatureD16 }, { } },
  { "cortex-r4", "Select the cortex-r4 processor", { ARM::ARMv7r, ARM::ProcR4, ARM::FeatureHasRAS, ARM::FeatureAvoidPartialCPSR, ARM::FeatureT2XtPk }, { } },
  { "cortex-r4f", "Select the cortex-r4f processor", { ARM::ARMv7r, ARM::ProcR4, ARM::FeatureHasRAS, ARM::FeatureSlowFPBrcc, ARM::FeatureHasSlowFPVMLx, ARM::FeatureVFP3, ARM::FeatureD16, ARM::FeatureAvoidPartialCPSR, ARM::FeatureT2XtPk }, { } },
  { "cortex-r5", "Select the cortex-r5 processor", { ARM::ARMv7r, ARM::ProcR5, ARM::FeatureHasRAS, ARM::FeatureVFP3, ARM::FeatureD16, ARM::FeatureSlowFPBrcc, ARM::FeatureHWDivARM, ARM::FeatureHasSlowFPVMLx, ARM::FeatureAvoidPartialCPSR, ARM::FeatureT2XtPk }, { } },
  { "cortex-r7", "Select the cortex-r7 processor", { ARM::ARMv7r, ARM::ProcR7, ARM::FeatureHasRAS, ARM::FeatureVFP3, ARM::FeatureVFPOnlySP, ARM::FeatureD16, ARM::FeatureMP, ARM::FeatureSlowFPBrcc, ARM::FeatureHWDivARM, ARM::FeatureHasSlowFPVMLx, ARM::FeatureAvoidPartialCPSR, ARM::FeatureT2XtPk }, { } },
  { "cyclone", "Select the cyclone processor", { ARM::ARMv8a, ARM::ProcSwift, ARM::FeatureHasRAS, ARM::FeatureNEONForFP, ARM::FeatureT2XtPk, ARM::FeatureVFP4, ARM::FeatureMP, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureAvoidPartialCPSR, ARM::FeatureAvoidMOVsShOp, ARM::FeatureHasSlowFPVMLx, ARM::FeatureCrypto, ARM::FeatureZCZeroing }, { } },
  { "ep9312", "Select the ep9312 processor", { ARM::ARMv4t }, { } },
  { "generic", "Select the generic processor", { }, { } },
  { "iwmmxt", "Select the iwmmxt processor", { ARM::ARMv5te }, { } },
  { "krait", "Select the krait processor", { ARM::ARMv7a, ARM::ProcKrait, ARM::FeatureHasRAS, ARM::FeatureVMLxForwarding, ARM::FeatureT2XtPk, ARM::FeatureFP16, ARM::FeatureAvoidPartialCPSR, ARM::FeatureVFP4, ARM::FeatureHWDiv, ARM::FeatureHWDivARM }, { } },
  { "mpcore", "Select the mpcore processor", { ARM::ARMv6k, ARM::FeatureVFP2, ARM::FeatureHasSlowFPVMLx }, { } },
  { "mpcorenovfp", "Select the mpcorenovfp processor", { ARM::ARMv6k }, { } },
  { "sc000", "Select the sc000 processor", { ARM::ARMv6m }, { } },
  { "sc300", "Select the sc300 processor", { ARM::ARMv7m }, { } },
  { "strongarm", "Select the strongarm processor", { ARM::ARMv4 }, { } },
  { "strongarm110", "Select the strongarm110 processor", { ARM::ARMv4 }, { } },
  { "strongarm1100", "Select the strongarm1100 processor", { ARM::ARMv4 }, { } },
  { "strongarm1110", "Select the strongarm1110 processor", { ARM::ARMv4 }, { } },
  { "swift", "Select the swift processor", { ARM::ARMv7a, ARM::ProcSwift, ARM::FeatureHasRAS, ARM::FeatureNEONForFP, ARM::FeatureT2XtPk, ARM::FeatureVFP4, ARM::FeatureMP, ARM::FeatureHWDiv, ARM::FeatureHWDivARM, ARM::FeatureAvoidPartialCPSR, ARM::FeatureAvoidMOVsShOp, ARM::FeatureHasSlowFPVMLx }, { } },
  { "xscale", "Select the xscale processor", { ARM::ARMv5te }, { } }
};

#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#ifndef NDEBUG
#define DBGFIELD(x) x,
#else
#define DBGFIELD(x)
#endif

// Functional units for "ARMV6Itineraries"
namespace ARMV6ItinerariesFU {
  const unsigned V6_Pipe = 1 << 0;
}

// Functional units for "CortexA9Itineraries"
namespace CortexA9ItinerariesFU {
  const unsigned A9_Issue0 = 1 << 0;
  const unsigned A9_Issue1 = 1 << 1;
  const unsigned A9_Branch = 1 << 2;
  const unsigned A9_ALU0 = 1 << 3;
  const unsigned A9_ALU1 = 1 << 4;
  const unsigned A9_AGU = 1 << 5;
  const unsigned A9_NPipe = 1 << 6;
  const unsigned A9_MUX0 = 1 << 7;
  const unsigned A9_LSUnit = 1 << 8;
  const unsigned A9_DRegsVFP = 1 << 9;
  const unsigned A9_DRegsN = 1 << 10;
}

// Pipeline forwarding pathes for itineraries "CortexA9Itineraries"
namespace CortexA9ItinerariesBypass {
  const unsigned NoBypass = 0;
  const unsigned A9_LdBypass = 1 << 0;
}

// Functional units for "CortexA8Itineraries"
namespace CortexA8ItinerariesFU {
  const unsigned A8_Pipe0 = 1 << 0;
  const unsigned A8_Pipe1 = 1 << 1;
  const unsigned A8_LSPipe = 1 << 2;
  const unsigned A8_NPipe = 1 << 3;
  const unsigned A8_NLSPipe = 1 << 4;
}

extern const llvm::InstrStage ARMStages[] = {
  { 0, 0, 0, llvm::InstrStage::Required }, // No itinerary
  { 1, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 1
  { 2, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 2
  { 3, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 3
  { 3, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 4-5
  { 1, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 6-7
  { 1, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 8-10
  { 29, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 11
  { 15, ARMV6ItinerariesFU::V6_Pipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 12
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 13-14
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 15-16
  { 1, CortexA9ItinerariesFU::A9_Issue0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_Branch, -1, (llvm::InstrStage::ReservationKinds)0 }, // 17-19
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 20-21
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 22-26
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 27-31
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_AGU, 1, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 32-35
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_AGU, 1, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_Branch, -1, (llvm::InstrStage::ReservationKinds)0 }, // 36-40
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_AGU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 41-44
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_AGU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 45-48
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_AGU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 49-53
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_AGU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_LSUnit, 0, (llvm::InstrStage::ReservationKinds)0 }, // 54-57
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_ALU0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 58-59
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 60-63
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 64-67
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_AGU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 68-73
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_ALU0 | CortexA9ItinerariesFU::A9_ALU1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 74-76
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_AGU, 1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 77-80
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 81
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA9ItinerariesFU::A9_ALU0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 82-83
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_AGU, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 84-87
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 7, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 88-92
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 7, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 93-97
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 8, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 98-102
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 103-107
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 26, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 20, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 108-112
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 16, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 10, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 113-117
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 118-122
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 10, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 123-127
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 9, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 128-132
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 10, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 4, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 133-137
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 7, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 138-143
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 8, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 144-149
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 9, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 3, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 150-155
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 11, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 5, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 156-161
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 10, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 4, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 162-167
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 168-173
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 174-179
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 }, // 180-181
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 7, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 182-186
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 6, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 187-191
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 8, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 192-196
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 11, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 197-201
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 12, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 202-206
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 207-211
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 33, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 28, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 212-216
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)0 },   { 18, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)1 },   { 13, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 217-221
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 1, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 222-227
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 228-233
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 3, CortexA9ItinerariesFU::A9_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 }, // 234-239
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 8, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 240-244
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 9, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 3, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 245-249
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 9, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 3, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 250-254
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_DRegsN, 0, (llvm::InstrStage::ReservationKinds)0 },   { 9, CortexA9ItinerariesFU::A9_DRegsVFP, 0, (llvm::InstrStage::ReservationKinds)1 },   { 2, CortexA9ItinerariesFU::A9_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 255-259
  { 1, CortexA9ItinerariesFU::A9_Issue0 | CortexA9ItinerariesFU::A9_Issue1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_MUX0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_AGU, 1, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA9ItinerariesFU::A9_LSUnit, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA9ItinerariesFU::A9_Branch, -1, (llvm::InstrStage::ReservationKinds)0 }, // 260-264
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 265
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 266-268
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 269-270
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 271-272
  { 2, CortexA8ItinerariesFU::A8_Pipe0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 273-274
  { 3, CortexA8ItinerariesFU::A8_Pipe0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 275-276
  { 3, CortexA8ItinerariesFU::A8_Pipe0, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 277-279
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 280-281
  { 2, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 282-283
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 284-286
  { 2, CortexA8ItinerariesFU::A8_Pipe0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 287
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 288-289
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 }, // 290-292
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 293-295
  { 3, CortexA8ItinerariesFU::A8_Pipe0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 296
  { 1, CortexA8ItinerariesFU::A8_Pipe0, -1, (llvm::InstrStage::ReservationKinds)0 }, // 297
  { 2, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 298-299
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 300-301
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 9, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 9, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 302-304
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 305-307
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 7, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 7, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 308-310
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 29, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 29, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 311-313
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 20, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 20, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 314-316
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 317-318
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 19, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 19, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 319-321
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 322-324
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, -1, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 325-327
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 328-330
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 331-333
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 5, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 334-336
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 4, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 337-339
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 340-344
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_LSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 345-347
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_NLSPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 3, CortexA8ItinerariesFU::A8_NPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 348-351
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 11, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 11, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 352-354
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 8, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 8, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 355-357
  { 1, CortexA8ItinerariesFU::A8_Pipe0 | CortexA8ItinerariesFU::A8_Pipe1, 0, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 },   { 1, CortexA8ItinerariesFU::A8_NPipe, 0, (llvm::InstrStage::ReservationKinds)0 },   { 2, CortexA8ItinerariesFU::A8_NLSPipe, -1, (llvm::InstrStage::ReservationKinds)0 }, // 358-361
  { 0, 0, 0, llvm::InstrStage::Required } // End stages
};
extern const unsigned ARMOperandCycles[] = {
  0, // No itinerary
  2,   2, // 1-2
  2,   2,   2, // 3-5
  3,   3,   2,   1, // 6-9
  3,   3,   2,   1, // 10-13
  3,   3,   2,   1, // 14-17
  2,   2, // 18-19
  2,   2,   2, // 20-22
  3,   3,   2,   1, // 23-26
  3,   3,   2,   1, // 27-30
  2,   1, // 31-32
  2,   2, // 33-34
  2, // 35
  2,   2, // 36-37
  3,   2,   1, // 38-40
  3,   2,   1, // 41-43
  5,   2, // 44-45
  5,   2, // 46-47
  3, // 48
  1,   1,   1,   1,   4, // 49-53
  2,   1,   1,   1,   4, // 54-58
  1,   2,   1,   1,   4, // 59-63
  4,   2,   1,   1, // 64-67
  4,   2,   1, // 68-70
  4,   1,   1, // 71-73
  5,   2,   1, // 74-76
  4,   1,   1, // 77-79
  4,   2,   1,   1, // 80-83
  4,   1, // 84-85
  3,   1, // 86-87
  4,   2,   1,   1, // 88-91
  4,   2,   1, // 92-94
  4,   1,   1, // 95-97
  5,   2,   1, // 98-100
  5,   1,   1,   2, // 101-104
  3, // 105
  2, // 106
  4, // 107
  3,   2, // 108-109
  4,   2,   1, // 110-112
  3, // 113
  5, // 114
  2, // 115
  2,   2, // 116-117
  3,   2,   1, // 118-120
  2,   1, // 121-122
  5,   1,   1, // 123-125
  2, // 126
  2,   2, // 127-128
  3,   2,   1, // 129-131
  2,   2,   2, // 132-134
  2,   1,   1, // 135-137
  2,   1,   1, // 138-140
  2,   2,   1, // 141-143
  2,   2,   1, // 144-146
  4,   1,   1,   2, // 147-150
  6,   1,   1,   2, // 151-154
  4,   1,   1, // 155-157
  6,   1,   1, // 158-160
  2, // 161
  2,   2,   1,   1, // 162-165
  2,   2,   1, // 166-168
  2,   2,   1,   1, // 169-172
  2,   2,   1, // 173-175
  2,   1,   1, // 176-178
  2,   2,   1,   1, // 179-182
  2,   2,   1, // 183-185
  2,   2,   1, // 186-188
  2,   2,   1, // 189-191
  1,   1, // 192-193
  2, // 194
  2,   2, // 195-196
  3,   2,   1, // 197-199
  3,   2,   1, // 200-202
  9,   2,   2, // 203-205
  9,   2,   2, // 206-208
  2,   2, // 209-210
  2,   2, // 211-212
  5,   2, // 213-214
  5,   2, // 215-216
  34,   2,   2, // 217-219
  20,   2,   2, // 220-222
  9,   2,   2,   2, // 223-226
  9,   2,   2,   2, // 227-230
  3,   2,   1,   1,   5, // 231-235
  2,   1,   1,   5, // 236-239
  5,   2,   2, // 240-242
  5,   2,   2, // 243-245
  9,   2,   2,   2, // 246-249
  9,   2,   2,   2, // 250-253
  10,   1,   1, // 254-256
  10,   10,   1, // 257-259
  10,   1, // 260-261
  10,   1, // 262-263
  9,   2,   2, // 264-266
  9,   2,   2, // 267-269
  9,   2, // 270-271
  9,   2, // 272-273
  9,   2, // 274-275
  9,   2, // 276-277
  34,   2,   2, // 278-280
  20,   2,   2, // 281-283
  3,   2,   2,   2,   2, // 284-288
  2,   2,   2,   2, // 289-292
  2,   2,   2, // 293-295
  2,   2,   2, // 296-298
  9,   2, // 299-300
  9,   2, // 301-302
  9,   2, // 303-304
  9,   2, // 305-306
  2,   2,   1, // 307-309
  2,   2, // 310-311
  2,   1, // 312-313
  2, // 314
  2,   2, // 315-316
  2,   1, // 317-318
  4,   1, // 319-320
  4,   1, // 321-322
  3,   1, // 323-324
  2, // 325
  2,   1, // 326-327
  2,   1, // 328-329
  2,   1, // 330-331
  3,   3,   2,   1, // 332-335
  1,   1, // 336-337
  2, // 338
  2,   2, // 339-340
  2,   1, // 341-342
  2,   2,   2, // 343-345
  2,   2, // 346-347
  2,   2,   2, // 348-350
  1,   1,   4, // 351-353
  1,   2,   4, // 354-356
  2,   2, // 357-358
  2,   2, // 359-360
  2,   2,   2, // 361-363
  3,   3,   2,   1, // 364-367
  3,   3,   2,   1, // 368-371
  4,   2,   1, // 372-374
  3,   2,   1, // 375-377
  2,   1, // 378-379
  3,   2,   1, // 380-382
  2,   2, // 383-384
  4, // 385
  2, // 386
  3, // 387
  5, // 388
  2,   1, // 389-390
  5,   1,   1,   2, // 391-394
  5,   1,   1, // 395-397
  6,   1,   1,   2, // 398-401
  6,   1,   1, // 402-404
  4,   1,   1, // 405-407
  4,   1,   1,   2, // 408-411
  4,   1,   1, // 412-414
  5,   2,   1, // 415-417
  4,   1,   1, // 418-420
  4,   2,   1,   1, // 421-424
  1,   1, // 425-426
  1,   1, // 427-428
  4, // 429
  2, // 430
  3, // 431
  2, // 432
  2,   1, // 433-434
  2,   2, // 435-436
  2,   2,   2, // 437-439
  2,   2,   2, // 440-442
  2,   2,   2, // 443-445
  2,   2,   1, // 446-448
  3,   3,   2,   1, // 449-452
  5,   1,   1, // 453-455
  4,   1,   1, // 456-458
  5,   1,   1,   2, // 459-462
  5,   1,   1,   2, // 463-466
  5,   1,   1,   2, // 467-470
  4,   1,   1,   2, // 471-474
  5,   1,   1,   2, // 475-478
  5,   1,   1,   2, // 479-482
  6,   1,   1, // 483-485
  6,   1,   1, // 486-488
  6,   1,   1,   2, // 489-492
  4,   1,   1, // 493-495
  5,   2,   1, // 496-498
  4,   1,   1, // 499-501
  4,   1, // 502-503
  4,   1, // 504-505
  3,   1, // 506-507
  5,   2,   1, // 508-510
  4,   1,   1, // 511-513
  4,   1,   1, // 514-516
  4,   1,   1, // 517-519
  4,   1,   1, // 520-522
  4,   1, // 523-524
  5,   2,   1, // 525-527
  4,   1,   1, // 528-530
  4,   2,   1,   1, // 531-534
  4,   2,   1, // 535-537
  4,   2,   1,   1, // 538-541
  4,   2,   1,   1, // 542-545
  4,   2,   1, // 546-548
  4,   1, // 549-550
  4,   1, // 551-552
  4,   1, // 553-554
  4,   2,   1, // 555-557
  4,   1,   1, // 558-560
  4,   1, // 561-562
  4,   2,   1,   1, // 563-566
  1,   1,   1,   1,   4, // 567-571
  2,   1,   1,   1,   4, // 572-576
  1,   2,   1,   1,   4, // 577-581
  1,   1,   4, // 582-584
  1,   2,   4, // 585-587
  2,   1,   1, // 588-590
  2,   1,   1, // 591-593
  2,   2,   1, // 594-596
  2,   2,   1, // 597-599
  2,   1, // 600-601
  2,   1, // 602-603
  2,   2,   1,   1, // 604-607
  2,   2,   1, // 608-610
  2,   2,   1,   1, // 611-614
  2,   2,   1, // 615-617
  2,   1, // 618-619
  2,   1, // 620-621
  2,   1,   1, // 622-624
  2,   2,   1,   1, // 625-628
  2, // 629
  4,   1, // 630-631
  3,   1, // 632-633
  5,   2, // 634-635
  5,   2, // 636-637
  2,   2, // 638-639
  2,   2, // 640-641
  9,   2,   2, // 642-644
  9,   2,   2, // 645-647
  9,   2,   2, // 648-650
  9,   2,   2, // 651-653
  9,   2,   2,   2, // 654-657
  9,   2,   2,   2, // 658-661
  9,   2,   2,   2, // 662-665
  9,   2,   2,   2, // 666-669
  5,   2, // 670-671
  5,   2, // 672-673
  9,   2, // 674-675
  9,   2, // 676-677
  9,   2, // 678-679
  9,   2, // 680-681
  9,   2, // 682-683
  9,   2, // 684-685
  5,   2, // 686-687
  5,   2, // 688-689
  10,   1, // 690-691
  10,   1, // 692-693
  10,   10,   1, // 694-696
  10,   1,   1, // 697-699
  10,   1,   1, // 700-702
  3, // 703
  3, // 704
  3, // 705
  5,   2,   2, // 706-708
  5,   2,   2, // 709-711
  2,   2,   2, // 712-714
  2,   2,   2, // 715-717
  2,   1,   1,   5, // 718-721
  2,   2,   2,   2, // 722-725
  2,   1,   1,   5, // 726-729
  3,   2,   1,   1,   5, // 730-734
  2,   2,   2,   2, // 735-738
  3,   2,   2,   2,   2, // 739-743
  20,   2,   2, // 744-746
  20,   2,   2, // 747-749
  34,   2,   2, // 750-752
  34,   2,   2, // 753-755
  1,   1, // 756-757
  1,   1,   1, // 758-760
  3,   1,   1,   1, // 761-764
  3,   1,   1,   1, // 765-768
  3,   1,   1,   1, // 769-772
  1,   1, // 773-774
  1,   1,   1, // 775-777
  3,   1,   1,   1, // 778-781
  3,   1,   1,   1, // 782-785
  2,   1, // 786-787
  1,   1, // 788-789
  1, // 790
  1,   1, // 791-792
  1,   1,   1, // 793-795
  1,   1,   1, // 796-798
  1,   1, // 799-800
  1,   1, // 801-802
  1, // 803
  1,   1,   1,   1,   3, // 804-808
  2,   1,   1,   1,   3, // 809-813
  1,   2,   1,   1,   3, // 814-818
  4,   3,   1,   1, // 819-822
  4,   3,   1, // 823-825
  4,   1,   1, // 826-828
  5,   1,   1, // 829-831
  3,   3,   1,   1, // 832-835
  3,   3,   1,   1, // 836-839
  3,   1, // 840-841
  2,   1, // 842-843
  3,   2,   1,   1, // 844-847
  3,   2,   1, // 848-850
  3,   1,   1, // 851-853
  4,   1,   1, // 854-856
  4,   1,   1,   1, // 857-860
  1, // 861
  1, // 862
  2, // 863
  1,   1, // 864-865
  2,   1,   1, // 866-868
  3, // 869
  5, // 870
  2, // 871
  1,   1, // 872-873
  2,   1,   1, // 874-876
  1,   1, // 877-878
  4,   1,   1, // 879-881
  1, // 882
  1,   1, // 883-884
  3,   1,   1, // 885-887
  1,   1,   1, // 888-890
  1,   1,   1, // 891-893
  1,   1,   1, // 894-896
  2,   1,   1, // 897-899
  2,   1,   1, // 900-902
  1,   1, // 903-904
  3,   1,   1,   1, // 905-908
  4,   5,   1,   1, // 909-912
  3,   1,   1, // 913-915
  4,   5,   1,   1, // 916-919
  2, // 920
  3,   1,   1,   1, // 921-924
  3,   1,   1, // 925-927
  2,   1,   1,   1, // 928-931
  1,   1,   1, // 932-934
  1,   1,   1, // 935-937
  3,   1,   1,   1, // 938-941
  2,   1,   1, // 942-944
  1,   1,   1, // 945-947
  3,   1,   1, // 948-950
  2,   1, // 951-952
  1, // 953
  1,   1, // 954-955
  1,   1,   1, // 956-958
  1,   1,   1, // 959-961
  6,   3,   2,   1, // 962-965
  6,   3,   2,   1, // 966-969
  4,   2,   1, // 970-972
  5,   2,   2, // 973-975
  6,   2,   2, // 976-978
  4,   2,   1, // 979-981
  5,   2, // 982-983
  6,   2, // 984-985
  4,   2, // 986-987
  4,   2, // 988-989
  4,   1,   1, // 990-992
  4,   2,   2, // 993-995
  3,   1,   1, // 996-998
  4,   1,   1, // 999-1001
  3,   2,   1, // 1002-1004
  3,   2,   2, // 1005-1007
  3,   2,   2, // 1008-1010
  3, // 1011
  3,   2,   2, // 1012-1014
  4,   2,   2, // 1015-1017
  1,   1, // 1018-1019
  1,   1, // 1020-1021
  4,   1, // 1022-1023
  2,   1, // 1024-1025
  4,   1, // 1026-1027
  4,   1, // 1028-1029
  25,   1,   1, // 1030-1032
  15,   1,   1, // 1033-1035
  1,   1, // 1036-1037
  2,   1, // 1038-1039
  2,   1, // 1040-1041
  2,   1,   1, // 1042-1044
  3,   1,   2, // 1045-1047
  9,   1,   1,   1, // 1048-1051
  8,   1,   1,   1, // 1052-1055
  6,   3,   2,   1, // 1056-1059
  8,   4,   2,   1, // 1060-1063
  2,   1, // 1064-1065
  4,   2,   2, // 1066-1068
  2,   1, // 1069-1070
  2,   2,   1,   1, // 1071-1074
  3,   1,   1,   1, // 1075-1078
  3,   2,   1,   1,   1,   1, // 1079-1084
  1,   1, // 1085-1086
  1,   1,   2,   2,   1, // 1087-1091
  1,   1,   2,   1, // 1092-1095
  1,   1,   2,   1, // 1096-1099
  1,   2,   1, // 1100-1102
  1,   1,   1, // 1103-1105
  2,   2,   1, // 1106-1108
  2,   2,   2,   1,   1, // 1109-1113
  3,   3,   1,   1,   1,   1, // 1114-1119
  3,   3,   2,   1,   1,   1,   1,   1, // 1120-1127
  2,   2,   1, // 1128-1130
  2,   2,   2,   1,   1,   1, // 1131-1136
  2,   3,   2,   3,   1, // 1137-1141
  2,   3,   2,   3,   2,   1, // 1142-1147
  3,   3,   4,   1, // 1148-1151
  3,   3,   4,   2,   1,   1, // 1152-1157
  5,   5,   6,   1,   1,   1,   1,   2, // 1158-1165
  5,   5,   6,   2,   1,   1,   1,   1,   1,   2, // 1166-1175
  3,   3,   4,   1, // 1176-1179
  3,   3,   4,   2,   1, // 1180-1184
  2,   2,   3,   3,   1, // 1185-1189
  2,   2,   3,   3,   2,   1,   1, // 1190-1196
  4,   4,   5,   5,   1,   1,   1,   1,   2,   2, // 1197-1206
  4,   4,   5,   5,   2,   1,   1,   1,   1,   1,   2,   2, // 1207-1218
  3,   3,   4,   4,   1, // 1219-1223
  3,   3,   4,   4,   2,   1, // 1224-1229
  2,   1,   1,   1, // 1230-1233
  1,   1,   1,   1, // 1234-1237
  2,   1, // 1238-1239
  1,   1, // 1240-1241
  9,   1,   1,   1, // 1242-1245
  7,   3,   2,   1, // 1246-1249
  6,   3,   2,   2, // 1250-1253
  8,   1,   1,   1, // 1254-1257
  6,   3,   2,   1, // 1258-1261
  8,   4,   2,   1, // 1262-1265
  9,   3,   2,   1, // 1266-1269
  7,   3,   2,   2, // 1270-1273
  1,   1,   1, // 1274-1276
  4,   1, // 1277-1278
  3,   1, // 1279-1280
  2,   1,   1, // 1281-1283
  2,   1, // 1284-1285
  1,   1, // 1286-1287
  6,   1,   1, // 1288-1290
  6,   2,   2, // 1291-1293
  7,   2,   1, // 1294-1296
  5,   1,   1, // 1297-1299
  5,   2,   1, // 1300-1302
  6,   2,   1, // 1303-1305
  7,   2,   2, // 1306-1308
  9,   2,   1, // 1309-1311
  3,   1,   1, // 1312-1314
  6,   3,   1, // 1315-1317
  6,   3,   1, // 1318-1320
  5,   1,   1, // 1321-1323
  4,   1, // 1324-1325
  4,   1,   1, // 1326-1328
  4,   1,   1, // 1329-1331
  9,   2,   2, // 1332-1334
  10,   2,   2, // 1335-1337
  3,   1,   1, // 1338-1340
  4,   1, // 1341-1342
  4,   1, // 1343-1344
  4,   1, // 1345-1346
  4,   1, // 1347-1348
  32,   1, // 1349-1350
  17,   1, // 1351-1352
  1,   1,   1, // 1353-1355
  2,   1,   1,   1,   1, // 1356-1360
  1,   1,   1, // 1361-1363
  1,   1,   1,   1,   2,   2, // 1364-1369
  1,   1,   2,   2,   2,   1, // 1370-1375
  1,   1,   1,   1,   2, // 1376-1380
  1,   1,   2,   2,   1, // 1381-1385
  2,   1,   1,   1,   1,   1,   2,   2, // 1386-1393
  2,   1,   1,   1,   1,   1,   2, // 1394-1400
  1,   1,   1,   1, // 1401-1404
  1,   1,   1,   1, // 1405-1408
  2,   1,   1,   1,   1,   1, // 1409-1414
  1,   1,   1,   1, // 1415-1418
  1,   1,   1,   1,   2,   2, // 1419-1424
  2,   1,   1,   1,   1,   1,   2,   2, // 1425-1432
  1,   1,   1,   1,   2, // 1433-1437
  2,   1,   1,   1,   1,   1,   2, // 1438-1444
  1,   1,   1,   1,   2, // 1445-1449
  2,   1,   1,   1,   1,   1,   2, // 1450-1456
  1,   1,   1,   1,   2,   2, // 1457-1462
  2,   1,   1,   1,   1,   1,   2,   2, // 1463-1470
  1,   1,   1,   1,   2,   2, // 1471-1476
  2,   1,   1,   1,   1,   1,   2,   2, // 1477-1484
  2,   1,   1,   1, // 1485-1488
  1,   1,   1,   1, // 1489-1492
  1,   1, // 1493-1494
  1,   1, // 1495-1496
  3,   2,   1, // 1497-1499
  3,   2,   1, // 1500-1502
  3,   2,   2,   1, // 1503-1506
  4,   2,   2,   3,   1, // 1507-1511
  4,   2,   2,   3,   3,   1, // 1512-1517
  3,   1,   2,   1, // 1518-1521
  3,   1,   2,   2,   1, // 1522-1526
  4,   1,   2,   2,   3,   1, // 1527-1532
  4,   1,   2,   2,   3,   3,   1, // 1533-1539
  4,   1, // 1540-1541
  4,   1, // 1542-1543
  4,   1, // 1544-1545
  4,   1, // 1546-1547
  2,   2,   1,   1, // 1548-1551
  3,   3,   1,   1, // 1552-1555
  4,   4,   1,   1, // 1556-1559
  2,   1,   1, // 1560-1562
  1,   1, // 1563-1564
  1,   1, // 1565-1566
  1, // 1567
  1,   1, // 1568-1569
  1,   1, // 1570-1571
  4,   1, // 1572-1573
  3,   3,   1, // 1574-1576
  1,   1, // 1577-1578
  1, // 1579
  2,   1, // 1580-1581
  2,   1,   1, // 1582-1584
  1,   1, // 1585-1586
  1,   1, // 1587-1588
  3,   1,   1,   1, // 1589-1592
  2,   1, // 1593-1594
  1, // 1595
  1,   1, // 1596-1597
  1,   1, // 1598-1599
  1,   1,   1, // 1600-1602
  1,   1, // 1603-1604
  1,   1,   1, // 1605-1607
  1,   1,   3, // 1608-1610
  1,   1,   3, // 1611-1613
  1,   1, // 1614-1615
  1,   1, // 1616-1617
  1,   1,   1, // 1618-1620
  3,   1,   1,   1, // 1621-1624
  3,   1,   1,   1, // 1625-1628
  2,   1,   1, // 1629-1631
  2,   1,   1, // 1632-1634
  1,   1, // 1635-1636
  3,   1,   1, // 1637-1639
  1,   1, // 1640-1641
  2, // 1642
  2, // 1643
  3, // 1644
  5, // 1645
  2,   1, // 1646-1647
  4,   1,   1,   1, // 1648-1651
  4,   1,   1, // 1652-1654
  4,   5,   1,   1, // 1655-1658
  4,   5,   1,   1, // 1659-1662
  3,   1,   1, // 1663-1665
  3,   1,   1,   1, // 1666-1669
  3,   1,   1, // 1670-1672
  4,   1,   1, // 1673-1675
  4,   1,   1, // 1676-1678
  4,   3,   1,   1, // 1679-1682
  2,   1, // 1683-1684
  2,   1, // 1685-1686
  2, // 1687
  2, // 1688
  3, // 1689
  1, // 1690
  2,   1, // 1691-1692
  1,   1, // 1693-1694
  1,   1,   1, // 1695-1697
  1,   1,   1, // 1698-1700
  1,   1,   1, // 1701-1703
  3,   1,   1, // 1704-1706
  3,   1,   1,   1, // 1707-1710
  4,   1,   1, // 1711-1713
  3,   1,   1, // 1714-1716
  4,   1,   1,   1, // 1717-1720
  4,   1,   1,   1, // 1721-1724
  4,   1,   1,   1, // 1725-1728
  3,   1,   1,   1, // 1729-1732
  4,   1,   1,   1, // 1733-1736
  4,   1,   1,   1, // 1737-1740
  4,   5,   1,   1, // 1741-1744
  4,   5,   1,   1, // 1745-1748
  4,   5,   1,   1, // 1749-1752
  4,   1,   1, // 1753-1755
  5,   1,   1, // 1756-1758
  3,   1,   1, // 1759-1761
  4,   1, // 1762-1763
  3,   1, // 1764-1765
  2,   1, // 1766-1767
  4,   1,   1, // 1768-1770
  4,   1,   1, // 1771-1773
  3,   1,   1, // 1774-1776
  4,   1,   1, // 1777-1779
  3,   1,   1, // 1780-1782
  4,   1, // 1783-1784
  5,   1,   1, // 1785-1787
  4,   1,   1, // 1788-1790
  4,   3,   1,   1, // 1791-1794
  4,   3,   1, // 1795-1797
  4,   3,   1,   1, // 1798-1801
  3,   2,   1,   1, // 1802-1805
  3,   2,   1, // 1806-1808
  4,   1, // 1809-1810
  3,   1, // 1811-1812
  4,   1, // 1813-1814
  4,   3,   1, // 1815-1817
  3,   3,   1,   1, // 1818-1821
  3,   3,   1, // 1822-1824
  3,   3,   1,   1, // 1825-1828
  1,   1,   1,   1,   3, // 1829-1833
  2,   1,   1,   1,   3, // 1834-1838
  1,   2,   1,   1,   3, // 1839-1843
  1,   1,   3, // 1844-1846
  1,   1,   3, // 1847-1849
  1,   1,   1, // 1850-1852
  1,   1,   1, // 1853-1855
  1,   1,   1, // 1856-1858
  1,   1,   1, // 1859-1861
  1,   1, // 1862-1863
  1,   1, // 1864-1865
  3,   1,   1,   1, // 1866-1869
  3,   1,   1, // 1870-1872
  2,   1,   1,   1, // 1873-1876
  2,   1,   1, // 1877-1879
  1,   1, // 1880-1881
  1,   1, // 1882-1883
  1,   1,   1, // 1884-1886
  3,   1,   1,   1, // 1887-1890
  2, // 1891
  3,   1, // 1892-1893
  2,   1, // 1894-1895
  3,   1,   1, // 1896-1898
  3,   2,   1, // 1899-1901
  3,   2,   2, // 1902-1904
  3,   2,   2, // 1905-1907
  3, // 1908
  3,   2,   2, // 1909-1911
  4,   2,   2, // 1912-1914
  4,   2,   2, // 1915-1917
  4,   2,   2, // 1918-1920
  4,   2,   1, // 1921-1923
  4,   2,   1, // 1924-1926
  6,   2, // 1927-1928
  5,   2, // 1929-1930
  3,   1,   1, // 1931-1933
  4,   1,   1, // 1934-1936
  4,   1,   1, // 1937-1939
  3,   2,   1, // 1940-1942
  2,   1,   1, // 1943-1945
  3,   1,   2, // 1946-1948
  2,   1, // 1949-1950
  2,   1, // 1951-1952
  6,   3,   2,   1, // 1953-1956
  6,   3,   2,   1, // 1957-1960
  5,   2, // 1961-1962
  6,   2, // 1963-1964
  4,   2, // 1965-1966
  4,   2, // 1967-1968
  5,   2,   2, // 1969-1971
  6,   2,   2, // 1972-1974
  4,   2,   1, // 1975-1977
  4,   2,   1, // 1978-1980
  6,   3,   1, // 1981-1983
  6,   3,   1, // 1984-1986
  4,   1, // 1987-1988
  4,   1, // 1989-1990
  4,   2,   2, // 1991-1993
  4,   2,   2, // 1994-1996
  4,   1,   1, // 1997-1999
  4,   1,   1, // 2000-2002
  5,   2, // 2003-2004
  6,   2, // 2005-2006
  4,   2,   2, // 2007-2009
  3,   1,   1, // 2010-2012
  4,   1,   1, // 2013-2015
  4,   2,   2, // 2016-2018
  3,   2,   1, // 2019-2021
  3,   1,   2,   1, // 2022-2025
  3,   2,   2,   1, // 2026-2029
  3,   1,   2,   2,   1, // 2030-2034
  4,   2,   2,   3,   1, // 2035-2039
  4,   1,   2,   2,   3,   1, // 2040-2045
  4,   2,   2,   3,   3,   1, // 2046-2051
  4,   1,   2,   2,   3,   3,   1, // 2052-2058
  2,   2,   1,   1, // 2059-2062
  3,   3,   1,   1, // 2063-2066
  4,   4,   1,   1, // 2067-2070
  1,   1, // 2071-2072
  1,   1, // 2073-2074
  1,   1, // 2075-2076
  1,   1, // 2077-2078
  4,   2,   1, // 2079-2081
  5,   2,   2, // 2082-2084
  6,   2,   2, // 2085-2087
  4,   2,   1, // 2088-2090
  4,   1,   1, // 2091-2093
  5,   1,   1, // 2094-2096
  4,   1,   1, // 2097-2099
  9,   2,   2, // 2100-2102
  10,   2,   2, // 2103-2105
  6,   2,   2, // 2106-2108
  7,   2,   1, // 2109-2111
  5,   1,   1, // 2112-2114
  5,   2,   1, // 2115-2117
  6,   2,   1, // 2118-2120
  7,   2,   2, // 2121-2123
  5,   2,   2, // 2124-2126
  6,   2,   2, // 2127-2129
  9,   2,   1, // 2130-2132
  6,   1,   1, // 2133-2135
  9,   1,   1,   1, // 2136-2139
  8,   1,   1,   1, // 2140-2143
  9,   1,   1,   1, // 2144-2147
  7,   3,   2,   1, // 2148-2151
  6,   3,   2,   2, // 2152-2155
  8,   1,   1,   1, // 2156-2159
  6,   3,   2,   1, // 2160-2163
  8,   4,   2,   1, // 2164-2167
  9,   3,   2,   1, // 2168-2171
  7,   3,   2,   2, // 2172-2175
  6,   3,   2,   1, // 2176-2179
  8,   4,   2,   1, // 2180-2183
  4,   1, // 2184-2185
  2,   1, // 2186-2187
  4,   1, // 2188-2189
  4,   1, // 2190-2191
  6,   2, // 2192-2193
  5,   2, // 2194-2195
  4,   1, // 2196-2197
  4,   1, // 2198-2199
  4,   1, // 2200-2201
  4,   1, // 2202-2203
  4,   1, // 2204-2205
  4,   1, // 2206-2207
  1,   1, // 2208-2209
  1,   1, // 2210-2211
  3, // 2212
  3,   2,   1, // 2213-2215
  4,   1, // 2216-2217
  3,   1, // 2218-2219
  4,   1, // 2220-2221
  2,   1, // 2222-2223
  2,   1, // 2224-2225
  1,   1, // 2226-2227
  2,   1, // 2228-2229
  1,   1, // 2230-2231
  3,   1,   1, // 2232-2234
  2,   1,   1, // 2235-2237
  1,   1,   1, // 2238-2240
  1,   1,   1, // 2241-2243
  2,   1, // 2244-2245
  2,   1, // 2246-2247
  1, // 2248
  1, // 2249
  1, // 2250
  2,   1, // 2251-2252
  1,   1, // 2253-2254
  1,   1, // 2255-2256
  1,   1, // 2257-2258
  1,   1,   1,   1, // 2259-2262
  1,   1,   1,   1, // 2263-2266
  1,   1,   1,   1, // 2267-2270
  2,   1,   1,   1, // 2271-2274
  1,   1,   1,   1, // 2275-2278
  2,   1,   1,   1, // 2279-2282
  1,   1, // 2283-2284
  1,   1,   1, // 2285-2287
  1,   2,   1, // 2288-2290
  1,   1,   2,   1, // 2291-2294
  1,   1,   2,   1, // 2295-2298
  1,   1,   2,   1, // 2299-2302
  1,   1,   2,   2,   1, // 2303-2307
  1,   1,   2,   1, // 2308-2311
  2,   2,   1, // 2312-2314
  2,   3,   2,   3,   1, // 2315-2319
  2,   2,   2,   1,   1,   1, // 2320-2325
  2,   3,   2,   3,   2,   1, // 2326-2331
  3,   3,   4,   1, // 2332-2335
  3,   3,   4,   1, // 2336-2339
  3,   3,   4,   2,   1, // 2340-2344
  3,   3,   4,   2,   1, // 2345-2349
  3,   3,   4,   4,   1, // 2350-2354
  3,   3,   4,   4,   1, // 2355-2359
  3,   3,   4,   4,   2,   1, // 2360-2365
  3,   3,   4,   4,   2,   1, // 2366-2371
  2,   1, // 2372-2373
  3,   1,   1,   1, // 2374-2377
  2,   2,   1,   1, // 2378-2381
  3,   2,   1,   1,   1,   1, // 2382-2387
  2,   2,   1, // 2388-2390
  3,   3,   1,   1,   1,   1, // 2391-2396
  3,   3,   2,   1,   1,   1,   1,   1, // 2397-2404
  2,   2,   2,   1,   1, // 2405-2409
  3,   3,   2,   1,   1,   1,   1,   1, // 2410-2417
  3,   3,   4,   1, // 2418-2421
  5,   5,   6,   1,   1,   1,   1,   2, // 2422-2429
  3,   3,   4,   2,   1,   1, // 2430-2435
  5,   5,   6,   2,   1,   1,   1,   1,   1,   2, // 2436-2445
  3,   3,   4,   2,   1,   1, // 2446-2451
  5,   5,   6,   2,   1,   1,   1,   1,   1,   2, // 2452-2461
  2,   2,   3,   3,   1, // 2462-2466
  4,   4,   5,   5,   1,   1,   1,   1,   2,   2, // 2467-2476
  2,   2,   3,   3,   2,   1,   1, // 2477-2483
  4,   4,   5,   5,   2,   1,   1,   1,   1,   1,   2,   2, // 2484-2495
  2,   2,   3,   3,   2,   1,   1, // 2496-2502
  4,   4,   5,   5,   2,   1,   1,   1,   1,   1,   2,   2, // 2503-2514
  1,   1,   1, // 2515-2517
  1,   1,   1,   1, // 2518-2521
  1,   2,   1, // 2522-2524
  1,   1,   2,   1, // 2525-2528
  1,   1,   1,   1,   2, // 2529-2533
  1,   1,   2,   2,   1, // 2534-2538
  2,   1,   1,   1,   1,   1,   2, // 2539-2545
  1,   1,   1,   1,   2,   2, // 2546-2551
  1,   1,   2,   2,   2,   1, // 2552-2557
  2,   1,   1,   1,   1,   1,   2,   2, // 2558-2565
  1,   1,   1,   1, // 2566-2569
  1,   2,   1, // 2570-2572
  1,   1,   1,   1,   2,   2, // 2573-2578
  2,   1,   1,   1,   1,   1,   2,   2, // 2579-2586
  1,   2,   1, // 2587-2589
  1,   1,   1,   1,   2, // 2590-2594
  2,   1,   1,   1,   1,   1,   2, // 2595-2601
  1,   1,   1,   1,   2,   2, // 2602-2607
  2,   1,   1,   1,   1,   1,   2,   2, // 2608-2615
  1,   1,   1, // 2616-2618
  2,   1,   1,   1,   1, // 2619-2623
  1,   1,   1,   1, // 2624-2627
  2,   1,   1,   1,   1,   1, // 2628-2633
  1,   1,   1,   1,   2, // 2634-2638
  2,   1,   1,   1,   1,   1,   2, // 2639-2645
  1,   1,   1,   1,   2,   2, // 2646-2651
  2,   1,   1,   1,   1,   1,   2,   2, // 2652-2659
  15,   1,   1, // 2660-2662
  17,   1, // 2663-2664
  25,   1,   1, // 2665-2667
  32,   1, // 2668-2669
  2,   2, // 2670-2671
  2,   2,   2, // 2672-2674
  2,   2,   1,   1, // 2675-2678
  2,   2,   1,   1, // 2679-2682
  2,   2,   1,   1, // 2683-2686
  2,   2, // 2687-2688
  2,   2,   2, // 2689-2691
  2,   2,   1,   1, // 2692-2695
  2,   2,   1,   1, // 2696-2699
  2,   1, // 2700-2701
  2,   2, // 2702-2703
  2, // 2704
  2,   2, // 2705-2706
  2,   1,   1, // 2707-2709
  2,   1,   1, // 2710-2712
  4,   1, // 2713-2714
  7,   1, // 2715-2716
  20, // 2717
  1,   1,   1,   1,   3, // 2718-2722
  2,   1,   1,   1,   3, // 2723-2727
  1,   2,   1,   1,   3, // 2728-2732
  3,   2,   1,   1, // 2733-2736
  3,   2,   1, // 2737-2739
  3,   1,   1, // 2740-2742
  4,   1,   1, // 2743-2745
  3,   1,   1, // 2746-2748
  3,   2,   1,   1, // 2749-2752
  3,   1, // 2753-2754
  4,   1, // 2755-2756
  3,   2,   1,   1, // 2757-2760
  3,   2,   1, // 2761-2763
  3,   1,   1, // 2764-2766
  4,   1,   1, // 2767-2769
  6,   1,   1,   4, // 2770-2773
  2, // 2774
  1, // 2775
  3,   1, // 2776-2777
  2,   1, // 2778-2779
  2,   1,   1, // 2780-2782
  3, // 2783
  5, // 2784
  2, // 2785
  1,   1, // 2786-2787
  1,   1,   1, // 2788-2790
  1,   1, // 2791-2792
  6,   1,   1, // 2793-2795
  1, // 2796
  1,   1, // 2797-2798
  1,   1,   1, // 2799-2801
  2,   2,   2, // 2802-2804
  3,   1,   1, // 2805-2807
  3,   1,   1, // 2808-2810
  2,   2,   1, // 2811-2813
  2,   2,   1, // 2814-2816
  2,   2, // 2817-2818
  6,   1,   1,   4, // 2819-2822
  6,   6,   1,   1, // 2823-2826
  5,   1,   1, // 2827-2829
  6,   6,   1,   1, // 2830-2833
  2, // 2834
  2,   3,   1,   1, // 2835-2838
  2,   3,   1, // 2839-2841
  2,   3,   1,   1, // 2842-2845
  3,   1,   1, // 2846-2848
  3,   1,   1, // 2849-2851
  2,   3,   1,   1, // 2852-2855
  2,   3,   1, // 2856-2858
  3,   1,   1, // 2859-2861
  2,   2,   1, // 2862-2864
  1,   1, // 2865-2866
  2, // 2867
  2,   2, // 2868-2869
  2,   1,   1, // 2870-2872
  2,   1,   1, // 2873-2875
  6,   3,   2,   1, // 2876-2879
  6,   3,   2,   1, // 2880-2883
  4,   2,   1, // 2884-2886
  5,   2,   2, // 2887-2889
  6,   2,   2, // 2890-2892
  4,   2,   1, // 2893-2895
  5,   2, // 2896-2897
  6,   2, // 2898-2899
  4,   2, // 2900-2901
  4,   2, // 2902-2903
  9,   1,   1, // 2904-2906
  4,   2,   1, // 2907-2909
  3,   1,   1, // 2910-2912
  7,   1,   1, // 2913-2915
  3,   2,   1, // 2916-2918
  3,   2,   2, // 2919-2921
  3,   2,   2, // 2922-2924
  3, // 2925
  3,   2,   2, // 2926-2928
  4,   2,   2, // 2929-2931
  4,   1, // 2932-2933
  1,   1, // 2934-2935
  5,   1, // 2936-2937
  7,   1, // 2938-2939
  29,   1,   1, // 2940-2942
  20,   1,   1, // 2943-2945
  2,   1, // 2946-2947
  2,   1, // 2948-2949
  3,   1, // 2950-2951
  2,   1,   1, // 2952-2954
  3,   1,   1, // 2955-2957
  19,   2,   1,   1, // 2958-2961
  7,   2,   1,   1, // 2962-2965
  9,   3,   2,   2, // 2966-2969
  10,   3,   2,   2, // 2970-2973
  20,   1, // 2974-2975
  4,   2,   1, // 2976-2978
  2,   1, // 2979-2980
  2,   2,   1,   1, // 2981-2984
  3,   1,   1,   1, // 2985-2988
  3,   2,   1,   1,   1,   1, // 2989-2994
  2,   1, // 2995-2996
  2,   2,   3,   3,   1, // 2997-3001
  2,   2,   2,   1, // 3002-3005
  2,   2,   3,   1, // 3006-3009
  2,   2,   1, // 3010-3012
  2,   2,   1, // 3013-3015
  2,   2,   1, // 3016-3018
  2,   2,   2,   1,   1, // 3019-3023
  3,   3,   1,   1,   1,   1, // 3024-3029
  3,   3,   2,   1,   1,   1,   1,   1, // 3030-3037
  2,   2,   1, // 3038-3040
  2,   2,   2,   1,   1,   1, // 3041-3046
  2,   2,   3,   3,   1, // 3047-3051
  2,   2,   3,   3,   2,   1, // 3052-3057
  2,   2,   3,   1, // 3058-3061
  2,   2,   3,   2,   1,   1, // 3062-3067
  4,   4,   5,   1,   1,   1,   1,   2, // 3068-3075
  4,   4,   5,   2,   1,   1,   1,   1,   1,   2, // 3076-3085
  3,   3,   4,   1, // 3086-3089
  3,   3,   4,   2,   1, // 3090-3094
  2,   2,   3,   3,   1, // 3095-3099
  2,   2,   3,   3,   2,   1,   1, // 3100-3106
  4,   4,   5,   5,   1,   1,   1,   1,   2,   2, // 3107-3116
  4,   4,   5,   5,   2,   1,   1,   1,   1,   1,   2,   2, // 3117-3128
  3,   3,   4,   4,   1, // 3129-3133
  3,   3,   4,   4,   2,   1, // 3134-3139
  2,   1,   1,   1,   2, // 3140-3144
  1,   1,   1,   2, // 3145-3148
  2,   1, // 3149-3150
  2,   1, // 3151-3152
  19,   2,   1,   1, // 3153-3156
  7,   3,   2,   1, // 3157-3160
  6,   3,   2,   2, // 3161-3164
  7,   2,   1,   1, // 3165-3168
  9,   3,   2,   2, // 3169-3172
  10,   3,   2,   2, // 3173-3176
  9,   3,   2,   1, // 3177-3180
  7,   3,   2,   2, // 3181-3184
  2,   1,   1, // 3185-3187
  4,   1, // 3188-3189
  2,   1, // 3190-3191
  20,   20,   1, // 3192-3194
  20,   1, // 3195-3196
  2,   1, // 3197-3198
  11,   1,   1, // 3199-3201
  6,   2,   2, // 3202-3204
  7,   2,   1, // 3205-3207
  7,   1,   1, // 3208-3210
  5,   2,   1, // 3211-3213
  6,   2,   1, // 3214-3216
  7,   2,   2, // 3217-3219
  9,   2,   1, // 3220-3222
  4,   1,   1, // 3223-3225
  7,   3,   1, // 3226-3228
  6,   3,   1, // 3229-3231
  5,   2,   2, // 3232-3234
  4,   1, // 3235-3236
  5,   1,   1, // 3237-3239
  4,   1,   1, // 3240-3242
  9,   2,   2, // 3243-3245
  10,   2,   2, // 3246-3248
  3,   1,   1, // 3249-3251
  8,   1, // 3252-3253
  7,   1, // 3254-3255
  8,   1, // 3256-3257
  7,   1, // 3258-3259
  29,   1, // 3260-3261
  19,   1, // 3262-3263
  1,   1,   1, // 3264-3266
  2,   1,   1,   1,   1, // 3267-3271
  1,   1,   1, // 3272-3274
  1,   1,   1,   1,   2,   2, // 3275-3280
  2,   2,   3,   3,   2,   1, // 3281-3286
  1,   1,   1,   1,   2, // 3287-3291
  2,   2,   3,   2,   1, // 3292-3296
  2,   1,   1,   1,   1,   1,   2,   2, // 3297-3304
  2,   1,   1,   1,   1,   1,   2, // 3305-3311
  1,   1,   1,   1, // 3312-3315
  1,   1,   1,   1, // 3316-3319
  2,   1,   1,   1,   1,   1, // 3320-3325
  1,   1,   1,   1, // 3326-3329
  1,   1,   1,   1,   2,   2, // 3330-3335
  2,   1,   1,   1,   1,   1,   2,   2, // 3336-3343
  1,   1,   1,   1,   2, // 3344-3348
  2,   1,   1,   1,   1,   1,   2, // 3349-3355
  1,   1,   1,   1,   2, // 3356-3360
  2,   1,   1,   1,   1,   1,   2, // 3361-3367
  1,   1,   1,   1,   2,   2, // 3368-3373
  2,   1,   1,   1,   1,   1,   2,   2, // 3374-3381
  1,   1,   1,   1,   2,   2, // 3382-3387
  2,   1,   1,   1,   1,   1,   2,   2, // 3388-3395
  2,   1,   1,   1,   1, // 3396-3400
  1,   1,   1,   1, // 3401-3404
  1,   1, // 3405-3406
  1,   1, // 3407-3408
  3,   2,   1, // 3409-3411
  3,   2,   1, // 3412-3414
  3,   2,   2,   1, // 3415-3418
  4,   2,   2,   3,   1, // 3419-3423
  4,   2,   2,   3,   3,   1, // 3424-3429
  3,   1,   2,   1, // 3430-3433
  3,   1,   2,   2,   1, // 3434-3438
  4,   1,   2,   2,   3,   1, // 3439-3444
  4,   1,   2,   2,   3,   3,   1, // 3445-3451
  8,   1, // 3452-3453
  7,   1, // 3454-3455
  8,   1, // 3456-3457
  7,   1, // 3458-3459
  2,   2,   1,   1, // 3460-3463
  3,   3,   1,   1, // 3464-3467
  4,   4,   1,   1, // 3468-3471
  2,   2,   1, // 3472-3474
  2,   2, // 3475-3476
  2,   1, // 3477-3478
  2, // 3479
  2,   2, // 3480-3481
  2,   1, // 3482-3483
  3,   1, // 3484-3485
  3,   1, // 3486-3487
  2,   1, // 3488-3489
  1, // 3490
  1,   1, // 3491-3492
  2,   1,   2, // 3493-3495
  3,   1, // 3496-3497
  3,   1, // 3498-3499
  2,   2,   1,   1, // 3500-3503
  1,   1, // 3504-3505
  2, // 3506
  2,   2, // 3507-3508
  2,   1, // 3509-3510
  2,   2,   2, // 3511-3513
  2,   2, // 3514-3515
  2,   2,   2, // 3516-3518
  1,   1,   3, // 3519-3521
  1,   1,   3, // 3522-3524
  2,   2, // 3525-3526
  2,   2, // 3527-3528
  2,   2,   2, // 3529-3531
  2,   2,   1,   1, // 3532-3535
  2,   2,   1,   1, // 3536-3539
  2,   1,   1, // 3540-3542
  1,   1,   1, // 3543-3545
  1,   1, // 3546-3547
  1,   1,   1, // 3548-3550
  1,   1, // 3551-3552
  3,   1, // 3553-3554
  2, // 3555
  3, // 3556
  5, // 3557
  2,   1, // 3558-3559
  6,   1,   1,   4, // 3560-3563
  6,   1,   1, // 3564-3566
  6,   6,   1,   1, // 3567-3570
  6,   6,   1,   1, // 3571-3574
  5,   1,   1, // 3575-3577
  6,   1,   1,   4, // 3578-3581
  3,   1,   1, // 3582-3584
  4,   1,   1, // 3585-3587
  3,   1,   1, // 3588-3590
  3,   2,   1,   1, // 3591-3594
  1,   1, // 3595-3596
  1,   1, // 3597-3598
  3,   1, // 3599-3600
  2, // 3601
  3, // 3602
  1, // 3603
  2,   1, // 3604-3605
  2,   2, // 3606-3607
  2,   2,   2, // 3608-3610
  2,   2,   2, // 3611-3613
  2,   2,   2, // 3614-3616
  2,   2,   1, // 3617-3619
  2,   2,   1,   1, // 3620-3623
  6,   1,   1, // 3624-3626
  5,   1,   1, // 3627-3629
  6,   1,   1,   4, // 3630-3633
  6,   1,   1,   4, // 3634-3637
  6,   1,   1,   4, // 3638-3641
  6,   1,   1,   4, // 3642-3645
  6,   1,   1,   4, // 3646-3649
  6,   1,   1,   4, // 3650-3653
  6,   6,   1,   1, // 3654-3657
  6,   6,   1,   1, // 3658-3661
  6,   6,   1,   1, // 3662-3665
  3,   1,   1, // 3666-3668
  4,   1,   1, // 3669-3671
  3,   1,   1, // 3672-3674
  3,   1, // 3675-3676
  3,   1, // 3677-3678
  4,   1, // 3679-3680
  4,   1,   1, // 3681-3683
  3,   1,   1, // 3684-3686
  3,   1,   1, // 3687-3689
  3,   1,   1, // 3690-3692
  3,   1,   1, // 3693-3695
  3,   1, // 3696-3697
  4,   1,   1, // 3698-3700
  3,   1,   1, // 3701-3703
  3,   2,   1,   1, // 3704-3707
  3,   2,   1, // 3708-3710
  3,   2,   1,   1, // 3711-3714
  3,   2,   1,   1, // 3715-3718
  3,   2,   1, // 3719-3721
  3,   1, // 3722-3723
  3,   1, // 3724-3725
  3,   1, // 3726-3727
  3,   2,   1, // 3728-3730
  3,   1,   1, // 3731-3733
  3,   1, // 3734-3735
  3,   2,   1,   1, // 3736-3739
  1,   1,   1,   1,   3, // 3740-3744
  2,   1,   1,   1,   3, // 3745-3749
  1,   2,   1,   1,   3, // 3750-3754
  1,   1,   3, // 3755-3757
  1,   1,   3, // 3758-3760
  3,   1,   1, // 3761-3763
  3,   1,   1, // 3764-3766
  3,   1,   1, // 3767-3769
  3,   1,   1, // 3770-3772
  3,   1, // 3773-3774
  3,   1, // 3775-3776
  2,   3,   1,   1, // 3777-3780
  2,   3,   1, // 3781-3783
  2,   3,   1,   1, // 3784-3787
  2,   3,   1, // 3788-3790
  3,   1, // 3791-3792
  3,   1, // 3793-3794
  3,   1,   1, // 3795-3797
  2,   3,   1,   1, // 3798-3801
  2, // 3802
  3,   1, // 3803-3804
  4,   1, // 3805-3806
  3,   1,   1, // 3807-3809
  3,   2,   1, // 3810-3812
  3,   2,   2, // 3813-3815
  3,   2,   2, // 3816-3818
  3, // 3819
  3,   2,   2, // 3820-3822
  4,   2,   2, // 3823-3825
  4,   2,   1, // 3826-3828
  4,   2,   1, // 3829-3831
  4,   2,   1, // 3832-3834
  4,   2,   1, // 3835-3837
  6,   2, // 3838-3839
  5,   2, // 3840-3841
  4,   1,   1, // 3842-3844
  4,   1,   1, // 3845-3847
  5,   1,   1, // 3848-3850
  3,   2,   1, // 3851-3853
  2,   1,   1, // 3854-3856
  3,   1,   1, // 3857-3859
  2,   1, // 3860-3861
  3,   1, // 3862-3863
  6,   3,   2,   1, // 3864-3867
  6,   3,   2,   1, // 3868-3871
  5,   2, // 3872-3873
  6,   2, // 3874-3875
  4,   2, // 3876-3877
  4,   2, // 3878-3879
  5,   2,   2, // 3880-3882
  6,   2,   2, // 3883-3885
  4,   2,   1, // 3886-3888
  4,   2,   1, // 3889-3891
  7,   3,   1, // 3892-3894
  6,   3,   1, // 3895-3897
  4,   1, // 3898-3899
  4,   1, // 3900-3901
  4,   2,   1, // 3902-3904
  4,   2,   1, // 3905-3907
  5,   1,   1, // 3908-3910
  4,   1,   1, // 3911-3913
  5,   2, // 3914-3915
  6,   2, // 3916-3917
  4,   2,   1, // 3918-3920
  3,   1,   1, // 3921-3923
  4,   1,   1, // 3924-3926
  4,   2,   1, // 3927-3929
  3,   2,   1, // 3930-3932
  3,   1,   2,   1, // 3933-3936
  3,   2,   2,   1, // 3937-3940
  3,   1,   2,   2,   1, // 3941-3945
  4,   2,   2,   3,   1, // 3946-3950
  4,   1,   2,   2,   3,   1, // 3951-3956
  4,   2,   2,   3,   3,   1, // 3957-3962
  4,   1,   2,   2,   3,   3,   1, // 3963-3969
  2,   2,   1,   1, // 3970-3973
  3,   3,   1,   1, // 3974-3977
  4,   4,   1,   1, // 3978-3981
  4,   1, // 3982-3983
  7,   1, // 3984-3985
  4,   1, // 3986-3987
  1,   1, // 3988-3989
  4,   2,   1, // 3990-3992
  5,   2,   2, // 3993-3995
  6,   2,   2, // 3996-3998
  4,   2,   1, // 3999-4001
  7,   1,   1, // 4002-4004
  5,   2,   2, // 4005-4007
  9,   1,   1, // 4008-4010
  9,   2,   2, // 4011-4013
  10,   2,   2, // 4014-4016
  6,   2,   2, // 4017-4019
  7,   2,   1, // 4020-4022
  7,   1,   1, // 4023-4025
  5,   2,   1, // 4026-4028
  6,   2,   1, // 4029-4031
  7,   2,   2, // 4032-4034
  5,   2,   2, // 4035-4037
  6,   2,   2, // 4038-4040
  9,   2,   1, // 4041-4043
  11,   1,   1, // 4044-4046
  19,   2,   1,   1, // 4047-4050
  7,   2,   1,   1, // 4051-4054
  19,   2,   1,   1, // 4055-4058
  7,   3,   2,   1, // 4059-4062
  6,   3,   2,   2, // 4063-4066
  7,   2,   1,   1, // 4067-4070
  9,   3,   2,   2, // 4071-4074
  10,   3,   2,   2, // 4075-4078
  9,   3,   2,   1, // 4079-4082
  7,   3,   2,   2, // 4083-4086
  9,   3,   2,   2, // 4087-4090
  10,   3,   2,   2, // 4091-4094
  5,   1, // 4095-4096
  7,   1, // 4097-4098
  6,   2, // 4099-4100
  5,   2, // 4101-4102
  8,   1, // 4103-4104
  7,   1, // 4105-4106
  8,   1, // 4107-4108
  7,   1, // 4109-4110
  8,   1, // 4111-4112
  7,   1, // 4113-4114
  4,   1, // 4115-4116
  7,   1, // 4117-4118
  3, // 4119
  3,   2,   1, // 4120-4122
  4,   1, // 4123-4124
  2,   1, // 4125-4126
  4,   1, // 4127-4128
  2,   1, // 4129-4130
  3,   1, // 4131-4132
  2,   1, // 4133-4134
  20,   1, // 4135-4136
  2,   1, // 4137-4138
  3,   1,   1, // 4139-4141
  20,   20,   1, // 4142-4144
  2,   1,   1, // 4145-4147
  2,   1,   1, // 4148-4150
  20,   1, // 4151-4152
  20,   1, // 4153-4154
  20, // 4155
  20, // 4156
  20, // 4157
  2,   1, // 4158-4159
  2,   1, // 4160-4161
  1,   1, // 4162-4163
  1,   1, // 4164-4165
  1,   1,   1,   2, // 4166-4169
  1,   1,   1,   1, // 4170-4173
  1,   1,   1,   2, // 4174-4177
  2,   1,   1,   1,   2, // 4178-4182
  1,   1,   1,   1, // 4183-4186
  2,   1,   1,   1,   1, // 4187-4191
  2,   1, // 4192-4193
  2,   2,   1, // 4194-4196
  2,   2,   1, // 4197-4199
  2,   2,   2,   1, // 4200-4203
  2,   2,   3,   1, // 4204-4207
  2,   2,   2,   1, // 4208-4211
  2,   2,   3,   3,   1, // 4212-4216
  2,   2,   2,   1, // 4217-4220
  2,   2,   1, // 4221-4223
  2,   2,   3,   3,   1, // 4224-4228
  2,   2,   2,   1,   1,   1, // 4229-4234
  2,   2,   3,   3,   2,   1, // 4235-4240
  3,   3,   4,   1, // 4241-4244
  3,   3,   4,   1, // 4245-4248
  3,   3,   4,   2,   1, // 4249-4253
  3,   3,   4,   2,   1, // 4254-4258
  3,   3,   4,   4,   1, // 4259-4263
  3,   3,   4,   4,   1, // 4264-4268
  3,   3,   4,   4,   2,   1, // 4269-4274
  3,   3,   4,   4,   2,   1, // 4275-4280
  2,   1, // 4281-4282
  3,   1,   1,   1, // 4283-4286
  2,   2,   1,   1, // 4287-4290
  3,   2,   1,   1,   1,   1, // 4291-4296
  2,   2,   1, // 4297-4299
  3,   3,   1,   1,   1,   1, // 4300-4305
  3,   3,   2,   1,   1,   1,   1,   1, // 4306-4313
  2,   2,   2,   1,   1, // 4314-4318
  3,   3,   2,   1,   1,   1,   1,   1, // 4319-4326
  2,   2,   3,   1, // 4327-4330
  4,   4,   5,   1,   1,   1,   1,   2, // 4331-4338
  2,   2,   3,   2,   1,   1, // 4339-4344
  4,   4,   5,   2,   1,   1,   1,   1,   1,   2, // 4345-4354
  2,   2,   3,   2,   1,   1, // 4355-4360
  4,   4,   5,   2,   1,   1,   1,   1,   1,   2, // 4361-4370
  2,   2,   3,   3,   1, // 4371-4375
  4,   4,   5,   5,   1,   1,   1,   1,   2,   2, // 4376-4385
  2,   2,   3,   3,   2,   1,   1, // 4386-4392
  4,   4,   5,   5,   2,   1,   1,   1,   1,   1,   2,   2, // 4393-4404
  2,   2,   3,   3,   2,   1,   1, // 4405-4411
  4,   4,   5,   5,   2,   1,   1,   1,   1,   1,   2,   2, // 4412-4423
  1,   1,   1, // 4424-4426
  1,   1,   1,   1, // 4427-4430
  2,   2,   1, // 4431-4433
  2,   2,   2,   1, // 4434-4437
  1,   1,   1,   1,   2, // 4438-4442
  2,   2,   3,   2,   1, // 4443-4447
  2,   1,   1,   1,   1,   1,   2, // 4448-4454
  1,   1,   1,   1,   2,   2, // 4455-4460
  2,   2,   3,   3,   2,   1, // 4461-4466
  2,   1,   1,   1,   1,   1,   2,   2, // 4467-4474
  1,   1,   1,   1, // 4475-4478
  2,   2,   1, // 4479-4481
  1,   1,   1,   1,   2,   2, // 4482-4487
  2,   1,   1,   1,   1,   1,   2,   2, // 4488-4495
  2,   2,   1, // 4496-4498
  1,   1,   1,   1,   2, // 4499-4503
  2,   1,   1,   1,   1,   1,   2, // 4504-4510
  1,   1,   1,   1,   2,   2, // 4511-4516
  2,   1,   1,   1,   1,   1,   2,   2, // 4517-4524
  1,   1,   1, // 4525-4527
  2,   1,   1,   1,   1, // 4528-4532
  1,   1,   1,   1, // 4533-4536
  2,   1,   1,   1,   1,   1, // 4537-4542
  1,   1,   1,   1,   2, // 4543-4547
  2,   1,   1,   1,   1,   1,   2, // 4548-4554
  1,   1,   1,   1,   2,   2, // 4555-4560
  2,   1,   1,   1,   1,   1,   2,   2, // 4561-4568
  20,   1,   1, // 4569-4571
  19,   1, // 4572-4573
  29,   1,   1, // 4574-4576
  29,   1, // 4577-4578
  0 // End operand cycles
};
extern const unsigned ARMForwardingPaths[] = {
 0, // No itinerary
 0,  0, // 1-2
 0,  0,  0, // 3-5
 0,  0,  0,  0, // 6-9
 0,  0,  0,  0, // 10-13
 0,  0,  0,  0, // 14-17
 0,  0, // 18-19
 0,  0,  0, // 20-22
 0,  0,  0,  0, // 23-26
 0,  0,  0,  0, // 27-30
 0,  0, // 31-32
 0,  0, // 33-34
 0, // 35
 0,  0, // 36-37
 0,  0,  0, // 38-40
 0,  0,  0, // 41-43
 0,  0, // 44-45
 0,  0, // 46-47
 0, // 48
 0,  0,  0,  0,  0, // 49-53
 0,  0,  0,  0,  0, // 54-58
 0,  0,  0,  0,  0, // 59-63
 0,  0,  0,  0, // 64-67
 0,  0,  0, // 68-70
 0,  0,  0, // 71-73
 0,  0,  0, // 74-76
 0,  0,  0, // 77-79
 0,  0,  0,  0, // 80-83
 0,  0, // 84-85
 0,  0, // 86-87
 0,  0,  0,  0, // 88-91
 0,  0,  0, // 92-94
 0,  0,  0, // 95-97
 0,  0,  0, // 98-100
 0,  0,  0,  0, // 101-104
 0, // 105
 0, // 106
 0, // 107
 0,  0, // 108-109
 0,  0,  0, // 110-112
 0, // 113
 0, // 114
 0, // 115
 0,  0, // 116-117
 0,  0,  0, // 118-120
 0,  0, // 121-122
 0,  0,  0, // 123-125
 0, // 126
 0,  0, // 127-128
 0,  0,  0, // 129-131
 0,  0,  0, // 132-134
 0,  0,  0, // 135-137
 0,  0,  0, // 138-140
 0,  0,  0, // 141-143
 0,  0,  0, // 144-146
 0,  0,  0,  0, // 147-150
 0,  0,  0,  0, // 151-154
 0,  0,  0, // 155-157
 0,  0,  0, // 158-160
 0, // 161
 0,  0,  0,  0, // 162-165
 0,  0,  0, // 166-168
 0,  0,  0,  0, // 169-172
 0,  0,  0, // 173-175
 0,  0,  0, // 176-178
 0,  0,  0,  0, // 179-182
 0,  0,  0, // 183-185
 0,  0,  0, // 186-188
 0,  0,  0, // 189-191
 0,  0, // 192-193
 0, // 194
 0,  0, // 195-196
 0,  0,  0, // 197-199
 0,  0,  0, // 200-202
 0,  0,  0, // 203-205
 0,  0,  0, // 206-208
 0,  0, // 209-210
 0,  0, // 211-212
 0,  0, // 213-214
 0,  0, // 215-216
 0,  0,  0, // 217-219
 0,  0,  0, // 220-222
 0,  0,  0,  0, // 223-226
 0,  0,  0,  0, // 227-230
 0,  0,  0,  0,  0, // 231-235
 0,  0,  0,  0, // 236-239
 0,  0,  0, // 240-242
 0,  0,  0, // 243-245
 0,  0,  0,  0, // 246-249
 0,  0,  0,  0, // 250-253
 0,  0,  0, // 254-256
 0,  0,  0, // 257-259
 0,  0, // 260-261
 0,  0, // 262-263
 0,  0,  0, // 264-266
 0,  0,  0, // 267-269
 0,  0, // 270-271
 0,  0, // 272-273
 0,  0, // 274-275
 0,  0, // 276-277
 0,  0,  0, // 278-280
 0,  0,  0, // 281-283
 0,  0,  0,  0,  0, // 284-288
 0,  0,  0,  0, // 289-292
 0,  0,  0, // 293-295
 0,  0,  0, // 296-298
 0,  0, // 299-300
 0,  0, // 301-302
 0,  0, // 303-304
 0,  0, // 305-306
 0,  0,  0, // 307-309
 0,  0, // 310-311
 0,  0, // 312-313
 0, // 314
 0,  0, // 315-316
 0,  0, // 317-318
 0,  0, // 319-320
 0,  0, // 321-322
 0,  0, // 323-324
 0, // 325
 0,  0, // 326-327
 0,  0, // 328-329
 0,  0, // 330-331
 0,  0,  0,  0, // 332-335
 0,  0, // 336-337
 0, // 338
 0,  0, // 339-340
 0,  0, // 341-342
 0,  0,  0, // 343-345
 0,  0, // 346-347
 0,  0,  0, // 348-350
 0,  0,  0, // 351-353
 0,  0,  0, // 354-356
 0,  0, // 357-358
 0,  0, // 359-360
 0,  0,  0, // 361-363
 0,  0,  0,  0, // 364-367
 0,  0,  0,  0, // 368-371
 0,  0,  0, // 372-374
 0,  0,  0, // 375-377
 0,  0, // 378-379
 0,  0,  0, // 380-382
 0,  0, // 383-384
 0, // 385
 0, // 386
 0, // 387
 0, // 388
 0,  0, // 389-390
 0,  0,  0,  0, // 391-394
 0,  0,  0, // 395-397
 0,  0,  0,  0, // 398-401
 0,  0,  0, // 402-404
 0,  0,  0, // 405-407
 0,  0,  0,  0, // 408-411
 0,  0,  0, // 412-414
 0,  0,  0, // 415-417
 0,  0,  0, // 418-420
 0,  0,  0,  0, // 421-424
 0,  0, // 425-426
 0,  0, // 427-428
 0, // 429
 0, // 430
 0, // 431
 0, // 432
 0,  0, // 433-434
 0,  0, // 435-436
 0,  0,  0, // 437-439
 0,  0,  0, // 440-442
 0,  0,  0, // 443-445
 0,  0,  0, // 446-448
 0,  0,  0,  0, // 449-452
 0,  0,  0, // 453-455
 0,  0,  0, // 456-458
 0,  0,  0,  0, // 459-462
 0,  0,  0,  0, // 463-466
 0,  0,  0,  0, // 467-470
 0,  0,  0,  0, // 471-474
 0,  0,  0,  0, // 475-478
 0,  0,  0,  0, // 479-482
 0,  0,  0, // 483-485
 0,  0,  0, // 486-488
 0,  0,  0,  0, // 489-492
 0,  0,  0, // 493-495
 0,  0,  0, // 496-498
 0,  0,  0, // 499-501
 0,  0, // 502-503
 0,  0, // 504-505
 0,  0, // 506-507
 0,  0,  0, // 508-510
 0,  0,  0, // 511-513
 0,  0,  0, // 514-516
 0,  0,  0, // 517-519
 0,  0,  0, // 520-522
 0,  0, // 523-524
 0,  0,  0, // 525-527
 0,  0,  0, // 528-530
 0,  0,  0,  0, // 531-534
 0,  0,  0, // 535-537
 0,  0,  0,  0, // 538-541
 0,  0,  0,  0, // 542-545
 0,  0,  0, // 546-548
 0,  0, // 549-550
 0,  0, // 551-552
 0,  0, // 553-554
 0,  0,  0, // 555-557
 0,  0,  0, // 558-560
 0,  0, // 561-562
 0,  0,  0,  0, // 563-566
 0,  0,  0,  0,  0, // 567-571
 0,  0,  0,  0,  0, // 572-576
 0,  0,  0,  0,  0, // 577-581
 0,  0,  0, // 582-584
 0,  0,  0, // 585-587
 0,  0,  0, // 588-590
 0,  0,  0, // 591-593
 0,  0,  0, // 594-596
 0,  0,  0, // 597-599
 0,  0, // 600-601
 0,  0, // 602-603
 0,  0,  0,  0, // 604-607
 0,  0,  0, // 608-610
 0,  0,  0,  0, // 611-614
 0,  0,  0, // 615-617
 0,  0, // 618-619
 0,  0, // 620-621
 0,  0,  0, // 622-624
 0,  0,  0,  0, // 625-628
 0, // 629
 0,  0, // 630-631
 0,  0, // 632-633
 0,  0, // 634-635
 0,  0, // 636-637
 0,  0, // 638-639
 0,  0, // 640-641
 0,  0,  0, // 642-644
 0,  0,  0, // 645-647
 0,  0,  0, // 648-650
 0,  0,  0, // 651-653
 0,  0,  0,  0, // 654-657
 0,  0,  0,  0, // 658-661
 0,  0,  0,  0, // 662-665
 0,  0,  0,  0, // 666-669
 0,  0, // 670-671
 0,  0, // 672-673
 0,  0, // 674-675
 0,  0, // 676-677
 0,  0, // 678-679
 0,  0, // 680-681
 0,  0, // 682-683
 0,  0, // 684-685
 0,  0, // 686-687
 0,  0, // 688-689
 0,  0, // 690-691
 0,  0, // 692-693
 0,  0,  0, // 694-696
 0,  0,  0, // 697-699
 0,  0,  0, // 700-702
 0, // 703
 0, // 704
 0, // 705
 0,  0,  0, // 706-708
 0,  0,  0, // 709-711
 0,  0,  0, // 712-714
 0,  0,  0, // 715-717
 0,  0,  0,  0, // 718-721
 0,  0,  0,  0, // 722-725
 0,  0,  0,  0, // 726-729
 0,  0,  0,  0,  0, // 730-734
 0,  0,  0,  0, // 735-738
 0,  0,  0,  0,  0, // 739-743
 0,  0,  0, // 744-746
 0,  0,  0, // 747-749
 0,  0,  0, // 750-752
 0,  0,  0, // 753-755
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 756-757
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 758-760
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, // 761-764
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, // 765-768
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, // 769-772
 0,  0, // 773-774
 0,  0,  0, // 775-777
 0,  0,  0,  0, // 778-781
 0,  0,  0,  0, // 782-785
 0,  0, // 786-787
 0,  0, // 788-789
CortexA9ItinerariesBypass::A9_LdBypass, // 790
CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 791-792
CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, // 793-795
CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, // 796-798
 0,  0, // 799-800
 0,  0, // 801-802
 0, // 803
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 804-808
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 809-813
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 814-818
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 819-822
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 823-825
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 826-828
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 829-831
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 832-835
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 836-839
CortexA9ItinerariesBypass::A9_LdBypass,  0, // 840-841
 0,  0, // 842-843
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 844-847
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 848-850
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 851-853
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 854-856
 0,  0,  0,  0, // 857-860
 0, // 861
 0, // 862
 0, // 863
 0,  0, // 864-865
 0,  0,  0, // 866-868
 0, // 869
 0, // 870
 0, // 871
 0,  0, // 872-873
 0,  0,  0, // 874-876
 0,  0, // 877-878
 0,  0,  0, // 879-881
 0, // 882
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 883-884
 0,  0,  0, // 885-887
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 888-890
 0,  0,  0, // 891-893
 0,  0,  0, // 894-896
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::NoBypass, // 897-899
 0,  0,  0, // 900-902
 0,  0, // 903-904
 0,  0,  0,  0, // 905-908
 0,  0,  0,  0, // 909-912
 0,  0,  0, // 913-915
 0,  0,  0,  0, // 916-919
 0, // 920
 0,  0,  0,  0, // 921-924
 0,  0,  0, // 925-927
 0,  0,  0,  0, // 928-931
 0,  0,  0, // 932-934
 0,  0,  0, // 935-937
 0,  0,  0,  0, // 938-941
 0,  0,  0, // 942-944
 0,  0,  0, // 945-947
 0,  0,  0, // 948-950
 0,  0, // 951-952
 0, // 953
 0,  0, // 954-955
 0,  0,  0, // 956-958
 0,  0,  0, // 959-961
 0,  0,  0,  0, // 962-965
 0,  0,  0,  0, // 966-969
 0,  0,  0, // 970-972
 0,  0,  0, // 973-975
 0,  0,  0, // 976-978
 0,  0,  0, // 979-981
 0,  0, // 982-983
 0,  0, // 984-985
 0,  0, // 986-987
 0,  0, // 988-989
 0,  0,  0, // 990-992
 0,  0,  0, // 993-995
 0,  0,  0, // 996-998
 0,  0,  0, // 999-1001
 0,  0,  0, // 1002-1004
 0,  0,  0, // 1005-1007
 0,  0,  0, // 1008-1010
 0, // 1011
 0,  0,  0, // 1012-1014
 0,  0,  0, // 1015-1017
 0,  0, // 1018-1019
 0,  0, // 1020-1021
 0,  0, // 1022-1023
 0,  0, // 1024-1025
 0,  0, // 1026-1027
 0,  0, // 1028-1029
 0,  0,  0, // 1030-1032
 0,  0,  0, // 1033-1035
 0,  0, // 1036-1037
 0,  0, // 1038-1039
 0,  0, // 1040-1041
 0,  0,  0, // 1042-1044
 0,  0,  0, // 1045-1047
 0,  0,  0,  0, // 1048-1051
 0,  0,  0,  0, // 1052-1055
 0,  0,  0,  0, // 1056-1059
 0,  0,  0,  0, // 1060-1063
 0,  0, // 1064-1065
 0,  0,  0, // 1066-1068
 0,  0, // 1069-1070
 0,  0,  0,  0, // 1071-1074
 0,  0,  0,  0, // 1075-1078
 0,  0,  0,  0,  0,  0, // 1079-1084
 0,  0, // 1085-1086
 0,  0,  0,  0,  0, // 1087-1091
 0,  0,  0,  0, // 1092-1095
 0,  0,  0,  0, // 1096-1099
 0,  0,  0, // 1100-1102
 0,  0,  0, // 1103-1105
 0,  0,  0, // 1106-1108
 0,  0,  0,  0,  0, // 1109-1113
 0,  0,  0,  0,  0,  0, // 1114-1119
 0,  0,  0,  0,  0,  0,  0,  0, // 1120-1127
 0,  0,  0, // 1128-1130
 0,  0,  0,  0,  0,  0, // 1131-1136
 0,  0,  0,  0,  0, // 1137-1141
 0,  0,  0,  0,  0,  0, // 1142-1147
 0,  0,  0,  0, // 1148-1151
 0,  0,  0,  0,  0,  0, // 1152-1157
 0,  0,  0,  0,  0,  0,  0,  0, // 1158-1165
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 1166-1175
 0,  0,  0,  0, // 1176-1179
 0,  0,  0,  0,  0, // 1180-1184
 0,  0,  0,  0,  0, // 1185-1189
 0,  0,  0,  0,  0,  0,  0, // 1190-1196
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 1197-1206
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 1207-1218
 0,  0,  0,  0,  0, // 1219-1223
 0,  0,  0,  0,  0,  0, // 1224-1229
 0,  0,  0,  0, // 1230-1233
 0,  0,  0,  0, // 1234-1237
 0,  0, // 1238-1239
 0,  0, // 1240-1241
 0,  0,  0,  0, // 1242-1245
 0,  0,  0,  0, // 1246-1249
 0,  0,  0,  0, // 1250-1253
 0,  0,  0,  0, // 1254-1257
 0,  0,  0,  0, // 1258-1261
 0,  0,  0,  0, // 1262-1265
 0,  0,  0,  0, // 1266-1269
 0,  0,  0,  0, // 1270-1273
 0,  0,  0, // 1274-1276
 0,  0, // 1277-1278
 0,  0, // 1279-1280
 0,  0,  0, // 1281-1283
 0,  0, // 1284-1285
 0,  0, // 1286-1287
 0,  0,  0, // 1288-1290
 0,  0,  0, // 1291-1293
 0,  0,  0, // 1294-1296
 0,  0,  0, // 1297-1299
 0,  0,  0, // 1300-1302
 0,  0,  0, // 1303-1305
 0,  0,  0, // 1306-1308
 0,  0,  0, // 1309-1311
 0,  0,  0, // 1312-1314
 0,  0,  0, // 1315-1317
 0,  0,  0, // 1318-1320
 0,  0,  0, // 1321-1323
 0,  0, // 1324-1325
 0,  0,  0, // 1326-1328
 0,  0,  0, // 1329-1331
 0,  0,  0, // 1332-1334
 0,  0,  0, // 1335-1337
 0,  0,  0, // 1338-1340
 0,  0, // 1341-1342
 0,  0, // 1343-1344
 0,  0, // 1345-1346
 0,  0, // 1347-1348
 0,  0, // 1349-1350
 0,  0, // 1351-1352
 0,  0,  0, // 1353-1355
 0,  0,  0,  0,  0, // 1356-1360
 0,  0,  0, // 1361-1363
 0,  0,  0,  0,  0,  0, // 1364-1369
 0,  0,  0,  0,  0,  0, // 1370-1375
 0,  0,  0,  0,  0, // 1376-1380
 0,  0,  0,  0,  0, // 1381-1385
 0,  0,  0,  0,  0,  0,  0,  0, // 1386-1393
 0,  0,  0,  0,  0,  0,  0, // 1394-1400
 0,  0,  0,  0, // 1401-1404
 0,  0,  0,  0, // 1405-1408
 0,  0,  0,  0,  0,  0, // 1409-1414
 0,  0,  0,  0, // 1415-1418
 0,  0,  0,  0,  0,  0, // 1419-1424
 0,  0,  0,  0,  0,  0,  0,  0, // 1425-1432
 0,  0,  0,  0,  0, // 1433-1437
 0,  0,  0,  0,  0,  0,  0, // 1438-1444
 0,  0,  0,  0,  0, // 1445-1449
 0,  0,  0,  0,  0,  0,  0, // 1450-1456
 0,  0,  0,  0,  0,  0, // 1457-1462
 0,  0,  0,  0,  0,  0,  0,  0, // 1463-1470
 0,  0,  0,  0,  0,  0, // 1471-1476
 0,  0,  0,  0,  0,  0,  0,  0, // 1477-1484
 0,  0,  0,  0, // 1485-1488
 0,  0,  0,  0, // 1489-1492
 0,  0, // 1493-1494
 0,  0, // 1495-1496
 0,  0,  0, // 1497-1499
 0,  0,  0, // 1500-1502
 0,  0,  0,  0, // 1503-1506
 0,  0,  0,  0,  0, // 1507-1511
 0,  0,  0,  0,  0,  0, // 1512-1517
 0,  0,  0,  0, // 1518-1521
 0,  0,  0,  0,  0, // 1522-1526
 0,  0,  0,  0,  0,  0, // 1527-1532
 0,  0,  0,  0,  0,  0,  0, // 1533-1539
 0,  0, // 1540-1541
 0,  0, // 1542-1543
 0,  0, // 1544-1545
 0,  0, // 1546-1547
 0,  0,  0,  0, // 1548-1551
 0,  0,  0,  0, // 1552-1555
 0,  0,  0,  0, // 1556-1559
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::NoBypass, // 1560-1562
 0,  0, // 1563-1564
CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::NoBypass, // 1565-1566
CortexA9ItinerariesBypass::A9_LdBypass, // 1567
CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1568-1569
CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::NoBypass, // 1570-1571
CortexA9ItinerariesBypass::A9_LdBypass,  0, // 1572-1573
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1574-1576
 0,  0, // 1577-1578
 0, // 1579
 0,  0, // 1580-1581
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1582-1584
 0,  0, // 1585-1586
 0,  0, // 1587-1588
 0,  0,  0,  0, // 1589-1592
 0,  0, // 1593-1594
 0, // 1595
 0,  0, // 1596-1597
 0,  0, // 1598-1599
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1600-1602
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1603-1604
 0,  0,  0, // 1605-1607
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1608-1610
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1611-1613
 0,  0, // 1614-1615
 0,  0, // 1616-1617
 0,  0,  0, // 1618-1620
 0,  0,  0,  0, // 1621-1624
 0,  0,  0,  0, // 1625-1628
 0,  0,  0, // 1629-1631
 0,  0,  0, // 1632-1634
 0,  0, // 1635-1636
 0,  0,  0, // 1637-1639
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1640-1641
 0, // 1642
 0, // 1643
 0, // 1644
 0, // 1645
 0,  0, // 1646-1647
 0,  0,  0,  0, // 1648-1651
 0,  0,  0, // 1652-1654
 0,  0,  0,  0, // 1655-1658
 0,  0,  0,  0, // 1659-1662
 0,  0,  0, // 1663-1665
 0,  0,  0,  0, // 1666-1669
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1670-1672
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1673-1675
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1676-1678
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 1679-1682
 0,  0, // 1683-1684
 0,  0, // 1685-1686
 0, // 1687
 0, // 1688
 0, // 1689
 0, // 1690
 0,  0, // 1691-1692
 0,  0, // 1693-1694
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1695-1697
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1698-1700
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1701-1703
 0,  0,  0, // 1704-1706
 0,  0,  0,  0, // 1707-1710
 0,  0,  0, // 1711-1713
 0,  0,  0, // 1714-1716
 0,  0,  0,  0, // 1717-1720
 0,  0,  0,  0, // 1721-1724
 0,  0,  0,  0, // 1725-1728
 0,  0,  0,  0, // 1729-1732
 0,  0,  0,  0, // 1733-1736
 0,  0,  0,  0, // 1737-1740
 0,  0,  0,  0, // 1741-1744
 0,  0,  0,  0, // 1745-1748
 0,  0,  0,  0, // 1749-1752
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1753-1755
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1756-1758
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1759-1761
CortexA9ItinerariesBypass::A9_LdBypass,  0, // 1762-1763
CortexA9ItinerariesBypass::A9_LdBypass,  0, // 1764-1765
 0,  0, // 1766-1767
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1768-1770
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1771-1773
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1774-1776
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1777-1779
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1780-1782
CortexA9ItinerariesBypass::A9_LdBypass,  0, // 1783-1784
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1785-1787
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1788-1790
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 1791-1794
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1795-1797
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 1798-1801
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 1802-1805
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1806-1808
CortexA9ItinerariesBypass::A9_LdBypass,  0, // 1809-1810
CortexA9ItinerariesBypass::A9_LdBypass,  0, // 1811-1812
CortexA9ItinerariesBypass::A9_LdBypass,  0, // 1813-1814
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1815-1817
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 1818-1821
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0, // 1822-1824
CortexA9ItinerariesBypass::A9_LdBypass,  0,  0,  0, // 1825-1828
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1829-1833
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1834-1838
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1839-1843
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1844-1846
CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::NoBypass, CortexA9ItinerariesBypass::A9_LdBypass, // 1847-1849
 0,  0,  0, // 1850-1852
 0,  0,  0, // 1853-1855
 0,  0,  0, // 1856-1858
 0,  0,  0, // 1859-1861
 0,  0, // 1862-1863
 0,  0, // 1864-1865
 0,  0,  0,  0, // 1866-1869
 0,  0,  0, // 1870-1872
 0,  0,  0,  0, // 1873-1876
 0,  0,  0, // 1877-1879
 0,  0, // 1880-1881
 0,  0, // 1882-1883
 0,  0,  0, // 1884-1886
 0,  0,  0,  0, // 1887-1890
 0, // 1891
CortexA9ItinerariesBypass::A9_LdBypass,  0, // 1892-1893
 0,  0, // 1894-1895
 0,  0,  0, // 1896-1898
 0,  0,  0, // 1899-1901
 0,  0,  0, // 1902-1904
 0,  0,  0, // 1905-1907
 0, // 1908
 0,  0,  0, // 1909-1911
 0,  0,  0, // 1912-1914
 0,  0,  0, // 1915-1917
 0,  0,  0, // 1918-1920
 0,  0,  0, // 1921-1923
 0,  0,  0, // 1924-1926
 0,  0, // 1927-1928
 0,  0, // 1929-1930
 0,  0,  0, // 1931-1933
 0,  0,  0, // 1934-1936
 0,  0,  0, // 1937-1939
 0,  0,  0, // 1940-1942
 0,  0,  0, // 1943-1945
 0,  0,  0, // 1946-1948
 0,  0, // 1949-1950
 0,  0, // 1951-1952
 0,  0,  0,  0, // 1953-1956
 0,  0,  0,  0, // 1957-1960
 0,  0, // 1961-1962
 0,  0, // 1963-1964
 0,  0, // 1965-1966
 0,  0, // 1967-1968
 0,  0,  0, // 1969-1971
 0,  0,  0, // 1972-1974
 0,  0,  0, // 1975-1977
 0,  0,  0, // 1978-1980
 0,  0,  0, // 1981-1983
 0,  0,  0, // 1984-1986
 0,  0, // 1987-1988
 0,  0, // 1989-1990
 0,  0,  0, // 1991-1993
 0,  0,  0, // 1994-1996
 0,  0,  0, // 1997-1999
 0,  0,  0, // 2000-2002
 0,  0, // 2003-2004
 0,  0, // 2005-2006
 0,  0,  0, // 2007-2009
 0,  0,  0, // 2010-2012
 0,  0,  0, // 2013-2015
 0,  0,  0, // 2016-2018
 0,  0,  0, // 2019-2021
 0,  0,  0,  0, // 2022-2025
 0,  0,  0,  0, // 2026-2029
 0,  0,  0,  0,  0, // 2030-2034
 0,  0,  0,  0,  0, // 2035-2039
 0,  0,  0,  0,  0,  0, // 2040-2045
 0,  0,  0,  0,  0,  0, // 2046-2051
 0,  0,  0,  0,  0,  0,  0, // 2052-2058
 0,  0,  0,  0, // 2059-2062
 0,  0,  0,  0, // 2063-2066
 0,  0,  0,  0, // 2067-2070
 0,  0, // 2071-2072
 0,  0, // 2073-2074
 0,  0, // 2075-2076
 0,  0, // 2077-2078
 0,  0,  0, // 2079-2081
 0,  0,  0, // 2082-2084
 0,  0,  0, // 2085-2087
 0,  0,  0, // 2088-2090
 0,  0,  0, // 2091-2093
 0,  0,  0, // 2094-2096
 0,  0,  0, // 2097-2099
 0,  0,  0, // 2100-2102
 0,  0,  0, // 2103-2105
 0,  0,  0, // 2106-2108
 0,  0,  0, // 2109-2111
 0,  0,  0, // 2112-2114
 0,  0,  0, // 2115-2117
 0,  0,  0, // 2118-2120
 0,  0,  0, // 2121-2123
 0,  0,  0, // 2124-2126
 0,  0,  0, // 2127-2129
 0,  0,  0, // 2130-2132
 0,  0,  0, // 2133-2135
 0,  0,  0,  0, // 2136-2139
 0,  0,  0,  0, // 2140-2143
 0,  0,  0,  0, // 2144-2147
 0,  0,  0,  0, // 2148-2151
 0,  0,  0,  0, // 2152-2155
 0,  0,  0,  0, // 2156-2159
 0,  0,  0,  0, // 2160-2163
 0,  0,  0,  0, // 2164-2167
 0,  0,  0,  0, // 2168-2171
 0,  0,  0,  0, // 2172-2175
 0,  0,  0,  0, // 2176-2179
 0,  0,  0,  0, // 2180-2183
 0,  0, // 2184-2185
 0,  0, // 2186-2187
 0,  0, // 2188-2189
 0,  0, // 2190-2191
 0,  0, // 2192-2193
 0,  0, // 2194-2195
 0,  0, // 2196-2197
 0,  0, // 2198-2199
 0,  0, // 2200-2201
 0,  0, // 2202-2203
 0,  0, // 2204-2205
 0,  0, // 2206-2207
 0,  0, // 2208-2209
 0,  0, // 2210-2211
 0, // 2212
 0,  0,  0, // 2213-2215
 0,  0, // 2216-2217
 0,  0, // 2218-2219
 0,  0, // 2220-2221
 0,  0, // 2222-2223
 0,  0, // 2224-2225
 0,  0, // 2226-2227
 0,  0, // 2228-2229
 0,  0, // 2230-2231
 0,  0,  0, // 2232-2234
 0,  0,  0, // 2235-2237
 0,  0,  0, // 2238-2240
 0,  0,  0, // 2241-2243
 0,  0, // 2244-2245
 0,  0, // 2246-2247
 0, // 2248
 0, // 2249
 0, // 2250
 0,  0, // 2251-2252
 0,  0, // 2253-2254
 0,  0, // 2255-2256
 0,  0, // 2257-2258
 0,  0,  0,  0, // 2259-2262
 0,  0,  0,  0, // 2263-2266
 0,  0,  0,  0, // 2267-2270
 0,  0,  0,  0, // 2271-2274
 0,  0,  0,  0, // 2275-2278
 0,  0,  0,  0, // 2279-2282
 0,  0, // 2283-2284
 0,  0,  0, // 2285-2287
 0,  0,  0, // 2288-2290
 0,  0,  0,  0, // 2291-2294
 0,  0,  0,  0, // 2295-2298
 0,  0,  0,  0, // 2299-2302
 0,  0,  0,  0,  0, // 2303-2307
 0,  0,  0,  0, // 2308-2311
 0,  0,  0, // 2312-2314
 0,  0,  0,  0,  0, // 2315-2319
 0,  0,  0,  0,  0,  0, // 2320-2325
 0,  0,  0,  0,  0,  0, // 2326-2331
 0,  0,  0,  0, // 2332-2335
 0,  0,  0,  0, // 2336-2339
 0,  0,  0,  0,  0, // 2340-2344
 0,  0,  0,  0,  0, // 2345-2349
 0,  0,  0,  0,  0, // 2350-2354
 0,  0,  0,  0,  0, // 2355-2359
 0,  0,  0,  0,  0,  0, // 2360-2365
 0,  0,  0,  0,  0,  0, // 2366-2371
 0,  0, // 2372-2373
 0,  0,  0,  0, // 2374-2377
 0,  0,  0,  0, // 2378-2381
 0,  0,  0,  0,  0,  0, // 2382-2387
 0,  0,  0, // 2388-2390
 0,  0,  0,  0,  0,  0, // 2391-2396
 0,  0,  0,  0,  0,  0,  0,  0, // 2397-2404
 0,  0,  0,  0,  0, // 2405-2409
 0,  0,  0,  0,  0,  0,  0,  0, // 2410-2417
 0,  0,  0,  0, // 2418-2421
 0,  0,  0,  0,  0,  0,  0,  0, // 2422-2429
 0,  0,  0,  0,  0,  0, // 2430-2435
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 2436-2445
 0,  0,  0,  0,  0,  0, // 2446-2451
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 2452-2461
 0,  0,  0,  0,  0, // 2462-2466
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 2467-2476
 0,  0,  0,  0,  0,  0,  0, // 2477-2483
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 2484-2495
 0,  0,  0,  0,  0,  0,  0, // 2496-2502
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 2503-2514
 0,  0,  0, // 2515-2517
 0,  0,  0,  0, // 2518-2521
 0,  0,  0, // 2522-2524
 0,  0,  0,  0, // 2525-2528
 0,  0,  0,  0,  0, // 2529-2533
 0,  0,  0,  0,  0, // 2534-2538
 0,  0,  0,  0,  0,  0,  0, // 2539-2545
 0,  0,  0,  0,  0,  0, // 2546-2551
 0,  0,  0,  0,  0,  0, // 2552-2557
 0,  0,  0,  0,  0,  0,  0,  0, // 2558-2565
 0,  0,  0,  0, // 2566-2569
 0,  0,  0, // 2570-2572
 0,  0,  0,  0,  0,  0, // 2573-2578
 0,  0,  0,  0,  0,  0,  0,  0, // 2579-2586
 0,  0,  0, // 2587-2589
 0,  0,  0,  0,  0, // 2590-2594
 0,  0,  0,  0,  0,  0,  0, // 2595-2601
 0,  0,  0,  0,  0,  0, // 2602-2607
 0,  0,  0,  0,  0,  0,  0,  0, // 2608-2615
 0,  0,  0, // 2616-2618
 0,  0,  0,  0,  0, // 2619-2623
 0,  0,  0,  0, // 2624-2627
 0,  0,  0,  0,  0,  0, // 2628-2633
 0,  0,  0,  0,  0, // 2634-2638
 0,  0,  0,  0,  0,  0,  0, // 2639-2645
 0,  0,  0,  0,  0,  0, // 2646-2651
 0,  0,  0,  0,  0,  0,  0,  0, // 2652-2659
 0,  0,  0, // 2660-2662
 0,  0, // 2663-2664
 0,  0,  0, // 2665-2667
 0,  0, // 2668-2669
 0,  0, // 2670-2671
 0,  0,  0, // 2672-2674
 0,  0,  0,  0, // 2675-2678
 0,  0,  0,  0, // 2679-2682
 0,  0,  0,  0, // 2683-2686
 0,  0, // 2687-2688
 0,  0,  0, // 2689-2691
 0,  0,  0,  0, // 2692-2695
 0,  0,  0,  0, // 2696-2699
 0,  0, // 2700-2701
 0,  0, // 2702-2703
 0, // 2704
 0,  0, // 2705-2706
 0,  0,  0, // 2707-2709
 0,  0,  0, // 2710-2712
 0,  0, // 2713-2714
 0,  0, // 2715-2716
 0, // 2717
 0,  0,  0,  0,  0, // 2718-2722
 0,  0,  0,  0,  0, // 2723-2727
 0,  0,  0,  0,  0, // 2728-2732
 0,  0,  0,  0, // 2733-2736
 0,  0,  0, // 2737-2739
 0,  0,  0, // 2740-2742
 0,  0,  0, // 2743-2745
 0,  0,  0, // 2746-2748
 0,  0,  0,  0, // 2749-2752
 0,  0, // 2753-2754
 0,  0, // 2755-2756
 0,  0,  0,  0, // 2757-2760
 0,  0,  0, // 2761-2763
 0,  0,  0, // 2764-2766
 0,  0,  0, // 2767-2769
 0,  0,  0,  0, // 2770-2773
 0, // 2774
 0, // 2775
 0,  0, // 2776-2777
 0,  0, // 2778-2779
 0,  0,  0, // 2780-2782
 0, // 2783
 0, // 2784
 0, // 2785
 0,  0, // 2786-2787
 0,  0,  0, // 2788-2790
 0,  0, // 2791-2792
 0,  0,  0, // 2793-2795
 0, // 2796
 0,  0, // 2797-2798
 0,  0,  0, // 2799-2801
 0,  0,  0, // 2802-2804
 0,  0,  0, // 2805-2807
 0,  0,  0, // 2808-2810
 0,  0,  0, // 2811-2813
 0,  0,  0, // 2814-2816
 0,  0, // 2817-2818
 0,  0,  0,  0, // 2819-2822
 0,  0,  0,  0, // 2823-2826
 0,  0,  0, // 2827-2829
 0,  0,  0,  0, // 2830-2833
 0, // 2834
 0,  0,  0,  0, // 2835-2838
 0,  0,  0, // 2839-2841
 0,  0,  0,  0, // 2842-2845
 0,  0,  0, // 2846-2848
 0,  0,  0, // 2849-2851
 0,  0,  0,  0, // 2852-2855
 0,  0,  0, // 2856-2858
 0,  0,  0, // 2859-2861
 0,  0,  0, // 2862-2864
 0,  0, // 2865-2866
 0, // 2867
 0,  0, // 2868-2869
 0,  0,  0, // 2870-2872
 0,  0,  0, // 2873-2875
 0,  0,  0,  0, // 2876-2879
 0,  0,  0,  0, // 2880-2883
 0,  0,  0, // 2884-2886
 0,  0,  0, // 2887-2889
 0,  0,  0, // 2890-2892
 0,  0,  0, // 2893-2895
 0,  0, // 2896-2897
 0,  0, // 2898-2899
 0,  0, // 2900-2901
 0,  0, // 2902-2903
 0,  0,  0, // 2904-2906
 0,  0,  0, // 2907-2909
 0,  0,  0, // 2910-2912
 0,  0,  0, // 2913-2915
 0,  0,  0, // 2916-2918
 0,  0,  0, // 2919-2921
 0,  0,  0, // 2922-2924
 0, // 2925
 0,  0,  0, // 2926-2928
 0,  0,  0, // 2929-2931
 0,  0, // 2932-2933
 0,  0, // 2934-2935
 0,  0, // 2936-2937
 0,  0, // 2938-2939
 0,  0,  0, // 2940-2942
 0,  0,  0, // 2943-2945
 0,  0, // 2946-2947
 0,  0, // 2948-2949
 0,  0, // 2950-2951
 0,  0,  0, // 2952-2954
 0,  0,  0, // 2955-2957
 0,  0,  0,  0, // 2958-2961
 0,  0,  0,  0, // 2962-2965
 0,  0,  0,  0, // 2966-2969
 0,  0,  0,  0, // 2970-2973
 0,  0, // 2974-2975
 0,  0,  0, // 2976-2978
 0,  0, // 2979-2980
 0,  0,  0,  0, // 2981-2984
 0,  0,  0,  0, // 2985-2988
 0,  0,  0,  0,  0,  0, // 2989-2994
 0,  0, // 2995-2996
 0,  0,  0,  0,  0, // 2997-3001
 0,  0,  0,  0, // 3002-3005
 0,  0,  0,  0, // 3006-3009
 0,  0,  0, // 3010-3012
 0,  0,  0, // 3013-3015
 0,  0,  0, // 3016-3018
 0,  0,  0,  0,  0, // 3019-3023
 0,  0,  0,  0,  0,  0, // 3024-3029
 0,  0,  0,  0,  0,  0,  0,  0, // 3030-3037
 0,  0,  0, // 3038-3040
 0,  0,  0,  0,  0,  0, // 3041-3046
 0,  0,  0,  0,  0, // 3047-3051
 0,  0,  0,  0,  0,  0, // 3052-3057
 0,  0,  0,  0, // 3058-3061
 0,  0,  0,  0,  0,  0, // 3062-3067
 0,  0,  0,  0,  0,  0,  0,  0, // 3068-3075
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 3076-3085
 0,  0,  0,  0, // 3086-3089
 0,  0,  0,  0,  0, // 3090-3094
 0,  0,  0,  0,  0, // 3095-3099
 0,  0,  0,  0,  0,  0,  0, // 3100-3106
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 3107-3116
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 3117-3128
 0,  0,  0,  0,  0, // 3129-3133
 0,  0,  0,  0,  0,  0, // 3134-3139
 0,  0,  0,  0,  0, // 3140-3144
 0,  0,  0,  0, // 3145-3148
 0,  0, // 3149-3150
 0,  0, // 3151-3152
 0,  0,  0,  0, // 3153-3156
 0,  0,  0,  0, // 3157-3160
 0,  0,  0,  0, // 3161-3164
 0,  0,  0,  0, // 3165-3168
 0,  0,  0,  0, // 3169-3172
 0,  0,  0,  0, // 3173-3176
 0,  0,  0,  0, // 3177-3180
 0,  0,  0,  0, // 3181-3184
 0,  0,  0, // 3185-3187
 0,  0, // 3188-3189
 0,  0, // 3190-3191
 0,  0,  0, // 3192-3194
 0,  0, // 3195-3196
 0,  0, // 3197-3198
 0,  0,  0, // 3199-3201
 0,  0,  0, // 3202-3204
 0,  0,  0, // 3205-3207
 0,  0,  0, // 3208-3210
 0,  0,  0, // 3211-3213
 0,  0,  0, // 3214-3216
 0,  0,  0, // 3217-3219
 0,  0,  0, // 3220-3222
 0,  0,  0, // 3223-3225
 0,  0,  0, // 3226-3228
 0,  0,  0, // 3229-3231
 0,  0,  0, // 3232-3234
 0,  0, // 3235-3236
 0,  0,  0, // 3237-3239
 0,  0,  0, // 3240-3242
 0,  0,  0, // 3243-3245
 0,  0,  0, // 3246-3248
 0,  0,  0, // 3249-3251
 0,  0, // 3252-3253
 0,  0, // 3254-3255
 0,  0, // 3256-3257
 0,  0, // 3258-3259
 0,  0, // 3260-3261
 0,  0, // 3262-3263
 0,  0,  0, // 3264-3266
 0,  0,  0,  0,  0, // 3267-3271
 0,  0,  0, // 3272-3274
 0,  0,  0,  0,  0,  0, // 3275-3280
 0,  0,  0,  0,  0,  0, // 3281-3286
 0,  0,  0,  0,  0, // 3287-3291
 0,  0,  0,  0,  0, // 3292-3296
 0,  0,  0,  0,  0,  0,  0,  0, // 3297-3304
 0,  0,  0,  0,  0,  0,  0, // 3305-3311
 0,  0,  0,  0, // 3312-3315
 0,  0,  0,  0, // 3316-3319
 0,  0,  0,  0,  0,  0, // 3320-3325
 0,  0,  0,  0, // 3326-3329
 0,  0,  0,  0,  0,  0, // 3330-3335
 0,  0,  0,  0,  0,  0,  0,  0, // 3336-3343
 0,  0,  0,  0,  0, // 3344-3348
 0,  0,  0,  0,  0,  0,  0, // 3349-3355
 0,  0,  0,  0,  0, // 3356-3360
 0,  0,  0,  0,  0,  0,  0, // 3361-3367
 0,  0,  0,  0,  0,  0, // 3368-3373
 0,  0,  0,  0,  0,  0,  0,  0, // 3374-3381
 0,  0,  0,  0,  0,  0, // 3382-3387
 0,  0,  0,  0,  0,  0,  0,  0, // 3388-3395
 0,  0,  0,  0,  0, // 3396-3400
 0,  0,  0,  0, // 3401-3404
 0,  0, // 3405-3406
 0,  0, // 3407-3408
 0,  0,  0, // 3409-3411
 0,  0,  0, // 3412-3414
 0,  0,  0,  0, // 3415-3418
 0,  0,  0,  0,  0, // 3419-3423
 0,  0,  0,  0,  0,  0, // 3424-3429
 0,  0,  0,  0, // 3430-3433
 0,  0,  0,  0,  0, // 3434-3438
 0,  0,  0,  0,  0,  0, // 3439-3444
 0,  0,  0,  0,  0,  0,  0, // 3445-3451
 0,  0, // 3452-3453
 0,  0, // 3454-3455
 0,  0, // 3456-3457
 0,  0, // 3458-3459
 0,  0,  0,  0, // 3460-3463
 0,  0,  0,  0, // 3464-3467
 0,  0,  0,  0, // 3468-3471
 0,  0,  0, // 3472-3474
 0,  0, // 3475-3476
 0,  0, // 3477-3478
 0, // 3479
 0,  0, // 3480-3481
 0,  0, // 3482-3483
 0,  0, // 3484-3485
 0,  0, // 3486-3487
 0,  0, // 3488-3489
 0, // 3490
 0,  0, // 3491-3492
 0,  0,  0, // 3493-3495
 0,  0, // 3496-3497
 0,  0, // 3498-3499
 0,  0,  0,  0, // 3500-3503
 0,  0, // 3504-3505
 0, // 3506
 0,  0, // 3507-3508
 0,  0, // 3509-3510
 0,  0,  0, // 3511-3513
 0,  0, // 3514-3515
 0,  0,  0, // 3516-3518
 0,  0,  0, // 3519-3521
 0,  0,  0, // 3522-3524
 0,  0, // 3525-3526
 0,  0, // 3527-3528
 0,  0,  0, // 3529-3531
 0,  0,  0,  0, // 3532-3535
 0,  0,  0,  0, // 3536-3539
 0,  0,  0, // 3540-3542
 0,  0,  0, // 3543-3545
 0,  0, // 3546-3547
 0,  0,  0, // 3548-3550
 0,  0, // 3551-3552
 0,  0, // 3553-3554
 0, // 3555
 0, // 3556
 0, // 3557
 0,  0, // 3558-3559
 0,  0,  0,  0, // 3560-3563
 0,  0,  0, // 3564-3566
 0,  0,  0,  0, // 3567-3570
 0,  0,  0,  0, // 3571-3574
 0,  0,  0, // 3575-3577
 0,  0,  0,  0, // 3578-3581
 0,  0,  0, // 3582-3584
 0,  0,  0, // 3585-3587
 0,  0,  0, // 3588-3590
 0,  0,  0,  0, // 3591-3594
 0,  0, // 3595-3596
 0,  0, // 3597-3598
 0,  0, // 3599-3600
 0, // 3601
 0, // 3602
 0, // 3603
 0,  0, // 3604-3605
 0,  0, // 3606-3607
 0,  0,  0, // 3608-3610
 0,  0,  0, // 3611-3613
 0,  0,  0, // 3614-3616
 0,  0,  0, // 3617-3619
 0,  0,  0,  0, // 3620-3623
 0,  0,  0, // 3624-3626
 0,  0,  0, // 3627-3629
 0,  0,  0,  0, // 3630-3633
 0,  0,  0,  0, // 3634-3637
 0,  0,  0,  0, // 3638-3641
 0,  0,  0,  0, // 3642-3645
 0,  0,  0,  0, // 3646-3649
 0,  0,  0,  0, // 3650-3653
 0,  0,  0,  0, // 3654-3657
 0,  0,  0,  0, // 3658-3661
 0,  0,  0,  0, // 3662-3665
 0,  0,  0, // 3666-3668
 0,  0,  0, // 3669-3671
 0,  0,  0, // 3672-3674
 0,  0, // 3675-3676
 0,  0, // 3677-3678
 0,  0, // 3679-3680
 0,  0,  0, // 3681-3683
 0,  0,  0, // 3684-3686
 0,  0,  0, // 3687-3689
 0,  0,  0, // 3690-3692
 0,  0,  0, // 3693-3695
 0,  0, // 3696-3697
 0,  0,  0, // 3698-3700
 0,  0,  0, // 3701-3703
 0,  0,  0,  0, // 3704-3707
 0,  0,  0, // 3708-3710
 0,  0,  0,  0, // 3711-3714
 0,  0,  0,  0, // 3715-3718
 0,  0,  0, // 3719-3721
 0,  0, // 3722-3723
 0,  0, // 3724-3725
 0,  0, // 3726-3727
 0,  0,  0, // 3728-3730
 0,  0,  0, // 3731-3733
 0,  0, // 3734-3735
 0,  0,  0,  0, // 3736-3739
 0,  0,  0,  0,  0, // 3740-3744
 0,  0,  0,  0,  0, // 3745-3749
 0,  0,  0,  0,  0, // 3750-3754
 0,  0,  0, // 3755-3757
 0,  0,  0, // 3758-3760
 0,  0,  0, // 3761-3763
 0,  0,  0, // 3764-3766
 0,  0,  0, // 3767-3769
 0,  0,  0, // 3770-3772
 0,  0, // 3773-3774
 0,  0, // 3775-3776
 0,  0,  0,  0, // 3777-3780
 0,  0,  0, // 3781-3783
 0,  0,  0,  0, // 3784-3787
 0,  0,  0, // 3788-3790
 0,  0, // 3791-3792
 0,  0, // 3793-3794
 0,  0,  0, // 3795-3797
 0,  0,  0,  0, // 3798-3801
 0, // 3802
 0,  0, // 3803-3804
 0,  0, // 3805-3806
 0,  0,  0, // 3807-3809
 0,  0,  0, // 3810-3812
 0,  0,  0, // 3813-3815
 0,  0,  0, // 3816-3818
 0, // 3819
 0,  0,  0, // 3820-3822
 0,  0,  0, // 3823-3825
 0,  0,  0, // 3826-3828
 0,  0,  0, // 3829-3831
 0,  0,  0, // 3832-3834
 0,  0,  0, // 3835-3837
 0,  0, // 3838-3839
 0,  0, // 3840-3841
 0,  0,  0, // 3842-3844
 0,  0,  0, // 3845-3847
 0,  0,  0, // 3848-3850
 0,  0,  0, // 3851-3853
 0,  0,  0, // 3854-3856
 0,  0,  0, // 3857-3859
 0,  0, // 3860-3861
 0,  0, // 3862-3863
 0,  0,  0,  0, // 3864-3867
 0,  0,  0,  0, // 3868-3871
 0,  0, // 3872-3873
 0,  0, // 3874-3875
 0,  0, // 3876-3877
 0,  0, // 3878-3879
 0,  0,  0, // 3880-3882
 0,  0,  0, // 3883-3885
 0,  0,  0, // 3886-3888
 0,  0,  0, // 3889-3891
 0,  0,  0, // 3892-3894
 0,  0,  0, // 3895-3897
 0,  0, // 3898-3899
 0,  0, // 3900-3901
 0,  0,  0, // 3902-3904
 0,  0,  0, // 3905-3907
 0,  0,  0, // 3908-3910
 0,  0,  0, // 3911-3913
 0,  0, // 3914-3915
 0,  0, // 3916-3917
 0,  0,  0, // 3918-3920
 0,  0,  0, // 3921-3923
 0,  0,  0, // 3924-3926
 0,  0,  0, // 3927-3929
 0,  0,  0, // 3930-3932
 0,  0,  0,  0, // 3933-3936
 0,  0,  0,  0, // 3937-3940
 0,  0,  0,  0,  0, // 3941-3945
 0,  0,  0,  0,  0, // 3946-3950
 0,  0,  0,  0,  0,  0, // 3951-3956
 0,  0,  0,  0,  0,  0, // 3957-3962
 0,  0,  0,  0,  0,  0,  0, // 3963-3969
 0,  0,  0,  0, // 3970-3973
 0,  0,  0,  0, // 3974-3977
 0,  0,  0,  0, // 3978-3981
 0,  0, // 3982-3983
 0,  0, // 3984-3985
 0,  0, // 3986-3987
 0,  0, // 3988-3989
 0,  0,  0, // 3990-3992
 0,  0,  0, // 3993-3995
 0,  0,  0, // 3996-3998
 0,  0,  0, // 3999-4001
 0,  0,  0, // 4002-4004
 0,  0,  0, // 4005-4007
 0,  0,  0, // 4008-4010
 0,  0,  0, // 4011-4013
 0,  0,  0, // 4014-4016
 0,  0,  0, // 4017-4019
 0,  0,  0, // 4020-4022
 0,  0,  0, // 4023-4025
 0,  0,  0, // 4026-4028
 0,  0,  0, // 4029-4031
 0,  0,  0, // 4032-4034
 0,  0,  0, // 4035-4037
 0,  0,  0, // 4038-4040
 0,  0,  0, // 4041-4043
 0,  0,  0, // 4044-4046
 0,  0,  0,  0, // 4047-4050
 0,  0,  0,  0, // 4051-4054
 0,  0,  0,  0, // 4055-4058
 0,  0,  0,  0, // 4059-4062
 0,  0,  0,  0, // 4063-4066
 0,  0,  0,  0, // 4067-4070
 0,  0,  0,  0, // 4071-4074
 0,  0,  0,  0, // 4075-4078
 0,  0,  0,  0, // 4079-4082
 0,  0,  0,  0, // 4083-4086
 0,  0,  0,  0, // 4087-4090
 0,  0,  0,  0, // 4091-4094
 0,  0, // 4095-4096
 0,  0, // 4097-4098
 0,  0, // 4099-4100
 0,  0, // 4101-4102
 0,  0, // 4103-4104
 0,  0, // 4105-4106
 0,  0, // 4107-4108
 0,  0, // 4109-4110
 0,  0, // 4111-4112
 0,  0, // 4113-4114
 0,  0, // 4115-4116
 0,  0, // 4117-4118
 0, // 4119
 0,  0,  0, // 4120-4122
 0,  0, // 4123-4124
 0,  0, // 4125-4126
 0,  0, // 4127-4128
 0,  0, // 4129-4130
 0,  0, // 4131-4132
 0,  0, // 4133-4134
 0,  0, // 4135-4136
 0,  0, // 4137-4138
 0,  0,  0, // 4139-4141
 0,  0,  0, // 4142-4144
 0,  0,  0, // 4145-4147
 0,  0,  0, // 4148-4150
 0,  0, // 4151-4152
 0,  0, // 4153-4154
 0, // 4155
 0, // 4156
 0, // 4157
 0,  0, // 4158-4159
 0,  0, // 4160-4161
 0,  0, // 4162-4163
 0,  0, // 4164-4165
 0,  0,  0,  0, // 4166-4169
 0,  0,  0,  0, // 4170-4173
 0,  0,  0,  0, // 4174-4177
 0,  0,  0,  0,  0, // 4178-4182
 0,  0,  0,  0, // 4183-4186
 0,  0,  0,  0,  0, // 4187-4191
 0,  0, // 4192-4193
 0,  0,  0, // 4194-4196
 0,  0,  0, // 4197-4199
 0,  0,  0,  0, // 4200-4203
 0,  0,  0,  0, // 4204-4207
 0,  0,  0,  0, // 4208-4211
 0,  0,  0,  0,  0, // 4212-4216
 0,  0,  0,  0, // 4217-4220
 0,  0,  0, // 4221-4223
 0,  0,  0,  0,  0, // 4224-4228
 0,  0,  0,  0,  0,  0, // 4229-4234
 0,  0,  0,  0,  0,  0, // 4235-4240
 0,  0,  0,  0, // 4241-4244
 0,  0,  0,  0, // 4245-4248
 0,  0,  0,  0,  0, // 4249-4253
 0,  0,  0,  0,  0, // 4254-4258
 0,  0,  0,  0,  0, // 4259-4263
 0,  0,  0,  0,  0, // 4264-4268
 0,  0,  0,  0,  0,  0, // 4269-4274
 0,  0,  0,  0,  0,  0, // 4275-4280
 0,  0, // 4281-4282
 0,  0,  0,  0, // 4283-4286
 0,  0,  0,  0, // 4287-4290
 0,  0,  0,  0,  0,  0, // 4291-4296
 0,  0,  0, // 4297-4299
 0,  0,  0,  0,  0,  0, // 4300-4305
 0,  0,  0,  0,  0,  0,  0,  0, // 4306-4313
 0,  0,  0,  0,  0, // 4314-4318
 0,  0,  0,  0,  0,  0,  0,  0, // 4319-4326
 0,  0,  0,  0, // 4327-4330
 0,  0,  0,  0,  0,  0,  0,  0, // 4331-4338
 0,  0,  0,  0,  0,  0, // 4339-4344
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 4345-4354
 0,  0,  0,  0,  0,  0, // 4355-4360
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 4361-4370
 0,  0,  0,  0,  0, // 4371-4375
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 4376-4385
 0,  0,  0,  0,  0,  0,  0, // 4386-4392
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 4393-4404
 0,  0,  0,  0,  0,  0,  0, // 4405-4411
 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, // 4412-4423
 0,  0,  0, // 4424-4426
 0,  0,  0,  0, // 4427-4430
 0,  0,  0, // 4431-4433
 0,  0,  0,  0, // 4434-4437
 0,  0,  0,  0,  0, // 4438-4442
 0,  0,  0,  0,  0, // 4443-4447
 0,  0,  0,  0,  0,  0,  0, // 4448-4454
 0,  0,  0,  0,  0,  0, // 4455-4460
 0,  0,  0,  0,  0,  0, // 4461-4466
 0,  0,  0,  0,  0,  0,  0,  0, // 4467-4474
 0,  0,  0,  0, // 4475-4478
 0,  0,  0, // 4479-4481
 0,  0,  0,  0,  0,  0, // 4482-4487
 0,  0,  0,  0,  0,  0,  0,  0, // 4488-4495
 0,  0,  0, // 4496-4498
 0,  0,  0,  0,  0, // 4499-4503
 0,  0,  0,  0,  0,  0,  0, // 4504-4510
 0,  0,  0,  0,  0,  0, // 4511-4516
 0,  0,  0,  0,  0,  0,  0,  0, // 4517-4524
 0,  0,  0, // 4525-4527
 0,  0,  0,  0,  0, // 4528-4532
 0,  0,  0,  0, // 4533-4536
 0,  0,  0,  0,  0,  0, // 4537-4542
 0,  0,  0,  0,  0, // 4543-4547
 0,  0,  0,  0,  0,  0,  0, // 4548-4554
 0,  0,  0,  0,  0,  0, // 4555-4560
 0,  0,  0,  0,  0,  0,  0,  0, // 4561-4568
 0,  0,  0, // 4569-4571
 0,  0, // 4572-4573
 0,  0,  0, // 4574-4576
 0,  0, // 4577-4578
 0 // End bypass tables
};

static const llvm::InstrItinerary ARMV6Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 1, 2, 1, 3 }, // 1 IIC_iALUi_WriteALU_ReadALU
  { 1, 1, 2, 3, 6 }, // 2 IIC_iALUr_WriteALU_ReadALU_ReadALU
  { 1, 2, 3, 6, 10 }, // 3 IIC_iALUsr_WriteALUsi_ReadALU
  { 1, 2, 3, 10, 14 }, // 4 IIC_iALUsr_WriteALUsr_ReadALUsr
  { 1, 2, 3, 14, 18 }, // 5 IIC_iALUsr_WriteALUSsr_ReadALUsr
  { 1, 1, 2, 18, 20 }, // 6 IIC_iBITi_WriteALU_ReadALU
  { 1, 1, 2, 20, 23 }, // 7 IIC_iBITr_WriteALU_ReadALU_ReadALU
  { 1, 2, 3, 23, 27 }, // 8 IIC_iBITsr_WriteALUsi_ReadALU
  { 1, 2, 3, 27, 31 }, // 9 IIC_iBITsr_WriteALUsr_ReadALUsr
  { 1, 1, 2, 0, 0 }, // 10 IIC_Br_WriteBr
  { 1, 1, 2, 31, 33 }, // 11 IIC_iUNAsi
  { 1, 1, 2, 0, 0 }, // 12 IIC_Br_WriteBrL
  { 0, 0, 0, 0, 0 }, // 13 WriteBrL
  { 1, 1, 2, 0, 0 }, // 14 IIC_Br_WriteBrTbl
  { 0, 0, 0, 0, 0 }, // 15 WriteBr
  { 1, 1, 2, 33, 35 }, // 16 IIC_iUNAr_WriteALU
  { 1, 1, 2, 35, 36 }, // 17 IIC_iCMPi_WriteCMP_ReadALU
  { 1, 1, 2, 36, 38 }, // 18 IIC_iCMPr_WriteCMP_ReadALU_ReadALU
  { 1, 2, 3, 38, 41 }, // 19 IIC_iCMPsr_WriteCMPsi_ReadALU
  { 1, 2, 3, 41, 44 }, // 20 IIC_iCMPsr_WriteCMPsr_ReadALU
  { 1, 1, 2, 44, 46 }, // 21 IIC_fpUNA64
  { 1, 1, 2, 46, 48 }, // 22 IIC_fpUNA32
  { 1, 1, 2, 48, 49 }, // 23 IIC_fpSTAT
  { 1, 3, 4, 49, 54 }, // 24 IIC_iLoad_m
  { 1, 3, 4, 54, 59 }, // 25 IIC_iLoad_mu
  { 1, 4, 6, 59, 64 }, // 26 IIC_iLoad_mBr
  { 1, 1, 2, 64, 68 }, // 27 IIC_iLoad_bh_ru
  { 1, 1, 2, 68, 71 }, // 28 IIC_iLoad_bh_iu
  { 1, 1, 2, 71, 74 }, // 29 IIC_iLoad_bh_r
  { 1, 2, 3, 74, 77 }, // 30 IIC_iLoad_bh_si
  { 1, 1, 2, 77, 80 }, // 31 IIC_iLoad_d_r
  { 1, 1, 2, 80, 84 }, // 32 IIC_iLoad_d_ru
  { 1, 1, 2, 84, 86 }, // 33 IIC_iLoad_i
  { 1, 6, 8, 86, 88 }, // 34 IIC_iLoadiALU
  { 1, 1, 2, 88, 92 }, // 35 IIC_iLoad_ru
  { 1, 1, 2, 92, 95 }, // 36 IIC_iLoad_iu
  { 1, 1, 2, 95, 98 }, // 37 IIC_iLoad_r
  { 1, 2, 3, 98, 101 }, // 38 IIC_iLoad_si
  { 1, 2, 3, 101, 105 }, // 39 IIC_iMAC32
  { 1, 1, 2, 105, 106 }, // 40 IIC_iCMOVi_WriteALU
  { 1, 1, 2, 106, 107 }, // 41 IIC_iMOVi_WriteALU
  { 1, 6, 8, 107, 108 }, // 42 IIC_iCMOVix2
  { 1, 1, 2, 108, 110 }, // 43 IIC_iCMOVr_WriteALU
  { 1, 1, 2, 110, 113 }, // 44 IIC_iCMOVsr_WriteALU
  { 1, 8, 11, 113, 114 }, // 45 IIC_iMOVix2addpc
  { 1, 8, 11, 114, 115 }, // 46 IIC_iMOVix2ld
  { 1, 6, 8, 115, 116 }, // 47 IIC_iMOVix2
  { 1, 1, 2, 116, 118 }, // 48 IIC_iMOVr_WriteALU
  { 1, 2, 3, 118, 121 }, // 49 IIC_iMOVsr_WriteALU
  { 1, 1, 2, 121, 123 }, // 50 IIC_iMOVsi_WriteALU
  { 1, 2, 3, 123, 126 }, // 51 IIC_iMUL32
  { 1, 1, 2, 126, 127 }, // 52 IIC_iMVNi_WriteALU
  { 1, 1, 2, 127, 129 }, // 53 IIC_iMVNr_WriteALU
  { 1, 2, 3, 129, 132 }, // 54 IIC_iMVNsr_WriteALU
  { 1, 1, 2, 132, 135 }, // 55 IIC_iALUr_WriteALU_ReadALU
  { 1, 1, 2, 135, 138 }, // 56 IIC_iStore_r
  { 1, 1, 2, 138, 141 }, // 57 IIC_iStore_bh_r
  { 1, 1, 2, 141, 144 }, // 58 IIC_iALUsi_WriteALUsi_ReadALU
  { 1, 1, 2, 144, 147 }, // 59 IIC_iBITsi_WriteALUsi_ReadALU
  { 0, 0, 0, 0, 0 }, // 60 IIC_Preload_WritePreLd
  { 0, 0, 0, 0, 0 }, // 61 IIC_iDIV
  { 1, 1, 2, 147, 151 }, // 62 IIC_iMAC16
  { 1, 3, 4, 151, 155 }, // 63 IIC_iMAC64
  { 1, 1, 2, 155, 158 }, // 64 IIC_iMUL16
  { 1, 3, 4, 158, 161 }, // 65 IIC_iMUL64
  { 1, 3, 4, 0, 0 }, // 66 IIC_iStore_m
  { 1, 3, 4, 161, 162 }, // 67 IIC_iStore_mu
  { 1, 1, 2, 162, 166 }, // 68 IIC_iStore_bh_ru
  { 1, 1, 2, 166, 169 }, // 69 IIC_iStore_bh_iu
  { 1, 1, 2, 169, 173 }, // 70 IIC_iStore_ru
  { 1, 2, 3, 173, 176 }, // 71 IIC_iStore_bh_si
  { 1, 1, 2, 176, 179 }, // 72 IIC_iStore_d_r
  { 1, 1, 2, 179, 183 }, // 73 IIC_iStore_d_ru
  { 1, 1, 2, 183, 186 }, // 74 IIC_iStore_iu
  { 1, 2, 3, 186, 189 }, // 75 IIC_iStore_si
  { 1, 1, 2, 0, 0 }, // 76 IIC_Br
  { 1, 1, 2, 189, 192 }, // 77 IIC_iEXTAr_WriteALUsr
  { 1, 1, 2, 192, 194 }, // 78 IIC_iEXTr_WriteALUsi
  { 1, 1, 2, 194, 195 }, // 79 IIC_iTSTi_WriteCMP_ReadALU
  { 1, 1, 2, 195, 197 }, // 80 IIC_iTSTr_WriteCMP_ReadALU_ReadALU
  { 1, 2, 3, 197, 200 }, // 81 IIC_iTSTsr_WriteCMPsi_ReadALU
  { 1, 2, 3, 200, 203 }, // 82 IIC_iTSTsr_WriteCMPsr_ReadALU
  { 0, 0, 0, 0, 0 }, // 83 WriteALU_ReadALU_ReadALU
  { 0, 0, 0, 0, 0 }, // 84 IIC_VABAD
  { 0, 0, 0, 0, 0 }, // 85 IIC_VABAQ
  { 0, 0, 0, 0, 0 }, // 86 IIC_VSUBi4Q
  { 0, 0, 0, 0, 0 }, // 87 IIC_VBIND
  { 0, 0, 0, 0, 0 }, // 88 IIC_VBINQ
  { 0, 0, 0, 0, 0 }, // 89 IIC_VSUBi4D
  { 0, 0, 0, 0, 0 }, // 90 IIC_VUNAD
  { 0, 0, 0, 0, 0 }, // 91 IIC_VUNAQ
  { 0, 0, 0, 0, 0 }, // 92 IIC_VUNAiQ
  { 0, 0, 0, 0, 0 }, // 93 IIC_VUNAiD
  { 1, 1, 2, 203, 206 }, // 94 IIC_fpALU64
  { 0, 0, 0, 0, 0 }, // 95 IIC_VBINi4D
  { 0, 0, 0, 0, 0 }, // 96 IIC_VSHLiD
  { 1, 1, 2, 206, 209 }, // 97 IIC_fpALU32
  { 0, 0, 0, 0, 0 }, // 98 IIC_VSUBiD
  { 0, 0, 0, 0, 0 }, // 99 IIC_VBINiQ
  { 0, 0, 0, 0, 0 }, // 100 IIC_VBINiD
  { 0, 0, 0, 0, 0 }, // 101 IIC_VMOVImm
  { 0, 0, 0, 0, 0 }, // 102 IIC_VCNTiD
  { 0, 0, 0, 0, 0 }, // 103 IIC_VCNTiQ
  { 1, 1, 2, 209, 211 }, // 104 IIC_fpCMP64
  { 1, 1, 2, 211, 213 }, // 105 IIC_fpCMP32
  { 0, 0, 0, 0, 0 }, // 106 IIC_fpCVTSH
  { 0, 0, 0, 0, 0 }, // 107 IIC_fpCVTHS
  { 1, 1, 2, 213, 215 }, // 108 IIC_fpCVTDS
  { 1, 1, 2, 215, 217 }, // 109 IIC_fpCVTSD
  { 1, 11, 12, 217, 220 }, // 110 IIC_fpDIV64
  { 1, 12, 13, 220, 223 }, // 111 IIC_fpDIV32
  { 0, 0, 0, 0, 0 }, // 112 IIC_VMOVIS
  { 0, 0, 0, 0, 0 }, // 113 IIC_VMOVD
  { 0, 0, 0, 0, 0 }, // 114 IIC_VMOVQ
  { 0, 0, 0, 0, 0 }, // 115 IIC_VEXTD
  { 0, 0, 0, 0, 0 }, // 116 IIC_VEXTQ
  { 1, 2, 3, 223, 227 }, // 117 IIC_fpFMAC64
  { 1, 1, 2, 227, 231 }, // 118 IIC_fpFMAC32
  { 0, 0, 0, 0, 0 }, // 119 IIC_VFMACD
  { 0, 0, 0, 0, 0 }, // 120 IIC_VFMACQ
  { 0, 0, 0, 0, 0 }, // 121 IIC_VMOVSI
  { 0, 0, 0, 0, 0 }, // 122 IIC_VBINi4Q
  { 0, 0, 0, 0, 0 }, // 123 IIC_VLD1dup
  { 0, 0, 0, 0, 0 }, // 124 IIC_VLD1dupu
  { 0, 0, 0, 0, 0 }, // 125 IIC_VLD1ln
  { 0, 0, 0, 0, 0 }, // 126 IIC_VLD1lnu
  { 0, 0, 0, 0, 0 }, // 127 IIC_VLD1
  { 0, 0, 0, 0, 0 }, // 128 IIC_VLD1x4
  { 0, 0, 0, 0, 0 }, // 129 IIC_VLD1x2u
  { 0, 0, 0, 0, 0 }, // 130 IIC_VLD1x3
  { 0, 0, 0, 0, 0 }, // 131 IIC_VLD1u
  { 0, 0, 0, 0, 0 }, // 132 IIC_VLD1x2
  { 0, 0, 0, 0, 0 }, // 133 IIC_VLD2dup
  { 0, 0, 0, 0, 0 }, // 134 IIC_VLD2dupu
  { 0, 0, 0, 0, 0 }, // 135 IIC_VLD2ln
  { 0, 0, 0, 0, 0 }, // 136 IIC_VLD2lnu
  { 0, 0, 0, 0, 0 }, // 137 IIC_VLD2
  { 0, 0, 0, 0, 0 }, // 138 IIC_VLD2u
  { 0, 0, 0, 0, 0 }, // 139 IIC_VLD2x2
  { 0, 0, 0, 0, 0 }, // 140 IIC_VLD2x2u
  { 0, 0, 0, 0, 0 }, // 141 IIC_VLD3dup
  { 0, 0, 0, 0, 0 }, // 142 IIC_VLD3dupu
  { 0, 0, 0, 0, 0 }, // 143 IIC_VLD3ln
  { 0, 0, 0, 0, 0 }, // 144 IIC_VLD3lnu
  { 0, 0, 0, 0, 0 }, // 145 IIC_VLD3
  { 0, 0, 0, 0, 0 }, // 146 IIC_VLD3u
  { 0, 0, 0, 0, 0 }, // 147 IIC_VLD4dup
  { 0, 0, 0, 0, 0 }, // 148 IIC_VLD4dupu
  { 0, 0, 0, 0, 0 }, // 149 IIC_VLD4ln
  { 0, 0, 0, 0, 0 }, // 150 IIC_VLD4lnu
  { 0, 0, 0, 0, 0 }, // 151 IIC_VLD4
  { 0, 0, 0, 0, 0 }, // 152 IIC_VLD4u
  { 1, 3, 4, 231, 236 }, // 153 IIC_fpLoad_mu
  { 1, 3, 4, 236, 240 }, // 154 IIC_fpLoad_m
  { 1, 1, 2, 240, 243 }, // 155 IIC_fpLoad64
  { 1, 1, 2, 243, 246 }, // 156 IIC_fpLoad32
  { 1, 2, 3, 246, 250 }, // 157 IIC_fpMAC64
  { 0, 0, 0, 0, 0 }, // 158 IIC_VMACi32D
  { 0, 0, 0, 0, 0 }, // 159 IIC_VMACi16D
  { 1, 1, 2, 250, 254 }, // 160 IIC_fpMAC32
  { 0, 0, 0, 0, 0 }, // 161 IIC_VMACD
  { 0, 0, 0, 0, 0 }, // 162 IIC_VMACQ
  { 0, 0, 0, 0, 0 }, // 163 IIC_VMACi32Q
  { 0, 0, 0, 0, 0 }, // 164 IIC_VMACi16Q
  { 1, 1, 2, 254, 257 }, // 165 IIC_fpMOVID
  { 0, 0, 0, 0, 0 }, // 166 IIC_VQUNAiD
  { 0, 0, 0, 0, 0 }, // 167 IIC_VMOVN
  { 1, 1, 2, 257, 260 }, // 168 IIC_fpMOVDI
  { 1, 1, 2, 260, 262 }, // 169 IIC_fpMOVSI
  { 1, 1, 2, 262, 264 }, // 170 IIC_fpMOVIS
  { 1, 2, 3, 264, 267 }, // 171 IIC_fpMUL64
  { 0, 0, 0, 0, 0 }, // 172 IIC_VMULi16D
  { 0, 0, 0, 0, 0 }, // 173 IIC_VMULi32D
  { 1, 1, 2, 267, 270 }, // 174 IIC_fpMUL32
  { 0, 0, 0, 0, 0 }, // 175 IIC_VFMULD
  { 0, 0, 0, 0, 0 }, // 176 IIC_VFMULQ
  { 0, 0, 0, 0, 0 }, // 177 IIC_VMULi16Q
  { 0, 0, 0, 0, 0 }, // 178 IIC_VMULi32Q
  { 0, 0, 0, 0, 0 }, // 179 IIC_VSHLiQ
  { 0, 0, 0, 0, 0 }, // 180 IIC_VPALiQ
  { 0, 0, 0, 0, 0 }, // 181 IIC_VPALiD
  { 0, 0, 0, 0, 0 }, // 182 IIC_VPBIND
  { 0, 0, 0, 0, 0 }, // 183 IIC_VQUNAiQ
  { 0, 0, 0, 0, 0 }, // 184 IIC_VSHLi4Q
  { 0, 0, 0, 0, 0 }, // 185 IIC_VSHLi4D
  { 0, 0, 0, 0, 0 }, // 186 IIC_VRECSD
  { 0, 0, 0, 0, 0 }, // 187 IIC_VRECSQ
  { 0, 0, 0, 0, 0 }, // 188 IIC_VMOVISL
  { 1, 1, 2, 270, 272 }, // 189 IIC_fpCVTID_WriteCvtFP
  { 1, 1, 2, 272, 274 }, // 190 IIC_fpCVTIS_WriteCvtFP
  { 1, 1, 2, 274, 276 }, // 191 IIC_fpCVTID
  { 1, 1, 2, 276, 278 }, // 192 IIC_fpCVTIS
  { 1, 11, 12, 278, 281 }, // 193 IIC_fpSQRT64
  { 1, 12, 13, 281, 284 }, // 194 IIC_fpSQRT32
  { 0, 0, 0, 0, 0 }, // 195 IIC_VST1ln
  { 0, 0, 0, 0, 0 }, // 196 IIC_VST1lnu
  { 0, 0, 0, 0, 0 }, // 197 IIC_VST1
  { 0, 0, 0, 0, 0 }, // 198 IIC_VST1x4
  { 0, 0, 0, 0, 0 }, // 199 IIC_VLD1x4u
  { 0, 0, 0, 0, 0 }, // 200 IIC_VST1x3
  { 0, 0, 0, 0, 0 }, // 201 IIC_VLD1x3u
  { 0, 0, 0, 0, 0 }, // 202 IIC_VST1x4u
  { 0, 0, 0, 0, 0 }, // 203 IIC_VST1x3u
  { 0, 0, 0, 0, 0 }, // 204 IIC_VST1x2
  { 0, 0, 0, 0, 0 }, // 205 IIC_VST2ln
  { 0, 0, 0, 0, 0 }, // 206 IIC_VST2lnu
  { 0, 0, 0, 0, 0 }, // 207 IIC_VST2
  { 0, 0, 0, 0, 0 }, // 208 IIC_VST2x2
  { 0, 0, 0, 0, 0 }, // 209 IIC_VST2x2u
  { 0, 0, 0, 0, 0 }, // 210 IIC_VST3ln
  { 0, 0, 0, 0, 0 }, // 211 IIC_VST3lnu
  { 0, 0, 0, 0, 0 }, // 212 IIC_VST3
  { 0, 0, 0, 0, 0 }, // 213 IIC_VST3u
  { 0, 0, 0, 0, 0 }, // 214 IIC_VST4ln
  { 0, 0, 0, 0, 0 }, // 215 IIC_VST4lnu
  { 0, 0, 0, 0, 0 }, // 216 IIC_VST4
  { 0, 0, 0, 0, 0 }, // 217 IIC_VST4u
  { 1, 3, 4, 284, 289 }, // 218 IIC_fpStore_mu
  { 1, 3, 4, 289, 293 }, // 219 IIC_fpStore_m
  { 1, 1, 2, 293, 296 }, // 220 IIC_fpStore64
  { 1, 1, 2, 296, 299 }, // 221 IIC_fpStore32
  { 0, 0, 0, 0, 0 }, // 222 IIC_VSUBiQ
  { 0, 0, 0, 0, 0 }, // 223 IIC_VTB1
  { 0, 0, 0, 0, 0 }, // 224 IIC_VTB2
  { 0, 0, 0, 0, 0 }, // 225 IIC_VTB3
  { 0, 0, 0, 0, 0 }, // 226 IIC_VTB4
  { 0, 0, 0, 0, 0 }, // 227 IIC_VTBX1
  { 0, 0, 0, 0, 0 }, // 228 IIC_VTBX2
  { 0, 0, 0, 0, 0 }, // 229 IIC_VTBX3
  { 0, 0, 0, 0, 0 }, // 230 IIC_VTBX4
  { 1, 1, 2, 299, 301 }, // 231 IIC_fpCVTDI_WriteCvtFP
  { 1, 1, 2, 301, 303 }, // 232 IIC_fpCVTSI_WriteCvtFP
  { 1, 1, 2, 303, 305 }, // 233 IIC_fpCVTDI
  { 1, 1, 2, 305, 307 }, // 234 IIC_fpCVTSI
  { 0, 0, 0, 0, 0 }, // 235 IIC_VPERMD
  { 0, 0, 0, 0, 0 }, // 236 IIC_VPERMQ
  { 0, 0, 0, 0, 0 }, // 237 IIC_VPERMQ3
  { 1, 1, 2, 307, 310 }, // 238 IIC_iALUsi_WriteALUsi_ReadALUsr
  { 1, 1, 2, 310, 312 }, // 239 IIC_iBITi
  { 1, 1, 2, 312, 314 }, // 240 IIC_iCMPsi_WriteCMPsi_ReadALU_ReadALU
  { 1, 1, 2, 314, 315 }, // 241 IIC_iCMPi_WriteCMP
  { 1, 1, 2, 315, 317 }, // 242 IIC_iCMPr_WriteCMP
  { 1, 1, 2, 317, 319 }, // 243 IIC_iCMPsi_WriteCMPsi
  { 1, 1, 2, 0, 0 }, // 244 IIC_iALUx
  { 1, 1, 2, 319, 321 }, // 245 IIC_iLoad_bh_i
  { 1, 1, 2, 321, 323 }, // 246 IIC_iLoad_d_i
  { 1, 1, 2, 323, 325 }, // 247 IIC_iCMOVsi_WriteALU
  { 1, 1, 2, 325, 326 }, // 248 IIC_iMOVi
  { 1, 1, 2, 326, 328 }, // 249 IIC_iMVNsi_WriteALU
  { 0, 0, 0, 0, 0 }, // 250 IIC_iALUsir_WriteALUsi_ReadALU
  { 1, 1, 2, 328, 330 }, // 251 IIC_iStore_bh_i
  { 1, 1, 2, 330, 332 }, // 252 IIC_iStore_i
  { 1, 2, 3, 332, 336 }, // 253 IIC_iEXTAsr
  { 1, 1, 2, 336, 338 }, // 254 IIC_iEXTr
  { 1, 1, 2, 338, 339 }, // 255 IIC_iTSTi_WriteCMP
  { 1, 1, 2, 339, 341 }, // 256 IIC_iTSTr_WriteCMP
  { 1, 1, 2, 341, 343 }, // 257 IIC_iTSTsi_WriteCMPsi
  { 1, 1, 2, 343, 346 }, // 258 IIC_iALUr_WriteALU
  { 1, 1, 2, 346, 348 }, // 259 IIC_iALUi_WriteALU
  { 1, 1, 2, 348, 351 }, // 260 IIC_iBITr_WriteALU
  { 1, 3, 4, 351, 354 }, // 261 IIC_iPop
  { 1, 4, 6, 354, 357 }, // 262 IIC_iPop_Br_WriteBrL
  { 1, 1, 2, 357, 359 }, // 263 IIC_iTSTr_WriteALU
  { 1, 1, 2, 359, 361 }, // 264 ANDri_BICri_EORri_ORRri
  { 1, 1, 2, 361, 364 }, // 265 ANDrr_BICrr_EORrr_ORRrr
  { 1, 2, 3, 364, 368 }, // 266 ANDrsi_BICrsi_EORrsi_ORRrsi
  { 1, 2, 3, 368, 372 }, // 267 ANDrsr_BICrsr_EORrsr_ORRrsr
  { 1, 1, 2, 372, 375 }, // 268 MOVCCsi_MOVCCsr
  { 1, 2, 3, 375, 378 }, // 269 MOVsi_MOVsr
  { 1, 1, 2, 378, 380 }, // 270 MOVsra_flag_MOVsrl_flag
  { 1, 2, 3, 380, 383 }, // 271 MVNsr
  { 1, 1, 2, 383, 385 }, // 272 MVNr
  { 1, 6, 8, 385, 386 }, // 273 MOVCCi32imm
  { 1, 6, 8, 386, 387 }, // 274 MOVi32imm
  { 1, 8, 11, 387, 388 }, // 275 MOV_ga_pcrel
  { 1, 8, 11, 388, 389 }, // 276 MOV_ga_pcrel_ldr
  { 0, 0, 0, 0, 0 }, // 277 SEL
  { 1, 1, 2, 389, 391 }, // 278 BFC_BFI_SBFX_UBFX
  { 1, 2, 3, 391, 395 }, // 279 MLA_MLAv5_MLS_SMMLA_SMMLAR_SMMLS_SMMLSR
  { 1, 2, 3, 395, 398 }, // 280 MUL_MULv5_SMMUL_SMMULR
  { 1, 3, 4, 398, 402 }, // 281 SMLAL_SMLALBB_SMLALBT_SMLALTB_SMLALTT_SMLALv5_UMAAL_UMLAL_UMLALv5
  { 1, 3, 4, 402, 405 }, // 282 SMULL_SMULLv5_UMULL_UMULLv5
  { 0, 0, 0, 0, 0 }, // 283 SMLAD_SMLADX_SMLALD_SMLALDX_SMLSD_SMLSDX_SMLSLD_SMLSLDX_SMUAD_SMUADX_SMUSD_SMUSDX
  { 1, 1, 2, 405, 408 }, // 284 SMULBB_SMULBT_SMULTB_SMULTT_SMULWB_SMULWT
  { 1, 1, 2, 408, 412 }, // 285 SMLABB_SMLABT_SMLATB_SMLATT_SMLAWB_SMLAWT
  { 1, 1, 2, 412, 415 }, // 286 LDRi12_PICLDR
  { 1, 2, 3, 415, 418 }, // 287 LDRrs
  { 1, 1, 2, 418, 421 }, // 288 LDRBi12_LDRH_LDRSB_LDRSH_PICLDRB_PICLDRH_PICLDRSB_PICLDRSH
  { 1, 1, 2, 421, 425 }, // 289 LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE_LDRSBTi_LDRSBTr_LDRSB_POST_LDRSB_PRE_LDRSHTi_LDRSHTr_LDRSH_POST_LDRSH_PRE
  { 1, 1, 2, 425, 427 }, // 290 SXTB_SXTB16_SXTH_UXTB_UXTB16_UXTH
  { 1, 1, 2, 427, 429 }, // 291 t2SXTB_t2SXTB16_t2SXTH_t2UXTB_t2UXTB16_t2UXTH
  { 1, 6, 8, 429, 430 }, // 292 t2MOVCCi32imm
  { 1, 6, 8, 430, 431 }, // 293 t2MOVi32imm
  { 1, 8, 11, 431, 432 }, // 294 t2MOV_ga_pcrel
  { 1, 1, 2, 432, 433 }, // 295 t2MOVi16_ga_pcrel
  { 0, 0, 0, 0, 0 }, // 296 t2SEL
  { 1, 1, 2, 433, 435 }, // 297 t2BFC_t2SBFX_t2UBFX
  { 1, 1, 2, 435, 437 }, // 298 t2BFI
  { 1, 1, 2, 437, 440 }, // 299 QADD_QADD16_QADD8_QASX_QDADD_QDSUB_QSAX_QSUB_QSUB16_QSUB8_UQADD16_UQADD8_UQASX_UQSAX_UQSUB16_UQSUB8
  { 0, 0, 0, 0, 0 }, // 300 SSAT_SSAT16_USAT_USAT16_t2QADD_t2QADD16_t2QADD8_t2QASX_t2QDADD_t2QDSUB_t2QSAX_t2QSUB_t2QSUB16_t2QSUB8_t2SSAT_t2SSAT16_t2UQADD16_t2UQADD8_t2UQASX_t2UQSAX_t2UQSUB16_t2UQSUB8_t2USAT_t2USAT16
  { 1, 1, 2, 440, 443 }, // 301 SADD16_SADD8_SASX_SSAX_SSUB16_SSUB8_UADD16_UADD8_UASX_USAX_USUB16_USUB8
  { 0, 0, 0, 0, 0 }, // 302 t2SADD16_t2SADD8_t2SASX_t2SSAX_t2SSUB16_t2SSUB8_t2UADD16_t2UADD8_t2UASX_t2USAX_t2USUB16_t2USUB8
  { 1, 1, 2, 443, 446 }, // 303 SHADD16_SHADD8_SHASX_SHSAX_SHSUB16_SHSUB8_UHADD16_UHADD8_UHASX_UHSAX_UHSUB16_UHSUB8
  { 1, 1, 2, 446, 449 }, // 304 SXTAB_SXTAB16_SXTAH_UXTAB_UXTAB16_UXTAH
  { 0, 0, 0, 0, 0 }, // 305 t2SHADD16_t2SHADD8_t2SHASX_t2SHSAX_t2SHSUB16_t2SHSUB8_t2UHADD16_t2UHADD8_t2UHASX_t2UHSAX_t2UHSUB16_t2UHSUB8
  { 1, 2, 3, 449, 453 }, // 306 t2SXTAB_t2SXTAB16_t2SXTAH_t2UXTAB_t2UXTAB16_t2UXTAH
  { 0, 0, 0, 0, 0 }, // 307 USAD8
  { 0, 0, 0, 0, 0 }, // 308 USADA8
  { 0, 0, 0, 0, 0 }, // 309 SMUSD_SMUSDX
  { 1, 2, 3, 453, 456 }, // 310 t2MUL_t2SMMUL_t2SMMULR
  { 1, 1, 2, 456, 459 }, // 311 t2SMULBB_t2SMULBT_t2SMULTB_t2SMULTT_t2SMULWB_t2SMULWT
  { 1, 2, 3, 459, 463 }, // 312 t2SMUSD_t2SMUSDX
  { 1, 2, 3, 463, 467 }, // 313 t2MLA_t2MLS_t2SMMLA_t2SMMLAR_t2SMMLS_t2SMMLSR
  { 0, 0, 0, 0, 0 }, // 314 SMUAD_SMUADX
  { 1, 2, 3, 467, 471 }, // 315 t2SMUAD_t2SMUADX
  { 0, 0, 0, 0, 0 }, // 316 SMLSD_SMLSDX
  { 1, 1, 2, 471, 475 }, // 317 t2SMLABB_t2SMLABT_t2SMLATB_t2SMLATT_t2SMLAWB_t2SMLAWT
  { 1, 2, 3, 475, 479 }, // 318 t2SMLSD_t2SMLSDX
  { 0, 0, 0, 0, 0 }, // 319 SMLAD_SMLADX
  { 1, 2, 3, 479, 483 }, // 320 t2SMLAD_t2SMLADX
  { 1, 3, 4, 483, 486 }, // 321 SMULL_UMULL
  { 1, 3, 4, 486, 489 }, // 322 t2SMULL_t2UMULL
  { 1, 3, 4, 489, 493 }, // 323 t2SMLAL_t2SMLALBB_t2SMLALBT_t2SMLALD_t2SMLALDX_t2SMLALTB_t2SMLALTT_t2SMLSLD_t2SMLSLDX_t2UMAAL_t2UMLAL
  { 0, 0, 0, 0, 0 }, // 324 SDIV_UDIV_t2SDIV_t2UDIV
  { 1, 1, 2, 493, 496 }, // 325 LDRBi12
  { 1, 2, 3, 496, 499 }, // 326 LDRBrs_t2LDRBs_t2LDRHs
  { 0, 0, 0, 0, 0 }, // 327 LDREX_LDREXB_LDREXD_LDREXH_tLDRpci_pic
  { 1, 1, 2, 499, 502 }, // 328 LDRi12
  { 1, 1, 2, 502, 504 }, // 329 t2LDRBi12_t2LDRBi8_t2LDRBpci_t2LDRHi12_t2LDRHi8_t2LDRHpci_tLDRBi_tLDRHi
  { 1, 1, 2, 504, 506 }, // 330 t2LDRi12_t2LDRi8_t2LDRpci_tLDRi_tLDRpci_tLDRspi
  { 1, 6, 8, 506, 508 }, // 331 t2LDRpci_pic
  { 1, 2, 3, 508, 511 }, // 332 t2LDRs
  { 1, 1, 2, 511, 514 }, // 333 tLDRBr_tLDRHr
  { 1, 1, 2, 514, 517 }, // 334 tLDRr
  { 1, 1, 2, 517, 520 }, // 335 LDRH_PICLDRB_PICLDRH
  { 1, 1, 2, 520, 523 }, // 336 LDRcp
  { 1, 1, 2, 523, 525 }, // 337 t2LDRSBi12_t2LDRSBi8_t2LDRSBpci_t2LDRSHi12_t2LDRSHi8_t2LDRSHpci
  { 0, 0, 0, 0, 0 }, // 338 t2LDRSBpcrel_t2LDRSHpcrel
  { 1, 2, 3, 525, 528 }, // 339 t2LDRSBs_t2LDRSHs
  { 1, 1, 2, 528, 531 }, // 340 tLDRSB_tLDRSH
  { 1, 1, 2, 531, 535 }, // 341 LDRBT_POST_IMM_LDRBT_POST_REG_LDRB_POST_REG_LDRB_PRE_REG
  { 1, 1, 2, 535, 538 }, // 342 LDRB_POST_IMM_LDRB_PRE_IMM_t2LDRB_POST_t2LDRB_PRE_t2LDRH_POST_t2LDRH_PRE
  { 1, 1, 2, 538, 542 }, // 343 LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE
  { 1, 1, 2, 542, 546 }, // 344 LDRT_POST_IMM_LDRT_POST_REG_LDR_POST_REG_LDR_PRE_REG
  { 1, 1, 2, 546, 549 }, // 345 LDR_POST_IMM_LDR_PRE_IMM_t2LDR_POST_t2LDR_PRE
  { 1, 1, 2, 549, 551 }, // 346 t2LDRBT_t2LDRHT
  { 1, 1, 2, 551, 553 }, // 347 t2LDRT
  { 1, 1, 2, 553, 555 }, // 348 t2LDRSBT_t2LDRSHT
  { 1, 1, 2, 555, 558 }, // 349 t2LDRSB_POST_t2LDRSB_PRE_t2LDRSH_POST_t2LDRSH_PRE
  { 1, 1, 2, 558, 561 }, // 350 LDRD
  { 1, 1, 2, 561, 563 }, // 351 t2LDRDi8
  { 1, 1, 2, 563, 567 }, // 352 LDRD_POST_LDRD_PRE_t2LDRD_POST_t2LDRD_PRE
  { 1, 3, 4, 567, 572 }, // 353 LDMDA_LDMDB_LDMIA_LDMIB_sysLDMDA_sysLDMDB_sysLDMIA_sysLDMIB_t2LDMDB_t2LDMIA_tLDMIA
  { 1, 3, 4, 572, 577 }, // 354 LDMDA_UPD_LDMDB_UPD_LDMIA_UPD_LDMIB_UPD_sysLDMDA_UPD_sysLDMDB_UPD_sysLDMIA_UPD_sysLDMIB_UPD_t2LDMDB_UPD_t2LDMIA_UPD_tLDMIA_UPD
  { 1, 4, 6, 577, 582 }, // 355 LDMIA_RET_t2LDMIA_RET
  { 1, 3, 4, 582, 585 }, // 356 tPOP
  { 1, 4, 6, 585, 588 }, // 357 tPOP_RET
  { 1, 1, 2, 588, 591 }, // 358 PICSTR_STRi12_tSTRr
  { 1, 1, 2, 591, 594 }, // 359 PICSTRB_PICSTRH_STRBi12_STRH_tSTRBr_tSTRHr
  { 1, 2, 3, 594, 597 }, // 360 STRBrs_t2STRBs_t2STRHs
  { 0, 0, 0, 0, 0 }, // 361 STREX_STREXB_STREXD_STREXH
  { 1, 2, 3, 597, 600 }, // 362 STRrs_t2STRs
  { 1, 1, 2, 600, 602 }, // 363 t2STRBi12_t2STRBi8_t2STRHi12_t2STRHi8_tSTRBi_tSTRHi
  { 1, 1, 2, 602, 604 }, // 364 t2STRi12_t2STRi8_tSTRi_tSTRspi
  { 0, 0, 0, 0, 0 }, // 365 STRBT_POST_STRT_POST
  { 1, 1, 2, 604, 608 }, // 366 STRBT_POST_IMM_STRBT_POST_REG_STRB_POST_REG_STRB_PRE_REG_STRHTi_STRHTr_STRH_POST_STRH_PRE
  { 1, 1, 2, 608, 611 }, // 367 STRB_POST_IMM_STRB_PRE_IMM_t2STRB_POST_t2STRB_PRE_t2STRH_POST
  { 1, 1, 2, 611, 615 }, // 368 STRBi_preidx_STRBr_preidx_STRH_preidx_STRT_POST_IMM_STRT_POST_REG_STR_POST_REG_STR_PRE_REG_STRi_preidx_STRr_preidx_t2STRB_preidx_t2STRH_preidx_t2STR_preidx
  { 1, 1, 2, 615, 618 }, // 369 STR_POST_IMM_STR_PRE_IMM_t2STRH_PRE_t2STR_POST_t2STR_PRE
  { 1, 1, 2, 618, 620 }, // 370 t2STRBT_t2STRHT
  { 1, 1, 2, 620, 622 }, // 371 t2STRT
  { 1, 1, 2, 622, 625 }, // 372 STRD_t2STRDi8
  { 1, 1, 2, 625, 629 }, // 373 STRD_POST_STRD_PRE_t2STRD_POST_t2STRD_PRE
  { 1, 3, 4, 0, 0 }, // 374 STMDA_STMDB_STMIA_STMIB_sysSTMDA_sysSTMDB_sysSTMIA_sysSTMIB_t2STMDB_t2STMIA
  { 1, 3, 4, 629, 630 }, // 375 STMDA_UPD_STMDB_UPD_STMIA_UPD_STMIB_UPD_sysSTMDA_UPD_sysSTMDB_UPD_sysSTMIA_UPD_sysSTMIB_UPD_t2STMDB_UPD_t2STMIA_UPD_tSTMIA_UPD
  { 1, 3, 4, 0, 0 }, // 376 tPUSH
  { 1, 1, 2, 630, 632 }, // 377 LDRLIT_ga_abs_tLDRLIT_ga_abs
  { 1, 6, 8, 632, 634 }, // 378 LDRLIT_ga_pcrel_tLDRLIT_ga_pcrel
  { 0, 0, 0, 0, 0 }, // 379 LDRLIT_ga_pcrel_ldr
  { 0, 0, 0, 0, 0 }, // 380 ITasm
  { 1, 1, 2, 0, 0 }, // 381 t2IT
  { 0, 0, 0, 0, 0 }, // 382 VADDLsv2i64_VADDLsv4i32_VADDLsv8i16_VADDLuv2i64_VADDLuv4i32_VADDLuv8i16_VNEGs16d_VNEGs32d_VNEGs8d_VPADDLsv16i8_VPADDLsv2i32_VPADDLsv4i16_VPADDLsv4i32_VPADDLsv8i16_VPADDLsv8i8_VPADDLuv16i8_VPADDLuv2i32_VPADDLuv4i16_VPADDLuv4i32_VPADDLuv8i16_VPADDLuv8i8_VPADDi16_VPADDi32_VPADDi8_VSHLLi16_VSHLLi32_VSHLLi8_VSHLLsv2i64_VSHLLsv4i32_VSHLLsv8i16_VSHLLuv2i64_VSHLLuv4i32_VSHLLuv8i16_VSHLiv16i8_VSHLiv1i64_VSHLiv2i32_VSHLiv2i64_VSHLiv4i16_VSHLiv4i32_VSHLiv8i16_VSHLiv8i8_VSHLsv1i64_VSHLsv2i32_VSHLsv4i16_VSHLsv8i8_VSHLuv1i64_VSHLuv2i32_VSHLuv4i16_VSHLuv8i8_VSHRsv16i8_VSHRsv1i64_VSHRsv2i32_VSHRsv2i64_VSHRsv4i16_VSHRsv4i32_VSHRsv8i16_VSHRsv8i8_VSHRuv16i8_VSHRuv1i64_VSHRuv2i32_VSHRuv2i64_VSHRuv4i16_VSHRuv4i32_VSHRuv8i16_VSHRuv8i8_VSLIv1i64_VSLIv2i32_VSLIv4i16_VSLIv8i8_VSRIv1i64_VSRIv2i32_VSRIv4i16_VSRIv8i8_VSUBLsv2i64_VSUBLsv4i32_VSUBLsv8i16_VSUBLuv2i64_VSUBLuv4i32_VSUBLuv8i16
  { 0, 0, 0, 0, 0 }, // 383 VADDWsv2i64_VADDWsv4i32_VADDWsv8i16_VADDWuv2i64_VADDWuv4i32_VADDWuv8i16_VSUBWsv2i64_VSUBWsv4i32_VSUBWsv8i16_VSUBWuv2i64_VSUBWuv4i32_VSUBWuv8i16_VSUBv1i64_VSUBv2i32_VSUBv4i16_VSUBv8i8
  { 0, 0, 0, 0, 0 }, // 384 VADDv16i8_VADDv2i64_VADDv4i32_VADDv8i16_VANDq_VBICq_VBIFq_VBITq_VEORq_VORNq_VORRq
  { 0, 0, 0, 0, 0 }, // 385 VADDv1i64_VADDv2i32_VADDv4i16_VADDv8i8_VANDd_VBICd_VBIFd_VBITd_VEORd_VORNd_VORRd
  { 0, 0, 0, 0, 0 }, // 386 VBICiv2i32_VBICiv4i16_VBICiv4i32_VBICiv8i16_VORRiv2i32_VORRiv4i16_VORRiv4i32_VORRiv8i16
  { 0, 0, 0, 0, 0 }, // 387 VBSLd_VCLSv2i32_VCLSv4i16_VCLSv8i8_VCLZv2i32_VCLZv4i16_VCLZv8i8_VCNTd
  { 0, 0, 0, 0, 0 }, // 388 VBSLq_VCLSv16i8_VCLSv4i32_VCLSv8i16_VCLZv16i8_VCLZv4i32_VCLZv8i16_VCNTq
  { 0, 0, 0, 0, 0 }, // 389 VHADDsv16i8_VHADDsv4i32_VHADDsv8i16_VHADDuv16i8_VHADDuv4i32_VHADDuv8i16_VRHADDsv16i8_VRHADDsv4i32_VRHADDsv8i16_VRHADDuv16i8_VRHADDuv4i32_VRHADDuv8i16_VTSTv16i8_VTSTv4i32_VTSTv8i16
  { 0, 0, 0, 0, 0 }, // 390 VHADDsv2i32_VHADDsv4i16_VHADDsv8i8_VHADDuv2i32_VHADDuv4i16_VHADDuv8i8_VRHADDsv2i32_VRHADDsv4i16_VRHADDsv8i8_VRHADDuv2i32_VRHADDuv4i16_VRHADDuv8i8_VTSTv2i32_VTSTv4i16_VTSTv8i8
  { 0, 0, 0, 0, 0 }, // 391 VHSUBsv16i8_VHSUBsv4i32_VHSUBsv8i16_VHSUBuv16i8_VHSUBuv4i32_VHSUBuv8i16
  { 0, 0, 0, 0, 0 }, // 392 VHSUBsv2i32_VHSUBsv4i16_VHSUBsv8i8_VHSUBuv2i32_VHSUBuv4i16_VHSUBuv8i8
  { 0, 0, 0, 0, 0 }, // 393 VNEGf32q
  { 0, 0, 0, 0, 0 }, // 394 VNEGfd
  { 0, 0, 0, 0, 0 }, // 395 VNEGs16q_VNEGs32q_VNEGs8q_VSHLsv16i8_VSHLsv2i64_VSHLsv4i32_VSHLsv8i16_VSHLuv16i8_VSHLuv2i64_VSHLuv4i32_VSHLuv8i16_VSLIv16i8_VSLIv2i64_VSLIv4i32_VSLIv8i16_VSRIv16i8_VSRIv2i64_VSRIv4i32_VSRIv8i16
  { 0, 0, 0, 0, 0 }, // 396 VQSHLsiv16i8_VQSHLsiv1i64_VQSHLsiv2i32_VQSHLsiv2i64_VQSHLsiv4i16_VQSHLsiv4i32_VQSHLsiv8i16_VQSHLsiv8i8_VQSHLsuv16i8_VQSHLsuv1i64_VQSHLsuv2i32_VQSHLsuv2i64_VQSHLsuv4i16_VQSHLsuv4i32_VQSHLsuv8i16_VQSHLsuv8i8_VQSHLsv1i64_VQSHLsv2i32_VQSHLsv4i16_VQSHLsv8i8_VQSHLuiv16i8_VQSHLuiv1i64_VQSHLuiv2i32_VQSHLuiv2i64_VQSHLuiv4i16_VQSHLuiv4i32_VQSHLuiv8i16_VQSHLuiv8i8_VQSHLuv1i64_VQSHLuv2i32_VQSHLuv4i16_VQSHLuv8i8
  { 0, 0, 0, 0, 0 }, // 397 VQSHLsv16i8_VQSHLsv2i64_VQSHLsv4i32_VQSHLsv8i16_VQSHLuv16i8_VQSHLuv2i64_VQSHLuv4i32_VQSHLuv8i16
  { 0, 0, 0, 0, 0 }, // 398 VSUBv16i8_VSUBv2i64_VSUBv4i32_VSUBv8i16
  { 0, 0, 0, 0, 0 }, // 399 VEXTd16_VEXTd32_VEXTd8
  { 0, 0, 0, 0, 0 }, // 400 VEXTq16_VEXTq32_VEXTq64_VEXTq8
  { 0, 0, 0, 0, 0 }, // 401 VREV16d8_VREV32d16_VREV32d8_VREV64d16_VREV64d32_VREV64d8
  { 0, 0, 0, 0, 0 }, // 402 VREV16q8_VREV32q16_VREV32q8_VREV64q16_VREV64q32_VREV64q8
  { 0, 0, 0, 0, 0 }, // 403 VABALsv2i64_VABALsv4i32_VABALsv8i16_VABALuv2i64_VABALuv4i32_VABALuv8i16_VABAsv2i32_VABAsv4i16_VABAsv8i8_VABAuv2i32_VABAuv4i16_VABAuv8i8
  { 0, 0, 0, 0, 0 }, // 404 VABAsv16i8_VABAsv4i32_VABAsv8i16_VABAuv16i8_VABAuv4i32_VABAuv8i16
  { 0, 0, 0, 0, 0 }, // 405 VABSfd
  { 0, 0, 0, 0, 0 }, // 406 VABSfq
  { 0, 0, 0, 0, 0 }, // 407 VABSv16i8_VABSv4i32_VABSv8i16
  { 0, 0, 0, 0, 0 }, // 408 VABSv2i32_VABSv4i16_VABSv8i8
  { 0, 0, 0, 0, 0 }, // 409 VACGEd_VACGTd_VCEQfd_VCGEfd_VCGTfd
  { 0, 0, 0, 0, 0 }, // 410 VACGEq_VACGTq_VCEQfq_VCGEfq_VCGTfq
  { 0, 0, 0, 0, 0 }, // 411 VCEQv16i8_VCEQv4i32_VCEQv8i16_VCGEsv16i8_VCGEsv4i32_VCGEsv8i16_VCGEuv16i8_VCGEuv4i32_VCGEuv8i16_VCGTsv16i8_VCGTsv4i32_VCGTsv8i16_VCGTuv16i8_VCGTuv4i32_VCGTuv8i16_VQSUBsv16i8_VQSUBsv2i64_VQSUBsv4i32_VQSUBsv8i16_VQSUBuv16i8_VQSUBuv2i64_VQSUBuv4i32_VQSUBuv8i16
  { 0, 0, 0, 0, 0 }, // 412 VCEQv2i32_VCEQv4i16_VCEQv8i8_VCGEsv2i32_VCGEsv4i16_VCGEsv8i8_VCGEuv2i32_VCGEuv4i16_VCGEuv8i8_VCGTsv2i32_VCGTsv4i16_VCGTsv8i8_VCGTuv2i32_VCGTuv4i16_VCGTuv8i8_VQSUBsv1i64_VQSUBsv2i32_VQSUBsv4i16_VQSUBsv8i8_VQSUBuv1i64_VQSUBuv2i32_VQSUBuv4i16_VQSUBuv8i8
  { 0, 0, 0, 0, 0 }, // 413 VCEQzv16i8_VCEQzv2f32_VCEQzv2i32_VCEQzv4f32_VCEQzv4i16_VCEQzv4i32_VCEQzv8i16_VCEQzv8i8_VCGEzv16i8_VCGEzv2f32_VCGEzv2i32_VCGEzv4f32_VCGEzv4i16_VCGEzv4i32_VCGEzv8i16_VCGEzv8i8_VCGTzv16i8_VCGTzv2f32_VCGTzv2i32_VCGTzv4f32_VCGTzv4i16_VCGTzv4i32_VCGTzv8i16_VCGTzv8i8_VCLEzv16i8_VCLEzv2f32_VCLEzv2i32_VCLEzv4f32_VCLEzv4i16_VCLEzv4i32_VCLEzv8i16_VCLEzv8i8_VCLTzv16i8_VCLTzv2f32_VCLTzv2i32_VCLTzv4f32_VCLTzv4i16_VCLTzv4i32_VCLTzv8i16_VCLTzv8i8
  { 0, 0, 0, 0, 0 }, // 414 VPADALsv16i8_VPADALsv4i32_VPADALsv8i16_VPADALuv16i8_VPADALuv4i32_VPADALuv8i16
  { 0, 0, 0, 0, 0 }, // 415 VPADALsv2i32_VPADALsv4i16_VPADALsv8i8_VPADALuv2i32_VPADALuv4i16_VPADALuv8i8_VRSRAsv16i8_VRSRAsv1i64_VRSRAsv2i32_VRSRAsv2i64_VRSRAsv4i16_VRSRAsv4i32_VRSRAsv8i16_VRSRAsv8i8_VRSRAuv16i8_VRSRAuv1i64_VRSRAuv2i32_VRSRAuv2i64_VRSRAuv4i16_VRSRAuv4i32_VRSRAuv8i16_VRSRAuv8i8_VSRAsv16i8_VSRAsv1i64_VSRAsv2i32_VSRAsv2i64_VSRAsv4i16_VSRAsv4i32_VSRAsv8i16_VSRAsv8i8_VSRAuv16i8_VSRAuv1i64_VSRAuv2i32_VSRAuv2i64_VSRAuv4i16_VSRAuv4i32_VSRAuv8i16_VSRAuv8i8
  { 0, 0, 0, 0, 0 }, // 416 VQABSv16i8_VQABSv4i32_VQABSv8i16_VQNEGv16i8_VQNEGv4i32_VQNEGv8i16
  { 0, 0, 0, 0, 0 }, // 417 VQABSv2i32_VQABSv4i16_VQABSv8i8_VQNEGv2i32_VQNEGv4i16_VQNEGv8i8
  { 0, 0, 0, 0, 0 }, // 418 VQADDsv16i8_VQADDsv2i64_VQADDsv4i32_VQADDsv8i16_VQADDuv16i8_VQADDuv2i64_VQADDuv4i32_VQADDuv8i16
  { 0, 0, 0, 0, 0 }, // 419 VQADDsv1i64_VQADDsv2i32_VQADDsv4i16_VQADDsv8i8_VQADDuv1i64_VQADDuv2i32_VQADDuv4i16_VQADDuv8i8
  { 0, 0, 0, 0, 0 }, // 420 VQRSHLsv16i8_VQRSHLsv2i64_VQRSHLsv4i32_VQRSHLsv8i16_VQRSHLuv16i8_VQRSHLuv2i64_VQRSHLuv4i32_VQRSHLuv8i16_VRSHLsv16i8_VRSHLsv2i64_VRSHLsv4i32_VRSHLsv8i16_VRSHLuv16i8_VRSHLuv2i64_VRSHLuv4i32_VRSHLuv8i16
  { 0, 0, 0, 0, 0 }, // 421 VQRSHLsv1i64_VQRSHLsv2i32_VQRSHLsv4i16_VQRSHLsv8i8_VQRSHLuv1i64_VQRSHLuv2i32_VQRSHLuv4i16_VQRSHLuv8i8_VRSHLsv1i64_VRSHLsv2i32_VRSHLsv4i16_VRSHLsv8i8_VRSHLuv1i64_VRSHLuv2i32_VRSHLuv4i16_VRSHLuv8i8_VRSHRsv16i8_VRSHRsv1i64_VRSHRsv2i32_VRSHRsv2i64_VRSHRsv4i16_VRSHRsv4i32_VRSHRsv8i16_VRSHRsv8i8_VRSHRuv16i8_VRSHRuv1i64_VRSHRuv2i32_VRSHRuv2i64_VRSHRuv4i16_VRSHRuv4i32_VRSHRuv8i16_VRSHRuv8i8
  { 0, 0, 0, 0, 0 }, // 422 VRECPEd_VRECPEfd_VRSQRTEd_VRSQRTEfd
  { 0, 0, 0, 0, 0 }, // 423 VRECPEfq_VRECPEq_VRSQRTEfq_VRSQRTEq
  { 0, 0, 0, 0, 0 }, // 424 VADDHNv2i32_VADDHNv4i16_VADDHNv8i8_VSUBHNv2i32_VSUBHNv4i16_VSUBHNv8i8
  { 0, 0, 0, 0, 0 }, // 425 VSHRNv2i32_VSHRNv4i16_VSHRNv8i8
  { 0, 0, 0, 0, 0 }, // 426 VQRSHRNsv2i32_VQRSHRNsv4i16_VQRSHRNsv8i8_VQRSHRNuv2i32_VQRSHRNuv4i16_VQRSHRNuv8i8_VQRSHRUNv2i32_VQRSHRUNv4i16_VQRSHRUNv8i8_VQSHRNsv2i32_VQSHRNsv4i16_VQSHRNsv8i8_VQSHRNuv2i32_VQSHRNuv4i16_VQSHRNuv8i8_VQSHRUNv2i32_VQSHRUNv4i16_VQSHRUNv8i8_VRSHRNv2i32_VRSHRNv4i16_VRSHRNv8i8
  { 0, 0, 0, 0, 0 }, // 427 VRADDHNv2i32_VRADDHNv4i16_VRADDHNv8i8_VRSUBHNv2i32_VRSUBHNv4i16_VRSUBHNv8i8
  { 0, 0, 0, 0, 0 }, // 428 VTBL1
  { 0, 0, 0, 0, 0 }, // 429 VTBX1
  { 0, 0, 0, 0, 0 }, // 430 VTBL2
  { 0, 0, 0, 0, 0 }, // 431 VTBX2
  { 0, 0, 0, 0, 0 }, // 432 VTBL3_VTBL3Pseudo
  { 0, 0, 0, 0, 0 }, // 433 VTBX3_VTBX3Pseudo
  { 0, 0, 0, 0, 0 }, // 434 VTBL4_VTBL4Pseudo
  { 0, 0, 0, 0, 0 }, // 435 VTBX4_VTBX4Pseudo
  { 0, 0, 0, 0, 0 }, // 436 VSWPd_VSWPq
  { 0, 0, 0, 0, 0 }, // 437 VTRNd16_VTRNd32_VTRNd8_VUZPd16_VUZPd8_VZIPd16_VZIPd8
  { 0, 0, 0, 0, 0 }, // 438 VTRNq16_VTRNq32_VTRNq8
  { 0, 0, 0, 0, 0 }, // 439 VUZPq16_VUZPq32_VUZPq8_VZIPq16_VZIPq32_VZIPq8
  { 1, 1, 2, 634, 636 }, // 440 VABSD_VNEGD
  { 1, 1, 2, 636, 638 }, // 441 VABSS_VNEGS
  { 1, 1, 2, 638, 640 }, // 442 VCMPD_VCMPED_VCMPEZD_VCMPZD
  { 1, 1, 2, 640, 642 }, // 443 VCMPES_VCMPEZS_VCMPS_VCMPZS
  { 0, 0, 0, 0, 0 }, // 444 VABDLsv2i64_VABDLsv4i32_VABDLsv8i16_VABDLuv2i64_VABDLuv4i32_VABDLuv8i16_VABDsv16i8_VABDsv4i32_VABDsv8i16_VABDuv16i8_VABDuv4i32_VABDuv8i16_VMAXsv16i8_VMAXsv4i32_VMAXsv8i16_VMAXuv16i8_VMAXuv4i32_VMAXuv8i16_VMINsv16i8_VMINsv4i32_VMINsv8i16_VMINuv16i8_VMINuv4i32_VMINuv8i16
  { 0, 0, 0, 0, 0 }, // 445 VABDfd_VADDfd_VMAXfd_VMINfd_VSUBfd
  { 0, 0, 0, 0, 0 }, // 446 VABDfq_VADDfq_VMAXfq_VMINfq_VSUBfq
  { 0, 0, 0, 0, 0 }, // 447 VABDsv2i32_VABDsv4i16_VABDsv8i8_VABDuv2i32_VABDuv4i16_VABDuv8i8_VMAXsv2i32_VMAXsv4i16_VMAXsv8i8_VMAXuv2i32_VMAXuv4i16_VMAXuv8i8_VMINsv2i32_VMINsv4i16_VMINsv8i8_VMINuv2i32_VMINuv4i16_VMINuv8i8_VPMAXs16_VPMAXs32_VPMAXs8_VPMAXu16_VPMAXu32_VPMAXu8_VPMINs16_VPMINs32_VPMINs8_VPMINu16_VPMINu32_VPMINu8
  { 1, 1, 2, 642, 645 }, // 448 VADDS_VSUBS
  { 0, 0, 0, 0, 0 }, // 449 VMAXNMD_VMAXNMND_VMAXNMNQ_VMAXNMS_VMINNMD_VMINNMND_VMINNMNQ_VMINNMS
  { 0, 0, 0, 0, 0 }, // 450 VPADDf_VPMAXf_VPMINf
  { 1, 1, 2, 645, 648 }, // 451 VADDD_VSUBD
  { 0, 0, 0, 0, 0 }, // 452 VRECPSfd_VRSQRTSfd
  { 0, 0, 0, 0, 0 }, // 453 VRECPSfq_VRSQRTSfq
  { 0, 0, 0, 0, 0 }, // 454 VMULLp64
  { 0, 0, 0, 0, 0 }, // 455 VMULLp8_VMULLslsv2i32_VMULLslsv4i16_VMULLsluv2i32_VMULLsluv4i16_VMULLsv4i32_VMULLsv8i16_VMULLuv4i32_VMULLuv8i16_VMULpd_VMULslv4i16_VMULv4i16_VMULv8i8_VQDMULHslv4i16_VQDMULHv4i16_VQDMULLslv2i32_VQDMULLslv4i16_VQDMULLv4i32_VQRDMULHslv4i16_VQRDMULHv4i16
  { 0, 0, 0, 0, 0 }, // 456 VMULLsv2i64_VMULLuv2i64_VMULslv2i32_VMULv2i32_VQDMULHslv2i32_VQDMULHv2i32_VQDMULLv2i64_VQRDMULHslv2i32_VQRDMULHv2i32
  { 1, 1, 2, 648, 651 }, // 457 VMULS_VNMULS
  { 0, 0, 0, 0, 0 }, // 458 VMULfd
  { 0, 0, 0, 0, 0 }, // 459 VMULfq
  { 0, 0, 0, 0, 0 }, // 460 VMULpq_VMULslv8i16_VMULv16i8_VMULv8i16_VQDMULHslv8i16_VQDMULHv8i16_VQRDMULHslv8i16_VQRDMULHv8i16
  { 0, 0, 0, 0, 0 }, // 461 VMULslfd
  { 0, 0, 0, 0, 0 }, // 462 VMULslfq
  { 0, 0, 0, 0, 0 }, // 463 VMULslv4i32_VMULv4i32_VQDMULHslv4i32_VQDMULHv4i32_VQRDMULHslv4i32_VQRDMULHv4i32
  { 1, 2, 3, 651, 654 }, // 464 VMULD_VNMULD
  { 1, 2, 3, 654, 658 }, // 465 VFMAD_VFMSD_VFNMAD_VFNMSD
  { 1, 1, 2, 658, 662 }, // 466 VFMAS_VFMSS_VFNMAS_VFNMSS
  { 1, 2, 3, 662, 666 }, // 467 VMLAD_VMLSD_VNMLAD_VNMLSD
  { 0, 0, 0, 0, 0 }, // 468 VMLALslsv2i32_VMLALsluv2i32_VMLALsv2i64_VMLALuv2i64_VMLAslv2i32_VMLAv2i32_VMLSLslsv2i32_VMLSLsluv2i32_VMLSLsv2i64_VMLSLuv2i64_VMLSslv2i32_VMLSv2i32_VQDMLALslv2i32_VQDMLALv2i64_VQDMLSLslv2i32_VQDMLSLv2i64
  { 0, 0, 0, 0, 0 }, // 469 VMLALslsv4i16_VMLALsluv4i16_VMLALsv4i32_VMLALsv8i16_VMLALuv4i32_VMLALuv8i16_VMLAslv4i16_VMLAv4i16_VMLAv8i8_VMLSLslsv4i16_VMLSLsluv4i16_VMLSLsv4i32_VMLSLsv8i16_VMLSLuv4i32_VMLSLuv8i16_VMLSslv4i16_VMLSv4i16_VMLSv8i8_VQDMLALslv4i16_VQDMLALv4i32_VQDMLSLslv4i16_VQDMLSLv4i32
  { 1, 1, 2, 666, 670 }, // 470 VMLAS_VMLSS_VNMLAS_VNMLSS
  { 0, 0, 0, 0, 0 }, // 471 VMLAfd_VMLAslfd_VMLSfd_VMLSslfd
  { 0, 0, 0, 0, 0 }, // 472 VMLAfq_VMLAslfq_VMLSfq_VMLSslfq
  { 0, 0, 0, 0, 0 }, // 473 VMLAslv4i32_VMLAv4i32_VMLSslv4i32_VMLSv4i32
  { 0, 0, 0, 0, 0 }, // 474 VMLAslv8i16_VMLAv16i8_VMLAv8i16_VMLSslv8i16_VMLSv16i8_VMLSv8i16
  { 0, 0, 0, 0, 0 }, // 475 VFMAfd_VFMSfd
  { 0, 0, 0, 0, 0 }, // 476 VFMAfq_VFMSfq
  { 0, 0, 0, 0, 0 }, // 477 VCVTANSD_VCVTANSQ_VCVTANUD_VCVTANUQ_VCVTASD_VCVTASS_VCVTAUD_VCVTAUS_VCVTBDH_VCVTBHD_VCVTMNSD_VCVTMNSQ_VCVTMNUD_VCVTMNUQ_VCVTMSD_VCVTMSS_VCVTMUD_VCVTMUS_VCVTNNSD_VCVTNNSQ_VCVTNNUD_VCVTNNUQ_VCVTNSD_VCVTNSS_VCVTNUD_VCVTNUS_VCVTPNSD_VCVTPNSQ_VCVTPNUD_VCVTPNUQ_VCVTPSD_VCVTPSS_VCVTPUD_VCVTPUS_VCVTTDH_VCVTTHD
  { 0, 0, 0, 0, 0 }, // 478 VCVTBHS_VCVTTHS
  { 0, 0, 0, 0, 0 }, // 479 VCVTBSH_VCVTTSH
  { 1, 1, 2, 670, 672 }, // 480 VCVTDS
  { 1, 1, 2, 672, 674 }, // 481 VCVTSD
  { 0, 0, 0, 0, 0 }, // 482 VCVTf2h_VCVTf2sq_VCVTf2uq_VCVTf2xsq_VCVTf2xuq_VCVTh2f_VCVTs2fq_VCVTu2fq_VCVTxs2fq_VCVTxu2fq
  { 0, 0, 0, 0, 0 }, // 483 VCVTf2sd_VCVTf2ud_VCVTf2xsd_VCVTf2xud_VCVTs2fd_VCVTu2fd_VCVTxs2fd_VCVTxu2fd
  { 1, 1, 2, 674, 676 }, // 484 VSITOD_VUITOD
  { 1, 1, 2, 676, 678 }, // 485 VSITOS_VUITOS
  { 1, 1, 2, 678, 680 }, // 486 VTOSHD_VTOSLD_VTOUHD_VTOULD
  { 1, 1, 2, 680, 682 }, // 487 VTOSHS_VTOSLS_VTOUHS_VTOULS
  { 1, 1, 2, 682, 684 }, // 488 VTOSIRD_VTOSIZD_VTOUIRD_VTOUIZD
  { 1, 1, 2, 684, 686 }, // 489 VTOSIRS_VTOSIZS_VTOUIRS_VTOUIZS
  { 1, 1, 2, 686, 688 }, // 490 FCONSTD_VMOVD_VMOVDcc
  { 1, 1, 2, 688, 690 }, // 491 FCONSTS_VMOVS_VMOVScc
  { 0, 0, 0, 0, 0 }, // 492 VMOVv16i8_VMOVv1i64_VMOVv2f32_VMOVv2i32_VMOVv2i64_VMOVv4f32_VMOVv4i16_VMOVv4i32_VMOVv8i16_VMOVv8i8_VMVNv2i32_VMVNv4i16_VMVNv4i32_VMVNv8i16
  { 0, 0, 0, 0, 0 }, // 493 VMVNd_VMVNq
  { 0, 0, 0, 0, 0 }, // 494 VMOVLsv2i64_VMOVLsv4i32_VMOVLsv8i16_VMOVLuv2i64_VMOVLuv4i32_VMOVLuv8i16
  { 0, 0, 0, 0, 0 }, // 495 VMOVNv2i32_VMOVNv4i16_VMOVNv8i8
  { 0, 0, 0, 0, 0 }, // 496 VQMOVNsuv2i32_VQMOVNsuv4i16_VQMOVNsuv8i8_VQMOVNsv2i32_VQMOVNsv4i16_VQMOVNsv8i8_VQMOVNuv2i32_VQMOVNuv4i16_VQMOVNuv8i8
  { 0, 0, 0, 0, 0 }, // 497 VDUPLN16d_VDUPLN32d_VDUPLN8d
  { 0, 0, 0, 0, 0 }, // 498 VDUPLN16q_VDUPLN32q_VDUPLN8q
  { 0, 0, 0, 0, 0 }, // 499 VDUP16d_VDUP16q_VDUP32d_VDUP32q_VDUP8d_VDUP8q
  { 1, 1, 2, 690, 692 }, // 500 VMOVRS
  { 1, 1, 2, 692, 694 }, // 501 VMOVSR
  { 0, 0, 0, 0, 0 }, // 502 VSETLNi16_VSETLNi32_VSETLNi8
  { 1, 1, 2, 694, 697 }, // 503 VMOVRRD_VMOVRRS
  { 1, 1, 2, 697, 700 }, // 504 VMOVDRR
  { 1, 1, 2, 700, 703 }, // 505 VMOVSRR
  { 0, 0, 0, 0, 0 }, // 506 VGETLNi32_VGETLNu16_VGETLNu8
  { 0, 0, 0, 0, 0 }, // 507 VGETLNs16_VGETLNs8
  { 1, 1, 2, 703, 704 }, // 508 VMRS_VMRS_FPEXC_VMRS_FPINST_VMRS_FPINST2_VMRS_FPSID_VMRS_MVFR0_VMRS_MVFR1_VMRS_MVFR2
  { 1, 1, 2, 704, 705 }, // 509 VMSR_VMSR_FPEXC_VMSR_FPINST_VMSR_FPINST2_VMSR_FPSID
  { 1, 1, 2, 705, 706 }, // 510 FMSTAT
  { 1, 1, 2, 706, 709 }, // 511 VLDRD
  { 1, 1, 2, 709, 712 }, // 512 VLDRS
  { 1, 1, 2, 712, 715 }, // 513 VSTRD
  { 1, 1, 2, 715, 718 }, // 514 VSTRS
  { 1, 3, 4, 718, 722 }, // 515 VLDMQIA
  { 1, 3, 4, 722, 726 }, // 516 VSTMQIA
  { 1, 3, 4, 726, 730 }, // 517 VLDMDIA_VLDMSIA
  { 1, 3, 4, 730, 735 }, // 518 VLDMDDB_UPD_VLDMDIA_UPD_VLDMSDB_UPD_VLDMSIA_UPD
  { 1, 3, 4, 735, 739 }, // 519 VSTMDIA_VSTMSIA
  { 1, 3, 4, 739, 744 }, // 520 VSTMDDB_UPD_VSTMDIA_UPD_VSTMSDB_UPD_VSTMSIA_UPD
  { 0, 0, 0, 0, 0 }, // 521 VLD1d16_VLD1d32_VLD1d64_VLD1d8
  { 0, 0, 0, 0, 0 }, // 522 VLD1q16_VLD1q32_VLD1q64_VLD1q8
  { 0, 0, 0, 0, 0 }, // 523 VLD1d16wb_fixed_VLD1d16wb_register_VLD1d32wb_fixed_VLD1d32wb_register_VLD1d64wb_fixed_VLD1d64wb_register_VLD1d8wb_fixed_VLD1d8wb_register
  { 0, 0, 0, 0, 0 }, // 524 VLD1q16wb_fixed_VLD1q16wb_register_VLD1q32wb_fixed_VLD1q32wb_register_VLD1q64wb_fixed_VLD1q64wb_register_VLD1q8wb_fixed_VLD1q8wb_register
  { 0, 0, 0, 0, 0 }, // 525 VLD1d16T_VLD1d32T_VLD1d64T_VLD1d64TPseudo_VLD1d64TPseudoWB_fixed_VLD1d64TPseudoWB_register_VLD1d8T
  { 0, 0, 0, 0, 0 }, // 526 VLD1d16Twb_fixed_VLD1d16Twb_register_VLD1d32Twb_fixed_VLD1d32Twb_register_VLD1d64Twb_fixed_VLD1d64Twb_register_VLD1d8Twb_fixed_VLD1d8Twb_register
  { 0, 0, 0, 0, 0 }, // 527 VLD1d16Q_VLD1d32Q_VLD1d64Q_VLD1d64QPseudo_VLD1d64QPseudoWB_fixed_VLD1d64QPseudoWB_register_VLD1d8Q
  { 0, 0, 0, 0, 0 }, // 528 VLD1d16Qwb_fixed_VLD1d16Qwb_register_VLD1d32Qwb_fixed_VLD1d32Qwb_register_VLD1d64Qwb_fixed_VLD1d64Qwb_register_VLD1d8Qwb_fixed_VLD1d8Qwb_register
  { 0, 0, 0, 0, 0 }, // 529 VLD2b16_VLD2b32_VLD2b8_VLD2d16_VLD2d32_VLD2d8
  { 0, 0, 0, 0, 0 }, // 530 VLD2q16_VLD2q16Pseudo_VLD2q32_VLD2q32Pseudo_VLD2q8_VLD2q8Pseudo
  { 0, 0, 0, 0, 0 }, // 531 VLD2b16wb_fixed_VLD2b16wb_register_VLD2b32wb_fixed_VLD2b32wb_register_VLD2b8wb_fixed_VLD2b8wb_register_VLD2d16wb_fixed_VLD2d16wb_register_VLD2d32wb_fixed_VLD2d32wb_register_VLD2d8wb_fixed_VLD2d8wb_register
  { 0, 0, 0, 0, 0 }, // 532 VLD2q16PseudoWB_fixed_VLD2q16PseudoWB_register_VLD2q16wb_fixed_VLD2q16wb_register_VLD2q32PseudoWB_fixed_VLD2q32PseudoWB_register_VLD2q32wb_fixed_VLD2q32wb_register_VLD2q8PseudoWB_fixed_VLD2q8PseudoWB_register_VLD2q8wb_fixed_VLD2q8wb_register
  { 0, 0, 0, 0, 0 }, // 533 VLD3d16_VLD3d32_VLD3d8_VLD3q16_VLD3q32_VLD3q8
  { 0, 0, 0, 0, 0 }, // 534 VLD3d16Pseudo_VLD3d32Pseudo_VLD3d8Pseudo_VLD3q16oddPseudo_VLD3q32oddPseudo_VLD3q8oddPseudo
  { 0, 0, 0, 0, 0 }, // 535 VLD3d16_UPD_VLD3d32_UPD_VLD3d8_UPD_VLD3q16_UPD_VLD3q32_UPD_VLD3q8_UPD
  { 0, 0, 0, 0, 0 }, // 536 VLD3d16Pseudo_UPD_VLD3d32Pseudo_UPD_VLD3d8Pseudo_UPD_VLD3q16Pseudo_UPD_VLD3q16oddPseudo_UPD_VLD3q32Pseudo_UPD_VLD3q32oddPseudo_UPD_VLD3q8Pseudo_UPD_VLD3q8oddPseudo_UPD
  { 0, 0, 0, 0, 0 }, // 537 VLD4d16_VLD4d32_VLD4d8_VLD4q16_VLD4q32_VLD4q8
  { 0, 0, 0, 0, 0 }, // 538 VLD4d16Pseudo_VLD4d32Pseudo_VLD4d8Pseudo_VLD4q16oddPseudo_VLD4q32oddPseudo_VLD4q8oddPseudo
  { 0, 0, 0, 0, 0 }, // 539 VLD4d16_UPD_VLD4d32_UPD_VLD4d8_UPD_VLD4q16_UPD_VLD4q32_UPD_VLD4q8_UPD
  { 0, 0, 0, 0, 0 }, // 540 VLD4d16Pseudo_UPD_VLD4d32Pseudo_UPD_VLD4d8Pseudo_UPD_VLD4q16Pseudo_UPD_VLD4q16oddPseudo_UPD_VLD4q32Pseudo_UPD_VLD4q32oddPseudo_UPD_VLD4q8Pseudo_UPD_VLD4q8oddPseudo_UPD
  { 0, 0, 0, 0, 0 }, // 541 VLD1DUPd16_VLD1DUPd32_VLD1DUPd8_VLD1DUPq16_VLD1DUPq32_VLD1DUPq8
  { 0, 0, 0, 0, 0 }, // 542 VLD1LNd16_VLD1LNd32_VLD1LNd8_VLD1LNq16Pseudo_VLD1LNq32Pseudo_VLD1LNq8Pseudo
  { 0, 0, 0, 0, 0 }, // 543 VLD1DUPd16wb_fixed_VLD1DUPd16wb_register_VLD1DUPd32wb_fixed_VLD1DUPd32wb_register_VLD1DUPd8wb_fixed_VLD1DUPd8wb_register_VLD1DUPq16wb_fixed_VLD1DUPq16wb_register_VLD1DUPq32wb_fixed_VLD1DUPq32wb_register_VLD1DUPq8wb_fixed_VLD1DUPq8wb_register
  { 0, 0, 0, 0, 0 }, // 544 VLD1LNd16_UPD_VLD1LNd32_UPD_VLD1LNd8_UPD_VLD1LNq16Pseudo_UPD_VLD1LNq32Pseudo_UPD_VLD1LNq8Pseudo_UPD
  { 0, 0, 0, 0, 0 }, // 545 VLD2DUPd16_VLD2DUPd16x2_VLD2DUPd32_VLD2DUPd32x2_VLD2DUPd8_VLD2DUPd8x2
  { 0, 0, 0, 0, 0 }, // 546 VLD2LNd16_VLD2LNd16Pseudo_VLD2LNd32_VLD2LNd32Pseudo_VLD2LNd8_VLD2LNd8Pseudo_VLD2LNq16_VLD2LNq16Pseudo_VLD2LNq32_VLD2LNq32Pseudo
  { 0, 0, 0, 0, 0 }, // 547 VLD2LNd16_UPD_VLD2LNd32_UPD_VLD2LNd8_UPD_VLD2LNq16_UPD_VLD2LNq32_UPD
  { 0, 0, 0, 0, 0 }, // 548 VLD2DUPd16wb_fixed_VLD2DUPd16wb_register_VLD2DUPd16x2wb_fixed_VLD2DUPd16x2wb_register_VLD2DUPd32wb_fixed_VLD2DUPd32wb_register_VLD2DUPd32x2wb_fixed_VLD2DUPd32x2wb_register_VLD2DUPd8wb_fixed_VLD2DUPd8wb_register_VLD2DUPd8x2wb_fixed_VLD2DUPd8x2wb_register
  { 0, 0, 0, 0, 0 }, // 549 VLD2LNd16Pseudo_UPD_VLD2LNd32Pseudo_UPD_VLD2LNd8Pseudo_UPD_VLD2LNq16Pseudo_UPD_VLD2LNq32Pseudo_UPD
  { 0, 0, 0, 0, 0 }, // 550 VLD3DUPd16_VLD3DUPd16Pseudo_VLD3DUPd32_VLD3DUPd32Pseudo_VLD3DUPd8_VLD3DUPd8Pseudo_VLD3DUPq16_VLD3DUPq32_VLD3DUPq8
  { 0, 0, 0, 0, 0 }, // 551 VLD3LNd16_VLD3LNd16Pseudo_VLD3LNd32_VLD3LNd32Pseudo_VLD3LNd8_VLD3LNd8Pseudo_VLD3LNq16_VLD3LNq16Pseudo_VLD3LNq32_VLD3LNq32Pseudo
  { 0, 0, 0, 0, 0 }, // 552 VLD3DUPd16_UPD_VLD3DUPd32_UPD_VLD3DUPd8_UPD_VLD3DUPq16_UPD_VLD3DUPq32_UPD_VLD3DUPq8_UPD
  { 0, 0, 0, 0, 0 }, // 553 VLD3LNd16_UPD_VLD3LNd32_UPD_VLD3LNd8_UPD_VLD3LNq16_UPD_VLD3LNq32_UPD
  { 0, 0, 0, 0, 0 }, // 554 VLD3DUPd16Pseudo_UPD_VLD3DUPd32Pseudo_UPD_VLD3DUPd8Pseudo_UPD
  { 0, 0, 0, 0, 0 }, // 555 VLD3LNd16Pseudo_UPD_VLD3LNd32Pseudo_UPD_VLD3LNd8Pseudo_UPD_VLD3LNq16Pseudo_UPD_VLD3LNq32Pseudo_UPD
  { 0, 0, 0, 0, 0 }, // 556 VLD4DUPd16_VLD4DUPd16Pseudo_VLD4DUPd32_VLD4DUPd32Pseudo_VLD4DUPd8_VLD4DUPd8Pseudo_VLD4DUPq16_VLD4DUPq32_VLD4DUPq8
  { 0, 0, 0, 0, 0 }, // 557 VLD4LNd16_VLD4LNd16Pseudo_VLD4LNd32_VLD4LNd32Pseudo_VLD4LNd8_VLD4LNd8Pseudo_VLD4LNq16_VLD4LNq16Pseudo_VLD4LNq32_VLD4LNq32Pseudo
  { 0, 0, 0, 0, 0 }, // 558 VLD4DUPd16_UPD_VLD4DUPd32_UPD_VLD4DUPd8_UPD_VLD4DUPq16_UPD_VLD4DUPq32_UPD_VLD4DUPq8_UPD
  { 0, 0, 0, 0, 0 }, // 559 VLD4LNd16_UPD_VLD4LNd32_UPD_VLD4LNd8_UPD_VLD4LNq16_UPD_VLD4LNq32_UPD
  { 0, 0, 0, 0, 0 }, // 560 VLD4DUPd16Pseudo_UPD_VLD4DUPd32Pseudo_UPD_VLD4DUPd8Pseudo_UPD
  { 0, 0, 0, 0, 0 }, // 561 VLD4LNd16Pseudo_UPD_VLD4LNd32Pseudo_UPD_VLD4LNd8Pseudo_UPD_VLD4LNq16Pseudo_UPD_VLD4LNq32Pseudo_UPD
  { 0, 0, 0, 0, 0 }, // 562 VST1d16_VST1d32_VST1d64_VST1d8
  { 0, 0, 0, 0, 0 }, // 563 VST1q16_VST1q32_VST1q64_VST1q8
  { 0, 0, 0, 0, 0 }, // 564 VST1d16wb_fixed_VST1d16wb_register_VST1d32wb_fixed_VST1d32wb_register_VST1d64wb_fixed_VST1d64wb_register_VST1d8wb_fixed_VST1d8wb_register
  { 0, 0, 0, 0, 0 }, // 565 VST1q16wb_fixed_VST1q16wb_register_VST1q32wb_fixed_VST1q32wb_register_VST1q64wb_fixed_VST1q64wb_register_VST1q8wb_fixed_VST1q8wb_register
  { 0, 0, 0, 0, 0 }, // 566 VST1d16T_VST1d32T_VST1d64T_VST1d64TPseudo_VST1d8T
  { 0, 0, 0, 0, 0 }, // 567 VST1d16Twb_fixed_VST1d16Twb_register_VST1d32Twb_fixed_VST1d32Twb_register_VST1d64Twb_fixed_VST1d64Twb_register_VST1d8Twb_fixed_VST1d8Twb_register
  { 0, 0, 0, 0, 0 }, // 568 VST1d64TPseudoWB_fixed_VST1d64TPseudoWB_register
  { 0, 0, 0, 0, 0 }, // 569 VST1d16Q_VST1d32Q_VST1d64Q_VST1d64QPseudo_VST1d8Q
  { 0, 0, 0, 0, 0 }, // 570 VST1d16Qwb_fixed_VST1d16Qwb_register_VST1d32Qwb_fixed_VST1d32Qwb_register_VST1d64Qwb_fixed_VST1d64Qwb_register_VST1d8Qwb_fixed_VST1d8Qwb_register
  { 0, 0, 0, 0, 0 }, // 571 VST1d64QPseudoWB_fixed_VST1d64QPseudoWB_register
  { 0, 0, 0, 0, 0 }, // 572 VST2b16_VST2b32_VST2b8_VST2d16_VST2d32_VST2d8
  { 0, 0, 0, 0, 0 }, // 573 VST2b16wb_fixed_VST2b16wb_register_VST2b32wb_fixed_VST2b32wb_register_VST2b8wb_fixed_VST2b8wb_register_VST2d16wb_fixed_VST2d16wb_register_VST2d32wb_fixed_VST2d32wb_register_VST2d8wb_fixed_VST2d8wb_register
  { 0, 0, 0, 0, 0 }, // 574 VST2q16_VST2q16Pseudo_VST2q32_VST2q32Pseudo_VST2q8_VST2q8Pseudo
  { 0, 0, 0, 0, 0 }, // 575 VST2q16PseudoWB_fixed_VST2q16PseudoWB_register_VST2q32PseudoWB_fixed_VST2q32PseudoWB_register_VST2q8PseudoWB_fixed_VST2q8PseudoWB_register
  { 0, 0, 0, 0, 0 }, // 576 VST2q16wb_fixed_VST2q16wb_register_VST2q32wb_fixed_VST2q32wb_register_VST2q8wb_fixed_VST2q8wb_register
  { 0, 0, 0, 0, 0 }, // 577 VST3d16_VST3d16Pseudo_VST3d32_VST3d32Pseudo_VST3d8_VST3d8Pseudo_VST3q16_VST3q16oddPseudo_VST3q32_VST3q32oddPseudo_VST3q8_VST3q8oddPseudo
  { 0, 0, 0, 0, 0 }, // 578 VST3d16Pseudo_UPD_VST3d16_UPD_VST3d32Pseudo_UPD_VST3d32_UPD_VST3d8Pseudo_UPD_VST3d8_UPD_VST3q16Pseudo_UPD_VST3q16_UPD_VST3q16oddPseudo_UPD_VST3q32Pseudo_UPD_VST3q32_UPD_VST3q32oddPseudo_UPD_VST3q8Pseudo_UPD_VST3q8_UPD_VST3q8oddPseudo_UPD
  { 0, 0, 0, 0, 0 }, // 579 VST4d16_VST4d16Pseudo_VST4d32_VST4d32Pseudo_VST4d8_VST4d8Pseudo_VST4q16_VST4q16oddPseudo_VST4q32_VST4q32oddPseudo_VST4q8_VST4q8oddPseudo
  { 0, 0, 0, 0, 0 }, // 580 VST4d16Pseudo_UPD_VST4d16_UPD_VST4d32Pseudo_UPD_VST4d32_UPD_VST4d8Pseudo_UPD_VST4d8_UPD_VST4q16Pseudo_UPD_VST4q16_UPD_VST4q16oddPseudo_UPD_VST4q32Pseudo_UPD_VST4q32_UPD_VST4q32oddPseudo_UPD_VST4q8Pseudo_UPD_VST4q8_UPD_VST4q8oddPseudo_UPD
  { 0, 0, 0, 0, 0 }, // 581 VST1LNd16_VST1LNd32_VST1LNd8_VST1LNq16Pseudo_VST1LNq32Pseudo_VST1LNq8Pseudo
  { 0, 0, 0, 0, 0 }, // 582 VST1LNd16_UPD_VST1LNd32_UPD_VST1LNd8_UPD_VST1LNq16Pseudo_UPD_VST1LNq32Pseudo_UPD_VST1LNq8Pseudo_UPD
  { 0, 0, 0, 0, 0 }, // 583 VST2LNd16_VST2LNd16Pseudo_VST2LNd32_VST2LNd32Pseudo_VST2LNd8_VST2LNd8Pseudo_VST2LNq16_VST2LNq16Pseudo_VST2LNq32_VST2LNq32Pseudo
  { 0, 0, 0, 0, 0 }, // 584 VST2LNd16Pseudo_UPD_VST2LNd16_UPD_VST2LNd32Pseudo_UPD_VST2LNd32_UPD_VST2LNd8Pseudo_UPD_VST2LNd8_UPD_VST2LNq16Pseudo_UPD_VST2LNq16_UPD_VST2LNq32Pseudo_UPD_VST2LNq32_UPD
  { 0, 0, 0, 0, 0 }, // 585 VST3LNd16_VST3LNd16Pseudo_VST3LNd32_VST3LNd32Pseudo_VST3LNd8_VST3LNd8Pseudo_VST3LNq16_VST3LNq16Pseudo_VST3LNq32_VST3LNq32Pseudo
  { 0, 0, 0, 0, 0 }, // 586 VST3LNd16Pseudo_UPD_VST3LNd16_UPD_VST3LNd32Pseudo_UPD_VST3LNd32_UPD_VST3LNd8Pseudo_UPD_VST3LNd8_UPD_VST3LNq16Pseudo_UPD_VST3LNq16_UPD_VST3LNq32Pseudo_UPD_VST3LNq32_UPD
  { 0, 0, 0, 0, 0 }, // 587 VST4LNd16_VST4LNd16Pseudo_VST4LNd32_VST4LNd32Pseudo_VST4LNd8_VST4LNd8Pseudo_VST4LNq16_VST4LNq16Pseudo_VST4LNq32_VST4LNq32Pseudo
  { 0, 0, 0, 0, 0 }, // 588 VST4LNd16Pseudo_UPD_VST4LNd16_UPD_VST4LNd32Pseudo_UPD_VST4LNd32_UPD_VST4LNd8Pseudo_UPD_VST4LNd8_UPD_VST4LNq16Pseudo_UPD_VST4LNq16_UPD_VST4LNq32Pseudo_UPD_VST4LNq32_UPD
  { 1, 12, 13, 744, 747 }, // 589 VDIVS
  { 1, 12, 13, 747, 750 }, // 590 VSQRTS
  { 1, 11, 12, 750, 753 }, // 591 VDIVD
  { 1, 11, 12, 753, 756 }, // 592 VSQRTD
  { 0, 0, 0, 0, 0 }, // 593 ABS
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary CortexA9Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 13, 15, 756, 758 }, // 1 IIC_iALUi_WriteALU_ReadALU
  { 1, 13, 15, 758, 761 }, // 2 IIC_iALUr_WriteALU_ReadALU_ReadALU
  { 1, 15, 17, 761, 765 }, // 3 IIC_iALUsr_WriteALUsi_ReadALU
  { 1, 15, 17, 765, 769 }, // 4 IIC_iALUsr_WriteALUsr_ReadALUsr
  { 1, 15, 17, 769, 773 }, // 5 IIC_iALUsr_WriteALUSsr_ReadALUsr
  { 1, 13, 15, 773, 775 }, // 6 IIC_iBITi_WriteALU_ReadALU
  { 1, 13, 15, 775, 778 }, // 7 IIC_iBITr_WriteALU_ReadALU_ReadALU
  { 1, 15, 17, 778, 782 }, // 8 IIC_iBITsr_WriteALUsi_ReadALU
  { 1, 15, 17, 782, 786 }, // 9 IIC_iBITsr_WriteALUsr_ReadALUsr
  { 1, 17, 20, 0, 0 }, // 10 IIC_Br_WriteBr
  { 1, 20, 22, 786, 788 }, // 11 IIC_iUNAsi
  { 1, 17, 20, 0, 0 }, // 12 IIC_Br_WriteBrL
  { 0, 0, 0, 0, 0 }, // 13 WriteBrL
  { 1, 17, 20, 0, 0 }, // 14 IIC_Br_WriteBrTbl
  { 0, 0, 0, 0, 0 }, // 15 WriteBr
  { 1, 13, 15, 788, 790 }, // 16 IIC_iUNAr_WriteALU
  { 1, 13, 15, 790, 791 }, // 17 IIC_iCMPi_WriteCMP_ReadALU
  { 1, 13, 15, 791, 793 }, // 18 IIC_iCMPr_WriteCMP_ReadALU_ReadALU
  { 1, 15, 17, 793, 796 }, // 19 IIC_iCMPsr_WriteCMPsi_ReadALU
  { 1, 15, 17, 796, 799 }, // 20 IIC_iCMPsr_WriteCMPsr_ReadALU
  { 1, 22, 27, 799, 801 }, // 21 IIC_fpUNA64
  { 1, 22, 27, 801, 803 }, // 22 IIC_fpUNA32
  { 1, 27, 32, 803, 804 }, // 23 IIC_fpSTAT
  { -1, 32, 36, 804, 809 }, // 24 IIC_iLoad_m
  { -1, 32, 36, 809, 814 }, // 25 IIC_iLoad_mu
  { -1, 36, 41, 814, 819 }, // 26 IIC_iLoad_mBr
  { 1, 41, 45, 819, 823 }, // 27 IIC_iLoad_bh_ru
  { 1, 41, 45, 823, 826 }, // 28 IIC_iLoad_bh_iu
  { 1, 41, 45, 826, 829 }, // 29 IIC_iLoad_bh_r
  { 1, 41, 45, 829, 832 }, // 30 IIC_iLoad_bh_si
  { 1, 41, 45, 832, 836 }, // 31 IIC_iLoad_d_r
  { 1, 41, 45, 836, 840 }, // 32 IIC_iLoad_d_ru
  { 1, 45, 49, 840, 842 }, // 33 IIC_iLoad_i
  { 1, 49, 54, 842, 844 }, // 34 IIC_iLoadiALU
  { 1, 45, 49, 844, 848 }, // 35 IIC_iLoad_ru
  { 1, 45, 49, 848, 851 }, // 36 IIC_iLoad_iu
  { 1, 45, 49, 851, 854 }, // 37 IIC_iLoad_r
  { 1, 54, 58, 854, 857 }, // 38 IIC_iLoad_si
  { 1, 58, 60, 857, 861 }, // 39 IIC_iMAC32
  { 1, 13, 15, 861, 862 }, // 40 IIC_iCMOVi_WriteALU
  { 1, 13, 15, 862, 863 }, // 41 IIC_iMOVi_WriteALU
  { 1, 60, 64, 863, 864 }, // 42 IIC_iCMOVix2
  { 1, 13, 15, 864, 866 }, // 43 IIC_iCMOVr_WriteALU
  { 1, 20, 22, 866, 869 }, // 44 IIC_iCMOVsr_WriteALU
  { 1, 64, 68, 869, 870 }, // 45 IIC_iMOVix2addpc
  { 1, 68, 74, 870, 871 }, // 46 IIC_iMOVix2ld
  { 1, 74, 77, 871, 872 }, // 47 IIC_iMOVix2
  { 1, 13, 15, 872, 874 }, // 48 IIC_iMOVr_WriteALU
  { 1, 20, 22, 874, 877 }, // 49 IIC_iMOVsr_WriteALU
  { 1, 13, 15, 877, 879 }, // 50 IIC_iMOVsi_WriteALU
  { 1, 58, 60, 879, 882 }, // 51 IIC_iMUL32
  { 1, 13, 15, 882, 883 }, // 52 IIC_iMVNi_WriteALU
  { 1, 13, 15, 883, 885 }, // 53 IIC_iMVNr_WriteALU
  { 1, 15, 17, 885, 888 }, // 54 IIC_iMVNsr_WriteALU
  { 1, 13, 15, 888, 891 }, // 55 IIC_iALUr_WriteALU_ReadALU
  { 1, 45, 49, 891, 894 }, // 56 IIC_iStore_r
  { 1, 77, 81, 894, 897 }, // 57 IIC_iStore_bh_r
  { 1, 20, 22, 897, 900 }, // 58 IIC_iALUsi_WriteALUsi_ReadALU
  { 1, 20, 22, 900, 903 }, // 59 IIC_iBITsi_WriteALUsi_ReadALU
  { 1, 81, 82, 903, 905 }, // 60 IIC_Preload_WritePreLd
  { 0, 0, 0, 0, 0 }, // 61 IIC_iDIV
  { 1, 58, 60, 905, 909 }, // 62 IIC_iMAC16
  { 1, 82, 84, 909, 913 }, // 63 IIC_iMAC64
  { 1, 58, 60, 913, 916 }, // 64 IIC_iMUL16
  { 1, 82, 84, 916, 920 }, // 65 IIC_iMUL64
  { -1, 84, 88, 0, 0 }, // 66 IIC_iStore_m
  { -1, 84, 88, 920, 921 }, // 67 IIC_iStore_mu
  { 1, 77, 81, 921, 925 }, // 68 IIC_iStore_bh_ru
  { 1, 77, 81, 925, 928 }, // 69 IIC_iStore_bh_iu
  { 1, 45, 49, 928, 932 }, // 70 IIC_iStore_ru
  { 1, 77, 81, 932, 935 }, // 71 IIC_iStore_bh_si
  { 1, 77, 81, 935, 938 }, // 72 IIC_iStore_d_r
  { 1, 77, 81, 938, 942 }, // 73 IIC_iStore_d_ru
  { 1, 45, 49, 942, 945 }, // 74 IIC_iStore_iu
  { 1, 45, 49, 945, 948 }, // 75 IIC_iStore_si
  { 1, 17, 20, 0, 0 }, // 76 IIC_Br
  { 1, 20, 22, 948, 951 }, // 77 IIC_iEXTAr_WriteALUsr
  { 1, 13, 15, 951, 953 }, // 78 IIC_iEXTr_WriteALUsi
  { 1, 13, 15, 953, 954 }, // 79 IIC_iTSTi_WriteCMP_ReadALU
  { 1, 13, 15, 954, 956 }, // 80 IIC_iTSTr_WriteCMP_ReadALU_ReadALU
  { 1, 15, 17, 956, 959 }, // 81 IIC_iTSTsr_WriteCMPsi_ReadALU
  { 1, 15, 17, 959, 962 }, // 82 IIC_iTSTsr_WriteCMPsr_ReadALU
  { 0, 0, 0, 0, 0 }, // 83 WriteALU_ReadALU_ReadALU
  { 1, 88, 93, 962, 966 }, // 84 IIC_VABAD
  { 1, 93, 98, 966, 970 }, // 85 IIC_VABAQ
  { 1, 88, 93, 970, 973 }, // 86 IIC_VSUBi4Q
  { 1, 88, 93, 973, 976 }, // 87 IIC_VBIND
  { 1, 98, 103, 976, 979 }, // 88 IIC_VBINQ
  { 1, 88, 93, 979, 982 }, // 89 IIC_VSUBi4D
  { 1, 88, 93, 982, 984 }, // 90 IIC_VUNAD
  { 1, 98, 103, 984, 986 }, // 91 IIC_VUNAQ
  { 1, 88, 93, 986, 988 }, // 92 IIC_VUNAiQ
  { 1, 88, 93, 988, 990 }, // 93 IIC_VUNAiD
  { 1, 103, 108, 990, 993 }, // 94 IIC_fpALU64
  { 1, 88, 93, 993, 996 }, // 95 IIC_VBINi4D
  { 1, 88, 93, 996, 999 }, // 96 IIC_VSHLiD
  { 1, 103, 108, 999, 1002 }, // 97 IIC_fpALU32
  { 1, 88, 93, 1002, 1005 }, // 98 IIC_VSUBiD
  { 1, 88, 93, 1005, 1008 }, // 99 IIC_VBINiQ
  { 1, 88, 93, 1008, 1011 }, // 100 IIC_VBINiD
  { 1, 88, 93, 1011, 1012 }, // 101 IIC_VMOVImm
  { 1, 88, 93, 1012, 1015 }, // 102 IIC_VCNTiD
  { 1, 98, 103, 1015, 1018 }, // 103 IIC_VCNTiQ
  { 1, 103, 108, 1018, 1020 }, // 104 IIC_fpCMP64
  { 1, 103, 108, 1020, 1022 }, // 105 IIC_fpCMP32
  { 1, 103, 108, 1022, 1024 }, // 106 IIC_fpCVTSH
  { 1, 22, 27, 1024, 1026 }, // 107 IIC_fpCVTHS
  { 1, 103, 108, 1026, 1028 }, // 108 IIC_fpCVTDS
  { 1, 103, 108, 1028, 1030 }, // 109 IIC_fpCVTSD
  { 1, 108, 113, 1030, 1033 }, // 110 IIC_fpDIV64
  { 1, 113, 118, 1033, 1036 }, // 111 IIC_fpDIV32
  { 1, 118, 123, 1036, 1038 }, // 112 IIC_VMOVIS
  { 1, 88, 93, 1038, 1040 }, // 113 IIC_VMOVD
  { 1, 88, 93, 1040, 1042 }, // 114 IIC_VMOVQ
  { 1, 88, 93, 1042, 1045 }, // 115 IIC_VEXTD
  { 1, 98, 103, 1045, 1048 }, // 116 IIC_VEXTQ
  { 1, 123, 128, 1048, 1052 }, // 117 IIC_fpFMAC64
  { 1, 128, 133, 1052, 1056 }, // 118 IIC_fpFMAC32
  { 1, 98, 103, 1056, 1060 }, // 119 IIC_VFMACD
  { 1, 133, 138, 1060, 1064 }, // 120 IIC_VFMACQ
  { 1, 118, 123, 1064, 1066 }, // 121 IIC_VMOVSI
  { 1, 88, 93, 1066, 1069 }, // 122 IIC_VBINi4Q
  { 1, 138, 144, 1069, 1071 }, // 123 IIC_VLD1dup
  { 1, 138, 144, 1071, 1075 }, // 124 IIC_VLD1dupu
  { 1, 144, 150, 1075, 1079 }, // 125 IIC_VLD1ln
  { 1, 144, 150, 1079, 1085 }, // 126 IIC_VLD1lnu
  { 1, 138, 144, 1085, 1087 }, // 127 IIC_VLD1
  { 1, 144, 150, 1087, 1092 }, // 128 IIC_VLD1x4
  { 1, 138, 144, 1092, 1096 }, // 129 IIC_VLD1x2u
  { 1, 144, 150, 1096, 1100 }, // 130 IIC_VLD1x3
  { 1, 138, 144, 1100, 1103 }, // 131 IIC_VLD1u
  { 1, 138, 144, 1103, 1106 }, // 132 IIC_VLD1x2
  { 1, 138, 144, 1106, 1109 }, // 133 IIC_VLD2dup
  { 1, 138, 144, 1109, 1114 }, // 134 IIC_VLD2dupu
  { 1, 144, 150, 1114, 1120 }, // 135 IIC_VLD2ln
  { 1, 144, 150, 1120, 1128 }, // 136 IIC_VLD2lnu
  { 1, 138, 144, 1128, 1131 }, // 137 IIC_VLD2
  { 1, 138, 144, 1131, 1137 }, // 138 IIC_VLD2u
  { 1, 144, 150, 1137, 1142 }, // 139 IIC_VLD2x2
  { 1, 144, 150, 1142, 1148 }, // 140 IIC_VLD2x2u
  { 1, 150, 156, 1148, 1152 }, // 141 IIC_VLD3dup
  { 1, 150, 156, 1152, 1158 }, // 142 IIC_VLD3dupu
  { 1, 156, 162, 1158, 1166 }, // 143 IIC_VLD3ln
  { 1, 156, 162, 1166, 1176 }, // 144 IIC_VLD3lnu
  { 1, 150, 156, 1176, 1180 }, // 145 IIC_VLD3
  { 1, 150, 156, 1180, 1185 }, // 146 IIC_VLD3u
  { 1, 144, 150, 1185, 1190 }, // 147 IIC_VLD4dup
  { 1, 144, 150, 1190, 1197 }, // 148 IIC_VLD4dupu
  { 1, 162, 168, 1197, 1207 }, // 149 IIC_VLD4ln
  { 1, 162, 168, 1207, 1219 }, // 150 IIC_VLD4lnu
  { 1, 150, 156, 1219, 1224 }, // 151 IIC_VLD4
  { 1, 150, 156, 1224, 1230 }, // 152 IIC_VLD4u
  { -1, 168, 174, 1230, 1234 }, // 153 IIC_fpLoad_mu
  { -1, 168, 174, 1234, 1238 }, // 154 IIC_fpLoad_m
  { 1, 174, 180, 1238, 1240 }, // 155 IIC_fpLoad64
  { 1, 174, 180, 1240, 1242 }, // 156 IIC_fpLoad32
  { 1, 123, 128, 1242, 1246 }, // 157 IIC_fpMAC64
  { 1, 98, 103, 1246, 1250 }, // 158 IIC_VMACi32D
  { 1, 88, 93, 1250, 1254 }, // 159 IIC_VMACi16D
  { 1, 128, 133, 1254, 1258 }, // 160 IIC_fpMAC32
  { 1, 98, 103, 1258, 1262 }, // 161 IIC_VMACD
  { 1, 133, 138, 1262, 1266 }, // 162 IIC_VMACQ
  { 1, 133, 138, 1266, 1270 }, // 163 IIC_VMACi32Q
  { 1, 98, 103, 1270, 1274 }, // 164 IIC_VMACi16Q
  { 1, 22, 27, 1274, 1277 }, // 165 IIC_fpMOVID
  { 1, 88, 93, 1277, 1279 }, // 166 IIC_VQUNAiD
  { 1, 88, 93, 1279, 1281 }, // 167 IIC_VMOVN
  { 1, 180, 182, 1281, 1284 }, // 168 IIC_fpMOVDI
  { 1, 180, 182, 1284, 1286 }, // 169 IIC_fpMOVSI
  { 1, 22, 27, 1286, 1288 }, // 170 IIC_fpMOVIS
  { 1, 182, 187, 1288, 1291 }, // 171 IIC_fpMUL64
  { 1, 88, 93, 1291, 1294 }, // 172 IIC_VMULi16D
  { 1, 98, 103, 1294, 1297 }, // 173 IIC_VMULi32D
  { 1, 187, 192, 1297, 1300 }, // 174 IIC_fpMUL32
  { 1, 88, 93, 1300, 1303 }, // 175 IIC_VFMULD
  { 1, 192, 197, 1303, 1306 }, // 176 IIC_VFMULQ
  { 1, 98, 103, 1306, 1309 }, // 177 IIC_VMULi16Q
  { 1, 133, 138, 1309, 1312 }, // 178 IIC_VMULi32Q
  { 1, 88, 93, 1312, 1315 }, // 179 IIC_VSHLiQ
  { 1, 93, 98, 1315, 1318 }, // 180 IIC_VPALiQ
  { 1, 88, 93, 1318, 1321 }, // 181 IIC_VPALiD
  { 1, 88, 93, 1321, 1324 }, // 182 IIC_VPBIND
  { 1, 88, 93, 1324, 1326 }, // 183 IIC_VQUNAiQ
  { 1, 88, 93, 1326, 1329 }, // 184 IIC_VSHLi4Q
  { 1, 88, 93, 1329, 1332 }, // 185 IIC_VSHLi4D
  { 1, 197, 202, 1332, 1335 }, // 186 IIC_VRECSD
  { 1, 202, 207, 1335, 1338 }, // 187 IIC_VRECSQ
  { 1, 207, 212, 1338, 1341 }, // 188 IIC_VMOVISL
  { 1, 103, 108, 1341, 1343 }, // 189 IIC_fpCVTID_WriteCvtFP
  { 1, 103, 108, 1343, 1345 }, // 190 IIC_fpCVTIS_WriteCvtFP
  { 1, 103, 108, 1345, 1347 }, // 191 IIC_fpCVTID
  { 1, 103, 108, 1347, 1349 }, // 192 IIC_fpCVTIS
  { 1, 212, 217, 1349, 1351 }, // 193 IIC_fpSQRT64
  { 1, 217, 222, 1351, 1353 }, // 194 IIC_fpSQRT32
  { 1, 222, 228, 1353, 1356 }, // 195 IIC_VST1ln
  { 1, 222, 228, 1356, 1361 }, // 196 IIC_VST1lnu
  { 1, 222, 228, 1361, 1364 }, // 197 IIC_VST1
  { 1, 228, 234, 1364, 1370 }, // 198 IIC_VST1x4
  { 1, 144, 150, 1370, 1376 }, // 199 IIC_VLD1x4u
  { 1, 228, 234, 1376, 1381 }, // 200 IIC_VST1x3
  { 1, 144, 150, 1381, 1386 }, // 201 IIC_VLD1x3u
  { 1, 228, 234, 1386, 1394 }, // 202 IIC_VST1x4u
  { 1, 228, 234, 1394, 1401 }, // 203 IIC_VST1x3u
  { 1, 222, 228, 1401, 1405 }, // 204 IIC_VST1x2
  { 1, 222, 228, 1405, 1409 }, // 205 IIC_VST2ln
  { 1, 222, 228, 1409, 1415 }, // 206 IIC_VST2lnu
  { 1, 222, 228, 1415, 1419 }, // 207 IIC_VST2
  { 1, 234, 240, 1419, 1425 }, // 208 IIC_VST2x2
  { 1, 234, 240, 1425, 1433 }, // 209 IIC_VST2x2u
  { 1, 234, 240, 1433, 1438 }, // 210 IIC_VST3ln
  { 1, 234, 240, 1438, 1445 }, // 211 IIC_VST3lnu
  { 1, 228, 234, 1445, 1450 }, // 212 IIC_VST3
  { 1, 228, 234, 1450, 1457 }, // 213 IIC_VST3u
  { 1, 228, 234, 1457, 1463 }, // 214 IIC_VST4ln
  { 1, 228, 234, 1463, 1471 }, // 215 IIC_VST4lnu
  { 1, 228, 234, 1471, 1477 }, // 216 IIC_VST4
  { 1, 228, 234, 1477, 1485 }, // 217 IIC_VST4u
  { -1, 168, 174, 1485, 1489 }, // 218 IIC_fpStore_mu
  { -1, 168, 174, 1489, 1493 }, // 219 IIC_fpStore_m
  { 1, 174, 180, 1493, 1495 }, // 220 IIC_fpStore64
  { 1, 174, 180, 1495, 1497 }, // 221 IIC_fpStore32
  { 1, 88, 93, 1497, 1500 }, // 222 IIC_VSUBiQ
  { 1, 98, 103, 1500, 1503 }, // 223 IIC_VTB1
  { 1, 240, 245, 1503, 1507 }, // 224 IIC_VTB2
  { 1, 245, 250, 1507, 1512 }, // 225 IIC_VTB3
  { 1, 250, 255, 1512, 1518 }, // 226 IIC_VTB4
  { 1, 98, 103, 1518, 1522 }, // 227 IIC_VTBX1
  { 1, 98, 103, 1522, 1527 }, // 228 IIC_VTBX2
  { 1, 250, 255, 1527, 1533 }, // 229 IIC_VTBX3
  { 1, 255, 260, 1533, 1540 }, // 230 IIC_VTBX4
  { 1, 103, 108, 1540, 1542 }, // 231 IIC_fpCVTDI_WriteCvtFP
  { 1, 103, 108, 1542, 1544 }, // 232 IIC_fpCVTSI_WriteCvtFP
  { 1, 103, 108, 1544, 1546 }, // 233 IIC_fpCVTDI
  { 1, 103, 108, 1546, 1548 }, // 234 IIC_fpCVTSI
  { 1, 88, 93, 1548, 1552 }, // 235 IIC_VPERMD
  { 1, 98, 103, 1552, 1556 }, // 236 IIC_VPERMQ
  { 1, 250, 255, 1556, 1560 }, // 237 IIC_VPERMQ3
  { 1, 20, 22, 1560, 1563 }, // 238 IIC_iALUsi_WriteALUsi_ReadALUsr
  { 1, 13, 15, 1563, 1565 }, // 239 IIC_iBITi
  { 1, 20, 22, 1565, 1567 }, // 240 IIC_iCMPsi_WriteCMPsi_ReadALU_ReadALU
  { 1, 13, 15, 1567, 1568 }, // 241 IIC_iCMPi_WriteCMP
  { 1, 13, 15, 1568, 1570 }, // 242 IIC_iCMPr_WriteCMP
  { 1, 20, 22, 1570, 1572 }, // 243 IIC_iCMPsi_WriteCMPsi
  { 1, 13, 15, 0, 0 }, // 244 IIC_iALUx
  { 1, 41, 45, 1572, 1574 }, // 245 IIC_iLoad_bh_i
  { 1, 41, 45, 1574, 1577 }, // 246 IIC_iLoad_d_i
  { 1, 13, 15, 1577, 1579 }, // 247 IIC_iCMOVsi_WriteALU
  { 1, 13, 15, 1579, 1580 }, // 248 IIC_iMOVi
  { 1, 20, 22, 1580, 1582 }, // 249 IIC_iMVNsi_WriteALU
  { 1, 20, 22, 1582, 1585 }, // 250 IIC_iALUsir_WriteALUsi_ReadALU
  { 1, 77, 81, 1585, 1587 }, // 251 IIC_iStore_bh_i
  { 1, 45, 49, 1587, 1589 }, // 252 IIC_iStore_i
  { 1, 15, 17, 1589, 1593 }, // 253 IIC_iEXTAsr
  { 1, 13, 15, 1593, 1595 }, // 254 IIC_iEXTr
  { 1, 13, 15, 1595, 1596 }, // 255 IIC_iTSTi_WriteCMP
  { 1, 13, 15, 1596, 1598 }, // 256 IIC_iTSTr_WriteCMP
  { 1, 20, 22, 1598, 1600 }, // 257 IIC_iTSTsi_WriteCMPsi
  { 1, 13, 15, 1600, 1603 }, // 258 IIC_iALUr_WriteALU
  { 1, 13, 15, 1603, 1605 }, // 259 IIC_iALUi_WriteALU
  { 1, 13, 15, 1605, 1608 }, // 260 IIC_iBITr_WriteALU
  { -1, 32, 36, 1608, 1611 }, // 261 IIC_iPop
  { -1, 260, 265, 1611, 1614 }, // 262 IIC_iPop_Br_WriteBrL
  { 1, 13, 15, 1614, 1616 }, // 263 IIC_iTSTr_WriteALU
  { 1, 13, 15, 1616, 1618 }, // 264 ANDri_BICri_EORri_ORRri
  { 1, 13, 15, 1618, 1621 }, // 265 ANDrr_BICrr_EORrr_ORRrr
  { 1, 15, 17, 1621, 1625 }, // 266 ANDrsi_BICrsi_EORrsi_ORRrsi
  { 1, 15, 17, 1625, 1629 }, // 267 ANDrsr_BICrsr_EORrsr_ORRrsr
  { 1, 20, 22, 1629, 1632 }, // 268 MOVCCsi_MOVCCsr
  { 1, 20, 22, 1632, 1635 }, // 269 MOVsi_MOVsr
  { 1, 13, 15, 1635, 1637 }, // 270 MOVsra_flag_MOVsrl_flag
  { 1, 15, 17, 1637, 1640 }, // 271 MVNsr
  { 1, 13, 15, 1640, 1642 }, // 272 MVNr
  { 1, 60, 64, 1642, 1643 }, // 273 MOVCCi32imm
  { 1, 74, 77, 1643, 1644 }, // 274 MOVi32imm
  { 1, 64, 68, 1644, 1645 }, // 275 MOV_ga_pcrel
  { 1, 68, 74, 1645, 1646 }, // 276 MOV_ga_pcrel_ldr
  { 0, 0, 0, 0, 0 }, // 277 SEL
  { 1, 20, 22, 1646, 1648 }, // 278 BFC_BFI_SBFX_UBFX
  { 1, 58, 60, 1648, 1652 }, // 279 MLA_MLAv5_MLS_SMMLA_SMMLAR_SMMLS_SMMLSR
  { 1, 58, 60, 1652, 1655 }, // 280 MUL_MULv5_SMMUL_SMMULR
  { 1, 82, 84, 1655, 1659 }, // 281 SMLAL_SMLALBB_SMLALBT_SMLALTB_SMLALTT_SMLALv5_UMAAL_UMLAL_UMLALv5
  { 1, 82, 84, 1659, 1663 }, // 282 SMULL_SMULLv5_UMULL_UMULLv5
  { 0, 0, 0, 0, 0 }, // 283 SMLAD_SMLADX_SMLALD_SMLALDX_SMLSD_SMLSDX_SMLSLD_SMLSLDX_SMUAD_SMUADX_SMUSD_SMUSDX
  { 1, 58, 60, 1663, 1666 }, // 284 SMULBB_SMULBT_SMULTB_SMULTT_SMULWB_SMULWT
  { 1, 58, 60, 1666, 1670 }, // 285 SMLABB_SMLABT_SMLATB_SMLATT_SMLAWB_SMLAWT
  { 1, 45, 49, 1670, 1673 }, // 286 LDRi12_PICLDR
  { 1, 54, 58, 1673, 1676 }, // 287 LDRrs
  { 1, 41, 45, 1676, 1679 }, // 288 LDRBi12_LDRH_LDRSB_LDRSH_PICLDRB_PICLDRH_PICLDRSB_PICLDRSH
  { 1, 41, 45, 1679, 1683 }, // 289 LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE_LDRSBTi_LDRSBTr_LDRSB_POST_LDRSB_PRE_LDRSHTi_LDRSHTr_LDRSH_POST_LDRSH_PRE
  { 1, 13, 15, 1683, 1685 }, // 290 SXTB_SXTB16_SXTH_UXTB_UXTB16_UXTH
  { 1, 13, 15, 1685, 1687 }, // 291 t2SXTB_t2SXTB16_t2SXTH_t2UXTB_t2UXTB16_t2UXTH
  { 1, 60, 64, 1687, 1688 }, // 292 t2MOVCCi32imm
  { 1, 74, 77, 1688, 1689 }, // 293 t2MOVi32imm
  { 1, 64, 68, 1689, 1690 }, // 294 t2MOV_ga_pcrel
  { 1, 13, 15, 1690, 1691 }, // 295 t2MOVi16_ga_pcrel
  { 0, 0, 0, 0, 0 }, // 296 t2SEL
  { 1, 20, 22, 1691, 1693 }, // 297 t2BFC_t2SBFX_t2UBFX
  { 1, 13, 15, 1693, 1695 }, // 298 t2BFI
  { 1, 13, 15, 1695, 1698 }, // 299 QADD_QADD16_QADD8_QASX_QDADD_QDSUB_QSAX_QSUB_QSUB16_QSUB8_UQADD16_UQADD8_UQASX_UQSAX_UQSUB16_UQSUB8
  { 0, 0, 0, 0, 0 }, // 300 SSAT_SSAT16_USAT_USAT16_t2QADD_t2QADD16_t2QADD8_t2QASX_t2QDADD_t2QDSUB_t2QSAX_t2QSUB_t2QSUB16_t2QSUB8_t2SSAT_t2SSAT16_t2UQADD16_t2UQADD8_t2UQASX_t2UQSAX_t2UQSUB16_t2UQSUB8_t2USAT_t2USAT16
  { 1, 13, 15, 1698, 1701 }, // 301 SADD16_SADD8_SASX_SSAX_SSUB16_SSUB8_UADD16_UADD8_UASX_USAX_USUB16_USUB8
  { 0, 0, 0, 0, 0 }, // 302 t2SADD16_t2SADD8_t2SASX_t2SSAX_t2SSUB16_t2SSUB8_t2UADD16_t2UADD8_t2UASX_t2USAX_t2USUB16_t2USUB8
  { 1, 13, 15, 1701, 1704 }, // 303 SHADD16_SHADD8_SHASX_SHSAX_SHSUB16_SHSUB8_UHADD16_UHADD8_UHASX_UHSAX_UHSUB16_UHSUB8
  { 1, 20, 22, 1704, 1707 }, // 304 SXTAB_SXTAB16_SXTAH_UXTAB_UXTAB16_UXTAH
  { 0, 0, 0, 0, 0 }, // 305 t2SHADD16_t2SHADD8_t2SHASX_t2SHSAX_t2SHSUB16_t2SHSUB8_t2UHADD16_t2UHADD8_t2UHASX_t2UHSAX_t2UHSUB16_t2UHSUB8
  { 1, 15, 17, 1707, 1711 }, // 306 t2SXTAB_t2SXTAB16_t2SXTAH_t2UXTAB_t2UXTAB16_t2UXTAH
  { 0, 0, 0, 0, 0 }, // 307 USAD8
  { 0, 0, 0, 0, 0 }, // 308 USADA8
  { 0, 0, 0, 0, 0 }, // 309 SMUSD_SMUSDX
  { 1, 58, 60, 1711, 1714 }, // 310 t2MUL_t2SMMUL_t2SMMULR
  { 1, 58, 60, 1714, 1717 }, // 311 t2SMULBB_t2SMULBT_t2SMULTB_t2SMULTT_t2SMULWB_t2SMULWT
  { 1, 58, 60, 1717, 1721 }, // 312 t2SMUSD_t2SMUSDX
  { 1, 58, 60, 1721, 1725 }, // 313 t2MLA_t2MLS_t2SMMLA_t2SMMLAR_t2SMMLS_t2SMMLSR
  { 0, 0, 0, 0, 0 }, // 314 SMUAD_SMUADX
  { 1, 58, 60, 1725, 1729 }, // 315 t2SMUAD_t2SMUADX
  { 0, 0, 0, 0, 0 }, // 316 SMLSD_SMLSDX
  { 1, 58, 60, 1729, 1733 }, // 317 t2SMLABB_t2SMLABT_t2SMLATB_t2SMLATT_t2SMLAWB_t2SMLAWT
  { 1, 58, 60, 1733, 1737 }, // 318 t2SMLSD_t2SMLSDX
  { 0, 0, 0, 0, 0 }, // 319 SMLAD_SMLADX
  { 1, 58, 60, 1737, 1741 }, // 320 t2SMLAD_t2SMLADX
  { 1, 82, 84, 1741, 1745 }, // 321 SMULL_UMULL
  { 1, 82, 84, 1745, 1749 }, // 322 t2SMULL_t2UMULL
  { 1, 82, 84, 1749, 1753 }, // 323 t2SMLAL_t2SMLALBB_t2SMLALBT_t2SMLALD_t2SMLALDX_t2SMLALTB_t2SMLALTT_t2SMLSLD_t2SMLSLDX_t2UMAAL_t2UMLAL
  { 0, 0, 0, 0, 0 }, // 324 SDIV_UDIV_t2SDIV_t2UDIV
  { 1, 41, 45, 1753, 1756 }, // 325 LDRBi12
  { 1, 41, 45, 1756, 1759 }, // 326 LDRBrs_t2LDRBs_t2LDRHs
  { 0, 0, 0, 0, 0 }, // 327 LDREX_LDREXB_LDREXD_LDREXH_tLDRpci_pic
  { 1, 45, 49, 1759, 1762 }, // 328 LDRi12
  { 1, 41, 45, 1762, 1764 }, // 329 t2LDRBi12_t2LDRBi8_t2LDRBpci_t2LDRHi12_t2LDRHi8_t2LDRHpci_tLDRBi_tLDRHi
  { 1, 45, 49, 1764, 1766 }, // 330 t2LDRi12_t2LDRi8_t2LDRpci_tLDRi_tLDRpci_tLDRspi
  { 1, 49, 54, 1766, 1768 }, // 331 t2LDRpci_pic
  { 1, 54, 58, 1768, 1771 }, // 332 t2LDRs
  { 1, 41, 45, 1771, 1774 }, // 333 tLDRBr_tLDRHr
  { 1, 45, 49, 1774, 1777 }, // 334 tLDRr
  { 1, 41, 45, 1777, 1780 }, // 335 LDRH_PICLDRB_PICLDRH
  { 1, 45, 49, 1780, 1783 }, // 336 LDRcp
  { 1, 41, 45, 1783, 1785 }, // 337 t2LDRSBi12_t2LDRSBi8_t2LDRSBpci_t2LDRSHi12_t2LDRSHi8_t2LDRSHpci
  { 0, 0, 0, 0, 0 }, // 338 t2LDRSBpcrel_t2LDRSHpcrel
  { 1, 41, 45, 1785, 1788 }, // 339 t2LDRSBs_t2LDRSHs
  { 1, 41, 45, 1788, 1791 }, // 340 tLDRSB_tLDRSH
  { 1, 41, 45, 1791, 1795 }, // 341 LDRBT_POST_IMM_LDRBT_POST_REG_LDRB_POST_REG_LDRB_PRE_REG
  { 1, 41, 45, 1795, 1798 }, // 342 LDRB_POST_IMM_LDRB_PRE_IMM_t2LDRB_POST_t2LDRB_PRE_t2LDRH_POST_t2LDRH_PRE
  { 1, 41, 45, 1798, 1802 }, // 343 LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE
  { 1, 45, 49, 1802, 1806 }, // 344 LDRT_POST_IMM_LDRT_POST_REG_LDR_POST_REG_LDR_PRE_REG
  { 1, 45, 49, 1806, 1809 }, // 345 LDR_POST_IMM_LDR_PRE_IMM_t2LDR_POST_t2LDR_PRE
  { 1, 41, 45, 1809, 1811 }, // 346 t2LDRBT_t2LDRHT
  { 1, 45, 49, 1811, 1813 }, // 347 t2LDRT
  { 1, 41, 45, 1813, 1815 }, // 348 t2LDRSBT_t2LDRSHT
  { 1, 41, 45, 1815, 1818 }, // 349 t2LDRSB_POST_t2LDRSB_PRE_t2LDRSH_POST_t2LDRSH_PRE
  { 1, 41, 45, 1818, 1822 }, // 350 LDRD
  { 1, 41, 45, 1822, 1825 }, // 351 t2LDRDi8
  { 1, 41, 45, 1825, 1829 }, // 352 LDRD_POST_LDRD_PRE_t2LDRD_POST_t2LDRD_PRE
  { -1, 32, 36, 1829, 1834 }, // 353 LDMDA_LDMDB_LDMIA_LDMIB_sysLDMDA_sysLDMDB_sysLDMIA_sysLDMIB_t2LDMDB_t2LDMIA_tLDMIA
  { -1, 32, 36, 1834, 1839 }, // 354 LDMDA_UPD_LDMDB_UPD_LDMIA_UPD_LDMIB_UPD_sysLDMDA_UPD_sysLDMDB_UPD_sysLDMIA_UPD_sysLDMIB_UPD_t2LDMDB_UPD_t2LDMIA_UPD_tLDMIA_UPD
  { -1, 36, 41, 1839, 1844 }, // 355 LDMIA_RET_t2LDMIA_RET
  { -1, 32, 36, 1844, 1847 }, // 356 tPOP
  { -1, 260, 265, 1847, 1850 }, // 357 tPOP_RET
  { 1, 45, 49, 1850, 1853 }, // 358 PICSTR_STRi12_tSTRr
  { 1, 77, 81, 1853, 1856 }, // 359 PICSTRB_PICSTRH_STRBi12_STRH_tSTRBr_tSTRHr
  { 1, 77, 81, 1856, 1859 }, // 360 STRBrs_t2STRBs_t2STRHs
  { 0, 0, 0, 0, 0 }, // 361 STREX_STREXB_STREXD_STREXH
  { 1, 45, 49, 1859, 1862 }, // 362 STRrs_t2STRs
  { 1, 77, 81, 1862, 1864 }, // 363 t2STRBi12_t2STRBi8_t2STRHi12_t2STRHi8_tSTRBi_tSTRHi
  { 1, 45, 49, 1864, 1866 }, // 364 t2STRi12_t2STRi8_tSTRi_tSTRspi
  { 0, 0, 0, 0, 0 }, // 365 STRBT_POST_STRT_POST
  { 1, 77, 81, 1866, 1870 }, // 366 STRBT_POST_IMM_STRBT_POST_REG_STRB_POST_REG_STRB_PRE_REG_STRHTi_STRHTr_STRH_POST_STRH_PRE
  { 1, 77, 81, 1870, 1873 }, // 367 STRB_POST_IMM_STRB_PRE_IMM_t2STRB_POST_t2STRB_PRE_t2STRH_POST
  { 1, 45, 49, 1873, 1877 }, // 368 STRBi_preidx_STRBr_preidx_STRH_preidx_STRT_POST_IMM_STRT_POST_REG_STR_POST_REG_STR_PRE_REG_STRi_preidx_STRr_preidx_t2STRB_preidx_t2STRH_preidx_t2STR_preidx
  { 1, 45, 49, 1877, 1880 }, // 369 STR_POST_IMM_STR_PRE_IMM_t2STRH_PRE_t2STR_POST_t2STR_PRE
  { 1, 77, 81, 1880, 1882 }, // 370 t2STRBT_t2STRHT
  { 1, 45, 49, 1882, 1884 }, // 371 t2STRT
  { 1, 77, 81, 1884, 1887 }, // 372 STRD_t2STRDi8
  { 1, 77, 81, 1887, 1891 }, // 373 STRD_POST_STRD_PRE_t2STRD_POST_t2STRD_PRE
  { -1, 84, 88, 0, 0 }, // 374 STMDA_STMDB_STMIA_STMIB_sysSTMDA_sysSTMDB_sysSTMIA_sysSTMIB_t2STMDB_t2STMIA
  { -1, 84, 88, 1891, 1892 }, // 375 STMDA_UPD_STMDB_UPD_STMIA_UPD_STMIB_UPD_sysSTMDA_UPD_sysSTMDB_UPD_sysSTMIA_UPD_sysSTMIB_UPD_t2STMDB_UPD_t2STMIA_UPD_tSTMIA_UPD
  { -1, 84, 88, 0, 0 }, // 376 tPUSH
  { 1, 45, 49, 1892, 1894 }, // 377 LDRLIT_ga_abs_tLDRLIT_ga_abs
  { 1, 49, 54, 1894, 1896 }, // 378 LDRLIT_ga_pcrel_tLDRLIT_ga_pcrel
  { 0, 0, 0, 0, 0 }, // 379 LDRLIT_ga_pcrel_ldr
  { 0, 0, 0, 0, 0 }, // 380 ITasm
  { 1, 13, 15, 0, 0 }, // 381 t2IT
  { 1, 88, 93, 1896, 1899 }, // 382 VADDLsv2i64_VADDLsv4i32_VADDLsv8i16_VADDLuv2i64_VADDLuv4i32_VADDLuv8i16_VNEGs16d_VNEGs32d_VNEGs8d_VPADDLsv16i8_VPADDLsv2i32_VPADDLsv4i16_VPADDLsv4i32_VPADDLsv8i16_VPADDLsv8i8_VPADDLuv16i8_VPADDLuv2i32_VPADDLuv4i16_VPADDLuv4i32_VPADDLuv8i16_VPADDLuv8i8_VPADDi16_VPADDi32_VPADDi8_VSHLLi16_VSHLLi32_VSHLLi8_VSHLLsv2i64_VSHLLsv4i32_VSHLLsv8i16_VSHLLuv2i64_VSHLLuv4i32_VSHLLuv8i16_VSHLiv16i8_VSHLiv1i64_VSHLiv2i32_VSHLiv2i64_VSHLiv4i16_VSHLiv4i32_VSHLiv8i16_VSHLiv8i8_VSHLsv1i64_VSHLsv2i32_VSHLsv4i16_VSHLsv8i8_VSHLuv1i64_VSHLuv2i32_VSHLuv4i16_VSHLuv8i8_VSHRsv16i8_VSHRsv1i64_VSHRsv2i32_VSHRsv2i64_VSHRsv4i16_VSHRsv4i32_VSHRsv8i16_VSHRsv8i8_VSHRuv16i8_VSHRuv1i64_VSHRuv2i32_VSHRuv2i64_VSHRuv4i16_VSHRuv4i32_VSHRuv8i16_VSHRuv8i8_VSLIv1i64_VSLIv2i32_VSLIv4i16_VSLIv8i8_VSRIv1i64_VSRIv2i32_VSRIv4i16_VSRIv8i8_VSUBLsv2i64_VSUBLsv4i32_VSUBLsv8i16_VSUBLuv2i64_VSUBLuv4i32_VSUBLuv8i16
  { 1, 88, 93, 1899, 1902 }, // 383 VADDWsv2i64_VADDWsv4i32_VADDWsv8i16_VADDWuv2i64_VADDWuv4i32_VADDWuv8i16_VSUBWsv2i64_VSUBWsv4i32_VSUBWsv8i16_VSUBWuv2i64_VSUBWuv4i32_VSUBWuv8i16_VSUBv1i64_VSUBv2i32_VSUBv4i16_VSUBv8i8
  { 1, 88, 93, 1902, 1905 }, // 384 VADDv16i8_VADDv2i64_VADDv4i32_VADDv8i16_VANDq_VBICq_VBIFq_VBITq_VEORq_VORNq_VORRq
  { 1, 88, 93, 1905, 1908 }, // 385 VADDv1i64_VADDv2i32_VADDv4i16_VADDv8i8_VANDd_VBICd_VBIFd_VBITd_VEORd_VORNd_VORRd
  { 1, 88, 93, 1908, 1909 }, // 386 VBICiv2i32_VBICiv4i16_VBICiv4i32_VBICiv8i16_VORRiv2i32_VORRiv4i16_VORRiv4i32_VORRiv8i16
  { 1, 88, 93, 1909, 1912 }, // 387 VBSLd_VCLSv2i32_VCLSv4i16_VCLSv8i8_VCLZv2i32_VCLZv4i16_VCLZv8i8_VCNTd
  { 1, 98, 103, 1912, 1915 }, // 388 VBSLq_VCLSv16i8_VCLSv4i32_VCLSv8i16_VCLZv16i8_VCLZv4i32_VCLZv8i16_VCNTq
  { 1, 88, 93, 1915, 1918 }, // 389 VHADDsv16i8_VHADDsv4i32_VHADDsv8i16_VHADDuv16i8_VHADDuv4i32_VHADDuv8i16_VRHADDsv16i8_VRHADDsv4i32_VRHADDsv8i16_VRHADDuv16i8_VRHADDuv4i32_VRHADDuv8i16_VTSTv16i8_VTSTv4i32_VTSTv8i16
  { 1, 88, 93, 1918, 1921 }, // 390 VHADDsv2i32_VHADDsv4i16_VHADDsv8i8_VHADDuv2i32_VHADDuv4i16_VHADDuv8i8_VRHADDsv2i32_VRHADDsv4i16_VRHADDsv8i8_VRHADDuv2i32_VRHADDuv4i16_VRHADDuv8i8_VTSTv2i32_VTSTv4i16_VTSTv8i8
  { 1, 88, 93, 1921, 1924 }, // 391 VHSUBsv16i8_VHSUBsv4i32_VHSUBsv8i16_VHSUBuv16i8_VHSUBuv4i32_VHSUBuv8i16
  { 1, 88, 93, 1924, 1927 }, // 392 VHSUBsv2i32_VHSUBsv4i16_VHSUBsv8i8_VHSUBuv2i32_VHSUBuv4i16_VHSUBuv8i8
  { 1, 98, 103, 1927, 1929 }, // 393 VNEGf32q
  { 1, 88, 93, 1929, 1931 }, // 394 VNEGfd
  { 1, 88, 93, 1931, 1934 }, // 395 VNEGs16q_VNEGs32q_VNEGs8q_VSHLsv16i8_VSHLsv2i64_VSHLsv4i32_VSHLsv8i16_VSHLuv16i8_VSHLuv2i64_VSHLuv4i32_VSHLuv8i16_VSLIv16i8_VSLIv2i64_VSLIv4i32_VSLIv8i16_VSRIv16i8_VSRIv2i64_VSRIv4i32_VSRIv8i16
  { 1, 88, 93, 1934, 1937 }, // 396 VQSHLsiv16i8_VQSHLsiv1i64_VQSHLsiv2i32_VQSHLsiv2i64_VQSHLsiv4i16_VQSHLsiv4i32_VQSHLsiv8i16_VQSHLsiv8i8_VQSHLsuv16i8_VQSHLsuv1i64_VQSHLsuv2i32_VQSHLsuv2i64_VQSHLsuv4i16_VQSHLsuv4i32_VQSHLsuv8i16_VQSHLsuv8i8_VQSHLsv1i64_VQSHLsv2i32_VQSHLsv4i16_VQSHLsv8i8_VQSHLuiv16i8_VQSHLuiv1i64_VQSHLuiv2i32_VQSHLuiv2i64_VQSHLuiv4i16_VQSHLuiv4i32_VQSHLuiv8i16_VQSHLuiv8i8_VQSHLuv1i64_VQSHLuv2i32_VQSHLuv4i16_VQSHLuv8i8
  { 1, 88, 93, 1937, 1940 }, // 397 VQSHLsv16i8_VQSHLsv2i64_VQSHLsv4i32_VQSHLsv8i16_VQSHLuv16i8_VQSHLuv2i64_VQSHLuv4i32_VQSHLuv8i16
  { 1, 88, 93, 1940, 1943 }, // 398 VSUBv16i8_VSUBv2i64_VSUBv4i32_VSUBv8i16
  { 1, 88, 93, 1943, 1946 }, // 399 VEXTd16_VEXTd32_VEXTd8
  { 1, 98, 103, 1946, 1949 }, // 400 VEXTq16_VEXTq32_VEXTq64_VEXTq8
  { 1, 88, 93, 1949, 1951 }, // 401 VREV16d8_VREV32d16_VREV32d8_VREV64d16_VREV64d32_VREV64d8
  { 1, 88, 93, 1951, 1953 }, // 402 VREV16q8_VREV32q16_VREV32q8_VREV64q16_VREV64q32_VREV64q8
  { 1, 88, 93, 1953, 1957 }, // 403 VABALsv2i64_VABALsv4i32_VABALsv8i16_VABALuv2i64_VABALuv4i32_VABALuv8i16_VABAsv2i32_VABAsv4i16_VABAsv8i8_VABAuv2i32_VABAuv4i16_VABAuv8i8
  { 1, 93, 98, 1957, 1961 }, // 404 VABAsv16i8_VABAsv4i32_VABAsv8i16_VABAuv16i8_VABAuv4i32_VABAuv8i16
  { 1, 88, 93, 1961, 1963 }, // 405 VABSfd
  { 1, 98, 103, 1963, 1965 }, // 406 VABSfq
  { 1, 88, 93, 1965, 1967 }, // 407 VABSv16i8_VABSv4i32_VABSv8i16
  { 1, 88, 93, 1967, 1969 }, // 408 VABSv2i32_VABSv4i16_VABSv8i8
  { 1, 88, 93, 1969, 1972 }, // 409 VACGEd_VACGTd_VCEQfd_VCGEfd_VCGTfd
  { 1, 98, 103, 1972, 1975 }, // 410 VACGEq_VACGTq_VCEQfq_VCGEfq_VCGTfq
  { 1, 88, 93, 1975, 1978 }, // 411 VCEQv16i8_VCEQv4i32_VCEQv8i16_VCGEsv16i8_VCGEsv4i32_VCGEsv8i16_VCGEuv16i8_VCGEuv4i32_VCGEuv8i16_VCGTsv16i8_VCGTsv4i32_VCGTsv8i16_VCGTuv16i8_VCGTuv4i32_VCGTuv8i16_VQSUBsv16i8_VQSUBsv2i64_VQSUBsv4i32_VQSUBsv8i16_VQSUBuv16i8_VQSUBuv2i64_VQSUBuv4i32_VQSUBuv8i16
  { 1, 88, 93, 1978, 1981 }, // 412 VCEQv2i32_VCEQv4i16_VCEQv8i8_VCGEsv2i32_VCGEsv4i16_VCGEsv8i8_VCGEuv2i32_VCGEuv4i16_VCGEuv8i8_VCGTsv2i32_VCGTsv4i16_VCGTsv8i8_VCGTuv2i32_VCGTuv4i16_VCGTuv8i8_VQSUBsv1i64_VQSUBsv2i32_VQSUBsv4i16_VQSUBsv8i8_VQSUBuv1i64_VQSUBuv2i32_VQSUBuv4i16_VQSUBuv8i8
  { 0, 0, 0, 0, 0 }, // 413 VCEQzv16i8_VCEQzv2f32_VCEQzv2i32_VCEQzv4f32_VCEQzv4i16_VCEQzv4i32_VCEQzv8i16_VCEQzv8i8_VCGEzv16i8_VCGEzv2f32_VCGEzv2i32_VCGEzv4f32_VCGEzv4i16_VCGEzv4i32_VCGEzv8i16_VCGEzv8i8_VCGTzv16i8_VCGTzv2f32_VCGTzv2i32_VCGTzv4f32_VCGTzv4i16_VCGTzv4i32_VCGTzv8i16_VCGTzv8i8_VCLEzv16i8_VCLEzv2f32_VCLEzv2i32_VCLEzv4f32_VCLEzv4i16_VCLEzv4i32_VCLEzv8i16_VCLEzv8i8_VCLTzv16i8_VCLTzv2f32_VCLTzv2i32_VCLTzv4f32_VCLTzv4i16_VCLTzv4i32_VCLTzv8i16_VCLTzv8i8
  { 1, 93, 98, 1981, 1984 }, // 414 VPADALsv16i8_VPADALsv4i32_VPADALsv8i16_VPADALuv16i8_VPADALuv4i32_VPADALuv8i16
  { 1, 88, 93, 1984, 1987 }, // 415 VPADALsv2i32_VPADALsv4i16_VPADALsv8i8_VPADALuv2i32_VPADALuv4i16_VPADALuv8i8_VRSRAsv16i8_VRSRAsv1i64_VRSRAsv2i32_VRSRAsv2i64_VRSRAsv4i16_VRSRAsv4i32_VRSRAsv8i16_VRSRAsv8i8_VRSRAuv16i8_VRSRAuv1i64_VRSRAuv2i32_VRSRAuv2i64_VRSRAuv4i16_VRSRAuv4i32_VRSRAuv8i16_VRSRAuv8i8_VSRAsv16i8_VSRAsv1i64_VSRAsv2i32_VSRAsv2i64_VSRAsv4i16_VSRAsv4i32_VSRAsv8i16_VSRAsv8i8_VSRAuv16i8_VSRAuv1i64_VSRAuv2i32_VSRAuv2i64_VSRAuv4i16_VSRAuv4i32_VSRAuv8i16_VSRAuv8i8
  { 1, 88, 93, 1987, 1989 }, // 416 VQABSv16i8_VQABSv4i32_VQABSv8i16_VQNEGv16i8_VQNEGv4i32_VQNEGv8i16
  { 1, 88, 93, 1989, 1991 }, // 417 VQABSv2i32_VQABSv4i16_VQABSv8i8_VQNEGv2i32_VQNEGv4i16_VQNEGv8i8
  { 1, 88, 93, 1991, 1994 }, // 418 VQADDsv16i8_VQADDsv2i64_VQADDsv4i32_VQADDsv8i16_VQADDuv16i8_VQADDuv2i64_VQADDuv4i32_VQADDuv8i16
  { 1, 88, 93, 1994, 1997 }, // 419 VQADDsv1i64_VQADDsv2i32_VQADDsv4i16_VQADDsv8i8_VQADDuv1i64_VQADDuv2i32_VQADDuv4i16_VQADDuv8i8
  { 1, 88, 93, 1997, 2000 }, // 420 VQRSHLsv16i8_VQRSHLsv2i64_VQRSHLsv4i32_VQRSHLsv8i16_VQRSHLuv16i8_VQRSHLuv2i64_VQRSHLuv4i32_VQRSHLuv8i16_VRSHLsv16i8_VRSHLsv2i64_VRSHLsv4i32_VRSHLsv8i16_VRSHLuv16i8_VRSHLuv2i64_VRSHLuv4i32_VRSHLuv8i16
  { 1, 88, 93, 2000, 2003 }, // 421 VQRSHLsv1i64_VQRSHLsv2i32_VQRSHLsv4i16_VQRSHLsv8i8_VQRSHLuv1i64_VQRSHLuv2i32_VQRSHLuv4i16_VQRSHLuv8i8_VRSHLsv1i64_VRSHLsv2i32_VRSHLsv4i16_VRSHLsv8i8_VRSHLuv1i64_VRSHLuv2i32_VRSHLuv4i16_VRSHLuv8i8_VRSHRsv16i8_VRSHRsv1i64_VRSHRsv2i32_VRSHRsv2i64_VRSHRsv4i16_VRSHRsv4i32_VRSHRsv8i16_VRSHRsv8i8_VRSHRuv16i8_VRSHRuv1i64_VRSHRuv2i32_VRSHRuv2i64_VRSHRuv4i16_VRSHRuv4i32_VRSHRuv8i16_VRSHRuv8i8
  { 1, 88, 93, 2003, 2005 }, // 422 VRECPEd_VRECPEfd_VRSQRTEd_VRSQRTEfd
  { 1, 98, 103, 2005, 2007 }, // 423 VRECPEfq_VRECPEq_VRSQRTEfq_VRSQRTEq
  { 1, 88, 93, 2007, 2010 }, // 424 VADDHNv2i32_VADDHNv4i16_VADDHNv8i8_VSUBHNv2i32_VSUBHNv4i16_VSUBHNv8i8
  { 1, 88, 93, 2010, 2013 }, // 425 VSHRNv2i32_VSHRNv4i16_VSHRNv8i8
  { 1, 88, 93, 2013, 2016 }, // 426 VQRSHRNsv2i32_VQRSHRNsv4i16_VQRSHRNsv8i8_VQRSHRNuv2i32_VQRSHRNuv4i16_VQRSHRNuv8i8_VQRSHRUNv2i32_VQRSHRUNv4i16_VQRSHRUNv8i8_VQSHRNsv2i32_VQSHRNsv4i16_VQSHRNsv8i8_VQSHRNuv2i32_VQSHRNuv4i16_VQSHRNuv8i8_VQSHRUNv2i32_VQSHRUNv4i16_VQSHRUNv8i8_VRSHRNv2i32_VRSHRNv4i16_VRSHRNv8i8
  { 1, 88, 93, 2016, 2019 }, // 427 VRADDHNv2i32_VRADDHNv4i16_VRADDHNv8i8_VRSUBHNv2i32_VRSUBHNv4i16_VRSUBHNv8i8
  { 1, 98, 103, 2019, 2022 }, // 428 VTBL1
  { 1, 98, 103, 2022, 2026 }, // 429 VTBX1
  { 1, 240, 245, 2026, 2030 }, // 430 VTBL2
  { 1, 98, 103, 2030, 2035 }, // 431 VTBX2
  { 1, 245, 250, 2035, 2040 }, // 432 VTBL3_VTBL3Pseudo
  { 1, 250, 255, 2040, 2046 }, // 433 VTBX3_VTBX3Pseudo
  { 1, 250, 255, 2046, 2052 }, // 434 VTBL4_VTBL4Pseudo
  { 1, 255, 260, 2052, 2059 }, // 435 VTBX4_VTBX4Pseudo
  { 0, 0, 0, 0, 0 }, // 436 VSWPd_VSWPq
  { 1, 88, 93, 2059, 2063 }, // 437 VTRNd16_VTRNd32_VTRNd8_VUZPd16_VUZPd8_VZIPd16_VZIPd8
  { 1, 98, 103, 2063, 2067 }, // 438 VTRNq16_VTRNq32_VTRNq8
  { 1, 250, 255, 2067, 2071 }, // 439 VUZPq16_VUZPq32_VUZPq8_VZIPq16_VZIPq32_VZIPq8
  { 1, 22, 27, 2071, 2073 }, // 440 VABSD_VNEGD
  { 1, 22, 27, 2073, 2075 }, // 441 VABSS_VNEGS
  { 1, 103, 108, 2075, 2077 }, // 442 VCMPD_VCMPED_VCMPEZD_VCMPZD
  { 1, 103, 108, 2077, 2079 }, // 443 VCMPES_VCMPEZS_VCMPS_VCMPZS
  { 1, 88, 93, 2079, 2082 }, // 444 VABDLsv2i64_VABDLsv4i32_VABDLsv8i16_VABDLuv2i64_VABDLuv4i32_VABDLuv8i16_VABDsv16i8_VABDsv4i32_VABDsv8i16_VABDuv16i8_VABDuv4i32_VABDuv8i16_VMAXsv16i8_VMAXsv4i32_VMAXsv8i16_VMAXuv16i8_VMAXuv4i32_VMAXuv8i16_VMINsv16i8_VMINsv4i32_VMINsv8i16_VMINuv16i8_VMINuv4i32_VMINuv8i16
  { 1, 88, 93, 2082, 2085 }, // 445 VABDfd_VADDfd_VMAXfd_VMINfd_VSUBfd
  { 1, 98, 103, 2085, 2088 }, // 446 VABDfq_VADDfq_VMAXfq_VMINfq_VSUBfq
  { 1, 88, 93, 2088, 2091 }, // 447 VABDsv2i32_VABDsv4i16_VABDsv8i8_VABDuv2i32_VABDuv4i16_VABDuv8i8_VMAXsv2i32_VMAXsv4i16_VMAXsv8i8_VMAXuv2i32_VMAXuv4i16_VMAXuv8i8_VMINsv2i32_VMINsv4i16_VMINsv8i8_VMINuv2i32_VMINuv4i16_VMINuv8i8_VPMAXs16_VPMAXs32_VPMAXs8_VPMAXu16_VPMAXu32_VPMAXu8_VPMINs16_VPMINs32_VPMINs8_VPMINu16_VPMINu32_VPMINu8
  { 1, 103, 108, 2091, 2094 }, // 448 VADDS_VSUBS
  { 0, 0, 0, 0, 0 }, // 449 VMAXNMD_VMAXNMND_VMAXNMNQ_VMAXNMS_VMINNMD_VMINNMND_VMINNMNQ_VMINNMS
  { 1, 88, 93, 2094, 2097 }, // 450 VPADDf_VPMAXf_VPMINf
  { 1, 103, 108, 2097, 2100 }, // 451 VADDD_VSUBD
  { 1, 197, 202, 2100, 2103 }, // 452 VRECPSfd_VRSQRTSfd
  { 1, 202, 207, 2103, 2106 }, // 453 VRECPSfq_VRSQRTSfq
  { 0, 0, 0, 0, 0 }, // 454 VMULLp64
  { 1, 88, 93, 2106, 2109 }, // 455 VMULLp8_VMULLslsv2i32_VMULLslsv4i16_VMULLsluv2i32_VMULLsluv4i16_VMULLsv4i32_VMULLsv8i16_VMULLuv4i32_VMULLuv8i16_VMULpd_VMULslv4i16_VMULv4i16_VMULv8i8_VQDMULHslv4i16_VQDMULHv4i16_VQDMULLslv2i32_VQDMULLslv4i16_VQDMULLv4i32_VQRDMULHslv4i16_VQRDMULHv4i16
  { 1, 98, 103, 2109, 2112 }, // 456 VMULLsv2i64_VMULLuv2i64_VMULslv2i32_VMULv2i32_VQDMULHslv2i32_VQDMULHv2i32_VQDMULLv2i64_VQRDMULHslv2i32_VQRDMULHv2i32
  { 1, 187, 192, 2112, 2115 }, // 457 VMULS_VNMULS
  { 1, 88, 93, 2115, 2118 }, // 458 VMULfd
  { 1, 192, 197, 2118, 2121 }, // 459 VMULfq
  { 1, 98, 103, 2121, 2124 }, // 460 VMULpq_VMULslv8i16_VMULv16i8_VMULv8i16_VQDMULHslv8i16_VQDMULHv8i16_VQRDMULHslv8i16_VQRDMULHv8i16
  { 1, 88, 93, 2124, 2127 }, // 461 VMULslfd
  { 1, 98, 103, 2127, 2130 }, // 462 VMULslfq
  { 1, 133, 138, 2130, 2133 }, // 463 VMULslv4i32_VMULv4i32_VQDMULHslv4i32_VQDMULHv4i32_VQRDMULHslv4i32_VQRDMULHv4i32
  { 1, 182, 187, 2133, 2136 }, // 464 VMULD_VNMULD
  { 1, 123, 128, 2136, 2140 }, // 465 VFMAD_VFMSD_VFNMAD_VFNMSD
  { 1, 128, 133, 2140, 2144 }, // 466 VFMAS_VFMSS_VFNMAS_VFNMSS
  { 1, 123, 128, 2144, 2148 }, // 467 VMLAD_VMLSD_VNMLAD_VNMLSD
  { 1, 98, 103, 2148, 2152 }, // 468 VMLALslsv2i32_VMLALsluv2i32_VMLALsv2i64_VMLALuv2i64_VMLAslv2i32_VMLAv2i32_VMLSLslsv2i32_VMLSLsluv2i32_VMLSLsv2i64_VMLSLuv2i64_VMLSslv2i32_VMLSv2i32_VQDMLALslv2i32_VQDMLALv2i64_VQDMLSLslv2i32_VQDMLSLv2i64
  { 1, 88, 93, 2152, 2156 }, // 469 VMLALslsv4i16_VMLALsluv4i16_VMLALsv4i32_VMLALsv8i16_VMLALuv4i32_VMLALuv8i16_VMLAslv4i16_VMLAv4i16_VMLAv8i8_VMLSLslsv4i16_VMLSLsluv4i16_VMLSLsv4i32_VMLSLsv8i16_VMLSLuv4i32_VMLSLuv8i16_VMLSslv4i16_VMLSv4i16_VMLSv8i8_VQDMLALslv4i16_VQDMLALv4i32_VQDMLSLslv4i16_VQDMLSLv4i32
  { 1, 128, 133, 2156, 2160 }, // 470 VMLAS_VMLSS_VNMLAS_VNMLSS
  { 1, 98, 103, 2160, 2164 }, // 471 VMLAfd_VMLAslfd_VMLSfd_VMLSslfd
  { 1, 133, 138, 2164, 2168 }, // 472 VMLAfq_VMLAslfq_VMLSfq_VMLSslfq
  { 1, 133, 138, 2168, 2172 }, // 473 VMLAslv4i32_VMLAv4i32_VMLSslv4i32_VMLSv4i32
  { 1, 98, 103, 2172, 2176 }, // 474 VMLAslv8i16_VMLAv16i8_VMLAv8i16_VMLSslv8i16_VMLSv16i8_VMLSv8i16
  { 1, 98, 103, 2176, 2180 }, // 475 VFMAfd_VFMSfd
  { 1, 133, 138, 2180, 2184 }, // 476 VFMAfq_VFMSfq
  { 0, 0, 0, 0, 0 }, // 477 VCVTANSD_VCVTANSQ_VCVTANUD_VCVTANUQ_VCVTASD_VCVTASS_VCVTAUD_VCVTAUS_VCVTBDH_VCVTBHD_VCVTMNSD_VCVTMNSQ_VCVTMNUD_VCVTMNUQ_VCVTMSD_VCVTMSS_VCVTMUD_VCVTMUS_VCVTNNSD_VCVTNNSQ_VCVTNNUD_VCVTNNUQ_VCVTNSD_VCVTNSS_VCVTNUD_VCVTNUS_VCVTPNSD_VCVTPNSQ_VCVTPNUD_VCVTPNUQ_VCVTPSD_VCVTPSS_VCVTPUD_VCVTPUS_VCVTTDH_VCVTTHD
  { 1, 103, 108, 2184, 2186 }, // 478 VCVTBHS_VCVTTHS
  { 1, 22, 27, 2186, 2188 }, // 479 VCVTBSH_VCVTTSH
  { 1, 103, 108, 2188, 2190 }, // 480 VCVTDS
  { 1, 103, 108, 2190, 2192 }, // 481 VCVTSD
  { 1, 98, 103, 2192, 2194 }, // 482 VCVTf2h_VCVTf2sq_VCVTf2uq_VCVTf2xsq_VCVTf2xuq_VCVTh2f_VCVTs2fq_VCVTu2fq_VCVTxs2fq_VCVTxu2fq
  { 1, 88, 93, 2194, 2196 }, // 483 VCVTf2sd_VCVTf2ud_VCVTf2xsd_VCVTf2xud_VCVTs2fd_VCVTu2fd_VCVTxs2fd_VCVTxu2fd
  { 1, 103, 108, 2196, 2198 }, // 484 VSITOD_VUITOD
  { 1, 103, 108, 2198, 2200 }, // 485 VSITOS_VUITOS
  { 1, 103, 108, 2200, 2202 }, // 486 VTOSHD_VTOSLD_VTOUHD_VTOULD
  { 1, 103, 108, 2202, 2204 }, // 487 VTOSHS_VTOSLS_VTOUHS_VTOULS
  { 1, 103, 108, 2204, 2206 }, // 488 VTOSIRD_VTOSIZD_VTOUIRD_VTOUIZD
  { 1, 103, 108, 2206, 2208 }, // 489 VTOSIRS_VTOSIZS_VTOUIRS_VTOUIZS
  { 1, 22, 27, 2208, 2210 }, // 490 FCONSTD_VMOVD_VMOVDcc
  { 1, 22, 27, 2210, 2212 }, // 491 FCONSTS_VMOVS_VMOVScc
  { 1, 88, 93, 2212, 2213 }, // 492 VMOVv16i8_VMOVv1i64_VMOVv2f32_VMOVv2i32_VMOVv2i64_VMOVv4f32_VMOVv4i16_VMOVv4i32_VMOVv8i16_VMOVv8i8_VMVNv2i32_VMVNv4i16_VMVNv4i32_VMVNv8i16
  { 1, 88, 93, 2213, 2216 }, // 493 VMVNd_VMVNq
  { 1, 88, 93, 2216, 2218 }, // 494 VMOVLsv2i64_VMOVLsv4i32_VMOVLsv8i16_VMOVLuv2i64_VMOVLuv4i32_VMOVLuv8i16
  { 1, 88, 93, 2218, 2220 }, // 495 VMOVNv2i32_VMOVNv4i16_VMOVNv8i8
  { 1, 88, 93, 2220, 2222 }, // 496 VQMOVNsuv2i32_VQMOVNsuv4i16_VQMOVNsuv8i8_VQMOVNsv2i32_VQMOVNsv4i16_VQMOVNsv8i8_VQMOVNuv2i32_VQMOVNuv4i16_VQMOVNuv8i8
  { 1, 88, 93, 2222, 2224 }, // 497 VDUPLN16d_VDUPLN32d_VDUPLN8d
  { 1, 88, 93, 2224, 2226 }, // 498 VDUPLN16q_VDUPLN32q_VDUPLN8q
  { 1, 118, 123, 2226, 2228 }, // 499 VDUP16d_VDUP16q_VDUP32d_VDUP32q_VDUP8d_VDUP8q
  { 1, 180, 182, 2228, 2230 }, // 500 VMOVRS
  { 1, 22, 27, 2230, 2232 }, // 501 VMOVSR
  { 1, 207, 212, 2232, 2235 }, // 502 VSETLNi16_VSETLNi32_VSETLNi8
  { 1, 180, 182, 2235, 2238 }, // 503 VMOVRRD_VMOVRRS
  { 1, 22, 27, 2238, 2241 }, // 504 VMOVDRR
  { 1, 22, 27, 2241, 2244 }, // 505 VMOVSRR
  { 1, 118, 123, 2244, 2246 }, // 506 VGETLNi32_VGETLNu16_VGETLNu8
  { 1, 118, 123, 2246, 2248 }, // 507 VGETLNs16_VGETLNs8
  { 1, 27, 32, 2248, 2249 }, // 508 VMRS_VMRS_FPEXC_VMRS_FPINST_VMRS_FPINST2_VMRS_FPSID_VMRS_MVFR0_VMRS_MVFR1_VMRS_MVFR2
  { 1, 27, 32, 2249, 2250 }, // 509 VMSR_VMSR_FPEXC_VMSR_FPINST_VMSR_FPINST2_VMSR_FPSID
  { 1, 27, 32, 2250, 2251 }, // 510 FMSTAT
  { 1, 174, 180, 2251, 2253 }, // 511 VLDRD
  { 1, 174, 180, 2253, 2255 }, // 512 VLDRS
  { 1, 174, 180, 2255, 2257 }, // 513 VSTRD
  { 1, 174, 180, 2257, 2259 }, // 514 VSTRS
  { -1, 168, 174, 2259, 2263 }, // 515 VLDMQIA
  { -1, 168, 174, 2263, 2267 }, // 516 VSTMQIA
  { -1, 168, 174, 2267, 2271 }, // 517 VLDMDIA_VLDMSIA
  { -1, 168, 174, 2271, 2275 }, // 518 VLDMDDB_UPD_VLDMDIA_UPD_VLDMSDB_UPD_VLDMSIA_UPD
  { -1, 168, 174, 2275, 2279 }, // 519 VSTMDIA_VSTMSIA
  { -1, 168, 174, 2279, 2283 }, // 520 VSTMDDB_UPD_VSTMDIA_UPD_VSTMSDB_UPD_VSTMSIA_UPD
  { 1, 138, 144, 2283, 2285 }, // 521 VLD1d16_VLD1d32_VLD1d64_VLD1d8
  { 1, 138, 144, 2285, 2288 }, // 522 VLD1q16_VLD1q32_VLD1q64_VLD1q8
  { 1, 138, 144, 2288, 2291 }, // 523 VLD1d16wb_fixed_VLD1d16wb_register_VLD1d32wb_fixed_VLD1d32wb_register_VLD1d64wb_fixed_VLD1d64wb_register_VLD1d8wb_fixed_VLD1d8wb_register
  { 1, 138, 144, 2291, 2295 }, // 524 VLD1q16wb_fixed_VLD1q16wb_register_VLD1q32wb_fixed_VLD1q32wb_register_VLD1q64wb_fixed_VLD1q64wb_register_VLD1q8wb_fixed_VLD1q8wb_register
  { 1, 144, 150, 2295, 2299 }, // 525 VLD1d16T_VLD1d32T_VLD1d64T_VLD1d64TPseudo_VLD1d64TPseudoWB_fixed_VLD1d64TPseudoWB_register_VLD1d8T
  { 1, 138, 144, 2299, 2303 }, // 526 VLD1d16Twb_fixed_VLD1d16Twb_register_VLD1d32Twb_fixed_VLD1d32Twb_register_VLD1d64Twb_fixed_VLD1d64Twb_register_VLD1d8Twb_fixed_VLD1d8Twb_register
  { 1, 144, 150, 2303, 2308 }, // 527 VLD1d16Q_VLD1d32Q_VLD1d64Q_VLD1d64QPseudo_VLD1d64QPseudoWB_fixed_VLD1d64QPseudoWB_register_VLD1d8Q
  { 1, 138, 144, 2308, 2312 }, // 528 VLD1d16Qwb_fixed_VLD1d16Qwb_register_VLD1d32Qwb_fixed_VLD1d32Qwb_register_VLD1d64Qwb_fixed_VLD1d64Qwb_register_VLD1d8Qwb_fixed_VLD1d8Qwb_register
  { 1, 138, 144, 2312, 2315 }, // 529 VLD2b16_VLD2b32_VLD2b8_VLD2d16_VLD2d32_VLD2d8
  { 1, 144, 150, 2315, 2320 }, // 530 VLD2q16_VLD2q16Pseudo_VLD2q32_VLD2q32Pseudo_VLD2q8_VLD2q8Pseudo
  { 1, 138, 144, 2320, 2326 }, // 531 VLD2b16wb_fixed_VLD2b16wb_register_VLD2b32wb_fixed_VLD2b32wb_register_VLD2b8wb_fixed_VLD2b8wb_register_VLD2d16wb_fixed_VLD2d16wb_register_VLD2d32wb_fixed_VLD2d32wb_register_VLD2d8wb_fixed_VLD2d8wb_register
  { 1, 144, 150, 2326, 2332 }, // 532 VLD2q16PseudoWB_fixed_VLD2q16PseudoWB_register_VLD2q16wb_fixed_VLD2q16wb_register_VLD2q32PseudoWB_fixed_VLD2q32PseudoWB_register_VLD2q32wb_fixed_VLD2q32wb_register_VLD2q8PseudoWB_fixed_VLD2q8PseudoWB_register_VLD2q8wb_fixed_VLD2q8wb_register
  { 1, 150, 156, 2332, 2336 }, // 533 VLD3d16_VLD3d32_VLD3d8_VLD3q16_VLD3q32_VLD3q8
  { 1, 150, 156, 2336, 2340 }, // 534 VLD3d16Pseudo_VLD3d32Pseudo_VLD3d8Pseudo_VLD3q16oddPseudo_VLD3q32oddPseudo_VLD3q8oddPseudo
  { 1, 150, 156, 2340, 2345 }, // 535 VLD3d16_UPD_VLD3d32_UPD_VLD3d8_UPD_VLD3q16_UPD_VLD3q32_UPD_VLD3q8_UPD
  { 1, 150, 156, 2345, 2350 }, // 536 VLD3d16Pseudo_UPD_VLD3d32Pseudo_UPD_VLD3d8Pseudo_UPD_VLD3q16Pseudo_UPD_VLD3q16oddPseudo_UPD_VLD3q32Pseudo_UPD_VLD3q32oddPseudo_UPD_VLD3q8Pseudo_UPD_VLD3q8oddPseudo_UPD
  { 1, 150, 156, 2350, 2355 }, // 537 VLD4d16_VLD4d32_VLD4d8_VLD4q16_VLD4q32_VLD4q8
  { 1, 150, 156, 2355, 2360 }, // 538 VLD4d16Pseudo_VLD4d32Pseudo_VLD4d8Pseudo_VLD4q16oddPseudo_VLD4q32oddPseudo_VLD4q8oddPseudo
  { 1, 150, 156, 2360, 2366 }, // 539 VLD4d16_UPD_VLD4d32_UPD_VLD4d8_UPD_VLD4q16_UPD_VLD4q32_UPD_VLD4q8_UPD
  { 1, 150, 156, 2366, 2372 }, // 540 VLD4d16Pseudo_UPD_VLD4d32Pseudo_UPD_VLD4d8Pseudo_UPD_VLD4q16Pseudo_UPD_VLD4q16oddPseudo_UPD_VLD4q32Pseudo_UPD_VLD4q32oddPseudo_UPD_VLD4q8Pseudo_UPD_VLD4q8oddPseudo_UPD
  { 1, 138, 144, 2372, 2374 }, // 541 VLD1DUPd16_VLD1DUPd32_VLD1DUPd8_VLD1DUPq16_VLD1DUPq32_VLD1DUPq8
  { 1, 144, 150, 2374, 2378 }, // 542 VLD1LNd16_VLD1LNd32_VLD1LNd8_VLD1LNq16Pseudo_VLD1LNq32Pseudo_VLD1LNq8Pseudo
  { 1, 138, 144, 2378, 2382 }, // 543 VLD1DUPd16wb_fixed_VLD1DUPd16wb_register_VLD1DUPd32wb_fixed_VLD1DUPd32wb_register_VLD1DUPd8wb_fixed_VLD1DUPd8wb_register_VLD1DUPq16wb_fixed_VLD1DUPq16wb_register_VLD1DUPq32wb_fixed_VLD1DUPq32wb_register_VLD1DUPq8wb_fixed_VLD1DUPq8wb_register
  { 1, 144, 150, 2382, 2388 }, // 544 VLD1LNd16_UPD_VLD1LNd32_UPD_VLD1LNd8_UPD_VLD1LNq16Pseudo_UPD_VLD1LNq32Pseudo_UPD_VLD1LNq8Pseudo_UPD
  { 1, 138, 144, 2388, 2391 }, // 545 VLD2DUPd16_VLD2DUPd16x2_VLD2DUPd32_VLD2DUPd32x2_VLD2DUPd8_VLD2DUPd8x2
  { 1, 144, 150, 2391, 2397 }, // 546 VLD2LNd16_VLD2LNd16Pseudo_VLD2LNd32_VLD2LNd32Pseudo_VLD2LNd8_VLD2LNd8Pseudo_VLD2LNq16_VLD2LNq16Pseudo_VLD2LNq32_VLD2LNq32Pseudo
  { 1, 144, 150, 2397, 2405 }, // 547 VLD2LNd16_UPD_VLD2LNd32_UPD_VLD2LNd8_UPD_VLD2LNq16_UPD_VLD2LNq32_UPD
  { 1, 138, 144, 2405, 2410 }, // 548 VLD2DUPd16wb_fixed_VLD2DUPd16wb_register_VLD2DUPd16x2wb_fixed_VLD2DUPd16x2wb_register_VLD2DUPd32wb_fixed_VLD2DUPd32wb_register_VLD2DUPd32x2wb_fixed_VLD2DUPd32x2wb_register_VLD2DUPd8wb_fixed_VLD2DUPd8wb_register_VLD2DUPd8x2wb_fixed_VLD2DUPd8x2wb_register
  { 1, 144, 150, 2410, 2418 }, // 549 VLD2LNd16Pseudo_UPD_VLD2LNd32Pseudo_UPD_VLD2LNd8Pseudo_UPD_VLD2LNq16Pseudo_UPD_VLD2LNq32Pseudo_UPD
  { 1, 150, 156, 2418, 2422 }, // 550 VLD3DUPd16_VLD3DUPd16Pseudo_VLD3DUPd32_VLD3DUPd32Pseudo_VLD3DUPd8_VLD3DUPd8Pseudo_VLD3DUPq16_VLD3DUPq32_VLD3DUPq8
  { 1, 156, 162, 2422, 2430 }, // 551 VLD3LNd16_VLD3LNd16Pseudo_VLD3LNd32_VLD3LNd32Pseudo_VLD3LNd8_VLD3LNd8Pseudo_VLD3LNq16_VLD3LNq16Pseudo_VLD3LNq32_VLD3LNq32Pseudo
  { 1, 150, 156, 2430, 2436 }, // 552 VLD3DUPd16_UPD_VLD3DUPd32_UPD_VLD3DUPd8_UPD_VLD3DUPq16_UPD_VLD3DUPq32_UPD_VLD3DUPq8_UPD
  { 1, 156, 162, 2436, 2446 }, // 553 VLD3LNd16_UPD_VLD3LNd32_UPD_VLD3LNd8_UPD_VLD3LNq16_UPD_VLD3LNq32_UPD
  { 1, 150, 156, 2446, 2452 }, // 554 VLD3DUPd16Pseudo_UPD_VLD3DUPd32Pseudo_UPD_VLD3DUPd8Pseudo_UPD
  { 1, 156, 162, 2452, 2462 }, // 555 VLD3LNd16Pseudo_UPD_VLD3LNd32Pseudo_UPD_VLD3LNd8Pseudo_UPD_VLD3LNq16Pseudo_UPD_VLD3LNq32Pseudo_UPD
  { 1, 144, 150, 2462, 2467 }, // 556 VLD4DUPd16_VLD4DUPd16Pseudo_VLD4DUPd32_VLD4DUPd32Pseudo_VLD4DUPd8_VLD4DUPd8Pseudo_VLD4DUPq16_VLD4DUPq32_VLD4DUPq8
  { 1, 162, 168, 2467, 2477 }, // 557 VLD4LNd16_VLD4LNd16Pseudo_VLD4LNd32_VLD4LNd32Pseudo_VLD4LNd8_VLD4LNd8Pseudo_VLD4LNq16_VLD4LNq16Pseudo_VLD4LNq32_VLD4LNq32Pseudo
  { 1, 144, 150, 2477, 2484 }, // 558 VLD4DUPd16_UPD_VLD4DUPd32_UPD_VLD4DUPd8_UPD_VLD4DUPq16_UPD_VLD4DUPq32_UPD_VLD4DUPq8_UPD
  { 1, 162, 168, 2484, 2496 }, // 559 VLD4LNd16_UPD_VLD4LNd32_UPD_VLD4LNd8_UPD_VLD4LNq16_UPD_VLD4LNq32_UPD
  { 1, 144, 150, 2496, 2503 }, // 560 VLD4DUPd16Pseudo_UPD_VLD4DUPd32Pseudo_UPD_VLD4DUPd8Pseudo_UPD
  { 1, 162, 168, 2503, 2515 }, // 561 VLD4LNd16Pseudo_UPD_VLD4LNd32Pseudo_UPD_VLD4LNd8Pseudo_UPD_VLD4LNq16Pseudo_UPD_VLD4LNq32Pseudo_UPD
  { 1, 222, 228, 2515, 2518 }, // 562 VST1d16_VST1d32_VST1d64_VST1d8
  { 1, 222, 228, 2518, 2522 }, // 563 VST1q16_VST1q32_VST1q64_VST1q8
  { 1, 138, 144, 2522, 2525 }, // 564 VST1d16wb_fixed_VST1d16wb_register_VST1d32wb_fixed_VST1d32wb_register_VST1d64wb_fixed_VST1d64wb_register_VST1d8wb_fixed_VST1d8wb_register
  { 1, 138, 144, 2525, 2529 }, // 565 VST1q16wb_fixed_VST1q16wb_register_VST1q32wb_fixed_VST1q32wb_register_VST1q64wb_fixed_VST1q64wb_register_VST1q8wb_fixed_VST1q8wb_register
  { 1, 228, 234, 2529, 2534 }, // 566 VST1d16T_VST1d32T_VST1d64T_VST1d64TPseudo_VST1d8T
  { 1, 144, 150, 2534, 2539 }, // 567 VST1d16Twb_fixed_VST1d16Twb_register_VST1d32Twb_fixed_VST1d32Twb_register_VST1d64Twb_fixed_VST1d64Twb_register_VST1d8Twb_fixed_VST1d8Twb_register
  { 1, 228, 234, 2539, 2546 }, // 568 VST1d64TPseudoWB_fixed_VST1d64TPseudoWB_register
  { 1, 228, 234, 2546, 2552 }, // 569 VST1d16Q_VST1d32Q_VST1d64Q_VST1d64QPseudo_VST1d8Q
  { 1, 144, 150, 2552, 2558 }, // 570 VST1d16Qwb_fixed_VST1d16Qwb_register_VST1d32Qwb_fixed_VST1d32Qwb_register_VST1d64Qwb_fixed_VST1d64Qwb_register_VST1d8Qwb_fixed_VST1d8Qwb_register
  { 1, 228, 234, 2558, 2566 }, // 571 VST1d64QPseudoWB_fixed_VST1d64QPseudoWB_register
  { 1, 222, 228, 2566, 2570 }, // 572 VST2b16_VST2b32_VST2b8_VST2d16_VST2d32_VST2d8
  { 1, 138, 144, 2570, 2573 }, // 573 VST2b16wb_fixed_VST2b16wb_register_VST2b32wb_fixed_VST2b32wb_register_VST2b8wb_fixed_VST2b8wb_register_VST2d16wb_fixed_VST2d16wb_register_VST2d32wb_fixed_VST2d32wb_register_VST2d8wb_fixed_VST2d8wb_register
  { 1, 234, 240, 2573, 2579 }, // 574 VST2q16_VST2q16Pseudo_VST2q32_VST2q32Pseudo_VST2q8_VST2q8Pseudo
  { 1, 234, 240, 2579, 2587 }, // 575 VST2q16PseudoWB_fixed_VST2q16PseudoWB_register_VST2q32PseudoWB_fixed_VST2q32PseudoWB_register_VST2q8PseudoWB_fixed_VST2q8PseudoWB_register
  { 1, 138, 144, 2587, 2590 }, // 576 VST2q16wb_fixed_VST2q16wb_register_VST2q32wb_fixed_VST2q32wb_register_VST2q8wb_fixed_VST2q8wb_register
  { 1, 228, 234, 2590, 2595 }, // 577 VST3d16_VST3d16Pseudo_VST3d32_VST3d32Pseudo_VST3d8_VST3d8Pseudo_VST3q16_VST3q16oddPseudo_VST3q32_VST3q32oddPseudo_VST3q8_VST3q8oddPseudo
  { 1, 228, 234, 2595, 2602 }, // 578 VST3d16Pseudo_UPD_VST3d16_UPD_VST3d32Pseudo_UPD_VST3d32_UPD_VST3d8Pseudo_UPD_VST3d8_UPD_VST3q16Pseudo_UPD_VST3q16_UPD_VST3q16oddPseudo_UPD_VST3q32Pseudo_UPD_VST3q32_UPD_VST3q32oddPseudo_UPD_VST3q8Pseudo_UPD_VST3q8_UPD_VST3q8oddPseudo_UPD
  { 1, 228, 234, 2602, 2608 }, // 579 VST4d16_VST4d16Pseudo_VST4d32_VST4d32Pseudo_VST4d8_VST4d8Pseudo_VST4q16_VST4q16oddPseudo_VST4q32_VST4q32oddPseudo_VST4q8_VST4q8oddPseudo
  { 1, 228, 234, 2608, 2616 }, // 580 VST4d16Pseudo_UPD_VST4d16_UPD_VST4d32Pseudo_UPD_VST4d32_UPD_VST4d8Pseudo_UPD_VST4d8_UPD_VST4q16Pseudo_UPD_VST4q16_UPD_VST4q16oddPseudo_UPD_VST4q32Pseudo_UPD_VST4q32_UPD_VST4q32oddPseudo_UPD_VST4q8Pseudo_UPD_VST4q8_UPD_VST4q8oddPseudo_UPD
  { 1, 222, 228, 2616, 2619 }, // 581 VST1LNd16_VST1LNd32_VST1LNd8_VST1LNq16Pseudo_VST1LNq32Pseudo_VST1LNq8Pseudo
  { 1, 222, 228, 2619, 2624 }, // 582 VST1LNd16_UPD_VST1LNd32_UPD_VST1LNd8_UPD_VST1LNq16Pseudo_UPD_VST1LNq32Pseudo_UPD_VST1LNq8Pseudo_UPD
  { 1, 222, 228, 2624, 2628 }, // 583 VST2LNd16_VST2LNd16Pseudo_VST2LNd32_VST2LNd32Pseudo_VST2LNd8_VST2LNd8Pseudo_VST2LNq16_VST2LNq16Pseudo_VST2LNq32_VST2LNq32Pseudo
  { 1, 222, 228, 2628, 2634 }, // 584 VST2LNd16Pseudo_UPD_VST2LNd16_UPD_VST2LNd32Pseudo_UPD_VST2LNd32_UPD_VST2LNd8Pseudo_UPD_VST2LNd8_UPD_VST2LNq16Pseudo_UPD_VST2LNq16_UPD_VST2LNq32Pseudo_UPD_VST2LNq32_UPD
  { 1, 234, 240, 2634, 2639 }, // 585 VST3LNd16_VST3LNd16Pseudo_VST3LNd32_VST3LNd32Pseudo_VST3LNd8_VST3LNd8Pseudo_VST3LNq16_VST3LNq16Pseudo_VST3LNq32_VST3LNq32Pseudo
  { 1, 234, 240, 2639, 2646 }, // 586 VST3LNd16Pseudo_UPD_VST3LNd16_UPD_VST3LNd32Pseudo_UPD_VST3LNd32_UPD_VST3LNd8Pseudo_UPD_VST3LNd8_UPD_VST3LNq16Pseudo_UPD_VST3LNq16_UPD_VST3LNq32Pseudo_UPD_VST3LNq32_UPD
  { 1, 228, 234, 2646, 2652 }, // 587 VST4LNd16_VST4LNd16Pseudo_VST4LNd32_VST4LNd32Pseudo_VST4LNd8_VST4LNd8Pseudo_VST4LNq16_VST4LNq16Pseudo_VST4LNq32_VST4LNq32Pseudo
  { 1, 228, 234, 2652, 2660 }, // 588 VST4LNd16Pseudo_UPD_VST4LNd16_UPD_VST4LNd32Pseudo_UPD_VST4LNd32_UPD_VST4LNd8Pseudo_UPD_VST4LNd8_UPD_VST4LNq16Pseudo_UPD_VST4LNq16_UPD_VST4LNq32Pseudo_UPD_VST4LNq32_UPD
  { 1, 113, 118, 2660, 2663 }, // 589 VDIVS
  { 1, 217, 222, 2663, 2665 }, // 590 VSQRTS
  { 1, 108, 113, 2665, 2668 }, // 591 VDIVD
  { 1, 212, 217, 2668, 2670 }, // 592 VSQRTD
  { 0, 0, 0, 0, 0 }, // 593 ABS
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

static const llvm::InstrItinerary CortexA8Itineraries[] = {
  { 0, 0, 0, 0, 0 }, // 0 NoInstrModel
  { 1, 265, 266, 2670, 2672 }, // 1 IIC_iALUi_WriteALU_ReadALU
  { 1, 265, 266, 2672, 2675 }, // 2 IIC_iALUr_WriteALU_ReadALU_ReadALU
  { 1, 265, 266, 2675, 2679 }, // 3 IIC_iALUsr_WriteALUsi_ReadALU
  { 1, 265, 266, 2679, 2683 }, // 4 IIC_iALUsr_WriteALUsr_ReadALUsr
  { 1, 265, 266, 2683, 2687 }, // 5 IIC_iALUsr_WriteALUSsr_ReadALUsr
  { 1, 265, 266, 2687, 2689 }, // 6 IIC_iBITi_WriteALU_ReadALU
  { 1, 265, 266, 2689, 2692 }, // 7 IIC_iBITr_WriteALU_ReadALU_ReadALU
  { 1, 265, 266, 2692, 2696 }, // 8 IIC_iBITsr_WriteALUsi_ReadALU
  { 1, 265, 266, 2696, 2700 }, // 9 IIC_iBITsr_WriteALUsr_ReadALUsr
  { 1, 265, 266, 0, 0 }, // 10 IIC_Br_WriteBr
  { 1, 265, 266, 2700, 2702 }, // 11 IIC_iUNAsi
  { 1, 265, 266, 0, 0 }, // 12 IIC_Br_WriteBrL
  { 0, 0, 0, 0, 0 }, // 13 WriteBrL
  { 1, 265, 266, 0, 0 }, // 14 IIC_Br_WriteBrTbl
  { 0, 0, 0, 0, 0 }, // 15 WriteBr
  { 1, 265, 266, 2702, 2704 }, // 16 IIC_iUNAr_WriteALU
  { 1, 265, 266, 2704, 2705 }, // 17 IIC_iCMPi_WriteCMP_ReadALU
  { 1, 265, 266, 2705, 2707 }, // 18 IIC_iCMPr_WriteCMP_ReadALU_ReadALU
  { 1, 265, 266, 2707, 2710 }, // 19 IIC_iCMPsr_WriteCMPsi_ReadALU
  { 1, 265, 266, 2710, 2713 }, // 20 IIC_iCMPsr_WriteCMPsr_ReadALU
  { 1, 266, 269, 2713, 2715 }, // 21 IIC_fpUNA64
  { 1, 269, 271, 2715, 2717 }, // 22 IIC_fpUNA32
  { 1, 271, 273, 2717, 2718 }, // 23 IIC_fpSTAT
  { -1, 273, 275, 2718, 2723 }, // 24 IIC_iLoad_m
  { -1, 275, 277, 2723, 2728 }, // 25 IIC_iLoad_mu
  { -1, 277, 280, 2728, 2733 }, // 26 IIC_iLoad_mBr
  { 1, 280, 282, 2733, 2737 }, // 27 IIC_iLoad_bh_ru
  { 1, 280, 282, 2737, 2740 }, // 28 IIC_iLoad_bh_iu
  { 1, 280, 282, 2740, 2743 }, // 29 IIC_iLoad_bh_r
  { 1, 282, 284, 2743, 2746 }, // 30 IIC_iLoad_bh_si
  { 1, 280, 282, 2746, 2749 }, // 31 IIC_iLoad_d_r
  { 1, 280, 282, 2749, 2753 }, // 32 IIC_iLoad_d_ru
  { 1, 280, 282, 2753, 2755 }, // 33 IIC_iLoad_i
  { 1, 284, 287, 2755, 2757 }, // 34 IIC_iLoadiALU
  { 1, 280, 282, 2757, 2761 }, // 35 IIC_iLoad_ru
  { 1, 280, 282, 2761, 2764 }, // 36 IIC_iLoad_iu
  { 1, 280, 282, 2764, 2767 }, // 37 IIC_iLoad_r
  { 1, 282, 284, 2767, 2770 }, // 38 IIC_iLoad_si
  { 1, 287, 288, 2770, 2774 }, // 39 IIC_iMAC32
  { 1, 265, 266, 2774, 2775 }, // 40 IIC_iCMOVi_WriteALU
  { 1, 265, 266, 2775, 2776 }, // 41 IIC_iMOVi_WriteALU
  { 1, 288, 290, 2776, 2778 }, // 42 IIC_iCMOVix2
  { 1, 265, 266, 2778, 2780 }, // 43 IIC_iCMOVr_WriteALU
  { 1, 265, 266, 2780, 2783 }, // 44 IIC_iCMOVsr_WriteALU
  { 1, 290, 293, 2783, 2784 }, // 45 IIC_iMOVix2addpc
  { 1, 293, 296, 2784, 2785 }, // 46 IIC_iMOVix2ld
  { 1, 288, 290, 2785, 2786 }, // 47 IIC_iMOVix2
  { 1, 265, 266, 2786, 2788 }, // 48 IIC_iMOVr_WriteALU
  { 1, 265, 266, 2788, 2791 }, // 49 IIC_iMOVsr_WriteALU
  { 1, 265, 266, 2791, 2793 }, // 50 IIC_iMOVsi_WriteALU
  { 1, 287, 288, 2793, 2796 }, // 51 IIC_iMUL32
  { 1, 265, 266, 2796, 2797 }, // 52 IIC_iMVNi_WriteALU
  { 1, 265, 266, 2797, 2799 }, // 53 IIC_iMVNr_WriteALU
  { 1, 265, 266, 2799, 2802 }, // 54 IIC_iMVNsr_WriteALU
  { 1, 265, 266, 2802, 2805 }, // 55 IIC_iALUr_WriteALU_ReadALU
  { 1, 280, 282, 2805, 2808 }, // 56 IIC_iStore_r
  { 1, 280, 282, 2808, 2811 }, // 57 IIC_iStore_bh_r
  { 1, 265, 266, 2811, 2814 }, // 58 IIC_iALUsi_WriteALUsi_ReadALU
  { 1, 265, 266, 2814, 2817 }, // 59 IIC_iBITsi_WriteALUsi_ReadALU
  { 1, 265, 266, 2817, 2819 }, // 60 IIC_Preload_WritePreLd
  { 0, 0, 0, 0, 0 }, // 61 IIC_iDIV
  { 1, 287, 288, 2819, 2823 }, // 62 IIC_iMAC16
  { 1, 296, 297, 2823, 2827 }, // 63 IIC_iMAC64
  { 1, 297, 298, 2827, 2830 }, // 64 IIC_iMUL16
  { 1, 296, 297, 2830, 2834 }, // 65 IIC_iMUL64
  { -1, 273, 275, 0, 0 }, // 66 IIC_iStore_m
  { -1, 273, 275, 2834, 2835 }, // 67 IIC_iStore_mu
  { 1, 280, 282, 2835, 2839 }, // 68 IIC_iStore_bh_ru
  { 1, 280, 282, 2839, 2842 }, // 69 IIC_iStore_bh_iu
  { 1, 280, 282, 2842, 2846 }, // 70 IIC_iStore_ru
  { 1, 298, 300, 2846, 2849 }, // 71 IIC_iStore_bh_si
  { 1, 280, 282, 2849, 2852 }, // 72 IIC_iStore_d_r
  { 1, 280, 282, 2852, 2856 }, // 73 IIC_iStore_d_ru
  { 1, 280, 282, 2856, 2859 }, // 74 IIC_iStore_iu
  { 1, 298, 300, 2859, 2862 }, // 75 IIC_iStore_si
  { 1, 265, 266, 0, 0 }, // 76 IIC_Br
  { 1, 265, 266, 2862, 2865 }, // 77 IIC_iEXTAr_WriteALUsr
  { 1, 265, 266, 2865, 2867 }, // 78 IIC_iEXTr_WriteALUsi
  { 1, 265, 266, 2867, 2868 }, // 79 IIC_iTSTi_WriteCMP_ReadALU
  { 1, 265, 266, 2868, 2870 }, // 80 IIC_iTSTr_WriteCMP_ReadALU_ReadALU
  { 1, 265, 266, 2870, 2873 }, // 81 IIC_iTSTsr_WriteCMPsi_ReadALU
  { 1, 265, 266, 2873, 2876 }, // 82 IIC_iTSTsr_WriteCMPsr_ReadALU
  { 0, 0, 0, 0, 0 }, // 83 WriteALU_ReadALU_ReadALU
  { 1, 269, 271, 2876, 2880 }, // 84 IIC_VABAD
  { 1, 300, 302, 2880, 2884 }, // 85 IIC_VABAQ
  { 1, 269, 271, 2884, 2887 }, // 86 IIC_VSUBi4Q
  { 1, 269, 271, 2887, 2890 }, // 87 IIC_VBIND
  { 1, 300, 302, 2890, 2893 }, // 88 IIC_VBINQ
  { 1, 269, 271, 2893, 2896 }, // 89 IIC_VSUBi4D
  { 1, 269, 271, 2896, 2898 }, // 90 IIC_VUNAD
  { 1, 300, 302, 2898, 2900 }, // 91 IIC_VUNAQ
  { 1, 269, 271, 2900, 2902 }, // 92 IIC_VUNAiQ
  { 1, 269, 271, 2902, 2904 }, // 93 IIC_VUNAiD
  { 1, 302, 305, 2904, 2907 }, // 94 IIC_fpALU64
  { 1, 269, 271, 2907, 2910 }, // 95 IIC_VBINi4D
  { 1, 269, 271, 2910, 2913 }, // 96 IIC_VSHLiD
  { 1, 269, 271, 2913, 2916 }, // 97 IIC_fpALU32
  { 1, 269, 271, 2916, 2919 }, // 98 IIC_VSUBiD
  { 1, 269, 271, 2919, 2922 }, // 99 IIC_VBINiQ
  { 1, 269, 271, 2922, 2925 }, // 100 IIC_VBINiD
  { 1, 269, 271, 2925, 2926 }, // 101 IIC_VMOVImm
  { 1, 269, 271, 2926, 2929 }, // 102 IIC_VCNTiD
  { 1, 300, 302, 2929, 2932 }, // 103 IIC_VCNTiQ
  { 1, 266, 269, 2932, 2934 }, // 104 IIC_fpCMP64
  { 1, 269, 271, 2934, 2936 }, // 105 IIC_fpCMP32
  { 0, 0, 0, 0, 0 }, // 106 IIC_fpCVTSH
  { 0, 0, 0, 0, 0 }, // 107 IIC_fpCVTHS
  { 1, 305, 308, 2936, 2938 }, // 108 IIC_fpCVTDS
  { 1, 308, 311, 2938, 2940 }, // 109 IIC_fpCVTSD
  { 1, 311, 314, 2940, 2943 }, // 110 IIC_fpDIV64
  { 1, 314, 317, 2943, 2946 }, // 111 IIC_fpDIV32
  { 1, 271, 273, 2946, 2948 }, // 112 IIC_VMOVIS
  { 1, 271, 273, 2948, 2950 }, // 113 IIC_VMOVD
  { 1, 317, 319, 2950, 2952 }, // 114 IIC_VMOVQ
  { 1, 271, 273, 2952, 2955 }, // 115 IIC_VEXTD
  { 1, 317, 319, 2955, 2958 }, // 116 IIC_VEXTQ
  { 1, 319, 322, 2958, 2962 }, // 117 IIC_fpFMAC64
  { 1, 269, 271, 2962, 2966 }, // 118 IIC_fpFMAC32
  { 1, 269, 271, 2966, 2970 }, // 119 IIC_VFMACD
  { 1, 300, 302, 2970, 2974 }, // 120 IIC_VFMACQ
  { 1, 271, 273, 2974, 2976 }, // 121 IIC_VMOVSI
  { 1, 269, 271, 2976, 2979 }, // 122 IIC_VBINi4Q
  { 1, 322, 325, 2979, 2981 }, // 123 IIC_VLD1dup
  { 1, 322, 325, 2981, 2985 }, // 124 IIC_VLD1dupu
  { 1, 325, 328, 2985, 2989 }, // 125 IIC_VLD1ln
  { 1, 325, 328, 2989, 2995 }, // 126 IIC_VLD1lnu
  { 1, 328, 331, 2995, 2997 }, // 127 IIC_VLD1
  { 1, 331, 334, 2997, 3002 }, // 128 IIC_VLD1x4
  { 1, 328, 331, 3002, 3006 }, // 129 IIC_VLD1x2u
  { 1, 331, 334, 3006, 3010 }, // 130 IIC_VLD1x3
  { 1, 328, 331, 3010, 3013 }, // 131 IIC_VLD1u
  { 1, 328, 331, 3013, 3016 }, // 132 IIC_VLD1x2
  { 1, 322, 325, 3016, 3019 }, // 133 IIC_VLD2dup
  { 1, 322, 325, 3019, 3024 }, // 134 IIC_VLD2dupu
  { 1, 331, 334, 3024, 3030 }, // 135 IIC_VLD2ln
  { 1, 331, 334, 3030, 3038 }, // 136 IIC_VLD2lnu
  { 1, 328, 331, 3038, 3041 }, // 137 IIC_VLD2
  { 1, 328, 331, 3041, 3047 }, // 138 IIC_VLD2u
  { 1, 331, 334, 3047, 3052 }, // 139 IIC_VLD2x2
  { 1, 331, 334, 3052, 3058 }, // 140 IIC_VLD2x2u
  { 1, 325, 328, 3058, 3062 }, // 141 IIC_VLD3dup
  { 1, 325, 328, 3062, 3068 }, // 142 IIC_VLD3dupu
  { 1, 334, 337, 3068, 3076 }, // 143 IIC_VLD3ln
  { 1, 334, 337, 3076, 3086 }, // 144 IIC_VLD3lnu
  { 1, 337, 340, 3086, 3090 }, // 145 IIC_VLD3
  { 1, 337, 340, 3090, 3095 }, // 146 IIC_VLD3u
  { 1, 325, 328, 3095, 3100 }, // 147 IIC_VLD4dup
  { 1, 325, 328, 3100, 3107 }, // 148 IIC_VLD4dupu
  { 1, 334, 337, 3107, 3117 }, // 149 IIC_VLD4ln
  { 1, 334, 337, 3117, 3129 }, // 150 IIC_VLD4lnu
  { 1, 337, 340, 3129, 3134 }, // 151 IIC_VLD4
  { 1, 337, 340, 3134, 3140 }, // 152 IIC_VLD4u
  { -1, 340, 345, 3140, 3145 }, // 153 IIC_fpLoad_mu
  { -1, 340, 345, 3145, 3149 }, // 154 IIC_fpLoad_m
  { 1, 345, 348, 3149, 3151 }, // 155 IIC_fpLoad64
  { 1, 345, 348, 3151, 3153 }, // 156 IIC_fpLoad32
  { 1, 319, 322, 3153, 3157 }, // 157 IIC_fpMAC64
  { 1, 300, 302, 3157, 3161 }, // 158 IIC_VMACi32D
  { 1, 269, 271, 3161, 3165 }, // 159 IIC_VMACi16D
  { 1, 269, 271, 3165, 3169 }, // 160 IIC_fpMAC32
  { 1, 269, 271, 3169, 3173 }, // 161 IIC_VMACD
  { 1, 300, 302, 3173, 3177 }, // 162 IIC_VMACQ
  { 1, 348, 352, 3177, 3181 }, // 163 IIC_VMACi32Q
  { 1, 300, 302, 3181, 3185 }, // 164 IIC_VMACi16Q
  { 1, 269, 271, 3185, 3188 }, // 165 IIC_fpMOVID
  { 1, 269, 271, 3188, 3190 }, // 166 IIC_VQUNAiD
  { 1, 269, 271, 3190, 3192 }, // 167 IIC_VMOVN
  { 1, 269, 271, 3192, 3195 }, // 168 IIC_fpMOVDI
  { 1, 269, 271, 3195, 3197 }, // 169 IIC_fpMOVSI
  { 1, 269, 271, 3197, 3199 }, // 170 IIC_fpMOVIS
  { 1, 352, 355, 3199, 3202 }, // 171 IIC_fpMUL64
  { 1, 269, 271, 3202, 3205 }, // 172 IIC_VMULi16D
  { 1, 300, 302, 3205, 3208 }, // 173 IIC_VMULi32D
  { 1, 269, 271, 3208, 3211 }, // 174 IIC_fpMUL32
  { 1, 269, 271, 3211, 3214 }, // 175 IIC_VFMULD
  { 1, 269, 271, 3214, 3217 }, // 176 IIC_VFMULQ
  { 1, 300, 302, 3217, 3220 }, // 177 IIC_VMULi16Q
  { 1, 348, 352, 3220, 3223 }, // 178 IIC_VMULi32Q
  { 1, 300, 302, 3223, 3226 }, // 179 IIC_VSHLiQ
  { 1, 300, 302, 3226, 3229 }, // 180 IIC_VPALiQ
  { 1, 269, 271, 3229, 3232 }, // 181 IIC_VPALiD
  { 1, 269, 271, 3232, 3235 }, // 182 IIC_VPBIND
  { 1, 269, 271, 3235, 3237 }, // 183 IIC_VQUNAiQ
  { 1, 300, 302, 3237, 3240 }, // 184 IIC_VSHLi4Q
  { 1, 269, 271, 3240, 3243 }, // 185 IIC_VSHLi4D
  { 1, 269, 271, 3243, 3246 }, // 186 IIC_VRECSD
  { 1, 300, 302, 3246, 3249 }, // 187 IIC_VRECSQ
  { 1, 317, 319, 3249, 3252 }, // 188 IIC_VMOVISL
  { 1, 355, 358, 3252, 3254 }, // 189 IIC_fpCVTID_WriteCvtFP
  { 1, 269, 271, 3254, 3256 }, // 190 IIC_fpCVTIS_WriteCvtFP
  { 1, 355, 358, 3256, 3258 }, // 191 IIC_fpCVTID
  { 1, 269, 271, 3258, 3260 }, // 192 IIC_fpCVTIS
  { 1, 311, 314, 3260, 3262 }, // 193 IIC_fpSQRT64
  { 1, 319, 322, 3262, 3264 }, // 194 IIC_fpSQRT32
  { 1, 322, 325, 3264, 3267 }, // 195 IIC_VST1ln
  { 1, 322, 325, 3267, 3272 }, // 196 IIC_VST1lnu
  { 1, 328, 331, 3272, 3275 }, // 197 IIC_VST1
  { 1, 331, 334, 3275, 3281 }, // 198 IIC_VST1x4
  { 1, 331, 334, 3281, 3287 }, // 199 IIC_VLD1x4u
  { 1, 331, 334, 3287, 3292 }, // 200 IIC_VST1x3
  { 1, 331, 334, 3292, 3297 }, // 201 IIC_VLD1x3u
  { 1, 331, 334, 3297, 3305 }, // 202 IIC_VST1x4u
  { 1, 331, 334, 3305, 3312 }, // 203 IIC_VST1x3u
  { 1, 328, 331, 3312, 3316 }, // 204 IIC_VST1x2
  { 1, 328, 331, 3316, 3320 }, // 205 IIC_VST2ln
  { 1, 328, 331, 3320, 3326 }, // 206 IIC_VST2lnu
  { 1, 328, 331, 3326, 3330 }, // 207 IIC_VST2
  { 1, 337, 340, 3330, 3336 }, // 208 IIC_VST2x2
  { 1, 337, 340, 3336, 3344 }, // 209 IIC_VST2x2u
  { 1, 331, 334, 3344, 3349 }, // 210 IIC_VST3ln
  { 1, 331, 334, 3349, 3356 }, // 211 IIC_VST3lnu
  { 1, 331, 334, 3356, 3361 }, // 212 IIC_VST3
  { 1, 331, 334, 3361, 3368 }, // 213 IIC_VST3u
  { 1, 337, 340, 3368, 3374 }, // 214 IIC_VST4ln
  { 1, 337, 340, 3374, 3382 }, // 215 IIC_VST4lnu
  { 1, 337, 340, 3382, 3388 }, // 216 IIC_VST4
  { 1, 337, 340, 3388, 3396 }, // 217 IIC_VST4u
  { -1, 340, 345, 3396, 3401 }, // 218 IIC_fpStore_mu
  { -1, 340, 345, 3401, 3405 }, // 219 IIC_fpStore_m
  { 1, 345, 348, 3405, 3407 }, // 220 IIC_fpStore64
  { 1, 345, 348, 3407, 3409 }, // 221 IIC_fpStore32
  { 1, 269, 271, 3409, 3412 }, // 222 IIC_VSUBiQ
  { 1, 317, 319, 3412, 3415 }, // 223 IIC_VTB1
  { 1, 317, 319, 3415, 3419 }, // 224 IIC_VTB2
  { 1, 358, 362, 3419, 3424 }, // 225 IIC_VTB3
  { 1, 358, 362, 3424, 3430 }, // 226 IIC_VTB4
  { 1, 317, 319, 3430, 3434 }, // 227 IIC_VTBX1
  { 1, 317, 319, 3434, 3439 }, // 228 IIC_VTBX2
  { 1, 358, 362, 3439, 3445 }, // 229 IIC_VTBX3
  { 1, 358, 362, 3445, 3452 }, // 230 IIC_VTBX4
  { 1, 355, 358, 3452, 3454 }, // 231 IIC_fpCVTDI_WriteCvtFP
  { 1, 269, 271, 3454, 3456 }, // 232 IIC_fpCVTSI_WriteCvtFP
  { 1, 355, 358, 3456, 3458 }, // 233 IIC_fpCVTDI
  { 1, 269, 271, 3458, 3460 }, // 234 IIC_fpCVTSI
  { 1, 271, 273, 3460, 3464 }, // 235 IIC_VPERMD
  { 1, 317, 319, 3464, 3468 }, // 236 IIC_VPERMQ
  { 1, 358, 362, 3468, 3472 }, // 237 IIC_VPERMQ3
  { 1, 265, 266, 3472, 3475 }, // 238 IIC_iALUsi_WriteALUsi_ReadALUsr
  { 1, 265, 266, 3475, 3477 }, // 239 IIC_iBITi
  { 1, 265, 266, 3477, 3479 }, // 240 IIC_iCMPsi_WriteCMPsi_ReadALU_ReadALU
  { 1, 265, 266, 3479, 3480 }, // 241 IIC_iCMPi_WriteCMP
  { 1, 265, 266, 3480, 3482 }, // 242 IIC_iCMPr_WriteCMP
  { 1, 265, 266, 3482, 3484 }, // 243 IIC_iCMPsi_WriteCMPsi
  { 1, 265, 266, 0, 0 }, // 244 IIC_iALUx
  { 1, 280, 282, 3484, 3486 }, // 245 IIC_iLoad_bh_i
  { 1, 280, 282, 3486, 3488 }, // 246 IIC_iLoad_d_i
  { 1, 265, 266, 3488, 3490 }, // 247 IIC_iCMOVsi_WriteALU
  { 1, 265, 266, 3490, 3491 }, // 248 IIC_iMOVi
  { 1, 265, 266, 3491, 3493 }, // 249 IIC_iMVNsi_WriteALU
  { 1, 265, 266, 3493, 3496 }, // 250 IIC_iALUsir_WriteALUsi_ReadALU
  { 1, 280, 282, 3496, 3498 }, // 251 IIC_iStore_bh_i
  { 1, 280, 282, 3498, 3500 }, // 252 IIC_iStore_i
  { 1, 265, 266, 3500, 3504 }, // 253 IIC_iEXTAsr
  { 1, 265, 266, 3504, 3506 }, // 254 IIC_iEXTr
  { 1, 265, 266, 3506, 3507 }, // 255 IIC_iTSTi_WriteCMP
  { 1, 265, 266, 3507, 3509 }, // 256 IIC_iTSTr_WriteCMP
  { 1, 265, 266, 3509, 3511 }, // 257 IIC_iTSTsi_WriteCMPsi
  { 1, 265, 266, 3511, 3514 }, // 258 IIC_iALUr_WriteALU
  { 1, 265, 266, 3514, 3516 }, // 259 IIC_iALUi_WriteALU
  { 1, 265, 266, 3516, 3519 }, // 260 IIC_iBITr_WriteALU
  { -1, 275, 277, 3519, 3522 }, // 261 IIC_iPop
  { -1, 277, 280, 3522, 3525 }, // 262 IIC_iPop_Br_WriteBrL
  { 1, 265, 266, 3525, 3527 }, // 263 IIC_iTSTr_WriteALU
  { 1, 265, 266, 3527, 3529 }, // 264 ANDri_BICri_EORri_ORRri
  { 1, 265, 266, 3529, 3532 }, // 265 ANDrr_BICrr_EORrr_ORRrr
  { 1, 265, 266, 3532, 3536 }, // 266 ANDrsi_BICrsi_EORrsi_ORRrsi
  { 1, 265, 266, 3536, 3540 }, // 267 ANDrsr_BICrsr_EORrsr_ORRrsr
  { 1, 265, 266, 3540, 3543 }, // 268 MOVCCsi_MOVCCsr
  { 1, 265, 266, 3543, 3546 }, // 269 MOVsi_MOVsr
  { 1, 265, 266, 3546, 3548 }, // 270 MOVsra_flag_MOVsrl_flag
  { 1, 265, 266, 3548, 3551 }, // 271 MVNsr
  { 1, 265, 266, 3551, 3553 }, // 272 MVNr
  { 1, 288, 290, 3553, 3555 }, // 273 MOVCCi32imm
  { 1, 288, 290, 3555, 3556 }, // 274 MOVi32imm
  { 1, 290, 293, 3556, 3557 }, // 275 MOV_ga_pcrel
  { 1, 293, 296, 3557, 3558 }, // 276 MOV_ga_pcrel_ldr
  { 0, 0, 0, 0, 0 }, // 277 SEL
  { 1, 265, 266, 3558, 3560 }, // 278 BFC_BFI_SBFX_UBFX
  { 1, 287, 288, 3560, 3564 }, // 279 MLA_MLAv5_MLS_SMMLA_SMMLAR_SMMLS_SMMLSR
  { 1, 287, 288, 3564, 3567 }, // 280 MUL_MULv5_SMMUL_SMMULR
  { 1, 296, 297, 3567, 3571 }, // 281 SMLAL_SMLALBB_SMLALBT_SMLALTB_SMLALTT_SMLALv5_UMAAL_UMLAL_UMLALv5
  { 1, 296, 297, 3571, 3575 }, // 282 SMULL_SMULLv5_UMULL_UMULLv5
  { 0, 0, 0, 0, 0 }, // 283 SMLAD_SMLADX_SMLALD_SMLALDX_SMLSD_SMLSDX_SMLSLD_SMLSLDX_SMUAD_SMUADX_SMUSD_SMUSDX
  { 1, 297, 298, 3575, 3578 }, // 284 SMULBB_SMULBT_SMULTB_SMULTT_SMULWB_SMULWT
  { 1, 287, 288, 3578, 3582 }, // 285 SMLABB_SMLABT_SMLATB_SMLATT_SMLAWB_SMLAWT
  { 1, 280, 282, 3582, 3585 }, // 286 LDRi12_PICLDR
  { 1, 282, 284, 3585, 3588 }, // 287 LDRrs
  { 1, 280, 282, 3588, 3591 }, // 288 LDRBi12_LDRH_LDRSB_LDRSH_PICLDRB_PICLDRH_PICLDRSB_PICLDRSH
  { 1, 280, 282, 3591, 3595 }, // 289 LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE_LDRSBTi_LDRSBTr_LDRSB_POST_LDRSB_PRE_LDRSHTi_LDRSHTr_LDRSH_POST_LDRSH_PRE
  { 1, 265, 266, 3595, 3597 }, // 290 SXTB_SXTB16_SXTH_UXTB_UXTB16_UXTH
  { 1, 265, 266, 3597, 3599 }, // 291 t2SXTB_t2SXTB16_t2SXTH_t2UXTB_t2UXTB16_t2UXTH
  { 1, 288, 290, 3599, 3601 }, // 292 t2MOVCCi32imm
  { 1, 288, 290, 3601, 3602 }, // 293 t2MOVi32imm
  { 1, 290, 293, 3602, 3603 }, // 294 t2MOV_ga_pcrel
  { 1, 265, 266, 3603, 3604 }, // 295 t2MOVi16_ga_pcrel
  { 0, 0, 0, 0, 0 }, // 296 t2SEL
  { 1, 265, 266, 3604, 3606 }, // 297 t2BFC_t2SBFX_t2UBFX
  { 1, 265, 266, 3606, 3608 }, // 298 t2BFI
  { 1, 265, 266, 3608, 3611 }, // 299 QADD_QADD16_QADD8_QASX_QDADD_QDSUB_QSAX_QSUB_QSUB16_QSUB8_UQADD16_UQADD8_UQASX_UQSAX_UQSUB16_UQSUB8
  { 0, 0, 0, 0, 0 }, // 300 SSAT_SSAT16_USAT_USAT16_t2QADD_t2QADD16_t2QADD8_t2QASX_t2QDADD_t2QDSUB_t2QSAX_t2QSUB_t2QSUB16_t2QSUB8_t2SSAT_t2SSAT16_t2UQADD16_t2UQADD8_t2UQASX_t2UQSAX_t2UQSUB16_t2UQSUB8_t2USAT_t2USAT16
  { 1, 265, 266, 3611, 3614 }, // 301 SADD16_SADD8_SASX_SSAX_SSUB16_SSUB8_UADD16_UADD8_UASX_USAX_USUB16_USUB8
  { 0, 0, 0, 0, 0 }, // 302 t2SADD16_t2SADD8_t2SASX_t2SSAX_t2SSUB16_t2SSUB8_t2UADD16_t2UADD8_t2UASX_t2USAX_t2USUB16_t2USUB8
  { 1, 265, 266, 3614, 3617 }, // 303 SHADD16_SHADD8_SHASX_SHSAX_SHSUB16_SHSUB8_UHADD16_UHADD8_UHASX_UHSAX_UHSUB16_UHSUB8
  { 1, 265, 266, 3617, 3620 }, // 304 SXTAB_SXTAB16_SXTAH_UXTAB_UXTAB16_UXTAH
  { 0, 0, 0, 0, 0 }, // 305 t2SHADD16_t2SHADD8_t2SHASX_t2SHSAX_t2SHSUB16_t2SHSUB8_t2UHADD16_t2UHADD8_t2UHASX_t2UHSAX_t2UHSUB16_t2UHSUB8
  { 1, 265, 266, 3620, 3624 }, // 306 t2SXTAB_t2SXTAB16_t2SXTAH_t2UXTAB_t2UXTAB16_t2UXTAH
  { 0, 0, 0, 0, 0 }, // 307 USAD8
  { 0, 0, 0, 0, 0 }, // 308 USADA8
  { 0, 0, 0, 0, 0 }, // 309 SMUSD_SMUSDX
  { 1, 287, 288, 3624, 3627 }, // 310 t2MUL_t2SMMUL_t2SMMULR
  { 1, 297, 298, 3627, 3630 }, // 311 t2SMULBB_t2SMULBT_t2SMULTB_t2SMULTT_t2SMULWB_t2SMULWT
  { 1, 287, 288, 3630, 3634 }, // 312 t2SMUSD_t2SMUSDX
  { 1, 287, 288, 3634, 3638 }, // 313 t2MLA_t2MLS_t2SMMLA_t2SMMLAR_t2SMMLS_t2SMMLSR
  { 0, 0, 0, 0, 0 }, // 314 SMUAD_SMUADX
  { 1, 287, 288, 3638, 3642 }, // 315 t2SMUAD_t2SMUADX
  { 0, 0, 0, 0, 0 }, // 316 SMLSD_SMLSDX
  { 1, 287, 288, 3642, 3646 }, // 317 t2SMLABB_t2SMLABT_t2SMLATB_t2SMLATT_t2SMLAWB_t2SMLAWT
  { 1, 287, 288, 3646, 3650 }, // 318 t2SMLSD_t2SMLSDX
  { 0, 0, 0, 0, 0 }, // 319 SMLAD_SMLADX
  { 1, 287, 288, 3650, 3654 }, // 320 t2SMLAD_t2SMLADX
  { 1, 296, 297, 3654, 3658 }, // 321 SMULL_UMULL
  { 1, 296, 297, 3658, 3662 }, // 322 t2SMULL_t2UMULL
  { 1, 296, 297, 3662, 3666 }, // 323 t2SMLAL_t2SMLALBB_t2SMLALBT_t2SMLALD_t2SMLALDX_t2SMLALTB_t2SMLALTT_t2SMLSLD_t2SMLSLDX_t2UMAAL_t2UMLAL
  { 0, 0, 0, 0, 0 }, // 324 SDIV_UDIV_t2SDIV_t2UDIV
  { 1, 280, 282, 3666, 3669 }, // 325 LDRBi12
  { 1, 282, 284, 3669, 3672 }, // 326 LDRBrs_t2LDRBs_t2LDRHs
  { 0, 0, 0, 0, 0 }, // 327 LDREX_LDREXB_LDREXD_LDREXH_tLDRpci_pic
  { 1, 280, 282, 3672, 3675 }, // 328 LDRi12
  { 1, 280, 282, 3675, 3677 }, // 329 t2LDRBi12_t2LDRBi8_t2LDRBpci_t2LDRHi12_t2LDRHi8_t2LDRHpci_tLDRBi_tLDRHi
  { 1, 280, 282, 3677, 3679 }, // 330 t2LDRi12_t2LDRi8_t2LDRpci_tLDRi_tLDRpci_tLDRspi
  { 1, 284, 287, 3679, 3681 }, // 331 t2LDRpci_pic
  { 1, 282, 284, 3681, 3684 }, // 332 t2LDRs
  { 1, 280, 282, 3684, 3687 }, // 333 tLDRBr_tLDRHr
  { 1, 280, 282, 3687, 3690 }, // 334 tLDRr
  { 1, 280, 282, 3690, 3693 }, // 335 LDRH_PICLDRB_PICLDRH
  { 1, 280, 282, 3693, 3696 }, // 336 LDRcp
  { 1, 280, 282, 3696, 3698 }, // 337 t2LDRSBi12_t2LDRSBi8_t2LDRSBpci_t2LDRSHi12_t2LDRSHi8_t2LDRSHpci
  { 0, 0, 0, 0, 0 }, // 338 t2LDRSBpcrel_t2LDRSHpcrel
  { 1, 282, 284, 3698, 3701 }, // 339 t2LDRSBs_t2LDRSHs
  { 1, 280, 282, 3701, 3704 }, // 340 tLDRSB_tLDRSH
  { 1, 280, 282, 3704, 3708 }, // 341 LDRBT_POST_IMM_LDRBT_POST_REG_LDRB_POST_REG_LDRB_PRE_REG
  { 1, 280, 282, 3708, 3711 }, // 342 LDRB_POST_IMM_LDRB_PRE_IMM_t2LDRB_POST_t2LDRB_PRE_t2LDRH_POST_t2LDRH_PRE
  { 1, 280, 282, 3711, 3715 }, // 343 LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE
  { 1, 280, 282, 3715, 3719 }, // 344 LDRT_POST_IMM_LDRT_POST_REG_LDR_POST_REG_LDR_PRE_REG
  { 1, 280, 282, 3719, 3722 }, // 345 LDR_POST_IMM_LDR_PRE_IMM_t2LDR_POST_t2LDR_PRE
  { 1, 280, 282, 3722, 3724 }, // 346 t2LDRBT_t2LDRHT
  { 1, 280, 282, 3724, 3726 }, // 347 t2LDRT
  { 1, 280, 282, 3726, 3728 }, // 348 t2LDRSBT_t2LDRSHT
  { 1, 280, 282, 3728, 3731 }, // 349 t2LDRSB_POST_t2LDRSB_PRE_t2LDRSH_POST_t2LDRSH_PRE
  { 1, 280, 282, 3731, 3734 }, // 350 LDRD
  { 1, 280, 282, 3734, 3736 }, // 351 t2LDRDi8
  { 1, 280, 282, 3736, 3740 }, // 352 LDRD_POST_LDRD_PRE_t2LDRD_POST_t2LDRD_PRE
  { -1, 273, 275, 3740, 3745 }, // 353 LDMDA_LDMDB_LDMIA_LDMIB_sysLDMDA_sysLDMDB_sysLDMIA_sysLDMIB_t2LDMDB_t2LDMIA_tLDMIA
  { -1, 275, 277, 3745, 3750 }, // 354 LDMDA_UPD_LDMDB_UPD_LDMIA_UPD_LDMIB_UPD_sysLDMDA_UPD_sysLDMDB_UPD_sysLDMIA_UPD_sysLDMIB_UPD_t2LDMDB_UPD_t2LDMIA_UPD_tLDMIA_UPD
  { -1, 277, 280, 3750, 3755 }, // 355 LDMIA_RET_t2LDMIA_RET
  { -1, 275, 277, 3755, 3758 }, // 356 tPOP
  { -1, 277, 280, 3758, 3761 }, // 357 tPOP_RET
  { 1, 280, 282, 3761, 3764 }, // 358 PICSTR_STRi12_tSTRr
  { 1, 280, 282, 3764, 3767 }, // 359 PICSTRB_PICSTRH_STRBi12_STRH_tSTRBr_tSTRHr
  { 1, 298, 300, 3767, 3770 }, // 360 STRBrs_t2STRBs_t2STRHs
  { 0, 0, 0, 0, 0 }, // 361 STREX_STREXB_STREXD_STREXH
  { 1, 298, 300, 3770, 3773 }, // 362 STRrs_t2STRs
  { 1, 280, 282, 3773, 3775 }, // 363 t2STRBi12_t2STRBi8_t2STRHi12_t2STRHi8_tSTRBi_tSTRHi
  { 1, 280, 282, 3775, 3777 }, // 364 t2STRi12_t2STRi8_tSTRi_tSTRspi
  { 0, 0, 0, 0, 0 }, // 365 STRBT_POST_STRT_POST
  { 1, 280, 282, 3777, 3781 }, // 366 STRBT_POST_IMM_STRBT_POST_REG_STRB_POST_REG_STRB_PRE_REG_STRHTi_STRHTr_STRH_POST_STRH_PRE
  { 1, 280, 282, 3781, 3784 }, // 367 STRB_POST_IMM_STRB_PRE_IMM_t2STRB_POST_t2STRB_PRE_t2STRH_POST
  { 1, 280, 282, 3784, 3788 }, // 368 STRBi_preidx_STRBr_preidx_STRH_preidx_STRT_POST_IMM_STRT_POST_REG_STR_POST_REG_STR_PRE_REG_STRi_preidx_STRr_preidx_t2STRB_preidx_t2STRH_preidx_t2STR_preidx
  { 1, 280, 282, 3788, 3791 }, // 369 STR_POST_IMM_STR_PRE_IMM_t2STRH_PRE_t2STR_POST_t2STR_PRE
  { 1, 280, 282, 3791, 3793 }, // 370 t2STRBT_t2STRHT
  { 1, 280, 282, 3793, 3795 }, // 371 t2STRT
  { 1, 280, 282, 3795, 3798 }, // 372 STRD_t2STRDi8
  { 1, 280, 282, 3798, 3802 }, // 373 STRD_POST_STRD_PRE_t2STRD_POST_t2STRD_PRE
  { -1, 273, 275, 0, 0 }, // 374 STMDA_STMDB_STMIA_STMIB_sysSTMDA_sysSTMDB_sysSTMIA_sysSTMIB_t2STMDB_t2STMIA
  { -1, 273, 275, 3802, 3803 }, // 375 STMDA_UPD_STMDB_UPD_STMIA_UPD_STMIB_UPD_sysSTMDA_UPD_sysSTMDB_UPD_sysSTMIA_UPD_sysSTMIB_UPD_t2STMDB_UPD_t2STMIA_UPD_tSTMIA_UPD
  { -1, 273, 275, 0, 0 }, // 376 tPUSH
  { 1, 280, 282, 3803, 3805 }, // 377 LDRLIT_ga_abs_tLDRLIT_ga_abs
  { 1, 284, 287, 3805, 3807 }, // 378 LDRLIT_ga_pcrel_tLDRLIT_ga_pcrel
  { 0, 0, 0, 0, 0 }, // 379 LDRLIT_ga_pcrel_ldr
  { 0, 0, 0, 0, 0 }, // 380 ITasm
  { 1, 265, 266, 0, 0 }, // 381 t2IT
  { 1, 269, 271, 3807, 3810 }, // 382 VADDLsv2i64_VADDLsv4i32_VADDLsv8i16_VADDLuv2i64_VADDLuv4i32_VADDLuv8i16_VNEGs16d_VNEGs32d_VNEGs8d_VPADDLsv16i8_VPADDLsv2i32_VPADDLsv4i16_VPADDLsv4i32_VPADDLsv8i16_VPADDLsv8i8_VPADDLuv16i8_VPADDLuv2i32_VPADDLuv4i16_VPADDLuv4i32_VPADDLuv8i16_VPADDLuv8i8_VPADDi16_VPADDi32_VPADDi8_VSHLLi16_VSHLLi32_VSHLLi8_VSHLLsv2i64_VSHLLsv4i32_VSHLLsv8i16_VSHLLuv2i64_VSHLLuv4i32_VSHLLuv8i16_VSHLiv16i8_VSHLiv1i64_VSHLiv2i32_VSHLiv2i64_VSHLiv4i16_VSHLiv4i32_VSHLiv8i16_VSHLiv8i8_VSHLsv1i64_VSHLsv2i32_VSHLsv4i16_VSHLsv8i8_VSHLuv1i64_VSHLuv2i32_VSHLuv4i16_VSHLuv8i8_VSHRsv16i8_VSHRsv1i64_VSHRsv2i32_VSHRsv2i64_VSHRsv4i16_VSHRsv4i32_VSHRsv8i16_VSHRsv8i8_VSHRuv16i8_VSHRuv1i64_VSHRuv2i32_VSHRuv2i64_VSHRuv4i16_VSHRuv4i32_VSHRuv8i16_VSHRuv8i8_VSLIv1i64_VSLIv2i32_VSLIv4i16_VSLIv8i8_VSRIv1i64_VSRIv2i32_VSRIv4i16_VSRIv8i8_VSUBLsv2i64_VSUBLsv4i32_VSUBLsv8i16_VSUBLuv2i64_VSUBLuv4i32_VSUBLuv8i16
  { 1, 269, 271, 3810, 3813 }, // 383 VADDWsv2i64_VADDWsv4i32_VADDWsv8i16_VADDWuv2i64_VADDWuv4i32_VADDWuv8i16_VSUBWsv2i64_VSUBWsv4i32_VSUBWsv8i16_VSUBWuv2i64_VSUBWuv4i32_VSUBWuv8i16_VSUBv1i64_VSUBv2i32_VSUBv4i16_VSUBv8i8
  { 1, 269, 271, 3813, 3816 }, // 384 VADDv16i8_VADDv2i64_VADDv4i32_VADDv8i16_VANDq_VBICq_VBIFq_VBITq_VEORq_VORNq_VORRq
  { 1, 269, 271, 3816, 3819 }, // 385 VADDv1i64_VADDv2i32_VADDv4i16_VADDv8i8_VANDd_VBICd_VBIFd_VBITd_VEORd_VORNd_VORRd
  { 1, 269, 271, 3819, 3820 }, // 386 VBICiv2i32_VBICiv4i16_VBICiv4i32_VBICiv8i16_VORRiv2i32_VORRiv4i16_VORRiv4i32_VORRiv8i16
  { 1, 269, 271, 3820, 3823 }, // 387 VBSLd_VCLSv2i32_VCLSv4i16_VCLSv8i8_VCLZv2i32_VCLZv4i16_VCLZv8i8_VCNTd
  { 1, 300, 302, 3823, 3826 }, // 388 VBSLq_VCLSv16i8_VCLSv4i32_VCLSv8i16_VCLZv16i8_VCLZv4i32_VCLZv8i16_VCNTq
  { 1, 269, 271, 3826, 3829 }, // 389 VHADDsv16i8_VHADDsv4i32_VHADDsv8i16_VHADDuv16i8_VHADDuv4i32_VHADDuv8i16_VRHADDsv16i8_VRHADDsv4i32_VRHADDsv8i16_VRHADDuv16i8_VRHADDuv4i32_VRHADDuv8i16_VTSTv16i8_VTSTv4i32_VTSTv8i16
  { 1, 269, 271, 3829, 3832 }, // 390 VHADDsv2i32_VHADDsv4i16_VHADDsv8i8_VHADDuv2i32_VHADDuv4i16_VHADDuv8i8_VRHADDsv2i32_VRHADDsv4i16_VRHADDsv8i8_VRHADDuv2i32_VRHADDuv4i16_VRHADDuv8i8_VTSTv2i32_VTSTv4i16_VTSTv8i8
  { 1, 269, 271, 3832, 3835 }, // 391 VHSUBsv16i8_VHSUBsv4i32_VHSUBsv8i16_VHSUBuv16i8_VHSUBuv4i32_VHSUBuv8i16
  { 1, 269, 271, 3835, 3838 }, // 392 VHSUBsv2i32_VHSUBsv4i16_VHSUBsv8i8_VHSUBuv2i32_VHSUBuv4i16_VHSUBuv8i8
  { 1, 300, 302, 3838, 3840 }, // 393 VNEGf32q
  { 1, 269, 271, 3840, 3842 }, // 394 VNEGfd
  { 1, 300, 302, 3842, 3845 }, // 395 VNEGs16q_VNEGs32q_VNEGs8q_VSHLsv16i8_VSHLsv2i64_VSHLsv4i32_VSHLsv8i16_VSHLuv16i8_VSHLuv2i64_VSHLuv4i32_VSHLuv8i16_VSLIv16i8_VSLIv2i64_VSLIv4i32_VSLIv8i16_VSRIv16i8_VSRIv2i64_VSRIv4i32_VSRIv8i16
  { 1, 269, 271, 3845, 3848 }, // 396 VQSHLsiv16i8_VQSHLsiv1i64_VQSHLsiv2i32_VQSHLsiv2i64_VQSHLsiv4i16_VQSHLsiv4i32_VQSHLsiv8i16_VQSHLsiv8i8_VQSHLsuv16i8_VQSHLsuv1i64_VQSHLsuv2i32_VQSHLsuv2i64_VQSHLsuv4i16_VQSHLsuv4i32_VQSHLsuv8i16_VQSHLsuv8i8_VQSHLsv1i64_VQSHLsv2i32_VQSHLsv4i16_VQSHLsv8i8_VQSHLuiv16i8_VQSHLuiv1i64_VQSHLuiv2i32_VQSHLuiv2i64_VQSHLuiv4i16_VQSHLuiv4i32_VQSHLuiv8i16_VQSHLuiv8i8_VQSHLuv1i64_VQSHLuv2i32_VQSHLuv4i16_VQSHLuv8i8
  { 1, 300, 302, 3848, 3851 }, // 397 VQSHLsv16i8_VQSHLsv2i64_VQSHLsv4i32_VQSHLsv8i16_VQSHLuv16i8_VQSHLuv2i64_VQSHLuv4i32_VQSHLuv8i16
  { 1, 269, 271, 3851, 3854 }, // 398 VSUBv16i8_VSUBv2i64_VSUBv4i32_VSUBv8i16
  { 1, 271, 273, 3854, 3857 }, // 399 VEXTd16_VEXTd32_VEXTd8
  { 1, 317, 319, 3857, 3860 }, // 400 VEXTq16_VEXTq32_VEXTq64_VEXTq8
  { 1, 271, 273, 3860, 3862 }, // 401 VREV16d8_VREV32d16_VREV32d8_VREV64d16_VREV64d32_VREV64d8
  { 1, 317, 319, 3862, 3864 }, // 402 VREV16q8_VREV32q16_VREV32q8_VREV64q16_VREV64q32_VREV64q8
  { 1, 269, 271, 3864, 3868 }, // 403 VABALsv2i64_VABALsv4i32_VABALsv8i16_VABALuv2i64_VABALuv4i32_VABALuv8i16_VABAsv2i32_VABAsv4i16_VABAsv8i8_VABAuv2i32_VABAuv4i16_VABAuv8i8
  { 1, 300, 302, 3868, 3872 }, // 404 VABAsv16i8_VABAsv4i32_VABAsv8i16_VABAuv16i8_VABAuv4i32_VABAuv8i16
  { 1, 269, 271, 3872, 3874 }, // 405 VABSfd
  { 1, 300, 302, 3874, 3876 }, // 406 VABSfq
  { 1, 269, 271, 3876, 3878 }, // 407 VABSv16i8_VABSv4i32_VABSv8i16
  { 1, 269, 271, 3878, 3880 }, // 408 VABSv2i32_VABSv4i16_VABSv8i8
  { 1, 269, 271, 3880, 3883 }, // 409 VACGEd_VACGTd_VCEQfd_VCGEfd_VCGTfd
  { 1, 300, 302, 3883, 3886 }, // 410 VACGEq_VACGTq_VCEQfq_VCGEfq_VCGTfq
  { 1, 269, 271, 3886, 3889 }, // 411 VCEQv16i8_VCEQv4i32_VCEQv8i16_VCGEsv16i8_VCGEsv4i32_VCGEsv8i16_VCGEuv16i8_VCGEuv4i32_VCGEuv8i16_VCGTsv16i8_VCGTsv4i32_VCGTsv8i16_VCGTuv16i8_VCGTuv4i32_VCGTuv8i16_VQSUBsv16i8_VQSUBsv2i64_VQSUBsv4i32_VQSUBsv8i16_VQSUBuv16i8_VQSUBuv2i64_VQSUBuv4i32_VQSUBuv8i16
  { 1, 269, 271, 3889, 3892 }, // 412 VCEQv2i32_VCEQv4i16_VCEQv8i8_VCGEsv2i32_VCGEsv4i16_VCGEsv8i8_VCGEuv2i32_VCGEuv4i16_VCGEuv8i8_VCGTsv2i32_VCGTsv4i16_VCGTsv8i8_VCGTuv2i32_VCGTuv4i16_VCGTuv8i8_VQSUBsv1i64_VQSUBsv2i32_VQSUBsv4i16_VQSUBsv8i8_VQSUBuv1i64_VQSUBuv2i32_VQSUBuv4i16_VQSUBuv8i8
  { 0, 0, 0, 0, 0 }, // 413 VCEQzv16i8_VCEQzv2f32_VCEQzv2i32_VCEQzv4f32_VCEQzv4i16_VCEQzv4i32_VCEQzv8i16_VCEQzv8i8_VCGEzv16i8_VCGEzv2f32_VCGEzv2i32_VCGEzv4f32_VCGEzv4i16_VCGEzv4i32_VCGEzv8i16_VCGEzv8i8_VCGTzv16i8_VCGTzv2f32_VCGTzv2i32_VCGTzv4f32_VCGTzv4i16_VCGTzv4i32_VCGTzv8i16_VCGTzv8i8_VCLEzv16i8_VCLEzv2f32_VCLEzv2i32_VCLEzv4f32_VCLEzv4i16_VCLEzv4i32_VCLEzv8i16_VCLEzv8i8_VCLTzv16i8_VCLTzv2f32_VCLTzv2i32_VCLTzv4f32_VCLTzv4i16_VCLTzv4i32_VCLTzv8i16_VCLTzv8i8
  { 1, 300, 302, 3892, 3895 }, // 414 VPADALsv16i8_VPADALsv4i32_VPADALsv8i16_VPADALuv16i8_VPADALuv4i32_VPADALuv8i16
  { 1, 269, 271, 3895, 3898 }, // 415 VPADALsv2i32_VPADALsv4i16_VPADALsv8i8_VPADALuv2i32_VPADALuv4i16_VPADALuv8i8_VRSRAsv16i8_VRSRAsv1i64_VRSRAsv2i32_VRSRAsv2i64_VRSRAsv4i16_VRSRAsv4i32_VRSRAsv8i16_VRSRAsv8i8_VRSRAuv16i8_VRSRAuv1i64_VRSRAuv2i32_VRSRAuv2i64_VRSRAuv4i16_VRSRAuv4i32_VRSRAuv8i16_VRSRAuv8i8_VSRAsv16i8_VSRAsv1i64_VSRAsv2i32_VSRAsv2i64_VSRAsv4i16_VSRAsv4i32_VSRAsv8i16_VSRAsv8i8_VSRAuv16i8_VSRAuv1i64_VSRAuv2i32_VSRAuv2i64_VSRAuv4i16_VSRAuv4i32_VSRAuv8i16_VSRAuv8i8
  { 1, 269, 271, 3898, 3900 }, // 416 VQABSv16i8_VQABSv4i32_VQABSv8i16_VQNEGv16i8_VQNEGv4i32_VQNEGv8i16
  { 1, 269, 271, 3900, 3902 }, // 417 VQABSv2i32_VQABSv4i16_VQABSv8i8_VQNEGv2i32_VQNEGv4i16_VQNEGv8i8
  { 1, 269, 271, 3902, 3905 }, // 418 VQADDsv16i8_VQADDsv2i64_VQADDsv4i32_VQADDsv8i16_VQADDuv16i8_VQADDuv2i64_VQADDuv4i32_VQADDuv8i16
  { 1, 269, 271, 3905, 3908 }, // 419 VQADDsv1i64_VQADDsv2i32_VQADDsv4i16_VQADDsv8i8_VQADDuv1i64_VQADDuv2i32_VQADDuv4i16_VQADDuv8i8
  { 1, 300, 302, 3908, 3911 }, // 420 VQRSHLsv16i8_VQRSHLsv2i64_VQRSHLsv4i32_VQRSHLsv8i16_VQRSHLuv16i8_VQRSHLuv2i64_VQRSHLuv4i32_VQRSHLuv8i16_VRSHLsv16i8_VRSHLsv2i64_VRSHLsv4i32_VRSHLsv8i16_VRSHLuv16i8_VRSHLuv2i64_VRSHLuv4i32_VRSHLuv8i16
  { 1, 269, 271, 3911, 3914 }, // 421 VQRSHLsv1i64_VQRSHLsv2i32_VQRSHLsv4i16_VQRSHLsv8i8_VQRSHLuv1i64_VQRSHLuv2i32_VQRSHLuv4i16_VQRSHLuv8i8_VRSHLsv1i64_VRSHLsv2i32_VRSHLsv4i16_VRSHLsv8i8_VRSHLuv1i64_VRSHLuv2i32_VRSHLuv4i16_VRSHLuv8i8_VRSHRsv16i8_VRSHRsv1i64_VRSHRsv2i32_VRSHRsv2i64_VRSHRsv4i16_VRSHRsv4i32_VRSHRsv8i16_VRSHRsv8i8_VRSHRuv16i8_VRSHRuv1i64_VRSHRuv2i32_VRSHRuv2i64_VRSHRuv4i16_VRSHRuv4i32_VRSHRuv8i16_VRSHRuv8i8
  { 1, 269, 271, 3914, 3916 }, // 422 VRECPEd_VRECPEfd_VRSQRTEd_VRSQRTEfd
  { 1, 300, 302, 3916, 3918 }, // 423 VRECPEfq_VRECPEq_VRSQRTEfq_VRSQRTEq
  { 1, 269, 271, 3918, 3921 }, // 424 VADDHNv2i32_VADDHNv4i16_VADDHNv8i8_VSUBHNv2i32_VSUBHNv4i16_VSUBHNv8i8
  { 1, 269, 271, 3921, 3924 }, // 425 VSHRNv2i32_VSHRNv4i16_VSHRNv8i8
  { 1, 269, 271, 3924, 3927 }, // 426 VQRSHRNsv2i32_VQRSHRNsv4i16_VQRSHRNsv8i8_VQRSHRNuv2i32_VQRSHRNuv4i16_VQRSHRNuv8i8_VQRSHRUNv2i32_VQRSHRUNv4i16_VQRSHRUNv8i8_VQSHRNsv2i32_VQSHRNsv4i16_VQSHRNsv8i8_VQSHRNuv2i32_VQSHRNuv4i16_VQSHRNuv8i8_VQSHRUNv2i32_VQSHRUNv4i16_VQSHRUNv8i8_VRSHRNv2i32_VRSHRNv4i16_VRSHRNv8i8
  { 1, 269, 271, 3927, 3930 }, // 427 VRADDHNv2i32_VRADDHNv4i16_VRADDHNv8i8_VRSUBHNv2i32_VRSUBHNv4i16_VRSUBHNv8i8
  { 1, 317, 319, 3930, 3933 }, // 428 VTBL1
  { 1, 317, 319, 3933, 3937 }, // 429 VTBX1
  { 1, 317, 319, 3937, 3941 }, // 430 VTBL2
  { 1, 317, 319, 3941, 3946 }, // 431 VTBX2
  { 1, 358, 362, 3946, 3951 }, // 432 VTBL3_VTBL3Pseudo
  { 1, 358, 362, 3951, 3957 }, // 433 VTBX3_VTBX3Pseudo
  { 1, 358, 362, 3957, 3963 }, // 434 VTBL4_VTBL4Pseudo
  { 1, 358, 362, 3963, 3970 }, // 435 VTBX4_VTBX4Pseudo
  { 0, 0, 0, 0, 0 }, // 436 VSWPd_VSWPq
  { 1, 271, 273, 3970, 3974 }, // 437 VTRNd16_VTRNd32_VTRNd8_VUZPd16_VUZPd8_VZIPd16_VZIPd8
  { 1, 317, 319, 3974, 3978 }, // 438 VTRNq16_VTRNq32_VTRNq8
  { 1, 358, 362, 3978, 3982 }, // 439 VUZPq16_VUZPq32_VUZPq8_VZIPq16_VZIPq32_VZIPq8
  { 1, 266, 269, 3982, 3984 }, // 440 VABSD_VNEGD
  { 1, 269, 271, 3984, 3986 }, // 441 VABSS_VNEGS
  { 1, 266, 269, 3986, 3988 }, // 442 VCMPD_VCMPED_VCMPEZD_VCMPZD
  { 1, 269, 271, 3988, 3990 }, // 443 VCMPES_VCMPEZS_VCMPS_VCMPZS
  { 1, 269, 271, 3990, 3993 }, // 444 VABDLsv2i64_VABDLsv4i32_VABDLsv8i16_VABDLuv2i64_VABDLuv4i32_VABDLuv8i16_VABDsv16i8_VABDsv4i32_VABDsv8i16_VABDuv16i8_VABDuv4i32_VABDuv8i16_VMAXsv16i8_VMAXsv4i32_VMAXsv8i16_VMAXuv16i8_VMAXuv4i32_VMAXuv8i16_VMINsv16i8_VMINsv4i32_VMINsv8i16_VMINuv16i8_VMINuv4i32_VMINuv8i16
  { 1, 269, 271, 3993, 3996 }, // 445 VABDfd_VADDfd_VMAXfd_VMINfd_VSUBfd
  { 1, 300, 302, 3996, 3999 }, // 446 VABDfq_VADDfq_VMAXfq_VMINfq_VSUBfq
  { 1, 269, 271, 3999, 4002 }, // 447 VABDsv2i32_VABDsv4i16_VABDsv8i8_VABDuv2i32_VABDuv4i16_VABDuv8i8_VMAXsv2i32_VMAXsv4i16_VMAXsv8i8_VMAXuv2i32_VMAXuv4i16_VMAXuv8i8_VMINsv2i32_VMINsv4i16_VMINsv8i8_VMINuv2i32_VMINuv4i16_VMINuv8i8_VPMAXs16_VPMAXs32_VPMAXs8_VPMAXu16_VPMAXu32_VPMAXu8_VPMINs16_VPMINs32_VPMINs8_VPMINu16_VPMINu32_VPMINu8
  { 1, 269, 271, 4002, 4005 }, // 448 VADDS_VSUBS
  { 0, 0, 0, 0, 0 }, // 449 VMAXNMD_VMAXNMND_VMAXNMNQ_VMAXNMS_VMINNMD_VMINNMND_VMINNMNQ_VMINNMS
  { 1, 269, 271, 4005, 4008 }, // 450 VPADDf_VPMAXf_VPMINf
  { 1, 302, 305, 4008, 4011 }, // 451 VADDD_VSUBD
  { 1, 269, 271, 4011, 4014 }, // 452 VRECPSfd_VRSQRTSfd
  { 1, 300, 302, 4014, 4017 }, // 453 VRECPSfq_VRSQRTSfq
  { 0, 0, 0, 0, 0 }, // 454 VMULLp64
  { 1, 269, 271, 4017, 4020 }, // 455 VMULLp8_VMULLslsv2i32_VMULLslsv4i16_VMULLsluv2i32_VMULLsluv4i16_VMULLsv4i32_VMULLsv8i16_VMULLuv4i32_VMULLuv8i16_VMULpd_VMULslv4i16_VMULv4i16_VMULv8i8_VQDMULHslv4i16_VQDMULHv4i16_VQDMULLslv2i32_VQDMULLslv4i16_VQDMULLv4i32_VQRDMULHslv4i16_VQRDMULHv4i16
  { 1, 300, 302, 4020, 4023 }, // 456 VMULLsv2i64_VMULLuv2i64_VMULslv2i32_VMULv2i32_VQDMULHslv2i32_VQDMULHv2i32_VQDMULLv2i64_VQRDMULHslv2i32_VQRDMULHv2i32
  { 1, 269, 271, 4023, 4026 }, // 457 VMULS_VNMULS
  { 1, 269, 271, 4026, 4029 }, // 458 VMULfd
  { 1, 269, 271, 4029, 4032 }, // 459 VMULfq
  { 1, 300, 302, 4032, 4035 }, // 460 VMULpq_VMULslv8i16_VMULv16i8_VMULv8i16_VQDMULHslv8i16_VQDMULHv8i16_VQRDMULHslv8i16_VQRDMULHv8i16
  { 1, 269, 271, 4035, 4038 }, // 461 VMULslfd
  { 1, 300, 302, 4038, 4041 }, // 462 VMULslfq
  { 1, 348, 352, 4041, 4044 }, // 463 VMULslv4i32_VMULv4i32_VQDMULHslv4i32_VQDMULHv4i32_VQRDMULHslv4i32_VQRDMULHv4i32
  { 1, 352, 355, 4044, 4047 }, // 464 VMULD_VNMULD
  { 1, 319, 322, 4047, 4051 }, // 465 VFMAD_VFMSD_VFNMAD_VFNMSD
  { 1, 269, 271, 4051, 4055 }, // 466 VFMAS_VFMSS_VFNMAS_VFNMSS
  { 1, 319, 322, 4055, 4059 }, // 467 VMLAD_VMLSD_VNMLAD_VNMLSD
  { 1, 300, 302, 4059, 4063 }, // 468 VMLALslsv2i32_VMLALsluv2i32_VMLALsv2i64_VMLALuv2i64_VMLAslv2i32_VMLAv2i32_VMLSLslsv2i32_VMLSLsluv2i32_VMLSLsv2i64_VMLSLuv2i64_VMLSslv2i32_VMLSv2i32_VQDMLALslv2i32_VQDMLALv2i64_VQDMLSLslv2i32_VQDMLSLv2i64
  { 1, 269, 271, 4063, 4067 }, // 469 VMLALslsv4i16_VMLALsluv4i16_VMLALsv4i32_VMLALsv8i16_VMLALuv4i32_VMLALuv8i16_VMLAslv4i16_VMLAv4i16_VMLAv8i8_VMLSLslsv4i16_VMLSLsluv4i16_VMLSLsv4i32_VMLSLsv8i16_VMLSLuv4i32_VMLSLuv8i16_VMLSslv4i16_VMLSv4i16_VMLSv8i8_VQDMLALslv4i16_VQDMLALv4i32_VQDMLSLslv4i16_VQDMLSLv4i32
  { 1, 269, 271, 4067, 4071 }, // 470 VMLAS_VMLSS_VNMLAS_VNMLSS
  { 1, 269, 271, 4071, 4075 }, // 471 VMLAfd_VMLAslfd_VMLSfd_VMLSslfd
  { 1, 300, 302, 4075, 4079 }, // 472 VMLAfq_VMLAslfq_VMLSfq_VMLSslfq
  { 1, 348, 352, 4079, 4083 }, // 473 VMLAslv4i32_VMLAv4i32_VMLSslv4i32_VMLSv4i32
  { 1, 300, 302, 4083, 4087 }, // 474 VMLAslv8i16_VMLAv16i8_VMLAv8i16_VMLSslv8i16_VMLSv16i8_VMLSv8i16
  { 1, 269, 271, 4087, 4091 }, // 475 VFMAfd_VFMSfd
  { 1, 300, 302, 4091, 4095 }, // 476 VFMAfq_VFMSfq
  { 0, 0, 0, 0, 0 }, // 477 VCVTANSD_VCVTANSQ_VCVTANUD_VCVTANUQ_VCVTASD_VCVTASS_VCVTAUD_VCVTAUS_VCVTBDH_VCVTBHD_VCVTMNSD_VCVTMNSQ_VCVTMNUD_VCVTMNUQ_VCVTMSD_VCVTMSS_VCVTMUD_VCVTMUS_VCVTNNSD_VCVTNNSQ_VCVTNNUD_VCVTNNUQ_VCVTNSD_VCVTNSS_VCVTNUD_VCVTNUS_VCVTPNSD_VCVTPNSQ_VCVTPNUD_VCVTPNUQ_VCVTPSD_VCVTPSS_VCVTPUD_VCVTPUS_VCVTTDH_VCVTTHD
  { 0, 0, 0, 0, 0 }, // 478 VCVTBHS_VCVTTHS
  { 0, 0, 0, 0, 0 }, // 479 VCVTBSH_VCVTTSH
  { 1, 305, 308, 4095, 4097 }, // 480 VCVTDS
  { 1, 308, 311, 4097, 4099 }, // 481 VCVTSD
  { 1, 300, 302, 4099, 4101 }, // 482 VCVTf2h_VCVTf2sq_VCVTf2uq_VCVTf2xsq_VCVTf2xuq_VCVTh2f_VCVTs2fq_VCVTu2fq_VCVTxs2fq_VCVTxu2fq
  { 1, 269, 271, 4101, 4103 }, // 483 VCVTf2sd_VCVTf2ud_VCVTf2xsd_VCVTf2xud_VCVTs2fd_VCVTu2fd_VCVTxs2fd_VCVTxu2fd
  { 1, 355, 358, 4103, 4105 }, // 484 VSITOD_VUITOD
  { 1, 269, 271, 4105, 4107 }, // 485 VSITOS_VUITOS
  { 1, 355, 358, 4107, 4109 }, // 486 VTOSHD_VTOSLD_VTOUHD_VTOULD
  { 1, 269, 271, 4109, 4111 }, // 487 VTOSHS_VTOSLS_VTOUHS_VTOULS
  { 1, 355, 358, 4111, 4113 }, // 488 VTOSIRD_VTOSIZD_VTOUIRD_VTOUIZD
  { 1, 269, 271, 4113, 4115 }, // 489 VTOSIRS_VTOSIZS_VTOUIRS_VTOUIZS
  { 1, 266, 269, 4115, 4117 }, // 490 FCONSTD_VMOVD_VMOVDcc
  { 1, 269, 271, 4117, 4119 }, // 491 FCONSTS_VMOVS_VMOVScc
  { 1, 269, 271, 4119, 4120 }, // 492 VMOVv16i8_VMOVv1i64_VMOVv2f32_VMOVv2i32_VMOVv2i64_VMOVv4f32_VMOVv4i16_VMOVv4i32_VMOVv8i16_VMOVv8i8_VMVNv2i32_VMVNv4i16_VMVNv4i32_VMVNv8i16
  { 1, 269, 271, 4120, 4123 }, // 493 VMVNd_VMVNq
  { 1, 269, 271, 4123, 4125 }, // 494 VMOVLsv2i64_VMOVLsv4i32_VMOVLsv8i16_VMOVLuv2i64_VMOVLuv4i32_VMOVLuv8i16
  { 1, 269, 271, 4125, 4127 }, // 495 VMOVNv2i32_VMOVNv4i16_VMOVNv8i8
  { 1, 269, 271, 4127, 4129 }, // 496 VQMOVNsuv2i32_VQMOVNsuv4i16_VQMOVNsuv8i8_VQMOVNsv2i32_VQMOVNsv4i16_VQMOVNsv8i8_VQMOVNuv2i32_VQMOVNuv4i16_VQMOVNuv8i8
  { 1, 271, 273, 4129, 4131 }, // 497 VDUPLN16d_VDUPLN32d_VDUPLN8d
  { 1, 317, 319, 4131, 4133 }, // 498 VDUPLN16q_VDUPLN32q_VDUPLN8q
  { 1, 271, 273, 4133, 4135 }, // 499 VDUP16d_VDUP16q_VDUP32d_VDUP32q_VDUP8d_VDUP8q
  { 1, 269, 271, 4135, 4137 }, // 500 VMOVRS
  { 1, 269, 271, 4137, 4139 }, // 501 VMOVSR
  { 1, 317, 319, 4139, 4142 }, // 502 VSETLNi16_VSETLNi32_VSETLNi8
  { 1, 269, 271, 4142, 4145 }, // 503 VMOVRRD_VMOVRRS
  { 1, 269, 271, 4145, 4148 }, // 504 VMOVDRR
  { 1, 269, 271, 4148, 4151 }, // 505 VMOVSRR
  { 1, 271, 273, 4151, 4153 }, // 506 VGETLNi32_VGETLNu16_VGETLNu8
  { 1, 271, 273, 4153, 4155 }, // 507 VGETLNs16_VGETLNs8
  { 1, 271, 273, 4155, 4156 }, // 508 VMRS_VMRS_FPEXC_VMRS_FPINST_VMRS_FPINST2_VMRS_FPSID_VMRS_MVFR0_VMRS_MVFR1_VMRS_MVFR2
  { 1, 271, 273, 4156, 4157 }, // 509 VMSR_VMSR_FPEXC_VMSR_FPINST_VMSR_FPINST2_VMSR_FPSID
  { 1, 271, 273, 4157, 4158 }, // 510 FMSTAT
  { 1, 345, 348, 4158, 4160 }, // 511 VLDRD
  { 1, 345, 348, 4160, 4162 }, // 512 VLDRS
  { 1, 345, 348, 4162, 4164 }, // 513 VSTRD
  { 1, 345, 348, 4164, 4166 }, // 514 VSTRS
  { -1, 340, 345, 4166, 4170 }, // 515 VLDMQIA
  { -1, 340, 345, 4170, 4174 }, // 516 VSTMQIA
  { -1, 340, 345, 4174, 4178 }, // 517 VLDMDIA_VLDMSIA
  { -1, 340, 345, 4178, 4183 }, // 518 VLDMDDB_UPD_VLDMDIA_UPD_VLDMSDB_UPD_VLDMSIA_UPD
  { -1, 340, 345, 4183, 4187 }, // 519 VSTMDIA_VSTMSIA
  { -1, 340, 345, 4187, 4192 }, // 520 VSTMDDB_UPD_VSTMDIA_UPD_VSTMSDB_UPD_VSTMSIA_UPD
  { 1, 328, 331, 4192, 4194 }, // 521 VLD1d16_VLD1d32_VLD1d64_VLD1d8
  { 1, 328, 331, 4194, 4197 }, // 522 VLD1q16_VLD1q32_VLD1q64_VLD1q8
  { 1, 328, 331, 4197, 4200 }, // 523 VLD1d16wb_fixed_VLD1d16wb_register_VLD1d32wb_fixed_VLD1d32wb_register_VLD1d64wb_fixed_VLD1d64wb_register_VLD1d8wb_fixed_VLD1d8wb_register
  { 1, 328, 331, 4200, 4204 }, // 524 VLD1q16wb_fixed_VLD1q16wb_register_VLD1q32wb_fixed_VLD1q32wb_register_VLD1q64wb_fixed_VLD1q64wb_register_VLD1q8wb_fixed_VLD1q8wb_register
  { 1, 331, 334, 4204, 4208 }, // 525 VLD1d16T_VLD1d32T_VLD1d64T_VLD1d64TPseudo_VLD1d64TPseudoWB_fixed_VLD1d64TPseudoWB_register_VLD1d8T
  { 1, 328, 331, 4208, 4212 }, // 526 VLD1d16Twb_fixed_VLD1d16Twb_register_VLD1d32Twb_fixed_VLD1d32Twb_register_VLD1d64Twb_fixed_VLD1d64Twb_register_VLD1d8Twb_fixed_VLD1d8Twb_register
  { 1, 331, 334, 4212, 4217 }, // 527 VLD1d16Q_VLD1d32Q_VLD1d64Q_VLD1d64QPseudo_VLD1d64QPseudoWB_fixed_VLD1d64QPseudoWB_register_VLD1d8Q
  { 1, 328, 331, 4217, 4221 }, // 528 VLD1d16Qwb_fixed_VLD1d16Qwb_register_VLD1d32Qwb_fixed_VLD1d32Qwb_register_VLD1d64Qwb_fixed_VLD1d64Qwb_register_VLD1d8Qwb_fixed_VLD1d8Qwb_register
  { 1, 328, 331, 4221, 4224 }, // 529 VLD2b16_VLD2b32_VLD2b8_VLD2d16_VLD2d32_VLD2d8
  { 1, 331, 334, 4224, 4229 }, // 530 VLD2q16_VLD2q16Pseudo_VLD2q32_VLD2q32Pseudo_VLD2q8_VLD2q8Pseudo
  { 1, 328, 331, 4229, 4235 }, // 531 VLD2b16wb_fixed_VLD2b16wb_register_VLD2b32wb_fixed_VLD2b32wb_register_VLD2b8wb_fixed_VLD2b8wb_register_VLD2d16wb_fixed_VLD2d16wb_register_VLD2d32wb_fixed_VLD2d32wb_register_VLD2d8wb_fixed_VLD2d8wb_register
  { 1, 331, 334, 4235, 4241 }, // 532 VLD2q16PseudoWB_fixed_VLD2q16PseudoWB_register_VLD2q16wb_fixed_VLD2q16wb_register_VLD2q32PseudoWB_fixed_VLD2q32PseudoWB_register_VLD2q32wb_fixed_VLD2q32wb_register_VLD2q8PseudoWB_fixed_VLD2q8PseudoWB_register_VLD2q8wb_fixed_VLD2q8wb_register
  { 1, 337, 340, 4241, 4245 }, // 533 VLD3d16_VLD3d32_VLD3d8_VLD3q16_VLD3q32_VLD3q8
  { 1, 337, 340, 4245, 4249 }, // 534 VLD3d16Pseudo_VLD3d32Pseudo_VLD3d8Pseudo_VLD3q16oddPseudo_VLD3q32oddPseudo_VLD3q8oddPseudo
  { 1, 337, 340, 4249, 4254 }, // 535 VLD3d16_UPD_VLD3d32_UPD_VLD3d8_UPD_VLD3q16_UPD_VLD3q32_UPD_VLD3q8_UPD
  { 1, 337, 340, 4254, 4259 }, // 536 VLD3d16Pseudo_UPD_VLD3d32Pseudo_UPD_VLD3d8Pseudo_UPD_VLD3q16Pseudo_UPD_VLD3q16oddPseudo_UPD_VLD3q32Pseudo_UPD_VLD3q32oddPseudo_UPD_VLD3q8Pseudo_UPD_VLD3q8oddPseudo_UPD
  { 1, 337, 340, 4259, 4264 }, // 537 VLD4d16_VLD4d32_VLD4d8_VLD4q16_VLD4q32_VLD4q8
  { 1, 337, 340, 4264, 4269 }, // 538 VLD4d16Pseudo_VLD4d32Pseudo_VLD4d8Pseudo_VLD4q16oddPseudo_VLD4q32oddPseudo_VLD4q8oddPseudo
  { 1, 337, 340, 4269, 4275 }, // 539 VLD4d16_UPD_VLD4d32_UPD_VLD4d8_UPD_VLD4q16_UPD_VLD4q32_UPD_VLD4q8_UPD
  { 1, 337, 340, 4275, 4281 }, // 540 VLD4d16Pseudo_UPD_VLD4d32Pseudo_UPD_VLD4d8Pseudo_UPD_VLD4q16Pseudo_UPD_VLD4q16oddPseudo_UPD_VLD4q32Pseudo_UPD_VLD4q32oddPseudo_UPD_VLD4q8Pseudo_UPD_VLD4q8oddPseudo_UPD
  { 1, 322, 325, 4281, 4283 }, // 541 VLD1DUPd16_VLD1DUPd32_VLD1DUPd8_VLD1DUPq16_VLD1DUPq32_VLD1DUPq8
  { 1, 325, 328, 4283, 4287 }, // 542 VLD1LNd16_VLD1LNd32_VLD1LNd8_VLD1LNq16Pseudo_VLD1LNq32Pseudo_VLD1LNq8Pseudo
  { 1, 322, 325, 4287, 4291 }, // 543 VLD1DUPd16wb_fixed_VLD1DUPd16wb_register_VLD1DUPd32wb_fixed_VLD1DUPd32wb_register_VLD1DUPd8wb_fixed_VLD1DUPd8wb_register_VLD1DUPq16wb_fixed_VLD1DUPq16wb_register_VLD1DUPq32wb_fixed_VLD1DUPq32wb_register_VLD1DUPq8wb_fixed_VLD1DUPq8wb_register
  { 1, 325, 328, 4291, 4297 }, // 544 VLD1LNd16_UPD_VLD1LNd32_UPD_VLD1LNd8_UPD_VLD1LNq16Pseudo_UPD_VLD1LNq32Pseudo_UPD_VLD1LNq8Pseudo_UPD
  { 1, 322, 325, 4297, 4300 }, // 545 VLD2DUPd16_VLD2DUPd16x2_VLD2DUPd32_VLD2DUPd32x2_VLD2DUPd8_VLD2DUPd8x2
  { 1, 331, 334, 4300, 4306 }, // 546 VLD2LNd16_VLD2LNd16Pseudo_VLD2LNd32_VLD2LNd32Pseudo_VLD2LNd8_VLD2LNd8Pseudo_VLD2LNq16_VLD2LNq16Pseudo_VLD2LNq32_VLD2LNq32Pseudo
  { 1, 331, 334, 4306, 4314 }, // 547 VLD2LNd16_UPD_VLD2LNd32_UPD_VLD2LNd8_UPD_VLD2LNq16_UPD_VLD2LNq32_UPD
  { 1, 322, 325, 4314, 4319 }, // 548 VLD2DUPd16wb_fixed_VLD2DUPd16wb_register_VLD2DUPd16x2wb_fixed_VLD2DUPd16x2wb_register_VLD2DUPd32wb_fixed_VLD2DUPd32wb_register_VLD2DUPd32x2wb_fixed_VLD2DUPd32x2wb_register_VLD2DUPd8wb_fixed_VLD2DUPd8wb_register_VLD2DUPd8x2wb_fixed_VLD2DUPd8x2wb_register
  { 1, 331, 334, 4319, 4327 }, // 549 VLD2LNd16Pseudo_UPD_VLD2LNd32Pseudo_UPD_VLD2LNd8Pseudo_UPD_VLD2LNq16Pseudo_UPD_VLD2LNq32Pseudo_UPD
  { 1, 325, 328, 4327, 4331 }, // 550 VLD3DUPd16_VLD3DUPd16Pseudo_VLD3DUPd32_VLD3DUPd32Pseudo_VLD3DUPd8_VLD3DUPd8Pseudo_VLD3DUPq16_VLD3DUPq32_VLD3DUPq8
  { 1, 334, 337, 4331, 4339 }, // 551 VLD3LNd16_VLD3LNd16Pseudo_VLD3LNd32_VLD3LNd32Pseudo_VLD3LNd8_VLD3LNd8Pseudo_VLD3LNq16_VLD3LNq16Pseudo_VLD3LNq32_VLD3LNq32Pseudo
  { 1, 325, 328, 4339, 4345 }, // 552 VLD3DUPd16_UPD_VLD3DUPd32_UPD_VLD3DUPd8_UPD_VLD3DUPq16_UPD_VLD3DUPq32_UPD_VLD3DUPq8_UPD
  { 1, 334, 337, 4345, 4355 }, // 553 VLD3LNd16_UPD_VLD3LNd32_UPD_VLD3LNd8_UPD_VLD3LNq16_UPD_VLD3LNq32_UPD
  { 1, 325, 328, 4355, 4361 }, // 554 VLD3DUPd16Pseudo_UPD_VLD3DUPd32Pseudo_UPD_VLD3DUPd8Pseudo_UPD
  { 1, 334, 337, 4361, 4371 }, // 555 VLD3LNd16Pseudo_UPD_VLD3LNd32Pseudo_UPD_VLD3LNd8Pseudo_UPD_VLD3LNq16Pseudo_UPD_VLD3LNq32Pseudo_UPD
  { 1, 325, 328, 4371, 4376 }, // 556 VLD4DUPd16_VLD4DUPd16Pseudo_VLD4DUPd32_VLD4DUPd32Pseudo_VLD4DUPd8_VLD4DUPd8Pseudo_VLD4DUPq16_VLD4DUPq32_VLD4DUPq8
  { 1, 334, 337, 4376, 4386 }, // 557 VLD4LNd16_VLD4LNd16Pseudo_VLD4LNd32_VLD4LNd32Pseudo_VLD4LNd8_VLD4LNd8Pseudo_VLD4LNq16_VLD4LNq16Pseudo_VLD4LNq32_VLD4LNq32Pseudo
  { 1, 325, 328, 4386, 4393 }, // 558 VLD4DUPd16_UPD_VLD4DUPd32_UPD_VLD4DUPd8_UPD_VLD4DUPq16_UPD_VLD4DUPq32_UPD_VLD4DUPq8_UPD
  { 1, 334, 337, 4393, 4405 }, // 559 VLD4LNd16_UPD_VLD4LNd32_UPD_VLD4LNd8_UPD_VLD4LNq16_UPD_VLD4LNq32_UPD
  { 1, 325, 328, 4405, 4412 }, // 560 VLD4DUPd16Pseudo_UPD_VLD4DUPd32Pseudo_UPD_VLD4DUPd8Pseudo_UPD
  { 1, 334, 337, 4412, 4424 }, // 561 VLD4LNd16Pseudo_UPD_VLD4LNd32Pseudo_UPD_VLD4LNd8Pseudo_UPD_VLD4LNq16Pseudo_UPD_VLD4LNq32Pseudo_UPD
  { 1, 328, 331, 4424, 4427 }, // 562 VST1d16_VST1d32_VST1d64_VST1d8
  { 1, 328, 331, 4427, 4431 }, // 563 VST1q16_VST1q32_VST1q64_VST1q8
  { 1, 328, 331, 4431, 4434 }, // 564 VST1d16wb_fixed_VST1d16wb_register_VST1d32wb_fixed_VST1d32wb_register_VST1d64wb_fixed_VST1d64wb_register_VST1d8wb_fixed_VST1d8wb_register
  { 1, 328, 331, 4434, 4438 }, // 565 VST1q16wb_fixed_VST1q16wb_register_VST1q32wb_fixed_VST1q32wb_register_VST1q64wb_fixed_VST1q64wb_register_VST1q8wb_fixed_VST1q8wb_register
  { 1, 331, 334, 4438, 4443 }, // 566 VST1d16T_VST1d32T_VST1d64T_VST1d64TPseudo_VST1d8T
  { 1, 331, 334, 4443, 4448 }, // 567 VST1d16Twb_fixed_VST1d16Twb_register_VST1d32Twb_fixed_VST1d32Twb_register_VST1d64Twb_fixed_VST1d64Twb_register_VST1d8Twb_fixed_VST1d8Twb_register
  { 1, 331, 334, 4448, 4455 }, // 568 VST1d64TPseudoWB_fixed_VST1d64TPseudoWB_register
  { 1, 331, 334, 4455, 4461 }, // 569 VST1d16Q_VST1d32Q_VST1d64Q_VST1d64QPseudo_VST1d8Q
  { 1, 331, 334, 4461, 4467 }, // 570 VST1d16Qwb_fixed_VST1d16Qwb_register_VST1d32Qwb_fixed_VST1d32Qwb_register_VST1d64Qwb_fixed_VST1d64Qwb_register_VST1d8Qwb_fixed_VST1d8Qwb_register
  { 1, 331, 334, 4467, 4475 }, // 571 VST1d64QPseudoWB_fixed_VST1d64QPseudoWB_register
  { 1, 328, 331, 4475, 4479 }, // 572 VST2b16_VST2b32_VST2b8_VST2d16_VST2d32_VST2d8
  { 1, 328, 331, 4479, 4482 }, // 573 VST2b16wb_fixed_VST2b16wb_register_VST2b32wb_fixed_VST2b32wb_register_VST2b8wb_fixed_VST2b8wb_register_VST2d16wb_fixed_VST2d16wb_register_VST2d32wb_fixed_VST2d32wb_register_VST2d8wb_fixed_VST2d8wb_register
  { 1, 337, 340, 4482, 4488 }, // 574 VST2q16_VST2q16Pseudo_VST2q32_VST2q32Pseudo_VST2q8_VST2q8Pseudo
  { 1, 337, 340, 4488, 4496 }, // 575 VST2q16PseudoWB_fixed_VST2q16PseudoWB_register_VST2q32PseudoWB_fixed_VST2q32PseudoWB_register_VST2q8PseudoWB_fixed_VST2q8PseudoWB_register
  { 1, 328, 331, 4496, 4499 }, // 576 VST2q16wb_fixed_VST2q16wb_register_VST2q32wb_fixed_VST2q32wb_register_VST2q8wb_fixed_VST2q8wb_register
  { 1, 331, 334, 4499, 4504 }, // 577 VST3d16_VST3d16Pseudo_VST3d32_VST3d32Pseudo_VST3d8_VST3d8Pseudo_VST3q16_VST3q16oddPseudo_VST3q32_VST3q32oddPseudo_VST3q8_VST3q8oddPseudo
  { 1, 331, 334, 4504, 4511 }, // 578 VST3d16Pseudo_UPD_VST3d16_UPD_VST3d32Pseudo_UPD_VST3d32_UPD_VST3d8Pseudo_UPD_VST3d8_UPD_VST3q16Pseudo_UPD_VST3q16_UPD_VST3q16oddPseudo_UPD_VST3q32Pseudo_UPD_VST3q32_UPD_VST3q32oddPseudo_UPD_VST3q8Pseudo_UPD_VST3q8_UPD_VST3q8oddPseudo_UPD
  { 1, 337, 340, 4511, 4517 }, // 579 VST4d16_VST4d16Pseudo_VST4d32_VST4d32Pseudo_VST4d8_VST4d8Pseudo_VST4q16_VST4q16oddPseudo_VST4q32_VST4q32oddPseudo_VST4q8_VST4q8oddPseudo
  { 1, 337, 340, 4517, 4525 }, // 580 VST4d16Pseudo_UPD_VST4d16_UPD_VST4d32Pseudo_UPD_VST4d32_UPD_VST4d8Pseudo_UPD_VST4d8_UPD_VST4q16Pseudo_UPD_VST4q16_UPD_VST4q16oddPseudo_UPD_VST4q32Pseudo_UPD_VST4q32_UPD_VST4q32oddPseudo_UPD_VST4q8Pseudo_UPD_VST4q8_UPD_VST4q8oddPseudo_UPD
  { 1, 322, 325, 4525, 4528 }, // 581 VST1LNd16_VST1LNd32_VST1LNd8_VST1LNq16Pseudo_VST1LNq32Pseudo_VST1LNq8Pseudo
  { 1, 322, 325, 4528, 4533 }, // 582 VST1LNd16_UPD_VST1LNd32_UPD_VST1LNd8_UPD_VST1LNq16Pseudo_UPD_VST1LNq32Pseudo_UPD_VST1LNq8Pseudo_UPD
  { 1, 328, 331, 4533, 4537 }, // 583 VST2LNd16_VST2LNd16Pseudo_VST2LNd32_VST2LNd32Pseudo_VST2LNd8_VST2LNd8Pseudo_VST2LNq16_VST2LNq16Pseudo_VST2LNq32_VST2LNq32Pseudo
  { 1, 328, 331, 4537, 4543 }, // 584 VST2LNd16Pseudo_UPD_VST2LNd16_UPD_VST2LNd32Pseudo_UPD_VST2LNd32_UPD_VST2LNd8Pseudo_UPD_VST2LNd8_UPD_VST2LNq16Pseudo_UPD_VST2LNq16_UPD_VST2LNq32Pseudo_UPD_VST2LNq32_UPD
  { 1, 331, 334, 4543, 4548 }, // 585 VST3LNd16_VST3LNd16Pseudo_VST3LNd32_VST3LNd32Pseudo_VST3LNd8_VST3LNd8Pseudo_VST3LNq16_VST3LNq16Pseudo_VST3LNq32_VST3LNq32Pseudo
  { 1, 331, 334, 4548, 4555 }, // 586 VST3LNd16Pseudo_UPD_VST3LNd16_UPD_VST3LNd32Pseudo_UPD_VST3LNd32_UPD_VST3LNd8Pseudo_UPD_VST3LNd8_UPD_VST3LNq16Pseudo_UPD_VST3LNq16_UPD_VST3LNq32Pseudo_UPD_VST3LNq32_UPD
  { 1, 337, 340, 4555, 4561 }, // 587 VST4LNd16_VST4LNd16Pseudo_VST4LNd32_VST4LNd32Pseudo_VST4LNd8_VST4LNd8Pseudo_VST4LNq16_VST4LNq16Pseudo_VST4LNq32_VST4LNq32Pseudo
  { 1, 337, 340, 4561, 4569 }, // 588 VST4LNd16Pseudo_UPD_VST4LNd16_UPD_VST4LNd32Pseudo_UPD_VST4LNd32_UPD_VST4LNd8Pseudo_UPD_VST4LNd8_UPD_VST4LNq16Pseudo_UPD_VST4LNq16_UPD_VST4LNq32Pseudo_UPD_VST4LNq32_UPD
  { 1, 314, 317, 4569, 4572 }, // 589 VDIVS
  { 1, 319, 322, 4572, 4574 }, // 590 VSQRTS
  { 1, 311, 314, 4574, 4577 }, // 591 VDIVD
  { 1, 311, 314, 4577, 4579 }, // 592 VSQRTD
  { 0, 0, 0, 0, 0 }, // 593 ABS
  { 0, ~0U, ~0U, ~0U, ~0U } // end marker
};

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, Cycles}
extern const llvm::MCWriteProcResEntry ARMWriteProcResTable[] = {
  { 0,  0}, // Invalid
  { 2,  1}, // #1
  { 3,  1}, // #2
  { 1,  1}, // #3
  { 4,  1}, // #4
  { 1,  2}, // #5
  { 5,  1}, // #6
  { 1,  1}, // #7
  { 5,  1}, // #8
  { 1,  1}, // #9
  { 2,  1}, // #10
  { 5,  1}, // #11
  { 2,  3}, // #12
  { 6,  3}, // #13
  { 2,  2}, // #14
  { 2,  2}, // #15
  { 5,  1}, // #16
  { 2,  2}, // #17
  { 6,  2}, // #18
  { 1,  3}, // #19
  { 5,  1}, // #20
  { 1,  1}, // #21
  { 4,  2}, // #22
  { 1,  2}, // #23
  { 4,  2}, // #24
  { 1,  2}, // #25
  { 4,  2}, // #26
  { 5,  1}, // #27
  { 1,  2}, // #28
  { 4,  3}, // #29
  { 5,  2}, // #30
  { 1,  1}, // #31
  { 4,  1}, // #32
  { 5,  1}, // #33
  { 1,  2}, // #34
  { 4,  2}, // #35
  { 5,  2}, // #36
  { 1,  4}, // #37
  { 4,  4}, // #38
  { 5,  3}, // #39
  { 1,  6}, // #40
  { 4,  6}, // #41
  { 5,  5}, // #42
  { 1,  5}, // #43
  { 4,  5}, // #44
  { 5,  4}, // #45
  { 1,  2}, // #46
  { 5,  2}, // #47
  { 1,  3}, // #48
  { 5,  3}, // #49
  { 1,  4}, // #50
  { 5,  4}, // #51
  { 1,  5}, // #52
  { 5,  5}, // #53
  { 1,  6}, // #54
  { 5,  6}, // #55
  { 1,  7}, // #56
  { 5,  7}, // #57
  { 1,  8}, // #58
  { 5,  8}, // #59
  { 1,  1}, // #60
  { 3,  1}, // #61
  { 5,  1}, // #62
  { 1,  2}, // #63
  { 3,  1}, // #64
  { 5,  2}, // #65
  { 1,  3}, // #66
  { 3,  1}, // #67
  { 5,  3}, // #68
  { 1,  4}, // #69
  { 3,  1}, // #70
  { 5,  4}, // #71
  { 1,  5}, // #72
  { 3,  1}, // #73
  { 5,  5}, // #74
  { 1,  6}, // #75
  { 3,  1}, // #76
  { 5,  6}, // #77
  { 1,  7}, // #78
  { 3,  1}, // #79
  { 5,  7}, // #80
  { 1,  8}, // #81
  { 3,  1}, // #82
  { 5,  8}, // #83
  { 1,  3}, // #84
  { 4,  3}, // #85
  { 5,  3}, // #86
  { 1,  4}, // #87
  { 4,  4}, // #88
  { 5,  4}, // #89
  { 1,  5}, // #90
  { 4,  5}, // #91
  { 5,  5}, // #92
  { 1,  6}, // #93
  { 4,  6}, // #94
  { 5,  6}, // #95
  { 1,  7}, // #96
  { 4,  7}, // #97
  { 5,  7}, // #98
  { 1,  8}, // #99
  { 4,  8}, // #100
  { 5,  8}, // #101
  { 3,  1}, // #102
  { 4,  1}, // #103
  { 5,  1}, // #104
  { 4,  0}, // #105
  { 2,  2}, // #106
  { 5,  5}, // #107
  { 4,  1}, // #108
  { 5,  2}, // #109
  { 2,  1}, // #110
  { 3,  1}, // #111
  { 5,  2}, // #112
  { 2,  2}, // #113
  { 5,  3}, // #114
  { 1, 14}, // #115
  { 2,  1}, // #116
  { 5,  1}, // #117
  { 3,  2}, // #118
  { 5,  2}, // #119
  { 3,  3}, // #120
  { 5,  3}, // #121
  { 3,  4}, // #122
  { 5,  4}, // #123
  { 2,  1}, // #124
  { 4,  1}, // #125
  { 5,  1}, // #126
  { 3,  2}, // #127
  { 4,  2}, // #128
  { 5,  2}, // #129
  { 3,  1}, // #130
  { 4,  1}, // #131
  { 5,  2}, // #132
  { 2, 15}, // #133
  { 3, 15}, // #134
  { 4, 15}, // #135
  { 5, 30}, // #136
  { 4,  3}, // #137
  { 5,  1}, // #138
  { 2,  2}, // #139
  { 3,  2}, // #140
  { 4,  1}, // #141
  { 5,  4}, // #142
  { 2,  2}, // #143
  { 3,  2}, // #144
  { 4,  1}, // #145
  { 5,  5}, // #146
  { 3,  3}, // #147
  { 4,  4}, // #148
  { 5,  3}, // #149
  { 3,  3}, // #150
  { 4,  4}, // #151
  { 5,  4}, // #152
  { 2,  2}, // #153
  { 3,  4}, // #154
  { 4,  7}, // #155
  { 5,  6}, // #156
  { 2,  2}, // #157
  { 3,  4}, // #158
  { 4,  4}, // #159
  { 5,  6}, // #160
  { 2,  2}, // #161
  { 3,  4}, // #162
  { 4,  7}, // #163
  { 5,  7}, // #164
  { 2,  2}, // #165
  { 3,  4}, // #166
  { 4,  4}, // #167
  { 5,  7}, // #168
  { 3,  2}, // #169
  { 4,  1}, // #170
  { 5,  2}, // #171
  { 3,  2}, // #172
  { 4,  1}, // #173
  { 5,  3}, // #174
  { 2,  1}, // #175
  { 3,  2}, // #176
  { 4,  2}, // #177
  { 5,  3}, // #178
  { 2,  1}, // #179
  { 3,  2}, // #180
  { 4,  2}, // #181
  { 5,  4}, // #182
  { 2,  1}, // #183
  { 3,  3}, // #184
  { 4,  3}, // #185
  { 5,  4}, // #186
  { 2,  1}, // #187
  { 3,  3}, // #188
  { 4,  3}, // #189
  { 5,  5}, // #190
  { 2,  1}, // #191
  { 3,  5}, // #192
  { 4,  2}, // #193
  { 5,  6}, // #194
  { 2,  1}, // #195
  { 3,  5}, // #196
  { 4,  2}, // #197
  { 5,  7}, // #198
  { 4,  4}, // #199
  { 5,  1}, // #200
  { 3,  2}, // #201
  { 4,  4}, // #202
  { 5,  2}, // #203
  { 3,  2}, // #204
  { 4,  4}, // #205
  { 5,  3}, // #206
  { 3,  4}, // #207
  { 4,  4}, // #208
  { 5,  5}, // #209
  { 1, 15}, // #210
  { 2,  1}, // #211
  { 5,  1}, // #212
  { 1, 30}, // #213
  { 2,  1}, // #214
  { 5,  1}, // #215
  { 2,  3}, // #216
  { 5,  3}, // #217
  { 2,  2}, // #218
  { 5,  2}, // #219
  { 2,  1}, // #220
  { 5,  2}, // #221
  { 4,  5}, // #222
  { 5,  1}, // #223
  { 4,  6}, // #224
  { 5,  1}, // #225
  { 4,  7}, // #226
  { 5,  1}, // #227
  { 4,  8}, // #228
  { 5,  1}, // #229
  { 4,  9}, // #230
  { 5,  1}, // #231
  { 4, 10}, // #232
  { 5,  1}, // #233
  { 4, 11}, // #234
  { 5,  1}, // #235
  { 4, 12}, // #236
  { 5,  1}, // #237
  { 4, 13}, // #238
  { 5,  1}, // #239
  { 4, 14}, // #240
  { 5,  1}, // #241
  { 4, 15}, // #242
  { 5,  1}, // #243
  { 4, 16}, // #244
  { 5,  1}, // #245
  { 4,  5}, // #246
  { 5,  2}, // #247
  { 4,  6}, // #248
  { 5,  2}, // #249
  { 4,  7}, // #250
  { 5,  2}, // #251
  { 4,  8}, // #252
  { 5,  2}, // #253
  { 4,  9}, // #254
  { 5,  2}, // #255
  { 4, 10}, // #256
  { 5,  2}, // #257
  { 4, 11}, // #258
  { 5,  2}, // #259
  { 4, 12}, // #260
  { 5,  2}, // #261
  { 4, 13}, // #262
  { 5,  2}, // #263
  { 4, 14}, // #264
  { 5,  2}, // #265
  { 4, 15}, // #266
  { 5,  2}, // #267
  { 4, 16}, // #268
  { 5,  2}, // #269
  { 3,  1}, // #270
  { 4,  2}, // #271
  { 5,  3}, // #272
  { 3,  1}, // #273
  { 4,  3}, // #274
  { 5,  3}, // #275
  { 3,  1}, // #276
  { 4,  4}, // #277
  { 5,  3}, // #278
  { 3,  1}, // #279
  { 4,  5}, // #280
  { 5,  3}, // #281
  { 3,  1}, // #282
  { 4,  6}, // #283
  { 5,  3}, // #284
  { 3,  1}, // #285
  { 4,  7}, // #286
  { 5,  3}, // #287
  { 3,  1}, // #288
  { 4,  8}, // #289
  { 5,  3}, // #290
  { 3,  1}, // #291
  { 4,  9}, // #292
  { 5,  3}, // #293
  { 3,  1}, // #294
  { 4, 10}, // #295
  { 5,  3}, // #296
  { 3,  1}, // #297
  { 4, 11}, // #298
  { 5,  3}, // #299
  { 3,  1}, // #300
  { 4, 12}, // #301
  { 5,  3}, // #302
  { 3,  1}, // #303
  { 4, 13}, // #304
  { 5,  3}, // #305
  { 3,  1}, // #306
  { 4, 14}, // #307
  { 5,  3}, // #308
  { 3,  1}, // #309
  { 4, 15}, // #310
  { 5,  3}, // #311
  { 3,  1}, // #312
  { 4, 16}, // #313
  { 5,  3}, // #314
  { 4,  9}, // #315
  { 5,  9}, // #316
  { 4, 10}, // #317
  { 5, 10}, // #318
  { 4, 11}, // #319
  { 5, 11}, // #320
  { 4, 12}, // #321
  { 5, 12}, // #322
  { 4, 13}, // #323
  { 5, 13}, // #324
  { 4, 14}, // #325
  { 5, 14}, // #326
  { 4, 15}, // #327
  { 5, 15}, // #328
  { 4, 16}, // #329
  { 5, 16}, // #330
  { 4,  5}, // #331
  { 5,  6}, // #332
  { 4,  6}, // #333
  { 5,  7}, // #334
  { 4,  7}, // #335
  { 5,  8}, // #336
  { 4,  8}, // #337
  { 5,  9}, // #338
  { 4,  9}, // #339
  { 5, 10}, // #340
  { 4, 10}, // #341
  { 5, 11}, // #342
  { 4, 11}, // #343
  { 5, 12}, // #344
  { 4, 12}, // #345
  { 5, 13}, // #346
  { 4, 13}, // #347
  { 5, 14}, // #348
  { 4, 14}, // #349
  { 5, 15}, // #350
  { 4, 15}, // #351
  { 5, 16}, // #352
  { 4, 16}, // #353
  { 5, 17}, // #354
  { 3,  3}, // #355
  { 4,  2}, // #356
  { 5,  4}, // #357
  { 3,  5}, // #358
  { 4,  3}, // #359
  { 5,  6}, // #360
  { 3,  7}, // #361
  { 4,  3}, // #362
  { 5,  8}, // #363
  { 3,  2}, // #364
  { 4,  3}, // #365
  { 5,  3}, // #366
  { 3,  9}, // #367
  { 4,  3}, // #368
  { 5, 10}, // #369
  { 3,  5}, // #370
  { 4,  4}, // #371
  { 5,  6}, // #372
  { 3,  7}, // #373
  { 4,  5}, // #374
  { 5,  8}, // #375
  { 3,  9}, // #376
  { 4,  5}, // #377
  { 5, 10}, // #378
  { 3,  4}, // #379
  { 4,  5}, // #380
  { 5,  5}, // #381
  { 3,  3}, // #382
  { 4,  2}, // #383
  { 5,  6}, // #384
  { 3,  5}, // #385
  { 4,  2}, // #386
  { 5,  8}, // #387
  { 3,  5}, // #388
  { 4,  3}, // #389
  { 5,  8}, // #390
  { 3,  7}, // #391
  { 4,  3}, // #392
  { 5, 10}, // #393
  { 3,  2}, // #394
  { 4,  3}, // #395
  { 5,  5}, // #396
  { 3,  9}, // #397
  { 4,  3}, // #398
  { 5, 12}, // #399
  { 3,  5}, // #400
  { 4,  4}, // #401
  { 5,  8}, // #402
  { 3,  3}, // #403
  { 4,  4}, // #404
  { 5,  6}, // #405
  { 3,  7}, // #406
  { 4,  5}, // #407
  { 5, 10}, // #408
  { 3,  9}, // #409
  { 4,  5}, // #410
  { 5, 12}, // #411
  { 3,  4}, // #412
  { 4,  5}, // #413
  { 5,  7}, // #414
  { 4,  6}, // #415
  { 5,  8}, // #416
  { 4,  8}, // #417
  { 5, 10}, // #418
  { 4, 10}, // #419
  { 5, 12}, // #420
  { 4, 12}, // #421
  { 5, 14}, // #422
  { 4, 14}, // #423
  { 5, 16}, // #424
  { 4, 16}, // #425
  { 5, 18} // #426
}; // ARMWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry ARMWriteLatencyTable[] = {
  { 0,  0}, // Invalid
  { 1,  0}, // #1 A9WriteALU_WriteBr_WriteBrL_WriteBrTbl_A9WriteFMov_WritePreLd_A9WriteB_A9WriteV1_WriteCMP_SwiftWriteP01OneCycle_SwiftWriteP0OneCycle
  { 2,  0}, // #2 WriteALUsi_A9WriteI_A9WriteV2_A9WriteIsr_WriteBrL_SwiftWriteP01TwoCycle_SwiftWriteP01OneCycle_SwiftWriteP0TwoCycle_SwiftWriteP1TwoCycle_SwiftWriteP0OneCycle
  { 3,  0}, // #3 A9WriteALUsr_A9WriteV3_SwiftWriteP01OneCycle_SwiftWriteP2ThreeCycle_SwiftWriteP01ThreeCycleTwoUops_SwiftWriteP0ThreeCycleThreeUops
  { 4, 83}, // #4 A9WriteLb
  { 2,  0}, // #5 A9WriteAdr
  { 5, 84}, // #6 A9WriteLbsi
  { 2,  0}, // #7 A9WriteAdr
  { 3, 40}, // #8 A9WriteL
  { 3, 57}, // #9 A9WriteLHi
  { 1,  0}, // #10 A9WriteAdr
  { 3, 40}, // #11 A9WriteL
  { 1,  0}, // #12 A9WriteAdr
  { 3, 40}, // #13 A9WriteL
  { 1,  0}, // #14 A9WriteAdr_A9WriteLfpOp_A9WriteLSfp_A9WriteFMov
  { 1,  0}, // #15 A9WriteALU_A9WriteS_A9WriteAdr_A9WriteFMov_A9WriteLfpOp_A9WriteLSfp
  { 4, 107}, // #16 A9WriteLsi
  { 1,  0}, // #17 A9WriteAdr
  { 4,  0}, // #18 A9WriteM_A9WriteV4_A9WriteF_A9Write2V4_WriteCvtFP_SwiftWriteP0FourCycle_SwiftWriteP2P01FourCyle_SwiftWriteP0P1FourCycle_SwiftWriteP1FourCycle_SwiftWriteP1TwoCycle_SwiftWriteP2FourCycle_SwiftWriteLM4Cy_SwiftWrite3xP2FourCy_SwiftWrite2xP2FourCy
  { 5,  0}, // #19 A9WriteMHi_A9WriteV5_A9WriteFMulS_SwiftWriteP2ThreeCycle_SwiftWriteP0P01FiveCycleTwoUops
  { 5, 40}, // #20 A9WriteL
  { 2,  0}, // #21 A9WriteAdr
  { 1,  0}, // #22 A9WriteS_SwiftWriteLDMAddrWB
  { 3,  0}, // #23 A9WriteM16_A9WriteV3_SwiftWriteP2P2ThreeCycle_SwiftWriteP2ThreeCycle_SwiftWriteLM3Cy
  { 4,  0}, // #24 A9WriteM16Hi_A9WriteV4_SwiftWriteLdFour_SwiftWriteP2FourCycle_SwiftWriteLM4Cy
  { 3,  0}, // #25 A9WriteAdr_SwiftWriteP2P01ThreeCycle_SwiftWriteP2ThreeCycle
  { 1,  0}, // #26 A9WriteS_SwiftWrBackOne_WriteALU
  { 6,  0}, // #27 A9WriteV6_A9WriteFMulD_SwiftWriteP0P1SixCycle_SwiftWriteP1TwoCycle_SwiftWriteP0SixCycle_SwiftWriteP1SixCycle_SwiftWriteP0TwoCycle_SwiftWriteP01OneCycle
  {25,  0}, // #28 A9WriteFDivD
  {15,  0}, // #29 A9WriteFDivS
  { 2,  0}, // #30 A9WriteV2_A9WriteLfpOp_A9WriteAdr
  { 2,  0}, // #31 A9WriteV2_A9WriteAdr_A9WriteLfpOp
  { 9,  0}, // #32 A9WriteV9_A9WriteFMAD_A9Write2V9
  {10,  0}, // #33 A9WriteV10
  { 5,  0}, // #34 A9WriteLfpOp
  { 1,  0}, // #35 A9WriteAdr
  { 6,  0}, // #36 A9WriteLfpOp
  { 1,  0}, // #37 A9WriteAdr
  { 7,  0}, // #38 A9WriteLfpOp_A9Write2V7_A9WriteV7
  { 3,  0}, // #39 A9WriteAdr
  { 9,  0}, // #40 A9WriteLfpOp
  { 5,  0}, // #41 A9WriteAdr
  { 8,  0}, // #42 A9WriteLfpOp_A9WriteFMAS_SwiftWriteP1TwoCycle_SwiftWriteP1EightCycle
  { 4,  0}, // #43 A9WriteAdr
  {32,  0}, // #44 A9WriteFSqrtD_SwiftDiv32
  {17,  0}, // #45 A9WriteFSqrtS_SwiftDiv17
  { 3,  0}, // #46 A9WriteCycle1_A9WriteAdr_A9WriteLfpOp
  { 3,  0}, // #47 A9WriteCycle1_A9WriteLfpOp_A9WriteAdr
  { 1,  0}, // #48 A9WriteAdr_SwiftWriteP01OneCycle
  { 0,  0}, // #49 A9WriteIssue_SwiftWriteP2_SwiftWriteStIncAddr
  { 3,  0}, // #50 A9WriteCycle1
  { 3,  0}, // #51 A9WriteCycle1
  { 4,  0}, // #52 A9WriteCycle1_A9WriteAdr_A9WriteLfpOp_SwiftWriteP1FourCycle_SwiftWriteLM4Cy
  { 4,  0}, // #53 A9WriteCycle1_A9WriteLfpOp_A9WriteAdr_SwiftWriteP1FourCycle_SwiftWriteLM4CyNo
  { 2,  0}, // #54 A9WriteAdr_SwiftWriteP1TwoCycle_SwiftWriteP01OneCycle
  { 0,  0}, // #55 A9WriteIssue_SwiftWriteStIncAddr
  { 3,  0}, // #56 A9WriteCycle1
  { 3,  0}, // #57 A9WriteCycle1
  { 4,  0}, // #58 A9WriteCycle1
  { 4,  0}, // #59 A9WriteCycle1
  { 5,  0}, // #60 A9WriteCycle1_A9WriteAdr_A9WriteLfpOp_SwiftP0P0P01FiveCycle
  { 5,  0}, // #61 A9WriteCycle1_A9WriteLfpOp_A9WriteAdr_SwiftWrite5Cycle
  { 3,  0}, // #62 A9WriteAdr
  { 0,  0}, // #63 A9WriteIssue
  { 3,  0}, // #64 A9WriteCycle1
  { 3,  0}, // #65 A9WriteCycle1
  { 4,  0}, // #66 A9WriteCycle1
  { 4,  0}, // #67 A9WriteCycle1
  { 5,  0}, // #68 A9WriteCycle1
  { 5,  0}, // #69 A9WriteCycle1
  { 6,  0}, // #70 A9WriteCycle1_A9WriteAdr_A9WriteLfpOp
  { 6,  0}, // #71 A9WriteCycle1_A9WriteLfpOp_A9WriteAdr
  { 4,  0}, // #72 A9WriteAdr
  { 0,  0}, // #73 A9WriteIssue
  { 3,  0}, // #74 A9WriteCycle1
  { 3,  0}, // #75 A9WriteCycle1
  { 4,  0}, // #76 A9WriteCycle1
  { 4,  0}, // #77 A9WriteCycle1
  { 5,  0}, // #78 A9WriteCycle1
  { 5,  0}, // #79 A9WriteCycle1
  { 6,  0}, // #80 A9WriteCycle1
  { 6,  0}, // #81 A9WriteCycle1_SwiftWriteP1TwoCycle
  { 7,  0}, // #82 A9WriteCycle1_A9WriteAdr_A9WriteLfpOp_SwiftWriteP1TwoCycle
  { 7,  0}, // #83 A9WriteCycle1_A9WriteLfpOp_A9WriteAdr
  { 5,  0}, // #84 A9WriteAdr
  { 0,  0}, // #85 A9WriteIssue
  { 3,  0}, // #86 A9WriteCycle1
  { 3,  0}, // #87 A9WriteCycle1
  { 4,  0}, // #88 A9WriteCycle1
  { 4,  0}, // #89 A9WriteCycle1
  { 5,  0}, // #90 A9WriteCycle1
  { 5,  0}, // #91 A9WriteCycle1
  { 6,  0}, // #92 A9WriteCycle1
  { 6,  0}, // #93 A9WriteCycle1
  { 7,  0}, // #94 A9WriteCycle1
  { 7,  0}, // #95 A9WriteCycle1
  { 8,  0}, // #96 A9WriteCycle1_A9WriteAdr_A9WriteLfpOp
  { 8,  0}, // #97 A9WriteCycle1_A9WriteLfpOp_A9WriteAdr
  { 6,  0}, // #98 A9WriteAdr_SwiftWriteLM6Cy
  { 0,  0}, // #99 A9WriteIssue_SwiftVLDMPerm2
  { 3,  0}, // #100 A9WriteCycle1
  { 3,  0}, // #101 A9WriteCycle1
  { 4,  0}, // #102 A9WriteCycle1
  { 4,  0}, // #103 A9WriteCycle1
  { 5,  0}, // #104 A9WriteCycle1
  { 5,  0}, // #105 A9WriteCycle1
  { 6,  0}, // #106 A9WriteCycle1
  { 6,  0}, // #107 A9WriteCycle1
  { 7,  0}, // #108 A9WriteCycle1
  { 7,  0}, // #109 A9WriteCycle1
  { 8,  0}, // #110 A9WriteCycle1
  { 8,  0}, // #111 A9WriteCycle1
  { 9,  0}, // #112 A9WriteCycle1
  { 9,  0}, // #113 A9WriteCycle1
  { 7,  0}, // #114 A9WriteAdr
  { 0,  0}, // #115 A9WriteIssue
  { 3,  0}, // #116 A9WriteCycle1
  { 3,  0}, // #117 A9WriteCycle1
  { 4,  0}, // #118 A9WriteCycle1
  { 4,  0}, // #119 A9WriteCycle1
  { 5,  0}, // #120 A9WriteCycle1
  { 5,  0}, // #121 A9WriteCycle1
  { 6,  0}, // #122 A9WriteCycle1
  { 6,  0}, // #123 A9WriteCycle1
  { 7,  0}, // #124 A9WriteCycle1
  { 7,  0}, // #125 A9WriteCycle1
  { 8,  0}, // #126 A9WriteCycle1
  { 8,  0}, // #127 A9WriteCycle1
  { 9,  0}, // #128 A9WriteCycle1
  { 9,  0}, // #129 A9WriteCycle1
  {10,  0}, // #130 A9WriteCycle1
  {10,  0}, // #131 A9WriteCycle1
  { 8,  0}, // #132 A9WriteAdr
  { 0,  0}, // #133 A9WriteIssue
  { 3,  0}, // #134 A9WriteCycle1
  { 3,  0}, // #135 A9WriteCycle1
  { 4,  0}, // #136 A9WriteCycle1
  { 4,  0}, // #137 A9WriteCycle1
  { 5,  0}, // #138 A9WriteCycle1
  { 5,  0}, // #139 A9WriteCycle1
  { 6,  0}, // #140 A9WriteCycle1
  { 6,  0}, // #141 A9WriteCycle1
  { 7,  0}, // #142 A9WriteCycle1
  { 7,  0}, // #143 A9WriteCycle1
  { 8,  0}, // #144 A9WriteCycle1
  { 8,  0}, // #145 A9WriteCycle1
  { 9,  0}, // #146 A9WriteCycle1
  { 9,  0}, // #147 A9WriteCycle1
  {10,  0}, // #148 A9WriteCycle1
  {10,  0}, // #149 A9WriteCycle1
  { 2,  0}, // #150 A9WriteAdr
  { 0,  0}, // #151 A9WriteIssue
  { 1,  0}, // #152 A9WriteAdr
  { 3,  0}, // #153 A9WriteCycle1
  { 3,  0}, // #154 A9WriteCycle1
  { 0,  0}, // #155 A9WriteIssue
  { 2,  0}, // #156 A9WriteAdr
  { 3,  0}, // #157 A9WriteCycle1
  { 3,  0}, // #158 A9WriteCycle1
  { 4,  0}, // #159 A9WriteCycle1
  { 4,  0}, // #160 A9WriteCycle1
  { 0,  0}, // #161 A9WriteIssue
  { 3,  0}, // #162 A9WriteAdr
  { 3,  0}, // #163 A9WriteCycle1
  { 3,  0}, // #164 A9WriteCycle1
  { 4,  0}, // #165 A9WriteCycle1
  { 4,  0}, // #166 A9WriteCycle1
  { 5,  0}, // #167 A9WriteCycle1
  { 5,  0}, // #168 A9WriteCycle1
  { 0,  0}, // #169 A9WriteIssue
  { 4,  0}, // #170 A9WriteAdr
  { 3,  0}, // #171 A9WriteCycle1
  { 3,  0}, // #172 A9WriteCycle1
  { 4,  0}, // #173 A9WriteCycle1
  { 4,  0}, // #174 A9WriteCycle1
  { 5,  0}, // #175 A9WriteCycle1
  { 5,  0}, // #176 A9WriteCycle1
  { 6,  0}, // #177 A9WriteCycle1
  { 6,  0}, // #178 A9WriteCycle1
  { 0,  0}, // #179 A9WriteIssue
  { 5,  0}, // #180 A9WriteAdr
  { 3,  0}, // #181 A9WriteCycle1
  { 3,  0}, // #182 A9WriteCycle1
  { 4,  0}, // #183 A9WriteCycle1
  { 4,  0}, // #184 A9WriteCycle1
  { 5,  0}, // #185 A9WriteCycle1
  { 5,  0}, // #186 A9WriteCycle1
  { 6,  0}, // #187 A9WriteCycle1
  { 6,  0}, // #188 A9WriteCycle1
  { 7,  0}, // #189 A9WriteCycle1
  { 7,  0}, // #190 A9WriteCycle1
  { 0,  0}, // #191 A9WriteIssue
  { 6,  0}, // #192 A9WriteAdr
  { 3,  0}, // #193 A9WriteCycle1
  { 3,  0}, // #194 A9WriteCycle1
  { 4,  0}, // #195 A9WriteCycle1
  { 4,  0}, // #196 A9WriteCycle1
  { 5,  0}, // #197 A9WriteCycle1
  { 5,  0}, // #198 A9WriteCycle1
  { 6,  0}, // #199 A9WriteCycle1
  { 6,  0}, // #200 A9WriteCycle1
  { 7,  0}, // #201 A9WriteCycle1
  { 7,  0}, // #202 A9WriteCycle1
  { 8,  0}, // #203 A9WriteCycle1
  { 8,  0}, // #204 A9WriteCycle1
  { 0,  0}, // #205 A9WriteIssue
  { 7,  0}, // #206 A9WriteAdr
  { 3,  0}, // #207 A9WriteCycle1
  { 3,  0}, // #208 A9WriteCycle1
  { 4,  0}, // #209 A9WriteCycle1
  { 4,  0}, // #210 A9WriteCycle1
  { 5,  0}, // #211 A9WriteCycle1
  { 5,  0}, // #212 A9WriteCycle1
  { 6,  0}, // #213 A9WriteCycle1
  { 6,  0}, // #214 A9WriteCycle1
  { 7,  0}, // #215 A9WriteCycle1
  { 7,  0}, // #216 A9WriteCycle1
  { 8,  0}, // #217 A9WriteCycle1
  { 8,  0}, // #218 A9WriteCycle1
  { 9,  0}, // #219 A9WriteCycle1
  { 9,  0}, // #220 A9WriteCycle1
  { 0,  0}, // #221 A9WriteIssue
  { 8,  0}, // #222 A9WriteAdr
  { 3,  0}, // #223 A9WriteCycle1
  { 3,  0}, // #224 A9WriteCycle1
  { 4,  0}, // #225 A9WriteCycle1
  { 4,  0}, // #226 A9WriteCycle1
  { 5,  0}, // #227 A9WriteCycle1
  { 5,  0}, // #228 A9WriteCycle1
  { 6,  0}, // #229 A9WriteCycle1
  { 6,  0}, // #230 A9WriteCycle1
  { 7,  0}, // #231 A9WriteCycle1
  { 7,  0}, // #232 A9WriteCycle1
  { 8,  0}, // #233 A9WriteCycle1
  { 8,  0}, // #234 A9WriteCycle1
  { 9,  0}, // #235 A9WriteCycle1
  { 9,  0}, // #236 A9WriteCycle1
  {10,  0}, // #237 A9WriteCycle1
  {10,  0}, // #238 A9WriteCycle1
  { 0,  0}, // #239 A9WriteIssue
  { 2,  0}, // #240 A9WriteAdr
  { 3,  0}, // #241 A9WriteCycle1
  { 3,  0}, // #242 A9WriteCycle1
  { 4,  0}, // #243 A9WriteCycle1
  { 4,  0}, // #244 A9WriteCycle1
  { 5,  0}, // #245 A9WriteCycle1
  { 5,  0}, // #246 A9WriteCycle1
  { 6,  0}, // #247 A9WriteCycle1
  { 6,  0}, // #248 A9WriteCycle1
  { 7,  0}, // #249 A9WriteCycle1
  { 7,  0}, // #250 A9WriteCycle1
  { 8,  0}, // #251 A9WriteCycle1
  { 8,  0}, // #252 A9WriteCycle1
  { 9,  0}, // #253 A9WriteCycle1
  { 9,  0}, // #254 A9WriteCycle1
  {10,  0}, // #255 A9WriteCycle1
  {10,  0}, // #256 A9WriteCycle1
  { 0,  0}, // #257 A9WriteIssue
  { 3,  0}, // #258 A9WriteCycle1
  { 3,  0}, // #259 A9WriteCycle1
  { 1,  0}, // #260 A9WriteAdr
  { 1,  0}, // #261 A9WriteB_A9WriteCycle1
  { 3,  0}, // #262 A9WriteCycle1
  { 3,  0}, // #263 A9WriteCycle1
  { 4,  0}, // #264 A9WriteCycle1
  { 4,  0}, // #265 A9WriteCycle1
  { 2,  0}, // #266 A9WriteAdr
  { 1,  0}, // #267 A9WriteB
  { 3,  0}, // #268 A9WriteCycle1
  { 3,  0}, // #269 A9WriteCycle1
  { 4,  0}, // #270 A9WriteCycle1
  { 4,  0}, // #271 A9WriteCycle1
  { 5,  0}, // #272 A9WriteCycle1
  { 5,  0}, // #273 A9WriteCycle1
  { 3,  0}, // #274 A9WriteAdr
  { 1,  0}, // #275 A9WriteB
  { 3,  0}, // #276 A9WriteCycle1
  { 3,  0}, // #277 A9WriteCycle1
  { 4,  0}, // #278 A9WriteCycle1
  { 4,  0}, // #279 A9WriteCycle1
  { 5,  0}, // #280 A9WriteCycle1
  { 5,  0}, // #281 A9WriteCycle1
  { 6,  0}, // #282 A9WriteCycle1
  { 6,  0}, // #283 A9WriteCycle1
  { 4,  0}, // #284 A9WriteAdr_SwiftWriteP2P01P01FourCycle_SwiftWriteLM4Cy_SwiftWrite3xP2FourCy_SwiftWrite2xP2FourCy
  { 1,  0}, // #285 A9WriteB_SwiftWrBackOne_SwiftWriteP01OneCycle
  { 3,  0}, // #286 A9WriteCycle1
  { 3,  0}, // #287 A9WriteCycle1
  { 4,  0}, // #288 A9WriteCycle1
  { 4,  0}, // #289 A9WriteCycle1
  { 5,  0}, // #290 A9WriteCycle1
  { 5,  0}, // #291 A9WriteCycle1
  { 6,  0}, // #292 A9WriteCycle1
  { 6,  0}, // #293 A9WriteCycle1
  { 7,  0}, // #294 A9WriteCycle1
  { 7,  0}, // #295 A9WriteCycle1
  { 5,  0}, // #296 A9WriteAdr
  { 1,  0}, // #297 A9WriteB
  { 3,  0}, // #298 A9WriteCycle1
  { 3,  0}, // #299 A9WriteCycle1
  { 4,  0}, // #300 A9WriteCycle1
  { 4,  0}, // #301 A9WriteCycle1
  { 5,  0}, // #302 A9WriteCycle1
  { 5,  0}, // #303 A9WriteCycle1
  { 6,  0}, // #304 A9WriteCycle1
  { 6,  0}, // #305 A9WriteCycle1
  { 7,  0}, // #306 A9WriteCycle1
  { 7,  0}, // #307 A9WriteCycle1
  { 8,  0}, // #308 A9WriteCycle1
  { 8,  0}, // #309 A9WriteCycle1
  { 6,  0}, // #310 A9WriteAdr
  { 1,  0}, // #311 A9WriteB
  { 3,  0}, // #312 A9WriteCycle1
  { 3,  0}, // #313 A9WriteCycle1
  { 4,  0}, // #314 A9WriteCycle1
  { 4,  0}, // #315 A9WriteCycle1
  { 5,  0}, // #316 A9WriteCycle1
  { 5,  0}, // #317 A9WriteCycle1
  { 6,  0}, // #318 A9WriteCycle1
  { 6,  0}, // #319 A9WriteCycle1
  { 7,  0}, // #320 A9WriteCycle1
  { 7,  0}, // #321 A9WriteCycle1
  { 8,  0}, // #322 A9WriteCycle1
  { 8,  0}, // #323 A9WriteCycle1
  { 9,  0}, // #324 A9WriteCycle1
  { 9,  0}, // #325 A9WriteCycle1
  { 7,  0}, // #326 A9WriteAdr
  { 1,  0}, // #327 A9WriteB
  { 3,  0}, // #328 A9WriteCycle1
  { 3,  0}, // #329 A9WriteCycle1
  { 4,  0}, // #330 A9WriteCycle1
  { 4,  0}, // #331 A9WriteCycle1
  { 5,  0}, // #332 A9WriteCycle1
  { 5,  0}, // #333 A9WriteCycle1
  { 6,  0}, // #334 A9WriteCycle1
  { 6,  0}, // #335 A9WriteCycle1
  { 7,  0}, // #336 A9WriteCycle1
  { 7,  0}, // #337 A9WriteCycle1
  { 8,  0}, // #338 A9WriteCycle1
  { 8,  0}, // #339 A9WriteCycle1
  { 9,  0}, // #340 A9WriteCycle1
  { 9,  0}, // #341 A9WriteCycle1
  {10,  0}, // #342 A9WriteCycle1
  {10,  0}, // #343 A9WriteCycle1
  { 8,  0}, // #344 A9WriteAdr
  { 1,  0}, // #345 A9WriteB
  { 3,  0}, // #346 A9WriteCycle1
  { 3,  0}, // #347 A9WriteCycle1
  { 4,  0}, // #348 A9WriteCycle1
  { 4,  0}, // #349 A9WriteCycle1
  { 5,  0}, // #350 A9WriteCycle1
  { 5,  0}, // #351 A9WriteCycle1
  { 6,  0}, // #352 A9WriteCycle1
  { 6,  0}, // #353 A9WriteCycle1
  { 7,  0}, // #354 A9WriteCycle1
  { 7,  0}, // #355 A9WriteCycle1
  { 8,  0}, // #356 A9WriteCycle1
  { 8,  0}, // #357 A9WriteCycle1
  { 9,  0}, // #358 A9WriteCycle1
  { 9,  0}, // #359 A9WriteCycle1
  {10,  0}, // #360 A9WriteCycle1
  {10,  0}, // #361 A9WriteCycle1
  { 2,  0}, // #362 A9WriteAdr
  { 1,  0}, // #363 A9WriteB
  { 2,  0}, // #364 A9WriteAdr
  { 1,  0}, // #365 A9WriteCycle1
  { 2,  0}, // #366 A9WriteCycle1_SwiftWriteP01OneCycle
  { 4,  0}, // #367 A9WriteCycle1_SwiftWriteLM4Cy
  { 4,  0}, // #368 A9WriteCycle1_SwiftWriteLM4CyNo
  { 3,  0}, // #369 A9WriteAdr
  { 1,  0}, // #370 A9WriteCycle1
  { 2,  0}, // #371 A9WriteCycle1
  { 3,  0}, // #372 A9WriteCycle1
  { 4,  0}, // #373 A9WriteCycle1
  { 5,  0}, // #374 A9WriteCycle1
  { 5,  0}, // #375 A9WriteCycle1
  { 4,  0}, // #376 A9WriteAdr
  { 1,  0}, // #377 A9WriteCycle1
  { 2,  0}, // #378 A9WriteCycle1
  { 3,  0}, // #379 A9WriteCycle1
  { 4,  0}, // #380 A9WriteCycle1
  { 5,  0}, // #381 A9WriteCycle1
  { 5,  0}, // #382 A9WriteCycle1
  { 6,  0}, // #383 A9WriteCycle1
  { 6,  0}, // #384 A9WriteCycle1
  { 5,  0}, // #385 A9WriteAdr
  { 1,  0}, // #386 A9WriteCycle1
  { 2,  0}, // #387 A9WriteCycle1
  { 3,  0}, // #388 A9WriteCycle1
  { 4,  0}, // #389 A9WriteCycle1
  { 5,  0}, // #390 A9WriteCycle1
  { 5,  0}, // #391 A9WriteCycle1
  { 6,  0}, // #392 A9WriteCycle1
  { 6,  0}, // #393 A9WriteCycle1
  { 7,  0}, // #394 A9WriteCycle1
  { 7,  0}, // #395 A9WriteCycle1
  { 6,  0}, // #396 A9WriteAdr
  { 1,  0}, // #397 A9WriteCycle1
  { 2,  0}, // #398 A9WriteCycle1
  { 3,  0}, // #399 A9WriteCycle1
  { 4,  0}, // #400 A9WriteCycle1
  { 5,  0}, // #401 A9WriteCycle1
  { 6,  0}, // #402 A9WriteCycle1
  { 6,  0}, // #403 A9WriteCycle1
  { 6,  0}, // #404 A9WriteCycle1
  { 7,  0}, // #405 A9WriteCycle1
  { 7,  0}, // #406 A9WriteCycle1
  { 8,  0}, // #407 A9WriteCycle1
  { 8,  0}, // #408 A9WriteCycle1
  { 7,  0}, // #409 A9WriteAdr
  { 1,  0}, // #410 A9WriteCycle1
  { 2,  0}, // #411 A9WriteCycle1
  { 3,  0}, // #412 A9WriteCycle1
  { 4,  0}, // #413 A9WriteCycle1
  { 5,  0}, // #414 A9WriteCycle1
  { 6,  0}, // #415 A9WriteCycle1
  { 7,  0}, // #416 A9WriteCycle1
  { 6,  0}, // #417 A9WriteCycle1
  { 7,  0}, // #418 A9WriteCycle1
  { 7,  0}, // #419 A9WriteCycle1
  { 8,  0}, // #420 A9WriteCycle1
  { 8,  0}, // #421 A9WriteCycle1
  { 9,  0}, // #422 A9WriteCycle1
  { 9,  0}, // #423 A9WriteCycle1
  { 8,  0}, // #424 A9WriteAdr
  { 1,  0}, // #425 A9WriteCycle1
  { 2,  0}, // #426 A9WriteCycle1
  { 3,  0}, // #427 A9WriteCycle1
  { 4,  0}, // #428 A9WriteCycle1
  { 5,  0}, // #429 A9WriteCycle1
  { 6,  0}, // #430 A9WriteCycle1
  { 7,  0}, // #431 A9WriteCycle1
  { 8,  0}, // #432 A9WriteCycle1
  { 7,  0}, // #433 A9WriteCycle1
  { 7,  0}, // #434 A9WriteCycle1
  { 8,  0}, // #435 A9WriteCycle1
  { 8,  0}, // #436 A9WriteCycle1
  { 9,  0}, // #437 A9WriteCycle1
  { 9,  0}, // #438 A9WriteCycle1
  {10,  0}, // #439 A9WriteCycle1
  {10,  0}, // #440 A9WriteCycle1
  { 2,  0}, // #441 A9WriteAdr
  { 1,  0}, // #442 A9WriteCycle1
  { 2,  0}, // #443 A9WriteCycle1
  { 5,  0}, // #444 A9WriteCycle1
  { 6,  0}, // #445 A9WriteCycle1
  { 7,  0}, // #446 A9WriteCycle1
  { 8,  0}, // #447 A9WriteCycle1
  { 9,  0}, // #448 A9WriteCycle1
  {10,  0}, // #449 A9WriteCycle1
  { 7,  0}, // #450 A9WriteCycle1
  { 7,  0}, // #451 A9WriteCycle1
  { 8,  0}, // #452 A9WriteCycle1
  { 8,  0}, // #453 A9WriteCycle1
  { 9,  0}, // #454 A9WriteCycle1
  { 9,  0}, // #455 A9WriteCycle1
  {10,  0}, // #456 A9WriteCycle1
  {10,  0}, // #457 A9WriteCycle1
  { 1,  0}, // #458 A9WriteCycle1
  { 3,  0}, // #459 A9WriteCycle1
  { 1,  0}, // #460 A9WriteAdr
  { 1,  0}, // #461 A9WriteCycle1
  { 2,  0}, // #462 A9WriteCycle1
  { 4,  0}, // #463 A9WriteCycle1
  { 4,  0}, // #464 A9WriteCycle1
  { 2,  0}, // #465 A9WriteAdr
  { 1,  0}, // #466 A9WriteCycle1
  { 2,  0}, // #467 A9WriteCycle1
  { 3,  0}, // #468 A9WriteCycle1
  { 4,  0}, // #469 A9WriteCycle1
  { 5,  0}, // #470 A9WriteCycle1
  { 5,  0}, // #471 A9WriteCycle1
  { 3,  0}, // #472 A9WriteAdr
  { 1,  0}, // #473 A9WriteCycle1
  { 2,  0}, // #474 A9WriteCycle1
  { 3,  0}, // #475 A9WriteCycle1
  { 4,  0}, // #476 A9WriteCycle1
  { 5,  0}, // #477 A9WriteCycle1
  { 5,  0}, // #478 A9WriteCycle1
  { 6,  0}, // #479 A9WriteCycle1
  { 6,  0}, // #480 A9WriteCycle1
  { 4,  0}, // #481 A9WriteAdr
  { 1,  0}, // #482 A9WriteCycle1
  { 2,  0}, // #483 A9WriteCycle1
  { 3,  0}, // #484 A9WriteCycle1
  { 4,  0}, // #485 A9WriteCycle1
  { 5,  0}, // #486 A9WriteCycle1
  { 5,  0}, // #487 A9WriteCycle1
  { 6,  0}, // #488 A9WriteCycle1
  { 6,  0}, // #489 A9WriteCycle1
  { 7,  0}, // #490 A9WriteCycle1
  { 7,  0}, // #491 A9WriteCycle1
  { 5,  0}, // #492 A9WriteAdr
  { 1,  0}, // #493 A9WriteCycle1
  { 2,  0}, // #494 A9WriteCycle1
  { 3,  0}, // #495 A9WriteCycle1
  { 4,  0}, // #496 A9WriteCycle1
  { 5,  0}, // #497 A9WriteCycle1
  { 6,  0}, // #498 A9WriteCycle1
  { 6,  0}, // #499 A9WriteCycle1
  { 6,  0}, // #500 A9WriteCycle1
  { 7,  0}, // #501 A9WriteCycle1
  { 7,  0}, // #502 A9WriteCycle1
  { 8,  0}, // #503 A9WriteCycle1
  { 8,  0}, // #504 A9WriteCycle1
  { 6,  0}, // #505 A9WriteAdr
  { 1,  0}, // #506 A9WriteCycle1
  { 2,  0}, // #507 A9WriteCycle1
  { 3,  0}, // #508 A9WriteCycle1
  { 4,  0}, // #509 A9WriteCycle1
  { 5,  0}, // #510 A9WriteCycle1
  { 6,  0}, // #511 A9WriteCycle1
  { 7,  0}, // #512 A9WriteCycle1
  { 6,  0}, // #513 A9WriteCycle1
  { 7,  0}, // #514 A9WriteCycle1
  { 7,  0}, // #515 A9WriteCycle1
  { 8,  0}, // #516 A9WriteCycle1
  { 8,  0}, // #517 A9WriteCycle1
  { 9,  0}, // #518 A9WriteCycle1
  { 9,  0}, // #519 A9WriteCycle1
  { 7,  0}, // #520 A9WriteAdr
  { 1,  0}, // #521 A9WriteCycle1
  { 2,  0}, // #522 A9WriteCycle1
  { 3,  0}, // #523 A9WriteCycle1
  { 4,  0}, // #524 A9WriteCycle1
  { 5,  0}, // #525 A9WriteCycle1
  { 6,  0}, // #526 A9WriteCycle1
  { 7,  0}, // #527 A9WriteCycle1
  { 8,  0}, // #528 A9WriteCycle1
  { 7,  0}, // #529 A9WriteCycle1
  { 7,  0}, // #530 A9WriteCycle1
  { 8,  0}, // #531 A9WriteCycle1
  { 8,  0}, // #532 A9WriteCycle1
  { 9,  0}, // #533 A9WriteCycle1
  { 9,  0}, // #534 A9WriteCycle1
  {10,  0}, // #535 A9WriteCycle1
  {10,  0}, // #536 A9WriteCycle1
  { 8,  0}, // #537 A9WriteAdr
  { 1,  0}, // #538 A9WriteCycle1
  { 2,  0}, // #539 A9WriteCycle1
  { 5,  0}, // #540 A9WriteCycle1
  { 6,  0}, // #541 A9WriteCycle1
  { 7,  0}, // #542 A9WriteCycle1
  { 8,  0}, // #543 A9WriteCycle1
  { 9,  0}, // #544 A9WriteCycle1
  {10,  0}, // #545 A9WriteCycle1
  { 7,  0}, // #546 A9WriteCycle1
  { 7,  0}, // #547 A9WriteCycle1
  { 8,  0}, // #548 A9WriteCycle1
  { 8,  0}, // #549 A9WriteCycle1
  { 9,  0}, // #550 A9WriteCycle1
  { 9,  0}, // #551 A9WriteCycle1
  {10,  0}, // #552 A9WriteCycle1
  {10,  0}, // #553 A9WriteCycle1
  { 2,  0}, // #554 A9WriteAdr
  { 5,  0}, // #555 SwiftWrite5Cycle
  { 7,  0}, // #556 Swift2P03P01FiveCycle
  {14,  0}, // #557 SwiftDiv
  { 3,  0}, // #558 SwiftWriteP2P2P01ThreeCycle
  { 4,  0}, // #559 SwiftWriteLdFour
  { 1,  0}, // #560 SwiftWrBackOne_SwiftWriteP01OneCycle
  { 0,  0}, // #561 SwiftWriteP2
  { 0,  0}, // #562 SwiftWriteP2_SwiftVLDMPerm1_SwiftVLDMPerm2_SwiftVLDMPerm4
  { 1,  0}, // #563 SwiftWriteP01OneCycle
  {12,  0}, // #564 SwiftWriteP1TwelveCyc
  {15,  0}, // #565 SwiftWaitP0For15Cy
  {15,  0}, // #566 SwiftWaitP1For15Cy
  {15,  0}, // #567 SwiftWaitP2For15Cy
  { 9,  0}, // #568 SwiftWriteLM9Cy
  { 0,  0}, // #569 SwiftExt2xP0
  { 0,  0}, // #570 SwiftVLDMPerm2
  { 9,  0}, // #571 SwiftWriteLM9Cy
  { 1,  0}, // #572 SwiftWriteP01OneCycle
  { 0,  0}, // #573 SwiftExt2xP0
  { 0,  0}, // #574 SwiftVLDMPerm2
  { 9,  0}, // #575 SwiftWriteLM9Cy
  { 9,  0}, // #576 SwiftWriteLM9CyNo
  { 9,  0}, // #577 SwiftWriteLM9CyNo
  { 0,  0}, // #578 SwiftVLDMPerm3
  { 4,  0}, // #579 SwiftWrite3xP2FourCy
  { 9,  0}, // #580 SwiftWriteLM9Cy
  { 9,  0}, // #581 SwiftWriteLM9CyNo
  { 9,  0}, // #582 SwiftWriteLM9CyNo
  { 1,  0}, // #583 SwiftWriteP01OneCycle
  { 0,  0}, // #584 SwiftVLDMPerm3
  { 4,  0}, // #585 SwiftWrite3xP2FourCy
  {11,  0}, // #586 SwiftWriteLM11Cy
  {11,  0}, // #587 SwiftWriteLM11Cy
  {11,  0}, // #588 SwiftWriteLM11Cy
  {11,  0}, // #589 SwiftWriteLM11Cy
  { 0,  0}, // #590 SwiftExt2xP0
  { 0,  0}, // #591 SwiftVLDMPerm4
  { 4,  0}, // #592 SwiftWrite3xP2FourCy
  {11,  0}, // #593 SwiftWriteLM11Cy
  {11,  0}, // #594 SwiftWriteLM11Cy
  {11,  0}, // #595 SwiftWriteLM11Cy
  {11,  0}, // #596 SwiftWriteLM11Cy
  { 1,  0}, // #597 SwiftWriteP01OneCycle
  { 0,  0}, // #598 SwiftExt2xP0
  { 0,  0}, // #599 SwiftVLDMPerm4
  { 4,  0}, // #600 SwiftWrite3xP2FourCy
  { 6,  0}, // #601 SwiftWriteLM6Cy
  { 1,  0}, // #602 SwiftWriteP01OneCycle
  { 0,  0}, // #603 SwiftVLDMPerm2
  { 6,  0}, // #604 SwiftWriteLM6Cy
  { 6,  0}, // #605 SwiftWriteLM6Cy
  { 0,  0}, // #606 SwiftExt1xP0
  { 0,  0}, // #607 SwiftVLDMPerm2
  { 6,  0}, // #608 SwiftWriteLM6Cy
  { 6,  0}, // #609 SwiftWriteLM6Cy
  { 1,  0}, // #610 SwiftWriteP01OneCycle
  { 0,  0}, // #611 SwiftExt1xP0
  { 0,  0}, // #612 SwiftVLDMPerm2
  { 6,  0}, // #613 SwiftWriteLM6Cy
  { 1,  0}, // #614 SwiftWriteP01OneCycle
  { 6,  0}, // #615 SwiftWriteLM6Cy
  { 0,  0}, // #616 SwiftExt1xP0
  { 0,  0}, // #617 SwiftVLDMPerm2
  { 7,  0}, // #618 SwiftWriteLM7Cy
  { 8,  0}, // #619 SwiftWriteLM8Cy
  { 8,  0}, // #620 SwiftWriteLM8Cy
  { 0,  0}, // #621 SwiftExt1xP0
  { 0,  0}, // #622 SwiftVLDMPerm3
  { 7,  0}, // #623 SwiftWriteLM7Cy
  { 8,  0}, // #624 SwiftWriteLM8Cy
  { 8,  0}, // #625 SwiftWriteLM8Cy
  { 1,  0}, // #626 SwiftWriteP01OneCycle
  { 0,  0}, // #627 SwiftExt1xP0
  { 0,  0}, // #628 SwiftVLDMPerm3
  { 7,  0}, // #629 SwiftWriteLM7Cy
  { 1,  0}, // #630 SwiftWriteP01OneCycle
  { 8,  0}, // #631 SwiftWriteLM8Cy
  { 8,  0}, // #632 SwiftWriteLM8Cy
  { 0,  0}, // #633 SwiftExt1xP0
  { 0,  0}, // #634 SwiftVLDMPerm3
  { 8,  0}, // #635 SwiftWriteLM8Cy
  { 9,  0}, // #636 SwiftWriteLM9Cy
  {10,  0}, // #637 SwiftWriteLM10CyNo
  {10,  0}, // #638 SwiftWriteLM10CyNo
  { 0,  0}, // #639 SwiftExt1xP0
  { 0,  0}, // #640 SwiftVLDMPerm5
  { 8,  0}, // #641 SwiftWriteLM8Cy
  { 9,  0}, // #642 SwiftWriteLM9Cy
  {10,  0}, // #643 SwiftWriteLM10CyNo
  {10,  0}, // #644 SwiftWriteLM10CyNo
  { 1,  0}, // #645 SwiftWriteP01OneCycle
  { 0,  0}, // #646 SwiftExt1xP0
  { 0,  0}, // #647 SwiftVLDMPerm5
  { 8,  0}, // #648 SwiftWriteLM8Cy
  { 1,  0}, // #649 SwiftWriteP01OneCycle
  { 9,  0}, // #650 SwiftWriteLM9Cy
  {10,  0}, // #651 SwiftWriteLM10CyNo
  {10,  0}, // #652 SwiftWriteLM10CyNo
  { 0,  0}, // #653 SwiftExt1xP0
  { 0,  0}, // #654 SwiftVLDMPerm5
  { 3,  0}, // #655 SwiftWriteLM3Cy
  { 4,  0}, // #656 SwiftWriteLM4Cy
  { 0,  0}, // #657 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #658 SwiftWriteLM3Cy
  { 4,  0}, // #659 SwiftWriteLM4Cy
  { 5,  0}, // #660 SwiftWriteLM5Cy
  { 0,  0}, // #661 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #662 SwiftWriteLM3Cy
  { 4,  0}, // #663 SwiftWriteLM4Cy
  { 5,  0}, // #664 SwiftWriteLM5Cy
  { 6,  0}, // #665 SwiftWriteLM6Cy
  { 0,  0}, // #666 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #667 SwiftWriteLM3Cy
  { 4,  0}, // #668 SwiftWriteLM4Cy
  { 5,  0}, // #669 SwiftWriteLM5Cy
  { 6,  0}, // #670 SwiftWriteLM6Cy
  { 7,  0}, // #671 SwiftWriteLM7Cy
  { 0,  0}, // #672 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #673 SwiftWriteLM3Cy
  { 4,  0}, // #674 SwiftWriteLM4Cy
  { 5,  0}, // #675 SwiftWriteLM5Cy
  { 6,  0}, // #676 SwiftWriteLM6Cy
  { 7,  0}, // #677 SwiftWriteLM7Cy
  { 8,  0}, // #678 SwiftWriteLM8Cy
  { 0,  0}, // #679 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #680 SwiftWriteLM3Cy
  { 4,  0}, // #681 SwiftWriteLM4Cy
  { 5,  0}, // #682 SwiftWriteLM5Cy
  { 6,  0}, // #683 SwiftWriteLM6Cy
  { 7,  0}, // #684 SwiftWriteLM7Cy
  { 8,  0}, // #685 SwiftWriteLM8Cy
  { 9,  0}, // #686 SwiftWriteLM9Cy
  { 0,  0}, // #687 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #688 SwiftWriteLM3Cy
  { 4,  0}, // #689 SwiftWriteLM4Cy
  { 5,  0}, // #690 SwiftWriteLM5Cy
  { 6,  0}, // #691 SwiftWriteLM6Cy
  { 7,  0}, // #692 SwiftWriteLM7Cy
  { 8,  0}, // #693 SwiftWriteLM8Cy
  { 9,  0}, // #694 SwiftWriteLM9Cy
  {10,  0}, // #695 SwiftWriteLM10Cy
  { 0,  0}, // #696 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #697 SwiftWriteLM3Cy
  { 4,  0}, // #698 SwiftWriteLM4Cy
  { 5,  0}, // #699 SwiftWriteLM5Cy
  { 6,  0}, // #700 SwiftWriteLM6Cy
  { 7,  0}, // #701 SwiftWriteLM7Cy
  { 8,  0}, // #702 SwiftWriteLM8Cy
  { 9,  0}, // #703 SwiftWriteLM9Cy
  {10,  0}, // #704 SwiftWriteLM10Cy
  {11,  0}, // #705 SwiftWriteLM11Cy
  { 0,  0}, // #706 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #707 SwiftWriteLM3Cy
  { 4,  0}, // #708 SwiftWriteLM4Cy
  { 5,  0}, // #709 SwiftWriteLM5Cy
  { 6,  0}, // #710 SwiftWriteLM6Cy
  { 7,  0}, // #711 SwiftWriteLM7Cy
  { 8,  0}, // #712 SwiftWriteLM8Cy
  { 9,  0}, // #713 SwiftWriteLM9Cy
  {10,  0}, // #714 SwiftWriteLM10Cy
  {11,  0}, // #715 SwiftWriteLM11Cy
  {12,  0}, // #716 SwiftWriteLM12Cy
  { 0,  0}, // #717 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #718 SwiftWriteLM3Cy
  { 4,  0}, // #719 SwiftWriteLM4Cy
  { 5,  0}, // #720 SwiftWriteLM5Cy
  { 6,  0}, // #721 SwiftWriteLM6Cy
  { 7,  0}, // #722 SwiftWriteLM7Cy
  { 8,  0}, // #723 SwiftWriteLM8Cy
  { 9,  0}, // #724 SwiftWriteLM9Cy
  {10,  0}, // #725 SwiftWriteLM10Cy
  {11,  0}, // #726 SwiftWriteLM11Cy
  {12,  0}, // #727 SwiftWriteLM12Cy
  {13,  0}, // #728 SwiftWriteLM13Cy
  { 0,  0}, // #729 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #730 SwiftWriteLM3Cy
  { 4,  0}, // #731 SwiftWriteLM4Cy
  { 5,  0}, // #732 SwiftWriteLM5Cy
  { 6,  0}, // #733 SwiftWriteLM6Cy
  { 7,  0}, // #734 SwiftWriteLM7Cy
  { 8,  0}, // #735 SwiftWriteLM8Cy
  { 9,  0}, // #736 SwiftWriteLM9Cy
  {10,  0}, // #737 SwiftWriteLM10Cy
  {11,  0}, // #738 SwiftWriteLM11Cy
  {12,  0}, // #739 SwiftWriteLM12Cy
  {13,  0}, // #740 SwiftWriteLM13Cy
  {14,  0}, // #741 SwiftWriteLM14Cy
  { 0,  0}, // #742 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #743 SwiftWriteLM3Cy
  { 4,  0}, // #744 SwiftWriteLM4Cy
  { 5,  0}, // #745 SwiftWriteLM5Cy
  { 6,  0}, // #746 SwiftWriteLM6Cy
  { 7,  0}, // #747 SwiftWriteLM7Cy
  { 8,  0}, // #748 SwiftWriteLM8Cy
  { 9,  0}, // #749 SwiftWriteLM9Cy
  {10,  0}, // #750 SwiftWriteLM10Cy
  {11,  0}, // #751 SwiftWriteLM11Cy
  {12,  0}, // #752 SwiftWriteLM12Cy
  {13,  0}, // #753 SwiftWriteLM13Cy
  {14,  0}, // #754 SwiftWriteLM14Cy
  {15,  0}, // #755 SwiftWriteLM15Cy
  { 0,  0}, // #756 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #757 SwiftWriteLM3Cy
  { 4,  0}, // #758 SwiftWriteLM4Cy
  { 5,  0}, // #759 SwiftWriteLM5Cy
  { 6,  0}, // #760 SwiftWriteLM6Cy
  { 7,  0}, // #761 SwiftWriteLM7Cy
  { 8,  0}, // #762 SwiftWriteLM8Cy
  { 9,  0}, // #763 SwiftWriteLM9Cy
  {10,  0}, // #764 SwiftWriteLM10Cy
  {11,  0}, // #765 SwiftWriteLM11Cy
  {12,  0}, // #766 SwiftWriteLM12Cy
  {13,  0}, // #767 SwiftWriteLM13Cy
  {14,  0}, // #768 SwiftWriteLM14Cy
  {15,  0}, // #769 SwiftWriteLM15Cy
  {16,  0}, // #770 SwiftWriteLM16Cy
  { 0,  0}, // #771 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #772 SwiftWriteLM3Cy
  { 4,  0}, // #773 SwiftWriteLM4Cy
  { 5,  0}, // #774 SwiftWriteLM5Cy
  { 6,  0}, // #775 SwiftWriteLM6Cy
  { 7,  0}, // #776 SwiftWriteLM7Cy
  { 8,  0}, // #777 SwiftWriteLM8Cy
  { 9,  0}, // #778 SwiftWriteLM9Cy
  {10,  0}, // #779 SwiftWriteLM10Cy
  {11,  0}, // #780 SwiftWriteLM11Cy
  {12,  0}, // #781 SwiftWriteLM12Cy
  {13,  0}, // #782 SwiftWriteLM13Cy
  {14,  0}, // #783 SwiftWriteLM14Cy
  {15,  0}, // #784 SwiftWriteLM15Cy
  {16,  0}, // #785 SwiftWriteLM16Cy
  {17,  0}, // #786 SwiftWriteLM17Cy
  { 0,  0}, // #787 SwiftWriteLDMAddrNoWB
  { 3,  0}, // #788 SwiftWriteLM3Cy
  { 4,  0}, // #789 SwiftWriteLM4Cy
  { 5,  0}, // #790 SwiftWriteLM5Cy_SwiftWriteLM5CyNo
  { 6,  0}, // #791 SwiftWriteLM6Cy_SwiftWriteLM6CyNo
  { 7,  0}, // #792 SwiftWriteLM7Cy_SwiftWriteLM7CyNo
  { 8,  0}, // #793 SwiftWriteLM8Cy_SwiftWriteLM8CyNo
  { 9,  0}, // #794 SwiftWriteLM9Cy_SwiftWriteLM9CyNo
  {10,  0}, // #795 SwiftWriteLM10Cy_SwiftWriteLM10CyNo
  {11,  0}, // #796 SwiftWriteLM11Cy_SwiftWriteLM11CyNo
  {12,  0}, // #797 SwiftWriteLM12Cy_SwiftWriteLM12CyNo
  {13,  0}, // #798 SwiftWriteLM13Cy_SwiftWriteLM13CyNo
  {14,  0}, // #799 SwiftWriteLM14Cy_SwiftWriteLM14CyNo
  {15,  0}, // #800 SwiftWriteLM15Cy_SwiftWriteLM15CyNo
  {16,  0}, // #801 SwiftWriteLM16Cy_SwiftWriteLM16CyNo
  {17,  0}, // #802 SwiftWriteLM17Cy_SwiftWriteLM17CyNo
  {18,  0}, // #803 SwiftWriteLM18Cy_SwiftWriteLM18CyNo
  { 0,  0}, // #804 SwiftWriteLDMAddrNoWB
  { 1,  0}, // #805 SwiftWriteLDMAddrWB
  { 3,  0}, // #806 SwiftWriteLM3Cy
  { 4,  0}, // #807 SwiftWriteLM4Cy
  { 5,  0}, // #808 SwiftWriteLM5Cy
  { 1,  0}, // #809 SwiftWriteLDMAddrWB
  { 3,  0}, // #810 SwiftWriteLM3Cy
  { 4,  0}, // #811 SwiftWriteLM4Cy
  { 5,  0}, // #812 SwiftWriteLM5Cy
  { 6,  0}, // #813 SwiftWriteLM6Cy
  { 1,  0}, // #814 SwiftWriteLDMAddrWB
  { 3,  0}, // #815 SwiftWriteLM3Cy
  { 4,  0}, // #816 SwiftWriteLM4Cy
  { 5,  0}, // #817 SwiftWriteLM5Cy
  { 6,  0}, // #818 SwiftWriteLM6Cy
  { 7,  0}, // #819 SwiftWriteLM7Cy
  { 1,  0}, // #820 SwiftWriteLDMAddrWB
  { 3,  0}, // #821 SwiftWriteLM3Cy
  { 4,  0}, // #822 SwiftWriteLM4Cy
  { 5,  0}, // #823 SwiftWriteLM5Cy
  { 6,  0}, // #824 SwiftWriteLM6Cy
  { 7,  0}, // #825 SwiftWriteLM7Cy
  { 8,  0}, // #826 SwiftWriteLM8Cy
  { 1,  0}, // #827 SwiftWriteLDMAddrWB
  { 3,  0}, // #828 SwiftWriteLM3Cy
  { 4,  0}, // #829 SwiftWriteLM4Cy
  { 5,  0}, // #830 SwiftWriteLM5Cy
  { 6,  0}, // #831 SwiftWriteLM6Cy
  { 7,  0}, // #832 SwiftWriteLM7Cy
  { 8,  0}, // #833 SwiftWriteLM8Cy
  { 9,  0}, // #834 SwiftWriteLM9Cy
  { 1,  0}, // #835 SwiftWriteLDMAddrWB
  { 3,  0}, // #836 SwiftWriteLM3Cy
  { 4,  0}, // #837 SwiftWriteLM4Cy
  { 5,  0}, // #838 SwiftWriteLM5Cy
  { 6,  0}, // #839 SwiftWriteLM6Cy
  { 7,  0}, // #840 SwiftWriteLM7Cy
  { 8,  0}, // #841 SwiftWriteLM8Cy
  { 9,  0}, // #842 SwiftWriteLM9Cy
  {10,  0}, // #843 SwiftWriteLM10Cy
  { 1,  0}, // #844 SwiftWriteLDMAddrWB
  { 3,  0}, // #845 SwiftWriteLM3Cy
  { 4,  0}, // #846 SwiftWriteLM4Cy
  { 5,  0}, // #847 SwiftWriteLM5Cy
  { 6,  0}, // #848 SwiftWriteLM6Cy
  { 7,  0}, // #849 SwiftWriteLM7Cy
  { 8,  0}, // #850 SwiftWriteLM8Cy
  { 9,  0}, // #851 SwiftWriteLM9Cy
  {10,  0}, // #852 SwiftWriteLM10Cy
  {11,  0}, // #853 SwiftWriteLM11Cy
  { 1,  0}, // #854 SwiftWriteLDMAddrWB
  { 3,  0}, // #855 SwiftWriteLM3Cy
  { 4,  0}, // #856 SwiftWriteLM4Cy
  { 5,  0}, // #857 SwiftWriteLM5Cy
  { 6,  0}, // #858 SwiftWriteLM6Cy
  { 7,  0}, // #859 SwiftWriteLM7Cy
  { 8,  0}, // #860 SwiftWriteLM8Cy
  { 9,  0}, // #861 SwiftWriteLM9Cy
  {10,  0}, // #862 SwiftWriteLM10Cy
  {11,  0}, // #863 SwiftWriteLM11Cy
  {12,  0}, // #864 SwiftWriteLM12Cy
  { 1,  0}, // #865 SwiftWriteLDMAddrWB
  { 3,  0}, // #866 SwiftWriteLM3Cy
  { 4,  0}, // #867 SwiftWriteLM4Cy
  { 5,  0}, // #868 SwiftWriteLM5Cy
  { 6,  0}, // #869 SwiftWriteLM6Cy
  { 7,  0}, // #870 SwiftWriteLM7Cy
  { 8,  0}, // #871 SwiftWriteLM8Cy
  { 9,  0}, // #872 SwiftWriteLM9Cy
  {10,  0}, // #873 SwiftWriteLM10Cy
  {11,  0}, // #874 SwiftWriteLM11Cy
  {12,  0}, // #875 SwiftWriteLM12Cy
  {13,  0}, // #876 SwiftWriteLM13Cy
  { 1,  0}, // #877 SwiftWriteLDMAddrWB
  { 3,  0}, // #878 SwiftWriteLM3Cy
  { 4,  0}, // #879 SwiftWriteLM4Cy
  { 5,  0}, // #880 SwiftWriteLM5Cy
  { 6,  0}, // #881 SwiftWriteLM6Cy
  { 7,  0}, // #882 SwiftWriteLM7Cy
  { 8,  0}, // #883 SwiftWriteLM8Cy
  { 9,  0}, // #884 SwiftWriteLM9Cy
  {10,  0}, // #885 SwiftWriteLM10Cy
  {11,  0}, // #886 SwiftWriteLM11Cy
  {12,  0}, // #887 SwiftWriteLM12Cy
  {13,  0}, // #888 SwiftWriteLM13Cy
  {14,  0}, // #889 SwiftWriteLM14Cy
  { 1,  0}, // #890 SwiftWriteLDMAddrWB
  { 3,  0}, // #891 SwiftWriteLM3Cy
  { 4,  0}, // #892 SwiftWriteLM4Cy
  { 5,  0}, // #893 SwiftWriteLM5Cy
  { 6,  0}, // #894 SwiftWriteLM6Cy
  { 7,  0}, // #895 SwiftWriteLM7Cy
  { 8,  0}, // #896 SwiftWriteLM8Cy
  { 9,  0}, // #897 SwiftWriteLM9Cy
  {10,  0}, // #898 SwiftWriteLM10Cy
  {11,  0}, // #899 SwiftWriteLM11Cy
  {12,  0}, // #900 SwiftWriteLM12Cy
  {13,  0}, // #901 SwiftWriteLM13Cy
  {14,  0}, // #902 SwiftWriteLM14Cy
  {15,  0}, // #903 SwiftWriteLM15Cy
  { 1,  0}, // #904 SwiftWriteLDMAddrWB
  { 3,  0}, // #905 SwiftWriteLM3Cy
  { 4,  0}, // #906 SwiftWriteLM4Cy
  { 5,  0}, // #907 SwiftWriteLM5Cy
  { 6,  0}, // #908 SwiftWriteLM6Cy
  { 7,  0}, // #909 SwiftWriteLM7Cy
  { 8,  0}, // #910 SwiftWriteLM8Cy
  { 9,  0}, // #911 SwiftWriteLM9Cy
  {10,  0}, // #912 SwiftWriteLM10Cy
  {11,  0}, // #913 SwiftWriteLM11Cy
  {12,  0}, // #914 SwiftWriteLM12Cy
  {13,  0}, // #915 SwiftWriteLM13Cy
  {14,  0}, // #916 SwiftWriteLM14Cy
  {15,  0}, // #917 SwiftWriteLM15Cy
  {16,  0}, // #918 SwiftWriteLM16Cy
  { 1,  0}, // #919 SwiftWriteLDMAddrWB
  { 3,  0}, // #920 SwiftWriteLM3Cy
  { 4,  0}, // #921 SwiftWriteLM4Cy
  { 5,  0}, // #922 SwiftWriteLM5Cy
  { 6,  0}, // #923 SwiftWriteLM6Cy
  { 7,  0}, // #924 SwiftWriteLM7Cy
  { 8,  0}, // #925 SwiftWriteLM8Cy
  { 9,  0}, // #926 SwiftWriteLM9Cy
  {10,  0}, // #927 SwiftWriteLM10Cy
  {11,  0}, // #928 SwiftWriteLM11Cy
  {12,  0}, // #929 SwiftWriteLM12Cy
  {13,  0}, // #930 SwiftWriteLM13Cy
  {14,  0}, // #931 SwiftWriteLM14Cy
  {15,  0}, // #932 SwiftWriteLM15Cy
  {16,  0}, // #933 SwiftWriteLM16Cy
  {17,  0}, // #934 SwiftWriteLM17Cy
  { 1,  0}, // #935 SwiftWriteLDMAddrWB
  { 3,  0}, // #936 SwiftWriteLM3Cy
  { 4,  0}, // #937 SwiftWriteLM4Cy
  { 5,  0}, // #938 SwiftWriteLM5Cy_SwiftWriteLM5CyNo
  { 6,  0}, // #939 SwiftWriteLM6Cy_SwiftWriteLM6CyNo
  { 7,  0}, // #940 SwiftWriteLM7Cy_SwiftWriteLM7CyNo
  { 8,  0}, // #941 SwiftWriteLM8Cy_SwiftWriteLM8CyNo
  { 9,  0}, // #942 SwiftWriteLM9Cy_SwiftWriteLM9CyNo
  {10,  0}, // #943 SwiftWriteLM10Cy_SwiftWriteLM10CyNo
  {11,  0}, // #944 SwiftWriteLM11Cy_SwiftWriteLM11CyNo
  {12,  0}, // #945 SwiftWriteLM12Cy_SwiftWriteLM12CyNo
  {13,  0}, // #946 SwiftWriteLM13Cy_SwiftWriteLM13CyNo
  {14,  0}, // #947 SwiftWriteLM14Cy_SwiftWriteLM14CyNo
  {15,  0}, // #948 SwiftWriteLM15Cy_SwiftWriteLM15CyNo
  {16,  0}, // #949 SwiftWriteLM16Cy_SwiftWriteLM16CyNo
  {17,  0}, // #950 SwiftWriteLM17Cy_SwiftWriteLM17CyNo
  {18,  0}, // #951 SwiftWriteLM18Cy_SwiftWriteLM18CyNo
  { 1,  0}, // #952 SwiftWriteLDMAddrWB
  { 3,  0}, // #953 SwiftWriteLM3Cy
  { 4,  0}, // #954 SwiftWriteLM4Cy
  { 2,  0}, // #955 SwiftWriteP1TwoCycle
  { 1,  0}, // #956 SwiftWriteLDMAddrWB
  { 3,  0}, // #957 SwiftWriteLM3Cy
  { 4,  0}, // #958 SwiftWriteLM4Cy
  { 5,  0}, // #959 SwiftWriteLM5Cy
  { 2,  0}, // #960 SwiftWriteP1TwoCycle
  { 1,  0}, // #961 SwiftWriteLDMAddrWB
  { 3,  0}, // #962 SwiftWriteLM3Cy
  { 4,  0}, // #963 SwiftWriteLM4Cy
  { 5,  0}, // #964 SwiftWriteLM5Cy
  { 6,  0}, // #965 SwiftWriteLM6Cy
  { 2,  0}, // #966 SwiftWriteP1TwoCycle
  { 1,  0}, // #967 SwiftWriteLDMAddrWB
  { 3,  0}, // #968 SwiftWriteLM3Cy
  { 4,  0}, // #969 SwiftWriteLM4Cy
  { 5,  0}, // #970 SwiftWriteLM5Cy
  { 6,  0}, // #971 SwiftWriteLM6Cy
  { 7,  0}, // #972 SwiftWriteLM7Cy
  { 2,  0}, // #973 SwiftWriteP1TwoCycle
  { 1,  0}, // #974 SwiftWriteLDMAddrWB
  { 3,  0}, // #975 SwiftWriteLM3Cy
  { 4,  0}, // #976 SwiftWriteLM4Cy
  { 5,  0}, // #977 SwiftWriteLM5Cy
  { 6,  0}, // #978 SwiftWriteLM6Cy
  { 7,  0}, // #979 SwiftWriteLM7Cy
  { 8,  0}, // #980 SwiftWriteLM8Cy
  { 2,  0}, // #981 SwiftWriteP1TwoCycle
  { 1,  0}, // #982 SwiftWriteLDMAddrWB
  { 3,  0}, // #983 SwiftWriteLM3Cy
  { 4,  0}, // #984 SwiftWriteLM4Cy
  { 5,  0}, // #985 SwiftWriteLM5Cy
  { 6,  0}, // #986 SwiftWriteLM6Cy
  { 7,  0}, // #987 SwiftWriteLM7Cy
  { 8,  0}, // #988 SwiftWriteLM8Cy
  { 9,  0}, // #989 SwiftWriteLM9Cy
  { 2,  0}, // #990 SwiftWriteP1TwoCycle
  { 1,  0}, // #991 SwiftWriteLDMAddrWB
  { 3,  0}, // #992 SwiftWriteLM3Cy
  { 4,  0}, // #993 SwiftWriteLM4Cy
  { 5,  0}, // #994 SwiftWriteLM5Cy
  { 6,  0}, // #995 SwiftWriteLM6Cy
  { 7,  0}, // #996 SwiftWriteLM7Cy
  { 8,  0}, // #997 SwiftWriteLM8Cy
  { 9,  0}, // #998 SwiftWriteLM9Cy
  {10,  0}, // #999 SwiftWriteLM10Cy
  { 2,  0}, // #1000 SwiftWriteP1TwoCycle
  { 1,  0}, // #1001 SwiftWriteLDMAddrWB
  { 3,  0}, // #1002 SwiftWriteLM3Cy
  { 4,  0}, // #1003 SwiftWriteLM4Cy
  { 5,  0}, // #1004 SwiftWriteLM5Cy
  { 6,  0}, // #1005 SwiftWriteLM6Cy
  { 7,  0}, // #1006 SwiftWriteLM7Cy
  { 8,  0}, // #1007 SwiftWriteLM8Cy
  { 9,  0}, // #1008 SwiftWriteLM9Cy
  {10,  0}, // #1009 SwiftWriteLM10Cy
  {11,  0}, // #1010 SwiftWriteLM11Cy
  { 2,  0}, // #1011 SwiftWriteP1TwoCycle
  { 1,  0}, // #1012 SwiftWriteLDMAddrWB
  { 3,  0}, // #1013 SwiftWriteLM3Cy
  { 4,  0}, // #1014 SwiftWriteLM4Cy
  { 5,  0}, // #1015 SwiftWriteLM5Cy
  { 6,  0}, // #1016 SwiftWriteLM6Cy
  { 7,  0}, // #1017 SwiftWriteLM7Cy
  { 8,  0}, // #1018 SwiftWriteLM8Cy
  { 9,  0}, // #1019 SwiftWriteLM9Cy
  {10,  0}, // #1020 SwiftWriteLM10Cy
  {11,  0}, // #1021 SwiftWriteLM11Cy
  {12,  0}, // #1022 SwiftWriteLM12Cy
  { 2,  0}, // #1023 SwiftWriteP1TwoCycle
  { 1,  0}, // #1024 SwiftWriteLDMAddrWB
  { 3,  0}, // #1025 SwiftWriteLM3Cy
  { 4,  0}, // #1026 SwiftWriteLM4Cy
  { 5,  0}, // #1027 SwiftWriteLM5Cy
  { 6,  0}, // #1028 SwiftWriteLM6Cy
  { 7,  0}, // #1029 SwiftWriteLM7Cy
  { 8,  0}, // #1030 SwiftWriteLM8Cy
  { 9,  0}, // #1031 SwiftWriteLM9Cy
  {10,  0}, // #1032 SwiftWriteLM10Cy
  {11,  0}, // #1033 SwiftWriteLM11Cy
  {12,  0}, // #1034 SwiftWriteLM12Cy
  {13,  0}, // #1035 SwiftWriteLM13Cy
  { 2,  0}, // #1036 SwiftWriteP1TwoCycle
  { 1,  0}, // #1037 SwiftWriteLDMAddrWB
  { 3,  0}, // #1038 SwiftWriteLM3Cy
  { 4,  0}, // #1039 SwiftWriteLM4Cy
  { 5,  0}, // #1040 SwiftWriteLM5Cy
  { 6,  0}, // #1041 SwiftWriteLM6Cy
  { 7,  0}, // #1042 SwiftWriteLM7Cy
  { 8,  0}, // #1043 SwiftWriteLM8Cy
  { 9,  0}, // #1044 SwiftWriteLM9Cy
  {10,  0}, // #1045 SwiftWriteLM10Cy
  {11,  0}, // #1046 SwiftWriteLM11Cy
  {12,  0}, // #1047 SwiftWriteLM12Cy
  {13,  0}, // #1048 SwiftWriteLM13Cy
  {14,  0}, // #1049 SwiftWriteLM14Cy
  { 2,  0}, // #1050 SwiftWriteP1TwoCycle
  { 1,  0}, // #1051 SwiftWriteLDMAddrWB
  { 3,  0}, // #1052 SwiftWriteLM3Cy
  { 4,  0}, // #1053 SwiftWriteLM4Cy
  { 5,  0}, // #1054 SwiftWriteLM5Cy
  { 6,  0}, // #1055 SwiftWriteLM6Cy
  { 7,  0}, // #1056 SwiftWriteLM7Cy
  { 8,  0}, // #1057 SwiftWriteLM8Cy
  { 9,  0}, // #1058 SwiftWriteLM9Cy
  {10,  0}, // #1059 SwiftWriteLM10Cy
  {11,  0}, // #1060 SwiftWriteLM11Cy
  {12,  0}, // #1061 SwiftWriteLM12Cy
  {13,  0}, // #1062 SwiftWriteLM13Cy
  {14,  0}, // #1063 SwiftWriteLM14Cy
  {15,  0}, // #1064 SwiftWriteLM15Cy
  { 2,  0}, // #1065 SwiftWriteP1TwoCycle
  { 1,  0}, // #1066 SwiftWriteLDMAddrWB
  { 3,  0}, // #1067 SwiftWriteLM3Cy
  { 4,  0}, // #1068 SwiftWriteLM4Cy
  { 5,  0}, // #1069 SwiftWriteLM5Cy
  { 6,  0}, // #1070 SwiftWriteLM6Cy
  { 7,  0}, // #1071 SwiftWriteLM7Cy
  { 8,  0}, // #1072 SwiftWriteLM8Cy
  { 9,  0}, // #1073 SwiftWriteLM9Cy
  {10,  0}, // #1074 SwiftWriteLM10Cy
  {11,  0}, // #1075 SwiftWriteLM11Cy
  {12,  0}, // #1076 SwiftWriteLM12Cy
  {13,  0}, // #1077 SwiftWriteLM13Cy
  {14,  0}, // #1078 SwiftWriteLM14Cy
  {15,  0}, // #1079 SwiftWriteLM15Cy
  {16,  0}, // #1080 SwiftWriteLM16Cy
  { 2,  0}, // #1081 SwiftWriteP1TwoCycle
  { 1,  0}, // #1082 SwiftWriteLDMAddrWB
  { 3,  0}, // #1083 SwiftWriteLM3Cy
  { 4,  0}, // #1084 SwiftWriteLM4Cy
  { 5,  0}, // #1085 SwiftWriteLM5Cy
  { 6,  0}, // #1086 SwiftWriteLM6Cy
  { 7,  0}, // #1087 SwiftWriteLM7Cy
  { 8,  0}, // #1088 SwiftWriteLM8Cy
  { 9,  0}, // #1089 SwiftWriteLM9Cy
  {10,  0}, // #1090 SwiftWriteLM10Cy
  {11,  0}, // #1091 SwiftWriteLM11Cy
  {12,  0}, // #1092 SwiftWriteLM12Cy
  {13,  0}, // #1093 SwiftWriteLM13Cy
  {14,  0}, // #1094 SwiftWriteLM14Cy
  {15,  0}, // #1095 SwiftWriteLM15Cy
  {16,  0}, // #1096 SwiftWriteLM16Cy
  {17,  0}, // #1097 SwiftWriteLM17Cy
  { 2,  0}, // #1098 SwiftWriteP1TwoCycle
  { 1,  0}, // #1099 SwiftWriteLDMAddrWB
  { 3,  0}, // #1100 SwiftWriteLM3Cy
  { 4,  0}, // #1101 SwiftWriteLM4Cy
  { 5,  0}, // #1102 SwiftWriteLM5Cy_SwiftWriteLM5CyNo
  { 6,  0}, // #1103 SwiftWriteLM6Cy_SwiftWriteLM6CyNo
  { 7,  0}, // #1104 SwiftWriteLM7Cy_SwiftWriteLM7CyNo
  { 8,  0}, // #1105 SwiftWriteLM8Cy_SwiftWriteLM8CyNo
  { 9,  0}, // #1106 SwiftWriteLM9Cy_SwiftWriteLM9CyNo
  {10,  0}, // #1107 SwiftWriteLM10Cy_SwiftWriteLM10CyNo
  {11,  0}, // #1108 SwiftWriteLM11Cy_SwiftWriteLM11CyNo
  {12,  0}, // #1109 SwiftWriteLM12Cy_SwiftWriteLM12CyNo
  {13,  0}, // #1110 SwiftWriteLM13Cy_SwiftWriteLM13CyNo
  {14,  0}, // #1111 SwiftWriteLM14Cy_SwiftWriteLM14CyNo
  {15,  0}, // #1112 SwiftWriteLM15Cy_SwiftWriteLM15CyNo
  {16,  0}, // #1113 SwiftWriteLM16Cy_SwiftWriteLM16CyNo
  {17,  0}, // #1114 SwiftWriteLM17Cy_SwiftWriteLM17CyNo
  {18,  0}, // #1115 SwiftWriteLM18Cy_SwiftWriteLM18CyNo
  { 2,  0}, // #1116 SwiftWriteP1TwoCycle_SwiftWriteP01OneCycle
  { 9,  0}, // #1117 SwiftWriteLM9Cy
  {10,  0}, // #1118 SwiftWriteLM10Cy
  {13,  0}, // #1119 SwiftWriteLM13CyNo
  { 1,  0}, // #1120 SwiftWriteP01OneCycle
  { 0,  0}, // #1121 SwiftVLDMPerm3
  { 4,  0}, // #1122 SwiftWriteLM4Cy
  { 4,  0}, // #1123 SwiftWriteLM4CyNo
  { 4,  0}, // #1124 SwiftWriteLM4CyNo
  { 4,  0}, // #1125 SwiftWriteLM4CyNo
  { 9,  0}, // #1126 SwiftWriteLM9Cy
  {10,  0}, // #1127 SwiftWriteLM10Cy
  {13,  0}, // #1128 SwiftWriteLM13CyNo
  {14,  0}, // #1129 SwiftWriteLM14CyNo
  {17,  0}, // #1130 SwiftWriteLM17CyNo
  { 1,  0}, // #1131 SwiftWriteP01OneCycle
  { 0,  0}, // #1132 SwiftVLDMPerm5
  { 7,  0}, // #1133 SwiftWriteLM7Cy
  { 8,  0}, // #1134 SwiftWriteLM8Cy
  {10,  0}, // #1135 SwiftWriteLM10Cy
  {14,  0}, // #1136 SwiftWriteLM14CyNo
  {14,  0}, // #1137 SwiftWriteLM14CyNo
  {14,  0}, // #1138 SwiftWriteLM14CyNo
  { 1,  0}, // #1139 SwiftWriteP01OneCycle
  { 0,  0}, // #1140 SwiftVLDMPerm5
  { 9,  0}, // #1141 SwiftWriteLM9Cy
  {10,  0}, // #1142 SwiftWriteLM10Cy
  {13,  0}, // #1143 SwiftWriteLM13Cy
  {14,  0}, // #1144 SwiftWriteLM14CyNo
  {17,  0}, // #1145 SwiftWriteLM17CyNo
  {18,  0}, // #1146 SwiftWriteLM18CyNo
  {21,  0}, // #1147 SwiftWriteLM21CyNo
  { 1,  0}, // #1148 SwiftWriteP01OneCycle
  { 0,  0}, // #1149 SwiftVLDMPerm7
  { 7,  0}, // #1150 SwiftWriteLM7Cy
  { 8,  0}, // #1151 SwiftWriteLM8Cy
  {13,  0}, // #1152 SwiftWriteLM13Cy
  {13,  0}, // #1153 SwiftWriteLM13CyNo
  {13,  0}, // #1154 SwiftWriteLM13CyNo
  {13,  0}, // #1155 SwiftWriteLM13CyNo
  {13,  0}, // #1156 SwiftWriteLM13CyNo
  {13,  0}, // #1157 SwiftWriteLM13CyNo
  { 1,  0}, // #1158 SwiftWriteP01OneCycle
  { 0,  0}, // #1159 SwiftVLDMPerm2
  { 9,  0}, // #1160 SwiftWriteLM9Cy
  {10,  0}, // #1161 SwiftWriteLM10Cy
  {13,  0}, // #1162 SwiftWriteLM13Cy
  {14,  0}, // #1163 SwiftWriteLM14CyNo
  {17,  0}, // #1164 SwiftWriteLM17CyNo
  {18,  0}, // #1165 SwiftWriteLM18CyNo
  {21,  0}, // #1166 SwiftWriteLM21CyNo
  {22,  0}, // #1167 SwiftWriteLM22CyNo
  {25,  0}, // #1168 SwiftWriteLM25CyNo
  { 1,  0}, // #1169 SwiftWriteP01OneCycle
  { 0,  0}, // #1170 SwiftVLDMPerm9
  { 7,  0}, // #1171 SwiftWriteLM7Cy
  { 8,  0}, // #1172 SwiftWriteLM8Cy
  {10,  0}, // #1173 SwiftWriteLM10Cy
  {14,  0}, // #1174 SwiftWriteLM14Cy
  {14,  0}, // #1175 SwiftWriteLM14CyNo
  {14,  0}, // #1176 SwiftWriteLM14CyNo
  {14,  0}, // #1177 SwiftWriteLM14CyNo
  {14,  0}, // #1178 SwiftWriteLM14CyNo
  {14,  0}, // #1179 SwiftWriteLM14CyNo
  {14,  0}, // #1180 SwiftWriteLM14CyNo
  { 1,  0}, // #1181 SwiftWriteP01OneCycle
  { 0,  0}, // #1182 SwiftVLDMPerm5
  { 9,  0}, // #1183 SwiftWriteLM9Cy
  {10,  0}, // #1184 SwiftWriteLM10Cy
  {13,  0}, // #1185 SwiftWriteLM13Cy
  {14,  0}, // #1186 SwiftWriteLM14CyNo
  {17,  0}, // #1187 SwiftWriteLM17CyNo
  {18,  0}, // #1188 SwiftWriteLM18CyNo
  {21,  0}, // #1189 SwiftWriteLM21CyNo
  {22,  0}, // #1190 SwiftWriteLM22CyNo
  {21,  0}, // #1191 SwiftWriteLM21CyNo
  {22,  0}, // #1192 SwiftWriteLM22CyNo
  {25,  0}, // #1193 SwiftWriteLM25CyNo
  { 1,  0}, // #1194 SwiftWriteP01OneCycle
  { 0,  0}, // #1195 SwiftVLDMPerm9
  { 7,  0}, // #1196 SwiftWriteLM7Cy
  { 8,  0}, // #1197 SwiftWriteLM8Cy
  {11,  0}, // #1198 SwiftWriteLM11Cy
  {11,  0}, // #1199 SwiftWriteLM11Cy
  {11,  0}, // #1200 SwiftWriteLM11CyNo
  {11,  0}, // #1201 SwiftWriteLM11CyNo
  {11,  0}, // #1202 SwiftWriteLM11CyNo
  {11,  0}, // #1203 SwiftWriteLM11CyNo
  {11,  0}, // #1204 SwiftWriteLM11CyNo
  {11,  0}, // #1205 SwiftWriteLM11CyNo
  {11,  0}, // #1206 SwiftWriteLM11CyNo
  {11,  0}, // #1207 SwiftWriteLM11CyNo
  { 1,  0}, // #1208 SwiftWriteP01OneCycle
  { 0,  0}, // #1209 SwiftVLDMPerm3
  { 9,  0}, // #1210 SwiftWriteLM9Cy
  {10,  0}, // #1211 SwiftWriteLM10Cy
  {13,  0}, // #1212 SwiftWriteLM13Cy
  {14,  0}, // #1213 SwiftWriteLM14CyNo
  {17,  0}, // #1214 SwiftWriteLM17CyNo
  {18,  0}, // #1215 SwiftWriteLM18CyNo
  {21,  0}, // #1216 SwiftWriteLM21CyNo
  {22,  0}, // #1217 SwiftWriteLM22CyNo
  {21,  0}, // #1218 SwiftWriteLM21CyNo
  {22,  0}, // #1219 SwiftWriteLM22CyNo
  {21,  0}, // #1220 SwiftWriteLM21CyNo
  {22,  0}, // #1221 SwiftWriteLM22CyNo
  {25,  0}, // #1222 SwiftWriteLM25CyNo
  { 1,  0}, // #1223 SwiftWriteP01OneCycle
  { 0,  0}, // #1224 SwiftVLDMPerm9
  { 7,  0}, // #1225 SwiftWriteLM7Cy
  { 8,  0}, // #1226 SwiftWriteLM8Cy
  {10,  0}, // #1227 SwiftWriteLM10Cy
  {14,  0}, // #1228 SwiftWriteLM14Cy
  {14,  0}, // #1229 SwiftWriteLM14Cy
  {14,  0}, // #1230 SwiftWriteLM14CyNo
  {14,  0}, // #1231 SwiftWriteLM14CyNo
  {14,  0}, // #1232 SwiftWriteLM14CyNo
  {14,  0}, // #1233 SwiftWriteLM14CyNo
  {14,  0}, // #1234 SwiftWriteLM14CyNo
  {14,  0}, // #1235 SwiftWriteLM14CyNo
  {14,  0}, // #1236 SwiftWriteLM14CyNo
  { 1,  0}, // #1237 SwiftWriteP01OneCycle
  { 0,  0}, // #1238 SwiftVLDMPerm7
  { 9,  0}, // #1239 SwiftWriteLM9Cy
  {10,  0}, // #1240 SwiftWriteLM10Cy
  {13,  0}, // #1241 SwiftWriteLM13Cy
  {14,  0}, // #1242 SwiftWriteLM14Cy
  {17,  0}, // #1243 SwiftWriteLM17Cy
  {18,  0}, // #1244 SwiftWriteLM18CyNo
  {21,  0}, // #1245 SwiftWriteLM21CyNo
  {22,  0}, // #1246 SwiftWriteLM22CyNo
  {21,  0}, // #1247 SwiftWriteLM21CyNo
  {22,  0}, // #1248 SwiftWriteLM22CyNo
  {21,  0}, // #1249 SwiftWriteLM21CyNo
  {22,  0}, // #1250 SwiftWriteLM22CyNo
  {21,  0}, // #1251 SwiftWriteLM21CyNo
  {22,  0}, // #1252 SwiftWriteLM22CyNo
  {25,  0}, // #1253 SwiftWriteLM25CyNo
  { 1,  0}, // #1254 SwiftWriteP01OneCycle
  { 0,  0}, // #1255 SwiftVLDMPerm9
  { 7,  0}, // #1256 SwiftWriteLM7Cy
  {10,  0}, // #1257 SwiftWriteLM10Cy
  {11,  0}, // #1258 SwiftWriteLM11Cy
  {14,  0}, // #1259 SwiftWriteLM14Cy
  {15,  0}, // #1260 SwiftWriteLM15Cy
  {18,  0}, // #1261 SwiftWriteLM18CyNo
  {19,  0}, // #1262 SwiftWriteLM19CyNo
  {22,  0}, // #1263 SwiftWriteLM22CyNo
  {19,  0}, // #1264 SwiftWriteLM19CyNo
  {22,  0}, // #1265 SwiftWriteLM22CyNo
  {19,  0}, // #1266 SwiftWriteLM19CyNo
  {22,  0}, // #1267 SwiftWriteLM22CyNo
  {19,  0}, // #1268 SwiftWriteLM19CyNo
  {22,  0}, // #1269 SwiftWriteLM22CyNo
  {19,  0}, // #1270 SwiftWriteLM19CyNo
  {22,  0}, // #1271 SwiftWriteLM22CyNo
  { 1,  0}, // #1272 SwiftWriteP01OneCycle
  { 0,  0}, // #1273 SwiftVLDMPerm4
  { 7,  0}, // #1274 SwiftWriteLM7Cy
  { 8,  0}, // #1275 SwiftWriteLM8Cy
  {13,  0}, // #1276 SwiftWriteLM13Cy
  {13,  0}, // #1277 SwiftWriteLM13CyNo
  {13,  0}, // #1278 SwiftWriteLM13CyNo
  {13,  0}, // #1279 SwiftWriteLM13CyNo
  {13,  0}, // #1280 SwiftWriteLM13CyNo
  {13,  0}, // #1281 SwiftWriteLM13CyNo
  {13,  0}, // #1282 SwiftWriteLM13CyNo
  {13,  0}, // #1283 SwiftWriteLM13CyNo
  {13,  0}, // #1284 SwiftWriteLM13CyNo
  {13,  0}, // #1285 SwiftWriteLM13CyNo
  {13,  0}, // #1286 SwiftWriteLM13CyNo
  {13,  0}, // #1287 SwiftWriteLM13CyNo
  {13,  0}, // #1288 SwiftWriteLM13CyNo
  {13,  0}, // #1289 SwiftWriteLM13CyNo
  {13,  0}, // #1290 SwiftWriteLM13CyNo
  {13,  0}, // #1291 SwiftWriteLM13CyNo
  {13,  0}, // #1292 SwiftWriteLM13CyNo
  {13,  0}, // #1293 SwiftWriteLM13CyNo
  {13,  0}, // #1294 SwiftWriteLM13CyNo
  {13,  0}, // #1295 SwiftWriteLM13CyNo
  {13,  0}, // #1296 SwiftWriteLM13CyNo
  {13,  0}, // #1297 SwiftWriteLM13CyNo
  {13,  0}, // #1298 SwiftWriteLM13CyNo
  {13,  0}, // #1299 SwiftWriteLM13CyNo
  {13,  0}, // #1300 SwiftWriteLM13CyNo
  {13,  0}, // #1301 SwiftWriteLM13CyNo
  {13,  0}, // #1302 SwiftWriteLM13CyNo
  {13,  0}, // #1303 SwiftWriteLM13CyNo
  {13,  0}, // #1304 SwiftWriteLM13CyNo
  {13,  0}, // #1305 SwiftWriteLM13CyNo
  { 1,  0}, // #1306 SwiftWriteP01OneCycle
  { 0,  0}, // #1307 SwiftVLDMPerm2
  { 2,  0}, // #1308 SwiftWriteP01OneCycle
  { 4,  0}, // #1309 SwiftWriteLM4Cy
  { 4,  0}, // #1310 SwiftWriteLM4CyNo
  { 4,  0}, // #1311 SwiftWriteLM4CyNo
  { 4,  0}, // #1312 SwiftWriteLM4CyNo
  { 2,  0}, // #1313 SwiftWriteP01OneCycle
  { 9,  0}, // #1314 SwiftWriteLM9Cy
  {10,  0}, // #1315 SwiftWriteLM10Cy
  {13,  0}, // #1316 SwiftWriteLM13CyNo
  {14,  0}, // #1317 SwiftWriteLM14CyNo
  {17,  0}, // #1318 SwiftWriteLM17CyNo
  { 1,  0}, // #1319 SwiftWriteP01OneCycle
  { 0,  0}, // #1320 SwiftVLDMPerm5
  { 2,  0}, // #1321 SwiftWriteP01OneCycle
  { 7,  0}, // #1322 SwiftWriteLM7Cy
  { 8,  0}, // #1323 SwiftWriteLM8Cy
  {10,  0}, // #1324 SwiftWriteLM10Cy
  {14,  0}, // #1325 SwiftWriteLM14CyNo
  {14,  0}, // #1326 SwiftWriteLM14CyNo
  {14,  0}, // #1327 SwiftWriteLM14CyNo
  { 1,  0}, // #1328 SwiftWriteP01OneCycle
  { 0,  0}, // #1329 SwiftVLDMPerm5
  { 2,  0}, // #1330 SwiftWriteP01OneCycle
  { 9,  0}, // #1331 SwiftWriteLM9Cy
  {10,  0}, // #1332 SwiftWriteLM10Cy
  {13,  0}, // #1333 SwiftWriteLM13Cy
  {14,  0}, // #1334 SwiftWriteLM14CyNo
  {17,  0}, // #1335 SwiftWriteLM17CyNo
  {18,  0}, // #1336 SwiftWriteLM18CyNo
  {21,  0}, // #1337 SwiftWriteLM21CyNo
  { 1,  0}, // #1338 SwiftWriteP01OneCycle
  { 0,  0}, // #1339 SwiftVLDMPerm7
  { 2,  0}, // #1340 SwiftWriteP01OneCycle
  { 7,  0}, // #1341 SwiftWriteLM7Cy
  { 8,  0}, // #1342 SwiftWriteLM8Cy
  {13,  0}, // #1343 SwiftWriteLM13Cy
  {13,  0}, // #1344 SwiftWriteLM13CyNo
  {13,  0}, // #1345 SwiftWriteLM13CyNo
  {13,  0}, // #1346 SwiftWriteLM13CyNo
  {13,  0}, // #1347 SwiftWriteLM13CyNo
  {13,  0}, // #1348 SwiftWriteLM13CyNo
  { 1,  0}, // #1349 SwiftWriteP01OneCycle
  { 0,  0}, // #1350 SwiftVLDMPerm2
  { 2,  0}, // #1351 SwiftWriteP01OneCycle
  { 9,  0}, // #1352 SwiftWriteLM9Cy
  {10,  0}, // #1353 SwiftWriteLM10Cy
  {13,  0}, // #1354 SwiftWriteLM13Cy
  {14,  0}, // #1355 SwiftWriteLM14CyNo
  {17,  0}, // #1356 SwiftWriteLM17CyNo
  {18,  0}, // #1357 SwiftWriteLM18CyNo
  {21,  0}, // #1358 SwiftWriteLM21CyNo
  {22,  0}, // #1359 SwiftWriteLM22CyNo
  {25,  0}, // #1360 SwiftWriteLM25CyNo
  { 1,  0}, // #1361 SwiftWriteP01OneCycle
  { 0,  0}, // #1362 SwiftVLDMPerm9
  { 2,  0}, // #1363 SwiftWriteP01OneCycle
  { 7,  0}, // #1364 SwiftWriteLM7Cy
  { 8,  0}, // #1365 SwiftWriteLM8Cy
  {10,  0}, // #1366 SwiftWriteLM10Cy
  {14,  0}, // #1367 SwiftWriteLM14Cy
  {14,  0}, // #1368 SwiftWriteLM14CyNo
  {14,  0}, // #1369 SwiftWriteLM14CyNo
  {14,  0}, // #1370 SwiftWriteLM14CyNo
  {14,  0}, // #1371 SwiftWriteLM14CyNo
  {14,  0}, // #1372 SwiftWriteLM14CyNo
  {14,  0}, // #1373 SwiftWriteLM14CyNo
  { 1,  0}, // #1374 SwiftWriteP01OneCycle
  { 0,  0}, // #1375 SwiftVLDMPerm5
  { 2,  0}, // #1376 SwiftWriteP01OneCycle
  { 9,  0}, // #1377 SwiftWriteLM9Cy
  {10,  0}, // #1378 SwiftWriteLM10Cy
  {13,  0}, // #1379 SwiftWriteLM13Cy
  {14,  0}, // #1380 SwiftWriteLM14CyNo
  {17,  0}, // #1381 SwiftWriteLM17CyNo
  {18,  0}, // #1382 SwiftWriteLM18CyNo
  {21,  0}, // #1383 SwiftWriteLM21CyNo
  {22,  0}, // #1384 SwiftWriteLM22CyNo
  {21,  0}, // #1385 SwiftWriteLM21CyNo
  {22,  0}, // #1386 SwiftWriteLM22CyNo
  {25,  0}, // #1387 SwiftWriteLM25CyNo
  { 1,  0}, // #1388 SwiftWriteP01OneCycle
  { 0,  0}, // #1389 SwiftVLDMPerm9
  { 2,  0}, // #1390 SwiftWriteP01OneCycle
  { 7,  0}, // #1391 SwiftWriteLM7Cy
  { 8,  0}, // #1392 SwiftWriteLM8Cy
  {11,  0}, // #1393 SwiftWriteLM11Cy
  {11,  0}, // #1394 SwiftWriteLM11Cy
  {11,  0}, // #1395 SwiftWriteLM11CyNo
  {11,  0}, // #1396 SwiftWriteLM11CyNo
  {11,  0}, // #1397 SwiftWriteLM11CyNo
  {11,  0}, // #1398 SwiftWriteLM11CyNo
  {11,  0}, // #1399 SwiftWriteLM11CyNo
  {11,  0}, // #1400 SwiftWriteLM11CyNo
  {11,  0}, // #1401 SwiftWriteLM11CyNo
  {11,  0}, // #1402 SwiftWriteLM11CyNo
  { 1,  0}, // #1403 SwiftWriteP01OneCycle
  { 0,  0}, // #1404 SwiftVLDMPerm3
  { 2,  0}, // #1405 SwiftWriteP01OneCycle
  { 9,  0}, // #1406 SwiftWriteLM9Cy
  {10,  0}, // #1407 SwiftWriteLM10Cy
  {13,  0}, // #1408 SwiftWriteLM13Cy
  {14,  0}, // #1409 SwiftWriteLM14CyNo
  {17,  0}, // #1410 SwiftWriteLM17CyNo
  {18,  0}, // #1411 SwiftWriteLM18CyNo
  {21,  0}, // #1412 SwiftWriteLM21CyNo
  {22,  0}, // #1413 SwiftWriteLM22CyNo
  {21,  0}, // #1414 SwiftWriteLM21CyNo
  {22,  0}, // #1415 SwiftWriteLM22CyNo
  {21,  0}, // #1416 SwiftWriteLM21CyNo
  {22,  0}, // #1417 SwiftWriteLM22CyNo
  {25,  0}, // #1418 SwiftWriteLM25CyNo
  { 1,  0}, // #1419 SwiftWriteP01OneCycle
  { 0,  0}, // #1420 SwiftVLDMPerm9
  { 2,  0}, // #1421 SwiftWriteP01OneCycle
  { 7,  0}, // #1422 SwiftWriteLM7Cy
  { 8,  0}, // #1423 SwiftWriteLM8Cy
  {10,  0}, // #1424 SwiftWriteLM10Cy
  {14,  0}, // #1425 SwiftWriteLM14Cy
  {14,  0}, // #1426 SwiftWriteLM14Cy
  {14,  0}, // #1427 SwiftWriteLM14CyNo
  {14,  0}, // #1428 SwiftWriteLM14CyNo
  {14,  0}, // #1429 SwiftWriteLM14CyNo
  {14,  0}, // #1430 SwiftWriteLM14CyNo
  {14,  0}, // #1431 SwiftWriteLM14CyNo
  {14,  0}, // #1432 SwiftWriteLM14CyNo
  {14,  0}, // #1433 SwiftWriteLM14CyNo
  { 1,  0}, // #1434 SwiftWriteP01OneCycle
  { 0,  0}, // #1435 SwiftVLDMPerm7
  { 2,  0}, // #1436 SwiftWriteP01OneCycle
  { 9,  0}, // #1437 SwiftWriteLM9Cy
  {10,  0}, // #1438 SwiftWriteLM10Cy
  {13,  0}, // #1439 SwiftWriteLM13Cy
  {14,  0}, // #1440 SwiftWriteLM14Cy
  {17,  0}, // #1441 SwiftWriteLM17Cy
  {18,  0}, // #1442 SwiftWriteLM18CyNo
  {21,  0}, // #1443 SwiftWriteLM21CyNo
  {22,  0}, // #1444 SwiftWriteLM22CyNo
  {21,  0}, // #1445 SwiftWriteLM21CyNo
  {22,  0}, // #1446 SwiftWriteLM22CyNo
  {21,  0}, // #1447 SwiftWriteLM21CyNo
  {22,  0}, // #1448 SwiftWriteLM22CyNo
  {21,  0}, // #1449 SwiftWriteLM21CyNo
  {22,  0}, // #1450 SwiftWriteLM22CyNo
  {25,  0}, // #1451 SwiftWriteLM25CyNo
  { 1,  0}, // #1452 SwiftWriteP01OneCycle
  { 0,  0}, // #1453 SwiftVLDMPerm9
  { 2,  0}, // #1454 SwiftWriteP01OneCycle
  { 7,  0}, // #1455 SwiftWriteLM7Cy
  {10,  0}, // #1456 SwiftWriteLM10Cy
  {11,  0}, // #1457 SwiftWriteLM11Cy
  {14,  0}, // #1458 SwiftWriteLM14Cy
  {15,  0}, // #1459 SwiftWriteLM15Cy
  {18,  0}, // #1460 SwiftWriteLM18CyNo
  {19,  0}, // #1461 SwiftWriteLM19CyNo
  {22,  0}, // #1462 SwiftWriteLM22CyNo
  {19,  0}, // #1463 SwiftWriteLM19CyNo
  {22,  0}, // #1464 SwiftWriteLM22CyNo
  {19,  0}, // #1465 SwiftWriteLM19CyNo
  {22,  0}, // #1466 SwiftWriteLM22CyNo
  {19,  0}, // #1467 SwiftWriteLM19CyNo
  {22,  0}, // #1468 SwiftWriteLM22CyNo
  {19,  0}, // #1469 SwiftWriteLM19CyNo
  {22,  0}, // #1470 SwiftWriteLM22CyNo
  { 1,  0}, // #1471 SwiftWriteP01OneCycle
  { 0,  0}, // #1472 SwiftVLDMPerm4
  { 2,  0}, // #1473 SwiftWriteP01OneCycle
  { 7,  0}, // #1474 SwiftWriteLM7Cy
  { 8,  0}, // #1475 SwiftWriteLM8Cy
  {13,  0}, // #1476 SwiftWriteLM13Cy
  {13,  0}, // #1477 SwiftWriteLM13CyNo
  {13,  0}, // #1478 SwiftWriteLM13CyNo
  {13,  0}, // #1479 SwiftWriteLM13CyNo
  {13,  0}, // #1480 SwiftWriteLM13CyNo
  {13,  0}, // #1481 SwiftWriteLM13CyNo
  {13,  0}, // #1482 SwiftWriteLM13CyNo
  {13,  0}, // #1483 SwiftWriteLM13CyNo
  {13,  0}, // #1484 SwiftWriteLM13CyNo
  {13,  0}, // #1485 SwiftWriteLM13CyNo
  {13,  0}, // #1486 SwiftWriteLM13CyNo
  {13,  0}, // #1487 SwiftWriteLM13CyNo
  {13,  0}, // #1488 SwiftWriteLM13CyNo
  {13,  0}, // #1489 SwiftWriteLM13CyNo
  {13,  0}, // #1490 SwiftWriteLM13CyNo
  {13,  0}, // #1491 SwiftWriteLM13CyNo
  {13,  0}, // #1492 SwiftWriteLM13CyNo
  {13,  0}, // #1493 SwiftWriteLM13CyNo
  {13,  0}, // #1494 SwiftWriteLM13CyNo
  {13,  0}, // #1495 SwiftWriteLM13CyNo
  {13,  0}, // #1496 SwiftWriteLM13CyNo
  {13,  0}, // #1497 SwiftWriteLM13CyNo
  {13,  0}, // #1498 SwiftWriteLM13CyNo
  {13,  0}, // #1499 SwiftWriteLM13CyNo
  {13,  0}, // #1500 SwiftWriteLM13CyNo
  {13,  0}, // #1501 SwiftWriteLM13CyNo
  {13,  0}, // #1502 SwiftWriteLM13CyNo
  {13,  0}, // #1503 SwiftWriteLM13CyNo
  {13,  0}, // #1504 SwiftWriteLM13CyNo
  {13,  0}, // #1505 SwiftWriteLM13CyNo
  { 1,  0}, // #1506 SwiftWriteP01OneCycle
  { 0,  0} // #1507 SwiftVLDMPerm2
}; // ARMWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry ARMReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
  {0, 40,  1}, // #1
  {0, 41,  1}, // #2
  {0, 42,  1}, // #3
  {0, 43,  1}, // #4
  {0, 44,  1}, // #5
  {0, 45,  1}, // #6
  {0, 46,  1}, // #7
  {0, 47,  1}, // #8
  {0, 48,  1}, // #9
  {0, 49,  1}, // #10
  {0, 50,  1}, // #11
  {0, 51,  1}, // #12
  {0, 52,  1}, // #13
  {0, 53,  1}, // #14
  {0, 54,  1}, // #15
  {0, 55,  1}, // #16
  {0, 56,  1}, // #17
  {0, 57,  1}, // #18
  {0, 83,  1}, // #19
  {0, 84,  1}, // #20
  {0, 107,  1}, // #21
  {0, 40,  1}, // #22
  {0, 41,  1}, // #23
  {0, 42,  1}, // #24
  {0, 43,  1}, // #25
  {0, 44,  1}, // #26
  {0, 45,  1}, // #27
  {0, 46,  1}, // #28
  {0, 47,  1}, // #29
  {0, 48,  1}, // #30
  {0, 49,  1}, // #31
  {0, 50,  1}, // #32
  {0, 51,  1}, // #33
  {0, 52,  1}, // #34
  {0, 53,  1}, // #35
  {0, 54,  1}, // #36
  {0, 55,  1}, // #37
  {0, 56,  1}, // #38
  {0, 57,  1}, // #39
  {0, 83,  1}, // #40
  {0, 84,  1}, // #41
  {0, 107,  1}, // #42
  {1, 40,  1}, // #43
  {1, 41,  1}, // #44
  {1, 42,  1}, // #45
  {1, 43,  1}, // #46
  {1, 44,  1}, // #47
  {1, 45,  1}, // #48
  {1, 46,  1}, // #49
  {1, 47,  1}, // #50
  {1, 48,  1}, // #51
  {1, 49,  1}, // #52
  {1, 50,  1}, // #53
  {1, 51,  1}, // #54
  {1, 52,  1}, // #55
  {1, 53,  1}, // #56
  {1, 54,  1}, // #57
  {1, 55,  1}, // #58
  {1, 56,  1}, // #59
  {1, 57,  1}, // #60
  {1, 83,  1}, // #61
  {1, 84,  1}, // #62
  {1, 107,  1}, // #63
  {0,  0,  2}, // #64
  {1,  0,  1}, // #65
  {0,  0,  1}, // #66
  {0,  0,  1}, // #67
  {1,  0,  1}, // #68
  {0,  0,  2}, // #69
  {1,  0,  1}, // #70
  {2,  0,  1}, // #71
  {0,  0,  1}, // #72
  {1,  0,  1}, // #73
  {2,  0,  2}, // #74
  {0,  0,  1}, // #75
  {1,  0,  1}, // #76
  {2,  0,  2}, // #77
  {3,  0,  2}, // #78
  {1,  0,  1}, // #79
  {2,  0,  1}, // #80
  {3,  0,  2}, // #81
  {1,  0,  1}, // #82
  {2,  0,  1}, // #83
  {3,  0,  2}, // #84
  {4,  0,  2}, // #85
  {0,  0,  0}, // #86
  {1,  0,  0}, // #87
  {0,  0,  0}, // #88
  {1,  0,  0}, // #89
  {2,  0,  4}, // #90
  {3,  0,  3}, // #91
  {0,  0,  0}, // #92
  {1,  0,  0}, // #93
  {2,  0,  2}, // #94
  {0,  0,  0}, // #95
  {1,  0,  0}, // #96
  {2,  0,  0} // #97
}; // ARMReadAdvanceTable

// {Name, NumMicroOps, BeginGroup, EndGroup, WriteProcResIdx,#, WriteLatencyIdx,#, ReadAdvanceIdx,#}
static const llvm::MCSchedClassDesc CortexA9ModelSchedClasses[] = {
  {DBGFIELD("InvalidSchedClass")  65535, 0, 0,  0, 0,  0, 0,  0, 0},
  {DBGFIELD("IIC_iALUi_WriteALU_ReadALU") 1, 0, 0,  1, 1,  1, 1,  1, 21}, // #1
  {DBGFIELD("IIC_iALUr_WriteALU_ReadALU_ReadALU") 1, 0, 0,  1, 1,  1, 1, 22, 42}, // #2
  {DBGFIELD("IIC_iALUsr_WriteALUsi_ReadALU") 1, 0, 0,  1, 1,  2, 1,  1, 21}, // #3
  {DBGFIELD("IIC_iALUsr_WriteALUsr_ReadALUsr") 1, 0, 0,  1, 1,  3, 1,  1, 21}, // #4
  {DBGFIELD("IIC_iALUsr_WriteALUSsr_ReadALUsr") 1, 0, 0,  1, 1,  3, 1,  1, 21}, // #5
  {DBGFIELD("IIC_iBITi_WriteALU_ReadALU") 1, 0, 0,  1, 1,  1, 1,  1, 21}, // #6
  {DBGFIELD("IIC_iBITr_WriteALU_ReadALU_ReadALU") 1, 0, 0,  1, 1,  1, 1, 22, 42}, // #7
  {DBGFIELD("IIC_iBITsr_WriteALUsi_ReadALU") 1, 0, 0,  1, 1,  2, 1,  1, 21}, // #8
  {DBGFIELD("IIC_iBITsr_WriteALUsr_ReadALUsr") 1, 0, 0,  1, 1,  3, 1,  1, 21}, // #9
  {DBGFIELD("IIC_Br_WriteBr")     1, 0, 0,  2, 1,  1, 1,  0, 0}, // #10
  {DBGFIELD("IIC_iUNAsi")         1, 0, 0,  1, 1,  2, 1,  0, 0}, // #11
  {DBGFIELD("IIC_Br_WriteBrL")    1, 0, 0,  2, 1,  1, 1,  0, 0}, // #12
  {DBGFIELD("WriteBrL")           1, 0, 0,  2, 1,  1, 1,  0, 0}, // #13
  {DBGFIELD("IIC_Br_WriteBrTbl")  1, 0, 0,  2, 1,  1, 1,  0, 0}, // #14
  {DBGFIELD("WriteBr")            1, 0, 0,  2, 1,  1, 1,  0, 0}, // #15
  {DBGFIELD("IIC_iUNAr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #16
  {DBGFIELD("IIC_iCMPi_WriteCMP_ReadALU") 1, 0, 0,  1, 1,  1, 1,  1, 21}, // #17
  {DBGFIELD("IIC_iCMPr_WriteCMP_ReadALU_ReadALU") 1, 0, 0,  1, 1,  1, 1, 22, 42}, // #18
  {DBGFIELD("IIC_iCMPsr_WriteCMPsi_ReadALU") 1, 0, 0,  1, 1,  1, 1,  1, 21}, // #19
  {DBGFIELD("IIC_iCMPsr_WriteCMPsr_ReadALU") 1, 0, 0,  1, 1,  1, 1,  1, 21}, // #20
  {DBGFIELD("IIC_fpUNA64")        1, 0, 0,  3, 2,  1, 1,  0, 0}, // #21
  {DBGFIELD("IIC_fpUNA32")        1, 0, 0,  3, 2,  1, 1,  0, 0}, // #22
  {DBGFIELD("IIC_fpSTAT")         1, 0, 0,  3, 2,  1, 1,  0, 0}, // #23
  {DBGFIELD("IIC_iLoad_m")        65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #24
  {DBGFIELD("IIC_iLoad_mu")       65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #25
  {DBGFIELD("IIC_iLoad_mBr")      65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #26
  {DBGFIELD("IIC_iLoad_bh_ru")    1, 0, 0,  5, 2,  4, 2,  0, 0}, // #27
  {DBGFIELD("IIC_iLoad_bh_iu")    1, 0, 0,  5, 2,  4, 2,  0, 0}, // #28
  {DBGFIELD("IIC_iLoad_bh_r")     1, 0, 0,  5, 2,  4, 2,  0, 0}, // #29
  {DBGFIELD("IIC_iLoad_bh_si")    1, 0, 0,  5, 2,  6, 2,  0, 0}, // #30
  {DBGFIELD("IIC_iLoad_d_r")      1, 0, 0,  7, 2,  8, 3,  0, 0}, // #31
  {DBGFIELD("IIC_iLoad_d_ru")     1, 0, 0,  7, 2,  8, 3,  0, 0}, // #32
  {DBGFIELD("IIC_iLoad_i")        1, 0, 0,  7, 2, 11, 2,  0, 0}, // #33
  {DBGFIELD("IIC_iLoadiALU")      2, 0, 0,  9, 3, 13, 3,  0, 0}, // #34
  {DBGFIELD("IIC_iLoad_ru")       1, 0, 0,  7, 2, 11, 2,  0, 0}, // #35
  {DBGFIELD("IIC_iLoad_iu")       1, 0, 0,  7, 2, 11, 2,  0, 0}, // #36
  {DBGFIELD("IIC_iLoad_r")        1, 0, 0,  7, 2, 11, 2,  0, 0}, // #37
  {DBGFIELD("IIC_iLoad_si")       1, 0, 0,  7, 2, 16, 2,  0, 0}, // #38
  {DBGFIELD("IIC_iMAC32")         1, 0, 0, 12, 2, 18, 2,  0, 0}, // #39
  {DBGFIELD("IIC_iCMOVi_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #40
  {DBGFIELD("IIC_iMOVi_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #41
  {DBGFIELD("IIC_iCMOVix2")       2, 0, 0, 14, 1,  2, 1,  0, 0}, // #42
  {DBGFIELD("IIC_iCMOVr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #43
  {DBGFIELD("IIC_iCMOVsr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #44
  {DBGFIELD("IIC_iMOVix2addpc")   3, 0, 0, 12, 1,  3, 1,  0, 0}, // #45
  {DBGFIELD("IIC_iMOVix2ld")      3, 0, 0, 15, 2, 20, 1,  0, 0}, // #46
  {DBGFIELD("IIC_iMOVix2")        2, 0, 0, 14, 1,  2, 1,  0, 0}, // #47
  {DBGFIELD("IIC_iMOVr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #48
  {DBGFIELD("IIC_iMOVsr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #49
  {DBGFIELD("IIC_iMOVsi_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #50
  {DBGFIELD("IIC_iMUL32")         1, 0, 0, 12, 2, 18, 2,  0, 0}, // #51
  {DBGFIELD("IIC_iMVNi_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #52
  {DBGFIELD("IIC_iMVNr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #53
  {DBGFIELD("IIC_iMVNsr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #54
  {DBGFIELD("IIC_iALUr_WriteALU_ReadALU") 1, 0, 0,  1, 1,  1, 1,  1, 21}, // #55
  {DBGFIELD("IIC_iStore_r")       1, 0, 0,  7, 2, 14, 2,  0, 0}, // #56
  {DBGFIELD("IIC_iStore_bh_r")    1, 0, 0,  5, 2, 21, 2,  0, 0}, // #57
  {DBGFIELD("IIC_iALUsi_WriteALUsi_ReadALU") 1, 0, 0,  1, 1,  2, 1,  1, 21}, // #58
  {DBGFIELD("IIC_iBITsi_WriteALUsi_ReadALU") 1, 0, 0,  1, 1,  2, 1,  1, 21}, // #59
  {DBGFIELD("IIC_Preload_WritePreLd") 1, 0, 0,  0, 0,  1, 1,  0, 0}, // #60
  {DBGFIELD("IIC_iDIV")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #61
  {DBGFIELD("IIC_iMAC16")         1, 0, 0, 17, 2, 23, 2,  0, 0}, // #62
  {DBGFIELD("IIC_iMAC64")         1, 0, 0, 12, 2, 18, 2,  0, 0}, // #63
  {DBGFIELD("IIC_iMUL16")         1, 0, 0, 17, 2, 23, 2,  0, 0}, // #64
  {DBGFIELD("IIC_iMUL64")         1, 0, 0, 12, 2, 18, 2,  0, 0}, // #65
  {DBGFIELD("IIC_iStore_m")       65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #66
  {DBGFIELD("IIC_iStore_mu")      65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #67
  {DBGFIELD("IIC_iStore_bh_ru")   1, 0, 0,  5, 2, 21, 2,  0, 0}, // #68
  {DBGFIELD("IIC_iStore_bh_iu")   1, 0, 0,  5, 2, 21, 2,  0, 0}, // #69
  {DBGFIELD("IIC_iStore_ru")      1, 0, 0,  7, 2, 14, 2,  0, 0}, // #70
  {DBGFIELD("IIC_iStore_bh_si")   1, 0, 0, 19, 2, 25, 2,  0, 0}, // #71
  {DBGFIELD("IIC_iStore_d_r")     1, 0, 0,  7, 2, 14, 2,  0, 0}, // #72
  {DBGFIELD("IIC_iStore_d_ru")    1, 0, 0,  7, 2, 14, 2,  0, 0}, // #73
  {DBGFIELD("IIC_iStore_iu")      1, 0, 0,  7, 2, 14, 2,  0, 0}, // #74
  {DBGFIELD("IIC_iStore_si")      1, 0, 0,  5, 2, 21, 2,  0, 0}, // #75
  {DBGFIELD("IIC_Br")             1, 0, 0,  2, 1,  1, 1,  0, 0}, // #76
  {DBGFIELD("IIC_iEXTAr_WriteALUsr") 1, 0, 0,  1, 1,  3, 1,  0, 0}, // #77
  {DBGFIELD("IIC_iEXTr_WriteALUsi") 1, 0, 0,  1, 1,  2, 1,  0, 0}, // #78
  {DBGFIELD("IIC_iTSTi_WriteCMP_ReadALU") 1, 0, 0,  1, 1,  1, 1,  1, 21}, // #79
  {DBGFIELD("IIC_iTSTr_WriteCMP_ReadALU_ReadALU") 1, 0, 0,  1, 1,  1, 1, 22, 42}, // #80
  {DBGFIELD("IIC_iTSTsr_WriteCMPsi_ReadALU") 1, 0, 0,  1, 1,  1, 1,  1, 21}, // #81
  {DBGFIELD("IIC_iTSTsr_WriteCMPsr_ReadALU") 1, 0, 0,  1, 1,  1, 1,  1, 21}, // #82
  {DBGFIELD("WriteALU_ReadALU_ReadALU") 1, 0, 0,  1, 1,  1, 1, 22, 42}, // #83
  {DBGFIELD("IIC_VABAD")          1, 0, 0,  3, 2, 27, 1, 64, 2}, // #84
  {DBGFIELD("IIC_VABAQ")          1, 0, 0,  3, 2, 27, 1, 64, 2}, // #85
  {DBGFIELD("IIC_VSUBi4Q")        1, 0, 0,  3, 2, 18, 1, 66, 1}, // #86
  {DBGFIELD("IIC_VBIND")          1, 0, 0,  3, 2, 19, 1, 67, 2}, // #87
  {DBGFIELD("IIC_VBINQ")          1, 0, 0,  3, 2, 27, 1, 67, 2}, // #88
  {DBGFIELD("IIC_VSUBi4D")        1, 0, 0,  3, 2, 18, 1, 66, 1}, // #89
  {DBGFIELD("IIC_VUNAD")          1, 0, 0,  3, 2, 19, 1, 66, 1}, // #90
  {DBGFIELD("IIC_VUNAQ")          1, 0, 0,  3, 2, 27, 1, 66, 1}, // #91
  {DBGFIELD("IIC_VUNAiQ")         1, 0, 0,  3, 2, 18, 1, 66, 1}, // #92
  {DBGFIELD("IIC_VUNAiD")         1, 0, 0,  3, 2, 18, 1, 66, 1}, // #93
  {DBGFIELD("IIC_fpALU64")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #94
  {DBGFIELD("IIC_VBINi4D")        1, 0, 0,  3, 2, 18, 1, 67, 2}, // #95
  {DBGFIELD("IIC_VSHLiD")         1, 0, 0,  3, 2,  3, 1,  0, 0}, // #96
  {DBGFIELD("IIC_fpALU32")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #97
  {DBGFIELD("IIC_VSUBiD")         1, 0, 0,  3, 2,  3, 1, 66, 1}, // #98
  {DBGFIELD("IIC_VBINiQ")         1, 0, 0,  3, 2,  3, 1, 67, 2}, // #99
  {DBGFIELD("IIC_VBINiD")         1, 0, 0,  3, 2,  3, 1, 67, 2}, // #100
  {DBGFIELD("IIC_VMOVImm")        1, 0, 0,  3, 2,  3, 1,  0, 0}, // #101
  {DBGFIELD("IIC_VCNTiD")         1, 0, 0,  3, 2,  3, 1, 66, 1}, // #102
  {DBGFIELD("IIC_VCNTiQ")         1, 0, 0, 21, 2, 18, 1, 64, 1}, // #103
  {DBGFIELD("IIC_fpCMP64")        1, 0, 0,  3, 2,  1, 1,  0, 0}, // #104
  {DBGFIELD("IIC_fpCMP32")        1, 0, 0,  3, 2,  1, 1,  0, 0}, // #105
  {DBGFIELD("IIC_fpCVTSH")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #106
  {DBGFIELD("IIC_fpCVTHS")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #107
  {DBGFIELD("IIC_fpCVTDS")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #108
  {DBGFIELD("IIC_fpCVTSD")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #109
  {DBGFIELD("IIC_fpDIV64")        1, 0, 0,  3, 2, 28, 1,  0, 0}, // #110
  {DBGFIELD("IIC_fpDIV32")        1, 0, 0,  3, 2, 29, 1,  0, 0}, // #111
  {DBGFIELD("IIC_VMOVIS")         1, 0, 0,  3, 2,  1, 1,  0, 0}, // #112
  {DBGFIELD("IIC_VMOVD")          1, 0, 0,  3, 2,  2, 1,  0, 0}, // #113
  {DBGFIELD("IIC_VMOVQ")          1, 0, 0,  3, 2,  2, 1,  0, 0}, // #114
  {DBGFIELD("IIC_VEXTD")          2, 0, 0, 23, 2, 30, 2,  0, 0}, // #115
  {DBGFIELD("IIC_VEXTQ")          2, 0, 0, 23, 2, 23, 2, 65, 1}, // #116
  {DBGFIELD("IIC_fpFMAC64")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #117
  {DBGFIELD("IIC_fpFMAC32")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #118
  {DBGFIELD("IIC_VFMACD")         1, 0, 0,  3, 2, 32, 1, 64, 2}, // #119
  {DBGFIELD("IIC_VFMACQ")         1, 0, 0,  3, 2, 33, 1, 64, 2}, // #120
  {DBGFIELD("IIC_VMOVSI")         1, 0, 0,  3, 2,  2, 1,  0, 0}, // #121
  {DBGFIELD("IIC_VBINi4Q")        1, 0, 0,  3, 2, 18, 1, 67, 2}, // #122
  {DBGFIELD("IIC_VLD1dup")        1, 0, 0, 25, 3, 34, 2,  0, 0}, // #123
  {DBGFIELD("IIC_VLD1dupu")       1, 0, 0, 25, 3, 34, 2,  0, 0}, // #124
  {DBGFIELD("IIC_VLD1ln")         1, 0, 0, 28, 3, 36, 2,  0, 0}, // #125
  {DBGFIELD("IIC_VLD1lnu")        1, 0, 0, 28, 3, 36, 2,  0, 0}, // #126
  {DBGFIELD("IIC_VLD1")           1, 0, 0, 31, 3, 14, 2,  0, 0}, // #127
  {DBGFIELD("IIC_VLD1x4")         1, 0, 0, 34, 3, 30, 2,  0, 0}, // #128
  {DBGFIELD("IIC_VLD1x2u")        1, 0, 0, 31, 3, 14, 2,  0, 0}, // #129
  {DBGFIELD("IIC_VLD1x3")         1, 0, 0, 34, 3, 30, 2,  0, 0}, // #130
  {DBGFIELD("IIC_VLD1u")          1, 0, 0, 31, 3, 14, 2,  0, 0}, // #131
  {DBGFIELD("IIC_VLD1x2")         1, 0, 0, 31, 3, 14, 2,  0, 0}, // #132
  {DBGFIELD("IIC_VLD2dup")        1, 0, 0, 25, 3, 34, 2,  0, 0}, // #133
  {DBGFIELD("IIC_VLD2dupu")       1, 0, 0, 25, 3, 34, 2,  0, 0}, // #134
  {DBGFIELD("IIC_VLD2ln")         1, 0, 0, 28, 3, 36, 2,  0, 0}, // #135
  {DBGFIELD("IIC_VLD2lnu")        1, 0, 0, 28, 3, 36, 2,  0, 0}, // #136
  {DBGFIELD("IIC_VLD2")           1, 0, 0, 25, 3, 34, 2,  0, 0}, // #137
  {DBGFIELD("IIC_VLD2u")          1, 0, 0, 25, 3, 34, 2,  0, 0}, // #138
  {DBGFIELD("IIC_VLD2x2")         1, 0, 0, 28, 3, 36, 2,  0, 0}, // #139
  {DBGFIELD("IIC_VLD2x2u")        1, 0, 0, 28, 3, 36, 2,  0, 0}, // #140
  {DBGFIELD("IIC_VLD3dup")        1, 0, 0, 37, 3, 38, 2,  0, 0}, // #141
  {DBGFIELD("IIC_VLD3dupu")       1, 0, 0, 37, 3, 38, 2,  0, 0}, // #142
  {DBGFIELD("IIC_VLD3ln")         1, 0, 0, 40, 3, 40, 2,  0, 0}, // #143
  {DBGFIELD("IIC_VLD3lnu")        1, 0, 0, 40, 3, 40, 2,  0, 0}, // #144
  {DBGFIELD("IIC_VLD3")           1, 0, 0, 37, 3, 38, 2,  0, 0}, // #145
  {DBGFIELD("IIC_VLD3u")          1, 0, 0, 37, 3, 38, 2,  0, 0}, // #146
  {DBGFIELD("IIC_VLD4dup")        1, 0, 0, 34, 3, 30, 2,  0, 0}, // #147
  {DBGFIELD("IIC_VLD4dupu")       1, 0, 0, 34, 3, 30, 2,  0, 0}, // #148
  {DBGFIELD("IIC_VLD4ln")         1, 0, 0, 43, 3, 42, 2,  0, 0}, // #149
  {DBGFIELD("IIC_VLD4lnu")        1, 0, 0, 43, 3, 42, 2,  0, 0}, // #150
  {DBGFIELD("IIC_VLD4")           1, 0, 0, 43, 3, 42, 2,  0, 0}, // #151
  {DBGFIELD("IIC_VLD4u")          1, 0, 0, 43, 3, 42, 2,  0, 0}, // #152
  {DBGFIELD("IIC_fpLoad_mu")      65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #153
  {DBGFIELD("IIC_fpLoad_m")       65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #154
  {DBGFIELD("IIC_fpLoad64")       1, 0, 0, 31, 3, 14, 2,  0, 0}, // #155
  {DBGFIELD("IIC_fpLoad32")       1, 0, 0, 31, 3, 14, 2,  0, 0}, // #156
  {DBGFIELD("IIC_fpMAC64")        1, 0, 0,  3, 2, 32, 1,  0, 0}, // #157
  {DBGFIELD("IIC_VMACi32D")       1, 0, 0, 21, 2, 38, 1, 64, 2}, // #158
  {DBGFIELD("IIC_VMACi16D")       1, 0, 0,  3, 2, 27, 1, 69, 3}, // #159
  {DBGFIELD("IIC_fpMAC32")        1, 0, 0,  3, 2, 42, 1,  0, 0}, // #160
  {DBGFIELD("IIC_VMACD")          1, 0, 0,  3, 2, 32, 1, 64, 2}, // #161
  {DBGFIELD("IIC_VMACQ")          1, 0, 0,  3, 2, 33, 1, 64, 2}, // #162
  {DBGFIELD("IIC_VMACi32Q")       1, 0, 0, 21, 2, 32, 1, 64, 2}, // #163
  {DBGFIELD("IIC_VMACi16Q")       1, 0, 0,  3, 2, 38, 1, 69, 3}, // #164
  {DBGFIELD("IIC_fpMOVID")        1, 0, 0,  3, 2,  1, 1,  0, 0}, // #165
  {DBGFIELD("IIC_VQUNAiD")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #166
  {DBGFIELD("IIC_VMOVN")          1, 0, 0,  3, 2,  3, 1,  0, 0}, // #167
  {DBGFIELD("IIC_fpMOVDI")        2, 0, 0, 23, 2, 14, 2,  0, 0}, // #168
  {DBGFIELD("IIC_fpMOVSI")        1, 0, 0,  3, 2,  1, 1,  0, 0}, // #169
  {DBGFIELD("IIC_fpMOVIS")        1, 0, 0,  3, 2,  1, 1,  0, 0}, // #170
  {DBGFIELD("IIC_fpMUL64")        1, 0, 0,  3, 2, 27, 1,  0, 0}, // #171
  {DBGFIELD("IIC_VMULi16D")       1, 0, 0,  3, 2, 27, 1, 67, 2}, // #172
  {DBGFIELD("IIC_VMULi32D")       1, 0, 0, 21, 2, 38, 1, 66, 1}, // #173
  {DBGFIELD("IIC_fpMUL32")        1, 0, 0,  3, 2, 19, 1,  0, 0}, // #174
  {DBGFIELD("IIC_VFMULD")         1, 0, 0,  3, 2, 19, 1, 66, 1}, // #175
  {DBGFIELD("IIC_VFMULQ")         1, 0, 0,  3, 2, 27, 1, 66, 1}, // #176
  {DBGFIELD("IIC_VMULi16Q")       1, 0, 0,  3, 2, 38, 1, 67, 2}, // #177
  {DBGFIELD("IIC_VMULi32Q")       1, 0, 0, 21, 2, 32, 1, 66, 1}, // #178
  {DBGFIELD("IIC_VSHLiQ")         1, 0, 0,  3, 2,  3, 1,  0, 0}, // #179
  {DBGFIELD("IIC_VPALiQ")         1, 0, 0,  3, 2, 27, 1, 64, 1}, // #180
  {DBGFIELD("IIC_VPALiD")         1, 0, 0,  3, 2, 27, 1, 64, 1}, // #181
  {DBGFIELD("IIC_VPBIND")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #182
  {DBGFIELD("IIC_VQUNAiQ")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #183
  {DBGFIELD("IIC_VSHLi4Q")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #184
  {DBGFIELD("IIC_VSHLi4D")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #185
  {DBGFIELD("IIC_VRECSD")         1, 0, 0,  3, 2, 32, 1, 67, 2}, // #186
  {DBGFIELD("IIC_VRECSQ")         1, 0, 0,  3, 2, 33, 1, 67, 2}, // #187
  {DBGFIELD("IIC_VMOVISL")        1, 0, 0,  3, 2,  3, 1,  0, 0}, // #188
  {DBGFIELD("IIC_fpCVTID_WriteCvtFP") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #189
  {DBGFIELD("IIC_fpCVTIS_WriteCvtFP") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #190
  {DBGFIELD("IIC_fpCVTID")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #191
  {DBGFIELD("IIC_fpCVTIS")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #192
  {DBGFIELD("IIC_fpSQRT64")       1, 0, 0,  3, 2, 44, 1,  0, 0}, // #193
  {DBGFIELD("IIC_fpSQRT32")       1, 0, 0,  3, 2, 45, 1,  0, 0}, // #194
  {DBGFIELD("IIC_VST1ln")         1, 0, 0, 31, 3, 14, 2,  0, 0}, // #195
  {DBGFIELD("IIC_VST1lnu")        1, 0, 0, 31, 3, 14, 2,  0, 0}, // #196
  {DBGFIELD("IIC_VST1")           1, 0, 0, 31, 3, 14, 2,  0, 0}, // #197
  {DBGFIELD("IIC_VST1x4")         1, 0, 0, 34, 3, 30, 2,  0, 0}, // #198
  {DBGFIELD("IIC_VLD1x4u")        1, 0, 0, 34, 3, 30, 2,  0, 0}, // #199
  {DBGFIELD("IIC_VST1x3")         1, 0, 0, 34, 3, 30, 2,  0, 0}, // #200
  {DBGFIELD("IIC_VLD1x3u")        1, 0, 0, 34, 3, 30, 2,  0, 0}, // #201
  {DBGFIELD("IIC_VST1x4u")        1, 0, 0, 34, 3, 30, 2,  0, 0}, // #202
  {DBGFIELD("IIC_VST1x3u")        1, 0, 0, 34, 3, 30, 2,  0, 0}, // #203
  {DBGFIELD("IIC_VST1x2")         1, 0, 0, 31, 3, 14, 2,  0, 0}, // #204
  {DBGFIELD("IIC_VST2ln")         1, 0, 0, 31, 3, 14, 2,  0, 0}, // #205
  {DBGFIELD("IIC_VST2lnu")        1, 0, 0, 31, 3, 14, 2,  0, 0}, // #206
  {DBGFIELD("IIC_VST2")           1, 0, 0, 31, 3, 14, 2,  0, 0}, // #207
  {DBGFIELD("IIC_VST2x2")         1, 0, 0, 31, 3, 14, 2,  0, 0}, // #208
  {DBGFIELD("IIC_VST2x2u")        1, 0, 0, 31, 3, 14, 2,  0, 0}, // #209
  {DBGFIELD("IIC_VST3ln")         1, 0, 0, 34, 3, 30, 2,  0, 0}, // #210
  {DBGFIELD("IIC_VST3lnu")        1, 0, 0, 34, 3, 30, 2,  0, 0}, // #211
  {DBGFIELD("IIC_VST3")           1, 0, 0, 34, 3, 30, 2,  0, 0}, // #212
  {DBGFIELD("IIC_VST3u")          1, 0, 0, 34, 3, 30, 2,  0, 0}, // #213
  {DBGFIELD("IIC_VST4ln")         1, 0, 0, 34, 3, 30, 2,  0, 0}, // #214
  {DBGFIELD("IIC_VST4lnu")        1, 0, 0, 34, 3, 30, 2,  0, 0}, // #215
  {DBGFIELD("IIC_VST4")           1, 0, 0, 34, 3, 30, 2,  0, 0}, // #216
  {DBGFIELD("IIC_VST4u")          1, 0, 0, 34, 3, 30, 2,  0, 0}, // #217
  {DBGFIELD("IIC_fpStore_mu")     1, 0, 0, 31, 3, 14, 2,  0, 0}, // #218
  {DBGFIELD("IIC_fpStore_m")      1, 0, 0, 31, 3, 14, 2,  0, 0}, // #219
  {DBGFIELD("IIC_fpStore64")      1, 0, 0, 31, 3, 14, 2,  0, 0}, // #220
  {DBGFIELD("IIC_fpStore32")      1, 0, 0, 31, 3, 14, 2,  0, 0}, // #221
  {DBGFIELD("IIC_VSUBiQ")         1, 0, 0,  3, 2,  3, 1, 66, 1}, // #222
  {DBGFIELD("IIC_VTB1")           1, 0, 0,  3, 2,  3, 1, 66, 1}, // #223
  {DBGFIELD("IIC_VTB2")           1, 0, 0,  3, 2,  3, 1, 67, 2}, // #224
  {DBGFIELD("IIC_VTB3")           1, 0, 0,  3, 2, 18, 1, 72, 3}, // #225
  {DBGFIELD("IIC_VTB4")           1, 0, 0,  3, 2, 18, 1, 75, 4}, // #226
  {DBGFIELD("IIC_VTBX1")          1, 0, 0,  3, 2,  3, 1, 65, 1}, // #227
  {DBGFIELD("IIC_VTBX2")          1, 0, 0,  3, 2,  3, 1, 70, 2}, // #228
  {DBGFIELD("IIC_VTBX3")          1, 0, 0,  3, 2, 18, 1, 79, 3}, // #229
  {DBGFIELD("IIC_VTBX4")          1, 0, 0,  3, 2, 18, 1, 82, 4}, // #230
  {DBGFIELD("IIC_fpCVTDI_WriteCvtFP") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #231
  {DBGFIELD("IIC_fpCVTSI_WriteCvtFP") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #232
  {DBGFIELD("IIC_fpCVTDI")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #233
  {DBGFIELD("IIC_fpCVTSI")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #234
  {DBGFIELD("IIC_VPERMD")         2, 0, 0, 23, 2, 30, 2,  0, 0}, // #235
  {DBGFIELD("IIC_VPERMQ")         2, 0, 0, 23, 2, 30, 2,  0, 0}, // #236
  {DBGFIELD("IIC_VPERMQ3")        2, 0, 0, 23, 2, 23, 2, 65, 1}, // #237
  {DBGFIELD("IIC_iALUsi_WriteALUsi_ReadALUsr") 1, 0, 0,  1, 1,  2, 1,  1, 21}, // #238
  {DBGFIELD("IIC_iBITi")          1, 0, 0,  1, 1,  1, 1,  0, 0}, // #239
  {DBGFIELD("IIC_iCMPsi_WriteCMPsi_ReadALU_ReadALU") 1, 0, 0,  1, 1,  1, 1, 22, 42}, // #240
  {DBGFIELD("IIC_iCMPi_WriteCMP") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #241
  {DBGFIELD("IIC_iCMPr_WriteCMP") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #242
  {DBGFIELD("IIC_iCMPsi_WriteCMPsi") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #243
  {DBGFIELD("IIC_iALUx")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #244
  {DBGFIELD("IIC_iLoad_bh_i")     1, 0, 0,  5, 2,  4, 2,  0, 0}, // #245
  {DBGFIELD("IIC_iLoad_d_i")      1, 0, 0,  7, 2,  8, 3,  0, 0}, // #246
  {DBGFIELD("IIC_iCMOVsi_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #247
  {DBGFIELD("IIC_iMOVi")          1, 0, 0,  1, 1,  1, 1,  0, 0}, // #248
  {DBGFIELD("IIC_iMVNsi_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #249
  {DBGFIELD("IIC_iALUsir_WriteALUsi_ReadALU") 1, 0, 0,  1, 1,  2, 1,  1, 21}, // #250
  {DBGFIELD("IIC_iStore_bh_i")    1, 0, 0,  5, 2, 21, 2,  0, 0}, // #251
  {DBGFIELD("IIC_iStore_i")       1, 0, 0,  7, 2, 14, 2,  0, 0}, // #252
  {DBGFIELD("IIC_iEXTAsr")        1, 0, 0,  1, 1,  3, 1,  0, 0}, // #253
  {DBGFIELD("IIC_iEXTr")          1, 0, 0,  1, 1,  2, 1,  0, 0}, // #254
  {DBGFIELD("IIC_iTSTi_WriteCMP") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #255
  {DBGFIELD("IIC_iTSTr_WriteCMP") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #256
  {DBGFIELD("IIC_iTSTsi_WriteCMPsi") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #257
  {DBGFIELD("IIC_iALUr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #258
  {DBGFIELD("IIC_iALUi_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #259
  {DBGFIELD("IIC_iBITr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #260
  {DBGFIELD("IIC_iPop")           65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #261
  {DBGFIELD("IIC_iPop_Br_WriteBrL") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #262
  {DBGFIELD("IIC_iTSTr_WriteALU") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #263
  {DBGFIELD("ANDri_BICri_EORri_ORRri") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #264
  {DBGFIELD("ANDrr_BICrr_EORrr_ORRrr") 1, 0, 0,  1, 1,  1, 1,  0, 0}, // #265
  {DBGFIELD("ANDrsi_BICrsi_EORrsi_ORRrsi") 1, 0, 0,  1, 1,  2, 1,  0, 0}, // #266
  {DBGFIELD("ANDrsr_BICrsr_EORrsr_ORRrsr") 1, 0, 0,  1, 1,  3, 1,  0, 0}, // #267
  {DBGFIELD("MOVCCsi_MOVCCsr")    1, 0, 0,  1, 1,  2, 1,  0, 0}, // #268
  {DBGFIELD("MOVsi_MOVsr")        1, 0, 0,  1, 1,  2, 1,  0, 0}, // #269
  {DBGFIELD("MOVsra_flag_MOVsrl_flag") 1, 0, 0,  1, 1,  2, 1,  0, 0}, // #270
  {DBGFIELD("MVNsr")              1, 0, 0,  1, 1,  2, 1,  0, 0}, // #271
  {DBGFIELD("MVNr")               1, 0, 0,  1, 1,  1, 1,  1, 21}, // #272
  {DBGFIELD("MOVCCi32imm")        2, 0, 0, 14, 1,  2, 1,  0, 0}, // #273
  {DBGFIELD("MOVi32imm")          2, 0, 0, 14, 1,  2, 1,  0, 0}, // #274
  {DBGFIELD("MOV_ga_pcrel")       3, 0, 0, 12, 1,  3, 1,  0, 0}, // #275
  {DBGFIELD("MOV_ga_pcrel_ldr")   3, 0, 0, 12, 1,  3, 1,  0, 0}, // #276
  {DBGFIELD("SEL")                1, 0, 0,  1, 1,  1, 1,  0, 0}, // #277
  {DBGFIELD("BFC_BFI_SBFX_UBFX")  1, 0, 0,  1, 1,  2, 1,  0, 0}, // #278
  {DBGFIELD("MLA_MLAv5_MLS_SMMLA_SMMLAR_SMMLS_SMMLSR") 1, 0, 0, 17, 2, 18, 1,  0, 0}, // #279
  {DBGFIELD("MUL_MULv5_SMMUL_SMMULR") 1, 0, 0, 17, 2, 18, 1,  0, 0}, // #280
  {DBGFIELD("SMLAL_SMLALBB_SMLALBT_SMLALTB_SMLALTT_SMLALv5_UMAAL_UMLAL_UMLALv5") 1, 0, 0, 12, 2, 18, 2,  0, 0}, // #281
  {DBGFIELD("SMULL_SMULLv5_UMULL_UMULLv5") 1, 0, 0, 12, 2, 18, 2,  0, 0}, // #282
  {DBGFIELD("SMLAD_SMLADX_SMLALD_SMLALDX_SMLSD_SMLSDX_SMLSLD_SMLSLDX_SMUAD_SMUADX_SMUSD_SMUSDX") 1, 0, 0, 12, 2, 18, 2,  0, 0}, // #283
  {DBGFIELD("SMULBB_SMULBT_SMULTB_SMULTT_SMULWB_SMULWT") 1, 0, 0, 17, 2, 23, 2,  0, 0}, // #284
  {DBGFIELD("SMLABB_SMLABT_SMLATB_SMLATT_SMLAWB_SMLAWT") 1, 0, 0, 17, 2, 23, 2,  0, 0}, // #285
  {DBGFIELD("LDRi12_PICLDR")      1, 0, 0,  6, 1,  8, 1,  0, 0}, // #286
  {DBGFIELD("LDRrs")              1, 0, 0,  6, 1, 16, 1,  0, 0}, // #287
  {DBGFIELD("LDRBi12_LDRH_LDRSB_LDRSH_PICLDRB_PICLDRH_PICLDRSB_PICLDRSH") 1, 0, 0,  6, 1,  4, 1,  0, 0}, // #288
  {DBGFIELD("LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE_LDRSBTi_LDRSBTr_LDRSB_POST_LDRSB_PRE_LDRSHTi_LDRSHTr_LDRSH_POST_LDRSH_PRE") 1, 0, 0,  6, 1,  4, 1,  0, 0}, // #289
  {DBGFIELD("SXTB_SXTB16_SXTH_UXTB_UXTB16_UXTH") 1, 0, 0,  1, 1,  2, 1,  0, 0}, // #290
  {DBGFIELD("t2SXTB_t2SXTB16_t2SXTH_t2UXTB_t2UXTB16_t2UXTH") 1, 0, 0,  1, 1,  2, 1,  0, 0}, // #291
  {DBGFIELD("t2MOVCCi32imm")      2, 0, 0, 14, 1,  2, 1,  0, 0}, // #292
  {DBGFIELD("t2MOVi32imm")        2, 0, 0, 14, 1,  2, 1,  0, 0}, // #293
  {DBGFIELD("t2MOV_ga_pcrel")     3, 0, 0, 12, 1,  3, 1,  0, 0}, // #294
  {DBGFIELD("t2MOVi16_ga_pcrel")  1, 0, 0,  1, 1,  1, 1,  0, 0}, // #295
  {DBGFIELD("t2SEL")              0, 0, 0,  0, 0,  0, 0,  0, 0}, // #296
  {DBGFIELD("t2BFC_t2SBFX_t2UBFX") 1, 0, 0,  1, 1,  2, 1,  0, 0}, // #297
  {DBGFIELD("t2BFI")              1, 0, 0,  1, 1,  1, 1,  0, 0}, // #298
  {DBGFIELD("QADD_QADD16_QADD8_QASX_QDADD_QDSUB_QSAX_QSUB_QSUB16_QSUB8_UQADD16_UQADD8_UQASX_UQSAX_UQSUB16_UQSUB8") 1, 0, 0,  1, 1,  1, 1, 22, 42}, // #299
  {DBGFIELD("SSAT_SSAT16_USAT_USAT16_t2QADD_t2QADD16_t2QADD8_t2QASX_t2QDADD_t2QDSUB_t2QSAX_t2QSUB_t2QSUB16_t2QSUB8_t2SSAT_t2SSAT16_t2UQADD16_t2UQADD8_t2UQASX_t2UQSAX_t2UQSUB16_t2UQSUB8_t2USAT_t2USAT16") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #300
  {DBGFIELD("SADD16_SADD8_SASX_SSAX_SSUB16_SSUB8_UADD16_UADD8_UASX_USAX_USUB16_USUB8") 1, 0, 0,  1, 1,  1, 1, 22, 42}, // #301
  {DBGFIELD("t2SADD16_t2SADD8_t2SASX_t2SSAX_t2SSUB16_t2SSUB8_t2UADD16_t2UADD8_t2UASX_t2USAX_t2USUB16_t2USUB8") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #302
  {DBGFIELD("SHADD16_SHADD8_SHASX_SHSAX_SHSUB16_SHSUB8_UHADD16_UHADD8_UHASX_UHSAX_UHSUB16_UHSUB8") 1, 0, 0,  1, 1,  1, 1, 22, 42}, // #303
  {DBGFIELD("SXTAB_SXTAB16_SXTAH_UXTAB_UXTAB16_UXTAH") 1, 0, 0,  1, 1,  3, 1,  0, 0}, // #304
  {DBGFIELD("t2SHADD16_t2SHADD8_t2SHASX_t2SHSAX_t2SHSUB16_t2SHSUB8_t2UHADD16_t2UHADD8_t2UHASX_t2UHSAX_t2UHSUB16_t2UHSUB8") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #305
  {DBGFIELD("t2SXTAB_t2SXTAB16_t2SXTAH_t2UXTAB_t2UXTAB16_t2UXTAH") 1, 0, 0,  1, 1,  3, 1,  0, 0}, // #306
  {DBGFIELD("USAD8")              1, 0, 0,  1, 1,  1, 1, 22, 42}, // #307
  {DBGFIELD("USADA8")             1, 0, 0,  1, 1,  1, 1, 22, 42}, // #308
  {DBGFIELD("SMUSD_SMUSDX")       1, 0, 0, 12, 2, 18, 2,  0, 0}, // #309
  {DBGFIELD("t2MUL_t2SMMUL_t2SMMULR") 1, 0, 0, 12, 2, 18, 2,  0, 0}, // #310
  {DBGFIELD("t2SMULBB_t2SMULBT_t2SMULTB_t2SMULTT_t2SMULWB_t2SMULWT") 1, 0, 0, 17, 2, 23, 2,  0, 0}, // #311
  {DBGFIELD("t2SMUSD_t2SMUSDX")   1, 0, 0, 12, 2, 18, 2,  0, 0}, // #312
  {DBGFIELD("t2MLA_t2MLS_t2SMMLA_t2SMMLAR_t2SMMLS_t2SMMLSR") 1, 0, 0, 12, 2, 18, 2,  0, 0}, // #313
  {DBGFIELD("SMUAD_SMUADX")       1, 0, 0, 12, 2, 18, 2,  0, 0}, // #314
  {DBGFIELD("t2SMUAD_t2SMUADX")   1, 0, 0, 12, 2, 18, 2,  0, 0}, // #315
  {DBGFIELD("SMLSD_SMLSDX")       1, 0, 0, 12, 2, 18, 2,  0, 0}, // #316
  {DBGFIELD("t2SMLABB_t2SMLABT_t2SMLATB_t2SMLATT_t2SMLAWB_t2SMLAWT") 1, 0, 0, 17, 2, 23, 2,  0, 0}, // #317
  {DBGFIELD("t2SMLSD_t2SMLSDX")   1, 0, 0, 12, 2, 18, 2,  0, 0}, // #318
  {DBGFIELD("SMLAD_SMLADX")       1, 0, 0, 12, 2, 18, 2,  0, 0}, // #319
  {DBGFIELD("t2SMLAD_t2SMLADX")   1, 0, 0, 12, 2, 18, 2,  0, 0}, // #320
  {DBGFIELD("SMULL_UMULL")        1, 0, 0, 12, 2, 18, 2,  0, 0}, // #321
  {DBGFIELD("t2SMULL_t2UMULL")    1, 0, 0, 12, 2, 18, 2,  0, 0}, // #322
  {DBGFIELD("t2SMLAL_t2SMLALBB_t2SMLALBT_t2SMLALD_t2SMLALDX_t2SMLALTB_t2SMLALTT_t2SMLSLD_t2SMLSLDX_t2UMAAL_t2UMLAL") 1, 0, 0, 12, 2, 18, 2,  0, 0}, // #323
  {DBGFIELD("SDIV_UDIV_t2SDIV_t2UDIV") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #324
  {DBGFIELD("LDRBi12")            1, 0, 0,  6, 1,  4, 1,  0, 0}, // #325
  {DBGFIELD("LDRBrs_t2LDRBs_t2LDRHs") 1, 0, 0,  5, 2,  6, 2,  0, 0}, // #326
  {DBGFIELD("LDREX_LDREXB_LDREXD_LDREXH_tLDRpci_pic") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #327
  {DBGFIELD("LDRi12")             1, 0, 0,  6, 1,  8, 1,  0, 0}, // #328
  {DBGFIELD("t2LDRBi12_t2LDRBi8_t2LDRBpci_t2LDRHi12_t2LDRHi8_t2LDRHpci_tLDRBi_tLDRHi") 1, 0, 0,  5, 2,  4, 2,  0, 0}, // #329
  {DBGFIELD("t2LDRi12_t2LDRi8_t2LDRpci_tLDRi_tLDRpci_tLDRspi") 1, 0, 0,  7, 2, 11, 2,  0, 0}, // #330
  {DBGFIELD("t2LDRpci_pic")       2, 0, 0,  9, 3, 13, 3,  0, 0}, // #331
  {DBGFIELD("t2LDRs")             1, 0, 0,  7, 2, 16, 2,  0, 0}, // #332
  {DBGFIELD("tLDRBr_tLDRHr")      1, 0, 0,  5, 2,  4, 2,  0, 0}, // #333
  {DBGFIELD("tLDRr")              1, 0, 0,  7, 2, 11, 2,  0, 0}, // #334
  {DBGFIELD("LDRH_PICLDRB_PICLDRH") 1, 0, 0,  6, 1,  4, 1,  0, 0}, // #335
  {DBGFIELD("LDRcp")              1, 0, 0,  7, 2, 11, 2,  0, 0}, // #336
  {DBGFIELD("t2LDRSBi12_t2LDRSBi8_t2LDRSBpci_t2LDRSHi12_t2LDRSHi8_t2LDRSHpci") 1, 0, 0,  5, 2,  4, 2,  0, 0}, // #337
  {DBGFIELD("t2LDRSBpcrel_t2LDRSHpcrel") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #338
  {DBGFIELD("t2LDRSBs_t2LDRSHs")  1, 0, 0,  5, 2,  6, 2,  0, 0}, // #339
  {DBGFIELD("tLDRSB_tLDRSH")      1, 0, 0,  5, 2,  4, 2,  0, 0}, // #340
  {DBGFIELD("LDRBT_POST_IMM_LDRBT_POST_REG_LDRB_POST_REG_LDRB_PRE_REG") 1, 0, 0,  5, 2,  4, 2,  0, 0}, // #341
  {DBGFIELD("LDRB_POST_IMM_LDRB_PRE_IMM_t2LDRB_POST_t2LDRB_PRE_t2LDRH_POST_t2LDRH_PRE") 1, 0, 0,  5, 2,  4, 2,  0, 0}, // #342
  {DBGFIELD("LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE") 1, 0, 0,  6, 1,  4, 1,  0, 0}, // #343
  {DBGFIELD("LDRT_POST_IMM_LDRT_POST_REG_LDR_POST_REG_LDR_PRE_REG") 1, 0, 0,  7, 2, 11, 2,  0, 0}, // #344
  {DBGFIELD("LDR_POST_IMM_LDR_PRE_IMM_t2LDR_POST_t2LDR_PRE") 1, 0, 0,  7, 2, 11, 2,  0, 0}, // #345
  {DBGFIELD("t2LDRBT_t2LDRHT")    1, 0, 0,  5, 2,  4, 2,  0, 0}, // #346
  {DBGFIELD("t2LDRT")             1, 0, 0,  7, 2, 11, 2,  0, 0}, // #347
  {DBGFIELD("t2LDRSBT_t2LDRSHT")  1, 0, 0,  5, 2,  4, 2,  0, 0}, // #348
  {DBGFIELD("t2LDRSB_POST_t2LDRSB_PRE_t2LDRSH_POST_t2LDRSH_PRE") 1, 0, 0,  5, 2,  4, 2,  0, 0}, // #349
  {DBGFIELD("LDRD")               1, 0, 0,  7, 2,  8, 3,  0, 0}, // #350
  {DBGFIELD("t2LDRDi8")           1, 0, 0,  7, 2,  8, 3,  0, 0}, // #351
  {DBGFIELD("LDRD_POST_LDRD_PRE_t2LDRD_POST_t2LDRD_PRE") 1, 0, 0,  7, 2,  8, 3,  0, 0}, // #352
  {DBGFIELD("LDMDA_LDMDB_LDMIA_LDMIB_sysLDMDA_sysLDMDB_sysLDMIA_sysLDMIB_t2LDMDB_t2LDMIA_tLDMIA") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #353
  {DBGFIELD("LDMDA_UPD_LDMDB_UPD_LDMIA_UPD_LDMIB_UPD_sysLDMDA_UPD_sysLDMDB_UPD_sysLDMIA_UPD_sysLDMIB_UPD_t2LDMDB_UPD_t2LDMIA_UPD_tLDMIA_UPD") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #354
  {DBGFIELD("LDMIA_RET_t2LDMIA_RET") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #355
  {DBGFIELD("tPOP")               65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #356
  {DBGFIELD("tPOP_RET")           65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #357
  {DBGFIELD("PICSTR_STRi12_tSTRr") 1, 0, 0,  7, 2, 14, 2,  0, 0}, // #358
  {DBGFIELD("PICSTRB_PICSTRH_STRBi12_STRH_tSTRBr_tSTRHr") 1, 0, 0,  5, 2, 21, 2,  0, 0}, // #359
  {DBGFIELD("STRBrs_t2STRBs_t2STRHs") 1, 0, 0, 19, 2, 25, 2,  0, 0}, // #360
  {DBGFIELD("STREX_STREXB_STREXD_STREXH") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #361
  {DBGFIELD("STRrs_t2STRs")       1, 0, 0,  5, 2, 21, 2,  0, 0}, // #362
  {DBGFIELD("t2STRBi12_t2STRBi8_t2STRHi12_t2STRHi8_tSTRBi_tSTRHi") 1, 0, 0,  5, 2, 21, 2,  0, 0}, // #363
  {DBGFIELD("t2STRi12_t2STRi8_tSTRi_tSTRspi") 1, 0, 0,  7, 2, 14, 2,  0, 0}, // #364
  {DBGFIELD("STRBT_POST_STRT_POST") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #365
  {DBGFIELD("STRBT_POST_IMM_STRBT_POST_REG_STRB_POST_REG_STRB_PRE_REG_STRHTi_STRHTr_STRH_POST_STRH_PRE") 1, 0, 0,  5, 2, 21, 2,  0, 0}, // #366
  {DBGFIELD("STRB_POST_IMM_STRB_PRE_IMM_t2STRB_POST_t2STRB_PRE_t2STRH_POST") 1, 0, 0,  5, 2, 21, 2,  0, 0}, // #367
  {DBGFIELD("STRBi_preidx_STRBr_preidx_STRH_preidx_STRT_POST_IMM_STRT_POST_REG_STR_POST_REG_STR_PRE_REG_STRi_preidx_STRr_preidx_t2STRB_preidx_t2STRH_preidx_t2STR_preidx") 1, 0, 0,  7, 2, 14, 2,  0, 0}, // #368
  {DBGFIELD("STR_POST_IMM_STR_PRE_IMM_t2STRH_PRE_t2STR_POST_t2STR_PRE") 1, 0, 0,  7, 2, 14, 2,  0, 0}, // #369
  {DBGFIELD("t2STRBT_t2STRHT")    1, 0, 0,  5, 2, 21, 2,  0, 0}, // #370
  {DBGFIELD("t2STRT")             1, 0, 0,  7, 2, 14, 2,  0, 0}, // #371
  {DBGFIELD("STRD_t2STRDi8")      1, 0, 0,  7, 2, 14, 2,  0, 0}, // #372
  {DBGFIELD("STRD_POST_STRD_PRE_t2STRD_POST_t2STRD_PRE") 1, 0, 0,  7, 2, 14, 2,  0, 0}, // #373
  {DBGFIELD("STMDA_STMDB_STMIA_STMIB_sysSTMDA_sysSTMDB_sysSTMIA_sysSTMIB_t2STMDB_t2STMIA") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #374
  {DBGFIELD("STMDA_UPD_STMDB_UPD_STMIA_UPD_STMIB_UPD_sysSTMDA_UPD_sysSTMDB_UPD_sysSTMIA_UPD_sysSTMIB_UPD_t2STMDB_UPD_t2STMIA_UPD_tSTMIA_UPD") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #375
  {DBGFIELD("tPUSH")              65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #376
  {DBGFIELD("LDRLIT_ga_abs_tLDRLIT_ga_abs") 1, 0, 0,  7, 2, 11, 2,  0, 0}, // #377
  {DBGFIELD("LDRLIT_ga_pcrel_tLDRLIT_ga_pcrel") 2, 0, 0,  9, 3, 13, 3,  0, 0}, // #378
  {DBGFIELD("LDRLIT_ga_pcrel_ldr") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #379
  {DBGFIELD("ITasm")              0, 0, 0,  0, 0,  0, 0,  0, 0}, // #380
  {DBGFIELD("t2IT")               0, 0, 0,  0, 0,  0, 0,  0, 0}, // #381
  {DBGFIELD("VADDLsv2i64_VADDLsv4i32_VADDLsv8i16_VADDLuv2i64_VADDLuv4i32_VADDLuv8i16_VNEGs16d_VNEGs32d_VNEGs8d_VPADDLsv16i8_VPADDLsv2i32_VPADDLsv4i16_VPADDLsv4i32_VPADDLsv8i16_VPADDLsv8i8_VPADDLuv16i8_VPADDLuv2i32_VPADDLuv4i16_VPADDLuv4i32_VPADDLuv8i16_VPADDLuv8i8_VPADDi16_VPADDi32_VPADDi8_VSHLLi16_VSHLLi32_VSHLLi8_VSHLLsv2i64_VSHLLsv4i32_VSHLLsv8i16_VSHLLuv2i64_VSHLLuv4i32_VSHLLuv8i16_VSHLiv16i8_VSHLiv1i64_VSHLiv2i32_VSHLiv2i64_VSHLiv4i16_VSHLiv4i32_VSHLiv8i16_VSHLiv8i8_VSHLsv1i64_VSHLsv2i32_VSHLsv4i16_VSHLsv8i8_VSHLuv1i64_VSHLuv2i32_VSHLuv4i16_VSHLuv8i8_VSHRsv16i8_VSHRsv1i64_VSHRsv2i32_VSHRsv2i64_VSHRsv4i16_VSHRsv4i32_VSHRsv8i16_VSHRsv8i8_VSHRuv16i8_VSHRuv1i64_VSHRuv2i32_VSHRuv2i64_VSHRuv4i16_VSHRuv4i32_VSHRuv8i16_VSHRuv8i8_VSLIv1i64_VSLIv2i32_VSLIv4i16_VSLIv8i8_VSRIv1i64_VSRIv2i32_VSRIv4i16_VSRIv8i8_VSUBLsv2i64_VSUBLsv4i32_VSUBLsv8i16_VSUBLuv2i64_VSUBLuv4i32_VSUBLuv8i16") 1, 0, 0,  3, 2,  3, 1,  0, 0}, // #382
  {DBGFIELD("VADDWsv2i64_VADDWsv4i32_VADDWsv8i16_VADDWuv2i64_VADDWuv4i32_VADDWuv8i16_VSUBWsv2i64_VSUBWsv4i32_VSUBWsv8i16_VSUBWuv2i64_VSUBWuv4i32_VSUBWuv8i16_VSUBv1i64_VSUBv2i32_VSUBv4i16_VSUBv8i8") 1, 0, 0,  3, 2,  3, 1, 66, 1}, // #383
  {DBGFIELD("VADDv16i8_VADDv2i64_VADDv4i32_VADDv8i16_VANDq_VBICq_VBIFq_VBITq_VEORq_VORNq_VORRq") 1, 0, 0,  3, 2,  3, 1, 67, 2}, // #384
  {DBGFIELD("VADDv1i64_VADDv2i32_VADDv4i16_VADDv8i8_VANDd_VBICd_VBIFd_VBITd_VEORd_VORNd_VORRd") 1, 0, 0,  3, 2,  3, 1, 67, 2}, // #385
  {DBGFIELD("VBICiv2i32_VBICiv4i16_VBICiv4i32_VBICiv8i16_VORRiv2i32_VORRiv4i16_VORRiv4i32_VORRiv8i16") 1, 0, 0,  3, 2,  3, 1,  0, 0}, // #386
  {DBGFIELD("VBSLd_VCLSv2i32_VCLSv4i16_VCLSv8i8_VCLZv2i32_VCLZv4i16_VCLZv8i8_VCNTd") 1, 0, 0,  3, 2,  3, 1, 66, 1}, // #387
  {DBGFIELD("VBSLq_VCLSv16i8_VCLSv4i32_VCLSv8i16_VCLZv16i8_VCLZv4i32_VCLZv8i16_VCNTq") 1, 0, 0, 21, 2, 18, 1, 64, 1}, // #388
  {DBGFIELD("VHADDsv16i8_VHADDsv4i32_VHADDsv8i16_VHADDuv16i8_VHADDuv4i32_VHADDuv8i16_VRHADDsv16i8_VRHADDsv4i32_VRHADDsv8i16_VRHADDuv16i8_VRHADDuv4i32_VRHADDuv8i16_VTSTv16i8_VTSTv4i32_VTSTv8i16") 1, 0, 0,  3, 2, 18, 1, 67, 2}, // #389
  {DBGFIELD("VHADDsv2i32_VHADDsv4i16_VHADDsv8i8_VHADDuv2i32_VHADDuv4i16_VHADDuv8i8_VRHADDsv2i32_VRHADDsv4i16_VRHADDsv8i8_VRHADDuv2i32_VRHADDuv4i16_VRHADDuv8i8_VTSTv2i32_VTSTv4i16_VTSTv8i8") 1, 0, 0,  3, 2, 18, 1, 67, 2}, // #390
  {DBGFIELD("VHSUBsv16i8_VHSUBsv4i32_VHSUBsv8i16_VHSUBuv16i8_VHSUBuv4i32_VHSUBuv8i16") 1, 0, 0,  3, 2, 18, 1, 66, 1}, // #391
  {DBGFIELD("VHSUBsv2i32_VHSUBsv4i16_VHSUBsv8i8_VHSUBuv2i32_VHSUBuv4i16_VHSUBuv8i8") 1, 0, 0,  3, 2, 18, 1, 66, 1}, // #392
  {DBGFIELD("VNEGf32q")           1, 0, 0,  3, 2, 27, 1, 66, 1}, // #393
  {DBGFIELD("VNEGfd")             1, 0, 0,  3, 2, 19, 1, 66, 1}, // #394
  {DBGFIELD("VNEGs16q_VNEGs32q_VNEGs8q_VSHLsv16i8_VSHLsv2i64_VSHLsv4i32_VSHLsv8i16_VSHLuv16i8_VSHLuv2i64_VSHLuv4i32_VSHLuv8i16_VSLIv16i8_VSLIv2i64_VSLIv4i32_VSLIv8i16_VSRIv16i8_VSRIv2i64_VSRIv4i32_VSRIv8i16") 1, 0, 0,  3, 2,  3, 1,  0, 0}, // #395
  {DBGFIELD("VQSHLsiv16i8_VQSHLsiv1i64_VQSHLsiv2i32_VQSHLsiv2i64_VQSHLsiv4i16_VQSHLsiv4i32_VQSHLsiv8i16_VQSHLsiv8i8_VQSHLsuv16i8_VQSHLsuv1i64_VQSHLsuv2i32_VQSHLsuv2i64_VQSHLsuv4i16_VQSHLsuv4i32_VQSHLsuv8i16_VQSHLsuv8i8_VQSHLsv1i64_VQSHLsv2i32_VQSHLsv4i16_VQSHLsv8i8_VQSHLuiv16i8_VQSHLuiv1i64_VQSHLuiv2i32_VQSHLuiv2i64_VQSHLuiv4i16_VQSHLuiv4i32_VQSHLuiv8i16_VQSHLuiv8i8_VQSHLuv1i64_VQSHLuv2i32_VQSHLuv4i16_VQSHLuv8i8") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #396
  {DBGFIELD("VQSHLsv16i8_VQSHLsv2i64_VQSHLsv4i32_VQSHLsv8i16_VQSHLuv16i8_VQSHLuv2i64_VQSHLuv4i32_VQSHLuv8i16") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #397
  {DBGFIELD("VSUBv16i8_VSUBv2i64_VSUBv4i32_VSUBv8i16") 1, 0, 0,  3, 2,  3, 1, 66, 1}, // #398
  {DBGFIELD("VEXTd16_VEXTd32_VEXTd8") 2, 0, 0, 23, 2, 30, 2,  0, 0}, // #399
  {DBGFIELD("VEXTq16_VEXTq32_VEXTq64_VEXTq8") 2, 0, 0, 23, 2, 23, 2, 65, 1}, // #400
  {DBGFIELD("VREV16d8_VREV32d16_VREV32d8_VREV64d16_VREV64d32_VREV64d8") 1, 0, 0,  3, 2,  2, 1,  0, 0}, // #401
  {DBGFIELD("VREV16q8_VREV32q16_VREV32q8_VREV64q16_VREV64q32_VREV64q8") 1, 0, 0,  3, 2,  2, 1,  0, 0}, // #402
  {DBGFIELD("VABALsv2i64_VABALsv4i32_VABALsv8i16_VABALuv2i64_VABALuv4i32_VABALuv8i16_VABAsv2i32_VABAsv4i16_VABAsv8i8_VABAuv2i32_VABAuv4i16_VABAuv8i8") 1, 0, 0,  3, 2, 27, 1, 64, 2}, // #403
  {DBGFIELD("VABAsv16i8_VABAsv4i32_VABAsv8i16_VABAuv16i8_VABAuv4i32_VABAuv8i16") 1, 0, 0,  3, 2, 27, 1, 64, 2}, // #404
  {DBGFIELD("VABSfd")             1, 0, 0,  3, 2, 19, 1, 66, 1}, // #405
  {DBGFIELD("VABSfq")             1, 0, 0,  3, 2, 27, 1, 66, 1}, // #406
  {DBGFIELD("VABSv16i8_VABSv4i32_VABSv8i16") 1, 0, 0,  3, 2, 18, 1, 66, 1}, // #407
  {DBGFIELD("VABSv2i32_VABSv4i16_VABSv8i8") 1, 0, 0,  3, 2, 18, 1, 66, 1}, // #408
  {DBGFIELD("VACGEd_VACGTd_VCEQfd_VCGEfd_VCGTfd") 1, 0, 0,  3, 2, 19, 1, 67, 2}, // #409
  {DBGFIELD("VACGEq_VACGTq_VCEQfq_VCGEfq_VCGTfq") 1, 0, 0,  3, 2, 27, 1, 67, 2}, // #410
  {DBGFIELD("VCEQv16i8_VCEQv4i32_VCEQv8i16_VCGEsv16i8_VCGEsv4i32_VCGEsv8i16_VCGEuv16i8_VCGEuv4i32_VCGEuv8i16_VCGTsv16i8_VCGTsv4i32_VCGTsv8i16_VCGTuv16i8_VCGTuv4i32_VCGTuv8i16_VQSUBsv16i8_VQSUBsv2i64_VQSUBsv4i32_VQSUBsv8i16_VQSUBuv16i8_VQSUBuv2i64_VQSUBuv4i32_VQSUBuv8i16") 1, 0, 0,  3, 2, 18, 1, 66, 1}, // #411
  {DBGFIELD("VCEQv2i32_VCEQv4i16_VCEQv8i8_VCGEsv2i32_VCGEsv4i16_VCGEsv8i8_VCGEuv2i32_VCGEuv4i16_VCGEuv8i8_VCGTsv2i32_VCGTsv4i16_VCGTsv8i8_VCGTuv2i32_VCGTuv4i16_VCGTuv8i8_VQSUBsv1i64_VQSUBsv2i32_VQSUBsv4i16_VQSUBsv8i8_VQSUBuv1i64_VQSUBuv2i32_VQSUBuv4i16_VQSUBuv8i8") 1, 0, 0,  3, 2, 18, 1, 66, 1}, // #412
  {DBGFIELD("VCEQzv16i8_VCEQzv2f32_VCEQzv2i32_VCEQzv4f32_VCEQzv4i16_VCEQzv4i32_VCEQzv8i16_VCEQzv8i8_VCGEzv16i8_VCGEzv2f32_VCGEzv2i32_VCGEzv4f32_VCGEzv4i16_VCGEzv4i32_VCGEzv8i16_VCGEzv8i8_VCGTzv16i8_VCGTzv2f32_VCGTzv2i32_VCGTzv4f32_VCGTzv4i16_VCGTzv4i32_VCGTzv8i16_VCGTzv8i8_VCLEzv16i8_VCLEzv2f32_VCLEzv2i32_VCLEzv4f32_VCLEzv4i16_VCLEzv4i32_VCLEzv8i16_VCLEzv8i8_VCLTzv16i8_VCLTzv2f32_VCLTzv2i32_VCLTzv4f32_VCLTzv4i16_VCLTzv4i32_VCLTzv8i16_VCLTzv8i8") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #413
  {DBGFIELD("VPADALsv16i8_VPADALsv4i32_VPADALsv8i16_VPADALuv16i8_VPADALuv4i32_VPADALuv8i16") 1, 0, 0,  3, 2, 27, 1, 64, 1}, // #414
  {DBGFIELD("VPADALsv2i32_VPADALsv4i16_VPADALsv8i8_VPADALuv2i32_VPADALuv4i16_VPADALuv8i8_VRSRAsv16i8_VRSRAsv1i64_VRSRAsv2i32_VRSRAsv2i64_VRSRAsv4i16_VRSRAsv4i32_VRSRAsv8i16_VRSRAsv8i8_VRSRAuv16i8_VRSRAuv1i64_VRSRAuv2i32_VRSRAuv2i64_VRSRAuv4i16_VRSRAuv4i32_VRSRAuv8i16_VRSRAuv8i8_VSRAsv16i8_VSRAsv1i64_VSRAsv2i32_VSRAsv2i64_VSRAsv4i16_VSRAsv4i32_VSRAsv8i16_VSRAsv8i8_VSRAuv16i8_VSRAuv1i64_VSRAuv2i32_VSRAuv2i64_VSRAuv4i16_VSRAuv4i32_VSRAuv8i16_VSRAuv8i8") 1, 0, 0,  3, 2, 27, 1, 64, 1}, // #415
  {DBGFIELD("VQABSv16i8_VQABSv4i32_VQABSv8i16_VQNEGv16i8_VQNEGv4i32_VQNEGv8i16") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #416
  {DBGFIELD("VQABSv2i32_VQABSv4i16_VQABSv8i8_VQNEGv2i32_VQNEGv4i16_VQNEGv8i8") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #417
  {DBGFIELD("VQADDsv16i8_VQADDsv2i64_VQADDsv4i32_VQADDsv8i16_VQADDuv16i8_VQADDuv2i64_VQADDuv4i32_VQADDuv8i16") 1, 0, 0,  3, 2, 18, 1, 67, 2}, // #418
  {DBGFIELD("VQADDsv1i64_VQADDsv2i32_VQADDsv4i16_VQADDsv8i8_VQADDuv1i64_VQADDuv2i32_VQADDuv4i16_VQADDuv8i8") 1, 0, 0,  3, 2, 18, 1, 67, 2}, // #419
  {DBGFIELD("VQRSHLsv16i8_VQRSHLsv2i64_VQRSHLsv4i32_VQRSHLsv8i16_VQRSHLuv16i8_VQRSHLuv2i64_VQRSHLuv4i32_VQRSHLuv8i16_VRSHLsv16i8_VRSHLsv2i64_VRSHLsv4i32_VRSHLsv8i16_VRSHLuv16i8_VRSHLuv2i64_VRSHLuv4i32_VRSHLuv8i16") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #420
  {DBGFIELD("VQRSHLsv1i64_VQRSHLsv2i32_VQRSHLsv4i16_VQRSHLsv8i8_VQRSHLuv1i64_VQRSHLuv2i32_VQRSHLuv4i16_VQRSHLuv8i8_VRSHLsv1i64_VRSHLsv2i32_VRSHLsv4i16_VRSHLsv8i8_VRSHLuv1i64_VRSHLuv2i32_VRSHLuv4i16_VRSHLuv8i8_VRSHRsv16i8_VRSHRsv1i64_VRSHRsv2i32_VRSHRsv2i64_VRSHRsv4i16_VRSHRsv4i32_VRSHRsv8i16_VRSHRsv8i8_VRSHRuv16i8_VRSHRuv1i64_VRSHRuv2i32_VRSHRuv2i64_VRSHRuv4i16_VRSHRuv4i32_VRSHRuv8i16_VRSHRuv8i8") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #421
  {DBGFIELD("VRECPEd_VRECPEfd_VRSQRTEd_VRSQRTEfd") 1, 0, 0,  3, 2, 19, 1, 66, 1}, // #422
  {DBGFIELD("VRECPEfq_VRECPEq_VRSQRTEfq_VRSQRTEq") 1, 0, 0,  3, 2, 27, 1, 66, 1}, // #423
  {DBGFIELD("VADDHNv2i32_VADDHNv4i16_VADDHNv8i8_VSUBHNv2i32_VSUBHNv4i16_VSUBHNv8i8") 1, 0, 0,  3, 2, 18, 1, 67, 2}, // #424
  {DBGFIELD("VSHRNv2i32_VSHRNv4i16_VSHRNv8i8") 1, 0, 0,  3, 2,  3, 1,  0, 0}, // #425
  {DBGFIELD("VQRSHRNsv2i32_VQRSHRNsv4i16_VQRSHRNsv8i8_VQRSHRNuv2i32_VQRSHRNuv4i16_VQRSHRNuv8i8_VQRSHRUNv2i32_VQRSHRUNv4i16_VQRSHRUNv8i8_VQSHRNsv2i32_VQSHRNsv4i16_VQSHRNsv8i8_VQSHRNuv2i32_VQSHRNuv4i16_VQSHRNuv8i8_VQSHRUNv2i32_VQSHRUNv4i16_VQSHRUNv8i8_VRSHRNv2i32_VRSHRNv4i16_VRSHRNv8i8") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #426
  {DBGFIELD("VRADDHNv2i32_VRADDHNv4i16_VRADDHNv8i8_VRSUBHNv2i32_VRSUBHNv4i16_VRSUBHNv8i8") 1, 0, 0,  3, 2, 18, 1, 67, 2}, // #427
  {DBGFIELD("VTBL1")              1, 0, 0,  3, 2,  3, 1, 66, 1}, // #428
  {DBGFIELD("VTBX1")              1, 0, 0,  3, 2,  3, 1, 65, 1}, // #429
  {DBGFIELD("VTBL2")              1, 0, 0,  3, 2,  3, 1, 67, 2}, // #430
  {DBGFIELD("VTBX2")              1, 0, 0,  3, 2,  3, 1, 70, 2}, // #431
  {DBGFIELD("VTBL3_VTBL3Pseudo")  1, 0, 0,  3, 2, 18, 1, 72, 3}, // #432
  {DBGFIELD("VTBX3_VTBX3Pseudo")  1, 0, 0,  3, 2, 18, 1, 79, 3}, // #433
  {DBGFIELD("VTBL4_VTBL4Pseudo")  1, 0, 0,  3, 2, 18, 1, 75, 4}, // #434
  {DBGFIELD("VTBX4_VTBX4Pseudo")  1, 0, 0,  3, 2, 18, 1, 82, 4}, // #435
  {DBGFIELD("VSWPd_VSWPq")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #436
  {DBGFIELD("VTRNd16_VTRNd32_VTRNd8_VUZPd16_VUZPd8_VZIPd16_VZIPd8") 2, 0, 0, 23, 2, 30, 2,  0, 0}, // #437
  {DBGFIELD("VTRNq16_VTRNq32_VTRNq8") 2, 0, 0, 23, 2, 30, 2,  0, 0}, // #438
  {DBGFIELD("VUZPq16_VUZPq32_VUZPq8_VZIPq16_VZIPq32_VZIPq8") 2, 0, 0, 23, 2, 23, 2, 65, 1}, // #439
  {DBGFIELD("VABSD_VNEGD")        1, 0, 0,  3, 2,  1, 1,  0, 0}, // #440
  {DBGFIELD("VABSS_VNEGS")        1, 0, 0,  3, 2,  1, 1,  0, 0}, // #441
  {DBGFIELD("VCMPD_VCMPED_VCMPEZD_VCMPZD") 1, 0, 0,  3, 2,  1, 1,  0, 0}, // #442
  {DBGFIELD("VCMPES_VCMPEZS_VCMPS_VCMPZS") 1, 0, 0,  3, 2,  1, 1,  0, 0}, // #443
  {DBGFIELD("VABDLsv2i64_VABDLsv4i32_VABDLsv8i16_VABDLuv2i64_VABDLuv4i32_VABDLuv8i16_VABDsv16i8_VABDsv4i32_VABDsv8i16_VABDuv16i8_VABDuv4i32_VABDuv8i16_VMAXsv16i8_VMAXsv4i32_VMAXsv8i16_VMAXuv16i8_VMAXuv4i32_VMAXuv8i16_VMINsv16i8_VMINsv4i32_VMINsv8i16_VMINuv16i8_VMINuv4i32_VMINuv8i16") 1, 0, 0,  3, 2, 18, 1, 66, 1}, // #444
  {DBGFIELD("VABDfd_VADDfd_VMAXfd_VMINfd_VSUBfd") 1, 0, 0,  3, 2, 19, 1, 67, 2}, // #445
  {DBGFIELD("VABDfq_VADDfq_VMAXfq_VMINfq_VSUBfq") 1, 0, 0,  3, 2, 27, 1, 67, 2}, // #446
  {DBGFIELD("VABDsv2i32_VABDsv4i16_VABDsv8i8_VABDuv2i32_VABDuv4i16_VABDuv8i8_VMAXsv2i32_VMAXsv4i16_VMAXsv8i8_VMAXuv2i32_VMAXuv4i16_VMAXuv8i8_VMINsv2i32_VMINsv4i16_VMINsv8i8_VMINuv2i32_VMINuv4i16_VMINuv8i8_VPMAXs16_VPMAXs32_VPMAXs8_VPMAXu16_VPMAXu32_VPMAXu8_VPMINs16_VPMINs32_VPMINs8_VPMINu16_VPMINu32_VPMINu8") 1, 0, 0,  3, 2, 18, 1, 66, 1}, // #447
  {DBGFIELD("VADDS_VSUBS")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #448
  {DBGFIELD("VMAXNMD_VMAXNMND_VMAXNMNQ_VMAXNMS_VMINNMD_VMINNMND_VMINNMNQ_VMINNMS") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #449
  {DBGFIELD("VPADDf_VPMAXf_VPMINf") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #450
  {DBGFIELD("VADDD_VSUBD")        1, 0, 0,  3, 2, 18, 1,  0, 0}, // #451
  {DBGFIELD("VRECPSfd_VRSQRTSfd") 1, 0, 0,  3, 2, 32, 1, 67, 2}, // #452
  {DBGFIELD("VRECPSfq_VRSQRTSfq") 1, 0, 0,  3, 2, 33, 1, 67, 2}, // #453
  {DBGFIELD("VMULLp64")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #454
  {DBGFIELD("VMULLp8_VMULLslsv2i32_VMULLslsv4i16_VMULLsluv2i32_VMULLsluv4i16_VMULLsv4i32_VMULLsv8i16_VMULLuv4i32_VMULLuv8i16_VMULpd_VMULslv4i16_VMULv4i16_VMULv8i8_VQDMULHslv4i16_VQDMULHv4i16_VQDMULLslv2i32_VQDMULLslv4i16_VQDMULLv4i32_VQRDMULHslv4i16_VQRDMULHv4i16") 1, 0, 0,  3, 2, 27, 1, 67, 2}, // #455
  {DBGFIELD("VMULLsv2i64_VMULLuv2i64_VMULslv2i32_VMULv2i32_VQDMULHslv2i32_VQDMULHv2i32_VQDMULLv2i64_VQRDMULHslv2i32_VQRDMULHv2i32") 1, 0, 0, 21, 2, 38, 1, 66, 1}, // #456
  {DBGFIELD("VMULS_VNMULS")       1, 0, 0,  3, 2, 19, 1,  0, 0}, // #457
  {DBGFIELD("VMULfd")             1, 0, 0,  3, 2, 19, 1, 66, 1}, // #458
  {DBGFIELD("VMULfq")             1, 0, 0,  3, 2, 27, 1, 66, 1}, // #459
  {DBGFIELD("VMULpq_VMULslv8i16_VMULv16i8_VMULv8i16_VQDMULHslv8i16_VQDMULHv8i16_VQRDMULHslv8i16_VQRDMULHv8i16") 1, 0, 0,  3, 2, 38, 1, 67, 2}, // #460
  {DBGFIELD("VMULslfd")           1, 0, 0,  3, 2, 19, 1, 67, 2}, // #461
  {DBGFIELD("VMULslfq")           1, 0, 0,  3, 2, 27, 1, 67, 2}, // #462
  {DBGFIELD("VMULslv4i32_VMULv4i32_VQDMULHslv4i32_VQDMULHv4i32_VQRDMULHslv4i32_VQRDMULHv4i32") 1, 0, 0, 21, 2, 32, 1, 66, 1}, // #463
  {DBGFIELD("VMULD_VNMULD")       1, 0, 0,  3, 2, 27, 1,  0, 0}, // #464
  {DBGFIELD("VFMAD_VFMSD_VFNMAD_VFNMSD") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #465
  {DBGFIELD("VFMAS_VFMSS_VFNMAS_VFNMSS") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #466
  {DBGFIELD("VMLAD_VMLSD_VNMLAD_VNMLSD") 1, 0, 0,  3, 2, 32, 1,  0, 0}, // #467
  {DBGFIELD("VMLALslsv2i32_VMLALsluv2i32_VMLALsv2i64_VMLALuv2i64_VMLAslv2i32_VMLAv2i32_VMLSLslsv2i32_VMLSLsluv2i32_VMLSLsv2i64_VMLSLuv2i64_VMLSslv2i32_VMLSv2i32_VQDMLALslv2i32_VQDMLALv2i64_VQDMLSLslv2i32_VQDMLSLv2i64") 1, 0, 0, 21, 2, 38, 1, 64, 2}, // #468
  {DBGFIELD("VMLALslsv4i16_VMLALsluv4i16_VMLALsv4i32_VMLALsv8i16_VMLALuv4i32_VMLALuv8i16_VMLAslv4i16_VMLAv4i16_VMLAv8i8_VMLSLslsv4i16_VMLSLsluv4i16_VMLSLsv4i32_VMLSLsv8i16_VMLSLuv4i32_VMLSLuv8i16_VMLSslv4i16_VMLSv4i16_VMLSv8i8_VQDMLALslv4i16_VQDMLALv4i32_VQDMLSLslv4i16_VQDMLSLv4i32") 1, 0, 0,  3, 2, 27, 1, 69, 3}, // #469
  {DBGFIELD("VMLAS_VMLSS_VNMLAS_VNMLSS") 1, 0, 0,  3, 2, 42, 1,  0, 0}, // #470
  {DBGFIELD("VMLAfd_VMLAslfd_VMLSfd_VMLSslfd") 1, 0, 0,  3, 2, 32, 1, 64, 2}, // #471
  {DBGFIELD("VMLAfq_VMLAslfq_VMLSfq_VMLSslfq") 1, 0, 0,  3, 2, 33, 1, 64, 2}, // #472
  {DBGFIELD("VMLAslv4i32_VMLAv4i32_VMLSslv4i32_VMLSv4i32") 1, 0, 0, 21, 2, 32, 1, 64, 2}, // #473
  {DBGFIELD("VMLAslv8i16_VMLAv16i8_VMLAv8i16_VMLSslv8i16_VMLSv16i8_VMLSv8i16") 1, 0, 0,  3, 2, 38, 1, 69, 3}, // #474
  {DBGFIELD("VFMAfd_VFMSfd")      1, 0, 0,  3, 2, 32, 1, 64, 2}, // #475
  {DBGFIELD("VFMAfq_VFMSfq")      1, 0, 0,  3, 2, 33, 1, 64, 2}, // #476
  {DBGFIELD("VCVTANSD_VCVTANSQ_VCVTANUD_VCVTANUQ_VCVTASD_VCVTASS_VCVTAUD_VCVTAUS_VCVTBDH_VCVTBHD_VCVTMNSD_VCVTMNSQ_VCVTMNUD_VCVTMNUQ_VCVTMSD_VCVTMSS_VCVTMUD_VCVTMUS_VCVTNNSD_VCVTNNSQ_VCVTNNUD_VCVTNNUQ_VCVTNSD_VCVTNSS_VCVTNUD_VCVTNUS_VCVTPNSD_VCVTPNSQ_VCVTPNUD_VCVTPNUQ_VCVTPSD_VCVTPSS_VCVTPUD_VCVTPUS_VCVTTDH_VCVTTHD") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #477
  {DBGFIELD("VCVTBHS_VCVTTHS")    1, 0, 0,  3, 2, 18, 1,  0, 0}, // #478
  {DBGFIELD("VCVTBSH_VCVTTSH")    1, 0, 0,  3, 2, 18, 1,  0, 0}, // #479
  {DBGFIELD("VCVTDS")             1, 0, 0,  3, 2, 18, 1,  0, 0}, // #480
  {DBGFIELD("VCVTSD")             1, 0, 0,  3, 2, 18, 1,  0, 0}, // #481
  {DBGFIELD("VCVTf2h_VCVTf2sq_VCVTf2uq_VCVTf2xsq_VCVTf2xuq_VCVTh2f_VCVTs2fq_VCVTu2fq_VCVTxs2fq_VCVTxu2fq") 1, 0, 0,  3, 2, 27, 1, 66, 1}, // #482
  {DBGFIELD("VCVTf2sd_VCVTf2ud_VCVTf2xsd_VCVTf2xud_VCVTs2fd_VCVTu2fd_VCVTxs2fd_VCVTxu2fd") 1, 0, 0,  3, 2, 19, 1, 66, 1}, // #483
  {DBGFIELD("VSITOD_VUITOD")      1, 0, 0,  3, 2, 18, 1,  0, 0}, // #484
  {DBGFIELD("VSITOS_VUITOS")      1, 0, 0,  3, 2, 18, 1,  0, 0}, // #485
  {DBGFIELD("VTOSHD_VTOSLD_VTOUHD_VTOULD") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #486
  {DBGFIELD("VTOSHS_VTOSLS_VTOUHS_VTOULS") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #487
  {DBGFIELD("VTOSIRD_VTOSIZD_VTOUIRD_VTOUIZD") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #488
  {DBGFIELD("VTOSIRS_VTOSIZS_VTOUIRS_VTOUIZS") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #489
  {DBGFIELD("FCONSTD_VMOVD_VMOVDcc") 1, 0, 0,  3, 2,  1, 1,  0, 0}, // #490
  {DBGFIELD("FCONSTS_VMOVS_VMOVScc") 1, 0, 0,  3, 2,  1, 1,  0, 0}, // #491
  {DBGFIELD("VMOVv16i8_VMOVv1i64_VMOVv2f32_VMOVv2i32_VMOVv2i64_VMOVv4f32_VMOVv4i16_VMOVv4i32_VMOVv8i16_VMOVv8i8_VMVNv2i32_VMVNv4i16_VMVNv4i32_VMVNv8i16") 1, 0, 0,  3, 2,  3, 1,  0, 0}, // #492
  {DBGFIELD("VMVNd_VMVNq")        1, 0, 0,  3, 2,  3, 1, 66, 1}, // #493
  {DBGFIELD("VMOVLsv2i64_VMOVLsv4i32_VMOVLsv8i16_VMOVLuv2i64_VMOVLuv4i32_VMOVLuv8i16") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #494
  {DBGFIELD("VMOVNv2i32_VMOVNv4i16_VMOVNv8i8") 1, 0, 0,  3, 2,  3, 1,  0, 0}, // #495
  {DBGFIELD("VQMOVNsuv2i32_VQMOVNsuv4i16_VQMOVNsuv8i8_VQMOVNsv2i32_VQMOVNsv4i16_VQMOVNsv8i8_VQMOVNuv2i32_VQMOVNuv4i16_VQMOVNuv8i8") 1, 0, 0,  3, 2, 18, 1,  0, 0}, // #496
  {DBGFIELD("VDUPLN16d_VDUPLN32d_VDUPLN8d") 1, 0, 0,  3, 2,  2, 1,  0, 0}, // #497
  {DBGFIELD("VDUPLN16q_VDUPLN32q_VDUPLN8q") 1, 0, 0,  3, 2,  2, 1,  0, 0}, // #498
  {DBGFIELD("VDUP16d_VDUP16q_VDUP32d_VDUP32q_VDUP8d_VDUP8q") 1, 0, 0,  3, 2,  1, 1,  0, 0}, // #499
  {DBGFIELD("VMOVRS")             1, 0, 0,  3, 2,  1, 1,  0, 0}, // #500
  {DBGFIELD("VMOVSR")             1, 0, 0,  3, 2,  1, 1,  0, 0}, // #501
  {DBGFIELD("VSETLNi16_VSETLNi32_VSETLNi8") 1, 0, 0,  3, 2,  3, 1,  0, 0}, // #502
  {DBGFIELD("VMOVRRD_VMOVRRS")    2, 0, 0, 23, 2, 14, 2,  0, 0}, // #503
  {DBGFIELD("VMOVDRR")            1, 0, 0,  3, 2,  1, 1,  0, 0}, // #504
  {DBGFIELD("VMOVSRR")            1, 0, 0,  3, 2,  1, 1,  0, 0}, // #505
  {DBGFIELD("VGETLNi32_VGETLNu16_VGETLNu8") 1, 0, 0,  3, 2,  2, 1,  0, 0}, // #506
  {DBGFIELD("VGETLNs16_VGETLNs8") 1, 0, 0,  3, 2,  2, 1,  0, 0}, // #507
  {DBGFIELD("VMRS_VMRS_FPEXC_VMRS_FPINST_VMRS_FPINST2_VMRS_FPSID_VMRS_MVFR0_VMRS_MVFR1_VMRS_MVFR2") 1, 0, 0,  3, 2,  1, 1,  0, 0}, // #508
  {DBGFIELD("VMSR_VMSR_FPEXC_VMSR_FPINST_VMSR_FPINST2_VMSR_FPSID") 1, 0, 0,  3, 2,  1, 1,  0, 0}, // #509
  {DBGFIELD("FMSTAT")             1, 0, 0,  3, 2,  1, 1,  0, 0}, // #510
  {DBGFIELD("VLDRD")              1, 0, 0, 31, 3, 14, 2,  0, 0}, // #511
  {DBGFIELD("VLDRS")              1, 0, 0, 31, 3, 14, 2,  0, 0}, // #512
  {DBGFIELD("VSTRD")              1, 0, 0, 31, 3, 14, 2,  0, 0}, // #513
  {DBGFIELD("VSTRS")              1, 0, 0, 31, 3, 14, 2,  0, 0}, // #514
  {DBGFIELD("VLDMQIA")            65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #515
  {DBGFIELD("VSTMQIA")            1, 0, 0, 31, 3, 14, 2,  0, 0}, // #516
  {DBGFIELD("VLDMDIA_VLDMSIA")    65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #517
  {DBGFIELD("VLDMDDB_UPD_VLDMDIA_UPD_VLDMSDB_UPD_VLDMSIA_UPD") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #518
  {DBGFIELD("VSTMDIA_VSTMSIA")    1, 0, 0, 31, 3, 14, 2,  0, 0}, // #519
  {DBGFIELD("VSTMDDB_UPD_VSTMDIA_UPD_VSTMSDB_UPD_VSTMSIA_UPD") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #520
  {DBGFIELD("VLD1d16_VLD1d32_VLD1d64_VLD1d8") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #521
  {DBGFIELD("VLD1q16_VLD1q32_VLD1q64_VLD1q8") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #522
  {DBGFIELD("VLD1d16wb_fixed_VLD1d16wb_register_VLD1d32wb_fixed_VLD1d32wb_register_VLD1d64wb_fixed_VLD1d64wb_register_VLD1d8wb_fixed_VLD1d8wb_register") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #523
  {DBGFIELD("VLD1q16wb_fixed_VLD1q16wb_register_VLD1q32wb_fixed_VLD1q32wb_register_VLD1q64wb_fixed_VLD1q64wb_register_VLD1q8wb_fixed_VLD1q8wb_register") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #524
  {DBGFIELD("VLD1d16T_VLD1d32T_VLD1d64T_VLD1d64TPseudo_VLD1d64TPseudoWB_fixed_VLD1d64TPseudoWB_register_VLD1d8T") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #525
  {DBGFIELD("VLD1d16Twb_fixed_VLD1d16Twb_register_VLD1d32Twb_fixed_VLD1d32Twb_register_VLD1d64Twb_fixed_VLD1d64Twb_register_VLD1d8Twb_fixed_VLD1d8Twb_register") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #526
  {DBGFIELD("VLD1d16Q_VLD1d32Q_VLD1d64Q_VLD1d64QPseudo_VLD1d64QPseudoWB_fixed_VLD1d64QPseudoWB_register_VLD1d8Q") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #527
  {DBGFIELD("VLD1d16Qwb_fixed_VLD1d16Qwb_register_VLD1d32Qwb_fixed_VLD1d32Qwb_register_VLD1d64Qwb_fixed_VLD1d64Qwb_register_VLD1d8Qwb_fixed_VLD1d8Qwb_register") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #528
  {DBGFIELD("VLD2b16_VLD2b32_VLD2b8_VLD2d16_VLD2d32_VLD2d8") 1, 0, 0, 25, 3, 34, 2,  0, 0}, // #529
  {DBGFIELD("VLD2q16_VLD2q16Pseudo_VLD2q32_VLD2q32Pseudo_VLD2q8_VLD2q8Pseudo") 1, 0, 0, 28, 3, 36, 2,  0, 0}, // #530
  {DBGFIELD("VLD2b16wb_fixed_VLD2b16wb_register_VLD2b32wb_fixed_VLD2b32wb_register_VLD2b8wb_fixed_VLD2b8wb_register_VLD2d16wb_fixed_VLD2d16wb_register_VLD2d32wb_fixed_VLD2d32wb_register_VLD2d8wb_fixed_VLD2d8wb_register") 1, 0, 0, 25, 3, 34, 2,  0, 0}, // #531
  {DBGFIELD("VLD2q16PseudoWB_fixed_VLD2q16PseudoWB_register_VLD2q16wb_fixed_VLD2q16wb_register_VLD2q32PseudoWB_fixed_VLD2q32PseudoWB_register_VLD2q32wb_fixed_VLD2q32wb_register_VLD2q8PseudoWB_fixed_VLD2q8PseudoWB_register_VLD2q8wb_fixed_VLD2q8wb_register") 1, 0, 0, 28, 3, 36, 2,  0, 0}, // #532
  {DBGFIELD("VLD3d16_VLD3d32_VLD3d8_VLD3q16_VLD3q32_VLD3q8") 1, 0, 0, 37, 3, 38, 2,  0, 0}, // #533
  {DBGFIELD("VLD3d16Pseudo_VLD3d32Pseudo_VLD3d8Pseudo_VLD3q16oddPseudo_VLD3q32oddPseudo_VLD3q8oddPseudo") 1, 0, 0, 37, 3, 38, 2,  0, 0}, // #534
  {DBGFIELD("VLD3d16_UPD_VLD3d32_UPD_VLD3d8_UPD_VLD3q16_UPD_VLD3q32_UPD_VLD3q8_UPD") 1, 0, 0, 37, 3, 38, 2,  0, 0}, // #535
  {DBGFIELD("VLD3d16Pseudo_UPD_VLD3d32Pseudo_UPD_VLD3d8Pseudo_UPD_VLD3q16Pseudo_UPD_VLD3q16oddPseudo_UPD_VLD3q32Pseudo_UPD_VLD3q32oddPseudo_UPD_VLD3q8Pseudo_UPD_VLD3q8oddPseudo_UPD") 1, 0, 0, 37, 3, 38, 2,  0, 0}, // #536
  {DBGFIELD("VLD4d16_VLD4d32_VLD4d8_VLD4q16_VLD4q32_VLD4q8") 1, 0, 0, 43, 3, 42, 2,  0, 0}, // #537
  {DBGFIELD("VLD4d16Pseudo_VLD4d32Pseudo_VLD4d8Pseudo_VLD4q16oddPseudo_VLD4q32oddPseudo_VLD4q8oddPseudo") 1, 0, 0, 43, 3, 42, 2,  0, 0}, // #538
  {DBGFIELD("VLD4d16_UPD_VLD4d32_UPD_VLD4d8_UPD_VLD4q16_UPD_VLD4q32_UPD_VLD4q8_UPD") 1, 0, 0, 43, 3, 42, 2,  0, 0}, // #539
  {DBGFIELD("VLD4d16Pseudo_UPD_VLD4d32Pseudo_UPD_VLD4d8Pseudo_UPD_VLD4q16Pseudo_UPD_VLD4q16oddPseudo_UPD_VLD4q32Pseudo_UPD_VLD4q32oddPseudo_UPD_VLD4q8Pseudo_UPD_VLD4q8oddPseudo_UPD") 1, 0, 0, 43, 3, 42, 2,  0, 0}, // #540
  {DBGFIELD("VLD1DUPd16_VLD1DUPd32_VLD1DUPd8_VLD1DUPq16_VLD1DUPq32_VLD1DUPq8") 1, 0, 0, 25, 3, 34, 2,  0, 0}, // #541
  {DBGFIELD("VLD1LNd16_VLD1LNd32_VLD1LNd8_VLD1LNq16Pseudo_VLD1LNq32Pseudo_VLD1LNq8Pseudo") 1, 0, 0, 28, 3, 36, 2,  0, 0}, // #542
  {DBGFIELD("VLD1DUPd16wb_fixed_VLD1DUPd16wb_register_VLD1DUPd32wb_fixed_VLD1DUPd32wb_register_VLD1DUPd8wb_fixed_VLD1DUPd8wb_register_VLD1DUPq16wb_fixed_VLD1DUPq16wb_register_VLD1DUPq32wb_fixed_VLD1DUPq32wb_register_VLD1DUPq8wb_fixed_VLD1DUPq8wb_register") 1, 0, 0, 25, 3, 34, 2,  0, 0}, // #543
  {DBGFIELD("VLD1LNd16_UPD_VLD1LNd32_UPD_VLD1LNd8_UPD_VLD1LNq16Pseudo_UPD_VLD1LNq32Pseudo_UPD_VLD1LNq8Pseudo_UPD") 1, 0, 0, 28, 3, 36, 2,  0, 0}, // #544
  {DBGFIELD("VLD2DUPd16_VLD2DUPd16x2_VLD2DUPd32_VLD2DUPd32x2_VLD2DUPd8_VLD2DUPd8x2") 1, 0, 0, 25, 3, 34, 2,  0, 0}, // #545
  {DBGFIELD("VLD2LNd16_VLD2LNd16Pseudo_VLD2LNd32_VLD2LNd32Pseudo_VLD2LNd8_VLD2LNd8Pseudo_VLD2LNq16_VLD2LNq16Pseudo_VLD2LNq32_VLD2LNq32Pseudo") 1, 0, 0, 28, 3, 36, 2,  0, 0}, // #546
  {DBGFIELD("VLD2LNd16_UPD_VLD2LNd32_UPD_VLD2LNd8_UPD_VLD2LNq16_UPD_VLD2LNq32_UPD") 1, 0, 0, 28, 3, 36, 2,  0, 0}, // #547
  {DBGFIELD("VLD2DUPd16wb_fixed_VLD2DUPd16wb_register_VLD2DUPd16x2wb_fixed_VLD2DUPd16x2wb_register_VLD2DUPd32wb_fixed_VLD2DUPd32wb_register_VLD2DUPd32x2wb_fixed_VLD2DUPd32x2wb_register_VLD2DUPd8wb_fixed_VLD2DUPd8wb_register_VLD2DUPd8x2wb_fixed_VLD2DUPd8x2wb_register") 1, 0, 0, 25, 3, 34, 2,  0, 0}, // #548
  {DBGFIELD("VLD2LNd16Pseudo_UPD_VLD2LNd32Pseudo_UPD_VLD2LNd8Pseudo_UPD_VLD2LNq16Pseudo_UPD_VLD2LNq32Pseudo_UPD") 1, 0, 0, 28, 3, 36, 2,  0, 0}, // #549
  {DBGFIELD("VLD3DUPd16_VLD3DUPd16Pseudo_VLD3DUPd32_VLD3DUPd32Pseudo_VLD3DUPd8_VLD3DUPd8Pseudo_VLD3DUPq16_VLD3DUPq32_VLD3DUPq8") 1, 0, 0, 37, 3, 38, 2,  0, 0}, // #550
  {DBGFIELD("VLD3LNd16_VLD3LNd16Pseudo_VLD3LNd32_VLD3LNd32Pseudo_VLD3LNd8_VLD3LNd8Pseudo_VLD3LNq16_VLD3LNq16Pseudo_VLD3LNq32_VLD3LNq32Pseudo") 1, 0, 0, 40, 3, 40, 2,  0, 0}, // #551
  {DBGFIELD("VLD3DUPd16_UPD_VLD3DUPd32_UPD_VLD3DUPd8_UPD_VLD3DUPq16_UPD_VLD3DUPq32_UPD_VLD3DUPq8_UPD") 1, 0, 0, 37, 3, 38, 2,  0, 0}, // #552
  {DBGFIELD("VLD3LNd16_UPD_VLD3LNd32_UPD_VLD3LNd8_UPD_VLD3LNq16_UPD_VLD3LNq32_UPD") 1, 0, 0, 40, 3, 40, 2,  0, 0}, // #553
  {DBGFIELD("VLD3DUPd16Pseudo_UPD_VLD3DUPd32Pseudo_UPD_VLD3DUPd8Pseudo_UPD") 1, 0, 0, 37, 3, 38, 2,  0, 0}, // #554
  {DBGFIELD("VLD3LNd16Pseudo_UPD_VLD3LNd32Pseudo_UPD_VLD3LNd8Pseudo_UPD_VLD3LNq16Pseudo_UPD_VLD3LNq32Pseudo_UPD") 1, 0, 0, 40, 3, 40, 2,  0, 0}, // #555
  {DBGFIELD("VLD4DUPd16_VLD4DUPd16Pseudo_VLD4DUPd32_VLD4DUPd32Pseudo_VLD4DUPd8_VLD4DUPd8Pseudo_VLD4DUPq16_VLD4DUPq32_VLD4DUPq8") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #556
  {DBGFIELD("VLD4LNd16_VLD4LNd16Pseudo_VLD4LNd32_VLD4LNd32Pseudo_VLD4LNd8_VLD4LNd8Pseudo_VLD4LNq16_VLD4LNq16Pseudo_VLD4LNq32_VLD4LNq32Pseudo") 1, 0, 0, 43, 3, 42, 2,  0, 0}, // #557
  {DBGFIELD("VLD4DUPd16_UPD_VLD4DUPd32_UPD_VLD4DUPd8_UPD_VLD4DUPq16_UPD_VLD4DUPq32_UPD_VLD4DUPq8_UPD") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #558
  {DBGFIELD("VLD4LNd16_UPD_VLD4LNd32_UPD_VLD4LNd8_UPD_VLD4LNq16_UPD_VLD4LNq32_UPD") 1, 0, 0, 43, 3, 42, 2,  0, 0}, // #559
  {DBGFIELD("VLD4DUPd16Pseudo_UPD_VLD4DUPd32Pseudo_UPD_VLD4DUPd8Pseudo_UPD") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #560
  {DBGFIELD("VLD4LNd16Pseudo_UPD_VLD4LNd32Pseudo_UPD_VLD4LNd8Pseudo_UPD_VLD4LNq16Pseudo_UPD_VLD4LNq32Pseudo_UPD") 1, 0, 0, 43, 3, 42, 2,  0, 0}, // #561
  {DBGFIELD("VST1d16_VST1d32_VST1d64_VST1d8") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #562
  {DBGFIELD("VST1q16_VST1q32_VST1q64_VST1q8") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #563
  {DBGFIELD("VST1d16wb_fixed_VST1d16wb_register_VST1d32wb_fixed_VST1d32wb_register_VST1d64wb_fixed_VST1d64wb_register_VST1d8wb_fixed_VST1d8wb_register") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #564
  {DBGFIELD("VST1q16wb_fixed_VST1q16wb_register_VST1q32wb_fixed_VST1q32wb_register_VST1q64wb_fixed_VST1q64wb_register_VST1q8wb_fixed_VST1q8wb_register") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #565
  {DBGFIELD("VST1d16T_VST1d32T_VST1d64T_VST1d64TPseudo_VST1d8T") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #566
  {DBGFIELD("VST1d16Twb_fixed_VST1d16Twb_register_VST1d32Twb_fixed_VST1d32Twb_register_VST1d64Twb_fixed_VST1d64Twb_register_VST1d8Twb_fixed_VST1d8Twb_register") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #567
  {DBGFIELD("VST1d64TPseudoWB_fixed_VST1d64TPseudoWB_register") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #568
  {DBGFIELD("VST1d16Q_VST1d32Q_VST1d64Q_VST1d64QPseudo_VST1d8Q") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #569
  {DBGFIELD("VST1d16Qwb_fixed_VST1d16Qwb_register_VST1d32Qwb_fixed_VST1d32Qwb_register_VST1d64Qwb_fixed_VST1d64Qwb_register_VST1d8Qwb_fixed_VST1d8Qwb_register") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #570
  {DBGFIELD("VST1d64QPseudoWB_fixed_VST1d64QPseudoWB_register") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #571
  {DBGFIELD("VST2b16_VST2b32_VST2b8_VST2d16_VST2d32_VST2d8") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #572
  {DBGFIELD("VST2b16wb_fixed_VST2b16wb_register_VST2b32wb_fixed_VST2b32wb_register_VST2b8wb_fixed_VST2b8wb_register_VST2d16wb_fixed_VST2d16wb_register_VST2d32wb_fixed_VST2d32wb_register_VST2d8wb_fixed_VST2d8wb_register") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #573
  {DBGFIELD("VST2q16_VST2q16Pseudo_VST2q32_VST2q32Pseudo_VST2q8_VST2q8Pseudo") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #574
  {DBGFIELD("VST2q16PseudoWB_fixed_VST2q16PseudoWB_register_VST2q32PseudoWB_fixed_VST2q32PseudoWB_register_VST2q8PseudoWB_fixed_VST2q8PseudoWB_register") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #575
  {DBGFIELD("VST2q16wb_fixed_VST2q16wb_register_VST2q32wb_fixed_VST2q32wb_register_VST2q8wb_fixed_VST2q8wb_register") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #576
  {DBGFIELD("VST3d16_VST3d16Pseudo_VST3d32_VST3d32Pseudo_VST3d8_VST3d8Pseudo_VST3q16_VST3q16oddPseudo_VST3q32_VST3q32oddPseudo_VST3q8_VST3q8oddPseudo") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #577
  {DBGFIELD("VST3d16Pseudo_UPD_VST3d16_UPD_VST3d32Pseudo_UPD_VST3d32_UPD_VST3d8Pseudo_UPD_VST3d8_UPD_VST3q16Pseudo_UPD_VST3q16_UPD_VST3q16oddPseudo_UPD_VST3q32Pseudo_UPD_VST3q32_UPD_VST3q32oddPseudo_UPD_VST3q8Pseudo_UPD_VST3q8_UPD_VST3q8oddPseudo_UPD") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #578
  {DBGFIELD("VST4d16_VST4d16Pseudo_VST4d32_VST4d32Pseudo_VST4d8_VST4d8Pseudo_VST4q16_VST4q16oddPseudo_VST4q32_VST4q32oddPseudo_VST4q8_VST4q8oddPseudo") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #579
  {DBGFIELD("VST4d16Pseudo_UPD_VST4d16_UPD_VST4d32Pseudo_UPD_VST4d32_UPD_VST4d8Pseudo_UPD_VST4d8_UPD_VST4q16Pseudo_UPD_VST4q16_UPD_VST4q16oddPseudo_UPD_VST4q32Pseudo_UPD_VST4q32_UPD_VST4q32oddPseudo_UPD_VST4q8Pseudo_UPD_VST4q8_UPD_VST4q8oddPseudo_UPD") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #580
  {DBGFIELD("VST1LNd16_VST1LNd32_VST1LNd8_VST1LNq16Pseudo_VST1LNq32Pseudo_VST1LNq8Pseudo") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #581
  {DBGFIELD("VST1LNd16_UPD_VST1LNd32_UPD_VST1LNd8_UPD_VST1LNq16Pseudo_UPD_VST1LNq32Pseudo_UPD_VST1LNq8Pseudo_UPD") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #582
  {DBGFIELD("VST2LNd16_VST2LNd16Pseudo_VST2LNd32_VST2LNd32Pseudo_VST2LNd8_VST2LNd8Pseudo_VST2LNq16_VST2LNq16Pseudo_VST2LNq32_VST2LNq32Pseudo") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #583
  {DBGFIELD("VST2LNd16Pseudo_UPD_VST2LNd16_UPD_VST2LNd32Pseudo_UPD_VST2LNd32_UPD_VST2LNd8Pseudo_UPD_VST2LNd8_UPD_VST2LNq16Pseudo_UPD_VST2LNq16_UPD_VST2LNq32Pseudo_UPD_VST2LNq32_UPD") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #584
  {DBGFIELD("VST3LNd16_VST3LNd16Pseudo_VST3LNd32_VST3LNd32Pseudo_VST3LNd8_VST3LNd8Pseudo_VST3LNq16_VST3LNq16Pseudo_VST3LNq32_VST3LNq32Pseudo") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #585
  {DBGFIELD("VST3LNd16Pseudo_UPD_VST3LNd16_UPD_VST3LNd32Pseudo_UPD_VST3LNd32_UPD_VST3LNd8Pseudo_UPD_VST3LNd8_UPD_VST3LNq16Pseudo_UPD_VST3LNq16_UPD_VST3LNq32Pseudo_UPD_VST3LNq32_UPD") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #586
  {DBGFIELD("VST4LNd16_VST4LNd16Pseudo_VST4LNd32_VST4LNd32Pseudo_VST4LNd8_VST4LNd8Pseudo_VST4LNq16_VST4LNq16Pseudo_VST4LNq32_VST4LNq32Pseudo") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #587
  {DBGFIELD("VST4LNd16Pseudo_UPD_VST4LNd16_UPD_VST4LNd32Pseudo_UPD_VST4LNd32_UPD_VST4LNd8Pseudo_UPD_VST4LNd8_UPD_VST4LNq16Pseudo_UPD_VST4LNq16_UPD_VST4LNq32Pseudo_UPD_VST4LNq32_UPD") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #588
  {DBGFIELD("VDIVS")              1, 0, 0,  3, 2, 29, 1,  0, 0}, // #589
  {DBGFIELD("VSQRTS")             1, 0, 0,  3, 2, 45, 1,  0, 0}, // #590
  {DBGFIELD("VDIVD")              1, 0, 0,  3, 2, 28, 1,  0, 0}, // #591
  {DBGFIELD("VSQRTD")             1, 0, 0,  3, 2, 44, 1,  0, 0}, // #592
  {DBGFIELD("ABS")                0, 0, 0,  0, 0,  0, 0,  0, 0}, // #593
  {DBGFIELD("SwiftWriteP01TwoCycle_ReadALU") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #594
  {DBGFIELD("WriteALU_ReadALU")   0, 0, 0,  0, 0,  0, 0,  0, 0}, // #595
  {DBGFIELD("SwiftWriteP01ThreeCycleTwoUops_anonymous_3044") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #596
  {DBGFIELD("SwiftWriteP01TwoCycle_NoReadAdvance") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #597
  {DBGFIELD("SwiftWriteP0ThreeCycleThreeUops_anonymous_3044") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #598
  {DBGFIELD("SwiftWriteP01OneCycle_ReadALU") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #599
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteIssue") 1, 0, 0,  7, 2, 46, 4,  0, 0}, // #600
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue") 1, 0, 0, 46, 2, 50, 6,  0, 0}, // #601
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 1, 0, 0, 48, 2, 56, 8,  0, 0}, // #602
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 1, 0, 0, 50, 2, 64, 10,  0, 0}, // #603
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 1, 0, 0, 52, 2, 74, 12,  0, 0}, // #604
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 1, 0, 0, 54, 2, 86, 14,  0, 0}, // #605
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 1, 0, 0, 56, 2, 100, 16,  0, 0}, // #606
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 1, 0, 0, 58, 2, 116, 18,  0, 0}, // #607
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue") 1, 0, 0, 46, 2, 134, 18,  0, 0}, // #608
  {DBGFIELD("A9WriteAdr_A9WriteL1_A9WriteL1Hi_A9WriteIssue") 1, 0, 0,  7, 2, 152, 4,  0, 0}, // #609
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 1, 0, 0, 46, 2, 156, 6,  0, 0}, // #610
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 1, 0, 0, 48, 2, 162, 8,  0, 0}, // #611
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 1, 0, 0, 50, 2, 170, 10,  0, 0}, // #612
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 1, 0, 0, 52, 2, 180, 12,  0, 0}, // #613
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 1, 0, 0, 54, 2, 192, 14,  0, 0}, // #614
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 1, 0, 0, 56, 2, 206, 16,  0, 0}, // #615
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 1, 0, 0, 58, 2, 222, 18,  0, 0}, // #616
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 1, 0, 0, 46, 2, 240, 18,  0, 0}, // #617
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteB") 1, 0, 0, 60, 3, 258, 4,  0, 0}, // #618
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB") 1, 0, 0, 63, 3, 262, 6,  0, 0}, // #619
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 1, 0, 0, 66, 3, 268, 8,  0, 0}, // #620
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 1, 0, 0, 69, 3, 276, 10,  0, 0}, // #621
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 1, 0, 0, 72, 3, 286, 12,  0, 0}, // #622
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 1, 0, 0, 75, 3, 298, 14,  0, 0}, // #623
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 1, 0, 0, 78, 3, 312, 16,  0, 0}, // #624
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 1, 0, 0, 81, 3, 328, 18,  0, 0}, // #625
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB") 1, 0, 0, 63, 3, 346, 18,  0, 0}, // #626
  {DBGFIELD("SwiftWriteP01ThreeCycleTwoUops") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #627
  {DBGFIELD("SwiftWriteP01TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #628
  {DBGFIELD("WriteALU")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #629
  {DBGFIELD("A9WriteAdr_(A9WriteIssue_A9WriteLfpOp)") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #630
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #631
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 1, 0, 0, 84, 3, 46, 2,  0, 0}, // #632
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 1, 0, 0, 87, 3, 52, 2,  0, 0}, // #633
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 1, 0, 0, 90, 3, 60, 2,  0, 0}, // #634
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 1, 0, 0, 93, 3, 70, 2,  0, 0}, // #635
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 1, 0, 0, 96, 3, 82, 2,  0, 0}, // #636
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 1, 0, 0, 99, 3, 96, 2,  0, 0}, // #637
  {DBGFIELD("A9WriteAdr_A9WriteLMfp1_A9WriteL1Hi") 1, 0, 0, 31, 3, 260, 3,  0, 0}, // #638
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)") 2, 0, 0, 34, 3, 364, 5,  0, 0}, // #639
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 3, 0, 0, 84, 3, 369, 7,  0, 0}, // #640
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 4, 0, 0, 87, 3, 376, 9,  0, 0}, // #641
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 5, 0, 0, 90, 3, 385, 11,  0, 0}, // #642
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 6, 0, 0, 93, 3, 396, 13,  0, 0}, // #643
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 7, 0, 0, 96, 3, 409, 15,  0, 0}, // #644
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 8, 0, 0, 99, 3, 424, 17,  0, 0}, // #645
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 2, 0, 0, 34, 3, 441, 17,  0, 0}, // #646
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp)_A9WriteAdr") 1, 0, 0, 31, 3, 14, 2,  0, 0}, // #647
  {DBGFIELD("A9WriteLMfp1_A9WriteL1Hi_A9WriteAdr") 1, 0, 0, 31, 3, 458, 3,  0, 0}, // #648
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr)") 1, 0, 0, 34, 3, 30, 2,  0, 0}, // #649
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)") 1, 0, 0, 84, 3, 46, 2,  0, 0}, // #650
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 1, 0, 0, 87, 3, 52, 2,  0, 0}, // #651
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 1, 0, 0, 90, 3, 60, 2,  0, 0}, // #652
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 1, 0, 0, 93, 3, 70, 2,  0, 0}, // #653
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 1, 0, 0, 96, 3, 82, 2,  0, 0}, // #654
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 1, 0, 0, 99, 3, 96, 2,  0, 0}, // #655
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)") 2, 0, 0, 34, 3, 461, 5,  0, 0}, // #656
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)") 3, 0, 0, 84, 3, 466, 7,  0, 0}, // #657
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 4, 0, 0, 87, 3, 473, 9,  0, 0}, // #658
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 5, 0, 0, 90, 3, 482, 11,  0, 0}, // #659
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 6, 0, 0, 93, 3, 493, 13,  0, 0}, // #660
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 7, 0, 0, 96, 3, 506, 15,  0, 0}, // #661
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 8, 0, 0, 99, 3, 521, 17,  0, 0}, // #662
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)") 2, 0, 0, 34, 3, 538, 17,  0, 0}, // #663
  {DBGFIELD("SwiftWriteP01TwoCycle_anonymous_3044") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #664
  {DBGFIELD("WriteALU_anonymous_3044") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #665
  {DBGFIELD("WriteALU_NoReadAdvance") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #666
  {DBGFIELD("SwiftWriteP01OneCycle_ReadALU_ReadALU") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #667
  {DBGFIELD("SwiftWriteP01TwoCycle_ReadALU_ReadALU") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #668
  {DBGFIELD("SwiftWriteP01OneCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #669
  {DBGFIELD("(SwiftWriteP0OneCycle_SwiftWriteP0OneCycle)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #670
  {DBGFIELD("SwiftWriteP0OneCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #671
  {DBGFIELD("SwiftWriteP0P01FiveCycleTwoUops_ReadALU_ReadALU_anonymous_3075") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #672
  {DBGFIELD("SwiftWriteP0FourCycle_ReadALU_ReadALU_ReadALU") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #673
  {DBGFIELD("SwiftWriteP0P01FiveCycleTwoUops") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #674
  {DBGFIELD("SwiftWriteP0FourCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #675
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #676
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #677
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #678
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #679
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #680
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #681
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #682
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #683
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #684
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #685
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #686
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #687
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #688
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #689
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #690
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLDMAddrNoWB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #691
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #692
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #693
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #694
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #695
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #696
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #697
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #698
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #699
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #700
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #701
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #702
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #703
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #704
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #705
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #706
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #707
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #708
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #709
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #710
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #711
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #712
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #713
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #714
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #715
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #716
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #717
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #718
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #719
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #720
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #721
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #722
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteP1TwoCycle") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #723
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #724
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #725
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #726
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #727
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #728
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #729
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #730
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #731
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #732
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #733
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #734
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #735
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #736
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #737
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #738
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #739
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #740
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #741
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #742
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #743
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #744
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #745
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #746
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #747
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #748
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #749
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #750
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #751
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #752
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #753
  {DBGFIELD("SwiftWriteLM4Cy")    0, 0, 0,  0, 0,  0, 0,  0, 0}, // #754
  {DBGFIELD("SwiftWriteLM4Cy_SwiftWriteLM4CyNo") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #755
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #756
  {DBGFIELD("SwiftWriteLM4Cy_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #757
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #758
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #759
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #760
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #761
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #762
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #763
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #764
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM11Cy_SwiftWriteLM11Cy_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #765
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #766
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #767
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM17Cy_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #768
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM18CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm4") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #769
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #770
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM4Cy") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #771
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM4Cy_SwiftWriteLM4CyNo") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #772
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #773
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM4Cy_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #774
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #775
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #776
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #777
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #778
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #779
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #780
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #781
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM11Cy_SwiftWriteLM11Cy_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #782
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #783
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #784
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM17Cy_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #785
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM18CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm4") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #786
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #787
  {DBGFIELD("SwiftWriteStIncAddr") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #788
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteStIncAddr") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #789
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #790
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #791
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #792
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #793
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #794
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #795
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #796
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #797
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 0, 0, 0,  0, 0,  0, 0,  0, 0} // #798
}; // CortexA9ModelSchedClasses

// {Name, NumMicroOps, BeginGroup, EndGroup, WriteProcResIdx,#, WriteLatencyIdx,#, ReadAdvanceIdx,#}
static const llvm::MCSchedClassDesc SwiftModelSchedClasses[] = {
  {DBGFIELD("InvalidSchedClass")  65535, 0, 0,  0, 0,  0, 0,  0, 0},
  {DBGFIELD("IIC_iALUi_WriteALU_ReadALU") 1, 0, 0,  6, 1,  1, 1,  0, 1}, // #1
  {DBGFIELD("IIC_iALUr_WriteALU_ReadALU_ReadALU") 1, 0, 0,  6, 1,  1, 1, 86, 2}, // #2
  {DBGFIELD("IIC_iALUsr_WriteALUsi_ReadALU") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #3
  {DBGFIELD("IIC_iALUsr_WriteALUsr_ReadALUsr") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #4
  {DBGFIELD("IIC_iALUsr_WriteALUSsr_ReadALUsr") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #5
  {DBGFIELD("IIC_iBITi_WriteALU_ReadALU") 1, 0, 0,  6, 1,  1, 1,  0, 1}, // #6
  {DBGFIELD("IIC_iBITr_WriteALU_ReadALU_ReadALU") 1, 0, 0,  6, 1,  1, 1, 86, 2}, // #7
  {DBGFIELD("IIC_iBITsr_WriteALUsi_ReadALU") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #8
  {DBGFIELD("IIC_iBITsr_WriteALUsr_ReadALUsr") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #9
  {DBGFIELD("IIC_Br_WriteBr")     1, 0, 0, 61, 2,  0, 1,  0, 0}, // #10
  {DBGFIELD("IIC_iUNAsi")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #11
  {DBGFIELD("IIC_Br_WriteBrL")    1, 0, 0, 61, 2,  2, 1,  0, 0}, // #12
  {DBGFIELD("WriteBrL")           1, 0, 0, 61, 2,  2, 1,  0, 0}, // #13
  {DBGFIELD("IIC_Br_WriteBrTbl")  1, 0, 0, 102, 3,  0, 1,  0, 0}, // #14
  {DBGFIELD("WriteBr")            1, 0, 0, 61, 2,  0, 1,  0, 0}, // #15
  {DBGFIELD("IIC_iUNAr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #16
  {DBGFIELD("IIC_iCMPi_WriteCMP_ReadALU") 1, 0, 0,  6, 1,  1, 1,  0, 1}, // #17
  {DBGFIELD("IIC_iCMPr_WriteCMP_ReadALU_ReadALU") 1, 0, 0,  6, 1,  1, 1, 86, 2}, // #18
  {DBGFIELD("IIC_iCMPsr_WriteCMPsi_ReadALU") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #19
  {DBGFIELD("IIC_iCMPsr_WriteCMPsr_ReadALU") 1, 0, 0,  6, 1,  2, 1,  0, 1}, // #20
  {DBGFIELD("IIC_fpUNA64")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #21
  {DBGFIELD("IIC_fpUNA32")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #22
  {DBGFIELD("IIC_fpSTAT")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #23
  {DBGFIELD("IIC_iLoad_m")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #24
  {DBGFIELD("IIC_iLoad_mu")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #25
  {DBGFIELD("IIC_iLoad_mBr")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #26
  {DBGFIELD("IIC_iLoad_bh_ru")    0, 0, 0,  0, 0,  0, 0,  0, 0}, // #27
  {DBGFIELD("IIC_iLoad_bh_iu")    0, 0, 0,  0, 0,  0, 0,  0, 0}, // #28
  {DBGFIELD("IIC_iLoad_bh_r")     0, 0, 0,  0, 0,  0, 0,  0, 0}, // #29
  {DBGFIELD("IIC_iLoad_bh_si")    0, 0, 0,  0, 0,  0, 0,  0, 0}, // #30
  {DBGFIELD("IIC_iLoad_d_r")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #31
  {DBGFIELD("IIC_iLoad_d_ru")     0, 0, 0,  0, 0,  0, 0,  0, 0}, // #32
  {DBGFIELD("IIC_iLoad_i")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #33
  {DBGFIELD("IIC_iLoadiALU")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #34
  {DBGFIELD("IIC_iLoad_ru")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #35
  {DBGFIELD("IIC_iLoad_iu")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #36
  {DBGFIELD("IIC_iLoad_r")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #37
  {DBGFIELD("IIC_iLoad_si")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #38
  {DBGFIELD("IIC_iMAC32")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #39
  {DBGFIELD("IIC_iCMOVi_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #40
  {DBGFIELD("IIC_iMOVi_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #41
  {DBGFIELD("IIC_iCMOVix2")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #42
  {DBGFIELD("IIC_iCMOVr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #43
  {DBGFIELD("IIC_iCMOVsr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #44
  {DBGFIELD("IIC_iMOVix2addpc")   0, 0, 0,  0, 0,  0, 0,  0, 0}, // #45
  {DBGFIELD("IIC_iMOVix2ld")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #46
  {DBGFIELD("IIC_iMOVix2")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #47
  {DBGFIELD("IIC_iMOVr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #48
  {DBGFIELD("IIC_iMOVsr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #49
  {DBGFIELD("IIC_iMOVsi_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #50
  {DBGFIELD("IIC_iMUL32")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #51
  {DBGFIELD("IIC_iMVNi_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #52
  {DBGFIELD("IIC_iMVNr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #53
  {DBGFIELD("IIC_iMVNsr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #54
  {DBGFIELD("IIC_iALUr_WriteALU_ReadALU") 1, 0, 0,  6, 1,  1, 1,  0, 1}, // #55
  {DBGFIELD("IIC_iStore_r")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #56
  {DBGFIELD("IIC_iStore_bh_r")    0, 0, 0,  0, 0,  0, 0,  0, 0}, // #57
  {DBGFIELD("IIC_iALUsi_WriteALUsi_ReadALU") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #58
  {DBGFIELD("IIC_iBITsi_WriteALUsi_ReadALU") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #59
  {DBGFIELD("IIC_Preload_WritePreLd") 1, 0, 0, 105, 1,  0, 1,  0, 0}, // #60
  {DBGFIELD("IIC_iDIV")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #61
  {DBGFIELD("IIC_iMAC16")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #62
  {DBGFIELD("IIC_iMAC64")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #63
  {DBGFIELD("IIC_iMUL16")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #64
  {DBGFIELD("IIC_iMUL64")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #65
  {DBGFIELD("IIC_iStore_m")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #66
  {DBGFIELD("IIC_iStore_mu")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #67
  {DBGFIELD("IIC_iStore_bh_ru")   0, 0, 0,  0, 0,  0, 0,  0, 0}, // #68
  {DBGFIELD("IIC_iStore_bh_iu")   0, 0, 0,  0, 0,  0, 0,  0, 0}, // #69
  {DBGFIELD("IIC_iStore_ru")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #70
  {DBGFIELD("IIC_iStore_bh_si")   0, 0, 0,  0, 0,  0, 0,  0, 0}, // #71
  {DBGFIELD("IIC_iStore_d_r")     0, 0, 0,  0, 0,  0, 0,  0, 0}, // #72
  {DBGFIELD("IIC_iStore_d_ru")    0, 0, 0,  0, 0,  0, 0,  0, 0}, // #73
  {DBGFIELD("IIC_iStore_iu")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #74
  {DBGFIELD("IIC_iStore_si")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #75
  {DBGFIELD("IIC_Br")             0, 0, 0,  0, 0,  0, 0,  0, 0}, // #76
  {DBGFIELD("IIC_iEXTAr_WriteALUsr") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #77
  {DBGFIELD("IIC_iEXTr_WriteALUsi") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #78
  {DBGFIELD("IIC_iTSTi_WriteCMP_ReadALU") 1, 0, 0,  6, 1,  1, 1,  0, 1}, // #79
  {DBGFIELD("IIC_iTSTr_WriteCMP_ReadALU_ReadALU") 1, 0, 0,  6, 1,  1, 1, 86, 2}, // #80
  {DBGFIELD("IIC_iTSTsr_WriteCMPsi_ReadALU") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #81
  {DBGFIELD("IIC_iTSTsr_WriteCMPsr_ReadALU") 1, 0, 0,  6, 1,  2, 1,  0, 1}, // #82
  {DBGFIELD("WriteALU_ReadALU_ReadALU") 1, 0, 0,  6, 1,  1, 1, 86, 2}, // #83
  {DBGFIELD("IIC_VABAD")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #84
  {DBGFIELD("IIC_VABAQ")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #85
  {DBGFIELD("IIC_VSUBi4Q")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #86
  {DBGFIELD("IIC_VBIND")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #87
  {DBGFIELD("IIC_VBINQ")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #88
  {DBGFIELD("IIC_VSUBi4D")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #89
  {DBGFIELD("IIC_VUNAD")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #90
  {DBGFIELD("IIC_VUNAQ")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #91
  {DBGFIELD("IIC_VUNAiQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #92
  {DBGFIELD("IIC_VUNAiD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #93
  {DBGFIELD("IIC_fpALU64")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #94
  {DBGFIELD("IIC_VBINi4D")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #95
  {DBGFIELD("IIC_VSHLiD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #96
  {DBGFIELD("IIC_fpALU32")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #97
  {DBGFIELD("IIC_VSUBiD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #98
  {DBGFIELD("IIC_VBINiQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #99
  {DBGFIELD("IIC_VBINiD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #100
  {DBGFIELD("IIC_VMOVImm")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #101
  {DBGFIELD("IIC_VCNTiD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #102
  {DBGFIELD("IIC_VCNTiQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #103
  {DBGFIELD("IIC_fpCMP64")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #104
  {DBGFIELD("IIC_fpCMP32")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #105
  {DBGFIELD("IIC_fpCVTSH")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #106
  {DBGFIELD("IIC_fpCVTHS")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #107
  {DBGFIELD("IIC_fpCVTDS")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #108
  {DBGFIELD("IIC_fpCVTSD")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #109
  {DBGFIELD("IIC_fpDIV64")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #110
  {DBGFIELD("IIC_fpDIV32")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #111
  {DBGFIELD("IIC_VMOVIS")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #112
  {DBGFIELD("IIC_VMOVD")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #113
  {DBGFIELD("IIC_VMOVQ")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #114
  {DBGFIELD("IIC_VEXTD")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #115
  {DBGFIELD("IIC_VEXTQ")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #116
  {DBGFIELD("IIC_fpFMAC64")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #117
  {DBGFIELD("IIC_fpFMAC32")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #118
  {DBGFIELD("IIC_VFMACD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #119
  {DBGFIELD("IIC_VFMACQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #120
  {DBGFIELD("IIC_VMOVSI")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #121
  {DBGFIELD("IIC_VBINi4Q")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #122
  {DBGFIELD("IIC_VLD1dup")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #123
  {DBGFIELD("IIC_VLD1dupu")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #124
  {DBGFIELD("IIC_VLD1ln")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #125
  {DBGFIELD("IIC_VLD1lnu")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #126
  {DBGFIELD("IIC_VLD1")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #127
  {DBGFIELD("IIC_VLD1x4")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #128
  {DBGFIELD("IIC_VLD1x2u")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #129
  {DBGFIELD("IIC_VLD1x3")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #130
  {DBGFIELD("IIC_VLD1u")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #131
  {DBGFIELD("IIC_VLD1x2")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #132
  {DBGFIELD("IIC_VLD2dup")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #133
  {DBGFIELD("IIC_VLD2dupu")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #134
  {DBGFIELD("IIC_VLD2ln")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #135
  {DBGFIELD("IIC_VLD2lnu")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #136
  {DBGFIELD("IIC_VLD2")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #137
  {DBGFIELD("IIC_VLD2u")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #138
  {DBGFIELD("IIC_VLD2x2")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #139
  {DBGFIELD("IIC_VLD2x2u")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #140
  {DBGFIELD("IIC_VLD3dup")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #141
  {DBGFIELD("IIC_VLD3dupu")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #142
  {DBGFIELD("IIC_VLD3ln")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #143
  {DBGFIELD("IIC_VLD3lnu")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #144
  {DBGFIELD("IIC_VLD3")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #145
  {DBGFIELD("IIC_VLD3u")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #146
  {DBGFIELD("IIC_VLD4dup")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #147
  {DBGFIELD("IIC_VLD4dupu")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #148
  {DBGFIELD("IIC_VLD4ln")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #149
  {DBGFIELD("IIC_VLD4lnu")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #150
  {DBGFIELD("IIC_VLD4")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #151
  {DBGFIELD("IIC_VLD4u")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #152
  {DBGFIELD("IIC_fpLoad_mu")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #153
  {DBGFIELD("IIC_fpLoad_m")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #154
  {DBGFIELD("IIC_fpLoad64")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #155
  {DBGFIELD("IIC_fpLoad32")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #156
  {DBGFIELD("IIC_fpMAC64")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #157
  {DBGFIELD("IIC_VMACi32D")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #158
  {DBGFIELD("IIC_VMACi16D")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #159
  {DBGFIELD("IIC_fpMAC32")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #160
  {DBGFIELD("IIC_VMACD")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #161
  {DBGFIELD("IIC_VMACQ")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #162
  {DBGFIELD("IIC_VMACi32Q")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #163
  {DBGFIELD("IIC_VMACi16Q")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #164
  {DBGFIELD("IIC_fpMOVID")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #165
  {DBGFIELD("IIC_VQUNAiD")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #166
  {DBGFIELD("IIC_VMOVN")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #167
  {DBGFIELD("IIC_fpMOVDI")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #168
  {DBGFIELD("IIC_fpMOVSI")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #169
  {DBGFIELD("IIC_fpMOVIS")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #170
  {DBGFIELD("IIC_fpMUL64")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #171
  {DBGFIELD("IIC_VMULi16D")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #172
  {DBGFIELD("IIC_VMULi32D")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #173
  {DBGFIELD("IIC_fpMUL32")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #174
  {DBGFIELD("IIC_VFMULD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #175
  {DBGFIELD("IIC_VFMULQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #176
  {DBGFIELD("IIC_VMULi16Q")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #177
  {DBGFIELD("IIC_VMULi32Q")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #178
  {DBGFIELD("IIC_VSHLiQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #179
  {DBGFIELD("IIC_VPALiQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #180
  {DBGFIELD("IIC_VPALiD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #181
  {DBGFIELD("IIC_VPBIND")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #182
  {DBGFIELD("IIC_VQUNAiQ")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #183
  {DBGFIELD("IIC_VSHLi4Q")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #184
  {DBGFIELD("IIC_VSHLi4D")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #185
  {DBGFIELD("IIC_VRECSD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #186
  {DBGFIELD("IIC_VRECSQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #187
  {DBGFIELD("IIC_VMOVISL")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #188
  {DBGFIELD("IIC_fpCVTID_WriteCvtFP") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #189
  {DBGFIELD("IIC_fpCVTIS_WriteCvtFP") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #190
  {DBGFIELD("IIC_fpCVTID")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #191
  {DBGFIELD("IIC_fpCVTIS")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #192
  {DBGFIELD("IIC_fpSQRT64")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #193
  {DBGFIELD("IIC_fpSQRT32")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #194
  {DBGFIELD("IIC_VST1ln")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #195
  {DBGFIELD("IIC_VST1lnu")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #196
  {DBGFIELD("IIC_VST1")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #197
  {DBGFIELD("IIC_VST1x4")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #198
  {DBGFIELD("IIC_VLD1x4u")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #199
  {DBGFIELD("IIC_VST1x3")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #200
  {DBGFIELD("IIC_VLD1x3u")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #201
  {DBGFIELD("IIC_VST1x4u")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #202
  {DBGFIELD("IIC_VST1x3u")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #203
  {DBGFIELD("IIC_VST1x2")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #204
  {DBGFIELD("IIC_VST2ln")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #205
  {DBGFIELD("IIC_VST2lnu")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #206
  {DBGFIELD("IIC_VST2")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #207
  {DBGFIELD("IIC_VST2x2")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #208
  {DBGFIELD("IIC_VST2x2u")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #209
  {DBGFIELD("IIC_VST3ln")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #210
  {DBGFIELD("IIC_VST3lnu")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #211
  {DBGFIELD("IIC_VST3")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #212
  {DBGFIELD("IIC_VST3u")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #213
  {DBGFIELD("IIC_VST4ln")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #214
  {DBGFIELD("IIC_VST4lnu")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #215
  {DBGFIELD("IIC_VST4")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #216
  {DBGFIELD("IIC_VST4u")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #217
  {DBGFIELD("IIC_fpStore_mu")     0, 0, 0,  0, 0,  0, 0,  0, 0}, // #218
  {DBGFIELD("IIC_fpStore_m")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #219
  {DBGFIELD("IIC_fpStore64")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #220
  {DBGFIELD("IIC_fpStore32")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #221
  {DBGFIELD("IIC_VSUBiQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #222
  {DBGFIELD("IIC_VTB1")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #223
  {DBGFIELD("IIC_VTB2")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #224
  {DBGFIELD("IIC_VTB3")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #225
  {DBGFIELD("IIC_VTB4")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #226
  {DBGFIELD("IIC_VTBX1")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #227
  {DBGFIELD("IIC_VTBX2")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #228
  {DBGFIELD("IIC_VTBX3")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #229
  {DBGFIELD("IIC_VTBX4")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #230
  {DBGFIELD("IIC_fpCVTDI_WriteCvtFP") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #231
  {DBGFIELD("IIC_fpCVTSI_WriteCvtFP") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #232
  {DBGFIELD("IIC_fpCVTDI")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #233
  {DBGFIELD("IIC_fpCVTSI")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #234
  {DBGFIELD("IIC_VPERMD")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #235
  {DBGFIELD("IIC_VPERMQ")         0, 0, 0,  0, 0,  0, 0,  0, 0}, // #236
  {DBGFIELD("IIC_VPERMQ3")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #237
  {DBGFIELD("IIC_iALUsi_WriteALUsi_ReadALUsr") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #238
  {DBGFIELD("IIC_iBITi")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #239
  {DBGFIELD("IIC_iCMPsi_WriteCMPsi_ReadALU_ReadALU") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #240
  {DBGFIELD("IIC_iCMPi_WriteCMP") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #241
  {DBGFIELD("IIC_iCMPr_WriteCMP") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #242
  {DBGFIELD("IIC_iCMPsi_WriteCMPsi") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #243
  {DBGFIELD("IIC_iALUx")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #244
  {DBGFIELD("IIC_iLoad_bh_i")     0, 0, 0,  0, 0,  0, 0,  0, 0}, // #245
  {DBGFIELD("IIC_iLoad_d_i")      0, 0, 0,  0, 0,  0, 0,  0, 0}, // #246
  {DBGFIELD("IIC_iCMOVsi_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #247
  {DBGFIELD("IIC_iMOVi")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #248
  {DBGFIELD("IIC_iMVNsi_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #249
  {DBGFIELD("IIC_iALUsir_WriteALUsi_ReadALU") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #250
  {DBGFIELD("IIC_iStore_bh_i")    0, 0, 0,  0, 0,  0, 0,  0, 0}, // #251
  {DBGFIELD("IIC_iStore_i")       0, 0, 0,  0, 0,  0, 0,  0, 0}, // #252
  {DBGFIELD("IIC_iEXTAsr")        0, 0, 0,  0, 0,  0, 0,  0, 0}, // #253
  {DBGFIELD("IIC_iEXTr")          0, 0, 0,  0, 0,  0, 0,  0, 0}, // #254
  {DBGFIELD("IIC_iTSTi_WriteCMP") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #255
  {DBGFIELD("IIC_iTSTr_WriteCMP") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #256
  {DBGFIELD("IIC_iTSTsi_WriteCMPsi") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #257
  {DBGFIELD("IIC_iALUr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #258
  {DBGFIELD("IIC_iALUi_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #259
  {DBGFIELD("IIC_iBITr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #260
  {DBGFIELD("IIC_iPop")           0, 0, 0,  0, 0,  0, 0,  0, 0}, // #261
  {DBGFIELD("IIC_iPop_Br_WriteBrL") 1, 0, 0, 61, 2,  2, 1,  0, 0}, // #262
  {DBGFIELD("IIC_iTSTr_WriteALU") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #263
  {DBGFIELD("ANDri_BICri_EORri_ORRri") 1, 0, 0,  6, 1,  1, 1,  0, 1}, // #264
  {DBGFIELD("ANDrr_BICrr_EORrr_ORRrr") 1, 0, 0,  6, 1,  1, 1, 86, 2}, // #265
  {DBGFIELD("ANDrsi_BICrsi_EORrsi_ORRrsi") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #266
  {DBGFIELD("ANDrsr_BICrsr_EORrsr_ORRrsr") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #267
  {DBGFIELD("MOVCCsi_MOVCCsr")    1, 0, 0,  6, 1,  1, 1,  0, 0}, // #268
  {DBGFIELD("MOVsi_MOVsr")        1, 0, 0,  6, 1,  1, 1,  0, 0}, // #269
  {DBGFIELD("MOVsra_flag_MOVsrl_flag") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #270
  {DBGFIELD("MVNsr")              1, 0, 0,  6, 1,  1, 1,  0, 0}, // #271
  {DBGFIELD("MVNr")               1, 0, 0,  6, 1,  1, 1,  0, 0}, // #272
  {DBGFIELD("MOVCCi32imm")        2, 0, 0, 30, 1,  2, 1,  0, 0}, // #273
  {DBGFIELD("MOVi32imm")          2, 0, 0, 30, 1,  2, 1,  0, 0}, // #274
  {DBGFIELD("MOV_ga_pcrel")       3, 0, 0, 39, 1,  3, 1,  0, 0}, // #275
  {DBGFIELD("MOV_ga_pcrel_ldr")   3, 0, 0, 39, 1,  3, 1,  0, 0}, // #276
  {DBGFIELD("SEL")                65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #277
  {DBGFIELD("BFC_BFI_SBFX_UBFX")  1, 0, 0,  6, 1,  2, 1,  0, 0}, // #278
  {DBGFIELD("MLA_MLAv5_MLS_SMMLA_SMMLAR_SMMLS_SMMLSR") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #279
  {DBGFIELD("MUL_MULv5_SMMUL_SMMULR") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #280
  {DBGFIELD("SMLAL_SMLALBB_SMLALBT_SMLALTB_SMLALTT_SMLALv5_UMAAL_UMLAL_UMLALv5") 5, 0, 0, 106, 2, 555, 2, 88, 4}, // #281
  {DBGFIELD("SMULL_SMULLv5_UMULL_UMULLv5") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #282
  {DBGFIELD("SMLAD_SMLADX_SMLALD_SMLALDX_SMLSD_SMLSDX_SMLSLD_SMLSLDX_SMUAD_SMUADX_SMUSD_SMUSDX") 5, 0, 0, 106, 2, 555, 2, 88, 4}, // #283
  {DBGFIELD("SMULBB_SMULBT_SMULTB_SMULTT_SMULWB_SMULWT") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #284
  {DBGFIELD("SMLABB_SMLABT_SMLATB_SMLATT_SMLAWB_SMLAWT") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #285
  {DBGFIELD("LDRi12_PICLDR")      1, 0, 0,  4, 1,  3, 1,  0, 0}, // #286
  {DBGFIELD("LDRrs")              1, 0, 0,  4, 1,  3, 1,  0, 0}, // #287
  {DBGFIELD("LDRBi12_LDRH_LDRSB_LDRSH_PICLDRB_PICLDRH_PICLDRSB_PICLDRSH") 2, 0, 0, 32, 2, 18, 1,  0, 0}, // #288
  {DBGFIELD("LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE_LDRSBTi_LDRSBTr_LDRSB_POST_LDRSB_PRE_LDRSHTi_LDRSHTr_LDRSH_POST_LDRSH_PRE") 3, 0, 0, 108, 2, 284, 2,  0, 0}, // #289
  {DBGFIELD("SXTB_SXTB16_SXTH_UXTB_UXTB16_UXTH") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #290
  {DBGFIELD("t2SXTB_t2SXTB16_t2SXTH_t2UXTB_t2UXTB16_t2UXTH") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #291
  {DBGFIELD("t2MOVCCi32imm")      2, 0, 0, 30, 1,  2, 1,  0, 0}, // #292
  {DBGFIELD("t2MOVi32imm")        2, 0, 0, 30, 1,  2, 1,  0, 0}, // #293
  {DBGFIELD("t2MOV_ga_pcrel")     3, 0, 0, 39, 1,  3, 1,  0, 0}, // #294
  {DBGFIELD("t2MOVi16_ga_pcrel")  3, 0, 0, 39, 1,  3, 1,  0, 0}, // #295
  {DBGFIELD("t2SEL")              65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #296
  {DBGFIELD("t2BFC_t2SBFX_t2UBFX") 1, 0, 0,  6, 1,  2, 1,  0, 0}, // #297
  {DBGFIELD("t2BFI")              1, 0, 0,  6, 1,  2, 1,  0, 0}, // #298
  {DBGFIELD("QADD_QADD16_QADD8_QASX_QDADD_QDSUB_QSAX_QSUB_QSUB16_QSUB8_UQADD16_UQADD8_UQASX_UQSAX_UQSUB16_UQSUB8") 1, 0, 0,  6, 1,  2, 1,  0, 0}, // #299
  {DBGFIELD("SSAT_SSAT16_USAT_USAT16_t2QADD_t2QADD16_t2QADD8_t2QASX_t2QDADD_t2QDSUB_t2QSAX_t2QSUB_t2QSUB16_t2QSUB8_t2SSAT_t2SSAT16_t2UQADD16_t2UQADD8_t2UQASX_t2UQSAX_t2UQSUB16_t2UQSUB8_t2USAT_t2USAT16") 1, 0, 0,  6, 1,  2, 1,  0, 0}, // #300
  {DBGFIELD("SADD16_SADD8_SASX_SSAX_SSUB16_SSUB8_UADD16_UADD8_UASX_USAX_USUB16_USUB8") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #301
  {DBGFIELD("t2SADD16_t2SADD8_t2SASX_t2SSAX_t2SSUB16_t2SSUB8_t2UADD16_t2UADD8_t2UASX_t2USAX_t2USUB16_t2USUB8") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #302
  {DBGFIELD("SHADD16_SHADD8_SHASX_SHSAX_SHSUB16_SHSUB8_UHADD16_UHADD8_UHASX_UHSAX_UHSUB16_UHSUB8") 1, 0, 0,  6, 1,  2, 1,  0, 0}, // #303
  {DBGFIELD("SXTAB_SXTAB16_SXTAH_UXTAB_UXTAB16_UXTAH") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #304
  {DBGFIELD("t2SHADD16_t2SHADD8_t2SHASX_t2SHSAX_t2SHSUB16_t2SHSUB8_t2UHADD16_t2UHADD8_t2UHASX_t2UHSAX_t2UHSUB16_t2UHSUB8") 1, 0, 0,  6, 1,  2, 1,  0, 0}, // #305
  {DBGFIELD("t2SXTAB_t2SXTAB16_t2SXTAH_t2UXTAB_t2UXTAB16_t2UXTAH") 1, 0, 0,  6, 1,  2, 1,  0, 0}, // #306
  {DBGFIELD("USAD8")              1, 0, 0, 110, 3, 18, 1,  0, 0}, // #307
  {DBGFIELD("USADA8")             1, 0, 0, 110, 3, 18, 1, 92, 3}, // #308
  {DBGFIELD("SMUSD_SMUSDX")       1, 0, 0, 10, 2, 18, 1,  0, 0}, // #309
  {DBGFIELD("t2MUL_t2SMMUL_t2SMMULR") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #310
  {DBGFIELD("t2SMULBB_t2SMULBT_t2SMULTB_t2SMULTT_t2SMULWB_t2SMULWT") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #311
  {DBGFIELD("t2SMUSD_t2SMUSDX")   1, 0, 0, 10, 2, 18, 1,  0, 0}, // #312
  {DBGFIELD("t2MLA_t2MLS_t2SMMLA_t2SMMLAR_t2SMMLS_t2SMMLSR") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #313
  {DBGFIELD("SMUAD_SMUADX")       1, 0, 0, 10, 2, 18, 1,  0, 0}, // #314
  {DBGFIELD("t2SMUAD_t2SMUADX")   1, 0, 0, 10, 2, 18, 1,  0, 0}, // #315
  {DBGFIELD("SMLSD_SMLSDX")       65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #316
  {DBGFIELD("t2SMLABB_t2SMLABT_t2SMLATB_t2SMLATT_t2SMLAWB_t2SMLAWT") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #317
  {DBGFIELD("t2SMLSD_t2SMLSDX")   65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #318
  {DBGFIELD("SMLAD_SMLADX")       65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #319
  {DBGFIELD("t2SMLAD_t2SMLADX")   65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #320
  {DBGFIELD("SMULL_UMULL")        3, 0, 0, 113, 2, 60, 2,  0, 0}, // #321
  {DBGFIELD("t2SMULL_t2UMULL")    3, 0, 0, 113, 2, 60, 2,  0, 0}, // #322
  {DBGFIELD("t2SMLAL_t2SMLALBB_t2SMLALBT_t2SMLALD_t2SMLALDX_t2SMLALTB_t2SMLALTT_t2SMLSLD_t2SMLSLDX_t2UMAAL_t2UMLAL") 5, 0, 0, 106, 2, 555, 2, 88, 4}, // #323
  {DBGFIELD("SDIV_UDIV_t2SDIV_t2UDIV") 1, 0, 0, 115, 3, 557, 1,  0, 0}, // #324
  {DBGFIELD("LDRBi12")            1, 0, 0,  4, 1,  3, 1,  0, 0}, // #325
  {DBGFIELD("LDRBrs_t2LDRBs_t2LDRHs") 1, 0, 0,  4, 1,  3, 1,  0, 0}, // #326
  {DBGFIELD("LDREX_LDREXB_LDREXD_LDREXH_tLDRpci_pic") 1, 0, 0,  4, 1,  3, 1,  0, 0}, // #327
  {DBGFIELD("LDRi12")             1, 0, 0,  4, 1,  3, 1,  0, 0}, // #328
  {DBGFIELD("t2LDRBi12_t2LDRBi8_t2LDRBpci_t2LDRHi12_t2LDRHi8_t2LDRHpci_tLDRBi_tLDRHi") 1, 0, 0,  4, 1,  3, 1,  0, 0}, // #329
  {DBGFIELD("t2LDRi12_t2LDRi8_t2LDRpci_tLDRi_tLDRpci_tLDRspi") 1, 0, 0,  4, 1,  3, 1,  0, 0}, // #330
  {DBGFIELD("t2LDRpci_pic")       1, 0, 0,  4, 1,  3, 1,  0, 0}, // #331
  {DBGFIELD("t2LDRs")             1, 0, 0,  4, 1,  3, 1,  0, 0}, // #332
  {DBGFIELD("tLDRBr_tLDRHr")      1, 0, 0,  4, 1,  3, 1,  0, 0}, // #333
  {DBGFIELD("tLDRr")              1, 0, 0,  4, 1,  3, 1,  0, 0}, // #334
  {DBGFIELD("LDRH_PICLDRB_PICLDRH") 1, 0, 0,  4, 1,  3, 1,  0, 0}, // #335
  {DBGFIELD("LDRcp")              1, 0, 0,  4, 1,  3, 1,  0, 0}, // #336
  {DBGFIELD("t2LDRSBi12_t2LDRSBi8_t2LDRSBpci_t2LDRSHi12_t2LDRSHi8_t2LDRSHpci") 2, 0, 0, 32, 2, 18, 1,  0, 0}, // #337
  {DBGFIELD("t2LDRSBpcrel_t2LDRSHpcrel") 2, 0, 0, 32, 2, 18, 1,  0, 0}, // #338
  {DBGFIELD("t2LDRSBs_t2LDRSHs")  2, 0, 0, 32, 2, 18, 1,  0, 0}, // #339
  {DBGFIELD("tLDRSB_tLDRSH")      2, 0, 0, 32, 2, 18, 1,  0, 0}, // #340
  {DBGFIELD("LDRBT_POST_IMM_LDRBT_POST_REG_LDRB_POST_REG_LDRB_PRE_REG") 2, 0, 0, 32, 2, 25, 2,  0, 0}, // #341
  {DBGFIELD("LDRB_POST_IMM_LDRB_PRE_IMM_t2LDRB_POST_t2LDRB_PRE_t2LDRH_POST_t2LDRH_PRE") 2, 0, 0, 32, 2, 25, 2,  0, 0}, // #342
  {DBGFIELD("LDRHTi_LDRHTr_LDRH_POST_LDRH_PRE") 2, 0, 0, 32, 2, 25, 2,  0, 0}, // #343
  {DBGFIELD("LDRT_POST_IMM_LDRT_POST_REG_LDR_POST_REG_LDR_PRE_REG") 2, 0, 0, 32, 2, 25, 2,  0, 0}, // #344
  {DBGFIELD("LDR_POST_IMM_LDR_PRE_IMM_t2LDR_POST_t2LDR_PRE") 2, 0, 0, 32, 2, 25, 2,  0, 0}, // #345
  {DBGFIELD("t2LDRBT_t2LDRHT")    2, 0, 0, 32, 2, 25, 2,  0, 0}, // #346
  {DBGFIELD("t2LDRT")             2, 0, 0, 32, 2, 25, 2,  0, 0}, // #347
  {DBGFIELD("t2LDRSBT_t2LDRSHT")  3, 0, 0, 108, 2, 284, 2,  0, 0}, // #348
  {DBGFIELD("t2LDRSB_POST_t2LDRSB_PRE_t2LDRSH_POST_t2LDRSH_PRE") 3, 0, 0, 108, 2, 284, 2,  0, 0}, // #349
  {DBGFIELD("LDRD")               2, 0, 0, 22, 1, 23, 2,  0, 0}, // #350
  {DBGFIELD("t2LDRDi8")           2, 0, 0, 22, 1, 23, 2,  0, 0}, // #351
  {DBGFIELD("LDRD_POST_LDRD_PRE_t2LDRD_POST_t2LDRD_PRE") 3, 0, 0, 26, 2, 558, 3,  0, 0}, // #352
  {DBGFIELD("LDMDA_LDMDB_LDMIA_LDMIB_sysLDMDA_sysLDMDB_sysLDMIA_sysLDMIB_t2LDMDB_t2LDMIA_tLDMIA") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #353
  {DBGFIELD("LDMDA_UPD_LDMDB_UPD_LDMIA_UPD_LDMIB_UPD_sysLDMDA_UPD_sysLDMDB_UPD_sysLDMIA_UPD_sysLDMIB_UPD_t2LDMDB_UPD_t2LDMIA_UPD_tLDMIA_UPD") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #354
  {DBGFIELD("LDMIA_RET_t2LDMIA_RET") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #355
  {DBGFIELD("tPOP")               65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #356
  {DBGFIELD("tPOP_RET")           65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #357
  {DBGFIELD("PICSTR_STRi12_tSTRr") 1, 0, 0,  4, 1,  0, 1,  0, 0}, // #358
  {DBGFIELD("PICSTRB_PICSTRH_STRBi12_STRH_tSTRBr_tSTRHr") 1, 0, 0,  4, 1,  0, 1,  0, 0}, // #359
  {DBGFIELD("STRBrs_t2STRBs_t2STRHs") 1, 0, 0,  4, 1,  0, 1,  0, 0}, // #360
  {DBGFIELD("STREX_STREXB_STREXD_STREXH") 1, 0, 0,  4, 1,  0, 1,  0, 0}, // #361
  {DBGFIELD("STRrs_t2STRs")       1, 0, 0,  4, 1,  0, 1,  0, 0}, // #362
  {DBGFIELD("t2STRBi12_t2STRBi8_t2STRHi12_t2STRHi8_tSTRBi_tSTRHi") 1, 0, 0,  4, 1,  0, 1,  0, 0}, // #363
  {DBGFIELD("t2STRi12_t2STRi8_tSTRi_tSTRspi") 1, 0, 0,  4, 1,  0, 1,  0, 0}, // #364
  {DBGFIELD("STRBT_POST_STRT_POST") 2, 0, 0, 32, 2, 48, 2,  0, 0}, // #365
  {DBGFIELD("STRBT_POST_IMM_STRBT_POST_REG_STRB_POST_REG_STRB_PRE_REG_STRHTi_STRHTr_STRH_POST_STRH_PRE") 2, 0, 0, 32, 2, 48, 2,  0, 0}, // #366
  {DBGFIELD("STRB_POST_IMM_STRB_PRE_IMM_t2STRB_POST_t2STRB_PRE_t2STRH_POST") 2, 0, 0, 32, 2, 48, 2,  0, 0}, // #367
  {DBGFIELD("STRBi_preidx_STRBr_preidx_STRH_preidx_STRT_POST_IMM_STRT_POST_REG_STR_POST_REG_STR_PRE_REG_STRi_preidx_STRr_preidx_t2STRB_preidx_t2STRH_preidx_t2STR_preidx") 2, 0, 0, 32, 2, 48, 2,  0, 0}, // #368
  {DBGFIELD("STR_POST_IMM_STR_PRE_IMM_t2STRH_PRE_t2STR_POST_t2STR_PRE") 2, 0, 0, 32, 2, 48, 2,  0, 0}, // #369
  {DBGFIELD("t2STRBT_t2STRHT")    2, 0, 0, 32, 2, 48, 2,  0, 0}, // #370
  {DBGFIELD("t2STRT")             2, 0, 0, 32, 2, 48, 2,  0, 0}, // #371
  {DBGFIELD("STRD_t2STRDi8")      3, 0, 0, 26, 2, 561, 3,  0, 0}, // #372
  {DBGFIELD("STRD_POST_STRD_PRE_t2STRD_POST_t2STRD_PRE") 4, 0, 0, 35, 2, 560, 4,  0, 0}, // #373
  {DBGFIELD("STMDA_STMDB_STMIA_STMIB_sysSTMDA_sysSTMDB_sysSTMIA_sysSTMIB_t2STMDB_t2STMIA") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #374
  {DBGFIELD("STMDA_UPD_STMDB_UPD_STMIA_UPD_STMIB_UPD_sysSTMDA_UPD_sysSTMDB_UPD_sysSTMIA_UPD_sysSTMIB_UPD_t2STMDB_UPD_t2STMIA_UPD_tSTMIA_UPD") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #375
  {DBGFIELD("tPUSH")              65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #376
  {DBGFIELD("LDRLIT_ga_abs_tLDRLIT_ga_abs") 2, 0, 0, 32, 2, 25, 2,  0, 0}, // #377
  {DBGFIELD("LDRLIT_ga_pcrel_tLDRLIT_ga_pcrel") 2, 0, 0, 32, 2, 25, 2,  0, 0}, // #378
  {DBGFIELD("LDRLIT_ga_pcrel_ldr") 2, 0, 0, 32, 2, 25, 2,  0, 0}, // #379
  {DBGFIELD("ITasm")              0, 0, 0,  0, 0,  0, 1,  0, 0}, // #380
  {DBGFIELD("t2IT")               0, 0, 0,  0, 0,  0, 1,  0, 0}, // #381
  {DBGFIELD("VADDLsv2i64_VADDLsv4i32_VADDLsv8i16_VADDLuv2i64_VADDLuv4i32_VADDLuv8i16_VNEGs16d_VNEGs32d_VNEGs8d_VPADDLsv16i8_VPADDLsv2i32_VPADDLsv4i16_VPADDLsv4i32_VPADDLsv8i16_VPADDLsv8i8_VPADDLuv16i8_VPADDLuv2i32_VPADDLuv4i16_VPADDLuv4i32_VPADDLuv8i16_VPADDLuv8i8_VPADDi16_VPADDi32_VPADDi8_VSHLLi16_VSHLLi32_VSHLLi8_VSHLLsv2i64_VSHLLsv4i32_VSHLLsv8i16_VSHLLuv2i64_VSHLLuv4i32_VSHLLuv8i16_VSHLiv16i8_VSHLiv1i64_VSHLiv2i32_VSHLiv2i64_VSHLiv4i16_VSHLiv4i32_VSHLiv8i16_VSHLiv8i8_VSHLsv1i64_VSHLsv2i32_VSHLsv4i16_VSHLsv8i8_VSHLuv1i64_VSHLuv2i32_VSHLuv4i16_VSHLuv8i8_VSHRsv16i8_VSHRsv1i64_VSHRsv2i32_VSHRsv2i64_VSHRsv4i16_VSHRsv4i32_VSHRsv8i16_VSHRsv8i8_VSHRuv16i8_VSHRuv1i64_VSHRuv2i32_VSHRuv2i64_VSHRuv4i16_VSHRuv4i32_VSHRuv8i16_VSHRuv8i8_VSLIv1i64_VSLIv2i32_VSLIv4i16_VSLIv8i8_VSRIv1i64_VSRIv2i32_VSRIv4i16_VSRIv8i8_VSUBLsv2i64_VSUBLsv4i32_VSUBLsv8i16_VSUBLuv2i64_VSUBLuv4i32_VSUBLuv8i16") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #382
  {DBGFIELD("VADDWsv2i64_VADDWsv4i32_VADDWsv8i16_VADDWuv2i64_VADDWuv4i32_VADDWuv8i16_VSUBWsv2i64_VSUBWsv4i32_VSUBWsv8i16_VSUBWuv2i64_VSUBWuv4i32_VSUBWuv8i16_VSUBv1i64_VSUBv2i32_VSUBv4i16_VSUBv8i8") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #383
  {DBGFIELD("VADDv16i8_VADDv2i64_VADDv4i32_VADDv8i16_VANDq_VBICq_VBIFq_VBITq_VEORq_VORNq_VORRq") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #384
  {DBGFIELD("VADDv1i64_VADDv2i32_VADDv4i16_VADDv8i8_VANDd_VBICd_VBIFd_VBITd_VEORd_VORNd_VORRd") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #385
  {DBGFIELD("VBICiv2i32_VBICiv4i16_VBICiv4i32_VBICiv8i16_VORRiv2i32_VORRiv4i16_VORRiv4i32_VORRiv8i16") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #386
  {DBGFIELD("VBSLd_VCLSv2i32_VCLSv4i16_VCLSv8i8_VCLZv2i32_VCLZv4i16_VCLZv8i8_VCNTd") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #387
  {DBGFIELD("VBSLq_VCLSv16i8_VCLSv4i32_VCLSv8i16_VCLZv16i8_VCLZv4i32_VCLZv8i16_VCNTq") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #388
  {DBGFIELD("VHADDsv16i8_VHADDsv4i32_VHADDsv8i16_VHADDuv16i8_VHADDuv4i32_VHADDuv8i16_VRHADDsv16i8_VRHADDsv4i32_VRHADDsv8i16_VRHADDuv16i8_VRHADDuv4i32_VRHADDuv8i16_VTSTv16i8_VTSTv4i32_VTSTv8i16") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #389
  {DBGFIELD("VHADDsv2i32_VHADDsv4i16_VHADDsv8i8_VHADDuv2i32_VHADDuv4i16_VHADDuv8i8_VRHADDsv2i32_VRHADDsv4i16_VRHADDsv8i8_VRHADDuv2i32_VRHADDuv4i16_VRHADDuv8i8_VTSTv2i32_VTSTv4i16_VTSTv8i8") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #390
  {DBGFIELD("VHSUBsv16i8_VHSUBsv4i32_VHSUBsv8i16_VHSUBuv16i8_VHSUBuv4i32_VHSUBuv8i16") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #391
  {DBGFIELD("VHSUBsv2i32_VHSUBsv4i16_VHSUBsv8i8_VHSUBuv2i32_VHSUBuv4i16_VHSUBuv8i8") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #392
  {DBGFIELD("VNEGf32q")           1, 0, 0, 10, 2,  2, 1,  0, 0}, // #393
  {DBGFIELD("VNEGfd")             1, 0, 0, 10, 2,  2, 1,  0, 0}, // #394
  {DBGFIELD("VNEGs16q_VNEGs32q_VNEGs8q_VSHLsv16i8_VSHLsv2i64_VSHLsv4i32_VSHLsv8i16_VSHLuv16i8_VSHLuv2i64_VSHLuv4i32_VSHLuv8i16_VSLIv16i8_VSLIv2i64_VSLIv4i32_VSLIv8i16_VSRIv16i8_VSRIv2i64_VSRIv4i32_VSRIv8i16") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #395
  {DBGFIELD("VQSHLsiv16i8_VQSHLsiv1i64_VQSHLsiv2i32_VQSHLsiv2i64_VQSHLsiv4i16_VQSHLsiv4i32_VQSHLsiv8i16_VQSHLsiv8i8_VQSHLsuv16i8_VQSHLsuv1i64_VQSHLsuv2i32_VQSHLsuv2i64_VQSHLsuv4i16_VQSHLsuv4i32_VQSHLsuv8i16_VQSHLsuv8i8_VQSHLsv1i64_VQSHLsv2i32_VQSHLsv4i16_VQSHLsv8i8_VQSHLuiv16i8_VQSHLuiv1i64_VQSHLuiv2i32_VQSHLuiv2i64_VQSHLuiv4i16_VQSHLuiv4i32_VQSHLuiv8i16_VQSHLuiv8i8_VQSHLuv1i64_VQSHLuv2i32_VQSHLuv4i16_VQSHLuv8i8") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #396
  {DBGFIELD("VQSHLsv16i8_VQSHLsv2i64_VQSHLsv4i32_VQSHLsv8i16_VQSHLuv16i8_VQSHLuv2i64_VQSHLuv4i32_VQSHLuv8i16") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #397
  {DBGFIELD("VSUBv16i8_VSUBv2i64_VSUBv4i32_VSUBv8i16") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #398
  {DBGFIELD("VEXTd16_VEXTd32_VEXTd8") 1, 0, 0, 61, 2,  2, 1,  0, 0}, // #399
  {DBGFIELD("VEXTq16_VEXTq32_VEXTq64_VEXTq8") 1, 0, 0, 61, 2,  2, 1,  0, 0}, // #400
  {DBGFIELD("VREV16d8_VREV32d16_VREV32d8_VREV64d16_VREV64d32_VREV64d8") 1, 0, 0, 61, 2,  2, 1,  0, 0}, // #401
  {DBGFIELD("VREV16q8_VREV32q16_VREV32q8_VREV64q16_VREV64q32_VREV64q8") 1, 0, 0, 61, 2,  2, 1,  0, 0}, // #402
  {DBGFIELD("VABALsv2i64_VABALsv4i32_VABALsv8i16_VABALuv2i64_VABALuv4i32_VABALuv8i16_VABAsv2i32_VABAsv4i16_VABAsv8i8_VABAuv2i32_VABAuv4i16_VABAuv8i8") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #403
  {DBGFIELD("VABAsv16i8_VABAsv4i32_VABAsv8i16_VABAuv16i8_VABAuv4i32_VABAuv8i16") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #404
  {DBGFIELD("VABSfd")             1, 0, 0, 10, 2, 18, 1,  0, 0}, // #405
  {DBGFIELD("VABSfq")             1, 0, 0, 10, 2, 18, 1,  0, 0}, // #406
  {DBGFIELD("VABSv16i8_VABSv4i32_VABSv8i16") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #407
  {DBGFIELD("VABSv2i32_VABSv4i16_VABSv8i8") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #408
  {DBGFIELD("VACGEd_VACGTd_VCEQfd_VCGEfd_VCGTfd") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #409
  {DBGFIELD("VACGEq_VACGTq_VCEQfq_VCGEfq_VCGTfq") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #410
  {DBGFIELD("VCEQv16i8_VCEQv4i32_VCEQv8i16_VCGEsv16i8_VCGEsv4i32_VCGEsv8i16_VCGEuv16i8_VCGEuv4i32_VCGEuv8i16_VCGTsv16i8_VCGTsv4i32_VCGTsv8i16_VCGTuv16i8_VCGTuv4i32_VCGTuv8i16_VQSUBsv16i8_VQSUBsv2i64_VQSUBsv4i32_VQSUBsv8i16_VQSUBuv16i8_VQSUBuv2i64_VQSUBuv4i32_VQSUBuv8i16") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #411
  {DBGFIELD("VCEQv2i32_VCEQv4i16_VCEQv8i8_VCGEsv2i32_VCGEsv4i16_VCGEsv8i8_VCGEuv2i32_VCGEuv4i16_VCGEuv8i8_VCGTsv2i32_VCGTsv4i16_VCGTsv8i8_VCGTuv2i32_VCGTuv4i16_VCGTuv8i8_VQSUBsv1i64_VQSUBsv2i32_VQSUBsv4i16_VQSUBsv8i8_VQSUBuv1i64_VQSUBuv2i32_VQSUBuv4i16_VQSUBuv8i8") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #412
  {DBGFIELD("VCEQzv16i8_VCEQzv2f32_VCEQzv2i32_VCEQzv4f32_VCEQzv4i16_VCEQzv4i32_VCEQzv8i16_VCEQzv8i8_VCGEzv16i8_VCGEzv2f32_VCGEzv2i32_VCGEzv4f32_VCGEzv4i16_VCGEzv4i32_VCGEzv8i16_VCGEzv8i8_VCGTzv16i8_VCGTzv2f32_VCGTzv2i32_VCGTzv4f32_VCGTzv4i16_VCGTzv4i32_VCGTzv8i16_VCGTzv8i8_VCLEzv16i8_VCLEzv2f32_VCLEzv2i32_VCLEzv4f32_VCLEzv4i16_VCLEzv4i32_VCLEzv8i16_VCLEzv8i8_VCLTzv16i8_VCLTzv2f32_VCLTzv2i32_VCLTzv4f32_VCLTzv4i16_VCLTzv4i32_VCLTzv8i16_VCLTzv8i8") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #413
  {DBGFIELD("VPADALsv16i8_VPADALsv4i32_VPADALsv8i16_VPADALuv16i8_VPADALuv4i32_VPADALuv8i16") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #414
  {DBGFIELD("VPADALsv2i32_VPADALsv4i16_VPADALsv8i8_VPADALuv2i32_VPADALuv4i16_VPADALuv8i8_VRSRAsv16i8_VRSRAsv1i64_VRSRAsv2i32_VRSRAsv2i64_VRSRAsv4i16_VRSRAsv4i32_VRSRAsv8i16_VRSRAsv8i8_VRSRAuv16i8_VRSRAuv1i64_VRSRAuv2i32_VRSRAuv2i64_VRSRAuv4i16_VRSRAuv4i32_VRSRAuv8i16_VRSRAuv8i8_VSRAsv16i8_VSRAsv1i64_VSRAsv2i32_VSRAsv2i64_VSRAsv4i16_VSRAsv4i32_VSRAsv8i16_VSRAsv8i8_VSRAuv16i8_VSRAuv1i64_VSRAuv2i32_VSRAuv2i64_VSRAuv4i16_VSRAuv4i32_VSRAuv8i16_VSRAuv8i8") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #415
  {DBGFIELD("VQABSv16i8_VQABSv4i32_VQABSv8i16_VQNEGv16i8_VQNEGv4i32_VQNEGv8i16") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #416
  {DBGFIELD("VQABSv2i32_VQABSv4i16_VQABSv8i8_VQNEGv2i32_VQNEGv4i16_VQNEGv8i8") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #417
  {DBGFIELD("VQADDsv16i8_VQADDsv2i64_VQADDsv4i32_VQADDsv8i16_VQADDuv16i8_VQADDuv2i64_VQADDuv4i32_VQADDuv8i16") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #418
  {DBGFIELD("VQADDsv1i64_VQADDsv2i32_VQADDsv4i16_VQADDsv8i8_VQADDuv1i64_VQADDuv2i32_VQADDuv4i16_VQADDuv8i8") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #419
  {DBGFIELD("VQRSHLsv16i8_VQRSHLsv2i64_VQRSHLsv4i32_VQRSHLsv8i16_VQRSHLuv16i8_VQRSHLuv2i64_VQRSHLuv4i32_VQRSHLuv8i16_VRSHLsv16i8_VRSHLsv2i64_VRSHLsv4i32_VRSHLsv8i16_VRSHLuv16i8_VRSHLuv2i64_VRSHLuv4i32_VRSHLuv8i16") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #420
  {DBGFIELD("VQRSHLsv1i64_VQRSHLsv2i32_VQRSHLsv4i16_VQRSHLsv8i8_VQRSHLuv1i64_VQRSHLuv2i32_VQRSHLuv4i16_VQRSHLuv8i8_VRSHLsv1i64_VRSHLsv2i32_VRSHLsv4i16_VRSHLsv8i8_VRSHLuv1i64_VRSHLuv2i32_VRSHLuv4i16_VRSHLuv8i8_VRSHRsv16i8_VRSHRsv1i64_VRSHRsv2i32_VRSHRsv2i64_VRSHRsv4i16_VRSHRsv4i32_VRSHRsv8i16_VRSHRsv8i8_VRSHRuv16i8_VRSHRuv1i64_VRSHRuv2i32_VRSHRuv2i64_VRSHRuv4i16_VRSHRuv4i32_VRSHRuv8i16_VRSHRuv8i8") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #421
  {DBGFIELD("VRECPEd_VRECPEfd_VRSQRTEd_VRSQRTEfd") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #422
  {DBGFIELD("VRECPEfq_VRECPEq_VRSQRTEfq_VRSQRTEq") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #423
  {DBGFIELD("VADDHNv2i32_VADDHNv4i16_VADDHNv8i8_VSUBHNv2i32_VSUBHNv4i16_VSUBHNv8i8") 1, 0, 0, 110, 3, 18, 1,  0, 0}, // #424
  {DBGFIELD("VSHRNv2i32_VSHRNv4i16_VSHRNv8i8") 1, 0, 0, 110, 3, 18, 1,  0, 0}, // #425
  {DBGFIELD("VQRSHRNsv2i32_VQRSHRNsv4i16_VQRSHRNsv8i8_VQRSHRNuv2i32_VQRSHRNuv4i16_VQRSHRNuv8i8_VQRSHRUNv2i32_VQRSHRUNv4i16_VQRSHRUNv8i8_VQSHRNsv2i32_VQSHRNsv4i16_VQSHRNsv8i8_VQSHRNuv2i32_VQSHRNuv4i16_VQSHRNuv8i8_VQSHRUNv2i32_VQSHRUNv4i16_VQSHRUNv8i8_VRSHRNv2i32_VRSHRNv4i16_VRSHRNv8i8") 1, 0, 0, 110, 3, 27, 1,  0, 0}, // #426
  {DBGFIELD("VRADDHNv2i32_VRADDHNv4i16_VRADDHNv8i8_VRSUBHNv2i32_VRSUBHNv4i16_VRSUBHNv8i8") 1, 0, 0, 110, 3, 27, 1,  0, 0}, // #427
  {DBGFIELD("VTBL1")              1, 0, 0, 61, 2,  2, 1,  0, 0}, // #428
  {DBGFIELD("VTBX1")              1, 0, 0, 61, 2,  2, 1,  0, 0}, // #429
  {DBGFIELD("VTBL2")              2, 0, 0, 118, 2, 18, 1,  0, 0}, // #430
  {DBGFIELD("VTBX2")              2, 0, 0, 118, 2, 18, 1,  0, 0}, // #431
  {DBGFIELD("VTBL3_VTBL3Pseudo")  3, 0, 0, 120, 2, 27, 1,  0, 0}, // #432
  {DBGFIELD("VTBX3_VTBX3Pseudo")  3, 0, 0, 120, 2, 27, 1,  0, 0}, // #433
  {DBGFIELD("VTBL4_VTBL4Pseudo")  4, 0, 0, 122, 2, 42, 1,  0, 0}, // #434
  {DBGFIELD("VTBX4_VTBX4Pseudo")  4, 0, 0, 122, 2, 42, 1,  0, 0}, // #435
  {DBGFIELD("VSWPd_VSWPq")        3, 0, 0, 120, 2, 52, 3, 64, 1}, // #436
  {DBGFIELD("VTRNd16_VTRNd32_VTRNd8_VUZPd16_VUZPd8_VZIPd16_VZIPd8") 3, 0, 0, 120, 2, 52, 3, 64, 1}, // #437
  {DBGFIELD("VTRNq16_VTRNq32_VTRNq8") 3, 0, 0, 120, 2, 52, 3, 64, 1}, // #438
  {DBGFIELD("VUZPq16_VUZPq32_VUZPq8_VZIPq16_VZIPq32_VZIPq8") 3, 0, 0, 120, 2, 52, 3, 64, 1}, // #439
  {DBGFIELD("VABSD_VNEGD")        1, 0, 0, 10, 2,  2, 1,  0, 0}, // #440
  {DBGFIELD("VABSS_VNEGS")        1, 0, 0, 10, 2,  2, 1,  0, 0}, // #441
  {DBGFIELD("VCMPD_VCMPED_VCMPEZD_VCMPZD") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #442
  {DBGFIELD("VCMPES_VCMPEZS_VCMPS_VCMPZS") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #443
  {DBGFIELD("VABDLsv2i64_VABDLsv4i32_VABDLsv8i16_VABDLuv2i64_VABDLuv4i32_VABDLuv8i16_VABDsv16i8_VABDsv4i32_VABDsv8i16_VABDuv16i8_VABDuv4i32_VABDuv8i16_VMAXsv16i8_VMAXsv4i32_VMAXsv8i16_VMAXuv16i8_VMAXuv4i32_VMAXuv8i16_VMINsv16i8_VMINsv4i32_VMINsv8i16_VMINuv16i8_VMINuv4i32_VMINuv8i16") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #444
  {DBGFIELD("VABDfd_VADDfd_VMAXfd_VMINfd_VSUBfd") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #445
  {DBGFIELD("VABDfq_VADDfq_VMAXfq_VMINfq_VSUBfq") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #446
  {DBGFIELD("VABDsv2i32_VABDsv4i16_VABDsv8i8_VABDuv2i32_VABDuv4i16_VABDuv8i8_VMAXsv2i32_VMAXsv4i16_VMAXsv8i8_VMAXuv2i32_VMAXuv4i16_VMAXuv8i8_VMINsv2i32_VMINsv4i16_VMINsv8i8_VMINuv2i32_VMINuv4i16_VMINuv8i8_VPMAXs16_VPMAXs32_VPMAXs8_VPMAXu16_VPMAXu32_VPMAXu8_VPMINs16_VPMINs32_VPMINs8_VPMINu16_VPMINu32_VPMINu8") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #447
  {DBGFIELD("VADDS_VSUBS")        1, 0, 0, 10, 2, 18, 1,  0, 0}, // #448
  {DBGFIELD("VMAXNMD_VMAXNMND_VMAXNMNQ_VMAXNMS_VMINNMD_VMINNMND_VMINNMNQ_VMINNMS") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #449
  {DBGFIELD("VPADDf_VPMAXf_VPMINf") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #450
  {DBGFIELD("VADDD_VSUBD")        1, 0, 0, 10, 2, 27, 1,  0, 0}, // #451
  {DBGFIELD("VRECPSfd_VRSQRTSfd") 1, 0, 0, 61, 2, 42, 1,  0, 0}, // #452
  {DBGFIELD("VRECPSfq_VRSQRTSfq") 1, 0, 0, 61, 2, 42, 1,  0, 0}, // #453
  {DBGFIELD("VMULLp64")           1, 0, 0, 61, 2, 18, 1,  0, 0}, // #454
  {DBGFIELD("VMULLp8_VMULLslsv2i32_VMULLslsv4i16_VMULLsluv2i32_VMULLsluv4i16_VMULLsv4i32_VMULLsv8i16_VMULLuv4i32_VMULLuv8i16_VMULpd_VMULslv4i16_VMULv4i16_VMULv8i8_VQDMULHslv4i16_VQDMULHv4i16_VQDMULLslv2i32_VQDMULLslv4i16_VQDMULLv4i32_VQRDMULHslv4i16_VQRDMULHv4i16") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #455
  {DBGFIELD("VMULLsv2i64_VMULLuv2i64_VMULslv2i32_VMULv2i32_VQDMULHslv2i32_VQDMULHv2i32_VQDMULLv2i64_VQRDMULHslv2i32_VQRDMULHv2i32") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #456
  {DBGFIELD("VMULS_VNMULS")       1, 0, 0, 61, 2, 18, 1,  0, 0}, // #457
  {DBGFIELD("VMULfd")             1, 0, 0, 61, 2, 18, 1,  0, 0}, // #458
  {DBGFIELD("VMULfq")             1, 0, 0, 61, 2, 18, 1,  0, 0}, // #459
  {DBGFIELD("VMULpq_VMULslv8i16_VMULv16i8_VMULv8i16_VQDMULHslv8i16_VQDMULHv8i16_VQRDMULHslv8i16_VQRDMULHv8i16") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #460
  {DBGFIELD("VMULslfd")           1, 0, 0, 61, 2, 18, 1,  0, 0}, // #461
  {DBGFIELD("VMULslfq")           1, 0, 0, 61, 2, 18, 1,  0, 0}, // #462
  {DBGFIELD("VMULslv4i32_VMULv4i32_VQDMULHslv4i32_VQDMULHv4i32_VQRDMULHslv4i32_VQRDMULHv4i32") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #463
  {DBGFIELD("VMULD_VNMULD")       1, 0, 0, 61, 2, 27, 1,  0, 0}, // #464
  {DBGFIELD("VFMAD_VFMSD_VFNMAD_VFNMSD") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #465
  {DBGFIELD("VFMAS_VFMSS_VFNMAS_VFNMSS") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #466
  {DBGFIELD("VMLAD_VMLSD_VNMLAD_VNMLSD") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #467
  {DBGFIELD("VMLALslsv2i32_VMLALsluv2i32_VMLALsv2i64_VMLALuv2i64_VMLAslv2i32_VMLAv2i32_VMLSLslsv2i32_VMLSLsluv2i32_VMLSLsv2i64_VMLSLuv2i64_VMLSslv2i32_VMLSv2i32_VQDMLALslv2i32_VQDMLALv2i64_VQDMLSLslv2i32_VQDMLSLv2i64") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #468
  {DBGFIELD("VMLALslsv4i16_VMLALsluv4i16_VMLALsv4i32_VMLALsv8i16_VMLALuv4i32_VMLALuv8i16_VMLAslv4i16_VMLAv4i16_VMLAv8i8_VMLSLslsv4i16_VMLSLsluv4i16_VMLSLsv4i32_VMLSLsv8i16_VMLSLuv4i32_VMLSLuv8i16_VMLSslv4i16_VMLSv4i16_VMLSv8i8_VQDMLALslv4i16_VQDMLALv4i32_VQDMLSLslv4i16_VQDMLSLv4i32") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #469
  {DBGFIELD("VMLAS_VMLSS_VNMLAS_VNMLSS") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #470
  {DBGFIELD("VMLAfd_VMLAslfd_VMLSfd_VMLSslfd") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #471
  {DBGFIELD("VMLAfq_VMLAslfq_VMLSfq_VMLSslfq") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #472
  {DBGFIELD("VMLAslv4i32_VMLAv4i32_VMLSslv4i32_VMLSv4i32") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #473
  {DBGFIELD("VMLAslv8i16_VMLAv16i8_VMLAv8i16_VMLSslv8i16_VMLSv16i8_VMLSv8i16") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #474
  {DBGFIELD("VFMAfd_VFMSfd")      1, 0, 0, 61, 2, 42, 1,  0, 0}, // #475
  {DBGFIELD("VFMAfq_VFMSfq")      1, 0, 0, 61, 2, 564, 1,  0, 0}, // #476
  {DBGFIELD("VCVTANSD_VCVTANSQ_VCVTANUD_VCVTANUQ_VCVTASD_VCVTASS_VCVTAUD_VCVTAUS_VCVTBDH_VCVTBHD_VCVTMNSD_VCVTMNSQ_VCVTMNUD_VCVTMNUQ_VCVTMSD_VCVTMSS_VCVTMUD_VCVTMUS_VCVTNNSD_VCVTNNSQ_VCVTNNUD_VCVTNNUQ_VCVTNSD_VCVTNSS_VCVTNUD_VCVTNUS_VCVTPNSD_VCVTPNSQ_VCVTPNUD_VCVTPNUQ_VCVTPSD_VCVTPSS_VCVTPUD_VCVTPUS_VCVTTDH_VCVTTHD") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #477
  {DBGFIELD("VCVTBHS_VCVTTHS")    1, 0, 0, 61, 2, 18, 1,  0, 0}, // #478
  {DBGFIELD("VCVTBSH_VCVTTSH")    1, 0, 0, 61, 2, 18, 1,  0, 0}, // #479
  {DBGFIELD("VCVTDS")             1, 0, 0, 61, 2, 18, 1,  0, 0}, // #480
  {DBGFIELD("VCVTSD")             1, 0, 0, 61, 2, 18, 1,  0, 0}, // #481
  {DBGFIELD("VCVTf2h_VCVTf2sq_VCVTf2uq_VCVTf2xsq_VCVTf2xuq_VCVTh2f_VCVTs2fq_VCVTu2fq_VCVTxs2fq_VCVTxu2fq") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #482
  {DBGFIELD("VCVTf2sd_VCVTf2ud_VCVTf2xsd_VCVTf2xud_VCVTs2fd_VCVTu2fd_VCVTxs2fd_VCVTxu2fd") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #483
  {DBGFIELD("VSITOD_VUITOD")      1, 0, 0, 61, 2, 18, 1,  0, 0}, // #484
  {DBGFIELD("VSITOS_VUITOS")      1, 0, 0, 61, 2, 18, 1,  0, 0}, // #485
  {DBGFIELD("VTOSHD_VTOSLD_VTOUHD_VTOULD") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #486
  {DBGFIELD("VTOSHS_VTOSLS_VTOUHS_VTOULS") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #487
  {DBGFIELD("VTOSIRD_VTOSIZD_VTOUIRD_VTOUIZD") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #488
  {DBGFIELD("VTOSIRS_VTOSIZS_VTOUIRS_VTOUIZS") 1, 0, 0, 61, 2, 18, 1,  0, 0}, // #489
  {DBGFIELD("FCONSTD_VMOVD_VMOVDcc") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #490
  {DBGFIELD("FCONSTS_VMOVS_VMOVScc") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #491
  {DBGFIELD("VMOVv16i8_VMOVv1i64_VMOVv2f32_VMOVv2i32_VMOVv2i64_VMOVv4f32_VMOVv4i16_VMOVv4i32_VMOVv8i16_VMOVv8i8_VMVNv2i32_VMVNv4i16_VMVNv4i32_VMVNv8i16") 1, 0, 0, 10, 2,  2, 1,  0, 0}, // #492
  {DBGFIELD("VMVNd_VMVNq")        1, 0, 0, 10, 2,  2, 1,  0, 0}, // #493
  {DBGFIELD("VMOVLsv2i64_VMOVLsv4i32_VMOVLsv8i16_VMOVLuv2i64_VMOVLuv4i32_VMOVLuv8i16") 1, 0, 0, 61, 2,  2, 1,  0, 0}, // #494
  {DBGFIELD("VMOVNv2i32_VMOVNv4i16_VMOVNv8i8") 1, 0, 0, 61, 2,  2, 1,  0, 0}, // #495
  {DBGFIELD("VQMOVNsuv2i32_VQMOVNsuv4i16_VQMOVNsuv8i8_VQMOVNsv2i32_VQMOVNsv4i16_VQMOVNsv8i8_VQMOVNuv2i32_VQMOVNuv4i16_VQMOVNuv8i8") 2, 0, 0, 110, 3, 27, 1,  0, 0}, // #496
  {DBGFIELD("VDUPLN16d_VDUPLN32d_VDUPLN8d") 1, 0, 0, 61, 2,  2, 1,  0, 0}, // #497
  {DBGFIELD("VDUPLN16q_VDUPLN32q_VDUPLN8q") 1, 0, 0, 61, 2,  2, 1,  0, 0}, // #498
  {DBGFIELD("VDUP16d_VDUP16q_VDUP32d_VDUP32q_VDUP8d_VDUP8q") 2, 0, 0, 102, 3, 27, 1,  0, 0}, // #499
  {DBGFIELD("VMOVRS")             1, 0, 0,  4, 1,  3, 1,  0, 0}, // #500
  {DBGFIELD("VMOVSR")             2, 0, 0, 124, 3, 27, 1,  0, 0}, // #501
  {DBGFIELD("VSETLNi16_VSETLNi32_VSETLNi8") 2, 0, 0, 124, 3, 27, 1,  0, 0}, // #502
  {DBGFIELD("VMOVRRD_VMOVRRS")    2, 0, 0, 22, 1, 23, 2,  0, 0}, // #503
  {DBGFIELD("VMOVDRR")            1, 0, 0,  4, 1, 18, 1,  0, 0}, // #504
  {DBGFIELD("VMOVSRR")            4, 0, 0, 127, 3, 81, 2,  0, 0}, // #505
  {DBGFIELD("VGETLNi32_VGETLNu16_VGETLNu8") 2, 0, 0, 102, 3, 19, 1,  0, 0}, // #506
  {DBGFIELD("VGETLNs16_VGETLNs8") 3, 0, 0, 130, 3, 27, 1,  0, 0}, // #507
  {DBGFIELD("VMRS_VMRS_FPEXC_VMRS_FPINST_VMRS_FPINST2_VMRS_FPSID_VMRS_MVFR0_VMRS_MVFR1_VMRS_MVFR2") 3, 0, 0, 133, 4, 565, 3,  0, 0}, // #508
  {DBGFIELD("VMSR_VMSR_FPEXC_VMSR_FPINST_VMSR_FPINST2_VMSR_FPSID") 3, 0, 0, 133, 4, 565, 3,  0, 0}, // #509
  {DBGFIELD("FMSTAT")             1, 0, 0, 10, 2,  2, 1,  0, 0}, // #510
  {DBGFIELD("VLDRD")              1, 0, 0,  4, 1, 18, 1,  0, 0}, // #511
  {DBGFIELD("VLDRS")              1, 0, 0,  4, 1, 18, 1,  0, 0}, // #512
  {DBGFIELD("VSTRD")              1, 0, 0,  4, 1, 18, 1,  0, 0}, // #513
  {DBGFIELD("VSTRS")              1, 0, 0,  4, 1, 18, 1,  0, 0}, // #514
  {DBGFIELD("VLDMQIA")            1, 0, 0,  4, 1, 18, 1,  0, 0}, // #515
  {DBGFIELD("VSTMQIA")            1, 0, 0,  4, 1, 18, 1,  0, 0}, // #516
  {DBGFIELD("VLDMDIA_VLDMSIA")    65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #517
  {DBGFIELD("VLDMDDB_UPD_VLDMDIA_UPD_VLDMSDB_UPD_VLDMSIA_UPD") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #518
  {DBGFIELD("VSTMDIA_VSTMSIA")    65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #519
  {DBGFIELD("VSTMDDB_UPD_VSTMDIA_UPD_VSTMSDB_UPD_VSTMSIA_UPD") 65534, 0, 0,  0, 0,  0, 0,  0, 0}, // #520
  {DBGFIELD("VLD1d16_VLD1d32_VLD1d64_VLD1d8") 1, 0, 0,  4, 1, 18, 1,  0, 0}, // #521
  {DBGFIELD("VLD1q16_VLD1q32_VLD1q64_VLD1q8") 1, 0, 0,  4, 1, 18, 1,  0, 0}, // #522
  {DBGFIELD("VLD1d16wb_fixed_VLD1d16wb_register_VLD1d32wb_fixed_VLD1d32wb_register_VLD1d64wb_fixed_VLD1d64wb_register_VLD1d8wb_fixed_VLD1d8wb_register") 2, 0, 0, 32, 2, 284, 2,  0, 0}, // #523
  {DBGFIELD("VLD1q16wb_fixed_VLD1q16wb_register_VLD1q32wb_fixed_VLD1q32wb_register_VLD1q64wb_fixed_VLD1q64wb_register_VLD1q8wb_fixed_VLD1q8wb_register") 2, 0, 0, 32, 2, 284, 2,  0, 0}, // #524
  {DBGFIELD("VLD1d16T_VLD1d32T_VLD1d64T_VLD1d64TPseudo_VLD1d64TPseudoWB_fixed_VLD1d64TPseudoWB_register_VLD1d8T") 1, 0, 0, 29, 1, 18, 1,  0, 0}, // #525
  {DBGFIELD("VLD1d16Twb_fixed_VLD1d16Twb_register_VLD1d32Twb_fixed_VLD1d32Twb_register_VLD1d64Twb_fixed_VLD1d64Twb_register_VLD1d8Twb_fixed_VLD1d8Twb_register") 2, 0, 0, 137, 2, 284, 2,  0, 0}, // #526
  {DBGFIELD("VLD1d16Q_VLD1d32Q_VLD1d64Q_VLD1d64QPseudo_VLD1d64QPseudoWB_fixed_VLD1d64QPseudoWB_register_VLD1d8Q") 1, 0, 0, 22, 1, 18, 1,  0, 0}, // #527
  {DBGFIELD("VLD1d16Qwb_fixed_VLD1d16Qwb_register_VLD1d32Qwb_fixed_VLD1d32Qwb_register_VLD1d64Qwb_fixed_VLD1d64Qwb_register_VLD1d8Qwb_fixed_VLD1d8Qwb_register") 2, 0, 0, 26, 2, 284, 2,  0, 0}, // #528
  {DBGFIELD("VLD2b16_VLD2b32_VLD2b8_VLD2d16_VLD2d32_VLD2d8") 5, 0, 0, 139, 4, 568, 3,  0, 0}, // #529
  {DBGFIELD("VLD2q16_VLD2q16Pseudo_VLD2q32_VLD2q32Pseudo_VLD2q8_VLD2q8Pseudo") 5, 0, 0, 139, 4, 568, 3,  0, 0}, // #530
  {DBGFIELD("VLD2b16wb_fixed_VLD2b16wb_register_VLD2b32wb_fixed_VLD2b32wb_register_VLD2b8wb_fixed_VLD2b8wb_register_VLD2d16wb_fixed_VLD2d16wb_register_VLD2d32wb_fixed_VLD2d32wb_register_VLD2d8wb_fixed_VLD2d8wb_register") 6, 0, 0, 143, 4, 571, 4,  0, 0}, // #531
  {DBGFIELD("VLD2q16PseudoWB_fixed_VLD2q16PseudoWB_register_VLD2q16wb_fixed_VLD2q16wb_register_VLD2q32PseudoWB_fixed_VLD2q32PseudoWB_register_VLD2q32wb_fixed_VLD2q32wb_register_VLD2q8PseudoWB_fixed_VLD2q8PseudoWB_register_VLD2q8wb_fixed_VLD2q8wb_register") 6, 0, 0, 143, 4, 571, 4,  0, 0}, // #532
  {DBGFIELD("VLD3d16_VLD3d32_VLD3d8_VLD3q16_VLD3q32_VLD3q8") 5, 0, 0, 147, 3, 575, 5,  0, 0}, // #533
  {DBGFIELD("VLD3d16Pseudo_VLD3d32Pseudo_VLD3d8Pseudo_VLD3q16oddPseudo_VLD3q32oddPseudo_VLD3q8oddPseudo") 5, 0, 0, 147, 3, 577, 3,  0, 0}, // #534
  {DBGFIELD("VLD3d16_UPD_VLD3d32_UPD_VLD3d8_UPD_VLD3q16_UPD_VLD3q32_UPD_VLD3q8_UPD") 6, 0, 0, 150, 3, 580, 6,  0, 0}, // #535
  {DBGFIELD("VLD3d16Pseudo_UPD_VLD3d32Pseudo_UPD_VLD3d8Pseudo_UPD_VLD3q16Pseudo_UPD_VLD3q16oddPseudo_UPD_VLD3q32Pseudo_UPD_VLD3q32oddPseudo_UPD_VLD3q8Pseudo_UPD_VLD3q8oddPseudo_UPD") 6, 0, 0, 150, 3, 582, 4,  0, 0}, // #536
  {DBGFIELD("VLD4d16_VLD4d32_VLD4d8_VLD4q16_VLD4q32_VLD4q8") 11, 0, 0, 153, 4, 586, 7,  0, 0}, // #537
  {DBGFIELD("VLD4d16Pseudo_VLD4d32Pseudo_VLD4d8Pseudo_VLD4q16oddPseudo_VLD4q32oddPseudo_VLD4q8oddPseudo") 8, 0, 0, 157, 4, 589, 4,  0, 0}, // #538
  {DBGFIELD("VLD4d16_UPD_VLD4d32_UPD_VLD4d8_UPD_VLD4q16_UPD_VLD4q32_UPD_VLD4q8_UPD") 12, 0, 0, 161, 4, 593, 8,  0, 0}, // #539
  {DBGFIELD("VLD4d16Pseudo_UPD_VLD4d32Pseudo_UPD_VLD4d8Pseudo_UPD_VLD4q16Pseudo_UPD_VLD4q16oddPseudo_UPD_VLD4q32Pseudo_UPD_VLD4q32oddPseudo_UPD_VLD4q8Pseudo_UPD_VLD4q8oddPseudo_UPD") 9, 0, 0, 165, 4, 596, 5,  0, 0}, // #540
  {DBGFIELD("VLD1DUPd16_VLD1DUPd32_VLD1DUPd8_VLD1DUPq16_VLD1DUPq32_VLD1DUPq8") 3, 0, 0, 169, 3, 98, 2,  0, 0}, // #541
  {DBGFIELD("VLD1LNd16_VLD1LNd32_VLD1LNd8_VLD1LNq16Pseudo_VLD1LNq32Pseudo_VLD1LNq8Pseudo") 3, 0, 0, 169, 3, 98, 2,  0, 0}, // #542
  {DBGFIELD("VLD1DUPd16wb_fixed_VLD1DUPd16wb_register_VLD1DUPd32wb_fixed_VLD1DUPd32wb_register_VLD1DUPd8wb_fixed_VLD1DUPd8wb_register_VLD1DUPq16wb_fixed_VLD1DUPq16wb_register_VLD1DUPq32wb_fixed_VLD1DUPq32wb_register_VLD1DUPq8wb_fixed_VLD1DUPq8wb_register") 4, 0, 0, 172, 3, 601, 3,  0, 0}, // #543
  {DBGFIELD("VLD1LNd16_UPD_VLD1LNd32_UPD_VLD1LNd8_UPD_VLD1LNq16Pseudo_UPD_VLD1LNq32Pseudo_UPD_VLD1LNq8Pseudo_UPD") 4, 0, 0, 172, 3, 601, 3,  0, 0}, // #544
  {DBGFIELD("VLD2DUPd16_VLD2DUPd16x2_VLD2DUPd32_VLD2DUPd32x2_VLD2DUPd8_VLD2DUPd8x2") 5, 0, 0, 175, 4, 604, 4,  0, 0}, // #545
  {DBGFIELD("VLD2LNd16_VLD2LNd16Pseudo_VLD2LNd32_VLD2LNd32Pseudo_VLD2LNd8_VLD2LNd8Pseudo_VLD2LNq16_VLD2LNq16Pseudo_VLD2LNq32_VLD2LNq32Pseudo") 5, 0, 0, 175, 4, 604, 4,  0, 0}, // #546
  {DBGFIELD("VLD2LNd16_UPD_VLD2LNd32_UPD_VLD2LNd8_UPD_VLD2LNq16_UPD_VLD2LNq32_UPD") 6, 0, 0, 179, 4, 608, 5,  0, 0}, // #547
  {DBGFIELD("VLD2DUPd16wb_fixed_VLD2DUPd16wb_register_VLD2DUPd16x2wb_fixed_VLD2DUPd16x2wb_register_VLD2DUPd32wb_fixed_VLD2DUPd32wb_register_VLD2DUPd32x2wb_fixed_VLD2DUPd32x2wb_register_VLD2DUPd8wb_fixed_VLD2DUPd8wb_register_VLD2DUPd8x2wb_fixed_VLD2DUPd8x2wb_register") 6, 0, 0, 179, 4, 613, 5,  0, 0}, // #548
  {DBGFIELD("VLD2LNd16Pseudo_UPD_VLD2LNd32Pseudo_UPD_VLD2LNd8Pseudo_UPD_VLD2LNq16Pseudo_UPD_VLD2LNq32Pseudo_UPD") 6, 0, 0, 179, 4, 613, 5,  0, 0}, // #549
  {DBGFIELD("VLD3DUPd16_VLD3DUPd16Pseudo_VLD3DUPd32_VLD3DUPd32Pseudo_VLD3DUPd8_VLD3DUPd8Pseudo_VLD3DUPq16_VLD3DUPq32_VLD3DUPq8") 7, 0, 0, 183, 4, 618, 5,  0, 0}, // #550
  {DBGFIELD("VLD3LNd16_VLD3LNd16Pseudo_VLD3LNd32_VLD3LNd32Pseudo_VLD3LNd8_VLD3LNd8Pseudo_VLD3LNq16_VLD3LNq16Pseudo_VLD3LNq32_VLD3LNq32Pseudo") 7, 0, 0, 183, 4, 618, 5,  0, 0}, // #551
  {DBGFIELD("VLD3DUPd16_UPD_VLD3DUPd32_UPD_VLD3DUPd8_UPD_VLD3DUPq16_UPD_VLD3DUPq32_UPD_VLD3DUPq8_UPD") 8, 0, 0, 187, 4, 623, 6,  0, 0}, // #552
  {DBGFIELD("VLD3LNd16_UPD_VLD3LNd32_UPD_VLD3LNd8_UPD_VLD3LNq16_UPD_VLD3LNq32_UPD") 8, 0, 0, 187, 4, 623, 6,  0, 0}, // #553
  {DBGFIELD("VLD3DUPd16Pseudo_UPD_VLD3DUPd32Pseudo_UPD_VLD3DUPd8Pseudo_UPD") 8, 0, 0, 187, 4, 629, 6,  0, 0}, // #554
  {DBGFIELD("VLD3LNd16Pseudo_UPD_VLD3LNd32Pseudo_UPD_VLD3LNd8Pseudo_UPD_VLD3LNq16Pseudo_UPD_VLD3LNq32Pseudo_UPD") 8, 0, 0, 187, 4, 629, 6,  0, 0}, // #555
  {DBGFIELD("VLD4DUPd16_VLD4DUPd16Pseudo_VLD4DUPd32_VLD4DUPd32Pseudo_VLD4DUPd8_VLD4DUPd8Pseudo_VLD4DUPq16_VLD4DUPq32_VLD4DUPq8") 8, 0, 0, 191, 4, 635, 6,  0, 0}, // #556
  {DBGFIELD("VLD4LNd16_VLD4LNd16Pseudo_VLD4LNd32_VLD4LNd32Pseudo_VLD4LNd8_VLD4LNd8Pseudo_VLD4LNq16_VLD4LNq16Pseudo_VLD4LNq32_VLD4LNq32Pseudo") 8, 0, 0, 191, 4, 635, 6,  0, 0}, // #557
  {DBGFIELD("VLD4DUPd16_UPD_VLD4DUPd32_UPD_VLD4DUPd8_UPD_VLD4DUPq16_UPD_VLD4DUPq32_UPD_VLD4DUPq8_UPD") 9, 0, 0, 195, 4, 641, 7,  0, 0}, // #558
  {DBGFIELD("VLD4LNd16_UPD_VLD4LNd32_UPD_VLD4LNd8_UPD_VLD4LNq16_UPD_VLD4LNq32_UPD") 9, 0, 0, 195, 4, 641, 7,  0, 0}, // #559
  {DBGFIELD("VLD4DUPd16Pseudo_UPD_VLD4DUPd32Pseudo_UPD_VLD4DUPd8Pseudo_UPD") 9, 0, 0, 195, 4, 648, 7,  0, 0}, // #560
  {DBGFIELD("VLD4LNd16Pseudo_UPD_VLD4LNd32Pseudo_UPD_VLD4LNd8Pseudo_UPD_VLD4LNq16Pseudo_UPD_VLD4LNq32Pseudo_UPD") 9, 0, 0, 195, 4, 648, 7,  0, 0}, // #561
  {DBGFIELD("VST1d16_VST1d32_VST1d64_VST1d8") 1, 0, 0,  4, 1,  0, 1,  0, 0}, // #562
  {DBGFIELD("VST1q16_VST1q32_VST1q64_VST1q8") 2, 0, 0, 22, 1,  0, 1,  0, 0}, // #563
  {DBGFIELD("VST1d16wb_fixed_VST1d16wb_register_VST1d32wb_fixed_VST1d32wb_register_VST1d64wb_fixed_VST1d64wb_register_VST1d8wb_fixed_VST1d8wb_register") 2, 0, 0, 32, 2, 48, 2,  0, 0}, // #564
  {DBGFIELD("VST1q16wb_fixed_VST1q16wb_register_VST1q32wb_fixed_VST1q32wb_register_VST1q64wb_fixed_VST1q64wb_register_VST1q8wb_fixed_VST1q8wb_register") 3, 0, 0, 26, 2, 48, 2,  0, 0}, // #565
  {DBGFIELD("VST1d16T_VST1d32T_VST1d64T_VST1d64TPseudo_VST1d8T") 3, 0, 0, 29, 1,  0, 1,  0, 0}, // #566
  {DBGFIELD("VST1d16Twb_fixed_VST1d16Twb_register_VST1d32Twb_fixed_VST1d32Twb_register_VST1d64Twb_fixed_VST1d64Twb_register_VST1d8Twb_fixed_VST1d8Twb_register") 4, 0, 0, 137, 2, 48, 2,  0, 0}, // #567
  {DBGFIELD("VST1d64TPseudoWB_fixed_VST1d64TPseudoWB_register") 4, 0, 0, 137, 2, 48, 2,  0, 0}, // #568
  {DBGFIELD("VST1d16Q_VST1d32Q_VST1d64Q_VST1d64QPseudo_VST1d8Q") 4, 0, 0, 38, 1,  0, 1,  0, 0}, // #569
  {DBGFIELD("VST1d16Qwb_fixed_VST1d16Qwb_register_VST1d32Qwb_fixed_VST1d32Qwb_register_VST1d64Qwb_fixed_VST1d64Qwb_register_VST1d8Qwb_fixed_VST1d8Qwb_register") 5, 0, 0, 199, 2, 48, 2,  0, 0}, // #570
  {DBGFIELD("VST1d64QPseudoWB_fixed_VST1d64QPseudoWB_register") 5, 0, 0, 199, 2, 48, 2,  0, 0}, // #571
  {DBGFIELD("VST2b16_VST2b32_VST2b8_VST2d16_VST2d32_VST2d8") 2, 0, 0, 102, 3, 561, 2,  0, 0}, // #572
  {DBGFIELD("VST2b16wb_fixed_VST2b16wb_register_VST2b32wb_fixed_VST2b32wb_register_VST2b8wb_fixed_VST2b8wb_register_VST2d16wb_fixed_VST2d16wb_register_VST2d32wb_fixed_VST2d32wb_register_VST2d8wb_fixed_VST2d8wb_register") 3, 0, 0, 130, 3, 560, 3,  0, 0}, // #573
  {DBGFIELD("VST2q16_VST2q16Pseudo_VST2q32_VST2q32Pseudo_VST2q8_VST2q8Pseudo") 4, 0, 0, 127, 3, 561, 2,  0, 0}, // #574
  {DBGFIELD("VST2q16PseudoWB_fixed_VST2q16PseudoWB_register_VST2q32PseudoWB_fixed_VST2q32PseudoWB_register_VST2q8PseudoWB_fixed_VST2q8PseudoWB_register") 4, 0, 0, 127, 3, 561, 2,  0, 0}, // #575
  {DBGFIELD("VST2q16wb_fixed_VST2q16wb_register_VST2q32wb_fixed_VST2q32wb_register_VST2q8wb_fixed_VST2q8wb_register") 4, 0, 0, 127, 3, 561, 2,  0, 0}, // #576
  {DBGFIELD("VST3d16_VST3d16Pseudo_VST3d32_VST3d32Pseudo_VST3d8_VST3d8Pseudo_VST3q16_VST3q16oddPseudo_VST3q32_VST3q32oddPseudo_VST3q8_VST3q8oddPseudo") 6, 0, 0, 201, 3, 561, 2,  0, 0}, // #577
  {DBGFIELD("VST3d16Pseudo_UPD_VST3d16_UPD_VST3d32Pseudo_UPD_VST3d32_UPD_VST3d8Pseudo_UPD_VST3d8_UPD_VST3q16Pseudo_UPD_VST3q16_UPD_VST3q16oddPseudo_UPD_VST3q32Pseudo_UPD_VST3q32_UPD_VST3q32oddPseudo_UPD_VST3q8Pseudo_UPD_VST3q8_UPD_VST3q8oddPseudo_UPD") 7, 0, 0, 204, 3, 560, 3,  0, 0}, // #578
  {DBGFIELD("VST4d16_VST4d16Pseudo_VST4d32_VST4d32Pseudo_VST4d8_VST4d8Pseudo_VST4q16_VST4q16oddPseudo_VST4q32_VST4q32oddPseudo_VST4q8_VST4q8oddPseudo") 6, 0, 0, 201, 3, 561, 2,  0, 0}, // #579
  {DBGFIELD("VST4d16Pseudo_UPD_VST4d16_UPD_VST4d32Pseudo_UPD_VST4d32_UPD_VST4d8Pseudo_UPD_VST4d8_UPD_VST4q16Pseudo_UPD_VST4q16_UPD_VST4q16oddPseudo_UPD_VST4q32Pseudo_UPD_VST4q32_UPD_VST4q32oddPseudo_UPD_VST4q8Pseudo_UPD_VST4q8_UPD_VST4q8oddPseudo_UPD") 9, 0, 0, 207, 3, 560, 3,  0, 0}, // #580
  {DBGFIELD("VST1LNd16_VST1LNd32_VST1LNd8_VST1LNq16Pseudo_VST1LNq32Pseudo_VST1LNq8Pseudo") 2, 0, 0, 102, 3, 561, 2,  0, 0}, // #581
  {DBGFIELD("VST1LNd16_UPD_VST1LNd32_UPD_VST1LNd8_UPD_VST1LNq16Pseudo_UPD_VST1LNq32Pseudo_UPD_VST1LNq8Pseudo_UPD") 3, 0, 0, 130, 3, 560, 3,  0, 0}, // #582
  {DBGFIELD("VST2LNd16_VST2LNd16Pseudo_VST2LNd32_VST2LNd32Pseudo_VST2LNd8_VST2LNd8Pseudo_VST2LNq16_VST2LNq16Pseudo_VST2LNq32_VST2LNq32Pseudo") 3, 0, 0, 169, 3, 561, 2,  0, 0}, // #583
  {DBGFIELD("VST2LNd16Pseudo_UPD_VST2LNd16_UPD_VST2LNd32Pseudo_UPD_VST2LNd32_UPD_VST2LNd8Pseudo_UPD_VST2LNd8_UPD_VST2LNq16Pseudo_UPD_VST2LNq16_UPD_VST2LNq32Pseudo_UPD_VST2LNq32_UPD") 4, 0, 0, 172, 3, 560, 3,  0, 0}, // #584
  {DBGFIELD("VST3LNd16_VST3LNd16Pseudo_VST3LNd32_VST3LNd32Pseudo_VST3LNd8_VST3LNd8Pseudo_VST3LNq16_VST3LNq16Pseudo_VST3LNq32_VST3LNq32Pseudo") 6, 0, 0, 201, 3, 561, 2,  0, 0}, // #585
  {DBGFIELD("VST3LNd16Pseudo_UPD_VST3LNd16_UPD_VST3LNd32Pseudo_UPD_VST3LNd32_UPD_VST3LNd8Pseudo_UPD_VST3LNd8_UPD_VST3LNq16Pseudo_UPD_VST3LNq16_UPD_VST3LNq32Pseudo_UPD_VST3LNq32_UPD") 7, 0, 0, 204, 3, 560, 3,  0, 0}, // #586
  {DBGFIELD("VST4LNd16_VST4LNd16Pseudo_VST4LNd32_VST4LNd32Pseudo_VST4LNd8_VST4LNd8Pseudo_VST4LNq16_VST4LNq16Pseudo_VST4LNq32_VST4LNq32Pseudo") 4, 0, 0, 127, 3, 561, 2,  0, 0}, // #587
  {DBGFIELD("VST4LNd16Pseudo_UPD_VST4LNd16_UPD_VST4LNd32Pseudo_UPD_VST4LNd32_UPD_VST4LNd8Pseudo_UPD_VST4LNd8_UPD_VST4LNq16Pseudo_UPD_VST4LNq16_UPD_VST4LNq32Pseudo_UPD_VST4LNq32_UPD") 5, 0, 0, 176, 3, 560, 3,  0, 0}, // #588
  {DBGFIELD("VDIVS")              1, 0, 0, 210, 3, 45, 1,  0, 0}, // #589
  {DBGFIELD("VSQRTS")             1, 0, 0, 210, 3, 45, 1,  0, 0}, // #590
  {DBGFIELD("VDIVD")              1, 0, 0, 213, 3, 44, 1,  0, 0}, // #591
  {DBGFIELD("VSQRTD")             1, 0, 0, 213, 3, 44, 1,  0, 0}, // #592
  {DBGFIELD("ABS")                2, 0, 0, 30, 1,  2, 1,  0, 0}, // #593
  {DBGFIELD("SwiftWriteP01TwoCycle_ReadALU") 1, 0, 0,  6, 1,  2, 1,  0, 1}, // #594
  {DBGFIELD("WriteALU_ReadALU")   1, 0, 0,  6, 1,  1, 1,  0, 1}, // #595
  {DBGFIELD("SwiftWriteP01ThreeCycleTwoUops_anonymous_3044") 2, 0, 0, 30, 1,  3, 1, 64, 1}, // #596
  {DBGFIELD("SwiftWriteP01TwoCycle_NoReadAdvance") 1, 0, 0,  6, 1,  2, 1,  0, 1}, // #597
  {DBGFIELD("SwiftWriteP0ThreeCycleThreeUops_anonymous_3044") 3, 0, 0, 216, 2,  3, 1, 64, 1}, // #598
  {DBGFIELD("SwiftWriteP01OneCycle_ReadALU") 1, 0, 0,  6, 1,  1, 1,  0, 1}, // #599
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #600
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #601
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #602
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #603
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #604
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #605
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #606
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #607
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #608
  {DBGFIELD("A9WriteAdr_A9WriteL1_A9WriteL1Hi_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #609
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #610
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #611
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #612
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #613
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #614
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #615
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #616
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #617
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #618
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #619
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #620
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #621
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #622
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #623
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #624
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #625
  {DBGFIELD("A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #626
  {DBGFIELD("SwiftWriteP01ThreeCycleTwoUops") 2, 0, 0, 30, 1,  3, 1,  0, 0}, // #627
  {DBGFIELD("SwiftWriteP01TwoCycle") 1, 0, 0,  6, 1,  2, 1,  0, 0}, // #628
  {DBGFIELD("WriteALU")           1, 0, 0,  6, 1,  1, 1,  0, 0}, // #629
  {DBGFIELD("A9WriteAdr_(A9WriteIssue_A9WriteLfpOp)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #630
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #631
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #632
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #633
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #634
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #635
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #636
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #637
  {DBGFIELD("A9WriteAdr_A9WriteLMfp1_A9WriteL1Hi") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #638
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #639
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #640
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #641
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #642
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #643
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #644
  {DBGFIELD("(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #645
  {DBGFIELD("(A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #646
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp)_A9WriteAdr") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #647
  {DBGFIELD("A9WriteLMfp1_A9WriteL1Hi_A9WriteAdr") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #648
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #649
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #650
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #651
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #652
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #653
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #654
  {DBGFIELD("(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #655
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #656
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #657
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #658
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #659
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #660
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #661
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #662
  {DBGFIELD("A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)") 0, 0, 0,  0, 0,  0, 0,  0, 0}, // #663
  {DBGFIELD("SwiftWriteP01TwoCycle_anonymous_3044") 1, 0, 0,  6, 1,  2, 1, 64, 1}, // #664
  {DBGFIELD("WriteALU_anonymous_3044") 1, 0, 0,  6, 1,  1, 1, 64, 1}, // #665
  {DBGFIELD("WriteALU_NoReadAdvance") 1, 0, 0,  6, 1,  1, 1,  0, 1}, // #666
  {DBGFIELD("SwiftWriteP01OneCycle_ReadALU_ReadALU") 1, 0, 0,  6, 1,  1, 1, 86, 2}, // #667
  {DBGFIELD("SwiftWriteP01TwoCycle_ReadALU_ReadALU") 1, 0, 0,  6, 1,  2, 1, 86, 2}, // #668
  {DBGFIELD("SwiftWriteP01OneCycle") 1, 0, 0,  6, 1,  1, 1,  0, 0}, // #669
  {DBGFIELD("(SwiftWriteP0OneCycle_SwiftWriteP0OneCycle)") 2, 0, 0, 218, 2,  2, 1,  0, 0}, // #670
  {DBGFIELD("SwiftWriteP0OneCycle") 1, 0, 0, 10, 2,  1, 1,  0, 0}, // #671
  {DBGFIELD("SwiftWriteP0P01FiveCycleTwoUops_ReadALU_ReadALU_anonymous_3075") 1, 0, 0, 220, 2, 19, 1, 88, 3}, // #672
  {DBGFIELD("SwiftWriteP0FourCycle_ReadALU_ReadALU_ReadALU") 1, 0, 0, 10, 2, 18, 1, 95, 3}, // #673
  {DBGFIELD("SwiftWriteP0P01FiveCycleTwoUops") 1, 0, 0, 220, 2, 19, 1,  0, 0}, // #674
  {DBGFIELD("SwiftWriteP0FourCycle") 1, 0, 0, 10, 2, 18, 1,  0, 0}, // #675
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLDMAddrNoWB") 3, 0, 0, 26, 2, 655, 3,  0, 0}, // #676
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLDMAddrNoWB") 4, 0, 0, 137, 2, 658, 4,  0, 0}, // #677
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLDMAddrNoWB") 5, 0, 0, 199, 2, 662, 5,  0, 0}, // #678
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLDMAddrNoWB") 6, 0, 0, 222, 2, 667, 6,  0, 0}, // #679
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLDMAddrNoWB") 7, 0, 0, 224, 2, 673, 7,  0, 0}, // #680
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLDMAddrNoWB") 8, 0, 0, 226, 2, 680, 8,  0, 0}, // #681
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLDMAddrNoWB") 9, 0, 0, 228, 2, 688, 9,  0, 0}, // #682
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLDMAddrNoWB") 10, 0, 0, 230, 2, 697, 10,  0, 0}, // #683
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLDMAddrNoWB") 11, 0, 0, 232, 2, 707, 11,  0, 0}, // #684
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLDMAddrNoWB") 12, 0, 0, 234, 2, 718, 12,  0, 0}, // #685
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLDMAddrNoWB") 13, 0, 0, 236, 2, 730, 13,  0, 0}, // #686
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLDMAddrNoWB") 14, 0, 0, 238, 2, 743, 14,  0, 0}, // #687
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLDMAddrNoWB") 15, 0, 0, 240, 2, 757, 15,  0, 0}, // #688
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLDMAddrNoWB") 16, 0, 0, 242, 2, 772, 16,  0, 0}, // #689
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy_SwiftWriteLDMAddrNoWB") 17, 0, 0, 244, 2, 788, 17,  0, 0}, // #690
  {DBGFIELD("SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLDMAddrNoWB") 3, 0, 0, 26, 2, 788, 17,  0, 0}, // #691
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy") 3, 0, 0, 35, 2, 22, 3,  0, 0}, // #692
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy") 4, 0, 0, 29, 2, 805, 4,  0, 0}, // #693
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy") 5, 0, 0, 202, 2, 809, 5,  0, 0}, // #694
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy") 6, 0, 0, 246, 2, 814, 6,  0, 0}, // #695
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy") 7, 0, 0, 248, 2, 820, 7,  0, 0}, // #696
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy") 8, 0, 0, 250, 2, 827, 8,  0, 0}, // #697
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy") 9, 0, 0, 252, 2, 835, 9,  0, 0}, // #698
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy") 10, 0, 0, 254, 2, 844, 10,  0, 0}, // #699
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy") 11, 0, 0, 256, 2, 854, 11,  0, 0}, // #700
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy") 12, 0, 0, 258, 2, 865, 12,  0, 0}, // #701
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy") 13, 0, 0, 260, 2, 877, 13,  0, 0}, // #702
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy") 14, 0, 0, 262, 2, 890, 14,  0, 0}, // #703
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy") 15, 0, 0, 264, 2, 904, 15,  0, 0}, // #704
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy") 16, 0, 0, 266, 2, 919, 16,  0, 0}, // #705
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy") 17, 0, 0, 268, 2, 935, 17,  0, 0}, // #706
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo") 3, 0, 0, 35, 2, 935, 17,  0, 0}, // #707
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteP1TwoCycle") 4, 0, 0, 270, 3, 952, 4,  0, 0}, // #708
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteP1TwoCycle") 5, 0, 0, 273, 3, 956, 5,  0, 0}, // #709
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteP1TwoCycle") 6, 0, 0, 276, 3, 961, 6,  0, 0}, // #710
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteP1TwoCycle") 7, 0, 0, 279, 3, 967, 7,  0, 0}, // #711
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteP1TwoCycle") 8, 0, 0, 282, 3, 974, 8,  0, 0}, // #712
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteP1TwoCycle") 9, 0, 0, 285, 3, 982, 9,  0, 0}, // #713
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteP1TwoCycle") 10, 0, 0, 288, 3, 991, 10,  0, 0}, // #714
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteP1TwoCycle") 11, 0, 0, 291, 3, 1001, 11,  0, 0}, // #715
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteP1TwoCycle") 12, 0, 0, 294, 3, 1012, 12,  0, 0}, // #716
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteP1TwoCycle") 13, 0, 0, 297, 3, 1024, 13,  0, 0}, // #717
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteP1TwoCycle") 14, 0, 0, 300, 3, 1037, 14,  0, 0}, // #718
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteP1TwoCycle") 15, 0, 0, 303, 3, 1051, 15,  0, 0}, // #719
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteP1TwoCycle") 16, 0, 0, 306, 3, 1066, 16,  0, 0}, // #720
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteP1TwoCycle") 17, 0, 0, 309, 3, 1082, 17,  0, 0}, // #721
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy_SwiftWriteP1TwoCycle") 18, 0, 0, 312, 3, 1099, 18,  0, 0}, // #722
  {DBGFIELD("SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteP1TwoCycle") 4, 0, 0, 270, 3, 1099, 18,  0, 0}, // #723
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 4, 0, 0, 35, 2,  0, 1,  0, 0}, // #724
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 6, 0, 0, 85, 2,  0, 1,  0, 0}, // #725
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 8, 0, 0, 88, 2,  0, 1,  0, 0}, // #726
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 10, 0, 0, 91, 2,  0, 1,  0, 0}, // #727
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 12, 0, 0, 94, 2,  0, 1,  0, 0}, // #728
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 14, 0, 0, 97, 2,  0, 1,  0, 0}, // #729
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 16, 0, 0, 100, 2,  0, 1,  0, 0}, // #730
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 18, 0, 0, 315, 2,  0, 1,  0, 0}, // #731
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 20, 0, 0, 317, 2,  0, 1,  0, 0}, // #732
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 22, 0, 0, 319, 2,  0, 1,  0, 0}, // #733
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 24, 0, 0, 321, 2,  0, 1,  0, 0}, // #734
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 26, 0, 0, 323, 2,  0, 1,  0, 0}, // #735
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 28, 0, 0, 325, 2,  0, 1,  0, 0}, // #736
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 30, 0, 0, 327, 2,  0, 1,  0, 0}, // #737
  {DBGFIELD("(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 32, 0, 0, 329, 2,  0, 1,  0, 0}, // #738
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 5, 0, 0, 177, 2, 48, 2,  0, 0}, // #739
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 7, 0, 0, 185, 2, 48, 2,  0, 0}, // #740
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 9, 0, 0, 208, 2, 48, 2,  0, 0}, // #741
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 11, 0, 0, 331, 2, 48, 2,  0, 0}, // #742
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 13, 0, 0, 333, 2, 48, 2,  0, 0}, // #743
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 15, 0, 0, 335, 2, 48, 2,  0, 0}, // #744
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 17, 0, 0, 337, 2, 48, 2,  0, 0}, // #745
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 19, 0, 0, 339, 2, 48, 2,  0, 0}, // #746
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 21, 0, 0, 341, 2, 48, 2,  0, 0}, // #747
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 23, 0, 0, 343, 2, 48, 2,  0, 0}, // #748
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 25, 0, 0, 345, 2, 48, 2,  0, 0}, // #749
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 27, 0, 0, 347, 2, 48, 2,  0, 0}, // #750
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 29, 0, 0, 349, 2, 48, 2,  0, 0}, // #751
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 31, 0, 0, 351, 2, 48, 2,  0, 0}, // #752
  {DBGFIELD("SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 33, 0, 0, 353, 2, 48, 2,  0, 0}, // #753
  {DBGFIELD("SwiftWriteLM4Cy")    1, 0, 0,  4, 1, 18, 1,  0, 0}, // #754
  {DBGFIELD("SwiftWriteLM4Cy_SwiftWriteLM4CyNo") 1, 0, 0,  4, 1, 52, 2,  0, 0}, // #755
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3") 6, 0, 0, 355, 3, 1117, 5,  0, 0}, // #756
  {DBGFIELD("SwiftWriteLM4Cy_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo") 1, 0, 0,  4, 1, 1122, 4,  0, 0}, // #757
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 8, 0, 0, 192, 3, 1126, 7,  0, 0}, // #758
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 9, 0, 0, 358, 3, 1133, 8,  0, 0}, // #759
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7") 11, 0, 0, 361, 3, 1141, 9,  0, 0}, // #760
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2") 6, 0, 0, 364, 3, 1150, 10,  0, 0}, // #761
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 13, 0, 0, 367, 3, 1160, 11,  0, 0}, // #762
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 10, 0, 0, 370, 3, 1171, 12,  0, 0}, // #763
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 13, 0, 0, 367, 3, 1183, 13,  0, 0}, // #764
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM11Cy_SwiftWriteLM11Cy_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3") 8, 0, 0, 150, 3, 1196, 14,  0, 0}, // #765
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 13, 0, 0, 367, 3, 1210, 15,  0, 0}, // #766
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7") 13, 0, 0, 373, 3, 1225, 14,  0, 0}, // #767
  {DBGFIELD("SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM17Cy_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 15, 0, 0, 376, 3, 1239, 17,  0, 0}, // #768
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM18CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm4") 10, 0, 0, 379, 3, 1256, 18,  0, 0}, // #769
  {DBGFIELD("SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2") 6, 0, 0, 364, 3, 1274, 34,  0, 0}, // #770
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM4Cy") 3, 0, 0, 108, 2, 366, 2,  0, 0}, // #771
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM4Cy_SwiftWriteLM4CyNo") 3, 0, 0, 108, 2, 366, 3,  0, 0}, // #772
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3") 8, 0, 0, 382, 3, 1116, 6,  0, 0}, // #773
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM4Cy_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo") 3, 0, 0, 108, 2, 1308, 5,  0, 0}, // #774
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 10, 0, 0, 385, 3, 1313, 8,  0, 0}, // #775
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 11, 0, 0, 388, 3, 1321, 9,  0, 0}, // #776
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7") 13, 0, 0, 391, 3, 1330, 10,  0, 0}, // #777
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2") 8, 0, 0, 394, 3, 1340, 11,  0, 0}, // #778
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 15, 0, 0, 397, 3, 1351, 12,  0, 0}, // #779
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5") 12, 0, 0, 400, 3, 1363, 13,  0, 0}, // #780
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 15, 0, 0, 397, 3, 1376, 14,  0, 0}, // #781
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM11Cy_SwiftWriteLM11Cy_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3") 10, 0, 0, 403, 3, 1390, 15,  0, 0}, // #782
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 15, 0, 0, 397, 3, 1405, 16,  0, 0}, // #783
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7") 15, 0, 0, 406, 3, 1421, 15,  0, 0}, // #784
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM17Cy_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9") 17, 0, 0, 409, 3, 1436, 18,  0, 0}, // #785
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM18CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm4") 12, 0, 0, 412, 3, 1454, 19,  0, 0}, // #786
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2") 8, 0, 0, 394, 3, 1473, 35,  0, 0}, // #787
  {DBGFIELD("SwiftWriteStIncAddr") 2, 0, 0, 32, 2,  0, 1,  0, 0}, // #788
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteStIncAddr") 4, 0, 0, 173, 2, 54, 2,  0, 0}, // #789
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 10, 0, 0, 159, 2, 54, 2,  0, 0}, // #790
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 14, 0, 0, 415, 2, 54, 2,  0, 0}, // #791
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 18, 0, 0, 417, 2, 54, 2,  0, 0}, // #792
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 8, 0, 0, 189, 2, 54, 2,  0, 0}, // #793
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 22, 0, 0, 419, 2, 54, 2,  0, 0}, // #794
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 26, 0, 0, 421, 2, 54, 2,  0, 0}, // #795
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 30, 0, 0, 423, 2, 54, 2,  0, 0}, // #796
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 34, 0, 0, 425, 2, 54, 2,  0, 0}, // #797
  {DBGFIELD("(SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)") 12, 0, 0, 413, 2, 54, 2,  0, 0} // #798
}; // SwiftModelSchedClasses

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

static const llvm::MCSchedModel ARMV6ItinerariesModel = {
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
  ARMV6Itineraries};

// {Name, NumUnits, SuperIdx, IsBuffered}
static const llvm::MCProcResourceDesc CortexA9ModelProcResources[] = {
  {DBGFIELD("InvalidUnit")     0, 0, 0},
  {DBGFIELD("A9UnitAGU")       1, 0, 1}, // #1
  {DBGFIELD("A9UnitALU")       2, 0, -1}, // #2
  {DBGFIELD("A9UnitB")         1, 0, -1}, // #3
  {DBGFIELD("A9UnitFP")        1, 0, 0}, // #4
  {DBGFIELD("A9UnitLS")        1, 0, -1}, // #5
  {DBGFIELD("A9UnitMul")       1, 2, -1}  // #6, Super=A9UnitALU
};

static const llvm::MCSchedModel CortexA9Model = {
  2, // IssueWidth
  56, // MicroOpBufferSize
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  2, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  8, // MispredictPenalty
  0, // PostRAScheduler
  0, // CompleteModel
  2, // Processor ID
  CortexA9ModelProcResources,
  CortexA9ModelSchedClasses,
  7,
  799,
  CortexA9Itineraries};

static const llvm::MCSchedModel CortexA8Model = {
  2, // IssueWidth
  MCSchedModel::DefaultMicroOpBufferSize,
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  2, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  13, // MispredictPenalty
  0, // PostRAScheduler
  1, // CompleteModel
  3, // Processor ID
  nullptr, nullptr, 0, 0, // No instruction-level machine model.
  CortexA8Itineraries};

// {Name, NumUnits, SuperIdx, IsBuffered}
static const llvm::MCProcResourceDesc SwiftModelProcResources[] = {
  {DBGFIELD("InvalidUnit")     0, 0, 0},
  {DBGFIELD("SwiftUnitDiv")    1, 0, -1}, // #1
  {DBGFIELD("SwiftUnitP0")     1, 5, -1}, // #2, Super=SwiftUnitP01
  {DBGFIELD("SwiftUnitP1")     1, 5, -1}, // #3, Super=SwiftUnitP01
  {DBGFIELD("SwiftUnitP2")     1, 0, -1}, // #4
  {DBGFIELD("SwiftUnitP01")    2, 0, -1}  // #5
};

static const llvm::MCSchedModel SwiftModel = {
  3, // IssueWidth
  45, // MicroOpBufferSize
  MCSchedModel::DefaultLoopMicroOpBufferSize,
  3, // LoadLatency
  MCSchedModel::DefaultHighLatency,
  14, // MispredictPenalty
  0, // PostRAScheduler
  0, // CompleteModel
  4, // Processor ID
  SwiftModelProcResources,
  SwiftModelSchedClasses,
  6,
  799,
  nullptr}; // No Itinerary

// Sorted (by key) array of itineraries for CPU subtype.
extern const llvm::SubtargetInfoKV ARMProcSchedKV[] = {
  { "arm1020e", (const void *)&NoSchedModel },
  { "arm1020t", (const void *)&NoSchedModel },
  { "arm1022e", (const void *)&NoSchedModel },
  { "arm10e", (const void *)&NoSchedModel },
  { "arm10tdmi", (const void *)&NoSchedModel },
  { "arm1136j-s", (const void *)&ARMV6ItinerariesModel },
  { "arm1136jf-s", (const void *)&ARMV6ItinerariesModel },
  { "arm1156t2-s", (const void *)&ARMV6ItinerariesModel },
  { "arm1156t2f-s", (const void *)&ARMV6ItinerariesModel },
  { "arm1176jz-s", (const void *)&ARMV6ItinerariesModel },
  { "arm1176jzf-s", (const void *)&ARMV6ItinerariesModel },
  { "arm710t", (const void *)&NoSchedModel },
  { "arm720t", (const void *)&NoSchedModel },
  { "arm7tdmi", (const void *)&NoSchedModel },
  { "arm7tdmi-s", (const void *)&NoSchedModel },
  { "arm8", (const void *)&NoSchedModel },
  { "arm810", (const void *)&NoSchedModel },
  { "arm9", (const void *)&NoSchedModel },
  { "arm920", (const void *)&NoSchedModel },
  { "arm920t", (const void *)&NoSchedModel },
  { "arm922t", (const void *)&NoSchedModel },
  { "arm926ej-s", (const void *)&NoSchedModel },
  { "arm940t", (const void *)&NoSchedModel },
  { "arm946e-s", (const void *)&NoSchedModel },
  { "arm966e-s", (const void *)&NoSchedModel },
  { "arm968e-s", (const void *)&NoSchedModel },
  { "arm9e", (const void *)&NoSchedModel },
  { "arm9tdmi", (const void *)&NoSchedModel },
  { "cortex-a12", (const void *)&CortexA9Model },
  { "cortex-a15", (const void *)&CortexA9Model },
  { "cortex-a17", (const void *)&CortexA9Model },
  { "cortex-a35", (const void *)&NoSchedModel },
  { "cortex-a5", (const void *)&CortexA8Model },
  { "cortex-a53", (const void *)&NoSchedModel },
  { "cortex-a57", (const void *)&NoSchedModel },
  { "cortex-a7", (const void *)&CortexA8Model },
  { "cortex-a72", (const void *)&NoSchedModel },
  { "cortex-a8", (const void *)&CortexA8Model },
  { "cortex-a9", (const void *)&CortexA9Model },
  { "cortex-m0", (const void *)&ARMV6ItinerariesModel },
  { "cortex-m0plus", (const void *)&ARMV6ItinerariesModel },
  { "cortex-m1", (const void *)&ARMV6ItinerariesModel },
  { "cortex-m3", (const void *)&NoSchedModel },
  { "cortex-m4", (const void *)&NoSchedModel },
  { "cortex-m7", (const void *)&NoSchedModel },
  { "cortex-r4", (const void *)&CortexA8Model },
  { "cortex-r4f", (const void *)&CortexA8Model },
  { "cortex-r5", (const void *)&CortexA8Model },
  { "cortex-r7", (const void *)&CortexA8Model },
  { "cyclone", (const void *)&SwiftModel },
  { "ep9312", (const void *)&NoSchedModel },
  { "generic", (const void *)&NoSchedModel },
  { "iwmmxt", (const void *)&NoSchedModel },
  { "krait", (const void *)&CortexA9Model },
  { "mpcore", (const void *)&ARMV6ItinerariesModel },
  { "mpcorenovfp", (const void *)&ARMV6ItinerariesModel },
  { "sc000", (const void *)&ARMV6ItinerariesModel },
  { "sc300", (const void *)&NoSchedModel },
  { "strongarm", (const void *)&NoSchedModel },
  { "strongarm110", (const void *)&NoSchedModel },
  { "strongarm1100", (const void *)&NoSchedModel },
  { "strongarm1110", (const void *)&NoSchedModel },
  { "swift", (const void *)&SwiftModel },
  { "xscale", (const void *)&NoSchedModel }
};
#undef DBGFIELD
static inline MCSubtargetInfo *createARMMCSubtargetInfoImpl(const Triple &TT, StringRef CPU, StringRef FS) {
  return new MCSubtargetInfo(TT, CPU, FS, ARMFeatureKV, ARMSubTypeKV, 
                      ARMProcSchedKV, ARMWriteProcResTable, ARMWriteLatencyTable, ARMReadAdvanceTable, 
                      ARMStages, ARMOperandCycles, ARMForwardingPaths);
}

} // end llvm namespace
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::ARMSubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  const FeatureBitset& Bits = getFeatureBits();
  if (Bits[ARM::ARMv2] && ARMArch < ARMv2) ARMArch = ARMv2;
  if (Bits[ARM::ARMv2a] && ARMArch < ARMv2a) ARMArch = ARMv2a;
  if (Bits[ARM::ARMv3] && ARMArch < ARMv3) ARMArch = ARMv3;
  if (Bits[ARM::ARMv3m] && ARMArch < ARMv3m) ARMArch = ARMv3m;
  if (Bits[ARM::ARMv4] && ARMArch < ARMv4) ARMArch = ARMv4;
  if (Bits[ARM::ARMv4t] && ARMArch < ARMv4t) ARMArch = ARMv4t;
  if (Bits[ARM::ARMv5t] && ARMArch < ARMv5t) ARMArch = ARMv5t;
  if (Bits[ARM::ARMv5te] && ARMArch < ARMv5te) ARMArch = ARMv5te;
  if (Bits[ARM::ARMv5tej] && ARMArch < ARMv5tej) ARMArch = ARMv5tej;
  if (Bits[ARM::ARMv6] && ARMArch < ARMv6) ARMArch = ARMv6;
  if (Bits[ARM::ARMv6j] && ARMArch < ARMv7a) ARMArch = ARMv7a;
  if (Bits[ARM::ARMv6k] && ARMArch < ARMv6k) ARMArch = ARMv6k;
  if (Bits[ARM::ARMv6kz] && ARMArch < ARMv6kz) ARMArch = ARMv6kz;
  if (Bits[ARM::ARMv6m] && ARMArch < ARMv6m) ARMArch = ARMv6m;
  if (Bits[ARM::ARMv6sm] && ARMArch < ARMv6sm) ARMArch = ARMv6sm;
  if (Bits[ARM::ARMv6t2] && ARMArch < ARMv6t2) ARMArch = ARMv6t2;
  if (Bits[ARM::ARMv7a] && ARMArch < ARMv7a) ARMArch = ARMv7a;
  if (Bits[ARM::ARMv7em] && ARMArch < ARMv7em) ARMArch = ARMv7em;
  if (Bits[ARM::ARMv7k] && ARMArch < ARMv7a) ARMArch = ARMv7a;
  if (Bits[ARM::ARMv7m] && ARMArch < ARMv7m) ARMArch = ARMv7m;
  if (Bits[ARM::ARMv7r] && ARMArch < ARMv7r) ARMArch = ARMv7r;
  if (Bits[ARM::ARMv7s] && ARMArch < ARMv7a) ARMArch = ARMv7a;
  if (Bits[ARM::ARMv8a] && ARMArch < ARMv8a) ARMArch = ARMv8a;
  if (Bits[ARM::ARMv81a] && ARMArch < ARMv81a) ARMArch = ARMv81a;
  if (Bits[ARM::ARMv82a] && ARMArch < ARMv82a) ARMArch = ARMv82a;
  if (Bits[ARM::FeatureAClass] && ARMProcClass < AClass) ARMProcClass = AClass;
  if (Bits[ARM::FeatureAvoidMOVsShOp]) AvoidMOVsShifterOperand = true;
  if (Bits[ARM::FeatureAvoidPartialCPSR]) AvoidCPSRPartialUpdate = true;
  if (Bits[ARM::FeatureCRC]) HasCRC = true;
  if (Bits[ARM::FeatureCrypto]) HasCrypto = true;
  if (Bits[ARM::FeatureD16]) HasD16 = true;
  if (Bits[ARM::FeatureDB]) HasDataBarrier = true;
  if (Bits[ARM::FeatureDSP]) HasDSP = true;
  if (Bits[ARM::FeatureFP16]) HasFP16 = true;
  if (Bits[ARM::FeatureFPARMv8]) HasFPARMv8 = true;
  if (Bits[ARM::FeatureFullFP16]) HasFullFP16 = true;
  if (Bits[ARM::FeatureHWDiv]) HasHardwareDivide = true;
  if (Bits[ARM::FeatureHWDivARM]) HasHardwareDivideInARM = true;
  if (Bits[ARM::FeatureHasRAS]) HasRAS = true;
  if (Bits[ARM::FeatureHasSlowFPVMLx]) SlowFPVMLx = true;
  if (Bits[ARM::FeatureLongCalls]) GenLongCalls = true;
  if (Bits[ARM::FeatureMClass] && ARMProcClass < MClass) ARMProcClass = MClass;
  if (Bits[ARM::FeatureMP]) HasMPExtension = true;
  if (Bits[ARM::FeatureNEON]) HasNEON = true;
  if (Bits[ARM::FeatureNEONForFP]) UseNEONForSinglePrecisionFP = true;
  if (Bits[ARM::FeatureNaClTrap]) UseNaClTrap = true;
  if (Bits[ARM::FeatureNoARM]) NoARM = true;
  if (Bits[ARM::FeatureNoMovt]) NoMovt = true;
  if (Bits[ARM::FeaturePerfMon]) HasPerfMon = true;
  if (Bits[ARM::FeaturePref32BitThumb]) Pref32BitThumb = true;
  if (Bits[ARM::FeatureRClass] && ARMProcClass < RClass) ARMProcClass = RClass;
  if (Bits[ARM::FeatureReserveR9]) ReserveR9 = true;
  if (Bits[ARM::FeatureSlowFPBrcc]) SlowFPBrcc = true;
  if (Bits[ARM::FeatureStrictAlign]) StrictAlign = true;
  if (Bits[ARM::FeatureT2XtPk]) HasT2ExtractPack = true;
  if (Bits[ARM::FeatureThumb2]) HasThumb2 = true;
  if (Bits[ARM::FeatureTrustZone]) HasTrustZone = true;
  if (Bits[ARM::FeatureVFP2]) HasVFPv2 = true;
  if (Bits[ARM::FeatureVFP3]) HasVFPv3 = true;
  if (Bits[ARM::FeatureVFP4]) HasVFPv4 = true;
  if (Bits[ARM::FeatureVFPOnlySP]) FPOnlySP = true;
  if (Bits[ARM::FeatureVMLxForwarding]) HasVMLxForwarding = true;
  if (Bits[ARM::FeatureVirtualization]) HasVirtualization = true;
  if (Bits[ARM::FeatureZCZeroing]) HasZeroCycleZeroing = true;
  if (Bits[ARM::HasV4TOps]) HasV4TOps = true;
  if (Bits[ARM::HasV5TEOps]) HasV5TEOps = true;
  if (Bits[ARM::HasV5TOps]) HasV5TOps = true;
  if (Bits[ARM::HasV6KOps]) HasV6KOps = true;
  if (Bits[ARM::HasV6MOps]) HasV6MOps = true;
  if (Bits[ARM::HasV6Ops]) HasV6Ops = true;
  if (Bits[ARM::HasV6T2Ops]) HasV6T2Ops = true;
  if (Bits[ARM::HasV7Ops]) HasV7Ops = true;
  if (Bits[ARM::HasV8Ops]) HasV8Ops = true;
  if (Bits[ARM::HasV8_1aOps]) HasV8_1aOps = true;
  if (Bits[ARM::HasV8_2aOps]) HasV8_2aOps = true;
  if (Bits[ARM::IWMMXT] && ARMArch < ARMv5te) ARMArch = ARMv5te;
  if (Bits[ARM::IWMMXT2] && ARMArch < ARMv5te) ARMArch = ARMv5te;
  if (Bits[ARM::ModeSoftFloat]) UseSoftFloat = true;
  if (Bits[ARM::ModeThumb]) InThumbMode = true;
  if (Bits[ARM::ProcA5] && ARMProcFamily < CortexA5) ARMProcFamily = CortexA5;
  if (Bits[ARM::ProcA7] && ARMProcFamily < CortexA7) ARMProcFamily = CortexA7;
  if (Bits[ARM::ProcA8] && ARMProcFamily < CortexA8) ARMProcFamily = CortexA8;
  if (Bits[ARM::ProcA9] && ARMProcFamily < CortexA9) ARMProcFamily = CortexA9;
  if (Bits[ARM::ProcA12] && ARMProcFamily < CortexA12) ARMProcFamily = CortexA12;
  if (Bits[ARM::ProcA15] && ARMProcFamily < CortexA15) ARMProcFamily = CortexA15;
  if (Bits[ARM::ProcA17] && ARMProcFamily < CortexA17) ARMProcFamily = CortexA17;
  if (Bits[ARM::ProcA35] && ARMProcFamily < CortexA35) ARMProcFamily = CortexA35;
  if (Bits[ARM::ProcA53] && ARMProcFamily < CortexA53) ARMProcFamily = CortexA53;
  if (Bits[ARM::ProcA57] && ARMProcFamily < CortexA57) ARMProcFamily = CortexA57;
  if (Bits[ARM::ProcA72] && ARMProcFamily < CortexA72) ARMProcFamily = CortexA72;
  if (Bits[ARM::ProcKrait] && ARMProcFamily < Krait) ARMProcFamily = Krait;
  if (Bits[ARM::ProcR4] && ARMProcFamily < CortexR4) ARMProcFamily = CortexR4;
  if (Bits[ARM::ProcR5] && ARMProcFamily < CortexR5) ARMProcFamily = CortexR5;
  if (Bits[ARM::ProcR7] && ARMProcFamily < CortexR7) ARMProcFamily = CortexR7;
  if (Bits[ARM::ProcSwift] && ARMProcFamily < Swift) ARMProcFamily = Swift;
  if (Bits[ARM::XScale] && ARMArch < ARMv5te) ARMArch = ARMv5te;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct ARMGenSubtargetInfo : public TargetSubtargetInfo {
  explicit ARMGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS);
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
extern const llvm::SubtargetFeatureKV ARMFeatureKV[];
extern const llvm::SubtargetFeatureKV ARMSubTypeKV[];
extern const llvm::SubtargetInfoKV ARMProcSchedKV[];
extern const llvm::MCWriteProcResEntry ARMWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry ARMWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry ARMReadAdvanceTable[];
extern const llvm::InstrStage ARMStages[];
extern const unsigned ARMOperandCycles[];
extern const unsigned ARMForwardingPaths[];
ARMGenSubtargetInfo::ARMGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo(TT, CPU, FS, makeArrayRef(ARMFeatureKV, 96), makeArrayRef(ARMSubTypeKV, 64), 
                        ARMProcSchedKV, ARMWriteProcResTable, ARMWriteLatencyTable, ARMReadAdvanceTable, 
                        ARMStages, ARMOperandCycles, ARMForwardingPaths) {}

unsigned ARMGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {

  const ARMBaseInstrInfo *TII =
    static_cast<const ARMBaseInstrInfo*>(SchedModel->getInstrInfo());
  (void)TII;

  switch (SchedClass) {
  case 3: // IIC_iALUsr_WriteALUsi_ReadALU
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 594; // SwiftWriteP01TwoCycle_ReadALU
      if ((true))
        return 595; // WriteALU_ReadALU
    }
    break;
  case 4: // IIC_iALUsr_WriteALUsr_ReadALUsr
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 596; // SwiftWriteP01ThreeCycleTwoUops_anonymous_3044
      if ((true))
        return 597; // SwiftWriteP01TwoCycle_NoReadAdvance
    }
    break;
  case 5: // IIC_iALUsr_WriteALUSsr_ReadALUsr
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 598; // SwiftWriteP0ThreeCycleThreeUops_anonymous_3044
      if ((true))
        return 597; // SwiftWriteP01TwoCycle_NoReadAdvance
    }
    break;
  case 8: // IIC_iBITsr_WriteALUsi_ReadALU
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 594; // SwiftWriteP01TwoCycle_ReadALU
      if ((true))
        return 595; // WriteALU_ReadALU
    }
    break;
  case 9: // IIC_iBITsr_WriteALUsr_ReadALUsr
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 596; // SwiftWriteP01ThreeCycleTwoUops_anonymous_3044
      if ((true))
        return 597; // SwiftWriteP01TwoCycle_NoReadAdvance
    }
    break;
  case 19: // IIC_iCMPsr_WriteCMPsi_ReadALU
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 599; // SwiftWriteP01OneCycle_ReadALU
      if ((true))
        return 594; // SwiftWriteP01TwoCycle_ReadALU
    }
    break;
  case 24: // IIC_iLoad_m
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 600; // A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 601; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 602; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 603; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 604; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 605; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 606; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 607; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 608; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue
    }
    break;
  case 25: // IIC_iLoad_mu
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 609; // A9WriteAdr_A9WriteL1_A9WriteL1Hi_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 610; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 611; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 612; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 613; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 614; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 615; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 616; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 617; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
    }
    break;
  case 26: // IIC_iLoad_mBr
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 618; // A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 619; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 620; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 621; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 622; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 623; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 624; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 625; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 626; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB
    }
    break;
  case 58: // IIC_iALUsi_WriteALUsi_ReadALU
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 594; // SwiftWriteP01TwoCycle_ReadALU
      if ((true))
        return 595; // WriteALU_ReadALU
    }
    break;
  case 59: // IIC_iBITsi_WriteALUsi_ReadALU
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 594; // SwiftWriteP01TwoCycle_ReadALU
      if ((true))
        return 595; // WriteALU_ReadALU
    }
    break;
  case 66: // IIC_iStore_m
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 609; // A9WriteAdr_A9WriteL1_A9WriteL1Hi_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 610; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 611; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 612; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 613; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 614; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 615; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 616; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 617; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
    }
    break;
  case 67: // IIC_iStore_mu
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 609; // A9WriteAdr_A9WriteL1_A9WriteL1Hi_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 610; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 611; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 612; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 613; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 614; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 615; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 616; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 617; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
    }
    break;
  case 77: // IIC_iEXTAr_WriteALUsr
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 627; // SwiftWriteP01ThreeCycleTwoUops
      if ((true))
        return 628; // SwiftWriteP01TwoCycle
    }
    break;
  case 78: // IIC_iEXTr_WriteALUsi
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 628; // SwiftWriteP01TwoCycle
      if ((true))
        return 629; // WriteALU
    }
    break;
  case 81: // IIC_iTSTsr_WriteCMPsi_ReadALU
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 599; // SwiftWriteP01OneCycle_ReadALU
      if ((true))
        return 594; // SwiftWriteP01TwoCycle_ReadALU
    }
    break;
  case 153: // IIC_fpLoad_mu
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 630; // A9WriteAdr_(A9WriteIssue_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 631; // (A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 632; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 633; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 634; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 635; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 636; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 637; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if ((TII->getNumLDMAddresses(MI) == 0)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 631; // (A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 638; // A9WriteAdr_A9WriteLMfp1_A9WriteL1Hi
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 639; // (A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 640; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 641; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 642; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 643; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 644; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 645; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if ((TII->getNumLDMAddresses(MI) == 0)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 646; // (A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
    }
    break;
  case 154: // IIC_fpLoad_m
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 647; // (A9WriteIssue_A9WriteLfpOp)_A9WriteAdr
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 648; // A9WriteLMfp1_A9WriteL1Hi_A9WriteAdr
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 649; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 650; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 651; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 652; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 653; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 654; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 655; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 649; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 656; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 657; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 658; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 659; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 660; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 661; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 662; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 663; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)
    }
    break;
  case 238: // IIC_iALUsi_WriteALUsi_ReadALUsr
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI))
          && (TII->isPredicated(MI)))
        return 664; // SwiftWriteP01TwoCycle_anonymous_3044
      if ((true)
          && (TII->isPredicated(MI)))
        return 665; // WriteALU_anonymous_3044
      if ((true))
        return 666; // WriteALU_NoReadAdvance
    }
    break;
  case 240: // IIC_iCMPsi_WriteCMPsi_ReadALU_ReadALU
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 667; // SwiftWriteP01OneCycle_ReadALU_ReadALU
      if ((true))
        return 668; // SwiftWriteP01TwoCycle_ReadALU_ReadALU
    }
    break;
  case 243: // IIC_iCMPsi_WriteCMPsi
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 669; // SwiftWriteP01OneCycle
      if ((true))
        return 628; // SwiftWriteP01TwoCycle
    }
    break;
  case 250: // IIC_iALUsir_WriteALUsi_ReadALU
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 594; // SwiftWriteP01TwoCycle_ReadALU
      if ((true))
        return 595; // WriteALU_ReadALU
    }
    break;
  case 257: // IIC_iTSTsi_WriteCMPsi
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 669; // SwiftWriteP01OneCycle
      if ((true))
        return 628; // SwiftWriteP01TwoCycle
    }
    break;
  case 261: // IIC_iPop
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 600; // A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 601; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 602; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 603; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 604; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 605; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 606; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 607; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 608; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue
    }
    break;
  case 262: // IIC_iPop_Br_WriteBrL
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 618; // A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 619; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 620; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 621; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 622; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 623; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 624; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 625; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 626; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB
    }
    break;
  case 266: // ANDrsi_BICrsi_EORrsi_ORRrsi
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 594; // SwiftWriteP01TwoCycle_ReadALU
      if ((true))
        return 595; // WriteALU_ReadALU
    }
    break;
  case 267: // ANDrsr_BICrsr_EORrsr_ORRrsr
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 596; // SwiftWriteP01ThreeCycleTwoUops_anonymous_3044
      if ((true))
        return 597; // SwiftWriteP01TwoCycle_NoReadAdvance
    }
    break;
  case 277: // SEL
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 670; // (SwiftWriteP0OneCycle_SwiftWriteP0OneCycle)
      if ((true))
        return 671; // SwiftWriteP0OneCycle
    }
    break;
  case 279: // MLA_MLAv5_MLS_SMMLA_SMMLAR_SMMLS_SMMLSR
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 672; // SwiftWriteP0P01FiveCycleTwoUops_ReadALU_ReadALU_anonymous_3075
      if ((true))
        return 673; // SwiftWriteP0FourCycle_ReadALU_ReadALU_ReadALU
    }
    break;
  case 285: // SMLABB_SMLABT_SMLATB_SMLATT_SMLAWB_SMLAWT
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 672; // SwiftWriteP0P01FiveCycleTwoUops_ReadALU_ReadALU_anonymous_3075
      if ((true))
        return 673; // SwiftWriteP0FourCycle_ReadALU_ReadALU_ReadALU
    }
    break;
  case 290: // SXTB_SXTB16_SXTH_UXTB_UXTB16_UXTH
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isSwiftFastImmShift(MI)))
        return 628; // SwiftWriteP01TwoCycle
      if ((true))
        return 629; // WriteALU
    }
    break;
  case 296: // t2SEL
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 670; // (SwiftWriteP0OneCycle_SwiftWriteP0OneCycle)
      if ((true))
        return 671; // SwiftWriteP0OneCycle
    }
    break;
  case 301: // SADD16_SADD8_SASX_SSAX_SSUB16_SSUB8_UADD16_UADD8_UASX_USAX_USUB16_USUB8
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 627; // SwiftWriteP01ThreeCycleTwoUops
      if ((true))
        return 628; // SwiftWriteP01TwoCycle
    }
    break;
  case 302: // t2SADD16_t2SADD8_t2SASX_t2SSAX_t2SSUB16_t2SSUB8_t2UADD16_t2UADD8_t2UASX_t2USAX_t2USUB16_t2USUB8
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 627; // SwiftWriteP01ThreeCycleTwoUops
      if ((true))
        return 628; // SwiftWriteP01TwoCycle
    }
    break;
  case 304: // SXTAB_SXTAB16_SXTAH_UXTAB_UXTAB16_UXTAH
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 627; // SwiftWriteP01ThreeCycleTwoUops
      if ((true))
        return 628; // SwiftWriteP01TwoCycle
    }
    break;
  case 313: // t2MLA_t2MLS_t2SMMLA_t2SMMLAR_t2SMMLS_t2SMMLSR
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 672; // SwiftWriteP0P01FiveCycleTwoUops_ReadALU_ReadALU_anonymous_3075
      if ((true))
        return 673; // SwiftWriteP0FourCycle_ReadALU_ReadALU_ReadALU
    }
    break;
  case 316: // SMLSD_SMLSDX
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 672; // SwiftWriteP0P01FiveCycleTwoUops_ReadALU_ReadALU_anonymous_3075
      if ((true))
        return 673; // SwiftWriteP0FourCycle_ReadALU_ReadALU_ReadALU
    }
    break;
  case 317: // t2SMLABB_t2SMLABT_t2SMLATB_t2SMLATT_t2SMLAWB_t2SMLAWT
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 672; // SwiftWriteP0P01FiveCycleTwoUops_ReadALU_ReadALU_anonymous_3075
      if ((true))
        return 673; // SwiftWriteP0FourCycle_ReadALU_ReadALU_ReadALU
    }
    break;
  case 318: // t2SMLSD_t2SMLSDX
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 672; // SwiftWriteP0P01FiveCycleTwoUops_ReadALU_ReadALU_anonymous_3075
      if ((true))
        return 673; // SwiftWriteP0FourCycle_ReadALU_ReadALU_ReadALU
    }
    break;
  case 319: // SMLAD_SMLADX
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 674; // SwiftWriteP0P01FiveCycleTwoUops
      if ((true))
        return 675; // SwiftWriteP0FourCycle
    }
    break;
  case 320: // t2SMLAD_t2SMLADX
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->isPredicated(MI)))
        return 674; // SwiftWriteP0P01FiveCycleTwoUops
      if ((true))
        return 675; // SwiftWriteP0FourCycle
    }
    break;
  case 353: // LDMDA_LDMDB_LDMIA_LDMIB_sysLDMDA_sysLDMDB_sysLDMIA_sysLDMIB_t2LDMDB_t2LDMIA_tLDMIA
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 600; // A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 601; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 602; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 603; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 604; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 605; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 606; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 607; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 608; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 676; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 677; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 678; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 679; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 680; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 681; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 682; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 683; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 684; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 685; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 686; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 687; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 688; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 689; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLDMAddrNoWB
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 690; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy_SwiftWriteLDMAddrNoWB
      if ((true))
        return 691; // SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLDMAddrNoWB
    }
    break;
  case 354: // LDMDA_UPD_LDMDB_UPD_LDMIA_UPD_LDMIB_UPD_sysLDMDA_UPD_sysLDMDB_UPD_sysLDMIA_UPD_sysLDMIB_UPD_t2LDMDB_UPD_t2LDMIA_UPD_tLDMIA_UPD
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 609; // A9WriteAdr_A9WriteL1_A9WriteL1Hi_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 610; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 611; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 612; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 613; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 614; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 615; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 616; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 617; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 692; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 693; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 694; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 695; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 696; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 697; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 698; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 699; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 700; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 701; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 702; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 703; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 704; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 705; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 706; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy
      if ((true))
        return 707; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo
    }
    break;
  case 355: // LDMIA_RET_t2LDMIA_RET
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 618; // A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 619; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 620; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 621; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 622; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 623; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 624; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 625; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 626; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 708; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 709; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 710; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 711; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 712; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 713; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 714; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 715; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 716; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 717; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 718; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 719; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 720; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 721; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 722; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy_SwiftWriteP1TwoCycle
      if ((true))
        return 723; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteP1TwoCycle
    }
    break;
  case 356: // tPOP
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 600; // A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 601; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 602; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 603; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 604; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 605; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 606; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 607; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 608; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteIssue
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 708; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 709; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 710; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 711; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 712; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 713; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 714; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 715; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 716; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 717; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 718; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 719; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 720; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 721; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 722; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy_SwiftWriteP1TwoCycle
      if ((true))
        return 723; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteP1TwoCycle
    }
    break;
  case 357: // tPOP_RET
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 618; // A9WriteL1_A9WriteL1Hi_A9WriteAdr_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 619; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 620; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 621; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 622; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 623; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 624; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 625; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteB
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 626; // A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)_A9WriteB
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 708; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 709; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 710; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 711; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 712; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 713; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 714; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 715; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 716; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 717; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 718; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 719; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 720; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 721; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteP1TwoCycle
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 722; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5Cy_SwiftWriteLM6Cy_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM12Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM16Cy_SwiftWriteLM17Cy_SwiftWriteLM18Cy_SwiftWriteP1TwoCycle
      if ((true))
        return 723; // SwiftWriteLDMAddrWB_SwiftWriteLM3Cy_SwiftWriteLM4Cy_SwiftWriteLM5CyNo_SwiftWriteLM6CyNo_SwiftWriteLM7CyNo_SwiftWriteLM8CyNo_SwiftWriteLM9CyNo_SwiftWriteLM10CyNo_SwiftWriteLM11CyNo_SwiftWriteLM12CyNo_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM15CyNo_SwiftWriteLM16CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteP1TwoCycle
    }
    break;
  case 374: // STMDA_STMDB_STMIA_STMIB_sysSTMDA_sysSTMDB_sysSTMIA_sysSTMIB_t2STMDB_t2STMIA
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 609; // A9WriteAdr_A9WriteL1_A9WriteL1Hi_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 610; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 611; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 612; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 613; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 614; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 615; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 616; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 617; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 724; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 725; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 726; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 727; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 728; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 729; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 730; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 731; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 732; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 733; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 734; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 735; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 736; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 737; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 738; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((true))
        return 724; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr)
    }
    break;
  case 375: // STMDA_UPD_STMDB_UPD_STMIA_UPD_STMIB_UPD_sysSTMDA_UPD_sysSTMDB_UPD_sysSTMIA_UPD_sysSTMIB_UPD_t2STMDB_UPD_t2STMIA_UPD_tSTMIA_UPD
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 609; // A9WriteAdr_A9WriteL1_A9WriteL1Hi_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 610; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 611; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 612; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 613; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 614; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 615; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 616; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 617; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 739; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 740; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 741; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 742; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 743; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 744; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 745; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 746; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 747; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 748; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 749; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 750; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 751; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 752; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 753; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((true))
        return 739; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr)
    }
    break;
  case 376: // tPUSH
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 609; // A9WriteAdr_A9WriteL1_A9WriteL1Hi_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 610; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 611; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 612; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 613; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 614; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 615; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 616; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
      if ((TII->getNumLDMAddresses(MI) == 0))
        return 617; // (A9WriteAdr_A9WriteAdr)_A9WriteL1_A9WriteL1Hi_(A9WriteLMLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_A9WriteIssue
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 739; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 740; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 741; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 742; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 743; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 744; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 745; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 746; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 747; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 748; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 749; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 750; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 751; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 752; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 753; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((true))
        return 739; // SwiftWriteP01OneCycle_(SwiftWriteStIncAddr_SwiftWriteStIncAddr)
    }
    break;
  case 515: // VLDMQIA
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 647; // (A9WriteIssue_A9WriteLfpOp)_A9WriteAdr
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 648; // A9WriteLMfp1_A9WriteL1Hi_A9WriteAdr
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 649; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 650; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 651; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 652; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 653; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 654; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 655; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 649; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 656; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 657; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 658; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 659; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 660; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 661; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 662; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 663; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)
    }
    break;
  case 517: // VLDMDIA_VLDMSIA
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 647; // (A9WriteIssue_A9WriteLfpOp)_A9WriteAdr
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 648; // A9WriteLMfp1_A9WriteL1Hi_A9WriteAdr
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 649; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 650; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 651; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 652; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 653; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 654; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 655; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 649; // (A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)_(A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 656; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 657; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 658; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 659; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 660; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 661; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 662; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)
      if ((TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 663; // A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteAdr_A9WriteAdr)
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 1))
        return 754; // SwiftWriteLM4Cy
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 755; // SwiftWriteLM4Cy_SwiftWriteLM4CyNo
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 756; // SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 757; // SwiftWriteLM4Cy_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 758; // SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 759; // SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 760; // SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 761; // SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 762; // SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 763; // SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 764; // SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 765; // SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM11Cy_SwiftWriteLM11Cy_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 766; // SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 767; // SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 768; // SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM17Cy_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 769; // SwiftWriteLM7Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM18CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm4
      if ((true))
        return 770; // SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2
    }
    break;
  case 518: // VLDMDDB_UPD_VLDMDIA_UPD_VLDMSDB_UPD_VLDMSIA_UPD
    if (SchedModel->getProcessorID() == 2) { // CortexA9Model
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 630; // A9WriteAdr_(A9WriteIssue_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 631; // (A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 632; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 633; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 634; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 635; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 636; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 637; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp_A9WriteLfpOp)
      if ((TII->getNumLDMAddresses(MI) == 0)
          && (TargetRegisterInfo::isVirtualRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 631; // (A9WriteAdr_A9WriteAdr)_(A9WriteIssue_A9WriteLfpOp_A9WriteLfpOp)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 1)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 1))
        return 638; // A9WriteAdr_A9WriteLMfp1_A9WriteL1Hi
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 2)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 2))
        return 639; // (A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 3)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 3))
        return 640; // (A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 4)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 4))
        return 641; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 5)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 5))
        return 642; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 6)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 6))
        return 643; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 7)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 7))
        return 644; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if (((TII->getNumLDMAddresses(MI)+1)/2 == 8)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && ((TII->getNumLDMAddresses(MI)+1)/2 == 8))
        return 645; // (A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
      if ((TII->getNumLDMAddresses(MI) == 0)
          && (TargetRegisterInfo::isPhysicalRegister(MI->getOperand(0).getReg()))
          && (TII->getNumLDMAddresses(MI) == 0))
        return 646; // (A9WriteAdr_A9WriteAdr)_A9WriteLMfp1_(A9WriteLMfpLo_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)_(A9WriteLMHi_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1_A9WriteCycle1)
    }
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 1))
        return 771; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM4Cy
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 772; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM4Cy_SwiftWriteLM4CyNo
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 773; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 774; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM4Cy_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo_SwiftWriteLM4CyNo
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 775; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13CyNo_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 776; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 777; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 778; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 779; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 780; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm5
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 781; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 782; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM11Cy_SwiftWriteLM11Cy_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteLM11CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm3
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 783; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14CyNo_SwiftWriteLM17CyNo_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 784; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM10Cy_SwiftWriteLM14Cy_SwiftWriteLM14Cy_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteLM14CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm7
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 785; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM9Cy_SwiftWriteLM10Cy_SwiftWriteLM13Cy_SwiftWriteLM14Cy_SwiftWriteLM17Cy_SwiftWriteLM18CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM21CyNo_SwiftWriteLM22CyNo_SwiftWriteLM25CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm9
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 786; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM10Cy_SwiftWriteLM11Cy_SwiftWriteLM14Cy_SwiftWriteLM15Cy_SwiftWriteLM18CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteLM19CyNo_SwiftWriteLM22CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm4
      if ((true))
        return 787; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteLM7Cy_SwiftWriteLM8Cy_SwiftWriteLM13Cy_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteLM13CyNo_SwiftWriteP01OneCycle_SwiftVLDMPerm2
    }
    break;
  case 519: // VSTMDIA_VSTMSIA
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 1))
        return 788; // SwiftWriteStIncAddr
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 788; // SwiftWriteStIncAddr
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 726; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 788; // SwiftWriteStIncAddr
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 728; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 726; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 730; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 725; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 732; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 728; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 734; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 726; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 736; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 730; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 738; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 727; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((true))
        return 725; // (SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
    }
    break;
  case 520: // VSTMDDB_UPD_VSTMDIA_UPD_VSTMSDB_UPD_VSTMSIA_UPD
    if (SchedModel->getProcessorID() == 4) { // SwiftModel
      if ((TII->getNumLDMAddresses(MI) == 1))
        return 789; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteStIncAddr
      if ((TII->getNumLDMAddresses(MI) == 2))
        return 789; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteStIncAddr
      if ((TII->getNumLDMAddresses(MI) == 3))
        return 790; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 4))
        return 789; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_SwiftWriteStIncAddr
      if ((TII->getNumLDMAddresses(MI) == 5))
        return 791; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 6))
        return 790; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 7))
        return 792; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 8))
        return 793; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 9))
        return 794; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 10))
        return 791; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 11))
        return 795; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 12))
        return 790; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 13))
        return 796; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 14))
        return 792; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 15))
        return 797; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((TII->getNumLDMAddresses(MI) == 16))
        return 798; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
      if ((true))
        return 793; // (SwiftWriteP01OneCycle_SwiftWriteP01OneCycle)_(SwiftWriteStIncAddr_SwiftWriteStIncAddr_SwiftWriteStIncAddr)
    }
    break;
  };
  report_fatal_error("Expected a variant SchedClass");
} // ARMGenSubtargetInfo::resolveSchedClass
} // end llvm namespace
#endif // GET_SUBTARGETINFO_CTOR

