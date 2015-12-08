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
} // end llvm namespace
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV BPFSubTypeKV[] = {
  { "generic", "Select the generic processor", { }, { } }
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
extern const llvm::MCWriteProcResEntry BPFWriteProcResTable[] = {
  { 0,  0}, // Invalid
}; // BPFWriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry BPFWriteLatencyTable[] = {
  { 0,  0}, // Invalid
}; // BPFWriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry BPFReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // BPFReadAdvanceTable

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
extern const llvm::SubtargetInfoKV BPFProcSchedKV[] = {
  { "generic", (const void *)&NoSchedModel }
};
#undef DBGFIELD
static inline MCSubtargetInfo *createBPFMCSubtargetInfoImpl(const Triple &TT, StringRef CPU, StringRef FS) {
  return new MCSubtargetInfo(TT, CPU, FS, None, BPFSubTypeKV, 
                      BPFProcSchedKV, BPFWriteProcResTable, BPFWriteLatencyTable, BPFReadAdvanceTable, 0, 0, 0);
}

} // end llvm namespace
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::BPFSubtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct BPFGenSubtargetInfo : public TargetSubtargetInfo {
  explicit BPFGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS);
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
extern const llvm::SubtargetFeatureKV BPFFeatureKV[];
extern const llvm::SubtargetFeatureKV BPFSubTypeKV[];
extern const llvm::SubtargetInfoKV BPFProcSchedKV[];
extern const llvm::MCWriteProcResEntry BPFWriteProcResTable[];
extern const llvm::MCWriteLatencyEntry BPFWriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry BPFReadAdvanceTable[];
BPFGenSubtargetInfo::BPFGenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo(TT, CPU, FS, None, makeArrayRef(BPFSubTypeKV, 1), 
                        BPFProcSchedKV, BPFWriteProcResTable, BPFWriteLatencyTable, BPFReadAdvanceTable, 
                        0, 0, 0) {}

unsigned BPFGenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // BPFGenSubtargetInfo::resolveSchedClass
} // end llvm namespace
#endif // GET_SUBTARGETINFO_CTOR

