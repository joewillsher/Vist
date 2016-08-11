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
    
#ifndef __cplusplus
#import <Foundation/Foundation.h>
    typedef NS_ENUM(NSInteger, LLVMIntrinsic) {
#else
    enum LLVMIntrinsic {
#endif
        i_add_overflow,
        i_sub_overflow,
        i_mul_overflow,
        
        expect,
        trap,
        memcopy,
        
        lifetime_start,
        lifetime_end,
    };
        
        /// Intrinsic with a buffer of overload types
        _Nullable LLVMValueRef getIntrinsicFunction(LLVMIntrinsic,
                                                    LLVMModuleRef _Nonnull,
                                                    LLVMTypeRef _Nullable *_Nonnull,
                                                    long);
#ifdef __cplusplus // only for c++
}


#include "llvm/IR/Value.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/ADT/StringRef.h"
#include <vector>
    using namespace llvm;
    
    Function * _Nonnull getIntrinsicFn(LLVMIntrinsic intrinsic,
                                       Module *_Nonnull mod,
                                       std::vector<Type *> types);
    
    Intrinsic::ID getIntrinsicID(LLVMIntrinsic intrinsic);
    
#endif

#endif /* Intrinsic_h */
