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
        guard let string = textView.string, let range = textView.string?.rangeOfString(string) else { return }
        
        string.enumerateSubstringsInRange(range, options: NSStringEnumerationOptions.ByWords) {
            (substring, substringRange, enclosingRange, _) in
            guard let sub = substring where !substringRange.isEmpty else { return }
            self.textView.setTextColor(self.colourForWord(sub), range: string.asNSRange(substringRange))
        }

        string.enumerateSubstringsInRange(range, options: NSStringEnumerationOptions.ByLines) {
            (substring, substringRange, enclosingRange, _) in
            guard let sub = substring where !substringRange.isEmpty else { return }
            guard let commentDeclRange = sub.rangeOfString("//") else { return }
            
            let green = string.asNSRange(commentDeclRange.startIndex.advancedBy(string.startIndex.distanceTo(sub.startIndex))..<substringRange.endIndex)
            self.textView.setTextColor(self.commentColor, range: green)
        }
        
    }
    
    private let vistKeywords = ["let", "var", "func", "do", "return", "for", "in", "type", "concept", "mutating"]
    private let vhirKeywords = ["struct", "struct_extract", "variable_decl", "builtin", "return", "call", "tuple", "tuple_extract", "int_literal", "bool_literal", "break"]
    
    private func colourForWord(str: String) -> NSColor {
        
        if let _ = Int(str) { return numberColor }
        
        switch language {
        case .vist where vistKeywords.contains(str): return keywordColor
        case .vhir where vhirKeywords.contains(str): return keywordColor
        default: return .whiteColor()
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

