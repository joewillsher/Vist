//
//  runtime.hh
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

// Define arr



#ifdef __cplusplus
#define SWIFT_NAME(X)
extern "C" {
#else
    
#define SWIFT_NAME(X) __attribute__((swift_name(#X)))
    // Types are exposed to swift with this name
    //  - Types ending in 'Arr' will be lowered as an array, with
    //    the member _ 'ArrCount' being used as the static size
    
#endif
    
    typedef struct ValueWitness ValueWitness;
    typedef struct ConceptConformance ConceptConformance;
    typedef struct TypeMetadata TypeMetadata;
    typedef struct ExistentialObject ExistentialObject;
    typedef struct WitnessTable WitnessTable;
    
    /// A witness function
    struct ValueWitness {
        void *witness;
        
#ifdef RUNTIME
    public:
        ValueWitness(void *v)
            : witness(v) {}
#endif
    };
    
    
    
    /// A concept witness table
    struct WitnessTable {
        /// The witnesses
        
        ValueWitness * SWIFT_NAME(witnessArr) witnesses;
        int32_t SWIFT_NAME(witnessArrCount) numWitnesses;
        
#ifdef RUNTIME
    public:
        WitnessTable(ValueWitness *witnesses, int64_t numWitnesses)
            : witnesses(witnesses), numWitnesses(numWitnesses) {}
#endif
    };
    
    
    
    struct TypeMetadata {
        /// witness tables
        ConceptConformance ** SWIFT_NAME(conceptConformanceArr) conceptConformances;
        int32_t SWIFT_NAME(conceptConformanceArrCount) numConformances;
        const char *name;
        
#ifdef RUNTIME
    public:
        TypeMetadata(ConceptConformance **conformances, int32_t s, const char *n)
            : conceptConformances(conformances), numConformances(s), name(n) {}
#endif
    };
    
    
    
    
    /// The modeling of a concept -- the concept and witness table
    struct ConceptConformance {
        TypeMetadata *concept;   /// The concept we are conforming to
        int32_t * SWIFT_NAME(propWitnessOffsetArr) propWitnessOffsets;  /// Offset of concept elements
        int32_t SWIFT_NAME(propWitnessOffsetArrCount) numOffsets;       /// Number of offsets in `propWitnessOffsets`
        WitnessTable *witnessTable; /// Pointer to the conformant's witness table
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
        int32_t SWIFT_NAME(conformanceArrCount) numConformances;
        ConceptConformance ** SWIFT_NAME(conformanceArr) conformances;
        
#ifdef RUNTIME
    public:
        ExistentialObject(void *object,
                          int32_t numConformances,
                          ConceptConformance **conformances)
            : object(object), numConformances(numConformances), conformances(conformances) {}
#endif
    };
    
    
#ifdef __cplusplus
}
#endif






#endif /* runtime_h */
