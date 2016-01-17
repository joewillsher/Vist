//
//  StructType.swift
//  Vist
//
//  Created by Josef Willsher on 17/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

final class StructType: LLVMTyped {
    let name: String
    let members: [(String, LLVMTyped, Bool)]
    var methods: [(String, FnType)]
    
    init(members: [(String, LLVMTyped, Bool)], methods: [(String, FnType)], name: String) {
        self.name = name
        self.members = members
        self.methods = methods
    }
    
    func ir() -> LLVMTypeRef {
        let arr = members
            .map { $0.1.ir() }
            .ptr()
        defer { arr.dealloc(members.count) }
        
        return LLVMStructType(
            arr,
            UInt32(members.count),
            LLVMBool(false))
    }
    
    func propertyType(name: String) throws -> LLVMTyped? {
        guard let i = (members.indexOf { $0.0 == name }) else { throw SemaError.NoPropertyNamed(name) }
        return members[i].1
    }
    
    static func named(n: String) -> StructType {
        return StructType(members: [], methods: [], name: n)
    }
    static func withProperties(ps: [LLVMTyped], gen: (Int -> String) = { _ in ""}) -> StructType {
        return StructType(members: ps.enumerate().map {(gen($0), $1, false)}, methods: [], name: "")
    }
    
    var isStdBool: Bool {
        return name == "Bool" && members[0].0 == "value"
    }
    var isStdInt: Bool {
        return name == "Int" && members[0].0 == "value"
    }
    var isStdRange: Bool {
        // TODO: make these `contains` functions indep of layout
        return name == "Range" && members[0].0 == "start" && members[1].0 == "end"
    }
}

extension StructType {
    
    subscript (function function: String, paramTypes types: [LLVMTyped]) -> FnType? {
        get {
            if let v = methods[raw: function, paramTypes: types] { return v }
            return nil
        }
    }
}


