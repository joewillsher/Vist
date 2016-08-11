//
//  Intrinsic.cpp
//  Vist
//
//  Created by Josef Willsher on 16/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "Intrinsic.hpp"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"
#include "llvm/Target/TargetIntrinsicInfo.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

using namespace llvm;

Intrinsic::ID getIntrinsicID(LLVMIntrinsic intrinsic) {
    switch (intrinsic) {
            case LLVMIntrinsic::i_add_overflow: return Intrinsic::sadd_with_overflow;
            case LLVMIntrinsic::i_sub_overflow: return Intrinsic::ssub_with_overflow;
            case LLVMIntrinsic::i_mul_overflow: return Intrinsic::smul_with_overflow;
            case LLVMIntrinsic::expect: return Intrinsic::expect;
            case LLVMIntrinsic::trap: return Intrinsic::trap;
            case LLVMIntrinsic::memcopy: return Intrinsic::memcpy;
            case LLVMIntrinsic::lifetime_start: return Intrinsic::lifetime_start;
            case LLVMIntrinsic::lifetime_end: return Intrinsic::lifetime_end;
    }
}


Function *getIntrinsicFn(LLVMIntrinsic intrinsic,
                         Module *mod,
                         std::vector<Type *> types) {
    
    return llvm::Intrinsic::getDeclaration(mod, getIntrinsicID(intrinsic), types);
}


/// Returns ptr to intrinsic function
_Nonnull LLVMValueRef getIntrinsicFunction(LLVMIntrinsic intrinsic,
                                           LLVMModuleRef _Nonnull mod,
                                           LLVMTypeRef * _Nonnull ty,
                                           long numArgs) {
    auto t = ty;
    std::vector<Type *> arg_types;
    if (ty != nullptr)
    for (long i = 0; i < numArgs; ++i) {
        arg_types.push_back(*unwrap(t));
        ++t;
    }
    
    return wrap(getIntrinsicFn(intrinsic, unwrap(mod), arg_types));
}




