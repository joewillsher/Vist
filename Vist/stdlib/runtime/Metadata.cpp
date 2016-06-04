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


ConceptConformance *ExistentialObject::getConformance(int32_t index) {
    return (ConceptConformance *)(conformances) + index;
}

void *WitnessTable::getWitness(int32_t index) {
    auto witness = witnesses[index];
    return *(void**)witness->witness;
}

int32_t ConceptConformance::getOffset(int32_t index) {
    // the table, get as i32***
    auto offs = (int32_t ***)propWitnessOffsets; // _gYconfXpropWitnessOffsetArr
    // move to the offset, then load twice
    auto i = offs[index];                        // when i = 1, this is _gYconfXpropWitnessOffsetArr12
    auto w = **i;                                  // load _gYconfXpropWitnessOffsetArr12 then from _gYconfXpropWitnessOffsetArr1
    printf("old = %p %i\n", i, w);
    return w;
}

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
    
    return existential->getConformance(conformanceIndex)->witnessTable->getWitness(methodIndex);
}
/// EXAMPLE DATA SECTION FOR WITNESS LOOKUP:
//    @_gYconfXwitnessTablewitnessArr0 = constant { i8* } { i8* bitcast (void (%Y*)* @foo_mY to i8*) }
//    @_gYconfXwitnessTablewitnessArr03 = constant { i8* }* @_gYconfXwitnessTablewitnessArr0
//    @_gYconfXwitnessTablewitnessArr = constant [1 x { i8* }**] [{ i8* }** @_gYconfXwitnessTablewitnessArr03]
//    @_gYconfXwitnessTable = constant { { i8* }*, i32 } { { i8* }* bitcast ([1 x { i8* }**]* @_gYconfXwitnessTablewitnessArr to { i8* }*), i32 1 }

extern "C"
int32_t
vist_getPropertyOffset(ExistentialObject *existential,
                       int32_t conformanceIndex,
                       int32_t propertyIndex) {
    // conf is @__gFooconfC
    auto conf = existential->getConformance(conformanceIndex);
    
    // the table, get as i32***
    auto offs = (int32_t ***)conf->propWitnessOffsets; // _gYconfXpropWitnessOffsetArr
    // move to the offset, then load twice
    auto i = offs[propertyIndex];                      // when i = 1, this is _gYconfXpropWitnessOffsetArr12
    auto w = **i;                                        // load _gYconfXpropWitnessOffsetArr12 then from _gYconfXpropWitnessOffsetArr1
    
    auto x = conf->getOffset(propertyIndex);
    
    printf("old = %p %i\n", i, w);
    
    return w;
    
/// EXAMPLE DATA SECTION FOR OFFSET LOOKUP:
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



