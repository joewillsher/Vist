extension DictionaryLiteralConvertible
    where
    Key == String,
    Self : SequenceType,
    Self.Generator.Element == (Key, Value)
{
    
    subscript(raw raw: String) -> Value? {
        get {
            for (k, v) in self {
                let kk = k.characters.dropFirst()
                let r = String(kk.prefixUpTo(kk.indexOf("_")!))
                
                if r == raw { return v }
            }
            return nil
        }
    }
    
}

let d = ["_foo_meme": 1]
import Foundation

let x = d[raw: "foo"]


extension String {
    
    func mangle() -> String {
        return "_\(sansUnderscores())_"
    }
    
    func sansUnderscores() -> String {
        return stringByReplacingOccurrencesOfString("LLVM.", withString: "LLVM")
            .stringByReplacingOccurrencesOfString("_", withString: "$")
    }
    
    // TODO: Add globalinit to mangled names for initalisers
    func demangleName() -> String {
        let kk = characters.dropFirst()
        return String(kk.prefixUpTo(kk.indexOf("_")!))
            .stringByReplacingOccurrencesOfString("LLVM", withString: "LLVM.")
//            .stringByReplacingOccurrencesOfString("$", withString: "_")
    }
    
}

let a = "_foo".mangle()
let b = "LLVM.i_add".mangle()


a.demangleName()
b.demangleName()



"_LLVM..add..i64..i64_i64i64".demangleName()
