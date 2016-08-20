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
        void *_Nonnull witness;
    };
    
    /// A concept witness table
    struct WitnessTable {
        /// The witnesses
        ValueWitness *_Nullable *_Nonnull SWIFT_NAME(witnessArr) witnesses;
        int32_t SWIFT_NAME(witnessArrCount) numWitnesses;
        
#ifdef __cplusplus
        /// Returns the witness at `index` from the static metadata
        void *_Nullable getWitness(int32_t index);
#endif
    };
    
    struct TypeMetadata {
        /// witness tables
        ConceptConformance *_Nullable *_Nonnull  SWIFT_NAME(conceptConformanceArr) conceptConformances;
        int32_t SWIFT_NAME(conceptConformanceArrCount) numConformances;
        
        int32_t size;
        const char *_Nonnull name;
    };
    
    /// The modeling of a concept -- the concept and witness table
    struct ConceptConformance {
        /// The concept we are conforming to
        TypeMetadata *_Nonnull concept;
        
        int32_t *_Nullable *_Nonnull SWIFT_NAME(propWitnessOffsetArr) propWitnessOffsets;  /// Offset of concept elements
        int32_t SWIFT_NAME(propWitnessOffsetArrCount) numOffsets;       /// Number of offsets in `propWitnessOffsets`
        
        /// Pointer to the conformant's witness table
        WitnessTable *_Nonnull witnessTable;
        
#ifdef __cplusplus
        /// Returns the offset at `index` from the static metadata
        int32_t getOffset(int32_t index);
#endif
    };
    
    struct ExistentialObject {
        /// The instance
        
#ifdef __cplusplus
    protected:
#endif
        /// a tagged pointer containing the instance, and in the least
        /// significant bit, a flag stating whether the ptr is stored
        /// on the heap and needs deallocating
        uintptr_t instanceTaggedPtr;
#ifdef __cplusplus
    public:
#endif
        int32_t SWIFT_NAME(conformanceArrCount) numConformances;
        ConceptConformance *_Nullable *_Nonnull SWIFT_NAME(conformanceArr) conformances;
        TypeMetadata *_Nonnull metadata;
        
#ifdef __cplusplus
        /// Returns the concept at `index` from the existential's metadata
        ConceptConformance *_Nonnull getConformance(int32_t index);
        
        ExistentialObject(uintptr_t object,
                          TypeMetadata *_Nonnull metadata,
                          int32_t numConformances,
                          ConceptConformance *_Nonnull *_Nullable conformances)
            : instanceTaggedPtr(object), metadata(metadata), numConformances(numConformances), conformances(conformances) {}
        
        __attribute__((always_inline))
        uintptr_t projectBuffer() {
            return (uintptr_t)instanceTaggedPtr & ~0x1;
        }
        __attribute__((always_inline))
        bool isNonLocal() {
            return (uintptr_t)instanceTaggedPtr & 0x1;
        }
#endif
    };
    
    
#ifdef __cplusplus
}
#endif



#endif /* runtime_h */
