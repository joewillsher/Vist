//
//  CFGTest.swift
//  Vist
//
//  Created by Josef Willsher on 17/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


func testExampleCFGOpt() throws -> Bool {
    let module = Module()
    let intType = BuiltinType.int(size: 64)
    let fn = try module.builder.buildFunction(name: "test", type: FunctionType(params: [], returns: intType), paramNames: [])
    
    let b1 = try module.builder.appendBasicBlock(name: "b1")
    try module.builder.buildBreak(to: b1)
    module.builder.insertPoint.block = b1
    
    
    let imem = try module.builder.build(inst: AllocInst(memType: intType, irName: "i"))
    let i = try module.builder.build(inst: IntLiteralInst(val: 0, size: 64))
    try module.builder.build(inst: StoreInst(address: imem, value: i))
    
    let nmem = try module.builder.build(inst: AllocInst(memType: intType, irName: "n"))
    let n = try module.builder.build(inst: IntLiteralInst(val: 0, size: 64))
    try module.builder.build(inst: StoreInst(address: nmem, value: n))
    
    let b2 = try module.builder.appendBasicBlock(name: "b2")
    let b3 = try module.builder.appendBasicBlock(name: "b3")
    let b4 = try module.builder.appendBasicBlock(name: "b4")
    
    do {
        try module.builder.buildBreak(to: b2)
        module.builder.insertPoint.block = b2
        let one = try module.builder.build(inst: IntLiteralInst(val: 1, size: 64))
        let iterator = try module.builder.build(inst: LoadInst(address: imem))
        let cmp = try module.builder.build(inst: BuiltinInstCall(inst: .ieq, args: [iterator, one]))
        try module.builder.buildCondBreak(if: Operand(cmp),
                                          to: (block: b3, args: nil),
                                          elseTo: (block: b4, args: nil))
    }
    
    let b5 = try module.builder.appendBasicBlock(name: "b5")
    let b6 = try module.builder.appendBasicBlock(name: "b6")
    
    do {
        module.builder.insertPoint.block = b3
        let two = try module.builder.build(inst: IntLiteralInst(val: 2, size: 64))
        let n = try module.builder.build(inst: LoadInst(address: nmem))
        let mod = try module.builder.build(inst: BuiltinInstCall(inst: .irem, args: [n, two]))
        let zero = try module.builder.build(inst: IntLiteralInst(val: 0, size: 64))
        let cmp = try module.builder.build(inst: BuiltinInstCall(inst: .ieq, args: [mod, zero]))
        try module.builder.buildCondBreak(if: Operand(cmp),
                                          to: (block: b5, args: nil),
                                          elseTo: (block: b6, args: nil))
    }
    
    do {
        module.builder.insertPoint.block = b4
        let val = try module.builder.build(inst: LoadInst(address: imem))
        try module.builder.buildReturn(value: val)
    }
    
    let b7 = try module.builder.appendBasicBlock(name: "b7")
    
    do {
        module.builder.insertPoint.block = b5
        let val = try module.builder.build(inst: LoadInst(address: nmem))
        let two = try module.builder.build(inst: IntLiteralInst(val: 2, size: 64))
        let div = try module.builder.build(inst: BuiltinInstCall(inst: .idiv, args: [val, two]))
        try module.builder.build(inst: StoreInst(address: nmem, value: div))
        try module.builder.buildBreak(to: b7)
    }
    
    do {
        module.builder.insertPoint.block = b6
        let val = try module.builder.build(inst: LoadInst(address: nmem))
        let three = try module.builder.build(inst: IntLiteralInst(val: 3, size: 64))
        let mul = try module.builder.build(inst: BuiltinInstCall(inst: .imuloverflow, args: [val, three]))
        let one = try module.builder.build(inst: IntLiteralInst(val: 1, size: 64))
        let add = try module.builder.build(inst: BuiltinInstCall(inst: .iaddoverflow, args: [mul, one]))
        try module.builder.build(inst: StoreInst(address: nmem, value: add))
        try module.builder.buildBreak(to: b7)
    }
    
    do {
        module.builder.insertPoint.block = b7
        let val = try module.builder.build(inst: LoadInst(address: imem))
        let one = try module.builder.build(inst: IntLiteralInst(val: 1, size: 64))
        let add = try module.builder.build(inst: BuiltinInstCall(inst: .iaddoverflow, args: [val, one]))
        try module.builder.build(inst: StoreInst(address: imem, value: add))
        try module.builder.buildBreak(to: b2)
    }
    
    try RegisterPromotionPass.run(on: fn)
    
    let expected = try String(contentsOfFile: OutputTests.testDir + "/CFGPhiOptTest.txt")
    return expected == fn.vir
}

func testExampleCFGOpt2() throws -> Bool {
    let module = Module()
    let intType = BuiltinType.int(size: 64)
    let fn = try module.builder.buildFunction(name: "main", type: FunctionType(params: [BuiltinType.bool], returns: intType), paramNames: ["cond"])
    
    let b1 = try module.builder.appendBasicBlock(name: "b1")
    try module.builder.buildBreak(to: b1)
    module.builder.insertPoint.block = b1
    
    
    let imem = try module.builder.build(inst: AllocInst(memType: StdLib.intType.importedType(in: module), irName: "i"))
    let i = try module.builder.build(inst: IntLiteralInst(val: 0, size: 64))
    let iaggr = try module.builder.build(inst: StructInitInst(type: StdLib.intType, values: i, irName: "iaggr"))
    try module.builder.build(inst: StoreInst(address: imem, value: iaggr))
    
    let b2 = try module.builder.appendBasicBlock(name: "b2")
    let b3 = try module.builder.appendBasicBlock(name: "b3")
    let b4 = try module.builder.appendBasicBlock(name: "b4")
    
    try module.builder.buildCondBreak(if: Operand(fn.param(named: "cond")),
                                      to: (b2, nil),
                                      elseTo: (b3, nil))
    
    do {
        module.builder.insertPoint.block = b2
        let i2 = try module.builder.build(inst: IntLiteralInst(val: 1, size: 64))
        let i2aggr = try module.builder.build(inst: StructInitInst(type: StdLib.intType, values: i2, irName: "i2aggr"))
        try module.builder.build(inst: StoreInst(address: imem, value: i2aggr))
        try module.builder.buildBreak(to: b4)
    }
    do {
        module.builder.insertPoint.block = b3
        let i3 = try module.builder.build(inst: IntLiteralInst(val: 2, size: 64))
        let i3aggr = try module.builder.build(inst: StructInitInst(type: StdLib.intType, values: i3, irName: "i3aggr"))
        try module.builder.build(inst: StoreInst(address: imem, value: i3aggr))
        try module.builder.buildBreak(to: b4)
    }
    do {
        module.builder.insertPoint.block = b4
        let ptr = try module.builder.build(inst: StructElementPtrInst(object: imem, property: "value"))
        let val = try module.builder.build(inst: LoadInst(address: ptr))
        try module.builder.buildReturn(value: val)
    }
    
    try RegisterPromotionPass.run(on: fn)
    
    let expected = try String(contentsOfFile: OutputTests.testDir + "/CFGPhiOptTest2.txt")
    return expected == fn.vir
}

