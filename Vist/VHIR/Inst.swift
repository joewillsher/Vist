//
//  Inst.swift
//  Vist
//
//  Created by Josef Willsher on 29/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

/// An instruction o
protocol Inst: Value {
    var args: [Operand] { get }
    var type: Type? { get }
    var instName: String { get }
}
