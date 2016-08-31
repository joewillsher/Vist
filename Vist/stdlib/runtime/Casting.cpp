//
//  Casting.cpp
//  Vist
//
//  Created by Josef Willsher on 10/05/2016.
//  Copyright © 2016 vistlang. All rights reserved.
//

#include <cstring>

// introspection

RUNTIME_STDLIB_INTERFACE
void *vist_runtime_getMetadata(ExistentialObject *ex) {
    return ex->metadata;
}
RUNTIME_STDLIB_INTERFACE
int64_t vist_runtime_metadataGetSize(void *md) {
    auto metadata = (TypeMetadata*)md;
    return metadata->size;
}
RUNTIME_STDLIB_INTERFACE
void *vist_runtime_metadataGetName(void *md) {
    auto metadata = (TypeMetadata*)md;
    return (void *)vist_demangle(metadata->name);
}


RUNTIME_COMPILER_INTERFACE
bool vist_castExistentialToConcrete(ExistentialObject *_Nonnull existential,
                                    TypeMetadata *_Nonnull targetMetadata,
                                    void *_Nullable out) {
    if (existential->metadata != targetMetadata)
        return false;
    // if the metadata is the same, we can copy into the out param
    memcpy(out, (void*)existential->projectBuffer(), targetMetadata->size);
    return true;
}
RUNTIME_COMPILER_INTERFACE
bool vist_castExistentialToConcept(ExistentialObject *_Nonnull existential,
                                   TypeMetadata *_Nonnull conceptMetadata,
                                   ExistentialObject *_Nullable out) {
    auto conformances = existential->metadata->conceptConformances;
    
#ifdef REFCOUNT_DEBUG
    printf("→cast %p %s to %s\n", existential->projectBuffer(), existential->metadata->name, conceptMetadata->name);
#endif
    
    for (int index = 0; index < existential->metadata->numConformances; index += 1) {
        auto conf = *(ConceptConformance **)(conformances[index]);
#ifdef REFCOUNT_DEBUG
        printf("   ↳candidate=%p: %s %s\n", conf, conf->concept->name, conceptMetadata->name);
#endif
        // TODO: when the compiler can guarantee only 1 metadata entry per type,
        //       do a ptr comparison here
        if (strcmp(conf->concept->name, conceptMetadata->name) == 0) {
            // if the metadata is the same, we can copy into the out param
            auto mem = malloc(conceptMetadata->size);
            memcpy(mem, (void*)existential->projectBuffer(), conceptMetadata->size);
            *out = ExistentialObject((uintptr_t)mem | true,
                                     conceptMetadata,
                                     1, (ConceptConformance **)conf);
#ifdef REFCOUNT_DEBUG
            printf("     ↳cast to: %p\n", mem);
#endif
            return true;
        }
    }
#ifdef REFCOUNT_DEBUG
    printf("   ↳no match found\n");
#endif
    return false;
}



