//
//  runtime.h
//  Vist
//
//  Created by Josef Willsher on 16/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#ifndef runtime_h
#define runtime_h

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

///// A witness function
struct ValueWitness {
    void *witness;
    
#ifdef RUNTIME
public:
    ValueWitness(void *v) : witness(v) {}
#endif
};

/// A concept witness table
struct WitnessTable {
    /// The witnesses
    struct ValueWitness *witnesses;
    int32_t numWitnesses;
    
#ifdef RUNTIME
public:
    WitnessTable(ValueWitness *witnesses, int64_t numWitnesses) : witnesses(witnesses), numWitnesses(numWitnesses) {}
#endif
};

struct ConceptConformance;

struct TypeMetadata {
    /// witness tables
    struct ConceptConformance **conceptConformances;
    int32_t numConformances;
    char *name;
    
#ifdef RUNTIME
public:
    TypeMetadata(ConceptConformance **conformances, int32_t s, char *n)
    : conceptConformances(conformances), numConformances(s), name(n) {}
#endif
};

//class NominalTypeMetadata : public TypeMetadata {
//
//};

/// The modeling of a concept -- the concept and witness table
struct ConceptConformance {
    struct TypeMetadata *concept;   /// The concept we are conforming to
    int32_t *propWitnessOffsets;    /// Offset of concept elements
    int32_t numOffsets;             /// Number of offsets in `propWitnessOffsets`
    struct WitnessTable *witnessTable; /// Pointer to the conformant's witness table
                                       /// for this concept
    
#ifdef RUNTIME
public:
    ConceptConformance(TypeMetadata *md,
                       int32_t *offsets,
                       int32_t numOffs,
                       WitnessTable *witnessTable)
    : concept(md), propWitnessOffsets(offsets), numOffsets(numOffs), witnessTable(witnessTable) {}
#endif
};


struct ExistentialObject {
    void *object;
    int32_t numConformances;
    struct ConceptConformance *conformances;
    
#ifdef RUNTIME
public:
    ExistentialObject(void *object,
                      int32_t numConformances,
                      ConceptConformance *conformances)
    : object(object), numConformances(numConformances), conformances(conformances) {}
#endif
};


#ifdef __cplusplus
}
#endif






#endif /* runtime_h */
