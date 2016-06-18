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
    
    #pragma clang diagnostic push // workaround -- this was crashing llvm without it
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wall"

#include "llvm/IR/Value.h"
#include "llvm/ADT/StringRef.h"
#include <vector>

#pragma clang diagnostic pop

using namespace llvm;
Function *_Nullable getIntrinsic(StringRef name,
                                 Module *_Nonnull mod,
                                 std::vector<Type *> types);
#endif

//#ifndef __cplusplus
//NS_ASSUME_NONNULL_END
//#endif

#endif /* Intrinsic_h */
