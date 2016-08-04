//
//  VIRType.swift
//  Vist
//
//  Created by Josef Willsher on 02/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

struct VIRType {
    let type: Type
    unowned let module: Module
    
    func isAddressOnly() -> Bool { return false }
}

