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

  enum OperandMatchResultTy {
    MatchOperand_Success,    // operand matched successfully
    MatchOperand_NoMatch,    // operand did not match
    MatchOperand_ParseFail   // operand matched but had errors
  };
  OperandMatchResultTy MatchOperandParserImpl(
    OperandVector &Operands,
    StringRef Mnemonic);
  OperandMatchResultTy tryCustomParseOperand(
    OperandVector &Operands,
    unsigned MCK);

#endif // GET_ASSEMBLER_HEADER_INFO


#ifdef GET_OPERAND_DIAGNOSTIC_TYPES
#undef GET_OPERAND_DIAGNOSTIC_TYPES

#endif // GET_OPERAND_DIAGNOSTIC_TYPES


#ifdef GET_REGISTER_MATCHER
#undef GET_REGISTER_MATCHER

// Flags for subtarget features that participate in instruction matching.
enum SubtargetFeatureFlag : uint8_t {
  Feature_HasV9 = (1ULL << 0),
  Feature_HasVIS = (1ULL << 1),
  Feature_HasVIS2 = (1ULL << 2),
  Feature_HasVIS3 = (1ULL << 3),
  Feature_None = 0
};

#endif // GET_REGISTER_MATCHER


#ifdef GET_SUBTARGET_FEATURE_NAME
#undef GET_SUBTARGET_FEATURE_NAME

// User-level names for subtarget features that participate in
// instruction matching.
static const char *getSubtargetFeatureName(uint64_t Val) {
  switch(Val) {
  case Feature_HasV9: return "";
  case Feature_HasVIS: return "";
  case Feature_HasVIS2: return "";
  case Feature_HasVIS3: return "";
  default: return "(unknown)";
  }
}

#endif // GET_SUBTARGET_FEATURE_NAME


#ifdef GET_MATCHER_IMPLEMENTATION
#undef GET_MATCHER_IMPLEMENTATION

static void applyMnemonicAliases(StringRef &Mnemonic, uint64_t Features, unsigned VariantID) {
  switch (VariantID) {
    case 0:
      switch (Mnemonic.size()) {
      default: break;
      case 4:	 // 3 strings to match.
        switch (Mnemonic[0]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "ddc", 3))
            break;
          if ((Features & Feature_HasV9) == Feature_HasV9)	 // "addc"
            Mnemonic = "addx";
          return;
        case 'l':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "duw", 3))
            break;
          if ((Features & Feature_HasV9) == Feature_HasV9)	 // "lduw"
            Mnemonic = "ld";
          return;
        case 's':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "ubc", 3))
            break;
          if ((Features & Feature_HasV9) == Feature_HasV9)	 // "subc"
            Mnemonic = "subx";
          return;
        }
        break;
      case 5:	 // 1 string to match.
        if (memcmp(Mnemonic.data()+0, "lduwa", 5))
          break;
        if ((Features & Feature_HasV9) == Feature_HasV9)	 // "lduwa"
          Mnemonic = "lda";
        return;
      case 6:	 // 3 strings to match.
        switch (Mnemonic[0]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "ddccc", 5))
            break;
          if ((Features & Feature_HasV9) == Feature_HasV9)	 // "addccc"
            Mnemonic = "addxcc";
          return;
        case 'r':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "eturn", 5))
            break;
          if ((Features & Feature_HasV9) == Feature_HasV9)	 // "return"
            Mnemonic = "rett";
          return;
        case 's':	 // 1 string to match.
          if (memcmp(Mnemonic.data()+1, "ubccc", 5))
            break;
          if ((Features & Feature_HasV9) == Feature_HasV9)	 // "subccc"
            Mnemonic = "subxcc";
          return;
        }
        break;
      }
    break;
  }
  switch (Mnemonic.size()) {
  default: break;
  case 4:	 // 3 strings to match.
    switch (Mnemonic[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "ddc", 3))
        break;
      if ((Features & Feature_HasV9) == Feature_HasV9)	 // "addc"
        Mnemonic = "addx";
      return;
    case 'l':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "duw", 3))
        break;
      if ((Features & Feature_HasV9) == Feature_HasV9)	 // "lduw"
        Mnemonic = "ld";
      return;
    case 's':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "ubc", 3))
        break;
      if ((Features & Feature_HasV9) == Feature_HasV9)	 // "subc"
        Mnemonic = "subx";
      return;
    }
    break;
  case 5:	 // 1 string to match.
    if (memcmp(Mnemonic.data()+0, "lduwa", 5))
      break;
    if ((Features & Feature_HasV9) == Feature_HasV9)	 // "lduwa"
      Mnemonic = "lda";
    return;
  case 6:	 // 3 strings to match.
    switch (Mnemonic[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "ddccc", 5))
        break;
      if ((Features & Feature_HasV9) == Feature_HasV9)	 // "addccc"
        Mnemonic = "addxcc";
      return;
    case 'r':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "eturn", 5))
        break;
      if ((Features & Feature_HasV9) == Feature_HasV9)	 // "return"
        Mnemonic = "rett";
      return;
    case 's':	 // 1 string to match.
      if (memcmp(Mnemonic.data()+1, "ubccc", 5))
        break;
      if ((Features & Feature_HasV9) == Feature_HasV9)	 // "subccc"
        Mnemonic = "subxcc";
      return;
    }
    break;
  }
}

namespace {
enum OperatorConversionKind {
  CVT_Done,
  CVT_Reg,
  CVT_Tied,
  CVT_95_Reg,
  CVT_95_addImmOperands,
  CVT_imm_95_8,
  CVT_imm_95_13,
  CVT_imm_95_5,
  CVT_imm_95_1,
  CVT_imm_95_10,
  CVT_imm_95_11,
  CVT_imm_95_12,
  CVT_imm_95_3,
  CVT_imm_95_2,
  CVT_imm_95_4,
  CVT_imm_95_0,
  CVT_imm_95_9,
  CVT_imm_95_6,
  CVT_imm_95_14,
  CVT_regG0,
  CVT_imm_95_15,
  CVT_imm_95_7,
  CVT_regO7,
  CVT_95_addMEMriOperands,
  CVT_95_addMEMrrOperands,
  CVT_regFCC0,
  CVT_NUM_CONVERTERS
};

enum InstructionConversionKind {
  Convert__Reg1_3__Reg1_1__Reg1_2,
  Convert__Reg1_3__Reg1_1__Imm1_2,
  Convert__Imm1_1__imm_95_8,
  Convert__Imm1_2__imm_95_8,
  Convert__Imm1_2__Imm1_1,
  Convert__Imm1_3__imm_95_8,
  Convert__Imm1_3__Imm1_1,
  Convert__Imm1_4__imm_95_8,
  Convert__Imm1_4__Imm1_1,
  Convert__Imm1_5__Imm1_1,
  Convert__Imm1_1,
  Convert__Imm1_1__imm_95_13,
  Convert__Imm1_2__imm_95_13,
  Convert__Imm1_3__imm_95_13,
  Convert__Imm1_4__imm_95_13,
  Convert__Reg1_2__Reg1_2__Reg1_1,
  Convert__Reg1_2__Reg1_2__Imm1_1,
  Convert__Imm1_1__imm_95_5,
  Convert__Imm1_2__imm_95_5,
  Convert__Imm1_3__imm_95_5,
  Convert__Imm1_4__imm_95_5,
  Convert__Imm1_1__imm_95_1,
  Convert__Imm1_2__imm_95_1,
  Convert__Imm1_3__imm_95_1,
  Convert__Imm1_4__imm_95_1,
  Convert__Imm1_1__imm_95_10,
  Convert__Imm1_2__imm_95_10,
  Convert__Imm1_3__imm_95_10,
  Convert__Imm1_4__imm_95_10,
  Convert__Imm1_1__imm_95_11,
  Convert__Imm1_2__imm_95_11,
  Convert__Imm1_3__imm_95_11,
  Convert__Imm1_4__imm_95_11,
  Convert__Imm1_1__imm_95_12,
  Convert__Imm1_2__imm_95_12,
  Convert__Imm1_3__imm_95_12,
  Convert__Imm1_4__imm_95_12,
  Convert__Imm1_1__imm_95_3,
  Convert__Imm1_2__imm_95_3,
  Convert__Imm1_3__imm_95_3,
  Convert__Imm1_4__imm_95_3,
  Convert__Imm1_1__imm_95_2,
  Convert__Imm1_2__imm_95_2,
  Convert__Imm1_3__imm_95_2,
  Convert__Imm1_4__imm_95_2,
  Convert__Imm1_1__imm_95_4,
  Convert__Imm1_2__imm_95_4,
  Convert__Imm1_3__imm_95_4,
  Convert__Imm1_4__imm_95_4,
  Convert__Imm1_1__imm_95_0,
  Convert__Imm1_2__imm_95_0,
  Convert__Imm1_3__imm_95_0,
  Convert__Imm1_4__imm_95_0,
  Convert__Imm1_1__imm_95_9,
  Convert__Imm1_2__imm_95_9,
  Convert__Imm1_3__imm_95_9,
  Convert__Imm1_4__imm_95_9,
  Convert__Imm1_1__imm_95_6,
  Convert__Imm1_2__imm_95_6,
  Convert__Imm1_3__imm_95_6,
  Convert__Imm1_4__imm_95_6,
  Convert__Imm1_1__imm_95_14,
  Convert__Imm1_2__imm_95_14,
  Convert__Imm1_3__imm_95_14,
  Convert__Imm1_4__imm_95_14,
  Convert__Reg1_1__Imm1_2,
  Convert__Reg1_2__Imm1_3,
  Convert__Reg1_3__Imm1_4,
  Convert__regG0__Reg1_2__Reg1_1,
  Convert__regG0__Reg1_2__Imm1_1,
  Convert__Imm1_1__imm_95_15,
  Convert__Imm1_2__imm_95_15,
  Convert__Imm1_3__imm_95_15,
  Convert__Imm1_4__imm_95_15,
  Convert__Imm1_1__imm_95_7,
  Convert__Imm1_2__imm_95_7,
  Convert__Imm1_3__imm_95_7,
  Convert__Imm1_4__imm_95_7,
  Convert__regO7__MEMri2_1,
  Convert__regO7__MEMrr2_1,
  Convert__Reg1_5__Reg1_2__Reg1_4__Tie0,
  Convert__Reg1_1__regG0__regG0,
  Convert__MEMri2_2__regG0,
  Convert__MEMrr2_2__regG0,
  Convert__Reg1_1,
  Convert__Reg1_1__Reg1_2,
  Convert__Reg1_1__Reg1_1__imm_95_1,
  Convert__Reg1_2__Reg1_1,
  Convert__Imm1_2__imm_95_0__Reg1_1,
  Convert__Imm1_3__imm_95_0__Reg1_2,
  Convert__Imm1_3__Imm1_1__Reg1_2,
  Convert__Imm1_4__imm_95_0__Reg1_3,
  Convert__Imm1_4__Imm1_1__Reg1_3,
  Convert__Imm1_5__Imm1_1__Reg1_4,
  Convert__Imm1_2__imm_95_9__Reg1_1,
  Convert__Imm1_3__imm_95_9__Reg1_2,
  Convert__Imm1_4__imm_95_9__Reg1_3,
  Convert__Imm1_2__imm_95_6__Reg1_1,
  Convert__Imm1_3__imm_95_6__Reg1_2,
  Convert__Imm1_4__imm_95_6__Reg1_3,
  Convert__Imm1_2__imm_95_11__Reg1_1,
  Convert__Imm1_3__imm_95_11__Reg1_2,
  Convert__Imm1_4__imm_95_11__Reg1_3,
  Convert__Imm1_2__imm_95_4__Reg1_1,
  Convert__Imm1_3__imm_95_4__Reg1_2,
  Convert__Imm1_4__imm_95_4__Reg1_3,
  Convert__Imm1_2__imm_95_13__Reg1_1,
  Convert__Imm1_3__imm_95_13__Reg1_2,
  Convert__Imm1_4__imm_95_13__Reg1_3,
  Convert__Imm1_2__imm_95_2__Reg1_1,
  Convert__Imm1_3__imm_95_2__Reg1_2,
  Convert__Imm1_4__imm_95_2__Reg1_3,
  Convert__Imm1_2__imm_95_8__Reg1_1,
  Convert__Imm1_3__imm_95_8__Reg1_2,
  Convert__Imm1_4__imm_95_8__Reg1_3,
  Convert__Imm1_2__imm_95_1__Reg1_1,
  Convert__Imm1_3__imm_95_1__Reg1_2,
  Convert__Imm1_4__imm_95_1__Reg1_3,
  Convert__Imm1_2__imm_95_15__Reg1_1,
  Convert__Imm1_3__imm_95_15__Reg1_2,
  Convert__Imm1_4__imm_95_15__Reg1_3,
  Convert__Imm1_2__imm_95_7__Reg1_1,
  Convert__Imm1_3__imm_95_7__Reg1_2,
  Convert__Imm1_4__imm_95_7__Reg1_3,
  Convert__Imm1_2__imm_95_10__Reg1_1,
  Convert__Imm1_3__imm_95_10__Reg1_2,
  Convert__Imm1_4__imm_95_10__Reg1_3,
  Convert__Imm1_2__imm_95_5__Reg1_1,
  Convert__Imm1_3__imm_95_5__Reg1_2,
  Convert__Imm1_4__imm_95_5__Reg1_3,
  Convert__Imm1_2__imm_95_12__Reg1_1,
  Convert__Imm1_3__imm_95_12__Reg1_2,
  Convert__Imm1_4__imm_95_12__Reg1_3,
  Convert__Imm1_2__imm_95_3__Reg1_1,
  Convert__Imm1_3__imm_95_3__Reg1_2,
  Convert__Imm1_4__imm_95_3__Reg1_3,
  Convert__Imm1_2__imm_95_14__Reg1_1,
  Convert__Imm1_3__imm_95_14__Reg1_2,
  Convert__Imm1_4__imm_95_14__Reg1_3,
  Convert__regFCC0__Reg1_1__Reg1_2,
  Convert__Reg1_1__Reg1_2__Reg1_3,
  Convert_NoOperands,
  Convert__MEMri2_1,
  Convert__MEMrr2_1,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_8,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0,
  Convert__Reg1_4__Reg1_3__Tie0__Imm1_1,
  Convert__Reg1_4__Reg1_2__Reg1_3__Tie0__Imm1_1,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_13,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_5,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_1,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_10,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_6,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_11,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_11,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_12,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_3,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_4,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_2,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_13,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_4,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_2,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_0,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_8,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_9,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_6,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_15,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_14,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_7,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_10,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_5,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_12,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_3,
  Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_14,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_15,
  Convert__Reg1_3__Reg1_2__Tie0__imm_95_7,
  Convert__Reg1_1__Tie0,
  Convert__regG0__MEMri2_1,
  Convert__regG0__MEMrr2_1,
  Convert__Reg1_2__MEMri2_1,
  Convert__Reg1_2__MEMrr2_1,
  Convert__MEMri2_2,
  Convert__Reg1_4__MEMri2_2,
  Convert__MEMrr2_2,
  Convert__Reg1_4__MEMrr2_2,
  Convert__Reg1_5__MEMrr2_2__Imm1_4,
  Convert__Reg1_2,
  Convert__regG0__Reg1_1,
  Convert__Reg1_2__regG0__Reg1_1,
  Convert__regG0__Imm1_1,
  Convert__Reg1_2__regG0__Imm1_1,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_8,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_0,
  Convert__Reg1_4__Imm1_3__Tie0__Imm1_1,
  Convert__Reg1_4__Reg1_2__Imm1_3__Tie0__Imm1_1,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_13,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_5,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_1,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_9,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_10,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_6,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_11,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_11,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_12,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_3,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_4,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_2,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_13,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_4,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_2,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_0,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_8,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_9,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_1,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_6,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_15,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_14,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_7,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_10,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_5,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_12,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_3,
  Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_14,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_15,
  Convert__Reg1_3__Imm1_2__Tie0__imm_95_7,
  Convert__Reg1_1__regG0__Reg1_1,
  Convert__Reg1_1__Reg1_1__regG0,
  Convert__Reg1_2__Reg1_1__regG0,
  Convert__regG0__regG0__regG0,
  Convert__imm_95_8,
  Convert__Reg1_2__Imm1_1,
  Convert__MEMri2_3,
  Convert__MEMrr2_3,
  Convert__MEMri2_3__Reg1_1,
  Convert__MEMrr2_3__Reg1_1,
  Convert__MEMrr2_3__Reg1_1__Imm1_5,
  Convert__Reg1_4__MEMri2_2__Tie0,
  Convert__Reg1_4__MEMrr2_2__Tie0,
  Convert__Reg1_5__MEMrr2_2__Imm1_4__Tie0,
  Convert__regG0__Reg1_1__imm_95_8,
  Convert__regG0__Imm1_1__imm_95_8,
  Convert__regG0__Reg1_2__imm_95_8,
  Convert__regG0__Imm1_2__imm_95_8,
  Convert__Reg1_1__Reg1_3__imm_95_8,
  Convert__Reg1_1__Imm1_3__imm_95_8,
  Convert__Reg1_2__Reg1_4__imm_95_8,
  Convert__Reg1_2__Imm1_4__imm_95_8,
  Convert__Reg1_3__Reg1_5__Imm1_1,
  Convert__Reg1_3__Imm1_5__Imm1_1,
  Convert__regG0__Reg1_1__imm_95_13,
  Convert__regG0__Imm1_1__imm_95_13,
  Convert__regG0__Reg1_2__imm_95_13,
  Convert__regG0__Imm1_2__imm_95_13,
  Convert__Reg1_1__Reg1_3__imm_95_13,
  Convert__Reg1_1__Imm1_3__imm_95_13,
  Convert__Reg1_2__Reg1_4__imm_95_13,
  Convert__Reg1_2__Imm1_4__imm_95_13,
  Convert__regG0__Reg1_1__imm_95_5,
  Convert__regG0__Imm1_1__imm_95_5,
  Convert__regG0__Reg1_2__imm_95_5,
  Convert__regG0__Imm1_2__imm_95_5,
  Convert__Reg1_1__Reg1_3__imm_95_5,
  Convert__Reg1_1__Imm1_3__imm_95_5,
  Convert__Reg1_2__Reg1_4__imm_95_5,
  Convert__Reg1_2__Imm1_4__imm_95_5,
  Convert__regG0__Reg1_1__imm_95_1,
  Convert__regG0__Imm1_1__imm_95_1,
  Convert__regG0__Reg1_2__imm_95_1,
  Convert__regG0__Imm1_2__imm_95_1,
  Convert__Reg1_1__Reg1_3__imm_95_1,
  Convert__Reg1_1__Imm1_3__imm_95_1,
  Convert__Reg1_2__Reg1_4__imm_95_1,
  Convert__Reg1_2__Imm1_4__imm_95_1,
  Convert__regG0__Reg1_1__imm_95_10,
  Convert__regG0__Imm1_1__imm_95_10,
  Convert__regG0__Reg1_2__imm_95_10,
  Convert__regG0__Imm1_2__imm_95_10,
  Convert__Reg1_1__Reg1_3__imm_95_10,
  Convert__Reg1_1__Imm1_3__imm_95_10,
  Convert__Reg1_2__Reg1_4__imm_95_10,
  Convert__Reg1_2__Imm1_4__imm_95_10,
  Convert__regG0__Reg1_1__imm_95_11,
  Convert__regG0__Imm1_1__imm_95_11,
  Convert__regG0__Reg1_2__imm_95_11,
  Convert__regG0__Imm1_2__imm_95_11,
  Convert__Reg1_1__Reg1_3__imm_95_11,
  Convert__Reg1_1__Imm1_3__imm_95_11,
  Convert__Reg1_2__Reg1_4__imm_95_11,
  Convert__Reg1_2__Imm1_4__imm_95_11,
  Convert__regG0__Reg1_1__imm_95_12,
  Convert__regG0__Imm1_1__imm_95_12,
  Convert__regG0__Reg1_2__imm_95_12,
  Convert__regG0__Imm1_2__imm_95_12,
  Convert__Reg1_1__Reg1_3__imm_95_12,
  Convert__Reg1_1__Imm1_3__imm_95_12,
  Convert__Reg1_2__Reg1_4__imm_95_12,
  Convert__Reg1_2__Imm1_4__imm_95_12,
  Convert__regG0__Reg1_1__imm_95_3,
  Convert__regG0__Imm1_1__imm_95_3,
  Convert__regG0__Reg1_2__imm_95_3,
  Convert__regG0__Imm1_2__imm_95_3,
  Convert__Reg1_1__Reg1_3__imm_95_3,
  Convert__Reg1_1__Imm1_3__imm_95_3,
  Convert__Reg1_2__Reg1_4__imm_95_3,
  Convert__Reg1_2__Imm1_4__imm_95_3,
  Convert__regG0__Reg1_1__imm_95_2,
  Convert__regG0__Imm1_1__imm_95_2,
  Convert__regG0__Reg1_2__imm_95_2,
  Convert__regG0__Imm1_2__imm_95_2,
  Convert__Reg1_1__Reg1_3__imm_95_2,
  Convert__Reg1_1__Imm1_3__imm_95_2,
  Convert__Reg1_2__Reg1_4__imm_95_2,
  Convert__Reg1_2__Imm1_4__imm_95_2,
  Convert__regG0__Reg1_1__imm_95_4,
  Convert__regG0__Imm1_1__imm_95_4,
  Convert__regG0__Reg1_2__imm_95_4,
  Convert__regG0__Imm1_2__imm_95_4,
  Convert__Reg1_1__Reg1_3__imm_95_4,
  Convert__Reg1_1__Imm1_3__imm_95_4,
  Convert__Reg1_2__Reg1_4__imm_95_4,
  Convert__Reg1_2__Imm1_4__imm_95_4,
  Convert__regG0__Reg1_1__imm_95_0,
  Convert__regG0__Imm1_1__imm_95_0,
  Convert__regG0__Reg1_2__imm_95_0,
  Convert__regG0__Imm1_2__imm_95_0,
  Convert__Reg1_1__Reg1_3__imm_95_0,
  Convert__Reg1_1__Imm1_3__imm_95_0,
  Convert__Reg1_2__Reg1_4__imm_95_0,
  Convert__Reg1_2__Imm1_4__imm_95_0,
  Convert__regG0__Reg1_1__imm_95_9,
  Convert__regG0__Imm1_1__imm_95_9,
  Convert__regG0__Reg1_2__imm_95_9,
  Convert__regG0__Imm1_2__imm_95_9,
  Convert__Reg1_1__Reg1_3__imm_95_9,
  Convert__Reg1_1__Imm1_3__imm_95_9,
  Convert__Reg1_2__Reg1_4__imm_95_9,
  Convert__Reg1_2__Imm1_4__imm_95_9,
  Convert__regG0__Reg1_1__imm_95_6,
  Convert__regG0__Imm1_1__imm_95_6,
  Convert__regG0__Reg1_2__imm_95_6,
  Convert__regG0__Imm1_2__imm_95_6,
  Convert__Reg1_1__Reg1_3__imm_95_6,
  Convert__Reg1_1__Imm1_3__imm_95_6,
  Convert__Reg1_2__Reg1_4__imm_95_6,
  Convert__Reg1_2__Imm1_4__imm_95_6,
  Convert__regG0__Reg1_1__imm_95_14,
  Convert__regG0__Imm1_1__imm_95_14,
  Convert__regG0__Reg1_2__imm_95_14,
  Convert__regG0__Imm1_2__imm_95_14,
  Convert__Reg1_1__Reg1_3__imm_95_14,
  Convert__Reg1_1__Imm1_3__imm_95_14,
  Convert__Reg1_2__Reg1_4__imm_95_14,
  Convert__Reg1_2__Imm1_4__imm_95_14,
  Convert__regG0__Reg1_1__regG0,
  Convert__regG0__Reg1_1__imm_95_15,
  Convert__regG0__Imm1_1__imm_95_15,
  Convert__regG0__Reg1_2__imm_95_15,
  Convert__regG0__Imm1_2__imm_95_15,
  Convert__Reg1_1__Reg1_3__imm_95_15,
  Convert__Reg1_1__Imm1_3__imm_95_15,
  Convert__Reg1_2__Reg1_4__imm_95_15,
  Convert__Reg1_2__Imm1_4__imm_95_15,
  Convert__regG0__Reg1_1__imm_95_7,
  Convert__regG0__Imm1_1__imm_95_7,
  Convert__regG0__Reg1_2__imm_95_7,
  Convert__regG0__Imm1_2__imm_95_7,
  Convert__Reg1_1__Reg1_3__imm_95_7,
  Convert__Reg1_1__Imm1_3__imm_95_7,
  Convert__Reg1_2__Reg1_4__imm_95_7,
  Convert__Reg1_2__Imm1_4__imm_95_7,
  CVT_NUM_SIGNATURES
};

} // end anonymous namespace

static const uint8_t ConversionTable[CVT_NUM_SIGNATURES][11] = {
  // Convert__Reg1_3__Reg1_1__Reg1_2
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Imm1_1__imm_95_8
  { CVT_95_addImmOperands, 1, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_8
  { CVT_95_addImmOperands, 2, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Imm1_2__Imm1_1
  { CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_8
  { CVT_95_addImmOperands, 3, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Imm1_3__Imm1_1
  { CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_4__imm_95_8
  { CVT_95_addImmOperands, 4, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Imm1_4__Imm1_1
  { CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_5__Imm1_1
  { CVT_95_addImmOperands, 5, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_1
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_1__imm_95_13
  { CVT_95_addImmOperands, 1, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_13
  { CVT_95_addImmOperands, 2, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_13
  { CVT_95_addImmOperands, 3, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_13
  { CVT_95_addImmOperands, 4, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Reg1_1
  { CVT_95_Reg, 2, CVT_95_Reg, 2, CVT_95_Reg, 1, CVT_Done },
  // Convert__Reg1_2__Reg1_2__Imm1_1
  { CVT_95_Reg, 2, CVT_95_Reg, 2, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_1__imm_95_5
  { CVT_95_addImmOperands, 1, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_5
  { CVT_95_addImmOperands, 2, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_5
  { CVT_95_addImmOperands, 3, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_5
  { CVT_95_addImmOperands, 4, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_1
  { CVT_95_addImmOperands, 1, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_1
  { CVT_95_addImmOperands, 3, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_1
  { CVT_95_addImmOperands, 4, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_10
  { CVT_95_addImmOperands, 1, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_10
  { CVT_95_addImmOperands, 2, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_10
  { CVT_95_addImmOperands, 3, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_10
  { CVT_95_addImmOperands, 4, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_11
  { CVT_95_addImmOperands, 1, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_11
  { CVT_95_addImmOperands, 2, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_11
  { CVT_95_addImmOperands, 3, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_11
  { CVT_95_addImmOperands, 4, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_12
  { CVT_95_addImmOperands, 1, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_12
  { CVT_95_addImmOperands, 2, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_12
  { CVT_95_addImmOperands, 3, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_12
  { CVT_95_addImmOperands, 4, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_3
  { CVT_95_addImmOperands, 1, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_3
  { CVT_95_addImmOperands, 2, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_3
  { CVT_95_addImmOperands, 3, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_2
  { CVT_95_addImmOperands, 1, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_2
  { CVT_95_addImmOperands, 2, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_2
  { CVT_95_addImmOperands, 4, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_4
  { CVT_95_addImmOperands, 1, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_4
  { CVT_95_addImmOperands, 2, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_4
  { CVT_95_addImmOperands, 3, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_4
  { CVT_95_addImmOperands, 4, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_0
  { CVT_95_addImmOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_0
  { CVT_95_addImmOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_0
  { CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_0
  { CVT_95_addImmOperands, 4, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_9
  { CVT_95_addImmOperands, 1, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_9
  { CVT_95_addImmOperands, 2, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_9
  { CVT_95_addImmOperands, 3, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_9
  { CVT_95_addImmOperands, 4, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_6
  { CVT_95_addImmOperands, 1, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_6
  { CVT_95_addImmOperands, 2, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_6
  { CVT_95_addImmOperands, 3, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_6
  { CVT_95_addImmOperands, 4, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_14
  { CVT_95_addImmOperands, 1, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_14
  { CVT_95_addImmOperands, 2, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_14
  { CVT_95_addImmOperands, 3, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_14
  { CVT_95_addImmOperands, 4, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_2
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_2__Imm1_3
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_3__Imm1_4
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__regG0__Reg1_2__Reg1_1
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_95_Reg, 1, CVT_Done },
  // Convert__regG0__Reg1_2__Imm1_1
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_1__imm_95_15
  { CVT_95_addImmOperands, 1, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_15
  { CVT_95_addImmOperands, 2, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_15
  { CVT_95_addImmOperands, 3, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_15
  { CVT_95_addImmOperands, 4, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Imm1_1__imm_95_7
  { CVT_95_addImmOperands, 1, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Imm1_2__imm_95_7
  { CVT_95_addImmOperands, 2, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Imm1_3__imm_95_7
  { CVT_95_addImmOperands, 3, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Imm1_4__imm_95_7
  { CVT_95_addImmOperands, 4, CVT_imm_95_7, 0, CVT_Done },
  // Convert__regO7__MEMri2_1
  { CVT_regO7, 0, CVT_95_addMEMriOperands, 1, CVT_Done },
  // Convert__regO7__MEMrr2_1
  { CVT_regO7, 0, CVT_95_addMEMrrOperands, 1, CVT_Done },
  // Convert__Reg1_5__Reg1_2__Reg1_4__Tie0
  { CVT_95_Reg, 5, CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_1__regG0__regG0
  { CVT_95_Reg, 1, CVT_regG0, 0, CVT_regG0, 0, CVT_Done },
  // Convert__MEMri2_2__regG0
  { CVT_95_addMEMriOperands, 2, CVT_regG0, 0, CVT_Done },
  // Convert__MEMrr2_2__regG0
  { CVT_95_addMEMrrOperands, 2, CVT_regG0, 0, CVT_Done },
  // Convert__Reg1_1
  { CVT_95_Reg, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_1__Reg1_1__imm_95_1
  { CVT_95_Reg, 1, CVT_95_Reg, 1, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_1
  { CVT_95_Reg, 2, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_2__imm_95_0__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_0, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_0__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_3__Imm1_1__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_95_addImmOperands, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_0__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_0, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_4__Imm1_1__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_95_addImmOperands, 1, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_5__Imm1_1__Reg1_4
  { CVT_95_addImmOperands, 5, CVT_95_addImmOperands, 1, CVT_95_Reg, 4, CVT_Done },
  // Convert__Imm1_2__imm_95_9__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_9, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_9__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_9, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_9__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_9, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_6__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_6, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_6__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_6, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_6__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_6, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_11__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_11, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_11__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_11, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_11__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_11, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_4__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_4, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_4__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_4, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_4__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_4, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_13__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_13, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_13__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_13, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_13__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_13, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_2__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_2, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_2__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_2, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_2__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_2, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_8__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_8, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_8__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_8, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_8__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_8, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_1__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_1, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_1__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_1, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_1__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_1, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_15__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_15, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_15__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_15, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_15__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_15, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_7__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_7, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_7__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_7, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_7__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_7, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_10__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_10, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_10__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_10, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_10__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_10, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_5__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_5, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_5__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_5, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_5__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_5, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_12__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_12, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_12__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_12, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_12__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_12, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_3__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_3, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_3__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_3, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_3__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_3, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__Imm1_2__imm_95_14__Reg1_1
  { CVT_95_addImmOperands, 2, CVT_imm_95_14, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Imm1_3__imm_95_14__Reg1_2
  { CVT_95_addImmOperands, 3, CVT_imm_95_14, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Imm1_4__imm_95_14__Reg1_3
  { CVT_95_addImmOperands, 4, CVT_imm_95_14, 0, CVT_95_Reg, 3, CVT_Done },
  // Convert__regFCC0__Reg1_1__Reg1_2
  { CVT_regFCC0, 0, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Reg1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Done },
  // Convert_NoOperands
  { CVT_Done },
  // Convert__MEMri2_1
  { CVT_95_addMEMriOperands, 1, CVT_Done },
  // Convert__MEMrr2_1
  { CVT_95_addMEMrrOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_8
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Reg1_4__Reg1_3__Tie0__Imm1_1
  { CVT_95_Reg, 4, CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Reg1_4__Reg1_2__Reg1_3__Tie0__Imm1_1
  { CVT_95_Reg, 4, CVT_95_Reg, 2, CVT_95_Reg, 3, CVT_Tied, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_13
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_5
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_1
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_10
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_6
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_11
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_11
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_12
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_3
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_4
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_2
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_13
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_4
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_2
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_0
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_8
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_9
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_6
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_15
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_14
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_7
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_10
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_5
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_12
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_3
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_14
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_15
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_2__Tie0__imm_95_7
  { CVT_95_Reg, 3, CVT_95_Reg, 2, CVT_Tied, 0, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Reg1_1__Tie0
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_Done },
  // Convert__regG0__MEMri2_1
  { CVT_regG0, 0, CVT_95_addMEMriOperands, 1, CVT_Done },
  // Convert__regG0__MEMrr2_1
  { CVT_regG0, 0, CVT_95_addMEMrrOperands, 1, CVT_Done },
  // Convert__Reg1_2__MEMri2_1
  { CVT_95_Reg, 2, CVT_95_addMEMriOperands, 1, CVT_Done },
  // Convert__Reg1_2__MEMrr2_1
  { CVT_95_Reg, 2, CVT_95_addMEMrrOperands, 1, CVT_Done },
  // Convert__MEMri2_2
  { CVT_95_addMEMriOperands, 2, CVT_Done },
  // Convert__Reg1_4__MEMri2_2
  { CVT_95_Reg, 4, CVT_95_addMEMriOperands, 2, CVT_Done },
  // Convert__MEMrr2_2
  { CVT_95_addMEMrrOperands, 2, CVT_Done },
  // Convert__Reg1_4__MEMrr2_2
  { CVT_95_Reg, 4, CVT_95_addMEMrrOperands, 2, CVT_Done },
  // Convert__Reg1_5__MEMrr2_2__Imm1_4
  { CVT_95_Reg, 5, CVT_95_addMEMrrOperands, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_2
  { CVT_95_Reg, 2, CVT_Done },
  // Convert__regG0__Reg1_1
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Reg1_2__regG0__Reg1_1
  { CVT_95_Reg, 2, CVT_regG0, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__regG0__Imm1_1
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Reg1_2__regG0__Imm1_1
  { CVT_95_Reg, 2, CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_8
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_0
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Reg1_4__Imm1_3__Tie0__Imm1_1
  { CVT_95_Reg, 4, CVT_95_addImmOperands, 3, CVT_Tied, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Reg1_4__Reg1_2__Imm1_3__Tie0__Imm1_1
  { CVT_95_Reg, 4, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Tied, 0, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_13
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_5
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_1
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_9
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_10
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_6
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_11
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_11
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_12
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_3
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_4
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_2
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_13
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_4
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_2
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_0
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_8
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_9
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_1
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_6
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_15
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_14
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_7
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_10
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_5
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_12
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_3
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_14
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_15
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Reg1_3__Imm1_2__Tie0__imm_95_7
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 2, CVT_Tied, 0, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Reg1_1__regG0__Reg1_1
  { CVT_95_Reg, 1, CVT_regG0, 0, CVT_95_Reg, 1, CVT_Done },
  // Convert__Reg1_1__Reg1_1__regG0
  { CVT_95_Reg, 1, CVT_95_Reg, 1, CVT_regG0, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_1__regG0
  { CVT_95_Reg, 2, CVT_95_Reg, 1, CVT_regG0, 0, CVT_Done },
  // Convert__regG0__regG0__regG0
  { CVT_regG0, 0, CVT_regG0, 0, CVT_regG0, 0, CVT_Done },
  // Convert__imm_95_8
  { CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_1
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__MEMri2_3
  { CVT_95_addMEMriOperands, 3, CVT_Done },
  // Convert__MEMrr2_3
  { CVT_95_addMEMrrOperands, 3, CVT_Done },
  // Convert__MEMri2_3__Reg1_1
  { CVT_95_addMEMriOperands, 3, CVT_95_Reg, 1, CVT_Done },
  // Convert__MEMrr2_3__Reg1_1
  { CVT_95_addMEMrrOperands, 3, CVT_95_Reg, 1, CVT_Done },
  // Convert__MEMrr2_3__Reg1_1__Imm1_5
  { CVT_95_addMEMrrOperands, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_4__MEMri2_2__Tie0
  { CVT_95_Reg, 4, CVT_95_addMEMriOperands, 2, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_4__MEMrr2_2__Tie0
  { CVT_95_Reg, 4, CVT_95_addMEMrrOperands, 2, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_5__MEMrr2_2__Imm1_4__Tie0
  { CVT_95_Reg, 5, CVT_95_addMEMrrOperands, 2, CVT_95_addImmOperands, 4, CVT_Tied, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_8
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_8, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_8
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_8, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_8
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_8, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_8
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_8
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_8
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_8
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_8
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_8, 0, CVT_Done },
  // Convert__Reg1_3__Reg1_5__Imm1_1
  { CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Reg1_3__Imm1_5__Imm1_1
  { CVT_95_Reg, 3, CVT_95_addImmOperands, 5, CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_13
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_13, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_13
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_13, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_13
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_13, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_13
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_13
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_13
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_13
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_13, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_13
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_13, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_5
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_5, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_5
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_5, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_5
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_5, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_5
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_5
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_5
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_5
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_5, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_5
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_5, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_1
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_1, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_1
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_1, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_1
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_1, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_1
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_1
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_1
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_1
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_1, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_1
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_1, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_10
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_10, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_10
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_10, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_10
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_10, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_10
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_10
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_10
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_10
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_10, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_10
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_10, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_11
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_11, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_11
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_11, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_11
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_11, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_11
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_11
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_11
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_11
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_11, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_11
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_11, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_12
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_12, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_12
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_12, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_12
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_12, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_12
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_12
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_12
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_12
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_12, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_12
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_12, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_3
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_3, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_3
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_3, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_3
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_3, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_3
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_3
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_3
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_3
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_3, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_3
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_3, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_2
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_2, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_2
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_2, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_2
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_2, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_2
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_2
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_2
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_2
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_2, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_2
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_2, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_4
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_4, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_4
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_4, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_4
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_4, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_4
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_4
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_4
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_4
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_4, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_4
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_4, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_0
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_0
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_0, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_0
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_0
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_0
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_0
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_0
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_0, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_0
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_0, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_9
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_9, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_9
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_9, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_9
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_9, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_9
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_9
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_9
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_9
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_9, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_9
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_9, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_6
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_6, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_6
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_6, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_6
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_6, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_6
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_6
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_6
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_6
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_6, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_6
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_6, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_14
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_14, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_14
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_14, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_14
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_14, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_14
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_14
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_14
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_14
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_14, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_14
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_14, 0, CVT_Done },
  // Convert__regG0__Reg1_1__regG0
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_regG0, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_15
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_15, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_15
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_15, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_15
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_15, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_15
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_15
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_15
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_15
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_15, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_15
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_15, 0, CVT_Done },
  // Convert__regG0__Reg1_1__imm_95_7
  { CVT_regG0, 0, CVT_95_Reg, 1, CVT_imm_95_7, 0, CVT_Done },
  // Convert__regG0__Imm1_1__imm_95_7
  { CVT_regG0, 0, CVT_95_addImmOperands, 1, CVT_imm_95_7, 0, CVT_Done },
  // Convert__regG0__Reg1_2__imm_95_7
  { CVT_regG0, 0, CVT_95_Reg, 2, CVT_imm_95_7, 0, CVT_Done },
  // Convert__regG0__Imm1_2__imm_95_7
  { CVT_regG0, 0, CVT_95_addImmOperands, 2, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_3__imm_95_7
  { CVT_95_Reg, 1, CVT_95_Reg, 3, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Reg1_1__Imm1_3__imm_95_7
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 3, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Reg1_2__Reg1_4__imm_95_7
  { CVT_95_Reg, 2, CVT_95_Reg, 4, CVT_imm_95_7, 0, CVT_Done },
  // Convert__Reg1_2__Imm1_4__imm_95_7
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_imm_95_7, 0, CVT_Done },
};

void SparcAsmParser::
convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                const OperandVector &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  Inst.setOpcode(Opcode);
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      static_cast<SparcOperand&>(*Operands[*(p + 1)]).addRegOperands(Inst, 1);
      break;
    case CVT_Tied:
      Inst.addOperand(Inst.getOperand(*(p + 1)));
      break;
    case CVT_95_Reg:
      static_cast<SparcOperand&>(*Operands[*(p + 1)]).addRegOperands(Inst, 1);
      break;
    case CVT_95_addImmOperands:
      static_cast<SparcOperand&>(*Operands[*(p + 1)]).addImmOperands(Inst, 1);
      break;
    case CVT_imm_95_8:
      Inst.addOperand(MCOperand::createImm(8));
      break;
    case CVT_imm_95_13:
      Inst.addOperand(MCOperand::createImm(13));
      break;
    case CVT_imm_95_5:
      Inst.addOperand(MCOperand::createImm(5));
      break;
    case CVT_imm_95_1:
      Inst.addOperand(MCOperand::createImm(1));
      break;
    case CVT_imm_95_10:
      Inst.addOperand(MCOperand::createImm(10));
      break;
    case CVT_imm_95_11:
      Inst.addOperand(MCOperand::createImm(11));
      break;
    case CVT_imm_95_12:
      Inst.addOperand(MCOperand::createImm(12));
      break;
    case CVT_imm_95_3:
      Inst.addOperand(MCOperand::createImm(3));
      break;
    case CVT_imm_95_2:
      Inst.addOperand(MCOperand::createImm(2));
      break;
    case CVT_imm_95_4:
      Inst.addOperand(MCOperand::createImm(4));
      break;
    case CVT_imm_95_0:
      Inst.addOperand(MCOperand::createImm(0));
      break;
    case CVT_imm_95_9:
      Inst.addOperand(MCOperand::createImm(9));
      break;
    case CVT_imm_95_6:
      Inst.addOperand(MCOperand::createImm(6));
      break;
    case CVT_imm_95_14:
      Inst.addOperand(MCOperand::createImm(14));
      break;
    case CVT_regG0:
      Inst.addOperand(MCOperand::createReg(SP::G0));
      break;
    case CVT_imm_95_15:
      Inst.addOperand(MCOperand::createImm(15));
      break;
    case CVT_imm_95_7:
      Inst.addOperand(MCOperand::createImm(7));
      break;
    case CVT_regO7:
      Inst.addOperand(MCOperand::createReg(SP::O7));
      break;
    case CVT_95_addMEMriOperands:
      static_cast<SparcOperand&>(*Operands[*(p + 1)]).addMEMriOperands(Inst, 2);
      break;
    case CVT_95_addMEMrrOperands:
      static_cast<SparcOperand&>(*Operands[*(p + 1)]).addMEMrrOperands(Inst, 2);
      break;
    case CVT_regFCC0:
      Inst.addOperand(MCOperand::createReg(SP::FCC0));
      break;
    }
  }
}

void SparcAsmParser::
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
    case CVT_95_Reg:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("r");
      NumMCOperands += 1;
      break;
    case CVT_95_addImmOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 1;
      break;
    case CVT_imm_95_8:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_13:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_5:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_1:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_10:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_11:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_12:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_3:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_2:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_4:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_9:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_6:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_14:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_regG0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_imm_95_15:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_imm_95_7:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("");
      ++NumMCOperands;
      break;
    case CVT_regO7:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      ++NumMCOperands;
      break;
    case CVT_95_addMEMriOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_95_addMEMrrOperands:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
      NumMCOperands += 2;
      break;
    case CVT_regFCC0:
      Operands[*(p + 1)]->setMCOperandNum(NumMCOperands);
      Operands[*(p + 1)]->setConstraint("m");
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
  MCK__PCT_fcc0, // '%fcc0'
  MCK__PCT_fsr, // '%fsr'
  MCK__PCT_g0, // '%g0'
  MCK__PCT_icc, // '%icc'
  MCK__PCT_psr, // '%psr'
  MCK__PCT_tbr, // '%tbr'
  MCK__PCT_wim, // '%wim'
  MCK__PCT_xcc, // '%xcc'
  MCK__43_, // '+'
  MCK_3, // '3'
  MCK_5, // '5'
  MCK__91_, // '['
  MCK__93_, // ']'
  MCK_a, // 'a'
  MCK_add, // 'add'
  MCK_addcc, // 'addcc'
  MCK_addx, // 'addx'
  MCK_addxc, // 'addxc'
  MCK_addxcc, // 'addxcc'
  MCK_addxccc, // 'addxccc'
  MCK_alignaddr, // 'alignaddr'
  MCK_alignaddrl, // 'alignaddrl'
  MCK_and, // 'and'
  MCK_andcc, // 'andcc'
  MCK_andn, // 'andn'
  MCK_andncc, // 'andncc'
  MCK_array16, // 'array16'
  MCK_array32, // 'array32'
  MCK_array8, // 'array8'
  MCK_b, // 'b'
  MCK_ba, // 'ba'
  MCK_bcc, // 'bcc'
  MCK_bclr, // 'bclr'
  MCK_bcs, // 'bcs'
  MCK_be, // 'be'
  MCK_beq, // 'beq'
  MCK_bg, // 'bg'
  MCK_bge, // 'bge'
  MCK_bgeu, // 'bgeu'
  MCK_bgu, // 'bgu'
  MCK_bl, // 'bl'
  MCK_ble, // 'ble'
  MCK_bleu, // 'bleu'
  MCK_blu, // 'blu'
  MCK_bmask, // 'bmask'
  MCK_bn, // 'bn'
  MCK_bne, // 'bne'
  MCK_bneg, // 'bneg'
  MCK_bnz, // 'bnz'
  MCK_bpos, // 'bpos'
  MCK_brgez, // 'brgez'
  MCK_brgz, // 'brgz'
  MCK_brlez, // 'brlez'
  MCK_brlz, // 'brlz'
  MCK_brnz, // 'brnz'
  MCK_brz, // 'brz'
  MCK_bset, // 'bset'
  MCK_bshuffle, // 'bshuffle'
  MCK_btog, // 'btog'
  MCK_btst, // 'btst'
  MCK_bvc, // 'bvc'
  MCK_bvs, // 'bvs'
  MCK_bz, // 'bz'
  MCK_call, // 'call'
  MCK_cas, // 'cas'
  MCK_casx, // 'casx'
  MCK_clr, // 'clr'
  MCK_clrb, // 'clrb'
  MCK_clrh, // 'clrh'
  MCK_cmask16, // 'cmask16'
  MCK_cmask32, // 'cmask32'
  MCK_cmask8, // 'cmask8'
  MCK_cmp, // 'cmp'
  MCK_dec, // 'dec'
  MCK_deccc, // 'deccc'
  MCK_edge16, // 'edge16'
  MCK_edge16l, // 'edge16l'
  MCK_edge16ln, // 'edge16ln'
  MCK_edge16n, // 'edge16n'
  MCK_edge32, // 'edge32'
  MCK_edge32l, // 'edge32l'
  MCK_edge32ln, // 'edge32ln'
  MCK_edge32n, // 'edge32n'
  MCK_edge8, // 'edge8'
  MCK_edge8l, // 'edge8l'
  MCK_edge8ln, // 'edge8ln'
  MCK_edge8n, // 'edge8n'
  MCK_fabsd, // 'fabsd'
  MCK_fabsq, // 'fabsq'
  MCK_fabss, // 'fabss'
  MCK_faddd, // 'faddd'
  MCK_faddq, // 'faddq'
  MCK_fadds, // 'fadds'
  MCK_faligndata, // 'faligndata'
  MCK_fand, // 'fand'
  MCK_fandnot1, // 'fandnot1'
  MCK_fandnot1s, // 'fandnot1s'
  MCK_fandnot2, // 'fandnot2'
  MCK_fandnot2s, // 'fandnot2s'
  MCK_fands, // 'fands'
  MCK_fb, // 'fb'
  MCK_fba, // 'fba'
  MCK_fbe, // 'fbe'
  MCK_fbg, // 'fbg'
  MCK_fbge, // 'fbge'
  MCK_fbl, // 'fbl'
  MCK_fble, // 'fble'
  MCK_fblg, // 'fblg'
  MCK_fbn, // 'fbn'
  MCK_fbne, // 'fbne'
  MCK_fbnz, // 'fbnz'
  MCK_fbo, // 'fbo'
  MCK_fbu, // 'fbu'
  MCK_fbue, // 'fbue'
  MCK_fbug, // 'fbug'
  MCK_fbuge, // 'fbuge'
  MCK_fbul, // 'fbul'
  MCK_fbule, // 'fbule'
  MCK_fbz, // 'fbz'
  MCK_fchksm16, // 'fchksm16'
  MCK_fcmpd, // 'fcmpd'
  MCK_fcmped, // 'fcmped'
  MCK_fcmpeq, // 'fcmpeq'
  MCK_fcmpeq16, // 'fcmpeq16'
  MCK_fcmpeq32, // 'fcmpeq32'
  MCK_fcmpes, // 'fcmpes'
  MCK_fcmpgt16, // 'fcmpgt16'
  MCK_fcmpgt32, // 'fcmpgt32'
  MCK_fcmple16, // 'fcmple16'
  MCK_fcmple32, // 'fcmple32'
  MCK_fcmpne16, // 'fcmpne16'
  MCK_fcmpne32, // 'fcmpne32'
  MCK_fcmpq, // 'fcmpq'
  MCK_fcmps, // 'fcmps'
  MCK_fdivd, // 'fdivd'
  MCK_fdivq, // 'fdivq'
  MCK_fdivs, // 'fdivs'
  MCK_fdmulq, // 'fdmulq'
  MCK_fdtoi, // 'fdtoi'
  MCK_fdtoq, // 'fdtoq'
  MCK_fdtos, // 'fdtos'
  MCK_fdtox, // 'fdtox'
  MCK_fexpand, // 'fexpand'
  MCK_fhaddd, // 'fhaddd'
  MCK_fhadds, // 'fhadds'
  MCK_fhsubd, // 'fhsubd'
  MCK_fhsubs, // 'fhsubs'
  MCK_fitod, // 'fitod'
  MCK_fitoq, // 'fitoq'
  MCK_fitos, // 'fitos'
  MCK_flcmpd, // 'flcmpd'
  MCK_flcmps, // 'flcmps'
  MCK_flush, // 'flush'
  MCK_flushw, // 'flushw'
  MCK_fmean16, // 'fmean16'
  MCK_fmovd, // 'fmovd'
  MCK_fmovda, // 'fmovda'
  MCK_fmovdcc, // 'fmovdcc'
  MCK_fmovdcs, // 'fmovdcs'
  MCK_fmovde, // 'fmovde'
  MCK_fmovdeq, // 'fmovdeq'
  MCK_fmovdg, // 'fmovdg'
  MCK_fmovdge, // 'fmovdge'
  MCK_fmovdgeu, // 'fmovdgeu'
  MCK_fmovdgu, // 'fmovdgu'
  MCK_fmovdl, // 'fmovdl'
  MCK_fmovdle, // 'fmovdle'
  MCK_fmovdleu, // 'fmovdleu'
  MCK_fmovdlg, // 'fmovdlg'
  MCK_fmovdlu, // 'fmovdlu'
  MCK_fmovdn, // 'fmovdn'
  MCK_fmovdne, // 'fmovdne'
  MCK_fmovdneg, // 'fmovdneg'
  MCK_fmovdnz, // 'fmovdnz'
  MCK_fmovdo, // 'fmovdo'
  MCK_fmovdpos, // 'fmovdpos'
  MCK_fmovdu, // 'fmovdu'
  MCK_fmovdue, // 'fmovdue'
  MCK_fmovdug, // 'fmovdug'
  MCK_fmovduge, // 'fmovduge'
  MCK_fmovdul, // 'fmovdul'
  MCK_fmovdule, // 'fmovdule'
  MCK_fmovdvc, // 'fmovdvc'
  MCK_fmovdvs, // 'fmovdvs'
  MCK_fmovdz, // 'fmovdz'
  MCK_fmovq, // 'fmovq'
  MCK_fmovqa, // 'fmovqa'
  MCK_fmovqcc, // 'fmovqcc'
  MCK_fmovqcs, // 'fmovqcs'
  MCK_fmovqe, // 'fmovqe'
  MCK_fmovqeq, // 'fmovqeq'
  MCK_fmovqg, // 'fmovqg'
  MCK_fmovqge, // 'fmovqge'
  MCK_fmovqgeu, // 'fmovqgeu'
  MCK_fmovqgu, // 'fmovqgu'
  MCK_fmovql, // 'fmovql'
  MCK_fmovqle, // 'fmovqle'
  MCK_fmovqleu, // 'fmovqleu'
  MCK_fmovqlg, // 'fmovqlg'
  MCK_fmovqlu, // 'fmovqlu'
  MCK_fmovqn, // 'fmovqn'
  MCK_fmovqne, // 'fmovqne'
  MCK_fmovqneg, // 'fmovqneg'
  MCK_fmovqnz, // 'fmovqnz'
  MCK_fmovqo, // 'fmovqo'
  MCK_fmovqpos, // 'fmovqpos'
  MCK_fmovqu, // 'fmovqu'
  MCK_fmovque, // 'fmovque'
  MCK_fmovqug, // 'fmovqug'
  MCK_fmovquge, // 'fmovquge'
  MCK_fmovqul, // 'fmovqul'
  MCK_fmovqule, // 'fmovqule'
  MCK_fmovqvc, // 'fmovqvc'
  MCK_fmovqvs, // 'fmovqvs'
  MCK_fmovqz, // 'fmovqz'
  MCK_fmovrdgez, // 'fmovrdgez'
  MCK_fmovrdgz, // 'fmovrdgz'
  MCK_fmovrdlez, // 'fmovrdlez'
  MCK_fmovrdlz, // 'fmovrdlz'
  MCK_fmovrdnz, // 'fmovrdnz'
  MCK_fmovrdz, // 'fmovrdz'
  MCK_fmovrqgez, // 'fmovrqgez'
  MCK_fmovrqgz, // 'fmovrqgz'
  MCK_fmovrqlez, // 'fmovrqlez'
  MCK_fmovrqlz, // 'fmovrqlz'
  MCK_fmovrqnz, // 'fmovrqnz'
  MCK_fmovrqz, // 'fmovrqz'
  MCK_fmovrsgez, // 'fmovrsgez'
  MCK_fmovrsgz, // 'fmovrsgz'
  MCK_fmovrslez, // 'fmovrslez'
  MCK_fmovrslz, // 'fmovrslz'
  MCK_fmovrsnz, // 'fmovrsnz'
  MCK_fmovrsz, // 'fmovrsz'
  MCK_fmovs, // 'fmovs'
  MCK_fmovsa, // 'fmovsa'
  MCK_fmovscc, // 'fmovscc'
  MCK_fmovscs, // 'fmovscs'
  MCK_fmovse, // 'fmovse'
  MCK_fmovseq, // 'fmovseq'
  MCK_fmovsg, // 'fmovsg'
  MCK_fmovsge, // 'fmovsge'
  MCK_fmovsgeu, // 'fmovsgeu'
  MCK_fmovsgu, // 'fmovsgu'
  MCK_fmovsl, // 'fmovsl'
  MCK_fmovsle, // 'fmovsle'
  MCK_fmovsleu, // 'fmovsleu'
  MCK_fmovslg, // 'fmovslg'
  MCK_fmovslu, // 'fmovslu'
  MCK_fmovsn, // 'fmovsn'
  MCK_fmovsne, // 'fmovsne'
  MCK_fmovsneg, // 'fmovsneg'
  MCK_fmovsnz, // 'fmovsnz'
  MCK_fmovso, // 'fmovso'
  MCK_fmovspos, // 'fmovspos'
  MCK_fmovsu, // 'fmovsu'
  MCK_fmovsue, // 'fmovsue'
  MCK_fmovsug, // 'fmovsug'
  MCK_fmovsuge, // 'fmovsuge'
  MCK_fmovsul, // 'fmovsul'
  MCK_fmovsule, // 'fmovsule'
  MCK_fmovsvc, // 'fmovsvc'
  MCK_fmovsvs, // 'fmovsvs'
  MCK_fmovsz, // 'fmovsz'
  MCK_fmul8sux16, // 'fmul8sux16'
  MCK_fmul8ulx16, // 'fmul8ulx16'
  MCK_fmul8x16, // 'fmul8x16'
  MCK_fmul8x16al, // 'fmul8x16al'
  MCK_fmul8x16au, // 'fmul8x16au'
  MCK_fmuld, // 'fmuld'
  MCK_fmuld8sux16, // 'fmuld8sux16'
  MCK_fmuld8ulx16, // 'fmuld8ulx16'
  MCK_fmulq, // 'fmulq'
  MCK_fmuls, // 'fmuls'
  MCK_fnaddd, // 'fnaddd'
  MCK_fnadds, // 'fnadds'
  MCK_fnand, // 'fnand'
  MCK_fnands, // 'fnands'
  MCK_fnegd, // 'fnegd'
  MCK_fnegq, // 'fnegq'
  MCK_fnegs, // 'fnegs'
  MCK_fnhaddd, // 'fnhaddd'
  MCK_fnhadds, // 'fnhadds'
  MCK_fnor, // 'fnor'
  MCK_fnors, // 'fnors'
  MCK_fnot1, // 'fnot1'
  MCK_fnot1s, // 'fnot1s'
  MCK_fnot2, // 'fnot2'
  MCK_fnot2s, // 'fnot2s'
  MCK_fone, // 'fone'
  MCK_fones, // 'fones'
  MCK_for, // 'for'
  MCK_fornot1, // 'fornot1'
  MCK_fornot1s, // 'fornot1s'
  MCK_fornot2, // 'fornot2'
  MCK_fornot2s, // 'fornot2s'
  MCK_fors, // 'fors'
  MCK_fpack16, // 'fpack16'
  MCK_fpack32, // 'fpack32'
  MCK_fpackfix, // 'fpackfix'
  MCK_fpadd16, // 'fpadd16'
  MCK_fpadd16s, // 'fpadd16s'
  MCK_fpadd32, // 'fpadd32'
  MCK_fpadd32s, // 'fpadd32s'
  MCK_fpadd64, // 'fpadd64'
  MCK_fpmerge, // 'fpmerge'
  MCK_fpsub16, // 'fpsub16'
  MCK_fpsub16S, // 'fpsub16S'
  MCK_fpsub32, // 'fpsub32'
  MCK_fpsub32S, // 'fpsub32S'
  MCK_fqtod, // 'fqtod'
  MCK_fqtoi, // 'fqtoi'
  MCK_fqtos, // 'fqtos'
  MCK_fqtox, // 'fqtox'
  MCK_fslas16, // 'fslas16'
  MCK_fslas32, // 'fslas32'
  MCK_fsll16, // 'fsll16'
  MCK_fsll32, // 'fsll32'
  MCK_fsmuld, // 'fsmuld'
  MCK_fsqrtd, // 'fsqrtd'
  MCK_fsqrtq, // 'fsqrtq'
  MCK_fsqrts, // 'fsqrts'
  MCK_fsra16, // 'fsra16'
  MCK_fsra32, // 'fsra32'
  MCK_fsrc1, // 'fsrc1'
  MCK_fsrc1s, // 'fsrc1s'
  MCK_fsrc2, // 'fsrc2'
  MCK_fsrc2s, // 'fsrc2s'
  MCK_fsrl16, // 'fsrl16'
  MCK_fsrl32, // 'fsrl32'
  MCK_fstod, // 'fstod'
  MCK_fstoi, // 'fstoi'
  MCK_fstoq, // 'fstoq'
  MCK_fstox, // 'fstox'
  MCK_fsubd, // 'fsubd'
  MCK_fsubq, // 'fsubq'
  MCK_fsubs, // 'fsubs'
  MCK_fxnor, // 'fxnor'
  MCK_fxnors, // 'fxnors'
  MCK_fxor, // 'fxor'
  MCK_fxors, // 'fxors'
  MCK_fxtod, // 'fxtod'
  MCK_fxtoq, // 'fxtoq'
  MCK_fxtos, // 'fxtos'
  MCK_fzero, // 'fzero'
  MCK_fzeros, // 'fzeros'
  MCK_inc, // 'inc'
  MCK_inccc, // 'inccc'
  MCK_jmp, // 'jmp'
  MCK_jmpl, // 'jmpl'
  MCK_ld, // 'ld'
  MCK_lda, // 'lda'
  MCK_ldd, // 'ldd'
  MCK_ldda, // 'ldda'
  MCK_ldq, // 'ldq'
  MCK_ldqa, // 'ldqa'
  MCK_ldsb, // 'ldsb'
  MCK_ldsba, // 'ldsba'
  MCK_ldsh, // 'ldsh'
  MCK_ldsha, // 'ldsha'
  MCK_ldstub, // 'ldstub'
  MCK_ldstuba, // 'ldstuba'
  MCK_ldsw, // 'ldsw'
  MCK_ldub, // 'ldub'
  MCK_lduba, // 'lduba'
  MCK_lduh, // 'lduh'
  MCK_lduha, // 'lduha'
  MCK_ldx, // 'ldx'
  MCK_lzcnt, // 'lzcnt'
  MCK_membar, // 'membar'
  MCK_mov, // 'mov'
  MCK_mova, // 'mova'
  MCK_movcc, // 'movcc'
  MCK_movcs, // 'movcs'
  MCK_movdtox, // 'movdtox'
  MCK_move, // 'move'
  MCK_moveq, // 'moveq'
  MCK_movg, // 'movg'
  MCK_movge, // 'movge'
  MCK_movgeu, // 'movgeu'
  MCK_movgu, // 'movgu'
  MCK_movl, // 'movl'
  MCK_movle, // 'movle'
  MCK_movleu, // 'movleu'
  MCK_movlg, // 'movlg'
  MCK_movlu, // 'movlu'
  MCK_movn, // 'movn'
  MCK_movne, // 'movne'
  MCK_movneg, // 'movneg'
  MCK_movnz, // 'movnz'
  MCK_movo, // 'movo'
  MCK_movpos, // 'movpos'
  MCK_movrgez, // 'movrgez'
  MCK_movrgz, // 'movrgz'
  MCK_movrlez, // 'movrlez'
  MCK_movrlz, // 'movrlz'
  MCK_movrnz, // 'movrnz'
  MCK_movrz, // 'movrz'
  MCK_movstosw, // 'movstosw'
  MCK_movstouw, // 'movstouw'
  MCK_movu, // 'movu'
  MCK_movue, // 'movue'
  MCK_movug, // 'movug'
  MCK_movuge, // 'movuge'
  MCK_movul, // 'movul'
  MCK_movule, // 'movule'
  MCK_movvc, // 'movvc'
  MCK_movvs, // 'movvs'
  MCK_movz, // 'movz'
  MCK_mulscc, // 'mulscc'
  MCK_mulx, // 'mulx'
  MCK_neg, // 'neg'
  MCK_nop, // 'nop'
  MCK_not, // 'not'
  MCK_or, // 'or'
  MCK_orcc, // 'orcc'
  MCK_orn, // 'orn'
  MCK_orncc, // 'orncc'
  MCK_pdist, // 'pdist'
  MCK_pdistn, // 'pdistn'
  MCK_pn, // 'pn'
  MCK_popc, // 'popc'
  MCK_pt, // 'pt'
  MCK_rd, // 'rd'
  MCK_rdpr, // 'rdpr'
  MCK_restore, // 'restore'
  MCK_ret, // 'ret'
  MCK_retl, // 'retl'
  MCK_rett, // 'rett'
  MCK_save, // 'save'
  MCK_sdiv, // 'sdiv'
  MCK_sdivcc, // 'sdivcc'
  MCK_sdivx, // 'sdivx'
  MCK_set, // 'set'
  MCK_sethi, // 'sethi'
  MCK_shutdown, // 'shutdown'
  MCK_siam, // 'siam'
  MCK_signx, // 'signx'
  MCK_sll, // 'sll'
  MCK_sllx, // 'sllx'
  MCK_smul, // 'smul'
  MCK_smulcc, // 'smulcc'
  MCK_sra, // 'sra'
  MCK_srax, // 'srax'
  MCK_srl, // 'srl'
  MCK_srlx, // 'srlx'
  MCK_st, // 'st'
  MCK_sta, // 'sta'
  MCK_stb, // 'stb'
  MCK_stba, // 'stba'
  MCK_stbar, // 'stbar'
  MCK_std, // 'std'
  MCK_stda, // 'stda'
  MCK_sth, // 'sth'
  MCK_stha, // 'stha'
  MCK_stq, // 'stq'
  MCK_stqa, // 'stqa'
  MCK_stx, // 'stx'
  MCK_sub, // 'sub'
  MCK_subcc, // 'subcc'
  MCK_subx, // 'subx'
  MCK_subxcc, // 'subxcc'
  MCK_swap, // 'swap'
  MCK_swapa, // 'swapa'
  MCK_t, // 't'
  MCK_ta, // 'ta'
  MCK_taddcc, // 'taddcc'
  MCK_taddcctv, // 'taddcctv'
  MCK_tcc, // 'tcc'
  MCK_tcs, // 'tcs'
  MCK_te, // 'te'
  MCK_teq, // 'teq'
  MCK_tg, // 'tg'
  MCK_tge, // 'tge'
  MCK_tgeu, // 'tgeu'
  MCK_tgu, // 'tgu'
  MCK_tl, // 'tl'
  MCK_tle, // 'tle'
  MCK_tleu, // 'tleu'
  MCK_tlu, // 'tlu'
  MCK_tn, // 'tn'
  MCK_tne, // 'tne'
  MCK_tneg, // 'tneg'
  MCK_tnz, // 'tnz'
  MCK_tpos, // 'tpos'
  MCK_tst, // 'tst'
  MCK_tsubcc, // 'tsubcc'
  MCK_tsubcctv, // 'tsubcctv'
  MCK_tvc, // 'tvc'
  MCK_tvs, // 'tvs'
  MCK_tz, // 'tz'
  MCK_udiv, // 'udiv'
  MCK_udivcc, // 'udivcc'
  MCK_udivx, // 'udivx'
  MCK_umul, // 'umul'
  MCK_umulcc, // 'umulcc'
  MCK_umulxhi, // 'umulxhi'
  MCK_unimp, // 'unimp'
  MCK_wr, // 'wr'
  MCK_wrpr, // 'wrpr'
  MCK_xmulx, // 'xmulx'
  MCK_xmulxhi, // 'xmulxhi'
  MCK_xnor, // 'xnor'
  MCK_xnorcc, // 'xnorcc'
  MCK_xor, // 'xor'
  MCK_xorcc, // 'xorcc'
  MCK_FCCRegs, // register class 'FCCRegs'
  MCK_ASRRegs, // register class 'ASRRegs'
  MCK_PRRegs, // register class 'PRRegs'
  MCK_IntRegs, // register class 'IntRegs,I64Regs'
  MCK_FPRegs, // register class 'FPRegs'
  MCK_Reg5, // derived register class
  MCK_DFPRegs, // register class 'DFPRegs'
  MCK_Reg7, // derived register class
  MCK_QFPRegs, // register class 'QFPRegs'
  MCK_IntPair, // register class 'IntPair'
  MCK_Imm, // user defined class 'ImmAsmOperand'
  MCK_MEMri, // user defined class 'SparcMEMriAsmOperand'
  MCK_MEMrr, // user defined class 'SparcMEMrrAsmOperand'
  NumMatchClassKinds
};

}

static MatchClassKind matchTokenString(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 1:	 // 8 strings to match.
    switch (Name[0]) {
    default: break;
    case '+':	 // 1 string to match.
      return MCK__43_;	 // "+"
    case '3':	 // 1 string to match.
      return MCK_3;	 // "3"
    case '5':	 // 1 string to match.
      return MCK_5;	 // "5"
    case '[':	 // 1 string to match.
      return MCK__91_;	 // "["
    case ']':	 // 1 string to match.
      return MCK__93_;	 // "]"
    case 'a':	 // 1 string to match.
      return MCK_a;	 // "a"
    case 'b':	 // 1 string to match.
      return MCK_b;	 // "b"
    case 't':	 // 1 string to match.
      return MCK_t;	 // "t"
    }
    break;
  case 2:	 // 20 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 6 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        return MCK_ba;	 // "ba"
      case 'e':	 // 1 string to match.
        return MCK_be;	 // "be"
      case 'g':	 // 1 string to match.
        return MCK_bg;	 // "bg"
      case 'l':	 // 1 string to match.
        return MCK_bl;	 // "bl"
      case 'n':	 // 1 string to match.
        return MCK_bn;	 // "bn"
      case 'z':	 // 1 string to match.
        return MCK_bz;	 // "bz"
      }
      break;
    case 'f':	 // 1 string to match.
      if (Name[1] != 'b')
        break;
      return MCK_fb;	 // "fb"
    case 'l':	 // 1 string to match.
      if (Name[1] != 'd')
        break;
      return MCK_ld;	 // "ld"
    case 'o':	 // 1 string to match.
      if (Name[1] != 'r')
        break;
      return MCK_or;	 // "or"
    case 'p':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'n':	 // 1 string to match.
        return MCK_pn;	 // "pn"
      case 't':	 // 1 string to match.
        return MCK_pt;	 // "pt"
      }
      break;
    case 'r':	 // 1 string to match.
      if (Name[1] != 'd')
        break;
      return MCK_rd;	 // "rd"
    case 's':	 // 1 string to match.
      if (Name[1] != 't')
        break;
      return MCK_st;	 // "st"
    case 't':	 // 6 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        return MCK_ta;	 // "ta"
      case 'e':	 // 1 string to match.
        return MCK_te;	 // "te"
      case 'g':	 // 1 string to match.
        return MCK_tg;	 // "tg"
      case 'l':	 // 1 string to match.
        return MCK_tl;	 // "tl"
      case 'n':	 // 1 string to match.
        return MCK_tn;	 // "tn"
      case 'z':	 // 1 string to match.
        return MCK_tz;	 // "tz"
      }
      break;
    case 'w':	 // 1 string to match.
      if (Name[1] != 'r')
        break;
      return MCK_wr;	 // "wr"
    }
    break;
  case 3:	 // 64 strings to match.
    switch (Name[0]) {
    default: break;
    case '%':	 // 1 string to match.
      if (memcmp(Name.data()+1, "g0", 2))
        break;
      return MCK__PCT_g0;	 // "%g0"
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
    case 'b':	 // 12 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          return MCK_bcc;	 // "bcc"
        case 's':	 // 1 string to match.
          return MCK_bcs;	 // "bcs"
        }
        break;
      case 'e':	 // 1 string to match.
        if (Name[2] != 'q')
          break;
        return MCK_beq;	 // "beq"
      case 'g':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_bge;	 // "bge"
        case 'u':	 // 1 string to match.
          return MCK_bgu;	 // "bgu"
        }
        break;
      case 'l':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_ble;	 // "ble"
        case 'u':	 // 1 string to match.
          return MCK_blu;	 // "blu"
        }
        break;
      case 'n':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_bne;	 // "bne"
        case 'z':	 // 1 string to match.
          return MCK_bnz;	 // "bnz"
        }
        break;
      case 'r':	 // 1 string to match.
        if (Name[2] != 'z')
          break;
        return MCK_brz;	 // "brz"
      case 'v':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          return MCK_bvc;	 // "bvc"
        case 's':	 // 1 string to match.
          return MCK_bvs;	 // "bvs"
        }
        break;
      }
      break;
    case 'c':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (Name[2] != 's')
          break;
        return MCK_cas;	 // "cas"
      case 'l':	 // 1 string to match.
        if (Name[2] != 'r')
          break;
        return MCK_clr;	 // "clr"
      case 'm':	 // 1 string to match.
        if (Name[2] != 'p')
          break;
        return MCK_cmp;	 // "cmp"
      }
      break;
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ec", 2))
        break;
      return MCK_dec;	 // "dec"
    case 'f':	 // 9 strings to match.
      switch (Name[1]) {
      default: break;
      case 'b':	 // 8 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_fba;	 // "fba"
        case 'e':	 // 1 string to match.
          return MCK_fbe;	 // "fbe"
        case 'g':	 // 1 string to match.
          return MCK_fbg;	 // "fbg"
        case 'l':	 // 1 string to match.
          return MCK_fbl;	 // "fbl"
        case 'n':	 // 1 string to match.
          return MCK_fbn;	 // "fbn"
        case 'o':	 // 1 string to match.
          return MCK_fbo;	 // "fbo"
        case 'u':	 // 1 string to match.
          return MCK_fbu;	 // "fbu"
        case 'z':	 // 1 string to match.
          return MCK_fbz;	 // "fbz"
        }
        break;
      case 'o':	 // 1 string to match.
        if (Name[2] != 'r')
          break;
        return MCK_for;	 // "for"
      }
      break;
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+1, "nc", 2))
        break;
      return MCK_inc;	 // "inc"
    case 'j':	 // 1 string to match.
      if (memcmp(Name.data()+1, "mp", 2))
        break;
      return MCK_jmp;	 // "jmp"
    case 'l':	 // 4 strings to match.
      if (Name[1] != 'd')
        break;
      switch (Name[2]) {
      default: break;
      case 'a':	 // 1 string to match.
        return MCK_lda;	 // "lda"
      case 'd':	 // 1 string to match.
        return MCK_ldd;	 // "ldd"
      case 'q':	 // 1 string to match.
        return MCK_ldq;	 // "ldq"
      case 'x':	 // 1 string to match.
        return MCK_ldx;	 // "ldx"
      }
      break;
    case 'm':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ov", 2))
        break;
      return MCK_mov;	 // "mov"
    case 'n':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (Name[2] != 'g')
          break;
        return MCK_neg;	 // "neg"
      case 'o':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'p':	 // 1 string to match.
          return MCK_nop;	 // "nop"
        case 't':	 // 1 string to match.
          return MCK_not;	 // "not"
        }
        break;
      }
      break;
    case 'o':	 // 1 string to match.
      if (memcmp(Name.data()+1, "rn", 2))
        break;
      return MCK_orn;	 // "orn"
    case 'r':	 // 1 string to match.
      if (memcmp(Name.data()+1, "et", 2))
        break;
      return MCK_ret;	 // "ret"
    case 's':	 // 11 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (Name[2] != 't')
          break;
        return MCK_set;	 // "set"
      case 'l':	 // 1 string to match.
        if (Name[2] != 'l')
          break;
        return MCK_sll;	 // "sll"
      case 'r':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_sra;	 // "sra"
        case 'l':	 // 1 string to match.
          return MCK_srl;	 // "srl"
        }
        break;
      case 't':	 // 6 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_sta;	 // "sta"
        case 'b':	 // 1 string to match.
          return MCK_stb;	 // "stb"
        case 'd':	 // 1 string to match.
          return MCK_std;	 // "std"
        case 'h':	 // 1 string to match.
          return MCK_sth;	 // "sth"
        case 'q':	 // 1 string to match.
          return MCK_stq;	 // "stq"
        case 'x':	 // 1 string to match.
          return MCK_stx;	 // "stx"
        }
        break;
      case 'u':	 // 1 string to match.
        if (Name[2] != 'b')
          break;
        return MCK_sub;	 // "sub"
      }
      break;
    case 't':	 // 12 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          return MCK_tcc;	 // "tcc"
        case 's':	 // 1 string to match.
          return MCK_tcs;	 // "tcs"
        }
        break;
      case 'e':	 // 1 string to match.
        if (Name[2] != 'q')
          break;
        return MCK_teq;	 // "teq"
      case 'g':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_tge;	 // "tge"
        case 'u':	 // 1 string to match.
          return MCK_tgu;	 // "tgu"
        }
        break;
      case 'l':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_tle;	 // "tle"
        case 'u':	 // 1 string to match.
          return MCK_tlu;	 // "tlu"
        }
        break;
      case 'n':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_tne;	 // "tne"
        case 'z':	 // 1 string to match.
          return MCK_tnz;	 // "tnz"
        }
        break;
      case 's':	 // 1 string to match.
        if (Name[2] != 't')
          break;
        return MCK_tst;	 // "tst"
      case 'v':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 1 string to match.
          return MCK_tvc;	 // "tvc"
        case 's':	 // 1 string to match.
          return MCK_tvs;	 // "tvs"
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
  case 4:	 // 79 strings to match.
    switch (Name[0]) {
    default: break;
    case '%':	 // 6 strings to match.
      switch (Name[1]) {
      default: break;
      case 'f':	 // 1 string to match.
        if (memcmp(Name.data()+2, "sr", 2))
          break;
        return MCK__PCT_fsr;	 // "%fsr"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+2, "cc", 2))
          break;
        return MCK__PCT_icc;	 // "%icc"
      case 'p':	 // 1 string to match.
        if (memcmp(Name.data()+2, "sr", 2))
          break;
        return MCK__PCT_psr;	 // "%psr"
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+2, "br", 2))
          break;
        return MCK__PCT_tbr;	 // "%tbr"
      case 'w':	 // 1 string to match.
        if (memcmp(Name.data()+2, "im", 2))
          break;
        return MCK__PCT_wim;	 // "%wim"
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+2, "cc", 2))
          break;
        return MCK__PCT_xcc;	 // "%xcc"
      }
      break;
    case 'a':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "dx", 2))
          break;
        return MCK_addx;	 // "addx"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "dn", 2))
          break;
        return MCK_andn;	 // "andn"
      }
      break;
    case 'b':	 // 11 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(Name.data()+2, "lr", 2))
          break;
        return MCK_bclr;	 // "bclr"
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eu", 2))
          break;
        return MCK_bgeu;	 // "bgeu"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eu", 2))
          break;
        return MCK_bleu;	 // "bleu"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eg", 2))
          break;
        return MCK_bneg;	 // "bneg"
      case 'p':	 // 1 string to match.
        if (memcmp(Name.data()+2, "os", 2))
          break;
        return MCK_bpos;	 // "bpos"
      case 'r':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'g':	 // 1 string to match.
          if (Name[3] != 'z')
            break;
          return MCK_brgz;	 // "brgz"
        case 'l':	 // 1 string to match.
          if (Name[3] != 'z')
            break;
          return MCK_brlz;	 // "brlz"
        case 'n':	 // 1 string to match.
          if (Name[3] != 'z')
            break;
          return MCK_brnz;	 // "brnz"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "et", 2))
          break;
        return MCK_bset;	 // "bset"
      case 't':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'o':	 // 1 string to match.
          if (Name[3] != 'g')
            break;
          return MCK_btog;	 // "btog"
        case 's':	 // 1 string to match.
          if (Name[3] != 't')
            break;
          return MCK_btst;	 // "btst"
        }
        break;
      }
      break;
    case 'c':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'l':	 // 1 string to match.
          if (Name[3] != 'l')
            break;
          return MCK_call;	 // "call"
        case 's':	 // 1 string to match.
          if (Name[3] != 'x')
            break;
          return MCK_casx;	 // "casx"
        }
        break;
      case 'l':	 // 2 strings to match.
        if (Name[2] != 'r')
          break;
        switch (Name[3]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_clrb;	 // "clrb"
        case 'h':	 // 1 string to match.
          return MCK_clrh;	 // "clrh"
        }
        break;
      }
      break;
    case 'f':	 // 13 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "nd", 2))
          break;
        return MCK_fand;	 // "fand"
      case 'b':	 // 8 strings to match.
        switch (Name[2]) {
        default: break;
        case 'g':	 // 1 string to match.
          if (Name[3] != 'e')
            break;
          return MCK_fbge;	 // "fbge"
        case 'l':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_fble;	 // "fble"
          case 'g':	 // 1 string to match.
            return MCK_fblg;	 // "fblg"
          }
          break;
        case 'n':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_fbne;	 // "fbne"
          case 'z':	 // 1 string to match.
            return MCK_fbnz;	 // "fbnz"
          }
          break;
        case 'u':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'e':	 // 1 string to match.
            return MCK_fbue;	 // "fbue"
          case 'g':	 // 1 string to match.
            return MCK_fbug;	 // "fbug"
          case 'l':	 // 1 string to match.
            return MCK_fbul;	 // "fbul"
          }
          break;
        }
        break;
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "or", 2))
          break;
        return MCK_fnor;	 // "fnor"
      case 'o':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'n':	 // 1 string to match.
          if (Name[3] != 'e')
            break;
          return MCK_fone;	 // "fone"
        case 'r':	 // 1 string to match.
          if (Name[3] != 's')
            break;
          return MCK_fors;	 // "fors"
        }
        break;
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+2, "or", 2))
          break;
        return MCK_fxor;	 // "fxor"
      }
      break;
    case 'j':	 // 1 string to match.
      if (memcmp(Name.data()+1, "mpl", 3))
        break;
      return MCK_jmpl;	 // "jmpl"
    case 'l':	 // 7 strings to match.
      if (Name[1] != 'd')
        break;
      switch (Name[2]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (Name[3] != 'a')
          break;
        return MCK_ldda;	 // "ldda"
      case 'q':	 // 1 string to match.
        if (Name[3] != 'a')
          break;
        return MCK_ldqa;	 // "ldqa"
      case 's':	 // 3 strings to match.
        switch (Name[3]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_ldsb;	 // "ldsb"
        case 'h':	 // 1 string to match.
          return MCK_ldsh;	 // "ldsh"
        case 'w':	 // 1 string to match.
          return MCK_ldsw;	 // "ldsw"
        }
        break;
      case 'u':	 // 2 strings to match.
        switch (Name[3]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_ldub;	 // "ldub"
        case 'h':	 // 1 string to match.
          return MCK_lduh;	 // "lduh"
        }
        break;
      }
      break;
    case 'm':	 // 9 strings to match.
      switch (Name[1]) {
      default: break;
      case 'o':	 // 8 strings to match.
        if (Name[2] != 'v')
          break;
        switch (Name[3]) {
        default: break;
        case 'a':	 // 1 string to match.
          return MCK_mova;	 // "mova"
        case 'e':	 // 1 string to match.
          return MCK_move;	 // "move"
        case 'g':	 // 1 string to match.
          return MCK_movg;	 // "movg"
        case 'l':	 // 1 string to match.
          return MCK_movl;	 // "movl"
        case 'n':	 // 1 string to match.
          return MCK_movn;	 // "movn"
        case 'o':	 // 1 string to match.
          return MCK_movo;	 // "movo"
        case 'u':	 // 1 string to match.
          return MCK_movu;	 // "movu"
        case 'z':	 // 1 string to match.
          return MCK_movz;	 // "movz"
        }
        break;
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "lx", 2))
          break;
        return MCK_mulx;	 // "mulx"
      }
      break;
    case 'o':	 // 1 string to match.
      if (memcmp(Name.data()+1, "rcc", 3))
        break;
      return MCK_orcc;	 // "orcc"
    case 'p':	 // 1 string to match.
      if (memcmp(Name.data()+1, "opc", 3))
        break;
      return MCK_popc;	 // "popc"
    case 'r':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "pr", 2))
          break;
        return MCK_rdpr;	 // "rdpr"
      case 'e':	 // 2 strings to match.
        if (Name[2] != 't')
          break;
        switch (Name[3]) {
        default: break;
        case 'l':	 // 1 string to match.
          return MCK_retl;	 // "retl"
        case 't':	 // 1 string to match.
          return MCK_rett;	 // "rett"
        }
        break;
      }
      break;
    case 's':	 // 13 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ve", 2))
          break;
        return MCK_save;	 // "save"
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "iv", 2))
          break;
        return MCK_sdiv;	 // "sdiv"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+2, "am", 2))
          break;
        return MCK_siam;	 // "siam"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "lx", 2))
          break;
        return MCK_sllx;	 // "sllx"
      case 'm':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ul", 2))
          break;
        return MCK_smul;	 // "smul"
      case 'r':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (Name[3] != 'x')
            break;
          return MCK_srax;	 // "srax"
        case 'l':	 // 1 string to match.
          if (Name[3] != 'x')
            break;
          return MCK_srlx;	 // "srlx"
        }
        break;
      case 't':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 1 string to match.
          if (Name[3] != 'a')
            break;
          return MCK_stba;	 // "stba"
        case 'd':	 // 1 string to match.
          if (Name[3] != 'a')
            break;
          return MCK_stda;	 // "stda"
        case 'h':	 // 1 string to match.
          if (Name[3] != 'a')
            break;
          return MCK_stha;	 // "stha"
        case 'q':	 // 1 string to match.
          if (Name[3] != 'a')
            break;
          return MCK_stqa;	 // "stqa"
        }
        break;
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bx", 2))
          break;
        return MCK_subx;	 // "subx"
      case 'w':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ap", 2))
          break;
        return MCK_swap;	 // "swap"
      }
      break;
    case 't':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'g':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eu", 2))
          break;
        return MCK_tgeu;	 // "tgeu"
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eu", 2))
          break;
        return MCK_tleu;	 // "tleu"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eg", 2))
          break;
        return MCK_tneg;	 // "tneg"
      case 'p':	 // 1 string to match.
        if (memcmp(Name.data()+2, "os", 2))
          break;
        return MCK_tpos;	 // "tpos"
      }
      break;
    case 'u':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "iv", 2))
          break;
        return MCK_udiv;	 // "udiv"
      case 'm':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ul", 2))
          break;
        return MCK_umul;	 // "umul"
      }
      break;
    case 'w':	 // 1 string to match.
      if (memcmp(Name.data()+1, "rpr", 3))
        break;
      return MCK_wrpr;	 // "wrpr"
    case 'x':	 // 1 string to match.
      if (memcmp(Name.data()+1, "nor", 3))
        break;
      return MCK_xnor;	 // "xnor"
    }
    break;
  case 5:	 // 99 strings to match.
    switch (Name[0]) {
    default: break;
    case '%':	 // 1 string to match.
      if (memcmp(Name.data()+1, "fcc0", 4))
        break;
      return MCK__PCT_fcc0;	 // "%fcc0"
    case 'a':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 2 strings to match.
        if (Name[2] != 'd')
          break;
        switch (Name[3]) {
        default: break;
        case 'c':	 // 1 string to match.
          if (Name[4] != 'c')
            break;
          return MCK_addcc;	 // "addcc"
        case 'x':	 // 1 string to match.
          if (Name[4] != 'c')
            break;
          return MCK_addxc;	 // "addxc"
        }
        break;
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "dcc", 3))
          break;
        return MCK_andcc;	 // "andcc"
      }
      break;
    case 'b':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'm':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ask", 3))
          break;
        return MCK_bmask;	 // "bmask"
      case 'r':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'g':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ez", 2))
            break;
          return MCK_brgez;	 // "brgez"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ez", 2))
            break;
          return MCK_brlez;	 // "brlez"
        }
        break;
      }
      break;
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "eccc", 4))
        break;
      return MCK_deccc;	 // "deccc"
    case 'e':	 // 1 string to match.
      if (memcmp(Name.data()+1, "dge8", 4))
        break;
      return MCK_edge8;	 // "edge8"
    case 'f':	 // 56 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 7 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 3 strings to match.
          if (Name[3] != 's')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fabsd;	 // "fabsd"
          case 'q':	 // 1 string to match.
            return MCK_fabsq;	 // "fabsq"
          case 's':	 // 1 string to match.
            return MCK_fabss;	 // "fabss"
          }
          break;
        case 'd':	 // 3 strings to match.
          if (Name[3] != 'd')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_faddd;	 // "faddd"
          case 'q':	 // 1 string to match.
            return MCK_faddq;	 // "faddq"
          case 's':	 // 1 string to match.
            return MCK_fadds;	 // "fadds"
          }
          break;
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ds", 2))
            break;
          return MCK_fands;	 // "fands"
        }
        break;
      case 'b':	 // 2 strings to match.
        if (Name[2] != 'u')
          break;
        switch (Name[3]) {
        default: break;
        case 'g':	 // 1 string to match.
          if (Name[4] != 'e')
            break;
          return MCK_fbuge;	 // "fbuge"
        case 'l':	 // 1 string to match.
          if (Name[4] != 'e')
            break;
          return MCK_fbule;	 // "fbule"
        }
        break;
      case 'c':	 // 3 strings to match.
        if (memcmp(Name.data()+2, "mp", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_fcmpd;	 // "fcmpd"
        case 'q':	 // 1 string to match.
          return MCK_fcmpq;	 // "fcmpq"
        case 's':	 // 1 string to match.
          return MCK_fcmps;	 // "fcmps"
        }
        break;
      case 'd':	 // 7 strings to match.
        switch (Name[2]) {
        default: break;
        case 'i':	 // 3 strings to match.
          if (Name[3] != 'v')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fdivd;	 // "fdivd"
          case 'q':	 // 1 string to match.
            return MCK_fdivq;	 // "fdivq"
          case 's':	 // 1 string to match.
            return MCK_fdivs;	 // "fdivs"
          }
          break;
        case 't':	 // 4 strings to match.
          if (Name[3] != 'o')
            break;
          switch (Name[4]) {
          default: break;
          case 'i':	 // 1 string to match.
            return MCK_fdtoi;	 // "fdtoi"
          case 'q':	 // 1 string to match.
            return MCK_fdtoq;	 // "fdtoq"
          case 's':	 // 1 string to match.
            return MCK_fdtos;	 // "fdtos"
          case 'x':	 // 1 string to match.
            return MCK_fdtox;	 // "fdtox"
          }
          break;
        }
        break;
      case 'i':	 // 3 strings to match.
        if (memcmp(Name.data()+2, "to", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_fitod;	 // "fitod"
        case 'q':	 // 1 string to match.
          return MCK_fitoq;	 // "fitoq"
        case 's':	 // 1 string to match.
          return MCK_fitos;	 // "fitos"
        }
        break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ush", 3))
          break;
        return MCK_flush;	 // "flush"
      case 'm':	 // 6 strings to match.
        switch (Name[2]) {
        default: break;
        case 'o':	 // 3 strings to match.
          if (Name[3] != 'v')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fmovd;	 // "fmovd"
          case 'q':	 // 1 string to match.
            return MCK_fmovq;	 // "fmovq"
          case 's':	 // 1 string to match.
            return MCK_fmovs;	 // "fmovs"
          }
          break;
        case 'u':	 // 3 strings to match.
          if (Name[3] != 'l')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fmuld;	 // "fmuld"
          case 'q':	 // 1 string to match.
            return MCK_fmulq;	 // "fmulq"
          case 's':	 // 1 string to match.
            return MCK_fmuls;	 // "fmuls"
          }
          break;
        }
        break;
      case 'n':	 // 7 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(Name.data()+3, "nd", 2))
            break;
          return MCK_fnand;	 // "fnand"
        case 'e':	 // 3 strings to match.
          if (Name[3] != 'g')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fnegd;	 // "fnegd"
          case 'q':	 // 1 string to match.
            return MCK_fnegq;	 // "fnegq"
          case 's':	 // 1 string to match.
            return MCK_fnegs;	 // "fnegs"
          }
          break;
        case 'o':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'r':	 // 1 string to match.
            if (Name[4] != 's')
              break;
            return MCK_fnors;	 // "fnors"
          case 't':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '1':	 // 1 string to match.
              return MCK_fnot1;	 // "fnot1"
            case '2':	 // 1 string to match.
              return MCK_fnot2;	 // "fnot2"
            }
            break;
          }
          break;
        }
        break;
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "nes", 3))
          break;
        return MCK_fones;	 // "fones"
      case 'q':	 // 4 strings to match.
        if (memcmp(Name.data()+2, "to", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_fqtod;	 // "fqtod"
        case 'i':	 // 1 string to match.
          return MCK_fqtoi;	 // "fqtoi"
        case 's':	 // 1 string to match.
          return MCK_fqtos;	 // "fqtos"
        case 'x':	 // 1 string to match.
          return MCK_fqtox;	 // "fqtox"
        }
        break;
      case 's':	 // 9 strings to match.
        switch (Name[2]) {
        default: break;
        case 'r':	 // 2 strings to match.
          if (Name[3] != 'c')
            break;
          switch (Name[4]) {
          default: break;
          case '1':	 // 1 string to match.
            return MCK_fsrc1;	 // "fsrc1"
          case '2':	 // 1 string to match.
            return MCK_fsrc2;	 // "fsrc2"
          }
          break;
        case 't':	 // 4 strings to match.
          if (Name[3] != 'o')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fstod;	 // "fstod"
          case 'i':	 // 1 string to match.
            return MCK_fstoi;	 // "fstoi"
          case 'q':	 // 1 string to match.
            return MCK_fstoq;	 // "fstoq"
          case 'x':	 // 1 string to match.
            return MCK_fstox;	 // "fstox"
          }
          break;
        case 'u':	 // 3 strings to match.
          if (Name[3] != 'b')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fsubd;	 // "fsubd"
          case 'q':	 // 1 string to match.
            return MCK_fsubq;	 // "fsubq"
          case 's':	 // 1 string to match.
            return MCK_fsubs;	 // "fsubs"
          }
          break;
        }
        break;
      case 'x':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+3, "or", 2))
            break;
          return MCK_fxnor;	 // "fxnor"
        case 'o':	 // 1 string to match.
          if (memcmp(Name.data()+3, "rs", 2))
            break;
          return MCK_fxors;	 // "fxors"
        case 't':	 // 3 strings to match.
          if (Name[3] != 'o')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fxtod;	 // "fxtod"
          case 'q':	 // 1 string to match.
            return MCK_fxtoq;	 // "fxtoq"
          case 's':	 // 1 string to match.
            return MCK_fxtos;	 // "fxtos"
          }
          break;
        }
        break;
      case 'z':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ero", 3))
          break;
        return MCK_fzero;	 // "fzero"
      }
      break;
    case 'i':	 // 1 string to match.
      if (memcmp(Name.data()+1, "nccc", 4))
        break;
      return MCK_inccc;	 // "inccc"
    case 'l':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 's':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (Name[4] != 'a')
              break;
            return MCK_ldsba;	 // "ldsba"
          case 'h':	 // 1 string to match.
            if (Name[4] != 'a')
              break;
            return MCK_ldsha;	 // "ldsha"
          }
          break;
        case 'u':	 // 2 strings to match.
          switch (Name[3]) {
          default: break;
          case 'b':	 // 1 string to match.
            if (Name[4] != 'a')
              break;
            return MCK_lduba;	 // "lduba"
          case 'h':	 // 1 string to match.
            if (Name[4] != 'a')
              break;
            return MCK_lduha;	 // "lduha"
          }
          break;
        }
        break;
      case 'z':	 // 1 string to match.
        if (memcmp(Name.data()+2, "cnt", 3))
          break;
        return MCK_lzcnt;	 // "lzcnt"
      }
      break;
    case 'm':	 // 16 strings to match.
      if (memcmp(Name.data()+1, "ov", 2))
        break;
      switch (Name[3]) {
      default: break;
      case 'c':	 // 2 strings to match.
        switch (Name[4]) {
        default: break;
        case 'c':	 // 1 string to match.
          return MCK_movcc;	 // "movcc"
        case 's':	 // 1 string to match.
          return MCK_movcs;	 // "movcs"
        }
        break;
      case 'e':	 // 1 string to match.
        if (Name[4] != 'q')
          break;
        return MCK_moveq;	 // "moveq"
      case 'g':	 // 2 strings to match.
        switch (Name[4]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_movge;	 // "movge"
        case 'u':	 // 1 string to match.
          return MCK_movgu;	 // "movgu"
        }
        break;
      case 'l':	 // 3 strings to match.
        switch (Name[4]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_movle;	 // "movle"
        case 'g':	 // 1 string to match.
          return MCK_movlg;	 // "movlg"
        case 'u':	 // 1 string to match.
          return MCK_movlu;	 // "movlu"
        }
        break;
      case 'n':	 // 2 strings to match.
        switch (Name[4]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_movne;	 // "movne"
        case 'z':	 // 1 string to match.
          return MCK_movnz;	 // "movnz"
        }
        break;
      case 'r':	 // 1 string to match.
        if (Name[4] != 'z')
          break;
        return MCK_movrz;	 // "movrz"
      case 'u':	 // 3 strings to match.
        switch (Name[4]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_movue;	 // "movue"
        case 'g':	 // 1 string to match.
          return MCK_movug;	 // "movug"
        case 'l':	 // 1 string to match.
          return MCK_movul;	 // "movul"
        }
        break;
      case 'v':	 // 2 strings to match.
        switch (Name[4]) {
        default: break;
        case 'c':	 // 1 string to match.
          return MCK_movvc;	 // "movvc"
        case 's':	 // 1 string to match.
          return MCK_movvs;	 // "movvs"
        }
        break;
      }
      break;
    case 'o':	 // 1 string to match.
      if (memcmp(Name.data()+1, "rncc", 4))
        break;
      return MCK_orncc;	 // "orncc"
    case 'p':	 // 1 string to match.
      if (memcmp(Name.data()+1, "dist", 4))
        break;
      return MCK_pdist;	 // "pdist"
    case 's':	 // 6 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ivx", 3))
          break;
        return MCK_sdivx;	 // "sdivx"
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "thi", 3))
          break;
        return MCK_sethi;	 // "sethi"
      case 'i':	 // 1 string to match.
        if (memcmp(Name.data()+2, "gnx", 3))
          break;
        return MCK_signx;	 // "signx"
      case 't':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bar", 3))
          break;
        return MCK_stbar;	 // "stbar"
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bcc", 3))
          break;
        return MCK_subcc;	 // "subcc"
      case 'w':	 // 1 string to match.
        if (memcmp(Name.data()+2, "apa", 3))
          break;
        return MCK_swapa;	 // "swapa"
      }
      break;
    case 'u':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ivx", 3))
          break;
        return MCK_udivx;	 // "udivx"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "imp", 3))
          break;
        return MCK_unimp;	 // "unimp"
      }
      break;
    case 'x':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'm':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ulx", 3))
          break;
        return MCK_xmulx;	 // "xmulx"
      case 'o':	 // 1 string to match.
        if (memcmp(Name.data()+2, "rcc", 3))
          break;
        return MCK_xorcc;	 // "xorcc"
      }
      break;
    }
    break;
  case 6:	 // 83 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "dxcc", 4))
          break;
        return MCK_addxcc;	 // "addxcc"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "dncc", 4))
          break;
        return MCK_andncc;	 // "andncc"
      case 'r':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ray8", 4))
          break;
        return MCK_array8;	 // "array8"
      }
      break;
    case 'c':	 // 1 string to match.
      if (memcmp(Name.data()+1, "mask8", 5))
        break;
      return MCK_cmask8;	 // "cmask8"
    case 'e':	 // 4 strings to match.
      if (memcmp(Name.data()+1, "dge", 3))
        break;
      switch (Name[4]) {
      default: break;
      case '1':	 // 1 string to match.
        if (Name[5] != '6')
          break;
        return MCK_edge16;	 // "edge16"
      case '3':	 // 1 string to match.
        if (Name[5] != '2')
          break;
        return MCK_edge32;	 // "edge32"
      case '8':	 // 2 strings to match.
        switch (Name[5]) {
        default: break;
        case 'l':	 // 1 string to match.
          return MCK_edge8l;	 // "edge8l"
        case 'n':	 // 1 string to match.
          return MCK_edge8n;	 // "edge8n"
        }
        break;
      }
      break;
    case 'f':	 // 54 strings to match.
      switch (Name[1]) {
      default: break;
      case 'c':	 // 3 strings to match.
        if (memcmp(Name.data()+2, "mpe", 3))
          break;
        switch (Name[5]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_fcmped;	 // "fcmped"
        case 'q':	 // 1 string to match.
          return MCK_fcmpeq;	 // "fcmpeq"
        case 's':	 // 1 string to match.
          return MCK_fcmpes;	 // "fcmpes"
        }
        break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "mulq", 4))
          break;
        return MCK_fdmulq;	 // "fdmulq"
      case 'h':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "dd", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fhaddd;	 // "fhaddd"
          case 's':	 // 1 string to match.
            return MCK_fhadds;	 // "fhadds"
          }
          break;
        case 's':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ub", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fhsubd;	 // "fhsubd"
          case 's':	 // 1 string to match.
            return MCK_fhsubs;	 // "fhsubs"
          }
          break;
        }
        break;
      case 'l':	 // 3 strings to match.
        switch (Name[2]) {
        default: break;
        case 'c':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "mp", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_flcmpd;	 // "flcmpd"
          case 's':	 // 1 string to match.
            return MCK_flcmps;	 // "flcmps"
          }
          break;
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+3, "shw", 3))
            break;
          return MCK_flushw;	 // "flushw"
        }
        break;
      case 'm':	 // 24 strings to match.
        if (memcmp(Name.data()+2, "ov", 2))
          break;
        switch (Name[4]) {
        default: break;
        case 'd':	 // 8 strings to match.
          switch (Name[5]) {
          default: break;
          case 'a':	 // 1 string to match.
            return MCK_fmovda;	 // "fmovda"
          case 'e':	 // 1 string to match.
            return MCK_fmovde;	 // "fmovde"
          case 'g':	 // 1 string to match.
            return MCK_fmovdg;	 // "fmovdg"
          case 'l':	 // 1 string to match.
            return MCK_fmovdl;	 // "fmovdl"
          case 'n':	 // 1 string to match.
            return MCK_fmovdn;	 // "fmovdn"
          case 'o':	 // 1 string to match.
            return MCK_fmovdo;	 // "fmovdo"
          case 'u':	 // 1 string to match.
            return MCK_fmovdu;	 // "fmovdu"
          case 'z':	 // 1 string to match.
            return MCK_fmovdz;	 // "fmovdz"
          }
          break;
        case 'q':	 // 8 strings to match.
          switch (Name[5]) {
          default: break;
          case 'a':	 // 1 string to match.
            return MCK_fmovqa;	 // "fmovqa"
          case 'e':	 // 1 string to match.
            return MCK_fmovqe;	 // "fmovqe"
          case 'g':	 // 1 string to match.
            return MCK_fmovqg;	 // "fmovqg"
          case 'l':	 // 1 string to match.
            return MCK_fmovql;	 // "fmovql"
          case 'n':	 // 1 string to match.
            return MCK_fmovqn;	 // "fmovqn"
          case 'o':	 // 1 string to match.
            return MCK_fmovqo;	 // "fmovqo"
          case 'u':	 // 1 string to match.
            return MCK_fmovqu;	 // "fmovqu"
          case 'z':	 // 1 string to match.
            return MCK_fmovqz;	 // "fmovqz"
          }
          break;
        case 's':	 // 8 strings to match.
          switch (Name[5]) {
          default: break;
          case 'a':	 // 1 string to match.
            return MCK_fmovsa;	 // "fmovsa"
          case 'e':	 // 1 string to match.
            return MCK_fmovse;	 // "fmovse"
          case 'g':	 // 1 string to match.
            return MCK_fmovsg;	 // "fmovsg"
          case 'l':	 // 1 string to match.
            return MCK_fmovsl;	 // "fmovsl"
          case 'n':	 // 1 string to match.
            return MCK_fmovsn;	 // "fmovsn"
          case 'o':	 // 1 string to match.
            return MCK_fmovso;	 // "fmovso"
          case 'u':	 // 1 string to match.
            return MCK_fmovsu;	 // "fmovsu"
          case 'z':	 // 1 string to match.
            return MCK_fmovsz;	 // "fmovsz"
          }
          break;
        }
        break;
      case 'n':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'd':	 // 2 strings to match.
            if (Name[4] != 'd')
              break;
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              return MCK_fnaddd;	 // "fnaddd"
            case 's':	 // 1 string to match.
              return MCK_fnadds;	 // "fnadds"
            }
            break;
          case 'n':	 // 1 string to match.
            if (memcmp(Name.data()+4, "ds", 2))
              break;
            return MCK_fnands;	 // "fnands"
          }
          break;
        case 'o':	 // 2 strings to match.
          if (Name[3] != 't')
            break;
          switch (Name[4]) {
          default: break;
          case '1':	 // 1 string to match.
            if (Name[5] != 's')
              break;
            return MCK_fnot1s;	 // "fnot1s"
          case '2':	 // 1 string to match.
            if (Name[5] != 's')
              break;
            return MCK_fnot2s;	 // "fnot2s"
          }
          break;
        }
        break;
      case 's':	 // 12 strings to match.
        switch (Name[2]) {
        default: break;
        case 'l':	 // 2 strings to match.
          if (Name[3] != 'l')
            break;
          switch (Name[4]) {
          default: break;
          case '1':	 // 1 string to match.
            if (Name[5] != '6')
              break;
            return MCK_fsll16;	 // "fsll16"
          case '3':	 // 1 string to match.
            if (Name[5] != '2')
              break;
            return MCK_fsll32;	 // "fsll32"
          }
          break;
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "uld", 3))
            break;
          return MCK_fsmuld;	 // "fsmuld"
        case 'q':	 // 3 strings to match.
          if (memcmp(Name.data()+3, "rt", 2))
            break;
          switch (Name[5]) {
          default: break;
          case 'd':	 // 1 string to match.
            return MCK_fsqrtd;	 // "fsqrtd"
          case 'q':	 // 1 string to match.
            return MCK_fsqrtq;	 // "fsqrtq"
          case 's':	 // 1 string to match.
            return MCK_fsqrts;	 // "fsqrts"
          }
          break;
        case 'r':	 // 6 strings to match.
          switch (Name[3]) {
          default: break;
          case 'a':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '1':	 // 1 string to match.
              if (Name[5] != '6')
                break;
              return MCK_fsra16;	 // "fsra16"
            case '3':	 // 1 string to match.
              if (Name[5] != '2')
                break;
              return MCK_fsra32;	 // "fsra32"
            }
            break;
          case 'c':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '1':	 // 1 string to match.
              if (Name[5] != 's')
                break;
              return MCK_fsrc1s;	 // "fsrc1s"
            case '2':	 // 1 string to match.
              if (Name[5] != 's')
                break;
              return MCK_fsrc2s;	 // "fsrc2s"
            }
            break;
          case 'l':	 // 2 strings to match.
            switch (Name[4]) {
            default: break;
            case '1':	 // 1 string to match.
              if (Name[5] != '6')
                break;
              return MCK_fsrl16;	 // "fsrl16"
            case '3':	 // 1 string to match.
              if (Name[5] != '2')
                break;
              return MCK_fsrl32;	 // "fsrl32"
            }
            break;
          }
          break;
        }
        break;
      case 'x':	 // 1 string to match.
        if (memcmp(Name.data()+2, "nors", 4))
          break;
        return MCK_fxnors;	 // "fxnors"
      case 'z':	 // 1 string to match.
        if (memcmp(Name.data()+2, "eros", 4))
          break;
        return MCK_fzeros;	 // "fzeros"
      }
      break;
    case 'l':	 // 1 string to match.
      if (memcmp(Name.data()+1, "dstub", 5))
        break;
      return MCK_ldstub;	 // "ldstub"
    case 'm':	 // 11 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "mbar", 4))
          break;
        return MCK_membar;	 // "membar"
      case 'o':	 // 9 strings to match.
        if (Name[2] != 'v')
          break;
        switch (Name[3]) {
        default: break;
        case 'g':	 // 1 string to match.
          if (memcmp(Name.data()+4, "eu", 2))
            break;
          return MCK_movgeu;	 // "movgeu"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+4, "eu", 2))
            break;
          return MCK_movleu;	 // "movleu"
        case 'n':	 // 1 string to match.
          if (memcmp(Name.data()+4, "eg", 2))
            break;
          return MCK_movneg;	 // "movneg"
        case 'p':	 // 1 string to match.
          if (memcmp(Name.data()+4, "os", 2))
            break;
          return MCK_movpos;	 // "movpos"
        case 'r':	 // 3 strings to match.
          switch (Name[4]) {
          default: break;
          case 'g':	 // 1 string to match.
            if (Name[5] != 'z')
              break;
            return MCK_movrgz;	 // "movrgz"
          case 'l':	 // 1 string to match.
            if (Name[5] != 'z')
              break;
            return MCK_movrlz;	 // "movrlz"
          case 'n':	 // 1 string to match.
            if (Name[5] != 'z')
              break;
            return MCK_movrnz;	 // "movrnz"
          }
          break;
        case 'u':	 // 2 strings to match.
          switch (Name[4]) {
          default: break;
          case 'g':	 // 1 string to match.
            if (Name[5] != 'e')
              break;
            return MCK_movuge;	 // "movuge"
          case 'l':	 // 1 string to match.
            if (Name[5] != 'e')
              break;
            return MCK_movule;	 // "movule"
          }
          break;
        }
        break;
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "lscc", 4))
          break;
        return MCK_mulscc;	 // "mulscc"
      }
      break;
    case 'p':	 // 1 string to match.
      if (memcmp(Name.data()+1, "distn", 5))
        break;
      return MCK_pdistn;	 // "pdistn"
    case 's':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ivcc", 4))
          break;
        return MCK_sdivcc;	 // "sdivcc"
      case 'm':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ulcc", 4))
          break;
        return MCK_smulcc;	 // "smulcc"
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bxcc", 4))
          break;
        return MCK_subxcc;	 // "subxcc"
      }
      break;
    case 't':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ddcc", 4))
          break;
        return MCK_taddcc;	 // "taddcc"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ubcc", 4))
          break;
        return MCK_tsubcc;	 // "tsubcc"
      }
      break;
    case 'u':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ivcc", 4))
          break;
        return MCK_udivcc;	 // "udivcc"
      case 'm':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ulcc", 4))
          break;
        return MCK_umulcc;	 // "umulcc"
      }
      break;
    case 'x':	 // 1 string to match.
      if (memcmp(Name.data()+1, "norcc", 5))
        break;
      return MCK_xnorcc;	 // "xnorcc"
    }
    break;
  case 7:	 // 81 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 3 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "dxccc", 5))
          break;
        return MCK_addxccc;	 // "addxccc"
      case 'r':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "ray", 3))
          break;
        switch (Name[5]) {
        default: break;
        case '1':	 // 1 string to match.
          if (Name[6] != '6')
            break;
          return MCK_array16;	 // "array16"
        case '3':	 // 1 string to match.
          if (Name[6] != '2')
            break;
          return MCK_array32;	 // "array32"
        }
        break;
      }
      break;
    case 'c':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "mask", 4))
        break;
      switch (Name[5]) {
      default: break;
      case '1':	 // 1 string to match.
        if (Name[6] != '6')
          break;
        return MCK_cmask16;	 // "cmask16"
      case '3':	 // 1 string to match.
        if (Name[6] != '2')
          break;
        return MCK_cmask32;	 // "cmask32"
      }
      break;
    case 'e':	 // 5 strings to match.
      if (memcmp(Name.data()+1, "dge", 3))
        break;
      switch (Name[4]) {
      default: break;
      case '1':	 // 2 strings to match.
        if (Name[5] != '6')
          break;
        switch (Name[6]) {
        default: break;
        case 'l':	 // 1 string to match.
          return MCK_edge16l;	 // "edge16l"
        case 'n':	 // 1 string to match.
          return MCK_edge16n;	 // "edge16n"
        }
        break;
      case '3':	 // 2 strings to match.
        if (Name[5] != '2')
          break;
        switch (Name[6]) {
        default: break;
        case 'l':	 // 1 string to match.
          return MCK_edge32l;	 // "edge32l"
        case 'n':	 // 1 string to match.
          return MCK_edge32n;	 // "edge32n"
        }
        break;
      case '8':	 // 1 string to match.
        if (memcmp(Name.data()+5, "ln", 2))
          break;
        return MCK_edge8ln;	 // "edge8ln"
      }
      break;
    case 'f':	 // 64 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "xpand", 5))
          break;
        return MCK_fexpand;	 // "fexpand"
      case 'm':	 // 49 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (memcmp(Name.data()+3, "an16", 4))
            break;
          return MCK_fmean16;	 // "fmean16"
        case 'o':	 // 48 strings to match.
          if (Name[3] != 'v')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 15 strings to match.
            switch (Name[5]) {
            default: break;
            case 'c':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'c':	 // 1 string to match.
                return MCK_fmovdcc;	 // "fmovdcc"
              case 's':	 // 1 string to match.
                return MCK_fmovdcs;	 // "fmovdcs"
              }
              break;
            case 'e':	 // 1 string to match.
              if (Name[6] != 'q')
                break;
              return MCK_fmovdeq;	 // "fmovdeq"
            case 'g':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovdge;	 // "fmovdge"
              case 'u':	 // 1 string to match.
                return MCK_fmovdgu;	 // "fmovdgu"
              }
              break;
            case 'l':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovdle;	 // "fmovdle"
              case 'g':	 // 1 string to match.
                return MCK_fmovdlg;	 // "fmovdlg"
              case 'u':	 // 1 string to match.
                return MCK_fmovdlu;	 // "fmovdlu"
              }
              break;
            case 'n':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovdne;	 // "fmovdne"
              case 'z':	 // 1 string to match.
                return MCK_fmovdnz;	 // "fmovdnz"
              }
              break;
            case 'u':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovdue;	 // "fmovdue"
              case 'g':	 // 1 string to match.
                return MCK_fmovdug;	 // "fmovdug"
              case 'l':	 // 1 string to match.
                return MCK_fmovdul;	 // "fmovdul"
              }
              break;
            case 'v':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'c':	 // 1 string to match.
                return MCK_fmovdvc;	 // "fmovdvc"
              case 's':	 // 1 string to match.
                return MCK_fmovdvs;	 // "fmovdvs"
              }
              break;
            }
            break;
          case 'q':	 // 15 strings to match.
            switch (Name[5]) {
            default: break;
            case 'c':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'c':	 // 1 string to match.
                return MCK_fmovqcc;	 // "fmovqcc"
              case 's':	 // 1 string to match.
                return MCK_fmovqcs;	 // "fmovqcs"
              }
              break;
            case 'e':	 // 1 string to match.
              if (Name[6] != 'q')
                break;
              return MCK_fmovqeq;	 // "fmovqeq"
            case 'g':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovqge;	 // "fmovqge"
              case 'u':	 // 1 string to match.
                return MCK_fmovqgu;	 // "fmovqgu"
              }
              break;
            case 'l':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovqle;	 // "fmovqle"
              case 'g':	 // 1 string to match.
                return MCK_fmovqlg;	 // "fmovqlg"
              case 'u':	 // 1 string to match.
                return MCK_fmovqlu;	 // "fmovqlu"
              }
              break;
            case 'n':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovqne;	 // "fmovqne"
              case 'z':	 // 1 string to match.
                return MCK_fmovqnz;	 // "fmovqnz"
              }
              break;
            case 'u':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovque;	 // "fmovque"
              case 'g':	 // 1 string to match.
                return MCK_fmovqug;	 // "fmovqug"
              case 'l':	 // 1 string to match.
                return MCK_fmovqul;	 // "fmovqul"
              }
              break;
            case 'v':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'c':	 // 1 string to match.
                return MCK_fmovqvc;	 // "fmovqvc"
              case 's':	 // 1 string to match.
                return MCK_fmovqvs;	 // "fmovqvs"
              }
              break;
            }
            break;
          case 'r':	 // 3 strings to match.
            switch (Name[5]) {
            default: break;
            case 'd':	 // 1 string to match.
              if (Name[6] != 'z')
                break;
              return MCK_fmovrdz;	 // "fmovrdz"
            case 'q':	 // 1 string to match.
              if (Name[6] != 'z')
                break;
              return MCK_fmovrqz;	 // "fmovrqz"
            case 's':	 // 1 string to match.
              if (Name[6] != 'z')
                break;
              return MCK_fmovrsz;	 // "fmovrsz"
            }
            break;
          case 's':	 // 15 strings to match.
            switch (Name[5]) {
            default: break;
            case 'c':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'c':	 // 1 string to match.
                return MCK_fmovscc;	 // "fmovscc"
              case 's':	 // 1 string to match.
                return MCK_fmovscs;	 // "fmovscs"
              }
              break;
            case 'e':	 // 1 string to match.
              if (Name[6] != 'q')
                break;
              return MCK_fmovseq;	 // "fmovseq"
            case 'g':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovsge;	 // "fmovsge"
              case 'u':	 // 1 string to match.
                return MCK_fmovsgu;	 // "fmovsgu"
              }
              break;
            case 'l':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovsle;	 // "fmovsle"
              case 'g':	 // 1 string to match.
                return MCK_fmovslg;	 // "fmovslg"
              case 'u':	 // 1 string to match.
                return MCK_fmovslu;	 // "fmovslu"
              }
              break;
            case 'n':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovsne;	 // "fmovsne"
              case 'z':	 // 1 string to match.
                return MCK_fmovsnz;	 // "fmovsnz"
              }
              break;
            case 'u':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'e':	 // 1 string to match.
                return MCK_fmovsue;	 // "fmovsue"
              case 'g':	 // 1 string to match.
                return MCK_fmovsug;	 // "fmovsug"
              case 'l':	 // 1 string to match.
                return MCK_fmovsul;	 // "fmovsul"
              }
              break;
            case 'v':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'c':	 // 1 string to match.
                return MCK_fmovsvc;	 // "fmovsvc"
              case 's':	 // 1 string to match.
                return MCK_fmovsvs;	 // "fmovsvs"
              }
              break;
            }
            break;
          }
          break;
        }
        break;
      case 'n':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "hadd", 4))
          break;
        switch (Name[6]) {
        default: break;
        case 'd':	 // 1 string to match.
          return MCK_fnhaddd;	 // "fnhaddd"
        case 's':	 // 1 string to match.
          return MCK_fnhadds;	 // "fnhadds"
        }
        break;
      case 'o':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "rnot", 4))
          break;
        switch (Name[6]) {
        default: break;
        case '1':	 // 1 string to match.
          return MCK_fornot1;	 // "fornot1"
        case '2':	 // 1 string to match.
          return MCK_fornot2;	 // "fornot2"
        }
        break;
      case 'p':	 // 8 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 5 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 2 strings to match.
            if (Name[4] != 'k')
              break;
            switch (Name[5]) {
            default: break;
            case '1':	 // 1 string to match.
              if (Name[6] != '6')
                break;
              return MCK_fpack16;	 // "fpack16"
            case '3':	 // 1 string to match.
              if (Name[6] != '2')
                break;
              return MCK_fpack32;	 // "fpack32"
            }
            break;
          case 'd':	 // 3 strings to match.
            if (Name[4] != 'd')
              break;
            switch (Name[5]) {
            default: break;
            case '1':	 // 1 string to match.
              if (Name[6] != '6')
                break;
              return MCK_fpadd16;	 // "fpadd16"
            case '3':	 // 1 string to match.
              if (Name[6] != '2')
                break;
              return MCK_fpadd32;	 // "fpadd32"
            case '6':	 // 1 string to match.
              if (Name[6] != '4')
                break;
              return MCK_fpadd64;	 // "fpadd64"
            }
            break;
          }
          break;
        case 'm':	 // 1 string to match.
          if (memcmp(Name.data()+3, "erge", 4))
            break;
          return MCK_fpmerge;	 // "fpmerge"
        case 's':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ub", 2))
            break;
          switch (Name[5]) {
          default: break;
          case '1':	 // 1 string to match.
            if (Name[6] != '6')
              break;
            return MCK_fpsub16;	 // "fpsub16"
          case '3':	 // 1 string to match.
            if (Name[6] != '2')
              break;
            return MCK_fpsub32;	 // "fpsub32"
          }
          break;
        }
        break;
      case 's':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "las", 3))
          break;
        switch (Name[5]) {
        default: break;
        case '1':	 // 1 string to match.
          if (Name[6] != '6')
            break;
          return MCK_fslas16;	 // "fslas16"
        case '3':	 // 1 string to match.
          if (Name[6] != '2')
            break;
          return MCK_fslas32;	 // "fslas32"
        }
        break;
      }
      break;
    case 'l':	 // 1 string to match.
      if (memcmp(Name.data()+1, "dstuba", 6))
        break;
      return MCK_ldstuba;	 // "ldstuba"
    case 'm':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "ov", 2))
        break;
      switch (Name[3]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+4, "tox", 3))
          break;
        return MCK_movdtox;	 // "movdtox"
      case 'r':	 // 2 strings to match.
        switch (Name[4]) {
        default: break;
        case 'g':	 // 1 string to match.
          if (memcmp(Name.data()+5, "ez", 2))
            break;
          return MCK_movrgez;	 // "movrgez"
        case 'l':	 // 1 string to match.
          if (memcmp(Name.data()+5, "ez", 2))
            break;
          return MCK_movrlez;	 // "movrlez"
        }
        break;
      }
      break;
    case 'r':	 // 1 string to match.
      if (memcmp(Name.data()+1, "estore", 6))
        break;
      return MCK_restore;	 // "restore"
    case 'u':	 // 1 string to match.
      if (memcmp(Name.data()+1, "mulxhi", 6))
        break;
      return MCK_umulxhi;	 // "umulxhi"
    case 'x':	 // 1 string to match.
      if (memcmp(Name.data()+1, "mulxhi", 6))
        break;
      return MCK_xmulxhi;	 // "xmulxhi"
    }
    break;
  case 8:	 // 54 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 1 string to match.
      if (memcmp(Name.data()+1, "shuffle", 7))
        break;
      return MCK_bshuffle;	 // "bshuffle"
    case 'e':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "dge", 3))
        break;
      switch (Name[4]) {
      default: break;
      case '1':	 // 1 string to match.
        if (memcmp(Name.data()+5, "6ln", 3))
          break;
        return MCK_edge16ln;	 // "edge16ln"
      case '3':	 // 1 string to match.
        if (memcmp(Name.data()+5, "2ln", 3))
          break;
        return MCK_edge32ln;	 // "edge32ln"
      }
      break;
    case 'f':	 // 46 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "ndnot", 5))
          break;
        switch (Name[7]) {
        default: break;
        case '1':	 // 1 string to match.
          return MCK_fandnot1;	 // "fandnot1"
        case '2':	 // 1 string to match.
          return MCK_fandnot2;	 // "fandnot2"
        }
        break;
      case 'c':	 // 9 strings to match.
        switch (Name[2]) {
        default: break;
        case 'h':	 // 1 string to match.
          if (memcmp(Name.data()+3, "ksm16", 5))
            break;
          return MCK_fchksm16;	 // "fchksm16"
        case 'm':	 // 8 strings to match.
          if (Name[3] != 'p')
            break;
          switch (Name[4]) {
          default: break;
          case 'e':	 // 2 strings to match.
            if (Name[5] != 'q')
              break;
            switch (Name[6]) {
            default: break;
            case '1':	 // 1 string to match.
              if (Name[7] != '6')
                break;
              return MCK_fcmpeq16;	 // "fcmpeq16"
            case '3':	 // 1 string to match.
              if (Name[7] != '2')
                break;
              return MCK_fcmpeq32;	 // "fcmpeq32"
            }
            break;
          case 'g':	 // 2 strings to match.
            if (Name[5] != 't')
              break;
            switch (Name[6]) {
            default: break;
            case '1':	 // 1 string to match.
              if (Name[7] != '6')
                break;
              return MCK_fcmpgt16;	 // "fcmpgt16"
            case '3':	 // 1 string to match.
              if (Name[7] != '2')
                break;
              return MCK_fcmpgt32;	 // "fcmpgt32"
            }
            break;
          case 'l':	 // 2 strings to match.
            if (Name[5] != 'e')
              break;
            switch (Name[6]) {
            default: break;
            case '1':	 // 1 string to match.
              if (Name[7] != '6')
                break;
              return MCK_fcmple16;	 // "fcmple16"
            case '3':	 // 1 string to match.
              if (Name[7] != '2')
                break;
              return MCK_fcmple32;	 // "fcmple32"
            }
            break;
          case 'n':	 // 2 strings to match.
            if (Name[5] != 'e')
              break;
            switch (Name[6]) {
            default: break;
            case '1':	 // 1 string to match.
              if (Name[7] != '6')
                break;
              return MCK_fcmpne16;	 // "fcmpne16"
            case '3':	 // 1 string to match.
              if (Name[7] != '2')
                break;
              return MCK_fcmpne32;	 // "fcmpne32"
            }
            break;
          }
          break;
        }
        break;
      case 'm':	 // 28 strings to match.
        switch (Name[2]) {
        default: break;
        case 'o':	 // 27 strings to match.
          if (Name[3] != 'v')
            break;
          switch (Name[4]) {
          default: break;
          case 'd':	 // 6 strings to match.
            switch (Name[5]) {
            default: break;
            case 'g':	 // 1 string to match.
              if (memcmp(Name.data()+6, "eu", 2))
                break;
              return MCK_fmovdgeu;	 // "fmovdgeu"
            case 'l':	 // 1 string to match.
              if (memcmp(Name.data()+6, "eu", 2))
                break;
              return MCK_fmovdleu;	 // "fmovdleu"
            case 'n':	 // 1 string to match.
              if (memcmp(Name.data()+6, "eg", 2))
                break;
              return MCK_fmovdneg;	 // "fmovdneg"
            case 'p':	 // 1 string to match.
              if (memcmp(Name.data()+6, "os", 2))
                break;
              return MCK_fmovdpos;	 // "fmovdpos"
            case 'u':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'g':	 // 1 string to match.
                if (Name[7] != 'e')
                  break;
                return MCK_fmovduge;	 // "fmovduge"
              case 'l':	 // 1 string to match.
                if (Name[7] != 'e')
                  break;
                return MCK_fmovdule;	 // "fmovdule"
              }
              break;
            }
            break;
          case 'q':	 // 6 strings to match.
            switch (Name[5]) {
            default: break;
            case 'g':	 // 1 string to match.
              if (memcmp(Name.data()+6, "eu", 2))
                break;
              return MCK_fmovqgeu;	 // "fmovqgeu"
            case 'l':	 // 1 string to match.
              if (memcmp(Name.data()+6, "eu", 2))
                break;
              return MCK_fmovqleu;	 // "fmovqleu"
            case 'n':	 // 1 string to match.
              if (memcmp(Name.data()+6, "eg", 2))
                break;
              return MCK_fmovqneg;	 // "fmovqneg"
            case 'p':	 // 1 string to match.
              if (memcmp(Name.data()+6, "os", 2))
                break;
              return MCK_fmovqpos;	 // "fmovqpos"
            case 'u':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'g':	 // 1 string to match.
                if (Name[7] != 'e')
                  break;
                return MCK_fmovquge;	 // "fmovquge"
              case 'l':	 // 1 string to match.
                if (Name[7] != 'e')
                  break;
                return MCK_fmovqule;	 // "fmovqule"
              }
              break;
            }
            break;
          case 'r':	 // 9 strings to match.
            switch (Name[5]) {
            default: break;
            case 'd':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'g':	 // 1 string to match.
                if (Name[7] != 'z')
                  break;
                return MCK_fmovrdgz;	 // "fmovrdgz"
              case 'l':	 // 1 string to match.
                if (Name[7] != 'z')
                  break;
                return MCK_fmovrdlz;	 // "fmovrdlz"
              case 'n':	 // 1 string to match.
                if (Name[7] != 'z')
                  break;
                return MCK_fmovrdnz;	 // "fmovrdnz"
              }
              break;
            case 'q':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'g':	 // 1 string to match.
                if (Name[7] != 'z')
                  break;
                return MCK_fmovrqgz;	 // "fmovrqgz"
              case 'l':	 // 1 string to match.
                if (Name[7] != 'z')
                  break;
                return MCK_fmovrqlz;	 // "fmovrqlz"
              case 'n':	 // 1 string to match.
                if (Name[7] != 'z')
                  break;
                return MCK_fmovrqnz;	 // "fmovrqnz"
              }
              break;
            case 's':	 // 3 strings to match.
              switch (Name[6]) {
              default: break;
              case 'g':	 // 1 string to match.
                if (Name[7] != 'z')
                  break;
                return MCK_fmovrsgz;	 // "fmovrsgz"
              case 'l':	 // 1 string to match.
                if (Name[7] != 'z')
                  break;
                return MCK_fmovrslz;	 // "fmovrslz"
              case 'n':	 // 1 string to match.
                if (Name[7] != 'z')
                  break;
                return MCK_fmovrsnz;	 // "fmovrsnz"
              }
              break;
            }
            break;
          case 's':	 // 6 strings to match.
            switch (Name[5]) {
            default: break;
            case 'g':	 // 1 string to match.
              if (memcmp(Name.data()+6, "eu", 2))
                break;
              return MCK_fmovsgeu;	 // "fmovsgeu"
            case 'l':	 // 1 string to match.
              if (memcmp(Name.data()+6, "eu", 2))
                break;
              return MCK_fmovsleu;	 // "fmovsleu"
            case 'n':	 // 1 string to match.
              if (memcmp(Name.data()+6, "eg", 2))
                break;
              return MCK_fmovsneg;	 // "fmovsneg"
            case 'p':	 // 1 string to match.
              if (memcmp(Name.data()+6, "os", 2))
                break;
              return MCK_fmovspos;	 // "fmovspos"
            case 'u':	 // 2 strings to match.
              switch (Name[6]) {
              default: break;
              case 'g':	 // 1 string to match.
                if (Name[7] != 'e')
                  break;
                return MCK_fmovsuge;	 // "fmovsuge"
              case 'l':	 // 1 string to match.
                if (Name[7] != 'e')
                  break;
                return MCK_fmovsule;	 // "fmovsule"
              }
              break;
            }
            break;
          }
          break;
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+3, "l8x16", 5))
            break;
          return MCK_fmul8x16;	 // "fmul8x16"
        }
        break;
      case 'o':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "rnot", 4))
          break;
        switch (Name[6]) {
        default: break;
        case '1':	 // 1 string to match.
          if (Name[7] != 's')
            break;
          return MCK_fornot1s;	 // "fornot1s"
        case '2':	 // 1 string to match.
          if (Name[7] != 's')
            break;
          return MCK_fornot2s;	 // "fornot2s"
        }
        break;
      case 'p':	 // 5 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 3 strings to match.
          switch (Name[3]) {
          default: break;
          case 'c':	 // 1 string to match.
            if (memcmp(Name.data()+4, "kfix", 4))
              break;
            return MCK_fpackfix;	 // "fpackfix"
          case 'd':	 // 2 strings to match.
            if (Name[4] != 'd')
              break;
            switch (Name[5]) {
            default: break;
            case '1':	 // 1 string to match.
              if (memcmp(Name.data()+6, "6s", 2))
                break;
              return MCK_fpadd16s;	 // "fpadd16s"
            case '3':	 // 1 string to match.
              if (memcmp(Name.data()+6, "2s", 2))
                break;
              return MCK_fpadd32s;	 // "fpadd32s"
            }
            break;
          }
          break;
        case 's':	 // 2 strings to match.
          if (memcmp(Name.data()+3, "ub", 2))
            break;
          switch (Name[5]) {
          default: break;
          case '1':	 // 1 string to match.
            if (memcmp(Name.data()+6, "6S", 2))
              break;
            return MCK_fpsub16S;	 // "fpsub16S"
          case '3':	 // 1 string to match.
            if (memcmp(Name.data()+6, "2S", 2))
              break;
            return MCK_fpsub32S;	 // "fpsub32S"
          }
          break;
        }
        break;
      }
      break;
    case 'm':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "ovsto", 5))
        break;
      switch (Name[6]) {
      default: break;
      case 's':	 // 1 string to match.
        if (Name[7] != 'w')
          break;
        return MCK_movstosw;	 // "movstosw"
      case 'u':	 // 1 string to match.
        if (Name[7] != 'w')
          break;
        return MCK_movstouw;	 // "movstouw"
      }
      break;
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+1, "hutdown", 7))
        break;
      return MCK_shutdown;	 // "shutdown"
    case 't':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ddcctv", 6))
          break;
        return MCK_taddcctv;	 // "taddcctv"
      case 's':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ubcctv", 6))
          break;
        return MCK_tsubcctv;	 // "tsubcctv"
      }
      break;
    }
    break;
  case 9:	 // 9 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "lignaddr", 8))
        break;
      return MCK_alignaddr;	 // "alignaddr"
    case 'f':	 // 8 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 2 strings to match.
        if (memcmp(Name.data()+2, "ndnot", 5))
          break;
        switch (Name[7]) {
        default: break;
        case '1':	 // 1 string to match.
          if (Name[8] != 's')
            break;
          return MCK_fandnot1s;	 // "fandnot1s"
        case '2':	 // 1 string to match.
          if (Name[8] != 's')
            break;
          return MCK_fandnot2s;	 // "fandnot2s"
        }
        break;
      case 'm':	 // 6 strings to match.
        if (memcmp(Name.data()+2, "ovr", 3))
          break;
        switch (Name[5]) {
        default: break;
        case 'd':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 'g':	 // 1 string to match.
            if (memcmp(Name.data()+7, "ez", 2))
              break;
            return MCK_fmovrdgez;	 // "fmovrdgez"
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+7, "ez", 2))
              break;
            return MCK_fmovrdlez;	 // "fmovrdlez"
          }
          break;
        case 'q':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 'g':	 // 1 string to match.
            if (memcmp(Name.data()+7, "ez", 2))
              break;
            return MCK_fmovrqgez;	 // "fmovrqgez"
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+7, "ez", 2))
              break;
            return MCK_fmovrqlez;	 // "fmovrqlez"
          }
          break;
        case 's':	 // 2 strings to match.
          switch (Name[6]) {
          default: break;
          case 'g':	 // 1 string to match.
            if (memcmp(Name.data()+7, "ez", 2))
              break;
            return MCK_fmovrsgez;	 // "fmovrsgez"
          case 'l':	 // 1 string to match.
            if (memcmp(Name.data()+7, "ez", 2))
              break;
            return MCK_fmovrslez;	 // "fmovrslez"
          }
          break;
        }
        break;
      }
      break;
    }
    break;
  case 10:	 // 6 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 1 string to match.
      if (memcmp(Name.data()+1, "lignaddrl", 9))
        break;
      return MCK_alignaddrl;	 // "alignaddrl"
    case 'f':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'a':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ligndata", 8))
          break;
        return MCK_faligndata;	 // "faligndata"
      case 'm':	 // 4 strings to match.
        if (memcmp(Name.data()+2, "ul8", 3))
          break;
        switch (Name[5]) {
        default: break;
        case 's':	 // 1 string to match.
          if (memcmp(Name.data()+6, "ux16", 4))
            break;
          return MCK_fmul8sux16;	 // "fmul8sux16"
        case 'u':	 // 1 string to match.
          if (memcmp(Name.data()+6, "lx16", 4))
            break;
          return MCK_fmul8ulx16;	 // "fmul8ulx16"
        case 'x':	 // 2 strings to match.
          if (memcmp(Name.data()+6, "16a", 3))
            break;
          switch (Name[9]) {
          default: break;
          case 'l':	 // 1 string to match.
            return MCK_fmul8x16al;	 // "fmul8x16al"
          case 'u':	 // 1 string to match.
            return MCK_fmul8x16au;	 // "fmul8x16au"
          }
          break;
        }
        break;
      }
      break;
    }
    break;
  case 11:	 // 2 strings to match.
    if (memcmp(Name.data()+0, "fmuld8", 6))
      break;
    switch (Name[6]) {
    default: break;
    case 's':	 // 1 string to match.
      if (memcmp(Name.data()+7, "ux16", 4))
        break;
      return MCK_fmuld8sux16;	 // "fmuld8sux16"
    case 'u':	 // 1 string to match.
      if (memcmp(Name.data()+7, "lx16", 4))
        break;
      return MCK_fmuld8ulx16;	 // "fmuld8ulx16"
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

  case MCK_Reg5:
    return B == MCK_DFPRegs;

  case MCK_Reg7:
    return B == MCK_QFPRegs;
  }
}

static unsigned validateOperandClass(MCParsedAsmOperand &GOp, MatchClassKind Kind) {
  SparcOperand &Operand = (SparcOperand&)GOp;
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

  // 'MEMri' class
  if (Kind == MCK_MEMri) {
    if (Operand.isMEMri())
      return MCTargetAsmParser::Match_Success;
  }

  // 'MEMrr' class
  if (Kind == MCK_MEMrr) {
    if (Operand.isMEMrr())
      return MCTargetAsmParser::Match_Success;
  }

  if (Operand.isReg()) {
    MatchClassKind OpKind;
    switch (Operand.getReg()) {
    default: OpKind = InvalidMatchClass; break;
    case Sparc::FCC0: OpKind = MCK_FCCRegs; break;
    case Sparc::FCC1: OpKind = MCK_FCCRegs; break;
    case Sparc::FCC2: OpKind = MCK_FCCRegs; break;
    case Sparc::FCC3: OpKind = MCK_FCCRegs; break;
    case Sparc::Y: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR1: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR2: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR3: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR4: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR5: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR6: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR7: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR8: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR9: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR10: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR11: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR12: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR13: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR14: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR15: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR16: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR17: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR18: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR19: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR20: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR21: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR22: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR23: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR24: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR25: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR26: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR27: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR28: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR29: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR30: OpKind = MCK_ASRRegs; break;
    case Sparc::ASR31: OpKind = MCK_ASRRegs; break;
    case Sparc::TPC: OpKind = MCK_PRRegs; break;
    case Sparc::TNPC: OpKind = MCK_PRRegs; break;
    case Sparc::TSTATE: OpKind = MCK_PRRegs; break;
    case Sparc::TT: OpKind = MCK_PRRegs; break;
    case Sparc::TICK: OpKind = MCK_PRRegs; break;
    case Sparc::TBA: OpKind = MCK_PRRegs; break;
    case Sparc::PSTATE: OpKind = MCK_PRRegs; break;
    case Sparc::TL: OpKind = MCK_PRRegs; break;
    case Sparc::PIL: OpKind = MCK_PRRegs; break;
    case Sparc::CWP: OpKind = MCK_PRRegs; break;
    case Sparc::CANSAVE: OpKind = MCK_PRRegs; break;
    case Sparc::CANRESTORE: OpKind = MCK_PRRegs; break;
    case Sparc::CLEANWIN: OpKind = MCK_PRRegs; break;
    case Sparc::OTHERWIN: OpKind = MCK_PRRegs; break;
    case Sparc::WSTATE: OpKind = MCK_PRRegs; break;
    case Sparc::G0: OpKind = MCK_IntRegs; break;
    case Sparc::G1: OpKind = MCK_IntRegs; break;
    case Sparc::G2: OpKind = MCK_IntRegs; break;
    case Sparc::G3: OpKind = MCK_IntRegs; break;
    case Sparc::G4: OpKind = MCK_IntRegs; break;
    case Sparc::G5: OpKind = MCK_IntRegs; break;
    case Sparc::G6: OpKind = MCK_IntRegs; break;
    case Sparc::G7: OpKind = MCK_IntRegs; break;
    case Sparc::O0: OpKind = MCK_IntRegs; break;
    case Sparc::O1: OpKind = MCK_IntRegs; break;
    case Sparc::O2: OpKind = MCK_IntRegs; break;
    case Sparc::O3: OpKind = MCK_IntRegs; break;
    case Sparc::O4: OpKind = MCK_IntRegs; break;
    case Sparc::O5: OpKind = MCK_IntRegs; break;
    case Sparc::O6: OpKind = MCK_IntRegs; break;
    case Sparc::O7: OpKind = MCK_IntRegs; break;
    case Sparc::L0: OpKind = MCK_IntRegs; break;
    case Sparc::L1: OpKind = MCK_IntRegs; break;
    case Sparc::L2: OpKind = MCK_IntRegs; break;
    case Sparc::L3: OpKind = MCK_IntRegs; break;
    case Sparc::L4: OpKind = MCK_IntRegs; break;
    case Sparc::L5: OpKind = MCK_IntRegs; break;
    case Sparc::L6: OpKind = MCK_IntRegs; break;
    case Sparc::L7: OpKind = MCK_IntRegs; break;
    case Sparc::I0: OpKind = MCK_IntRegs; break;
    case Sparc::I1: OpKind = MCK_IntRegs; break;
    case Sparc::I2: OpKind = MCK_IntRegs; break;
    case Sparc::I3: OpKind = MCK_IntRegs; break;
    case Sparc::I4: OpKind = MCK_IntRegs; break;
    case Sparc::I5: OpKind = MCK_IntRegs; break;
    case Sparc::I6: OpKind = MCK_IntRegs; break;
    case Sparc::I7: OpKind = MCK_IntRegs; break;
    case Sparc::F0: OpKind = MCK_FPRegs; break;
    case Sparc::F1: OpKind = MCK_FPRegs; break;
    case Sparc::F2: OpKind = MCK_FPRegs; break;
    case Sparc::F3: OpKind = MCK_FPRegs; break;
    case Sparc::F4: OpKind = MCK_FPRegs; break;
    case Sparc::F5: OpKind = MCK_FPRegs; break;
    case Sparc::F6: OpKind = MCK_FPRegs; break;
    case Sparc::F7: OpKind = MCK_FPRegs; break;
    case Sparc::F8: OpKind = MCK_FPRegs; break;
    case Sparc::F9: OpKind = MCK_FPRegs; break;
    case Sparc::F10: OpKind = MCK_FPRegs; break;
    case Sparc::F11: OpKind = MCK_FPRegs; break;
    case Sparc::F12: OpKind = MCK_FPRegs; break;
    case Sparc::F13: OpKind = MCK_FPRegs; break;
    case Sparc::F14: OpKind = MCK_FPRegs; break;
    case Sparc::F15: OpKind = MCK_FPRegs; break;
    case Sparc::F16: OpKind = MCK_FPRegs; break;
    case Sparc::F17: OpKind = MCK_FPRegs; break;
    case Sparc::F18: OpKind = MCK_FPRegs; break;
    case Sparc::F19: OpKind = MCK_FPRegs; break;
    case Sparc::F20: OpKind = MCK_FPRegs; break;
    case Sparc::F21: OpKind = MCK_FPRegs; break;
    case Sparc::F22: OpKind = MCK_FPRegs; break;
    case Sparc::F23: OpKind = MCK_FPRegs; break;
    case Sparc::F24: OpKind = MCK_FPRegs; break;
    case Sparc::F25: OpKind = MCK_FPRegs; break;
    case Sparc::F26: OpKind = MCK_FPRegs; break;
    case Sparc::F27: OpKind = MCK_FPRegs; break;
    case Sparc::F28: OpKind = MCK_FPRegs; break;
    case Sparc::F29: OpKind = MCK_FPRegs; break;
    case Sparc::F30: OpKind = MCK_FPRegs; break;
    case Sparc::F31: OpKind = MCK_FPRegs; break;
    case Sparc::D0: OpKind = MCK_Reg5; break;
    case Sparc::D1: OpKind = MCK_Reg5; break;
    case Sparc::D2: OpKind = MCK_Reg5; break;
    case Sparc::D3: OpKind = MCK_Reg5; break;
    case Sparc::D4: OpKind = MCK_Reg5; break;
    case Sparc::D5: OpKind = MCK_Reg5; break;
    case Sparc::D6: OpKind = MCK_Reg5; break;
    case Sparc::D7: OpKind = MCK_Reg5; break;
    case Sparc::D8: OpKind = MCK_Reg5; break;
    case Sparc::D9: OpKind = MCK_Reg5; break;
    case Sparc::D10: OpKind = MCK_Reg5; break;
    case Sparc::D11: OpKind = MCK_Reg5; break;
    case Sparc::D12: OpKind = MCK_Reg5; break;
    case Sparc::D13: OpKind = MCK_Reg5; break;
    case Sparc::D14: OpKind = MCK_Reg5; break;
    case Sparc::D15: OpKind = MCK_Reg5; break;
    case Sparc::D16: OpKind = MCK_DFPRegs; break;
    case Sparc::D17: OpKind = MCK_DFPRegs; break;
    case Sparc::D18: OpKind = MCK_DFPRegs; break;
    case Sparc::D19: OpKind = MCK_DFPRegs; break;
    case Sparc::D20: OpKind = MCK_DFPRegs; break;
    case Sparc::D21: OpKind = MCK_DFPRegs; break;
    case Sparc::D22: OpKind = MCK_DFPRegs; break;
    case Sparc::D23: OpKind = MCK_DFPRegs; break;
    case Sparc::D24: OpKind = MCK_DFPRegs; break;
    case Sparc::D25: OpKind = MCK_DFPRegs; break;
    case Sparc::D26: OpKind = MCK_DFPRegs; break;
    case Sparc::D27: OpKind = MCK_DFPRegs; break;
    case Sparc::D28: OpKind = MCK_DFPRegs; break;
    case Sparc::D29: OpKind = MCK_DFPRegs; break;
    case Sparc::D30: OpKind = MCK_DFPRegs; break;
    case Sparc::D31: OpKind = MCK_DFPRegs; break;
    case Sparc::Q0: OpKind = MCK_Reg7; break;
    case Sparc::Q1: OpKind = MCK_Reg7; break;
    case Sparc::Q2: OpKind = MCK_Reg7; break;
    case Sparc::Q3: OpKind = MCK_Reg7; break;
    case Sparc::Q4: OpKind = MCK_Reg7; break;
    case Sparc::Q5: OpKind = MCK_Reg7; break;
    case Sparc::Q6: OpKind = MCK_Reg7; break;
    case Sparc::Q7: OpKind = MCK_Reg7; break;
    case Sparc::Q8: OpKind = MCK_QFPRegs; break;
    case Sparc::Q9: OpKind = MCK_QFPRegs; break;
    case Sparc::Q10: OpKind = MCK_QFPRegs; break;
    case Sparc::Q11: OpKind = MCK_QFPRegs; break;
    case Sparc::Q12: OpKind = MCK_QFPRegs; break;
    case Sparc::Q13: OpKind = MCK_QFPRegs; break;
    case Sparc::Q14: OpKind = MCK_QFPRegs; break;
    case Sparc::Q15: OpKind = MCK_QFPRegs; break;
    case Sparc::G0_G1: OpKind = MCK_IntPair; break;
    case Sparc::G2_G3: OpKind = MCK_IntPair; break;
    case Sparc::G4_G5: OpKind = MCK_IntPair; break;
    case Sparc::G6_G7: OpKind = MCK_IntPair; break;
    case Sparc::O0_O1: OpKind = MCK_IntPair; break;
    case Sparc::O2_O3: OpKind = MCK_IntPair; break;
    case Sparc::O4_O5: OpKind = MCK_IntPair; break;
    case Sparc::O6_O7: OpKind = MCK_IntPair; break;
    case Sparc::L0_L1: OpKind = MCK_IntPair; break;
    case Sparc::L2_L3: OpKind = MCK_IntPair; break;
    case Sparc::L4_L5: OpKind = MCK_IntPair; break;
    case Sparc::L6_L7: OpKind = MCK_IntPair; break;
    case Sparc::I0_I1: OpKind = MCK_IntPair; break;
    case Sparc::I2_I3: OpKind = MCK_IntPair; break;
    case Sparc::I4_I5: OpKind = MCK_IntPair; break;
    case Sparc::I6_I7: OpKind = MCK_IntPair; break;
    }
    return isSubclass(OpKind, Kind) ? MCTargetAsmParser::Match_Success :
                                      MCTargetAsmParser::Match_InvalidOperand;
  }

  return MCTargetAsmParser::Match_InvalidOperand;
}

uint64_t SparcAsmParser::
ComputeAvailableFeatures(const FeatureBitset& FB) const {
  uint64_t Features = 0;
  if ((FB[Sparc::FeatureV9]))
    Features |= Feature_HasV9;
  if ((FB[Sparc::FeatureVIS]))
    Features |= Feature_HasVIS;
  if ((FB[Sparc::FeatureVIS2]))
    Features |= Feature_HasVIS2;
  if ((FB[Sparc::FeatureVIS3]))
    Features |= Feature_HasVIS3;
  return Features;
}

static const char *const MnemonicTable =
    "\003add\005addcc\004addx\005addxc\006addxcc\007addxccc\talignaddr\nalig"
    "naddrl\003and\005andcc\004andn\006andncc\007array16\007array32\006array"
    "8\001b\002ba\003bcc\004bclr\003bcs\002be\003beq\002bg\003bge\004bgeu\003"
    "bgu\002bl\003ble\004bleu\003blu\005bmask\002bn\003bne\004bneg\003bnz\004"
    "bpos\005brgez\004brgz\005brlez\004brlz\004brnz\003brz\004bset\010bshuff"
    "le\004btog\004btst\003bvc\003bvs\002bz\004call\003cas\004casx\003clr\004"
    "clrb\004clrh\007cmask16\007cmask32\006cmask8\003cmp\003dec\005deccc\006"
    "edge16\007edge16l\010edge16ln\007edge16n\006edge32\007edge32l\010edge32"
    "ln\007edge32n\005edge8\006edge8l\007edge8ln\006edge8n\005fabsd\005fabsq"
    "\005fabss\005faddd\005faddq\005fadds\nfaligndata\004fand\010fandnot1\tf"
    "andnot1s\010fandnot2\tfandnot2s\005fands\002fb\003fba\003fbe\003fbg\004"
    "fbge\003fbl\004fble\004fblg\003fbn\004fbne\004fbnz\003fbo\003fbu\004fbu"
    "e\004fbug\005fbuge\004fbul\005fbule\003fbz\010fchksm16\005fcmpd\006fcmp"
    "ed\006fcmpeq\010fcmpeq16\010fcmpeq32\006fcmpes\010fcmpgt16\010fcmpgt32\010"
    "fcmple16\010fcmple32\010fcmpne16\010fcmpne32\005fcmpq\005fcmps\005fdivd"
    "\005fdivq\005fdivs\006fdmulq\005fdtoi\005fdtoq\005fdtos\005fdtox\007fex"
    "pand\006fhaddd\006fhadds\006fhsubd\006fhsubs\005fitod\005fitoq\005fitos"
    "\006flcmpd\006flcmps\005flush\006flushw\007fmean16\005fmovd\006fmovda\007"
    "fmovdcc\007fmovdcs\006fmovde\007fmovdeq\006fmovdg\007fmovdge\010fmovdge"
    "u\007fmovdgu\006fmovdl\007fmovdle\010fmovdleu\007fmovdlg\007fmovdlu\006"
    "fmovdn\007fmovdne\010fmovdneg\007fmovdnz\006fmovdo\010fmovdpos\006fmovd"
    "u\007fmovdue\007fmovdug\010fmovduge\007fmovdul\010fmovdule\007fmovdvc\007"
    "fmovdvs\006fmovdz\005fmovq\006fmovqa\007fmovqcc\007fmovqcs\006fmovqe\007"
    "fmovqeq\006fmovqg\007fmovqge\010fmovqgeu\007fmovqgu\006fmovql\007fmovql"
    "e\010fmovqleu\007fmovqlg\007fmovqlu\006fmovqn\007fmovqne\010fmovqneg\007"
    "fmovqnz\006fmovqo\010fmovqpos\006fmovqu\007fmovque\007fmovqug\010fmovqu"
    "ge\007fmovqul\010fmovqule\007fmovqvc\007fmovqvs\006fmovqz\tfmovrdgez\010"
    "fmovrdgz\tfmovrdlez\010fmovrdlz\010fmovrdnz\007fmovrdz\tfmovrqgez\010fm"
    "ovrqgz\tfmovrqlez\010fmovrqlz\010fmovrqnz\007fmovrqz\tfmovrsgez\010fmov"
    "rsgz\tfmovrslez\010fmovrslz\010fmovrsnz\007fmovrsz\005fmovs\006fmovsa\007"
    "fmovscc\007fmovscs\006fmovse\007fmovseq\006fmovsg\007fmovsge\010fmovsge"
    "u\007fmovsgu\006fmovsl\007fmovsle\010fmovsleu\007fmovslg\007fmovslu\006"
    "fmovsn\007fmovsne\010fmovsneg\007fmovsnz\006fmovso\010fmovspos\006fmovs"
    "u\007fmovsue\007fmovsug\010fmovsuge\007fmovsul\010fmovsule\007fmovsvc\007"
    "fmovsvs\006fmovsz\nfmul8sux16\nfmul8ulx16\010fmul8x16\nfmul8x16al\nfmul"
    "8x16au\005fmuld\013fmuld8sux16\013fmuld8ulx16\005fmulq\005fmuls\006fnad"
    "dd\006fnadds\005fnand\006fnands\005fnegd\005fnegq\005fnegs\007fnhaddd\007"
    "fnhadds\004fnor\005fnors\005fnot1\006fnot1s\005fnot2\006fnot2s\004fone\005"
    "fones\003for\007fornot1\010fornot1s\007fornot2\010fornot2s\004fors\007f"
    "pack16\007fpack32\010fpackfix\007fpadd16\010fpadd16s\007fpadd32\010fpad"
    "d32s\007fpadd64\007fpmerge\007fpsub16\010fpsub16S\007fpsub32\010fpsub32"
    "S\005fqtod\005fqtoi\005fqtos\005fqtox\007fslas16\007fslas32\006fsll16\006"
    "fsll32\006fsmuld\006fsqrtd\006fsqrtq\006fsqrts\006fsra16\006fsra32\005f"
    "src1\006fsrc1s\005fsrc2\006fsrc2s\006fsrl16\006fsrl32\005fstod\005fstoi"
    "\005fstoq\005fstox\005fsubd\005fsubq\005fsubs\005fxnor\006fxnors\004fxo"
    "r\005fxors\005fxtod\005fxtoq\005fxtos\005fzero\006fzeros\003inc\005incc"
    "c\003jmp\004jmpl\002ld\003lda\003ldd\004ldda\003ldq\004ldqa\004ldsb\005"
    "ldsba\004ldsh\005ldsha\006ldstub\007ldstuba\004ldsw\004ldub\005lduba\004"
    "lduh\005lduha\003ldx\005lzcnt\006membar\003mov\004mova\005movcc\005movc"
    "s\007movdtox\004move\005moveq\004movg\005movge\006movgeu\005movgu\004mo"
    "vl\005movle\006movleu\005movlg\005movlu\004movn\005movne\006movneg\005m"
    "ovnz\004movo\006movpos\007movrgez\006movrgz\007movrlez\006movrlz\006mov"
    "rnz\005movrz\010movstosw\010movstouw\004movu\005movue\005movug\006movug"
    "e\005movul\006movule\005movvc\005movvs\004movz\006mulscc\004mulx\003neg"
    "\003nop\003not\002or\004orcc\003orn\005orncc\005pdist\006pdistn\004popc"
    "\002rd\004rdpr\007restore\003ret\004retl\004rett\004save\004sdiv\006sdi"
    "vcc\005sdivx\003set\005sethi\010shutdown\004siam\005signx\003sll\004sll"
    "x\004smul\006smulcc\003sra\004srax\003srl\004srlx\002st\003sta\003stb\004"
    "stba\005stbar\003std\004stda\003sth\004stha\003stq\004stqa\003stx\003su"
    "b\005subcc\004subx\006subxcc\004swap\005swapa\001t\002ta\006taddcc\010t"
    "addcctv\003tcc\003tcs\002te\003teq\002tg\003tge\004tgeu\003tgu\002tl\003"
    "tle\004tleu\003tlu\002tn\003tne\004tneg\003tnz\004tpos\003tst\006tsubcc"
    "\010tsubcctv\003tvc\003tvs\002tz\004udiv\006udivcc\005udivx\004umul\006"
    "umulcc\007umulxhi\005unimp\002wr\004wrpr\005xmulx\007xmulxhi\004xnor\006"
    "xnorcc\003xor\005xorcc";

namespace {
  struct MatchEntry {
    uint16_t Mnemonic;
    uint16_t Opcode;
    uint16_t ConvertFn;
    uint8_t RequiredFeatures;
    uint16_t Classes[6];
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
  { 0 /* add */, Sparc::ADDrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_add, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 0 /* add */, Sparc::ADDri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_add, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 4 /* addcc */, Sparc::ADDCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_addcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 4 /* addcc */, Sparc::ADDCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_addcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 10 /* addx */, Sparc::ADDCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_addx, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 10 /* addx */, Sparc::ADDCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_addx, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 15 /* addxc */, Sparc::ADDXC, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_addxc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 21 /* addxcc */, Sparc::ADDErr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_addxcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 21 /* addxcc */, Sparc::ADDEri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_addxcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 28 /* addxccc */, Sparc::ADDXCCC, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_addxccc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 36 /* alignaddr */, Sparc::ALIGNADDR, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_alignaddr, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 46 /* alignaddrl */, Sparc::ALIGNADDRL, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_alignaddrl, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 57 /* and */, Sparc::ANDrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_and, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 57 /* and */, Sparc::ANDri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_and, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 61 /* andcc */, Sparc::ANDCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_andcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 61 /* andcc */, Sparc::ANDCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_andcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 67 /* andn */, Sparc::ANDNrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_andn, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 67 /* andn */, Sparc::ANDNri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_andn, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 72 /* andncc */, Sparc::ANDNCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_andncc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 72 /* andncc */, Sparc::ANDNCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_andncc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 79 /* array16 */, Sparc::ARRAY16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_array16, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 87 /* array32 */, Sparc::ARRAY32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_array32, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 95 /* array8 */, Sparc::ARRAY8, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_array8, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 102 /* b */, Sparc::BCOND, Convert__Imm1_1__imm_95_8, 0, { MCK_b, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICC, Convert__Imm1_2__imm_95_8, Feature_HasV9, { MCK_b, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCC, Convert__Imm1_2__imm_95_8, 0, { MCK_b, MCK__PCT_xcc, MCK_Imm }, },
  { 102 /* b */, Sparc::BCONDA, Convert__Imm1_2__imm_95_8, 0, { MCK_b, MCK_a, MCK_Imm }, },
  { 102 /* b */, Sparc::BCOND, Convert__Imm1_2__Imm1_1, 0, { MCK_b, MCK_Imm, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICCA, Convert__Imm1_3__imm_95_8, Feature_HasV9, { MCK_b, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_8, 0, { MCK_b, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_8, Feature_HasV9, { MCK_b, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_8, 0, { MCK_b, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICC, Convert__Imm1_3__imm_95_8, Feature_HasV9, { MCK_b, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCC, Convert__Imm1_3__imm_95_8, 0, { MCK_b, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICC, Convert__Imm1_3__Imm1_1, Feature_HasV9, { MCK_b, MCK_Imm, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCC, Convert__Imm1_3__Imm1_1, 0, { MCK_b, MCK_Imm, MCK__PCT_xcc, MCK_Imm }, },
  { 102 /* b */, Sparc::BCONDA, Convert__Imm1_3__Imm1_1, 0, { MCK_b, MCK_Imm, MCK_a, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_8, Feature_HasV9, { MCK_b, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_8, 0, { MCK_b, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICCA, Convert__Imm1_4__imm_95_8, Feature_HasV9, { MCK_b, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_8, 0, { MCK_b, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICCA, Convert__Imm1_4__Imm1_1, Feature_HasV9, { MCK_b, MCK_Imm, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCCA, Convert__Imm1_4__Imm1_1, 0, { MCK_b, MCK_Imm, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICCNT, Convert__Imm1_4__Imm1_1, Feature_HasV9, { MCK_b, MCK_Imm, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCCNT, Convert__Imm1_4__Imm1_1, 0, { MCK_b, MCK_Imm, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPICCANT, Convert__Imm1_5__Imm1_1, Feature_HasV9, { MCK_b, MCK_Imm, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 102 /* b */, Sparc::BPXCCANT, Convert__Imm1_5__Imm1_1, 0, { MCK_b, MCK_Imm, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BA, Convert__Imm1_1, 0, { MCK_ba, MCK_Imm }, },
  { 104 /* ba */, Sparc::BCOND, Convert__Imm1_1__imm_95_8, 0, { MCK_ba, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPICC, Convert__Imm1_2__imm_95_8, Feature_HasV9, { MCK_ba, MCK__PCT_icc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPXCC, Convert__Imm1_2__imm_95_8, 0, { MCK_ba, MCK__PCT_xcc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BCONDA, Convert__Imm1_2__imm_95_8, 0, { MCK_ba, MCK_a, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPICCA, Convert__Imm1_3__imm_95_8, Feature_HasV9, { MCK_ba, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_8, 0, { MCK_ba, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_8, Feature_HasV9, { MCK_ba, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_8, 0, { MCK_ba, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPICC, Convert__Imm1_3__imm_95_8, Feature_HasV9, { MCK_ba, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPXCC, Convert__Imm1_3__imm_95_8, 0, { MCK_ba, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_8, Feature_HasV9, { MCK_ba, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_8, 0, { MCK_ba, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPICCA, Convert__Imm1_4__imm_95_8, Feature_HasV9, { MCK_ba, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 104 /* ba */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_8, 0, { MCK_ba, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BCOND, Convert__Imm1_1__imm_95_13, 0, { MCK_bcc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPICC, Convert__Imm1_2__imm_95_13, Feature_HasV9, { MCK_bcc, MCK__PCT_icc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPXCC, Convert__Imm1_2__imm_95_13, 0, { MCK_bcc, MCK__PCT_xcc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BCONDA, Convert__Imm1_2__imm_95_13, 0, { MCK_bcc, MCK_a, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPICCA, Convert__Imm1_3__imm_95_13, Feature_HasV9, { MCK_bcc, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_13, 0, { MCK_bcc, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_13, Feature_HasV9, { MCK_bcc, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_13, 0, { MCK_bcc, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPICC, Convert__Imm1_3__imm_95_13, Feature_HasV9, { MCK_bcc, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPXCC, Convert__Imm1_3__imm_95_13, 0, { MCK_bcc, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_13, Feature_HasV9, { MCK_bcc, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_13, 0, { MCK_bcc, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPICCA, Convert__Imm1_4__imm_95_13, Feature_HasV9, { MCK_bcc, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 107 /* bcc */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_13, 0, { MCK_bcc, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 111 /* bclr */, Sparc::ANDNrr, Convert__Reg1_2__Reg1_2__Reg1_1, 0, { MCK_bclr, MCK_IntRegs, MCK_IntRegs }, },
  { 111 /* bclr */, Sparc::ANDNri, Convert__Reg1_2__Reg1_2__Imm1_1, 0, { MCK_bclr, MCK_Imm, MCK_IntRegs }, },
  { 116 /* bcs */, Sparc::BCOND, Convert__Imm1_1__imm_95_5, 0, { MCK_bcs, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPICC, Convert__Imm1_2__imm_95_5, Feature_HasV9, { MCK_bcs, MCK__PCT_icc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPXCC, Convert__Imm1_2__imm_95_5, 0, { MCK_bcs, MCK__PCT_xcc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BCONDA, Convert__Imm1_2__imm_95_5, 0, { MCK_bcs, MCK_a, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPICCA, Convert__Imm1_3__imm_95_5, Feature_HasV9, { MCK_bcs, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_5, 0, { MCK_bcs, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_5, Feature_HasV9, { MCK_bcs, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_5, 0, { MCK_bcs, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPICC, Convert__Imm1_3__imm_95_5, Feature_HasV9, { MCK_bcs, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPXCC, Convert__Imm1_3__imm_95_5, 0, { MCK_bcs, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_5, Feature_HasV9, { MCK_bcs, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_5, 0, { MCK_bcs, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPICCA, Convert__Imm1_4__imm_95_5, Feature_HasV9, { MCK_bcs, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 116 /* bcs */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_5, 0, { MCK_bcs, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 120 /* be */, Sparc::BCOND, Convert__Imm1_1__imm_95_1, 0, { MCK_be, MCK_Imm }, },
  { 120 /* be */, Sparc::BPICC, Convert__Imm1_2__imm_95_1, Feature_HasV9, { MCK_be, MCK__PCT_icc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPXCC, Convert__Imm1_2__imm_95_1, 0, { MCK_be, MCK__PCT_xcc, MCK_Imm }, },
  { 120 /* be */, Sparc::BCONDA, Convert__Imm1_2__imm_95_1, 0, { MCK_be, MCK_a, MCK_Imm }, },
  { 120 /* be */, Sparc::BPICCA, Convert__Imm1_3__imm_95_1, Feature_HasV9, { MCK_be, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_1, 0, { MCK_be, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_1, Feature_HasV9, { MCK_be, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_1, 0, { MCK_be, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPICC, Convert__Imm1_3__imm_95_1, Feature_HasV9, { MCK_be, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPXCC, Convert__Imm1_3__imm_95_1, 0, { MCK_be, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_1, Feature_HasV9, { MCK_be, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_1, 0, { MCK_be, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPICCA, Convert__Imm1_4__imm_95_1, Feature_HasV9, { MCK_be, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 120 /* be */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_1, 0, { MCK_be, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BCOND, Convert__Imm1_1__imm_95_1, 0, { MCK_beq, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPICC, Convert__Imm1_2__imm_95_1, Feature_HasV9, { MCK_beq, MCK__PCT_icc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPXCC, Convert__Imm1_2__imm_95_1, 0, { MCK_beq, MCK__PCT_xcc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BCONDA, Convert__Imm1_2__imm_95_1, 0, { MCK_beq, MCK_a, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPICCA, Convert__Imm1_3__imm_95_1, Feature_HasV9, { MCK_beq, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_1, 0, { MCK_beq, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_1, Feature_HasV9, { MCK_beq, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_1, 0, { MCK_beq, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPICC, Convert__Imm1_3__imm_95_1, Feature_HasV9, { MCK_beq, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPXCC, Convert__Imm1_3__imm_95_1, 0, { MCK_beq, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_1, Feature_HasV9, { MCK_beq, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_1, 0, { MCK_beq, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPICCA, Convert__Imm1_4__imm_95_1, Feature_HasV9, { MCK_beq, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 123 /* beq */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_1, 0, { MCK_beq, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BCOND, Convert__Imm1_1__imm_95_10, 0, { MCK_bg, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPICC, Convert__Imm1_2__imm_95_10, Feature_HasV9, { MCK_bg, MCK__PCT_icc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPXCC, Convert__Imm1_2__imm_95_10, 0, { MCK_bg, MCK__PCT_xcc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BCONDA, Convert__Imm1_2__imm_95_10, 0, { MCK_bg, MCK_a, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPICCA, Convert__Imm1_3__imm_95_10, Feature_HasV9, { MCK_bg, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_10, 0, { MCK_bg, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_10, Feature_HasV9, { MCK_bg, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_10, 0, { MCK_bg, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPICC, Convert__Imm1_3__imm_95_10, Feature_HasV9, { MCK_bg, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPXCC, Convert__Imm1_3__imm_95_10, 0, { MCK_bg, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_10, Feature_HasV9, { MCK_bg, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_10, 0, { MCK_bg, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPICCA, Convert__Imm1_4__imm_95_10, Feature_HasV9, { MCK_bg, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 127 /* bg */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_10, 0, { MCK_bg, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BCOND, Convert__Imm1_1__imm_95_11, 0, { MCK_bge, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPICC, Convert__Imm1_2__imm_95_11, Feature_HasV9, { MCK_bge, MCK__PCT_icc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPXCC, Convert__Imm1_2__imm_95_11, 0, { MCK_bge, MCK__PCT_xcc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BCONDA, Convert__Imm1_2__imm_95_11, 0, { MCK_bge, MCK_a, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPICCA, Convert__Imm1_3__imm_95_11, Feature_HasV9, { MCK_bge, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_11, 0, { MCK_bge, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_11, Feature_HasV9, { MCK_bge, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_11, 0, { MCK_bge, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPICC, Convert__Imm1_3__imm_95_11, Feature_HasV9, { MCK_bge, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPXCC, Convert__Imm1_3__imm_95_11, 0, { MCK_bge, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_11, Feature_HasV9, { MCK_bge, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_11, 0, { MCK_bge, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPICCA, Convert__Imm1_4__imm_95_11, Feature_HasV9, { MCK_bge, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 130 /* bge */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_11, 0, { MCK_bge, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BCOND, Convert__Imm1_1__imm_95_13, 0, { MCK_bgeu, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPICC, Convert__Imm1_2__imm_95_13, Feature_HasV9, { MCK_bgeu, MCK__PCT_icc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPXCC, Convert__Imm1_2__imm_95_13, 0, { MCK_bgeu, MCK__PCT_xcc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BCONDA, Convert__Imm1_2__imm_95_13, 0, { MCK_bgeu, MCK_a, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPICCA, Convert__Imm1_3__imm_95_13, Feature_HasV9, { MCK_bgeu, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_13, 0, { MCK_bgeu, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_13, Feature_HasV9, { MCK_bgeu, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_13, 0, { MCK_bgeu, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPICC, Convert__Imm1_3__imm_95_13, Feature_HasV9, { MCK_bgeu, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPXCC, Convert__Imm1_3__imm_95_13, 0, { MCK_bgeu, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_13, Feature_HasV9, { MCK_bgeu, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_13, 0, { MCK_bgeu, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPICCA, Convert__Imm1_4__imm_95_13, Feature_HasV9, { MCK_bgeu, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 134 /* bgeu */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_13, 0, { MCK_bgeu, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BCOND, Convert__Imm1_1__imm_95_12, 0, { MCK_bgu, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPICC, Convert__Imm1_2__imm_95_12, Feature_HasV9, { MCK_bgu, MCK__PCT_icc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPXCC, Convert__Imm1_2__imm_95_12, 0, { MCK_bgu, MCK__PCT_xcc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BCONDA, Convert__Imm1_2__imm_95_12, 0, { MCK_bgu, MCK_a, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPICCA, Convert__Imm1_3__imm_95_12, Feature_HasV9, { MCK_bgu, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_12, 0, { MCK_bgu, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_12, Feature_HasV9, { MCK_bgu, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_12, 0, { MCK_bgu, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPICC, Convert__Imm1_3__imm_95_12, Feature_HasV9, { MCK_bgu, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPXCC, Convert__Imm1_3__imm_95_12, 0, { MCK_bgu, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_12, Feature_HasV9, { MCK_bgu, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_12, 0, { MCK_bgu, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPICCA, Convert__Imm1_4__imm_95_12, Feature_HasV9, { MCK_bgu, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 139 /* bgu */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_12, 0, { MCK_bgu, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BCOND, Convert__Imm1_1__imm_95_3, 0, { MCK_bl, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPICC, Convert__Imm1_2__imm_95_3, Feature_HasV9, { MCK_bl, MCK__PCT_icc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPXCC, Convert__Imm1_2__imm_95_3, 0, { MCK_bl, MCK__PCT_xcc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BCONDA, Convert__Imm1_2__imm_95_3, 0, { MCK_bl, MCK_a, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPICCA, Convert__Imm1_3__imm_95_3, Feature_HasV9, { MCK_bl, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_3, 0, { MCK_bl, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_3, Feature_HasV9, { MCK_bl, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_3, 0, { MCK_bl, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPICC, Convert__Imm1_3__imm_95_3, Feature_HasV9, { MCK_bl, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPXCC, Convert__Imm1_3__imm_95_3, 0, { MCK_bl, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_3, Feature_HasV9, { MCK_bl, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_3, 0, { MCK_bl, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPICCA, Convert__Imm1_4__imm_95_3, Feature_HasV9, { MCK_bl, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 143 /* bl */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_3, 0, { MCK_bl, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BCOND, Convert__Imm1_1__imm_95_2, 0, { MCK_ble, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPICC, Convert__Imm1_2__imm_95_2, Feature_HasV9, { MCK_ble, MCK__PCT_icc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPXCC, Convert__Imm1_2__imm_95_2, 0, { MCK_ble, MCK__PCT_xcc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BCONDA, Convert__Imm1_2__imm_95_2, 0, { MCK_ble, MCK_a, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPICCA, Convert__Imm1_3__imm_95_2, Feature_HasV9, { MCK_ble, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_2, 0, { MCK_ble, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_2, Feature_HasV9, { MCK_ble, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_2, 0, { MCK_ble, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPICC, Convert__Imm1_3__imm_95_2, Feature_HasV9, { MCK_ble, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPXCC, Convert__Imm1_3__imm_95_2, 0, { MCK_ble, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_2, Feature_HasV9, { MCK_ble, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_2, 0, { MCK_ble, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPICCA, Convert__Imm1_4__imm_95_2, Feature_HasV9, { MCK_ble, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 146 /* ble */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_2, 0, { MCK_ble, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BCOND, Convert__Imm1_1__imm_95_4, 0, { MCK_bleu, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPICC, Convert__Imm1_2__imm_95_4, Feature_HasV9, { MCK_bleu, MCK__PCT_icc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPXCC, Convert__Imm1_2__imm_95_4, 0, { MCK_bleu, MCK__PCT_xcc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BCONDA, Convert__Imm1_2__imm_95_4, 0, { MCK_bleu, MCK_a, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPICCA, Convert__Imm1_3__imm_95_4, Feature_HasV9, { MCK_bleu, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_4, 0, { MCK_bleu, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_4, Feature_HasV9, { MCK_bleu, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_4, 0, { MCK_bleu, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPICC, Convert__Imm1_3__imm_95_4, Feature_HasV9, { MCK_bleu, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPXCC, Convert__Imm1_3__imm_95_4, 0, { MCK_bleu, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_4, Feature_HasV9, { MCK_bleu, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_4, 0, { MCK_bleu, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPICCA, Convert__Imm1_4__imm_95_4, Feature_HasV9, { MCK_bleu, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 150 /* bleu */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_4, 0, { MCK_bleu, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BCOND, Convert__Imm1_1__imm_95_5, 0, { MCK_blu, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPICC, Convert__Imm1_2__imm_95_5, Feature_HasV9, { MCK_blu, MCK__PCT_icc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPXCC, Convert__Imm1_2__imm_95_5, 0, { MCK_blu, MCK__PCT_xcc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BCONDA, Convert__Imm1_2__imm_95_5, 0, { MCK_blu, MCK_a, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPICCA, Convert__Imm1_3__imm_95_5, Feature_HasV9, { MCK_blu, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_5, 0, { MCK_blu, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_5, Feature_HasV9, { MCK_blu, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_5, 0, { MCK_blu, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPICC, Convert__Imm1_3__imm_95_5, Feature_HasV9, { MCK_blu, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPXCC, Convert__Imm1_3__imm_95_5, 0, { MCK_blu, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_5, Feature_HasV9, { MCK_blu, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_5, 0, { MCK_blu, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPICCA, Convert__Imm1_4__imm_95_5, Feature_HasV9, { MCK_blu, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 155 /* blu */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_5, 0, { MCK_blu, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 159 /* bmask */, Sparc::BMASK, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS2, { MCK_bmask, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 165 /* bn */, Sparc::BCOND, Convert__Imm1_1__imm_95_0, 0, { MCK_bn, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPICC, Convert__Imm1_2__imm_95_0, Feature_HasV9, { MCK_bn, MCK__PCT_icc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPXCC, Convert__Imm1_2__imm_95_0, 0, { MCK_bn, MCK__PCT_xcc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BCONDA, Convert__Imm1_2__imm_95_0, 0, { MCK_bn, MCK_a, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPICCA, Convert__Imm1_3__imm_95_0, Feature_HasV9, { MCK_bn, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_0, 0, { MCK_bn, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_0, Feature_HasV9, { MCK_bn, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_0, 0, { MCK_bn, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPICC, Convert__Imm1_3__imm_95_0, Feature_HasV9, { MCK_bn, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPXCC, Convert__Imm1_3__imm_95_0, 0, { MCK_bn, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_0, Feature_HasV9, { MCK_bn, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_0, 0, { MCK_bn, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPICCA, Convert__Imm1_4__imm_95_0, Feature_HasV9, { MCK_bn, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 165 /* bn */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_0, 0, { MCK_bn, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BCOND, Convert__Imm1_1__imm_95_9, 0, { MCK_bne, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPICC, Convert__Imm1_2__imm_95_9, Feature_HasV9, { MCK_bne, MCK__PCT_icc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPXCC, Convert__Imm1_2__imm_95_9, 0, { MCK_bne, MCK__PCT_xcc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BCONDA, Convert__Imm1_2__imm_95_9, 0, { MCK_bne, MCK_a, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPICCA, Convert__Imm1_3__imm_95_9, Feature_HasV9, { MCK_bne, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_9, 0, { MCK_bne, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_9, Feature_HasV9, { MCK_bne, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_9, 0, { MCK_bne, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPICC, Convert__Imm1_3__imm_95_9, Feature_HasV9, { MCK_bne, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPXCC, Convert__Imm1_3__imm_95_9, 0, { MCK_bne, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_9, Feature_HasV9, { MCK_bne, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_9, 0, { MCK_bne, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPICCA, Convert__Imm1_4__imm_95_9, Feature_HasV9, { MCK_bne, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 168 /* bne */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_9, 0, { MCK_bne, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BCOND, Convert__Imm1_1__imm_95_6, 0, { MCK_bneg, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPICC, Convert__Imm1_2__imm_95_6, Feature_HasV9, { MCK_bneg, MCK__PCT_icc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPXCC, Convert__Imm1_2__imm_95_6, 0, { MCK_bneg, MCK__PCT_xcc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BCONDA, Convert__Imm1_2__imm_95_6, 0, { MCK_bneg, MCK_a, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPICCA, Convert__Imm1_3__imm_95_6, Feature_HasV9, { MCK_bneg, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_6, 0, { MCK_bneg, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_6, Feature_HasV9, { MCK_bneg, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_6, 0, { MCK_bneg, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPICC, Convert__Imm1_3__imm_95_6, Feature_HasV9, { MCK_bneg, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPXCC, Convert__Imm1_3__imm_95_6, 0, { MCK_bneg, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_6, Feature_HasV9, { MCK_bneg, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_6, 0, { MCK_bneg, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPICCA, Convert__Imm1_4__imm_95_6, Feature_HasV9, { MCK_bneg, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 172 /* bneg */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_6, 0, { MCK_bneg, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BCOND, Convert__Imm1_1__imm_95_9, 0, { MCK_bnz, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPICC, Convert__Imm1_2__imm_95_9, Feature_HasV9, { MCK_bnz, MCK__PCT_icc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPXCC, Convert__Imm1_2__imm_95_9, 0, { MCK_bnz, MCK__PCT_xcc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BCONDA, Convert__Imm1_2__imm_95_9, 0, { MCK_bnz, MCK_a, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPICCA, Convert__Imm1_3__imm_95_9, Feature_HasV9, { MCK_bnz, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_9, 0, { MCK_bnz, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_9, Feature_HasV9, { MCK_bnz, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_9, 0, { MCK_bnz, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPICC, Convert__Imm1_3__imm_95_9, Feature_HasV9, { MCK_bnz, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPXCC, Convert__Imm1_3__imm_95_9, 0, { MCK_bnz, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_9, Feature_HasV9, { MCK_bnz, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_9, 0, { MCK_bnz, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPICCA, Convert__Imm1_4__imm_95_9, Feature_HasV9, { MCK_bnz, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 177 /* bnz */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_9, 0, { MCK_bnz, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BCOND, Convert__Imm1_1__imm_95_14, 0, { MCK_bpos, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPICC, Convert__Imm1_2__imm_95_14, Feature_HasV9, { MCK_bpos, MCK__PCT_icc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPXCC, Convert__Imm1_2__imm_95_14, 0, { MCK_bpos, MCK__PCT_xcc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BCONDA, Convert__Imm1_2__imm_95_14, 0, { MCK_bpos, MCK_a, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPICCA, Convert__Imm1_3__imm_95_14, Feature_HasV9, { MCK_bpos, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_14, 0, { MCK_bpos, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_14, Feature_HasV9, { MCK_bpos, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_14, 0, { MCK_bpos, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPICC, Convert__Imm1_3__imm_95_14, Feature_HasV9, { MCK_bpos, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPXCC, Convert__Imm1_3__imm_95_14, 0, { MCK_bpos, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_14, Feature_HasV9, { MCK_bpos, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_14, 0, { MCK_bpos, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPICCA, Convert__Imm1_4__imm_95_14, Feature_HasV9, { MCK_bpos, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 181 /* bpos */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_14, 0, { MCK_bpos, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 186 /* brgez */, Sparc::BPGEZnapt, Convert__Reg1_1__Imm1_2, 0, { MCK_brgez, MCK_IntRegs, MCK_Imm }, },
  { 186 /* brgez */, Sparc::BPGEZapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brgez, MCK_a, MCK_IntRegs, MCK_Imm }, },
  { 186 /* brgez */, Sparc::BPGEZnapn, Convert__Reg1_2__Imm1_3, 0, { MCK_brgez, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 186 /* brgez */, Sparc::BPGEZnapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brgez, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 186 /* brgez */, Sparc::BPGEZapn, Convert__Reg1_3__Imm1_4, 0, { MCK_brgez, MCK_a, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 186 /* brgez */, Sparc::BPGEZapt, Convert__Reg1_3__Imm1_4, 0, { MCK_brgez, MCK_a, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 192 /* brgz */, Sparc::BPGZnapt, Convert__Reg1_1__Imm1_2, 0, { MCK_brgz, MCK_IntRegs, MCK_Imm }, },
  { 192 /* brgz */, Sparc::BPGZapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brgz, MCK_a, MCK_IntRegs, MCK_Imm }, },
  { 192 /* brgz */, Sparc::BPGZnapn, Convert__Reg1_2__Imm1_3, 0, { MCK_brgz, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 192 /* brgz */, Sparc::BPGZnapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brgz, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 192 /* brgz */, Sparc::BPGZapn, Convert__Reg1_3__Imm1_4, 0, { MCK_brgz, MCK_a, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 192 /* brgz */, Sparc::BPGZapt, Convert__Reg1_3__Imm1_4, 0, { MCK_brgz, MCK_a, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 197 /* brlez */, Sparc::BPLEZnapt, Convert__Reg1_1__Imm1_2, 0, { MCK_brlez, MCK_IntRegs, MCK_Imm }, },
  { 197 /* brlez */, Sparc::BPLEZapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brlez, MCK_a, MCK_IntRegs, MCK_Imm }, },
  { 197 /* brlez */, Sparc::BPLEZnapn, Convert__Reg1_2__Imm1_3, 0, { MCK_brlez, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 197 /* brlez */, Sparc::BPLEZnapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brlez, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 197 /* brlez */, Sparc::BPLEZapn, Convert__Reg1_3__Imm1_4, 0, { MCK_brlez, MCK_a, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 197 /* brlez */, Sparc::BPLEZapt, Convert__Reg1_3__Imm1_4, 0, { MCK_brlez, MCK_a, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 203 /* brlz */, Sparc::BPLZnapt, Convert__Reg1_1__Imm1_2, 0, { MCK_brlz, MCK_IntRegs, MCK_Imm }, },
  { 203 /* brlz */, Sparc::BPLZapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brlz, MCK_a, MCK_IntRegs, MCK_Imm }, },
  { 203 /* brlz */, Sparc::BPLZnapn, Convert__Reg1_2__Imm1_3, 0, { MCK_brlz, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 203 /* brlz */, Sparc::BPLZnapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brlz, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 203 /* brlz */, Sparc::BPLZapn, Convert__Reg1_3__Imm1_4, 0, { MCK_brlz, MCK_a, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 203 /* brlz */, Sparc::BPLZapt, Convert__Reg1_3__Imm1_4, 0, { MCK_brlz, MCK_a, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 208 /* brnz */, Sparc::BPNZnapt, Convert__Reg1_1__Imm1_2, 0, { MCK_brnz, MCK_IntRegs, MCK_Imm }, },
  { 208 /* brnz */, Sparc::BPNZapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brnz, MCK_a, MCK_IntRegs, MCK_Imm }, },
  { 208 /* brnz */, Sparc::BPNZnapn, Convert__Reg1_2__Imm1_3, 0, { MCK_brnz, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 208 /* brnz */, Sparc::BPNZnapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brnz, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 208 /* brnz */, Sparc::BPNZapn, Convert__Reg1_3__Imm1_4, 0, { MCK_brnz, MCK_a, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 208 /* brnz */, Sparc::BPNZapt, Convert__Reg1_3__Imm1_4, 0, { MCK_brnz, MCK_a, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 213 /* brz */, Sparc::BPZnapt, Convert__Reg1_1__Imm1_2, 0, { MCK_brz, MCK_IntRegs, MCK_Imm }, },
  { 213 /* brz */, Sparc::BPZapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brz, MCK_a, MCK_IntRegs, MCK_Imm }, },
  { 213 /* brz */, Sparc::BPZnapn, Convert__Reg1_2__Imm1_3, 0, { MCK_brz, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 213 /* brz */, Sparc::BPZnapt, Convert__Reg1_2__Imm1_3, 0, { MCK_brz, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 213 /* brz */, Sparc::BPZapn, Convert__Reg1_3__Imm1_4, 0, { MCK_brz, MCK_a, MCK_pn, MCK_IntRegs, MCK_Imm }, },
  { 213 /* brz */, Sparc::BPZapt, Convert__Reg1_3__Imm1_4, 0, { MCK_brz, MCK_a, MCK_pt, MCK_IntRegs, MCK_Imm }, },
  { 217 /* bset */, Sparc::ORrr, Convert__Reg1_2__Reg1_2__Reg1_1, 0, { MCK_bset, MCK_IntRegs, MCK_IntRegs }, },
  { 217 /* bset */, Sparc::ORri, Convert__Reg1_2__Reg1_2__Imm1_1, 0, { MCK_bset, MCK_Imm, MCK_IntRegs }, },
  { 222 /* bshuffle */, Sparc::BSHUFFLE, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS2, { MCK_bshuffle, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 231 /* btog */, Sparc::XORrr, Convert__Reg1_2__Reg1_2__Reg1_1, 0, { MCK_btog, MCK_IntRegs, MCK_IntRegs }, },
  { 231 /* btog */, Sparc::XORri, Convert__Reg1_2__Reg1_2__Imm1_1, 0, { MCK_btog, MCK_Imm, MCK_IntRegs }, },
  { 236 /* btst */, Sparc::ANDCCrr, Convert__regG0__Reg1_2__Reg1_1, 0, { MCK_btst, MCK_IntRegs, MCK_IntRegs }, },
  { 236 /* btst */, Sparc::ANDCCri, Convert__regG0__Reg1_2__Imm1_1, 0, { MCK_btst, MCK_Imm, MCK_IntRegs }, },
  { 241 /* bvc */, Sparc::BCOND, Convert__Imm1_1__imm_95_15, 0, { MCK_bvc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPICC, Convert__Imm1_2__imm_95_15, Feature_HasV9, { MCK_bvc, MCK__PCT_icc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPXCC, Convert__Imm1_2__imm_95_15, 0, { MCK_bvc, MCK__PCT_xcc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BCONDA, Convert__Imm1_2__imm_95_15, 0, { MCK_bvc, MCK_a, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPICCA, Convert__Imm1_3__imm_95_15, Feature_HasV9, { MCK_bvc, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_15, 0, { MCK_bvc, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_15, Feature_HasV9, { MCK_bvc, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_15, 0, { MCK_bvc, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPICC, Convert__Imm1_3__imm_95_15, Feature_HasV9, { MCK_bvc, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPXCC, Convert__Imm1_3__imm_95_15, 0, { MCK_bvc, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_15, Feature_HasV9, { MCK_bvc, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_15, 0, { MCK_bvc, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPICCA, Convert__Imm1_4__imm_95_15, Feature_HasV9, { MCK_bvc, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 241 /* bvc */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_15, 0, { MCK_bvc, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BCOND, Convert__Imm1_1__imm_95_7, 0, { MCK_bvs, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPICC, Convert__Imm1_2__imm_95_7, Feature_HasV9, { MCK_bvs, MCK__PCT_icc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPXCC, Convert__Imm1_2__imm_95_7, 0, { MCK_bvs, MCK__PCT_xcc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BCONDA, Convert__Imm1_2__imm_95_7, 0, { MCK_bvs, MCK_a, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPICCA, Convert__Imm1_3__imm_95_7, Feature_HasV9, { MCK_bvs, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_7, 0, { MCK_bvs, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_7, Feature_HasV9, { MCK_bvs, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_7, 0, { MCK_bvs, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPICC, Convert__Imm1_3__imm_95_7, Feature_HasV9, { MCK_bvs, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPXCC, Convert__Imm1_3__imm_95_7, 0, { MCK_bvs, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_7, Feature_HasV9, { MCK_bvs, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_7, 0, { MCK_bvs, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPICCA, Convert__Imm1_4__imm_95_7, Feature_HasV9, { MCK_bvs, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 245 /* bvs */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_7, 0, { MCK_bvs, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BCOND, Convert__Imm1_1__imm_95_1, 0, { MCK_bz, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPICC, Convert__Imm1_2__imm_95_1, Feature_HasV9, { MCK_bz, MCK__PCT_icc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPXCC, Convert__Imm1_2__imm_95_1, 0, { MCK_bz, MCK__PCT_xcc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BCONDA, Convert__Imm1_2__imm_95_1, 0, { MCK_bz, MCK_a, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPICCA, Convert__Imm1_3__imm_95_1, Feature_HasV9, { MCK_bz, MCK_a, MCK__PCT_icc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPXCCA, Convert__Imm1_3__imm_95_1, 0, { MCK_bz, MCK_a, MCK__PCT_xcc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPICCNT, Convert__Imm1_3__imm_95_1, Feature_HasV9, { MCK_bz, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPXCCNT, Convert__Imm1_3__imm_95_1, 0, { MCK_bz, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPICC, Convert__Imm1_3__imm_95_1, Feature_HasV9, { MCK_bz, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPXCC, Convert__Imm1_3__imm_95_1, 0, { MCK_bz, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPICCANT, Convert__Imm1_4__imm_95_1, Feature_HasV9, { MCK_bz, MCK_a, MCK_pn, MCK__PCT_icc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPXCCANT, Convert__Imm1_4__imm_95_1, 0, { MCK_bz, MCK_a, MCK_pn, MCK__PCT_xcc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPICCA, Convert__Imm1_4__imm_95_1, Feature_HasV9, { MCK_bz, MCK_a, MCK_pt, MCK__PCT_icc, MCK_Imm }, },
  { 249 /* bz */, Sparc::BPXCCA, Convert__Imm1_4__imm_95_1, 0, { MCK_bz, MCK_a, MCK_pt, MCK__PCT_xcc, MCK_Imm }, },
  { 252 /* call */, Sparc::CALL, Convert__Imm1_1, 0, { MCK_call, MCK_Imm }, },
  { 252 /* call */, Sparc::JMPLri, Convert__regO7__MEMri2_1, 0, { MCK_call, MCK_MEMri }, },
  { 252 /* call */, Sparc::JMPLrr, Convert__regO7__MEMrr2_1, 0, { MCK_call, MCK_MEMrr }, },
  { 257 /* cas */, Sparc::CASrr, Convert__Reg1_5__Reg1_2__Reg1_4__Tie0, Feature_HasV9, { MCK_cas, MCK__91_, MCK_IntRegs, MCK__93_, MCK_IntRegs, MCK_IntRegs }, },
  { 261 /* casx */, Sparc::CASXrr, Convert__Reg1_5__Reg1_2__Reg1_4__Tie0, 0, { MCK_casx, MCK__91_, MCK_IntRegs, MCK__93_, MCK_IntRegs, MCK_IntRegs }, },
  { 266 /* clr */, Sparc::ORrr, Convert__Reg1_1__regG0__regG0, 0, { MCK_clr, MCK_IntRegs }, },
  { 266 /* clr */, Sparc::STri, Convert__MEMri2_2__regG0, 0, { MCK_clr, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 266 /* clr */, Sparc::STrr, Convert__MEMrr2_2__regG0, 0, { MCK_clr, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 270 /* clrb */, Sparc::STBri, Convert__MEMri2_2__regG0, 0, { MCK_clrb, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 270 /* clrb */, Sparc::STBrr, Convert__MEMrr2_2__regG0, 0, { MCK_clrb, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 275 /* clrh */, Sparc::STHri, Convert__MEMri2_2__regG0, 0, { MCK_clrh, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 275 /* clrh */, Sparc::STHrr, Convert__MEMrr2_2__regG0, 0, { MCK_clrh, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 280 /* cmask16 */, Sparc::CMASK16, Convert__Reg1_1, Feature_HasVIS3, { MCK_cmask16, MCK_IntRegs }, },
  { 288 /* cmask32 */, Sparc::CMASK32, Convert__Reg1_1, Feature_HasVIS3, { MCK_cmask32, MCK_IntRegs }, },
  { 296 /* cmask8 */, Sparc::CMASK8, Convert__Reg1_1, Feature_HasVIS3, { MCK_cmask8, MCK_IntRegs }, },
  { 303 /* cmp */, Sparc::CMPrr, Convert__Reg1_1__Reg1_2, 0, { MCK_cmp, MCK_IntRegs, MCK_IntRegs }, },
  { 303 /* cmp */, Sparc::CMPri, Convert__Reg1_1__Imm1_2, 0, { MCK_cmp, MCK_IntRegs, MCK_Imm }, },
  { 307 /* dec */, Sparc::SUBri, Convert__Reg1_1__Reg1_1__imm_95_1, 0, { MCK_dec, MCK_IntRegs }, },
  { 307 /* dec */, Sparc::SUBri, Convert__Reg1_2__Reg1_2__Imm1_1, 0, { MCK_dec, MCK_Imm, MCK_IntRegs }, },
  { 311 /* deccc */, Sparc::SUBCCri, Convert__Reg1_1__Reg1_1__imm_95_1, 0, { MCK_deccc, MCK_IntRegs }, },
  { 311 /* deccc */, Sparc::SUBCCri, Convert__Reg1_2__Reg1_2__Imm1_1, 0, { MCK_deccc, MCK_Imm, MCK_IntRegs }, },
  { 317 /* edge16 */, Sparc::EDGE16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_edge16, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 324 /* edge16l */, Sparc::EDGE16L, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_edge16l, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 332 /* edge16ln */, Sparc::EDGE16LN, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS2, { MCK_edge16ln, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 341 /* edge16n */, Sparc::EDGE16N, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS2, { MCK_edge16n, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 349 /* edge32 */, Sparc::EDGE32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_edge32, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 356 /* edge32l */, Sparc::EDGE32L, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_edge32l, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 364 /* edge32ln */, Sparc::EDGE32LN, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS2, { MCK_edge32ln, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 373 /* edge32n */, Sparc::EDGE32N, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS2, { MCK_edge32n, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 381 /* edge8 */, Sparc::EDGE8, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_edge8, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 387 /* edge8l */, Sparc::EDGE8L, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_edge8l, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 394 /* edge8ln */, Sparc::EDGE8LN, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS2, { MCK_edge8ln, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 402 /* edge8n */, Sparc::EDGE8N, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS2, { MCK_edge8n, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 409 /* fabsd */, Sparc::FABSD, Convert__Reg1_2__Reg1_1, Feature_HasV9, { MCK_fabsd, MCK_DFPRegs, MCK_DFPRegs }, },
  { 415 /* fabsq */, Sparc::FABSQ, Convert__Reg1_2__Reg1_1, Feature_HasV9, { MCK_fabsq, MCK_QFPRegs, MCK_QFPRegs }, },
  { 421 /* fabss */, Sparc::FABSS, Convert__Reg1_2__Reg1_1, 0, { MCK_fabss, MCK_FPRegs, MCK_FPRegs }, },
  { 427 /* faddd */, Sparc::FADDD, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_faddd, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 433 /* faddq */, Sparc::FADDQ, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_faddq, MCK_QFPRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 439 /* fadds */, Sparc::FADDS, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fadds, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 445 /* faligndata */, Sparc::FALIGNADATA, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_faligndata, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 456 /* fand */, Sparc::FAND, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fand, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 461 /* fandnot1 */, Sparc::FANDNOT1, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fandnot1, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 470 /* fandnot1s */, Sparc::FANDNOT1S, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fandnot1s, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 480 /* fandnot2 */, Sparc::FANDNOT2, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fandnot2, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 489 /* fandnot2s */, Sparc::FANDNOT2S, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fandnot2s, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 499 /* fands */, Sparc::FANDS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fands, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 505 /* fb */, Sparc::FBCOND, Convert__Imm1_1__imm_95_0, 0, { MCK_fb, MCK_Imm }, },
  { 505 /* fb */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_0, 0, { MCK_fb, MCK_a, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCC, Convert__Imm1_2__imm_95_0__Reg1_1, Feature_HasV9, { MCK_fb, MCK_FCCRegs, MCK_Imm }, },
  { 505 /* fb */, Sparc::FBCOND, Convert__Imm1_2__Imm1_1, 0, { MCK_fb, MCK_Imm, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_0__Reg1_2, Feature_HasV9, { MCK_fb, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_0__Reg1_2, Feature_HasV9, { MCK_fb, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCC, Convert__Imm1_3__imm_95_0__Reg1_2, Feature_HasV9, { MCK_fb, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 505 /* fb */, Sparc::FBCONDA, Convert__Imm1_3__Imm1_1, 0, { MCK_fb, MCK_Imm, MCK_a, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCC, Convert__Imm1_3__Imm1_1__Reg1_2, Feature_HasV9, { MCK_fb, MCK_Imm, MCK_FCCRegs, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_0__Reg1_3, Feature_HasV9, { MCK_fb, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_0__Reg1_3, Feature_HasV9, { MCK_fb, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCCA, Convert__Imm1_4__Imm1_1__Reg1_3, Feature_HasV9, { MCK_fb, MCK_Imm, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCCNT, Convert__Imm1_4__Imm1_1__Reg1_3, Feature_HasV9, { MCK_fb, MCK_Imm, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 505 /* fb */, Sparc::BPFCCANT, Convert__Imm1_5__Imm1_1__Reg1_4, Feature_HasV9, { MCK_fb, MCK_Imm, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 508 /* fba */, Sparc::FBCOND, Convert__Imm1_1__imm_95_0, 0, { MCK_fba, MCK_Imm }, },
  { 508 /* fba */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_0, 0, { MCK_fba, MCK_a, MCK_Imm }, },
  { 508 /* fba */, Sparc::BPFCC, Convert__Imm1_2__imm_95_0__Reg1_1, Feature_HasV9, { MCK_fba, MCK_FCCRegs, MCK_Imm }, },
  { 508 /* fba */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_0__Reg1_2, Feature_HasV9, { MCK_fba, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 508 /* fba */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_0__Reg1_2, Feature_HasV9, { MCK_fba, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 508 /* fba */, Sparc::BPFCC, Convert__Imm1_3__imm_95_0__Reg1_2, Feature_HasV9, { MCK_fba, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 508 /* fba */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_0__Reg1_3, Feature_HasV9, { MCK_fba, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 508 /* fba */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_0__Reg1_3, Feature_HasV9, { MCK_fba, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 512 /* fbe */, Sparc::FBCOND, Convert__Imm1_1__imm_95_9, 0, { MCK_fbe, MCK_Imm }, },
  { 512 /* fbe */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_9, 0, { MCK_fbe, MCK_a, MCK_Imm }, },
  { 512 /* fbe */, Sparc::BPFCC, Convert__Imm1_2__imm_95_9__Reg1_1, Feature_HasV9, { MCK_fbe, MCK_FCCRegs, MCK_Imm }, },
  { 512 /* fbe */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_9__Reg1_2, Feature_HasV9, { MCK_fbe, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 512 /* fbe */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_9__Reg1_2, Feature_HasV9, { MCK_fbe, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 512 /* fbe */, Sparc::BPFCC, Convert__Imm1_3__imm_95_9__Reg1_2, Feature_HasV9, { MCK_fbe, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 512 /* fbe */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_9__Reg1_3, Feature_HasV9, { MCK_fbe, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 512 /* fbe */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_9__Reg1_3, Feature_HasV9, { MCK_fbe, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 516 /* fbg */, Sparc::FBCOND, Convert__Imm1_1__imm_95_6, 0, { MCK_fbg, MCK_Imm }, },
  { 516 /* fbg */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_6, 0, { MCK_fbg, MCK_a, MCK_Imm }, },
  { 516 /* fbg */, Sparc::BPFCC, Convert__Imm1_2__imm_95_6__Reg1_1, Feature_HasV9, { MCK_fbg, MCK_FCCRegs, MCK_Imm }, },
  { 516 /* fbg */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_6__Reg1_2, Feature_HasV9, { MCK_fbg, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 516 /* fbg */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_6__Reg1_2, Feature_HasV9, { MCK_fbg, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 516 /* fbg */, Sparc::BPFCC, Convert__Imm1_3__imm_95_6__Reg1_2, Feature_HasV9, { MCK_fbg, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 516 /* fbg */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_6__Reg1_3, Feature_HasV9, { MCK_fbg, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 516 /* fbg */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_6__Reg1_3, Feature_HasV9, { MCK_fbg, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 520 /* fbge */, Sparc::FBCOND, Convert__Imm1_1__imm_95_11, 0, { MCK_fbge, MCK_Imm }, },
  { 520 /* fbge */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_11, 0, { MCK_fbge, MCK_a, MCK_Imm }, },
  { 520 /* fbge */, Sparc::BPFCC, Convert__Imm1_2__imm_95_11__Reg1_1, Feature_HasV9, { MCK_fbge, MCK_FCCRegs, MCK_Imm }, },
  { 520 /* fbge */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_11__Reg1_2, Feature_HasV9, { MCK_fbge, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 520 /* fbge */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_11__Reg1_2, Feature_HasV9, { MCK_fbge, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 520 /* fbge */, Sparc::BPFCC, Convert__Imm1_3__imm_95_11__Reg1_2, Feature_HasV9, { MCK_fbge, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 520 /* fbge */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_11__Reg1_3, Feature_HasV9, { MCK_fbge, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 520 /* fbge */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_11__Reg1_3, Feature_HasV9, { MCK_fbge, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 525 /* fbl */, Sparc::FBCOND, Convert__Imm1_1__imm_95_4, 0, { MCK_fbl, MCK_Imm }, },
  { 525 /* fbl */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_4, 0, { MCK_fbl, MCK_a, MCK_Imm }, },
  { 525 /* fbl */, Sparc::BPFCC, Convert__Imm1_2__imm_95_4__Reg1_1, Feature_HasV9, { MCK_fbl, MCK_FCCRegs, MCK_Imm }, },
  { 525 /* fbl */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_4__Reg1_2, Feature_HasV9, { MCK_fbl, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 525 /* fbl */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_4__Reg1_2, Feature_HasV9, { MCK_fbl, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 525 /* fbl */, Sparc::BPFCC, Convert__Imm1_3__imm_95_4__Reg1_2, Feature_HasV9, { MCK_fbl, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 525 /* fbl */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_4__Reg1_3, Feature_HasV9, { MCK_fbl, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 525 /* fbl */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_4__Reg1_3, Feature_HasV9, { MCK_fbl, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 529 /* fble */, Sparc::FBCOND, Convert__Imm1_1__imm_95_13, 0, { MCK_fble, MCK_Imm }, },
  { 529 /* fble */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_13, 0, { MCK_fble, MCK_a, MCK_Imm }, },
  { 529 /* fble */, Sparc::BPFCC, Convert__Imm1_2__imm_95_13__Reg1_1, Feature_HasV9, { MCK_fble, MCK_FCCRegs, MCK_Imm }, },
  { 529 /* fble */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_13__Reg1_2, Feature_HasV9, { MCK_fble, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 529 /* fble */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_13__Reg1_2, Feature_HasV9, { MCK_fble, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 529 /* fble */, Sparc::BPFCC, Convert__Imm1_3__imm_95_13__Reg1_2, Feature_HasV9, { MCK_fble, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 529 /* fble */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_13__Reg1_3, Feature_HasV9, { MCK_fble, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 529 /* fble */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_13__Reg1_3, Feature_HasV9, { MCK_fble, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 534 /* fblg */, Sparc::FBCOND, Convert__Imm1_1__imm_95_2, 0, { MCK_fblg, MCK_Imm }, },
  { 534 /* fblg */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_2, 0, { MCK_fblg, MCK_a, MCK_Imm }, },
  { 534 /* fblg */, Sparc::BPFCC, Convert__Imm1_2__imm_95_2__Reg1_1, Feature_HasV9, { MCK_fblg, MCK_FCCRegs, MCK_Imm }, },
  { 534 /* fblg */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_2__Reg1_2, Feature_HasV9, { MCK_fblg, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 534 /* fblg */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_2__Reg1_2, Feature_HasV9, { MCK_fblg, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 534 /* fblg */, Sparc::BPFCC, Convert__Imm1_3__imm_95_2__Reg1_2, Feature_HasV9, { MCK_fblg, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 534 /* fblg */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_2__Reg1_3, Feature_HasV9, { MCK_fblg, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 534 /* fblg */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_2__Reg1_3, Feature_HasV9, { MCK_fblg, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 539 /* fbn */, Sparc::FBCOND, Convert__Imm1_1__imm_95_8, 0, { MCK_fbn, MCK_Imm }, },
  { 539 /* fbn */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_8, 0, { MCK_fbn, MCK_a, MCK_Imm }, },
  { 539 /* fbn */, Sparc::BPFCC, Convert__Imm1_2__imm_95_8__Reg1_1, Feature_HasV9, { MCK_fbn, MCK_FCCRegs, MCK_Imm }, },
  { 539 /* fbn */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_8__Reg1_2, Feature_HasV9, { MCK_fbn, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 539 /* fbn */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_8__Reg1_2, Feature_HasV9, { MCK_fbn, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 539 /* fbn */, Sparc::BPFCC, Convert__Imm1_3__imm_95_8__Reg1_2, Feature_HasV9, { MCK_fbn, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 539 /* fbn */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_8__Reg1_3, Feature_HasV9, { MCK_fbn, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 539 /* fbn */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_8__Reg1_3, Feature_HasV9, { MCK_fbn, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 543 /* fbne */, Sparc::FBCOND, Convert__Imm1_1__imm_95_1, 0, { MCK_fbne, MCK_Imm }, },
  { 543 /* fbne */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_1, 0, { MCK_fbne, MCK_a, MCK_Imm }, },
  { 543 /* fbne */, Sparc::BPFCC, Convert__Imm1_2__imm_95_1__Reg1_1, Feature_HasV9, { MCK_fbne, MCK_FCCRegs, MCK_Imm }, },
  { 543 /* fbne */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_1__Reg1_2, Feature_HasV9, { MCK_fbne, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 543 /* fbne */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_1__Reg1_2, Feature_HasV9, { MCK_fbne, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 543 /* fbne */, Sparc::BPFCC, Convert__Imm1_3__imm_95_1__Reg1_2, Feature_HasV9, { MCK_fbne, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 543 /* fbne */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_1__Reg1_3, Feature_HasV9, { MCK_fbne, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 543 /* fbne */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_1__Reg1_3, Feature_HasV9, { MCK_fbne, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 548 /* fbnz */, Sparc::FBCOND, Convert__Imm1_1__imm_95_1, 0, { MCK_fbnz, MCK_Imm }, },
  { 548 /* fbnz */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_1, 0, { MCK_fbnz, MCK_a, MCK_Imm }, },
  { 548 /* fbnz */, Sparc::BPFCC, Convert__Imm1_2__imm_95_1__Reg1_1, Feature_HasV9, { MCK_fbnz, MCK_FCCRegs, MCK_Imm }, },
  { 548 /* fbnz */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_1__Reg1_2, Feature_HasV9, { MCK_fbnz, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 548 /* fbnz */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_1__Reg1_2, Feature_HasV9, { MCK_fbnz, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 548 /* fbnz */, Sparc::BPFCC, Convert__Imm1_3__imm_95_1__Reg1_2, Feature_HasV9, { MCK_fbnz, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 548 /* fbnz */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_1__Reg1_3, Feature_HasV9, { MCK_fbnz, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 548 /* fbnz */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_1__Reg1_3, Feature_HasV9, { MCK_fbnz, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 553 /* fbo */, Sparc::FBCOND, Convert__Imm1_1__imm_95_15, 0, { MCK_fbo, MCK_Imm }, },
  { 553 /* fbo */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_15, 0, { MCK_fbo, MCK_a, MCK_Imm }, },
  { 553 /* fbo */, Sparc::BPFCC, Convert__Imm1_2__imm_95_15__Reg1_1, Feature_HasV9, { MCK_fbo, MCK_FCCRegs, MCK_Imm }, },
  { 553 /* fbo */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_15__Reg1_2, Feature_HasV9, { MCK_fbo, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 553 /* fbo */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_15__Reg1_2, Feature_HasV9, { MCK_fbo, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 553 /* fbo */, Sparc::BPFCC, Convert__Imm1_3__imm_95_15__Reg1_2, Feature_HasV9, { MCK_fbo, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 553 /* fbo */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_15__Reg1_3, Feature_HasV9, { MCK_fbo, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 553 /* fbo */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_15__Reg1_3, Feature_HasV9, { MCK_fbo, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 557 /* fbu */, Sparc::FBCOND, Convert__Imm1_1__imm_95_7, 0, { MCK_fbu, MCK_Imm }, },
  { 557 /* fbu */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_7, 0, { MCK_fbu, MCK_a, MCK_Imm }, },
  { 557 /* fbu */, Sparc::BPFCC, Convert__Imm1_2__imm_95_7__Reg1_1, Feature_HasV9, { MCK_fbu, MCK_FCCRegs, MCK_Imm }, },
  { 557 /* fbu */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_7__Reg1_2, Feature_HasV9, { MCK_fbu, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 557 /* fbu */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_7__Reg1_2, Feature_HasV9, { MCK_fbu, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 557 /* fbu */, Sparc::BPFCC, Convert__Imm1_3__imm_95_7__Reg1_2, Feature_HasV9, { MCK_fbu, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 557 /* fbu */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_7__Reg1_3, Feature_HasV9, { MCK_fbu, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 557 /* fbu */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_7__Reg1_3, Feature_HasV9, { MCK_fbu, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 561 /* fbue */, Sparc::FBCOND, Convert__Imm1_1__imm_95_10, 0, { MCK_fbue, MCK_Imm }, },
  { 561 /* fbue */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_10, 0, { MCK_fbue, MCK_a, MCK_Imm }, },
  { 561 /* fbue */, Sparc::BPFCC, Convert__Imm1_2__imm_95_10__Reg1_1, Feature_HasV9, { MCK_fbue, MCK_FCCRegs, MCK_Imm }, },
  { 561 /* fbue */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_10__Reg1_2, Feature_HasV9, { MCK_fbue, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 561 /* fbue */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_10__Reg1_2, Feature_HasV9, { MCK_fbue, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 561 /* fbue */, Sparc::BPFCC, Convert__Imm1_3__imm_95_10__Reg1_2, Feature_HasV9, { MCK_fbue, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 561 /* fbue */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_10__Reg1_3, Feature_HasV9, { MCK_fbue, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 561 /* fbue */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_10__Reg1_3, Feature_HasV9, { MCK_fbue, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 566 /* fbug */, Sparc::FBCOND, Convert__Imm1_1__imm_95_5, 0, { MCK_fbug, MCK_Imm }, },
  { 566 /* fbug */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_5, 0, { MCK_fbug, MCK_a, MCK_Imm }, },
  { 566 /* fbug */, Sparc::BPFCC, Convert__Imm1_2__imm_95_5__Reg1_1, Feature_HasV9, { MCK_fbug, MCK_FCCRegs, MCK_Imm }, },
  { 566 /* fbug */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_5__Reg1_2, Feature_HasV9, { MCK_fbug, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 566 /* fbug */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_5__Reg1_2, Feature_HasV9, { MCK_fbug, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 566 /* fbug */, Sparc::BPFCC, Convert__Imm1_3__imm_95_5__Reg1_2, Feature_HasV9, { MCK_fbug, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 566 /* fbug */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_5__Reg1_3, Feature_HasV9, { MCK_fbug, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 566 /* fbug */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_5__Reg1_3, Feature_HasV9, { MCK_fbug, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 571 /* fbuge */, Sparc::FBCOND, Convert__Imm1_1__imm_95_12, 0, { MCK_fbuge, MCK_Imm }, },
  { 571 /* fbuge */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_12, 0, { MCK_fbuge, MCK_a, MCK_Imm }, },
  { 571 /* fbuge */, Sparc::BPFCC, Convert__Imm1_2__imm_95_12__Reg1_1, Feature_HasV9, { MCK_fbuge, MCK_FCCRegs, MCK_Imm }, },
  { 571 /* fbuge */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_12__Reg1_2, Feature_HasV9, { MCK_fbuge, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 571 /* fbuge */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_12__Reg1_2, Feature_HasV9, { MCK_fbuge, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 571 /* fbuge */, Sparc::BPFCC, Convert__Imm1_3__imm_95_12__Reg1_2, Feature_HasV9, { MCK_fbuge, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 571 /* fbuge */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_12__Reg1_3, Feature_HasV9, { MCK_fbuge, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 571 /* fbuge */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_12__Reg1_3, Feature_HasV9, { MCK_fbuge, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 577 /* fbul */, Sparc::FBCOND, Convert__Imm1_1__imm_95_3, 0, { MCK_fbul, MCK_Imm }, },
  { 577 /* fbul */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_3, 0, { MCK_fbul, MCK_a, MCK_Imm }, },
  { 577 /* fbul */, Sparc::BPFCC, Convert__Imm1_2__imm_95_3__Reg1_1, Feature_HasV9, { MCK_fbul, MCK_FCCRegs, MCK_Imm }, },
  { 577 /* fbul */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_3__Reg1_2, Feature_HasV9, { MCK_fbul, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 577 /* fbul */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_3__Reg1_2, Feature_HasV9, { MCK_fbul, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 577 /* fbul */, Sparc::BPFCC, Convert__Imm1_3__imm_95_3__Reg1_2, Feature_HasV9, { MCK_fbul, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 577 /* fbul */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_3__Reg1_3, Feature_HasV9, { MCK_fbul, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 577 /* fbul */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_3__Reg1_3, Feature_HasV9, { MCK_fbul, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 582 /* fbule */, Sparc::FBCOND, Convert__Imm1_1__imm_95_14, 0, { MCK_fbule, MCK_Imm }, },
  { 582 /* fbule */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_14, 0, { MCK_fbule, MCK_a, MCK_Imm }, },
  { 582 /* fbule */, Sparc::BPFCC, Convert__Imm1_2__imm_95_14__Reg1_1, Feature_HasV9, { MCK_fbule, MCK_FCCRegs, MCK_Imm }, },
  { 582 /* fbule */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_14__Reg1_2, Feature_HasV9, { MCK_fbule, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 582 /* fbule */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_14__Reg1_2, Feature_HasV9, { MCK_fbule, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 582 /* fbule */, Sparc::BPFCC, Convert__Imm1_3__imm_95_14__Reg1_2, Feature_HasV9, { MCK_fbule, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 582 /* fbule */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_14__Reg1_3, Feature_HasV9, { MCK_fbule, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 582 /* fbule */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_14__Reg1_3, Feature_HasV9, { MCK_fbule, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 588 /* fbz */, Sparc::FBCOND, Convert__Imm1_1__imm_95_9, 0, { MCK_fbz, MCK_Imm }, },
  { 588 /* fbz */, Sparc::FBCONDA, Convert__Imm1_2__imm_95_9, 0, { MCK_fbz, MCK_a, MCK_Imm }, },
  { 588 /* fbz */, Sparc::BPFCC, Convert__Imm1_2__imm_95_9__Reg1_1, Feature_HasV9, { MCK_fbz, MCK_FCCRegs, MCK_Imm }, },
  { 588 /* fbz */, Sparc::BPFCCA, Convert__Imm1_3__imm_95_9__Reg1_2, Feature_HasV9, { MCK_fbz, MCK_a, MCK_FCCRegs, MCK_Imm }, },
  { 588 /* fbz */, Sparc::BPFCCNT, Convert__Imm1_3__imm_95_9__Reg1_2, Feature_HasV9, { MCK_fbz, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 588 /* fbz */, Sparc::BPFCC, Convert__Imm1_3__imm_95_9__Reg1_2, Feature_HasV9, { MCK_fbz, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 588 /* fbz */, Sparc::BPFCCANT, Convert__Imm1_4__imm_95_9__Reg1_3, Feature_HasV9, { MCK_fbz, MCK_a, MCK_pn, MCK_FCCRegs, MCK_Imm }, },
  { 588 /* fbz */, Sparc::BPFCCA, Convert__Imm1_4__imm_95_9__Reg1_3, Feature_HasV9, { MCK_fbz, MCK_a, MCK_pt, MCK_FCCRegs, MCK_Imm }, },
  { 592 /* fchksm16 */, Sparc::FCHKSM16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fchksm16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 601 /* fcmpd */, Sparc::V9FCMPD, Convert__regFCC0__Reg1_1__Reg1_2, 0, { MCK_fcmpd, MCK_DFPRegs, MCK_DFPRegs }, },
  { 601 /* fcmpd */, Sparc::V9FCMPD, Convert__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_fcmpd, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 607 /* fcmped */, Sparc::V9FCMPED, Convert__regFCC0__Reg1_1__Reg1_2, 0, { MCK_fcmped, MCK_DFPRegs, MCK_DFPRegs }, },
  { 607 /* fcmped */, Sparc::V9FCMPED, Convert__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_fcmped, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 614 /* fcmpeq */, Sparc::V9FCMPEQ, Convert__regFCC0__Reg1_1__Reg1_2, 0, { MCK_fcmpeq, MCK_QFPRegs, MCK_QFPRegs }, },
  { 614 /* fcmpeq */, Sparc::V9FCMPEQ, Convert__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_fcmpeq, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 621 /* fcmpeq16 */, Sparc::FCMPEQ16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fcmpeq16, MCK_DFPRegs, MCK_DFPRegs, MCK_IntRegs }, },
  { 630 /* fcmpeq32 */, Sparc::FCMPEQ32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fcmpeq32, MCK_DFPRegs, MCK_DFPRegs, MCK_IntRegs }, },
  { 639 /* fcmpes */, Sparc::V9FCMPES, Convert__regFCC0__Reg1_1__Reg1_2, 0, { MCK_fcmpes, MCK_FPRegs, MCK_FPRegs }, },
  { 639 /* fcmpes */, Sparc::V9FCMPES, Convert__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_fcmpes, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 646 /* fcmpgt16 */, Sparc::FCMPGT16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fcmpgt16, MCK_DFPRegs, MCK_DFPRegs, MCK_IntRegs }, },
  { 655 /* fcmpgt32 */, Sparc::FCMPGT32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fcmpgt32, MCK_DFPRegs, MCK_DFPRegs, MCK_IntRegs }, },
  { 664 /* fcmple16 */, Sparc::FCMPLE16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fcmple16, MCK_DFPRegs, MCK_DFPRegs, MCK_IntRegs }, },
  { 673 /* fcmple32 */, Sparc::FCMPLE32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fcmple32, MCK_DFPRegs, MCK_DFPRegs, MCK_IntRegs }, },
  { 682 /* fcmpne16 */, Sparc::FCMPNE16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fcmpne16, MCK_DFPRegs, MCK_DFPRegs, MCK_IntRegs }, },
  { 691 /* fcmpne32 */, Sparc::FCMPNE32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fcmpne32, MCK_DFPRegs, MCK_DFPRegs, MCK_IntRegs }, },
  { 700 /* fcmpq */, Sparc::V9FCMPQ, Convert__regFCC0__Reg1_1__Reg1_2, 0, { MCK_fcmpq, MCK_QFPRegs, MCK_QFPRegs }, },
  { 700 /* fcmpq */, Sparc::V9FCMPQ, Convert__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_fcmpq, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 706 /* fcmps */, Sparc::V9FCMPS, Convert__regFCC0__Reg1_1__Reg1_2, 0, { MCK_fcmps, MCK_FPRegs, MCK_FPRegs }, },
  { 706 /* fcmps */, Sparc::V9FCMPS, Convert__Reg1_1__Reg1_2__Reg1_3, 0, { MCK_fcmps, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 712 /* fdivd */, Sparc::FDIVD, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fdivd, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 718 /* fdivq */, Sparc::FDIVQ, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fdivq, MCK_QFPRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 724 /* fdivs */, Sparc::FDIVS, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fdivs, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 730 /* fdmulq */, Sparc::FDMULQ, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fdmulq, MCK_DFPRegs, MCK_DFPRegs, MCK_QFPRegs }, },
  { 737 /* fdtoi */, Sparc::FDTOI, Convert__Reg1_2__Reg1_1, 0, { MCK_fdtoi, MCK_DFPRegs, MCK_FPRegs }, },
  { 743 /* fdtoq */, Sparc::FDTOQ, Convert__Reg1_2__Reg1_1, 0, { MCK_fdtoq, MCK_DFPRegs, MCK_QFPRegs }, },
  { 749 /* fdtos */, Sparc::FDTOS, Convert__Reg1_2__Reg1_1, 0, { MCK_fdtos, MCK_DFPRegs, MCK_FPRegs }, },
  { 755 /* fdtox */, Sparc::FDTOX, Convert__Reg1_2__Reg1_1, 0, { MCK_fdtox, MCK_DFPRegs, MCK_DFPRegs }, },
  { 761 /* fexpand */, Sparc::FEXPAND, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fexpand, MCK_DFPRegs, MCK_DFPRegs }, },
  { 769 /* fhaddd */, Sparc::FHADDD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fhaddd, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 776 /* fhadds */, Sparc::FHADDS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fhadds, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 783 /* fhsubd */, Sparc::FHSUBD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fhsubd, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 790 /* fhsubs */, Sparc::FHSUBS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fhsubs, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 797 /* fitod */, Sparc::FITOD, Convert__Reg1_2__Reg1_1, 0, { MCK_fitod, MCK_FPRegs, MCK_DFPRegs }, },
  { 803 /* fitoq */, Sparc::FITOQ, Convert__Reg1_2__Reg1_1, 0, { MCK_fitoq, MCK_FPRegs, MCK_QFPRegs }, },
  { 809 /* fitos */, Sparc::FITOS, Convert__Reg1_2__Reg1_1, 0, { MCK_fitos, MCK_FPRegs, MCK_FPRegs }, },
  { 815 /* flcmpd */, Sparc::FLCMPD, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasVIS3, { MCK_flcmpd, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 822 /* flcmps */, Sparc::FLCMPS, Convert__Reg1_1__Reg1_2__Reg1_3, Feature_HasVIS3, { MCK_flcmps, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 829 /* flush */, Sparc::FLUSH, Convert_NoOperands, 0, { MCK_flush }, },
  { 829 /* flush */, Sparc::FLUSH, Convert_NoOperands, 0, { MCK_flush, MCK__PCT_g0 }, },
  { 829 /* flush */, Sparc::FLUSHri, Convert__MEMri2_1, 0, { MCK_flush, MCK_MEMri }, },
  { 829 /* flush */, Sparc::FLUSHrr, Convert__MEMrr2_1, 0, { MCK_flush, MCK_MEMrr }, },
  { 835 /* flushw */, Sparc::FLUSHW, Convert_NoOperands, Feature_HasV9, { MCK_flushw }, },
  { 842 /* fmean16 */, Sparc::FMEAN16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fmean16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 850 /* fmovd */, Sparc::FMOVD, Convert__Reg1_2__Reg1_1, Feature_HasV9, { MCK_fmovd, MCK_DFPRegs, MCK_DFPRegs }, },
  { 850 /* fmovd */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_fmovd, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 850 /* fmovd */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, 0, { MCK_fmovd, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 850 /* fmovd */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_fmovd, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 850 /* fmovd */, Sparc::FMOVD_FCC, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_fmovd, MCK_Imm, MCK__PCT_fcc0, MCK_DFPRegs, MCK_DFPRegs }, },
  { 850 /* fmovd */, Sparc::FMOVD_ICC, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_fmovd, MCK_Imm, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 850 /* fmovd */, Sparc::FMOVD_XCC, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, 0, { MCK_fmovd, MCK_Imm, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 850 /* fmovd */, Sparc::V9FMOVD_FCC, Convert__Reg1_4__Reg1_2__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_fmovd, MCK_Imm, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 856 /* fmovda */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_fmovda, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 856 /* fmovda */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, 0, { MCK_fmovda, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 856 /* fmovda */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_fmovda, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 863 /* fmovdcc */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_fmovdcc, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 863 /* fmovdcc */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, 0, { MCK_fmovdcc, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 871 /* fmovdcs */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_fmovdcs, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 871 /* fmovdcs */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, 0, { MCK_fmovdcs, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 879 /* fmovde */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovde, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 879 /* fmovde */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_fmovde, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 879 /* fmovde */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovde, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 886 /* fmovdeq */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovdeq, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 886 /* fmovdeq */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_fmovdeq, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 894 /* fmovdg */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_fmovdg, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 894 /* fmovdg */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_10, 0, { MCK_fmovdg, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 894 /* fmovdg */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_fmovdg, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 901 /* fmovdge */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_fmovdge, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 901 /* fmovdge */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_11, 0, { MCK_fmovdge, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 901 /* fmovdge */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_fmovdge, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 909 /* fmovdgeu */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_fmovdgeu, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 909 /* fmovdgeu */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, 0, { MCK_fmovdgeu, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 918 /* fmovdgu */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_fmovdgu, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 918 /* fmovdgu */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_12, 0, { MCK_fmovdgu, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 926 /* fmovdl */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_fmovdl, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 926 /* fmovdl */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_3, 0, { MCK_fmovdl, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 926 /* fmovdl */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_fmovdl, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 933 /* fmovdle */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_fmovdle, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 933 /* fmovdle */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_2, 0, { MCK_fmovdle, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 933 /* fmovdle */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_fmovdle, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 941 /* fmovdleu */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_fmovdleu, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 941 /* fmovdleu */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_4, 0, { MCK_fmovdleu, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 950 /* fmovdlg */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_fmovdlg, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 958 /* fmovdlu */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_fmovdlu, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 958 /* fmovdlu */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, 0, { MCK_fmovdlu, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 966 /* fmovdn */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_fmovdn, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 966 /* fmovdn */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_0, 0, { MCK_fmovdn, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 966 /* fmovdn */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_fmovdn, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 973 /* fmovdne */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovdne, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 973 /* fmovdne */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, 0, { MCK_fmovdne, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 973 /* fmovdne */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovdne, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 981 /* fmovdneg */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_fmovdneg, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 981 /* fmovdneg */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_6, 0, { MCK_fmovdneg, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 990 /* fmovdnz */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovdnz, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 990 /* fmovdnz */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, 0, { MCK_fmovdnz, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 990 /* fmovdnz */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovdnz, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 998 /* fmovdo */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_fmovdo, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1005 /* fmovdpos */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_fmovdpos, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1005 /* fmovdpos */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_14, 0, { MCK_fmovdpos, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1014 /* fmovdu */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_fmovdu, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1021 /* fmovdue */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_fmovdue, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1029 /* fmovdug */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_fmovdug, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1037 /* fmovduge */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_fmovduge, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1046 /* fmovdul */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_fmovdul, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1054 /* fmovdule */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_fmovdule, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1063 /* fmovdvc */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_fmovdvc, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1063 /* fmovdvc */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_15, 0, { MCK_fmovdvc, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1071 /* fmovdvs */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_fmovdvs, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1071 /* fmovdvs */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_7, 0, { MCK_fmovdvs, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1079 /* fmovdz */, Sparc::FMOVD_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovdz, MCK__PCT_icc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1079 /* fmovdz */, Sparc::FMOVD_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_fmovdz, MCK__PCT_xcc, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1079 /* fmovdz */, Sparc::V9FMOVD_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovdz, MCK_FCCRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1086 /* fmovq */, Sparc::FMOVQ, Convert__Reg1_2__Reg1_1, Feature_HasV9, { MCK_fmovq, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1086 /* fmovq */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_fmovq, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1086 /* fmovq */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, 0, { MCK_fmovq, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1086 /* fmovq */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_fmovq, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1086 /* fmovq */, Sparc::FMOVQ_FCC, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_fmovq, MCK_Imm, MCK__PCT_fcc0, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1086 /* fmovq */, Sparc::FMOVQ_ICC, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_fmovq, MCK_Imm, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1086 /* fmovq */, Sparc::FMOVQ_XCC, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, 0, { MCK_fmovq, MCK_Imm, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1086 /* fmovq */, Sparc::V9FMOVQ_FCC, Convert__Reg1_4__Reg1_2__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_fmovq, MCK_Imm, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1092 /* fmovqa */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_fmovqa, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1092 /* fmovqa */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, 0, { MCK_fmovqa, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1092 /* fmovqa */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_fmovqa, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1099 /* fmovqcc */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_fmovqcc, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1099 /* fmovqcc */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, 0, { MCK_fmovqcc, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1107 /* fmovqcs */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_fmovqcs, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1107 /* fmovqcs */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, 0, { MCK_fmovqcs, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1115 /* fmovqe */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovqe, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1115 /* fmovqe */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_fmovqe, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1115 /* fmovqe */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovqe, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1122 /* fmovqeq */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovqeq, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1122 /* fmovqeq */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_fmovqeq, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1130 /* fmovqg */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_fmovqg, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1130 /* fmovqg */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_10, 0, { MCK_fmovqg, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1130 /* fmovqg */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_fmovqg, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1137 /* fmovqge */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_fmovqge, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1137 /* fmovqge */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_11, 0, { MCK_fmovqge, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1137 /* fmovqge */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_fmovqge, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1145 /* fmovqgeu */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_fmovqgeu, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1145 /* fmovqgeu */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, 0, { MCK_fmovqgeu, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1154 /* fmovqgu */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_fmovqgu, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1154 /* fmovqgu */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_12, 0, { MCK_fmovqgu, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1162 /* fmovql */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_fmovql, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1162 /* fmovql */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_3, 0, { MCK_fmovql, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1162 /* fmovql */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_fmovql, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1169 /* fmovqle */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_fmovqle, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1169 /* fmovqle */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_2, 0, { MCK_fmovqle, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1169 /* fmovqle */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_fmovqle, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1177 /* fmovqleu */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_fmovqleu, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1177 /* fmovqleu */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_4, 0, { MCK_fmovqleu, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1186 /* fmovqlg */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_fmovqlg, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1194 /* fmovqlu */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_fmovqlu, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1194 /* fmovqlu */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, 0, { MCK_fmovqlu, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1202 /* fmovqn */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_fmovqn, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1202 /* fmovqn */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_0, 0, { MCK_fmovqn, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1202 /* fmovqn */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_fmovqn, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1209 /* fmovqne */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovqne, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1209 /* fmovqne */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, 0, { MCK_fmovqne, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1209 /* fmovqne */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovqne, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1217 /* fmovqneg */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_fmovqneg, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1217 /* fmovqneg */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_6, 0, { MCK_fmovqneg, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1226 /* fmovqnz */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovqnz, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1226 /* fmovqnz */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, 0, { MCK_fmovqnz, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1226 /* fmovqnz */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovqnz, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1234 /* fmovqo */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_fmovqo, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1241 /* fmovqpos */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_fmovqpos, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1241 /* fmovqpos */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_14, 0, { MCK_fmovqpos, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1250 /* fmovqu */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_fmovqu, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1257 /* fmovque */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_fmovque, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1265 /* fmovqug */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_fmovqug, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1273 /* fmovquge */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_fmovquge, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1282 /* fmovqul */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_fmovqul, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1290 /* fmovqule */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_fmovqule, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1299 /* fmovqvc */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_fmovqvc, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1299 /* fmovqvc */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_15, 0, { MCK_fmovqvc, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1307 /* fmovqvs */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_fmovqvs, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1307 /* fmovqvs */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_7, 0, { MCK_fmovqvs, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1315 /* fmovqz */, Sparc::FMOVQ_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovqz, MCK__PCT_icc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1315 /* fmovqz */, Sparc::FMOVQ_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_fmovqz, MCK__PCT_xcc, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1315 /* fmovqz */, Sparc::V9FMOVQ_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovqz, MCK_FCCRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1322 /* fmovrdgez */, Sparc::FMOVRGEZD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrdgez, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1332 /* fmovrdgz */, Sparc::FMOVRGZD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrdgz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1341 /* fmovrdlez */, Sparc::FMOVRLEZD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrdlez, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1351 /* fmovrdlz */, Sparc::FMOVRLZD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrdlz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1360 /* fmovrdnz */, Sparc::FMOVRNZD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrdnz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1369 /* fmovrdz */, Sparc::FMOVRZD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrdz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1377 /* fmovrqgez */, Sparc::FMOVRGEZQ, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrqgez, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1387 /* fmovrqgz */, Sparc::FMOVRGZQ, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrqgz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1396 /* fmovrqlez */, Sparc::FMOVRLEZQ, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrqlez, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1406 /* fmovrqlz */, Sparc::FMOVRLZQ, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrqlz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1415 /* fmovrqnz */, Sparc::FMOVRNZQ, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrqnz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1424 /* fmovrqz */, Sparc::FMOVRZQ, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrqz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1432 /* fmovrsgez */, Sparc::FMOVRGEZS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrsgez, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1442 /* fmovrsgz */, Sparc::FMOVRGZS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrsgz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1451 /* fmovrslez */, Sparc::FMOVRLEZS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrslez, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1461 /* fmovrslz */, Sparc::FMOVRLZS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrslz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1470 /* fmovrsnz */, Sparc::FMOVRNZS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrsnz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1479 /* fmovrsz */, Sparc::FMOVRZS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_fmovrsz, MCK_IntRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1487 /* fmovs */, Sparc::FMOVS, Convert__Reg1_2__Reg1_1, 0, { MCK_fmovs, MCK_FPRegs, MCK_FPRegs }, },
  { 1487 /* fmovs */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_fmovs, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1487 /* fmovs */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, 0, { MCK_fmovs, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1487 /* fmovs */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_fmovs, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1487 /* fmovs */, Sparc::FMOVS_FCC, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_fmovs, MCK_Imm, MCK__PCT_fcc0, MCK_FPRegs, MCK_FPRegs }, },
  { 1487 /* fmovs */, Sparc::FMOVS_ICC, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_fmovs, MCK_Imm, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1487 /* fmovs */, Sparc::FMOVS_XCC, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, 0, { MCK_fmovs, MCK_Imm, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1487 /* fmovs */, Sparc::V9FMOVS_FCC, Convert__Reg1_4__Reg1_2__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_fmovs, MCK_Imm, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1493 /* fmovsa */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_fmovsa, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1493 /* fmovsa */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, 0, { MCK_fmovsa, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1493 /* fmovsa */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_fmovsa, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1500 /* fmovscc */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_fmovscc, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1500 /* fmovscc */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, 0, { MCK_fmovscc, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1508 /* fmovscs */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_fmovscs, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1508 /* fmovscs */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, 0, { MCK_fmovscs, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1516 /* fmovse */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovse, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1516 /* fmovse */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_fmovse, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1516 /* fmovse */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovse, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1523 /* fmovseq */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovseq, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1523 /* fmovseq */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_fmovseq, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1531 /* fmovsg */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_fmovsg, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1531 /* fmovsg */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_10, 0, { MCK_fmovsg, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1531 /* fmovsg */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_fmovsg, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1538 /* fmovsge */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_fmovsge, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1538 /* fmovsge */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_11, 0, { MCK_fmovsge, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1538 /* fmovsge */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_fmovsge, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1546 /* fmovsgeu */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_fmovsgeu, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1546 /* fmovsgeu */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, 0, { MCK_fmovsgeu, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1555 /* fmovsgu */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_fmovsgu, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1555 /* fmovsgu */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_12, 0, { MCK_fmovsgu, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1563 /* fmovsl */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_fmovsl, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1563 /* fmovsl */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_3, 0, { MCK_fmovsl, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1563 /* fmovsl */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_fmovsl, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1570 /* fmovsle */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_fmovsle, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1570 /* fmovsle */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_2, 0, { MCK_fmovsle, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1570 /* fmovsle */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_fmovsle, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1578 /* fmovsleu */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_fmovsleu, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1578 /* fmovsleu */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_4, 0, { MCK_fmovsleu, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1587 /* fmovslg */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_fmovslg, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1595 /* fmovslu */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_fmovslu, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1595 /* fmovslu */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, 0, { MCK_fmovslu, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1603 /* fmovsn */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_fmovsn, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1603 /* fmovsn */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_0, 0, { MCK_fmovsn, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1603 /* fmovsn */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_fmovsn, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1610 /* fmovsne */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovsne, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1610 /* fmovsne */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, 0, { MCK_fmovsne, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1610 /* fmovsne */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovsne, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1618 /* fmovsneg */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_fmovsneg, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1618 /* fmovsneg */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_6, 0, { MCK_fmovsneg, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1627 /* fmovsnz */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovsnz, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1627 /* fmovsnz */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, 0, { MCK_fmovsnz, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1627 /* fmovsnz */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovsnz, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1635 /* fmovso */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_fmovso, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1642 /* fmovspos */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_fmovspos, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1642 /* fmovspos */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_14, 0, { MCK_fmovspos, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1651 /* fmovsu */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_fmovsu, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1658 /* fmovsue */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_fmovsue, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1666 /* fmovsug */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_fmovsug, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1674 /* fmovsuge */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_fmovsuge, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1683 /* fmovsul */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_fmovsul, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1691 /* fmovsule */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_fmovsule, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1700 /* fmovsvc */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_fmovsvc, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1700 /* fmovsvc */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_15, 0, { MCK_fmovsvc, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1708 /* fmovsvs */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_fmovsvs, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1708 /* fmovsvs */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_7, 0, { MCK_fmovsvs, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1716 /* fmovsz */, Sparc::FMOVS_ICC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_fmovsz, MCK__PCT_icc, MCK_FPRegs, MCK_FPRegs }, },
  { 1716 /* fmovsz */, Sparc::FMOVS_XCC, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_fmovsz, MCK__PCT_xcc, MCK_FPRegs, MCK_FPRegs }, },
  { 1716 /* fmovsz */, Sparc::V9FMOVS_FCC, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_fmovsz, MCK_FCCRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1723 /* fmul8sux16 */, Sparc::FMUL8SUX16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fmul8sux16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1734 /* fmul8ulx16 */, Sparc::FMUL8ULX16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fmul8ulx16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1745 /* fmul8x16 */, Sparc::FMUL8X16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fmul8x16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1754 /* fmul8x16al */, Sparc::FMUL8X16AL, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fmul8x16al, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1765 /* fmul8x16au */, Sparc::FMUL8X16AU, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fmul8x16au, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1776 /* fmuld */, Sparc::FMULD, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fmuld, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1782 /* fmuld8sux16 */, Sparc::FMULD8SUX16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fmuld8sux16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1794 /* fmuld8ulx16 */, Sparc::FMULD8ULX16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fmuld8ulx16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1806 /* fmulq */, Sparc::FMULQ, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fmulq, MCK_QFPRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1812 /* fmuls */, Sparc::FMULS, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fmuls, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1818 /* fnaddd */, Sparc::FNADDD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fnaddd, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1825 /* fnadds */, Sparc::FNADDS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fnadds, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1832 /* fnand */, Sparc::FNAND, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fnand, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1838 /* fnands */, Sparc::FNANDS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fnands, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1845 /* fnegd */, Sparc::FNEGD, Convert__Reg1_2__Reg1_1, Feature_HasV9, { MCK_fnegd, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1851 /* fnegq */, Sparc::FNEGQ, Convert__Reg1_2__Reg1_1, Feature_HasV9, { MCK_fnegq, MCK_QFPRegs, MCK_QFPRegs }, },
  { 1857 /* fnegs */, Sparc::FNEGS, Convert__Reg1_2__Reg1_1, 0, { MCK_fnegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1863 /* fnhaddd */, Sparc::FNHADDD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fnhaddd, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1863 /* fnhaddd */, Sparc::FNMULD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fnhaddd, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1871 /* fnhadds */, Sparc::FNHADDS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fnhadds, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1871 /* fnhadds */, Sparc::FNMULS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fnhadds, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1871 /* fnhadds */, Sparc::FNSMULD, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fnhadds, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1879 /* fnor */, Sparc::FNOR, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fnor, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1884 /* fnors */, Sparc::FNORS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fnors, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1890 /* fnot1 */, Sparc::FNOT1, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fnot1, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1896 /* fnot1s */, Sparc::FNOT1S, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fnot1s, MCK_FPRegs, MCK_FPRegs }, },
  { 1903 /* fnot2 */, Sparc::FNOT2, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fnot2, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1909 /* fnot2s */, Sparc::FNOT2S, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fnot2s, MCK_FPRegs, MCK_FPRegs }, },
  { 1916 /* fone */, Sparc::FONE, Convert__Reg1_1__Tie0, Feature_HasVIS, { MCK_fone, MCK_DFPRegs }, },
  { 1921 /* fones */, Sparc::FONES, Convert__Reg1_1__Tie0, Feature_HasVIS, { MCK_fones, MCK_FPRegs }, },
  { 1927 /* for */, Sparc::FOR, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_for, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1931 /* fornot1 */, Sparc::FORNOT1, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fornot1, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1939 /* fornot1s */, Sparc::FORNOT1S, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fornot1s, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1948 /* fornot2 */, Sparc::FORNOT2, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fornot2, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1956 /* fornot2s */, Sparc::FORNOT2S, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fornot2s, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1965 /* fors */, Sparc::FORS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fors, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 1970 /* fpack16 */, Sparc::FPACK16, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fpack16, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1978 /* fpack32 */, Sparc::FPACK32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpack32, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1986 /* fpackfix */, Sparc::FPACKFIX, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fpackfix, MCK_DFPRegs, MCK_DFPRegs }, },
  { 1995 /* fpadd16 */, Sparc::FPADD16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpadd16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2003 /* fpadd16s */, Sparc::FPADD16S, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpadd16s, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2012 /* fpadd32 */, Sparc::FPADD32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpadd32, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2020 /* fpadd32s */, Sparc::FPADD32S, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpadd32s, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2029 /* fpadd64 */, Sparc::FPADD64, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fpadd64, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2037 /* fpmerge */, Sparc::FPMERGE, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpmerge, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2045 /* fpsub16 */, Sparc::FPSUB16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpsub16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2053 /* fpsub16S */, Sparc::FPSUB16S, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpsub16S, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2062 /* fpsub32 */, Sparc::FPSUB32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpsub32, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2070 /* fpsub32S */, Sparc::FPSUB32S, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fpsub32S, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2079 /* fqtod */, Sparc::FQTOD, Convert__Reg1_2__Reg1_1, 0, { MCK_fqtod, MCK_QFPRegs, MCK_DFPRegs }, },
  { 2085 /* fqtoi */, Sparc::FQTOI, Convert__Reg1_2__Reg1_1, 0, { MCK_fqtoi, MCK_QFPRegs, MCK_FPRegs }, },
  { 2091 /* fqtos */, Sparc::FQTOS, Convert__Reg1_2__Reg1_1, 0, { MCK_fqtos, MCK_QFPRegs, MCK_FPRegs }, },
  { 2097 /* fqtox */, Sparc::FQTOX, Convert__Reg1_2__Reg1_1, 0, { MCK_fqtox, MCK_QFPRegs, MCK_DFPRegs }, },
  { 2103 /* fslas16 */, Sparc::FSLAS16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fslas16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2111 /* fslas32 */, Sparc::FSLAS32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fslas32, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2119 /* fsll16 */, Sparc::FSLL16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fsll16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2126 /* fsll32 */, Sparc::FSLL32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fsll32, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2133 /* fsmuld */, Sparc::FSMULD, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fsmuld, MCK_FPRegs, MCK_FPRegs, MCK_DFPRegs }, },
  { 2140 /* fsqrtd */, Sparc::FSQRTD, Convert__Reg1_2__Reg1_1, 0, { MCK_fsqrtd, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2147 /* fsqrtq */, Sparc::FSQRTQ, Convert__Reg1_2__Reg1_1, 0, { MCK_fsqrtq, MCK_QFPRegs, MCK_QFPRegs }, },
  { 2154 /* fsqrts */, Sparc::FSQRTS, Convert__Reg1_2__Reg1_1, 0, { MCK_fsqrts, MCK_FPRegs, MCK_FPRegs }, },
  { 2161 /* fsra16 */, Sparc::FSRA16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fsra16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2168 /* fsra32 */, Sparc::FSRA32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fsra32, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2175 /* fsrc1 */, Sparc::FSRC1, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fsrc1, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2181 /* fsrc1s */, Sparc::FSRC1S, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fsrc1s, MCK_FPRegs, MCK_FPRegs }, },
  { 2188 /* fsrc2 */, Sparc::FSRC2, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fsrc2, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2194 /* fsrc2s */, Sparc::FSRC2S, Convert__Reg1_2__Reg1_1, Feature_HasVIS, { MCK_fsrc2s, MCK_FPRegs, MCK_FPRegs }, },
  { 2201 /* fsrl16 */, Sparc::FSRL16, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fsrl16, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2208 /* fsrl32 */, Sparc::FSRL32, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_fsrl32, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2215 /* fstod */, Sparc::FSTOD, Convert__Reg1_2__Reg1_1, 0, { MCK_fstod, MCK_FPRegs, MCK_DFPRegs }, },
  { 2221 /* fstoi */, Sparc::FSTOI, Convert__Reg1_2__Reg1_1, 0, { MCK_fstoi, MCK_FPRegs, MCK_FPRegs }, },
  { 2227 /* fstoq */, Sparc::FSTOQ, Convert__Reg1_2__Reg1_1, 0, { MCK_fstoq, MCK_FPRegs, MCK_QFPRegs }, },
  { 2233 /* fstox */, Sparc::FSTOX, Convert__Reg1_2__Reg1_1, 0, { MCK_fstox, MCK_FPRegs, MCK_DFPRegs }, },
  { 2239 /* fsubd */, Sparc::FSUBD, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fsubd, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2245 /* fsubq */, Sparc::FSUBQ, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fsubq, MCK_QFPRegs, MCK_QFPRegs, MCK_QFPRegs }, },
  { 2251 /* fsubs */, Sparc::FSUBS, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_fsubs, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 2257 /* fxnor */, Sparc::FXNOR, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fxnor, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2263 /* fxnors */, Sparc::FXNORS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fxnors, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 2270 /* fxor */, Sparc::FXOR, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fxor, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2275 /* fxors */, Sparc::FXORS, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_fxors, MCK_FPRegs, MCK_FPRegs, MCK_FPRegs }, },
  { 2281 /* fxtod */, Sparc::FXTOD, Convert__Reg1_2__Reg1_1, 0, { MCK_fxtod, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2287 /* fxtoq */, Sparc::FXTOQ, Convert__Reg1_2__Reg1_1, 0, { MCK_fxtoq, MCK_DFPRegs, MCK_QFPRegs }, },
  { 2293 /* fxtos */, Sparc::FXTOS, Convert__Reg1_2__Reg1_1, 0, { MCK_fxtos, MCK_DFPRegs, MCK_FPRegs }, },
  { 2299 /* fzero */, Sparc::FZERO, Convert__Reg1_1__Tie0, Feature_HasVIS, { MCK_fzero, MCK_DFPRegs }, },
  { 2305 /* fzeros */, Sparc::FZEROS, Convert__Reg1_1__Tie0, Feature_HasVIS, { MCK_fzeros, MCK_FPRegs }, },
  { 2312 /* inc */, Sparc::ADDri, Convert__Reg1_1__Reg1_1__imm_95_1, 0, { MCK_inc, MCK_IntRegs }, },
  { 2312 /* inc */, Sparc::ADDri, Convert__Reg1_2__Reg1_2__Imm1_1, 0, { MCK_inc, MCK_Imm, MCK_IntRegs }, },
  { 2316 /* inccc */, Sparc::ADDCCri, Convert__Reg1_1__Reg1_1__imm_95_1, 0, { MCK_inccc, MCK_IntRegs }, },
  { 2316 /* inccc */, Sparc::ADDCCri, Convert__Reg1_2__Reg1_2__Imm1_1, 0, { MCK_inccc, MCK_Imm, MCK_IntRegs }, },
  { 2322 /* jmp */, Sparc::JMPLri, Convert__regG0__MEMri2_1, 0, { MCK_jmp, MCK_MEMri }, },
  { 2322 /* jmp */, Sparc::JMPLrr, Convert__regG0__MEMrr2_1, 0, { MCK_jmp, MCK_MEMrr }, },
  { 2326 /* jmpl */, Sparc::JMPLri, Convert__Reg1_2__MEMri2_1, 0, { MCK_jmpl, MCK_MEMri, MCK_IntRegs }, },
  { 2326 /* jmpl */, Sparc::JMPLrr, Convert__Reg1_2__MEMrr2_1, 0, { MCK_jmpl, MCK_MEMrr, MCK_IntRegs }, },
  { 2331 /* ld */, Sparc::LDFSRri, Convert__MEMri2_2, 0, { MCK_ld, MCK__91_, MCK_MEMri, MCK__93_, MCK__PCT_fsr }, },
  { 2331 /* ld */, Sparc::LDri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ld, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntRegs }, },
  { 2331 /* ld */, Sparc::LDFri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ld, MCK__91_, MCK_MEMri, MCK__93_, MCK_FPRegs }, },
  { 2331 /* ld */, Sparc::LDFSRrr, Convert__MEMrr2_2, 0, { MCK_ld, MCK__91_, MCK_MEMrr, MCK__93_, MCK__PCT_fsr }, },
  { 2331 /* ld */, Sparc::LDrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ld, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntRegs }, },
  { 2331 /* ld */, Sparc::LDFrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ld, MCK__91_, MCK_MEMrr, MCK__93_, MCK_FPRegs }, },
  { 2334 /* lda */, Sparc::LDArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, 0, { MCK_lda, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_IntRegs }, },
  { 2334 /* lda */, Sparc::LDFArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, Feature_HasV9, { MCK_lda, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_FPRegs }, },
  { 2338 /* ldd */, Sparc::LDDFri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ldd, MCK__91_, MCK_MEMri, MCK__93_, MCK_DFPRegs }, },
  { 2338 /* ldd */, Sparc::LDDri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ldd, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntPair }, },
  { 2338 /* ldd */, Sparc::LDDFrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ldd, MCK__91_, MCK_MEMrr, MCK__93_, MCK_DFPRegs }, },
  { 2338 /* ldd */, Sparc::LDDrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ldd, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntPair }, },
  { 2342 /* ldda */, Sparc::LDDFArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, Feature_HasV9, { MCK_ldda, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_DFPRegs }, },
  { 2342 /* ldda */, Sparc::LDDArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, 0, { MCK_ldda, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_IntPair }, },
  { 2347 /* ldq */, Sparc::LDQFri, Convert__Reg1_4__MEMri2_2, Feature_HasV9, { MCK_ldq, MCK__91_, MCK_MEMri, MCK__93_, MCK_QFPRegs }, },
  { 2347 /* ldq */, Sparc::LDQFrr, Convert__Reg1_4__MEMrr2_2, Feature_HasV9, { MCK_ldq, MCK__91_, MCK_MEMrr, MCK__93_, MCK_QFPRegs }, },
  { 2351 /* ldqa */, Sparc::LDQFArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, Feature_HasV9, { MCK_ldqa, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_QFPRegs }, },
  { 2356 /* ldsb */, Sparc::LDSBri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ldsb, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntRegs }, },
  { 2356 /* ldsb */, Sparc::LDSBrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ldsb, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntRegs }, },
  { 2361 /* ldsba */, Sparc::LDSBArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, 0, { MCK_ldsba, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_IntRegs }, },
  { 2367 /* ldsh */, Sparc::LDSHri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ldsh, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntRegs }, },
  { 2367 /* ldsh */, Sparc::LDSHrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ldsh, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntRegs }, },
  { 2372 /* ldsha */, Sparc::LDSHArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, 0, { MCK_ldsha, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_IntRegs }, },
  { 2378 /* ldstub */, Sparc::LDSTUBri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ldstub, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntRegs }, },
  { 2378 /* ldstub */, Sparc::LDSTUBrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ldstub, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntRegs }, },
  { 2385 /* ldstuba */, Sparc::LDSTUBArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, 0, { MCK_ldstuba, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_IntRegs }, },
  { 2393 /* ldsw */, Sparc::LDSWri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ldsw, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntRegs }, },
  { 2393 /* ldsw */, Sparc::LDSWrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ldsw, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntRegs }, },
  { 2398 /* ldub */, Sparc::LDUBri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ldub, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntRegs }, },
  { 2398 /* ldub */, Sparc::LDUBrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ldub, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntRegs }, },
  { 2403 /* lduba */, Sparc::LDUBArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, 0, { MCK_lduba, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_IntRegs }, },
  { 2409 /* lduh */, Sparc::LDUHri, Convert__Reg1_4__MEMri2_2, 0, { MCK_lduh, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntRegs }, },
  { 2409 /* lduh */, Sparc::LDUHrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_lduh, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntRegs }, },
  { 2414 /* lduha */, Sparc::LDUHArr, Convert__Reg1_5__MEMrr2_2__Imm1_4, 0, { MCK_lduha, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_IntRegs }, },
  { 2420 /* ldx */, Sparc::LDXFSRri, Convert__MEMri2_2, Feature_HasV9, { MCK_ldx, MCK__91_, MCK_MEMri, MCK__93_, MCK__PCT_fsr }, },
  { 2420 /* ldx */, Sparc::LDXri, Convert__Reg1_4__MEMri2_2, 0, { MCK_ldx, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntRegs }, },
  { 2420 /* ldx */, Sparc::LDXFSRrr, Convert__MEMrr2_2, Feature_HasV9, { MCK_ldx, MCK__91_, MCK_MEMrr, MCK__93_, MCK__PCT_fsr }, },
  { 2420 /* ldx */, Sparc::LDXrr, Convert__Reg1_4__MEMrr2_2, 0, { MCK_ldx, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntRegs }, },
  { 2424 /* lzcnt */, Sparc::LZCNT, Convert__Reg1_2__Reg1_1, Feature_HasVIS3, { MCK_lzcnt, MCK_IntRegs, MCK_IntRegs }, },
  { 2430 /* membar */, Sparc::MEMBARi, Convert__Imm1_1, Feature_HasV9, { MCK_membar, MCK_Imm }, },
  { 2437 /* mov */, Sparc::RDPSR, Convert__Reg1_2, 0, { MCK_mov, MCK__PCT_psr, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::RDTBR, Convert__Reg1_2, 0, { MCK_mov, MCK__PCT_tbr, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::RDWIM, Convert__Reg1_2, 0, { MCK_mov, MCK__PCT_wim, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::RDASR, Convert__Reg1_2__Reg1_1, 0, { MCK_mov, MCK_ASRRegs, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::WRPSRrr, Convert__regG0__Reg1_1, 0, { MCK_mov, MCK_IntRegs, MCK__PCT_psr }, },
  { 2437 /* mov */, Sparc::WRTBRrr, Convert__regG0__Reg1_1, 0, { MCK_mov, MCK_IntRegs, MCK__PCT_tbr }, },
  { 2437 /* mov */, Sparc::WRWIMrr, Convert__regG0__Reg1_1, 0, { MCK_mov, MCK_IntRegs, MCK__PCT_wim }, },
  { 2437 /* mov */, Sparc::WRASRrr, Convert__Reg1_2__regG0__Reg1_1, 0, { MCK_mov, MCK_IntRegs, MCK_ASRRegs }, },
  { 2437 /* mov */, Sparc::ORrr, Convert__Reg1_2__regG0__Reg1_1, 0, { MCK_mov, MCK_IntRegs, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::WRPSRri, Convert__regG0__Imm1_1, 0, { MCK_mov, MCK_Imm, MCK__PCT_psr }, },
  { 2437 /* mov */, Sparc::WRTBRri, Convert__regG0__Imm1_1, 0, { MCK_mov, MCK_Imm, MCK__PCT_tbr }, },
  { 2437 /* mov */, Sparc::WRWIMri, Convert__regG0__Imm1_1, 0, { MCK_mov, MCK_Imm, MCK__PCT_wim }, },
  { 2437 /* mov */, Sparc::WRASRri, Convert__Reg1_2__regG0__Imm1_1, 0, { MCK_mov, MCK_Imm, MCK_ASRRegs }, },
  { 2437 /* mov */, Sparc::ORri, Convert__Reg1_2__regG0__Imm1_1, 0, { MCK_mov, MCK_Imm, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_mov, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_mov, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, 0, { MCK_mov, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_8, 0, { MCK_mov, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_mov, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_mov, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVFCCrr, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_mov, MCK_Imm, MCK__PCT_fcc0, MCK_IntRegs, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVFCCri, Convert__Reg1_4__Imm1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_mov, MCK_Imm, MCK__PCT_fcc0, MCK_Imm, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVICCrr, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_mov, MCK_Imm, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVICCri, Convert__Reg1_4__Imm1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_mov, MCK_Imm, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVXCCrr, Convert__Reg1_4__Reg1_3__Tie0__Imm1_1, 0, { MCK_mov, MCK_Imm, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::MOVXCCri, Convert__Reg1_4__Imm1_3__Tie0__Imm1_1, 0, { MCK_mov, MCK_Imm, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::V9MOVFCCrr, Convert__Reg1_4__Reg1_2__Reg1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_mov, MCK_Imm, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2437 /* mov */, Sparc::V9MOVFCCri, Convert__Reg1_4__Reg1_2__Imm1_3__Tie0__Imm1_1, Feature_HasV9, { MCK_mov, MCK_Imm, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2441 /* mova */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_mova, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2441 /* mova */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_mova, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2441 /* mova */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_8, 0, { MCK_mova, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2441 /* mova */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_8, 0, { MCK_mova, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2441 /* mova */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_mova, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2441 /* mova */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_mova, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2446 /* movcc */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_movcc, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2446 /* movcc */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_movcc, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2446 /* movcc */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, 0, { MCK_movcc, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2446 /* movcc */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_13, 0, { MCK_movcc, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2452 /* movcs */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_movcs, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2452 /* movcs */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_movcs, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2452 /* movcs */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, 0, { MCK_movcs, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2452 /* movcs */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_5, 0, { MCK_movcs, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2458 /* movdtox */, Sparc::MOVWTOS, Convert__Reg1_2__Reg1_1, Feature_HasVIS3, { MCK_movdtox, MCK_IntRegs, MCK_DFPRegs }, },
  { 2458 /* movdtox */, Sparc::MOVXTOD, Convert__Reg1_2__Reg1_1, Feature_HasVIS3, { MCK_movdtox, MCK_IntRegs, MCK_DFPRegs }, },
  { 2458 /* movdtox */, Sparc::MOVDTOX, Convert__Reg1_2__Reg1_1, Feature_HasVIS3, { MCK_movdtox, MCK_DFPRegs, MCK_IntRegs }, },
  { 2466 /* move */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_move, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2466 /* move */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_move, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2466 /* move */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_move, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2466 /* move */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_1, 0, { MCK_move, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2466 /* move */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_move, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2466 /* move */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_move, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2471 /* moveq */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_moveq, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2471 /* moveq */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_moveq, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2471 /* moveq */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_moveq, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2471 /* moveq */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_1, 0, { MCK_moveq, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2477 /* movg */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_movg, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2477 /* movg */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_movg, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2477 /* movg */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_10, 0, { MCK_movg, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2477 /* movg */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_10, 0, { MCK_movg, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2477 /* movg */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_movg, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2477 /* movg */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_movg, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2482 /* movge */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_movge, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2482 /* movge */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_movge, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2482 /* movge */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_11, 0, { MCK_movge, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2482 /* movge */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_11, 0, { MCK_movge, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2482 /* movge */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_movge, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2482 /* movge */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_11, Feature_HasV9, { MCK_movge, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2488 /* movgeu */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_movgeu, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2488 /* movgeu */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_movgeu, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2488 /* movgeu */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_13, 0, { MCK_movgeu, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2488 /* movgeu */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_13, 0, { MCK_movgeu, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2495 /* movgu */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_movgu, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2495 /* movgu */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_movgu, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2495 /* movgu */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_12, 0, { MCK_movgu, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2495 /* movgu */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_12, 0, { MCK_movgu, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2501 /* movl */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_movl, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2501 /* movl */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_movl, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2501 /* movl */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_3, 0, { MCK_movl, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2501 /* movl */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_3, 0, { MCK_movl, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2501 /* movl */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_movl, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2501 /* movl */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_movl, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2506 /* movle */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_movle, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2506 /* movle */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_movle, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2506 /* movle */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_2, 0, { MCK_movle, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2506 /* movle */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_2, 0, { MCK_movle, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2506 /* movle */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_movle, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2506 /* movle */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_13, Feature_HasV9, { MCK_movle, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2512 /* movleu */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_movleu, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2512 /* movleu */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_4, Feature_HasV9, { MCK_movleu, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2512 /* movleu */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_4, 0, { MCK_movleu, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2512 /* movleu */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_4, 0, { MCK_movleu, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2519 /* movlg */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_movlg, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2519 /* movlg */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_2, Feature_HasV9, { MCK_movlg, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2525 /* movlu */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_movlu, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2525 /* movlu */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_movlu, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2525 /* movlu */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_5, 0, { MCK_movlu, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2525 /* movlu */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_5, 0, { MCK_movlu, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2531 /* movn */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_movn, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2531 /* movn */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_0, Feature_HasV9, { MCK_movn, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2531 /* movn */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_0, 0, { MCK_movn, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2531 /* movn */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_0, 0, { MCK_movn, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2531 /* movn */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_movn, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2531 /* movn */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_8, Feature_HasV9, { MCK_movn, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2536 /* movne */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_movne, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2536 /* movne */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_movne, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2536 /* movne */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, 0, { MCK_movne, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2536 /* movne */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_9, 0, { MCK_movne, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2536 /* movne */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_movne, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2536 /* movne */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_movne, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2542 /* movneg */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_movneg, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2542 /* movneg */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_6, Feature_HasV9, { MCK_movneg, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2542 /* movneg */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_6, 0, { MCK_movneg, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2542 /* movneg */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_6, 0, { MCK_movneg, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2549 /* movnz */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_movnz, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2549 /* movnz */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_movnz, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2549 /* movnz */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_9, 0, { MCK_movnz, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2549 /* movnz */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_9, 0, { MCK_movnz, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2549 /* movnz */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_movnz, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2549 /* movnz */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_movnz, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2555 /* movo */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_movo, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2555 /* movo */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_movo, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2560 /* movpos */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_movpos, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2560 /* movpos */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_movpos, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2560 /* movpos */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_14, 0, { MCK_movpos, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2560 /* movpos */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_14, 0, { MCK_movpos, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2567 /* movrgez */, Sparc::MOVRGEZrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_movrgez, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2567 /* movrgez */, Sparc::MOVRGEZri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_movrgez, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2575 /* movrgz */, Sparc::MOVRGZrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_movrgz, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2575 /* movrgz */, Sparc::MOVRGZri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_movrgz, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2582 /* movrlez */, Sparc::MOVRLEZrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_movrlez, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2582 /* movrlez */, Sparc::MOVRLEZri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_movrlez, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2590 /* movrlz */, Sparc::MOVRLZrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_movrlz, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2590 /* movrlz */, Sparc::MOVRLZri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_movrlz, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2597 /* movrnz */, Sparc::MOVRNZrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_movrnz, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2597 /* movrnz */, Sparc::MOVRNZri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_movrnz, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2604 /* movrz */, Sparc::MOVRRZrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_movrz, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2604 /* movrz */, Sparc::MOVRRZri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_movrz, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2610 /* movstosw */, Sparc::MOVSTOSW, Convert__Reg1_2__Reg1_1, Feature_HasVIS3, { MCK_movstosw, MCK_DFPRegs, MCK_IntRegs }, },
  { 2619 /* movstouw */, Sparc::MOVSTOUW, Convert__Reg1_2__Reg1_1, Feature_HasVIS3, { MCK_movstouw, MCK_DFPRegs, MCK_IntRegs }, },
  { 2628 /* movu */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_movu, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2628 /* movu */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_movu, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2633 /* movue */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_movue, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2633 /* movue */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_10, Feature_HasV9, { MCK_movue, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2639 /* movug */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_movug, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2639 /* movug */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_5, Feature_HasV9, { MCK_movug, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2645 /* movuge */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_movuge, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2645 /* movuge */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_12, Feature_HasV9, { MCK_movuge, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2652 /* movul */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_movul, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2652 /* movul */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_3, Feature_HasV9, { MCK_movul, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2658 /* movule */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_movule, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2658 /* movule */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_14, Feature_HasV9, { MCK_movule, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2665 /* movvc */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_movvc, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2665 /* movvc */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_15, Feature_HasV9, { MCK_movvc, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2665 /* movvc */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_15, 0, { MCK_movvc, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2665 /* movvc */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_15, 0, { MCK_movvc, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2671 /* movvs */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_movvs, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2671 /* movvs */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_7, Feature_HasV9, { MCK_movvs, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2671 /* movvs */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_7, 0, { MCK_movvs, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2671 /* movvs */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_7, 0, { MCK_movvs, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2677 /* movz */, Sparc::MOVICCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_movz, MCK__PCT_icc, MCK_IntRegs, MCK_IntRegs }, },
  { 2677 /* movz */, Sparc::MOVICCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_1, Feature_HasV9, { MCK_movz, MCK__PCT_icc, MCK_Imm, MCK_IntRegs }, },
  { 2677 /* movz */, Sparc::MOVXCCrr, Convert__Reg1_3__Reg1_2__Tie0__imm_95_1, 0, { MCK_movz, MCK__PCT_xcc, MCK_IntRegs, MCK_IntRegs }, },
  { 2677 /* movz */, Sparc::MOVXCCri, Convert__Reg1_3__Imm1_2__Tie0__imm_95_1, 0, { MCK_movz, MCK__PCT_xcc, MCK_Imm, MCK_IntRegs }, },
  { 2677 /* movz */, Sparc::V9MOVFCCrr, Convert__Reg1_3__Reg1_1__Reg1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_movz, MCK_FCCRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2677 /* movz */, Sparc::V9MOVFCCri, Convert__Reg1_3__Reg1_1__Imm1_2__Tie0__imm_95_9, Feature_HasV9, { MCK_movz, MCK_FCCRegs, MCK_Imm, MCK_IntRegs }, },
  { 2682 /* mulscc */, Sparc::MULSCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_mulscc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2682 /* mulscc */, Sparc::MULSCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_mulscc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2689 /* mulx */, Sparc::MULXrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_mulx, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2689 /* mulx */, Sparc::MULXri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_mulx, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2694 /* neg */, Sparc::SUBrr, Convert__Reg1_1__regG0__Reg1_1, 0, { MCK_neg, MCK_IntRegs }, },
  { 2694 /* neg */, Sparc::SUBrr, Convert__Reg1_2__regG0__Reg1_1, 0, { MCK_neg, MCK_IntRegs, MCK_IntRegs }, },
  { 2698 /* nop */, Sparc::NOP, Convert_NoOperands, 0, { MCK_nop }, },
  { 2702 /* not */, Sparc::XNORrr, Convert__Reg1_1__Reg1_1__regG0, 0, { MCK_not, MCK_IntRegs }, },
  { 2702 /* not */, Sparc::XNORrr, Convert__Reg1_2__Reg1_1__regG0, 0, { MCK_not, MCK_IntRegs, MCK_IntRegs }, },
  { 2706 /* or */, Sparc::ORrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_or, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2706 /* or */, Sparc::ORri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_or, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2709 /* orcc */, Sparc::ORCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_orcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2709 /* orcc */, Sparc::ORCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_orcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2714 /* orn */, Sparc::ORNrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_orn, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2714 /* orn */, Sparc::ORNri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_orn, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2718 /* orncc */, Sparc::ORNCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_orncc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2718 /* orncc */, Sparc::ORNCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_orncc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2724 /* pdist */, Sparc::PDIST, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS, { MCK_pdist, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2730 /* pdistn */, Sparc::PDISTN, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_pdistn, MCK_DFPRegs, MCK_DFPRegs, MCK_DFPRegs }, },
  { 2737 /* popc */, Sparc::POPCrr, Convert__Reg1_2__Reg1_1, Feature_HasV9, { MCK_popc, MCK_IntRegs, MCK_IntRegs }, },
  { 2742 /* rd */, Sparc::RDPSR, Convert__Reg1_2, 0, { MCK_rd, MCK__PCT_psr, MCK_IntRegs }, },
  { 2742 /* rd */, Sparc::RDTBR, Convert__Reg1_2, 0, { MCK_rd, MCK__PCT_tbr, MCK_IntRegs }, },
  { 2742 /* rd */, Sparc::RDWIM, Convert__Reg1_2, 0, { MCK_rd, MCK__PCT_wim, MCK_IntRegs }, },
  { 2742 /* rd */, Sparc::RDASR, Convert__Reg1_2__Reg1_1, 0, { MCK_rd, MCK_ASRRegs, MCK_IntRegs }, },
  { 2745 /* rdpr */, Sparc::RDPR, Convert__Reg1_2__Reg1_1, Feature_HasV9, { MCK_rdpr, MCK_PRRegs, MCK_IntRegs }, },
  { 2750 /* restore */, Sparc::RESTORErr, Convert__regG0__regG0__regG0, 0, { MCK_restore }, },
  { 2750 /* restore */, Sparc::RESTORErr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_restore, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2750 /* restore */, Sparc::RESTOREri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_restore, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2758 /* ret */, Sparc::RET, Convert__imm_95_8, 0, { MCK_ret }, },
  { 2762 /* retl */, Sparc::RETL, Convert__imm_95_8, 0, { MCK_retl }, },
  { 2767 /* rett */, Sparc::RETTri, Convert__MEMri2_1, 0, { MCK_rett, MCK_MEMri }, },
  { 2767 /* rett */, Sparc::RETTrr, Convert__MEMrr2_1, 0, { MCK_rett, MCK_MEMrr }, },
  { 2772 /* save */, Sparc::SAVErr, Convert__regG0__regG0__regG0, 0, { MCK_save }, },
  { 2772 /* save */, Sparc::SAVErr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_save, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2772 /* save */, Sparc::SAVEri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_save, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2777 /* sdiv */, Sparc::SDIVrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_sdiv, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2777 /* sdiv */, Sparc::SDIVri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_sdiv, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2782 /* sdivcc */, Sparc::SDIVCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_sdivcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2782 /* sdivcc */, Sparc::SDIVCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_sdivcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2789 /* sdivx */, Sparc::SDIVXrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_sdivx, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2789 /* sdivx */, Sparc::SDIVXri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_sdivx, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2795 /* set */, Sparc::SET, Convert__Reg1_2__Imm1_1, 0, { MCK_set, MCK_Imm, MCK_IntRegs }, },
  { 2799 /* sethi */, Sparc::SETHIi, Convert__Reg1_2__Imm1_1, 0, { MCK_sethi, MCK_Imm, MCK_IntRegs }, },
  { 2805 /* shutdown */, Sparc::SHUTDOWN, Convert_NoOperands, Feature_HasVIS, { MCK_shutdown }, },
  { 2814 /* siam */, Sparc::SIAM, Convert_NoOperands, Feature_HasVIS2, { MCK_siam }, },
  { 2819 /* signx */, Sparc::SRArr, Convert__Reg1_1__Reg1_1__regG0, Feature_HasV9, { MCK_signx, MCK_IntRegs }, },
  { 2819 /* signx */, Sparc::SRArr, Convert__Reg1_2__Reg1_1__regG0, Feature_HasV9, { MCK_signx, MCK_IntRegs, MCK_IntRegs }, },
  { 2825 /* sll */, Sparc::SLLrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_sll, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2825 /* sll */, Sparc::SLLri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_sll, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2829 /* sllx */, Sparc::SLLXrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_sllx, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2829 /* sllx */, Sparc::SLLXri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_sllx, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2834 /* smul */, Sparc::SMULrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_smul, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2834 /* smul */, Sparc::SMULri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_smul, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2839 /* smulcc */, Sparc::SMULCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_smulcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2839 /* smulcc */, Sparc::SMULCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_smulcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2846 /* sra */, Sparc::SRArr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_sra, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2846 /* sra */, Sparc::SRAri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_sra, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2850 /* srax */, Sparc::SRAXrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_srax, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2850 /* srax */, Sparc::SRAXri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_srax, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2855 /* srl */, Sparc::SRLrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_srl, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2855 /* srl */, Sparc::SRLri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_srl, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2859 /* srlx */, Sparc::SRLXrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_srlx, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2859 /* srlx */, Sparc::SRLXri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_srlx, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2864 /* st */, Sparc::STFSRri, Convert__MEMri2_3, 0, { MCK_st, MCK__PCT_fsr, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2864 /* st */, Sparc::STFSRrr, Convert__MEMrr2_3, 0, { MCK_st, MCK__PCT_fsr, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2864 /* st */, Sparc::STri, Convert__MEMri2_3__Reg1_1, 0, { MCK_st, MCK_IntRegs, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2864 /* st */, Sparc::STrr, Convert__MEMrr2_3__Reg1_1, 0, { MCK_st, MCK_IntRegs, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2864 /* st */, Sparc::STFri, Convert__MEMri2_3__Reg1_1, 0, { MCK_st, MCK_FPRegs, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2864 /* st */, Sparc::STFrr, Convert__MEMrr2_3__Reg1_1, 0, { MCK_st, MCK_FPRegs, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2867 /* sta */, Sparc::STArr, Convert__MEMrr2_3__Reg1_1__Imm1_5, 0, { MCK_sta, MCK_IntRegs, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm }, },
  { 2867 /* sta */, Sparc::STFArr, Convert__MEMrr2_3__Reg1_1__Imm1_5, Feature_HasV9, { MCK_sta, MCK_FPRegs, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm }, },
  { 2871 /* stb */, Sparc::STBri, Convert__MEMri2_3__Reg1_1, 0, { MCK_stb, MCK_IntRegs, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2871 /* stb */, Sparc::STBrr, Convert__MEMrr2_3__Reg1_1, 0, { MCK_stb, MCK_IntRegs, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2875 /* stba */, Sparc::STBArr, Convert__MEMrr2_3__Reg1_1__Imm1_5, 0, { MCK_stba, MCK_IntRegs, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm }, },
  { 2880 /* stbar */, Sparc::STBAR, Convert_NoOperands, 0, { MCK_stbar }, },
  { 2886 /* std */, Sparc::STDFri, Convert__MEMri2_3__Reg1_1, 0, { MCK_std, MCK_DFPRegs, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2886 /* std */, Sparc::STDFrr, Convert__MEMrr2_3__Reg1_1, 0, { MCK_std, MCK_DFPRegs, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2886 /* std */, Sparc::STDri, Convert__MEMri2_3__Reg1_1, 0, { MCK_std, MCK_IntPair, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2886 /* std */, Sparc::STDrr, Convert__MEMrr2_3__Reg1_1, 0, { MCK_std, MCK_IntPair, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2890 /* stda */, Sparc::STDFArr, Convert__MEMrr2_3__Reg1_1__Imm1_5, Feature_HasV9, { MCK_stda, MCK_DFPRegs, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm }, },
  { 2890 /* stda */, Sparc::STDArr, Convert__MEMrr2_3__Reg1_1__Imm1_5, 0, { MCK_stda, MCK_IntPair, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm }, },
  { 2895 /* sth */, Sparc::STHri, Convert__MEMri2_3__Reg1_1, 0, { MCK_sth, MCK_IntRegs, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2895 /* sth */, Sparc::STHrr, Convert__MEMrr2_3__Reg1_1, 0, { MCK_sth, MCK_IntRegs, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2899 /* stha */, Sparc::STHArr, Convert__MEMrr2_3__Reg1_1__Imm1_5, 0, { MCK_stha, MCK_IntRegs, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm }, },
  { 2904 /* stq */, Sparc::STQFri, Convert__MEMri2_3__Reg1_1, Feature_HasV9, { MCK_stq, MCK_QFPRegs, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2904 /* stq */, Sparc::STQFrr, Convert__MEMrr2_3__Reg1_1, Feature_HasV9, { MCK_stq, MCK_QFPRegs, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2908 /* stqa */, Sparc::STQFArr, Convert__MEMrr2_3__Reg1_1__Imm1_5, Feature_HasV9, { MCK_stqa, MCK_QFPRegs, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm }, },
  { 2913 /* stx */, Sparc::STXFSRri, Convert__MEMri2_3, Feature_HasV9, { MCK_stx, MCK__PCT_fsr, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2913 /* stx */, Sparc::STXFSRrr, Convert__MEMrr2_3, Feature_HasV9, { MCK_stx, MCK__PCT_fsr, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2913 /* stx */, Sparc::STXri, Convert__MEMri2_3__Reg1_1, 0, { MCK_stx, MCK_IntRegs, MCK__91_, MCK_MEMri, MCK__93_ }, },
  { 2913 /* stx */, Sparc::STXrr, Convert__MEMrr2_3__Reg1_1, 0, { MCK_stx, MCK_IntRegs, MCK__91_, MCK_MEMrr, MCK__93_ }, },
  { 2917 /* sub */, Sparc::SUBrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_sub, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2917 /* sub */, Sparc::SUBri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_sub, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2921 /* subcc */, Sparc::SUBCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_subcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2921 /* subcc */, Sparc::SUBCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_subcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2927 /* subx */, Sparc::SUBCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_subx, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2927 /* subx */, Sparc::SUBCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_subx, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2932 /* subxcc */, Sparc::SUBErr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_subxcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2932 /* subxcc */, Sparc::SUBEri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_subxcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2939 /* swap */, Sparc::SWAPri, Convert__Reg1_4__MEMri2_2__Tie0, 0, { MCK_swap, MCK__91_, MCK_MEMri, MCK__93_, MCK_IntRegs }, },
  { 2939 /* swap */, Sparc::SWAPrr, Convert__Reg1_4__MEMrr2_2__Tie0, 0, { MCK_swap, MCK__91_, MCK_MEMrr, MCK__93_, MCK_IntRegs }, },
  { 2944 /* swapa */, Sparc::SWAPArr, Convert__Reg1_5__MEMrr2_2__Imm1_4__Tie0, 0, { MCK_swapa, MCK__91_, MCK_MEMrr, MCK__93_, MCK_Imm, MCK_IntRegs }, },
  { 2950 /* t */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_8, 0, { MCK_t, MCK_IntRegs }, },
  { 2950 /* t */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_8, 0, { MCK_t, MCK_Imm }, },
  { 2950 /* t */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_8, Feature_HasV9, { MCK_t, MCK__PCT_icc, MCK_IntRegs }, },
  { 2950 /* t */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_8, Feature_HasV9, { MCK_t, MCK__PCT_icc, MCK_Imm }, },
  { 2950 /* t */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_8, Feature_HasV9, { MCK_t, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2950 /* t */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_8, Feature_HasV9, { MCK_t, MCK__PCT_xcc, MCK_Imm }, },
  { 2950 /* t */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_8, 0, { MCK_t, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2950 /* t */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_8, 0, { MCK_t, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2950 /* t */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_8, Feature_HasV9, { MCK_t, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2950 /* t */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_8, Feature_HasV9, { MCK_t, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2950 /* t */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_8, Feature_HasV9, { MCK_t, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2950 /* t */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_8, Feature_HasV9, { MCK_t, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2950 /* t */, Sparc::TICCrr, Convert__Reg1_3__Reg1_5__Imm1_1, 0, { MCK_t, MCK_Imm, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2950 /* t */, Sparc::TICCri, Convert__Reg1_3__Imm1_5__Imm1_1, 0, { MCK_t, MCK_Imm, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2950 /* t */, Sparc::TXCCrr, Convert__Reg1_3__Reg1_5__Imm1_1, 0, { MCK_t, MCK_Imm, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2950 /* t */, Sparc::TXCCri, Convert__Reg1_3__Imm1_5__Imm1_1, 0, { MCK_t, MCK_Imm, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2952 /* ta */, Sparc::TA3, Convert_NoOperands, 0, { MCK_ta, MCK_3 }, },
  { 2952 /* ta */, Sparc::TA5, Convert_NoOperands, 0, { MCK_ta, MCK_5 }, },
  { 2952 /* ta */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_8, 0, { MCK_ta, MCK_IntRegs }, },
  { 2952 /* ta */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_8, 0, { MCK_ta, MCK_Imm }, },
  { 2952 /* ta */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_8, Feature_HasV9, { MCK_ta, MCK__PCT_icc, MCK_IntRegs }, },
  { 2952 /* ta */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_8, Feature_HasV9, { MCK_ta, MCK__PCT_icc, MCK_Imm }, },
  { 2952 /* ta */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_8, Feature_HasV9, { MCK_ta, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2952 /* ta */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_8, Feature_HasV9, { MCK_ta, MCK__PCT_xcc, MCK_Imm }, },
  { 2952 /* ta */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_8, 0, { MCK_ta, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2952 /* ta */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_8, 0, { MCK_ta, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2952 /* ta */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_8, Feature_HasV9, { MCK_ta, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2952 /* ta */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_8, Feature_HasV9, { MCK_ta, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2952 /* ta */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_8, Feature_HasV9, { MCK_ta, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2952 /* ta */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_8, Feature_HasV9, { MCK_ta, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2955 /* taddcc */, Sparc::TADDCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_taddcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2955 /* taddcc */, Sparc::TADDCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_taddcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2962 /* taddcctv */, Sparc::TADDCCTVrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_taddcctv, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 2962 /* taddcctv */, Sparc::TADDCCTVri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_taddcctv, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 2971 /* tcc */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_13, 0, { MCK_tcc, MCK_IntRegs }, },
  { 2971 /* tcc */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_13, 0, { MCK_tcc, MCK_Imm }, },
  { 2971 /* tcc */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_13, Feature_HasV9, { MCK_tcc, MCK__PCT_icc, MCK_IntRegs }, },
  { 2971 /* tcc */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_13, Feature_HasV9, { MCK_tcc, MCK__PCT_icc, MCK_Imm }, },
  { 2971 /* tcc */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_13, Feature_HasV9, { MCK_tcc, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2971 /* tcc */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_13, Feature_HasV9, { MCK_tcc, MCK__PCT_xcc, MCK_Imm }, },
  { 2971 /* tcc */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_13, 0, { MCK_tcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2971 /* tcc */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_13, 0, { MCK_tcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2971 /* tcc */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_13, Feature_HasV9, { MCK_tcc, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2971 /* tcc */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_13, Feature_HasV9, { MCK_tcc, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2971 /* tcc */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_13, Feature_HasV9, { MCK_tcc, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2971 /* tcc */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_13, Feature_HasV9, { MCK_tcc, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2975 /* tcs */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_5, 0, { MCK_tcs, MCK_IntRegs }, },
  { 2975 /* tcs */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_5, 0, { MCK_tcs, MCK_Imm }, },
  { 2975 /* tcs */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_5, Feature_HasV9, { MCK_tcs, MCK__PCT_icc, MCK_IntRegs }, },
  { 2975 /* tcs */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_5, Feature_HasV9, { MCK_tcs, MCK__PCT_icc, MCK_Imm }, },
  { 2975 /* tcs */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_5, Feature_HasV9, { MCK_tcs, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2975 /* tcs */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_5, Feature_HasV9, { MCK_tcs, MCK__PCT_xcc, MCK_Imm }, },
  { 2975 /* tcs */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_5, 0, { MCK_tcs, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2975 /* tcs */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_5, 0, { MCK_tcs, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2975 /* tcs */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_5, Feature_HasV9, { MCK_tcs, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2975 /* tcs */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_5, Feature_HasV9, { MCK_tcs, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2975 /* tcs */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_5, Feature_HasV9, { MCK_tcs, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2975 /* tcs */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_5, Feature_HasV9, { MCK_tcs, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2979 /* te */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_1, 0, { MCK_te, MCK_IntRegs }, },
  { 2979 /* te */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_1, 0, { MCK_te, MCK_Imm }, },
  { 2979 /* te */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_1, Feature_HasV9, { MCK_te, MCK__PCT_icc, MCK_IntRegs }, },
  { 2979 /* te */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_1, Feature_HasV9, { MCK_te, MCK__PCT_icc, MCK_Imm }, },
  { 2979 /* te */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_1, Feature_HasV9, { MCK_te, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2979 /* te */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_1, Feature_HasV9, { MCK_te, MCK__PCT_xcc, MCK_Imm }, },
  { 2979 /* te */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_1, 0, { MCK_te, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2979 /* te */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_1, 0, { MCK_te, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2979 /* te */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_1, Feature_HasV9, { MCK_te, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2979 /* te */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_1, Feature_HasV9, { MCK_te, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2979 /* te */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_1, Feature_HasV9, { MCK_te, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2979 /* te */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_1, Feature_HasV9, { MCK_te, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2982 /* teq */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_1, 0, { MCK_teq, MCK_IntRegs }, },
  { 2982 /* teq */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_1, 0, { MCK_teq, MCK_Imm }, },
  { 2982 /* teq */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_1, Feature_HasV9, { MCK_teq, MCK__PCT_icc, MCK_IntRegs }, },
  { 2982 /* teq */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_1, Feature_HasV9, { MCK_teq, MCK__PCT_icc, MCK_Imm }, },
  { 2982 /* teq */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_1, Feature_HasV9, { MCK_teq, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2982 /* teq */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_1, Feature_HasV9, { MCK_teq, MCK__PCT_xcc, MCK_Imm }, },
  { 2982 /* teq */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_1, 0, { MCK_teq, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2982 /* teq */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_1, 0, { MCK_teq, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2982 /* teq */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_1, Feature_HasV9, { MCK_teq, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2982 /* teq */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_1, Feature_HasV9, { MCK_teq, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2982 /* teq */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_1, Feature_HasV9, { MCK_teq, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2982 /* teq */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_1, Feature_HasV9, { MCK_teq, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2986 /* tg */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_10, 0, { MCK_tg, MCK_IntRegs }, },
  { 2986 /* tg */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_10, 0, { MCK_tg, MCK_Imm }, },
  { 2986 /* tg */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_10, Feature_HasV9, { MCK_tg, MCK__PCT_icc, MCK_IntRegs }, },
  { 2986 /* tg */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_10, Feature_HasV9, { MCK_tg, MCK__PCT_icc, MCK_Imm }, },
  { 2986 /* tg */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_10, Feature_HasV9, { MCK_tg, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2986 /* tg */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_10, Feature_HasV9, { MCK_tg, MCK__PCT_xcc, MCK_Imm }, },
  { 2986 /* tg */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_10, 0, { MCK_tg, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2986 /* tg */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_10, 0, { MCK_tg, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2986 /* tg */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_10, Feature_HasV9, { MCK_tg, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2986 /* tg */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_10, Feature_HasV9, { MCK_tg, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2986 /* tg */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_10, Feature_HasV9, { MCK_tg, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2986 /* tg */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_10, Feature_HasV9, { MCK_tg, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2989 /* tge */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_11, 0, { MCK_tge, MCK_IntRegs }, },
  { 2989 /* tge */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_11, 0, { MCK_tge, MCK_Imm }, },
  { 2989 /* tge */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_11, Feature_HasV9, { MCK_tge, MCK__PCT_icc, MCK_IntRegs }, },
  { 2989 /* tge */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_11, Feature_HasV9, { MCK_tge, MCK__PCT_icc, MCK_Imm }, },
  { 2989 /* tge */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_11, Feature_HasV9, { MCK_tge, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2989 /* tge */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_11, Feature_HasV9, { MCK_tge, MCK__PCT_xcc, MCK_Imm }, },
  { 2989 /* tge */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_11, 0, { MCK_tge, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2989 /* tge */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_11, 0, { MCK_tge, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2989 /* tge */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_11, Feature_HasV9, { MCK_tge, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2989 /* tge */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_11, Feature_HasV9, { MCK_tge, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2989 /* tge */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_11, Feature_HasV9, { MCK_tge, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2989 /* tge */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_11, Feature_HasV9, { MCK_tge, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2993 /* tgeu */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_13, 0, { MCK_tgeu, MCK_IntRegs }, },
  { 2993 /* tgeu */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_13, 0, { MCK_tgeu, MCK_Imm }, },
  { 2993 /* tgeu */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_13, Feature_HasV9, { MCK_tgeu, MCK__PCT_icc, MCK_IntRegs }, },
  { 2993 /* tgeu */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_13, Feature_HasV9, { MCK_tgeu, MCK__PCT_icc, MCK_Imm }, },
  { 2993 /* tgeu */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_13, Feature_HasV9, { MCK_tgeu, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2993 /* tgeu */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_13, Feature_HasV9, { MCK_tgeu, MCK__PCT_xcc, MCK_Imm }, },
  { 2993 /* tgeu */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_13, 0, { MCK_tgeu, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2993 /* tgeu */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_13, 0, { MCK_tgeu, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2993 /* tgeu */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_13, Feature_HasV9, { MCK_tgeu, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2993 /* tgeu */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_13, Feature_HasV9, { MCK_tgeu, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2993 /* tgeu */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_13, Feature_HasV9, { MCK_tgeu, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2993 /* tgeu */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_13, Feature_HasV9, { MCK_tgeu, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2998 /* tgu */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_12, 0, { MCK_tgu, MCK_IntRegs }, },
  { 2998 /* tgu */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_12, 0, { MCK_tgu, MCK_Imm }, },
  { 2998 /* tgu */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_12, Feature_HasV9, { MCK_tgu, MCK__PCT_icc, MCK_IntRegs }, },
  { 2998 /* tgu */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_12, Feature_HasV9, { MCK_tgu, MCK__PCT_icc, MCK_Imm }, },
  { 2998 /* tgu */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_12, Feature_HasV9, { MCK_tgu, MCK__PCT_xcc, MCK_IntRegs }, },
  { 2998 /* tgu */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_12, Feature_HasV9, { MCK_tgu, MCK__PCT_xcc, MCK_Imm }, },
  { 2998 /* tgu */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_12, 0, { MCK_tgu, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2998 /* tgu */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_12, 0, { MCK_tgu, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2998 /* tgu */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_12, Feature_HasV9, { MCK_tgu, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2998 /* tgu */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_12, Feature_HasV9, { MCK_tgu, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 2998 /* tgu */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_12, Feature_HasV9, { MCK_tgu, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 2998 /* tgu */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_12, Feature_HasV9, { MCK_tgu, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3002 /* tl */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_3, 0, { MCK_tl, MCK_IntRegs }, },
  { 3002 /* tl */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_3, 0, { MCK_tl, MCK_Imm }, },
  { 3002 /* tl */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_3, Feature_HasV9, { MCK_tl, MCK__PCT_icc, MCK_IntRegs }, },
  { 3002 /* tl */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_3, Feature_HasV9, { MCK_tl, MCK__PCT_icc, MCK_Imm }, },
  { 3002 /* tl */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_3, Feature_HasV9, { MCK_tl, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3002 /* tl */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_3, Feature_HasV9, { MCK_tl, MCK__PCT_xcc, MCK_Imm }, },
  { 3002 /* tl */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_3, 0, { MCK_tl, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3002 /* tl */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_3, 0, { MCK_tl, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3002 /* tl */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_3, Feature_HasV9, { MCK_tl, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3002 /* tl */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_3, Feature_HasV9, { MCK_tl, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3002 /* tl */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_3, Feature_HasV9, { MCK_tl, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3002 /* tl */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_3, Feature_HasV9, { MCK_tl, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3005 /* tle */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_2, 0, { MCK_tle, MCK_IntRegs }, },
  { 3005 /* tle */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_2, 0, { MCK_tle, MCK_Imm }, },
  { 3005 /* tle */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_2, Feature_HasV9, { MCK_tle, MCK__PCT_icc, MCK_IntRegs }, },
  { 3005 /* tle */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_2, Feature_HasV9, { MCK_tle, MCK__PCT_icc, MCK_Imm }, },
  { 3005 /* tle */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_2, Feature_HasV9, { MCK_tle, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3005 /* tle */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_2, Feature_HasV9, { MCK_tle, MCK__PCT_xcc, MCK_Imm }, },
  { 3005 /* tle */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_2, 0, { MCK_tle, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3005 /* tle */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_2, 0, { MCK_tle, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3005 /* tle */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_2, Feature_HasV9, { MCK_tle, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3005 /* tle */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_2, Feature_HasV9, { MCK_tle, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3005 /* tle */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_2, Feature_HasV9, { MCK_tle, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3005 /* tle */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_2, Feature_HasV9, { MCK_tle, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3009 /* tleu */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_4, 0, { MCK_tleu, MCK_IntRegs }, },
  { 3009 /* tleu */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_4, 0, { MCK_tleu, MCK_Imm }, },
  { 3009 /* tleu */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_4, Feature_HasV9, { MCK_tleu, MCK__PCT_icc, MCK_IntRegs }, },
  { 3009 /* tleu */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_4, Feature_HasV9, { MCK_tleu, MCK__PCT_icc, MCK_Imm }, },
  { 3009 /* tleu */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_4, Feature_HasV9, { MCK_tleu, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3009 /* tleu */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_4, Feature_HasV9, { MCK_tleu, MCK__PCT_xcc, MCK_Imm }, },
  { 3009 /* tleu */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_4, 0, { MCK_tleu, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3009 /* tleu */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_4, 0, { MCK_tleu, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3009 /* tleu */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_4, Feature_HasV9, { MCK_tleu, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3009 /* tleu */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_4, Feature_HasV9, { MCK_tleu, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3009 /* tleu */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_4, Feature_HasV9, { MCK_tleu, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3009 /* tleu */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_4, Feature_HasV9, { MCK_tleu, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3014 /* tlu */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_5, 0, { MCK_tlu, MCK_IntRegs }, },
  { 3014 /* tlu */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_5, 0, { MCK_tlu, MCK_Imm }, },
  { 3014 /* tlu */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_5, Feature_HasV9, { MCK_tlu, MCK__PCT_icc, MCK_IntRegs }, },
  { 3014 /* tlu */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_5, Feature_HasV9, { MCK_tlu, MCK__PCT_icc, MCK_Imm }, },
  { 3014 /* tlu */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_5, Feature_HasV9, { MCK_tlu, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3014 /* tlu */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_5, Feature_HasV9, { MCK_tlu, MCK__PCT_xcc, MCK_Imm }, },
  { 3014 /* tlu */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_5, 0, { MCK_tlu, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3014 /* tlu */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_5, 0, { MCK_tlu, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3014 /* tlu */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_5, Feature_HasV9, { MCK_tlu, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3014 /* tlu */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_5, Feature_HasV9, { MCK_tlu, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3014 /* tlu */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_5, Feature_HasV9, { MCK_tlu, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3014 /* tlu */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_5, Feature_HasV9, { MCK_tlu, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3018 /* tn */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_0, 0, { MCK_tn, MCK_IntRegs }, },
  { 3018 /* tn */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_0, 0, { MCK_tn, MCK_Imm }, },
  { 3018 /* tn */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_0, Feature_HasV9, { MCK_tn, MCK__PCT_icc, MCK_IntRegs }, },
  { 3018 /* tn */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_0, Feature_HasV9, { MCK_tn, MCK__PCT_icc, MCK_Imm }, },
  { 3018 /* tn */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_0, Feature_HasV9, { MCK_tn, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3018 /* tn */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_0, Feature_HasV9, { MCK_tn, MCK__PCT_xcc, MCK_Imm }, },
  { 3018 /* tn */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_0, 0, { MCK_tn, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3018 /* tn */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_0, 0, { MCK_tn, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3018 /* tn */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_0, Feature_HasV9, { MCK_tn, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3018 /* tn */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_0, Feature_HasV9, { MCK_tn, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3018 /* tn */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_0, Feature_HasV9, { MCK_tn, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3018 /* tn */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_0, Feature_HasV9, { MCK_tn, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3021 /* tne */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_9, 0, { MCK_tne, MCK_IntRegs }, },
  { 3021 /* tne */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_9, 0, { MCK_tne, MCK_Imm }, },
  { 3021 /* tne */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_9, Feature_HasV9, { MCK_tne, MCK__PCT_icc, MCK_IntRegs }, },
  { 3021 /* tne */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_9, Feature_HasV9, { MCK_tne, MCK__PCT_icc, MCK_Imm }, },
  { 3021 /* tne */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_9, Feature_HasV9, { MCK_tne, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3021 /* tne */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_9, Feature_HasV9, { MCK_tne, MCK__PCT_xcc, MCK_Imm }, },
  { 3021 /* tne */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_9, 0, { MCK_tne, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3021 /* tne */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_9, 0, { MCK_tne, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3021 /* tne */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_9, Feature_HasV9, { MCK_tne, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3021 /* tne */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_9, Feature_HasV9, { MCK_tne, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3021 /* tne */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_9, Feature_HasV9, { MCK_tne, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3021 /* tne */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_9, Feature_HasV9, { MCK_tne, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3025 /* tneg */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_6, 0, { MCK_tneg, MCK_IntRegs }, },
  { 3025 /* tneg */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_6, 0, { MCK_tneg, MCK_Imm }, },
  { 3025 /* tneg */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_6, Feature_HasV9, { MCK_tneg, MCK__PCT_icc, MCK_IntRegs }, },
  { 3025 /* tneg */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_6, Feature_HasV9, { MCK_tneg, MCK__PCT_icc, MCK_Imm }, },
  { 3025 /* tneg */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_6, Feature_HasV9, { MCK_tneg, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3025 /* tneg */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_6, Feature_HasV9, { MCK_tneg, MCK__PCT_xcc, MCK_Imm }, },
  { 3025 /* tneg */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_6, 0, { MCK_tneg, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3025 /* tneg */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_6, 0, { MCK_tneg, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3025 /* tneg */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_6, Feature_HasV9, { MCK_tneg, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3025 /* tneg */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_6, Feature_HasV9, { MCK_tneg, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3025 /* tneg */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_6, Feature_HasV9, { MCK_tneg, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3025 /* tneg */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_6, Feature_HasV9, { MCK_tneg, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3030 /* tnz */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_9, 0, { MCK_tnz, MCK_IntRegs }, },
  { 3030 /* tnz */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_9, 0, { MCK_tnz, MCK_Imm }, },
  { 3030 /* tnz */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_9, Feature_HasV9, { MCK_tnz, MCK__PCT_icc, MCK_IntRegs }, },
  { 3030 /* tnz */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_9, Feature_HasV9, { MCK_tnz, MCK__PCT_icc, MCK_Imm }, },
  { 3030 /* tnz */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_9, Feature_HasV9, { MCK_tnz, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3030 /* tnz */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_9, Feature_HasV9, { MCK_tnz, MCK__PCT_xcc, MCK_Imm }, },
  { 3030 /* tnz */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_9, 0, { MCK_tnz, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3030 /* tnz */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_9, 0, { MCK_tnz, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3030 /* tnz */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_9, Feature_HasV9, { MCK_tnz, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3030 /* tnz */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_9, Feature_HasV9, { MCK_tnz, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3030 /* tnz */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_9, Feature_HasV9, { MCK_tnz, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3030 /* tnz */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_9, Feature_HasV9, { MCK_tnz, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3034 /* tpos */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_14, 0, { MCK_tpos, MCK_IntRegs }, },
  { 3034 /* tpos */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_14, 0, { MCK_tpos, MCK_Imm }, },
  { 3034 /* tpos */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_14, Feature_HasV9, { MCK_tpos, MCK__PCT_icc, MCK_IntRegs }, },
  { 3034 /* tpos */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_14, Feature_HasV9, { MCK_tpos, MCK__PCT_icc, MCK_Imm }, },
  { 3034 /* tpos */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_14, Feature_HasV9, { MCK_tpos, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3034 /* tpos */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_14, Feature_HasV9, { MCK_tpos, MCK__PCT_xcc, MCK_Imm }, },
  { 3034 /* tpos */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_14, 0, { MCK_tpos, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3034 /* tpos */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_14, 0, { MCK_tpos, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3034 /* tpos */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_14, Feature_HasV9, { MCK_tpos, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3034 /* tpos */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_14, Feature_HasV9, { MCK_tpos, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3034 /* tpos */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_14, Feature_HasV9, { MCK_tpos, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3034 /* tpos */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_14, Feature_HasV9, { MCK_tpos, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3039 /* tst */, Sparc::ORCCrr, Convert__regG0__Reg1_1__regG0, 0, { MCK_tst, MCK_IntRegs }, },
  { 3043 /* tsubcc */, Sparc::TSUBCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_tsubcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3043 /* tsubcc */, Sparc::TSUBCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_tsubcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3050 /* tsubcctv */, Sparc::TSUBCCTVrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_tsubcctv, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3050 /* tsubcctv */, Sparc::TSUBCCTVri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_tsubcctv, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3059 /* tvc */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_15, 0, { MCK_tvc, MCK_IntRegs }, },
  { 3059 /* tvc */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_15, 0, { MCK_tvc, MCK_Imm }, },
  { 3059 /* tvc */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_15, Feature_HasV9, { MCK_tvc, MCK__PCT_icc, MCK_IntRegs }, },
  { 3059 /* tvc */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_15, Feature_HasV9, { MCK_tvc, MCK__PCT_icc, MCK_Imm }, },
  { 3059 /* tvc */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_15, Feature_HasV9, { MCK_tvc, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3059 /* tvc */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_15, Feature_HasV9, { MCK_tvc, MCK__PCT_xcc, MCK_Imm }, },
  { 3059 /* tvc */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_15, 0, { MCK_tvc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3059 /* tvc */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_15, 0, { MCK_tvc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3059 /* tvc */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_15, Feature_HasV9, { MCK_tvc, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3059 /* tvc */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_15, Feature_HasV9, { MCK_tvc, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3059 /* tvc */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_15, Feature_HasV9, { MCK_tvc, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3059 /* tvc */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_15, Feature_HasV9, { MCK_tvc, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3063 /* tvs */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_7, 0, { MCK_tvs, MCK_IntRegs }, },
  { 3063 /* tvs */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_7, 0, { MCK_tvs, MCK_Imm }, },
  { 3063 /* tvs */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_7, Feature_HasV9, { MCK_tvs, MCK__PCT_icc, MCK_IntRegs }, },
  { 3063 /* tvs */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_7, Feature_HasV9, { MCK_tvs, MCK__PCT_icc, MCK_Imm }, },
  { 3063 /* tvs */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_7, Feature_HasV9, { MCK_tvs, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3063 /* tvs */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_7, Feature_HasV9, { MCK_tvs, MCK__PCT_xcc, MCK_Imm }, },
  { 3063 /* tvs */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_7, 0, { MCK_tvs, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3063 /* tvs */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_7, 0, { MCK_tvs, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3063 /* tvs */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_7, Feature_HasV9, { MCK_tvs, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3063 /* tvs */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_7, Feature_HasV9, { MCK_tvs, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3063 /* tvs */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_7, Feature_HasV9, { MCK_tvs, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3063 /* tvs */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_7, Feature_HasV9, { MCK_tvs, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3067 /* tz */, Sparc::TICCrr, Convert__regG0__Reg1_1__imm_95_1, 0, { MCK_tz, MCK_IntRegs }, },
  { 3067 /* tz */, Sparc::TICCri, Convert__regG0__Imm1_1__imm_95_1, 0, { MCK_tz, MCK_Imm }, },
  { 3067 /* tz */, Sparc::TICCrr, Convert__regG0__Reg1_2__imm_95_1, Feature_HasV9, { MCK_tz, MCK__PCT_icc, MCK_IntRegs }, },
  { 3067 /* tz */, Sparc::TICCri, Convert__regG0__Imm1_2__imm_95_1, Feature_HasV9, { MCK_tz, MCK__PCT_icc, MCK_Imm }, },
  { 3067 /* tz */, Sparc::TXCCrr, Convert__regG0__Reg1_2__imm_95_1, Feature_HasV9, { MCK_tz, MCK__PCT_xcc, MCK_IntRegs }, },
  { 3067 /* tz */, Sparc::TXCCri, Convert__regG0__Imm1_2__imm_95_1, Feature_HasV9, { MCK_tz, MCK__PCT_xcc, MCK_Imm }, },
  { 3067 /* tz */, Sparc::TICCrr, Convert__Reg1_1__Reg1_3__imm_95_1, 0, { MCK_tz, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3067 /* tz */, Sparc::TICCri, Convert__Reg1_1__Imm1_3__imm_95_1, 0, { MCK_tz, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3067 /* tz */, Sparc::TICCrr, Convert__Reg1_2__Reg1_4__imm_95_1, Feature_HasV9, { MCK_tz, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3067 /* tz */, Sparc::TICCri, Convert__Reg1_2__Imm1_4__imm_95_1, Feature_HasV9, { MCK_tz, MCK__PCT_icc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3067 /* tz */, Sparc::TXCCrr, Convert__Reg1_2__Reg1_4__imm_95_1, Feature_HasV9, { MCK_tz, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_IntRegs }, },
  { 3067 /* tz */, Sparc::TXCCri, Convert__Reg1_2__Imm1_4__imm_95_1, Feature_HasV9, { MCK_tz, MCK__PCT_xcc, MCK_IntRegs, MCK__43_, MCK_Imm }, },
  { 3070 /* udiv */, Sparc::UDIVrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_udiv, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3070 /* udiv */, Sparc::UDIVri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_udiv, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3075 /* udivcc */, Sparc::UDIVCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_udivcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3075 /* udivcc */, Sparc::UDIVCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_udivcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3082 /* udivx */, Sparc::UDIVXrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_udivx, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3082 /* udivx */, Sparc::UDIVXri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_udivx, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3088 /* umul */, Sparc::UMULrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_umul, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3088 /* umul */, Sparc::UMULri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_umul, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3093 /* umulcc */, Sparc::UMULCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_umulcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3093 /* umulcc */, Sparc::UMULCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_umulcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3100 /* umulxhi */, Sparc::UMULXHI, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_umulxhi, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3108 /* unimp */, Sparc::UNIMP, Convert__Imm1_1, 0, { MCK_unimp, MCK_Imm }, },
  { 3114 /* wr */, Sparc::WRPSRrr, Convert__regG0__Reg1_1, 0, { MCK_wr, MCK_IntRegs, MCK__PCT_psr }, },
  { 3114 /* wr */, Sparc::WRTBRrr, Convert__regG0__Reg1_1, 0, { MCK_wr, MCK_IntRegs, MCK__PCT_tbr }, },
  { 3114 /* wr */, Sparc::WRWIMrr, Convert__regG0__Reg1_1, 0, { MCK_wr, MCK_IntRegs, MCK__PCT_wim }, },
  { 3114 /* wr */, Sparc::WRASRrr, Convert__Reg1_2__regG0__Reg1_1, 0, { MCK_wr, MCK_IntRegs, MCK_ASRRegs }, },
  { 3114 /* wr */, Sparc::WRPSRri, Convert__regG0__Imm1_1, 0, { MCK_wr, MCK_Imm, MCK__PCT_psr }, },
  { 3114 /* wr */, Sparc::WRTBRri, Convert__regG0__Imm1_1, 0, { MCK_wr, MCK_Imm, MCK__PCT_tbr }, },
  { 3114 /* wr */, Sparc::WRWIMri, Convert__regG0__Imm1_1, 0, { MCK_wr, MCK_Imm, MCK__PCT_wim }, },
  { 3114 /* wr */, Sparc::WRASRri, Convert__Reg1_2__regG0__Imm1_1, 0, { MCK_wr, MCK_Imm, MCK_ASRRegs }, },
  { 3114 /* wr */, Sparc::WRPSRrr, Convert__Reg1_1__Reg1_2, 0, { MCK_wr, MCK_IntRegs, MCK_IntRegs, MCK__PCT_psr }, },
  { 3114 /* wr */, Sparc::WRTBRrr, Convert__Reg1_1__Reg1_2, 0, { MCK_wr, MCK_IntRegs, MCK_IntRegs, MCK__PCT_tbr }, },
  { 3114 /* wr */, Sparc::WRWIMrr, Convert__Reg1_1__Reg1_2, 0, { MCK_wr, MCK_IntRegs, MCK_IntRegs, MCK__PCT_wim }, },
  { 3114 /* wr */, Sparc::WRASRrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_wr, MCK_IntRegs, MCK_IntRegs, MCK_ASRRegs }, },
  { 3114 /* wr */, Sparc::WRPSRri, Convert__Reg1_1__Imm1_2, 0, { MCK_wr, MCK_IntRegs, MCK_Imm, MCK__PCT_psr }, },
  { 3114 /* wr */, Sparc::WRTBRri, Convert__Reg1_1__Imm1_2, 0, { MCK_wr, MCK_IntRegs, MCK_Imm, MCK__PCT_tbr }, },
  { 3114 /* wr */, Sparc::WRWIMri, Convert__Reg1_1__Imm1_2, 0, { MCK_wr, MCK_IntRegs, MCK_Imm, MCK__PCT_wim }, },
  { 3114 /* wr */, Sparc::WRASRri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_wr, MCK_IntRegs, MCK_Imm, MCK_ASRRegs }, },
  { 3117 /* wrpr */, Sparc::WRPRrr, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasV9, { MCK_wrpr, MCK_IntRegs, MCK_IntRegs, MCK_PRRegs }, },
  { 3117 /* wrpr */, Sparc::WRPRri, Convert__Reg1_3__Reg1_1__Imm1_2, Feature_HasV9, { MCK_wrpr, MCK_IntRegs, MCK_Imm, MCK_PRRegs }, },
  { 3122 /* xmulx */, Sparc::XMULX, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_xmulx, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3128 /* xmulxhi */, Sparc::XMULXHI, Convert__Reg1_3__Reg1_1__Reg1_2, Feature_HasVIS3, { MCK_xmulxhi, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3136 /* xnor */, Sparc::XNORrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_xnor, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3136 /* xnor */, Sparc::XNORri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_xnor, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3141 /* xnorcc */, Sparc::XNORCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_xnorcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3141 /* xnorcc */, Sparc::XNORCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_xnorcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3148 /* xor */, Sparc::XORrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_xor, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3148 /* xor */, Sparc::XORri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_xor, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
  { 3152 /* xorcc */, Sparc::XORCCrr, Convert__Reg1_3__Reg1_1__Reg1_2, 0, { MCK_xorcc, MCK_IntRegs, MCK_IntRegs, MCK_IntRegs }, },
  { 3152 /* xorcc */, Sparc::XORCCri, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_xorcc, MCK_IntRegs, MCK_Imm, MCK_IntRegs }, },
};

bool SparcAsmParser::
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

unsigned SparcAsmParser::
MatchInstructionImpl(const OperandVector &Operands,
                     MCInst &Inst, uint64_t &ErrorInfo,
                     bool matchingInlineAsm, unsigned VariantID) {
  // Eliminate obvious mismatches.
  if (Operands.size() > 6) {
    ErrorInfo = 6;
    return Match_InvalidOperand;
  }

  // Get the current feature set.
  uint64_t AvailableFeatures = getAvailableFeatures();

  // Get the instruction mnemonic, which is the first token.
  StringRef Mnemonic;
  if (Operands[0]->isToken())
    Mnemonic = ((SparcOperand&)*Operands[0]).getToken();

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
    for (unsigned i = SIndex; i != 6; ++i) {
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

    return Match_Success;
  }

  // Okay, we had no match.  Try to return a useful error code.
  if (HadMatchOtherThanPredicate || !HadMatchOtherThanFeatures)
    return RetCode;

  // Missing feature matches return which features were missing
  ErrorInfo = MissingFeatures;
  return Match_MissingFeature;
}

namespace {
  struct OperandMatchEntry {
    uint8_t RequiredFeatures;
    uint16_t Mnemonic;
    uint16_t Class;
    uint8_t OperandMask;

    StringRef getMnemonic() const {
      return StringRef(MnemonicTable + Mnemonic + 1,
                       MnemonicTable[Mnemonic]);
    }
  };

  // Predicate for searching for an opcode.
  struct LessOpcodeOperand {
    bool operator()(const OperandMatchEntry &LHS, StringRef RHS) {
      return LHS.getMnemonic()  < RHS;
    }
    bool operator()(StringRef LHS, const OperandMatchEntry &RHS) {
      return LHS < RHS.getMnemonic();
    }
    bool operator()(const OperandMatchEntry &LHS, const OperandMatchEntry &RHS) {
      return LHS.getMnemonic() < RHS.getMnemonic();
    }
  };
} // end anonymous namespace.

static const OperandMatchEntry OperandMatchTable[84] = {
  /* Operand List Mask, Mnemonic, Operand Class, Features */
  { 0, 252 /* call */, MCK_MEMri, 2 /* 1 */ },
  { 0, 252 /* call */, MCK_MEMrr, 2 /* 1 */ },
  { 0, 266 /* clr */, MCK_MEMri, 4 /* 2 */ },
  { 0, 266 /* clr */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 270 /* clrb */, MCK_MEMri, 4 /* 2 */ },
  { 0, 270 /* clrb */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 275 /* clrh */, MCK_MEMri, 4 /* 2 */ },
  { 0, 275 /* clrh */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 829 /* flush */, MCK_MEMri, 2 /* 1 */ },
  { 0, 829 /* flush */, MCK_MEMrr, 2 /* 1 */ },
  { 0, 2322 /* jmp */, MCK_MEMri, 2 /* 1 */ },
  { 0, 2322 /* jmp */, MCK_MEMrr, 2 /* 1 */ },
  { 0, 2326 /* jmpl */, MCK_MEMri, 2 /* 1 */ },
  { 0, 2326 /* jmpl */, MCK_MEMrr, 2 /* 1 */ },
  { 0, 2331 /* ld */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2331 /* ld */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2331 /* ld */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2331 /* ld */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2331 /* ld */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2331 /* ld */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2334 /* lda */, MCK_MEMrr, 4 /* 2 */ },
  { Feature_HasV9, 2334 /* lda */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2338 /* ldd */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2338 /* ldd */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2338 /* ldd */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2338 /* ldd */, MCK_MEMrr, 4 /* 2 */ },
  { Feature_HasV9, 2342 /* ldda */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2342 /* ldda */, MCK_MEMrr, 4 /* 2 */ },
  { Feature_HasV9, 2347 /* ldq */, MCK_MEMri, 4 /* 2 */ },
  { Feature_HasV9, 2347 /* ldq */, MCK_MEMrr, 4 /* 2 */ },
  { Feature_HasV9, 2351 /* ldqa */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2356 /* ldsb */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2356 /* ldsb */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2361 /* ldsba */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2367 /* ldsh */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2367 /* ldsh */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2372 /* ldsha */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2378 /* ldstub */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2378 /* ldstub */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2385 /* ldstuba */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2393 /* ldsw */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2393 /* ldsw */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2398 /* ldub */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2398 /* ldub */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2403 /* lduba */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2409 /* lduh */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2409 /* lduh */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2414 /* lduha */, MCK_MEMrr, 4 /* 2 */ },
  { Feature_HasV9, 2420 /* ldx */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2420 /* ldx */, MCK_MEMri, 4 /* 2 */ },
  { Feature_HasV9, 2420 /* ldx */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2420 /* ldx */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2767 /* rett */, MCK_MEMri, 2 /* 1 */ },
  { 0, 2767 /* rett */, MCK_MEMrr, 2 /* 1 */ },
  { 0, 2864 /* st */, MCK_MEMri, 8 /* 3 */ },
  { 0, 2864 /* st */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2864 /* st */, MCK_MEMri, 8 /* 3 */ },
  { 0, 2864 /* st */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2864 /* st */, MCK_MEMri, 8 /* 3 */ },
  { 0, 2864 /* st */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2867 /* sta */, MCK_MEMrr, 8 /* 3 */ },
  { Feature_HasV9, 2867 /* sta */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2871 /* stb */, MCK_MEMri, 8 /* 3 */ },
  { 0, 2871 /* stb */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2875 /* stba */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2886 /* std */, MCK_MEMri, 8 /* 3 */ },
  { 0, 2886 /* std */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2886 /* std */, MCK_MEMri, 8 /* 3 */ },
  { 0, 2886 /* std */, MCK_MEMrr, 8 /* 3 */ },
  { Feature_HasV9, 2890 /* stda */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2890 /* stda */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2895 /* sth */, MCK_MEMri, 8 /* 3 */ },
  { 0, 2895 /* sth */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2899 /* stha */, MCK_MEMrr, 8 /* 3 */ },
  { Feature_HasV9, 2904 /* stq */, MCK_MEMri, 8 /* 3 */ },
  { Feature_HasV9, 2904 /* stq */, MCK_MEMrr, 8 /* 3 */ },
  { Feature_HasV9, 2908 /* stqa */, MCK_MEMrr, 8 /* 3 */ },
  { Feature_HasV9, 2913 /* stx */, MCK_MEMri, 8 /* 3 */ },
  { Feature_HasV9, 2913 /* stx */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2913 /* stx */, MCK_MEMri, 8 /* 3 */ },
  { 0, 2913 /* stx */, MCK_MEMrr, 8 /* 3 */ },
  { 0, 2939 /* swap */, MCK_MEMri, 4 /* 2 */ },
  { 0, 2939 /* swap */, MCK_MEMrr, 4 /* 2 */ },
  { 0, 2944 /* swapa */, MCK_MEMrr, 4 /* 2 */ },
};

SparcAsmParser::OperandMatchResultTy SparcAsmParser::
tryCustomParseOperand(OperandVector &Operands,
                      unsigned MCK) {

  switch(MCK) {
  case MCK_MEMri:
    return parseMEMOperand(Operands);
  case MCK_MEMrr:
    return parseMEMOperand(Operands);
  default:
    return MatchOperand_NoMatch;
  }
  return MatchOperand_NoMatch;
}

SparcAsmParser::OperandMatchResultTy SparcAsmParser::
MatchOperandParserImpl(OperandVector &Operands,
                       StringRef Mnemonic) {
  // Get the current feature set.
  uint64_t AvailableFeatures = getAvailableFeatures();

  // Get the next operand index.
  unsigned NextOpNum = Operands.size();
  // Search the table.
  std::pair<const OperandMatchEntry*, const OperandMatchEntry*> MnemonicRange
       (OperandMatchTable, OperandMatchTable+84);
  if(!Mnemonic.empty())
    MnemonicRange = std::equal_range(OperandMatchTable, OperandMatchTable+84, Mnemonic,
                     LessOpcodeOperand());

  if (MnemonicRange.first == MnemonicRange.second)
    return MatchOperand_NoMatch;

  for (const OperandMatchEntry *it = MnemonicRange.first,
       *ie = MnemonicRange.second; it != ie; ++it) {
    // equal_range guarantees that instruction mnemonic matches.
    assert(Mnemonic == it->getMnemonic());

    // check if the available features match
    if ((AvailableFeatures & it->RequiredFeatures) != it->RequiredFeatures) {
      continue;
    }

    // check if the operand in question has a custom parser.
    if (!(it->OperandMask & (1 << NextOpNum)))
      continue;

    // call custom parse method to handle the operand
    OperandMatchResultTy Result = tryCustomParseOperand(Operands, it->Class);
    if (Result != MatchOperand_NoMatch)
      return Result;
  }

  // Okay, we had no match.
  return MatchOperand_NoMatch;
}

#endif // GET_MATCHER_IMPLEMENTATION

