/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*  * PPC Disassembler                                                        *|
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

static const uint8_t DecoderTable32[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 17
/* 7 */       MCD::OPC_CheckField, 1, 10, 128, 2, 64, 43, // Skip to: 11086
/* 14 */      MCD::OPC_Decode, 120, 0, // Opcode: ATTN
/* 17 */      MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 25
/* 21 */      MCD::OPC_Decode, 178, 9, 1, // Opcode: TDI
/* 25 */      MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 33
/* 29 */      MCD::OPC_Decode, 199, 9, 2, // Opcode: TWI
/* 33 */      MCD::OPC_FilterValue, 4, 232, 7, // Skip to: 2061
/* 37 */      MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 40 */      MCD::OPC_FilterValue, 0, 211, 0, // Skip to: 255
/* 44 */      MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 47 */      MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 55
/* 51 */      MCD::OPC_Decode, 210, 9, 3, // Opcode: VADDUBM
/* 55 */      MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 63
/* 59 */      MCD::OPC_Decode, 213, 9, 3, // Opcode: VADDUHM
/* 63 */      MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 71
/* 67 */      MCD::OPC_Decode, 216, 9, 3, // Opcode: VADDUWM
/* 71 */      MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 79
/* 75 */      MCD::OPC_Decode, 212, 9, 3, // Opcode: VADDUDM
/* 79 */      MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 87
/* 83 */      MCD::OPC_Decode, 215, 9, 3, // Opcode: VADDUQM
/* 87 */      MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 95
/* 91 */      MCD::OPC_Decode, 202, 9, 3, // Opcode: VADDCUQ
/* 95 */      MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 103
/* 99 */      MCD::OPC_Decode, 203, 9, 3, // Opcode: VADDCUW
/* 103 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 111
/* 107 */     MCD::OPC_Decode, 211, 9, 3, // Opcode: VADDUBS
/* 111 */     MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 119
/* 115 */     MCD::OPC_Decode, 214, 9, 3, // Opcode: VADDUHS
/* 119 */     MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 127
/* 123 */     MCD::OPC_Decode, 217, 9, 3, // Opcode: VADDUWS
/* 127 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 135
/* 131 */     MCD::OPC_Decode, 207, 9, 3, // Opcode: VADDSBS
/* 135 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 143
/* 139 */     MCD::OPC_Decode, 208, 9, 3, // Opcode: VADDSHS
/* 143 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 151
/* 147 */     MCD::OPC_Decode, 209, 9, 3, // Opcode: VADDSWS
/* 151 */     MCD::OPC_FilterValue, 16, 4, 0, // Skip to: 159
/* 155 */     MCD::OPC_Decode, 145, 11, 3, // Opcode: VSUBUBM
/* 159 */     MCD::OPC_FilterValue, 17, 4, 0, // Skip to: 167
/* 163 */     MCD::OPC_Decode, 148, 11, 3, // Opcode: VSUBUHM
/* 167 */     MCD::OPC_FilterValue, 18, 4, 0, // Skip to: 175
/* 171 */     MCD::OPC_Decode, 151, 11, 3, // Opcode: VSUBUWM
/* 175 */     MCD::OPC_FilterValue, 19, 4, 0, // Skip to: 183
/* 179 */     MCD::OPC_Decode, 147, 11, 3, // Opcode: VSUBUDM
/* 183 */     MCD::OPC_FilterValue, 20, 4, 0, // Skip to: 191
/* 187 */     MCD::OPC_Decode, 150, 11, 3, // Opcode: VSUBUQM
/* 191 */     MCD::OPC_FilterValue, 21, 4, 0, // Skip to: 199
/* 195 */     MCD::OPC_Decode, 137, 11, 3, // Opcode: VSUBCUQ
/* 199 */     MCD::OPC_FilterValue, 22, 4, 0, // Skip to: 207
/* 203 */     MCD::OPC_Decode, 138, 11, 3, // Opcode: VSUBCUW
/* 207 */     MCD::OPC_FilterValue, 24, 4, 0, // Skip to: 215
/* 211 */     MCD::OPC_Decode, 146, 11, 3, // Opcode: VSUBUBS
/* 215 */     MCD::OPC_FilterValue, 25, 4, 0, // Skip to: 223
/* 219 */     MCD::OPC_Decode, 149, 11, 3, // Opcode: VSUBUHS
/* 223 */     MCD::OPC_FilterValue, 26, 4, 0, // Skip to: 231
/* 227 */     MCD::OPC_Decode, 152, 11, 3, // Opcode: VSUBUWS
/* 231 */     MCD::OPC_FilterValue, 28, 4, 0, // Skip to: 239
/* 235 */     MCD::OPC_Decode, 142, 11, 3, // Opcode: VSUBSBS
/* 239 */     MCD::OPC_FilterValue, 29, 4, 0, // Skip to: 247
/* 243 */     MCD::OPC_Decode, 143, 11, 3, // Opcode: VSUBSHS
/* 247 */     MCD::OPC_FilterValue, 30, 83, 42, // Skip to: 11086
/* 251 */     MCD::OPC_Decode, 144, 11, 3, // Opcode: VSUBSWS
/* 255 */     MCD::OPC_FilterValue, 2, 251, 0, // Skip to: 510
/* 259 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 262 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 270
/* 266 */     MCD::OPC_Decode, 155, 10, 3, // Opcode: VMAXUB
/* 270 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 278
/* 274 */     MCD::OPC_Decode, 157, 10, 3, // Opcode: VMAXUH
/* 278 */     MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 286
/* 282 */     MCD::OPC_Decode, 158, 10, 3, // Opcode: VMAXUW
/* 286 */     MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 294
/* 290 */     MCD::OPC_Decode, 156, 10, 3, // Opcode: VMAXUD
/* 294 */     MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 302
/* 298 */     MCD::OPC_Decode, 151, 10, 3, // Opcode: VMAXSB
/* 302 */     MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 310
/* 306 */     MCD::OPC_Decode, 153, 10, 3, // Opcode: VMAXSH
/* 310 */     MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 318
/* 314 */     MCD::OPC_Decode, 154, 10, 3, // Opcode: VMAXSW
/* 318 */     MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 326
/* 322 */     MCD::OPC_Decode, 152, 10, 3, // Opcode: VMAXSD
/* 326 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 334
/* 330 */     MCD::OPC_Decode, 166, 10, 3, // Opcode: VMINUB
/* 334 */     MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 342
/* 338 */     MCD::OPC_Decode, 168, 10, 3, // Opcode: VMINUH
/* 342 */     MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 350
/* 346 */     MCD::OPC_Decode, 169, 10, 3, // Opcode: VMINUW
/* 350 */     MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 358
/* 354 */     MCD::OPC_Decode, 167, 10, 3, // Opcode: VMINUD
/* 358 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 366
/* 362 */     MCD::OPC_Decode, 162, 10, 3, // Opcode: VMINSB
/* 366 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 374
/* 370 */     MCD::OPC_Decode, 164, 10, 3, // Opcode: VMINSH
/* 374 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 382
/* 378 */     MCD::OPC_Decode, 165, 10, 3, // Opcode: VMINSW
/* 382 */     MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 390
/* 386 */     MCD::OPC_Decode, 163, 10, 3, // Opcode: VMINSD
/* 390 */     MCD::OPC_FilterValue, 16, 4, 0, // Skip to: 398
/* 394 */     MCD::OPC_Decode, 223, 9, 3, // Opcode: VAVGUB
/* 398 */     MCD::OPC_FilterValue, 17, 4, 0, // Skip to: 406
/* 402 */     MCD::OPC_Decode, 224, 9, 3, // Opcode: VAVGUH
/* 406 */     MCD::OPC_FilterValue, 18, 4, 0, // Skip to: 414
/* 410 */     MCD::OPC_Decode, 225, 9, 3, // Opcode: VAVGUW
/* 414 */     MCD::OPC_FilterValue, 20, 4, 0, // Skip to: 422
/* 418 */     MCD::OPC_Decode, 220, 9, 3, // Opcode: VAVGSB
/* 422 */     MCD::OPC_FilterValue, 21, 4, 0, // Skip to: 430
/* 426 */     MCD::OPC_Decode, 221, 9, 3, // Opcode: VAVGSH
/* 430 */     MCD::OPC_FilterValue, 22, 4, 0, // Skip to: 438
/* 434 */     MCD::OPC_Decode, 222, 9, 3, // Opcode: VAVGSW
/* 438 */     MCD::OPC_FilterValue, 26, 4, 0, // Skip to: 446
/* 442 */     MCD::OPC_Decode, 241, 10, 4, // Opcode: VSHASIGMAW
/* 446 */     MCD::OPC_FilterValue, 27, 4, 0, // Skip to: 454
/* 450 */     MCD::OPC_Decode, 240, 10, 4, // Opcode: VSHASIGMAD
/* 454 */     MCD::OPC_FilterValue, 28, 10, 0, // Skip to: 468
/* 458 */     MCD::OPC_CheckField, 16, 5, 0, 126, 41, // Skip to: 11086
/* 464 */     MCD::OPC_Decode, 233, 9, 5, // Opcode: VCLZB
/* 468 */     MCD::OPC_FilterValue, 29, 10, 0, // Skip to: 482
/* 472 */     MCD::OPC_CheckField, 16, 5, 0, 112, 41, // Skip to: 11086
/* 478 */     MCD::OPC_Decode, 235, 9, 5, // Opcode: VCLZH
/* 482 */     MCD::OPC_FilterValue, 30, 10, 0, // Skip to: 496
/* 486 */     MCD::OPC_CheckField, 16, 5, 0, 98, 41, // Skip to: 11086
/* 492 */     MCD::OPC_Decode, 236, 9, 5, // Opcode: VCLZW
/* 496 */     MCD::OPC_FilterValue, 31, 90, 41, // Skip to: 11086
/* 500 */     MCD::OPC_CheckField, 16, 5, 0, 84, 41, // Skip to: 11086
/* 506 */     MCD::OPC_Decode, 234, 9, 5, // Opcode: VCLZD
/* 510 */     MCD::OPC_FilterValue, 3, 59, 0, // Skip to: 573
/* 514 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 517 */     MCD::OPC_FilterValue, 28, 10, 0, // Skip to: 531
/* 521 */     MCD::OPC_CheckField, 16, 5, 0, 63, 41, // Skip to: 11086
/* 527 */     MCD::OPC_Decode, 224, 10, 5, // Opcode: VPOPCNTB
/* 531 */     MCD::OPC_FilterValue, 29, 10, 0, // Skip to: 545
/* 535 */     MCD::OPC_CheckField, 16, 5, 0, 49, 41, // Skip to: 11086
/* 541 */     MCD::OPC_Decode, 226, 10, 5, // Opcode: VPOPCNTH
/* 545 */     MCD::OPC_FilterValue, 30, 10, 0, // Skip to: 559
/* 549 */     MCD::OPC_CheckField, 16, 5, 0, 35, 41, // Skip to: 11086
/* 555 */     MCD::OPC_Decode, 227, 10, 5, // Opcode: VPOPCNTW
/* 559 */     MCD::OPC_FilterValue, 31, 27, 41, // Skip to: 11086
/* 563 */     MCD::OPC_CheckField, 16, 5, 0, 21, 41, // Skip to: 11086
/* 569 */     MCD::OPC_Decode, 225, 10, 5, // Opcode: VPOPCNTD
/* 573 */     MCD::OPC_FilterValue, 4, 239, 0, // Skip to: 816
/* 577 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 580 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 588
/* 584 */     MCD::OPC_Decode, 233, 10, 3, // Opcode: VRLB
/* 588 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 596
/* 592 */     MCD::OPC_Decode, 235, 10, 3, // Opcode: VRLH
/* 596 */     MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 604
/* 600 */     MCD::OPC_Decode, 236, 10, 3, // Opcode: VRLW
/* 604 */     MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 612
/* 608 */     MCD::OPC_Decode, 234, 10, 3, // Opcode: VRLD
/* 612 */     MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 620
/* 616 */     MCD::OPC_Decode, 243, 10, 3, // Opcode: VSLB
/* 620 */     MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 628
/* 624 */     MCD::OPC_Decode, 246, 10, 3, // Opcode: VSLH
/* 628 */     MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 636
/* 632 */     MCD::OPC_Decode, 248, 10, 3, // Opcode: VSLW
/* 636 */     MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 644
/* 640 */     MCD::OPC_Decode, 242, 10, 3, // Opcode: VSL
/* 644 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 652
/* 648 */     MCD::OPC_Decode, 132, 11, 3, // Opcode: VSRB
/* 652 */     MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 660
/* 656 */     MCD::OPC_Decode, 134, 11, 3, // Opcode: VSRH
/* 660 */     MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 668
/* 664 */     MCD::OPC_Decode, 136, 11, 3, // Opcode: VSRW
/* 668 */     MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 676
/* 672 */     MCD::OPC_Decode, 255, 10, 3, // Opcode: VSR
/* 676 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 684
/* 680 */     MCD::OPC_Decode, 128, 11, 3, // Opcode: VSRAB
/* 684 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 692
/* 688 */     MCD::OPC_Decode, 130, 11, 3, // Opcode: VSRAH
/* 692 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 700
/* 696 */     MCD::OPC_Decode, 131, 11, 3, // Opcode: VSRAW
/* 700 */     MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 708
/* 704 */     MCD::OPC_Decode, 129, 11, 3, // Opcode: VSRAD
/* 708 */     MCD::OPC_FilterValue, 16, 4, 0, // Skip to: 716
/* 712 */     MCD::OPC_Decode, 218, 9, 3, // Opcode: VAND
/* 716 */     MCD::OPC_FilterValue, 17, 4, 0, // Skip to: 724
/* 720 */     MCD::OPC_Decode, 219, 9, 3, // Opcode: VANDC
/* 724 */     MCD::OPC_FilterValue, 18, 4, 0, // Skip to: 732
/* 728 */     MCD::OPC_Decode, 203, 10, 3, // Opcode: VOR
/* 732 */     MCD::OPC_FilterValue, 19, 4, 0, // Skip to: 740
/* 736 */     MCD::OPC_Decode, 166, 11, 3, // Opcode: VXOR
/* 740 */     MCD::OPC_FilterValue, 20, 4, 0, // Skip to: 748
/* 744 */     MCD::OPC_Decode, 202, 10, 3, // Opcode: VNOR
/* 748 */     MCD::OPC_FilterValue, 21, 4, 0, // Skip to: 756
/* 752 */     MCD::OPC_Decode, 204, 10, 3, // Opcode: VORC
/* 756 */     MCD::OPC_FilterValue, 22, 4, 0, // Skip to: 764
/* 760 */     MCD::OPC_Decode, 198, 10, 3, // Opcode: VNAND
/* 764 */     MCD::OPC_FilterValue, 23, 4, 0, // Skip to: 772
/* 768 */     MCD::OPC_Decode, 244, 10, 3, // Opcode: VSLD
/* 772 */     MCD::OPC_FilterValue, 24, 10, 0, // Skip to: 786
/* 776 */     MCD::OPC_CheckField, 11, 10, 0, 64, 40, // Skip to: 11086
/* 782 */     MCD::OPC_Decode, 230, 5, 6, // Opcode: MFVSCR
/* 786 */     MCD::OPC_FilterValue, 25, 10, 0, // Skip to: 800
/* 790 */     MCD::OPC_CheckField, 16, 10, 0, 50, 40, // Skip to: 11086
/* 796 */     MCD::OPC_Decode, 132, 6, 7, // Opcode: MTVSCR
/* 800 */     MCD::OPC_FilterValue, 26, 4, 0, // Skip to: 808
/* 804 */     MCD::OPC_Decode, 145, 10, 3, // Opcode: VEQV
/* 808 */     MCD::OPC_FilterValue, 27, 34, 40, // Skip to: 11086
/* 812 */     MCD::OPC_Decode, 133, 11, 3, // Opcode: VSRD
/* 816 */     MCD::OPC_FilterValue, 6, 211, 0, // Skip to: 1031
/* 820 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 823 */     MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 831
/* 827 */     MCD::OPC_Decode, 241, 9, 3, // Opcode: VCMPEQUB
/* 831 */     MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 839
/* 835 */     MCD::OPC_Decode, 245, 9, 3, // Opcode: VCMPEQUH
/* 839 */     MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 847
/* 843 */     MCD::OPC_Decode, 247, 9, 3, // Opcode: VCMPEQUW
/* 847 */     MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 855
/* 851 */     MCD::OPC_Decode, 239, 9, 3, // Opcode: VCMPEQFP
/* 855 */     MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 863
/* 859 */     MCD::OPC_Decode, 249, 9, 3, // Opcode: VCMPGEFP
/* 863 */     MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 871
/* 867 */     MCD::OPC_Decode, 133, 10, 3, // Opcode: VCMPGTUB
/* 871 */     MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 879
/* 875 */     MCD::OPC_Decode, 137, 10, 3, // Opcode: VCMPGTUH
/* 879 */     MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 887
/* 883 */     MCD::OPC_Decode, 139, 10, 3, // Opcode: VCMPGTUW
/* 887 */     MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 895
/* 891 */     MCD::OPC_Decode, 251, 9, 3, // Opcode: VCMPGTFP
/* 895 */     MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 903
/* 899 */     MCD::OPC_Decode, 253, 9, 3, // Opcode: VCMPGTSB
/* 903 */     MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 911
/* 907 */     MCD::OPC_Decode, 129, 10, 3, // Opcode: VCMPGTSH
/* 911 */     MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 919
/* 915 */     MCD::OPC_Decode, 131, 10, 3, // Opcode: VCMPGTSW
/* 919 */     MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 927
/* 923 */     MCD::OPC_Decode, 237, 9, 3, // Opcode: VCMPBFP
/* 927 */     MCD::OPC_FilterValue, 16, 4, 0, // Skip to: 935
/* 931 */     MCD::OPC_Decode, 242, 9, 3, // Opcode: VCMPEQUBo
/* 935 */     MCD::OPC_FilterValue, 17, 4, 0, // Skip to: 943
/* 939 */     MCD::OPC_Decode, 246, 9, 3, // Opcode: VCMPEQUHo
/* 943 */     MCD::OPC_FilterValue, 18, 4, 0, // Skip to: 951
/* 947 */     MCD::OPC_Decode, 248, 9, 3, // Opcode: VCMPEQUWo
/* 951 */     MCD::OPC_FilterValue, 19, 4, 0, // Skip to: 959
/* 955 */     MCD::OPC_Decode, 240, 9, 3, // Opcode: VCMPEQFPo
/* 959 */     MCD::OPC_FilterValue, 23, 4, 0, // Skip to: 967
/* 963 */     MCD::OPC_Decode, 250, 9, 3, // Opcode: VCMPGEFPo
/* 967 */     MCD::OPC_FilterValue, 24, 4, 0, // Skip to: 975
/* 971 */     MCD::OPC_Decode, 134, 10, 3, // Opcode: VCMPGTUBo
/* 975 */     MCD::OPC_FilterValue, 25, 4, 0, // Skip to: 983
/* 979 */     MCD::OPC_Decode, 138, 10, 3, // Opcode: VCMPGTUHo
/* 983 */     MCD::OPC_FilterValue, 26, 4, 0, // Skip to: 991
/* 987 */     MCD::OPC_Decode, 140, 10, 3, // Opcode: VCMPGTUWo
/* 991 */     MCD::OPC_FilterValue, 27, 4, 0, // Skip to: 999
/* 995 */     MCD::OPC_Decode, 252, 9, 3, // Opcode: VCMPGTFPo
/* 999 */     MCD::OPC_FilterValue, 28, 4, 0, // Skip to: 1007
/* 1003 */    MCD::OPC_Decode, 254, 9, 3, // Opcode: VCMPGTSBo
/* 1007 */    MCD::OPC_FilterValue, 29, 4, 0, // Skip to: 1015
/* 1011 */    MCD::OPC_Decode, 130, 10, 3, // Opcode: VCMPGTSHo
/* 1015 */    MCD::OPC_FilterValue, 30, 4, 0, // Skip to: 1023
/* 1019 */    MCD::OPC_Decode, 132, 10, 3, // Opcode: VCMPGTSWo
/* 1023 */    MCD::OPC_FilterValue, 31, 75, 39, // Skip to: 11086
/* 1027 */    MCD::OPC_Decode, 238, 9, 3, // Opcode: VCMPBFPo
/* 1031 */    MCD::OPC_FilterValue, 7, 51, 0, // Skip to: 1086
/* 1035 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1038 */    MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 1046
/* 1042 */    MCD::OPC_Decode, 243, 9, 3, // Opcode: VCMPEQUD
/* 1046 */    MCD::OPC_FilterValue, 11, 4, 0, // Skip to: 1054
/* 1050 */    MCD::OPC_Decode, 135, 10, 3, // Opcode: VCMPGTUD
/* 1054 */    MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 1062
/* 1058 */    MCD::OPC_Decode, 255, 9, 3, // Opcode: VCMPGTSD
/* 1062 */    MCD::OPC_FilterValue, 19, 4, 0, // Skip to: 1070
/* 1066 */    MCD::OPC_Decode, 244, 9, 3, // Opcode: VCMPEQUDo
/* 1070 */    MCD::OPC_FilterValue, 27, 4, 0, // Skip to: 1078
/* 1074 */    MCD::OPC_Decode, 136, 10, 3, // Opcode: VCMPGTUDo
/* 1078 */    MCD::OPC_FilterValue, 31, 20, 39, // Skip to: 11086
/* 1082 */    MCD::OPC_Decode, 128, 10, 3, // Opcode: VCMPGTSDo
/* 1086 */    MCD::OPC_FilterValue, 8, 201, 0, // Skip to: 1291
/* 1090 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1093 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 1101
/* 1097 */    MCD::OPC_Decode, 194, 10, 3, // Opcode: VMULOUB
/* 1101 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 1109
/* 1105 */    MCD::OPC_Decode, 195, 10, 3, // Opcode: VMULOUH
/* 1109 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 1117
/* 1113 */    MCD::OPC_Decode, 196, 10, 3, // Opcode: VMULOUW
/* 1117 */    MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 1125
/* 1121 */    MCD::OPC_Decode, 191, 10, 3, // Opcode: VMULOSB
/* 1125 */    MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 1133
/* 1129 */    MCD::OPC_Decode, 192, 10, 3, // Opcode: VMULOSH
/* 1133 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 1141
/* 1137 */    MCD::OPC_Decode, 193, 10, 3, // Opcode: VMULOSW
/* 1141 */    MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 1149
/* 1145 */    MCD::OPC_Decode, 188, 10, 3, // Opcode: VMULEUB
/* 1149 */    MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 1157
/* 1153 */    MCD::OPC_Decode, 189, 10, 3, // Opcode: VMULEUH
/* 1157 */    MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 1165
/* 1161 */    MCD::OPC_Decode, 190, 10, 3, // Opcode: VMULEUW
/* 1165 */    MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 1173
/* 1169 */    MCD::OPC_Decode, 185, 10, 3, // Opcode: VMULESB
/* 1173 */    MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 1181
/* 1177 */    MCD::OPC_Decode, 186, 10, 3, // Opcode: VMULESH
/* 1181 */    MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 1189
/* 1185 */    MCD::OPC_Decode, 187, 10, 3, // Opcode: VMULESW
/* 1189 */    MCD::OPC_FilterValue, 16, 4, 0, // Skip to: 1197
/* 1193 */    MCD::OPC_Decode, 220, 10, 3, // Opcode: VPMSUMB
/* 1197 */    MCD::OPC_FilterValue, 17, 4, 0, // Skip to: 1205
/* 1201 */    MCD::OPC_Decode, 222, 10, 3, // Opcode: VPMSUMH
/* 1205 */    MCD::OPC_FilterValue, 18, 4, 0, // Skip to: 1213
/* 1209 */    MCD::OPC_Decode, 223, 10, 3, // Opcode: VPMSUMW
/* 1213 */    MCD::OPC_FilterValue, 19, 4, 0, // Skip to: 1221
/* 1217 */    MCD::OPC_Decode, 221, 10, 3, // Opcode: VPMSUMD
/* 1221 */    MCD::OPC_FilterValue, 20, 4, 0, // Skip to: 1229
/* 1225 */    MCD::OPC_Decode, 231, 9, 3, // Opcode: VCIPHER
/* 1229 */    MCD::OPC_FilterValue, 21, 4, 0, // Skip to: 1237
/* 1233 */    MCD::OPC_Decode, 199, 10, 3, // Opcode: VNCIPHER
/* 1237 */    MCD::OPC_FilterValue, 23, 10, 0, // Skip to: 1251
/* 1241 */    MCD::OPC_CheckField, 11, 5, 0, 111, 38, // Skip to: 11086
/* 1247 */    MCD::OPC_Decode, 238, 10, 8, // Opcode: VSBOX
/* 1251 */    MCD::OPC_FilterValue, 24, 4, 0, // Skip to: 1259
/* 1255 */    MCD::OPC_Decode, 156, 11, 3, // Opcode: VSUM4UBS
/* 1259 */    MCD::OPC_FilterValue, 25, 4, 0, // Skip to: 1267
/* 1263 */    MCD::OPC_Decode, 155, 11, 3, // Opcode: VSUM4SHS
/* 1267 */    MCD::OPC_FilterValue, 26, 4, 0, // Skip to: 1275
/* 1271 */    MCD::OPC_Decode, 153, 11, 3, // Opcode: VSUM2SWS
/* 1275 */    MCD::OPC_FilterValue, 28, 4, 0, // Skip to: 1283
/* 1279 */    MCD::OPC_Decode, 154, 11, 3, // Opcode: VSUM4SBS
/* 1283 */    MCD::OPC_FilterValue, 30, 71, 38, // Skip to: 11086
/* 1287 */    MCD::OPC_Decode, 157, 11, 3, // Opcode: VSUMSWS
/* 1291 */    MCD::OPC_FilterValue, 9, 27, 0, // Skip to: 1322
/* 1295 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1298 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 1306
/* 1302 */    MCD::OPC_Decode, 197, 10, 3, // Opcode: VMULUWM
/* 1306 */    MCD::OPC_FilterValue, 20, 4, 0, // Skip to: 1314
/* 1310 */    MCD::OPC_Decode, 232, 9, 3, // Opcode: VCIPHERLAST
/* 1314 */    MCD::OPC_FilterValue, 21, 40, 38, // Skip to: 11086
/* 1318 */    MCD::OPC_Decode, 200, 10, 3, // Opcode: VNCIPHERLAST
/* 1322 */    MCD::OPC_FilterValue, 10, 179, 0, // Skip to: 1505
/* 1326 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1329 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 1337
/* 1333 */    MCD::OPC_Decode, 206, 9, 3, // Opcode: VADDFP
/* 1337 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 1345
/* 1341 */    MCD::OPC_Decode, 141, 11, 3, // Opcode: VSUBFP
/* 1345 */    MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 1359
/* 1349 */    MCD::OPC_CheckField, 16, 5, 0, 3, 38, // Skip to: 11086
/* 1355 */    MCD::OPC_Decode, 228, 10, 5, // Opcode: VREFP
/* 1359 */    MCD::OPC_FilterValue, 5, 10, 0, // Skip to: 1373
/* 1363 */    MCD::OPC_CheckField, 16, 5, 0, 245, 37, // Skip to: 11086
/* 1369 */    MCD::OPC_Decode, 237, 10, 5, // Opcode: VRSQRTEFP
/* 1373 */    MCD::OPC_FilterValue, 6, 10, 0, // Skip to: 1387
/* 1377 */    MCD::OPC_CheckField, 16, 5, 0, 231, 37, // Skip to: 11086
/* 1383 */    MCD::OPC_Decode, 146, 10, 5, // Opcode: VEXPTEFP
/* 1387 */    MCD::OPC_FilterValue, 7, 10, 0, // Skip to: 1401
/* 1391 */    MCD::OPC_CheckField, 16, 5, 0, 217, 37, // Skip to: 11086
/* 1397 */    MCD::OPC_Decode, 148, 10, 5, // Opcode: VLOGEFP
/* 1401 */    MCD::OPC_FilterValue, 8, 10, 0, // Skip to: 1415
/* 1405 */    MCD::OPC_CheckField, 16, 5, 0, 203, 37, // Skip to: 11086
/* 1411 */    MCD::OPC_Decode, 230, 10, 5, // Opcode: VRFIN
/* 1415 */    MCD::OPC_FilterValue, 9, 10, 0, // Skip to: 1429
/* 1419 */    MCD::OPC_CheckField, 16, 5, 0, 189, 37, // Skip to: 11086
/* 1425 */    MCD::OPC_Decode, 232, 10, 5, // Opcode: VRFIZ
/* 1429 */    MCD::OPC_FilterValue, 10, 10, 0, // Skip to: 1443
/* 1433 */    MCD::OPC_CheckField, 16, 5, 0, 175, 37, // Skip to: 11086
/* 1439 */    MCD::OPC_Decode, 231, 10, 5, // Opcode: VRFIP
/* 1443 */    MCD::OPC_FilterValue, 11, 10, 0, // Skip to: 1457
/* 1447 */    MCD::OPC_CheckField, 16, 5, 0, 161, 37, // Skip to: 11086
/* 1453 */    MCD::OPC_Decode, 229, 10, 5, // Opcode: VRFIM
/* 1457 */    MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 1465
/* 1461 */    MCD::OPC_Decode, 229, 9, 9, // Opcode: VCFUX
/* 1465 */    MCD::OPC_FilterValue, 13, 4, 0, // Skip to: 1473
/* 1469 */    MCD::OPC_Decode, 227, 9, 9, // Opcode: VCFSX
/* 1473 */    MCD::OPC_FilterValue, 14, 4, 0, // Skip to: 1481
/* 1477 */    MCD::OPC_Decode, 143, 10, 9, // Opcode: VCTUXS
/* 1481 */    MCD::OPC_FilterValue, 15, 4, 0, // Skip to: 1489
/* 1485 */    MCD::OPC_Decode, 141, 10, 9, // Opcode: VCTSXS
/* 1489 */    MCD::OPC_FilterValue, 16, 4, 0, // Skip to: 1497
/* 1493 */    MCD::OPC_Decode, 150, 10, 3, // Opcode: VMAXFP
/* 1497 */    MCD::OPC_FilterValue, 17, 113, 37, // Skip to: 11086
/* 1501 */    MCD::OPC_Decode, 161, 10, 3, // Opcode: VMINFP
/* 1505 */    MCD::OPC_FilterValue, 12, 171, 0, // Skip to: 1680
/* 1509 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1512 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 1520
/* 1516 */    MCD::OPC_Decode, 172, 10, 3, // Opcode: VMRGHB
/* 1520 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 1528
/* 1524 */    MCD::OPC_Decode, 173, 10, 3, // Opcode: VMRGHH
/* 1528 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 1536
/* 1532 */    MCD::OPC_Decode, 174, 10, 3, // Opcode: VMRGHW
/* 1536 */    MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 1544
/* 1540 */    MCD::OPC_Decode, 175, 10, 3, // Opcode: VMRGLB
/* 1544 */    MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 1552
/* 1548 */    MCD::OPC_Decode, 176, 10, 3, // Opcode: VMRGLH
/* 1552 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 1560
/* 1556 */    MCD::OPC_Decode, 177, 10, 3, // Opcode: VMRGLW
/* 1560 */    MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 1568
/* 1564 */    MCD::OPC_Decode, 249, 10, 9, // Opcode: VSPLTB
/* 1568 */    MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 1576
/* 1572 */    MCD::OPC_Decode, 250, 10, 9, // Opcode: VSPLTH
/* 1576 */    MCD::OPC_FilterValue, 10, 4, 0, // Skip to: 1584
/* 1580 */    MCD::OPC_Decode, 254, 10, 9, // Opcode: VSPLTW
/* 1584 */    MCD::OPC_FilterValue, 12, 10, 0, // Skip to: 1598
/* 1588 */    MCD::OPC_CheckField, 11, 5, 0, 20, 37, // Skip to: 11086
/* 1594 */    MCD::OPC_Decode, 251, 10, 10, // Opcode: VSPLTISB
/* 1598 */    MCD::OPC_FilterValue, 13, 10, 0, // Skip to: 1612
/* 1602 */    MCD::OPC_CheckField, 11, 5, 0, 6, 37, // Skip to: 11086
/* 1608 */    MCD::OPC_Decode, 252, 10, 10, // Opcode: VSPLTISH
/* 1612 */    MCD::OPC_FilterValue, 14, 10, 0, // Skip to: 1626
/* 1616 */    MCD::OPC_CheckField, 11, 5, 0, 248, 36, // Skip to: 11086
/* 1622 */    MCD::OPC_Decode, 253, 10, 10, // Opcode: VSPLTISW
/* 1626 */    MCD::OPC_FilterValue, 16, 4, 0, // Skip to: 1634
/* 1630 */    MCD::OPC_Decode, 247, 10, 3, // Opcode: VSLO
/* 1634 */    MCD::OPC_FilterValue, 17, 4, 0, // Skip to: 1642
/* 1638 */    MCD::OPC_Decode, 135, 11, 3, // Opcode: VSRO
/* 1642 */    MCD::OPC_FilterValue, 20, 10, 0, // Skip to: 1656
/* 1646 */    MCD::OPC_CheckField, 16, 5, 0, 218, 36, // Skip to: 11086
/* 1652 */    MCD::OPC_Decode, 147, 10, 5, // Opcode: VGBBD
/* 1656 */    MCD::OPC_FilterValue, 21, 4, 0, // Skip to: 1664
/* 1660 */    MCD::OPC_Decode, 226, 9, 3, // Opcode: VBPERMQ
/* 1664 */    MCD::OPC_FilterValue, 26, 4, 0, // Skip to: 1672
/* 1668 */    MCD::OPC_Decode, 178, 10, 3, // Opcode: VMRGOW
/* 1672 */    MCD::OPC_FilterValue, 30, 194, 36, // Skip to: 11086
/* 1676 */    MCD::OPC_Decode, 171, 10, 3, // Opcode: VMRGEW
/* 1680 */    MCD::OPC_FilterValue, 14, 219, 0, // Skip to: 1903
/* 1684 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1687 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 1695
/* 1691 */    MCD::OPC_Decode, 216, 10, 3, // Opcode: VPKUHUM
/* 1695 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 1703
/* 1699 */    MCD::OPC_Decode, 218, 10, 3, // Opcode: VPKUWUM
/* 1703 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 1711
/* 1707 */    MCD::OPC_Decode, 217, 10, 3, // Opcode: VPKUHUS
/* 1711 */    MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 1719
/* 1715 */    MCD::OPC_Decode, 219, 10, 3, // Opcode: VPKUWUS
/* 1719 */    MCD::OPC_FilterValue, 4, 4, 0, // Skip to: 1727
/* 1723 */    MCD::OPC_Decode, 211, 10, 3, // Opcode: VPKSHUS
/* 1727 */    MCD::OPC_FilterValue, 5, 4, 0, // Skip to: 1735
/* 1731 */    MCD::OPC_Decode, 213, 10, 3, // Opcode: VPKSWUS
/* 1735 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 1743
/* 1739 */    MCD::OPC_Decode, 210, 10, 3, // Opcode: VPKSHSS
/* 1743 */    MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 1751
/* 1747 */    MCD::OPC_Decode, 212, 10, 3, // Opcode: VPKSWSS
/* 1751 */    MCD::OPC_FilterValue, 8, 10, 0, // Skip to: 1765
/* 1755 */    MCD::OPC_CheckField, 16, 5, 0, 109, 36, // Skip to: 11086
/* 1761 */    MCD::OPC_Decode, 159, 11, 5, // Opcode: VUPKHSB
/* 1765 */    MCD::OPC_FilterValue, 9, 10, 0, // Skip to: 1779
/* 1769 */    MCD::OPC_CheckField, 16, 5, 0, 95, 36, // Skip to: 11086
/* 1775 */    MCD::OPC_Decode, 160, 11, 5, // Opcode: VUPKHSH
/* 1779 */    MCD::OPC_FilterValue, 10, 10, 0, // Skip to: 1793
/* 1783 */    MCD::OPC_CheckField, 16, 5, 0, 81, 36, // Skip to: 11086
/* 1789 */    MCD::OPC_Decode, 163, 11, 5, // Opcode: VUPKLSB
/* 1793 */    MCD::OPC_FilterValue, 11, 10, 0, // Skip to: 1807
/* 1797 */    MCD::OPC_CheckField, 16, 5, 0, 67, 36, // Skip to: 11086
/* 1803 */    MCD::OPC_Decode, 164, 11, 5, // Opcode: VUPKLSH
/* 1807 */    MCD::OPC_FilterValue, 12, 4, 0, // Skip to: 1815
/* 1811 */    MCD::OPC_Decode, 207, 10, 3, // Opcode: VPKPX
/* 1815 */    MCD::OPC_FilterValue, 13, 10, 0, // Skip to: 1829
/* 1819 */    MCD::OPC_CheckField, 16, 5, 0, 45, 36, // Skip to: 11086
/* 1825 */    MCD::OPC_Decode, 158, 11, 5, // Opcode: VUPKHPX
/* 1829 */    MCD::OPC_FilterValue, 15, 10, 0, // Skip to: 1843
/* 1833 */    MCD::OPC_CheckField, 16, 5, 0, 31, 36, // Skip to: 11086
/* 1839 */    MCD::OPC_Decode, 162, 11, 5, // Opcode: VUPKLPX
/* 1843 */    MCD::OPC_FilterValue, 17, 4, 0, // Skip to: 1851
/* 1847 */    MCD::OPC_Decode, 214, 10, 3, // Opcode: VPKUDUM
/* 1851 */    MCD::OPC_FilterValue, 19, 4, 0, // Skip to: 1859
/* 1855 */    MCD::OPC_Decode, 215, 10, 3, // Opcode: VPKUDUS
/* 1859 */    MCD::OPC_FilterValue, 21, 4, 0, // Skip to: 1867
/* 1863 */    MCD::OPC_Decode, 209, 10, 3, // Opcode: VPKSDUS
/* 1867 */    MCD::OPC_FilterValue, 23, 4, 0, // Skip to: 1875
/* 1871 */    MCD::OPC_Decode, 208, 10, 3, // Opcode: VPKSDSS
/* 1875 */    MCD::OPC_FilterValue, 25, 10, 0, // Skip to: 1889
/* 1879 */    MCD::OPC_CheckField, 16, 5, 0, 241, 35, // Skip to: 11086
/* 1885 */    MCD::OPC_Decode, 161, 11, 5, // Opcode: VUPKHSW
/* 1889 */    MCD::OPC_FilterValue, 27, 233, 35, // Skip to: 11086
/* 1893 */    MCD::OPC_CheckField, 16, 5, 0, 227, 35, // Skip to: 11086
/* 1899 */    MCD::OPC_Decode, 165, 11, 5, // Opcode: VUPKLSW
/* 1903 */    MCD::OPC_FilterValue, 32, 4, 0, // Skip to: 1911
/* 1907 */    MCD::OPC_Decode, 159, 10, 11, // Opcode: VMHADDSHS
/* 1911 */    MCD::OPC_FilterValue, 33, 4, 0, // Skip to: 1919
/* 1915 */    MCD::OPC_Decode, 160, 10, 11, // Opcode: VMHRADDSHS
/* 1919 */    MCD::OPC_FilterValue, 34, 4, 0, // Skip to: 1927
/* 1923 */    MCD::OPC_Decode, 170, 10, 11, // Opcode: VMLADDUHM
/* 1927 */    MCD::OPC_FilterValue, 36, 4, 0, // Skip to: 1935
/* 1931 */    MCD::OPC_Decode, 182, 10, 11, // Opcode: VMSUMUBM
/* 1935 */    MCD::OPC_FilterValue, 37, 4, 0, // Skip to: 1943
/* 1939 */    MCD::OPC_Decode, 179, 10, 11, // Opcode: VMSUMMBM
/* 1943 */    MCD::OPC_FilterValue, 38, 4, 0, // Skip to: 1951
/* 1947 */    MCD::OPC_Decode, 183, 10, 11, // Opcode: VMSUMUHM
/* 1951 */    MCD::OPC_FilterValue, 39, 4, 0, // Skip to: 1959
/* 1955 */    MCD::OPC_Decode, 184, 10, 11, // Opcode: VMSUMUHS
/* 1959 */    MCD::OPC_FilterValue, 40, 4, 0, // Skip to: 1967
/* 1963 */    MCD::OPC_Decode, 180, 10, 11, // Opcode: VMSUMSHM
/* 1967 */    MCD::OPC_FilterValue, 41, 4, 0, // Skip to: 1975
/* 1971 */    MCD::OPC_Decode, 181, 10, 11, // Opcode: VMSUMSHS
/* 1975 */    MCD::OPC_FilterValue, 42, 4, 0, // Skip to: 1983
/* 1979 */    MCD::OPC_Decode, 239, 10, 11, // Opcode: VSEL
/* 1983 */    MCD::OPC_FilterValue, 43, 4, 0, // Skip to: 1991
/* 1987 */    MCD::OPC_Decode, 205, 10, 11, // Opcode: VPERM
/* 1991 */    MCD::OPC_FilterValue, 44, 10, 0, // Skip to: 2005
/* 1995 */    MCD::OPC_CheckField, 10, 1, 0, 125, 35, // Skip to: 11086
/* 2001 */    MCD::OPC_Decode, 245, 10, 12, // Opcode: VSLDOI
/* 2005 */    MCD::OPC_FilterValue, 45, 4, 0, // Skip to: 2013
/* 2009 */    MCD::OPC_Decode, 206, 10, 11, // Opcode: VPERMXOR
/* 2013 */    MCD::OPC_FilterValue, 46, 4, 0, // Skip to: 2021
/* 2017 */    MCD::OPC_Decode, 149, 10, 13, // Opcode: VMADDFP
/* 2021 */    MCD::OPC_FilterValue, 47, 4, 0, // Skip to: 2029
/* 2025 */    MCD::OPC_Decode, 201, 10, 13, // Opcode: VNMSUBFP
/* 2029 */    MCD::OPC_FilterValue, 60, 4, 0, // Skip to: 2037
/* 2033 */    MCD::OPC_Decode, 205, 9, 11, // Opcode: VADDEUQM
/* 2037 */    MCD::OPC_FilterValue, 61, 4, 0, // Skip to: 2045
/* 2041 */    MCD::OPC_Decode, 204, 9, 11, // Opcode: VADDECUQ
/* 2045 */    MCD::OPC_FilterValue, 62, 4, 0, // Skip to: 2053
/* 2049 */    MCD::OPC_Decode, 140, 11, 11, // Opcode: VSUBEUQM
/* 2053 */    MCD::OPC_FilterValue, 63, 69, 35, // Skip to: 11086
/* 2057 */    MCD::OPC_Decode, 139, 11, 11, // Opcode: VSUBECUQ
/* 2061 */    MCD::OPC_FilterValue, 7, 4, 0, // Skip to: 2069
/* 2065 */    MCD::OPC_Decode, 146, 6, 14, // Opcode: MULLI
/* 2069 */    MCD::OPC_FilterValue, 8, 4, 0, // Skip to: 2077
/* 2073 */    MCD::OPC_Decode, 141, 9, 14, // Opcode: SUBFIC
/* 2077 */    MCD::OPC_FilterValue, 10, 19, 0, // Skip to: 2100
/* 2081 */    MCD::OPC_ExtractField, 21, 2,  // Inst{22-21} ...
/* 2084 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 2092
/* 2088 */    MCD::OPC_Decode, 226, 1, 15, // Opcode: CMPLWI
/* 2092 */    MCD::OPC_FilterValue, 1, 30, 35, // Skip to: 11086
/* 2096 */    MCD::OPC_Decode, 224, 1, 16, // Opcode: CMPLDI
/* 2100 */    MCD::OPC_FilterValue, 11, 19, 0, // Skip to: 2123
/* 2104 */    MCD::OPC_ExtractField, 21, 2,  // Inst{22-21} ...
/* 2107 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 2115
/* 2111 */    MCD::OPC_Decode, 228, 1, 17, // Opcode: CMPWI
/* 2115 */    MCD::OPC_FilterValue, 1, 7, 35, // Skip to: 11086
/* 2119 */    MCD::OPC_Decode, 222, 1, 18, // Opcode: CMPDI
/* 2123 */    MCD::OPC_FilterValue, 12, 3, 0, // Skip to: 2130
/* 2127 */    MCD::OPC_Decode, 40, 14, // Opcode: ADDIC
/* 2130 */    MCD::OPC_FilterValue, 13, 3, 0, // Skip to: 2137
/* 2134 */    MCD::OPC_Decode, 42, 14, // Opcode: ADDICo
/* 2137 */    MCD::OPC_FilterValue, 14, 13, 0, // Skip to: 2154
/* 2141 */    MCD::OPC_CheckField, 16, 5, 0, 4, 0, // Skip to: 2151
/* 2147 */    MCD::OPC_Decode, 167, 5, 19, // Opcode: LI
/* 2151 */    MCD::OPC_Decode, 38, 20, // Opcode: ADDI
/* 2154 */    MCD::OPC_FilterValue, 15, 13, 0, // Skip to: 2171
/* 2158 */    MCD::OPC_CheckField, 16, 5, 0, 4, 0, // Skip to: 2168
/* 2164 */    MCD::OPC_Decode, 169, 5, 19, // Opcode: LIS
/* 2168 */    MCD::OPC_Decode, 43, 20, // Opcode: ADDIS
/* 2171 */    MCD::OPC_FilterValue, 16, 7, 1, // Skip to: 2438
/* 2175 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 2178 */    MCD::OPC_FilterValue, 0, 61, 0, // Skip to: 2243
/* 2182 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 2185 */    MCD::OPC_FilterValue, 128, 4, 4, 0, // Skip to: 2194
/* 2190 */    MCD::OPC_Decode, 155, 1, 21, // Opcode: BDNZ
/* 2194 */    MCD::OPC_FilterValue, 192, 4, 4, 0, // Skip to: 2203
/* 2199 */    MCD::OPC_Decode, 175, 1, 21, // Opcode: BDZ
/* 2203 */    MCD::OPC_FilterValue, 128, 6, 4, 0, // Skip to: 2212
/* 2208 */    MCD::OPC_Decode, 173, 1, 21, // Opcode: BDNZm
/* 2212 */    MCD::OPC_FilterValue, 160, 6, 4, 0, // Skip to: 2221
/* 2217 */    MCD::OPC_Decode, 174, 1, 21, // Opcode: BDNZp
/* 2221 */    MCD::OPC_FilterValue, 192, 6, 4, 0, // Skip to: 2230
/* 2226 */    MCD::OPC_Decode, 193, 1, 21, // Opcode: BDZm
/* 2230 */    MCD::OPC_FilterValue, 224, 6, 4, 0, // Skip to: 2239
/* 2235 */    MCD::OPC_Decode, 194, 1, 21, // Opcode: BDZp
/* 2239 */    MCD::OPC_Decode, 214, 12, 22, // Opcode: gBC
/* 2243 */    MCD::OPC_FilterValue, 1, 61, 0, // Skip to: 2308
/* 2247 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 2250 */    MCD::OPC_FilterValue, 128, 4, 4, 0, // Skip to: 2259
/* 2255 */    MCD::OPC_Decode, 160, 1, 21, // Opcode: BDNZL
/* 2259 */    MCD::OPC_FilterValue, 192, 4, 4, 0, // Skip to: 2268
/* 2264 */    MCD::OPC_Decode, 180, 1, 21, // Opcode: BDZL
/* 2268 */    MCD::OPC_FilterValue, 128, 6, 4, 0, // Skip to: 2277
/* 2273 */    MCD::OPC_Decode, 171, 1, 21, // Opcode: BDNZLm
/* 2277 */    MCD::OPC_FilterValue, 160, 6, 4, 0, // Skip to: 2286
/* 2282 */    MCD::OPC_Decode, 172, 1, 21, // Opcode: BDNZLp
/* 2286 */    MCD::OPC_FilterValue, 192, 6, 4, 0, // Skip to: 2295
/* 2291 */    MCD::OPC_Decode, 191, 1, 21, // Opcode: BDZLm
/* 2295 */    MCD::OPC_FilterValue, 224, 6, 4, 0, // Skip to: 2304
/* 2300 */    MCD::OPC_Decode, 192, 1, 21, // Opcode: BDZLp
/* 2304 */    MCD::OPC_Decode, 218, 12, 22, // Opcode: gBCL
/* 2308 */    MCD::OPC_FilterValue, 2, 61, 0, // Skip to: 2373
/* 2312 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 2315 */    MCD::OPC_FilterValue, 128, 4, 4, 0, // Skip to: 2324
/* 2320 */    MCD::OPC_Decode, 157, 1, 21, // Opcode: BDNZA
/* 2324 */    MCD::OPC_FilterValue, 192, 4, 4, 0, // Skip to: 2333
/* 2329 */    MCD::OPC_Decode, 177, 1, 21, // Opcode: BDZA
/* 2333 */    MCD::OPC_FilterValue, 128, 6, 4, 0, // Skip to: 2342
/* 2338 */    MCD::OPC_Decode, 158, 1, 21, // Opcode: BDNZAm
/* 2342 */    MCD::OPC_FilterValue, 160, 6, 4, 0, // Skip to: 2351
/* 2347 */    MCD::OPC_Decode, 159, 1, 21, // Opcode: BDNZAp
/* 2351 */    MCD::OPC_FilterValue, 192, 6, 4, 0, // Skip to: 2360
/* 2356 */    MCD::OPC_Decode, 178, 1, 21, // Opcode: BDZAm
/* 2360 */    MCD::OPC_FilterValue, 224, 6, 4, 0, // Skip to: 2369
/* 2365 */    MCD::OPC_Decode, 179, 1, 21, // Opcode: BDZAp
/* 2369 */    MCD::OPC_Decode, 215, 12, 22, // Opcode: gBCA
/* 2373 */    MCD::OPC_FilterValue, 3, 5, 34, // Skip to: 11086
/* 2377 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 2380 */    MCD::OPC_FilterValue, 128, 4, 4, 0, // Skip to: 2389
/* 2385 */    MCD::OPC_Decode, 161, 1, 21, // Opcode: BDNZLA
/* 2389 */    MCD::OPC_FilterValue, 192, 4, 4, 0, // Skip to: 2398
/* 2394 */    MCD::OPC_Decode, 181, 1, 21, // Opcode: BDZLA
/* 2398 */    MCD::OPC_FilterValue, 128, 6, 4, 0, // Skip to: 2407
/* 2403 */    MCD::OPC_Decode, 162, 1, 21, // Opcode: BDNZLAm
/* 2407 */    MCD::OPC_FilterValue, 160, 6, 4, 0, // Skip to: 2416
/* 2412 */    MCD::OPC_Decode, 163, 1, 21, // Opcode: BDNZLAp
/* 2416 */    MCD::OPC_FilterValue, 192, 6, 4, 0, // Skip to: 2425
/* 2421 */    MCD::OPC_Decode, 182, 1, 21, // Opcode: BDZLAm
/* 2425 */    MCD::OPC_FilterValue, 224, 6, 4, 0, // Skip to: 2434
/* 2430 */    MCD::OPC_Decode, 183, 1, 21, // Opcode: BDZLAp
/* 2434 */    MCD::OPC_Decode, 219, 12, 22, // Opcode: gBCLA
/* 2438 */    MCD::OPC_FilterValue, 17, 10, 0, // Skip to: 2452
/* 2442 */    MCD::OPC_CheckField, 1, 1, 1, 190, 33, // Skip to: 11086
/* 2448 */    MCD::OPC_Decode, 140, 8, 23, // Opcode: SC
/* 2452 */    MCD::OPC_FilterValue, 18, 33, 0, // Skip to: 2489
/* 2456 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 2459 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 2466
/* 2463 */    MCD::OPC_Decode, 121, 24, // Opcode: B
/* 2466 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 2474
/* 2470 */    MCD::OPC_Decode, 195, 1, 24, // Opcode: BL
/* 2474 */    MCD::OPC_FilterValue, 2, 3, 0, // Skip to: 2481
/* 2478 */    MCD::OPC_Decode, 122, 24, // Opcode: BA
/* 2481 */    MCD::OPC_FilterValue, 3, 153, 33, // Skip to: 11086
/* 2485 */    MCD::OPC_Decode, 201, 1, 24, // Opcode: BLA
/* 2489 */    MCD::OPC_FilterValue, 19, 250, 1, // Skip to: 2999
/* 2493 */    MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 2496 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 2516
/* 2500 */    MCD::OPC_CheckField, 21, 2, 0, 132, 33, // Skip to: 11086
/* 2506 */    MCD::OPC_CheckField, 11, 7, 0, 126, 33, // Skip to: 11086
/* 2512 */    MCD::OPC_Decode, 207, 5, 25, // Opcode: MCRF
/* 2516 */    MCD::OPC_FilterValue, 32, 119, 0, // Skip to: 2639
/* 2520 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 2523 */    MCD::OPC_FilterValue, 0, 111, 33, // Skip to: 11086
/* 2527 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 2530 */    MCD::OPC_FilterValue, 128, 4, 10, 0, // Skip to: 2545
/* 2535 */    MCD::OPC_CheckField, 11, 2, 0, 94, 0, // Skip to: 2635
/* 2541 */    MCD::OPC_Decode, 164, 1, 0, // Opcode: BDNZLR
/* 2545 */    MCD::OPC_FilterValue, 192, 4, 10, 0, // Skip to: 2560
/* 2550 */    MCD::OPC_CheckField, 11, 2, 0, 79, 0, // Skip to: 2635
/* 2556 */    MCD::OPC_Decode, 184, 1, 0, // Opcode: BDZLR
/* 2560 */    MCD::OPC_FilterValue, 128, 5, 10, 0, // Skip to: 2575
/* 2565 */    MCD::OPC_CheckField, 11, 2, 0, 64, 0, // Skip to: 2635
/* 2571 */    MCD::OPC_Decode, 204, 1, 0, // Opcode: BLR
/* 2575 */    MCD::OPC_FilterValue, 128, 6, 10, 0, // Skip to: 2590
/* 2580 */    MCD::OPC_CheckField, 11, 2, 0, 49, 0, // Skip to: 2635
/* 2586 */    MCD::OPC_Decode, 169, 1, 0, // Opcode: BDNZLRm
/* 2590 */    MCD::OPC_FilterValue, 160, 6, 10, 0, // Skip to: 2605
/* 2595 */    MCD::OPC_CheckField, 11, 2, 0, 34, 0, // Skip to: 2635
/* 2601 */    MCD::OPC_Decode, 170, 1, 0, // Opcode: BDNZLRp
/* 2605 */    MCD::OPC_FilterValue, 192, 6, 10, 0, // Skip to: 2620
/* 2610 */    MCD::OPC_CheckField, 11, 2, 0, 19, 0, // Skip to: 2635
/* 2616 */    MCD::OPC_Decode, 189, 1, 0, // Opcode: BDZLRm
/* 2620 */    MCD::OPC_FilterValue, 224, 6, 10, 0, // Skip to: 2635
/* 2625 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 2635
/* 2631 */    MCD::OPC_Decode, 190, 1, 0, // Opcode: BDZLRp
/* 2635 */    MCD::OPC_Decode, 220, 12, 26, // Opcode: gBCLR
/* 2639 */    MCD::OPC_FilterValue, 33, 119, 0, // Skip to: 2762
/* 2643 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 2646 */    MCD::OPC_FilterValue, 0, 244, 32, // Skip to: 11086
/* 2650 */    MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 2653 */    MCD::OPC_FilterValue, 128, 4, 10, 0, // Skip to: 2668
/* 2658 */    MCD::OPC_CheckField, 11, 2, 0, 94, 0, // Skip to: 2758
/* 2664 */    MCD::OPC_Decode, 166, 1, 0, // Opcode: BDNZLRL
/* 2668 */    MCD::OPC_FilterValue, 192, 4, 10, 0, // Skip to: 2683
/* 2673 */    MCD::OPC_CheckField, 11, 2, 0, 79, 0, // Skip to: 2758
/* 2679 */    MCD::OPC_Decode, 186, 1, 0, // Opcode: BDZLRL
/* 2683 */    MCD::OPC_FilterValue, 128, 5, 10, 0, // Skip to: 2698
/* 2688 */    MCD::OPC_CheckField, 11, 2, 0, 64, 0, // Skip to: 2758
/* 2694 */    MCD::OPC_Decode, 206, 1, 0, // Opcode: BLRL
/* 2698 */    MCD::OPC_FilterValue, 128, 6, 10, 0, // Skip to: 2713
/* 2703 */    MCD::OPC_CheckField, 11, 2, 0, 49, 0, // Skip to: 2758
/* 2709 */    MCD::OPC_Decode, 167, 1, 0, // Opcode: BDNZLRLm
/* 2713 */    MCD::OPC_FilterValue, 160, 6, 10, 0, // Skip to: 2728
/* 2718 */    MCD::OPC_CheckField, 11, 2, 0, 34, 0, // Skip to: 2758
/* 2724 */    MCD::OPC_Decode, 168, 1, 0, // Opcode: BDNZLRLp
/* 2728 */    MCD::OPC_FilterValue, 192, 6, 10, 0, // Skip to: 2743
/* 2733 */    MCD::OPC_CheckField, 11, 2, 0, 19, 0, // Skip to: 2758
/* 2739 */    MCD::OPC_Decode, 187, 1, 0, // Opcode: BDZLRLm
/* 2743 */    MCD::OPC_FilterValue, 224, 6, 10, 0, // Skip to: 2758
/* 2748 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 2758
/* 2754 */    MCD::OPC_Decode, 188, 1, 0, // Opcode: BDZLRLp
/* 2758 */    MCD::OPC_Decode, 221, 12, 26, // Opcode: gBCLRL
/* 2762 */    MCD::OPC_FilterValue, 36, 10, 0, // Skip to: 2776
/* 2766 */    MCD::OPC_CheckField, 11, 15, 0, 122, 32, // Skip to: 11086
/* 2772 */    MCD::OPC_Decode, 230, 7, 0, // Opcode: RFID
/* 2776 */    MCD::OPC_FilterValue, 66, 4, 0, // Skip to: 2784
/* 2780 */    MCD::OPC_Decode, 241, 1, 27, // Opcode: CRNOR
/* 2784 */    MCD::OPC_FilterValue, 76, 10, 0, // Skip to: 2798
/* 2788 */    MCD::OPC_CheckField, 11, 15, 0, 100, 32, // Skip to: 11086
/* 2794 */    MCD::OPC_Decode, 231, 7, 0, // Opcode: RFMCI
/* 2798 */    MCD::OPC_FilterValue, 78, 10, 0, // Skip to: 2812
/* 2802 */    MCD::OPC_CheckField, 11, 15, 0, 86, 32, // Skip to: 11086
/* 2808 */    MCD::OPC_Decode, 227, 7, 0, // Opcode: RFDI
/* 2812 */    MCD::OPC_FilterValue, 100, 10, 0, // Skip to: 2826
/* 2816 */    MCD::OPC_CheckField, 11, 15, 0, 72, 32, // Skip to: 11086
/* 2822 */    MCD::OPC_Decode, 229, 7, 0, // Opcode: RFI
/* 2826 */    MCD::OPC_FilterValue, 102, 10, 0, // Skip to: 2840
/* 2830 */    MCD::OPC_CheckField, 11, 15, 0, 58, 32, // Skip to: 11086
/* 2836 */    MCD::OPC_Decode, 226, 7, 0, // Opcode: RFCI
/* 2840 */    MCD::OPC_FilterValue, 130, 2, 4, 0, // Skip to: 2849
/* 2845 */    MCD::OPC_Decode, 238, 1, 27, // Opcode: CRANDC
/* 2849 */    MCD::OPC_FilterValue, 164, 2, 10, 0, // Skip to: 2864
/* 2854 */    MCD::OPC_CheckField, 12, 14, 0, 34, 32, // Skip to: 11086
/* 2860 */    MCD::OPC_Decode, 228, 7, 28, // Opcode: RFEBB
/* 2864 */    MCD::OPC_FilterValue, 172, 2, 10, 0, // Skip to: 2879
/* 2869 */    MCD::OPC_CheckField, 11, 15, 0, 19, 32, // Skip to: 11086
/* 2875 */    MCD::OPC_Decode, 235, 4, 0, // Opcode: ISYNC
/* 2879 */    MCD::OPC_FilterValue, 130, 3, 4, 0, // Skip to: 2888
/* 2884 */    MCD::OPC_Decode, 246, 1, 27, // Opcode: CRXOR
/* 2888 */    MCD::OPC_FilterValue, 194, 3, 4, 0, // Skip to: 2897
/* 2893 */    MCD::OPC_Decode, 240, 1, 27, // Opcode: CRNAND
/* 2897 */    MCD::OPC_FilterValue, 130, 4, 4, 0, // Skip to: 2906
/* 2902 */    MCD::OPC_Decode, 237, 1, 27, // Opcode: CRAND
/* 2906 */    MCD::OPC_FilterValue, 194, 4, 4, 0, // Skip to: 2915
/* 2911 */    MCD::OPC_Decode, 239, 1, 27, // Opcode: CREQV
/* 2915 */    MCD::OPC_FilterValue, 194, 6, 4, 0, // Skip to: 2924
/* 2920 */    MCD::OPC_Decode, 243, 1, 27, // Opcode: CRORC
/* 2924 */    MCD::OPC_FilterValue, 130, 7, 4, 0, // Skip to: 2933
/* 2929 */    MCD::OPC_Decode, 242, 1, 27, // Opcode: CROR
/* 2933 */    MCD::OPC_FilterValue, 160, 8, 28, 0, // Skip to: 2966
/* 2938 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 2941 */    MCD::OPC_FilterValue, 0, 205, 31, // Skip to: 11086
/* 2945 */    MCD::OPC_CheckField, 16, 10, 128, 5, 10, 0, // Skip to: 2962
/* 2952 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 2962
/* 2958 */    MCD::OPC_Decode, 149, 1, 0, // Opcode: BCTR
/* 2962 */    MCD::OPC_Decode, 216, 12, 26, // Opcode: gBCCTR
/* 2966 */    MCD::OPC_FilterValue, 161, 8, 179, 31, // Skip to: 11086
/* 2971 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 2974 */    MCD::OPC_FilterValue, 0, 172, 31, // Skip to: 11086
/* 2978 */    MCD::OPC_CheckField, 16, 10, 128, 5, 10, 0, // Skip to: 2995
/* 2985 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 2995
/* 2991 */    MCD::OPC_Decode, 151, 1, 0, // Opcode: BCTRL
/* 2995 */    MCD::OPC_Decode, 217, 12, 26, // Opcode: gBCCTRL
/* 2999 */    MCD::OPC_FilterValue, 20, 19, 0, // Skip to: 3022
/* 3003 */    MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 3006 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3014
/* 3010 */    MCD::OPC_Decode, 245, 7, 29, // Opcode: RLWIMI
/* 3014 */    MCD::OPC_FilterValue, 1, 132, 31, // Skip to: 11086
/* 3018 */    MCD::OPC_Decode, 249, 7, 29, // Opcode: RLWIMIo
/* 3022 */    MCD::OPC_FilterValue, 21, 19, 0, // Skip to: 3045
/* 3026 */    MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 3029 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3037
/* 3033 */    MCD::OPC_Decode, 251, 7, 30, // Opcode: RLWINM
/* 3037 */    MCD::OPC_FilterValue, 1, 109, 31, // Skip to: 11086
/* 3041 */    MCD::OPC_Decode, 255, 7, 30, // Opcode: RLWINMo
/* 3045 */    MCD::OPC_FilterValue, 23, 19, 0, // Skip to: 3068
/* 3049 */    MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 3052 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3060
/* 3056 */    MCD::OPC_Decode, 129, 8, 31, // Opcode: RLWNM
/* 3060 */    MCD::OPC_FilterValue, 1, 86, 31, // Skip to: 11086
/* 3064 */    MCD::OPC_Decode, 133, 8, 31, // Opcode: RLWNMo
/* 3068 */    MCD::OPC_FilterValue, 24, 14, 0, // Skip to: 3086
/* 3072 */    MCD::OPC_CheckField, 0, 26, 0, 4, 0, // Skip to: 3082
/* 3078 */    MCD::OPC_Decode, 161, 6, 0, // Opcode: NOP
/* 3082 */    MCD::OPC_Decode, 175, 6, 32, // Opcode: ORI
/* 3086 */    MCD::OPC_FilterValue, 25, 4, 0, // Skip to: 3094
/* 3090 */    MCD::OPC_Decode, 177, 6, 32, // Opcode: ORIS
/* 3094 */    MCD::OPC_FilterValue, 26, 4, 0, // Skip to: 3102
/* 3098 */    MCD::OPC_Decode, 179, 11, 32, // Opcode: XORI
/* 3102 */    MCD::OPC_FilterValue, 27, 4, 0, // Skip to: 3110
/* 3106 */    MCD::OPC_Decode, 181, 11, 32, // Opcode: XORIS
/* 3110 */    MCD::OPC_FilterValue, 28, 3, 0, // Skip to: 3117
/* 3114 */    MCD::OPC_Decode, 81, 32, // Opcode: ANDIo
/* 3117 */    MCD::OPC_FilterValue, 29, 3, 0, // Skip to: 3124
/* 3121 */    MCD::OPC_Decode, 79, 32, // Opcode: ANDISo
/* 3124 */    MCD::OPC_FilterValue, 30, 134, 0, // Skip to: 3262
/* 3128 */    MCD::OPC_ExtractField, 2, 3,  // Inst{4-2} ...
/* 3131 */    MCD::OPC_FilterValue, 0, 19, 0, // Skip to: 3154
/* 3135 */    MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 3138 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3146
/* 3142 */    MCD::OPC_Decode, 237, 7, 33, // Opcode: RLDICL
/* 3146 */    MCD::OPC_FilterValue, 1, 0, 31, // Skip to: 11086
/* 3150 */    MCD::OPC_Decode, 239, 7, 33, // Opcode: RLDICLo
/* 3154 */    MCD::OPC_FilterValue, 1, 19, 0, // Skip to: 3177
/* 3158 */    MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 3161 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3169
/* 3165 */    MCD::OPC_Decode, 240, 7, 33, // Opcode: RLDICR
/* 3169 */    MCD::OPC_FilterValue, 1, 233, 30, // Skip to: 11086
/* 3173 */    MCD::OPC_Decode, 241, 7, 33, // Opcode: RLDICRo
/* 3177 */    MCD::OPC_FilterValue, 2, 19, 0, // Skip to: 3200
/* 3181 */    MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 3184 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3192
/* 3188 */    MCD::OPC_Decode, 236, 7, 33, // Opcode: RLDIC
/* 3192 */    MCD::OPC_FilterValue, 1, 210, 30, // Skip to: 11086
/* 3196 */    MCD::OPC_Decode, 242, 7, 33, // Opcode: RLDICo
/* 3200 */    MCD::OPC_FilterValue, 3, 19, 0, // Skip to: 3223
/* 3204 */    MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 3207 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3215
/* 3211 */    MCD::OPC_Decode, 243, 7, 34, // Opcode: RLDIMI
/* 3215 */    MCD::OPC_FilterValue, 1, 187, 30, // Skip to: 11086
/* 3219 */    MCD::OPC_Decode, 244, 7, 34, // Opcode: RLDIMIo
/* 3223 */    MCD::OPC_FilterValue, 4, 179, 30, // Skip to: 11086
/* 3227 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3230 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3238
/* 3234 */    MCD::OPC_Decode, 232, 7, 35, // Opcode: RLDCL
/* 3238 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 3246
/* 3242 */    MCD::OPC_Decode, 233, 7, 35, // Opcode: RLDCLo
/* 3246 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 3254
/* 3250 */    MCD::OPC_Decode, 234, 7, 35, // Opcode: RLDCR
/* 3254 */    MCD::OPC_FilterValue, 3, 148, 30, // Skip to: 11086
/* 3258 */    MCD::OPC_Decode, 235, 7, 35, // Opcode: RLDCRo
/* 3262 */    MCD::OPC_FilterValue, 31, 182, 14, // Skip to: 7032
/* 3266 */    MCD::OPC_ExtractField, 2, 4,  // Inst{5-2} ...
/* 3269 */    MCD::OPC_FilterValue, 0, 73, 0, // Skip to: 3346
/* 3273 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3276 */    MCD::OPC_FilterValue, 0, 31, 0, // Skip to: 3311
/* 3280 */    MCD::OPC_ExtractField, 21, 2,  // Inst{22-21} ...
/* 3283 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 3297
/* 3287 */    MCD::OPC_CheckField, 0, 2, 0, 113, 30, // Skip to: 11086
/* 3293 */    MCD::OPC_Decode, 227, 1, 36, // Opcode: CMPW
/* 3297 */    MCD::OPC_FilterValue, 1, 105, 30, // Skip to: 11086
/* 3301 */    MCD::OPC_CheckField, 0, 2, 0, 99, 30, // Skip to: 11086
/* 3307 */    MCD::OPC_Decode, 221, 1, 37, // Opcode: CMPD
/* 3311 */    MCD::OPC_FilterValue, 1, 91, 30, // Skip to: 11086
/* 3315 */    MCD::OPC_ExtractField, 21, 2,  // Inst{22-21} ...
/* 3318 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 3332
/* 3322 */    MCD::OPC_CheckField, 0, 2, 0, 78, 30, // Skip to: 11086
/* 3328 */    MCD::OPC_Decode, 225, 1, 36, // Opcode: CMPLW
/* 3332 */    MCD::OPC_FilterValue, 1, 70, 30, // Skip to: 11086
/* 3336 */    MCD::OPC_CheckField, 0, 2, 0, 64, 30, // Skip to: 11086
/* 3342 */    MCD::OPC_Decode, 223, 1, 37, // Opcode: CMPLD
/* 3346 */    MCD::OPC_FilterValue, 1, 65, 0, // Skip to: 3415
/* 3350 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3353 */    MCD::OPC_FilterValue, 4, 16, 0, // Skip to: 3373
/* 3357 */    MCD::OPC_CheckField, 16, 1, 0, 43, 30, // Skip to: 11086
/* 3363 */    MCD::OPC_CheckField, 1, 1, 1, 37, 30, // Skip to: 11086
/* 3369 */    MCD::OPC_Decode, 174, 11, 38, // Opcode: WRTEE
/* 3373 */    MCD::OPC_FilterValue, 5, 10, 0, // Skip to: 3387
/* 3377 */    MCD::OPC_CheckField, 1, 1, 1, 23, 30, // Skip to: 11086
/* 3383 */    MCD::OPC_Decode, 175, 11, 39, // Opcode: WRTEEI
/* 3387 */    MCD::OPC_FilterValue, 10, 10, 0, // Skip to: 3401
/* 3391 */    MCD::OPC_CheckField, 0, 2, 2, 9, 30, // Skip to: 11086
/* 3397 */    MCD::OPC_Decode, 214, 5, 40, // Opcode: MFDCR
/* 3401 */    MCD::OPC_FilterValue, 14, 1, 30, // Skip to: 11086
/* 3405 */    MCD::OPC_CheckField, 0, 2, 2, 251, 29, // Skip to: 11086
/* 3411 */    MCD::OPC_Decode, 240, 5, 40, // Opcode: MTDCR
/* 3415 */    MCD::OPC_FilterValue, 2, 44, 0, // Skip to: 3463
/* 3419 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3422 */    MCD::OPC_FilterValue, 0, 23, 0, // Skip to: 3449
/* 3426 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3429 */    MCD::OPC_FilterValue, 0, 229, 29, // Skip to: 11086
/* 3433 */    MCD::OPC_CheckField, 11, 15, 128, 248, 1, 4, 0, // Skip to: 3445
/* 3441 */    MCD::OPC_Decode, 194, 9, 0, // Opcode: TRAP
/* 3445 */    MCD::OPC_Decode, 198, 9, 41, // Opcode: TW
/* 3449 */    MCD::OPC_FilterValue, 2, 209, 29, // Skip to: 11086
/* 3453 */    MCD::OPC_CheckField, 0, 2, 0, 203, 29, // Skip to: 11086
/* 3459 */    MCD::OPC_Decode, 177, 9, 42, // Opcode: TD
/* 3463 */    MCD::OPC_FilterValue, 3, 201, 0, // Skip to: 3668
/* 3467 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3470 */    MCD::OPC_FilterValue, 0, 19, 0, // Skip to: 3493
/* 3474 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3477 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3485
/* 3481 */    MCD::OPC_Decode, 176, 5, 43, // Opcode: LVSL
/* 3485 */    MCD::OPC_FilterValue, 2, 173, 29, // Skip to: 11086
/* 3489 */    MCD::OPC_Decode, 173, 5, 43, // Opcode: LVEBX
/* 3493 */    MCD::OPC_FilterValue, 1, 19, 0, // Skip to: 3516
/* 3497 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3500 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3508
/* 3504 */    MCD::OPC_Decode, 177, 5, 43, // Opcode: LVSR
/* 3508 */    MCD::OPC_FilterValue, 2, 150, 29, // Skip to: 11086
/* 3512 */    MCD::OPC_Decode, 174, 5, 43, // Opcode: LVEHX
/* 3516 */    MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 3530
/* 3520 */    MCD::OPC_CheckField, 0, 2, 2, 136, 29, // Skip to: 11086
/* 3526 */    MCD::OPC_Decode, 175, 5, 43, // Opcode: LVEWX
/* 3530 */    MCD::OPC_FilterValue, 3, 10, 0, // Skip to: 3544
/* 3534 */    MCD::OPC_CheckField, 0, 2, 2, 122, 29, // Skip to: 11086
/* 3540 */    MCD::OPC_Decode, 178, 5, 43, // Opcode: LVX
/* 3544 */    MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 3558
/* 3548 */    MCD::OPC_CheckField, 0, 2, 2, 108, 29, // Skip to: 11086
/* 3554 */    MCD::OPC_Decode, 237, 8, 43, // Opcode: STVEBX
/* 3558 */    MCD::OPC_FilterValue, 5, 10, 0, // Skip to: 3572
/* 3562 */    MCD::OPC_CheckField, 0, 2, 2, 94, 29, // Skip to: 11086
/* 3568 */    MCD::OPC_Decode, 238, 8, 43, // Opcode: STVEHX
/* 3572 */    MCD::OPC_FilterValue, 6, 10, 0, // Skip to: 3586
/* 3576 */    MCD::OPC_CheckField, 0, 2, 2, 80, 29, // Skip to: 11086
/* 3582 */    MCD::OPC_Decode, 239, 8, 43, // Opcode: STVEWX
/* 3586 */    MCD::OPC_FilterValue, 7, 10, 0, // Skip to: 3600
/* 3590 */    MCD::OPC_CheckField, 0, 2, 2, 66, 29, // Skip to: 11086
/* 3596 */    MCD::OPC_Decode, 240, 8, 43, // Opcode: STVX
/* 3600 */    MCD::OPC_FilterValue, 11, 10, 0, // Skip to: 3614
/* 3604 */    MCD::OPC_CheckField, 0, 2, 2, 52, 29, // Skip to: 11086
/* 3610 */    MCD::OPC_Decode, 179, 5, 43, // Opcode: LVXL
/* 3614 */    MCD::OPC_FilterValue, 14, 16, 0, // Skip to: 3634
/* 3618 */    MCD::OPC_CheckField, 21, 5, 0, 38, 29, // Skip to: 11086
/* 3624 */    MCD::OPC_CheckField, 0, 2, 0, 32, 29, // Skip to: 11086
/* 3630 */    MCD::OPC_Decode, 135, 2, 44, // Opcode: DCCCI
/* 3634 */    MCD::OPC_FilterValue, 15, 10, 0, // Skip to: 3648
/* 3638 */    MCD::OPC_CheckField, 0, 2, 2, 18, 29, // Skip to: 11086
/* 3644 */    MCD::OPC_Decode, 241, 8, 43, // Opcode: STVXL
/* 3648 */    MCD::OPC_FilterValue, 30, 10, 29, // Skip to: 11086
/* 3652 */    MCD::OPC_CheckField, 21, 5, 0, 4, 29, // Skip to: 11086
/* 3658 */    MCD::OPC_CheckField, 0, 2, 0, 254, 28, // Skip to: 11086
/* 3664 */    MCD::OPC_Decode, 226, 4, 44, // Opcode: ICCCI
/* 3668 */    MCD::OPC_FilterValue, 4, 68, 1, // Skip to: 3996
/* 3672 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3675 */    MCD::OPC_FilterValue, 0, 35, 0, // Skip to: 3714
/* 3679 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3682 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3690
/* 3686 */    MCD::OPC_Decode, 133, 9, 45, // Opcode: SUBFC
/* 3690 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 3698
/* 3694 */    MCD::OPC_Decode, 136, 9, 45, // Opcode: SUBFCo
/* 3698 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 3706
/* 3702 */    MCD::OPC_Decode, 137, 6, 46, // Opcode: MULHDU
/* 3706 */    MCD::OPC_FilterValue, 3, 208, 28, // Skip to: 11086
/* 3710 */    MCD::OPC_Decode, 138, 6, 46, // Opcode: MULHDUo
/* 3714 */    MCD::OPC_FilterValue, 1, 19, 0, // Skip to: 3737
/* 3718 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3721 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3729
/* 3725 */    MCD::OPC_Decode, 130, 9, 45, // Opcode: SUBF
/* 3729 */    MCD::OPC_FilterValue, 1, 185, 28, // Skip to: 11086
/* 3733 */    MCD::OPC_Decode, 151, 9, 45, // Opcode: SUBFo
/* 3737 */    MCD::OPC_FilterValue, 2, 19, 0, // Skip to: 3760
/* 3741 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3744 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 3752
/* 3748 */    MCD::OPC_Decode, 136, 6, 46, // Opcode: MULHD
/* 3752 */    MCD::OPC_FilterValue, 3, 162, 28, // Skip to: 11086
/* 3756 */    MCD::OPC_Decode, 139, 6, 46, // Opcode: MULHDo
/* 3760 */    MCD::OPC_FilterValue, 3, 31, 0, // Skip to: 3795
/* 3764 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3767 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 3781
/* 3771 */    MCD::OPC_CheckField, 11, 5, 0, 141, 28, // Skip to: 11086
/* 3777 */    MCD::OPC_Decode, 157, 6, 47, // Opcode: NEG
/* 3781 */    MCD::OPC_FilterValue, 1, 133, 28, // Skip to: 11086
/* 3785 */    MCD::OPC_CheckField, 11, 5, 0, 127, 28, // Skip to: 11086
/* 3791 */    MCD::OPC_Decode, 160, 6, 47, // Opcode: NEGo
/* 3795 */    MCD::OPC_FilterValue, 4, 19, 0, // Skip to: 3818
/* 3799 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3802 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 3810
/* 3806 */    MCD::OPC_Decode, 137, 9, 45, // Opcode: SUBFE
/* 3810 */    MCD::OPC_FilterValue, 1, 104, 28, // Skip to: 11086
/* 3814 */    MCD::OPC_Decode, 140, 9, 45, // Opcode: SUBFEo
/* 3818 */    MCD::OPC_FilterValue, 6, 31, 0, // Skip to: 3853
/* 3822 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3825 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 3839
/* 3829 */    MCD::OPC_CheckField, 11, 5, 0, 83, 28, // Skip to: 11086
/* 3835 */    MCD::OPC_Decode, 147, 9, 47, // Opcode: SUBFZE
/* 3839 */    MCD::OPC_FilterValue, 1, 75, 28, // Skip to: 11086
/* 3843 */    MCD::OPC_CheckField, 11, 5, 0, 69, 28, // Skip to: 11086
/* 3849 */    MCD::OPC_Decode, 150, 9, 47, // Opcode: SUBFZEo
/* 3853 */    MCD::OPC_FilterValue, 7, 47, 0, // Skip to: 3904
/* 3857 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3860 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 3874
/* 3864 */    MCD::OPC_CheckField, 11, 5, 0, 48, 28, // Skip to: 11086
/* 3870 */    MCD::OPC_Decode, 143, 9, 47, // Opcode: SUBFME
/* 3874 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 3888
/* 3878 */    MCD::OPC_CheckField, 11, 5, 0, 34, 28, // Skip to: 11086
/* 3884 */    MCD::OPC_Decode, 146, 9, 47, // Opcode: SUBFMEo
/* 3888 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 3896
/* 3892 */    MCD::OPC_Decode, 144, 6, 46, // Opcode: MULLD
/* 3896 */    MCD::OPC_FilterValue, 3, 18, 28, // Skip to: 11086
/* 3900 */    MCD::OPC_Decode, 145, 6, 46, // Opcode: MULLDo
/* 3904 */    MCD::OPC_FilterValue, 12, 19, 0, // Skip to: 3927
/* 3908 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3911 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 3919
/* 3915 */    MCD::OPC_Decode, 138, 2, 46, // Opcode: DIVDEU
/* 3919 */    MCD::OPC_FilterValue, 3, 251, 27, // Skip to: 11086
/* 3923 */    MCD::OPC_Decode, 139, 2, 46, // Opcode: DIVDEUo
/* 3927 */    MCD::OPC_FilterValue, 13, 19, 0, // Skip to: 3950
/* 3931 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3934 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 3942
/* 3938 */    MCD::OPC_Decode, 137, 2, 46, // Opcode: DIVDE
/* 3942 */    MCD::OPC_FilterValue, 3, 228, 27, // Skip to: 11086
/* 3946 */    MCD::OPC_Decode, 140, 2, 46, // Opcode: DIVDEo
/* 3950 */    MCD::OPC_FilterValue, 14, 19, 0, // Skip to: 3973
/* 3954 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3957 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 3965
/* 3961 */    MCD::OPC_Decode, 141, 2, 46, // Opcode: DIVDU
/* 3965 */    MCD::OPC_FilterValue, 3, 205, 27, // Skip to: 11086
/* 3969 */    MCD::OPC_Decode, 142, 2, 46, // Opcode: DIVDUo
/* 3973 */    MCD::OPC_FilterValue, 15, 197, 27, // Skip to: 11086
/* 3977 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 3980 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 3988
/* 3984 */    MCD::OPC_Decode, 136, 2, 46, // Opcode: DIVD
/* 3988 */    MCD::OPC_FilterValue, 3, 182, 27, // Skip to: 11086
/* 3992 */    MCD::OPC_Decode, 143, 2, 46, // Opcode: DIVDo
/* 3996 */    MCD::OPC_FilterValue, 5, 23, 1, // Skip to: 4279
/* 4000 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 4003 */    MCD::OPC_FilterValue, 0, 33, 0, // Skip to: 4040
/* 4007 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4010 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 4017
/* 4014 */    MCD::OPC_Decode, 30, 45, // Opcode: ADDC
/* 4017 */    MCD::OPC_FilterValue, 1, 3, 0, // Skip to: 4024
/* 4021 */    MCD::OPC_Decode, 33, 45, // Opcode: ADDCo
/* 4024 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 4032
/* 4028 */    MCD::OPC_Decode, 141, 6, 45, // Opcode: MULHWU
/* 4032 */    MCD::OPC_FilterValue, 3, 138, 27, // Skip to: 11086
/* 4036 */    MCD::OPC_Decode, 142, 6, 45, // Opcode: MULHWUo
/* 4040 */    MCD::OPC_FilterValue, 2, 19, 0, // Skip to: 4063
/* 4044 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4047 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 4055
/* 4051 */    MCD::OPC_Decode, 140, 6, 45, // Opcode: MULHW
/* 4055 */    MCD::OPC_FilterValue, 3, 115, 27, // Skip to: 11086
/* 4059 */    MCD::OPC_Decode, 143, 6, 45, // Opcode: MULHWo
/* 4063 */    MCD::OPC_FilterValue, 4, 17, 0, // Skip to: 4084
/* 4067 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4070 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 4077
/* 4074 */    MCD::OPC_Decode, 34, 45, // Opcode: ADDE
/* 4077 */    MCD::OPC_FilterValue, 1, 93, 27, // Skip to: 11086
/* 4081 */    MCD::OPC_Decode, 37, 45, // Opcode: ADDEo
/* 4084 */    MCD::OPC_FilterValue, 6, 29, 0, // Skip to: 4117
/* 4088 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4091 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4104
/* 4095 */    MCD::OPC_CheckField, 11, 5, 0, 73, 27, // Skip to: 11086
/* 4101 */    MCD::OPC_Decode, 66, 47, // Opcode: ADDZE
/* 4104 */    MCD::OPC_FilterValue, 1, 66, 27, // Skip to: 11086
/* 4108 */    MCD::OPC_CheckField, 11, 5, 0, 60, 27, // Skip to: 11086
/* 4114 */    MCD::OPC_Decode, 69, 47, // Opcode: ADDZEo
/* 4117 */    MCD::OPC_FilterValue, 7, 45, 0, // Skip to: 4166
/* 4121 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4124 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4137
/* 4128 */    MCD::OPC_CheckField, 11, 5, 0, 40, 27, // Skip to: 11086
/* 4134 */    MCD::OPC_Decode, 62, 47, // Opcode: ADDME
/* 4137 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 4150
/* 4141 */    MCD::OPC_CheckField, 11, 5, 0, 27, 27, // Skip to: 11086
/* 4147 */    MCD::OPC_Decode, 65, 47, // Opcode: ADDMEo
/* 4150 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 4158
/* 4154 */    MCD::OPC_Decode, 148, 6, 45, // Opcode: MULLW
/* 4158 */    MCD::OPC_FilterValue, 3, 12, 27, // Skip to: 11086
/* 4162 */    MCD::OPC_Decode, 149, 6, 45, // Opcode: MULLWo
/* 4166 */    MCD::OPC_FilterValue, 8, 17, 0, // Skip to: 4187
/* 4170 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4173 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 4180
/* 4177 */    MCD::OPC_Decode, 23, 45, // Opcode: ADD4
/* 4180 */    MCD::OPC_FilterValue, 1, 246, 26, // Skip to: 11086
/* 4184 */    MCD::OPC_Decode, 25, 45, // Opcode: ADD4o
/* 4187 */    MCD::OPC_FilterValue, 12, 19, 0, // Skip to: 4210
/* 4191 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4194 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 4202
/* 4198 */    MCD::OPC_Decode, 146, 2, 45, // Opcode: DIVWEU
/* 4202 */    MCD::OPC_FilterValue, 3, 224, 26, // Skip to: 11086
/* 4206 */    MCD::OPC_Decode, 147, 2, 45, // Opcode: DIVWEUo
/* 4210 */    MCD::OPC_FilterValue, 13, 19, 0, // Skip to: 4233
/* 4214 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4217 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 4225
/* 4221 */    MCD::OPC_Decode, 145, 2, 45, // Opcode: DIVWE
/* 4225 */    MCD::OPC_FilterValue, 3, 201, 26, // Skip to: 11086
/* 4229 */    MCD::OPC_Decode, 148, 2, 45, // Opcode: DIVWEo
/* 4233 */    MCD::OPC_FilterValue, 14, 19, 0, // Skip to: 4256
/* 4237 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4240 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 4248
/* 4244 */    MCD::OPC_Decode, 149, 2, 45, // Opcode: DIVWU
/* 4248 */    MCD::OPC_FilterValue, 3, 178, 26, // Skip to: 11086
/* 4252 */    MCD::OPC_Decode, 150, 2, 45, // Opcode: DIVWUo
/* 4256 */    MCD::OPC_FilterValue, 15, 170, 26, // Skip to: 11086
/* 4260 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4263 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 4271
/* 4267 */    MCD::OPC_Decode, 144, 2, 45, // Opcode: DIVW
/* 4271 */    MCD::OPC_FilterValue, 3, 155, 26, // Skip to: 11086
/* 4275 */    MCD::OPC_Decode, 151, 2, 45, // Opcode: DIVWo
/* 4279 */    MCD::OPC_FilterValue, 6, 171, 0, // Skip to: 4454
/* 4283 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 4286 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 4300
/* 4290 */    MCD::OPC_CheckField, 1, 1, 0, 134, 26, // Skip to: 11086
/* 4296 */    MCD::OPC_Decode, 201, 5, 48, // Opcode: LXSIWZX
/* 4300 */    MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 4314
/* 4304 */    MCD::OPC_CheckField, 1, 1, 0, 120, 26, // Skip to: 11086
/* 4310 */    MCD::OPC_Decode, 200, 5, 48, // Opcode: LXSIWAX
/* 4314 */    MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 4328
/* 4318 */    MCD::OPC_CheckField, 1, 1, 0, 106, 26, // Skip to: 11086
/* 4324 */    MCD::OPC_Decode, 254, 8, 48, // Opcode: STXSIWX
/* 4328 */    MCD::OPC_FilterValue, 10, 10, 0, // Skip to: 4342
/* 4332 */    MCD::OPC_CheckField, 1, 1, 0, 92, 26, // Skip to: 11086
/* 4338 */    MCD::OPC_Decode, 204, 5, 49, // Opcode: LXVDSX
/* 4342 */    MCD::OPC_FilterValue, 16, 10, 0, // Skip to: 4356
/* 4346 */    MCD::OPC_CheckField, 1, 1, 0, 78, 26, // Skip to: 11086
/* 4352 */    MCD::OPC_Decode, 202, 5, 50, // Opcode: LXSSPX
/* 4356 */    MCD::OPC_FilterValue, 18, 10, 0, // Skip to: 4370
/* 4360 */    MCD::OPC_CheckField, 1, 1, 0, 64, 26, // Skip to: 11086
/* 4366 */    MCD::OPC_Decode, 199, 5, 48, // Opcode: LXSDX
/* 4370 */    MCD::OPC_FilterValue, 20, 10, 0, // Skip to: 4384
/* 4374 */    MCD::OPC_CheckField, 1, 1, 0, 50, 26, // Skip to: 11086
/* 4380 */    MCD::OPC_Decode, 255, 8, 50, // Opcode: STXSSPX
/* 4384 */    MCD::OPC_FilterValue, 22, 10, 0, // Skip to: 4398
/* 4388 */    MCD::OPC_CheckField, 1, 1, 0, 36, 26, // Skip to: 11086
/* 4394 */    MCD::OPC_Decode, 253, 8, 48, // Opcode: STXSDX
/* 4398 */    MCD::OPC_FilterValue, 24, 10, 0, // Skip to: 4412
/* 4402 */    MCD::OPC_CheckField, 1, 1, 0, 22, 26, // Skip to: 11086
/* 4408 */    MCD::OPC_Decode, 205, 5, 49, // Opcode: LXVW4X
/* 4412 */    MCD::OPC_FilterValue, 26, 10, 0, // Skip to: 4426
/* 4416 */    MCD::OPC_CheckField, 1, 1, 0, 8, 26, // Skip to: 11086
/* 4422 */    MCD::OPC_Decode, 203, 5, 49, // Opcode: LXVD2X
/* 4426 */    MCD::OPC_FilterValue, 28, 10, 0, // Skip to: 4440
/* 4430 */    MCD::OPC_CheckField, 1, 1, 0, 250, 25, // Skip to: 11086
/* 4436 */    MCD::OPC_Decode, 129, 9, 49, // Opcode: STXVW4X
/* 4440 */    MCD::OPC_FilterValue, 30, 242, 25, // Skip to: 11086
/* 4444 */    MCD::OPC_CheckField, 1, 1, 0, 236, 25, // Skip to: 11086
/* 4450 */    MCD::OPC_Decode, 128, 9, 49, // Opcode: STXVD2X
/* 4454 */    MCD::OPC_FilterValue, 7, 201, 0, // Skip to: 4659
/* 4458 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4461 */    MCD::OPC_FilterValue, 0, 39, 0, // Skip to: 4504
/* 4465 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 4468 */    MCD::OPC_FilterValue, 9, 4, 0, // Skip to: 4476
/* 4472 */    MCD::OPC_Decode, 209, 5, 51, // Opcode: MFBHRBE
/* 4476 */    MCD::OPC_FilterValue, 13, 10, 0, // Skip to: 4490
/* 4480 */    MCD::OPC_CheckField, 11, 15, 0, 200, 25, // Skip to: 11086
/* 4486 */    MCD::OPC_Decode, 210, 1, 0, // Opcode: CLRBHRB
/* 4490 */    MCD::OPC_FilterValue, 22, 192, 25, // Skip to: 11086
/* 4494 */    MCD::OPC_CheckField, 11, 12, 0, 186, 25, // Skip to: 11086
/* 4500 */    MCD::OPC_Decode, 169, 9, 52, // Opcode: TCHECK
/* 4504 */    MCD::OPC_FilterValue, 1, 143, 0, // Skip to: 4651
/* 4508 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 4511 */    MCD::OPC_FilterValue, 20, 16, 0, // Skip to: 4531
/* 4515 */    MCD::OPC_CheckField, 22, 4, 0, 165, 25, // Skip to: 11086
/* 4521 */    MCD::OPC_CheckField, 11, 10, 0, 159, 25, // Skip to: 11086
/* 4527 */    MCD::OPC_Decode, 168, 9, 53, // Opcode: TBEGIN
/* 4531 */    MCD::OPC_FilterValue, 21, 10, 0, // Skip to: 4545
/* 4535 */    MCD::OPC_CheckField, 11, 14, 0, 145, 25, // Skip to: 11086
/* 4541 */    MCD::OPC_Decode, 179, 9, 54, // Opcode: TEND
/* 4545 */    MCD::OPC_FilterValue, 23, 16, 0, // Skip to: 4565
/* 4549 */    MCD::OPC_CheckField, 22, 3, 0, 131, 25, // Skip to: 11086
/* 4555 */    MCD::OPC_CheckField, 11, 10, 0, 125, 25, // Skip to: 11086
/* 4561 */    MCD::OPC_Decode, 197, 9, 53, // Opcode: TSR
/* 4565 */    MCD::OPC_FilterValue, 24, 4, 0, // Skip to: 4573
/* 4569 */    MCD::OPC_Decode, 160, 9, 55, // Opcode: TABORTWC
/* 4573 */    MCD::OPC_FilterValue, 25, 4, 0, // Skip to: 4581
/* 4577 */    MCD::OPC_Decode, 158, 9, 55, // Opcode: TABORTDC
/* 4581 */    MCD::OPC_FilterValue, 26, 4, 0, // Skip to: 4589
/* 4585 */    MCD::OPC_Decode, 161, 9, 56, // Opcode: TABORTWCI
/* 4589 */    MCD::OPC_FilterValue, 27, 4, 0, // Skip to: 4597
/* 4593 */    MCD::OPC_Decode, 159, 9, 56, // Opcode: TABORTDCI
/* 4597 */    MCD::OPC_FilterValue, 28, 16, 0, // Skip to: 4617
/* 4601 */    MCD::OPC_CheckField, 21, 5, 0, 79, 25, // Skip to: 11086
/* 4607 */    MCD::OPC_CheckField, 11, 5, 0, 73, 25, // Skip to: 11086
/* 4613 */    MCD::OPC_Decode, 157, 9, 57, // Opcode: TABORT
/* 4617 */    MCD::OPC_FilterValue, 29, 16, 0, // Skip to: 4637
/* 4621 */    MCD::OPC_CheckField, 21, 5, 0, 59, 25, // Skip to: 11086
/* 4627 */    MCD::OPC_CheckField, 11, 5, 0, 53, 25, // Skip to: 11086
/* 4633 */    MCD::OPC_Decode, 196, 9, 57, // Opcode: TRECLAIM
/* 4637 */    MCD::OPC_FilterValue, 31, 45, 25, // Skip to: 11086
/* 4641 */    MCD::OPC_CheckField, 11, 15, 0, 39, 25, // Skip to: 11086
/* 4647 */    MCD::OPC_Decode, 195, 9, 0, // Opcode: TRECHKPT
/* 4651 */    MCD::OPC_FilterValue, 2, 31, 25, // Skip to: 11086
/* 4655 */    MCD::OPC_Decode, 233, 4, 58, // Opcode: ISEL
/* 4659 */    MCD::OPC_FilterValue, 8, 43, 0, // Skip to: 4706
/* 4663 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 4666 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 4686
/* 4670 */    MCD::OPC_CheckField, 6, 6, 4, 10, 25, // Skip to: 11086
/* 4676 */    MCD::OPC_CheckField, 0, 2, 0, 4, 25, // Skip to: 11086
/* 4682 */    MCD::OPC_Decode, 234, 5, 59, // Opcode: MTCRF
/* 4686 */    MCD::OPC_FilterValue, 1, 252, 24, // Skip to: 11086
/* 4690 */    MCD::OPC_CheckField, 6, 6, 4, 246, 24, // Skip to: 11086
/* 4696 */    MCD::OPC_CheckField, 0, 2, 0, 240, 24, // Skip to: 11086
/* 4702 */    MCD::OPC_Decode, 252, 5, 60, // Opcode: MTOCRF
/* 4706 */    MCD::OPC_FilterValue, 9, 75, 2, // Skip to: 5297
/* 4710 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 4713 */    MCD::OPC_FilterValue, 0, 43, 0, // Skip to: 4760
/* 4717 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 4720 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 4740
/* 4724 */    MCD::OPC_CheckField, 11, 9, 0, 212, 24, // Skip to: 11086
/* 4730 */    MCD::OPC_CheckField, 0, 2, 2, 206, 24, // Skip to: 11086
/* 4736 */    MCD::OPC_Decode, 210, 5, 38, // Opcode: MFCR
/* 4740 */    MCD::OPC_FilterValue, 1, 198, 24, // Skip to: 11086
/* 4744 */    MCD::OPC_CheckField, 11, 1, 0, 192, 24, // Skip to: 11086
/* 4750 */    MCD::OPC_CheckField, 0, 2, 2, 186, 24, // Skip to: 11086
/* 4756 */    MCD::OPC_Decode, 220, 5, 61, // Opcode: MFOCRF
/* 4760 */    MCD::OPC_FilterValue, 1, 16, 0, // Skip to: 4780
/* 4764 */    MCD::OPC_CheckField, 11, 5, 0, 172, 24, // Skip to: 11086
/* 4770 */    MCD::OPC_CheckField, 1, 1, 1, 166, 24, // Skip to: 11086
/* 4776 */    MCD::OPC_Decode, 231, 5, 62, // Opcode: MFVSRD
/* 4780 */    MCD::OPC_FilterValue, 2, 16, 0, // Skip to: 4800
/* 4784 */    MCD::OPC_CheckField, 11, 10, 0, 152, 24, // Skip to: 11086
/* 4790 */    MCD::OPC_CheckField, 0, 2, 2, 146, 24, // Skip to: 11086
/* 4796 */    MCD::OPC_Decode, 219, 5, 38, // Opcode: MFMSR
/* 4800 */    MCD::OPC_FilterValue, 3, 16, 0, // Skip to: 4820
/* 4804 */    MCD::OPC_CheckField, 11, 5, 0, 132, 24, // Skip to: 11086
/* 4810 */    MCD::OPC_CheckField, 1, 1, 1, 126, 24, // Skip to: 11086
/* 4816 */    MCD::OPC_Decode, 232, 5, 63, // Opcode: MFVSRWZ
/* 4820 */    MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 4834
/* 4824 */    MCD::OPC_CheckField, 1, 1, 0, 112, 24, // Skip to: 11086
/* 4830 */    MCD::OPC_Decode, 250, 5, 64, // Opcode: MTMSR
/* 4834 */    MCD::OPC_FilterValue, 5, 25, 0, // Skip to: 4863
/* 4838 */    MCD::OPC_ExtractField, 1, 1,  // Inst{1} ...
/* 4841 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 4849
/* 4845 */    MCD::OPC_Decode, 251, 5, 64, // Opcode: MTMSRD
/* 4849 */    MCD::OPC_FilterValue, 1, 89, 24, // Skip to: 11086
/* 4853 */    MCD::OPC_CheckField, 11, 5, 0, 83, 24, // Skip to: 11086
/* 4859 */    MCD::OPC_Decode, 133, 6, 65, // Opcode: MTVSRD
/* 4863 */    MCD::OPC_FilterValue, 6, 25, 0, // Skip to: 4892
/* 4867 */    MCD::OPC_ExtractField, 1, 1,  // Inst{1} ...
/* 4870 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 4878
/* 4874 */    MCD::OPC_Decode, 128, 6, 66, // Opcode: MTSR
/* 4878 */    MCD::OPC_FilterValue, 1, 60, 24, // Skip to: 11086
/* 4882 */    MCD::OPC_CheckField, 11, 5, 0, 54, 24, // Skip to: 11086
/* 4888 */    MCD::OPC_Decode, 134, 6, 67, // Opcode: MTVSRWA
/* 4892 */    MCD::OPC_FilterValue, 7, 25, 0, // Skip to: 4921
/* 4896 */    MCD::OPC_ExtractField, 1, 1,  // Inst{1} ...
/* 4899 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 4907
/* 4903 */    MCD::OPC_Decode, 129, 6, 68, // Opcode: MTSRIN
/* 4907 */    MCD::OPC_FilterValue, 1, 31, 24, // Skip to: 11086
/* 4911 */    MCD::OPC_CheckField, 11, 5, 0, 25, 24, // Skip to: 11086
/* 4917 */    MCD::OPC_Decode, 135, 6, 67, // Opcode: MTVSRWZ
/* 4921 */    MCD::OPC_FilterValue, 8, 16, 0, // Skip to: 4941
/* 4925 */    MCD::OPC_CheckField, 16, 10, 0, 11, 24, // Skip to: 11086
/* 4931 */    MCD::OPC_CheckField, 0, 2, 0, 5, 24, // Skip to: 11086
/* 4937 */    MCD::OPC_Decode, 182, 9, 69, // Opcode: TLBIEL
/* 4941 */    MCD::OPC_FilterValue, 9, 16, 0, // Skip to: 4961
/* 4945 */    MCD::OPC_CheckField, 16, 5, 0, 247, 23, // Skip to: 11086
/* 4951 */    MCD::OPC_CheckField, 0, 2, 0, 241, 23, // Skip to: 11086
/* 4957 */    MCD::OPC_Decode, 181, 9, 68, // Opcode: TLBIE
/* 4961 */    MCD::OPC_FilterValue, 10, 32, 0, // Skip to: 4997
/* 4965 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 4968 */    MCD::OPC_FilterValue, 2, 226, 23, // Skip to: 11086
/* 4972 */    MCD::OPC_ExtractField, 11, 10,  // Inst{20-11} ...
/* 4975 */    MCD::OPC_FilterValue, 128, 2, 4, 0, // Skip to: 4984
/* 4980 */    MCD::OPC_Decode, 217, 5, 38, // Opcode: MFLR
/* 4984 */    MCD::OPC_FilterValue, 160, 2, 4, 0, // Skip to: 4993
/* 4989 */    MCD::OPC_Decode, 212, 5, 38, // Opcode: MFCTR
/* 4993 */    MCD::OPC_Decode, 222, 5, 40, // Opcode: MFSPR
/* 4997 */    MCD::OPC_FilterValue, 11, 25, 0, // Skip to: 5026
/* 5001 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5004 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5018
/* 5008 */    MCD::OPC_CheckField, 11, 15, 0, 184, 23, // Skip to: 11086
/* 5014 */    MCD::OPC_Decode, 180, 9, 0, // Opcode: TLBIA
/* 5018 */    MCD::OPC_FilterValue, 2, 176, 23, // Skip to: 11086
/* 5022 */    MCD::OPC_Decode, 226, 5, 40, // Opcode: MFTB
/* 5026 */    MCD::OPC_FilterValue, 12, 16, 0, // Skip to: 5046
/* 5030 */    MCD::OPC_CheckField, 16, 5, 0, 162, 23, // Skip to: 11086
/* 5036 */    MCD::OPC_CheckField, 0, 2, 0, 156, 23, // Skip to: 11086
/* 5042 */    MCD::OPC_Decode, 166, 8, 68, // Opcode: SLBMTE
/* 5046 */    MCD::OPC_FilterValue, 13, 16, 0, // Skip to: 5066
/* 5050 */    MCD::OPC_CheckField, 16, 10, 0, 142, 23, // Skip to: 11086
/* 5056 */    MCD::OPC_CheckField, 0, 2, 0, 136, 23, // Skip to: 11086
/* 5062 */    MCD::OPC_Decode, 164, 8, 69, // Opcode: SLBIE
/* 5066 */    MCD::OPC_FilterValue, 14, 32, 0, // Skip to: 5102
/* 5070 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5073 */    MCD::OPC_FilterValue, 2, 121, 23, // Skip to: 11086
/* 5077 */    MCD::OPC_ExtractField, 11, 10,  // Inst{20-11} ...
/* 5080 */    MCD::OPC_FilterValue, 128, 2, 4, 0, // Skip to: 5089
/* 5085 */    MCD::OPC_Decode, 248, 5, 38, // Opcode: MTLR
/* 5089 */    MCD::OPC_FilterValue, 160, 2, 4, 0, // Skip to: 5098
/* 5094 */    MCD::OPC_Decode, 236, 5, 38, // Opcode: MTCTR
/* 5098 */    MCD::OPC_Decode, 254, 5, 70, // Opcode: MTSPR
/* 5102 */    MCD::OPC_FilterValue, 15, 16, 0, // Skip to: 5122
/* 5106 */    MCD::OPC_CheckField, 11, 15, 0, 86, 23, // Skip to: 11086
/* 5112 */    MCD::OPC_CheckField, 0, 2, 0, 80, 23, // Skip to: 11086
/* 5118 */    MCD::OPC_Decode, 163, 8, 0, // Opcode: SLBIA
/* 5122 */    MCD::OPC_FilterValue, 18, 10, 0, // Skip to: 5136
/* 5126 */    MCD::OPC_CheckField, 1, 1, 1, 66, 23, // Skip to: 11086
/* 5132 */    MCD::OPC_Decode, 224, 5, 66, // Opcode: MFSR
/* 5136 */    MCD::OPC_FilterValue, 20, 10, 0, // Skip to: 5150
/* 5140 */    MCD::OPC_CheckField, 1, 1, 1, 52, 23, // Skip to: 11086
/* 5146 */    MCD::OPC_Decode, 225, 5, 68, // Opcode: MFSRIN
/* 5150 */    MCD::OPC_FilterValue, 24, 16, 0, // Skip to: 5170
/* 5154 */    MCD::OPC_CheckField, 21, 5, 0, 38, 23, // Skip to: 11086
/* 5160 */    MCD::OPC_CheckField, 0, 2, 0, 32, 23, // Skip to: 11086
/* 5166 */    MCD::OPC_Decode, 183, 9, 44, // Opcode: TLBIVAX
/* 5170 */    MCD::OPC_FilterValue, 28, 43, 0, // Skip to: 5217
/* 5174 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5177 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 5195
/* 5181 */    MCD::OPC_CheckField, 21, 5, 0, 4, 0, // Skip to: 5191
/* 5187 */    MCD::OPC_Decode, 188, 9, 44, // Opcode: TLBSX
/* 5191 */    MCD::OPC_Decode, 189, 9, 45, // Opcode: TLBSX2
/* 5195 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 5203
/* 5199 */    MCD::OPC_Decode, 190, 9, 45, // Opcode: TLBSX2D
/* 5203 */    MCD::OPC_FilterValue, 2, 247, 22, // Skip to: 11086
/* 5207 */    MCD::OPC_CheckField, 16, 5, 0, 241, 22, // Skip to: 11086
/* 5213 */    MCD::OPC_Decode, 165, 8, 68, // Opcode: SLBMFEE
/* 5217 */    MCD::OPC_FilterValue, 29, 21, 0, // Skip to: 5242
/* 5221 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5224 */    MCD::OPC_FilterValue, 0, 226, 22, // Skip to: 11086
/* 5228 */    MCD::OPC_CheckField, 11, 15, 0, 4, 0, // Skip to: 5238
/* 5234 */    MCD::OPC_Decode, 186, 9, 0, // Opcode: TLBRE
/* 5238 */    MCD::OPC_Decode, 187, 9, 71, // Opcode: TLBRE2
/* 5242 */    MCD::OPC_FilterValue, 30, 31, 0, // Skip to: 5277
/* 5246 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5249 */    MCD::OPC_FilterValue, 0, 201, 22, // Skip to: 11086
/* 5253 */    MCD::OPC_CheckField, 11, 15, 0, 4, 0, // Skip to: 5263
/* 5259 */    MCD::OPC_Decode, 192, 9, 0, // Opcode: TLBWE
/* 5263 */    MCD::OPC_CheckField, 16, 10, 0, 4, 0, // Skip to: 5273
/* 5269 */    MCD::OPC_Decode, 184, 9, 69, // Opcode: TLBLD
/* 5273 */    MCD::OPC_Decode, 193, 9, 71, // Opcode: TLBWE2
/* 5277 */    MCD::OPC_FilterValue, 31, 173, 22, // Skip to: 11086
/* 5281 */    MCD::OPC_CheckField, 16, 10, 0, 167, 22, // Skip to: 11086
/* 5287 */    MCD::OPC_CheckField, 0, 2, 0, 161, 22, // Skip to: 11086
/* 5293 */    MCD::OPC_Decode, 185, 9, 69, // Opcode: TLBLI
/* 5297 */    MCD::OPC_FilterValue, 10, 79, 1, // Skip to: 5636
/* 5301 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 5304 */    MCD::OPC_FilterValue, 0, 27, 0, // Skip to: 5335
/* 5308 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5311 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 5319
/* 5315 */    MCD::OPC_Decode, 181, 5, 72, // Opcode: LWARX
/* 5319 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 5327
/* 5323 */    MCD::OPC_Decode, 182, 5, 72, // Opcode: LWARXL
/* 5327 */    MCD::OPC_FilterValue, 2, 123, 22, // Skip to: 11086
/* 5331 */    MCD::OPC_Decode, 128, 5, 73, // Opcode: LDX
/* 5335 */    MCD::OPC_FilterValue, 1, 27, 0, // Skip to: 5366
/* 5339 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5342 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 5350
/* 5346 */    MCD::OPC_Decode, 238, 4, 72, // Opcode: LBARX
/* 5350 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 5358
/* 5354 */    MCD::OPC_Decode, 239, 4, 72, // Opcode: LBARXL
/* 5358 */    MCD::OPC_FilterValue, 2, 92, 22, // Skip to: 11086
/* 5362 */    MCD::OPC_Decode, 255, 4, 74, // Opcode: LDUX
/* 5366 */    MCD::OPC_FilterValue, 2, 19, 0, // Skip to: 5389
/* 5370 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5373 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 5381
/* 5377 */    MCD::OPC_Decode, 250, 4, 73, // Opcode: LDARX
/* 5381 */    MCD::OPC_FilterValue, 1, 69, 22, // Skip to: 11086
/* 5385 */    MCD::OPC_Decode, 251, 4, 73, // Opcode: LDARXL
/* 5389 */    MCD::OPC_FilterValue, 3, 19, 0, // Skip to: 5412
/* 5393 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5396 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 5404
/* 5400 */    MCD::OPC_Decode, 148, 5, 72, // Opcode: LHARX
/* 5404 */    MCD::OPC_FilterValue, 1, 46, 22, // Skip to: 11086
/* 5408 */    MCD::OPC_Decode, 149, 5, 72, // Opcode: LHARXL
/* 5412 */    MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 5426
/* 5416 */    MCD::OPC_CheckField, 0, 2, 2, 32, 22, // Skip to: 11086
/* 5422 */    MCD::OPC_Decode, 214, 8, 73, // Opcode: STDX
/* 5426 */    MCD::OPC_FilterValue, 5, 10, 0, // Skip to: 5440
/* 5430 */    MCD::OPC_CheckField, 0, 2, 2, 18, 22, // Skip to: 11086
/* 5436 */    MCD::OPC_Decode, 213, 8, 75, // Opcode: STDUX
/* 5440 */    MCD::OPC_FilterValue, 10, 10, 0, // Skip to: 5454
/* 5444 */    MCD::OPC_CheckField, 0, 2, 2, 4, 22, // Skip to: 11086
/* 5450 */    MCD::OPC_Decode, 184, 5, 73, // Opcode: LWAX
/* 5454 */    MCD::OPC_FilterValue, 11, 10, 0, // Skip to: 5468
/* 5458 */    MCD::OPC_CheckField, 0, 2, 2, 246, 21, // Skip to: 11086
/* 5464 */    MCD::OPC_Decode, 183, 5, 74, // Opcode: LWAUX
/* 5468 */    MCD::OPC_FilterValue, 16, 10, 0, // Skip to: 5482
/* 5472 */    MCD::OPC_CheckField, 0, 2, 0, 232, 21, // Skip to: 11086
/* 5478 */    MCD::OPC_Decode, 252, 4, 73, // Opcode: LDBRX
/* 5482 */    MCD::OPC_FilterValue, 18, 10, 0, // Skip to: 5496
/* 5486 */    MCD::OPC_CheckField, 0, 2, 2, 218, 21, // Skip to: 11086
/* 5492 */    MCD::OPC_Decode, 172, 5, 76, // Opcode: LSWI
/* 5496 */    MCD::OPC_FilterValue, 20, 10, 0, // Skip to: 5510
/* 5500 */    MCD::OPC_CheckField, 0, 2, 0, 204, 21, // Skip to: 11086
/* 5506 */    MCD::OPC_Decode, 209, 8, 73, // Opcode: STDBRX
/* 5510 */    MCD::OPC_FilterValue, 22, 10, 0, // Skip to: 5524
/* 5514 */    MCD::OPC_CheckField, 0, 2, 2, 190, 21, // Skip to: 11086
/* 5520 */    MCD::OPC_Decode, 236, 8, 76, // Opcode: STSWI
/* 5524 */    MCD::OPC_FilterValue, 24, 10, 0, // Skip to: 5538
/* 5528 */    MCD::OPC_CheckField, 0, 2, 2, 176, 21, // Skip to: 11086
/* 5534 */    MCD::OPC_Decode, 191, 5, 45, // Opcode: LWZCIX
/* 5538 */    MCD::OPC_FilterValue, 25, 10, 0, // Skip to: 5552
/* 5542 */    MCD::OPC_CheckField, 0, 2, 2, 162, 21, // Skip to: 11086
/* 5548 */    MCD::OPC_Decode, 160, 5, 45, // Opcode: LHZCIX
/* 5552 */    MCD::OPC_FilterValue, 26, 10, 0, // Skip to: 5566
/* 5556 */    MCD::OPC_CheckField, 0, 2, 2, 148, 21, // Skip to: 11086
/* 5562 */    MCD::OPC_Decode, 242, 4, 45, // Opcode: LBZCIX
/* 5566 */    MCD::OPC_FilterValue, 27, 10, 0, // Skip to: 5580
/* 5570 */    MCD::OPC_CheckField, 0, 2, 2, 134, 21, // Skip to: 11086
/* 5576 */    MCD::OPC_Decode, 253, 4, 45, // Opcode: LDCIX
/* 5580 */    MCD::OPC_FilterValue, 28, 10, 0, // Skip to: 5594
/* 5584 */    MCD::OPC_CheckField, 0, 2, 2, 120, 21, // Skip to: 11086
/* 5590 */    MCD::OPC_Decode, 245, 8, 45, // Opcode: STWCIX
/* 5594 */    MCD::OPC_FilterValue, 29, 10, 0, // Skip to: 5608
/* 5598 */    MCD::OPC_CheckField, 0, 2, 2, 106, 21, // Skip to: 11086
/* 5604 */    MCD::OPC_Decode, 227, 8, 45, // Opcode: STHCIX
/* 5608 */    MCD::OPC_FilterValue, 30, 10, 0, // Skip to: 5622
/* 5612 */    MCD::OPC_CheckField, 0, 2, 2, 92, 21, // Skip to: 11086
/* 5618 */    MCD::OPC_Decode, 200, 8, 45, // Opcode: STBCIX
/* 5622 */    MCD::OPC_FilterValue, 31, 84, 21, // Skip to: 11086
/* 5626 */    MCD::OPC_CheckField, 0, 2, 2, 78, 21, // Skip to: 11086
/* 5632 */    MCD::OPC_Decode, 210, 8, 45, // Opcode: STDCIX
/* 5636 */    MCD::OPC_FilterValue, 11, 233, 2, // Skip to: 6385
/* 5640 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 5643 */    MCD::OPC_FilterValue, 0, 25, 0, // Skip to: 5672
/* 5647 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5650 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5664
/* 5654 */    MCD::OPC_CheckField, 25, 1, 0, 50, 21, // Skip to: 11086
/* 5660 */    MCD::OPC_Decode, 225, 4, 77, // Opcode: ICBT
/* 5664 */    MCD::OPC_FilterValue, 2, 42, 21, // Skip to: 11086
/* 5668 */    MCD::OPC_Decode, 196, 5, 72, // Opcode: LWZX
/* 5672 */    MCD::OPC_FilterValue, 1, 25, 0, // Skip to: 5701
/* 5676 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5679 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5693
/* 5683 */    MCD::OPC_CheckField, 21, 5, 0, 21, 21, // Skip to: 11086
/* 5689 */    MCD::OPC_Decode, 250, 1, 78, // Opcode: DCBST
/* 5693 */    MCD::OPC_FilterValue, 2, 13, 21, // Skip to: 11086
/* 5697 */    MCD::OPC_Decode, 194, 5, 79, // Opcode: LWZUX
/* 5701 */    MCD::OPC_FilterValue, 2, 25, 0, // Skip to: 5730
/* 5705 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5708 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 5722
/* 5712 */    MCD::OPC_CheckField, 21, 5, 0, 248, 20, // Skip to: 11086
/* 5718 */    MCD::OPC_Decode, 248, 1, 78, // Opcode: DCBF
/* 5722 */    MCD::OPC_FilterValue, 2, 240, 20, // Skip to: 11086
/* 5726 */    MCD::OPC_Decode, 247, 4, 72, // Opcode: LBZX
/* 5730 */    MCD::OPC_FilterValue, 3, 10, 0, // Skip to: 5744
/* 5734 */    MCD::OPC_CheckField, 0, 2, 2, 226, 20, // Skip to: 11086
/* 5740 */    MCD::OPC_Decode, 245, 4, 79, // Opcode: LBZUX
/* 5744 */    MCD::OPC_FilterValue, 4, 19, 0, // Skip to: 5767
/* 5748 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5751 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 5759
/* 5755 */    MCD::OPC_Decode, 246, 8, 72, // Opcode: STWCX
/* 5759 */    MCD::OPC_FilterValue, 2, 203, 20, // Skip to: 11086
/* 5763 */    MCD::OPC_Decode, 251, 8, 72, // Opcode: STWX
/* 5767 */    MCD::OPC_FilterValue, 5, 10, 0, // Skip to: 5781
/* 5771 */    MCD::OPC_CheckField, 0, 2, 2, 189, 20, // Skip to: 11086
/* 5777 */    MCD::OPC_Decode, 249, 8, 80, // Opcode: STWUX
/* 5781 */    MCD::OPC_FilterValue, 6, 19, 0, // Skip to: 5804
/* 5785 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5788 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 5796
/* 5792 */    MCD::OPC_Decode, 211, 8, 73, // Opcode: STDCX
/* 5796 */    MCD::OPC_FilterValue, 2, 166, 20, // Skip to: 11086
/* 5800 */    MCD::OPC_Decode, 206, 8, 72, // Opcode: STBX
/* 5804 */    MCD::OPC_FilterValue, 7, 19, 0, // Skip to: 5827
/* 5808 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5811 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 5819
/* 5815 */    MCD::OPC_Decode, 254, 1, 81, // Opcode: DCBTST
/* 5819 */    MCD::OPC_FilterValue, 2, 143, 20, // Skip to: 11086
/* 5823 */    MCD::OPC_Decode, 204, 8, 80, // Opcode: STBUX
/* 5827 */    MCD::OPC_FilterValue, 8, 19, 0, // Skip to: 5850
/* 5831 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5834 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 5842
/* 5838 */    MCD::OPC_Decode, 251, 1, 81, // Opcode: DCBT
/* 5842 */    MCD::OPC_FilterValue, 2, 120, 20, // Skip to: 11086
/* 5846 */    MCD::OPC_Decode, 165, 5, 72, // Opcode: LHZX
/* 5850 */    MCD::OPC_FilterValue, 9, 10, 0, // Skip to: 5864
/* 5854 */    MCD::OPC_CheckField, 0, 2, 2, 106, 20, // Skip to: 11086
/* 5860 */    MCD::OPC_Decode, 163, 5, 79, // Opcode: LHZUX
/* 5864 */    MCD::OPC_FilterValue, 10, 34, 0, // Skip to: 5902
/* 5868 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5871 */    MCD::OPC_FilterValue, 0, 19, 0, // Skip to: 5894
/* 5875 */    MCD::OPC_ExtractField, 23, 3,  // Inst{25-23} ...
/* 5878 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 5886
/* 5882 */    MCD::OPC_Decode, 154, 2, 82, // Opcode: DST
/* 5886 */    MCD::OPC_FilterValue, 4, 76, 20, // Skip to: 11086
/* 5890 */    MCD::OPC_Decode, 160, 2, 82, // Opcode: DSTT
/* 5894 */    MCD::OPC_FilterValue, 2, 68, 20, // Skip to: 11086
/* 5898 */    MCD::OPC_Decode, 154, 5, 72, // Opcode: LHAX
/* 5902 */    MCD::OPC_FilterValue, 11, 34, 0, // Skip to: 5940
/* 5906 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5909 */    MCD::OPC_FilterValue, 0, 19, 0, // Skip to: 5932
/* 5913 */    MCD::OPC_ExtractField, 23, 3,  // Inst{25-23} ...
/* 5916 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 5924
/* 5920 */    MCD::OPC_Decode, 156, 2, 82, // Opcode: DSTST
/* 5924 */    MCD::OPC_FilterValue, 4, 38, 20, // Skip to: 11086
/* 5928 */    MCD::OPC_Decode, 158, 2, 82, // Opcode: DSTSTT
/* 5932 */    MCD::OPC_FilterValue, 2, 30, 20, // Skip to: 11086
/* 5936 */    MCD::OPC_Decode, 152, 5, 79, // Opcode: LHAUX
/* 5940 */    MCD::OPC_FilterValue, 12, 10, 0, // Skip to: 5954
/* 5944 */    MCD::OPC_CheckField, 0, 2, 2, 16, 20, // Skip to: 11086
/* 5950 */    MCD::OPC_Decode, 233, 8, 72, // Opcode: STHX
/* 5954 */    MCD::OPC_FilterValue, 13, 10, 0, // Skip to: 5968
/* 5958 */    MCD::OPC_CheckField, 0, 2, 2, 2, 20, // Skip to: 11086
/* 5964 */    MCD::OPC_Decode, 231, 8, 80, // Opcode: STHUX
/* 5968 */    MCD::OPC_FilterValue, 14, 16, 0, // Skip to: 5988
/* 5972 */    MCD::OPC_CheckField, 21, 5, 0, 244, 19, // Skip to: 11086
/* 5978 */    MCD::OPC_CheckField, 0, 2, 0, 238, 19, // Skip to: 11086
/* 5984 */    MCD::OPC_Decode, 249, 1, 78, // Opcode: DCBI
/* 5988 */    MCD::OPC_FilterValue, 16, 19, 0, // Skip to: 6011
/* 5992 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 5995 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6003
/* 5999 */    MCD::OPC_Decode, 187, 5, 72, // Opcode: LWBRX
/* 6003 */    MCD::OPC_FilterValue, 2, 215, 19, // Skip to: 11086
/* 6007 */    MCD::OPC_Decode, 145, 5, 83, // Opcode: LFSX
/* 6011 */    MCD::OPC_FilterValue, 17, 25, 0, // Skip to: 6040
/* 6015 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6018 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6032
/* 6022 */    MCD::OPC_CheckField, 11, 15, 0, 194, 19, // Skip to: 11086
/* 6028 */    MCD::OPC_Decode, 191, 9, 0, // Opcode: TLBSYNC
/* 6032 */    MCD::OPC_FilterValue, 2, 186, 19, // Skip to: 11086
/* 6036 */    MCD::OPC_Decode, 144, 5, 84, // Opcode: LFSUX
/* 6040 */    MCD::OPC_FilterValue, 18, 31, 0, // Skip to: 6075
/* 6044 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6047 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 6067
/* 6051 */    MCD::OPC_CheckField, 23, 3, 0, 165, 19, // Skip to: 11086
/* 6057 */    MCD::OPC_CheckField, 11, 10, 0, 159, 19, // Skip to: 11086
/* 6063 */    MCD::OPC_Decode, 156, 9, 85, // Opcode: SYNC
/* 6067 */    MCD::OPC_FilterValue, 2, 151, 19, // Skip to: 11086
/* 6071 */    MCD::OPC_Decode, 139, 5, 86, // Opcode: LFDX
/* 6075 */    MCD::OPC_FilterValue, 19, 10, 0, // Skip to: 6089
/* 6079 */    MCD::OPC_CheckField, 0, 2, 2, 137, 19, // Skip to: 11086
/* 6085 */    MCD::OPC_Decode, 138, 5, 87, // Opcode: LFDUX
/* 6089 */    MCD::OPC_FilterValue, 20, 19, 0, // Skip to: 6112
/* 6093 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6096 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6104
/* 6100 */    MCD::OPC_Decode, 244, 8, 72, // Opcode: STWBRX
/* 6104 */    MCD::OPC_FilterValue, 2, 114, 19, // Skip to: 11086
/* 6108 */    MCD::OPC_Decode, 223, 8, 83, // Opcode: STFSX
/* 6112 */    MCD::OPC_FilterValue, 21, 19, 0, // Skip to: 6135
/* 6116 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6119 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 6127
/* 6123 */    MCD::OPC_Decode, 201, 8, 72, // Opcode: STBCX
/* 6127 */    MCD::OPC_FilterValue, 2, 91, 19, // Skip to: 11086
/* 6131 */    MCD::OPC_Decode, 222, 8, 88, // Opcode: STFSUX
/* 6135 */    MCD::OPC_FilterValue, 22, 19, 0, // Skip to: 6158
/* 6139 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6142 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 6150
/* 6146 */    MCD::OPC_Decode, 228, 8, 72, // Opcode: STHCX
/* 6150 */    MCD::OPC_FilterValue, 2, 68, 19, // Skip to: 11086
/* 6154 */    MCD::OPC_Decode, 218, 8, 86, // Opcode: STFDX
/* 6158 */    MCD::OPC_FilterValue, 23, 25, 0, // Skip to: 6187
/* 6162 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6165 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6179
/* 6169 */    MCD::OPC_CheckField, 21, 5, 0, 47, 19, // Skip to: 11086
/* 6175 */    MCD::OPC_Decode, 247, 1, 78, // Opcode: DCBA
/* 6179 */    MCD::OPC_FilterValue, 2, 39, 19, // Skip to: 11086
/* 6183 */    MCD::OPC_Decode, 217, 8, 89, // Opcode: STFDUX
/* 6187 */    MCD::OPC_FilterValue, 24, 10, 0, // Skip to: 6201
/* 6191 */    MCD::OPC_CheckField, 0, 2, 0, 25, 19, // Skip to: 11086
/* 6197 */    MCD::OPC_Decode, 156, 5, 72, // Opcode: LHBRX
/* 6201 */    MCD::OPC_FilterValue, 25, 43, 0, // Skip to: 6248
/* 6205 */    MCD::OPC_ExtractField, 23, 3,  // Inst{25-23} ...
/* 6208 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 6228
/* 6212 */    MCD::OPC_CheckField, 11, 10, 0, 4, 19, // Skip to: 11086
/* 6218 */    MCD::OPC_CheckField, 0, 2, 0, 254, 18, // Skip to: 11086
/* 6224 */    MCD::OPC_Decode, 152, 2, 90, // Opcode: DSS
/* 6228 */    MCD::OPC_FilterValue, 4, 246, 18, // Skip to: 11086
/* 6232 */    MCD::OPC_CheckField, 11, 12, 0, 240, 18, // Skip to: 11086
/* 6238 */    MCD::OPC_CheckField, 0, 2, 0, 234, 18, // Skip to: 11086
/* 6244 */    MCD::OPC_Decode, 153, 2, 0, // Opcode: DSSALL
/* 6248 */    MCD::OPC_FilterValue, 26, 41, 0, // Skip to: 6293
/* 6252 */    MCD::OPC_ExtractField, 1, 1,  // Inst{1} ...
/* 6255 */    MCD::OPC_FilterValue, 0, 20, 0, // Skip to: 6279
/* 6259 */    MCD::OPC_CheckField, 11, 15, 0, 10, 0, // Skip to: 6275
/* 6265 */    MCD::OPC_CheckField, 0, 1, 0, 4, 0, // Skip to: 6275
/* 6271 */    MCD::OPC_Decode, 240, 3, 0, // Opcode: EnforceIEIO
/* 6275 */    MCD::OPC_Decode, 206, 5, 91, // Opcode: MBAR
/* 6279 */    MCD::OPC_FilterValue, 1, 195, 18, // Skip to: 11086
/* 6283 */    MCD::OPC_CheckField, 0, 1, 0, 189, 18, // Skip to: 11086
/* 6289 */    MCD::OPC_Decode, 140, 5, 86, // Opcode: LFIWAX
/* 6293 */    MCD::OPC_FilterValue, 27, 10, 0, // Skip to: 6307
/* 6297 */    MCD::OPC_CheckField, 0, 2, 2, 175, 18, // Skip to: 11086
/* 6303 */    MCD::OPC_Decode, 141, 5, 86, // Opcode: LFIWZX
/* 6307 */    MCD::OPC_FilterValue, 28, 10, 0, // Skip to: 6321
/* 6311 */    MCD::OPC_CheckField, 0, 2, 0, 161, 18, // Skip to: 11086
/* 6317 */    MCD::OPC_Decode, 226, 8, 72, // Opcode: STHBRX
/* 6321 */    MCD::OPC_FilterValue, 30, 25, 0, // Skip to: 6350
/* 6325 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6328 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6342
/* 6332 */    MCD::OPC_CheckField, 21, 5, 0, 140, 18, // Skip to: 11086
/* 6338 */    MCD::OPC_Decode, 224, 4, 78, // Opcode: ICBI
/* 6342 */    MCD::OPC_FilterValue, 2, 132, 18, // Skip to: 11086
/* 6346 */    MCD::OPC_Decode, 219, 8, 86, // Opcode: STFIWX
/* 6350 */    MCD::OPC_FilterValue, 31, 124, 18, // Skip to: 11086
/* 6354 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 6357 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6371
/* 6361 */    MCD::OPC_CheckField, 0, 2, 0, 111, 18, // Skip to: 11086
/* 6367 */    MCD::OPC_Decode, 133, 2, 78, // Opcode: DCBZ
/* 6371 */    MCD::OPC_FilterValue, 1, 103, 18, // Skip to: 11086
/* 6375 */    MCD::OPC_CheckField, 0, 2, 0, 97, 18, // Skip to: 11086
/* 6381 */    MCD::OPC_Decode, 134, 2, 78, // Opcode: DCBZL
/* 6385 */    MCD::OPC_FilterValue, 12, 95, 0, // Skip to: 6484
/* 6389 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 6392 */    MCD::OPC_FilterValue, 0, 19, 0, // Skip to: 6415
/* 6396 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6399 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6407
/* 6403 */    MCD::OPC_Decode, 171, 8, 92, // Opcode: SLW
/* 6407 */    MCD::OPC_FilterValue, 1, 67, 18, // Skip to: 11086
/* 6411 */    MCD::OPC_Decode, 176, 8, 92, // Opcode: SLWo
/* 6415 */    MCD::OPC_FilterValue, 16, 19, 0, // Skip to: 6438
/* 6419 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6422 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6430
/* 6426 */    MCD::OPC_Decode, 192, 8, 92, // Opcode: SRW
/* 6430 */    MCD::OPC_FilterValue, 1, 44, 18, // Skip to: 11086
/* 6434 */    MCD::OPC_Decode, 197, 8, 92, // Opcode: SRWo
/* 6438 */    MCD::OPC_FilterValue, 24, 19, 0, // Skip to: 6461
/* 6442 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6445 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6453
/* 6449 */    MCD::OPC_Decode, 184, 8, 92, // Opcode: SRAW
/* 6453 */    MCD::OPC_FilterValue, 1, 21, 18, // Skip to: 11086
/* 6457 */    MCD::OPC_Decode, 187, 8, 92, // Opcode: SRAWo
/* 6461 */    MCD::OPC_FilterValue, 25, 13, 18, // Skip to: 11086
/* 6465 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6468 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6476
/* 6472 */    MCD::OPC_Decode, 185, 8, 93, // Opcode: SRAWI
/* 6476 */    MCD::OPC_FilterValue, 1, 254, 17, // Skip to: 11086
/* 6480 */    MCD::OPC_Decode, 186, 8, 93, // Opcode: SRAWIo
/* 6484 */    MCD::OPC_FilterValue, 13, 47, 1, // Skip to: 6791
/* 6488 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 6491 */    MCD::OPC_FilterValue, 0, 47, 0, // Skip to: 6542
/* 6495 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6498 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6512
/* 6502 */    MCD::OPC_CheckField, 11, 5, 0, 226, 17, // Skip to: 11086
/* 6508 */    MCD::OPC_Decode, 231, 1, 94, // Opcode: CNTLZW
/* 6512 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 6526
/* 6516 */    MCD::OPC_CheckField, 11, 5, 0, 212, 17, // Skip to: 11086
/* 6522 */    MCD::OPC_Decode, 234, 1, 94, // Opcode: CNTLZWo
/* 6526 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 6534
/* 6530 */    MCD::OPC_Decode, 167, 8, 95, // Opcode: SLD
/* 6534 */    MCD::OPC_FilterValue, 3, 196, 17, // Skip to: 11086
/* 6538 */    MCD::OPC_Decode, 170, 8, 95, // Opcode: SLDo
/* 6542 */    MCD::OPC_FilterValue, 1, 31, 0, // Skip to: 6577
/* 6546 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6549 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6563
/* 6553 */    MCD::OPC_CheckField, 11, 5, 0, 175, 17, // Skip to: 11086
/* 6559 */    MCD::OPC_Decode, 229, 1, 96, // Opcode: CNTLZD
/* 6563 */    MCD::OPC_FilterValue, 1, 167, 17, // Skip to: 11086
/* 6567 */    MCD::OPC_CheckField, 11, 5, 0, 161, 17, // Skip to: 11086
/* 6573 */    MCD::OPC_Decode, 230, 1, 96, // Opcode: CNTLZDo
/* 6577 */    MCD::OPC_FilterValue, 11, 16, 0, // Skip to: 6597
/* 6581 */    MCD::OPC_CheckField, 11, 5, 0, 147, 17, // Skip to: 11086
/* 6587 */    MCD::OPC_CheckField, 0, 2, 0, 141, 17, // Skip to: 11086
/* 6593 */    MCD::OPC_Decode, 181, 6, 94, // Opcode: POPCNTW
/* 6597 */    MCD::OPC_FilterValue, 15, 16, 0, // Skip to: 6617
/* 6601 */    MCD::OPC_CheckField, 11, 5, 0, 127, 17, // Skip to: 11086
/* 6607 */    MCD::OPC_CheckField, 0, 2, 0, 121, 17, // Skip to: 11086
/* 6613 */    MCD::OPC_Decode, 180, 6, 96, // Opcode: POPCNTD
/* 6617 */    MCD::OPC_FilterValue, 16, 19, 0, // Skip to: 6640
/* 6621 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6624 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 6632
/* 6628 */    MCD::OPC_Decode, 188, 8, 95, // Opcode: SRD
/* 6632 */    MCD::OPC_FilterValue, 3, 98, 17, // Skip to: 11086
/* 6636 */    MCD::OPC_Decode, 191, 8, 95, // Opcode: SRDo
/* 6640 */    MCD::OPC_FilterValue, 24, 19, 0, // Skip to: 6663
/* 6644 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6647 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6655
/* 6651 */    MCD::OPC_Decode, 180, 8, 95, // Opcode: SRAD
/* 6655 */    MCD::OPC_FilterValue, 1, 75, 17, // Skip to: 11086
/* 6659 */    MCD::OPC_Decode, 183, 8, 95, // Opcode: SRADo
/* 6663 */    MCD::OPC_FilterValue, 25, 19, 0, // Skip to: 6686
/* 6667 */    MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 6670 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6678
/* 6674 */    MCD::OPC_Decode, 181, 8, 97, // Opcode: SRADI
/* 6678 */    MCD::OPC_FilterValue, 1, 52, 17, // Skip to: 11086
/* 6682 */    MCD::OPC_Decode, 182, 8, 97, // Opcode: SRADIo
/* 6686 */    MCD::OPC_FilterValue, 28, 31, 0, // Skip to: 6721
/* 6690 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6693 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6707
/* 6697 */    MCD::OPC_CheckField, 11, 5, 0, 31, 17, // Skip to: 11086
/* 6703 */    MCD::OPC_Decode, 231, 3, 94, // Opcode: EXTSH
/* 6707 */    MCD::OPC_FilterValue, 1, 23, 17, // Skip to: 11086
/* 6711 */    MCD::OPC_CheckField, 11, 5, 0, 17, 17, // Skip to: 11086
/* 6717 */    MCD::OPC_Decode, 235, 3, 94, // Opcode: EXTSHo
/* 6721 */    MCD::OPC_FilterValue, 29, 31, 0, // Skip to: 6756
/* 6725 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6728 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6742
/* 6732 */    MCD::OPC_CheckField, 11, 5, 0, 252, 16, // Skip to: 11086
/* 6738 */    MCD::OPC_Decode, 226, 3, 94, // Opcode: EXTSB
/* 6742 */    MCD::OPC_FilterValue, 1, 244, 16, // Skip to: 11086
/* 6746 */    MCD::OPC_CheckField, 11, 5, 0, 238, 16, // Skip to: 11086
/* 6752 */    MCD::OPC_Decode, 230, 3, 94, // Opcode: EXTSBo
/* 6756 */    MCD::OPC_FilterValue, 30, 230, 16, // Skip to: 11086
/* 6760 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6763 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 6777
/* 6767 */    MCD::OPC_CheckField, 11, 5, 0, 217, 16, // Skip to: 11086
/* 6773 */    MCD::OPC_Decode, 236, 3, 96, // Opcode: EXTSW
/* 6777 */    MCD::OPC_FilterValue, 1, 209, 16, // Skip to: 11086
/* 6781 */    MCD::OPC_CheckField, 11, 5, 0, 203, 16, // Skip to: 11086
/* 6787 */    MCD::OPC_Decode, 239, 3, 96, // Opcode: EXTSWo
/* 6791 */    MCD::OPC_FilterValue, 14, 211, 0, // Skip to: 7006
/* 6795 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 6798 */    MCD::OPC_FilterValue, 0, 17, 0, // Skip to: 6819
/* 6802 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6805 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 6812
/* 6809 */    MCD::OPC_Decode, 72, 92, // Opcode: AND
/* 6812 */    MCD::OPC_FilterValue, 1, 174, 16, // Skip to: 11086
/* 6816 */    MCD::OPC_Decode, 87, 92, // Opcode: ANDo
/* 6819 */    MCD::OPC_FilterValue, 1, 17, 0, // Skip to: 6840
/* 6823 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6826 */    MCD::OPC_FilterValue, 0, 3, 0, // Skip to: 6833
/* 6830 */    MCD::OPC_Decode, 75, 92, // Opcode: ANDC
/* 6833 */    MCD::OPC_FilterValue, 1, 153, 16, // Skip to: 11086
/* 6837 */    MCD::OPC_Decode, 78, 92, // Opcode: ANDCo
/* 6840 */    MCD::OPC_FilterValue, 3, 19, 0, // Skip to: 6863
/* 6844 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6847 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6855
/* 6851 */    MCD::OPC_Decode, 164, 6, 92, // Opcode: NOR
/* 6855 */    MCD::OPC_FilterValue, 1, 131, 16, // Skip to: 11086
/* 6859 */    MCD::OPC_Decode, 167, 6, 92, // Opcode: NORo
/* 6863 */    MCD::OPC_FilterValue, 7, 10, 0, // Skip to: 6877
/* 6867 */    MCD::OPC_CheckField, 0, 2, 0, 117, 16, // Skip to: 11086
/* 6873 */    MCD::OPC_Decode, 208, 1, 98, // Opcode: BPERMD
/* 6877 */    MCD::OPC_FilterValue, 8, 19, 0, // Skip to: 6900
/* 6881 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6884 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6892
/* 6888 */    MCD::OPC_Decode, 171, 2, 92, // Opcode: EQV
/* 6892 */    MCD::OPC_FilterValue, 1, 94, 16, // Skip to: 11086
/* 6896 */    MCD::OPC_Decode, 174, 2, 92, // Opcode: EQVo
/* 6900 */    MCD::OPC_FilterValue, 9, 19, 0, // Skip to: 6923
/* 6904 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6907 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6915
/* 6911 */    MCD::OPC_Decode, 176, 11, 92, // Opcode: XOR
/* 6915 */    MCD::OPC_FilterValue, 1, 71, 16, // Skip to: 11086
/* 6919 */    MCD::OPC_Decode, 183, 11, 92, // Opcode: XORo
/* 6923 */    MCD::OPC_FilterValue, 12, 19, 0, // Skip to: 6946
/* 6927 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6930 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6938
/* 6934 */    MCD::OPC_Decode, 171, 6, 92, // Opcode: ORC
/* 6938 */    MCD::OPC_FilterValue, 1, 48, 16, // Skip to: 11086
/* 6942 */    MCD::OPC_Decode, 174, 6, 92, // Opcode: ORCo
/* 6946 */    MCD::OPC_FilterValue, 13, 19, 0, // Skip to: 6969
/* 6950 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6953 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6961
/* 6957 */    MCD::OPC_Decode, 168, 6, 92, // Opcode: OR
/* 6961 */    MCD::OPC_FilterValue, 1, 25, 16, // Skip to: 11086
/* 6965 */    MCD::OPC_Decode, 179, 6, 92, // Opcode: ORo
/* 6969 */    MCD::OPC_FilterValue, 14, 19, 0, // Skip to: 6992
/* 6973 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 6976 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 6984
/* 6980 */    MCD::OPC_Decode, 153, 6, 92, // Opcode: NAND
/* 6984 */    MCD::OPC_FilterValue, 1, 2, 16, // Skip to: 11086
/* 6988 */    MCD::OPC_Decode, 156, 6, 92, // Opcode: NANDo
/* 6992 */    MCD::OPC_FilterValue, 15, 250, 15, // Skip to: 11086
/* 6996 */    MCD::OPC_CheckField, 0, 2, 0, 244, 15, // Skip to: 11086
/* 7002 */    MCD::OPC_Decode, 219, 1, 92, // Opcode: CMPB
/* 7006 */    MCD::OPC_FilterValue, 15, 236, 15, // Skip to: 11086
/* 7010 */    MCD::OPC_CheckField, 23, 3, 0, 230, 15, // Skip to: 11086
/* 7016 */    MCD::OPC_CheckField, 6, 15, 1, 224, 15, // Skip to: 11086
/* 7022 */    MCD::OPC_CheckField, 0, 2, 0, 218, 15, // Skip to: 11086
/* 7028 */    MCD::OPC_Decode, 173, 11, 85, // Opcode: WAIT
/* 7032 */    MCD::OPC_FilterValue, 32, 4, 0, // Skip to: 7040
/* 7036 */    MCD::OPC_Decode, 189, 5, 99, // Opcode: LWZ
/* 7040 */    MCD::OPC_FilterValue, 33, 4, 0, // Skip to: 7048
/* 7044 */    MCD::OPC_Decode, 192, 5, 99, // Opcode: LWZU
/* 7048 */    MCD::OPC_FilterValue, 34, 4, 0, // Skip to: 7056
/* 7052 */    MCD::OPC_Decode, 240, 4, 99, // Opcode: LBZ
/* 7056 */    MCD::OPC_FilterValue, 35, 4, 0, // Skip to: 7064
/* 7060 */    MCD::OPC_Decode, 243, 4, 99, // Opcode: LBZU
/* 7064 */    MCD::OPC_FilterValue, 36, 4, 0, // Skip to: 7072
/* 7068 */    MCD::OPC_Decode, 242, 8, 99, // Opcode: STW
/* 7072 */    MCD::OPC_FilterValue, 37, 4, 0, // Skip to: 7080
/* 7076 */    MCD::OPC_Decode, 247, 8, 99, // Opcode: STWU
/* 7080 */    MCD::OPC_FilterValue, 38, 4, 0, // Skip to: 7088
/* 7084 */    MCD::OPC_Decode, 198, 8, 99, // Opcode: STB
/* 7088 */    MCD::OPC_FilterValue, 39, 4, 0, // Skip to: 7096
/* 7092 */    MCD::OPC_Decode, 202, 8, 99, // Opcode: STBU
/* 7096 */    MCD::OPC_FilterValue, 40, 4, 0, // Skip to: 7104
/* 7100 */    MCD::OPC_Decode, 158, 5, 99, // Opcode: LHZ
/* 7104 */    MCD::OPC_FilterValue, 41, 4, 0, // Skip to: 7112
/* 7108 */    MCD::OPC_Decode, 161, 5, 99, // Opcode: LHZU
/* 7112 */    MCD::OPC_FilterValue, 42, 4, 0, // Skip to: 7120
/* 7116 */    MCD::OPC_Decode, 146, 5, 99, // Opcode: LHA
/* 7120 */    MCD::OPC_FilterValue, 43, 4, 0, // Skip to: 7128
/* 7124 */    MCD::OPC_Decode, 150, 5, 99, // Opcode: LHAU
/* 7128 */    MCD::OPC_FilterValue, 44, 4, 0, // Skip to: 7136
/* 7132 */    MCD::OPC_Decode, 224, 8, 99, // Opcode: STH
/* 7136 */    MCD::OPC_FilterValue, 45, 4, 0, // Skip to: 7144
/* 7140 */    MCD::OPC_Decode, 229, 8, 99, // Opcode: STHU
/* 7144 */    MCD::OPC_FilterValue, 46, 4, 0, // Skip to: 7152
/* 7148 */    MCD::OPC_Decode, 171, 5, 99, // Opcode: LMW
/* 7152 */    MCD::OPC_FilterValue, 47, 4, 0, // Skip to: 7160
/* 7156 */    MCD::OPC_Decode, 235, 8, 99, // Opcode: STMW
/* 7160 */    MCD::OPC_FilterValue, 48, 4, 0, // Skip to: 7168
/* 7164 */    MCD::OPC_Decode, 142, 5, 100, // Opcode: LFS
/* 7168 */    MCD::OPC_FilterValue, 49, 4, 0, // Skip to: 7176
/* 7172 */    MCD::OPC_Decode, 143, 5, 100, // Opcode: LFSU
/* 7176 */    MCD::OPC_FilterValue, 50, 4, 0, // Skip to: 7184
/* 7180 */    MCD::OPC_Decode, 136, 5, 101, // Opcode: LFD
/* 7184 */    MCD::OPC_FilterValue, 51, 4, 0, // Skip to: 7192
/* 7188 */    MCD::OPC_Decode, 137, 5, 101, // Opcode: LFDU
/* 7192 */    MCD::OPC_FilterValue, 52, 4, 0, // Skip to: 7200
/* 7196 */    MCD::OPC_Decode, 220, 8, 100, // Opcode: STFS
/* 7200 */    MCD::OPC_FilterValue, 53, 4, 0, // Skip to: 7208
/* 7204 */    MCD::OPC_Decode, 221, 8, 100, // Opcode: STFSU
/* 7208 */    MCD::OPC_FilterValue, 54, 4, 0, // Skip to: 7216
/* 7212 */    MCD::OPC_Decode, 215, 8, 101, // Opcode: STFD
/* 7216 */    MCD::OPC_FilterValue, 55, 4, 0, // Skip to: 7224
/* 7220 */    MCD::OPC_Decode, 216, 8, 101, // Opcode: STFDU
/* 7224 */    MCD::OPC_FilterValue, 58, 27, 0, // Skip to: 7255
/* 7228 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 7231 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7239
/* 7235 */    MCD::OPC_Decode, 249, 4, 102, // Opcode: LD
/* 7239 */    MCD::OPC_FilterValue, 1, 4, 0, // Skip to: 7247
/* 7243 */    MCD::OPC_Decode, 254, 4, 102, // Opcode: LDU
/* 7247 */    MCD::OPC_FilterValue, 2, 251, 14, // Skip to: 11086
/* 7251 */    MCD::OPC_Decode, 180, 5, 102, // Opcode: LWA
/* 7255 */    MCD::OPC_FilterValue, 59, 113, 1, // Skip to: 7628
/* 7259 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 7262 */    MCD::OPC_FilterValue, 28, 31, 0, // Skip to: 7297
/* 7266 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 7269 */    MCD::OPC_FilterValue, 26, 10, 0, // Skip to: 7283
/* 7273 */    MCD::OPC_CheckField, 16, 5, 0, 223, 14, // Skip to: 11086
/* 7279 */    MCD::OPC_Decode, 251, 3, 103, // Opcode: FCFIDS
/* 7283 */    MCD::OPC_FilterValue, 30, 215, 14, // Skip to: 11086
/* 7287 */    MCD::OPC_CheckField, 16, 5, 0, 209, 14, // Skip to: 11086
/* 7293 */    MCD::OPC_Decode, 254, 3, 103, // Opcode: FCFIDUS
/* 7297 */    MCD::OPC_FilterValue, 29, 31, 0, // Skip to: 7332
/* 7301 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 7304 */    MCD::OPC_FilterValue, 26, 10, 0, // Skip to: 7318
/* 7308 */    MCD::OPC_CheckField, 16, 5, 0, 188, 14, // Skip to: 11086
/* 7314 */    MCD::OPC_Decode, 252, 3, 103, // Opcode: FCFIDSo
/* 7318 */    MCD::OPC_FilterValue, 30, 180, 14, // Skip to: 11086
/* 7322 */    MCD::OPC_CheckField, 16, 5, 0, 174, 14, // Skip to: 11086
/* 7328 */    MCD::OPC_Decode, 255, 3, 103, // Opcode: FCFIDUSo
/* 7332 */    MCD::OPC_FilterValue, 36, 10, 0, // Skip to: 7346
/* 7336 */    MCD::OPC_CheckField, 6, 5, 0, 160, 14, // Skip to: 11086
/* 7342 */    MCD::OPC_Decode, 149, 4, 104, // Opcode: FDIVS
/* 7346 */    MCD::OPC_FilterValue, 37, 10, 0, // Skip to: 7360
/* 7350 */    MCD::OPC_CheckField, 6, 5, 0, 146, 14, // Skip to: 11086
/* 7356 */    MCD::OPC_Decode, 150, 4, 104, // Opcode: FDIVSo
/* 7360 */    MCD::OPC_FilterValue, 40, 10, 0, // Skip to: 7374
/* 7364 */    MCD::OPC_CheckField, 6, 5, 0, 132, 14, // Skip to: 11086
/* 7370 */    MCD::OPC_Decode, 217, 4, 104, // Opcode: FSUBS
/* 7374 */    MCD::OPC_FilterValue, 41, 10, 0, // Skip to: 7388
/* 7378 */    MCD::OPC_CheckField, 6, 5, 0, 118, 14, // Skip to: 11086
/* 7384 */    MCD::OPC_Decode, 218, 4, 104, // Opcode: FSUBSo
/* 7388 */    MCD::OPC_FilterValue, 42, 10, 0, // Skip to: 7402
/* 7392 */    MCD::OPC_CheckField, 6, 5, 0, 104, 14, // Skip to: 11086
/* 7398 */    MCD::OPC_Decode, 246, 3, 104, // Opcode: FADDS
/* 7402 */    MCD::OPC_FilterValue, 43, 10, 0, // Skip to: 7416
/* 7406 */    MCD::OPC_CheckField, 6, 5, 0, 90, 14, // Skip to: 11086
/* 7412 */    MCD::OPC_Decode, 247, 3, 104, // Opcode: FADDSo
/* 7416 */    MCD::OPC_FilterValue, 44, 16, 0, // Skip to: 7436
/* 7420 */    MCD::OPC_CheckField, 16, 5, 0, 76, 14, // Skip to: 11086
/* 7426 */    MCD::OPC_CheckField, 6, 5, 0, 70, 14, // Skip to: 11086
/* 7432 */    MCD::OPC_Decode, 213, 4, 105, // Opcode: FSQRTS
/* 7436 */    MCD::OPC_FilterValue, 45, 16, 0, // Skip to: 7456
/* 7440 */    MCD::OPC_CheckField, 16, 5, 0, 56, 14, // Skip to: 11086
/* 7446 */    MCD::OPC_CheckField, 6, 5, 0, 50, 14, // Skip to: 11086
/* 7452 */    MCD::OPC_Decode, 214, 4, 105, // Opcode: FSQRTSo
/* 7456 */    MCD::OPC_FilterValue, 48, 16, 0, // Skip to: 7476
/* 7460 */    MCD::OPC_CheckField, 16, 5, 0, 36, 14, // Skip to: 11086
/* 7466 */    MCD::OPC_CheckField, 6, 5, 0, 30, 14, // Skip to: 11086
/* 7472 */    MCD::OPC_Decode, 183, 4, 105, // Opcode: FRES
/* 7476 */    MCD::OPC_FilterValue, 49, 16, 0, // Skip to: 7496
/* 7480 */    MCD::OPC_CheckField, 16, 5, 0, 16, 14, // Skip to: 11086
/* 7486 */    MCD::OPC_CheckField, 6, 5, 0, 10, 14, // Skip to: 11086
/* 7492 */    MCD::OPC_Decode, 184, 4, 105, // Opcode: FRESo
/* 7496 */    MCD::OPC_FilterValue, 50, 10, 0, // Skip to: 7510
/* 7500 */    MCD::OPC_CheckField, 11, 5, 0, 252, 13, // Skip to: 11086
/* 7506 */    MCD::OPC_Decode, 163, 4, 106, // Opcode: FMULS
/* 7510 */    MCD::OPC_FilterValue, 51, 10, 0, // Skip to: 7524
/* 7514 */    MCD::OPC_CheckField, 11, 5, 0, 238, 13, // Skip to: 11086
/* 7520 */    MCD::OPC_Decode, 164, 4, 106, // Opcode: FMULSo
/* 7524 */    MCD::OPC_FilterValue, 52, 16, 0, // Skip to: 7544
/* 7528 */    MCD::OPC_CheckField, 16, 5, 0, 224, 13, // Skip to: 11086
/* 7534 */    MCD::OPC_CheckField, 6, 5, 0, 218, 13, // Skip to: 11086
/* 7540 */    MCD::OPC_Decode, 205, 4, 105, // Opcode: FRSQRTES
/* 7544 */    MCD::OPC_FilterValue, 53, 16, 0, // Skip to: 7564
/* 7548 */    MCD::OPC_CheckField, 16, 5, 0, 204, 13, // Skip to: 11086
/* 7554 */    MCD::OPC_CheckField, 6, 5, 0, 198, 13, // Skip to: 11086
/* 7560 */    MCD::OPC_Decode, 206, 4, 105, // Opcode: FRSQRTESo
/* 7564 */    MCD::OPC_FilterValue, 56, 4, 0, // Skip to: 7572
/* 7568 */    MCD::OPC_Decode, 159, 4, 107, // Opcode: FMSUBS
/* 7572 */    MCD::OPC_FilterValue, 57, 4, 0, // Skip to: 7580
/* 7576 */    MCD::OPC_Decode, 160, 4, 107, // Opcode: FMSUBSo
/* 7580 */    MCD::OPC_FilterValue, 58, 4, 0, // Skip to: 7588
/* 7584 */    MCD::OPC_Decode, 153, 4, 107, // Opcode: FMADDS
/* 7588 */    MCD::OPC_FilterValue, 59, 4, 0, // Skip to: 7596
/* 7592 */    MCD::OPC_Decode, 154, 4, 107, // Opcode: FMADDSo
/* 7596 */    MCD::OPC_FilterValue, 60, 4, 0, // Skip to: 7604
/* 7600 */    MCD::OPC_Decode, 179, 4, 107, // Opcode: FNMSUBS
/* 7604 */    MCD::OPC_FilterValue, 61, 4, 0, // Skip to: 7612
/* 7608 */    MCD::OPC_Decode, 180, 4, 107, // Opcode: FNMSUBSo
/* 7612 */    MCD::OPC_FilterValue, 62, 4, 0, // Skip to: 7620
/* 7616 */    MCD::OPC_Decode, 175, 4, 107, // Opcode: FNMADDS
/* 7620 */    MCD::OPC_FilterValue, 63, 134, 13, // Skip to: 11086
/* 7624 */    MCD::OPC_Decode, 176, 4, 107, // Opcode: FNMADDSo
/* 7628 */    MCD::OPC_FilterValue, 60, 48, 9, // Skip to: 9984
/* 7632 */    MCD::OPC_ExtractField, 4, 2,  // Inst{5-4} ...
/* 7635 */    MCD::OPC_FilterValue, 0, 164, 2, // Skip to: 8315
/* 7639 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 7642 */    MCD::OPC_FilterValue, 0, 19, 0, // Skip to: 7665
/* 7646 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7649 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7657
/* 7653 */    MCD::OPC_Decode, 186, 11, 108, // Opcode: XSADDSP
/* 7657 */    MCD::OPC_FilterValue, 1, 97, 13, // Skip to: 11086
/* 7661 */    MCD::OPC_Decode, 205, 11, 109, // Opcode: XSMADDASP
/* 7665 */    MCD::OPC_FilterValue, 1, 19, 0, // Skip to: 7688
/* 7669 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7672 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7680
/* 7676 */    MCD::OPC_Decode, 238, 11, 108, // Opcode: XSSUBSP
/* 7680 */    MCD::OPC_FilterValue, 1, 74, 13, // Skip to: 11086
/* 7684 */    MCD::OPC_Decode, 207, 11, 109, // Opcode: XSMADDMSP
/* 7688 */    MCD::OPC_FilterValue, 2, 19, 0, // Skip to: 7711
/* 7692 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7695 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7703
/* 7699 */    MCD::OPC_Decode, 215, 11, 108, // Opcode: XSMULSP
/* 7703 */    MCD::OPC_FilterValue, 1, 51, 13, // Skip to: 11086
/* 7707 */    MCD::OPC_Decode, 211, 11, 109, // Opcode: XSMSUBASP
/* 7711 */    MCD::OPC_FilterValue, 3, 19, 0, // Skip to: 7734
/* 7715 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7718 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7726
/* 7722 */    MCD::OPC_Decode, 203, 11, 108, // Opcode: XSDIVSP
/* 7726 */    MCD::OPC_FilterValue, 1, 28, 13, // Skip to: 11086
/* 7730 */    MCD::OPC_Decode, 213, 11, 109, // Opcode: XSMSUBMSP
/* 7734 */    MCD::OPC_FilterValue, 4, 19, 0, // Skip to: 7757
/* 7738 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7741 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7749
/* 7745 */    MCD::OPC_Decode, 185, 11, 110, // Opcode: XSADDDP
/* 7749 */    MCD::OPC_FilterValue, 1, 5, 13, // Skip to: 11086
/* 7753 */    MCD::OPC_Decode, 204, 11, 111, // Opcode: XSMADDADP
/* 7757 */    MCD::OPC_FilterValue, 5, 19, 0, // Skip to: 7780
/* 7761 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7764 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7772
/* 7768 */    MCD::OPC_Decode, 237, 11, 110, // Opcode: XSSUBDP
/* 7772 */    MCD::OPC_FilterValue, 1, 238, 12, // Skip to: 11086
/* 7776 */    MCD::OPC_Decode, 206, 11, 111, // Opcode: XSMADDMDP
/* 7780 */    MCD::OPC_FilterValue, 6, 19, 0, // Skip to: 7803
/* 7784 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7787 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7795
/* 7791 */    MCD::OPC_Decode, 214, 11, 110, // Opcode: XSMULDP
/* 7795 */    MCD::OPC_FilterValue, 1, 215, 12, // Skip to: 11086
/* 7799 */    MCD::OPC_Decode, 210, 11, 111, // Opcode: XSMSUBADP
/* 7803 */    MCD::OPC_FilterValue, 7, 19, 0, // Skip to: 7826
/* 7807 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7810 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7818
/* 7814 */    MCD::OPC_Decode, 202, 11, 110, // Opcode: XSDIVDP
/* 7818 */    MCD::OPC_FilterValue, 1, 192, 12, // Skip to: 11086
/* 7822 */    MCD::OPC_Decode, 212, 11, 111, // Opcode: XSMSUBMDP
/* 7826 */    MCD::OPC_FilterValue, 8, 19, 0, // Skip to: 7849
/* 7830 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7833 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7841
/* 7837 */    MCD::OPC_Decode, 244, 11, 112, // Opcode: XVADDSP
/* 7841 */    MCD::OPC_FilterValue, 1, 169, 12, // Skip to: 11086
/* 7845 */    MCD::OPC_Decode, 152, 12, 113, // Opcode: XVMADDASP
/* 7849 */    MCD::OPC_FilterValue, 9, 19, 0, // Skip to: 7872
/* 7853 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7856 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7864
/* 7860 */    MCD::OPC_Decode, 194, 12, 112, // Opcode: XVSUBSP
/* 7864 */    MCD::OPC_FilterValue, 1, 146, 12, // Skip to: 11086
/* 7868 */    MCD::OPC_Decode, 154, 12, 113, // Opcode: XVMADDMSP
/* 7872 */    MCD::OPC_FilterValue, 10, 19, 0, // Skip to: 7895
/* 7876 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7879 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7887
/* 7883 */    MCD::OPC_Decode, 164, 12, 112, // Opcode: XVMULSP
/* 7887 */    MCD::OPC_FilterValue, 1, 123, 12, // Skip to: 11086
/* 7891 */    MCD::OPC_Decode, 160, 12, 113, // Opcode: XVMSUBASP
/* 7895 */    MCD::OPC_FilterValue, 11, 19, 0, // Skip to: 7918
/* 7899 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7902 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7910
/* 7906 */    MCD::OPC_Decode, 150, 12, 112, // Opcode: XVDIVSP
/* 7910 */    MCD::OPC_FilterValue, 1, 100, 12, // Skip to: 11086
/* 7914 */    MCD::OPC_Decode, 162, 12, 113, // Opcode: XVMSUBMSP
/* 7918 */    MCD::OPC_FilterValue, 12, 19, 0, // Skip to: 7941
/* 7922 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7925 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7933
/* 7929 */    MCD::OPC_Decode, 243, 11, 112, // Opcode: XVADDDP
/* 7933 */    MCD::OPC_FilterValue, 1, 77, 12, // Skip to: 11086
/* 7937 */    MCD::OPC_Decode, 151, 12, 113, // Opcode: XVMADDADP
/* 7941 */    MCD::OPC_FilterValue, 13, 19, 0, // Skip to: 7964
/* 7945 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7948 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7956
/* 7952 */    MCD::OPC_Decode, 193, 12, 112, // Opcode: XVSUBDP
/* 7956 */    MCD::OPC_FilterValue, 1, 54, 12, // Skip to: 11086
/* 7960 */    MCD::OPC_Decode, 153, 12, 113, // Opcode: XVMADDMDP
/* 7964 */    MCD::OPC_FilterValue, 14, 19, 0, // Skip to: 7987
/* 7968 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7971 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 7979
/* 7975 */    MCD::OPC_Decode, 163, 12, 112, // Opcode: XVMULDP
/* 7979 */    MCD::OPC_FilterValue, 1, 31, 12, // Skip to: 11086
/* 7983 */    MCD::OPC_Decode, 159, 12, 113, // Opcode: XVMSUBADP
/* 7987 */    MCD::OPC_FilterValue, 15, 19, 0, // Skip to: 8010
/* 7991 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 7994 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8002
/* 7998 */    MCD::OPC_Decode, 149, 12, 112, // Opcode: XVDIVDP
/* 8002 */    MCD::OPC_FilterValue, 1, 8, 12, // Skip to: 11086
/* 8006 */    MCD::OPC_Decode, 161, 12, 113, // Opcode: XVMSUBMDP
/* 8010 */    MCD::OPC_FilterValue, 16, 10, 0, // Skip to: 8024
/* 8014 */    MCD::OPC_CheckField, 3, 1, 1, 250, 11, // Skip to: 11086
/* 8020 */    MCD::OPC_Decode, 219, 11, 109, // Opcode: XSNMADDASP
/* 8024 */    MCD::OPC_FilterValue, 17, 10, 0, // Skip to: 8038
/* 8028 */    MCD::OPC_CheckField, 3, 1, 1, 236, 11, // Skip to: 11086
/* 8034 */    MCD::OPC_Decode, 221, 11, 109, // Opcode: XSNMADDMSP
/* 8038 */    MCD::OPC_FilterValue, 18, 10, 0, // Skip to: 8052
/* 8042 */    MCD::OPC_CheckField, 3, 1, 1, 222, 11, // Skip to: 11086
/* 8048 */    MCD::OPC_Decode, 223, 11, 109, // Opcode: XSNMSUBASP
/* 8052 */    MCD::OPC_FilterValue, 19, 10, 0, // Skip to: 8066
/* 8056 */    MCD::OPC_CheckField, 3, 1, 1, 208, 11, // Skip to: 11086
/* 8062 */    MCD::OPC_Decode, 225, 11, 109, // Opcode: XSNMSUBMSP
/* 8066 */    MCD::OPC_FilterValue, 20, 19, 0, // Skip to: 8089
/* 8070 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8073 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8081
/* 8077 */    MCD::OPC_Decode, 208, 11, 110, // Opcode: XSMAXDP
/* 8081 */    MCD::OPC_FilterValue, 1, 185, 11, // Skip to: 11086
/* 8085 */    MCD::OPC_Decode, 218, 11, 111, // Opcode: XSNMADDADP
/* 8089 */    MCD::OPC_FilterValue, 21, 19, 0, // Skip to: 8112
/* 8093 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8096 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8104
/* 8100 */    MCD::OPC_Decode, 209, 11, 110, // Opcode: XSMINDP
/* 8104 */    MCD::OPC_FilterValue, 1, 162, 11, // Skip to: 11086
/* 8108 */    MCD::OPC_Decode, 220, 11, 111, // Opcode: XSNMADDMDP
/* 8112 */    MCD::OPC_FilterValue, 22, 19, 0, // Skip to: 8135
/* 8116 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8119 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8127
/* 8123 */    MCD::OPC_Decode, 189, 11, 110, // Opcode: XSCPSGNDP
/* 8127 */    MCD::OPC_FilterValue, 1, 139, 11, // Skip to: 11086
/* 8131 */    MCD::OPC_Decode, 222, 11, 111, // Opcode: XSNMSUBADP
/* 8135 */    MCD::OPC_FilterValue, 23, 10, 0, // Skip to: 8149
/* 8139 */    MCD::OPC_CheckField, 3, 1, 1, 125, 11, // Skip to: 11086
/* 8145 */    MCD::OPC_Decode, 224, 11, 111, // Opcode: XSNMSUBMDP
/* 8149 */    MCD::OPC_FilterValue, 24, 19, 0, // Skip to: 8172
/* 8153 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8156 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8164
/* 8160 */    MCD::OPC_Decode, 156, 12, 112, // Opcode: XVMAXSP
/* 8164 */    MCD::OPC_FilterValue, 1, 102, 11, // Skip to: 11086
/* 8168 */    MCD::OPC_Decode, 170, 12, 113, // Opcode: XVNMADDASP
/* 8172 */    MCD::OPC_FilterValue, 25, 19, 0, // Skip to: 8195
/* 8176 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8179 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8187
/* 8183 */    MCD::OPC_Decode, 158, 12, 112, // Opcode: XVMINSP
/* 8187 */    MCD::OPC_FilterValue, 1, 79, 11, // Skip to: 11086
/* 8191 */    MCD::OPC_Decode, 172, 12, 113, // Opcode: XVNMADDMSP
/* 8195 */    MCD::OPC_FilterValue, 26, 19, 0, // Skip to: 8218
/* 8199 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8202 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8210
/* 8206 */    MCD::OPC_Decode, 130, 12, 112, // Opcode: XVCPSGNSP
/* 8210 */    MCD::OPC_FilterValue, 1, 56, 11, // Skip to: 11086
/* 8214 */    MCD::OPC_Decode, 174, 12, 113, // Opcode: XVNMSUBASP
/* 8218 */    MCD::OPC_FilterValue, 27, 10, 0, // Skip to: 8232
/* 8222 */    MCD::OPC_CheckField, 3, 1, 1, 42, 11, // Skip to: 11086
/* 8228 */    MCD::OPC_Decode, 176, 12, 113, // Opcode: XVNMSUBMSP
/* 8232 */    MCD::OPC_FilterValue, 28, 19, 0, // Skip to: 8255
/* 8236 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8239 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8247
/* 8243 */    MCD::OPC_Decode, 155, 12, 112, // Opcode: XVMAXDP
/* 8247 */    MCD::OPC_FilterValue, 1, 19, 11, // Skip to: 11086
/* 8251 */    MCD::OPC_Decode, 169, 12, 113, // Opcode: XVNMADDADP
/* 8255 */    MCD::OPC_FilterValue, 29, 19, 0, // Skip to: 8278
/* 8259 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8262 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8270
/* 8266 */    MCD::OPC_Decode, 157, 12, 112, // Opcode: XVMINDP
/* 8270 */    MCD::OPC_FilterValue, 1, 252, 10, // Skip to: 11086
/* 8274 */    MCD::OPC_Decode, 171, 12, 113, // Opcode: XVNMADDMDP
/* 8278 */    MCD::OPC_FilterValue, 30, 19, 0, // Skip to: 8301
/* 8282 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8285 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8293
/* 8289 */    MCD::OPC_Decode, 129, 12, 112, // Opcode: XVCPSGNDP
/* 8293 */    MCD::OPC_FilterValue, 1, 229, 10, // Skip to: 11086
/* 8297 */    MCD::OPC_Decode, 173, 12, 113, // Opcode: XVNMSUBADP
/* 8301 */    MCD::OPC_FilterValue, 31, 221, 10, // Skip to: 11086
/* 8305 */    MCD::OPC_CheckField, 3, 1, 1, 215, 10, // Skip to: 11086
/* 8311 */    MCD::OPC_Decode, 175, 12, 113, // Opcode: XVNMSUBMDP
/* 8315 */    MCD::OPC_FilterValue, 1, 130, 1, // Skip to: 8705
/* 8319 */    MCD::OPC_ExtractField, 6, 2,  // Inst{7-6} ...
/* 8322 */    MCD::OPC_FilterValue, 0, 100, 0, // Skip to: 8426
/* 8326 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8329 */    MCD::OPC_FilterValue, 0, 34, 0, // Skip to: 8367
/* 8333 */    MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 8336 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8344
/* 8340 */    MCD::OPC_Decode, 212, 12, 114, // Opcode: XXSLDWI
/* 8344 */    MCD::OPC_FilterValue, 1, 178, 10, // Skip to: 11086
/* 8348 */    MCD::OPC_ExtractField, 8, 2,  // Inst{9-8} ...
/* 8351 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8359
/* 8355 */    MCD::OPC_Decode, 199, 12, 112, // Opcode: XXLAND
/* 8359 */    MCD::OPC_FilterValue, 1, 163, 10, // Skip to: 11086
/* 8363 */    MCD::OPC_Decode, 203, 12, 112, // Opcode: XXLNOR
/* 8367 */    MCD::OPC_FilterValue, 1, 155, 10, // Skip to: 11086
/* 8371 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 8374 */    MCD::OPC_FilterValue, 1, 16, 0, // Skip to: 8394
/* 8378 */    MCD::OPC_CheckField, 21, 2, 0, 142, 10, // Skip to: 11086
/* 8384 */    MCD::OPC_CheckField, 0, 1, 0, 136, 10, // Skip to: 11086
/* 8390 */    MCD::OPC_Decode, 188, 11, 115, // Opcode: XSCMPUDP
/* 8394 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 8402
/* 8398 */    MCD::OPC_Decode, 247, 11, 112, // Opcode: XVCMPEQSP
/* 8402 */    MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 8410
/* 8406 */    MCD::OPC_Decode, 245, 11, 112, // Opcode: XVCMPEQDP
/* 8410 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 8418
/* 8414 */    MCD::OPC_Decode, 248, 11, 112, // Opcode: XVCMPEQSPo
/* 8418 */    MCD::OPC_FilterValue, 7, 104, 10, // Skip to: 11086
/* 8422 */    MCD::OPC_Decode, 246, 11, 112, // Opcode: XVCMPEQDPo
/* 8426 */    MCD::OPC_FilterValue, 1, 100, 0, // Skip to: 8530
/* 8430 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8433 */    MCD::OPC_FilterValue, 0, 34, 0, // Skip to: 8471
/* 8437 */    MCD::OPC_ExtractField, 10, 1,  // Inst{10} ...
/* 8440 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8448
/* 8444 */    MCD::OPC_Decode, 210, 12, 114, // Opcode: XXPERMDI
/* 8448 */    MCD::OPC_FilterValue, 1, 74, 10, // Skip to: 11086
/* 8452 */    MCD::OPC_ExtractField, 8, 2,  // Inst{9-8} ...
/* 8455 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 8463
/* 8459 */    MCD::OPC_Decode, 200, 12, 112, // Opcode: XXLANDC
/* 8463 */    MCD::OPC_FilterValue, 1, 59, 10, // Skip to: 11086
/* 8467 */    MCD::OPC_Decode, 205, 12, 112, // Opcode: XXLORC
/* 8471 */    MCD::OPC_FilterValue, 1, 51, 10, // Skip to: 11086
/* 8475 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 8478 */    MCD::OPC_FilterValue, 1, 16, 0, // Skip to: 8498
/* 8482 */    MCD::OPC_CheckField, 21, 2, 0, 38, 10, // Skip to: 11086
/* 8488 */    MCD::OPC_CheckField, 0, 1, 0, 32, 10, // Skip to: 11086
/* 8494 */    MCD::OPC_Decode, 187, 11, 115, // Opcode: XSCMPODP
/* 8498 */    MCD::OPC_FilterValue, 2, 4, 0, // Skip to: 8506
/* 8502 */    MCD::OPC_Decode, 255, 11, 112, // Opcode: XVCMPGTSP
/* 8506 */    MCD::OPC_FilterValue, 3, 4, 0, // Skip to: 8514
/* 8510 */    MCD::OPC_Decode, 253, 11, 112, // Opcode: XVCMPGTDP
/* 8514 */    MCD::OPC_FilterValue, 6, 4, 0, // Skip to: 8522
/* 8518 */    MCD::OPC_Decode, 128, 12, 112, // Opcode: XVCMPGTSPo
/* 8522 */    MCD::OPC_FilterValue, 7, 0, 10, // Skip to: 11086
/* 8526 */    MCD::OPC_Decode, 254, 11, 112, // Opcode: XVCMPGTDPo
/* 8530 */    MCD::OPC_FilterValue, 2, 136, 0, // Skip to: 8670
/* 8534 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 8537 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 8551
/* 8541 */    MCD::OPC_CheckField, 3, 1, 0, 235, 9, // Skip to: 11086
/* 8547 */    MCD::OPC_Decode, 208, 12, 112, // Opcode: XXMRGHW
/* 8551 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 8565
/* 8555 */    MCD::OPC_CheckField, 3, 1, 0, 221, 9, // Skip to: 11086
/* 8561 */    MCD::OPC_Decode, 209, 12, 112, // Opcode: XXMRGLW
/* 8565 */    MCD::OPC_FilterValue, 2, 31, 0, // Skip to: 8600
/* 8569 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8572 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 8592
/* 8576 */    MCD::OPC_CheckField, 18, 3, 0, 200, 9, // Skip to: 11086
/* 8582 */    MCD::OPC_CheckField, 2, 1, 0, 194, 9, // Skip to: 11086
/* 8588 */    MCD::OPC_Decode, 213, 12, 116, // Opcode: XXSPLTW
/* 8592 */    MCD::OPC_FilterValue, 1, 186, 9, // Skip to: 11086
/* 8596 */    MCD::OPC_Decode, 251, 11, 112, // Opcode: XVCMPGESP
/* 8600 */    MCD::OPC_FilterValue, 3, 10, 0, // Skip to: 8614
/* 8604 */    MCD::OPC_CheckField, 3, 1, 1, 172, 9, // Skip to: 11086
/* 8610 */    MCD::OPC_Decode, 249, 11, 112, // Opcode: XVCMPGEDP
/* 8614 */    MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 8628
/* 8618 */    MCD::OPC_CheckField, 3, 1, 0, 158, 9, // Skip to: 11086
/* 8624 */    MCD::OPC_Decode, 204, 12, 112, // Opcode: XXLOR
/* 8628 */    MCD::OPC_FilterValue, 5, 10, 0, // Skip to: 8642
/* 8632 */    MCD::OPC_CheckField, 3, 1, 0, 144, 9, // Skip to: 11086
/* 8638 */    MCD::OPC_Decode, 202, 12, 112, // Opcode: XXLNAND
/* 8642 */    MCD::OPC_FilterValue, 6, 10, 0, // Skip to: 8656
/* 8646 */    MCD::OPC_CheckField, 3, 1, 1, 130, 9, // Skip to: 11086
/* 8652 */    MCD::OPC_Decode, 252, 11, 112, // Opcode: XVCMPGESPo
/* 8656 */    MCD::OPC_FilterValue, 7, 122, 9, // Skip to: 11086
/* 8660 */    MCD::OPC_CheckField, 3, 1, 1, 116, 9, // Skip to: 11086
/* 8666 */    MCD::OPC_Decode, 250, 11, 112, // Opcode: XVCMPGEDPo
/* 8670 */    MCD::OPC_FilterValue, 3, 108, 9, // Skip to: 11086
/* 8674 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 8677 */    MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 8691
/* 8681 */    MCD::OPC_CheckField, 3, 1, 0, 95, 9, // Skip to: 11086
/* 8687 */    MCD::OPC_Decode, 207, 12, 112, // Opcode: XXLXOR
/* 8691 */    MCD::OPC_FilterValue, 5, 87, 9, // Skip to: 11086
/* 8695 */    MCD::OPC_CheckField, 3, 1, 0, 81, 9, // Skip to: 11086
/* 8701 */    MCD::OPC_Decode, 201, 12, 112, // Opcode: XXLEQV
/* 8705 */    MCD::OPC_FilterValue, 2, 243, 4, // Skip to: 9976
/* 8709 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 8712 */    MCD::OPC_FilterValue, 0, 31, 0, // Skip to: 8747
/* 8716 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 8719 */    MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 8733
/* 8723 */    MCD::OPC_CheckField, 16, 5, 0, 53, 9, // Skip to: 11086
/* 8729 */    MCD::OPC_Decode, 234, 11, 117, // Opcode: XSRSQRTESP
/* 8733 */    MCD::OPC_FilterValue, 3, 45, 9, // Skip to: 11086
/* 8737 */    MCD::OPC_CheckField, 16, 5, 0, 39, 9, // Skip to: 11086
/* 8743 */    MCD::OPC_Decode, 236, 11, 117, // Opcode: XSSQRTSP
/* 8747 */    MCD::OPC_FilterValue, 1, 16, 0, // Skip to: 8767
/* 8751 */    MCD::OPC_CheckField, 16, 5, 0, 25, 9, // Skip to: 11086
/* 8757 */    MCD::OPC_CheckField, 2, 2, 2, 19, 9, // Skip to: 11086
/* 8763 */    MCD::OPC_Decode, 232, 11, 117, // Opcode: XSRESP
/* 8767 */    MCD::OPC_FilterValue, 4, 59, 0, // Skip to: 8830
/* 8771 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 8774 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 8788
/* 8778 */    MCD::OPC_CheckField, 16, 5, 0, 254, 8, // Skip to: 11086
/* 8784 */    MCD::OPC_Decode, 195, 11, 118, // Opcode: XSCVDPUXWS
/* 8788 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 8802
/* 8792 */    MCD::OPC_CheckField, 16, 5, 0, 240, 8, // Skip to: 11086
/* 8798 */    MCD::OPC_Decode, 226, 11, 118, // Opcode: XSRDPI
/* 8802 */    MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 8816
/* 8806 */    MCD::OPC_CheckField, 16, 5, 0, 226, 8, // Skip to: 11086
/* 8812 */    MCD::OPC_Decode, 233, 11, 118, // Opcode: XSRSQRTEDP
/* 8816 */    MCD::OPC_FilterValue, 3, 218, 8, // Skip to: 11086
/* 8820 */    MCD::OPC_CheckField, 16, 5, 0, 212, 8, // Skip to: 11086
/* 8826 */    MCD::OPC_Decode, 235, 11, 118, // Opcode: XSSQRTDP
/* 8830 */    MCD::OPC_FilterValue, 5, 45, 0, // Skip to: 8879
/* 8834 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 8837 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 8851
/* 8841 */    MCD::OPC_CheckField, 16, 5, 0, 191, 8, // Skip to: 11086
/* 8847 */    MCD::OPC_Decode, 193, 11, 118, // Opcode: XSCVDPSXWS
/* 8851 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 8865
/* 8855 */    MCD::OPC_CheckField, 16, 5, 0, 177, 8, // Skip to: 11086
/* 8861 */    MCD::OPC_Decode, 230, 11, 118, // Opcode: XSRDPIZ
/* 8865 */    MCD::OPC_FilterValue, 2, 169, 8, // Skip to: 11086
/* 8869 */    MCD::OPC_CheckField, 16, 5, 0, 163, 8, // Skip to: 11086
/* 8875 */    MCD::OPC_Decode, 231, 11, 118, // Opcode: XSREDP
/* 8879 */    MCD::OPC_FilterValue, 6, 51, 0, // Skip to: 8934
/* 8883 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 8886 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 8900
/* 8890 */    MCD::OPC_CheckField, 16, 5, 0, 142, 8, // Skip to: 11086
/* 8896 */    MCD::OPC_Decode, 229, 11, 118, // Opcode: XSRDPIP
/* 8900 */    MCD::OPC_FilterValue, 2, 16, 0, // Skip to: 8920
/* 8904 */    MCD::OPC_CheckField, 16, 7, 0, 128, 8, // Skip to: 11086
/* 8910 */    MCD::OPC_CheckField, 0, 1, 0, 122, 8, // Skip to: 11086
/* 8916 */    MCD::OPC_Decode, 240, 11, 119, // Opcode: XSTSQRTDP
/* 8920 */    MCD::OPC_FilterValue, 3, 114, 8, // Skip to: 11086
/* 8924 */    MCD::OPC_CheckField, 16, 5, 0, 108, 8, // Skip to: 11086
/* 8930 */    MCD::OPC_Decode, 227, 11, 118, // Opcode: XSRDPIC
/* 8934 */    MCD::OPC_FilterValue, 7, 43, 0, // Skip to: 8981
/* 8938 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 8941 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 8961
/* 8945 */    MCD::OPC_CheckField, 16, 5, 0, 87, 8, // Skip to: 11086
/* 8951 */    MCD::OPC_CheckField, 2, 1, 1, 81, 8, // Skip to: 11086
/* 8957 */    MCD::OPC_Decode, 228, 11, 118, // Opcode: XSRDPIM
/* 8961 */    MCD::OPC_FilterValue, 1, 73, 8, // Skip to: 11086
/* 8965 */    MCD::OPC_CheckField, 21, 2, 0, 67, 8, // Skip to: 11086
/* 8971 */    MCD::OPC_CheckField, 0, 1, 0, 61, 8, // Skip to: 11086
/* 8977 */    MCD::OPC_Decode, 239, 11, 115, // Opcode: XSTDIVDP
/* 8981 */    MCD::OPC_FilterValue, 8, 59, 0, // Skip to: 9044
/* 8985 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 8988 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9002
/* 8992 */    MCD::OPC_CheckField, 16, 5, 0, 40, 8, // Skip to: 11086
/* 8998 */    MCD::OPC_Decode, 140, 12, 120, // Opcode: XVCVSPUXWS
/* 9002 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 9016
/* 9006 */    MCD::OPC_CheckField, 16, 5, 0, 26, 8, // Skip to: 11086
/* 9012 */    MCD::OPC_Decode, 184, 12, 120, // Opcode: XVRSPI
/* 9016 */    MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 9030
/* 9020 */    MCD::OPC_CheckField, 16, 5, 0, 12, 8, // Skip to: 11086
/* 9026 */    MCD::OPC_Decode, 190, 12, 120, // Opcode: XVRSQRTESP
/* 9030 */    MCD::OPC_FilterValue, 3, 4, 8, // Skip to: 11086
/* 9034 */    MCD::OPC_CheckField, 16, 5, 0, 254, 7, // Skip to: 11086
/* 9040 */    MCD::OPC_Decode, 192, 12, 120, // Opcode: XVSQRTSP
/* 9044 */    MCD::OPC_FilterValue, 9, 45, 0, // Skip to: 9093
/* 9048 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9051 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9065
/* 9055 */    MCD::OPC_CheckField, 16, 5, 0, 233, 7, // Skip to: 11086
/* 9061 */    MCD::OPC_Decode, 138, 12, 120, // Opcode: XVCVSPSXWS
/* 9065 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 9079
/* 9069 */    MCD::OPC_CheckField, 16, 5, 0, 219, 7, // Skip to: 11086
/* 9075 */    MCD::OPC_Decode, 188, 12, 120, // Opcode: XVRSPIZ
/* 9079 */    MCD::OPC_FilterValue, 2, 211, 7, // Skip to: 11086
/* 9083 */    MCD::OPC_CheckField, 16, 5, 0, 205, 7, // Skip to: 11086
/* 9089 */    MCD::OPC_Decode, 183, 12, 120, // Opcode: XVRESP
/* 9093 */    MCD::OPC_FilterValue, 10, 65, 0, // Skip to: 9162
/* 9097 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9100 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9114
/* 9104 */    MCD::OPC_CheckField, 16, 5, 0, 184, 7, // Skip to: 11086
/* 9110 */    MCD::OPC_Decode, 148, 12, 120, // Opcode: XVCVUXWSP
/* 9114 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 9128
/* 9118 */    MCD::OPC_CheckField, 16, 5, 0, 170, 7, // Skip to: 11086
/* 9124 */    MCD::OPC_Decode, 187, 12, 120, // Opcode: XVRSPIP
/* 9128 */    MCD::OPC_FilterValue, 2, 16, 0, // Skip to: 9148
/* 9132 */    MCD::OPC_CheckField, 16, 7, 0, 156, 7, // Skip to: 11086
/* 9138 */    MCD::OPC_CheckField, 0, 1, 0, 150, 7, // Skip to: 11086
/* 9144 */    MCD::OPC_Decode, 198, 12, 121, // Opcode: XVTSQRTSP
/* 9148 */    MCD::OPC_FilterValue, 3, 142, 7, // Skip to: 11086
/* 9152 */    MCD::OPC_CheckField, 16, 5, 0, 136, 7, // Skip to: 11086
/* 9158 */    MCD::OPC_Decode, 185, 12, 120, // Opcode: XVRSPIC
/* 9162 */    MCD::OPC_FilterValue, 11, 58, 0, // Skip to: 9224
/* 9166 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 9169 */    MCD::OPC_FilterValue, 0, 31, 0, // Skip to: 9204
/* 9173 */    MCD::OPC_ExtractField, 2, 1,  // Inst{2} ...
/* 9176 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9190
/* 9180 */    MCD::OPC_CheckField, 16, 5, 0, 108, 7, // Skip to: 11086
/* 9186 */    MCD::OPC_Decode, 144, 12, 120, // Opcode: XVCVSXWSP
/* 9190 */    MCD::OPC_FilterValue, 1, 100, 7, // Skip to: 11086
/* 9194 */    MCD::OPC_CheckField, 16, 5, 0, 94, 7, // Skip to: 11086
/* 9200 */    MCD::OPC_Decode, 186, 12, 120, // Opcode: XVRSPIM
/* 9204 */    MCD::OPC_FilterValue, 1, 86, 7, // Skip to: 11086
/* 9208 */    MCD::OPC_CheckField, 21, 2, 0, 80, 7, // Skip to: 11086
/* 9214 */    MCD::OPC_CheckField, 0, 1, 0, 74, 7, // Skip to: 11086
/* 9220 */    MCD::OPC_Decode, 196, 12, 122, // Opcode: XVTDIVSP
/* 9224 */    MCD::OPC_FilterValue, 12, 59, 0, // Skip to: 9287
/* 9228 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9231 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9245
/* 9235 */    MCD::OPC_CheckField, 16, 5, 0, 53, 7, // Skip to: 11086
/* 9241 */    MCD::OPC_Decode, 135, 12, 120, // Opcode: XVCVDPUXWS
/* 9245 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 9259
/* 9249 */    MCD::OPC_CheckField, 16, 5, 0, 39, 7, // Skip to: 11086
/* 9255 */    MCD::OPC_Decode, 177, 12, 120, // Opcode: XVRDPI
/* 9259 */    MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 9273
/* 9263 */    MCD::OPC_CheckField, 16, 5, 0, 25, 7, // Skip to: 11086
/* 9269 */    MCD::OPC_Decode, 189, 12, 120, // Opcode: XVRSQRTEDP
/* 9273 */    MCD::OPC_FilterValue, 3, 17, 7, // Skip to: 11086
/* 9277 */    MCD::OPC_CheckField, 16, 5, 0, 11, 7, // Skip to: 11086
/* 9283 */    MCD::OPC_Decode, 191, 12, 120, // Opcode: XVSQRTDP
/* 9287 */    MCD::OPC_FilterValue, 13, 45, 0, // Skip to: 9336
/* 9291 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9294 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9308
/* 9298 */    MCD::OPC_CheckField, 16, 5, 0, 246, 6, // Skip to: 11086
/* 9304 */    MCD::OPC_Decode, 133, 12, 120, // Opcode: XVCVDPSXWS
/* 9308 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 9322
/* 9312 */    MCD::OPC_CheckField, 16, 5, 0, 232, 6, // Skip to: 11086
/* 9318 */    MCD::OPC_Decode, 181, 12, 120, // Opcode: XVRDPIZ
/* 9322 */    MCD::OPC_FilterValue, 2, 224, 6, // Skip to: 11086
/* 9326 */    MCD::OPC_CheckField, 16, 5, 0, 218, 6, // Skip to: 11086
/* 9332 */    MCD::OPC_Decode, 182, 12, 120, // Opcode: XVREDP
/* 9336 */    MCD::OPC_FilterValue, 14, 65, 0, // Skip to: 9405
/* 9340 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9343 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9357
/* 9347 */    MCD::OPC_CheckField, 16, 5, 0, 197, 6, // Skip to: 11086
/* 9353 */    MCD::OPC_Decode, 147, 12, 120, // Opcode: XVCVUXWDP
/* 9357 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 9371
/* 9361 */    MCD::OPC_CheckField, 16, 5, 0, 183, 6, // Skip to: 11086
/* 9367 */    MCD::OPC_Decode, 180, 12, 120, // Opcode: XVRDPIP
/* 9371 */    MCD::OPC_FilterValue, 2, 16, 0, // Skip to: 9391
/* 9375 */    MCD::OPC_CheckField, 16, 7, 0, 169, 6, // Skip to: 11086
/* 9381 */    MCD::OPC_CheckField, 0, 1, 0, 163, 6, // Skip to: 11086
/* 9387 */    MCD::OPC_Decode, 197, 12, 121, // Opcode: XVTSQRTDP
/* 9391 */    MCD::OPC_FilterValue, 3, 155, 6, // Skip to: 11086
/* 9395 */    MCD::OPC_CheckField, 16, 5, 0, 149, 6, // Skip to: 11086
/* 9401 */    MCD::OPC_Decode, 178, 12, 120, // Opcode: XVRDPIC
/* 9405 */    MCD::OPC_FilterValue, 15, 58, 0, // Skip to: 9467
/* 9409 */    MCD::OPC_ExtractField, 3, 1,  // Inst{3} ...
/* 9412 */    MCD::OPC_FilterValue, 0, 31, 0, // Skip to: 9447
/* 9416 */    MCD::OPC_ExtractField, 2, 1,  // Inst{2} ...
/* 9419 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9433
/* 9423 */    MCD::OPC_CheckField, 16, 5, 0, 121, 6, // Skip to: 11086
/* 9429 */    MCD::OPC_Decode, 143, 12, 120, // Opcode: XVCVSXWDP
/* 9433 */    MCD::OPC_FilterValue, 1, 113, 6, // Skip to: 11086
/* 9437 */    MCD::OPC_CheckField, 16, 5, 0, 107, 6, // Skip to: 11086
/* 9443 */    MCD::OPC_Decode, 179, 12, 120, // Opcode: XVRDPIM
/* 9447 */    MCD::OPC_FilterValue, 1, 99, 6, // Skip to: 11086
/* 9451 */    MCD::OPC_CheckField, 21, 2, 0, 93, 6, // Skip to: 11086
/* 9457 */    MCD::OPC_CheckField, 0, 1, 0, 87, 6, // Skip to: 11086
/* 9463 */    MCD::OPC_Decode, 195, 12, 122, // Opcode: XVTDIVDP
/* 9467 */    MCD::OPC_FilterValue, 16, 31, 0, // Skip to: 9502
/* 9471 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9474 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 9488
/* 9478 */    MCD::OPC_CheckField, 16, 5, 0, 66, 6, // Skip to: 11086
/* 9484 */    MCD::OPC_Decode, 190, 11, 118, // Opcode: XSCVDPSP
/* 9488 */    MCD::OPC_FilterValue, 3, 58, 6, // Skip to: 11086
/* 9492 */    MCD::OPC_CheckField, 16, 5, 0, 52, 6, // Skip to: 11086
/* 9498 */    MCD::OPC_Decode, 191, 11, 123, // Opcode: XSCVDPSPN
/* 9502 */    MCD::OPC_FilterValue, 18, 16, 0, // Skip to: 9522
/* 9506 */    MCD::OPC_CheckField, 16, 5, 0, 38, 6, // Skip to: 11086
/* 9512 */    MCD::OPC_CheckField, 2, 2, 0, 32, 6, // Skip to: 11086
/* 9518 */    MCD::OPC_Decode, 201, 11, 124, // Opcode: XSCVUXDSP
/* 9522 */    MCD::OPC_FilterValue, 19, 16, 0, // Skip to: 9542
/* 9526 */    MCD::OPC_CheckField, 16, 5, 0, 18, 6, // Skip to: 11086
/* 9532 */    MCD::OPC_CheckField, 2, 2, 0, 12, 6, // Skip to: 11086
/* 9538 */    MCD::OPC_Decode, 199, 11, 124, // Opcode: XSCVSXDSP
/* 9542 */    MCD::OPC_FilterValue, 20, 45, 0, // Skip to: 9591
/* 9546 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9549 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9563
/* 9553 */    MCD::OPC_CheckField, 16, 5, 0, 247, 5, // Skip to: 11086
/* 9559 */    MCD::OPC_Decode, 194, 11, 118, // Opcode: XSCVDPUXDS
/* 9563 */    MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 9577
/* 9567 */    MCD::OPC_CheckField, 16, 5, 0, 233, 5, // Skip to: 11086
/* 9573 */    MCD::OPC_Decode, 196, 11, 118, // Opcode: XSCVSPDP
/* 9577 */    MCD::OPC_FilterValue, 3, 225, 5, // Skip to: 11086
/* 9581 */    MCD::OPC_CheckField, 16, 5, 0, 219, 5, // Skip to: 11086
/* 9587 */    MCD::OPC_Decode, 197, 11, 125, // Opcode: XSCVSPDPN
/* 9591 */    MCD::OPC_FilterValue, 21, 31, 0, // Skip to: 9626
/* 9595 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9598 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9612
/* 9602 */    MCD::OPC_CheckField, 16, 5, 0, 198, 5, // Skip to: 11086
/* 9608 */    MCD::OPC_Decode, 192, 11, 118, // Opcode: XSCVDPSXDS
/* 9612 */    MCD::OPC_FilterValue, 1, 190, 5, // Skip to: 11086
/* 9616 */    MCD::OPC_CheckField, 16, 5, 0, 184, 5, // Skip to: 11086
/* 9622 */    MCD::OPC_Decode, 184, 11, 118, // Opcode: XSABSDP
/* 9626 */    MCD::OPC_FilterValue, 22, 31, 0, // Skip to: 9661
/* 9630 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9633 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9647
/* 9637 */    MCD::OPC_CheckField, 16, 5, 0, 163, 5, // Skip to: 11086
/* 9643 */    MCD::OPC_Decode, 200, 11, 118, // Opcode: XSCVUXDDP
/* 9647 */    MCD::OPC_FilterValue, 1, 155, 5, // Skip to: 11086
/* 9651 */    MCD::OPC_CheckField, 16, 5, 0, 149, 5, // Skip to: 11086
/* 9657 */    MCD::OPC_Decode, 216, 11, 118, // Opcode: XSNABSDP
/* 9661 */    MCD::OPC_FilterValue, 23, 31, 0, // Skip to: 9696
/* 9665 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9668 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9682
/* 9672 */    MCD::OPC_CheckField, 16, 5, 0, 128, 5, // Skip to: 11086
/* 9678 */    MCD::OPC_Decode, 198, 11, 118, // Opcode: XSCVSXDDP
/* 9682 */    MCD::OPC_FilterValue, 1, 120, 5, // Skip to: 11086
/* 9686 */    MCD::OPC_CheckField, 16, 5, 0, 114, 5, // Skip to: 11086
/* 9692 */    MCD::OPC_Decode, 217, 11, 118, // Opcode: XSNEGDP
/* 9696 */    MCD::OPC_FilterValue, 24, 31, 0, // Skip to: 9731
/* 9700 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9703 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9717
/* 9707 */    MCD::OPC_CheckField, 16, 5, 0, 93, 5, // Skip to: 11086
/* 9713 */    MCD::OPC_Decode, 139, 12, 120, // Opcode: XVCVSPUXDS
/* 9717 */    MCD::OPC_FilterValue, 1, 85, 5, // Skip to: 11086
/* 9721 */    MCD::OPC_CheckField, 16, 5, 0, 79, 5, // Skip to: 11086
/* 9727 */    MCD::OPC_Decode, 131, 12, 120, // Opcode: XVCVDPSP
/* 9731 */    MCD::OPC_FilterValue, 25, 31, 0, // Skip to: 9766
/* 9735 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9738 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9752
/* 9742 */    MCD::OPC_CheckField, 16, 5, 0, 58, 5, // Skip to: 11086
/* 9748 */    MCD::OPC_Decode, 137, 12, 120, // Opcode: XVCVSPSXDS
/* 9752 */    MCD::OPC_FilterValue, 1, 50, 5, // Skip to: 11086
/* 9756 */    MCD::OPC_CheckField, 16, 5, 0, 44, 5, // Skip to: 11086
/* 9762 */    MCD::OPC_Decode, 242, 11, 120, // Opcode: XVABSSP
/* 9766 */    MCD::OPC_FilterValue, 26, 31, 0, // Skip to: 9801
/* 9770 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9773 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9787
/* 9777 */    MCD::OPC_CheckField, 16, 5, 0, 23, 5, // Skip to: 11086
/* 9783 */    MCD::OPC_Decode, 146, 12, 120, // Opcode: XVCVUXDSP
/* 9787 */    MCD::OPC_FilterValue, 1, 15, 5, // Skip to: 11086
/* 9791 */    MCD::OPC_CheckField, 16, 5, 0, 9, 5, // Skip to: 11086
/* 9797 */    MCD::OPC_Decode, 166, 12, 120, // Opcode: XVNABSSP
/* 9801 */    MCD::OPC_FilterValue, 27, 31, 0, // Skip to: 9836
/* 9805 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9808 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9822
/* 9812 */    MCD::OPC_CheckField, 16, 5, 0, 244, 4, // Skip to: 11086
/* 9818 */    MCD::OPC_Decode, 142, 12, 120, // Opcode: XVCVSXDSP
/* 9822 */    MCD::OPC_FilterValue, 1, 236, 4, // Skip to: 11086
/* 9826 */    MCD::OPC_CheckField, 16, 5, 0, 230, 4, // Skip to: 11086
/* 9832 */    MCD::OPC_Decode, 168, 12, 120, // Opcode: XVNEGSP
/* 9836 */    MCD::OPC_FilterValue, 28, 31, 0, // Skip to: 9871
/* 9840 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9843 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9857
/* 9847 */    MCD::OPC_CheckField, 16, 5, 0, 209, 4, // Skip to: 11086
/* 9853 */    MCD::OPC_Decode, 134, 12, 120, // Opcode: XVCVDPUXDS
/* 9857 */    MCD::OPC_FilterValue, 1, 201, 4, // Skip to: 11086
/* 9861 */    MCD::OPC_CheckField, 16, 5, 0, 195, 4, // Skip to: 11086
/* 9867 */    MCD::OPC_Decode, 136, 12, 120, // Opcode: XVCVSPDP
/* 9871 */    MCD::OPC_FilterValue, 29, 31, 0, // Skip to: 9906
/* 9875 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9878 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9892
/* 9882 */    MCD::OPC_CheckField, 16, 5, 0, 174, 4, // Skip to: 11086
/* 9888 */    MCD::OPC_Decode, 132, 12, 120, // Opcode: XVCVDPSXDS
/* 9892 */    MCD::OPC_FilterValue, 1, 166, 4, // Skip to: 11086
/* 9896 */    MCD::OPC_CheckField, 16, 5, 0, 160, 4, // Skip to: 11086
/* 9902 */    MCD::OPC_Decode, 241, 11, 120, // Opcode: XVABSDP
/* 9906 */    MCD::OPC_FilterValue, 30, 31, 0, // Skip to: 9941
/* 9910 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9913 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9927
/* 9917 */    MCD::OPC_CheckField, 16, 5, 0, 139, 4, // Skip to: 11086
/* 9923 */    MCD::OPC_Decode, 145, 12, 120, // Opcode: XVCVUXDDP
/* 9927 */    MCD::OPC_FilterValue, 1, 131, 4, // Skip to: 11086
/* 9931 */    MCD::OPC_CheckField, 16, 5, 0, 125, 4, // Skip to: 11086
/* 9937 */    MCD::OPC_Decode, 165, 12, 120, // Opcode: XVNABSDP
/* 9941 */    MCD::OPC_FilterValue, 31, 117, 4, // Skip to: 11086
/* 9945 */    MCD::OPC_ExtractField, 2, 2,  // Inst{3-2} ...
/* 9948 */    MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 9962
/* 9952 */    MCD::OPC_CheckField, 16, 5, 0, 104, 4, // Skip to: 11086
/* 9958 */    MCD::OPC_Decode, 141, 12, 120, // Opcode: XVCVSXDDP
/* 9962 */    MCD::OPC_FilterValue, 1, 96, 4, // Skip to: 11086
/* 9966 */    MCD::OPC_CheckField, 16, 5, 0, 90, 4, // Skip to: 11086
/* 9972 */    MCD::OPC_Decode, 167, 12, 120, // Opcode: XVNEGDP
/* 9976 */    MCD::OPC_FilterValue, 3, 82, 4, // Skip to: 11086
/* 9980 */    MCD::OPC_Decode, 211, 12, 126, // Opcode: XXSEL
/* 9984 */    MCD::OPC_FilterValue, 62, 19, 0, // Skip to: 10007
/* 9988 */    MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 9991 */    MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 9999
/* 9995 */    MCD::OPC_Decode, 208, 8, 102, // Opcode: STD
/* 9999 */    MCD::OPC_FilterValue, 1, 59, 4, // Skip to: 11086
/* 10003 */   MCD::OPC_Decode, 212, 8, 102, // Opcode: STDU
/* 10007 */   MCD::OPC_FilterValue, 63, 51, 4, // Skip to: 11086
/* 10011 */   MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 10014 */   MCD::OPC_FilterValue, 0, 37, 0, // Skip to: 10055
/* 10018 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10021 */   MCD::OPC_FilterValue, 0, 10, 0, // Skip to: 10035
/* 10025 */   MCD::OPC_CheckField, 21, 2, 0, 31, 4, // Skip to: 11086
/* 10031 */   MCD::OPC_Decode, 131, 4, 127, // Opcode: FCMPUS
/* 10035 */   MCD::OPC_FilterValue, 2, 23, 4, // Skip to: 11086
/* 10039 */   MCD::OPC_CheckField, 21, 2, 0, 17, 4, // Skip to: 11086
/* 10045 */   MCD::OPC_CheckField, 11, 7, 0, 11, 4, // Skip to: 11086
/* 10051 */   MCD::OPC_Decode, 208, 5, 25, // Opcode: MCRFS
/* 10055 */   MCD::OPC_FilterValue, 12, 46, 0, // Skip to: 10105
/* 10059 */   MCD::OPC_ExtractField, 6, 6,  // Inst{11-6} ...
/* 10062 */   MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 10076
/* 10066 */   MCD::OPC_CheckField, 12, 9, 0, 246, 3, // Skip to: 11086
/* 10072 */   MCD::OPC_Decode, 242, 5, 91, // Opcode: MTFSB1
/* 10076 */   MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 10090
/* 10080 */   MCD::OPC_CheckField, 12, 9, 0, 232, 3, // Skip to: 11086
/* 10086 */   MCD::OPC_Decode, 241, 5, 91, // Opcode: MTFSB0
/* 10090 */   MCD::OPC_FilterValue, 4, 224, 3, // Skip to: 11086
/* 10094 */   MCD::OPC_CheckField, 17, 6, 0, 218, 3, // Skip to: 11086
/* 10100 */   MCD::OPC_Decode, 244, 5, 128, 1, // Opcode: MTFSFI
/* 10105 */   MCD::OPC_FilterValue, 13, 17, 0, // Skip to: 10126
/* 10109 */   MCD::OPC_CheckField, 17, 6, 0, 203, 3, // Skip to: 11086
/* 10115 */   MCD::OPC_CheckField, 6, 6, 4, 197, 3, // Skip to: 11086
/* 10121 */   MCD::OPC_Decode, 245, 5, 128, 1, // Opcode: MTFSFIo
/* 10126 */   MCD::OPC_FilterValue, 14, 27, 0, // Skip to: 10157
/* 10130 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10133 */   MCD::OPC_FilterValue, 18, 11, 0, // Skip to: 10148
/* 10137 */   MCD::OPC_CheckField, 11, 10, 0, 175, 3, // Skip to: 11086
/* 10143 */   MCD::OPC_Decode, 215, 5, 129, 1, // Opcode: MFFS
/* 10148 */   MCD::OPC_FilterValue, 22, 166, 3, // Skip to: 11086
/* 10152 */   MCD::OPC_Decode, 243, 5, 130, 1, // Opcode: MTFSF
/* 10157 */   MCD::OPC_FilterValue, 15, 27, 0, // Skip to: 10188
/* 10161 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10164 */   MCD::OPC_FilterValue, 18, 11, 0, // Skip to: 10179
/* 10168 */   MCD::OPC_CheckField, 11, 10, 0, 144, 3, // Skip to: 11086
/* 10174 */   MCD::OPC_Decode, 216, 5, 129, 1, // Opcode: MFFSo
/* 10179 */   MCD::OPC_FilterValue, 22, 135, 3, // Skip to: 11086
/* 10183 */   MCD::OPC_Decode, 247, 5, 130, 1, // Opcode: MTFSFo
/* 10188 */   MCD::OPC_FilterValue, 16, 123, 0, // Skip to: 10315
/* 10192 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10195 */   MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 10203
/* 10199 */   MCD::OPC_Decode, 134, 4, 104, // Opcode: FCPSGNS
/* 10203 */   MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 10217
/* 10207 */   MCD::OPC_CheckField, 16, 5, 0, 105, 3, // Skip to: 11086
/* 10213 */   MCD::OPC_Decode, 172, 4, 105, // Opcode: FNEGS
/* 10217 */   MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 10231
/* 10221 */   MCD::OPC_CheckField, 16, 5, 0, 91, 3, // Skip to: 11086
/* 10227 */   MCD::OPC_Decode, 156, 4, 105, // Opcode: FMR
/* 10231 */   MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 10245
/* 10235 */   MCD::OPC_CheckField, 16, 5, 0, 77, 3, // Skip to: 11086
/* 10241 */   MCD::OPC_Decode, 168, 4, 105, // Opcode: FNABSS
/* 10245 */   MCD::OPC_FilterValue, 8, 10, 0, // Skip to: 10259
/* 10249 */   MCD::OPC_CheckField, 16, 5, 0, 63, 3, // Skip to: 11086
/* 10255 */   MCD::OPC_Decode, 243, 3, 105, // Opcode: FABSS
/* 10259 */   MCD::OPC_FilterValue, 12, 10, 0, // Skip to: 10273
/* 10263 */   MCD::OPC_CheckField, 16, 5, 0, 49, 3, // Skip to: 11086
/* 10269 */   MCD::OPC_Decode, 192, 4, 105, // Opcode: FRINS
/* 10273 */   MCD::OPC_FilterValue, 13, 10, 0, // Skip to: 10287
/* 10277 */   MCD::OPC_CheckField, 16, 5, 0, 35, 3, // Skip to: 11086
/* 10283 */   MCD::OPC_Decode, 200, 4, 105, // Opcode: FRIZS
/* 10287 */   MCD::OPC_FilterValue, 14, 10, 0, // Skip to: 10301
/* 10291 */   MCD::OPC_CheckField, 16, 5, 0, 21, 3, // Skip to: 11086
/* 10297 */   MCD::OPC_Decode, 196, 4, 105, // Opcode: FRIPS
/* 10301 */   MCD::OPC_FilterValue, 15, 13, 3, // Skip to: 11086
/* 10305 */   MCD::OPC_CheckField, 16, 5, 0, 7, 3, // Skip to: 11086
/* 10311 */   MCD::OPC_Decode, 188, 4, 105, // Opcode: FRIMS
/* 10315 */   MCD::OPC_FilterValue, 17, 123, 0, // Skip to: 10442
/* 10319 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10322 */   MCD::OPC_FilterValue, 0, 4, 0, // Skip to: 10330
/* 10326 */   MCD::OPC_Decode, 135, 4, 104, // Opcode: FCPSGNSo
/* 10330 */   MCD::OPC_FilterValue, 1, 10, 0, // Skip to: 10344
/* 10334 */   MCD::OPC_CheckField, 16, 5, 0, 234, 2, // Skip to: 11086
/* 10340 */   MCD::OPC_Decode, 173, 4, 105, // Opcode: FNEGSo
/* 10344 */   MCD::OPC_FilterValue, 2, 10, 0, // Skip to: 10358
/* 10348 */   MCD::OPC_CheckField, 16, 5, 0, 220, 2, // Skip to: 11086
/* 10354 */   MCD::OPC_Decode, 157, 4, 105, // Opcode: FMRo
/* 10358 */   MCD::OPC_FilterValue, 4, 10, 0, // Skip to: 10372
/* 10362 */   MCD::OPC_CheckField, 16, 5, 0, 206, 2, // Skip to: 11086
/* 10368 */   MCD::OPC_Decode, 169, 4, 105, // Opcode: FNABSSo
/* 10372 */   MCD::OPC_FilterValue, 8, 10, 0, // Skip to: 10386
/* 10376 */   MCD::OPC_CheckField, 16, 5, 0, 192, 2, // Skip to: 11086
/* 10382 */   MCD::OPC_Decode, 244, 3, 105, // Opcode: FABSSo
/* 10386 */   MCD::OPC_FilterValue, 12, 10, 0, // Skip to: 10400
/* 10390 */   MCD::OPC_CheckField, 16, 5, 0, 178, 2, // Skip to: 11086
/* 10396 */   MCD::OPC_Decode, 193, 4, 105, // Opcode: FRINSo
/* 10400 */   MCD::OPC_FilterValue, 13, 10, 0, // Skip to: 10414
/* 10404 */   MCD::OPC_CheckField, 16, 5, 0, 164, 2, // Skip to: 11086
/* 10410 */   MCD::OPC_Decode, 201, 4, 105, // Opcode: FRIZSo
/* 10414 */   MCD::OPC_FilterValue, 14, 10, 0, // Skip to: 10428
/* 10418 */   MCD::OPC_CheckField, 16, 5, 0, 150, 2, // Skip to: 11086
/* 10424 */   MCD::OPC_Decode, 197, 4, 105, // Opcode: FRIPSo
/* 10428 */   MCD::OPC_FilterValue, 15, 142, 2, // Skip to: 11086
/* 10432 */   MCD::OPC_CheckField, 16, 5, 0, 136, 2, // Skip to: 11086
/* 10438 */   MCD::OPC_Decode, 189, 4, 105, // Opcode: FRIMSo
/* 10442 */   MCD::OPC_FilterValue, 24, 16, 0, // Skip to: 10462
/* 10446 */   MCD::OPC_CheckField, 16, 5, 0, 122, 2, // Skip to: 11086
/* 10452 */   MCD::OPC_CheckField, 6, 5, 0, 116, 2, // Skip to: 11086
/* 10458 */   MCD::OPC_Decode, 202, 4, 103, // Opcode: FRSP
/* 10462 */   MCD::OPC_FilterValue, 25, 16, 0, // Skip to: 10482
/* 10466 */   MCD::OPC_CheckField, 16, 5, 0, 102, 2, // Skip to: 11086
/* 10472 */   MCD::OPC_CheckField, 6, 5, 0, 96, 2, // Skip to: 11086
/* 10478 */   MCD::OPC_Decode, 203, 4, 103, // Opcode: FRSPo
/* 10482 */   MCD::OPC_FilterValue, 28, 63, 0, // Skip to: 10549
/* 10486 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10489 */   MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 10504
/* 10493 */   MCD::OPC_CheckField, 16, 5, 0, 75, 2, // Skip to: 11086
/* 10499 */   MCD::OPC_Decode, 142, 4, 131, 1, // Opcode: FCTIW
/* 10504 */   MCD::OPC_FilterValue, 25, 11, 0, // Skip to: 10519
/* 10508 */   MCD::OPC_CheckField, 16, 5, 0, 60, 2, // Skip to: 11086
/* 10514 */   MCD::OPC_Decode, 136, 4, 131, 1, // Opcode: FCTID
/* 10519 */   MCD::OPC_FilterValue, 26, 11, 0, // Skip to: 10534
/* 10523 */   MCD::OPC_CheckField, 16, 5, 0, 45, 2, // Skip to: 11086
/* 10529 */   MCD::OPC_Decode, 250, 3, 131, 1, // Opcode: FCFID
/* 10534 */   MCD::OPC_FilterValue, 30, 36, 2, // Skip to: 11086
/* 10538 */   MCD::OPC_CheckField, 16, 5, 0, 30, 2, // Skip to: 11086
/* 10544 */   MCD::OPC_Decode, 253, 3, 131, 1, // Opcode: FCFIDU
/* 10549 */   MCD::OPC_FilterValue, 29, 63, 0, // Skip to: 10616
/* 10553 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10556 */   MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 10571
/* 10560 */   MCD::OPC_CheckField, 16, 5, 0, 8, 2, // Skip to: 11086
/* 10566 */   MCD::OPC_Decode, 147, 4, 131, 1, // Opcode: FCTIWo
/* 10571 */   MCD::OPC_FilterValue, 25, 11, 0, // Skip to: 10586
/* 10575 */   MCD::OPC_CheckField, 16, 5, 0, 249, 1, // Skip to: 11086
/* 10581 */   MCD::OPC_Decode, 141, 4, 131, 1, // Opcode: FCTIDo
/* 10586 */   MCD::OPC_FilterValue, 26, 11, 0, // Skip to: 10601
/* 10590 */   MCD::OPC_CheckField, 16, 5, 0, 234, 1, // Skip to: 11086
/* 10596 */   MCD::OPC_Decode, 129, 4, 131, 1, // Opcode: FCFIDo
/* 10601 */   MCD::OPC_FilterValue, 30, 225, 1, // Skip to: 11086
/* 10605 */   MCD::OPC_CheckField, 16, 5, 0, 219, 1, // Skip to: 11086
/* 10611 */   MCD::OPC_Decode, 128, 4, 131, 1, // Opcode: FCFIDUo
/* 10616 */   MCD::OPC_FilterValue, 30, 63, 0, // Skip to: 10683
/* 10620 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10623 */   MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 10638
/* 10627 */   MCD::OPC_CheckField, 16, 5, 0, 197, 1, // Skip to: 11086
/* 10633 */   MCD::OPC_Decode, 145, 4, 131, 1, // Opcode: FCTIWZ
/* 10638 */   MCD::OPC_FilterValue, 4, 11, 0, // Skip to: 10653
/* 10642 */   MCD::OPC_CheckField, 16, 5, 0, 182, 1, // Skip to: 11086
/* 10648 */   MCD::OPC_Decode, 143, 4, 131, 1, // Opcode: FCTIWUZ
/* 10653 */   MCD::OPC_FilterValue, 25, 11, 0, // Skip to: 10668
/* 10657 */   MCD::OPC_CheckField, 16, 5, 0, 167, 1, // Skip to: 11086
/* 10663 */   MCD::OPC_Decode, 139, 4, 131, 1, // Opcode: FCTIDZ
/* 10668 */   MCD::OPC_FilterValue, 29, 158, 1, // Skip to: 11086
/* 10672 */   MCD::OPC_CheckField, 16, 5, 0, 152, 1, // Skip to: 11086
/* 10678 */   MCD::OPC_Decode, 137, 4, 131, 1, // Opcode: FCTIDUZ
/* 10683 */   MCD::OPC_FilterValue, 31, 63, 0, // Skip to: 10750
/* 10687 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10690 */   MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 10705
/* 10694 */   MCD::OPC_CheckField, 16, 5, 0, 130, 1, // Skip to: 11086
/* 10700 */   MCD::OPC_Decode, 146, 4, 131, 1, // Opcode: FCTIWZo
/* 10705 */   MCD::OPC_FilterValue, 4, 11, 0, // Skip to: 10720
/* 10709 */   MCD::OPC_CheckField, 16, 5, 0, 115, 1, // Skip to: 11086
/* 10715 */   MCD::OPC_Decode, 144, 4, 131, 1, // Opcode: FCTIWUZo
/* 10720 */   MCD::OPC_FilterValue, 25, 11, 0, // Skip to: 10735
/* 10724 */   MCD::OPC_CheckField, 16, 5, 0, 100, 1, // Skip to: 11086
/* 10730 */   MCD::OPC_Decode, 140, 4, 131, 1, // Opcode: FCTIDZo
/* 10735 */   MCD::OPC_FilterValue, 29, 91, 1, // Skip to: 11086
/* 10739 */   MCD::OPC_CheckField, 16, 5, 0, 85, 1, // Skip to: 11086
/* 10745 */   MCD::OPC_Decode, 138, 4, 131, 1, // Opcode: FCTIDUZo
/* 10750 */   MCD::OPC_FilterValue, 36, 11, 0, // Skip to: 10765
/* 10754 */   MCD::OPC_CheckField, 6, 5, 0, 70, 1, // Skip to: 11086
/* 10760 */   MCD::OPC_Decode, 148, 4, 132, 1, // Opcode: FDIV
/* 10765 */   MCD::OPC_FilterValue, 37, 11, 0, // Skip to: 10780
/* 10769 */   MCD::OPC_CheckField, 6, 5, 0, 55, 1, // Skip to: 11086
/* 10775 */   MCD::OPC_Decode, 151, 4, 132, 1, // Opcode: FDIVo
/* 10780 */   MCD::OPC_FilterValue, 40, 11, 0, // Skip to: 10795
/* 10784 */   MCD::OPC_CheckField, 6, 5, 0, 40, 1, // Skip to: 11086
/* 10790 */   MCD::OPC_Decode, 216, 4, 132, 1, // Opcode: FSUB
/* 10795 */   MCD::OPC_FilterValue, 41, 11, 0, // Skip to: 10810
/* 10799 */   MCD::OPC_CheckField, 6, 5, 0, 25, 1, // Skip to: 11086
/* 10805 */   MCD::OPC_Decode, 219, 4, 132, 1, // Opcode: FSUBo
/* 10810 */   MCD::OPC_FilterValue, 42, 11, 0, // Skip to: 10825
/* 10814 */   MCD::OPC_CheckField, 6, 5, 0, 10, 1, // Skip to: 11086
/* 10820 */   MCD::OPC_Decode, 245, 3, 132, 1, // Opcode: FADD
/* 10825 */   MCD::OPC_FilterValue, 43, 11, 0, // Skip to: 10840
/* 10829 */   MCD::OPC_CheckField, 6, 5, 0, 251, 0, // Skip to: 11086
/* 10835 */   MCD::OPC_Decode, 248, 3, 132, 1, // Opcode: FADDo
/* 10840 */   MCD::OPC_FilterValue, 44, 17, 0, // Skip to: 10861
/* 10844 */   MCD::OPC_CheckField, 16, 5, 0, 236, 0, // Skip to: 11086
/* 10850 */   MCD::OPC_CheckField, 6, 5, 0, 230, 0, // Skip to: 11086
/* 10856 */   MCD::OPC_Decode, 212, 4, 131, 1, // Opcode: FSQRT
/* 10861 */   MCD::OPC_FilterValue, 45, 17, 0, // Skip to: 10882
/* 10865 */   MCD::OPC_CheckField, 16, 5, 0, 215, 0, // Skip to: 11086
/* 10871 */   MCD::OPC_CheckField, 6, 5, 0, 209, 0, // Skip to: 11086
/* 10877 */   MCD::OPC_Decode, 215, 4, 131, 1, // Opcode: FSQRTo
/* 10882 */   MCD::OPC_FilterValue, 46, 5, 0, // Skip to: 10891
/* 10886 */   MCD::OPC_Decode, 210, 4, 133, 1, // Opcode: FSELS
/* 10891 */   MCD::OPC_FilterValue, 47, 5, 0, // Skip to: 10900
/* 10895 */   MCD::OPC_Decode, 211, 4, 133, 1, // Opcode: FSELSo
/* 10900 */   MCD::OPC_FilterValue, 48, 17, 0, // Skip to: 10921
/* 10904 */   MCD::OPC_CheckField, 16, 5, 0, 176, 0, // Skip to: 11086
/* 10910 */   MCD::OPC_CheckField, 6, 5, 0, 170, 0, // Skip to: 11086
/* 10916 */   MCD::OPC_Decode, 182, 4, 131, 1, // Opcode: FRE
/* 10921 */   MCD::OPC_FilterValue, 49, 17, 0, // Skip to: 10942
/* 10925 */   MCD::OPC_CheckField, 16, 5, 0, 155, 0, // Skip to: 11086
/* 10931 */   MCD::OPC_CheckField, 6, 5, 0, 149, 0, // Skip to: 11086
/* 10937 */   MCD::OPC_Decode, 185, 4, 131, 1, // Opcode: FREo
/* 10942 */   MCD::OPC_FilterValue, 50, 11, 0, // Skip to: 10957
/* 10946 */   MCD::OPC_CheckField, 11, 5, 0, 134, 0, // Skip to: 11086
/* 10952 */   MCD::OPC_Decode, 162, 4, 134, 1, // Opcode: FMUL
/* 10957 */   MCD::OPC_FilterValue, 51, 11, 0, // Skip to: 10972
/* 10961 */   MCD::OPC_CheckField, 11, 5, 0, 119, 0, // Skip to: 11086
/* 10967 */   MCD::OPC_Decode, 165, 4, 134, 1, // Opcode: FMULo
/* 10972 */   MCD::OPC_FilterValue, 52, 17, 0, // Skip to: 10993
/* 10976 */   MCD::OPC_CheckField, 16, 5, 0, 104, 0, // Skip to: 11086
/* 10982 */   MCD::OPC_CheckField, 6, 5, 0, 98, 0, // Skip to: 11086
/* 10988 */   MCD::OPC_Decode, 204, 4, 131, 1, // Opcode: FRSQRTE
/* 10993 */   MCD::OPC_FilterValue, 53, 17, 0, // Skip to: 11014
/* 10997 */   MCD::OPC_CheckField, 16, 5, 0, 83, 0, // Skip to: 11086
/* 11003 */   MCD::OPC_CheckField, 6, 5, 0, 77, 0, // Skip to: 11086
/* 11009 */   MCD::OPC_Decode, 207, 4, 131, 1, // Opcode: FRSQRTEo
/* 11014 */   MCD::OPC_FilterValue, 56, 5, 0, // Skip to: 11023
/* 11018 */   MCD::OPC_Decode, 158, 4, 135, 1, // Opcode: FMSUB
/* 11023 */   MCD::OPC_FilterValue, 57, 5, 0, // Skip to: 11032
/* 11027 */   MCD::OPC_Decode, 161, 4, 135, 1, // Opcode: FMSUBo
/* 11032 */   MCD::OPC_FilterValue, 58, 5, 0, // Skip to: 11041
/* 11036 */   MCD::OPC_Decode, 152, 4, 135, 1, // Opcode: FMADD
/* 11041 */   MCD::OPC_FilterValue, 59, 5, 0, // Skip to: 11050
/* 11045 */   MCD::OPC_Decode, 155, 4, 135, 1, // Opcode: FMADDo
/* 11050 */   MCD::OPC_FilterValue, 60, 5, 0, // Skip to: 11059
/* 11054 */   MCD::OPC_Decode, 178, 4, 135, 1, // Opcode: FNMSUB
/* 11059 */   MCD::OPC_FilterValue, 61, 5, 0, // Skip to: 11068
/* 11063 */   MCD::OPC_Decode, 181, 4, 135, 1, // Opcode: FNMSUBo
/* 11068 */   MCD::OPC_FilterValue, 62, 5, 0, // Skip to: 11077
/* 11072 */   MCD::OPC_Decode, 174, 4, 135, 1, // Opcode: FNMADD
/* 11077 */   MCD::OPC_FilterValue, 63, 5, 0, // Skip to: 11086
/* 11081 */   MCD::OPC_Decode, 177, 4, 135, 1, // Opcode: FNMADDo
/* 11086 */   MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableQPX32[] = {
/* 0 */       MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 3 */       MCD::OPC_FilterValue, 0, 63, 0, // Skip to: 70
/* 7 */       MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 10 */      MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 25
/* 14 */      MCD::OPC_CheckField, 26, 6, 4, 178, 7, // Skip to: 1990
/* 20 */      MCD::OPC_Decode, 201, 6, 136, 1, // Opcode: QVFCMPEQb
/* 25 */      MCD::OPC_FilterValue, 1, 11, 0, // Skip to: 40
/* 29 */      MCD::OPC_CheckField, 26, 6, 4, 163, 7, // Skip to: 1990
/* 35 */      MCD::OPC_Decode, 204, 6, 136, 1, // Opcode: QVFCMPGTb
/* 40 */      MCD::OPC_FilterValue, 2, 11, 0, // Skip to: 55
/* 44 */      MCD::OPC_CheckField, 26, 6, 4, 148, 7, // Skip to: 1990
/* 50 */      MCD::OPC_Decode, 143, 7, 136, 1, // Opcode: QVFTSTNANb
/* 55 */      MCD::OPC_FilterValue, 3, 139, 7, // Skip to: 1990
/* 59 */      MCD::OPC_CheckField, 26, 6, 4, 133, 7, // Skip to: 1990
/* 65 */      MCD::OPC_Decode, 207, 6, 136, 1, // Opcode: QVFCMPLTb
/* 70 */      MCD::OPC_FilterValue, 2, 21, 0, // Skip to: 95
/* 74 */      MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 77 */      MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 86
/* 81 */      MCD::OPC_Decode, 152, 7, 137, 1, // Opcode: QVFXXMADDS
/* 86 */      MCD::OPC_FilterValue, 4, 108, 7, // Skip to: 1990
/* 90 */      MCD::OPC_Decode, 151, 7, 137, 1, // Opcode: QVFXXMADD
/* 95 */      MCD::OPC_FilterValue, 6, 21, 0, // Skip to: 120
/* 99 */      MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 102 */     MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 111
/* 106 */     MCD::OPC_Decode, 150, 7, 137, 1, // Opcode: QVFXXCPNMADDS
/* 111 */     MCD::OPC_FilterValue, 4, 83, 7, // Skip to: 1990
/* 115 */     MCD::OPC_Decode, 149, 7, 137, 1, // Opcode: QVFXXCPNMADD
/* 120 */     MCD::OPC_FilterValue, 8, 17, 0, // Skip to: 141
/* 124 */     MCD::OPC_CheckField, 26, 6, 4, 68, 7, // Skip to: 1990
/* 130 */     MCD::OPC_CheckField, 6, 1, 0, 62, 7, // Skip to: 1990
/* 136 */     MCD::OPC_Decode, 221, 6, 138, 1, // Opcode: QVFLOGICALb
/* 141 */     MCD::OPC_FilterValue, 10, 191, 0, // Skip to: 336
/* 145 */     MCD::OPC_ExtractField, 6, 3,  // Inst{8-6} ...
/* 148 */     MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 163
/* 152 */     MCD::OPC_CheckField, 26, 6, 4, 40, 7, // Skip to: 1990
/* 158 */     MCD::OPC_Decode, 184, 6, 139, 1, // Opcode: QVALIGNI
/* 163 */     MCD::OPC_FilterValue, 1, 17, 0, // Skip to: 184
/* 167 */     MCD::OPC_CheckField, 26, 6, 4, 25, 7, // Skip to: 1990
/* 173 */     MCD::OPC_CheckField, 11, 5, 0, 19, 7, // Skip to: 1990
/* 179 */     MCD::OPC_Decode, 187, 6, 140, 1, // Opcode: QVESPLATI
/* 184 */     MCD::OPC_FilterValue, 4, 37, 0, // Skip to: 225
/* 188 */     MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 191 */     MCD::OPC_FilterValue, 4, 5, 0, // Skip to: 200
/* 195 */     MCD::OPC_Decode, 155, 7, 141, 1, // Opcode: QVGPCI
/* 200 */     MCD::OPC_FilterValue, 31, 250, 6, // Skip to: 1990
/* 204 */     MCD::OPC_ExtractField, 9, 2,  // Inst{10-9} ...
/* 207 */     MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 216
/* 211 */     MCD::OPC_Decode, 199, 7, 142, 1, // Opcode: QVSTFCSXI
/* 216 */     MCD::OPC_FilterValue, 2, 234, 6, // Skip to: 1990
/* 220 */     MCD::OPC_Decode, 220, 7, 142, 1, // Opcode: QVSTFSXI
/* 225 */     MCD::OPC_FilterValue, 5, 33, 0, // Skip to: 262
/* 229 */     MCD::OPC_ExtractField, 9, 2,  // Inst{10-9} ...
/* 232 */     MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 247
/* 236 */     MCD::OPC_CheckField, 26, 6, 31, 212, 6, // Skip to: 1990
/* 242 */     MCD::OPC_Decode, 195, 7, 142, 1, // Opcode: QVSTFCSUXI
/* 247 */     MCD::OPC_FilterValue, 2, 203, 6, // Skip to: 1990
/* 251 */     MCD::OPC_CheckField, 26, 6, 31, 197, 6, // Skip to: 1990
/* 257 */     MCD::OPC_Decode, 215, 7, 142, 1, // Opcode: QVSTFSUXI
/* 262 */     MCD::OPC_FilterValue, 6, 33, 0, // Skip to: 299
/* 266 */     MCD::OPC_ExtractField, 9, 2,  // Inst{10-9} ...
/* 269 */     MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 284
/* 273 */     MCD::OPC_CheckField, 26, 6, 31, 175, 6, // Skip to: 1990
/* 279 */     MCD::OPC_Decode, 191, 7, 142, 1, // Opcode: QVSTFCDXI
/* 284 */     MCD::OPC_FilterValue, 2, 166, 6, // Skip to: 1990
/* 288 */     MCD::OPC_CheckField, 26, 6, 31, 160, 6, // Skip to: 1990
/* 294 */     MCD::OPC_Decode, 208, 7, 142, 1, // Opcode: QVSTFDXI
/* 299 */     MCD::OPC_FilterValue, 7, 151, 6, // Skip to: 1990
/* 303 */     MCD::OPC_ExtractField, 9, 2,  // Inst{10-9} ...
/* 306 */     MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 321
/* 310 */     MCD::OPC_CheckField, 26, 6, 31, 138, 6, // Skip to: 1990
/* 316 */     MCD::OPC_Decode, 187, 7, 142, 1, // Opcode: QVSTFCDUXI
/* 321 */     MCD::OPC_FilterValue, 2, 129, 6, // Skip to: 1990
/* 325 */     MCD::OPC_CheckField, 26, 6, 31, 123, 6, // Skip to: 1990
/* 331 */     MCD::OPC_Decode, 204, 7, 142, 1, // Opcode: QVSTFDUXI
/* 336 */     MCD::OPC_FilterValue, 11, 123, 0, // Skip to: 463
/* 340 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 343 */     MCD::OPC_FilterValue, 4, 11, 0, // Skip to: 358
/* 347 */     MCD::OPC_CheckField, 26, 6, 31, 101, 6, // Skip to: 1990
/* 353 */     MCD::OPC_Decode, 200, 7, 142, 1, // Opcode: QVSTFCSXIA
/* 358 */     MCD::OPC_FilterValue, 5, 11, 0, // Skip to: 373
/* 362 */     MCD::OPC_CheckField, 26, 6, 31, 86, 6, // Skip to: 1990
/* 368 */     MCD::OPC_Decode, 196, 7, 142, 1, // Opcode: QVSTFCSUXIA
/* 373 */     MCD::OPC_FilterValue, 6, 11, 0, // Skip to: 388
/* 377 */     MCD::OPC_CheckField, 26, 6, 31, 71, 6, // Skip to: 1990
/* 383 */     MCD::OPC_Decode, 192, 7, 142, 1, // Opcode: QVSTFCDXIA
/* 388 */     MCD::OPC_FilterValue, 7, 11, 0, // Skip to: 403
/* 392 */     MCD::OPC_CheckField, 26, 6, 31, 56, 6, // Skip to: 1990
/* 398 */     MCD::OPC_Decode, 188, 7, 142, 1, // Opcode: QVSTFCDUXIA
/* 403 */     MCD::OPC_FilterValue, 20, 11, 0, // Skip to: 418
/* 407 */     MCD::OPC_CheckField, 26, 6, 31, 41, 6, // Skip to: 1990
/* 413 */     MCD::OPC_Decode, 221, 7, 142, 1, // Opcode: QVSTFSXIA
/* 418 */     MCD::OPC_FilterValue, 21, 11, 0, // Skip to: 433
/* 422 */     MCD::OPC_CheckField, 26, 6, 31, 26, 6, // Skip to: 1990
/* 428 */     MCD::OPC_Decode, 216, 7, 142, 1, // Opcode: QVSTFSUXIA
/* 433 */     MCD::OPC_FilterValue, 22, 11, 0, // Skip to: 448
/* 437 */     MCD::OPC_CheckField, 26, 6, 31, 11, 6, // Skip to: 1990
/* 443 */     MCD::OPC_Decode, 209, 7, 142, 1, // Opcode: QVSTFDXIA
/* 448 */     MCD::OPC_FilterValue, 23, 2, 6, // Skip to: 1990
/* 452 */     MCD::OPC_CheckField, 26, 6, 31, 252, 5, // Skip to: 1990
/* 458 */     MCD::OPC_Decode, 205, 7, 142, 1, // Opcode: QVSTFDUXIA
/* 463 */     MCD::OPC_FilterValue, 12, 55, 0, // Skip to: 522
/* 467 */     MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 470 */     MCD::OPC_FilterValue, 4, 5, 0, // Skip to: 479
/* 474 */     MCD::OPC_Decode, 245, 6, 137, 1, // Opcode: QVFPERM
/* 479 */     MCD::OPC_FilterValue, 31, 227, 5, // Skip to: 1990
/* 483 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 486 */     MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 495
/* 490 */     MCD::OPC_Decode, 184, 7, 142, 1, // Opcode: QVLPCRSX
/* 495 */     MCD::OPC_FilterValue, 2, 5, 0, // Skip to: 504
/* 499 */     MCD::OPC_Decode, 183, 7, 142, 1, // Opcode: QVLPCRDX
/* 504 */     MCD::OPC_FilterValue, 16, 5, 0, // Skip to: 513
/* 508 */     MCD::OPC_Decode, 181, 7, 142, 1, // Opcode: QVLPCLSX
/* 513 */     MCD::OPC_FilterValue, 18, 193, 5, // Skip to: 1990
/* 517 */     MCD::OPC_Decode, 180, 7, 142, 1, // Opcode: QVLPCLDX
/* 522 */     MCD::OPC_FilterValue, 14, 32, 1, // Skip to: 814
/* 526 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 529 */     MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 544
/* 533 */     MCD::OPC_CheckField, 26, 6, 31, 171, 5, // Skip to: 1990
/* 539 */     MCD::OPC_Decode, 162, 7, 142, 1, // Opcode: QVLFCSX
/* 544 */     MCD::OPC_FilterValue, 1, 11, 0, // Skip to: 559
/* 548 */     MCD::OPC_CheckField, 26, 6, 31, 156, 5, // Skip to: 1990
/* 554 */     MCD::OPC_Decode, 160, 7, 142, 1, // Opcode: QVLFCSUX
/* 559 */     MCD::OPC_FilterValue, 2, 11, 0, // Skip to: 574
/* 563 */     MCD::OPC_CheckField, 26, 6, 31, 141, 5, // Skip to: 1990
/* 569 */     MCD::OPC_Decode, 158, 7, 142, 1, // Opcode: QVLFCDX
/* 574 */     MCD::OPC_FilterValue, 3, 11, 0, // Skip to: 589
/* 578 */     MCD::OPC_CheckField, 26, 6, 31, 126, 5, // Skip to: 1990
/* 584 */     MCD::OPC_Decode, 156, 7, 142, 1, // Opcode: QVLFCDUX
/* 589 */     MCD::OPC_FilterValue, 4, 11, 0, // Skip to: 604
/* 593 */     MCD::OPC_CheckField, 26, 6, 31, 111, 5, // Skip to: 1990
/* 599 */     MCD::OPC_Decode, 197, 7, 142, 1, // Opcode: QVSTFCSX
/* 604 */     MCD::OPC_FilterValue, 5, 11, 0, // Skip to: 619
/* 608 */     MCD::OPC_CheckField, 26, 6, 31, 96, 5, // Skip to: 1990
/* 614 */     MCD::OPC_Decode, 193, 7, 142, 1, // Opcode: QVSTFCSUX
/* 619 */     MCD::OPC_FilterValue, 6, 11, 0, // Skip to: 634
/* 623 */     MCD::OPC_CheckField, 26, 6, 31, 81, 5, // Skip to: 1990
/* 629 */     MCD::OPC_Decode, 189, 7, 142, 1, // Opcode: QVSTFCDX
/* 634 */     MCD::OPC_FilterValue, 7, 11, 0, // Skip to: 649
/* 638 */     MCD::OPC_CheckField, 26, 6, 31, 66, 5, // Skip to: 1990
/* 644 */     MCD::OPC_Decode, 185, 7, 142, 1, // Opcode: QVSTFCDUX
/* 649 */     MCD::OPC_FilterValue, 16, 11, 0, // Skip to: 664
/* 653 */     MCD::OPC_CheckField, 26, 6, 31, 51, 5, // Skip to: 1990
/* 659 */     MCD::OPC_Decode, 176, 7, 142, 1, // Opcode: QVLFSX
/* 664 */     MCD::OPC_FilterValue, 17, 11, 0, // Skip to: 679
/* 668 */     MCD::OPC_CheckField, 26, 6, 31, 36, 5, // Skip to: 1990
/* 674 */     MCD::OPC_Decode, 174, 7, 143, 1, // Opcode: QVLFSUX
/* 679 */     MCD::OPC_FilterValue, 18, 11, 0, // Skip to: 694
/* 683 */     MCD::OPC_CheckField, 26, 6, 31, 21, 5, // Skip to: 1990
/* 689 */     MCD::OPC_Decode, 167, 7, 142, 1, // Opcode: QVLFDX
/* 694 */     MCD::OPC_FilterValue, 19, 11, 0, // Skip to: 709
/* 698 */     MCD::OPC_CheckField, 26, 6, 31, 6, 5, // Skip to: 1990
/* 704 */     MCD::OPC_Decode, 165, 7, 144, 1, // Opcode: QVLFDUX
/* 709 */     MCD::OPC_FilterValue, 20, 11, 0, // Skip to: 724
/* 713 */     MCD::OPC_CheckField, 26, 6, 31, 247, 4, // Skip to: 1990
/* 719 */     MCD::OPC_Decode, 218, 7, 142, 1, // Opcode: QVSTFSX
/* 724 */     MCD::OPC_FilterValue, 21, 11, 0, // Skip to: 739
/* 728 */     MCD::OPC_CheckField, 26, 6, 31, 232, 4, // Skip to: 1990
/* 734 */     MCD::OPC_Decode, 213, 7, 145, 1, // Opcode: QVSTFSUX
/* 739 */     MCD::OPC_FilterValue, 22, 11, 0, // Skip to: 754
/* 743 */     MCD::OPC_CheckField, 26, 6, 31, 217, 4, // Skip to: 1990
/* 749 */     MCD::OPC_Decode, 206, 7, 142, 1, // Opcode: QVSTFDX
/* 754 */     MCD::OPC_FilterValue, 23, 11, 0, // Skip to: 769
/* 758 */     MCD::OPC_CheckField, 26, 6, 31, 202, 4, // Skip to: 1990
/* 764 */     MCD::OPC_Decode, 202, 7, 146, 1, // Opcode: QVSTFDUX
/* 769 */     MCD::OPC_FilterValue, 26, 11, 0, // Skip to: 784
/* 773 */     MCD::OPC_CheckField, 26, 6, 31, 187, 4, // Skip to: 1990
/* 779 */     MCD::OPC_Decode, 172, 7, 142, 1, // Opcode: QVLFIWZX
/* 784 */     MCD::OPC_FilterValue, 27, 11, 0, // Skip to: 799
/* 788 */     MCD::OPC_CheckField, 26, 6, 31, 172, 4, // Skip to: 1990
/* 794 */     MCD::OPC_Decode, 170, 7, 142, 1, // Opcode: QVLFIWAX
/* 799 */     MCD::OPC_FilterValue, 30, 163, 4, // Skip to: 1990
/* 803 */     MCD::OPC_CheckField, 26, 6, 31, 157, 4, // Skip to: 1990
/* 809 */     MCD::OPC_Decode, 211, 7, 142, 1, // Opcode: QVSTFIWX
/* 814 */     MCD::OPC_FilterValue, 15, 32, 1, // Skip to: 1106
/* 818 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 821 */     MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 836
/* 825 */     MCD::OPC_CheckField, 26, 6, 31, 135, 4, // Skip to: 1990
/* 831 */     MCD::OPC_Decode, 163, 7, 142, 1, // Opcode: QVLFCSXA
/* 836 */     MCD::OPC_FilterValue, 1, 11, 0, // Skip to: 851
/* 840 */     MCD::OPC_CheckField, 26, 6, 31, 120, 4, // Skip to: 1990
/* 846 */     MCD::OPC_Decode, 161, 7, 142, 1, // Opcode: QVLFCSUXA
/* 851 */     MCD::OPC_FilterValue, 2, 11, 0, // Skip to: 866
/* 855 */     MCD::OPC_CheckField, 26, 6, 31, 105, 4, // Skip to: 1990
/* 861 */     MCD::OPC_Decode, 159, 7, 142, 1, // Opcode: QVLFCDXA
/* 866 */     MCD::OPC_FilterValue, 3, 11, 0, // Skip to: 881
/* 870 */     MCD::OPC_CheckField, 26, 6, 31, 90, 4, // Skip to: 1990
/* 876 */     MCD::OPC_Decode, 157, 7, 142, 1, // Opcode: QVLFCDUXA
/* 881 */     MCD::OPC_FilterValue, 4, 11, 0, // Skip to: 896
/* 885 */     MCD::OPC_CheckField, 26, 6, 31, 75, 4, // Skip to: 1990
/* 891 */     MCD::OPC_Decode, 198, 7, 142, 1, // Opcode: QVSTFCSXA
/* 896 */     MCD::OPC_FilterValue, 5, 11, 0, // Skip to: 911
/* 900 */     MCD::OPC_CheckField, 26, 6, 31, 60, 4, // Skip to: 1990
/* 906 */     MCD::OPC_Decode, 194, 7, 142, 1, // Opcode: QVSTFCSUXA
/* 911 */     MCD::OPC_FilterValue, 6, 11, 0, // Skip to: 926
/* 915 */     MCD::OPC_CheckField, 26, 6, 31, 45, 4, // Skip to: 1990
/* 921 */     MCD::OPC_Decode, 190, 7, 142, 1, // Opcode: QVSTFCDXA
/* 926 */     MCD::OPC_FilterValue, 7, 11, 0, // Skip to: 941
/* 930 */     MCD::OPC_CheckField, 26, 6, 31, 30, 4, // Skip to: 1990
/* 936 */     MCD::OPC_Decode, 186, 7, 142, 1, // Opcode: QVSTFCDUXA
/* 941 */     MCD::OPC_FilterValue, 16, 11, 0, // Skip to: 956
/* 945 */     MCD::OPC_CheckField, 26, 6, 31, 15, 4, // Skip to: 1990
/* 951 */     MCD::OPC_Decode, 177, 7, 142, 1, // Opcode: QVLFSXA
/* 956 */     MCD::OPC_FilterValue, 17, 11, 0, // Skip to: 971
/* 960 */     MCD::OPC_CheckField, 26, 6, 31, 0, 4, // Skip to: 1990
/* 966 */     MCD::OPC_Decode, 175, 7, 142, 1, // Opcode: QVLFSUXA
/* 971 */     MCD::OPC_FilterValue, 18, 11, 0, // Skip to: 986
/* 975 */     MCD::OPC_CheckField, 26, 6, 31, 241, 3, // Skip to: 1990
/* 981 */     MCD::OPC_Decode, 168, 7, 142, 1, // Opcode: QVLFDXA
/* 986 */     MCD::OPC_FilterValue, 19, 11, 0, // Skip to: 1001
/* 990 */     MCD::OPC_CheckField, 26, 6, 31, 226, 3, // Skip to: 1990
/* 996 */     MCD::OPC_Decode, 166, 7, 142, 1, // Opcode: QVLFDUXA
/* 1001 */    MCD::OPC_FilterValue, 20, 11, 0, // Skip to: 1016
/* 1005 */    MCD::OPC_CheckField, 26, 6, 31, 211, 3, // Skip to: 1990
/* 1011 */    MCD::OPC_Decode, 219, 7, 142, 1, // Opcode: QVSTFSXA
/* 1016 */    MCD::OPC_FilterValue, 21, 11, 0, // Skip to: 1031
/* 1020 */    MCD::OPC_CheckField, 26, 6, 31, 196, 3, // Skip to: 1990
/* 1026 */    MCD::OPC_Decode, 214, 7, 142, 1, // Opcode: QVSTFSUXA
/* 1031 */    MCD::OPC_FilterValue, 22, 11, 0, // Skip to: 1046
/* 1035 */    MCD::OPC_CheckField, 26, 6, 31, 181, 3, // Skip to: 1990
/* 1041 */    MCD::OPC_Decode, 207, 7, 142, 1, // Opcode: QVSTFDXA
/* 1046 */    MCD::OPC_FilterValue, 23, 11, 0, // Skip to: 1061
/* 1050 */    MCD::OPC_CheckField, 26, 6, 31, 166, 3, // Skip to: 1990
/* 1056 */    MCD::OPC_Decode, 203, 7, 142, 1, // Opcode: QVSTFDUXA
/* 1061 */    MCD::OPC_FilterValue, 26, 11, 0, // Skip to: 1076
/* 1065 */    MCD::OPC_CheckField, 26, 6, 31, 151, 3, // Skip to: 1990
/* 1071 */    MCD::OPC_Decode, 173, 7, 142, 1, // Opcode: QVLFIWZXA
/* 1076 */    MCD::OPC_FilterValue, 27, 11, 0, // Skip to: 1091
/* 1080 */    MCD::OPC_CheckField, 26, 6, 31, 136, 3, // Skip to: 1990
/* 1086 */    MCD::OPC_Decode, 171, 7, 142, 1, // Opcode: QVLFIWAXA
/* 1091 */    MCD::OPC_FilterValue, 30, 127, 3, // Skip to: 1990
/* 1095 */    MCD::OPC_CheckField, 26, 6, 31, 121, 3, // Skip to: 1990
/* 1101 */    MCD::OPC_Decode, 212, 7, 142, 1, // Opcode: QVSTFIWXA
/* 1106 */    MCD::OPC_FilterValue, 16, 186, 0, // Skip to: 1296
/* 1110 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1113 */    MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 1128
/* 1117 */    MCD::OPC_CheckField, 26, 6, 4, 99, 3, // Skip to: 1990
/* 1123 */    MCD::OPC_Decode, 209, 6, 147, 1, // Opcode: QVFCPSGN
/* 1128 */    MCD::OPC_FilterValue, 1, 17, 0, // Skip to: 1149
/* 1132 */    MCD::OPC_CheckField, 26, 6, 4, 84, 3, // Skip to: 1990
/* 1138 */    MCD::OPC_CheckField, 16, 5, 0, 78, 3, // Skip to: 1990
/* 1144 */    MCD::OPC_Decode, 237, 6, 148, 1, // Opcode: QVFNEG
/* 1149 */    MCD::OPC_FilterValue, 2, 17, 0, // Skip to: 1170
/* 1153 */    MCD::OPC_CheckField, 26, 6, 4, 63, 3, // Skip to: 1990
/* 1159 */    MCD::OPC_CheckField, 16, 5, 0, 57, 3, // Skip to: 1990
/* 1165 */    MCD::OPC_Decode, 226, 6, 148, 1, // Opcode: QVFMR
/* 1170 */    MCD::OPC_FilterValue, 4, 17, 0, // Skip to: 1191
/* 1174 */    MCD::OPC_CheckField, 26, 6, 4, 42, 3, // Skip to: 1990
/* 1180 */    MCD::OPC_CheckField, 16, 5, 0, 36, 3, // Skip to: 1990
/* 1186 */    MCD::OPC_Decode, 235, 6, 148, 1, // Opcode: QVFNABS
/* 1191 */    MCD::OPC_FilterValue, 8, 17, 0, // Skip to: 1212
/* 1195 */    MCD::OPC_CheckField, 26, 6, 4, 21, 3, // Skip to: 1990
/* 1201 */    MCD::OPC_CheckField, 16, 5, 0, 15, 3, // Skip to: 1990
/* 1207 */    MCD::OPC_Decode, 190, 6, 148, 1, // Opcode: QVFABS
/* 1212 */    MCD::OPC_FilterValue, 12, 17, 0, // Skip to: 1233
/* 1216 */    MCD::OPC_CheckField, 26, 6, 4, 0, 3, // Skip to: 1990
/* 1222 */    MCD::OPC_CheckField, 16, 5, 0, 250, 2, // Skip to: 1990
/* 1228 */    MCD::OPC_Decode, 252, 6, 148, 1, // Opcode: QVFRIN
/* 1233 */    MCD::OPC_FilterValue, 13, 17, 0, // Skip to: 1254
/* 1237 */    MCD::OPC_CheckField, 26, 6, 4, 235, 2, // Skip to: 1990
/* 1243 */    MCD::OPC_CheckField, 16, 5, 0, 229, 2, // Skip to: 1990
/* 1249 */    MCD::OPC_Decode, 128, 7, 148, 1, // Opcode: QVFRIZ
/* 1254 */    MCD::OPC_FilterValue, 14, 17, 0, // Skip to: 1275
/* 1258 */    MCD::OPC_CheckField, 26, 6, 4, 214, 2, // Skip to: 1990
/* 1264 */    MCD::OPC_CheckField, 16, 5, 0, 208, 2, // Skip to: 1990
/* 1270 */    MCD::OPC_Decode, 254, 6, 148, 1, // Opcode: QVFRIP
/* 1275 */    MCD::OPC_FilterValue, 15, 199, 2, // Skip to: 1990
/* 1279 */    MCD::OPC_CheckField, 26, 6, 4, 193, 2, // Skip to: 1990
/* 1285 */    MCD::OPC_CheckField, 16, 5, 0, 187, 2, // Skip to: 1990
/* 1291 */    MCD::OPC_Decode, 250, 6, 148, 1, // Opcode: QVFRIM
/* 1296 */    MCD::OPC_FilterValue, 18, 21, 0, // Skip to: 1321
/* 1300 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1303 */    MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 1312
/* 1307 */    MCD::OPC_Decode, 146, 7, 137, 1, // Opcode: QVFXMADDS
/* 1312 */    MCD::OPC_FilterValue, 4, 162, 2, // Skip to: 1990
/* 1316 */    MCD::OPC_Decode, 145, 7, 137, 1, // Opcode: QVFXMADD
/* 1321 */    MCD::OPC_FilterValue, 22, 21, 0, // Skip to: 1346
/* 1325 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1328 */    MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 1337
/* 1332 */    MCD::OPC_Decode, 154, 7, 137, 1, // Opcode: QVFXXNPMADDS
/* 1337 */    MCD::OPC_FilterValue, 4, 137, 2, // Skip to: 1990
/* 1341 */    MCD::OPC_Decode, 153, 7, 137, 1, // Opcode: QVFXXNPMADD
/* 1346 */    MCD::OPC_FilterValue, 24, 23, 0, // Skip to: 1373
/* 1350 */    MCD::OPC_CheckField, 26, 6, 4, 122, 2, // Skip to: 1990
/* 1356 */    MCD::OPC_CheckField, 16, 5, 0, 116, 2, // Skip to: 1990
/* 1362 */    MCD::OPC_CheckField, 6, 5, 0, 110, 2, // Skip to: 1990
/* 1368 */    MCD::OPC_Decode, 131, 7, 149, 1, // Opcode: QVFRSPs
/* 1373 */    MCD::OPC_FilterValue, 28, 161, 0, // Skip to: 1538
/* 1377 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1380 */    MCD::OPC_FilterValue, 0, 17, 0, // Skip to: 1401
/* 1384 */    MCD::OPC_CheckField, 26, 6, 4, 88, 2, // Skip to: 1990
/* 1390 */    MCD::OPC_CheckField, 16, 5, 0, 82, 2, // Skip to: 1990
/* 1396 */    MCD::OPC_Decode, 216, 6, 148, 1, // Opcode: QVFCTIW
/* 1401 */    MCD::OPC_FilterValue, 4, 17, 0, // Skip to: 1422
/* 1405 */    MCD::OPC_CheckField, 26, 6, 4, 67, 2, // Skip to: 1990
/* 1411 */    MCD::OPC_CheckField, 16, 5, 0, 61, 2, // Skip to: 1990
/* 1417 */    MCD::OPC_Decode, 217, 6, 148, 1, // Opcode: QVFCTIWU
/* 1422 */    MCD::OPC_FilterValue, 25, 17, 0, // Skip to: 1443
/* 1426 */    MCD::OPC_CheckField, 26, 6, 4, 46, 2, // Skip to: 1990
/* 1432 */    MCD::OPC_CheckField, 16, 5, 0, 40, 2, // Skip to: 1990
/* 1438 */    MCD::OPC_Decode, 211, 6, 148, 1, // Opcode: QVFCTID
/* 1443 */    MCD::OPC_FilterValue, 26, 33, 0, // Skip to: 1480
/* 1447 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1450 */    MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 1465
/* 1454 */    MCD::OPC_CheckField, 16, 5, 0, 18, 2, // Skip to: 1990
/* 1460 */    MCD::OPC_Decode, 196, 6, 148, 1, // Opcode: QVFCFIDS
/* 1465 */    MCD::OPC_FilterValue, 4, 9, 2, // Skip to: 1990
/* 1469 */    MCD::OPC_CheckField, 16, 5, 0, 3, 2, // Skip to: 1990
/* 1475 */    MCD::OPC_Decode, 195, 6, 148, 1, // Opcode: QVFCFID
/* 1480 */    MCD::OPC_FilterValue, 29, 17, 0, // Skip to: 1501
/* 1484 */    MCD::OPC_CheckField, 26, 6, 4, 244, 1, // Skip to: 1990
/* 1490 */    MCD::OPC_CheckField, 16, 5, 0, 238, 1, // Skip to: 1990
/* 1496 */    MCD::OPC_Decode, 212, 6, 148, 1, // Opcode: QVFCTIDU
/* 1501 */    MCD::OPC_FilterValue, 30, 229, 1, // Skip to: 1990
/* 1505 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1508 */    MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 1523
/* 1512 */    MCD::OPC_CheckField, 16, 5, 0, 216, 1, // Skip to: 1990
/* 1518 */    MCD::OPC_Decode, 198, 6, 148, 1, // Opcode: QVFCFIDUS
/* 1523 */    MCD::OPC_FilterValue, 4, 207, 1, // Skip to: 1990
/* 1527 */    MCD::OPC_CheckField, 16, 5, 0, 201, 1, // Skip to: 1990
/* 1533 */    MCD::OPC_Decode, 197, 6, 148, 1, // Opcode: QVFCFIDU
/* 1538 */    MCD::OPC_FilterValue, 30, 87, 0, // Skip to: 1629
/* 1542 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1545 */    MCD::OPC_FilterValue, 0, 17, 0, // Skip to: 1566
/* 1549 */    MCD::OPC_CheckField, 26, 6, 4, 179, 1, // Skip to: 1990
/* 1555 */    MCD::OPC_CheckField, 16, 5, 0, 173, 1, // Skip to: 1990
/* 1561 */    MCD::OPC_Decode, 219, 6, 148, 1, // Opcode: QVFCTIWZ
/* 1566 */    MCD::OPC_FilterValue, 4, 17, 0, // Skip to: 1587
/* 1570 */    MCD::OPC_CheckField, 26, 6, 4, 158, 1, // Skip to: 1990
/* 1576 */    MCD::OPC_CheckField, 16, 5, 0, 152, 1, // Skip to: 1990
/* 1582 */    MCD::OPC_Decode, 218, 6, 148, 1, // Opcode: QVFCTIWUZ
/* 1587 */    MCD::OPC_FilterValue, 25, 17, 0, // Skip to: 1608
/* 1591 */    MCD::OPC_CheckField, 26, 6, 4, 137, 1, // Skip to: 1990
/* 1597 */    MCD::OPC_CheckField, 16, 5, 0, 131, 1, // Skip to: 1990
/* 1603 */    MCD::OPC_Decode, 214, 6, 148, 1, // Opcode: QVFCTIDZ
/* 1608 */    MCD::OPC_FilterValue, 29, 122, 1, // Skip to: 1990
/* 1612 */    MCD::OPC_CheckField, 26, 6, 4, 116, 1, // Skip to: 1990
/* 1618 */    MCD::OPC_CheckField, 16, 5, 0, 110, 1, // Skip to: 1990
/* 1624 */    MCD::OPC_Decode, 213, 6, 148, 1, // Opcode: QVFCTIDUZ
/* 1629 */    MCD::OPC_FilterValue, 34, 33, 0, // Skip to: 1666
/* 1633 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1636 */    MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 1651
/* 1640 */    MCD::OPC_CheckField, 11, 5, 0, 88, 1, // Skip to: 1990
/* 1646 */    MCD::OPC_Decode, 148, 7, 150, 1, // Opcode: QVFXMULS
/* 1651 */    MCD::OPC_FilterValue, 4, 79, 1, // Skip to: 1990
/* 1655 */    MCD::OPC_CheckField, 11, 5, 0, 73, 1, // Skip to: 1990
/* 1661 */    MCD::OPC_Decode, 147, 7, 150, 1, // Opcode: QVFXMUL
/* 1666 */    MCD::OPC_FilterValue, 40, 33, 0, // Skip to: 1703
/* 1670 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1673 */    MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 1688
/* 1677 */    MCD::OPC_CheckField, 6, 5, 0, 51, 1, // Skip to: 1990
/* 1683 */    MCD::OPC_Decode, 141, 7, 151, 1, // Opcode: QVFSUBSs
/* 1688 */    MCD::OPC_FilterValue, 4, 42, 1, // Skip to: 1990
/* 1692 */    MCD::OPC_CheckField, 6, 5, 0, 36, 1, // Skip to: 1990
/* 1698 */    MCD::OPC_Decode, 139, 7, 147, 1, // Opcode: QVFSUB
/* 1703 */    MCD::OPC_FilterValue, 42, 33, 0, // Skip to: 1740
/* 1707 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1710 */    MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 1725
/* 1714 */    MCD::OPC_CheckField, 6, 5, 0, 14, 1, // Skip to: 1990
/* 1720 */    MCD::OPC_Decode, 194, 6, 151, 1, // Opcode: QVFADDSs
/* 1725 */    MCD::OPC_FilterValue, 4, 5, 1, // Skip to: 1990
/* 1729 */    MCD::OPC_CheckField, 6, 5, 0, 255, 0, // Skip to: 1990
/* 1735 */    MCD::OPC_Decode, 192, 6, 147, 1, // Opcode: QVFADD
/* 1740 */    MCD::OPC_FilterValue, 46, 11, 0, // Skip to: 1755
/* 1744 */    MCD::OPC_CheckField, 26, 6, 4, 240, 0, // Skip to: 1990
/* 1750 */    MCD::OPC_Decode, 136, 7, 152, 1, // Opcode: QVFSELb
/* 1755 */    MCD::OPC_FilterValue, 48, 45, 0, // Skip to: 1804
/* 1759 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1762 */    MCD::OPC_FilterValue, 0, 17, 0, // Skip to: 1783
/* 1766 */    MCD::OPC_CheckField, 16, 5, 0, 218, 0, // Skip to: 1990
/* 1772 */    MCD::OPC_CheckField, 6, 5, 0, 212, 0, // Skip to: 1990
/* 1778 */    MCD::OPC_Decode, 248, 6, 148, 1, // Opcode: QVFRES
/* 1783 */    MCD::OPC_FilterValue, 4, 203, 0, // Skip to: 1990
/* 1787 */    MCD::OPC_CheckField, 16, 5, 0, 197, 0, // Skip to: 1990
/* 1793 */    MCD::OPC_CheckField, 6, 5, 0, 191, 0, // Skip to: 1990
/* 1799 */    MCD::OPC_Decode, 247, 6, 148, 1, // Opcode: QVFRE
/* 1804 */    MCD::OPC_FilterValue, 50, 33, 0, // Skip to: 1841
/* 1808 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1811 */    MCD::OPC_FilterValue, 0, 11, 0, // Skip to: 1826
/* 1815 */    MCD::OPC_CheckField, 11, 5, 0, 169, 0, // Skip to: 1990
/* 1821 */    MCD::OPC_Decode, 234, 6, 153, 1, // Opcode: QVFMULSs
/* 1826 */    MCD::OPC_FilterValue, 4, 160, 0, // Skip to: 1990
/* 1830 */    MCD::OPC_CheckField, 11, 5, 0, 154, 0, // Skip to: 1990
/* 1836 */    MCD::OPC_Decode, 232, 6, 150, 1, // Opcode: QVFMUL
/* 1841 */    MCD::OPC_FilterValue, 52, 45, 0, // Skip to: 1890
/* 1845 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1848 */    MCD::OPC_FilterValue, 0, 17, 0, // Skip to: 1869
/* 1852 */    MCD::OPC_CheckField, 16, 5, 0, 132, 0, // Skip to: 1990
/* 1858 */    MCD::OPC_CheckField, 6, 5, 0, 126, 0, // Skip to: 1990
/* 1864 */    MCD::OPC_Decode, 133, 7, 148, 1, // Opcode: QVFRSQRTES
/* 1869 */    MCD::OPC_FilterValue, 4, 117, 0, // Skip to: 1990
/* 1873 */    MCD::OPC_CheckField, 16, 5, 0, 111, 0, // Skip to: 1990
/* 1879 */    MCD::OPC_CheckField, 6, 5, 0, 105, 0, // Skip to: 1990
/* 1885 */    MCD::OPC_Decode, 132, 7, 148, 1, // Opcode: QVFRSQRTE
/* 1890 */    MCD::OPC_FilterValue, 56, 21, 0, // Skip to: 1915
/* 1894 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1897 */    MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 1906
/* 1901 */    MCD::OPC_Decode, 231, 6, 154, 1, // Opcode: QVFMSUBSs
/* 1906 */    MCD::OPC_FilterValue, 4, 80, 0, // Skip to: 1990
/* 1910 */    MCD::OPC_Decode, 229, 6, 137, 1, // Opcode: QVFMSUB
/* 1915 */    MCD::OPC_FilterValue, 58, 21, 0, // Skip to: 1940
/* 1919 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1922 */    MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 1931
/* 1926 */    MCD::OPC_Decode, 225, 6, 154, 1, // Opcode: QVFMADDSs
/* 1931 */    MCD::OPC_FilterValue, 4, 55, 0, // Skip to: 1990
/* 1935 */    MCD::OPC_Decode, 223, 6, 137, 1, // Opcode: QVFMADD
/* 1940 */    MCD::OPC_FilterValue, 60, 21, 0, // Skip to: 1965
/* 1944 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1947 */    MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 1956
/* 1951 */    MCD::OPC_Decode, 244, 6, 154, 1, // Opcode: QVFNMSUBSs
/* 1956 */    MCD::OPC_FilterValue, 4, 30, 0, // Skip to: 1990
/* 1960 */    MCD::OPC_Decode, 242, 6, 137, 1, // Opcode: QVFNMSUB
/* 1965 */    MCD::OPC_FilterValue, 62, 21, 0, // Skip to: 1990
/* 1969 */    MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 1972 */    MCD::OPC_FilterValue, 0, 5, 0, // Skip to: 1981
/* 1976 */    MCD::OPC_Decode, 241, 6, 154, 1, // Opcode: QVFNMADDSs
/* 1981 */    MCD::OPC_FilterValue, 4, 5, 0, // Skip to: 1990
/* 1985 */    MCD::OPC_Decode, 239, 6, 137, 1, // Opcode: QVFNMADD
/* 1990 */    MCD::OPC_Fail,
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
    tmp = fieldFromInstruction(insn, 21, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeSImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 2:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeSImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 3:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 4:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 15, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 5:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 6:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 7:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 8:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 9:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 10:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (decodeSImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 11:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 12:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 4);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 13:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 14:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeSImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 15:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeUImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 16:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeUImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 17:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeSImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 18:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeSImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 19:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeSImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 20:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRC_NOR0RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeSImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 21:
    tmp = fieldFromInstruction(insn, 2, 14);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 22:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCRBITRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 2, 14);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 23:
    tmp = fieldFromInstruction(insn, 5, 7);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 24:
    tmp = fieldFromInstruction(insn, 2, 24);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 25:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 18, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 26:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCRBITRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 27:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCRBITRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCRBITRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCRBITRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 28:
    tmp = fieldFromInstruction(insn, 11, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 29:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 1, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 30:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 1, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 31:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 1, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 32:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (decodeUImmOperand<16>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 33:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (decodeUImmOperand<6>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 5, 1) << 5;
    tmp |= fieldFromInstruction(insn, 6, 5) << 0;
    if (decodeUImmOperand<6>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 34:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (decodeUImmOperand<6>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 5, 1) << 5;
    tmp |= fieldFromInstruction(insn, 6, 5) << 0;
    if (decodeUImmOperand<6>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 35:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 5, 1) << 5;
    tmp |= fieldFromInstruction(insn, 6, 5) << 0;
    if (decodeUImmOperand<6>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 36:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 37:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 38:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 39:
    tmp = fieldFromInstruction(insn, 15, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 40:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 11, 5) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 41:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 42:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 43:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeVRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 44:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 45:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 46:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 47:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 48:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 49:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 50:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 51:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 10);
    if (decodeUImmOperand<10>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 52:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 53:
    tmp = fieldFromInstruction(insn, 21, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 54:
    tmp = fieldFromInstruction(insn, 25, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 55:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCRRC0RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 56:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeCRRC0RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 57:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 58:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRC_NOR0RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeCRBITRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 59:
    tmp = fieldFromInstruction(insn, 12, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 60:
    tmp = fieldFromInstruction(insn, 12, 8);
    if (decodeCRBitMOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 61:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 8);
    if (decodeCRBitMOperand(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 62:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 63:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 64:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 65:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 66:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 67:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 68:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 69:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 70:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 11, 5) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 71:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 72:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 73:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 74:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 75:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 76:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 77:
    tmp = fieldFromInstruction(insn, 21, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 78:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 79:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 80:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 81:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 82:
    tmp = fieldFromInstruction(insn, 21, 2);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 83:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 84:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 85:
    tmp = fieldFromInstruction(insn, 21, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 86:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 87:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 88:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 89:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 90:
    tmp = fieldFromInstruction(insn, 21, 2);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 91:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 92:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 93:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (decodeUImmOperand<5>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 94:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 95:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 96:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 97:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (decodeUImmOperand<6>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 98:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 99:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 21);
    if (decodeMemRIOperands(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 100:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 21);
    if (decodeMemRIOperands(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 101:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 21);
    if (decodeMemRIOperands(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 102:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeG8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 2, 19);
    if (decodeMemRIXOperands(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 103:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 104:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 105:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 106:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 107:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 108:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 109:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 110:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 111:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 112:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 113:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 114:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 8, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 115:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 116:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 117:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 118:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 119:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 120:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 121:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 122:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 123:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 124:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 125:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 126:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 1) << 5;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 2, 1) << 5;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 1, 1) << 5;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 3, 1) << 5;
    tmp |= fieldFromInstruction(insn, 6, 5) << 0;
    if (DecodeVSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 127:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 128:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeCRRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 16, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 129:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 130:
    tmp = fieldFromInstruction(insn, 17, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 25, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 16, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 131:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 132:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 133:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF4RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 134:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 135:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeF8RCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 136:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQBRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 137:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 138:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQBRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQBRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQBRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 7, 4);
    if (decodeUImmOperand<12>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 139:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 9, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 140:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 9, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 141:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 9, 12);
    if (decodeUImmOperand<12>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 142:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 143:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 144:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 145:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 146:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePointerLikeRegClass1(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodePointerLikeRegClass0(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 147:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 148:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 149:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 150:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 151:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 152:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQBRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeQFRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 153:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 154:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeQSRCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
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
