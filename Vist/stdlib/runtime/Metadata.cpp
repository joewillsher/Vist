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
    
//    auto table = conformance->witnessTable;
//    printf("conf %p\n", conformance); // 0x100001110 == __gFooconfC == ConceptConformance
//    printf("table %p\n", table); // 0x1000010f8 == __gFooconfCwitnessTable == WitnessTable
//    auto witness = table->witnesses[0]; // 0x1000010f0 == __gFooconfCwitnessTablewitnessArr01 == ValueWitness
//    printf("witness %p\n", witness);
//    printf("witness function %p\n", *(void**)witness->witness); // 0x100000d80 _foo_mFooI == yay

    return new ExistentialObject(instance, 1, (ConceptConformance **)conformance);
}

extern "C"
void *
vist_getWitnessMethod(ExistentialObject *existential,
                      int32_t conformanceIndex,
                      int32_t methodIndex) {
    // conf is @__gFooconfC
    ConceptConformance *conf = (ConceptConformance *)(existential->conformances) + conformanceIndex;
    
    // table is  @_gFooconfCwitnessTablewitnessArr
    WitnessTable *table = conf->witnessTable;
    auto witness = table->witnesses[methodIndex];
    // FIXME: Swift lowers this funny so we have to
    //        load the void* from where it thinks the
    //        witness is
    return *(void**)witness->witness;
}


#ifdef TESTING

int main() {
    return 0;
}

#endif



