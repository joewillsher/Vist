//
//  StringEncoding.cpp
//  Vist
//
//  Created by Josef Willsher on 05/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "StringEncoding.hpp"
#include "llvm/IR/Module.h"
#include "llvm/IR/TypeBuilder.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/GlobalAlias.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/Support/Path.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Transforms/Utils/Local.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/Support/ConvertUTF.h"
#include "LLVM.h"

#include <string>
#include <locale>
#include <codecvt>
#include <iostream>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#include <stdio.h>
#include <string.h>


using namespace llvm;

// https://github.com/apple/swift/blob/52cd8718de0d3876ff707c83232b6faeb2ea7ba3/lib/IRGen/GenDecl.cpp#L2845

/// Get or create a global UTF-16 string constant.
///
/// \returns an i16* with a null terminator; note that embedded nulls
///   are okay
Value *_convertToUTF16(StringRef utf8, Module *module) {
    
    // If not, first transcode it to UTF16.
    SmallVector<UTF16, 128> buffer(utf8.size() + 1); // +1 for ending nulls.
    const UTF8 *fromPtr = (const UTF8 *) utf8.data();
    UTF16 *toPtr = &buffer[0];
    (void) ConvertUTF8toUTF16(&fromPtr, fromPtr + utf8.size(),
                              &toPtr, toPtr + utf8.size(),
                              strictConversion);
    
    // The length of the transcoded string in UTF-8 code points.
    size_t utf16Length = toPtr - &buffer[0];
    
    // Null-terminate the UTF-16 string.
    *toPtr = 0;
    ArrayRef<UTF16> utf16(&buffer[0], utf16Length + 1);
    
    LLVMContext &context = module->getContext();
    IRBuilder<> builder = IRBuilder<>(context);
    
    auto init = llvm::ConstantDataArray::get(context, utf16);
    auto global = new llvm::GlobalVariable(*module, init->getType(), true,
                                           llvm::GlobalValue::PrivateLinkage,
                                           init);
    global->setUnnamedAddr(true);
    
    // Drill down to make an i16*.
    auto int16Ty = IntegerType::getInt16Ty(context);
    auto zero = ConstantInt::get(int16Ty, 0);
    llvm::Constant *indices[] = { zero, zero };
    return ConstantExpr::getInBoundsGetElementPtr(global, indices);
};

LLVMValueRef convertToUTF16(const char *utf8, LLVMModuleRef module) {
    return wrap(_convertToUTF16(StringRef(utf8), unwrap(module)));
};


