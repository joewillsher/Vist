//
//  InitialiserPass.cpp
//  Vist
//
//  Created by Josef Willsher on 24/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

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

#include <stdio.h>



// useful instructions here: http://llvm.org/docs/WritingAnLLVMPass.html
// swift example here https://github.com/apple/swift/blob/master/lib/LLVMPasses/LLVMStackPromotion.cpp

#define DEBUG_TYPE "initialiser-pass"
using namespace llvm;

// MARK: InitialiserSimplification pass decl

class InitialiserSimplification : public FunctionPass {
    
    virtual bool runOnFunction(Function &F) override;
    
public:
    static char ID;
    InitialiserSimplification() : FunctionPass(ID) {}
};

// we dont care about the ID
char InitialiserSimplification::ID = 0;



// MARK: bullshit llvm macros

// defines `initializeInitialiserSimplificationPassOnce(PassRegistry &Registry)` function
INITIALIZE_PASS_BEGIN(InitialiserSimplification,
                      "initialiser-pass", "Vist initialiser folding pass",
                      false, false)
// implements `llvm::initializeInitialiserSimplificationPass(PassRegistry &Registry)` function, declared in header
// adds it to the pass registry
INITIALIZE_PASS_END(InitialiserSimplification,
                    "initialiser-pass", "Vist initialiser folding pass",
                    false, false)


// MARK: InitialiserSimplification Functions

/// returns instance of the InitialiserSimplification pass
FunctionPass *createInitialiserSimplificationPass() {
    initializeInitialiserSimplificationPass(*PassRegistry::getPassRegistry());
    return new InitialiserSimplification();
}

/// Called on functions in module, this is where the optimisations happen
bool InitialiserSimplification::runOnFunction(Function &F) {
    
    printf("mrmr");
    
    return false;
}


// MARK: Expose to swift

/// Adds a named pass, not used yet
bool
LLVMAddPass(LLVMPassManagerRef PM, const char *PassName) {
    PassManagerBase *pm = unwrap(PM);
    
    StringRef SR(PassName);
    PassRegistry *PR = PassRegistry::getPassRegistry();
    
    const PassInfo *PI = PR->getPassInfo(SR);
    if (PI) {
        pm->add(PI->createPass());
        return true;
    }
    return false;
}


/// Function called by swift to add the initialiser simplification pass to the pass manager
void initialiserPass(LLVMPassManagerRef pm, LLVMModuleRef mod) {
    
    Module *module = unwrap(mod);
    std::unique_ptr<FunctionPassManager> passManager = llvm::make_unique<FunctionPassManager>(module);
    
    passManager->add(createInitialiserSimplificationPass());
    
    passManager->doInitialization();
    
    module->dump();
    
    
}






void addInitialiserSimplificationPass(const PassManagerBuilder &Builder, PassManagerBase &PM) {
//    if (Builder.OptLevel > 0) // unconditional
        PM.add(createInitialiserSimplificationPass());
}






//
//void performLLVMOptimisations(Module *Module) {
//    
//    PassManagerBuilder PMBuilder;
//    
//    PMBuilder.OptLevel = 3;
//    PMBuilder.Inliner = llvm::createFunctionInliningPass(200);
//    PMBuilder.SLPVectorize = true;
//    PMBuilder.LoopVectorize = true;
//    PMBuilder.MergeFunctions = true;
//    
//    PMBuilder.addExtension(PassManagerBuilder::EP_ModuleOptimizerEarly,
//                           addInitialiserSimplificationPass);
//    
//    
//    
//    // Configure the function passes.
//    legacy::FunctionPassManager FunctionPasses(Module);
////    FunctionPasses.add(createTargetTransformInfoWrapperPass(
////                                                            TargetMachine->getTargetIRAnalysis()));
////    if (Opts.Verify)
//        FunctionPasses.add(createVerifierPass());
//    PMBuilder.populateFunctionPassManager(FunctionPasses);
//
//    FunctionPasses.doInitialization();
//    for (auto I = Module->begin(), E = Module->end(); I != E; ++I)
//        if (!I->isDeclaration())
//            FunctionPasses.run(*I);
//    FunctionPasses.doFinalization();
//    
//    // Configure the module passes.
//    legacy::PassManager ModulePasses;
////    ModulePasses.add(createTargetTransformInfoWrapperPass(
////                                                          TargetMachine->getTargetIRAnalysis()));
//    PMBuilder.populateModulePassManager(ModulePasses);
//    
//    // If we're generating a profile, add the lowering pass now.
////    if (Opts.GenerateProfile)
//        ModulePasses.add(createInstrProfilingPass());
//    
////    if (Opts.Verify)
//        ModulePasses.add(createVerifierPass());
//    
//    // Do it.
//    ModulePasses.run(*Module);
//
//}
//
//void performLLVMOptimisations(LLVMModuleRef mod) {
//    Module *module = unwrap(mod);
//    performLLVMOptimisations(module);
//}




