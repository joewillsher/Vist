//
//  HeapInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

// MARK: Reference counting instructions

//final class HeapAllocInst : InstBase {
//    var storedType: Ty
//    
//    private init(memType: Ty, irName: String?) {
//        self.storedType = memType
//        super.init(args: [], irName: irName)
//    }
//    
//    override var type: Ty? { return BuiltinType.pointer(to: storedType) }
//    var memType: Ty? { return storedType }
//    
//    override var instVHIR: String {
//        return "\(name) = heap_alloc \(storedType) \(useComment)"
//    }
//}
