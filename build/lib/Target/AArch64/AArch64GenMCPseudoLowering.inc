/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Pseudo-instruction MC lowering Source Fragment                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

bool AArch64AsmPrinter::
emitPseudoExpansionLowering(MCStreamer &OutStreamer,
                            const MachineInstr *MI) {
  switch (MI->getOpcode()) {
    default: return false;
    case AArch64::FMOVD0: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(AArch64::FMOVXDr);
      // Operand: Rd
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: Rn
      TmpInst.addOperand(MCOperand::createReg(AArch64::XZR));
      EmitToStreamer(OutStreamer, TmpInst);
      break;
    }
    case AArch64::FMOVS0: {
      MCInst TmpInst;
      MCOperand MCOp;
      TmpInst.setOpcode(AArch64::FMOVWSr);
      // Operand: Rd
      lowerOperand(MI->getOperand(0), MCOp);
      TmpInst.addOperand(MCOp);
      // Operand: Rn
      TmpInst.addOperand(MCOperand::createReg(AArch64::WZR));
      EmitToStreamer(OutStreamer, TmpInst);
      break;
    }
  }
  return true;
}

