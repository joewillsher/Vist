//
//  VHIR.swift
//  Vist
//
//  Created by Josef Willsher on 28/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// Printable item as VHIR code
protocol VHIR {
    var vhir: String { get }
}




final class Function: VHIR {
    var name: String
    var type: Type
    var blocks: [BasicBlock]?
    
    init(name: String, type: Type, blocks: [BasicBlock]?) {
        self.name = name
        self.type = type
        self.blocks = blocks
    }
    
    var vhir: String {
        
        let b = blocks?.map { $0.vhir }
        let bString = b.map { "\n" + $0.joinWithSeparator("\n") } ?? ""
        return "func @\(name) : \(type.vhir)" + bString
    }
}



final class Module: VHIR {
    
    var functions: [Function] = []
    var vhir: String { return "" }
    
}








protocol Inst: VHIR {
}
protocol Value: VHIR {
}
protocol Type: VHIR {
}



final class BasicBlock: VHIR {
    private var parameters: [Value] = []
    private var instructions: [Inst] = []
    
    var vhir: String { return "" }
}


final class IntrinsicFunctionCallInst: Inst {
    var function: IntrinsicFunction
    var params: [Value]
    
    init?(function: String, params: [Value]) {
        if let f = IntrinsicFunction(rawValue: function) {
            self.function = f
            self.params = params
        }
        else { return nil }
    }
    
    var vhir: String {
        return function.rawValue
    }
}

enum IntrinsicFunction: String {
    case iadd, imul, isub
}
enum BuiltinTypes {
    case int, int32, float, double, bool
}





struct IntType: Type {
    let size: Int
    init(size: Int) { self.size = size }
}
struct FunctionType: Type {
    let params: [Type], returns: Type
    init(params: [Type], returns: Type) {
        self.params = params
        self.returns = returns
    }
}

extension CollectionType where Generator.Element == Type {
    func typeTupleVHIR() -> String {
        let a = map { "\($0.vhir)" }
        return "(\(a.joinWithSeparator(", ")))"
    }
}
extension IntType {
    var vhir: String { return "%Int\(size)" }
}
extension FunctionType {
    var vhir: String {
        return "\(params.typeTupleVHIR()) -> \(returns.vhir)"
    }
}






