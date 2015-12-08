/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* DAG Instruction Selector for the MSP430 target                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

// *** NOTE: This file is #included into the middle of the target
// *** instruction selector class.  These functions are really methods.

// The main instruction selector code.
SDNode *SelectCode(SDNode *N) {
  // Some target values are emitted as 2 bytes, TARGET_VAL handles
  // this.
  #define TARGET_VAL(X) X & 255, unsigned(X) >> 8
  static const unsigned char MatcherTable[] = {
/*0*/       OPC_SwitchOpcode /*34 cases */, 88|128,26/*3416*/, TARGET_VAL(ISD::STORE),// ->3421
/*5*/         OPC_RecordMemRef,
/*6*/         OPC_RecordNode, // #0 = 'st' chained node
/*7*/         OPC_Scope, 110|128,25/*3310*/, /*->3320*/ // 2 children in Scope
/*10*/          OPC_MoveChild, 1,
/*12*/          OPC_SwitchOpcode /*11 cases */, 81|128,5/*721*/, TARGET_VAL(ISD::AND),// ->738
/*17*/            OPC_Scope, 7|128,5/*647*/, /*->667*/ // 2 children in Scope
/*20*/              OPC_MoveChild, 0,
/*22*/              OPC_SwitchOpcode /*2 cases */, 62|128,3/*446*/, TARGET_VAL(ISD::LOAD),// ->473
/*27*/                OPC_RecordMemRef,
/*28*/                OPC_RecordNode, // #1 = 'ld' chained node
/*29*/                OPC_CheckFoldableChainNode,
/*30*/                OPC_RecordChild1, // #2 = $dst
/*31*/                OPC_CheckPredicate, 0, // Predicate_unindexedload
/*33*/                OPC_CheckPredicate, 1, // Predicate_load
/*35*/                OPC_MoveParent,
/*36*/                OPC_Scope, 54|128,2/*310*/, /*->349*/ // 2 children in Scope
/*39*/                  OPC_MoveChild, 1,
/*41*/                  OPC_SwitchOpcode /*2 cases */, 33|128,1/*161*/, TARGET_VAL(ISD::XOR),// ->207
/*46*/                    OPC_Scope, 90, /*->138*/ // 2 children in Scope
/*48*/                      OPC_MoveChild, 0,
/*50*/                      OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*53*/                      OPC_RecordMemRef,
/*54*/                      OPC_RecordNode, // #3 = 'ld' chained node
/*55*/                      OPC_CheckFoldableChainNode,
/*56*/                      OPC_RecordChild1, // #4 = $src
/*57*/                      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*59*/                      OPC_CheckPredicate, 1, // Predicate_load
/*61*/                      OPC_MoveParent,
/*62*/                      OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*73*/                      OPC_MoveParent,
/*74*/                      OPC_SwitchType /*2 cases */, 29, MVT::i8,// ->106
/*77*/                        OPC_MoveParent,
/*78*/                        OPC_CheckChild2Same, 2,
/*80*/                        OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*82*/                        OPC_CheckPredicate, 3, // Predicate_store
/*84*/                        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*87*/                        OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*90*/                        OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*95*/                        OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8mm), 0|OPFL_Chain|OPFL_MemRefs,
                                  1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                              // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (xor:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i8)), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 50
                              // Dst: (BIC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*106*/                     /*SwitchType*/ 29, MVT::i16,// ->137
/*108*/                       OPC_MoveParent,
/*109*/                       OPC_CheckChild2Same, 2,
/*111*/                       OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*113*/                       OPC_CheckPredicate, 3, // Predicate_store
/*115*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*118*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*121*/                       OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*126*/                       OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16mm), 0|OPFL_Chain|OPFL_MemRefs,
                                  1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                              // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (xor:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i16)), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 50
                              // Dst: (BIC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*137*/                     0, // EndSwitchType
/*138*/                   /*Scope*/ 67, /*->206*/
/*139*/                     OPC_RecordChild0, // #3 = $src
/*140*/                     OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*151*/                     OPC_MoveParent,
/*152*/                     OPC_SwitchType /*2 cases */, 24, MVT::i8,// ->179
/*155*/                       OPC_MoveParent,
/*156*/                       OPC_CheckChild2Same, 2,
/*158*/                       OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*160*/                       OPC_CheckPredicate, 3, // Predicate_store
/*162*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*165*/                       OPC_EmitMergeInputChains, 2, 0, 1, 
/*169*/                       OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8mr), 0|OPFL_Chain|OPFL_MemRefs,
                                  1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                              // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (xor:i8 GR8:i8:$src, -1:i8)), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 37
                              // Dst: (BIC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*179*/                     /*SwitchType*/ 24, MVT::i16,// ->205
/*181*/                       OPC_MoveParent,
/*182*/                       OPC_CheckChild2Same, 2,
/*184*/                       OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*186*/                       OPC_CheckPredicate, 3, // Predicate_store
/*188*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*191*/                       OPC_EmitMergeInputChains, 2, 0, 1, 
/*195*/                       OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16mr), 0|OPFL_Chain|OPFL_MemRefs,
                                  1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                              // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (xor:i16 GR16:i16:$src, -1:i16)), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 37
                              // Dst: (BIC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*205*/                     0, // EndSwitchType
/*206*/                   0, /*End of Scope*/
/*207*/                 /*SwitchOpcode*/ 9|128,1/*137*/, TARGET_VAL(ISD::LOAD),// ->348
/*211*/                   OPC_RecordMemRef,
/*212*/                   OPC_RecordNode, // #3 = 'ld' chained node
/*213*/                   OPC_CheckFoldableChainNode,
/*214*/                   OPC_RecordChild1, // #4 = $src
/*215*/                   OPC_CheckPredicate, 0, // Predicate_unindexedload
/*217*/                   OPC_CheckPredicate, 1, // Predicate_load
/*219*/                   OPC_MoveParent,
/*220*/                   OPC_SwitchType /*2 cases */, 61, MVT::i8,// ->284
/*223*/                     OPC_MoveParent,
/*224*/                     OPC_Scope, 28, /*->254*/ // 2 children in Scope
/*226*/                       OPC_CheckChild2Same, 2,
/*228*/                       OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*230*/                       OPC_CheckPredicate, 3, // Predicate_store
/*232*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*235*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*238*/                       OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*243*/                       OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mm), 0|OPFL_Chain|OPFL_MemRefs,
                                  1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                              // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                              // Dst: (AND8mm:i16 addr:i16:$dst, addr:i16:$src)
/*254*/                     /*Scope*/ 28, /*->283*/
/*255*/                       OPC_CheckChild2Same, 4,
/*257*/                       OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*259*/                       OPC_CheckPredicate, 3, // Predicate_store
/*261*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*264*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*267*/                       OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*272*/                       OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mm), 0|OPFL_Chain|OPFL_MemRefs,
                                  1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                              // Src: (st (and:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                              // Dst: (AND8mm:i16 addr:i16:$dst, addr:i16:$src)
/*283*/                     0, /*End of Scope*/
/*284*/                   /*SwitchType*/ 61, MVT::i16,// ->347
/*286*/                     OPC_MoveParent,
/*287*/                     OPC_Scope, 28, /*->317*/ // 2 children in Scope
/*289*/                       OPC_CheckChild2Same, 2,
/*291*/                       OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*293*/                       OPC_CheckPredicate, 3, // Predicate_store
/*295*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*298*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*301*/                       OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*306*/                       OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mm), 0|OPFL_Chain|OPFL_MemRefs,
                                  1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                              // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                              // Dst: (AND16mm:i16 addr:i16:$dst, addr:i16:$src)
/*317*/                     /*Scope*/ 28, /*->346*/
/*318*/                       OPC_CheckChild2Same, 4,
/*320*/                       OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*322*/                       OPC_CheckPredicate, 3, // Predicate_store
/*324*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*327*/                       OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*330*/                       OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*335*/                       OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mm), 0|OPFL_Chain|OPFL_MemRefs,
                                  1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                              // Src: (st (and:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                              // Dst: (AND16mm:i16 addr:i16:$dst, addr:i16:$src)
/*346*/                     0, /*End of Scope*/
/*347*/                   0, // EndSwitchType
/*348*/                 0, // EndSwitchOpcode
/*349*/               /*Scope*/ 122, /*->472*/
/*350*/                 OPC_RecordChild1, // #3 = $src
/*351*/                 OPC_Scope, 64, /*->417*/ // 3 children in Scope
/*353*/                   OPC_MoveChild, 1,
/*355*/                   OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*358*/                   OPC_MoveParent,
/*359*/                   OPC_SwitchType /*2 cases */, 26, MVT::i8,// ->388
/*362*/                     OPC_MoveParent,
/*363*/                     OPC_CheckChild2Same, 2,
/*365*/                     OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*367*/                     OPC_CheckPredicate, 3, // Predicate_store
/*369*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*372*/                     OPC_EmitMergeInputChains, 2, 0, 1, 
/*376*/                     OPC_EmitConvertToTarget, 3,
/*378*/                     OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mi), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                            // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                            // Dst: (AND8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*388*/                   /*SwitchType*/ 26, MVT::i16,// ->416
/*390*/                     OPC_MoveParent,
/*391*/                     OPC_CheckChild2Same, 2,
/*393*/                     OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*395*/                     OPC_CheckPredicate, 3, // Predicate_store
/*397*/                     OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*400*/                     OPC_EmitMergeInputChains, 2, 0, 1, 
/*404*/                     OPC_EmitConvertToTarget, 3,
/*406*/                     OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mi), 0|OPFL_Chain|OPFL_MemRefs,
                                1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                            // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                            // Dst: (AND16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*416*/                   0, // EndSwitchType
/*417*/                 /*Scope*/ 26, /*->444*/
/*418*/                   OPC_CheckType, MVT::i8,
/*420*/                   OPC_MoveParent,
/*421*/                   OPC_CheckChild2Same, 2,
/*423*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*425*/                   OPC_CheckPredicate, 3, // Predicate_store
/*427*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*430*/                   OPC_EmitMergeInputChains, 2, 0, 1, 
/*434*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mr), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                          // Src: (st (and:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                          // Dst: (AND8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*444*/                 /*Scope*/ 26, /*->471*/
/*445*/                   OPC_CheckType, MVT::i16,
/*447*/                   OPC_MoveParent,
/*448*/                   OPC_CheckChild2Same, 2,
/*450*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*452*/                   OPC_CheckPredicate, 3, // Predicate_store
/*454*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*457*/                   OPC_EmitMergeInputChains, 2, 0, 1, 
/*461*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mr), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                          // Src: (st (and:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                          // Dst: (AND16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*471*/                 0, /*End of Scope*/
/*472*/               0, /*End of Scope*/
/*473*/             /*SwitchOpcode*/ 61|128,1/*189*/, TARGET_VAL(ISD::XOR),// ->666
/*477*/               OPC_Scope, 104, /*->583*/ // 2 children in Scope
/*479*/                 OPC_MoveChild, 0,
/*481*/                 OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*484*/                 OPC_RecordMemRef,
/*485*/                 OPC_RecordNode, // #1 = 'ld' chained node
/*486*/                 OPC_CheckFoldableChainNode,
/*487*/                 OPC_RecordChild1, // #2 = $src
/*488*/                 OPC_CheckPredicate, 0, // Predicate_unindexedload
/*490*/                 OPC_CheckPredicate, 1, // Predicate_load
/*492*/                 OPC_MoveParent,
/*493*/                 OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*504*/                 OPC_MoveParent,
/*505*/                 OPC_MoveChild, 1,
/*507*/                 OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*510*/                 OPC_RecordMemRef,
/*511*/                 OPC_RecordNode, // #3 = 'ld' chained node
/*512*/                 OPC_CheckFoldableChainNode,
/*513*/                 OPC_RecordChild1, // #4 = $dst
/*514*/                 OPC_CheckPredicate, 0, // Predicate_unindexedload
/*516*/                 OPC_CheckPredicate, 1, // Predicate_load
/*518*/                 OPC_MoveParent,
/*519*/                 OPC_SwitchType /*2 cases */, 29, MVT::i8,// ->551
/*522*/                   OPC_MoveParent,
/*523*/                   OPC_CheckChild2Same, 4,
/*525*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*527*/                   OPC_CheckPredicate, 3, // Predicate_store
/*529*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*532*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*535*/                   OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*540*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                          // Src: (st (and:i8 (xor:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i8), (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 50
                          // Dst: (BIC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*551*/                 /*SwitchType*/ 29, MVT::i16,// ->582
/*553*/                   OPC_MoveParent,
/*554*/                   OPC_CheckChild2Same, 4,
/*556*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*558*/                   OPC_CheckPredicate, 3, // Predicate_store
/*560*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*563*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*566*/                   OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*571*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                          // Src: (st (and:i16 (xor:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i16), (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 50
                          // Dst: (BIC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*582*/                 0, // EndSwitchType
/*583*/               /*Scope*/ 81, /*->665*/
/*584*/                 OPC_RecordChild0, // #1 = $src
/*585*/                 OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*596*/                 OPC_MoveParent,
/*597*/                 OPC_MoveChild, 1,
/*599*/                 OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*602*/                 OPC_RecordMemRef,
/*603*/                 OPC_RecordNode, // #2 = 'ld' chained node
/*604*/                 OPC_CheckFoldableChainNode,
/*605*/                 OPC_RecordChild1, // #3 = $dst
/*606*/                 OPC_CheckPredicate, 0, // Predicate_unindexedload
/*608*/                 OPC_CheckPredicate, 1, // Predicate_load
/*610*/                 OPC_MoveParent,
/*611*/                 OPC_SwitchType /*2 cases */, 24, MVT::i8,// ->638
/*614*/                   OPC_MoveParent,
/*615*/                   OPC_CheckChild2Same, 3,
/*617*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*619*/                   OPC_CheckPredicate, 3, // Predicate_store
/*621*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*624*/                   OPC_EmitMergeInputChains, 2, 0, 2, 
/*628*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8mr), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                          // Src: (st (and:i8 (xor:i8 GR8:i8:$src, -1:i8), (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 37
                          // Dst: (BIC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*638*/                 /*SwitchType*/ 24, MVT::i16,// ->664
/*640*/                   OPC_MoveParent,
/*641*/                   OPC_CheckChild2Same, 3,
/*643*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*645*/                   OPC_CheckPredicate, 3, // Predicate_store
/*647*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*650*/                   OPC_EmitMergeInputChains, 2, 0, 2, 
/*654*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16mr), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                          // Src: (st (and:i16 (xor:i16 GR16:i16:$src, -1:i16), (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 37
                          // Dst: (BIC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*664*/                 0, // EndSwitchType
/*665*/               0, /*End of Scope*/
/*666*/             0, // EndSwitchOpcode
/*667*/           /*Scope*/ 69, /*->737*/
/*668*/             OPC_RecordChild0, // #1 = $src
/*669*/             OPC_MoveChild, 1,
/*671*/             OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*674*/             OPC_RecordMemRef,
/*675*/             OPC_RecordNode, // #2 = 'ld' chained node
/*676*/             OPC_CheckFoldableChainNode,
/*677*/             OPC_RecordChild1, // #3 = $dst
/*678*/             OPC_CheckPredicate, 0, // Predicate_unindexedload
/*680*/             OPC_CheckPredicate, 1, // Predicate_load
/*682*/             OPC_MoveParent,
/*683*/             OPC_SwitchType /*2 cases */, 24, MVT::i8,// ->710
/*686*/               OPC_MoveParent,
/*687*/               OPC_CheckChild2Same, 3,
/*689*/               OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*691*/               OPC_CheckPredicate, 3, // Predicate_store
/*693*/               OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*696*/               OPC_EmitMergeInputChains, 2, 0, 2, 
/*700*/               OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                      // Src: (st (and:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (AND8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*710*/             /*SwitchType*/ 24, MVT::i16,// ->736
/*712*/               OPC_MoveParent,
/*713*/               OPC_CheckChild2Same, 3,
/*715*/               OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*717*/               OPC_CheckPredicate, 3, // Predicate_store
/*719*/               OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*722*/               OPC_EmitMergeInputChains, 2, 0, 2, 
/*726*/               OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                      // Src: (st (and:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (AND16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*736*/             0, // EndSwitchType
/*737*/           0, /*End of Scope*/
/*738*/         /*SwitchOpcode*/ 101|128,2/*357*/, TARGET_VAL(ISD::ADD),// ->1099
/*742*/           OPC_Scope, 27|128,2/*283*/, /*->1028*/ // 2 children in Scope
/*745*/             OPC_MoveChild, 0,
/*747*/             OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*750*/             OPC_RecordMemRef,
/*751*/             OPC_RecordNode, // #1 = 'ld' chained node
/*752*/             OPC_CheckFoldableChainNode,
/*753*/             OPC_RecordChild1, // #2 = $dst
/*754*/             OPC_CheckPredicate, 0, // Predicate_unindexedload
/*756*/             OPC_CheckPredicate, 1, // Predicate_load
/*758*/             OPC_MoveParent,
/*759*/             OPC_Scope, 14|128,1/*142*/, /*->904*/ // 2 children in Scope
/*762*/               OPC_MoveChild, 1,
/*764*/               OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*767*/               OPC_RecordMemRef,
/*768*/               OPC_RecordNode, // #3 = 'ld' chained node
/*769*/               OPC_CheckFoldableChainNode,
/*770*/               OPC_RecordChild1, // #4 = $src
/*771*/               OPC_CheckPredicate, 0, // Predicate_unindexedload
/*773*/               OPC_CheckPredicate, 1, // Predicate_load
/*775*/               OPC_MoveParent,
/*776*/               OPC_SwitchType /*2 cases */, 61, MVT::i8,// ->840
/*779*/                 OPC_MoveParent,
/*780*/                 OPC_Scope, 28, /*->810*/ // 2 children in Scope
/*782*/                   OPC_CheckChild2Same, 2,
/*784*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*786*/                   OPC_CheckPredicate, 3, // Predicate_store
/*788*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*791*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*794*/                   OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*799*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                          // Src: (st (add:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADD8mm:i16 addr:i16:$dst, addr:i16:$src)
/*810*/                 /*Scope*/ 28, /*->839*/
/*811*/                   OPC_CheckChild2Same, 4,
/*813*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*815*/                   OPC_CheckPredicate, 3, // Predicate_store
/*817*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*820*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*823*/                   OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*828*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                          // Src: (st (add:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADD8mm:i16 addr:i16:$dst, addr:i16:$src)
/*839*/                 0, /*End of Scope*/
/*840*/               /*SwitchType*/ 61, MVT::i16,// ->903
/*842*/                 OPC_MoveParent,
/*843*/                 OPC_Scope, 28, /*->873*/ // 2 children in Scope
/*845*/                   OPC_CheckChild2Same, 2,
/*847*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*849*/                   OPC_CheckPredicate, 3, // Predicate_store
/*851*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*854*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*857*/                   OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*862*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                          // Src: (st (add:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADD16mm:i16 addr:i16:$dst, addr:i16:$src)
/*873*/                 /*Scope*/ 28, /*->902*/
/*874*/                   OPC_CheckChild2Same, 4,
/*876*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*878*/                   OPC_CheckPredicate, 3, // Predicate_store
/*880*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*883*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*886*/                   OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*891*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                          // Src: (st (add:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADD16mm:i16 addr:i16:$dst, addr:i16:$src)
/*902*/                 0, /*End of Scope*/
/*903*/               0, // EndSwitchType
/*904*/             /*Scope*/ 122, /*->1027*/
/*905*/               OPC_RecordChild1, // #3 = $src
/*906*/               OPC_Scope, 64, /*->972*/ // 3 children in Scope
/*908*/                 OPC_MoveChild, 1,
/*910*/                 OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*913*/                 OPC_MoveParent,
/*914*/                 OPC_SwitchType /*2 cases */, 26, MVT::i8,// ->943
/*917*/                   OPC_MoveParent,
/*918*/                   OPC_CheckChild2Same, 2,
/*920*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*922*/                   OPC_CheckPredicate, 3, // Predicate_store
/*924*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*927*/                   OPC_EmitMergeInputChains, 2, 0, 1, 
/*931*/                   OPC_EmitConvertToTarget, 3,
/*933*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mi), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                          // Src: (st (add:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (ADD8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*943*/                 /*SwitchType*/ 26, MVT::i16,// ->971
/*945*/                   OPC_MoveParent,
/*946*/                   OPC_CheckChild2Same, 2,
/*948*/                   OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*950*/                   OPC_CheckPredicate, 3, // Predicate_store
/*952*/                   OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*955*/                   OPC_EmitMergeInputChains, 2, 0, 1, 
/*959*/                   OPC_EmitConvertToTarget, 3,
/*961*/                   OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mi), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                          // Src: (st (add:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (ADD16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*971*/                 0, // EndSwitchType
/*972*/               /*Scope*/ 26, /*->999*/
/*973*/                 OPC_CheckType, MVT::i8,
/*975*/                 OPC_MoveParent,
/*976*/                 OPC_CheckChild2Same, 2,
/*978*/                 OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*980*/                 OPC_CheckPredicate, 3, // Predicate_store
/*982*/                 OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*985*/                 OPC_EmitMergeInputChains, 2, 0, 1, 
/*989*/                 OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                        // Src: (st (add:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (ADD8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*999*/               /*Scope*/ 26, /*->1026*/
/*1000*/                OPC_CheckType, MVT::i16,
/*1002*/                OPC_MoveParent,
/*1003*/                OPC_CheckChild2Same, 2,
/*1005*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1007*/                OPC_CheckPredicate, 3, // Predicate_store
/*1009*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1012*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*1016*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                        // Src: (st (add:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (ADD16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1026*/              0, /*End of Scope*/
/*1027*/            0, /*End of Scope*/
/*1028*/          /*Scope*/ 69, /*->1098*/
/*1029*/            OPC_RecordChild0, // #1 = $src
/*1030*/            OPC_MoveChild, 1,
/*1032*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1035*/            OPC_RecordMemRef,
/*1036*/            OPC_RecordNode, // #2 = 'ld' chained node
/*1037*/            OPC_CheckFoldableChainNode,
/*1038*/            OPC_RecordChild1, // #3 = $dst
/*1039*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1041*/            OPC_CheckPredicate, 1, // Predicate_load
/*1043*/            OPC_MoveParent,
/*1044*/            OPC_SwitchType /*2 cases */, 24, MVT::i8,// ->1071
/*1047*/              OPC_MoveParent,
/*1048*/              OPC_CheckChild2Same, 3,
/*1050*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1052*/              OPC_CheckPredicate, 3, // Predicate_store
/*1054*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*1057*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*1061*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                      // Src: (st (add:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADD8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1071*/            /*SwitchType*/ 24, MVT::i16,// ->1097
/*1073*/              OPC_MoveParent,
/*1074*/              OPC_CheckChild2Same, 3,
/*1076*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1078*/              OPC_CheckPredicate, 3, // Predicate_store
/*1080*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*1083*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*1087*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                      // Src: (st (add:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADD16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1097*/            0, // EndSwitchType
/*1098*/          0, /*End of Scope*/
/*1099*/        /*SwitchOpcode*/ 6|128,3/*390*/, TARGET_VAL(ISD::ADDE),// ->1493
/*1103*/          OPC_RecordNode, // #1 = 'adde' glue output node
/*1104*/          OPC_CaptureGlueInput,
/*1105*/          OPC_Scope, 52|128,2/*308*/, /*->1416*/ // 2 children in Scope
/*1108*/            OPC_MoveChild, 0,
/*1110*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1113*/            OPC_RecordMemRef,
/*1114*/            OPC_RecordNode, // #2 = 'ld' chained node
/*1115*/            OPC_CheckFoldableChainNode,
/*1116*/            OPC_RecordChild1, // #3 = $dst
/*1117*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1119*/            OPC_CheckPredicate, 1, // Predicate_load
/*1121*/            OPC_MoveParent,
/*1122*/            OPC_Scope, 26|128,1/*154*/, /*->1279*/ // 2 children in Scope
/*1125*/              OPC_MoveChild, 1,
/*1127*/              OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1130*/              OPC_RecordMemRef,
/*1131*/              OPC_RecordNode, // #4 = 'ld' chained node
/*1132*/              OPC_CheckFoldableChainNode,
/*1133*/              OPC_RecordChild1, // #5 = $src
/*1134*/              OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1136*/              OPC_CheckPredicate, 1, // Predicate_load
/*1138*/              OPC_MoveParent,
/*1139*/              OPC_SwitchType /*2 cases */, 67, MVT::i8,// ->1209
/*1142*/                OPC_MoveParent,
/*1143*/                OPC_Scope, 31, /*->1176*/ // 2 children in Scope
/*1145*/                  OPC_CheckChild2Same, 3,
/*1147*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1149*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1151*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*1154*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*1157*/                  OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*1162*/                  OPC_MarkGlueResults, 1, 1, 
/*1165*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                          // Src: (st (adde:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1176*/                /*Scope*/ 31, /*->1208*/
/*1177*/                  OPC_CheckChild2Same, 5,
/*1179*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1181*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1183*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src #6 #7
/*1186*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$dst #8 #9
/*1189*/                  OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*1194*/                  OPC_MarkGlueResults, 1, 1, 
/*1197*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 8, 9, 6, 7, 
                          // Src: (st (adde:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1208*/                0, /*End of Scope*/
/*1209*/              /*SwitchType*/ 67, MVT::i16,// ->1278
/*1211*/                OPC_MoveParent,
/*1212*/                OPC_Scope, 31, /*->1245*/ // 2 children in Scope
/*1214*/                  OPC_CheckChild2Same, 3,
/*1216*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1218*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1220*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*1223*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*1226*/                  OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*1231*/                  OPC_MarkGlueResults, 1, 1, 
/*1234*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                          // Src: (st (adde:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*1245*/                /*Scope*/ 31, /*->1277*/
/*1246*/                  OPC_CheckChild2Same, 5,
/*1248*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1250*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1252*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src #6 #7
/*1255*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$dst #8 #9
/*1258*/                  OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*1263*/                  OPC_MarkGlueResults, 1, 1, 
/*1266*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 8, 9, 6, 7, 
                          // Src: (st (adde:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*1277*/                0, /*End of Scope*/
/*1278*/              0, // EndSwitchType
/*1279*/            /*Scope*/ 6|128,1/*134*/, /*->1415*/
/*1281*/              OPC_RecordChild1, // #4 = $src
/*1282*/              OPC_Scope, 70, /*->1354*/ // 3 children in Scope
/*1284*/                OPC_MoveChild, 1,
/*1286*/                OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1289*/                OPC_MoveParent,
/*1290*/                OPC_SwitchType /*2 cases */, 29, MVT::i8,// ->1322
/*1293*/                  OPC_MoveParent,
/*1294*/                  OPC_CheckChild2Same, 3,
/*1296*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1298*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1300*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*1303*/                  OPC_EmitMergeInputChains, 2, 0, 2, 
/*1307*/                  OPC_EmitConvertToTarget, 4,
/*1309*/                  OPC_MarkGlueResults, 1, 1, 
/*1312*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 7, 
                          // Src: (st (adde:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (ADC8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*1322*/                /*SwitchType*/ 29, MVT::i16,// ->1353
/*1324*/                  OPC_MoveParent,
/*1325*/                  OPC_CheckChild2Same, 3,
/*1327*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1329*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1331*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*1334*/                  OPC_EmitMergeInputChains, 2, 0, 2, 
/*1338*/                  OPC_EmitConvertToTarget, 4,
/*1340*/                  OPC_MarkGlueResults, 1, 1, 
/*1343*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 7, 
                          // Src: (st (adde:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (ADC16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*1353*/                0, // EndSwitchType
/*1354*/              /*Scope*/ 29, /*->1384*/
/*1355*/                OPC_CheckType, MVT::i8,
/*1357*/                OPC_MoveParent,
/*1358*/                OPC_CheckChild2Same, 3,
/*1360*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1362*/                OPC_CheckPredicate, 3, // Predicate_store
/*1364*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*1367*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*1371*/                OPC_MarkGlueResults, 1, 1, 
/*1374*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                        // Src: (st (adde:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (ADC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1384*/              /*Scope*/ 29, /*->1414*/
/*1385*/                OPC_CheckType, MVT::i16,
/*1387*/                OPC_MoveParent,
/*1388*/                OPC_CheckChild2Same, 3,
/*1390*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1392*/                OPC_CheckPredicate, 3, // Predicate_store
/*1394*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*1397*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*1401*/                OPC_MarkGlueResults, 1, 1, 
/*1404*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                        // Src: (st (adde:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (ADC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1414*/              0, /*End of Scope*/
/*1415*/            0, /*End of Scope*/
/*1416*/          /*Scope*/ 75, /*->1492*/
/*1417*/            OPC_RecordChild0, // #2 = $src
/*1418*/            OPC_MoveChild, 1,
/*1420*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1423*/            OPC_RecordMemRef,
/*1424*/            OPC_RecordNode, // #3 = 'ld' chained node
/*1425*/            OPC_CheckFoldableChainNode,
/*1426*/            OPC_RecordChild1, // #4 = $dst
/*1427*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1429*/            OPC_CheckPredicate, 1, // Predicate_load
/*1431*/            OPC_MoveParent,
/*1432*/            OPC_SwitchType /*2 cases */, 27, MVT::i8,// ->1462
/*1435*/              OPC_MoveParent,
/*1436*/              OPC_CheckChild2Same, 4,
/*1438*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1440*/              OPC_CheckPredicate, 3, // Predicate_store
/*1442*/              OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #5 #6
/*1445*/              OPC_EmitMergeInputChains, 2, 0, 3, 
/*1449*/              OPC_MarkGlueResults, 1, 1, 
/*1452*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 2, 
                      // Src: (st (adde:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1462*/            /*SwitchType*/ 27, MVT::i16,// ->1491
/*1464*/              OPC_MoveParent,
/*1465*/              OPC_CheckChild2Same, 4,
/*1467*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1469*/              OPC_CheckPredicate, 3, // Predicate_store
/*1471*/              OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #5 #6
/*1474*/              OPC_EmitMergeInputChains, 2, 0, 3, 
/*1478*/              OPC_MarkGlueResults, 1, 1, 
/*1481*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 2, 
                      // Src: (st (adde:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1491*/            0, // EndSwitchType
/*1492*/          0, /*End of Scope*/
/*1493*/        /*SwitchOpcode*/ 101|128,2/*357*/, TARGET_VAL(ISD::OR),// ->1854
/*1497*/          OPC_Scope, 27|128,2/*283*/, /*->1783*/ // 2 children in Scope
/*1500*/            OPC_MoveChild, 0,
/*1502*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1505*/            OPC_RecordMemRef,
/*1506*/            OPC_RecordNode, // #1 = 'ld' chained node
/*1507*/            OPC_CheckFoldableChainNode,
/*1508*/            OPC_RecordChild1, // #2 = $dst
/*1509*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1511*/            OPC_CheckPredicate, 1, // Predicate_load
/*1513*/            OPC_MoveParent,
/*1514*/            OPC_Scope, 14|128,1/*142*/, /*->1659*/ // 2 children in Scope
/*1517*/              OPC_MoveChild, 1,
/*1519*/              OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1522*/              OPC_RecordMemRef,
/*1523*/              OPC_RecordNode, // #3 = 'ld' chained node
/*1524*/              OPC_CheckFoldableChainNode,
/*1525*/              OPC_RecordChild1, // #4 = $src
/*1526*/              OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1528*/              OPC_CheckPredicate, 1, // Predicate_load
/*1530*/              OPC_MoveParent,
/*1531*/              OPC_SwitchType /*2 cases */, 61, MVT::i8,// ->1595
/*1534*/                OPC_MoveParent,
/*1535*/                OPC_Scope, 28, /*->1565*/ // 2 children in Scope
/*1537*/                  OPC_CheckChild2Same, 2,
/*1539*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1541*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1543*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*1546*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*1549*/                  OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1554*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                          // Src: (st (or:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (OR8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1565*/                /*Scope*/ 28, /*->1594*/
/*1566*/                  OPC_CheckChild2Same, 4,
/*1568*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1570*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1572*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*1575*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*1578*/                  OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1583*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                          // Src: (st (or:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (OR8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1594*/                0, /*End of Scope*/
/*1595*/              /*SwitchType*/ 61, MVT::i16,// ->1658
/*1597*/                OPC_MoveParent,
/*1598*/                OPC_Scope, 28, /*->1628*/ // 2 children in Scope
/*1600*/                  OPC_CheckChild2Same, 2,
/*1602*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1604*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1606*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*1609*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*1612*/                  OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1617*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                          // Src: (st (or:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (OR16mm:i16 addr:i16:$dst, addr:i16:$src)
/*1628*/                /*Scope*/ 28, /*->1657*/
/*1629*/                  OPC_CheckChild2Same, 4,
/*1631*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1633*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1635*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*1638*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*1641*/                  OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1646*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                          // Src: (st (or:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (OR16mm:i16 addr:i16:$dst, addr:i16:$src)
/*1657*/                0, /*End of Scope*/
/*1658*/              0, // EndSwitchType
/*1659*/            /*Scope*/ 122, /*->1782*/
/*1660*/              OPC_RecordChild1, // #3 = $src
/*1661*/              OPC_Scope, 64, /*->1727*/ // 3 children in Scope
/*1663*/                OPC_MoveChild, 1,
/*1665*/                OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1668*/                OPC_MoveParent,
/*1669*/                OPC_SwitchType /*2 cases */, 26, MVT::i8,// ->1698
/*1672*/                  OPC_MoveParent,
/*1673*/                  OPC_CheckChild2Same, 2,
/*1675*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1677*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1679*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1682*/                  OPC_EmitMergeInputChains, 2, 0, 1, 
/*1686*/                  OPC_EmitConvertToTarget, 3,
/*1688*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mi), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                          // Src: (st (or:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (OR8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*1698*/                /*SwitchType*/ 26, MVT::i16,// ->1726
/*1700*/                  OPC_MoveParent,
/*1701*/                  OPC_CheckChild2Same, 2,
/*1703*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1705*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1707*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1710*/                  OPC_EmitMergeInputChains, 2, 0, 1, 
/*1714*/                  OPC_EmitConvertToTarget, 3,
/*1716*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mi), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                          // Src: (st (or:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (OR16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*1726*/                0, // EndSwitchType
/*1727*/              /*Scope*/ 26, /*->1754*/
/*1728*/                OPC_CheckType, MVT::i8,
/*1730*/                OPC_MoveParent,
/*1731*/                OPC_CheckChild2Same, 2,
/*1733*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1735*/                OPC_CheckPredicate, 3, // Predicate_store
/*1737*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1740*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*1744*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                        // Src: (st (or:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (OR8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1754*/              /*Scope*/ 26, /*->1781*/
/*1755*/                OPC_CheckType, MVT::i16,
/*1757*/                OPC_MoveParent,
/*1758*/                OPC_CheckChild2Same, 2,
/*1760*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1762*/                OPC_CheckPredicate, 3, // Predicate_store
/*1764*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*1767*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*1771*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                        // Src: (st (or:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (OR16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1781*/              0, /*End of Scope*/
/*1782*/            0, /*End of Scope*/
/*1783*/          /*Scope*/ 69, /*->1853*/
/*1784*/            OPC_RecordChild0, // #1 = $src
/*1785*/            OPC_MoveChild, 1,
/*1787*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1790*/            OPC_RecordMemRef,
/*1791*/            OPC_RecordNode, // #2 = 'ld' chained node
/*1792*/            OPC_CheckFoldableChainNode,
/*1793*/            OPC_RecordChild1, // #3 = $dst
/*1794*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1796*/            OPC_CheckPredicate, 1, // Predicate_load
/*1798*/            OPC_MoveParent,
/*1799*/            OPC_SwitchType /*2 cases */, 24, MVT::i8,// ->1826
/*1802*/              OPC_MoveParent,
/*1803*/              OPC_CheckChild2Same, 3,
/*1805*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1807*/              OPC_CheckPredicate, 3, // Predicate_store
/*1809*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*1812*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*1816*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                      // Src: (st (or:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (OR8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*1826*/            /*SwitchType*/ 24, MVT::i16,// ->1852
/*1828*/              OPC_MoveParent,
/*1829*/              OPC_CheckChild2Same, 3,
/*1831*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1833*/              OPC_CheckPredicate, 3, // Predicate_store
/*1835*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*1838*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*1842*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                      // Src: (st (or:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (OR16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*1852*/            0, // EndSwitchType
/*1853*/          0, /*End of Scope*/
/*1854*/        /*SwitchOpcode*/ 101|128,2/*357*/, TARGET_VAL(ISD::XOR),// ->2215
/*1858*/          OPC_Scope, 27|128,2/*283*/, /*->2144*/ // 2 children in Scope
/*1861*/            OPC_MoveChild, 0,
/*1863*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1866*/            OPC_RecordMemRef,
/*1867*/            OPC_RecordNode, // #1 = 'ld' chained node
/*1868*/            OPC_CheckFoldableChainNode,
/*1869*/            OPC_RecordChild1, // #2 = $dst
/*1870*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1872*/            OPC_CheckPredicate, 1, // Predicate_load
/*1874*/            OPC_MoveParent,
/*1875*/            OPC_Scope, 14|128,1/*142*/, /*->2020*/ // 2 children in Scope
/*1878*/              OPC_MoveChild, 1,
/*1880*/              OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*1883*/              OPC_RecordMemRef,
/*1884*/              OPC_RecordNode, // #3 = 'ld' chained node
/*1885*/              OPC_CheckFoldableChainNode,
/*1886*/              OPC_RecordChild1, // #4 = $src
/*1887*/              OPC_CheckPredicate, 0, // Predicate_unindexedload
/*1889*/              OPC_CheckPredicate, 1, // Predicate_load
/*1891*/              OPC_MoveParent,
/*1892*/              OPC_SwitchType /*2 cases */, 61, MVT::i8,// ->1956
/*1895*/                OPC_MoveParent,
/*1896*/                OPC_Scope, 28, /*->1926*/ // 2 children in Scope
/*1898*/                  OPC_CheckChild2Same, 2,
/*1900*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1902*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1904*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*1907*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*1910*/                  OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1915*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                          // Src: (st (xor:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (XOR8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1926*/                /*Scope*/ 28, /*->1955*/
/*1927*/                  OPC_CheckChild2Same, 4,
/*1929*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1931*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1933*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*1936*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*1939*/                  OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1944*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                          // Src: (st (xor:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (XOR8mm:i16 addr:i16:$dst, addr:i16:$src)
/*1955*/                0, /*End of Scope*/
/*1956*/              /*SwitchType*/ 61, MVT::i16,// ->2019
/*1958*/                OPC_MoveParent,
/*1959*/                OPC_Scope, 28, /*->1989*/ // 2 children in Scope
/*1961*/                  OPC_CheckChild2Same, 2,
/*1963*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1965*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1967*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*1970*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*1973*/                  OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*1978*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                          // Src: (st (xor:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (XOR16mm:i16 addr:i16:$dst, addr:i16:$src)
/*1989*/                /*Scope*/ 28, /*->2018*/
/*1990*/                  OPC_CheckChild2Same, 4,
/*1992*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*1994*/                  OPC_CheckPredicate, 3, // Predicate_store
/*1996*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #5 #6
/*1999*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #7 #8
/*2002*/                  OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2007*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mm), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 7, 8, 5, 6, 
                          // Src: (st (xor:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (XOR16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2018*/                0, /*End of Scope*/
/*2019*/              0, // EndSwitchType
/*2020*/            /*Scope*/ 122, /*->2143*/
/*2021*/              OPC_RecordChild1, // #3 = $src
/*2022*/              OPC_Scope, 64, /*->2088*/ // 3 children in Scope
/*2024*/                OPC_MoveChild, 1,
/*2026*/                OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2029*/                OPC_MoveParent,
/*2030*/                OPC_SwitchType /*2 cases */, 26, MVT::i8,// ->2059
/*2033*/                  OPC_MoveParent,
/*2034*/                  OPC_CheckChild2Same, 2,
/*2036*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2038*/                  OPC_CheckPredicate, 3, // Predicate_store
/*2040*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2043*/                  OPC_EmitMergeInputChains, 2, 0, 1, 
/*2047*/                  OPC_EmitConvertToTarget, 3,
/*2049*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mi), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                          // Src: (st (xor:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (XOR8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*2059*/                /*SwitchType*/ 26, MVT::i16,// ->2087
/*2061*/                  OPC_MoveParent,
/*2062*/                  OPC_CheckChild2Same, 2,
/*2064*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2066*/                  OPC_CheckPredicate, 3, // Predicate_store
/*2068*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2071*/                  OPC_EmitMergeInputChains, 2, 0, 1, 
/*2075*/                  OPC_EmitConvertToTarget, 3,
/*2077*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mi), 0|OPFL_Chain|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                          // Src: (st (xor:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                          // Dst: (XOR16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*2087*/                0, // EndSwitchType
/*2088*/              /*Scope*/ 26, /*->2115*/
/*2089*/                OPC_CheckType, MVT::i8,
/*2091*/                OPC_MoveParent,
/*2092*/                OPC_CheckChild2Same, 2,
/*2094*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2096*/                OPC_CheckPredicate, 3, // Predicate_store
/*2098*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2101*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*2105*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                        // Src: (st (xor:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (XOR8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2115*/              /*Scope*/ 26, /*->2142*/
/*2116*/                OPC_CheckType, MVT::i16,
/*2118*/                OPC_MoveParent,
/*2119*/                OPC_CheckChild2Same, 2,
/*2121*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2123*/                OPC_CheckPredicate, 3, // Predicate_store
/*2125*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2128*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*2132*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mr), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                        // Src: (st (xor:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (XOR16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2142*/              0, /*End of Scope*/
/*2143*/            0, /*End of Scope*/
/*2144*/          /*Scope*/ 69, /*->2214*/
/*2145*/            OPC_RecordChild0, // #1 = $src
/*2146*/            OPC_MoveChild, 1,
/*2148*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2151*/            OPC_RecordMemRef,
/*2152*/            OPC_RecordNode, // #2 = 'ld' chained node
/*2153*/            OPC_CheckFoldableChainNode,
/*2154*/            OPC_RecordChild1, // #3 = $dst
/*2155*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2157*/            OPC_CheckPredicate, 1, // Predicate_load
/*2159*/            OPC_MoveParent,
/*2160*/            OPC_SwitchType /*2 cases */, 24, MVT::i8,// ->2187
/*2163*/              OPC_MoveParent,
/*2164*/              OPC_CheckChild2Same, 3,
/*2166*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2168*/              OPC_CheckPredicate, 3, // Predicate_store
/*2170*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*2173*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*2177*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                      // Src: (st (xor:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (XOR8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2187*/            /*SwitchType*/ 24, MVT::i16,// ->2213
/*2189*/              OPC_MoveParent,
/*2190*/              OPC_CheckChild2Same, 3,
/*2192*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2194*/              OPC_CheckPredicate, 3, // Predicate_store
/*2196*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #4 #5
/*2199*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*2203*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 1, 
                      // Src: (st (xor:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (XOR16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2213*/            0, // EndSwitchType
/*2214*/          0, /*End of Scope*/
/*2215*/        /*SwitchOpcode*/ 90|128,1/*218*/, TARGET_VAL(ISD::SUB),// ->2437
/*2219*/          OPC_MoveChild, 0,
/*2221*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2224*/          OPC_RecordMemRef,
/*2225*/          OPC_RecordNode, // #1 = 'ld' chained node
/*2226*/          OPC_CheckFoldableChainNode,
/*2227*/          OPC_RecordChild1, // #2 = $dst
/*2228*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2230*/          OPC_CheckPredicate, 1, // Predicate_load
/*2232*/          OPC_MoveParent,
/*2233*/          OPC_Scope, 78, /*->2313*/ // 2 children in Scope
/*2235*/            OPC_MoveChild, 1,
/*2237*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2240*/            OPC_RecordMemRef,
/*2241*/            OPC_RecordNode, // #3 = 'ld' chained node
/*2242*/            OPC_CheckFoldableChainNode,
/*2243*/            OPC_RecordChild1, // #4 = $src
/*2244*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2246*/            OPC_CheckPredicate, 1, // Predicate_load
/*2248*/            OPC_MoveParent,
/*2249*/            OPC_SwitchType /*2 cases */, 29, MVT::i8,// ->2281
/*2252*/              OPC_MoveParent,
/*2253*/              OPC_CheckChild2Same, 2,
/*2255*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2257*/              OPC_CheckPredicate, 3, // Predicate_store
/*2259*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*2262*/              OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*2265*/              OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2270*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mm), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                      // Src: (st (sub:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                      // Dst: (SUB8mm:i16 addr:i16:$dst, addr:i16:$src)
/*2281*/            /*SwitchType*/ 29, MVT::i16,// ->2312
/*2283*/              OPC_MoveParent,
/*2284*/              OPC_CheckChild2Same, 2,
/*2286*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2288*/              OPC_CheckPredicate, 3, // Predicate_store
/*2290*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #5 #6
/*2293*/              OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$src #7 #8
/*2296*/              OPC_EmitMergeInputChains, 3, 0, 1, 3, 
/*2301*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mm), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 4/*#Ops*/, 5, 6, 7, 8, 
                      // Src: (st (sub:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                      // Dst: (SUB16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2312*/            0, // EndSwitchType
/*2313*/          /*Scope*/ 122, /*->2436*/
/*2314*/            OPC_RecordChild1, // #3 = $src
/*2315*/            OPC_Scope, 64, /*->2381*/ // 3 children in Scope
/*2317*/              OPC_MoveChild, 1,
/*2319*/              OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2322*/              OPC_MoveParent,
/*2323*/              OPC_SwitchType /*2 cases */, 26, MVT::i8,// ->2352
/*2326*/                OPC_MoveParent,
/*2327*/                OPC_CheckChild2Same, 2,
/*2329*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2331*/                OPC_CheckPredicate, 3, // Predicate_store
/*2333*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2336*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*2340*/                OPC_EmitConvertToTarget, 3,
/*2342*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mi), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                        // Src: (st (sub:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (SUB8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*2352*/              /*SwitchType*/ 26, MVT::i16,// ->2380
/*2354*/                OPC_MoveParent,
/*2355*/                OPC_CheckChild2Same, 2,
/*2357*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2359*/                OPC_CheckPredicate, 3, // Predicate_store
/*2361*/                OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2364*/                OPC_EmitMergeInputChains, 2, 0, 1, 
/*2368*/                OPC_EmitConvertToTarget, 3,
/*2370*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mi), 0|OPFL_Chain|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 6, 
                        // Src: (st (sub:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (SUB16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*2380*/              0, // EndSwitchType
/*2381*/            /*Scope*/ 26, /*->2408*/
/*2382*/              OPC_CheckType, MVT::i8,
/*2384*/              OPC_MoveParent,
/*2385*/              OPC_CheckChild2Same, 2,
/*2387*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2389*/              OPC_CheckPredicate, 3, // Predicate_store
/*2391*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2394*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*2398*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (st (sub:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (SUB8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2408*/            /*Scope*/ 26, /*->2435*/
/*2409*/              OPC_CheckType, MVT::i16,
/*2411*/              OPC_MoveParent,
/*2412*/              OPC_CheckChild2Same, 2,
/*2414*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2416*/              OPC_CheckPredicate, 3, // Predicate_store
/*2418*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #4 #5
/*2421*/              OPC_EmitMergeInputChains, 2, 0, 1, 
/*2425*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mr), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 4, 5, 3, 
                      // Src: (st (sub:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (SUB16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2435*/            0, /*End of Scope*/
/*2436*/          0, /*End of Scope*/
/*2437*/        /*SwitchOpcode*/ 111|128,1/*239*/, TARGET_VAL(ISD::SUBE),// ->2680
/*2441*/          OPC_RecordNode, // #1 = 'sube' glue output node
/*2442*/          OPC_CaptureGlueInput,
/*2443*/          OPC_MoveChild, 0,
/*2445*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2448*/          OPC_RecordMemRef,
/*2449*/          OPC_RecordNode, // #2 = 'ld' chained node
/*2450*/          OPC_CheckFoldableChainNode,
/*2451*/          OPC_RecordChild1, // #3 = $dst
/*2452*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2454*/          OPC_CheckPredicate, 1, // Predicate_load
/*2456*/          OPC_MoveParent,
/*2457*/          OPC_Scope, 84, /*->2543*/ // 2 children in Scope
/*2459*/            OPC_MoveChild, 1,
/*2461*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2464*/            OPC_RecordMemRef,
/*2465*/            OPC_RecordNode, // #4 = 'ld' chained node
/*2466*/            OPC_CheckFoldableChainNode,
/*2467*/            OPC_RecordChild1, // #5 = $src
/*2468*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2470*/            OPC_CheckPredicate, 1, // Predicate_load
/*2472*/            OPC_MoveParent,
/*2473*/            OPC_SwitchType /*2 cases */, 32, MVT::i8,// ->2508
/*2476*/              OPC_MoveParent,
/*2477*/              OPC_CheckChild2Same, 3,
/*2479*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2481*/              OPC_CheckPredicate, 3, // Predicate_store
/*2483*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*2486*/              OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*2489*/              OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2494*/              OPC_MarkGlueResults, 1, 1, 
/*2497*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                      // Src: (st (sube:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                      // Dst: (SBC8mm:i16 addr:i16:$dst, addr:i16:$src)
/*2508*/            /*SwitchType*/ 32, MVT::i16,// ->2542
/*2510*/              OPC_MoveParent,
/*2511*/              OPC_CheckChild2Same, 3,
/*2513*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2515*/              OPC_CheckPredicate, 3, // Predicate_store
/*2517*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*2520*/              OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*2523*/              OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2528*/              OPC_MarkGlueResults, 1, 1, 
/*2531*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16mm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                      // Src: (st (sube:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                      // Dst: (SBC16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2542*/            0, // EndSwitchType
/*2543*/          /*Scope*/ 6|128,1/*134*/, /*->2679*/
/*2545*/            OPC_RecordChild1, // #4 = $src
/*2546*/            OPC_Scope, 70, /*->2618*/ // 3 children in Scope
/*2548*/              OPC_MoveChild, 1,
/*2550*/              OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2553*/              OPC_MoveParent,
/*2554*/              OPC_SwitchType /*2 cases */, 29, MVT::i8,// ->2586
/*2557*/                OPC_MoveParent,
/*2558*/                OPC_CheckChild2Same, 3,
/*2560*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2562*/                OPC_CheckPredicate, 3, // Predicate_store
/*2564*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2567*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*2571*/                OPC_EmitConvertToTarget, 4,
/*2573*/                OPC_MarkGlueResults, 1, 1, 
/*2576*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8mi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 7, 
                        // Src: (st (sube:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (SBC8mi:i16 addr:i16:$dst, (imm:i8):$src)
/*2586*/              /*SwitchType*/ 29, MVT::i16,// ->2617
/*2588*/                OPC_MoveParent,
/*2589*/                OPC_CheckChild2Same, 3,
/*2591*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2593*/                OPC_CheckPredicate, 3, // Predicate_store
/*2595*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2598*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*2602*/                OPC_EmitConvertToTarget, 4,
/*2604*/                OPC_MarkGlueResults, 1, 1, 
/*2607*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16mi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 7, 
                        // Src: (st (sube:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 32
                        // Dst: (SBC16mi:i16 addr:i16:$dst, (imm:i16):$src)
/*2617*/              0, // EndSwitchType
/*2618*/            /*Scope*/ 29, /*->2648*/
/*2619*/              OPC_CheckType, MVT::i8,
/*2621*/              OPC_MoveParent,
/*2622*/              OPC_CheckChild2Same, 3,
/*2624*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2626*/              OPC_CheckPredicate, 3, // Predicate_store
/*2628*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2631*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*2635*/              OPC_MarkGlueResults, 1, 1, 
/*2638*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                      // Src: (st (sube:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (SBC8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2648*/            /*Scope*/ 29, /*->2678*/
/*2649*/              OPC_CheckType, MVT::i16,
/*2651*/              OPC_MoveParent,
/*2652*/              OPC_CheckChild2Same, 3,
/*2654*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2656*/              OPC_CheckPredicate, 3, // Predicate_store
/*2658*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2661*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*2665*/              OPC_MarkGlueResults, 1, 1, 
/*2668*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16mr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                      // Src: (st (sube:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (SBC16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2678*/            0, /*End of Scope*/
/*2679*/          0, /*End of Scope*/
/*2680*/        /*SwitchOpcode*/ 59|128,2/*315*/, TARGET_VAL(ISD::ADDC),// ->2999
/*2684*/          OPC_RecordNode, // #1 = 'addc' glue output node
/*2685*/          OPC_Scope, 106|128,1/*234*/, /*->2922*/ // 2 children in Scope
/*2688*/            OPC_MoveChild, 0,
/*2690*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2693*/            OPC_RecordMemRef,
/*2694*/            OPC_RecordNode, // #2 = 'ld' chained node
/*2695*/            OPC_CheckFoldableChainNode,
/*2696*/            OPC_RecordChild1, // #3 = $dst
/*2697*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2699*/            OPC_CheckPredicate, 1, // Predicate_load
/*2701*/            OPC_MoveParent,
/*2702*/            OPC_Scope, 26|128,1/*154*/, /*->2859*/ // 2 children in Scope
/*2705*/              OPC_MoveChild, 1,
/*2707*/              OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2710*/              OPC_RecordMemRef,
/*2711*/              OPC_RecordNode, // #4 = 'ld' chained node
/*2712*/              OPC_CheckFoldableChainNode,
/*2713*/              OPC_RecordChild1, // #5 = $src
/*2714*/              OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2716*/              OPC_CheckPredicate, 1, // Predicate_load
/*2718*/              OPC_MoveParent,
/*2719*/              OPC_SwitchType /*2 cases */, 67, MVT::i16,// ->2789
/*2722*/                OPC_MoveParent,
/*2723*/                OPC_Scope, 31, /*->2756*/ // 2 children in Scope
/*2725*/                  OPC_CheckChild2Same, 3,
/*2727*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2729*/                  OPC_CheckPredicate, 3, // Predicate_store
/*2731*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*2734*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*2737*/                  OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2742*/                  OPC_MarkGlueResults, 1, 1, 
/*2745*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                          // Src: (st (addc:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADD16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2756*/                /*Scope*/ 31, /*->2788*/
/*2757*/                  OPC_CheckChild2Same, 5,
/*2759*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2761*/                  OPC_CheckPredicate, 3, // Predicate_store
/*2763*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src #6 #7
/*2766*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$dst #8 #9
/*2769*/                  OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2774*/                  OPC_MarkGlueResults, 1, 1, 
/*2777*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 8, 9, 6, 7, 
                          // Src: (st (addc:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADD16mm:i16 addr:i16:$dst, addr:i16:$src)
/*2788*/                0, /*End of Scope*/
/*2789*/              /*SwitchType*/ 67, MVT::i8,// ->2858
/*2791*/                OPC_MoveParent,
/*2792*/                OPC_Scope, 31, /*->2825*/ // 2 children in Scope
/*2794*/                  OPC_CheckChild2Same, 3,
/*2796*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2798*/                  OPC_CheckPredicate, 3, // Predicate_store
/*2800*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*2803*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*2806*/                  OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2811*/                  OPC_MarkGlueResults, 1, 1, 
/*2814*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                          // Src: (st (addc:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADD8mm:i16 addr:i16:$dst, addr:i16:$src)
/*2825*/                /*Scope*/ 31, /*->2857*/
/*2826*/                  OPC_CheckChild2Same, 5,
/*2828*/                  OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2830*/                  OPC_CheckPredicate, 3, // Predicate_store
/*2832*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src #6 #7
/*2835*/                  OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$dst #8 #9
/*2838*/                  OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*2843*/                  OPC_MarkGlueResults, 1, 1, 
/*2846*/                  OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                              1/*#VTs*/, MVT::i16, 4/*#Ops*/, 8, 9, 6, 7, 
                          // Src: (st (addc:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                          // Dst: (ADD8mm:i16 addr:i16:$dst, addr:i16:$src)
/*2857*/                0, /*End of Scope*/
/*2858*/              0, // EndSwitchType
/*2859*/            /*Scope*/ 61, /*->2921*/
/*2860*/              OPC_RecordChild1, // #4 = $src
/*2861*/              OPC_SwitchType /*2 cases */, 27, MVT::i16,// ->2891
/*2864*/                OPC_MoveParent,
/*2865*/                OPC_CheckChild2Same, 3,
/*2867*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2869*/                OPC_CheckPredicate, 3, // Predicate_store
/*2871*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2874*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*2878*/                OPC_MarkGlueResults, 1, 1, 
/*2881*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                        // Src: (st (addc:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (ADD16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2891*/              /*SwitchType*/ 27, MVT::i8,// ->2920
/*2893*/                OPC_MoveParent,
/*2894*/                OPC_CheckChild2Same, 3,
/*2896*/                OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2898*/                OPC_CheckPredicate, 3, // Predicate_store
/*2900*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*2903*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*2907*/                OPC_MarkGlueResults, 1, 1, 
/*2910*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                        // Src: (st (addc:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                        // Dst: (ADD8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2920*/              0, // EndSwitchType
/*2921*/            0, /*End of Scope*/
/*2922*/          /*Scope*/ 75, /*->2998*/
/*2923*/            OPC_RecordChild0, // #2 = $src
/*2924*/            OPC_MoveChild, 1,
/*2926*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*2929*/            OPC_RecordMemRef,
/*2930*/            OPC_RecordNode, // #3 = 'ld' chained node
/*2931*/            OPC_CheckFoldableChainNode,
/*2932*/            OPC_RecordChild1, // #4 = $dst
/*2933*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*2935*/            OPC_CheckPredicate, 1, // Predicate_load
/*2937*/            OPC_MoveParent,
/*2938*/            OPC_SwitchType /*2 cases */, 27, MVT::i16,// ->2968
/*2941*/              OPC_MoveParent,
/*2942*/              OPC_CheckChild2Same, 4,
/*2944*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2946*/              OPC_CheckPredicate, 3, // Predicate_store
/*2948*/              OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #5 #6
/*2951*/              OPC_EmitMergeInputChains, 2, 0, 3, 
/*2955*/              OPC_MarkGlueResults, 1, 1, 
/*2958*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 2, 
                      // Src: (st (addc:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADD16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*2968*/            /*SwitchType*/ 27, MVT::i8,// ->2997
/*2970*/              OPC_MoveParent,
/*2971*/              OPC_CheckChild2Same, 4,
/*2973*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*2975*/              OPC_CheckPredicate, 3, // Predicate_store
/*2977*/              OPC_CheckComplexPat, /*CP*/0, /*#*/4, // SelectAddr:$dst #5 #6
/*2980*/              OPC_EmitMergeInputChains, 2, 0, 3, 
/*2984*/              OPC_MarkGlueResults, 1, 1, 
/*2987*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 2, 
                      // Src: (st (addc:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (ADD8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*2997*/            0, // EndSwitchType
/*2998*/          0, /*End of Scope*/
/*2999*/        /*SwitchOpcode*/ 36|128,1/*164*/, TARGET_VAL(ISD::SUBC),// ->3167
/*3003*/          OPC_RecordNode, // #1 = 'subc' glue output node
/*3004*/          OPC_MoveChild, 0,
/*3006*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3009*/          OPC_RecordMemRef,
/*3010*/          OPC_RecordNode, // #2 = 'ld' chained node
/*3011*/          OPC_CheckFoldableChainNode,
/*3012*/          OPC_RecordChild1, // #3 = $dst
/*3013*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3015*/          OPC_CheckPredicate, 1, // Predicate_load
/*3017*/          OPC_MoveParent,
/*3018*/          OPC_Scope, 84, /*->3104*/ // 2 children in Scope
/*3020*/            OPC_MoveChild, 1,
/*3022*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3025*/            OPC_RecordMemRef,
/*3026*/            OPC_RecordNode, // #4 = 'ld' chained node
/*3027*/            OPC_CheckFoldableChainNode,
/*3028*/            OPC_RecordChild1, // #5 = $src
/*3029*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3031*/            OPC_CheckPredicate, 1, // Predicate_load
/*3033*/            OPC_MoveParent,
/*3034*/            OPC_SwitchType /*2 cases */, 32, MVT::i16,// ->3069
/*3037*/              OPC_MoveParent,
/*3038*/              OPC_CheckChild2Same, 3,
/*3040*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3042*/              OPC_CheckPredicate, 3, // Predicate_store
/*3044*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*3047*/              OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*3050*/              OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*3055*/              OPC_MarkGlueResults, 1, 1, 
/*3058*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                      // Src: (st (subc:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                      // Dst: (SUB16mm:i16 addr:i16:$dst, addr:i16:$src)
/*3069*/            /*SwitchType*/ 32, MVT::i8,// ->3103
/*3071*/              OPC_MoveParent,
/*3072*/              OPC_CheckChild2Same, 3,
/*3074*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3076*/              OPC_CheckPredicate, 3, // Predicate_store
/*3078*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*3081*/              OPC_CheckComplexPat, /*CP*/0, /*#*/5, // SelectAddr:$src #8 #9
/*3084*/              OPC_EmitMergeInputChains, 3, 0, 2, 4, 
/*3089*/              OPC_MarkGlueResults, 1, 1, 
/*3092*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 4/*#Ops*/, 6, 7, 8, 9, 
                      // Src: (st (subc:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 42
                      // Dst: (SUB8mm:i16 addr:i16:$dst, addr:i16:$src)
/*3103*/            0, // EndSwitchType
/*3104*/          /*Scope*/ 61, /*->3166*/
/*3105*/            OPC_RecordChild1, // #4 = $src
/*3106*/            OPC_SwitchType /*2 cases */, 27, MVT::i16,// ->3136
/*3109*/              OPC_MoveParent,
/*3110*/              OPC_CheckChild2Same, 3,
/*3112*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3114*/              OPC_CheckPredicate, 3, // Predicate_store
/*3116*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*3119*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*3123*/              OPC_MarkGlueResults, 1, 1, 
/*3126*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                      // Src: (st (subc:i16 (ld:i16 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (SUB16mr:i16 addr:i16:$dst, GR16:i16:$src)
/*3136*/            /*SwitchType*/ 27, MVT::i8,// ->3165
/*3138*/              OPC_MoveParent,
/*3139*/              OPC_CheckChild2Same, 3,
/*3141*/              OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3143*/              OPC_CheckPredicate, 3, // Predicate_store
/*3145*/              OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #5 #6
/*3148*/              OPC_EmitMergeInputChains, 2, 0, 2, 
/*3152*/              OPC_MarkGlueResults, 1, 1, 
/*3155*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 5, 6, 4, 
                      // Src: (st (subc:i8 (ld:i8 addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 29
                      // Dst: (SUB8mr:i16 addr:i16:$dst, GR8:i8:$src)
/*3165*/            0, // EndSwitchType
/*3166*/          0, /*End of Scope*/
/*3167*/        /*SwitchOpcode*/ 66, TARGET_VAL(ISD::LOAD),// ->3236
/*3170*/          OPC_RecordMemRef,
/*3171*/          OPC_RecordNode, // #1 = 'ld' chained node
/*3172*/          OPC_CheckFoldableChainNode,
/*3173*/          OPC_RecordChild1, // #2 = $src
/*3174*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3176*/          OPC_CheckPredicate, 1, // Predicate_load
/*3178*/          OPC_SwitchType /*2 cases */, 26, MVT::i8,// ->3207
/*3181*/            OPC_MoveParent,
/*3182*/            OPC_RecordChild2, // #3 = $dst
/*3183*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3185*/            OPC_CheckPredicate, 3, // Predicate_store
/*3187*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #4 #5
/*3190*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*3193*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*3197*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8mm), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 6, 7, 4, 5, 
                    // Src: (st (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 26
                    // Dst: (MOV8mm addr:i16:$dst, addr:i16:$src)
/*3207*/          /*SwitchType*/ 26, MVT::i16,// ->3235
/*3209*/            OPC_MoveParent,
/*3210*/            OPC_RecordChild2, // #3 = $dst
/*3211*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3213*/            OPC_CheckPredicate, 3, // Predicate_store
/*3215*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src #4 #5
/*3218*/            OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$dst #6 #7
/*3221*/            OPC_EmitMergeInputChains, 2, 0, 1, 
/*3225*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mm), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 4/*#Ops*/, 6, 7, 4, 5, 
                    // Src: (st (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 26
                    // Dst: (MOV16mm addr:i16:$dst, addr:i16:$src)
/*3235*/          0, // EndSwitchType
/*3236*/        /*SwitchOpcode*/ 80, TARGET_VAL(MSP430ISD::Wrapper),// ->3319
/*3239*/          OPC_RecordChild0, // #1 = $src
/*3240*/          OPC_MoveChild, 0,
/*3242*/          OPC_SwitchOpcode /*3 cases */, 22, TARGET_VAL(ISD::TargetGlobalAddress),// ->3268
/*3246*/            OPC_MoveParent,
/*3247*/            OPC_CheckType, MVT::i16,
/*3249*/            OPC_MoveParent,
/*3250*/            OPC_RecordChild2, // #2 = $dst
/*3251*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3253*/            OPC_CheckPredicate, 3, // Predicate_store
/*3255*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3258*/            OPC_EmitMergeInputChains1_0,
/*3259*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mi), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                    // Src: (st (MSP430Wrapper:i16 (tglobaladdr:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 19
                    // Dst: (MOV16mi addr:i16:$dst, (tglobaladdr:i16):$src)
/*3268*/          /*SwitchOpcode*/ 22, TARGET_VAL(ISD::TargetExternalSymbol),// ->3293
/*3271*/            OPC_MoveParent,
/*3272*/            OPC_CheckType, MVT::i16,
/*3274*/            OPC_MoveParent,
/*3275*/            OPC_RecordChild2, // #2 = $dst
/*3276*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3278*/            OPC_CheckPredicate, 3, // Predicate_store
/*3280*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3283*/            OPC_EmitMergeInputChains1_0,
/*3284*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mi), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                    // Src: (st (MSP430Wrapper:i16 (texternalsym:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 19
                    // Dst: (MOV16mi addr:i16:$dst, (texternalsym:i16):$src)
/*3293*/          /*SwitchOpcode*/ 22, TARGET_VAL(ISD::TargetBlockAddress),// ->3318
/*3296*/            OPC_MoveParent,
/*3297*/            OPC_CheckType, MVT::i16,
/*3299*/            OPC_MoveParent,
/*3300*/            OPC_RecordChild2, // #2 = $dst
/*3301*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3303*/            OPC_CheckPredicate, 3, // Predicate_store
/*3305*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3308*/            OPC_EmitMergeInputChains1_0,
/*3309*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mi), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                    // Src: (st (MSP430Wrapper:i16 (tblockaddress:i16):$src), addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 19
                    // Dst: (MOV16mi addr:i16:$dst, (tblockaddress:i16):$src)
/*3318*/          0, // EndSwitchOpcode
/*3319*/        0, // EndSwitchOpcode
/*3320*/      /*Scope*/ 99, /*->3420*/
/*3321*/        OPC_RecordChild1, // #1 = $src
/*3322*/        OPC_Scope, 53, /*->3377*/ // 3 children in Scope
/*3324*/          OPC_MoveChild, 1,
/*3326*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3329*/          OPC_SwitchType /*2 cases */, 21, MVT::i8,// ->3353
/*3332*/            OPC_MoveParent,
/*3333*/            OPC_RecordChild2, // #2 = $dst
/*3334*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3336*/            OPC_CheckPredicate, 3, // Predicate_store
/*3338*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3341*/            OPC_EmitMergeInputChains1_0,
/*3342*/            OPC_EmitConvertToTarget, 1,
/*3344*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8mi), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 5, 
                    // Src: (st (imm:i8):$src, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                    // Dst: (MOV8mi addr:i16:$dst, (imm:i8):$src)
/*3353*/          /*SwitchType*/ 21, MVT::i16,// ->3376
/*3355*/            OPC_MoveParent,
/*3356*/            OPC_RecordChild2, // #2 = $dst
/*3357*/            OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3359*/            OPC_CheckPredicate, 3, // Predicate_store
/*3361*/            OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3364*/            OPC_EmitMergeInputChains1_0,
/*3365*/            OPC_EmitConvertToTarget, 1,
/*3367*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mi), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 3, 4, 5, 
                    // Src: (st (imm:i16):$src, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 16
                    // Dst: (MOV16mi addr:i16:$dst, (imm:i16):$src)
/*3376*/          0, // EndSwitchType
/*3377*/        /*Scope*/ 20, /*->3398*/
/*3378*/          OPC_CheckChild1Type, MVT::i8,
/*3380*/          OPC_RecordChild2, // #2 = $dst
/*3381*/          OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3383*/          OPC_CheckPredicate, 3, // Predicate_store
/*3385*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3388*/          OPC_EmitMergeInputChains1_0,
/*3389*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8mr), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st GR8:i8:$src, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (MOV8mr addr:i16:$dst, GR8:i8:$src)
/*3398*/        /*Scope*/ 20, /*->3419*/
/*3399*/          OPC_CheckChild1Type, MVT::i16,
/*3401*/          OPC_RecordChild2, // #2 = $dst
/*3402*/          OPC_CheckPredicate, 2, // Predicate_unindexedstore
/*3404*/          OPC_CheckPredicate, 3, // Predicate_store
/*3406*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*3409*/          OPC_EmitMergeInputChains1_0,
/*3410*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16mr), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 3, 4, 1, 
                  // Src: (st GR16:i16:$src, addr:iPTR:$dst)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                  // Dst: (MOV16mr addr:i16:$dst, GR16:i16:$src)
/*3419*/        0, /*End of Scope*/
/*3420*/      0, /*End of Scope*/
/*3421*/    /*SwitchOpcode*/ 23|128,5/*663*/, TARGET_VAL(MSP430ISD::CMP),// ->4088
/*3425*/      OPC_Scope, 78|128,2/*334*/, /*->3762*/ // 4 children in Scope
/*3428*/        OPC_MoveChild, 0,
/*3430*/        OPC_SwitchOpcode /*2 cases */, 5|128,2/*261*/, TARGET_VAL(ISD::AND),// ->3696
/*3435*/          OPC_Scope, 13|128,1/*141*/, /*->3579*/ // 3 children in Scope
/*3438*/            OPC_MoveChild, 0,
/*3440*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3443*/            OPC_RecordMemRef,
/*3444*/            OPC_RecordNode, // #0 = 'ld' chained node
/*3445*/            OPC_CheckFoldableChainNode,
/*3446*/            OPC_RecordChild1, // #1 = $src
/*3447*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3449*/            OPC_CheckPredicate, 1, // Predicate_load
/*3451*/            OPC_MoveParent,
/*3452*/            OPC_Scope, 70, /*->3524*/ // 2 children in Scope
/*3454*/              OPC_MoveChild, 1,
/*3456*/              OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3459*/              OPC_RecordMemRef,
/*3460*/              OPC_RecordNode, // #2 = 'ld' chained node
/*3461*/              OPC_CheckFoldableChainNode,
/*3462*/              OPC_RecordChild1, // #3 = $src2
/*3463*/              OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3465*/              OPC_CheckPredicate, 1, // Predicate_load
/*3467*/              OPC_MoveParent,
/*3468*/              OPC_CheckPredicate, 4, // Predicate_and_su
/*3470*/              OPC_SwitchType /*2 cases */, 24, MVT::i8,// ->3497
/*3473*/                OPC_MoveParent,
/*3474*/                OPC_CheckChild1Integer, 0, 
/*3476*/                OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #4 #5
/*3479*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src2 #6 #7
/*3482*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*3486*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 4, 5, 6, 7, 
                        // Src: (MSP430cmp (and:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>)<<P:Predicate_and_su>>, 0:i8) - Complexity = 38
                        // Dst: (BIT8mm:i16 addr:i16:$src, addr:i16:$src2)
/*3497*/              /*SwitchType*/ 24, MVT::i16,// ->3523
/*3499*/                OPC_MoveParent,
/*3500*/                OPC_CheckChild1Integer, 0, 
/*3502*/                OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #4 #5
/*3505*/                OPC_CheckComplexPat, /*CP*/0, /*#*/3, // SelectAddr:$src2 #6 #7
/*3508*/                OPC_EmitMergeInputChains, 2, 0, 2, 
/*3512*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16mm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 4/*#Ops*/, 4, 5, 6, 7, 
                        // Src: (MSP430cmp (and:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>)<<P:Predicate_and_su>>, 0:i16) - Complexity = 38
                        // Dst: (BIT16mm:i16 addr:i16:$src, addr:i16:$src2)
/*3523*/              0, // EndSwitchType
/*3524*/            /*Scope*/ 53, /*->3578*/
/*3525*/              OPC_RecordChild1, // #2 = $src2
/*3526*/              OPC_MoveChild, 1,
/*3528*/              OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3531*/              OPC_MoveParent,
/*3532*/              OPC_CheckPredicate, 4, // Predicate_and_su
/*3534*/              OPC_SwitchType /*2 cases */, 19, MVT::i8,// ->3556
/*3537*/                OPC_MoveParent,
/*3538*/                OPC_CheckChild1Integer, 0, 
/*3540*/                OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3543*/                OPC_EmitMergeInputChains1_0,
/*3544*/                OPC_EmitConvertToTarget, 2,
/*3546*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8mi), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 5, 
                        // Src: (MSP430cmp (and:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src2)<<P:Predicate_and_su>>, 0:i8) - Complexity = 28
                        // Dst: (BIT8mi:i16 addr:i16:$src, (imm:i8):$src2)
/*3556*/              /*SwitchType*/ 19, MVT::i16,// ->3577
/*3558*/                OPC_MoveParent,
/*3559*/                OPC_CheckChild1Integer, 0, 
/*3561*/                OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3564*/                OPC_EmitMergeInputChains1_0,
/*3565*/                OPC_EmitConvertToTarget, 2,
/*3567*/                OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16mi), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                            1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 5, 
                        // Src: (MSP430cmp (and:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src2)<<P:Predicate_and_su>>, 0:i16) - Complexity = 28
                        // Dst: (BIT16mi:i16 addr:i16:$src, (imm:i16):$src2)
/*3577*/              0, // EndSwitchType
/*3578*/            0, /*End of Scope*/
/*3579*/          /*Scope*/ 57, /*->3637*/
/*3580*/            OPC_RecordChild0, // #0 = $src
/*3581*/            OPC_MoveChild, 1,
/*3583*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3586*/            OPC_RecordMemRef,
/*3587*/            OPC_RecordNode, // #1 = 'ld' chained node
/*3588*/            OPC_CheckFoldableChainNode,
/*3589*/            OPC_RecordChild1, // #2 = $src2
/*3590*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3592*/            OPC_CheckPredicate, 1, // Predicate_load
/*3594*/            OPC_MoveParent,
/*3595*/            OPC_CheckPredicate, 4, // Predicate_and_su
/*3597*/            OPC_SwitchType /*2 cases */, 17, MVT::i8,// ->3617
/*3600*/              OPC_MoveParent,
/*3601*/              OPC_CheckChild1Integer, 0, 
/*3603*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*3606*/              OPC_EmitMergeInputChains1_1,
/*3607*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                      // Src: (MSP430cmp (and:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>)<<P:Predicate_and_su>>, 0:i8) - Complexity = 25
                      // Dst: (BIT8rm:i16 GR8:i8:$src, addr:i16:$src2)
/*3617*/            /*SwitchType*/ 17, MVT::i16,// ->3636
/*3619*/              OPC_MoveParent,
/*3620*/              OPC_CheckChild1Integer, 0, 
/*3622*/              OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*3625*/              OPC_EmitMergeInputChains1_1,
/*3626*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                      // Src: (MSP430cmp (and:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>)<<P:Predicate_and_su>>, 0:i16) - Complexity = 25
                      // Dst: (BIT16rm:i16 GR16:i16:$src, addr:i16:$src2)
/*3636*/            0, // EndSwitchType
/*3637*/          /*Scope*/ 57, /*->3695*/
/*3638*/            OPC_MoveChild, 0,
/*3640*/            OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3643*/            OPC_RecordMemRef,
/*3644*/            OPC_RecordNode, // #0 = 'ld' chained node
/*3645*/            OPC_CheckFoldableChainNode,
/*3646*/            OPC_RecordChild1, // #1 = $src
/*3647*/            OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3649*/            OPC_CheckPredicate, 1, // Predicate_load
/*3651*/            OPC_MoveParent,
/*3652*/            OPC_RecordChild1, // #2 = $src2
/*3653*/            OPC_CheckPredicate, 4, // Predicate_and_su
/*3655*/            OPC_SwitchType /*2 cases */, 17, MVT::i8,// ->3675
/*3658*/              OPC_MoveParent,
/*3659*/              OPC_CheckChild1Integer, 0, 
/*3661*/              OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3664*/              OPC_EmitMergeInputChains1_0,
/*3665*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 2, 
                      // Src: (MSP430cmp (and:i8 (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src2)<<P:Predicate_and_su>>, 0:i8) - Complexity = 25
                      // Dst: (BIT8mr:i16 addr:i16:$src, GR8:i8:$src2)
/*3675*/            /*SwitchType*/ 17, MVT::i16,// ->3694
/*3677*/              OPC_MoveParent,
/*3678*/              OPC_CheckChild1Integer, 0, 
/*3680*/              OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3683*/              OPC_EmitMergeInputChains1_0,
/*3684*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 2, 
                      // Src: (MSP430cmp (and:i16 (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src2)<<P:Predicate_and_su>>, 0:i16) - Complexity = 25
                      // Dst: (BIT16mr:i16 addr:i16:$src, GR16:i16:$src2)
/*3694*/            0, // EndSwitchType
/*3695*/          0, /*End of Scope*/
/*3696*/        /*SwitchOpcode*/ 62, TARGET_VAL(ISD::LOAD),// ->3761
/*3699*/          OPC_RecordMemRef,
/*3700*/          OPC_RecordNode, // #0 = 'ld' chained node
/*3701*/          OPC_CheckFoldableChainNode,
/*3702*/          OPC_RecordChild1, // #1 = $src
/*3703*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3705*/          OPC_CheckPredicate, 1, // Predicate_load
/*3707*/          OPC_SwitchType /*2 cases */, 24, MVT::i8,// ->3734
/*3710*/            OPC_MoveParent,
/*3711*/            OPC_RecordChild1, // #2 = $src2
/*3712*/            OPC_MoveChild, 1,
/*3714*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3717*/            OPC_MoveParent,
/*3718*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3721*/            OPC_EmitMergeInputChains1_0,
/*3722*/            OPC_EmitConvertToTarget, 2,
/*3724*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8mi), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 5, 
                    // Src: (MSP430cmp (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i8):$src2) - Complexity = 19
                    // Dst: (CMP8mi:i16 addr:i16:$src, (imm:i8):$src2)
/*3734*/          /*SwitchType*/ 24, MVT::i16,// ->3760
/*3736*/            OPC_MoveParent,
/*3737*/            OPC_RecordChild1, // #2 = $src2
/*3738*/            OPC_MoveChild, 1,
/*3740*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3743*/            OPC_MoveParent,
/*3744*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3747*/            OPC_EmitMergeInputChains1_0,
/*3748*/            OPC_EmitConvertToTarget, 2,
/*3750*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16mi), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 5, 
                    // Src: (MSP430cmp (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, (imm:i16):$src2) - Complexity = 19
                    // Dst: (CMP16mi:i16 addr:i16:$src, (imm:i16):$src2)
/*3760*/          0, // EndSwitchType
/*3761*/        0, // EndSwitchOpcode
/*3762*/      /*Scope*/ 65, /*->3828*/
/*3763*/        OPC_RecordChild0, // #0 = $src
/*3764*/        OPC_Scope, 30, /*->3796*/ // 2 children in Scope
/*3766*/          OPC_CheckChild0Type, MVT::i8,
/*3768*/          OPC_MoveChild, 1,
/*3770*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3773*/          OPC_RecordMemRef,
/*3774*/          OPC_RecordNode, // #1 = 'ld' chained node
/*3775*/          OPC_CheckFoldableChainNode,
/*3776*/          OPC_RecordChild1, // #2 = $src2
/*3777*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3779*/          OPC_CheckPredicate, 1, // Predicate_load
/*3781*/          OPC_MoveParent,
/*3782*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*3785*/          OPC_EmitMergeInputChains1_1,
/*3786*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (MSP430cmp GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (CMP8rm:i16 GR8:i8:$src, addr:i16:$src2)
/*3796*/        /*Scope*/ 30, /*->3827*/
/*3797*/          OPC_CheckChild0Type, MVT::i16,
/*3799*/          OPC_MoveChild, 1,
/*3801*/          OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*3804*/          OPC_RecordMemRef,
/*3805*/          OPC_RecordNode, // #1 = 'ld' chained node
/*3806*/          OPC_CheckFoldableChainNode,
/*3807*/          OPC_RecordChild1, // #2 = $src2
/*3808*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3810*/          OPC_CheckPredicate, 1, // Predicate_load
/*3812*/          OPC_MoveParent,
/*3813*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*3816*/          OPC_EmitMergeInputChains1_1,
/*3817*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (MSP430cmp GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (CMP16rm:i16 GR16:i16:$src, addr:i16:$src2)
/*3827*/        0, /*End of Scope*/
/*3828*/      /*Scope*/ 57|128,1/*185*/, /*->4015*/
/*3830*/        OPC_MoveChild, 0,
/*3832*/        OPC_SwitchOpcode /*3 cases */, 46, TARGET_VAL(ISD::LOAD),// ->3882
/*3836*/          OPC_RecordMemRef,
/*3837*/          OPC_RecordNode, // #0 = 'ld' chained node
/*3838*/          OPC_CheckFoldableChainNode,
/*3839*/          OPC_RecordChild1, // #1 = $src
/*3840*/          OPC_CheckPredicate, 0, // Predicate_unindexedload
/*3842*/          OPC_CheckPredicate, 1, // Predicate_load
/*3844*/          OPC_SwitchType /*2 cases */, 16, MVT::i8,// ->3863
/*3847*/            OPC_MoveParent,
/*3848*/            OPC_RecordChild1, // #2 = $src2
/*3849*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3852*/            OPC_EmitMergeInputChains1_0,
/*3853*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 2, 
                    // Src: (MSP430cmp (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src2) - Complexity = 16
                    // Dst: (CMP8mr:i16 addr:i16:$src, GR8:i8:$src2)
/*3863*/          /*SwitchType*/ 16, MVT::i16,// ->3881
/*3865*/            OPC_MoveParent,
/*3866*/            OPC_RecordChild1, // #2 = $src2
/*3867*/            OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #3 #4
/*3870*/            OPC_EmitMergeInputChains1_0,
/*3871*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16mr), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i16, 3/*#Ops*/, 3, 4, 2, 
                    // Src: (MSP430cmp (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src2) - Complexity = 16
                    // Dst: (CMP16mr:i16 addr:i16:$src, GR16:i16:$src2)
/*3881*/          0, // EndSwitchType
/*3882*/        /*SwitchOpcode*/ 80, TARGET_VAL(ISD::AND),// ->3965
/*3885*/          OPC_RecordChild0, // #0 = $src
/*3886*/          OPC_RecordChild1, // #1 = $src2
/*3887*/          OPC_Scope, 42, /*->3931*/ // 2 children in Scope
/*3889*/            OPC_MoveChild, 1,
/*3891*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3894*/            OPC_MoveParent,
/*3895*/            OPC_CheckPredicate, 4, // Predicate_and_su
/*3897*/            OPC_SwitchType /*2 cases */, 14, MVT::i8,// ->3914
/*3900*/              OPC_MoveParent,
/*3901*/              OPC_CheckChild1Integer, 0, 
/*3903*/              OPC_EmitConvertToTarget, 1,
/*3905*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8ri), 0|OPFL_GlueOutput,
                          1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 2, 
                      // Src: (MSP430cmp (and:i8 GR8:i8:$src, (imm:i8):$src2)<<P:Predicate_and_su>>, 0:i8) - Complexity = 15
                      // Dst: (BIT8ri:i16 GR8:i8:$src, (imm:i8):$src2)
/*3914*/            /*SwitchType*/ 14, MVT::i16,// ->3930
/*3916*/              OPC_MoveParent,
/*3917*/              OPC_CheckChild1Integer, 0, 
/*3919*/              OPC_EmitConvertToTarget, 1,
/*3921*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16ri), 0|OPFL_GlueOutput,
                          1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 2, 
                      // Src: (MSP430cmp (and:i16 GR16:i16:$src, (imm:i16):$src2)<<P:Predicate_and_su>>, 0:i16) - Complexity = 15
                      // Dst: (BIT16ri:i16 GR16:i16:$src, (imm:i16):$src2)
/*3930*/            0, // EndSwitchType
/*3931*/          /*Scope*/ 32, /*->3964*/
/*3932*/            OPC_CheckPredicate, 4, // Predicate_and_su
/*3934*/            OPC_SwitchType /*2 cases */, 12, MVT::i8,// ->3949
/*3937*/              OPC_MoveParent,
/*3938*/              OPC_CheckChild1Integer, 0, 
/*3940*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8rr), 0|OPFL_GlueOutput,
                          1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 1, 
                      // Src: (MSP430cmp (and:i8 GR8:i8:$src, GR8:i8:$src2)<<P:Predicate_and_su>>, 0:i8) - Complexity = 12
                      // Dst: (BIT8rr:i16 GR8:i8:$src, GR8:i8:$src2)
/*3949*/            /*SwitchType*/ 12, MVT::i16,// ->3963
/*3951*/              OPC_MoveParent,
/*3952*/              OPC_CheckChild1Integer, 0, 
/*3954*/              OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT16rr), 0|OPFL_GlueOutput,
                          1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 1, 
                      // Src: (MSP430cmp (and:i16 GR16:i16:$src, GR16:i16:$src2)<<P:Predicate_and_su>>, 0:i16) - Complexity = 12
                      // Dst: (BIT16rr:i16 GR16:i16:$src, GR16:i16:$src2)
/*3963*/            0, // EndSwitchType
/*3964*/          0, /*End of Scope*/
/*3965*/        /*SwitchOpcode*/ 46, TARGET_VAL(ISD::TRUNCATE),// ->4014
/*3968*/          OPC_MoveChild, 0,
/*3970*/          OPC_CheckOpcode, TARGET_VAL(ISD::AND),
/*3973*/          OPC_RecordChild0, // #0 = $src
/*3974*/          OPC_RecordChild1, // #1 = $src2
/*3975*/          OPC_CheckPredicate, 4, // Predicate_and_su
/*3977*/          OPC_MoveParent,
/*3978*/          OPC_MoveParent,
/*3979*/          OPC_CheckChild1Integer, 0, 
/*3981*/          OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*3984*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i8, 2/*#Ops*/, 0, 2,  // Results = #3
/*3993*/          OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*3996*/          OPC_EmitNode, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                      1/*#VTs*/, MVT::i8, 2/*#Ops*/, 1, 4,  // Results = #5
/*4005*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::BIT8rr), 0|OPFL_GlueOutput,
                      1/*#VTs*/, MVT::i16, 2/*#Ops*/, 3, 5, 
                  // Src: (MSP430cmp (trunc:i8 (and:i16 GR16:i16:$src, GR16:i16:$src2)<<P:Predicate_and_su>>), 0:i8) - Complexity = 15
                  // Dst: (BIT8rr:i16 (EXTRACT_SUBREG:i8 GR16:i16:$src, subreg_8bit:i32), (EXTRACT_SUBREG:i8 GR16:i16:$src2, subreg_8bit:i32))
/*4014*/        0, // EndSwitchOpcode
/*4015*/      /*Scope*/ 71, /*->4087*/
/*4016*/        OPC_RecordChild0, // #0 = $src
/*4017*/        OPC_Scope, 33, /*->4052*/ // 2 children in Scope
/*4019*/          OPC_CheckChild0Type, MVT::i8,
/*4021*/          OPC_RecordChild1, // #1 = $src2
/*4022*/          OPC_Scope, 17, /*->4041*/ // 2 children in Scope
/*4024*/            OPC_MoveChild, 1,
/*4026*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4029*/            OPC_MoveParent,
/*4030*/            OPC_EmitConvertToTarget, 1,
/*4032*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8ri), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (MSP430cmp GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (CMP8ri:i16 GR8:i8:$src, (imm:i8):$src2)
/*4041*/          /*Scope*/ 9, /*->4051*/
/*4042*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP8rr), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 1, 
                    // Src: (MSP430cmp GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                    // Dst: (CMP8rr:i16 GR8:i8:$src, GR8:i8:$src2)
/*4051*/          0, /*End of Scope*/
/*4052*/        /*Scope*/ 33, /*->4086*/
/*4053*/          OPC_CheckChild0Type, MVT::i16,
/*4055*/          OPC_RecordChild1, // #1 = $src2
/*4056*/          OPC_Scope, 17, /*->4075*/ // 2 children in Scope
/*4058*/            OPC_MoveChild, 1,
/*4060*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4063*/            OPC_MoveParent,
/*4064*/            OPC_EmitConvertToTarget, 1,
/*4066*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16ri), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (MSP430cmp GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (CMP16ri:i16 GR16:i16:$src, (imm:i16):$src2)
/*4075*/          /*Scope*/ 9, /*->4085*/
/*4076*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CMP16rr), 0|OPFL_GlueOutput,
                        1/*#VTs*/, MVT::i16, 2/*#Ops*/, 0, 1, 
                    // Src: (MSP430cmp GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                    // Dst: (CMP16rr:i16 GR16:i16:$src, GR16:i16:$src2)
/*4085*/          0, /*End of Scope*/
/*4086*/        0, /*End of Scope*/
/*4087*/      0, /*End of Scope*/
/*4088*/    /*SwitchOpcode*/ 35|128,3/*419*/, TARGET_VAL(ISD::AND),// ->4511
/*4092*/      OPC_Scope, 68, /*->4162*/ // 8 children in Scope
/*4094*/        OPC_RecordChild0, // #0 = $src
/*4095*/        OPC_MoveChild, 1,
/*4097*/        OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4100*/        OPC_MoveChild, 0,
/*4102*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4105*/        OPC_RecordMemRef,
/*4106*/        OPC_RecordNode, // #1 = 'ld' chained node
/*4107*/        OPC_CheckFoldableChainNode,
/*4108*/        OPC_RecordChild1, // #2 = $src2
/*4109*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4111*/        OPC_CheckPredicate, 1, // Predicate_load
/*4113*/        OPC_MoveParent,
/*4114*/        OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4125*/        OPC_MoveParent,
/*4126*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->4144
/*4129*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4132*/          OPC_EmitMergeInputChains1_1,
/*4133*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (and:i8 GR8:i8:$src, (xor:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i8)) - Complexity = 24
                  // Dst: (BIC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4144*/        /*SwitchType*/ 15, MVT::i16,// ->4161
/*4146*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4149*/          OPC_EmitMergeInputChains1_1,
/*4150*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (and:i16 GR16:i16:$src, (xor:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i16)) - Complexity = 24
                  // Dst: (BIC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4161*/        0, // EndSwitchType
/*4162*/      /*Scope*/ 68, /*->4231*/
/*4163*/        OPC_MoveChild, 0,
/*4165*/        OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4168*/        OPC_MoveChild, 0,
/*4170*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4173*/        OPC_RecordMemRef,
/*4174*/        OPC_RecordNode, // #0 = 'ld' chained node
/*4175*/        OPC_CheckFoldableChainNode,
/*4176*/        OPC_RecordChild1, // #1 = $src2
/*4177*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4179*/        OPC_CheckPredicate, 1, // Predicate_load
/*4181*/        OPC_MoveParent,
/*4182*/        OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4193*/        OPC_MoveParent,
/*4194*/        OPC_RecordChild1, // #2 = $src
/*4195*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->4213
/*4198*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4201*/          OPC_EmitMergeInputChains1_0,
/*4202*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (and:i8 (xor:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i8), GR8:i8:$src) - Complexity = 24
                  // Dst: (BIC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4213*/        /*SwitchType*/ 15, MVT::i16,// ->4230
/*4215*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4218*/          OPC_EmitMergeInputChains1_0,
/*4219*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (and:i16 (xor:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, -1:i16), GR16:i16:$src) - Complexity = 24
                  // Dst: (BIC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4230*/        0, // EndSwitchType
/*4231*/      /*Scope*/ 51, /*->4283*/
/*4232*/        OPC_RecordChild0, // #0 = $src
/*4233*/        OPC_MoveChild, 1,
/*4235*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4238*/        OPC_RecordMemRef,
/*4239*/        OPC_RecordNode, // #1 = 'ld' chained node
/*4240*/        OPC_CheckFoldableChainNode,
/*4241*/        OPC_RecordChild1, // #2 = $src2
/*4242*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4244*/        OPC_CheckPredicate, 1, // Predicate_load
/*4246*/        OPC_MoveParent,
/*4247*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->4265
/*4250*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4253*/          OPC_EmitMergeInputChains1_1,
/*4254*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (and:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (AND8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4265*/        /*SwitchType*/ 15, MVT::i16,// ->4282
/*4267*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4270*/          OPC_EmitMergeInputChains1_1,
/*4271*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (and:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (AND16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4282*/        0, // EndSwitchType
/*4283*/      /*Scope*/ 51, /*->4335*/
/*4284*/        OPC_MoveChild, 0,
/*4286*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4289*/        OPC_RecordMemRef,
/*4290*/        OPC_RecordNode, // #0 = 'ld' chained node
/*4291*/        OPC_CheckFoldableChainNode,
/*4292*/        OPC_RecordChild1, // #1 = $src2
/*4293*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4295*/        OPC_CheckPredicate, 1, // Predicate_load
/*4297*/        OPC_MoveParent,
/*4298*/        OPC_RecordChild1, // #2 = $src
/*4299*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->4317
/*4302*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4305*/          OPC_EmitMergeInputChains1_0,
/*4306*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (and:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                  // Dst: (AND8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4317*/        /*SwitchType*/ 15, MVT::i16,// ->4334
/*4319*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4322*/          OPC_EmitMergeInputChains1_0,
/*4323*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (and:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                  // Dst: (AND16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4334*/        0, // EndSwitchType
/*4335*/      /*Scope*/ 45, /*->4381*/
/*4336*/        OPC_RecordChild0, // #0 = $src
/*4337*/        OPC_MoveChild, 1,
/*4339*/        OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4342*/        OPC_RecordChild0, // #1 = $src2
/*4343*/        OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4354*/        OPC_MoveParent,
/*4355*/        OPC_SwitchType /*2 cases */, 10, MVT::i8,// ->4368
/*4358*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8rr), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (and:i8 GR8:i8:$src, (xor:i8 GR8:i8:$src2, -1:i8)) - Complexity = 11
                  // Dst: (BIC8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*4368*/        /*SwitchType*/ 10, MVT::i16,// ->4380
/*4370*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16rr), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (and:i16 GR16:i16:$src, (xor:i16 GR16:i16:$src2, -1:i16)) - Complexity = 11
                  // Dst: (BIC16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*4380*/        0, // EndSwitchType
/*4381*/      /*Scope*/ 45, /*->4427*/
/*4382*/        OPC_MoveChild, 0,
/*4384*/        OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*4387*/        OPC_RecordChild0, // #0 = $src2
/*4388*/        OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*4399*/        OPC_MoveParent,
/*4400*/        OPC_RecordChild1, // #1 = $src
/*4401*/        OPC_SwitchType /*2 cases */, 10, MVT::i8,// ->4414
/*4404*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC8rr), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 1, 0, 
                  // Src: (and:i8 (xor:i8 GR8:i8:$src2, -1:i8), GR8:i8:$src) - Complexity = 11
                  // Dst: (BIC8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*4414*/        /*SwitchType*/ 10, MVT::i16,// ->4426
/*4416*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::BIC16rr), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 1, 0, 
                  // Src: (and:i16 (xor:i16 GR16:i16:$src2, -1:i16), GR16:i16:$src) - Complexity = 11
                  // Dst: (BIC16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*4426*/        0, // EndSwitchType
/*4427*/      /*Scope*/ 14, /*->4442*/
/*4428*/        OPC_CheckAndImm, 127|128,1/*255*/, 
/*4431*/        OPC_RecordChild0, // #0 = $src
/*4432*/        OPC_CheckType, MVT::i16,
/*4434*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ZEXT16r), 0,
                    1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (and:i16 GR16:i16:$src, 255:i16) - Complexity = 8
                // Dst: (ZEXT16r:i16 GR16:i16:$src)
/*4442*/      /*Scope*/ 67, /*->4510*/
/*4443*/        OPC_RecordChild0, // #0 = $src
/*4444*/        OPC_RecordChild1, // #1 = $src2
/*4445*/        OPC_Scope, 36, /*->4483*/ // 3 children in Scope
/*4447*/          OPC_MoveChild, 1,
/*4449*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4452*/          OPC_MoveParent,
/*4453*/          OPC_SwitchType /*2 cases */, 12, MVT::i8,// ->4468
/*4456*/            OPC_EmitConvertToTarget, 1,
/*4458*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8ri), 0,
                        2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (and:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (AND8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*4468*/          /*SwitchType*/ 12, MVT::i16,// ->4482
/*4470*/            OPC_EmitConvertToTarget, 1,
/*4472*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16ri), 0,
                        2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (and:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (AND16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*4482*/          0, // EndSwitchType
/*4483*/        /*Scope*/ 12, /*->4496*/
/*4484*/          OPC_CheckType, MVT::i8,
/*4486*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::AND8rr), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (and:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (AND8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*4496*/        /*Scope*/ 12, /*->4509*/
/*4497*/          OPC_CheckType, MVT::i16,
/*4499*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::AND16rr), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (and:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (AND16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*4509*/        0, /*End of Scope*/
/*4510*/      0, /*End of Scope*/
/*4511*/    /*SwitchOpcode*/ 63, TARGET_VAL(ISD::BRIND),// ->4577
/*4514*/      OPC_RecordNode, // #0 = 'brind' chained node
/*4515*/      OPC_Scope, 29, /*->4546*/ // 2 children in Scope
/*4517*/        OPC_MoveChild, 1,
/*4519*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4522*/        OPC_RecordMemRef,
/*4523*/        OPC_RecordNode, // #1 = 'ld' chained node
/*4524*/        OPC_CheckFoldableChainNode,
/*4525*/        OPC_RecordChild1, // #2 = $brdst
/*4526*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4528*/        OPC_CheckPredicate, 1, // Predicate_load
/*4530*/        OPC_MoveParent,
/*4531*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$brdst #3 #4
/*4534*/        OPC_EmitMergeInputChains, 2, 0, 1, 
/*4538*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Bm), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 2/*#Ops*/, 3, 4, 
                // Src: (brind (ld:iPTR addr:iPTR:$brdst)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (Bm addr:i16:$brdst)
/*4546*/      /*Scope*/ 29, /*->4576*/
/*4547*/        OPC_RecordChild1, // #1 = $brdst
/*4548*/        OPC_Scope, 14, /*->4564*/ // 2 children in Scope
/*4550*/          OPC_MoveChild, 1,
/*4552*/          OPC_CheckOpcode, TARGET_VAL(ISD::TargetBlockAddress),
/*4555*/          OPC_MoveParent,
/*4556*/          OPC_EmitMergeInputChains1_0,
/*4557*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::Bi), 0|OPFL_Chain,
                      0/*#VTs*/, 1/*#Ops*/, 1, 
                  // Src: (brind (tblockaddress:iPTR):$brdst) - Complexity = 6
                  // Dst: (Bi (tblockaddress:i16):$brdst)
/*4564*/        /*Scope*/ 10, /*->4575*/
/*4565*/          OPC_CheckChild1Type, MVT::i16,
/*4567*/          OPC_EmitMergeInputChains1_0,
/*4568*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::Br), 0|OPFL_Chain,
                      0/*#VTs*/, 1/*#Ops*/, 1, 
                  // Src: (brind GR16:i16:$brdst) - Complexity = 3
                  // Dst: (Br GR16:i16:$brdst)
/*4575*/        0, /*End of Scope*/
/*4576*/      0, /*End of Scope*/
/*4577*/    /*SwitchOpcode*/ 101, TARGET_VAL(MSP430ISD::CALL),// ->4681
/*4580*/      OPC_RecordNode, // #0 = 'MSP430call' chained node
/*4581*/      OPC_CaptureGlueInput,
/*4582*/      OPC_Scope, 30, /*->4614*/ // 2 children in Scope
/*4584*/        OPC_MoveChild, 1,
/*4586*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4589*/        OPC_RecordMemRef,
/*4590*/        OPC_RecordNode, // #1 = 'ld' chained node
/*4591*/        OPC_CheckFoldableChainNode,
/*4592*/        OPC_RecordChild1, // #2 = $dst
/*4593*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4595*/        OPC_CheckPredicate, 1, // Predicate_load
/*4597*/        OPC_MoveParent,
/*4598*/        OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$dst #3 #4
/*4601*/        OPC_EmitMergeInputChains, 2, 0, 1, 
/*4605*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs|OPFL_Variadic1,
                    1/*#VTs*/, MVT::i16, 2/*#Ops*/, 3, 4, 
                // Src: (MSP430call (ld:iPTR addr:iPTR:$dst)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                // Dst: (CALLm:i16 addr:i16:$dst)
/*4614*/      /*Scope*/ 65, /*->4680*/
/*4615*/        OPC_RecordChild1, // #1 = $dst
/*4616*/        OPC_Scope, 49, /*->4667*/ // 2 children in Scope
/*4618*/          OPC_MoveChild, 1,
/*4620*/          OPC_SwitchOpcode /*3 cases */, 12, TARGET_VAL(ISD::Constant),// ->4636
/*4624*/            OPC_MoveParent,
/*4625*/            OPC_EmitMergeInputChains1_0,
/*4626*/            OPC_EmitConvertToTarget, 1,
/*4628*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                        1/*#VTs*/, MVT::i16, 1/*#Ops*/, 2, 
                    // Src: (MSP430call (imm:iPTR):$dst) - Complexity = 6
                    // Dst: (CALLi:i16 (imm:i16):$dst)
/*4636*/          /*SwitchOpcode*/ 12, TARGET_VAL(ISD::TargetGlobalAddress),// ->4651
/*4639*/            OPC_CheckType, MVT::i16,
/*4641*/            OPC_MoveParent,
/*4642*/            OPC_EmitMergeInputChains1_0,
/*4643*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                        1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
                    // Src: (MSP430call (tglobaladdr:i16):$dst) - Complexity = 6
                    // Dst: (CALLi:i16 (tglobaladdr:i16):$dst)
/*4651*/          /*SwitchOpcode*/ 12, TARGET_VAL(ISD::TargetExternalSymbol),// ->4666
/*4654*/            OPC_CheckType, MVT::i16,
/*4656*/            OPC_MoveParent,
/*4657*/            OPC_EmitMergeInputChains1_0,
/*4658*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLi), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                        1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
                    // Src: (MSP430call (texternalsym:i16):$dst) - Complexity = 6
                    // Dst: (CALLi:i16 (texternalsym:i16):$dst)
/*4666*/          0, // EndSwitchOpcode
/*4667*/        /*Scope*/ 11, /*->4679*/
/*4668*/          OPC_CheckChild1Type, MVT::i16,
/*4670*/          OPC_EmitMergeInputChains1_0,
/*4671*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::CALLr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                      1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
                  // Src: (MSP430call GR16:i16:$dst) - Complexity = 3
                  // Dst: (CALLr:i16 GR16:i16:$dst)
/*4679*/        0, /*End of Scope*/
/*4680*/      0, /*End of Scope*/
/*4681*/    /*SwitchOpcode*/ 46|128,2/*302*/, TARGET_VAL(ISD::ADD),// ->4987
/*4685*/      OPC_Scope, 51, /*->4738*/ // 5 children in Scope
/*4687*/        OPC_RecordChild0, // #0 = $src
/*4688*/        OPC_MoveChild, 1,
/*4690*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4693*/        OPC_RecordMemRef,
/*4694*/        OPC_RecordNode, // #1 = 'ld' chained node
/*4695*/        OPC_CheckFoldableChainNode,
/*4696*/        OPC_RecordChild1, // #2 = $src2
/*4697*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4699*/        OPC_CheckPredicate, 1, // Predicate_load
/*4701*/        OPC_MoveParent,
/*4702*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->4720
/*4705*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4708*/          OPC_EmitMergeInputChains1_1,
/*4709*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (add:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (ADD8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4720*/        /*SwitchType*/ 15, MVT::i16,// ->4737
/*4722*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*4725*/          OPC_EmitMergeInputChains1_1,
/*4726*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (add:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (ADD16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4737*/        0, // EndSwitchType
/*4738*/      /*Scope*/ 51, /*->4790*/
/*4739*/        OPC_MoveChild, 0,
/*4741*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*4744*/        OPC_RecordMemRef,
/*4745*/        OPC_RecordNode, // #0 = 'ld' chained node
/*4746*/        OPC_CheckFoldableChainNode,
/*4747*/        OPC_RecordChild1, // #1 = $src2
/*4748*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*4750*/        OPC_CheckPredicate, 1, // Predicate_load
/*4752*/        OPC_MoveParent,
/*4753*/        OPC_RecordChild1, // #2 = $src
/*4754*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->4772
/*4757*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4760*/          OPC_EmitMergeInputChains1_0,
/*4761*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (add:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                  // Dst: (ADD8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*4772*/        /*SwitchType*/ 15, MVT::i16,// ->4789
/*4774*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*4777*/          OPC_EmitMergeInputChains1_0,
/*4778*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (add:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                  // Dst: (ADD16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*4789*/        0, // EndSwitchType
/*4790*/      /*Scope*/ 62, /*->4853*/
/*4791*/        OPC_RecordChild0, // #0 = $src
/*4792*/        OPC_MoveChild, 1,
/*4794*/        OPC_CheckOpcode, TARGET_VAL(MSP430ISD::Wrapper),
/*4797*/        OPC_RecordChild0, // #1 = $src2
/*4798*/        OPC_MoveChild, 0,
/*4800*/        OPC_SwitchOpcode /*3 cases */, 14, TARGET_VAL(ISD::TargetGlobalAddress),// ->4818
/*4804*/          OPC_MoveParent,
/*4805*/          OPC_MoveParent,
/*4806*/          OPC_CheckType, MVT::i16,
/*4808*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i16 GR16:i16:$src, (MSP430Wrapper:i16 (tglobaladdr:i16):$src2)) - Complexity = 9
                  // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (tglobaladdr:i16):$src2)
/*4818*/        /*SwitchOpcode*/ 14, TARGET_VAL(ISD::TargetExternalSymbol),// ->4835
/*4821*/          OPC_MoveParent,
/*4822*/          OPC_MoveParent,
/*4823*/          OPC_CheckType, MVT::i16,
/*4825*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i16 GR16:i16:$src, (MSP430Wrapper:i16 (texternalsym:i16):$src2)) - Complexity = 9
                  // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (texternalsym:i16):$src2)
/*4835*/        /*SwitchOpcode*/ 14, TARGET_VAL(ISD::TargetBlockAddress),// ->4852
/*4838*/          OPC_MoveParent,
/*4839*/          OPC_MoveParent,
/*4840*/          OPC_CheckType, MVT::i16,
/*4842*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i16 GR16:i16:$src, (MSP430Wrapper:i16 (tblockaddress:i16):$src2)) - Complexity = 9
                  // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (tblockaddress:i16):$src2)
/*4852*/        0, // EndSwitchOpcode
/*4853*/      /*Scope*/ 64, /*->4918*/
/*4854*/        OPC_MoveChild, 0,
/*4856*/        OPC_CheckOpcode, TARGET_VAL(MSP430ISD::Wrapper),
/*4859*/        OPC_RecordChild0, // #0 = $src2
/*4860*/        OPC_MoveChild, 0,
/*4862*/        OPC_SwitchOpcode /*3 cases */, 15, TARGET_VAL(ISD::TargetGlobalAddress),// ->4881
/*4866*/          OPC_MoveParent,
/*4867*/          OPC_MoveParent,
/*4868*/          OPC_RecordChild1, // #1 = $src
/*4869*/          OPC_CheckType, MVT::i16,
/*4871*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 1, 0, 
                  // Src: (add:i16 (MSP430Wrapper:i16 (tglobaladdr:i16):$src2), GR16:i16:$src) - Complexity = 9
                  // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (tglobaladdr:i16):$src2)
/*4881*/        /*SwitchOpcode*/ 15, TARGET_VAL(ISD::TargetExternalSymbol),// ->4899
/*4884*/          OPC_MoveParent,
/*4885*/          OPC_MoveParent,
/*4886*/          OPC_RecordChild1, // #1 = $src
/*4887*/          OPC_CheckType, MVT::i16,
/*4889*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 1, 0, 
                  // Src: (add:i16 (MSP430Wrapper:i16 (texternalsym:i16):$src2), GR16:i16:$src) - Complexity = 9
                  // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (texternalsym:i16):$src2)
/*4899*/        /*SwitchOpcode*/ 15, TARGET_VAL(ISD::TargetBlockAddress),// ->4917
/*4902*/          OPC_MoveParent,
/*4903*/          OPC_MoveParent,
/*4904*/          OPC_RecordChild1, // #1 = $src
/*4905*/          OPC_CheckType, MVT::i16,
/*4907*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 1, 0, 
                  // Src: (add:i16 (MSP430Wrapper:i16 (tblockaddress:i16):$src2), GR16:i16:$src) - Complexity = 9
                  // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (tblockaddress:i16):$src2)
/*4917*/        0, // EndSwitchOpcode
/*4918*/      /*Scope*/ 67, /*->4986*/
/*4919*/        OPC_RecordChild0, // #0 = $src
/*4920*/        OPC_RecordChild1, // #1 = $src2
/*4921*/        OPC_Scope, 36, /*->4959*/ // 3 children in Scope
/*4923*/          OPC_MoveChild, 1,
/*4925*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*4928*/          OPC_MoveParent,
/*4929*/          OPC_SwitchType /*2 cases */, 12, MVT::i8,// ->4944
/*4932*/            OPC_EmitConvertToTarget, 1,
/*4934*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8ri), 0,
                        2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (add:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (ADD8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*4944*/          /*SwitchType*/ 12, MVT::i16,// ->4958
/*4946*/            OPC_EmitConvertToTarget, 1,
/*4948*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0,
                        2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (add:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*4958*/          0, // EndSwitchType
/*4959*/        /*Scope*/ 12, /*->4972*/
/*4960*/          OPC_CheckType, MVT::i8,
/*4962*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rr), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (ADD8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*4972*/        /*Scope*/ 12, /*->4985*/
/*4973*/          OPC_CheckType, MVT::i16,
/*4975*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rr), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (ADD16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*4985*/        0, /*End of Scope*/
/*4986*/      0, /*End of Scope*/
/*4987*/    /*SwitchOpcode*/ 47|128,1/*175*/, TARGET_VAL(ISD::ADDE),// ->5166
/*4991*/      OPC_CaptureGlueInput,
/*4992*/      OPC_Scope, 51, /*->5045*/ // 3 children in Scope
/*4994*/        OPC_RecordChild0, // #0 = $src
/*4995*/        OPC_MoveChild, 1,
/*4997*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5000*/        OPC_RecordMemRef,
/*5001*/        OPC_RecordNode, // #1 = 'ld' chained node
/*5002*/        OPC_CheckFoldableChainNode,
/*5003*/        OPC_RecordChild1, // #2 = $src2
/*5004*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5006*/        OPC_CheckPredicate, 1, // Predicate_load
/*5008*/        OPC_MoveParent,
/*5009*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->5027
/*5012*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5015*/          OPC_EmitMergeInputChains1_1,
/*5016*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (adde:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (ADC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5027*/        /*SwitchType*/ 15, MVT::i16,// ->5044
/*5029*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5032*/          OPC_EmitMergeInputChains1_1,
/*5033*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (adde:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (ADC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5044*/        0, // EndSwitchType
/*5045*/      /*Scope*/ 51, /*->5097*/
/*5046*/        OPC_MoveChild, 0,
/*5048*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5051*/        OPC_RecordMemRef,
/*5052*/        OPC_RecordNode, // #0 = 'ld' chained node
/*5053*/        OPC_CheckFoldableChainNode,
/*5054*/        OPC_RecordChild1, // #1 = $src2
/*5055*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5057*/        OPC_CheckPredicate, 1, // Predicate_load
/*5059*/        OPC_MoveParent,
/*5060*/        OPC_RecordChild1, // #2 = $src
/*5061*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->5079
/*5064*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5067*/          OPC_EmitMergeInputChains1_0,
/*5068*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (adde:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                  // Dst: (ADC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5079*/        /*SwitchType*/ 15, MVT::i16,// ->5096
/*5081*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5084*/          OPC_EmitMergeInputChains1_0,
/*5085*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (adde:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                  // Dst: (ADC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5096*/        0, // EndSwitchType
/*5097*/      /*Scope*/ 67, /*->5165*/
/*5098*/        OPC_RecordChild0, // #0 = $src
/*5099*/        OPC_RecordChild1, // #1 = $src2
/*5100*/        OPC_Scope, 36, /*->5138*/ // 3 children in Scope
/*5102*/          OPC_MoveChild, 1,
/*5104*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5107*/          OPC_MoveParent,
/*5108*/          OPC_SwitchType /*2 cases */, 12, MVT::i8,// ->5123
/*5111*/            OPC_EmitConvertToTarget, 1,
/*5113*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8ri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                        2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (adde:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (ADC8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5123*/          /*SwitchType*/ 12, MVT::i16,// ->5137
/*5125*/            OPC_EmitConvertToTarget, 1,
/*5127*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16ri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                        2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (adde:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (ADC16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5137*/          0, // EndSwitchType
/*5138*/        /*Scope*/ 12, /*->5151*/
/*5139*/          OPC_CheckType, MVT::i8,
/*5141*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC8rr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (adde:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (ADC8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5151*/        /*Scope*/ 12, /*->5164*/
/*5152*/          OPC_CheckType, MVT::i16,
/*5154*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADC16rr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (adde:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (ADC16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5164*/        0, /*End of Scope*/
/*5165*/      0, /*End of Scope*/
/*5166*/    /*SwitchOpcode*/ 46|128,1/*174*/, TARGET_VAL(ISD::OR),// ->5344
/*5170*/      OPC_Scope, 51, /*->5223*/ // 3 children in Scope
/*5172*/        OPC_RecordChild0, // #0 = $src
/*5173*/        OPC_MoveChild, 1,
/*5175*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5178*/        OPC_RecordMemRef,
/*5179*/        OPC_RecordNode, // #1 = 'ld' chained node
/*5180*/        OPC_CheckFoldableChainNode,
/*5181*/        OPC_RecordChild1, // #2 = $src2
/*5182*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5184*/        OPC_CheckPredicate, 1, // Predicate_load
/*5186*/        OPC_MoveParent,
/*5187*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->5205
/*5190*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5193*/          OPC_EmitMergeInputChains1_1,
/*5194*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (or:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (OR8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5205*/        /*SwitchType*/ 15, MVT::i16,// ->5222
/*5207*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5210*/          OPC_EmitMergeInputChains1_1,
/*5211*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (or:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (OR16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5222*/        0, // EndSwitchType
/*5223*/      /*Scope*/ 51, /*->5275*/
/*5224*/        OPC_MoveChild, 0,
/*5226*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5229*/        OPC_RecordMemRef,
/*5230*/        OPC_RecordNode, // #0 = 'ld' chained node
/*5231*/        OPC_CheckFoldableChainNode,
/*5232*/        OPC_RecordChild1, // #1 = $src2
/*5233*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5235*/        OPC_CheckPredicate, 1, // Predicate_load
/*5237*/        OPC_MoveParent,
/*5238*/        OPC_RecordChild1, // #2 = $src
/*5239*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->5257
/*5242*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5245*/          OPC_EmitMergeInputChains1_0,
/*5246*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (or:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                  // Dst: (OR8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5257*/        /*SwitchType*/ 15, MVT::i16,// ->5274
/*5259*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5262*/          OPC_EmitMergeInputChains1_0,
/*5263*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (or:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                  // Dst: (OR16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5274*/        0, // EndSwitchType
/*5275*/      /*Scope*/ 67, /*->5343*/
/*5276*/        OPC_RecordChild0, // #0 = $src
/*5277*/        OPC_RecordChild1, // #1 = $src2
/*5278*/        OPC_Scope, 36, /*->5316*/ // 3 children in Scope
/*5280*/          OPC_MoveChild, 1,
/*5282*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5285*/          OPC_MoveParent,
/*5286*/          OPC_SwitchType /*2 cases */, 12, MVT::i8,// ->5301
/*5289*/            OPC_EmitConvertToTarget, 1,
/*5291*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8ri), 0,
                        2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (or:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (OR8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5301*/          /*SwitchType*/ 12, MVT::i16,// ->5315
/*5303*/            OPC_EmitConvertToTarget, 1,
/*5305*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16ri), 0,
                        2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (or:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (OR16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5315*/          0, // EndSwitchType
/*5316*/        /*Scope*/ 12, /*->5329*/
/*5317*/          OPC_CheckType, MVT::i8,
/*5319*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::OR8rr), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (or:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (OR8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5329*/        /*Scope*/ 12, /*->5342*/
/*5330*/          OPC_CheckType, MVT::i16,
/*5332*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::OR16rr), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (or:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (OR16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5342*/        0, /*End of Scope*/
/*5343*/      0, /*End of Scope*/
/*5344*/    /*SwitchOpcode*/ 46|128,1/*174*/, TARGET_VAL(ISD::XOR),// ->5522
/*5348*/      OPC_Scope, 51, /*->5401*/ // 3 children in Scope
/*5350*/        OPC_RecordChild0, // #0 = $src
/*5351*/        OPC_MoveChild, 1,
/*5353*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5356*/        OPC_RecordMemRef,
/*5357*/        OPC_RecordNode, // #1 = 'ld' chained node
/*5358*/        OPC_CheckFoldableChainNode,
/*5359*/        OPC_RecordChild1, // #2 = $src2
/*5360*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5362*/        OPC_CheckPredicate, 1, // Predicate_load
/*5364*/        OPC_MoveParent,
/*5365*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->5383
/*5368*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5371*/          OPC_EmitMergeInputChains1_1,
/*5372*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (xor:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (XOR8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5383*/        /*SwitchType*/ 15, MVT::i16,// ->5400
/*5385*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5388*/          OPC_EmitMergeInputChains1_1,
/*5389*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (xor:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (XOR16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5400*/        0, // EndSwitchType
/*5401*/      /*Scope*/ 51, /*->5453*/
/*5402*/        OPC_MoveChild, 0,
/*5404*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5407*/        OPC_RecordMemRef,
/*5408*/        OPC_RecordNode, // #0 = 'ld' chained node
/*5409*/        OPC_CheckFoldableChainNode,
/*5410*/        OPC_RecordChild1, // #1 = $src2
/*5411*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5413*/        OPC_CheckPredicate, 1, // Predicate_load
/*5415*/        OPC_MoveParent,
/*5416*/        OPC_RecordChild1, // #2 = $src
/*5417*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->5435
/*5420*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5423*/          OPC_EmitMergeInputChains1_0,
/*5424*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (xor:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                  // Dst: (XOR8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5435*/        /*SwitchType*/ 15, MVT::i16,// ->5452
/*5437*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5440*/          OPC_EmitMergeInputChains1_0,
/*5441*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (xor:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                  // Dst: (XOR16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5452*/        0, // EndSwitchType
/*5453*/      /*Scope*/ 67, /*->5521*/
/*5454*/        OPC_RecordChild0, // #0 = $src
/*5455*/        OPC_RecordChild1, // #1 = $src2
/*5456*/        OPC_Scope, 36, /*->5494*/ // 3 children in Scope
/*5458*/          OPC_MoveChild, 1,
/*5460*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5463*/          OPC_MoveParent,
/*5464*/          OPC_SwitchType /*2 cases */, 12, MVT::i8,// ->5479
/*5467*/            OPC_EmitConvertToTarget, 1,
/*5469*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8ri), 0,
                        2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (xor:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (XOR8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5479*/          /*SwitchType*/ 12, MVT::i16,// ->5493
/*5481*/            OPC_EmitConvertToTarget, 1,
/*5483*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16ri), 0,
                        2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (xor:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (XOR16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5493*/          0, // EndSwitchType
/*5494*/        /*Scope*/ 12, /*->5507*/
/*5495*/          OPC_CheckType, MVT::i8,
/*5497*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR8rr), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (XOR8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5507*/        /*Scope*/ 12, /*->5520*/
/*5508*/          OPC_CheckType, MVT::i16,
/*5510*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::XOR16rr), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (xor:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (XOR16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5520*/        0, /*End of Scope*/
/*5521*/      0, /*End of Scope*/
/*5522*/    /*SwitchOpcode*/ 121, TARGET_VAL(ISD::SUB),// ->5646
/*5525*/      OPC_RecordChild0, // #0 = $src
/*5526*/      OPC_Scope, 50, /*->5578*/ // 2 children in Scope
/*5528*/        OPC_MoveChild, 1,
/*5530*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5533*/        OPC_RecordMemRef,
/*5534*/        OPC_RecordNode, // #1 = 'ld' chained node
/*5535*/        OPC_CheckFoldableChainNode,
/*5536*/        OPC_RecordChild1, // #2 = $src2
/*5537*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5539*/        OPC_CheckPredicate, 1, // Predicate_load
/*5541*/        OPC_MoveParent,
/*5542*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->5560
/*5545*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5548*/          OPC_EmitMergeInputChains1_1,
/*5549*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (sub:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (SUB8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5560*/        /*SwitchType*/ 15, MVT::i16,// ->5577
/*5562*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5565*/          OPC_EmitMergeInputChains1_1,
/*5566*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (sub:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (SUB16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5577*/        0, // EndSwitchType
/*5578*/      /*Scope*/ 66, /*->5645*/
/*5579*/        OPC_RecordChild1, // #1 = $src2
/*5580*/        OPC_Scope, 36, /*->5618*/ // 3 children in Scope
/*5582*/          OPC_MoveChild, 1,
/*5584*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5587*/          OPC_MoveParent,
/*5588*/          OPC_SwitchType /*2 cases */, 12, MVT::i8,// ->5603
/*5591*/            OPC_EmitConvertToTarget, 1,
/*5593*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8ri), 0,
                        2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (sub:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (SUB8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5603*/          /*SwitchType*/ 12, MVT::i16,// ->5617
/*5605*/            OPC_EmitConvertToTarget, 1,
/*5607*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16ri), 0,
                        2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (sub:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (SUB16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5617*/          0, // EndSwitchType
/*5618*/        /*Scope*/ 12, /*->5631*/
/*5619*/          OPC_CheckType, MVT::i8,
/*5621*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8rr), 0,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (SUB8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5631*/        /*Scope*/ 12, /*->5644*/
/*5632*/          OPC_CheckType, MVT::i16,
/*5634*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16rr), 0,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (SUB16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5644*/        0, /*End of Scope*/
/*5645*/      0, /*End of Scope*/
/*5646*/    /*SwitchOpcode*/ 122, TARGET_VAL(ISD::SUBE),// ->5771
/*5649*/      OPC_CaptureGlueInput,
/*5650*/      OPC_RecordChild0, // #0 = $src
/*5651*/      OPC_Scope, 50, /*->5703*/ // 2 children in Scope
/*5653*/        OPC_MoveChild, 1,
/*5655*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5658*/        OPC_RecordMemRef,
/*5659*/        OPC_RecordNode, // #1 = 'ld' chained node
/*5660*/        OPC_CheckFoldableChainNode,
/*5661*/        OPC_RecordChild1, // #2 = $src2
/*5662*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5664*/        OPC_CheckPredicate, 1, // Predicate_load
/*5666*/        OPC_MoveParent,
/*5667*/        OPC_SwitchType /*2 cases */, 15, MVT::i8,// ->5685
/*5670*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5673*/          OPC_EmitMergeInputChains1_1,
/*5674*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (sube:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (SBC8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5685*/        /*SwitchType*/ 15, MVT::i16,// ->5702
/*5687*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5690*/          OPC_EmitMergeInputChains1_1,
/*5691*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16rm), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (sube:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (SBC16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5702*/        0, // EndSwitchType
/*5703*/      /*Scope*/ 66, /*->5770*/
/*5704*/        OPC_RecordChild1, // #1 = $src2
/*5705*/        OPC_Scope, 36, /*->5743*/ // 3 children in Scope
/*5707*/          OPC_MoveChild, 1,
/*5709*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5712*/          OPC_MoveParent,
/*5713*/          OPC_SwitchType /*2 cases */, 12, MVT::i8,// ->5728
/*5716*/            OPC_EmitConvertToTarget, 1,
/*5718*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8ri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                        2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (sube:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (SBC8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5728*/          /*SwitchType*/ 12, MVT::i16,// ->5742
/*5730*/            OPC_EmitConvertToTarget, 1,
/*5732*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16ri), 0|OPFL_GlueInput|OPFL_GlueOutput,
                        2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (sube:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (SBC16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5742*/          0, // EndSwitchType
/*5743*/        /*Scope*/ 12, /*->5756*/
/*5744*/          OPC_CheckType, MVT::i8,
/*5746*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC8rr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (sube:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (SBC8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5756*/        /*Scope*/ 12, /*->5769*/
/*5757*/          OPC_CheckType, MVT::i16,
/*5759*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SBC16rr), 0|OPFL_GlueInput|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (sube:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (SBC16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5769*/        0, /*End of Scope*/
/*5770*/      0, /*End of Scope*/
/*5771*/    /*SwitchOpcode*/ 46|128,1/*174*/, TARGET_VAL(ISD::ADDC),// ->5949
/*5775*/      OPC_Scope, 51, /*->5828*/ // 3 children in Scope
/*5777*/        OPC_RecordChild0, // #0 = $src
/*5778*/        OPC_MoveChild, 1,
/*5780*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5783*/        OPC_RecordMemRef,
/*5784*/        OPC_RecordNode, // #1 = 'ld' chained node
/*5785*/        OPC_CheckFoldableChainNode,
/*5786*/        OPC_RecordChild1, // #2 = $src2
/*5787*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5789*/        OPC_CheckPredicate, 1, // Predicate_load
/*5791*/        OPC_MoveParent,
/*5792*/        OPC_SwitchType /*2 cases */, 15, MVT::i16,// ->5810
/*5795*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5798*/          OPC_EmitMergeInputChains1_1,
/*5799*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (addc:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (ADD16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5810*/        /*SwitchType*/ 15, MVT::i8,// ->5827
/*5812*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5815*/          OPC_EmitMergeInputChains1_1,
/*5816*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (addc:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (ADD8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5827*/        0, // EndSwitchType
/*5828*/      /*Scope*/ 51, /*->5880*/
/*5829*/        OPC_MoveChild, 0,
/*5831*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5834*/        OPC_RecordMemRef,
/*5835*/        OPC_RecordNode, // #0 = 'ld' chained node
/*5836*/        OPC_CheckFoldableChainNode,
/*5837*/        OPC_RecordChild1, // #1 = $src2
/*5838*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5840*/        OPC_CheckPredicate, 1, // Predicate_load
/*5842*/        OPC_MoveParent,
/*5843*/        OPC_RecordChild1, // #2 = $src
/*5844*/        OPC_SwitchType /*2 cases */, 15, MVT::i16,// ->5862
/*5847*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5850*/          OPC_EmitMergeInputChains1_0,
/*5851*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (addc:i16 (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR16:i16:$src) - Complexity = 16
                  // Dst: (ADD16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5862*/        /*SwitchType*/ 15, MVT::i8,// ->5879
/*5864*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src2 #3 #4
/*5867*/          OPC_EmitMergeInputChains1_0,
/*5868*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 2, 3, 4, 
                  // Src: (addc:i8 (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>, GR8:i8:$src) - Complexity = 16
                  // Dst: (ADD8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*5879*/        0, // EndSwitchType
/*5880*/      /*Scope*/ 67, /*->5948*/
/*5881*/        OPC_RecordChild0, // #0 = $src
/*5882*/        OPC_RecordChild1, // #1 = $src2
/*5883*/        OPC_Scope, 36, /*->5921*/ // 3 children in Scope
/*5885*/          OPC_MoveChild, 1,
/*5887*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*5890*/          OPC_MoveParent,
/*5891*/          OPC_SwitchType /*2 cases */, 12, MVT::i16,// ->5906
/*5894*/            OPC_EmitConvertToTarget, 1,
/*5896*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16ri), 0|OPFL_GlueOutput,
                        2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (addc:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (ADD16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*5906*/          /*SwitchType*/ 12, MVT::i8,// ->5920
/*5908*/            OPC_EmitConvertToTarget, 1,
/*5910*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8ri), 0|OPFL_GlueOutput,
                        2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (addc:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (ADD8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*5920*/          0, // EndSwitchType
/*5921*/        /*Scope*/ 12, /*->5934*/
/*5922*/          OPC_CheckType, MVT::i16,
/*5924*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD16rr), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (addc:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (ADD16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*5934*/        /*Scope*/ 12, /*->5947*/
/*5935*/          OPC_CheckType, MVT::i8,
/*5937*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::ADD8rr), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (addc:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (ADD8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*5947*/        0, /*End of Scope*/
/*5948*/      0, /*End of Scope*/
/*5949*/    /*SwitchOpcode*/ 121, TARGET_VAL(ISD::SUBC),// ->6073
/*5952*/      OPC_RecordChild0, // #0 = $src
/*5953*/      OPC_Scope, 50, /*->6005*/ // 2 children in Scope
/*5955*/        OPC_MoveChild, 1,
/*5957*/        OPC_CheckOpcode, TARGET_VAL(ISD::LOAD),
/*5960*/        OPC_RecordMemRef,
/*5961*/        OPC_RecordNode, // #1 = 'ld' chained node
/*5962*/        OPC_CheckFoldableChainNode,
/*5963*/        OPC_RecordChild1, // #2 = $src2
/*5964*/        OPC_CheckPredicate, 0, // Predicate_unindexedload
/*5966*/        OPC_CheckPredicate, 1, // Predicate_load
/*5968*/        OPC_MoveParent,
/*5969*/        OPC_SwitchType /*2 cases */, 15, MVT::i16,// ->5987
/*5972*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5975*/          OPC_EmitMergeInputChains1_1,
/*5976*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i16, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (subc:i16 GR16:i16:$src, (ld:i16 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (SUB16rm:i16:i16 GR16:i16:$src, addr:i16:$src2)
/*5987*/        /*SwitchType*/ 15, MVT::i8,// ->6004
/*5989*/          OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$src2 #3 #4
/*5992*/          OPC_EmitMergeInputChains1_1,
/*5993*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8rm), 0|OPFL_Chain|OPFL_GlueOutput|OPFL_MemRefs,
                      2/*#VTs*/, MVT::i8, MVT::i16, 3/*#Ops*/, 0, 3, 4, 
                  // Src: (subc:i8 GR8:i8:$src, (ld:i8 addr:iPTR:$src2)<<P:Predicate_unindexedload>><<P:Predicate_load>>) - Complexity = 16
                  // Dst: (SUB8rm:i8:i16 GR8:i8:$src, addr:i16:$src2)
/*6004*/        0, // EndSwitchType
/*6005*/      /*Scope*/ 66, /*->6072*/
/*6006*/        OPC_RecordChild1, // #1 = $src2
/*6007*/        OPC_Scope, 36, /*->6045*/ // 3 children in Scope
/*6009*/          OPC_MoveChild, 1,
/*6011*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6014*/          OPC_MoveParent,
/*6015*/          OPC_SwitchType /*2 cases */, 12, MVT::i16,// ->6030
/*6018*/            OPC_EmitConvertToTarget, 1,
/*6020*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16ri), 0|OPFL_GlueOutput,
                        2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (subc:i16 GR16:i16:$src, (imm:i16):$src2) - Complexity = 6
                    // Dst: (SUB16ri:i16:i16 GR16:i16:$src, (imm:i16):$src2)
/*6030*/          /*SwitchType*/ 12, MVT::i8,// ->6044
/*6032*/            OPC_EmitConvertToTarget, 1,
/*6034*/            OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8ri), 0|OPFL_GlueOutput,
                        2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 2, 
                    // Src: (subc:i8 GR8:i8:$src, (imm:i8):$src2) - Complexity = 6
                    // Dst: (SUB8ri:i8:i16 GR8:i8:$src, (imm:i8):$src2)
/*6044*/          0, // EndSwitchType
/*6045*/        /*Scope*/ 12, /*->6058*/
/*6046*/          OPC_CheckType, MVT::i16,
/*6048*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB16rr), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (subc:i16 GR16:i16:$src, GR16:i16:$src2) - Complexity = 3
                  // Dst: (SUB16rr:i16:i16 GR16:i16:$src, GR16:i16:$src2)
/*6058*/        /*Scope*/ 12, /*->6071*/
/*6059*/          OPC_CheckType, MVT::i8,
/*6061*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::SUB8rr), 0|OPFL_GlueOutput,
                      2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                  // Src: (subc:i8 GR8:i8:$src, GR8:i8:$src2) - Complexity = 3
                  // Dst: (SUB8rr:i8:i16 GR8:i8:$src, GR8:i8:$src2)
/*6071*/        0, /*End of Scope*/
/*6072*/      0, /*End of Scope*/
/*6073*/    /*SwitchOpcode*/ 82, TARGET_VAL(ISD::LOAD),// ->6158
/*6076*/      OPC_RecordMemRef,
/*6077*/      OPC_RecordNode, // #0 = 'ld' chained node
/*6078*/      OPC_RecordChild1, // #1 = $src
/*6079*/      OPC_CheckPredicate, 0, // Predicate_unindexedload
/*6081*/      OPC_Scope, 34, /*->6117*/ // 3 children in Scope
/*6083*/        OPC_CheckPredicate, 1, // Predicate_load
/*6085*/        OPC_SwitchType /*2 cases */, 13, MVT::i8,// ->6101
/*6088*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*6091*/          OPC_EmitMergeInputChains1_0,
/*6092*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8rm), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i8, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i8 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (MOV8rm:i8 addr:i16:$src)
/*6101*/        /*SwitchType*/ 13, MVT::i16,// ->6116
/*6103*/          OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*6106*/          OPC_EmitMergeInputChains1_0,
/*6107*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16rm), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i16, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                  // Dst: (MOV16rm:i16 addr:i16:$src)
/*6116*/        0, // EndSwitchType
/*6117*/      /*Scope*/ 19, /*->6137*/
/*6118*/        OPC_CheckPredicate, 5, // Predicate_zextload
/*6120*/        OPC_CheckPredicate, 6, // Predicate_zextloadi8
/*6122*/        OPC_CheckType, MVT::i16,
/*6124*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*6127*/        OPC_EmitMergeInputChains1_0,
/*6128*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOVZX16rm8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i16, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                // Dst: (MOVZX16rm8:i16 addr:i16:$src)
/*6137*/      /*Scope*/ 19, /*->6157*/
/*6138*/        OPC_CheckPredicate, 7, // Predicate_extload
/*6140*/        OPC_CheckPredicate, 6, // Predicate_extloadi8
/*6142*/        OPC_CheckType, MVT::i16,
/*6144*/        OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*6147*/        OPC_EmitMergeInputChains1_0,
/*6148*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOVZX16rm8), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i16, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i16 addr:iPTR:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                // Dst: (MOVZX16rm8:i16 addr:i16:$src)
/*6157*/      0, /*End of Scope*/
/*6158*/    /*SwitchOpcode*/ 26, TARGET_VAL(ISD::CALLSEQ_END),// ->6187
/*6161*/      OPC_RecordNode, // #0 = 'MSP430callseq_end' chained node
/*6162*/      OPC_CaptureGlueInput,
/*6163*/      OPC_RecordChild1, // #1 = $amt1
/*6164*/      OPC_MoveChild, 1,
/*6166*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*6169*/      OPC_MoveParent,
/*6170*/      OPC_RecordChild2, // #2 = $amt2
/*6171*/      OPC_MoveChild, 2,
/*6173*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*6176*/      OPC_MoveParent,
/*6177*/      OPC_EmitMergeInputChains1_0,
/*6178*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i16, 2/*#Ops*/, 1, 2, 
              // Src: (MSP430callseq_end (timm:i16):$amt1, (timm:i16):$amt2) - Complexity = 9
              // Dst: (ADJCALLSTACKUP:i16 (timm:i16):$amt1, (timm:i16):$amt2)
/*6187*/    /*SwitchOpcode*/ 17, TARGET_VAL(ISD::CALLSEQ_START),// ->6207
/*6190*/      OPC_RecordNode, // #0 = 'MSP430callseq_start' chained node
/*6191*/      OPC_RecordChild1, // #1 = $amt
/*6192*/      OPC_MoveChild, 1,
/*6194*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*6197*/      OPC_MoveParent,
/*6198*/      OPC_EmitMergeInputChains1_0,
/*6199*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
              // Src: (MSP430callseq_start (timm:i16):$amt) - Complexity = 6
              // Dst: (ADJCALLSTACKDOWN:i16 (timm:i16):$amt)
/*6207*/    /*SwitchOpcode*/ 27, TARGET_VAL(MSP430ISD::BR_CC),// ->6237
/*6210*/      OPC_RecordNode, // #0 = 'MSP430brcc' chained node
/*6211*/      OPC_CaptureGlueInput,
/*6212*/      OPC_RecordChild1, // #1 = $dst
/*6213*/      OPC_MoveChild, 1,
/*6215*/      OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*6218*/      OPC_MoveParent,
/*6219*/      OPC_RecordChild2, // #2 = $cc
/*6220*/      OPC_MoveChild, 2,
/*6222*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6225*/      OPC_MoveParent,
/*6226*/      OPC_EmitMergeInputChains1_0,
/*6227*/      OPC_EmitConvertToTarget, 2,
/*6229*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::JCC), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 2/*#Ops*/, 1, 3, 
              // Src: (MSP430brcc (bb:Other):$dst, (imm:i8):$cc) - Complexity = 6
              // Dst: (JCC (bb:Other):$dst, (imm:i8):$cc)
/*6237*/    /*SwitchOpcode*/ 53, TARGET_VAL(ISD::ZERO_EXTEND),// ->6293
/*6240*/      OPC_Scope, 15, /*->6257*/ // 2 children in Scope
/*6242*/        OPC_MoveChild, 0,
/*6244*/        OPC_CheckOpcode, TARGET_VAL(ISD::TRUNCATE),
/*6247*/        OPC_RecordChild0, // #0 = $src
/*6248*/        OPC_MoveParent,
/*6249*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::ZEXT16r), 0,
                    1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (zext:i16 (trunc:i8 GR16:i16:$src)) - Complexity = 6
                // Dst: (ZEXT16r:i16 GR16:i16:$src)
/*6257*/      /*Scope*/ 34, /*->6292*/
/*6258*/        OPC_RecordChild0, // #0 = $src
/*6259*/        OPC_Scope, 21, /*->6282*/ // 2 children in Scope
/*6261*/          OPC_MoveChild, 0,
/*6263*/          OPC_CheckPredicate, 8, // Predicate_def8
/*6265*/          OPC_MoveParent,
/*6266*/          OPC_EmitInteger, MVT::i16, 0, 
/*6269*/          OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*6272*/          OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::SUBREG_TO_REG), 0,
                      1/*#VTs*/, MVT::i16, 3/*#Ops*/, 1, 0, 2, 
                  // Src: (zext:i16 GR8:i8<<P:Predicate_def8>>:$src) - Complexity = 4
                  // Dst: (SUBREG_TO_REG:i16 0:i16, GR8:i8:$src, subreg_8bit:i32)
/*6282*/        /*Scope*/ 8, /*->6291*/
/*6283*/          OPC_MorphNodeTo, TARGET_VAL(MSP430::MOVZX16rr8), 0,
                      1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
                  // Src: (zext:i16 GR8:i8:$src) - Complexity = 3
                  // Dst: (MOVZX16rr8:i16 GR8:i8:$src)
/*6291*/        0, /*End of Scope*/
/*6292*/      0, /*End of Scope*/
/*6293*/    /*SwitchOpcode*/ 47, TARGET_VAL(MSP430ISD::Wrapper),// ->6343
/*6296*/      OPC_RecordChild0, // #0 = $dst
/*6297*/      OPC_MoveChild, 0,
/*6299*/      OPC_SwitchOpcode /*3 cases */, 11, TARGET_VAL(ISD::TargetGlobalAddress),// ->6314
/*6303*/        OPC_MoveParent,
/*6304*/        OPC_CheckType, MVT::i16,
/*6306*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16ri), 0,
                    1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (MSP430Wrapper:i16 (tglobaladdr:i16):$dst) - Complexity = 6
                // Dst: (MOV16ri:i16 (tglobaladdr:i16):$dst)
/*6314*/      /*SwitchOpcode*/ 11, TARGET_VAL(ISD::TargetExternalSymbol),// ->6328
/*6317*/        OPC_MoveParent,
/*6318*/        OPC_CheckType, MVT::i16,
/*6320*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16ri), 0,
                    1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (MSP430Wrapper:i16 (texternalsym:i16):$dst) - Complexity = 6
                // Dst: (MOV16ri:i16 (texternalsym:i16):$dst)
/*6328*/      /*SwitchOpcode*/ 11, TARGET_VAL(ISD::TargetBlockAddress),// ->6342
/*6331*/        OPC_MoveParent,
/*6332*/        OPC_CheckType, MVT::i16,
/*6334*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16ri), 0,
                    1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (MSP430Wrapper:i16 (tblockaddress:i16):$dst) - Complexity = 6
                // Dst: (MOV16ri:i16 (tblockaddress:i16):$dst)
/*6342*/      0, // EndSwitchOpcode
/*6343*/    /*SwitchOpcode*/ 40, TARGET_VAL(MSP430ISD::SELECT_CC),// ->6386
/*6346*/      OPC_CaptureGlueInput,
/*6347*/      OPC_RecordChild0, // #0 = $src
/*6348*/      OPC_RecordChild1, // #1 = $src2
/*6349*/      OPC_RecordChild2, // #2 = $cc
/*6350*/      OPC_MoveChild, 2,
/*6352*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*6355*/      OPC_MoveParent,
/*6356*/      OPC_SwitchType /*2 cases */, 12, MVT::i8,// ->6371
/*6359*/        OPC_EmitConvertToTarget, 2,
/*6361*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Select8), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i8, 3/*#Ops*/, 0, 1, 3, 
                // Src: (MSP430selectcc:i8 GR8:i8:$src, GR8:i8:$src2, (imm:i8):$cc) - Complexity = 6
                // Dst: (Select8:i8 GR8:i8:$src, GR8:i8:$src2, (imm:i8):$cc)
/*6371*/      /*SwitchType*/ 12, MVT::i16,// ->6385
/*6373*/        OPC_EmitConvertToTarget, 2,
/*6375*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Select16), 0|OPFL_GlueInput,
                    1/*#VTs*/, MVT::i16, 3/*#Ops*/, 0, 1, 3, 
                // Src: (MSP430selectcc:i16 GR16:i16:$src, GR16:i16:$src2, (imm:i8):$cc) - Complexity = 6
                // Dst: (Select16:i16 GR16:i16:$src, GR16:i16:$src2, (imm:i8):$cc)
/*6385*/      0, // EndSwitchType
/*6386*/    /*SwitchOpcode*/ 9, TARGET_VAL(MSP430ISD::RET_FLAG),// ->6398
/*6389*/      OPC_RecordNode, // #0 = 'MSP430retflag' chained node
/*6390*/      OPC_CaptureGlueInput,
/*6391*/      OPC_EmitMergeInputChains1_0,
/*6392*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::RET), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic0,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (MSP430retflag) - Complexity = 3
              // Dst: (RET)
/*6398*/    /*SwitchOpcode*/ 9, TARGET_VAL(MSP430ISD::RETI_FLAG),// ->6410
/*6401*/      OPC_RecordNode, // #0 = 'MSP430retiflag' chained node
/*6402*/      OPC_CaptureGlueInput,
/*6403*/      OPC_EmitMergeInputChains1_0,
/*6404*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::RETI), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic0,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (MSP430retiflag) - Complexity = 3
              // Dst: (RETI)
/*6410*/    /*SwitchOpcode*/ 16, TARGET_VAL(ISD::BR),// ->6429
/*6413*/      OPC_RecordNode, // #0 = 'br' chained node
/*6414*/      OPC_RecordChild1, // #1 = $dst
/*6415*/      OPC_MoveChild, 1,
/*6417*/      OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*6420*/      OPC_MoveParent,
/*6421*/      OPC_EmitMergeInputChains1_0,
/*6422*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::JMP), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (br (bb:Other):$dst) - Complexity = 3
              // Dst: (JMP (bb:Other):$dst)
/*6429*/    /*SwitchOpcode*/ 27, TARGET_VAL(ISD::Constant),// ->6459
/*6432*/      OPC_RecordNode, // #0 = $src
/*6433*/      OPC_SwitchType /*2 cases */, 10, MVT::i8,// ->6446
/*6436*/        OPC_EmitConvertToTarget, 0,
/*6438*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV8ri), 0,
                    1/*#VTs*/, MVT::i8, 1/*#Ops*/, 1, 
                // Src: (imm:i8):$src - Complexity = 3
                // Dst: (MOV8ri:i8 (imm:i8):$src)
/*6446*/      /*SwitchType*/ 10, MVT::i16,// ->6458
/*6448*/        OPC_EmitConvertToTarget, 0,
/*6450*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::MOV16ri), 0,
                    1/*#VTs*/, MVT::i16, 1/*#Ops*/, 1, 
                // Src: (imm:i16):$src - Complexity = 3
                // Dst: (MOV16ri:i16 (imm:i16):$src)
/*6458*/      0, // EndSwitchType
/*6459*/    /*SwitchOpcode*/ 25, TARGET_VAL(MSP430ISD::RRA),// ->6487
/*6462*/      OPC_RecordChild0, // #0 = $src
/*6463*/      OPC_SwitchType /*2 cases */, 9, MVT::i8,// ->6475
/*6466*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SAR8r1), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (MSP430rra:i8 GR8:i8:$src) - Complexity = 3
                // Dst: (SAR8r1:i8:i16 GR8:i8:$src)
/*6475*/      /*SwitchType*/ 9, MVT::i16,// ->6486
/*6477*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SAR16r1), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (MSP430rra:i16 GR16:i16:$src) - Complexity = 3
                // Dst: (SAR16r1:i16:i16 GR16:i16:$src)
/*6486*/      0, // EndSwitchType
/*6487*/    /*SwitchOpcode*/ 25, TARGET_VAL(MSP430ISD::RLA),// ->6515
/*6490*/      OPC_RecordChild0, // #0 = $src
/*6491*/      OPC_SwitchType /*2 cases */, 9, MVT::i8,// ->6503
/*6494*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SHL8r1), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (MSP430rla:i8 GR8:i8:$src) - Complexity = 3
                // Dst: (SHL8r1:i8:i16 GR8:i8:$src)
/*6503*/      /*SwitchType*/ 9, MVT::i16,// ->6514
/*6505*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SHL16r1), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (MSP430rla:i16 GR16:i16:$src) - Complexity = 3
                // Dst: (SHL16r1:i16:i16 GR16:i16:$src)
/*6514*/      0, // EndSwitchType
/*6515*/    /*SwitchOpcode*/ 25, TARGET_VAL(MSP430ISD::RRC),// ->6543
/*6518*/      OPC_RecordChild0, // #0 = $src
/*6519*/      OPC_SwitchType /*2 cases */, 9, MVT::i8,// ->6531
/*6522*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SAR8r1c), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (MSP430rrc:i8 GR8:i8:$src) - Complexity = 3
                // Dst: (SAR8r1c:i8:i16 GR8:i8:$src)
/*6531*/      /*SwitchType*/ 9, MVT::i16,// ->6542
/*6533*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::SAR16r1c), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 1/*#Ops*/, 0, 
                // Src: (MSP430rrc:i16 GR16:i16:$src) - Complexity = 3
                // Dst: (SAR16r1c:i16:i16 GR16:i16:$src)
/*6542*/      0, // EndSwitchType
/*6543*/    /*SwitchOpcode*/ 15, TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->6561
/*6546*/      OPC_RecordChild0, // #0 = $src
/*6547*/      OPC_MoveChild, 1,
/*6549*/      OPC_CheckValueType, MVT::i8,
/*6551*/      OPC_MoveParent,
/*6552*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::SEXT16r), 0,
                  2/*#VTs*/, MVT::i16, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (sext_inreg:i16 GR16:i16:$src, i8:Other) - Complexity = 3
              // Dst: (SEXT16r:i16:i16 GR16:i16:$src)
/*6561*/    /*SwitchOpcode*/ 11, TARGET_VAL(ISD::BSWAP),// ->6575
/*6564*/      OPC_RecordChild0, // #0 = $src
/*6565*/      OPC_CheckType, MVT::i16,
/*6567*/      OPC_MorphNodeTo, TARGET_VAL(MSP430::SWPB16r), 0,
                  1/*#VTs*/, MVT::i16, 1/*#Ops*/, 0, 
              // Src: (bswap:i16 GR16:i16:$src) - Complexity = 3
              // Dst: (SWPB16r:i16 GR16:i16:$src)
/*6575*/    /*SwitchOpcode*/ 17, TARGET_VAL(ISD::ANY_EXTEND),// ->6595
/*6578*/      OPC_RecordChild0, // #0 = $src
/*6579*/      OPC_EmitInteger, MVT::i16, 0, 
/*6582*/      OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*6585*/      OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::SUBREG_TO_REG), 0,
                  1/*#VTs*/, MVT::i16, 3/*#Ops*/, 1, 0, 2, 
              // Src: (anyext:i16 GR8:i8:$src) - Complexity = 3
              // Dst: (SUBREG_TO_REG:i16 0:i16, GR8:i8:$src, subreg_8bit:i32)
/*6595*/    /*SwitchOpcode*/ 13, TARGET_VAL(ISD::TRUNCATE),// ->6611
/*6598*/      OPC_RecordChild0, // #0 = $src
/*6599*/      OPC_EmitInteger, MVT::i32, MSP430::subreg_8bit,
/*6602*/      OPC_MorphNodeTo, TARGET_VAL(TargetOpcode::EXTRACT_SUBREG), 0,
                  1/*#VTs*/, MVT::i8, 2/*#Ops*/, 0, 1, 
              // Src: (trunc:i8 GR16:i16:$src) - Complexity = 3
              // Dst: (EXTRACT_SUBREG:i8 GR16:i16:$src, subreg_8bit:i32)
/*6611*/    /*SwitchOpcode*/ 28, TARGET_VAL(MSP430ISD::SHL),// ->6642
/*6614*/      OPC_RecordChild0, // #0 = $src
/*6615*/      OPC_RecordChild1, // #1 = $cnt
/*6616*/      OPC_SwitchType /*2 cases */, 10, MVT::i8,// ->6629
/*6619*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Shl8), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (MSP430shl:i8 GR8:i8:$src, GR8:i8:$cnt) - Complexity = 3
                // Dst: (Shl8:i8:i16 GR8:i8:$src, GR8:i8:$cnt)
/*6629*/      /*SwitchType*/ 10, MVT::i16,// ->6641
/*6631*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Shl16), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (MSP430shl:i16 GR16:i16:$src, GR8:i8:$cnt) - Complexity = 3
                // Dst: (Shl16:i16:i16 GR16:i16:$src, GR8:i8:$cnt)
/*6641*/      0, // EndSwitchType
/*6642*/    /*SwitchOpcode*/ 28, TARGET_VAL(MSP430ISD::SRA),// ->6673
/*6645*/      OPC_RecordChild0, // #0 = $src
/*6646*/      OPC_RecordChild1, // #1 = $cnt
/*6647*/      OPC_SwitchType /*2 cases */, 10, MVT::i8,// ->6660
/*6650*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Sra8), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (MSP430sra:i8 GR8:i8:$src, GR8:i8:$cnt) - Complexity = 3
                // Dst: (Sra8:i8:i16 GR8:i8:$src, GR8:i8:$cnt)
/*6660*/      /*SwitchType*/ 10, MVT::i16,// ->6672
/*6662*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Sra16), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (MSP430sra:i16 GR16:i16:$src, GR8:i8:$cnt) - Complexity = 3
                // Dst: (Sra16:i16:i16 GR16:i16:$src, GR8:i8:$cnt)
/*6672*/      0, // EndSwitchType
/*6673*/    /*SwitchOpcode*/ 28, TARGET_VAL(MSP430ISD::SRL),// ->6704
/*6676*/      OPC_RecordChild0, // #0 = $src
/*6677*/      OPC_RecordChild1, // #1 = $cnt
/*6678*/      OPC_SwitchType /*2 cases */, 10, MVT::i8,// ->6691
/*6681*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Srl8), 0,
                    2/*#VTs*/, MVT::i8, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (MSP430srl:i8 GR8:i8:$src, GR8:i8:$cnt) - Complexity = 3
                // Dst: (Srl8:i8:i16 GR8:i8:$src, GR8:i8:$cnt)
/*6691*/      /*SwitchType*/ 10, MVT::i16,// ->6703
/*6693*/        OPC_MorphNodeTo, TARGET_VAL(MSP430::Srl16), 0,
                    2/*#VTs*/, MVT::i16, MVT::i16, 2/*#Ops*/, 0, 1, 
                // Src: (MSP430srl:i16 GR16:i16:$src, GR8:i8:$cnt) - Complexity = 3
                // Dst: (Srl16:i16:i16 GR16:i16:$src, GR8:i8:$cnt)
/*6703*/      0, // EndSwitchType
/*6704*/    0, // EndSwitchOpcode
    0
  }; // Total Array size is 6706 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 71
  // #OPC_RecordNode                     = 71
  // #OPC_RecordChild                    = 170
  // #OPC_RecordMemRef                   = 58
  // #OPC_CaptureGlueInput               = 10
  // #OPC_MoveChild                      = 102
  // #OPC_MoveParent                     = 210
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 82
  // #OPC_CheckPatternPredicate          = 0
  // #OPC_CheckPredicate                 = 308
  // #OPC_CheckOpcode                    = 90
  // #OPC_SwitchOpcode                   = 11
  // #OPC_CheckType                      = 50
  // #OPC_SwitchType                     = 75
  // #OPC_CheckChildType                 = 8
  // #OPC_CheckInteger                   = 0
  // #OPC_CheckChildInteger              = 21
  // #OPC_CheckCondCode                  = 0
  // #OPC_CheckValueType                 = 1
  // #OPC_CheckComplexPat                = 183
  // #OPC_CheckAndImm                    = 1
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 56
  // #OPC_EmitInteger                    = 2
  // #OPC_EmitStringInteger              = 5
  // #OPC_EmitRegister                   = 0
  // #OPC_EmitConvertToTarget            = 48
  // #OPC_EmitMergeInputChains           = 157
  // #OPC_EmitCopyToReg                  = 0
  // #OPC_EmitNode                       = 2
  // #OPC_EmitNodeXForm                  = 0
  // #OPC_MarkGlueResults                = 28
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 239

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

bool CheckNodePredicate(SDNode *Node,
                        unsigned PredNo) const override {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { 
    // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 1: { 
    // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 2: { 
    // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 3: { 
    // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 4: { 
    // Predicate_and_su
    SDNode *N = Node;

  return N->hasOneUse();

  }
  case 5: { 
    // Predicate_zextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::ZEXTLOAD;

  }
  case 6: { 
    // Predicate_zextloadi8
    // Predicate_extloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 7: { 
    // Predicate_extload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::EXTLOAD;

  }
  case 8: { 
    // Predicate_def8
    SDNode *N = Node;

  return N->getOpcode() != ISD::TRUNCATE &&
         N->getOpcode() != TargetOpcode::EXTRACT_SUBREG &&
         N->getOpcode() != ISD::CopyFromReg;

  }
  }
}

bool CheckComplexPattern(SDNode *Root, SDNode *Parent,
                         SDValue N, unsigned PatternNo,
         SmallVectorImpl<std::pair<SDValue, SDNode*> > &Result) override {
  unsigned NextRes = Result.size();
  switch (PatternNo) {
  default: llvm_unreachable("Invalid pattern # in table?");
  case 0:
    Result.resize(NextRes+2);
    return SelectAddr(N, Result[NextRes+0].first, Result[NextRes+1].first);
  }
}

