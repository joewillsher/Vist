//
//  Backend.hpp
//  Vist
//
//  Created by Josef Willsher on 10/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef Backend_hpp
#define Backend_hpp

#include <stdio.h>
#include "LLVM.h"

#ifdef __cplusplus
extern "C" {
#endif

    void compileModule(LLVMModuleRef module);

#ifdef __cplusplus
}
#endif

    
#endif /* Backend_hpp */
