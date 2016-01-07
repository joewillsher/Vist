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
    
    
    func sansUnderscores() -> String {
        return stringByReplacingOccurrencesOfString("_", withString: ".")
    }
    
    // TODO: Allow underscores in names
    // TODO: Add globalinit to mangled names for initalisers
    func demangleName() -> String {
        let kk = characters.dropFirst()
        return String(kk.prefixUpTo(kk.indexOf("_")!))
    }
    
}


"_LLVM.add.i64.i64_i64i64".demangleName()

for var i = 0; i < 100; i++ { // c style
    i
}

for i in 0..<100 {
    i
}


let range = 0..<100

var _g = range.generate()

while let i = _g.next() {
    i
}







