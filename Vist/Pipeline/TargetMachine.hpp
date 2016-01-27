//
//  TargetMachine.hpp
//  Vist
//
//  Created by Josef Willsher on 27/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef TargetMachine_hpp
#define TargetMachine_hpp

#include <stdio.h>
#include "llvm/Target/TargetMachine.h"

using namespace llvm;
TargetMachine *createTargetMachine();

#endif /* TargetMachine_hpp */
