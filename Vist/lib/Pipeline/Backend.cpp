//
//  Backend.cpp
//  Vist
//
//  Created by Josef Willsher on 10/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "Backend.hpp"

//#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Analysis/TargetLibraryInfo.h"
#include "llvm/CodeGen/CommandFlags.h"
#include "llvm/CodeGen/LinkAllAsmWriterComponents.h"
#include "llvm/CodeGen/LinkAllCodegenComponents.h"
#include "llvm/CodeGen/MIRParser/MIRParser.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DiagnosticInfo.h"
#include "llvm/IR/DiagnosticPrinter.h"
#include "llvm/IR/IRPrintingPasses.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/MC/SubtargetFeature.h"
#include "llvm/Pass.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/PluginLoader.h"
#include "llvm/Support/PrettyStackTrace.h"
#include "llvm/Support/Signals.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetSubtargetInfo.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include <memory>
using namespace llvm;

#include <iostream>

// Returns the TargetMachine instance or zero if no triple is provided.
static llvm::TargetMachine *
getTargetMachine(llvm::Triple TheTriple, StringRef CPUStr,
                 StringRef FeaturesStr, const llvm::TargetOptions &Options) {
    std::string Error;
    const auto *TheTarget =
    llvm::TargetRegistry::lookupTarget(MArch, TheTriple, Error);
    // Some modules don't specify a triple, and this is okay.
    if (!TheTarget) {
        return nullptr;
    }
    
    return TheTarget->createTargetMachine(TheTriple.getTriple(), CPUStr,
                                          FeaturesStr, Options, getRelocModel(),
                                          CMModel, CodeGenOpt::Default);
}

void compile(Module *module, TargetMachine::CodeGenFileType type) {
    
    LLVMContext Context;
    
    PassRegistry *Registry = PassRegistry::getPassRegistry();
    initializeCore(*Registry);
    initializeCodeGen(*Registry);
    initializeLoopStrengthReducePass(*Registry);
    initializeLowerIntrinsicsPass(*Registry);
    initializeUnreachableBlockElimLegacyPassPass(*Registry);
    
    cl::AddExtraVersionPrinter(TargetRegistry::printRegisteredTargetsForVersion);
    cl::ParseEnvironmentOptions("vist", "1");
    
    Triple triple = Triple(Triple::normalize(module->getTargetTriple()));
    
    
    //module->dump();
    
//    if (TheTriple.getTriple().empty())
//        TheTriple.setTriple(sys::getDefaultTargetTriple());
    
    std::string Error;
    
    std::string CPUStr = sys::getHostCPUName();
    
    SubtargetFeatures Features;
    StringMap<bool> HostFeatures;
    if (sys::getHostCPUFeatures(HostFeatures))
        for (auto &F : HostFeatures)
            Features.AddFeature(F.first(), F.second);

    std::string FeaturesStr = Features.getString();
    
    TargetOptions Options = InitTargetOptionsFromCodeGenFlags();
    
    CodeGenOpt::Level OLvl = CodeGenOpt::Default;
 //   std::cout << CPUStr << "\n\n";
//    std::cout << FeaturesStr;
    std::cout << triple.getTriple() << "\n";
    std::cout << MArch << "\n";
    
    //  const Target *Target = TargetRegistry::lookupTarget(triple.str(), Error);
    //auto TM = getTargetMachine(triple, CPUStr, FeaturesStr, Options);
    //assert(TM);
    
    const Target *Target = TargetRegistry::lookupTarget(triple.str(), Error);
    
    std::cout << Error;
    assert(Target);
    
    auto TargetMachine = Target->createTargetMachine(triple.getTriple(), CPUStr, FeaturesStr,
                                                     Options, getRelocModel(), CMModel, OLvl);
    
    //module->setDataLayout(TargetMachine->createDataLayout());
    //setFunctionAttributes(CPUStr, FeaturesStr, *module);
    
    legacy::PassManager EmitPasses;
    raw_pwrite_stream *RawOS;

    EmitPasses.add(createTargetTransformInfoWrapperPass(TargetMachine->getTargetIRAnalysis()));
    
    
    bool fail = TargetMachine->addPassesToEmitFile(EmitPasses, *RawOS,
                                                   type, true);
    
}


void compileModule(LLVMModuleRef module) {
    compile(unwrap(module),
            TargetMachine::CodeGenFileType::CGFT_ObjectFile);
}


