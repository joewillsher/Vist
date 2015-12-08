/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* DAG Instruction Selector for the XCore target                              *|
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
/*0*/       OPC_SwitchOpcode /*44 cases */, 84|128,1/*212*/, TARGET_VAL(ISD::ADD),// ->217
/*5*/         OPC_Scope, 28, /*->35*/ // 5 children in Scope
/*7*/           OPC_MoveChild, 0,
/*9*/           OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*12*/          OPC_CheckChild0Integer, 1, 
/*14*/          OPC_RecordChild1, // #0 = $size
/*15*/          OPC_MoveParent,
/*16*/          OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*27*/          OPC_MorphNodeTo, TARGET_VAL(XCore::MKMSK_2r), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (add:i32 (shl:i32 1:i32, GRRegs:i32:$size), -1:i32) - Complexity = 16
                // Dst: (MKMSK_2r:i32 GRRegs:i32:$size)
/*35*/        /*Scope*/ 35, /*->71*/
/*36*/          OPC_RecordChild0, // #0 = $addr
/*37*/          OPC_MoveChild, 1,
/*39*/          OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*42*/          OPC_RecordChild0, // #1 = $offset
/*43*/          OPC_Scope, 12, /*->57*/ // 2 children in Scope
/*45*/            OPC_CheckChild1Integer, 2, 
/*47*/            OPC_MoveParent,
/*48*/            OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWF_l3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 2:i32)) - Complexity = 11
                  // Dst: (LDAWF_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*57*/          /*Scope*/ 12, /*->70*/
/*58*/            OPC_CheckChild1Integer, 1, 
/*60*/            OPC_MoveParent,
/*61*/            OPC_MorphNodeTo, TARGET_VAL(XCore::LDA16F_l3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)) - Complexity = 11
                  // Dst: (LDA16F_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*70*/          0, /*End of Scope*/
/*71*/        /*Scope*/ 36, /*->108*/
/*72*/          OPC_MoveChild, 0,
/*74*/          OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*77*/          OPC_RecordChild0, // #0 = $offset
/*78*/          OPC_Scope, 13, /*->93*/ // 2 children in Scope
/*80*/            OPC_CheckChild1Integer, 2, 
/*82*/            OPC_MoveParent,
/*83*/            OPC_RecordChild1, // #1 = $addr
/*84*/            OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWF_l3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (add:i32 (shl:i32 GRRegs:i32:$offset, 2:i32), GRRegs:i32:$addr) - Complexity = 11
                  // Dst: (LDAWF_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*93*/          /*Scope*/ 13, /*->107*/
/*94*/            OPC_CheckChild1Integer, 1, 
/*96*/            OPC_MoveParent,
/*97*/            OPC_RecordChild1, // #1 = $addr
/*98*/            OPC_MorphNodeTo, TARGET_VAL(XCore::LDA16F_l3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (add:i32 (shl:i32 GRRegs:i32:$offset, 1:i32), GRRegs:i32:$addr) - Complexity = 11
                  // Dst: (LDA16F_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*107*/         0, /*End of Scope*/
/*108*/       /*Scope*/ 15, /*->124*/
/*109*/         OPC_RecordNode, // #0 = $addr
/*110*/         OPC_CheckType, MVT::i32,
/*112*/         OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectADDRspii:$addr #1 #2
/*115*/         OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWFI), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                // Src: ADDRspii:i32:$addr - Complexity = 9
                // Dst: (LDAWFI:i32 ADDRspii:i32:$addr)
/*124*/       /*Scope*/ 91, /*->216*/
/*125*/         OPC_RecordChild0, // #0 = $b
/*126*/         OPC_RecordChild1, // #1 = $c
/*127*/         OPC_Scope, 76, /*->205*/ // 2 children in Scope
/*129*/           OPC_MoveChild, 1,
/*131*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*134*/           OPC_Scope, 14, /*->150*/ // 4 children in Scope
/*136*/             OPC_CheckPredicate, 0, // Predicate_immUs
/*138*/             OPC_MoveParent,
/*139*/             OPC_EmitConvertToTarget, 1,
/*141*/             OPC_MorphNodeTo, TARGET_VAL(XCore::ADD_2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (add:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immUs>>:$c) - Complexity = 7
                    // Dst: (ADD_2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*150*/           /*Scope*/ 17, /*->168*/
/*151*/             OPC_CheckPredicate, 1, // Predicate_immUs4
/*153*/             OPC_MoveParent,
/*154*/             OPC_EmitConvertToTarget, 1,
/*156*/             OPC_EmitNodeXForm, 0, 2, // div4_xform
/*159*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWF_l2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i32 GRRegs:i32:$addr, (imm:i32)<<P:Predicate_immUs4>>:$offset) - Complexity = 7
                    // Dst: (LDAWF_l2rus:i32 GRRegs:i32:$addr, (div4_xform:i32 (imm:i32)<<P:Predicate_immUs4>>:$offset))
/*168*/           /*Scope*/ 17, /*->186*/
/*169*/             OPC_CheckPredicate, 2, // Predicate_immUsNeg
/*171*/             OPC_MoveParent,
/*172*/             OPC_EmitConvertToTarget, 1,
/*174*/             OPC_EmitNodeXForm, 1, 2, // neg_xform
/*177*/             OPC_MorphNodeTo, TARGET_VAL(XCore::SUB_2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i32 GRRegs:i32:$src1, (imm:i32)<<P:Predicate_immUsNeg>>:$src2) - Complexity = 7
                    // Dst: (SUB_2rus:i32 GRRegs:i32:$src1, (neg_xform:i32 (imm:i32)<<P:Predicate_immUsNeg>>:$src2))
/*186*/           /*Scope*/ 17, /*->204*/
/*187*/             OPC_CheckPredicate, 3, // Predicate_immUs4Neg
/*189*/             OPC_MoveParent,
/*190*/             OPC_EmitConvertToTarget, 1,
/*192*/             OPC_EmitNodeXForm, 2, 2, // div4neg_xform
/*195*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWB_l2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (add:i32 GRRegs:i32:$src1, (imm:i32)<<P:Predicate_immUs4Neg>>:$src2) - Complexity = 7
                    // Dst: (LDAWB_l2rus:i32 GRRegs:i32:$src1, (div4neg_xform:i32 (imm:i32)<<P:Predicate_immUs4Neg>>:$src2))
/*204*/           0, /*End of Scope*/
/*205*/         /*Scope*/ 9, /*->215*/
/*206*/           OPC_MorphNodeTo, TARGET_VAL(XCore::ADD_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                  // Dst: (ADD_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*215*/         0, /*End of Scope*/
/*216*/       0, /*End of Scope*/
/*217*/     /*SwitchOpcode*/ 97|128,3/*481*/, TARGET_VAL(ISD::LOAD),// ->702
/*221*/       OPC_RecordMemRef,
/*222*/       OPC_RecordNode, // #0 = 'ld' chained node
/*223*/       OPC_Scope, 32|128,1/*160*/, /*->386*/ // 4 children in Scope
/*226*/         OPC_MoveChild, 1,
/*228*/         OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*231*/         OPC_Scope, 75, /*->308*/ // 2 children in Scope
/*233*/           OPC_RecordChild0, // #1 = $addr
/*234*/           OPC_MoveChild, 1,
/*236*/           OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*239*/           OPC_RecordChild0, // #2 = $offset
/*240*/           OPC_Scope, 42, /*->284*/ // 2 children in Scope
/*242*/             OPC_CheckChild1Integer, 1, 
/*244*/             OPC_MoveParent,
/*245*/             OPC_CheckType, MVT::i32,
/*247*/             OPC_MoveParent,
/*248*/             OPC_CheckPredicate, 4, // Predicate_unindexedload
/*250*/             OPC_CheckType, MVT::i32,
/*252*/             OPC_Scope, 14, /*->268*/ // 2 children in Scope
/*254*/               OPC_CheckPredicate, 5, // Predicate_sextload
/*256*/               OPC_CheckPredicate, 6, // Predicate_sextloadi16
/*258*/               OPC_EmitMergeInputChains1_0,
/*259*/               OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                      // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 15
                      // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*268*/             /*Scope*/ 14, /*->283*/
/*269*/               OPC_CheckPredicate, 7, // Predicate_extload
/*271*/               OPC_CheckPredicate, 6, // Predicate_extloadi16
/*273*/               OPC_EmitMergeInputChains1_0,
/*274*/               OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                      // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 15
                      // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*283*/             0, /*End of Scope*/
/*284*/           /*Scope*/ 22, /*->307*/
/*285*/             OPC_CheckChild1Integer, 2, 
/*287*/             OPC_MoveParent,
/*288*/             OPC_CheckType, MVT::i32,
/*290*/             OPC_MoveParent,
/*291*/             OPC_CheckPredicate, 4, // Predicate_unindexedload
/*293*/             OPC_CheckPredicate, 8, // Predicate_load
/*295*/             OPC_CheckType, MVT::i32,
/*297*/             OPC_EmitMergeInputChains1_0,
/*298*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LDW_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                    // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 2:i32)))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 15
                    // Dst: (LDW_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*307*/           0, /*End of Scope*/
/*308*/         /*Scope*/ 76, /*->385*/
/*309*/           OPC_MoveChild, 0,
/*311*/           OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*314*/           OPC_RecordChild0, // #1 = $offset
/*315*/           OPC_Scope, 43, /*->360*/ // 2 children in Scope
/*317*/             OPC_CheckChild1Integer, 1, 
/*319*/             OPC_MoveParent,
/*320*/             OPC_RecordChild1, // #2 = $addr
/*321*/             OPC_CheckType, MVT::i32,
/*323*/             OPC_MoveParent,
/*324*/             OPC_CheckPredicate, 4, // Predicate_unindexedload
/*326*/             OPC_CheckType, MVT::i32,
/*328*/             OPC_Scope, 14, /*->344*/ // 2 children in Scope
/*330*/               OPC_CheckPredicate, 5, // Predicate_sextload
/*332*/               OPC_CheckPredicate, 6, // Predicate_sextloadi16
/*334*/               OPC_EmitMergeInputChains1_0,
/*335*/               OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
                      // Src: (ld:i32 (add:i32 (shl:i32 GRRegs:i32:$offset, 1:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 15
                      // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*344*/             /*Scope*/ 14, /*->359*/
/*345*/               OPC_CheckPredicate, 7, // Predicate_extload
/*347*/               OPC_CheckPredicate, 6, // Predicate_extloadi16
/*349*/               OPC_EmitMergeInputChains1_0,
/*350*/               OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
                      // Src: (ld:i32 (add:i32 (shl:i32 GRRegs:i32:$offset, 1:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 15
                      // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*359*/             0, /*End of Scope*/
/*360*/           /*Scope*/ 23, /*->384*/
/*361*/             OPC_CheckChild1Integer, 2, 
/*363*/             OPC_MoveParent,
/*364*/             OPC_RecordChild1, // #2 = $addr
/*365*/             OPC_CheckType, MVT::i32,
/*367*/             OPC_MoveParent,
/*368*/             OPC_CheckPredicate, 4, // Predicate_unindexedload
/*370*/             OPC_CheckPredicate, 8, // Predicate_load
/*372*/             OPC_CheckType, MVT::i32,
/*374*/             OPC_EmitMergeInputChains1_0,
/*375*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LDW_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
                    // Src: (ld:i32 (add:i32 (shl:i32 GRRegs:i32:$offset, 2:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 15
                    // Dst: (LDW_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*384*/           0, /*End of Scope*/
/*385*/         0, /*End of Scope*/
/*386*/       /*Scope*/ 22, /*->409*/
/*387*/         OPC_RecordChild1, // #1 = $addr
/*388*/         OPC_CheckChild1Type, MVT::i32,
/*390*/         OPC_CheckPredicate, 4, // Predicate_unindexedload
/*392*/         OPC_CheckPredicate, 8, // Predicate_load
/*394*/         OPC_CheckType, MVT::i32,
/*396*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectADDRspii:$addr #2 #3
/*399*/         OPC_EmitMergeInputChains1_0,
/*400*/         OPC_MorphNodeTo, TARGET_VAL(XCore::LDWFI), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i32 ADDRspii:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (LDWFI:i32 ADDRspii:i32:$addr)
/*409*/       /*Scope*/ 30|128,1/*158*/, /*->569*/
/*411*/         OPC_MoveChild, 1,
/*413*/         OPC_SwitchOpcode /*3 cases */, 77, TARGET_VAL(ISD::ADD),// ->494
/*417*/           OPC_RecordChild0, // #1 = $addr
/*418*/           OPC_RecordChild1, // #2 = $offset
/*419*/           OPC_Scope, 32, /*->453*/ // 2 children in Scope
/*421*/             OPC_MoveChild, 1,
/*423*/             OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*426*/             OPC_CheckPredicate, 1, // Predicate_immUs4
/*428*/             OPC_MoveParent,
/*429*/             OPC_CheckType, MVT::i32,
/*431*/             OPC_MoveParent,
/*432*/             OPC_CheckPredicate, 4, // Predicate_unindexedload
/*434*/             OPC_CheckPredicate, 8, // Predicate_load
/*436*/             OPC_CheckType, MVT::i32,
/*438*/             OPC_EmitMergeInputChains1_0,
/*439*/             OPC_EmitConvertToTarget, 2,
/*441*/             OPC_EmitNodeXForm, 0, 3, // div4_xform
/*444*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LDW_2rus), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4, 
                    // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, (imm:i32)<<P:Predicate_immUs4>>:$offset))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 11
                    // Dst: (LDW_2rus:i32 GRRegs:i32:$addr, (div4_xform:i32 (imm:i32)<<P:Predicate_immUs4>>:$offset))
/*453*/           /*Scope*/ 39, /*->493*/
/*454*/             OPC_CheckType, MVT::i32,
/*456*/             OPC_MoveParent,
/*457*/             OPC_CheckPredicate, 4, // Predicate_unindexedload
/*459*/             OPC_CheckType, MVT::i32,
/*461*/             OPC_Scope, 14, /*->477*/ // 2 children in Scope
/*463*/               OPC_CheckPredicate, 9, // Predicate_zextload
/*465*/               OPC_CheckPredicate, 10, // Predicate_zextloadi8
/*467*/               OPC_EmitMergeInputChains1_0,
/*468*/               OPC_MorphNodeTo, TARGET_VAL(XCore::LD8U_3r), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                      // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, GRRegs:i32:$offset))<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 7
                      // Dst: (LD8U_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*477*/             /*Scope*/ 14, /*->492*/
/*478*/               OPC_CheckPredicate, 7, // Predicate_extload
/*480*/               OPC_CheckPredicate, 10, // Predicate_extloadi8
/*482*/               OPC_EmitMergeInputChains1_0,
/*483*/               OPC_MorphNodeTo, TARGET_VAL(XCore::LD8U_3r), 0|OPFL_Chain|OPFL_MemRefs,
                          1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                      // Src: (ld:i32 (add:i32 GRRegs:i32:$addr, GRRegs:i32:$offset))<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 7
                      // Dst: (LD8U_3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*492*/             0, /*End of Scope*/
/*493*/           0, /*End of Scope*/
/*494*/         /*SwitchOpcode*/ 23, TARGET_VAL(XCoreISD::DPRelativeWrapper),// ->520
/*497*/           OPC_RecordChild0, // #1 = $b
/*498*/           OPC_MoveChild, 0,
/*500*/           OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*503*/           OPC_MoveParent,
/*504*/           OPC_MoveParent,
/*505*/           OPC_CheckPredicate, 4, // Predicate_unindexedload
/*507*/           OPC_CheckPredicate, 8, // Predicate_load
/*509*/           OPC_CheckType, MVT::i32,
/*511*/           OPC_EmitMergeInputChains1_0,
/*512*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LDWDP_lru6), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                  // Src: (ld:i32 (dprelwrapper:iPTR (tglobaladdr:iPTR):$b))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 10
                  // Dst: (LDWDP_lru6:i32 (tglobaladdr:i32):$b)
/*520*/         /*SwitchOpcode*/ 45, TARGET_VAL(XCoreISD::CPRelativeWrapper),// ->568
/*523*/           OPC_RecordChild0, // #1 = $b
/*524*/           OPC_MoveChild, 0,
/*526*/           OPC_SwitchOpcode /*2 cases */, 17, TARGET_VAL(ISD::TargetGlobalAddress),// ->547
/*530*/             OPC_MoveParent,
/*531*/             OPC_MoveParent,
/*532*/             OPC_CheckPredicate, 4, // Predicate_unindexedload
/*534*/             OPC_CheckPredicate, 8, // Predicate_load
/*536*/             OPC_CheckType, MVT::i32,
/*538*/             OPC_EmitMergeInputChains1_0,
/*539*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LDWCP_lru6), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                    // Src: (ld:i32 (cprelwrapper:iPTR (tglobaladdr:iPTR):$b))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 10
                    // Dst: (LDWCP_lru6:i32 (tglobaladdr:i32):$b)
/*547*/           /*SwitchOpcode*/ 17, TARGET_VAL(ISD::TargetConstantPool),// ->567
/*550*/             OPC_MoveParent,
/*551*/             OPC_MoveParent,
/*552*/             OPC_CheckPredicate, 4, // Predicate_unindexedload
/*554*/             OPC_CheckPredicate, 8, // Predicate_load
/*556*/             OPC_CheckType, MVT::i32,
/*558*/             OPC_EmitMergeInputChains1_0,
/*559*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LDWCP_lru6), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                    // Src: (ld:i32 (cprelwrapper:iPTR (tconstpool:iPTR):$b))<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 10
                    // Dst: (LDWCP_lru6:i32 (tconstpool:i32):$b)
/*567*/           0, // EndSwitchOpcode
/*568*/         0, // EndSwitchOpcode
/*569*/       /*Scope*/ 2|128,1/*130*/, /*->701*/
/*571*/         OPC_RecordChild1, // #1 = $addr
/*572*/         OPC_CheckChild1Type, MVT::i32,
/*574*/         OPC_CheckPredicate, 4, // Predicate_unindexedload
/*576*/         OPC_CheckType, MVT::i32,
/*578*/         OPC_Scope, 15, /*->595*/ // 4 children in Scope
/*580*/           OPC_CheckPredicate, 8, // Predicate_load
/*582*/           OPC_EmitMergeInputChains1_0,
/*583*/           OPC_EmitInteger, MVT::i32, 0, 
/*586*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LDW_2rus), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
                  // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 4
                  // Dst: (LDW_2rus:i32 GRRegs:i32:$addr, 0:i32)
/*595*/         /*Scope*/ 25, /*->621*/
/*596*/           OPC_CheckPredicate, 9, // Predicate_zextload
/*598*/           OPC_CheckPredicate, 10, // Predicate_zextloadi8
/*600*/           OPC_EmitMergeInputChains1_0,
/*601*/           OPC_EmitInteger, MVT::i32, 0, 
/*604*/           OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*612*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LD8U_3r), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3, 
                  // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 4
                  // Dst: (LD8U_3r:i32 GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*621*/         /*Scope*/ 25, /*->647*/
/*622*/           OPC_CheckPredicate, 5, // Predicate_sextload
/*624*/           OPC_CheckPredicate, 6, // Predicate_sextloadi16
/*626*/           OPC_EmitMergeInputChains1_0,
/*627*/           OPC_EmitInteger, MVT::i32, 0, 
/*630*/           OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*638*/           OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3, 
                  // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_sextload>><<P:Predicate_sextloadi16>> - Complexity = 4
                  // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*647*/         /*Scope*/ 52, /*->700*/
/*648*/           OPC_CheckPredicate, 7, // Predicate_extload
/*650*/           OPC_Scope, 23, /*->675*/ // 2 children in Scope
/*652*/             OPC_CheckPredicate, 10, // Predicate_extloadi8
/*654*/             OPC_EmitMergeInputChains1_0,
/*655*/             OPC_EmitInteger, MVT::i32, 0, 
/*658*/             OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*666*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LD8U_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3, 
                    // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 4
                    // Dst: (LD8U_3r:i32 GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*675*/           /*Scope*/ 23, /*->699*/
/*676*/             OPC_CheckPredicate, 6, // Predicate_extloadi16
/*678*/             OPC_EmitMergeInputChains1_0,
/*679*/             OPC_EmitInteger, MVT::i32, 0, 
/*682*/             OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2,  // Results = #3
/*690*/             OPC_MorphNodeTo, TARGET_VAL(XCore::LD16S_3r), 0|OPFL_Chain|OPFL_MemRefs,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3, 
                    // Src: (ld:i32 GRRegs:i32:$addr)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 4
                    // Dst: (LD16S_3r:i32 GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*699*/           0, /*End of Scope*/
/*700*/         0, /*End of Scope*/
/*701*/       0, /*End of Scope*/
/*702*/     /*SwitchOpcode*/ 53|128,2/*309*/, TARGET_VAL(ISD::STORE),// ->1015
/*706*/       OPC_RecordMemRef,
/*707*/       OPC_RecordNode, // #0 = 'st' chained node
/*708*/       OPC_RecordChild1, // #1 = $val
/*709*/       OPC_CheckChild1Type, MVT::i32,
/*711*/       OPC_Scope, 116, /*->829*/ // 4 children in Scope
/*713*/         OPC_MoveChild, 2,
/*715*/         OPC_CheckOpcode, TARGET_VAL(ISD::ADD),
/*718*/         OPC_Scope, 53, /*->773*/ // 2 children in Scope
/*720*/           OPC_RecordChild0, // #2 = $addr
/*721*/           OPC_MoveChild, 1,
/*723*/           OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*726*/           OPC_RecordChild0, // #3 = $offset
/*727*/           OPC_Scope, 22, /*->751*/ // 2 children in Scope
/*729*/             OPC_CheckChild1Integer, 1, 
/*731*/             OPC_MoveParent,
/*732*/             OPC_CheckType, MVT::i32,
/*734*/             OPC_MoveParent,
/*735*/             OPC_CheckPredicate, 11, // Predicate_unindexedstore
/*737*/             OPC_CheckPredicate, 12, // Predicate_truncstore
/*739*/             OPC_CheckPredicate, 13, // Predicate_truncstorei16
/*741*/             OPC_EmitMergeInputChains1_0,
/*742*/             OPC_MorphNodeTo, TARGET_VAL(XCore::ST16_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (st GRRegs:i32:$val, (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 15
                    // Dst: (ST16_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*751*/           /*Scope*/ 20, /*->772*/
/*752*/             OPC_CheckChild1Integer, 2, 
/*754*/             OPC_MoveParent,
/*755*/             OPC_CheckType, MVT::i32,
/*757*/             OPC_MoveParent,
/*758*/             OPC_CheckPredicate, 11, // Predicate_unindexedstore
/*760*/             OPC_CheckPredicate, 14, // Predicate_store
/*762*/             OPC_EmitMergeInputChains1_0,
/*763*/             OPC_MorphNodeTo, TARGET_VAL(XCore::STW_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (st GRRegs:i32:$val, (add:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 2:i32)))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 15
                    // Dst: (STW_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*772*/           0, /*End of Scope*/
/*773*/         /*Scope*/ 54, /*->828*/
/*774*/           OPC_MoveChild, 0,
/*776*/           OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*779*/           OPC_RecordChild0, // #2 = $offset
/*780*/           OPC_Scope, 23, /*->805*/ // 2 children in Scope
/*782*/             OPC_CheckChild1Integer, 1, 
/*784*/             OPC_MoveParent,
/*785*/             OPC_RecordChild1, // #3 = $addr
/*786*/             OPC_CheckType, MVT::i32,
/*788*/             OPC_MoveParent,
/*789*/             OPC_CheckPredicate, 11, // Predicate_unindexedstore
/*791*/             OPC_CheckPredicate, 12, // Predicate_truncstore
/*793*/             OPC_CheckPredicate, 13, // Predicate_truncstorei16
/*795*/             OPC_EmitMergeInputChains1_0,
/*796*/             OPC_MorphNodeTo, TARGET_VAL(XCore::ST16_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                    // Src: (st GRRegs:i32:$val, (add:i32 (shl:i32 GRRegs:i32:$offset, 1:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 15
                    // Dst: (ST16_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*805*/           /*Scope*/ 21, /*->827*/
/*806*/             OPC_CheckChild1Integer, 2, 
/*808*/             OPC_MoveParent,
/*809*/             OPC_RecordChild1, // #3 = $addr
/*810*/             OPC_CheckType, MVT::i32,
/*812*/             OPC_MoveParent,
/*813*/             OPC_CheckPredicate, 11, // Predicate_unindexedstore
/*815*/             OPC_CheckPredicate, 14, // Predicate_store
/*817*/             OPC_EmitMergeInputChains1_0,
/*818*/             OPC_MorphNodeTo, TARGET_VAL(XCore::STW_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 3, 2, 
                    // Src: (st GRRegs:i32:$val, (add:i32 (shl:i32 GRRegs:i32:$offset, 2:i32), GRRegs:i32:$addr))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 15
                    // Dst: (STW_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*827*/           0, /*End of Scope*/
/*828*/         0, /*End of Scope*/
/*829*/       /*Scope*/ 20, /*->850*/
/*830*/         OPC_RecordChild2, // #2 = $addr
/*831*/         OPC_CheckChild2Type, MVT::i32,
/*833*/         OPC_CheckPredicate, 11, // Predicate_unindexedstore
/*835*/         OPC_CheckPredicate, 14, // Predicate_store
/*837*/         OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectADDRspii:$addr #3 #4
/*840*/         OPC_EmitMergeInputChains1_0,
/*841*/         OPC_MorphNodeTo, TARGET_VAL(XCore::STWFI), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (st GRRegs:i32:$src, ADDRspii:i32:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                // Dst: (STWFI GRRegs:i32:$src, ADDRspii:i32:$addr)
/*850*/       /*Scope*/ 86, /*->937*/
/*851*/         OPC_MoveChild, 2,
/*853*/         OPC_SwitchOpcode /*2 cases */, 55, TARGET_VAL(ISD::ADD),// ->912
/*857*/           OPC_RecordChild0, // #2 = $addr
/*858*/           OPC_RecordChild1, // #3 = $offset
/*859*/           OPC_Scope, 30, /*->891*/ // 2 children in Scope
/*861*/             OPC_MoveChild, 1,
/*863*/             OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*866*/             OPC_CheckPredicate, 1, // Predicate_immUs4
/*868*/             OPC_MoveParent,
/*869*/             OPC_CheckType, MVT::i32,
/*871*/             OPC_MoveParent,
/*872*/             OPC_CheckPredicate, 11, // Predicate_unindexedstore
/*874*/             OPC_CheckPredicate, 14, // Predicate_store
/*876*/             OPC_EmitMergeInputChains1_0,
/*877*/             OPC_EmitConvertToTarget, 3,
/*879*/             OPC_EmitNodeXForm, 0, 4, // div4_xform
/*882*/             OPC_MorphNodeTo, TARGET_VAL(XCore::STW_2rus), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 5, 
                    // Src: (st GRRegs:i32:$val, (add:i32 GRRegs:i32:$addr, (imm:i32)<<P:Predicate_immUs4>>:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 11
                    // Dst: (STW_2rus GRRegs:i32:$val, GRRegs:i32:$addr, (div4_xform:i32 (imm:i32)<<P:Predicate_immUs4>>:$offset))
/*891*/           /*Scope*/ 19, /*->911*/
/*892*/             OPC_CheckType, MVT::i32,
/*894*/             OPC_MoveParent,
/*895*/             OPC_CheckPredicate, 11, // Predicate_unindexedstore
/*897*/             OPC_CheckPredicate, 12, // Predicate_truncstore
/*899*/             OPC_CheckPredicate, 15, // Predicate_truncstorei8
/*901*/             OPC_EmitMergeInputChains1_0,
/*902*/             OPC_MorphNodeTo, TARGET_VAL(XCore::ST8_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                    // Src: (st GRRegs:i32:$val, (add:i32 GRRegs:i32:$addr, GRRegs:i32:$offset))<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 7
                    // Dst: (ST8_l3r GRRegs:i32:$val, GRRegs:i32:$addr, GRRegs:i32:$offset)
/*911*/           0, /*End of Scope*/
/*912*/         /*SwitchOpcode*/ 21, TARGET_VAL(XCoreISD::DPRelativeWrapper),// ->936
/*915*/           OPC_RecordChild0, // #2 = $b
/*916*/           OPC_MoveChild, 0,
/*918*/           OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*921*/           OPC_MoveParent,
/*922*/           OPC_MoveParent,
/*923*/           OPC_CheckPredicate, 11, // Predicate_unindexedstore
/*925*/           OPC_CheckPredicate, 14, // Predicate_store
/*927*/           OPC_EmitMergeInputChains1_0,
/*928*/           OPC_MorphNodeTo, TARGET_VAL(XCore::STWDP_lru6), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                  // Src: (st RRegs:i32:$a, (dprelwrapper:iPTR (tglobaladdr:iPTR):$b))<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 10
                  // Dst: (STWDP_lru6 RRegs:i32:$a, (tglobaladdr:i32):$b)
/*936*/         0, // EndSwitchOpcode
/*937*/       /*Scope*/ 76, /*->1014*/
/*938*/         OPC_RecordChild2, // #2 = $addr
/*939*/         OPC_CheckChild2Type, MVT::i32,
/*941*/         OPC_CheckPredicate, 11, // Predicate_unindexedstore
/*943*/         OPC_Scope, 15, /*->960*/ // 2 children in Scope
/*945*/           OPC_CheckPredicate, 14, // Predicate_store
/*947*/           OPC_EmitMergeInputChains1_0,
/*948*/           OPC_EmitInteger, MVT::i32, 0, 
/*951*/           OPC_MorphNodeTo, TARGET_VAL(XCore::STW_2rus), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (st GRRegs:i32:$val, GRRegs:i32:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 4
                  // Dst: (STW_2rus GRRegs:i32:$val, GRRegs:i32:$addr, 0:i32)
/*960*/         /*Scope*/ 52, /*->1013*/
/*961*/           OPC_CheckPredicate, 12, // Predicate_truncstore
/*963*/           OPC_Scope, 23, /*->988*/ // 2 children in Scope
/*965*/             OPC_CheckPredicate, 15, // Predicate_truncstorei8
/*967*/             OPC_EmitMergeInputChains1_0,
/*968*/             OPC_EmitInteger, MVT::i32, 0, 
/*971*/             OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*979*/             OPC_MorphNodeTo, TARGET_VAL(XCore::ST8_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 4, 
                    // Src: (st GRRegs:i32:$val, GRRegs:i32:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 4
                    // Dst: (ST8_l3r GRRegs:i32:$val, GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*988*/           /*Scope*/ 23, /*->1012*/
/*989*/             OPC_CheckPredicate, 13, // Predicate_truncstorei16
/*991*/             OPC_EmitMergeInputChains1_0,
/*992*/             OPC_EmitInteger, MVT::i32, 0, 
/*995*/             OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                        1/*#VTs*/, MVT::i32, 1/*#Ops*/, 3,  // Results = #4
/*1003*/            OPC_MorphNodeTo, TARGET_VAL(XCore::ST16_l3r), 0|OPFL_Chain|OPFL_MemRefs,
                        0/*#VTs*/, 3/*#Ops*/, 1, 2, 4, 
                    // Src: (st GRRegs:i32:$val, GRRegs:i32:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 4
                    // Dst: (ST16_l3r GRRegs:i32:$val, GRRegs:i32:$addr, (LDC_ru6:i32 0:i32))
/*1012*/          0, /*End of Scope*/
/*1013*/        0, /*End of Scope*/
/*1014*/      0, /*End of Scope*/
/*1015*/    /*SwitchOpcode*/ 88, TARGET_VAL(ISD::SRA),// ->1106
/*1018*/      OPC_Scope, 32, /*->1052*/ // 2 children in Scope
/*1020*/        OPC_MoveChild, 0,
/*1022*/        OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*1025*/        OPC_RecordChild0, // #0 = $src
/*1026*/        OPC_RecordChild1, // #1 = $imm
/*1027*/        OPC_MoveChild, 1,
/*1029*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1032*/        OPC_CheckPredicate, 16, // Predicate_immBpwSubBitp
/*1034*/        OPC_MoveParent,
/*1035*/        OPC_MoveParent,
/*1036*/        OPC_CheckChild1Same, 1,
/*1038*/        OPC_EmitConvertToTarget, 1,
/*1040*/        OPC_EmitNodeXForm, 3, 2, // bpwsub_xform
/*1043*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                // Src: (sra:i32 (shl:i32 GRRegs:i32:$src, (imm:i32)<<P:Predicate_immBpwSubBitp>>:$imm), (imm:i32)<<P:Predicate_immBpwSubBitp>>:$imm) - Complexity = 14
                // Dst: (SEXT_rus:i32 GRRegs:i32:$src, (bpwsub_xform:i32 (imm:i32)<<P:Predicate_immBpwSubBitp>>:$imm))
/*1052*/      /*Scope*/ 52, /*->1105*/
/*1053*/        OPC_RecordChild0, // #0 = $src
/*1054*/        OPC_Scope, 14, /*->1070*/ // 2 children in Scope
/*1056*/          OPC_CheckChild1Integer, 31, 
/*1058*/          OPC_EmitInteger, MVT::i32, 32, 
/*1061*/          OPC_MorphNodeTo, TARGET_VAL(XCore::ASHR_l2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sra:i32 GRRegs:i32:$src, 31:i32) - Complexity = 8
                  // Dst: (ASHR_l2rus:i32 GRRegs:i32:$src, 32:i32)
/*1070*/        /*Scope*/ 33, /*->1104*/
/*1071*/          OPC_RecordChild1, // #1 = $c
/*1072*/          OPC_Scope, 19, /*->1093*/ // 2 children in Scope
/*1074*/            OPC_MoveChild, 1,
/*1076*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1079*/            OPC_CheckPredicate, 17, // Predicate_immBitp
/*1081*/            OPC_MoveParent,
/*1082*/            OPC_EmitConvertToTarget, 1,
/*1084*/            OPC_MorphNodeTo, TARGET_VAL(XCore::ASHR_l2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (sra:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immBitp>>:$c) - Complexity = 7
                    // Dst: (ASHR_l2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*1093*/          /*Scope*/ 9, /*->1103*/
/*1094*/            OPC_MorphNodeTo, TARGET_VAL(XCore::ASHR_l3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                    // Src: (sra:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                    // Dst: (ASHR_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*1103*/          0, /*End of Scope*/
/*1104*/        0, /*End of Scope*/
/*1105*/      0, /*End of Scope*/
/*1106*/    /*SwitchOpcode*/ 0|128,5/*640*/, TARGET_VAL(ISD::INTRINSIC_VOID),// ->1750
/*1110*/      OPC_RecordNode, // #0 = 'intrinsic_void' chained node
/*1111*/      OPC_Scope, 57, /*->1170*/ // 30 children in Scope
/*1113*/        OPC_CheckChild1Integer, 39|128,46/*5927*/, 
/*1116*/        OPC_RecordChild2, // #1 = $a
/*1117*/        OPC_CheckChild2Type, MVT::i32,
/*1119*/        OPC_RecordChild3, // #2 = $b
/*1120*/        OPC_Scope, 37, /*->1159*/ // 2 children in Scope
/*1122*/          OPC_MoveChild, 3,
/*1124*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1127*/          OPC_Scope, 14, /*->1143*/ // 2 children in Scope
/*1129*/            OPC_CheckPredicate, 18, // Predicate_immU6
/*1131*/            OPC_MoveParent,
/*1132*/            OPC_EmitMergeInputChains1_0,
/*1133*/            OPC_EmitConvertToTarget, 2,
/*1135*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SETC_ru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                    // Src: (intrinsic_void 5927:iPTR, GRRegs:i32:$a, (imm:i32)<<P:Predicate_immU6>>:$b) - Complexity = 12
                    // Dst: (SETC_ru6 GRRegs:i32:$a, (imm:i32):$b)
/*1143*/          /*Scope*/ 14, /*->1158*/
/*1144*/            OPC_CheckPredicate, 19, // Predicate_immU16
/*1146*/            OPC_MoveParent,
/*1147*/            OPC_EmitMergeInputChains1_0,
/*1148*/            OPC_EmitConvertToTarget, 2,
/*1150*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SETC_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                    // Src: (intrinsic_void 5927:iPTR, GRRegs:i32:$a, (imm:i32)<<P:Predicate_immU16>>:$b) - Complexity = 12
                    // Dst: (SETC_lru6 GRRegs:i32:$a, (imm:i32):$b)
/*1158*/          0, /*End of Scope*/
/*1159*/        /*Scope*/ 9, /*->1169*/
/*1160*/          OPC_EmitMergeInputChains1_0,
/*1161*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SETC_l2r), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                  // Src: (intrinsic_void 5927:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                  // Dst: (SETC_l2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1169*/        0, /*End of Scope*/
/*1170*/      /*Scope*/ 39, /*->1210*/
/*1171*/        OPC_CheckChild1Integer, 47|128,46/*5935*/, 
/*1174*/        OPC_RecordChild2, // #1 = $a
/*1175*/        OPC_MoveChild, 2,
/*1177*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1180*/        OPC_Scope, 13, /*->1195*/ // 2 children in Scope
/*1182*/          OPC_CheckPredicate, 18, // Predicate_immU6
/*1184*/          OPC_MoveParent,
/*1185*/          OPC_EmitMergeInputChains1_0,
/*1186*/          OPC_EmitConvertToTarget, 1,
/*1188*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SETSR_u6), 0|OPFL_Chain,
                      0/*#VTs*/, 1/*#Ops*/, 2, 
                  // Src: (intrinsic_void 5935:iPTR, (imm:i32)<<P:Predicate_immU6>>:$a) - Complexity = 12
                  // Dst: (SETSR_u6 (imm:i32):$a)
/*1195*/        /*Scope*/ 13, /*->1209*/
/*1196*/          OPC_CheckPredicate, 19, // Predicate_immU16
/*1198*/          OPC_MoveParent,
/*1199*/          OPC_EmitMergeInputChains1_0,
/*1200*/          OPC_EmitConvertToTarget, 1,
/*1202*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SETSR_lu6), 0|OPFL_Chain,
                      0/*#VTs*/, 1/*#Ops*/, 2, 
                  // Src: (intrinsic_void 5935:iPTR, (imm:i32)<<P:Predicate_immU16>>:$a) - Complexity = 12
                  // Dst: (SETSR_lu6 (imm:i32):$a)
/*1209*/        0, /*End of Scope*/
/*1210*/      /*Scope*/ 39, /*->1250*/
/*1211*/        OPC_CheckChild1Integer, 9|128,46/*5897*/, 
/*1214*/        OPC_RecordChild2, // #1 = $a
/*1215*/        OPC_MoveChild, 2,
/*1217*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1220*/        OPC_Scope, 13, /*->1235*/ // 2 children in Scope
/*1222*/          OPC_CheckPredicate, 18, // Predicate_immU6
/*1224*/          OPC_MoveParent,
/*1225*/          OPC_EmitMergeInputChains1_0,
/*1226*/          OPC_EmitConvertToTarget, 1,
/*1228*/          OPC_MorphNodeTo, TARGET_VAL(XCore::CLRSR_u6), 0|OPFL_Chain,
                      0/*#VTs*/, 1/*#Ops*/, 2, 
                  // Src: (intrinsic_void 5897:iPTR, (imm:i32)<<P:Predicate_immU6>>:$a) - Complexity = 12
                  // Dst: (CLRSR_u6 (imm:i32):$a)
/*1235*/        /*Scope*/ 13, /*->1249*/
/*1236*/          OPC_CheckPredicate, 19, // Predicate_immU16
/*1238*/          OPC_MoveParent,
/*1239*/          OPC_EmitMergeInputChains1_0,
/*1240*/          OPC_EmitConvertToTarget, 1,
/*1242*/          OPC_MorphNodeTo, TARGET_VAL(XCore::CLRSR_lu6), 0|OPFL_Chain,
                      0/*#VTs*/, 1/*#Ops*/, 2, 
                  // Src: (intrinsic_void 5897:iPTR, (imm:i32)<<P:Predicate_immU16>>:$a) - Complexity = 12
                  // Dst: (CLRSR_lu6 (imm:i32):$a)
/*1249*/        0, /*End of Scope*/
/*1250*/      /*Scope*/ 39, /*->1290*/
/*1251*/        OPC_CheckChild1Integer, 35|128,46/*5923*/, 
/*1254*/        OPC_RecordChild2, // #1 = $r
/*1255*/        OPC_CheckChild2Type, MVT::i32,
/*1257*/        OPC_RecordChild3, // #2 = $val
/*1258*/        OPC_Scope, 19, /*->1279*/ // 2 children in Scope
/*1260*/          OPC_MoveChild, 3,
/*1262*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1265*/          OPC_CheckPredicate, 0, // Predicate_immUs
/*1267*/          OPC_MoveParent,
/*1268*/          OPC_EmitMergeInputChains1_0,
/*1269*/          OPC_EmitConvertToTarget, 2,
/*1271*/          OPC_MorphNodeTo, TARGET_VAL(XCore::OUTCT_rus), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                  // Src: (intrinsic_void 5923:iPTR, GRRegs:i32:$r, (imm:i32)<<P:Predicate_immUs>>:$val) - Complexity = 12
                  // Dst: (OUTCT_rus GRRegs:i32:$r, (imm:i32):$val)
/*1279*/        /*Scope*/ 9, /*->1289*/
/*1280*/          OPC_EmitMergeInputChains1_0,
/*1281*/          OPC_MorphNodeTo, TARGET_VAL(XCore::OUTCT_2r), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                  // Src: (intrinsic_void 5923:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                  // Dst: (OUTCT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1289*/        0, /*End of Scope*/
/*1290*/      /*Scope*/ 39, /*->1330*/
/*1291*/        OPC_CheckChild1Integer, 6|128,46/*5894*/, 
/*1294*/        OPC_RecordChild2, // #1 = $r
/*1295*/        OPC_CheckChild2Type, MVT::i32,
/*1297*/        OPC_RecordChild3, // #2 = $val
/*1298*/        OPC_Scope, 19, /*->1319*/ // 2 children in Scope
/*1300*/          OPC_MoveChild, 3,
/*1302*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1305*/          OPC_CheckPredicate, 0, // Predicate_immUs
/*1307*/          OPC_MoveParent,
/*1308*/          OPC_EmitMergeInputChains1_0,
/*1309*/          OPC_EmitConvertToTarget, 2,
/*1311*/          OPC_MorphNodeTo, TARGET_VAL(XCore::CHKCT_rus), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                  // Src: (intrinsic_void 5894:iPTR, GRRegs:i32:$r, (imm:i32)<<P:Predicate_immUs>>:$val) - Complexity = 12
                  // Dst: (CHKCT_rus GRRegs:i32:$r, (imm:i32):$val)
/*1319*/        /*Scope*/ 9, /*->1329*/
/*1320*/          OPC_EmitMergeInputChains1_0,
/*1321*/          OPC_MorphNodeTo, TARGET_VAL(XCore::CHKCT_2r), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                  // Src: (intrinsic_void 5894:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                  // Dst: (CHKCT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1329*/        0, /*End of Scope*/
/*1330*/      /*Scope*/ 16, /*->1347*/
/*1331*/        OPC_CheckChild1Integer, 45|128,46/*5933*/, 
/*1334*/        OPC_RecordChild2, // #1 = $r
/*1335*/        OPC_CheckChild2Type, MVT::i32,
/*1337*/        OPC_RecordChild3, // #2 = $val
/*1338*/        OPC_EmitMergeInputChains1_0,
/*1339*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETPT_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 5933:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                // Dst: (SETPT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1347*/      /*Scope*/ 16, /*->1364*/
/*1348*/        OPC_CheckChild1Integer, 37|128,46/*5925*/, 
/*1351*/        OPC_RecordChild2, // #1 = $r
/*1352*/        OPC_CheckChild2Type, MVT::i32,
/*1354*/        OPC_RecordChild3, // #2 = $val
/*1355*/        OPC_EmitMergeInputChains1_0,
/*1356*/        OPC_MorphNodeTo, TARGET_VAL(XCore::OUTT_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 5925:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                // Dst: (OUTT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1364*/      /*Scope*/ 16, /*->1381*/
/*1365*/        OPC_CheckChild1Integer, 34|128,46/*5922*/, 
/*1368*/        OPC_RecordChild2, // #1 = $r
/*1369*/        OPC_CheckChild2Type, MVT::i32,
/*1371*/        OPC_RecordChild3, // #2 = $val
/*1372*/        OPC_EmitMergeInputChains1_0,
/*1373*/        OPC_MorphNodeTo, TARGET_VAL(XCore::OUT_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 5922:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                // Dst: (OUT_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1381*/      /*Scope*/ 16, /*->1398*/
/*1382*/        OPC_CheckChild1Integer, 41|128,46/*5929*/, 
/*1385*/        OPC_RecordChild2, // #1 = $r
/*1386*/        OPC_CheckChild2Type, MVT::i32,
/*1388*/        OPC_RecordChild3, // #2 = $val
/*1389*/        OPC_EmitMergeInputChains1_0,
/*1390*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETD_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 5929:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                // Dst: (SETD_2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1398*/      /*Scope*/ 16, /*->1415*/
/*1399*/        OPC_CheckChild1Integer, 44|128,46/*5932*/, 
/*1402*/        OPC_RecordChild2, // #1 = $src1
/*1403*/        OPC_CheckChild2Type, MVT::i32,
/*1405*/        OPC_RecordChild3, // #2 = $src2
/*1406*/        OPC_EmitMergeInputChains1_0,
/*1407*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETPSC_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 5932:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
                // Dst: (SETPSC_2r GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1415*/      /*Scope*/ 18, /*->1434*/
/*1416*/        OPC_CheckChild1Integer, 29|128,46/*5917*/, 
/*1419*/        OPC_RecordChild2, // #1 = $t
/*1420*/        OPC_CheckChild2Type, MVT::i32,
/*1422*/        OPC_RecordChild3, // #2 = $src
/*1423*/        OPC_CheckChild3Type, MVT::i32,
/*1425*/        OPC_EmitMergeInputChains1_0,
/*1426*/        OPC_MorphNodeTo, TARGET_VAL(XCore::INITSP_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 2, 1, 
                // Src: (intrinsic_void 5917:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
                // Dst: (INITSP_2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1434*/      /*Scope*/ 18, /*->1453*/
/*1435*/        OPC_CheckChild1Integer, 28|128,46/*5916*/, 
/*1438*/        OPC_RecordChild2, // #1 = $t
/*1439*/        OPC_CheckChild2Type, MVT::i32,
/*1441*/        OPC_RecordChild3, // #2 = $src
/*1442*/        OPC_CheckChild3Type, MVT::i32,
/*1444*/        OPC_EmitMergeInputChains1_0,
/*1445*/        OPC_MorphNodeTo, TARGET_VAL(XCore::INITPC_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 2, 1, 
                // Src: (intrinsic_void 5916:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
                // Dst: (INITPC_2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1453*/      /*Scope*/ 18, /*->1472*/
/*1454*/        OPC_CheckChild1Integer, 25|128,46/*5913*/, 
/*1457*/        OPC_RecordChild2, // #1 = $t
/*1458*/        OPC_CheckChild2Type, MVT::i32,
/*1460*/        OPC_RecordChild3, // #2 = $src
/*1461*/        OPC_CheckChild3Type, MVT::i32,
/*1463*/        OPC_EmitMergeInputChains1_0,
/*1464*/        OPC_MorphNodeTo, TARGET_VAL(XCore::INITCP_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 2, 1, 
                // Src: (intrinsic_void 5913:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
                // Dst: (INITCP_2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1472*/      /*Scope*/ 18, /*->1491*/
/*1473*/        OPC_CheckChild1Integer, 26|128,46/*5914*/, 
/*1476*/        OPC_RecordChild2, // #1 = $t
/*1477*/        OPC_CheckChild2Type, MVT::i32,
/*1479*/        OPC_RecordChild3, // #2 = $src
/*1480*/        OPC_CheckChild3Type, MVT::i32,
/*1482*/        OPC_EmitMergeInputChains1_0,
/*1483*/        OPC_MorphNodeTo, TARGET_VAL(XCore::INITDP_2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 2, 1, 
                // Src: (intrinsic_void 5914:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
                // Dst: (INITDP_2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1491*/      /*Scope*/ 16, /*->1508*/
/*1492*/        OPC_CheckChild1Integer, 48|128,46/*5936*/, 
/*1495*/        OPC_RecordChild2, // #1 = $r
/*1496*/        OPC_CheckChild2Type, MVT::i32,
/*1498*/        OPC_RecordChild3, // #2 = $val
/*1499*/        OPC_EmitMergeInputChains1_0,
/*1500*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETTW_l2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 5936:iPTR, GRRegs:i32:$r, GRRegs:i32:$val) - Complexity = 8
                // Dst: (SETTW_l2r GRRegs:i32:$r, GRRegs:i32:$val)
/*1508*/      /*Scope*/ 14, /*->1523*/
/*1509*/        OPC_CheckChild1Integer, 43|128,46/*5931*/, 
/*1512*/        OPC_RecordChild2, // #1 = $src1
/*1513*/        OPC_RecordChild3, // #2 = $src2
/*1514*/        OPC_EmitMergeInputChains1_0,
/*1515*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETPS_l2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 5931:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
                // Dst: (SETPS_l2r GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1523*/      /*Scope*/ 18, /*->1542*/
/*1524*/        OPC_CheckChild1Integer, 27|128,46/*5915*/, 
/*1527*/        OPC_RecordChild2, // #1 = $t
/*1528*/        OPC_CheckChild2Type, MVT::i32,
/*1530*/        OPC_RecordChild3, // #2 = $src
/*1531*/        OPC_CheckChild3Type, MVT::i32,
/*1533*/        OPC_EmitMergeInputChains1_0,
/*1534*/        OPC_MorphNodeTo, TARGET_VAL(XCore::INITLR_l2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 2, 1, 
                // Src: (intrinsic_void 5915:iPTR, GRRegs:i32:$t, GRRegs:i32:$src) - Complexity = 8
                // Dst: (INITLR_l2r GRRegs:i32:$src, GRRegs:i32:$t)
/*1542*/      /*Scope*/ 18, /*->1561*/
/*1543*/        OPC_CheckChild1Integer, 40|128,46/*5928*/, 
/*1546*/        OPC_RecordChild2, // #1 = $src1
/*1547*/        OPC_CheckChild2Type, MVT::i32,
/*1549*/        OPC_RecordChild3, // #2 = $src2
/*1550*/        OPC_CheckChild3Type, MVT::i32,
/*1552*/        OPC_EmitMergeInputChains1_0,
/*1553*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETCLK_l2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 5928:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
                // Dst: (SETCLK_l2r GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1561*/      /*Scope*/ 18, /*->1580*/
/*1562*/        OPC_CheckChild1Integer, 46|128,46/*5934*/, 
/*1565*/        OPC_RecordChild2, // #1 = $src1
/*1566*/        OPC_CheckChild2Type, MVT::i32,
/*1568*/        OPC_RecordChild3, // #2 = $src2
/*1569*/        OPC_CheckChild3Type, MVT::i32,
/*1571*/        OPC_EmitMergeInputChains1_0,
/*1572*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETRDY_l2r), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (intrinsic_void 5934:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
                // Dst: (SETRDY_l2r GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1580*/      /*Scope*/ 14, /*->1595*/
/*1581*/        OPC_CheckChild1Integer, 33|128,46/*5921*/, 
/*1584*/        OPC_RecordChild2, // #1 = $a
/*1585*/        OPC_CheckChild2Type, MVT::i32,
/*1587*/        OPC_EmitMergeInputChains1_0,
/*1588*/        OPC_MorphNodeTo, TARGET_VAL(XCore::MSYNC_1r), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 5921:iPTR, GRRegs:i32:$a) - Complexity = 8
                // Dst: (MSYNC_1r GRRegs:i32:$a)
/*1595*/      /*Scope*/ 14, /*->1610*/
/*1596*/        OPC_CheckChild1Integer, 32|128,46/*5920*/, 
/*1599*/        OPC_RecordChild2, // #1 = $a
/*1600*/        OPC_CheckChild2Type, MVT::i32,
/*1602*/        OPC_EmitMergeInputChains1_0,
/*1603*/        OPC_MorphNodeTo, TARGET_VAL(XCore::MJOIN_1r), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 5920:iPTR, GRRegs:i32:$a) - Complexity = 8
                // Dst: (MJOIN_1r GRRegs:i32:$a)
/*1610*/      /*Scope*/ 14, /*->1625*/
/*1611*/        OPC_CheckChild1Integer, 52|128,46/*5940*/, 
/*1614*/        OPC_RecordChild2, // #1 = $a
/*1615*/        OPC_CheckChild2Type, MVT::i32,
/*1617*/        OPC_EmitMergeInputChains1_0,
/*1618*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SYNCR_1r), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 5940:iPTR, GRRegs:i32:$a) - Complexity = 8
                // Dst: (SYNCR_1r GRRegs:i32:$a)
/*1625*/      /*Scope*/ 14, /*->1640*/
/*1626*/        OPC_CheckChild1Integer, 15|128,46/*5903*/, 
/*1629*/        OPC_RecordChild2, // #1 = $a
/*1630*/        OPC_CheckChild2Type, MVT::i32,
/*1632*/        OPC_EmitMergeInputChains1_0,
/*1633*/        OPC_MorphNodeTo, TARGET_VAL(XCore::FREER_1r), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 5903:iPTR, GRRegs:i32:$a) - Complexity = 8
                // Dst: (FREER_1r GRRegs:i32:$a)
/*1640*/      /*Scope*/ 20, /*->1661*/
/*1641*/        OPC_CheckChild1Integer, 49|128,46/*5937*/, 
/*1644*/        OPC_RecordChild2, // #1 = $a
/*1645*/        OPC_CheckChild2Type, MVT::i32,
/*1647*/        OPC_RecordChild3, // #2 = physreg input R11
/*1648*/        OPC_CheckChild3Type, MVT::i32,
/*1650*/        OPC_EmitMergeInputChains1_0,
/*1651*/        OPC_EmitCopyToReg, 2, XCore::R11,
/*1654*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETV_1r), 0|OPFL_Chain|OPFL_GlueInput,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 5937:iPTR, GRRegs:i32:$a, R11:i32) - Complexity = 8
                // Dst: (SETV_1r GRRegs:i32:$a)
/*1661*/      /*Scope*/ 20, /*->1682*/
/*1662*/        OPC_CheckChild1Integer, 42|128,46/*5930*/, 
/*1665*/        OPC_RecordChild2, // #1 = $a
/*1666*/        OPC_CheckChild2Type, MVT::i32,
/*1668*/        OPC_RecordChild3, // #2 = physreg input R11
/*1669*/        OPC_CheckChild3Type, MVT::i32,
/*1671*/        OPC_EmitMergeInputChains1_0,
/*1672*/        OPC_EmitCopyToReg, 2, XCore::R11,
/*1675*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SETEV_1r), 0|OPFL_Chain|OPFL_GlueInput,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 5930:iPTR, GRRegs:i32:$a, R11:i32) - Complexity = 8
                // Dst: (SETEV_1r GRRegs:i32:$a)
/*1682*/      /*Scope*/ 14, /*->1697*/
/*1683*/        OPC_CheckChild1Integer, 12|128,46/*5900*/, 
/*1686*/        OPC_RecordChild2, // #1 = $a
/*1687*/        OPC_CheckChild2Type, MVT::i32,
/*1689*/        OPC_EmitMergeInputChains1_0,
/*1690*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EDU_1r), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 5900:iPTR, GRRegs:i32:$a) - Complexity = 8
                // Dst: (EDU_1r GRRegs:i32:$a)
/*1697*/      /*Scope*/ 14, /*->1712*/
/*1698*/        OPC_CheckChild1Integer, 13|128,46/*5901*/, 
/*1701*/        OPC_RecordChild2, // #1 = $a
/*1702*/        OPC_CheckChild2Type, MVT::i32,
/*1704*/        OPC_EmitMergeInputChains1_0,
/*1705*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EEU_1r), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 5901:iPTR, GRRegs:i32:$a) - Complexity = 8
                // Dst: (EEU_1r GRRegs:i32:$a)
/*1712*/      /*Scope*/ 14, /*->1727*/
/*1713*/        OPC_CheckChild1Integer, 8|128,46/*5896*/, 
/*1716*/        OPC_RecordChild2, // #1 = $a
/*1717*/        OPC_CheckChild2Type, MVT::i32,
/*1719*/        OPC_EmitMergeInputChains1_0,
/*1720*/        OPC_MorphNodeTo, TARGET_VAL(XCore::CLRPT_1R), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (intrinsic_void 5896:iPTR, GRRegs:i32:$a) - Complexity = 8
                // Dst: (CLRPT_1R GRRegs:i32:$a)
/*1727*/      /*Scope*/ 10, /*->1738*/
/*1728*/        OPC_CheckChild1Integer, 7|128,46/*5895*/, 
/*1731*/        OPC_EmitMergeInputChains1_0,
/*1732*/        OPC_MorphNodeTo, TARGET_VAL(XCore::CLRE_0R), 0|OPFL_Chain,
                    0/*#VTs*/, 0/*#Ops*/, 
                // Src: (intrinsic_void 5895:iPTR) - Complexity = 8
                // Dst: (CLRE_0R)
/*1738*/      /*Scope*/ 10, /*->1749*/
/*1739*/        OPC_CheckChild1Integer, 51|128,46/*5939*/, 
/*1742*/        OPC_EmitMergeInputChains1_0,
/*1743*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SSYNC_0r), 0|OPFL_Chain,
                    0/*#VTs*/, 0/*#Ops*/, 
                // Src: (intrinsic_void 5939:iPTR) - Complexity = 8
                // Dst: (SSYNC_0r)
/*1749*/      0, /*End of Scope*/
/*1750*/    /*SwitchOpcode*/ 119, TARGET_VAL(ISD::INTRINSIC_WO_CHAIN),// ->1872
/*1753*/      OPC_Scope, 37, /*->1792*/ // 5 children in Scope
/*1755*/        OPC_CheckChild0Integer, 50|128,46/*5938*/, 
/*1758*/        OPC_RecordChild1, // #0 = $src1
/*1759*/        OPC_RecordChild2, // #1 = $src2
/*1760*/        OPC_Scope, 19, /*->1781*/ // 2 children in Scope
/*1762*/          OPC_MoveChild, 2,
/*1764*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1767*/          OPC_CheckPredicate, 17, // Predicate_immBitp
/*1769*/          OPC_MoveParent,
/*1770*/          OPC_EmitConvertToTarget, 1,
/*1772*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (intrinsic_wo_chain:i32 5938:iPTR, GRRegs:i32:$src1, (imm:i32)<<P:Predicate_immBitp>>:$src2) - Complexity = 12
                  // Dst: (SEXT_rus:i32 GRRegs:i32:$src1, (imm:i32):$src2)
/*1781*/        /*Scope*/ 9, /*->1791*/
/*1782*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_2r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (intrinsic_wo_chain:i32 5938:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
                  // Dst: (SEXT_2r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1791*/        0, /*End of Scope*/
/*1792*/      /*Scope*/ 37, /*->1830*/
/*1793*/        OPC_CheckChild0Integer, 56|128,46/*5944*/, 
/*1796*/        OPC_RecordChild1, // #0 = $src1
/*1797*/        OPC_RecordChild2, // #1 = $src2
/*1798*/        OPC_Scope, 19, /*->1819*/ // 2 children in Scope
/*1800*/          OPC_MoveChild, 2,
/*1802*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1805*/          OPC_CheckPredicate, 17, // Predicate_immBitp
/*1807*/          OPC_MoveParent,
/*1808*/          OPC_EmitConvertToTarget, 1,
/*1810*/          OPC_MorphNodeTo, TARGET_VAL(XCore::ZEXT_rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (intrinsic_wo_chain:i32 5944:iPTR, GRRegs:i32:$src1, (imm:i32)<<P:Predicate_immBitp>>:$src2) - Complexity = 12
                  // Dst: (ZEXT_rus:i32 GRRegs:i32:$src1, (imm:i32):$src2)
/*1819*/        /*Scope*/ 9, /*->1829*/
/*1820*/          OPC_MorphNodeTo, TARGET_VAL(XCore::ZEXT_2r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (intrinsic_wo_chain:i32 5944:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2) - Complexity = 8
                  // Dst: (ZEXT_2r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2)
/*1829*/        0, /*End of Scope*/
/*1830*/      /*Scope*/ 16, /*->1847*/
/*1831*/        OPC_CheckChild0Integer, 10|128,46/*5898*/, 
/*1834*/        OPC_RecordChild1, // #0 = $src1
/*1835*/        OPC_RecordChild2, // #1 = $src2
/*1836*/        OPC_RecordChild3, // #2 = $src3
/*1837*/        OPC_MorphNodeTo, TARGET_VAL(XCore::CRC_l3r), 0,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (intrinsic_wo_chain:i32 5898:iPTR, GRRegs:i32:$src1, GRRegs:i32:$src2, GRRegs:i32:$src3) - Complexity = 8
                // Dst: (CRC_l3r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2, GRRegs:i32:$src3)
/*1847*/      /*Scope*/ 12, /*->1860*/
/*1848*/        OPC_CheckChild0Integer, 4|128,46/*5892*/, 
/*1851*/        OPC_RecordChild1, // #0 = $src
/*1852*/        OPC_MorphNodeTo, TARGET_VAL(XCore::BITREV_l2r), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (intrinsic_wo_chain:i32 5892:iPTR, GRRegs:i32:$src) - Complexity = 8
                // Dst: (BITREV_l2r:i32 GRRegs:i32:$src)
/*1860*/      /*Scope*/ 10, /*->1871*/
/*1861*/        OPC_CheckChild0Integer, 18|128,46/*5906*/, 
/*1864*/        OPC_MorphNodeTo, TARGET_VAL(XCore::GETID_0R), 0,
                    1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
                // Src: (intrinsic_wo_chain:i32 5906:iPTR) - Complexity = 8
                // Dst: (GETID_0R:i32)
/*1871*/      0, /*End of Scope*/
/*1872*/    /*SwitchOpcode*/ 121|128,1/*249*/, TARGET_VAL(ISD::INTRINSIC_W_CHAIN),// ->2125
/*1876*/      OPC_RecordNode, // #0 = 'intrinsic_w_chain' chained node
/*1877*/      OPC_Scope, 25, /*->1904*/ // 15 children in Scope
/*1879*/        OPC_CheckChild1Integer, 20|128,46/*5908*/, 
/*1882*/        OPC_RecordChild2, // #1 = $type
/*1883*/        OPC_MoveChild, 2,
/*1885*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1888*/        OPC_CheckPredicate, 0, // Predicate_immUs
/*1890*/        OPC_MoveParent,
/*1891*/        OPC_CheckType, MVT::i32,
/*1893*/        OPC_EmitMergeInputChains1_0,
/*1894*/        OPC_EmitConvertToTarget, 1,
/*1896*/        OPC_MorphNodeTo, TARGET_VAL(XCore::GETR_rus), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                // Src: (intrinsic_w_chain:i32 5908:iPTR, (imm:i32)<<P:Predicate_immUs>>:$type) - Complexity = 12
                // Dst: (GETR_rus:i32 (imm:i32):$type)
/*1904*/      /*Scope*/ 15, /*->1920*/
/*1905*/        OPC_CheckChild1Integer, 22|128,46/*5910*/, 
/*1908*/        OPC_RecordChild2, // #1 = $r
/*1909*/        OPC_CheckChild2Type, MVT::i32,
/*1911*/        OPC_EmitMergeInputChains1_0,
/*1912*/        OPC_MorphNodeTo, TARGET_VAL(XCore::GETTS_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5910:iPTR, GRRegs:i32:$r) - Complexity = 8
                // Dst: (GETTS_2r:i32 GRRegs:i32:$r)
/*1920*/      /*Scope*/ 17, /*->1938*/
/*1921*/        OPC_CheckChild1Integer, 36|128,46/*5924*/, 
/*1924*/        OPC_RecordChild2, // #1 = $r
/*1925*/        OPC_CheckChild2Type, MVT::i32,
/*1927*/        OPC_RecordChild3, // #2 = $src
/*1928*/        OPC_EmitMergeInputChains1_0,
/*1929*/        OPC_MorphNodeTo, TARGET_VAL(XCore::OUTSHR_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
                // Src: (intrinsic_w_chain:i32 5924:iPTR, GRRegs:i32:$r, GRRegs:i32:$src) - Complexity = 8
                // Dst: (OUTSHR_2r:i32 GRRegs:i32:$src, GRRegs:i32:$r)
/*1938*/      /*Scope*/ 15, /*->1954*/
/*1939*/        OPC_CheckChild1Integer, 24|128,46/*5912*/, 
/*1942*/        OPC_RecordChild2, // #1 = $r
/*1943*/        OPC_CheckChild2Type, MVT::i32,
/*1945*/        OPC_EmitMergeInputChains1_0,
/*1946*/        OPC_MorphNodeTo, TARGET_VAL(XCore::INCT_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5912:iPTR, GRRegs:i32:$r) - Complexity = 8
                // Dst: (INCT_2r:i32 GRRegs:i32:$r)
/*1954*/      /*Scope*/ 15, /*->1970*/
/*1955*/        OPC_CheckChild1Integer, 31|128,46/*5919*/, 
/*1958*/        OPC_RecordChild2, // #1 = $r
/*1959*/        OPC_CheckChild2Type, MVT::i32,
/*1961*/        OPC_EmitMergeInputChains1_0,
/*1962*/        OPC_MorphNodeTo, TARGET_VAL(XCore::INT_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5919:iPTR, GRRegs:i32:$r) - Complexity = 8
                // Dst: (INT_2r:i32 GRRegs:i32:$r)
/*1970*/      /*Scope*/ 15, /*->1986*/
/*1971*/        OPC_CheckChild1Integer, 23|128,46/*5911*/, 
/*1974*/        OPC_RecordChild2, // #1 = $r
/*1975*/        OPC_CheckChild2Type, MVT::i32,
/*1977*/        OPC_EmitMergeInputChains1_0,
/*1978*/        OPC_MorphNodeTo, TARGET_VAL(XCore::IN_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5911:iPTR, GRRegs:i32:$r) - Complexity = 8
                // Dst: (IN_2r:i32 GRRegs:i32:$r)
/*1986*/      /*Scope*/ 17, /*->2004*/
/*1987*/        OPC_CheckChild1Integer, 30|128,46/*5918*/, 
/*1990*/        OPC_RecordChild2, // #1 = $r
/*1991*/        OPC_CheckChild2Type, MVT::i32,
/*1993*/        OPC_RecordChild3, // #2 = $src
/*1994*/        OPC_EmitMergeInputChains1_0,
/*1995*/        OPC_MorphNodeTo, TARGET_VAL(XCore::INSHR_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1, 
                // Src: (intrinsic_w_chain:i32 5918:iPTR, GRRegs:i32:$r, GRRegs:i32:$src) - Complexity = 8
                // Dst: (INSHR_2r:i32 GRRegs:i32:$src, GRRegs:i32:$r)
/*2004*/      /*Scope*/ 15, /*->2020*/
/*2005*/        OPC_CheckChild1Integer, 53|128,46/*5941*/, 
/*2008*/        OPC_RecordChild2, // #1 = $src
/*2009*/        OPC_CheckChild2Type, MVT::i32,
/*2011*/        OPC_EmitMergeInputChains1_0,
/*2012*/        OPC_MorphNodeTo, TARGET_VAL(XCore::TESTCT_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5941:iPTR, GRRegs:i32:$src) - Complexity = 8
                // Dst: (TESTCT_2r:i32 GRRegs:i32:$src)
/*2020*/      /*Scope*/ 15, /*->2036*/
/*2021*/        OPC_CheckChild1Integer, 54|128,46/*5942*/, 
/*2024*/        OPC_RecordChild2, // #1 = $src
/*2025*/        OPC_CheckChild2Type, MVT::i32,
/*2027*/        OPC_EmitMergeInputChains1_0,
/*2028*/        OPC_MorphNodeTo, TARGET_VAL(XCore::TESTWCT_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5942:iPTR, GRRegs:i32:$src) - Complexity = 8
                // Dst: (TESTWCT_2r:i32 GRRegs:i32:$src)
/*2036*/      /*Scope*/ 17, /*->2054*/
/*2037*/        OPC_CheckChild1Integer, 21|128,46/*5909*/, 
/*2040*/        OPC_RecordChild2, // #1 = $r
/*2041*/        OPC_CheckChild2Type, MVT::i32,
/*2043*/        OPC_CheckType, MVT::i32,
/*2045*/        OPC_EmitMergeInputChains1_0,
/*2046*/        OPC_MorphNodeTo, TARGET_VAL(XCore::GETST_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5909:iPTR, GRRegs:i32:$r) - Complexity = 8
                // Dst: (GETST_2r:i32 GRRegs:i32:$r)
/*2054*/      /*Scope*/ 15, /*->2070*/
/*2055*/        OPC_CheckChild1Integer, 38|128,46/*5926*/, 
/*2058*/        OPC_RecordChild2, // #1 = $src
/*2059*/        OPC_CheckChild2Type, MVT::i32,
/*2061*/        OPC_EmitMergeInputChains1_0,
/*2062*/        OPC_MorphNodeTo, TARGET_VAL(XCore::PEEK_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5926:iPTR, GRRegs:i32:$src) - Complexity = 8
                // Dst: (PEEK_2r:i32 GRRegs:i32:$src)
/*2070*/      /*Scope*/ 15, /*->2086*/
/*2071*/        OPC_CheckChild1Integer, 14|128,46/*5902*/, 
/*2074*/        OPC_RecordChild2, // #1 = $src
/*2075*/        OPC_CheckChild2Type, MVT::i32,
/*2077*/        OPC_EmitMergeInputChains1_0,
/*2078*/        OPC_MorphNodeTo, TARGET_VAL(XCore::ENDIN_2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5902:iPTR, GRRegs:i32:$src) - Complexity = 8
                // Dst: (ENDIN_2r:i32 GRRegs:i32:$src)
/*2086*/      /*Scope*/ 13, /*->2100*/
/*2087*/        OPC_CheckChild1Integer, 19|128,46/*5907*/, 
/*2090*/        OPC_RecordChild2, // #1 = $src
/*2091*/        OPC_EmitMergeInputChains1_0,
/*2092*/        OPC_MorphNodeTo, TARGET_VAL(XCore::GETPS_l2r), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (intrinsic_w_chain:i32 5907:iPTR, GRRegs:i32:$src) - Complexity = 8
                // Dst: (GETPS_l2r:i32 GRRegs:i32:$src)
/*2100*/      /*Scope*/ 11, /*->2112*/
/*2101*/        OPC_CheckChild1Integer, 16|128,46/*5904*/, 
/*2104*/        OPC_EmitMergeInputChains1_0,
/*2105*/        OPC_MorphNodeTo, TARGET_VAL(XCore::GETED_0R), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
                // Src: (intrinsic_w_chain:i32 5904:iPTR) - Complexity = 8
                // Dst: (GETED_0R:i32)
/*2112*/      /*Scope*/ 11, /*->2124*/
/*2113*/        OPC_CheckChild1Integer, 17|128,46/*5905*/, 
/*2116*/        OPC_EmitMergeInputChains1_0,
/*2117*/        OPC_MorphNodeTo, TARGET_VAL(XCore::GETET_0R), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
                // Src: (intrinsic_w_chain:i32 5905:iPTR) - Complexity = 8
                // Dst: (GETET_0R:i32)
/*2124*/      0, /*End of Scope*/
/*2125*/    /*SwitchOpcode*/ 106, TARGET_VAL(ISD::SUB),// ->2234
/*2128*/      OPC_Scope, 35, /*->2165*/ // 3 children in Scope
/*2130*/        OPC_RecordChild0, // #0 = $addr
/*2131*/        OPC_MoveChild, 1,
/*2133*/        OPC_CheckOpcode, TARGET_VAL(ISD::SHL),
/*2136*/        OPC_RecordChild0, // #1 = $offset
/*2137*/        OPC_Scope, 12, /*->2151*/ // 2 children in Scope
/*2139*/          OPC_CheckChild1Integer, 2, 
/*2141*/          OPC_MoveParent,
/*2142*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWB_l3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 2:i32)) - Complexity = 11
                  // Dst: (LDAWB_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*2151*/        /*Scope*/ 12, /*->2164*/
/*2152*/          OPC_CheckChild1Integer, 1, 
/*2154*/          OPC_MoveParent,
/*2155*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LDA16B_l3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i32 GRRegs:i32:$addr, (shl:i32 GRRegs:i32:$offset, 1:i32)) - Complexity = 11
                  // Dst: (LDA16B_l3r:i32 GRRegs:i32:$addr, GRRegs:i32:$offset)
/*2164*/        0, /*End of Scope*/
/*2165*/      /*Scope*/ 11, /*->2177*/
/*2166*/        OPC_CheckChild0Integer, 0, 
/*2168*/        OPC_RecordChild1, // #0 = $b
/*2169*/        OPC_MorphNodeTo, TARGET_VAL(XCore::NEG), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (sub:i32 0:i32, GRRegs:i32:$b) - Complexity = 8
                // Dst: (NEG:i32 GRRegs:i32:$b)
/*2177*/      /*Scope*/ 55, /*->2233*/
/*2178*/        OPC_RecordChild0, // #0 = $b
/*2179*/        OPC_RecordChild1, // #1 = $c
/*2180*/        OPC_Scope, 40, /*->2222*/ // 2 children in Scope
/*2182*/          OPC_MoveChild, 1,
/*2184*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2187*/          OPC_Scope, 14, /*->2203*/ // 2 children in Scope
/*2189*/            OPC_CheckPredicate, 0, // Predicate_immUs
/*2191*/            OPC_MoveParent,
/*2192*/            OPC_EmitConvertToTarget, 1,
/*2194*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SUB_2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                    // Src: (sub:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immUs>>:$c) - Complexity = 7
                    // Dst: (SUB_2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*2203*/          /*Scope*/ 17, /*->2221*/
/*2204*/            OPC_CheckPredicate, 1, // Predicate_immUs4
/*2206*/            OPC_MoveParent,
/*2207*/            OPC_EmitConvertToTarget, 1,
/*2209*/            OPC_EmitNodeXForm, 0, 2, // div4_xform
/*2212*/            OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWB_l2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                    // Src: (sub:i32 GRRegs:i32:$addr, (imm:i32)<<P:Predicate_immUs4>>:$offset) - Complexity = 7
                    // Dst: (LDAWB_l2rus:i32 GRRegs:i32:$addr, (div4_xform:i32 (imm:i32)<<P:Predicate_immUs4>>:$offset))
/*2221*/          0, /*End of Scope*/
/*2222*/        /*Scope*/ 9, /*->2232*/
/*2223*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SUB_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (sub:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                  // Dst: (SUB_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*2232*/        0, /*End of Scope*/
/*2233*/      0, /*End of Scope*/
/*2234*/    /*SwitchOpcode*/ 98, TARGET_VAL(ISD::AND),// ->2335
/*2237*/      OPC_Scope, 28, /*->2267*/ // 3 children in Scope
/*2239*/        OPC_RecordChild0, // #0 = $src1
/*2240*/        OPC_MoveChild, 1,
/*2242*/        OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2245*/        OPC_RecordChild0, // #1 = $src2
/*2246*/        OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2257*/        OPC_MoveParent,
/*2258*/        OPC_MorphNodeTo, TARGET_VAL(XCore::ANDNOT_2r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (and:i32 GRRegs:i32:$src1, (xor:i32 GRRegs:i32:$src2, -1:i32)) - Complexity = 11
                // Dst: (ANDNOT_2r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2)
/*2267*/      /*Scope*/ 28, /*->2296*/
/*2268*/        OPC_MoveChild, 0,
/*2270*/        OPC_CheckOpcode, TARGET_VAL(ISD::XOR),
/*2273*/        OPC_RecordChild0, // #0 = $src2
/*2274*/        OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2285*/        OPC_MoveParent,
/*2286*/        OPC_RecordChild1, // #1 = $src1
/*2287*/        OPC_MorphNodeTo, TARGET_VAL(XCore::ANDNOT_2r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                // Src: (and:i32 (xor:i32 GRRegs:i32:$src2, -1:i32), GRRegs:i32:$src1) - Complexity = 11
                // Dst: (ANDNOT_2r:i32 GRRegs:i32:$src1, GRRegs:i32:$src2)
/*2296*/      /*Scope*/ 37, /*->2334*/
/*2297*/        OPC_RecordChild0, // #0 = $val
/*2298*/        OPC_RecordChild1, // #1 = $mask
/*2299*/        OPC_Scope, 22, /*->2323*/ // 2 children in Scope
/*2301*/          OPC_MoveChild, 1,
/*2303*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2306*/          OPC_CheckPredicate, 20, // Predicate_immMskBitp
/*2308*/          OPC_MoveParent,
/*2309*/          OPC_EmitConvertToTarget, 1,
/*2311*/          OPC_EmitNodeXForm, 4, 2, // msksize_xform
/*2314*/          OPC_MorphNodeTo, TARGET_VAL(XCore::ZEXT_rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3, 
                  // Src: (and:i32 GRRegs:i32:$val, (imm:i32)<<P:Predicate_immMskBitp>>:$mask) - Complexity = 7
                  // Dst: (ZEXT_rus:i32 GRRegs:i32:$val, (msksize_xform:i32 (imm:i32)<<P:Predicate_immMskBitp>>:$mask))
/*2323*/        /*Scope*/ 9, /*->2333*/
/*2324*/          OPC_MorphNodeTo, TARGET_VAL(XCore::AND_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (and:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                  // Dst: (AND_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*2333*/        0, /*End of Scope*/
/*2334*/      0, /*End of Scope*/
/*2335*/    /*SwitchOpcode*/ 37, TARGET_VAL(ISD::BRIND),// ->2375
/*2338*/      OPC_RecordNode, // #0 = 'brind' chained node
/*2339*/      OPC_Scope, 21, /*->2362*/ // 2 children in Scope
/*2341*/        OPC_MoveChild, 1,
/*2343*/        OPC_CheckOpcode, TARGET_VAL(ISD::INTRINSIC_W_CHAIN),
/*2346*/        OPC_RecordNode, // #1 = 'intrinsic_w_chain' chained node
/*2347*/        OPC_CheckFoldableChainNode,
/*2348*/        OPC_CheckChild1Integer, 55|128,46/*5943*/, 
/*2351*/        OPC_MoveParent,
/*2352*/        OPC_EmitMergeInputChains, 2, 0, 1, 
/*2356*/        OPC_MorphNodeTo, TARGET_VAL(XCore::WAITEU_0R), 0|OPFL_Chain,
                    0/*#VTs*/, 0/*#Ops*/, 
                // Src: (brind (intrinsic_w_chain:iPTR 5943:iPTR)) - Complexity = 11
                // Dst: (WAITEU_0R)
/*2362*/      /*Scope*/ 11, /*->2374*/
/*2363*/        OPC_RecordChild1, // #1 = $a
/*2364*/        OPC_CheckChild1Type, MVT::i32,
/*2366*/        OPC_EmitMergeInputChains1_0,
/*2367*/        OPC_MorphNodeTo, TARGET_VAL(XCore::BAU_1r), 0|OPFL_Chain,
                    0/*#VTs*/, 1/*#Ops*/, 1, 
                // Src: (brind GRRegs:i32:$a) - Complexity = 3
                // Dst: (BAU_1r GRRegs:i32:$a)
/*2374*/      0, /*End of Scope*/
/*2375*/    /*SwitchOpcode*/ 105|128,2/*361*/, TARGET_VAL(ISD::BRCOND),// ->2740
/*2379*/      OPC_RecordNode, // #0 = 'brcond' chained node
/*2380*/      OPC_Scope, 82|128,2/*338*/, /*->2721*/ // 2 children in Scope
/*2383*/        OPC_MoveChild, 1,
/*2385*/        OPC_CheckOpcode, TARGET_VAL(ISD::SETCC),
/*2388*/        OPC_RecordChild0, // #1 = $lhs
/*2389*/        OPC_Scope, 81, /*->2472*/ // 4 children in Scope
/*2391*/          OPC_CheckChild1Integer, 0, 
/*2393*/          OPC_MoveChild, 2,
/*2395*/          OPC_Scope, 20, /*->2417*/ // 3 children in Scope
/*2397*/            OPC_CheckCondCode, ISD::SETNE,
/*2399*/            OPC_MoveParent,
/*2400*/            OPC_MoveParent,
/*2401*/            OPC_RecordChild2, // #2 = $dst
/*2402*/            OPC_MoveChild, 2,
/*2404*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2407*/            OPC_MoveParent,
/*2408*/            OPC_EmitMergeInputChains1_0,
/*2409*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFT_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETNE:Other), (bb:Other):$dst) - Complexity = 11
                    // Dst: (BRFT_lru6 GRRegs:i32:$lhs, (bb:Other):$dst)
/*2417*/          /*Scope*/ 20, /*->2438*/
/*2418*/            OPC_CheckCondCode, ISD::SETEQ,
/*2420*/            OPC_MoveParent,
/*2421*/            OPC_MoveParent,
/*2422*/            OPC_RecordChild2, // #2 = $dst
/*2423*/            OPC_MoveChild, 2,
/*2425*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2428*/            OPC_MoveParent,
/*2429*/            OPC_EmitMergeInputChains1_0,
/*2430*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETEQ:Other), (bb:Other):$dst) - Complexity = 11
                    // Dst: (BRFF_lru6 GRRegs:i32:$lhs, (bb:Other):$dst)
/*2438*/          /*Scope*/ 32, /*->2471*/
/*2439*/            OPC_CheckCondCode, ISD::SETLT,
/*2441*/            OPC_MoveParent,
/*2442*/            OPC_MoveParent,
/*2443*/            OPC_RecordChild2, // #2 = $dst
/*2444*/            OPC_MoveChild, 2,
/*2446*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2449*/            OPC_MoveParent,
/*2450*/            OPC_EmitMergeInputChains1_0,
/*2451*/            OPC_EmitInteger, MVT::i32, 32, 
/*2454*/            OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*2463*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFT_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 4, 2, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETLT:Other), (bb:Other):$dst) - Complexity = 11
                    // Dst: (BRFT_lru6 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), (bb:Other):$dst)
/*2471*/          0, /*End of Scope*/
/*2472*/        /*Scope*/ 45, /*->2518*/
/*2473*/          OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2484*/          OPC_MoveChild, 2,
/*2486*/          OPC_CheckCondCode, ISD::SETGT,
/*2488*/          OPC_MoveParent,
/*2489*/          OPC_MoveParent,
/*2490*/          OPC_RecordChild2, // #2 = $dst
/*2491*/          OPC_MoveChild, 2,
/*2493*/          OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2496*/          OPC_MoveParent,
/*2497*/          OPC_EmitMergeInputChains1_0,
/*2498*/          OPC_EmitInteger, MVT::i32, 32, 
/*2501*/          OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 3,  // Results = #4
/*2510*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 4, 2, 
                  // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, -1:i32, SETGT:Other), (bb:Other):$dst) - Complexity = 11
                  // Dst: (BRFF_lru6 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), (bb:Other):$dst)
/*2518*/        /*Scope*/ 42, /*->2561*/
/*2519*/          OPC_RecordChild1, // #2 = $rhs
/*2520*/          OPC_MoveChild, 1,
/*2522*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2525*/          OPC_CheckPredicate, 0, // Predicate_immUs
/*2527*/          OPC_MoveParent,
/*2528*/          OPC_MoveChild, 2,
/*2530*/          OPC_CheckCondCode, ISD::SETNE,
/*2532*/          OPC_MoveParent,
/*2533*/          OPC_MoveParent,
/*2534*/          OPC_RecordChild2, // #3 = $dst
/*2535*/          OPC_MoveChild, 2,
/*2537*/          OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2540*/          OPC_MoveParent,
/*2541*/          OPC_EmitMergeInputChains1_0,
/*2542*/          OPC_EmitConvertToTarget, 2,
/*2544*/          OPC_EmitNode, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 4,  // Results = #5
/*2553*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                      0/*#VTs*/, 2/*#Ops*/, 5, 3, 
                  // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs, SETNE:Other), (bb:Other):$dst) - Complexity = 10
                  // Dst: (BRFF_lru6 (EQ_2rus:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs), (bb:Other):$dst)
/*2561*/        /*Scope*/ 29|128,1/*157*/, /*->2720*/
/*2563*/          OPC_CheckChild0Type, MVT::i32,
/*2565*/          OPC_RecordChild1, // #2 = $rhs
/*2566*/          OPC_MoveChild, 2,
/*2568*/          OPC_Scope, 29, /*->2599*/ // 5 children in Scope
/*2570*/            OPC_CheckCondCode, ISD::SETLE,
/*2572*/            OPC_MoveParent,
/*2573*/            OPC_MoveParent,
/*2574*/            OPC_RecordChild2, // #3 = $dst
/*2575*/            OPC_MoveChild, 2,
/*2577*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2580*/            OPC_MoveParent,
/*2581*/            OPC_EmitMergeInputChains1_0,
/*2582*/            OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1,  // Results = #4
/*2591*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETLE:Other), (bb:Other):$dst) - Complexity = 6
                    // Dst: (BRFF_lru6 (LSS_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), (bb:Other):$dst)
/*2599*/          /*Scope*/ 29, /*->2629*/
/*2600*/            OPC_CheckCondCode, ISD::SETULE,
/*2602*/            OPC_MoveParent,
/*2603*/            OPC_MoveParent,
/*2604*/            OPC_RecordChild2, // #3 = $dst
/*2605*/            OPC_MoveChild, 2,
/*2607*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2610*/            OPC_MoveParent,
/*2611*/            OPC_EmitMergeInputChains1_0,
/*2612*/            OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 1,  // Results = #4
/*2621*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETULE:Other), (bb:Other):$dst) - Complexity = 6
                    // Dst: (BRFF_lru6 (LSU_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), (bb:Other):$dst)
/*2629*/          /*Scope*/ 29, /*->2659*/
/*2630*/            OPC_CheckCondCode, ISD::SETGE,
/*2632*/            OPC_MoveParent,
/*2633*/            OPC_MoveParent,
/*2634*/            OPC_RecordChild2, // #3 = $dst
/*2635*/            OPC_MoveChild, 2,
/*2637*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2640*/            OPC_MoveParent,
/*2641*/            OPC_EmitMergeInputChains1_0,
/*2642*/            OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*2651*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETGE:Other), (bb:Other):$dst) - Complexity = 6
                    // Dst: (BRFF_lru6 (LSS_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), (bb:Other):$dst)
/*2659*/          /*Scope*/ 29, /*->2689*/
/*2660*/            OPC_CheckCondCode, ISD::SETUGE,
/*2662*/            OPC_MoveParent,
/*2663*/            OPC_MoveParent,
/*2664*/            OPC_RecordChild2, // #3 = $dst
/*2665*/            OPC_MoveChild, 2,
/*2667*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2670*/            OPC_MoveParent,
/*2671*/            OPC_EmitMergeInputChains1_0,
/*2672*/            OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*2681*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETUGE:Other), (bb:Other):$dst) - Complexity = 6
                    // Dst: (BRFF_lru6 (LSU_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), (bb:Other):$dst)
/*2689*/          /*Scope*/ 29, /*->2719*/
/*2690*/            OPC_CheckCondCode, ISD::SETNE,
/*2692*/            OPC_MoveParent,
/*2693*/            OPC_MoveParent,
/*2694*/            OPC_RecordChild2, // #3 = $dst
/*2695*/            OPC_MoveChild, 2,
/*2697*/            OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2700*/            OPC_MoveParent,
/*2701*/            OPC_EmitMergeInputChains1_0,
/*2702*/            OPC_EmitNode, TARGET_VAL(XCore::EQ_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2,  // Results = #4
/*2711*/            OPC_MorphNodeTo, TARGET_VAL(XCore::BRFF_lru6), 0|OPFL_Chain,
                        0/*#VTs*/, 2/*#Ops*/, 4, 3, 
                    // Src: (brcond (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETNE:Other), (bb:Other):$dst) - Complexity = 6
                    // Dst: (BRFF_lru6 (EQ_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), (bb:Other):$dst)
/*2719*/          0, /*End of Scope*/
/*2720*/        0, /*End of Scope*/
/*2721*/      /*Scope*/ 17, /*->2739*/
/*2722*/        OPC_RecordChild1, // #1 = $cond
/*2723*/        OPC_RecordChild2, // #2 = $addr
/*2724*/        OPC_MoveChild, 2,
/*2726*/        OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*2729*/        OPC_MoveParent,
/*2730*/        OPC_EmitMergeInputChains1_0,
/*2731*/        OPC_MorphNodeTo, TARGET_VAL(XCore::BRFT_lru6), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 2, 
                // Src: (brcond GRRegs:i32:$cond, (bb:Other):$addr) - Complexity = 3
                // Dst: (BRFT_lru6 GRRegs:i32:$cond, (bb:Other):$addr)
/*2739*/      0, /*End of Scope*/
/*2740*/    /*SwitchOpcode*/ 82|128,2/*338*/, TARGET_VAL(ISD::SELECT),// ->3082
/*2744*/      OPC_Scope, 62|128,2/*318*/, /*->3065*/ // 2 children in Scope
/*2747*/        OPC_MoveChild, 0,
/*2749*/        OPC_CheckOpcode, TARGET_VAL(ISD::SETCC),
/*2752*/        OPC_RecordChild0, // #0 = $lhs
/*2753*/        OPC_Scope, 75, /*->2830*/ // 4 children in Scope
/*2755*/          OPC_CheckChild1Integer, 0, 
/*2757*/          OPC_MoveChild, 2,
/*2759*/          OPC_Scope, 18, /*->2779*/ // 3 children in Scope
/*2761*/            OPC_CheckCondCode, ISD::SETNE,
/*2763*/            OPC_MoveParent,
/*2764*/            OPC_MoveParent,
/*2765*/            OPC_RecordChild1, // #1 = $T
/*2766*/            OPC_RecordChild2, // #2 = $F
/*2767*/            OPC_CheckType, MVT::i32,
/*2769*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 2, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETNE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 11
                    // Dst: (SELECT_CC:i32 GRRegs:i32:$lhs, GRRegs:i32:$T, GRRegs:i32:$F)
/*2779*/          /*Scope*/ 18, /*->2798*/
/*2780*/            OPC_CheckCondCode, ISD::SETEQ,
/*2782*/            OPC_MoveParent,
/*2783*/            OPC_MoveParent,
/*2784*/            OPC_RecordChild1, // #1 = $T
/*2785*/            OPC_RecordChild2, // #2 = $F
/*2786*/            OPC_CheckType, MVT::i32,
/*2788*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 2, 1, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETEQ:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 11
                    // Dst: (SELECT_CC:i32 GRRegs:i32:$lhs, GRRegs:i32:$F, GRRegs:i32:$T)
/*2798*/          /*Scope*/ 30, /*->2829*/
/*2799*/            OPC_CheckCondCode, ISD::SETLT,
/*2801*/            OPC_MoveParent,
/*2802*/            OPC_MoveParent,
/*2803*/            OPC_RecordChild1, // #1 = $T
/*2804*/            OPC_RecordChild2, // #2 = $F
/*2805*/            OPC_CheckType, MVT::i32,
/*2807*/            OPC_EmitInteger, MVT::i32, 32, 
/*2810*/            OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3,  // Results = #4
/*2819*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 1, 2, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, 0:i32, SETLT:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 11
                    // Dst: (SELECT_CC:i32 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), GRRegs:i32:$T, GRRegs:i32:$F)
/*2829*/          0, /*End of Scope*/
/*2830*/        /*Scope*/ 43, /*->2874*/
/*2831*/          OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*2842*/          OPC_MoveChild, 2,
/*2844*/          OPC_CheckCondCode, ISD::SETGT,
/*2846*/          OPC_MoveParent,
/*2847*/          OPC_MoveParent,
/*2848*/          OPC_RecordChild1, // #1 = $T
/*2849*/          OPC_RecordChild2, // #2 = $F
/*2850*/          OPC_CheckType, MVT::i32,
/*2852*/          OPC_EmitInteger, MVT::i32, 32, 
/*2855*/          OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 3,  // Results = #4
/*2864*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 2, 1, 
                  // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, -1:i32, SETGT:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 11
                  // Dst: (SELECT_CC:i32 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), GRRegs:i32:$F, GRRegs:i32:$T)
/*2874*/        /*Scope*/ 40, /*->2915*/
/*2875*/          OPC_RecordChild1, // #1 = $rhs
/*2876*/          OPC_MoveChild, 1,
/*2878*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*2881*/          OPC_CheckPredicate, 0, // Predicate_immUs
/*2883*/          OPC_MoveParent,
/*2884*/          OPC_MoveChild, 2,
/*2886*/          OPC_CheckCondCode, ISD::SETNE,
/*2888*/          OPC_MoveParent,
/*2889*/          OPC_MoveParent,
/*2890*/          OPC_RecordChild1, // #2 = $T
/*2891*/          OPC_RecordChild2, // #3 = $F
/*2892*/          OPC_CheckType, MVT::i32,
/*2894*/          OPC_EmitConvertToTarget, 1,
/*2896*/          OPC_EmitNode, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 4,  // Results = #5
/*2905*/          OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                      1/*#VTs*/, MVT::i32, 3/*#Ops*/, 5, 3, 2, 
                  // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs, SETNE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 10
                  // Dst: (SELECT_CC:i32 (EQ_2rus:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*2915*/        /*Scope*/ 19|128,1/*147*/, /*->3064*/
/*2917*/          OPC_CheckChild0Type, MVT::i32,
/*2919*/          OPC_RecordChild1, // #1 = $rhs
/*2920*/          OPC_MoveChild, 2,
/*2922*/          OPC_Scope, 27, /*->2951*/ // 5 children in Scope
/*2924*/            OPC_CheckCondCode, ISD::SETLE,
/*2926*/            OPC_MoveParent,
/*2927*/            OPC_MoveParent,
/*2928*/            OPC_RecordChild1, // #2 = $T
/*2929*/            OPC_RecordChild2, // #3 = $F
/*2930*/            OPC_CheckType, MVT::i32,
/*2932*/            OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*2941*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETLE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                    // Dst: (SELECT_CC:i32 (LSS_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*2951*/          /*Scope*/ 27, /*->2979*/
/*2952*/            OPC_CheckCondCode, ISD::SETULE,
/*2954*/            OPC_MoveParent,
/*2955*/            OPC_MoveParent,
/*2956*/            OPC_RecordChild1, // #2 = $T
/*2957*/            OPC_RecordChild2, // #3 = $F
/*2958*/            OPC_CheckType, MVT::i32,
/*2960*/            OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #4
/*2969*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETULE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                    // Dst: (SELECT_CC:i32 (LSU_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*2979*/          /*Scope*/ 27, /*->3007*/
/*2980*/            OPC_CheckCondCode, ISD::SETGE,
/*2982*/            OPC_MoveParent,
/*2983*/            OPC_MoveParent,
/*2984*/            OPC_RecordChild1, // #2 = $T
/*2985*/            OPC_RecordChild2, // #3 = $F
/*2986*/            OPC_CheckType, MVT::i32,
/*2988*/            OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*2997*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETGE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                    // Dst: (SELECT_CC:i32 (LSS_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*3007*/          /*Scope*/ 27, /*->3035*/
/*3008*/            OPC_CheckCondCode, ISD::SETUGE,
/*3010*/            OPC_MoveParent,
/*3011*/            OPC_MoveParent,
/*3012*/            OPC_RecordChild1, // #2 = $T
/*3013*/            OPC_RecordChild2, // #3 = $F
/*3014*/            OPC_CheckType, MVT::i32,
/*3016*/            OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*3025*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETUGE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                    // Dst: (SELECT_CC:i32 (LSU_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*3035*/          /*Scope*/ 27, /*->3063*/
/*3036*/            OPC_CheckCondCode, ISD::SETNE,
/*3038*/            OPC_MoveParent,
/*3039*/            OPC_MoveParent,
/*3040*/            OPC_RecordChild1, // #2 = $T
/*3041*/            OPC_RecordChild2, // #3 = $F
/*3042*/            OPC_CheckType, MVT::i32,
/*3044*/            OPC_EmitNode, TARGET_VAL(XCore::EQ_3r), 0,
                        1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #4
/*3053*/            OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                        1/*#VTs*/, MVT::i32, 3/*#Ops*/, 4, 3, 2, 
                    // Src: (select:i32 (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETNE:Other), GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 6
                    // Dst: (SELECT_CC:i32 (EQ_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), GRRegs:i32:$F, GRRegs:i32:$T)
/*3063*/          0, /*End of Scope*/
/*3064*/        0, /*End of Scope*/
/*3065*/      /*Scope*/ 15, /*->3081*/
/*3066*/        OPC_RecordChild0, // #0 = $cond
/*3067*/        OPC_RecordChild1, // #1 = $T
/*3068*/        OPC_RecordChild2, // #2 = $F
/*3069*/        OPC_CheckType, MVT::i32,
/*3071*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SELECT_CC), 0,
                    1/*#VTs*/, MVT::i32, 3/*#Ops*/, 0, 1, 2, 
                // Src: (select:i32 GRRegs:i32:$cond, GRRegs:i32:$T, GRRegs:i32:$F) - Complexity = 3
                // Dst: (SELECT_CC:i32 GRRegs:i32:$cond, GRRegs:i32:$T, GRRegs:i32:$F)
/*3081*/      0, /*End of Scope*/
/*3082*/    /*SwitchOpcode*/ 26, TARGET_VAL(ISD::CALLSEQ_END),// ->3111
/*3085*/      OPC_RecordNode, // #0 = 'callseq_end' chained node
/*3086*/      OPC_CaptureGlueInput,
/*3087*/      OPC_RecordChild1, // #1 = $amt1
/*3088*/      OPC_MoveChild, 1,
/*3090*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*3093*/      OPC_MoveParent,
/*3094*/      OPC_RecordChild2, // #2 = $amt2
/*3095*/      OPC_MoveChild, 2,
/*3097*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*3100*/      OPC_MoveParent,
/*3101*/      OPC_EmitMergeInputChains1_0,
/*3102*/      OPC_MorphNodeTo, TARGET_VAL(XCore::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: (callseq_end (timm:i32):$amt1, (timm:i32):$amt2) - Complexity = 9
              // Dst: (ADJCALLSTACKUP:i32 (timm:i32):$amt1, (timm:i32):$amt2)
/*3111*/    /*SwitchOpcode*/ 15, TARGET_VAL(ISD::FrameIndex),// ->3129
/*3114*/      OPC_RecordNode, // #0 = $addr
/*3115*/      OPC_CheckType, MVT::i32,
/*3117*/      OPC_CheckComplexPat, /*CP*/0, /*#*/0, // SelectADDRspii:$addr #1 #2
/*3120*/      OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWFI), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 2, 
              // Src: ADDRspii:i32:$addr - Complexity = 9
              // Dst: (LDAWFI:i32 ADDRspii:i32:$addr)
/*3129*/    /*SwitchOpcode*/ 34, TARGET_VAL(ISD::XOR),// ->3166
/*3132*/      OPC_RecordChild0, // #0 = $b
/*3133*/      OPC_Scope, 19, /*->3154*/ // 2 children in Scope
/*3135*/        OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3146*/        OPC_MorphNodeTo, TARGET_VAL(XCore::NOT), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (xor:i32 GRRegs:i32:$b, -1:i32) - Complexity = 8
                // Dst: (NOT:i32 GRRegs:i32:$b)
/*3154*/      /*Scope*/ 10, /*->3165*/
/*3155*/        OPC_RecordChild1, // #1 = $c
/*3156*/        OPC_MorphNodeTo, TARGET_VAL(XCore::XOR_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                // Dst: (XOR_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*3165*/      0, /*End of Scope*/
/*3166*/    /*SwitchOpcode*/ 59, TARGET_VAL(ISD::MUL),// ->3228
/*3169*/      OPC_RecordChild0, // #0 = $src
/*3170*/      OPC_Scope, 11, /*->3183*/ // 4 children in Scope
/*3172*/        OPC_CheckChild1Integer, 3, 
/*3174*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDA16F_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                // Src: (mul:i32 GRRegs:i32:$src, 3:i32) - Complexity = 8
                // Dst: (LDA16F_l3r:i32 GRRegs:i32:$src, GRRegs:i32:$src)
/*3183*/      /*Scope*/ 11, /*->3195*/
/*3184*/        OPC_CheckChild1Integer, 5, 
/*3186*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWF_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                // Src: (mul:i32 GRRegs:i32:$src, 5:i32) - Complexity = 8
                // Dst: (LDAWF_l3r:i32 GRRegs:i32:$src, GRRegs:i32:$src)
/*3195*/      /*Scope*/ 20, /*->3216*/
/*3196*/        OPC_CheckChild1Integer, 125|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551613*/, 
/*3207*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWB_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 0, 
                // Src: (mul:i32 GRRegs:i32:$src, -3:i32) - Complexity = 8
                // Dst: (LDAWB_l3r:i32 GRRegs:i32:$src, GRRegs:i32:$src)
/*3216*/      /*Scope*/ 10, /*->3227*/
/*3217*/        OPC_RecordChild1, // #1 = $c
/*3218*/        OPC_MorphNodeTo, TARGET_VAL(XCore::MUL_l3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (mul:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                // Dst: (MUL_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*3227*/      0, /*End of Scope*/
/*3228*/    /*SwitchOpcode*/ 43|128,2/*299*/, TARGET_VAL(ISD::SETCC),// ->3531
/*3232*/      OPC_RecordChild0, // #0 = $lhs
/*3233*/      OPC_Scope, 40, /*->3275*/ // 3 children in Scope
/*3235*/        OPC_CheckChild1Integer, 127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,127|128,1/*18446744073709551615*/, 
/*3246*/        OPC_MoveChild, 2,
/*3248*/        OPC_CheckCondCode, ISD::SETGT,
/*3250*/        OPC_MoveParent,
/*3251*/        OPC_EmitInteger, MVT::i32, 32, 
/*3254*/        OPC_EmitNode, TARGET_VAL(XCore::ASHR_l2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*3263*/        OPC_EmitInteger, MVT::i32, 0, 
/*3266*/        OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                // Src: (setcc:i32 GRRegs:i32:$lhs, -1:i32, SETGT:Other) - Complexity = 8
                // Dst: (EQ_2rus:i32 (ASHR_l2rus:i32 GRRegs:i32:$lhs, 32:i32), 0:i32)
/*3275*/      /*Scope*/ 55, /*->3331*/
/*3276*/        OPC_RecordChild1, // #1 = $rhs
/*3277*/        OPC_MoveChild, 1,
/*3279*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3282*/        OPC_CheckPredicate, 0, // Predicate_immUs
/*3284*/        OPC_MoveParent,
/*3285*/        OPC_MoveChild, 2,
/*3287*/        OPC_Scope, 14, /*->3303*/ // 2 children in Scope
/*3289*/          OPC_CheckCondCode, ISD::SETEQ,
/*3291*/          OPC_MoveParent,
/*3292*/          OPC_EmitConvertToTarget, 1,
/*3294*/          OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs, SETEQ:Other) - Complexity = 7
                  // Dst: (EQ_2rus:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs)
/*3303*/        /*Scope*/ 26, /*->3330*/
/*3304*/          OPC_CheckCondCode, ISD::SETNE,
/*3306*/          OPC_MoveParent,
/*3307*/          OPC_EmitConvertToTarget, 1,
/*3309*/          OPC_EmitNode, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2,  // Results = #3
/*3318*/          OPC_EmitInteger, MVT::i32, 0, 
/*3321*/          OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 3, 4, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs, SETNE:Other) - Complexity = 7
                  // Dst: (EQ_2rus:i32 (EQ_2rus:i32 GRRegs:i32:$lhs, (imm:i32)<<P:Predicate_immUs>>:$rhs), 0:i32)
/*3330*/        0, /*End of Scope*/
/*3331*/      /*Scope*/ 69|128,1/*197*/, /*->3530*/
/*3333*/        OPC_CheckChild0Type, MVT::i32,
/*3335*/        OPC_RecordChild1, // #1 = $rhs
/*3336*/        OPC_MoveChild, 2,
/*3338*/        OPC_Scope, 12, /*->3352*/ // 10 children in Scope
/*3340*/          OPC_CheckCondCode, ISD::SETGT,
/*3342*/          OPC_MoveParent,
/*3343*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LSS_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETGT:Other) - Complexity = 3
                  // Dst: (LSS_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs)
/*3352*/        /*Scope*/ 12, /*->3365*/
/*3353*/          OPC_CheckCondCode, ISD::SETUGT,
/*3355*/          OPC_MoveParent,
/*3356*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LSU_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETUGT:Other) - Complexity = 3
                  // Dst: (LSU_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs)
/*3365*/        /*Scope*/ 12, /*->3378*/
/*3366*/          OPC_CheckCondCode, ISD::SETLT,
/*3368*/          OPC_MoveParent,
/*3369*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LSS_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETLT:Other) - Complexity = 3
                  // Dst: (LSS_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs)
/*3378*/        /*Scope*/ 12, /*->3391*/
/*3379*/          OPC_CheckCondCode, ISD::SETULT,
/*3381*/          OPC_MoveParent,
/*3382*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LSU_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETULT:Other) - Complexity = 3
                  // Dst: (LSU_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs)
/*3391*/        /*Scope*/ 12, /*->3404*/
/*3392*/          OPC_CheckCondCode, ISD::SETEQ,
/*3394*/          OPC_MoveParent,
/*3395*/          OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETEQ:Other) - Complexity = 3
                  // Dst: (EQ_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs)
/*3404*/        /*Scope*/ 24, /*->3429*/
/*3405*/          OPC_CheckCondCode, ISD::SETLE,
/*3407*/          OPC_MoveParent,
/*3408*/          OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*3417*/          OPC_EmitInteger, MVT::i32, 0, 
/*3420*/          OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETLE:Other) - Complexity = 3
                  // Dst: (EQ_2rus:i32 (LSS_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), 0:i32)
/*3429*/        /*Scope*/ 24, /*->3454*/
/*3430*/          OPC_CheckCondCode, ISD::SETULE,
/*3432*/          OPC_MoveParent,
/*3433*/          OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 1, 0,  // Results = #2
/*3442*/          OPC_EmitInteger, MVT::i32, 0, 
/*3445*/          OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETULE:Other) - Complexity = 3
                  // Dst: (EQ_2rus:i32 (LSU_3r:i32 GRRegs:i32:$rhs, GRRegs:i32:$lhs), 0:i32)
/*3454*/        /*Scope*/ 24, /*->3479*/
/*3455*/          OPC_CheckCondCode, ISD::SETGE,
/*3457*/          OPC_MoveParent,
/*3458*/          OPC_EmitNode, TARGET_VAL(XCore::LSS_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*3467*/          OPC_EmitInteger, MVT::i32, 0, 
/*3470*/          OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETGE:Other) - Complexity = 3
                  // Dst: (EQ_2rus:i32 (LSS_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), 0:i32)
/*3479*/        /*Scope*/ 24, /*->3504*/
/*3480*/          OPC_CheckCondCode, ISD::SETUGE,
/*3482*/          OPC_MoveParent,
/*3483*/          OPC_EmitNode, TARGET_VAL(XCore::LSU_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*3492*/          OPC_EmitInteger, MVT::i32, 0, 
/*3495*/          OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETUGE:Other) - Complexity = 3
                  // Dst: (EQ_2rus:i32 (LSU_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), 0:i32)
/*3504*/        /*Scope*/ 24, /*->3529*/
/*3505*/          OPC_CheckCondCode, ISD::SETNE,
/*3507*/          OPC_MoveParent,
/*3508*/          OPC_EmitNode, TARGET_VAL(XCore::EQ_3r), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1,  // Results = #2
/*3517*/          OPC_EmitInteger, MVT::i32, 0, 
/*3520*/          OPC_MorphNodeTo, TARGET_VAL(XCore::EQ_2rus), 0,
                      1/*#VTs*/, MVT::i32, 2/*#Ops*/, 2, 3, 
                  // Src: (setcc:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs, SETNE:Other) - Complexity = 3
                  // Dst: (EQ_2rus:i32 (EQ_3r:i32 GRRegs:i32:$lhs, GRRegs:i32:$rhs), 0:i32)
/*3529*/        0, /*End of Scope*/
/*3530*/      0, /*End of Scope*/
/*3531*/    /*SwitchOpcode*/ 34, TARGET_VAL(ISD::SHL),// ->3568
/*3534*/      OPC_RecordChild0, // #0 = $b
/*3535*/      OPC_RecordChild1, // #1 = $c
/*3536*/      OPC_Scope, 19, /*->3557*/ // 2 children in Scope
/*3538*/        OPC_MoveChild, 1,
/*3540*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3543*/        OPC_CheckPredicate, 17, // Predicate_immBitp
/*3545*/        OPC_MoveParent,
/*3546*/        OPC_EmitConvertToTarget, 1,
/*3548*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SHL_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (shl:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immBitp>>:$c) - Complexity = 7
                // Dst: (SHL_2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*3557*/      /*Scope*/ 9, /*->3567*/
/*3558*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SHL_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                // Dst: (SHL_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*3567*/      0, /*End of Scope*/
/*3568*/    /*SwitchOpcode*/ 34, TARGET_VAL(ISD::SRL),// ->3605
/*3571*/      OPC_RecordChild0, // #0 = $b
/*3572*/      OPC_RecordChild1, // #1 = $c
/*3573*/      OPC_Scope, 19, /*->3594*/ // 2 children in Scope
/*3575*/        OPC_MoveChild, 1,
/*3577*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3580*/        OPC_CheckPredicate, 17, // Predicate_immBitp
/*3582*/        OPC_MoveParent,
/*3583*/        OPC_EmitConvertToTarget, 1,
/*3585*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SHR_2rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 2, 
                // Src: (srl:i32 GRRegs:i32:$b, (imm:i32)<<P:Predicate_immBitp>>:$c) - Complexity = 7
                // Dst: (SHR_2rus:i32 GRRegs:i32:$b, (imm:i32):$c)
/*3594*/      /*Scope*/ 9, /*->3604*/
/*3595*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SHR_3r), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (srl:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
                // Dst: (SHR_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*3604*/      0, /*End of Scope*/
/*3605*/    /*SwitchOpcode*/ 42, TARGET_VAL(XCoreISD::STWSP),// ->3650
/*3608*/      OPC_RecordNode, // #0 = 'XCoreStwsp' chained node
/*3609*/      OPC_RecordChild1, // #1 = $a
/*3610*/      OPC_CheckChild1Type, MVT::i32,
/*3612*/      OPC_RecordChild2, // #2 = $b
/*3613*/      OPC_MoveChild, 2,
/*3615*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3618*/      OPC_Scope, 14, /*->3634*/ // 2 children in Scope
/*3620*/        OPC_CheckPredicate, 18, // Predicate_immU6
/*3622*/        OPC_MoveParent,
/*3623*/        OPC_EmitMergeInputChains1_0,
/*3624*/        OPC_EmitConvertToTarget, 2,
/*3626*/        OPC_MorphNodeTo, TARGET_VAL(XCore::STWSP_ru6), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                // Src: (XCoreStwsp RRegs:i32:$a, (imm:i32)<<P:Predicate_immU6>>:$b) - Complexity = 7
                // Dst: (STWSP_ru6 RRegs:i32:$a, (imm:i32):$b)
/*3634*/      /*Scope*/ 14, /*->3649*/
/*3635*/        OPC_CheckPredicate, 19, // Predicate_immU16
/*3637*/        OPC_MoveParent,
/*3638*/        OPC_EmitMergeInputChains1_0,
/*3639*/        OPC_EmitConvertToTarget, 2,
/*3641*/        OPC_MorphNodeTo, TARGET_VAL(XCore::STWSP_lru6), 0|OPFL_Chain,
                    0/*#VTs*/, 2/*#Ops*/, 1, 3, 
                // Src: (XCoreStwsp RRegs:i32:$a, (imm:i32)<<P:Predicate_immU16>>:$b) - Complexity = 7
                // Dst: (STWSP_lru6 RRegs:i32:$a, (imm:i32):$b)
/*3649*/      0, /*End of Scope*/
/*3650*/    /*SwitchOpcode*/ 43, TARGET_VAL(XCoreISD::LDWSP),// ->3696
/*3653*/      OPC_RecordNode, // #0 = 'XCoreLdwsp' chained node
/*3654*/      OPC_RecordChild1, // #1 = $b
/*3655*/      OPC_MoveChild, 1,
/*3657*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3660*/      OPC_Scope, 16, /*->3678*/ // 2 children in Scope
/*3662*/        OPC_CheckPredicate, 18, // Predicate_immU6
/*3664*/        OPC_MoveParent,
/*3665*/        OPC_CheckType, MVT::i32,
/*3667*/        OPC_EmitMergeInputChains1_0,
/*3668*/        OPC_EmitConvertToTarget, 1,
/*3670*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDWSP_ru6), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                // Src: (XCoreLdwsp:i32 (imm:i32)<<P:Predicate_immU6>>:$b) - Complexity = 7
                // Dst: (LDWSP_ru6:i32 (imm:i32):$b)
/*3678*/      /*Scope*/ 16, /*->3695*/
/*3679*/        OPC_CheckPredicate, 19, // Predicate_immU16
/*3681*/        OPC_MoveParent,
/*3682*/        OPC_CheckType, MVT::i32,
/*3684*/        OPC_EmitMergeInputChains1_0,
/*3685*/        OPC_EmitConvertToTarget, 1,
/*3687*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDWSP_lru6), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                // Src: (XCoreLdwsp:i32 (imm:i32)<<P:Predicate_immU16>>:$b) - Complexity = 7
                // Dst: (LDWSP_lru6:i32 (imm:i32):$b)
/*3695*/      0, /*End of Scope*/
/*3696*/    /*SwitchOpcode*/ 42, TARGET_VAL(XCoreISD::RETSP),// ->3741
/*3699*/      OPC_RecordNode, // #0 = 'XCoreRetsp' chained node
/*3700*/      OPC_CaptureGlueInput,
/*3701*/      OPC_RecordChild1, // #1 = $a
/*3702*/      OPC_MoveChild, 1,
/*3704*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*3707*/      OPC_CheckType, MVT::i32,
/*3709*/      OPC_Scope, 14, /*->3725*/ // 2 children in Scope
/*3711*/        OPC_CheckPredicate, 18, // Predicate_immU6
/*3713*/        OPC_MoveParent,
/*3714*/        OPC_EmitMergeInputChains1_0,
/*3715*/        OPC_EmitConvertToTarget, 1,
/*3717*/        OPC_MorphNodeTo, TARGET_VAL(XCore::RETSP_u6), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                // Src: (XCoreRetsp (imm:i32)<<P:Predicate_immU6>>:$a) - Complexity = 7
                // Dst: (RETSP_u6:i32 (imm:i32):$a)
/*3725*/      /*Scope*/ 14, /*->3740*/
/*3726*/        OPC_CheckPredicate, 19, // Predicate_immU16
/*3728*/        OPC_MoveParent,
/*3729*/        OPC_EmitMergeInputChains1_0,
/*3730*/        OPC_EmitConvertToTarget, 1,
/*3732*/        OPC_MorphNodeTo, TARGET_VAL(XCore::RETSP_lu6), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic1,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 2, 
                // Src: (XCoreRetsp (imm:i32)<<P:Predicate_immU16>>:$a) - Complexity = 7
                // Dst: (RETSP_lu6:i32 (imm:i32):$a)
/*3740*/      0, /*End of Scope*/
/*3741*/    /*SwitchOpcode*/ 17, TARGET_VAL(ISD::CALLSEQ_START),// ->3761
/*3744*/      OPC_RecordNode, // #0 = 'callseq_start' chained node
/*3745*/      OPC_RecordChild1, // #1 = $amt
/*3746*/      OPC_MoveChild, 1,
/*3748*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*3751*/      OPC_MoveParent,
/*3752*/      OPC_EmitMergeInputChains1_0,
/*3753*/      OPC_MorphNodeTo, TARGET_VAL(XCore::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (callseq_start (timm:i32):$amt) - Complexity = 6
              // Dst: (ADJCALLSTACKDOWN:i32 (timm:i32):$amt)
/*3761*/    /*SwitchOpcode*/ 17, TARGET_VAL(XCoreISD::DPRelativeWrapper),// ->3781
/*3764*/      OPC_RecordChild0, // #0 = $b
/*3765*/      OPC_MoveChild, 0,
/*3767*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*3770*/      OPC_MoveParent,
/*3771*/      OPC_CheckType, MVT::i32,
/*3773*/      OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWDP_lru6), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (dprelwrapper:i32 (tglobaladdr:i32):$b) - Complexity = 6
              // Dst: (LDAWDP_lru6:i32 (tglobaladdr:i32):$b)
/*3781*/    /*SwitchOpcode*/ 33, TARGET_VAL(XCoreISD::CPRelativeWrapper),// ->3817
/*3784*/      OPC_RecordChild0, // #0 = $a
/*3785*/      OPC_MoveChild, 0,
/*3787*/      OPC_SwitchOpcode /*2 cases */, 11, TARGET_VAL(ISD::TargetGlobalAddress),// ->3802
/*3791*/        OPC_MoveParent,
/*3792*/        OPC_CheckType, MVT::i32,
/*3794*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWCP_lu6), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (cprelwrapper:i32 (tglobaladdr:i32):$a) - Complexity = 6
                // Dst: (LDAWCP_lu6:i32 (tglobaladdr:i32):$a)
/*3802*/      /*SwitchOpcode*/ 11, TARGET_VAL(ISD::TargetConstantPool),// ->3816
/*3805*/        OPC_MoveParent,
/*3806*/        OPC_CheckType, MVT::i32,
/*3808*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAWCP_lu6), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (cprelwrapper:i32 (tconstpool:i32):$b) - Complexity = 6
                // Dst: (LDAWCP_lu6:i32 (tconstpool:i32):$b)
/*3816*/      0, // EndSwitchOpcode
/*3817*/    /*SwitchOpcode*/ 45, TARGET_VAL(XCoreISD::PCRelativeWrapper),// ->3865
/*3820*/      OPC_RecordChild0, // #0 = $a
/*3821*/      OPC_MoveChild, 0,
/*3823*/      OPC_SwitchOpcode /*2 cases */, 23, TARGET_VAL(ISD::TargetGlobalAddress),// ->3850
/*3827*/        OPC_MoveParent,
/*3828*/        OPC_CheckType, MVT::i32,
/*3830*/        OPC_Scope, 8, /*->3840*/ // 2 children in Scope
/*3832*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LDAPF_lu10), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (pcrelwrapper:i32 (tglobaladdr:i32):$a) - Complexity = 6
                  // Dst: (LDAPF_lu10:i32 (tglobaladdr:i32):$a)
/*3840*/        /*Scope*/ 8, /*->3849*/
/*3841*/          OPC_MorphNodeTo, TARGET_VAL(XCore::LDAPB_lu10), 0,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                  // Src: (pcrelwrapper:i32 (tglobaladdr:i32):$a) - Complexity = 6
                  // Dst: (LDAPB_lu10:i32 (tglobaladdr:i32):$a)
/*3849*/        0, /*End of Scope*/
/*3850*/      /*SwitchOpcode*/ 11, TARGET_VAL(ISD::TargetBlockAddress),// ->3864
/*3853*/        OPC_MoveParent,
/*3854*/        OPC_CheckType, MVT::i32,
/*3856*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDAPF_lu10_ba), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
                // Src: (pcrelwrapper:i32 (tblockaddress:i32):$a) - Complexity = 6
                // Dst: (LDAPF_lu10_ba:i32 (tblockaddress:i32):$a)
/*3864*/      0, // EndSwitchOpcode
/*3865*/    /*SwitchOpcode*/ 48, TARGET_VAL(XCoreISD::BL),// ->3916
/*3868*/      OPC_RecordNode, // #0 = 'XCoreBranchLink' chained node
/*3869*/      OPC_CaptureGlueInput,
/*3870*/      OPC_RecordChild1, // #1 = $a
/*3871*/      OPC_Scope, 30, /*->3903*/ // 2 children in Scope
/*3873*/        OPC_MoveChild, 1,
/*3875*/        OPC_SwitchOpcode /*2 cases */, 10, TARGET_VAL(ISD::TargetGlobalAddress),// ->3889
/*3879*/          OPC_MoveParent,
/*3880*/          OPC_EmitMergeInputChains1_0,
/*3881*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BLRF_lu10), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                  // Src: (XCoreBranchLink (tglobaladdr:iPTR):$a) - Complexity = 6
                  // Dst: (BLRF_lu10:i32 (tglobaladdr:i32):$a)
/*3889*/        /*SwitchOpcode*/ 10, TARGET_VAL(ISD::TargetExternalSymbol),// ->3902
/*3892*/          OPC_MoveParent,
/*3893*/          OPC_EmitMergeInputChains1_0,
/*3894*/          OPC_MorphNodeTo, TARGET_VAL(XCore::BLRF_lu10), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                      1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                  // Src: (XCoreBranchLink (texternalsym:iPTR):$addr) - Complexity = 6
                  // Dst: (BLRF_lu10:i32 (texternalsym:i32):$addr)
/*3902*/        0, // EndSwitchOpcode
/*3903*/      /*Scope*/ 11, /*->3915*/
/*3904*/        OPC_CheckChild1Type, MVT::i32,
/*3906*/        OPC_EmitMergeInputChains1_0,
/*3907*/        OPC_MorphNodeTo, TARGET_VAL(XCore::BLA_1r), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (XCoreBranchLink GRRegs:i32:$a) - Complexity = 3
                // Dst: (BLA_1r:i32 GRRegs:i32:$a)
/*3915*/      0, /*End of Scope*/
/*3916*/    /*SwitchOpcode*/ 18, TARGET_VAL(XCoreISD::BR_JT),// ->3937
/*3919*/      OPC_RecordNode, // #0 = 'XCoreBR_JT' chained node
/*3920*/      OPC_RecordChild1, // #1 = $t
/*3921*/      OPC_MoveChild, 1,
/*3923*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetJumpTable),
/*3926*/      OPC_MoveParent,
/*3927*/      OPC_RecordChild2, // #2 = $i
/*3928*/      OPC_EmitMergeInputChains1_0,
/*3929*/      OPC_MorphNodeTo, TARGET_VAL(XCore::BR_JT), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (XCoreBR_JT (tjumptable:i32):$t, GRRegs:i32:$i) - Complexity = 6
              // Dst: (BR_JT (tjumptable:i32):$t, GRRegs:i32:$i)
/*3937*/    /*SwitchOpcode*/ 18, TARGET_VAL(XCoreISD::BR_JT32),// ->3958
/*3940*/      OPC_RecordNode, // #0 = 'XCoreBR_JT32' chained node
/*3941*/      OPC_RecordChild1, // #1 = $t
/*3942*/      OPC_MoveChild, 1,
/*3944*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetJumpTable),
/*3947*/      OPC_MoveParent,
/*3948*/      OPC_RecordChild2, // #2 = $i
/*3949*/      OPC_EmitMergeInputChains1_0,
/*3950*/      OPC_MorphNodeTo, TARGET_VAL(XCore::BR_JT32), 0|OPFL_Chain,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (XCoreBR_JT32 (tjumptable:i32):$t, GRRegs:i32:$i) - Complexity = 6
              // Dst: (BR_JT32 (tjumptable:i32):$t, GRRegs:i32:$i)
/*3958*/    /*SwitchOpcode*/ 29, TARGET_VAL(ISD::Constant),// ->3990
/*3961*/      OPC_RecordNode, // #0 = $b
/*3962*/      OPC_Scope, 12, /*->3976*/ // 2 children in Scope
/*3964*/        OPC_CheckPredicate, 18, // Predicate_immU6
/*3966*/        OPC_EmitConvertToTarget, 0,
/*3968*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDC_ru6), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (imm:i32)<<P:Predicate_immU6>>:$b - Complexity = 4
                // Dst: (LDC_ru6:i32 (imm:i32):$b)
/*3976*/      /*Scope*/ 12, /*->3989*/
/*3977*/        OPC_CheckPredicate, 19, // Predicate_immU16
/*3979*/        OPC_EmitConvertToTarget, 0,
/*3981*/        OPC_MorphNodeTo, TARGET_VAL(XCore::LDC_lru6), 0,
                    1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
                // Src: (imm:i32)<<P:Predicate_immU16>>:$b - Complexity = 4
                // Dst: (LDC_lru6:i32 (imm:i32):$b)
/*3989*/      0, /*End of Scope*/
/*3990*/    /*SwitchOpcode*/ 7, TARGET_VAL(XCoreISD::FRAME_TO_ARGS_OFFSET),// ->4000
/*3993*/      OPC_MorphNodeTo, TARGET_VAL(XCore::FRAME_TO_ARGS_OFFSET), 0,
                  1/*#VTs*/, MVT::i32, 0/*#Ops*/, 
              // Src: (frametoargsoffset:i32) - Complexity = 3
              // Dst: (FRAME_TO_ARGS_OFFSET:i32)
/*4000*/    /*SwitchOpcode*/ 15, TARGET_VAL(XCoreISD::EH_RETURN),// ->4018
/*4003*/      OPC_RecordNode, // #0 = 'XCoreEhRet' chained node
/*4004*/      OPC_CaptureGlueInput,
/*4005*/      OPC_RecordChild1, // #1 = $s
/*4006*/      OPC_CheckChild1Type, MVT::i32,
/*4008*/      OPC_RecordChild2, // #2 = $handler
/*4009*/      OPC_EmitMergeInputChains1_0,
/*4010*/      OPC_MorphNodeTo, TARGET_VAL(XCore::EH_RETURN), 0|OPFL_Chain|OPFL_GlueInput,
                  0/*#VTs*/, 2/*#Ops*/, 1, 2, 
              // Src: (XCoreEhRet GRRegs:i32:$s, GRRegs:i32:$handler) - Complexity = 3
              // Dst: (EH_RETURN GRRegs:i32:$s, GRRegs:i32:$handler)
/*4018*/    /*SwitchOpcode*/ 8, TARGET_VAL(XCoreISD::MEMBARRIER),// ->4029
/*4021*/      OPC_RecordNode, // #0 = 'XCoreMemBarrier' chained node
/*4022*/      OPC_EmitMergeInputChains1_0,
/*4023*/      OPC_MorphNodeTo, TARGET_VAL(XCore::Int_MemBarrier), 0|OPFL_Chain,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (XCoreMemBarrier) - Complexity = 3
              // Dst: (Int_MemBarrier)
/*4029*/    /*SwitchOpcode*/ 11, TARGET_VAL(ISD::OR),// ->4043
/*4032*/      OPC_RecordChild0, // #0 = $b
/*4033*/      OPC_RecordChild1, // #1 = $c
/*4034*/      OPC_MorphNodeTo, TARGET_VAL(XCore::OR_3r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (or:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
              // Dst: (OR_3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4043*/    /*SwitchOpcode*/ 11, TARGET_VAL(ISD::SDIV),// ->4057
/*4046*/      OPC_RecordChild0, // #0 = $b
/*4047*/      OPC_RecordChild1, // #1 = $c
/*4048*/      OPC_MorphNodeTo, TARGET_VAL(XCore::DIVS_l3r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (sdiv:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
              // Dst: (DIVS_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4057*/    /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UDIV),// ->4071
/*4060*/      OPC_RecordChild0, // #0 = $b
/*4061*/      OPC_RecordChild1, // #1 = $c
/*4062*/      OPC_MorphNodeTo, TARGET_VAL(XCore::DIVU_l3r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (udiv:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
              // Dst: (DIVU_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4071*/    /*SwitchOpcode*/ 11, TARGET_VAL(ISD::SREM),// ->4085
/*4074*/      OPC_RecordChild0, // #0 = $b
/*4075*/      OPC_RecordChild1, // #1 = $c
/*4076*/      OPC_MorphNodeTo, TARGET_VAL(XCore::REMS_l3r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (srem:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
              // Dst: (REMS_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4085*/    /*SwitchOpcode*/ 11, TARGET_VAL(ISD::UREM),// ->4099
/*4088*/      OPC_RecordChild0, // #0 = $b
/*4089*/      OPC_RecordChild1, // #1 = $c
/*4090*/      OPC_MorphNodeTo, TARGET_VAL(XCore::REMU_l3r), 0,
                  1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
              // Src: (urem:i32 GRRegs:i32:$b, GRRegs:i32:$c) - Complexity = 3
              // Dst: (REMU_l3r:i32 GRRegs:i32:$b, GRRegs:i32:$c)
/*4099*/    /*SwitchOpcode*/ 9, TARGET_VAL(ISD::BSWAP),// ->4111
/*4102*/      OPC_RecordChild0, // #0 = $src
/*4103*/      OPC_MorphNodeTo, TARGET_VAL(XCore::BYTEREV_l2r), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (bswap:i32 GRRegs:i32:$src) - Complexity = 3
              // Dst: (BYTEREV_l2r:i32 GRRegs:i32:$src)
/*4111*/    /*SwitchOpcode*/ 9, TARGET_VAL(ISD::CTLZ),// ->4123
/*4114*/      OPC_RecordChild0, // #0 = $src
/*4115*/      OPC_MorphNodeTo, TARGET_VAL(XCore::CLZ_l2r), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0, 
              // Src: (ctlz:i32 GRRegs:i32:$src) - Complexity = 3
              // Dst: (CLZ_l2r:i32 GRRegs:i32:$src)
/*4123*/    /*SwitchOpcode*/ 53, TARGET_VAL(ISD::SIGN_EXTEND_INREG),// ->4179
/*4126*/      OPC_RecordChild0, // #0 = $b
/*4127*/      OPC_MoveChild, 1,
/*4129*/      OPC_Scope, 15, /*->4146*/ // 3 children in Scope
/*4131*/        OPC_CheckValueType, MVT::i1,
/*4133*/        OPC_MoveParent,
/*4134*/        OPC_EmitInteger, MVT::i32, 1, 
/*4137*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sext_inreg:i32 GRRegs:i32:$b, i1:Other) - Complexity = 3
                // Dst: (SEXT_rus:i32 GRRegs:i32:$b, 1:i32)
/*4146*/      /*Scope*/ 15, /*->4162*/
/*4147*/        OPC_CheckValueType, MVT::i8,
/*4149*/        OPC_MoveParent,
/*4150*/        OPC_EmitInteger, MVT::i32, 8, 
/*4153*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sext_inreg:i32 GRRegs:i32:$b, i8:Other) - Complexity = 3
                // Dst: (SEXT_rus:i32 GRRegs:i32:$b, 8:i32)
/*4162*/      /*Scope*/ 15, /*->4178*/
/*4163*/        OPC_CheckValueType, MVT::i16,
/*4165*/        OPC_MoveParent,
/*4166*/        OPC_EmitInteger, MVT::i32, 16, 
/*4169*/        OPC_MorphNodeTo, TARGET_VAL(XCore::SEXT_rus), 0,
                    1/*#VTs*/, MVT::i32, 2/*#Ops*/, 0, 1, 
                // Src: (sext_inreg:i32 GRRegs:i32:$b, i16:Other) - Complexity = 3
                // Dst: (SEXT_rus:i32 GRRegs:i32:$b, 16:i32)
/*4178*/      0, /*End of Scope*/
/*4179*/    /*SwitchOpcode*/ 16, TARGET_VAL(ISD::BR),// ->4198
/*4182*/      OPC_RecordNode, // #0 = 'br' chained node
/*4183*/      OPC_RecordChild1, // #1 = $addr
/*4184*/      OPC_MoveChild, 1,
/*4186*/      OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*4189*/      OPC_MoveParent,
/*4190*/      OPC_EmitMergeInputChains1_0,
/*4191*/      OPC_MorphNodeTo, TARGET_VAL(XCore::BRFU_lu6), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (br (bb:Other):$addr) - Complexity = 3
              // Dst: (BRFU_lu6 (bb:Other):$addr)
/*4198*/    /*SwitchOpcode*/ 17, TARGET_VAL(ISD::CTTZ),// ->4218
/*4201*/      OPC_RecordChild0, // #0 = $src
/*4202*/      OPC_EmitNode, TARGET_VAL(XCore::BITREV_l2r), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 0,  // Results = #1
/*4210*/      OPC_MorphNodeTo, TARGET_VAL(XCore::CLZ_l2r), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1, 
              // Src: (cttz:i32 GRRegs:i32:$src) - Complexity = 3
              // Dst: (CLZ_l2r:i32 (BITREV_l2r:i32 GRRegs:i32:$src))
/*4218*/    /*SwitchOpcode*/ 20, TARGET_VAL(ISD::TRAP),// ->4241
/*4221*/      OPC_RecordNode, // #0 = 'trap' chained node
/*4222*/      OPC_EmitMergeInputChains1_0,
/*4223*/      OPC_EmitInteger, MVT::i32, 0, 
/*4226*/      OPC_EmitNode, TARGET_VAL(XCore::LDC_ru6), 0,
                  1/*#VTs*/, MVT::i32, 1/*#Ops*/, 1,  // Results = #2
/*4234*/      OPC_MorphNodeTo, TARGET_VAL(XCore::ECALLF_1r), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 2, 
              // Src: (trap) - Complexity = 3
              // Dst: (ECALLF_1r (LDC_ru6:i32 0:i32))
/*4241*/    0, // EndSwitchOpcode
    0
  }; // Total Array size is 4243 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 65
  // #OPC_RecordNode                     = 22
  // #OPC_RecordChild                    = 200
  // #OPC_RecordMemRef                   = 2
  // #OPC_CaptureGlueInput               = 4
  // #OPC_MoveChild                      = 77
  // #OPC_MoveParent                     = 152
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 1
  // #OPC_CheckPatternPredicate          = 0
  // #OPC_CheckPredicate                 = 97
  // #OPC_CheckOpcode                    = 59
  // #OPC_SwitchOpcode                   = 7
  // #OPC_CheckType                      = 46
  // #OPC_SwitchType                     = 0
  // #OPC_CheckChildType                 = 57
  // #OPC_CheckInteger                   = 0
  // #OPC_CheckChildInteger              = 80
  // #OPC_CheckCondCode                  = 33
  // #OPC_CheckValueType                 = 3
  // #OPC_CheckComplexPat                = 4
  // #OPC_CheckAndImm                    = 0
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 1
  // #OPC_EmitInteger                    = 25
  // #OPC_EmitStringInteger              = 0
  // #OPC_EmitRegister                   = 0
  // #OPC_EmitConvertToTarget            = 36
  // #OPC_EmitMergeInputChains           = 110
  // #OPC_EmitCopyToReg                  = 2
  // #OPC_EmitNode                       = 31
  // #OPC_EmitNodeXForm                  = 8
  // #OPC_MarkGlueResults                = 0
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 197

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

bool CheckNodePredicate(SDNode *Node,
                        unsigned PredNo) const override {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { 
    // Predicate_immUs
    auto *N = cast<ConstantSDNode>(Node);

  return (uint32_t)N->getZExtValue() <= 11;

  }
  case 1: { 
    // Predicate_immUs4
    auto *N = cast<ConstantSDNode>(Node);

  uint32_t value = (uint32_t)N->getZExtValue();
  return value%4 == 0 && value/4 <= 11;

  }
  case 2: { 
    // Predicate_immUsNeg
    auto *N = cast<ConstantSDNode>(Node);

  return -((uint32_t)N->getZExtValue()) <= 11;

  }
  case 3: { 
    // Predicate_immUs4Neg
    auto *N = cast<ConstantSDNode>(Node);

  uint32_t value = (uint32_t)N->getZExtValue();
  return (-value)%4 == 0 && (-value)/4 <= 11;

  }
  case 4: { 
    // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 5: { 
    // Predicate_sextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::SEXTLOAD;

  }
  case 6: { 
    // Predicate_sextloadi16
    // Predicate_extloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 7: { 
    // Predicate_extload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::EXTLOAD;

  }
  case 8: { 
    // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 9: { 
    // Predicate_zextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::ZEXTLOAD;

  }
  case 10: { 
    // Predicate_zextloadi8
    // Predicate_extloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 11: { 
    // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 12: { 
    // Predicate_truncstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 13: { 
    // Predicate_truncstorei16
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 14: { 
    // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 15: { 
    // Predicate_truncstorei8
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 16: { 
    // Predicate_immBpwSubBitp
    auto *N = cast<ConstantSDNode>(Node);

  uint32_t value = (uint32_t)N->getZExtValue();
  return (value >= 24 && value <= 31)
          || value == 16
          || value == 8
          || value == 0;

  }
  case 17: { 
    // Predicate_immBitp
    auto *N = cast<ConstantSDNode>(Node);

  uint32_t value = (uint32_t)N->getZExtValue();
  return (value >= 1 && value <= 8)
          || value == 16
          || value == 24
          || value == 32;

  }
  case 18: { 
    // Predicate_immU6
    auto *N = cast<ConstantSDNode>(Node);

  return (uint32_t)N->getZExtValue() < (1 << 6);

  }
  case 19: { 
    // Predicate_immU16
    auto *N = cast<ConstantSDNode>(Node);

  return (uint32_t)N->getZExtValue() < (1 << 16);

  }
  case 20: { 
    // Predicate_immMskBitp
    auto *N = cast<ConstantSDNode>(Node);
 return immMskBitp(N); 
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
    return SelectADDRspii(N, Result[NextRes+0].first, Result[NextRes+1].first);
  }
}

SDValue RunSDNodeXForm(SDValue V, unsigned XFormNo) override {
  switch (XFormNo) {
  default: llvm_unreachable("Invalid xform # in table?");
  case 0: {  // div4_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: imm/4
  assert(N->getZExtValue() % 4 == 0);
  return getI32Imm(N->getZExtValue()/4, SDLoc(N));

  }
  case 1: {  // neg_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: -imm
  uint32_t value = N->getZExtValue();
  return getI32Imm(-value, SDLoc(N));

  }
  case 2: {  // div4neg_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: -imm/4
  uint32_t value = N->getZExtValue();
  assert(-value % 4 == 0);
  return getI32Imm(-value/4, SDLoc(N));

  }
  case 3: {  // bpwsub_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: 32-imm
  uint32_t value = N->getZExtValue();
  return getI32Imm(32 - value, SDLoc(N));

  }
  case 4: {  // msksize_xform
    ConstantSDNode *N = cast<ConstantSDNode>(V.getNode());

  // Transformation function: get the size of a mask
  assert(isMask_32(N->getZExtValue()));
  // look for the first non-zero bit
  return getI32Imm(32 - countLeadingZeros((uint32_t)N->getZExtValue()),
                   SDLoc(N));

  }
  }
}

