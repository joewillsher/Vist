//: [Previous](@previous)


enum DefinedType {
    case Void
    case Type(String)
    indirect case Tuple([DefinedType])
    
    init(_ str: String) {
        self = .Type(str)
    }
    
    init(_ strs: [String]) {
        switch strs.count {
        case 0: self = .Void
        case 1: self = .Type(strs[0])
        case _: self = .Tuple(strs.map(DefinedType.init))
        }
}




//: [Next](@next)
