
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



let c = { $0 } as (Int) -> Any

let erased = c as Any

if let opened = erased as? (Any) -> Any {
    print(opened(1))
}

_ = ((Int) -> Any).self

