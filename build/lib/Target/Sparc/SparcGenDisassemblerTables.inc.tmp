/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*  * Sparc Disassembler                                                      *|
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

static const uint8_t DecoderTableSparc32[] = {
/* 0 */       MCD::OPC_ExtractField, 30, 2,  // Inst{31-30} ...
/* 3 */       MCD::OPC_FilterValue, 0, 13, 2, // Skip to: 532
/* 7 */       MCD::OPC_ExtractField, 22, 3,  // Inst{24-22} ...
/* 10 */      MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 24
/* 14 */      MCD::OPC_CheckField, 25, 5, 0, 172, 25, // Skip to: 6592
/* 20 */      MCD::OPC_Decode, 254, 3, 0, // Opcode: UNIMP
/* 24 */      MCD::OPC_FilterValue, 1, 103, 0, // Skip to: 131
/* 28 */      MCD::OPC_ExtractField, 19, 3,  // Inst{21-19} ...
/* 31 */      MCD::OPC_FilterValue, 0, 25, 0, // Skip to: 60
/* 35 */      MCD::OPC_ExtractField, 29, 1,  // Inst{29} ...
/* 38 */      MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 49
/* 42 */      MCD::OPC_CheckPredicate, 0, 146, 25, // Skip to: 6592
/* 46 */      MCD::OPC_Decode, 95, 1, // Opcode: BPICCNT
/* 49 */      MCD::OPC_FilterValue, 1, 139, 25, // Skip to: 6592
/* 53 */      MCD::OPC_CheckPredicate, 0, 135, 25, // Skip to: 6592
/* 57 */      MCD::OPC_Decode, 94, 1, // Opcode: BPICCANT
/* 60 */      MCD::OPC_FilterValue, 1, 25, 0, // Skip to: 89
/* 64 */      MCD::OPC_ExtractField, 29, 1,  // Inst{29} ...
/* 67 */      MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 78
/* 71 */      MCD::OPC_CheckPredicate, 0, 117, 25, // Skip to: 6592
/* 75 */      MCD::OPC_Decode, 92, 1, // Opcode: BPICC
/* 78 */      MCD::OPC_FilterValue, 1, 110, 25, // Skip to: 6592
/* 82 */      MCD::OPC_CheckPredicate, 0, 106, 25, // Skip to: 6592
/* 86 */      MCD::OPC_Decode, 93, 1, // Opcode: BPICCA
/* 89 */      MCD::OPC_FilterValue, 4, 17, 0, // Skip to: 110
/* 93 */      MCD::OPC_ExtractField, 29, 1,  // Inst{29} ...
/* 96 */      MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 103
/* 100 */     MCD::OPC_Decode, 111, 1, // Opcode: BPXCCNT
/* 103 */     MCD::OPC_FilterValue, 1, 85, 25, // Skip to: 6592
/* 107 */     MCD::OPC_Decode, 110, 1, // Opcode: BPXCCANT
/* 110 */     MCD::OPC_FilterValue, 5, 78, 25, // Skip to: 6592
/* 114 */     MCD::OPC_ExtractField, 29, 1,  // Inst{29} ...
/* 117 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 124
/* 121 */     MCD::OPC_Decode, 108, 1, // Opcode: BPXCC
/* 124 */     MCD::OPC_FilterValue, 1, 64, 25, // Skip to: 6592
/* 128 */     MCD::OPC_Decode, 109, 1, // Opcode: BPXCCA
/* 131 */     MCD::OPC_FilterValue, 2, 26, 0, // Skip to: 161
/* 135 */     MCD::OPC_ExtractField, 29, 1,  // Inst{29} ...
/* 138 */     MCD::OPC_FilterValue, 0, 12, 0, // Skip to: 154
/* 142 */     MCD::OPC_CheckField, 25, 4, 8, 3, 0, // Skip to: 151
/* 148 */     MCD::OPC_Decode, 74, 0, // Opcode: BA
/* 151 */     MCD::OPC_Decode, 75, 2, // Opcode: BCOND
/* 154 */     MCD::OPC_FilterValue, 1, 34, 25, // Skip to: 6592
/* 158 */     MCD::OPC_Decode, 76, 2, // Opcode: BCONDA
/* 161 */     MCD::OPC_FilterValue, 3, 255, 0, // Skip to: 420
/* 165 */     MCD::OPC_ExtractField, 25, 5,  // Inst{29-25} ...
/* 168 */     MCD::OPC_FilterValue, 1, 17, 0, // Skip to: 189
/* 172 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 175 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 182
/* 179 */     MCD::OPC_Decode, 114, 3, // Opcode: BPZnapn
/* 182 */     MCD::OPC_FilterValue, 1, 6, 25, // Skip to: 6592
/* 186 */     MCD::OPC_Decode, 115, 3, // Opcode: BPZnapt
/* 189 */     MCD::OPC_FilterValue, 2, 17, 0, // Skip to: 210
/* 193 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 196 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 203
/* 200 */     MCD::OPC_Decode, 98, 3, // Opcode: BPLEZnapn
/* 203 */     MCD::OPC_FilterValue, 1, 241, 24, // Skip to: 6592
/* 207 */     MCD::OPC_Decode, 99, 3, // Opcode: BPLEZnapt
/* 210 */     MCD::OPC_FilterValue, 3, 17, 0, // Skip to: 231
/* 214 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 217 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 224
/* 221 */     MCD::OPC_Decode, 102, 3, // Opcode: BPLZnapn
/* 224 */     MCD::OPC_FilterValue, 1, 220, 24, // Skip to: 6592
/* 228 */     MCD::OPC_Decode, 103, 3, // Opcode: BPLZnapt
/* 231 */     MCD::OPC_FilterValue, 5, 17, 0, // Skip to: 252
/* 235 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 238 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 245
/* 242 */     MCD::OPC_Decode, 106, 3, // Opcode: BPNZnapn
/* 245 */     MCD::OPC_FilterValue, 1, 199, 24, // Skip to: 6592
/* 249 */     MCD::OPC_Decode, 107, 3, // Opcode: BPNZnapt
/* 252 */     MCD::OPC_FilterValue, 6, 17, 0, // Skip to: 273
/* 256 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 259 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 266
/* 263 */     MCD::OPC_Decode, 90, 3, // Opcode: BPGZnapn
/* 266 */     MCD::OPC_FilterValue, 1, 178, 24, // Skip to: 6592
/* 270 */     MCD::OPC_Decode, 91, 3, // Opcode: BPGZnapt
/* 273 */     MCD::OPC_FilterValue, 7, 17, 0, // Skip to: 294
/* 277 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 280 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 287
/* 284 */     MCD::OPC_Decode, 86, 3, // Opcode: BPGEZnapn
/* 287 */     MCD::OPC_FilterValue, 1, 157, 24, // Skip to: 6592
/* 291 */     MCD::OPC_Decode, 87, 3, // Opcode: BPGEZnapt
/* 294 */     MCD::OPC_FilterValue, 17, 17, 0, // Skip to: 315
/* 298 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 301 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 308
/* 305 */     MCD::OPC_Decode, 112, 3, // Opcode: BPZapn
/* 308 */     MCD::OPC_FilterValue, 1, 136, 24, // Skip to: 6592
/* 312 */     MCD::OPC_Decode, 113, 3, // Opcode: BPZapt
/* 315 */     MCD::OPC_FilterValue, 18, 17, 0, // Skip to: 336
/* 319 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 322 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 329
/* 326 */     MCD::OPC_Decode, 96, 3, // Opcode: BPLEZapn
/* 329 */     MCD::OPC_FilterValue, 1, 115, 24, // Skip to: 6592
/* 333 */     MCD::OPC_Decode, 97, 3, // Opcode: BPLEZapt
/* 336 */     MCD::OPC_FilterValue, 19, 17, 0, // Skip to: 357
/* 340 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 343 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 350
/* 347 */     MCD::OPC_Decode, 100, 3, // Opcode: BPLZapn
/* 350 */     MCD::OPC_FilterValue, 1, 94, 24, // Skip to: 6592
/* 354 */     MCD::OPC_Decode, 101, 3, // Opcode: BPLZapt
/* 357 */     MCD::OPC_FilterValue, 21, 17, 0, // Skip to: 378
/* 361 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 364 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 371
/* 368 */     MCD::OPC_Decode, 104, 3, // Opcode: BPNZapn
/* 371 */     MCD::OPC_FilterValue, 1, 73, 24, // Skip to: 6592
/* 375 */     MCD::OPC_Decode, 105, 3, // Opcode: BPNZapt
/* 378 */     MCD::OPC_FilterValue, 22, 17, 0, // Skip to: 399
/* 382 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 385 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 392
/* 389 */     MCD::OPC_Decode, 88, 3, // Opcode: BPGZapn
/* 392 */     MCD::OPC_FilterValue, 1, 52, 24, // Skip to: 6592
/* 396 */     MCD::OPC_Decode, 89, 3, // Opcode: BPGZapt
/* 399 */     MCD::OPC_FilterValue, 23, 45, 24, // Skip to: 6592
/* 403 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 406 */     MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 413
/* 410 */     MCD::OPC_Decode, 84, 3, // Opcode: BPGEZapn
/* 413 */     MCD::OPC_FilterValue, 1, 31, 24, // Skip to: 6592
/* 417 */     MCD::OPC_Decode, 85, 3, // Opcode: BPGEZapt
/* 420 */     MCD::OPC_FilterValue, 4, 20, 0, // Skip to: 444
/* 424 */     MCD::OPC_CheckField, 25, 5, 0, 10, 0, // Skip to: 440
/* 430 */     MCD::OPC_CheckField, 0, 22, 0, 4, 0, // Skip to: 440
/* 436 */     MCD::OPC_Decode, 248, 2, 4, // Opcode: NOP
/* 440 */     MCD::OPC_Decode, 164, 3, 5, // Opcode: SETHIi
/* 444 */     MCD::OPC_FilterValue, 5, 61, 0, // Skip to: 509
/* 448 */     MCD::OPC_ExtractField, 19, 1,  // Inst{19} ...
/* 451 */     MCD::OPC_FilterValue, 0, 25, 0, // Skip to: 480
/* 455 */     MCD::OPC_ExtractField, 29, 1,  // Inst{29} ...
/* 458 */     MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 469
/* 462 */     MCD::OPC_CheckPredicate, 0, 238, 23, // Skip to: 6592
/* 466 */     MCD::OPC_Decode, 83, 6, // Opcode: BPFCCNT
/* 469 */     MCD::OPC_FilterValue, 1, 231, 23, // Skip to: 6592
/* 473 */     MCD::OPC_CheckPredicate, 0, 227, 23, // Skip to: 6592
/* 477 */     MCD::OPC_Decode, 82, 6, // Opcode: BPFCCANT
/* 480 */     MCD::OPC_FilterValue, 1, 220, 23, // Skip to: 6592
/* 484 */     MCD::OPC_ExtractField, 29, 1,  // Inst{29} ...
/* 487 */     MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 498
/* 491 */     MCD::OPC_CheckPredicate, 0, 209, 23, // Skip to: 6592
/* 495 */     MCD::OPC_Decode, 80, 6, // Opcode: BPFCC
/* 498 */     MCD::OPC_FilterValue, 1, 202, 23, // Skip to: 6592
/* 502 */     MCD::OPC_CheckPredicate, 0, 198, 23, // Skip to: 6592
/* 506 */     MCD::OPC_Decode, 81, 6, // Opcode: BPFCCA
/* 509 */     MCD::OPC_FilterValue, 6, 191, 23, // Skip to: 6592
/* 513 */     MCD::OPC_ExtractField, 29, 1,  // Inst{29} ...
/* 516 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 524
/* 520 */     MCD::OPC_Decode, 152, 1, 2, // Opcode: FBCOND
/* 524 */     MCD::OPC_FilterValue, 1, 176, 23, // Skip to: 6592
/* 528 */     MCD::OPC_Decode, 153, 1, 2, // Opcode: FBCONDA
/* 532 */     MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 539
/* 536 */     MCD::OPC_Decode, 117, 7, // Opcode: CALL
/* 539 */     MCD::OPC_FilterValue, 2, 99, 19, // Skip to: 5506
/* 543 */     MCD::OPC_ExtractField, 19, 6,  // Inst{24-19} ...
/* 546 */     MCD::OPC_FilterValue, 0, 23, 0, // Skip to: 573
/* 550 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 553 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 566
/* 557 */     MCD::OPC_CheckField, 5, 8, 0, 141, 23, // Skip to: 6592
/* 563 */     MCD::OPC_Decode, 34, 8, // Opcode: ADDrr
/* 566 */     MCD::OPC_FilterValue, 1, 134, 23, // Skip to: 6592
/* 570 */     MCD::OPC_Decode, 33, 9, // Opcode: ADDri
/* 573 */     MCD::OPC_FilterValue, 1, 23, 0, // Skip to: 600
/* 577 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 580 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 593
/* 584 */     MCD::OPC_CheckField, 5, 8, 0, 114, 23, // Skip to: 6592
/* 590 */     MCD::OPC_Decode, 49, 8, // Opcode: ANDrr
/* 593 */     MCD::OPC_FilterValue, 1, 107, 23, // Skip to: 6592
/* 597 */     MCD::OPC_Decode, 48, 9, // Opcode: ANDri
/* 600 */     MCD::OPC_FilterValue, 2, 25, 0, // Skip to: 629
/* 604 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 607 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 621
/* 611 */     MCD::OPC_CheckField, 5, 8, 0, 87, 23, // Skip to: 6592
/* 617 */     MCD::OPC_Decode, 131, 3, 8, // Opcode: ORrr
/* 621 */     MCD::OPC_FilterValue, 1, 79, 23, // Skip to: 6592
/* 625 */     MCD::OPC_Decode, 130, 3, 9, // Opcode: ORri
/* 629 */     MCD::OPC_FilterValue, 3, 25, 0, // Skip to: 658
/* 633 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 636 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 650
/* 640 */     MCD::OPC_CheckField, 5, 8, 0, 58, 23, // Skip to: 6592
/* 646 */     MCD::OPC_Decode, 160, 4, 8, // Opcode: XORrr
/* 650 */     MCD::OPC_FilterValue, 1, 50, 23, // Skip to: 6592
/* 654 */     MCD::OPC_Decode, 159, 4, 9, // Opcode: XORri
/* 658 */     MCD::OPC_FilterValue, 4, 25, 0, // Skip to: 687
/* 662 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 665 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 679
/* 669 */     MCD::OPC_CheckField, 5, 8, 0, 29, 23, // Skip to: 6592
/* 675 */     MCD::OPC_Decode, 220, 3, 8, // Opcode: SUBrr
/* 679 */     MCD::OPC_FilterValue, 1, 21, 23, // Skip to: 6592
/* 683 */     MCD::OPC_Decode, 219, 3, 9, // Opcode: SUBri
/* 687 */     MCD::OPC_FilterValue, 5, 23, 0, // Skip to: 714
/* 691 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 694 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 707
/* 698 */     MCD::OPC_CheckField, 5, 8, 0, 0, 23, // Skip to: 6592
/* 704 */     MCD::OPC_Decode, 44, 8, // Opcode: ANDNrr
/* 707 */     MCD::OPC_FilterValue, 1, 249, 22, // Skip to: 6592
/* 711 */     MCD::OPC_Decode, 43, 9, // Opcode: ANDNri
/* 714 */     MCD::OPC_FilterValue, 6, 25, 0, // Skip to: 743
/* 718 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 721 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 735
/* 725 */     MCD::OPC_CheckField, 5, 8, 0, 229, 22, // Skip to: 6592
/* 731 */     MCD::OPC_Decode, 254, 2, 8, // Opcode: ORNrr
/* 735 */     MCD::OPC_FilterValue, 1, 221, 22, // Skip to: 6592
/* 739 */     MCD::OPC_Decode, 253, 2, 9, // Opcode: ORNri
/* 743 */     MCD::OPC_FilterValue, 7, 25, 0, // Skip to: 772
/* 747 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 750 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 764
/* 754 */     MCD::OPC_CheckField, 5, 8, 0, 200, 22, // Skip to: 6592
/* 760 */     MCD::OPC_Decode, 154, 4, 8, // Opcode: XNORrr
/* 764 */     MCD::OPC_FilterValue, 1, 192, 22, // Skip to: 6592
/* 768 */     MCD::OPC_Decode, 153, 4, 9, // Opcode: XNORri
/* 772 */     MCD::OPC_FilterValue, 8, 23, 0, // Skip to: 799
/* 776 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 779 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 792
/* 783 */     MCD::OPC_CheckField, 5, 8, 0, 171, 22, // Skip to: 6592
/* 789 */     MCD::OPC_Decode, 26, 8, // Opcode: ADDCrr
/* 792 */     MCD::OPC_FilterValue, 1, 164, 22, // Skip to: 6592
/* 796 */     MCD::OPC_Decode, 25, 9, // Opcode: ADDCri
/* 799 */     MCD::OPC_FilterValue, 9, 25, 0, // Skip to: 828
/* 803 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 806 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 820
/* 810 */     MCD::OPC_CheckField, 5, 8, 0, 144, 22, // Skip to: 6592
/* 816 */     MCD::OPC_Decode, 247, 2, 10, // Opcode: MULXrr
/* 820 */     MCD::OPC_FilterValue, 1, 136, 22, // Skip to: 6592
/* 824 */     MCD::OPC_Decode, 246, 2, 11, // Opcode: MULXri
/* 828 */     MCD::OPC_FilterValue, 10, 25, 0, // Skip to: 857
/* 832 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 835 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 849
/* 839 */     MCD::OPC_CheckField, 5, 8, 0, 115, 22, // Skip to: 6592
/* 845 */     MCD::OPC_Decode, 253, 3, 8, // Opcode: UMULrr
/* 849 */     MCD::OPC_FilterValue, 1, 107, 22, // Skip to: 6592
/* 853 */     MCD::OPC_Decode, 252, 3, 9, // Opcode: UMULri
/* 857 */     MCD::OPC_FilterValue, 11, 25, 0, // Skip to: 886
/* 861 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 864 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 878
/* 868 */     MCD::OPC_CheckField, 5, 8, 0, 86, 22, // Skip to: 6592
/* 874 */     MCD::OPC_Decode, 174, 3, 8, // Opcode: SMULrr
/* 878 */     MCD::OPC_FilterValue, 1, 78, 22, // Skip to: 6592
/* 882 */     MCD::OPC_Decode, 173, 3, 9, // Opcode: SMULri
/* 886 */     MCD::OPC_FilterValue, 12, 25, 0, // Skip to: 915
/* 890 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 893 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 907
/* 897 */     MCD::OPC_CheckField, 5, 8, 0, 57, 22, // Skip to: 6592
/* 903 */     MCD::OPC_Decode, 214, 3, 8, // Opcode: SUBCrr
/* 907 */     MCD::OPC_FilterValue, 1, 49, 22, // Skip to: 6592
/* 911 */     MCD::OPC_Decode, 213, 3, 9, // Opcode: SUBCri
/* 915 */     MCD::OPC_FilterValue, 13, 25, 0, // Skip to: 944
/* 919 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 922 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 936
/* 926 */     MCD::OPC_CheckField, 5, 8, 0, 28, 22, // Skip to: 6592
/* 932 */     MCD::OPC_Decode, 246, 3, 10, // Opcode: UDIVXrr
/* 936 */     MCD::OPC_FilterValue, 1, 20, 22, // Skip to: 6592
/* 940 */     MCD::OPC_Decode, 245, 3, 11, // Opcode: UDIVXri
/* 944 */     MCD::OPC_FilterValue, 14, 25, 0, // Skip to: 973
/* 948 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 951 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 965
/* 955 */     MCD::OPC_CheckField, 5, 8, 0, 255, 21, // Skip to: 6592
/* 961 */     MCD::OPC_Decode, 248, 3, 8, // Opcode: UDIVrr
/* 965 */     MCD::OPC_FilterValue, 1, 247, 21, // Skip to: 6592
/* 969 */     MCD::OPC_Decode, 247, 3, 9, // Opcode: UDIVri
/* 973 */     MCD::OPC_FilterValue, 15, 25, 0, // Skip to: 1002
/* 977 */     MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 980 */     MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 994
/* 984 */     MCD::OPC_CheckField, 5, 8, 0, 226, 21, // Skip to: 6592
/* 990 */     MCD::OPC_Decode, 153, 3, 8, // Opcode: SDIVrr
/* 994 */     MCD::OPC_FilterValue, 1, 218, 21, // Skip to: 6592
/* 998 */     MCD::OPC_Decode, 152, 3, 9, // Opcode: SDIVri
/* 1002 */    MCD::OPC_FilterValue, 16, 23, 0, // Skip to: 1029
/* 1006 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1009 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 1022
/* 1013 */    MCD::OPC_CheckField, 5, 8, 0, 197, 21, // Skip to: 6592
/* 1019 */    MCD::OPC_Decode, 24, 8, // Opcode: ADDCCrr
/* 1022 */    MCD::OPC_FilterValue, 1, 190, 21, // Skip to: 6592
/* 1026 */    MCD::OPC_Decode, 23, 9, // Opcode: ADDCCri
/* 1029 */    MCD::OPC_FilterValue, 17, 23, 0, // Skip to: 1056
/* 1033 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1036 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 1049
/* 1040 */    MCD::OPC_CheckField, 5, 8, 0, 170, 21, // Skip to: 6592
/* 1046 */    MCD::OPC_Decode, 40, 8, // Opcode: ANDCCrr
/* 1049 */    MCD::OPC_FilterValue, 1, 163, 21, // Skip to: 6592
/* 1053 */    MCD::OPC_Decode, 39, 9, // Opcode: ANDCCri
/* 1056 */    MCD::OPC_FilterValue, 18, 25, 0, // Skip to: 1085
/* 1060 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1063 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1077
/* 1067 */    MCD::OPC_CheckField, 5, 8, 0, 143, 21, // Skip to: 6592
/* 1073 */    MCD::OPC_Decode, 250, 2, 8, // Opcode: ORCCrr
/* 1077 */    MCD::OPC_FilterValue, 1, 135, 21, // Skip to: 6592
/* 1081 */    MCD::OPC_Decode, 249, 2, 9, // Opcode: ORCCri
/* 1085 */    MCD::OPC_FilterValue, 19, 25, 0, // Skip to: 1114
/* 1089 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1092 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1106
/* 1096 */    MCD::OPC_CheckField, 5, 8, 0, 114, 21, // Skip to: 6592
/* 1102 */    MCD::OPC_Decode, 156, 4, 8, // Opcode: XORCCrr
/* 1106 */    MCD::OPC_FilterValue, 1, 106, 21, // Skip to: 6592
/* 1110 */    MCD::OPC_Decode, 155, 4, 9, // Opcode: XORCCri
/* 1114 */    MCD::OPC_FilterValue, 20, 44, 0, // Skip to: 1162
/* 1118 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1121 */    MCD::OPC_FilterValue, 0, 20, 0, // Skip to: 1145
/* 1125 */    MCD::OPC_ExtractField, 5, 8,  // Inst{12-5} ...
/* 1128 */    MCD::OPC_FilterValue, 0, 84, 21, // Skip to: 6592
/* 1132 */    MCD::OPC_CheckField, 25, 5, 0, 3, 0, // Skip to: 1141
/* 1138 */    MCD::OPC_Decode, 126, 12, // Opcode: CMPrr
/* 1141 */    MCD::OPC_Decode, 212, 3, 8, // Opcode: SUBCCrr
/* 1145 */    MCD::OPC_FilterValue, 1, 67, 21, // Skip to: 6592
/* 1149 */    MCD::OPC_CheckField, 25, 5, 0, 3, 0, // Skip to: 1158
/* 1155 */    MCD::OPC_Decode, 125, 13, // Opcode: CMPri
/* 1158 */    MCD::OPC_Decode, 211, 3, 9, // Opcode: SUBCCri
/* 1162 */    MCD::OPC_FilterValue, 21, 23, 0, // Skip to: 1189
/* 1166 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1169 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 1182
/* 1173 */    MCD::OPC_CheckField, 5, 8, 0, 37, 21, // Skip to: 6592
/* 1179 */    MCD::OPC_Decode, 42, 8, // Opcode: ANDNCCrr
/* 1182 */    MCD::OPC_FilterValue, 1, 30, 21, // Skip to: 6592
/* 1186 */    MCD::OPC_Decode, 41, 9, // Opcode: ANDNCCri
/* 1189 */    MCD::OPC_FilterValue, 22, 25, 0, // Skip to: 1218
/* 1193 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1196 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1210
/* 1200 */    MCD::OPC_CheckField, 5, 8, 0, 10, 21, // Skip to: 6592
/* 1206 */    MCD::OPC_Decode, 252, 2, 8, // Opcode: ORNCCrr
/* 1210 */    MCD::OPC_FilterValue, 1, 2, 21, // Skip to: 6592
/* 1214 */    MCD::OPC_Decode, 251, 2, 9, // Opcode: ORNCCri
/* 1218 */    MCD::OPC_FilterValue, 23, 25, 0, // Skip to: 1247
/* 1222 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1225 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1239
/* 1229 */    MCD::OPC_CheckField, 5, 8, 0, 237, 20, // Skip to: 6592
/* 1235 */    MCD::OPC_Decode, 151, 4, 8, // Opcode: XNORCCrr
/* 1239 */    MCD::OPC_FilterValue, 1, 229, 20, // Skip to: 6592
/* 1243 */    MCD::OPC_Decode, 150, 4, 9, // Opcode: XNORCCri
/* 1247 */    MCD::OPC_FilterValue, 24, 23, 0, // Skip to: 1274
/* 1251 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1254 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 1267
/* 1258 */    MCD::OPC_CheckField, 5, 8, 0, 208, 20, // Skip to: 6592
/* 1264 */    MCD::OPC_Decode, 28, 8, // Opcode: ADDErr
/* 1267 */    MCD::OPC_FilterValue, 1, 201, 20, // Skip to: 6592
/* 1271 */    MCD::OPC_Decode, 27, 9, // Opcode: ADDEri
/* 1274 */    MCD::OPC_FilterValue, 26, 25, 0, // Skip to: 1303
/* 1278 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1281 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1295
/* 1285 */    MCD::OPC_CheckField, 5, 8, 0, 181, 20, // Skip to: 6592
/* 1291 */    MCD::OPC_Decode, 250, 3, 8, // Opcode: UMULCCrr
/* 1295 */    MCD::OPC_FilterValue, 1, 173, 20, // Skip to: 6592
/* 1299 */    MCD::OPC_Decode, 249, 3, 9, // Opcode: UMULCCri
/* 1303 */    MCD::OPC_FilterValue, 27, 25, 0, // Skip to: 1332
/* 1307 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1310 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1324
/* 1314 */    MCD::OPC_CheckField, 5, 8, 0, 152, 20, // Skip to: 6592
/* 1320 */    MCD::OPC_Decode, 172, 3, 8, // Opcode: SMULCCrr
/* 1324 */    MCD::OPC_FilterValue, 1, 144, 20, // Skip to: 6592
/* 1328 */    MCD::OPC_Decode, 171, 3, 9, // Opcode: SMULCCri
/* 1332 */    MCD::OPC_FilterValue, 28, 25, 0, // Skip to: 1361
/* 1336 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1339 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1353
/* 1343 */    MCD::OPC_CheckField, 5, 8, 0, 123, 20, // Skip to: 6592
/* 1349 */    MCD::OPC_Decode, 216, 3, 8, // Opcode: SUBErr
/* 1353 */    MCD::OPC_FilterValue, 1, 115, 20, // Skip to: 6592
/* 1357 */    MCD::OPC_Decode, 215, 3, 9, // Opcode: SUBEri
/* 1361 */    MCD::OPC_FilterValue, 30, 25, 0, // Skip to: 1390
/* 1365 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1368 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1382
/* 1372 */    MCD::OPC_CheckField, 5, 8, 0, 94, 20, // Skip to: 6592
/* 1378 */    MCD::OPC_Decode, 244, 3, 8, // Opcode: UDIVCCrr
/* 1382 */    MCD::OPC_FilterValue, 1, 86, 20, // Skip to: 6592
/* 1386 */    MCD::OPC_Decode, 243, 3, 9, // Opcode: UDIVCCri
/* 1390 */    MCD::OPC_FilterValue, 31, 25, 0, // Skip to: 1419
/* 1394 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1397 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1411
/* 1401 */    MCD::OPC_CheckField, 5, 8, 0, 65, 20, // Skip to: 6592
/* 1407 */    MCD::OPC_Decode, 149, 3, 8, // Opcode: SDIVCCrr
/* 1411 */    MCD::OPC_FilterValue, 1, 57, 20, // Skip to: 6592
/* 1415 */    MCD::OPC_Decode, 148, 3, 9, // Opcode: SDIVCCri
/* 1419 */    MCD::OPC_FilterValue, 32, 25, 0, // Skip to: 1448
/* 1423 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1426 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1440
/* 1430 */    MCD::OPC_CheckField, 5, 8, 0, 36, 20, // Skip to: 6592
/* 1436 */    MCD::OPC_Decode, 229, 3, 8, // Opcode: TADDCCrr
/* 1440 */    MCD::OPC_FilterValue, 1, 28, 20, // Skip to: 6592
/* 1444 */    MCD::OPC_Decode, 228, 3, 9, // Opcode: TADDCCri
/* 1448 */    MCD::OPC_FilterValue, 33, 25, 0, // Skip to: 1477
/* 1452 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1455 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1469
/* 1459 */    MCD::OPC_CheckField, 5, 8, 0, 7, 20, // Skip to: 6592
/* 1465 */    MCD::OPC_Decode, 240, 3, 8, // Opcode: TSUBCCrr
/* 1469 */    MCD::OPC_FilterValue, 1, 255, 19, // Skip to: 6592
/* 1473 */    MCD::OPC_Decode, 239, 3, 9, // Opcode: TSUBCCri
/* 1477 */    MCD::OPC_FilterValue, 34, 25, 0, // Skip to: 1506
/* 1481 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1484 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1498
/* 1488 */    MCD::OPC_CheckField, 5, 8, 0, 234, 19, // Skip to: 6592
/* 1494 */    MCD::OPC_Decode, 227, 3, 8, // Opcode: TADDCCTVrr
/* 1498 */    MCD::OPC_FilterValue, 1, 226, 19, // Skip to: 6592
/* 1502 */    MCD::OPC_Decode, 226, 3, 9, // Opcode: TADDCCTVri
/* 1506 */    MCD::OPC_FilterValue, 35, 25, 0, // Skip to: 1535
/* 1510 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1513 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1527
/* 1517 */    MCD::OPC_CheckField, 5, 8, 0, 205, 19, // Skip to: 6592
/* 1523 */    MCD::OPC_Decode, 238, 3, 8, // Opcode: TSUBCCTVrr
/* 1527 */    MCD::OPC_FilterValue, 1, 197, 19, // Skip to: 6592
/* 1531 */    MCD::OPC_Decode, 237, 3, 9, // Opcode: TSUBCCTVri
/* 1535 */    MCD::OPC_FilterValue, 36, 25, 0, // Skip to: 1564
/* 1539 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1542 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1556
/* 1546 */    MCD::OPC_CheckField, 5, 8, 0, 176, 19, // Skip to: 6592
/* 1552 */    MCD::OPC_Decode, 245, 2, 8, // Opcode: MULSCCrr
/* 1556 */    MCD::OPC_FilterValue, 1, 168, 19, // Skip to: 6592
/* 1560 */    MCD::OPC_Decode, 244, 2, 9, // Opcode: MULSCCri
/* 1564 */    MCD::OPC_FilterValue, 37, 50, 0, // Skip to: 1618
/* 1568 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1571 */    MCD::OPC_FilterValue, 0, 25, 0, // Skip to: 1600
/* 1575 */    MCD::OPC_ExtractField, 12, 1,  // Inst{12} ...
/* 1578 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1592
/* 1582 */    MCD::OPC_CheckField, 5, 7, 0, 140, 19, // Skip to: 6592
/* 1588 */    MCD::OPC_Decode, 170, 3, 8, // Opcode: SLLrr
/* 1592 */    MCD::OPC_FilterValue, 1, 132, 19, // Skip to: 6592
/* 1596 */    MCD::OPC_Decode, 168, 3, 14, // Opcode: SLLXrr
/* 1600 */    MCD::OPC_FilterValue, 1, 124, 19, // Skip to: 6592
/* 1604 */    MCD::OPC_CheckField, 12, 1, 1, 4, 0, // Skip to: 1614
/* 1610 */    MCD::OPC_Decode, 167, 3, 15, // Opcode: SLLXri
/* 1614 */    MCD::OPC_Decode, 169, 3, 9, // Opcode: SLLri
/* 1618 */    MCD::OPC_FilterValue, 38, 50, 0, // Skip to: 1672
/* 1622 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1625 */    MCD::OPC_FilterValue, 0, 25, 0, // Skip to: 1654
/* 1629 */    MCD::OPC_ExtractField, 12, 1,  // Inst{12} ...
/* 1632 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1646
/* 1636 */    MCD::OPC_CheckField, 5, 7, 0, 86, 19, // Skip to: 6592
/* 1642 */    MCD::OPC_Decode, 182, 3, 8, // Opcode: SRLrr
/* 1646 */    MCD::OPC_FilterValue, 1, 78, 19, // Skip to: 6592
/* 1650 */    MCD::OPC_Decode, 180, 3, 14, // Opcode: SRLXrr
/* 1654 */    MCD::OPC_FilterValue, 1, 70, 19, // Skip to: 6592
/* 1658 */    MCD::OPC_CheckField, 12, 1, 1, 4, 0, // Skip to: 1668
/* 1664 */    MCD::OPC_Decode, 179, 3, 15, // Opcode: SRLXri
/* 1668 */    MCD::OPC_Decode, 181, 3, 9, // Opcode: SRLri
/* 1672 */    MCD::OPC_FilterValue, 39, 50, 0, // Skip to: 1726
/* 1676 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1679 */    MCD::OPC_FilterValue, 0, 25, 0, // Skip to: 1708
/* 1683 */    MCD::OPC_ExtractField, 12, 1,  // Inst{12} ...
/* 1686 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 1700
/* 1690 */    MCD::OPC_CheckField, 5, 7, 0, 32, 19, // Skip to: 6592
/* 1696 */    MCD::OPC_Decode, 178, 3, 8, // Opcode: SRArr
/* 1700 */    MCD::OPC_FilterValue, 1, 24, 19, // Skip to: 6592
/* 1704 */    MCD::OPC_Decode, 176, 3, 14, // Opcode: SRAXrr
/* 1708 */    MCD::OPC_FilterValue, 1, 16, 19, // Skip to: 6592
/* 1712 */    MCD::OPC_CheckField, 12, 1, 1, 4, 0, // Skip to: 1722
/* 1718 */    MCD::OPC_Decode, 175, 3, 15, // Opcode: SRAXri
/* 1722 */    MCD::OPC_Decode, 177, 3, 9, // Opcode: SRAri
/* 1726 */    MCD::OPC_FilterValue, 40, 58, 0, // Skip to: 1788
/* 1730 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1733 */    MCD::OPC_FilterValue, 0, 27, 0, // Skip to: 1764
/* 1737 */    MCD::OPC_ExtractField, 0, 13,  // Inst{12-0} ...
/* 1740 */    MCD::OPC_FilterValue, 0, 240, 18, // Skip to: 6592
/* 1744 */    MCD::OPC_CheckField, 25, 5, 0, 10, 0, // Skip to: 1760
/* 1750 */    MCD::OPC_CheckField, 14, 5, 15, 4, 0, // Skip to: 1760
/* 1756 */    MCD::OPC_Decode, 184, 3, 4, // Opcode: STBAR
/* 1760 */    MCD::OPC_Decode, 135, 3, 16, // Opcode: RDASR
/* 1764 */    MCD::OPC_FilterValue, 1, 216, 18, // Skip to: 6592
/* 1768 */    MCD::OPC_CheckPredicate, 0, 212, 18, // Skip to: 6592
/* 1772 */    MCD::OPC_CheckField, 25, 5, 0, 206, 18, // Skip to: 6592
/* 1778 */    MCD::OPC_CheckField, 14, 5, 15, 200, 18, // Skip to: 6592
/* 1784 */    MCD::OPC_Decode, 220, 2, 17, // Opcode: MEMBARi
/* 1788 */    MCD::OPC_FilterValue, 41, 10, 0, // Skip to: 1802
/* 1792 */    MCD::OPC_CheckField, 0, 19, 0, 186, 18, // Skip to: 6592
/* 1798 */    MCD::OPC_Decode, 137, 3, 18, // Opcode: RDPSR
/* 1802 */    MCD::OPC_FilterValue, 42, 25, 0, // Skip to: 1831
/* 1806 */    MCD::OPC_ExtractField, 0, 14,  // Inst{13-0} ...
/* 1809 */    MCD::OPC_FilterValue, 0, 171, 18, // Skip to: 6592
/* 1813 */    MCD::OPC_CheckField, 14, 5, 0, 4, 0, // Skip to: 1823
/* 1819 */    MCD::OPC_Decode, 139, 3, 18, // Opcode: RDWIM
/* 1823 */    MCD::OPC_CheckPredicate, 0, 157, 18, // Skip to: 6592
/* 1827 */    MCD::OPC_Decode, 136, 3, 19, // Opcode: RDPR
/* 1831 */    MCD::OPC_FilterValue, 43, 25, 0, // Skip to: 1860
/* 1835 */    MCD::OPC_ExtractField, 0, 19,  // Inst{18-0} ...
/* 1838 */    MCD::OPC_FilterValue, 0, 142, 18, // Skip to: 6592
/* 1842 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 1856
/* 1846 */    MCD::OPC_CheckField, 25, 5, 0, 4, 0, // Skip to: 1856
/* 1852 */    MCD::OPC_Decode, 185, 1, 4, // Opcode: FLUSHW
/* 1856 */    MCD::OPC_Decode, 138, 3, 18, // Opcode: RDTBR
/* 1860 */    MCD::OPC_FilterValue, 44, 123, 0, // Skip to: 1987
/* 1864 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1867 */    MCD::OPC_FilterValue, 0, 56, 0, // Skip to: 1927
/* 1871 */    MCD::OPC_ExtractField, 18, 1,  // Inst{18} ...
/* 1874 */    MCD::OPC_FilterValue, 0, 22, 0, // Skip to: 1900
/* 1878 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 1892
/* 1882 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 1892
/* 1888 */    MCD::OPC_Decode, 223, 2, 20, // Opcode: MOVFCCrr
/* 1892 */    MCD::OPC_CheckPredicate, 0, 88, 18, // Skip to: 6592
/* 1896 */    MCD::OPC_Decode, 137, 4, 21, // Opcode: V9MOVFCCrr
/* 1900 */    MCD::OPC_FilterValue, 1, 80, 18, // Skip to: 6592
/* 1904 */    MCD::OPC_ExtractField, 11, 2,  // Inst{12-11} ...
/* 1907 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1919
/* 1911 */    MCD::OPC_CheckPredicate, 0, 69, 18, // Skip to: 6592
/* 1915 */    MCD::OPC_Decode, 225, 2, 20, // Opcode: MOVICCrr
/* 1919 */    MCD::OPC_FilterValue, 2, 61, 18, // Skip to: 6592
/* 1923 */    MCD::OPC_Decode, 242, 2, 20, // Opcode: MOVXCCrr
/* 1927 */    MCD::OPC_FilterValue, 1, 53, 18, // Skip to: 6592
/* 1931 */    MCD::OPC_ExtractField, 18, 1,  // Inst{18} ...
/* 1934 */    MCD::OPC_FilterValue, 0, 22, 0, // Skip to: 1960
/* 1938 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 1952
/* 1942 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 1952
/* 1948 */    MCD::OPC_Decode, 222, 2, 22, // Opcode: MOVFCCri
/* 1952 */    MCD::OPC_CheckPredicate, 0, 28, 18, // Skip to: 6592
/* 1956 */    MCD::OPC_Decode, 136, 4, 23, // Opcode: V9MOVFCCri
/* 1960 */    MCD::OPC_FilterValue, 1, 20, 18, // Skip to: 6592
/* 1964 */    MCD::OPC_ExtractField, 11, 2,  // Inst{12-11} ...
/* 1967 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1979
/* 1971 */    MCD::OPC_CheckPredicate, 0, 9, 18, // Skip to: 6592
/* 1975 */    MCD::OPC_Decode, 224, 2, 22, // Opcode: MOVICCri
/* 1979 */    MCD::OPC_FilterValue, 2, 1, 18, // Skip to: 6592
/* 1983 */    MCD::OPC_Decode, 241, 2, 22, // Opcode: MOVXCCri
/* 1987 */    MCD::OPC_FilterValue, 45, 25, 0, // Skip to: 2016
/* 1991 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 1994 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 2008
/* 1998 */    MCD::OPC_CheckField, 5, 8, 0, 236, 17, // Skip to: 6592
/* 2004 */    MCD::OPC_Decode, 151, 3, 10, // Opcode: SDIVXrr
/* 2008 */    MCD::OPC_FilterValue, 1, 228, 17, // Skip to: 6592
/* 2012 */    MCD::OPC_Decode, 150, 3, 11, // Opcode: SDIVXri
/* 2016 */    MCD::OPC_FilterValue, 46, 14, 0, // Skip to: 2034
/* 2020 */    MCD::OPC_CheckPredicate, 0, 216, 17, // Skip to: 6592
/* 2024 */    MCD::OPC_CheckField, 5, 14, 0, 210, 17, // Skip to: 6592
/* 2030 */    MCD::OPC_Decode, 134, 3, 24, // Opcode: POPCrr
/* 2034 */    MCD::OPC_FilterValue, 47, 135, 0, // Skip to: 2173
/* 2038 */    MCD::OPC_ExtractField, 10, 4,  // Inst{13-10} ...
/* 2041 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 2055
/* 2045 */    MCD::OPC_CheckField, 5, 5, 0, 189, 17, // Skip to: 6592
/* 2051 */    MCD::OPC_Decode, 237, 2, 14, // Opcode: MOVRRZrr
/* 2055 */    MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 2069
/* 2059 */    MCD::OPC_CheckField, 5, 5, 0, 175, 17, // Skip to: 6592
/* 2065 */    MCD::OPC_Decode, 231, 2, 14, // Opcode: MOVRLEZrr
/* 2069 */    MCD::OPC_FilterValue, 3, 10, 0, // Skip to: 2083
/* 2073 */    MCD::OPC_CheckField, 5, 5, 0, 161, 17, // Skip to: 6592
/* 2079 */    MCD::OPC_Decode, 233, 2, 14, // Opcode: MOVRLZrr
/* 2083 */    MCD::OPC_FilterValue, 5, 10, 0, // Skip to: 2097
/* 2087 */    MCD::OPC_CheckField, 5, 5, 0, 147, 17, // Skip to: 6592
/* 2093 */    MCD::OPC_Decode, 235, 2, 14, // Opcode: MOVRNZrr
/* 2097 */    MCD::OPC_FilterValue, 6, 10, 0, // Skip to: 2111
/* 2101 */    MCD::OPC_CheckField, 5, 5, 0, 133, 17, // Skip to: 6592
/* 2107 */    MCD::OPC_Decode, 229, 2, 14, // Opcode: MOVRGZrr
/* 2111 */    MCD::OPC_FilterValue, 7, 10, 0, // Skip to: 2125
/* 2115 */    MCD::OPC_CheckField, 5, 5, 0, 119, 17, // Skip to: 6592
/* 2121 */    MCD::OPC_Decode, 227, 2, 14, // Opcode: MOVRGEZrr
/* 2125 */    MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 2133
/* 2129 */    MCD::OPC_Decode, 236, 2, 25, // Opcode: MOVRRZri
/* 2133 */    MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 2141
/* 2137 */    MCD::OPC_Decode, 230, 2, 25, // Opcode: MOVRLEZri
/* 2141 */    MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 2149
/* 2145 */    MCD::OPC_Decode, 232, 2, 25, // Opcode: MOVRLZri
/* 2149 */    MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 2157
/* 2153 */    MCD::OPC_Decode, 234, 2, 25, // Opcode: MOVRNZri
/* 2157 */    MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 2165
/* 2161 */    MCD::OPC_Decode, 228, 2, 25, // Opcode: MOVRGZri
/* 2165 */    MCD::OPC_FilterValue, 15, 71, 17, // Skip to: 6592
/* 2169 */    MCD::OPC_Decode, 226, 2, 25, // Opcode: MOVRGEZri
/* 2173 */    MCD::OPC_FilterValue, 48, 25, 0, // Skip to: 2202
/* 2177 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 2180 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 2194
/* 2184 */    MCD::OPC_CheckField, 5, 8, 0, 50, 17, // Skip to: 6592
/* 2190 */    MCD::OPC_Decode, 139, 4, 26, // Opcode: WRASRrr
/* 2194 */    MCD::OPC_FilterValue, 1, 42, 17, // Skip to: 6592
/* 2198 */    MCD::OPC_Decode, 138, 4, 27, // Opcode: WRASRri
/* 2202 */    MCD::OPC_FilterValue, 49, 37, 0, // Skip to: 2243
/* 2206 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 2209 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 2229
/* 2213 */    MCD::OPC_CheckField, 25, 5, 0, 21, 17, // Skip to: 6592
/* 2219 */    MCD::OPC_CheckField, 5, 8, 0, 15, 17, // Skip to: 6592
/* 2225 */    MCD::OPC_Decode, 143, 4, 12, // Opcode: WRPSRrr
/* 2229 */    MCD::OPC_FilterValue, 1, 7, 17, // Skip to: 6592
/* 2233 */    MCD::OPC_CheckField, 25, 5, 0, 1, 17, // Skip to: 6592
/* 2239 */    MCD::OPC_Decode, 142, 4, 13, // Opcode: WRPSRri
/* 2243 */    MCD::OPC_FilterValue, 50, 54, 0, // Skip to: 2301
/* 2247 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 2250 */    MCD::OPC_FilterValue, 0, 25, 0, // Skip to: 2279
/* 2254 */    MCD::OPC_ExtractField, 5, 8,  // Inst{12-5} ...
/* 2257 */    MCD::OPC_FilterValue, 0, 235, 16, // Skip to: 6592
/* 2261 */    MCD::OPC_CheckField, 25, 5, 0, 4, 0, // Skip to: 2271
/* 2267 */    MCD::OPC_Decode, 147, 4, 12, // Opcode: WRWIMrr
/* 2271 */    MCD::OPC_CheckPredicate, 0, 221, 16, // Skip to: 6592
/* 2275 */    MCD::OPC_Decode, 141, 4, 28, // Opcode: WRPRrr
/* 2279 */    MCD::OPC_FilterValue, 1, 213, 16, // Skip to: 6592
/* 2283 */    MCD::OPC_CheckField, 25, 5, 0, 4, 0, // Skip to: 2293
/* 2289 */    MCD::OPC_Decode, 146, 4, 13, // Opcode: WRWIMri
/* 2293 */    MCD::OPC_CheckPredicate, 0, 199, 16, // Skip to: 6592
/* 2297 */    MCD::OPC_Decode, 140, 4, 29, // Opcode: WRPRri
/* 2301 */    MCD::OPC_FilterValue, 51, 37, 0, // Skip to: 2342
/* 2305 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 2308 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 2328
/* 2312 */    MCD::OPC_CheckField, 25, 5, 0, 178, 16, // Skip to: 6592
/* 2318 */    MCD::OPC_CheckField, 5, 8, 0, 172, 16, // Skip to: 6592
/* 2324 */    MCD::OPC_Decode, 145, 4, 12, // Opcode: WRTBRrr
/* 2328 */    MCD::OPC_FilterValue, 1, 164, 16, // Skip to: 6592
/* 2332 */    MCD::OPC_CheckField, 25, 5, 0, 158, 16, // Skip to: 6592
/* 2338 */    MCD::OPC_Decode, 144, 4, 13, // Opcode: WRTBRri
/* 2342 */    MCD::OPC_FilterValue, 52, 197, 2, // Skip to: 3055
/* 2346 */    MCD::OPC_ExtractField, 5, 9,  // Inst{13-5} ...
/* 2349 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 2363
/* 2353 */    MCD::OPC_CheckField, 14, 5, 0, 137, 16, // Skip to: 6592
/* 2359 */    MCD::OPC_Decode, 215, 1, 30, // Opcode: FMOVS
/* 2363 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 2381
/* 2367 */    MCD::OPC_CheckPredicate, 0, 125, 16, // Skip to: 6592
/* 2371 */    MCD::OPC_CheckField, 14, 5, 0, 119, 16, // Skip to: 6592
/* 2377 */    MCD::OPC_Decode, 189, 1, 31, // Opcode: FMOVD
/* 2381 */    MCD::OPC_FilterValue, 3, 14, 0, // Skip to: 2399
/* 2385 */    MCD::OPC_CheckPredicate, 0, 107, 16, // Skip to: 6592
/* 2389 */    MCD::OPC_CheckField, 14, 5, 0, 101, 16, // Skip to: 6592
/* 2395 */    MCD::OPC_Decode, 193, 1, 32, // Opcode: FMOVQ
/* 2399 */    MCD::OPC_FilterValue, 5, 10, 0, // Skip to: 2413
/* 2403 */    MCD::OPC_CheckField, 14, 5, 0, 87, 16, // Skip to: 6592
/* 2409 */    MCD::OPC_Decode, 235, 1, 30, // Opcode: FNEGS
/* 2413 */    MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 2431
/* 2417 */    MCD::OPC_CheckPredicate, 0, 75, 16, // Skip to: 6592
/* 2421 */    MCD::OPC_CheckField, 14, 5, 0, 69, 16, // Skip to: 6592
/* 2427 */    MCD::OPC_Decode, 233, 1, 31, // Opcode: FNEGD
/* 2431 */    MCD::OPC_FilterValue, 7, 14, 0, // Skip to: 2449
/* 2435 */    MCD::OPC_CheckPredicate, 0, 57, 16, // Skip to: 6592
/* 2439 */    MCD::OPC_CheckField, 14, 5, 0, 51, 16, // Skip to: 6592
/* 2445 */    MCD::OPC_Decode, 234, 1, 32, // Opcode: FNEGQ
/* 2449 */    MCD::OPC_FilterValue, 9, 10, 0, // Skip to: 2463
/* 2453 */    MCD::OPC_CheckField, 14, 5, 0, 37, 16, // Skip to: 6592
/* 2459 */    MCD::OPC_Decode, 141, 1, 30, // Opcode: FABSS
/* 2463 */    MCD::OPC_FilterValue, 10, 14, 0, // Skip to: 2481
/* 2467 */    MCD::OPC_CheckPredicate, 0, 25, 16, // Skip to: 6592
/* 2471 */    MCD::OPC_CheckField, 14, 5, 0, 19, 16, // Skip to: 6592
/* 2477 */    MCD::OPC_Decode, 139, 1, 31, // Opcode: FABSD
/* 2481 */    MCD::OPC_FilterValue, 11, 14, 0, // Skip to: 2499
/* 2485 */    MCD::OPC_CheckPredicate, 0, 7, 16, // Skip to: 6592
/* 2489 */    MCD::OPC_CheckField, 14, 5, 0, 1, 16, // Skip to: 6592
/* 2495 */    MCD::OPC_Decode, 140, 1, 32, // Opcode: FABSQ
/* 2499 */    MCD::OPC_FilterValue, 41, 10, 0, // Skip to: 2513
/* 2503 */    MCD::OPC_CheckField, 14, 5, 0, 243, 15, // Skip to: 6592
/* 2509 */    MCD::OPC_Decode, 151, 2, 30, // Opcode: FSQRTS
/* 2513 */    MCD::OPC_FilterValue, 42, 10, 0, // Skip to: 2527
/* 2517 */    MCD::OPC_CheckField, 14, 5, 0, 229, 15, // Skip to: 6592
/* 2523 */    MCD::OPC_Decode, 149, 2, 31, // Opcode: FSQRTD
/* 2527 */    MCD::OPC_FilterValue, 43, 10, 0, // Skip to: 2541
/* 2531 */    MCD::OPC_CheckField, 14, 5, 0, 215, 15, // Skip to: 6592
/* 2537 */    MCD::OPC_Decode, 150, 2, 32, // Opcode: FSQRTQ
/* 2541 */    MCD::OPC_FilterValue, 65, 4, 0, // Skip to: 2549
/* 2545 */    MCD::OPC_Decode, 144, 1, 33, // Opcode: FADDS
/* 2549 */    MCD::OPC_FilterValue, 66, 4, 0, // Skip to: 2557
/* 2553 */    MCD::OPC_Decode, 142, 1, 34, // Opcode: FADDD
/* 2557 */    MCD::OPC_FilterValue, 67, 4, 0, // Skip to: 2565
/* 2561 */    MCD::OPC_Decode, 143, 1, 35, // Opcode: FADDQ
/* 2565 */    MCD::OPC_FilterValue, 69, 4, 0, // Skip to: 2573
/* 2569 */    MCD::OPC_Decode, 166, 2, 33, // Opcode: FSUBS
/* 2573 */    MCD::OPC_FilterValue, 70, 4, 0, // Skip to: 2581
/* 2577 */    MCD::OPC_Decode, 164, 2, 34, // Opcode: FSUBD
/* 2581 */    MCD::OPC_FilterValue, 71, 4, 0, // Skip to: 2589
/* 2585 */    MCD::OPC_Decode, 165, 2, 35, // Opcode: FSUBQ
/* 2589 */    MCD::OPC_FilterValue, 73, 4, 0, // Skip to: 2597
/* 2593 */    MCD::OPC_Decode, 228, 1, 33, // Opcode: FMULS
/* 2597 */    MCD::OPC_FilterValue, 74, 4, 0, // Skip to: 2605
/* 2601 */    MCD::OPC_Decode, 224, 1, 34, // Opcode: FMULD
/* 2605 */    MCD::OPC_FilterValue, 75, 4, 0, // Skip to: 2613
/* 2609 */    MCD::OPC_Decode, 227, 1, 35, // Opcode: FMULQ
/* 2613 */    MCD::OPC_FilterValue, 77, 4, 0, // Skip to: 2621
/* 2617 */    MCD::OPC_Decode, 168, 1, 33, // Opcode: FDIVS
/* 2621 */    MCD::OPC_FilterValue, 78, 4, 0, // Skip to: 2629
/* 2625 */    MCD::OPC_Decode, 166, 1, 34, // Opcode: FDIVD
/* 2629 */    MCD::OPC_FilterValue, 79, 4, 0, // Skip to: 2637
/* 2633 */    MCD::OPC_Decode, 167, 1, 35, // Opcode: FDIVQ
/* 2637 */    MCD::OPC_FilterValue, 81, 8, 0, // Skip to: 2649
/* 2641 */    MCD::OPC_CheckPredicate, 1, 107, 15, // Skip to: 6592
/* 2645 */    MCD::OPC_Decode, 230, 1, 34, // Opcode: FNADDS
/* 2649 */    MCD::OPC_FilterValue, 82, 8, 0, // Skip to: 2661
/* 2653 */    MCD::OPC_CheckPredicate, 1, 95, 15, // Skip to: 6592
/* 2657 */    MCD::OPC_Decode, 229, 1, 34, // Opcode: FNADDD
/* 2661 */    MCD::OPC_FilterValue, 89, 8, 0, // Skip to: 2673
/* 2665 */    MCD::OPC_CheckPredicate, 1, 83, 15, // Skip to: 6592
/* 2669 */    MCD::OPC_Decode, 239, 1, 34, // Opcode: FNMULS
/* 2673 */    MCD::OPC_FilterValue, 90, 8, 0, // Skip to: 2685
/* 2677 */    MCD::OPC_CheckPredicate, 1, 71, 15, // Skip to: 6592
/* 2681 */    MCD::OPC_Decode, 238, 1, 34, // Opcode: FNMULD
/* 2685 */    MCD::OPC_FilterValue, 97, 8, 0, // Skip to: 2697
/* 2689 */    MCD::OPC_CheckPredicate, 1, 59, 15, // Skip to: 6592
/* 2693 */    MCD::OPC_Decode, 176, 1, 34, // Opcode: FHADDS
/* 2697 */    MCD::OPC_FilterValue, 98, 8, 0, // Skip to: 2709
/* 2701 */    MCD::OPC_CheckPredicate, 1, 47, 15, // Skip to: 6592
/* 2705 */    MCD::OPC_Decode, 175, 1, 34, // Opcode: FHADDD
/* 2709 */    MCD::OPC_FilterValue, 101, 8, 0, // Skip to: 2721
/* 2713 */    MCD::OPC_CheckPredicate, 1, 35, 15, // Skip to: 6592
/* 2717 */    MCD::OPC_Decode, 178, 1, 34, // Opcode: FHSUBS
/* 2721 */    MCD::OPC_FilterValue, 102, 8, 0, // Skip to: 2733
/* 2725 */    MCD::OPC_CheckPredicate, 1, 23, 15, // Skip to: 6592
/* 2729 */    MCD::OPC_Decode, 177, 1, 34, // Opcode: FHSUBD
/* 2733 */    MCD::OPC_FilterValue, 105, 4, 0, // Skip to: 2741
/* 2737 */    MCD::OPC_Decode, 148, 2, 36, // Opcode: FSMULD
/* 2741 */    MCD::OPC_FilterValue, 110, 4, 0, // Skip to: 2749
/* 2745 */    MCD::OPC_Decode, 169, 1, 37, // Opcode: FDMULQ
/* 2749 */    MCD::OPC_FilterValue, 113, 8, 0, // Skip to: 2761
/* 2753 */    MCD::OPC_CheckPredicate, 1, 251, 14, // Skip to: 6592
/* 2757 */    MCD::OPC_Decode, 237, 1, 34, // Opcode: FNHADDS
/* 2761 */    MCD::OPC_FilterValue, 114, 8, 0, // Skip to: 2773
/* 2765 */    MCD::OPC_CheckPredicate, 1, 239, 14, // Skip to: 6592
/* 2769 */    MCD::OPC_Decode, 236, 1, 34, // Opcode: FNHADDD
/* 2773 */    MCD::OPC_FilterValue, 121, 8, 0, // Skip to: 2785
/* 2777 */    MCD::OPC_CheckPredicate, 1, 227, 14, // Skip to: 6592
/* 2781 */    MCD::OPC_Decode, 246, 1, 34, // Opcode: FNSMULD
/* 2785 */    MCD::OPC_FilterValue, 129, 1, 10, 0, // Skip to: 2800
/* 2790 */    MCD::OPC_CheckField, 14, 5, 0, 212, 14, // Skip to: 6592
/* 2796 */    MCD::OPC_Decode, 163, 2, 38, // Opcode: FSTOX
/* 2800 */    MCD::OPC_FilterValue, 130, 1, 10, 0, // Skip to: 2815
/* 2805 */    MCD::OPC_CheckField, 14, 5, 0, 197, 14, // Skip to: 6592
/* 2811 */    MCD::OPC_Decode, 173, 1, 31, // Opcode: FDTOX
/* 2815 */    MCD::OPC_FilterValue, 131, 1, 10, 0, // Skip to: 2830
/* 2820 */    MCD::OPC_CheckField, 14, 5, 0, 182, 14, // Skip to: 6592
/* 2826 */    MCD::OPC_Decode, 143, 2, 39, // Opcode: FQTOX
/* 2830 */    MCD::OPC_FilterValue, 132, 1, 10, 0, // Skip to: 2845
/* 2835 */    MCD::OPC_CheckField, 14, 5, 0, 167, 14, // Skip to: 6592
/* 2841 */    MCD::OPC_Decode, 173, 2, 40, // Opcode: FXTOS
/* 2845 */    MCD::OPC_FilterValue, 136, 1, 10, 0, // Skip to: 2860
/* 2850 */    MCD::OPC_CheckField, 14, 5, 0, 152, 14, // Skip to: 6592
/* 2856 */    MCD::OPC_Decode, 171, 2, 31, // Opcode: FXTOD
/* 2860 */    MCD::OPC_FilterValue, 140, 1, 10, 0, // Skip to: 2875
/* 2865 */    MCD::OPC_CheckField, 14, 5, 0, 137, 14, // Skip to: 6592
/* 2871 */    MCD::OPC_Decode, 172, 2, 41, // Opcode: FXTOQ
/* 2875 */    MCD::OPC_FilterValue, 196, 1, 10, 0, // Skip to: 2890
/* 2880 */    MCD::OPC_CheckField, 14, 5, 0, 122, 14, // Skip to: 6592
/* 2886 */    MCD::OPC_Decode, 181, 1, 30, // Opcode: FITOS
/* 2890 */    MCD::OPC_FilterValue, 198, 1, 10, 0, // Skip to: 2905
/* 2895 */    MCD::OPC_CheckField, 14, 5, 0, 107, 14, // Skip to: 6592
/* 2901 */    MCD::OPC_Decode, 172, 1, 40, // Opcode: FDTOS
/* 2905 */    MCD::OPC_FilterValue, 199, 1, 10, 0, // Skip to: 2920
/* 2910 */    MCD::OPC_CheckField, 14, 5, 0, 92, 14, // Skip to: 6592
/* 2916 */    MCD::OPC_Decode, 142, 2, 42, // Opcode: FQTOS
/* 2920 */    MCD::OPC_FilterValue, 200, 1, 10, 0, // Skip to: 2935
/* 2925 */    MCD::OPC_CheckField, 14, 5, 0, 77, 14, // Skip to: 6592
/* 2931 */    MCD::OPC_Decode, 179, 1, 38, // Opcode: FITOD
/* 2935 */    MCD::OPC_FilterValue, 201, 1, 10, 0, // Skip to: 2950
/* 2940 */    MCD::OPC_CheckField, 14, 5, 0, 62, 14, // Skip to: 6592
/* 2946 */    MCD::OPC_Decode, 160, 2, 38, // Opcode: FSTOD
/* 2950 */    MCD::OPC_FilterValue, 203, 1, 10, 0, // Skip to: 2965
/* 2955 */    MCD::OPC_CheckField, 14, 5, 0, 47, 14, // Skip to: 6592
/* 2961 */    MCD::OPC_Decode, 140, 2, 39, // Opcode: FQTOD
/* 2965 */    MCD::OPC_FilterValue, 204, 1, 10, 0, // Skip to: 2980
/* 2970 */    MCD::OPC_CheckField, 14, 5, 0, 32, 14, // Skip to: 6592
/* 2976 */    MCD::OPC_Decode, 180, 1, 43, // Opcode: FITOQ
/* 2980 */    MCD::OPC_FilterValue, 205, 1, 10, 0, // Skip to: 2995
/* 2985 */    MCD::OPC_CheckField, 14, 5, 0, 17, 14, // Skip to: 6592
/* 2991 */    MCD::OPC_Decode, 162, 2, 43, // Opcode: FSTOQ
/* 2995 */    MCD::OPC_FilterValue, 206, 1, 10, 0, // Skip to: 3010
/* 3000 */    MCD::OPC_CheckField, 14, 5, 0, 2, 14, // Skip to: 6592
/* 3006 */    MCD::OPC_Decode, 171, 1, 41, // Opcode: FDTOQ
/* 3010 */    MCD::OPC_FilterValue, 209, 1, 10, 0, // Skip to: 3025
/* 3015 */    MCD::OPC_CheckField, 14, 5, 0, 243, 13, // Skip to: 6592
/* 3021 */    MCD::OPC_Decode, 161, 2, 30, // Opcode: FSTOI
/* 3025 */    MCD::OPC_FilterValue, 210, 1, 10, 0, // Skip to: 3040
/* 3030 */    MCD::OPC_CheckField, 14, 5, 0, 228, 13, // Skip to: 6592
/* 3036 */    MCD::OPC_Decode, 170, 1, 40, // Opcode: FDTOI
/* 3040 */    MCD::OPC_FilterValue, 211, 1, 219, 13, // Skip to: 6592
/* 3045 */    MCD::OPC_CheckField, 14, 5, 0, 213, 13, // Skip to: 6592
/* 3051 */    MCD::OPC_Decode, 141, 2, 42, // Opcode: FQTOI
/* 3055 */    MCD::OPC_FilterValue, 53, 70, 2, // Skip to: 3641
/* 3059 */    MCD::OPC_ExtractField, 5, 6,  // Inst{10-5} ...
/* 3062 */    MCD::OPC_FilterValue, 1, 75, 0, // Skip to: 3141
/* 3066 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 3069 */    MCD::OPC_FilterValue, 0, 29, 0, // Skip to: 3102
/* 3073 */    MCD::OPC_ExtractField, 18, 1,  // Inst{18} ...
/* 3076 */    MCD::OPC_FilterValue, 0, 184, 13, // Skip to: 6592
/* 3080 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 3094
/* 3084 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 3094
/* 3090 */    MCD::OPC_Decode, 216, 1, 44, // Opcode: FMOVS_FCC
/* 3094 */    MCD::OPC_CheckPredicate, 0, 166, 13, // Skip to: 6592
/* 3098 */    MCD::OPC_Decode, 135, 4, 45, // Opcode: V9FMOVS_FCC
/* 3102 */    MCD::OPC_FilterValue, 1, 158, 13, // Skip to: 6592
/* 3106 */    MCD::OPC_ExtractField, 11, 2,  // Inst{12-11} ...
/* 3109 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 3127
/* 3113 */    MCD::OPC_CheckPredicate, 0, 147, 13, // Skip to: 6592
/* 3117 */    MCD::OPC_CheckField, 18, 1, 0, 141, 13, // Skip to: 6592
/* 3123 */    MCD::OPC_Decode, 217, 1, 44, // Opcode: FMOVS_ICC
/* 3127 */    MCD::OPC_FilterValue, 2, 133, 13, // Skip to: 6592
/* 3131 */    MCD::OPC_CheckField, 18, 1, 0, 127, 13, // Skip to: 6592
/* 3137 */    MCD::OPC_Decode, 218, 1, 44, // Opcode: FMOVS_XCC
/* 3141 */    MCD::OPC_FilterValue, 2, 75, 0, // Skip to: 3220
/* 3145 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 3148 */    MCD::OPC_FilterValue, 0, 29, 0, // Skip to: 3181
/* 3152 */    MCD::OPC_ExtractField, 18, 1,  // Inst{18} ...
/* 3155 */    MCD::OPC_FilterValue, 0, 105, 13, // Skip to: 6592
/* 3159 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 3173
/* 3163 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 3173
/* 3169 */    MCD::OPC_Decode, 190, 1, 46, // Opcode: FMOVD_FCC
/* 3173 */    MCD::OPC_CheckPredicate, 0, 87, 13, // Skip to: 6592
/* 3177 */    MCD::OPC_Decode, 133, 4, 47, // Opcode: V9FMOVD_FCC
/* 3181 */    MCD::OPC_FilterValue, 1, 79, 13, // Skip to: 6592
/* 3185 */    MCD::OPC_ExtractField, 11, 2,  // Inst{12-11} ...
/* 3188 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 3206
/* 3192 */    MCD::OPC_CheckPredicate, 0, 68, 13, // Skip to: 6592
/* 3196 */    MCD::OPC_CheckField, 18, 1, 0, 62, 13, // Skip to: 6592
/* 3202 */    MCD::OPC_Decode, 191, 1, 46, // Opcode: FMOVD_ICC
/* 3206 */    MCD::OPC_FilterValue, 2, 54, 13, // Skip to: 6592
/* 3210 */    MCD::OPC_CheckField, 18, 1, 0, 48, 13, // Skip to: 6592
/* 3216 */    MCD::OPC_Decode, 192, 1, 46, // Opcode: FMOVD_XCC
/* 3220 */    MCD::OPC_FilterValue, 3, 75, 0, // Skip to: 3299
/* 3224 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 3227 */    MCD::OPC_FilterValue, 0, 29, 0, // Skip to: 3260
/* 3231 */    MCD::OPC_ExtractField, 18, 1,  // Inst{18} ...
/* 3234 */    MCD::OPC_FilterValue, 0, 26, 13, // Skip to: 6592
/* 3238 */    MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 3252
/* 3242 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 3252
/* 3248 */    MCD::OPC_Decode, 194, 1, 48, // Opcode: FMOVQ_FCC
/* 3252 */    MCD::OPC_CheckPredicate, 0, 8, 13, // Skip to: 6592
/* 3256 */    MCD::OPC_Decode, 134, 4, 49, // Opcode: V9FMOVQ_FCC
/* 3260 */    MCD::OPC_FilterValue, 1, 0, 13, // Skip to: 6592
/* 3264 */    MCD::OPC_ExtractField, 11, 2,  // Inst{12-11} ...
/* 3267 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 3285
/* 3271 */    MCD::OPC_CheckPredicate, 0, 245, 12, // Skip to: 6592
/* 3275 */    MCD::OPC_CheckField, 18, 1, 0, 239, 12, // Skip to: 6592
/* 3281 */    MCD::OPC_Decode, 195, 1, 48, // Opcode: FMOVQ_ICC
/* 3285 */    MCD::OPC_FilterValue, 2, 231, 12, // Skip to: 6592
/* 3289 */    MCD::OPC_CheckField, 18, 1, 0, 225, 12, // Skip to: 6592
/* 3295 */    MCD::OPC_Decode, 196, 1, 48, // Opcode: FMOVQ_XCC
/* 3299 */    MCD::OPC_FilterValue, 5, 27, 0, // Skip to: 3330
/* 3303 */    MCD::OPC_ExtractField, 11, 3,  // Inst{13-11} ...
/* 3306 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3318
/* 3310 */    MCD::OPC_CheckPredicate, 0, 206, 12, // Skip to: 6592
/* 3314 */    MCD::OPC_Decode, 205, 1, 50, // Opcode: FMOVRLEZS
/* 3318 */    MCD::OPC_FilterValue, 3, 198, 12, // Skip to: 6592
/* 3322 */    MCD::OPC_CheckPredicate, 0, 194, 12, // Skip to: 6592
/* 3326 */    MCD::OPC_Decode, 202, 1, 50, // Opcode: FMOVRGZS
/* 3330 */    MCD::OPC_FilterValue, 6, 27, 0, // Skip to: 3361
/* 3334 */    MCD::OPC_ExtractField, 11, 3,  // Inst{13-11} ...
/* 3337 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3349
/* 3341 */    MCD::OPC_CheckPredicate, 0, 175, 12, // Skip to: 6592
/* 3345 */    MCD::OPC_Decode, 203, 1, 50, // Opcode: FMOVRLEZD
/* 3349 */    MCD::OPC_FilterValue, 3, 167, 12, // Skip to: 6592
/* 3353 */    MCD::OPC_CheckPredicate, 0, 163, 12, // Skip to: 6592
/* 3357 */    MCD::OPC_Decode, 200, 1, 50, // Opcode: FMOVRGZD
/* 3361 */    MCD::OPC_FilterValue, 7, 27, 0, // Skip to: 3392
/* 3365 */    MCD::OPC_ExtractField, 11, 3,  // Inst{13-11} ...
/* 3368 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3380
/* 3372 */    MCD::OPC_CheckPredicate, 0, 144, 12, // Skip to: 6592
/* 3376 */    MCD::OPC_Decode, 204, 1, 50, // Opcode: FMOVRLEZQ
/* 3380 */    MCD::OPC_FilterValue, 3, 136, 12, // Skip to: 6592
/* 3384 */    MCD::OPC_CheckPredicate, 0, 132, 12, // Skip to: 6592
/* 3388 */    MCD::OPC_Decode, 201, 1, 50, // Opcode: FMOVRGZQ
/* 3392 */    MCD::OPC_FilterValue, 17, 10, 0, // Skip to: 3406
/* 3396 */    MCD::OPC_CheckField, 11, 3, 1, 118, 12, // Skip to: 6592
/* 3402 */    MCD::OPC_Decode, 132, 4, 51, // Opcode: V9FCMPS
/* 3406 */    MCD::OPC_FilterValue, 18, 10, 0, // Skip to: 3420
/* 3410 */    MCD::OPC_CheckField, 11, 3, 1, 104, 12, // Skip to: 6592
/* 3416 */    MCD::OPC_Decode, 255, 3, 52, // Opcode: V9FCMPD
/* 3420 */    MCD::OPC_FilterValue, 19, 10, 0, // Skip to: 3434
/* 3424 */    MCD::OPC_CheckField, 11, 3, 1, 90, 12, // Skip to: 6592
/* 3430 */    MCD::OPC_Decode, 131, 4, 53, // Opcode: V9FCMPQ
/* 3434 */    MCD::OPC_FilterValue, 21, 10, 0, // Skip to: 3448
/* 3438 */    MCD::OPC_CheckField, 11, 3, 1, 76, 12, // Skip to: 6592
/* 3444 */    MCD::OPC_Decode, 130, 4, 51, // Opcode: V9FCMPES
/* 3448 */    MCD::OPC_FilterValue, 22, 10, 0, // Skip to: 3462
/* 3452 */    MCD::OPC_CheckField, 11, 3, 1, 62, 12, // Skip to: 6592
/* 3458 */    MCD::OPC_Decode, 128, 4, 52, // Opcode: V9FCMPED
/* 3462 */    MCD::OPC_FilterValue, 23, 10, 0, // Skip to: 3476
/* 3466 */    MCD::OPC_CheckField, 11, 3, 1, 48, 12, // Skip to: 6592
/* 3472 */    MCD::OPC_Decode, 129, 4, 53, // Opcode: V9FCMPEQ
/* 3476 */    MCD::OPC_FilterValue, 37, 51, 0, // Skip to: 3531
/* 3480 */    MCD::OPC_ExtractField, 11, 3,  // Inst{13-11} ...
/* 3483 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 3495
/* 3487 */    MCD::OPC_CheckPredicate, 0, 29, 12, // Skip to: 6592
/* 3491 */    MCD::OPC_Decode, 214, 1, 50, // Opcode: FMOVRZS
/* 3495 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3507
/* 3499 */    MCD::OPC_CheckPredicate, 0, 17, 12, // Skip to: 6592
/* 3503 */    MCD::OPC_Decode, 208, 1, 50, // Opcode: FMOVRLZS
/* 3507 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 3519
/* 3511 */    MCD::OPC_CheckPredicate, 0, 5, 12, // Skip to: 6592
/* 3515 */    MCD::OPC_Decode, 211, 1, 50, // Opcode: FMOVRNZS
/* 3519 */    MCD::OPC_FilterValue, 3, 253, 11, // Skip to: 6592
/* 3523 */    MCD::OPC_CheckPredicate, 0, 249, 11, // Skip to: 6592
/* 3527 */    MCD::OPC_Decode, 199, 1, 50, // Opcode: FMOVRGEZS
/* 3531 */    MCD::OPC_FilterValue, 38, 51, 0, // Skip to: 3586
/* 3535 */    MCD::OPC_ExtractField, 11, 3,  // Inst{13-11} ...
/* 3538 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 3550
/* 3542 */    MCD::OPC_CheckPredicate, 0, 230, 11, // Skip to: 6592
/* 3546 */    MCD::OPC_Decode, 212, 1, 50, // Opcode: FMOVRZD
/* 3550 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3562
/* 3554 */    MCD::OPC_CheckPredicate, 0, 218, 11, // Skip to: 6592
/* 3558 */    MCD::OPC_Decode, 206, 1, 50, // Opcode: FMOVRLZD
/* 3562 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 3574
/* 3566 */    MCD::OPC_CheckPredicate, 0, 206, 11, // Skip to: 6592
/* 3570 */    MCD::OPC_Decode, 209, 1, 50, // Opcode: FMOVRNZD
/* 3574 */    MCD::OPC_FilterValue, 3, 198, 11, // Skip to: 6592
/* 3578 */    MCD::OPC_CheckPredicate, 0, 194, 11, // Skip to: 6592
/* 3582 */    MCD::OPC_Decode, 197, 1, 50, // Opcode: FMOVRGEZD
/* 3586 */    MCD::OPC_FilterValue, 39, 186, 11, // Skip to: 6592
/* 3590 */    MCD::OPC_ExtractField, 11, 3,  // Inst{13-11} ...
/* 3593 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 3605
/* 3597 */    MCD::OPC_CheckPredicate, 0, 175, 11, // Skip to: 6592
/* 3601 */    MCD::OPC_Decode, 213, 1, 50, // Opcode: FMOVRZQ
/* 3605 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3617
/* 3609 */    MCD::OPC_CheckPredicate, 0, 163, 11, // Skip to: 6592
/* 3613 */    MCD::OPC_Decode, 207, 1, 50, // Opcode: FMOVRLZQ
/* 3617 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 3629
/* 3621 */    MCD::OPC_CheckPredicate, 0, 151, 11, // Skip to: 6592
/* 3625 */    MCD::OPC_Decode, 210, 1, 50, // Opcode: FMOVRNZQ
/* 3629 */    MCD::OPC_FilterValue, 3, 143, 11, // Skip to: 6592
/* 3633 */    MCD::OPC_CheckPredicate, 0, 139, 11, // Skip to: 6592
/* 3637 */    MCD::OPC_Decode, 198, 1, 50, // Opcode: FMOVRGEZQ
/* 3641 */    MCD::OPC_FilterValue, 54, 19, 6, // Skip to: 5200
/* 3645 */    MCD::OPC_ExtractField, 5, 9,  // Inst{13-5} ...
/* 3648 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 3660
/* 3652 */    MCD::OPC_CheckPredicate, 2, 120, 11, // Skip to: 6592
/* 3656 */    MCD::OPC_Decode, 135, 1, 10, // Opcode: EDGE8
/* 3660 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3672
/* 3664 */    MCD::OPC_CheckPredicate, 3, 108, 11, // Skip to: 6592
/* 3668 */    MCD::OPC_Decode, 138, 1, 10, // Opcode: EDGE8N
/* 3672 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 3684
/* 3676 */    MCD::OPC_CheckPredicate, 2, 96, 11, // Skip to: 6592
/* 3680 */    MCD::OPC_Decode, 136, 1, 10, // Opcode: EDGE8L
/* 3684 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 3696
/* 3688 */    MCD::OPC_CheckPredicate, 3, 84, 11, // Skip to: 6592
/* 3692 */    MCD::OPC_Decode, 137, 1, 10, // Opcode: EDGE8LN
/* 3696 */    MCD::OPC_FilterValue, 4, 7, 0, // Skip to: 3707
/* 3700 */    MCD::OPC_CheckPredicate, 2, 72, 11, // Skip to: 6592
/* 3704 */    MCD::OPC_Decode, 127, 10, // Opcode: EDGE16
/* 3707 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 3719
/* 3711 */    MCD::OPC_CheckPredicate, 3, 61, 11, // Skip to: 6592
/* 3715 */    MCD::OPC_Decode, 130, 1, 10, // Opcode: EDGE16N
/* 3719 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 3731
/* 3723 */    MCD::OPC_CheckPredicate, 2, 49, 11, // Skip to: 6592
/* 3727 */    MCD::OPC_Decode, 128, 1, 10, // Opcode: EDGE16L
/* 3731 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 3743
/* 3735 */    MCD::OPC_CheckPredicate, 3, 37, 11, // Skip to: 6592
/* 3739 */    MCD::OPC_Decode, 129, 1, 10, // Opcode: EDGE16LN
/* 3743 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 3755
/* 3747 */    MCD::OPC_CheckPredicate, 2, 25, 11, // Skip to: 6592
/* 3751 */    MCD::OPC_Decode, 131, 1, 10, // Opcode: EDGE32
/* 3755 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 3767
/* 3759 */    MCD::OPC_CheckPredicate, 3, 13, 11, // Skip to: 6592
/* 3763 */    MCD::OPC_Decode, 134, 1, 10, // Opcode: EDGE32N
/* 3767 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 3779
/* 3771 */    MCD::OPC_CheckPredicate, 2, 1, 11, // Skip to: 6592
/* 3775 */    MCD::OPC_Decode, 132, 1, 10, // Opcode: EDGE32L
/* 3779 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 3791
/* 3783 */    MCD::OPC_CheckPredicate, 3, 245, 10, // Skip to: 6592
/* 3787 */    MCD::OPC_Decode, 133, 1, 10, // Opcode: EDGE32LN
/* 3791 */    MCD::OPC_FilterValue, 16, 7, 0, // Skip to: 3802
/* 3795 */    MCD::OPC_CheckPredicate, 2, 233, 10, // Skip to: 6592
/* 3799 */    MCD::OPC_Decode, 52, 10, // Opcode: ARRAY8
/* 3802 */    MCD::OPC_FilterValue, 17, 7, 0, // Skip to: 3813
/* 3806 */    MCD::OPC_CheckPredicate, 1, 222, 10, // Skip to: 6592
/* 3810 */    MCD::OPC_Decode, 29, 10, // Opcode: ADDXC
/* 3813 */    MCD::OPC_FilterValue, 18, 7, 0, // Skip to: 3824
/* 3817 */    MCD::OPC_CheckPredicate, 2, 211, 10, // Skip to: 6592
/* 3821 */    MCD::OPC_Decode, 50, 10, // Opcode: ARRAY16
/* 3824 */    MCD::OPC_FilterValue, 19, 7, 0, // Skip to: 3835
/* 3828 */    MCD::OPC_CheckPredicate, 1, 200, 10, // Skip to: 6592
/* 3832 */    MCD::OPC_Decode, 30, 10, // Opcode: ADDXCCC
/* 3835 */    MCD::OPC_FilterValue, 20, 7, 0, // Skip to: 3846
/* 3839 */    MCD::OPC_CheckPredicate, 2, 189, 10, // Skip to: 6592
/* 3843 */    MCD::OPC_Decode, 51, 10, // Opcode: ARRAY32
/* 3846 */    MCD::OPC_FilterValue, 22, 8, 0, // Skip to: 3858
/* 3850 */    MCD::OPC_CheckPredicate, 1, 178, 10, // Skip to: 6592
/* 3854 */    MCD::OPC_Decode, 251, 3, 10, // Opcode: UMULXHI
/* 3858 */    MCD::OPC_FilterValue, 23, 14, 0, // Skip to: 3876
/* 3862 */    MCD::OPC_CheckPredicate, 1, 166, 10, // Skip to: 6592
/* 3866 */    MCD::OPC_CheckField, 14, 5, 0, 160, 10, // Skip to: 6592
/* 3872 */    MCD::OPC_Decode, 219, 2, 54, // Opcode: LZCNT
/* 3876 */    MCD::OPC_FilterValue, 24, 7, 0, // Skip to: 3887
/* 3880 */    MCD::OPC_CheckPredicate, 2, 148, 10, // Skip to: 6592
/* 3884 */    MCD::OPC_Decode, 37, 10, // Opcode: ALIGNADDR
/* 3887 */    MCD::OPC_FilterValue, 25, 7, 0, // Skip to: 3898
/* 3891 */    MCD::OPC_CheckPredicate, 3, 137, 10, // Skip to: 6592
/* 3895 */    MCD::OPC_Decode, 79, 10, // Opcode: BMASK
/* 3898 */    MCD::OPC_FilterValue, 26, 7, 0, // Skip to: 3909
/* 3902 */    MCD::OPC_CheckPredicate, 2, 126, 10, // Skip to: 6592
/* 3906 */    MCD::OPC_Decode, 38, 10, // Opcode: ALIGNADDRL
/* 3909 */    MCD::OPC_FilterValue, 27, 19, 0, // Skip to: 3932
/* 3913 */    MCD::OPC_CheckPredicate, 1, 115, 10, // Skip to: 6592
/* 3917 */    MCD::OPC_CheckField, 25, 5, 0, 109, 10, // Skip to: 6592
/* 3923 */    MCD::OPC_CheckField, 14, 5, 0, 103, 10, // Skip to: 6592
/* 3929 */    MCD::OPC_Decode, 124, 55, // Opcode: CMASK8
/* 3932 */    MCD::OPC_FilterValue, 28, 7, 0, // Skip to: 3943
/* 3936 */    MCD::OPC_CheckPredicate, 3, 92, 10, // Skip to: 6592
/* 3940 */    MCD::OPC_Decode, 116, 34, // Opcode: BSHUFFLE
/* 3943 */    MCD::OPC_FilterValue, 29, 19, 0, // Skip to: 3966
/* 3947 */    MCD::OPC_CheckPredicate, 1, 81, 10, // Skip to: 6592
/* 3951 */    MCD::OPC_CheckField, 25, 5, 0, 75, 10, // Skip to: 6592
/* 3957 */    MCD::OPC_CheckField, 14, 5, 0, 69, 10, // Skip to: 6592
/* 3963 */    MCD::OPC_Decode, 122, 55, // Opcode: CMASK16
/* 3966 */    MCD::OPC_FilterValue, 31, 19, 0, // Skip to: 3989
/* 3970 */    MCD::OPC_CheckPredicate, 1, 58, 10, // Skip to: 6592
/* 3974 */    MCD::OPC_CheckField, 25, 5, 0, 52, 10, // Skip to: 6592
/* 3980 */    MCD::OPC_CheckField, 14, 5, 0, 46, 10, // Skip to: 6592
/* 3986 */    MCD::OPC_Decode, 123, 55, // Opcode: CMASK32
/* 3989 */    MCD::OPC_FilterValue, 32, 8, 0, // Skip to: 4001
/* 3993 */    MCD::OPC_CheckPredicate, 2, 35, 10, // Skip to: 6592
/* 3997 */    MCD::OPC_Decode, 160, 1, 56, // Opcode: FCMPLE16
/* 4001 */    MCD::OPC_FilterValue, 33, 8, 0, // Skip to: 4013
/* 4005 */    MCD::OPC_CheckPredicate, 1, 23, 10, // Skip to: 6592
/* 4009 */    MCD::OPC_Decode, 146, 2, 34, // Opcode: FSLL16
/* 4013 */    MCD::OPC_FilterValue, 34, 8, 0, // Skip to: 4025
/* 4017 */    MCD::OPC_CheckPredicate, 2, 11, 10, // Skip to: 6592
/* 4021 */    MCD::OPC_Decode, 162, 1, 56, // Opcode: FCMPNE16
/* 4025 */    MCD::OPC_FilterValue, 35, 8, 0, // Skip to: 4037
/* 4029 */    MCD::OPC_CheckPredicate, 1, 255, 9, // Skip to: 6592
/* 4033 */    MCD::OPC_Decode, 158, 2, 34, // Opcode: FSRL16
/* 4037 */    MCD::OPC_FilterValue, 36, 8, 0, // Skip to: 4049
/* 4041 */    MCD::OPC_CheckPredicate, 2, 243, 9, // Skip to: 6592
/* 4045 */    MCD::OPC_Decode, 161, 1, 56, // Opcode: FCMPLE32
/* 4049 */    MCD::OPC_FilterValue, 37, 8, 0, // Skip to: 4061
/* 4053 */    MCD::OPC_CheckPredicate, 1, 231, 9, // Skip to: 6592
/* 4057 */    MCD::OPC_Decode, 147, 2, 34, // Opcode: FSLL32
/* 4061 */    MCD::OPC_FilterValue, 38, 8, 0, // Skip to: 4073
/* 4065 */    MCD::OPC_CheckPredicate, 2, 219, 9, // Skip to: 6592
/* 4069 */    MCD::OPC_Decode, 163, 1, 56, // Opcode: FCMPNE32
/* 4073 */    MCD::OPC_FilterValue, 39, 8, 0, // Skip to: 4085
/* 4077 */    MCD::OPC_CheckPredicate, 1, 207, 9, // Skip to: 6592
/* 4081 */    MCD::OPC_Decode, 159, 2, 34, // Opcode: FSRL32
/* 4085 */    MCD::OPC_FilterValue, 40, 8, 0, // Skip to: 4097
/* 4089 */    MCD::OPC_CheckPredicate, 2, 195, 9, // Skip to: 6592
/* 4093 */    MCD::OPC_Decode, 158, 1, 56, // Opcode: FCMPGT16
/* 4097 */    MCD::OPC_FilterValue, 41, 8, 0, // Skip to: 4109
/* 4101 */    MCD::OPC_CheckPredicate, 1, 183, 9, // Skip to: 6592
/* 4105 */    MCD::OPC_Decode, 144, 2, 34, // Opcode: FSLAS16
/* 4109 */    MCD::OPC_FilterValue, 42, 8, 0, // Skip to: 4121
/* 4113 */    MCD::OPC_CheckPredicate, 2, 171, 9, // Skip to: 6592
/* 4117 */    MCD::OPC_Decode, 156, 1, 56, // Opcode: FCMPEQ16
/* 4121 */    MCD::OPC_FilterValue, 43, 8, 0, // Skip to: 4133
/* 4125 */    MCD::OPC_CheckPredicate, 1, 159, 9, // Skip to: 6592
/* 4129 */    MCD::OPC_Decode, 152, 2, 34, // Opcode: FSRA16
/* 4133 */    MCD::OPC_FilterValue, 44, 8, 0, // Skip to: 4145
/* 4137 */    MCD::OPC_CheckPredicate, 2, 147, 9, // Skip to: 6592
/* 4141 */    MCD::OPC_Decode, 159, 1, 56, // Opcode: FCMPGT32
/* 4145 */    MCD::OPC_FilterValue, 45, 8, 0, // Skip to: 4157
/* 4149 */    MCD::OPC_CheckPredicate, 1, 135, 9, // Skip to: 6592
/* 4153 */    MCD::OPC_Decode, 145, 2, 34, // Opcode: FSLAS32
/* 4157 */    MCD::OPC_FilterValue, 46, 8, 0, // Skip to: 4169
/* 4161 */    MCD::OPC_CheckPredicate, 2, 123, 9, // Skip to: 6592
/* 4165 */    MCD::OPC_Decode, 157, 1, 56, // Opcode: FCMPEQ32
/* 4169 */    MCD::OPC_FilterValue, 47, 8, 0, // Skip to: 4181
/* 4173 */    MCD::OPC_CheckPredicate, 1, 111, 9, // Skip to: 6592
/* 4177 */    MCD::OPC_Decode, 153, 2, 34, // Opcode: FSRA32
/* 4181 */    MCD::OPC_FilterValue, 49, 8, 0, // Skip to: 4193
/* 4185 */    MCD::OPC_CheckPredicate, 2, 99, 9, // Skip to: 6592
/* 4189 */    MCD::OPC_Decode, 221, 1, 34, // Opcode: FMUL8X16
/* 4193 */    MCD::OPC_FilterValue, 51, 8, 0, // Skip to: 4205
/* 4197 */    MCD::OPC_CheckPredicate, 2, 87, 9, // Skip to: 6592
/* 4201 */    MCD::OPC_Decode, 223, 1, 34, // Opcode: FMUL8X16AU
/* 4205 */    MCD::OPC_FilterValue, 53, 8, 0, // Skip to: 4217
/* 4209 */    MCD::OPC_CheckPredicate, 2, 75, 9, // Skip to: 6592
/* 4213 */    MCD::OPC_Decode, 222, 1, 34, // Opcode: FMUL8X16AL
/* 4217 */    MCD::OPC_FilterValue, 54, 8, 0, // Skip to: 4229
/* 4221 */    MCD::OPC_CheckPredicate, 2, 63, 9, // Skip to: 6592
/* 4225 */    MCD::OPC_Decode, 219, 1, 34, // Opcode: FMUL8SUX16
/* 4229 */    MCD::OPC_FilterValue, 55, 8, 0, // Skip to: 4241
/* 4233 */    MCD::OPC_CheckPredicate, 2, 51, 9, // Skip to: 6592
/* 4237 */    MCD::OPC_Decode, 220, 1, 34, // Opcode: FMUL8ULX16
/* 4241 */    MCD::OPC_FilterValue, 56, 8, 0, // Skip to: 4253
/* 4245 */    MCD::OPC_CheckPredicate, 2, 39, 9, // Skip to: 6592
/* 4249 */    MCD::OPC_Decode, 225, 1, 34, // Opcode: FMULD8SUX16
/* 4253 */    MCD::OPC_FilterValue, 57, 8, 0, // Skip to: 4265
/* 4257 */    MCD::OPC_CheckPredicate, 2, 27, 9, // Skip to: 6592
/* 4261 */    MCD::OPC_Decode, 226, 1, 34, // Opcode: FMULD8ULX16
/* 4265 */    MCD::OPC_FilterValue, 58, 8, 0, // Skip to: 4277
/* 4269 */    MCD::OPC_CheckPredicate, 2, 15, 9, // Skip to: 6592
/* 4273 */    MCD::OPC_Decode, 128, 2, 34, // Opcode: FPACK32
/* 4277 */    MCD::OPC_FilterValue, 59, 14, 0, // Skip to: 4295
/* 4281 */    MCD::OPC_CheckPredicate, 2, 3, 9, // Skip to: 6592
/* 4285 */    MCD::OPC_CheckField, 14, 5, 0, 253, 8, // Skip to: 6592
/* 4291 */    MCD::OPC_Decode, 255, 1, 31, // Opcode: FPACK16
/* 4295 */    MCD::OPC_FilterValue, 61, 14, 0, // Skip to: 4313
/* 4299 */    MCD::OPC_CheckPredicate, 2, 241, 8, // Skip to: 6592
/* 4303 */    MCD::OPC_CheckField, 14, 5, 0, 235, 8, // Skip to: 6592
/* 4309 */    MCD::OPC_Decode, 129, 2, 31, // Opcode: FPACKFIX
/* 4313 */    MCD::OPC_FilterValue, 62, 8, 0, // Skip to: 4325
/* 4317 */    MCD::OPC_CheckPredicate, 2, 223, 8, // Skip to: 6592
/* 4321 */    MCD::OPC_Decode, 132, 3, 34, // Opcode: PDIST
/* 4325 */    MCD::OPC_FilterValue, 63, 8, 0, // Skip to: 4337
/* 4329 */    MCD::OPC_CheckPredicate, 1, 211, 8, // Skip to: 6592
/* 4333 */    MCD::OPC_Decode, 133, 3, 34, // Opcode: PDISTN
/* 4337 */    MCD::OPC_FilterValue, 64, 8, 0, // Skip to: 4349
/* 4341 */    MCD::OPC_CheckPredicate, 1, 199, 8, // Skip to: 6592
/* 4345 */    MCD::OPC_Decode, 188, 1, 34, // Opcode: FMEAN16
/* 4349 */    MCD::OPC_FilterValue, 66, 8, 0, // Skip to: 4361
/* 4353 */    MCD::OPC_CheckPredicate, 1, 187, 8, // Skip to: 6592
/* 4357 */    MCD::OPC_Decode, 134, 2, 34, // Opcode: FPADD64
/* 4361 */    MCD::OPC_FilterValue, 68, 8, 0, // Skip to: 4373
/* 4365 */    MCD::OPC_CheckPredicate, 1, 175, 8, // Skip to: 6592
/* 4369 */    MCD::OPC_Decode, 154, 1, 34, // Opcode: FCHKSM16
/* 4373 */    MCD::OPC_FilterValue, 72, 8, 0, // Skip to: 4385
/* 4377 */    MCD::OPC_CheckPredicate, 2, 163, 8, // Skip to: 6592
/* 4381 */    MCD::OPC_Decode, 145, 1, 34, // Opcode: FALIGNADATA
/* 4385 */    MCD::OPC_FilterValue, 75, 8, 0, // Skip to: 4397
/* 4389 */    MCD::OPC_CheckPredicate, 2, 151, 8, // Skip to: 6592
/* 4393 */    MCD::OPC_Decode, 135, 2, 34, // Opcode: FPMERGE
/* 4397 */    MCD::OPC_FilterValue, 77, 14, 0, // Skip to: 4415
/* 4401 */    MCD::OPC_CheckPredicate, 2, 139, 8, // Skip to: 6592
/* 4405 */    MCD::OPC_CheckField, 14, 5, 0, 133, 8, // Skip to: 6592
/* 4411 */    MCD::OPC_Decode, 174, 1, 31, // Opcode: FEXPAND
/* 4415 */    MCD::OPC_FilterValue, 80, 8, 0, // Skip to: 4427
/* 4419 */    MCD::OPC_CheckPredicate, 2, 121, 8, // Skip to: 6592
/* 4423 */    MCD::OPC_Decode, 130, 2, 34, // Opcode: FPADD16
/* 4427 */    MCD::OPC_FilterValue, 81, 8, 0, // Skip to: 4439
/* 4431 */    MCD::OPC_CheckPredicate, 2, 109, 8, // Skip to: 6592
/* 4435 */    MCD::OPC_Decode, 131, 2, 34, // Opcode: FPADD16S
/* 4439 */    MCD::OPC_FilterValue, 82, 8, 0, // Skip to: 4451
/* 4443 */    MCD::OPC_CheckPredicate, 2, 97, 8, // Skip to: 6592
/* 4447 */    MCD::OPC_Decode, 132, 2, 34, // Opcode: FPADD32
/* 4451 */    MCD::OPC_FilterValue, 83, 8, 0, // Skip to: 4463
/* 4455 */    MCD::OPC_CheckPredicate, 2, 85, 8, // Skip to: 6592
/* 4459 */    MCD::OPC_Decode, 133, 2, 34, // Opcode: FPADD32S
/* 4463 */    MCD::OPC_FilterValue, 84, 8, 0, // Skip to: 4475
/* 4467 */    MCD::OPC_CheckPredicate, 2, 73, 8, // Skip to: 6592
/* 4471 */    MCD::OPC_Decode, 136, 2, 34, // Opcode: FPSUB16
/* 4475 */    MCD::OPC_FilterValue, 85, 8, 0, // Skip to: 4487
/* 4479 */    MCD::OPC_CheckPredicate, 2, 61, 8, // Skip to: 6592
/* 4483 */    MCD::OPC_Decode, 137, 2, 34, // Opcode: FPSUB16S
/* 4487 */    MCD::OPC_FilterValue, 86, 8, 0, // Skip to: 4499
/* 4491 */    MCD::OPC_CheckPredicate, 2, 49, 8, // Skip to: 6592
/* 4495 */    MCD::OPC_Decode, 138, 2, 34, // Opcode: FPSUB32
/* 4499 */    MCD::OPC_FilterValue, 87, 8, 0, // Skip to: 4511
/* 4503 */    MCD::OPC_CheckPredicate, 2, 37, 8, // Skip to: 6592
/* 4507 */    MCD::OPC_Decode, 139, 2, 34, // Opcode: FPSUB32S
/* 4511 */    MCD::OPC_FilterValue, 96, 20, 0, // Skip to: 4535
/* 4515 */    MCD::OPC_CheckPredicate, 2, 25, 8, // Skip to: 6592
/* 4519 */    MCD::OPC_CheckField, 14, 5, 0, 19, 8, // Skip to: 6592
/* 4525 */    MCD::OPC_CheckField, 0, 5, 0, 13, 8, // Skip to: 6592
/* 4531 */    MCD::OPC_Decode, 174, 2, 57, // Opcode: FZERO
/* 4535 */    MCD::OPC_FilterValue, 97, 20, 0, // Skip to: 4559
/* 4539 */    MCD::OPC_CheckPredicate, 2, 1, 8, // Skip to: 6592
/* 4543 */    MCD::OPC_CheckField, 14, 5, 0, 251, 7, // Skip to: 6592
/* 4549 */    MCD::OPC_CheckField, 0, 5, 0, 245, 7, // Skip to: 6592
/* 4555 */    MCD::OPC_Decode, 175, 2, 58, // Opcode: FZEROS
/* 4559 */    MCD::OPC_FilterValue, 98, 8, 0, // Skip to: 4571
/* 4563 */    MCD::OPC_CheckPredicate, 2, 233, 7, // Skip to: 6592
/* 4567 */    MCD::OPC_Decode, 240, 1, 34, // Opcode: FNOR
/* 4571 */    MCD::OPC_FilterValue, 99, 8, 0, // Skip to: 4583
/* 4575 */    MCD::OPC_CheckPredicate, 2, 221, 7, // Skip to: 6592
/* 4579 */    MCD::OPC_Decode, 241, 1, 33, // Opcode: FNORS
/* 4583 */    MCD::OPC_FilterValue, 100, 8, 0, // Skip to: 4595
/* 4587 */    MCD::OPC_CheckPredicate, 2, 209, 7, // Skip to: 6592
/* 4591 */    MCD::OPC_Decode, 149, 1, 34, // Opcode: FANDNOT2
/* 4595 */    MCD::OPC_FilterValue, 101, 8, 0, // Skip to: 4607
/* 4599 */    MCD::OPC_CheckPredicate, 2, 197, 7, // Skip to: 6592
/* 4603 */    MCD::OPC_Decode, 150, 1, 33, // Opcode: FANDNOT2S
/* 4607 */    MCD::OPC_FilterValue, 102, 14, 0, // Skip to: 4625
/* 4611 */    MCD::OPC_CheckPredicate, 2, 185, 7, // Skip to: 6592
/* 4615 */    MCD::OPC_CheckField, 14, 5, 0, 179, 7, // Skip to: 6592
/* 4621 */    MCD::OPC_Decode, 244, 1, 31, // Opcode: FNOT2
/* 4625 */    MCD::OPC_FilterValue, 103, 14, 0, // Skip to: 4643
/* 4629 */    MCD::OPC_CheckPredicate, 2, 167, 7, // Skip to: 6592
/* 4633 */    MCD::OPC_CheckField, 14, 5, 0, 161, 7, // Skip to: 6592
/* 4639 */    MCD::OPC_Decode, 245, 1, 30, // Opcode: FNOT2S
/* 4643 */    MCD::OPC_FilterValue, 104, 8, 0, // Skip to: 4655
/* 4647 */    MCD::OPC_CheckPredicate, 2, 149, 7, // Skip to: 6592
/* 4651 */    MCD::OPC_Decode, 147, 1, 34, // Opcode: FANDNOT1
/* 4655 */    MCD::OPC_FilterValue, 105, 8, 0, // Skip to: 4667
/* 4659 */    MCD::OPC_CheckPredicate, 2, 137, 7, // Skip to: 6592
/* 4663 */    MCD::OPC_Decode, 148, 1, 33, // Opcode: FANDNOT1S
/* 4667 */    MCD::OPC_FilterValue, 106, 14, 0, // Skip to: 4685
/* 4671 */    MCD::OPC_CheckPredicate, 2, 125, 7, // Skip to: 6592
/* 4675 */    MCD::OPC_CheckField, 0, 5, 0, 119, 7, // Skip to: 6592
/* 4681 */    MCD::OPC_Decode, 242, 1, 59, // Opcode: FNOT1
/* 4685 */    MCD::OPC_FilterValue, 107, 14, 0, // Skip to: 4703
/* 4689 */    MCD::OPC_CheckPredicate, 2, 107, 7, // Skip to: 6592
/* 4693 */    MCD::OPC_CheckField, 0, 5, 0, 101, 7, // Skip to: 6592
/* 4699 */    MCD::OPC_Decode, 243, 1, 60, // Opcode: FNOT1S
/* 4703 */    MCD::OPC_FilterValue, 108, 8, 0, // Skip to: 4715
/* 4707 */    MCD::OPC_CheckPredicate, 2, 89, 7, // Skip to: 6592
/* 4711 */    MCD::OPC_Decode, 169, 2, 34, // Opcode: FXOR
/* 4715 */    MCD::OPC_FilterValue, 109, 8, 0, // Skip to: 4727
/* 4719 */    MCD::OPC_CheckPredicate, 2, 77, 7, // Skip to: 6592
/* 4723 */    MCD::OPC_Decode, 170, 2, 33, // Opcode: FXORS
/* 4727 */    MCD::OPC_FilterValue, 110, 8, 0, // Skip to: 4739
/* 4731 */    MCD::OPC_CheckPredicate, 2, 65, 7, // Skip to: 6592
/* 4735 */    MCD::OPC_Decode, 231, 1, 34, // Opcode: FNAND
/* 4739 */    MCD::OPC_FilterValue, 111, 8, 0, // Skip to: 4751
/* 4743 */    MCD::OPC_CheckPredicate, 2, 53, 7, // Skip to: 6592
/* 4747 */    MCD::OPC_Decode, 232, 1, 33, // Opcode: FNANDS
/* 4751 */    MCD::OPC_FilterValue, 112, 8, 0, // Skip to: 4763
/* 4755 */    MCD::OPC_CheckPredicate, 2, 41, 7, // Skip to: 6592
/* 4759 */    MCD::OPC_Decode, 146, 1, 34, // Opcode: FAND
/* 4763 */    MCD::OPC_FilterValue, 113, 8, 0, // Skip to: 4775
/* 4767 */    MCD::OPC_CheckPredicate, 2, 29, 7, // Skip to: 6592
/* 4771 */    MCD::OPC_Decode, 151, 1, 33, // Opcode: FANDS
/* 4775 */    MCD::OPC_FilterValue, 114, 8, 0, // Skip to: 4787
/* 4779 */    MCD::OPC_CheckPredicate, 2, 17, 7, // Skip to: 6592
/* 4783 */    MCD::OPC_Decode, 167, 2, 34, // Opcode: FXNOR
/* 4787 */    MCD::OPC_FilterValue, 115, 8, 0, // Skip to: 4799
/* 4791 */    MCD::OPC_CheckPredicate, 2, 5, 7, // Skip to: 6592
/* 4795 */    MCD::OPC_Decode, 168, 2, 33, // Opcode: FXNORS
/* 4799 */    MCD::OPC_FilterValue, 116, 14, 0, // Skip to: 4817
/* 4803 */    MCD::OPC_CheckPredicate, 2, 249, 6, // Skip to: 6592
/* 4807 */    MCD::OPC_CheckField, 0, 5, 0, 243, 6, // Skip to: 6592
/* 4813 */    MCD::OPC_Decode, 154, 2, 59, // Opcode: FSRC1
/* 4817 */    MCD::OPC_FilterValue, 117, 14, 0, // Skip to: 4835
/* 4821 */    MCD::OPC_CheckPredicate, 2, 231, 6, // Skip to: 6592
/* 4825 */    MCD::OPC_CheckField, 0, 5, 0, 225, 6, // Skip to: 6592
/* 4831 */    MCD::OPC_Decode, 155, 2, 60, // Opcode: FSRC1S
/* 4835 */    MCD::OPC_FilterValue, 118, 8, 0, // Skip to: 4847
/* 4839 */    MCD::OPC_CheckPredicate, 2, 213, 6, // Skip to: 6592
/* 4843 */    MCD::OPC_Decode, 252, 1, 34, // Opcode: FORNOT2
/* 4847 */    MCD::OPC_FilterValue, 119, 8, 0, // Skip to: 4859
/* 4851 */    MCD::OPC_CheckPredicate, 2, 201, 6, // Skip to: 6592
/* 4855 */    MCD::OPC_Decode, 253, 1, 33, // Opcode: FORNOT2S
/* 4859 */    MCD::OPC_FilterValue, 120, 14, 0, // Skip to: 4877
/* 4863 */    MCD::OPC_CheckPredicate, 2, 189, 6, // Skip to: 6592
/* 4867 */    MCD::OPC_CheckField, 14, 5, 0, 183, 6, // Skip to: 6592
/* 4873 */    MCD::OPC_Decode, 156, 2, 31, // Opcode: FSRC2
/* 4877 */    MCD::OPC_FilterValue, 121, 14, 0, // Skip to: 4895
/* 4881 */    MCD::OPC_CheckPredicate, 2, 171, 6, // Skip to: 6592
/* 4885 */    MCD::OPC_CheckField, 14, 5, 0, 165, 6, // Skip to: 6592
/* 4891 */    MCD::OPC_Decode, 157, 2, 30, // Opcode: FSRC2S
/* 4895 */    MCD::OPC_FilterValue, 122, 8, 0, // Skip to: 4907
/* 4899 */    MCD::OPC_CheckPredicate, 2, 153, 6, // Skip to: 6592
/* 4903 */    MCD::OPC_Decode, 250, 1, 34, // Opcode: FORNOT1
/* 4907 */    MCD::OPC_FilterValue, 123, 8, 0, // Skip to: 4919
/* 4911 */    MCD::OPC_CheckPredicate, 2, 141, 6, // Skip to: 6592
/* 4915 */    MCD::OPC_Decode, 251, 1, 33, // Opcode: FORNOT1S
/* 4919 */    MCD::OPC_FilterValue, 124, 8, 0, // Skip to: 4931
/* 4923 */    MCD::OPC_CheckPredicate, 2, 129, 6, // Skip to: 6592
/* 4927 */    MCD::OPC_Decode, 249, 1, 34, // Opcode: FOR
/* 4931 */    MCD::OPC_FilterValue, 125, 8, 0, // Skip to: 4943
/* 4935 */    MCD::OPC_CheckPredicate, 2, 117, 6, // Skip to: 6592
/* 4939 */    MCD::OPC_Decode, 254, 1, 33, // Opcode: FORS
/* 4943 */    MCD::OPC_FilterValue, 126, 20, 0, // Skip to: 4967
/* 4947 */    MCD::OPC_CheckPredicate, 2, 105, 6, // Skip to: 6592
/* 4951 */    MCD::OPC_CheckField, 14, 5, 0, 99, 6, // Skip to: 6592
/* 4957 */    MCD::OPC_CheckField, 0, 5, 0, 93, 6, // Skip to: 6592
/* 4963 */    MCD::OPC_Decode, 247, 1, 57, // Opcode: FONE
/* 4967 */    MCD::OPC_FilterValue, 127, 20, 0, // Skip to: 4991
/* 4971 */    MCD::OPC_CheckPredicate, 2, 81, 6, // Skip to: 6592
/* 4975 */    MCD::OPC_CheckField, 14, 5, 0, 75, 6, // Skip to: 6592
/* 4981 */    MCD::OPC_CheckField, 0, 5, 0, 69, 6, // Skip to: 6592
/* 4987 */    MCD::OPC_Decode, 248, 1, 58, // Opcode: FONES
/* 4991 */    MCD::OPC_FilterValue, 128, 1, 26, 0, // Skip to: 5022
/* 4996 */    MCD::OPC_CheckPredicate, 2, 56, 6, // Skip to: 6592
/* 5000 */    MCD::OPC_CheckField, 25, 5, 0, 50, 6, // Skip to: 6592
/* 5006 */    MCD::OPC_CheckField, 14, 5, 0, 44, 6, // Skip to: 6592
/* 5012 */    MCD::OPC_CheckField, 0, 5, 0, 38, 6, // Skip to: 6592
/* 5018 */    MCD::OPC_Decode, 165, 3, 4, // Opcode: SHUTDOWN
/* 5022 */    MCD::OPC_FilterValue, 129, 1, 26, 0, // Skip to: 5053
/* 5027 */    MCD::OPC_CheckPredicate, 3, 25, 6, // Skip to: 6592
/* 5031 */    MCD::OPC_CheckField, 25, 5, 0, 19, 6, // Skip to: 6592
/* 5037 */    MCD::OPC_CheckField, 14, 5, 0, 13, 6, // Skip to: 6592
/* 5043 */    MCD::OPC_CheckField, 0, 5, 0, 7, 6, // Skip to: 6592
/* 5049 */    MCD::OPC_Decode, 166, 3, 4, // Opcode: SIAM
/* 5053 */    MCD::OPC_FilterValue, 144, 2, 14, 0, // Skip to: 5072
/* 5058 */    MCD::OPC_CheckPredicate, 1, 250, 5, // Skip to: 6592
/* 5062 */    MCD::OPC_CheckField, 14, 5, 0, 244, 5, // Skip to: 6592
/* 5068 */    MCD::OPC_Decode, 221, 2, 61, // Opcode: MOVDTOX
/* 5072 */    MCD::OPC_FilterValue, 145, 2, 14, 0, // Skip to: 5091
/* 5077 */    MCD::OPC_CheckPredicate, 1, 231, 5, // Skip to: 6592
/* 5081 */    MCD::OPC_CheckField, 14, 5, 0, 225, 5, // Skip to: 6592
/* 5087 */    MCD::OPC_Decode, 239, 2, 61, // Opcode: MOVSTOUW
/* 5091 */    MCD::OPC_FilterValue, 147, 2, 14, 0, // Skip to: 5110
/* 5096 */    MCD::OPC_CheckPredicate, 1, 212, 5, // Skip to: 6592
/* 5100 */    MCD::OPC_CheckField, 14, 5, 0, 206, 5, // Skip to: 6592
/* 5106 */    MCD::OPC_Decode, 238, 2, 61, // Opcode: MOVSTOSW
/* 5110 */    MCD::OPC_FilterValue, 149, 2, 8, 0, // Skip to: 5123
/* 5115 */    MCD::OPC_CheckPredicate, 1, 193, 5, // Skip to: 6592
/* 5119 */    MCD::OPC_Decode, 148, 4, 10, // Opcode: XMULX
/* 5123 */    MCD::OPC_FilterValue, 151, 2, 8, 0, // Skip to: 5136
/* 5128 */    MCD::OPC_CheckPredicate, 1, 180, 5, // Skip to: 6592
/* 5132 */    MCD::OPC_Decode, 149, 4, 10, // Opcode: XMULXHI
/* 5136 */    MCD::OPC_FilterValue, 152, 2, 14, 0, // Skip to: 5155
/* 5141 */    MCD::OPC_CheckPredicate, 1, 167, 5, // Skip to: 6592
/* 5145 */    MCD::OPC_CheckField, 14, 5, 0, 161, 5, // Skip to: 6592
/* 5151 */    MCD::OPC_Decode, 243, 2, 62, // Opcode: MOVXTOD
/* 5155 */    MCD::OPC_FilterValue, 153, 2, 14, 0, // Skip to: 5174
/* 5160 */    MCD::OPC_CheckPredicate, 1, 148, 5, // Skip to: 6592
/* 5164 */    MCD::OPC_CheckField, 14, 5, 0, 142, 5, // Skip to: 6592
/* 5170 */    MCD::OPC_Decode, 240, 2, 62, // Opcode: MOVWTOS
/* 5174 */    MCD::OPC_FilterValue, 209, 2, 8, 0, // Skip to: 5187
/* 5179 */    MCD::OPC_CheckPredicate, 1, 129, 5, // Skip to: 6592
/* 5183 */    MCD::OPC_Decode, 183, 1, 52, // Opcode: FLCMPS
/* 5187 */    MCD::OPC_FilterValue, 210, 2, 120, 5, // Skip to: 6592
/* 5192 */    MCD::OPC_CheckPredicate, 1, 116, 5, // Skip to: 6592
/* 5196 */    MCD::OPC_Decode, 182, 1, 52, // Opcode: FLCMPD
/* 5200 */    MCD::OPC_FilterValue, 56, 25, 0, // Skip to: 5229
/* 5204 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5207 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5221
/* 5211 */    MCD::OPC_CheckField, 5, 8, 0, 95, 5, // Skip to: 6592
/* 5217 */    MCD::OPC_Decode, 178, 2, 63, // Opcode: JMPLrr
/* 5221 */    MCD::OPC_FilterValue, 1, 87, 5, // Skip to: 6592
/* 5225 */    MCD::OPC_Decode, 177, 2, 63, // Opcode: JMPLri
/* 5229 */    MCD::OPC_FilterValue, 57, 37, 0, // Skip to: 5270
/* 5233 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5236 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 5256
/* 5240 */    MCD::OPC_CheckField, 25, 5, 0, 66, 5, // Skip to: 6592
/* 5246 */    MCD::OPC_CheckField, 5, 8, 0, 60, 5, // Skip to: 6592
/* 5252 */    MCD::OPC_Decode, 145, 3, 64, // Opcode: RETTrr
/* 5256 */    MCD::OPC_FilterValue, 1, 52, 5, // Skip to: 6592
/* 5260 */    MCD::OPC_CheckField, 25, 5, 0, 46, 5, // Skip to: 6592
/* 5266 */    MCD::OPC_Decode, 144, 3, 64, // Opcode: RETTri
/* 5270 */    MCD::OPC_FilterValue, 58, 115, 0, // Skip to: 5389
/* 5274 */    MCD::OPC_ExtractField, 8, 6,  // Inst{13-8} ...
/* 5277 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 5297
/* 5281 */    MCD::OPC_CheckField, 29, 1, 0, 25, 5, // Skip to: 6592
/* 5287 */    MCD::OPC_CheckField, 5, 3, 0, 19, 5, // Skip to: 6592
/* 5293 */    MCD::OPC_Decode, 231, 3, 65, // Opcode: TICCrr
/* 5297 */    MCD::OPC_FilterValue, 16, 16, 0, // Skip to: 5317
/* 5301 */    MCD::OPC_CheckField, 29, 1, 0, 5, 5, // Skip to: 6592
/* 5307 */    MCD::OPC_CheckField, 5, 3, 0, 255, 4, // Skip to: 6592
/* 5313 */    MCD::OPC_Decode, 242, 3, 65, // Opcode: TXCCrr
/* 5317 */    MCD::OPC_FilterValue, 32, 54, 0, // Skip to: 5375
/* 5321 */    MCD::OPC_ExtractField, 29, 1,  // Inst{29} ...
/* 5324 */    MCD::OPC_FilterValue, 0, 240, 4, // Skip to: 6592
/* 5328 */    MCD::OPC_ExtractField, 0, 8,  // Inst{7-0} ...
/* 5331 */    MCD::OPC_FilterValue, 3, 16, 0, // Skip to: 5351
/* 5335 */    MCD::OPC_CheckField, 25, 4, 0, 30, 0, // Skip to: 5371
/* 5341 */    MCD::OPC_CheckField, 14, 5, 1, 24, 0, // Skip to: 5371
/* 5347 */    MCD::OPC_Decode, 224, 3, 4, // Opcode: TA3
/* 5351 */    MCD::OPC_FilterValue, 5, 16, 0, // Skip to: 5371
/* 5355 */    MCD::OPC_CheckField, 25, 4, 8, 10, 0, // Skip to: 5371
/* 5361 */    MCD::OPC_CheckField, 14, 5, 0, 4, 0, // Skip to: 5371
/* 5367 */    MCD::OPC_Decode, 225, 3, 4, // Opcode: TA5
/* 5371 */    MCD::OPC_Decode, 230, 3, 66, // Opcode: TICCri
/* 5375 */    MCD::OPC_FilterValue, 48, 189, 4, // Skip to: 6592
/* 5379 */    MCD::OPC_CheckField, 29, 1, 0, 183, 4, // Skip to: 6592
/* 5385 */    MCD::OPC_Decode, 241, 3, 66, // Opcode: TXCCri
/* 5389 */    MCD::OPC_FilterValue, 59, 55, 0, // Skip to: 5448
/* 5393 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5396 */    MCD::OPC_FilterValue, 0, 34, 0, // Skip to: 5434
/* 5400 */    MCD::OPC_ExtractField, 5, 8,  // Inst{12-5} ...
/* 5403 */    MCD::OPC_FilterValue, 0, 161, 4, // Skip to: 6592
/* 5407 */    MCD::OPC_ExtractField, 25, 5,  // Inst{29-25} ...
/* 5410 */    MCD::OPC_FilterValue, 0, 154, 4, // Skip to: 6592
/* 5414 */    MCD::OPC_CheckField, 14, 5, 0, 10, 0, // Skip to: 5430
/* 5420 */    MCD::OPC_CheckField, 0, 5, 0, 4, 0, // Skip to: 5430
/* 5426 */    MCD::OPC_Decode, 184, 1, 4, // Opcode: FLUSH
/* 5430 */    MCD::OPC_Decode, 187, 1, 4, // Opcode: FLUSHrr
/* 5434 */    MCD::OPC_FilterValue, 1, 130, 4, // Skip to: 6592
/* 5438 */    MCD::OPC_CheckField, 25, 5, 0, 124, 4, // Skip to: 6592
/* 5444 */    MCD::OPC_Decode, 186, 1, 4, // Opcode: FLUSHri
/* 5448 */    MCD::OPC_FilterValue, 60, 25, 0, // Skip to: 5477
/* 5452 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5455 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5469
/* 5459 */    MCD::OPC_CheckField, 5, 8, 0, 103, 4, // Skip to: 6592
/* 5465 */    MCD::OPC_Decode, 147, 3, 8, // Opcode: SAVErr
/* 5469 */    MCD::OPC_FilterValue, 1, 95, 4, // Skip to: 6592
/* 5473 */    MCD::OPC_Decode, 146, 3, 9, // Opcode: SAVEri
/* 5477 */    MCD::OPC_FilterValue, 61, 87, 4, // Skip to: 6592
/* 5481 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5484 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5498
/* 5488 */    MCD::OPC_CheckField, 5, 8, 0, 74, 4, // Skip to: 6592
/* 5494 */    MCD::OPC_Decode, 141, 3, 8, // Opcode: RESTORErr
/* 5498 */    MCD::OPC_FilterValue, 1, 66, 4, // Skip to: 6592
/* 5502 */    MCD::OPC_Decode, 140, 3, 9, // Opcode: RESTOREri
/* 5506 */    MCD::OPC_FilterValue, 3, 58, 4, // Skip to: 6592
/* 5510 */    MCD::OPC_ExtractField, 19, 6,  // Inst{24-19} ...
/* 5513 */    MCD::OPC_FilterValue, 0, 25, 0, // Skip to: 5542
/* 5517 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5520 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5534
/* 5524 */    MCD::OPC_CheckField, 5, 8, 0, 38, 4, // Skip to: 6592
/* 5530 */    MCD::OPC_Decode, 216, 2, 67, // Opcode: LDrr
/* 5534 */    MCD::OPC_FilterValue, 1, 30, 4, // Skip to: 6592
/* 5538 */    MCD::OPC_Decode, 215, 2, 67, // Opcode: LDri
/* 5542 */    MCD::OPC_FilterValue, 1, 25, 0, // Skip to: 5571
/* 5546 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5549 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5563
/* 5553 */    MCD::OPC_CheckField, 5, 8, 0, 9, 4, // Skip to: 6592
/* 5559 */    MCD::OPC_Decode, 207, 2, 67, // Opcode: LDUBrr
/* 5563 */    MCD::OPC_FilterValue, 1, 1, 4, // Skip to: 6592
/* 5567 */    MCD::OPC_Decode, 206, 2, 67, // Opcode: LDUBri
/* 5571 */    MCD::OPC_FilterValue, 2, 25, 0, // Skip to: 5600
/* 5575 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5578 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5592
/* 5582 */    MCD::OPC_CheckField, 5, 8, 0, 236, 3, // Skip to: 6592
/* 5588 */    MCD::OPC_Decode, 210, 2, 67, // Opcode: LDUHrr
/* 5592 */    MCD::OPC_FilterValue, 1, 228, 3, // Skip to: 6592
/* 5596 */    MCD::OPC_Decode, 209, 2, 67, // Opcode: LDUHri
/* 5600 */    MCD::OPC_FilterValue, 3, 25, 0, // Skip to: 5629
/* 5604 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5607 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5621
/* 5611 */    MCD::OPC_CheckField, 5, 8, 0, 207, 3, // Skip to: 6592
/* 5617 */    MCD::OPC_Decode, 185, 2, 68, // Opcode: LDDrr
/* 5621 */    MCD::OPC_FilterValue, 1, 199, 3, // Skip to: 6592
/* 5625 */    MCD::OPC_Decode, 184, 2, 68, // Opcode: LDDri
/* 5629 */    MCD::OPC_FilterValue, 4, 25, 0, // Skip to: 5658
/* 5633 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5636 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5650
/* 5640 */    MCD::OPC_CheckField, 5, 8, 0, 178, 3, // Skip to: 6592
/* 5646 */    MCD::OPC_Decode, 210, 3, 69, // Opcode: STrr
/* 5650 */    MCD::OPC_FilterValue, 1, 170, 3, // Skip to: 6592
/* 5654 */    MCD::OPC_Decode, 209, 3, 69, // Opcode: STri
/* 5658 */    MCD::OPC_FilterValue, 5, 25, 0, // Skip to: 5687
/* 5662 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5665 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5679
/* 5669 */    MCD::OPC_CheckField, 5, 8, 0, 149, 3, // Skip to: 6592
/* 5675 */    MCD::OPC_Decode, 187, 3, 69, // Opcode: STBrr
/* 5679 */    MCD::OPC_FilterValue, 1, 141, 3, // Skip to: 6592
/* 5683 */    MCD::OPC_Decode, 186, 3, 69, // Opcode: STBri
/* 5687 */    MCD::OPC_FilterValue, 6, 25, 0, // Skip to: 5716
/* 5691 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5694 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5708
/* 5698 */    MCD::OPC_CheckField, 5, 8, 0, 120, 3, // Skip to: 6592
/* 5704 */    MCD::OPC_Decode, 201, 3, 69, // Opcode: STHrr
/* 5708 */    MCD::OPC_FilterValue, 1, 112, 3, // Skip to: 6592
/* 5712 */    MCD::OPC_Decode, 200, 3, 69, // Opcode: STHri
/* 5716 */    MCD::OPC_FilterValue, 7, 25, 0, // Skip to: 5745
/* 5720 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5723 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5737
/* 5727 */    MCD::OPC_CheckField, 5, 8, 0, 91, 3, // Skip to: 6592
/* 5733 */    MCD::OPC_Decode, 193, 3, 70, // Opcode: STDrr
/* 5737 */    MCD::OPC_FilterValue, 1, 83, 3, // Skip to: 6592
/* 5741 */    MCD::OPC_Decode, 192, 3, 70, // Opcode: STDri
/* 5745 */    MCD::OPC_FilterValue, 8, 25, 0, // Skip to: 5774
/* 5749 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5752 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5766
/* 5756 */    MCD::OPC_CheckField, 5, 8, 0, 62, 3, // Skip to: 6592
/* 5762 */    MCD::OPC_Decode, 204, 2, 67, // Opcode: LDSWrr
/* 5766 */    MCD::OPC_FilterValue, 1, 54, 3, // Skip to: 6592
/* 5770 */    MCD::OPC_Decode, 203, 2, 67, // Opcode: LDSWri
/* 5774 */    MCD::OPC_FilterValue, 9, 25, 0, // Skip to: 5803
/* 5778 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5781 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5795
/* 5785 */    MCD::OPC_CheckField, 5, 8, 0, 33, 3, // Skip to: 6592
/* 5791 */    MCD::OPC_Decode, 196, 2, 67, // Opcode: LDSBrr
/* 5795 */    MCD::OPC_FilterValue, 1, 25, 3, // Skip to: 6592
/* 5799 */    MCD::OPC_Decode, 195, 2, 67, // Opcode: LDSBri
/* 5803 */    MCD::OPC_FilterValue, 10, 25, 0, // Skip to: 5832
/* 5807 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5810 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5824
/* 5814 */    MCD::OPC_CheckField, 5, 8, 0, 4, 3, // Skip to: 6592
/* 5820 */    MCD::OPC_Decode, 199, 2, 67, // Opcode: LDSHrr
/* 5824 */    MCD::OPC_FilterValue, 1, 252, 2, // Skip to: 6592
/* 5828 */    MCD::OPC_Decode, 198, 2, 67, // Opcode: LDSHri
/* 5832 */    MCD::OPC_FilterValue, 11, 25, 0, // Skip to: 5861
/* 5836 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5839 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5853
/* 5843 */    MCD::OPC_CheckField, 5, 8, 0, 231, 2, // Skip to: 6592
/* 5849 */    MCD::OPC_Decode, 214, 2, 67, // Opcode: LDXrr
/* 5853 */    MCD::OPC_FilterValue, 1, 223, 2, // Skip to: 6592
/* 5857 */    MCD::OPC_Decode, 213, 2, 67, // Opcode: LDXri
/* 5861 */    MCD::OPC_FilterValue, 13, 25, 0, // Skip to: 5890
/* 5865 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5868 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5882
/* 5872 */    MCD::OPC_CheckField, 5, 8, 0, 202, 2, // Skip to: 6592
/* 5878 */    MCD::OPC_Decode, 202, 2, 4, // Opcode: LDSTUBrr
/* 5882 */    MCD::OPC_FilterValue, 1, 194, 2, // Skip to: 6592
/* 5886 */    MCD::OPC_Decode, 201, 2, 4, // Opcode: LDSTUBri
/* 5890 */    MCD::OPC_FilterValue, 14, 25, 0, // Skip to: 5919
/* 5894 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5897 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5911
/* 5901 */    MCD::OPC_CheckField, 5, 8, 0, 173, 2, // Skip to: 6592
/* 5907 */    MCD::OPC_Decode, 208, 3, 69, // Opcode: STXrr
/* 5911 */    MCD::OPC_FilterValue, 1, 165, 2, // Skip to: 6592
/* 5915 */    MCD::OPC_Decode, 207, 3, 69, // Opcode: STXri
/* 5919 */    MCD::OPC_FilterValue, 15, 25, 0, // Skip to: 5948
/* 5923 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 5926 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5940
/* 5930 */    MCD::OPC_CheckField, 5, 8, 0, 144, 2, // Skip to: 6592
/* 5936 */    MCD::OPC_Decode, 223, 3, 71, // Opcode: SWAPrr
/* 5940 */    MCD::OPC_FilterValue, 1, 136, 2, // Skip to: 6592
/* 5944 */    MCD::OPC_Decode, 222, 3, 71, // Opcode: SWAPri
/* 5948 */    MCD::OPC_FilterValue, 16, 10, 0, // Skip to: 5962
/* 5952 */    MCD::OPC_CheckField, 13, 1, 0, 122, 2, // Skip to: 6592
/* 5958 */    MCD::OPC_Decode, 179, 2, 67, // Opcode: LDArr
/* 5962 */    MCD::OPC_FilterValue, 17, 10, 0, // Skip to: 5976
/* 5966 */    MCD::OPC_CheckField, 13, 1, 0, 108, 2, // Skip to: 6592
/* 5972 */    MCD::OPC_Decode, 205, 2, 67, // Opcode: LDUBArr
/* 5976 */    MCD::OPC_FilterValue, 18, 10, 0, // Skip to: 5990
/* 5980 */    MCD::OPC_CheckField, 13, 1, 0, 94, 2, // Skip to: 6592
/* 5986 */    MCD::OPC_Decode, 208, 2, 67, // Opcode: LDUHArr
/* 5990 */    MCD::OPC_FilterValue, 19, 10, 0, // Skip to: 6004
/* 5994 */    MCD::OPC_CheckField, 13, 1, 0, 80, 2, // Skip to: 6592
/* 6000 */    MCD::OPC_Decode, 180, 2, 68, // Opcode: LDDArr
/* 6004 */    MCD::OPC_FilterValue, 20, 10, 0, // Skip to: 6018
/* 6008 */    MCD::OPC_CheckField, 13, 1, 0, 66, 2, // Skip to: 6592
/* 6014 */    MCD::OPC_Decode, 183, 3, 69, // Opcode: STArr
/* 6018 */    MCD::OPC_FilterValue, 21, 10, 0, // Skip to: 6032
/* 6022 */    MCD::OPC_CheckField, 13, 1, 0, 52, 2, // Skip to: 6592
/* 6028 */    MCD::OPC_Decode, 185, 3, 69, // Opcode: STBArr
/* 6032 */    MCD::OPC_FilterValue, 22, 10, 0, // Skip to: 6046
/* 6036 */    MCD::OPC_CheckField, 13, 1, 0, 38, 2, // Skip to: 6592
/* 6042 */    MCD::OPC_Decode, 199, 3, 69, // Opcode: STHArr
/* 6046 */    MCD::OPC_FilterValue, 23, 10, 0, // Skip to: 6060
/* 6050 */    MCD::OPC_CheckField, 13, 1, 0, 24, 2, // Skip to: 6592
/* 6056 */    MCD::OPC_Decode, 188, 3, 70, // Opcode: STDArr
/* 6060 */    MCD::OPC_FilterValue, 25, 10, 0, // Skip to: 6074
/* 6064 */    MCD::OPC_CheckField, 13, 1, 0, 10, 2, // Skip to: 6592
/* 6070 */    MCD::OPC_Decode, 194, 2, 67, // Opcode: LDSBArr
/* 6074 */    MCD::OPC_FilterValue, 26, 10, 0, // Skip to: 6088
/* 6078 */    MCD::OPC_CheckField, 13, 1, 0, 252, 1, // Skip to: 6592
/* 6084 */    MCD::OPC_Decode, 197, 2, 67, // Opcode: LDSHArr
/* 6088 */    MCD::OPC_FilterValue, 29, 10, 0, // Skip to: 6102
/* 6092 */    MCD::OPC_CheckField, 13, 1, 0, 238, 1, // Skip to: 6592
/* 6098 */    MCD::OPC_Decode, 200, 2, 72, // Opcode: LDSTUBArr
/* 6102 */    MCD::OPC_FilterValue, 31, 10, 0, // Skip to: 6116
/* 6106 */    MCD::OPC_CheckField, 13, 1, 0, 224, 1, // Skip to: 6592
/* 6112 */    MCD::OPC_Decode, 221, 3, 71, // Opcode: SWAPArr
/* 6116 */    MCD::OPC_FilterValue, 32, 25, 0, // Skip to: 6145
/* 6120 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 6123 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6137
/* 6127 */    MCD::OPC_CheckField, 5, 8, 0, 203, 1, // Skip to: 6592
/* 6133 */    MCD::OPC_Decode, 190, 2, 73, // Opcode: LDFrr
/* 6137 */    MCD::OPC_FilterValue, 1, 195, 1, // Skip to: 6592
/* 6141 */    MCD::OPC_Decode, 189, 2, 73, // Opcode: LDFri
/* 6145 */    MCD::OPC_FilterValue, 33, 69, 0, // Skip to: 6218
/* 6149 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 6152 */    MCD::OPC_FilterValue, 0, 35, 0, // Skip to: 6191
/* 6156 */    MCD::OPC_ExtractField, 25, 5,  // Inst{29-25} ...
/* 6159 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6173
/* 6163 */    MCD::OPC_CheckField, 5, 8, 0, 167, 1, // Skip to: 6592
/* 6169 */    MCD::OPC_Decode, 188, 2, 73, // Opcode: LDFSRrr
/* 6173 */    MCD::OPC_FilterValue, 1, 159, 1, // Skip to: 6592
/* 6177 */    MCD::OPC_CheckPredicate, 0, 155, 1, // Skip to: 6592
/* 6181 */    MCD::OPC_CheckField, 5, 8, 0, 149, 1, // Skip to: 6592
/* 6187 */    MCD::OPC_Decode, 212, 2, 73, // Opcode: LDXFSRrr
/* 6191 */    MCD::OPC_FilterValue, 1, 141, 1, // Skip to: 6592
/* 6195 */    MCD::OPC_ExtractField, 25, 5,  // Inst{29-25} ...
/* 6198 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6206
/* 6202 */    MCD::OPC_Decode, 187, 2, 73, // Opcode: LDFSRri
/* 6206 */    MCD::OPC_FilterValue, 1, 126, 1, // Skip to: 6592
/* 6210 */    MCD::OPC_CheckPredicate, 0, 122, 1, // Skip to: 6592
/* 6214 */    MCD::OPC_Decode, 211, 2, 73, // Opcode: LDXFSRri
/* 6218 */    MCD::OPC_FilterValue, 34, 33, 0, // Skip to: 6255
/* 6222 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 6225 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 6243
/* 6229 */    MCD::OPC_CheckPredicate, 0, 103, 1, // Skip to: 6592
/* 6233 */    MCD::OPC_CheckField, 5, 8, 0, 97, 1, // Skip to: 6592
/* 6239 */    MCD::OPC_Decode, 193, 2, 74, // Opcode: LDQFrr
/* 6243 */    MCD::OPC_FilterValue, 1, 89, 1, // Skip to: 6592
/* 6247 */    MCD::OPC_CheckPredicate, 0, 85, 1, // Skip to: 6592
/* 6251 */    MCD::OPC_Decode, 192, 2, 74, // Opcode: LDQFri
/* 6255 */    MCD::OPC_FilterValue, 35, 25, 0, // Skip to: 6284
/* 6259 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 6262 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6276
/* 6266 */    MCD::OPC_CheckField, 5, 8, 0, 64, 1, // Skip to: 6592
/* 6272 */    MCD::OPC_Decode, 183, 2, 75, // Opcode: LDDFrr
/* 6276 */    MCD::OPC_FilterValue, 1, 56, 1, // Skip to: 6592
/* 6280 */    MCD::OPC_Decode, 182, 2, 75, // Opcode: LDDFri
/* 6284 */    MCD::OPC_FilterValue, 36, 25, 0, // Skip to: 6313
/* 6288 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 6291 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6305
/* 6295 */    MCD::OPC_CheckField, 5, 8, 0, 35, 1, // Skip to: 6592
/* 6301 */    MCD::OPC_Decode, 198, 3, 76, // Opcode: STFrr
/* 6305 */    MCD::OPC_FilterValue, 1, 27, 1, // Skip to: 6592
/* 6309 */    MCD::OPC_Decode, 197, 3, 76, // Opcode: STFri
/* 6313 */    MCD::OPC_FilterValue, 37, 69, 0, // Skip to: 6386
/* 6317 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 6320 */    MCD::OPC_FilterValue, 0, 35, 0, // Skip to: 6359
/* 6324 */    MCD::OPC_ExtractField, 25, 5,  // Inst{29-25} ...
/* 6327 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6341
/* 6331 */    MCD::OPC_CheckField, 5, 8, 0, 255, 0, // Skip to: 6592
/* 6337 */    MCD::OPC_Decode, 196, 3, 76, // Opcode: STFSRrr
/* 6341 */    MCD::OPC_FilterValue, 1, 247, 0, // Skip to: 6592
/* 6345 */    MCD::OPC_CheckPredicate, 0, 243, 0, // Skip to: 6592
/* 6349 */    MCD::OPC_CheckField, 5, 8, 0, 237, 0, // Skip to: 6592
/* 6355 */    MCD::OPC_Decode, 206, 3, 76, // Opcode: STXFSRrr
/* 6359 */    MCD::OPC_FilterValue, 1, 229, 0, // Skip to: 6592
/* 6363 */    MCD::OPC_ExtractField, 25, 5,  // Inst{29-25} ...
/* 6366 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6374
/* 6370 */    MCD::OPC_Decode, 195, 3, 76, // Opcode: STFSRri
/* 6374 */    MCD::OPC_FilterValue, 1, 214, 0, // Skip to: 6592
/* 6378 */    MCD::OPC_CheckPredicate, 0, 210, 0, // Skip to: 6592
/* 6382 */    MCD::OPC_Decode, 205, 3, 76, // Opcode: STXFSRri
/* 6386 */    MCD::OPC_FilterValue, 38, 33, 0, // Skip to: 6423
/* 6390 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 6393 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 6411
/* 6397 */    MCD::OPC_CheckPredicate, 0, 191, 0, // Skip to: 6592
/* 6401 */    MCD::OPC_CheckField, 5, 8, 0, 185, 0, // Skip to: 6592
/* 6407 */    MCD::OPC_Decode, 204, 3, 77, // Opcode: STQFrr
/* 6411 */    MCD::OPC_FilterValue, 1, 177, 0, // Skip to: 6592
/* 6415 */    MCD::OPC_CheckPredicate, 0, 173, 0, // Skip to: 6592
/* 6419 */    MCD::OPC_Decode, 203, 3, 77, // Opcode: STQFri
/* 6423 */    MCD::OPC_FilterValue, 39, 25, 0, // Skip to: 6452
/* 6427 */    MCD::OPC_ExtractField, 13, 1,  // Inst{13} ...
/* 6430 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6444
/* 6434 */    MCD::OPC_CheckField, 5, 8, 0, 152, 0, // Skip to: 6592
/* 6440 */    MCD::OPC_Decode, 191, 3, 78, // Opcode: STDFrr
/* 6444 */    MCD::OPC_FilterValue, 1, 144, 0, // Skip to: 6592
/* 6448 */    MCD::OPC_Decode, 190, 3, 78, // Opcode: STDFri
/* 6452 */    MCD::OPC_FilterValue, 48, 14, 0, // Skip to: 6470
/* 6456 */    MCD::OPC_CheckPredicate, 0, 132, 0, // Skip to: 6592
/* 6460 */    MCD::OPC_CheckField, 13, 1, 0, 126, 0, // Skip to: 6592
/* 6466 */    MCD::OPC_Decode, 186, 2, 73, // Opcode: LDFArr
/* 6470 */    MCD::OPC_FilterValue, 50, 14, 0, // Skip to: 6488
/* 6474 */    MCD::OPC_CheckPredicate, 0, 114, 0, // Skip to: 6592
/* 6478 */    MCD::OPC_CheckField, 13, 1, 0, 108, 0, // Skip to: 6592
/* 6484 */    MCD::OPC_Decode, 191, 2, 74, // Opcode: LDQFArr
/* 6488 */    MCD::OPC_FilterValue, 51, 14, 0, // Skip to: 6506
/* 6492 */    MCD::OPC_CheckPredicate, 0, 96, 0, // Skip to: 6592
/* 6496 */    MCD::OPC_CheckField, 13, 1, 0, 90, 0, // Skip to: 6592
/* 6502 */    MCD::OPC_Decode, 181, 2, 75, // Opcode: LDDFArr
/* 6506 */    MCD::OPC_FilterValue, 52, 14, 0, // Skip to: 6524
/* 6510 */    MCD::OPC_CheckPredicate, 0, 78, 0, // Skip to: 6592
/* 6514 */    MCD::OPC_CheckField, 13, 1, 0, 72, 0, // Skip to: 6592
/* 6520 */    MCD::OPC_Decode, 194, 3, 76, // Opcode: STFArr
/* 6524 */    MCD::OPC_FilterValue, 54, 14, 0, // Skip to: 6542
/* 6528 */    MCD::OPC_CheckPredicate, 0, 60, 0, // Skip to: 6592
/* 6532 */    MCD::OPC_CheckField, 13, 1, 0, 54, 0, // Skip to: 6592
/* 6538 */    MCD::OPC_Decode, 202, 3, 77, // Opcode: STQFArr
/* 6542 */    MCD::OPC_FilterValue, 55, 14, 0, // Skip to: 6560
/* 6546 */    MCD::OPC_CheckPredicate, 0, 42, 0, // Skip to: 6592
/* 6550 */    MCD::OPC_CheckField, 13, 1, 0, 36, 0, // Skip to: 6592
/* 6556 */    MCD::OPC_Decode, 189, 3, 78, // Opcode: STDFArr
/* 6560 */    MCD::OPC_FilterValue, 60, 14, 0, // Skip to: 6578
/* 6564 */    MCD::OPC_CheckPredicate, 0, 24, 0, // Skip to: 6592
/* 6568 */    MCD::OPC_CheckField, 5, 9, 128, 1, 17, 0, // Skip to: 6592
/* 6575 */    MCD::OPC_Decode, 121, 79, // Opcode: CASrr
/* 6578 */    MCD::OPC_FilterValue, 62, 10, 0, // Skip to: 6592
/* 6582 */    MCD::OPC_CheckField, 5, 9, 128, 1, 3, 0, // Skip to: 6592
/* 6589 */    MCD::OPC_Decode, 120, 80, // Opcode: CASXrr
/* 6592 */    MCD::OPC_Fail,
  0
};

static bool checkDecoderPredicate(unsigned Idx, const FeatureBitset& Bits) {
  switch (Idx) {
  default: llvm_unreachable("Invalid index!");
  case 0:
    return (Bits[Sparc::FeatureV9]);
  case 1:
    return (Bits[Sparc::FeatureVIS3]);
  case 2:
    return (Bits[Sparc::FeatureVIS]);
  case 3:
    return (Bits[Sparc::FeatureVIS2]);
  }
}

template<typename InsnType>
static DecodeStatus decodeToMCInst(DecodeStatus S, unsigned Idx, InsnType insn, MCInst &MI,
                                   uint64_t Address, const void *Decoder, bool &DecodeComplete) {
  DecodeComplete = true;
  InsnType tmp;
  switch (Idx) {
  default: llvm_unreachable("Invalid index!");
  case 0:
    tmp = fieldFromInstruction(insn, 0, 22);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 1:
    tmp = fieldFromInstruction(insn, 0, 19);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 25, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 2:
    tmp = fieldFromInstruction(insn, 0, 22);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 25, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 3:
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 14) << 0;
    tmp |= fieldFromInstruction(insn, 20, 2) << 14;
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 4:
    return S;
  case 5:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 22);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 6:
    tmp = fieldFromInstruction(insn, 0, 19);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 25, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 20, 2);
    if (DecodeFCCRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 7:
    tmp = fieldFromInstruction(insn, 0, 30);
    if (DecodeCall(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 8:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 9:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 13);
    if (DecodeSIMM13(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 10:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 11:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 13);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 12:
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 13:
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 13);
    if (DecodeSIMM13(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 14:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 15:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 16:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeASRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 17:
    tmp = fieldFromInstruction(insn, 0, 13);
    if (DecodeSIMM13(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 18:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 19:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodePRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 20:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 21:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeFCCRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 22:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 11);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 23:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeFCCRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 11);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 24:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 25:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 26:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeASRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 27:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeASRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 13);
    if (DecodeSIMM13(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 28:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodePRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 29:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodePRRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 13);
    if (DecodeSIMM13(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 30:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 31:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 32:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 33:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 34:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 35:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 36:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 37:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 38:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 39:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 40:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 41:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 42:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 43:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 44:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 45:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeFCCRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 46:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 47:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeFCCRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 48:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 49:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeFCCRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 50:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 51:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFCCRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 52:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFCCRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 53:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFCCRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeQFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 54:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 55:
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 56:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 57:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 58:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 59:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 60:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 61:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 62:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeDFPRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 63:
    if (DecodeJMPL(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 64:
    if (DecodeReturn(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 65:
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 66:
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 25, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 67:
    if (DecodeLoadInt(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 68:
    if (DecodeLoadIntPair(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 69:
    if (DecodeStoreInt(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 70:
    if (DecodeStoreIntPair(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 71:
    if (DecodeSWAP(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 72:
    tmp = fieldFromInstruction(insn, 5, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 73:
    if (DecodeLoadFP(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 74:
    if (DecodeLoadQFP(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 75:
    if (DecodeLoadDFP(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 76:
    if (DecodeStoreFP(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 77:
    if (DecodeStoreQFP(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 78:
    if (DecodeStoreDFP(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 79:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeIntRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 80:
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 5);
    if (DecodeI64RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
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
