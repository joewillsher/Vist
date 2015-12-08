/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Machine Code Emitter                                                       *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

uint64_t BPFMCCodeEmitter::getBinaryCodeForInstr(const MCInst &MI,
    SmallVectorImpl<MCFixup> &Fixups,
    const MCSubtargetInfo &STI) const {
  static const uint64_t InstBits[] = {
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(504403158265495552),	// ADD_ri
    UINT64_C(1080863910568919040),	// ADD_rr
    UINT64_C(0),
    UINT64_C(0),
    UINT64_C(6269010681299730432),	// AND_ri
    UINT64_C(6845471433603153920),	// AND_rr
    UINT64_C(15852670688344145936),	// BSWAP16
    UINT64_C(15852670688344145952),	// BSWAP32
    UINT64_C(15852670688344145984),	// BSWAP64
    UINT64_C(3963167672086036480),	// DIV_ri
    UINT64_C(4539628424389459968),	// DIV_rr
    UINT64_C(0),	// FI_ri
    UINT64_C(9583660007044415488),	// JAL
    UINT64_C(1513209474796486656),	// JEQ_ri
    UINT64_C(2089670227099910144),	// JEQ_rr
    UINT64_C(360287970189639680),	// JMP
    UINT64_C(6124895493223874560),	// JNE_ri
    UINT64_C(6701356245527298048),	// JNE_rr
    UINT64_C(8430738502437568512),	// JSGE_ri
    UINT64_C(9007199254740992000),	// JSGE_rr
    UINT64_C(7277816997830721536),	// JSGT_ri
    UINT64_C(7854277750134145024),	// JSGT_rr
    UINT64_C(3819052484010180608),	// JUGE_ri
    UINT64_C(4395513236313604096),	// JUGE_rr
    UINT64_C(2666130979403333632),	// JUGT_ri
    UINT64_C(3242591731706757120),	// JUGT_rr
    UINT64_C(8142508126285856768),	// LDB
    UINT64_C(8718968878589280256),	// LDD
    UINT64_C(7566047373982433280),	// LDH
    UINT64_C(6989586621679009792),	// LDW
    UINT64_C(3458764513820540928),	// LD_ABS_B
    UINT64_C(2882303761517117440),	// LD_ABS_H
    UINT64_C(2305843009213693952),	// LD_ABS_W
    UINT64_C(5764607523034234880),	// LD_IND_B
    UINT64_C(5188146770730811392),	// LD_IND_H
    UINT64_C(4611686018427387904),	// LD_IND_W
    UINT64_C(1729382256910270464),	// LD_imm64
    UINT64_C(1729382256910270464),	// LD_pseudo
    UINT64_C(13186539708940812288),	// MOV_ri
    UINT64_C(13763000461244235776),	// MOV_rr
    UINT64_C(2810246167479189504),	// MUL_ri
    UINT64_C(3386706919782612992),	// MUL_rr
    UINT64_C(13763000461244235776),	// NOP
    UINT64_C(5116089176692883456),	// OR_ri
    UINT64_C(5692549928996306944),	// OR_rr
    UINT64_C(10736581511651262464),	// RET
    UINT64_C(7421932185906577408),	// SLL_ri
    UINT64_C(7998392938210000896),	// SLL_rr
    UINT64_C(14339461213547659264),	// SRA_ri
    UINT64_C(14915921965851082752),	// SRA_rr
    UINT64_C(8574853690513424384),	// SRL_ri
    UINT64_C(9151314442816847872),	// SRL_rr
    UINT64_C(8286623314361712640),	// STB
    UINT64_C(8863084066665136128),	// STD
    UINT64_C(7710162562058289152),	// STH
    UINT64_C(7133701809754865664),	// STW
    UINT64_C(1657324662872342528),	// SUB_ri
    UINT64_C(2233785415175766016),	// SUB_rr
    UINT64_C(0),
    UINT64_C(14051230837395947520),	// XADD32
    UINT64_C(15780613094306217984),	// XADD64
    UINT64_C(12033618204333965312),	// XOR_ri
    UINT64_C(12610078956637388800),	// XOR_rr
    UINT64_C(0)
  };
  const unsigned opcode = MI.getOpcode();
  uint64_t Value = InstBits[opcode];
  uint64_t op = 0;
  (void)op;  // suppress warning
  switch (opcode) {
    case BPF::NOP:
    case BPF::RET: {
      break;
    }
    case BPF::FI_ri: {
      // op: BPFClass
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(7)) << 56;
      break;
    }
    case BPF::JMP: {
      // op: BrDst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(65535)) << 32;
      break;
    }
    case BPF::JAL: {
      // op: BrDst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= op & UINT64_C(4294967295);
      break;
    }
    case BPF::BSWAP16:
    case BPF::BSWAP32:
    case BPF::BSWAP64: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 48;
      break;
    }
    case BPF::JEQ_ri:
    case BPF::JNE_ri:
    case BPF::JSGE_ri:
    case BPF::JSGT_ri:
    case BPF::JUGE_ri:
    case BPF::JUGT_ri: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 48;
      // op: BrDst
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= (op & UINT64_C(65535)) << 32;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= op & UINT64_C(4294967295);
      break;
    }
    case BPF::LDB:
    case BPF::LDD:
    case BPF::LDH:
    case BPF::LDW: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 48;
      // op: addr
      op = getMemoryOpValue(MI, 1, Fixups, STI);
      Value |= (op & UINT64_C(983040)) << 36;
      Value |= (op & UINT64_C(65535)) << 32;
      break;
    }
    case BPF::LD_imm64:
    case BPF::MOV_ri: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 48;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= op & UINT64_C(4294967295);
      break;
    }
    case BPF::ADD_ri:
    case BPF::AND_ri:
    case BPF::DIV_ri:
    case BPF::MUL_ri:
    case BPF::OR_ri:
    case BPF::SLL_ri:
    case BPF::SRA_ri:
    case BPF::SRL_ri:
    case BPF::SUB_ri:
    case BPF::XOR_ri: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 48;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= op & UINT64_C(4294967295);
      break;
    }
    case BPF::LD_pseudo: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 48;
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= op & UINT64_C(4294967295);
      // op: pseudo
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 52;
      break;
    }
    case BPF::MOV_rr: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 48;
      // op: src
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 52;
      break;
    }
    case BPF::JEQ_rr:
    case BPF::JNE_rr:
    case BPF::JSGE_rr:
    case BPF::JSGT_rr:
    case BPF::JUGE_rr:
    case BPF::JUGT_rr: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 48;
      // op: src
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 52;
      // op: BrDst
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= (op & UINT64_C(65535)) << 32;
      break;
    }
    case BPF::ADD_rr:
    case BPF::AND_rr:
    case BPF::DIV_rr:
    case BPF::MUL_rr:
    case BPF::OR_rr:
    case BPF::SLL_rr:
    case BPF::SRA_rr:
    case BPF::SRL_rr:
    case BPF::SUB_rr:
    case BPF::XOR_rr: {
      // op: dst
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 48;
      // op: src
      op = getMachineOpValue(MI, MI.getOperand(2), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 52;
      break;
    }
    case BPF::LD_ABS_B:
    case BPF::LD_ABS_H:
    case BPF::LD_ABS_W: {
      // op: imm
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= op & UINT64_C(4294967295);
      break;
    }
    case BPF::STB:
    case BPF::STD:
    case BPF::STH:
    case BPF::STW:
    case BPF::XADD32:
    case BPF::XADD64: {
      // op: src
      op = getMachineOpValue(MI, MI.getOperand(0), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 52;
      // op: addr
      op = getMemoryOpValue(MI, 1, Fixups, STI);
      Value |= (op & UINT64_C(1048575)) << 32;
      break;
    }
    case BPF::LD_IND_B:
    case BPF::LD_IND_H:
    case BPF::LD_IND_W: {
      // op: val
      op = getMachineOpValue(MI, MI.getOperand(1), Fixups, STI);
      Value |= (op & UINT64_C(15)) << 52;
      break;
    }
  default:
    std::string msg;
    raw_string_ostream Msg(msg);
    Msg << "Not supported instr: " << MI;
    report_fatal_error(Msg.str());
  }
  return Value;
}

