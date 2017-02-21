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


// These functions must have a stub decl with the @runtime attr in the stdlib
#define RUNTIME_STDLIB_INTERFACE extern "C"

// These functions must have a definition in Vist/lib/Sema/Runtime.swift to
// be exposed to the compiler
#define RUNTIME_COMPILER_INTERFACE extern "C"

#define INLINE __attribute__((always_inline))


//typedef struct GenericParamList GenericParamList;
typedef struct TypeMetadata TypeMetadata;
typedef struct ExistentialObject ExistentialObject;
typedef struct WitnessTable WitnessTable;
typedef struct RefcountedObject RefcountedObject;

// Existential
RUNTIME_COMPILER_INTERFACE
void vist_constructExistential(WitnessTable *_Nonnull *_Nonnull conformances, int numConformances,
                               void *_Nonnull, TypeMetadata *_Nonnull,
                               bool, ExistentialObject *_Nullable);
RUNTIME_COMPILER_INTERFACE
void vist_deallocExistentialBuffer(ExistentialObject *_Nonnull);

RUNTIME_COMPILER_INTERFACE
void *_Nonnull
vist_getWitnessMethod(ExistentialObject *_Nonnull,
                      int32_t, int32_t);

RUNTIME_COMPILER_INTERFACE
void *_Nonnull
vist_getPropertyProjection(ExistentialObject *_Nonnull,
                           int32_t, int32_t);

RUNTIME_COMPILER_INTERFACE
void *_Nonnull
vist_getExistentialBufferProjection(ExistentialObject *_Nonnull);

RUNTIME_COMPILER_INTERFACE
void vist_exportExistentialBuffer(ExistentialObject *_Nonnull);

RUNTIME_COMPILER_INTERFACE
void vist_copyExistentialBuffer(ExistentialObject *_Nonnull,
                                ExistentialObject *_Nullable);

// Casting
RUNTIME_COMPILER_INTERFACE
bool vist_castExistentialToConcrete(ExistentialObject *_Nonnull,
                                    TypeMetadata *_Nonnull,
                                    void *_Nullable);

RUNTIME_COMPILER_INTERFACE
bool vist_castExistentialToConcept(ExistentialObject *_Nonnull,
                                   TypeMetadata *_Nonnull,
                                   ExistentialObject *_Nullable);

// introspection
RUNTIME_STDLIB_INTERFACE
void *_Nonnull vist_runtime_getMetadata(ExistentialObject *_Nonnull);

RUNTIME_STDLIB_INTERFACE
int64_t vist_runtime_metadataGetSize(void *_Nonnull);

RUNTIME_STDLIB_INTERFACE
void *_Nonnull vist_runtime_metadataGetName(void *_Nonnull);

// ref counting
RUNTIME_COMPILER_INTERFACE
RefcountedObject *_Nonnull
vist_allocObject(TypeMetadata *_Nonnull metadata);

RUNTIME_COMPILER_INTERFACE
void vist_deallocObject(RefcountedObject *_Nonnull object);

RUNTIME_COMPILER_INTERFACE
void vist_releaseObject(RefcountedObject *_Nonnull object);

RUNTIME_COMPILER_INTERFACE
void vist_retainObject(RefcountedObject *_Nonnull object);


struct RefcountedObject {
    void *_Nonnull object;
    uint32_t refCount;
    TypeMetadata *_Nonnull metadata;
};

struct TypeMetadata {
    /// witness tables
    WitnessTable *_Nullable *_Nonnull conformances;
    int32_t numConformances;
    
    TypeMetadata *_Nullable *_Nonnull genericParamList;
    
    int32_t size;
    const char *_Nonnull name;
    bool isRefCounted;
    
    /// Destroys the elements of this type
    void (*_Nullable destructor)(void *_Nullable);
    /// A user defined function to be run before deallocation. Called by codegen
    /// in the destructor
    void (*_Nullable deinitialiser)(void *_Nullable);
    /// Used to copy an instance of this object
    void (*_Nullable copyConstructor)(void *_Nullable, void *_Nullable);
    
    /// The size of runtime memory used to store an instance or reference to it
    /// \returns `sizeof(RefcountedObject)` iff self `isRefCounted`, otherwise `sizeof(self)`
    int32_t storageSize() {
        if (isRefCounted)
            return sizeof(RefcountedObject);
        return size;
    }
};

/// The modeling of a concept -- the concept and witness table
struct WitnessTable {
    /// The concept we are conforming to
    TypeMetadata *_Nonnull concept;
    
    /// The witness tables which provide conformance to this concept's inherited requirements
    WitnessTable *_Nullable *_Nonnull subtables;
    
    int32_t *_Nullable propWitnessOffsets;  /// Offset of concept elements
    int32_t numOffsets;       /// Number of offsets in `propWitnessOffsets`
    
    /// The witnesses
    void *_Nullable *_Nonnull witnesses;
    int32_t numWitnesses;
};

struct ExistentialObject {
    /// a tagged pointer containing the instance, and in the least
    /// significant bit, a flag stating whether the ptr is stored
    /// on the heap and needs deallocating
    uintptr_t instanceTaggedPtr;
    
public:
    WitnessTable *_Nonnull *_Nullable conformances;
    int32_t numConformances;
    /// The instance metadata
    TypeMetadata *_Nonnull metadata;
    
    ExistentialObject(uintptr_t object,
                      TypeMetadata *_Nonnull metadata,
                      int32_t numConformances,
                      WitnessTable *_Nonnull *_Nullable conformances)
    : instanceTaggedPtr(object), metadata(metadata), numConformances(numConformances), conformances(conformances) {}
    
    INLINE uintptr_t projectBuffer() {
        return (uintptr_t)instanceTaggedPtr & ~0x1;
    }
    INLINE bool isNonLocal() {
        return (uintptr_t)instanceTaggedPtr & 0x1;
    }
    INLINE void setNonLocalTag(bool tag) {
        if (tag)
            instanceTaggedPtr |= tag;
        else
            instanceTaggedPtr &= ~0x1;
    }
};



const char * _Nullable vist_demangle(const char * _Nonnull);



#endif /* runtime_h */
