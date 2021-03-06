
import class Foundation.NSString

extension String {
    
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
        ("/", "D"),
        ("~", "T"),
        ("^", "R"),
        ("%", "C"),
        (".", "D"),
        ("!", "B"),
        ]
    
    private func mappedChars() -> String {
        var resStr: [Character] = []
        
        for c in characters {
            if let replacement = String.mangleMap.index(where: {$0.0 == c}) {
                resStr.append("-")
                resStr.append(String.mangleMap[replacement].1)
            }
            else {
                resStr.append(c)
            }
        }
        return String(resStr)
    }
    
    /// returns the raw name, getting rid of type info at end,
    /// (and type prefix for methods)
    func demangleName() -> String {
        guard let ui = characters.index(of: "_") else { return self }
        let nameString = String(characters[startIndex..<ui])
        
        var resStr: [Character] = []
        var pred: Character? = nil
        
        for c in nameString.characters {
            if c != "-" {
                if let original = String.mangleMap.index(where: {$0.1 == c}) where pred == "-" {
                    resStr.append(String.mangleMap[original].0)
                } else {
                    resStr.append(c)
                }
            }
            
            pred = c
        }
        
        return String(resStr)
    }
    
    func demangleRuntimeName() -> String {
        return replacingOccurrences(of: "$", with: "-")
    }
    
}

"-D-D-L_tII".demangleName()

