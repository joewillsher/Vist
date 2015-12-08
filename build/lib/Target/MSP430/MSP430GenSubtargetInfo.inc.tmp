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
namespace MSP430 {
enum : uint64_t {
  FeatureX = 0
};
}
} // end llvm namespace
#endif // GET_SUBTARGETINFO_ENUM


#ifdef GET_SUBTARGETINFO_MC_DESC
#undef GET_SUBTARGETINFO_MC_DESC
namespace llvm {
// Sorted (by key) array of values for CPU features.
extern const llvm::SubtargetFeatureKV MSP430FeatureKV[] = {
  { "ext", "Enable MSP430-X extensions", { MSP430::FeatureX }, { } }
};

// Sorted (by key) array of values for CPU subtype.
extern const llvm::SubtargetFeatureKV MSP430SubTypeKV[] = {
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
extern const llvm::MCWriteProcResEntry MSP430WriteProcResTable[] = {
  { 0,  0}, // Invalid
}; // MSP430WriteProcResTable

// {Cycles, WriteResourceID}
extern const llvm::MCWriteLatencyEntry MSP430WriteLatencyTable[] = {
  { 0,  0}, // Invalid
}; // MSP430WriteLatencyTable

// {UseIdx, WriteResourceID, Cycles}
extern const llvm::MCReadAdvanceEntry MSP430ReadAdvanceTable[] = {
  {0,  0,  0}, // Invalid
}; // MSP430ReadAdvanceTable

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
extern const llvm::SubtargetInfoKV MSP430ProcSchedKV[] = {
  { "generic", (const void *)&NoSchedModel }
};
#undef DBGFIELD
static inline MCSubtargetInfo *createMSP430MCSubtargetInfoImpl(const Triple &TT, StringRef CPU, StringRef FS) {
  return new MCSubtargetInfo(TT, CPU, FS, MSP430FeatureKV, MSP430SubTypeKV, 
                      MSP430ProcSchedKV, MSP430WriteProcResTable, MSP430WriteLatencyTable, MSP430ReadAdvanceTable, 0, 0, 0);
}

} // end llvm namespace
#endif // GET_SUBTARGETINFO_MC_DESC


#ifdef GET_SUBTARGETINFO_TARGET_DESC
#undef GET_SUBTARGETINFO_TARGET_DESC
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
void llvm::MSP430Subtarget::ParseSubtargetFeatures(StringRef CPU, StringRef FS) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU << "\n\n");
  InitMCProcessorInfo(CPU, FS);
  const FeatureBitset& Bits = getFeatureBits();
  if (Bits[MSP430::FeatureX]) ExtendedInsts = true;
}
#endif // GET_SUBTARGETINFO_TARGET_DESC


#ifdef GET_SUBTARGETINFO_HEADER
#undef GET_SUBTARGETINFO_HEADER
namespace llvm {
class DFAPacketizer;
struct MSP430GenSubtargetInfo : public TargetSubtargetInfo {
  explicit MSP430GenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS);
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
extern const llvm::SubtargetFeatureKV MSP430FeatureKV[];
extern const llvm::SubtargetFeatureKV MSP430SubTypeKV[];
extern const llvm::SubtargetInfoKV MSP430ProcSchedKV[];
extern const llvm::MCWriteProcResEntry MSP430WriteProcResTable[];
extern const llvm::MCWriteLatencyEntry MSP430WriteLatencyTable[];
extern const llvm::MCReadAdvanceEntry MSP430ReadAdvanceTable[];
MSP430GenSubtargetInfo::MSP430GenSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS)
  : TargetSubtargetInfo(TT, CPU, FS, makeArrayRef(MSP430FeatureKV, 1), makeArrayRef(MSP430SubTypeKV, 1), 
                        MSP430ProcSchedKV, MSP430WriteProcResTable, MSP430WriteLatencyTable, MSP430ReadAdvanceTable, 
                        0, 0, 0) {}

unsigned MSP430GenSubtargetInfo
::resolveSchedClass(unsigned SchedClass, const MachineInstr *MI, const TargetSchedModel *SchedModel) const {
  report_fatal_error("Expected a variant SchedClass");
} // MSP430GenSubtargetInfo::resolveSchedClass
} // end llvm namespace
#endif // GET_SUBTARGETINFO_CTOR

