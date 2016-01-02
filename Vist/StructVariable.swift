//
//  StructVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


//private struct Padding {
//    let alignment: Int
//    let width: Int
//}
//
//private struct StructVariable {
//    
//    let variables: [(String, Padding)]
//    
//    // FIXME: Redo the struct alignment algorithm -- currently all alignments are an equal distance apart
//    init(objects: [(String, Int)]) {
//        
//        guard let w = (objects.map{$0.1}.maxElement()) else {
//            self.variables = []
//            return
//        }
//        
//        var p: [(String, Padding)] = []
//        
//        for i in 0..<objects.count {
//            p.append((objects[i].0, Padding(alignment: w*i, width: w)))
//        }
//        
//        self.variables = p
//    }
//    
//    func paddingFor(name: String) -> Padding? {
//        guard let i = (variables.map { $0.0 }.indexOf(name)) else { return nil }
//        return variables[i].1
//    }
//}
//


//
//
//class StructVariable : RuntimeVariable, MutableVariable {
//    var type: LLVMTypeRef
//    var ptr: LLVMValueRef
//    let mutable: Bool
//    
//    var builder: LLVMBuilderRef
//    
//    var properties: [String: LLVMTypeRef]
//    
//    init(type: LLVMTypeRef, ptr: LLVMValueRef, mutable: Bool, builder: LLVMBuilderRef) {
//        self.type = type
//        self.mutable = mutable
//        self.ptr = ptr
//        self.builder = builder
//    }
//    
//    func load(name: String = "") -> LLVMValueRef {
//        return LLVMBuildLoad(builder, ptr, name)
//    }
//    
//    func isValid() -> Bool {
//        return ptr != nil
//    }
//    
//    /// returns pointer to allocated memory
//    class func alloc(builder: LLVMBuilderRef, type: LLVMTypeRef, name: String = "", mutable: Bool) -> StructVariable {
//        let ptr = LLVMBuildAlloca(builder, type, name)
//        return StructVariable(type: type, ptr: ptr, mutable: mutable, builder: builder)
//    }
//    
//    func store(val: LLVMValueRef) {
//        LLVMBuildStore(builder, val, ptr)
//    }
//    
//    private func property(name: String) -> LLVMValueRef {
//        
//        
//        
//    }
//    
//    
//}








