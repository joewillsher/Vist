//
//  StructVariable.swift
//  Vist
//
//  Created by Josef Willsher on 25/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//


private struct Padding {
    let alignment: Int
    let width: Int
}

private struct StructVariable {
    
    let variables: [(String, Padding)]
    
    // FIXME: Redo the struct alignment algorithm -- currently all alignments are an equal distance apart
    init(objects: [(String, Int)]) {
        
        guard let w = (objects.map{$0.1}.maxElement()) else {
            self.variables = []
            return
        }
        
        var p: [(String, Padding)] = []
        
        for i in 0..<objects.count {
            p.append((objects[i].0, Padding(alignment: w*i, width: w)))
        }
        
        self.variables = p
    }
    
    func paddingFor(name: String) -> Padding? {
        guard let i = (variables.map { $0.0 }.indexOf(name)) else { return nil }
        return variables[i].1
    }
}





//class StructVariable : RuntimeVariable {
//    
//    var type: LLVMTypeRef = nil
//    
//    
//    func load(name: String) -> LLVMValueRef {
//        
//    }
//    
//    func isValid() -> Bool {
//        
//    }
//    
//}








