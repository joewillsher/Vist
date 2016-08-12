//
//  CFG.swift
//  Vist
//
//  Created by Josef Willsher on 26/07/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


/**
 ```
 func @factorial_tI : &thin (#Int) -> #Int {
 $entry(%a: #Int):
   %0 = int_literal 1
   %1 = struct_extract %a: #Int, !value
   %i_eq = builtin i_eq %1: #Builtin.Int64, %0: #Builtin.Int64
   break %i_eq: #Builtin.Bool, $if.0, $fail.0

 $if.0:
   %3 = int_literal 1
   %4 = struct %Int, (%3: #Builtin.Int64)
   return %4

 $fail.0:
   break $else.1

 $else.1:
   return %a
 }
 ```
 becomes
 ```
 func @factorial_tI : &thin (#Int) -> #Int {
 $entry(%a: #Int):
   %0 = int_literal 1
   %1 = struct_extract %a: #Int, !value
   %i_eq = builtin i_eq %1: #Builtin.Int64, %0: #Builtin.Int64
   break %i_eq: #Builtin.Bool, $true, $false

 $true:
   %3 = int_literal 1
   %4 = struct %Int, (%3: #Builtin.Int64)
   break $else.1 (%4: #Int)

 $false:
   break $else.1 (%a: #Int)

 $exit(%r: #Int):
   return %a
 }
 ```
*/
enum CFGPass : OptimisationPass {

    typealias PassTarget = Function
    static let minOptLevel: OptLevel = .high
    static let name = "cfg"
    
    static func run(on function: Function) throws {
        
        /*
        for block in function.blocks {
            for case let condBreakInst as CondBreakInst in function.blocks {
                
                guard case let literal as BoolLiteralInst = condBreakInst.condition else { continue }
                
                let br = BreakInst()
                condBreakInst.parentBlock!.insert(br, after: condBreakInst)
                try condBreakInst.eraseFromParent(replacingAllUsesWith: br)
            }
        }
        */
        
    }
}

