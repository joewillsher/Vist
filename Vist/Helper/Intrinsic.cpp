//
//  Intrinsic.cpp
//  Vist
//
//  Created by Josef Willsher on 16/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "Intrinsic.hpp"
#include "TargetMachine.hpp"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

static const char *const intrinsicNames[] = {
#define GET_INTRINSIC_NAME_TABLE
#include "llvm/IR/Intrinsics.gen"
#undef GET_INTRINSIC_NAME_TABLE
};

#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/Target/TargetIntrinsicInfo.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"


using namespace llvm;

// uses code from here: http://stackoverflow.com/questions/27681500/generate-call-to-intrinsic-using-llvm-c-api

static int search(const void *p1,
                  const void *p2) {
    const char *s1 = (const char *) p1;
    const char *s2 = *(const char **) p2;
    return strcmp(s1, s2);
}

bool GetLLVMIntrinsicIDFromString(const char* str,
                                 Intrinsic::ID& id) {
    void *ptr = bsearch(str, (const void *) intrinsicNames,
                        sizeof(intrinsicNames)/sizeof(const char *),
                        sizeof(const char *), search);
    if (ptr == NULL)
        return false;
    id = (Intrinsic::ID)((((const char**) ptr) - intrinsicNames) + 1);
    
    return true;
}


Function *getIntrinsic(StringRef name,
                       Module *mod,
                       Type *ty,
                       bool removeOverload) {
    auto found = mod->getFunction(name);
    
    // horrible hack
    // if overloaded (foo.i64), drop the .i64
    // TODO: an impl using the target machine
    if (ty != nullptr && removeOverload) {
        auto u = name.str();
        u.erase(u.length()-4, u.length());
        name = StringRef(u);
    }

    // if intrinsic is already declared, return that
    if (found)
        return found;
    
    Intrinsic::ID id;
    bool isIntrinsic = GetLLVMIntrinsicIDFromString(name.data(), id);
    
    if (!isIntrinsic)
        return nullptr;
    
    std::vector<Type *> arg_types;
    if (ty != nullptr)
        arg_types.push_back(ty);
        
    return Intrinsic::getDeclaration(mod, id, arg_types);
}

/// Returns ptr to intrinsic function
LLVMValueRef getIntrinsic(const char *name,
                          LLVMModuleRef mod,
                          LLVMTypeRef ty,
                          bool removeOverload) {
    return wrap(getIntrinsic(StringRef(name), unwrap(mod), unwrap(ty), removeOverload));
}





