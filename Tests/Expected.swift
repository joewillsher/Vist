//
//  Expected.swift
//  Vist
//
//  Created by Josef Willsher on 31/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSString


func expectedTestCaseOutput(path: String) -> String? {
    guard let contents = try? String(contentsOfFile: path) else { return nil }
    guard let toks = try? contents.getTokens() else { return nil }
    
    let comments = toks
        .flatMap { tok -> String? in if case .comment(let c) = tok.0 { return c } else { return nil } }
        .filter { comment in comment.hasPrefix(" test: ") }
        .flatMap { comment in comment
            .replacingOccurrences(of: " test: ", with: "")
            .replacingOccurrences(of: " ", with: "\n") }
    
    return comments.joined(separator: "\n") + "\n"
}

func getCommentsForFile(path: String) throws -> [String] {
    let contents = try String(contentsOfFile: path)
    let toks = try contents.getTokens()
    
    return toks.flatMap { tok in
        if case .comment(let c) = tok.0 { return c } else { return nil }
    }
}

//struct TestCommentCommandParser {
//    var configurationFlags: [String] = []
//    var output: String = "", vir: String = "", llvm: String = ""
//    
//    
//    enum CommandOutput {
//        case output
//        case vir
//        case llvm
//    }
//    
//    mutating func parseComment(comment: String) {
//        
//        let c = comment.componentsSeparatedByString(" ")
//        guard let f = c.first else { return }
//        let tokens = Array(c.dropFirst())
//        
//        switch f {
//        case "RUN:":
//            configurationFlags.appendContentsOf(tokens)
//        case "PRINT:":
//            output += "\n"
//            output += tokens.joined(separator: " ")
//            
//        default:
//            return
//        }
//    }
//    
//    func compareWithOutput() {
//        
//    }
//    
//}



