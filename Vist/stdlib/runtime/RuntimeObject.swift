//
//  RuntimeObject.swift
//  Vist
//
//  Created by Josef Willsher on 16/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

private protocol RuntimeObject {
    func lower(IGF: IRGenFunction) -> LLVMValue
    func type(IGF: IRGenFunction) -> LLVMType
}

private extension RuntimeObject {
    
    func lower(IGF: IRGenFunction) -> LLVMValue {
        
        let children = Mirror(reflecting: self).children.map {$0.value as! RuntimeObject}
        
        var aggr = LLVMGetUndef(type(IGF).type)
        
        for (i, c) in children.enumerate() {
            var index = [UInt32(i)], v = c.lower(IGF)
            aggr = LLVMConstInsertValue(aggr, v._value, &index, 1)
        }
        
        return LLVMValue(ref: aggr)
    }
    
    func getGlobalPointer(val: LLVMValue, name: String, IGF: IRGenFunction) -> LLVMGlobalValue {
        var global = LLVMGlobalValue(module: IGF.module, type: type(IGF), name: name)
        
        global.initialiser = val
        global.isConstant = true
        return global
    }

}

extension UnsafeMutablePointer : RuntimeObject {
    private func type(IGF: IRGenFunction) -> LLVMType {
        switch memory {
        case let r as RuntimeObject:
            return r.type(IGF)
        case is Swift.Void:
            return LLVMType.opaquePointer
        default:
            fatalError()
        }
    }
    private func lower(IGF: IRGenFunction) -> LLVMValue {
        switch memory {
        case let r as RuntimeObject:
            return getGlobalPointer(r.lower(IGF), name: "ptr", IGF: IGF).value
            
        case is Swift.Void: // Swift's void pointers are opaque LLVM ones
            return LLVMValue.constNull(type: LLVMType.opaquePointer)
        default:
            fatalError()
        }
    }
}

extension Int32 : RuntimeObject {
    private func type(IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 32) }
    private func lower(IGF: IRGenFunction) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 32) }
}
extension Int64 : RuntimeObject {
    private func type(IGF: IRGenFunction) -> LLVMType { return LLVMType.intType(size: 64) }
    private func lower(IGF: IRGenFunction) -> LLVMValue { return LLVMValue.constInt(Int(self), size: 64) }
}


extension ValueWitness : RuntimeObject {
    func type(IGF: IRGenFunction) -> LLVMType { return Runtime.valueWitnessType.lowerType(Module()) }
}

extension WitnessTable : RuntimeObject {
    
    private func type(IGF: IRGenFunction) -> LLVMType { return Runtime.witnessTableType.lowerType(Module()) }
    
    func __lower(IGF: IRGenFunction) {
        let v = lower(IGF)
        getGlobalPointer(v, name: "wt", IGF: IGF)
        
        IGF.module.dump()
        
    }
    
}
extension TypeMetadata : RuntimeObject {
    func type(IGF: IRGenFunction) -> LLVMType { return Runtime.typeMetadataType.lowerType(Module()) }

    func __lower(IGF: IRGenFunction) {
        lower(IGF)
    }
}




