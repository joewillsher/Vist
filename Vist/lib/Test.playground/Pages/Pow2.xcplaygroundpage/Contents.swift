

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

typealias IGNode = Int

struct IGMove : Hashable {
    let src: IGNode, dest: IGNode
    static func == (l: IGMove, r: IGMove) -> Bool {
        return l.hashValue == r.hashValue
    }
    var hashValue: Int {
        let ordered = [src.hashValue, dest.hashValue].sorted(by: <)
        let mask = sizeof(Int.self)*4
        return (ordered[0] << mask) + (ordered[1] & (Int.max >> mask))
    }
    func hasMember(_ node: IGNode) -> Bool {
        return src == node || dest == node
    }

}

let move = IGMove(src: 1, dest: 7)
move.hashValue
//let move2 = IGMove(src: 7, dest: 1)
//move2.hashValue

let s : Set = [move]

let m = IGMove.hasMember(move)
m.dynamicType
s.contains(where: m)
//s.contains(where: <#T##(IGMove) throws -> Bool#>)






