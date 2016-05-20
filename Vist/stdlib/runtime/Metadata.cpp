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


//extern "C"
ConceptConformance vist_constructConceptConformance(TypeMetadata *concept,
                                                    int32_t *offsets,
                                                    int32_t numOffsets,
                                                    WitnessTable *witnessTable) {
    return ConceptConformance(concept, offsets, numOffsets, witnessTable);
}

//extern "C"
TypeMetadata
vist_constructConceptMetadata(ConceptConformance **conformances,
                              int32_t numConformances,
                              char *name) {
    return TypeMetadata(conformances, numConformances, name);
}

extern "C"
ExistentialObject *
vist_constructExistential(ConceptConformance *conformance,
                          void *instance,
                          WitnessTable *witness) {
    return new ExistentialObject(instance, 1, conformance);
}


#ifdef TESTING

int main() {
    
    auto md = vist_constructNominalTypeMetadata(nullptr, 0, "Foo");
    
    return 0;
}

#endif



