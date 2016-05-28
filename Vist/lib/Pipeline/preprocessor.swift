//
//  preprocessor.swift
//  Vist
//
//  Created by Igor Timofeev on 28/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

import class Foundation.NSTask

func runPreprocessor(inout file: String, cwd: String) {
    
    let preprocessor = "\(SOURCE_ROOT)/Vist/lib/Pipeline/Preprocessor.sh"
    
    NSTask.execute(execName: preprocessor, files: [file], cwd: cwd, args: [])
    
    file = "\(file).previst"
}