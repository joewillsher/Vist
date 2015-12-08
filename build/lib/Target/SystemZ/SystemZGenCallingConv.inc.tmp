/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Calling Convention Implementation Fragment                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

static bool CC_SystemZ(unsigned ValNo, MVT ValVT,
                       MVT LocVT, CCValAssign::LocInfo LocInfo,
                       ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool RetCC_SystemZ(unsigned ValNo, MVT ValVT,
                          MVT LocVT, CCValAssign::LocInfo LocInfo,
                          ISD::ArgFlagsTy ArgFlags, CCState &State);


static bool CC_SystemZ(unsigned ValNo, MVT ValVT,
                       MVT LocVT, CCValAssign::LocInfo LocInfo,
                       ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i32) {
    if (ArgFlags.isSExt() || ArgFlags.isZExt()) {
      LocVT = MVT::i64;
      if (ArgFlags.isSExt())
            LocInfo = CCValAssign::SExt;
      else if (ArgFlags.isZExt())
            LocInfo = CCValAssign::ZExt;
      else
            LocInfo = CCValAssign::AExt;
    }
  }

  if (LocVT == MVT::f128) {
    LocVT = MVT::i64;
    LocInfo = CCValAssign::Indirect;
  }

  if (LocVT == MVT::i32) {
    static const MCPhysReg RegList1[] = {
      SystemZ::R2L, SystemZ::R3L, SystemZ::R4L, SystemZ::R5L, SystemZ::R6L
    };
    if (unsigned Reg = State.AllocateReg(RegList1)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i64) {
    static const MCPhysReg RegList2[] = {
      SystemZ::R2D, SystemZ::R3D, SystemZ::R4D, SystemZ::R5D, SystemZ::R6D
    };
    if (unsigned Reg = State.AllocateReg(RegList2)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f32) {
    static const MCPhysReg RegList3[] = {
      SystemZ::F0S, SystemZ::F2S, SystemZ::F4S, SystemZ::F6S
    };
    if (unsigned Reg = State.AllocateReg(RegList3)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f64) {
    static const MCPhysReg RegList4[] = {
      SystemZ::F0D, SystemZ::F2D, SystemZ::F4D, SystemZ::F6D
    };
    if (unsigned Reg = State.AllocateReg(RegList4)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (static_cast<const SystemZSubtarget&>(State.getMachineFunction().getSubtarget()).hasVector()) {
    if (LocVT == MVT::v16i8 ||
        LocVT == MVT::v8i16 ||
        LocVT == MVT::v4i32 ||
        LocVT == MVT::v2i64 ||
        LocVT == MVT::v4f32 ||
        LocVT == MVT::v2f64) {
      if (static_cast<SystemZCCState *>(&State)->IsFixed(ValNo)) {
        static const MCPhysReg RegList5[] = {
          SystemZ::V24, SystemZ::V26, SystemZ::V28, SystemZ::V30, SystemZ::V25, SystemZ::V27, SystemZ::V29, SystemZ::V31
        };
        if (unsigned Reg = State.AllocateReg(RegList5)) {
          State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
          return false;
        }
      }
    }
  }

  if (static_cast<const SystemZSubtarget&>(State.getMachineFunction().getSubtarget()).hasVector()) {
    if (LocVT == MVT::v16i8 ||
        LocVT == MVT::v8i16 ||
        LocVT == MVT::v4i32 ||
        LocVT == MVT::v2i64 ||
        LocVT == MVT::v4f32 ||
        LocVT == MVT::v2f64) {
      if (static_cast<SystemZCCState *>(&State)->IsShortVector(ValNo)) {
        LocVT = MVT::i64;
        LocInfo = CCValAssign::BCvt;
      }
    }
  }

  if (static_cast<const SystemZSubtarget&>(State.getMachineFunction().getSubtarget()).hasVector()) {
    if (LocVT == MVT::v16i8 ||
        LocVT == MVT::v8i16 ||
        LocVT == MVT::v4i32 ||
        LocVT == MVT::v2i64 ||
        LocVT == MVT::v4f32 ||
        LocVT == MVT::v2f64) {
      unsigned Offset6 = State.AllocateStack(16, 8);
      State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset6, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i32 ||
      LocVT == MVT::i64 ||
      LocVT == MVT::f32 ||
      LocVT == MVT::f64) {
    unsigned Offset7 = State.AllocateStack(8, 8);
    State.addLoc(CCValAssign::getMem(ValNo, ValVT, Offset7, LocVT, LocInfo));
    return false;
  }

  return true;  // CC didn't match.
}


static bool RetCC_SystemZ(unsigned ValNo, MVT ValVT,
                          MVT LocVT, CCValAssign::LocInfo LocInfo,
                          ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (LocVT == MVT::i32) {
    if (ArgFlags.isSExt() || ArgFlags.isZExt()) {
      LocVT = MVT::i64;
      if (ArgFlags.isSExt())
            LocInfo = CCValAssign::SExt;
      else if (ArgFlags.isZExt())
            LocInfo = CCValAssign::ZExt;
      else
            LocInfo = CCValAssign::AExt;
    }
  }

  if (LocVT == MVT::i32) {
    static const MCPhysReg RegList1[] = {
      SystemZ::R2L, SystemZ::R3L, SystemZ::R4L, SystemZ::R5L
    };
    if (unsigned Reg = State.AllocateReg(RegList1)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::i64) {
    static const MCPhysReg RegList2[] = {
      SystemZ::R2D, SystemZ::R3D, SystemZ::R4D, SystemZ::R5D
    };
    if (unsigned Reg = State.AllocateReg(RegList2)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f32) {
    static const MCPhysReg RegList3[] = {
      SystemZ::F0S, SystemZ::F2S, SystemZ::F4S, SystemZ::F6S
    };
    if (unsigned Reg = State.AllocateReg(RegList3)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (LocVT == MVT::f64) {
    static const MCPhysReg RegList4[] = {
      SystemZ::F0D, SystemZ::F2D, SystemZ::F4D, SystemZ::F6D
    };
    if (unsigned Reg = State.AllocateReg(RegList4)) {
      State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
      return false;
    }
  }

  if (static_cast<const SystemZSubtarget&>(State.getMachineFunction().getSubtarget()).hasVector()) {
    if (LocVT == MVT::v16i8 ||
        LocVT == MVT::v8i16 ||
        LocVT == MVT::v4i32 ||
        LocVT == MVT::v2i64 ||
        LocVT == MVT::v4f32 ||
        LocVT == MVT::v2f64) {
      static const MCPhysReg RegList5[] = {
        SystemZ::V24, SystemZ::V26, SystemZ::V28, SystemZ::V30, SystemZ::V25, SystemZ::V27, SystemZ::V29, SystemZ::V31
      };
      if (unsigned Reg = State.AllocateReg(RegList5)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  return true;  // CC didn't match.
}
