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

static unsigned MatchRegisterName(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 2:	 // 10 strings to match.
    if (Name[0] != 'r')
      break;
    switch (Name[1]) {
    default: break;
    case '0':	 // 1 string to match.
      return 1;	 // "r0"
    case '1':	 // 1 string to match.
      return 2;	 // "r1"
    case '2':	 // 1 string to match.
      return 3;	 // "r2"
    case '3':	 // 1 string to match.
      return 4;	 // "r3"
    case '4':	 // 1 string to match.
      return 5;	 // "r4"
    case '5':	 // 1 string to match.
      return 6;	 // "r5"
    case '6':	 // 1 string to match.
      return 7;	 // "r6"
    case '7':	 // 1 string to match.
      return 8;	 // "r7"
    case '8':	 // 1 string to match.
      return 9;	 // "r8"
    case '9':	 // 1 string to match.
      return 10;	 // "r9"
    }
    break;
  case 3:	 // 2 strings to match.
    if (memcmp(Name.data()+0, "r1", 2))
      break;
    switch (Name[2]) {
    default: break;
    case '0':	 // 1 string to match.
      return 11;	 // "r10"
    case '1':	 // 1 string to match.
      return 12;	 // "r11"
    }
    break;
  }
  return 0;
}

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

namespace {
enum OperatorConversionKind {
  CVT_Done,
  CVT_Reg,
  CVT_Tied,
  CVT_95_Reg,
  CVT_95_addImmOperands,
  CVT_NUM_CONVERTERS
};

enum InstructionConversionKind {
  Convert__Reg1_3__Reg1_5__Reg1_7__Imm1_6__Reg1_9__Reg1_11,
  Convert__Imm1_1,
  Convert__Imm1_1__Imm1_2,
  Convert__Reg1_1__Tie0__Reg1_2,
  Convert__Reg1_1__Tie0__Imm1_2,
  Convert__Reg1_1__Tie0,
  Convert__Reg1_1__Reg1_2__Imm1_4,
  Convert__Reg1_1__Imm1_2__Imm1_4,
  Convert__Reg1_1__Imm1_2,
  Convert__Reg1_1__Imm1_2__Imm1_3,
  Convert__Reg1_2__Imm1_5,
  Convert__Reg1_1__Reg1_2__Imm1_3,
  Convert__Reg1_2__Reg1_5,
  Convert__Reg1_1__Reg1_2,
  Convert_NoOperands,
  Convert__Reg1_3__Reg1_1__Imm1_2,
  Convert__Reg1_1__Reg1_2__Imm1_3__Tie0,
  CVT_NUM_SIGNATURES
};

} // end anonymous namespace

static const uint8_t ConversionTable[CVT_NUM_SIGNATURES][13] = {
  // Convert__Reg1_3__Reg1_5__Reg1_7__Imm1_6__Reg1_9__Reg1_11
  { CVT_95_Reg, 3, CVT_95_Reg, 5, CVT_95_Reg, 7, CVT_95_addImmOperands, 6, CVT_95_Reg, 9, CVT_95_Reg, 11, CVT_Done },
  // Convert__Imm1_1
  { CVT_95_addImmOperands, 1, CVT_Done },
  // Convert__Imm1_1__Imm1_2
  { CVT_95_addImmOperands, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_1__Tie0__Reg1_2
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_Reg, 2, CVT_Done },
  // Convert__Reg1_1__Tie0__Imm1_2
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_1__Tie0
  { CVT_95_Reg, 1, CVT_Tied, 0, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Imm1_4
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_1__Imm1_2__Imm1_4
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 4, CVT_Done },
  // Convert__Reg1_1__Imm1_2
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_1__Imm1_2__Imm1_3
  { CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_2__Imm1_5
  { CVT_95_Reg, 2, CVT_95_addImmOperands, 5, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Imm1_3
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Done },
  // Convert__Reg1_2__Reg1_5
  { CVT_95_Reg, 2, CVT_95_Reg, 5, CVT_Done },
  // Convert__Reg1_1__Reg1_2
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_Done },
  // Convert_NoOperands
  { CVT_Done },
  // Convert__Reg1_3__Reg1_1__Imm1_2
  { CVT_95_Reg, 3, CVT_95_Reg, 1, CVT_95_addImmOperands, 2, CVT_Done },
  // Convert__Reg1_1__Reg1_2__Imm1_3__Tie0
  { CVT_95_Reg, 1, CVT_95_Reg, 2, CVT_95_addImmOperands, 3, CVT_Tied, 0, CVT_Done },
};

void BPFAsmParser::
convertToMCInst(unsigned Kind, MCInst &Inst, unsigned Opcode,
                const OperandVector &Operands) {
  assert(Kind < CVT_NUM_SIGNATURES && "Invalid signature!");
  const uint8_t *Converter = ConversionTable[Kind];
  Inst.setOpcode(Opcode);
  for (const uint8_t *p = Converter; *p; p+= 2) {
    switch (*p) {
    default: llvm_unreachable("invalid conversion entry!");
    case CVT_Reg:
      static_cast<BPFOperand&>(*Operands[*(p + 1)]).addRegOperands(Inst, 1);
      break;
    case CVT_Tied:
      Inst.addOperand(Inst.getOperand(*(p + 1)));
      break;
    case CVT_95_Reg:
      static_cast<BPFOperand&>(*Operands[*(p + 1)]).addRegOperands(Inst, 1);
      break;
    case CVT_95_addImmOperands:
      static_cast<BPFOperand&>(*Operands[*(p + 1)]).addImmOperands(Inst, 1);
      break;
    }
  }
}

void BPFAsmParser::
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
    }
  }
}

namespace {

/// MatchClassKind - The kinds of classes which participate in
/// instruction matching.
enum MatchClassKind {
  InvalidMatchClass = 0,
  MCK__35_, // '#'
  MCK__35_ADJCALLSTACKDOWN, // '#ADJCALLSTACKDOWN'
  MCK__35_ADJCALLSTACKUP, // '#ADJCALLSTACKUP'
  MCK__43_, // '+'
  MCK__DOT_data, // '.data'
  MCK__COLON_, // ':'
  MCK__61_, // '='
  MCK__63_, // '?'
  MCK_PSEUDO, // 'PSEUDO'
  MCK_Select, // 'Select'
  MCK_add, // 'add'
  MCK_addi, // 'addi'
  MCK_and, // 'and'
  MCK_andi, // 'andi'
  MCK_bswap16, // 'bswap16'
  MCK_bswap32, // 'bswap32'
  MCK_bswap64, // 'bswap64'
  MCK_call, // 'call'
  MCK_div, // 'div'
  MCK_divi, // 'divi'
  MCK_goto, // 'goto'
  MCK_jeq, // 'jeq'
  MCK_jeqi, // 'jeqi'
  MCK_jge, // 'jge'
  MCK_jgei, // 'jgei'
  MCK_jgt, // 'jgt'
  MCK_jgti, // 'jgti'
  MCK_jmp, // 'jmp'
  MCK_jne, // 'jne'
  MCK_jnei, // 'jnei'
  MCK_jsge, // 'jsge'
  MCK_jsgei, // 'jsgei'
  MCK_jsgt, // 'jsgt'
  MCK_jsgti, // 'jsgti'
  MCK_ld_95_64, // 'ld_64'
  MCK_ld_95_pseudo, // 'ld_pseudo'
  MCK_ldabs_95_b, // 'ldabs_b'
  MCK_ldabs_95_h, // 'ldabs_h'
  MCK_ldabs_95_w, // 'ldabs_w'
  MCK_ldb, // 'ldb'
  MCK_ldd, // 'ldd'
  MCK_ldh, // 'ldh'
  MCK_ldind_95_b, // 'ldind_b'
  MCK_ldind_95_h, // 'ldind_h'
  MCK_ldind_95_w, // 'ldind_w'
  MCK_ldw, // 'ldw'
  MCK_lea, // 'lea'
  MCK_mov, // 'mov'
  MCK_mul, // 'mul'
  MCK_muli, // 'muli'
  MCK_nop, // 'nop'
  MCK_or, // 'or'
  MCK_ori, // 'ori'
  MCK_ret, // 'ret'
  MCK_sll, // 'sll'
  MCK_slli, // 'slli'
  MCK_sra, // 'sra'
  MCK_srai, // 'srai'
  MCK_srl, // 'srl'
  MCK_srli, // 'srli'
  MCK_stb, // 'stb'
  MCK_std, // 'std'
  MCK_sth, // 'sth'
  MCK_stw, // 'stw'
  MCK_sub, // 'sub'
  MCK_subi, // 'subi'
  MCK_xadd32, // 'xadd32'
  MCK_xadd64, // 'xadd64'
  MCK_xor, // 'xor'
  MCK_xori, // 'xori'
  MCK_R0, // register class 'R0'
  MCK_GPR, // register class 'GPR'
  MCK_Imm, // user defined class 'ImmAsmOperand'
  NumMatchClassKinds
};

}

static MatchClassKind matchTokenString(StringRef Name) {
  switch (Name.size()) {
  default: break;
  case 1:	 // 5 strings to match.
    switch (Name[0]) {
    default: break;
    case '#':	 // 1 string to match.
      return MCK__35_;	 // "#"
    case '+':	 // 1 string to match.
      return MCK__43_;	 // "+"
    case ':':	 // 1 string to match.
      return MCK__COLON_;	 // ":"
    case '=':	 // 1 string to match.
      return MCK__61_;	 // "="
    case '?':	 // 1 string to match.
      return MCK__63_;	 // "?"
    }
    break;
  case 2:	 // 1 string to match.
    if (memcmp(Name.data()+0, "or", 2))
      break;
    return MCK_or;	 // "or"
  case 3:	 // 27 strings to match.
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
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "iv", 2))
        break;
      return MCK_div;	 // "div"
    case 'j':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (Name[2] != 'q')
          break;
        return MCK_jeq;	 // "jeq"
      case 'g':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_jge;	 // "jge"
        case 't':	 // 1 string to match.
          return MCK_jgt;	 // "jgt"
        }
        break;
      case 'm':	 // 1 string to match.
        if (Name[2] != 'p')
          break;
        return MCK_jmp;	 // "jmp"
      case 'n':	 // 1 string to match.
        if (Name[2] != 'e')
          break;
        return MCK_jne;	 // "jne"
      }
      break;
    case 'l':	 // 5 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 4 strings to match.
        switch (Name[2]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_ldb;	 // "ldb"
        case 'd':	 // 1 string to match.
          return MCK_ldd;	 // "ldd"
        case 'h':	 // 1 string to match.
          return MCK_ldh;	 // "ldh"
        case 'w':	 // 1 string to match.
          return MCK_ldw;	 // "ldw"
        }
        break;
      case 'e':	 // 1 string to match.
        if (Name[2] != 'a')
          break;
        return MCK_lea;	 // "lea"
      }
      break;
    case 'm':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'o':	 // 1 string to match.
        if (Name[2] != 'v')
          break;
        return MCK_mov;	 // "mov"
      case 'u':	 // 1 string to match.
        if (Name[2] != 'l')
          break;
        return MCK_mul;	 // "mul"
      }
      break;
    case 'n':	 // 1 string to match.
      if (memcmp(Name.data()+1, "op", 2))
        break;
      return MCK_nop;	 // "nop"
    case 'o':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ri", 2))
        break;
      return MCK_ori;	 // "ori"
    case 'r':	 // 1 string to match.
      if (memcmp(Name.data()+1, "et", 2))
        break;
      return MCK_ret;	 // "ret"
    case 's':	 // 8 strings to match.
      switch (Name[1]) {
      default: break;
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
    case 'x':	 // 1 string to match.
      if (memcmp(Name.data()+1, "or", 2))
        break;
      return MCK_xor;	 // "xor"
    }
    break;
  case 4:	 // 17 strings to match.
    switch (Name[0]) {
    default: break;
    case 'a':	 // 2 strings to match.
      switch (Name[1]) {
      default: break;
      case 'd':	 // 1 string to match.
        if (memcmp(Name.data()+2, "di", 2))
          break;
        return MCK_addi;	 // "addi"
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "di", 2))
          break;
        return MCK_andi;	 // "andi"
      }
      break;
    case 'c':	 // 1 string to match.
      if (memcmp(Name.data()+1, "all", 3))
        break;
      return MCK_call;	 // "call"
    case 'd':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ivi", 3))
        break;
      return MCK_divi;	 // "divi"
    case 'g':	 // 1 string to match.
      if (memcmp(Name.data()+1, "oto", 3))
        break;
      return MCK_goto;	 // "goto"
    case 'j':	 // 6 strings to match.
      switch (Name[1]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(Name.data()+2, "qi", 2))
          break;
        return MCK_jeqi;	 // "jeqi"
      case 'g':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_jgei;	 // "jgei"
        case 't':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_jgti;	 // "jgti"
        }
        break;
      case 'n':	 // 1 string to match.
        if (memcmp(Name.data()+2, "ei", 2))
          break;
        return MCK_jnei;	 // "jnei"
      case 's':	 // 2 strings to match.
        if (Name[2] != 'g')
          break;
        switch (Name[3]) {
        default: break;
        case 'e':	 // 1 string to match.
          return MCK_jsge;	 // "jsge"
        case 't':	 // 1 string to match.
          return MCK_jsgt;	 // "jsgt"
        }
        break;
      }
      break;
    case 'm':	 // 1 string to match.
      if (memcmp(Name.data()+1, "uli", 3))
        break;
      return MCK_muli;	 // "muli"
    case 's':	 // 4 strings to match.
      switch (Name[1]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(Name.data()+2, "li", 2))
          break;
        return MCK_slli;	 // "slli"
      case 'r':	 // 2 strings to match.
        switch (Name[2]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_srai;	 // "srai"
        case 'l':	 // 1 string to match.
          if (Name[3] != 'i')
            break;
          return MCK_srli;	 // "srli"
        }
        break;
      case 'u':	 // 1 string to match.
        if (memcmp(Name.data()+2, "bi", 2))
          break;
        return MCK_subi;	 // "subi"
      }
      break;
    case 'x':	 // 1 string to match.
      if (memcmp(Name.data()+1, "ori", 3))
        break;
      return MCK_xori;	 // "xori"
    }
    break;
  case 5:	 // 4 strings to match.
    switch (Name[0]) {
    default: break;
    case '.':	 // 1 string to match.
      if (memcmp(Name.data()+1, "data", 4))
        break;
      return MCK__DOT_data;	 // ".data"
    case 'j':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "sg", 2))
        break;
      switch (Name[3]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (Name[4] != 'i')
          break;
        return MCK_jsgei;	 // "jsgei"
      case 't':	 // 1 string to match.
        if (Name[4] != 'i')
          break;
        return MCK_jsgti;	 // "jsgti"
      }
      break;
    case 'l':	 // 1 string to match.
      if (memcmp(Name.data()+1, "d_64", 4))
        break;
      return MCK_ld_95_64;	 // "ld_64"
    }
    break;
  case 6:	 // 4 strings to match.
    switch (Name[0]) {
    default: break;
    case 'P':	 // 1 string to match.
      if (memcmp(Name.data()+1, "SEUDO", 5))
        break;
      return MCK_PSEUDO;	 // "PSEUDO"
    case 'S':	 // 1 string to match.
      if (memcmp(Name.data()+1, "elect", 5))
        break;
      return MCK_Select;	 // "Select"
    case 'x':	 // 2 strings to match.
      if (memcmp(Name.data()+1, "add", 3))
        break;
      switch (Name[4]) {
      default: break;
      case '3':	 // 1 string to match.
        if (Name[5] != '2')
          break;
        return MCK_xadd32;	 // "xadd32"
      case '6':	 // 1 string to match.
        if (Name[5] != '4')
          break;
        return MCK_xadd64;	 // "xadd64"
      }
      break;
    }
    break;
  case 7:	 // 9 strings to match.
    switch (Name[0]) {
    default: break;
    case 'b':	 // 3 strings to match.
      if (memcmp(Name.data()+1, "swap", 4))
        break;
      switch (Name[5]) {
      default: break;
      case '1':	 // 1 string to match.
        if (Name[6] != '6')
          break;
        return MCK_bswap16;	 // "bswap16"
      case '3':	 // 1 string to match.
        if (Name[6] != '2')
          break;
        return MCK_bswap32;	 // "bswap32"
      case '6':	 // 1 string to match.
        if (Name[6] != '4')
          break;
        return MCK_bswap64;	 // "bswap64"
      }
      break;
    case 'l':	 // 6 strings to match.
      if (Name[1] != 'd')
        break;
      switch (Name[2]) {
      default: break;
      case 'a':	 // 3 strings to match.
        if (memcmp(Name.data()+3, "bs_", 3))
          break;
        switch (Name[6]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_ldabs_95_b;	 // "ldabs_b"
        case 'h':	 // 1 string to match.
          return MCK_ldabs_95_h;	 // "ldabs_h"
        case 'w':	 // 1 string to match.
          return MCK_ldabs_95_w;	 // "ldabs_w"
        }
        break;
      case 'i':	 // 3 strings to match.
        if (memcmp(Name.data()+3, "nd_", 3))
          break;
        switch (Name[6]) {
        default: break;
        case 'b':	 // 1 string to match.
          return MCK_ldind_95_b;	 // "ldind_b"
        case 'h':	 // 1 string to match.
          return MCK_ldind_95_h;	 // "ldind_h"
        case 'w':	 // 1 string to match.
          return MCK_ldind_95_w;	 // "ldind_w"
        }
        break;
      }
      break;
    }
    break;
  case 9:	 // 1 string to match.
    if (memcmp(Name.data()+0, "ld_pseudo", 9))
      break;
    return MCK_ld_95_pseudo;	 // "ld_pseudo"
  case 15:	 // 1 string to match.
    if (memcmp(Name.data()+0, "#ADJCALLSTACKUP", 15))
      break;
    return MCK__35_ADJCALLSTACKUP;	 // "#ADJCALLSTACKUP"
  case 17:	 // 1 string to match.
    if (memcmp(Name.data()+0, "#ADJCALLSTACKDOWN", 17))
      break;
    return MCK__35_ADJCALLSTACKDOWN;	 // "#ADJCALLSTACKDOWN"
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

  case MCK_R0:
    return B == MCK_GPR;
  }
}

static unsigned validateOperandClass(MCParsedAsmOperand &GOp, MatchClassKind Kind) {
  BPFOperand &Operand = (BPFOperand&)GOp;
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

  if (Operand.isReg()) {
    MatchClassKind OpKind;
    switch (Operand.getReg()) {
    default: OpKind = InvalidMatchClass; break;
    case BPF::R0: OpKind = MCK_R0; break;
    case BPF::R1: OpKind = MCK_GPR; break;
    case BPF::R2: OpKind = MCK_GPR; break;
    case BPF::R3: OpKind = MCK_GPR; break;
    case BPF::R4: OpKind = MCK_GPR; break;
    case BPF::R5: OpKind = MCK_GPR; break;
    case BPF::R6: OpKind = MCK_GPR; break;
    case BPF::R7: OpKind = MCK_GPR; break;
    case BPF::R8: OpKind = MCK_GPR; break;
    case BPF::R9: OpKind = MCK_GPR; break;
    case BPF::R10: OpKind = MCK_GPR; break;
    case BPF::R11: OpKind = MCK_GPR; break;
    }
    return isSubclass(OpKind, Kind) ? MCTargetAsmParser::Match_Success :
                                      MCTargetAsmParser::Match_InvalidOperand;
  }

  return MCTargetAsmParser::Match_InvalidOperand;
}

uint64_t BPFAsmParser::
ComputeAvailableFeatures(const FeatureBitset& FB) const {
  uint64_t Features = 0;
  return Features;
}

static const char *const MnemonicTable =
    "\001#\021#ADJCALLSTACKDOWN\017#ADJCALLSTACKUP\003add\004addi\003and\004"
    "andi\007bswap16\007bswap32\007bswap64\004call\003div\004divi\003jeq\004"
    "jeqi\003jge\004jgei\003jgt\004jgti\003jmp\003jne\004jnei\004jsge\005jsg"
    "ei\004jsgt\005jsgti\005ld_64\tld_pseudo\007ldabs_b\007ldabs_h\007ldabs_"
    "w\003ldb\003ldd\003ldh\007ldind_b\007ldind_h\007ldind_w\003ldw\003lea\003"
    "mov\003mul\004muli\003nop\002or\003ori\003ret\003sll\004slli\003sra\004"
    "srai\003srl\004srli\003stb\003std\003sth\003stw\003sub\004subi\006xadd3"
    "2\006xadd64\003xor\004xori";

namespace {
  struct MatchEntry {
    uint16_t Mnemonic;
    uint16_t Opcode;
    uint8_t ConvertFn;
    uint8_t RequiredFeatures;
    uint8_t Classes[12];
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
  { 0 /* # */, BPF::Select, Convert__Reg1_3__Reg1_5__Reg1_7__Imm1_6__Reg1_9__Reg1_11, 0, { MCK__35_, MCK_Select, MCK_PSEUDO, MCK_GPR, MCK__61_, MCK_GPR, MCK_Imm, MCK_GPR, MCK__63_, MCK_GPR, MCK__COLON_, MCK_GPR }, },
  { 2 /* #ADJCALLSTACKDOWN */, BPF::ADJCALLSTACKDOWN, Convert__Imm1_1, 0, { MCK__35_ADJCALLSTACKDOWN, MCK_Imm }, },
  { 20 /* #ADJCALLSTACKUP */, BPF::ADJCALLSTACKUP, Convert__Imm1_1__Imm1_2, 0, { MCK__35_ADJCALLSTACKUP, MCK_Imm, MCK_Imm }, },
  { 36 /* add */, BPF::ADD_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_add, MCK_GPR, MCK_GPR }, },
  { 40 /* addi */, BPF::ADD_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_addi, MCK_GPR, MCK_Imm }, },
  { 45 /* and */, BPF::AND_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_and, MCK_GPR, MCK_GPR }, },
  { 49 /* andi */, BPF::AND_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_andi, MCK_GPR, MCK_Imm }, },
  { 54 /* bswap16 */, BPF::BSWAP16, Convert__Reg1_1__Tie0, 0, { MCK_bswap16, MCK_GPR }, },
  { 62 /* bswap32 */, BPF::BSWAP32, Convert__Reg1_1__Tie0, 0, { MCK_bswap32, MCK_GPR }, },
  { 70 /* bswap64 */, BPF::BSWAP64, Convert__Reg1_1__Tie0, 0, { MCK_bswap64, MCK_GPR }, },
  { 78 /* call */, BPF::JAL, Convert__Imm1_1, 0, { MCK_call, MCK_Imm }, },
  { 83 /* div */, BPF::DIV_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_div, MCK_GPR, MCK_GPR }, },
  { 87 /* divi */, BPF::DIV_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_divi, MCK_GPR, MCK_Imm }, },
  { 92 /* jeq */, BPF::JEQ_rr, Convert__Reg1_1__Reg1_2__Imm1_4, 0, { MCK_jeq, MCK_GPR, MCK_GPR, MCK_goto, MCK_Imm }, },
  { 96 /* jeqi */, BPF::JEQ_ri, Convert__Reg1_1__Imm1_2__Imm1_4, 0, { MCK_jeqi, MCK_GPR, MCK_Imm, MCK_goto, MCK_Imm }, },
  { 101 /* jge */, BPF::JUGE_rr, Convert__Reg1_1__Reg1_2__Imm1_4, 0, { MCK_jge, MCK_GPR, MCK_GPR, MCK_goto, MCK_Imm }, },
  { 105 /* jgei */, BPF::JUGE_ri, Convert__Reg1_1__Imm1_2__Imm1_4, 0, { MCK_jgei, MCK_GPR, MCK_Imm, MCK_goto, MCK_Imm }, },
  { 110 /* jgt */, BPF::JUGT_rr, Convert__Reg1_1__Reg1_2__Imm1_4, 0, { MCK_jgt, MCK_GPR, MCK_GPR, MCK_goto, MCK_Imm }, },
  { 114 /* jgti */, BPF::JUGT_ri, Convert__Reg1_1__Imm1_2__Imm1_4, 0, { MCK_jgti, MCK_GPR, MCK_Imm, MCK_goto, MCK_Imm }, },
  { 119 /* jmp */, BPF::JMP, Convert__Imm1_1, 0, { MCK_jmp, MCK_Imm }, },
  { 123 /* jne */, BPF::JNE_rr, Convert__Reg1_1__Reg1_2__Imm1_4, 0, { MCK_jne, MCK_GPR, MCK_GPR, MCK_goto, MCK_Imm }, },
  { 127 /* jnei */, BPF::JNE_ri, Convert__Reg1_1__Imm1_2__Imm1_4, 0, { MCK_jnei, MCK_GPR, MCK_Imm, MCK_goto, MCK_Imm }, },
  { 132 /* jsge */, BPF::JSGE_rr, Convert__Reg1_1__Reg1_2__Imm1_4, 0, { MCK_jsge, MCK_GPR, MCK_GPR, MCK_goto, MCK_Imm }, },
  { 137 /* jsgei */, BPF::JSGE_ri, Convert__Reg1_1__Imm1_2__Imm1_4, 0, { MCK_jsgei, MCK_GPR, MCK_Imm, MCK_goto, MCK_Imm }, },
  { 143 /* jsgt */, BPF::JSGT_rr, Convert__Reg1_1__Reg1_2__Imm1_4, 0, { MCK_jsgt, MCK_GPR, MCK_GPR, MCK_goto, MCK_Imm }, },
  { 148 /* jsgti */, BPF::JSGT_ri, Convert__Reg1_1__Imm1_2__Imm1_4, 0, { MCK_jsgti, MCK_GPR, MCK_Imm, MCK_goto, MCK_Imm }, },
  { 154 /* ld_64 */, BPF::LD_imm64, Convert__Reg1_1__Imm1_2, 0, { MCK_ld_95_64, MCK_GPR, MCK_Imm }, },
  { 160 /* ld_pseudo */, BPF::LD_pseudo, Convert__Reg1_1__Imm1_2__Imm1_3, 0, { MCK_ld_95_pseudo, MCK_GPR, MCK_Imm, MCK_Imm }, },
  { 170 /* ldabs_b */, BPF::LD_ABS_B, Convert__Reg1_2__Imm1_5, 0, { MCK_ldabs_95_b, MCK_R0, MCK_GPR, MCK__DOT_data, MCK__43_, MCK_Imm }, },
  { 178 /* ldabs_h */, BPF::LD_ABS_H, Convert__Reg1_2__Imm1_5, 0, { MCK_ldabs_95_h, MCK_R0, MCK_GPR, MCK__DOT_data, MCK__43_, MCK_Imm }, },
  { 186 /* ldabs_w */, BPF::LD_ABS_W, Convert__Reg1_2__Imm1_5, 0, { MCK_ldabs_95_w, MCK_R0, MCK_GPR, MCK__DOT_data, MCK__43_, MCK_Imm }, },
  { 194 /* ldb */, BPF::LDB, Convert__Reg1_1__Reg1_2__Imm1_3, 0, { MCK_ldb, MCK_GPR, MCK_GPR, MCK_Imm }, },
  { 198 /* ldd */, BPF::LDD, Convert__Reg1_1__Reg1_2__Imm1_3, 0, { MCK_ldd, MCK_GPR, MCK_GPR, MCK_Imm }, },
  { 202 /* ldh */, BPF::LDH, Convert__Reg1_1__Reg1_2__Imm1_3, 0, { MCK_ldh, MCK_GPR, MCK_GPR, MCK_Imm }, },
  { 206 /* ldind_b */, BPF::LD_IND_B, Convert__Reg1_2__Reg1_5, 0, { MCK_ldind_95_b, MCK_R0, MCK_GPR, MCK__DOT_data, MCK__43_, MCK_GPR }, },
  { 214 /* ldind_h */, BPF::LD_IND_H, Convert__Reg1_2__Reg1_5, 0, { MCK_ldind_95_h, MCK_R0, MCK_GPR, MCK__DOT_data, MCK__43_, MCK_GPR }, },
  { 222 /* ldind_w */, BPF::LD_IND_W, Convert__Reg1_2__Reg1_5, 0, { MCK_ldind_95_w, MCK_R0, MCK_GPR, MCK__DOT_data, MCK__43_, MCK_GPR }, },
  { 230 /* ldw */, BPF::LDW, Convert__Reg1_1__Reg1_2__Imm1_3, 0, { MCK_ldw, MCK_GPR, MCK_GPR, MCK_Imm }, },
  { 234 /* lea */, BPF::FI_ri, Convert__Reg1_1__Reg1_2__Imm1_3, 0, { MCK_lea, MCK_GPR, MCK_GPR, MCK_Imm }, },
  { 238 /* mov */, BPF::MOV_rr, Convert__Reg1_1__Reg1_2, 0, { MCK_mov, MCK_GPR, MCK_GPR }, },
  { 238 /* mov */, BPF::MOV_ri, Convert__Reg1_1__Imm1_2, 0, { MCK_mov, MCK_GPR, MCK_Imm }, },
  { 242 /* mul */, BPF::MUL_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_mul, MCK_GPR, MCK_GPR }, },
  { 246 /* muli */, BPF::MUL_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_muli, MCK_GPR, MCK_Imm }, },
  { 251 /* nop */, BPF::NOP, Convert__Imm1_1, 0, { MCK_nop, MCK_Imm }, },
  { 255 /* or */, BPF::OR_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_or, MCK_GPR, MCK_GPR }, },
  { 258 /* ori */, BPF::OR_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_ori, MCK_GPR, MCK_Imm }, },
  { 262 /* ret */, BPF::RET, Convert_NoOperands, 0, { MCK_ret }, },
  { 266 /* sll */, BPF::SLL_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_sll, MCK_GPR, MCK_GPR }, },
  { 270 /* slli */, BPF::SLL_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_slli, MCK_GPR, MCK_Imm }, },
  { 275 /* sra */, BPF::SRA_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_sra, MCK_GPR, MCK_GPR }, },
  { 279 /* srai */, BPF::SRA_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_srai, MCK_GPR, MCK_Imm }, },
  { 284 /* srl */, BPF::SRL_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_srl, MCK_GPR, MCK_GPR }, },
  { 288 /* srli */, BPF::SRL_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_srli, MCK_GPR, MCK_Imm }, },
  { 293 /* stb */, BPF::STB, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_stb, MCK_GPR, MCK_Imm, MCK_GPR }, },
  { 297 /* std */, BPF::STD, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_std, MCK_GPR, MCK_Imm, MCK_GPR }, },
  { 301 /* sth */, BPF::STH, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_sth, MCK_GPR, MCK_Imm, MCK_GPR }, },
  { 305 /* stw */, BPF::STW, Convert__Reg1_3__Reg1_1__Imm1_2, 0, { MCK_stw, MCK_GPR, MCK_Imm, MCK_GPR }, },
  { 309 /* sub */, BPF::SUB_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_sub, MCK_GPR, MCK_GPR }, },
  { 313 /* subi */, BPF::SUB_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_subi, MCK_GPR, MCK_Imm }, },
  { 318 /* xadd32 */, BPF::XADD32, Convert__Reg1_1__Reg1_2__Imm1_3__Tie0, 0, { MCK_xadd32, MCK_GPR, MCK_GPR, MCK_Imm, MCK_GPR }, },
  { 325 /* xadd64 */, BPF::XADD64, Convert__Reg1_1__Reg1_2__Imm1_3__Tie0, 0, { MCK_xadd64, MCK_GPR, MCK_GPR, MCK_Imm, MCK_GPR }, },
  { 332 /* xor */, BPF::XOR_rr, Convert__Reg1_1__Tie0__Reg1_2, 0, { MCK_xor, MCK_GPR, MCK_GPR }, },
  { 336 /* xori */, BPF::XOR_ri, Convert__Reg1_1__Tie0__Imm1_2, 0, { MCK_xori, MCK_GPR, MCK_Imm }, },
};

bool BPFAsmParser::
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

unsigned BPFAsmParser::
MatchInstructionImpl(const OperandVector &Operands,
                     MCInst &Inst, uint64_t &ErrorInfo,
                     bool matchingInlineAsm, unsigned VariantID) {
  // Eliminate obvious mismatches.
  if (Operands.size() > 12) {
    ErrorInfo = 12;
    return Match_InvalidOperand;
  }

  // Get the current feature set.
  uint64_t AvailableFeatures = getAvailableFeatures();

  // Get the instruction mnemonic, which is the first token.
  StringRef Mnemonic;
  if (Operands[0]->isToken())
    Mnemonic = ((BPFOperand&)*Operands[0]).getToken();

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
    for (unsigned i = SIndex; i != 12; ++i) {
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

#endif // GET_MATCHER_IMPLEMENTATION

