/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* DAG Instruction Selector for the BPF target                                *|
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
/*0*/       OPC_SwitchOpcode /*24 cases */, 33|128,1/*161*/, TARGET_VAL(ISD::INTRINSIC_W_CHAIN),// ->166
/*5*/         OPC_RecordNode, // #0 = 'intrinsic_w_chain' chained node
/*6*/         OPC_Scope, 31, /*->39*/ // 4 children in Scope
/*8*/           OPC_CheckChild1Integer, 125|128,2/*381*/, 
/*11*/          OPC_RecordChild2, // #1 = $pseudo
/*12*/          OPC_MoveChild, 2,
/*14*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*17*/          OPC_MoveParent,
/*18*/          OPC_RecordChild3, // #2 = $imm
/*19*/          OPC_MoveChild, 3,
/*21*/          OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*24*/          OPC_MoveParent,
/*25*/          OPC_EmitMergeInputChains1_0,
/*26*/          OPC_EmitConvertToTarget, 1,
/*28*/          OPC_EmitConvertToTarget, 2,
/*30*/          OPC_MorphNodeTo, TARGET_VAL(BPF::LD_pseudo), 0|OPFL_Chain,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 3, 4, 
                // Src: (intrinsic_w_chain:i64 381:iPTR, (imm:i64):$pseudo, (imm:i64):$imm) - Complexity = 14
                // Dst: (LD_pseudo:i64 (imm:i64):$pseudo, (imm:i64):$imm)
/*39*/        /*Scope*/ 41, /*->81*/
/*40*/          OPC_CheckChild1Integer, 122|128,2/*378*/, 
/*43*/          OPC_RecordChild2, // #1 = $skb
/*44*/          OPC_CheckChild2Type, MVT::i64,
/*46*/          OPC_RecordChild3, // #2 = $imm
/*47*/          OPC_Scope, 20, /*->69*/ // 2 children in Scope
/*49*/            OPC_MoveChild, 3,
/*51*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*54*/            OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*56*/            OPC_MoveParent,
/*57*/            OPC_EmitMergeInputChains1_0,
/*58*/            OPC_EmitConvertToTarget, 2,
/*60*/            OPC_MorphNodeTo, TARGET_VAL(BPF::LD_ABS_B), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 3, 
                  // Src: (intrinsic_w_chain:i64 378:iPTR, GPR:i64:$skb, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 12
                  // Dst: (LD_ABS_B:i64 GPR:i64:$skb, (imm:i64):$imm)
/*69*/          /*Scope*/ 10, /*->80*/
/*70*/            OPC_EmitMergeInputChains1_0,
/*71*/            OPC_MorphNodeTo, TARGET_VAL(BPF::LD_IND_B), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                  // Src: (intrinsic_w_chain:i64 378:iPTR, GPR:i64:$skb, GPR:i64:$val) - Complexity = 8
                  // Dst: (LD_IND_B:i64 GPR:i64:$skb, GPR:i64:$val)
/*80*/          0, /*End of Scope*/
/*81*/        /*Scope*/ 41, /*->123*/
/*82*/          OPC_CheckChild1Integer, 123|128,2/*379*/, 
/*85*/          OPC_RecordChild2, // #1 = $skb
/*86*/          OPC_CheckChild2Type, MVT::i64,
/*88*/          OPC_RecordChild3, // #2 = $imm
/*89*/          OPC_Scope, 20, /*->111*/ // 2 children in Scope
/*91*/            OPC_MoveChild, 3,
/*93*/            OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*96*/            OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*98*/            OPC_MoveParent,
/*99*/            OPC_EmitMergeInputChains1_0,
/*100*/           OPC_EmitConvertToTarget, 2,
/*102*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LD_ABS_H), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 3, 
                  // Src: (intrinsic_w_chain:i64 379:iPTR, GPR:i64:$skb, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 12
                  // Dst: (LD_ABS_H:i64 GPR:i64:$skb, (imm:i64):$imm)
/*111*/         /*Scope*/ 10, /*->122*/
/*112*/           OPC_EmitMergeInputChains1_0,
/*113*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LD_IND_H), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                  // Src: (intrinsic_w_chain:i64 379:iPTR, GPR:i64:$skb, GPR:i64:$val) - Complexity = 8
                  // Dst: (LD_IND_H:i64 GPR:i64:$skb, GPR:i64:$val)
/*122*/         0, /*End of Scope*/
/*123*/       /*Scope*/ 41, /*->165*/
/*124*/         OPC_CheckChild1Integer, 124|128,2/*380*/, 
/*127*/         OPC_RecordChild2, // #1 = $skb
/*128*/         OPC_CheckChild2Type, MVT::i64,
/*130*/         OPC_RecordChild3, // #2 = $imm
/*131*/         OPC_Scope, 20, /*->153*/ // 2 children in Scope
/*133*/           OPC_MoveChild, 3,
/*135*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*138*/           OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*140*/           OPC_MoveParent,
/*141*/           OPC_EmitMergeInputChains1_0,
/*142*/           OPC_EmitConvertToTarget, 2,
/*144*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LD_ABS_W), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 3, 
                  // Src: (intrinsic_w_chain:i64 380:iPTR, GPR:i64:$skb, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 12
                  // Dst: (LD_ABS_W:i64 GPR:i64:$skb, (imm:i64):$imm)
/*153*/         /*Scope*/ 10, /*->164*/
/*154*/           OPC_EmitMergeInputChains1_0,
/*155*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LD_IND_W), 0|OPFL_Chain,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                  // Src: (intrinsic_w_chain:i64 380:iPTR, GPR:i64:$skb, GPR:i64:$val) - Complexity = 8
                  // Dst: (LD_IND_W:i64 GPR:i64:$skb, GPR:i64:$val)
/*164*/         0, /*End of Scope*/
/*165*/       0, /*End of Scope*/
/*166*/     /*SwitchOpcode*/ 81, TARGET_VAL(ISD::STORE),// ->250
/*169*/       OPC_RecordMemRef,
/*170*/       OPC_RecordNode, // #0 = 'st' chained node
/*171*/       OPC_RecordChild1, // #1 = $src
/*172*/       OPC_CheckChild1Type, MVT::i64,
/*174*/       OPC_RecordChild2, // #2 = $addr
/*175*/       OPC_CheckChild2Type, MVT::i64,
/*177*/       OPC_CheckPredicate, 1, // Predicate_unindexedstore
/*179*/       OPC_Scope, 52, /*->233*/ // 2 children in Scope
/*181*/         OPC_CheckPredicate, 2, // Predicate_truncstore
/*183*/         OPC_Scope, 15, /*->200*/ // 3 children in Scope
/*185*/           OPC_CheckPredicate, 3, // Predicate_truncstorei32
/*187*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*190*/           OPC_EmitMergeInputChains1_0,
/*191*/           OPC_MorphNodeTo, TARGET_VAL(BPF::STW), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                  // Src: (st i64:i64:$src, ADDRri:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei32>> - Complexity = 13
                  // Dst: (STW i64:i64:$src, ADDRri:i64:$addr)
/*200*/         /*Scope*/ 15, /*->216*/
/*201*/           OPC_CheckPredicate, 4, // Predicate_truncstorei16
/*203*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*206*/           OPC_EmitMergeInputChains1_0,
/*207*/           OPC_MorphNodeTo, TARGET_VAL(BPF::STH), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                  // Src: (st i64:i64:$src, ADDRri:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei16>> - Complexity = 13
                  // Dst: (STH i64:i64:$src, ADDRri:i64:$addr)
/*216*/         /*Scope*/ 15, /*->232*/
/*217*/           OPC_CheckPredicate, 5, // Predicate_truncstorei8
/*219*/           OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*222*/           OPC_EmitMergeInputChains1_0,
/*223*/           OPC_MorphNodeTo, TARGET_VAL(BPF::STB), 0|OPFL_Chain|OPFL_MemRefs,
                      0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                  // Src: (st i64:i64:$src, ADDRri:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_truncstore>><<P:Predicate_truncstorei8>> - Complexity = 13
                  // Dst: (STB i64:i64:$src, ADDRri:i64:$addr)
/*232*/         0, /*End of Scope*/
/*233*/       /*Scope*/ 15, /*->249*/
/*234*/         OPC_CheckPredicate, 6, // Predicate_store
/*236*/         OPC_CheckComplexPat, /*CP*/0, /*#*/2, // SelectAddr:$addr #3 #4
/*239*/         OPC_EmitMergeInputChains1_0,
/*240*/         OPC_MorphNodeTo, TARGET_VAL(BPF::STD), 0|OPFL_Chain|OPFL_MemRefs,
                    0/*#VTs*/, 3/*#Ops*/, 1, 3, 4, 
                // Src: (st i64:i64:$src, ADDRri:i64:$addr)<<P:Predicate_unindexedstore>><<P:Predicate_store>> - Complexity = 13
                // Dst: (STD i64:i64:$src, ADDRri:i64:$addr)
/*249*/       0, /*End of Scope*/
/*250*/     /*SwitchOpcode*/ 5|128,1/*133*/, TARGET_VAL(ISD::LOAD),// ->387
/*254*/       OPC_RecordMemRef,
/*255*/       OPC_RecordNode, // #0 = 'ld' chained node
/*256*/       OPC_RecordChild1, // #1 = $addr
/*257*/       OPC_CheckChild1Type, MVT::i64,
/*259*/       OPC_CheckPredicate, 7, // Predicate_unindexedload
/*261*/       OPC_CheckType, MVT::i64,
/*263*/       OPC_Scope, 52, /*->317*/ // 3 children in Scope
/*265*/         OPC_CheckPredicate, 8, // Predicate_zextload
/*267*/         OPC_Scope, 15, /*->284*/ // 3 children in Scope
/*269*/           OPC_CheckPredicate, 9, // Predicate_zextloadi32
/*271*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*274*/           OPC_EmitMergeInputChains1_0,
/*275*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LDW), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 ADDRri:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi32>> - Complexity = 13
                  // Dst: (LDW:i64 ADDRri:i64:$addr)
/*284*/         /*Scope*/ 15, /*->300*/
/*285*/           OPC_CheckPredicate, 10, // Predicate_zextloadi16
/*287*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*290*/           OPC_EmitMergeInputChains1_0,
/*291*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LDH), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 ADDRri:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi16>> - Complexity = 13
                  // Dst: (LDH:i64 ADDRri:i64:$addr)
/*300*/         /*Scope*/ 15, /*->316*/
/*301*/           OPC_CheckPredicate, 11, // Predicate_zextloadi8
/*303*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*306*/           OPC_EmitMergeInputChains1_0,
/*307*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LDB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 ADDRri:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_zextload>><<P:Predicate_zextloadi8>> - Complexity = 13
                  // Dst: (LDB:i64 ADDRri:i64:$addr)
/*316*/         0, /*End of Scope*/
/*317*/       /*Scope*/ 15, /*->333*/
/*318*/         OPC_CheckPredicate, 12, // Predicate_load
/*320*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #2 #3
/*323*/         OPC_EmitMergeInputChains1_0,
/*324*/         OPC_MorphNodeTo, TARGET_VAL(BPF::LDD), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (ld:i64 ADDRri:i64:$addr)<<P:Predicate_unindexedload>><<P:Predicate_load>> - Complexity = 13
                // Dst: (LDD:i64 ADDRri:i64:$addr)
/*333*/       /*Scope*/ 52, /*->386*/
/*334*/         OPC_CheckPredicate, 13, // Predicate_extload
/*336*/         OPC_Scope, 15, /*->353*/ // 3 children in Scope
/*338*/           OPC_CheckPredicate, 11, // Predicate_extloadi8
/*340*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*343*/           OPC_EmitMergeInputChains1_0,
/*344*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LDB), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 ADDRri:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi8>> - Complexity = 13
                  // Dst: (LDB:i64 ADDRri:i64:$src)
/*353*/         /*Scope*/ 15, /*->369*/
/*354*/           OPC_CheckPredicate, 10, // Predicate_extloadi16
/*356*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*359*/           OPC_EmitMergeInputChains1_0,
/*360*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LDH), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 ADDRri:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi16>> - Complexity = 13
                  // Dst: (LDH:i64 ADDRri:i64:$src)
/*369*/         /*Scope*/ 15, /*->385*/
/*370*/           OPC_CheckPredicate, 9, // Predicate_extloadi32
/*372*/           OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$src #2 #3
/*375*/           OPC_EmitMergeInputChains1_0,
/*376*/           OPC_MorphNodeTo, TARGET_VAL(BPF::LDW), 0|OPFL_Chain|OPFL_MemRefs,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                  // Src: (ld:i64 ADDRri:i64:$src)<<P:Predicate_unindexedload>><<P:Predicate_extload>><<P:Predicate_extloadi32>> - Complexity = 13
                  // Dst: (LDW:i64 ADDRri:i64:$src)
/*385*/         0, /*End of Scope*/
/*386*/       0, /*End of Scope*/
/*387*/     /*SwitchOpcode*/ 42, TARGET_VAL(ISD::ATOMIC_LOAD_ADD),// ->432
/*390*/       OPC_RecordMemRef,
/*391*/       OPC_RecordNode, // #0 = 'atomic_load_add' chained node
/*392*/       OPC_RecordChild1, // #1 = $addr
/*393*/       OPC_CheckChild1Type, MVT::i64,
/*395*/       OPC_RecordChild2, // #2 = $val
/*396*/       OPC_Scope, 16, /*->414*/ // 2 children in Scope
/*398*/         OPC_CheckPredicate, 14, // Predicate_atomic_load_add_32
/*400*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*403*/         OPC_EmitMergeInputChains1_0,
/*404*/         OPC_MorphNodeTo, TARGET_VAL(BPF::XADD32), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_add:i64 ADDRri:i64:$addr, GPR:i64:$val)<<P:Predicate_atomic_load_add_32>> - Complexity = 13
                // Dst: (XADD32:i64 ADDRri:i64:$addr, GPR:i64:$val)
/*414*/       /*Scope*/ 16, /*->431*/
/*415*/         OPC_CheckPredicate, 15, // Predicate_atomic_load_add_64
/*417*/         OPC_CheckComplexPat, /*CP*/0, /*#*/1, // SelectAddr:$addr #3 #4
/*420*/         OPC_EmitMergeInputChains1_0,
/*421*/         OPC_MorphNodeTo, TARGET_VAL(BPF::XADD64), 0|OPFL_Chain|OPFL_MemRefs,
                    1/*#VTs*/, MVT::i64, 3/*#Ops*/, 3, 4, 2, 
                // Src: (atomic_load_add:i64 ADDRri:i64:$addr, GPR:i64:$val)<<P:Predicate_atomic_load_add_64>> - Complexity = 13
                // Dst: (XADD64:i64 ADDRri:i64:$addr, GPR:i64:$val)
/*431*/       0, /*End of Scope*/
/*432*/     /*SwitchOpcode*/ 43|128,2/*299*/, TARGET_VAL(BPFISD::BR_CC),// ->735
/*436*/       OPC_RecordNode, // #0 = 'BPFbrcc' chained node
/*437*/       OPC_CaptureGlueInput,
/*438*/       OPC_RecordChild1, // #1 = $dst
/*439*/       OPC_Scope, 26|128,1/*154*/, /*->596*/ // 2 children in Scope
/*442*/         OPC_RecordChild2, // #2 = $imm
/*443*/         OPC_MoveChild, 2,
/*445*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*448*/         OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*450*/         OPC_MoveParent,
/*451*/         OPC_MoveChild, 3,
/*453*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*456*/         OPC_Scope, 22, /*->480*/ // 6 children in Scope
/*458*/           OPC_CheckPredicate, 16, // Predicate_BPF_CC_EQ
/*460*/           OPC_MoveParent,
/*461*/           OPC_RecordChild4, // #3 = $BrDst
/*462*/           OPC_MoveChild, 4,
/*464*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*467*/           OPC_MoveParent,
/*468*/           OPC_EmitMergeInputChains1_0,
/*469*/           OPC_EmitConvertToTarget, 2,
/*471*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JEQ_ri), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm, (imm:i64)<<P:Predicate_BPF_CC_EQ>>, (bb:Other):$BrDst) - Complexity = 11
                  // Dst: (JEQ_ri i64:i64:$dst, (imm:i64):$imm, (bb:Other):$BrDst)
/*480*/         /*Scope*/ 22, /*->503*/
/*481*/           OPC_CheckPredicate, 17, // Predicate_BPF_CC_GTU
/*483*/           OPC_MoveParent,
/*484*/           OPC_RecordChild4, // #3 = $BrDst
/*485*/           OPC_MoveChild, 4,
/*487*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*490*/           OPC_MoveParent,
/*491*/           OPC_EmitMergeInputChains1_0,
/*492*/           OPC_EmitConvertToTarget, 2,
/*494*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JUGT_ri), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm, (imm:i64)<<P:Predicate_BPF_CC_GTU>>, (bb:Other):$BrDst) - Complexity = 11
                  // Dst: (JUGT_ri i64:i64:$dst, (imm:i64):$imm, (bb:Other):$BrDst)
/*503*/         /*Scope*/ 22, /*->526*/
/*504*/           OPC_CheckPredicate, 18, // Predicate_BPF_CC_GEU
/*506*/           OPC_MoveParent,
/*507*/           OPC_RecordChild4, // #3 = $BrDst
/*508*/           OPC_MoveChild, 4,
/*510*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*513*/           OPC_MoveParent,
/*514*/           OPC_EmitMergeInputChains1_0,
/*515*/           OPC_EmitConvertToTarget, 2,
/*517*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JUGE_ri), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm, (imm:i64)<<P:Predicate_BPF_CC_GEU>>, (bb:Other):$BrDst) - Complexity = 11
                  // Dst: (JUGE_ri i64:i64:$dst, (imm:i64):$imm, (bb:Other):$BrDst)
/*526*/         /*Scope*/ 22, /*->549*/
/*527*/           OPC_CheckPredicate, 19, // Predicate_BPF_CC_NE
/*529*/           OPC_MoveParent,
/*530*/           OPC_RecordChild4, // #3 = $BrDst
/*531*/           OPC_MoveChild, 4,
/*533*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*536*/           OPC_MoveParent,
/*537*/           OPC_EmitMergeInputChains1_0,
/*538*/           OPC_EmitConvertToTarget, 2,
/*540*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JNE_ri), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm, (imm:i64)<<P:Predicate_BPF_CC_NE>>, (bb:Other):$BrDst) - Complexity = 11
                  // Dst: (JNE_ri i64:i64:$dst, (imm:i64):$imm, (bb:Other):$BrDst)
/*549*/         /*Scope*/ 22, /*->572*/
/*550*/           OPC_CheckPredicate, 20, // Predicate_BPF_CC_GT
/*552*/           OPC_MoveParent,
/*553*/           OPC_RecordChild4, // #3 = $BrDst
/*554*/           OPC_MoveChild, 4,
/*556*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*559*/           OPC_MoveParent,
/*560*/           OPC_EmitMergeInputChains1_0,
/*561*/           OPC_EmitConvertToTarget, 2,
/*563*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JSGT_ri), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm, (imm:i64)<<P:Predicate_BPF_CC_GT>>, (bb:Other):$BrDst) - Complexity = 11
                  // Dst: (JSGT_ri i64:i64:$dst, (imm:i64):$imm, (bb:Other):$BrDst)
/*572*/         /*Scope*/ 22, /*->595*/
/*573*/           OPC_CheckPredicate, 21, // Predicate_BPF_CC_GE
/*575*/           OPC_MoveParent,
/*576*/           OPC_RecordChild4, // #3 = $BrDst
/*577*/           OPC_MoveChild, 4,
/*579*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*582*/           OPC_MoveParent,
/*583*/           OPC_EmitMergeInputChains1_0,
/*584*/           OPC_EmitConvertToTarget, 2,
/*586*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JSGE_ri), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 4, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm, (imm:i64)<<P:Predicate_BPF_CC_GE>>, (bb:Other):$BrDst) - Complexity = 11
                  // Dst: (JSGE_ri i64:i64:$dst, (imm:i64):$imm, (bb:Other):$BrDst)
/*595*/         0, /*End of Scope*/
/*596*/       /*Scope*/ 8|128,1/*136*/, /*->734*/
/*598*/         OPC_CheckChild1Type, MVT::i64,
/*600*/         OPC_RecordChild2, // #2 = $src
/*601*/         OPC_MoveChild, 3,
/*603*/         OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*606*/         OPC_Scope, 20, /*->628*/ // 6 children in Scope
/*608*/           OPC_CheckPredicate, 16, // Predicate_BPF_CC_EQ
/*610*/           OPC_MoveParent,
/*611*/           OPC_RecordChild4, // #3 = $BrDst
/*612*/           OPC_MoveChild, 4,
/*614*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*617*/           OPC_MoveParent,
/*618*/           OPC_EmitMergeInputChains1_0,
/*619*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JEQ_rr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, i64:i64:$src, (imm:i64)<<P:Predicate_BPF_CC_EQ>>, (bb:Other):$BrDst) - Complexity = 7
                  // Dst: (JEQ_rr i64:i64:$dst, i64:i64:$src, (bb:Other):$BrDst)
/*628*/         /*Scope*/ 20, /*->649*/
/*629*/           OPC_CheckPredicate, 17, // Predicate_BPF_CC_GTU
/*631*/           OPC_MoveParent,
/*632*/           OPC_RecordChild4, // #3 = $BrDst
/*633*/           OPC_MoveChild, 4,
/*635*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*638*/           OPC_MoveParent,
/*639*/           OPC_EmitMergeInputChains1_0,
/*640*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JUGT_rr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, i64:i64:$src, (imm:i64)<<P:Predicate_BPF_CC_GTU>>, (bb:Other):$BrDst) - Complexity = 7
                  // Dst: (JUGT_rr i64:i64:$dst, i64:i64:$src, (bb:Other):$BrDst)
/*649*/         /*Scope*/ 20, /*->670*/
/*650*/           OPC_CheckPredicate, 18, // Predicate_BPF_CC_GEU
/*652*/           OPC_MoveParent,
/*653*/           OPC_RecordChild4, // #3 = $BrDst
/*654*/           OPC_MoveChild, 4,
/*656*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*659*/           OPC_MoveParent,
/*660*/           OPC_EmitMergeInputChains1_0,
/*661*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JUGE_rr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, i64:i64:$src, (imm:i64)<<P:Predicate_BPF_CC_GEU>>, (bb:Other):$BrDst) - Complexity = 7
                  // Dst: (JUGE_rr i64:i64:$dst, i64:i64:$src, (bb:Other):$BrDst)
/*670*/         /*Scope*/ 20, /*->691*/
/*671*/           OPC_CheckPredicate, 19, // Predicate_BPF_CC_NE
/*673*/           OPC_MoveParent,
/*674*/           OPC_RecordChild4, // #3 = $BrDst
/*675*/           OPC_MoveChild, 4,
/*677*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*680*/           OPC_MoveParent,
/*681*/           OPC_EmitMergeInputChains1_0,
/*682*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JNE_rr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, i64:i64:$src, (imm:i64)<<P:Predicate_BPF_CC_NE>>, (bb:Other):$BrDst) - Complexity = 7
                  // Dst: (JNE_rr i64:i64:$dst, i64:i64:$src, (bb:Other):$BrDst)
/*691*/         /*Scope*/ 20, /*->712*/
/*692*/           OPC_CheckPredicate, 20, // Predicate_BPF_CC_GT
/*694*/           OPC_MoveParent,
/*695*/           OPC_RecordChild4, // #3 = $BrDst
/*696*/           OPC_MoveChild, 4,
/*698*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*701*/           OPC_MoveParent,
/*702*/           OPC_EmitMergeInputChains1_0,
/*703*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JSGT_rr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, i64:i64:$src, (imm:i64)<<P:Predicate_BPF_CC_GT>>, (bb:Other):$BrDst) - Complexity = 7
                  // Dst: (JSGT_rr i64:i64:$dst, i64:i64:$src, (bb:Other):$BrDst)
/*712*/         /*Scope*/ 20, /*->733*/
/*713*/           OPC_CheckPredicate, 21, // Predicate_BPF_CC_GE
/*715*/           OPC_MoveParent,
/*716*/           OPC_RecordChild4, // #3 = $BrDst
/*717*/           OPC_MoveChild, 4,
/*719*/           OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*722*/           OPC_MoveParent,
/*723*/           OPC_EmitMergeInputChains1_0,
/*724*/           OPC_MorphNodeTo, TARGET_VAL(BPF::JSGE_rr), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                      0/*#VTs*/, 3/*#Ops*/, 1, 2, 3, 
                  // Src: (BPFbrcc i64:i64:$dst, i64:i64:$src, (imm:i64)<<P:Predicate_BPF_CC_GE>>, (bb:Other):$BrDst) - Complexity = 7
                  // Dst: (JSGE_rr i64:i64:$dst, i64:i64:$src, (bb:Other):$BrDst)
/*733*/         0, /*End of Scope*/
/*734*/       0, /*End of Scope*/
/*735*/     /*SwitchOpcode*/ 69, TARGET_VAL(ISD::SRL),// ->807
/*738*/       OPC_Scope, 31, /*->771*/ // 2 children in Scope
/*740*/         OPC_MoveChild, 0,
/*742*/         OPC_CheckOpcode, TARGET_VAL(ISD::BSWAP),
/*745*/         OPC_RecordChild0, // #0 = $src
/*746*/         OPC_MoveParent,
/*747*/         OPC_Scope, 10, /*->759*/ // 2 children in Scope
/*749*/           OPC_CheckChild1Integer, 48, 
/*751*/           OPC_MorphNodeTo, TARGET_VAL(BPF::BSWAP16), 0,
                      1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                  // Src: (srl:i64 (bswap:i64 GPR:i64:$src), 48:i64) - Complexity = 11
                  // Dst: (BSWAP16:i64 GPR:i64:$src)
/*759*/         /*Scope*/ 10, /*->770*/
/*760*/           OPC_CheckChild1Integer, 32, 
/*762*/           OPC_MorphNodeTo, TARGET_VAL(BPF::BSWAP32), 0,
                      1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
                  // Src: (srl:i64 (bswap:i64 GPR:i64:$src), 32:i64) - Complexity = 11
                  // Dst: (BSWAP32:i64 GPR:i64:$src)
/*770*/         0, /*End of Scope*/
/*771*/       /*Scope*/ 34, /*->806*/
/*772*/         OPC_RecordChild0, // #0 = $src2
/*773*/         OPC_RecordChild1, // #1 = $imm
/*774*/         OPC_Scope, 19, /*->795*/ // 2 children in Scope
/*776*/           OPC_MoveChild, 1,
/*778*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*781*/           OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*783*/           OPC_MoveParent,
/*784*/           OPC_EmitConvertToTarget, 1,
/*786*/           OPC_MorphNodeTo, TARGET_VAL(BPF::SRL_ri), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                  // Src: (srl:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                  // Dst: (SRL_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*795*/         /*Scope*/ 9, /*->805*/
/*796*/           OPC_MorphNodeTo, TARGET_VAL(BPF::SRL_rr), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (srl:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                  // Dst: (SRL_rr:i64 i64:i64:$src2, i64:i64:$src)
/*805*/         0, /*End of Scope*/
/*806*/       0, /*End of Scope*/
/*807*/     /*SwitchOpcode*/ 53, TARGET_VAL(ISD::ADD),// ->863
/*810*/       OPC_Scope, 15, /*->827*/ // 2 children in Scope
/*812*/         OPC_RecordNode, // #0 = $addr
/*813*/         OPC_CheckType, MVT::i64,
/*815*/         OPC_CheckComplexPat, /*CP*/1, /*#*/0, // SelectFIAddr:$addr #1 #2
/*818*/         OPC_MorphNodeTo, TARGET_VAL(BPF::FI_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: FIri:i64:$addr - Complexity = 9
                // Dst: (FI_ri:i64 FIri:i64:$addr)
/*827*/       /*Scope*/ 34, /*->862*/
/*828*/         OPC_RecordChild0, // #0 = $src2
/*829*/         OPC_RecordChild1, // #1 = $imm
/*830*/         OPC_Scope, 19, /*->851*/ // 2 children in Scope
/*832*/           OPC_MoveChild, 1,
/*834*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*837*/           OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*839*/           OPC_MoveParent,
/*840*/           OPC_EmitConvertToTarget, 1,
/*842*/           OPC_MorphNodeTo, TARGET_VAL(BPF::ADD_ri), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                  // Src: (add:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                  // Dst: (ADD_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*851*/         /*Scope*/ 9, /*->861*/
/*852*/           OPC_MorphNodeTo, TARGET_VAL(BPF::ADD_rr), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (add:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                  // Dst: (ADD_rr:i64 i64:i64:$src2, i64:i64:$src)
/*861*/         0, /*End of Scope*/
/*862*/       0, /*End of Scope*/
/*863*/     /*SwitchOpcode*/ 53, TARGET_VAL(ISD::OR),// ->919
/*866*/       OPC_Scope, 15, /*->883*/ // 2 children in Scope
/*868*/         OPC_RecordNode, // #0 = $addr
/*869*/         OPC_CheckType, MVT::i64,
/*871*/         OPC_CheckComplexPat, /*CP*/1, /*#*/0, // SelectFIAddr:$addr #1 #2
/*874*/         OPC_MorphNodeTo, TARGET_VAL(BPF::FI_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
                // Src: FIri:i64:$addr - Complexity = 9
                // Dst: (FI_ri:i64 FIri:i64:$addr)
/*883*/       /*Scope*/ 34, /*->918*/
/*884*/         OPC_RecordChild0, // #0 = $src2
/*885*/         OPC_RecordChild1, // #1 = $imm
/*886*/         OPC_Scope, 19, /*->907*/ // 2 children in Scope
/*888*/           OPC_MoveChild, 1,
/*890*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*893*/           OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*895*/           OPC_MoveParent,
/*896*/           OPC_EmitConvertToTarget, 1,
/*898*/           OPC_MorphNodeTo, TARGET_VAL(BPF::OR_ri), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                  // Src: (or:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                  // Dst: (OR_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*907*/         /*Scope*/ 9, /*->917*/
/*908*/           OPC_MorphNodeTo, TARGET_VAL(BPF::OR_rr), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (or:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                  // Dst: (OR_rr:i64 i64:i64:$src2, i64:i64:$src)
/*917*/         0, /*End of Scope*/
/*918*/       0, /*End of Scope*/
/*919*/     /*SwitchOpcode*/ 26, TARGET_VAL(ISD::CALLSEQ_END),// ->948
/*922*/       OPC_RecordNode, // #0 = 'BPFcallseq_end' chained node
/*923*/       OPC_CaptureGlueInput,
/*924*/       OPC_RecordChild1, // #1 = $amt1
/*925*/       OPC_MoveChild, 1,
/*927*/       OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*930*/       OPC_MoveParent,
/*931*/       OPC_RecordChild2, // #2 = $amt2
/*932*/       OPC_MoveChild, 2,
/*934*/       OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*937*/       OPC_MoveParent,
/*938*/       OPC_EmitMergeInputChains1_0,
/*939*/       OPC_MorphNodeTo, TARGET_VAL(BPF::ADJCALLSTACKUP), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i64, 2/*#Ops*/, 1, 2, 
              // Src: (BPFcallseq_end (timm:iPTR):$amt1, (timm:iPTR):$amt2) - Complexity = 9
              // Dst: (ADJCALLSTACKUP:i64 (timm:i64):$amt1, (timm:i64):$amt2)
/*948*/     /*SwitchOpcode*/ 69, TARGET_VAL(ISD::AND),// ->1020
/*951*/       OPC_Scope, 31, /*->984*/ // 2 children in Scope
/*953*/         OPC_CheckAndImm, 127|128,127|128,127|128,127|128,15/*4294967295*/, 
/*959*/         OPC_RecordChild0, // #0 = $src
/*960*/         OPC_EmitInteger, MVT::i64, 32, 
/*963*/         OPC_EmitNode, TARGET_VAL(BPF::SLL_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1,  // Results = #2
/*972*/         OPC_EmitInteger, MVT::i64, 32, 
/*975*/         OPC_MorphNodeTo, TARGET_VAL(BPF::SRL_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 2, 3, 
                // Src: (and:i64 GPR:i64:$src, 4294967295:i64) - Complexity = 8
                // Dst: (SRL_ri:i64 (SLL_ri:i64 GPR:i64:$src, 32:i64), 32:i64)
/*984*/       /*Scope*/ 34, /*->1019*/
/*985*/         OPC_RecordChild0, // #0 = $src2
/*986*/         OPC_RecordChild1, // #1 = $imm
/*987*/         OPC_Scope, 19, /*->1008*/ // 2 children in Scope
/*989*/           OPC_MoveChild, 1,
/*991*/           OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*994*/           OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*996*/           OPC_MoveParent,
/*997*/           OPC_EmitConvertToTarget, 1,
/*999*/           OPC_MorphNodeTo, TARGET_VAL(BPF::AND_ri), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                  // Src: (and:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                  // Dst: (AND_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*1008*/        /*Scope*/ 9, /*->1018*/
/*1009*/          OPC_MorphNodeTo, TARGET_VAL(BPF::AND_rr), 0,
                      1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                  // Src: (and:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                  // Dst: (AND_rr:i64 i64:i64:$src2, i64:i64:$src)
/*1018*/        0, /*End of Scope*/
/*1019*/      0, /*End of Scope*/
/*1020*/    /*SwitchOpcode*/ 34, TARGET_VAL(ISD::SUB),// ->1057
/*1023*/      OPC_RecordChild0, // #0 = $src2
/*1024*/      OPC_RecordChild1, // #1 = $imm
/*1025*/      OPC_Scope, 19, /*->1046*/ // 2 children in Scope
/*1027*/        OPC_MoveChild, 1,
/*1029*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1032*/        OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*1034*/        OPC_MoveParent,
/*1035*/        OPC_EmitConvertToTarget, 1,
/*1037*/        OPC_MorphNodeTo, TARGET_VAL(BPF::SUB_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (sub:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                // Dst: (SUB_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*1046*/      /*Scope*/ 9, /*->1056*/
/*1047*/        OPC_MorphNodeTo, TARGET_VAL(BPF::SUB_rr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (sub:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                // Dst: (SUB_rr:i64 i64:i64:$src2, i64:i64:$src)
/*1056*/      0, /*End of Scope*/
/*1057*/    /*SwitchOpcode*/ 34, TARGET_VAL(ISD::SHL),// ->1094
/*1060*/      OPC_RecordChild0, // #0 = $src2
/*1061*/      OPC_RecordChild1, // #1 = $imm
/*1062*/      OPC_Scope, 19, /*->1083*/ // 2 children in Scope
/*1064*/        OPC_MoveChild, 1,
/*1066*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1069*/        OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*1071*/        OPC_MoveParent,
/*1072*/        OPC_EmitConvertToTarget, 1,
/*1074*/        OPC_MorphNodeTo, TARGET_VAL(BPF::SLL_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (shl:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                // Dst: (SLL_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*1083*/      /*Scope*/ 9, /*->1093*/
/*1084*/        OPC_MorphNodeTo, TARGET_VAL(BPF::SLL_rr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (shl:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                // Dst: (SLL_rr:i64 i64:i64:$src2, i64:i64:$src)
/*1093*/      0, /*End of Scope*/
/*1094*/    /*SwitchOpcode*/ 34, TARGET_VAL(ISD::XOR),// ->1131
/*1097*/      OPC_RecordChild0, // #0 = $src2
/*1098*/      OPC_RecordChild1, // #1 = $imm
/*1099*/      OPC_Scope, 19, /*->1120*/ // 2 children in Scope
/*1101*/        OPC_MoveChild, 1,
/*1103*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1106*/        OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*1108*/        OPC_MoveParent,
/*1109*/        OPC_EmitConvertToTarget, 1,
/*1111*/        OPC_MorphNodeTo, TARGET_VAL(BPF::XOR_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (xor:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                // Dst: (XOR_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*1120*/      /*Scope*/ 9, /*->1130*/
/*1121*/        OPC_MorphNodeTo, TARGET_VAL(BPF::XOR_rr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (xor:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                // Dst: (XOR_rr:i64 i64:i64:$src2, i64:i64:$src)
/*1130*/      0, /*End of Scope*/
/*1131*/    /*SwitchOpcode*/ 34, TARGET_VAL(ISD::SRA),// ->1168
/*1134*/      OPC_RecordChild0, // #0 = $src2
/*1135*/      OPC_RecordChild1, // #1 = $imm
/*1136*/      OPC_Scope, 19, /*->1157*/ // 2 children in Scope
/*1138*/        OPC_MoveChild, 1,
/*1140*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1143*/        OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*1145*/        OPC_MoveParent,
/*1146*/        OPC_EmitConvertToTarget, 1,
/*1148*/        OPC_MorphNodeTo, TARGET_VAL(BPF::SRA_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (sra:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                // Dst: (SRA_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*1157*/      /*Scope*/ 9, /*->1167*/
/*1158*/        OPC_MorphNodeTo, TARGET_VAL(BPF::SRA_rr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (sra:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                // Dst: (SRA_rr:i64 i64:i64:$src2, i64:i64:$src)
/*1167*/      0, /*End of Scope*/
/*1168*/    /*SwitchOpcode*/ 34, TARGET_VAL(ISD::MUL),// ->1205
/*1171*/      OPC_RecordChild0, // #0 = $src2
/*1172*/      OPC_RecordChild1, // #1 = $imm
/*1173*/      OPC_Scope, 19, /*->1194*/ // 2 children in Scope
/*1175*/        OPC_MoveChild, 1,
/*1177*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1180*/        OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*1182*/        OPC_MoveParent,
/*1183*/        OPC_EmitConvertToTarget, 1,
/*1185*/        OPC_MorphNodeTo, TARGET_VAL(BPF::MUL_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (mul:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                // Dst: (MUL_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*1194*/      /*Scope*/ 9, /*->1204*/
/*1195*/        OPC_MorphNodeTo, TARGET_VAL(BPF::MUL_rr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (mul:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                // Dst: (MUL_rr:i64 i64:i64:$src2, i64:i64:$src)
/*1204*/      0, /*End of Scope*/
/*1205*/    /*SwitchOpcode*/ 34, TARGET_VAL(ISD::UDIV),// ->1242
/*1208*/      OPC_RecordChild0, // #0 = $src2
/*1209*/      OPC_RecordChild1, // #1 = $imm
/*1210*/      OPC_Scope, 19, /*->1231*/ // 2 children in Scope
/*1212*/        OPC_MoveChild, 1,
/*1214*/        OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1217*/        OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*1219*/        OPC_MoveParent,
/*1220*/        OPC_EmitConvertToTarget, 1,
/*1222*/        OPC_MorphNodeTo, TARGET_VAL(BPF::DIV_ri), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 2, 
                // Src: (udiv:i64 GPR:i64:$src2, (imm:i64)<<P:Predicate_i64immSExt32>>:$imm) - Complexity = 7
                // Dst: (DIV_ri:i64 GPR:i64:$src2, (imm:i64):$imm)
/*1231*/      /*Scope*/ 9, /*->1241*/
/*1232*/        OPC_MorphNodeTo, TARGET_VAL(BPF::DIV_rr), 0,
                    1/*#VTs*/, MVT::i64, 2/*#Ops*/, 0, 1, 
                // Src: (udiv:i64 i64:i64:$src2, i64:i64:$src) - Complexity = 3
                // Dst: (DIV_rr:i64 i64:i64:$src2, i64:i64:$src)
/*1241*/      0, /*End of Scope*/
/*1242*/    /*SwitchOpcode*/ 17, TARGET_VAL(ISD::CALLSEQ_START),// ->1262
/*1245*/      OPC_RecordNode, // #0 = 'BPFcallseq_start' chained node
/*1246*/      OPC_RecordChild1, // #1 = $amt
/*1247*/      OPC_MoveChild, 1,
/*1249*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetConstant),
/*1252*/      OPC_MoveParent,
/*1253*/      OPC_EmitMergeInputChains1_0,
/*1254*/      OPC_MorphNodeTo, TARGET_VAL(BPF::ADJCALLSTACKDOWN), 0|OPFL_Chain|OPFL_GlueOutput,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
              // Src: (BPFcallseq_start (timm:iPTR):$amt) - Complexity = 6
              // Dst: (ADJCALLSTACKDOWN:i64 (timm:i64):$amt)
/*1262*/    /*SwitchOpcode*/ 17, TARGET_VAL(BPFISD::Wrapper),// ->1282
/*1265*/      OPC_RecordChild0, // #0 = $in
/*1266*/      OPC_MoveChild, 0,
/*1268*/      OPC_CheckOpcode, TARGET_VAL(ISD::TargetGlobalAddress),
/*1271*/      OPC_MoveParent,
/*1272*/      OPC_CheckType, MVT::i64,
/*1274*/      OPC_MorphNodeTo, TARGET_VAL(BPF::LD_imm64), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (BPFWrapper:i64 (tglobaladdr:i64):$in) - Complexity = 6
              // Dst: (LD_imm64:i64 (tglobaladdr:i64):$in)
/*1282*/    /*SwitchOpcode*/ 35, TARGET_VAL(BPFISD::CALL),// ->1320
/*1285*/      OPC_RecordNode, // #0 = 'BPFcall' chained node
/*1286*/      OPC_CaptureGlueInput,
/*1287*/      OPC_RecordChild1, // #1 = $dst
/*1288*/      OPC_MoveChild, 1,
/*1290*/      OPC_SwitchOpcode /*2 cases */, 10, TARGET_VAL(ISD::TargetGlobalAddress),// ->1304
/*1294*/        OPC_MoveParent,
/*1295*/        OPC_EmitMergeInputChains1_0,
/*1296*/        OPC_MorphNodeTo, TARGET_VAL(BPF::JAL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
                // Src: (BPFcall (tglobaladdr:iPTR):$dst) - Complexity = 6
                // Dst: (JAL:i64 (tglobaladdr:i64):$dst)
/*1304*/      /*SwitchOpcode*/ 12, TARGET_VAL(ISD::Constant),// ->1319
/*1307*/        OPC_MoveParent,
/*1308*/        OPC_EmitMergeInputChains1_0,
/*1309*/        OPC_EmitConvertToTarget, 1,
/*1311*/        OPC_MorphNodeTo, TARGET_VAL(BPF::JAL), 0|OPFL_Chain|OPFL_GlueInput|OPFL_GlueOutput|OPFL_Variadic1,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 2, 
                // Src: (BPFcall (imm:iPTR):$dst) - Complexity = 6
                // Dst: (JAL:i64 (imm:i64):$dst)
/*1319*/      0, // EndSwitchOpcode
/*1320*/    /*SwitchOpcode*/ 30, TARGET_VAL(BPFISD::SELECT_CC),// ->1353
/*1323*/      OPC_CaptureGlueInput,
/*1324*/      OPC_RecordChild0, // #0 = $lhs
/*1325*/      OPC_CheckChild0Type, MVT::i64,
/*1327*/      OPC_RecordChild1, // #1 = $rhs
/*1328*/      OPC_RecordChild2, // #2 = $imm
/*1329*/      OPC_MoveChild, 2,
/*1331*/      OPC_CheckOpcode, TARGET_VAL(ISD::Constant),
/*1334*/      OPC_MoveParent,
/*1335*/      OPC_RecordChild3, // #3 = $src
/*1336*/      OPC_RecordChild4, // #4 = $src2
/*1337*/      OPC_CheckType, MVT::i64,
/*1339*/      OPC_EmitConvertToTarget, 2,
/*1341*/      OPC_MorphNodeTo, TARGET_VAL(BPF::Select), 0|OPFL_GlueInput,
                  1/*#VTs*/, MVT::i64, 5/*#Ops*/, 0, 1, 5, 3, 4, 
              // Src: (BPFselectcc:i64 i64:i64:$lhs, i64:i64:$rhs, (imm:i64):$imm, i64:i64:$src, i64:i64:$src2) - Complexity = 6
              // Dst: (Select:i64 i64:i64:$lhs, i64:i64:$rhs, (imm:i64):$imm, i64:i64:$src, i64:i64:$src2)
/*1353*/    /*SwitchOpcode*/ 27, TARGET_VAL(ISD::Constant),// ->1383
/*1356*/      OPC_RecordNode, // #0 = $imm
/*1357*/      OPC_Scope, 12, /*->1371*/ // 2 children in Scope
/*1359*/        OPC_CheckPredicate, 0, // Predicate_i64immSExt32
/*1361*/        OPC_EmitConvertToTarget, 0,
/*1363*/        OPC_MorphNodeTo, TARGET_VAL(BPF::MOV_ri), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
                // Src: (imm:i64)<<P:Predicate_i64immSExt32>>:$imm - Complexity = 4
                // Dst: (MOV_ri:i64 (imm:i64):$imm)
/*1371*/      /*Scope*/ 10, /*->1382*/
/*1372*/        OPC_EmitConvertToTarget, 0,
/*1374*/        OPC_MorphNodeTo, TARGET_VAL(BPF::LD_imm64), 0,
                    1/*#VTs*/, MVT::i64, 1/*#Ops*/, 1, 
                // Src: (imm:i64):$imm - Complexity = 3
                // Dst: (LD_imm64:i64 (imm:i64):$imm)
/*1382*/      0, /*End of Scope*/
/*1383*/    /*SwitchOpcode*/ 16, TARGET_VAL(ISD::BR),// ->1402
/*1386*/      OPC_RecordNode, // #0 = 'br' chained node
/*1387*/      OPC_RecordChild1, // #1 = $BrDst
/*1388*/      OPC_MoveChild, 1,
/*1390*/      OPC_CheckOpcode, TARGET_VAL(ISD::BasicBlock),
/*1393*/      OPC_MoveParent,
/*1394*/      OPC_EmitMergeInputChains1_0,
/*1395*/      OPC_MorphNodeTo, TARGET_VAL(BPF::JMP), 0|OPFL_Chain,
                  0/*#VTs*/, 1/*#Ops*/, 1, 
              // Src: (br (bb:Other):$BrDst) - Complexity = 3
              // Dst: (JMP (bb:Other):$BrDst)
/*1402*/    /*SwitchOpcode*/ 9, TARGET_VAL(BPFISD::RET_FLAG),// ->1414
/*1405*/      OPC_RecordNode, // #0 = 'BPFretflag' chained node
/*1406*/      OPC_CaptureGlueInput,
/*1407*/      OPC_EmitMergeInputChains1_0,
/*1408*/      OPC_MorphNodeTo, TARGET_VAL(BPF::RET), 0|OPFL_Chain|OPFL_GlueInput|OPFL_Variadic0,
                  0/*#VTs*/, 0/*#Ops*/, 
              // Src: (BPFretflag) - Complexity = 3
              // Dst: (RET)
/*1414*/    /*SwitchOpcode*/ 9, TARGET_VAL(ISD::BSWAP),// ->1426
/*1417*/      OPC_RecordChild0, // #0 = $src
/*1418*/      OPC_MorphNodeTo, TARGET_VAL(BPF::BSWAP64), 0,
                  1/*#VTs*/, MVT::i64, 1/*#Ops*/, 0, 
              // Src: (bswap:i64 GPR:i64:$src) - Complexity = 3
              // Dst: (BSWAP64:i64 GPR:i64:$src)
/*1426*/    0, // EndSwitchOpcode
    0
  }; // Total Array size is 1428 bytes

  // Opcode Histogram:
  // #OPC_Scope                          = 29
  // #OPC_RecordNode                     = 13
  // #OPC_RecordChild                    = 62
  // #OPC_RecordMemRef                   = 3
  // #OPC_CaptureGlueInput               = 5
  // #OPC_MoveChild                      = 38
  // #OPC_MoveParent                     = 49
  // #OPC_CheckSame                      = 0
  // #OPC_CheckChildSame                 = 0
  // #OPC_CheckPatternPredicate          = 0
  // #OPC_CheckPredicate                 = 45
  // #OPC_CheckOpcode                    = 37
  // #OPC_SwitchOpcode                   = 2
  // #OPC_CheckType                      = 5
  // #OPC_SwitchType                     = 0
  // #OPC_CheckChildType                 = 9
  // #OPC_CheckInteger                   = 0
  // #OPC_CheckChildInteger              = 6
  // #OPC_CheckCondCode                  = 0
  // #OPC_CheckValueType                 = 0
  // #OPC_CheckComplexPat                = 15
  // #OPC_CheckAndImm                    = 1
  // #OPC_CheckOrImm                     = 0
  // #OPC_CheckFoldableChainNode         = 0
  // #OPC_EmitInteger                    = 2
  // #OPC_EmitStringInteger              = 0
  // #OPC_EmitRegister                   = 0
  // #OPC_EmitConvertToTarget            = 25
  // #OPC_EmitMergeInputChains           = 38
  // #OPC_EmitCopyToReg                  = 0
  // #OPC_EmitNode                       = 1
  // #OPC_EmitNodeXForm                  = 0
  // #OPC_MarkGlueResults                = 0
  // #OPC_CompleteMatch                  = 0
  // #OPC_MorphNodeTo                    = 68

  #undef TARGET_VAL
  return SelectCodeCommon(N, MatcherTable,sizeof(MatcherTable));
}

bool CheckNodePredicate(SDNode *Node,
                        unsigned PredNo) const override {
  switch (PredNo) {
  default: llvm_unreachable("Invalid predicate in table?");
  case 0: { 
    // Predicate_i64immSExt32
    auto *N = cast<ConstantSDNode>(Node);
return isInt<32>(N->getSExtValue()); 
  }
  case 1: { 
    // Predicate_unindexedstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 2: { 
    // Predicate_truncstore
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 3: { 
    // Predicate_truncstorei32
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 4: { 
    // Predicate_truncstorei16
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 5: { 
    // Predicate_truncstorei8
    SDNode *N = Node;

  return cast<StoreSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 6: { 
    // Predicate_store
    SDNode *N = Node;

  return !cast<StoreSDNode>(N)->isTruncatingStore();

  }
  case 7: { 
    // Predicate_unindexedload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getAddressingMode() == ISD::UNINDEXED;

  }
  case 8: { 
    // Predicate_zextload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::ZEXTLOAD;

  }
  case 9: { 
    // Predicate_zextloadi32
    // Predicate_extloadi32
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i32;

  }
  case 10: { 
    // Predicate_zextloadi16
    // Predicate_extloadi16
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i16;

  }
  case 11: { 
    // Predicate_zextloadi8
    // Predicate_extloadi8
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getMemoryVT() == MVT::i8;

  }
  case 12: { 
    // Predicate_load
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::NON_EXTLOAD;

  }
  case 13: { 
    // Predicate_extload
    SDNode *N = Node;

  return cast<LoadSDNode>(N)->getExtensionType() == ISD::EXTLOAD;

  }
  case 14: { 
    // Predicate_atomic_load_add_32
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i32;
  
  }
  case 15: { 
    // Predicate_atomic_load_add_64
    SDNode *N = Node;

    return cast<AtomicSDNode>(N)->getMemoryVT() == MVT::i64;
  
  }
  case 16: { 
    // Predicate_BPF_CC_EQ
    auto *N = cast<ConstantSDNode>(Node);
return (N->getZExtValue() == ISD::SETEQ);
  }
  case 17: { 
    // Predicate_BPF_CC_GTU
    auto *N = cast<ConstantSDNode>(Node);
return (N->getZExtValue() == ISD::SETUGT);
  }
  case 18: { 
    // Predicate_BPF_CC_GEU
    auto *N = cast<ConstantSDNode>(Node);
return (N->getZExtValue() == ISD::SETUGE);
  }
  case 19: { 
    // Predicate_BPF_CC_NE
    auto *N = cast<ConstantSDNode>(Node);
return (N->getZExtValue() == ISD::SETNE);
  }
  case 20: { 
    // Predicate_BPF_CC_GT
    auto *N = cast<ConstantSDNode>(Node);
return (N->getZExtValue() == ISD::SETGT);
  }
  case 21: { 
    // Predicate_BPF_CC_GE
    auto *N = cast<ConstantSDNode>(Node);
return (N->getZExtValue() == ISD::SETGE);
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
  case 1:
    Result.resize(NextRes+2);
    return SelectFIAddr(N, Result[NextRes+0].first, Result[NextRes+1].first);
  }
}

