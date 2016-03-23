//
//  LLVM.h
//  Vist
//
//  Created by Josef Willsher on 16/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef LLVM_h
#define LLVM_h

#include "llvm-c/Analysis.h"
#include "llvm-c/BitReader.h"
#include "llvm-c/BitWriter.h"
#include "llvm-c/Core.h"
#include "llvm-c/Disassembler.h"
#include "llvm-c/ErrorHandling.h"
#include "llvm-c/ExecutionEngine.h"
#include "llvm-c/Initialization.h"
#include "llvm-c/IRReader.h"
#include "llvm-c/Linker.h"
#include "llvm-c/LinkTimeOptimizer.h"
#include "llvm-c/lto.h"
#include "llvm-c/Object.h"
#include "llvm-c/OrcBindings.h"
#include "llvm-c/Support.h"
#include "llvm-c/Target.h"
#include "llvm-c/TargetMachine.h"
#include "llvm-c/Types.h"

#include "llvm-c/Transforms/IPO.h"
#include "llvm-c/Transforms/PassManagerBuilder.h"
#include "llvm-c/Transforms/Scalar.h"
#include "llvm-c/Transforms/Vectorize.h"

#endif /* LLVM_h */
