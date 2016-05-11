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
struct ValueWitness {
    void *witness;
public:
    ValueWitness(void *v) : witness(v) {}
};

/// A concept witness table
struct WitnessTable {
    /// The witnesses
    ValueWitness *witnesses;
    int32_t numWitnesses;
public:
    WitnessTable(ValueWitness *witnesses, int64_t numWitnesses) : witnesses(witnesses), numWitnesses(numWitnesses) {}
};

struct ConceptConformance;

class TypeMetadata {
    /// witness tables
    ConceptConformance **conceptConformances;
    int32_t numConformances;
    char *name;
//    std::vector<TypeMetadata *> members;
    
public:
    TypeMetadata(ConceptConformance **conformances, int32_t s, char *n)
        : conceptConformances(conformances), numConformances(s), name(n) {}
};

//
//template<int32_t NumConformances>
//class TypeMetadata__ {
//    /// witness tables
//    ConceptConformance *conceptConformances;
//    char *name;
//
//public:
//    TypeMetadata__(ConceptConformance *conformances, char *n)
//        : conceptConformances(conformances), name(n) {}
//};


//class NominalTypeMetadata : public TypeMetadata {
//
//};

/// The modeling of a concept -- the concept and witness table
struct ConceptConformance {
    TypeMetadata *concept; /// the concept we are conforming to
    int32_t *propWitnessOffsets;
    int32_t numOffsets;
    WitnessTable witnessTable;
    
public:
    ConceptConformance(TypeMetadata *md,
                       int32_t *offsets,
                       int32_t numOffs,
                       ValueWitness *witnesses,
                       int64_t numWitnesses)
    : concept(md), propWitnessOffsets(offsets), numOffsets(numOffs), witnessTable(witnesses, numWitnesses) {}
};


struct ExistentialObject {
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
    
public:
    void insert(ValueTy *value, char *key) {
        map.insert(std::pair<char *, ValueTy *>(key, value));
        printf("insert %p for %s\n", value, key);
    }
};

static MetadataCache<TypeMetadata> cache;


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
    // cache it
    cache.insert(metadata, name);
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



