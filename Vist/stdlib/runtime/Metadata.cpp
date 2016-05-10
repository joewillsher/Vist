//
//  Metadata.cpp
//  Vist
//
//  Created by Josef Willsher on 10/5/2016.
//  Copyright © 2015 vistlang. All rights reserved.
//

/// A witness function to a concept
struct ValueWitness {
    void *witness;
}

/// A concept witness table
template <uint32_t NumWitnesses>
struct WitnessTable {
    /// the witnessing concept
    void *concept;
    /// The witnesses
    const ValueWitness *witnesses[NumWitnesses];
};

template <uint32_t NumWitnessTables>
struct TypeMetadata {
    WitnessTable *witnessTables;
    const WitnessTable *witnessTables[NumWitnessTables]
};

struct ExistentialObject {
    void *object
    int32_t *propWitnessOffsets;
    WitnessTable *wittnessTables;
};
//static std::map<char *, TypeMetadata *> typeCache;


extern "C"
ExistentialObject *
vist_constructExistential() {
    return nullptr;
}

extern "C"
WitnessTable *
vist_getWitnessTable(TypeMetadata *metadata) {
    return nullptr;
}



