//
//  CreateType.hpp
//  Vist
//
//  Created by Josef Willsher on 10/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef CreateType_hpp
#define CreateType_hpp

#include <stdio.h>
#include "LLVM.h"

#ifdef __cplusplus
extern "C" {
#endif

    LLVMTypeRef getNamedType(const char *name, LLVMModuleRef module);
    LLVMTypeRef createNamedType(LLVMTypeRef type, const char *name);
    
#ifdef __cplusplus
}

#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"

using namespace llvm;

Type *getNamedType(StringRef name, Module *module);
Type *createNamedType(Type *type, StringRef name);

#endif

#endif /* CreateType_hpp */
