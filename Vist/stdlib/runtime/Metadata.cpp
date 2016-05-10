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
#include <vector>
#include <map>



///// A witness function
class ValueWitness {
    void *witness;
public:
    ValueWitness(void *v) : witness(v) {}
};

/// A concept witness table
class WitnessTable {
    /// The witnesses
    std::vector<ValueWitness> witnesses;
public:
    WitnessTable(ValueWitness *witnesses, int64_t numWitnesses) : witnesses(witnesses, witnesses + numWitnesses) {}
};

class ConceptConformance;

class TypeMetadata {
    /// witness tables
    std::vector<ConceptConformance *> conceptConformances;
    char *name;
//    std::vector<TypeMetadata *> members;
    
public:
    TypeMetadata(std::vector<ConceptConformance *> conformances, char *n)
    : conceptConformances(conformances), name(n) {}
};

//class NominalTypeMetadata : public TypeMetadata {
//
//};

/// The modeling of a concept -- the concept and witness table
class ConceptConformance {
    TypeMetadata *concept; /// the concept we are conforming to
    std::vector<int32_t> propWitnessOffsets;
    WitnessTable witnessTable;
    
public:
    ConceptConformance(TypeMetadata *md,
                       int32_t *offsets,
                       int32_t numOffsets,
                       ValueWitness *witnesses,
                       int64_t numWitnesses)
    : concept(md), propWitnessOffsets(offsets, offsets+numOffsets), witnessTable(witnesses, numWitnesses) {}
};


class ExistentialObject {
    void *object;
    int32_t numConformances;
    ConceptConformance *conformances;
};


//extern "C"
//WitnessTable *
//vist_getWitnessTable(TypeMetadata *metadata) {
//    return nullptr;
//};
//

template <class ValueTy>
class MetadataCache {
    std::map<char *, ValueTy *> map;
};



extern "C"
ConceptConformance vist_constructConceptConformance(TypeMetadata *concept,
                                                    int32_t *offsets,
                                                    int32_t numOffsets,
                                                    ValueWitness *witnesses,
                                                    int32_t numWitnesses) {
    return ConceptConformance(concept, offsets, numOffsets, witnesses, numWitnesses);
}

extern "C"
ExistentialObject *vist_constructExistential(int32_t *offsets,
                                             int32_t numOffsets,
                                             void *witnesses,
                                             int32_t numWitnesses,
                                             char *name,
                                             void *instance) {
    return nullptr;
}


#ifdef TESTING

void print() {
    printf("memmes");
}

int main() {
        
    std::vector<ConceptConformance *> empty;
    auto type = TypeMetadata(empty, "Foo");
    int32_t offsets = 0;
    ValueWitness valueWitness = ValueWitness((void*)(print));
    auto conformance = vist_constructConceptConformance(&type, &offsets, 1, &valueWitness, 1);
    
    
    
    return 0;
}


#endif



