//
//  TargetMachine.hpp
//  Vist
//
//  Created by Josef Willsher on 27/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef TargetMachine_hpp
#define TargetMachine_hpp

#include <stdio.h>
#include "LLVM.h"

#ifdef _cplusplus
extern "C" {
#endif

//    LLVMTargetMachineRef *createLLVMTargetMachine();
    
#ifdef _cplusplus
}

#include "llvm/IR/Value.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;
TargetMachine *createTargetMachine();


#endif

#endif /* TargetMachine_hpp */
