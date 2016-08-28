//
//  main.swift
//  Vist
//
//  Created by Josef Willsher on 16/08/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//
import class Foundation.Task
//
//
//do {
//    let module = Module()
//    let intType = BuiltinType.int(size: 64)
//    
//    let conc = ConceptType(name: "Test", requiredFunctions: [], requiredProperties: [(name: "a", type: intType, isMutable: false)])
//    let conf = StructType(members: [(name: "a", type: intType, isMutable: false)], methods: [], name: "Conforms")
//    let cont = StructType(members: [(name: "conf", type: conf.importedType(in: module), isMutable: false)], methods: [], name: "Container")
//
//    let fn = try module.builder.buildFunction(name: "test",
//                                              type: FunctionType(params: [cont.ptrType()], returns: intType),
//                                              params: [(name: "val", convention: .inout)])
//    
//    var gen = VIRGenFunction(scope: VIRGenScope(module: module),
//                             builder: module.builder)
//    
//    
//    let param = try fn.param(named: "val").managed(gen: gen)
//    let int = try gen.builder.build(IntLiteralInst(val: 1, size: 64))
//    var managedInt = Managed<IntLiteralInst>.forUnmanaged(int, gen: gen)
//    // create owned memory for the int
//    let intMem = try gen.emitTempAlloc(memType: intType)
//    // forward the int's destructor responisbility to the memory, as we assign into it
//    try managedInt.forward(into: intMem, gen: gen)
//    
//    // init a struct
//    let str = try gen.builder.build(StructInitInst(type: conf,
//                                                         values: managedInt.forward()))
//    var managedStr = Managed<StructInitInst>.forUnmanaged(str, gen: gen)
//    
//    // create an existential which owns its own memory
//    let ex = try gen.builder.build(ExistentialConstructInst(value: managedStr.value,
//                                                                  existentialType: conc,
//                                                                  module: module))
//    var managedEx = Managed<ExistentialConstructInst>.forUnmanaged(ex, gen: gen)
//    
//    
//    try managedEx.copy(into: param, gen: gen)
//    
//    try gen.cleanup()
//    
//    module.dump()
//    
//    module.dump()
//
//}
//catch {
//    
//}



do {
    let flags = Array(Process.arguments.dropFirst())
    try compile(withFlags: flags, inDirectory: Task().currentDirectoryPath, out: nil)
}
catch {
    print(error, terminator: "\n\n")
}
