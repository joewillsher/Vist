//
//  InitialiserPass.cpp
//  Vist
//
//  Created by Josef Willsher on 24/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "InitialiserPass.hpp"
#include "Optimiser.hpp"

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
#include "llvm/IR/CallSite.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/Transforms/Utils/Local.h"
#include "llvm/Transforms/IPO/InlinerPass.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/ADT/ilist_node.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils/Cloning.h"

#include "LLVM.h"

#include <stdio.h>
#include <iostream>


// useful instructions here: http://llvm.org/docs/WritingAnLLVMPass.html
// swift example here https://github.com/apple/swift/blob/master/lib/LLVMPasses/LLVMStackPromotion.cpp

#define DEBUG_TYPE "initialiser-pass"
using namespace llvm;

// MARK: StdLibInline pass decl

class StdLibInline : public FunctionPass {
    
    Module *stdLibModule;
    
    virtual bool runOnFunction(Function &F) override;
    
public:
    static char ID;
    
    StdLibInline() : FunctionPass(ID) {
        std::string path = "/Users/JoeWillsher/Developer/Vist/Vist/stdlib/stdlib.bc";
        auto b = MemoryBuffer::getFile(path.c_str());
        
        if (b.getError()) {
            stdLibModule = nullptr;
            printf("STANDARD LIBRARY NOT FOUND\nCould not run Inline-Stdlib optimiser pass\n\n");
            return;
        }
        
        // FIXME: why am I using the C API?
        MemoryBufferRef stdLibModuleBuffer = b.get().get()->getMemBufferRef();
        auto res = parseBitcodeFile(stdLibModuleBuffer, getGlobalContext());
        
        stdLibModule = res.get();
    }
    
//    ~StdLibInline() {
//        delete stdLibModule;
//    }
};

// we dont care about the ID
char StdLibInline::ID = 0;



// MARK: bullshit llvm macros

// defines `initializeStdLibInlinePassOnce(PassRegistry &Registry)` function
INITIALIZE_PASS_BEGIN(StdLibInline,
                      "initialiser-pass", "Vist initialiser folding pass",
                      false, false)
// implements `llvm::initializeStdLibInlinePass(PassRegistry &Registry)` function, declared in header
// adds it to the pass registry
INITIALIZE_PASS_END(StdLibInline,
                    "initialiser-pass", "Vist initialiser folding pass",
                    false, false)

//#define PATH(a) = ##a;



// MARK: StdLibInline Functions

/// returns instance of the StdLibInline pass
FunctionPass *createStdLibInlinePass() {
    initializeStdLibInlinePass(*PassRegistry::getPassRegistry());
    return new StdLibInline();
}


/// Called on functions in module, this is where the optimisations happen
bool StdLibInline::runOnFunction(Function &function) {
    
    bool changed = false;
    
    if (stdLibModule == nullptr)
        return false;
    
    Module *module = function.getParent();
    LLVMContext &context = module->getContext();
    IRBuilder<> builder = IRBuilder<>(context);
    
    
    int initiID = LLVMMetadataID("stdlib.init");
//    int fnID = LLVMMetadataID("stdlib.fn");
    
    // for each block in the function
    for (BasicBlock *index = function.begin(); index != function.end();) {
        BasicBlock &basicBlock = *index;
        index++;
        
        if (index == nullptr)
            break;
        
        // For each instruction in the block
        for (Instruction &instruction : basicBlock) {
            
            std::cout << function.size() << '\n';
            
            // If its a function call
            if (auto *call = dyn_cast<CallInst>(&instruction)) {
                
                // which is a standardlib one
                auto metadata = call->getMetadata(initiID);
                if (metadata == nullptr)
                    continue;
                
                // Run the stdlib inline pass
                
                // get info about caller and callee
                StringRef fnName = call->getCalledFunction()->getName();
                Type *returnType = call->getType();
                Function *calledFunction = stdLibModule->getFunction(fnName);

                if (calledFunction == nullptr)
                    continue;
                
                // move builder to call
                // add bb here
                builder.SetInsertPoint(call);
                // allocate the *return* value
                Value *returnValueStorage = builder.CreateAlloca(returnType);

                // split the current bb, and do all temp work in `inlinedBlock`
                BasicBlock *rest = basicBlock.splitBasicBlock(call, Twine("rest"));
                BasicBlock *inlinedBlock = BasicBlock::Create(context, Twine("inlined." + fnName), &function, rest);
                
                rest->replaceAllUsesWith(inlinedBlock); // move predecessors into `inlinedBlock`
                builder.SetInsertPoint(inlinedBlock); // add IR code here

                // for block & instruction in the stdlib function's definition
                for (BasicBlock &fnBlock : *calledFunction) {
                    
                    for (Instruction &inst : fnBlock) {
                        
                        // if the instruction is a return, assign to the `returnValueStorage` and jump out of temp block
                        if (auto *ret = dyn_cast<ReturnInst>(&inst)) {
                            builder.CreateStore(ret->getReturnValue(), returnValueStorage);
                            builder.CreateBr(rest);
                        }
                        // otherwise add the inst to the inlined block
                        else {
                            builder.Insert(inst.clone());
                        }
                    }
                }
                
                // move out of `inlinedBlock`
                builder.SetInsertPoint(rest, rest->begin());
                
                // replace uses of %0, %1 in the function with the parameters passed into it
                uint i = 0;
                for (Argument &fnArg : calledFunction->args()) {
                    Value *calledArg = call->getOperand(i);
                    
                    fnArg.replaceAllUsesWith(calledArg);
                    i++;
                }
                
                // finalise -- store result in return val, and remove call from bb
                Value *returnValue = builder.CreateLoad(returnValueStorage, fnName);
                call->replaceAllUsesWith(returnValue);
                call->removeFromParent();
                
                // merge blocks
                MergeBlockIntoPredecessor(inlinedBlock);
                
                index--;
                changed = true;
                break;
            }
            
        }
    }
    
    return changed;
}


/// Expose to the general optimiser function
void addStdLibInlinePass(const PassManagerBuilder &Builder, PassManagerBase &PM) {
    PM.add(createStdLibInlinePass());  // run my opt pass
    PM.add(createCFGSimplificationPass());          // remove the `inlinedBlock`
    PM.add(createPromoteMemoryToRegisterPass());    // remove the extra load & store
}





