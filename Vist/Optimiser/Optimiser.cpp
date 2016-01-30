//
//  Optimiser.cpp
//  Vist
//
//  Created by Josef Willsher on 25/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "Optimiser.hpp"
#include "StdLibInline.hpp"

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
#include "llvm/LTO/LTOModule.h"
#include "llvm/LTO/LTOCodeGenerator.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Vectorize.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Analysis/Passes.h"

#include <iostream>


using namespace llvm;

// swift impl here
// https://github.com/apple/swift/blob/master/lib/IRGen/IRGen.cpp
// https://github.com/apple/swift/blob/master/tools/swift-llvm-opt/LLVMOpt.cpp

/// Runs the optimisations
void performLLVMOptimisations(Module *Module, int optLevel, bool isStdLib) {
    
    PassManagerBuilder PMBuilder;
    
    if (optLevel != 0) {
        PMBuilder.OptLevel = 3;
        PMBuilder.Inliner = createFunctionInliningPass(3, 0);
        PMBuilder.DisableTailCalls = false;
        PMBuilder.DisableUnitAtATime = false;
        PMBuilder.DisableUnrollLoops = false;
        PMBuilder.BBVectorize = true;
        PMBuilder.SLPVectorize = true;
        PMBuilder.LoopVectorize = true;
        PMBuilder.RerollLoops = true;
        PMBuilder.LoadCombine = true;
        PMBuilder.DisableGVNLoadPRE = true;
        PMBuilder.VerifyInput = true;
        PMBuilder.VerifyOutput = true;
        PMBuilder.StripDebug = true;
        PMBuilder.MergeFunctions = true;
    }
    else { // we want some optimisations, even at -O0
        PMBuilder.OptLevel = 0;
        PMBuilder.Inliner = createAlwaysInlinerPass(false);
    }
    
    if (!isStdLib)
        PMBuilder.addExtension(PassManagerBuilder::EP_ModuleOptimizerEarly,  // Run first thing
                               addStdLibInlinePass);                         // The initialiaser pass
    
    // Configure the function passes.
    legacy::FunctionPassManager FunctionPasses(Module);
    
    FunctionPasses.add(createVerifierPass());
    
    if (optLevel == 0) { // we want some optimisations, even at -O0
        FunctionPasses.add(createBasicAliasAnalysisPass());
        FunctionPasses.add(createInstructionCombiningPass());
        
        // needed as compiler produces a lot of redundant memory code assuming it will be optimied away
        FunctionPasses.add(createPromoteMemoryToRegisterPass());
        
        FunctionPasses.add(createReassociatePass());
        FunctionPasses.add(createConstantPropagationPass());
    }
    else {
//        FunctionPasses.add(createPromoteMemoryToRegisterPass());
    }
    PMBuilder.populateFunctionPassManager(FunctionPasses);
    
    // TODO: Dont run all optimisations in -O0
    // TODO: also make it so you *can* run this and not the command line `opt` tool
    
    FunctionPasses.doInitialization();
    for (auto I = Module->begin(), E = Module->end(); I != E; ++I)
        if (!I->isDeclaration())
            FunctionPasses.run(*I);
    FunctionPasses.doFinalization();
    
    // Configure the module passes.
    legacy::PassManager ModulePasses;
    PMBuilder.populateModulePassManager(ModulePasses);
    
//    ModulePasses.add(createVerifierPass());
    
    /// add custom module passes here
    // eg... ModulePasses.add(<#createAnyModulePass()#>);
    
    // then run optimisations
    ModulePasses.run(*Module);
    
//    if (!isStdLib) {
//        legacy::PassManager LTOPasses;
//        /// add custom link time optimisations
//        //    LTOPasses.addLTOOptimizationPasses(<#createAnyLTOPass()#>);
//        PMBuilder.populateLTOPassManager(LTOPasses);
//        LTOPasses.run(*Module);
//    }
}

/// Called from swift code
void performLLVMOptimisations(LLVMModuleRef mod, int optLevel, bool isStdLib) {
    performLLVMOptimisations(unwrap(mod), optLevel, isStdLib);
}


void LLVMAddMetadata(LLVMValueRef val, const char * String) {
    auto s = StringRef(String);
    auto id = LLVMGetMDKindID(s.data(), int32_t(s.size()));
    
    LLVMValueRef md = LLVMMDString(s.data(), uint(s.size()));
    LLVMSetMetadata(val, id, md);
}

int LLVMMetadataID(const char * String) {
    auto s = StringRef(String);
    return LLVMGetMDKindID(s.data(), int32_t(s.size()));
}


