//
//  Metadata.cpp
//  Vist
//
//  Created by Josef Willsher on 10/5/2016.
//  Copyright © 2015 vistlang. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdlib.h>


extern "C"
ExistentialObject *
vist_constructExistential(ConceptConformance *conformance,
                          void *instance) {
    return new ExistentialObject(instance, 1, (ConceptConformance **)conformance);
}

extern "C"
void *
vist_getWitnessMethod(ExistentialObject *existential,
                      int32_t conformanceIndex,
                      int32_t methodIndex) {
    auto conf = existential->conformances[conformanceIndex];
    auto table = conformance->witnessTable;
    auto witness = table->witnesses[0];
    auto f = witness->witness;
    return *(void**)f;
}

/*
 @_gFooconfCpropWitnessOffsetArr0 = constant i32 0
 @_gFooconfCpropWitnessOffsetArr = constant [2 x i32*] 
    [
        i32* @_gFooconfCpropWitnessOffsetArr0, i32* @_gFooconfCpropWitnessOffsetArr0
    ]
 
 @_gFooconfCwitnessTablewitnessArr0 = constant { i8* } 
    { 
        i8* bitcast (
            void (%Foo*, %Int)* @foo_mFooI to i8*
        )
    }
 @_gFooconfCwitnessTablewitnessArr = constant [1 x { i8* }*] 
    [
        { i8* }* @_gFooconfCwitnessTablewitnessArr0
    ]
 @_gFooconfCwitnessTable = constant { { i8* }*, i32 } 
    { 
        { i8* }* bitcast (
            [1 x { i8* }*]* @_gFooconfCwitnessTablewitnessArr to { i8* }*
        ),
        i32 1 
    }
 @_gFooconfC = constant { i8*, i32*, i32, { { i8* }*, i32 }* } 
    { 
        i8* bitcast (
            { { i8*, i32*, i32, { { i8* }*, i32 }* }**, i32, i8* }* @_gFooconfCconcept to i8*
        ), 
        i32* bitcast (
            [2 x i32*]* @_gFooconfCpropWitnessOffsetArr to i32*
        ), 
        i32 2, 
        { { i8* }*, i32 }* @_gFooconfCwitnessTable 
    }
 */


//extern "C"
//int32_t
//vist_getPropertyOffset(ExistentialObject *existential,
//                      ) {
//    return offset...;
//}


#ifdef TESTING

int main() {
    return 0;
}

#endif



