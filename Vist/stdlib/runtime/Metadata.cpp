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
//WitnessTable *
//vist_getWitnessTable(TypeMetadata *metadata) {
//    return nullptr;
//};
//


//extern "C"
ConceptConformance vist_constructConceptConformance(TypeMetadata *concept,
                                                    int32_t *offsets,
                                                    int32_t numOffsets,
                                                    ValueWitness *witnesses,
                                                    int32_t numWitnesses) {
    return ConceptConformance(concept, offsets, numOffsets, witnesses, numWitnesses);
}

//extern "C"
TypeMetadata
vist_constructConceptMetadata(ConceptConformance **conformances,
                              int32_t numConformances,
                              char *name) {
    return TypeMetadata(conformances, numConformances, name);
}

/// Called by VIRLower to generate the metadata for a nominal type
extern "C"
TypeMetadata *
vist_constructNominalTypeMetadata(ConceptConformance **conformances,
                                  int32_t numConformances,
                                  char *name) {
    auto metadata = new TypeMetadata(conformances, numConformances, name);
    return metadata;
}


//extern "C"
//ExistentialObject *vist_constructExistential(int32_t *offsets,
//                                             int32_t numOffsets,
//                                             void *witnesses,
//                                             int32_t numWitnesses,
//                                             char *name,
//                                             void *instance) {
//    return nullptr;
//}


#ifdef TESTING

int main() {
    
    auto md = vist_constructNominalTypeMetadata(nullptr, 0, "Foo");
    
    return 0;
}


#endif



