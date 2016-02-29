//
//  Function.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/// A VHIR function, has a type and ismade of a series
/// of basic blocks
final class Function: VHIR {
    var name: String
    var type: FunctionType
    var paramNames: [String]
    var blocks: [BasicBlock]?
    
    init(name: String, type: FunctionType, paramNames: [String]) {
        self.name = name
        self.type = type
        self.paramNames = paramNames
    }
    
    var hasBody: Bool { return (blocks?.count != 0) ?? false }
    
    func getEntryBlock() throws -> BasicBlock {
        guard let first = blocks?.first else { throw VHIRError.noFunctionBody }
        return first
    }
    func getLastBlock() throws -> BasicBlock {
        guard let last = blocks?.last else { throw VHIRError.noFunctionBody }
        return last
    }
    
    func paramNamed(name: String) throws -> Operand {
        guard let p = try blocks?.first?.paramNamed(name) else { throw VHIRError.noParamNamed(name) }
        return p
    }
}