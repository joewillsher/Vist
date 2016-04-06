//
//  StringEncoding.hpp
//  Vist
//
//  Created by Josef Willsher on 05/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef StringEncoding_hpp
#define StringEncoding_hpp

#include "LLVM.h"

#ifdef __cplusplus
extern "C"
#endif
LLVMValueRef convertToUTF16(const char *utf8, LLVMModuleRef module);
    

#endif /* StringEncoding_hpp */
