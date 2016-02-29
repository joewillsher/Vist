//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//
import Foundation

// setup module
let module = Module()
let builder = module.builder

// setup function
let fnType = FunctionType(params: [IntType(size: 64), IntType(size: 64)], returns: IntType(size: 64))
let fn = try module.addFunction("add", type: fnType, paramNames: ["a", "b"])

// build block and add insts
try builder.setInsertPoint(fn)
try builder.addBasicBlock("entry")
let _0 = try builder.createBinaryInst("iadd", l: try fn.paramNamed("a"), r: try fn.paramNamed("b"), irName: nil)
let _1 = try builder.createBinaryInst("iadd", l: Operand(_0), r: try fn.paramNamed("b"), irName: nil)
let _2 = try builder.createBinaryInst("iadd", l: Operand(_0), r: Operand(_1), irName: nil)
try builder.createReturnInst(Operand(_2))

print(module.vhir)
/*
 func @add : (%Int64, %Int64) -> %Int64 {
 #entry(%a: %Int64, %b: %Int64):
	%0 = $iadd %a: %Int64, %b: %Int64
	%1 = $iadd %0: %Int64, %b: %Int64
	%2 = $iadd %0: %Int64, %1: %Int64
	return %2
 }
*/

// test the VHIR modifying code
_0.replaceAllUsesWith(try fn.paramNamed("a"))
try _0.removeFromParent()

// rename a node
_2.name = "foo"



print(module.vhir)
/*
 func @add : (%Int64, %Int64) -> %Int64 {
 #entry(%a: %Int64, %b: %Int64):
	%0 = $iadd %a: %Int64, %b: %Int64
	%foo = $iadd %a: %Int64, %0: %Int64
	return %foo
 }
 */










/*
do {
    let flags = Array(Process.arguments.dropFirst())
    try compileWithOptions(flags, inDirectory: NSTask().currentDirectoryPath)
}
catch {
    print("", error, terminator: "\n\n")
}
*/
