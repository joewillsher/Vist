

private extension Int {
//    var isPowerOf2: Bool {
//        guard self != 0 else { return false }
//        var c = 0
//        while self & (1<<c) == 0 { c += 1 }
//        return self >> (c+1) == 0
//    }
    var isPowerOf2: Bool {
        guard self >= 0 else { return false }
        var v = self
        while v & 1 == 0 { v >>= 1 }
        return v == 0
    }
}

let a = 5
a.isPowerOf2

//for i in 0..<100000 where i.isPowerOf2 {
//    print(i)
//}


