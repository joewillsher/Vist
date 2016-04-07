
import Foundation.NSString

let a = "🔥 test 🔥"


extension String {
    
    enum Encoding { case utf8, utf16 }
    
    var encoding: Encoding {
        switch smallestEncoding {
        case NSUTF16StringEncoding: return .utf16
        default: return .utf8
        }
    }
    var numberOfCodeUnits: Int {
        switch encoding {
        case .utf8: return utf8.count
        case .utf16: return utf16.count
        }
    }
    
}

a.encoding
a.numberOfCodeUnits + 1


var u = a.utf16.count
a.nulTerminatedUTF8.withUnsafeBufferPointer { buffer in
    
    let s = NSString(CString: UnsafePointer<Int8>(buffer.baseAddress), encoding: NSUTF16StringEncoding)
    print(s)
}

print("\n")

a.utf8.count
for c in a.utf8 {
    c
}

