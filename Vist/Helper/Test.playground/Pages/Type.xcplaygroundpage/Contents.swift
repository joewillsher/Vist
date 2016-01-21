//: [Previous](@previous)

protocol Ty {
}


protocol Typed {
    typealias Type: Ty
    var type: Type? { get set }
}

protocol SomeType : Ty {
    func typeGet() -> Ty
}

extension SomeType where Self : Ty {
    func typeGet() -> Ty {
        return self
    }
}


struct StructType : Ty, SomeType {
}
enum BuiltinType : Ty, SomeType {
    case Null
}

final class AnyType {
    
    init<Type where Type : Ty>(_ s: Type) {
        type = s
    }
    
    /// Some type object is a `Ty` behind a `.getType()`
    var type: SomeType?
    
    /// Returns the Ty object inside the SomeType
    func getType() -> Ty? {
        return type?.getType()
    }
}


extension Typed where Type == AnyType {
    
    func getType() -> Ty? {
        return type?.getType()
    }
}


struct VarExpr : Typed {
    
    var type: AnyType? = nil
}

let s = StructType()
var u = VarExpr(type: nil)
u.type = AnyType(StructType())

u.getType()









//: [Next](@next)
