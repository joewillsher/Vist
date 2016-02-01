//
//  Expected.swift
//  Vist
//
//  Created by Josef Willsher on 31/01/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import Foundation

func expectedTestCaseOutput(file file: String) -> String? {
    guard let contents = try? String(contentsOfFile: "\(testDir)/\(file)") else { return nil }
    guard let toks = try? contents.getTokens() else { return nil }
    
    let comments = toks
        .flatMap { tok -> String? in if case let .Comment(c) = tok.0 { return c } else { return nil } }
        .flatMap { comment -> String? in
            if comment.hasPrefix(" test: ") { return comment
                .stringByReplacingOccurrencesOfString(" test: ", withString: "")
                .stringByReplacingOccurrencesOfString(" ", withString: "\n")
            } else { return nil }
    }
    
    return comments.joinWithSeparator("\n") + "\n"
}
