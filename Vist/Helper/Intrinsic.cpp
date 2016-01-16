//
//  Intrinsic.cpp
//  Vist
//
//  Created by Josef Willsher on 16/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "Intrinsic.h"

#include <stdio.h>
#include <stdlib.h>

static const char *const intrinsicNames[] = {
#define GET_INTRINSIC_NAME_TABLE
#include "llvm/IR/Intrinsics.gen"
#undef GET_INTRINSIC_NAME_TABLE
};

#import "llvm/IR/Intrinsics.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"


// http://stackoverflow.com/questions/27681500/generate-call-to-intrinsic-using-llvm-c-api

static int search(const void *p1,
                  const void *p2) {
    const char *s1 = (const char *) p1;
    const char *s2 = *(const char **) p2;
    return strcmp(s1, s2);
}
int GetLLVMIntrinsicIDFromString(const char* str,
                                 llvm::Intrinsic::ID& id) {
    void *ptr = bsearch(str, (const void *) intrinsicNames,
                        sizeof(intrinsicNames)/sizeof(const char *),
                        sizeof(const char *), search);
    if (ptr == NULL)
        return 0;
    id = (llvm::Intrinsic::ID)((((const char**) ptr) - intrinsicNames) + 1);
    return 1;
}

LLVMValueRef getIntrinsic(const char *name,
                          LLVMModuleRef mod,
                          LLVMTypeRef ty
                          ) {
    llvm::Intrinsic::ID id;
    
    GetLLVMIntrinsicIDFromString(name, id);
    
    std::vector<llvm::Type *> arg_types;
    arg_types.push_back(llvm::unwrap(ty));
    
    LLVMValueRef rt = llvm::wrap(llvm::Intrinsic::getDeclaration(llvm::unwrap(mod), id, arg_types));
    return rt;
}


//inline LLVMValueRef *wrap(const llvm::Value **Vals) {
//    return reinterpret_cast<LLVMValueRef*>(const_cast<llvm::Value**>(Vals));
//}
