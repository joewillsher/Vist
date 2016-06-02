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
    // conf is @__gFooconfC
    ConceptConformance *conf = (ConceptConformance *)(existential->conformances) + conformanceIndex;
    // FIXME: ^ doesn't work if I subscript it out -- can't use the load
    
    // table is  @_gFooconfCwitnessTablewitnessArr
    WitnessTable *table = conf->witnessTable;
    ValueWitness *witness = table->witnesses[methodIndex];
    return *(void**)witness->witness;
    
    /// EXAMPLE DATA SECTION:
//    @_gYconfXwitnessTablewitnessArr0 = constant { i8* } { i8* bitcast (void (%Y*)* @foo_mY to i8*) }
//    @_gYconfXwitnessTablewitnessArr03 = constant { i8* }* @_gYconfXwitnessTablewitnessArr0
//    @_gYconfXwitnessTablewitnessArr = constant [1 x { i8* }**] [{ i8* }** @_gYconfXwitnessTablewitnessArr03]
//    @_gYconfXwitnessTable = constant { { i8* }*, i32 } { { i8* }* bitcast ([1 x { i8* }**]* @_gYconfXwitnessTablewitnessArr to { i8* }*), i32 1 }
}

extern "C"
int32_t
vist_getPropertyOffset(ExistentialObject *existential,
                       int32_t conformanceIndex,
                       int32_t propertyIndex) {
    // conf is @__gFooconfC
    ConceptConformance *conf = (ConceptConformance *)(existential->conformances) + conformanceIndex;
    
    // the table, get as i32***
    auto offs = (int32_t ***)conf->propWitnessOffsets; // _gYconfXpropWitnessOffsetArr
    // move to the offset, then load twice
    auto i = offs[propertyIndex];                      // when i = 1, this is _gYconfXpropWitnessOffsetArr12
    return **i;                                        // load _gYconfXpropWitnessOffsetArr12 then from _gYconfXpropWitnessOffsetArr1
    
    /// EXAMPLE DATA SECTION:
//    @_gYconfXpropWitnessOffsetArr0 = constant i32 8
//    @_gYconfXpropWitnessOffsetArr01 = constant i32* @_gYconfXpropWitnessOffsetArr0
//    @_gYconfXpropWitnessOffsetArr1 = constant i32 0
//    @_gYconfXpropWitnessOffsetArr12 = constant i32* @_gYconfXpropWitnessOffsetArr1
//    @_gYconfXpropWitnessOffsetArr = constant [2 x i32**] [i32** @_gYconfXpropWitnessOffsetArr01, i32** @_gYconfXpropWitnessOffsetArr12]
}


#ifdef TESTING

int main() {
    return 0;
}

#endif



