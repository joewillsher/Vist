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

#ifdef __cplusplus
extern "C"
#endif
void initialiserPass(LLVMPassManagerRef);


#ifdef __cplusplus
#include "llvm/PassRegistry.h"
namespace llvm {
    void initializeInitialiserSimplificationPass(llvm::PassRegistry &Registry);
}
#endif



#endif /* InitialiserPass_hpp */
