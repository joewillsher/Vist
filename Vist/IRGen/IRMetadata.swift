//
//  IRMetadata.swift
//  Vist
//
//  Created by Josef Willsher on 18/02/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//


protocol RuntimeMetadata {
    
}


final class ExistentialConceptMetadata: RuntimeMetadata {
    var arr = MetadataArray()
    var ptr = OpaquePointer()
}


final class MetadataArray: RuntimeMetadata {
    
    
    
}

final class OpaquePointer: RuntimeMetadata {
    
    
    
}

