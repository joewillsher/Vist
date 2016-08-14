//
//  Backend.hpp
//  Vist
//
//  Created by Josef Willsher on 11/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef Backend_hpp
#define Backend_hpp

#include "LLVM.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    const char * _Nonnull getHostTriple();
    const char * _Nonnull getHostCPUName();
    
    void compileModule(LLVMModuleRef _Nonnull module);
    
#ifdef __cplusplus
}
#endif



#endif /* Backend_hpp */
