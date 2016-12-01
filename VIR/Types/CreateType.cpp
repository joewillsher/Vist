//
//  CreateType.cpp
//  Vist
//
//  Created by Josef Willsher on 10/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "CreateType.hpp"

#include "llvm/IR/Value.h"
#include "llvm/IR/Module.h"
#include "llvm/ADT/ArrayRef.h"

using namespace llvm;


Type * _Nullable getNamedType(StringRef name, Module *module) {
    return module->getTypeByName(name);
}

Type * _Nullable createNamedType(Type *type, StringRef name) {
    
    std::vector<Type *> els;
    for (unsigned i = 0; i < type->getStructNumElements(); ++i) {
        els.push_back(type->getStructElementType(i));
    }
    auto elements = ArrayRef<Type *>(els);
    return StructType::create(type->getContext(), elements, name);
}

_Nullable LLVMTypeRef getNamedType(const char * _Nonnull name, LLVMModuleRef _Nonnull module) {
    return wrap(getNamedType(StringRef(name), unwrap(module)));
}

_Nullable LLVMTypeRef createNamedType(LLVMTypeRef _Nonnull type, const char * _Nonnull name) {
    return wrap(createNamedType(unwrap(type), name));
}


