/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Calling Convention Implementation Fragment                                 *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

static bool CC_AMDGPU(unsigned ValNo, MVT ValVT,
                      MVT LocVT, CCValAssign::LocInfo LocInfo,
                      ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool CC_AMDGPU_Kernel(unsigned ValNo, MVT ValVT,
                             MVT LocVT, CCValAssign::LocInfo LocInfo,
                             ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool CC_R600(unsigned ValNo, MVT ValVT,
                    MVT LocVT, CCValAssign::LocInfo LocInfo,
                    ISD::ArgFlagsTy ArgFlags, CCState &State);
static bool CC_SI(unsigned ValNo, MVT ValVT,
                  MVT LocVT, CCValAssign::LocInfo LocInfo,
                  ISD::ArgFlagsTy ArgFlags, CCState &State);


static bool CC_AMDGPU(unsigned ValNo, MVT ValVT,
                      MVT LocVT, CCValAssign::LocInfo LocInfo,
                      ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (static_cast<const AMDGPUSubtarget&>(State.getMachineFunction().getSubtarget()).getGeneration() >=AMDGPUSubtarget::SOUTHERN_ISLANDS && State.getMachineFunction().getInfo<SIMachineFunctionInfo>()->getShaderType() == ShaderType::COMPUTE) {
    if (!CC_AMDGPU_Kernel(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  if (static_cast<const AMDGPUSubtarget&>(State.getMachineFunction().getSubtarget()).getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS && State.getMachineFunction().getInfo<R600MachineFunctionInfo>()->getShaderType() == ShaderType::COMPUTE) {
    if (!CC_AMDGPU_Kernel(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  if (static_cast<const AMDGPUSubtarget&>(State.getMachineFunction().getSubtarget()).getGeneration() >= AMDGPUSubtarget::SOUTHERN_ISLANDS) {
    if (!CC_SI(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  if (static_cast<const AMDGPUSubtarget&>(State.getMachineFunction().getSubtarget()).getGeneration() < AMDGPUSubtarget::SOUTHERN_ISLANDS) {
    if (!CC_R600(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
      return false;
  }

  return true;  // CC didn't match.
}


static bool CC_AMDGPU_Kernel(unsigned ValNo, MVT ValVT,
                             MVT LocVT, CCValAssign::LocInfo LocInfo,
                             ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (allocateStack(ValNo, ValVT, LocVT, LocInfo, ArgFlags, State))
    return false;

  return true;  // CC didn't match.
}


static bool CC_R600(unsigned ValNo, MVT ValVT,
                    MVT LocVT, CCValAssign::LocInfo LocInfo,
                    ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (ArgFlags.isInReg()) {
    if (LocVT == MVT::v4f32 ||
        LocVT == MVT::v4i32) {
      static const MCPhysReg RegList1[] = {
        AMDGPU::T0_XYZW, AMDGPU::T1_XYZW, AMDGPU::T2_XYZW, AMDGPU::T3_XYZW, AMDGPU::T4_XYZW, AMDGPU::T5_XYZW, AMDGPU::T6_XYZW, AMDGPU::T7_XYZW, AMDGPU::T8_XYZW, AMDGPU::T9_XYZW, AMDGPU::T10_XYZW, AMDGPU::T11_XYZW, AMDGPU::T12_XYZW, AMDGPU::T13_XYZW, AMDGPU::T14_XYZW, AMDGPU::T15_XYZW, AMDGPU::T16_XYZW, AMDGPU::T17_XYZW, AMDGPU::T18_XYZW, AMDGPU::T19_XYZW, AMDGPU::T20_XYZW, AMDGPU::T21_XYZW, AMDGPU::T22_XYZW, AMDGPU::T23_XYZW, AMDGPU::T24_XYZW, AMDGPU::T25_XYZW, AMDGPU::T26_XYZW, AMDGPU::T27_XYZW, AMDGPU::T28_XYZW, AMDGPU::T29_XYZW, AMDGPU::T30_XYZW, AMDGPU::T31_XYZW, AMDGPU::T32_XYZW
      };
      if (unsigned Reg = State.AllocateReg(RegList1)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  return true;  // CC didn't match.
}


static bool CC_SI(unsigned ValNo, MVT ValVT,
                  MVT LocVT, CCValAssign::LocInfo LocInfo,
                  ISD::ArgFlagsTy ArgFlags, CCState &State) {

  if (ArgFlags.isInReg()) {
    if (LocVT == MVT::f32 ||
        LocVT == MVT::i32) {
      static const MCPhysReg RegList1[] = {
        AMDGPU::SGPR0, AMDGPU::SGPR1, AMDGPU::SGPR2, AMDGPU::SGPR3, AMDGPU::SGPR4, AMDGPU::SGPR5, AMDGPU::SGPR6, AMDGPU::SGPR7, AMDGPU::SGPR8, AMDGPU::SGPR9, AMDGPU::SGPR10, AMDGPU::SGPR11, AMDGPU::SGPR12, AMDGPU::SGPR13, AMDGPU::SGPR14, AMDGPU::SGPR15, AMDGPU::SGPR16, AMDGPU::SGPR17, AMDGPU::SGPR18, AMDGPU::SGPR19, AMDGPU::SGPR20, AMDGPU::SGPR21
      };
      if (unsigned Reg = State.AllocateReg(RegList1)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  if (ArgFlags.isInReg()) {
    if (LocVT == MVT::i64) {
      static const MCPhysReg RegList2[] = {
        AMDGPU::SGPR0, AMDGPU::SGPR2, AMDGPU::SGPR4, AMDGPU::SGPR6, AMDGPU::SGPR8, AMDGPU::SGPR10, AMDGPU::SGPR12, AMDGPU::SGPR14
      };
      static const MCPhysReg RegList3[] = {
        AMDGPU::SGPR1, AMDGPU::SGPR3, AMDGPU::SGPR5, AMDGPU::SGPR7, AMDGPU::SGPR9, AMDGPU::SGPR11, AMDGPU::SGPR13, AMDGPU::SGPR15
      };
      if (unsigned Reg = State.AllocateReg(RegList2, RegList3)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  if (!ArgFlags.isInReg()) {
    if (LocVT == MVT::f32 ||
        LocVT == MVT::i32) {
      static const MCPhysReg RegList4[] = {
        AMDGPU::VGPR0, AMDGPU::VGPR1, AMDGPU::VGPR2, AMDGPU::VGPR3, AMDGPU::VGPR4, AMDGPU::VGPR5, AMDGPU::VGPR6, AMDGPU::VGPR7, AMDGPU::VGPR8, AMDGPU::VGPR9, AMDGPU::VGPR10, AMDGPU::VGPR11, AMDGPU::VGPR12, AMDGPU::VGPR13, AMDGPU::VGPR14, AMDGPU::VGPR15, AMDGPU::VGPR16, AMDGPU::VGPR17, AMDGPU::VGPR18, AMDGPU::VGPR19, AMDGPU::VGPR20, AMDGPU::VGPR21, AMDGPU::VGPR22, AMDGPU::VGPR23, AMDGPU::VGPR24, AMDGPU::VGPR25, AMDGPU::VGPR26, AMDGPU::VGPR27, AMDGPU::VGPR28, AMDGPU::VGPR29, AMDGPU::VGPR30, AMDGPU::VGPR31
      };
      if (unsigned Reg = State.AllocateReg(RegList4)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  if (ArgFlags.isByVal()) {
    if (LocVT == MVT::i64) {
      static const MCPhysReg RegList5[] = {
        AMDGPU::SGPR0, AMDGPU::SGPR2, AMDGPU::SGPR4, AMDGPU::SGPR6, AMDGPU::SGPR8, AMDGPU::SGPR10, AMDGPU::SGPR12, AMDGPU::SGPR14
      };
      static const MCPhysReg RegList6[] = {
        AMDGPU::SGPR1, AMDGPU::SGPR3, AMDGPU::SGPR5, AMDGPU::SGPR7, AMDGPU::SGPR9, AMDGPU::SGPR11, AMDGPU::SGPR13, AMDGPU::SGPR15
      };
      if (unsigned Reg = State.AllocateReg(RegList5, RegList6)) {
        State.addLoc(CCValAssign::getReg(ValNo, ValVT, Reg, LocVT, LocInfo));
        return false;
      }
    }
  }

  return true;  // CC didn't match.
}
