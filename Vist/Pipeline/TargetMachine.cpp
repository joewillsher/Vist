//
//  TargetMachine.cpp
//  Vist
//
//  Created by Josef Willsher on 27/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "TargetMachine.hpp"

#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/Target/TargetIntrinsicInfo.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Pass.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/MC/SubtargetFeature.h"
#include "llvm/Target/TargetSubtargetInfo.h"
#include "llvm/CodeGen/CommandFlags.h"
#include "llvm/Support/Host.h"
#include "llvm/MC/SubtargetFeature.h"
#include "llvm/Support/TargetSelect.h"

#include "clang/Basic/AddressSpaces.h"
#include "clang/Basic/LLVM.h"
#include "clang/Basic/Specifiers.h"
#include "clang/Basic/TargetCXXABI.h"
#include "clang/Basic/TargetOptions.h"
#include "clang/Basic/VersionTuple.h"
#include "clang/Basic/TargetInfo.h"

#include <iostream>


using namespace llvm;

TargetMachine *createTargetMachine() {
    
    InitializeAllTargets();
    
    const Triple &triple = Triple(Twine("x86_64"), Twine("apple"), Twine("macosx10.11.0"));
    std::string Error;
    const Target *Target = llvm::TargetRegistry::lookupTarget(triple.str(), Error);
    
    
    CodeGenOpt::Level OptLevel = CodeGenOpt::Aggressive;
    //    : CodeGenOpt::None;
    
    // Set up TargetOptions and create the target features string.
    TargetOptions TargetOpts = InitTargetOptionsFromCodeGenFlags();
    std::string CPU = sys::getHostCPUName();
    
    std::string targetFeatures;
    SubtargetFeatures Features;
    
    StringMap<bool> HostFeatures;
    if (sys::getHostCPUFeatures(HostFeatures))
        for (auto &F : HostFeatures)
            Features.AddFeature(F.first());
    targetFeatures = Features.getString();
    
//    const auto &Opts = std::make_shared<TargetOptions>(TargetOpts);
//    std::vector<StringRef> vec = TargetOpts.Features;
    
    
    std::cout << Error << '\n' << triple.str();
    
    // Create a target machine.
    llvm::TargetMachine *TargetMachine
    = Target->createTargetMachine(triple.str(), CPU,
                                  targetFeatures, TargetOpts, Reloc::PIC_,
                                  CodeModel::Default, OptLevel);
    if (!TargetMachine)
        return nullptr;
    
    return TargetMachine;
}





