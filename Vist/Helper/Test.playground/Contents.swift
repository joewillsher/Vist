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


let x = d[raw: "foo"]
