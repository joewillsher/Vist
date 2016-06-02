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

//#ifndef __cplusplus
//NS_ASSUME_NONNULL_BEGIN
//#endif

#ifdef __cplusplus
extern "C" {
#endif
    
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wnullability-completeness"
    
    /// Intrinsic with a buffer of overload types
    _Nullable LLVMValueRef getOverloadedIntrinsic(const char * _Nonnull,
                                                  LLVMModuleRef _Nonnull,
                                                  LLVMTypeRef * _Nonnull,
                                                  int);
    #pragma clang diagnostic pop
    
    /// Intrinsic with a single overload type
    _Nullable LLVMValueRef getSinglyOverloadedIntrinsic(const char * _Nonnull name,
                                                        LLVMModuleRef _Nonnull mod,
                                                        LLVMTypeRef _Nonnull ty);
    
    /// Non overloaded intrinsic
    _Nullable LLVMValueRef getRawIntrinsic(const char * _Nonnull name,
                                           LLVMModuleRef _Nonnull mod);
    
    
#ifdef __cplusplus // only for c++
}

#include "llvm/IR/Value.h"
#include "llvm/ADT/StringRef.h"
#include <vector>

using namespace llvm;
Function *getIntrinsic(StringRef name,
                       Module *mod,
                       std::vector<Type *> types);
#endif

//#ifndef __cplusplus
//NS_ASSUME_NONNULL_END
//#endif

#endif /* Intrinsic_h */
