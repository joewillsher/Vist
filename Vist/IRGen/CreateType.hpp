//
//  CreateType.hpp
//  Vist
//
//  Created by Josef Willsher on 10/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef CreateType_hpp
#define CreateType_hpp

#include <stdio.h>
#include "LLVM.h"

#ifdef __cplusplus
extern "C"
#endif
LLVMTypeRef createNamedType(LLVMTypeRef type, const char *name, LLVMModuleRef module);


#endif /* CreateType_hpp */
