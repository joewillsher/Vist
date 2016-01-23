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
extern "C"
#endif
/// Returns a LLVM intrinsic funtion from a name
///
/// If its an overloaded intrinsic, the overloaded type is needed too
///
///  http://llvm.org/docs/LangRef.html#intrinsic-functions

LLVMValueRef getIntrinsic(const char *name,
                          LLVMModuleRef mod,
                          LLVMTypeRef ty);



#endif /* Intrinsic_h */
