
//
//  Optimiser.cpp
//  Vist
//
//  Created by Josef Willsher on 25/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "Optimiser.hpp"

#include "llvm/PassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/PassInfo.h"
#include "llvm/PassSupport.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/IR/LLVMContext.h"

#include "llvm/Transforms/Instrumentation.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/Analysis/Passes.h"

#include <iostream>

using namespace llvm;

/// Runs the optimisations
void performLLVMOptimisations(Module *module, int optLevel, bool isStdLib) {
    
    PassManagerBuilder pmBuilder;
    PassManager passManager;
        
    if (optLevel != 0) {
        pmBuilder.OptLevel = optLevel;
        pmBuilder.Inliner = createFunctionInliningPass();
        pmBuilder.DisableTailCalls = false;
        pmBuilder.DisableUnitAtATime = false;
        pmBuilder.DisableUnrollLoops = false;
        pmBuilder.BBVectorize = true;
        pmBuilder.SLPVectorize = true;
        pmBuilder.LoopVectorize = true;
        pmBuilder.RerollLoops = true;
        pmBuilder.LoadCombine = true;
        pmBuilder.DisableGVNLoadPRE = true;
        pmBuilder.VerifyInput = true;
        pmBuilder.VerifyOutput = true;
        pmBuilder.MergeFunctions = true;
    }
    else { // we want some optimisations, even at -Onone
        pmBuilder.OptLevel = 0;
        pmBuilder.LoadCombine = true;
        pmBuilder.DisableUnrollLoops = true;
        pmBuilder.Inliner = createAlwaysInlinerPass(false);
    }
    
    // add default opt passes
    initializeTargetPassConfigPass(*PassRegistry::getPassRegistry());
    pmBuilder.populateModulePassManager(passManager);
    // and run them
    passManager.run(*module);
}

/// Called from swift code
void performLLVMOptimisations(LLVMModuleRef __nonnull mod, int optLevel, bool isStdLib) {
    performLLVMOptimisations(unwrap(mod), optLevel, isStdLib);
}
