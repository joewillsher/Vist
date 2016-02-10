//
//  CreateType.cpp
//  Vist
//
//  Created by Josef Willsher on 10/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "CreateType.hpp"

#include "LLVM.h"

#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/Target/TargetIntrinsicInfo.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/LLVMContext.h"

using namespace llvm;


LLVMTypeRef createNamedType(LLVMTypeRef type, const char *name, LLVMModuleRef module) {
    
    Type *ty = unwrap(type);
    Module *mod = unwrap(module);
    
    auto found = mod->getTypeByName(name);
    if (found)
        return wrap(found);
    
    std::vector<Type *> els;
    for (unsigned i = 0; i < ty->getStructNumElements(); ++i) {
        els.push_back(ty->getStructElementType(i));
    }
    auto elements = ArrayRef<Type *>(els);
    
    Type *t = StructType::create(getGlobalContext(), elements, StringRef(name));
    
    return wrap(t);
}


