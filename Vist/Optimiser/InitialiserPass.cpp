//
//  InitialiserPass.cpp
//  Vist
//
//  Created by Josef Willsher on 24/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "InitialiserPass.hpp"

#include "llvm/IR/Module.h"
#include "llvm/PassManager.h"
#include "llvm/PassInfo.h"
#include "llvm/PassSupport.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/DynamicLibrary.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/IPO.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Pass.h"
#include "llvm/ADT/Statistic.h"
#include <stdio.h>

// useful instructions here: http://llvm.org/docs/WritingAnLLVMPass.html

//#define DEBUG_TYPE "initialiser-pass"

class InitialiserSimplification : public llvm::FunctionPass {

    virtual bool runOnFunction(llvm::Function &F) override;
    
public:
    static char ID;
    InitialiserSimplification() : llvm::FunctionPass(ID) {}
};


using namespace llvm;


INITIALIZE_PASS_BEGIN(InitialiserSimplification,
                      "initialiser-pass", "Vist initialiser folding pass",
                      false, false)

InitialiserSimplification::ID = 0;

INITIALIZE_PASS_END(InitialiserSimplification,
                    "initialiser-pass", "Vist initialiser folding pass",
                    false, false)

//PassInfo *PI = new PassInfo("Vist initialiser folding pass", "initialiser-pass", & InitialiserSimplification::ID, PassInfo::NormalCtor_t(callDefaultCtor<InitialiserSimplification>), false, false);
//Registry.registerPass(*PI, true);
//return PI;
//}

//void initializeInitialiserSimplificationPass(PassRegistry &Registry) {
//    CALL_ONCE_INITIALIZATION(initializeInitialiserSimplificationPassOnce);
//}

llvm::FunctionPass *createInitialiserSimplificationPass() {
    initializeInitialiserSimplificationPass(*llvm::PassRegistry::getPassRegistry());
    return new InitialiserSimplification();
}


bool InitialiserSimplification::runOnFunction(llvm::Function &F) {
    
    printf("mrmr");
    
    return false;
}




extern "C" bool
LLVMAddPass(LLVMPassManagerRef PM, const char *PassName) {
    llvm::PassManagerBase *pm = llvm::unwrap(PM);
    
    llvm::StringRef SR(PassName);
    llvm::PassRegistry *PR = llvm::PassRegistry::getPassRegistry();
    
    const llvm::PassInfo *PI = PR->getPassInfo(SR);
    if (PI) {
        pm->add(PI->createPass());
        return true;
    }
    return false;
}



void initialiserPass(LLVMPassManagerRef pm) {
    
//    InitialiserPass *pass = createInitialiserPass();
    
//    PassManagerBase *PM = unwrap(pm);
    LLVMAddPass(pm, "verify");
    
    llvm::PassRegistry *reg = llvm::PassRegistry::getPassRegistry();
    
    auto a = createInitialiserSimplificationPass();
    
    //    PassInfo x = Passinfo;
    
    //    PassRegistry *PR = PassRegistry::getPassRegistry();
    
    
}




