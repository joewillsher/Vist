//: [Previous](@previous)

protocol Collection {
    associatedtype T
    func next() -> T
}

struct CollectionExample<C: Collection> {
    var collection: C
}




//: [Next](@next)
