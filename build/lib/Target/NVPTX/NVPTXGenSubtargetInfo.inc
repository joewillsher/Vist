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
namespace NVPTX {
enum : uint64_t {
  PTX32 = 0,
  PTX40 = 1,
  PTX41 = 2,
  PTX42 = 3,
  SM20 = 4,
  SM21 = 5,
  SM30 = 6,
  SM32 = 7,
  SM35 = 8,
  SM37 = 9,
  SM50 = 10,
  SM52 = 11,
  SM53 = 12
};
}
} // end llvm namespace
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV NVPTXFeatureKV[] = {
  { "ptx32", "Use PTX version 3.2", { NVPTX::PTX32 }, { } },
  { "ptx40", "Use PTX version 4.0", { NVPTX::PTX40 }, { } },
  { "ptx41", "Use PTX version 4.1", { NVPTX::PTX41 }, { } },
  { "ptx42", "Use PTX version 4.2", { NVPTX::PTX42 }, { } },
  { "sm_20", "Target SM 2.0", { NVPTX::SM20 }, { } },
  { "sm_21", "Target SM 2.1", { NVPTX::SM21 }, { } },
  { "sm_30", "Target SM 3.0", { NVPTX::SM30 }, { } },
  { "sm_32", "Target SM 3.2", { NVPTX::SM32 }, { } },
  { "sm_35", "Target SM 3.5", { NVPTX::SM35 }, { } },
  { "sm_37", "Target SM 3.7", { NVPTX::SM37 }, { } },
  { "sm_50", "Target SM 5.0", { NVPTX::SM50 }, { } },
  { "sm_52", "Target SM 5.2", { NVPTX::SM52 }, { } },
  { "sm_53", "Target SM 5.3", { NVPTX::SM53 }, { } }
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV NVPTXSubTypeKV[] = {
  { "sm_20", "Select the sm_20 processor", { NVPTX::SM20 }, { } },
  { "sm_21", "Select the sm_21 processor", { NVPTX::SM21 }, { } },
  { "sm_30", "Select the sm_30 processor", { NVPTX::SM30 }, { } },
  { "sm_32", "Select the sm_32 processor", { NVPTX::SM32, NVPTX::PTX40 }, { } },
  { "sm_35", "Select the sm_35 processor", { NVPTX::SM35 }, { } },
  { "sm_37", "Select the sm_37 processor", { NVPTX::SM37, NVPTX::PTX41 }, { } },
  { "sm_50", "Select the sm_50 processor", { NVPTX::SM50, NVPTX::PTX40 }, { } },
  { "sm_52", "Select the sm_52 processor", { NVPTX::SM52, NVPTX::PTX41 }, { } },
  { "sm_53", "Select the sm_53 processor", { NVPTX::SM53, NVPTX::PTX42 }, { } }
};

#ifdef DBGFIELD
#error "<target>GenSubtargetInfo.inc requires a DBGFIELD macro"
#endif
#ifndef NDEBUG
#define DBGFIELD(x) x,
#else
#define DBGFIELD(x)
#endif

// ===============================================================
// Data tables for the new per-operand machine model.

// {ProcResourceIdx, Cycles}
extern const llvm::MCWriteProcResEntry NVPTXWriteProcResTable[] = {
  { 0,  0}, // Invalid
}; // NVPTXWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry NVPTXWriteLatencyTable[] = {
  { 0,  0}, // Invalid
}; // NVPTXWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry NVPTXReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // NVPTXReadAdvanceTable

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

// Sorted (by key) array of itineraries for CPU subtype.
extern const llvm::SubtargetInfoKV NVPTXProcSchedKV[] = {
  { "sm_20", (const void *)&NoSchedModel },
  { "sm_21", (const void *)&NoSchedModel },
  { "sm_30", (const void *)&NoSchedModel },
  { "sm_32", (const void *)&NoSchedModel },
  { "sm_35", (const void *)&NoSchedModel },
  { "sm_37", (const void *)&NoSchedModel },
  { "sm_50", (const void *)&NoSchedModel },
  { "sm_52", (const void *)&NoSchedModel },
  { "sm_53", (const void *)&NoSchedModel }
};
#undef DBGFIELD
static inline MCSubtargetInfo *createNVPTXMCSubtargetInfoImpl(const Triple &TT, StringRef CPU, StringRef FS) {
  return new MCSubtargetInfo(TT, CPU, FS, NVPTXFeatureKV, NVPTXSubTypeKV, 
                      NVPTXProcSchedKV, NVPTXWriteProcResTable, NVPTXWriteLatencyTable, NVPTXReadAdvanceTable, 0, 0, 0);
}

} // end llvm namespace
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::NVPTXSubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  const FeatureBitset& Bits = getFeatureBits();
  if (Bits[NVPTX::PTX32] && PTXVersion < 32) PTXVersion = 32;
  if (Bits[NVPTX::PTX40] && PTXVersion < 40) PTXVersion = 40;
  if (Bits[NVPTX::PTX41] && PTXVersion < 41) PTXVersion = 41;
  if (Bits[NVPTX::PTX42] && PTXVersion < 42) PTXVersion = 42;
  if (Bits[NVPTX::SM20] && SmVersion < 20) SmVersion = 20;
  if (Bits[NVPTX::SM21] && SmVersion < 21) SmVersion = 21;
  if (Bits[NVPTX::SM30] && SmVersion < 30) SmVersion = 30;
  if (Bits[NVPTX::SM32] && SmVersion < 32) SmVersion = 32;
  if (Bits[NVPTX::SM35] && SmVersion < 35) SmVersion = 35;
  if (Bits[NVPTX::SM37] && SmVersion < 37) SmVersion = 37;
  if (Bits[NVPTX::SM50] && SmVersion < 50) SmVersion = 50;
  if (Bits[NVPTX::SM52] && SmVersion < 52) SmVersion = 52;
  if (Bits[NVPTX::SM53] && SmVersion < 53) SmVersion = 53;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct NVPTXGenSubtargetInfo : public TargetSubtargetInfo {
  explicit NVPTXGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS);
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
extern const llvm::SubtargetFeatureKV NVPTXFeatureKV[];
extern const llvm::SubtargetFeatureKV NVPTXSubTypeKV[];
extern const llvm::SubtargetInfoKV NVPTXProcSchedKV[];
extern const llvm::MCWriteProcResEntry NVPTXWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry NVPTXWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry NVPTXReadAdvanceTable[];
NVPTXGenSubtargetInfo::NVPTXGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo(TT, CPU, FS, makeArrayRef(NVPTXFeatureKV, 13), makeArrayRef(NVPTXSubTypeKV, 9), 
                        NVPTXProcSchedKV, NVPTXWriteProcResTable, NVPTXWriteLatencyTable, NVPTXReadAdvanceTable, 
                        0, 0, 0) {}

unsigned NVPTXGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // NVPTXGenSubtargetInfo::resolveSchedClass
} // end llvm namespace
#endif // GET_SUBTARGETINFO_CTOR

