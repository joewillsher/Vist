import Foundation

extension String {
    
    func mangle() -> String {
        return "\(mappedChars())_"
    }
    
    private static var mangleMap: [(Character, Character)] = [
        ("_", "U"),
        ("-", "M"),
        ("+", "P"),
        ("|", "O"),
        ("&", "N"),
        ("$", "V"),
        ("*", "A"),
        ("<", "L"),
        (">", "G"),
        ("=", "E"),
        ("/", "D")
    ]
    
    func mappedChars() -> String {
        var resStr: [Character] = []
        
        for c in characters {
            if let replacement = String.mangleMap.indexOf({$0.0 == c}) {
                resStr.append("-")
                resStr.append(String.mangleMap[replacement].1)
            }
            else {
                resStr.append(c)
            }
        }
        return String(resStr)
    }
    
    func demangleName() -> String {
        let end = characters.indexOf("_")! // index of end of name
        
        let d = characters.indexOf(".") // index of initial name dot
        let start: CharacterView.Index
        
        if let d = d {
            if String(characters[startIndex..<d]) == "LLVM" {
                start = startIndex
            }
            else {
                start = d.successor()
            }
        }
        else {
            start = startIndex
        }
        
        let name = String(characters[start..<end])
        
        var resStr: [Character] = []
        var pred: Character? = nil
        
        for c in name.characters {
            if c != "-" {
                if let original = String.mangleMap.indexOf({$0.1 == c}) where pred == "-" {
                    resStr.append(String.mangleMap[original].0)
                } else {
                    resStr.append(c)
                }
            }
            
            pred = c
        }
        
        return String(resStr)
    }
}

//extension DictionaryLiteralConvertible
//    where
//    Key == String,
//    Self: SequenceType,
//    Self.Generator.Element == (Key, Value)
//{
//    
//    /// Subscript for unmangled names
//    ///
//    /// Function name is required to be between underscores at the start _foo_...
//    subscript(raw raw: String) -> Value? {
//        get {
//            
//            for (k, v) in self {
//                
//                if k.demangleName() == raw { return v }
//            }
//            return nil
//        }
//    }
//    
//    
//}


let d = ["_$fatalError_": 5]

let m = "_fatalError".mangle()
let n = "+".mangle()
let a = "Eq.sum_Int"
let l = "LLVM.foo_Int"

m.demangleName()
n.demangleName()
a.demangleName()
l.demangleName()
