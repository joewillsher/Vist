//
//  Expected.swift
//  Vist
//
//  Created by Josef Willsher on 31/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation

func expectedTestCaseOutput(path path: String) -> String? {
    guard let contents = try? String(contentsOfFile: path) else { return nil }
    guard let toks = try? contents.getTokens() else { return nil }
    
    let comments = toks
        .flatMap { tok -> String? in if case let .Comment(c) = tok.0 { return c } else { return nil } }
        .filter { comment in comment.hasPrefix(" test: ") }
        .flatMap { comment in comment.stringByReplacingOccurrencesOfString(" test: ", withString: "").stringByReplacingOccurrencesOfString(" ", withString: "\n") }
    
    return comments.joinWithSeparator("\n") + "\n"
}
