/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Assembly Matcher Source Fragment                                           *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_ASSEMBLER_HEADER
#undef GET_ASSEMBLER_HEADER
  // This should be included into the middle of the declaration of
  // your subclasses implementation of MCTargetAsmParser.
  uint64_t ComputeAvailableFeatures(const FeatureBitset& FB) const;
  void convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                       const OperandVector &Operands);
  void convertToMapAndConstraints(unsigned Kind,
                           const OperandVector &Operands) override;
  bool mnemonicIsValid(StringRef Mnemonic, unsigned VariantID) override;
  unsigned MatchInstructionImpl(const OperandVector &Operands,
                                MCInst &Inst,
                                uint64_t &ErrorInfo, bool matchingInlineAsm,
                                unsigned VariantID = 0);
#endif // GET_ASSEMBLER_HEADER_INFO


#ifdef GET_OPERAND_DIAGNOSTIC_TYPES
#undef GET_OPERAND_DIAGNOSTIC_TYPES

#endif // GET_OPERAND_DIAGNOSTIC_TYPES


#ifdef GET_REGISTER_MATCHER
#undef GET_REGISTER_MATCHER

// Flags for subtarget features that participate in instruction matching.
enum SubtargetFeatureFlag : uint8_t {
  Feature_None = 0
};

#endif // GET_REGISTER_MATCHER


#ifdef GET_SUBTARGET_FEATURE_NAME
#undef GET_SUBTARGET_FEATURE_NAME

// User-level names for subtarget features that participate in
// instruction matching.
static const char *getSubtargetFeatureName(uint64_t Val) {
  return "(unknown)";
}

#endif // GET_SUBTARGET_FEATURE_NAME


#ifdef GET_MATCHER_IMPLEMENTATION
#undef GET_MATCHER_IMPLEMENTATION

static void applyMnemonicAliases(StringRef &Mnemonic, uint64_t Features, unsigned VariantID) {
  switch (VariantID) {
    case 0:
      switch (Mnemonic.size()) {
      default: break;
      case 5:	 // 1 string to match.
        if (memcmp(Mnemonic.data()+0, "cntlz", 5))
          break;
        Mnemonic = "cntlzw";	 // "cntlz"
        return;
      case 6:	 // 1 string to match.
        if (memcmp(Mnemonic.data()+0, "cntlz.", 6))
          break;
        Mnemonic = "cntlzw.";	 // "cntlz."
        return;
      }
    break;
  }
  switch (Mnemonic.size()) {
  default: break;
  case 5:	 // 1 string to match.
    if (memcmp(Mnemonic.data()+0, "cntlz", 5))
      break;
    Mnemonic = "cntlzw";	 // "cntlz"
    return;
  case 6:	 // 1 string to match.
    if (memcmp(Mnemonic.data()+0, "cntlz.", 6))
      break;
    Mnemonic = "cntlzw.";	 // "cntlz."
    return;
  }
}

namespace {
enum OperatorConversionKind {
  CVT_Done,
  CVT_Reg,
  CVT_Tied,
  CVT_95_addRegG8RCOperands,
  CVT_95_addTLSRegOperands,
  CVT_95_addRegGPRCOperands,
  CVT_95_addRegGPRCNoR0Operands,
  CVT_95_addS16ImmOperands,
  CVT_95_addU16ImmOperands,
  CVT_95_addBranchTargetOperands,
  CVT_95_addImmOperands,
  CVT_95_addRegCRBITRCOperands,
  CVT_imm_95_0,
  CVT_imm_95_8,
  CVT_imm_95_2,
  CVT_imm_95_10,
  CVT_imm_95_76,
  CVT_regCR0,
  CVT_95_addRegCRRCOperands,
  CVT_imm_95_79,
  CVT_imm_95_78,
  CVT_imm_95_4,
  CVT_imm_95_7,
  CVT_imm_95_6,
  CVT_imm_95_44,
  CVT_imm_95_47,
  CVT_imm_95_46,
  CVT_imm_95_36,
  CVT_imm_95_39,
  CVT_imm_95_38,
  CVT_imm_95_12,
  CVT_imm_95_15,
  CVT_imm_95_14,
  CVT_imm_95_68,
  CVT_imm_95_71,
  CVT_imm_95_70,
  CVT_imm_95_100,
  CVT_imm_95_103,
  CVT_imm_95_102,
  CVT_imm_95_108,
  CVT_imm_95_111,
  CVT_imm_95_110,
  CVT_imm_95_31,
  CVT_95_addRegGxRCNoR0Operands,
  CVT_95_addRegGxRCOperands,
  CVT_regR0,
  CVT_95_addRegF4RCOperands,
  CVT_95_addRegF8RCOperands,
  CVT_95_addRegVRRCOperands,
  CVT_imm_95_1,
  CVT_95_addRegVSFRCOperands,
  CVT_95_addRegVSSRCOperands,
  CVT_95_addRegVSRCOperands,
  CVT_imm_95_29,
  CVT_imm_95_280,
  CVT_imm_95_128,
  CVT_imm_95_129,
  CVT_imm_95_130,
  CVT_imm_95_131,
  CVT_imm_95_132,
  CVT_imm_95_133,
  CVT_imm_95_134,
  CVT_imm_95_135,
  CVT_imm_95_28,
  CVT_imm_95_19,
  CVT_imm_95_537,
  CVT_imm_95_539,
  CVT_imm_95_541,
  CVT_imm_95_543,
  CVT_imm_95_536,
  CVT_imm_95_538,
  CVT_imm_95_540,
  CVT_imm_95_542,
  CVT_imm_95_1018,
  CVT_imm_95_981,
  CVT_imm_95_22,
  CVT_imm_95_17,
  CVT_imm_95_18,
  CVT_imm_95_980,
  CVT_imm_95_529,
  CVT_imm_95_531,
  CVT_imm_95_533,
  CVT_imm_95_535,
  CVT_imm_95_528,
  CVT_imm_95_530,
  CVT_imm_95_532,
  CVT_imm_95_534,
  CVT_imm_95_1019,
  CVT_95_addCRBitMaskOperands,
  CVT_imm_95_48,
  CVT_imm_95_287,
  CVT_imm_95_5,
  CVT_imm_95_25,
  CVT_imm_95_512,
  CVT_imm_95_272,
  CVT_imm_95_273,
  CVT_imm_95_274,
  CVT_imm_95_275,
  CVT_imm_95_260,
  CVT_imm_95_261,
  CVT_imm_95_262,
  CVT_imm_95_263,
  CVT_imm_95_26,
  CVT_imm_95_27,
  CVT_imm_95_990,
  CVT_imm_95_991,
  CVT_imm_95_268,
  CVT_imm_95_988,
  CVT_imm_95_989,
  CVT_imm_95_269,
  CVT_imm_95_986,
  CVT_imm_95_255,
  CVT_imm_95_284,
  CVT_imm_95_285,
  CVT_95_addRegQFRCOperands,
  CVT_95_addRegQSRCOperands,
  CVT_95_addRegQBRCOperands,
  CVT_imm_95_9,
  CVT_imm_95_13,
  CVT_imm_95_20,
  CVT_imm_95_16,
  CVT_imm_95_24,
  CVT_imm_95_3,
  CVT_NUM_CONVERTERS
};

enum InstructionConversionKind {
  Convert__RegG8RC1_1__RegG8RC1_2__TLSReg1_3,
  Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3,
  Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4,
  Convert__RegGPRC1_1__RegGPRCNoR01_2__S16Imm1_3,
  Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3,
  Convert__RegGPRC1_2__RegGPRC1_3__S16Imm1_4,
  Convert__RegGPRC1_1__RegGPRCNoR01_2__S17Imm1_3,
  Convert__RegGPRC1_1__RegGPRC1_2,
  Convert__RegGPRC1_2__RegGPRC1_3,
  Convert__RegGPRC1_2__RegGPRC1_3__U16Imm1_4,
  Convert_NoOperands,
  Convert__DirectBr1_1,
  Convert__U5Imm1_1__RegCRBITRC1_2__CondBr1_3,
  Convert__U5Imm1_1__RegCRBITRC1_2__imm_95_0,
  Convert__U5Imm1_1__RegCRBITRC1_2__Imm1_3,
  Convert__CondBr1_1,
  Convert__imm_95_0__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_0__RegCRBITRC1_1__imm_95_0,
  Convert__imm_95_8__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_8__RegCRBITRC1_1__imm_95_0,
  Convert__imm_95_2__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_2__RegCRBITRC1_1__imm_95_0,
  Convert__imm_95_10__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_10__RegCRBITRC1_1__imm_95_0,
  Convert__imm_95_76__regCR0__CondBr1_1,
  Convert__imm_95_76__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_79__regCR0__CondBr1_1,
  Convert__imm_95_79__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_78__regCR0__CondBr1_1,
  Convert__imm_95_78__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_76__regCR0,
  Convert__imm_95_76__RegCRRC1_1,
  Convert__imm_95_79__regCR0,
  Convert__imm_95_79__RegCRRC1_1,
  Convert__imm_95_78__regCR0,
  Convert__imm_95_78__RegCRRC1_1,
  Convert__imm_95_4__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_7__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_6__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_4__RegCRBITRC1_1__imm_95_0,
  Convert__imm_95_7__RegCRBITRC1_1__imm_95_0,
  Convert__imm_95_6__RegCRBITRC1_1__imm_95_0,
  Convert__imm_95_4__regCR0__CondBr1_1,
  Convert__imm_95_4__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_7__regCR0__CondBr1_1,
  Convert__imm_95_7__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_6__regCR0__CondBr1_1,
  Convert__imm_95_6__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_4__regCR0,
  Convert__imm_95_4__RegCRRC1_1,
  Convert__imm_95_7__regCR0,
  Convert__imm_95_7__RegCRRC1_1,
  Convert__imm_95_6__regCR0,
  Convert__imm_95_6__RegCRRC1_1,
  Convert__imm_95_44__regCR0__CondBr1_1,
  Convert__imm_95_44__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_47__regCR0__CondBr1_1,
  Convert__imm_95_47__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_46__regCR0__CondBr1_1,
  Convert__imm_95_46__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_44__regCR0,
  Convert__imm_95_44__RegCRRC1_1,
  Convert__imm_95_47__regCR0,
  Convert__imm_95_47__RegCRRC1_1,
  Convert__imm_95_46__regCR0,
  Convert__imm_95_46__RegCRRC1_1,
  Convert__DirectBr1_1__Imm1_2,
  Convert__imm_95_36__regCR0__CondBr1_1,
  Convert__imm_95_36__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_39__regCR0__CondBr1_1,
  Convert__imm_95_39__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_38__regCR0__CondBr1_1,
  Convert__imm_95_38__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_36__regCR0,
  Convert__imm_95_36__RegCRRC1_1,
  Convert__imm_95_39__regCR0,
  Convert__imm_95_39__RegCRRC1_1,
  Convert__imm_95_38__regCR0,
  Convert__imm_95_38__RegCRRC1_1,
  Convert__imm_95_12__regCR0__CondBr1_1,
  Convert__imm_95_12__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_15__regCR0__CondBr1_1,
  Convert__imm_95_15__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_14__regCR0__CondBr1_1,
  Convert__imm_95_14__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_12__regCR0,
  Convert__imm_95_12__RegCRRC1_1,
  Convert__imm_95_15__regCR0,
  Convert__imm_95_15__RegCRRC1_1,
  Convert__imm_95_14__regCR0,
  Convert__imm_95_14__RegCRRC1_1,
  Convert__imm_95_68__regCR0__CondBr1_1,
  Convert__imm_95_68__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_71__regCR0__CondBr1_1,
  Convert__imm_95_71__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_70__regCR0__CondBr1_1,
  Convert__imm_95_70__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_68__regCR0,
  Convert__imm_95_68__RegCRRC1_1,
  Convert__imm_95_71__regCR0,
  Convert__imm_95_71__RegCRRC1_1,
  Convert__imm_95_70__regCR0,
  Convert__imm_95_70__RegCRRC1_1,
  Convert__imm_95_100__regCR0__CondBr1_1,
  Convert__imm_95_100__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_103__regCR0__CondBr1_1,
  Convert__imm_95_103__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_102__regCR0__CondBr1_1,
  Convert__imm_95_102__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_100__regCR0,
  Convert__imm_95_100__RegCRRC1_1,
  Convert__imm_95_103__regCR0,
  Convert__imm_95_103__RegCRRC1_1,
  Convert__imm_95_102__regCR0,
  Convert__imm_95_102__RegCRRC1_1,
  Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3,
  Convert__imm_95_108__regCR0__CondBr1_1,
  Convert__imm_95_108__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_111__regCR0__CondBr1_1,
  Convert__imm_95_111__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_110__regCR0__CondBr1_1,
  Convert__imm_95_110__RegCRRC1_1__CondBr1_2,
  Convert__imm_95_108__regCR0,
  Convert__imm_95_108__RegCRRC1_1,
  Convert__imm_95_111__regCR0,
  Convert__imm_95_111__RegCRRC1_1,
  Convert__imm_95_110__regCR0,
  Convert__imm_95_110__RegCRRC1_1,
  Convert__imm_95_12__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_15__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_14__RegCRBITRC1_1__CondBr1_2,
  Convert__imm_95_12__RegCRBITRC1_1__imm_95_0,
  Convert__imm_95_15__RegCRBITRC1_1__imm_95_0,
  Convert__imm_95_14__RegCRBITRC1_1__imm_95_0,
  Convert__RegG8RC1_1__RegG8RC1_2__imm_95_0__U6Imm1_3,
  Convert__RegG8RC1_2__RegG8RC1_3__imm_95_0__U6Imm1_4,
  Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4,
  Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__U6Imm1_5,
  Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4,
  Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5,
  Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0__U5Imm1_3__imm_95_31,
  Convert__RegGPRC1_2__RegGPRC1_3__imm_95_0__U5Imm1_4__imm_95_31,
  Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3,
  Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4,
  Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3,
  Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4,
  Convert__RegCRRC1_1__RegGPRC1_3__RegGPRC1_4,
  Convert__RegCRRC1_1__RegG8RC1_3__RegG8RC1_4,
  Convert__regCR0__RegG8RC1_1__RegG8RC1_2,
  Convert__RegCRRC1_1__RegG8RC1_2__RegG8RC1_3,
  Convert__regCR0__RegG8RC1_1__S16Imm1_2,
  Convert__RegCRRC1_1__RegG8RC1_2__S16Imm1_3,
  Convert__RegCRRC1_1__RegGPRC1_3__S16Imm1_4,
  Convert__RegCRRC1_1__RegG8RC1_3__S16Imm1_4,
  Convert__regCR0__RegG8RC1_1__U16Imm1_2,
  Convert__RegCRRC1_1__RegG8RC1_2__U16Imm1_3,
  Convert__RegCRRC1_1__RegGPRC1_3__U16Imm1_4,
  Convert__RegCRRC1_1__RegG8RC1_3__U16Imm1_4,
  Convert__regCR0__RegGPRC1_1__RegGPRC1_2,
  Convert__RegCRRC1_1__RegGPRC1_2__RegGPRC1_3,
  Convert__regCR0__RegGPRC1_1__U16Imm1_2,
  Convert__RegCRRC1_1__RegGPRC1_2__U16Imm1_3,
  Convert__regCR0__RegGPRC1_1__S16Imm1_2,
  Convert__RegCRRC1_1__RegGPRC1_2__S16Imm1_3,
  Convert__RegG8RC1_1__RegG8RC1_2,
  Convert__RegG8RC1_2__RegG8RC1_3,
  Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3,
  Convert__RegCRBITRC1_1__RegCRBITRC1_1__RegCRBITRC1_1,
  Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_2,
  Convert__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__U5Imm1_3__RegGxRCNoR01_1__RegGxRC1_2,
  Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_3,
  Convert__regR0__regR0,
  Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_4,
  Convert__U5Imm1_1,
  Convert__U5Imm1_3__RegGPRC1_1__RegGPRC1_2,
  Convert__RegGPRC1_1__RegGPRC1_3__U5Imm1_2,
  Convert__RegGPRC1_1__DispSPE81_2__RegGxRCNoR01_3,
  Convert__RegGPRC1_1__DispSPE21_2__RegGxRCNoR01_3,
  Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3,
  Convert__RegGPRC1_1__Imm1_2,
  Convert__RegGPRC1_1__U5Imm1_2__RegGPRC1_3,
  Convert__RegF4RC1_1__RegF4RC1_2,
  Convert__RegF4RC1_2__RegF4RC1_3,
  Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3,
  Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4,
  Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3,
  Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4,
  Convert__RegF8RC1_1__RegF8RC1_2,
  Convert__RegF8RC1_2__RegF8RC1_3,
  Convert__RegF4RC1_1__RegF8RC1_2,
  Convert__RegF4RC1_2__RegF8RC1_3,
  Convert__RegCRRC1_1__RegF4RC1_2__RegF4RC1_3,
  Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4,
  Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4__RegF8RC1_5,
  Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4,
  Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4__RegF4RC1_5,
  Convert__RegF4RC1_1__RegF8RC1_2__RegF4RC1_3__RegF4RC1_4,
  Convert__RegF4RC1_2__RegF8RC1_3__RegF4RC1_4__RegF4RC1_5,
  Convert__U4Imm1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegGPRC1_1__RegGPRCNoR01_2__RegGPRC1_3__RegCRBITRC1_4,
  Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3,
  Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegGPRC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3,
  Convert__RegGPRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegG8RC1_1__DispRIX1_2__RegGxRCNoR01_3,
  Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegG8RC1_1__imm_95_0__DispRIX1_2__RegGxRCNoR01_3,
  Convert__RegG8RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegF8RC1_1__DispRI1_2__RegGxRCNoR01_3,
  Convert__RegF8RC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3,
  Convert__RegF8RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegF4RC1_1__DispRI1_2__RegGxRCNoR01_3,
  Convert__RegF4RC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3,
  Convert__RegF4RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegF4RC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegGPRC1_1__S16Imm1_2,
  Convert__RegGPRC1_1__S17Imm1_2,
  Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__imm_95_1,
  Convert__RegVSFRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegVSSRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegVSRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__imm_95_0,
  Convert__RegCRRC1_1__RegCRRC1_2,
  Convert__RegGPRC1_1__imm_95_29,
  Convert__RegGPRC1_1__imm_95_280,
  Convert__RegGPRC1_1__U10Imm1_2__imm_95_0,
  Convert__RegGPRC1_1__imm_95_128,
  Convert__RegGPRC1_1__imm_95_129,
  Convert__RegGPRC1_1__imm_95_130,
  Convert__RegGPRC1_1__imm_95_131,
  Convert__RegGPRC1_1__imm_95_132,
  Convert__RegGPRC1_1__imm_95_133,
  Convert__RegGPRC1_1__imm_95_134,
  Convert__RegGPRC1_1__imm_95_135,
  Convert__RegGPRC1_1__imm_95_28,
  Convert__RegGPRC1_1,
  Convert__RegGPRC1_1__imm_95_19,
  Convert__RegGPRC1_1__imm_95_537,
  Convert__RegGPRC1_1__imm_95_539,
  Convert__RegGPRC1_1__imm_95_541,
  Convert__RegGPRC1_1__imm_95_543,
  Convert__RegGPRC1_1__imm_95_536,
  Convert__RegGPRC1_1__imm_95_538,
  Convert__RegGPRC1_1__imm_95_540,
  Convert__RegGPRC1_1__imm_95_542,
  Convert__RegGPRC1_1__imm_95_1018,
  Convert__RegGPRC1_1__imm_95_981,
  Convert__RegGPRC1_1__imm_95_22,
  Convert__RegGPRC1_1__imm_95_17,
  Convert__RegGPRC1_1__imm_95_18,
  Convert__RegGPRC1_1__imm_95_980,
  Convert__RegF8RC1_1,
  Convert__RegF8RC1_2,
  Convert__RegGPRC1_1__imm_95_529,
  Convert__RegGPRC1_1__imm_95_531,
  Convert__RegGPRC1_1__imm_95_533,
  Convert__RegGPRC1_1__imm_95_535,
  Convert__RegGPRC1_1__imm_95_528,
  Convert__RegGPRC1_1__imm_95_530,
  Convert__RegGPRC1_1__imm_95_532,
  Convert__RegGPRC1_1__imm_95_534,
  Convert__RegGPRC1_1__imm_95_1019,
  Convert__RegGPRC1_1__CRBitMask1_2,
  Convert__RegGPRC1_1__imm_95_48,
  Convert__RegGPRC1_1__imm_95_287,
  Convert__RegGPRC1_1__imm_95_5,
  Convert__RegGPRC1_1__imm_95_4,
  Convert__RegGPRC1_1__imm_95_25,
  Convert__RegGPRC1_1__imm_95_512,
  Convert__RegGPRC1_1__imm_95_272,
  Convert__RegGPRC1_1__imm_95_273,
  Convert__RegGPRC1_1__imm_95_274,
  Convert__RegGPRC1_1__imm_95_275,
  Convert__RegGPRC1_1__imm_95_260,
  Convert__RegGPRC1_1__imm_95_261,
  Convert__RegGPRC1_1__imm_95_262,
  Convert__RegGPRC1_1__imm_95_263,
  Convert__RegGPRC1_1__U4Imm1_2,
  Convert__RegGPRC1_1__imm_95_26,
  Convert__RegGPRC1_1__imm_95_27,
  Convert__RegGPRC1_1__imm_95_990,
  Convert__RegGPRC1_1__imm_95_991,
  Convert__RegGPRC1_1__imm_95_268,
  Convert__RegGPRC1_1__imm_95_988,
  Convert__RegGPRC1_1__imm_95_989,
  Convert__RegGPRC1_1__imm_95_269,
  Convert__RegGPRC1_1__imm_95_986,
  Convert__RegVRRC1_1,
  Convert__RegG8RC1_1__RegVSFRC1_2,
  Convert__RegGPRC1_1__RegVSFRC1_2,
  Convert__RegGPRC1_1__imm_95_1,
  Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_2,
  Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_3,
  Convert__imm_95_29__RegGPRC1_1,
  Convert__imm_95_280__RegGPRC1_1,
  Convert__imm_95_28__RegGPRC1_1,
  Convert__imm_95_255__RegG8RC1_1,
  Convert__Imm1_1__RegGPRC1_2,
  Convert__imm_95_19__RegGPRC1_1,
  Convert__imm_95_537__RegGPRC1_2,
  Convert__imm_95_539__RegGPRC1_2,
  Convert__imm_95_541__RegGPRC1_2,
  Convert__imm_95_543__RegGPRC1_2,
  Convert__imm_95_536__RegGPRC1_2,
  Convert__imm_95_538__RegGPRC1_2,
  Convert__imm_95_540__RegGPRC1_2,
  Convert__imm_95_542__RegGPRC1_2,
  Convert__imm_95_1018__RegGPRC1_1,
  Convert__RegGPRC1_2__Imm1_1,
  Convert__imm_95_981__RegGPRC1_1,
  Convert__imm_95_22__RegGPRC1_1,
  Convert__imm_95_17__RegGPRC1_1,
  Convert__imm_95_18__RegGPRC1_1,
  Convert__imm_95_980__RegGPRC1_1,
  Convert__Imm1_1__RegF8RC1_2__imm_95_0__imm_95_0,
  Convert__Imm1_2__RegF8RC1_3__imm_95_0__imm_95_0,
  Convert__Imm1_1__RegF8RC1_2__Imm1_3__Imm1_4,
  Convert__Imm1_2__RegF8RC1_3__Imm1_4__Imm1_5,
  Convert__RegCRRC1_1__Imm1_2__imm_95_0,
  Convert__RegCRRC1_2__Imm1_3__imm_95_0,
  Convert__RegCRRC1_1__Imm1_2__Imm1_3,
  Convert__RegCRRC1_2__Imm1_3__Imm1_4,
  Convert__imm_95_529__RegGPRC1_2,
  Convert__imm_95_531__RegGPRC1_2,
  Convert__imm_95_533__RegGPRC1_2,
  Convert__imm_95_535__RegGPRC1_2,
  Convert__imm_95_528__RegGPRC1_2,
  Convert__imm_95_530__RegGPRC1_2,
  Convert__imm_95_532__RegGPRC1_2,
  Convert__imm_95_534__RegGPRC1_2,
  Convert__imm_95_1019__RegGPRC1_1,
  Convert__RegGPRC1_1__imm_95_0,
  Convert__CRBitMask1_1__RegGPRC1_2,
  Convert__imm_95_48__RegGPRC1_1,
  Convert__imm_95_25__RegGPRC1_1,
  Convert__imm_95_512__RegGPRC1_1,
  Convert__imm_95_272__RegGPRC1_2,
  Convert__imm_95_273__RegGPRC1_2,
  Convert__imm_95_274__RegGPRC1_2,
  Convert__imm_95_275__RegGPRC1_2,
  Convert__imm_95_260__RegGPRC1_2,
  Convert__imm_95_261__RegGPRC1_2,
  Convert__imm_95_262__RegGPRC1_2,
  Convert__imm_95_263__RegGPRC1_2,
  Convert__imm_95_272__RegGPRC1_1,
  Convert__imm_95_273__RegGPRC1_1,
  Convert__imm_95_274__RegGPRC1_1,
  Convert__imm_95_275__RegGPRC1_1,
  Convert__imm_95_260__RegGPRC1_1,
  Convert__imm_95_261__RegGPRC1_1,
  Convert__imm_95_262__RegGPRC1_1,
  Convert__imm_95_263__RegGPRC1_1,
  Convert__RegGPRC1_2__U4Imm1_1,
  Convert__imm_95_26__RegGPRC1_1,
  Convert__imm_95_27__RegGPRC1_1,
  Convert__imm_95_990__RegGPRC1_1,
  Convert__imm_95_991__RegGPRC1_1,
  Convert__imm_95_988__RegGPRC1_1,
  Convert__imm_95_284__RegGPRC1_1,
  Convert__imm_95_989__RegGPRC1_1,
  Convert__imm_95_285__RegGPRC1_1,
  Convert__imm_95_986__RegGPRC1_1,
  Convert__RegVSFRC1_1__RegG8RC1_2,
  Convert__RegVSFRC1_1__RegGPRC1_2,
  Convert__imm_95_1__RegGPRC1_1,
  Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3,
  Convert__imm_95_2,
  Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3__U2Imm1_4,
  Convert__RegQFRC1_1__RegQFRC1_2__U2Imm1_3,
  Convert__RegQFRC1_1__RegQFRC1_2,
  Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3,
  Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_1,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_4,
  Convert__RegQBRC1_1__RegQBRC1_1__RegQBRC1_1__imm_95_0,
  Convert__RegQBRC1_1__RegQFRC1_2__RegQFRC1_3,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_2__imm_95_5,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_9,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__U12Imm1_4,
  Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3,
  Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_4__RegQSRC1_3,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_14,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_8,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_2__imm_95_10,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_7,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_13,
  Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3__RegQFRC1_4,
  Convert__RegQSRC1_1__RegQFRC1_2,
  Convert__RegQFRC1_1__RegQBRC1_2__RegQFRC1_4__RegQFRC1_3,
  Convert__RegQBRC1_1__RegQBRC1_1__RegQBRC1_1__imm_95_15,
  Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_6,
  Convert__RegQFRC1_1__U12Imm1_2,
  Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegQFRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegQSRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__imm_95_0__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__imm_95_0__RegQSRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__U1Imm1_1,
  Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__U6Imm1_4,
  Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4__U6Imm1_5,
  Convert__RegG8RC1_1__Tie0__RegG8RC1_2__U6Imm1_3__U6Imm1_4,
  Convert__RegG8RC1_2__Tie0__RegG8RC1_3__U6Imm1_4__U6Imm1_5,
  Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4,
  Convert__RegG8RC1_2__RegG8RC1_3__U5Imm1_4__Imm1_5,
  Convert__RegGPRC1_1__Tie0__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5,
  Convert__RegGPRC1_2__Tie0__RegGPRC1_3__U5Imm1_4__U5Imm1_5__U5Imm1_6,
  Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5,
  Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5__U5Imm1_6,
  Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5,
  Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4__U5Imm1_5__U5Imm1_6,
  Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__imm_95_0,
  Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4__imm_95_0,
  Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__imm_95_0,
  Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__imm_95_0,
  Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__imm_95_0__imm_95_31,
  Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4__imm_95_0__imm_95_31,
  Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__imm_95_0__imm_95_31,
  Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__imm_95_0__imm_95_31,
  Convert__Imm1_1,
  Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3,
  Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4,
  Convert__RegGPRC1_2__RegGxRCNoR01_3__RegGxRC1_4,
  Convert__imm_95_0__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3,
  Convert__imm_95_0__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegG8RC1_2__RegGxRCNoR01_3__RegGxRC1_4,
  Convert__imm_95_0__RegG8RC1_1__DispRIX1_2__RegGxRCNoR01_3,
  Convert__imm_95_0__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__imm_95_0__RegF8RC1_1__DispRI1_2__RegGxRCNoR01_3,
  Convert__imm_95_0__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__imm_95_0__RegF4RC1_1__DispRI1_2__RegGxRCNoR01_3,
  Convert__imm_95_0__RegF4RC1_1__RegGxRCNoR01_2__RegGxRC1_3,
  Convert__RegG8RC1_1__RegG8RC1_3__RegG8RC1_2,
  Convert__RegG8RC1_2__RegG8RC1_4__RegG8RC1_3,
  Convert__imm_95_0__RegGPRC1_2,
  Convert__imm_95_0__U5Imm1_2__RegGPRC1_3__RegGPRC1_4,
  Convert__imm_95_0__U5Imm1_2__RegGPRC1_3__U5Imm1_4,
  Convert__imm_95_0__U1Imm1_2,
  Convert__RegCRRC1_1,
  Convert__U5Imm1_1__RegG8RC1_2__RegG8RC1_3,
  Convert__imm_95_4__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_4__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_12__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_12__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_8__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_8__RegG8RC1_1__S16Imm1_2,
  Convert__U5Imm1_1__RegG8RC1_2__S16Imm1_3,
  Convert__imm_95_20__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_20__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_5__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_5__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_1__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_1__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_6__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_6__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_2__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_2__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_16__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_16__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_24__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_24__RegG8RC1_1__S16Imm1_2,
  Convert__imm_95_31__RegG8RC1_1__RegG8RC1_2,
  Convert__imm_95_31__RegG8RC1_1__S16Imm1_2,
  Convert__regR0__RegGPRC1_1,
  Convert__RegGPRC1_2__RegGPRC1_1,
  Convert__RegGPRC1_1__RegGPRC1_2__Imm1_3,
  Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0,
  Convert__RegGPRC1_1__RegGPRC1_2__imm_95_1,
  Convert__U5Imm1_1__RegGPRC1_2__RegGPRC1_3,
  Convert__imm_95_4__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_4__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_12__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_12__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_8__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_8__RegGPRC1_1__S16Imm1_2,
  Convert__U5Imm1_1__RegGPRC1_2__S16Imm1_3,
  Convert__imm_95_20__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_20__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_5__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_5__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_1__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_1__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_6__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_6__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_2__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_2__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_16__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_16__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_24__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_24__RegGPRC1_1__S16Imm1_2,
  Convert__imm_95_31__RegGPRC1_1__RegGPRC1_2,
  Convert__imm_95_31__RegGPRC1_1__S16Imm1_2,
  Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3,
  Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4,
  Convert__RegVRRC1_1__U5Imm1_3__RegVRRC1_2,
  Convert__RegVRRC1_1__RegVRRC1_2,
  Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4,
  Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3__U4Imm1_4,
  Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__U5Imm1_4,
  Convert__RegVRRC1_1__S5Imm1_2,
  Convert__regR0__regR0__imm_95_0,
  Convert__RegVSFRC1_1__RegVSFRC1_2,
  Convert__RegVSFRC1_1__RegVSFRC1_2__RegVSFRC1_3,
  Convert__RegVSSRC1_1__RegVSSRC1_2__RegVSSRC1_3,
  Convert__RegCRRC1_1__RegVSFRC1_2__RegVSFRC1_3,
  Convert__RegVSRC1_1__RegVSSRC1_2,
  Convert__RegVSSRC1_1__RegVSRC1_2,
  Convert__RegVSSRC1_1__RegVSFRC1_2,
  Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3,
  Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3,
  Convert__RegVSSRC1_1__RegVSSRC1_2,
  Convert__RegCRRC1_1__RegVSFRC1_2,
  Convert__RegVSRC1_1__RegVSRC1_2,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3,
  Convert__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4,
  Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2,
  Convert__RegCRRC1_1__RegVSRC1_2__RegVSRC1_3,
  Convert__RegCRRC1_1__RegVSRC1_2,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__imm_95_0,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__imm_95_3,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__U2Imm1_4,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2__imm_95_0,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2__imm_95_3,
  Convert__RegVSRC1_1__RegVSRC1_2__U2Imm1_3,
  Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2__imm_95_2,
  CVT_NUM_SIGNATURES
};

} // end anonymous namespace

static const uint8_t ConversionTable[CVT_NUM_SIGNATURES][13] = {
  // Convert__RegG8RC1_1__RegG8RC1_2__TLSReg1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addTLSRegOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRCNoR01_2__S16Imm1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCNoR0Operands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__S16Imm1_4
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addS16ImmOperands, 4, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRCNoR01_2__S17Imm1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCNoR0Operands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__U16Imm1_4
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addU16ImmOperands, 4, CVT_Done },
  // Convert_NoOperands
  { CVT_Done },
  // Convert__DirectBr1_1
  { CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__U5Imm1_1__RegCRBITRC1_2__CondBr1_3
  { CVT_95_addImmOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addBranchTargetOperands, 3, CVT_Done },
  // Convert__U5Imm1_1__RegCRBITRC1_2__imm_95_0
  { CVT_95_addImmOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__U5Imm1_1__RegCRBITRC1_2__Imm1_3
  { CVT_95_addImmOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__CondBr1_1
  { CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_0__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_0, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_0__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_0, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_8__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_8, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_8, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_2__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_2, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_2, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_10__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_10, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_10__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_10, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_76__regCR0__CondBr1_1
  { CVT_imm_95_76, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_76__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_76, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_79__regCR0__CondBr1_1
  { CVT_imm_95_79, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_79__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_79, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_78__regCR0__CondBr1_1
  { CVT_imm_95_78, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_78__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_78, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_76__regCR0
  { CVT_imm_95_76, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_76__RegCRRC1_1
  { CVT_imm_95_76, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_79__regCR0
  { CVT_imm_95_79, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_79__RegCRRC1_1
  { CVT_imm_95_79, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_78__regCR0
  { CVT_imm_95_78, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_78__RegCRRC1_1
  { CVT_imm_95_78, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_4__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_4, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_7__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_7, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_6, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_4__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_4, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_7__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_7, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_6__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_6, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_4__regCR0__CondBr1_1
  { CVT_imm_95_4, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_4__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_4, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_7__regCR0__CondBr1_1
  { CVT_imm_95_7, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_7__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_7, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_6__regCR0__CondBr1_1
  { CVT_imm_95_6, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_6__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_6, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_4__regCR0
  { CVT_imm_95_4, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_4__RegCRRC1_1
  { CVT_imm_95_4, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_7__regCR0
  { CVT_imm_95_7, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_7__RegCRRC1_1
  { CVT_imm_95_7, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_6__regCR0
  { CVT_imm_95_6, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_6__RegCRRC1_1
  { CVT_imm_95_6, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_44__regCR0__CondBr1_1
  { CVT_imm_95_44, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_44__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_44, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_47__regCR0__CondBr1_1
  { CVT_imm_95_47, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_47__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_47, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_46__regCR0__CondBr1_1
  { CVT_imm_95_46, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_46__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_46, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_44__regCR0
  { CVT_imm_95_44, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_44__RegCRRC1_1
  { CVT_imm_95_44, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_47__regCR0
  { CVT_imm_95_47, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_47__RegCRRC1_1
  { CVT_imm_95_47, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_46__regCR0
  { CVT_imm_95_46, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_46__RegCRRC1_1
  { CVT_imm_95_46, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__DirectBr1_1__Imm1_2
  { CVT_95_addBranchTargetOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__imm_95_36__regCR0__CondBr1_1
  { CVT_imm_95_36, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_36__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_36, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_39__regCR0__CondBr1_1
  { CVT_imm_95_39, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_39__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_39, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_38__regCR0__CondBr1_1
  { CVT_imm_95_38, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_38__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_38, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_36__regCR0
  { CVT_imm_95_36, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_36__RegCRRC1_1
  { CVT_imm_95_36, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_39__regCR0
  { CVT_imm_95_39, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_39__RegCRRC1_1
  { CVT_imm_95_39, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_38__regCR0
  { CVT_imm_95_38, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_38__RegCRRC1_1
  { CVT_imm_95_38, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_12__regCR0__CondBr1_1
  { CVT_imm_95_12, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_12__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_12, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_15__regCR0__CondBr1_1
  { CVT_imm_95_15, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_15__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_15, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_14__regCR0__CondBr1_1
  { CVT_imm_95_14, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_14__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_14, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_12__regCR0
  { CVT_imm_95_12, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_12__RegCRRC1_1
  { CVT_imm_95_12, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_15__regCR0
  { CVT_imm_95_15, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_15__RegCRRC1_1
  { CVT_imm_95_15, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_14__regCR0
  { CVT_imm_95_14, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_14__RegCRRC1_1
  { CVT_imm_95_14, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_68__regCR0__CondBr1_1
  { CVT_imm_95_68, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_68__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_68, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_71__regCR0__CondBr1_1
  { CVT_imm_95_71, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_71__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_71, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_70__regCR0__CondBr1_1
  { CVT_imm_95_70, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_70__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_70, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_68__regCR0
  { CVT_imm_95_68, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_68__RegCRRC1_1
  { CVT_imm_95_68, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_71__regCR0
  { CVT_imm_95_71, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_71__RegCRRC1_1
  { CVT_imm_95_71, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_70__regCR0
  { CVT_imm_95_70, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_70__RegCRRC1_1
  { CVT_imm_95_70, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_100__regCR0__CondBr1_1
  { CVT_imm_95_100, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_100__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_100, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_103__regCR0__CondBr1_1
  { CVT_imm_95_103, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_103__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_103, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_102__regCR0__CondBr1_1
  { CVT_imm_95_102, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_102__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_102, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_100__regCR0
  { CVT_imm_95_100, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_100__RegCRRC1_1
  { CVT_imm_95_100, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_103__regCR0
  { CVT_imm_95_103, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_103__RegCRRC1_1
  { CVT_imm_95_103, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_102__regCR0
  { CVT_imm_95_102, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_102__RegCRRC1_1
  { CVT_imm_95_102, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__imm_95_108__regCR0__CondBr1_1
  { CVT_imm_95_108, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_108__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_108, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_111__regCR0__CondBr1_1
  { CVT_imm_95_111, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_111__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_111, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_110__regCR0__CondBr1_1
  { CVT_imm_95_110, 0, CVT_regCR0, 0, CVT_95_addBranchTargetOperands, 1, CVT_Done },
  // Convert__imm_95_110__RegCRRC1_1__CondBr1_2
  { CVT_imm_95_110, 0, CVT_95_addRegCRRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_108__regCR0
  { CVT_imm_95_108, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_108__RegCRRC1_1
  { CVT_imm_95_108, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_111__regCR0
  { CVT_imm_95_111, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_111__RegCRRC1_1
  { CVT_imm_95_111, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_110__regCR0
  { CVT_imm_95_110, 0, CVT_regCR0, 0, CVT_Done },
  // Convert__imm_95_110__RegCRRC1_1
  { CVT_imm_95_110, 0, CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__imm_95_12__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_12, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_15__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_15, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_14__RegCRBITRC1_1__CondBr1_2
  { CVT_imm_95_14, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addBranchTargetOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_12, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_15__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_15, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__imm_95_14__RegCRBITRC1_1__imm_95_0
  { CVT_imm_95_14, 0, CVT_95_addRegCRBITRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__imm_95_0__U6Imm1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_imm_95_0, 0, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__imm_95_0__U6Imm1_4
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_imm_95_0, 0, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__U6Imm1_5
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0__U5Imm1_3__imm_95_31
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_imm_95_0, 0, CVT_95_addImmOperands, 3, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__imm_95_0__U5Imm1_4__imm_95_31
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_imm_95_0, 0, CVT_95_addImmOperands, 4, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegCRRC1_1__RegGPRC1_3__RegGPRC1_4
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_Done },
  // Convert__RegCRRC1_1__RegG8RC1_3__RegG8RC1_4
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 4, CVT_Done },
  // Convert__regCR0__RegG8RC1_1__RegG8RC1_2
  { CVT_regCR0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_1__RegG8RC1_2__RegG8RC1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__regCR0__RegG8RC1_1__S16Imm1_2
  { CVT_regCR0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegCRRC1_1__RegG8RC1_2__S16Imm1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegCRRC1_1__RegGPRC1_3__S16Imm1_4
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 3, CVT_95_addS16ImmOperands, 4, CVT_Done },
  // Convert__RegCRRC1_1__RegG8RC1_3__S16Imm1_4
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 3, CVT_95_addS16ImmOperands, 4, CVT_Done },
  // Convert__regCR0__RegG8RC1_1__U16Imm1_2
  { CVT_regCR0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addU16ImmOperands, 2, CVT_Done },
  // Convert__RegCRRC1_1__RegG8RC1_2__U16Imm1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addU16ImmOperands, 3, CVT_Done },
  // Convert__RegCRRC1_1__RegGPRC1_3__U16Imm1_4
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 3, CVT_95_addU16ImmOperands, 4, CVT_Done },
  // Convert__RegCRRC1_1__RegG8RC1_3__U16Imm1_4
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegG8RCOperands, 3, CVT_95_addU16ImmOperands, 4, CVT_Done },
  // Convert__regCR0__RegGPRC1_1__RegGPRC1_2
  { CVT_regCR0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_1__RegGPRC1_2__RegGPRC1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__regCR0__RegGPRC1_1__U16Imm1_2
  { CVT_regCR0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addU16ImmOperands, 2, CVT_Done },
  // Convert__RegCRRC1_1__RegGPRC1_2__U16Imm1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addU16ImmOperands, 3, CVT_Done },
  // Convert__regCR0__RegGPRC1_1__S16Imm1_2
  { CVT_regCR0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegCRRC1_1__RegGPRC1_2__S16Imm1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3
  { CVT_95_addRegCRBITRCOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addRegCRBITRCOperands, 3, CVT_Done },
  // Convert__RegCRBITRC1_1__RegCRBITRC1_1__RegCRBITRC1_1
  { CVT_95_addRegCRBITRCOperands, 1, CVT_95_addRegCRBITRCOperands, 1, CVT_95_addRegCRBITRCOperands, 1, CVT_Done },
  // Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_2
  { CVT_95_addRegCRBITRCOperands, 1, CVT_95_addRegCRBITRCOperands, 2, CVT_95_addRegCRBITRCOperands, 2, CVT_Done },
  // Convert__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addRegGxRCNoR0Operands, 1, CVT_95_addRegGxRCOperands, 2, CVT_Done },
  // Convert__U5Imm1_3__RegGxRCNoR01_1__RegGxRC1_2
  { CVT_95_addImmOperands, 3, CVT_95_addRegGxRCNoR0Operands, 1, CVT_95_addRegGxRCOperands, 2, CVT_Done },
  // Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_3
  { CVT_95_addRegGxRCNoR0Operands, 1, CVT_95_addRegGxRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__regR0__regR0
  { CVT_regR0, 0, CVT_regR0, 0, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_4
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 4, CVT_Done },
  // Convert__U5Imm1_1
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__U5Imm1_3__RegGPRC1_1__RegGPRC1_2
  { CVT_95_addImmOperands, 3, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_3__U5Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__DispSPE81_2__RegGxRCNoR01_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegGPRC1_1__DispSPE21_2__RegGxRCNoR01_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegGPRC1_1__Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__U5Imm1_2__RegGPRC1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_1__RegF4RC1_2
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF4RCOperands, 2, CVT_Done },
  // Convert__RegF4RC1_2__RegF4RC1_3
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4
  { CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addRegF8RCOperands, 4, CVT_Done },
  // Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_Done },
  // Convert__RegF8RC1_1__RegF8RC1_2
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_Done },
  // Convert__RegF8RC1_2__RegF8RC1_3
  { CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_1__RegF8RC1_2
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_Done },
  // Convert__RegF4RC1_2__RegF8RC1_3
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_Done },
  // Convert__RegCRRC1_1__RegF4RC1_2__RegF4RC1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addRegF8RCOperands, 4, CVT_Done },
  // Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4__RegF8RC1_5
  { CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addRegF8RCOperands, 4, CVT_95_addRegF8RCOperands, 5, CVT_Done },
  // Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_Done },
  // Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4__RegF4RC1_5
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_95_addRegF4RCOperands, 5, CVT_Done },
  // Convert__RegF4RC1_1__RegF8RC1_2__RegF4RC1_3__RegF4RC1_4
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_95_addRegF4RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_Done },
  // Convert__RegF4RC1_2__RegF8RC1_3__RegF4RC1_4__RegF4RC1_5
  { CVT_95_addRegF4RCOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addRegF4RCOperands, 4, CVT_95_addRegF4RCOperands, 5, CVT_Done },
  // Convert__U4Imm1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addImmOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRCNoR01_2__RegGPRC1_3__RegCRBITRC1_4
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCNoR0Operands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegCRBITRCOperands, 4, CVT_Done },
  // Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_0, 0, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_1__DispRIX1_2__RegGxRCNoR01_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_1__imm_95_0__DispRIX1_2__RegGxRCNoR01_3
  { CVT_95_addRegG8RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegG8RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_1__DispRI1_2__RegGxRCNoR01_3
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF8RC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3
  { CVT_95_addRegF8RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF8RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegF8RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegF8RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_1__DispRI1_2__RegGxRCNoR01_3
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF4RC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3
  { CVT_95_addRegF4RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__RegF4RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegF4RCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegF4RC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegF4RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__S16Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__S17Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_1
  { CVT_imm_95_1, 0, CVT_Done },
  // Convert__RegVSFRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegVSSRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegVSRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_0
  { CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegCRRC1_1__RegCRRC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegCRRCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_29
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_29, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_280
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_280, 0, CVT_Done },
  // Convert__RegGPRC1_1__U10Imm1_2__imm_95_0
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_128
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_128, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_129
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_129, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_130
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_130, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_131
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_131, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_132
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_132, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_133
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_133, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_134
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_134, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_135
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_135, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_28
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_28, 0, CVT_Done },
  // Convert__RegGPRC1_1
  { CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_19
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_19, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_537
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_537, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_539
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_539, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_541
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_541, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_543
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_543, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_536
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_536, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_538
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_538, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_540
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_540, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_542
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_542, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_1018
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_1018, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_981
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_981, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_22
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_22, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_17
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_17, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_18
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_18, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_980
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_980, 0, CVT_Done },
  // Convert__RegF8RC1_1
  { CVT_95_addRegF8RCOperands, 1, CVT_Done },
  // Convert__RegF8RC1_2
  { CVT_95_addRegF8RCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_529
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_529, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_531
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_531, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_533
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_533, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_535
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_535, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_528
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_528, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_530
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_530, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_532
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_532, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_534
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_534, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_1019
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_1019, 0, CVT_Done },
  // Convert__RegGPRC1_1__CRBitMask1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addCRBitMaskOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_48
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_48, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_287
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_287, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_5
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_5, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_4
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_4, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_25
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_25, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_512
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_512, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_272
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_272, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_273
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_273, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_274
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_274, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_275
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_275, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_260
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_260, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_261
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_261, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_262
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_262, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_263
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_263, 0, CVT_Done },
  // Convert__RegGPRC1_1__U4Imm1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_26
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_26, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_27
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_27, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_990
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_990, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_991
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_991, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_268
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_268, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_988
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_988, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_989
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_989, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_269
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_269, 0, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_986
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_986, 0, CVT_Done },
  // Convert__RegVRRC1_1
  { CVT_95_addRegVRRCOperands, 1, CVT_Done },
  // Convert__RegG8RC1_1__RegVSFRC1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__RegVSFRC1_2
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_1
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_1, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_3
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__imm_95_29__RegGPRC1_1
  { CVT_imm_95_29, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_280__RegGPRC1_1
  { CVT_imm_95_280, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_28__RegGPRC1_1
  { CVT_imm_95_28, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_255__RegG8RC1_1
  { CVT_imm_95_255, 0, CVT_95_addRegG8RCOperands, 1, CVT_Done },
  // Convert__Imm1_1__RegGPRC1_2
  { CVT_95_addImmOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_19__RegGPRC1_1
  { CVT_imm_95_19, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_537__RegGPRC1_2
  { CVT_imm_95_537, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_539__RegGPRC1_2
  { CVT_imm_95_539, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_541__RegGPRC1_2
  { CVT_imm_95_541, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_543__RegGPRC1_2
  { CVT_imm_95_543, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_536__RegGPRC1_2
  { CVT_imm_95_536, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_538__RegGPRC1_2
  { CVT_imm_95_538, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_540__RegGPRC1_2
  { CVT_imm_95_540, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_542__RegGPRC1_2
  { CVT_imm_95_542, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_1018__RegGPRC1_1
  { CVT_imm_95_1018, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_2__Imm1_1
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__imm_95_981__RegGPRC1_1
  { CVT_imm_95_981, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_22__RegGPRC1_1
  { CVT_imm_95_22, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_17__RegGPRC1_1
  { CVT_imm_95_17, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_18__RegGPRC1_1
  { CVT_imm_95_18, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_980__RegGPRC1_1
  { CVT_imm_95_980, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__Imm1_1__RegF8RC1_2__imm_95_0__imm_95_0
  { CVT_95_addImmOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_imm_95_0, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Imm1_2__RegF8RC1_3__imm_95_0__imm_95_0
  { CVT_95_addImmOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_imm_95_0, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Imm1_1__RegF8RC1_2__Imm1_3__Imm1_4
  { CVT_95_addImmOperands, 1, CVT_95_addRegF8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Imm1_2__RegF8RC1_3__Imm1_4__Imm1_5
  { CVT_95_addImmOperands, 2, CVT_95_addRegF8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegCRRC1_1__Imm1_2__imm_95_0
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addImmOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegCRRC1_2__Imm1_3__imm_95_0
  { CVT_95_addRegCRRCOperands, 2, CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegCRRC1_1__Imm1_2__Imm1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegCRRC1_2__Imm1_3__Imm1_4
  { CVT_95_addRegCRRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__imm_95_529__RegGPRC1_2
  { CVT_imm_95_529, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_531__RegGPRC1_2
  { CVT_imm_95_531, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_533__RegGPRC1_2
  { CVT_imm_95_533, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_535__RegGPRC1_2
  { CVT_imm_95_535, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_528__RegGPRC1_2
  { CVT_imm_95_528, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_530__RegGPRC1_2
  { CVT_imm_95_530, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_532__RegGPRC1_2
  { CVT_imm_95_532, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_534__RegGPRC1_2
  { CVT_imm_95_534, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_1019__RegGPRC1_1
  { CVT_imm_95_1019, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_1__imm_95_0
  { CVT_95_addRegGPRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__CRBitMask1_1__RegGPRC1_2
  { CVT_95_addCRBitMaskOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_48__RegGPRC1_1
  { CVT_imm_95_48, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_25__RegGPRC1_1
  { CVT_imm_95_25, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_512__RegGPRC1_1
  { CVT_imm_95_512, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_272__RegGPRC1_2
  { CVT_imm_95_272, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_273__RegGPRC1_2
  { CVT_imm_95_273, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_274__RegGPRC1_2
  { CVT_imm_95_274, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_275__RegGPRC1_2
  { CVT_imm_95_275, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_260__RegGPRC1_2
  { CVT_imm_95_260, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_261__RegGPRC1_2
  { CVT_imm_95_261, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_262__RegGPRC1_2
  { CVT_imm_95_262, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_263__RegGPRC1_2
  { CVT_imm_95_263, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_272__RegGPRC1_1
  { CVT_imm_95_272, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_273__RegGPRC1_1
  { CVT_imm_95_273, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_274__RegGPRC1_1
  { CVT_imm_95_274, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_275__RegGPRC1_1
  { CVT_imm_95_275, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_260__RegGPRC1_1
  { CVT_imm_95_260, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_261__RegGPRC1_1
  { CVT_imm_95_261, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_262__RegGPRC1_1
  { CVT_imm_95_262, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_263__RegGPRC1_1
  { CVT_imm_95_263, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_2__U4Imm1_1
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__imm_95_26__RegGPRC1_1
  { CVT_imm_95_26, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_27__RegGPRC1_1
  { CVT_imm_95_27, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_990__RegGPRC1_1
  { CVT_imm_95_990, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_991__RegGPRC1_1
  { CVT_imm_95_991, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_988__RegGPRC1_1
  { CVT_imm_95_988, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_284__RegGPRC1_1
  { CVT_imm_95_284, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_989__RegGPRC1_1
  { CVT_imm_95_989, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_285__RegGPRC1_1
  { CVT_imm_95_285, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__imm_95_986__RegGPRC1_1
  { CVT_imm_95_986, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegVSFRC1_1__RegG8RC1_2
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegVSFRC1_1__RegGPRC1_2
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegGPRC1_1
  { CVT_imm_95_1, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addU16ImmOperands, 3, CVT_Done },
  // Convert__imm_95_2
  { CVT_imm_95_2, 0, CVT_Done },
  // Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3__U2Imm1_4
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegQFRC1_1__RegQFRC1_2__U2Imm1_3
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegQFRC1_1__RegQFRC1_2
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_Done },
  // Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 3, CVT_Done },
  // Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3
  { CVT_95_addRegQSRCOperands, 1, CVT_95_addRegQSRCOperands, 2, CVT_95_addRegQSRCOperands, 3, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_1
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_1, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_4
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_4, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_1__RegQBRC1_1__imm_95_0
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQFRC1_2__RegQFRC1_3
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 3, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_2__imm_95_5
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 2, CVT_imm_95_5, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_9
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_9, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__U12Imm1_4
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 4, CVT_95_addRegQFRCOperands, 3, CVT_Done },
  // Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_4__RegQSRC1_3
  { CVT_95_addRegQSRCOperands, 1, CVT_95_addRegQSRCOperands, 2, CVT_95_addRegQSRCOperands, 4, CVT_95_addRegQSRCOperands, 3, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_14
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_14, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_8
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_8, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_2__imm_95_10
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 2, CVT_imm_95_10, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_7
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_7, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_13
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_13, 0, CVT_Done },
  // Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3__RegQFRC1_4
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_95_addRegQFRCOperands, 3, CVT_95_addRegQFRCOperands, 4, CVT_Done },
  // Convert__RegQSRC1_1__RegQFRC1_2
  { CVT_95_addRegQSRCOperands, 1, CVT_95_addRegQFRCOperands, 2, CVT_Done },
  // Convert__RegQFRC1_1__RegQBRC1_2__RegQFRC1_4__RegQFRC1_3
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQFRCOperands, 4, CVT_95_addRegQFRCOperands, 3, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_1__RegQBRC1_1__imm_95_15
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 1, CVT_imm_95_15, 0, CVT_Done },
  // Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_6
  { CVT_95_addRegQBRCOperands, 1, CVT_95_addRegQBRCOperands, 2, CVT_95_addRegQBRCOperands, 3, CVT_imm_95_6, 0, CVT_Done },
  // Convert__RegQFRC1_1__U12Imm1_2
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegQFRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegQFRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegQFRCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegQSRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_95_addRegQSRCOperands, 1, CVT_imm_95_0, 0, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_0__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_imm_95_0, 0, CVT_95_addRegQFRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_0__RegQSRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_imm_95_0, 0, CVT_95_addRegQSRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__U1Imm1_1
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__U6Imm1_4
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4__U6Imm1_5
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegG8RC1_1__Tie0__RegG8RC1_2__U6Imm1_3__U6Imm1_4
  { CVT_95_addRegG8RCOperands, 1, CVT_Tied, 0, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_2__Tie0__RegG8RC1_3__U6Imm1_4__U6Imm1_5
  { CVT_95_addRegG8RCOperands, 2, CVT_Tied, 0, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__U5Imm1_4__Imm1_5
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_1__Tie0__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5
  { CVT_95_addRegGPRCOperands, 1, CVT_Tied, 0, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_2__Tie0__RegGPRC1_3__U5Imm1_4__U5Imm1_5__U5Imm1_6
  { CVT_95_addRegGPRCOperands, 2, CVT_Tied, 0, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5__U5Imm1_6
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4__U5Imm1_5__U5Imm1_6
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_95_addImmOperands, 5, CVT_95_addImmOperands, 6, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__imm_95_0
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4__imm_95_0
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__imm_95_0
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__imm_95_0
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addImmOperands, 4, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__imm_95_0__imm_95_31
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4__imm_95_0__imm_95_31
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__imm_95_0__imm_95_31
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__imm_95_0__imm_95_31
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_imm_95_0, 0, CVT_imm_95_31, 0, CVT_Done },
  // Convert__Imm1_1
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_Done },
  // Convert__RegGPRC1_2__RegGxRCNoR01_3__RegGxRC1_4
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_95_addRegGxRCOperands, 4, CVT_Done },
  // Convert__imm_95_0__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3
  { CVT_imm_95_0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__imm_95_0__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_imm_95_0, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_2__RegGxRCNoR01_3__RegGxRC1_4
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_95_addRegGxRCOperands, 4, CVT_Done },
  // Convert__imm_95_0__RegG8RC1_1__DispRIX1_2__RegGxRCNoR01_3
  { CVT_imm_95_0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__imm_95_0__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_imm_95_0, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_0__RegF8RC1_1__DispRI1_2__RegGxRCNoR01_3
  { CVT_imm_95_0, 0, CVT_95_addRegF8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__imm_95_0__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_imm_95_0, 0, CVT_95_addRegF8RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__imm_95_0__RegF4RC1_1__DispRI1_2__RegGxRCNoR01_3
  { CVT_imm_95_0, 0, CVT_95_addRegF4RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_95_addRegGxRCNoR0Operands, 3, CVT_Done },
  // Convert__imm_95_0__RegF4RC1_1__RegGxRCNoR01_2__RegGxRC1_3
  { CVT_imm_95_0, 0, CVT_95_addRegF4RCOperands, 1, CVT_95_addRegGxRCNoR0Operands, 2, CVT_95_addRegGxRCOperands, 3, CVT_Done },
  // Convert__RegG8RC1_1__RegG8RC1_3__RegG8RC1_2
  { CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 3, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__RegG8RC1_2__RegG8RC1_4__RegG8RC1_3
  { CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 4, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__imm_95_0__RegGPRC1_2
  { CVT_imm_95_0, 0, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_0__U5Imm1_2__RegGPRC1_3__RegGPRC1_4
  { CVT_imm_95_0, 0, CVT_95_addImmOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addRegGPRCOperands, 4, CVT_Done },
  // Convert__imm_95_0__U5Imm1_2__RegGPRC1_3__U5Imm1_4
  { CVT_imm_95_0, 0, CVT_95_addImmOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__imm_95_0__U1Imm1_2
  { CVT_imm_95_0, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__RegCRRC1_1
  { CVT_95_addRegCRRCOperands, 1, CVT_Done },
  // Convert__U5Imm1_1__RegG8RC1_2__RegG8RC1_3
  { CVT_95_addImmOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addRegG8RCOperands, 3, CVT_Done },
  // Convert__imm_95_4__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_4, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_4__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_4, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_12, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_12, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_8, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_8, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__U5Imm1_1__RegG8RC1_2__S16Imm1_3
  { CVT_95_addImmOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__imm_95_20__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_20, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_20__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_20, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_5__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_5, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_5__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_5, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_1, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_1, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_6, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_6, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_2, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_2, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_16__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_16, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_16__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_16, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_24__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_24, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_24__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_24, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_31__RegG8RC1_1__RegG8RC1_2
  { CVT_imm_95_31, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addRegG8RCOperands, 2, CVT_Done },
  // Convert__imm_95_31__RegG8RC1_1__S16Imm1_2
  { CVT_imm_95_31, 0, CVT_95_addRegG8RCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__regR0__RegGPRC1_1
  { CVT_regR0, 0, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_2__RegGPRC1_1
  { CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 1, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__Imm1_3
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegGPRC1_1__RegGPRC1_2__imm_95_1
  { CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_imm_95_1, 0, CVT_Done },
  // Convert__U5Imm1_1__RegGPRC1_2__RegGPRC1_3
  { CVT_95_addImmOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addRegGPRCOperands, 3, CVT_Done },
  // Convert__imm_95_4__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_4, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_4__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_4, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_12, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_12__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_12, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_8, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_8__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_8, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__U5Imm1_1__RegGPRC1_2__S16Imm1_3
  { CVT_95_addImmOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_95_addS16ImmOperands, 3, CVT_Done },
  // Convert__imm_95_20__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_20, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_20__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_20, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_5__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_5, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_5__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_5, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_1, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_1__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_1, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_6, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_6__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_6, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_2, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_2__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_2, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_16__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_16, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_16__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_16, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_24__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_24, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_24__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_24, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__imm_95_31__RegGPRC1_1__RegGPRC1_2
  { CVT_imm_95_31, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addRegGPRCOperands, 2, CVT_Done },
  // Convert__imm_95_31__RegGPRC1_1__S16Imm1_2
  { CVT_imm_95_31, 0, CVT_95_addRegGPRCOperands, 1, CVT_95_addS16ImmOperands, 2, CVT_Done },
  // Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_Done },
  // Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_95_addRegVRRCOperands, 4, CVT_Done },
  // Convert__RegVRRC1_1__U5Imm1_3__RegVRRC1_2
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addImmOperands, 3, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegVRRC1_1__RegVRRC1_2
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_Done },
  // Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4
  { CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_95_addRegVRRCOperands, 4, CVT_Done },
  // Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3__U4Imm1_4
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__U5Imm1_4
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addRegVRRCOperands, 2, CVT_95_addRegVRRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegVRRC1_1__S5Imm1_2
  { CVT_95_addRegVRRCOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__regR0__regR0__imm_95_0
  { CVT_regR0, 0, CVT_regR0, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegVSFRC1_1__RegVSFRC1_2
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegVSFRC1_1__RegVSFRC1_2__RegVSFRC1_3
  { CVT_95_addRegVSFRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_95_addRegVSFRCOperands, 3, CVT_Done },
  // Convert__RegVSSRC1_1__RegVSSRC1_2__RegVSSRC1_3
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegVSSRCOperands, 2, CVT_95_addRegVSSRCOperands, 3, CVT_Done },
  // Convert__RegCRRC1_1__RegVSFRC1_2__RegVSFRC1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_95_addRegVSFRCOperands, 3, CVT_Done },
  // Convert__RegVSRC1_1__RegVSSRC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSSRCOperands, 2, CVT_Done },
  // Convert__RegVSSRC1_1__RegVSRC1_2
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegVSSRC1_1__RegVSFRC1_2
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3
  { CVT_95_addRegVSFRCOperands, 1, CVT_Tied, 0, CVT_95_addRegVSFRCOperands, 2, CVT_95_addRegVSFRCOperands, 3, CVT_Done },
  // Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3
  { CVT_95_addRegVSSRCOperands, 1, CVT_Tied, 0, CVT_95_addRegVSSRCOperands, 2, CVT_95_addRegVSSRCOperands, 3, CVT_Done },
  // Convert__RegVSSRC1_1__RegVSSRC1_2
  { CVT_95_addRegVSSRCOperands, 1, CVT_95_addRegVSSRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_1__RegVSFRC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegVSFRCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_Done },
  // Convert__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4
  { CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_95_addRegVSRCOperands, 4, CVT_Done },
  // Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3
  { CVT_95_addRegVSRCOperands, 1, CVT_Tied, 0, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegCRRC1_1__RegVSRC1_2__RegVSRC1_3
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_Done },
  // Convert__RegCRRC1_1__RegVSRC1_2
  { CVT_95_addRegCRRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__imm_95_0
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__imm_95_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_imm_95_3, 0, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__U2Imm1_4
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 3, CVT_95_addRegVSRCOperands, 4, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2__imm_95_0
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2__imm_95_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 2, CVT_imm_95_3, 0, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__U2Imm1_3
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2__imm_95_2
  { CVT_95_addRegVSRCOperands, 1, CVT_95_addRegVSRCOperands, 2, CVT_95_addRegVSRCOperands, 2, CVT_imm_95_2, 0, CVT_Done },
};

void PPCAsmParser::
convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                const OperandVector &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  Inst.setOpcode(Opcode);
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegOperands(Inst, 1);
      break;
    case CVT_Tied:
      Inst.addOperand(Inst.getOperand(*(p + 1)));
      break;
    case CVT_95_addRegG8RCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegG8RCOperands(Inst, 1);
      break;
    case CVT_95_addTLSRegOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addTLSRegOperands(Inst, 1);
      break;
    case CVT_95_addRegGPRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegGPRCOperands(Inst, 1);
      break;
    case CVT_95_addRegGPRCNoR0Operands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegGPRCNoR0Operands(Inst, 1);
      break;
    case CVT_95_addS16ImmOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addS16ImmOperands(Inst, 1);
      break;
    case CVT_95_addU16ImmOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addU16ImmOperands(Inst, 1);
      break;
    case CVT_95_addBranchTargetOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addBranchTargetOperands(Inst, 1);
      break;
    case CVT_95_addImmOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addImmOperands(Inst, 1);
      break;
    case CVT_95_addRegCRBITRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegCRBITRCOperands(Inst, 1);
      break;
    case CVT_imm_95_0:
      Inst.addOperand(MCOperand::createImm(0));
      break;
    case CVT_imm_95_8:
      Inst.addOperand(MCOperand::createImm(8));
      break;
    case CVT_imm_95_2:
      Inst.addOperand(MCOperand::createImm(2));
      break;
    case CVT_imm_95_10:
      Inst.addOperand(MCOperand::createImm(10));
      break;
    case CVT_imm_95_76:
      Inst.addOperand(MCOperand::createImm(76));
      break;
    case CVT_regCR0:
      Inst.addOperand(MCOperand::createReg(PPC::CR0));
      break;
    case CVT_95_addRegCRRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegCRRCOperands(Inst, 1);
      break;
    case CVT_imm_95_79:
      Inst.addOperand(MCOperand::createImm(79));
      break;
    case CVT_imm_95_78:
      Inst.addOperand(MCOperand::createImm(78));
      break;
    case CVT_imm_95_4:
      Inst.addOperand(MCOperand::createImm(4));
      break;
    case CVT_imm_95_7:
      Inst.addOperand(MCOperand::createImm(7));
      break;
    case CVT_imm_95_6:
      Inst.addOperand(MCOperand::createImm(6));
      break;
    case CVT_imm_95_44:
      Inst.addOperand(MCOperand::createImm(44));
      break;
    case CVT_imm_95_47:
      Inst.addOperand(MCOperand::createImm(47));
      break;
    case CVT_imm_95_46:
      Inst.addOperand(MCOperand::createImm(46));
      break;
    case CVT_imm_95_36:
      Inst.addOperand(MCOperand::createImm(36));
      break;
    case CVT_imm_95_39:
      Inst.addOperand(MCOperand::createImm(39));
      break;
    case CVT_imm_95_38:
      Inst.addOperand(MCOperand::createImm(38));
      break;
    case CVT_imm_95_12:
      Inst.addOperand(MCOperand::createImm(12));
      break;
    case CVT_imm_95_15:
      Inst.addOperand(MCOperand::createImm(15));
      break;
    case CVT_imm_95_14:
      Inst.addOperand(MCOperand::createImm(14));
      break;
    case CVT_imm_95_68:
      Inst.addOperand(MCOperand::createImm(68));
      break;
    case CVT_imm_95_71:
      Inst.addOperand(MCOperand::createImm(71));
      break;
    case CVT_imm_95_70:
      Inst.addOperand(MCOperand::createImm(70));
      break;
    case CVT_imm_95_100:
      Inst.addOperand(MCOperand::createImm(100));
      break;
    case CVT_imm_95_103:
      Inst.addOperand(MCOperand::createImm(103));
      break;
    case CVT_imm_95_102:
      Inst.addOperand(MCOperand::createImm(102));
      break;
    case CVT_imm_95_108:
      Inst.addOperand(MCOperand::createImm(108));
      break;
    case CVT_imm_95_111:
      Inst.addOperand(MCOperand::createImm(111));
      break;
    case CVT_imm_95_110:
      Inst.addOperand(MCOperand::createImm(110));
      break;
    case CVT_imm_95_31:
      Inst.addOperand(MCOperand::createImm(31));
      break;
    case CVT_95_addRegGxRCNoR0Operands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegGxRCNoR0Operands(Inst, 1);
      break;
    case CVT_95_addRegGxRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegGxRCOperands(Inst, 1);
      break;
    case CVT_regR0:
      Inst.addOperand(MCOperand::createReg(PPC::R0));
      break;
    case CVT_95_addRegF4RCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegF4RCOperands(Inst, 1);
      break;
    case CVT_95_addRegF8RCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegF8RCOperands(Inst, 1);
      break;
    case CVT_95_addRegVRRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegVRRCOperands(Inst, 1);
      break;
    case CVT_imm_95_1:
      Inst.addOperand(MCOperand::createImm(1));
      break;
    case CVT_95_addRegVSFRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegVSFRCOperands(Inst, 1);
      break;
    case CVT_95_addRegVSSRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegVSSRCOperands(Inst, 1);
      break;
    case CVT_95_addRegVSRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegVSRCOperands(Inst, 1);
      break;
    case CVT_imm_95_29:
      Inst.addOperand(MCOperand::createImm(29));
      break;
    case CVT_imm_95_280:
      Inst.addOperand(MCOperand::createImm(280));
      break;
    case CVT_imm_95_128:
      Inst.addOperand(MCOperand::createImm(128));
      break;
    case CVT_imm_95_129:
      Inst.addOperand(MCOperand::createImm(129));
      break;
    case CVT_imm_95_130:
      Inst.addOperand(MCOperand::createImm(130));
      break;
    case CVT_imm_95_131:
      Inst.addOperand(MCOperand::createImm(131));
      break;
    case CVT_imm_95_132:
      Inst.addOperand(MCOperand::createImm(132));
      break;
    case CVT_imm_95_133:
      Inst.addOperand(MCOperand::createImm(133));
      break;
    case CVT_imm_95_134:
      Inst.addOperand(MCOperand::createImm(134));
      break;
    case CVT_imm_95_135:
      Inst.addOperand(MCOperand::createImm(135));
      break;
    case CVT_imm_95_28:
      Inst.addOperand(MCOperand::createImm(28));
      break;
    case CVT_imm_95_19:
      Inst.addOperand(MCOperand::createImm(19));
      break;
    case CVT_imm_95_537:
      Inst.addOperand(MCOperand::createImm(537));
      break;
    case CVT_imm_95_539:
      Inst.addOperand(MCOperand::createImm(539));
      break;
    case CVT_imm_95_541:
      Inst.addOperand(MCOperand::createImm(541));
      break;
    case CVT_imm_95_543:
      Inst.addOperand(MCOperand::createImm(543));
      break;
    case CVT_imm_95_536:
      Inst.addOperand(MCOperand::createImm(536));
      break;
    case CVT_imm_95_538:
      Inst.addOperand(MCOperand::createImm(538));
      break;
    case CVT_imm_95_540:
      Inst.addOperand(MCOperand::createImm(540));
      break;
    case CVT_imm_95_542:
      Inst.addOperand(MCOperand::createImm(542));
      break;
    case CVT_imm_95_1018:
      Inst.addOperand(MCOperand::createImm(1018));
      break;
    case CVT_imm_95_981:
      Inst.addOperand(MCOperand::createImm(981));
      break;
    case CVT_imm_95_22:
      Inst.addOperand(MCOperand::createImm(22));
      break;
    case CVT_imm_95_17:
      Inst.addOperand(MCOperand::createImm(17));
      break;
    case CVT_imm_95_18:
      Inst.addOperand(MCOperand::createImm(18));
      break;
    case CVT_imm_95_980:
      Inst.addOperand(MCOperand::createImm(980));
      break;
    case CVT_imm_95_529:
      Inst.addOperand(MCOperand::createImm(529));
      break;
    case CVT_imm_95_531:
      Inst.addOperand(MCOperand::createImm(531));
      break;
    case CVT_imm_95_533:
      Inst.addOperand(MCOperand::createImm(533));
      break;
    case CVT_imm_95_535:
      Inst.addOperand(MCOperand::createImm(535));
      break;
    case CVT_imm_95_528:
      Inst.addOperand(MCOperand::createImm(528));
      break;
    case CVT_imm_95_530:
      Inst.addOperand(MCOperand::createImm(530));
      break;
    case CVT_imm_95_532:
      Inst.addOperand(MCOperand::createImm(532));
      break;
    case CVT_imm_95_534:
      Inst.addOperand(MCOperand::createImm(534));
      break;
    case CVT_imm_95_1019:
      Inst.addOperand(MCOperand::createImm(1019));
      break;
    case CVT_95_addCRBitMaskOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addCRBitMaskOperands(Inst, 1);
      break;
    case CVT_imm_95_48:
      Inst.addOperand(MCOperand::createImm(48));
      break;
    case CVT_imm_95_287:
      Inst.addOperand(MCOperand::createImm(287));
      break;
    case CVT_imm_95_5:
      Inst.addOperand(MCOperand::createImm(5));
      break;
    case CVT_imm_95_25:
      Inst.addOperand(MCOperand::createImm(25));
      break;
    case CVT_imm_95_512:
      Inst.addOperand(MCOperand::createImm(512));
      break;
    case CVT_imm_95_272:
      Inst.addOperand(MCOperand::createImm(272));
      break;
    case CVT_imm_95_273:
      Inst.addOperand(MCOperand::createImm(273));
      break;
    case CVT_imm_95_274:
      Inst.addOperand(MCOperand::createImm(274));
      break;
    case CVT_imm_95_275:
      Inst.addOperand(MCOperand::createImm(275));
      break;
    case CVT_imm_95_260:
      Inst.addOperand(MCOperand::createImm(260));
      break;
    case CVT_imm_95_261:
      Inst.addOperand(MCOperand::createImm(261));
      break;
    case CVT_imm_95_262:
      Inst.addOperand(MCOperand::createImm(262));
      break;
    case CVT_imm_95_263:
      Inst.addOperand(MCOperand::createImm(263));
      break;
    case CVT_imm_95_26:
      Inst.addOperand(MCOperand::createImm(26));
      break;
    case CVT_imm_95_27:
      Inst.addOperand(MCOperand::createImm(27));
      break;
    case CVT_imm_95_990:
      Inst.addOperand(MCOperand::createImm(990));
      break;
    case CVT_imm_95_991:
      Inst.addOperand(MCOperand::createImm(991));
      break;
    case CVT_imm_95_268:
      Inst.addOperand(MCOperand::createImm(268));
      break;
    case CVT_imm_95_988:
      Inst.addOperand(MCOperand::createImm(988));
      break;
    case CVT_imm_95_989:
      Inst.addOperand(MCOperand::createImm(989));
      break;
    case CVT_imm_95_269:
      Inst.addOperand(MCOperand::createImm(269));
      break;
    case CVT_imm_95_986:
      Inst.addOperand(MCOperand::createImm(986));
      break;
    case CVT_imm_95_255:
      Inst.addOperand(MCOperand::createImm(255));
      break;
    case CVT_imm_95_284:
      Inst.addOperand(MCOperand::createImm(284));
      break;
    case CVT_imm_95_285:
      Inst.addOperand(MCOperand::createImm(285));
      break;
    case CVT_95_addRegQFRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegQFRCOperands(Inst, 1);
      break;
    case CVT_95_addRegQSRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegQSRCOperands(Inst, 1);
      break;
    case CVT_95_addRegQBRCOperands:
      static_cast<PPCOperand&>(*Operands[*(p + 1)]).addRegQBRCOperands(Inst, 1);
      break;
    case CVT_imm_95_9:
      Inst.addOperand(MCOperand::createImm(9));
      break;
    case CVT_imm_95_13:
      Inst.addOperand(MCOperand::createImm(13));
      break;
    case CVT_imm_95_20:
      Inst.addOperand(MCOperand::createImm(20));
      break;
    case CVT_imm_95_16:
      Inst.addOperand(MCOperand::createImm(16));
      break;
    case CVT_imm_95_24:
      Inst.addOperand(MCOperand::createImm(24));
      break;
    case CVT_imm_95_3:
      Inst.addOperand(MCOperand::createImm(3));
      break;
    }
  }
}

void PPCAsmParser::
convertToMapAndConstraints(unsigned Kind,
                           const OperandVector &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  unsigned NumMCOperands = 0;
  const uint8_t *Converter = ConversionTable[Kind];
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("r");
      ++NumMCOperands;
      break;
    case CVT_Tied:
      ++NumMCOperands;
      break;
    case CVT_95_addRegG8RCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addTLSRegOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegGPRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegGPRCNoR0Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addS16ImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addU16ImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addBranchTargetOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegCRBITRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_8:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_2:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_10:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_76:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_regCR0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addRegCRRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_79:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_78:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_4:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_7:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_6:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_44:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_47:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_46:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_36:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_39:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_38:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_12:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_15:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_14:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_68:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_71:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_70:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_100:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_103:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_102:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_108:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_111:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_110:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_31:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addRegGxRCNoR0Operands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegGxRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_regR0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addRegF4RCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegF8RCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegVRRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_1:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addRegVSFRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegVSSRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegVSRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_29:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_280:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_128:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_129:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_130:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_131:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_132:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_133:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_134:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_135:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_28:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_19:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_537:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_539:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_541:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_543:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_536:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_538:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_540:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_542:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_1018:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_981:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_22:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_17:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_18:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_980:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_529:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_531:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_533:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_535:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_528:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_530:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_532:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_534:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_1019:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addCRBitMaskOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_48:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_287:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_5:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_25:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_512:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_272:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_273:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_274:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_275:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_260:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_261:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_262:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_263:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_26:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_27:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_990:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_991:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_268:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_988:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_989:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_269:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_986:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_255:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_284:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_285:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_95_addRegQFRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegQSRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_95_addRegQBRCOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_9:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_13:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_20:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_16:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_24:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_3:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    }
  }
}

namespace {

/// MatchClassKind - The kinds of classes which participate in
/// instruction matching.
enum MatchClassKind {
  InvalidMatchClass = 0,
  MCK__DOT_, // '.'
  MCK_0, // '0'
  MCK_1, // '1'
  MCK_2, // '2'
  MCK_3, // '3'
  MCK_4, // '4'
  MCK_5, // '5'
  MCK_6, // '6'
  MCK_7, // '7'
  MCK_add, // 'add'
  MCK_addc, // 'addc'
  MCK_adde, // 'adde'
  MCK_addi, // 'addi'
  MCK_addic, // 'addic'
  MCK_addis, // 'addis'
  MCK_addme, // 'addme'
  MCK_addze, // 'addze'
  MCK_and, // 'and'
  MCK_andc, // 'andc'
  MCK_andi, // 'andi'
  MCK_andis, // 'andis'
  MCK_attn, // 'attn'
  MCK_b, // 'b'
  MCK_ba, // 'ba'
  MCK_bc, // 'bc'
  MCK_bca, // 'bca'
  MCK_bcctr, // 'bcctr'
  MCK_bcctrl, // 'bcctrl'
  MCK_bcl, // 'bcl'
  MCK_bcla, // 'bcla'
  MCK_bclr, // 'bclr'
  MCK_bclrl, // 'bclrl'
  MCK_bctr, // 'bctr'
  MCK_bctrl, // 'bctrl'
  MCK_bdnz, // 'bdnz'
  MCK_bdnz_43_, // 'bdnz+'
  MCK_bdnz_MINUS_, // 'bdnz-'
  MCK_bdnza, // 'bdnza'
  MCK_bdnza_43_, // 'bdnza+'
  MCK_bdnza_MINUS_, // 'bdnza-'
  MCK_bdnzf, // 'bdnzf'
  MCK_bdnzfa, // 'bdnzfa'
  MCK_bdnzfl, // 'bdnzfl'
  MCK_bdnzfla, // 'bdnzfla'
  MCK_bdnzflr, // 'bdnzflr'
  MCK_bdnzflrl, // 'bdnzflrl'
  MCK_bdnzl, // 'bdnzl'
  MCK_bdnzl_43_, // 'bdnzl+'
  MCK_bdnzl_MINUS_, // 'bdnzl-'
  MCK_bdnzla, // 'bdnzla'
  MCK_bdnzla_43_, // 'bdnzla+'
  MCK_bdnzla_MINUS_, // 'bdnzla-'
  MCK_bdnzlr, // 'bdnzlr'
  MCK_bdnzlr_43_, // 'bdnzlr+'
  MCK_bdnzlr_MINUS_, // 'bdnzlr-'
  MCK_bdnzlrl, // 'bdnzlrl'
  MCK_bdnzlrl_43_, // 'bdnzlrl+'
  MCK_bdnzlrl_MINUS_, // 'bdnzlrl-'
  MCK_bdnzt, // 'bdnzt'
  MCK_bdnzta, // 'bdnzta'
  MCK_bdnztl, // 'bdnztl'
  MCK_bdnztla, // 'bdnztla'
  MCK_bdnztlr, // 'bdnztlr'
  MCK_bdnztlrl, // 'bdnztlrl'
  MCK_bdz, // 'bdz'
  MCK_bdz_43_, // 'bdz+'
  MCK_bdz_MINUS_, // 'bdz-'
  MCK_bdza, // 'bdza'
  MCK_bdza_43_, // 'bdza+'
  MCK_bdza_MINUS_, // 'bdza-'
  MCK_bdzf, // 'bdzf'
  MCK_bdzfa, // 'bdzfa'
  MCK_bdzfl, // 'bdzfl'
  MCK_bdzfla, // 'bdzfla'
  MCK_bdzflr, // 'bdzflr'
  MCK_bdzflrl, // 'bdzflrl'
  MCK_bdzl, // 'bdzl'
  MCK_bdzl_43_, // 'bdzl+'
  MCK_bdzl_MINUS_, // 'bdzl-'
  MCK_bdzla, // 'bdzla'
  MCK_bdzla_43_, // 'bdzla+'
  MCK_bdzla_MINUS_, // 'bdzla-'
  MCK_bdzlr, // 'bdzlr'
  MCK_bdzlr_43_, // 'bdzlr+'
  MCK_bdzlr_MINUS_, // 'bdzlr-'
  MCK_bdzlrl, // 'bdzlrl'
  MCK_bdzlrl_43_, // 'bdzlrl+'
  MCK_bdzlrl_MINUS_, // 'bdzlrl-'
  MCK_bdzt, // 'bdzt'
  MCK_bdzta, // 'bdzta'
  MCK_bdztl, // 'bdztl'
  MCK_bdztla, // 'bdztla'
  MCK_bdztlr, // 'bdztlr'
  MCK_bdztlrl, // 'bdztlrl'
  MCK_beq, // 'beq'
  MCK_beq_43_, // 'beq+'
  MCK_beq_MINUS_, // 'beq-'
  MCK_beqa, // 'beqa'
  MCK_beqa_43_, // 'beqa+'
  MCK_beqa_MINUS_, // 'beqa-'
  MCK_beqctr, // 'beqctr'
  MCK_beqctr_43_, // 'beqctr+'
  MCK_beqctr_MINUS_, // 'beqctr-'
  MCK_beqctrl, // 'beqctrl'
  MCK_beqctrl_43_, // 'beqctrl+'
  MCK_beqctrl_MINUS_, // 'beqctrl-'
  MCK_beql, // 'beql'
  MCK_beql_43_, // 'beql+'
  MCK_beql_MINUS_, // 'beql-'
  MCK_beqla, // 'beqla'
  MCK_beqla_43_, // 'beqla+'
  MCK_beqla_MINUS_, // 'beqla-'
  MCK_beqlr, // 'beqlr'
  MCK_beqlr_43_, // 'beqlr+'
  MCK_beqlr_MINUS_, // 'beqlr-'
  MCK_beqlrl, // 'beqlrl'
  MCK_beqlrl_43_, // 'beqlrl+'
  MCK_beqlrl_MINUS_, // 'beqlrl-'
  MCK_bf, // 'bf'
  MCK_bf_43_, // 'bf+'
  MCK_bf_MINUS_, // 'bf-'
  MCK_bfa, // 'bfa'
  MCK_bfa_43_, // 'bfa+'
  MCK_bfa_MINUS_, // 'bfa-'
  MCK_bfctr, // 'bfctr'
  MCK_bfctr_43_, // 'bfctr+'
  MCK_bfctr_MINUS_, // 'bfctr-'
  MCK_bfctrl, // 'bfctrl'
  MCK_bfctrl_43_, // 'bfctrl+'
  MCK_bfctrl_MINUS_, // 'bfctrl-'
  MCK_bfl, // 'bfl'
  MCK_bfl_43_, // 'bfl+'
  MCK_bfl_MINUS_, // 'bfl-'
  MCK_bfla, // 'bfla'
  MCK_bfla_43_, // 'bfla+'
  MCK_bfla_MINUS_, // 'bfla-'
  MCK_bflr, // 'bflr'
  MCK_bflr_43_, // 'bflr+'
  MCK_bflr_MINUS_, // 'bflr-'
  MCK_bflrl, // 'bflrl'
  MCK_bflrl_43_, // 'bflrl+'
  MCK_bflrl_MINUS_, // 'bflrl-'
  MCK_bge, // 'bge'
  MCK_bge_43_, // 'bge+'
  MCK_bge_MINUS_, // 'bge-'
  MCK_bgea, // 'bgea'
  MCK_bgea_43_, // 'bgea+'
  MCK_bgea_MINUS_, // 'bgea-'
  MCK_bgectr, // 'bgectr'
  MCK_bgectr_43_, // 'bgectr+'
  MCK_bgectr_MINUS_, // 'bgectr-'
  MCK_bgectrl, // 'bgectrl'
  MCK_bgectrl_43_, // 'bgectrl+'
  MCK_bgectrl_MINUS_, // 'bgectrl-'
  MCK_bgel, // 'bgel'
  MCK_bgel_43_, // 'bgel+'
  MCK_bgel_MINUS_, // 'bgel-'
  MCK_bgela, // 'bgela'
  MCK_bgela_43_, // 'bgela+'
  MCK_bgela_MINUS_, // 'bgela-'
  MCK_bgelr, // 'bgelr'
  MCK_bgelr_43_, // 'bgelr+'
  MCK_bgelr_MINUS_, // 'bgelr-'
  MCK_bgelrl, // 'bgelrl'
  MCK_bgelrl_43_, // 'bgelrl+'
  MCK_bgelrl_MINUS_, // 'bgelrl-'
  MCK_bgt, // 'bgt'
  MCK_bgt_43_, // 'bgt+'
  MCK_bgt_MINUS_, // 'bgt-'
  MCK_bgta, // 'bgta'
  MCK_bgta_43_, // 'bgta+'
  MCK_bgta_MINUS_, // 'bgta-'
  MCK_bgtctr, // 'bgtctr'
  MCK_bgtctr_43_, // 'bgtctr+'
  MCK_bgtctr_MINUS_, // 'bgtctr-'
  MCK_bgtctrl, // 'bgtctrl'
  MCK_bgtctrl_43_, // 'bgtctrl+'
  MCK_bgtctrl_MINUS_, // 'bgtctrl-'
  MCK_bgtl, // 'bgtl'
  MCK_bgtl_43_, // 'bgtl+'
  MCK_bgtl_MINUS_, // 'bgtl-'
  MCK_bgtla, // 'bgtla'
  MCK_bgtla_43_, // 'bgtla+'
  MCK_bgtla_MINUS_, // 'bgtla-'
  MCK_bgtlr, // 'bgtlr'
  MCK_bgtlr_43_, // 'bgtlr+'
  MCK_bgtlr_MINUS_, // 'bgtlr-'
  MCK_bgtlrl, // 'bgtlrl'
  MCK_bgtlrl_43_, // 'bgtlrl+'
  MCK_bgtlrl_MINUS_, // 'bgtlrl-'
  MCK_bl, // 'bl'
  MCK_bla, // 'bla'
  MCK_ble, // 'ble'
  MCK_ble_43_, // 'ble+'
  MCK_ble_MINUS_, // 'ble-'
  MCK_blea, // 'blea'
  MCK_blea_43_, // 'blea+'
  MCK_blea_MINUS_, // 'blea-'
  MCK_blectr, // 'blectr'
  MCK_blectr_43_, // 'blectr+'
  MCK_blectr_MINUS_, // 'blectr-'
  MCK_blectrl, // 'blectrl'
  MCK_blectrl_43_, // 'blectrl+'
  MCK_blectrl_MINUS_, // 'blectrl-'
  MCK_blel, // 'blel'
  MCK_blel_43_, // 'blel+'
  MCK_blel_MINUS_, // 'blel-'
  MCK_blela, // 'blela'
  MCK_blela_43_, // 'blela+'
  MCK_blela_MINUS_, // 'blela-'
  MCK_blelr, // 'blelr'
  MCK_blelr_43_, // 'blelr+'
  MCK_blelr_MINUS_, // 'blelr-'
  MCK_blelrl, // 'blelrl'
  MCK_blelrl_43_, // 'blelrl+'
  MCK_blelrl_MINUS_, // 'blelrl-'
  MCK_blr, // 'blr'
  MCK_blrl, // 'blrl'
  MCK_blt, // 'blt'
  MCK_blt_43_, // 'blt+'
  MCK_blt_MINUS_, // 'blt-'
  MCK_blta, // 'blta'
  MCK_blta_43_, // 'blta+'
  MCK_blta_MINUS_, // 'blta-'
  MCK_bltctr, // 'bltctr'
  MCK_bltctr_43_, // 'bltctr+'
  MCK_bltctr_MINUS_, // 'bltctr-'
  MCK_bltctrl, // 'bltctrl'
  MCK_bltctrl_43_, // 'bltctrl+'
  MCK_bltctrl_MINUS_, // 'bltctrl-'
  MCK_bltl, // 'bltl'
  MCK_bltl_43_, // 'bltl+'
  MCK_bltl_MINUS_, // 'bltl-'
  MCK_bltla, // 'bltla'
  MCK_bltla_43_, // 'bltla+'
  MCK_bltla_MINUS_, // 'bltla-'
  MCK_bltlr, // 'bltlr'
  MCK_bltlr_43_, // 'bltlr+'
  MCK_bltlr_MINUS_, // 'bltlr-'
  MCK_bltlrl, // 'bltlrl'
  MCK_bltlrl_43_, // 'bltlrl+'
  MCK_bltlrl_MINUS_, // 'bltlrl-'
  MCK_bne, // 'bne'
  MCK_bne_43_, // 'bne+'
  MCK_bne_MINUS_, // 'bne-'
  MCK_bnea, // 'bnea'
  MCK_bnea_43_, // 'bnea+'
  MCK_bnea_MINUS_, // 'bnea-'
  MCK_bnectr, // 'bnectr'
  MCK_bnectr_43_, // 'bnectr+'
  MCK_bnectr_MINUS_, // 'bnectr-'
  MCK_bnectrl, // 'bnectrl'
  MCK_bnectrl_43_, // 'bnectrl+'
  MCK_bnectrl_MINUS_, // 'bnectrl-'
  MCK_bnel, // 'bnel'
  MCK_bnel_43_, // 'bnel+'
  MCK_bnel_MINUS_, // 'bnel-'
  MCK_bnela, // 'bnela'
  MCK_bnela_43_, // 'bnela+'
  MCK_bnela_MINUS_, // 'bnela-'
  MCK_bnelr, // 'bnelr'
  MCK_bnelr_43_, // 'bnelr+'
  MCK_bnelr_MINUS_, // 'bnelr-'
  MCK_bnelrl, // 'bnelrl'
  MCK_bnelrl_43_, // 'bnelrl+'
  MCK_bnelrl_MINUS_, // 'bnelrl-'
  MCK_bng, // 'bng'
  MCK_bng_43_, // 'bng+'
  MCK_bng_MINUS_, // 'bng-'
  MCK_bnga, // 'bnga'
  MCK_bnga_43_, // 'bnga+'
  MCK_bnga_MINUS_, // 'bnga-'
  MCK_bngctr, // 'bngctr'
  MCK_bngctr_43_, // 'bngctr+'
  MCK_bngctr_MINUS_, // 'bngctr-'
  MCK_bngctrl, // 'bngctrl'
  MCK_bngctrl_43_, // 'bngctrl+'
  MCK_bngctrl_MINUS_, // 'bngctrl-'
  MCK_bngl, // 'bngl'
  MCK_bngl_43_, // 'bngl+'
  MCK_bngl_MINUS_, // 'bngl-'
  MCK_bngla, // 'bngla'
  MCK_bngla_43_, // 'bngla+'
  MCK_bngla_MINUS_, // 'bngla-'
  MCK_bnglr, // 'bnglr'
  MCK_bnglr_43_, // 'bnglr+'
  MCK_bnglr_MINUS_, // 'bnglr-'
  MCK_bnglrl, // 'bnglrl'
  MCK_bnglrl_43_, // 'bnglrl+'
  MCK_bnglrl_MINUS_, // 'bnglrl-'
  MCK_bnl, // 'bnl'
  MCK_bnl_43_, // 'bnl+'
  MCK_bnl_MINUS_, // 'bnl-'
  MCK_bnla, // 'bnla'
  MCK_bnla_43_, // 'bnla+'
  MCK_bnla_MINUS_, // 'bnla-'
  MCK_bnlctr, // 'bnlctr'
  MCK_bnlctr_43_, // 'bnlctr+'
  MCK_bnlctr_MINUS_, // 'bnlctr-'
  MCK_bnlctrl, // 'bnlctrl'
  MCK_bnlctrl_43_, // 'bnlctrl+'
  MCK_bnlctrl_MINUS_, // 'bnlctrl-'
  MCK_bnll, // 'bnll'
  MCK_bnll_43_, // 'bnll+'
  MCK_bnll_MINUS_, // 'bnll-'
  MCK_bnlla, // 'bnlla'
  MCK_bnlla_43_, // 'bnlla+'
  MCK_bnlla_MINUS_, // 'bnlla-'
  MCK_bnllr, // 'bnllr'
  MCK_bnllr_43_, // 'bnllr+'
  MCK_bnllr_MINUS_, // 'bnllr-'
  MCK_bnllrl, // 'bnllrl'
  MCK_bnllrl_43_, // 'bnllrl+'
  MCK_bnllrl_MINUS_, // 'bnllrl-'
  MCK_bns, // 'bns'
  MCK_bns_43_, // 'bns+'
  MCK_bns_MINUS_, // 'bns-'
  MCK_bnsa, // 'bnsa'
  MCK_bnsa_43_, // 'bnsa+'
  MCK_bnsa_MINUS_, // 'bnsa-'
  MCK_bnsctr, // 'bnsctr'
  MCK_bnsctr_43_, // 'bnsctr+'
  MCK_bnsctr_MINUS_, // 'bnsctr-'
  MCK_bnsctrl, // 'bnsctrl'
  MCK_bnsctrl_43_, // 'bnsctrl+'
  MCK_bnsctrl_MINUS_, // 'bnsctrl-'
  MCK_bnsl, // 'bnsl'
  MCK_bnsl_43_, // 'bnsl+'
  MCK_bnsl_MINUS_, // 'bnsl-'
  MCK_bnsla, // 'bnsla'
  MCK_bnsla_43_, // 'bnsla+'
  MCK_bnsla_MINUS_, // 'bnsla-'
  MCK_bnslr, // 'bnslr'
  MCK_bnslr_43_, // 'bnslr+'
  MCK_bnslr_MINUS_, // 'bnslr-'
  MCK_bnslrl, // 'bnslrl'
  MCK_bnslrl_43_, // 'bnslrl+'
  MCK_bnslrl_MINUS_, // 'bnslrl-'
  MCK_bnu, // 'bnu'
  MCK_bnu_43_, // 'bnu+'
  MCK_bnu_MINUS_, // 'bnu-'
  MCK_bnua, // 'bnua'
  MCK_bnua_43_, // 'bnua+'
  MCK_bnua_MINUS_, // 'bnua-'
  MCK_bnuctr, // 'bnuctr'
  MCK_bnuctr_43_, // 'bnuctr+'
  MCK_bnuctr_MINUS_, // 'bnuctr-'
  MCK_bnuctrl, // 'bnuctrl'
  MCK_bnuctrl_43_, // 'bnuctrl+'
  MCK_bnuctrl_MINUS_, // 'bnuctrl-'
  MCK_bnul, // 'bnul'
  MCK_bnul_43_, // 'bnul+'
  MCK_bnul_MINUS_, // 'bnul-'
  MCK_bnula, // 'bnula'
  MCK_bnula_43_, // 'bnula+'
  MCK_bnula_MINUS_, // 'bnula-'
  MCK_bnulr, // 'bnulr'
  MCK_bnulr_43_, // 'bnulr+'
  MCK_bnulr_MINUS_, // 'bnulr-'
  MCK_bnulrl, // 'bnulrl'
  MCK_bnulrl_43_, // 'bnulrl+'
  MCK_bnulrl_MINUS_, // 'bnulrl-'
  MCK_bpermd, // 'bpermd'
  MCK_brinc, // 'brinc'
  MCK_bso, // 'bso'
  MCK_bso_43_, // 'bso+'
  MCK_bso_MINUS_, // 'bso-'
  MCK_bsoa, // 'bsoa'
  MCK_bsoa_43_, // 'bsoa+'
  MCK_bsoa_MINUS_, // 'bsoa-'
  MCK_bsoctr, // 'bsoctr'
  MCK_bsoctr_43_, // 'bsoctr+'
  MCK_bsoctr_MINUS_, // 'bsoctr-'
  MCK_bsoctrl, // 'bsoctrl'
  MCK_bsoctrl_43_, // 'bsoctrl+'
  MCK_bsoctrl_MINUS_, // 'bsoctrl-'
  MCK_bsol, // 'bsol'
  MCK_bsol_43_, // 'bsol+'
  MCK_bsol_MINUS_, // 'bsol-'
  MCK_bsola, // 'bsola'
  MCK_bsola_43_, // 'bsola+'
  MCK_bsola_MINUS_, // 'bsola-'
  MCK_bsolr, // 'bsolr'
  MCK_bsolr_43_, // 'bsolr+'
  MCK_bsolr_MINUS_, // 'bsolr-'
  MCK_bsolrl, // 'bsolrl'
  MCK_bsolrl_43_, // 'bsolrl+'
  MCK_bsolrl_MINUS_, // 'bsolrl-'
  MCK_bt, // 'bt'
  MCK_bt_43_, // 'bt+'
  MCK_bt_MINUS_, // 'bt-'
  MCK_bta, // 'bta'
  MCK_bta_43_, // 'bta+'
  MCK_bta_MINUS_, // 'bta-'
  MCK_btctr, // 'btctr'
  MCK_btctr_43_, // 'btctr+'
  MCK_btctr_MINUS_, // 'btctr-'
  MCK_btctrl, // 'btctrl'
  MCK_btctrl_43_, // 'btctrl+'
  MCK_btctrl_MINUS_, // 'btctrl-'
  MCK_btl, // 'btl'
  MCK_btl_43_, // 'btl+'
  MCK_btl_MINUS_, // 'btl-'
  MCK_btla, // 'btla'
  MCK_btla_43_, // 'btla+'
  MCK_btla_MINUS_, // 'btla-'
  MCK_btlr, // 'btlr'
  MCK_btlr_43_, // 'btlr+'
  MCK_btlr_MINUS_, // 'btlr-'
  MCK_btlrl, // 'btlrl'
  MCK_btlrl_43_, // 'btlrl+'
  MCK_btlrl_MINUS_, // 'btlrl-'
  MCK_bun, // 'bun'
  MCK_bun_43_, // 'bun+'
  MCK_bun_MINUS_, // 'bun-'
  MCK_buna, // 'buna'
  MCK_buna_43_, // 'buna+'
  MCK_buna_MINUS_, // 'buna-'
  MCK_bunctr, // 'bunctr'
  MCK_bunctr_43_, // 'bunctr+'
  MCK_bunctr_MINUS_, // 'bunctr-'
  MCK_bunctrl, // 'bunctrl'
  MCK_bunctrl_43_, // 'bunctrl+'
  MCK_bunctrl_MINUS_, // 'bunctrl-'
  MCK_bunl, // 'bunl'
  MCK_bunl_43_, // 'bunl+'
  MCK_bunl_MINUS_, // 'bunl-'
  MCK_bunla, // 'bunla'
  MCK_bunla_43_, // 'bunla+'
  MCK_bunla_MINUS_, // 'bunla-'
  MCK_bunlr, // 'bunlr'
  MCK_bunlr_43_, // 'bunlr+'
  MCK_bunlr_MINUS_, // 'bunlr-'
  MCK_bunlrl, // 'bunlrl'
  MCK_bunlrl_43_, // 'bunlrl+'
  MCK_bunlrl_MINUS_, // 'bunlrl-'
  MCK_clrbhrb, // 'clrbhrb'
  MCK_clrldi, // 'clrldi'
  MCK_clrlsldi, // 'clrlsldi'
  MCK_clrlslwi, // 'clrlslwi'
  MCK_clrlwi, // 'clrlwi'
  MCK_clrrdi, // 'clrrdi'
  MCK_clrrwi, // 'clrrwi'
  MCK_cmp, // 'cmp'
  MCK_cmpb, // 'cmpb'
  MCK_cmpd, // 'cmpd'
  MCK_cmpdi, // 'cmpdi'
  MCK_cmpi, // 'cmpi'
  MCK_cmpl, // 'cmpl'
  MCK_cmpld, // 'cmpld'
  MCK_cmpldi, // 'cmpldi'
  MCK_cmpli, // 'cmpli'
  MCK_cmplw, // 'cmplw'
  MCK_cmplwi, // 'cmplwi'
  MCK_cmpw, // 'cmpw'
  MCK_cmpwi, // 'cmpwi'
  MCK_cntlzd, // 'cntlzd'
  MCK_cntlzw, // 'cntlzw'
  MCK_crand, // 'crand'
  MCK_crandc, // 'crandc'
  MCK_crclr, // 'crclr'
  MCK_creqv, // 'creqv'
  MCK_crmove, // 'crmove'
  MCK_crnand, // 'crnand'
  MCK_crnor, // 'crnor'
  MCK_crnot, // 'crnot'
  MCK_cror, // 'cror'
  MCK_crorc, // 'crorc'
  MCK_crset, // 'crset'
  MCK_crxor, // 'crxor'
  MCK_dcba, // 'dcba'
  MCK_dcbf, // 'dcbf'
  MCK_dcbi, // 'dcbi'
  MCK_dcbst, // 'dcbst'
  MCK_dcbt, // 'dcbt'
  MCK_dcbtct, // 'dcbtct'
  MCK_dcbtds, // 'dcbtds'
  MCK_dcbtst, // 'dcbtst'
  MCK_dcbtstct, // 'dcbtstct'
  MCK_dcbtstds, // 'dcbtstds'
  MCK_dcbtstt, // 'dcbtstt'
  MCK_dcbtt, // 'dcbtt'
  MCK_dcbz, // 'dcbz'
  MCK_dcbzl, // 'dcbzl'
  MCK_dccci, // 'dccci'
  MCK_dci, // 'dci'
  MCK_divd, // 'divd'
  MCK_divde, // 'divde'
  MCK_divdeu, // 'divdeu'
  MCK_divdu, // 'divdu'
  MCK_divw, // 'divw'
  MCK_divwe, // 'divwe'
  MCK_divweu, // 'divweu'
  MCK_divwu, // 'divwu'
  MCK_dss, // 'dss'
  MCK_dssall, // 'dssall'
  MCK_dst, // 'dst'
  MCK_dstst, // 'dstst'
  MCK_dststt, // 'dststt'
  MCK_dstt, // 'dstt'
  MCK_eieio, // 'eieio'
  MCK_eqv, // 'eqv'
  MCK_evabs, // 'evabs'
  MCK_evaddiw, // 'evaddiw'
  MCK_evaddsmiaaw, // 'evaddsmiaaw'
  MCK_evaddssiaaw, // 'evaddssiaaw'
  MCK_evaddumiaaw, // 'evaddumiaaw'
  MCK_evaddusiaaw, // 'evaddusiaaw'
  MCK_evaddw, // 'evaddw'
  MCK_evand, // 'evand'
  MCK_evandc, // 'evandc'
  MCK_evcmpeq, // 'evcmpeq'
  MCK_evcmpgts, // 'evcmpgts'
  MCK_evcmpgtu, // 'evcmpgtu'
  MCK_evcmplts, // 'evcmplts'
  MCK_evcmpltu, // 'evcmpltu'
  MCK_evcntlsw, // 'evcntlsw'
  MCK_evcntlzw, // 'evcntlzw'
  MCK_evdivws, // 'evdivws'
  MCK_evdivwu, // 'evdivwu'
  MCK_eveqv, // 'eveqv'
  MCK_evextsb, // 'evextsb'
  MCK_evextsh, // 'evextsh'
  MCK_evldd, // 'evldd'
  MCK_evlddx, // 'evlddx'
  MCK_evldh, // 'evldh'
  MCK_evldhx, // 'evldhx'
  MCK_evldw, // 'evldw'
  MCK_evldwx, // 'evldwx'
  MCK_evlhhesplat, // 'evlhhesplat'
  MCK_evlhhesplatx, // 'evlhhesplatx'
  MCK_evlhhossplat, // 'evlhhossplat'
  MCK_evlhhossplatx, // 'evlhhossplatx'
  MCK_evlhhousplat, // 'evlhhousplat'
  MCK_evlhhousplatx, // 'evlhhousplatx'
  MCK_evlwhe, // 'evlwhe'
  MCK_evlwhex, // 'evlwhex'
  MCK_evlwhos, // 'evlwhos'
  MCK_evlwhosx, // 'evlwhosx'
  MCK_evlwhou, // 'evlwhou'
  MCK_evlwhoux, // 'evlwhoux'
  MCK_evlwhsplat, // 'evlwhsplat'
  MCK_evlwhsplatx, // 'evlwhsplatx'
  MCK_evlwwsplat, // 'evlwwsplat'
  MCK_evlwwsplatx, // 'evlwwsplatx'
  MCK_evmergehi, // 'evmergehi'
  MCK_evmergehilo, // 'evmergehilo'
  MCK_evmergelo, // 'evmergelo'
  MCK_evmergelohi, // 'evmergelohi'
  MCK_evmhegsmfaa, // 'evmhegsmfaa'
  MCK_evmhegsmfan, // 'evmhegsmfan'
  MCK_evmhegsmiaa, // 'evmhegsmiaa'
  MCK_evmhegsmian, // 'evmhegsmian'
  MCK_evmhegumiaa, // 'evmhegumiaa'
  MCK_evmhegumian, // 'evmhegumian'
  MCK_evmhesmf, // 'evmhesmf'
  MCK_evmhesmfa, // 'evmhesmfa'
  MCK_evmhesmfaaw, // 'evmhesmfaaw'
  MCK_evmhesmfanw, // 'evmhesmfanw'
  MCK_evmhesmi, // 'evmhesmi'
  MCK_evmhesmia, // 'evmhesmia'
  MCK_evmhesmiaaw, // 'evmhesmiaaw'
  MCK_evmhesmianw, // 'evmhesmianw'
  MCK_evmhessf, // 'evmhessf'
  MCK_evmhessfa, // 'evmhessfa'
  MCK_evmhessfaaw, // 'evmhessfaaw'
  MCK_evmhessfanw, // 'evmhessfanw'
  MCK_evmhessiaaw, // 'evmhessiaaw'
  MCK_evmhessianw, // 'evmhessianw'
  MCK_evmheumi, // 'evmheumi'
  MCK_evmheumia, // 'evmheumia'
  MCK_evmheumiaaw, // 'evmheumiaaw'
  MCK_evmheumianw, // 'evmheumianw'
  MCK_evmheusiaaw, // 'evmheusiaaw'
  MCK_evmheusianw, // 'evmheusianw'
  MCK_evmhogsmfaa, // 'evmhogsmfaa'
  MCK_evmhogsmfan, // 'evmhogsmfan'
  MCK_evmhogsmiaa, // 'evmhogsmiaa'
  MCK_evmhogsmian, // 'evmhogsmian'
  MCK_evmhogumiaa, // 'evmhogumiaa'
  MCK_evmhogumian, // 'evmhogumian'
  MCK_evmhosmf, // 'evmhosmf'
  MCK_evmhosmfa, // 'evmhosmfa'
  MCK_evmhosmfaaw, // 'evmhosmfaaw'
  MCK_evmhosmfanw, // 'evmhosmfanw'
  MCK_evmhosmi, // 'evmhosmi'
  MCK_evmhosmia, // 'evmhosmia'
  MCK_evmhosmiaaw, // 'evmhosmiaaw'
  MCK_evmhosmianw, // 'evmhosmianw'
  MCK_evmhossf, // 'evmhossf'
  MCK_evmhossfa, // 'evmhossfa'
  MCK_evmhossfaaw, // 'evmhossfaaw'
  MCK_evmhossfanw, // 'evmhossfanw'
  MCK_evmhossiaaw, // 'evmhossiaaw'
  MCK_evmhossianw, // 'evmhossianw'
  MCK_evmhoumi, // 'evmhoumi'
  MCK_evmhoumia, // 'evmhoumia'
  MCK_evmhoumiaaw, // 'evmhoumiaaw'
  MCK_evmhoumianw, // 'evmhoumianw'
  MCK_evmhousiaaw, // 'evmhousiaaw'
  MCK_evmhousianw, // 'evmhousianw'
  MCK_evmra, // 'evmra'
  MCK_evmwhsmf, // 'evmwhsmf'
  MCK_evmwhsmfa, // 'evmwhsmfa'
  MCK_evmwhsmi, // 'evmwhsmi'
  MCK_evmwhsmia, // 'evmwhsmia'
  MCK_evmwhssf, // 'evmwhssf'
  MCK_evmwhssfa, // 'evmwhssfa'
  MCK_evmwhumi, // 'evmwhumi'
  MCK_evmwhumia, // 'evmwhumia'
  MCK_evmwlsmiaaw, // 'evmwlsmiaaw'
  MCK_evmwlsmianw, // 'evmwlsmianw'
  MCK_evmwlssiaaw, // 'evmwlssiaaw'
  MCK_evmwlssianw, // 'evmwlssianw'
  MCK_evmwlumi, // 'evmwlumi'
  MCK_evmwlumia, // 'evmwlumia'
  MCK_evmwlumiaaw, // 'evmwlumiaaw'
  MCK_evmwlumianw, // 'evmwlumianw'
  MCK_evmwlusiaaw, // 'evmwlusiaaw'
  MCK_evmwlusianw, // 'evmwlusianw'
  MCK_evmwsmf, // 'evmwsmf'
  MCK_evmwsmfa, // 'evmwsmfa'
  MCK_evmwsmfaa, // 'evmwsmfaa'
  MCK_evmwsmfan, // 'evmwsmfan'
  MCK_evmwsmi, // 'evmwsmi'
  MCK_evmwsmia, // 'evmwsmia'
  MCK_evmwsmiaa, // 'evmwsmiaa'
  MCK_evmwsmian, // 'evmwsmian'
  MCK_evmwssf, // 'evmwssf'
  MCK_evmwssfa, // 'evmwssfa'
  MCK_evmwssfaa, // 'evmwssfaa'
  MCK_evmwssfan, // 'evmwssfan'
  MCK_evmwumi, // 'evmwumi'
  MCK_evmwumia, // 'evmwumia'
  MCK_evmwumiaa, // 'evmwumiaa'
  MCK_evmwumian, // 'evmwumian'
  MCK_evnand, // 'evnand'
  MCK_evneg, // 'evneg'
  MCK_evnor, // 'evnor'
  MCK_evor, // 'evor'
  MCK_evorc, // 'evorc'
  MCK_evrlw, // 'evrlw'
  MCK_evrlwi, // 'evrlwi'
  MCK_evrndw, // 'evrndw'
  MCK_evslw, // 'evslw'
  MCK_evslwi, // 'evslwi'
  MCK_evsplatfi, // 'evsplatfi'
  MCK_evsplati, // 'evsplati'
  MCK_evsrwis, // 'evsrwis'
  MCK_evsrwiu, // 'evsrwiu'
  MCK_evsrws, // 'evsrws'
  MCK_evsrwu, // 'evsrwu'
  MCK_evstdd, // 'evstdd'
  MCK_evstddx, // 'evstddx'
  MCK_evstdh, // 'evstdh'
  MCK_evstdhx, // 'evstdhx'
  MCK_evstdw, // 'evstdw'
  MCK_evstdwx, // 'evstdwx'
  MCK_evstwhe, // 'evstwhe'
  MCK_evstwhex, // 'evstwhex'
  MCK_evstwho, // 'evstwho'
  MCK_evstwhox, // 'evstwhox'
  MCK_evstwwe, // 'evstwwe'
  MCK_evstwwex, // 'evstwwex'
  MCK_evstwwo, // 'evstwwo'
  MCK_evstwwox, // 'evstwwox'
  MCK_evsubfsmiaaw, // 'evsubfsmiaaw'
  MCK_evsubfssiaaw, // 'evsubfssiaaw'
  MCK_evsubfumiaaw, // 'evsubfumiaaw'
  MCK_evsubfusiaaw, // 'evsubfusiaaw'
  MCK_evsubfw, // 'evsubfw'
  MCK_evsubifw, // 'evsubifw'
  MCK_evxor, // 'evxor'
  MCK_extldi, // 'extldi'
  MCK_extlwi, // 'extlwi'
  MCK_extrdi, // 'extrdi'
  MCK_extrwi, // 'extrwi'
  MCK_extsb, // 'extsb'
  MCK_extsh, // 'extsh'
  MCK_extsw, // 'extsw'
  MCK_fabs, // 'fabs'
  MCK_fadd, // 'fadd'
  MCK_fadds, // 'fadds'
  MCK_fcfid, // 'fcfid'
  MCK_fcfids, // 'fcfids'
  MCK_fcfidu, // 'fcfidu'
  MCK_fcfidus, // 'fcfidus'
  MCK_fcmpu, // 'fcmpu'
  MCK_fcpsgn, // 'fcpsgn'
  MCK_fctid, // 'fctid'
  MCK_fctiduz, // 'fctiduz'
  MCK_fctidz, // 'fctidz'
  MCK_fctiw, // 'fctiw'
  MCK_fctiwuz, // 'fctiwuz'
  MCK_fctiwz, // 'fctiwz'
  MCK_fdiv, // 'fdiv'
  MCK_fdivs, // 'fdivs'
  MCK_fmadd, // 'fmadd'
  MCK_fmadds, // 'fmadds'
  MCK_fmr, // 'fmr'
  MCK_fmsub, // 'fmsub'
  MCK_fmsubs, // 'fmsubs'
  MCK_fmul, // 'fmul'
  MCK_fmuls, // 'fmuls'
  MCK_fnabs, // 'fnabs'
  MCK_fneg, // 'fneg'
  MCK_fnmadd, // 'fnmadd'
  MCK_fnmadds, // 'fnmadds'
  MCK_fnmsub, // 'fnmsub'
  MCK_fnmsubs, // 'fnmsubs'
  MCK_fre, // 'fre'
  MCK_fres, // 'fres'
  MCK_frim, // 'frim'
  MCK_frin, // 'frin'
  MCK_frip, // 'frip'
  MCK_friz, // 'friz'
  MCK_frsp, // 'frsp'
  MCK_frsqrte, // 'frsqrte'
  MCK_frsqrtes, // 'frsqrtes'
  MCK_fsel, // 'fsel'
  MCK_fsqrt, // 'fsqrt'
  MCK_fsqrts, // 'fsqrts'
  MCK_fsub, // 'fsub'
  MCK_fsubs, // 'fsubs'
  MCK_icbi, // 'icbi'
  MCK_icbt, // 'icbt'
  MCK_iccci, // 'iccci'
  MCK_ici, // 'ici'
  MCK_inslwi, // 'inslwi'
  MCK_insrdi, // 'insrdi'
  MCK_insrwi, // 'insrwi'
  MCK_isel, // 'isel'
  MCK_isync, // 'isync'
  MCK_la, // 'la'
  MCK_lbarx, // 'lbarx'
  MCK_lbz, // 'lbz'
  MCK_lbzcix, // 'lbzcix'
  MCK_lbzu, // 'lbzu'
  MCK_lbzux, // 'lbzux'
  MCK_lbzx, // 'lbzx'
  MCK_ld, // 'ld'
  MCK_ldarx, // 'ldarx'
  MCK_ldbrx, // 'ldbrx'
  MCK_ldcix, // 'ldcix'
  MCK_ldu, // 'ldu'
  MCK_ldux, // 'ldux'
  MCK_ldx, // 'ldx'
  MCK_lfd, // 'lfd'
  MCK_lfdu, // 'lfdu'
  MCK_lfdux, // 'lfdux'
  MCK_lfdx, // 'lfdx'
  MCK_lfiwax, // 'lfiwax'
  MCK_lfiwzx, // 'lfiwzx'
  MCK_lfs, // 'lfs'
  MCK_lfsu, // 'lfsu'
  MCK_lfsux, // 'lfsux'
  MCK_lfsx, // 'lfsx'
  MCK_lha, // 'lha'
  MCK_lharx, // 'lharx'
  MCK_lhau, // 'lhau'
  MCK_lhaux, // 'lhaux'
  MCK_lhax, // 'lhax'
  MCK_lhbrx, // 'lhbrx'
  MCK_lhz, // 'lhz'
  MCK_lhzcix, // 'lhzcix'
  MCK_lhzu, // 'lhzu'
  MCK_lhzux, // 'lhzux'
  MCK_lhzx, // 'lhzx'
  MCK_li, // 'li'
  MCK_lis, // 'lis'
  MCK_lmw, // 'lmw'
  MCK_lswi, // 'lswi'
  MCK_lvebx, // 'lvebx'
  MCK_lvehx, // 'lvehx'
  MCK_lvewx, // 'lvewx'
  MCK_lvsl, // 'lvsl'
  MCK_lvsr, // 'lvsr'
  MCK_lvx, // 'lvx'
  MCK_lvxl, // 'lvxl'
  MCK_lwa, // 'lwa'
  MCK_lwarx, // 'lwarx'
  MCK_lwaux, // 'lwaux'
  MCK_lwax, // 'lwax'
  MCK_lwbrx, // 'lwbrx'
  MCK_lwsync, // 'lwsync'
  MCK_lwz, // 'lwz'
  MCK_lwzcix, // 'lwzcix'
  MCK_lwzu, // 'lwzu'
  MCK_lwzux, // 'lwzux'
  MCK_lwzx, // 'lwzx'
  MCK_lxsdx, // 'lxsdx'
  MCK_lxsiwax, // 'lxsiwax'
  MCK_lxsiwzx, // 'lxsiwzx'
  MCK_lxsspx, // 'lxsspx'
  MCK_lxvd2x, // 'lxvd2x'
  MCK_lxvdsx, // 'lxvdsx'
  MCK_lxvw4x, // 'lxvw4x'
  MCK_mbar, // 'mbar'
  MCK_mcrf, // 'mcrf'
  MCK_mcrfs, // 'mcrfs'
  MCK_mfamr, // 'mfamr'
  MCK_mfasr, // 'mfasr'
  MCK_mfbhrbe, // 'mfbhrbe'
  MCK_mfbr0, // 'mfbr0'
  MCK_mfbr1, // 'mfbr1'
  MCK_mfbr2, // 'mfbr2'
  MCK_mfbr3, // 'mfbr3'
  MCK_mfbr4, // 'mfbr4'
  MCK_mfbr5, // 'mfbr5'
  MCK_mfbr6, // 'mfbr6'
  MCK_mfbr7, // 'mfbr7'
  MCK_mfcfar, // 'mfcfar'
  MCK_mfcr, // 'mfcr'
  MCK_mfctr, // 'mfctr'
  MCK_mfdar, // 'mfdar'
  MCK_mfdbatl, // 'mfdbatl'
  MCK_mfdbatu, // 'mfdbatu'
  MCK_mfdccr, // 'mfdccr'
  MCK_mfdcr, // 'mfdcr'
  MCK_mfdear, // 'mfdear'
  MCK_mfdec, // 'mfdec'
  MCK_mfdscr, // 'mfdscr'
  MCK_mfdsisr, // 'mfdsisr'
  MCK_mfesr, // 'mfesr'
  MCK_mffs, // 'mffs'
  MCK_mfibatl, // 'mfibatl'
  MCK_mfibatu, // 'mfibatu'
  MCK_mficcr, // 'mficcr'
  MCK_mflr, // 'mflr'
  MCK_mfmsr, // 'mfmsr'
  MCK_mfocrf, // 'mfocrf'
  MCK_mfpid, // 'mfpid'
  MCK_mfpvr, // 'mfpvr'
  MCK_mfrtcl, // 'mfrtcl'
  MCK_mfrtcu, // 'mfrtcu'
  MCK_mfsdr1, // 'mfsdr1'
  MCK_mfspefscr, // 'mfspefscr'
  MCK_mfspr, // 'mfspr'
  MCK_mfsprg, // 'mfsprg'
  MCK_mfsprg0, // 'mfsprg0'
  MCK_mfsprg1, // 'mfsprg1'
  MCK_mfsprg2, // 'mfsprg2'
  MCK_mfsprg3, // 'mfsprg3'
  MCK_mfsprg4, // 'mfsprg4'
  MCK_mfsprg5, // 'mfsprg5'
  MCK_mfsprg6, // 'mfsprg6'
  MCK_mfsprg7, // 'mfsprg7'
  MCK_mfsr, // 'mfsr'
  MCK_mfsrin, // 'mfsrin'
  MCK_mfsrr0, // 'mfsrr0'
  MCK_mfsrr1, // 'mfsrr1'
  MCK_mfsrr2, // 'mfsrr2'
  MCK_mfsrr3, // 'mfsrr3'
  MCK_mftb, // 'mftb'
  MCK_mftbhi, // 'mftbhi'
  MCK_mftbl, // 'mftbl'
  MCK_mftblo, // 'mftblo'
  MCK_mftbu, // 'mftbu'
  MCK_mftcr, // 'mftcr'
  MCK_mfvscr, // 'mfvscr'
  MCK_mfvsrd, // 'mfvsrd'
  MCK_mfvsrwz, // 'mfvsrwz'
  MCK_mfxer, // 'mfxer'
  MCK_mr, // 'mr'
  MCK_msync, // 'msync'
  MCK_mtamr, // 'mtamr'
  MCK_mtasr, // 'mtasr'
  MCK_mtbr0, // 'mtbr0'
  MCK_mtbr1, // 'mtbr1'
  MCK_mtbr2, // 'mtbr2'
  MCK_mtbr3, // 'mtbr3'
  MCK_mtbr4, // 'mtbr4'
  MCK_mtbr5, // 'mtbr5'
  MCK_mtbr6, // 'mtbr6'
  MCK_mtbr7, // 'mtbr7'
  MCK_mtcfar, // 'mtcfar'
  MCK_mtcr, // 'mtcr'
  MCK_mtcrf, // 'mtcrf'
  MCK_mtctr, // 'mtctr'
  MCK_mtdar, // 'mtdar'
  MCK_mtdbatl, // 'mtdbatl'
  MCK_mtdbatu, // 'mtdbatu'
  MCK_mtdccr, // 'mtdccr'
  MCK_mtdcr, // 'mtdcr'
  MCK_mtdear, // 'mtdear'
  MCK_mtdec, // 'mtdec'
  MCK_mtdscr, // 'mtdscr'
  MCK_mtdsisr, // 'mtdsisr'
  MCK_mtesr, // 'mtesr'
  MCK_mtfsb0, // 'mtfsb0'
  MCK_mtfsb1, // 'mtfsb1'
  MCK_mtfsf, // 'mtfsf'
  MCK_mtfsfi, // 'mtfsfi'
  MCK_mtibatl, // 'mtibatl'
  MCK_mtibatu, // 'mtibatu'
  MCK_mticcr, // 'mticcr'
  MCK_mtlr, // 'mtlr'
  MCK_mtmsr, // 'mtmsr'
  MCK_mtmsrd, // 'mtmsrd'
  MCK_mtocrf, // 'mtocrf'
  MCK_mtpid, // 'mtpid'
  MCK_mtsdr1, // 'mtsdr1'
  MCK_mtspefscr, // 'mtspefscr'
  MCK_mtspr, // 'mtspr'
  MCK_mtsprg, // 'mtsprg'
  MCK_mtsprg0, // 'mtsprg0'
  MCK_mtsprg1, // 'mtsprg1'
  MCK_mtsprg2, // 'mtsprg2'
  MCK_mtsprg3, // 'mtsprg3'
  MCK_mtsprg4, // 'mtsprg4'
  MCK_mtsprg5, // 'mtsprg5'
  MCK_mtsprg6, // 'mtsprg6'
  MCK_mtsprg7, // 'mtsprg7'
  MCK_mtsr, // 'mtsr'
  MCK_mtsrin, // 'mtsrin'
  MCK_mtsrr0, // 'mtsrr0'
  MCK_mtsrr1, // 'mtsrr1'
  MCK_mtsrr2, // 'mtsrr2'
  MCK_mtsrr3, // 'mtsrr3'
  MCK_mttbhi, // 'mttbhi'
  MCK_mttbl, // 'mttbl'
  MCK_mttblo, // 'mttblo'
  MCK_mttbu, // 'mttbu'
  MCK_mttcr, // 'mttcr'
  MCK_mtvscr, // 'mtvscr'
  MCK_mtvsrd, // 'mtvsrd'
  MCK_mtvsrwa, // 'mtvsrwa'
  MCK_mtvsrwz, // 'mtvsrwz'
  MCK_mtxer, // 'mtxer'
  MCK_mulhd, // 'mulhd'
  MCK_mulhdu, // 'mulhdu'
  MCK_mulhw, // 'mulhw'
  MCK_mulhwu, // 'mulhwu'
  MCK_mulld, // 'mulld'
  MCK_mulli, // 'mulli'
  MCK_mullw, // 'mullw'
  MCK_nand, // 'nand'
  MCK_neg, // 'neg'
  MCK_nop, // 'nop'
  MCK_nor, // 'nor'
  MCK_not, // 'not'
  MCK_or, // 'or'
  MCK_orc, // 'orc'
  MCK_ori, // 'ori'
  MCK_oris, // 'oris'
  MCK_popcntd, // 'popcntd'
  MCK_popcntw, // 'popcntw'
  MCK_ptesync, // 'ptesync'
  MCK_qvaligni, // 'qvaligni'
  MCK_qvesplati, // 'qvesplati'
  MCK_qvfabs, // 'qvfabs'
  MCK_qvfadd, // 'qvfadd'
  MCK_qvfadds, // 'qvfadds'
  MCK_qvfand, // 'qvfand'
  MCK_qvfandc, // 'qvfandc'
  MCK_qvfcfid, // 'qvfcfid'
  MCK_qvfcfids, // 'qvfcfids'
  MCK_qvfcfidu, // 'qvfcfidu'
  MCK_qvfcfidus, // 'qvfcfidus'
  MCK_qvfclr, // 'qvfclr'
  MCK_qvfcmpeq, // 'qvfcmpeq'
  MCK_qvfcmpgt, // 'qvfcmpgt'
  MCK_qvfcmplt, // 'qvfcmplt'
  MCK_qvfcpsgn, // 'qvfcpsgn'
  MCK_qvfctfb, // 'qvfctfb'
  MCK_qvfctid, // 'qvfctid'
  MCK_qvfctidu, // 'qvfctidu'
  MCK_qvfctiduz, // 'qvfctiduz'
  MCK_qvfctidz, // 'qvfctidz'
  MCK_qvfctiw, // 'qvfctiw'
  MCK_qvfctiwu, // 'qvfctiwu'
  MCK_qvfctiwuz, // 'qvfctiwuz'
  MCK_qvfctiwz, // 'qvfctiwz'
  MCK_qvfequ, // 'qvfequ'
  MCK_qvflogical, // 'qvflogical'
  MCK_qvfmadd, // 'qvfmadd'
  MCK_qvfmadds, // 'qvfmadds'
  MCK_qvfmr, // 'qvfmr'
  MCK_qvfmsub, // 'qvfmsub'
  MCK_qvfmsubs, // 'qvfmsubs'
  MCK_qvfmul, // 'qvfmul'
  MCK_qvfmuls, // 'qvfmuls'
  MCK_qvfnabs, // 'qvfnabs'
  MCK_qvfnand, // 'qvfnand'
  MCK_qvfneg, // 'qvfneg'
  MCK_qvfnmadd, // 'qvfnmadd'
  MCK_qvfnmadds, // 'qvfnmadds'
  MCK_qvfnmsub, // 'qvfnmsub'
  MCK_qvfnmsubs, // 'qvfnmsubs'
  MCK_qvfnor, // 'qvfnor'
  MCK_qvfnot, // 'qvfnot'
  MCK_qvfor, // 'qvfor'
  MCK_qvforc, // 'qvforc'
  MCK_qvfperm, // 'qvfperm'
  MCK_qvfre, // 'qvfre'
  MCK_qvfres, // 'qvfres'
  MCK_qvfrim, // 'qvfrim'
  MCK_qvfrin, // 'qvfrin'
  MCK_qvfrip, // 'qvfrip'
  MCK_qvfriz, // 'qvfriz'
  MCK_qvfrsp, // 'qvfrsp'
  MCK_qvfrsqrte, // 'qvfrsqrte'
  MCK_qvfrsqrtes, // 'qvfrsqrtes'
  MCK_qvfsel, // 'qvfsel'
  MCK_qvfset, // 'qvfset'
  MCK_qvfsub, // 'qvfsub'
  MCK_qvfsubs, // 'qvfsubs'
  MCK_qvftstnan, // 'qvftstnan'
  MCK_qvfxmadd, // 'qvfxmadd'
  MCK_qvfxmadds, // 'qvfxmadds'
  MCK_qvfxmul, // 'qvfxmul'
  MCK_qvfxmuls, // 'qvfxmuls'
  MCK_qvfxor, // 'qvfxor'
  MCK_qvfxxcpnmadd, // 'qvfxxcpnmadd'
  MCK_qvfxxcpnmadds, // 'qvfxxcpnmadds'
  MCK_qvfxxmadd, // 'qvfxxmadd'
  MCK_qvfxxmadds, // 'qvfxxmadds'
  MCK_qvfxxnpmadd, // 'qvfxxnpmadd'
  MCK_qvfxxnpmadds, // 'qvfxxnpmadds'
  MCK_qvgpci, // 'qvgpci'
  MCK_qvlfcdux, // 'qvlfcdux'
  MCK_qvlfcduxa, // 'qvlfcduxa'
  MCK_qvlfcdx, // 'qvlfcdx'
  MCK_qvlfcdxa, // 'qvlfcdxa'
  MCK_qvlfcsux, // 'qvlfcsux'
  MCK_qvlfcsuxa, // 'qvlfcsuxa'
  MCK_qvlfcsx, // 'qvlfcsx'
  MCK_qvlfcsxa, // 'qvlfcsxa'
  MCK_qvlfdux, // 'qvlfdux'
  MCK_qvlfduxa, // 'qvlfduxa'
  MCK_qvlfdx, // 'qvlfdx'
  MCK_qvlfdxa, // 'qvlfdxa'
  MCK_qvlfiwax, // 'qvlfiwax'
  MCK_qvlfiwaxa, // 'qvlfiwaxa'
  MCK_qvlfiwzx, // 'qvlfiwzx'
  MCK_qvlfiwzxa, // 'qvlfiwzxa'
  MCK_qvlfsux, // 'qvlfsux'
  MCK_qvlfsuxa, // 'qvlfsuxa'
  MCK_qvlfsx, // 'qvlfsx'
  MCK_qvlfsxa, // 'qvlfsxa'
  MCK_qvlpcldx, // 'qvlpcldx'
  MCK_qvlpclsx, // 'qvlpclsx'
  MCK_qvlpcrdx, // 'qvlpcrdx'
  MCK_qvlpcrsx, // 'qvlpcrsx'
  MCK_qvstfcdux, // 'qvstfcdux'
  MCK_qvstfcduxa, // 'qvstfcduxa'
  MCK_qvstfcduxi, // 'qvstfcduxi'
  MCK_qvstfcduxia, // 'qvstfcduxia'
  MCK_qvstfcdx, // 'qvstfcdx'
  MCK_qvstfcdxa, // 'qvstfcdxa'
  MCK_qvstfcdxi, // 'qvstfcdxi'
  MCK_qvstfcdxia, // 'qvstfcdxia'
  MCK_qvstfcsux, // 'qvstfcsux'
  MCK_qvstfcsuxa, // 'qvstfcsuxa'
  MCK_qvstfcsuxi, // 'qvstfcsuxi'
  MCK_qvstfcsuxia, // 'qvstfcsuxia'
  MCK_qvstfcsx, // 'qvstfcsx'
  MCK_qvstfcsxa, // 'qvstfcsxa'
  MCK_qvstfcsxi, // 'qvstfcsxi'
  MCK_qvstfcsxia, // 'qvstfcsxia'
  MCK_qvstfdux, // 'qvstfdux'
  MCK_qvstfduxa, // 'qvstfduxa'
  MCK_qvstfduxi, // 'qvstfduxi'
  MCK_qvstfduxia, // 'qvstfduxia'
  MCK_qvstfdx, // 'qvstfdx'
  MCK_qvstfdxa, // 'qvstfdxa'
  MCK_qvstfdxi, // 'qvstfdxi'
  MCK_qvstfdxia, // 'qvstfdxia'
  MCK_qvstfiwx, // 'qvstfiwx'
  MCK_qvstfiwxa, // 'qvstfiwxa'
  MCK_qvstfsux, // 'qvstfsux'
  MCK_qvstfsuxa, // 'qvstfsuxa'
  MCK_qvstfsuxi, // 'qvstfsuxi'
  MCK_qvstfsuxia, // 'qvstfsuxia'
  MCK_qvstfsx, // 'qvstfsx'
  MCK_qvstfsxa, // 'qvstfsxa'
  MCK_qvstfsxi, // 'qvstfsxi'
  MCK_qvstfsxia, // 'qvstfsxia'
  MCK_rfci, // 'rfci'
  MCK_rfdi, // 'rfdi'
  MCK_rfebb, // 'rfebb'
  MCK_rfi, // 'rfi'
  MCK_rfid, // 'rfid'
  MCK_rfmci, // 'rfmci'
  MCK_rldcl, // 'rldcl'
  MCK_rldcr, // 'rldcr'
  MCK_rldic, // 'rldic'
  MCK_rldicl, // 'rldicl'
  MCK_rldicr, // 'rldicr'
  MCK_rldimi, // 'rldimi'
  MCK_rlwimi, // 'rlwimi'
  MCK_rlwinm, // 'rlwinm'
  MCK_rlwnm, // 'rlwnm'
  MCK_rotld, // 'rotld'
  MCK_rotldi, // 'rotldi'
  MCK_rotlw, // 'rotlw'
  MCK_rotlwi, // 'rotlwi'
  MCK_rotrdi, // 'rotrdi'
  MCK_rotrwi, // 'rotrwi'
  MCK_sc, // 'sc'
  MCK_slbia, // 'slbia'
  MCK_slbie, // 'slbie'
  MCK_slbmfee, // 'slbmfee'
  MCK_slbmte, // 'slbmte'
  MCK_sld, // 'sld'
  MCK_sldi, // 'sldi'
  MCK_slw, // 'slw'
  MCK_slwi, // 'slwi'
  MCK_srad, // 'srad'
  MCK_sradi, // 'sradi'
  MCK_sraw, // 'sraw'
  MCK_srawi, // 'srawi'
  MCK_srd, // 'srd'
  MCK_srdi, // 'srdi'
  MCK_srw, // 'srw'
  MCK_srwi, // 'srwi'
  MCK_stb, // 'stb'
  MCK_stbcix, // 'stbcix'
  MCK_stbcx, // 'stbcx'
  MCK_stbu, // 'stbu'
  MCK_stbux, // 'stbux'
  MCK_stbx, // 'stbx'
  MCK_std, // 'std'
  MCK_stdbrx, // 'stdbrx'
  MCK_stdcix, // 'stdcix'
  MCK_stdcx, // 'stdcx'
  MCK_stdu, // 'stdu'
  MCK_stdux, // 'stdux'
  MCK_stdx, // 'stdx'
  MCK_stfd, // 'stfd'
  MCK_stfdu, // 'stfdu'
  MCK_stfdux, // 'stfdux'
  MCK_stfdx, // 'stfdx'
  MCK_stfiwx, // 'stfiwx'
  MCK_stfs, // 'stfs'
  MCK_stfsu, // 'stfsu'
  MCK_stfsux, // 'stfsux'
  MCK_stfsx, // 'stfsx'
  MCK_sth, // 'sth'
  MCK_sthbrx, // 'sthbrx'
  MCK_sthcix, // 'sthcix'
  MCK_sthcx, // 'sthcx'
  MCK_sthu, // 'sthu'
  MCK_sthux, // 'sthux'
  MCK_sthx, // 'sthx'
  MCK_stmw, // 'stmw'
  MCK_stswi, // 'stswi'
  MCK_stvebx, // 'stvebx'
  MCK_stvehx, // 'stvehx'
  MCK_stvewx, // 'stvewx'
  MCK_stvx, // 'stvx'
  MCK_stvxl, // 'stvxl'
  MCK_stw, // 'stw'
  MCK_stwbrx, // 'stwbrx'
  MCK_stwcix, // 'stwcix'
  MCK_stwcx, // 'stwcx'
  MCK_stwu, // 'stwu'
  MCK_stwux, // 'stwux'
  MCK_stwx, // 'stwx'
  MCK_stxsdx, // 'stxsdx'
  MCK_stxsiwx, // 'stxsiwx'
  MCK_stxsspx, // 'stxsspx'
  MCK_stxvd2x, // 'stxvd2x'
  MCK_stxvw4x, // 'stxvw4x'
  MCK_sub, // 'sub'
  MCK_subc, // 'subc'
  MCK_subf, // 'subf'
  MCK_subfc, // 'subfc'
  MCK_subfe, // 'subfe'
  MCK_subfic, // 'subfic'
  MCK_subfme, // 'subfme'
  MCK_subfze, // 'subfze'
  MCK_subi, // 'subi'
  MCK_subic, // 'subic'
  MCK_subis, // 'subis'
  MCK_sync, // 'sync'
  MCK_tabort, // 'tabort'
  MCK_tabortdc, // 'tabortdc'
  MCK_tabortdci, // 'tabortdci'
  MCK_tabortwc, // 'tabortwc'
  MCK_tabortwci, // 'tabortwci'
  MCK_tbegin, // 'tbegin'
  MCK_tcheck, // 'tcheck'
  MCK_td, // 'td'
  MCK_tdeq, // 'tdeq'
  MCK_tdeqi, // 'tdeqi'
  MCK_tdge, // 'tdge'
  MCK_tdgei, // 'tdgei'
  MCK_tdgt, // 'tdgt'
  MCK_tdgti, // 'tdgti'
  MCK_tdi, // 'tdi'
  MCK_tdle, // 'tdle'
  MCK_tdlei, // 'tdlei'
  MCK_tdlge, // 'tdlge'
  MCK_tdlgei, // 'tdlgei'
  MCK_tdlgt, // 'tdlgt'
  MCK_tdlgti, // 'tdlgti'
  MCK_tdlle, // 'tdlle'
  MCK_tdllei, // 'tdllei'
  MCK_tdllt, // 'tdllt'
  MCK_tdllti, // 'tdllti'
  MCK_tdlng, // 'tdlng'
  MCK_tdlngi, // 'tdlngi'
  MCK_tdlnl, // 'tdlnl'
  MCK_tdlnli, // 'tdlnli'
  MCK_tdlt, // 'tdlt'
  MCK_tdlti, // 'tdlti'
  MCK_tdne, // 'tdne'
  MCK_tdnei, // 'tdnei'
  MCK_tdng, // 'tdng'
  MCK_tdngi, // 'tdngi'
  MCK_tdnl, // 'tdnl'
  MCK_tdnli, // 'tdnli'
  MCK_tdu, // 'tdu'
  MCK_tdui, // 'tdui'
  MCK_tend, // 'tend'
  MCK_tlbia, // 'tlbia'
  MCK_tlbie, // 'tlbie'
  MCK_tlbiel, // 'tlbiel'
  MCK_tlbivax, // 'tlbivax'
  MCK_tlbld, // 'tlbld'
  MCK_tlbli, // 'tlbli'
  MCK_tlbre, // 'tlbre'
  MCK_tlbrehi, // 'tlbrehi'
  MCK_tlbrelo, // 'tlbrelo'
  MCK_tlbsx, // 'tlbsx'
  MCK_tlbsync, // 'tlbsync'
  MCK_tlbwe, // 'tlbwe'
  MCK_tlbwehi, // 'tlbwehi'
  MCK_tlbwelo, // 'tlbwelo'
  MCK_trap, // 'trap'
  MCK_trechkpt, // 'trechkpt'
  MCK_treclaim, // 'treclaim'
  MCK_tsr, // 'tsr'
  MCK_tw, // 'tw'
  MCK_tweq, // 'tweq'
  MCK_tweqi, // 'tweqi'
  MCK_twge, // 'twge'
  MCK_twgei, // 'twgei'
  MCK_twgt, // 'twgt'
  MCK_twgti, // 'twgti'
  MCK_twi, // 'twi'
  MCK_twle, // 'twle'
  MCK_twlei, // 'twlei'
  MCK_twlge, // 'twlge'
  MCK_twlgei, // 'twlgei'
  MCK_twlgt, // 'twlgt'
  MCK_twlgti, // 'twlgti'
  MCK_twlle, // 'twlle'
  MCK_twllei, // 'twllei'
  MCK_twllt, // 'twllt'
  MCK_twllti, // 'twllti'
  MCK_twlng, // 'twlng'
  MCK_twlngi, // 'twlngi'
  MCK_twlnl, // 'twlnl'
  MCK_twlnli, // 'twlnli'
  MCK_twlt, // 'twlt'
  MCK_twlti, // 'twlti'
  MCK_twne, // 'twne'
  MCK_twnei, // 'twnei'
  MCK_twng, // 'twng'
  MCK_twngi, // 'twngi'
  MCK_twnl, // 'twnl'
  MCK_twnli, // 'twnli'
  MCK_twu, // 'twu'
  MCK_twui, // 'twui'
  MCK_vaddcuq, // 'vaddcuq'
  MCK_vaddcuw, // 'vaddcuw'
  MCK_vaddecuq, // 'vaddecuq'
  MCK_vaddeuqm, // 'vaddeuqm'
  MCK_vaddfp, // 'vaddfp'
  MCK_vaddsbs, // 'vaddsbs'
  MCK_vaddshs, // 'vaddshs'
  MCK_vaddsws, // 'vaddsws'
  MCK_vaddubm, // 'vaddubm'
  MCK_vaddubs, // 'vaddubs'
  MCK_vaddudm, // 'vaddudm'
  MCK_vadduhm, // 'vadduhm'
  MCK_vadduhs, // 'vadduhs'
  MCK_vadduqm, // 'vadduqm'
  MCK_vadduwm, // 'vadduwm'
  MCK_vadduws, // 'vadduws'
  MCK_vand, // 'vand'
  MCK_vandc, // 'vandc'
  MCK_vavgsb, // 'vavgsb'
  MCK_vavgsh, // 'vavgsh'
  MCK_vavgsw, // 'vavgsw'
  MCK_vavgub, // 'vavgub'
  MCK_vavguh, // 'vavguh'
  MCK_vavguw, // 'vavguw'
  MCK_vbpermq, // 'vbpermq'
  MCK_vcfsx, // 'vcfsx'
  MCK_vcfux, // 'vcfux'
  MCK_vcipher, // 'vcipher'
  MCK_vcipherlast, // 'vcipherlast'
  MCK_vclzb, // 'vclzb'
  MCK_vclzd, // 'vclzd'
  MCK_vclzh, // 'vclzh'
  MCK_vclzw, // 'vclzw'
  MCK_vcmpbfp, // 'vcmpbfp'
  MCK_vcmpeqfp, // 'vcmpeqfp'
  MCK_vcmpequb, // 'vcmpequb'
  MCK_vcmpequd, // 'vcmpequd'
  MCK_vcmpequh, // 'vcmpequh'
  MCK_vcmpequw, // 'vcmpequw'
  MCK_vcmpgefp, // 'vcmpgefp'
  MCK_vcmpgtfp, // 'vcmpgtfp'
  MCK_vcmpgtsb, // 'vcmpgtsb'
  MCK_vcmpgtsd, // 'vcmpgtsd'
  MCK_vcmpgtsh, // 'vcmpgtsh'
  MCK_vcmpgtsw, // 'vcmpgtsw'
  MCK_vcmpgtub, // 'vcmpgtub'
  MCK_vcmpgtud, // 'vcmpgtud'
  MCK_vcmpgtuh, // 'vcmpgtuh'
  MCK_vcmpgtuw, // 'vcmpgtuw'
  MCK_vctsxs, // 'vctsxs'
  MCK_vctuxs, // 'vctuxs'
  MCK_veqv, // 'veqv'
  MCK_vexptefp, // 'vexptefp'
  MCK_vgbbd, // 'vgbbd'
  MCK_vlogefp, // 'vlogefp'
  MCK_vmaddfp, // 'vmaddfp'
  MCK_vmaxfp, // 'vmaxfp'
  MCK_vmaxsb, // 'vmaxsb'
  MCK_vmaxsd, // 'vmaxsd'
  MCK_vmaxsh, // 'vmaxsh'
  MCK_vmaxsw, // 'vmaxsw'
  MCK_vmaxub, // 'vmaxub'
  MCK_vmaxud, // 'vmaxud'
  MCK_vmaxuh, // 'vmaxuh'
  MCK_vmaxuw, // 'vmaxuw'
  MCK_vmhaddshs, // 'vmhaddshs'
  MCK_vmhraddshs, // 'vmhraddshs'
  MCK_vminfp, // 'vminfp'
  MCK_vminsb, // 'vminsb'
  MCK_vminsd, // 'vminsd'
  MCK_vminsh, // 'vminsh'
  MCK_vminsw, // 'vminsw'
  MCK_vminub, // 'vminub'
  MCK_vminud, // 'vminud'
  MCK_vminuh, // 'vminuh'
  MCK_vminuw, // 'vminuw'
  MCK_vmladduhm, // 'vmladduhm'
  MCK_vmrgew, // 'vmrgew'
  MCK_vmrghb, // 'vmrghb'
  MCK_vmrghh, // 'vmrghh'
  MCK_vmrghw, // 'vmrghw'
  MCK_vmrglb, // 'vmrglb'
  MCK_vmrglh, // 'vmrglh'
  MCK_vmrglw, // 'vmrglw'
  MCK_vmrgow, // 'vmrgow'
  MCK_vmsummbm, // 'vmsummbm'
  MCK_vmsumshm, // 'vmsumshm'
  MCK_vmsumshs, // 'vmsumshs'
  MCK_vmsumubm, // 'vmsumubm'
  MCK_vmsumuhm, // 'vmsumuhm'
  MCK_vmsumuhs, // 'vmsumuhs'
  MCK_vmulesb, // 'vmulesb'
  MCK_vmulesh, // 'vmulesh'
  MCK_vmulesw, // 'vmulesw'
  MCK_vmuleub, // 'vmuleub'
  MCK_vmuleuh, // 'vmuleuh'
  MCK_vmuleuw, // 'vmuleuw'
  MCK_vmulosb, // 'vmulosb'
  MCK_vmulosh, // 'vmulosh'
  MCK_vmulosw, // 'vmulosw'
  MCK_vmuloub, // 'vmuloub'
  MCK_vmulouh, // 'vmulouh'
  MCK_vmulouw, // 'vmulouw'
  MCK_vmuluwm, // 'vmuluwm'
  MCK_vnand, // 'vnand'
  MCK_vncipher, // 'vncipher'
  MCK_vncipherlast, // 'vncipherlast'
  MCK_vnmsubfp, // 'vnmsubfp'
  MCK_vnor, // 'vnor'
  MCK_vor, // 'vor'
  MCK_vorc, // 'vorc'
  MCK_vperm, // 'vperm'
  MCK_vpermxor, // 'vpermxor'
  MCK_vpkpx, // 'vpkpx'
  MCK_vpksdss, // 'vpksdss'
  MCK_vpksdus, // 'vpksdus'
  MCK_vpkshss, // 'vpkshss'
  MCK_vpkshus, // 'vpkshus'
  MCK_vpkswss, // 'vpkswss'
  MCK_vpkswus, // 'vpkswus'
  MCK_vpkudum, // 'vpkudum'
  MCK_vpkudus, // 'vpkudus'
  MCK_vpkuhum, // 'vpkuhum'
  MCK_vpkuhus, // 'vpkuhus'
  MCK_vpkuwum, // 'vpkuwum'
  MCK_vpkuwus, // 'vpkuwus'
  MCK_vpmsumb, // 'vpmsumb'
  MCK_vpmsumd, // 'vpmsumd'
  MCK_vpmsumh, // 'vpmsumh'
  MCK_vpmsumw, // 'vpmsumw'
  MCK_vpopcntb, // 'vpopcntb'
  MCK_vpopcntd, // 'vpopcntd'
  MCK_vpopcnth, // 'vpopcnth'
  MCK_vpopcntw, // 'vpopcntw'
  MCK_vrefp, // 'vrefp'
  MCK_vrfim, // 'vrfim'
  MCK_vrfin, // 'vrfin'
  MCK_vrfip, // 'vrfip'
  MCK_vrfiz, // 'vrfiz'
  MCK_vrlb, // 'vrlb'
  MCK_vrld, // 'vrld'
  MCK_vrlh, // 'vrlh'
  MCK_vrlw, // 'vrlw'
  MCK_vrsqrtefp, // 'vrsqrtefp'
  MCK_vsbox, // 'vsbox'
  MCK_vsel, // 'vsel'
  MCK_vshasigmad, // 'vshasigmad'
  MCK_vshasigmaw, // 'vshasigmaw'
  MCK_vsl, // 'vsl'
  MCK_vslb, // 'vslb'
  MCK_vsld, // 'vsld'
  MCK_vsldoi, // 'vsldoi'
  MCK_vslh, // 'vslh'
  MCK_vslo, // 'vslo'
  MCK_vslw, // 'vslw'
  MCK_vspltb, // 'vspltb'
  MCK_vsplth, // 'vsplth'
  MCK_vspltisb, // 'vspltisb'
  MCK_vspltish, // 'vspltish'
  MCK_vspltisw, // 'vspltisw'
  MCK_vspltw, // 'vspltw'
  MCK_vsr, // 'vsr'
  MCK_vsrab, // 'vsrab'
  MCK_vsrad, // 'vsrad'
  MCK_vsrah, // 'vsrah'
  MCK_vsraw, // 'vsraw'
  MCK_vsrb, // 'vsrb'
  MCK_vsrd, // 'vsrd'
  MCK_vsrh, // 'vsrh'
  MCK_vsro, // 'vsro'
  MCK_vsrw, // 'vsrw'
  MCK_vsubcuq, // 'vsubcuq'
  MCK_vsubcuw, // 'vsubcuw'
  MCK_vsubecuq, // 'vsubecuq'
  MCK_vsubeuqm, // 'vsubeuqm'
  MCK_vsubfp, // 'vsubfp'
  MCK_vsubsbs, // 'vsubsbs'
  MCK_vsubshs, // 'vsubshs'
  MCK_vsubsws, // 'vsubsws'
  MCK_vsububm, // 'vsububm'
  MCK_vsububs, // 'vsububs'
  MCK_vsubudm, // 'vsubudm'
  MCK_vsubuhm, // 'vsubuhm'
  MCK_vsubuhs, // 'vsubuhs'
  MCK_vsubuqm, // 'vsubuqm'
  MCK_vsubuwm, // 'vsubuwm'
  MCK_vsubuws, // 'vsubuws'
  MCK_vsum2sws, // 'vsum2sws'
  MCK_vsum4sbs, // 'vsum4sbs'
  MCK_vsum4shs, // 'vsum4shs'
  MCK_vsum4ubs, // 'vsum4ubs'
  MCK_vsumsws, // 'vsumsws'
  MCK_vupkhpx, // 'vupkhpx'
  MCK_vupkhsb, // 'vupkhsb'
  MCK_vupkhsh, // 'vupkhsh'
  MCK_vupkhsw, // 'vupkhsw'
  MCK_vupklpx, // 'vupklpx'
  MCK_vupklsb, // 'vupklsb'
  MCK_vupklsh, // 'vupklsh'
  MCK_vupklsw, // 'vupklsw'
  MCK_vxor, // 'vxor'
  MCK_wait, // 'wait'
  MCK_waitimpl, // 'waitimpl'
  MCK_waitrsv, // 'waitrsv'
  MCK_wrtee, // 'wrtee'
  MCK_wrteei, // 'wrteei'
  MCK_xnop, // 'xnop'
  MCK_xor, // 'xor'
  MCK_xori, // 'xori'
  MCK_xoris, // 'xoris'
  MCK_xsabsdp, // 'xsabsdp'
  MCK_xsadddp, // 'xsadddp'
  MCK_xsaddsp, // 'xsaddsp'
  MCK_xscmpodp, // 'xscmpodp'
  MCK_xscmpudp, // 'xscmpudp'
  MCK_xscpsgndp, // 'xscpsgndp'
  MCK_xscvdpsp, // 'xscvdpsp'
  MCK_xscvdpspn, // 'xscvdpspn'
  MCK_xscvdpsxds, // 'xscvdpsxds'
  MCK_xscvdpsxws, // 'xscvdpsxws'
  MCK_xscvdpuxds, // 'xscvdpuxds'
  MCK_xscvdpuxws, // 'xscvdpuxws'
  MCK_xscvspdp, // 'xscvspdp'
  MCK_xscvspdpn, // 'xscvspdpn'
  MCK_xscvsxddp, // 'xscvsxddp'
  MCK_xscvsxdsp, // 'xscvsxdsp'
  MCK_xscvuxddp, // 'xscvuxddp'
  MCK_xscvuxdsp, // 'xscvuxdsp'
  MCK_xsdivdp, // 'xsdivdp'
  MCK_xsdivsp, // 'xsdivsp'
  MCK_xsmaddadp, // 'xsmaddadp'
  MCK_xsmaddasp, // 'xsmaddasp'
  MCK_xsmaddmdp, // 'xsmaddmdp'
  MCK_xsmaddmsp, // 'xsmaddmsp'
  MCK_xsmaxdp, // 'xsmaxdp'
  MCK_xsmindp, // 'xsmindp'
  MCK_xsmsubadp, // 'xsmsubadp'
  MCK_xsmsubasp, // 'xsmsubasp'
  MCK_xsmsubmdp, // 'xsmsubmdp'
  MCK_xsmsubmsp, // 'xsmsubmsp'
  MCK_xsmuldp, // 'xsmuldp'
  MCK_xsmulsp, // 'xsmulsp'
  MCK_xsnabsdp, // 'xsnabsdp'
  MCK_xsnegdp, // 'xsnegdp'
  MCK_xsnmaddadp, // 'xsnmaddadp'
  MCK_xsnmaddasp, // 'xsnmaddasp'
  MCK_xsnmaddmdp, // 'xsnmaddmdp'
  MCK_xsnmaddmsp, // 'xsnmaddmsp'
  MCK_xsnmsubadp, // 'xsnmsubadp'
  MCK_xsnmsubasp, // 'xsnmsubasp'
  MCK_xsnmsubmdp, // 'xsnmsubmdp'
  MCK_xsnmsubmsp, // 'xsnmsubmsp'
  MCK_xsrdpi, // 'xsrdpi'
  MCK_xsrdpic, // 'xsrdpic'
  MCK_xsrdpim, // 'xsrdpim'
  MCK_xsrdpip, // 'xsrdpip'
  MCK_xsrdpiz, // 'xsrdpiz'
  MCK_xsredp, // 'xsredp'
  MCK_xsresp, // 'xsresp'
  MCK_xsrsqrtedp, // 'xsrsqrtedp'
  MCK_xsrsqrtesp, // 'xsrsqrtesp'
  MCK_xssqrtdp, // 'xssqrtdp'
  MCK_xssqrtsp, // 'xssqrtsp'
  MCK_xssubdp, // 'xssubdp'
  MCK_xssubsp, // 'xssubsp'
  MCK_xstdivdp, // 'xstdivdp'
  MCK_xstsqrtdp, // 'xstsqrtdp'
  MCK_xvabsdp, // 'xvabsdp'
  MCK_xvabssp, // 'xvabssp'
  MCK_xvadddp, // 'xvadddp'
  MCK_xvaddsp, // 'xvaddsp'
  MCK_xvcmpeqdp, // 'xvcmpeqdp'
  MCK_xvcmpeqsp, // 'xvcmpeqsp'
  MCK_xvcmpgedp, // 'xvcmpgedp'
  MCK_xvcmpgesp, // 'xvcmpgesp'
  MCK_xvcmpgtdp, // 'xvcmpgtdp'
  MCK_xvcmpgtsp, // 'xvcmpgtsp'
  MCK_xvcpsgndp, // 'xvcpsgndp'
  MCK_xvcpsgnsp, // 'xvcpsgnsp'
  MCK_xvcvdpsp, // 'xvcvdpsp'
  MCK_xvcvdpsxds, // 'xvcvdpsxds'
  MCK_xvcvdpsxws, // 'xvcvdpsxws'
  MCK_xvcvdpuxds, // 'xvcvdpuxds'
  MCK_xvcvdpuxws, // 'xvcvdpuxws'
  MCK_xvcvspdp, // 'xvcvspdp'
  MCK_xvcvspsxds, // 'xvcvspsxds'
  MCK_xvcvspsxws, // 'xvcvspsxws'
  MCK_xvcvspuxds, // 'xvcvspuxds'
  MCK_xvcvspuxws, // 'xvcvspuxws'
  MCK_xvcvsxddp, // 'xvcvsxddp'
  MCK_xvcvsxdsp, // 'xvcvsxdsp'
  MCK_xvcvsxwdp, // 'xvcvsxwdp'
  MCK_xvcvsxwsp, // 'xvcvsxwsp'
  MCK_xvcvuxddp, // 'xvcvuxddp'
  MCK_xvcvuxdsp, // 'xvcvuxdsp'
  MCK_xvcvuxwdp, // 'xvcvuxwdp'
  MCK_xvcvuxwsp, // 'xvcvuxwsp'
  MCK_xvdivdp, // 'xvdivdp'
  MCK_xvdivsp, // 'xvdivsp'
  MCK_xvmaddadp, // 'xvmaddadp'
  MCK_xvmaddasp, // 'xvmaddasp'
  MCK_xvmaddmdp, // 'xvmaddmdp'
  MCK_xvmaddmsp, // 'xvmaddmsp'
  MCK_xvmaxdp, // 'xvmaxdp'
  MCK_xvmaxsp, // 'xvmaxsp'
  MCK_xvmindp, // 'xvmindp'
  MCK_xvminsp, // 'xvminsp'
  MCK_xvmovdp, // 'xvmovdp'
  MCK_xvmovsp, // 'xvmovsp'
  MCK_xvmsubadp, // 'xvmsubadp'
  MCK_xvmsubasp, // 'xvmsubasp'
  MCK_xvmsubmdp, // 'xvmsubmdp'
  MCK_xvmsubmsp, // 'xvmsubmsp'
  MCK_xvmuldp, // 'xvmuldp'
  MCK_xvmulsp, // 'xvmulsp'
  MCK_xvnabsdp, // 'xvnabsdp'
  MCK_xvnabssp, // 'xvnabssp'
  MCK_xvnegdp, // 'xvnegdp'
  MCK_xvnegsp, // 'xvnegsp'
  MCK_xvnmaddadp, // 'xvnmaddadp'
  MCK_xvnmaddasp, // 'xvnmaddasp'
  MCK_xvnmaddmdp, // 'xvnmaddmdp'
  MCK_xvnmaddmsp, // 'xvnmaddmsp'
  MCK_xvnmsubadp, // 'xvnmsubadp'
  MCK_xvnmsubasp, // 'xvnmsubasp'
  MCK_xvnmsubmdp, // 'xvnmsubmdp'
  MCK_xvnmsubmsp, // 'xvnmsubmsp'
  MCK_xvrdpi, // 'xvrdpi'
  MCK_xvrdpic, // 'xvrdpic'
  MCK_xvrdpim, // 'xvrdpim'
  MCK_xvrdpip, // 'xvrdpip'
  MCK_xvrdpiz, // 'xvrdpiz'
  MCK_xvredp, // 'xvredp'
  MCK_xvresp, // 'xvresp'
  MCK_xvrspi, // 'xvrspi'
  MCK_xvrspic, // 'xvrspic'
  MCK_xvrspim, // 'xvrspim'
  MCK_xvrspip, // 'xvrspip'
  MCK_xvrspiz, // 'xvrspiz'
  MCK_xvrsqrtedp, // 'xvrsqrtedp'
  MCK_xvrsqrtesp, // 'xvrsqrtesp'
  MCK_xvsqrtdp, // 'xvsqrtdp'
  MCK_xvsqrtsp, // 'xvsqrtsp'
  MCK_xvsubdp, // 'xvsubdp'
  MCK_xvsubsp, // 'xvsubsp'
  MCK_xvtdivdp, // 'xvtdivdp'
  MCK_xvtdivsp, // 'xvtdivsp'
  MCK_xvtsqrtdp, // 'xvtsqrtdp'
  MCK_xvtsqrtsp, // 'xvtsqrtsp'
  MCK_xxland, // 'xxland'
  MCK_xxlandc, // 'xxlandc'
  MCK_xxleqv, // 'xxleqv'
  MCK_xxlnand, // 'xxlnand'
  MCK_xxlnor, // 'xxlnor'
  MCK_xxlor, // 'xxlor'
  MCK_xxlorc, // 'xxlorc'
  MCK_xxlxor, // 'xxlxor'
  MCK_xxmrghd, // 'xxmrghd'
  MCK_xxmrghw, // 'xxmrghw'
  MCK_xxmrgld, // 'xxmrgld'
  MCK_xxmrglw, // 'xxmrglw'
  MCK_xxpermdi, // 'xxpermdi'
  MCK_xxsel, // 'xxsel'
  MCK_xxsldwi, // 'xxsldwi'
  MCK_xxspltd, // 'xxspltd'
  MCK_xxspltw, // 'xxspltw'
  MCK_xxswapd, // 'xxswapd'
  MCK_Reg2, // derived register class
  MCK_GPRC, // register class 'GPRC'
  MCK_GPRC_NOR0, // register class 'GPRC_NOR0'
  MCK_Reg5, // derived register class
  MCK_G8RC, // register class 'G8RC'
  MCK_G8RC_NOX0, // register class 'G8RC_NOX0'
  MCK_F4RC, // register class 'F4RC,F8RC'
  MCK_VFRC, // register class 'VFRC'
  MCK_VSSRC, // register class 'VSSRC,VSFRC'
  MCK_QSRC, // register class 'QSRC,QBRC,QFRC'
  MCK_VRRC, // register class 'VRRC'
  MCK_VSLRC, // register class 'VSLRC'
  MCK_VSHRC, // register class 'VSHRC'
  MCK_VSRC, // register class 'VSRC'
  MCK_CRBITRC, // register class 'CRBITRC'
  MCK_CRRC0, // register class 'CRRC0'
  MCK_CRRC, // register class 'CRRC'
  MCK_CTRRC, // register class 'CTRRC'
  MCK_CTRRC8, // register class 'CTRRC8'
  MCK_VRSAVERC, // register class 'VRSAVERC'
  MCK_CARRYRC, // register class 'CARRYRC'
  MCK_Imm, // user defined class 'ImmAsmOperand'
  MCK_CRBitMask, // user defined class 'PPCCRBitMaskOperand'
  MCK_CondBr, // user defined class 'PPCCondBrAsmOperand'
  MCK_DirectBr, // user defined class 'PPCDirectBrAsmOperand'
  MCK_DispRI, // user defined class 'PPCDispRIOperand'
  MCK_DispRIX, // user defined class 'PPCDispRIXOperand'
  MCK_DispSPE2, // user defined class 'PPCDispSPE2Operand'
  MCK_DispSPE4, // user defined class 'PPCDispSPE4Operand'
  MCK_DispSPE8, // user defined class 'PPCDispSPE8Operand'
  MCK_RegCRBITRC, // user defined class 'PPCRegCRBITRCAsmOperand'
  MCK_RegCRRC, // user defined class 'PPCRegCRRCAsmOperand'
  MCK_RegF4RC, // user defined class 'PPCRegF4RCAsmOperand'
  MCK_RegF8RC, // user defined class 'PPCRegF8RCAsmOperand'
  MCK_RegG8RC, // user defined class 'PPCRegG8RCAsmOperand'
  MCK_RegG8RCNoX0, // user defined class 'PPCRegG8RCNoX0AsmOperand'
  MCK_RegGPRC, // user defined class 'PPCRegGPRCAsmOperand'
  MCK_RegGPRCNoR0, // user defined class 'PPCRegGPRCNoR0AsmOperand'
  MCK_RegGxRCNoR0, // user defined class 'PPCRegGxRCNoR0Operand'
  MCK_RegGxRC, // user defined class 'PPCRegGxRCOperand'
  MCK_RegQBRC, // user defined class 'PPCRegQBRCAsmOperand'
  MCK_RegQFRC, // user defined class 'PPCRegQFRCAsmOperand'
  MCK_RegQSRC, // user defined class 'PPCRegQSRCAsmOperand'
  MCK_RegVRRC, // user defined class 'PPCRegVRRCAsmOperand'
  MCK_RegVSFRC, // user defined class 'PPCRegVSFRCAsmOperand'
  MCK_RegVSRC, // user defined class 'PPCRegVSRCAsmOperand'
  MCK_RegVSSRC, // user defined class 'PPCRegVSSRCAsmOperand'
  MCK_S16Imm, // user defined class 'PPCS16ImmAsmOperand'
  MCK_S17Imm, // user defined class 'PPCS17ImmAsmOperand'
  MCK_S5Imm, // user defined class 'PPCS5ImmAsmOperand'
  MCK_TLSReg, // user defined class 'PPCTLSRegOperand'
  MCK_U10Imm, // user defined class 'PPCU10ImmAsmOperand'
  MCK_U12Imm, // user defined class 'PPCU12ImmAsmOperand'
  MCK_U16Imm, // user defined class 'PPCU16ImmAsmOperand'
  MCK_U1Imm, // user defined class 'PPCU1ImmAsmOperand'
  MCK_U2Imm, // user defined class 'PPCU2ImmAsmOperand'
  MCK_U3Imm, // user defined class 'PPCU3ImmAsmOperand'
  MCK_U4Imm, // user defined class 'PPCU4ImmAsmOperand'
  MCK_U5Imm, // user defined class 'PPCU5ImmAsmOperand'
  MCK_U6Imm, // user defined class 'PPCU6ImmAsmOperand'
  NumMatchClassKinds
};

}

static MatchClassKind matchTokenString(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 1:	 // 10 strings to match.
    switch (Name[0]) {
    default: break;
    case '.':	 // 1 string to match.
      return MCK__DOT_;	 // "."
    case '0':	 // 1 string to match.
      return MCK_0;	 // "0"
    case '1':	 // 1 string to match.
      return MCK_1;	 // "1"
    case '2':	 // 1 string to match.
      return MCK_2;	 // "2"
    case '3':	 // 1 string to match.
      return MCK_3;	 // "3"
    case '4':	 // 1 string to match.
      return MCK_4;	 // "4"
    case '5':	 // 1 string to match.
      return MCK_5;	 // "5"
    case '6':	 // 1 string to match.
      return MCK_6;	 // "6"
    case '7':	 // 1 string to match.
      return MCK_7;	 // "7"
    case 'b':	 // 1 string to match.
      return MCK_b;	 // "b"
    }
    break;
  case 2:	 // 13 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        return MCK_ba;	 // "ba"
      case 'c':	 // 1 string to match.
        return MCK_bc;	 // "bc"
      case 'f':	 // 1 string to match.
        return MCK_bf;	 // "bf"
      case 'l':	 // 1 string to match.
        return MCK_bl;	 // "bl"
      case 't':	 // 1 string to match.
        return MCK_bt;	 // "bt"
      }
      break;
    case 'l':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        return MCK_la;	 // "la"
      case 'd':	 // 1 string to match.
        return MCK_ld;	 // "ld"
      case 'i':	 // 1 string to match.
        return MCK_li;	 // "li"
      }
      break;
    case 'm':	 // 1 string to match.
      if (Name[1] != 'r')
        break;
      return MCK_mr;	 // "mr"
    case 'o':	 // 1 string to match.
      if (Name[1] != 'r')
        break;
      return MCK_or;	 // "or"
    case 's':	 // 1 string to match.
      if (Name[1] != 'c')
        break;
      return MCK_sc;	 // "sc"
    case 't':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        return MCK_td;	 // "td"
      case 'w':	 // 1 string to match.
        return MCK_tw;	 // "tw"
      }
      break;
    }
    break;
  case 3:	 // 72 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (Name[2] != 'd')
          break;
        return MCK_add;	 // "add"
      case 'n':	 // 1 string to match.
        if (Name[2] != 'd')
          break;
        return MCK_and;	 // "and"
      }
      break;
    case 'b':	 // 25 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_bca;	 // "bca"
        case 'l':	 // 1 string to match.
          return MCK_bcl;	 // "bcl"
        }
        break;
      case 'd':	 // 1 string to match.
        if (Name[2] != 'z')
          break;
        return MCK_bdz;	 // "bdz"
      case 'e':	 // 1 string to match.
        if (Name[2] != 'q')
          break;
        return MCK_beq;	 // "beq"
      case 'f':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_bf_43_;	 // "bf+"
        case '-':	 // 1 string to match.
          return MCK_bf_MINUS_;	 // "bf-"
        case 'a':	 // 1 string to match.
          return MCK_bfa;	 // "bfa"
        case 'l':	 // 1 string to match.
          return MCK_bfl;	 // "bfl"
        }
        break;
      case 'g':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_bge;	 // "bge"
        case 't':	 // 1 string to match.
          return MCK_bgt;	 // "bgt"
        }
        break;
      case 'l':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_bla;	 // "bla"
        case 'e':	 // 1 string to match.
          return MCK_ble;	 // "ble"
        case 'r':	 // 1 string to match.
          return MCK_blr;	 // "blr"
        case 't':	 // 1 string to match.
          return MCK_blt;	 // "blt"
        }
        break;
      case 'n':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_bne;	 // "bne"
        case 'g':	 // 1 string to match.
          return MCK_bng;	 // "bng"
        case 'l':	 // 1 string to match.
          return MCK_bnl;	 // "bnl"
        case 's':	 // 1 string to match.
          return MCK_bns;	 // "bns"
        case 'u':	 // 1 string to match.
          return MCK_bnu;	 // "bnu"
        }
        break;
      case 's':	 // 1 string to match.
        if (Name[2] != 'o')
          break;
        return MCK_bso;	 // "bso"
      case 't':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_bt_43_;	 // "bt+"
        case '-':	 // 1 string to match.
          return MCK_bt_MINUS_;	 // "bt-"
        case 'a':	 // 1 string to match.
          return MCK_bta;	 // "bta"
        case 'l':	 // 1 string to match.
          return MCK_btl;	 // "btl"
        }
        break;
      case 'u':	 // 1 string to match.
        if (Name[2] != 'n')
          break;
        return MCK_bun;	 // "bun"
      }
      break;
    case 'c':	 // 1 string to match.
      if (memcmp(Name.data()+1, "mp", 2))
        break;
      return MCK_cmp;	 // "cmp"
    case 'd':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (Name[2] != 'i')
          break;
        return MCK_dci;	 // "dci"
      case 's':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 's':	 // 1 string to match.
          return MCK_dss;	 // "dss"
        case 't':	 // 1 string to match.
          return MCK_dst;	 // "dst"
        }
        break;
      }
      break;
    case 'e':	 // 1 string to match.
      if (memcmp(Name.data()+1, "qv", 2))
        break;
      return MCK_eqv;	 // "eqv"
    case 'f':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'm':	 // 1 string to match.
        if (Name[2] != 'r')
          break;
        return MCK_fmr;	 // "fmr"
      case 'r':	 // 1 string to match.
        if (Name[2] != 'e')
          break;
        return MCK_fre;	 // "fre"
      }
      break;
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ci", 2))
        break;
      return MCK_ici;	 // "ici"
    case 'l':	 // 12 strings to match.
      switch (Name[1]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (Name[2] != 'z')
          break;
        return MCK_lbz;	 // "lbz"
      case 'd':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'u':	 // 1 string to match.
          return MCK_ldu;	 // "ldu"
        case 'x':	 // 1 string to match.
          return MCK_ldx;	 // "ldx"
        }
        break;
      case 'f':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_lfd;	 // "lfd"
        case 's':	 // 1 string to match.
          return MCK_lfs;	 // "lfs"
        }
        break;
      case 'h':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_lha;	 // "lha"
        case 'z':	 // 1 string to match.
          return MCK_lhz;	 // "lhz"
        }
        break;
      case 'i':	 // 1 string to match.
        if (Name[2] != 's')
          break;
        return MCK_lis;	 // "lis"
      case 'm':	 // 1 string to match.
        if (Name[2] != 'w')
          break;
        return MCK_lmw;	 // "lmw"
      case 'v':	 // 1 string to match.
        if (Name[2] != 'x')
          break;
        return MCK_lvx;	 // "lvx"
      case 'w':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_lwa;	 // "lwa"
        case 'z':	 // 1 string to match.
          return MCK_lwz;	 // "lwz"
        }
        break;
      }
      break;
    case 'n':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (Name[2] != 'g')
          break;
        return MCK_neg;	 // "neg"
      case 'o':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'p':	 // 1 string to match.
          return MCK_nop;	 // "nop"
        case 'r':	 // 1 string to match.
          return MCK_nor;	 // "nor"
        case 't':	 // 1 string to match.
          return MCK_not;	 // "not"
        }
        break;
      }
      break;
    case 'o':	 // 2 strings to match.
      if (Name[1] != 'r')
        break;
      switch (Name[2]) {
      default: break;
      case 'c':	 // 1 string to match.
        return MCK_orc;	 // "orc"
      case 'i':	 // 1 string to match.
        return MCK_ori;	 // "ori"
      }
      break;
    case 'r':	 // 1 string to match.
      if (memcmp(Name.data()+1, "fi", 2))
        break;
      return MCK_rfi;	 // "rfi"
    case 's':	 // 9 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_sld;	 // "sld"
        case 'w':	 // 1 string to match.
          return MCK_slw;	 // "slw"
        }
        break;
      case 'r':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_srd;	 // "srd"
        case 'w':	 // 1 string to match.
          return MCK_srw;	 // "srw"
        }
        break;
      case 't':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_stb;	 // "stb"
        case 'd':	 // 1 string to match.
          return MCK_std;	 // "std"
        case 'h':	 // 1 string to match.
          return MCK_sth;	 // "sth"
        case 'w':	 // 1 string to match.
          return MCK_stw;	 // "stw"
        }
        break;
      case 'u':	 // 1 string to match.
        if (Name[2] != 'b')
          break;
        return MCK_sub;	 // "sub"
      }
      break;
    case 't':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'i':	 // 1 string to match.
          return MCK_tdi;	 // "tdi"
        case 'u':	 // 1 string to match.
          return MCK_tdu;	 // "tdu"
        }
        break;
      case 's':	 // 1 string to match.
        if (Name[2] != 'r')
          break;
        return MCK_tsr;	 // "tsr"
      case 'w':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'i':	 // 1 string to match.
          return MCK_twi;	 // "twi"
        case 'u':	 // 1 string to match.
          return MCK_twu;	 // "twu"
        }
        break;
      }
      break;
    case 'v':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'o':	 // 1 string to match.
        if (Name[2] != 'r')
          break;
        return MCK_vor;	 // "vor"
      case 's':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'l':	 // 1 string to match.
          return MCK_vsl;	 // "vsl"
        case 'r':	 // 1 string to match.
          return MCK_vsr;	 // "vsr"
        }
        break;
      }
      break;
    case 'x':	 // 1 string to match.
      if (memcmp(Name.data()+1, "or", 2))
        break;
      return MCK_xor;	 // "xor"
    }
    break;
  case 4:	 // 206 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 6 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 3 strings to match.
        if (Name[2] != 'd')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 1 string to match.
          return MCK_addc;	 // "addc"
        case 'e':	 // 1 string to match.
          return MCK_adde;	 // "adde"
        case 'i':	 // 1 string to match.
          return MCK_addi;	 // "addi"
        }
        break;
      case 'n':	 // 2 strings to match.
        if (Name[2] != 'd')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 1 string to match.
          return MCK_andc;	 // "andc"
        case 'i':	 // 1 string to match.
          return MCK_andi;	 // "andi"
        }
        break;
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+2, "tn", 2))
          break;
        return MCK_attn;	 // "attn"
      }
      break;
    case 'b':	 // 71 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'l':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 1 string to match.
            return MCK_bcla;	 // "bcla"
          case 'r':	 // 1 string to match.
            return MCK_bclr;	 // "bclr"
          }
          break;
        case 't':	 // 1 string to match.
          if (Name[3] != 'r')
            break;
          return MCK_bctr;	 // "bctr"
        }
        break;
      case 'd':	 // 7 strings to match.
        switch (Name[2]) {
        default: break;
        case 'n':	 // 1 string to match.
          if (Name[3] != 'z')
            break;
          return MCK_bdnz;	 // "bdnz"
        case 'z':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bdz_43_;	 // "bdz+"
          case '-':	 // 1 string to match.
            return MCK_bdz_MINUS_;	 // "bdz-"
          case 'a':	 // 1 string to match.
            return MCK_bdza;	 // "bdza"
          case 'f':	 // 1 string to match.
            return MCK_bdzf;	 // "bdzf"
          case 'l':	 // 1 string to match.
            return MCK_bdzl;	 // "bdzl"
          case 't':	 // 1 string to match.
            return MCK_bdzt;	 // "bdzt"
          }
          break;
        }
        break;
      case 'e':	 // 4 strings to match.
        if (Name[2] != 'q')
          break;
        switch (Name[3]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_beq_43_;	 // "beq+"
        case '-':	 // 1 string to match.
          return MCK_beq_MINUS_;	 // "beq-"
        case 'a':	 // 1 string to match.
          return MCK_beqa;	 // "beqa"
        case 'l':	 // 1 string to match.
          return MCK_beql;	 // "beql"
        }
        break;
      case 'f':	 // 6 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bfa_43_;	 // "bfa+"
          case '-':	 // 1 string to match.
            return MCK_bfa_MINUS_;	 // "bfa-"
          }
          break;
        case 'l':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bfl_43_;	 // "bfl+"
          case '-':	 // 1 string to match.
            return MCK_bfl_MINUS_;	 // "bfl-"
          case 'a':	 // 1 string to match.
            return MCK_bfla;	 // "bfla"
          case 'r':	 // 1 string to match.
            return MCK_bflr;	 // "bflr"
          }
          break;
        }
        break;
      case 'g':	 // 8 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bge_43_;	 // "bge+"
          case '-':	 // 1 string to match.
            return MCK_bge_MINUS_;	 // "bge-"
          case 'a':	 // 1 string to match.
            return MCK_bgea;	 // "bgea"
          case 'l':	 // 1 string to match.
            return MCK_bgel;	 // "bgel"
          }
          break;
        case 't':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bgt_43_;	 // "bgt+"
          case '-':	 // 1 string to match.
            return MCK_bgt_MINUS_;	 // "bgt-"
          case 'a':	 // 1 string to match.
            return MCK_bgta;	 // "bgta"
          case 'l':	 // 1 string to match.
            return MCK_bgtl;	 // "bgtl"
          }
          break;
        }
        break;
      case 'l':	 // 9 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_ble_43_;	 // "ble+"
          case '-':	 // 1 string to match.
            return MCK_ble_MINUS_;	 // "ble-"
          case 'a':	 // 1 string to match.
            return MCK_blea;	 // "blea"
          case 'l':	 // 1 string to match.
            return MCK_blel;	 // "blel"
          }
          break;
        case 'r':	 // 1 string to match.
          if (Name[3] != 'l')
            break;
          return MCK_blrl;	 // "blrl"
        case 't':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_blt_43_;	 // "blt+"
          case '-':	 // 1 string to match.
            return MCK_blt_MINUS_;	 // "blt-"
          case 'a':	 // 1 string to match.
            return MCK_blta;	 // "blta"
          case 'l':	 // 1 string to match.
            return MCK_bltl;	 // "bltl"
          }
          break;
        }
        break;
      case 'n':	 // 20 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bne_43_;	 // "bne+"
          case '-':	 // 1 string to match.
            return MCK_bne_MINUS_;	 // "bne-"
          case 'a':	 // 1 string to match.
            return MCK_bnea;	 // "bnea"
          case 'l':	 // 1 string to match.
            return MCK_bnel;	 // "bnel"
          }
          break;
        case 'g':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bng_43_;	 // "bng+"
          case '-':	 // 1 string to match.
            return MCK_bng_MINUS_;	 // "bng-"
          case 'a':	 // 1 string to match.
            return MCK_bnga;	 // "bnga"
          case 'l':	 // 1 string to match.
            return MCK_bngl;	 // "bngl"
          }
          break;
        case 'l':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bnl_43_;	 // "bnl+"
          case '-':	 // 1 string to match.
            return MCK_bnl_MINUS_;	 // "bnl-"
          case 'a':	 // 1 string to match.
            return MCK_bnla;	 // "bnla"
          case 'l':	 // 1 string to match.
            return MCK_bnll;	 // "bnll"
          }
          break;
        case 's':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bns_43_;	 // "bns+"
          case '-':	 // 1 string to match.
            return MCK_bns_MINUS_;	 // "bns-"
          case 'a':	 // 1 string to match.
            return MCK_bnsa;	 // "bnsa"
          case 'l':	 // 1 string to match.
            return MCK_bnsl;	 // "bnsl"
          }
          break;
        case 'u':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bnu_43_;	 // "bnu+"
          case '-':	 // 1 string to match.
            return MCK_bnu_MINUS_;	 // "bnu-"
          case 'a':	 // 1 string to match.
            return MCK_bnua;	 // "bnua"
          case 'l':	 // 1 string to match.
            return MCK_bnul;	 // "bnul"
          }
          break;
        }
        break;
      case 's':	 // 4 strings to match.
        if (Name[2] != 'o')
          break;
        switch (Name[3]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_bso_43_;	 // "bso+"
        case '-':	 // 1 string to match.
          return MCK_bso_MINUS_;	 // "bso-"
        case 'a':	 // 1 string to match.
          return MCK_bsoa;	 // "bsoa"
        case 'l':	 // 1 string to match.
          return MCK_bsol;	 // "bsol"
        }
        break;
      case 't':	 // 6 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bta_43_;	 // "bta+"
          case '-':	 // 1 string to match.
            return MCK_bta_MINUS_;	 // "bta-"
          }
          break;
        case 'l':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_btl_43_;	 // "btl+"
          case '-':	 // 1 string to match.
            return MCK_btl_MINUS_;	 // "btl-"
          case 'a':	 // 1 string to match.
            return MCK_btla;	 // "btla"
          case 'r':	 // 1 string to match.
            return MCK_btlr;	 // "btlr"
          }
          break;
        }
        break;
      case 'u':	 // 4 strings to match.
        if (Name[2] != 'n')
          break;
        switch (Name[3]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_bun_43_;	 // "bun+"
        case '-':	 // 1 string to match.
          return MCK_bun_MINUS_;	 // "bun-"
        case 'a':	 // 1 string to match.
          return MCK_buna;	 // "buna"
        case 'l':	 // 1 string to match.
          return MCK_bunl;	 // "bunl"
        }
        break;
      }
      break;
    case 'c':	 // 6 strings to match.
      switch (Name[1]) {
      default: break;
      case 'm':	 // 5 strings to match.
        if (Name[2] != 'p')
          break;
        switch (Name[3]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_cmpb;	 // "cmpb"
        case 'd':	 // 1 string to match.
          return MCK_cmpd;	 // "cmpd"
        case 'i':	 // 1 string to match.
          return MCK_cmpi;	 // "cmpi"
        case 'l':	 // 1 string to match.
          return MCK_cmpl;	 // "cmpl"
        case 'w':	 // 1 string to match.
          return MCK_cmpw;	 // "cmpw"
        }
        break;
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "or", 2))
          break;
        return MCK_cror;	 // "cror"
      }
      break;
    case 'd':	 // 8 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 5 strings to match.
        if (Name[2] != 'b')
          break;
        switch (Name[3]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_dcba;	 // "dcba"
        case 'f':	 // 1 string to match.
          return MCK_dcbf;	 // "dcbf"
        case 'i':	 // 1 string to match.
          return MCK_dcbi;	 // "dcbi"
        case 't':	 // 1 string to match.
          return MCK_dcbt;	 // "dcbt"
        case 'z':	 // 1 string to match.
          return MCK_dcbz;	 // "dcbz"
        }
        break;
      case 'i':	 // 2 strings to match.
        if (Name[2] != 'v')
          break;
        switch (Name[3]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_divd;	 // "divd"
        case 'w':	 // 1 string to match.
          return MCK_divw;	 // "divw"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "tt", 2))
          break;
        return MCK_dstt;	 // "dstt"
      }
      break;
    case 'e':	 // 1 string to match.
      if (memcmp(Name.data()+1, "vor", 3))
        break;
      return MCK_evor;	 // "evor"
    case 'f':	 // 13 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 1 string to match.
          if (Name[3] != 's')
            break;
          return MCK_fabs;	 // "fabs"
        case 'd':	 // 1 string to match.
          if (Name[3] != 'd')
            break;
          return MCK_fadd;	 // "fadd"
        }
        break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "iv", 2))
          break;
        return MCK_fdiv;	 // "fdiv"
      case 'm':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ul", 2))
          break;
        return MCK_fmul;	 // "fmul"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eg", 2))
          break;
        return MCK_fneg;	 // "fneg"
      case 'r':	 // 6 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (Name[3] != 's')
            break;
          return MCK_fres;	 // "fres"
        case 'i':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case 'm':	 // 1 string to match.
            return MCK_frim;	 // "frim"
          case 'n':	 // 1 string to match.
            return MCK_frin;	 // "frin"
          case 'p':	 // 1 string to match.
            return MCK_frip;	 // "frip"
          case 'z':	 // 1 string to match.
            return MCK_friz;	 // "friz"
          }
          break;
        case 's':	 // 1 string to match.
          if (Name[3] != 'p')
            break;
          return MCK_frsp;	 // "frsp"
        }
        break;
      case 's':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (Name[3] != 'l')
            break;
          return MCK_fsel;	 // "fsel"
        case 'u':	 // 1 string to match.
          if (Name[3] != 'b')
            break;
          return MCK_fsub;	 // "fsub"
        }
        break;
      }
      break;
    case 'i':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 2 strings to match.
        if (Name[2] != 'b')
          break;
        switch (Name[3]) {
        default: break;
        case 'i':	 // 1 string to match.
          return MCK_icbi;	 // "icbi"
        case 't':	 // 1 string to match.
          return MCK_icbt;	 // "icbt"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "el", 2))
          break;
        return MCK_isel;	 // "isel"
      }
      break;
    case 'l':	 // 18 strings to match.
      switch (Name[1]) {
      default: break;
      case 'b':	 // 2 strings to match.
        if (Name[2] != 'z')
          break;
        switch (Name[3]) {
        default: break;
        case 'u':	 // 1 string to match.
          return MCK_lbzu;	 // "lbzu"
        case 'x':	 // 1 string to match.
          return MCK_lbzx;	 // "lbzx"
        }
        break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ux", 2))
          break;
        return MCK_ldux;	 // "ldux"
      case 'f':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'u':	 // 1 string to match.
            return MCK_lfdu;	 // "lfdu"
          case 'x':	 // 1 string to match.
            return MCK_lfdx;	 // "lfdx"
          }
          break;
        case 's':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'u':	 // 1 string to match.
            return MCK_lfsu;	 // "lfsu"
          case 'x':	 // 1 string to match.
            return MCK_lfsx;	 // "lfsx"
          }
          break;
        }
        break;
      case 'h':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'u':	 // 1 string to match.
            return MCK_lhau;	 // "lhau"
          case 'x':	 // 1 string to match.
            return MCK_lhax;	 // "lhax"
          }
          break;
        case 'z':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'u':	 // 1 string to match.
            return MCK_lhzu;	 // "lhzu"
          case 'x':	 // 1 string to match.
            return MCK_lhzx;	 // "lhzx"
          }
          break;
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "wi", 2))
          break;
        return MCK_lswi;	 // "lswi"
      case 'v':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 's':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'l':	 // 1 string to match.
            return MCK_lvsl;	 // "lvsl"
          case 'r':	 // 1 string to match.
            return MCK_lvsr;	 // "lvsr"
          }
          break;
        case 'x':	 // 1 string to match.
          if (Name[3] != 'l')
            break;
          return MCK_lvxl;	 // "lvxl"
        }
        break;
      case 'w':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (Name[3] != 'x')
            break;
          return MCK_lwax;	 // "lwax"
        case 'z':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'u':	 // 1 string to match.
            return MCK_lwzu;	 // "lwzu"
          case 'x':	 // 1 string to match.
            return MCK_lwzx;	 // "lwzx"
          }
          break;
        }
        break;
      }
      break;
    case 'm':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ar", 2))
          break;
        return MCK_mbar;	 // "mbar"
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+2, "rf", 2))
          break;
        return MCK_mcrf;	 // "mcrf"
      case 'f':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (Name[3] != 'r')
            break;
          return MCK_mfcr;	 // "mfcr"
        case 'f':	 // 1 string to match.
          if (Name[3] != 's')
            break;
          return MCK_mffs;	 // "mffs"
        case 'l':	 // 1 string to match.
          if (Name[3] != 'r')
            break;
          return MCK_mflr;	 // "mflr"
        case 's':	 // 1 string to match.
          if (Name[3] != 'r')
            break;
          return MCK_mfsr;	 // "mfsr"
        case 't':	 // 1 string to match.
          if (Name[3] != 'b')
            break;
          return MCK_mftb;	 // "mftb"
        }
        break;
      case 't':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (Name[3] != 'r')
            break;
          return MCK_mtcr;	 // "mtcr"
        case 'l':	 // 1 string to match.
          if (Name[3] != 'r')
            break;
          return MCK_mtlr;	 // "mtlr"
        case 's':	 // 1 string to match.
          if (Name[3] != 'r')
            break;
          return MCK_mtsr;	 // "mtsr"
        }
        break;
      }
      break;
    case 'n':	 // 1 string to match.
      if (memcmp(Name.data()+1, "and", 3))
        break;
      return MCK_nand;	 // "nand"
    case 'o':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ris", 3))
        break;
      return MCK_oris;	 // "oris"
    case 'r':	 // 3 strings to match.
      if (Name[1] != 'f')
        break;
      switch (Name[2]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (Name[3] != 'i')
          break;
        return MCK_rfci;	 // "rfci"
      case 'd':	 // 1 string to match.
        if (Name[3] != 'i')
          break;
        return MCK_rfdi;	 // "rfdi"
      case 'i':	 // 1 string to match.
        if (Name[3] != 'd')
          break;
        return MCK_rfid;	 // "rfid"
      }
      break;
    case 's':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_sldi;	 // "sldi"
        case 'w':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_slwi;	 // "slwi"
        }
        break;
      case 'r':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_srad;	 // "srad"
          case 'w':	 // 1 string to match.
            return MCK_sraw;	 // "sraw"
          }
          break;
        case 'd':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_srdi;	 // "srdi"
        case 'w':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_srwi;	 // "srwi"
        }
        break;
      case 't':	 // 12 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'u':	 // 1 string to match.
            return MCK_stbu;	 // "stbu"
          case 'x':	 // 1 string to match.
            return MCK_stbx;	 // "stbx"
          }
          break;
        case 'd':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'u':	 // 1 string to match.
            return MCK_stdu;	 // "stdu"
          case 'x':	 // 1 string to match.
            return MCK_stdx;	 // "stdx"
          }
          break;
        case 'f':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_stfd;	 // "stfd"
          case 's':	 // 1 string to match.
            return MCK_stfs;	 // "stfs"
          }
          break;
        case 'h':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'u':	 // 1 string to match.
            return MCK_sthu;	 // "sthu"
          case 'x':	 // 1 string to match.
            return MCK_sthx;	 // "sthx"
          }
          break;
        case 'm':	 // 1 string to match.
          if (Name[3] != 'w')
            break;
          return MCK_stmw;	 // "stmw"
        case 'v':	 // 1 string to match.
          if (Name[3] != 'x')
            break;
          return MCK_stvx;	 // "stvx"
        case 'w':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'u':	 // 1 string to match.
            return MCK_stwu;	 // "stwu"
          case 'x':	 // 1 string to match.
            return MCK_stwx;	 // "stwx"
          }
          break;
        }
        break;
      case 'u':	 // 3 strings to match.
        if (Name[2] != 'b')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 1 string to match.
          return MCK_subc;	 // "subc"
        case 'f':	 // 1 string to match.
          return MCK_subf;	 // "subf"
        case 'i':	 // 1 string to match.
          return MCK_subi;	 // "subi"
        }
        break;
      case 'y':	 // 1 string to match.
        if (memcmp(Name.data()+2, "nc", 2))
          break;
        return MCK_sync;	 // "sync"
      }
      break;
    case 't':	 // 20 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 9 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (Name[3] != 'q')
            break;
          return MCK_tdeq;	 // "tdeq"
        case 'g':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_tdge;	 // "tdge"
          case 't':	 // 1 string to match.
            return MCK_tdgt;	 // "tdgt"
          }
          break;
        case 'l':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_tdle;	 // "tdle"
          case 't':	 // 1 string to match.
            return MCK_tdlt;	 // "tdlt"
          }
          break;
        case 'n':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_tdne;	 // "tdne"
          case 'g':	 // 1 string to match.
            return MCK_tdng;	 // "tdng"
          case 'l':	 // 1 string to match.
            return MCK_tdnl;	 // "tdnl"
          }
          break;
        case 'u':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_tdui;	 // "tdui"
        }
        break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "nd", 2))
          break;
        return MCK_tend;	 // "tend"
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ap", 2))
          break;
        return MCK_trap;	 // "trap"
      case 'w':	 // 9 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (Name[3] != 'q')
            break;
          return MCK_tweq;	 // "tweq"
        case 'g':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_twge;	 // "twge"
          case 't':	 // 1 string to match.
            return MCK_twgt;	 // "twgt"
          }
          break;
        case 'l':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_twle;	 // "twle"
          case 't':	 // 1 string to match.
            return MCK_twlt;	 // "twlt"
          }
          break;
        case 'n':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_twne;	 // "twne"
          case 'g':	 // 1 string to match.
            return MCK_twng;	 // "twng"
          case 'l':	 // 1 string to match.
            return MCK_twnl;	 // "twnl"
          }
          break;
        case 'u':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_twui;	 // "twui"
        }
        break;
      }
      break;
    case 'v':	 // 20 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "nd", 2))
          break;
        return MCK_vand;	 // "vand"
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "qv", 2))
          break;
        return MCK_veqv;	 // "veqv"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "or", 2))
          break;
        return MCK_vnor;	 // "vnor"
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "rc", 2))
          break;
        return MCK_vorc;	 // "vorc"
      case 'r':	 // 4 strings to match.
        if (Name[2] != 'l')
          break;
        switch (Name[3]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_vrlb;	 // "vrlb"
        case 'd':	 // 1 string to match.
          return MCK_vrld;	 // "vrld"
        case 'h':	 // 1 string to match.
          return MCK_vrlh;	 // "vrlh"
        case 'w':	 // 1 string to match.
          return MCK_vrlw;	 // "vrlw"
        }
        break;
      case 's':	 // 11 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (Name[3] != 'l')
            break;
          return MCK_vsel;	 // "vsel"
        case 'l':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 1 string to match.
            return MCK_vslb;	 // "vslb"
          case 'd':	 // 1 string to match.
            return MCK_vsld;	 // "vsld"
          case 'h':	 // 1 string to match.
            return MCK_vslh;	 // "vslh"
          case 'o':	 // 1 string to match.
            return MCK_vslo;	 // "vslo"
          case 'w':	 // 1 string to match.
            return MCK_vslw;	 // "vslw"
          }
          break;
        case 'r':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 1 string to match.
            return MCK_vsrb;	 // "vsrb"
          case 'd':	 // 1 string to match.
            return MCK_vsrd;	 // "vsrd"
          case 'h':	 // 1 string to match.
            return MCK_vsrh;	 // "vsrh"
          case 'o':	 // 1 string to match.
            return MCK_vsro;	 // "vsro"
          case 'w':	 // 1 string to match.
            return MCK_vsrw;	 // "vsrw"
          }
          break;
        }
        break;
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+2, "or", 2))
          break;
        return MCK_vxor;	 // "vxor"
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ait", 3))
        break;
      return MCK_wait;	 // "wait"
    case 'x':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "op", 2))
          break;
        return MCK_xnop;	 // "xnop"
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ri", 2))
          break;
        return MCK_xori;	 // "xori"
      }
      break;
    }
    break;
  case 5:	 // 328 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 4 strings to match.
        if (Name[2] != 'd')
          break;
        switch (Name[3]) {
        default: break;
        case 'i':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'c':	 // 1 string to match.
            return MCK_addic;	 // "addic"
          case 's':	 // 1 string to match.
            return MCK_addis;	 // "addis"
          }
          break;
        case 'm':	 // 1 string to match.
          if (Name[4] != 'e')
            break;
          return MCK_addme;	 // "addme"
        case 'z':	 // 1 string to match.
          if (Name[4] != 'e')
            break;
          return MCK_addze;	 // "addze"
        }
        break;
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "dis", 3))
          break;
        return MCK_andis;	 // "andis"
      }
      break;
    case 'b':	 // 104 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "tr", 2))
            break;
          return MCK_bcctr;	 // "bcctr"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rl", 2))
            break;
          return MCK_bclrl;	 // "bclrl"
        case 't':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rl", 2))
            break;
          return MCK_bctrl;	 // "bctrl"
        }
        break;
      case 'd':	 // 16 strings to match.
        switch (Name[2]) {
        default: break;
        case 'n':	 // 6 strings to match.
          if (Name[3] != 'z')
            break;
          switch (Name[4]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bdnz_43_;	 // "bdnz+"
          case '-':	 // 1 string to match.
            return MCK_bdnz_MINUS_;	 // "bdnz-"
          case 'a':	 // 1 string to match.
            return MCK_bdnza;	 // "bdnza"
          case 'f':	 // 1 string to match.
            return MCK_bdnzf;	 // "bdnzf"
          case 'l':	 // 1 string to match.
            return MCK_bdnzl;	 // "bdnzl"
          case 't':	 // 1 string to match.
            return MCK_bdnzt;	 // "bdnzt"
          }
          break;
        case 'z':	 // 10 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bdza_43_;	 // "bdza+"
            case '-':	 // 1 string to match.
              return MCK_bdza_MINUS_;	 // "bdza-"
            }
            break;
          case 'f':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_bdzfa;	 // "bdzfa"
            case 'l':	 // 1 string to match.
              return MCK_bdzfl;	 // "bdzfl"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bdzl_43_;	 // "bdzl+"
            case '-':	 // 1 string to match.
              return MCK_bdzl_MINUS_;	 // "bdzl-"
            case 'a':	 // 1 string to match.
              return MCK_bdzla;	 // "bdzla"
            case 'r':	 // 1 string to match.
              return MCK_bdzlr;	 // "bdzlr"
            }
            break;
          case 't':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_bdzta;	 // "bdzta"
            case 'l':	 // 1 string to match.
              return MCK_bdztl;	 // "bdztl"
            }
            break;
          }
          break;
        }
        break;
      case 'e':	 // 6 strings to match.
        if (Name[2] != 'q')
          break;
        switch (Name[3]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_beqa_43_;	 // "beqa+"
          case '-':	 // 1 string to match.
            return MCK_beqa_MINUS_;	 // "beqa-"
          }
          break;
        case 'l':	 // 4 strings to match.
          switch (Name[4]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_beql_43_;	 // "beql+"
          case '-':	 // 1 string to match.
            return MCK_beql_MINUS_;	 // "beql-"
          case 'a':	 // 1 string to match.
            return MCK_beqla;	 // "beqla"
          case 'r':	 // 1 string to match.
            return MCK_beqlr;	 // "beqlr"
          }
          break;
        }
        break;
      case 'f':	 // 6 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "tr", 2))
            break;
          return MCK_bfctr;	 // "bfctr"
        case 'l':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bfla_43_;	 // "bfla+"
            case '-':	 // 1 string to match.
              return MCK_bfla_MINUS_;	 // "bfla-"
            }
            break;
          case 'r':	 // 3 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bflr_43_;	 // "bflr+"
            case '-':	 // 1 string to match.
              return MCK_bflr_MINUS_;	 // "bflr-"
            case 'l':	 // 1 string to match.
              return MCK_bflrl;	 // "bflrl"
            }
            break;
          }
          break;
        }
        break;
      case 'g':	 // 12 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bgea_43_;	 // "bgea+"
            case '-':	 // 1 string to match.
              return MCK_bgea_MINUS_;	 // "bgea-"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bgel_43_;	 // "bgel+"
            case '-':	 // 1 string to match.
              return MCK_bgel_MINUS_;	 // "bgel-"
            case 'a':	 // 1 string to match.
              return MCK_bgela;	 // "bgela"
            case 'r':	 // 1 string to match.
              return MCK_bgelr;	 // "bgelr"
            }
            break;
          }
          break;
        case 't':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bgta_43_;	 // "bgta+"
            case '-':	 // 1 string to match.
              return MCK_bgta_MINUS_;	 // "bgta-"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bgtl_43_;	 // "bgtl+"
            case '-':	 // 1 string to match.
              return MCK_bgtl_MINUS_;	 // "bgtl-"
            case 'a':	 // 1 string to match.
              return MCK_bgtla;	 // "bgtla"
            case 'r':	 // 1 string to match.
              return MCK_bgtlr;	 // "bgtlr"
            }
            break;
          }
          break;
        }
        break;
      case 'l':	 // 12 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_blea_43_;	 // "blea+"
            case '-':	 // 1 string to match.
              return MCK_blea_MINUS_;	 // "blea-"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_blel_43_;	 // "blel+"
            case '-':	 // 1 string to match.
              return MCK_blel_MINUS_;	 // "blel-"
            case 'a':	 // 1 string to match.
              return MCK_blela;	 // "blela"
            case 'r':	 // 1 string to match.
              return MCK_blelr;	 // "blelr"
            }
            break;
          }
          break;
        case 't':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_blta_43_;	 // "blta+"
            case '-':	 // 1 string to match.
              return MCK_blta_MINUS_;	 // "blta-"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bltl_43_;	 // "bltl+"
            case '-':	 // 1 string to match.
              return MCK_bltl_MINUS_;	 // "bltl-"
            case 'a':	 // 1 string to match.
              return MCK_bltla;	 // "bltla"
            case 'r':	 // 1 string to match.
              return MCK_bltlr;	 // "bltlr"
            }
            break;
          }
          break;
        }
        break;
      case 'n':	 // 30 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnea_43_;	 // "bnea+"
            case '-':	 // 1 string to match.
              return MCK_bnea_MINUS_;	 // "bnea-"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnel_43_;	 // "bnel+"
            case '-':	 // 1 string to match.
              return MCK_bnel_MINUS_;	 // "bnel-"
            case 'a':	 // 1 string to match.
              return MCK_bnela;	 // "bnela"
            case 'r':	 // 1 string to match.
              return MCK_bnelr;	 // "bnelr"
            }
            break;
          }
          break;
        case 'g':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnga_43_;	 // "bnga+"
            case '-':	 // 1 string to match.
              return MCK_bnga_MINUS_;	 // "bnga-"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bngl_43_;	 // "bngl+"
            case '-':	 // 1 string to match.
              return MCK_bngl_MINUS_;	 // "bngl-"
            case 'a':	 // 1 string to match.
              return MCK_bngla;	 // "bngla"
            case 'r':	 // 1 string to match.
              return MCK_bnglr;	 // "bnglr"
            }
            break;
          }
          break;
        case 'l':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnla_43_;	 // "bnla+"
            case '-':	 // 1 string to match.
              return MCK_bnla_MINUS_;	 // "bnla-"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnll_43_;	 // "bnll+"
            case '-':	 // 1 string to match.
              return MCK_bnll_MINUS_;	 // "bnll-"
            case 'a':	 // 1 string to match.
              return MCK_bnlla;	 // "bnlla"
            case 'r':	 // 1 string to match.
              return MCK_bnllr;	 // "bnllr"
            }
            break;
          }
          break;
        case 's':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnsa_43_;	 // "bnsa+"
            case '-':	 // 1 string to match.
              return MCK_bnsa_MINUS_;	 // "bnsa-"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnsl_43_;	 // "bnsl+"
            case '-':	 // 1 string to match.
              return MCK_bnsl_MINUS_;	 // "bnsl-"
            case 'a':	 // 1 string to match.
              return MCK_bnsla;	 // "bnsla"
            case 'r':	 // 1 string to match.
              return MCK_bnslr;	 // "bnslr"
            }
            break;
          }
          break;
        case 'u':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnua_43_;	 // "bnua+"
            case '-':	 // 1 string to match.
              return MCK_bnua_MINUS_;	 // "bnua-"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnul_43_;	 // "bnul+"
            case '-':	 // 1 string to match.
              return MCK_bnul_MINUS_;	 // "bnul-"
            case 'a':	 // 1 string to match.
              return MCK_bnula;	 // "bnula"
            case 'r':	 // 1 string to match.
              return MCK_bnulr;	 // "bnulr"
            }
            break;
          }
          break;
        }
        break;
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "inc", 3))
          break;
        return MCK_brinc;	 // "brinc"
      case 's':	 // 6 strings to match.
        if (Name[2] != 'o')
          break;
        switch (Name[3]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bsoa_43_;	 // "bsoa+"
          case '-':	 // 1 string to match.
            return MCK_bsoa_MINUS_;	 // "bsoa-"
          }
          break;
        case 'l':	 // 4 strings to match.
          switch (Name[4]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bsol_43_;	 // "bsol+"
          case '-':	 // 1 string to match.
            return MCK_bsol_MINUS_;	 // "bsol-"
          case 'a':	 // 1 string to match.
            return MCK_bsola;	 // "bsola"
          case 'r':	 // 1 string to match.
            return MCK_bsolr;	 // "bsolr"
          }
          break;
        }
        break;
      case 't':	 // 6 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "tr", 2))
            break;
          return MCK_btctr;	 // "btctr"
        case 'l':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_btla_43_;	 // "btla+"
            case '-':	 // 1 string to match.
              return MCK_btla_MINUS_;	 // "btla-"
            }
            break;
          case 'r':	 // 3 strings to match.
            switch (Name[4]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_btlr_43_;	 // "btlr+"
            case '-':	 // 1 string to match.
              return MCK_btlr_MINUS_;	 // "btlr-"
            case 'l':	 // 1 string to match.
              return MCK_btlrl;	 // "btlrl"
            }
            break;
          }
          break;
        }
        break;
      case 'u':	 // 6 strings to match.
        if (Name[2] != 'n')
          break;
        switch (Name[3]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_buna_43_;	 // "buna+"
          case '-':	 // 1 string to match.
            return MCK_buna_MINUS_;	 // "buna-"
          }
          break;
        case 'l':	 // 4 strings to match.
          switch (Name[4]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bunl_43_;	 // "bunl+"
          case '-':	 // 1 string to match.
            return MCK_bunl_MINUS_;	 // "bunl-"
          case 'a':	 // 1 string to match.
            return MCK_bunla;	 // "bunla"
          case 'r':	 // 1 string to match.
            return MCK_bunlr;	 // "bunlr"
          }
          break;
        }
        break;
      }
      break;
    case 'c':	 // 13 strings to match.
      switch (Name[1]) {
      default: break;
      case 'm':	 // 5 strings to match.
        if (Name[2] != 'p')
          break;
        switch (Name[3]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[4] != 'i')
            break;
          return MCK_cmpdi;	 // "cmpdi"
        case 'l':	 // 3 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_cmpld;	 // "cmpld"
          case 'i':	 // 1 string to match.
            return MCK_cmpli;	 // "cmpli"
          case 'w':	 // 1 string to match.
            return MCK_cmplw;	 // "cmplw"
          }
          break;
        case 'w':	 // 1 string to match.
          if (Name[4] != 'i')
            break;
          return MCK_cmpwi;	 // "cmpwi"
        }
        break;
      case 'r':	 // 8 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "nd", 2))
            break;
          return MCK_crand;	 // "crand"
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "lr", 2))
            break;
          return MCK_crclr;	 // "crclr"
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "qv", 2))
            break;
          return MCK_creqv;	 // "creqv"
        case 'n':	 // 2 strings to match.
          if (Name[3] != 'o')
            break;
          switch (Name[4]) {
          default: break;
          case 'r':	 // 1 string to match.
            return MCK_crnor;	 // "crnor"
          case 't':	 // 1 string to match.
            return MCK_crnot;	 // "crnot"
          }
          break;
        case 'o':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rc", 2))
            break;
          return MCK_crorc;	 // "crorc"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "et", 2))
            break;
          return MCK_crset;	 // "crset"
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+3, "or", 2))
            break;
          return MCK_crxor;	 // "crxor"
        }
        break;
      }
      break;
    case 'd':	 // 9 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 's':	 // 1 string to match.
            if (Name[4] != 't')
              break;
            return MCK_dcbst;	 // "dcbst"
          case 't':	 // 1 string to match.
            if (Name[4] != 't')
              break;
            return MCK_dcbtt;	 // "dcbtt"
          case 'z':	 // 1 string to match.
            if (Name[4] != 'l')
              break;
            return MCK_dcbzl;	 // "dcbzl"
          }
          break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ci", 2))
            break;
          return MCK_dccci;	 // "dccci"
        }
        break;
      case 'i':	 // 4 strings to match.
        if (Name[2] != 'v')
          break;
        switch (Name[3]) {
        default: break;
        case 'd':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_divde;	 // "divde"
          case 'u':	 // 1 string to match.
            return MCK_divdu;	 // "divdu"
          }
          break;
        case 'w':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_divwe;	 // "divwe"
          case 'u':	 // 1 string to match.
            return MCK_divwu;	 // "divwu"
          }
          break;
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "tst", 3))
          break;
        return MCK_dstst;	 // "dstst"
      }
      break;
    case 'e':	 // 17 strings to match.
      switch (Name[1]) {
      default: break;
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eio", 3))
          break;
        return MCK_eieio;	 // "eieio"
      case 'v':	 // 13 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (Name[4] != 's')
              break;
            return MCK_evabs;	 // "evabs"
          case 'n':	 // 1 string to match.
            if (Name[4] != 'd')
              break;
            return MCK_evand;	 // "evand"
          }
          break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "qv", 2))
            break;
          return MCK_eveqv;	 // "eveqv"
        case 'l':	 // 3 strings to match.
          if (Name[3] != 'd')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_evldd;	 // "evldd"
          case 'h':	 // 1 string to match.
            return MCK_evldh;	 // "evldh"
          case 'w':	 // 1 string to match.
            return MCK_evldw;	 // "evldw"
          }
          break;
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ra", 2))
            break;
          return MCK_evmra;	 // "evmra"
        case 'n':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[4] != 'g')
              break;
            return MCK_evneg;	 // "evneg"
          case 'o':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_evnor;	 // "evnor"
          }
          break;
        case 'o':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rc", 2))
            break;
          return MCK_evorc;	 // "evorc"
        case 'r':	 // 1 string to match.
          if (memcmp(Name.data()+3, "lw", 2))
            break;
          return MCK_evrlw;	 // "evrlw"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "lw", 2))
            break;
          return MCK_evslw;	 // "evslw"
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+3, "or", 2))
            break;
          return MCK_evxor;	 // "evxor"
        }
        break;
      case 'x':	 // 3 strings to match.
        if (memcmp(Name.data()+2, "ts", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_extsb;	 // "extsb"
        case 'h':	 // 1 string to match.
          return MCK_extsh;	 // "extsh"
        case 'w':	 // 1 string to match.
          return MCK_extsw;	 // "extsw"
        }
        break;
      }
      break;
    case 'f':	 // 12 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "dds", 3))
          break;
        return MCK_fadds;	 // "fadds"
      case 'c':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'f':	 // 1 string to match.
          if (memcmp(Name.data()+3, "id", 2))
            break;
          return MCK_fcfid;	 // "fcfid"
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "pu", 2))
            break;
          return MCK_fcmpu;	 // "fcmpu"
        case 't':	 // 2 strings to match.
          if (Name[3] != 'i')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fctid;	 // "fctid"
          case 'w':	 // 1 string to match.
            return MCK_fctiw;	 // "fctiw"
          }
          break;
        }
        break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ivs", 3))
          break;
        return MCK_fdivs;	 // "fdivs"
      case 'm':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "dd", 2))
            break;
          return MCK_fmadd;	 // "fmadd"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ub", 2))
            break;
          return MCK_fmsub;	 // "fmsub"
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ls", 2))
            break;
          return MCK_fmuls;	 // "fmuls"
        }
        break;
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "abs", 3))
          break;
        return MCK_fnabs;	 // "fnabs"
      case 's':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'q':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rt", 2))
            break;
          return MCK_fsqrt;	 // "fsqrt"
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+3, "bs", 2))
            break;
          return MCK_fsubs;	 // "fsubs"
        }
        break;
      }
      break;
    case 'i':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+2, "cci", 3))
          break;
        return MCK_iccci;	 // "iccci"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ync", 3))
          break;
        return MCK_isync;	 // "isync"
      }
      break;
    case 'l':	 // 19 strings to match.
      switch (Name[1]) {
      default: break;
      case 'b':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rx", 2))
            break;
          return MCK_lbarx;	 // "lbarx"
        case 'z':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ux", 2))
            break;
          return MCK_lbzux;	 // "lbzux"
        }
        break;
      case 'd':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rx", 2))
            break;
          return MCK_ldarx;	 // "ldarx"
        case 'b':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rx", 2))
            break;
          return MCK_ldbrx;	 // "ldbrx"
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ix", 2))
            break;
          return MCK_ldcix;	 // "ldcix"
        }
        break;
      case 'f':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ux", 2))
            break;
          return MCK_lfdux;	 // "lfdux"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ux", 2))
            break;
          return MCK_lfsux;	 // "lfsux"
        }
        break;
      case 'h':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'r':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_lharx;	 // "lharx"
          case 'u':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_lhaux;	 // "lhaux"
          }
          break;
        case 'b':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rx", 2))
            break;
          return MCK_lhbrx;	 // "lhbrx"
        case 'z':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ux", 2))
            break;
          return MCK_lhzux;	 // "lhzux"
        }
        break;
      case 'v':	 // 3 strings to match.
        if (Name[2] != 'e')
          break;
        switch (Name[3]) {
        default: break;
        case 'b':	 // 1 string to match.
          if (Name[4] != 'x')
            break;
          return MCK_lvebx;	 // "lvebx"
        case 'h':	 // 1 string to match.
          if (Name[4] != 'x')
            break;
          return MCK_lvehx;	 // "lvehx"
        case 'w':	 // 1 string to match.
          if (Name[4] != 'x')
            break;
          return MCK_lvewx;	 // "lvewx"
        }
        break;
      case 'w':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'r':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_lwarx;	 // "lwarx"
          case 'u':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_lwaux;	 // "lwaux"
          }
          break;
        case 'b':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rx", 2))
            break;
          return MCK_lwbrx;	 // "lwbrx"
        case 'z':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ux", 2))
            break;
          return MCK_lwzux;	 // "lwzux"
        }
        break;
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+2, "sdx", 3))
          break;
        return MCK_lxsdx;	 // "lxsdx"
      }
      break;
    case 'm':	 // 54 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+2, "rfs", 3))
          break;
        return MCK_mcrfs;	 // "mcrfs"
      case 'f':	 // 23 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'm':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mfamr;	 // "mfamr"
          case 's':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mfasr;	 // "mfasr"
          }
          break;
        case 'b':	 // 8 strings to match.
          if (Name[3] != 'r')
            break;
          switch (Name[4]) {
          default: break;
          case '0':	 // 1 string to match.
            return MCK_mfbr0;	 // "mfbr0"
          case '1':	 // 1 string to match.
            return MCK_mfbr1;	 // "mfbr1"
          case '2':	 // 1 string to match.
            return MCK_mfbr2;	 // "mfbr2"
          case '3':	 // 1 string to match.
            return MCK_mfbr3;	 // "mfbr3"
          case '4':	 // 1 string to match.
            return MCK_mfbr4;	 // "mfbr4"
          case '5':	 // 1 string to match.
            return MCK_mfbr5;	 // "mfbr5"
          case '6':	 // 1 string to match.
            return MCK_mfbr6;	 // "mfbr6"
          case '7':	 // 1 string to match.
            return MCK_mfbr7;	 // "mfbr7"
          }
          break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "tr", 2))
            break;
          return MCK_mfctr;	 // "mfctr"
        case 'd':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mfdar;	 // "mfdar"
          case 'c':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mfdcr;	 // "mfdcr"
          case 'e':	 // 1 string to match.
            if (Name[4] != 'c')
              break;
            return MCK_mfdec;	 // "mfdec"
          }
          break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "sr", 2))
            break;
          return MCK_mfesr;	 // "mfesr"
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "sr", 2))
            break;
          return MCK_mfmsr;	 // "mfmsr"
        case 'p':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'i':	 // 1 string to match.
            if (Name[4] != 'd')
              break;
            return MCK_mfpid;	 // "mfpid"
          case 'v':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mfpvr;	 // "mfpvr"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "pr", 2))
            break;
          return MCK_mfspr;	 // "mfspr"
        case 't':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'l':	 // 1 string to match.
              return MCK_mftbl;	 // "mftbl"
            case 'u':	 // 1 string to match.
              return MCK_mftbu;	 // "mftbu"
            }
            break;
          case 'c':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mftcr;	 // "mftcr"
          }
          break;
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+3, "er", 2))
            break;
          return MCK_mfxer;	 // "mfxer"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ync", 3))
          break;
        return MCK_msync;	 // "msync"
      case 't':	 // 24 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'm':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mtamr;	 // "mtamr"
          case 's':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mtasr;	 // "mtasr"
          }
          break;
        case 'b':	 // 8 strings to match.
          if (Name[3] != 'r')
            break;
          switch (Name[4]) {
          default: break;
          case '0':	 // 1 string to match.
            return MCK_mtbr0;	 // "mtbr0"
          case '1':	 // 1 string to match.
            return MCK_mtbr1;	 // "mtbr1"
          case '2':	 // 1 string to match.
            return MCK_mtbr2;	 // "mtbr2"
          case '3':	 // 1 string to match.
            return MCK_mtbr3;	 // "mtbr3"
          case '4':	 // 1 string to match.
            return MCK_mtbr4;	 // "mtbr4"
          case '5':	 // 1 string to match.
            return MCK_mtbr5;	 // "mtbr5"
          case '6':	 // 1 string to match.
            return MCK_mtbr6;	 // "mtbr6"
          case '7':	 // 1 string to match.
            return MCK_mtbr7;	 // "mtbr7"
          }
          break;
        case 'c':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'r':	 // 1 string to match.
            if (Name[4] != 'f')
              break;
            return MCK_mtcrf;	 // "mtcrf"
          case 't':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mtctr;	 // "mtctr"
          }
          break;
        case 'd':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mtdar;	 // "mtdar"
          case 'c':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mtdcr;	 // "mtdcr"
          case 'e':	 // 1 string to match.
            if (Name[4] != 'c')
              break;
            return MCK_mtdec;	 // "mtdec"
          }
          break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "sr", 2))
            break;
          return MCK_mtesr;	 // "mtesr"
        case 'f':	 // 1 string to match.
          if (memcmp(Name.data()+3, "sf", 2))
            break;
          return MCK_mtfsf;	 // "mtfsf"
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "sr", 2))
            break;
          return MCK_mtmsr;	 // "mtmsr"
        case 'p':	 // 1 string to match.
          if (memcmp(Name.data()+3, "id", 2))
            break;
          return MCK_mtpid;	 // "mtpid"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "pr", 2))
            break;
          return MCK_mtspr;	 // "mtspr"
        case 't':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'l':	 // 1 string to match.
              return MCK_mttbl;	 // "mttbl"
            case 'u':	 // 1 string to match.
              return MCK_mttbu;	 // "mttbu"
            }
            break;
          case 'c':	 // 1 string to match.
            if (Name[4] != 'r')
              break;
            return MCK_mttcr;	 // "mttcr"
          }
          break;
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+3, "er", 2))
            break;
          return MCK_mtxer;	 // "mtxer"
        }
        break;
      case 'u':	 // 5 strings to match.
        if (Name[2] != 'l')
          break;
        switch (Name[3]) {
        default: break;
        case 'h':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_mulhd;	 // "mulhd"
          case 'w':	 // 1 string to match.
            return MCK_mulhw;	 // "mulhw"
          }
          break;
        case 'l':	 // 3 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_mulld;	 // "mulld"
          case 'i':	 // 1 string to match.
            return MCK_mulli;	 // "mulli"
          case 'w':	 // 1 string to match.
            return MCK_mullw;	 // "mullw"
          }
          break;
        }
        break;
      }
      break;
    case 'q':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "vf", 2))
        break;
      switch (Name[3]) {
      default: break;
      case 'm':	 // 1 string to match.
        if (Name[4] != 'r')
          break;
        return MCK_qvfmr;	 // "qvfmr"
      case 'o':	 // 1 string to match.
        if (Name[4] != 'r')
          break;
        return MCK_qvfor;	 // "qvfor"
      case 'r':	 // 1 string to match.
        if (Name[4] != 'e')
          break;
        return MCK_qvfre;	 // "qvfre"
      }
      break;
    case 'r':	 // 8 strings to match.
      switch (Name[1]) {
      default: break;
      case 'f':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "bb", 2))
            break;
          return MCK_rfebb;	 // "rfebb"
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ci", 2))
            break;
          return MCK_rfmci;	 // "rfmci"
        }
        break;
      case 'l':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'l':	 // 1 string to match.
              return MCK_rldcl;	 // "rldcl"
            case 'r':	 // 1 string to match.
              return MCK_rldcr;	 // "rldcr"
            }
            break;
          case 'i':	 // 1 string to match.
            if (Name[4] != 'c')
              break;
            return MCK_rldic;	 // "rldic"
          }
          break;
        case 'w':	 // 1 string to match.
          if (memcmp(Name.data()+3, "nm", 2))
            break;
          return MCK_rlwnm;	 // "rlwnm"
        }
        break;
      case 'o':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "tl", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_rotld;	 // "rotld"
        case 'w':	 // 1 string to match.
          return MCK_rotlw;	 // "rotlw"
        }
        break;
      }
      break;
    case 's':	 // 22 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "bi", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_slbia;	 // "slbia"
        case 'e':	 // 1 string to match.
          return MCK_slbie;	 // "slbie"
        }
        break;
      case 'r':	 // 2 strings to match.
        if (Name[2] != 'a')
          break;
        switch (Name[3]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[4] != 'i')
            break;
          return MCK_sradi;	 // "sradi"
        case 'w':	 // 1 string to match.
          if (Name[4] != 'i')
            break;
          return MCK_srawi;	 // "srawi"
        }
        break;
      case 't':	 // 14 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_stbcx;	 // "stbcx"
          case 'u':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_stbux;	 // "stbux"
          }
          break;
        case 'd':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_stdcx;	 // "stdcx"
          case 'u':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_stdux;	 // "stdux"
          }
          break;
        case 'f':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'u':	 // 1 string to match.
              return MCK_stfdu;	 // "stfdu"
            case 'x':	 // 1 string to match.
              return MCK_stfdx;	 // "stfdx"
            }
            break;
          case 's':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'u':	 // 1 string to match.
              return MCK_stfsu;	 // "stfsu"
            case 'x':	 // 1 string to match.
              return MCK_stfsx;	 // "stfsx"
            }
            break;
          }
          break;
        case 'h':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_sthcx;	 // "sthcx"
          case 'u':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_sthux;	 // "sthux"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "wi", 2))
            break;
          return MCK_stswi;	 // "stswi"
        case 'v':	 // 1 string to match.
          if (memcmp(Name.data()+3, "xl", 2))
            break;
          return MCK_stvxl;	 // "stvxl"
        case 'w':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_stwcx;	 // "stwcx"
          case 'u':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_stwux;	 // "stwux"
          }
          break;
        }
        break;
      case 'u':	 // 4 strings to match.
        if (Name[2] != 'b')
          break;
        switch (Name[3]) {
        default: break;
        case 'f':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'c':	 // 1 string to match.
            return MCK_subfc;	 // "subfc"
          case 'e':	 // 1 string to match.
            return MCK_subfe;	 // "subfe"
          }
          break;
        case 'i':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'c':	 // 1 string to match.
            return MCK_subic;	 // "subic"
          case 's':	 // 1 string to match.
            return MCK_subis;	 // "subis"
          }
          break;
        }
        break;
      }
      break;
    case 't':	 // 35 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 14 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "qi", 2))
            break;
          return MCK_tdeqi;	 // "tdeqi"
        case 'g':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_tdgei;	 // "tdgei"
          case 't':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_tdgti;	 // "tdgti"
          }
          break;
        case 'l':	 // 8 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_tdlei;	 // "tdlei"
          case 'g':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'e':	 // 1 string to match.
              return MCK_tdlge;	 // "tdlge"
            case 't':	 // 1 string to match.
              return MCK_tdlgt;	 // "tdlgt"
            }
            break;
          case 'l':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'e':	 // 1 string to match.
              return MCK_tdlle;	 // "tdlle"
            case 't':	 // 1 string to match.
              return MCK_tdllt;	 // "tdllt"
            }
            break;
          case 'n':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'g':	 // 1 string to match.
              return MCK_tdlng;	 // "tdlng"
            case 'l':	 // 1 string to match.
              return MCK_tdlnl;	 // "tdlnl"
            }
            break;
          case 't':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_tdlti;	 // "tdlti"
          }
          break;
        case 'n':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_tdnei;	 // "tdnei"
          case 'g':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_tdngi;	 // "tdngi"
          case 'l':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_tdnli;	 // "tdnli"
          }
          break;
        }
        break;
      case 'l':	 // 7 strings to match.
        if (Name[2] != 'b')
          break;
        switch (Name[3]) {
        default: break;
        case 'i':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'a':	 // 1 string to match.
            return MCK_tlbia;	 // "tlbia"
          case 'e':	 // 1 string to match.
            return MCK_tlbie;	 // "tlbie"
          }
          break;
        case 'l':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_tlbld;	 // "tlbld"
          case 'i':	 // 1 string to match.
            return MCK_tlbli;	 // "tlbli"
          }
          break;
        case 'r':	 // 1 string to match.
          if (Name[4] != 'e')
            break;
          return MCK_tlbre;	 // "tlbre"
        case 's':	 // 1 string to match.
          if (Name[4] != 'x')
            break;
          return MCK_tlbsx;	 // "tlbsx"
        case 'w':	 // 1 string to match.
          if (Name[4] != 'e')
            break;
          return MCK_tlbwe;	 // "tlbwe"
        }
        break;
      case 'w':	 // 14 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "qi", 2))
            break;
          return MCK_tweqi;	 // "tweqi"
        case 'g':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_twgei;	 // "twgei"
          case 't':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_twgti;	 // "twgti"
          }
          break;
        case 'l':	 // 8 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_twlei;	 // "twlei"
          case 'g':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'e':	 // 1 string to match.
              return MCK_twlge;	 // "twlge"
            case 't':	 // 1 string to match.
              return MCK_twlgt;	 // "twlgt"
            }
            break;
          case 'l':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'e':	 // 1 string to match.
              return MCK_twlle;	 // "twlle"
            case 't':	 // 1 string to match.
              return MCK_twllt;	 // "twllt"
            }
            break;
          case 'n':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'g':	 // 1 string to match.
              return MCK_twlng;	 // "twlng"
            case 'l':	 // 1 string to match.
              return MCK_twlnl;	 // "twlnl"
            }
            break;
          case 't':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_twlti;	 // "twlti"
          }
          break;
        case 'n':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_twnei;	 // "twnei"
          case 'g':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_twngi;	 // "twngi"
          case 'l':	 // 1 string to match.
            if (Name[4] != 'i')
              break;
            return MCK_twnli;	 // "twnli"
          }
          break;
        }
        break;
      }
      break;
    case 'v':	 // 21 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ndc", 3))
          break;
        return MCK_vandc;	 // "vandc"
      case 'c':	 // 6 strings to match.
        switch (Name[2]) {
        default: break;
        case 'f':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 's':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_vcfsx;	 // "vcfsx"
          case 'u':	 // 1 string to match.
            if (Name[4] != 'x')
              break;
            return MCK_vcfux;	 // "vcfux"
          }
          break;
        case 'l':	 // 4 strings to match.
          if (Name[3] != 'z')
            break;
          switch (Name[4]) {
          default: break;
          case 'b':	 // 1 string to match.
            return MCK_vclzb;	 // "vclzb"
          case 'd':	 // 1 string to match.
            return MCK_vclzd;	 // "vclzd"
          case 'h':	 // 1 string to match.
            return MCK_vclzh;	 // "vclzh"
          case 'w':	 // 1 string to match.
            return MCK_vclzw;	 // "vclzw"
          }
          break;
        }
        break;
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bbd", 3))
          break;
        return MCK_vgbbd;	 // "vgbbd"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "and", 3))
          break;
        return MCK_vnand;	 // "vnand"
      case 'p':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rm", 2))
            break;
          return MCK_vperm;	 // "vperm"
        case 'k':	 // 1 string to match.
          if (memcmp(Name.data()+3, "px", 2))
            break;
          return MCK_vpkpx;	 // "vpkpx"
        }
        break;
      case 'r':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "fp", 2))
            break;
          return MCK_vrefp;	 // "vrefp"
        case 'f':	 // 4 strings to match.
          if (Name[3] != 'i')
            break;
          switch (Name[4]) {
          default: break;
          case 'm':	 // 1 string to match.
            return MCK_vrfim;	 // "vrfim"
          case 'n':	 // 1 string to match.
            return MCK_vrfin;	 // "vrfin"
          case 'p':	 // 1 string to match.
            return MCK_vrfip;	 // "vrfip"
          case 'z':	 // 1 string to match.
            return MCK_vrfiz;	 // "vrfiz"
          }
          break;
        }
        break;
      case 's':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ox", 2))
            break;
          return MCK_vsbox;	 // "vsbox"
        case 'r':	 // 4 strings to match.
          if (Name[3] != 'a')
            break;
          switch (Name[4]) {
          default: break;
          case 'b':	 // 1 string to match.
            return MCK_vsrab;	 // "vsrab"
          case 'd':	 // 1 string to match.
            return MCK_vsrad;	 // "vsrad"
          case 'h':	 // 1 string to match.
            return MCK_vsrah;	 // "vsrah"
          case 'w':	 // 1 string to match.
            return MCK_vsraw;	 // "vsraw"
          }
          break;
        }
        break;
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "rtee", 4))
        break;
      return MCK_wrtee;	 // "wrtee"
    case 'x':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ris", 3))
          break;
        return MCK_xoris;	 // "xoris"
      case 'x':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+3, "or", 2))
            break;
          return MCK_xxlor;	 // "xxlor"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "el", 2))
            break;
          return MCK_xxsel;	 // "xxsel"
        }
        break;
      }
      break;
    }
    break;
  case 6:	 // 324 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 103 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ctrl", 4))
          break;
        return MCK_bcctrl;	 // "bcctrl"
      case 'd':	 // 19 strings to match.
        switch (Name[2]) {
        default: break;
        case 'n':	 // 10 strings to match.
          if (Name[3] != 'z')
            break;
          switch (Name[4]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bdnza_43_;	 // "bdnza+"
            case '-':	 // 1 string to match.
              return MCK_bdnza_MINUS_;	 // "bdnza-"
            }
            break;
          case 'f':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_bdnzfa;	 // "bdnzfa"
            case 'l':	 // 1 string to match.
              return MCK_bdnzfl;	 // "bdnzfl"
            }
            break;
          case 'l':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bdnzl_43_;	 // "bdnzl+"
            case '-':	 // 1 string to match.
              return MCK_bdnzl_MINUS_;	 // "bdnzl-"
            case 'a':	 // 1 string to match.
              return MCK_bdnzla;	 // "bdnzla"
            case 'r':	 // 1 string to match.
              return MCK_bdnzlr;	 // "bdnzlr"
            }
            break;
          case 't':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_bdnzta;	 // "bdnzta"
            case 'l':	 // 1 string to match.
              return MCK_bdnztl;	 // "bdnztl"
            }
            break;
          }
          break;
        case 'z':	 // 9 strings to match.
          switch (Name[3]) {
          default: break;
          case 'f':	 // 2 strings to match.
            if (Name[4] != 'l')
              break;
            switch (Name[5]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_bdzfla;	 // "bdzfla"
            case 'r':	 // 1 string to match.
              return MCK_bdzflr;	 // "bdzflr"
            }
            break;
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bdzla_43_;	 // "bdzla+"
              case '-':	 // 1 string to match.
                return MCK_bdzla_MINUS_;	 // "bdzla-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bdzlr_43_;	 // "bdzlr+"
              case '-':	 // 1 string to match.
                return MCK_bdzlr_MINUS_;	 // "bdzlr-"
              case 'l':	 // 1 string to match.
                return MCK_bdzlrl;	 // "bdzlrl"
              }
              break;
            }
            break;
          case 't':	 // 2 strings to match.
            if (Name[4] != 'l')
              break;
            switch (Name[5]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_bdztla;	 // "bdztla"
            case 'r':	 // 1 string to match.
              return MCK_bdztlr;	 // "bdztlr"
            }
            break;
          }
          break;
        }
        break;
      case 'e':	 // 6 strings to match.
        if (Name[2] != 'q')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+4, "tr", 2))
            break;
          return MCK_beqctr;	 // "beqctr"
        case 'l':	 // 5 strings to match.
          switch (Name[4]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_beqla_43_;	 // "beqla+"
            case '-':	 // 1 string to match.
              return MCK_beqla_MINUS_;	 // "beqla-"
            }
            break;
          case 'r':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_beqlr_43_;	 // "beqlr+"
            case '-':	 // 1 string to match.
              return MCK_beqlr_MINUS_;	 // "beqlr-"
            case 'l':	 // 1 string to match.
              return MCK_beqlrl;	 // "beqlrl"
            }
            break;
          }
          break;
        }
        break;
      case 'f':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 3 strings to match.
          if (memcmp(Name.data()+3, "tr", 2))
            break;
          switch (Name[5]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bfctr_43_;	 // "bfctr+"
          case '-':	 // 1 string to match.
            return MCK_bfctr_MINUS_;	 // "bfctr-"
          case 'l':	 // 1 string to match.
            return MCK_bfctrl;	 // "bfctrl"
          }
          break;
        case 'l':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "rl", 2))
            break;
          switch (Name[5]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bflrl_43_;	 // "bflrl+"
          case '-':	 // 1 string to match.
            return MCK_bflrl_MINUS_;	 // "bflrl-"
          }
          break;
        }
        break;
      case 'g':	 // 12 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            return MCK_bgectr;	 // "bgectr"
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bgela_43_;	 // "bgela+"
              case '-':	 // 1 string to match.
                return MCK_bgela_MINUS_;	 // "bgela-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bgelr_43_;	 // "bgelr+"
              case '-':	 // 1 string to match.
                return MCK_bgelr_MINUS_;	 // "bgelr-"
              case 'l':	 // 1 string to match.
                return MCK_bgelrl;	 // "bgelrl"
              }
              break;
            }
            break;
          }
          break;
        case 't':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            return MCK_bgtctr;	 // "bgtctr"
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bgtla_43_;	 // "bgtla+"
              case '-':	 // 1 string to match.
                return MCK_bgtla_MINUS_;	 // "bgtla-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bgtlr_43_;	 // "bgtlr+"
              case '-':	 // 1 string to match.
                return MCK_bgtlr_MINUS_;	 // "bgtlr-"
              case 'l':	 // 1 string to match.
                return MCK_bgtlrl;	 // "bgtlrl"
              }
              break;
            }
            break;
          }
          break;
        }
        break;
      case 'l':	 // 12 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            return MCK_blectr;	 // "blectr"
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_blela_43_;	 // "blela+"
              case '-':	 // 1 string to match.
                return MCK_blela_MINUS_;	 // "blela-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_blelr_43_;	 // "blelr+"
              case '-':	 // 1 string to match.
                return MCK_blelr_MINUS_;	 // "blelr-"
              case 'l':	 // 1 string to match.
                return MCK_blelrl;	 // "blelrl"
              }
              break;
            }
            break;
          }
          break;
        case 't':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            return MCK_bltctr;	 // "bltctr"
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bltla_43_;	 // "bltla+"
              case '-':	 // 1 string to match.
                return MCK_bltla_MINUS_;	 // "bltla-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bltlr_43_;	 // "bltlr+"
              case '-':	 // 1 string to match.
                return MCK_bltlr_MINUS_;	 // "bltlr-"
              case 'l':	 // 1 string to match.
                return MCK_bltlrl;	 // "bltlrl"
              }
              break;
            }
            break;
          }
          break;
        }
        break;
      case 'n':	 // 30 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            return MCK_bnectr;	 // "bnectr"
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bnela_43_;	 // "bnela+"
              case '-':	 // 1 string to match.
                return MCK_bnela_MINUS_;	 // "bnela-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bnelr_43_;	 // "bnelr+"
              case '-':	 // 1 string to match.
                return MCK_bnelr_MINUS_;	 // "bnelr-"
              case 'l':	 // 1 string to match.
                return MCK_bnelrl;	 // "bnelrl"
              }
              break;
            }
            break;
          }
          break;
        case 'g':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            return MCK_bngctr;	 // "bngctr"
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bngla_43_;	 // "bngla+"
              case '-':	 // 1 string to match.
                return MCK_bngla_MINUS_;	 // "bngla-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bnglr_43_;	 // "bnglr+"
              case '-':	 // 1 string to match.
                return MCK_bnglr_MINUS_;	 // "bnglr-"
              case 'l':	 // 1 string to match.
                return MCK_bnglrl;	 // "bnglrl"
              }
              break;
            }
            break;
          }
          break;
        case 'l':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            return MCK_bnlctr;	 // "bnlctr"
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bnlla_43_;	 // "bnlla+"
              case '-':	 // 1 string to match.
                return MCK_bnlla_MINUS_;	 // "bnlla-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bnllr_43_;	 // "bnllr+"
              case '-':	 // 1 string to match.
                return MCK_bnllr_MINUS_;	 // "bnllr-"
              case 'l':	 // 1 string to match.
                return MCK_bnllrl;	 // "bnllrl"
              }
              break;
            }
            break;
          }
          break;
        case 's':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            return MCK_bnsctr;	 // "bnsctr"
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bnsla_43_;	 // "bnsla+"
              case '-':	 // 1 string to match.
                return MCK_bnsla_MINUS_;	 // "bnsla-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bnslr_43_;	 // "bnslr+"
              case '-':	 // 1 string to match.
                return MCK_bnslr_MINUS_;	 // "bnslr-"
              case 'l':	 // 1 string to match.
                return MCK_bnslrl;	 // "bnslrl"
              }
              break;
            }
            break;
          }
          break;
        case 'u':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            return MCK_bnuctr;	 // "bnuctr"
          case 'l':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bnula_43_;	 // "bnula+"
              case '-':	 // 1 string to match.
                return MCK_bnula_MINUS_;	 // "bnula-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bnulr_43_;	 // "bnulr+"
              case '-':	 // 1 string to match.
                return MCK_bnulr_MINUS_;	 // "bnulr-"
              case 'l':	 // 1 string to match.
                return MCK_bnulrl;	 // "bnulrl"
              }
              break;
            }
            break;
          }
          break;
        }
        break;
      case 'p':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ermd", 4))
          break;
        return MCK_bpermd;	 // "bpermd"
      case 's':	 // 6 strings to match.
        if (Name[2] != 'o')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+4, "tr", 2))
            break;
          return MCK_bsoctr;	 // "bsoctr"
        case 'l':	 // 5 strings to match.
          switch (Name[4]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bsola_43_;	 // "bsola+"
            case '-':	 // 1 string to match.
              return MCK_bsola_MINUS_;	 // "bsola-"
            }
            break;
          case 'r':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bsolr_43_;	 // "bsolr+"
            case '-':	 // 1 string to match.
              return MCK_bsolr_MINUS_;	 // "bsolr-"
            case 'l':	 // 1 string to match.
              return MCK_bsolrl;	 // "bsolrl"
            }
            break;
          }
          break;
        }
        break;
      case 't':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 3 strings to match.
          if (memcmp(Name.data()+3, "tr", 2))
            break;
          switch (Name[5]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_btctr_43_;	 // "btctr+"
          case '-':	 // 1 string to match.
            return MCK_btctr_MINUS_;	 // "btctr-"
          case 'l':	 // 1 string to match.
            return MCK_btctrl;	 // "btctrl"
          }
          break;
        case 'l':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "rl", 2))
            break;
          switch (Name[5]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_btlrl_43_;	 // "btlrl+"
          case '-':	 // 1 string to match.
            return MCK_btlrl_MINUS_;	 // "btlrl-"
          }
          break;
        }
        break;
      case 'u':	 // 6 strings to match.
        if (Name[2] != 'n')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+4, "tr", 2))
            break;
          return MCK_bunctr;	 // "bunctr"
        case 'l':	 // 5 strings to match.
          switch (Name[4]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bunla_43_;	 // "bunla+"
            case '-':	 // 1 string to match.
              return MCK_bunla_MINUS_;	 // "bunla-"
            }
            break;
          case 'r':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bunlr_43_;	 // "bunlr+"
            case '-':	 // 1 string to match.
              return MCK_bunlr_MINUS_;	 // "bunlr-"
            case 'l':	 // 1 string to match.
              return MCK_bunlrl;	 // "bunlrl"
            }
            break;
          }
          break;
        }
        break;
      }
      break;
    case 'c':	 // 11 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 4 strings to match.
        if (Name[2] != 'r')
          break;
        switch (Name[3]) {
        default: break;
        case 'l':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_clrldi;	 // "clrldi"
          case 'w':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_clrlwi;	 // "clrlwi"
          }
          break;
        case 'r':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_clrrdi;	 // "clrrdi"
          case 'w':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_clrrwi;	 // "clrrwi"
          }
          break;
        }
        break;
      case 'm':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "pl", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[5] != 'i')
            break;
          return MCK_cmpldi;	 // "cmpldi"
        case 'w':	 // 1 string to match.
          if (Name[5] != 'i')
            break;
          return MCK_cmplwi;	 // "cmplwi"
        }
        break;
      case 'n':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "tlz", 3))
          break;
        switch (Name[5]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_cntlzd;	 // "cntlzd"
        case 'w':	 // 1 string to match.
          return MCK_cntlzw;	 // "cntlzw"
        }
        break;
      case 'r':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ndc", 3))
            break;
          return MCK_crandc;	 // "crandc"
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ove", 3))
            break;
          return MCK_crmove;	 // "crmove"
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+3, "and", 3))
            break;
          return MCK_crnand;	 // "crnand"
        }
        break;
      }
      break;
    case 'd':	 // 7 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 3 strings to match.
        if (memcmp(Name.data()+2, "bt", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (Name[5] != 't')
            break;
          return MCK_dcbtct;	 // "dcbtct"
        case 'd':	 // 1 string to match.
          if (Name[5] != 's')
            break;
          return MCK_dcbtds;	 // "dcbtds"
        case 's':	 // 1 string to match.
          if (Name[5] != 't')
            break;
          return MCK_dcbtst;	 // "dcbtst"
        }
        break;
      case 'i':	 // 2 strings to match.
        if (Name[2] != 'v')
          break;
        switch (Name[3]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+4, "eu", 2))
            break;
          return MCK_divdeu;	 // "divdeu"
        case 'w':	 // 1 string to match.
          if (memcmp(Name.data()+4, "eu", 2))
            break;
          return MCK_divweu;	 // "divweu"
        }
        break;
      case 's':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "all", 3))
            break;
          return MCK_dssall;	 // "dssall"
        case 't':	 // 1 string to match.
          if (memcmp(Name.data()+3, "stt", 3))
            break;
          return MCK_dststt;	 // "dststt"
        }
        break;
      }
      break;
    case 'e':	 // 19 strings to match.
      switch (Name[1]) {
      default: break;
      case 'v':	 // 15 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+4, "dw", 2))
              break;
            return MCK_evaddw;	 // "evaddw"
          case 'n':	 // 1 string to match.
            if (memcmp(Name.data()+4, "dc", 2))
              break;
            return MCK_evandc;	 // "evandc"
          }
          break;
        case 'l':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 3 strings to match.
            switch (Name[4]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[5] != 'x')
                break;
              return MCK_evlddx;	 // "evlddx"
            case 'h':	 // 1 string to match.
              if (Name[5] != 'x')
                break;
              return MCK_evldhx;	 // "evldhx"
            case 'w':	 // 1 string to match.
              if (Name[5] != 'x')
                break;
              return MCK_evldwx;	 // "evldwx"
            }
            break;
          case 'w':	 // 1 string to match.
            if (memcmp(Name.data()+4, "he", 2))
              break;
            return MCK_evlwhe;	 // "evlwhe"
          }
          break;
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+3, "and", 3))
            break;
          return MCK_evnand;	 // "evnand"
        case 'r':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+4, "wi", 2))
              break;
            return MCK_evrlwi;	 // "evrlwi"
          case 'n':	 // 1 string to match.
            if (memcmp(Name.data()+4, "dw", 2))
              break;
            return MCK_evrndw;	 // "evrndw"
          }
          break;
        case 's':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+4, "wi", 2))
              break;
            return MCK_evslwi;	 // "evslwi"
          case 'r':	 // 2 strings to match.
            if (Name[4] != 'w')
              break;
            switch (Name[5]) {
            default: break;
            case 's':	 // 1 string to match.
              return MCK_evsrws;	 // "evsrws"
            case 'u':	 // 1 string to match.
              return MCK_evsrwu;	 // "evsrwu"
            }
            break;
          case 't':	 // 3 strings to match.
            if (Name[4] != 'd')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              return MCK_evstdd;	 // "evstdd"
            case 'h':	 // 1 string to match.
              return MCK_evstdh;	 // "evstdh"
            case 'w':	 // 1 string to match.
              return MCK_evstdw;	 // "evstdw"
            }
            break;
          }
          break;
        }
        break;
      case 'x':	 // 4 strings to match.
        if (Name[2] != 't')
          break;
        switch (Name[3]) {
        default: break;
        case 'l':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_extldi;	 // "extldi"
          case 'w':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_extlwi;	 // "extlwi"
          }
          break;
        case 'r':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_extrdi;	 // "extrdi"
          case 'w':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_extrwi;	 // "extrwi"
          }
          break;
        }
        break;
      }
      break;
    case 'f':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'f':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "id", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 's':	 // 1 string to match.
            return MCK_fcfids;	 // "fcfids"
          case 'u':	 // 1 string to match.
            return MCK_fcfidu;	 // "fcfidu"
          }
          break;
        case 'p':	 // 1 string to match.
          if (memcmp(Name.data()+3, "sgn", 3))
            break;
          return MCK_fcpsgn;	 // "fcpsgn"
        case 't':	 // 2 strings to match.
          if (Name[3] != 'i')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[5] != 'z')
              break;
            return MCK_fctidz;	 // "fctidz"
          case 'w':	 // 1 string to match.
            if (Name[5] != 'z')
              break;
            return MCK_fctiwz;	 // "fctiwz"
          }
          break;
        }
        break;
      case 'm':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "dds", 3))
            break;
          return MCK_fmadds;	 // "fmadds"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ubs", 3))
            break;
          return MCK_fmsubs;	 // "fmsubs"
        }
        break;
      case 'n':	 // 2 strings to match.
        if (Name[2] != 'm')
          break;
        switch (Name[3]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+4, "dd", 2))
            break;
          return MCK_fnmadd;	 // "fnmadd"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+4, "ub", 2))
            break;
          return MCK_fnmsub;	 // "fnmsub"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "qrts", 4))
          break;
        return MCK_fsqrts;	 // "fsqrts"
      }
      break;
    case 'i':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "ns", 2))
        break;
      switch (Name[3]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+4, "wi", 2))
          break;
        return MCK_inslwi;	 // "inslwi"
      case 'r':	 // 2 strings to match.
        switch (Name[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[5] != 'i')
            break;
          return MCK_insrdi;	 // "insrdi"
        case 'w':	 // 1 string to match.
          if (Name[5] != 'i')
            break;
          return MCK_insrwi;	 // "insrwi"
        }
        break;
      }
      break;
    case 'l':	 // 10 strings to match.
      switch (Name[1]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+2, "zcix", 4))
          break;
        return MCK_lbzcix;	 // "lbzcix"
      case 'f':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "iw", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (Name[5] != 'x')
            break;
          return MCK_lfiwax;	 // "lfiwax"
        case 'z':	 // 1 string to match.
          if (Name[5] != 'x')
            break;
          return MCK_lfiwzx;	 // "lfiwzx"
        }
        break;
      case 'h':	 // 1 string to match.
        if (memcmp(Name.data()+2, "zcix", 4))
          break;
        return MCK_lhzcix;	 // "lhzcix"
      case 'w':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ync", 3))
            break;
          return MCK_lwsync;	 // "lwsync"
        case 'z':	 // 1 string to match.
          if (memcmp(Name.data()+3, "cix", 3))
            break;
          return MCK_lwzcix;	 // "lwzcix"
        }
        break;
      case 'x':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+3, "spx", 3))
            break;
          return MCK_lxsspx;	 // "lxsspx"
        case 'v':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '2':	 // 1 string to match.
              if (Name[5] != 'x')
                break;
              return MCK_lxvd2x;	 // "lxvd2x"
            case 's':	 // 1 string to match.
              if (Name[5] != 'x')
                break;
              return MCK_lxvdsx;	 // "lxvdsx"
            }
            break;
          case 'w':	 // 1 string to match.
            if (memcmp(Name.data()+4, "4x", 2))
              break;
            return MCK_lxvw4x;	 // "lxvw4x"
          }
          break;
        }
        break;
      }
      break;
    case 'm':	 // 42 strings to match.
      switch (Name[1]) {
      default: break;
      case 'f':	 // 19 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "far", 3))
            break;
          return MCK_mfcfar;	 // "mfcfar"
        case 'd':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "cr", 2))
              break;
            return MCK_mfdccr;	 // "mfdccr"
          case 'e':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ar", 2))
              break;
            return MCK_mfdear;	 // "mfdear"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+4, "cr", 2))
              break;
            return MCK_mfdscr;	 // "mfdscr"
          }
          break;
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ccr", 3))
            break;
          return MCK_mficcr;	 // "mficcr"
        case 'o':	 // 1 string to match.
          if (memcmp(Name.data()+3, "crf", 3))
            break;
          return MCK_mfocrf;	 // "mfocrf"
        case 'r':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "tc", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'l':	 // 1 string to match.
            return MCK_mfrtcl;	 // "mfrtcl"
          case 'u':	 // 1 string to match.
            return MCK_mfrtcu;	 // "mfrtcu"
          }
          break;
        case 's':	 // 7 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+4, "r1", 2))
              break;
            return MCK_mfsdr1;	 // "mfsdr1"
          case 'p':	 // 1 string to match.
            if (memcmp(Name.data()+4, "rg", 2))
              break;
            return MCK_mfsprg;	 // "mfsprg"
          case 'r':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'i':	 // 1 string to match.
              if (Name[5] != 'n')
                break;
              return MCK_mfsrin;	 // "mfsrin"
            case 'r':	 // 4 strings to match.
              switch (Name[5]) {
              default: break;
              case '0':	 // 1 string to match.
                return MCK_mfsrr0;	 // "mfsrr0"
              case '1':	 // 1 string to match.
                return MCK_mfsrr1;	 // "mfsrr1"
              case '2':	 // 1 string to match.
                return MCK_mfsrr2;	 // "mfsrr2"
              case '3':	 // 1 string to match.
                return MCK_mfsrr3;	 // "mfsrr3"
              }
              break;
            }
            break;
          }
          break;
        case 't':	 // 2 strings to match.
          if (Name[3] != 'b')
            break;
          switch (Name[4]) {
          default: break;
          case 'h':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_mftbhi;	 // "mftbhi"
          case 'l':	 // 1 string to match.
            if (Name[5] != 'o')
              break;
            return MCK_mftblo;	 // "mftblo"
          }
          break;
        case 'v':	 // 2 strings to match.
          if (Name[3] != 's')
            break;
          switch (Name[4]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (Name[5] != 'r')
              break;
            return MCK_mfvscr;	 // "mfvscr"
          case 'r':	 // 1 string to match.
            if (Name[5] != 'd')
              break;
            return MCK_mfvsrd;	 // "mfvsrd"
          }
          break;
        }
        break;
      case 't':	 // 21 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "far", 3))
            break;
          return MCK_mtcfar;	 // "mtcfar"
        case 'd':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "cr", 2))
              break;
            return MCK_mtdccr;	 // "mtdccr"
          case 'e':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ar", 2))
              break;
            return MCK_mtdear;	 // "mtdear"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+4, "cr", 2))
              break;
            return MCK_mtdscr;	 // "mtdscr"
          }
          break;
        case 'f':	 // 3 strings to match.
          if (Name[3] != 's')
            break;
          switch (Name[4]) {
          default: break;
          case 'b':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case '0':	 // 1 string to match.
              return MCK_mtfsb0;	 // "mtfsb0"
            case '1':	 // 1 string to match.
              return MCK_mtfsb1;	 // "mtfsb1"
            }
            break;
          case 'f':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_mtfsfi;	 // "mtfsfi"
          }
          break;
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ccr", 3))
            break;
          return MCK_mticcr;	 // "mticcr"
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "srd", 3))
            break;
          return MCK_mtmsrd;	 // "mtmsrd"
        case 'o':	 // 1 string to match.
          if (memcmp(Name.data()+3, "crf", 3))
            break;
          return MCK_mtocrf;	 // "mtocrf"
        case 's':	 // 7 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+4, "r1", 2))
              break;
            return MCK_mtsdr1;	 // "mtsdr1"
          case 'p':	 // 1 string to match.
            if (memcmp(Name.data()+4, "rg", 2))
              break;
            return MCK_mtsprg;	 // "mtsprg"
          case 'r':	 // 5 strings to match.
            switch (Name[4]) {
            default: break;
            case 'i':	 // 1 string to match.
              if (Name[5] != 'n')
                break;
              return MCK_mtsrin;	 // "mtsrin"
            case 'r':	 // 4 strings to match.
              switch (Name[5]) {
              default: break;
              case '0':	 // 1 string to match.
                return MCK_mtsrr0;	 // "mtsrr0"
              case '1':	 // 1 string to match.
                return MCK_mtsrr1;	 // "mtsrr1"
              case '2':	 // 1 string to match.
                return MCK_mtsrr2;	 // "mtsrr2"
              case '3':	 // 1 string to match.
                return MCK_mtsrr3;	 // "mtsrr3"
              }
              break;
            }
            break;
          }
          break;
        case 't':	 // 2 strings to match.
          if (Name[3] != 'b')
            break;
          switch (Name[4]) {
          default: break;
          case 'h':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_mttbhi;	 // "mttbhi"
          case 'l':	 // 1 string to match.
            if (Name[5] != 'o')
              break;
            return MCK_mttblo;	 // "mttblo"
          }
          break;
        case 'v':	 // 2 strings to match.
          if (Name[3] != 's')
            break;
          switch (Name[4]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (Name[5] != 'r')
              break;
            return MCK_mtvscr;	 // "mtvscr"
          case 'r':	 // 1 string to match.
            if (Name[5] != 'd')
              break;
            return MCK_mtvsrd;	 // "mtvsrd"
          }
          break;
        }
        break;
      case 'u':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "lh", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[5] != 'u')
            break;
          return MCK_mulhdu;	 // "mulhdu"
        case 'w':	 // 1 string to match.
          if (Name[5] != 'u')
            break;
          return MCK_mulhwu;	 // "mulhwu"
        }
        break;
      }
      break;
    case 'q':	 // 23 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'f':	 // 20 strings to match.
        switch (Name[3]) {
        default: break;
        case 'a':	 // 3 strings to match.
          switch (Name[4]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (Name[5] != 's')
              break;
            return MCK_qvfabs;	 // "qvfabs"
          case 'd':	 // 1 string to match.
            if (Name[5] != 'd')
              break;
            return MCK_qvfadd;	 // "qvfadd"
          case 'n':	 // 1 string to match.
            if (Name[5] != 'd')
              break;
            return MCK_qvfand;	 // "qvfand"
          }
          break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+4, "lr", 2))
            break;
          return MCK_qvfclr;	 // "qvfclr"
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+4, "qu", 2))
            break;
          return MCK_qvfequ;	 // "qvfequ"
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+4, "ul", 2))
            break;
          return MCK_qvfmul;	 // "qvfmul"
        case 'n':	 // 3 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[5] != 'g')
              break;
            return MCK_qvfneg;	 // "qvfneg"
          case 'o':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case 'r':	 // 1 string to match.
              return MCK_qvfnor;	 // "qvfnor"
            case 't':	 // 1 string to match.
              return MCK_qvfnot;	 // "qvfnot"
            }
            break;
          }
          break;
        case 'o':	 // 1 string to match.
          if (memcmp(Name.data()+4, "rc", 2))
            break;
          return MCK_qvforc;	 // "qvforc"
        case 'r':	 // 6 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[5] != 's')
              break;
            return MCK_qvfres;	 // "qvfres"
          case 'i':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 'm':	 // 1 string to match.
              return MCK_qvfrim;	 // "qvfrim"
            case 'n':	 // 1 string to match.
              return MCK_qvfrin;	 // "qvfrin"
            case 'p':	 // 1 string to match.
              return MCK_qvfrip;	 // "qvfrip"
            case 'z':	 // 1 string to match.
              return MCK_qvfriz;	 // "qvfriz"
            }
            break;
          case 's':	 // 1 string to match.
            if (Name[5] != 'p')
              break;
            return MCK_qvfrsp;	 // "qvfrsp"
          }
          break;
        case 's':	 // 3 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case 'l':	 // 1 string to match.
              return MCK_qvfsel;	 // "qvfsel"
            case 't':	 // 1 string to match.
              return MCK_qvfset;	 // "qvfset"
            }
            break;
          case 'u':	 // 1 string to match.
            if (Name[5] != 'b')
              break;
            return MCK_qvfsub;	 // "qvfsub"
          }
          break;
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+4, "or", 2))
            break;
          return MCK_qvfxor;	 // "qvfxor"
        }
        break;
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+3, "pci", 3))
          break;
        return MCK_qvgpci;	 // "qvgpci"
      case 'l':	 // 2 strings to match.
        if (Name[3] != 'f')
          break;
        switch (Name[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[5] != 'x')
            break;
          return MCK_qvlfdx;	 // "qvlfdx"
        case 's':	 // 1 string to match.
          if (Name[5] != 'x')
            break;
          return MCK_qvlfsx;	 // "qvlfsx"
        }
        break;
      }
      break;
    case 'r':	 // 9 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 3 strings to match.
          if (Name[3] != 'i')
            break;
          switch (Name[4]) {
          default: break;
          case 'c':	 // 2 strings to match.
            switch (Name[5]) {
            default: break;
            case 'l':	 // 1 string to match.
              return MCK_rldicl;	 // "rldicl"
            case 'r':	 // 1 string to match.
              return MCK_rldicr;	 // "rldicr"
            }
            break;
          case 'm':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_rldimi;	 // "rldimi"
          }
          break;
        case 'w':	 // 2 strings to match.
          if (Name[3] != 'i')
            break;
          switch (Name[4]) {
          default: break;
          case 'm':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_rlwimi;	 // "rlwimi"
          case 'n':	 // 1 string to match.
            if (Name[5] != 'm')
              break;
            return MCK_rlwinm;	 // "rlwinm"
          }
          break;
        }
        break;
      case 'o':	 // 4 strings to match.
        if (Name[2] != 't')
          break;
        switch (Name[3]) {
        default: break;
        case 'l':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_rotldi;	 // "rotldi"
          case 'w':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_rotlwi;	 // "rotlwi"
          }
          break;
        case 'r':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_rotrdi;	 // "rotrdi"
          case 'w':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_rotrwi;	 // "rotrwi"
          }
          break;
        }
        break;
      }
      break;
    case 's':	 // 18 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bmte", 4))
          break;
        return MCK_slbmte;	 // "slbmte"
      case 't':	 // 14 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 1 string to match.
          if (memcmp(Name.data()+3, "cix", 3))
            break;
          return MCK_stbcix;	 // "stbcix"
        case 'd':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (memcmp(Name.data()+4, "rx", 2))
              break;
            return MCK_stdbrx;	 // "stdbrx"
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ix", 2))
              break;
            return MCK_stdcix;	 // "stdcix"
          }
          break;
        case 'f':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ux", 2))
              break;
            return MCK_stfdux;	 // "stfdux"
          case 'i':	 // 1 string to match.
            if (memcmp(Name.data()+4, "wx", 2))
              break;
            return MCK_stfiwx;	 // "stfiwx"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ux", 2))
              break;
            return MCK_stfsux;	 // "stfsux"
          }
          break;
        case 'h':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (memcmp(Name.data()+4, "rx", 2))
              break;
            return MCK_sthbrx;	 // "sthbrx"
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ix", 2))
              break;
            return MCK_sthcix;	 // "sthcix"
          }
          break;
        case 'v':	 // 3 strings to match.
          if (Name[3] != 'e')
            break;
          switch (Name[4]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (Name[5] != 'x')
              break;
            return MCK_stvebx;	 // "stvebx"
          case 'h':	 // 1 string to match.
            if (Name[5] != 'x')
              break;
            return MCK_stvehx;	 // "stvehx"
          case 'w':	 // 1 string to match.
            if (Name[5] != 'x')
              break;
            return MCK_stvewx;	 // "stvewx"
          }
          break;
        case 'w':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (memcmp(Name.data()+4, "rx", 2))
              break;
            return MCK_stwbrx;	 // "stwbrx"
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ix", 2))
              break;
            return MCK_stwcix;	 // "stwcix"
          }
          break;
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+3, "sdx", 3))
            break;
          return MCK_stxsdx;	 // "stxsdx"
        }
        break;
      case 'u':	 // 3 strings to match.
        if (memcmp(Name.data()+2, "bf", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'i':	 // 1 string to match.
          if (Name[5] != 'c')
            break;
          return MCK_subfic;	 // "subfic"
        case 'm':	 // 1 string to match.
          if (Name[5] != 'e')
            break;
          return MCK_subfme;	 // "subfme"
        case 'z':	 // 1 string to match.
          if (Name[5] != 'e')
            break;
          return MCK_subfze;	 // "subfze"
        }
        break;
      }
      break;
    case 't':	 // 16 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bort", 4))
          break;
        return MCK_tabort;	 // "tabort"
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+2, "egin", 4))
          break;
        return MCK_tbegin;	 // "tbegin"
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+2, "heck", 4))
          break;
        return MCK_tcheck;	 // "tcheck"
      case 'd':	 // 6 strings to match.
        if (Name[2] != 'l')
          break;
        switch (Name[3]) {
        default: break;
        case 'g':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_tdlgei;	 // "tdlgei"
          case 't':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_tdlgti;	 // "tdlgti"
          }
          break;
        case 'l':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_tdllei;	 // "tdllei"
          case 't':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_tdllti;	 // "tdllti"
          }
          break;
        case 'n':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'g':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_tdlngi;	 // "tdlngi"
          case 'l':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_tdlnli;	 // "tdlnli"
          }
          break;
        }
        break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "biel", 4))
          break;
        return MCK_tlbiel;	 // "tlbiel"
      case 'w':	 // 6 strings to match.
        if (Name[2] != 'l')
          break;
        switch (Name[3]) {
        default: break;
        case 'g':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_twlgei;	 // "twlgei"
          case 't':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_twlgti;	 // "twlgti"
          }
          break;
        case 'l':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_twllei;	 // "twllei"
          case 't':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_twllti;	 // "twllti"
          }
          break;
        case 'n':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'g':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_twlngi;	 // "twlngi"
          case 'l':	 // 1 string to match.
            if (Name[5] != 'i')
              break;
            return MCK_twlnli;	 // "twlnli"
          }
          break;
        }
        break;
      }
      break;
    case 'v':	 // 40 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 7 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+3, "dfp", 3))
            break;
          return MCK_vaddfp;	 // "vaddfp"
        case 'v':	 // 6 strings to match.
          if (Name[3] != 'g')
            break;
          switch (Name[4]) {
          default: break;
          case 's':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vavgsb;	 // "vavgsb"
            case 'h':	 // 1 string to match.
              return MCK_vavgsh;	 // "vavgsh"
            case 'w':	 // 1 string to match.
              return MCK_vavgsw;	 // "vavgsw"
            }
            break;
          case 'u':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vavgub;	 // "vavgub"
            case 'h':	 // 1 string to match.
              return MCK_vavguh;	 // "vavguh"
            case 'w':	 // 1 string to match.
              return MCK_vavguw;	 // "vavguw"
            }
            break;
          }
          break;
        }
        break;
      case 'c':	 // 2 strings to match.
        if (Name[2] != 't')
          break;
        switch (Name[3]) {
        default: break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+4, "xs", 2))
            break;
          return MCK_vctsxs;	 // "vctsxs"
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+4, "xs", 2))
            break;
          return MCK_vctuxs;	 // "vctuxs"
        }
        break;
      case 'm':	 // 26 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 9 strings to match.
          if (Name[3] != 'x')
            break;
          switch (Name[4]) {
          default: break;
          case 'f':	 // 1 string to match.
            if (Name[5] != 'p')
              break;
            return MCK_vmaxfp;	 // "vmaxfp"
          case 's':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vmaxsb;	 // "vmaxsb"
            case 'd':	 // 1 string to match.
              return MCK_vmaxsd;	 // "vmaxsd"
            case 'h':	 // 1 string to match.
              return MCK_vmaxsh;	 // "vmaxsh"
            case 'w':	 // 1 string to match.
              return MCK_vmaxsw;	 // "vmaxsw"
            }
            break;
          case 'u':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vmaxub;	 // "vmaxub"
            case 'd':	 // 1 string to match.
              return MCK_vmaxud;	 // "vmaxud"
            case 'h':	 // 1 string to match.
              return MCK_vmaxuh;	 // "vmaxuh"
            case 'w':	 // 1 string to match.
              return MCK_vmaxuw;	 // "vmaxuw"
            }
            break;
          }
          break;
        case 'i':	 // 9 strings to match.
          if (Name[3] != 'n')
            break;
          switch (Name[4]) {
          default: break;
          case 'f':	 // 1 string to match.
            if (Name[5] != 'p')
              break;
            return MCK_vminfp;	 // "vminfp"
          case 's':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vminsb;	 // "vminsb"
            case 'd':	 // 1 string to match.
              return MCK_vminsd;	 // "vminsd"
            case 'h':	 // 1 string to match.
              return MCK_vminsh;	 // "vminsh"
            case 'w':	 // 1 string to match.
              return MCK_vminsw;	 // "vminsw"
            }
            break;
          case 'u':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vminub;	 // "vminub"
            case 'd':	 // 1 string to match.
              return MCK_vminud;	 // "vminud"
            case 'h':	 // 1 string to match.
              return MCK_vminuh;	 // "vminuh"
            case 'w':	 // 1 string to match.
              return MCK_vminuw;	 // "vminuw"
            }
            break;
          }
          break;
        case 'r':	 // 8 strings to match.
          if (Name[3] != 'g')
            break;
          switch (Name[4]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (Name[5] != 'w')
              break;
            return MCK_vmrgew;	 // "vmrgew"
          case 'h':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vmrghb;	 // "vmrghb"
            case 'h':	 // 1 string to match.
              return MCK_vmrghh;	 // "vmrghh"
            case 'w':	 // 1 string to match.
              return MCK_vmrghw;	 // "vmrghw"
            }
            break;
          case 'l':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vmrglb;	 // "vmrglb"
            case 'h':	 // 1 string to match.
              return MCK_vmrglh;	 // "vmrglh"
            case 'w':	 // 1 string to match.
              return MCK_vmrglw;	 // "vmrglw"
            }
            break;
          case 'o':	 // 1 string to match.
            if (Name[5] != 'w')
              break;
            return MCK_vmrgow;	 // "vmrgow"
          }
          break;
        }
        break;
      case 's':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+3, "doi", 3))
            break;
          return MCK_vsldoi;	 // "vsldoi"
        case 'p':	 // 3 strings to match.
          if (memcmp(Name.data()+3, "lt", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'b':	 // 1 string to match.
            return MCK_vspltb;	 // "vspltb"
          case 'h':	 // 1 string to match.
            return MCK_vsplth;	 // "vsplth"
          case 'w':	 // 1 string to match.
            return MCK_vspltw;	 // "vspltw"
          }
          break;
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+3, "bfp", 3))
            break;
          return MCK_vsubfp;	 // "vsubfp"
        }
        break;
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "rteei", 5))
        break;
      return MCK_wrteei;	 // "wrteei"
    case 'x':	 // 12 strings to match.
      switch (Name[1]) {
      default: break;
      case 's':	 // 3 strings to match.
        if (Name[2] != 'r')
          break;
        switch (Name[3]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+4, "pi", 2))
            break;
          return MCK_xsrdpi;	 // "xsrdpi"
        case 'e':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[5] != 'p')
              break;
            return MCK_xsredp;	 // "xsredp"
          case 's':	 // 1 string to match.
            if (Name[5] != 'p')
              break;
            return MCK_xsresp;	 // "xsresp"
          }
          break;
        }
        break;
      case 'v':	 // 4 strings to match.
        if (Name[2] != 'r')
          break;
        switch (Name[3]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+4, "pi", 2))
            break;
          return MCK_xvrdpi;	 // "xvrdpi"
        case 'e':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[5] != 'p')
              break;
            return MCK_xvredp;	 // "xvredp"
          case 's':	 // 1 string to match.
            if (Name[5] != 'p')
              break;
            return MCK_xvresp;	 // "xvresp"
          }
          break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+4, "pi", 2))
            break;
          return MCK_xvrspi;	 // "xvrspi"
        }
        break;
      case 'x':	 // 5 strings to match.
        if (Name[2] != 'l')
          break;
        switch (Name[3]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+4, "nd", 2))
            break;
          return MCK_xxland;	 // "xxland"
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+4, "qv", 2))
            break;
          return MCK_xxleqv;	 // "xxleqv"
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+4, "or", 2))
            break;
          return MCK_xxlnor;	 // "xxlnor"
        case 'o':	 // 1 string to match.
          if (memcmp(Name.data()+4, "rc", 2))
            break;
          return MCK_xxlorc;	 // "xxlorc"
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+4, "or", 2))
            break;
          return MCK_xxlxor;	 // "xxlxor"
        }
        break;
      }
      break;
    }
    break;
  case 7:	 // 298 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 77 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 13 strings to match.
        switch (Name[2]) {
        default: break;
        case 'n':	 // 9 strings to match.
          if (Name[3] != 'z')
            break;
          switch (Name[4]) {
          default: break;
          case 'f':	 // 2 strings to match.
            if (Name[5] != 'l')
              break;
            switch (Name[6]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_bdnzfla;	 // "bdnzfla"
            case 'r':	 // 1 string to match.
              return MCK_bdnzflr;	 // "bdnzflr"
            }
            break;
          case 'l':	 // 5 strings to match.
            switch (Name[5]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bdnzla_43_;	 // "bdnzla+"
              case '-':	 // 1 string to match.
                return MCK_bdnzla_MINUS_;	 // "bdnzla-"
              }
              break;
            case 'r':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case '+':	 // 1 string to match.
                return MCK_bdnzlr_43_;	 // "bdnzlr+"
              case '-':	 // 1 string to match.
                return MCK_bdnzlr_MINUS_;	 // "bdnzlr-"
              case 'l':	 // 1 string to match.
                return MCK_bdnzlrl;	 // "bdnzlrl"
              }
              break;
            }
            break;
          case 't':	 // 2 strings to match.
            if (Name[5] != 'l')
              break;
            switch (Name[6]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_bdnztla;	 // "bdnztla"
            case 'r':	 // 1 string to match.
              return MCK_bdnztlr;	 // "bdnztlr"
            }
            break;
          }
          break;
        case 'z':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case 'f':	 // 1 string to match.
            if (memcmp(Name.data()+4, "lrl", 3))
              break;
            return MCK_bdzflrl;	 // "bdzflrl"
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bdzlrl_43_;	 // "bdzlrl+"
            case '-':	 // 1 string to match.
              return MCK_bdzlrl_MINUS_;	 // "bdzlrl-"
            }
            break;
          case 't':	 // 1 string to match.
            if (memcmp(Name.data()+4, "lrl", 3))
              break;
            return MCK_bdztlrl;	 // "bdztlrl"
          }
          break;
        }
        break;
      case 'e':	 // 5 strings to match.
        if (Name[2] != 'q')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 3 strings to match.
          if (memcmp(Name.data()+4, "tr", 2))
            break;
          switch (Name[6]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_beqctr_43_;	 // "beqctr+"
          case '-':	 // 1 string to match.
            return MCK_beqctr_MINUS_;	 // "beqctr-"
          case 'l':	 // 1 string to match.
            return MCK_beqctrl;	 // "beqctrl"
          }
          break;
        case 'l':	 // 2 strings to match.
          if (memcmp(Name.data()+4, "rl", 2))
            break;
          switch (Name[6]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_beqlrl_43_;	 // "beqlrl+"
          case '-':	 // 1 string to match.
            return MCK_beqlrl_MINUS_;	 // "beqlrl-"
          }
          break;
        }
        break;
      case 'f':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "ctrl", 4))
          break;
        switch (Name[6]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_bfctrl_43_;	 // "bfctrl+"
        case '-':	 // 1 string to match.
          return MCK_bfctrl_MINUS_;	 // "bfctrl-"
        }
        break;
      case 'g':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 3 strings to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bgectr_43_;	 // "bgectr+"
            case '-':	 // 1 string to match.
              return MCK_bgectr_MINUS_;	 // "bgectr-"
            case 'l':	 // 1 string to match.
              return MCK_bgectrl;	 // "bgectrl"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bgelrl_43_;	 // "bgelrl+"
            case '-':	 // 1 string to match.
              return MCK_bgelrl_MINUS_;	 // "bgelrl-"
            }
            break;
          }
          break;
        case 't':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 3 strings to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bgtctr_43_;	 // "bgtctr+"
            case '-':	 // 1 string to match.
              return MCK_bgtctr_MINUS_;	 // "bgtctr-"
            case 'l':	 // 1 string to match.
              return MCK_bgtctrl;	 // "bgtctrl"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bgtlrl_43_;	 // "bgtlrl+"
            case '-':	 // 1 string to match.
              return MCK_bgtlrl_MINUS_;	 // "bgtlrl-"
            }
            break;
          }
          break;
        }
        break;
      case 'l':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 3 strings to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_blectr_43_;	 // "blectr+"
            case '-':	 // 1 string to match.
              return MCK_blectr_MINUS_;	 // "blectr-"
            case 'l':	 // 1 string to match.
              return MCK_blectrl;	 // "blectrl"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_blelrl_43_;	 // "blelrl+"
            case '-':	 // 1 string to match.
              return MCK_blelrl_MINUS_;	 // "blelrl-"
            }
            break;
          }
          break;
        case 't':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 3 strings to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bltctr_43_;	 // "bltctr+"
            case '-':	 // 1 string to match.
              return MCK_bltctr_MINUS_;	 // "bltctr-"
            case 'l':	 // 1 string to match.
              return MCK_bltctrl;	 // "bltctrl"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bltlrl_43_;	 // "bltlrl+"
            case '-':	 // 1 string to match.
              return MCK_bltlrl_MINUS_;	 // "bltlrl-"
            }
            break;
          }
          break;
        }
        break;
      case 'n':	 // 25 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 3 strings to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnectr_43_;	 // "bnectr+"
            case '-':	 // 1 string to match.
              return MCK_bnectr_MINUS_;	 // "bnectr-"
            case 'l':	 // 1 string to match.
              return MCK_bnectrl;	 // "bnectrl"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnelrl_43_;	 // "bnelrl+"
            case '-':	 // 1 string to match.
              return MCK_bnelrl_MINUS_;	 // "bnelrl-"
            }
            break;
          }
          break;
        case 'g':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 3 strings to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bngctr_43_;	 // "bngctr+"
            case '-':	 // 1 string to match.
              return MCK_bngctr_MINUS_;	 // "bngctr-"
            case 'l':	 // 1 string to match.
              return MCK_bngctrl;	 // "bngctrl"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnglrl_43_;	 // "bnglrl+"
            case '-':	 // 1 string to match.
              return MCK_bnglrl_MINUS_;	 // "bnglrl-"
            }
            break;
          }
          break;
        case 'l':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 3 strings to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnlctr_43_;	 // "bnlctr+"
            case '-':	 // 1 string to match.
              return MCK_bnlctr_MINUS_;	 // "bnlctr-"
            case 'l':	 // 1 string to match.
              return MCK_bnlctrl;	 // "bnlctrl"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnllrl_43_;	 // "bnllrl+"
            case '-':	 // 1 string to match.
              return MCK_bnllrl_MINUS_;	 // "bnllrl-"
            }
            break;
          }
          break;
        case 's':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 3 strings to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnsctr_43_;	 // "bnsctr+"
            case '-':	 // 1 string to match.
              return MCK_bnsctr_MINUS_;	 // "bnsctr-"
            case 'l':	 // 1 string to match.
              return MCK_bnsctrl;	 // "bnsctrl"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnslrl_43_;	 // "bnslrl+"
            case '-':	 // 1 string to match.
              return MCK_bnslrl_MINUS_;	 // "bnslrl-"
            }
            break;
          }
          break;
        case 'u':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 3 strings to match.
            if (memcmp(Name.data()+4, "tr", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnuctr_43_;	 // "bnuctr+"
            case '-':	 // 1 string to match.
              return MCK_bnuctr_MINUS_;	 // "bnuctr-"
            case 'l':	 // 1 string to match.
              return MCK_bnuctrl;	 // "bnuctrl"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "rl", 2))
              break;
            switch (Name[6]) {
            default: break;
            case '+':	 // 1 string to match.
              return MCK_bnulrl_43_;	 // "bnulrl+"
            case '-':	 // 1 string to match.
              return MCK_bnulrl_MINUS_;	 // "bnulrl-"
            }
            break;
          }
          break;
        }
        break;
      case 's':	 // 5 strings to match.
        if (Name[2] != 'o')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 3 strings to match.
          if (memcmp(Name.data()+4, "tr", 2))
            break;
          switch (Name[6]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bsoctr_43_;	 // "bsoctr+"
          case '-':	 // 1 string to match.
            return MCK_bsoctr_MINUS_;	 // "bsoctr-"
          case 'l':	 // 1 string to match.
            return MCK_bsoctrl;	 // "bsoctrl"
          }
          break;
        case 'l':	 // 2 strings to match.
          if (memcmp(Name.data()+4, "rl", 2))
            break;
          switch (Name[6]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bsolrl_43_;	 // "bsolrl+"
          case '-':	 // 1 string to match.
            return MCK_bsolrl_MINUS_;	 // "bsolrl-"
          }
          break;
        }
        break;
      case 't':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "ctrl", 4))
          break;
        switch (Name[6]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_btctrl_43_;	 // "btctrl+"
        case '-':	 // 1 string to match.
          return MCK_btctrl_MINUS_;	 // "btctrl-"
        }
        break;
      case 'u':	 // 5 strings to match.
        if (Name[2] != 'n')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 3 strings to match.
          if (memcmp(Name.data()+4, "tr", 2))
            break;
          switch (Name[6]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bunctr_43_;	 // "bunctr+"
          case '-':	 // 1 string to match.
            return MCK_bunctr_MINUS_;	 // "bunctr-"
          case 'l':	 // 1 string to match.
            return MCK_bunctrl;	 // "bunctrl"
          }
          break;
        case 'l':	 // 2 strings to match.
          if (memcmp(Name.data()+4, "rl", 2))
            break;
          switch (Name[6]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bunlrl_43_;	 // "bunlrl+"
          case '-':	 // 1 string to match.
            return MCK_bunlrl_MINUS_;	 // "bunlrl-"
          }
          break;
        }
        break;
      }
      break;
    case 'c':	 // 1 string to match.
      if (memcmp(Name.data()+1, "lrbhrb", 6))
        break;
      return MCK_clrbhrb;	 // "clrbhrb"
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "cbtstt", 6))
        break;
      return MCK_dcbtstt;	 // "dcbtstt"
    case 'e':	 // 23 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+3, "ddiw", 4))
          break;
        return MCK_evaddiw;	 // "evaddiw"
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+3, "mpeq", 4))
          break;
        return MCK_evcmpeq;	 // "evcmpeq"
      case 'd':	 // 2 strings to match.
        if (memcmp(Name.data()+3, "ivw", 3))
          break;
        switch (Name[6]) {
        default: break;
        case 's':	 // 1 string to match.
          return MCK_evdivws;	 // "evdivws"
        case 'u':	 // 1 string to match.
          return MCK_evdivwu;	 // "evdivwu"
        }
        break;
      case 'e':	 // 2 strings to match.
        if (memcmp(Name.data()+3, "xts", 3))
          break;
        switch (Name[6]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_evextsb;	 // "evextsb"
        case 'h':	 // 1 string to match.
          return MCK_evextsh;	 // "evextsh"
        }
        break;
      case 'l':	 // 3 strings to match.
        if (memcmp(Name.data()+3, "wh", 2))
          break;
        switch (Name[5]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (Name[6] != 'x')
            break;
          return MCK_evlwhex;	 // "evlwhex"
        case 'o':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 's':	 // 1 string to match.
            return MCK_evlwhos;	 // "evlwhos"
          case 'u':	 // 1 string to match.
            return MCK_evlwhou;	 // "evlwhou"
          }
          break;
        }
        break;
      case 'm':	 // 4 strings to match.
        if (Name[3] != 'w')
          break;
        switch (Name[4]) {
        default: break;
        case 's':	 // 3 strings to match.
          switch (Name[5]) {
          default: break;
          case 'm':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'f':	 // 1 string to match.
              return MCK_evmwsmf;	 // "evmwsmf"
            case 'i':	 // 1 string to match.
              return MCK_evmwsmi;	 // "evmwsmi"
            }
            break;
          case 's':	 // 1 string to match.
            if (Name[6] != 'f')
              break;
            return MCK_evmwssf;	 // "evmwssf"
          }
          break;
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+5, "mi", 2))
            break;
          return MCK_evmwumi;	 // "evmwumi"
        }
        break;
      case 's':	 // 10 strings to match.
        switch (Name[3]) {
        default: break;
        case 'r':	 // 2 strings to match.
          if (memcmp(Name.data()+4, "wi", 2))
            break;
          switch (Name[6]) {
          default: break;
          case 's':	 // 1 string to match.
            return MCK_evsrwis;	 // "evsrwis"
          case 'u':	 // 1 string to match.
            return MCK_evsrwiu;	 // "evsrwiu"
          }
          break;
        case 't':	 // 7 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'x')
                break;
              return MCK_evstddx;	 // "evstddx"
            case 'h':	 // 1 string to match.
              if (Name[6] != 'x')
                break;
              return MCK_evstdhx;	 // "evstdhx"
            case 'w':	 // 1 string to match.
              if (Name[6] != 'x')
                break;
              return MCK_evstdwx;	 // "evstdwx"
            }
            break;
          case 'w':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 'h':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_evstwhe;	 // "evstwhe"
              case 'o':	 // 1 string to match.
                return MCK_evstwho;	 // "evstwho"
              }
              break;
            case 'w':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_evstwwe;	 // "evstwwe"
              case 'o':	 // 1 string to match.
                return MCK_evstwwo;	 // "evstwwo"
              }
              break;
            }
            break;
          }
          break;
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+4, "bfw", 3))
            break;
          return MCK_evsubfw;	 // "evsubfw"
        }
        break;
      }
      break;
    case 'f':	 // 6 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'f':	 // 1 string to match.
          if (memcmp(Name.data()+3, "idus", 4))
            break;
          return MCK_fcfidus;	 // "fcfidus"
        case 't':	 // 2 strings to match.
          if (Name[3] != 'i')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+5, "uz", 2))
              break;
            return MCK_fctiduz;	 // "fctiduz"
          case 'w':	 // 1 string to match.
            if (memcmp(Name.data()+5, "uz", 2))
              break;
            return MCK_fctiwuz;	 // "fctiwuz"
          }
          break;
        }
        break;
      case 'n':	 // 2 strings to match.
        if (Name[2] != 'm')
          break;
        switch (Name[3]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+4, "dds", 3))
            break;
          return MCK_fnmadds;	 // "fnmadds"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+4, "ubs", 3))
            break;
          return MCK_fnmsubs;	 // "fnmsubs"
        }
        break;
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "sqrte", 5))
          break;
        return MCK_frsqrte;	 // "frsqrte"
      }
      break;
    case 'l':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "xsiw", 4))
        break;
      switch (Name[5]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (Name[6] != 'x')
          break;
        return MCK_lxsiwax;	 // "lxsiwax"
      case 'z':	 // 1 string to match.
        if (Name[6] != 'x')
          break;
        return MCK_lxsiwzx;	 // "lxsiwzx"
      }
      break;
    case 'm':	 // 30 strings to match.
      switch (Name[1]) {
      default: break;
      case 'f':	 // 15 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 1 string to match.
          if (memcmp(Name.data()+3, "hrbe", 4))
            break;
          return MCK_mfbhrbe;	 // "mfbhrbe"
        case 'd':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "at", 2))
              break;
            switch (Name[6]) {
            default: break;
            case 'l':	 // 1 string to match.
              return MCK_mfdbatl;	 // "mfdbatl"
            case 'u':	 // 1 string to match.
              return MCK_mfdbatu;	 // "mfdbatu"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+4, "isr", 3))
              break;
            return MCK_mfdsisr;	 // "mfdsisr"
          }
          break;
        case 'i':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "bat", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 'l':	 // 1 string to match.
            return MCK_mfibatl;	 // "mfibatl"
          case 'u':	 // 1 string to match.
            return MCK_mfibatu;	 // "mfibatu"
          }
          break;
        case 's':	 // 8 strings to match.
          if (memcmp(Name.data()+3, "prg", 3))
            break;
          switch (Name[6]) {
          default: break;
          case '0':	 // 1 string to match.
            return MCK_mfsprg0;	 // "mfsprg0"
          case '1':	 // 1 string to match.
            return MCK_mfsprg1;	 // "mfsprg1"
          case '2':	 // 1 string to match.
            return MCK_mfsprg2;	 // "mfsprg2"
          case '3':	 // 1 string to match.
            return MCK_mfsprg3;	 // "mfsprg3"
          case '4':	 // 1 string to match.
            return MCK_mfsprg4;	 // "mfsprg4"
          case '5':	 // 1 string to match.
            return MCK_mfsprg5;	 // "mfsprg5"
          case '6':	 // 1 string to match.
            return MCK_mfsprg6;	 // "mfsprg6"
          case '7':	 // 1 string to match.
            return MCK_mfsprg7;	 // "mfsprg7"
          }
          break;
        case 'v':	 // 1 string to match.
          if (memcmp(Name.data()+3, "srwz", 4))
            break;
          return MCK_mfvsrwz;	 // "mfvsrwz"
        }
        break;
      case 't':	 // 15 strings to match.
        switch (Name[2]) {
        default: break;
        case 'd':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "at", 2))
              break;
            switch (Name[6]) {
            default: break;
            case 'l':	 // 1 string to match.
              return MCK_mtdbatl;	 // "mtdbatl"
            case 'u':	 // 1 string to match.
              return MCK_mtdbatu;	 // "mtdbatu"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+4, "isr", 3))
              break;
            return MCK_mtdsisr;	 // "mtdsisr"
          }
          break;
        case 'i':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "bat", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 'l':	 // 1 string to match.
            return MCK_mtibatl;	 // "mtibatl"
          case 'u':	 // 1 string to match.
            return MCK_mtibatu;	 // "mtibatu"
          }
          break;
        case 's':	 // 8 strings to match.
          if (memcmp(Name.data()+3, "prg", 3))
            break;
          switch (Name[6]) {
          default: break;
          case '0':	 // 1 string to match.
            return MCK_mtsprg0;	 // "mtsprg0"
          case '1':	 // 1 string to match.
            return MCK_mtsprg1;	 // "mtsprg1"
          case '2':	 // 1 string to match.
            return MCK_mtsprg2;	 // "mtsprg2"
          case '3':	 // 1 string to match.
            return MCK_mtsprg3;	 // "mtsprg3"
          case '4':	 // 1 string to match.
            return MCK_mtsprg4;	 // "mtsprg4"
          case '5':	 // 1 string to match.
            return MCK_mtsprg5;	 // "mtsprg5"
          case '6':	 // 1 string to match.
            return MCK_mtsprg6;	 // "mtsprg6"
          case '7':	 // 1 string to match.
            return MCK_mtsprg7;	 // "mtsprg7"
          }
          break;
        case 'v':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "srw", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 'a':	 // 1 string to match.
            return MCK_mtvsrwa;	 // "mtvsrwa"
          case 'z':	 // 1 string to match.
            return MCK_mtvsrwz;	 // "mtvsrwz"
          }
          break;
        }
        break;
      }
      break;
    case 'p':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'o':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "pcnt", 4))
          break;
        switch (Name[6]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_popcntd;	 // "popcntd"
        case 'w':	 // 1 string to match.
          return MCK_popcntw;	 // "popcntw"
        }
        break;
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+2, "esync", 5))
          break;
        return MCK_ptesync;	 // "ptesync"
      }
      break;
    case 'q':	 // 22 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'f':	 // 14 strings to match.
        switch (Name[3]) {
        default: break;
        case 'a':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+5, "ds", 2))
              break;
            return MCK_qvfadds;	 // "qvfadds"
          case 'n':	 // 1 string to match.
            if (memcmp(Name.data()+5, "dc", 2))
              break;
            return MCK_qvfandc;	 // "qvfandc"
          }
          break;
        case 'c':	 // 4 strings to match.
          switch (Name[4]) {
          default: break;
          case 'f':	 // 1 string to match.
            if (memcmp(Name.data()+5, "id", 2))
              break;
            return MCK_qvfcfid;	 // "qvfcfid"
          case 't':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case 'f':	 // 1 string to match.
              if (Name[6] != 'b')
                break;
              return MCK_qvfctfb;	 // "qvfctfb"
            case 'i':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'd':	 // 1 string to match.
                return MCK_qvfctid;	 // "qvfctid"
              case 'w':	 // 1 string to match.
                return MCK_qvfctiw;	 // "qvfctiw"
              }
              break;
            }
            break;
          }
          break;
        case 'm':	 // 3 strings to match.
          switch (Name[4]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+5, "dd", 2))
              break;
            return MCK_qvfmadd;	 // "qvfmadd"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+5, "ub", 2))
              break;
            return MCK_qvfmsub;	 // "qvfmsub"
          case 'u':	 // 1 string to match.
            if (memcmp(Name.data()+5, "ls", 2))
              break;
            return MCK_qvfmuls;	 // "qvfmuls"
          }
          break;
        case 'n':	 // 2 strings to match.
          if (Name[4] != 'a')
            break;
          switch (Name[5]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (Name[6] != 's')
              break;
            return MCK_qvfnabs;	 // "qvfnabs"
          case 'n':	 // 1 string to match.
            if (Name[6] != 'd')
              break;
            return MCK_qvfnand;	 // "qvfnand"
          }
          break;
        case 'p':	 // 1 string to match.
          if (memcmp(Name.data()+4, "erm", 3))
            break;
          return MCK_qvfperm;	 // "qvfperm"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+4, "ubs", 3))
            break;
          return MCK_qvfsubs;	 // "qvfsubs"
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+4, "mul", 3))
            break;
          return MCK_qvfxmul;	 // "qvfxmul"
        }
        break;
      case 'l':	 // 6 strings to match.
        if (Name[3] != 'f')
          break;
        switch (Name[4]) {
        default: break;
        case 'c':	 // 2 strings to match.
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[6] != 'x')
              break;
            return MCK_qvlfcdx;	 // "qvlfcdx"
          case 's':	 // 1 string to match.
            if (Name[6] != 'x')
              break;
            return MCK_qvlfcsx;	 // "qvlfcsx"
          }
          break;
        case 'd':	 // 2 strings to match.
          switch (Name[5]) {
          default: break;
          case 'u':	 // 1 string to match.
            if (Name[6] != 'x')
              break;
            return MCK_qvlfdux;	 // "qvlfdux"
          case 'x':	 // 1 string to match.
            if (Name[6] != 'a')
              break;
            return MCK_qvlfdxa;	 // "qvlfdxa"
          }
          break;
        case 's':	 // 2 strings to match.
          switch (Name[5]) {
          default: break;
          case 'u':	 // 1 string to match.
            if (Name[6] != 'x')
              break;
            return MCK_qvlfsux;	 // "qvlfsux"
          case 'x':	 // 1 string to match.
            if (Name[6] != 'a')
              break;
            return MCK_qvlfsxa;	 // "qvlfsxa"
          }
          break;
        }
        break;
      case 's':	 // 2 strings to match.
        if (memcmp(Name.data()+3, "tf", 2))
          break;
        switch (Name[5]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[6] != 'x')
            break;
          return MCK_qvstfdx;	 // "qvstfdx"
        case 's':	 // 1 string to match.
          if (Name[6] != 'x')
            break;
          return MCK_qvstfsx;	 // "qvstfsx"
        }
        break;
      }
      break;
    case 's':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bmfee", 5))
          break;
        return MCK_slbmfee;	 // "slbmfee"
      case 't':	 // 4 strings to match.
        if (Name[2] != 'x')
          break;
        switch (Name[3]) {
        default: break;
        case 's':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'i':	 // 1 string to match.
            if (memcmp(Name.data()+5, "wx", 2))
              break;
            return MCK_stxsiwx;	 // "stxsiwx"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+5, "px", 2))
              break;
            return MCK_stxsspx;	 // "stxsspx"
          }
          break;
        case 'v':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+5, "2x", 2))
              break;
            return MCK_stxvd2x;	 // "stxvd2x"
          case 'w':	 // 1 string to match.
            if (memcmp(Name.data()+5, "4x", 2))
              break;
            return MCK_stxvw4x;	 // "stxvw4x"
          }
          break;
        }
        break;
      }
      break;
    case 't':	 // 6 strings to match.
      if (memcmp(Name.data()+1, "lb", 2))
        break;
      switch (Name[3]) {
      default: break;
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+4, "vax", 3))
          break;
        return MCK_tlbivax;	 // "tlbivax"
      case 'r':	 // 2 strings to match.
        if (Name[4] != 'e')
          break;
        switch (Name[5]) {
        default: break;
        case 'h':	 // 1 string to match.
          if (Name[6] != 'i')
            break;
          return MCK_tlbrehi;	 // "tlbrehi"
        case 'l':	 // 1 string to match.
          if (Name[6] != 'o')
            break;
          return MCK_tlbrelo;	 // "tlbrelo"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+4, "ync", 3))
          break;
        return MCK_tlbsync;	 // "tlbsync"
      case 'w':	 // 2 strings to match.
        if (Name[4] != 'e')
          break;
        switch (Name[5]) {
        default: break;
        case 'h':	 // 1 string to match.
          if (Name[6] != 'i')
            break;
          return MCK_tlbwehi;	 // "tlbwehi"
        case 'l':	 // 1 string to match.
          if (Name[6] != 'o')
            break;
          return MCK_tlbwelo;	 // "tlbwelo"
        }
        break;
      }
      break;
    case 'v':	 // 69 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 13 strings to match.
        if (memcmp(Name.data()+2, "dd", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'c':	 // 2 strings to match.
          if (Name[5] != 'u')
            break;
          switch (Name[6]) {
          default: break;
          case 'q':	 // 1 string to match.
            return MCK_vaddcuq;	 // "vaddcuq"
          case 'w':	 // 1 string to match.
            return MCK_vaddcuw;	 // "vaddcuw"
          }
          break;
        case 's':	 // 3 strings to match.
          switch (Name[5]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (Name[6] != 's')
              break;
            return MCK_vaddsbs;	 // "vaddsbs"
          case 'h':	 // 1 string to match.
            if (Name[6] != 's')
              break;
            return MCK_vaddshs;	 // "vaddshs"
          case 'w':	 // 1 string to match.
            if (Name[6] != 's')
              break;
            return MCK_vaddsws;	 // "vaddsws"
          }
          break;
        case 'u':	 // 8 strings to match.
          switch (Name[5]) {
          default: break;
          case 'b':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'm':	 // 1 string to match.
              return MCK_vaddubm;	 // "vaddubm"
            case 's':	 // 1 string to match.
              return MCK_vaddubs;	 // "vaddubs"
            }
            break;
          case 'd':	 // 1 string to match.
            if (Name[6] != 'm')
              break;
            return MCK_vaddudm;	 // "vaddudm"
          case 'h':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'm':	 // 1 string to match.
              return MCK_vadduhm;	 // "vadduhm"
            case 's':	 // 1 string to match.
              return MCK_vadduhs;	 // "vadduhs"
            }
            break;
          case 'q':	 // 1 string to match.
            if (Name[6] != 'm')
              break;
            return MCK_vadduqm;	 // "vadduqm"
          case 'w':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'm':	 // 1 string to match.
              return MCK_vadduwm;	 // "vadduwm"
            case 's':	 // 1 string to match.
              return MCK_vadduws;	 // "vadduws"
            }
            break;
          }
          break;
        }
        break;
      case 'b':	 // 1 string to match.
        if (memcmp(Name.data()+2, "permq", 5))
          break;
        return MCK_vbpermq;	 // "vbpermq"
      case 'c':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+3, "pher", 4))
            break;
          return MCK_vcipher;	 // "vcipher"
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "pbfp", 4))
            break;
          return MCK_vcmpbfp;	 // "vcmpbfp"
        }
        break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ogefp", 5))
          break;
        return MCK_vlogefp;	 // "vlogefp"
      case 'm':	 // 14 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ddfp", 4))
            break;
          return MCK_vmaddfp;	 // "vmaddfp"
        case 'u':	 // 13 strings to match.
          if (Name[3] != 'l')
            break;
          switch (Name[4]) {
          default: break;
          case 'e':	 // 6 strings to match.
            switch (Name[5]) {
            default: break;
            case 's':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'b':	 // 1 string to match.
                return MCK_vmulesb;	 // "vmulesb"
              case 'h':	 // 1 string to match.
                return MCK_vmulesh;	 // "vmulesh"
              case 'w':	 // 1 string to match.
                return MCK_vmulesw;	 // "vmulesw"
              }
              break;
            case 'u':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'b':	 // 1 string to match.
                return MCK_vmuleub;	 // "vmuleub"
              case 'h':	 // 1 string to match.
                return MCK_vmuleuh;	 // "vmuleuh"
              case 'w':	 // 1 string to match.
                return MCK_vmuleuw;	 // "vmuleuw"
              }
              break;
            }
            break;
          case 'o':	 // 6 strings to match.
            switch (Name[5]) {
            default: break;
            case 's':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'b':	 // 1 string to match.
                return MCK_vmulosb;	 // "vmulosb"
              case 'h':	 // 1 string to match.
                return MCK_vmulosh;	 // "vmulosh"
              case 'w':	 // 1 string to match.
                return MCK_vmulosw;	 // "vmulosw"
              }
              break;
            case 'u':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'b':	 // 1 string to match.
                return MCK_vmuloub;	 // "vmuloub"
              case 'h':	 // 1 string to match.
                return MCK_vmulouh;	 // "vmulouh"
              case 'w':	 // 1 string to match.
                return MCK_vmulouw;	 // "vmulouw"
              }
              break;
            }
            break;
          case 'u':	 // 1 string to match.
            if (memcmp(Name.data()+5, "wm", 2))
              break;
            return MCK_vmuluwm;	 // "vmuluwm"
          }
          break;
        }
        break;
      case 'p':	 // 16 strings to match.
        switch (Name[2]) {
        default: break;
        case 'k':	 // 12 strings to match.
          switch (Name[3]) {
          default: break;
          case 's':	 // 6 strings to match.
            switch (Name[4]) {
            default: break;
            case 'd':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case 's':	 // 1 string to match.
                if (Name[6] != 's')
                  break;
                return MCK_vpksdss;	 // "vpksdss"
              case 'u':	 // 1 string to match.
                if (Name[6] != 's')
                  break;
                return MCK_vpksdus;	 // "vpksdus"
              }
              break;
            case 'h':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case 's':	 // 1 string to match.
                if (Name[6] != 's')
                  break;
                return MCK_vpkshss;	 // "vpkshss"
              case 'u':	 // 1 string to match.
                if (Name[6] != 's')
                  break;
                return MCK_vpkshus;	 // "vpkshus"
              }
              break;
            case 'w':	 // 2 strings to match.
              switch (Name[5]) {
              default: break;
              case 's':	 // 1 string to match.
                if (Name[6] != 's')
                  break;
                return MCK_vpkswss;	 // "vpkswss"
              case 'u':	 // 1 string to match.
                if (Name[6] != 's')
                  break;
                return MCK_vpkswus;	 // "vpkswus"
              }
              break;
            }
            break;
          case 'u':	 // 6 strings to match.
            switch (Name[4]) {
            default: break;
            case 'd':	 // 2 strings to match.
              if (Name[5] != 'u')
                break;
              switch (Name[6]) {
              default: break;
              case 'm':	 // 1 string to match.
                return MCK_vpkudum;	 // "vpkudum"
              case 's':	 // 1 string to match.
                return MCK_vpkudus;	 // "vpkudus"
              }
              break;
            case 'h':	 // 2 strings to match.
              if (Name[5] != 'u')
                break;
              switch (Name[6]) {
              default: break;
              case 'm':	 // 1 string to match.
                return MCK_vpkuhum;	 // "vpkuhum"
              case 's':	 // 1 string to match.
                return MCK_vpkuhus;	 // "vpkuhus"
              }
              break;
            case 'w':	 // 2 strings to match.
              if (Name[5] != 'u')
                break;
              switch (Name[6]) {
              default: break;
              case 'm':	 // 1 string to match.
                return MCK_vpkuwum;	 // "vpkuwum"
              case 's':	 // 1 string to match.
                return MCK_vpkuwus;	 // "vpkuwus"
              }
              break;
            }
            break;
          }
          break;
        case 'm':	 // 4 strings to match.
          if (memcmp(Name.data()+3, "sum", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 'b':	 // 1 string to match.
            return MCK_vpmsumb;	 // "vpmsumb"
          case 'd':	 // 1 string to match.
            return MCK_vpmsumd;	 // "vpmsumd"
          case 'h':	 // 1 string to match.
            return MCK_vpmsumh;	 // "vpmsumh"
          case 'w':	 // 1 string to match.
            return MCK_vpmsumw;	 // "vpmsumw"
          }
          break;
        }
        break;
      case 's':	 // 14 strings to match.
        if (Name[2] != 'u')
          break;
        switch (Name[3]) {
        default: break;
        case 'b':	 // 13 strings to match.
          switch (Name[4]) {
          default: break;
          case 'c':	 // 2 strings to match.
            if (Name[5] != 'u')
              break;
            switch (Name[6]) {
            default: break;
            case 'q':	 // 1 string to match.
              return MCK_vsubcuq;	 // "vsubcuq"
            case 'w':	 // 1 string to match.
              return MCK_vsubcuw;	 // "vsubcuw"
            }
            break;
          case 's':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 1 string to match.
              if (Name[6] != 's')
                break;
              return MCK_vsubsbs;	 // "vsubsbs"
            case 'h':	 // 1 string to match.
              if (Name[6] != 's')
                break;
              return MCK_vsubshs;	 // "vsubshs"
            case 'w':	 // 1 string to match.
              if (Name[6] != 's')
                break;
              return MCK_vsubsws;	 // "vsubsws"
            }
            break;
          case 'u':	 // 8 strings to match.
            switch (Name[5]) {
            default: break;
            case 'b':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 1 string to match.
                return MCK_vsububm;	 // "vsububm"
              case 's':	 // 1 string to match.
                return MCK_vsububs;	 // "vsububs"
              }
              break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'm')
                break;
              return MCK_vsubudm;	 // "vsubudm"
            case 'h':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 1 string to match.
                return MCK_vsubuhm;	 // "vsubuhm"
              case 's':	 // 1 string to match.
                return MCK_vsubuhs;	 // "vsubuhs"
              }
              break;
            case 'q':	 // 1 string to match.
              if (Name[6] != 'm')
                break;
              return MCK_vsubuqm;	 // "vsubuqm"
            case 'w':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 1 string to match.
                return MCK_vsubuwm;	 // "vsubuwm"
              case 's':	 // 1 string to match.
                return MCK_vsubuws;	 // "vsubuws"
              }
              break;
            }
            break;
          }
          break;
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+4, "sws", 3))
            break;
          return MCK_vsumsws;	 // "vsumsws"
        }
        break;
      case 'u':	 // 8 strings to match.
        if (memcmp(Name.data()+2, "pk", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'h':	 // 4 strings to match.
          switch (Name[5]) {
          default: break;
          case 'p':	 // 1 string to match.
            if (Name[6] != 'x')
              break;
            return MCK_vupkhpx;	 // "vupkhpx"
          case 's':	 // 3 strings to match.
            switch (Name[6]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vupkhsb;	 // "vupkhsb"
            case 'h':	 // 1 string to match.
              return MCK_vupkhsh;	 // "vupkhsh"
            case 'w':	 // 1 string to match.
              return MCK_vupkhsw;	 // "vupkhsw"
            }
            break;
          }
          break;
        case 'l':	 // 4 strings to match.
          switch (Name[5]) {
          default: break;
          case 'p':	 // 1 string to match.
            if (Name[6] != 'x')
              break;
            return MCK_vupklpx;	 // "vupklpx"
          case 's':	 // 3 strings to match.
            switch (Name[6]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vupklsb;	 // "vupklsb"
            case 'h':	 // 1 string to match.
              return MCK_vupklsh;	 // "vupklsh"
            case 'w':	 // 1 string to match.
              return MCK_vupklsw;	 // "vupklsw"
            }
            break;
          }
          break;
        }
        break;
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "aitrsv", 6))
        break;
      return MCK_waitrsv;	 // "waitrsv"
    case 'x':	 // 52 strings to match.
      switch (Name[1]) {
      default: break;
      case 's':	 // 16 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (memcmp(Name.data()+4, "sdp", 3))
              break;
            return MCK_xsabsdp;	 // "xsabsdp"
          case 'd':	 // 2 strings to match.
            if (Name[4] != 'd')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xsadddp;	 // "xsadddp"
            case 's':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xsaddsp;	 // "xsaddsp"
            }
            break;
          }
          break;
        case 'd':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "iv", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xsdivdp;	 // "xsdivdp"
          case 's':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xsdivsp;	 // "xsdivsp"
          }
          break;
        case 'm':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+4, "xdp", 3))
              break;
            return MCK_xsmaxdp;	 // "xsmaxdp"
          case 'i':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ndp", 3))
              break;
            return MCK_xsmindp;	 // "xsmindp"
          case 'u':	 // 2 strings to match.
            if (Name[4] != 'l')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xsmuldp;	 // "xsmuldp"
            case 's':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xsmulsp;	 // "xsmulsp"
            }
            break;
          }
          break;
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+3, "egdp", 4))
            break;
          return MCK_xsnegdp;	 // "xsnegdp"
        case 'r':	 // 4 strings to match.
          if (memcmp(Name.data()+3, "dpi", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 'c':	 // 1 string to match.
            return MCK_xsrdpic;	 // "xsrdpic"
          case 'm':	 // 1 string to match.
            return MCK_xsrdpim;	 // "xsrdpim"
          case 'p':	 // 1 string to match.
            return MCK_xsrdpip;	 // "xsrdpip"
          case 'z':	 // 1 string to match.
            return MCK_xsrdpiz;	 // "xsrdpiz"
          }
          break;
        case 's':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ub", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xssubdp;	 // "xssubdp"
          case 's':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xssubsp;	 // "xssubsp"
          }
          break;
        }
        break;
      case 'v':	 // 26 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 2 strings to match.
            if (Name[4] != 's')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvabsdp;	 // "xvabsdp"
            case 's':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvabssp;	 // "xvabssp"
            }
            break;
          case 'd':	 // 2 strings to match.
            if (Name[4] != 'd')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvadddp;	 // "xvadddp"
            case 's':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvaddsp;	 // "xvaddsp"
            }
            break;
          }
          break;
        case 'd':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "iv", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xvdivdp;	 // "xvdivdp"
          case 's':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xvdivsp;	 // "xvdivsp"
          }
          break;
        case 'm':	 // 8 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            if (Name[4] != 'x')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvmaxdp;	 // "xvmaxdp"
            case 's':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvmaxsp;	 // "xvmaxsp"
            }
            break;
          case 'i':	 // 2 strings to match.
            if (Name[4] != 'n')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvmindp;	 // "xvmindp"
            case 's':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvminsp;	 // "xvminsp"
            }
            break;
          case 'o':	 // 2 strings to match.
            if (Name[4] != 'v')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvmovdp;	 // "xvmovdp"
            case 's':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvmovsp;	 // "xvmovsp"
            }
            break;
          case 'u':	 // 2 strings to match.
            if (Name[4] != 'l')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvmuldp;	 // "xvmuldp"
            case 's':	 // 1 string to match.
              if (Name[6] != 'p')
                break;
              return MCK_xvmulsp;	 // "xvmulsp"
            }
            break;
          }
          break;
        case 'n':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "eg", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xvnegdp;	 // "xvnegdp"
          case 's':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xvnegsp;	 // "xvnegsp"
          }
          break;
        case 'r':	 // 8 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 4 strings to match.
            if (memcmp(Name.data()+4, "pi", 2))
              break;
            switch (Name[6]) {
            default: break;
            case 'c':	 // 1 string to match.
              return MCK_xvrdpic;	 // "xvrdpic"
            case 'm':	 // 1 string to match.
              return MCK_xvrdpim;	 // "xvrdpim"
            case 'p':	 // 1 string to match.
              return MCK_xvrdpip;	 // "xvrdpip"
            case 'z':	 // 1 string to match.
              return MCK_xvrdpiz;	 // "xvrdpiz"
            }
            break;
          case 's':	 // 4 strings to match.
            if (memcmp(Name.data()+4, "pi", 2))
              break;
            switch (Name[6]) {
            default: break;
            case 'c':	 // 1 string to match.
              return MCK_xvrspic;	 // "xvrspic"
            case 'm':	 // 1 string to match.
              return MCK_xvrspim;	 // "xvrspim"
            case 'p':	 // 1 string to match.
              return MCK_xvrspip;	 // "xvrspip"
            case 'z':	 // 1 string to match.
              return MCK_xvrspiz;	 // "xvrspiz"
            }
            break;
          }
          break;
        case 's':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ub", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xvsubdp;	 // "xvsubdp"
          case 's':	 // 1 string to match.
            if (Name[6] != 'p')
              break;
            return MCK_xvsubsp;	 // "xvsubsp"
          }
          break;
        }
        break;
      case 'x':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case 'l':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ndc", 3))
              break;
            return MCK_xxlandc;	 // "xxlandc"
          case 'n':	 // 1 string to match.
            if (memcmp(Name.data()+4, "and", 3))
              break;
            return MCK_xxlnand;	 // "xxlnand"
          }
          break;
        case 'm':	 // 4 strings to match.
          if (memcmp(Name.data()+3, "rg", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'h':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'd':	 // 1 string to match.
              return MCK_xxmrghd;	 // "xxmrghd"
            case 'w':	 // 1 string to match.
              return MCK_xxmrghw;	 // "xxmrghw"
            }
            break;
          case 'l':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'd':	 // 1 string to match.
              return MCK_xxmrgld;	 // "xxmrgld"
            case 'w':	 // 1 string to match.
              return MCK_xxmrglw;	 // "xxmrglw"
            }
            break;
          }
          break;
        case 's':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+4, "dwi", 3))
              break;
            return MCK_xxsldwi;	 // "xxsldwi"
          case 'p':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "lt", 2))
              break;
            switch (Name[6]) {
            default: break;
            case 'd':	 // 1 string to match.
              return MCK_xxspltd;	 // "xxspltd"
            case 'w':	 // 1 string to match.
              return MCK_xxspltw;	 // "xxspltw"
            }
            break;
          case 'w':	 // 1 string to match.
            if (memcmp(Name.data()+4, "apd", 3))
              break;
            return MCK_xxswapd;	 // "xxswapd"
          }
          break;
        }
        break;
      }
      break;
    }
    break;
  case 8:	 // 164 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 28 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 4 strings to match.
        if (memcmp(Name.data()+2, "nz", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'f':	 // 1 string to match.
          if (memcmp(Name.data()+5, "lrl", 3))
            break;
          return MCK_bdnzflrl;	 // "bdnzflrl"
        case 'l':	 // 2 strings to match.
          if (memcmp(Name.data()+5, "rl", 2))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bdnzlrl_43_;	 // "bdnzlrl+"
          case '-':	 // 1 string to match.
            return MCK_bdnzlrl_MINUS_;	 // "bdnzlrl-"
          }
          break;
        case 't':	 // 1 string to match.
          if (memcmp(Name.data()+5, "lrl", 3))
            break;
          return MCK_bdnztlrl;	 // "bdnztlrl"
        }
        break;
      case 'e':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "qctrl", 5))
          break;
        switch (Name[7]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_beqctrl_43_;	 // "beqctrl+"
        case '-':	 // 1 string to match.
          return MCK_beqctrl_MINUS_;	 // "beqctrl-"
        }
        break;
      case 'g':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ctrl", 4))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bgectrl_43_;	 // "bgectrl+"
          case '-':	 // 1 string to match.
            return MCK_bgectrl_MINUS_;	 // "bgectrl-"
          }
          break;
        case 't':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ctrl", 4))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bgtctrl_43_;	 // "bgtctrl+"
          case '-':	 // 1 string to match.
            return MCK_bgtctrl_MINUS_;	 // "bgtctrl-"
          }
          break;
        }
        break;
      case 'l':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ctrl", 4))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_blectrl_43_;	 // "blectrl+"
          case '-':	 // 1 string to match.
            return MCK_blectrl_MINUS_;	 // "blectrl-"
          }
          break;
        case 't':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ctrl", 4))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bltctrl_43_;	 // "bltctrl+"
          case '-':	 // 1 string to match.
            return MCK_bltctrl_MINUS_;	 // "bltctrl-"
          }
          break;
        }
        break;
      case 'n':	 // 10 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ctrl", 4))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bnectrl_43_;	 // "bnectrl+"
          case '-':	 // 1 string to match.
            return MCK_bnectrl_MINUS_;	 // "bnectrl-"
          }
          break;
        case 'g':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ctrl", 4))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bngctrl_43_;	 // "bngctrl+"
          case '-':	 // 1 string to match.
            return MCK_bngctrl_MINUS_;	 // "bngctrl-"
          }
          break;
        case 'l':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ctrl", 4))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bnlctrl_43_;	 // "bnlctrl+"
          case '-':	 // 1 string to match.
            return MCK_bnlctrl_MINUS_;	 // "bnlctrl-"
          }
          break;
        case 's':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ctrl", 4))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bnsctrl_43_;	 // "bnsctrl+"
          case '-':	 // 1 string to match.
            return MCK_bnsctrl_MINUS_;	 // "bnsctrl-"
          }
          break;
        case 'u':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ctrl", 4))
            break;
          switch (Name[7]) {
          default: break;
          case '+':	 // 1 string to match.
            return MCK_bnuctrl_43_;	 // "bnuctrl+"
          case '-':	 // 1 string to match.
            return MCK_bnuctrl_MINUS_;	 // "bnuctrl-"
          }
          break;
        }
        break;
      case 's':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "octrl", 5))
          break;
        switch (Name[7]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_bsoctrl_43_;	 // "bsoctrl+"
        case '-':	 // 1 string to match.
          return MCK_bsoctrl_MINUS_;	 // "bsoctrl-"
        }
        break;
      case 'u':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "nctrl", 5))
          break;
        switch (Name[7]) {
        default: break;
        case '+':	 // 1 string to match.
          return MCK_bunctrl_43_;	 // "bunctrl+"
        case '-':	 // 1 string to match.
          return MCK_bunctrl_MINUS_;	 // "bunctrl-"
        }
        break;
      }
      break;
    case 'c':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "lrlsl", 5))
        break;
      switch (Name[6]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (Name[7] != 'i')
          break;
        return MCK_clrlsldi;	 // "clrlsldi"
      case 'w':	 // 1 string to match.
        if (Name[7] != 'i')
          break;
        return MCK_clrlslwi;	 // "clrlslwi"
      }
      break;
    case 'd':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "cbtst", 5))
        break;
      switch (Name[6]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (Name[7] != 't')
          break;
        return MCK_dcbtstct;	 // "dcbtstct"
      case 'd':	 // 1 string to match.
        if (Name[7] != 's')
          break;
        return MCK_dcbtstds;	 // "dcbtstds"
      }
      break;
    case 'e':	 // 31 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'c':	 // 6 strings to match.
        switch (Name[3]) {
        default: break;
        case 'm':	 // 4 strings to match.
          if (Name[4] != 'p')
            break;
          switch (Name[5]) {
          default: break;
          case 'g':	 // 2 strings to match.
            if (Name[6] != 't')
              break;
            switch (Name[7]) {
            default: break;
            case 's':	 // 1 string to match.
              return MCK_evcmpgts;	 // "evcmpgts"
            case 'u':	 // 1 string to match.
              return MCK_evcmpgtu;	 // "evcmpgtu"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (Name[6] != 't')
              break;
            switch (Name[7]) {
            default: break;
            case 's':	 // 1 string to match.
              return MCK_evcmplts;	 // "evcmplts"
            case 'u':	 // 1 string to match.
              return MCK_evcmpltu;	 // "evcmpltu"
            }
            break;
          }
          break;
        case 'n':	 // 2 strings to match.
          if (memcmp(Name.data()+4, "tl", 2))
            break;
          switch (Name[6]) {
          default: break;
          case 's':	 // 1 string to match.
            if (Name[7] != 'w')
              break;
            return MCK_evcntlsw;	 // "evcntlsw"
          case 'z':	 // 1 string to match.
            if (Name[7] != 'w')
              break;
            return MCK_evcntlzw;	 // "evcntlzw"
          }
          break;
        }
        break;
      case 'l':	 // 2 strings to match.
        if (memcmp(Name.data()+3, "who", 3))
          break;
        switch (Name[6]) {
        default: break;
        case 's':	 // 1 string to match.
          if (Name[7] != 'x')
            break;
          return MCK_evlwhosx;	 // "evlwhosx"
        case 'u':	 // 1 string to match.
          if (Name[7] != 'x')
            break;
          return MCK_evlwhoux;	 // "evlwhoux"
        }
        break;
      case 'm':	 // 17 strings to match.
        switch (Name[3]) {
        default: break;
        case 'h':	 // 8 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 's':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 1 string to match.
                  return MCK_evmhesmf;	 // "evmhesmf"
                case 'i':	 // 1 string to match.
                  return MCK_evmhesmi;	 // "evmhesmi"
                }
                break;
              case 's':	 // 1 string to match.
                if (Name[7] != 'f')
                  break;
                return MCK_evmhessf;	 // "evmhessf"
              }
              break;
            case 'u':	 // 1 string to match.
              if (memcmp(Name.data()+6, "mi", 2))
                break;
              return MCK_evmheumi;	 // "evmheumi"
            }
            break;
          case 'o':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 's':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 1 string to match.
                  return MCK_evmhosmf;	 // "evmhosmf"
                case 'i':	 // 1 string to match.
                  return MCK_evmhosmi;	 // "evmhosmi"
                }
                break;
              case 's':	 // 1 string to match.
                if (Name[7] != 'f')
                  break;
                return MCK_evmhossf;	 // "evmhossf"
              }
              break;
            case 'u':	 // 1 string to match.
              if (memcmp(Name.data()+6, "mi", 2))
                break;
              return MCK_evmhoumi;	 // "evmhoumi"
            }
            break;
          }
          break;
        case 'w':	 // 9 strings to match.
          switch (Name[4]) {
          default: break;
          case 'h':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 's':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 1 string to match.
                  return MCK_evmwhsmf;	 // "evmwhsmf"
                case 'i':	 // 1 string to match.
                  return MCK_evmwhsmi;	 // "evmwhsmi"
                }
                break;
              case 's':	 // 1 string to match.
                if (Name[7] != 'f')
                  break;
                return MCK_evmwhssf;	 // "evmwhssf"
              }
              break;
            case 'u':	 // 1 string to match.
              if (memcmp(Name.data()+6, "mi", 2))
                break;
              return MCK_evmwhumi;	 // "evmwhumi"
            }
            break;
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+5, "umi", 3))
              break;
            return MCK_evmwlumi;	 // "evmwlumi"
          case 's':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case 'm':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'f':	 // 1 string to match.
                if (Name[7] != 'a')
                  break;
                return MCK_evmwsmfa;	 // "evmwsmfa"
              case 'i':	 // 1 string to match.
                if (Name[7] != 'a')
                  break;
                return MCK_evmwsmia;	 // "evmwsmia"
              }
              break;
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+6, "fa", 2))
                break;
              return MCK_evmwssfa;	 // "evmwssfa"
            }
            break;
          case 'u':	 // 1 string to match.
            if (memcmp(Name.data()+5, "mia", 3))
              break;
            return MCK_evmwumia;	 // "evmwumia"
          }
          break;
        }
        break;
      case 's':	 // 6 strings to match.
        switch (Name[3]) {
        default: break;
        case 'p':	 // 1 string to match.
          if (memcmp(Name.data()+4, "lati", 4))
            break;
          return MCK_evsplati;	 // "evsplati"
        case 't':	 // 4 strings to match.
          if (Name[4] != 'w')
            break;
          switch (Name[5]) {
          default: break;
          case 'h':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'e':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_evstwhex;	 // "evstwhex"
            case 'o':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_evstwhox;	 // "evstwhox"
            }
            break;
          case 'w':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'e':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_evstwwex;	 // "evstwwex"
            case 'o':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_evstwwox;	 // "evstwwox"
            }
            break;
          }
          break;
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+4, "bifw", 4))
            break;
          return MCK_evsubifw;	 // "evsubifw"
        }
        break;
      }
      break;
    case 'f':	 // 1 string to match.
      if (memcmp(Name.data()+1, "rsqrtes", 7))
        break;
      return MCK_frsqrtes;	 // "frsqrtes"
    case 'q':	 // 38 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+3, "ligni", 5))
          break;
        return MCK_qvaligni;	 // "qvaligni"
      case 'f':	 // 16 strings to match.
        switch (Name[3]) {
        default: break;
        case 'c':	 // 10 strings to match.
          switch (Name[4]) {
          default: break;
          case 'f':	 // 2 strings to match.
            if (memcmp(Name.data()+5, "id", 2))
              break;
            switch (Name[7]) {
            default: break;
            case 's':	 // 1 string to match.
              return MCK_qvfcfids;	 // "qvfcfids"
            case 'u':	 // 1 string to match.
              return MCK_qvfcfidu;	 // "qvfcfidu"
            }
            break;
          case 'm':	 // 3 strings to match.
            if (Name[5] != 'p')
              break;
            switch (Name[6]) {
            default: break;
            case 'e':	 // 1 string to match.
              if (Name[7] != 'q')
                break;
              return MCK_qvfcmpeq;	 // "qvfcmpeq"
            case 'g':	 // 1 string to match.
              if (Name[7] != 't')
                break;
              return MCK_qvfcmpgt;	 // "qvfcmpgt"
            case 'l':	 // 1 string to match.
              if (Name[7] != 't')
                break;
              return MCK_qvfcmplt;	 // "qvfcmplt"
            }
            break;
          case 'p':	 // 1 string to match.
            if (memcmp(Name.data()+5, "sgn", 3))
              break;
            return MCK_qvfcpsgn;	 // "qvfcpsgn"
          case 't':	 // 4 strings to match.
            if (Name[5] != 'i')
              break;
            switch (Name[6]) {
            default: break;
            case 'd':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'u':	 // 1 string to match.
                return MCK_qvfctidu;	 // "qvfctidu"
              case 'z':	 // 1 string to match.
                return MCK_qvfctidz;	 // "qvfctidz"
              }
              break;
            case 'w':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'u':	 // 1 string to match.
                return MCK_qvfctiwu;	 // "qvfctiwu"
              case 'z':	 // 1 string to match.
                return MCK_qvfctiwz;	 // "qvfctiwz"
              }
              break;
            }
            break;
          }
          break;
        case 'm':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+5, "dds", 3))
              break;
            return MCK_qvfmadds;	 // "qvfmadds"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+5, "ubs", 3))
              break;
            return MCK_qvfmsubs;	 // "qvfmsubs"
          }
          break;
        case 'n':	 // 2 strings to match.
          if (Name[4] != 'm')
            break;
          switch (Name[5]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+6, "dd", 2))
              break;
            return MCK_qvfnmadd;	 // "qvfnmadd"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+6, "ub", 2))
              break;
            return MCK_qvfnmsub;	 // "qvfnmsub"
          }
          break;
        case 'x':	 // 2 strings to match.
          if (Name[4] != 'm')
            break;
          switch (Name[5]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+6, "dd", 2))
              break;
            return MCK_qvfxmadd;	 // "qvfxmadd"
          case 'u':	 // 1 string to match.
            if (memcmp(Name.data()+6, "ls", 2))
              break;
            return MCK_qvfxmuls;	 // "qvfxmuls"
          }
          break;
        }
        break;
      case 'l':	 // 12 strings to match.
        switch (Name[3]) {
        default: break;
        case 'f':	 // 8 strings to match.
          switch (Name[4]) {
          default: break;
          case 'c':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 'd':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'u':	 // 1 string to match.
                if (Name[7] != 'x')
                  break;
                return MCK_qvlfcdux;	 // "qvlfcdux"
              case 'x':	 // 1 string to match.
                if (Name[7] != 'a')
                  break;
                return MCK_qvlfcdxa;	 // "qvlfcdxa"
              }
              break;
            case 's':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'u':	 // 1 string to match.
                if (Name[7] != 'x')
                  break;
                return MCK_qvlfcsux;	 // "qvlfcsux"
              case 'x':	 // 1 string to match.
                if (Name[7] != 'a')
                  break;
                return MCK_qvlfcsxa;	 // "qvlfcsxa"
              }
              break;
            }
            break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+5, "uxa", 3))
              break;
            return MCK_qvlfduxa;	 // "qvlfduxa"
          case 'i':	 // 2 strings to match.
            if (Name[5] != 'w')
              break;
            switch (Name[6]) {
            default: break;
            case 'a':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_qvlfiwax;	 // "qvlfiwax"
            case 'z':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_qvlfiwzx;	 // "qvlfiwzx"
            }
            break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+5, "uxa", 3))
              break;
            return MCK_qvlfsuxa;	 // "qvlfsuxa"
          }
          break;
        case 'p':	 // 4 strings to match.
          if (Name[4] != 'c')
            break;
          switch (Name[5]) {
          default: break;
          case 'l':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_qvlpcldx;	 // "qvlpcldx"
            case 's':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_qvlpclsx;	 // "qvlpclsx"
            }
            break;
          case 'r':	 // 2 strings to match.
            switch (Name[6]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_qvlpcrdx;	 // "qvlpcrdx"
            case 's':	 // 1 string to match.
              if (Name[7] != 'x')
                break;
              return MCK_qvlpcrsx;	 // "qvlpcrsx"
            }
            break;
          }
          break;
        }
        break;
      case 's':	 // 9 strings to match.
        if (memcmp(Name.data()+3, "tf", 2))
          break;
        switch (Name[5]) {
        default: break;
        case 'c':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[7] != 'x')
              break;
            return MCK_qvstfcdx;	 // "qvstfcdx"
          case 's':	 // 1 string to match.
            if (Name[7] != 'x')
              break;
            return MCK_qvstfcsx;	 // "qvstfcsx"
          }
          break;
        case 'd':	 // 3 strings to match.
          switch (Name[6]) {
          default: break;
          case 'u':	 // 1 string to match.
            if (Name[7] != 'x')
              break;
            return MCK_qvstfdux;	 // "qvstfdux"
          case 'x':	 // 2 strings to match.
            switch (Name[7]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_qvstfdxa;	 // "qvstfdxa"
            case 'i':	 // 1 string to match.
              return MCK_qvstfdxi;	 // "qvstfdxi"
            }
            break;
          }
          break;
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+6, "wx", 2))
            break;
          return MCK_qvstfiwx;	 // "qvstfiwx"
        case 's':	 // 3 strings to match.
          switch (Name[6]) {
          default: break;
          case 'u':	 // 1 string to match.
            if (Name[7] != 'x')
              break;
            return MCK_qvstfsux;	 // "qvstfsux"
          case 'x':	 // 2 strings to match.
            switch (Name[7]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_qvstfsxa;	 // "qvstfsxa"
            case 'i':	 // 1 string to match.
              return MCK_qvstfsxi;	 // "qvstfsxi"
            }
            break;
          }
          break;
        }
        break;
      }
      break;
    case 't':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "bort", 4))
          break;
        switch (Name[6]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (Name[7] != 'c')
            break;
          return MCK_tabortdc;	 // "tabortdc"
        case 'w':	 // 1 string to match.
          if (Name[7] != 'c')
            break;
          return MCK_tabortwc;	 // "tabortwc"
        }
        break;
      case 'r':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "ec", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'h':	 // 1 string to match.
          if (memcmp(Name.data()+5, "kpt", 3))
            break;
          return MCK_trechkpt;	 // "trechkpt"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+5, "aim", 3))
            break;
          return MCK_treclaim;	 // "treclaim"
        }
        break;
      }
      break;
    case 'v':	 // 40 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "dde", 3))
          break;
        switch (Name[5]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+6, "uq", 2))
            break;
          return MCK_vaddecuq;	 // "vaddecuq"
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+6, "qm", 2))
            break;
          return MCK_vaddeuqm;	 // "vaddeuqm"
        }
        break;
      case 'c':	 // 15 strings to match.
        if (memcmp(Name.data()+2, "mp", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'e':	 // 5 strings to match.
          if (Name[5] != 'q')
            break;
          switch (Name[6]) {
          default: break;
          case 'f':	 // 1 string to match.
            if (Name[7] != 'p')
              break;
            return MCK_vcmpeqfp;	 // "vcmpeqfp"
          case 'u':	 // 4 strings to match.
            switch (Name[7]) {
            default: break;
            case 'b':	 // 1 string to match.
              return MCK_vcmpequb;	 // "vcmpequb"
            case 'd':	 // 1 string to match.
              return MCK_vcmpequd;	 // "vcmpequd"
            case 'h':	 // 1 string to match.
              return MCK_vcmpequh;	 // "vcmpequh"
            case 'w':	 // 1 string to match.
              return MCK_vcmpequw;	 // "vcmpequw"
            }
            break;
          }
          break;
        case 'g':	 // 10 strings to match.
          switch (Name[5]) {
          default: break;
          case 'e':	 // 1 string to match.
            if (memcmp(Name.data()+6, "fp", 2))
              break;
            return MCK_vcmpgefp;	 // "vcmpgefp"
          case 't':	 // 9 strings to match.
            switch (Name[6]) {
            default: break;
            case 'f':	 // 1 string to match.
              if (Name[7] != 'p')
                break;
              return MCK_vcmpgtfp;	 // "vcmpgtfp"
            case 's':	 // 4 strings to match.
              switch (Name[7]) {
              default: break;
              case 'b':	 // 1 string to match.
                return MCK_vcmpgtsb;	 // "vcmpgtsb"
              case 'd':	 // 1 string to match.
                return MCK_vcmpgtsd;	 // "vcmpgtsd"
              case 'h':	 // 1 string to match.
                return MCK_vcmpgtsh;	 // "vcmpgtsh"
              case 'w':	 // 1 string to match.
                return MCK_vcmpgtsw;	 // "vcmpgtsw"
              }
              break;
            case 'u':	 // 4 strings to match.
              switch (Name[7]) {
              default: break;
              case 'b':	 // 1 string to match.
                return MCK_vcmpgtub;	 // "vcmpgtub"
              case 'd':	 // 1 string to match.
                return MCK_vcmpgtud;	 // "vcmpgtud"
              case 'h':	 // 1 string to match.
                return MCK_vcmpgtuh;	 // "vcmpgtuh"
              case 'w':	 // 1 string to match.
                return MCK_vcmpgtuw;	 // "vcmpgtuw"
              }
              break;
            }
            break;
          }
          break;
        }
        break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "xptefp", 6))
          break;
        return MCK_vexptefp;	 // "vexptefp"
      case 'm':	 // 6 strings to match.
        if (memcmp(Name.data()+2, "sum", 3))
          break;
        switch (Name[5]) {
        default: break;
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+6, "bm", 2))
            break;
          return MCK_vmsummbm;	 // "vmsummbm"
        case 's':	 // 2 strings to match.
          if (Name[6] != 'h')
            break;
          switch (Name[7]) {
          default: break;
          case 'm':	 // 1 string to match.
            return MCK_vmsumshm;	 // "vmsumshm"
          case 's':	 // 1 string to match.
            return MCK_vmsumshs;	 // "vmsumshs"
          }
          break;
        case 'u':	 // 3 strings to match.
          switch (Name[6]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (Name[7] != 'm')
              break;
            return MCK_vmsumubm;	 // "vmsumubm"
          case 'h':	 // 2 strings to match.
            switch (Name[7]) {
            default: break;
            case 'm':	 // 1 string to match.
              return MCK_vmsumuhm;	 // "vmsumuhm"
            case 's':	 // 1 string to match.
              return MCK_vmsumuhs;	 // "vmsumuhs"
            }
            break;
          }
          break;
        }
        break;
      case 'n':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ipher", 5))
            break;
          return MCK_vncipher;	 // "vncipher"
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "subfp", 5))
            break;
          return MCK_vnmsubfp;	 // "vnmsubfp"
        }
        break;
      case 'p':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rmxor", 5))
            break;
          return MCK_vpermxor;	 // "vpermxor"
        case 'o':	 // 4 strings to match.
          if (memcmp(Name.data()+3, "pcnt", 4))
            break;
          switch (Name[7]) {
          default: break;
          case 'b':	 // 1 string to match.
            return MCK_vpopcntb;	 // "vpopcntb"
          case 'd':	 // 1 string to match.
            return MCK_vpopcntd;	 // "vpopcntd"
          case 'h':	 // 1 string to match.
            return MCK_vpopcnth;	 // "vpopcnth"
          case 'w':	 // 1 string to match.
            return MCK_vpopcntw;	 // "vpopcntw"
          }
          break;
        }
        break;
      case 's':	 // 9 strings to match.
        switch (Name[2]) {
        default: break;
        case 'p':	 // 3 strings to match.
          if (memcmp(Name.data()+3, "ltis", 4))
            break;
          switch (Name[7]) {
          default: break;
          case 'b':	 // 1 string to match.
            return MCK_vspltisb;	 // "vspltisb"
          case 'h':	 // 1 string to match.
            return MCK_vspltish;	 // "vspltish"
          case 'w':	 // 1 string to match.
            return MCK_vspltisw;	 // "vspltisw"
          }
          break;
        case 'u':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 2 strings to match.
            if (Name[4] != 'e')
              break;
            switch (Name[5]) {
            default: break;
            case 'c':	 // 1 string to match.
              if (memcmp(Name.data()+6, "uq", 2))
                break;
              return MCK_vsubecuq;	 // "vsubecuq"
            case 'u':	 // 1 string to match.
              if (memcmp(Name.data()+6, "qm", 2))
                break;
              return MCK_vsubeuqm;	 // "vsubeuqm"
            }
            break;
          case 'm':	 // 4 strings to match.
            switch (Name[4]) {
            default: break;
            case '2':	 // 1 string to match.
              if (memcmp(Name.data()+5, "sws", 3))
                break;
              return MCK_vsum2sws;	 // "vsum2sws"
            case '4':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case 's':	 // 2 strings to match.
                switch (Name[6]) {
                default: break;
                case 'b':	 // 1 string to match.
                  if (Name[7] != 's')
                    break;
                  return MCK_vsum4sbs;	 // "vsum4sbs"
                case 'h':	 // 1 string to match.
                  if (Name[7] != 's')
                    break;
                  return MCK_vsum4shs;	 // "vsum4shs"
                }
                break;
              case 'u':	 // 1 string to match.
                if (memcmp(Name.data()+6, "bs", 2))
                  break;
                return MCK_vsum4ubs;	 // "vsum4ubs"
              }
              break;
            }
            break;
          }
          break;
        }
        break;
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "aitimpl", 7))
        break;
      return MCK_waitimpl;	 // "waitimpl"
    case 'x':	 // 17 strings to match.
      switch (Name[1]) {
      default: break;
      case 's':	 // 8 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 4 strings to match.
          switch (Name[3]) {
          default: break;
          case 'm':	 // 2 strings to match.
            if (Name[4] != 'p')
              break;
            switch (Name[5]) {
            default: break;
            case 'o':	 // 1 string to match.
              if (memcmp(Name.data()+6, "dp", 2))
                break;
              return MCK_xscmpodp;	 // "xscmpodp"
            case 'u':	 // 1 string to match.
              if (memcmp(Name.data()+6, "dp", 2))
                break;
              return MCK_xscmpudp;	 // "xscmpudp"
            }
            break;
          case 'v':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (memcmp(Name.data()+5, "psp", 3))
                break;
              return MCK_xscvdpsp;	 // "xscvdpsp"
            case 's':	 // 1 string to match.
              if (memcmp(Name.data()+5, "pdp", 3))
                break;
              return MCK_xscvspdp;	 // "xscvspdp"
            }
            break;
          }
          break;
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+3, "absdp", 5))
            break;
          return MCK_xsnabsdp;	 // "xsnabsdp"
        case 's':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "qrt", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[7] != 'p')
              break;
            return MCK_xssqrtdp;	 // "xssqrtdp"
          case 's':	 // 1 string to match.
            if (Name[7] != 'p')
              break;
            return MCK_xssqrtsp;	 // "xssqrtsp"
          }
          break;
        case 't':	 // 1 string to match.
          if (memcmp(Name.data()+3, "divdp", 5))
            break;
          return MCK_xstdivdp;	 // "xstdivdp"
        }
        break;
      case 'v':	 // 8 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 2 strings to match.
          if (Name[3] != 'v')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+5, "psp", 3))
              break;
            return MCK_xvcvdpsp;	 // "xvcvdpsp"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+5, "pdp", 3))
              break;
            return MCK_xvcvspdp;	 // "xvcvspdp"
          }
          break;
        case 'n':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "abs", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[7] != 'p')
              break;
            return MCK_xvnabsdp;	 // "xvnabsdp"
          case 's':	 // 1 string to match.
            if (Name[7] != 'p')
              break;
            return MCK_xvnabssp;	 // "xvnabssp"
          }
          break;
        case 's':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "qrt", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[7] != 'p')
              break;
            return MCK_xvsqrtdp;	 // "xvsqrtdp"
          case 's':	 // 1 string to match.
            if (Name[7] != 'p')
              break;
            return MCK_xvsqrtsp;	 // "xvsqrtsp"
          }
          break;
        case 't':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "div", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[7] != 'p')
              break;
            return MCK_xvtdivdp;	 // "xvtdivdp"
          case 's':	 // 1 string to match.
            if (Name[7] != 'p')
              break;
            return MCK_xvtdivsp;	 // "xvtdivsp"
          }
          break;
        }
        break;
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+2, "permdi", 6))
          break;
        return MCK_xxpermdi;	 // "xxpermdi"
      }
      break;
    }
    break;
  case 9:	 // 100 strings to match.
    switch (Name[0]) {
    default: break;
    case 'e':	 // 24 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'm':	 // 23 strings to match.
        switch (Name[3]) {
        default: break;
        case 'e':	 // 2 strings to match.
          if (memcmp(Name.data()+4, "rge", 3))
            break;
          switch (Name[7]) {
          default: break;
          case 'h':	 // 1 string to match.
            if (Name[8] != 'i')
              break;
            return MCK_evmergehi;	 // "evmergehi"
          case 'l':	 // 1 string to match.
            if (Name[8] != 'o')
              break;
            return MCK_evmergelo;	 // "evmergelo"
          }
          break;
        case 'h':	 // 8 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 's':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 1 string to match.
                  if (Name[8] != 'a')
                    break;
                  return MCK_evmhesmfa;	 // "evmhesmfa"
                case 'i':	 // 1 string to match.
                  if (Name[8] != 'a')
                    break;
                  return MCK_evmhesmia;	 // "evmhesmia"
                }
                break;
              case 's':	 // 1 string to match.
                if (memcmp(Name.data()+7, "fa", 2))
                  break;
                return MCK_evmhessfa;	 // "evmhessfa"
              }
              break;
            case 'u':	 // 1 string to match.
              if (memcmp(Name.data()+6, "mia", 3))
                break;
              return MCK_evmheumia;	 // "evmheumia"
            }
            break;
          case 'o':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 's':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 1 string to match.
                  if (Name[8] != 'a')
                    break;
                  return MCK_evmhosmfa;	 // "evmhosmfa"
                case 'i':	 // 1 string to match.
                  if (Name[8] != 'a')
                    break;
                  return MCK_evmhosmia;	 // "evmhosmia"
                }
                break;
              case 's':	 // 1 string to match.
                if (memcmp(Name.data()+7, "fa", 2))
                  break;
                return MCK_evmhossfa;	 // "evmhossfa"
              }
              break;
            case 'u':	 // 1 string to match.
              if (memcmp(Name.data()+6, "mia", 3))
                break;
              return MCK_evmhoumia;	 // "evmhoumia"
            }
            break;
          }
          break;
        case 'w':	 // 13 strings to match.
          switch (Name[4]) {
          default: break;
          case 'h':	 // 4 strings to match.
            switch (Name[5]) {
            default: break;
            case 's':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 1 string to match.
                  if (Name[8] != 'a')
                    break;
                  return MCK_evmwhsmfa;	 // "evmwhsmfa"
                case 'i':	 // 1 string to match.
                  if (Name[8] != 'a')
                    break;
                  return MCK_evmwhsmia;	 // "evmwhsmia"
                }
                break;
              case 's':	 // 1 string to match.
                if (memcmp(Name.data()+7, "fa", 2))
                  break;
                return MCK_evmwhssfa;	 // "evmwhssfa"
              }
              break;
            case 'u':	 // 1 string to match.
              if (memcmp(Name.data()+6, "mia", 3))
                break;
              return MCK_evmwhumia;	 // "evmwhumia"
            }
            break;
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+5, "umia", 4))
              break;
            return MCK_evmwlumia;	 // "evmwlumia"
          case 's':	 // 6 strings to match.
            switch (Name[5]) {
            default: break;
            case 'm':	 // 4 strings to match.
              switch (Name[6]) {
              default: break;
              case 'f':	 // 2 strings to match.
                if (Name[7] != 'a')
                  break;
                switch (Name[8]) {
                default: break;
                case 'a':	 // 1 string to match.
                  return MCK_evmwsmfaa;	 // "evmwsmfaa"
                case 'n':	 // 1 string to match.
                  return MCK_evmwsmfan;	 // "evmwsmfan"
                }
                break;
              case 'i':	 // 2 strings to match.
                if (Name[7] != 'a')
                  break;
                switch (Name[8]) {
                default: break;
                case 'a':	 // 1 string to match.
                  return MCK_evmwsmiaa;	 // "evmwsmiaa"
                case 'n':	 // 1 string to match.
                  return MCK_evmwsmian;	 // "evmwsmian"
                }
                break;
              }
              break;
            case 's':	 // 2 strings to match.
              if (memcmp(Name.data()+6, "fa", 2))
                break;
              switch (Name[8]) {
              default: break;
              case 'a':	 // 1 string to match.
                return MCK_evmwssfaa;	 // "evmwssfaa"
              case 'n':	 // 1 string to match.
                return MCK_evmwssfan;	 // "evmwssfan"
              }
              break;
            }
            break;
          case 'u':	 // 2 strings to match.
            if (memcmp(Name.data()+5, "mia", 3))
              break;
            switch (Name[8]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_evmwumiaa;	 // "evmwumiaa"
            case 'n':	 // 1 string to match.
              return MCK_evmwumian;	 // "evmwumian"
            }
            break;
          }
          break;
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+3, "platfi", 6))
          break;
        return MCK_evsplatfi;	 // "evsplatfi"
      }
      break;
    case 'm':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'f':	 // 1 string to match.
        if (memcmp(Name.data()+2, "spefscr", 7))
          break;
        return MCK_mfspefscr;	 // "mfspefscr"
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+2, "spefscr", 7))
          break;
        return MCK_mtspefscr;	 // "mtspefscr"
      }
      break;
    case 'q':	 // 27 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+3, "splati", 6))
          break;
        return MCK_qvesplati;	 // "qvesplati"
      case 'f':	 // 9 strings to match.
        switch (Name[3]) {
        default: break;
        case 'c':	 // 3 strings to match.
          switch (Name[4]) {
          default: break;
          case 'f':	 // 1 string to match.
            if (memcmp(Name.data()+5, "idus", 4))
              break;
            return MCK_qvfcfidus;	 // "qvfcfidus"
          case 't':	 // 2 strings to match.
            if (Name[5] != 'i')
              break;
            switch (Name[6]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (memcmp(Name.data()+7, "uz", 2))
                break;
              return MCK_qvfctiduz;	 // "qvfctiduz"
            case 'w':	 // 1 string to match.
              if (memcmp(Name.data()+7, "uz", 2))
                break;
              return MCK_qvfctiwuz;	 // "qvfctiwuz"
            }
            break;
          }
          break;
        case 'n':	 // 2 strings to match.
          if (Name[4] != 'm')
            break;
          switch (Name[5]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+6, "dds", 3))
              break;
            return MCK_qvfnmadds;	 // "qvfnmadds"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+6, "ubs", 3))
              break;
            return MCK_qvfnmsubs;	 // "qvfnmsubs"
          }
          break;
        case 'r':	 // 1 string to match.
          if (memcmp(Name.data()+4, "sqrte", 5))
            break;
          return MCK_qvfrsqrte;	 // "qvfrsqrte"
        case 't':	 // 1 string to match.
          if (memcmp(Name.data()+4, "stnan", 5))
            break;
          return MCK_qvftstnan;	 // "qvftstnan"
        case 'x':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'm':	 // 1 string to match.
            if (memcmp(Name.data()+5, "adds", 4))
              break;
            return MCK_qvfxmadds;	 // "qvfxmadds"
          case 'x':	 // 1 string to match.
            if (memcmp(Name.data()+5, "madd", 4))
              break;
            return MCK_qvfxxmadd;	 // "qvfxxmadd"
          }
          break;
        }
        break;
      case 'l':	 // 4 strings to match.
        if (Name[3] != 'f')
          break;
        switch (Name[4]) {
        default: break;
        case 'c':	 // 2 strings to match.
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (memcmp(Name.data()+6, "uxa", 3))
              break;
            return MCK_qvlfcduxa;	 // "qvlfcduxa"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+6, "uxa", 3))
              break;
            return MCK_qvlfcsuxa;	 // "qvlfcsuxa"
          }
          break;
        case 'i':	 // 2 strings to match.
          if (Name[5] != 'w')
            break;
          switch (Name[6]) {
          default: break;
          case 'a':	 // 1 string to match.
            if (memcmp(Name.data()+7, "xa", 2))
              break;
            return MCK_qvlfiwaxa;	 // "qvlfiwaxa"
          case 'z':	 // 1 string to match.
            if (memcmp(Name.data()+7, "xa", 2))
              break;
            return MCK_qvlfiwzxa;	 // "qvlfiwzxa"
          }
          break;
        }
        break;
      case 's':	 // 13 strings to match.
        if (memcmp(Name.data()+3, "tf", 2))
          break;
        switch (Name[5]) {
        default: break;
        case 'c':	 // 6 strings to match.
          switch (Name[6]) {
          default: break;
          case 'd':	 // 3 strings to match.
            switch (Name[7]) {
            default: break;
            case 'u':	 // 1 string to match.
              if (Name[8] != 'x')
                break;
              return MCK_qvstfcdux;	 // "qvstfcdux"
            case 'x':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'a':	 // 1 string to match.
                return MCK_qvstfcdxa;	 // "qvstfcdxa"
              case 'i':	 // 1 string to match.
                return MCK_qvstfcdxi;	 // "qvstfcdxi"
              }
              break;
            }
            break;
          case 's':	 // 3 strings to match.
            switch (Name[7]) {
            default: break;
            case 'u':	 // 1 string to match.
              if (Name[8] != 'x')
                break;
              return MCK_qvstfcsux;	 // "qvstfcsux"
            case 'x':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'a':	 // 1 string to match.
                return MCK_qvstfcsxa;	 // "qvstfcsxa"
              case 'i':	 // 1 string to match.
                return MCK_qvstfcsxi;	 // "qvstfcsxi"
              }
              break;
            }
            break;
          }
          break;
        case 'd':	 // 3 strings to match.
          switch (Name[6]) {
          default: break;
          case 'u':	 // 2 strings to match.
            if (Name[7] != 'x')
              break;
            switch (Name[8]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_qvstfduxa;	 // "qvstfduxa"
            case 'i':	 // 1 string to match.
              return MCK_qvstfduxi;	 // "qvstfduxi"
            }
            break;
          case 'x':	 // 1 string to match.
            if (memcmp(Name.data()+7, "ia", 2))
              break;
            return MCK_qvstfdxia;	 // "qvstfdxia"
          }
          break;
        case 'i':	 // 1 string to match.
          if (memcmp(Name.data()+6, "wxa", 3))
            break;
          return MCK_qvstfiwxa;	 // "qvstfiwxa"
        case 's':	 // 3 strings to match.
          switch (Name[6]) {
          default: break;
          case 'u':	 // 2 strings to match.
            if (Name[7] != 'x')
              break;
            switch (Name[8]) {
            default: break;
            case 'a':	 // 1 string to match.
              return MCK_qvstfsuxa;	 // "qvstfsuxa"
            case 'i':	 // 1 string to match.
              return MCK_qvstfsuxi;	 // "qvstfsuxi"
            }
            break;
          case 'x':	 // 1 string to match.
            if (memcmp(Name.data()+7, "ia", 2))
              break;
            return MCK_qvstfsxia;	 // "qvstfsxia"
          }
          break;
        }
        break;
      }
      break;
    case 't':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "abort", 5))
        break;
      switch (Name[6]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+7, "ci", 2))
          break;
        return MCK_tabortdci;	 // "tabortdci"
      case 'w':	 // 1 string to match.
        if (memcmp(Name.data()+7, "ci", 2))
          break;
        return MCK_tabortwci;	 // "tabortwci"
      }
      break;
    case 'v':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'm':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'h':	 // 1 string to match.
          if (memcmp(Name.data()+3, "addshs", 6))
            break;
          return MCK_vmhaddshs;	 // "vmhaddshs"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+3, "adduhm", 6))
            break;
          return MCK_vmladduhm;	 // "vmladduhm"
        }
        break;
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "sqrtefp", 7))
          break;
        return MCK_vrsqrtefp;	 // "vrsqrtefp"
      }
      break;
    case 'x':	 // 42 strings to match.
      switch (Name[1]) {
      default: break;
      case 's':	 // 16 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 7 strings to match.
          switch (Name[3]) {
          default: break;
          case 'p':	 // 1 string to match.
            if (memcmp(Name.data()+4, "sgndp", 5))
              break;
            return MCK_xscpsgndp;	 // "xscpsgndp"
          case 'v':	 // 6 strings to match.
            switch (Name[4]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (memcmp(Name.data()+5, "pspn", 4))
                break;
              return MCK_xscvdpspn;	 // "xscvdpspn"
            case 's':	 // 3 strings to match.
              switch (Name[5]) {
              default: break;
              case 'p':	 // 1 string to match.
                if (memcmp(Name.data()+6, "dpn", 3))
                  break;
                return MCK_xscvspdpn;	 // "xscvspdpn"
              case 'x':	 // 2 strings to match.
                if (Name[6] != 'd')
                  break;
                switch (Name[7]) {
                default: break;
                case 'd':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xscvsxddp;	 // "xscvsxddp"
                case 's':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xscvsxdsp;	 // "xscvsxdsp"
                }
                break;
              }
              break;
            case 'u':	 // 2 strings to match.
              if (memcmp(Name.data()+5, "xd", 2))
                break;
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xscvuxddp;	 // "xscvuxddp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xscvuxdsp;	 // "xscvuxdsp"
              }
              break;
            }
            break;
          }
          break;
        case 'm':	 // 8 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 4 strings to match.
            if (memcmp(Name.data()+4, "dd", 2))
              break;
            switch (Name[6]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xsmaddadp;	 // "xsmaddadp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xsmaddasp;	 // "xsmaddasp"
              }
              break;
            case 'm':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xsmaddmdp;	 // "xsmaddmdp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xsmaddmsp;	 // "xsmaddmsp"
              }
              break;
            }
            break;
          case 's':	 // 4 strings to match.
            if (memcmp(Name.data()+4, "ub", 2))
              break;
            switch (Name[6]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xsmsubadp;	 // "xsmsubadp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xsmsubasp;	 // "xsmsubasp"
              }
              break;
            case 'm':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xsmsubmdp;	 // "xsmsubmdp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xsmsubmsp;	 // "xsmsubmsp"
              }
              break;
            }
            break;
          }
          break;
        case 't':	 // 1 string to match.
          if (memcmp(Name.data()+3, "sqrtdp", 6))
            break;
          return MCK_xstsqrtdp;	 // "xstsqrtdp"
        }
        break;
      case 'v':	 // 26 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 16 strings to match.
          switch (Name[3]) {
          default: break;
          case 'm':	 // 6 strings to match.
            if (Name[4] != 'p')
              break;
            switch (Name[5]) {
            default: break;
            case 'e':	 // 2 strings to match.
              if (Name[6] != 'q')
                break;
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvcmpeqdp;	 // "xvcmpeqdp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvcmpeqsp;	 // "xvcmpeqsp"
              }
              break;
            case 'g':	 // 4 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'd':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcmpgedp;	 // "xvcmpgedp"
                case 's':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcmpgesp;	 // "xvcmpgesp"
                }
                break;
              case 't':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'd':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcmpgtdp;	 // "xvcmpgtdp"
                case 's':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcmpgtsp;	 // "xvcmpgtsp"
                }
                break;
              }
              break;
            }
            break;
          case 'p':	 // 2 strings to match.
            if (memcmp(Name.data()+4, "sgn", 3))
              break;
            switch (Name[7]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[8] != 'p')
                break;
              return MCK_xvcpsgndp;	 // "xvcpsgndp"
            case 's':	 // 1 string to match.
              if (Name[8] != 'p')
                break;
              return MCK_xvcpsgnsp;	 // "xvcpsgnsp"
            }
            break;
          case 'v':	 // 8 strings to match.
            switch (Name[4]) {
            default: break;
            case 's':	 // 4 strings to match.
              if (Name[5] != 'x')
                break;
              switch (Name[6]) {
              default: break;
              case 'd':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'd':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcvsxddp;	 // "xvcvsxddp"
                case 's':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcvsxdsp;	 // "xvcvsxdsp"
                }
                break;
              case 'w':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'd':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcvsxwdp;	 // "xvcvsxwdp"
                case 's':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcvsxwsp;	 // "xvcvsxwsp"
                }
                break;
              }
              break;
            case 'u':	 // 4 strings to match.
              if (Name[5] != 'x')
                break;
              switch (Name[6]) {
              default: break;
              case 'd':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'd':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcvuxddp;	 // "xvcvuxddp"
                case 's':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcvuxdsp;	 // "xvcvuxdsp"
                }
                break;
              case 'w':	 // 2 strings to match.
                switch (Name[7]) {
                default: break;
                case 'd':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcvuxwdp;	 // "xvcvuxwdp"
                case 's':	 // 1 string to match.
                  if (Name[8] != 'p')
                    break;
                  return MCK_xvcvuxwsp;	 // "xvcvuxwsp"
                }
                break;
              }
              break;
            }
            break;
          }
          break;
        case 'm':	 // 8 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 4 strings to match.
            if (memcmp(Name.data()+4, "dd", 2))
              break;
            switch (Name[6]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvmaddadp;	 // "xvmaddadp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvmaddasp;	 // "xvmaddasp"
              }
              break;
            case 'm':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvmaddmdp;	 // "xvmaddmdp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvmaddmsp;	 // "xvmaddmsp"
              }
              break;
            }
            break;
          case 's':	 // 4 strings to match.
            if (memcmp(Name.data()+4, "ub", 2))
              break;
            switch (Name[6]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvmsubadp;	 // "xvmsubadp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvmsubasp;	 // "xvmsubasp"
              }
              break;
            case 'm':	 // 2 strings to match.
              switch (Name[7]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvmsubmdp;	 // "xvmsubmdp"
              case 's':	 // 1 string to match.
                if (Name[8] != 'p')
                  break;
                return MCK_xvmsubmsp;	 // "xvmsubmsp"
              }
              break;
            }
            break;
          }
          break;
        case 't':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "sqrt", 4))
            break;
          switch (Name[7]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[8] != 'p')
              break;
            return MCK_xvtsqrtdp;	 // "xvtsqrtdp"
          case 's':	 // 1 string to match.
            if (Name[8] != 'p')
              break;
            return MCK_xvtsqrtsp;	 // "xvtsqrtsp"
          }
          break;
        }
        break;
      }
      break;
    }
    break;
  case 10:	 // 48 strings to match.
    switch (Name[0]) {
    default: break;
    case 'e':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "vlw", 3))
        break;
      switch (Name[4]) {
      default: break;
      case 'h':	 // 1 string to match.
        if (memcmp(Name.data()+5, "splat", 5))
          break;
        return MCK_evlwhsplat;	 // "evlwhsplat"
      case 'w':	 // 1 string to match.
        if (memcmp(Name.data()+5, "splat", 5))
          break;
        return MCK_evlwwsplat;	 // "evlwwsplat"
      }
      break;
    case 'q':	 // 11 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'f':	 // 3 strings to match.
        switch (Name[3]) {
        default: break;
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+4, "ogical", 6))
            break;
          return MCK_qvflogical;	 // "qvflogical"
        case 'r':	 // 1 string to match.
          if (memcmp(Name.data()+4, "sqrtes", 6))
            break;
          return MCK_qvfrsqrtes;	 // "qvfrsqrtes"
        case 'x':	 // 1 string to match.
          if (memcmp(Name.data()+4, "xmadds", 6))
            break;
          return MCK_qvfxxmadds;	 // "qvfxxmadds"
        }
        break;
      case 's':	 // 8 strings to match.
        if (memcmp(Name.data()+3, "tf", 2))
          break;
        switch (Name[5]) {
        default: break;
        case 'c':	 // 6 strings to match.
          switch (Name[6]) {
          default: break;
          case 'd':	 // 3 strings to match.
            switch (Name[7]) {
            default: break;
            case 'u':	 // 2 strings to match.
              if (Name[8] != 'x')
                break;
              switch (Name[9]) {
              default: break;
              case 'a':	 // 1 string to match.
                return MCK_qvstfcduxa;	 // "qvstfcduxa"
              case 'i':	 // 1 string to match.
                return MCK_qvstfcduxi;	 // "qvstfcduxi"
              }
              break;
            case 'x':	 // 1 string to match.
              if (memcmp(Name.data()+8, "ia", 2))
                break;
              return MCK_qvstfcdxia;	 // "qvstfcdxia"
            }
            break;
          case 's':	 // 3 strings to match.
            switch (Name[7]) {
            default: break;
            case 'u':	 // 2 strings to match.
              if (Name[8] != 'x')
                break;
              switch (Name[9]) {
              default: break;
              case 'a':	 // 1 string to match.
                return MCK_qvstfcsuxa;	 // "qvstfcsuxa"
              case 'i':	 // 1 string to match.
                return MCK_qvstfcsuxi;	 // "qvstfcsuxi"
              }
              break;
            case 'x':	 // 1 string to match.
              if (memcmp(Name.data()+8, "ia", 2))
                break;
              return MCK_qvstfcsxia;	 // "qvstfcsxia"
            }
            break;
          }
          break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+6, "uxia", 4))
            break;
          return MCK_qvstfduxia;	 // "qvstfduxia"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+6, "uxia", 4))
            break;
          return MCK_qvstfsuxia;	 // "qvstfsuxia"
        }
        break;
      }
      break;
    case 'v':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'm':	 // 1 string to match.
        if (memcmp(Name.data()+2, "hraddshs", 8))
          break;
        return MCK_vmhraddshs;	 // "vmhraddshs"
      case 's':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "hasigma", 7))
          break;
        switch (Name[9]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_vshasigmad;	 // "vshasigmad"
        case 'w':	 // 1 string to match.
          return MCK_vshasigmaw;	 // "vshasigmaw"
        }
        break;
      }
      break;
    case 'x':	 // 32 strings to match.
      switch (Name[1]) {
      default: break;
      case 's':	 // 14 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 4 strings to match.
          if (memcmp(Name.data()+3, "vdp", 3))
            break;
          switch (Name[6]) {
          default: break;
          case 's':	 // 2 strings to match.
            if (Name[7] != 'x')
              break;
            switch (Name[8]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[9] != 's')
                break;
              return MCK_xscvdpsxds;	 // "xscvdpsxds"
            case 'w':	 // 1 string to match.
              if (Name[9] != 's')
                break;
              return MCK_xscvdpsxws;	 // "xscvdpsxws"
            }
            break;
          case 'u':	 // 2 strings to match.
            if (Name[7] != 'x')
              break;
            switch (Name[8]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[9] != 's')
                break;
              return MCK_xscvdpuxds;	 // "xscvdpuxds"
            case 'w':	 // 1 string to match.
              if (Name[9] != 's')
                break;
              return MCK_xscvdpuxws;	 // "xscvdpuxws"
            }
            break;
          }
          break;
        case 'n':	 // 8 strings to match.
          if (Name[3] != 'm')
            break;
          switch (Name[4]) {
          default: break;
          case 'a':	 // 4 strings to match.
            if (memcmp(Name.data()+5, "dd", 2))
              break;
            switch (Name[7]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xsnmaddadp;	 // "xsnmaddadp"
              case 's':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xsnmaddasp;	 // "xsnmaddasp"
              }
              break;
            case 'm':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xsnmaddmdp;	 // "xsnmaddmdp"
              case 's':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xsnmaddmsp;	 // "xsnmaddmsp"
              }
              break;
            }
            break;
          case 's':	 // 4 strings to match.
            if (memcmp(Name.data()+5, "ub", 2))
              break;
            switch (Name[7]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xsnmsubadp;	 // "xsnmsubadp"
              case 's':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xsnmsubasp;	 // "xsnmsubasp"
              }
              break;
            case 'm':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xsnmsubmdp;	 // "xsnmsubmdp"
              case 's':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xsnmsubmsp;	 // "xsnmsubmsp"
              }
              break;
            }
            break;
          }
          break;
        case 'r':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "sqrte", 5))
            break;
          switch (Name[8]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[9] != 'p')
              break;
            return MCK_xsrsqrtedp;	 // "xsrsqrtedp"
          case 's':	 // 1 string to match.
            if (Name[9] != 'p')
              break;
            return MCK_xsrsqrtesp;	 // "xsrsqrtesp"
          }
          break;
        }
        break;
      case 'v':	 // 18 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 8 strings to match.
          if (Name[3] != 'v')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 4 strings to match.
            if (Name[5] != 'p')
              break;
            switch (Name[6]) {
            default: break;
            case 's':	 // 2 strings to match.
              if (Name[7] != 'x')
                break;
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 's')
                  break;
                return MCK_xvcvdpsxds;	 // "xvcvdpsxds"
              case 'w':	 // 1 string to match.
                if (Name[9] != 's')
                  break;
                return MCK_xvcvdpsxws;	 // "xvcvdpsxws"
              }
              break;
            case 'u':	 // 2 strings to match.
              if (Name[7] != 'x')
                break;
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 's')
                  break;
                return MCK_xvcvdpuxds;	 // "xvcvdpuxds"
              case 'w':	 // 1 string to match.
                if (Name[9] != 's')
                  break;
                return MCK_xvcvdpuxws;	 // "xvcvdpuxws"
              }
              break;
            }
            break;
          case 's':	 // 4 strings to match.
            if (Name[5] != 'p')
              break;
            switch (Name[6]) {
            default: break;
            case 's':	 // 2 strings to match.
              if (Name[7] != 'x')
                break;
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 's')
                  break;
                return MCK_xvcvspsxds;	 // "xvcvspsxds"
              case 'w':	 // 1 string to match.
                if (Name[9] != 's')
                  break;
                return MCK_xvcvspsxws;	 // "xvcvspsxws"
              }
              break;
            case 'u':	 // 2 strings to match.
              if (Name[7] != 'x')
                break;
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 's')
                  break;
                return MCK_xvcvspuxds;	 // "xvcvspuxds"
              case 'w':	 // 1 string to match.
                if (Name[9] != 's')
                  break;
                return MCK_xvcvspuxws;	 // "xvcvspuxws"
              }
              break;
            }
            break;
          }
          break;
        case 'n':	 // 8 strings to match.
          if (Name[3] != 'm')
            break;
          switch (Name[4]) {
          default: break;
          case 'a':	 // 4 strings to match.
            if (memcmp(Name.data()+5, "dd", 2))
              break;
            switch (Name[7]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xvnmaddadp;	 // "xvnmaddadp"
              case 's':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xvnmaddasp;	 // "xvnmaddasp"
              }
              break;
            case 'm':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xvnmaddmdp;	 // "xvnmaddmdp"
              case 's':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xvnmaddmsp;	 // "xvnmaddmsp"
              }
              break;
            }
            break;
          case 's':	 // 4 strings to match.
            if (memcmp(Name.data()+5, "ub", 2))
              break;
            switch (Name[7]) {
            default: break;
            case 'a':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xvnmsubadp;	 // "xvnmsubadp"
              case 's':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xvnmsubasp;	 // "xvnmsubasp"
              }
              break;
            case 'm':	 // 2 strings to match.
              switch (Name[8]) {
              default: break;
              case 'd':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xvnmsubmdp;	 // "xvnmsubmdp"
              case 's':	 // 1 string to match.
                if (Name[9] != 'p')
                  break;
                return MCK_xvnmsubmsp;	 // "xvnmsubmsp"
              }
              break;
            }
            break;
          }
          break;
        case 'r':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "sqrte", 5))
            break;
          switch (Name[8]) {
          default: break;
          case 'd':	 // 1 string to match.
            if (Name[9] != 'p')
              break;
            return MCK_xvrsqrtedp;	 // "xvrsqrtedp"
          case 's':	 // 1 string to match.
            if (Name[9] != 'p')
              break;
            return MCK_xvrsqrtesp;	 // "xvrsqrtesp"
          }
          break;
        }
        break;
      }
      break;
    }
    break;
  case 11:	 // 57 strings to match.
    switch (Name[0]) {
    default: break;
    case 'e':	 // 53 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'a':	 // 4 strings to match.
        if (memcmp(Name.data()+3, "dd", 2))
          break;
        switch (Name[5]) {
        default: break;
        case 's':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 'm':	 // 1 string to match.
            if (memcmp(Name.data()+7, "iaaw", 4))
              break;
            return MCK_evaddsmiaaw;	 // "evaddsmiaaw"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+7, "iaaw", 4))
              break;
            return MCK_evaddssiaaw;	 // "evaddssiaaw"
          }
          break;
        case 'u':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 'm':	 // 1 string to match.
            if (memcmp(Name.data()+7, "iaaw", 4))
              break;
            return MCK_evaddumiaaw;	 // "evaddumiaaw"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+7, "iaaw", 4))
              break;
            return MCK_evaddusiaaw;	 // "evaddusiaaw"
          }
          break;
        }
        break;
      case 'l':	 // 3 strings to match.
        switch (Name[3]) {
        default: break;
        case 'h':	 // 1 string to match.
          if (memcmp(Name.data()+4, "hesplat", 7))
            break;
          return MCK_evlhhesplat;	 // "evlhhesplat"
        case 'w':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'h':	 // 1 string to match.
            if (memcmp(Name.data()+5, "splatx", 6))
              break;
            return MCK_evlwhsplatx;	 // "evlwhsplatx"
          case 'w':	 // 1 string to match.
            if (memcmp(Name.data()+5, "splatx", 6))
              break;
            return MCK_evlwwsplatx;	 // "evlwwsplatx"
          }
          break;
        }
        break;
      case 'm':	 // 46 strings to match.
        switch (Name[3]) {
        default: break;
        case 'e':	 // 2 strings to match.
          if (memcmp(Name.data()+4, "rge", 3))
            break;
          switch (Name[7]) {
          default: break;
          case 'h':	 // 1 string to match.
            if (memcmp(Name.data()+8, "ilo", 3))
              break;
            return MCK_evmergehilo;	 // "evmergehilo"
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+8, "ohi", 3))
              break;
            return MCK_evmergelohi;	 // "evmergelohi"
          }
          break;
        case 'h':	 // 36 strings to match.
          switch (Name[4]) {
          default: break;
          case 'e':	 // 18 strings to match.
            switch (Name[5]) {
            default: break;
            case 'g':	 // 6 strings to match.
              switch (Name[6]) {
              default: break;
              case 's':	 // 4 strings to match.
                if (Name[7] != 'm')
                  break;
                switch (Name[8]) {
                default: break;
                case 'f':	 // 2 strings to match.
                  if (Name[9] != 'a')
                    break;
                  switch (Name[10]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    return MCK_evmhegsmfaa;	 // "evmhegsmfaa"
                  case 'n':	 // 1 string to match.
                    return MCK_evmhegsmfan;	 // "evmhegsmfan"
                  }
                  break;
                case 'i':	 // 2 strings to match.
                  if (Name[9] != 'a')
                    break;
                  switch (Name[10]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    return MCK_evmhegsmiaa;	 // "evmhegsmiaa"
                  case 'n':	 // 1 string to match.
                    return MCK_evmhegsmian;	 // "evmhegsmian"
                  }
                  break;
                }
                break;
              case 'u':	 // 2 strings to match.
                if (memcmp(Name.data()+7, "mia", 3))
                  break;
                switch (Name[10]) {
                default: break;
                case 'a':	 // 1 string to match.
                  return MCK_evmhegumiaa;	 // "evmhegumiaa"
                case 'n':	 // 1 string to match.
                  return MCK_evmhegumian;	 // "evmhegumian"
                }
                break;
              }
              break;
            case 's':	 // 8 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 4 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 2 strings to match.
                  if (Name[8] != 'a')
                    break;
                  switch (Name[9]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhesmfaaw;	 // "evmhesmfaaw"
                  case 'n':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhesmfanw;	 // "evmhesmfanw"
                  }
                  break;
                case 'i':	 // 2 strings to match.
                  if (Name[8] != 'a')
                    break;
                  switch (Name[9]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhesmiaaw;	 // "evmhesmiaaw"
                  case 'n':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhesmianw;	 // "evmhesmianw"
                  }
                  break;
                }
                break;
              case 's':	 // 4 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 2 strings to match.
                  if (Name[8] != 'a')
                    break;
                  switch (Name[9]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhessfaaw;	 // "evmhessfaaw"
                  case 'n':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhessfanw;	 // "evmhessfanw"
                  }
                  break;
                case 'i':	 // 2 strings to match.
                  if (Name[8] != 'a')
                    break;
                  switch (Name[9]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhessiaaw;	 // "evmhessiaaw"
                  case 'n':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhessianw;	 // "evmhessianw"
                  }
                  break;
                }
                break;
              }
              break;
            case 'u':	 // 4 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 2 strings to match.
                if (memcmp(Name.data()+7, "ia", 2))
                  break;
                switch (Name[9]) {
                default: break;
                case 'a':	 // 1 string to match.
                  if (Name[10] != 'w')
                    break;
                  return MCK_evmheumiaaw;	 // "evmheumiaaw"
                case 'n':	 // 1 string to match.
                  if (Name[10] != 'w')
                    break;
                  return MCK_evmheumianw;	 // "evmheumianw"
                }
                break;
              case 's':	 // 2 strings to match.
                if (memcmp(Name.data()+7, "ia", 2))
                  break;
                switch (Name[9]) {
                default: break;
                case 'a':	 // 1 string to match.
                  if (Name[10] != 'w')
                    break;
                  return MCK_evmheusiaaw;	 // "evmheusiaaw"
                case 'n':	 // 1 string to match.
                  if (Name[10] != 'w')
                    break;
                  return MCK_evmheusianw;	 // "evmheusianw"
                }
                break;
              }
              break;
            }
            break;
          case 'o':	 // 18 strings to match.
            switch (Name[5]) {
            default: break;
            case 'g':	 // 6 strings to match.
              switch (Name[6]) {
              default: break;
              case 's':	 // 4 strings to match.
                if (Name[7] != 'm')
                  break;
                switch (Name[8]) {
                default: break;
                case 'f':	 // 2 strings to match.
                  if (Name[9] != 'a')
                    break;
                  switch (Name[10]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    return MCK_evmhogsmfaa;	 // "evmhogsmfaa"
                  case 'n':	 // 1 string to match.
                    return MCK_evmhogsmfan;	 // "evmhogsmfan"
                  }
                  break;
                case 'i':	 // 2 strings to match.
                  if (Name[9] != 'a')
                    break;
                  switch (Name[10]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    return MCK_evmhogsmiaa;	 // "evmhogsmiaa"
                  case 'n':	 // 1 string to match.
                    return MCK_evmhogsmian;	 // "evmhogsmian"
                  }
                  break;
                }
                break;
              case 'u':	 // 2 strings to match.
                if (memcmp(Name.data()+7, "mia", 3))
                  break;
                switch (Name[10]) {
                default: break;
                case 'a':	 // 1 string to match.
                  return MCK_evmhogumiaa;	 // "evmhogumiaa"
                case 'n':	 // 1 string to match.
                  return MCK_evmhogumian;	 // "evmhogumian"
                }
                break;
              }
              break;
            case 's':	 // 8 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 4 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 2 strings to match.
                  if (Name[8] != 'a')
                    break;
                  switch (Name[9]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhosmfaaw;	 // "evmhosmfaaw"
                  case 'n':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhosmfanw;	 // "evmhosmfanw"
                  }
                  break;
                case 'i':	 // 2 strings to match.
                  if (Name[8] != 'a')
                    break;
                  switch (Name[9]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhosmiaaw;	 // "evmhosmiaaw"
                  case 'n':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhosmianw;	 // "evmhosmianw"
                  }
                  break;
                }
                break;
              case 's':	 // 4 strings to match.
                switch (Name[7]) {
                default: break;
                case 'f':	 // 2 strings to match.
                  if (Name[8] != 'a')
                    break;
                  switch (Name[9]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhossfaaw;	 // "evmhossfaaw"
                  case 'n':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhossfanw;	 // "evmhossfanw"
                  }
                  break;
                case 'i':	 // 2 strings to match.
                  if (Name[8] != 'a')
                    break;
                  switch (Name[9]) {
                  default: break;
                  case 'a':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhossiaaw;	 // "evmhossiaaw"
                  case 'n':	 // 1 string to match.
                    if (Name[10] != 'w')
                      break;
                    return MCK_evmhossianw;	 // "evmhossianw"
                  }
                  break;
                }
                break;
              }
              break;
            case 'u':	 // 4 strings to match.
              switch (Name[6]) {
              default: break;
              case 'm':	 // 2 strings to match.
                if (memcmp(Name.data()+7, "ia", 2))
                  break;
                switch (Name[9]) {
                default: break;
                case 'a':	 // 1 string to match.
                  if (Name[10] != 'w')
                    break;
                  return MCK_evmhoumiaaw;	 // "evmhoumiaaw"
                case 'n':	 // 1 string to match.
                  if (Name[10] != 'w')
                    break;
                  return MCK_evmhoumianw;	 // "evmhoumianw"
                }
                break;
              case 's':	 // 2 strings to match.
                if (memcmp(Name.data()+7, "ia", 2))
                  break;
                switch (Name[9]) {
                default: break;
                case 'a':	 // 1 string to match.
                  if (Name[10] != 'w')
                    break;
                  return MCK_evmhousiaaw;	 // "evmhousiaaw"
                case 'n':	 // 1 string to match.
                  if (Name[10] != 'w')
                    break;
                  return MCK_evmhousianw;	 // "evmhousianw"
                }
                break;
              }
              break;
            }
            break;
          }
          break;
        case 'w':	 // 8 strings to match.
          if (Name[4] != 'l')
            break;
          switch (Name[5]) {
          default: break;
          case 's':	 // 4 strings to match.
            switch (Name[6]) {
            default: break;
            case 'm':	 // 2 strings to match.
              if (memcmp(Name.data()+7, "ia", 2))
                break;
              switch (Name[9]) {
              default: break;
              case 'a':	 // 1 string to match.
                if (Name[10] != 'w')
                  break;
                return MCK_evmwlsmiaaw;	 // "evmwlsmiaaw"
              case 'n':	 // 1 string to match.
                if (Name[10] != 'w')
                  break;
                return MCK_evmwlsmianw;	 // "evmwlsmianw"
              }
              break;
            case 's':	 // 2 strings to match.
              if (memcmp(Name.data()+7, "ia", 2))
                break;
              switch (Name[9]) {
              default: break;
              case 'a':	 // 1 string to match.
                if (Name[10] != 'w')
                  break;
                return MCK_evmwlssiaaw;	 // "evmwlssiaaw"
              case 'n':	 // 1 string to match.
                if (Name[10] != 'w')
                  break;
                return MCK_evmwlssianw;	 // "evmwlssianw"
              }
              break;
            }
            break;
          case 'u':	 // 4 strings to match.
            switch (Name[6]) {
            default: break;
            case 'm':	 // 2 strings to match.
              if (memcmp(Name.data()+7, "ia", 2))
                break;
              switch (Name[9]) {
              default: break;
              case 'a':	 // 1 string to match.
                if (Name[10] != 'w')
                  break;
                return MCK_evmwlumiaaw;	 // "evmwlumiaaw"
              case 'n':	 // 1 string to match.
                if (Name[10] != 'w')
                  break;
                return MCK_evmwlumianw;	 // "evmwlumianw"
              }
              break;
            case 's':	 // 2 strings to match.
              if (memcmp(Name.data()+7, "ia", 2))
                break;
              switch (Name[9]) {
              default: break;
              case 'a':	 // 1 string to match.
                if (Name[10] != 'w')
                  break;
                return MCK_evmwlusiaaw;	 // "evmwlusiaaw"
              case 'n':	 // 1 string to match.
                if (Name[10] != 'w')
                  break;
                return MCK_evmwlusianw;	 // "evmwlusianw"
              }
              break;
            }
            break;
          }
          break;
        }
        break;
      }
      break;
    case 'q':	 // 3 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'f':	 // 1 string to match.
        if (memcmp(Name.data()+3, "xxnpmadd", 8))
          break;
        return MCK_qvfxxnpmadd;	 // "qvfxxnpmadd"
      case 's':	 // 2 strings to match.
        if (memcmp(Name.data()+3, "tfc", 3))
          break;
        switch (Name[6]) {
        default: break;
        case 'd':	 // 1 string to match.
          if (memcmp(Name.data()+7, "uxia", 4))
            break;
          return MCK_qvstfcduxia;	 // "qvstfcduxia"
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+7, "uxia", 4))
            break;
          return MCK_qvstfcsuxia;	 // "qvstfcsuxia"
        }
        break;
      }
      break;
    case 'v':	 // 1 string to match.
      if (memcmp(Name.data()+1, "cipherlast", 10))
        break;
      return MCK_vcipherlast;	 // "vcipherlast"
    }
    break;
  case 12:	 // 10 strings to match.
    switch (Name[0]) {
    default: break;
    case 'e':	 // 7 strings to match.
      if (Name[1] != 'v')
        break;
      switch (Name[2]) {
      default: break;
      case 'l':	 // 3 strings to match.
        if (memcmp(Name.data()+3, "hh", 2))
          break;
        switch (Name[5]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+6, "splatx", 6))
            break;
          return MCK_evlhhesplatx;	 // "evlhhesplatx"
        case 'o':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+7, "splat", 5))
              break;
            return MCK_evlhhossplat;	 // "evlhhossplat"
          case 'u':	 // 1 string to match.
            if (memcmp(Name.data()+7, "splat", 5))
              break;
            return MCK_evlhhousplat;	 // "evlhhousplat"
          }
          break;
        }
        break;
      case 's':	 // 4 strings to match.
        if (memcmp(Name.data()+3, "ubf", 3))
          break;
        switch (Name[6]) {
        default: break;
        case 's':	 // 2 strings to match.
          switch (Name[7]) {
          default: break;
          case 'm':	 // 1 string to match.
            if (memcmp(Name.data()+8, "iaaw", 4))
              break;
            return MCK_evsubfsmiaaw;	 // "evsubfsmiaaw"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+8, "iaaw", 4))
              break;
            return MCK_evsubfssiaaw;	 // "evsubfssiaaw"
          }
          break;
        case 'u':	 // 2 strings to match.
          switch (Name[7]) {
          default: break;
          case 'm':	 // 1 string to match.
            if (memcmp(Name.data()+8, "iaaw", 4))
              break;
            return MCK_evsubfumiaaw;	 // "evsubfumiaaw"
          case 's':	 // 1 string to match.
            if (memcmp(Name.data()+8, "iaaw", 4))
              break;
            return MCK_evsubfusiaaw;	 // "evsubfusiaaw"
          }
          break;
        }
        break;
      }
      break;
    case 'q':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "vfxx", 4))
        break;
      switch (Name[5]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+6, "pnmadd", 6))
          break;
        return MCK_qvfxxcpnmadd;	 // "qvfxxcpnmadd"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+6, "pmadds", 6))
          break;
        return MCK_qvfxxnpmadds;	 // "qvfxxnpmadds"
      }
      break;
    case 'v':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ncipherlast", 11))
        break;
      return MCK_vncipherlast;	 // "vncipherlast"
    }
    break;
  case 13:	 // 3 strings to match.
    switch (Name[0]) {
    default: break;
    case 'e':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "vlhho", 5))
        break;
      switch (Name[6]) {
      default: break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+7, "splatx", 6))
          break;
        return MCK_evlhhossplatx;	 // "evlhhossplatx"
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+7, "splatx", 6))
          break;
        return MCK_evlhhousplatx;	 // "evlhhousplatx"
      }
      break;
    case 'q':	 // 1 string to match.
      if (memcmp(Name.data()+1, "vfxxcpnmadds", 12))
        break;
      return MCK_qvfxxcpnmadds;	 // "qvfxxcpnmadds"
    }
    break;
  }
  return InvalidMatchClass;
}

/// isSubclass - Compute whether \p A is a subclass of \p B.
static bool isSubclass(MatchClassKind A, MatchClassKind B) {
  if (A == B)
    return true;

  switch (A) {
  default:
    return false;

  case MCK_Reg2:
    switch (B) {
    default: return false;
    case MCK_GPRC: return true;
    case MCK_GPRC_NOR0: return true;
    }

  case MCK_Reg5:
    switch (B) {
    default: return false;
    case MCK_G8RC: return true;
    case MCK_G8RC_NOX0: return true;
    }

  case MCK_F4RC:
    return B == MCK_VSSRC;

  case MCK_VFRC:
    return B == MCK_VSSRC;

  case MCK_VSLRC:
    return B == MCK_VSRC;

  case MCK_VSHRC:
    return B == MCK_VSRC;

  case MCK_CRRC0:
    return B == MCK_CRRC;
  }
}

static unsigned validateOperandClass(MCParsedAsmOperand &GOp, MatchClassKind Kind) {
  PPCOperand &Operand = (PPCOperand&)GOp;
  if (Kind == InvalidMatchClass)
    return MCTargetAsmParser::Match_InvalidOperand;

  if (Operand.isToken())
    return isSubclass(matchTokenString(Operand.getToken()), Kind) ?
             MCTargetAsmParser::Match_Success :
             MCTargetAsmParser::Match_InvalidOperand;

  // 'Imm' class
  if (Kind == MCK_Imm) {
    if (Operand.isImm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CRBitMask' class
  if (Kind == MCK_CRBitMask) {
    if (Operand.isCRBitMask())
      return MCTargetAsmParser::Match_Success;
  }

  // 'CondBr' class
  if (Kind == MCK_CondBr) {
    if (Operand.isCondBr())
      return MCTargetAsmParser::Match_Success;
  }

  // 'DirectBr' class
  if (Kind == MCK_DirectBr) {
    if (Operand.isDirectBr())
      return MCTargetAsmParser::Match_Success;
  }

  // 'DispRI' class
  if (Kind == MCK_DispRI) {
    if (Operand.isS16Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'DispRIX' class
  if (Kind == MCK_DispRIX) {
    if (Operand.isS16ImmX4())
      return MCTargetAsmParser::Match_Success;
  }

  // 'DispSPE2' class
  if (Kind == MCK_DispSPE2) {
    if (Operand.isU6ImmX2())
      return MCTargetAsmParser::Match_Success;
  }

  // 'DispSPE4' class
  if (Kind == MCK_DispSPE4) {
    if (Operand.isU7ImmX4())
      return MCTargetAsmParser::Match_Success;
  }

  // 'DispSPE8' class
  if (Kind == MCK_DispSPE8) {
    if (Operand.isU8ImmX8())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegCRBITRC' class
  if (Kind == MCK_RegCRBITRC) {
    if (Operand.isCRBitNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegCRRC' class
  if (Kind == MCK_RegCRRC) {
    if (Operand.isCCRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegF4RC' class
  if (Kind == MCK_RegF4RC) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegF8RC' class
  if (Kind == MCK_RegF8RC) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegG8RC' class
  if (Kind == MCK_RegG8RC) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegG8RCNoX0' class
  if (Kind == MCK_RegG8RCNoX0) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegGPRC' class
  if (Kind == MCK_RegGPRC) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegGPRCNoR0' class
  if (Kind == MCK_RegGPRCNoR0) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegGxRCNoR0' class
  if (Kind == MCK_RegGxRCNoR0) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegGxRC' class
  if (Kind == MCK_RegGxRC) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegQBRC' class
  if (Kind == MCK_RegQBRC) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegQFRC' class
  if (Kind == MCK_RegQFRC) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegQSRC' class
  if (Kind == MCK_RegQSRC) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegVRRC' class
  if (Kind == MCK_RegVRRC) {
    if (Operand.isRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegVSFRC' class
  if (Kind == MCK_RegVSFRC) {
    if (Operand.isVSRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegVSRC' class
  if (Kind == MCK_RegVSRC) {
    if (Operand.isVSRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'RegVSSRC' class
  if (Kind == MCK_RegVSSRC) {
    if (Operand.isVSRegNumber())
      return MCTargetAsmParser::Match_Success;
  }

  // 'S16Imm' class
  if (Kind == MCK_S16Imm) {
    if (Operand.isS16Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'S17Imm' class
  if (Kind == MCK_S17Imm) {
    if (Operand.isS17Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'S5Imm' class
  if (Kind == MCK_S5Imm) {
    if (Operand.isS5Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'TLSReg' class
  if (Kind == MCK_TLSReg) {
    if (Operand.isTLSReg())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U10Imm' class
  if (Kind == MCK_U10Imm) {
    if (Operand.isU10Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U12Imm' class
  if (Kind == MCK_U12Imm) {
    if (Operand.isU12Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U16Imm' class
  if (Kind == MCK_U16Imm) {
    if (Operand.isU16Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U1Imm' class
  if (Kind == MCK_U1Imm) {
    if (Operand.isU1Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U2Imm' class
  if (Kind == MCK_U2Imm) {
    if (Operand.isU2Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U3Imm' class
  if (Kind == MCK_U3Imm) {
    if (Operand.isU3Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U4Imm' class
  if (Kind == MCK_U4Imm) {
    if (Operand.isU4Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U5Imm' class
  if (Kind == MCK_U5Imm) {
    if (Operand.isU5Imm())
      return MCTargetAsmParser::Match_Success;
  }

  // 'U6Imm' class
  if (Kind == MCK_U6Imm) {
    if (Operand.isU6Imm())
      return MCTargetAsmParser::Match_Success;
  }

  if (Operand.isReg()) {
    MatchClassKind OpKind;
    switch (Operand.getReg()) {
    default: OpKind = InvalidMatchClass; break;
    case PPC::R0: OpKind = MCK_GPRC; break;
    case PPC::R1: OpKind = MCK_Reg2; break;
    case PPC::R2: OpKind = MCK_Reg2; break;
    case PPC::R3: OpKind = MCK_Reg2; break;
    case PPC::R4: OpKind = MCK_Reg2; break;
    case PPC::R5: OpKind = MCK_Reg2; break;
    case PPC::R6: OpKind = MCK_Reg2; break;
    case PPC::R7: OpKind = MCK_Reg2; break;
    case PPC::R8: OpKind = MCK_Reg2; break;
    case PPC::R9: OpKind = MCK_Reg2; break;
    case PPC::R10: OpKind = MCK_Reg2; break;
    case PPC::R11: OpKind = MCK_Reg2; break;
    case PPC::R12: OpKind = MCK_Reg2; break;
    case PPC::R13: OpKind = MCK_Reg2; break;
    case PPC::R14: OpKind = MCK_Reg2; break;
    case PPC::R15: OpKind = MCK_Reg2; break;
    case PPC::R16: OpKind = MCK_Reg2; break;
    case PPC::R17: OpKind = MCK_Reg2; break;
    case PPC::R18: OpKind = MCK_Reg2; break;
    case PPC::R19: OpKind = MCK_Reg2; break;
    case PPC::R20: OpKind = MCK_Reg2; break;
    case PPC::R21: OpKind = MCK_Reg2; break;
    case PPC::R22: OpKind = MCK_Reg2; break;
    case PPC::R23: OpKind = MCK_Reg2; break;
    case PPC::R24: OpKind = MCK_Reg2; break;
    case PPC::R25: OpKind = MCK_Reg2; break;
    case PPC::R26: OpKind = MCK_Reg2; break;
    case PPC::R27: OpKind = MCK_Reg2; break;
    case PPC::R28: OpKind = MCK_Reg2; break;
    case PPC::R29: OpKind = MCK_Reg2; break;
    case PPC::R30: OpKind = MCK_Reg2; break;
    case PPC::R31: OpKind = MCK_Reg2; break;
    case PPC::X0: OpKind = MCK_G8RC; break;
    case PPC::X1: OpKind = MCK_Reg5; break;
    case PPC::X2: OpKind = MCK_Reg5; break;
    case PPC::X3: OpKind = MCK_Reg5; break;
    case PPC::X4: OpKind = MCK_Reg5; break;
    case PPC::X5: OpKind = MCK_Reg5; break;
    case PPC::X6: OpKind = MCK_Reg5; break;
    case PPC::X7: OpKind = MCK_Reg5; break;
    case PPC::X8: OpKind = MCK_Reg5; break;
    case PPC::X9: OpKind = MCK_Reg5; break;
    case PPC::X10: OpKind = MCK_Reg5; break;
    case PPC::X11: OpKind = MCK_Reg5; break;
    case PPC::X12: OpKind = MCK_Reg5; break;
    case PPC::X13: OpKind = MCK_Reg5; break;
    case PPC::X14: OpKind = MCK_Reg5; break;
    case PPC::X15: OpKind = MCK_Reg5; break;
    case PPC::X16: OpKind = MCK_Reg5; break;
    case PPC::X17: OpKind = MCK_Reg5; break;
    case PPC::X18: OpKind = MCK_Reg5; break;
    case PPC::X19: OpKind = MCK_Reg5; break;
    case PPC::X20: OpKind = MCK_Reg5; break;
    case PPC::X21: OpKind = MCK_Reg5; break;
    case PPC::X22: OpKind = MCK_Reg5; break;
    case PPC::X23: OpKind = MCK_Reg5; break;
    case PPC::X24: OpKind = MCK_Reg5; break;
    case PPC::X25: OpKind = MCK_Reg5; break;
    case PPC::X26: OpKind = MCK_Reg5; break;
    case PPC::X27: OpKind = MCK_Reg5; break;
    case PPC::X28: OpKind = MCK_Reg5; break;
    case PPC::X29: OpKind = MCK_Reg5; break;
    case PPC::X30: OpKind = MCK_Reg5; break;
    case PPC::X31: OpKind = MCK_Reg5; break;
    case PPC::F0: OpKind = MCK_F4RC; break;
    case PPC::F1: OpKind = MCK_F4RC; break;
    case PPC::F2: OpKind = MCK_F4RC; break;
    case PPC::F3: OpKind = MCK_F4RC; break;
    case PPC::F4: OpKind = MCK_F4RC; break;
    case PPC::F5: OpKind = MCK_F4RC; break;
    case PPC::F6: OpKind = MCK_F4RC; break;
    case PPC::F7: OpKind = MCK_F4RC; break;
    case PPC::F8: OpKind = MCK_F4RC; break;
    case PPC::F9: OpKind = MCK_F4RC; break;
    case PPC::F10: OpKind = MCK_F4RC; break;
    case PPC::F11: OpKind = MCK_F4RC; break;
    case PPC::F12: OpKind = MCK_F4RC; break;
    case PPC::F13: OpKind = MCK_F4RC; break;
    case PPC::F14: OpKind = MCK_F4RC; break;
    case PPC::F15: OpKind = MCK_F4RC; break;
    case PPC::F16: OpKind = MCK_F4RC; break;
    case PPC::F17: OpKind = MCK_F4RC; break;
    case PPC::F18: OpKind = MCK_F4RC; break;
    case PPC::F19: OpKind = MCK_F4RC; break;
    case PPC::F20: OpKind = MCK_F4RC; break;
    case PPC::F21: OpKind = MCK_F4RC; break;
    case PPC::F22: OpKind = MCK_F4RC; break;
    case PPC::F23: OpKind = MCK_F4RC; break;
    case PPC::F24: OpKind = MCK_F4RC; break;
    case PPC::F25: OpKind = MCK_F4RC; break;
    case PPC::F26: OpKind = MCK_F4RC; break;
    case PPC::F27: OpKind = MCK_F4RC; break;
    case PPC::F28: OpKind = MCK_F4RC; break;
    case PPC::F29: OpKind = MCK_F4RC; break;
    case PPC::F30: OpKind = MCK_F4RC; break;
    case PPC::F31: OpKind = MCK_F4RC; break;
    case PPC::VF0: OpKind = MCK_VFRC; break;
    case PPC::VF1: OpKind = MCK_VFRC; break;
    case PPC::VF2: OpKind = MCK_VFRC; break;
    case PPC::VF3: OpKind = MCK_VFRC; break;
    case PPC::VF4: OpKind = MCK_VFRC; break;
    case PPC::VF5: OpKind = MCK_VFRC; break;
    case PPC::VF6: OpKind = MCK_VFRC; break;
    case PPC::VF7: OpKind = MCK_VFRC; break;
    case PPC::VF8: OpKind = MCK_VFRC; break;
    case PPC::VF9: OpKind = MCK_VFRC; break;
    case PPC::VF10: OpKind = MCK_VFRC; break;
    case PPC::VF11: OpKind = MCK_VFRC; break;
    case PPC::VF12: OpKind = MCK_VFRC; break;
    case PPC::VF13: OpKind = MCK_VFRC; break;
    case PPC::VF14: OpKind = MCK_VFRC; break;
    case PPC::VF15: OpKind = MCK_VFRC; break;
    case PPC::VF16: OpKind = MCK_VFRC; break;
    case PPC::VF17: OpKind = MCK_VFRC; break;
    case PPC::VF18: OpKind = MCK_VFRC; break;
    case PPC::VF19: OpKind = MCK_VFRC; break;
    case PPC::VF20: OpKind = MCK_VFRC; break;
    case PPC::VF21: OpKind = MCK_VFRC; break;
    case PPC::VF22: OpKind = MCK_VFRC; break;
    case PPC::VF23: OpKind = MCK_VFRC; break;
    case PPC::VF24: OpKind = MCK_VFRC; break;
    case PPC::VF25: OpKind = MCK_VFRC; break;
    case PPC::VF26: OpKind = MCK_VFRC; break;
    case PPC::VF27: OpKind = MCK_VFRC; break;
    case PPC::VF28: OpKind = MCK_VFRC; break;
    case PPC::VF29: OpKind = MCK_VFRC; break;
    case PPC::VF30: OpKind = MCK_VFRC; break;
    case PPC::VF31: OpKind = MCK_VFRC; break;
    case PPC::QF0: OpKind = MCK_QSRC; break;
    case PPC::QF1: OpKind = MCK_QSRC; break;
    case PPC::QF2: OpKind = MCK_QSRC; break;
    case PPC::QF3: OpKind = MCK_QSRC; break;
    case PPC::QF4: OpKind = MCK_QSRC; break;
    case PPC::QF5: OpKind = MCK_QSRC; break;
    case PPC::QF6: OpKind = MCK_QSRC; break;
    case PPC::QF7: OpKind = MCK_QSRC; break;
    case PPC::QF8: OpKind = MCK_QSRC; break;
    case PPC::QF9: OpKind = MCK_QSRC; break;
    case PPC::QF10: OpKind = MCK_QSRC; break;
    case PPC::QF11: OpKind = MCK_QSRC; break;
    case PPC::QF12: OpKind = MCK_QSRC; break;
    case PPC::QF13: OpKind = MCK_QSRC; break;
    case PPC::QF14: OpKind = MCK_QSRC; break;
    case PPC::QF15: OpKind = MCK_QSRC; break;
    case PPC::QF16: OpKind = MCK_QSRC; break;
    case PPC::QF17: OpKind = MCK_QSRC; break;
    case PPC::QF18: OpKind = MCK_QSRC; break;
    case PPC::QF19: OpKind = MCK_QSRC; break;
    case PPC::QF20: OpKind = MCK_QSRC; break;
    case PPC::QF21: OpKind = MCK_QSRC; break;
    case PPC::QF22: OpKind = MCK_QSRC; break;
    case PPC::QF23: OpKind = MCK_QSRC; break;
    case PPC::QF24: OpKind = MCK_QSRC; break;
    case PPC::QF25: OpKind = MCK_QSRC; break;
    case PPC::QF26: OpKind = MCK_QSRC; break;
    case PPC::QF27: OpKind = MCK_QSRC; break;
    case PPC::QF28: OpKind = MCK_QSRC; break;
    case PPC::QF29: OpKind = MCK_QSRC; break;
    case PPC::QF30: OpKind = MCK_QSRC; break;
    case PPC::QF31: OpKind = MCK_QSRC; break;
    case PPC::V0: OpKind = MCK_VRRC; break;
    case PPC::V1: OpKind = MCK_VRRC; break;
    case PPC::V2: OpKind = MCK_VRRC; break;
    case PPC::V3: OpKind = MCK_VRRC; break;
    case PPC::V4: OpKind = MCK_VRRC; break;
    case PPC::V5: OpKind = MCK_VRRC; break;
    case PPC::V6: OpKind = MCK_VRRC; break;
    case PPC::V7: OpKind = MCK_VRRC; break;
    case PPC::V8: OpKind = MCK_VRRC; break;
    case PPC::V9: OpKind = MCK_VRRC; break;
    case PPC::V10: OpKind = MCK_VRRC; break;
    case PPC::V11: OpKind = MCK_VRRC; break;
    case PPC::V12: OpKind = MCK_VRRC; break;
    case PPC::V13: OpKind = MCK_VRRC; break;
    case PPC::V14: OpKind = MCK_VRRC; break;
    case PPC::V15: OpKind = MCK_VRRC; break;
    case PPC::V16: OpKind = MCK_VRRC; break;
    case PPC::V17: OpKind = MCK_VRRC; break;
    case PPC::V18: OpKind = MCK_VRRC; break;
    case PPC::V19: OpKind = MCK_VRRC; break;
    case PPC::V20: OpKind = MCK_VRRC; break;
    case PPC::V21: OpKind = MCK_VRRC; break;
    case PPC::V22: OpKind = MCK_VRRC; break;
    case PPC::V23: OpKind = MCK_VRRC; break;
    case PPC::V24: OpKind = MCK_VRRC; break;
    case PPC::V25: OpKind = MCK_VRRC; break;
    case PPC::V26: OpKind = MCK_VRRC; break;
    case PPC::V27: OpKind = MCK_VRRC; break;
    case PPC::V28: OpKind = MCK_VRRC; break;
    case PPC::V29: OpKind = MCK_VRRC; break;
    case PPC::V30: OpKind = MCK_VRRC; break;
    case PPC::V31: OpKind = MCK_VRRC; break;
    case PPC::VSL0: OpKind = MCK_VSLRC; break;
    case PPC::VSL1: OpKind = MCK_VSLRC; break;
    case PPC::VSL2: OpKind = MCK_VSLRC; break;
    case PPC::VSL3: OpKind = MCK_VSLRC; break;
    case PPC::VSL4: OpKind = MCK_VSLRC; break;
    case PPC::VSL5: OpKind = MCK_VSLRC; break;
    case PPC::VSL6: OpKind = MCK_VSLRC; break;
    case PPC::VSL7: OpKind = MCK_VSLRC; break;
    case PPC::VSL8: OpKind = MCK_VSLRC; break;
    case PPC::VSL9: OpKind = MCK_VSLRC; break;
    case PPC::VSL10: OpKind = MCK_VSLRC; break;
    case PPC::VSL11: OpKind = MCK_VSLRC; break;
    case PPC::VSL12: OpKind = MCK_VSLRC; break;
    case PPC::VSL13: OpKind = MCK_VSLRC; break;
    case PPC::VSL14: OpKind = MCK_VSLRC; break;
    case PPC::VSL15: OpKind = MCK_VSLRC; break;
    case PPC::VSL16: OpKind = MCK_VSLRC; break;
    case PPC::VSL17: OpKind = MCK_VSLRC; break;
    case PPC::VSL18: OpKind = MCK_VSLRC; break;
    case PPC::VSL19: OpKind = MCK_VSLRC; break;
    case PPC::VSL20: OpKind = MCK_VSLRC; break;
    case PPC::VSL21: OpKind = MCK_VSLRC; break;
    case PPC::VSL22: OpKind = MCK_VSLRC; break;
    case PPC::VSL23: OpKind = MCK_VSLRC; break;
    case PPC::VSL24: OpKind = MCK_VSLRC; break;
    case PPC::VSL25: OpKind = MCK_VSLRC; break;
    case PPC::VSL26: OpKind = MCK_VSLRC; break;
    case PPC::VSL27: OpKind = MCK_VSLRC; break;
    case PPC::VSL28: OpKind = MCK_VSLRC; break;
    case PPC::VSL29: OpKind = MCK_VSLRC; break;
    case PPC::VSL30: OpKind = MCK_VSLRC; break;
    case PPC::VSL31: OpKind = MCK_VSLRC; break;
    case PPC::VSH0: OpKind = MCK_VSHRC; break;
    case PPC::VSH1: OpKind = MCK_VSHRC; break;
    case PPC::VSH2: OpKind = MCK_VSHRC; break;
    case PPC::VSH3: OpKind = MCK_VSHRC; break;
    case PPC::VSH4: OpKind = MCK_VSHRC; break;
    case PPC::VSH5: OpKind = MCK_VSHRC; break;
    case PPC::VSH6: OpKind = MCK_VSHRC; break;
    case PPC::VSH7: OpKind = MCK_VSHRC; break;
    case PPC::VSH8: OpKind = MCK_VSHRC; break;
    case PPC::VSH9: OpKind = MCK_VSHRC; break;
    case PPC::VSH10: OpKind = MCK_VSHRC; break;
    case PPC::VSH11: OpKind = MCK_VSHRC; break;
    case PPC::VSH12: OpKind = MCK_VSHRC; break;
    case PPC::VSH13: OpKind = MCK_VSHRC; break;
    case PPC::VSH14: OpKind = MCK_VSHRC; break;
    case PPC::VSH15: OpKind = MCK_VSHRC; break;
    case PPC::VSH16: OpKind = MCK_VSHRC; break;
    case PPC::VSH17: OpKind = MCK_VSHRC; break;
    case PPC::VSH18: OpKind = MCK_VSHRC; break;
    case PPC::VSH19: OpKind = MCK_VSHRC; break;
    case PPC::VSH20: OpKind = MCK_VSHRC; break;
    case PPC::VSH21: OpKind = MCK_VSHRC; break;
    case PPC::VSH22: OpKind = MCK_VSHRC; break;
    case PPC::VSH23: OpKind = MCK_VSHRC; break;
    case PPC::VSH24: OpKind = MCK_VSHRC; break;
    case PPC::VSH25: OpKind = MCK_VSHRC; break;
    case PPC::VSH26: OpKind = MCK_VSHRC; break;
    case PPC::VSH27: OpKind = MCK_VSHRC; break;
    case PPC::VSH28: OpKind = MCK_VSHRC; break;
    case PPC::VSH29: OpKind = MCK_VSHRC; break;
    case PPC::VSH30: OpKind = MCK_VSHRC; break;
    case PPC::VSH31: OpKind = MCK_VSHRC; break;
    case PPC::ZERO: OpKind = MCK_GPRC_NOR0; break;
    case PPC::ZERO8: OpKind = MCK_G8RC_NOX0; break;
    case PPC::FP: OpKind = MCK_Reg2; break;
    case PPC::FP8: OpKind = MCK_Reg5; break;
    case PPC::BP: OpKind = MCK_Reg2; break;
    case PPC::BP8: OpKind = MCK_Reg5; break;
    case PPC::CR0LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR0GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR0EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR0UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR1LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR1GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR1EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR1UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR2LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR2GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR2EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR2UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR3LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR3GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR3EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR3UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR4LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR4GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR4EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR4UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR5LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR5GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR5EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR5UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR6LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR6GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR6EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR6UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR7LT: OpKind = MCK_CRBITRC; break;
    case PPC::CR7GT: OpKind = MCK_CRBITRC; break;
    case PPC::CR7EQ: OpKind = MCK_CRBITRC; break;
    case PPC::CR7UN: OpKind = MCK_CRBITRC; break;
    case PPC::CR0: OpKind = MCK_CRRC0; break;
    case PPC::CR1: OpKind = MCK_CRRC; break;
    case PPC::CR2: OpKind = MCK_CRRC; break;
    case PPC::CR3: OpKind = MCK_CRRC; break;
    case PPC::CR4: OpKind = MCK_CRRC; break;
    case PPC::CR5: OpKind = MCK_CRRC; break;
    case PPC::CR6: OpKind = MCK_CRRC; break;
    case PPC::CR7: OpKind = MCK_CRRC; break;
    case PPC::CTR: OpKind = MCK_CTRRC; break;
    case PPC::CTR8: OpKind = MCK_CTRRC8; break;
    case PPC::VRSAVE: OpKind = MCK_VRSAVERC; break;
    case PPC::CARRY: OpKind = MCK_CARRYRC; break;
    }
    return isSubclass(OpKind, Kind) ? MCTargetAsmParser::Match_Success :
                                      MCTargetAsmParser::Match_InvalidOperand;
  }

  return MCTargetAsmParser::Match_InvalidOperand;
}

uint64_t PPCAsmParser::
ComputeAvailableFeatures(const FeatureBitset& FB) const {
  uint64_t Features = 0;
  return Features;
}

static const char *const MnemonicTable =
    "\003add\004addc\004adde\004addi\005addic\005addis\005addme\005addze\003"
    "and\004andc\004andi\005andis\004attn\001b\002ba\002bc\003bca\005bcctr\006"
    "bcctrl\003bcl\004bcla\004bclr\005bclrl\004bctr\005bctrl\004bdnz\005bdnz"
    "+\005bdnz-\005bdnza\006bdnza+\006bdnza-\005bdnzf\006bdnzfa\006bdnzfl\007"
    "bdnzfla\007bdnzflr\010bdnzflrl\005bdnzl\006bdnzl+\006bdnzl-\006bdnzla\007"
    "bdnzla+\007bdnzla-\006bdnzlr\007bdnzlr+\007bdnzlr-\007bdnzlrl\010bdnzlr"
    "l+\010bdnzlrl-\005bdnzt\006bdnzta\006bdnztl\007bdnztla\007bdnztlr\010bd"
    "nztlrl\003bdz\004bdz+\004bdz-\004bdza\005bdza+\005bdza-\004bdzf\005bdzf"
    "a\005bdzfl\006bdzfla\006bdzflr\007bdzflrl\004bdzl\005bdzl+\005bdzl-\005"
    "bdzla\006bdzla+\006bdzla-\005bdzlr\006bdzlr+\006bdzlr-\006bdzlrl\007bdz"
    "lrl+\007bdzlrl-\004bdzt\005bdzta\005bdztl\006bdztla\006bdztlr\007bdztlr"
    "l\003beq\004beq+\004beq-\004beqa\005beqa+\005beqa-\006beqctr\007beqctr+"
    "\007beqctr-\007beqctrl\010beqctrl+\010beqctrl-\004beql\005beql+\005beql"
    "-\005beqla\006beqla+\006beqla-\005beqlr\006beqlr+\006beqlr-\006beqlrl\007"
    "beqlrl+\007beqlrl-\002bf\003bf+\003bf-\003bfa\004bfa+\004bfa-\005bfctr\006"
    "bfctr+\006bfctr-\006bfctrl\007bfctrl+\007bfctrl-\003bfl\004bfl+\004bfl-"
    "\004bfla\005bfla+\005bfla-\004bflr\005bflr+\005bflr-\005bflrl\006bflrl+"
    "\006bflrl-\003bge\004bge+\004bge-\004bgea\005bgea+\005bgea-\006bgectr\007"
    "bgectr+\007bgectr-\007bgectrl\010bgectrl+\010bgectrl-\004bgel\005bgel+\005"
    "bgel-\005bgela\006bgela+\006bgela-\005bgelr\006bgelr+\006bgelr-\006bgel"
    "rl\007bgelrl+\007bgelrl-\003bgt\004bgt+\004bgt-\004bgta\005bgta+\005bgt"
    "a-\006bgtctr\007bgtctr+\007bgtctr-\007bgtctrl\010bgtctrl+\010bgtctrl-\004"
    "bgtl\005bgtl+\005bgtl-\005bgtla\006bgtla+\006bgtla-\005bgtlr\006bgtlr+\006"
    "bgtlr-\006bgtlrl\007bgtlrl+\007bgtlrl-\002bl\003bla\003ble\004ble+\004b"
    "le-\004blea\005blea+\005blea-\006blectr\007blectr+\007blectr-\007blectr"
    "l\010blectrl+\010blectrl-\004blel\005blel+\005blel-\005blela\006blela+\006"
    "blela-\005blelr\006blelr+\006blelr-\006blelrl\007blelrl+\007blelrl-\003"
    "blr\004blrl\003blt\004blt+\004blt-\004blta\005blta+\005blta-\006bltctr\007"
    "bltctr+\007bltctr-\007bltctrl\010bltctrl+\010bltctrl-\004bltl\005bltl+\005"
    "bltl-\005bltla\006bltla+\006bltla-\005bltlr\006bltlr+\006bltlr-\006bltl"
    "rl\007bltlrl+\007bltlrl-\003bne\004bne+\004bne-\004bnea\005bnea+\005bne"
    "a-\006bnectr\007bnectr+\007bnectr-\007bnectrl\010bnectrl+\010bnectrl-\004"
    "bnel\005bnel+\005bnel-\005bnela\006bnela+\006bnela-\005bnelr\006bnelr+\006"
    "bnelr-\006bnelrl\007bnelrl+\007bnelrl-\003bng\004bng+\004bng-\004bnga\005"
    "bnga+\005bnga-\006bngctr\007bngctr+\007bngctr-\007bngctrl\010bngctrl+\010"
    "bngctrl-\004bngl\005bngl+\005bngl-\005bngla\006bngla+\006bngla-\005bngl"
    "r\006bnglr+\006bnglr-\006bnglrl\007bnglrl+\007bnglrl-\003bnl\004bnl+\004"
    "bnl-\004bnla\005bnla+\005bnla-\006bnlctr\007bnlctr+\007bnlctr-\007bnlct"
    "rl\010bnlctrl+\010bnlctrl-\004bnll\005bnll+\005bnll-\005bnlla\006bnlla+"
    "\006bnlla-\005bnllr\006bnllr+\006bnllr-\006bnllrl\007bnllrl+\007bnllrl-"
    "\003bns\004bns+\004bns-\004bnsa\005bnsa+\005bnsa-\006bnsctr\007bnsctr+\007"
    "bnsctr-\007bnsctrl\010bnsctrl+\010bnsctrl-\004bnsl\005bnsl+\005bnsl-\005"
    "bnsla\006bnsla+\006bnsla-\005bnslr\006bnslr+\006bnslr-\006bnslrl\007bns"
    "lrl+\007bnslrl-\003bnu\004bnu+\004bnu-\004bnua\005bnua+\005bnua-\006bnu"
    "ctr\007bnuctr+\007bnuctr-\007bnuctrl\010bnuctrl+\010bnuctrl-\004bnul\005"
    "bnul+\005bnul-\005bnula\006bnula+\006bnula-\005bnulr\006bnulr+\006bnulr"
    "-\006bnulrl\007bnulrl+\007bnulrl-\006bpermd\005brinc\003bso\004bso+\004"
    "bso-\004bsoa\005bsoa+\005bsoa-\006bsoctr\007bsoctr+\007bsoctr-\007bsoct"
    "rl\010bsoctrl+\010bsoctrl-\004bsol\005bsol+\005bsol-\005bsola\006bsola+"
    "\006bsola-\005bsolr\006bsolr+\006bsolr-\006bsolrl\007bsolrl+\007bsolrl-"
    "\002bt\003bt+\003bt-\003bta\004bta+\004bta-\005btctr\006btctr+\006btctr"
    "-\006btctrl\007btctrl+\007btctrl-\003btl\004btl+\004btl-\004btla\005btl"
    "a+\005btla-\004btlr\005btlr+\005btlr-\005btlrl\006btlrl+\006btlrl-\003b"
    "un\004bun+\004bun-\004buna\005buna+\005buna-\006bunctr\007bunctr+\007bu"
    "nctr-\007bunctrl\010bunctrl+\010bunctrl-\004bunl\005bunl+\005bunl-\005b"
    "unla\006bunla+\006bunla-\005bunlr\006bunlr+\006bunlr-\006bunlrl\007bunl"
    "rl+\007bunlrl-\007clrbhrb\006clrldi\010clrlsldi\010clrlslwi\006clrlwi\006"
    "clrrdi\006clrrwi\003cmp\004cmpb\004cmpd\005cmpdi\004cmpi\004cmpl\005cmp"
    "ld\006cmpldi\005cmpli\005cmplw\006cmplwi\004cmpw\005cmpwi\006cntlzd\006"
    "cntlzw\005crand\006crandc\005crclr\005creqv\006crmove\006crnand\005crno"
    "r\005crnot\004cror\005crorc\005crset\005crxor\004dcba\004dcbf\004dcbi\005"
    "dcbst\004dcbt\006dcbtct\006dcbtds\006dcbtst\010dcbtstct\010dcbtstds\007"
    "dcbtstt\005dcbtt\004dcbz\005dcbzl\005dccci\003dci\004divd\005divde\006d"
    "ivdeu\005divdu\004divw\005divwe\006divweu\005divwu\003dss\006dssall\003"
    "dst\005dstst\006dststt\004dstt\005eieio\003eqv\005evabs\007evaddiw\013e"
    "vaddsmiaaw\013evaddssiaaw\013evaddumiaaw\013evaddusiaaw\006evaddw\005ev"
    "and\006evandc\007evcmpeq\010evcmpgts\010evcmpgtu\010evcmplts\010evcmplt"
    "u\010evcntlsw\010evcntlzw\007evdivws\007evdivwu\005eveqv\007evextsb\007"
    "evextsh\005evldd\006evlddx\005evldh\006evldhx\005evldw\006evldwx\013evl"
    "hhesplat\014evlhhesplatx\014evlhhossplat\015evlhhossplatx\014evlhhouspl"
    "at\015evlhhousplatx\006evlwhe\007evlwhex\007evlwhos\010evlwhosx\007evlw"
    "hou\010evlwhoux\nevlwhsplat\013evlwhsplatx\nevlwwsplat\013evlwwsplatx\t"
    "evmergehi\013evmergehilo\tevmergelo\013evmergelohi\013evmhegsmfaa\013ev"
    "mhegsmfan\013evmhegsmiaa\013evmhegsmian\013evmhegumiaa\013evmhegumian\010"
    "evmhesmf\tevmhesmfa\013evmhesmfaaw\013evmhesmfanw\010evmhesmi\tevmhesmi"
    "a\013evmhesmiaaw\013evmhesmianw\010evmhessf\tevmhessfa\013evmhessfaaw\013"
    "evmhessfanw\013evmhessiaaw\013evmhessianw\010evmheumi\tevmheumia\013evm"
    "heumiaaw\013evmheumianw\013evmheusiaaw\013evmheusianw\013evmhogsmfaa\013"
    "evmhogsmfan\013evmhogsmiaa\013evmhogsmian\013evmhogumiaa\013evmhogumian"
    "\010evmhosmf\tevmhosmfa\013evmhosmfaaw\013evmhosmfanw\010evmhosmi\tevmh"
    "osmia\013evmhosmiaaw\013evmhosmianw\010evmhossf\tevmhossfa\013evmhossfa"
    "aw\013evmhossfanw\013evmhossiaaw\013evmhossianw\010evmhoumi\tevmhoumia\013"
    "evmhoumiaaw\013evmhoumianw\013evmhousiaaw\013evmhousianw\005evmra\010ev"
    "mwhsmf\tevmwhsmfa\010evmwhsmi\tevmwhsmia\010evmwhssf\tevmwhssfa\010evmw"
    "humi\tevmwhumia\013evmwlsmiaaw\013evmwlsmianw\013evmwlssiaaw\013evmwlss"
    "ianw\010evmwlumi\tevmwlumia\013evmwlumiaaw\013evmwlumianw\013evmwlusiaa"
    "w\013evmwlusianw\007evmwsmf\010evmwsmfa\tevmwsmfaa\tevmwsmfan\007evmwsm"
    "i\010evmwsmia\tevmwsmiaa\tevmwsmian\007evmwssf\010evmwssfa\tevmwssfaa\t"
    "evmwssfan\007evmwumi\010evmwumia\tevmwumiaa\tevmwumian\006evnand\005evn"
    "eg\005evnor\004evor\005evorc\005evrlw\006evrlwi\006evrndw\005evslw\006e"
    "vslwi\tevsplatfi\010evsplati\007evsrwis\007evsrwiu\006evsrws\006evsrwu\006"
    "evstdd\007evstddx\006evstdh\007evstdhx\006evstdw\007evstdwx\007evstwhe\010"
    "evstwhex\007evstwho\010evstwhox\007evstwwe\010evstwwex\007evstwwo\010ev"
    "stwwox\014evsubfsmiaaw\014evsubfssiaaw\014evsubfumiaaw\014evsubfusiaaw\007"
    "evsubfw\010evsubifw\005evxor\006extldi\006extlwi\006extrdi\006extrwi\005"
    "extsb\005extsh\005extsw\004fabs\004fadd\005fadds\005fcfid\006fcfids\006"
    "fcfidu\007fcfidus\005fcmpu\006fcpsgn\005fctid\007fctiduz\006fctidz\005f"
    "ctiw\007fctiwuz\006fctiwz\004fdiv\005fdivs\005fmadd\006fmadds\003fmr\005"
    "fmsub\006fmsubs\004fmul\005fmuls\005fnabs\004fneg\006fnmadd\007fnmadds\006"
    "fnmsub\007fnmsubs\003fre\004fres\004frim\004frin\004frip\004friz\004frs"
    "p\007frsqrte\010frsqrtes\004fsel\005fsqrt\006fsqrts\004fsub\005fsubs\004"
    "icbi\004icbt\005iccci\003ici\006inslwi\006insrdi\006insrwi\004isel\005i"
    "sync\002la\005lbarx\003lbz\006lbzcix\004lbzu\005lbzux\004lbzx\002ld\005"
    "ldarx\005ldbrx\005ldcix\003ldu\004ldux\003ldx\003lfd\004lfdu\005lfdux\004"
    "lfdx\006lfiwax\006lfiwzx\003lfs\004lfsu\005lfsux\004lfsx\003lha\005lhar"
    "x\004lhau\005lhaux\004lhax\005lhbrx\003lhz\006lhzcix\004lhzu\005lhzux\004"
    "lhzx\002li\003lis\003lmw\004lswi\005lvebx\005lvehx\005lvewx\004lvsl\004"
    "lvsr\003lvx\004lvxl\003lwa\005lwarx\005lwaux\004lwax\005lwbrx\006lwsync"
    "\003lwz\006lwzcix\004lwzu\005lwzux\004lwzx\005lxsdx\007lxsiwax\007lxsiw"
    "zx\006lxsspx\006lxvd2x\006lxvdsx\006lxvw4x\004mbar\004mcrf\005mcrfs\005"
    "mfamr\005mfasr\007mfbhrbe\005mfbr0\005mfbr1\005mfbr2\005mfbr3\005mfbr4\005"
    "mfbr5\005mfbr6\005mfbr7\006mfcfar\004mfcr\005mfctr\005mfdar\007mfdbatl\007"
    "mfdbatu\006mfdccr\005mfdcr\006mfdear\005mfdec\006mfdscr\007mfdsisr\005m"
    "fesr\004mffs\007mfibatl\007mfibatu\006mficcr\004mflr\005mfmsr\006mfocrf"
    "\005mfpid\005mfpvr\006mfrtcl\006mfrtcu\006mfsdr1\tmfspefscr\005mfspr\006"
    "mfsprg\007mfsprg0\007mfsprg1\007mfsprg2\007mfsprg3\007mfsprg4\007mfsprg"
    "5\007mfsprg6\007mfsprg7\004mfsr\006mfsrin\006mfsrr0\006mfsrr1\006mfsrr2"
    "\006mfsrr3\004mftb\006mftbhi\005mftbl\006mftblo\005mftbu\005mftcr\006mf"
    "vscr\006mfvsrd\007mfvsrwz\005mfxer\002mr\005msync\005mtamr\005mtasr\005"
    "mtbr0\005mtbr1\005mtbr2\005mtbr3\005mtbr4\005mtbr5\005mtbr6\005mtbr7\006"
    "mtcfar\004mtcr\005mtcrf\005mtctr\005mtdar\007mtdbatl\007mtdbatu\006mtdc"
    "cr\005mtdcr\006mtdear\005mtdec\006mtdscr\007mtdsisr\005mtesr\006mtfsb0\006"
    "mtfsb1\005mtfsf\006mtfsfi\007mtibatl\007mtibatu\006mticcr\004mtlr\005mt"
    "msr\006mtmsrd\006mtocrf\005mtpid\006mtsdr1\tmtspefscr\005mtspr\006mtspr"
    "g\007mtsprg0\007mtsprg1\007mtsprg2\007mtsprg3\007mtsprg4\007mtsprg5\007"
    "mtsprg6\007mtsprg7\004mtsr\006mtsrin\006mtsrr0\006mtsrr1\006mtsrr2\006m"
    "tsrr3\006mttbhi\005mttbl\006mttblo\005mttbu\005mttcr\006mtvscr\006mtvsr"
    "d\007mtvsrwa\007mtvsrwz\005mtxer\005mulhd\006mulhdu\005mulhw\006mulhwu\005"
    "mulld\005mulli\005mullw\004nand\003neg\003nop\003nor\003not\002or\003or"
    "c\003ori\004oris\007popcntd\007popcntw\007ptesync\010qvaligni\tqvesplat"
    "i\006qvfabs\006qvfadd\007qvfadds\006qvfand\007qvfandc\007qvfcfid\010qvf"
    "cfids\010qvfcfidu\tqvfcfidus\006qvfclr\010qvfcmpeq\010qvfcmpgt\010qvfcm"
    "plt\010qvfcpsgn\007qvfctfb\007qvfctid\010qvfctidu\tqvfctiduz\010qvfctid"
    "z\007qvfctiw\010qvfctiwu\tqvfctiwuz\010qvfctiwz\006qvfequ\nqvflogical\007"
    "qvfmadd\010qvfmadds\005qvfmr\007qvfmsub\010qvfmsubs\006qvfmul\007qvfmul"
    "s\007qvfnabs\007qvfnand\006qvfneg\010qvfnmadd\tqvfnmadds\010qvfnmsub\tq"
    "vfnmsubs\006qvfnor\006qvfnot\005qvfor\006qvforc\007qvfperm\005qvfre\006"
    "qvfres\006qvfrim\006qvfrin\006qvfrip\006qvfriz\006qvfrsp\tqvfrsqrte\nqv"
    "frsqrtes\006qvfsel\006qvfset\006qvfsub\007qvfsubs\tqvftstnan\010qvfxmad"
    "d\tqvfxmadds\007qvfxmul\010qvfxmuls\006qvfxor\014qvfxxcpnmadd\015qvfxxc"
    "pnmadds\tqvfxxmadd\nqvfxxmadds\013qvfxxnpmadd\014qvfxxnpmadds\006qvgpci"
    "\010qvlfcdux\tqvlfcduxa\007qvlfcdx\010qvlfcdxa\010qvlfcsux\tqvlfcsuxa\007"
    "qvlfcsx\010qvlfcsxa\007qvlfdux\010qvlfduxa\006qvlfdx\007qvlfdxa\010qvlf"
    "iwax\tqvlfiwaxa\010qvlfiwzx\tqvlfiwzxa\007qvlfsux\010qvlfsuxa\006qvlfsx"
    "\007qvlfsxa\010qvlpcldx\010qvlpclsx\010qvlpcrdx\010qvlpcrsx\tqvstfcdux\n"
    "qvstfcduxa\nqvstfcduxi\013qvstfcduxia\010qvstfcdx\tqvstfcdxa\tqvstfcdxi"
    "\nqvstfcdxia\tqvstfcsux\nqvstfcsuxa\nqvstfcsuxi\013qvstfcsuxia\010qvstf"
    "csx\tqvstfcsxa\tqvstfcsxi\nqvstfcsxia\010qvstfdux\tqvstfduxa\tqvstfduxi"
    "\nqvstfduxia\007qvstfdx\010qvstfdxa\010qvstfdxi\tqvstfdxia\010qvstfiwx\t"
    "qvstfiwxa\010qvstfsux\tqvstfsuxa\tqvstfsuxi\nqvstfsuxia\007qvstfsx\010q"
    "vstfsxa\010qvstfsxi\tqvstfsxia\004rfci\004rfdi\005rfebb\003rfi\004rfid\005"
    "rfmci\005rldcl\005rldcr\005rldic\006rldicl\006rldicr\006rldimi\006rlwim"
    "i\006rlwinm\005rlwnm\005rotld\006rotldi\005rotlw\006rotlwi\006rotrdi\006"
    "rotrwi\002sc\005slbia\005slbie\007slbmfee\006slbmte\003sld\004sldi\003s"
    "lw\004slwi\004srad\005sradi\004sraw\005srawi\003srd\004srdi\003srw\004s"
    "rwi\003stb\006stbcix\005stbcx\004stbu\005stbux\004stbx\003std\006stdbrx"
    "\006stdcix\005stdcx\004stdu\005stdux\004stdx\004stfd\005stfdu\006stfdux"
    "\005stfdx\006stfiwx\004stfs\005stfsu\006stfsux\005stfsx\003sth\006sthbr"
    "x\006sthcix\005sthcx\004sthu\005sthux\004sthx\004stmw\005stswi\006stveb"
    "x\006stvehx\006stvewx\004stvx\005stvxl\003stw\006stwbrx\006stwcix\005st"
    "wcx\004stwu\005stwux\004stwx\006stxsdx\007stxsiwx\007stxsspx\007stxvd2x"
    "\007stxvw4x\003sub\004subc\004subf\005subfc\005subfe\006subfic\006subfm"
    "e\006subfze\004subi\005subic\005subis\004sync\006tabort\010tabortdc\tta"
    "bortdci\010tabortwc\ttabortwci\006tbegin\006tcheck\002td\004tdeq\005tde"
    "qi\004tdge\005tdgei\004tdgt\005tdgti\003tdi\004tdle\005tdlei\005tdlge\006"
    "tdlgei\005tdlgt\006tdlgti\005tdlle\006tdllei\005tdllt\006tdllti\005tdln"
    "g\006tdlngi\005tdlnl\006tdlnli\004tdlt\005tdlti\004tdne\005tdnei\004tdn"
    "g\005tdngi\004tdnl\005tdnli\003tdu\004tdui\004tend\005tlbia\005tlbie\006"
    "tlbiel\007tlbivax\005tlbld\005tlbli\005tlbre\007tlbrehi\007tlbrelo\005t"
    "lbsx\007tlbsync\005tlbwe\007tlbwehi\007tlbwelo\004trap\010trechkpt\010t"
    "reclaim\003tsr\002tw\004tweq\005tweqi\004twge\005twgei\004twgt\005twgti"
    "\003twi\004twle\005twlei\005twlge\006twlgei\005twlgt\006twlgti\005twlle"
    "\006twllei\005twllt\006twllti\005twlng\006twlngi\005twlnl\006twlnli\004"
    "twlt\005twlti\004twne\005twnei\004twng\005twngi\004twnl\005twnli\003twu"
    "\004twui\007vaddcuq\007vaddcuw\010vaddecuq\010vaddeuqm\006vaddfp\007vad"
    "dsbs\007vaddshs\007vaddsws\007vaddubm\007vaddubs\007vaddudm\007vadduhm\007"
    "vadduhs\007vadduqm\007vadduwm\007vadduws\004vand\005vandc\006vavgsb\006"
    "vavgsh\006vavgsw\006vavgub\006vavguh\006vavguw\007vbpermq\005vcfsx\005v"
    "cfux\007vcipher\013vcipherlast\005vclzb\005vclzd\005vclzh\005vclzw\007v"
    "cmpbfp\010vcmpeqfp\010vcmpequb\010vcmpequd\010vcmpequh\010vcmpequw\010v"
    "cmpgefp\010vcmpgtfp\010vcmpgtsb\010vcmpgtsd\010vcmpgtsh\010vcmpgtsw\010"
    "vcmpgtub\010vcmpgtud\010vcmpgtuh\010vcmpgtuw\006vctsxs\006vctuxs\004veq"
    "v\010vexptefp\005vgbbd\007vlogefp\007vmaddfp\006vmaxfp\006vmaxsb\006vma"
    "xsd\006vmaxsh\006vmaxsw\006vmaxub\006vmaxud\006vmaxuh\006vmaxuw\tvmhadd"
    "shs\nvmhraddshs\006vminfp\006vminsb\006vminsd\006vminsh\006vminsw\006vm"
    "inub\006vminud\006vminuh\006vminuw\tvmladduhm\006vmrgew\006vmrghb\006vm"
    "rghh\006vmrghw\006vmrglb\006vmrglh\006vmrglw\006vmrgow\010vmsummbm\010v"
    "msumshm\010vmsumshs\010vmsumubm\010vmsumuhm\010vmsumuhs\007vmulesb\007v"
    "mulesh\007vmulesw\007vmuleub\007vmuleuh\007vmuleuw\007vmulosb\007vmulos"
    "h\007vmulosw\007vmuloub\007vmulouh\007vmulouw\007vmuluwm\005vnand\010vn"
    "cipher\014vncipherlast\010vnmsubfp\004vnor\003vor\004vorc\005vperm\010v"
    "permxor\005vpkpx\007vpksdss\007vpksdus\007vpkshss\007vpkshus\007vpkswss"
    "\007vpkswus\007vpkudum\007vpkudus\007vpkuhum\007vpkuhus\007vpkuwum\007v"
    "pkuwus\007vpmsumb\007vpmsumd\007vpmsumh\007vpmsumw\010vpopcntb\010vpopc"
    "ntd\010vpopcnth\010vpopcntw\005vrefp\005vrfim\005vrfin\005vrfip\005vrfi"
    "z\004vrlb\004vrld\004vrlh\004vrlw\tvrsqrtefp\005vsbox\004vsel\nvshasigm"
    "ad\nvshasigmaw\003vsl\004vslb\004vsld\006vsldoi\004vslh\004vslo\004vslw"
    "\006vspltb\006vsplth\010vspltisb\010vspltish\010vspltisw\006vspltw\003v"
    "sr\005vsrab\005vsrad\005vsrah\005vsraw\004vsrb\004vsrd\004vsrh\004vsro\004"
    "vsrw\007vsubcuq\007vsubcuw\010vsubecuq\010vsubeuqm\006vsubfp\007vsubsbs"
    "\007vsubshs\007vsubsws\007vsububm\007vsububs\007vsubudm\007vsubuhm\007v"
    "subuhs\007vsubuqm\007vsubuwm\007vsubuws\010vsum2sws\010vsum4sbs\010vsum"
    "4shs\010vsum4ubs\007vsumsws\007vupkhpx\007vupkhsb\007vupkhsh\007vupkhsw"
    "\007vupklpx\007vupklsb\007vupklsh\007vupklsw\004vxor\004wait\010waitimp"
    "l\007waitrsv\005wrtee\006wrteei\004xnop\003xor\004xori\005xoris\007xsab"
    "sdp\007xsadddp\007xsaddsp\010xscmpodp\010xscmpudp\txscpsgndp\010xscvdps"
    "p\txscvdpspn\nxscvdpsxds\nxscvdpsxws\nxscvdpuxds\nxscvdpuxws\010xscvspd"
    "p\txscvspdpn\txscvsxddp\txscvsxdsp\txscvuxddp\txscvuxdsp\007xsdivdp\007"
    "xsdivsp\txsmaddadp\txsmaddasp\txsmaddmdp\txsmaddmsp\007xsmaxdp\007xsmin"
    "dp\txsmsubadp\txsmsubasp\txsmsubmdp\txsmsubmsp\007xsmuldp\007xsmulsp\010"
    "xsnabsdp\007xsnegdp\nxsnmaddadp\nxsnmaddasp\nxsnmaddmdp\nxsnmaddmsp\nxs"
    "nmsubadp\nxsnmsubasp\nxsnmsubmdp\nxsnmsubmsp\006xsrdpi\007xsrdpic\007xs"
    "rdpim\007xsrdpip\007xsrdpiz\006xsredp\006xsresp\nxsrsqrtedp\nxsrsqrtesp"
    "\010xssqrtdp\010xssqrtsp\007xssubdp\007xssubsp\010xstdivdp\txstsqrtdp\007"
    "xvabsdp\007xvabssp\007xvadddp\007xvaddsp\txvcmpeqdp\txvcmpeqsp\txvcmpge"
    "dp\txvcmpgesp\txvcmpgtdp\txvcmpgtsp\txvcpsgndp\txvcpsgnsp\010xvcvdpsp\n"
    "xvcvdpsxds\nxvcvdpsxws\nxvcvdpuxds\nxvcvdpuxws\010xvcvspdp\nxvcvspsxds\n"
    "xvcvspsxws\nxvcvspuxds\nxvcvspuxws\txvcvsxddp\txvcvsxdsp\txvcvsxwdp\txv"
    "cvsxwsp\txvcvuxddp\txvcvuxdsp\txvcvuxwdp\txvcvuxwsp\007xvdivdp\007xvdiv"
    "sp\txvmaddadp\txvmaddasp\txvmaddmdp\txvmaddmsp\007xvmaxdp\007xvmaxsp\007"
    "xvmindp\007xvminsp\007xvmovdp\007xvmovsp\txvmsubadp\txvmsubasp\txvmsubm"
    "dp\txvmsubmsp\007xvmuldp\007xvmulsp\010xvnabsdp\010xvnabssp\007xvnegdp\007"
    "xvnegsp\nxvnmaddadp\nxvnmaddasp\nxvnmaddmdp\nxvnmaddmsp\nxvnmsubadp\nxv"
    "nmsubasp\nxvnmsubmdp\nxvnmsubmsp\006xvrdpi\007xvrdpic\007xvrdpim\007xvr"
    "dpip\007xvrdpiz\006xvredp\006xvresp\006xvrspi\007xvrspic\007xvrspim\007"
    "xvrspip\007xvrspiz\nxvrsqrtedp\nxvrsqrtesp\010xvsqrtdp\010xvsqrtsp\007x"
    "vsubdp\007xvsubsp\010xvtdivdp\010xvtdivsp\txvtsqrtdp\txvtsqrtsp\006xxla"
    "nd\007xxlandc\006xxleqv\007xxlnand\006xxlnor\005xxlor\006xxlorc\006xxlx"
    "or\007xxmrghd\007xxmrghw\007xxmrgld\007xxmrglw\010xxpermdi\005xxsel\007"
    "xxsldwi\007xxspltd\007xxspltw\007xxswapd";

namespace {
  struct MatchEntry {
    uint16_t Mnemonic;
    uint16_t Opcode;
    uint16_t ConvertFn;
    uint8_t RequiredFeatures;
    uint16_t Classes[7];
    StringRef getMnemonic() const {
      return StringRef(MnemonicTable + Mnemonic + 1,
                       MnemonicTable[Mnemonic]);
    }
  };

  // Predicate for searching for an opcode.
  struct LessOpcode {
    bool operator()(const MatchEntry &LHS, StringRef RHS) {
      return LHS.getMnemonic() < RHS;
    }
    bool operator()(StringRef LHS, const MatchEntry &RHS) {
      return LHS < RHS.getMnemonic();
    }
    bool operator()(const MatchEntry &LHS, const MatchEntry &RHS) {
      return LHS.getMnemonic() < RHS.getMnemonic();
    }
  };
} // end anonymous namespace.

static const MatchEntry MatchTable0[] = {
  { 0 /* add */, PPC::ADD8TLS_, Convert__RegG8RC1_1__RegG8RC1_2__TLSReg1_3, 0, { MCK_add, MCK_RegG8RC, MCK_RegG8RC, MCK_TLSReg }, },
  { 0 /* add */, PPC::ADD4, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_add, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 0 /* add */, PPC::ADD4o, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_add, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4 /* addc */, PPC::ADDC, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_addc, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4 /* addc */, PPC::ADDCo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_addc, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9 /* adde */, PPC::ADDE, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_adde, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 9 /* adde */, PPC::ADDEo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_adde, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 14 /* addi */, PPC::ADDI, Convert__RegGPRC1_1__RegGPRCNoR01_2__S16Imm1_3, 0, { MCK_addi, MCK_RegGPRC, MCK_RegGPRCNoR0, MCK_S16Imm }, },
  { 19 /* addic */, PPC::ADDIC, Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3, 0, { MCK_addic, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 19 /* addic */, PPC::ADDICo, Convert__RegGPRC1_2__RegGPRC1_3__S16Imm1_4, 0, { MCK_addic, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 25 /* addis */, PPC::ADDIS, Convert__RegGPRC1_1__RegGPRCNoR01_2__S17Imm1_3, 0, { MCK_addis, MCK_RegGPRC, MCK_RegGPRCNoR0, MCK_S17Imm }, },
  { 31 /* addme */, PPC::ADDME, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_addme, MCK_RegGPRC, MCK_RegGPRC }, },
  { 31 /* addme */, PPC::ADDMEo, Convert__RegGPRC1_2__RegGPRC1_3, 0, { MCK_addme, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 37 /* addze */, PPC::ADDZE, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_addze, MCK_RegGPRC, MCK_RegGPRC }, },
  { 37 /* addze */, PPC::ADDZEo, Convert__RegGPRC1_2__RegGPRC1_3, 0, { MCK_addze, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 43 /* and */, PPC::AND, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_and, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 43 /* and */, PPC::ANDo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_and, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 47 /* andc */, PPC::ANDC, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_andc, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 47 /* andc */, PPC::ANDCo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_andc, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 52 /* andi */, PPC::ANDIo, Convert__RegGPRC1_2__RegGPRC1_3__U16Imm1_4, 0, { MCK_andi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 57 /* andis */, PPC::ANDISo, Convert__RegGPRC1_2__RegGPRC1_3__U16Imm1_4, 0, { MCK_andis, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 63 /* attn */, PPC::ATTN, Convert_NoOperands, 0, { MCK_attn }, },
  { 68 /* b */, PPC::B, Convert__DirectBr1_1, 0, { MCK_b, MCK_DirectBr }, },
  { 70 /* ba */, PPC::BA, Convert__DirectBr1_1, 0, { MCK_ba, MCK_DirectBr }, },
  { 73 /* bc */, PPC::gBC, Convert__U5Imm1_1__RegCRBITRC1_2__CondBr1_3, 0, { MCK_bc, MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 76 /* bca */, PPC::gBCA, Convert__U5Imm1_1__RegCRBITRC1_2__CondBr1_3, 0, { MCK_bca, MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 80 /* bcctr */, PPC::gBCCTR, Convert__U5Imm1_1__RegCRBITRC1_2__imm_95_0, 0, { MCK_bcctr, MCK_U5Imm, MCK_RegCRBITRC }, },
  { 80 /* bcctr */, PPC::gBCCTR, Convert__U5Imm1_1__RegCRBITRC1_2__Imm1_3, 0, { MCK_bcctr, MCK_U5Imm, MCK_RegCRBITRC, MCK_Imm }, },
  { 86 /* bcctrl */, PPC::gBCCTRL, Convert__U5Imm1_1__RegCRBITRC1_2__imm_95_0, 0, { MCK_bcctrl, MCK_U5Imm, MCK_RegCRBITRC }, },
  { 86 /* bcctrl */, PPC::gBCCTRL, Convert__U5Imm1_1__RegCRBITRC1_2__Imm1_3, 0, { MCK_bcctrl, MCK_U5Imm, MCK_RegCRBITRC, MCK_Imm }, },
  { 93 /* bcl */, PPC::gBCL, Convert__U5Imm1_1__RegCRBITRC1_2__CondBr1_3, 0, { MCK_bcl, MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 97 /* bcla */, PPC::gBCLA, Convert__U5Imm1_1__RegCRBITRC1_2__CondBr1_3, 0, { MCK_bcla, MCK_U5Imm, MCK_RegCRBITRC, MCK_CondBr }, },
  { 102 /* bclr */, PPC::gBCLR, Convert__U5Imm1_1__RegCRBITRC1_2__imm_95_0, 0, { MCK_bclr, MCK_U5Imm, MCK_RegCRBITRC }, },
  { 102 /* bclr */, PPC::gBCLR, Convert__U5Imm1_1__RegCRBITRC1_2__Imm1_3, 0, { MCK_bclr, MCK_U5Imm, MCK_RegCRBITRC, MCK_Imm }, },
  { 107 /* bclrl */, PPC::gBCLRL, Convert__U5Imm1_1__RegCRBITRC1_2__imm_95_0, 0, { MCK_bclrl, MCK_U5Imm, MCK_RegCRBITRC }, },
  { 107 /* bclrl */, PPC::gBCLRL, Convert__U5Imm1_1__RegCRBITRC1_2__Imm1_3, 0, { MCK_bclrl, MCK_U5Imm, MCK_RegCRBITRC, MCK_Imm }, },
  { 113 /* bctr */, PPC::BCTR, Convert_NoOperands, 0, { MCK_bctr }, },
  { 118 /* bctrl */, PPC::BCTRL, Convert_NoOperands, 0, { MCK_bctrl }, },
  { 124 /* bdnz */, PPC::BDNZ, Convert__CondBr1_1, 0, { MCK_bdnz, MCK_CondBr }, },
  { 129 /* bdnz+ */, PPC::BDNZp, Convert__CondBr1_1, 0, { MCK_bdnz_43_, MCK_CondBr }, },
  { 135 /* bdnz- */, PPC::BDNZm, Convert__CondBr1_1, 0, { MCK_bdnz_MINUS_, MCK_CondBr }, },
  { 141 /* bdnza */, PPC::BDNZA, Convert__CondBr1_1, 0, { MCK_bdnza, MCK_CondBr }, },
  { 147 /* bdnza+ */, PPC::BDNZAp, Convert__CondBr1_1, 0, { MCK_bdnza_43_, MCK_CondBr }, },
  { 154 /* bdnza- */, PPC::BDNZAm, Convert__CondBr1_1, 0, { MCK_bdnza_MINUS_, MCK_CondBr }, },
  { 161 /* bdnzf */, PPC::gBC, Convert__imm_95_0__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdnzf, MCK_RegCRBITRC, MCK_CondBr }, },
  { 167 /* bdnzfa */, PPC::gBCA, Convert__imm_95_0__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdnzfa, MCK_RegCRBITRC, MCK_CondBr }, },
  { 174 /* bdnzfl */, PPC::gBCL, Convert__imm_95_0__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdnzfl, MCK_RegCRBITRC, MCK_CondBr }, },
  { 181 /* bdnzfla */, PPC::gBCLA, Convert__imm_95_0__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdnzfla, MCK_RegCRBITRC, MCK_CondBr }, },
  { 189 /* bdnzflr */, PPC::gBCLR, Convert__imm_95_0__RegCRBITRC1_1__imm_95_0, 0, { MCK_bdnzflr, MCK_RegCRBITRC }, },
  { 197 /* bdnzflrl */, PPC::gBCLRL, Convert__imm_95_0__RegCRBITRC1_1__imm_95_0, 0, { MCK_bdnzflrl, MCK_RegCRBITRC }, },
  { 206 /* bdnzl */, PPC::BDNZL, Convert__CondBr1_1, 0, { MCK_bdnzl, MCK_CondBr }, },
  { 212 /* bdnzl+ */, PPC::BDNZLp, Convert__CondBr1_1, 0, { MCK_bdnzl_43_, MCK_CondBr }, },
  { 219 /* bdnzl- */, PPC::BDNZLm, Convert__CondBr1_1, 0, { MCK_bdnzl_MINUS_, MCK_CondBr }, },
  { 226 /* bdnzla */, PPC::BDNZLA, Convert__CondBr1_1, 0, { MCK_bdnzla, MCK_CondBr }, },
  { 233 /* bdnzla+ */, PPC::BDNZLAp, Convert__CondBr1_1, 0, { MCK_bdnzla_43_, MCK_CondBr }, },
  { 241 /* bdnzla- */, PPC::BDNZLAm, Convert__CondBr1_1, 0, { MCK_bdnzla_MINUS_, MCK_CondBr }, },
  { 249 /* bdnzlr */, PPC::BDNZLR, Convert_NoOperands, 0, { MCK_bdnzlr }, },
  { 256 /* bdnzlr+ */, PPC::BDNZLRp, Convert_NoOperands, 0, { MCK_bdnzlr_43_ }, },
  { 264 /* bdnzlr- */, PPC::BDNZLRm, Convert_NoOperands, 0, { MCK_bdnzlr_MINUS_ }, },
  { 272 /* bdnzlrl */, PPC::BDNZLRL, Convert_NoOperands, 0, { MCK_bdnzlrl }, },
  { 280 /* bdnzlrl+ */, PPC::BDNZLRLp, Convert_NoOperands, 0, { MCK_bdnzlrl_43_ }, },
  { 289 /* bdnzlrl- */, PPC::BDNZLRLm, Convert_NoOperands, 0, { MCK_bdnzlrl_MINUS_ }, },
  { 298 /* bdnzt */, PPC::gBC, Convert__imm_95_8__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdnzt, MCK_RegCRBITRC, MCK_CondBr }, },
  { 304 /* bdnzta */, PPC::gBCA, Convert__imm_95_8__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdnzta, MCK_RegCRBITRC, MCK_CondBr }, },
  { 311 /* bdnztl */, PPC::gBCL, Convert__imm_95_8__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdnztl, MCK_RegCRBITRC, MCK_CondBr }, },
  { 318 /* bdnztla */, PPC::gBCLA, Convert__imm_95_8__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdnztla, MCK_RegCRBITRC, MCK_CondBr }, },
  { 326 /* bdnztlr */, PPC::gBCLR, Convert__imm_95_8__RegCRBITRC1_1__imm_95_0, 0, { MCK_bdnztlr, MCK_RegCRBITRC }, },
  { 334 /* bdnztlrl */, PPC::gBCLRL, Convert__imm_95_8__RegCRBITRC1_1__imm_95_0, 0, { MCK_bdnztlrl, MCK_RegCRBITRC }, },
  { 343 /* bdz */, PPC::BDZ, Convert__CondBr1_1, 0, { MCK_bdz, MCK_CondBr }, },
  { 347 /* bdz+ */, PPC::BDZp, Convert__CondBr1_1, 0, { MCK_bdz_43_, MCK_CondBr }, },
  { 352 /* bdz- */, PPC::BDZm, Convert__CondBr1_1, 0, { MCK_bdz_MINUS_, MCK_CondBr }, },
  { 357 /* bdza */, PPC::BDZA, Convert__CondBr1_1, 0, { MCK_bdza, MCK_CondBr }, },
  { 362 /* bdza+ */, PPC::BDZAp, Convert__CondBr1_1, 0, { MCK_bdza_43_, MCK_CondBr }, },
  { 368 /* bdza- */, PPC::BDZAm, Convert__CondBr1_1, 0, { MCK_bdza_MINUS_, MCK_CondBr }, },
  { 374 /* bdzf */, PPC::gBC, Convert__imm_95_2__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdzf, MCK_RegCRBITRC, MCK_CondBr }, },
  { 379 /* bdzfa */, PPC::gBCA, Convert__imm_95_2__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdzfa, MCK_RegCRBITRC, MCK_CondBr }, },
  { 385 /* bdzfl */, PPC::gBCL, Convert__imm_95_2__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdzfl, MCK_RegCRBITRC, MCK_CondBr }, },
  { 391 /* bdzfla */, PPC::gBCLA, Convert__imm_95_2__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdzfla, MCK_RegCRBITRC, MCK_CondBr }, },
  { 398 /* bdzflr */, PPC::gBCLR, Convert__imm_95_2__RegCRBITRC1_1__imm_95_0, 0, { MCK_bdzflr, MCK_RegCRBITRC }, },
  { 405 /* bdzflrl */, PPC::gBCLRL, Convert__imm_95_2__RegCRBITRC1_1__imm_95_0, 0, { MCK_bdzflrl, MCK_RegCRBITRC }, },
  { 413 /* bdzl */, PPC::BDZL, Convert__CondBr1_1, 0, { MCK_bdzl, MCK_CondBr }, },
  { 418 /* bdzl+ */, PPC::BDZLp, Convert__CondBr1_1, 0, { MCK_bdzl_43_, MCK_CondBr }, },
  { 424 /* bdzl- */, PPC::BDZLm, Convert__CondBr1_1, 0, { MCK_bdzl_MINUS_, MCK_CondBr }, },
  { 430 /* bdzla */, PPC::BDZLA, Convert__CondBr1_1, 0, { MCK_bdzla, MCK_CondBr }, },
  { 436 /* bdzla+ */, PPC::BDZLAp, Convert__CondBr1_1, 0, { MCK_bdzla_43_, MCK_CondBr }, },
  { 443 /* bdzla- */, PPC::BDZLAm, Convert__CondBr1_1, 0, { MCK_bdzla_MINUS_, MCK_CondBr }, },
  { 450 /* bdzlr */, PPC::BDZLR, Convert_NoOperands, 0, { MCK_bdzlr }, },
  { 456 /* bdzlr+ */, PPC::BDZLRp, Convert_NoOperands, 0, { MCK_bdzlr_43_ }, },
  { 463 /* bdzlr- */, PPC::BDZLRm, Convert_NoOperands, 0, { MCK_bdzlr_MINUS_ }, },
  { 470 /* bdzlrl */, PPC::BDZLRL, Convert_NoOperands, 0, { MCK_bdzlrl }, },
  { 477 /* bdzlrl+ */, PPC::BDZLRLp, Convert_NoOperands, 0, { MCK_bdzlrl_43_ }, },
  { 485 /* bdzlrl- */, PPC::BDZLRLm, Convert_NoOperands, 0, { MCK_bdzlrl_MINUS_ }, },
  { 493 /* bdzt */, PPC::gBC, Convert__imm_95_10__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdzt, MCK_RegCRBITRC, MCK_CondBr }, },
  { 498 /* bdzta */, PPC::gBCA, Convert__imm_95_10__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdzta, MCK_RegCRBITRC, MCK_CondBr }, },
  { 504 /* bdztl */, PPC::gBCL, Convert__imm_95_10__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdztl, MCK_RegCRBITRC, MCK_CondBr }, },
  { 510 /* bdztla */, PPC::gBCLA, Convert__imm_95_10__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bdztla, MCK_RegCRBITRC, MCK_CondBr }, },
  { 517 /* bdztlr */, PPC::gBCLR, Convert__imm_95_10__RegCRBITRC1_1__imm_95_0, 0, { MCK_bdztlr, MCK_RegCRBITRC }, },
  { 524 /* bdztlrl */, PPC::gBCLRL, Convert__imm_95_10__RegCRBITRC1_1__imm_95_0, 0, { MCK_bdztlrl, MCK_RegCRBITRC }, },
  { 532 /* beq */, PPC::BCC, Convert__imm_95_76__regCR0__CondBr1_1, 0, { MCK_beq, MCK_CondBr }, },
  { 532 /* beq */, PPC::BCC, Convert__imm_95_76__RegCRRC1_1__CondBr1_2, 0, { MCK_beq, MCK_RegCRRC, MCK_CondBr }, },
  { 536 /* beq+ */, PPC::BCC, Convert__imm_95_79__regCR0__CondBr1_1, 0, { MCK_beq_43_, MCK_CondBr }, },
  { 536 /* beq+ */, PPC::BCC, Convert__imm_95_79__RegCRRC1_1__CondBr1_2, 0, { MCK_beq_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 541 /* beq- */, PPC::BCC, Convert__imm_95_78__regCR0__CondBr1_1, 0, { MCK_beq_MINUS_, MCK_CondBr }, },
  { 541 /* beq- */, PPC::BCC, Convert__imm_95_78__RegCRRC1_1__CondBr1_2, 0, { MCK_beq_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 546 /* beqa */, PPC::BCCA, Convert__imm_95_76__regCR0__CondBr1_1, 0, { MCK_beqa, MCK_CondBr }, },
  { 546 /* beqa */, PPC::BCCA, Convert__imm_95_76__RegCRRC1_1__CondBr1_2, 0, { MCK_beqa, MCK_RegCRRC, MCK_CondBr }, },
  { 551 /* beqa+ */, PPC::BCCA, Convert__imm_95_79__regCR0__CondBr1_1, 0, { MCK_beqa_43_, MCK_CondBr }, },
  { 551 /* beqa+ */, PPC::BCCA, Convert__imm_95_79__RegCRRC1_1__CondBr1_2, 0, { MCK_beqa_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 557 /* beqa- */, PPC::BCCA, Convert__imm_95_78__regCR0__CondBr1_1, 0, { MCK_beqa_MINUS_, MCK_CondBr }, },
  { 557 /* beqa- */, PPC::BCCA, Convert__imm_95_78__RegCRRC1_1__CondBr1_2, 0, { MCK_beqa_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 563 /* beqctr */, PPC::BCCCTR, Convert__imm_95_76__regCR0, 0, { MCK_beqctr }, },
  { 563 /* beqctr */, PPC::BCCCTR, Convert__imm_95_76__RegCRRC1_1, 0, { MCK_beqctr, MCK_RegCRRC }, },
  { 570 /* beqctr+ */, PPC::BCCCTR, Convert__imm_95_79__regCR0, 0, { MCK_beqctr_43_ }, },
  { 570 /* beqctr+ */, PPC::BCCCTR, Convert__imm_95_79__RegCRRC1_1, 0, { MCK_beqctr_43_, MCK_RegCRRC }, },
  { 578 /* beqctr- */, PPC::BCCCTR, Convert__imm_95_78__regCR0, 0, { MCK_beqctr_MINUS_ }, },
  { 578 /* beqctr- */, PPC::BCCCTR, Convert__imm_95_78__RegCRRC1_1, 0, { MCK_beqctr_MINUS_, MCK_RegCRRC }, },
  { 586 /* beqctrl */, PPC::BCCCTRL, Convert__imm_95_76__regCR0, 0, { MCK_beqctrl }, },
  { 586 /* beqctrl */, PPC::BCCCTRL, Convert__imm_95_76__RegCRRC1_1, 0, { MCK_beqctrl, MCK_RegCRRC }, },
  { 594 /* beqctrl+ */, PPC::BCCCTRL, Convert__imm_95_79__regCR0, 0, { MCK_beqctrl_43_ }, },
  { 594 /* beqctrl+ */, PPC::BCCCTRL, Convert__imm_95_79__RegCRRC1_1, 0, { MCK_beqctrl_43_, MCK_RegCRRC }, },
  { 603 /* beqctrl- */, PPC::BCCCTRL, Convert__imm_95_78__regCR0, 0, { MCK_beqctrl_MINUS_ }, },
  { 603 /* beqctrl- */, PPC::BCCCTRL, Convert__imm_95_78__RegCRRC1_1, 0, { MCK_beqctrl_MINUS_, MCK_RegCRRC }, },
  { 612 /* beql */, PPC::BCCL, Convert__imm_95_76__regCR0__CondBr1_1, 0, { MCK_beql, MCK_CondBr }, },
  { 612 /* beql */, PPC::BCCL, Convert__imm_95_76__RegCRRC1_1__CondBr1_2, 0, { MCK_beql, MCK_RegCRRC, MCK_CondBr }, },
  { 617 /* beql+ */, PPC::BCCL, Convert__imm_95_79__regCR0__CondBr1_1, 0, { MCK_beql_43_, MCK_CondBr }, },
  { 617 /* beql+ */, PPC::BCCL, Convert__imm_95_79__RegCRRC1_1__CondBr1_2, 0, { MCK_beql_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 623 /* beql- */, PPC::BCCL, Convert__imm_95_78__regCR0__CondBr1_1, 0, { MCK_beql_MINUS_, MCK_CondBr }, },
  { 623 /* beql- */, PPC::BCCL, Convert__imm_95_78__RegCRRC1_1__CondBr1_2, 0, { MCK_beql_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 629 /* beqla */, PPC::BCCLA, Convert__imm_95_76__regCR0__CondBr1_1, 0, { MCK_beqla, MCK_CondBr }, },
  { 629 /* beqla */, PPC::BCCLA, Convert__imm_95_76__RegCRRC1_1__CondBr1_2, 0, { MCK_beqla, MCK_RegCRRC, MCK_CondBr }, },
  { 635 /* beqla+ */, PPC::BCCLA, Convert__imm_95_79__regCR0__CondBr1_1, 0, { MCK_beqla_43_, MCK_CondBr }, },
  { 635 /* beqla+ */, PPC::BCCLA, Convert__imm_95_79__RegCRRC1_1__CondBr1_2, 0, { MCK_beqla_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 642 /* beqla- */, PPC::BCCLA, Convert__imm_95_78__regCR0__CondBr1_1, 0, { MCK_beqla_MINUS_, MCK_CondBr }, },
  { 642 /* beqla- */, PPC::BCCLA, Convert__imm_95_78__RegCRRC1_1__CondBr1_2, 0, { MCK_beqla_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 649 /* beqlr */, PPC::BCCLR, Convert__imm_95_76__regCR0, 0, { MCK_beqlr }, },
  { 649 /* beqlr */, PPC::BCCLR, Convert__imm_95_76__RegCRRC1_1, 0, { MCK_beqlr, MCK_RegCRRC }, },
  { 655 /* beqlr+ */, PPC::BCCLR, Convert__imm_95_79__regCR0, 0, { MCK_beqlr_43_ }, },
  { 655 /* beqlr+ */, PPC::BCCLR, Convert__imm_95_79__RegCRRC1_1, 0, { MCK_beqlr_43_, MCK_RegCRRC }, },
  { 662 /* beqlr- */, PPC::BCCLR, Convert__imm_95_78__regCR0, 0, { MCK_beqlr_MINUS_ }, },
  { 662 /* beqlr- */, PPC::BCCLR, Convert__imm_95_78__RegCRRC1_1, 0, { MCK_beqlr_MINUS_, MCK_RegCRRC }, },
  { 669 /* beqlrl */, PPC::BCCLRL, Convert__imm_95_76__regCR0, 0, { MCK_beqlrl }, },
  { 669 /* beqlrl */, PPC::BCCLRL, Convert__imm_95_76__RegCRRC1_1, 0, { MCK_beqlrl, MCK_RegCRRC }, },
  { 676 /* beqlrl+ */, PPC::BCCLRL, Convert__imm_95_79__regCR0, 0, { MCK_beqlrl_43_ }, },
  { 676 /* beqlrl+ */, PPC::BCCLRL, Convert__imm_95_79__RegCRRC1_1, 0, { MCK_beqlrl_43_, MCK_RegCRRC }, },
  { 684 /* beqlrl- */, PPC::BCCLRL, Convert__imm_95_78__regCR0, 0, { MCK_beqlrl_MINUS_ }, },
  { 684 /* beqlrl- */, PPC::BCCLRL, Convert__imm_95_78__RegCRRC1_1, 0, { MCK_beqlrl_MINUS_, MCK_RegCRRC }, },
  { 692 /* bf */, PPC::gBC, Convert__imm_95_4__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bf, MCK_RegCRBITRC, MCK_CondBr }, },
  { 695 /* bf+ */, PPC::gBC, Convert__imm_95_7__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bf_43_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 699 /* bf- */, PPC::gBC, Convert__imm_95_6__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bf_MINUS_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 703 /* bfa */, PPC::gBCA, Convert__imm_95_4__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bfa, MCK_RegCRBITRC, MCK_CondBr }, },
  { 707 /* bfa+ */, PPC::gBCA, Convert__imm_95_7__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bfa_43_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 712 /* bfa- */, PPC::gBCA, Convert__imm_95_6__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bfa_MINUS_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 717 /* bfctr */, PPC::gBCCTR, Convert__imm_95_4__RegCRBITRC1_1__imm_95_0, 0, { MCK_bfctr, MCK_RegCRBITRC }, },
  { 723 /* bfctr+ */, PPC::gBCCTR, Convert__imm_95_7__RegCRBITRC1_1__imm_95_0, 0, { MCK_bfctr_43_, MCK_RegCRBITRC }, },
  { 730 /* bfctr- */, PPC::gBCCTR, Convert__imm_95_6__RegCRBITRC1_1__imm_95_0, 0, { MCK_bfctr_MINUS_, MCK_RegCRBITRC }, },
  { 737 /* bfctrl */, PPC::gBCCTRL, Convert__imm_95_4__RegCRBITRC1_1__imm_95_0, 0, { MCK_bfctrl, MCK_RegCRBITRC }, },
  { 744 /* bfctrl+ */, PPC::gBCCTRL, Convert__imm_95_7__RegCRBITRC1_1__imm_95_0, 0, { MCK_bfctrl_43_, MCK_RegCRBITRC }, },
  { 752 /* bfctrl- */, PPC::gBCCTRL, Convert__imm_95_6__RegCRBITRC1_1__imm_95_0, 0, { MCK_bfctrl_MINUS_, MCK_RegCRBITRC }, },
  { 760 /* bfl */, PPC::gBCL, Convert__imm_95_4__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bfl, MCK_RegCRBITRC, MCK_CondBr }, },
  { 764 /* bfl+ */, PPC::gBCL, Convert__imm_95_7__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bfl_43_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 769 /* bfl- */, PPC::gBCL, Convert__imm_95_6__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bfl_MINUS_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 774 /* bfla */, PPC::gBCLA, Convert__imm_95_4__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bfla, MCK_RegCRBITRC, MCK_CondBr }, },
  { 779 /* bfla+ */, PPC::gBCLA, Convert__imm_95_7__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bfla_43_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 785 /* bfla- */, PPC::gBCLA, Convert__imm_95_6__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bfla_MINUS_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 791 /* bflr */, PPC::gBCLR, Convert__imm_95_4__RegCRBITRC1_1__imm_95_0, 0, { MCK_bflr, MCK_RegCRBITRC }, },
  { 796 /* bflr+ */, PPC::gBCLR, Convert__imm_95_7__RegCRBITRC1_1__imm_95_0, 0, { MCK_bflr_43_, MCK_RegCRBITRC }, },
  { 802 /* bflr- */, PPC::gBCLR, Convert__imm_95_6__RegCRBITRC1_1__imm_95_0, 0, { MCK_bflr_MINUS_, MCK_RegCRBITRC }, },
  { 808 /* bflrl */, PPC::gBCLRL, Convert__imm_95_4__RegCRBITRC1_1__imm_95_0, 0, { MCK_bflrl, MCK_RegCRBITRC }, },
  { 814 /* bflrl+ */, PPC::gBCLRL, Convert__imm_95_7__RegCRBITRC1_1__imm_95_0, 0, { MCK_bflrl_43_, MCK_RegCRBITRC }, },
  { 821 /* bflrl- */, PPC::gBCLRL, Convert__imm_95_6__RegCRBITRC1_1__imm_95_0, 0, { MCK_bflrl_MINUS_, MCK_RegCRBITRC }, },
  { 828 /* bge */, PPC::BCC, Convert__imm_95_4__regCR0__CondBr1_1, 0, { MCK_bge, MCK_CondBr }, },
  { 828 /* bge */, PPC::BCC, Convert__imm_95_4__RegCRRC1_1__CondBr1_2, 0, { MCK_bge, MCK_RegCRRC, MCK_CondBr }, },
  { 832 /* bge+ */, PPC::BCC, Convert__imm_95_7__regCR0__CondBr1_1, 0, { MCK_bge_43_, MCK_CondBr }, },
  { 832 /* bge+ */, PPC::BCC, Convert__imm_95_7__RegCRRC1_1__CondBr1_2, 0, { MCK_bge_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 837 /* bge- */, PPC::BCC, Convert__imm_95_6__regCR0__CondBr1_1, 0, { MCK_bge_MINUS_, MCK_CondBr }, },
  { 837 /* bge- */, PPC::BCC, Convert__imm_95_6__RegCRRC1_1__CondBr1_2, 0, { MCK_bge_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 842 /* bgea */, PPC::BCCA, Convert__imm_95_4__regCR0__CondBr1_1, 0, { MCK_bgea, MCK_CondBr }, },
  { 842 /* bgea */, PPC::BCCA, Convert__imm_95_4__RegCRRC1_1__CondBr1_2, 0, { MCK_bgea, MCK_RegCRRC, MCK_CondBr }, },
  { 847 /* bgea+ */, PPC::BCCA, Convert__imm_95_7__regCR0__CondBr1_1, 0, { MCK_bgea_43_, MCK_CondBr }, },
  { 847 /* bgea+ */, PPC::BCCA, Convert__imm_95_7__RegCRRC1_1__CondBr1_2, 0, { MCK_bgea_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 853 /* bgea- */, PPC::BCCA, Convert__imm_95_6__regCR0__CondBr1_1, 0, { MCK_bgea_MINUS_, MCK_CondBr }, },
  { 853 /* bgea- */, PPC::BCCA, Convert__imm_95_6__RegCRRC1_1__CondBr1_2, 0, { MCK_bgea_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 859 /* bgectr */, PPC::BCCCTR, Convert__imm_95_4__regCR0, 0, { MCK_bgectr }, },
  { 859 /* bgectr */, PPC::BCCCTR, Convert__imm_95_4__RegCRRC1_1, 0, { MCK_bgectr, MCK_RegCRRC }, },
  { 866 /* bgectr+ */, PPC::BCCCTR, Convert__imm_95_7__regCR0, 0, { MCK_bgectr_43_ }, },
  { 866 /* bgectr+ */, PPC::BCCCTR, Convert__imm_95_7__RegCRRC1_1, 0, { MCK_bgectr_43_, MCK_RegCRRC }, },
  { 874 /* bgectr- */, PPC::BCCCTR, Convert__imm_95_6__regCR0, 0, { MCK_bgectr_MINUS_ }, },
  { 874 /* bgectr- */, PPC::BCCCTR, Convert__imm_95_6__RegCRRC1_1, 0, { MCK_bgectr_MINUS_, MCK_RegCRRC }, },
  { 882 /* bgectrl */, PPC::BCCCTRL, Convert__imm_95_4__regCR0, 0, { MCK_bgectrl }, },
  { 882 /* bgectrl */, PPC::BCCCTRL, Convert__imm_95_4__RegCRRC1_1, 0, { MCK_bgectrl, MCK_RegCRRC }, },
  { 890 /* bgectrl+ */, PPC::BCCCTRL, Convert__imm_95_7__regCR0, 0, { MCK_bgectrl_43_ }, },
  { 890 /* bgectrl+ */, PPC::BCCCTRL, Convert__imm_95_7__RegCRRC1_1, 0, { MCK_bgectrl_43_, MCK_RegCRRC }, },
  { 899 /* bgectrl- */, PPC::BCCCTRL, Convert__imm_95_6__regCR0, 0, { MCK_bgectrl_MINUS_ }, },
  { 899 /* bgectrl- */, PPC::BCCCTRL, Convert__imm_95_6__RegCRRC1_1, 0, { MCK_bgectrl_MINUS_, MCK_RegCRRC }, },
  { 908 /* bgel */, PPC::BCCL, Convert__imm_95_4__regCR0__CondBr1_1, 0, { MCK_bgel, MCK_CondBr }, },
  { 908 /* bgel */, PPC::BCCL, Convert__imm_95_4__RegCRRC1_1__CondBr1_2, 0, { MCK_bgel, MCK_RegCRRC, MCK_CondBr }, },
  { 913 /* bgel+ */, PPC::BCCL, Convert__imm_95_7__regCR0__CondBr1_1, 0, { MCK_bgel_43_, MCK_CondBr }, },
  { 913 /* bgel+ */, PPC::BCCL, Convert__imm_95_7__RegCRRC1_1__CondBr1_2, 0, { MCK_bgel_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 919 /* bgel- */, PPC::BCCL, Convert__imm_95_6__regCR0__CondBr1_1, 0, { MCK_bgel_MINUS_, MCK_CondBr }, },
  { 919 /* bgel- */, PPC::BCCL, Convert__imm_95_6__RegCRRC1_1__CondBr1_2, 0, { MCK_bgel_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 925 /* bgela */, PPC::BCCLA, Convert__imm_95_4__regCR0__CondBr1_1, 0, { MCK_bgela, MCK_CondBr }, },
  { 925 /* bgela */, PPC::BCCLA, Convert__imm_95_4__RegCRRC1_1__CondBr1_2, 0, { MCK_bgela, MCK_RegCRRC, MCK_CondBr }, },
  { 931 /* bgela+ */, PPC::BCCLA, Convert__imm_95_7__regCR0__CondBr1_1, 0, { MCK_bgela_43_, MCK_CondBr }, },
  { 931 /* bgela+ */, PPC::BCCLA, Convert__imm_95_7__RegCRRC1_1__CondBr1_2, 0, { MCK_bgela_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 938 /* bgela- */, PPC::BCCLA, Convert__imm_95_6__regCR0__CondBr1_1, 0, { MCK_bgela_MINUS_, MCK_CondBr }, },
  { 938 /* bgela- */, PPC::BCCLA, Convert__imm_95_6__RegCRRC1_1__CondBr1_2, 0, { MCK_bgela_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 945 /* bgelr */, PPC::BCCLR, Convert__imm_95_4__regCR0, 0, { MCK_bgelr }, },
  { 945 /* bgelr */, PPC::BCCLR, Convert__imm_95_4__RegCRRC1_1, 0, { MCK_bgelr, MCK_RegCRRC }, },
  { 951 /* bgelr+ */, PPC::BCCLR, Convert__imm_95_7__regCR0, 0, { MCK_bgelr_43_ }, },
  { 951 /* bgelr+ */, PPC::BCCLR, Convert__imm_95_7__RegCRRC1_1, 0, { MCK_bgelr_43_, MCK_RegCRRC }, },
  { 958 /* bgelr- */, PPC::BCCLR, Convert__imm_95_6__regCR0, 0, { MCK_bgelr_MINUS_ }, },
  { 958 /* bgelr- */, PPC::BCCLR, Convert__imm_95_6__RegCRRC1_1, 0, { MCK_bgelr_MINUS_, MCK_RegCRRC }, },
  { 965 /* bgelrl */, PPC::BCCLRL, Convert__imm_95_4__regCR0, 0, { MCK_bgelrl }, },
  { 965 /* bgelrl */, PPC::BCCLRL, Convert__imm_95_4__RegCRRC1_1, 0, { MCK_bgelrl, MCK_RegCRRC }, },
  { 972 /* bgelrl+ */, PPC::BCCLRL, Convert__imm_95_7__regCR0, 0, { MCK_bgelrl_43_ }, },
  { 972 /* bgelrl+ */, PPC::BCCLRL, Convert__imm_95_7__RegCRRC1_1, 0, { MCK_bgelrl_43_, MCK_RegCRRC }, },
  { 980 /* bgelrl- */, PPC::BCCLRL, Convert__imm_95_6__regCR0, 0, { MCK_bgelrl_MINUS_ }, },
  { 980 /* bgelrl- */, PPC::BCCLRL, Convert__imm_95_6__RegCRRC1_1, 0, { MCK_bgelrl_MINUS_, MCK_RegCRRC }, },
  { 988 /* bgt */, PPC::BCC, Convert__imm_95_44__regCR0__CondBr1_1, 0, { MCK_bgt, MCK_CondBr }, },
  { 988 /* bgt */, PPC::BCC, Convert__imm_95_44__RegCRRC1_1__CondBr1_2, 0, { MCK_bgt, MCK_RegCRRC, MCK_CondBr }, },
  { 992 /* bgt+ */, PPC::BCC, Convert__imm_95_47__regCR0__CondBr1_1, 0, { MCK_bgt_43_, MCK_CondBr }, },
  { 992 /* bgt+ */, PPC::BCC, Convert__imm_95_47__RegCRRC1_1__CondBr1_2, 0, { MCK_bgt_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 997 /* bgt- */, PPC::BCC, Convert__imm_95_46__regCR0__CondBr1_1, 0, { MCK_bgt_MINUS_, MCK_CondBr }, },
  { 997 /* bgt- */, PPC::BCC, Convert__imm_95_46__RegCRRC1_1__CondBr1_2, 0, { MCK_bgt_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1002 /* bgta */, PPC::BCCA, Convert__imm_95_44__regCR0__CondBr1_1, 0, { MCK_bgta, MCK_CondBr }, },
  { 1002 /* bgta */, PPC::BCCA, Convert__imm_95_44__RegCRRC1_1__CondBr1_2, 0, { MCK_bgta, MCK_RegCRRC, MCK_CondBr }, },
  { 1007 /* bgta+ */, PPC::BCCA, Convert__imm_95_47__regCR0__CondBr1_1, 0, { MCK_bgta_43_, MCK_CondBr }, },
  { 1007 /* bgta+ */, PPC::BCCA, Convert__imm_95_47__RegCRRC1_1__CondBr1_2, 0, { MCK_bgta_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1013 /* bgta- */, PPC::BCCA, Convert__imm_95_46__regCR0__CondBr1_1, 0, { MCK_bgta_MINUS_, MCK_CondBr }, },
  { 1013 /* bgta- */, PPC::BCCA, Convert__imm_95_46__RegCRRC1_1__CondBr1_2, 0, { MCK_bgta_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1019 /* bgtctr */, PPC::BCCCTR, Convert__imm_95_44__regCR0, 0, { MCK_bgtctr }, },
  { 1019 /* bgtctr */, PPC::BCCCTR, Convert__imm_95_44__RegCRRC1_1, 0, { MCK_bgtctr, MCK_RegCRRC }, },
  { 1026 /* bgtctr+ */, PPC::BCCCTR, Convert__imm_95_47__regCR0, 0, { MCK_bgtctr_43_ }, },
  { 1026 /* bgtctr+ */, PPC::BCCCTR, Convert__imm_95_47__RegCRRC1_1, 0, { MCK_bgtctr_43_, MCK_RegCRRC }, },
  { 1034 /* bgtctr- */, PPC::BCCCTR, Convert__imm_95_46__regCR0, 0, { MCK_bgtctr_MINUS_ }, },
  { 1034 /* bgtctr- */, PPC::BCCCTR, Convert__imm_95_46__RegCRRC1_1, 0, { MCK_bgtctr_MINUS_, MCK_RegCRRC }, },
  { 1042 /* bgtctrl */, PPC::BCCCTRL, Convert__imm_95_44__regCR0, 0, { MCK_bgtctrl }, },
  { 1042 /* bgtctrl */, PPC::BCCCTRL, Convert__imm_95_44__RegCRRC1_1, 0, { MCK_bgtctrl, MCK_RegCRRC }, },
  { 1050 /* bgtctrl+ */, PPC::BCCCTRL, Convert__imm_95_47__regCR0, 0, { MCK_bgtctrl_43_ }, },
  { 1050 /* bgtctrl+ */, PPC::BCCCTRL, Convert__imm_95_47__RegCRRC1_1, 0, { MCK_bgtctrl_43_, MCK_RegCRRC }, },
  { 1059 /* bgtctrl- */, PPC::BCCCTRL, Convert__imm_95_46__regCR0, 0, { MCK_bgtctrl_MINUS_ }, },
  { 1059 /* bgtctrl- */, PPC::BCCCTRL, Convert__imm_95_46__RegCRRC1_1, 0, { MCK_bgtctrl_MINUS_, MCK_RegCRRC }, },
  { 1068 /* bgtl */, PPC::BCCL, Convert__imm_95_44__regCR0__CondBr1_1, 0, { MCK_bgtl, MCK_CondBr }, },
  { 1068 /* bgtl */, PPC::BCCL, Convert__imm_95_44__RegCRRC1_1__CondBr1_2, 0, { MCK_bgtl, MCK_RegCRRC, MCK_CondBr }, },
  { 1073 /* bgtl+ */, PPC::BCCL, Convert__imm_95_47__regCR0__CondBr1_1, 0, { MCK_bgtl_43_, MCK_CondBr }, },
  { 1073 /* bgtl+ */, PPC::BCCL, Convert__imm_95_47__RegCRRC1_1__CondBr1_2, 0, { MCK_bgtl_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1079 /* bgtl- */, PPC::BCCL, Convert__imm_95_46__regCR0__CondBr1_1, 0, { MCK_bgtl_MINUS_, MCK_CondBr }, },
  { 1079 /* bgtl- */, PPC::BCCL, Convert__imm_95_46__RegCRRC1_1__CondBr1_2, 0, { MCK_bgtl_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1085 /* bgtla */, PPC::BCCLA, Convert__imm_95_44__regCR0__CondBr1_1, 0, { MCK_bgtla, MCK_CondBr }, },
  { 1085 /* bgtla */, PPC::BCCLA, Convert__imm_95_44__RegCRRC1_1__CondBr1_2, 0, { MCK_bgtla, MCK_RegCRRC, MCK_CondBr }, },
  { 1091 /* bgtla+ */, PPC::BCCLA, Convert__imm_95_47__regCR0__CondBr1_1, 0, { MCK_bgtla_43_, MCK_CondBr }, },
  { 1091 /* bgtla+ */, PPC::BCCLA, Convert__imm_95_47__RegCRRC1_1__CondBr1_2, 0, { MCK_bgtla_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1098 /* bgtla- */, PPC::BCCLA, Convert__imm_95_46__regCR0__CondBr1_1, 0, { MCK_bgtla_MINUS_, MCK_CondBr }, },
  { 1098 /* bgtla- */, PPC::BCCLA, Convert__imm_95_46__RegCRRC1_1__CondBr1_2, 0, { MCK_bgtla_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1105 /* bgtlr */, PPC::BCCLR, Convert__imm_95_44__regCR0, 0, { MCK_bgtlr }, },
  { 1105 /* bgtlr */, PPC::BCCLR, Convert__imm_95_44__RegCRRC1_1, 0, { MCK_bgtlr, MCK_RegCRRC }, },
  { 1111 /* bgtlr+ */, PPC::BCCLR, Convert__imm_95_47__regCR0, 0, { MCK_bgtlr_43_ }, },
  { 1111 /* bgtlr+ */, PPC::BCCLR, Convert__imm_95_47__RegCRRC1_1, 0, { MCK_bgtlr_43_, MCK_RegCRRC }, },
  { 1118 /* bgtlr- */, PPC::BCCLR, Convert__imm_95_46__regCR0, 0, { MCK_bgtlr_MINUS_ }, },
  { 1118 /* bgtlr- */, PPC::BCCLR, Convert__imm_95_46__RegCRRC1_1, 0, { MCK_bgtlr_MINUS_, MCK_RegCRRC }, },
  { 1125 /* bgtlrl */, PPC::BCCLRL, Convert__imm_95_44__regCR0, 0, { MCK_bgtlrl }, },
  { 1125 /* bgtlrl */, PPC::BCCLRL, Convert__imm_95_44__RegCRRC1_1, 0, { MCK_bgtlrl, MCK_RegCRRC }, },
  { 1132 /* bgtlrl+ */, PPC::BCCLRL, Convert__imm_95_47__regCR0, 0, { MCK_bgtlrl_43_ }, },
  { 1132 /* bgtlrl+ */, PPC::BCCLRL, Convert__imm_95_47__RegCRRC1_1, 0, { MCK_bgtlrl_43_, MCK_RegCRRC }, },
  { 1140 /* bgtlrl- */, PPC::BCCLRL, Convert__imm_95_46__regCR0, 0, { MCK_bgtlrl_MINUS_ }, },
  { 1140 /* bgtlrl- */, PPC::BCCLRL, Convert__imm_95_46__RegCRRC1_1, 0, { MCK_bgtlrl_MINUS_, MCK_RegCRRC }, },
  { 1148 /* bl */, PPC::BL, Convert__DirectBr1_1, 0, { MCK_bl, MCK_DirectBr }, },
  { 1148 /* bl */, PPC::BL8_TLS_, Convert__DirectBr1_1__Imm1_2, 0, { MCK_bl, MCK_DirectBr, MCK_Imm }, },
  { 1151 /* bla */, PPC::BLA, Convert__DirectBr1_1, 0, { MCK_bla, MCK_DirectBr }, },
  { 1155 /* ble */, PPC::BCC, Convert__imm_95_36__regCR0__CondBr1_1, 0, { MCK_ble, MCK_CondBr }, },
  { 1155 /* ble */, PPC::BCC, Convert__imm_95_36__RegCRRC1_1__CondBr1_2, 0, { MCK_ble, MCK_RegCRRC, MCK_CondBr }, },
  { 1159 /* ble+ */, PPC::BCC, Convert__imm_95_39__regCR0__CondBr1_1, 0, { MCK_ble_43_, MCK_CondBr }, },
  { 1159 /* ble+ */, PPC::BCC, Convert__imm_95_39__RegCRRC1_1__CondBr1_2, 0, { MCK_ble_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1164 /* ble- */, PPC::BCC, Convert__imm_95_38__regCR0__CondBr1_1, 0, { MCK_ble_MINUS_, MCK_CondBr }, },
  { 1164 /* ble- */, PPC::BCC, Convert__imm_95_38__RegCRRC1_1__CondBr1_2, 0, { MCK_ble_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1169 /* blea */, PPC::BCCA, Convert__imm_95_36__regCR0__CondBr1_1, 0, { MCK_blea, MCK_CondBr }, },
  { 1169 /* blea */, PPC::BCCA, Convert__imm_95_36__RegCRRC1_1__CondBr1_2, 0, { MCK_blea, MCK_RegCRRC, MCK_CondBr }, },
  { 1174 /* blea+ */, PPC::BCCA, Convert__imm_95_39__regCR0__CondBr1_1, 0, { MCK_blea_43_, MCK_CondBr }, },
  { 1174 /* blea+ */, PPC::BCCA, Convert__imm_95_39__RegCRRC1_1__CondBr1_2, 0, { MCK_blea_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1180 /* blea- */, PPC::BCCA, Convert__imm_95_38__regCR0__CondBr1_1, 0, { MCK_blea_MINUS_, MCK_CondBr }, },
  { 1180 /* blea- */, PPC::BCCA, Convert__imm_95_38__RegCRRC1_1__CondBr1_2, 0, { MCK_blea_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1186 /* blectr */, PPC::BCCCTR, Convert__imm_95_36__regCR0, 0, { MCK_blectr }, },
  { 1186 /* blectr */, PPC::BCCCTR, Convert__imm_95_36__RegCRRC1_1, 0, { MCK_blectr, MCK_RegCRRC }, },
  { 1193 /* blectr+ */, PPC::BCCCTR, Convert__imm_95_39__regCR0, 0, { MCK_blectr_43_ }, },
  { 1193 /* blectr+ */, PPC::BCCCTR, Convert__imm_95_39__RegCRRC1_1, 0, { MCK_blectr_43_, MCK_RegCRRC }, },
  { 1201 /* blectr- */, PPC::BCCCTR, Convert__imm_95_38__regCR0, 0, { MCK_blectr_MINUS_ }, },
  { 1201 /* blectr- */, PPC::BCCCTR, Convert__imm_95_38__RegCRRC1_1, 0, { MCK_blectr_MINUS_, MCK_RegCRRC }, },
  { 1209 /* blectrl */, PPC::BCCCTRL, Convert__imm_95_36__regCR0, 0, { MCK_blectrl }, },
  { 1209 /* blectrl */, PPC::BCCCTRL, Convert__imm_95_36__RegCRRC1_1, 0, { MCK_blectrl, MCK_RegCRRC }, },
  { 1217 /* blectrl+ */, PPC::BCCCTRL, Convert__imm_95_39__regCR0, 0, { MCK_blectrl_43_ }, },
  { 1217 /* blectrl+ */, PPC::BCCCTRL, Convert__imm_95_39__RegCRRC1_1, 0, { MCK_blectrl_43_, MCK_RegCRRC }, },
  { 1226 /* blectrl- */, PPC::BCCCTRL, Convert__imm_95_38__regCR0, 0, { MCK_blectrl_MINUS_ }, },
  { 1226 /* blectrl- */, PPC::BCCCTRL, Convert__imm_95_38__RegCRRC1_1, 0, { MCK_blectrl_MINUS_, MCK_RegCRRC }, },
  { 1235 /* blel */, PPC::BCCL, Convert__imm_95_36__regCR0__CondBr1_1, 0, { MCK_blel, MCK_CondBr }, },
  { 1235 /* blel */, PPC::BCCL, Convert__imm_95_36__RegCRRC1_1__CondBr1_2, 0, { MCK_blel, MCK_RegCRRC, MCK_CondBr }, },
  { 1240 /* blel+ */, PPC::BCCL, Convert__imm_95_39__regCR0__CondBr1_1, 0, { MCK_blel_43_, MCK_CondBr }, },
  { 1240 /* blel+ */, PPC::BCCL, Convert__imm_95_39__RegCRRC1_1__CondBr1_2, 0, { MCK_blel_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1246 /* blel- */, PPC::BCCL, Convert__imm_95_38__regCR0__CondBr1_1, 0, { MCK_blel_MINUS_, MCK_CondBr }, },
  { 1246 /* blel- */, PPC::BCCL, Convert__imm_95_38__RegCRRC1_1__CondBr1_2, 0, { MCK_blel_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1252 /* blela */, PPC::BCCLA, Convert__imm_95_36__regCR0__CondBr1_1, 0, { MCK_blela, MCK_CondBr }, },
  { 1252 /* blela */, PPC::BCCLA, Convert__imm_95_36__RegCRRC1_1__CondBr1_2, 0, { MCK_blela, MCK_RegCRRC, MCK_CondBr }, },
  { 1258 /* blela+ */, PPC::BCCLA, Convert__imm_95_39__regCR0__CondBr1_1, 0, { MCK_blela_43_, MCK_CondBr }, },
  { 1258 /* blela+ */, PPC::BCCLA, Convert__imm_95_39__RegCRRC1_1__CondBr1_2, 0, { MCK_blela_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1265 /* blela- */, PPC::BCCLA, Convert__imm_95_38__regCR0__CondBr1_1, 0, { MCK_blela_MINUS_, MCK_CondBr }, },
  { 1265 /* blela- */, PPC::BCCLA, Convert__imm_95_38__RegCRRC1_1__CondBr1_2, 0, { MCK_blela_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1272 /* blelr */, PPC::BCCLR, Convert__imm_95_36__regCR0, 0, { MCK_blelr }, },
  { 1272 /* blelr */, PPC::BCCLR, Convert__imm_95_36__RegCRRC1_1, 0, { MCK_blelr, MCK_RegCRRC }, },
  { 1278 /* blelr+ */, PPC::BCCLR, Convert__imm_95_39__regCR0, 0, { MCK_blelr_43_ }, },
  { 1278 /* blelr+ */, PPC::BCCLR, Convert__imm_95_39__RegCRRC1_1, 0, { MCK_blelr_43_, MCK_RegCRRC }, },
  { 1285 /* blelr- */, PPC::BCCLR, Convert__imm_95_38__regCR0, 0, { MCK_blelr_MINUS_ }, },
  { 1285 /* blelr- */, PPC::BCCLR, Convert__imm_95_38__RegCRRC1_1, 0, { MCK_blelr_MINUS_, MCK_RegCRRC }, },
  { 1292 /* blelrl */, PPC::BCCLRL, Convert__imm_95_36__regCR0, 0, { MCK_blelrl }, },
  { 1292 /* blelrl */, PPC::BCCLRL, Convert__imm_95_36__RegCRRC1_1, 0, { MCK_blelrl, MCK_RegCRRC }, },
  { 1299 /* blelrl+ */, PPC::BCCLRL, Convert__imm_95_39__regCR0, 0, { MCK_blelrl_43_ }, },
  { 1299 /* blelrl+ */, PPC::BCCLRL, Convert__imm_95_39__RegCRRC1_1, 0, { MCK_blelrl_43_, MCK_RegCRRC }, },
  { 1307 /* blelrl- */, PPC::BCCLRL, Convert__imm_95_38__regCR0, 0, { MCK_blelrl_MINUS_ }, },
  { 1307 /* blelrl- */, PPC::BCCLRL, Convert__imm_95_38__RegCRRC1_1, 0, { MCK_blelrl_MINUS_, MCK_RegCRRC }, },
  { 1315 /* blr */, PPC::BLR, Convert_NoOperands, 0, { MCK_blr }, },
  { 1319 /* blrl */, PPC::BLRL, Convert_NoOperands, 0, { MCK_blrl }, },
  { 1324 /* blt */, PPC::BCC, Convert__imm_95_12__regCR0__CondBr1_1, 0, { MCK_blt, MCK_CondBr }, },
  { 1324 /* blt */, PPC::BCC, Convert__imm_95_12__RegCRRC1_1__CondBr1_2, 0, { MCK_blt, MCK_RegCRRC, MCK_CondBr }, },
  { 1328 /* blt+ */, PPC::BCC, Convert__imm_95_15__regCR0__CondBr1_1, 0, { MCK_blt_43_, MCK_CondBr }, },
  { 1328 /* blt+ */, PPC::BCC, Convert__imm_95_15__RegCRRC1_1__CondBr1_2, 0, { MCK_blt_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1333 /* blt- */, PPC::BCC, Convert__imm_95_14__regCR0__CondBr1_1, 0, { MCK_blt_MINUS_, MCK_CondBr }, },
  { 1333 /* blt- */, PPC::BCC, Convert__imm_95_14__RegCRRC1_1__CondBr1_2, 0, { MCK_blt_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1338 /* blta */, PPC::BCCA, Convert__imm_95_12__regCR0__CondBr1_1, 0, { MCK_blta, MCK_CondBr }, },
  { 1338 /* blta */, PPC::BCCA, Convert__imm_95_12__RegCRRC1_1__CondBr1_2, 0, { MCK_blta, MCK_RegCRRC, MCK_CondBr }, },
  { 1343 /* blta+ */, PPC::BCCA, Convert__imm_95_15__regCR0__CondBr1_1, 0, { MCK_blta_43_, MCK_CondBr }, },
  { 1343 /* blta+ */, PPC::BCCA, Convert__imm_95_15__RegCRRC1_1__CondBr1_2, 0, { MCK_blta_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1349 /* blta- */, PPC::BCCA, Convert__imm_95_14__regCR0__CondBr1_1, 0, { MCK_blta_MINUS_, MCK_CondBr }, },
  { 1349 /* blta- */, PPC::BCCA, Convert__imm_95_14__RegCRRC1_1__CondBr1_2, 0, { MCK_blta_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1355 /* bltctr */, PPC::BCCCTR, Convert__imm_95_12__regCR0, 0, { MCK_bltctr }, },
  { 1355 /* bltctr */, PPC::BCCCTR, Convert__imm_95_12__RegCRRC1_1, 0, { MCK_bltctr, MCK_RegCRRC }, },
  { 1362 /* bltctr+ */, PPC::BCCCTR, Convert__imm_95_15__regCR0, 0, { MCK_bltctr_43_ }, },
  { 1362 /* bltctr+ */, PPC::BCCCTR, Convert__imm_95_15__RegCRRC1_1, 0, { MCK_bltctr_43_, MCK_RegCRRC }, },
  { 1370 /* bltctr- */, PPC::BCCCTR, Convert__imm_95_14__regCR0, 0, { MCK_bltctr_MINUS_ }, },
  { 1370 /* bltctr- */, PPC::BCCCTR, Convert__imm_95_14__RegCRRC1_1, 0, { MCK_bltctr_MINUS_, MCK_RegCRRC }, },
  { 1378 /* bltctrl */, PPC::BCCCTRL, Convert__imm_95_12__regCR0, 0, { MCK_bltctrl }, },
  { 1378 /* bltctrl */, PPC::BCCCTRL, Convert__imm_95_12__RegCRRC1_1, 0, { MCK_bltctrl, MCK_RegCRRC }, },
  { 1386 /* bltctrl+ */, PPC::BCCCTRL, Convert__imm_95_15__regCR0, 0, { MCK_bltctrl_43_ }, },
  { 1386 /* bltctrl+ */, PPC::BCCCTRL, Convert__imm_95_15__RegCRRC1_1, 0, { MCK_bltctrl_43_, MCK_RegCRRC }, },
  { 1395 /* bltctrl- */, PPC::BCCCTRL, Convert__imm_95_14__regCR0, 0, { MCK_bltctrl_MINUS_ }, },
  { 1395 /* bltctrl- */, PPC::BCCCTRL, Convert__imm_95_14__RegCRRC1_1, 0, { MCK_bltctrl_MINUS_, MCK_RegCRRC }, },
  { 1404 /* bltl */, PPC::BCCL, Convert__imm_95_12__regCR0__CondBr1_1, 0, { MCK_bltl, MCK_CondBr }, },
  { 1404 /* bltl */, PPC::BCCL, Convert__imm_95_12__RegCRRC1_1__CondBr1_2, 0, { MCK_bltl, MCK_RegCRRC, MCK_CondBr }, },
  { 1409 /* bltl+ */, PPC::BCCL, Convert__imm_95_15__regCR0__CondBr1_1, 0, { MCK_bltl_43_, MCK_CondBr }, },
  { 1409 /* bltl+ */, PPC::BCCL, Convert__imm_95_15__RegCRRC1_1__CondBr1_2, 0, { MCK_bltl_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1415 /* bltl- */, PPC::BCCL, Convert__imm_95_14__regCR0__CondBr1_1, 0, { MCK_bltl_MINUS_, MCK_CondBr }, },
  { 1415 /* bltl- */, PPC::BCCL, Convert__imm_95_14__RegCRRC1_1__CondBr1_2, 0, { MCK_bltl_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1421 /* bltla */, PPC::BCCLA, Convert__imm_95_12__regCR0__CondBr1_1, 0, { MCK_bltla, MCK_CondBr }, },
  { 1421 /* bltla */, PPC::BCCLA, Convert__imm_95_12__RegCRRC1_1__CondBr1_2, 0, { MCK_bltla, MCK_RegCRRC, MCK_CondBr }, },
  { 1427 /* bltla+ */, PPC::BCCLA, Convert__imm_95_15__regCR0__CondBr1_1, 0, { MCK_bltla_43_, MCK_CondBr }, },
  { 1427 /* bltla+ */, PPC::BCCLA, Convert__imm_95_15__RegCRRC1_1__CondBr1_2, 0, { MCK_bltla_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1434 /* bltla- */, PPC::BCCLA, Convert__imm_95_14__regCR0__CondBr1_1, 0, { MCK_bltla_MINUS_, MCK_CondBr }, },
  { 1434 /* bltla- */, PPC::BCCLA, Convert__imm_95_14__RegCRRC1_1__CondBr1_2, 0, { MCK_bltla_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1441 /* bltlr */, PPC::BCCLR, Convert__imm_95_12__regCR0, 0, { MCK_bltlr }, },
  { 1441 /* bltlr */, PPC::BCCLR, Convert__imm_95_12__RegCRRC1_1, 0, { MCK_bltlr, MCK_RegCRRC }, },
  { 1447 /* bltlr+ */, PPC::BCCLR, Convert__imm_95_15__regCR0, 0, { MCK_bltlr_43_ }, },
  { 1447 /* bltlr+ */, PPC::BCCLR, Convert__imm_95_15__RegCRRC1_1, 0, { MCK_bltlr_43_, MCK_RegCRRC }, },
  { 1454 /* bltlr- */, PPC::BCCLR, Convert__imm_95_14__regCR0, 0, { MCK_bltlr_MINUS_ }, },
  { 1454 /* bltlr- */, PPC::BCCLR, Convert__imm_95_14__RegCRRC1_1, 0, { MCK_bltlr_MINUS_, MCK_RegCRRC }, },
  { 1461 /* bltlrl */, PPC::BCCLRL, Convert__imm_95_12__regCR0, 0, { MCK_bltlrl }, },
  { 1461 /* bltlrl */, PPC::BCCLRL, Convert__imm_95_12__RegCRRC1_1, 0, { MCK_bltlrl, MCK_RegCRRC }, },
  { 1468 /* bltlrl+ */, PPC::BCCLRL, Convert__imm_95_15__regCR0, 0, { MCK_bltlrl_43_ }, },
  { 1468 /* bltlrl+ */, PPC::BCCLRL, Convert__imm_95_15__RegCRRC1_1, 0, { MCK_bltlrl_43_, MCK_RegCRRC }, },
  { 1476 /* bltlrl- */, PPC::BCCLRL, Convert__imm_95_14__regCR0, 0, { MCK_bltlrl_MINUS_ }, },
  { 1476 /* bltlrl- */, PPC::BCCLRL, Convert__imm_95_14__RegCRRC1_1, 0, { MCK_bltlrl_MINUS_, MCK_RegCRRC }, },
  { 1484 /* bne */, PPC::BCC, Convert__imm_95_68__regCR0__CondBr1_1, 0, { MCK_bne, MCK_CondBr }, },
  { 1484 /* bne */, PPC::BCC, Convert__imm_95_68__RegCRRC1_1__CondBr1_2, 0, { MCK_bne, MCK_RegCRRC, MCK_CondBr }, },
  { 1488 /* bne+ */, PPC::BCC, Convert__imm_95_71__regCR0__CondBr1_1, 0, { MCK_bne_43_, MCK_CondBr }, },
  { 1488 /* bne+ */, PPC::BCC, Convert__imm_95_71__RegCRRC1_1__CondBr1_2, 0, { MCK_bne_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1493 /* bne- */, PPC::BCC, Convert__imm_95_70__regCR0__CondBr1_1, 0, { MCK_bne_MINUS_, MCK_CondBr }, },
  { 1493 /* bne- */, PPC::BCC, Convert__imm_95_70__RegCRRC1_1__CondBr1_2, 0, { MCK_bne_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1498 /* bnea */, PPC::BCCA, Convert__imm_95_68__regCR0__CondBr1_1, 0, { MCK_bnea, MCK_CondBr }, },
  { 1498 /* bnea */, PPC::BCCA, Convert__imm_95_68__RegCRRC1_1__CondBr1_2, 0, { MCK_bnea, MCK_RegCRRC, MCK_CondBr }, },
  { 1503 /* bnea+ */, PPC::BCCA, Convert__imm_95_71__regCR0__CondBr1_1, 0, { MCK_bnea_43_, MCK_CondBr }, },
  { 1503 /* bnea+ */, PPC::BCCA, Convert__imm_95_71__RegCRRC1_1__CondBr1_2, 0, { MCK_bnea_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1509 /* bnea- */, PPC::BCCA, Convert__imm_95_70__regCR0__CondBr1_1, 0, { MCK_bnea_MINUS_, MCK_CondBr }, },
  { 1509 /* bnea- */, PPC::BCCA, Convert__imm_95_70__RegCRRC1_1__CondBr1_2, 0, { MCK_bnea_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1515 /* bnectr */, PPC::BCCCTR, Convert__imm_95_68__regCR0, 0, { MCK_bnectr }, },
  { 1515 /* bnectr */, PPC::BCCCTR, Convert__imm_95_68__RegCRRC1_1, 0, { MCK_bnectr, MCK_RegCRRC }, },
  { 1522 /* bnectr+ */, PPC::BCCCTR, Convert__imm_95_71__regCR0, 0, { MCK_bnectr_43_ }, },
  { 1522 /* bnectr+ */, PPC::BCCCTR, Convert__imm_95_71__RegCRRC1_1, 0, { MCK_bnectr_43_, MCK_RegCRRC }, },
  { 1530 /* bnectr- */, PPC::BCCCTR, Convert__imm_95_70__regCR0, 0, { MCK_bnectr_MINUS_ }, },
  { 1530 /* bnectr- */, PPC::BCCCTR, Convert__imm_95_70__RegCRRC1_1, 0, { MCK_bnectr_MINUS_, MCK_RegCRRC }, },
  { 1538 /* bnectrl */, PPC::BCCCTRL, Convert__imm_95_68__regCR0, 0, { MCK_bnectrl }, },
  { 1538 /* bnectrl */, PPC::BCCCTRL, Convert__imm_95_68__RegCRRC1_1, 0, { MCK_bnectrl, MCK_RegCRRC }, },
  { 1546 /* bnectrl+ */, PPC::BCCCTRL, Convert__imm_95_71__regCR0, 0, { MCK_bnectrl_43_ }, },
  { 1546 /* bnectrl+ */, PPC::BCCCTRL, Convert__imm_95_71__RegCRRC1_1, 0, { MCK_bnectrl_43_, MCK_RegCRRC }, },
  { 1555 /* bnectrl- */, PPC::BCCCTRL, Convert__imm_95_70__regCR0, 0, { MCK_bnectrl_MINUS_ }, },
  { 1555 /* bnectrl- */, PPC::BCCCTRL, Convert__imm_95_70__RegCRRC1_1, 0, { MCK_bnectrl_MINUS_, MCK_RegCRRC }, },
  { 1564 /* bnel */, PPC::BCCL, Convert__imm_95_68__regCR0__CondBr1_1, 0, { MCK_bnel, MCK_CondBr }, },
  { 1564 /* bnel */, PPC::BCCL, Convert__imm_95_68__RegCRRC1_1__CondBr1_2, 0, { MCK_bnel, MCK_RegCRRC, MCK_CondBr }, },
  { 1569 /* bnel+ */, PPC::BCCL, Convert__imm_95_71__regCR0__CondBr1_1, 0, { MCK_bnel_43_, MCK_CondBr }, },
  { 1569 /* bnel+ */, PPC::BCCL, Convert__imm_95_71__RegCRRC1_1__CondBr1_2, 0, { MCK_bnel_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1575 /* bnel- */, PPC::BCCL, Convert__imm_95_70__regCR0__CondBr1_1, 0, { MCK_bnel_MINUS_, MCK_CondBr }, },
  { 1575 /* bnel- */, PPC::BCCL, Convert__imm_95_70__RegCRRC1_1__CondBr1_2, 0, { MCK_bnel_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1581 /* bnela */, PPC::BCCLA, Convert__imm_95_68__regCR0__CondBr1_1, 0, { MCK_bnela, MCK_CondBr }, },
  { 1581 /* bnela */, PPC::BCCLA, Convert__imm_95_68__RegCRRC1_1__CondBr1_2, 0, { MCK_bnela, MCK_RegCRRC, MCK_CondBr }, },
  { 1587 /* bnela+ */, PPC::BCCLA, Convert__imm_95_71__regCR0__CondBr1_1, 0, { MCK_bnela_43_, MCK_CondBr }, },
  { 1587 /* bnela+ */, PPC::BCCLA, Convert__imm_95_71__RegCRRC1_1__CondBr1_2, 0, { MCK_bnela_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1594 /* bnela- */, PPC::BCCLA, Convert__imm_95_70__regCR0__CondBr1_1, 0, { MCK_bnela_MINUS_, MCK_CondBr }, },
  { 1594 /* bnela- */, PPC::BCCLA, Convert__imm_95_70__RegCRRC1_1__CondBr1_2, 0, { MCK_bnela_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1601 /* bnelr */, PPC::BCCLR, Convert__imm_95_68__regCR0, 0, { MCK_bnelr }, },
  { 1601 /* bnelr */, PPC::BCCLR, Convert__imm_95_68__RegCRRC1_1, 0, { MCK_bnelr, MCK_RegCRRC }, },
  { 1607 /* bnelr+ */, PPC::BCCLR, Convert__imm_95_71__regCR0, 0, { MCK_bnelr_43_ }, },
  { 1607 /* bnelr+ */, PPC::BCCLR, Convert__imm_95_71__RegCRRC1_1, 0, { MCK_bnelr_43_, MCK_RegCRRC }, },
  { 1614 /* bnelr- */, PPC::BCCLR, Convert__imm_95_70__regCR0, 0, { MCK_bnelr_MINUS_ }, },
  { 1614 /* bnelr- */, PPC::BCCLR, Convert__imm_95_70__RegCRRC1_1, 0, { MCK_bnelr_MINUS_, MCK_RegCRRC }, },
  { 1621 /* bnelrl */, PPC::BCCLRL, Convert__imm_95_68__regCR0, 0, { MCK_bnelrl }, },
  { 1621 /* bnelrl */, PPC::BCCLRL, Convert__imm_95_68__RegCRRC1_1, 0, { MCK_bnelrl, MCK_RegCRRC }, },
  { 1628 /* bnelrl+ */, PPC::BCCLRL, Convert__imm_95_71__regCR0, 0, { MCK_bnelrl_43_ }, },
  { 1628 /* bnelrl+ */, PPC::BCCLRL, Convert__imm_95_71__RegCRRC1_1, 0, { MCK_bnelrl_43_, MCK_RegCRRC }, },
  { 1636 /* bnelrl- */, PPC::BCCLRL, Convert__imm_95_70__regCR0, 0, { MCK_bnelrl_MINUS_ }, },
  { 1636 /* bnelrl- */, PPC::BCCLRL, Convert__imm_95_70__RegCRRC1_1, 0, { MCK_bnelrl_MINUS_, MCK_RegCRRC }, },
  { 1644 /* bng */, PPC::BCC, Convert__imm_95_36__regCR0__CondBr1_1, 0, { MCK_bng, MCK_CondBr }, },
  { 1644 /* bng */, PPC::BCC, Convert__imm_95_36__RegCRRC1_1__CondBr1_2, 0, { MCK_bng, MCK_RegCRRC, MCK_CondBr }, },
  { 1648 /* bng+ */, PPC::BCC, Convert__imm_95_39__regCR0__CondBr1_1, 0, { MCK_bng_43_, MCK_CondBr }, },
  { 1648 /* bng+ */, PPC::BCC, Convert__imm_95_39__RegCRRC1_1__CondBr1_2, 0, { MCK_bng_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1653 /* bng- */, PPC::BCC, Convert__imm_95_38__regCR0__CondBr1_1, 0, { MCK_bng_MINUS_, MCK_CondBr }, },
  { 1653 /* bng- */, PPC::BCC, Convert__imm_95_38__RegCRRC1_1__CondBr1_2, 0, { MCK_bng_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1658 /* bnga */, PPC::BCCA, Convert__imm_95_36__regCR0__CondBr1_1, 0, { MCK_bnga, MCK_CondBr }, },
  { 1658 /* bnga */, PPC::BCCA, Convert__imm_95_36__RegCRRC1_1__CondBr1_2, 0, { MCK_bnga, MCK_RegCRRC, MCK_CondBr }, },
  { 1663 /* bnga+ */, PPC::BCCA, Convert__imm_95_39__regCR0__CondBr1_1, 0, { MCK_bnga_43_, MCK_CondBr }, },
  { 1663 /* bnga+ */, PPC::BCCA, Convert__imm_95_39__RegCRRC1_1__CondBr1_2, 0, { MCK_bnga_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1669 /* bnga- */, PPC::BCCA, Convert__imm_95_38__regCR0__CondBr1_1, 0, { MCK_bnga_MINUS_, MCK_CondBr }, },
  { 1669 /* bnga- */, PPC::BCCA, Convert__imm_95_38__RegCRRC1_1__CondBr1_2, 0, { MCK_bnga_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1675 /* bngctr */, PPC::BCCCTR, Convert__imm_95_36__regCR0, 0, { MCK_bngctr }, },
  { 1675 /* bngctr */, PPC::BCCCTR, Convert__imm_95_36__RegCRRC1_1, 0, { MCK_bngctr, MCK_RegCRRC }, },
  { 1682 /* bngctr+ */, PPC::BCCCTR, Convert__imm_95_39__regCR0, 0, { MCK_bngctr_43_ }, },
  { 1682 /* bngctr+ */, PPC::BCCCTR, Convert__imm_95_39__RegCRRC1_1, 0, { MCK_bngctr_43_, MCK_RegCRRC }, },
  { 1690 /* bngctr- */, PPC::BCCCTR, Convert__imm_95_38__regCR0, 0, { MCK_bngctr_MINUS_ }, },
  { 1690 /* bngctr- */, PPC::BCCCTR, Convert__imm_95_38__RegCRRC1_1, 0, { MCK_bngctr_MINUS_, MCK_RegCRRC }, },
  { 1698 /* bngctrl */, PPC::BCCCTRL, Convert__imm_95_36__regCR0, 0, { MCK_bngctrl }, },
  { 1698 /* bngctrl */, PPC::BCCCTRL, Convert__imm_95_36__RegCRRC1_1, 0, { MCK_bngctrl, MCK_RegCRRC }, },
  { 1706 /* bngctrl+ */, PPC::BCCCTRL, Convert__imm_95_39__regCR0, 0, { MCK_bngctrl_43_ }, },
  { 1706 /* bngctrl+ */, PPC::BCCCTRL, Convert__imm_95_39__RegCRRC1_1, 0, { MCK_bngctrl_43_, MCK_RegCRRC }, },
  { 1715 /* bngctrl- */, PPC::BCCCTRL, Convert__imm_95_38__regCR0, 0, { MCK_bngctrl_MINUS_ }, },
  { 1715 /* bngctrl- */, PPC::BCCCTRL, Convert__imm_95_38__RegCRRC1_1, 0, { MCK_bngctrl_MINUS_, MCK_RegCRRC }, },
  { 1724 /* bngl */, PPC::BCCL, Convert__imm_95_36__regCR0__CondBr1_1, 0, { MCK_bngl, MCK_CondBr }, },
  { 1724 /* bngl */, PPC::BCCL, Convert__imm_95_36__RegCRRC1_1__CondBr1_2, 0, { MCK_bngl, MCK_RegCRRC, MCK_CondBr }, },
  { 1729 /* bngl+ */, PPC::BCCL, Convert__imm_95_39__regCR0__CondBr1_1, 0, { MCK_bngl_43_, MCK_CondBr }, },
  { 1729 /* bngl+ */, PPC::BCCL, Convert__imm_95_39__RegCRRC1_1__CondBr1_2, 0, { MCK_bngl_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1735 /* bngl- */, PPC::BCCL, Convert__imm_95_38__regCR0__CondBr1_1, 0, { MCK_bngl_MINUS_, MCK_CondBr }, },
  { 1735 /* bngl- */, PPC::BCCL, Convert__imm_95_38__RegCRRC1_1__CondBr1_2, 0, { MCK_bngl_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1741 /* bngla */, PPC::BCCLA, Convert__imm_95_36__regCR0__CondBr1_1, 0, { MCK_bngla, MCK_CondBr }, },
  { 1741 /* bngla */, PPC::BCCLA, Convert__imm_95_36__RegCRRC1_1__CondBr1_2, 0, { MCK_bngla, MCK_RegCRRC, MCK_CondBr }, },
  { 1747 /* bngla+ */, PPC::BCCLA, Convert__imm_95_39__regCR0__CondBr1_1, 0, { MCK_bngla_43_, MCK_CondBr }, },
  { 1747 /* bngla+ */, PPC::BCCLA, Convert__imm_95_39__RegCRRC1_1__CondBr1_2, 0, { MCK_bngla_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1754 /* bngla- */, PPC::BCCLA, Convert__imm_95_38__regCR0__CondBr1_1, 0, { MCK_bngla_MINUS_, MCK_CondBr }, },
  { 1754 /* bngla- */, PPC::BCCLA, Convert__imm_95_38__RegCRRC1_1__CondBr1_2, 0, { MCK_bngla_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1761 /* bnglr */, PPC::BCCLR, Convert__imm_95_36__regCR0, 0, { MCK_bnglr }, },
  { 1761 /* bnglr */, PPC::BCCLR, Convert__imm_95_36__RegCRRC1_1, 0, { MCK_bnglr, MCK_RegCRRC }, },
  { 1767 /* bnglr+ */, PPC::BCCLR, Convert__imm_95_39__regCR0, 0, { MCK_bnglr_43_ }, },
  { 1767 /* bnglr+ */, PPC::BCCLR, Convert__imm_95_39__RegCRRC1_1, 0, { MCK_bnglr_43_, MCK_RegCRRC }, },
  { 1774 /* bnglr- */, PPC::BCCLR, Convert__imm_95_38__regCR0, 0, { MCK_bnglr_MINUS_ }, },
  { 1774 /* bnglr- */, PPC::BCCLR, Convert__imm_95_38__RegCRRC1_1, 0, { MCK_bnglr_MINUS_, MCK_RegCRRC }, },
  { 1781 /* bnglrl */, PPC::BCCLRL, Convert__imm_95_36__regCR0, 0, { MCK_bnglrl }, },
  { 1781 /* bnglrl */, PPC::BCCLRL, Convert__imm_95_36__RegCRRC1_1, 0, { MCK_bnglrl, MCK_RegCRRC }, },
  { 1788 /* bnglrl+ */, PPC::BCCLRL, Convert__imm_95_39__regCR0, 0, { MCK_bnglrl_43_ }, },
  { 1788 /* bnglrl+ */, PPC::BCCLRL, Convert__imm_95_39__RegCRRC1_1, 0, { MCK_bnglrl_43_, MCK_RegCRRC }, },
  { 1796 /* bnglrl- */, PPC::BCCLRL, Convert__imm_95_38__regCR0, 0, { MCK_bnglrl_MINUS_ }, },
  { 1796 /* bnglrl- */, PPC::BCCLRL, Convert__imm_95_38__RegCRRC1_1, 0, { MCK_bnglrl_MINUS_, MCK_RegCRRC }, },
  { 1804 /* bnl */, PPC::BCC, Convert__imm_95_4__regCR0__CondBr1_1, 0, { MCK_bnl, MCK_CondBr }, },
  { 1804 /* bnl */, PPC::BCC, Convert__imm_95_4__RegCRRC1_1__CondBr1_2, 0, { MCK_bnl, MCK_RegCRRC, MCK_CondBr }, },
  { 1808 /* bnl+ */, PPC::BCC, Convert__imm_95_7__regCR0__CondBr1_1, 0, { MCK_bnl_43_, MCK_CondBr }, },
  { 1808 /* bnl+ */, PPC::BCC, Convert__imm_95_7__RegCRRC1_1__CondBr1_2, 0, { MCK_bnl_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1813 /* bnl- */, PPC::BCC, Convert__imm_95_6__regCR0__CondBr1_1, 0, { MCK_bnl_MINUS_, MCK_CondBr }, },
  { 1813 /* bnl- */, PPC::BCC, Convert__imm_95_6__RegCRRC1_1__CondBr1_2, 0, { MCK_bnl_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1818 /* bnla */, PPC::BCCA, Convert__imm_95_4__regCR0__CondBr1_1, 0, { MCK_bnla, MCK_CondBr }, },
  { 1818 /* bnla */, PPC::BCCA, Convert__imm_95_4__RegCRRC1_1__CondBr1_2, 0, { MCK_bnla, MCK_RegCRRC, MCK_CondBr }, },
  { 1823 /* bnla+ */, PPC::BCCA, Convert__imm_95_7__regCR0__CondBr1_1, 0, { MCK_bnla_43_, MCK_CondBr }, },
  { 1823 /* bnla+ */, PPC::BCCA, Convert__imm_95_7__RegCRRC1_1__CondBr1_2, 0, { MCK_bnla_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1829 /* bnla- */, PPC::BCCA, Convert__imm_95_6__regCR0__CondBr1_1, 0, { MCK_bnla_MINUS_, MCK_CondBr }, },
  { 1829 /* bnla- */, PPC::BCCA, Convert__imm_95_6__RegCRRC1_1__CondBr1_2, 0, { MCK_bnla_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1835 /* bnlctr */, PPC::BCCCTR, Convert__imm_95_4__regCR0, 0, { MCK_bnlctr }, },
  { 1835 /* bnlctr */, PPC::BCCCTR, Convert__imm_95_4__RegCRRC1_1, 0, { MCK_bnlctr, MCK_RegCRRC }, },
  { 1842 /* bnlctr+ */, PPC::BCCCTR, Convert__imm_95_7__regCR0, 0, { MCK_bnlctr_43_ }, },
  { 1842 /* bnlctr+ */, PPC::BCCCTR, Convert__imm_95_7__RegCRRC1_1, 0, { MCK_bnlctr_43_, MCK_RegCRRC }, },
  { 1850 /* bnlctr- */, PPC::BCCCTR, Convert__imm_95_6__regCR0, 0, { MCK_bnlctr_MINUS_ }, },
  { 1850 /* bnlctr- */, PPC::BCCCTR, Convert__imm_95_6__RegCRRC1_1, 0, { MCK_bnlctr_MINUS_, MCK_RegCRRC }, },
  { 1858 /* bnlctrl */, PPC::BCCCTRL, Convert__imm_95_4__regCR0, 0, { MCK_bnlctrl }, },
  { 1858 /* bnlctrl */, PPC::BCCCTRL, Convert__imm_95_4__RegCRRC1_1, 0, { MCK_bnlctrl, MCK_RegCRRC }, },
  { 1866 /* bnlctrl+ */, PPC::BCCCTRL, Convert__imm_95_7__regCR0, 0, { MCK_bnlctrl_43_ }, },
  { 1866 /* bnlctrl+ */, PPC::BCCCTRL, Convert__imm_95_7__RegCRRC1_1, 0, { MCK_bnlctrl_43_, MCK_RegCRRC }, },
  { 1875 /* bnlctrl- */, PPC::BCCCTRL, Convert__imm_95_6__regCR0, 0, { MCK_bnlctrl_MINUS_ }, },
  { 1875 /* bnlctrl- */, PPC::BCCCTRL, Convert__imm_95_6__RegCRRC1_1, 0, { MCK_bnlctrl_MINUS_, MCK_RegCRRC }, },
  { 1884 /* bnll */, PPC::BCCL, Convert__imm_95_4__regCR0__CondBr1_1, 0, { MCK_bnll, MCK_CondBr }, },
  { 1884 /* bnll */, PPC::BCCL, Convert__imm_95_4__RegCRRC1_1__CondBr1_2, 0, { MCK_bnll, MCK_RegCRRC, MCK_CondBr }, },
  { 1889 /* bnll+ */, PPC::BCCL, Convert__imm_95_7__regCR0__CondBr1_1, 0, { MCK_bnll_43_, MCK_CondBr }, },
  { 1889 /* bnll+ */, PPC::BCCL, Convert__imm_95_7__RegCRRC1_1__CondBr1_2, 0, { MCK_bnll_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1895 /* bnll- */, PPC::BCCL, Convert__imm_95_6__regCR0__CondBr1_1, 0, { MCK_bnll_MINUS_, MCK_CondBr }, },
  { 1895 /* bnll- */, PPC::BCCL, Convert__imm_95_6__RegCRRC1_1__CondBr1_2, 0, { MCK_bnll_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1901 /* bnlla */, PPC::BCCLA, Convert__imm_95_4__regCR0__CondBr1_1, 0, { MCK_bnlla, MCK_CondBr }, },
  { 1901 /* bnlla */, PPC::BCCLA, Convert__imm_95_4__RegCRRC1_1__CondBr1_2, 0, { MCK_bnlla, MCK_RegCRRC, MCK_CondBr }, },
  { 1907 /* bnlla+ */, PPC::BCCLA, Convert__imm_95_7__regCR0__CondBr1_1, 0, { MCK_bnlla_43_, MCK_CondBr }, },
  { 1907 /* bnlla+ */, PPC::BCCLA, Convert__imm_95_7__RegCRRC1_1__CondBr1_2, 0, { MCK_bnlla_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1914 /* bnlla- */, PPC::BCCLA, Convert__imm_95_6__regCR0__CondBr1_1, 0, { MCK_bnlla_MINUS_, MCK_CondBr }, },
  { 1914 /* bnlla- */, PPC::BCCLA, Convert__imm_95_6__RegCRRC1_1__CondBr1_2, 0, { MCK_bnlla_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1921 /* bnllr */, PPC::BCCLR, Convert__imm_95_4__regCR0, 0, { MCK_bnllr }, },
  { 1921 /* bnllr */, PPC::BCCLR, Convert__imm_95_4__RegCRRC1_1, 0, { MCK_bnllr, MCK_RegCRRC }, },
  { 1927 /* bnllr+ */, PPC::BCCLR, Convert__imm_95_7__regCR0, 0, { MCK_bnllr_43_ }, },
  { 1927 /* bnllr+ */, PPC::BCCLR, Convert__imm_95_7__RegCRRC1_1, 0, { MCK_bnllr_43_, MCK_RegCRRC }, },
  { 1934 /* bnllr- */, PPC::BCCLR, Convert__imm_95_6__regCR0, 0, { MCK_bnllr_MINUS_ }, },
  { 1934 /* bnllr- */, PPC::BCCLR, Convert__imm_95_6__RegCRRC1_1, 0, { MCK_bnllr_MINUS_, MCK_RegCRRC }, },
  { 1941 /* bnllrl */, PPC::BCCLRL, Convert__imm_95_4__regCR0, 0, { MCK_bnllrl }, },
  { 1941 /* bnllrl */, PPC::BCCLRL, Convert__imm_95_4__RegCRRC1_1, 0, { MCK_bnllrl, MCK_RegCRRC }, },
  { 1948 /* bnllrl+ */, PPC::BCCLRL, Convert__imm_95_7__regCR0, 0, { MCK_bnllrl_43_ }, },
  { 1948 /* bnllrl+ */, PPC::BCCLRL, Convert__imm_95_7__RegCRRC1_1, 0, { MCK_bnllrl_43_, MCK_RegCRRC }, },
  { 1956 /* bnllrl- */, PPC::BCCLRL, Convert__imm_95_6__regCR0, 0, { MCK_bnllrl_MINUS_ }, },
  { 1956 /* bnllrl- */, PPC::BCCLRL, Convert__imm_95_6__RegCRRC1_1, 0, { MCK_bnllrl_MINUS_, MCK_RegCRRC }, },
  { 1964 /* bns */, PPC::BCC, Convert__imm_95_100__regCR0__CondBr1_1, 0, { MCK_bns, MCK_CondBr }, },
  { 1964 /* bns */, PPC::BCC, Convert__imm_95_100__RegCRRC1_1__CondBr1_2, 0, { MCK_bns, MCK_RegCRRC, MCK_CondBr }, },
  { 1968 /* bns+ */, PPC::BCC, Convert__imm_95_103__regCR0__CondBr1_1, 0, { MCK_bns_43_, MCK_CondBr }, },
  { 1968 /* bns+ */, PPC::BCC, Convert__imm_95_103__RegCRRC1_1__CondBr1_2, 0, { MCK_bns_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1973 /* bns- */, PPC::BCC, Convert__imm_95_102__regCR0__CondBr1_1, 0, { MCK_bns_MINUS_, MCK_CondBr }, },
  { 1973 /* bns- */, PPC::BCC, Convert__imm_95_102__RegCRRC1_1__CondBr1_2, 0, { MCK_bns_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1978 /* bnsa */, PPC::BCCA, Convert__imm_95_100__regCR0__CondBr1_1, 0, { MCK_bnsa, MCK_CondBr }, },
  { 1978 /* bnsa */, PPC::BCCA, Convert__imm_95_100__RegCRRC1_1__CondBr1_2, 0, { MCK_bnsa, MCK_RegCRRC, MCK_CondBr }, },
  { 1983 /* bnsa+ */, PPC::BCCA, Convert__imm_95_103__regCR0__CondBr1_1, 0, { MCK_bnsa_43_, MCK_CondBr }, },
  { 1983 /* bnsa+ */, PPC::BCCA, Convert__imm_95_103__RegCRRC1_1__CondBr1_2, 0, { MCK_bnsa_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 1989 /* bnsa- */, PPC::BCCA, Convert__imm_95_102__regCR0__CondBr1_1, 0, { MCK_bnsa_MINUS_, MCK_CondBr }, },
  { 1989 /* bnsa- */, PPC::BCCA, Convert__imm_95_102__RegCRRC1_1__CondBr1_2, 0, { MCK_bnsa_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 1995 /* bnsctr */, PPC::BCCCTR, Convert__imm_95_100__regCR0, 0, { MCK_bnsctr }, },
  { 1995 /* bnsctr */, PPC::BCCCTR, Convert__imm_95_100__RegCRRC1_1, 0, { MCK_bnsctr, MCK_RegCRRC }, },
  { 2002 /* bnsctr+ */, PPC::BCCCTR, Convert__imm_95_103__regCR0, 0, { MCK_bnsctr_43_ }, },
  { 2002 /* bnsctr+ */, PPC::BCCCTR, Convert__imm_95_103__RegCRRC1_1, 0, { MCK_bnsctr_43_, MCK_RegCRRC }, },
  { 2010 /* bnsctr- */, PPC::BCCCTR, Convert__imm_95_102__regCR0, 0, { MCK_bnsctr_MINUS_ }, },
  { 2010 /* bnsctr- */, PPC::BCCCTR, Convert__imm_95_102__RegCRRC1_1, 0, { MCK_bnsctr_MINUS_, MCK_RegCRRC }, },
  { 2018 /* bnsctrl */, PPC::BCCCTRL, Convert__imm_95_100__regCR0, 0, { MCK_bnsctrl }, },
  { 2018 /* bnsctrl */, PPC::BCCCTRL, Convert__imm_95_100__RegCRRC1_1, 0, { MCK_bnsctrl, MCK_RegCRRC }, },
  { 2026 /* bnsctrl+ */, PPC::BCCCTRL, Convert__imm_95_103__regCR0, 0, { MCK_bnsctrl_43_ }, },
  { 2026 /* bnsctrl+ */, PPC::BCCCTRL, Convert__imm_95_103__RegCRRC1_1, 0, { MCK_bnsctrl_43_, MCK_RegCRRC }, },
  { 2035 /* bnsctrl- */, PPC::BCCCTRL, Convert__imm_95_102__regCR0, 0, { MCK_bnsctrl_MINUS_ }, },
  { 2035 /* bnsctrl- */, PPC::BCCCTRL, Convert__imm_95_102__RegCRRC1_1, 0, { MCK_bnsctrl_MINUS_, MCK_RegCRRC }, },
  { 2044 /* bnsl */, PPC::BCCL, Convert__imm_95_100__regCR0__CondBr1_1, 0, { MCK_bnsl, MCK_CondBr }, },
  { 2044 /* bnsl */, PPC::BCCL, Convert__imm_95_100__RegCRRC1_1__CondBr1_2, 0, { MCK_bnsl, MCK_RegCRRC, MCK_CondBr }, },
  { 2049 /* bnsl+ */, PPC::BCCL, Convert__imm_95_103__regCR0__CondBr1_1, 0, { MCK_bnsl_43_, MCK_CondBr }, },
  { 2049 /* bnsl+ */, PPC::BCCL, Convert__imm_95_103__RegCRRC1_1__CondBr1_2, 0, { MCK_bnsl_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2055 /* bnsl- */, PPC::BCCL, Convert__imm_95_102__regCR0__CondBr1_1, 0, { MCK_bnsl_MINUS_, MCK_CondBr }, },
  { 2055 /* bnsl- */, PPC::BCCL, Convert__imm_95_102__RegCRRC1_1__CondBr1_2, 0, { MCK_bnsl_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2061 /* bnsla */, PPC::BCCLA, Convert__imm_95_100__regCR0__CondBr1_1, 0, { MCK_bnsla, MCK_CondBr }, },
  { 2061 /* bnsla */, PPC::BCCLA, Convert__imm_95_100__RegCRRC1_1__CondBr1_2, 0, { MCK_bnsla, MCK_RegCRRC, MCK_CondBr }, },
  { 2067 /* bnsla+ */, PPC::BCCLA, Convert__imm_95_103__regCR0__CondBr1_1, 0, { MCK_bnsla_43_, MCK_CondBr }, },
  { 2067 /* bnsla+ */, PPC::BCCLA, Convert__imm_95_103__RegCRRC1_1__CondBr1_2, 0, { MCK_bnsla_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2074 /* bnsla- */, PPC::BCCLA, Convert__imm_95_102__regCR0__CondBr1_1, 0, { MCK_bnsla_MINUS_, MCK_CondBr }, },
  { 2074 /* bnsla- */, PPC::BCCLA, Convert__imm_95_102__RegCRRC1_1__CondBr1_2, 0, { MCK_bnsla_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2081 /* bnslr */, PPC::BCCLR, Convert__imm_95_100__regCR0, 0, { MCK_bnslr }, },
  { 2081 /* bnslr */, PPC::BCCLR, Convert__imm_95_100__RegCRRC1_1, 0, { MCK_bnslr, MCK_RegCRRC }, },
  { 2087 /* bnslr+ */, PPC::BCCLR, Convert__imm_95_103__regCR0, 0, { MCK_bnslr_43_ }, },
  { 2087 /* bnslr+ */, PPC::BCCLR, Convert__imm_95_103__RegCRRC1_1, 0, { MCK_bnslr_43_, MCK_RegCRRC }, },
  { 2094 /* bnslr- */, PPC::BCCLR, Convert__imm_95_102__regCR0, 0, { MCK_bnslr_MINUS_ }, },
  { 2094 /* bnslr- */, PPC::BCCLR, Convert__imm_95_102__RegCRRC1_1, 0, { MCK_bnslr_MINUS_, MCK_RegCRRC }, },
  { 2101 /* bnslrl */, PPC::BCCLRL, Convert__imm_95_100__regCR0, 0, { MCK_bnslrl }, },
  { 2101 /* bnslrl */, PPC::BCCLRL, Convert__imm_95_100__RegCRRC1_1, 0, { MCK_bnslrl, MCK_RegCRRC }, },
  { 2108 /* bnslrl+ */, PPC::BCCLRL, Convert__imm_95_103__regCR0, 0, { MCK_bnslrl_43_ }, },
  { 2108 /* bnslrl+ */, PPC::BCCLRL, Convert__imm_95_103__RegCRRC1_1, 0, { MCK_bnslrl_43_, MCK_RegCRRC }, },
  { 2116 /* bnslrl- */, PPC::BCCLRL, Convert__imm_95_102__regCR0, 0, { MCK_bnslrl_MINUS_ }, },
  { 2116 /* bnslrl- */, PPC::BCCLRL, Convert__imm_95_102__RegCRRC1_1, 0, { MCK_bnslrl_MINUS_, MCK_RegCRRC }, },
  { 2124 /* bnu */, PPC::BCC, Convert__imm_95_100__regCR0__CondBr1_1, 0, { MCK_bnu, MCK_CondBr }, },
  { 2124 /* bnu */, PPC::BCC, Convert__imm_95_100__RegCRRC1_1__CondBr1_2, 0, { MCK_bnu, MCK_RegCRRC, MCK_CondBr }, },
  { 2128 /* bnu+ */, PPC::BCC, Convert__imm_95_103__regCR0__CondBr1_1, 0, { MCK_bnu_43_, MCK_CondBr }, },
  { 2128 /* bnu+ */, PPC::BCC, Convert__imm_95_103__RegCRRC1_1__CondBr1_2, 0, { MCK_bnu_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2133 /* bnu- */, PPC::BCC, Convert__imm_95_102__regCR0__CondBr1_1, 0, { MCK_bnu_MINUS_, MCK_CondBr }, },
  { 2133 /* bnu- */, PPC::BCC, Convert__imm_95_102__RegCRRC1_1__CondBr1_2, 0, { MCK_bnu_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2138 /* bnua */, PPC::BCCA, Convert__imm_95_100__regCR0__CondBr1_1, 0, { MCK_bnua, MCK_CondBr }, },
  { 2138 /* bnua */, PPC::BCCA, Convert__imm_95_100__RegCRRC1_1__CondBr1_2, 0, { MCK_bnua, MCK_RegCRRC, MCK_CondBr }, },
  { 2143 /* bnua+ */, PPC::BCCA, Convert__imm_95_103__regCR0__CondBr1_1, 0, { MCK_bnua_43_, MCK_CondBr }, },
  { 2143 /* bnua+ */, PPC::BCCA, Convert__imm_95_103__RegCRRC1_1__CondBr1_2, 0, { MCK_bnua_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2149 /* bnua- */, PPC::BCCA, Convert__imm_95_102__regCR0__CondBr1_1, 0, { MCK_bnua_MINUS_, MCK_CondBr }, },
  { 2149 /* bnua- */, PPC::BCCA, Convert__imm_95_102__RegCRRC1_1__CondBr1_2, 0, { MCK_bnua_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2155 /* bnuctr */, PPC::BCCCTR, Convert__imm_95_100__regCR0, 0, { MCK_bnuctr }, },
  { 2155 /* bnuctr */, PPC::BCCCTR, Convert__imm_95_100__RegCRRC1_1, 0, { MCK_bnuctr, MCK_RegCRRC }, },
  { 2162 /* bnuctr+ */, PPC::BCCCTR, Convert__imm_95_103__regCR0, 0, { MCK_bnuctr_43_ }, },
  { 2162 /* bnuctr+ */, PPC::BCCCTR, Convert__imm_95_103__RegCRRC1_1, 0, { MCK_bnuctr_43_, MCK_RegCRRC }, },
  { 2170 /* bnuctr- */, PPC::BCCCTR, Convert__imm_95_102__regCR0, 0, { MCK_bnuctr_MINUS_ }, },
  { 2170 /* bnuctr- */, PPC::BCCCTR, Convert__imm_95_102__RegCRRC1_1, 0, { MCK_bnuctr_MINUS_, MCK_RegCRRC }, },
  { 2178 /* bnuctrl */, PPC::BCCCTRL, Convert__imm_95_100__regCR0, 0, { MCK_bnuctrl }, },
  { 2178 /* bnuctrl */, PPC::BCCCTRL, Convert__imm_95_100__RegCRRC1_1, 0, { MCK_bnuctrl, MCK_RegCRRC }, },
  { 2186 /* bnuctrl+ */, PPC::BCCCTRL, Convert__imm_95_103__regCR0, 0, { MCK_bnuctrl_43_ }, },
  { 2186 /* bnuctrl+ */, PPC::BCCCTRL, Convert__imm_95_103__RegCRRC1_1, 0, { MCK_bnuctrl_43_, MCK_RegCRRC }, },
  { 2195 /* bnuctrl- */, PPC::BCCCTRL, Convert__imm_95_102__regCR0, 0, { MCK_bnuctrl_MINUS_ }, },
  { 2195 /* bnuctrl- */, PPC::BCCCTRL, Convert__imm_95_102__RegCRRC1_1, 0, { MCK_bnuctrl_MINUS_, MCK_RegCRRC }, },
  { 2204 /* bnul */, PPC::BCCL, Convert__imm_95_100__regCR0__CondBr1_1, 0, { MCK_bnul, MCK_CondBr }, },
  { 2204 /* bnul */, PPC::BCCL, Convert__imm_95_100__RegCRRC1_1__CondBr1_2, 0, { MCK_bnul, MCK_RegCRRC, MCK_CondBr }, },
  { 2209 /* bnul+ */, PPC::BCCL, Convert__imm_95_103__regCR0__CondBr1_1, 0, { MCK_bnul_43_, MCK_CondBr }, },
  { 2209 /* bnul+ */, PPC::BCCL, Convert__imm_95_103__RegCRRC1_1__CondBr1_2, 0, { MCK_bnul_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2215 /* bnul- */, PPC::BCCL, Convert__imm_95_102__regCR0__CondBr1_1, 0, { MCK_bnul_MINUS_, MCK_CondBr }, },
  { 2215 /* bnul- */, PPC::BCCL, Convert__imm_95_102__RegCRRC1_1__CondBr1_2, 0, { MCK_bnul_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2221 /* bnula */, PPC::BCCLA, Convert__imm_95_100__regCR0__CondBr1_1, 0, { MCK_bnula, MCK_CondBr }, },
  { 2221 /* bnula */, PPC::BCCLA, Convert__imm_95_100__RegCRRC1_1__CondBr1_2, 0, { MCK_bnula, MCK_RegCRRC, MCK_CondBr }, },
  { 2227 /* bnula+ */, PPC::BCCLA, Convert__imm_95_103__regCR0__CondBr1_1, 0, { MCK_bnula_43_, MCK_CondBr }, },
  { 2227 /* bnula+ */, PPC::BCCLA, Convert__imm_95_103__RegCRRC1_1__CondBr1_2, 0, { MCK_bnula_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2234 /* bnula- */, PPC::BCCLA, Convert__imm_95_102__regCR0__CondBr1_1, 0, { MCK_bnula_MINUS_, MCK_CondBr }, },
  { 2234 /* bnula- */, PPC::BCCLA, Convert__imm_95_102__RegCRRC1_1__CondBr1_2, 0, { MCK_bnula_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2241 /* bnulr */, PPC::BCCLR, Convert__imm_95_100__regCR0, 0, { MCK_bnulr }, },
  { 2241 /* bnulr */, PPC::BCCLR, Convert__imm_95_100__RegCRRC1_1, 0, { MCK_bnulr, MCK_RegCRRC }, },
  { 2247 /* bnulr+ */, PPC::BCCLR, Convert__imm_95_103__regCR0, 0, { MCK_bnulr_43_ }, },
  { 2247 /* bnulr+ */, PPC::BCCLR, Convert__imm_95_103__RegCRRC1_1, 0, { MCK_bnulr_43_, MCK_RegCRRC }, },
  { 2254 /* bnulr- */, PPC::BCCLR, Convert__imm_95_102__regCR0, 0, { MCK_bnulr_MINUS_ }, },
  { 2254 /* bnulr- */, PPC::BCCLR, Convert__imm_95_102__RegCRRC1_1, 0, { MCK_bnulr_MINUS_, MCK_RegCRRC }, },
  { 2261 /* bnulrl */, PPC::BCCLRL, Convert__imm_95_100__regCR0, 0, { MCK_bnulrl }, },
  { 2261 /* bnulrl */, PPC::BCCLRL, Convert__imm_95_100__RegCRRC1_1, 0, { MCK_bnulrl, MCK_RegCRRC }, },
  { 2268 /* bnulrl+ */, PPC::BCCLRL, Convert__imm_95_103__regCR0, 0, { MCK_bnulrl_43_ }, },
  { 2268 /* bnulrl+ */, PPC::BCCLRL, Convert__imm_95_103__RegCRRC1_1, 0, { MCK_bnulrl_43_, MCK_RegCRRC }, },
  { 2276 /* bnulrl- */, PPC::BCCLRL, Convert__imm_95_102__regCR0, 0, { MCK_bnulrl_MINUS_ }, },
  { 2276 /* bnulrl- */, PPC::BCCLRL, Convert__imm_95_102__RegCRRC1_1, 0, { MCK_bnulrl_MINUS_, MCK_RegCRRC }, },
  { 2284 /* bpermd */, PPC::BPERMD, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_bpermd, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2291 /* brinc */, PPC::BRINC, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_brinc, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2297 /* bso */, PPC::BCC, Convert__imm_95_108__regCR0__CondBr1_1, 0, { MCK_bso, MCK_CondBr }, },
  { 2297 /* bso */, PPC::BCC, Convert__imm_95_108__RegCRRC1_1__CondBr1_2, 0, { MCK_bso, MCK_RegCRRC, MCK_CondBr }, },
  { 2301 /* bso+ */, PPC::BCC, Convert__imm_95_111__regCR0__CondBr1_1, 0, { MCK_bso_43_, MCK_CondBr }, },
  { 2301 /* bso+ */, PPC::BCC, Convert__imm_95_111__RegCRRC1_1__CondBr1_2, 0, { MCK_bso_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2306 /* bso- */, PPC::BCC, Convert__imm_95_110__regCR0__CondBr1_1, 0, { MCK_bso_MINUS_, MCK_CondBr }, },
  { 2306 /* bso- */, PPC::BCC, Convert__imm_95_110__RegCRRC1_1__CondBr1_2, 0, { MCK_bso_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2311 /* bsoa */, PPC::BCCA, Convert__imm_95_108__regCR0__CondBr1_1, 0, { MCK_bsoa, MCK_CondBr }, },
  { 2311 /* bsoa */, PPC::BCCA, Convert__imm_95_108__RegCRRC1_1__CondBr1_2, 0, { MCK_bsoa, MCK_RegCRRC, MCK_CondBr }, },
  { 2316 /* bsoa+ */, PPC::BCCA, Convert__imm_95_111__regCR0__CondBr1_1, 0, { MCK_bsoa_43_, MCK_CondBr }, },
  { 2316 /* bsoa+ */, PPC::BCCA, Convert__imm_95_111__RegCRRC1_1__CondBr1_2, 0, { MCK_bsoa_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2322 /* bsoa- */, PPC::BCCA, Convert__imm_95_110__regCR0__CondBr1_1, 0, { MCK_bsoa_MINUS_, MCK_CondBr }, },
  { 2322 /* bsoa- */, PPC::BCCA, Convert__imm_95_110__RegCRRC1_1__CondBr1_2, 0, { MCK_bsoa_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2328 /* bsoctr */, PPC::BCCCTR, Convert__imm_95_108__regCR0, 0, { MCK_bsoctr }, },
  { 2328 /* bsoctr */, PPC::BCCCTR, Convert__imm_95_108__RegCRRC1_1, 0, { MCK_bsoctr, MCK_RegCRRC }, },
  { 2335 /* bsoctr+ */, PPC::BCCCTR, Convert__imm_95_111__regCR0, 0, { MCK_bsoctr_43_ }, },
  { 2335 /* bsoctr+ */, PPC::BCCCTR, Convert__imm_95_111__RegCRRC1_1, 0, { MCK_bsoctr_43_, MCK_RegCRRC }, },
  { 2343 /* bsoctr- */, PPC::BCCCTR, Convert__imm_95_110__regCR0, 0, { MCK_bsoctr_MINUS_ }, },
  { 2343 /* bsoctr- */, PPC::BCCCTR, Convert__imm_95_110__RegCRRC1_1, 0, { MCK_bsoctr_MINUS_, MCK_RegCRRC }, },
  { 2351 /* bsoctrl */, PPC::BCCCTRL, Convert__imm_95_108__regCR0, 0, { MCK_bsoctrl }, },
  { 2351 /* bsoctrl */, PPC::BCCCTRL, Convert__imm_95_108__RegCRRC1_1, 0, { MCK_bsoctrl, MCK_RegCRRC }, },
  { 2359 /* bsoctrl+ */, PPC::BCCCTRL, Convert__imm_95_111__regCR0, 0, { MCK_bsoctrl_43_ }, },
  { 2359 /* bsoctrl+ */, PPC::BCCCTRL, Convert__imm_95_111__RegCRRC1_1, 0, { MCK_bsoctrl_43_, MCK_RegCRRC }, },
  { 2368 /* bsoctrl- */, PPC::BCCCTRL, Convert__imm_95_110__regCR0, 0, { MCK_bsoctrl_MINUS_ }, },
  { 2368 /* bsoctrl- */, PPC::BCCCTRL, Convert__imm_95_110__RegCRRC1_1, 0, { MCK_bsoctrl_MINUS_, MCK_RegCRRC }, },
  { 2377 /* bsol */, PPC::BCCL, Convert__imm_95_108__regCR0__CondBr1_1, 0, { MCK_bsol, MCK_CondBr }, },
  { 2377 /* bsol */, PPC::BCCL, Convert__imm_95_108__RegCRRC1_1__CondBr1_2, 0, { MCK_bsol, MCK_RegCRRC, MCK_CondBr }, },
  { 2382 /* bsol+ */, PPC::BCCL, Convert__imm_95_111__regCR0__CondBr1_1, 0, { MCK_bsol_43_, MCK_CondBr }, },
  { 2382 /* bsol+ */, PPC::BCCL, Convert__imm_95_111__RegCRRC1_1__CondBr1_2, 0, { MCK_bsol_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2388 /* bsol- */, PPC::BCCL, Convert__imm_95_110__regCR0__CondBr1_1, 0, { MCK_bsol_MINUS_, MCK_CondBr }, },
  { 2388 /* bsol- */, PPC::BCCL, Convert__imm_95_110__RegCRRC1_1__CondBr1_2, 0, { MCK_bsol_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2394 /* bsola */, PPC::BCCLA, Convert__imm_95_108__regCR0__CondBr1_1, 0, { MCK_bsola, MCK_CondBr }, },
  { 2394 /* bsola */, PPC::BCCLA, Convert__imm_95_108__RegCRRC1_1__CondBr1_2, 0, { MCK_bsola, MCK_RegCRRC, MCK_CondBr }, },
  { 2400 /* bsola+ */, PPC::BCCLA, Convert__imm_95_111__regCR0__CondBr1_1, 0, { MCK_bsola_43_, MCK_CondBr }, },
  { 2400 /* bsola+ */, PPC::BCCLA, Convert__imm_95_111__RegCRRC1_1__CondBr1_2, 0, { MCK_bsola_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2407 /* bsola- */, PPC::BCCLA, Convert__imm_95_110__regCR0__CondBr1_1, 0, { MCK_bsola_MINUS_, MCK_CondBr }, },
  { 2407 /* bsola- */, PPC::BCCLA, Convert__imm_95_110__RegCRRC1_1__CondBr1_2, 0, { MCK_bsola_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2414 /* bsolr */, PPC::BCCLR, Convert__imm_95_108__regCR0, 0, { MCK_bsolr }, },
  { 2414 /* bsolr */, PPC::BCCLR, Convert__imm_95_108__RegCRRC1_1, 0, { MCK_bsolr, MCK_RegCRRC }, },
  { 2420 /* bsolr+ */, PPC::BCCLR, Convert__imm_95_111__regCR0, 0, { MCK_bsolr_43_ }, },
  { 2420 /* bsolr+ */, PPC::BCCLR, Convert__imm_95_111__RegCRRC1_1, 0, { MCK_bsolr_43_, MCK_RegCRRC }, },
  { 2427 /* bsolr- */, PPC::BCCLR, Convert__imm_95_110__regCR0, 0, { MCK_bsolr_MINUS_ }, },
  { 2427 /* bsolr- */, PPC::BCCLR, Convert__imm_95_110__RegCRRC1_1, 0, { MCK_bsolr_MINUS_, MCK_RegCRRC }, },
  { 2434 /* bsolrl */, PPC::BCCLRL, Convert__imm_95_108__regCR0, 0, { MCK_bsolrl }, },
  { 2434 /* bsolrl */, PPC::BCCLRL, Convert__imm_95_108__RegCRRC1_1, 0, { MCK_bsolrl, MCK_RegCRRC }, },
  { 2441 /* bsolrl+ */, PPC::BCCLRL, Convert__imm_95_111__regCR0, 0, { MCK_bsolrl_43_ }, },
  { 2441 /* bsolrl+ */, PPC::BCCLRL, Convert__imm_95_111__RegCRRC1_1, 0, { MCK_bsolrl_43_, MCK_RegCRRC }, },
  { 2449 /* bsolrl- */, PPC::BCCLRL, Convert__imm_95_110__regCR0, 0, { MCK_bsolrl_MINUS_ }, },
  { 2449 /* bsolrl- */, PPC::BCCLRL, Convert__imm_95_110__RegCRRC1_1, 0, { MCK_bsolrl_MINUS_, MCK_RegCRRC }, },
  { 2457 /* bt */, PPC::gBC, Convert__imm_95_12__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bt, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2460 /* bt+ */, PPC::gBC, Convert__imm_95_15__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bt_43_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2464 /* bt- */, PPC::gBC, Convert__imm_95_14__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bt_MINUS_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2468 /* bta */, PPC::gBCA, Convert__imm_95_12__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bta, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2472 /* bta+ */, PPC::gBCA, Convert__imm_95_15__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bta_43_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2477 /* bta- */, PPC::gBCA, Convert__imm_95_14__RegCRBITRC1_1__CondBr1_2, 0, { MCK_bta_MINUS_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2482 /* btctr */, PPC::gBCCTR, Convert__imm_95_12__RegCRBITRC1_1__imm_95_0, 0, { MCK_btctr, MCK_RegCRBITRC }, },
  { 2488 /* btctr+ */, PPC::gBCCTR, Convert__imm_95_15__RegCRBITRC1_1__imm_95_0, 0, { MCK_btctr_43_, MCK_RegCRBITRC }, },
  { 2495 /* btctr- */, PPC::gBCCTR, Convert__imm_95_14__RegCRBITRC1_1__imm_95_0, 0, { MCK_btctr_MINUS_, MCK_RegCRBITRC }, },
  { 2502 /* btctrl */, PPC::gBCCTRL, Convert__imm_95_12__RegCRBITRC1_1__imm_95_0, 0, { MCK_btctrl, MCK_RegCRBITRC }, },
  { 2509 /* btctrl+ */, PPC::gBCCTRL, Convert__imm_95_15__RegCRBITRC1_1__imm_95_0, 0, { MCK_btctrl_43_, MCK_RegCRBITRC }, },
  { 2517 /* btctrl- */, PPC::gBCCTRL, Convert__imm_95_14__RegCRBITRC1_1__imm_95_0, 0, { MCK_btctrl_MINUS_, MCK_RegCRBITRC }, },
  { 2525 /* btl */, PPC::gBCL, Convert__imm_95_12__RegCRBITRC1_1__CondBr1_2, 0, { MCK_btl, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2529 /* btl+ */, PPC::gBCL, Convert__imm_95_15__RegCRBITRC1_1__CondBr1_2, 0, { MCK_btl_43_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2534 /* btl- */, PPC::gBCL, Convert__imm_95_14__RegCRBITRC1_1__CondBr1_2, 0, { MCK_btl_MINUS_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2539 /* btla */, PPC::gBCLA, Convert__imm_95_12__RegCRBITRC1_1__CondBr1_2, 0, { MCK_btla, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2544 /* btla+ */, PPC::gBCLA, Convert__imm_95_15__RegCRBITRC1_1__CondBr1_2, 0, { MCK_btla_43_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2550 /* btla- */, PPC::gBCLA, Convert__imm_95_14__RegCRBITRC1_1__CondBr1_2, 0, { MCK_btla_MINUS_, MCK_RegCRBITRC, MCK_CondBr }, },
  { 2556 /* btlr */, PPC::gBCLR, Convert__imm_95_12__RegCRBITRC1_1__imm_95_0, 0, { MCK_btlr, MCK_RegCRBITRC }, },
  { 2561 /* btlr+ */, PPC::gBCLR, Convert__imm_95_15__RegCRBITRC1_1__imm_95_0, 0, { MCK_btlr_43_, MCK_RegCRBITRC }, },
  { 2567 /* btlr- */, PPC::gBCLR, Convert__imm_95_14__RegCRBITRC1_1__imm_95_0, 0, { MCK_btlr_MINUS_, MCK_RegCRBITRC }, },
  { 2573 /* btlrl */, PPC::gBCLRL, Convert__imm_95_12__RegCRBITRC1_1__imm_95_0, 0, { MCK_btlrl, MCK_RegCRBITRC }, },
  { 2579 /* btlrl+ */, PPC::gBCLRL, Convert__imm_95_15__RegCRBITRC1_1__imm_95_0, 0, { MCK_btlrl_43_, MCK_RegCRBITRC }, },
  { 2586 /* btlrl- */, PPC::gBCLRL, Convert__imm_95_14__RegCRBITRC1_1__imm_95_0, 0, { MCK_btlrl_MINUS_, MCK_RegCRBITRC }, },
  { 2593 /* bun */, PPC::BCC, Convert__imm_95_108__regCR0__CondBr1_1, 0, { MCK_bun, MCK_CondBr }, },
  { 2593 /* bun */, PPC::BCC, Convert__imm_95_108__RegCRRC1_1__CondBr1_2, 0, { MCK_bun, MCK_RegCRRC, MCK_CondBr }, },
  { 2597 /* bun+ */, PPC::BCC, Convert__imm_95_111__regCR0__CondBr1_1, 0, { MCK_bun_43_, MCK_CondBr }, },
  { 2597 /* bun+ */, PPC::BCC, Convert__imm_95_111__RegCRRC1_1__CondBr1_2, 0, { MCK_bun_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2602 /* bun- */, PPC::BCC, Convert__imm_95_110__regCR0__CondBr1_1, 0, { MCK_bun_MINUS_, MCK_CondBr }, },
  { 2602 /* bun- */, PPC::BCC, Convert__imm_95_110__RegCRRC1_1__CondBr1_2, 0, { MCK_bun_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2607 /* buna */, PPC::BCCA, Convert__imm_95_108__regCR0__CondBr1_1, 0, { MCK_buna, MCK_CondBr }, },
  { 2607 /* buna */, PPC::BCCA, Convert__imm_95_108__RegCRRC1_1__CondBr1_2, 0, { MCK_buna, MCK_RegCRRC, MCK_CondBr }, },
  { 2612 /* buna+ */, PPC::BCCA, Convert__imm_95_111__regCR0__CondBr1_1, 0, { MCK_buna_43_, MCK_CondBr }, },
  { 2612 /* buna+ */, PPC::BCCA, Convert__imm_95_111__RegCRRC1_1__CondBr1_2, 0, { MCK_buna_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2618 /* buna- */, PPC::BCCA, Convert__imm_95_110__regCR0__CondBr1_1, 0, { MCK_buna_MINUS_, MCK_CondBr }, },
  { 2618 /* buna- */, PPC::BCCA, Convert__imm_95_110__RegCRRC1_1__CondBr1_2, 0, { MCK_buna_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2624 /* bunctr */, PPC::BCCCTR, Convert__imm_95_108__regCR0, 0, { MCK_bunctr }, },
  { 2624 /* bunctr */, PPC::BCCCTR, Convert__imm_95_108__RegCRRC1_1, 0, { MCK_bunctr, MCK_RegCRRC }, },
  { 2631 /* bunctr+ */, PPC::BCCCTR, Convert__imm_95_111__regCR0, 0, { MCK_bunctr_43_ }, },
  { 2631 /* bunctr+ */, PPC::BCCCTR, Convert__imm_95_111__RegCRRC1_1, 0, { MCK_bunctr_43_, MCK_RegCRRC }, },
  { 2639 /* bunctr- */, PPC::BCCCTR, Convert__imm_95_110__regCR0, 0, { MCK_bunctr_MINUS_ }, },
  { 2639 /* bunctr- */, PPC::BCCCTR, Convert__imm_95_110__RegCRRC1_1, 0, { MCK_bunctr_MINUS_, MCK_RegCRRC }, },
  { 2647 /* bunctrl */, PPC::BCCCTRL, Convert__imm_95_108__regCR0, 0, { MCK_bunctrl }, },
  { 2647 /* bunctrl */, PPC::BCCCTRL, Convert__imm_95_108__RegCRRC1_1, 0, { MCK_bunctrl, MCK_RegCRRC }, },
  { 2655 /* bunctrl+ */, PPC::BCCCTRL, Convert__imm_95_111__regCR0, 0, { MCK_bunctrl_43_ }, },
  { 2655 /* bunctrl+ */, PPC::BCCCTRL, Convert__imm_95_111__RegCRRC1_1, 0, { MCK_bunctrl_43_, MCK_RegCRRC }, },
  { 2664 /* bunctrl- */, PPC::BCCCTRL, Convert__imm_95_110__regCR0, 0, { MCK_bunctrl_MINUS_ }, },
  { 2664 /* bunctrl- */, PPC::BCCCTRL, Convert__imm_95_110__RegCRRC1_1, 0, { MCK_bunctrl_MINUS_, MCK_RegCRRC }, },
  { 2673 /* bunl */, PPC::BCCL, Convert__imm_95_108__regCR0__CondBr1_1, 0, { MCK_bunl, MCK_CondBr }, },
  { 2673 /* bunl */, PPC::BCCL, Convert__imm_95_108__RegCRRC1_1__CondBr1_2, 0, { MCK_bunl, MCK_RegCRRC, MCK_CondBr }, },
  { 2678 /* bunl+ */, PPC::BCCL, Convert__imm_95_111__regCR0__CondBr1_1, 0, { MCK_bunl_43_, MCK_CondBr }, },
  { 2678 /* bunl+ */, PPC::BCCL, Convert__imm_95_111__RegCRRC1_1__CondBr1_2, 0, { MCK_bunl_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2684 /* bunl- */, PPC::BCCL, Convert__imm_95_110__regCR0__CondBr1_1, 0, { MCK_bunl_MINUS_, MCK_CondBr }, },
  { 2684 /* bunl- */, PPC::BCCL, Convert__imm_95_110__RegCRRC1_1__CondBr1_2, 0, { MCK_bunl_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2690 /* bunla */, PPC::BCCLA, Convert__imm_95_108__regCR0__CondBr1_1, 0, { MCK_bunla, MCK_CondBr }, },
  { 2690 /* bunla */, PPC::BCCLA, Convert__imm_95_108__RegCRRC1_1__CondBr1_2, 0, { MCK_bunla, MCK_RegCRRC, MCK_CondBr }, },
  { 2696 /* bunla+ */, PPC::BCCLA, Convert__imm_95_111__regCR0__CondBr1_1, 0, { MCK_bunla_43_, MCK_CondBr }, },
  { 2696 /* bunla+ */, PPC::BCCLA, Convert__imm_95_111__RegCRRC1_1__CondBr1_2, 0, { MCK_bunla_43_, MCK_RegCRRC, MCK_CondBr }, },
  { 2703 /* bunla- */, PPC::BCCLA, Convert__imm_95_110__regCR0__CondBr1_1, 0, { MCK_bunla_MINUS_, MCK_CondBr }, },
  { 2703 /* bunla- */, PPC::BCCLA, Convert__imm_95_110__RegCRRC1_1__CondBr1_2, 0, { MCK_bunla_MINUS_, MCK_RegCRRC, MCK_CondBr }, },
  { 2710 /* bunlr */, PPC::BCCLR, Convert__imm_95_108__regCR0, 0, { MCK_bunlr }, },
  { 2710 /* bunlr */, PPC::BCCLR, Convert__imm_95_108__RegCRRC1_1, 0, { MCK_bunlr, MCK_RegCRRC }, },
  { 2716 /* bunlr+ */, PPC::BCCLR, Convert__imm_95_111__regCR0, 0, { MCK_bunlr_43_ }, },
  { 2716 /* bunlr+ */, PPC::BCCLR, Convert__imm_95_111__RegCRRC1_1, 0, { MCK_bunlr_43_, MCK_RegCRRC }, },
  { 2723 /* bunlr- */, PPC::BCCLR, Convert__imm_95_110__regCR0, 0, { MCK_bunlr_MINUS_ }, },
  { 2723 /* bunlr- */, PPC::BCCLR, Convert__imm_95_110__RegCRRC1_1, 0, { MCK_bunlr_MINUS_, MCK_RegCRRC }, },
  { 2730 /* bunlrl */, PPC::BCCLRL, Convert__imm_95_108__regCR0, 0, { MCK_bunlrl }, },
  { 2730 /* bunlrl */, PPC::BCCLRL, Convert__imm_95_108__RegCRRC1_1, 0, { MCK_bunlrl, MCK_RegCRRC }, },
  { 2737 /* bunlrl+ */, PPC::BCCLRL, Convert__imm_95_111__regCR0, 0, { MCK_bunlrl_43_ }, },
  { 2737 /* bunlrl+ */, PPC::BCCLRL, Convert__imm_95_111__RegCRRC1_1, 0, { MCK_bunlrl_43_, MCK_RegCRRC }, },
  { 2745 /* bunlrl- */, PPC::BCCLRL, Convert__imm_95_110__regCR0, 0, { MCK_bunlrl_MINUS_ }, },
  { 2745 /* bunlrl- */, PPC::BCCLRL, Convert__imm_95_110__RegCRRC1_1, 0, { MCK_bunlrl_MINUS_, MCK_RegCRRC }, },
  { 2753 /* clrbhrb */, PPC::CLRBHRB, Convert_NoOperands, 0, { MCK_clrbhrb }, },
  { 2761 /* clrldi */, PPC::RLDICL, Convert__RegG8RC1_1__RegG8RC1_2__imm_95_0__U6Imm1_3, 0, { MCK_clrldi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 2761 /* clrldi */, PPC::RLDICLo, Convert__RegG8RC1_2__RegG8RC1_3__imm_95_0__U6Imm1_4, 0, { MCK_clrldi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 2768 /* clrlsldi */, PPC::CLRLSLDI, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, 0, { MCK_clrlsldi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 2768 /* clrlsldi */, PPC::CLRLSLDIo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__U6Imm1_5, 0, { MCK_clrlsldi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 2777 /* clrlslwi */, PPC::CLRLSLWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, 0, { MCK_clrlslwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 2777 /* clrlslwi */, PPC::CLRLSLWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5, 0, { MCK_clrlslwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 2786 /* clrlwi */, PPC::RLWINM, Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0__U5Imm1_3__imm_95_31, 0, { MCK_clrlwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 2786 /* clrlwi */, PPC::RLWINMo, Convert__RegGPRC1_2__RegGPRC1_3__imm_95_0__U5Imm1_4__imm_95_31, 0, { MCK_clrlwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 2793 /* clrrdi */, PPC::CLRRDI, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, 0, { MCK_clrrdi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 2793 /* clrrdi */, PPC::CLRRDIo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4, 0, { MCK_clrrdi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 2800 /* clrrwi */, PPC::CLRRWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_clrrwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 2800 /* clrrwi */, PPC::CLRRWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4, 0, { MCK_clrrwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 2807 /* cmp */, PPC::CMPW, Convert__RegCRRC1_1__RegGPRC1_3__RegGPRC1_4, 0, { MCK_cmp, MCK_RegCRRC, MCK_0, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2807 /* cmp */, PPC::CMPD, Convert__RegCRRC1_1__RegG8RC1_3__RegG8RC1_4, 0, { MCK_cmp, MCK_RegCRRC, MCK_1, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2811 /* cmpb */, PPC::CMPB, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_cmpb, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2816 /* cmpd */, PPC::CMPD, Convert__regCR0__RegG8RC1_1__RegG8RC1_2, 0, { MCK_cmpd, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2816 /* cmpd */, PPC::CMPD, Convert__RegCRRC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_cmpd, MCK_RegCRRC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2821 /* cmpdi */, PPC::CMPDI, Convert__regCR0__RegG8RC1_1__S16Imm1_2, 0, { MCK_cmpdi, MCK_RegG8RC, MCK_S16Imm }, },
  { 2821 /* cmpdi */, PPC::CMPDI, Convert__RegCRRC1_1__RegG8RC1_2__S16Imm1_3, 0, { MCK_cmpdi, MCK_RegCRRC, MCK_RegG8RC, MCK_S16Imm }, },
  { 2827 /* cmpi */, PPC::CMPWI, Convert__RegCRRC1_1__RegGPRC1_3__S16Imm1_4, 0, { MCK_cmpi, MCK_RegCRRC, MCK_0, MCK_RegGPRC, MCK_S16Imm }, },
  { 2827 /* cmpi */, PPC::CMPDI, Convert__RegCRRC1_1__RegG8RC1_3__S16Imm1_4, 0, { MCK_cmpi, MCK_RegCRRC, MCK_1, MCK_RegG8RC, MCK_S16Imm }, },
  { 2832 /* cmpl */, PPC::CMPLW, Convert__RegCRRC1_1__RegGPRC1_3__RegGPRC1_4, 0, { MCK_cmpl, MCK_RegCRRC, MCK_0, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2832 /* cmpl */, PPC::CMPLD, Convert__RegCRRC1_1__RegG8RC1_3__RegG8RC1_4, 0, { MCK_cmpl, MCK_RegCRRC, MCK_1, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2837 /* cmpld */, PPC::CMPLD, Convert__regCR0__RegG8RC1_1__RegG8RC1_2, 0, { MCK_cmpld, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2837 /* cmpld */, PPC::CMPLD, Convert__RegCRRC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_cmpld, MCK_RegCRRC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2843 /* cmpldi */, PPC::CMPLDI, Convert__regCR0__RegG8RC1_1__U16Imm1_2, 0, { MCK_cmpldi, MCK_RegG8RC, MCK_U16Imm }, },
  { 2843 /* cmpldi */, PPC::CMPLDI, Convert__RegCRRC1_1__RegG8RC1_2__U16Imm1_3, 0, { MCK_cmpldi, MCK_RegCRRC, MCK_RegG8RC, MCK_U16Imm }, },
  { 2850 /* cmpli */, PPC::CMPLWI, Convert__RegCRRC1_1__RegGPRC1_3__U16Imm1_4, 0, { MCK_cmpli, MCK_RegCRRC, MCK_0, MCK_RegGPRC, MCK_U16Imm }, },
  { 2850 /* cmpli */, PPC::CMPLDI, Convert__RegCRRC1_1__RegG8RC1_3__U16Imm1_4, 0, { MCK_cmpli, MCK_RegCRRC, MCK_1, MCK_RegG8RC, MCK_U16Imm }, },
  { 2856 /* cmplw */, PPC::CMPLW, Convert__regCR0__RegGPRC1_1__RegGPRC1_2, 0, { MCK_cmplw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2856 /* cmplw */, PPC::CMPLW, Convert__RegCRRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_cmplw, MCK_RegCRRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2862 /* cmplwi */, PPC::CMPLWI, Convert__regCR0__RegGPRC1_1__U16Imm1_2, 0, { MCK_cmplwi, MCK_RegGPRC, MCK_U16Imm }, },
  { 2862 /* cmplwi */, PPC::CMPLWI, Convert__RegCRRC1_1__RegGPRC1_2__U16Imm1_3, 0, { MCK_cmplwi, MCK_RegCRRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 2869 /* cmpw */, PPC::CMPW, Convert__regCR0__RegGPRC1_1__RegGPRC1_2, 0, { MCK_cmpw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2869 /* cmpw */, PPC::CMPW, Convert__RegCRRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_cmpw, MCK_RegCRRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2874 /* cmpwi */, PPC::CMPWI, Convert__regCR0__RegGPRC1_1__S16Imm1_2, 0, { MCK_cmpwi, MCK_RegGPRC, MCK_S16Imm }, },
  { 2874 /* cmpwi */, PPC::CMPWI, Convert__RegCRRC1_1__RegGPRC1_2__S16Imm1_3, 0, { MCK_cmpwi, MCK_RegCRRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 2880 /* cntlzd */, PPC::CNTLZD, Convert__RegG8RC1_1__RegG8RC1_2, 0, { MCK_cntlzd, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2880 /* cntlzd */, PPC::CNTLZDo, Convert__RegG8RC1_2__RegG8RC1_3, 0, { MCK_cntlzd, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 2887 /* cntlzw */, PPC::CNTLZW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_cntlzw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2887 /* cntlzw */, PPC::CNTLZW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_cntlzw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2887 /* cntlzw */, PPC::CNTLZWo, Convert__RegGPRC1_2__RegGPRC1_3, 0, { MCK_cntlzw, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2887 /* cntlzw */, PPC::CNTLZWo, Convert__RegGPRC1_2__RegGPRC1_3, 0, { MCK_cntlzw, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 2894 /* crand */, PPC::CRAND, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3, 0, { MCK_crand, MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2900 /* crandc */, PPC::CRANDC, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3, 0, { MCK_crandc, MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2907 /* crclr */, PPC::CRXOR, Convert__RegCRBITRC1_1__RegCRBITRC1_1__RegCRBITRC1_1, 0, { MCK_crclr, MCK_RegCRBITRC }, },
  { 2913 /* creqv */, PPC::CREQV, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3, 0, { MCK_creqv, MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2919 /* crmove */, PPC::CROR, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_2, 0, { MCK_crmove, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2926 /* crnand */, PPC::CRNAND, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3, 0, { MCK_crnand, MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2933 /* crnor */, PPC::CRNOR, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3, 0, { MCK_crnor, MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2939 /* crnot */, PPC::CRNOR, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_2, 0, { MCK_crnot, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2945 /* cror */, PPC::CROR, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3, 0, { MCK_cror, MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2950 /* crorc */, PPC::CRORC, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3, 0, { MCK_crorc, MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2956 /* crset */, PPC::CREQV, Convert__RegCRBITRC1_1__RegCRBITRC1_1__RegCRBITRC1_1, 0, { MCK_crset, MCK_RegCRBITRC }, },
  { 2962 /* crxor */, PPC::CRXOR, Convert__RegCRBITRC1_1__RegCRBITRC1_2__RegCRBITRC1_3, 0, { MCK_crxor, MCK_RegCRBITRC, MCK_RegCRBITRC, MCK_RegCRBITRC }, },
  { 2968 /* dcba */, PPC::DCBA, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcba, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 2973 /* dcbf */, PPC::DCBF, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbf, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 2978 /* dcbi */, PPC::DCBI, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbi, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 2983 /* dcbst */, PPC::DCBST, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbst, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 2989 /* dcbt */, PPC::DCBTx, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbt, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 2989 /* dcbt */, PPC::DCBT, Convert__U5Imm1_3__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbt, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 2994 /* dcbtct */, PPC::DCBTCT, Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_3, 0, { MCK_dcbtct, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3001 /* dcbtds */, PPC::DCBTDS, Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_3, 0, { MCK_dcbtds, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3008 /* dcbtst */, PPC::DCBTSTx, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbtst, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3008 /* dcbtst */, PPC::DCBTST, Convert__U5Imm1_3__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbtst, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3015 /* dcbtstct */, PPC::DCBTSTCT, Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_3, 0, { MCK_dcbtstct, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3024 /* dcbtstds */, PPC::DCBTSTDS, Convert__RegGxRCNoR01_1__RegGxRC1_2__U5Imm1_3, 0, { MCK_dcbtstds, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_U5Imm }, },
  { 3033 /* dcbtstt */, PPC::DCBTSTT, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbtstt, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3041 /* dcbtt */, PPC::DCBTT, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbtt, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3047 /* dcbz */, PPC::DCBZ, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbz, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3052 /* dcbzl */, PPC::DCBZL, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_dcbzl, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 3058 /* dccci */, PPC::DCCCI, Convert__regR0__regR0, 0, { MCK_dccci }, },
  { 3058 /* dccci */, PPC::DCCCI, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_dccci, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3064 /* dci */, PPC::DCCCI, Convert__regR0__regR0, 0, { MCK_dci, MCK_0 }, },
  { 3068 /* divd */, PPC::DIVD, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_divd, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3068 /* divd */, PPC::DIVDo, Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_4, 0, { MCK_divd, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3073 /* divde */, PPC::DIVDE, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_divde, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3073 /* divde */, PPC::DIVDEo, Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_4, 0, { MCK_divde, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3079 /* divdeu */, PPC::DIVDEU, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_divdeu, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3079 /* divdeu */, PPC::DIVDEUo, Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_4, 0, { MCK_divdeu, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3086 /* divdu */, PPC::DIVDU, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_divdu, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3086 /* divdu */, PPC::DIVDUo, Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_4, 0, { MCK_divdu, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 3092 /* divw */, PPC::DIVW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_divw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3092 /* divw */, PPC::DIVWo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_divw, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3097 /* divwe */, PPC::DIVWE, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_divwe, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3097 /* divwe */, PPC::DIVWEo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_divwe, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3103 /* divweu */, PPC::DIVWEU, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_divweu, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3103 /* divweu */, PPC::DIVWEUo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_divweu, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3110 /* divwu */, PPC::DIVWU, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_divwu, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3110 /* divwu */, PPC::DIVWUo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_divwu, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3116 /* dss */, PPC::DSS, Convert__U5Imm1_1, 0, { MCK_dss, MCK_U5Imm }, },
  { 3120 /* dssall */, PPC::DSSALL, Convert_NoOperands, 0, { MCK_dssall }, },
  { 3127 /* dst */, PPC::DST, Convert__U5Imm1_3__RegGPRC1_1__RegGPRC1_2, 0, { MCK_dst, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 3131 /* dstst */, PPC::DSTST, Convert__U5Imm1_3__RegGPRC1_1__RegGPRC1_2, 0, { MCK_dstst, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 3137 /* dststt */, PPC::DSTSTT, Convert__U5Imm1_3__RegGPRC1_1__RegGPRC1_2, 0, { MCK_dststt, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 3144 /* dstt */, PPC::DSTT, Convert__U5Imm1_3__RegGPRC1_1__RegGPRC1_2, 0, { MCK_dstt, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 3149 /* eieio */, PPC::EnforceIEIO, Convert_NoOperands, 0, { MCK_eieio }, },
  { 3155 /* eqv */, PPC::EQV, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_eqv, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3155 /* eqv */, PPC::EQVo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_eqv, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3159 /* evabs */, PPC::EVABS, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evabs, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3165 /* evaddiw */, PPC::EVADDIW, Convert__RegGPRC1_1__RegGPRC1_3__U5Imm1_2, 0, { MCK_evaddiw, MCK_RegGPRC, MCK_U5Imm, MCK_RegGPRC }, },
  { 3173 /* evaddsmiaaw */, PPC::EVADDSMIAAW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evaddsmiaaw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3185 /* evaddssiaaw */, PPC::EVADDSSIAAW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evaddssiaaw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3197 /* evaddumiaaw */, PPC::EVADDUMIAAW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evaddumiaaw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3209 /* evaddusiaaw */, PPC::EVADDUSIAAW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evaddusiaaw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3221 /* evaddw */, PPC::EVADDW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evaddw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3228 /* evand */, PPC::EVAND, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evand, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3234 /* evandc */, PPC::EVANDC, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evandc, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3241 /* evcmpeq */, PPC::EVCMPEQ, Convert__RegCRRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evcmpeq, MCK_RegCRRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3249 /* evcmpgts */, PPC::EVCMPGTS, Convert__RegCRRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evcmpgts, MCK_RegCRRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3258 /* evcmpgtu */, PPC::EVCMPGTU, Convert__RegCRRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evcmpgtu, MCK_RegCRRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3267 /* evcmplts */, PPC::EVCMPLTS, Convert__RegCRRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evcmplts, MCK_RegCRRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3276 /* evcmpltu */, PPC::EVCMPLTU, Convert__RegCRRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evcmpltu, MCK_RegCRRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3285 /* evcntlsw */, PPC::EVCNTLSW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evcntlsw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3294 /* evcntlzw */, PPC::EVCNTLZW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evcntlzw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3303 /* evdivws */, PPC::EVDIVWS, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evdivws, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3311 /* evdivwu */, PPC::EVDIVWU, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evdivwu, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3319 /* eveqv */, PPC::EVEQV, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_eveqv, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3325 /* evextsb */, PPC::EVEXTSB, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evextsb, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3333 /* evextsh */, PPC::EVEXTSH, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evextsh, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3341 /* evldd */, PPC::EVLDD, Convert__RegGPRC1_1__DispSPE81_2__RegGxRCNoR01_3, 0, { MCK_evldd, MCK_RegGPRC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 3347 /* evlddx */, PPC::EVLDDX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evlddx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3354 /* evldh */, PPC::EVLDH, Convert__RegGPRC1_1__DispSPE81_2__RegGxRCNoR01_3, 0, { MCK_evldh, MCK_RegGPRC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 3360 /* evldhx */, PPC::EVLDHX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evldhx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3367 /* evldw */, PPC::EVLDW, Convert__RegGPRC1_1__DispSPE81_2__RegGxRCNoR01_3, 0, { MCK_evldw, MCK_RegGPRC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 3373 /* evldwx */, PPC::EVLDWX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evldwx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3380 /* evlhhesplat */, PPC::EVLHHESPLAT, Convert__RegGPRC1_1__DispSPE21_2__RegGxRCNoR01_3, 0, { MCK_evlhhesplat, MCK_RegGPRC, MCK_DispSPE2, MCK_RegGxRCNoR0 }, },
  { 3392 /* evlhhesplatx */, PPC::EVLHHESPLATX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evlhhesplatx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3405 /* evlhhossplat */, PPC::EVLHHOSSPLAT, Convert__RegGPRC1_1__DispSPE21_2__RegGxRCNoR01_3, 0, { MCK_evlhhossplat, MCK_RegGPRC, MCK_DispSPE2, MCK_RegGxRCNoR0 }, },
  { 3418 /* evlhhossplatx */, PPC::EVLHHOSSPLATX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evlhhossplatx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3432 /* evlhhousplat */, PPC::EVLHHOUSPLAT, Convert__RegGPRC1_1__DispSPE21_2__RegGxRCNoR01_3, 0, { MCK_evlhhousplat, MCK_RegGPRC, MCK_DispSPE2, MCK_RegGxRCNoR0 }, },
  { 3445 /* evlhhousplatx */, PPC::EVLHHOUSPLATX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evlhhousplatx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3459 /* evlwhe */, PPC::EVLWHE, Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3, 0, { MCK_evlwhe, MCK_RegGPRC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 3466 /* evlwhex */, PPC::EVLWHEX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evlwhex, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3474 /* evlwhos */, PPC::EVLWHOS, Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3, 0, { MCK_evlwhos, MCK_RegGPRC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 3482 /* evlwhosx */, PPC::EVLWHOSX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evlwhosx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3491 /* evlwhou */, PPC::EVLWHOU, Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3, 0, { MCK_evlwhou, MCK_RegGPRC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 3499 /* evlwhoux */, PPC::EVLWHOUX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evlwhoux, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3508 /* evlwhsplat */, PPC::EVLWHSPLAT, Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3, 0, { MCK_evlwhsplat, MCK_RegGPRC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 3519 /* evlwhsplatx */, PPC::EVLWHSPLATX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evlwhsplatx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3531 /* evlwwsplat */, PPC::EVLWWSPLAT, Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3, 0, { MCK_evlwwsplat, MCK_RegGPRC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 3542 /* evlwwsplatx */, PPC::EVLWWSPLATX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evlwwsplatx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3554 /* evmergehi */, PPC::EVMERGEHI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmergehi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3564 /* evmergehilo */, PPC::EVMERGEHILO, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmergehilo, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3576 /* evmergelo */, PPC::EVMERGELO, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmergelo, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3586 /* evmergelohi */, PPC::EVMERGELOHI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmergelohi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3598 /* evmhegsmfaa */, PPC::EVMHEGSMFAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhegsmfaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3610 /* evmhegsmfan */, PPC::EVMHEGSMFAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhegsmfan, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3622 /* evmhegsmiaa */, PPC::EVMHEGSMIAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhegsmiaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3634 /* evmhegsmian */, PPC::EVMHEGSMIAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhegsmian, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3646 /* evmhegumiaa */, PPC::EVMHEGUMIAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhegumiaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3658 /* evmhegumian */, PPC::EVMHEGUMIAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhegumian, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3670 /* evmhesmf */, PPC::EVMHESMF, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhesmf, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3679 /* evmhesmfa */, PPC::EVMHESMFA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhesmfa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3689 /* evmhesmfaaw */, PPC::EVMHESMFAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhesmfaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3701 /* evmhesmfanw */, PPC::EVMHESMFANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhesmfanw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3713 /* evmhesmi */, PPC::EVMHESMI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhesmi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3722 /* evmhesmia */, PPC::EVMHESMIA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhesmia, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3732 /* evmhesmiaaw */, PPC::EVMHESMIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhesmiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3744 /* evmhesmianw */, PPC::EVMHESMIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhesmianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3756 /* evmhessf */, PPC::EVMHESSF, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhessf, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3765 /* evmhessfa */, PPC::EVMHESSFA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhessfa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3775 /* evmhessfaaw */, PPC::EVMHESSFAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhessfaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3787 /* evmhessfanw */, PPC::EVMHESSFANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhessfanw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3799 /* evmhessiaaw */, PPC::EVMHESSIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhessiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3811 /* evmhessianw */, PPC::EVMHESSIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhessianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3823 /* evmheumi */, PPC::EVMHEUMI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmheumi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3832 /* evmheumia */, PPC::EVMHEUMIA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmheumia, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3842 /* evmheumiaaw */, PPC::EVMHEUMIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmheumiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3854 /* evmheumianw */, PPC::EVMHEUMIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmheumianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3866 /* evmheusiaaw */, PPC::EVMHEUSIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmheusiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3878 /* evmheusianw */, PPC::EVMHEUSIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmheusianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3890 /* evmhogsmfaa */, PPC::EVMHOGSMFAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhogsmfaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3902 /* evmhogsmfan */, PPC::EVMHOGSMFAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhogsmfan, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3914 /* evmhogsmiaa */, PPC::EVMHOGSMIAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhogsmiaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3926 /* evmhogsmian */, PPC::EVMHOGSMIAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhogsmian, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3938 /* evmhogumiaa */, PPC::EVMHOGUMIAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhogumiaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3950 /* evmhogumian */, PPC::EVMHOGUMIAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhogumian, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3962 /* evmhosmf */, PPC::EVMHOSMF, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhosmf, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3971 /* evmhosmfa */, PPC::EVMHOSMFA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhosmfa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3981 /* evmhosmfaaw */, PPC::EVMHOSMFAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhosmfaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 3993 /* evmhosmfanw */, PPC::EVMHOSMFANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhosmfanw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4005 /* evmhosmi */, PPC::EVMHOSMI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhosmi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4014 /* evmhosmia */, PPC::EVMHOSMIA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhosmia, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4024 /* evmhosmiaaw */, PPC::EVMHOSMIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhosmiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4036 /* evmhosmianw */, PPC::EVMHOSMIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhosmianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4048 /* evmhossf */, PPC::EVMHOSSF, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhossf, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4057 /* evmhossfa */, PPC::EVMHOSSFA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhossfa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4067 /* evmhossfaaw */, PPC::EVMHOSSFAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhossfaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4079 /* evmhossfanw */, PPC::EVMHOSSFANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhossfanw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4091 /* evmhossiaaw */, PPC::EVMHOSSIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhossiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4103 /* evmhossianw */, PPC::EVMHOSSIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhossianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4115 /* evmhoumi */, PPC::EVMHOUMI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhoumi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4124 /* evmhoumia */, PPC::EVMHOUMIA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhoumia, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4134 /* evmhoumiaaw */, PPC::EVMHOUMIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhoumiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4146 /* evmhoumianw */, PPC::EVMHOUMIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhoumianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4158 /* evmhousiaaw */, PPC::EVMHOUSIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhousiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4170 /* evmhousianw */, PPC::EVMHOUSIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmhousianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4182 /* evmra */, PPC::EVMRA, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evmra, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4188 /* evmwhsmf */, PPC::EVMWHSMF, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwhsmf, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4197 /* evmwhsmfa */, PPC::EVMWHSMFA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwhsmfa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4207 /* evmwhsmi */, PPC::EVMWHSMI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwhsmi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4216 /* evmwhsmia */, PPC::EVMWHSMIA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwhsmia, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4226 /* evmwhssf */, PPC::EVMWHSSF, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwhssf, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4235 /* evmwhssfa */, PPC::EVMWHSSFA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwhssfa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4245 /* evmwhumi */, PPC::EVMWHUMI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwhumi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4254 /* evmwhumia */, PPC::EVMWHUMIA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwhumia, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4264 /* evmwlsmiaaw */, PPC::EVMWLSMIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlsmiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4276 /* evmwlsmianw */, PPC::EVMWLSMIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlsmianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4288 /* evmwlssiaaw */, PPC::EVMWLSSIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlssiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4300 /* evmwlssianw */, PPC::EVMWLSSIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlssianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4312 /* evmwlumi */, PPC::EVMWLUMI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlumi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4321 /* evmwlumia */, PPC::EVMWLUMIA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlumia, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4331 /* evmwlumiaaw */, PPC::EVMWLUMIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlumiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4343 /* evmwlumianw */, PPC::EVMWLUMIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlumianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4355 /* evmwlusiaaw */, PPC::EVMWLUSIAAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlusiaaw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4367 /* evmwlusianw */, PPC::EVMWLUSIANW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwlusianw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4379 /* evmwsmf */, PPC::EVMWSMF, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwsmf, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4387 /* evmwsmfa */, PPC::EVMWSMFA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwsmfa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4396 /* evmwsmfaa */, PPC::EVMWSMFAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwsmfaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4406 /* evmwsmfan */, PPC::EVMWSMFAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwsmfan, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4416 /* evmwsmi */, PPC::EVMWSMI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwsmi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4424 /* evmwsmia */, PPC::EVMWSMIA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwsmia, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4433 /* evmwsmiaa */, PPC::EVMWSMIAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwsmiaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4443 /* evmwsmian */, PPC::EVMWSMIAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwsmian, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4453 /* evmwssf */, PPC::EVMWSSF, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwssf, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4461 /* evmwssfa */, PPC::EVMWSSFA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwssfa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4470 /* evmwssfaa */, PPC::EVMWSSFAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwssfaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4480 /* evmwssfan */, PPC::EVMWSSFAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwssfan, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4490 /* evmwumi */, PPC::EVMWUMI, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwumi, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4498 /* evmwumia */, PPC::EVMWUMIA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwumia, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4507 /* evmwumiaa */, PPC::EVMWUMIAA, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwumiaa, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4517 /* evmwumian */, PPC::EVMWUMIAN, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evmwumian, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4527 /* evnand */, PPC::EVNAND, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evnand, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4534 /* evneg */, PPC::EVNEG, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evneg, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4540 /* evnor */, PPC::EVNOR, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evnor, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4546 /* evor */, PPC::EVOR, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evor, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4551 /* evorc */, PPC::EVORC, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evorc, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4557 /* evrlw */, PPC::EVRLW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evrlw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4563 /* evrlwi */, PPC::EVRLWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_evrlwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 4570 /* evrndw */, PPC::EVRNDW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evrndw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4577 /* evslw */, PPC::EVSLW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evslw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4583 /* evslwi */, PPC::EVSLWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_evslwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 4590 /* evsplatfi */, PPC::EVSPLATFI, Convert__RegGPRC1_1__Imm1_2, 0, { MCK_evsplatfi, MCK_RegGPRC, MCK_Imm }, },
  { 4600 /* evsplati */, PPC::EVSPLATI, Convert__RegGPRC1_1__Imm1_2, 0, { MCK_evsplati, MCK_RegGPRC, MCK_Imm }, },
  { 4609 /* evsrwis */, PPC::EVSRWIS, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_evsrwis, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 4617 /* evsrwiu */, PPC::EVSRWIU, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_evsrwiu, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 4625 /* evsrws */, PPC::EVSRWS, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evsrws, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4632 /* evsrwu */, PPC::EVSRWU, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evsrwu, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4639 /* evstdd */, PPC::EVSTDD, Convert__RegGPRC1_1__DispSPE81_2__RegGxRCNoR01_3, 0, { MCK_evstdd, MCK_RegGPRC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 4646 /* evstddx */, PPC::EVSTDDX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evstddx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4654 /* evstdh */, PPC::EVSTDH, Convert__RegGPRC1_1__DispSPE81_2__RegGxRCNoR01_3, 0, { MCK_evstdh, MCK_RegGPRC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 4661 /* evstdhx */, PPC::EVSTDHX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evstdhx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4669 /* evstdw */, PPC::EVSTDW, Convert__RegGPRC1_1__DispSPE81_2__RegGxRCNoR01_3, 0, { MCK_evstdw, MCK_RegGPRC, MCK_DispSPE8, MCK_RegGxRCNoR0 }, },
  { 4676 /* evstdwx */, PPC::EVSTDWX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evstdwx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4684 /* evstwhe */, PPC::EVSTWHE, Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3, 0, { MCK_evstwhe, MCK_RegGPRC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 4692 /* evstwhex */, PPC::EVSTWHEX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evstwhex, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4701 /* evstwho */, PPC::EVSTWHO, Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3, 0, { MCK_evstwho, MCK_RegGPRC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 4709 /* evstwhox */, PPC::EVSTWHOX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evstwhox, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4718 /* evstwwe */, PPC::EVSTWWE, Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3, 0, { MCK_evstwwe, MCK_RegGPRC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 4726 /* evstwwex */, PPC::EVSTWWEX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evstwwex, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4735 /* evstwwo */, PPC::EVSTWWO, Convert__RegGPRC1_1__DispSPE41_2__RegGxRCNoR01_3, 0, { MCK_evstwwo, MCK_RegGPRC, MCK_DispSPE4, MCK_RegGxRCNoR0 }, },
  { 4743 /* evstwwox */, PPC::EVSTWWOX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evstwwox, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4752 /* evsubfsmiaaw */, PPC::EVSUBFSMIAAW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evsubfsmiaaw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4765 /* evsubfssiaaw */, PPC::EVSUBFSSIAAW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evsubfssiaaw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4778 /* evsubfumiaaw */, PPC::EVSUBFUMIAAW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evsubfumiaaw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4791 /* evsubfusiaaw */, PPC::EVSUBFUSIAAW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_evsubfusiaaw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4804 /* evsubfw */, PPC::EVSUBFW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evsubfw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4812 /* evsubifw */, PPC::EVSUBIFW, Convert__RegGPRC1_1__U5Imm1_2__RegGPRC1_3, 0, { MCK_evsubifw, MCK_RegGPRC, MCK_U5Imm, MCK_RegGPRC }, },
  { 4821 /* evxor */, PPC::EVXOR, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_evxor, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4827 /* extldi */, PPC::EXTLDI, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, 0, { MCK_extldi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 4827 /* extldi */, PPC::EXTLDIo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__U6Imm1_5, 0, { MCK_extldi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 4834 /* extlwi */, PPC::EXTLWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, 0, { MCK_extlwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 4834 /* extlwi */, PPC::EXTLWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5, 0, { MCK_extlwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 4841 /* extrdi */, PPC::EXTRDI, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, 0, { MCK_extrdi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 4841 /* extrdi */, PPC::EXTRDIo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__U6Imm1_5, 0, { MCK_extrdi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 4848 /* extrwi */, PPC::EXTRWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, 0, { MCK_extrwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 4848 /* extrwi */, PPC::EXTRWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5, 0, { MCK_extrwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 4855 /* extsb */, PPC::EXTSB, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_extsb, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4855 /* extsb */, PPC::EXTSBo, Convert__RegGPRC1_2__RegGPRC1_3, 0, { MCK_extsb, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4861 /* extsh */, PPC::EXTSH, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_extsh, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4861 /* extsh */, PPC::EXTSHo, Convert__RegGPRC1_2__RegGPRC1_3, 0, { MCK_extsh, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 4867 /* extsw */, PPC::EXTSW, Convert__RegG8RC1_1__RegG8RC1_2, 0, { MCK_extsw, MCK_RegG8RC, MCK_RegG8RC }, },
  { 4867 /* extsw */, PPC::EXTSWo, Convert__RegG8RC1_2__RegG8RC1_3, 0, { MCK_extsw, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 4873 /* fabs */, PPC::FABSS, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_fabs, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4873 /* fabs */, PPC::FABSSo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fabs, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4878 /* fadd */, PPC::FADD, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fadd, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4878 /* fadd */, PPC::FADDo, Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, 0, { MCK_fadd, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4883 /* fadds */, PPC::FADDS, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fadds, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4883 /* fadds */, PPC::FADDSo, Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fadds, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4889 /* fcfid */, PPC::FCFID, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fcfid, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4889 /* fcfid */, PPC::FCFIDo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fcfid, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4895 /* fcfids */, PPC::FCFIDS, Convert__RegF4RC1_1__RegF8RC1_2, 0, { MCK_fcfids, MCK_RegF4RC, MCK_RegF8RC }, },
  { 4895 /* fcfids */, PPC::FCFIDSo, Convert__RegF4RC1_2__RegF8RC1_3, 0, { MCK_fcfids, MCK__DOT_, MCK_RegF4RC, MCK_RegF8RC }, },
  { 4902 /* fcfidu */, PPC::FCFIDU, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fcfidu, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4902 /* fcfidu */, PPC::FCFIDUo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fcfidu, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4909 /* fcfidus */, PPC::FCFIDUS, Convert__RegF4RC1_1__RegF8RC1_2, 0, { MCK_fcfidus, MCK_RegF4RC, MCK_RegF8RC }, },
  { 4909 /* fcfidus */, PPC::FCFIDUSo, Convert__RegF4RC1_2__RegF8RC1_3, 0, { MCK_fcfidus, MCK__DOT_, MCK_RegF4RC, MCK_RegF8RC }, },
  { 4917 /* fcmpu */, PPC::FCMPUS, Convert__RegCRRC1_1__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fcmpu, MCK_RegCRRC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4923 /* fcpsgn */, PPC::FCPSGNS, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fcpsgn, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4923 /* fcpsgn */, PPC::FCPSGNSo, Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fcpsgn, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4930 /* fctid */, PPC::FCTID, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fctid, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4930 /* fctid */, PPC::FCTIDo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fctid, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4936 /* fctiduz */, PPC::FCTIDUZ, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fctiduz, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4936 /* fctiduz */, PPC::FCTIDUZo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fctiduz, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4944 /* fctidz */, PPC::FCTIDZ, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fctidz, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4944 /* fctidz */, PPC::FCTIDZo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fctidz, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4951 /* fctiw */, PPC::FCTIW, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fctiw, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4951 /* fctiw */, PPC::FCTIWo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fctiw, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4957 /* fctiwuz */, PPC::FCTIWUZ, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fctiwuz, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4957 /* fctiwuz */, PPC::FCTIWUZo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fctiwuz, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4965 /* fctiwz */, PPC::FCTIWZ, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fctiwz, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4965 /* fctiwz */, PPC::FCTIWZo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fctiwz, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4972 /* fdiv */, PPC::FDIV, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fdiv, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4972 /* fdiv */, PPC::FDIVo, Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, 0, { MCK_fdiv, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4977 /* fdivs */, PPC::FDIVS, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fdivs, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4977 /* fdivs */, PPC::FDIVSo, Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fdivs, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4983 /* fmadd */, PPC::FMADD, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, 0, { MCK_fmadd, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4983 /* fmadd */, PPC::FMADDo, Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4__RegF8RC1_5, 0, { MCK_fmadd, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 4989 /* fmadds */, PPC::FMADDS, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fmadds, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4989 /* fmadds */, PPC::FMADDSo, Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4__RegF4RC1_5, 0, { MCK_fmadds, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4996 /* fmr */, PPC::FMR, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_fmr, MCK_RegF4RC, MCK_RegF4RC }, },
  { 4996 /* fmr */, PPC::FMRo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fmr, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5000 /* fmsub */, PPC::FMSUB, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, 0, { MCK_fmsub, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5000 /* fmsub */, PPC::FMSUBo, Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4__RegF8RC1_5, 0, { MCK_fmsub, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5006 /* fmsubs */, PPC::FMSUBS, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fmsubs, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5006 /* fmsubs */, PPC::FMSUBSo, Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4__RegF4RC1_5, 0, { MCK_fmsubs, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5013 /* fmul */, PPC::FMUL, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fmul, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5013 /* fmul */, PPC::FMULo, Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, 0, { MCK_fmul, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5018 /* fmuls */, PPC::FMULS, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fmuls, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5018 /* fmuls */, PPC::FMULSo, Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fmuls, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5024 /* fnabs */, PPC::FNABSS, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_fnabs, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5024 /* fnabs */, PPC::FNABSSo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fnabs, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5030 /* fneg */, PPC::FNEGS, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_fneg, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5030 /* fneg */, PPC::FNEGSo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fneg, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5035 /* fnmadd */, PPC::FNMADD, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, 0, { MCK_fnmadd, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5035 /* fnmadd */, PPC::FNMADDo, Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4__RegF8RC1_5, 0, { MCK_fnmadd, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5042 /* fnmadds */, PPC::FNMADDS, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fnmadds, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5042 /* fnmadds */, PPC::FNMADDSo, Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4__RegF4RC1_5, 0, { MCK_fnmadds, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5050 /* fnmsub */, PPC::FNMSUB, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, 0, { MCK_fnmsub, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5050 /* fnmsub */, PPC::FNMSUBo, Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4__RegF8RC1_5, 0, { MCK_fnmsub, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5057 /* fnmsubs */, PPC::FNMSUBS, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fnmsubs, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5057 /* fnmsubs */, PPC::FNMSUBSo, Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4__RegF4RC1_5, 0, { MCK_fnmsubs, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5065 /* fre */, PPC::FRE, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fre, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5065 /* fre */, PPC::FREo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fre, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5069 /* fres */, PPC::FRES, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_fres, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5069 /* fres */, PPC::FRESo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fres, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5074 /* frim */, PPC::FRIMS, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_frim, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5074 /* frim */, PPC::FRIMSo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_frim, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5079 /* frin */, PPC::FRINS, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_frin, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5079 /* frin */, PPC::FRINSo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_frin, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5084 /* frip */, PPC::FRIPS, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_frip, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5084 /* frip */, PPC::FRIPSo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_frip, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5089 /* friz */, PPC::FRIZS, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_friz, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5089 /* friz */, PPC::FRIZSo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_friz, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5094 /* frsp */, PPC::FRSP, Convert__RegF4RC1_1__RegF8RC1_2, 0, { MCK_frsp, MCK_RegF4RC, MCK_RegF8RC }, },
  { 5094 /* frsp */, PPC::FRSPo, Convert__RegF4RC1_2__RegF8RC1_3, 0, { MCK_frsp, MCK__DOT_, MCK_RegF4RC, MCK_RegF8RC }, },
  { 5099 /* frsqrte */, PPC::FRSQRTE, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_frsqrte, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5099 /* frsqrte */, PPC::FRSQRTEo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_frsqrte, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5107 /* frsqrtes */, PPC::FRSQRTES, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_frsqrtes, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5107 /* frsqrtes */, PPC::FRSQRTESo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_frsqrtes, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5116 /* fsel */, PPC::FSELS, Convert__RegF4RC1_1__RegF8RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fsel, MCK_RegF4RC, MCK_RegF8RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5116 /* fsel */, PPC::FSELSo, Convert__RegF4RC1_2__RegF8RC1_3__RegF4RC1_4__RegF4RC1_5, 0, { MCK_fsel, MCK__DOT_, MCK_RegF4RC, MCK_RegF8RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5121 /* fsqrt */, PPC::FSQRT, Convert__RegF8RC1_1__RegF8RC1_2, 0, { MCK_fsqrt, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5121 /* fsqrt */, PPC::FSQRTo, Convert__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fsqrt, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5127 /* fsqrts */, PPC::FSQRTS, Convert__RegF4RC1_1__RegF4RC1_2, 0, { MCK_fsqrts, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5127 /* fsqrts */, PPC::FSQRTSo, Convert__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fsqrts, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5134 /* fsub */, PPC::FSUB, Convert__RegF8RC1_1__RegF8RC1_2__RegF8RC1_3, 0, { MCK_fsub, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5134 /* fsub */, PPC::FSUBo, Convert__RegF8RC1_2__RegF8RC1_3__RegF8RC1_4, 0, { MCK_fsub, MCK__DOT_, MCK_RegF8RC, MCK_RegF8RC, MCK_RegF8RC }, },
  { 5139 /* fsubs */, PPC::FSUBS, Convert__RegF4RC1_1__RegF4RC1_2__RegF4RC1_3, 0, { MCK_fsubs, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5139 /* fsubs */, PPC::FSUBSo, Convert__RegF4RC1_2__RegF4RC1_3__RegF4RC1_4, 0, { MCK_fsubs, MCK__DOT_, MCK_RegF4RC, MCK_RegF4RC, MCK_RegF4RC }, },
  { 5145 /* icbi */, PPC::ICBI, Convert__RegGxRCNoR01_1__RegGxRC1_2, 0, { MCK_icbi, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5150 /* icbt */, PPC::ICBT, Convert__U4Imm1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_icbt, MCK_U4Imm, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5155 /* iccci */, PPC::ICCCI, Convert__regR0__regR0, 0, { MCK_iccci }, },
  { 5155 /* iccci */, PPC::ICCCI, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_iccci, MCK_RegGPRC, MCK_RegGPRC }, },
  { 5161 /* ici */, PPC::ICCCI, Convert__regR0__regR0, 0, { MCK_ici, MCK_0 }, },
  { 5165 /* inslwi */, PPC::INSLWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, 0, { MCK_inslwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 5165 /* inslwi */, PPC::INSLWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5, 0, { MCK_inslwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 5172 /* insrdi */, PPC::INSRDI, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, 0, { MCK_insrdi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 5172 /* insrdi */, PPC::INSRDIo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__U6Imm1_5, 0, { MCK_insrdi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 5179 /* insrwi */, PPC::INSRWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4, 0, { MCK_insrwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 5179 /* insrwi */, PPC::INSRWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5, 0, { MCK_insrwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 5186 /* isel */, PPC::ISEL, Convert__RegGPRC1_1__RegGPRCNoR01_2__RegGPRC1_3__RegCRBITRC1_4, 0, { MCK_isel, MCK_RegGPRC, MCK_RegGPRCNoR0, MCK_RegGPRC, MCK_RegCRBITRC }, },
  { 5191 /* isync */, PPC::ISYNC, Convert_NoOperands, 0, { MCK_isync }, },
  { 5197 /* la */, PPC::LAx, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_la, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5200 /* lbarx */, PPC::LBARX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lbarx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5200 /* lbarx */, PPC::LBARXL, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lbarx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_1 }, },
  { 5206 /* lbz */, PPC::LBZ, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lbz, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5210 /* lbzcix */, PPC::LBZCIX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_lbzcix, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 5217 /* lbzu */, PPC::LBZU, Convert__RegGPRC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lbzu, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5222 /* lbzux */, PPC::LBZUX, Convert__RegGPRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lbzux, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5228 /* lbzx */, PPC::LBZX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lbzx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5233 /* ld */, PPC::LD, Convert__RegG8RC1_1__DispRIX1_2__RegGxRCNoR01_3, 0, { MCK_ld, MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 5236 /* ldarx */, PPC::LDARX, Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_ldarx, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5236 /* ldarx */, PPC::LDARXL, Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_ldarx, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_1 }, },
  { 5242 /* ldbrx */, PPC::LDBRX, Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_ldbrx, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5248 /* ldcix */, PPC::LDCIX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_ldcix, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 5254 /* ldu */, PPC::LDU, Convert__RegG8RC1_1__imm_95_0__DispRIX1_2__RegGxRCNoR01_3, 0, { MCK_ldu, MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 5258 /* ldux */, PPC::LDUX, Convert__RegG8RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_ldux, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5263 /* ldx */, PPC::LDX, Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_ldx, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5267 /* lfd */, PPC::LFD, Convert__RegF8RC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lfd, MCK_RegF8RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5271 /* lfdu */, PPC::LFDU, Convert__RegF8RC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lfdu, MCK_RegF8RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5276 /* lfdux */, PPC::LFDUX, Convert__RegF8RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lfdux, MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5282 /* lfdx */, PPC::LFDX, Convert__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lfdx, MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5287 /* lfiwax */, PPC::LFIWAX, Convert__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lfiwax, MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5294 /* lfiwzx */, PPC::LFIWZX, Convert__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lfiwzx, MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5301 /* lfs */, PPC::LFS, Convert__RegF4RC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lfs, MCK_RegF4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5305 /* lfsu */, PPC::LFSU, Convert__RegF4RC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lfsu, MCK_RegF4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5310 /* lfsux */, PPC::LFSUX, Convert__RegF4RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lfsux, MCK_RegF4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5316 /* lfsx */, PPC::LFSX, Convert__RegF4RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lfsx, MCK_RegF4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5321 /* lha */, PPC::LHA, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lha, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5325 /* lharx */, PPC::LHARX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lharx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5325 /* lharx */, PPC::LHARXL, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lharx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_1 }, },
  { 5331 /* lhau */, PPC::LHAU, Convert__RegGPRC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lhau, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5336 /* lhaux */, PPC::LHAUX, Convert__RegGPRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lhaux, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5342 /* lhax */, PPC::LHAX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lhax, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5347 /* lhbrx */, PPC::LHBRX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lhbrx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5353 /* lhz */, PPC::LHZ, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lhz, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5357 /* lhzcix */, PPC::LHZCIX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_lhzcix, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 5364 /* lhzu */, PPC::LHZU, Convert__RegGPRC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lhzu, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5369 /* lhzux */, PPC::LHZUX, Convert__RegGPRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lhzux, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5375 /* lhzx */, PPC::LHZX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lhzx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5380 /* li */, PPC::LI, Convert__RegGPRC1_1__S16Imm1_2, 0, { MCK_li, MCK_RegGPRC, MCK_S16Imm }, },
  { 5383 /* lis */, PPC::LIS, Convert__RegGPRC1_1__S17Imm1_2, 0, { MCK_lis, MCK_RegGPRC, MCK_S17Imm }, },
  { 5387 /* lmw */, PPC::LMW, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lmw, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5391 /* lswi */, PPC::LSWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_lswi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 5396 /* lvebx */, PPC::LVEBX, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lvebx, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5402 /* lvehx */, PPC::LVEHX, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lvehx, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5408 /* lvewx */, PPC::LVEWX, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lvewx, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5414 /* lvsl */, PPC::LVSL, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lvsl, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5419 /* lvsr */, PPC::LVSR, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lvsr, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5424 /* lvx */, PPC::LVX, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lvx, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5428 /* lvxl */, PPC::LVXL, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lvxl, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5433 /* lwa */, PPC::LWA, Convert__RegG8RC1_1__DispRIX1_2__RegGxRCNoR01_3, 0, { MCK_lwa, MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 5437 /* lwarx */, PPC::LWARX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lwarx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5437 /* lwarx */, PPC::LWARXL, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lwarx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC, MCK_1 }, },
  { 5443 /* lwaux */, PPC::LWAUX, Convert__RegG8RC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lwaux, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5449 /* lwax */, PPC::LWAX, Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lwax, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5454 /* lwbrx */, PPC::LWBRX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lwbrx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5460 /* lwsync */, PPC::SYNC, Convert__imm_95_1, 0, { MCK_lwsync }, },
  { 5467 /* lwz */, PPC::LWZ, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lwz, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5471 /* lwzcix */, PPC::LWZCIX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_lwzcix, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 5478 /* lwzu */, PPC::LWZU, Convert__RegGPRC1_1__imm_95_0__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_lwzu, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 5483 /* lwzux */, PPC::LWZUX, Convert__RegGPRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lwzux, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5489 /* lwzx */, PPC::LWZX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lwzx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5494 /* lxsdx */, PPC::LXSDX, Convert__RegVSFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lxsdx, MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5500 /* lxsiwax */, PPC::LXSIWAX, Convert__RegVSFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lxsiwax, MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5508 /* lxsiwzx */, PPC::LXSIWZX, Convert__RegVSFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lxsiwzx, MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5516 /* lxsspx */, PPC::LXSSPX, Convert__RegVSSRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lxsspx, MCK_RegVSSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5523 /* lxvd2x */, PPC::LXVD2X, Convert__RegVSRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lxvd2x, MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5530 /* lxvdsx */, PPC::LXVDSX, Convert__RegVSRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lxvdsx, MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5537 /* lxvw4x */, PPC::LXVW4X, Convert__RegVSRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_lxvw4x, MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 5544 /* mbar */, PPC::MBAR, Convert__imm_95_0, 0, { MCK_mbar }, },
  { 5544 /* mbar */, PPC::MBAR, Convert__U5Imm1_1, 0, { MCK_mbar, MCK_U5Imm }, },
  { 5549 /* mcrf */, PPC::MCRF, Convert__RegCRRC1_1__RegCRRC1_2, 0, { MCK_mcrf, MCK_RegCRRC, MCK_RegCRRC }, },
  { 5554 /* mcrfs */, PPC::MCRFS, Convert__RegCRRC1_1__RegCRRC1_2, 0, { MCK_mcrfs, MCK_RegCRRC, MCK_RegCRRC }, },
  { 5560 /* mfamr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_29, 0, { MCK_mfamr, MCK_RegGPRC }, },
  { 5566 /* mfasr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_280, 0, { MCK_mfasr, MCK_RegGPRC }, },
  { 5572 /* mfbhrbe */, PPC::MFBHRBE, Convert__RegGPRC1_1__U10Imm1_2__imm_95_0, 0, { MCK_mfbhrbe, MCK_RegGPRC, MCK_U10Imm }, },
  { 5580 /* mfbr0 */, PPC::MFDCR, Convert__RegGPRC1_1__imm_95_128, 0, { MCK_mfbr0, MCK_RegGPRC }, },
  { 5586 /* mfbr1 */, PPC::MFDCR, Convert__RegGPRC1_1__imm_95_129, 0, { MCK_mfbr1, MCK_RegGPRC }, },
  { 5592 /* mfbr2 */, PPC::MFDCR, Convert__RegGPRC1_1__imm_95_130, 0, { MCK_mfbr2, MCK_RegGPRC }, },
  { 5598 /* mfbr3 */, PPC::MFDCR, Convert__RegGPRC1_1__imm_95_131, 0, { MCK_mfbr3, MCK_RegGPRC }, },
  { 5604 /* mfbr4 */, PPC::MFDCR, Convert__RegGPRC1_1__imm_95_132, 0, { MCK_mfbr4, MCK_RegGPRC }, },
  { 5610 /* mfbr5 */, PPC::MFDCR, Convert__RegGPRC1_1__imm_95_133, 0, { MCK_mfbr5, MCK_RegGPRC }, },
  { 5616 /* mfbr6 */, PPC::MFDCR, Convert__RegGPRC1_1__imm_95_134, 0, { MCK_mfbr6, MCK_RegGPRC }, },
  { 5622 /* mfbr7 */, PPC::MFDCR, Convert__RegGPRC1_1__imm_95_135, 0, { MCK_mfbr7, MCK_RegGPRC }, },
  { 5628 /* mfcfar */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_28, 0, { MCK_mfcfar, MCK_RegGPRC }, },
  { 5635 /* mfcr */, PPC::MFCR, Convert__RegGPRC1_1, 0, { MCK_mfcr, MCK_RegGPRC }, },
  { 5640 /* mfctr */, PPC::MFCTR, Convert__RegGPRC1_1, 0, { MCK_mfctr, MCK_RegGPRC }, },
  { 5646 /* mfdar */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_19, 0, { MCK_mfdar, MCK_RegGPRC }, },
  { 5652 /* mfdbatl */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_537, 0, { MCK_mfdbatl, MCK_RegGPRC, MCK_0 }, },
  { 5652 /* mfdbatl */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_539, 0, { MCK_mfdbatl, MCK_RegGPRC, MCK_1 }, },
  { 5652 /* mfdbatl */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_541, 0, { MCK_mfdbatl, MCK_RegGPRC, MCK_2 }, },
  { 5652 /* mfdbatl */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_543, 0, { MCK_mfdbatl, MCK_RegGPRC, MCK_3 }, },
  { 5660 /* mfdbatu */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_536, 0, { MCK_mfdbatu, MCK_RegGPRC, MCK_0 }, },
  { 5660 /* mfdbatu */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_538, 0, { MCK_mfdbatu, MCK_RegGPRC, MCK_1 }, },
  { 5660 /* mfdbatu */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_540, 0, { MCK_mfdbatu, MCK_RegGPRC, MCK_2 }, },
  { 5660 /* mfdbatu */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_542, 0, { MCK_mfdbatu, MCK_RegGPRC, MCK_3 }, },
  { 5668 /* mfdccr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_1018, 0, { MCK_mfdccr, MCK_RegGPRC }, },
  { 5675 /* mfdcr */, PPC::MFDCR, Convert__RegGPRC1_1__Imm1_2, 0, { MCK_mfdcr, MCK_RegGPRC, MCK_Imm }, },
  { 5681 /* mfdear */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_981, 0, { MCK_mfdear, MCK_RegGPRC }, },
  { 5688 /* mfdec */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_22, 0, { MCK_mfdec, MCK_RegGPRC }, },
  { 5688 /* mfdec */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_22, 0, { MCK_mfdec, MCK_RegGPRC }, },
  { 5694 /* mfdscr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_17, 0, { MCK_mfdscr, MCK_RegGPRC }, },
  { 5701 /* mfdsisr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_18, 0, { MCK_mfdsisr, MCK_RegGPRC }, },
  { 5709 /* mfesr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_980, 0, { MCK_mfesr, MCK_RegGPRC }, },
  { 5715 /* mffs */, PPC::MFFS, Convert__RegF8RC1_1, 0, { MCK_mffs, MCK_RegF8RC }, },
  { 5715 /* mffs */, PPC::MFFSo, Convert__RegF8RC1_2, 0, { MCK_mffs, MCK__DOT_, MCK_RegF8RC }, },
  { 5720 /* mfibatl */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_529, 0, { MCK_mfibatl, MCK_RegGPRC, MCK_0 }, },
  { 5720 /* mfibatl */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_531, 0, { MCK_mfibatl, MCK_RegGPRC, MCK_1 }, },
  { 5720 /* mfibatl */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_533, 0, { MCK_mfibatl, MCK_RegGPRC, MCK_2 }, },
  { 5720 /* mfibatl */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_535, 0, { MCK_mfibatl, MCK_RegGPRC, MCK_3 }, },
  { 5728 /* mfibatu */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_528, 0, { MCK_mfibatu, MCK_RegGPRC, MCK_0 }, },
  { 5728 /* mfibatu */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_530, 0, { MCK_mfibatu, MCK_RegGPRC, MCK_1 }, },
  { 5728 /* mfibatu */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_532, 0, { MCK_mfibatu, MCK_RegGPRC, MCK_2 }, },
  { 5728 /* mfibatu */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_534, 0, { MCK_mfibatu, MCK_RegGPRC, MCK_3 }, },
  { 5736 /* mficcr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_1019, 0, { MCK_mficcr, MCK_RegGPRC }, },
  { 5743 /* mflr */, PPC::MFLR, Convert__RegGPRC1_1, 0, { MCK_mflr, MCK_RegGPRC }, },
  { 5748 /* mfmsr */, PPC::MFMSR, Convert__RegGPRC1_1, 0, { MCK_mfmsr, MCK_RegGPRC }, },
  { 5754 /* mfocrf */, PPC::MFOCRF, Convert__RegGPRC1_1__CRBitMask1_2, 0, { MCK_mfocrf, MCK_RegGPRC, MCK_CRBitMask }, },
  { 5761 /* mfpid */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_48, 0, { MCK_mfpid, MCK_RegGPRC }, },
  { 5767 /* mfpvr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_287, 0, { MCK_mfpvr, MCK_RegGPRC }, },
  { 5773 /* mfrtcl */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_5, 0, { MCK_mfrtcl, MCK_RegGPRC }, },
  { 5780 /* mfrtcu */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_4, 0, { MCK_mfrtcu, MCK_RegGPRC }, },
  { 5787 /* mfsdr1 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_25, 0, { MCK_mfsdr1, MCK_RegGPRC }, },
  { 5787 /* mfsdr1 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_25, 0, { MCK_mfsdr1, MCK_RegGPRC }, },
  { 5794 /* mfspefscr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_512, 0, { MCK_mfspefscr, MCK_RegGPRC }, },
  { 5804 /* mfspr */, PPC::MFSPR, Convert__RegGPRC1_1__Imm1_2, 0, { MCK_mfspr, MCK_RegGPRC, MCK_Imm }, },
  { 5810 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_272, 0, { MCK_mfsprg, MCK_RegGPRC, MCK_0 }, },
  { 5810 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_273, 0, { MCK_mfsprg, MCK_RegGPRC, MCK_1 }, },
  { 5810 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_274, 0, { MCK_mfsprg, MCK_RegGPRC, MCK_2 }, },
  { 5810 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_275, 0, { MCK_mfsprg, MCK_RegGPRC, MCK_3 }, },
  { 5810 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_260, 0, { MCK_mfsprg, MCK_RegGPRC, MCK_4 }, },
  { 5810 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_261, 0, { MCK_mfsprg, MCK_RegGPRC, MCK_5 }, },
  { 5810 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_262, 0, { MCK_mfsprg, MCK_RegGPRC, MCK_6 }, },
  { 5810 /* mfsprg */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_263, 0, { MCK_mfsprg, MCK_RegGPRC, MCK_7 }, },
  { 5817 /* mfsprg0 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_272, 0, { MCK_mfsprg0, MCK_RegGPRC }, },
  { 5825 /* mfsprg1 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_273, 0, { MCK_mfsprg1, MCK_RegGPRC }, },
  { 5833 /* mfsprg2 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_274, 0, { MCK_mfsprg2, MCK_RegGPRC }, },
  { 5841 /* mfsprg3 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_275, 0, { MCK_mfsprg3, MCK_RegGPRC }, },
  { 5849 /* mfsprg4 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_260, 0, { MCK_mfsprg4, MCK_RegGPRC }, },
  { 5857 /* mfsprg5 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_261, 0, { MCK_mfsprg5, MCK_RegGPRC }, },
  { 5865 /* mfsprg6 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_262, 0, { MCK_mfsprg6, MCK_RegGPRC }, },
  { 5873 /* mfsprg7 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_263, 0, { MCK_mfsprg7, MCK_RegGPRC }, },
  { 5881 /* mfsr */, PPC::MFSR, Convert__RegGPRC1_1__U4Imm1_2, 0, { MCK_mfsr, MCK_RegGPRC, MCK_U4Imm }, },
  { 5886 /* mfsrin */, PPC::MFSRIN, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_mfsrin, MCK_RegGPRC, MCK_RegGPRC }, },
  { 5893 /* mfsrr0 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_26, 0, { MCK_mfsrr0, MCK_RegGPRC }, },
  { 5893 /* mfsrr0 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_26, 0, { MCK_mfsrr0, MCK_RegGPRC }, },
  { 5900 /* mfsrr1 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_27, 0, { MCK_mfsrr1, MCK_RegGPRC }, },
  { 5900 /* mfsrr1 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_27, 0, { MCK_mfsrr1, MCK_RegGPRC }, },
  { 5907 /* mfsrr2 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_990, 0, { MCK_mfsrr2, MCK_RegGPRC }, },
  { 5914 /* mfsrr3 */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_991, 0, { MCK_mfsrr3, MCK_RegGPRC }, },
  { 5921 /* mftb */, PPC::MFTB, Convert__RegGPRC1_1__imm_95_268, 0, { MCK_mftb, MCK_RegGPRC }, },
  { 5921 /* mftb */, PPC::MFTB, Convert__RegGPRC1_1__Imm1_2, 0, { MCK_mftb, MCK_RegGPRC, MCK_Imm }, },
  { 5926 /* mftbhi */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_988, 0, { MCK_mftbhi, MCK_RegGPRC }, },
  { 5933 /* mftbl */, PPC::MFTB, Convert__RegGPRC1_1__imm_95_268, 0, { MCK_mftbl, MCK_RegGPRC }, },
  { 5939 /* mftblo */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_989, 0, { MCK_mftblo, MCK_RegGPRC }, },
  { 5946 /* mftbu */, PPC::MFTB, Convert__RegGPRC1_1__imm_95_269, 0, { MCK_mftbu, MCK_RegGPRC }, },
  { 5952 /* mftcr */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_986, 0, { MCK_mftcr, MCK_RegGPRC }, },
  { 5958 /* mfvscr */, PPC::MFVSCR, Convert__RegVRRC1_1, 0, { MCK_mfvscr, MCK_RegVRRC }, },
  { 5965 /* mfvsrd */, PPC::MFVSRD, Convert__RegG8RC1_1__RegVSFRC1_2, 0, { MCK_mfvsrd, MCK_RegG8RC, MCK_RegVSFRC }, },
  { 5972 /* mfvsrwz */, PPC::MFVSRWZ, Convert__RegGPRC1_1__RegVSFRC1_2, 0, { MCK_mfvsrwz, MCK_RegGPRC, MCK_RegVSFRC }, },
  { 5980 /* mfxer */, PPC::MFSPR, Convert__RegGPRC1_1__imm_95_1, 0, { MCK_mfxer, MCK_RegGPRC }, },
  { 5986 /* mr */, PPC::OR8, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_2, 0, { MCK_mr, MCK_RegG8RC, MCK_RegG8RC }, },
  { 5986 /* mr */, PPC::OR8o, Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_3, 0, { MCK_mr, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 5989 /* msync */, PPC::SYNC, Convert__imm_95_0, 0, { MCK_msync }, },
  { 5995 /* mtamr */, PPC::MTSPR, Convert__imm_95_29__RegGPRC1_1, 0, { MCK_mtamr, MCK_RegGPRC }, },
  { 6001 /* mtasr */, PPC::MTSPR, Convert__imm_95_280__RegGPRC1_1, 0, { MCK_mtasr, MCK_RegGPRC }, },
  { 6001 /* mtasr */, PPC::MTSPR, Convert__imm_95_280__RegGPRC1_1, 0, { MCK_mtasr, MCK_RegGPRC }, },
  { 6007 /* mtbr0 */, PPC::MTDCR, Convert__RegGPRC1_1__imm_95_128, 0, { MCK_mtbr0, MCK_RegGPRC }, },
  { 6013 /* mtbr1 */, PPC::MTDCR, Convert__RegGPRC1_1__imm_95_129, 0, { MCK_mtbr1, MCK_RegGPRC }, },
  { 6019 /* mtbr2 */, PPC::MTDCR, Convert__RegGPRC1_1__imm_95_130, 0, { MCK_mtbr2, MCK_RegGPRC }, },
  { 6025 /* mtbr3 */, PPC::MTDCR, Convert__RegGPRC1_1__imm_95_131, 0, { MCK_mtbr3, MCK_RegGPRC }, },
  { 6031 /* mtbr4 */, PPC::MTDCR, Convert__RegGPRC1_1__imm_95_132, 0, { MCK_mtbr4, MCK_RegGPRC }, },
  { 6037 /* mtbr5 */, PPC::MTDCR, Convert__RegGPRC1_1__imm_95_133, 0, { MCK_mtbr5, MCK_RegGPRC }, },
  { 6043 /* mtbr6 */, PPC::MTDCR, Convert__RegGPRC1_1__imm_95_134, 0, { MCK_mtbr6, MCK_RegGPRC }, },
  { 6049 /* mtbr7 */, PPC::MTDCR, Convert__RegGPRC1_1__imm_95_135, 0, { MCK_mtbr7, MCK_RegGPRC }, },
  { 6055 /* mtcfar */, PPC::MTSPR, Convert__imm_95_28__RegGPRC1_1, 0, { MCK_mtcfar, MCK_RegGPRC }, },
  { 6062 /* mtcr */, PPC::MTCRF8, Convert__imm_95_255__RegG8RC1_1, 0, { MCK_mtcr, MCK_RegG8RC }, },
  { 6067 /* mtcrf */, PPC::MTCRF, Convert__Imm1_1__RegGPRC1_2, 0, { MCK_mtcrf, MCK_Imm, MCK_RegGPRC }, },
  { 6073 /* mtctr */, PPC::MTCTR, Convert__RegGPRC1_1, 0, { MCK_mtctr, MCK_RegGPRC }, },
  { 6079 /* mtdar */, PPC::MTSPR, Convert__imm_95_19__RegGPRC1_1, 0, { MCK_mtdar, MCK_RegGPRC }, },
  { 6085 /* mtdbatl */, PPC::MTSPR, Convert__imm_95_537__RegGPRC1_2, 0, { MCK_mtdbatl, MCK_0, MCK_RegGPRC }, },
  { 6085 /* mtdbatl */, PPC::MTSPR, Convert__imm_95_539__RegGPRC1_2, 0, { MCK_mtdbatl, MCK_1, MCK_RegGPRC }, },
  { 6085 /* mtdbatl */, PPC::MTSPR, Convert__imm_95_541__RegGPRC1_2, 0, { MCK_mtdbatl, MCK_2, MCK_RegGPRC }, },
  { 6085 /* mtdbatl */, PPC::MTSPR, Convert__imm_95_543__RegGPRC1_2, 0, { MCK_mtdbatl, MCK_3, MCK_RegGPRC }, },
  { 6093 /* mtdbatu */, PPC::MTSPR, Convert__imm_95_536__RegGPRC1_2, 0, { MCK_mtdbatu, MCK_0, MCK_RegGPRC }, },
  { 6093 /* mtdbatu */, PPC::MTSPR, Convert__imm_95_538__RegGPRC1_2, 0, { MCK_mtdbatu, MCK_1, MCK_RegGPRC }, },
  { 6093 /* mtdbatu */, PPC::MTSPR, Convert__imm_95_540__RegGPRC1_2, 0, { MCK_mtdbatu, MCK_2, MCK_RegGPRC }, },
  { 6093 /* mtdbatu */, PPC::MTSPR, Convert__imm_95_542__RegGPRC1_2, 0, { MCK_mtdbatu, MCK_3, MCK_RegGPRC }, },
  { 6101 /* mtdccr */, PPC::MTSPR, Convert__imm_95_1018__RegGPRC1_1, 0, { MCK_mtdccr, MCK_RegGPRC }, },
  { 6108 /* mtdcr */, PPC::MTDCR, Convert__RegGPRC1_2__Imm1_1, 0, { MCK_mtdcr, MCK_Imm, MCK_RegGPRC }, },
  { 6114 /* mtdear */, PPC::MTSPR, Convert__imm_95_981__RegGPRC1_1, 0, { MCK_mtdear, MCK_RegGPRC }, },
  { 6121 /* mtdec */, PPC::MTSPR, Convert__imm_95_22__RegGPRC1_1, 0, { MCK_mtdec, MCK_RegGPRC }, },
  { 6121 /* mtdec */, PPC::MTSPR, Convert__imm_95_22__RegGPRC1_1, 0, { MCK_mtdec, MCK_RegGPRC }, },
  { 6127 /* mtdscr */, PPC::MTSPR, Convert__imm_95_17__RegGPRC1_1, 0, { MCK_mtdscr, MCK_RegGPRC }, },
  { 6134 /* mtdsisr */, PPC::MTSPR, Convert__imm_95_18__RegGPRC1_1, 0, { MCK_mtdsisr, MCK_RegGPRC }, },
  { 6142 /* mtesr */, PPC::MTSPR, Convert__imm_95_980__RegGPRC1_1, 0, { MCK_mtesr, MCK_RegGPRC }, },
  { 6148 /* mtfsb0 */, PPC::MTFSB0, Convert__U5Imm1_1, 0, { MCK_mtfsb0, MCK_U5Imm }, },
  { 6155 /* mtfsb1 */, PPC::MTFSB1, Convert__U5Imm1_1, 0, { MCK_mtfsb1, MCK_U5Imm }, },
  { 6162 /* mtfsf */, PPC::MTFSF, Convert__Imm1_1__RegF8RC1_2__imm_95_0__imm_95_0, 0, { MCK_mtfsf, MCK_Imm, MCK_RegF8RC }, },
  { 6162 /* mtfsf */, PPC::MTFSFo, Convert__Imm1_2__RegF8RC1_3__imm_95_0__imm_95_0, 0, { MCK_mtfsf, MCK__DOT_, MCK_Imm, MCK_RegF8RC }, },
  { 6162 /* mtfsf */, PPC::MTFSF, Convert__Imm1_1__RegF8RC1_2__Imm1_3__Imm1_4, 0, { MCK_mtfsf, MCK_Imm, MCK_RegF8RC, MCK_Imm, MCK_Imm }, },
  { 6162 /* mtfsf */, PPC::MTFSFo, Convert__Imm1_2__RegF8RC1_3__Imm1_4__Imm1_5, 0, { MCK_mtfsf, MCK__DOT_, MCK_Imm, MCK_RegF8RC, MCK_Imm, MCK_Imm }, },
  { 6168 /* mtfsfi */, PPC::MTFSFI, Convert__RegCRRC1_1__Imm1_2__imm_95_0, 0, { MCK_mtfsfi, MCK_RegCRRC, MCK_Imm }, },
  { 6168 /* mtfsfi */, PPC::MTFSFIo, Convert__RegCRRC1_2__Imm1_3__imm_95_0, 0, { MCK_mtfsfi, MCK__DOT_, MCK_RegCRRC, MCK_Imm }, },
  { 6168 /* mtfsfi */, PPC::MTFSFI, Convert__RegCRRC1_1__Imm1_2__Imm1_3, 0, { MCK_mtfsfi, MCK_RegCRRC, MCK_Imm, MCK_Imm }, },
  { 6168 /* mtfsfi */, PPC::MTFSFIo, Convert__RegCRRC1_2__Imm1_3__Imm1_4, 0, { MCK_mtfsfi, MCK__DOT_, MCK_RegCRRC, MCK_Imm, MCK_Imm }, },
  { 6175 /* mtibatl */, PPC::MTSPR, Convert__imm_95_529__RegGPRC1_2, 0, { MCK_mtibatl, MCK_0, MCK_RegGPRC }, },
  { 6175 /* mtibatl */, PPC::MTSPR, Convert__imm_95_531__RegGPRC1_2, 0, { MCK_mtibatl, MCK_1, MCK_RegGPRC }, },
  { 6175 /* mtibatl */, PPC::MTSPR, Convert__imm_95_533__RegGPRC1_2, 0, { MCK_mtibatl, MCK_2, MCK_RegGPRC }, },
  { 6175 /* mtibatl */, PPC::MTSPR, Convert__imm_95_535__RegGPRC1_2, 0, { MCK_mtibatl, MCK_3, MCK_RegGPRC }, },
  { 6183 /* mtibatu */, PPC::MTSPR, Convert__imm_95_528__RegGPRC1_2, 0, { MCK_mtibatu, MCK_0, MCK_RegGPRC }, },
  { 6183 /* mtibatu */, PPC::MTSPR, Convert__imm_95_530__RegGPRC1_2, 0, { MCK_mtibatu, MCK_1, MCK_RegGPRC }, },
  { 6183 /* mtibatu */, PPC::MTSPR, Convert__imm_95_532__RegGPRC1_2, 0, { MCK_mtibatu, MCK_2, MCK_RegGPRC }, },
  { 6183 /* mtibatu */, PPC::MTSPR, Convert__imm_95_534__RegGPRC1_2, 0, { MCK_mtibatu, MCK_3, MCK_RegGPRC }, },
  { 6191 /* mticcr */, PPC::MTSPR, Convert__imm_95_1019__RegGPRC1_1, 0, { MCK_mticcr, MCK_RegGPRC }, },
  { 6198 /* mtlr */, PPC::MTLR, Convert__RegGPRC1_1, 0, { MCK_mtlr, MCK_RegGPRC }, },
  { 6203 /* mtmsr */, PPC::MTMSR, Convert__RegGPRC1_1__imm_95_0, 0, { MCK_mtmsr, MCK_RegGPRC }, },
  { 6203 /* mtmsr */, PPC::MTMSR, Convert__RegGPRC1_1__Imm1_2, 0, { MCK_mtmsr, MCK_RegGPRC, MCK_Imm }, },
  { 6209 /* mtmsrd */, PPC::MTMSRD, Convert__RegGPRC1_1__imm_95_0, 0, { MCK_mtmsrd, MCK_RegGPRC }, },
  { 6209 /* mtmsrd */, PPC::MTMSRD, Convert__RegGPRC1_1__Imm1_2, 0, { MCK_mtmsrd, MCK_RegGPRC, MCK_Imm }, },
  { 6216 /* mtocrf */, PPC::MTOCRF, Convert__CRBitMask1_1__RegGPRC1_2, 0, { MCK_mtocrf, MCK_CRBitMask, MCK_RegGPRC }, },
  { 6223 /* mtpid */, PPC::MTSPR, Convert__imm_95_48__RegGPRC1_1, 0, { MCK_mtpid, MCK_RegGPRC }, },
  { 6229 /* mtsdr1 */, PPC::MTSPR, Convert__imm_95_25__RegGPRC1_1, 0, { MCK_mtsdr1, MCK_RegGPRC }, },
  { 6229 /* mtsdr1 */, PPC::MTSPR, Convert__imm_95_25__RegGPRC1_1, 0, { MCK_mtsdr1, MCK_RegGPRC }, },
  { 6236 /* mtspefscr */, PPC::MTSPR, Convert__imm_95_512__RegGPRC1_1, 0, { MCK_mtspefscr, MCK_RegGPRC }, },
  { 6246 /* mtspr */, PPC::MTSPR, Convert__Imm1_1__RegGPRC1_2, 0, { MCK_mtspr, MCK_Imm, MCK_RegGPRC }, },
  { 6252 /* mtsprg */, PPC::MTSPR, Convert__imm_95_272__RegGPRC1_2, 0, { MCK_mtsprg, MCK_0, MCK_RegGPRC }, },
  { 6252 /* mtsprg */, PPC::MTSPR, Convert__imm_95_273__RegGPRC1_2, 0, { MCK_mtsprg, MCK_1, MCK_RegGPRC }, },
  { 6252 /* mtsprg */, PPC::MTSPR, Convert__imm_95_274__RegGPRC1_2, 0, { MCK_mtsprg, MCK_2, MCK_RegGPRC }, },
  { 6252 /* mtsprg */, PPC::MTSPR, Convert__imm_95_275__RegGPRC1_2, 0, { MCK_mtsprg, MCK_3, MCK_RegGPRC }, },
  { 6252 /* mtsprg */, PPC::MTSPR, Convert__imm_95_260__RegGPRC1_2, 0, { MCK_mtsprg, MCK_4, MCK_RegGPRC }, },
  { 6252 /* mtsprg */, PPC::MTSPR, Convert__imm_95_261__RegGPRC1_2, 0, { MCK_mtsprg, MCK_5, MCK_RegGPRC }, },
  { 6252 /* mtsprg */, PPC::MTSPR, Convert__imm_95_262__RegGPRC1_2, 0, { MCK_mtsprg, MCK_6, MCK_RegGPRC }, },
  { 6252 /* mtsprg */, PPC::MTSPR, Convert__imm_95_263__RegGPRC1_2, 0, { MCK_mtsprg, MCK_7, MCK_RegGPRC }, },
  { 6259 /* mtsprg0 */, PPC::MTSPR, Convert__imm_95_272__RegGPRC1_1, 0, { MCK_mtsprg0, MCK_RegGPRC }, },
  { 6267 /* mtsprg1 */, PPC::MTSPR, Convert__imm_95_273__RegGPRC1_1, 0, { MCK_mtsprg1, MCK_RegGPRC }, },
  { 6275 /* mtsprg2 */, PPC::MTSPR, Convert__imm_95_274__RegGPRC1_1, 0, { MCK_mtsprg2, MCK_RegGPRC }, },
  { 6283 /* mtsprg3 */, PPC::MTSPR, Convert__imm_95_275__RegGPRC1_1, 0, { MCK_mtsprg3, MCK_RegGPRC }, },
  { 6291 /* mtsprg4 */, PPC::MTSPR, Convert__imm_95_260__RegGPRC1_1, 0, { MCK_mtsprg4, MCK_RegGPRC }, },
  { 6299 /* mtsprg5 */, PPC::MTSPR, Convert__imm_95_261__RegGPRC1_1, 0, { MCK_mtsprg5, MCK_RegGPRC }, },
  { 6307 /* mtsprg6 */, PPC::MTSPR, Convert__imm_95_262__RegGPRC1_1, 0, { MCK_mtsprg6, MCK_RegGPRC }, },
  { 6315 /* mtsprg7 */, PPC::MTSPR, Convert__imm_95_263__RegGPRC1_1, 0, { MCK_mtsprg7, MCK_RegGPRC }, },
  { 6323 /* mtsr */, PPC::MTSR, Convert__RegGPRC1_2__U4Imm1_1, 0, { MCK_mtsr, MCK_U4Imm, MCK_RegGPRC }, },
  { 6328 /* mtsrin */, PPC::MTSRIN, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_mtsrin, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6335 /* mtsrr0 */, PPC::MTSPR, Convert__imm_95_26__RegGPRC1_1, 0, { MCK_mtsrr0, MCK_RegGPRC }, },
  { 6335 /* mtsrr0 */, PPC::MTSPR, Convert__imm_95_26__RegGPRC1_1, 0, { MCK_mtsrr0, MCK_RegGPRC }, },
  { 6342 /* mtsrr1 */, PPC::MTSPR, Convert__imm_95_27__RegGPRC1_1, 0, { MCK_mtsrr1, MCK_RegGPRC }, },
  { 6342 /* mtsrr1 */, PPC::MTSPR, Convert__imm_95_27__RegGPRC1_1, 0, { MCK_mtsrr1, MCK_RegGPRC }, },
  { 6349 /* mtsrr2 */, PPC::MTSPR, Convert__imm_95_990__RegGPRC1_1, 0, { MCK_mtsrr2, MCK_RegGPRC }, },
  { 6356 /* mtsrr3 */, PPC::MTSPR, Convert__imm_95_991__RegGPRC1_1, 0, { MCK_mtsrr3, MCK_RegGPRC }, },
  { 6363 /* mttbhi */, PPC::MTSPR, Convert__imm_95_988__RegGPRC1_1, 0, { MCK_mttbhi, MCK_RegGPRC }, },
  { 6370 /* mttbl */, PPC::MTSPR, Convert__imm_95_284__RegGPRC1_1, 0, { MCK_mttbl, MCK_RegGPRC }, },
  { 6376 /* mttblo */, PPC::MTSPR, Convert__imm_95_989__RegGPRC1_1, 0, { MCK_mttblo, MCK_RegGPRC }, },
  { 6383 /* mttbu */, PPC::MTSPR, Convert__imm_95_285__RegGPRC1_1, 0, { MCK_mttbu, MCK_RegGPRC }, },
  { 6389 /* mttcr */, PPC::MTSPR, Convert__imm_95_986__RegGPRC1_1, 0, { MCK_mttcr, MCK_RegGPRC }, },
  { 6395 /* mtvscr */, PPC::MTVSCR, Convert__RegVRRC1_1, 0, { MCK_mtvscr, MCK_RegVRRC }, },
  { 6402 /* mtvsrd */, PPC::MTVSRD, Convert__RegVSFRC1_1__RegG8RC1_2, 0, { MCK_mtvsrd, MCK_RegVSFRC, MCK_RegG8RC }, },
  { 6409 /* mtvsrwa */, PPC::MTVSRWA, Convert__RegVSFRC1_1__RegGPRC1_2, 0, { MCK_mtvsrwa, MCK_RegVSFRC, MCK_RegGPRC }, },
  { 6417 /* mtvsrwz */, PPC::MTVSRWZ, Convert__RegVSFRC1_1__RegGPRC1_2, 0, { MCK_mtvsrwz, MCK_RegVSFRC, MCK_RegGPRC }, },
  { 6425 /* mtxer */, PPC::MTSPR, Convert__imm_95_1__RegGPRC1_1, 0, { MCK_mtxer, MCK_RegGPRC }, },
  { 6431 /* mulhd */, PPC::MULHD, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_mulhd, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6431 /* mulhd */, PPC::MULHDo, Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_4, 0, { MCK_mulhd, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6437 /* mulhdu */, PPC::MULHDU, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_mulhdu, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6437 /* mulhdu */, PPC::MULHDUo, Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_4, 0, { MCK_mulhdu, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6444 /* mulhw */, PPC::MULHW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_mulhw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6444 /* mulhw */, PPC::MULHWo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_mulhw, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6450 /* mulhwu */, PPC::MULHWU, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_mulhwu, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6450 /* mulhwu */, PPC::MULHWUo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_mulhwu, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6457 /* mulld */, PPC::MULLD, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_mulld, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6457 /* mulld */, PPC::MULLDo, Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_4, 0, { MCK_mulld, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6463 /* mulli */, PPC::MULLI, Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3, 0, { MCK_mulli, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 6469 /* mullw */, PPC::MULLW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_mullw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6469 /* mullw */, PPC::MULLWo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_mullw, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6475 /* nand */, PPC::NAND, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_nand, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6475 /* nand */, PPC::NANDo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_nand, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6480 /* neg */, PPC::NEG, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_neg, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6480 /* neg */, PPC::NEGo, Convert__RegGPRC1_2__RegGPRC1_3, 0, { MCK_neg, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6484 /* nop */, PPC::NOP, Convert_NoOperands, 0, { MCK_nop }, },
  { 6488 /* nor */, PPC::NOR, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_nor, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6488 /* nor */, PPC::NORo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_nor, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6492 /* not */, PPC::NOR8, Convert__RegG8RC1_1__RegG8RC1_2__RegG8RC1_2, 0, { MCK_not, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6492 /* not */, PPC::NOR8o, Convert__RegG8RC1_2__RegG8RC1_3__RegG8RC1_3, 0, { MCK_not, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6496 /* or */, PPC::OR, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_or, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6496 /* or */, PPC::ORo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_or, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6499 /* orc */, PPC::ORC, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_orc, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6499 /* orc */, PPC::ORCo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_orc, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6503 /* ori */, PPC::ORI, Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3, 0, { MCK_ori, MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 6507 /* oris */, PPC::ORIS, Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3, 0, { MCK_oris, MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 6512 /* popcntd */, PPC::POPCNTD, Convert__RegG8RC1_1__RegG8RC1_2, 0, { MCK_popcntd, MCK_RegG8RC, MCK_RegG8RC }, },
  { 6520 /* popcntw */, PPC::POPCNTW, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_popcntw, MCK_RegGPRC, MCK_RegGPRC }, },
  { 6528 /* ptesync */, PPC::SYNC, Convert__imm_95_2, 0, { MCK_ptesync }, },
  { 6536 /* qvaligni */, PPC::QVALIGNI, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3__U2Imm1_4, 0, { MCK_qvaligni, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_U2Imm }, },
  { 6545 /* qvesplati */, PPC::QVESPLATI, Convert__RegQFRC1_1__RegQFRC1_2__U2Imm1_3, 0, { MCK_qvesplati, MCK_RegQFRC, MCK_RegQFRC, MCK_U2Imm }, },
  { 6555 /* qvfabs */, PPC::QVFABS, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfabs, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6562 /* qvfadd */, PPC::QVFADD, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvfadd, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6569 /* qvfadds */, PPC::QVFADDSs, Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3, 0, { MCK_qvfadds, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 6577 /* qvfand */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_1, 0, { MCK_qvfand, MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 6584 /* qvfandc */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_4, 0, { MCK_qvfandc, MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 6592 /* qvfcfid */, PPC::QVFCFID, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfcfid, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6600 /* qvfcfids */, PPC::QVFCFIDS, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfcfids, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6609 /* qvfcfidu */, PPC::QVFCFIDU, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfcfidu, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6618 /* qvfcfidus */, PPC::QVFCFIDUS, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfcfidus, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6628 /* qvfclr */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_1__RegQBRC1_1__imm_95_0, 0, { MCK_qvfclr, MCK_RegQBRC }, },
  { 6635 /* qvfcmpeq */, PPC::QVFCMPEQb, Convert__RegQBRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvfcmpeq, MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6644 /* qvfcmpgt */, PPC::QVFCMPGTb, Convert__RegQBRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvfcmpgt, MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6653 /* qvfcmplt */, PPC::QVFCMPLTb, Convert__RegQBRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvfcmplt, MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6662 /* qvfcpsgn */, PPC::QVFCPSGN, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvfcpsgn, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6671 /* qvfctfb */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_2__imm_95_5, 0, { MCK_qvfctfb, MCK_RegQBRC, MCK_RegQBRC }, },
  { 6679 /* qvfctid */, PPC::QVFCTID, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfctid, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6687 /* qvfctidu */, PPC::QVFCTIDU, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfctidu, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6696 /* qvfctiduz */, PPC::QVFCTIDUZ, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfctiduz, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6706 /* qvfctidz */, PPC::QVFCTIDZ, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfctidz, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6715 /* qvfctiw */, PPC::QVFCTIW, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfctiw, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6723 /* qvfctiwu */, PPC::QVFCTIWU, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfctiwu, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6732 /* qvfctiwuz */, PPC::QVFCTIWUZ, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfctiwuz, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6742 /* qvfctiwz */, PPC::QVFCTIWZ, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfctiwz, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6751 /* qvfequ */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_9, 0, { MCK_qvfequ, MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 6758 /* qvflogical */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__U12Imm1_4, 0, { MCK_qvflogical, MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC, MCK_U12Imm }, },
  { 6769 /* qvfmadd */, PPC::QVFMADD, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfmadd, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6777 /* qvfmadds */, PPC::QVFMADDSs, Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_4__RegQSRC1_3, 0, { MCK_qvfmadds, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 6786 /* qvfmr */, PPC::QVFMR, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfmr, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6792 /* qvfmsub */, PPC::QVFMSUB, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfmsub, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6800 /* qvfmsubs */, PPC::QVFMSUBSs, Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_4__RegQSRC1_3, 0, { MCK_qvfmsubs, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 6809 /* qvfmul */, PPC::QVFMUL, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvfmul, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6816 /* qvfmuls */, PPC::QVFMULSs, Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3, 0, { MCK_qvfmuls, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 6824 /* qvfnabs */, PPC::QVFNABS, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfnabs, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6832 /* qvfnand */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_14, 0, { MCK_qvfnand, MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 6840 /* qvfneg */, PPC::QVFNEG, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfneg, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6847 /* qvfnmadd */, PPC::QVFNMADD, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfnmadd, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6856 /* qvfnmadds */, PPC::QVFNMADDSs, Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_4__RegQSRC1_3, 0, { MCK_qvfnmadds, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 6866 /* qvfnmsub */, PPC::QVFNMSUB, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfnmsub, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6875 /* qvfnmsubs */, PPC::QVFNMSUBSs, Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_4__RegQSRC1_3, 0, { MCK_qvfnmsubs, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 6885 /* qvfnor */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_8, 0, { MCK_qvfnor, MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 6892 /* qvfnot */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_2__imm_95_10, 0, { MCK_qvfnot, MCK_RegQBRC, MCK_RegQBRC }, },
  { 6899 /* qvfor */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_7, 0, { MCK_qvfor, MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 6905 /* qvforc */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_13, 0, { MCK_qvforc, MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 6912 /* qvfperm */, PPC::QVFPERM, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3__RegQFRC1_4, 0, { MCK_qvfperm, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6920 /* qvfre */, PPC::QVFRE, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfre, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6926 /* qvfres */, PPC::QVFRES, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfres, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6933 /* qvfrim */, PPC::QVFRIM, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfrim, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6940 /* qvfrin */, PPC::QVFRIN, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfrin, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6947 /* qvfrip */, PPC::QVFRIP, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfrip, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6954 /* qvfriz */, PPC::QVFRIZ, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfriz, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6961 /* qvfrsp */, PPC::QVFRSPs, Convert__RegQSRC1_1__RegQFRC1_2, 0, { MCK_qvfrsp, MCK_RegQSRC, MCK_RegQFRC }, },
  { 6968 /* qvfrsqrte */, PPC::QVFRSQRTE, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfrsqrte, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6978 /* qvfrsqrtes */, PPC::QVFRSQRTES, Convert__RegQFRC1_1__RegQFRC1_2, 0, { MCK_qvfrsqrtes, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6989 /* qvfsel */, PPC::QVFSELb, Convert__RegQFRC1_1__RegQBRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfsel, MCK_RegQFRC, MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 6996 /* qvfset */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_1__RegQBRC1_1__imm_95_15, 0, { MCK_qvfset, MCK_RegQBRC }, },
  { 7003 /* qvfsub */, PPC::QVFSUB, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvfsub, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7010 /* qvfsubs */, PPC::QVFSUBSs, Convert__RegQSRC1_1__RegQSRC1_2__RegQSRC1_3, 0, { MCK_qvfsubs, MCK_RegQSRC, MCK_RegQSRC, MCK_RegQSRC }, },
  { 7018 /* qvftstnan */, PPC::QVFTSTNANb, Convert__RegQBRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvftstnan, MCK_RegQBRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7028 /* qvfxmadd */, PPC::QVFXMADD, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfxmadd, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7037 /* qvfxmadds */, PPC::QVFXMADDS, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfxmadds, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7047 /* qvfxmul */, PPC::QVFXMUL, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvfxmul, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7055 /* qvfxmuls */, PPC::QVFXMULS, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_3, 0, { MCK_qvfxmuls, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7064 /* qvfxor */, PPC::QVFLOGICALb, Convert__RegQBRC1_1__RegQBRC1_2__RegQBRC1_3__imm_95_6, 0, { MCK_qvfxor, MCK_RegQBRC, MCK_RegQBRC, MCK_RegQBRC }, },
  { 7071 /* qvfxxcpnmadd */, PPC::QVFXXCPNMADD, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfxxcpnmadd, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7084 /* qvfxxcpnmadds */, PPC::QVFXXCPNMADDS, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfxxcpnmadds, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7098 /* qvfxxmadd */, PPC::QVFXXMADD, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfxxmadd, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7108 /* qvfxxmadds */, PPC::QVFXXMADDS, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfxxmadds, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7119 /* qvfxxnpmadd */, PPC::QVFXXNPMADD, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfxxnpmadd, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7131 /* qvfxxnpmadds */, PPC::QVFXXNPMADDS, Convert__RegQFRC1_1__RegQFRC1_2__RegQFRC1_4__RegQFRC1_3, 0, { MCK_qvfxxnpmadds, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC, MCK_RegQFRC }, },
  { 7144 /* qvgpci */, PPC::QVGPCI, Convert__RegQFRC1_1__U12Imm1_2, 0, { MCK_qvgpci, MCK_RegQFRC, MCK_U12Imm }, },
  { 7151 /* qvlfcdux */, PPC::QVLFCDUX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfcdux, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7160 /* qvlfcduxa */, PPC::QVLFCDUXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfcduxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7170 /* qvlfcdx */, PPC::QVLFCDX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfcdx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7178 /* qvlfcdxa */, PPC::QVLFCDXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfcdxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7187 /* qvlfcsux */, PPC::QVLFCSUX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfcsux, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7196 /* qvlfcsuxa */, PPC::QVLFCSUXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfcsuxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7206 /* qvlfcsx */, PPC::QVLFCSX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfcsx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7214 /* qvlfcsxa */, PPC::QVLFCSXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfcsxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7223 /* qvlfdux */, PPC::QVLFDUX, Convert__RegQFRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfdux, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7231 /* qvlfduxa */, PPC::QVLFDUXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfduxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7240 /* qvlfdx */, PPC::QVLFDX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfdx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7247 /* qvlfdxa */, PPC::QVLFDXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfdxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7255 /* qvlfiwax */, PPC::QVLFIWAX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfiwax, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7264 /* qvlfiwaxa */, PPC::QVLFIWAXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfiwaxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7274 /* qvlfiwzx */, PPC::QVLFIWZX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfiwzx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7283 /* qvlfiwzxa */, PPC::QVLFIWZXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfiwzxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7293 /* qvlfsux */, PPC::QVLFSUX, Convert__RegQSRC1_1__imm_95_0__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfsux, MCK_RegQSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7301 /* qvlfsuxa */, PPC::QVLFSUXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfsuxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7310 /* qvlfsx */, PPC::QVLFSX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfsx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7317 /* qvlfsxa */, PPC::QVLFSXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlfsxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7325 /* qvlpcldx */, PPC::QVLPCLDX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlpcldx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7334 /* qvlpclsx */, PPC::QVLPCLSX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlpclsx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7343 /* qvlpcrdx */, PPC::QVLPCRDX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlpcrdx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7352 /* qvlpcrsx */, PPC::QVLPCRSX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvlpcrsx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7361 /* qvstfcdux */, PPC::QVSTFCDUX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcdux, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7371 /* qvstfcduxa */, PPC::QVSTFCDUXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcduxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7382 /* qvstfcduxi */, PPC::QVSTFCDUXI, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcduxi, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7393 /* qvstfcduxia */, PPC::QVSTFCDUXIA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcduxia, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7405 /* qvstfcdx */, PPC::QVSTFCDX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcdx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7414 /* qvstfcdxa */, PPC::QVSTFCDXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcdxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7424 /* qvstfcdxi */, PPC::QVSTFCDXI, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcdxi, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7434 /* qvstfcdxia */, PPC::QVSTFCDXIA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcdxia, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7445 /* qvstfcsux */, PPC::QVSTFCSUX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcsux, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7455 /* qvstfcsuxa */, PPC::QVSTFCSUXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcsuxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7466 /* qvstfcsuxi */, PPC::QVSTFCSUXI, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcsuxi, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7477 /* qvstfcsuxia */, PPC::QVSTFCSUXIA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcsuxia, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7489 /* qvstfcsx */, PPC::QVSTFCSX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcsx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7498 /* qvstfcsxa */, PPC::QVSTFCSXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcsxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7508 /* qvstfcsxi */, PPC::QVSTFCSXI, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcsxi, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7518 /* qvstfcsxia */, PPC::QVSTFCSXIA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfcsxia, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7529 /* qvstfdux */, PPC::QVSTFDUX, Convert__imm_95_0__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfdux, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7538 /* qvstfduxa */, PPC::QVSTFDUXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfduxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7548 /* qvstfduxi */, PPC::QVSTFDUXI, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfduxi, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7558 /* qvstfduxia */, PPC::QVSTFDUXIA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfduxia, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7569 /* qvstfdx */, PPC::QVSTFDX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfdx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7577 /* qvstfdxa */, PPC::QVSTFDXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfdxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7586 /* qvstfdxi */, PPC::QVSTFDXI, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfdxi, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7595 /* qvstfdxia */, PPC::QVSTFDXIA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfdxia, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7605 /* qvstfiwx */, PPC::QVSTFIWX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfiwx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7614 /* qvstfiwxa */, PPC::QVSTFIWXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfiwxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7624 /* qvstfsux */, PPC::QVSTFSUX, Convert__imm_95_0__RegQSRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfsux, MCK_RegQSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7633 /* qvstfsuxa */, PPC::QVSTFSUXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfsuxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7643 /* qvstfsuxi */, PPC::QVSTFSUXI, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfsuxi, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7653 /* qvstfsuxia */, PPC::QVSTFSUXIA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfsuxia, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7664 /* qvstfsx */, PPC::QVSTFSX, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfsx, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7672 /* qvstfsxa */, PPC::QVSTFSXA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfsxa, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7681 /* qvstfsxi */, PPC::QVSTFSXI, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfsxi, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7690 /* qvstfsxia */, PPC::QVSTFSXIA, Convert__RegQFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_qvstfsxia, MCK_RegQFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7700 /* rfci */, PPC::RFCI, Convert_NoOperands, 0, { MCK_rfci }, },
  { 7705 /* rfdi */, PPC::RFDI, Convert_NoOperands, 0, { MCK_rfdi }, },
  { 7710 /* rfebb */, PPC::RFEBB, Convert__U1Imm1_1, 0, { MCK_rfebb, MCK_U1Imm }, },
  { 7716 /* rfi */, PPC::RFI, Convert_NoOperands, 0, { MCK_rfi }, },
  { 7720 /* rfid */, PPC::RFID, Convert_NoOperands, 0, { MCK_rfid }, },
  { 7725 /* rfmci */, PPC::RFMCI, Convert_NoOperands, 0, { MCK_rfmci }, },
  { 7731 /* rldcl */, PPC::RLDCL, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__U6Imm1_4, 0, { MCK_rldcl, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 7731 /* rldcl */, PPC::RLDCLo, Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4__U6Imm1_5, 0, { MCK_rldcl, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 7737 /* rldcr */, PPC::RLDCR, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__U6Imm1_4, 0, { MCK_rldcr, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 7737 /* rldcr */, PPC::RLDCRo, Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4__U6Imm1_5, 0, { MCK_rldcr, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC, MCK_U6Imm }, },
  { 7743 /* rldic */, PPC::RLDIC, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, 0, { MCK_rldic, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 7743 /* rldic */, PPC::RLDICo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__U6Imm1_5, 0, { MCK_rldic, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 7749 /* rldicl */, PPC::RLDICL, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, 0, { MCK_rldicl, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 7749 /* rldicl */, PPC::RLDICLo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__U6Imm1_5, 0, { MCK_rldicl, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 7756 /* rldicr */, PPC::RLDICR, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__U6Imm1_4, 0, { MCK_rldicr, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 7756 /* rldicr */, PPC::RLDICRo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__U6Imm1_5, 0, { MCK_rldicr, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 7763 /* rldimi */, PPC::RLDIMI, Convert__RegG8RC1_1__Tie0__RegG8RC1_2__U6Imm1_3__U6Imm1_4, 0, { MCK_rldimi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 7763 /* rldimi */, PPC::RLDIMIo, Convert__RegG8RC1_2__Tie0__RegG8RC1_3__U6Imm1_4__U6Imm1_5, 0, { MCK_rldimi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm, MCK_U6Imm }, },
  { 7770 /* rlwimi */, PPC::RLWIMIbm, Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4, 0, { MCK_rlwimi, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 7770 /* rlwimi */, PPC::RLWIMIobm, Convert__RegG8RC1_2__RegG8RC1_3__U5Imm1_4__Imm1_5, 0, { MCK_rlwimi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 7770 /* rlwimi */, PPC::RLWIMI, Convert__RegGPRC1_1__Tie0__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5, 0, { MCK_rlwimi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm, MCK_U5Imm }, },
  { 7770 /* rlwimi */, PPC::RLWIMIo, Convert__RegGPRC1_2__Tie0__RegGPRC1_3__U5Imm1_4__U5Imm1_5__U5Imm1_6, 0, { MCK_rlwimi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm, MCK_U5Imm }, },
  { 7777 /* rlwinm */, PPC::RLWINMbm, Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4, 0, { MCK_rlwinm, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 7777 /* rlwinm */, PPC::RLWINMobm, Convert__RegG8RC1_2__RegG8RC1_3__U5Imm1_4__Imm1_5, 0, { MCK_rlwinm, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 7777 /* rlwinm */, PPC::RLWINM, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__U5Imm1_4__U5Imm1_5, 0, { MCK_rlwinm, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm, MCK_U5Imm }, },
  { 7777 /* rlwinm */, PPC::RLWINMo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5__U5Imm1_6, 0, { MCK_rlwinm, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm, MCK_U5Imm }, },
  { 7784 /* rlwnm */, PPC::RLWNMbm, Convert__RegG8RC1_1__RegG8RC1_2__U5Imm1_3__Imm1_4, 0, { MCK_rlwnm, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 7784 /* rlwnm */, PPC::RLWNMobm, Convert__RegG8RC1_2__RegG8RC1_3__U5Imm1_4__Imm1_5, 0, { MCK_rlwnm, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U5Imm, MCK_Imm }, },
  { 7784 /* rlwnm */, PPC::RLWNM, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__U5Imm1_5, 0, { MCK_rlwnm, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 7784 /* rlwnm */, PPC::RLWNMo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4__U5Imm1_5__U5Imm1_6, 0, { MCK_rlwnm, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm, MCK_U5Imm }, },
  { 7790 /* rotld */, PPC::RLDCL, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3__imm_95_0, 0, { MCK_rotld, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 7790 /* rotld */, PPC::RLDCLo, Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4__imm_95_0, 0, { MCK_rotld, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 7796 /* rotldi */, PPC::RLDICL, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3__imm_95_0, 0, { MCK_rotldi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7796 /* rotldi */, PPC::RLDICLo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4__imm_95_0, 0, { MCK_rotldi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7803 /* rotlw */, PPC::RLWNM, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3__imm_95_0__imm_95_31, 0, { MCK_rotlw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7803 /* rotlw */, PPC::RLWNMo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4__imm_95_0__imm_95_31, 0, { MCK_rotlw, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7809 /* rotlwi */, PPC::RLWINM, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3__imm_95_0__imm_95_31, 0, { MCK_rotlwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7809 /* rotlwi */, PPC::RLWINMo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4__imm_95_0__imm_95_31, 0, { MCK_rotlwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7816 /* rotrdi */, PPC::ROTRDI, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, 0, { MCK_rotrdi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7816 /* rotrdi */, PPC::ROTRDIo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4, 0, { MCK_rotrdi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7823 /* rotrwi */, PPC::ROTRWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_rotrwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7823 /* rotrwi */, PPC::ROTRWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4, 0, { MCK_rotrwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7830 /* sc */, PPC::SC, Convert__imm_95_0, 0, { MCK_sc }, },
  { 7830 /* sc */, PPC::SC, Convert__Imm1_1, 0, { MCK_sc, MCK_Imm }, },
  { 7833 /* slbia */, PPC::SLBIA, Convert_NoOperands, 0, { MCK_slbia }, },
  { 7839 /* slbie */, PPC::SLBIE, Convert__RegGPRC1_1, 0, { MCK_slbie, MCK_RegGPRC }, },
  { 7845 /* slbmfee */, PPC::SLBMFEE, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_slbmfee, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7853 /* slbmte */, PPC::SLBMTE, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_slbmte, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7860 /* sld */, PPC::SLD, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3, 0, { MCK_sld, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 7860 /* sld */, PPC::SLDo, Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4, 0, { MCK_sld, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 7864 /* sldi */, PPC::SLDI, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, 0, { MCK_sldi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7864 /* sldi */, PPC::SLDIo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4, 0, { MCK_sldi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7869 /* slw */, PPC::SLW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_slw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7869 /* slw */, PPC::SLWo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_slw, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7873 /* slwi */, PPC::SLWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_slwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7873 /* slwi */, PPC::SLWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4, 0, { MCK_slwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7878 /* srad */, PPC::SRAD, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3, 0, { MCK_srad, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 7878 /* srad */, PPC::SRADo, Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4, 0, { MCK_srad, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 7883 /* sradi */, PPC::SRADI, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, 0, { MCK_sradi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7883 /* sradi */, PPC::SRADIo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4, 0, { MCK_sradi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7889 /* sraw */, PPC::SRAW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_sraw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7889 /* sraw */, PPC::SRAWo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_sraw, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7894 /* srawi */, PPC::SRAWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_srawi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7894 /* srawi */, PPC::SRAWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4, 0, { MCK_srawi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7900 /* srd */, PPC::SRD, Convert__RegG8RC1_1__RegG8RC1_2__RegGPRC1_3, 0, { MCK_srd, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 7900 /* srd */, PPC::SRDo, Convert__RegG8RC1_2__RegG8RC1_3__RegGPRC1_4, 0, { MCK_srd, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegGPRC }, },
  { 7904 /* srdi */, PPC::SRDI, Convert__RegG8RC1_1__RegG8RC1_2__U6Imm1_3, 0, { MCK_srdi, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7904 /* srdi */, PPC::SRDIo, Convert__RegG8RC1_2__RegG8RC1_3__U6Imm1_4, 0, { MCK_srdi, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_U6Imm }, },
  { 7909 /* srw */, PPC::SRW, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_srw, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7909 /* srw */, PPC::SRWo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_srw, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7913 /* srwi */, PPC::SRWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_srwi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7913 /* srwi */, PPC::SRWIo, Convert__RegGPRC1_2__RegGPRC1_3__U5Imm1_4, 0, { MCK_srwi, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 7918 /* stb */, PPC::STB, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_stb, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 7922 /* stbcix */, PPC::STBCIX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_stbcix, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7929 /* stbcx */, PPC::STBCX, Convert__RegGPRC1_2__RegGxRCNoR01_3__RegGxRC1_4, 0, { MCK_stbcx, MCK__DOT_, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7935 /* stbu */, PPC::STBU, Convert__imm_95_0__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_stbu, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 7940 /* stbux */, PPC::STBUX, Convert__imm_95_0__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stbux, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7946 /* stbx */, PPC::STBX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stbx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7951 /* std */, PPC::STD, Convert__RegG8RC1_1__DispRIX1_2__RegGxRCNoR01_3, 0, { MCK_std, MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 7955 /* stdbrx */, PPC::STDBRX, Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stdbrx, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7962 /* stdcix */, PPC::STDCIX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_stdcix, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 7969 /* stdcx */, PPC::STDCX, Convert__RegG8RC1_2__RegGxRCNoR01_3__RegGxRC1_4, 0, { MCK_stdcx, MCK__DOT_, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7975 /* stdu */, PPC::STDU, Convert__imm_95_0__RegG8RC1_1__DispRIX1_2__RegGxRCNoR01_3, 0, { MCK_stdu, MCK_RegG8RC, MCK_DispRIX, MCK_RegGxRCNoR0 }, },
  { 7980 /* stdux */, PPC::STDUX, Convert__imm_95_0__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stdux, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7986 /* stdx */, PPC::STDX, Convert__RegG8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stdx, MCK_RegG8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 7991 /* stfd */, PPC::STFD, Convert__RegF8RC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_stfd, MCK_RegF8RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 7996 /* stfdu */, PPC::STFDU, Convert__imm_95_0__RegF8RC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_stfdu, MCK_RegF8RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 8002 /* stfdux */, PPC::STFDUX, Convert__imm_95_0__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stfdux, MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8009 /* stfdx */, PPC::STFDX, Convert__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stfdx, MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8015 /* stfiwx */, PPC::STFIWX, Convert__RegF8RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stfiwx, MCK_RegF8RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8022 /* stfs */, PPC::STFS, Convert__RegF4RC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_stfs, MCK_RegF4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 8027 /* stfsu */, PPC::STFSU, Convert__imm_95_0__RegF4RC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_stfsu, MCK_RegF4RC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 8033 /* stfsux */, PPC::STFSUX, Convert__imm_95_0__RegF4RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stfsux, MCK_RegF4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8040 /* stfsx */, PPC::STFSX, Convert__RegF4RC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stfsx, MCK_RegF4RC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8046 /* sth */, PPC::STH, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_sth, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 8050 /* sthbrx */, PPC::STHBRX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_sthbrx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8057 /* sthcix */, PPC::STHCIX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_sthcix, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8064 /* sthcx */, PPC::STHCX, Convert__RegGPRC1_2__RegGxRCNoR01_3__RegGxRC1_4, 0, { MCK_sthcx, MCK__DOT_, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8070 /* sthu */, PPC::STHU, Convert__imm_95_0__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_sthu, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 8075 /* sthux */, PPC::STHUX, Convert__imm_95_0__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_sthux, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8081 /* sthx */, PPC::STHX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_sthx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8086 /* stmw */, PPC::STMW, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_stmw, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 8091 /* stswi */, PPC::STSWI, Convert__RegGPRC1_1__RegGPRC1_2__U5Imm1_3, 0, { MCK_stswi, MCK_RegGPRC, MCK_RegGPRC, MCK_U5Imm }, },
  { 8097 /* stvebx */, PPC::STVEBX, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stvebx, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8104 /* stvehx */, PPC::STVEHX, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stvehx, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8111 /* stvewx */, PPC::STVEWX, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stvewx, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8118 /* stvx */, PPC::STVX, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stvx, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8123 /* stvxl */, PPC::STVXL, Convert__RegVRRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stvxl, MCK_RegVRRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8129 /* stw */, PPC::STW, Convert__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_stw, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 8133 /* stwbrx */, PPC::STWBRX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stwbrx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8140 /* stwcix */, PPC::STWCIX, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_stwcix, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8147 /* stwcx */, PPC::STWCX, Convert__RegGPRC1_2__RegGxRCNoR01_3__RegGxRC1_4, 0, { MCK_stwcx, MCK__DOT_, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8153 /* stwu */, PPC::STWU, Convert__imm_95_0__RegGPRC1_1__DispRI1_2__RegGxRCNoR01_3, 0, { MCK_stwu, MCK_RegGPRC, MCK_DispRI, MCK_RegGxRCNoR0 }, },
  { 8158 /* stwux */, PPC::STWUX, Convert__imm_95_0__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stwux, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8164 /* stwx */, PPC::STWX, Convert__RegGPRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stwx, MCK_RegGPRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8169 /* stxsdx */, PPC::STXSDX, Convert__RegVSFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stxsdx, MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8176 /* stxsiwx */, PPC::STXSIWX, Convert__RegVSFRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stxsiwx, MCK_RegVSFRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8184 /* stxsspx */, PPC::STXSSPX, Convert__RegVSSRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stxsspx, MCK_RegVSSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8192 /* stxvd2x */, PPC::STXVD2X, Convert__RegVSRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stxvd2x, MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8200 /* stxvw4x */, PPC::STXVW4X, Convert__RegVSRC1_1__RegGxRCNoR01_2__RegGxRC1_3, 0, { MCK_stxvw4x, MCK_RegVSRC, MCK_RegGxRCNoR0, MCK_RegGxRC }, },
  { 8208 /* sub */, PPC::SUBF8, Convert__RegG8RC1_1__RegG8RC1_3__RegG8RC1_2, 0, { MCK_sub, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8208 /* sub */, PPC::SUBF8o, Convert__RegG8RC1_2__RegG8RC1_4__RegG8RC1_3, 0, { MCK_sub, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8212 /* subc */, PPC::SUBFC8, Convert__RegG8RC1_1__RegG8RC1_3__RegG8RC1_2, 0, { MCK_subc, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8212 /* subc */, PPC::SUBFC8o, Convert__RegG8RC1_2__RegG8RC1_4__RegG8RC1_3, 0, { MCK_subc, MCK__DOT_, MCK_RegG8RC, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8217 /* subf */, PPC::SUBF, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_subf, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8217 /* subf */, PPC::SUBFo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_subf, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8222 /* subfc */, PPC::SUBFC, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_subfc, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8222 /* subfc */, PPC::SUBFCo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_subfc, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8228 /* subfe */, PPC::SUBFE, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_subfe, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8228 /* subfe */, PPC::SUBFEo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_subfe, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8234 /* subfic */, PPC::SUBFIC, Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3, 0, { MCK_subfic, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 8241 /* subfme */, PPC::SUBFME, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_subfme, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8241 /* subfme */, PPC::SUBFMEo, Convert__RegGPRC1_2__RegGPRC1_3, 0, { MCK_subfme, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8248 /* subfze */, PPC::SUBFZE, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_subfze, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8248 /* subfze */, PPC::SUBFZEo, Convert__RegGPRC1_2__RegGPRC1_3, 0, { MCK_subfze, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8255 /* subi */, PPC::SUBI, Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3, 0, { MCK_subi, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 8260 /* subic */, PPC::SUBIC, Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3, 0, { MCK_subic, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 8260 /* subic */, PPC::SUBICo, Convert__RegGPRC1_2__RegGPRC1_3__S16Imm1_4, 0, { MCK_subic, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 8266 /* subis */, PPC::SUBIS, Convert__RegGPRC1_1__RegGPRC1_2__S16Imm1_3, 0, { MCK_subis, MCK_RegGPRC, MCK_RegGPRC, MCK_S16Imm }, },
  { 8272 /* sync */, PPC::SYNC, Convert__imm_95_0, 0, { MCK_sync }, },
  { 8272 /* sync */, PPC::SYNC, Convert__Imm1_1, 0, { MCK_sync, MCK_Imm }, },
  { 8277 /* tabort */, PPC::TABORT, Convert__imm_95_0__RegGPRC1_2, 0, { MCK_tabort, MCK__DOT_, MCK_RegGPRC }, },
  { 8284 /* tabortdc */, PPC::TABORTDC, Convert__imm_95_0__U5Imm1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_tabortdc, MCK__DOT_, MCK_U5Imm, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8293 /* tabortdci */, PPC::TABORTDCI, Convert__imm_95_0__U5Imm1_2__RegGPRC1_3__U5Imm1_4, 0, { MCK_tabortdci, MCK__DOT_, MCK_U5Imm, MCK_RegGPRC, MCK_U5Imm }, },
  { 8303 /* tabortwc */, PPC::TABORTWC, Convert__imm_95_0__U5Imm1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_tabortwc, MCK__DOT_, MCK_U5Imm, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8312 /* tabortwci */, PPC::TABORTWCI, Convert__imm_95_0__U5Imm1_2__RegGPRC1_3__U5Imm1_4, 0, { MCK_tabortwci, MCK__DOT_, MCK_U5Imm, MCK_RegGPRC, MCK_U5Imm }, },
  { 8322 /* tbegin */, PPC::TBEGIN, Convert__imm_95_0__U1Imm1_2, 0, { MCK_tbegin, MCK__DOT_, MCK_U1Imm }, },
  { 8329 /* tcheck */, PPC::TCHECK, Convert__RegCRRC1_1, 0, { MCK_tcheck, MCK_RegCRRC }, },
  { 8336 /* td */, PPC::TD, Convert__U5Imm1_1__RegG8RC1_2__RegG8RC1_3, 0, { MCK_td, MCK_U5Imm, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8339 /* tdeq */, PPC::TD, Convert__imm_95_4__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdeq, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8344 /* tdeqi */, PPC::TDI, Convert__imm_95_4__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdeqi, MCK_RegG8RC, MCK_S16Imm }, },
  { 8350 /* tdge */, PPC::TD, Convert__imm_95_12__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdge, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8355 /* tdgei */, PPC::TDI, Convert__imm_95_12__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdgei, MCK_RegG8RC, MCK_S16Imm }, },
  { 8361 /* tdgt */, PPC::TD, Convert__imm_95_8__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdgt, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8366 /* tdgti */, PPC::TDI, Convert__imm_95_8__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdgti, MCK_RegG8RC, MCK_S16Imm }, },
  { 8372 /* tdi */, PPC::TDI, Convert__U5Imm1_1__RegG8RC1_2__S16Imm1_3, 0, { MCK_tdi, MCK_U5Imm, MCK_RegG8RC, MCK_S16Imm }, },
  { 8376 /* tdle */, PPC::TD, Convert__imm_95_20__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdle, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8381 /* tdlei */, PPC::TDI, Convert__imm_95_20__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdlei, MCK_RegG8RC, MCK_S16Imm }, },
  { 8387 /* tdlge */, PPC::TD, Convert__imm_95_5__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdlge, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8393 /* tdlgei */, PPC::TDI, Convert__imm_95_5__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdlgei, MCK_RegG8RC, MCK_S16Imm }, },
  { 8400 /* tdlgt */, PPC::TD, Convert__imm_95_1__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdlgt, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8406 /* tdlgti */, PPC::TDI, Convert__imm_95_1__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdlgti, MCK_RegG8RC, MCK_S16Imm }, },
  { 8413 /* tdlle */, PPC::TD, Convert__imm_95_6__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdlle, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8419 /* tdllei */, PPC::TDI, Convert__imm_95_6__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdllei, MCK_RegG8RC, MCK_S16Imm }, },
  { 8426 /* tdllt */, PPC::TD, Convert__imm_95_2__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdllt, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8432 /* tdllti */, PPC::TDI, Convert__imm_95_2__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdllti, MCK_RegG8RC, MCK_S16Imm }, },
  { 8439 /* tdlng */, PPC::TD, Convert__imm_95_6__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdlng, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8445 /* tdlngi */, PPC::TDI, Convert__imm_95_6__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdlngi, MCK_RegG8RC, MCK_S16Imm }, },
  { 8452 /* tdlnl */, PPC::TD, Convert__imm_95_5__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdlnl, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8458 /* tdlnli */, PPC::TDI, Convert__imm_95_5__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdlnli, MCK_RegG8RC, MCK_S16Imm }, },
  { 8465 /* tdlt */, PPC::TD, Convert__imm_95_16__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdlt, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8470 /* tdlti */, PPC::TDI, Convert__imm_95_16__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdlti, MCK_RegG8RC, MCK_S16Imm }, },
  { 8476 /* tdne */, PPC::TD, Convert__imm_95_24__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdne, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8481 /* tdnei */, PPC::TDI, Convert__imm_95_24__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdnei, MCK_RegG8RC, MCK_S16Imm }, },
  { 8487 /* tdng */, PPC::TD, Convert__imm_95_20__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdng, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8492 /* tdngi */, PPC::TDI, Convert__imm_95_20__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdngi, MCK_RegG8RC, MCK_S16Imm }, },
  { 8498 /* tdnl */, PPC::TD, Convert__imm_95_12__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdnl, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8503 /* tdnli */, PPC::TDI, Convert__imm_95_12__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdnli, MCK_RegG8RC, MCK_S16Imm }, },
  { 8509 /* tdu */, PPC::TD, Convert__imm_95_31__RegG8RC1_1__RegG8RC1_2, 0, { MCK_tdu, MCK_RegG8RC, MCK_RegG8RC }, },
  { 8513 /* tdui */, PPC::TDI, Convert__imm_95_31__RegG8RC1_1__S16Imm1_2, 0, { MCK_tdui, MCK_RegG8RC, MCK_S16Imm }, },
  { 8518 /* tend */, PPC::TEND, Convert__imm_95_0__U1Imm1_2, 0, { MCK_tend, MCK__DOT_, MCK_U1Imm }, },
  { 8523 /* tlbia */, PPC::TLBIA, Convert_NoOperands, 0, { MCK_tlbia }, },
  { 8529 /* tlbie */, PPC::TLBIE, Convert__regR0__RegGPRC1_1, 0, { MCK_tlbie, MCK_RegGPRC }, },
  { 8529 /* tlbie */, PPC::TLBIE, Convert__RegGPRC1_2__RegGPRC1_1, 0, { MCK_tlbie, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8535 /* tlbiel */, PPC::TLBIEL, Convert__RegGPRC1_1, 0, { MCK_tlbiel, MCK_RegGPRC }, },
  { 8542 /* tlbivax */, PPC::TLBIVAX, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_tlbivax, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8550 /* tlbld */, PPC::TLBLD, Convert__RegGPRC1_1, 0, { MCK_tlbld, MCK_RegGPRC }, },
  { 8556 /* tlbli */, PPC::TLBLI, Convert__RegGPRC1_1, 0, { MCK_tlbli, MCK_RegGPRC }, },
  { 8562 /* tlbre */, PPC::TLBRE, Convert_NoOperands, 0, { MCK_tlbre }, },
  { 8562 /* tlbre */, PPC::TLBRE2, Convert__RegGPRC1_1__RegGPRC1_2__Imm1_3, 0, { MCK_tlbre, MCK_RegGPRC, MCK_RegGPRC, MCK_Imm }, },
  { 8568 /* tlbrehi */, PPC::TLBRE2, Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0, 0, { MCK_tlbrehi, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8576 /* tlbrelo */, PPC::TLBRE2, Convert__RegGPRC1_1__RegGPRC1_2__imm_95_1, 0, { MCK_tlbrelo, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8584 /* tlbsx */, PPC::TLBSX, Convert__RegGPRC1_1__RegGPRC1_2, 0, { MCK_tlbsx, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8584 /* tlbsx */, PPC::TLBSX2, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_tlbsx, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8584 /* tlbsx */, PPC::TLBSX2D, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_tlbsx, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8590 /* tlbsync */, PPC::TLBSYNC, Convert_NoOperands, 0, { MCK_tlbsync }, },
  { 8598 /* tlbwe */, PPC::TLBWE, Convert_NoOperands, 0, { MCK_tlbwe }, },
  { 8598 /* tlbwe */, PPC::TLBWE2, Convert__RegGPRC1_1__RegGPRC1_2__Imm1_3, 0, { MCK_tlbwe, MCK_RegGPRC, MCK_RegGPRC, MCK_Imm }, },
  { 8604 /* tlbwehi */, PPC::TLBWE2, Convert__RegGPRC1_1__RegGPRC1_2__imm_95_0, 0, { MCK_tlbwehi, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8612 /* tlbwelo */, PPC::TLBWE2, Convert__RegGPRC1_1__RegGPRC1_2__imm_95_1, 0, { MCK_tlbwelo, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8620 /* trap */, PPC::TRAP, Convert_NoOperands, 0, { MCK_trap }, },
  { 8625 /* trechkpt */, PPC::TRECHKPT, Convert__imm_95_0, 0, { MCK_trechkpt, MCK__DOT_ }, },
  { 8634 /* treclaim */, PPC::TRECLAIM, Convert__imm_95_0__RegGPRC1_2, 0, { MCK_treclaim, MCK__DOT_, MCK_RegGPRC }, },
  { 8643 /* tsr */, PPC::TSR, Convert__imm_95_0__U1Imm1_2, 0, { MCK_tsr, MCK__DOT_, MCK_U1Imm }, },
  { 8647 /* tw */, PPC::TW, Convert__U5Imm1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_tw, MCK_U5Imm, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8650 /* tweq */, PPC::TW, Convert__imm_95_4__RegGPRC1_1__RegGPRC1_2, 0, { MCK_tweq, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8655 /* tweqi */, PPC::TWI, Convert__imm_95_4__RegGPRC1_1__S16Imm1_2, 0, { MCK_tweqi, MCK_RegGPRC, MCK_S16Imm }, },
  { 8661 /* twge */, PPC::TW, Convert__imm_95_12__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twge, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8666 /* twgei */, PPC::TWI, Convert__imm_95_12__RegGPRC1_1__S16Imm1_2, 0, { MCK_twgei, MCK_RegGPRC, MCK_S16Imm }, },
  { 8672 /* twgt */, PPC::TW, Convert__imm_95_8__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twgt, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8677 /* twgti */, PPC::TWI, Convert__imm_95_8__RegGPRC1_1__S16Imm1_2, 0, { MCK_twgti, MCK_RegGPRC, MCK_S16Imm }, },
  { 8683 /* twi */, PPC::TWI, Convert__U5Imm1_1__RegGPRC1_2__S16Imm1_3, 0, { MCK_twi, MCK_U5Imm, MCK_RegGPRC, MCK_S16Imm }, },
  { 8687 /* twle */, PPC::TW, Convert__imm_95_20__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twle, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8692 /* twlei */, PPC::TWI, Convert__imm_95_20__RegGPRC1_1__S16Imm1_2, 0, { MCK_twlei, MCK_RegGPRC, MCK_S16Imm }, },
  { 8698 /* twlge */, PPC::TW, Convert__imm_95_5__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twlge, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8704 /* twlgei */, PPC::TWI, Convert__imm_95_5__RegGPRC1_1__S16Imm1_2, 0, { MCK_twlgei, MCK_RegGPRC, MCK_S16Imm }, },
  { 8711 /* twlgt */, PPC::TW, Convert__imm_95_1__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twlgt, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8717 /* twlgti */, PPC::TWI, Convert__imm_95_1__RegGPRC1_1__S16Imm1_2, 0, { MCK_twlgti, MCK_RegGPRC, MCK_S16Imm }, },
  { 8724 /* twlle */, PPC::TW, Convert__imm_95_6__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twlle, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8730 /* twllei */, PPC::TWI, Convert__imm_95_6__RegGPRC1_1__S16Imm1_2, 0, { MCK_twllei, MCK_RegGPRC, MCK_S16Imm }, },
  { 8737 /* twllt */, PPC::TW, Convert__imm_95_2__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twllt, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8743 /* twllti */, PPC::TWI, Convert__imm_95_2__RegGPRC1_1__S16Imm1_2, 0, { MCK_twllti, MCK_RegGPRC, MCK_S16Imm }, },
  { 8750 /* twlng */, PPC::TW, Convert__imm_95_6__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twlng, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8756 /* twlngi */, PPC::TWI, Convert__imm_95_6__RegGPRC1_1__S16Imm1_2, 0, { MCK_twlngi, MCK_RegGPRC, MCK_S16Imm }, },
  { 8763 /* twlnl */, PPC::TW, Convert__imm_95_5__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twlnl, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8769 /* twlnli */, PPC::TWI, Convert__imm_95_5__RegGPRC1_1__S16Imm1_2, 0, { MCK_twlnli, MCK_RegGPRC, MCK_S16Imm }, },
  { 8776 /* twlt */, PPC::TW, Convert__imm_95_16__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twlt, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8781 /* twlti */, PPC::TWI, Convert__imm_95_16__RegGPRC1_1__S16Imm1_2, 0, { MCK_twlti, MCK_RegGPRC, MCK_S16Imm }, },
  { 8787 /* twne */, PPC::TW, Convert__imm_95_24__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twne, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8792 /* twnei */, PPC::TWI, Convert__imm_95_24__RegGPRC1_1__S16Imm1_2, 0, { MCK_twnei, MCK_RegGPRC, MCK_S16Imm }, },
  { 8798 /* twng */, PPC::TW, Convert__imm_95_20__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twng, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8803 /* twngi */, PPC::TWI, Convert__imm_95_20__RegGPRC1_1__S16Imm1_2, 0, { MCK_twngi, MCK_RegGPRC, MCK_S16Imm }, },
  { 8809 /* twnl */, PPC::TW, Convert__imm_95_12__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twnl, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8814 /* twnli */, PPC::TWI, Convert__imm_95_12__RegGPRC1_1__S16Imm1_2, 0, { MCK_twnli, MCK_RegGPRC, MCK_S16Imm }, },
  { 8820 /* twu */, PPC::TW, Convert__imm_95_31__RegGPRC1_1__RegGPRC1_2, 0, { MCK_twu, MCK_RegGPRC, MCK_RegGPRC }, },
  { 8824 /* twui */, PPC::TWI, Convert__imm_95_31__RegGPRC1_1__S16Imm1_2, 0, { MCK_twui, MCK_RegGPRC, MCK_S16Imm }, },
  { 8829 /* vaddcuq */, PPC::VADDCUQ, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vaddcuq, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8837 /* vaddcuw */, PPC::VADDCUW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vaddcuw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8845 /* vaddecuq */, PPC::VADDECUQ, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vaddecuq, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8854 /* vaddeuqm */, PPC::VADDEUQM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vaddeuqm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8863 /* vaddfp */, PPC::VADDFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vaddfp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8870 /* vaddsbs */, PPC::VADDSBS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vaddsbs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8878 /* vaddshs */, PPC::VADDSHS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vaddshs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8886 /* vaddsws */, PPC::VADDSWS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vaddsws, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8894 /* vaddubm */, PPC::VADDUBM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vaddubm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8902 /* vaddubs */, PPC::VADDUBS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vaddubs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8910 /* vaddudm */, PPC::VADDUDM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vaddudm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8918 /* vadduhm */, PPC::VADDUHM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vadduhm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8926 /* vadduhs */, PPC::VADDUHS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vadduhs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8934 /* vadduqm */, PPC::VADDUQM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vadduqm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8942 /* vadduwm */, PPC::VADDUWM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vadduwm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8950 /* vadduws */, PPC::VADDUWS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vadduws, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8958 /* vand */, PPC::VAND, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vand, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8963 /* vandc */, PPC::VANDC, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vandc, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8969 /* vavgsb */, PPC::VAVGSB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vavgsb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8976 /* vavgsh */, PPC::VAVGSH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vavgsh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8983 /* vavgsw */, PPC::VAVGSW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vavgsw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8990 /* vavgub */, PPC::VAVGUB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vavgub, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 8997 /* vavguh */, PPC::VAVGUH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vavguh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9004 /* vavguw */, PPC::VAVGUW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vavguw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9011 /* vbpermq */, PPC::VBPERMQ, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vbpermq, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9019 /* vcfsx */, PPC::VCFSX, Convert__RegVRRC1_1__U5Imm1_3__RegVRRC1_2, 0, { MCK_vcfsx, MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 9025 /* vcfux */, PPC::VCFUX, Convert__RegVRRC1_1__U5Imm1_3__RegVRRC1_2, 0, { MCK_vcfux, MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 9031 /* vcipher */, PPC::VCIPHER, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcipher, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9039 /* vcipherlast */, PPC::VCIPHERLAST, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcipherlast, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9051 /* vclzb */, PPC::VCLZB, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vclzb, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9057 /* vclzd */, PPC::VCLZD, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vclzd, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9063 /* vclzh */, PPC::VCLZH, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vclzh, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9069 /* vclzw */, PPC::VCLZW, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vclzw, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9075 /* vcmpbfp */, PPC::VCMPBFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpbfp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9075 /* vcmpbfp */, PPC::VCMPBFPo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpbfp, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9083 /* vcmpeqfp */, PPC::VCMPEQFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpeqfp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9083 /* vcmpeqfp */, PPC::VCMPEQFPo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpeqfp, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9092 /* vcmpequb */, PPC::VCMPEQUB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpequb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9092 /* vcmpequb */, PPC::VCMPEQUBo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpequb, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9101 /* vcmpequd */, PPC::VCMPEQUD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpequd, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9101 /* vcmpequd */, PPC::VCMPEQUDo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpequd, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9110 /* vcmpequh */, PPC::VCMPEQUH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpequh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9110 /* vcmpequh */, PPC::VCMPEQUHo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpequh, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9119 /* vcmpequw */, PPC::VCMPEQUW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpequw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9119 /* vcmpequw */, PPC::VCMPEQUWo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpequw, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9128 /* vcmpgefp */, PPC::VCMPGEFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgefp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9128 /* vcmpgefp */, PPC::VCMPGEFPo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgefp, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9137 /* vcmpgtfp */, PPC::VCMPGTFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgtfp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9137 /* vcmpgtfp */, PPC::VCMPGTFPo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgtfp, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9146 /* vcmpgtsb */, PPC::VCMPGTSB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgtsb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9146 /* vcmpgtsb */, PPC::VCMPGTSBo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgtsb, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9155 /* vcmpgtsd */, PPC::VCMPGTSD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgtsd, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9155 /* vcmpgtsd */, PPC::VCMPGTSDo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgtsd, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9164 /* vcmpgtsh */, PPC::VCMPGTSH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgtsh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9164 /* vcmpgtsh */, PPC::VCMPGTSHo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgtsh, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9173 /* vcmpgtsw */, PPC::VCMPGTSW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgtsw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9173 /* vcmpgtsw */, PPC::VCMPGTSWo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgtsw, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9182 /* vcmpgtub */, PPC::VCMPGTUB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgtub, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9182 /* vcmpgtub */, PPC::VCMPGTUBo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgtub, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9191 /* vcmpgtud */, PPC::VCMPGTUD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgtud, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9191 /* vcmpgtud */, PPC::VCMPGTUDo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgtud, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9200 /* vcmpgtuh */, PPC::VCMPGTUH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgtuh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9200 /* vcmpgtuh */, PPC::VCMPGTUHo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgtuh, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9209 /* vcmpgtuw */, PPC::VCMPGTUW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vcmpgtuw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9209 /* vcmpgtuw */, PPC::VCMPGTUWo, Convert__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vcmpgtuw, MCK__DOT_, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9218 /* vctsxs */, PPC::VCTSXS, Convert__RegVRRC1_1__U5Imm1_3__RegVRRC1_2, 0, { MCK_vctsxs, MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 9225 /* vctuxs */, PPC::VCTUXS, Convert__RegVRRC1_1__U5Imm1_3__RegVRRC1_2, 0, { MCK_vctuxs, MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 9232 /* veqv */, PPC::VEQV, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_veqv, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9237 /* vexptefp */, PPC::VEXPTEFP, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vexptefp, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9246 /* vgbbd */, PPC::VGBBD, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vgbbd, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9252 /* vlogefp */, PPC::VLOGEFP, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vlogefp, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9260 /* vmaddfp */, PPC::VMADDFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmaddfp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9268 /* vmaxfp */, PPC::VMAXFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmaxfp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9275 /* vmaxsb */, PPC::VMAXSB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmaxsb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9282 /* vmaxsd */, PPC::VMAXSD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmaxsd, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9289 /* vmaxsh */, PPC::VMAXSH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmaxsh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9296 /* vmaxsw */, PPC::VMAXSW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmaxsw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9303 /* vmaxub */, PPC::VMAXUB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmaxub, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9310 /* vmaxud */, PPC::VMAXUD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmaxud, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9317 /* vmaxuh */, PPC::VMAXUH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmaxuh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9324 /* vmaxuw */, PPC::VMAXUW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmaxuw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9331 /* vmhaddshs */, PPC::VMHADDSHS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmhaddshs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9341 /* vmhraddshs */, PPC::VMHRADDSHS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmhraddshs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9352 /* vminfp */, PPC::VMINFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vminfp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9359 /* vminsb */, PPC::VMINSB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vminsb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9366 /* vminsd */, PPC::VMINSD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vminsd, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9373 /* vminsh */, PPC::VMINSH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vminsh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9380 /* vminsw */, PPC::VMINSW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vminsw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9387 /* vminub */, PPC::VMINUB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vminub, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9394 /* vminud */, PPC::VMINUD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vminud, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9401 /* vminuh */, PPC::VMINUH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vminuh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9408 /* vminuw */, PPC::VMINUW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vminuw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9415 /* vmladduhm */, PPC::VMLADDUHM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmladduhm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9425 /* vmrgew */, PPC::VMRGEW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmrgew, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9432 /* vmrghb */, PPC::VMRGHB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmrghb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9439 /* vmrghh */, PPC::VMRGHH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmrghh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9446 /* vmrghw */, PPC::VMRGHW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmrghw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9453 /* vmrglb */, PPC::VMRGLB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmrglb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9460 /* vmrglh */, PPC::VMRGLH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmrglh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9467 /* vmrglw */, PPC::VMRGLW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmrglw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9474 /* vmrgow */, PPC::VMRGOW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmrgow, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9481 /* vmsummbm */, PPC::VMSUMMBM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmsummbm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9490 /* vmsumshm */, PPC::VMSUMSHM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmsumshm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9499 /* vmsumshs */, PPC::VMSUMSHS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmsumshs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9508 /* vmsumubm */, PPC::VMSUMUBM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmsumubm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9517 /* vmsumuhm */, PPC::VMSUMUHM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmsumuhm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9526 /* vmsumuhs */, PPC::VMSUMUHS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vmsumuhs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9535 /* vmulesb */, PPC::VMULESB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmulesb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9543 /* vmulesh */, PPC::VMULESH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmulesh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9551 /* vmulesw */, PPC::VMULESW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmulesw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9559 /* vmuleub */, PPC::VMULEUB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmuleub, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9567 /* vmuleuh */, PPC::VMULEUH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmuleuh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9575 /* vmuleuw */, PPC::VMULEUW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmuleuw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9583 /* vmulosb */, PPC::VMULOSB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmulosb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9591 /* vmulosh */, PPC::VMULOSH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmulosh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9599 /* vmulosw */, PPC::VMULOSW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmulosw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9607 /* vmuloub */, PPC::VMULOUB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmuloub, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9615 /* vmulouh */, PPC::VMULOUH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmulouh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9623 /* vmulouw */, PPC::VMULOUW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmulouw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9631 /* vmuluwm */, PPC::VMULUWM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vmuluwm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9639 /* vnand */, PPC::VNAND, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vnand, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9645 /* vncipher */, PPC::VNCIPHER, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vncipher, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9654 /* vncipherlast */, PPC::VNCIPHERLAST, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vncipherlast, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9667 /* vnmsubfp */, PPC::VNMSUBFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vnmsubfp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9676 /* vnor */, PPC::VNOR, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vnor, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9681 /* vor */, PPC::VOR, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vor, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9685 /* vorc */, PPC::VORC, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vorc, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9690 /* vperm */, PPC::VPERM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vperm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9696 /* vpermxor */, PPC::VPERMXOR, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vpermxor, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9705 /* vpkpx */, PPC::VPKPX, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkpx, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9711 /* vpksdss */, PPC::VPKSDSS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpksdss, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9719 /* vpksdus */, PPC::VPKSDUS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpksdus, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9727 /* vpkshss */, PPC::VPKSHSS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkshss, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9735 /* vpkshus */, PPC::VPKSHUS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkshus, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9743 /* vpkswss */, PPC::VPKSWSS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkswss, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9751 /* vpkswus */, PPC::VPKSWUS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkswus, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9759 /* vpkudum */, PPC::VPKUDUM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkudum, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9767 /* vpkudus */, PPC::VPKUDUS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkudus, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9775 /* vpkuhum */, PPC::VPKUHUM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkuhum, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9783 /* vpkuhus */, PPC::VPKUHUS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkuhus, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9791 /* vpkuwum */, PPC::VPKUWUM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkuwum, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9799 /* vpkuwus */, PPC::VPKUWUS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpkuwus, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9807 /* vpmsumb */, PPC::VPMSUMB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpmsumb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9815 /* vpmsumd */, PPC::VPMSUMD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpmsumd, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9823 /* vpmsumh */, PPC::VPMSUMH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpmsumh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9831 /* vpmsumw */, PPC::VPMSUMW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vpmsumw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9839 /* vpopcntb */, PPC::VPOPCNTB, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vpopcntb, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9848 /* vpopcntd */, PPC::VPOPCNTD, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vpopcntd, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9857 /* vpopcnth */, PPC::VPOPCNTH, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vpopcnth, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9866 /* vpopcntw */, PPC::VPOPCNTW, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vpopcntw, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9875 /* vrefp */, PPC::VREFP, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vrefp, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9881 /* vrfim */, PPC::VRFIM, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vrfim, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9887 /* vrfin */, PPC::VRFIN, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vrfin, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9893 /* vrfip */, PPC::VRFIP, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vrfip, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9899 /* vrfiz */, PPC::VRFIZ, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vrfiz, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9905 /* vrlb */, PPC::VRLB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vrlb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9910 /* vrld */, PPC::VRLD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vrld, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9915 /* vrlh */, PPC::VRLH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vrlh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9920 /* vrlw */, PPC::VRLW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vrlw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9925 /* vrsqrtefp */, PPC::VRSQRTEFP, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vrsqrtefp, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9935 /* vsbox */, PPC::VSBOX, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vsbox, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9941 /* vsel */, PPC::VSEL, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vsel, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9946 /* vshasigmad */, PPC::VSHASIGMAD, Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3__U4Imm1_4, 0, { MCK_vshasigmad, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm, MCK_U4Imm }, },
  { 9957 /* vshasigmaw */, PPC::VSHASIGMAW, Convert__RegVRRC1_1__RegVRRC1_2__U1Imm1_3__U4Imm1_4, 0, { MCK_vshasigmaw, MCK_RegVRRC, MCK_RegVRRC, MCK_U1Imm, MCK_U4Imm }, },
  { 9968 /* vsl */, PPC::VSL, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsl, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9972 /* vslb */, PPC::VSLB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vslb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9977 /* vsld */, PPC::VSLD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsld, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9982 /* vsldoi */, PPC::VSLDOI, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__U5Imm1_4, 0, { MCK_vsldoi, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 9989 /* vslh */, PPC::VSLH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vslh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9994 /* vslo */, PPC::VSLO, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vslo, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 9999 /* vslw */, PPC::VSLW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vslw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10004 /* vspltb */, PPC::VSPLTB, Convert__RegVRRC1_1__U5Imm1_3__RegVRRC1_2, 0, { MCK_vspltb, MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 10011 /* vsplth */, PPC::VSPLTH, Convert__RegVRRC1_1__U5Imm1_3__RegVRRC1_2, 0, { MCK_vsplth, MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 10018 /* vspltisb */, PPC::VSPLTISB, Convert__RegVRRC1_1__S5Imm1_2, 0, { MCK_vspltisb, MCK_RegVRRC, MCK_S5Imm }, },
  { 10027 /* vspltish */, PPC::VSPLTISH, Convert__RegVRRC1_1__S5Imm1_2, 0, { MCK_vspltish, MCK_RegVRRC, MCK_S5Imm }, },
  { 10036 /* vspltisw */, PPC::VSPLTISW, Convert__RegVRRC1_1__S5Imm1_2, 0, { MCK_vspltisw, MCK_RegVRRC, MCK_S5Imm }, },
  { 10045 /* vspltw */, PPC::VSPLTW, Convert__RegVRRC1_1__U5Imm1_3__RegVRRC1_2, 0, { MCK_vspltw, MCK_RegVRRC, MCK_RegVRRC, MCK_U5Imm }, },
  { 10052 /* vsr */, PPC::VSR, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsr, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10056 /* vsrab */, PPC::VSRAB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsrab, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10062 /* vsrad */, PPC::VSRAD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsrad, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10068 /* vsrah */, PPC::VSRAH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsrah, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10074 /* vsraw */, PPC::VSRAW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsraw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10080 /* vsrb */, PPC::VSRB, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsrb, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10085 /* vsrd */, PPC::VSRD, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsrd, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10090 /* vsrh */, PPC::VSRH, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsrh, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10095 /* vsro */, PPC::VSRO, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsro, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10100 /* vsrw */, PPC::VSRW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsrw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10105 /* vsubcuq */, PPC::VSUBCUQ, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubcuq, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10113 /* vsubcuw */, PPC::VSUBCUW, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubcuw, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10121 /* vsubecuq */, PPC::VSUBECUQ, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vsubecuq, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10130 /* vsubeuqm */, PPC::VSUBEUQM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3__RegVRRC1_4, 0, { MCK_vsubeuqm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10139 /* vsubfp */, PPC::VSUBFP, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubfp, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10146 /* vsubsbs */, PPC::VSUBSBS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubsbs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10154 /* vsubshs */, PPC::VSUBSHS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubshs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10162 /* vsubsws */, PPC::VSUBSWS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubsws, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10170 /* vsububm */, PPC::VSUBUBM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsububm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10178 /* vsububs */, PPC::VSUBUBS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsububs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10186 /* vsubudm */, PPC::VSUBUDM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubudm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10194 /* vsubuhm */, PPC::VSUBUHM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubuhm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10202 /* vsubuhs */, PPC::VSUBUHS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubuhs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10210 /* vsubuqm */, PPC::VSUBUQM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubuqm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10218 /* vsubuwm */, PPC::VSUBUWM, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubuwm, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10226 /* vsubuws */, PPC::VSUBUWS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsubuws, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10234 /* vsum2sws */, PPC::VSUM2SWS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsum2sws, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10243 /* vsum4sbs */, PPC::VSUM4SBS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsum4sbs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10252 /* vsum4shs */, PPC::VSUM4SHS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsum4shs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10261 /* vsum4ubs */, PPC::VSUM4UBS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsum4ubs, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10270 /* vsumsws */, PPC::VSUMSWS, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vsumsws, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10278 /* vupkhpx */, PPC::VUPKHPX, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vupkhpx, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10286 /* vupkhsb */, PPC::VUPKHSB, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vupkhsb, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10294 /* vupkhsh */, PPC::VUPKHSH, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vupkhsh, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10302 /* vupkhsw */, PPC::VUPKHSW, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vupkhsw, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10310 /* vupklpx */, PPC::VUPKLPX, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vupklpx, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10318 /* vupklsb */, PPC::VUPKLSB, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vupklsb, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10326 /* vupklsh */, PPC::VUPKLSH, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vupklsh, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10334 /* vupklsw */, PPC::VUPKLSW, Convert__RegVRRC1_1__RegVRRC1_2, 0, { MCK_vupklsw, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10342 /* vxor */, PPC::VXOR, Convert__RegVRRC1_1__RegVRRC1_2__RegVRRC1_3, 0, { MCK_vxor, MCK_RegVRRC, MCK_RegVRRC, MCK_RegVRRC }, },
  { 10347 /* wait */, PPC::WAIT, Convert__imm_95_0, 0, { MCK_wait }, },
  { 10347 /* wait */, PPC::WAIT, Convert__Imm1_1, 0, { MCK_wait, MCK_Imm }, },
  { 10352 /* waitimpl */, PPC::WAIT, Convert__imm_95_2, 0, { MCK_waitimpl }, },
  { 10361 /* waitrsv */, PPC::WAIT, Convert__imm_95_1, 0, { MCK_waitrsv }, },
  { 10369 /* wrtee */, PPC::WRTEE, Convert__RegGPRC1_1, 0, { MCK_wrtee, MCK_RegGPRC }, },
  { 10375 /* wrteei */, PPC::WRTEEI, Convert__Imm1_1, 0, { MCK_wrteei, MCK_Imm }, },
  { 10382 /* xnop */, PPC::XORI, Convert__regR0__regR0__imm_95_0, 0, { MCK_xnop }, },
  { 10387 /* xor */, PPC::XOR, Convert__RegGPRC1_1__RegGPRC1_2__RegGPRC1_3, 0, { MCK_xor, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 10387 /* xor */, PPC::XORo, Convert__RegGPRC1_2__RegGPRC1_3__RegGPRC1_4, 0, { MCK_xor, MCK__DOT_, MCK_RegGPRC, MCK_RegGPRC, MCK_RegGPRC }, },
  { 10391 /* xori */, PPC::XORI, Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3, 0, { MCK_xori, MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 10396 /* xoris */, PPC::XORIS, Convert__RegGPRC1_1__RegGPRC1_2__U16Imm1_3, 0, { MCK_xoris, MCK_RegGPRC, MCK_RegGPRC, MCK_U16Imm }, },
  { 10402 /* xsabsdp */, PPC::XSABSDP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsabsdp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10410 /* xsadddp */, PPC::XSADDDP, Convert__RegVSFRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsadddp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10418 /* xsaddsp */, PPC::XSADDSP, Convert__RegVSSRC1_1__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsaddsp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10426 /* xscmpodp */, PPC::XSCMPODP, Convert__RegCRRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xscmpodp, MCK_RegCRRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10435 /* xscmpudp */, PPC::XSCMPUDP, Convert__RegCRRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xscmpudp, MCK_RegCRRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10444 /* xscpsgndp */, PPC::XSCPSGNDP, Convert__RegVSFRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xscpsgndp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10454 /* xscvdpsp */, PPC::XSCVDPSP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xscvdpsp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10463 /* xscvdpspn */, PPC::XSCVDPSPN, Convert__RegVSRC1_1__RegVSSRC1_2, 0, { MCK_xscvdpspn, MCK_RegVSRC, MCK_RegVSSRC }, },
  { 10473 /* xscvdpsxds */, PPC::XSCVDPSXDS, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xscvdpsxds, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10484 /* xscvdpsxws */, PPC::XSCVDPSXWS, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xscvdpsxws, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10495 /* xscvdpuxds */, PPC::XSCVDPUXDS, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xscvdpuxds, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10506 /* xscvdpuxws */, PPC::XSCVDPUXWS, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xscvdpuxws, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10517 /* xscvspdp */, PPC::XSCVSPDP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xscvspdp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10526 /* xscvspdpn */, PPC::XSCVSPDPN, Convert__RegVSSRC1_1__RegVSRC1_2, 0, { MCK_xscvspdpn, MCK_RegVSSRC, MCK_RegVSRC }, },
  { 10536 /* xscvsxddp */, PPC::XSCVSXDDP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xscvsxddp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10546 /* xscvsxdsp */, PPC::XSCVSXDSP, Convert__RegVSSRC1_1__RegVSFRC1_2, 0, { MCK_xscvsxdsp, MCK_RegVSSRC, MCK_RegVSFRC }, },
  { 10556 /* xscvuxddp */, PPC::XSCVUXDDP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xscvuxddp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10566 /* xscvuxdsp */, PPC::XSCVUXDSP, Convert__RegVSSRC1_1__RegVSFRC1_2, 0, { MCK_xscvuxdsp, MCK_RegVSSRC, MCK_RegVSFRC }, },
  { 10576 /* xsdivdp */, PPC::XSDIVDP, Convert__RegVSFRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsdivdp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10584 /* xsdivsp */, PPC::XSDIVSP, Convert__RegVSSRC1_1__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsdivsp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10592 /* xsmaddadp */, PPC::XSMADDADP, Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsmaddadp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10602 /* xsmaddasp */, PPC::XSMADDASP, Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsmaddasp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10612 /* xsmaddmdp */, PPC::XSMADDMDP, Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsmaddmdp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10622 /* xsmaddmsp */, PPC::XSMADDMSP, Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsmaddmsp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10632 /* xsmaxdp */, PPC::XSMAXDP, Convert__RegVSFRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsmaxdp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10640 /* xsmindp */, PPC::XSMINDP, Convert__RegVSFRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsmindp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10648 /* xsmsubadp */, PPC::XSMSUBADP, Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsmsubadp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10658 /* xsmsubasp */, PPC::XSMSUBASP, Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsmsubasp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10668 /* xsmsubmdp */, PPC::XSMSUBMDP, Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsmsubmdp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10678 /* xsmsubmsp */, PPC::XSMSUBMSP, Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsmsubmsp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10688 /* xsmuldp */, PPC::XSMULDP, Convert__RegVSFRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsmuldp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10696 /* xsmulsp */, PPC::XSMULSP, Convert__RegVSSRC1_1__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsmulsp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10704 /* xsnabsdp */, PPC::XSNABSDP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsnabsdp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10713 /* xsnegdp */, PPC::XSNEGDP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsnegdp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10721 /* xsnmaddadp */, PPC::XSNMADDADP, Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsnmaddadp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10732 /* xsnmaddasp */, PPC::XSNMADDASP, Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsnmaddasp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10743 /* xsnmaddmdp */, PPC::XSNMADDMDP, Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsnmaddmdp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10754 /* xsnmaddmsp */, PPC::XSNMADDMSP, Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsnmaddmsp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10765 /* xsnmsubadp */, PPC::XSNMSUBADP, Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsnmsubadp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10776 /* xsnmsubasp */, PPC::XSNMSUBASP, Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsnmsubasp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10787 /* xsnmsubmdp */, PPC::XSNMSUBMDP, Convert__RegVSFRC1_1__Tie0__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xsnmsubmdp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10798 /* xsnmsubmsp */, PPC::XSNMSUBMSP, Convert__RegVSSRC1_1__Tie0__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xsnmsubmsp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10809 /* xsrdpi */, PPC::XSRDPI, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsrdpi, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10816 /* xsrdpic */, PPC::XSRDPIC, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsrdpic, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10824 /* xsrdpim */, PPC::XSRDPIM, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsrdpim, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10832 /* xsrdpip */, PPC::XSRDPIP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsrdpip, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10840 /* xsrdpiz */, PPC::XSRDPIZ, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsrdpiz, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10848 /* xsredp */, PPC::XSREDP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsredp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10855 /* xsresp */, PPC::XSRESP, Convert__RegVSSRC1_1__RegVSSRC1_2, 0, { MCK_xsresp, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10862 /* xsrsqrtedp */, PPC::XSRSQRTEDP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xsrsqrtedp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10873 /* xsrsqrtesp */, PPC::XSRSQRTESP, Convert__RegVSSRC1_1__RegVSSRC1_2, 0, { MCK_xsrsqrtesp, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10884 /* xssqrtdp */, PPC::XSSQRTDP, Convert__RegVSFRC1_1__RegVSFRC1_2, 0, { MCK_xssqrtdp, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10893 /* xssqrtsp */, PPC::XSSQRTSP, Convert__RegVSSRC1_1__RegVSSRC1_2, 0, { MCK_xssqrtsp, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10902 /* xssubdp */, PPC::XSSUBDP, Convert__RegVSFRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xssubdp, MCK_RegVSFRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10910 /* xssubsp */, PPC::XSSUBSP, Convert__RegVSSRC1_1__RegVSSRC1_2__RegVSSRC1_3, 0, { MCK_xssubsp, MCK_RegVSSRC, MCK_RegVSSRC, MCK_RegVSSRC }, },
  { 10918 /* xstdivdp */, PPC::XSTDIVDP, Convert__RegCRRC1_1__RegVSFRC1_2__RegVSFRC1_3, 0, { MCK_xstdivdp, MCK_RegCRRC, MCK_RegVSFRC, MCK_RegVSFRC }, },
  { 10927 /* xstsqrtdp */, PPC::XSTSQRTDP, Convert__RegCRRC1_1__RegVSFRC1_2, 0, { MCK_xstsqrtdp, MCK_RegCRRC, MCK_RegVSFRC }, },
  { 10937 /* xvabsdp */, PPC::XVABSDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvabsdp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10945 /* xvabssp */, PPC::XVABSSP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvabssp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10953 /* xvadddp */, PPC::XVADDDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvadddp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10961 /* xvaddsp */, PPC::XVADDSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvaddsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10969 /* xvcmpeqdp */, PPC::XVCMPEQDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvcmpeqdp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10969 /* xvcmpeqdp */, PPC::XVCMPEQDPo, Convert__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4, 0, { MCK_xvcmpeqdp, MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10979 /* xvcmpeqsp */, PPC::XVCMPEQSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvcmpeqsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10979 /* xvcmpeqsp */, PPC::XVCMPEQSPo, Convert__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4, 0, { MCK_xvcmpeqsp, MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10989 /* xvcmpgedp */, PPC::XVCMPGEDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvcmpgedp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10989 /* xvcmpgedp */, PPC::XVCMPGEDPo, Convert__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4, 0, { MCK_xvcmpgedp, MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10999 /* xvcmpgesp */, PPC::XVCMPGESP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvcmpgesp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 10999 /* xvcmpgesp */, PPC::XVCMPGESPo, Convert__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4, 0, { MCK_xvcmpgesp, MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11009 /* xvcmpgtdp */, PPC::XVCMPGTDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvcmpgtdp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11009 /* xvcmpgtdp */, PPC::XVCMPGTDPo, Convert__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4, 0, { MCK_xvcmpgtdp, MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11019 /* xvcmpgtsp */, PPC::XVCMPGTSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvcmpgtsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11019 /* xvcmpgtsp */, PPC::XVCMPGTSPo, Convert__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4, 0, { MCK_xvcmpgtsp, MCK__DOT_, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11029 /* xvcpsgndp */, PPC::XVCPSGNDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvcpsgndp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11039 /* xvcpsgnsp */, PPC::XVCPSGNSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvcpsgnsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11049 /* xvcvdpsp */, PPC::XVCVDPSP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvdpsp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11058 /* xvcvdpsxds */, PPC::XVCVDPSXDS, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvdpsxds, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11069 /* xvcvdpsxws */, PPC::XVCVDPSXWS, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvdpsxws, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11080 /* xvcvdpuxds */, PPC::XVCVDPUXDS, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvdpuxds, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11091 /* xvcvdpuxws */, PPC::XVCVDPUXWS, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvdpuxws, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11102 /* xvcvspdp */, PPC::XVCVSPDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvspdp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11111 /* xvcvspsxds */, PPC::XVCVSPSXDS, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvspsxds, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11122 /* xvcvspsxws */, PPC::XVCVSPSXWS, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvspsxws, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11133 /* xvcvspuxds */, PPC::XVCVSPUXDS, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvspuxds, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11144 /* xvcvspuxws */, PPC::XVCVSPUXWS, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvspuxws, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11155 /* xvcvsxddp */, PPC::XVCVSXDDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvsxddp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11165 /* xvcvsxdsp */, PPC::XVCVSXDSP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvsxdsp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11175 /* xvcvsxwdp */, PPC::XVCVSXWDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvsxwdp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11185 /* xvcvsxwsp */, PPC::XVCVSXWSP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvsxwsp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11195 /* xvcvuxddp */, PPC::XVCVUXDDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvuxddp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11205 /* xvcvuxdsp */, PPC::XVCVUXDSP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvuxdsp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11215 /* xvcvuxwdp */, PPC::XVCVUXWDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvuxwdp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11225 /* xvcvuxwsp */, PPC::XVCVUXWSP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvcvuxwsp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11235 /* xvdivdp */, PPC::XVDIVDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvdivdp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11243 /* xvdivsp */, PPC::XVDIVSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvdivsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11251 /* xvmaddadp */, PPC::XVMADDADP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmaddadp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11261 /* xvmaddasp */, PPC::XVMADDASP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmaddasp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11271 /* xvmaddmdp */, PPC::XVMADDMDP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmaddmdp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11281 /* xvmaddmsp */, PPC::XVMADDMSP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmaddmsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11291 /* xvmaxdp */, PPC::XVMAXDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmaxdp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11299 /* xvmaxsp */, PPC::XVMAXSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmaxsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11307 /* xvmindp */, PPC::XVMINDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmindp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11315 /* xvminsp */, PPC::XVMINSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvminsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11323 /* xvmovdp */, PPC::XVCPSGNDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2, 0, { MCK_xvmovdp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11331 /* xvmovsp */, PPC::XVCPSGNSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2, 0, { MCK_xvmovsp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11339 /* xvmsubadp */, PPC::XVMSUBADP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmsubadp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11349 /* xvmsubasp */, PPC::XVMSUBASP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmsubasp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11359 /* xvmsubmdp */, PPC::XVMSUBMDP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmsubmdp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11369 /* xvmsubmsp */, PPC::XVMSUBMSP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmsubmsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11379 /* xvmuldp */, PPC::XVMULDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmuldp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11387 /* xvmulsp */, PPC::XVMULSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvmulsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11395 /* xvnabsdp */, PPC::XVNABSDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvnabsdp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11404 /* xvnabssp */, PPC::XVNABSSP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvnabssp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11413 /* xvnegdp */, PPC::XVNEGDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvnegdp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11421 /* xvnegsp */, PPC::XVNEGSP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvnegsp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11429 /* xvnmaddadp */, PPC::XVNMADDADP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvnmaddadp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11440 /* xvnmaddasp */, PPC::XVNMADDASP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvnmaddasp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11451 /* xvnmaddmdp */, PPC::XVNMADDMDP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvnmaddmdp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11462 /* xvnmaddmsp */, PPC::XVNMADDMSP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvnmaddmsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11473 /* xvnmsubadp */, PPC::XVNMSUBADP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvnmsubadp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11484 /* xvnmsubasp */, PPC::XVNMSUBASP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvnmsubasp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11495 /* xvnmsubmdp */, PPC::XVNMSUBMDP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvnmsubmdp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11506 /* xvnmsubmsp */, PPC::XVNMSUBMSP, Convert__RegVSRC1_1__Tie0__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvnmsubmsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11517 /* xvrdpi */, PPC::XVRDPI, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrdpi, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11524 /* xvrdpic */, PPC::XVRDPIC, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrdpic, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11532 /* xvrdpim */, PPC::XVRDPIM, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrdpim, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11540 /* xvrdpip */, PPC::XVRDPIP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrdpip, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11548 /* xvrdpiz */, PPC::XVRDPIZ, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrdpiz, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11556 /* xvredp */, PPC::XVREDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvredp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11563 /* xvresp */, PPC::XVRESP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvresp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11570 /* xvrspi */, PPC::XVRSPI, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrspi, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11577 /* xvrspic */, PPC::XVRSPIC, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrspic, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11585 /* xvrspim */, PPC::XVRSPIM, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrspim, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11593 /* xvrspip */, PPC::XVRSPIP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrspip, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11601 /* xvrspiz */, PPC::XVRSPIZ, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrspiz, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11609 /* xvrsqrtedp */, PPC::XVRSQRTEDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrsqrtedp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11620 /* xvrsqrtesp */, PPC::XVRSQRTESP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvrsqrtesp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11631 /* xvsqrtdp */, PPC::XVSQRTDP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvsqrtdp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11640 /* xvsqrtsp */, PPC::XVSQRTSP, Convert__RegVSRC1_1__RegVSRC1_2, 0, { MCK_xvsqrtsp, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11649 /* xvsubdp */, PPC::XVSUBDP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvsubdp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11657 /* xvsubsp */, PPC::XVSUBSP, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvsubsp, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11665 /* xvtdivdp */, PPC::XVTDIVDP, Convert__RegCRRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvtdivdp, MCK_RegCRRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11674 /* xvtdivsp */, PPC::XVTDIVSP, Convert__RegCRRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xvtdivsp, MCK_RegCRRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11683 /* xvtsqrtdp */, PPC::XVTSQRTDP, Convert__RegCRRC1_1__RegVSRC1_2, 0, { MCK_xvtsqrtdp, MCK_RegCRRC, MCK_RegVSRC }, },
  { 11693 /* xvtsqrtsp */, PPC::XVTSQRTSP, Convert__RegCRRC1_1__RegVSRC1_2, 0, { MCK_xvtsqrtsp, MCK_RegCRRC, MCK_RegVSRC }, },
  { 11703 /* xxland */, PPC::XXLAND, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxland, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11710 /* xxlandc */, PPC::XXLANDC, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxlandc, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11718 /* xxleqv */, PPC::XXLEQV, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxleqv, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11725 /* xxlnand */, PPC::XXLNAND, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxlnand, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11733 /* xxlnor */, PPC::XXLNOR, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxlnor, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11740 /* xxlor */, PPC::XXLOR, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxlor, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11746 /* xxlorc */, PPC::XXLORC, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxlorc, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11753 /* xxlxor */, PPC::XXLXOR, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxlxor, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11760 /* xxmrghd */, PPC::XXPERMDI, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__imm_95_0, 0, { MCK_xxmrghd, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11768 /* xxmrghw */, PPC::XXMRGHW, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxmrghw, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11776 /* xxmrgld */, PPC::XXPERMDI, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__imm_95_3, 0, { MCK_xxmrgld, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11784 /* xxmrglw */, PPC::XXMRGLW, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3, 0, { MCK_xxmrglw, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11792 /* xxpermdi */, PPC::XXPERMDI, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__U2Imm1_4, 0, { MCK_xxpermdi, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC, MCK_U2Imm }, },
  { 11801 /* xxsel */, PPC::XXSEL, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__RegVSRC1_4, 0, { MCK_xxsel, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC }, },
  { 11807 /* xxsldwi */, PPC::XXSLDWI, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_3__U2Imm1_4, 0, { MCK_xxsldwi, MCK_RegVSRC, MCK_RegVSRC, MCK_RegVSRC, MCK_U2Imm }, },
  { 11815 /* xxspltd */, PPC::XXPERMDI, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2__imm_95_0, 0, { MCK_xxspltd, MCK_RegVSRC, MCK_RegVSRC, MCK_0 }, },
  { 11815 /* xxspltd */, PPC::XXPERMDI, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2__imm_95_3, 0, { MCK_xxspltd, MCK_RegVSRC, MCK_RegVSRC, MCK_1 }, },
  { 11823 /* xxspltw */, PPC::XXSPLTW, Convert__RegVSRC1_1__RegVSRC1_2__U2Imm1_3, 0, { MCK_xxspltw, MCK_RegVSRC, MCK_RegVSRC, MCK_U2Imm }, },
  { 11831 /* xxswapd */, PPC::XXPERMDI, Convert__RegVSRC1_1__RegVSRC1_2__RegVSRC1_2__imm_95_2, 0, { MCK_xxswapd, MCK_RegVSRC, MCK_RegVSRC }, },
};

bool PPCAsmParser::
mnemonicIsValid(StringRef Mnemonic, unsigned VariantID) {
  // Find the appropriate table for this asm variant.
  const MatchEntry *Start, *End;
  switch (VariantID) {
  default: llvm_unreachable("invalid variant!");
  case 0: Start = std::begin(MatchTable0); End = std::end(MatchTable0); break;
  }
  // Search the table.
  std::pair<const MatchEntry*, const MatchEntry*> MnemonicRange =
    std::equal_range(Start, End, Mnemonic, LessOpcode());
  return MnemonicRange.first != MnemonicRange.second;
}

unsigned PPCAsmParser::
MatchInstructionImpl(const OperandVector &Operands,
                     MCInst &Inst, uint64_t &ErrorInfo,
                     bool matchingInlineAsm, unsigned VariantID) {
  // Eliminate obvious mismatches.
  if (Operands.size() > 7) {
    ErrorInfo = 7;
    return Match_InvalidOperand;
  }

  // Get the current feature set.
  uint64_t AvailableFeatures = getAvailableFeatures();

  // Get the instruction mnemonic, which is the first token.
  StringRef Mnemonic;
  if (Operands[0]->isToken())
    Mnemonic = ((PPCOperand&)*Operands[0]).getToken();

  // Process all MnemonicAliases to remap the mnemonic.
  applyMnemonicAliases(Mnemonic, AvailableFeatures, VariantID);

  // Some state to try to produce better error messages.
  bool HadMatchOtherThanFeatures = false;
  bool HadMatchOtherThanPredicate = false;
  unsigned RetCode = Match_InvalidOperand;
  uint64_t MissingFeatures = ~0ULL;
  // Set ErrorInfo to the operand that mismatches if it is
  // wrong for all instances of the instruction.
  ErrorInfo = ~0ULL;
  // Find the appropriate table for this asm variant.
  const MatchEntry *Start, *End;
  switch (VariantID) {
  default: llvm_unreachable("invalid variant!");
  case 0: Start = std::begin(MatchTable0); End = std::end(MatchTable0); break;
  }
  // Search the table.
  std::pair<const MatchEntry*, const MatchEntry*>MnemonicRange(Start, End);
  unsigned SIndex = Mnemonic.empty() ? 0 : 1;
  if (!Mnemonic.empty())
    MnemonicRange = std::equal_range(Start, End, Mnemonic.lower(), LessOpcode());

  // Return a more specific error code if no mnemonics match.
  if (MnemonicRange.first == MnemonicRange.second)
    return Match_MnemonicFail;

  for (const MatchEntry *it = MnemonicRange.first, *ie = MnemonicRange.second;
       it != ie; ++it) {
    bool OperandsValid = true;
    for (unsigned i = SIndex; i != 7; ++i) {
      auto Formal = static_cast<MatchClassKind>(it->Classes[i]);
      if (i >= Operands.size()) {
        OperandsValid = (Formal == InvalidMatchClass);
        if (!OperandsValid) ErrorInfo = i;
        break;
      }
      MCParsedAsmOperand &Actual = *Operands[i];
      unsigned Diag = validateOperandClass(Actual, Formal);
      if (Diag == Match_Success)
        continue;
      // If the generic handler indicates an invalid operand
      // failure, check for a special case.
      if (Diag == Match_InvalidOperand) {
        Diag = validateTargetOperandClass(Actual, Formal);
        if (Diag == Match_Success)
          continue;
      }
      // If this operand is broken for all of the instances of this
      // mnemonic, keep track of it so we can report loc info.
      // If we already had a match that only failed due to a
      // target predicate, that diagnostic is preferred.
      if (!HadMatchOtherThanPredicate &&
          (it == MnemonicRange.first || ErrorInfo <= i)) {
        ErrorInfo = i;
        // InvalidOperand is the default. Prefer specificity.
        if (Diag != Match_InvalidOperand)
          RetCode = Diag;
      }
      // Otherwise, just reject this instance of the mnemonic.
      OperandsValid = false;
      break;
    }

    if (!OperandsValid) continue;
    if ((AvailableFeatures & it->RequiredFeatures) != it->RequiredFeatures) {
      HadMatchOtherThanFeatures = true;
      uint64_t NewMissingFeatures = it->RequiredFeatures & ~AvailableFeatures;
      if (countPopulation(NewMissingFeatures) <=
          countPopulation(MissingFeatures))
        MissingFeatures = NewMissingFeatures;
      continue;
    }

    Inst.clear();

    if (matchingInlineAsm) {
      Inst.setOpcode(it->Opcode);
      convertToMapAndConstraints(it->ConvertFn, Operands);
      return Match_Success;
    }

    // We have selected a definite instruction, convert the parsed
    // operands into the appropriate MCInst.
    convertToMCInst(it->ConvertFn, Inst, it->Opcode, Operands);

    // We have a potential match. Check the target predicate to
    // handle any context sensitive constraints.
    unsigned MatchResult;
    if ((MatchResult = checkTargetMatchPredicate(Inst)) != Match_Success) {
      Inst.clear();
      RetCode = MatchResult;
      HadMatchOtherThanPredicate = true;
      continue;
    }

    std::string Info;
    if (MII.get(Inst.getOpcode()).getDeprecatedInfo(Inst, getSTI(), Info)) {
      SMLoc Loc = ((PPCOperand&)*Operands[0]).getStartLoc();
      getParser().Warning(Loc, Info, None);
    }
    return Match_Success;
  }

  // Okay, we had no match.  Try to return a useful error code.
  if (HadMatchOtherThanPredicate || !HadMatchOtherThanFeatures)
    return RetCode;

  // Missing feature matches return which features were missing
  ErrorInfo = MissingFeatures;
  return Match_MissingFeature;
}

#endif // GET_MATCHER_IMPLEMENTATION

