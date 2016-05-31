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
    // FIXME: Swift lowers this funny so we have to
    //        load the void* from where it thinks the
    //        witness is
    return *(void**)witness->witness;
}

extern "C"
int32_t
vist_getPropertyOffset(ExistentialObject *existential,
                       int32_t conformanceIndex,
                       int32_t propertyIndex) {
    // conf is @__gFooconfC
    ConceptConformance *conf = (ConceptConformance *)(existential->conformances) + conformanceIndex;
    
    // get offset table, (cast as ** and load, so we have orig pointer type
    // but we have loaded from it)
    auto offs = *(int32_t **)conf->propWitnessOffsets;
    return offs[propertyIndex];
}


#ifdef TESTING

int main() {
    return 0;
}

#endif



