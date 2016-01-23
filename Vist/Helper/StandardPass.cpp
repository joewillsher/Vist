//
//  StandardPass.cpp
//  Vist
//
//  Created by Josef Willsher on 22/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "StandardPass.hpp"

#include "llvm/ADT/Triple.h"
#include "llvm/Analysis/CallGraph.h"
#include "llvm/Analysis/CallGraphSCCPass.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/Analysis/RegionPass.h"
//#include "llvm/Analysis/TargetLibraryInfo.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/Bitcode/BitcodeWriterPass.h"
#include "llvm/CodeGen/CommandFlags.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/IR/IRPrintingPasses.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/LegacyPassNameParser.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/InitializePasses.h"
#include "llvm/LinkAllIR.h"
#include "llvm/LinkAllPasses.h"
#include "llvm/MC/SubtargetFeature.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/PluginLoader.h"
#include "llvm/Support/PrettyStackTrace.h"
#include "llvm/Support/Signals.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/SystemUtils.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include <algorithm>
#include <memory>

using namespace llvm;


void registerStandardPasses(LLVMModuleRef mod) {

    // Enable debug stream buffering.
    EnableDebugBuffering = true;
    
    llvm_shutdown_obj Y;  // Call llvm_shutdown() on exit.
    LLVMContext &Context = getGlobalContext();
    
    InitializeAllTargets();
    InitializeAllTargetMCs();
    InitializeAllAsmPrinters();
    
    // Initialize passes
    PassRegistry &Registry = *PassRegistry::getPassRegistry();
    initializeCore(Registry);
    initializeScalarOpts(Registry);
    initializeObjCARCOpts(Registry);
    initializeVectorization(Registry);
    initializeIPO(Registry);
    initializeAnalysis(Registry);
    initializeTransformUtils(Registry);
    initializeInstCombine(Registry);
    initializeInstrumentation(Registry);
    initializeTarget(Registry);
    // For codegen passes, only passes that do IR to IR transformation are
    // supported.
    initializeCodeGenPreparePass(Registry);
    initializeAtomicExpandPass(Registry);
    initializeRewriteSymbolsPass(Registry);
    initializeCodeGenPreparePass(Registry);
    initializeCodeGenPreparePass(Registry);
    initializeCodeGenPreparePass(Registry);
    
    auto M = std::unique_ptr<Module>(unwrap(mod));
    
    
    Triple ModuleTriple(M->getTargetTriple());
    std::string CPUStr, FeaturesStr;
    TargetMachine *Machine = nullptr;
    const TargetOptions Options = InitTargetOptionsFromCodeGenFlags();
    
    if (ModuleTriple.getArch()) {
        CPUStr = sys::getHostCPUName();
        FeaturesStr = getFeaturesStr();
        Machine = GetTargetMachine(ModuleTriple, CPUStr, FeaturesStr, Options);
    }
    
    std::unique_ptr<TargetMachine> TM(Machine);
    
    // Override function attributes based on CPUStr, FeaturesStr, and command line
    // flags.
//    setFunctionAttributes(CPUStr, FeaturesStr, *M);
    
    // If the output is set to be emitted to standard out, and standard out is a
    // console, print out a warning message and refuse to do it.  We don't
    // impress anyone by spewing tons of binary goo to a terminal.
    if (!Force && !NoOutput && !AnalyzeOnly && !OutputAssembly)
        if (CheckBitcodeOutputToConsole(Out->os(), !Quiet))
            NoOutput = true;
    
//    if (PassPipeline.getNumOccurrences() > 0) {
//        OutputKind OK = OK_NoOutput;
//        if (!NoOutput)
//            OK = OutputAssembly ? OK_OutputAssembly : OK_OutputBitcode;
//        
//        VerifierKind VK = VK_VerifyInAndOut;
//        if (NoVerify)
//            VK = VK_NoVerifier;
//        else if (VerifyEach)
//            VK = VK_VerifyEachPass;
//        
//        // The user has asked to use the new pass manager and provided a pipeline
//        // string. Hand off the rest of the functionality to the new code for that
//        // layer.
//        return runPassPipeline(argv[0], Context, *M, TM.get(), Out.get(),
//                               PassPipeline, OK, VK, PreserveAssemblyUseListOrder,
//                               PreserveBitcodeUseListOrder)
//        ? 0
//        : 1;
//    }
    
    // Create a PassManager to hold and optimize the collection of passes we are
    // about to build.
    //
    legacy::PassManager Passes;
    
    // Add an appropriate TargetLibraryInfo pass for the module's triple.
    TargetLibraryInfoImpl TLII(ModuleTriple);
    
    // The -disable-simplify-libcalls flag actually disables all builtin optzns.
    if (DisableSimplifyLibCalls)
        TLII.disableAllFunctions();
    Passes.add(new TargetLibraryInfoWrapperPass(TLII));
    
    // Add an appropriate DataLayout instance for this module.
    const DataLayout &DL = M->getDataLayout();
    if (DL.isDefault() && !DefaultDataLayout.empty()) {
        M->setDataLayout(DefaultDataLayout);
    }
    
    // Add internal analysis passes from the target machine.
    Passes.add(createTargetTransformInfoWrapperPass(TM ? TM->getTargetIRAnalysis()
                                                    : TargetIRAnalysis()));
    
    std::unique_ptr<legacy::FunctionPassManager> FPasses;
    if (OptLevelO1 || OptLevelO2 || OptLevelOs || OptLevelOz || OptLevelO3) {
        FPasses.reset(new legacy::FunctionPassManager(M.get()));
        FPasses->add(createTargetTransformInfoWrapperPass(
                                                          TM ? TM->getTargetIRAnalysis() : TargetIRAnalysis()));
    }
    
    if (PrintBreakpoints) {
        // Default to standard output.
        if (!Out) {
            if (OutputFilename.empty())
                OutputFilename = "-";
            
            std::error_code EC;
            Out = llvm::make_unique<tool_output_file>(OutputFilename, EC,
                                                      sys::fs::F_None);
            if (EC) {
                errs() << EC.message() << '\n';
                return 1;
            }
        }
        Passes.add(createBreakpointPrinter(Out->os()));
        NoOutput = true;
    }
    
    // Create a new optimization pass for each one specified on the command line
    for (unsigned i = 0; i < PassList.size(); ++i) {
        if (StandardLinkOpts &&
            StandardLinkOpts.getPosition() < PassList.getPosition(i)) {
            AddStandardLinkPasses(Passes);
            StandardLinkOpts = false;
        }
        
        if (OptLevelO1 && OptLevelO1.getPosition() < PassList.getPosition(i)) {
            AddOptimizationPasses(Passes, *FPasses, 1, 0);
            OptLevelO1 = false;
        }
        
        if (OptLevelO2 && OptLevelO2.getPosition() < PassList.getPosition(i)) {
            AddOptimizationPasses(Passes, *FPasses, 2, 0);
            OptLevelO2 = false;
        }
        
        if (OptLevelOs && OptLevelOs.getPosition() < PassList.getPosition(i)) {
            AddOptimizationPasses(Passes, *FPasses, 2, 1);
            OptLevelOs = false;
        }
        
        if (OptLevelOz && OptLevelOz.getPosition() < PassList.getPosition(i)) {
            AddOptimizationPasses(Passes, *FPasses, 2, 2);
            OptLevelOz = false;
        }
        
        if (OptLevelO3 && OptLevelO3.getPosition() < PassList.getPosition(i)) {
            AddOptimizationPasses(Passes, *FPasses, 3, 0);
            OptLevelO3 = false;
        }
        
        const PassInfo *PassInf = PassList[i];
        Pass *P = nullptr;
        if (PassInf->getTargetMachineCtor())
            P = PassInf->getTargetMachineCtor()(TM.get());
        else if (PassInf->getNormalCtor())
            P = PassInf->getNormalCtor()();
        else
            errs() << argv[0] << ": cannot create pass: "
            << PassInf->getPassName() << "\n";
        if (P) {
            PassKind Kind = P->getPassKind();
            addPass(Passes, P);
            
            if (AnalyzeOnly) {
                switch (Kind) {
                    case PT_BasicBlock:
                        Passes.add(createBasicBlockPassPrinter(PassInf, Out->os(), Quiet));
                        break;
                    case PT_Region:
                        Passes.add(createRegionPassPrinter(PassInf, Out->os(), Quiet));
                        break;
                    case PT_Loop:
                        Passes.add(createLoopPassPrinter(PassInf, Out->os(), Quiet));
                        break;
                    case PT_Function:
                        Passes.add(createFunctionPassPrinter(PassInf, Out->os(), Quiet));
                        break;
                    case PT_CallGraphSCC:
                        Passes.add(createCallGraphPassPrinter(PassInf, Out->os(), Quiet));
                        break;
                    default:
                        Passes.add(createModulePassPrinter(PassInf, Out->os(), Quiet));
                        break;
                }
            }
        }
        
        if (PrintEachXForm)
            Passes.add(
                       createPrintModulePass(errs(), "", PreserveAssemblyUseListOrder));
    }
    
    if (StandardLinkOpts) {
        AddStandardLinkPasses(Passes);
        StandardLinkOpts = false;
    }
    
    if (OptLevelO1)
        AddOptimizationPasses(Passes, *FPasses, 1, 0);
    
    if (OptLevelO2)
        AddOptimizationPasses(Passes, *FPasses, 2, 0);
    
    if (OptLevelOs)
        AddOptimizationPasses(Passes, *FPasses, 2, 1);
    
    if (OptLevelOz)
        AddOptimizationPasses(Passes, *FPasses, 2, 2);
    
    if (OptLevelO3)
        AddOptimizationPasses(Passes, *FPasses, 3, 0);
    
    if (OptLevelO1 || OptLevelO2 || OptLevelOs || OptLevelOz || OptLevelO3) {
        FPasses->doInitialization();
        for (Function &F : *M)
            FPasses->run(F);
        FPasses->doFinalization();
    }
    
    // Check that the module is well formed on completion of optimization
    if (!NoVerify && !VerifyEach)
        Passes.add(createVerifierPass());
    
    // In run twice mode, we want to make sure the output is bit-by-bit
    // equivalent if we run the pass manager again, so setup two buffers and
    // a stream to write to them. Note that llc does something similar and it
    // may be worth to abstract this out in the future.
    SmallVector<char, 0> Buffer;
    SmallVector<char, 0> CompileTwiceBuffer;
    std::unique_ptr<raw_svector_ostream> BOS;
    raw_ostream *OS = nullptr;
    
    // Write bitcode or assembly to the output as the last step...
    if (!NoOutput && !AnalyzeOnly) {
        assert(Out);
        OS = &Out->os();
        if (RunTwice) {
            BOS = make_unique<raw_svector_ostream>(Buffer);
            OS = BOS.get();
        }
        if (OutputAssembly)
            Passes.add(createPrintModulePass(*OS, "", PreserveAssemblyUseListOrder));
        else
            Passes.add(createBitcodeWriterPass(*OS, PreserveBitcodeUseListOrder));
    }
    
    // Before executing passes, print the final values of the LLVM options.
    cl::PrintOptionValues();
    
    // If requested, run all passes again with the same pass manager to catch
    // bugs caused by persistent state in the passes
    if (RunTwice) {
        std::unique_ptr<Module> M2(CloneModule(M.get()));
        Passes.run(*M2);
        CompileTwiceBuffer = Buffer;
        Buffer.clear();
    }
    
    // Now that we have all of the passes ready, run them.
    Passes.run(*M);
    
    // Compare the two outputs and make sure they're the same
    if (RunTwice) {
        assert(Out);
        if (Buffer.size() != CompileTwiceBuffer.size() ||
            (memcmp(Buffer.data(), CompileTwiceBuffer.data(), Buffer.size()) !=
             0)) {
                errs() << "Running the pass manager twice changed the output.\n"
                "Writing the result of the second run to the specified output.\n"
                "To generate the one-run comparison binary, just run without\n"
                "the compile-twice option\n";
                Out->os() << BOS->str();
                Out->keep();
                return 1;
            }
        Out->os() << BOS->str();
    }
    
    // Declare success.
    if (!NoOutput || PrintBreakpoints)
        Out->keep();
    
    return 0;
}
;