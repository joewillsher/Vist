//
//  Analysis.swift
//  Vist
//
//  Created by Josef Willsher on 14/08/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

protocol FunctionAnalysis {
    associatedtype Base : VIRElement
    
    static func get(_: Base) -> Self
}


struct Analysis<AnalysisType : FunctionAnalysis> {
    
    private var _analysis: AnalysisType?
    private let base: AnalysisType.Base
    
    init(_ base: AnalysisType.Base) {
        self.base = base
    }
    
    var analsis: AnalysisType {
        mutating get {
            if let computed = _analysis {
                return computed
            }
            
            let a = AnalysisType.get(base)
            _analysis = a
            return a
        }
    }
    
    mutating func invalidate() {
        _analysis = nil
    }
    
}

