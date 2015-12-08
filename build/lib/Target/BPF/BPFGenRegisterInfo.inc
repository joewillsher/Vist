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
extern const MCRegisterClass BPFMCRegisterClasses[];

namespace BPF {
enum {
  NoRegister,
  R0 = 1,
  R1 = 2,
  R2 = 3,
  R3 = 4,
  R4 = 5,
  R5 = 6,
  R6 = 7,
  R7 = 8,
  R8 = 9,
  R9 = 10,
  R10 = 11,
  R11 = 12,
  NUM_TARGET_REGS 	// 13
};
}

// Register classes
namespace BPF {
enum {
  GPRRegClassID = 0,

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

extern const MCPhysReg BPFRegDiffLists[] = {
  /* 0 */ 65535, 0,
};

extern const unsigned BPFLaneMaskLists[] = {
  /* 0 */ 0x00000000, ~0u,
};

extern const uint16_t BPFSubRegIdxLists[] = {
  /* 0 */ 0,
};

extern const MCRegisterInfo::SubRegCoveredBits BPFSubRegIdxRanges[] = {
  { 65535, 65535 },
};

extern const char BPFRegStrings[] = {
  /* 0 */ 'R', '1', '0', 0,
  /* 4 */ 'R', '0', 0,
  /* 7 */ 'R', '1', '1', 0,
  /* 11 */ 'R', '1', 0,
  /* 14 */ 'R', '2', 0,
  /* 17 */ 'R', '3', 0,
  /* 20 */ 'R', '4', 0,
  /* 23 */ 'R', '5', 0,
  /* 26 */ 'R', '6', 0,
  /* 29 */ 'R', '7', 0,
  /* 32 */ 'R', '8', 0,
  /* 35 */ 'R', '9', 0,
};

extern const MCRegisterDesc BPFRegDesc[] = { // Descriptors
  { 3, 0, 0, 0, 0, 0 },
  { 4, 1, 1, 0, 1, 0 },
  { 11, 1, 1, 0, 1, 0 },
  { 14, 1, 1, 0, 1, 0 },
  { 17, 1, 1, 0, 1, 0 },
  { 20, 1, 1, 0, 1, 0 },
  { 23, 1, 1, 0, 1, 0 },
  { 26, 1, 1, 0, 1, 0 },
  { 29, 1, 1, 0, 1, 0 },
  { 32, 1, 1, 0, 1, 0 },
  { 35, 1, 1, 0, 1, 0 },
  { 0, 1, 1, 0, 1, 0 },
  { 7, 1, 1, 0, 1, 0 },
};

extern const MCPhysReg BPFRegUnitRoots[][2] = {
  { BPF::R0 },
  { BPF::R1 },
  { BPF::R2 },
  { BPF::R3 },
  { BPF::R4 },
  { BPF::R5 },
  { BPF::R6 },
  { BPF::R7 },
  { BPF::R8 },
  { BPF::R9 },
  { BPF::R10 },
  { BPF::R11 },
};

namespace {     // Register classes...
  // GPR Register Class...
  const MCPhysReg GPR[] = {
    BPF::R1, BPF::R2, BPF::R3, BPF::R4, BPF::R5, BPF::R6, BPF::R7, BPF::R8, BPF::R9, BPF::R0, BPF::R11, BPF::R10, 
  };

  // GPR Bit set.
  const uint8_t GPRBits[] = {
    0xfe, 0x1f, 
  };

}

extern const char BPFRegClassStrings[] = {
  /* 0 */ 'G', 'P', 'R', 0,
};

extern const MCRegisterClass BPFMCRegisterClasses[] = {
  { GPR, GPRBits, 0, 12, sizeof(GPRBits), BPF::GPRRegClassID, 8, 8, 1, 1 },
};

// BPF Dwarf<->LLVM register mappings.
extern const MCRegisterInfo::DwarfLLVMRegPair BPFDwarfFlavour0Dwarf2L[] = {
  { 0U, BPF::R0 },
  { 1U, BPF::R1 },
  { 2U, BPF::R2 },
  { 3U, BPF::R3 },
  { 4U, BPF::R4 },
  { 5U, BPF::R5 },
  { 6U, BPF::R6 },
  { 7U, BPF::R7 },
  { 8U, BPF::R8 },
  { 9U, BPF::R9 },
  { 10U, BPF::R10 },
  { 11U, BPF::R11 },
};
extern const unsigned BPFDwarfFlavour0Dwarf2LSize = array_lengthof(BPFDwarfFlavour0Dwarf2L);

extern const MCRegisterInfo::DwarfLLVMRegPair BPFEHFlavour0Dwarf2L[] = {
  { 0U, BPF::R0 },
  { 1U, BPF::R1 },
  { 2U, BPF::R2 },
  { 3U, BPF::R3 },
  { 4U, BPF::R4 },
  { 5U, BPF::R5 },
  { 6U, BPF::R6 },
  { 7U, BPF::R7 },
  { 8U, BPF::R8 },
  { 9U, BPF::R9 },
  { 10U, BPF::R10 },
  { 11U, BPF::R11 },
};
extern const unsigned BPFEHFlavour0Dwarf2LSize = array_lengthof(BPFEHFlavour0Dwarf2L);

extern const MCRegisterInfo::DwarfLLVMRegPair BPFDwarfFlavour0L2Dwarf[] = {
  { BPF::R0, 0U },
  { BPF::R1, 1U },
  { BPF::R2, 2U },
  { BPF::R3, 3U },
  { BPF::R4, 4U },
  { BPF::R5, 5U },
  { BPF::R6, 6U },
  { BPF::R7, 7U },
  { BPF::R8, 8U },
  { BPF::R9, 9U },
  { BPF::R10, 10U },
  { BPF::R11, 11U },
};
extern const unsigned BPFDwarfFlavour0L2DwarfSize = array_lengthof(BPFDwarfFlavour0L2Dwarf);

extern const MCRegisterInfo::DwarfLLVMRegPair BPFEHFlavour0L2Dwarf[] = {
  { BPF::R0, 0U },
  { BPF::R1, 1U },
  { BPF::R2, 2U },
  { BPF::R3, 3U },
  { BPF::R4, 4U },
  { BPF::R5, 5U },
  { BPF::R6, 6U },
  { BPF::R7, 7U },
  { BPF::R8, 8U },
  { BPF::R9, 9U },
  { BPF::R10, 10U },
  { BPF::R11, 11U },
};
extern const unsigned BPFEHFlavour0L2DwarfSize = array_lengthof(BPFEHFlavour0L2Dwarf);

extern const uint16_t BPFRegEncodingTable[] = {
  0,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10,
  11,
};
static inline void InitBPFMCRegisterInfo(MCRegisterInfo *RI, unsigned RA, unsigned DwarfFlavour = 0, unsigned EHFlavour = 0, unsigned PC = 0) {
  RI->InitMCRegisterInfo(BPFRegDesc, 13, RA, PC, BPFMCRegisterClasses, 1, BPFRegUnitRoots, 12, BPFRegDiffLists, BPFLaneMaskLists, BPFRegStrings, BPFRegClassStrings, BPFSubRegIdxLists, 1,
BPFSubRegIdxRanges, BPFRegEncodingTable);

  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapDwarfRegsToLLVMRegs(BPFDwarfFlavour0Dwarf2L, BPFDwarfFlavour0Dwarf2LSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapDwarfRegsToLLVMRegs(BPFEHFlavour0Dwarf2L, BPFEHFlavour0Dwarf2LSize, true);
    break;
  }
  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapLLVMRegsToDwarfRegs(BPFDwarfFlavour0L2Dwarf, BPFDwarfFlavour0L2DwarfSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    RI->mapLLVMRegsToDwarfRegs(BPFEHFlavour0L2Dwarf, BPFEHFlavour0L2DwarfSize, true);
    break;
  }
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

class BPFFrameLowering;

struct BPFGenRegisterInfo : public TargetRegisterInfo {
  explicit BPFGenRegisterInfo(unsigned RA, unsigned D = 0, unsigned E = 0, unsigned PC = 0);
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
  static const BPFFrameLowering *getFrameLowering(
      const MachineFunction &MF);
};

namespace BPF { // Register classes
  extern const TargetRegisterClass GPRRegClass;
} // end of namespace BPF

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

extern const MCRegisterClass BPFMCRegisterClasses[];

static const MVT::SimpleValueType VTLists[] = {
  /* 0 */ MVT::i64, MVT::Other,
};

static const char *const SubRegIndexNameTable[] = { "" };


static const unsigned SubRegIndexLaneMaskTable[] = {
  ~0u,
 };



static const TargetRegisterClass *const NullRegClasses[] = { nullptr };

static const uint32_t GPRSubClassMask[] = {
  0x00000001, 
};

static const uint16_t SuperRegIdxSeqs[] = {
  /* 0 */ 0,
};


namespace BPF {   // Register class instances
  extern const TargetRegisterClass GPRRegClass = {
    &BPFMCRegisterClasses[GPRRegClassID],
    VTLists + 0,
    GPRSubClassMask,
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
    &BPF::GPRRegClass,
  };
}

static const TargetRegisterInfoDesc BPFRegInfoDesc[] = { // Extra Descriptors
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
};
/// Get the weight in units of pressure for this register class.
const RegClassWeight &BPFGenRegisterInfo::
getRegClassWeight(const TargetRegisterClass *RC) const {
  static const RegClassWeight RCWeightTable[] = {
    {1, 12},  	// GPR
  };
  return RCWeightTable[RC->getID()];
}

/// Get the weight in units of pressure for this register unit.
unsigned BPFGenRegisterInfo::
getRegUnitWeight(unsigned RegUnit) const {
  assert(RegUnit < 12 && "invalid register unit");
  // All register units have unit weight.
  return 1;
}


// Get the number of dimensions of register pressure.
unsigned BPFGenRegisterInfo::getNumRegPressureSets() const {
  return 1;
}

// Get the name of this register unit pressure set.
const char *BPFGenRegisterInfo::
getRegPressureSetName(unsigned Idx) const {
  static const char *const PressureNameTable[] = {
    "GPR",
  };
  return PressureNameTable[Idx];
}

// Get the register unit pressure limit for this dimension.
// This limit must be adjusted dynamically for reserved registers.
unsigned BPFGenRegisterInfo::
getRegPressureSetLimit(const MachineFunction &MF, unsigned Idx) const {
  static const uint8_t PressureLimitTable[] = {
    12,  	// 0: GPR
  };
  return PressureLimitTable[Idx];
}

/// Table of pressure sets per register class or unit.
static const int RCSetsTable[] = {
  /* 0 */ 0, -1,
};

/// Get the dimensions of register pressure impacted by this register class.
/// Returns a -1 terminated array of pressure set IDs
const int* BPFGenRegisterInfo::
getRegClassPressureSets(const TargetRegisterClass *RC) const {
  static const uint8_t RCSetStartTable[] = {
    0,};
  return &RCSetsTable[RCSetStartTable[RC->getID()]];
}

/// Get the dimensions of register pressure impacted by this register unit.
/// Returns a -1 terminated array of pressure set IDs
const int* BPFGenRegisterInfo::
getRegUnitPressureSets(unsigned RegUnit) const {
  assert(RegUnit < 12 && "invalid register unit");
  static const uint8_t RUSetStartTable[] = {
    0,0,0,0,0,0,0,0,0,0,0,0,};
  return &RCSetsTable[RUSetStartTable[RegUnit]];
}

extern const MCRegisterDesc BPFRegDesc[];
extern const MCPhysReg BPFRegDiffLists[];
extern const unsigned BPFLaneMaskLists[];
extern const char BPFRegStrings[];
extern const char BPFRegClassStrings[];
extern const MCPhysReg BPFRegUnitRoots[][2];
extern const uint16_t BPFSubRegIdxLists[];
extern const MCRegisterInfo::SubRegCoveredBits BPFSubRegIdxRanges[];
extern const uint16_t BPFRegEncodingTable[];
// BPF Dwarf<->LLVM register mappings.
extern const MCRegisterInfo::DwarfLLVMRegPair BPFDwarfFlavour0Dwarf2L[];
extern const unsigned BPFDwarfFlavour0Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair BPFEHFlavour0Dwarf2L[];
extern const unsigned BPFEHFlavour0Dwarf2LSize;

extern const MCRegisterInfo::DwarfLLVMRegPair BPFDwarfFlavour0L2Dwarf[];
extern const unsigned BPFDwarfFlavour0L2DwarfSize;

extern const MCRegisterInfo::DwarfLLVMRegPair BPFEHFlavour0L2Dwarf[];
extern const unsigned BPFEHFlavour0L2DwarfSize;

BPFGenRegisterInfo::
BPFGenRegisterInfo(unsigned RA, unsigned DwarfFlavour, unsigned EHFlavour, unsigned PC)
  : TargetRegisterInfo(BPFRegInfoDesc, RegisterClasses, RegisterClasses+1,
             SubRegIndexNameTable, SubRegIndexLaneMaskTable, 0xffffffff) {
  InitMCRegisterInfo(BPFRegDesc, 13, RA, PC,
                     BPFMCRegisterClasses, 1,
                     BPFRegUnitRoots,
                     12,
                     BPFRegDiffLists,
                     BPFLaneMaskLists,
                     BPFRegStrings,
                     BPFRegClassStrings,
                     BPFSubRegIdxLists,
                     1,
                     BPFSubRegIdxRanges,
                     BPFRegEncodingTable);

  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapDwarfRegsToLLVMRegs(BPFDwarfFlavour0Dwarf2L, BPFDwarfFlavour0Dwarf2LSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapDwarfRegsToLLVMRegs(BPFEHFlavour0Dwarf2L, BPFEHFlavour0Dwarf2LSize, true);
    break;
  }
  switch (DwarfFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapLLVMRegsToDwarfRegs(BPFDwarfFlavour0L2Dwarf, BPFDwarfFlavour0L2DwarfSize, false);
    break;
  }
  switch (EHFlavour) {
  default:
    llvm_unreachable("Unknown DWARF flavour");
  case 0:
    mapLLVMRegsToDwarfRegs(BPFEHFlavour0L2Dwarf, BPFEHFlavour0L2DwarfSize, true);
    break;
  }
}

static const MCPhysReg CSR_SaveList[] = { BPF::R6, BPF::R7, BPF::R8, BPF::R9, BPF::R10, 0 };
static const uint32_t CSR_RegMask[] = { 0x00000f80, };


ArrayRef<const uint32_t *> BPFGenRegisterInfo::getRegMasks() const {
  static const uint32_t *const Masks[] = {
    CSR_RegMask,
  };
  return makeArrayRef(Masks);
}

ArrayRef<const char *> BPFGenRegisterInfo::getRegMaskNames() const {
  static const char *const Names[] = {
    "CSR",
  };
  return makeArrayRef(Names);
}

const BPFFrameLowering *
BPFGenRegisterInfo::getFrameLowering(const MachineFunction &MF) {
  return static_cast<const BPFFrameLowering *>(
      MF.getSubtarget().getFrameLowering());
}

} // End llvm namespace
#endif // GET_REGINFO_TARGET_DESC

