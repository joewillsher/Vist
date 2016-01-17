//
//  TypeLowering.swift
//  Vist
//
//  Created by Josef Willsher on 27/12/2015.
//  Copyright © 2015 vistlang. All rights reserved.
//

protocol LLVMTyped : Printable, CustomDebugStringConvertible {
    func ir() -> LLVMTypeRef
    
    var isStdBool: Bool { get }
    var isStdInt: Bool { get }
    var isStdRange: Bool { get }
}

extension LLVMTyped {
    var isStdBool: Bool {
        return false
    }
    var isStdInt: Bool {
        return false
    }
    var isStdRange: Bool {
        return false
    }
}

extension NativeType : Equatable {}
extension FnType: Equatable {}



@warn_unused_result
func == (lhs: StructType, rhs: StructType) -> Bool {
    return lhs.name == rhs.name
}



func ir(val: LLVMTyped) throws -> LLVMValueRef {
    return val.ir()
}


@warn_unused_result
func ==
    <T : LLVMTyped>
    (lhs: T, rhs: T)
    -> Bool {
        return lhs.ir() == rhs.ir()
}
@warn_unused_result
func ==
    <T : LLVMTyped>
    (lhs: LLVMTyped?, rhs: T)
    -> Bool {
        return lhs?.ir() == rhs.ir()
}
@warn_unused_result
func ==
    (lhs: LLVMTyped, rhs: LLVMTyped)
    -> Bool {
        return lhs.ir() == rhs.ir()
}
@warn_unused_result
func ==
    (lhs: [LLVMTyped], rhs: [LLVMTyped])
    -> Bool {
        if lhs.isEmpty && rhs.isEmpty { return true }
        if lhs.count != rhs.count { return false }
        
        for (l,r) in zip(lhs,rhs) {
            if l == r { return true }
        }
        return false
}
extension CollectionType {
    func mapAs<T>(_: T.Type) -> [T] {
        return flatMap { $0 as? T }
    }
}



