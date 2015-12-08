/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*  * XCore Disassembler                                                      *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#include "llvm/MC/MCInst.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Support/LEB128.h"
#include "llvm/Support/raw_ostream.h"
#include <assert.h>

namespace llvm {

// Helper function for extracting fields from encoded instructions.
template<typename InsnType>
static InsnType fieldFromInstruction(InsnType insn, unsigned startBit,
                                     unsigned numBits) {
    assert(startBit + numBits <= (sizeof(InsnType)*8) &&
           "Instruction field out of bounds!");
    InsnType fieldMask;
    if (numBits == sizeof(InsnType)*8)
      fieldMask = (InsnType)(-1LL);
    else
      fieldMask = (((InsnType)1 << numBits) - 1) << startBit;
    return (insn & fieldMask) >> startBit;
}

static const uint8_t DecoderTable16[] = {
/* 0 */       MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 3 */       MCD::OPC_FilterValue, 0, 108, 0, // Skip to: 115
/* 7 */       MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 10 */      MCD::OPC_FilterValue, 236, 15, 4, 0, // Skip to: 19
/* 15 */      MCD::OPC_Decode, 244, 1, 0, // Opcode: WAITEU_0R
/* 19 */      MCD::OPC_FilterValue, 237, 15, 3, 0, // Skip to: 27
/* 24 */      MCD::OPC_Decode, 60, 0, // Opcode: CLRE_0R
/* 27 */      MCD::OPC_FilterValue, 238, 15, 4, 0, // Skip to: 36
/* 32 */      MCD::OPC_Decode, 219, 1, 0, // Opcode: SSYNC_0r
/* 36 */      MCD::OPC_FilterValue, 239, 15, 3, 0, // Skip to: 44
/* 41 */      MCD::OPC_Decode, 94, 0, // Opcode: FREET_0R
/* 44 */      MCD::OPC_FilterValue, 252, 15, 3, 0, // Skip to: 52
/* 49 */      MCD::OPC_Decode, 69, 0, // Opcode: DCALL_0R
/* 52 */      MCD::OPC_FilterValue, 253, 15, 3, 0, // Skip to: 60
/* 57 */      MCD::OPC_Decode, 126, 0, // Opcode: KRET_0R
/* 60 */      MCD::OPC_FilterValue, 254, 15, 3, 0, // Skip to: 68
/* 65 */      MCD::OPC_Decode, 75, 0, // Opcode: DRET_0R
/* 68 */      MCD::OPC_FilterValue, 255, 15, 4, 0, // Skip to: 77
/* 73 */      MCD::OPC_Decode, 200, 1, 0, // Opcode: SETKEP_0R
/* 77 */      MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 80 */      MCD::OPC_FilterValue, 126, 3, 0, // Skip to: 87
/* 84 */      MCD::OPC_Decode, 78, 1, // Opcode: EDU_1r
/* 87 */      MCD::OPC_FilterValue, 127, 3, 0, // Skip to: 94
/* 91 */      MCD::OPC_Decode, 81, 1, // Opcode: EEU_1r
/* 94 */      MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 97 */      MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 104
/* 101 */     MCD::OPC_Decode, 112, 2, // Opcode: INITPC_2r
/* 104 */     MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 111
/* 108 */     MCD::OPC_Decode, 106, 2, // Opcode: GETST_2r
/* 111 */     MCD::OPC_Decode, 231, 1, 3, // Opcode: STW_2rus
/* 115 */     MCD::OPC_FilterValue, 1, 114, 0, // Skip to: 233
/* 119 */     MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 122 */     MCD::OPC_FilterValue, 236, 15, 4, 0, // Skip to: 131
/* 127 */     MCD::OPC_Decode, 153, 1, 0, // Opcode: LDSPC_0R
/* 131 */     MCD::OPC_FilterValue, 237, 15, 4, 0, // Skip to: 140
/* 136 */     MCD::OPC_Decode, 224, 1, 0, // Opcode: STSPC_0R
/* 140 */     MCD::OPC_FilterValue, 238, 15, 4, 0, // Skip to: 149
/* 145 */     MCD::OPC_Decode, 154, 1, 0, // Opcode: LDSSR_0R
/* 149 */     MCD::OPC_FilterValue, 239, 15, 4, 0, // Skip to: 158
/* 154 */     MCD::OPC_Decode, 225, 1, 0, // Opcode: STSSR_0R
/* 158 */     MCD::OPC_FilterValue, 252, 15, 4, 0, // Skip to: 167
/* 163 */     MCD::OPC_Decode, 223, 1, 0, // Opcode: STSED_0R
/* 167 */     MCD::OPC_FilterValue, 253, 15, 4, 0, // Skip to: 176
/* 172 */     MCD::OPC_Decode, 222, 1, 0, // Opcode: STET_0R
/* 176 */     MCD::OPC_FilterValue, 254, 15, 3, 0, // Skip to: 184
/* 181 */     MCD::OPC_Decode, 96, 0, // Opcode: GETED_0R
/* 184 */     MCD::OPC_FilterValue, 255, 15, 3, 0, // Skip to: 192
/* 189 */     MCD::OPC_Decode, 97, 0, // Opcode: GETET_0R
/* 192 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 195 */     MCD::OPC_FilterValue, 126, 4, 0, // Skip to: 203
/* 199 */     MCD::OPC_Decode, 243, 1, 1, // Opcode: WAITET_1R
/* 203 */     MCD::OPC_FilterValue, 127, 4, 0, // Skip to: 211
/* 207 */     MCD::OPC_Decode, 242, 1, 1, // Opcode: WAITEF_1R
/* 211 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 214 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 221
/* 218 */     MCD::OPC_Decode, 110, 2, // Opcode: INITDP_2r
/* 221 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 229
/* 225 */     MCD::OPC_Decode, 184, 1, 4, // Opcode: OUTT_2r
/* 229 */     MCD::OPC_Decode, 164, 1, 3, // Opcode: LDW_2rus
/* 233 */     MCD::OPC_FilterValue, 2, 100, 0, // Skip to: 337
/* 237 */     MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 240 */     MCD::OPC_FilterValue, 236, 15, 3, 0, // Skip to: 248
/* 245 */     MCD::OPC_Decode, 70, 0, // Opcode: DENTSP_0R
/* 248 */     MCD::OPC_FilterValue, 237, 15, 3, 0, // Skip to: 256
/* 253 */     MCD::OPC_Decode, 74, 0, // Opcode: DRESTSP_0R
/* 256 */     MCD::OPC_FilterValue, 238, 15, 3, 0, // Skip to: 264
/* 261 */     MCD::OPC_Decode, 98, 0, // Opcode: GETID_0R
/* 264 */     MCD::OPC_FilterValue, 239, 15, 3, 0, // Skip to: 272
/* 269 */     MCD::OPC_Decode, 99, 0, // Opcode: GETKEP_0R
/* 272 */     MCD::OPC_FilterValue, 252, 15, 3, 0, // Skip to: 280
/* 277 */     MCD::OPC_Decode, 100, 0, // Opcode: GETKSP_0R
/* 280 */     MCD::OPC_FilterValue, 253, 15, 4, 0, // Skip to: 289
/* 285 */     MCD::OPC_Decode, 152, 1, 0, // Opcode: LDSED_0R
/* 289 */     MCD::OPC_FilterValue, 254, 15, 4, 0, // Skip to: 298
/* 294 */     MCD::OPC_Decode, 150, 1, 0, // Opcode: LDET_0R
/* 298 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 301 */     MCD::OPC_FilterValue, 126, 3, 0, // Skip to: 308
/* 305 */     MCD::OPC_Decode, 93, 1, // Opcode: FREER_1r
/* 308 */     MCD::OPC_FilterValue, 127, 4, 0, // Skip to: 316
/* 312 */     MCD::OPC_Decode, 172, 1, 1, // Opcode: MJOIN_1r
/* 316 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 319 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 326
/* 323 */     MCD::OPC_Decode, 113, 2, // Opcode: INITSP_2r
/* 326 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 334
/* 330 */     MCD::OPC_Decode, 198, 1, 4, // Opcode: SETD_2r
/* 334 */     MCD::OPC_Decode, 24, 5, // Opcode: ADD_3r
/* 337 */     MCD::OPC_FilterValue, 3, 41, 0, // Skip to: 382
/* 341 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 344 */     MCD::OPC_FilterValue, 126, 4, 0, // Skip to: 352
/* 348 */     MCD::OPC_Decode, 241, 1, 1, // Opcode: TSTART_1R
/* 352 */     MCD::OPC_FilterValue, 127, 4, 0, // Skip to: 360
/* 356 */     MCD::OPC_Decode, 175, 1, 1, // Opcode: MSYNC_1r
/* 360 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 363 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 370
/* 367 */     MCD::OPC_Decode, 109, 2, // Opcode: INITCP_2r
/* 370 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 378
/* 374 */     MCD::OPC_Decode, 239, 1, 6, // Opcode: TSETMR_2r
/* 378 */     MCD::OPC_Decode, 234, 1, 5, // Opcode: SUB_3r
/* 382 */     MCD::OPC_FilterValue, 4, 30, 0, // Skip to: 416
/* 386 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 389 */     MCD::OPC_FilterValue, 126, 3, 0, // Skip to: 396
/* 393 */     MCD::OPC_Decode, 37, 1, // Opcode: BLA_1r
/* 396 */     MCD::OPC_FilterValue, 127, 3, 0, // Skip to: 403
/* 400 */     MCD::OPC_Decode, 31, 1, // Opcode: BAU_1r
/* 403 */     MCD::OPC_CheckField, 4, 1, 1, 3, 0, // Skip to: 412
/* 409 */     MCD::OPC_Decode, 80, 2, // Opcode: EET_2r
/* 412 */     MCD::OPC_Decode, 216, 1, 5, // Opcode: SHL_3r
/* 416 */     MCD::OPC_FilterValue, 5, 39, 0, // Skip to: 459
/* 420 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 423 */     MCD::OPC_FilterValue, 126, 3, 0, // Skip to: 430
/* 427 */     MCD::OPC_Decode, 54, 1, // Opcode: BRU_1r
/* 430 */     MCD::OPC_FilterValue, 127, 4, 0, // Skip to: 438
/* 434 */     MCD::OPC_Decode, 206, 1, 1, // Opcode: SETSP_1r
/* 438 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 441 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 448
/* 445 */     MCD::OPC_Decode, 27, 7, // Opcode: ANDNOT_2r
/* 448 */     MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 455
/* 452 */     MCD::OPC_Decode, 79, 2, // Opcode: EEF_2r
/* 455 */     MCD::OPC_Decode, 218, 1, 5, // Opcode: SHR_3r
/* 459 */     MCD::OPC_FilterValue, 6, 41, 0, // Skip to: 504
/* 463 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 466 */     MCD::OPC_FilterValue, 126, 4, 0, // Skip to: 474
/* 470 */     MCD::OPC_Decode, 197, 1, 1, // Opcode: SETDP_1r
/* 474 */     MCD::OPC_FilterValue, 127, 4, 0, // Skip to: 482
/* 478 */     MCD::OPC_Decode, 193, 1, 1, // Opcode: SETCP_1r
/* 482 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 485 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 493
/* 489 */     MCD::OPC_Decode, 213, 1, 7, // Opcode: SEXT_2r
/* 493 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 501
/* 497 */     MCD::OPC_Decode, 214, 1, 8, // Opcode: SEXT_rus
/* 501 */     MCD::OPC_Decode, 87, 5, // Opcode: EQ_3r
/* 504 */     MCD::OPC_FilterValue, 7, 39, 0, // Skip to: 547
/* 508 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 511 */     MCD::OPC_FilterValue, 126, 3, 0, // Skip to: 518
/* 515 */     MCD::OPC_Decode, 71, 1, // Opcode: DGETREG_1r
/* 518 */     MCD::OPC_FilterValue, 127, 4, 0, // Skip to: 526
/* 522 */     MCD::OPC_Decode, 199, 1, 1, // Opcode: SETEV_1r
/* 526 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 529 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 536
/* 533 */     MCD::OPC_Decode, 107, 2, // Opcode: GETTS_2r
/* 536 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 544
/* 540 */     MCD::OPC_Decode, 204, 1, 4, // Opcode: SETPT_2r
/* 544 */     MCD::OPC_Decode, 28, 5, // Opcode: AND_3r
/* 547 */     MCD::OPC_FilterValue, 8, 41, 0, // Skip to: 592
/* 551 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 554 */     MCD::OPC_FilterValue, 126, 3, 0, // Skip to: 561
/* 558 */     MCD::OPC_Decode, 119, 1, // Opcode: KCALL_1r
/* 561 */     MCD::OPC_FilterValue, 127, 4, 0, // Skip to: 569
/* 565 */     MCD::OPC_Decode, 212, 1, 1, // Opcode: SETV_1r
/* 569 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 572 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 580
/* 576 */     MCD::OPC_Decode, 246, 1, 7, // Opcode: ZEXT_2r
/* 580 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 588
/* 584 */     MCD::OPC_Decode, 247, 1, 8, // Opcode: ZEXT_rus
/* 588 */     MCD::OPC_Decode, 179, 1, 5, // Opcode: OR_3r
/* 592 */     MCD::OPC_FilterValue, 9, 40, 0, // Skip to: 636
/* 596 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 599 */     MCD::OPC_FilterValue, 126, 3, 0, // Skip to: 606
/* 603 */     MCD::OPC_Decode, 76, 1, // Opcode: ECALLF_1r
/* 606 */     MCD::OPC_FilterValue, 127, 3, 0, // Skip to: 613
/* 610 */     MCD::OPC_Decode, 77, 1, // Opcode: ECALLT_1r
/* 613 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 616 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 624
/* 620 */     MCD::OPC_Decode, 180, 1, 2, // Opcode: OUTCT_2r
/* 624 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 632
/* 628 */     MCD::OPC_Decode, 181, 1, 9, // Opcode: OUTCT_rus
/* 632 */     MCD::OPC_Decode, 165, 1, 5, // Opcode: LDW_3r
/* 636 */     MCD::OPC_FilterValue, 10, 19, 0, // Skip to: 659
/* 640 */     MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 643 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 651
/* 647 */     MCD::OPC_Decode, 227, 1, 10, // Opcode: STWDP_ru6
/* 651 */     MCD::OPC_FilterValue, 1, 55, 2, // Skip to: 1222
/* 655 */     MCD::OPC_Decode, 230, 1, 10, // Opcode: STWSP_ru6
/* 659 */     MCD::OPC_FilterValue, 11, 19, 0, // Skip to: 682
/* 663 */     MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 666 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 674
/* 670 */     MCD::OPC_Decode, 160, 1, 10, // Opcode: LDWDP_ru6
/* 674 */     MCD::OPC_FilterValue, 1, 32, 2, // Skip to: 1222
/* 678 */     MCD::OPC_Decode, 163, 1, 10, // Opcode: LDWSP_ru6
/* 682 */     MCD::OPC_FilterValue, 12, 19, 0, // Skip to: 705
/* 686 */     MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 689 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 697
/* 693 */     MCD::OPC_Decode, 142, 1, 10, // Opcode: LDAWDP_ru6
/* 697 */     MCD::OPC_FilterValue, 1, 9, 2, // Skip to: 1222
/* 701 */     MCD::OPC_Decode, 147, 1, 10, // Opcode: LDAWSP_ru6
/* 705 */     MCD::OPC_FilterValue, 13, 19, 0, // Skip to: 728
/* 709 */     MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 712 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 720
/* 716 */     MCD::OPC_Decode, 149, 1, 10, // Opcode: LDC_ru6
/* 720 */     MCD::OPC_FilterValue, 1, 242, 1, // Skip to: 1222
/* 724 */     MCD::OPC_Decode, 157, 1, 10, // Opcode: LDWCP_ru6
/* 728 */     MCD::OPC_FilterValue, 14, 80, 0, // Skip to: 812
/* 732 */     MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 735 */     MCD::OPC_FilterValue, 0, 34, 0, // Skip to: 773
/* 739 */     MCD::OPC_ExtractField, 6, 4,  // Inst{9-6} ...
/* 742 */     MCD::OPC_FilterValue, 12, 3, 0, // Skip to: 749
/* 746 */     MCD::OPC_Decode, 53, 11, // Opcode: BRFU_u6
/* 749 */     MCD::OPC_FilterValue, 13, 3, 0, // Skip to: 756
/* 753 */     MCD::OPC_Decode, 36, 11, // Opcode: BLAT_u6
/* 756 */     MCD::OPC_FilterValue, 14, 3, 0, // Skip to: 763
/* 760 */     MCD::OPC_Decode, 89, 11, // Opcode: EXTDP_u6
/* 763 */     MCD::OPC_FilterValue, 15, 3, 0, // Skip to: 770
/* 767 */     MCD::OPC_Decode, 121, 11, // Opcode: KCALL_u6
/* 770 */     MCD::OPC_Decode, 51, 12, // Opcode: BRFT_ru6
/* 773 */     MCD::OPC_FilterValue, 1, 189, 1, // Skip to: 1222
/* 777 */     MCD::OPC_ExtractField, 6, 4,  // Inst{9-6} ...
/* 780 */     MCD::OPC_FilterValue, 12, 3, 0, // Skip to: 787
/* 784 */     MCD::OPC_Decode, 47, 13, // Opcode: BRBU_u6
/* 787 */     MCD::OPC_FilterValue, 13, 3, 0, // Skip to: 794
/* 791 */     MCD::OPC_Decode, 85, 11, // Opcode: ENTSP_u6
/* 794 */     MCD::OPC_FilterValue, 14, 3, 0, // Skip to: 801
/* 798 */     MCD::OPC_Decode, 91, 11, // Opcode: EXTSP_u6
/* 801 */     MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 809
/* 805 */     MCD::OPC_Decode, 190, 1, 11, // Opcode: RETSP_u6
/* 809 */     MCD::OPC_Decode, 45, 14, // Opcode: BRBT_ru6
/* 812 */     MCD::OPC_FilterValue, 15, 67, 0, // Skip to: 883
/* 816 */     MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 819 */     MCD::OPC_FilterValue, 0, 35, 0, // Skip to: 858
/* 823 */     MCD::OPC_ExtractField, 6, 4,  // Inst{9-6} ...
/* 826 */     MCD::OPC_FilterValue, 12, 3, 0, // Skip to: 833
/* 830 */     MCD::OPC_Decode, 65, 11, // Opcode: CLRSR_u6
/* 833 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 841
/* 837 */     MCD::OPC_Decode, 210, 1, 11, // Opcode: SETSR_u6
/* 841 */     MCD::OPC_FilterValue, 14, 3, 0, // Skip to: 848
/* 845 */     MCD::OPC_Decode, 123, 11, // Opcode: KENTSP_u6
/* 848 */     MCD::OPC_FilterValue, 15, 3, 0, // Skip to: 855
/* 852 */     MCD::OPC_Decode, 125, 11, // Opcode: KRESTSP_u6
/* 855 */     MCD::OPC_Decode, 49, 12, // Opcode: BRFF_ru6
/* 858 */     MCD::OPC_FilterValue, 1, 104, 1, // Skip to: 1222
/* 862 */     MCD::OPC_ExtractField, 6, 4,  // Inst{9-6} ...
/* 865 */     MCD::OPC_FilterValue, 12, 3, 0, // Skip to: 872
/* 869 */     MCD::OPC_Decode, 105, 11, // Opcode: GETSR_u6
/* 872 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 880
/* 876 */     MCD::OPC_Decode, 140, 1, 11, // Opcode: LDAWCP_u6
/* 880 */     MCD::OPC_Decode, 43, 14, // Opcode: BRBF_ru6
/* 883 */     MCD::OPC_FilterValue, 16, 39, 0, // Skip to: 926
/* 887 */     MCD::OPC_ExtractField, 4, 7,  // Inst{10-4} ...
/* 890 */     MCD::OPC_FilterValue, 126, 3, 0, // Skip to: 897
/* 894 */     MCD::OPC_Decode, 61, 1, // Opcode: CLRPT_1R
/* 897 */     MCD::OPC_FilterValue, 127, 4, 0, // Skip to: 905
/* 901 */     MCD::OPC_Decode, 235, 1, 1, // Opcode: SYNCR_1r
/* 905 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 908 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 915
/* 912 */     MCD::OPC_Decode, 103, 9, // Opcode: GETR_rus
/* 915 */     MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 922
/* 919 */     MCD::OPC_Decode, 108, 2, // Opcode: INCT_2r
/* 922 */     MCD::OPC_Decode, 128, 1, 5, // Opcode: LD16S_3r
/* 926 */     MCD::OPC_FilterValue, 17, 22, 0, // Skip to: 952
/* 930 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 933 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 941
/* 937 */     MCD::OPC_Decode, 178, 1, 2, // Opcode: NOT
/* 941 */     MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 948
/* 945 */     MCD::OPC_Decode, 116, 2, // Opcode: INT_2r
/* 948 */     MCD::OPC_Decode, 129, 1, 5, // Opcode: LD8U_3r
/* 952 */     MCD::OPC_FilterValue, 18, 21, 0, // Skip to: 977
/* 956 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 959 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 967
/* 963 */     MCD::OPC_Decode, 177, 1, 2, // Opcode: NEG
/* 967 */     MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 974
/* 971 */     MCD::OPC_Decode, 83, 2, // Opcode: ENDIN_2r
/* 974 */     MCD::OPC_Decode, 23, 3, // Opcode: ADD_2rus
/* 977 */     MCD::OPC_FilterValue, 19, 4, 0, // Skip to: 985
/* 981 */     MCD::OPC_Decode, 233, 1, 3, // Opcode: SUB_2rus
/* 985 */     MCD::OPC_FilterValue, 20, 23, 0, // Skip to: 1012
/* 989 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 992 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 1000
/* 996 */     MCD::OPC_Decode, 173, 1, 2, // Opcode: MKMSK_2r
/* 1000 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 1008
/* 1004 */    MCD::OPC_Decode, 174, 1, 15, // Opcode: MKMSK_rus
/* 1008 */    MCD::OPC_Decode, 215, 1, 16, // Opcode: SHL_2rus
/* 1012 */    MCD::OPC_FilterValue, 21, 23, 0, // Skip to: 1039
/* 1016 */    MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 1019 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 1027
/* 1023 */    MCD::OPC_Decode, 185, 1, 4, // Opcode: OUT_2r
/* 1027 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 1035
/* 1031 */    MCD::OPC_Decode, 183, 1, 7, // Opcode: OUTSHR_2r
/* 1035 */    MCD::OPC_Decode, 217, 1, 16, // Opcode: SHR_2rus
/* 1039 */    MCD::OPC_FilterValue, 22, 20, 0, // Skip to: 1063
/* 1043 */    MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 1046 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 1053
/* 1050 */    MCD::OPC_Decode, 117, 2, // Opcode: IN_2r
/* 1053 */    MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 1060
/* 1057 */    MCD::OPC_Decode, 115, 7, // Opcode: INSHR_2r
/* 1060 */    MCD::OPC_Decode, 86, 3, // Opcode: EQ_2rus
/* 1063 */    MCD::OPC_FilterValue, 23, 23, 0, // Skip to: 1090
/* 1067 */    MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 1070 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 1078
/* 1074 */    MCD::OPC_Decode, 186, 1, 2, // Opcode: PEEK_2r
/* 1078 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 1086
/* 1082 */    MCD::OPC_Decode, 236, 1, 2, // Opcode: TESTCT_2r
/* 1086 */    MCD::OPC_Decode, 240, 1, 17, // Opcode: TSETR_3r
/* 1090 */    MCD::OPC_FilterValue, 24, 23, 0, // Skip to: 1117
/* 1094 */    MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 1097 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 1105
/* 1101 */    MCD::OPC_Decode, 202, 1, 4, // Opcode: SETPSC_2r
/* 1105 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 1113
/* 1109 */    MCD::OPC_Decode, 238, 1, 2, // Opcode: TESTWCT_2r
/* 1113 */    MCD::OPC_Decode, 167, 1, 5, // Opcode: LSS_3r
/* 1117 */    MCD::OPC_FilterValue, 25, 21, 0, // Skip to: 1142
/* 1121 */    MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 1124 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 1131
/* 1128 */    MCD::OPC_Decode, 58, 2, // Opcode: CHKCT_2r
/* 1131 */    MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 1138
/* 1135 */    MCD::OPC_Decode, 59, 15, // Opcode: CHKCT_rus
/* 1138 */    MCD::OPC_Decode, 169, 1, 5, // Opcode: LSU_3r
/* 1142 */    MCD::OPC_FilterValue, 26, 17, 0, // Skip to: 1163
/* 1146 */    MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 1149 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 1156
/* 1153 */    MCD::OPC_Decode, 41, 18, // Opcode: BLRF_u10
/* 1156 */    MCD::OPC_FilterValue, 1, 62, 0, // Skip to: 1222
/* 1160 */    MCD::OPC_Decode, 39, 19, // Opcode: BLRB_u10
/* 1163 */    MCD::OPC_FilterValue, 27, 19, 0, // Skip to: 1186
/* 1167 */    MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 1170 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 1178
/* 1174 */    MCD::OPC_Decode, 136, 1, 18, // Opcode: LDAPF_u10
/* 1178 */    MCD::OPC_FilterValue, 1, 40, 0, // Skip to: 1222
/* 1182 */    MCD::OPC_Decode, 133, 1, 19, // Opcode: LDAPB_u10
/* 1186 */    MCD::OPC_FilterValue, 28, 18, 0, // Skip to: 1208
/* 1190 */    MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 1193 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 1200
/* 1197 */    MCD::OPC_Decode, 34, 18, // Opcode: BLACP_u10
/* 1200 */    MCD::OPC_FilterValue, 1, 18, 0, // Skip to: 1222
/* 1204 */    MCD::OPC_Decode, 158, 1, 18, // Opcode: LDWCP_u10
/* 1208 */    MCD::OPC_FilterValue, 29, 10, 0, // Skip to: 1222
/* 1212 */    MCD::OPC_CheckField, 10, 1, 0, 4, 0, // Skip to: 1222
/* 1218 */    MCD::OPC_Decode, 196, 1, 12, // Opcode: SETC_ru6
/* 1222 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable32[] = {
/* 0 */       MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 3 */       MCD::OPC_FilterValue, 0, 89, 0, // Skip to: 96
/* 7 */       MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 10 */      MCD::OPC_FilterValue, 31, 216, 3, // Skip to: 998
/* 14 */      MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 17 */      MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 31
/* 21 */      MCD::OPC_CheckField, 16, 11, 236, 15, 17, 0, // Skip to: 45
/* 28 */      MCD::OPC_Decode, 32, 20, // Opcode: BITREV_l2r
/* 31 */      MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 45
/* 35 */      MCD::OPC_CheckField, 16, 11, 236, 15, 3, 0, // Skip to: 45
/* 42 */      MCD::OPC_Decode, 57, 20, // Opcode: BYTEREV_l2r
/* 45 */      MCD::OPC_CheckField, 16, 11, 236, 15, 4, 0, // Skip to: 56
/* 52 */      MCD::OPC_Decode, 232, 1, 21, // Opcode: STW_l3r
/* 56 */      MCD::OPC_ExtractField, 20, 7,  // Inst{26-20} ...
/* 59 */      MCD::OPC_FilterValue, 126, 3, 0, // Skip to: 66
/* 63 */      MCD::OPC_Decode, 67, 22, // Opcode: CRC8_l4r
/* 66 */      MCD::OPC_FilterValue, 127, 4, 0, // Skip to: 74
/* 70 */      MCD::OPC_Decode, 171, 1, 23, // Opcode: MACCU_l4r
/* 74 */      MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 77 */      MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 85
/* 81 */      MCD::OPC_Decode, 151, 1, 24, // Opcode: LDIVU_l5r
/* 85 */      MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 92
/* 89 */      MCD::OPC_Decode, 127, 24, // Opcode: LADD_l5r
/* 92 */      MCD::OPC_Decode, 166, 1, 25, // Opcode: LMUL_l6r
/* 96 */      MCD::OPC_FilterValue, 1, 86, 0, // Skip to: 186
/* 100 */     MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 103 */     MCD::OPC_FilterValue, 31, 123, 3, // Skip to: 998
/* 107 */     MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 110 */     MCD::OPC_FilterValue, 0, 116, 3, // Skip to: 998
/* 114 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 117 */     MCD::OPC_FilterValue, 0, 15, 0, // Skip to: 136
/* 121 */     MCD::OPC_CheckField, 21, 6, 63, 29, 0, // Skip to: 156
/* 127 */     MCD::OPC_CheckField, 16, 4, 12, 23, 0, // Skip to: 156
/* 133 */     MCD::OPC_Decode, 66, 20, // Opcode: CLZ_l2r
/* 136 */     MCD::OPC_FilterValue, 1, 16, 0, // Skip to: 156
/* 140 */     MCD::OPC_CheckField, 21, 6, 63, 10, 0, // Skip to: 156
/* 146 */     MCD::OPC_CheckField, 16, 4, 12, 4, 0, // Skip to: 156
/* 152 */     MCD::OPC_Decode, 192, 1, 26, // Opcode: SETCLK_l2r
/* 156 */     MCD::OPC_CheckField, 21, 6, 63, 10, 0, // Skip to: 172
/* 162 */     MCD::OPC_CheckField, 16, 4, 12, 4, 0, // Skip to: 172
/* 168 */     MCD::OPC_Decode, 245, 1, 21, // Opcode: XOR_l3r
/* 172 */     MCD::OPC_CheckField, 21, 6, 63, 4, 0, // Skip to: 182
/* 178 */     MCD::OPC_Decode, 170, 1, 23, // Opcode: MACCS_l4r
/* 182 */     MCD::OPC_Decode, 168, 1, 24, // Opcode: LSUB_l5r
/* 186 */     MCD::OPC_FilterValue, 2, 29, 0, // Skip to: 219
/* 190 */     MCD::OPC_ExtractField, 11, 16,  // Inst{26-11} ...
/* 193 */     MCD::OPC_FilterValue, 159, 251, 3, 31, 3, // Skip to: 998
/* 199 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 202 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 209
/* 206 */     MCD::OPC_Decode, 111, 20, // Opcode: INITLR_l2r
/* 209 */     MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 216
/* 213 */     MCD::OPC_Decode, 102, 20, // Opcode: GETPS_l2r
/* 216 */     MCD::OPC_Decode, 30, 21, // Opcode: ASHR_l3r
/* 219 */     MCD::OPC_FilterValue, 3, 31, 0, // Skip to: 254
/* 223 */     MCD::OPC_ExtractField, 11, 16,  // Inst{26-11} ...
/* 226 */     MCD::OPC_FilterValue, 159, 251, 3, 254, 2, // Skip to: 998
/* 232 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 235 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 243
/* 239 */     MCD::OPC_Decode, 203, 1, 26, // Opcode: SETPS_l2r
/* 243 */     MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 250
/* 247 */     MCD::OPC_Decode, 95, 20, // Opcode: GETD_l2r
/* 250 */     MCD::OPC_Decode, 145, 1, 21, // Opcode: LDAWF_l3r
/* 254 */     MCD::OPC_FilterValue, 4, 32, 0, // Skip to: 290
/* 258 */     MCD::OPC_ExtractField, 11, 16,  // Inst{26-11} ...
/* 261 */     MCD::OPC_FilterValue, 159, 251, 3, 219, 2, // Skip to: 998
/* 267 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 270 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 278
/* 274 */     MCD::OPC_Decode, 237, 1, 20, // Opcode: TESTLCL_l2r
/* 278 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 286
/* 282 */     MCD::OPC_Decode, 211, 1, 26, // Opcode: SETTW_l2r
/* 286 */     MCD::OPC_Decode, 138, 1, 21, // Opcode: LDAWB_l3r
/* 290 */     MCD::OPC_FilterValue, 5, 32, 0, // Skip to: 326
/* 294 */     MCD::OPC_ExtractField, 11, 16,  // Inst{26-11} ...
/* 297 */     MCD::OPC_FilterValue, 159, 251, 3, 183, 2, // Skip to: 998
/* 303 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 306 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 314
/* 310 */     MCD::OPC_Decode, 205, 1, 26, // Opcode: SETRDY_l2r
/* 314 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 322
/* 318 */     MCD::OPC_Decode, 194, 1, 20, // Opcode: SETC_l2r
/* 322 */     MCD::OPC_Decode, 131, 1, 21, // Opcode: LDA16F_l3r
/* 326 */     MCD::OPC_FilterValue, 6, 31, 0, // Skip to: 361
/* 330 */     MCD::OPC_ExtractField, 11, 16,  // Inst{26-11} ...
/* 333 */     MCD::OPC_FilterValue, 159, 251, 3, 147, 2, // Skip to: 998
/* 339 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 342 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 350
/* 346 */     MCD::OPC_Decode, 201, 1, 26, // Opcode: SETN_l2r
/* 350 */     MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 357
/* 354 */     MCD::OPC_Decode, 101, 20, // Opcode: GETN_l2r
/* 357 */     MCD::OPC_Decode, 130, 1, 21, // Opcode: LDA16B_l3r
/* 361 */     MCD::OPC_FilterValue, 7, 12, 0, // Skip to: 377
/* 365 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 113, 2, // Skip to: 998
/* 373 */     MCD::OPC_Decode, 176, 1, 21, // Opcode: MUL_l3r
/* 377 */     MCD::OPC_FilterValue, 8, 11, 0, // Skip to: 392
/* 381 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 97, 2, // Skip to: 998
/* 389 */     MCD::OPC_Decode, 72, 21, // Opcode: DIVS_l3r
/* 392 */     MCD::OPC_FilterValue, 9, 11, 0, // Skip to: 407
/* 396 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 82, 2, // Skip to: 998
/* 404 */     MCD::OPC_Decode, 73, 21, // Opcode: DIVU_l3r
/* 407 */     MCD::OPC_FilterValue, 10, 31, 0, // Skip to: 442
/* 411 */     MCD::OPC_ExtractField, 26, 1,  // Inst{26} ...
/* 414 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 428
/* 418 */     MCD::OPC_CheckField, 10, 6, 60, 62, 2, // Skip to: 998
/* 424 */     MCD::OPC_Decode, 226, 1, 27, // Opcode: STWDP_lru6
/* 428 */     MCD::OPC_FilterValue, 1, 54, 2, // Skip to: 998
/* 432 */     MCD::OPC_CheckField, 10, 6, 60, 48, 2, // Skip to: 998
/* 438 */     MCD::OPC_Decode, 229, 1, 27, // Opcode: STWSP_lru6
/* 442 */     MCD::OPC_FilterValue, 11, 31, 0, // Skip to: 477
/* 446 */     MCD::OPC_ExtractField, 26, 1,  // Inst{26} ...
/* 449 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 463
/* 453 */     MCD::OPC_CheckField, 10, 6, 60, 27, 2, // Skip to: 998
/* 459 */     MCD::OPC_Decode, 159, 1, 27, // Opcode: LDWDP_lru6
/* 463 */     MCD::OPC_FilterValue, 1, 19, 2, // Skip to: 998
/* 467 */     MCD::OPC_CheckField, 10, 6, 60, 13, 2, // Skip to: 998
/* 473 */     MCD::OPC_Decode, 162, 1, 27, // Opcode: LDWSP_lru6
/* 477 */     MCD::OPC_FilterValue, 12, 31, 0, // Skip to: 512
/* 481 */     MCD::OPC_ExtractField, 26, 1,  // Inst{26} ...
/* 484 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 498
/* 488 */     MCD::OPC_CheckField, 10, 6, 60, 248, 1, // Skip to: 998
/* 494 */     MCD::OPC_Decode, 141, 1, 27, // Opcode: LDAWDP_lru6
/* 498 */     MCD::OPC_FilterValue, 1, 240, 1, // Skip to: 998
/* 502 */     MCD::OPC_CheckField, 10, 6, 60, 234, 1, // Skip to: 998
/* 508 */     MCD::OPC_Decode, 146, 1, 27, // Opcode: LDAWSP_lru6
/* 512 */     MCD::OPC_FilterValue, 13, 31, 0, // Skip to: 547
/* 516 */     MCD::OPC_ExtractField, 26, 1,  // Inst{26} ...
/* 519 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 533
/* 523 */     MCD::OPC_CheckField, 10, 6, 60, 213, 1, // Skip to: 998
/* 529 */     MCD::OPC_Decode, 148, 1, 27, // Opcode: LDC_lru6
/* 533 */     MCD::OPC_FilterValue, 1, 205, 1, // Skip to: 998
/* 537 */     MCD::OPC_CheckField, 10, 6, 60, 199, 1, // Skip to: 998
/* 543 */     MCD::OPC_Decode, 155, 1, 27, // Opcode: LDWCP_lru6
/* 547 */     MCD::OPC_FilterValue, 14, 94, 0, // Skip to: 645
/* 551 */     MCD::OPC_ExtractField, 26, 1,  // Inst{26} ...
/* 554 */     MCD::OPC_FilterValue, 0, 41, 0, // Skip to: 599
/* 558 */     MCD::OPC_ExtractField, 10, 6,  // Inst{15-10} ...
/* 561 */     MCD::OPC_FilterValue, 60, 177, 1, // Skip to: 998
/* 565 */     MCD::OPC_ExtractField, 22, 4,  // Inst{25-22} ...
/* 568 */     MCD::OPC_FilterValue, 12, 3, 0, // Skip to: 575
/* 572 */     MCD::OPC_Decode, 52, 28, // Opcode: BRFU_lu6
/* 575 */     MCD::OPC_FilterValue, 13, 3, 0, // Skip to: 582
/* 579 */     MCD::OPC_Decode, 35, 28, // Opcode: BLAT_lu6
/* 582 */     MCD::OPC_FilterValue, 14, 3, 0, // Skip to: 589
/* 586 */     MCD::OPC_Decode, 88, 28, // Opcode: EXTDP_lu6
/* 589 */     MCD::OPC_FilterValue, 15, 3, 0, // Skip to: 596
/* 593 */     MCD::OPC_Decode, 120, 28, // Opcode: KCALL_lu6
/* 596 */     MCD::OPC_Decode, 50, 29, // Opcode: BRFT_lru6
/* 599 */     MCD::OPC_FilterValue, 1, 139, 1, // Skip to: 998
/* 603 */     MCD::OPC_ExtractField, 10, 6,  // Inst{15-10} ...
/* 606 */     MCD::OPC_FilterValue, 60, 132, 1, // Skip to: 998
/* 610 */     MCD::OPC_ExtractField, 22, 4,  // Inst{25-22} ...
/* 613 */     MCD::OPC_FilterValue, 12, 3, 0, // Skip to: 620
/* 617 */     MCD::OPC_Decode, 46, 30, // Opcode: BRBU_lu6
/* 620 */     MCD::OPC_FilterValue, 13, 3, 0, // Skip to: 627
/* 624 */     MCD::OPC_Decode, 84, 28, // Opcode: ENTSP_lu6
/* 627 */     MCD::OPC_FilterValue, 14, 3, 0, // Skip to: 634
/* 631 */     MCD::OPC_Decode, 90, 28, // Opcode: EXTSP_lu6
/* 634 */     MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 642
/* 638 */     MCD::OPC_Decode, 189, 1, 28, // Opcode: RETSP_lu6
/* 642 */     MCD::OPC_Decode, 44, 31, // Opcode: BRBT_lru6
/* 645 */     MCD::OPC_FilterValue, 15, 81, 0, // Skip to: 730
/* 649 */     MCD::OPC_ExtractField, 26, 1,  // Inst{26} ...
/* 652 */     MCD::OPC_FilterValue, 0, 42, 0, // Skip to: 698
/* 656 */     MCD::OPC_ExtractField, 10, 6,  // Inst{15-10} ...
/* 659 */     MCD::OPC_FilterValue, 60, 79, 1, // Skip to: 998
/* 663 */     MCD::OPC_ExtractField, 22, 4,  // Inst{25-22} ...
/* 666 */     MCD::OPC_FilterValue, 12, 3, 0, // Skip to: 673
/* 670 */     MCD::OPC_Decode, 64, 28, // Opcode: CLRSR_lu6
/* 673 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 681
/* 677 */     MCD::OPC_Decode, 209, 1, 28, // Opcode: SETSR_lu6
/* 681 */     MCD::OPC_FilterValue, 14, 3, 0, // Skip to: 688
/* 685 */     MCD::OPC_Decode, 122, 28, // Opcode: KENTSP_lu6
/* 688 */     MCD::OPC_FilterValue, 15, 3, 0, // Skip to: 695
/* 692 */     MCD::OPC_Decode, 124, 28, // Opcode: KRESTSP_lu6
/* 695 */     MCD::OPC_Decode, 48, 29, // Opcode: BRFF_lru6
/* 698 */     MCD::OPC_FilterValue, 1, 40, 1, // Skip to: 998
/* 702 */     MCD::OPC_ExtractField, 10, 6,  // Inst{15-10} ...
/* 705 */     MCD::OPC_FilterValue, 60, 33, 1, // Skip to: 998
/* 709 */     MCD::OPC_ExtractField, 22, 4,  // Inst{25-22} ...
/* 712 */     MCD::OPC_FilterValue, 12, 3, 0, // Skip to: 719
/* 716 */     MCD::OPC_Decode, 104, 28, // Opcode: GETSR_lu6
/* 719 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 727
/* 723 */     MCD::OPC_Decode, 139, 1, 28, // Opcode: LDAWCP_lu6
/* 727 */     MCD::OPC_Decode, 42, 31, // Opcode: BRBF_lru6
/* 730 */     MCD::OPC_FilterValue, 16, 12, 0, // Skip to: 746
/* 734 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 0, 1, // Skip to: 998
/* 742 */     MCD::OPC_Decode, 220, 1, 21, // Opcode: ST16_l3r
/* 746 */     MCD::OPC_FilterValue, 17, 12, 0, // Skip to: 762
/* 750 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 240, 0, // Skip to: 998
/* 758 */     MCD::OPC_Decode, 221, 1, 21, // Opcode: ST8_l3r
/* 762 */     MCD::OPC_FilterValue, 18, 31, 0, // Skip to: 797
/* 766 */     MCD::OPC_ExtractField, 11, 16,  // Inst{26-11} ...
/* 769 */     MCD::OPC_FilterValue, 159, 251, 3, 3, 0, // Skip to: 778
/* 775 */     MCD::OPC_Decode, 29, 32, // Opcode: ASHR_l2rus
/* 778 */     MCD::OPC_FilterValue, 191, 251, 3, 4, 0, // Skip to: 788
/* 784 */     MCD::OPC_Decode, 182, 1, 32, // Opcode: OUTPW_l2rus
/* 788 */     MCD::OPC_FilterValue, 223, 251, 3, 204, 0, // Skip to: 998
/* 794 */     MCD::OPC_Decode, 114, 32, // Opcode: INPW_l2rus
/* 797 */     MCD::OPC_FilterValue, 19, 12, 0, // Skip to: 813
/* 801 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 189, 0, // Skip to: 998
/* 809 */     MCD::OPC_Decode, 144, 1, 33, // Opcode: LDAWF_l2rus
/* 813 */     MCD::OPC_FilterValue, 20, 12, 0, // Skip to: 829
/* 817 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 173, 0, // Skip to: 998
/* 825 */     MCD::OPC_Decode, 137, 1, 33, // Opcode: LDAWB_l2rus
/* 829 */     MCD::OPC_FilterValue, 21, 11, 0, // Skip to: 844
/* 833 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 157, 0, // Skip to: 998
/* 841 */     MCD::OPC_Decode, 68, 34, // Opcode: CRC_l3r
/* 844 */     MCD::OPC_FilterValue, 24, 12, 0, // Skip to: 860
/* 848 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 142, 0, // Skip to: 998
/* 856 */     MCD::OPC_Decode, 187, 1, 21, // Opcode: REMS_l3r
/* 860 */     MCD::OPC_FilterValue, 25, 12, 0, // Skip to: 876
/* 864 */     MCD::OPC_CheckField, 11, 16, 159, 251, 3, 126, 0, // Skip to: 998
/* 872 */     MCD::OPC_Decode, 188, 1, 21, // Opcode: REMU_l3r
/* 876 */     MCD::OPC_FilterValue, 26, 29, 0, // Skip to: 909
/* 880 */     MCD::OPC_ExtractField, 26, 1,  // Inst{26} ...
/* 883 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 896
/* 887 */     MCD::OPC_CheckField, 10, 6, 60, 105, 0, // Skip to: 998
/* 893 */     MCD::OPC_Decode, 40, 35, // Opcode: BLRF_lu10
/* 896 */     MCD::OPC_FilterValue, 1, 98, 0, // Skip to: 998
/* 900 */     MCD::OPC_CheckField, 10, 6, 60, 92, 0, // Skip to: 998
/* 906 */     MCD::OPC_Decode, 38, 36, // Opcode: BLRB_lu10
/* 909 */     MCD::OPC_FilterValue, 27, 31, 0, // Skip to: 944
/* 913 */     MCD::OPC_ExtractField, 26, 1,  // Inst{26} ...
/* 916 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 930
/* 920 */     MCD::OPC_CheckField, 10, 6, 60, 72, 0, // Skip to: 998
/* 926 */     MCD::OPC_Decode, 134, 1, 35, // Opcode: LDAPF_lu10
/* 930 */     MCD::OPC_FilterValue, 1, 64, 0, // Skip to: 998
/* 934 */     MCD::OPC_CheckField, 10, 6, 60, 58, 0, // Skip to: 998
/* 940 */     MCD::OPC_Decode, 132, 1, 36, // Opcode: LDAPB_lu10
/* 944 */     MCD::OPC_FilterValue, 28, 30, 0, // Skip to: 978
/* 948 */     MCD::OPC_ExtractField, 26, 1,  // Inst{26} ...
/* 951 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 964
/* 955 */     MCD::OPC_CheckField, 10, 6, 60, 37, 0, // Skip to: 998
/* 961 */     MCD::OPC_Decode, 33, 35, // Opcode: BLACP_lu10
/* 964 */     MCD::OPC_FilterValue, 1, 30, 0, // Skip to: 998
/* 968 */     MCD::OPC_CheckField, 10, 6, 60, 24, 0, // Skip to: 998
/* 974 */     MCD::OPC_Decode, 156, 1, 35, // Opcode: LDWCP_lu10
/* 978 */     MCD::OPC_FilterValue, 29, 16, 0, // Skip to: 998
/* 982 */     MCD::OPC_CheckField, 26, 1, 0, 10, 0, // Skip to: 998
/* 988 */     MCD::OPC_CheckField, 10, 6, 60, 4, 0, // Skip to: 998
/* 994 */     MCD::OPC_Decode, 195, 1, 29, // Opcode: SETC_lru6
/* 998 */     MCD::OPC_Fail,
  0
};

static bool checkDecoderPredicate(unsigned Idx, const FeatureBitset& Bits) {
  llvm_unreachable("Invalid index!");
}

template<typename InsnType>
static DecodeStatus decodeToMCInst(DecodeStatus S, unsigned Idx, InsnType insn, MCInst &MI,
                                   uint64_t Address, const void *Decoder, bool &DecodeComplete) {
  DecodeComplete = true;
  InsnType tmp;
  switch (Idx) {
  default: llvm_unreachable("Invalid index!");
  case 0:
    return S;
  case 1:
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 2:
    if (Decode2RInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 3:
    if (Decode2RUSInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 4:
    if (DecodeR2RInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 5:
    if (Decode3RInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 6:
    if (Decode2RImmInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 7:
    if (Decode2RSrcDstInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 8:
    if (DecodeRUSSrcDstBitpInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 9:
    if (DecodeRUSInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 10:
    tmp = fieldFromInstruction(insn, 6, 4);
    if (DecodeRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 11:
    tmp = fieldFromInstruction(insn, 0, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 12:
    tmp = fieldFromInstruction(insn, 6, 4);
    if (DecodeGRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 13:
    tmp = fieldFromInstruction(insn, 0, 6);
    if (DecodeNegImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 14:
    tmp = fieldFromInstruction(insn, 6, 4);
    if (DecodeGRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 6);
    if (DecodeNegImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 15:
    if (DecodeRUSBitpInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 16:
    if (Decode2RUSBitpInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 17:
    if (Decode3RImmInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 18:
    tmp = fieldFromInstruction(insn, 0, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 19:
    tmp = fieldFromInstruction(insn, 0, 10);
    if (DecodeNegImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 20:
    if (DecodeL2RInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 21:
    if (DecodeL3RInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 22:
    if (DecodeL4RSrcDstInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 23:
    if (DecodeL4RSrcDstSrcDstInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 24:
    if (DecodeL5RInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 25:
    if (DecodeL6RInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 26:
    if (DecodeLR2RInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 27:
    tmp = fieldFromInstruction(insn, 22, 4);
    if (DecodeRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 10) << 6;
    tmp |= fieldFromInstruction(insn, 16, 6) << 0;
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 28:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 10) << 6;
    tmp |= fieldFromInstruction(insn, 16, 6) << 0;
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 29:
    tmp = fieldFromInstruction(insn, 22, 4);
    if (DecodeGRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 10) << 6;
    tmp |= fieldFromInstruction(insn, 16, 6) << 0;
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 30:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 10) << 6;
    tmp |= fieldFromInstruction(insn, 16, 6) << 0;
    if (DecodeNegImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 31:
    tmp = fieldFromInstruction(insn, 22, 4);
    if (DecodeGRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 10) << 6;
    tmp |= fieldFromInstruction(insn, 16, 6) << 0;
    if (DecodeNegImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 32:
    if (DecodeL2RUSBitpInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 33:
    if (DecodeL2RUSInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 34:
    if (DecodeL3RSrcDstInstruction(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 35:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 10) << 10;
    tmp |= fieldFromInstruction(insn, 16, 10) << 0;
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 36:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 10) << 10;
    tmp |= fieldFromInstruction(insn, 16, 10) << 0;
    if (DecodeNegImmOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  }
}

template<typename InsnType>
static DecodeStatus decodeInstruction(const uint8_t DecodeTable[], MCInst &MI,
                                      InsnType insn, uint64_t Address,
                                      const void *DisAsm,
                                      const MCSubtargetInfo &STI) {
  const FeatureBitset& Bits = STI.getFeatureBits();

  const uint8_t *Ptr = DecodeTable;
  uint32_t CurFieldValue = 0;
  DecodeStatus S = MCDisassembler::Success;
  for (;;) {
    ptrdiff_t Loc = Ptr - DecodeTable;
    switch (*Ptr) {
    default:
      errs() << Loc << ": Unexpected decode table opcode!\n";
      return MCDisassembler::Fail;
    case MCD::OPC_ExtractField: {
      unsigned Start = *++Ptr;
      unsigned Len = *++Ptr;
      ++Ptr;
      CurFieldValue = fieldFromInstruction(insn, Start, Len);
      DEBUG(dbgs() << Loc << ": OPC_ExtractField(" << Start << ", "
                   << Len << "): " << CurFieldValue << "\n");
      break;
    }
    case MCD::OPC_FilterValue: {
      // Decode the field value.
      unsigned Len;
      InsnType Val = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;

      // Perform the filter operation.
      if (Val != CurFieldValue)
        Ptr += NumToSkip;
      DEBUG(dbgs() << Loc << ": OPC_FilterValue(" << Val << ", " << NumToSkip
                   << "): " << ((Val != CurFieldValue) ? "FAIL:" : "PASS:")
                   << " continuing at " << (Ptr - DecodeTable) << "\n");

      break;
    }
    case MCD::OPC_CheckField: {
      unsigned Start = *++Ptr;
      unsigned Len = *++Ptr;
      InsnType FieldValue = fieldFromInstruction(insn, Start, Len);
      // Decode the field value.
      uint32_t ExpectedValue = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;

      // If the actual and expected values don't match, skip.
      if (ExpectedValue != FieldValue)
        Ptr += NumToSkip;
      DEBUG(dbgs() << Loc << ": OPC_CheckField(" << Start << ", "
                   << Len << ", " << ExpectedValue << ", " << NumToSkip
                   << "): FieldValue = " << FieldValue << ", ExpectedValue = "
                   << ExpectedValue << ": "
                   << ((ExpectedValue == FieldValue) ? "PASS\n" : "FAIL\n"));
      break;
    }
    case MCD::OPC_CheckPredicate: {
      unsigned Len;
      // Decode the Predicate Index value.
      unsigned PIdx = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;
      // Check the predicate.
      bool Pred;
      if (!(Pred = checkDecoderPredicate(PIdx, Bits)))
        Ptr += NumToSkip;
      (void)Pred;
      DEBUG(dbgs() << Loc << ": OPC_CheckPredicate(" << PIdx << "): "
            << (Pred ? "PASS\n" : "FAIL\n"));

      break;
    }
    case MCD::OPC_Decode: {
      unsigned Len;
      // Decode the Opcode value.
      unsigned Opc = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      unsigned DecodeIdx = decodeULEB128(Ptr, &Len);
      Ptr += Len;

      MI.clear();
      MI.setOpcode(Opc);
      bool DecodeComplete;
      S = decodeToMCInst(S, DecodeIdx, insn, MI, Address, DisAsm, DecodeComplete);
      assert(DecodeComplete);

      DEBUG(dbgs() << Loc << ": OPC_Decode: opcode " << Opc
                   << ", using decoder " << DecodeIdx << ": "
                   << (S != MCDisassembler::Fail ? "PASS" : "FAIL") << "\n");
      return S;
    }
    case MCD::OPC_TryDecode: {
      unsigned Len;
      // Decode the Opcode value.
      unsigned Opc = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      unsigned DecodeIdx = decodeULEB128(Ptr, &Len);
      Ptr += Len;
      // NumToSkip is a plain 16-bit integer.
      unsigned NumToSkip = *Ptr++;
      NumToSkip |= (*Ptr++) << 8;

      // Perform the decode operation.
      MCInst TmpMI;
      TmpMI.setOpcode(Opc);
      bool DecodeComplete;
      S = decodeToMCInst(S, DecodeIdx, insn, TmpMI, Address, DisAsm, DecodeComplete);
      DEBUG(dbgs() << Loc << ": OPC_TryDecode: opcode " << Opc
                   << ", using decoder " << DecodeIdx << ": ");

      if (DecodeComplete) {
        // Decoding complete.
        DEBUG(dbgs() << (S != MCDisassembler::Fail ? "PASS" : "FAIL") << "\n");
        MI = TmpMI;
        return S;
      } else {
        assert(S == MCDisassembler::Fail);
        // If the decoding was incomplete, skip.
        Ptr += NumToSkip;
        DEBUG(dbgs() << "FAIL: continuing at " << (Ptr - DecodeTable) << "\n");
        // Reset decode status. This also drops a SoftFail status that could be
        // set before the decode attempt.
        S = MCDisassembler::Success;
      }
      break;
    }
    case MCD::OPC_SoftFail: {
      // Decode the mask values.
      unsigned Len;
      InsnType PositiveMask = decodeULEB128(++Ptr, &Len);
      Ptr += Len;
      InsnType NegativeMask = decodeULEB128(Ptr, &Len);
      Ptr += Len;
      bool Fail = (insn & PositiveMask) || (~insn & NegativeMask);
      if (Fail)
        S = MCDisassembler::SoftFail;
      DEBUG(dbgs() << Loc << ": OPC_SoftFail: " << (Fail ? "FAIL\n":"PASS\n"));
      break;
    }
    case MCD::OPC_Fail: {
      DEBUG(dbgs() << Loc << ": OPC_Fail\n");
      return MCDisassembler::Fail;
    }
    }
  }
  llvm_unreachable("bogosity detected in disassembler state machine!");
}


} // End llvm namespace
