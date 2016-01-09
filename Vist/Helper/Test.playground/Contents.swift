import Foundation

extension String {
    
    func mangle() -> String {
        return "_\(sansUnderscores())_"
    }
    
    func sansUnderscores() -> String {
        return stringByReplacingOccurrencesOfString("_", withString: "$")
    }
    
    // TODO: Add globalinit to mangled names for initalisers
    func demangleName() -> String {
        let kk = characters.dropFirst()
        return String(kk.prefixUpTo(kk.indexOf("_")!))
            .stringByReplacingOccurrencesOfString("$", withString: "_")
    }
    
}

extension DictionaryLiteralConvertible
    where
    Key == String,
    Self : SequenceType,
    Self.Generator.Element == (Key, Value)
{
    
    /// Subscript for unmangled names
    ///
    /// Function name is required to be between underscores at the start _foo_...
    subscript(raw raw: String) -> Value? {
        get {
            
            for (k, v) in self {
                
                if k.demangleName() == raw { return v }
            }
            return nil
        }
    }
    
    
}


let d = ["_$fatalError_": 5]

let x = d[raw: "_fatalError"]





