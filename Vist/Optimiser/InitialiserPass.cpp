//
//  InitialiserPass.cpp
//  Vist
//
//  Created by Josef Willsher on 24/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "InitialiserPass.hpp"

#include "llvm/PassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/PassInfo.h"
#include "llvm/PassSupport.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm-c/BitReader.h"

#include "LLVM.h"

#include <stdio.h>
#include <iostream>


// useful instructions here: http://llvm.org/docs/WritingAnLLVMPass.html
// swift example here https://github.com/apple/swift/blob/master/lib/LLVMPasses/LLVMStackPromotion.cpp

#define DEBUG_TYPE "initialiser-pass"
using namespace llvm;

// MARK: InitialiserSimplification pass decl

class InitialiserSimplification : public FunctionPass {
    
    MemoryBuffer *stdLibModuleBuffer;

    virtual bool runOnFunction(Function &F) override;
    
public:
    static char ID;
    
    InitialiserSimplification() : FunctionPass(ID) {
        std::string path = "/Users/JoeWillsher/Developer/Vist/Vist/stdlib/stdlib.bc";
        stdLibModuleBuffer = MemoryBuffer::getFile(path.c_str()).get().get();
    }
};

// we dont care about the ID
char InitialiserSimplification::ID = 0;



// MARK: bullshit llvm macros

// defines `initializeInitialiserSimplificationPassOnce(PassRegistry &Registry)` function
INITIALIZE_PASS_BEGIN(InitialiserSimplification,
                      "initialiser-pass", "Vist initialiser folding pass",
                      false, false)
// implements `llvm::initializeInitialiserSimplificationPass(PassRegistry &Registry)` function, declared in header
// adds it to the pass registry
INITIALIZE_PASS_END(InitialiserSimplification,
                    "initialiser-pass", "Vist initialiser folding pass",
                    false, false)

//#define PATH(a) = ##a;



// MARK: InitialiserSimplification Functions

/// returns instance of the InitialiserSimplification pass
FunctionPass *createInitialiserSimplificationPass() {
    initializeInitialiserSimplificationPass(*PassRegistry::getPassRegistry());
    return new InitialiserSimplification();
}

/// Called on functions in module, this is where the optimisations happen
bool InitialiserSimplification::runOnFunction(Function &function) {
    
    bool changed = false;

//    stdLibModule->dump();
    
    
    Module *module = function.getParent();
    LLVMContext &context = module->getContext();
    IRBuilder<> builder = IRBuilder<>(context);
    
//    func linkModule(inout module: LLVMModuleRef, withFile file: String) {
//        
//        let buffer = UnsafeMutablePointer<LLVMMemoryBufferRef>.alloc(1)
//        let str = UnsafeMutablePointer<UnsafeMutablePointer<Int8>>.alloc(1)
//        
//        LLVMCreateMemoryBufferWithContentsOfFile(file, buffer, str)
//        
//        var helperModule = LLVMModuleCreateWithName("_module")
//        
//        LLVMGetBitcodeModule(buffer.memory, &helperModule, str)
//        
//        LLVMLinkModules(module, helperModule, LLVMLinkerDestroySource, str)
//    }
    
    printf("%i\n", stdLibModuleBuffer);
    
    
    
    Module *stdLibModule = new Module(StringRef("std"), context);
    
    
    LLVMMemoryBufferRef buff = wrap(stdLibModuleBuffer);
    LLVMModuleRef m = wrap(stdLibModule);
    LLVMGetBitcodeModule(buff, &m, nullptr);
    
    unwrap(m)->dump();
    
    
//    Module *stdLibModule = parseBitcodeFile(stdLibModuleBuffer->getMemBufferRef(), context).get();
    
    
    auto s = StringRef("trivialInitialiser");
    auto id = LLVMGetMDKindID(s.data(), int32_t(s.size()));
    
    for (BasicBlock &basicBlock : function) {
        for (auto index = basicBlock.begin(); index != basicBlock.end(); ) {
            Instruction *instruction = index;
            index++;
            
            if (auto *call = dyn_cast<CallInst>(instruction)) {
                
                auto metadata = call->getMetadata(id);
                if (metadata == nullptr)
                    continue;

                auto returns = call->getType();
                
                auto res = dyn_cast<StructType>(returns);
                if (!res) // has to be a struct
                    continue;
                
                builder.SetInsertPoint(call);
                
                auto undef = UndefValue::get(res);
                Value *target = undef;
                
                for (uint i = 0; i < undef->getNumElements(); i++) {
                    auto arg = call->getArgOperand(i);
                    
                    auto ins = InsertValueInst::Create(target, arg, {i}, "");
                    builder.Insert(ins);
                    target = ins;
                };
                
                target->setName(call->getName());
                call->removeFromParent();
                call->replaceAllUsesWith(target);
                call->dropAllReferences();
                
                changed = true;
            }
        }
    }
    

    
    
    return changed;
}


/// Expose to the general optimiser function
void addInitialiserSimplificationPass(const PassManagerBuilder &Builder, PassManagerBase &PM) {
//    if (Builder.OptLevel > 0) // unconditional
        PM.add(createInitialiserSimplificationPass());
}





