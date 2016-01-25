//
//  Optimiser.cpp
//  Vist
//
//  Created by Josef Willsher on 25/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "Optimiser.hpp"
#include "InitialiserPass.hpp"

#include "llvm/PassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/PassInfo.h"
#include "llvm/PassSupport.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"

#include "llvm/Transforms/Instrumentation.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/IR/Verifier.h"

using namespace llvm;


void performLLVMOptimisations(Module *Module) {
    
    PassManagerBuilder PMBuilder;
    
    PMBuilder.OptLevel = 3;
    PMBuilder.Inliner = llvm::createFunctionInliningPass(200);
    PMBuilder.SLPVectorize = true;
    PMBuilder.LoopVectorize = true;
    PMBuilder.MergeFunctions = true;
    
    PMBuilder.addExtension(PassManagerBuilder::EP_ModuleOptimizerEarly, addInitialiserSimplificationPass);
    
    // Configure the function passes.
    legacy::FunctionPassManager FunctionPasses(Module);

    FunctionPasses.add(createVerifierPass());
    PMBuilder.populateFunctionPassManager(FunctionPasses);
    
    FunctionPasses.doInitialization();
    for (auto I = Module->begin(), E = Module->end(); I != E; ++I)
        if (!I->isDeclaration())
            FunctionPasses.run(*I);
    FunctionPasses.doFinalization();
    
    // Configure the module passes.
    legacy::PassManager ModulePasses;
    PMBuilder.populateModulePassManager(ModulePasses);
    
    
    ModulePasses.add(createVerifierPass());
    
    // Do it.
    ModulePasses.run(*Module);
    
}

void performLLVMOptimisations(LLVMModuleRef mod) {
    Module *module = unwrap(mod);
    performLLVMOptimisations(module);
}

