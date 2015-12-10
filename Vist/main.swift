//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


import LLVM




//private var runtimeVariables: [String: LLVMTypeRef] = [:]
//private var funtionTable: [String: FunctionType] = [:]
//private let context = LLVM.Context.globalContext
//private let builder = LLVM.Builder(inContext: context)
//private let module = LLVM.Module(name: "vist", context: context)
//private let passManager = LLVMCreatePassManager()

//
//
//let f = Function(name: "add", type: t, inModule: module)
//
//let d = ["a", "b"]
//
//for (i, param) in f.params.enumerate() {
//    LLVMSetValueName(param.ref, d[i])
//}
//let bb = BasicBlock(name: "ass", fn: f)

//let context = LLVMGetGlobalContext(), module = LLVMModuleCreateWithName("vist")


print("\n\n")

//let i = LLVMInt64Type()
//let type = LLVMFunctionType(i, [i,i].ptr(), 2, LLVMBool(false))
//
//let addFunction = LLVMAddFunction(module, "add", type)
//
//let entry = LLVMAppendBasicBlock(addFunction, "entry")
//
//
//let builder = LLVMCreateBuilder()
//LLVMPositionBuilderAtEnd(builder, entry)
//
//let two = LLVMConstInt(LLVMInt64Type(), 2, LLVMBool(false))
//
//let tmp = LLVMBuildAdd(builder, LLVMGetParam(addFunction, 0), LLVMGetParam(addFunction, 1), "tmp")
//let product = LLVMBuildMul(builder, tmp, two, "product")
//LLVMBuildRet(builder, product)




//LLVMDumpValue(addFunction)

//let pm = LLVMCreateFunctionPassManagerForModule(module)
//LLVMRunFunctionPassManager(pm, tmp)











do {
    
    try compileDocument(Process.arguments.dropFirst().last!)
    print("\n")
    
    // http://llvm.org/releases/2.6/docs/tutorial/JITTutorial1.html
    
    // do implemetation of this here to get IR Gen going
    
} catch {
    print(error)
}

