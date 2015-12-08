/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register Enum Values                                                *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_ENUM
#undef GET_REGINFO_ENUM
namespace llvm {

class MCRegisterClass;
extern const MCRegisterClass NVPTXMCRegisterClasses[];

namespace NVPTX {
enum {
  NoRegister,
  VRDepot = 1,
  VRFrame = 2,
  VRFrameLocal = 3,
  ENVREG0 = 4,
  ENVREG1 = 5,
  ENVREG2 = 6,
  ENVREG3 = 7,
  ENVREG4 = 8,
  ENVREG5 = 9,
  ENVREG6 = 10,
  ENVREG7 = 11,
  ENVREG8 = 12,
  ENVREG9 = 13,
  ENVREG10 = 14,
  ENVREG11 = 15,
  ENVREG12 = 16,
  ENVREG13 = 17,
  ENVREG14 = 18,
  ENVREG15 = 19,
  ENVREG16 = 20,
  ENVREG17 = 21,
  ENVREG18 = 22,
  ENVREG19 = 23,
  ENVREG20 = 24,
  ENVREG21 = 25,
  ENVREG22 = 26,
  ENVREG23 = 27,
  ENVREG24 = 28,
  ENVREG25 = 29,
  ENVREG26 = 30,
  ENVREG27 = 31,
  ENVREG28 = 32,
  ENVREG29 = 33,
  ENVREG30 = 34,
  ENVREG31 = 35,
  F0 = 36,
  F1 = 37,
  F2 = 38,
  F3 = 39,
  F4 = 40,
  FL0 = 41,
  FL1 = 42,
  FL2 = 43,
  FL3 = 44,
  FL4 = 45,
  P0 = 46,
  P1 = 47,
  P2 = 48,
  P3 = 49,
  P4 = 50,
  R0 = 51,
  R1 = 52,
  R2 = 53,
  R3 = 54,
  R4 = 55,
  RL0 = 56,
  RL1 = 57,
  RL2 = 58,
  RL3 = 59,
  RL4 = 60,
  RS0 = 61,
  RS1 = 62,
  RS2 = 63,
  RS3 = 64,
  RS4 = 65,
  da0 = 66,
  da1 = 67,
  da2 = 68,
  da3 = 69,
  da4 = 70,
  fa0 = 71,
  fa1 = 72,
  fa2 = 73,
  fa3 = 74,
  fa4 = 75,
  ia0 = 76,
  ia1 = 77,
  ia2 = 78,
  ia3 = 79,
  ia4 = 80,
  la0 = 81,
  la1 = 82,
  la2 = 83,
  la3 = 84,
  la4 = 85,
  NUM_TARGET_REGS 	// 86
};
}

// Register classes
namespace NVPTX {
enum {
  Int1RegsRegClassID = 0,
  Int16RegsRegClassID = 1,
  SpecialRegsRegClassID = 2,
  Float32ArgRegsRegClassID = 3,
  Float32RegsRegClassID = 4,
  Int32ArgRegsRegClassID = 5,
  Int32RegsRegClassID = 6,
  Float64ArgRegsRegClassID = 7,
  Float64RegsRegClassID = 8,
  Int64ArgRegsRegClassID = 9,
  Int64RegsRegClassID = 10,

  };
}
} // End llvm namespace
#endif // GET_REGINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* MC Register Information                                                    *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_MC_DESC
#undef GET_REGINFO_MC_DESC
namespace llvm {

extern const MCPhysReg NVPTXRegDiffLists[] = {
  /* 0 */ 65535, 0,
};

extern const unsigned NVPTXLaneMaskLists[] = {
  /* 0 */ 0x00000000, ~0u,
};

extern const uint16_t NVPTXSubRegIdxLists[] = {
  /* 0 */ 0,
};

extern const MCRegisterInfo::SubRegCoveredBits NVPTXSubRegIdxRanges[] = {
  { 65535, 65535 },
};

extern const char NVPTXRegStrings[] = {
  /* 0 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '0', 0,
  /* 9 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '0', 0,
  /* 18 */ 'E', 'N', 'V', 'R', 'E', 'G', '3', '0', 0,
  /* 27 */ 'F', '0', 0,
  /* 30 */ 'E', 'N', 'V', 'R', 'E', 'G', '0', 0,
  /* 38 */ 'F', 'L', '0', 0,
  /* 42 */ 'R', 'L', '0', 0,
  /* 46 */ 'P', '0', 0,
  /* 49 */ 'R', '0', 0,
  /* 52 */ 'R', 'S', '0', 0,
  /* 56 */ 'd', 'a', '0', 0,
  /* 60 */ 'f', 'a', '0', 0,
  /* 64 */ 'i', 'a', '0', 0,
  /* 68 */ 'l', 'a', '0', 0,
  /* 72 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '1', 0,
  /* 81 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '1', 0,
  /* 90 */ 'E', 'N', 'V', 'R', 'E', 'G', '3', '1', 0,
  /* 99 */ 'F', '1', 0,
  /* 102 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', 0,
  /* 110 */ 'F', 'L', '1', 0,
  /* 114 */ 'R', 'L', '1', 0,
  /* 118 */ 'P', '1', 0,
  /* 121 */ 'R', '1', 0,
  /* 124 */ 'R', 'S', '1', 0,
  /* 128 */ 'd', 'a', '1', 0,
  /* 132 */ 'f', 'a', '1', 0,
  /* 136 */ 'i', 'a', '1', 0,
  /* 140 */ 'l', 'a', '1', 0,
  /* 144 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '2', 0,
  /* 153 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '2', 0,
  /* 162 */ 'F', '2', 0,
  /* 165 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', 0,
  /* 173 */ 'F', 'L', '2', 0,
  /* 177 */ 'R', 'L', '2', 0,
  /* 181 */ 'P', '2', 0,
  /* 184 */ 'R', '2', 0,
  /* 187 */ 'R', 'S', '2', 0,
  /* 191 */ 'd', 'a', '2', 0,
  /* 195 */ 'f', 'a', '2', 0,
  /* 199 */ 'i', 'a', '2', 0,
  /* 203 */ 'l', 'a', '2', 0,
  /* 207 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '3', 0,
  /* 216 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '3', 0,
  /* 225 */ 'F', '3', 0,
  /* 228 */ 'E', 'N', 'V', 'R', 'E', 'G', '3', 0,
  /* 236 */ 'F', 'L', '3', 0,
  /* 240 */ 'R', 'L', '3', 0,
  /* 244 */ 'P', '3', 0,
  /* 247 */ 'R', '3', 0,
  /* 250 */ 'R', 'S', '3', 0,
  /* 254 */ 'd', 'a', '3', 0,
  /* 258 */ 'f', 'a', '3', 0,
  /* 262 */ 'i', 'a', '3', 0,
  /* 266 */ 'l', 'a', '3', 0,
  /* 270 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '4', 0,
  /* 279 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '4', 0,
  /* 288 */ 'F', '4', 0,
  /* 291 */ 'E', 'N', 'V', 'R', 'E', 'G', '4', 0,
  /* 299 */ 'F', 'L', '4', 0,
  /* 303 */ 'R', 'L', '4', 0,
  /* 307 */ 'P', '4', 0,
  /* 310 */ 'R', '4', 0,
  /* 313 */ 'R', 'S', '4', 0,
  /* 317 */ 'd', 'a', '4', 0,
  /* 321 */ 'f', 'a', '4', 0,
  /* 325 */ 'i', 'a', '4', 0,
  /* 329 */ 'l', 'a', '4', 0,
  /* 333 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '5', 0,
  /* 342 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '5', 0,
  /* 351 */ 'E', 'N', 'V', 'R', 'E', 'G', '5', 0,
  /* 359 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '6', 0,
  /* 368 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '6', 0,
  /* 377 */ 'E', 'N', 'V', 'R', 'E', 'G', '6', 0,
  /* 385 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '7', 0,
  /* 394 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '7', 0,
  /* 403 */ 'E', 'N', 'V', 'R', 'E', 'G', '7', 0,
  /* 411 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '8', 0,
  /* 420 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '8', 0,
  /* 429 */ 'E', 'N', 'V', 'R', 'E', 'G', '8', 0,
  /* 437 */ 'E', 'N', 'V', 'R', 'E', 'G', '1', '9', 0,
  /* 446 */ 'E', 'N', 'V', 'R', 'E', 'G', '2', '9', 0,
  /* 455 */ 'E', 'N', 'V', 'R', 'E', 'G', '9', 0,
  /* 463 */ 'V', 'R', 'F', 'r', 'a', 'm', 'e', 0,
  /* 471 */ 'V', 'R', 'F', 'r', 'a', 'm', 'e', 'L', 'o', 'c', 'a', 'l', 0,
  /* 484 */ 'V', 'R', 'D', 'e', 'p', 'o', 't', 0,
};

extern const MCRegisterDesc NVPTXRegDesc[] = { // Descriptors
  { 8, 0, 0, 0, 0, 0 },
  { 484, 1, 1, 0, 1, 0 },
  { 463, 1, 1, 0, 1, 0 },
  { 471, 1, 1, 0, 1, 0 },
  { 30, 1, 1, 0, 1, 0 },
  { 102, 1, 1, 0, 1, 0 },
  { 165, 1, 1, 0, 1, 0 },
  { 228, 1, 1, 0, 1, 0 },
  { 291, 1, 1, 0, 1, 0 },
  { 351, 1, 1, 0, 1, 0 },
  { 377, 1, 1, 0, 1, 0 },
  { 403, 1, 1, 0, 1, 0 },
  { 429, 1, 1, 0, 1, 0 },
  { 455, 1, 1, 0, 1, 0 },
  { 0, 1, 1, 0, 1, 0 },
  { 72, 1, 1, 0, 1, 0 },
  { 144, 1, 1, 0, 1, 0 },
  { 207, 1, 1, 0, 1, 0 },
  { 270, 1, 1, 0, 1, 0 },
  { 333, 1, 1, 0, 1, 0 },
  { 359, 1, 1, 0, 1, 0 },
  { 385, 1, 1, 0, 1, 0 },
  { 411, 1, 1, 0, 1, 0 },
  { 437, 1, 1, 0, 1, 0 },
  { 9, 1, 1, 0, 1, 0 },
  { 81, 1, 1, 0, 1, 0 },
  { 153, 1, 1, 0, 1, 0 },
  { 216, 1, 1, 0, 1, 0 },
  { 279, 1, 1, 0, 1, 0 },
  { 342, 1, 1, 0, 1, 0 },
  { 368, 1, 1, 0, 1, 0 },
  { 394, 1, 1, 0, 1, 0 },
  { 420, 1, 1, 0, 1, 0 },
  { 446, 1, 1, 0, 1, 0 },
  { 18, 1, 1, 0, 1, 0 },
  { 90, 1, 1, 0, 1, 0 },
  { 27, 1, 1, 0, 1, 0 },
  { 99, 1, 1, 0, 1, 0 },
  { 162, 1, 1, 0, 1, 0 },
  { 225, 1, 1, 0, 1, 0 },
  { 288, 1, 1, 0, 1, 0 },
  { 38, 1, 1, 0, 1, 0 },
  { 110, 1, 1, 0, 1, 0 },
  { 173, 1, 1, 0, 1, 0 },
  { 236, 1, 1, 0, 1, 0 },
  { 299, 1, 1, 0, 1, 0 },
  { 46, 1, 1, 0, 1, 0 },
  { 118, 1, 1, 0, 1, 0 },
  { 181, 1, 1, 0, 1, 0 },
  { 244, 1, 1, 0, 1, 0 },
  { 307, 1, 1, 0, 1, 0 },
  { 49, 1, 1, 0, 1, 0 },
  { 121, 1, 1, 0, 1, 0 },
  { 184, 1, 1, 0, 1, 0 },
  { 247, 1, 1, 0, 1, 0 },
  { 310, 1, 1, 0, 1, 0 },
  { 42, 1, 1, 0, 1, 0 },
  { 114, 1, 1, 0, 1, 0 },
  { 177, 1, 1, 0, 1, 0 },
  { 240, 1, 1, 0, 1, 0 },
  { 303, 1, 1, 0, 1, 0 },
  { 52, 1, 1, 0, 1, 0 },
  { 124, 1, 1, 0, 1, 0 },
  { 187, 1, 1, 0, 1, 0 },
  { 250, 1, 1, 0, 1, 0 },
  { 313, 1, 1, 0, 1, 0 },
  { 56, 1, 1, 0, 1, 0 },
  { 128, 1, 1, 0, 1, 0 },
  { 191, 1, 1, 0, 1, 0 },
  { 254, 1, 1, 0, 1, 0 },
  { 317, 1, 1, 0, 1, 0 },
  { 60, 1, 1, 0, 1, 0 },
  { 132, 1, 1, 0, 1, 0 },
  { 195, 1, 1, 0, 1, 0 },
  { 258, 1, 1, 0, 1, 0 },
  { 321, 1, 1, 0, 1, 0 },
  { 64, 1, 1, 0, 1, 0 },
  { 136, 1, 1, 0, 1, 0 },
  { 199, 1, 1, 0, 1, 0 },
  { 262, 1, 1, 0, 1, 0 },
  { 325, 1, 1, 0, 1, 0 },
  { 68, 1, 1, 0, 1, 0 },
  { 140, 1, 1, 0, 1, 0 },
  { 203, 1, 1, 0, 1, 0 },
  { 266, 1, 1, 0, 1, 0 },
  { 329, 1, 1, 0, 1, 0 },
};

extern const MCPhysReg NVPTXRegUnitRoots[][2] = {
  { NVPTX::VRDepot },
  { NVPTX::VRFrame },
  { NVPTX::VRFrameLocal },
  { NVPTX::ENVREG0 },
  { NVPTX::ENVREG1 },
  { NVPTX::ENVREG2 },
  { NVPTX::ENVREG3 },
  { NVPTX::ENVREG4 },
  { NVPTX::ENVREG5 },
  { NVPTX::ENVREG6 },
  { NVPTX::ENVREG7 },
  { NVPTX::ENVREG8 },
  { NVPTX::ENVREG9 },
  { NVPTX::ENVREG10 },
  { NVPTX::ENVREG11 },
  { NVPTX::ENVREG12 },
  { NVPTX::ENVREG13 },
  { NVPTX::ENVREG14 },
  { NVPTX::ENVREG15 },
  { NVPTX::ENVREG16 },
  { NVPTX::ENVREG17 },
  { NVPTX::ENVREG18 },
  { NVPTX::ENVREG19 },
  { NVPTX::ENVREG20 },
  { NVPTX::ENVREG21 },
  { NVPTX::ENVREG22 },
  { NVPTX::ENVREG23 },
  { NVPTX::ENVREG24 },
  { NVPTX::ENVREG25 },
  { NVPTX::ENVREG26 },
  { NVPTX::ENVREG27 },
  { NVPTX::ENVREG28 },
  { NVPTX::ENVREG29 },
  { NVPTX::ENVREG30 },
  { NVPTX::ENVREG31 },
  { NVPTX::F0 },
  { NVPTX::F1 },
  { NVPTX::F2 },
  { NVPTX::F3 },
  { NVPTX::F4 },
  { NVPTX::FL0 },
  { NVPTX::FL1 },
  { NVPTX::FL2 },
  { NVPTX::FL3 },
  { NVPTX::FL4 },
  { NVPTX::P0 },
  { NVPTX::P1 },
  { NVPTX::P2 },
  { NVPTX::P3 },
  { NVPTX::P4 },
  { NVPTX::R0 },
  { NVPTX::R1 },
  { NVPTX::R2 },
  { NVPTX::R3 },
  { NVPTX::R4 },
  { NVPTX::RL0 },
  { NVPTX::RL1 },
  { NVPTX::RL2 },
  { NVPTX::RL3 },
  { NVPTX::RL4 },
  { NVPTX::RS0 },
  { NVPTX::RS1 },
  { NVPTX::RS2 },
  { NVPTX::RS3 },
  { NVPTX::RS4 },
  { NVPTX::da0 },
  { NVPTX::da1 },
  { NVPTX::da2 },
  { NVPTX::da3 },
  { NVPTX::da4 },
  { NVPTX::fa0 },
  { NVPTX::fa1 },
  { NVPTX::fa2 },
  { NVPTX::fa3 },
  { NVPTX::fa4 },
  { NVPTX::ia0 },
  { NVPTX::ia1 },
  { NVPTX::ia2 },
  { NVPTX::ia3 },
  { NVPTX::ia4 },
  { NVPTX::la0 },
  { NVPTX::la1 },
  { NVPTX::la2 },
  { NVPTX::la3 },
  { NVPTX::la4 },
};

namespace {     // Register classes...
  // Int1Regs Register Class...
  const MCPhysReg Int1Regs[] = {
    NVPTX::P0, NVPTX::P1, NVPTX::P2, NVPTX::P3, NVPTX::P4, 
  };

  // Int1Regs Bit set.
  const uint8_t Int1RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, 
  };

  // Int16Regs Register Class...
  const MCPhysReg Int16Regs[] = {
    NVPTX::RS0, NVPTX::RS1, NVPTX::RS2, NVPTX::RS3, NVPTX::RS4, 
  };

  // Int16Regs Bit set.
  const uint8_t Int16RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 
  };

  // SpecialRegs Register Class...
  const MCPhysReg SpecialRegs[] = {
    NVPTX::VRFrame, NVPTX::VRFrameLocal, NVPTX::VRDepot, NVPTX::ENVREG0, NVPTX::ENVREG1, NVPTX::ENVREG2, NVPTX::ENVREG3, NVPTX::ENVREG4, NVPTX::ENVREG5, NVPTX::ENVREG6, NVPTX::ENVREG7, NVPTX::ENVREG8, NVPTX::ENVREG9, NVPTX::ENVREG10, NVPTX::ENVREG11, NVPTX::ENVREG12, NVPTX::ENVREG13, NVPTX::ENVREG14, NVPTX::ENVREG15, NVPTX::ENVREG16, NVPTX::ENVREG17, NVPTX::ENVREG18, NVPTX::ENVREG19, NVPTX::ENVREG20, NVPTX::ENVREG21, NVPTX::ENVREG22, NVPTX::ENVREG23, NVPTX::ENVREG24, NVPTX::ENVREG25, NVPTX::ENVREG26, NVPTX::ENVREG27, NVPTX::ENVREG28, NVPTX::ENVREG29, NVPTX::ENVREG30, NVPTX::ENVREG31, 
  };

  // SpecialRegs Bit set.
  const uint8_t SpecialRegsBits[] = {
    0xfe, 0xff, 0xff, 0xff, 0x0f, 
  };

  // Float32ArgRegs Register Class...
  const MCPhysReg Float32ArgRegs[] = {
    NVPTX::fa0, NVPTX::fa1, NVPTX::fa2, NVPTX::fa3, NVPTX::fa4, 
  };

  // Float32ArgRegs Bit set.
  const uint8_t Float32ArgRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0f, 
  };

  // Float32Regs Register Class...
  const MCPhysReg Float32Regs[] = {
    NVPTX::F0, NVPTX::F1, NVPTX::F2, NVPTX::F3, NVPTX::F4, 
  };

  // Float32Regs Bit set.
  const uint8_t Float32RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 
  };

  // Int32ArgRegs Register Class...
  const MCPhysReg Int32ArgRegs[] = {
    NVPTX::ia0, NVPTX::ia1, NVPTX::ia2, NVPTX::ia3, NVPTX::ia4, 
  };

  // Int32ArgRegs Bit set.
  const uint8_t Int32ArgRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01, 
  };

  // Int32Regs Register Class...
  const MCPhysReg Int32Regs[] = {
    NVPTX::R0, NVPTX::R1, NVPTX::R2, NVPTX::R3, NVPTX::R4, 
  };

  // Int32Regs Bit set.
  const uint8_t Int32RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 
  };

  // Float64ArgRegs Register Class...
  const MCPhysReg Float64ArgRegs[] = {
    NVPTX::da0, NVPTX::da1, NVPTX::da2, NVPTX::da3, NVPTX::da4, 
  };

  // Float64ArgRegs Bit set.
  const uint8_t Float64ArgRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 
  };

  // Float64Regs Register Class...
  const MCPhysReg Float64Regs[] = {
    NVPTX::FL0, NVPTX::FL1, NVPTX::FL2, NVPTX::FL3, NVPTX::FL4, 
  };

  // Float64Regs Bit set.
  const uint8_t Float64RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 
  };

  // Int64ArgRegs Register Class...
  const MCPhysReg Int64ArgRegs[] = {
    NVPTX::la0, NVPTX::la1, NVPTX::la2, NVPTX::la3, NVPTX::la4, 
  };

  // Int64ArgRegs Bit set.
  const uint8_t Int64ArgRegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 
  };

  // Int64Regs Register Class...
  const MCPhysReg Int64Regs[] = {
    NVPTX::RL0, NVPTX::RL1, NVPTX::RL2, NVPTX::RL3, NVPTX::RL4, 
  };

  // Int64Regs Bit set.
  const uint8_t Int64RegsBits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 
  };

}

extern const char NVPTXRegClassStrings[] = {
  /* 0 */ 'I', 'n', 't', '1', 'R', 'e', 'g', 's', 0,
  /* 9 */ 'F', 'l', 'o', 'a', 't', '3', '2', 'R', 'e', 'g', 's', 0,
  /* 21 */ 'I', 'n', 't', '3', '2', 'R', 'e', 'g', 's', 0,
  /* 31 */ 'F', 'l', 'o', 'a', 't', '6', '4', 'R', 'e', 'g', 's', 0,
  /* 43 */ 'I', 'n', 't', '6', '4', 'R', 'e', 'g', 's', 0,
  /* 53 */ 'I', 'n', 't', '1', '6', 'R', 'e', 'g', 's', 0,
  /* 63 */ 'F', 'l', 'o', 'a', 't', '3', '2', 'A', 'r', 'g', 'R', 'e', 'g', 's', 0,
  /* 78 */ 'I', 'n', 't', '3', '2', 'A', 'r', 'g', 'R', 'e', 'g', 's', 0,
  /* 91 */ 'F', 'l', 'o', 'a', 't', '6', '4', 'A', 'r', 'g', 'R', 'e', 'g', 's', 0,
  /* 106 */ 'I', 'n', 't', '6', '4', 'A', 'r', 'g', 'R', 'e', 'g', 's', 0,
  /* 119 */ 'S', 'p', 'e', 'c', 'i', 'a', 'l', 'R', 'e', 'g', 's', 0,
};

extern const MCRegisterClass NVPTXMCRegisterClasses[] = {
  { Int1Regs, Int1RegsBits, 0, 5, sizeof(Int1RegsBits), NVPTX::Int1RegsRegClassID, 0, 1, 1, 1 },
  { Int16Regs, Int16RegsBits, 53, 5, sizeof(Int16RegsBits), NVPTX::Int16RegsRegClassID, 2, 2, 1, 1 },
  { SpecialRegs, SpecialRegsBits, 119, 35, sizeof(SpecialRegsBits), NVPTX::SpecialRegsRegClassID, 4, 4, 1, 1 },
  { Float32ArgRegs, Float32ArgRegsBits, 63, 5, sizeof(Float32ArgRegsBits), NVPTX::Float32ArgRegsRegClassID, 4, 4, 1, 1 },
  { Float32Regs, Float32RegsBits, 9, 5, sizeof(Float32RegsBits), NVPTX::Float32RegsRegClassID, 4, 4, 1, 1 },
  { Int32ArgRegs, Int32ArgRegsBits, 78, 5, sizeof(Int32ArgRegsBits), NVPTX::Int32ArgRegsRegClassID, 4, 4, 1, 1 },
  { Int32Regs, Int32RegsBits, 21, 5, sizeof(Int32RegsBits), NVPTX::Int32RegsRegClassID, 4, 4, 1, 1 },
  { Float64ArgRegs, Float64ArgRegsBits, 91, 5, sizeof(Float64ArgRegsBits), NVPTX::Float64ArgRegsRegClassID, 8, 8, 1, 1 },
  { Float64Regs, Float64RegsBits, 31, 5, sizeof(Float64RegsBits), NVPTX::Float64RegsRegClassID, 8, 8, 1, 1 },
  { Int64ArgRegs, Int64ArgRegsBits, 106, 5, sizeof(Int64ArgRegsBits), NVPTX::Int64ArgRegsRegClassID, 8, 8, 1, 1 },
  { Int64Regs, Int64RegsBits, 43, 5, sizeof(Int64RegsBits), NVPTX::Int64RegsRegClassID, 8, 8, 1, 1 },
};

extern const uint16_t NVPTXRegEncodingTable[] = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
};
static inline void InitNVPTXMCRegisterInfo(MCRegisterInfo *RI, unsigned RA, unsigned DwarfFlavour = 0, unsigned EHFlavour = 0, unsigned PC = 0) {
  RI->InitMCRegisterInfo(NVPTXRegDesc, 86, RA, PC, NVPTXMCRegisterClasses, 11, NVPTXRegUnitRoots, 85, NVPTXRegDiffLists, NVPTXLaneMaskLists, NVPTXRegStrings, NVPTXRegClassStrings, NVPTXSubRegIdxLists, 1,
NVPTXSubRegIdxRanges, NVPTXRegEncodingTable);

}

} // End llvm namespace
#endif // GET_REGINFO_MC_DESC

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Register Information Header Fragment                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_HEADER
#undef GET_REGINFO_HEADER
#include "llvm/Target/TargetRegisterInfo.h"

namespace llvm {

class NVPTXFrameLowering;

struct NVPTXGenRegisterInfo : public TargetRegisterInfo {
  explicit NVPTXGenRegisterInfo(unsigned RA, unsigned D = 0, unsigned E = 0, unsigned PC = 0);
  const RegClassWeight &getRegClassWeight(const TargetRegisterClass *RC) const override;
  unsigned getRegUnitWeight(unsigned RegUnit) const override;
  unsigned getNumRegPressureSets() const override;
  const char *getRegPressureSetName(unsigned Idx) const override;
  unsigned getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const override;
  const int *getRegClassPressureSets(const TargetRegisterClass *RC) const override;
  const int *getRegUnitPressureSets(unsigned RegUnit) const override;
  ArrayRef<const char *> getRegMaskNames() const override;
  ArrayRef<const uint32_t *> getRegMasks() const override;
  /// Devirtualized TargetFrameLowering.
  static const NVPTXFrameLowering *getFrameLowering(
      const MachineFunction &MF);
};

namespace NVPTX { // Register classes
  extern const TargetRegisterClass Int1RegsRegClass;
  extern const TargetRegisterClass Int16RegsRegClass;
  extern const TargetRegisterClass SpecialRegsRegClass;
  extern const TargetRegisterClass Float32ArgRegsRegClass;
  extern const TargetRegisterClass Float32RegsRegClass;
  extern const TargetRegisterClass Int32ArgRegsRegClass;
  extern const TargetRegisterClass Int32RegsRegClass;
  extern const TargetRegisterClass Float64ArgRegsRegClass;
  extern const TargetRegisterClass Float64RegsRegClass;
  extern const TargetRegisterClass Int64ArgRegsRegClass;
  extern const TargetRegisterClass Int64RegsRegClass;
} // end of namespace NVPTX

} // End llvm namespace
#endif // GET_REGINFO_HEADER

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Register and Register Classes Information                           *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_REGINFO_TARGET_DESC
#undef GET_REGINFO_TARGET_DESC
namespace llvm {

extern const MCRegisterClass NVPTXMCRegisterClasses[];

static const MVT::SimpleValueType VTLists[] = {
  /* 0 */ MVT::i1, MVT::Other,
  /* 2 */ MVT::i16, MVT::Other,
  /* 4 */ MVT::i32, MVT::Other,
  /* 6 */ MVT::i64, MVT::Other,
  /* 8 */ MVT::f32, MVT::Other,
  /* 10 */ MVT::f64, MVT::Other,
};

static const char *const SubRegIndexNameTable[] = { "" };


static const unsigned SubRegIndexLaneMaskTable[] = {
  ~0u,
 };



static const TargetRegisterClass *const NullRegClasses[] = { nullptr };

static const uint32_t Int1RegsSubClassMask[] = {
  0x00000001, 
};

static const uint32_t Int16RegsSubClassMask[] = {
  0x00000002, 
};

static const uint32_t SpecialRegsSubClassMask[] = {
  0x00000004, 
};

static const uint32_t Float32ArgRegsSubClassMask[] = {
  0x00000008, 
};

static const uint32_t Float32RegsSubClassMask[] = {
  0x00000010, 
};

static const uint32_t Int32ArgRegsSubClassMask[] = {
  0x00000020, 
};

static const uint32_t Int32RegsSubClassMask[] = {
  0x00000040, 
};

static const uint32_t Float64ArgRegsSubClassMask[] = {
  0x00000080, 
};

static const uint32_t Float64RegsSubClassMask[] = {
  0x00000100, 
};

static const uint32_t Int64ArgRegsSubClassMask[] = {
  0x00000200, 
};

static const uint32_t Int64RegsSubClassMask[] = {
  0x00000400, 
};

static const uint16_t SuperRegIdxSeqs[] = {
  /* 0 */ 0,
};


namespace NVPTX {   // Register class instances
  extern const TargetRegisterClass Int1RegsRegClass = {
    &NVPTXMCRegisterClasses[Int1RegsRegClassID],
    VTLists + 0,
    Int1RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int16RegsRegClass = {
    &NVPTXMCRegisterClasses[Int16RegsRegClassID],
    VTLists + 2,
    Int16RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass SpecialRegsRegClass = {
    &NVPTXMCRegisterClasses[SpecialRegsRegClassID],
    VTLists + 4,
    SpecialRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float32ArgRegsRegClass = {
    &NVPTXMCRegisterClasses[Float32ArgRegsRegClassID],
    VTLists + 8,
    Float32ArgRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float32RegsRegClass = {
    &NVPTXMCRegisterClasses[Float32RegsRegClassID],
    VTLists + 8,
    Float32RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int32ArgRegsRegClass = {
    &NVPTXMCRegisterClasses[Int32ArgRegsRegClassID],
    VTLists + 4,
    Int32ArgRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int32RegsRegClass = {
    &NVPTXMCRegisterClasses[Int32RegsRegClassID],
    VTLists + 4,
    Int32RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float64ArgRegsRegClass = {
    &NVPTXMCRegisterClasses[Float64ArgRegsRegClassID],
    VTLists + 10,
    Float64ArgRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Float64RegsRegClass = {
    &NVPTXMCRegisterClasses[Float64RegsRegClassID],
    VTLists + 10,
    Float64RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int64ArgRegsRegClass = {
    &NVPTXMCRegisterClasses[Int64ArgRegsRegClassID],
    VTLists + 6,
    Int64ArgRegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

  extern const TargetRegisterClass Int64RegsRegClass = {
    &NVPTXMCRegisterClasses[Int64RegsRegClassID],
    VTLists + 6,
    Int64RegsSubClassMask,
    SuperRegIdxSeqs + 0,
    0xffffffff,
    0,
    false, /* HasDisjunctSubRegs */
    NullRegClasses,
    nullptr
  };

}

namespace {
  const TargetRegisterClass* const RegisterClasses[] = {
    &NVPTX::Int1RegsRegClass,
    &NVPTX::Int16RegsRegClass,
    &NVPTX::SpecialRegsRegClass,
    &NVPTX::Float32ArgRegsRegClass,
    &NVPTX::Float32RegsRegClass,
    &NVPTX::Int32ArgRegsRegClass,
    &NVPTX::Int32RegsRegClass,
    &NVPTX::Float64ArgRegsRegClass,
    &NVPTX::Float64RegsRegClass,
    &NVPTX::Int64ArgRegsRegClass,
    &NVPTX::Int64RegsRegClass,
  };
}

static const TargetRegisterInfoDesc NVPTXRegInfoDesc[] = { // Extra Descriptors
  { 0, 0 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
  { 0, 1 },
};
/// Get the weight in units of pressure for this register class.
const RegClassWeight &NVPTXGenRegisterInfo::
getRegClassWeight(const TargetRegisterClass *RC) const {
  static const RegClassWeight RCWeightTable[] = {
    {1, 5},  	// Int1Regs
    {1, 5},  	// Int16Regs
    {1, 35},  	// SpecialRegs
    {1, 5},  	// Float32ArgRegs
    {1, 5},  	// Float32Regs
    {1, 5},  	// Int32ArgRegs
    {1, 5},  	// Int32Regs
    {1, 5},  	// Float64ArgRegs
    {1, 5},  	// Float64Regs
    {1, 5},  	// Int64ArgRegs
    {1, 5},  	// Int64Regs
  };
  return RCWeightTable[RC->getID()];
}

/// Get the weight in units of pressure for this register unit.
unsigned NVPTXGenRegisterInfo::
getRegUnitWeight(unsigned RegUnit) const {
  assert(RegUnit < 85 && "invalid register unit");
  // All register units have unit weight.
  return 1;
}


// Get the number of dimensions of register pressure.
unsigned NVPTXGenRegisterInfo::getNumRegPressureSets() const {
  return 11;
}

// Get the name of this register unit pressure set.
const char *NVPTXGenRegisterInfo::
getRegPressureSetName(unsigned Idx) const {
  static const char *const PressureNameTable[] = {
    "Int1Regs",
    "Int16Regs",
    "Float32ArgRegs",
    "Float32Regs",
    "Int32ArgRegs",
    "Int32Regs",
    "Float64ArgRegs",
    "Float64Regs",
    "Int64ArgRegs",
    "Int64Regs",
    "SpecialRegs",
  };
  return PressureNameTable[Idx];
}

// Get the register unit pressure limit for this dimension.
// This limit must be adjusted dynamically for reserved registers.
unsigned NVPTXGenRegisterInfo::
getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const {
  static const uint8_t PressureLimitTable[] = {
    5,  	// 0: Int1Regs
    5,  	// 1: Int16Regs
    5,  	// 2: Float32ArgRegs
    5,  	// 3: Float32Regs
    5,  	// 4: Int32ArgRegs
    5,  	// 5: Int32Regs
    5,  	// 6: Float64ArgRegs
    5,  	// 7: Float64Regs
    5,  	// 8: Int64ArgRegs
    5,  	// 9: Int64Regs
    35,  	// 10: SpecialRegs
  };
  return PressureLimitTable[Idx];
}

/// Table of pressure sets per register class or unit.
static const int RCSetsTable[] = {
  /* 0 */ 0, -1,
  /* 2 */ 1, -1,
  /* 4 */ 2, -1,
  /* 6 */ 3, -1,
  /* 8 */ 4, -1,
  /* 10 */ 5, -1,
  /* 12 */ 6, -1,
  /* 14 */ 7, -1,
  /* 16 */ 8, -1,
  /* 18 */ 9, -1,
  /* 20 */ 10, -1,
};

/// Get the dimensions of register pressure impacted by this register class.
/// Returns a -1 terminated array of pressure set IDs
const int* NVPTXGenRegisterInfo::
getRegClassPressureSets(const TargetRegisterClass *RC) const {
  static const uint8_t RCSetStartTable[] = {
    0,2,20,4,6,8,10,12,14,16,18,};
  return &RCSetsTable[RCSetStartTable[RC->getID()]];
}

/// Get the dimensions of register pressure impacted by this register unit.
/// Returns a -1 terminated array of pressure set IDs
const int* NVPTXGenRegisterInfo::
getRegUnitPressureSets(unsigned RegUnit) const {
  assert(RegUnit < 85 && "invalid register unit");
  static const uint8_t RUSetStartTable[] = {
    20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,6,6,6,6,6,14,14,14,14,14,0,0,0,0,0,10,10,10,10,10,18,18,18,18,18,2,2,2,2,2,12,12,12,12,12,4,4,4,4,4,8,8,8,8,8,16,16,16,16,16,};
  return &RCSetsTable[RUSetStartTable[RegUnit]];
}

extern const MCRegisterDesc NVPTXRegDesc[];
extern const MCPhysReg NVPTXRegDiffLists[];
extern const unsigned NVPTXLaneMaskLists[];
extern const char NVPTXRegStrings[];
extern const char NVPTXRegClassStrings[];
extern const MCPhysReg NVPTXRegUnitRoots[][2];
extern const uint16_t NVPTXSubRegIdxLists[];
extern const MCRegisterInfo::SubRegCoveredBits NVPTXSubRegIdxRanges[];
extern const uint16_t NVPTXRegEncodingTable[];
NVPTXGenRegisterInfo::
NVPTXGenRegisterInfo(unsigned RA, unsigned DwarfFlavour, unsigned EHFlavour, unsigned PC)
  : TargetRegisterInfo(NVPTXRegInfoDesc, RegisterClasses, RegisterClasses+11,
             SubRegIndexNameTable, SubRegIndexLaneMaskTable, 0xffffffff) {
  InitMCRegisterInfo(NVPTXRegDesc, 86, RA, PC,
                     NVPTXMCRegisterClasses, 11,
                     NVPTXRegUnitRoots,
                     85,
                     NVPTXRegDiffLists,
                     NVPTXLaneMaskLists,
                     NVPTXRegStrings,
                     NVPTXRegClassStrings,
                     NVPTXSubRegIdxLists,
                     1,
                     NVPTXSubRegIdxRanges,
                     NVPTXRegEncodingTable);

}



ArrayRef<const uint32_t *> NVPTXGenRegisterInfo::getRegMasks() const {
  return None;
}

ArrayRef<const char *> NVPTXGenRegisterInfo::getRegMaskNames() const {
  return None;
}

const NVPTXFrameLowering *
NVPTXGenRegisterInfo::getFrameLowering(const MachineFunction &MF) {
  return static_cast<const NVPTXFrameLowering *>(
      MF.getSubtarget().getFrameLowering());
}

} // End llvm namespace
#endif // GET_REGINFO_TARGET_DESC

