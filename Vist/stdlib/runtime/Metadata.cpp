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


extern "C"
ExistentialObject *
vist_constructExistential(ConceptConformance *conformance,
                          void *instance) {
    return new ExistentialObject(instance, 1, &conformance);
}


#ifdef TESTING

int main() {
    
    auto md = vist_constructNominalTypeMetadata(nullptr, 0, "Foo");
    
    return 0;
}

#endif



