

let chars = [
    109,
    101,
    109,
    101,
    92,
    110,
]

extension String {
    
    private init(escaping: String) {
        
        var chars: [Character] = []
        let count = escaping.characters.count
        chars.reserveCapacity(count)
        
        // '\' character
        let escapeChar = Character("\\")
        
        var escape = false

        for (i, c) in escaping.characters.enumerate() {
            
            if escape {
                defer { escape = false }
                switch c {
                case "\\": chars.append("\\")
                case "n": chars.append("\n")
                case "t": chars.append("\t")
                case "r": chars.append("\r")
                default: break
                }
            }
            else if c == escapeChar {
                escape = true
            }
            else {
                chars.append(c)
            }
        }
        
        self = String(chars)
    }
    
}

//let a = "meme"
//let a_ = String(escaping: a)
//let b = "meme😗"
//let b_ = String(escaping: b)
//let c = "meme\\n"
//let c_ = String(escaping: c)



//
//for scalar in s.utf8 {
//    print(scalar)
//}


