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

#ifdef TESTING

int main() {
    return 0;
}

#endif



