//
//  Intrinsic.h
//  Vist
//
//  Created by Josef Willsher on 16/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef Intrinsic_h
#define Intrinsic_h

#include "LLVM.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    /// Intrinsic with a buffer of overload types
    LLVMValueRef getOverloadedIntrinsic(const char *name,
                                        LLVMModuleRef mod,
                                        LLVMTypeRef *ty,
                                        int overloadTypes,
                                        bool removeOverload);
    
    /// Intrinsic with a single overload type
    LLVMValueRef getSinglyOverloadedIntrinsic(const char *name,
                                              LLVMModuleRef mod,
                                              LLVMTypeRef ty,
                                              bool removeOverload);
    
    /// Non overloaded intrinsic
    LLVMValueRef getRawIntrinsic(const char *name,
                                 LLVMModuleRef mod);
    
    
#ifdef __cplusplus // only for c++
}
#include "llvm/IR/Value.h"
#include "llvm/ADT/StringRef.h"
#include <vector>

using namespace llvm;
Function *getIntrinsic(StringRef name,
                       Module *mod,
                       std::vector<Type *> types,
                       bool removeOverload);
#endif

#endif /* Intrinsic_h */
