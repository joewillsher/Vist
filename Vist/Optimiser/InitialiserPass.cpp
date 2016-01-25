//
//  InitialiserPass.cpp
//  Vist
//
//  Created by Josef Willsher on 24/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "InitialiserPass.hpp"

#include "llvm/PassManager.h"
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

// MARK: InitialiserSimplification pass decl

class InitialiserSimplification : public llvm::FunctionPass {
    
    virtual bool runOnFunction(llvm::Function &F) override;
    
public:
    static char ID;
    InitialiserSimplification() : llvm::FunctionPass(ID) {}
};

// we dont care about the ID
char InitialiserSimplification::ID = 0;


using namespace llvm;

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
llvm::FunctionPass *createInitialiserSimplificationPass() {
    initializeInitialiserSimplificationPass(*llvm::PassRegistry::getPassRegistry());
    return new InitialiserSimplification();
}

/// Called on functions in module, this is where the optimisations happen
bool InitialiserSimplification::runOnFunction(llvm::Function &F) {
    
    printf("mrmr");
    
    return false;
}



/// Adds a named pass, not used yet
bool
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


/// Function called by swift to add the initialiser simplification pass to the pass manager
void initialiserPass(LLVMPassManagerRef pm) {
    
    auto a = createInitialiserSimplificationPass();
    
    // ...
}




