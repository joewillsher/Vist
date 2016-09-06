
/*
extension RandomAccessCollection where Index == Self.Indices.Iterator.Element, Self : MutableCollection {
    
    mutating func formMap(transform: (Iterator.Element) throws -> Iterator.Element) rethrows {
        for index in indices {
            self[index] = try transform(self[index])
        }
    }
    
    mutating func formMap(transform: (inout Iterator.Element) throws) rethrows {
        for index in indices {
            try transform(self[index])
        }
    }
    
}

var arg = [1,2,3,4]

arg.formMap(transform: {
    $0 + 2
})

arg

arg.formMap(transform: {
    $0 += 1
})
*/

//let s: ContiguousArray<Int> = [1,3,4]

//s.withUnsafeMutableBufferPointer { ptr in
//    ptr.baseAddress
//}

/*
class Foo {
    let s: String = "aa"
    let f: Any = 1
    
    func foo() {
        Mirror(reflecting: self).children.filter {
            $0.label != "parent"
        }
    }
}

let g = Foo().foo()
*/


protocol AIRRegister {
    var air: String { get }
}
struct AnyRegister : AIRRegister {
    var air: String { return "" }
}

enum SelectionDAGOp {
    case entry // < entry token or root
    // %0 = add %1 %2
    case mul
    case call
    // a reference to a register
    case reg(AIRRegister)
    case int(Int)
    /// load src
    case load
    /// store dest src
    case store
    case ret
    
    var hasSideEffects: Bool {
        switch self {
        case .load, .store, .ret: return true
        default: return false
        }
    }
}
extension SelectionDAGOp : Equatable {
    static func == (l: SelectionDAGOp, r: SelectionDAGOp) -> Bool {
        switch (l, r) {
        case (.entry, .entry): return true
        case (.mul, .mul): return true
        case (.reg(let a), .reg(let b)): return a.air == b.air
        case (.int(let a), .int(let b)): return a == b
        case (.load, .load): return true
        case (.store, .store): return true
        case (.ret, .ret): return true
        case (.call, .call): return true
        default: return false
        }
    }
    static func nodesMatch (l: SelectionDAGOp, r: SelectionDAGOp) -> Bool {
        switch (l, r) {
        case (.entry, .entry): return true
        case (.mul, .mul): return true
        case (.reg, .reg): return true
        case (.int, .int): return true
        case (.load, .load): return true
        case (.store, .store): return true
        case (.ret, .ret): return true
        case (.call, .call): return true
        default: return false
        }
    }
}



private protocol OpPattern {
    static var matching: SelectionDAGOp { get }
}





enum X86Op {
    case mov
}

protocol OpOrder { }
private protocol MCInst {
    associatedtype Ins : OpOrder
    associatedtype Outs : OpOrder
}
private protocol Reg : OpPattern {
}
extension Reg {
}

private struct GPR : Reg {
    static var matching: SelectionDAGOp { return .reg(AnyRegister()) }
}

private struct Unary<R: Reg> : OpOrder {
}
private struct Binary<R1: Reg, R2: Reg> : OpOrder {
}
private struct Identity : OpOrder {}

private struct IADD64 : MCInst {
    typealias Ins = Binary<GPR, GPR>
    typealias Outs = Identity
}
private struct IADD64RR : MCInst {
    typealias Ins = Binary<GPR, GPR>
    typealias Outs = Unary<GPR>
}

private struct RET : MCInst {
    typealias Ins = Identity
    typealias Outs = Identity
}




private struct MulPattern<VAL1 : OpPattern, VAL2 : OpPattern> : OpPattern {
    static var matching: SelectionDAGOp { return .mul }
}
private struct StorePattern<DEST : Reg, VAL : OpPattern> : OpPattern {
    static var matching: SelectionDAGOp { return .store }
}

private typealias Match1 = StorePattern<GPR, MulPattern<GPR, GPR>>




print(1)

















