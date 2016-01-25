//
//  InitialiserPass.hpp
//  Vist
//
//  Created by Josef Willsher on 24/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef InitialiserPass_hpp
#define InitialiserPass_hpp

#include <stdio.h>
#include "LLVM.h"



#include "llvm/PassRegistry.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/LegacyPassManager.h"

namespace llvm {
    /// Used by macro
    void initializeInitialiserSimplificationPass(llvm::PassRegistry &Registry);
}

using namespace llvm;

void addInitialiserSimplificationPass(const PassManagerBuilder&, PassManagerBase&);



#endif /* InitialiserPass_hpp */
