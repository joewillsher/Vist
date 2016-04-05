//
//  RefCountInst.swift
//  Vist
//
//  Created by Josef Willsher on 02/04/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

// MARK: Reference counting instructions

final class AllocObjectInst : InstBase, LValue {
    var storedType: StructType
    
    private init(memType: StructType, irName: String?) {
        self.storedType = memType
        super.init(args: [], irName: irName)
    }
    
    var refType: Ty { return storedType.refCountedBox(module).usingTypesIn(module) }
    override var type: Ty? { return memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Ty? { return Runtime.refcountedObjectType.usingTypesIn(module) }
    
    override var instVHIR: String {
        return "\(name) = alloc_object \(refType) \(useComment)"
    }
}

final class RetainInst : InstBase {
    var object: PtrOperand
    
    private init(object: PtrOperand, irName: String?) {
        self.object = object
        super.init(args: [object], irName: irName)
    }
    
    override var type: Ty? { return object.memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Ty? { return object.memType }
    
    override var instHasSideEffects: Bool { return true }
    
    override var instVHIR: String {
        return "\(name) = retain_object \(object) \(useComment)"
    }
}

final class ReleaseInst : InstBase {
    var object: PtrOperand
    
    private init(object: PtrOperand, irName: String?) {
        self.object = object
        super.init(args: [object], irName: irName)
    }
    
    override var type: Ty? { return object.memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Ty? { return object.memType }
    
    override var instHasSideEffects: Bool { return true }
    
    override var instVHIR: String {
        return "\(name) = release_object \(object) \(useComment)"
    }
}

final class ReleaseUnownedInst : InstBase {
    var object: PtrOperand
    
    private init(object: PtrOperand, irName: String?) {
        self.object = object
        super.init(args: [object], irName: irName)
    }
    
    override var type: Ty? { return object.memType.map { BuiltinType.pointer(to: $0) } }
    var memType: Ty? { return object.memType }
    
    override var instHasSideEffects: Bool { return true }
    
    override var instVHIR: String {
        return "\(name) = release_unretained_object \(object) \(useComment)"
    }
}


extension Builder {
    
    func buildAllocObject(type: StructType, irName: String? = nil) throws -> AllocObjectInst {
        return try _add(AllocObjectInst(memType: type, irName: irName))
    }
    func buildRetain(object: PtrOperand, irName: String? = nil) throws -> RetainInst {
        return try _add(RetainInst(object: object, irName: irName))
    }
    func buildRelease(object: PtrOperand, irName: String? = nil) throws -> ReleaseInst {
        return try _add(ReleaseInst(object: object, irName: irName))
    }
    func buildReleaseUnowned(object: PtrOperand, irName: String? = nil) throws -> ReleaseUnownedInst {
        return try _add(ReleaseUnownedInst(object: object, irName: irName))
    }
    
}


