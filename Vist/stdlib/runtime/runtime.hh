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
    };
    
    /// A concept witness table
    struct WitnessTable {
        /// The witnesses
        ValueWitness ** SWIFT_NAME(witnessArr) witnesses;
        int32_t SWIFT_NAME(witnessArrCount) numWitnesses;
    };
    
    struct TypeMetadata {
        /// witness tables
        ConceptConformance ** SWIFT_NAME(conceptConformanceArr) conceptConformances;
        int32_t SWIFT_NAME(conceptConformanceArrCount) numConformances;
        const char *name;
    };
    
    /// The modeling of a concept -- the concept and witness table
    struct ConceptConformance {
        TypeMetadata *concept;   /// The concept we are conforming to
        int32_t * SWIFT_NAME(propWitnessOffsetArr) propWitnessOffsets;  /// Offset of concept elements
        int32_t SWIFT_NAME(propWitnessOffsetArrCount) numOffsets;       /// Number of offsets in `propWitnessOffsets`
        WitnessTable *witnessTable; /// Pointer to the conformant's witness table
    };
    
    struct ExistentialObject {
        void *object;
        int32_t SWIFT_NAME(conformanceArrCount) numConformances;
        ConceptConformance ** SWIFT_NAME(conformanceArr) conformances;
        
#ifdef __cplusplus
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
