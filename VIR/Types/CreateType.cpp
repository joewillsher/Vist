//
//  CreateType.cpp
//  Vist
//
//  Created by Josef Willsher on 10/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "CreateType.hpp"

#include "LLVM.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wall"

#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/Target/TargetIntrinsicInfo.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/LLVMContext.h"

#pragma clang diagnostic pop

using namespace llvm;


Type *getNamedType(StringRef name, Module *module) {
    return module->getTypeByName(name);
}

Type *createNamedType(Type *type, StringRef name) {
    
    std::vector<Type *> els;
    for (unsigned i = 0; i < type->getStructNumElements(); ++i) {
        els.push_back(type->getStructElementType(i));
    }
    auto elements = ArrayRef<Type *>(els);
    return StructType::create(getGlobalContext(), elements, name);
}

_Nullable LLVMTypeRef getNamedType(const char * _Nonnull name, LLVMModuleRef _Nonnull module) {
    return wrap(getNamedType(StringRef(name), unwrap(module)));
}

LLVMTypeRef createNamedType(LLVMTypeRef _Nonnull type, const char * _Nonnull name) {
    return wrap(createNamedType(unwrap(type), name));
}


