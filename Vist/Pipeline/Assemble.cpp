//
//  Assemble.cpp
//  Vist
//
//  Created by Josef Willsher on 27/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include "Assemble.hpp"


// https://github.com/apple/swift/blob/master/lib/IRGen/IRGen.cpp

//legacy::PassManager EmitPasses;
//
//// Set up the final emission passes.
//switch (Opts.OutputKind) {
//    case IRGenOutputKind::Module:
//        break;
//    case IRGenOutputKind::LLVMAssembly:
//        EmitPasses.add(createPrintModulePass(*RawOS));
//        break;
//    case IRGenOutputKind::LLVMBitcode:
//        EmitPasses.add(createBitcodeWriterPass(*RawOS));
//        break;
//    case IRGenOutputKind::NativeAssembly:
//    case IRGenOutputKind::ObjectFile: {
//        llvm::TargetMachine::CodeGenFileType FileType;
//        FileType = (Opts.OutputKind == IRGenOutputKind::NativeAssembly
//                    ? llvm::TargetMachine::CGFT_AssemblyFile
//                   : llvm::TargetMachine::CGFT_ObjectFile);
//        
//        EmitPasses.add(createTargetTransformInfoWrapperPass(
//                                                            TargetMachine->getTargetIRAnalysis()));
//        
//        // Make sure we do ARC contraction under optimization.  We don't
//        // rely on any other LLVM ARC transformations, but we do need ARC
//        // contraction to add the objc_retainAutoreleasedReturnValue
//        // assembly markers.
//        if (Opts.Optimize)
//            EmitPasses.add(createObjCARCContractPass());
//            
//            bool fail = TargetMachine->addPassesToEmitFile(EmitPasses, *RawOS,
//                                                           FileType, !Opts.Verify);
//            if (fail) {
//                if (DiagMutex)
//                    DiagMutex->lock();
//                    Diags.diagnose(SourceLoc(), diag::error_codegen_init_fail);
//                    if (DiagMutex)
//                        DiagMutex->unlock();
//                        return true;
//            }
//        break;
