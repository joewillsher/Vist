//
//  ViewController.swift
//  Editor
//
//  Created by Josef Willsher on 09/03/2016.
//  Copyright © 2016 vist. All rights reserved.
//

import Cocoa

private enum Lang { case vist, vhir }

class ViewController: NSViewController {

    var textView: NSTextView!
    private let language: Lang = .vist
    
    private let keywordColor = NSColor(calibratedRed: 128/256, green: 24/256, blue: 137/256, alpha: 1)
    private let numberColor = NSColor(calibratedRed: 154/256, green: 140/256, blue: 256/256, alpha: 1)
    private let commentColor = NSColor(calibratedRed: 65/256, green: 229/256, blue: 55/256, alpha: 0.63)
    
    private let instructionColor = NSColor(calibratedRed: 154/256, green: 60/256, blue: 255/256, alpha: 1)
    private let functionColor = NSColor(calibratedRed: 32/256, green: 149/256, blue: 255/256, alpha: 1)
    private let blockColor = NSColor(calibratedRed: 227/256, green: 142/256, blue: 81/256, alpha: 1)
    private let typeColor = NSColor(calibratedRed: 22/256, green: 185/256, blue: 227/256, alpha: 1)
    
    override func viewDidLoad() {
        textView = NSTextView(frame: view.frame)
        view.addSubview(textView)
        
        textView.textColor = .whiteColor()
        textView.backgroundColor = NSColor(calibratedRed: 30/256, green: 32/256, blue: 40/256, alpha: 1)
        textView.font = NSFont(name: "Menlo", size: 12)
        textView.delegate = self
        super.viewDidLoad()
    }
    
    func colourKeywords() {
        guard let string = textView.string else { return }
        
        do {
            var unsearchedRange = string.startIndex..<string.endIndex
            
            for line in string.componentsSeparatedByCharactersInSet(.newlineCharacterSet()) {
                let unsearchedString = string[unsearchedRange]
                guard let lineRange = unsearchedString.rangeOfString(line) else { continue }
                
                let offset = string.startIndex.distanceTo(unsearchedRange.startIndex)
                unsearchedRange.startIndex = unsearchedRange.startIndex.advancedBy(unsearchedString.startIndex.distanceTo(lineRange.endIndex))
                
                let lineNSRange = NSRange(location: offset + unsearchedString.startIndex.distanceTo(lineRange.startIndex), length: lineRange.startIndex.distanceTo(lineRange.endIndex))
                if case .vhir = language where line.hasPrefix("$") {
                    textView.setTextColor(blockColor, range: lineNSRange)
                }
                else {
                    textView.setTextColor(.whiteColor(), range: lineNSRange)
                }
                
                guard let _ = line.rangeOfString("//") else { continue }
                let commentRange = unsearchedString.rangeOfString("//")!
                let commentNSRange = NSRange(location: offset + unsearchedString.startIndex.distanceTo(commentRange.startIndex), length: commentRange.startIndex.distanceTo(lineRange.endIndex))
                textView.setTextColor(commentColor, range: commentNSRange)
            }
        }
        
        do {
            var unsearchedRange = string.startIndex..<string.endIndex
            let set = NSMutableCharacterSet.whitespaceAndNewlineCharacterSet()
            set.addCharactersInString("():,")
            
            for word in string.componentsSeparatedByCharactersInSet(set) {
                let unsearchedString = string[unsearchedRange]
                guard let wordRange = unsearchedString.rangeOfString(word) else { continue }
                
                let offset = string.startIndex.distanceTo(unsearchedRange.startIndex)
                unsearchedRange.startIndex = unsearchedRange.startIndex.advancedBy(unsearchedString.startIndex.distanceTo(wordRange.endIndex))
                
                let nsRange = NSRange(location: offset + unsearchedString.startIndex.distanceTo(wordRange.startIndex), length: wordRange.count)
                if let c = colourForWord(word) { textView.setTextColor(c, range: nsRange) }
            }
        }
        
    }
    
    private let vistKeywords = ["let", "var", "func", "do", "return", "for", "in", "type", "concept", "@mutating", "if", "else"]
    private let vhirKeywords = ["struct", "struct_extract", "variable_decl", "builtin", "return", "call", "tuple", "tuple_extract", "int_literal", "bool_literal", "break", "i_add", "i_sub", "i_mul", "condfail", "func", "type"]
    private let types = ["Int", "Bool", "Double", "Int32", "Float", "Range", "Builtin.Int32", "Builtin.Int64", "Builtin.Void", "Builtin.Double"]
    
    private func colourForWord(str: String) -> NSColor? {
        
        if let _ = Int(str) { return numberColor }
        
        switch language {
        case .vist where vistKeywords.contains(str): return keywordColor
        case .vhir where vhirKeywords.contains(str): return keywordColor
        case .vhir where str.hasPrefix("@"): return functionColor
        case .vist where types.contains(str): return typeColor
        case .vhir where types.contains({str.hasSuffix($0)}): return typeColor
        case .vhir where str.hasPrefix("%"): return .whiteColor()
        default: return nil
        }
    }
    
}




extension ViewController: NSTextViewDelegate {
    
    func textDidChange(notification: NSNotification) {
        
        colourKeywords()
    }
    
    func textView(textView: NSTextView, completions words: [String], forPartialWordRange charRange: NSRange, indexOfSelectedItem index: UnsafeMutablePointer<Int>) -> [String] {
        switch language {
        case .vist: return vistKeywords
        case .vhir: return vhirKeywords
        }
    }
    
}

extension String {
    
    func asNSRange(range: Range<String.CharacterView.Index>) -> NSRange {
        return NSRange(location: characters.startIndex.distanceTo(range.startIndex), length: range.count)
    }
}

