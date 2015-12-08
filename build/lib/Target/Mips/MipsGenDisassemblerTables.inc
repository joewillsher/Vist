/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|*  * Mips Disassembler                                                       *|
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
/* 3 */       MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 15
/* 7 */       MCD::OPC_CheckPredicate, 0, 245, 1, // Skip to: 512
/* 11 */      MCD::OPC_Decode, 139, 3, 0, // Opcode: Bimm16
/* 15 */      MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 27
/* 19 */      MCD::OPC_CheckPredicate, 0, 233, 1, // Skip to: 512
/* 23 */      MCD::OPC_Decode, 137, 3, 1, // Opcode: BeqzRxImm16
/* 27 */      MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 39
/* 31 */      MCD::OPC_CheckPredicate, 0, 221, 1, // Skip to: 512
/* 35 */      MCD::OPC_Decode, 142, 3, 1, // Opcode: BnezRxImm16
/* 39 */      MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 51
/* 43 */      MCD::OPC_CheckPredicate, 0, 209, 1, // Skip to: 512
/* 47 */      MCD::OPC_Decode, 191, 1, 2, // Opcode: AddiuRxRxImm16
/* 51 */      MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 63
/* 55 */      MCD::OPC_CheckPredicate, 0, 197, 1, // Skip to: 512
/* 59 */      MCD::OPC_Decode, 199, 16, 1, // Opcode: SltiRxImm16
/* 63 */      MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 75
/* 67 */      MCD::OPC_CheckPredicate, 0, 185, 1, // Skip to: 512
/* 71 */      MCD::OPC_Decode, 202, 16, 1, // Opcode: SltiuRxImm16
/* 75 */      MCD::OPC_FilterValue, 12, 63, 0, // Skip to: 142
/* 79 */      MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 82 */      MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 94
/* 86 */      MCD::OPC_CheckPredicate, 0, 166, 1, // Skip to: 512
/* 90 */      MCD::OPC_Decode, 145, 3, 0, // Opcode: Bteqz16
/* 94 */      MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 106
/* 98 */      MCD::OPC_CheckPredicate, 0, 154, 1, // Skip to: 512
/* 102 */     MCD::OPC_Decode, 153, 3, 0, // Opcode: Btnez16
/* 106 */     MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 118
/* 110 */     MCD::OPC_CheckPredicate, 0, 142, 1, // Skip to: 512
/* 114 */     MCD::OPC_Decode, 194, 1, 0, // Opcode: AddiuSpImm16
/* 118 */     MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 130
/* 122 */     MCD::OPC_CheckPredicate, 0, 130, 1, // Skip to: 512
/* 126 */     MCD::OPC_Decode, 253, 11, 3, // Opcode: Move32R16
/* 130 */     MCD::OPC_FilterValue, 7, 122, 1, // Skip to: 512
/* 134 */     MCD::OPC_CheckPredicate, 0, 118, 1, // Skip to: 512
/* 138 */     MCD::OPC_Decode, 254, 11, 4, // Opcode: MoveR3216
/* 142 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 154
/* 146 */     MCD::OPC_CheckPredicate, 0, 106, 1, // Skip to: 512
/* 150 */     MCD::OPC_Decode, 228, 9, 1, // Opcode: LiRxImm16
/* 154 */     MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 166
/* 158 */     MCD::OPC_CheckPredicate, 0, 94, 1, // Skip to: 512
/* 162 */     MCD::OPC_Decode, 152, 5, 1, // Opcode: CmpiRxImm16
/* 166 */     MCD::OPC_FilterValue, 22, 8, 0, // Skip to: 178
/* 170 */     MCD::OPC_CheckPredicate, 0, 82, 1, // Skip to: 512
/* 174 */     MCD::OPC_Decode, 238, 9, 1, // Opcode: LwRxPcTcp16
/* 178 */     MCD::OPC_FilterValue, 28, 27, 0, // Skip to: 209
/* 182 */     MCD::OPC_ExtractField, 0, 2,  // Inst{1-0} ...
/* 185 */     MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 197
/* 189 */     MCD::OPC_CheckPredicate, 0, 63, 1, // Skip to: 512
/* 193 */     MCD::OPC_Decode, 196, 1, 5, // Opcode: AdduRxRyRz16
/* 197 */     MCD::OPC_FilterValue, 3, 55, 1, // Skip to: 512
/* 201 */     MCD::OPC_CheckPredicate, 0, 51, 1, // Skip to: 512
/* 205 */     MCD::OPC_Decode, 211, 16, 5, // Opcode: SubuRxRyRz16
/* 209 */     MCD::OPC_FilterValue, 29, 43, 1, // Skip to: 512
/* 213 */     MCD::OPC_ExtractField, 0, 5,  // Inst{4-0} ...
/* 216 */     MCD::OPC_FilterValue, 0, 63, 0, // Skip to: 283
/* 220 */     MCD::OPC_ExtractField, 5, 3,  // Inst{7-5} ...
/* 223 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 235
/* 227 */     MCD::OPC_CheckPredicate, 0, 25, 1, // Skip to: 512
/* 231 */     MCD::OPC_Decode, 231, 8, 0, // Opcode: JumpLinkReg16
/* 235 */     MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 253
/* 239 */     MCD::OPC_CheckPredicate, 0, 13, 1, // Skip to: 512
/* 243 */     MCD::OPC_CheckField, 8, 3, 0, 7, 1, // Skip to: 512
/* 249 */     MCD::OPC_Decode, 228, 8, 0, // Opcode: JrRa16
/* 253 */     MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 265
/* 257 */     MCD::OPC_CheckPredicate, 0, 251, 0, // Skip to: 512
/* 261 */     MCD::OPC_Decode, 230, 8, 1, // Opcode: JrcRx16
/* 265 */     MCD::OPC_FilterValue, 7, 243, 0, // Skip to: 512
/* 269 */     MCD::OPC_CheckPredicate, 0, 239, 0, // Skip to: 512
/* 273 */     MCD::OPC_CheckField, 8, 3, 0, 233, 0, // Skip to: 512
/* 279 */     MCD::OPC_Decode, 229, 8, 0, // Opcode: JrcRa16
/* 283 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 295
/* 287 */     MCD::OPC_CheckPredicate, 0, 221, 0, // Skip to: 512
/* 291 */     MCD::OPC_Decode, 197, 16, 6, // Opcode: SltRxRy16
/* 295 */     MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 307
/* 299 */     MCD::OPC_CheckPredicate, 0, 209, 0, // Skip to: 512
/* 303 */     MCD::OPC_Decode, 205, 16, 6, // Opcode: SltuRxRy16
/* 307 */     MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 319
/* 311 */     MCD::OPC_CheckPredicate, 0, 197, 0, // Skip to: 512
/* 315 */     MCD::OPC_Decode, 195, 16, 7, // Opcode: SllvRxRy16
/* 319 */     MCD::OPC_FilterValue, 5, 14, 0, // Skip to: 337
/* 323 */     MCD::OPC_CheckPredicate, 0, 185, 0, // Skip to: 512
/* 327 */     MCD::OPC_CheckField, 5, 6, 0, 179, 0, // Skip to: 512
/* 333 */     MCD::OPC_Decode, 144, 3, 0, // Opcode: Break16
/* 337 */     MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 349
/* 341 */     MCD::OPC_CheckPredicate, 0, 167, 0, // Skip to: 512
/* 345 */     MCD::OPC_Decode, 210, 16, 7, // Opcode: SrlvRxRy16
/* 349 */     MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 361
/* 353 */     MCD::OPC_CheckPredicate, 0, 155, 0, // Skip to: 512
/* 357 */     MCD::OPC_Decode, 208, 16, 7, // Opcode: SravRxRy16
/* 361 */     MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 373
/* 365 */     MCD::OPC_CheckPredicate, 0, 143, 0, // Skip to: 512
/* 369 */     MCD::OPC_Decode, 151, 5, 6, // Opcode: CmpRxRy16
/* 373 */     MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 385
/* 377 */     MCD::OPC_CheckPredicate, 0, 131, 0, // Skip to: 512
/* 381 */     MCD::OPC_Decode, 197, 1, 7, // Opcode: AndRxRxRy16
/* 385 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 397
/* 389 */     MCD::OPC_CheckPredicate, 0, 119, 0, // Skip to: 512
/* 393 */     MCD::OPC_Decode, 179, 12, 7, // Opcode: OrRxRxRy16
/* 397 */     MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 409
/* 401 */     MCD::OPC_CheckPredicate, 0, 107, 0, // Skip to: 512
/* 405 */     MCD::OPC_Decode, 171, 17, 7, // Opcode: XorRxRxRy16
/* 409 */     MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 421
/* 413 */     MCD::OPC_CheckPredicate, 0, 95, 0, // Skip to: 512
/* 417 */     MCD::OPC_Decode, 163, 12, 6, // Opcode: NotRxRy16
/* 421 */     MCD::OPC_FilterValue, 16, 8, 0, // Skip to: 433
/* 425 */     MCD::OPC_CheckPredicate, 0, 83, 0, // Skip to: 512
/* 429 */     MCD::OPC_Decode, 251, 11, 1, // Opcode: Mfhi16
/* 433 */     MCD::OPC_FilterValue, 17, 27, 0, // Skip to: 464
/* 437 */     MCD::OPC_ExtractField, 5, 3,  // Inst{7-5} ...
/* 440 */     MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 452
/* 444 */     MCD::OPC_CheckPredicate, 0, 64, 0, // Skip to: 512
/* 448 */     MCD::OPC_Decode, 177, 16, 2, // Opcode: SebRx16
/* 452 */     MCD::OPC_FilterValue, 5, 56, 0, // Skip to: 512
/* 456 */     MCD::OPC_CheckPredicate, 0, 52, 0, // Skip to: 512
/* 460 */     MCD::OPC_Decode, 178, 16, 2, // Opcode: SehRx16
/* 464 */     MCD::OPC_FilterValue, 18, 8, 0, // Skip to: 476
/* 468 */     MCD::OPC_CheckPredicate, 0, 40, 0, // Skip to: 512
/* 472 */     MCD::OPC_Decode, 252, 11, 1, // Opcode: Mflo16
/* 476 */     MCD::OPC_FilterValue, 26, 8, 0, // Skip to: 488
/* 480 */     MCD::OPC_CheckPredicate, 0, 28, 0, // Skip to: 512
/* 484 */     MCD::OPC_Decode, 170, 6, 6, // Opcode: DivRxRy16
/* 488 */     MCD::OPC_FilterValue, 27, 8, 0, // Skip to: 500
/* 492 */     MCD::OPC_CheckPredicate, 0, 16, 0, // Skip to: 512
/* 496 */     MCD::OPC_Decode, 171, 6, 6, // Opcode: DivuRxRy16
/* 500 */     MCD::OPC_FilterValue, 29, 8, 0, // Skip to: 512
/* 504 */     MCD::OPC_CheckPredicate, 0, 4, 0, // Skip to: 512
/* 508 */     MCD::OPC_Decode, 162, 12, 6, // Opcode: NegRxRy16
/* 512 */     MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTable32[] = {
/* 0 */       MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 3 */       MCD::OPC_FilterValue, 1, 20, 0, // Skip to: 27
/* 7 */       MCD::OPC_CheckPredicate, 0, 198, 1, // Skip to: 465
/* 11 */      MCD::OPC_CheckField, 27, 5, 30, 192, 1, // Skip to: 465
/* 17 */      MCD::OPC_CheckField, 5, 3, 0, 186, 1, // Skip to: 465
/* 23 */      MCD::OPC_Decode, 190, 1, 1, // Opcode: AddiuRxPcImmX16
/* 27 */      MCD::OPC_FilterValue, 2, 20, 0, // Skip to: 51
/* 31 */      MCD::OPC_CheckPredicate, 0, 174, 1, // Skip to: 465
/* 35 */      MCD::OPC_CheckField, 27, 5, 30, 168, 1, // Skip to: 465
/* 41 */      MCD::OPC_CheckField, 5, 6, 0, 162, 1, // Skip to: 465
/* 47 */      MCD::OPC_Decode, 140, 3, 8, // Opcode: BimmX16
/* 51 */      MCD::OPC_FilterValue, 4, 20, 0, // Skip to: 75
/* 55 */      MCD::OPC_CheckPredicate, 0, 150, 1, // Skip to: 465
/* 59 */      MCD::OPC_CheckField, 27, 5, 30, 144, 1, // Skip to: 465
/* 65 */      MCD::OPC_CheckField, 5, 3, 0, 138, 1, // Skip to: 465
/* 71 */      MCD::OPC_Decode, 138, 3, 1, // Opcode: BeqzRxImmX16
/* 75 */      MCD::OPC_FilterValue, 5, 20, 0, // Skip to: 99
/* 79 */      MCD::OPC_CheckPredicate, 0, 126, 1, // Skip to: 465
/* 83 */      MCD::OPC_CheckField, 27, 5, 30, 120, 1, // Skip to: 465
/* 89 */      MCD::OPC_CheckField, 5, 3, 0, 114, 1, // Skip to: 465
/* 95 */      MCD::OPC_Decode, 143, 3, 1, // Opcode: BnezRxImmX16
/* 99 */      MCD::OPC_FilterValue, 6, 92, 0, // Skip to: 195
/* 103 */     MCD::OPC_ExtractField, 27, 5,  // Inst{31-27} ...
/* 106 */     MCD::OPC_FilterValue, 30, 99, 1, // Skip to: 465
/* 110 */     MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 113 */     MCD::OPC_FilterValue, 0, 39, 0, // Skip to: 156
/* 117 */     MCD::OPC_ExtractField, 0, 5,  // Inst{4-0} ...
/* 120 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 132
/* 124 */     MCD::OPC_CheckPredicate, 0, 28, 0, // Skip to: 156
/* 128 */     MCD::OPC_Decode, 194, 16, 6, // Opcode: SllX16
/* 132 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 144
/* 136 */     MCD::OPC_CheckPredicate, 0, 16, 0, // Skip to: 156
/* 140 */     MCD::OPC_Decode, 209, 16, 6, // Opcode: SrlX16
/* 144 */     MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 156
/* 148 */     MCD::OPC_CheckPredicate, 0, 4, 0, // Skip to: 156
/* 152 */     MCD::OPC_Decode, 207, 16, 6, // Opcode: SraX16
/* 156 */     MCD::OPC_ExtractField, 5, 6,  // Inst{10-5} ...
/* 159 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 171
/* 163 */     MCD::OPC_CheckPredicate, 0, 42, 1, // Skip to: 465
/* 167 */     MCD::OPC_Decode, 152, 3, 0, // Opcode: BteqzX16
/* 171 */     MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 183
/* 175 */     MCD::OPC_CheckPredicate, 0, 30, 1, // Skip to: 465
/* 179 */     MCD::OPC_Decode, 160, 3, 0, // Opcode: BtnezX16
/* 183 */     MCD::OPC_FilterValue, 24, 22, 1, // Skip to: 465
/* 187 */     MCD::OPC_CheckPredicate, 0, 18, 1, // Skip to: 465
/* 191 */     MCD::OPC_Decode, 195, 1, 0, // Opcode: AddiuSpImmX16
/* 195 */     MCD::OPC_FilterValue, 8, 20, 0, // Skip to: 219
/* 199 */     MCD::OPC_CheckPredicate, 0, 6, 1, // Skip to: 465
/* 203 */     MCD::OPC_CheckField, 27, 5, 30, 0, 1, // Skip to: 465
/* 209 */     MCD::OPC_CheckField, 4, 1, 0, 250, 0, // Skip to: 465
/* 215 */     MCD::OPC_Decode, 193, 1, 9, // Opcode: AddiuRxRyOffMemX16
/* 219 */     MCD::OPC_FilterValue, 9, 20, 0, // Skip to: 243
/* 223 */     MCD::OPC_CheckPredicate, 0, 238, 0, // Skip to: 465
/* 227 */     MCD::OPC_CheckField, 27, 5, 30, 232, 0, // Skip to: 465
/* 233 */     MCD::OPC_CheckField, 5, 3, 0, 226, 0, // Skip to: 465
/* 239 */     MCD::OPC_Decode, 189, 1, 1, // Opcode: AddiuRxImmX16
/* 243 */     MCD::OPC_FilterValue, 10, 20, 0, // Skip to: 267
/* 247 */     MCD::OPC_CheckPredicate, 0, 214, 0, // Skip to: 465
/* 251 */     MCD::OPC_CheckField, 27, 5, 30, 208, 0, // Skip to: 465
/* 257 */     MCD::OPC_CheckField, 5, 3, 0, 202, 0, // Skip to: 465
/* 263 */     MCD::OPC_Decode, 200, 16, 1, // Opcode: SltiRxImmX16
/* 267 */     MCD::OPC_FilterValue, 11, 20, 0, // Skip to: 291
/* 271 */     MCD::OPC_CheckPredicate, 0, 190, 0, // Skip to: 465
/* 275 */     MCD::OPC_CheckField, 27, 5, 30, 184, 0, // Skip to: 465
/* 281 */     MCD::OPC_CheckField, 5, 3, 0, 178, 0, // Skip to: 465
/* 287 */     MCD::OPC_Decode, 203, 16, 1, // Opcode: SltiuRxImmX16
/* 291 */     MCD::OPC_FilterValue, 13, 20, 0, // Skip to: 315
/* 295 */     MCD::OPC_CheckPredicate, 0, 166, 0, // Skip to: 465
/* 299 */     MCD::OPC_CheckField, 27, 5, 30, 160, 0, // Skip to: 465
/* 305 */     MCD::OPC_CheckField, 5, 3, 0, 154, 0, // Skip to: 465
/* 311 */     MCD::OPC_Decode, 230, 9, 1, // Opcode: LiRxImmX16
/* 315 */     MCD::OPC_FilterValue, 14, 20, 0, // Skip to: 339
/* 319 */     MCD::OPC_CheckPredicate, 0, 142, 0, // Skip to: 465
/* 323 */     MCD::OPC_CheckField, 27, 5, 30, 136, 0, // Skip to: 465
/* 329 */     MCD::OPC_CheckField, 5, 3, 0, 130, 0, // Skip to: 465
/* 335 */     MCD::OPC_Decode, 153, 5, 1, // Opcode: CmpiRxImmX16
/* 339 */     MCD::OPC_FilterValue, 18, 20, 0, // Skip to: 363
/* 343 */     MCD::OPC_CheckPredicate, 0, 118, 0, // Skip to: 465
/* 347 */     MCD::OPC_CheckField, 27, 5, 30, 112, 0, // Skip to: 465
/* 353 */     MCD::OPC_CheckField, 5, 3, 0, 106, 0, // Skip to: 465
/* 359 */     MCD::OPC_Decode, 241, 9, 1, // Opcode: LwRxSpImmX16
/* 363 */     MCD::OPC_FilterValue, 22, 20, 0, // Skip to: 387
/* 367 */     MCD::OPC_CheckPredicate, 0, 94, 0, // Skip to: 465
/* 371 */     MCD::OPC_CheckField, 27, 5, 30, 88, 0, // Skip to: 465
/* 377 */     MCD::OPC_CheckField, 5, 3, 0, 82, 0, // Skip to: 465
/* 383 */     MCD::OPC_Decode, 239, 9, 1, // Opcode: LwRxPcTcpX16
/* 387 */     MCD::OPC_FilterValue, 24, 14, 0, // Skip to: 405
/* 391 */     MCD::OPC_CheckPredicate, 0, 70, 0, // Skip to: 465
/* 395 */     MCD::OPC_CheckField, 27, 5, 30, 64, 0, // Skip to: 465
/* 401 */     MCD::OPC_Decode, 176, 16, 9, // Opcode: SbRxRyOffMemX16
/* 405 */     MCD::OPC_FilterValue, 25, 14, 0, // Skip to: 423
/* 409 */     MCD::OPC_CheckPredicate, 0, 52, 0, // Skip to: 465
/* 413 */     MCD::OPC_CheckField, 27, 5, 30, 46, 0, // Skip to: 465
/* 419 */     MCD::OPC_Decode, 193, 16, 9, // Opcode: ShRxRyOffMemX16
/* 423 */     MCD::OPC_FilterValue, 26, 20, 0, // Skip to: 447
/* 427 */     MCD::OPC_CheckPredicate, 0, 34, 0, // Skip to: 465
/* 431 */     MCD::OPC_CheckField, 27, 5, 30, 28, 0, // Skip to: 465
/* 437 */     MCD::OPC_CheckField, 5, 3, 0, 22, 0, // Skip to: 465
/* 443 */     MCD::OPC_Decode, 213, 16, 1, // Opcode: SwRxSpImmX16
/* 447 */     MCD::OPC_FilterValue, 27, 14, 0, // Skip to: 465
/* 451 */     MCD::OPC_CheckPredicate, 0, 10, 0, // Skip to: 465
/* 455 */     MCD::OPC_CheckField, 27, 5, 30, 4, 0, // Skip to: 465
/* 461 */     MCD::OPC_Decode, 212, 16, 9, // Opcode: SwRxRyOffMemX16
/* 465 */     MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableCOP3_32[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 51, 8, 0, // Skip to: 15
/* 7 */       MCD::OPC_CheckPredicate, 1, 40, 0, // Skip to: 51
/* 11 */      MCD::OPC_Decode, 191, 9, 10, // Opcode: LWC3
/* 15 */      MCD::OPC_FilterValue, 55, 8, 0, // Skip to: 27
/* 19 */      MCD::OPC_CheckPredicate, 2, 28, 0, // Skip to: 51
/* 23 */      MCD::OPC_Decode, 255, 8, 10, // Opcode: LDC3
/* 27 */      MCD::OPC_FilterValue, 59, 8, 0, // Skip to: 39
/* 31 */      MCD::OPC_CheckPredicate, 1, 16, 0, // Skip to: 51
/* 35 */      MCD::OPC_Decode, 137, 16, 10, // Opcode: SWC3
/* 39 */      MCD::OPC_FilterValue, 63, 8, 0, // Skip to: 51
/* 43 */      MCD::OPC_CheckPredicate, 2, 4, 0, // Skip to: 51
/* 47 */      MCD::OPC_Decode, 251, 13, 10, // Opcode: SDC3
/* 51 */      MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableCnMips32[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 18, 27, 0, // Skip to: 34
/* 7 */       MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 10 */      MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 22
/* 14 */      MCD::OPC_CheckPredicate, 3, 169, 1, // Skip to: 443
/* 18 */      MCD::OPC_Decode, 206, 5, 11, // Opcode: DMFC2_OCTEON
/* 22 */      MCD::OPC_FilterValue, 5, 161, 1, // Skip to: 443
/* 26 */      MCD::OPC_CheckPredicate, 3, 157, 1, // Skip to: 443
/* 30 */      MCD::OPC_Decode, 214, 5, 11, // Opcode: DMTC2_OCTEON
/* 34 */      MCD::OPC_FilterValue, 28, 101, 1, // Skip to: 395
/* 38 */      MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 41 */      MCD::OPC_FilterValue, 3, 14, 0, // Skip to: 59
/* 45 */      MCD::OPC_CheckPredicate, 3, 138, 1, // Skip to: 443
/* 49 */      MCD::OPC_CheckField, 6, 5, 0, 132, 1, // Skip to: 443
/* 55 */      MCD::OPC_Decode, 217, 5, 12, // Opcode: DMUL
/* 59 */      MCD::OPC_FilterValue, 8, 14, 0, // Skip to: 77
/* 63 */      MCD::OPC_CheckPredicate, 3, 120, 1, // Skip to: 443
/* 67 */      MCD::OPC_CheckField, 6, 15, 0, 114, 1, // Skip to: 443
/* 73 */      MCD::OPC_Decode, 197, 11, 13, // Opcode: MTM0
/* 77 */      MCD::OPC_FilterValue, 9, 14, 0, // Skip to: 95
/* 81 */      MCD::OPC_CheckPredicate, 3, 102, 1, // Skip to: 443
/* 85 */      MCD::OPC_CheckField, 6, 15, 0, 96, 1, // Skip to: 443
/* 91 */      MCD::OPC_Decode, 200, 11, 13, // Opcode: MTP0
/* 95 */      MCD::OPC_FilterValue, 10, 14, 0, // Skip to: 113
/* 99 */      MCD::OPC_CheckPredicate, 3, 84, 1, // Skip to: 443
/* 103 */     MCD::OPC_CheckField, 6, 15, 0, 78, 1, // Skip to: 443
/* 109 */     MCD::OPC_Decode, 201, 11, 13, // Opcode: MTP1
/* 113 */     MCD::OPC_FilterValue, 11, 14, 0, // Skip to: 131
/* 117 */     MCD::OPC_CheckPredicate, 3, 66, 1, // Skip to: 443
/* 121 */     MCD::OPC_CheckField, 6, 15, 0, 60, 1, // Skip to: 443
/* 127 */     MCD::OPC_Decode, 202, 11, 13, // Opcode: MTP2
/* 131 */     MCD::OPC_FilterValue, 12, 14, 0, // Skip to: 149
/* 135 */     MCD::OPC_CheckPredicate, 3, 48, 1, // Skip to: 443
/* 139 */     MCD::OPC_CheckField, 6, 15, 0, 42, 1, // Skip to: 443
/* 145 */     MCD::OPC_Decode, 198, 11, 13, // Opcode: MTM1
/* 149 */     MCD::OPC_FilterValue, 13, 14, 0, // Skip to: 167
/* 153 */     MCD::OPC_CheckPredicate, 3, 30, 1, // Skip to: 443
/* 157 */     MCD::OPC_CheckField, 6, 15, 0, 24, 1, // Skip to: 443
/* 163 */     MCD::OPC_Decode, 199, 11, 13, // Opcode: MTM2
/* 167 */     MCD::OPC_FilterValue, 15, 14, 0, // Skip to: 185
/* 171 */     MCD::OPC_CheckPredicate, 3, 12, 1, // Skip to: 443
/* 175 */     MCD::OPC_CheckField, 6, 5, 0, 6, 1, // Skip to: 443
/* 181 */     MCD::OPC_Decode, 143, 17, 12, // Opcode: VMULU
/* 185 */     MCD::OPC_FilterValue, 16, 14, 0, // Skip to: 203
/* 189 */     MCD::OPC_CheckPredicate, 3, 250, 0, // Skip to: 443
/* 193 */     MCD::OPC_CheckField, 6, 5, 0, 244, 0, // Skip to: 443
/* 199 */     MCD::OPC_Decode, 142, 17, 12, // Opcode: VMM0
/* 203 */     MCD::OPC_FilterValue, 17, 14, 0, // Skip to: 221
/* 207 */     MCD::OPC_CheckPredicate, 3, 232, 0, // Skip to: 443
/* 211 */     MCD::OPC_CheckField, 6, 5, 0, 226, 0, // Skip to: 443
/* 217 */     MCD::OPC_Decode, 141, 17, 12, // Opcode: V3MULU
/* 221 */     MCD::OPC_FilterValue, 40, 14, 0, // Skip to: 239
/* 225 */     MCD::OPC_CheckPredicate, 3, 214, 0, // Skip to: 443
/* 229 */     MCD::OPC_CheckField, 6, 5, 0, 208, 0, // Skip to: 443
/* 235 */     MCD::OPC_Decode, 200, 1, 12, // Opcode: BADDu
/* 239 */     MCD::OPC_FilterValue, 42, 14, 0, // Skip to: 257
/* 243 */     MCD::OPC_CheckPredicate, 3, 196, 0, // Skip to: 443
/* 247 */     MCD::OPC_CheckField, 6, 5, 0, 190, 0, // Skip to: 443
/* 253 */     MCD::OPC_Decode, 157, 14, 12, // Opcode: SEQ
/* 257 */     MCD::OPC_FilterValue, 43, 14, 0, // Skip to: 275
/* 261 */     MCD::OPC_CheckPredicate, 3, 178, 0, // Skip to: 443
/* 265 */     MCD::OPC_CheckField, 6, 5, 0, 172, 0, // Skip to: 443
/* 271 */     MCD::OPC_Decode, 254, 14, 12, // Opcode: SNE
/* 275 */     MCD::OPC_FilterValue, 44, 20, 0, // Skip to: 299
/* 279 */     MCD::OPC_CheckPredicate, 3, 160, 0, // Skip to: 443
/* 283 */     MCD::OPC_CheckField, 16, 5, 0, 154, 0, // Skip to: 443
/* 289 */     MCD::OPC_CheckField, 6, 5, 0, 148, 0, // Skip to: 443
/* 295 */     MCD::OPC_Decode, 198, 12, 14, // Opcode: POP
/* 299 */     MCD::OPC_FilterValue, 45, 20, 0, // Skip to: 323
/* 303 */     MCD::OPC_CheckPredicate, 3, 136, 0, // Skip to: 443
/* 307 */     MCD::OPC_CheckField, 16, 5, 0, 130, 0, // Skip to: 443
/* 313 */     MCD::OPC_CheckField, 6, 5, 0, 124, 0, // Skip to: 443
/* 319 */     MCD::OPC_Decode, 250, 5, 15, // Opcode: DPOP
/* 323 */     MCD::OPC_FilterValue, 46, 8, 0, // Skip to: 335
/* 327 */     MCD::OPC_CheckPredicate, 3, 112, 0, // Skip to: 443
/* 331 */     MCD::OPC_Decode, 158, 14, 16, // Opcode: SEQi
/* 335 */     MCD::OPC_FilterValue, 47, 8, 0, // Skip to: 347
/* 339 */     MCD::OPC_CheckPredicate, 3, 100, 0, // Skip to: 443
/* 343 */     MCD::OPC_Decode, 255, 14, 16, // Opcode: SNEi
/* 347 */     MCD::OPC_FilterValue, 50, 8, 0, // Skip to: 359
/* 351 */     MCD::OPC_CheckPredicate, 3, 88, 0, // Skip to: 443
/* 355 */     MCD::OPC_Decode, 192, 3, 17, // Opcode: CINS
/* 359 */     MCD::OPC_FilterValue, 51, 8, 0, // Skip to: 371
/* 363 */     MCD::OPC_CheckPredicate, 3, 76, 0, // Skip to: 443
/* 367 */     MCD::OPC_Decode, 193, 3, 17, // Opcode: CINS32
/* 371 */     MCD::OPC_FilterValue, 58, 8, 0, // Skip to: 383
/* 375 */     MCD::OPC_CheckPredicate, 3, 64, 0, // Skip to: 443
/* 379 */     MCD::OPC_Decode, 209, 6, 17, // Opcode: EXTS
/* 383 */     MCD::OPC_FilterValue, 59, 56, 0, // Skip to: 443
/* 387 */     MCD::OPC_CheckPredicate, 3, 52, 0, // Skip to: 443
/* 391 */     MCD::OPC_Decode, 210, 6, 17, // Opcode: EXTS32
/* 395 */     MCD::OPC_FilterValue, 50, 8, 0, // Skip to: 407
/* 399 */     MCD::OPC_CheckPredicate, 3, 40, 0, // Skip to: 443
/* 403 */     MCD::OPC_Decode, 206, 1, 18, // Opcode: BBIT0
/* 407 */     MCD::OPC_FilterValue, 54, 8, 0, // Skip to: 419
/* 411 */     MCD::OPC_CheckPredicate, 3, 28, 0, // Skip to: 443
/* 415 */     MCD::OPC_Decode, 207, 1, 18, // Opcode: BBIT032
/* 419 */     MCD::OPC_FilterValue, 58, 8, 0, // Skip to: 431
/* 423 */     MCD::OPC_CheckPredicate, 3, 16, 0, // Skip to: 443
/* 427 */     MCD::OPC_Decode, 208, 1, 18, // Opcode: BBIT1
/* 431 */     MCD::OPC_FilterValue, 62, 8, 0, // Skip to: 443
/* 435 */     MCD::OPC_CheckPredicate, 3, 4, 0, // Skip to: 443
/* 439 */     MCD::OPC_Decode, 209, 1, 18, // Opcode: BBIT132
/* 443 */     MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableMicroMips16[] = {
/* 0 */       MCD::OPC_ExtractField, 10, 6,  // Inst{15-10} ...
/* 3 */       MCD::OPC_FilterValue, 1, 26, 0, // Skip to: 33
/* 7 */       MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 10 */      MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 21
/* 14 */      MCD::OPC_CheckPredicate, 4, 19, 2, // Skip to: 549
/* 18 */      MCD::OPC_Decode, 68, 19, // Opcode: ADDU16_MM
/* 21 */      MCD::OPC_FilterValue, 1, 12, 2, // Skip to: 549
/* 25 */      MCD::OPC_CheckPredicate, 4, 8, 2, // Skip to: 549
/* 29 */      MCD::OPC_Decode, 227, 15, 19, // Opcode: SUBU16_MM
/* 33 */      MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 45
/* 37 */      MCD::OPC_CheckPredicate, 5, 252, 1, // Skip to: 549
/* 41 */      MCD::OPC_Decode, 237, 8, 20, // Opcode: LBU16_MM
/* 45 */      MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 57
/* 49 */      MCD::OPC_CheckPredicate, 5, 240, 1, // Skip to: 549
/* 53 */      MCD::OPC_Decode, 237, 10, 21, // Opcode: MOVE16_MM
/* 57 */      MCD::OPC_FilterValue, 9, 27, 0, // Skip to: 88
/* 61 */      MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 64 */      MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 76
/* 68 */      MCD::OPC_CheckPredicate, 4, 221, 1, // Skip to: 549
/* 72 */      MCD::OPC_Decode, 226, 14, 22, // Opcode: SLL16_MM
/* 76 */      MCD::OPC_FilterValue, 1, 213, 1, // Skip to: 549
/* 80 */      MCD::OPC_CheckPredicate, 4, 209, 1, // Skip to: 549
/* 84 */      MCD::OPC_Decode, 164, 15, 22, // Opcode: SRL16_MM
/* 88 */      MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 100
/* 92 */      MCD::OPC_CheckPredicate, 5, 197, 1, // Skip to: 549
/* 96 */      MCD::OPC_Decode, 148, 9, 20, // Opcode: LHU16_MM
/* 100 */     MCD::OPC_FilterValue, 11, 7, 0, // Skip to: 111
/* 104 */     MCD::OPC_CheckPredicate, 4, 185, 1, // Skip to: 549
/* 108 */     MCD::OPC_Decode, 115, 23, // Opcode: ANDI16_MM
/* 111 */     MCD::OPC_FilterValue, 17, 226, 0, // Skip to: 341
/* 115 */     MCD::OPC_ExtractField, 6, 4,  // Inst{9-6} ...
/* 118 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 130
/* 122 */     MCD::OPC_CheckPredicate, 4, 167, 1, // Skip to: 549
/* 126 */     MCD::OPC_Decode, 160, 12, 24, // Opcode: NOT16_MM
/* 130 */     MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 142
/* 134 */     MCD::OPC_CheckPredicate, 4, 155, 1, // Skip to: 549
/* 138 */     MCD::OPC_Decode, 157, 17, 25, // Opcode: XOR16_MM
/* 142 */     MCD::OPC_FilterValue, 2, 7, 0, // Skip to: 153
/* 146 */     MCD::OPC_CheckPredicate, 4, 143, 1, // Skip to: 549
/* 150 */     MCD::OPC_Decode, 112, 25, // Opcode: AND16_MM
/* 153 */     MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 165
/* 157 */     MCD::OPC_CheckPredicate, 4, 132, 1, // Skip to: 549
/* 161 */     MCD::OPC_Decode, 165, 12, 25, // Opcode: OR16_MM
/* 165 */     MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 177
/* 169 */     MCD::OPC_CheckPredicate, 6, 120, 1, // Skip to: 549
/* 173 */     MCD::OPC_Decode, 201, 9, 26, // Opcode: LWM16_MM
/* 177 */     MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 189
/* 181 */     MCD::OPC_CheckPredicate, 6, 108, 1, // Skip to: 549
/* 185 */     MCD::OPC_Decode, 146, 16, 26, // Opcode: SWM16_MM
/* 189 */     MCD::OPC_FilterValue, 6, 27, 0, // Skip to: 220
/* 193 */     MCD::OPC_ExtractField, 5, 1,  // Inst{5} ...
/* 196 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 208
/* 200 */     MCD::OPC_CheckPredicate, 5, 89, 1, // Skip to: 549
/* 204 */     MCD::OPC_Decode, 214, 8, 27, // Opcode: JR16_MM
/* 208 */     MCD::OPC_FilterValue, 1, 81, 1, // Skip to: 549
/* 212 */     MCD::OPC_CheckPredicate, 5, 77, 1, // Skip to: 549
/* 216 */     MCD::OPC_Decode, 217, 8, 27, // Opcode: JRC16_MM
/* 220 */     MCD::OPC_FilterValue, 7, 27, 0, // Skip to: 251
/* 224 */     MCD::OPC_ExtractField, 5, 1,  // Inst{5} ...
/* 227 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 239
/* 231 */     MCD::OPC_CheckPredicate, 6, 58, 1, // Skip to: 549
/* 235 */     MCD::OPC_Decode, 196, 8, 27, // Opcode: JALR16_MM
/* 239 */     MCD::OPC_FilterValue, 1, 50, 1, // Skip to: 549
/* 243 */     MCD::OPC_CheckPredicate, 5, 46, 1, // Skip to: 549
/* 247 */     MCD::OPC_Decode, 201, 8, 27, // Opcode: JALRS16_MM
/* 251 */     MCD::OPC_FilterValue, 8, 14, 0, // Skip to: 269
/* 255 */     MCD::OPC_CheckPredicate, 5, 34, 1, // Skip to: 549
/* 259 */     MCD::OPC_CheckField, 5, 1, 0, 28, 1, // Skip to: 549
/* 265 */     MCD::OPC_Decode, 183, 10, 27, // Opcode: MFHI16_MM
/* 269 */     MCD::OPC_FilterValue, 9, 14, 0, // Skip to: 287
/* 273 */     MCD::OPC_CheckPredicate, 5, 16, 1, // Skip to: 549
/* 277 */     MCD::OPC_CheckField, 5, 1, 0, 10, 1, // Skip to: 549
/* 283 */     MCD::OPC_Decode, 189, 10, 27, // Opcode: MFLO16_MM
/* 287 */     MCD::OPC_FilterValue, 10, 14, 0, // Skip to: 305
/* 291 */     MCD::OPC_CheckPredicate, 4, 254, 0, // Skip to: 549
/* 295 */     MCD::OPC_CheckField, 4, 2, 0, 248, 0, // Skip to: 549
/* 301 */     MCD::OPC_Decode, 238, 2, 28, // Opcode: BREAK16_MM
/* 305 */     MCD::OPC_FilterValue, 11, 14, 0, // Skip to: 323
/* 309 */     MCD::OPC_CheckPredicate, 4, 236, 0, // Skip to: 549
/* 313 */     MCD::OPC_CheckField, 4, 2, 0, 230, 0, // Skip to: 549
/* 319 */     MCD::OPC_Decode, 241, 13, 28, // Opcode: SDBBP16_MM
/* 323 */     MCD::OPC_FilterValue, 12, 222, 0, // Skip to: 549
/* 327 */     MCD::OPC_CheckPredicate, 5, 218, 0, // Skip to: 549
/* 331 */     MCD::OPC_CheckField, 5, 1, 0, 212, 0, // Skip to: 549
/* 337 */     MCD::OPC_Decode, 216, 8, 29, // Opcode: JRADDIUSP
/* 341 */     MCD::OPC_FilterValue, 18, 8, 0, // Skip to: 353
/* 345 */     MCD::OPC_CheckPredicate, 5, 200, 0, // Skip to: 549
/* 349 */     MCD::OPC_Decode, 213, 9, 30, // Opcode: LWSP_MM
/* 353 */     MCD::OPC_FilterValue, 19, 25, 0, // Skip to: 382
/* 357 */     MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 360 */     MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 371
/* 364 */     MCD::OPC_CheckPredicate, 5, 181, 0, // Skip to: 549
/* 368 */     MCD::OPC_Decode, 37, 31, // Opcode: ADDIUS5_MM
/* 371 */     MCD::OPC_FilterValue, 1, 174, 0, // Skip to: 549
/* 375 */     MCD::OPC_CheckPredicate, 5, 170, 0, // Skip to: 549
/* 379 */     MCD::OPC_Decode, 38, 32, // Opcode: ADDIUSP_MM
/* 382 */     MCD::OPC_FilterValue, 25, 8, 0, // Skip to: 394
/* 386 */     MCD::OPC_CheckPredicate, 5, 159, 0, // Skip to: 549
/* 390 */     MCD::OPC_Decode, 195, 9, 33, // Opcode: LWGP_MM
/* 394 */     MCD::OPC_FilterValue, 26, 8, 0, // Skip to: 406
/* 398 */     MCD::OPC_CheckPredicate, 5, 147, 0, // Skip to: 549
/* 402 */     MCD::OPC_Decode, 185, 9, 20, // Opcode: LW16_MM
/* 406 */     MCD::OPC_FilterValue, 27, 25, 0, // Skip to: 435
/* 410 */     MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 413 */     MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 424
/* 417 */     MCD::OPC_CheckPredicate, 5, 128, 0, // Skip to: 549
/* 421 */     MCD::OPC_Decode, 36, 34, // Opcode: ADDIUR2_MM
/* 424 */     MCD::OPC_FilterValue, 1, 121, 0, // Skip to: 549
/* 428 */     MCD::OPC_CheckPredicate, 5, 117, 0, // Skip to: 549
/* 432 */     MCD::OPC_Decode, 35, 35, // Opcode: ADDIUR1SP_MM
/* 435 */     MCD::OPC_FilterValue, 33, 14, 0, // Skip to: 453
/* 439 */     MCD::OPC_CheckPredicate, 5, 106, 0, // Skip to: 549
/* 443 */     MCD::OPC_CheckField, 0, 1, 0, 100, 0, // Skip to: 549
/* 449 */     MCD::OPC_Decode, 239, 10, 36, // Opcode: MOVEP_MM
/* 453 */     MCD::OPC_FilterValue, 34, 8, 0, // Skip to: 465
/* 457 */     MCD::OPC_CheckPredicate, 5, 88, 0, // Skip to: 549
/* 461 */     MCD::OPC_Decode, 223, 13, 20, // Opcode: SB16_MM
/* 465 */     MCD::OPC_FilterValue, 35, 8, 0, // Skip to: 477
/* 469 */     MCD::OPC_CheckPredicate, 5, 76, 0, // Skip to: 549
/* 473 */     MCD::OPC_Decode, 235, 1, 37, // Opcode: BEQZ16_MM
/* 477 */     MCD::OPC_FilterValue, 42, 8, 0, // Skip to: 489
/* 481 */     MCD::OPC_CheckPredicate, 5, 64, 0, // Skip to: 549
/* 485 */     MCD::OPC_Decode, 160, 14, 20, // Opcode: SH16_MM
/* 489 */     MCD::OPC_FilterValue, 43, 8, 0, // Skip to: 501
/* 493 */     MCD::OPC_CheckPredicate, 5, 52, 0, // Skip to: 549
/* 497 */     MCD::OPC_Decode, 221, 2, 37, // Opcode: BNEZ16_MM
/* 501 */     MCD::OPC_FilterValue, 50, 8, 0, // Skip to: 513
/* 505 */     MCD::OPC_CheckPredicate, 5, 40, 0, // Skip to: 549
/* 509 */     MCD::OPC_Decode, 156, 16, 30, // Opcode: SWSP_MM
/* 513 */     MCD::OPC_FilterValue, 51, 8, 0, // Skip to: 525
/* 517 */     MCD::OPC_CheckPredicate, 5, 28, 0, // Skip to: 549
/* 521 */     MCD::OPC_Decode, 199, 1, 38, // Opcode: B16_MM
/* 525 */     MCD::OPC_FilterValue, 58, 8, 0, // Skip to: 537
/* 529 */     MCD::OPC_CheckPredicate, 5, 16, 0, // Skip to: 549
/* 533 */     MCD::OPC_Decode, 130, 16, 20, // Opcode: SW16_MM
/* 537 */     MCD::OPC_FilterValue, 59, 8, 0, // Skip to: 549
/* 541 */     MCD::OPC_CheckPredicate, 5, 4, 0, // Skip to: 549
/* 545 */     MCD::OPC_Decode, 157, 9, 39, // Opcode: LI16_MM
/* 549 */     MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableMicroMips32[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 0, 215, 10, // Skip to: 2782
/* 7 */       MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 10 */      MCD::OPC_FilterValue, 0, 90, 0, // Skip to: 104
/* 14 */      MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 17 */      MCD::OPC_FilterValue, 0, 47, 0, // Skip to: 68
/* 21 */      MCD::OPC_ExtractField, 11, 15,  // Inst{25-11} ...
/* 24 */      MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 36
/* 28 */      MCD::OPC_CheckPredicate, 5, 28, 0, // Skip to: 60
/* 32 */      MCD::OPC_Decode, 186, 15, 0, // Opcode: SSNOP_MM
/* 36 */      MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 48
/* 40 */      MCD::OPC_CheckPredicate, 5, 16, 0, // Skip to: 60
/* 44 */      MCD::OPC_Decode, 173, 6, 0, // Opcode: EHB_MM
/* 48 */      MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 60
/* 52 */      MCD::OPC_CheckPredicate, 5, 4, 0, // Skip to: 60
/* 56 */      MCD::OPC_Decode, 182, 12, 0, // Opcode: PAUSE_MM
/* 60 */      MCD::OPC_CheckPredicate, 5, 33, 14, // Skip to: 3681
/* 64 */      MCD::OPC_Decode, 239, 14, 40, // Opcode: SLL_MM
/* 68 */      MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 80
/* 72 */      MCD::OPC_CheckPredicate, 5, 21, 14, // Skip to: 3681
/* 76 */      MCD::OPC_Decode, 183, 15, 40, // Opcode: SRL_MM
/* 80 */      MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 92
/* 84 */      MCD::OPC_CheckPredicate, 5, 9, 14, // Skip to: 3681
/* 88 */      MCD::OPC_Decode, 161, 15, 40, // Opcode: SRA_MM
/* 92 */      MCD::OPC_FilterValue, 3, 1, 14, // Skip to: 3681
/* 96 */      MCD::OPC_CheckPredicate, 5, 253, 13, // Skip to: 3681
/* 100 */     MCD::OPC_Decode, 196, 13, 40, // Opcode: ROTR_MM
/* 104 */     MCD::OPC_FilterValue, 5, 48, 0, // Skip to: 156
/* 108 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 111 */     MCD::OPC_FilterValue, 12, 7, 0, // Skip to: 122
/* 115 */     MCD::OPC_CheckPredicate, 7, 234, 13, // Skip to: 3681
/* 119 */     MCD::OPC_Decode, 53, 41, // Opcode: ADDQ_S_W_MM
/* 122 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 134
/* 126 */     MCD::OPC_CheckPredicate, 7, 223, 13, // Skip to: 3681
/* 130 */     MCD::OPC_Decode, 210, 15, 41, // Opcode: SUBQ_S_W_MM
/* 134 */     MCD::OPC_FilterValue, 14, 7, 0, // Skip to: 145
/* 138 */     MCD::OPC_CheckPredicate, 7, 211, 13, // Skip to: 3681
/* 142 */     MCD::OPC_Decode, 55, 41, // Opcode: ADDSC_MM
/* 145 */     MCD::OPC_FilterValue, 15, 204, 13, // Skip to: 3681
/* 149 */     MCD::OPC_CheckPredicate, 7, 200, 13, // Skip to: 3681
/* 153 */     MCD::OPC_Decode, 92, 41, // Opcode: ADDWC_MM
/* 156 */     MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 168
/* 160 */     MCD::OPC_CheckPredicate, 5, 189, 13, // Skip to: 3681
/* 164 */     MCD::OPC_Decode, 240, 2, 42, // Opcode: BREAK_MM
/* 168 */     MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 180
/* 172 */     MCD::OPC_CheckPredicate, 5, 177, 13, // Skip to: 3681
/* 176 */     MCD::OPC_Decode, 192, 8, 43, // Opcode: INS_MM
/* 180 */     MCD::OPC_FilterValue, 13, 95, 1, // Skip to: 535
/* 184 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 187 */     MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 198
/* 191 */     MCD::OPC_CheckPredicate, 7, 158, 13, // Skip to: 3681
/* 195 */     MCD::OPC_Decode, 49, 44, // Opcode: ADDQ_PH_MM
/* 198 */     MCD::OPC_FilterValue, 1, 7, 0, // Skip to: 209
/* 202 */     MCD::OPC_CheckPredicate, 8, 147, 13, // Skip to: 3681
/* 206 */     MCD::OPC_Decode, 41, 44, // Opcode: ADDQH_PH_MMR2
/* 209 */     MCD::OPC_FilterValue, 2, 7, 0, // Skip to: 220
/* 213 */     MCD::OPC_CheckPredicate, 8, 136, 13, // Skip to: 3681
/* 217 */     MCD::OPC_Decode, 47, 41, // Opcode: ADDQH_W_MMR2
/* 220 */     MCD::OPC_FilterValue, 3, 7, 0, // Skip to: 231
/* 224 */     MCD::OPC_CheckPredicate, 7, 125, 13, // Skip to: 3681
/* 228 */     MCD::OPC_Decode, 78, 44, // Opcode: ADDU_QB_MM
/* 231 */     MCD::OPC_FilterValue, 4, 7, 0, // Skip to: 242
/* 235 */     MCD::OPC_CheckPredicate, 8, 114, 13, // Skip to: 3681
/* 239 */     MCD::OPC_Decode, 76, 44, // Opcode: ADDU_PH_MMR2
/* 242 */     MCD::OPC_FilterValue, 5, 7, 0, // Skip to: 253
/* 246 */     MCD::OPC_CheckPredicate, 8, 103, 13, // Skip to: 3681
/* 250 */     MCD::OPC_Decode, 71, 44, // Opcode: ADDUH_QB_MMR2
/* 253 */     MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 265
/* 257 */     MCD::OPC_CheckPredicate, 7, 92, 13, // Skip to: 3681
/* 261 */     MCD::OPC_Decode, 188, 14, 45, // Opcode: SHRAV_PH_MM
/* 265 */     MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 277
/* 269 */     MCD::OPC_CheckPredicate, 8, 80, 13, // Skip to: 3681
/* 273 */     MCD::OPC_Decode, 190, 14, 45, // Opcode: SHRAV_QB_MMR2
/* 277 */     MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 289
/* 281 */     MCD::OPC_CheckPredicate, 7, 68, 13, // Skip to: 3681
/* 285 */     MCD::OPC_Decode, 206, 15, 44, // Opcode: SUBQ_PH_MM
/* 289 */     MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 301
/* 293 */     MCD::OPC_CheckPredicate, 8, 56, 13, // Skip to: 3681
/* 297 */     MCD::OPC_Decode, 198, 15, 44, // Opcode: SUBQH_PH_MMR2
/* 301 */     MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 313
/* 305 */     MCD::OPC_CheckPredicate, 8, 44, 13, // Skip to: 3681
/* 309 */     MCD::OPC_Decode, 204, 15, 41, // Opcode: SUBQH_W_MMR2
/* 313 */     MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 325
/* 317 */     MCD::OPC_CheckPredicate, 7, 32, 13, // Skip to: 3681
/* 321 */     MCD::OPC_Decode, 237, 15, 44, // Opcode: SUBU_QB_MM
/* 325 */     MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 337
/* 329 */     MCD::OPC_CheckPredicate, 8, 20, 13, // Skip to: 3681
/* 333 */     MCD::OPC_Decode, 235, 15, 44, // Opcode: SUBU_PH_MMR2
/* 337 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 349
/* 341 */     MCD::OPC_CheckPredicate, 8, 8, 13, // Skip to: 3681
/* 345 */     MCD::OPC_Decode, 230, 15, 44, // Opcode: SUBUH_QB_MMR2
/* 349 */     MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 361
/* 353 */     MCD::OPC_CheckPredicate, 8, 252, 12, // Skip to: 3681
/* 357 */     MCD::OPC_Decode, 230, 12, 46, // Opcode: PRECR_SRA_PH_W_MMR2
/* 361 */     MCD::OPC_FilterValue, 16, 7, 0, // Skip to: 372
/* 365 */     MCD::OPC_CheckPredicate, 7, 240, 12, // Skip to: 3681
/* 369 */     MCD::OPC_Decode, 51, 44, // Opcode: ADDQ_S_PH_MM
/* 372 */     MCD::OPC_FilterValue, 17, 7, 0, // Skip to: 383
/* 376 */     MCD::OPC_CheckPredicate, 8, 229, 12, // Skip to: 3681
/* 380 */     MCD::OPC_Decode, 43, 44, // Opcode: ADDQH_R_PH_MMR2
/* 383 */     MCD::OPC_FilterValue, 18, 7, 0, // Skip to: 394
/* 387 */     MCD::OPC_CheckPredicate, 8, 218, 12, // Skip to: 3681
/* 391 */     MCD::OPC_Decode, 45, 41, // Opcode: ADDQH_R_W_MMR2
/* 394 */     MCD::OPC_FilterValue, 19, 7, 0, // Skip to: 405
/* 398 */     MCD::OPC_CheckPredicate, 7, 207, 12, // Skip to: 3681
/* 402 */     MCD::OPC_Decode, 82, 44, // Opcode: ADDU_S_QB_MM
/* 405 */     MCD::OPC_FilterValue, 20, 7, 0, // Skip to: 416
/* 409 */     MCD::OPC_CheckPredicate, 8, 196, 12, // Skip to: 3681
/* 413 */     MCD::OPC_Decode, 80, 44, // Opcode: ADDU_S_PH_MMR2
/* 416 */     MCD::OPC_FilterValue, 21, 7, 0, // Skip to: 427
/* 420 */     MCD::OPC_CheckPredicate, 8, 185, 12, // Skip to: 3681
/* 424 */     MCD::OPC_Decode, 73, 44, // Opcode: ADDUH_R_QB_MMR2
/* 427 */     MCD::OPC_FilterValue, 22, 8, 0, // Skip to: 439
/* 431 */     MCD::OPC_CheckPredicate, 7, 174, 12, // Skip to: 3681
/* 435 */     MCD::OPC_Decode, 192, 14, 45, // Opcode: SHRAV_R_PH_MM
/* 439 */     MCD::OPC_FilterValue, 23, 8, 0, // Skip to: 451
/* 443 */     MCD::OPC_CheckPredicate, 8, 162, 12, // Skip to: 3681
/* 447 */     MCD::OPC_Decode, 194, 14, 45, // Opcode: SHRAV_R_QB_MMR2
/* 451 */     MCD::OPC_FilterValue, 24, 8, 0, // Skip to: 463
/* 455 */     MCD::OPC_CheckPredicate, 7, 150, 12, // Skip to: 3681
/* 459 */     MCD::OPC_Decode, 208, 15, 44, // Opcode: SUBQ_S_PH_MM
/* 463 */     MCD::OPC_FilterValue, 25, 8, 0, // Skip to: 475
/* 467 */     MCD::OPC_CheckPredicate, 8, 138, 12, // Skip to: 3681
/* 471 */     MCD::OPC_Decode, 200, 15, 44, // Opcode: SUBQH_R_PH_MMR2
/* 475 */     MCD::OPC_FilterValue, 26, 8, 0, // Skip to: 487
/* 479 */     MCD::OPC_CheckPredicate, 8, 126, 12, // Skip to: 3681
/* 483 */     MCD::OPC_Decode, 202, 15, 41, // Opcode: SUBQH_R_W_MMR2
/* 487 */     MCD::OPC_FilterValue, 27, 8, 0, // Skip to: 499
/* 491 */     MCD::OPC_CheckPredicate, 7, 114, 12, // Skip to: 3681
/* 495 */     MCD::OPC_Decode, 241, 15, 44, // Opcode: SUBU_S_QB_MM
/* 499 */     MCD::OPC_FilterValue, 28, 8, 0, // Skip to: 511
/* 503 */     MCD::OPC_CheckPredicate, 8, 102, 12, // Skip to: 3681
/* 507 */     MCD::OPC_Decode, 239, 15, 44, // Opcode: SUBU_S_PH_MMR2
/* 511 */     MCD::OPC_FilterValue, 29, 8, 0, // Skip to: 523
/* 515 */     MCD::OPC_CheckPredicate, 8, 90, 12, // Skip to: 3681
/* 519 */     MCD::OPC_Decode, 232, 15, 44, // Opcode: SUBUH_R_QB_MMR2
/* 523 */     MCD::OPC_FilterValue, 31, 82, 12, // Skip to: 3681
/* 527 */     MCD::OPC_CheckPredicate, 8, 78, 12, // Skip to: 3681
/* 531 */     MCD::OPC_Decode, 232, 12, 46, // Opcode: PRECR_SRA_R_PH_W_MMR2
/* 535 */     MCD::OPC_FilterValue, 14, 27, 0, // Skip to: 566
/* 539 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 542 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 554
/* 546 */     MCD::OPC_CheckPredicate, 7, 59, 12, // Skip to: 3681
/* 550 */     MCD::OPC_Decode, 172, 14, 45, // Opcode: SHLLV_PH_MM
/* 554 */     MCD::OPC_FilterValue, 16, 51, 12, // Skip to: 3681
/* 558 */     MCD::OPC_CheckPredicate, 7, 47, 12, // Skip to: 3681
/* 562 */     MCD::OPC_Decode, 176, 14, 45, // Opcode: SHLLV_S_PH_MM
/* 566 */     MCD::OPC_FilterValue, 16, 180, 0, // Skip to: 750
/* 570 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 573 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 585
/* 577 */     MCD::OPC_CheckPredicate, 5, 28, 12, // Skip to: 3681
/* 581 */     MCD::OPC_Decode, 235, 14, 47, // Opcode: SLLV_MM
/* 585 */     MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 597
/* 589 */     MCD::OPC_CheckPredicate, 5, 16, 12, // Skip to: 3681
/* 593 */     MCD::OPC_Decode, 179, 15, 47, // Opcode: SRLV_MM
/* 597 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 609
/* 601 */     MCD::OPC_CheckPredicate, 5, 4, 12, // Skip to: 3681
/* 605 */     MCD::OPC_Decode, 157, 15, 47, // Opcode: SRAV_MM
/* 609 */     MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 621
/* 613 */     MCD::OPC_CheckPredicate, 5, 248, 11, // Skip to: 3681
/* 617 */     MCD::OPC_Decode, 195, 13, 47, // Opcode: ROTRV_MM
/* 621 */     MCD::OPC_FilterValue, 4, 7, 0, // Skip to: 632
/* 625 */     MCD::OPC_CheckPredicate, 5, 236, 11, // Skip to: 3681
/* 629 */     MCD::OPC_Decode, 97, 41, // Opcode: ADD_MM
/* 632 */     MCD::OPC_FilterValue, 5, 7, 0, // Skip to: 643
/* 636 */     MCD::OPC_CheckPredicate, 5, 225, 11, // Skip to: 3681
/* 640 */     MCD::OPC_Decode, 104, 41, // Opcode: ADDu_MM
/* 643 */     MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 655
/* 647 */     MCD::OPC_CheckPredicate, 5, 214, 11, // Skip to: 3681
/* 651 */     MCD::OPC_Decode, 250, 15, 41, // Opcode: SUB_MM
/* 655 */     MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 667
/* 659 */     MCD::OPC_CheckPredicate, 5, 202, 11, // Skip to: 3681
/* 663 */     MCD::OPC_Decode, 253, 15, 41, // Opcode: SUBu_MM
/* 667 */     MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 679
/* 671 */     MCD::OPC_CheckPredicate, 5, 190, 11, // Skip to: 3681
/* 675 */     MCD::OPC_Decode, 242, 11, 41, // Opcode: MUL_MM
/* 679 */     MCD::OPC_FilterValue, 9, 7, 0, // Skip to: 690
/* 683 */     MCD::OPC_CheckPredicate, 5, 178, 11, // Skip to: 3681
/* 687 */     MCD::OPC_Decode, 119, 41, // Opcode: AND_MM
/* 690 */     MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 702
/* 694 */     MCD::OPC_CheckPredicate, 5, 167, 11, // Skip to: 3681
/* 698 */     MCD::OPC_Decode, 170, 12, 41, // Opcode: OR_MM
/* 702 */     MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 714
/* 706 */     MCD::OPC_CheckPredicate, 5, 155, 11, // Skip to: 3681
/* 710 */     MCD::OPC_Decode, 154, 12, 41, // Opcode: NOR_MM
/* 714 */     MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 726
/* 718 */     MCD::OPC_CheckPredicate, 5, 143, 11, // Skip to: 3681
/* 722 */     MCD::OPC_Decode, 162, 17, 41, // Opcode: XOR_MM
/* 726 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 738
/* 730 */     MCD::OPC_CheckPredicate, 5, 131, 11, // Skip to: 3681
/* 734 */     MCD::OPC_Decode, 244, 14, 41, // Opcode: SLT_MM
/* 738 */     MCD::OPC_FilterValue, 14, 123, 11, // Skip to: 3681
/* 742 */     MCD::OPC_CheckPredicate, 5, 119, 11, // Skip to: 3681
/* 746 */     MCD::OPC_Decode, 253, 14, 41, // Opcode: SLTu_MM
/* 750 */     MCD::OPC_FilterValue, 21, 147, 0, // Skip to: 901
/* 754 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 757 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 769
/* 761 */     MCD::OPC_CheckPredicate, 7, 100, 11, // Skip to: 3681
/* 765 */     MCD::OPC_Decode, 213, 11, 44, // Opcode: MULEU_S_PH_QBL_MM
/* 769 */     MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 781
/* 773 */     MCD::OPC_CheckPredicate, 7, 88, 11, // Skip to: 3681
/* 777 */     MCD::OPC_Decode, 215, 11, 44, // Opcode: MULEU_S_PH_QBR_MM
/* 781 */     MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 793
/* 785 */     MCD::OPC_CheckPredicate, 7, 76, 11, // Skip to: 3681
/* 789 */     MCD::OPC_Decode, 217, 11, 44, // Opcode: MULQ_RS_PH_MM
/* 793 */     MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 805
/* 797 */     MCD::OPC_CheckPredicate, 8, 64, 11, // Skip to: 3681
/* 801 */     MCD::OPC_Decode, 221, 11, 44, // Opcode: MULQ_S_PH_MMR2
/* 805 */     MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 817
/* 809 */     MCD::OPC_CheckPredicate, 8, 52, 11, // Skip to: 3681
/* 813 */     MCD::OPC_Decode, 219, 11, 41, // Opcode: MULQ_RS_W_MMR2
/* 817 */     MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 829
/* 821 */     MCD::OPC_CheckPredicate, 8, 40, 11, // Skip to: 3681
/* 825 */     MCD::OPC_Decode, 223, 11, 41, // Opcode: MULQ_S_W_MMR2
/* 829 */     MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 841
/* 833 */     MCD::OPC_CheckPredicate, 8, 28, 11, // Skip to: 3681
/* 837 */     MCD::OPC_Decode, 242, 12, 48, // Opcode: PREPEND_MMR2
/* 841 */     MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 853
/* 845 */     MCD::OPC_CheckPredicate, 7, 16, 11, // Skip to: 3681
/* 849 */     MCD::OPC_Decode, 196, 14, 47, // Opcode: SHRAV_R_W_MM
/* 853 */     MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 865
/* 857 */     MCD::OPC_CheckPredicate, 8, 4, 11, // Skip to: 3681
/* 861 */     MCD::OPC_Decode, 208, 14, 45, // Opcode: SHRLV_PH_MMR2
/* 865 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 877
/* 869 */     MCD::OPC_CheckPredicate, 7, 248, 10, // Skip to: 3681
/* 873 */     MCD::OPC_Decode, 210, 14, 45, // Opcode: SHRLV_QB_MM
/* 877 */     MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 889
/* 881 */     MCD::OPC_CheckPredicate, 7, 236, 10, // Skip to: 3681
/* 885 */     MCD::OPC_Decode, 174, 14, 45, // Opcode: SHLLV_QB_MM
/* 889 */     MCD::OPC_FilterValue, 15, 228, 10, // Skip to: 3681
/* 893 */     MCD::OPC_CheckPredicate, 7, 224, 10, // Skip to: 3681
/* 897 */     MCD::OPC_Decode, 178, 14, 47, // Opcode: SHLLV_S_W_MM
/* 901 */     MCD::OPC_FilterValue, 24, 39, 0, // Skip to: 944
/* 905 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 908 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 920
/* 912 */     MCD::OPC_CheckPredicate, 5, 205, 10, // Skip to: 3681
/* 916 */     MCD::OPC_Decode, 130, 11, 49, // Opcode: MOVN_I_MM
/* 920 */     MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 932
/* 924 */     MCD::OPC_CheckPredicate, 5, 193, 10, // Skip to: 3681
/* 928 */     MCD::OPC_Decode, 150, 11, 49, // Opcode: MOVZ_I_MM
/* 932 */     MCD::OPC_FilterValue, 4, 185, 10, // Skip to: 3681
/* 936 */     MCD::OPC_CheckPredicate, 5, 181, 10, // Skip to: 3681
/* 940 */     MCD::OPC_Decode, 219, 9, 50, // Opcode: LWXS_MM
/* 944 */     MCD::OPC_FilterValue, 37, 63, 0, // Skip to: 1011
/* 948 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 951 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 963
/* 955 */     MCD::OPC_CheckPredicate, 7, 162, 10, // Skip to: 3681
/* 959 */     MCD::OPC_Decode, 209, 11, 51, // Opcode: MULEQ_S_W_PHL_MM
/* 963 */     MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 975
/* 967 */     MCD::OPC_CheckPredicate, 7, 150, 10, // Skip to: 3681
/* 971 */     MCD::OPC_Decode, 211, 11, 51, // Opcode: MULEQ_S_W_PHR_MM
/* 975 */     MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 987
/* 979 */     MCD::OPC_CheckPredicate, 7, 138, 10, // Skip to: 3681
/* 983 */     MCD::OPC_Decode, 150, 9, 50, // Opcode: LHX_MM
/* 987 */     MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 999
/* 991 */     MCD::OPC_CheckPredicate, 7, 126, 10, // Skip to: 3681
/* 995 */     MCD::OPC_Decode, 220, 9, 50, // Opcode: LWX_MM
/* 999 */     MCD::OPC_FilterValue, 8, 118, 10, // Skip to: 3681
/* 1003 */    MCD::OPC_CheckPredicate, 7, 114, 10, // Skip to: 3681
/* 1007 */    MCD::OPC_Decode, 240, 8, 50, // Opcode: LBUX_MM
/* 1011 */    MCD::OPC_FilterValue, 44, 8, 0, // Skip to: 1023
/* 1015 */    MCD::OPC_CheckPredicate, 5, 102, 10, // Skip to: 3681
/* 1019 */    MCD::OPC_Decode, 211, 6, 52, // Opcode: EXT_MM
/* 1023 */    MCD::OPC_FilterValue, 45, 87, 0, // Skip to: 1114
/* 1027 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1030 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1042
/* 1034 */    MCD::OPC_CheckPredicate, 8, 83, 10, // Skip to: 3681
/* 1038 */    MCD::OPC_Decode, 245, 11, 44, // Opcode: MUL_PH_MMR2
/* 1042 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1054
/* 1046 */    MCD::OPC_CheckPredicate, 8, 71, 10, // Skip to: 3681
/* 1050 */    MCD::OPC_Decode, 228, 12, 44, // Opcode: PRECR_QB_PH_MMR2
/* 1054 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1066
/* 1058 */    MCD::OPC_CheckPredicate, 7, 59, 10, // Skip to: 3681
/* 1062 */    MCD::OPC_Decode, 224, 12, 44, // Opcode: PRECRQ_QB_PH_MM
/* 1066 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 1078
/* 1070 */    MCD::OPC_CheckPredicate, 7, 47, 10, // Skip to: 3681
/* 1074 */    MCD::OPC_Decode, 222, 12, 53, // Opcode: PRECRQ_PH_W_MM
/* 1078 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 1090
/* 1082 */    MCD::OPC_CheckPredicate, 7, 35, 10, // Skip to: 3681
/* 1086 */    MCD::OPC_Decode, 226, 12, 53, // Opcode: PRECRQ_RS_PH_W_MM
/* 1090 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 1102
/* 1094 */    MCD::OPC_CheckPredicate, 7, 23, 10, // Skip to: 3681
/* 1098 */    MCD::OPC_Decode, 220, 12, 44, // Opcode: PRECRQU_S_QB_PH_MM
/* 1102 */    MCD::OPC_FilterValue, 16, 15, 10, // Skip to: 3681
/* 1106 */    MCD::OPC_CheckPredicate, 8, 11, 10, // Skip to: 3681
/* 1110 */    MCD::OPC_Decode, 250, 11, 44, // Opcode: MUL_S_PH_MMR2
/* 1114 */    MCD::OPC_FilterValue, 53, 94, 0, // Skip to: 1212
/* 1118 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1121 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 1133
/* 1125 */    MCD::OPC_CheckPredicate, 7, 248, 9, // Skip to: 3681
/* 1129 */    MCD::OPC_Decode, 206, 14, 40, // Opcode: SHRA_R_W_MM
/* 1133 */    MCD::OPC_FilterValue, 12, 14, 0, // Skip to: 1151
/* 1137 */    MCD::OPC_CheckPredicate, 7, 236, 9, // Skip to: 3681
/* 1141 */    MCD::OPC_CheckField, 11, 1, 0, 230, 9, // Skip to: 3681
/* 1147 */    MCD::OPC_Decode, 198, 14, 54, // Opcode: SHRA_PH_MM
/* 1151 */    MCD::OPC_FilterValue, 14, 27, 0, // Skip to: 1182
/* 1155 */    MCD::OPC_ExtractField, 11, 1,  // Inst{11} ...
/* 1158 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1170
/* 1162 */    MCD::OPC_CheckPredicate, 7, 211, 9, // Skip to: 3681
/* 1166 */    MCD::OPC_Decode, 180, 14, 54, // Opcode: SHLL_PH_MM
/* 1170 */    MCD::OPC_FilterValue, 1, 203, 9, // Skip to: 3681
/* 1174 */    MCD::OPC_CheckPredicate, 7, 199, 9, // Skip to: 3681
/* 1178 */    MCD::OPC_Decode, 184, 14, 54, // Opcode: SHLL_S_PH_MM
/* 1182 */    MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 1194
/* 1186 */    MCD::OPC_CheckPredicate, 7, 187, 9, // Skip to: 3681
/* 1190 */    MCD::OPC_Decode, 186, 14, 40, // Opcode: SHLL_S_W_MM
/* 1194 */    MCD::OPC_FilterValue, 28, 179, 9, // Skip to: 3681
/* 1198 */    MCD::OPC_CheckPredicate, 7, 175, 9, // Skip to: 3681
/* 1202 */    MCD::OPC_CheckField, 11, 1, 0, 169, 9, // Skip to: 3681
/* 1208 */    MCD::OPC_Decode, 202, 14, 54, // Opcode: SHRA_R_PH_MM
/* 1212 */    MCD::OPC_FilterValue, 60, 12, 6, // Skip to: 2764
/* 1216 */    MCD::OPC_ExtractField, 6, 6,  // Inst{11-6} ...
/* 1219 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1231
/* 1223 */    MCD::OPC_CheckPredicate, 5, 150, 9, // Skip to: 3681
/* 1227 */    MCD::OPC_Decode, 220, 16, 55, // Opcode: TEQ_MM
/* 1231 */    MCD::OPC_FilterValue, 1, 75, 0, // Skip to: 1310
/* 1235 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 1238 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 1256
/* 1242 */    MCD::OPC_CheckPredicate, 7, 131, 9, // Skip to: 3681
/* 1246 */    MCD::OPC_CheckField, 21, 5, 0, 125, 9, // Skip to: 3681
/* 1252 */    MCD::OPC_Decode, 186, 10, 56, // Opcode: MFHI_DSP_MM
/* 1256 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 1274
/* 1260 */    MCD::OPC_CheckPredicate, 7, 113, 9, // Skip to: 3681
/* 1264 */    MCD::OPC_CheckField, 21, 5, 0, 107, 9, // Skip to: 3681
/* 1270 */    MCD::OPC_Decode, 192, 10, 56, // Opcode: MFLO_DSP_MM
/* 1274 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 1292
/* 1278 */    MCD::OPC_CheckPredicate, 7, 95, 9, // Skip to: 3681
/* 1282 */    MCD::OPC_CheckField, 21, 5, 0, 89, 9, // Skip to: 3681
/* 1288 */    MCD::OPC_Decode, 188, 11, 57, // Opcode: MTHI_DSP_MM
/* 1292 */    MCD::OPC_FilterValue, 3, 81, 9, // Skip to: 3681
/* 1296 */    MCD::OPC_CheckPredicate, 7, 77, 9, // Skip to: 3681
/* 1300 */    MCD::OPC_CheckField, 21, 5, 0, 71, 9, // Skip to: 3681
/* 1306 */    MCD::OPC_Decode, 195, 11, 58, // Opcode: MTLO_DSP_MM
/* 1310 */    MCD::OPC_FilterValue, 2, 51, 0, // Skip to: 1365
/* 1314 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 1317 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1329
/* 1321 */    MCD::OPC_CheckPredicate, 8, 52, 9, // Skip to: 3681
/* 1325 */    MCD::OPC_Decode, 249, 5, 59, // Opcode: DPA_W_PH_MMR2
/* 1329 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1341
/* 1333 */    MCD::OPC_CheckPredicate, 8, 40, 9, // Skip to: 3681
/* 1337 */    MCD::OPC_Decode, 247, 5, 59, // Opcode: DPAX_W_PH_MMR2
/* 1341 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1353
/* 1345 */    MCD::OPC_CheckPredicate, 7, 28, 9, // Skip to: 3681
/* 1349 */    MCD::OPC_Decode, 243, 5, 59, // Opcode: DPAU_H_QBL_MM
/* 1353 */    MCD::OPC_FilterValue, 3, 20, 9, // Skip to: 3681
/* 1357 */    MCD::OPC_CheckPredicate, 7, 16, 9, // Skip to: 3681
/* 1361 */    MCD::OPC_Decode, 245, 5, 59, // Opcode: DPAU_H_QBR_MM
/* 1365 */    MCD::OPC_FilterValue, 4, 132, 0, // Skip to: 1501
/* 1369 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 1372 */    MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 1383
/* 1376 */    MCD::OPC_CheckPredicate, 8, 253, 8, // Skip to: 3681
/* 1380 */    MCD::OPC_Decode, 26, 60, // Opcode: ABSQ_S_QB_MMR2
/* 1383 */    MCD::OPC_FilterValue, 1, 7, 0, // Skip to: 1394
/* 1387 */    MCD::OPC_CheckPredicate, 7, 242, 8, // Skip to: 3681
/* 1391 */    MCD::OPC_Decode, 24, 60, // Opcode: ABSQ_S_PH_MM
/* 1394 */    MCD::OPC_FilterValue, 2, 7, 0, // Skip to: 1405
/* 1398 */    MCD::OPC_CheckPredicate, 7, 231, 8, // Skip to: 3681
/* 1402 */    MCD::OPC_Decode, 28, 61, // Opcode: ABSQ_S_W_MM
/* 1405 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 1417
/* 1409 */    MCD::OPC_CheckPredicate, 7, 220, 8, // Skip to: 3681
/* 1413 */    MCD::OPC_Decode, 191, 8, 62, // Opcode: INSV_MM
/* 1417 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 1429
/* 1421 */    MCD::OPC_CheckPredicate, 7, 208, 8, // Skip to: 3681
/* 1425 */    MCD::OPC_Decode, 208, 12, 63, // Opcode: PRECEQ_W_PHL_MM
/* 1429 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 1441
/* 1433 */    MCD::OPC_CheckPredicate, 7, 196, 8, // Skip to: 3681
/* 1437 */    MCD::OPC_Decode, 210, 12, 63, // Opcode: PRECEQ_W_PHR_MM
/* 1441 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 1453
/* 1445 */    MCD::OPC_CheckPredicate, 7, 184, 8, // Skip to: 3681
/* 1449 */    MCD::OPC_Decode, 202, 12, 60, // Opcode: PRECEQU_PH_QBL_MM
/* 1453 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 1465
/* 1457 */    MCD::OPC_CheckPredicate, 7, 172, 8, // Skip to: 3681
/* 1461 */    MCD::OPC_Decode, 206, 12, 60, // Opcode: PRECEQU_PH_QBR_MM
/* 1465 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 1477
/* 1469 */    MCD::OPC_CheckPredicate, 7, 160, 8, // Skip to: 3681
/* 1473 */    MCD::OPC_Decode, 214, 12, 60, // Opcode: PRECEU_PH_QBL_MM
/* 1477 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 1489
/* 1481 */    MCD::OPC_CheckPredicate, 7, 148, 8, // Skip to: 3681
/* 1485 */    MCD::OPC_Decode, 218, 12, 60, // Opcode: PRECEU_PH_QBR_MM
/* 1489 */    MCD::OPC_FilterValue, 15, 140, 8, // Skip to: 3681
/* 1493 */    MCD::OPC_CheckPredicate, 7, 136, 8, // Skip to: 3681
/* 1497 */    MCD::OPC_Decode, 167, 13, 63, // Opcode: RADDU_W_QB_MM
/* 1501 */    MCD::OPC_FilterValue, 7, 27, 0, // Skip to: 1532
/* 1505 */    MCD::OPC_ExtractField, 12, 1,  // Inst{12} ...
/* 1508 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1520
/* 1512 */    MCD::OPC_CheckPredicate, 8, 117, 8, // Skip to: 3681
/* 1516 */    MCD::OPC_Decode, 200, 14, 64, // Opcode: SHRA_QB_MMR2
/* 1520 */    MCD::OPC_FilterValue, 1, 109, 8, // Skip to: 3681
/* 1524 */    MCD::OPC_CheckPredicate, 8, 105, 8, // Skip to: 3681
/* 1528 */    MCD::OPC_Decode, 204, 14, 64, // Opcode: SHRA_R_QB_MMR2
/* 1532 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 1544
/* 1536 */    MCD::OPC_CheckPredicate, 5, 93, 8, // Skip to: 3681
/* 1540 */    MCD::OPC_Decode, 228, 16, 55, // Opcode: TGE_MM
/* 1544 */    MCD::OPC_FilterValue, 9, 20, 0, // Skip to: 1568
/* 1548 */    MCD::OPC_CheckPredicate, 7, 81, 8, // Skip to: 3681
/* 1552 */    MCD::OPC_CheckField, 21, 5, 0, 75, 8, // Skip to: 3681
/* 1558 */    MCD::OPC_CheckField, 12, 2, 0, 69, 8, // Skip to: 3681
/* 1564 */    MCD::OPC_Decode, 191, 11, 65, // Opcode: MTHLIP_MM
/* 1568 */    MCD::OPC_FilterValue, 10, 51, 0, // Skip to: 1623
/* 1572 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 1575 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1587
/* 1579 */    MCD::OPC_CheckPredicate, 7, 50, 8, // Skip to: 3681
/* 1583 */    MCD::OPC_Decode, 241, 5, 59, // Opcode: DPAQ_S_W_PH_MM
/* 1587 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1599
/* 1591 */    MCD::OPC_CheckPredicate, 7, 38, 8, // Skip to: 3681
/* 1595 */    MCD::OPC_Decode, 239, 5, 59, // Opcode: DPAQ_SA_L_W_MM
/* 1599 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1611
/* 1603 */    MCD::OPC_CheckPredicate, 8, 26, 8, // Skip to: 3681
/* 1607 */    MCD::OPC_Decode, 237, 5, 59, // Opcode: DPAQX_S_W_PH_MMR2
/* 1611 */    MCD::OPC_FilterValue, 3, 18, 8, // Skip to: 3681
/* 1615 */    MCD::OPC_CheckPredicate, 8, 14, 8, // Skip to: 3681
/* 1619 */    MCD::OPC_Decode, 235, 5, 59, // Opcode: DPAQX_SA_W_PH_MMR2
/* 1623 */    MCD::OPC_FilterValue, 12, 75, 0, // Skip to: 1702
/* 1627 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 1630 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1642
/* 1634 */    MCD::OPC_CheckPredicate, 7, 251, 7, // Skip to: 3681
/* 1638 */    MCD::OPC_Decode, 178, 13, 66, // Opcode: REPLV_PH_MM
/* 1642 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1654
/* 1646 */    MCD::OPC_CheckPredicate, 7, 239, 7, // Skip to: 3681
/* 1650 */    MCD::OPC_Decode, 180, 13, 66, // Opcode: REPLV_QB_MM
/* 1654 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 1666
/* 1658 */    MCD::OPC_CheckPredicate, 7, 227, 7, // Skip to: 3681
/* 1662 */    MCD::OPC_Decode, 201, 12, 60, // Opcode: PRECEQU_PH_QBLA_MM
/* 1666 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 1678
/* 1670 */    MCD::OPC_CheckPredicate, 7, 215, 7, // Skip to: 3681
/* 1674 */    MCD::OPC_Decode, 205, 12, 60, // Opcode: PRECEQU_PH_QBRA_MM
/* 1678 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 1690
/* 1682 */    MCD::OPC_CheckPredicate, 7, 203, 7, // Skip to: 3681
/* 1686 */    MCD::OPC_Decode, 213, 12, 60, // Opcode: PRECEU_PH_QBLA_MM
/* 1690 */    MCD::OPC_FilterValue, 13, 195, 7, // Skip to: 3681
/* 1694 */    MCD::OPC_CheckPredicate, 7, 191, 7, // Skip to: 3681
/* 1698 */    MCD::OPC_Decode, 217, 12, 60, // Opcode: PRECEU_PH_QBRA_MM
/* 1702 */    MCD::OPC_FilterValue, 13, 123, 0, // Skip to: 1829
/* 1706 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 1709 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 1727
/* 1713 */    MCD::OPC_CheckPredicate, 5, 172, 7, // Skip to: 3681
/* 1717 */    MCD::OPC_CheckField, 16, 10, 0, 166, 7, // Skip to: 3681
/* 1723 */    MCD::OPC_Decode, 232, 16, 0, // Opcode: TLBP_MM
/* 1727 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 1745
/* 1731 */    MCD::OPC_CheckPredicate, 5, 154, 7, // Skip to: 3681
/* 1735 */    MCD::OPC_CheckField, 16, 10, 0, 148, 7, // Skip to: 3681
/* 1741 */    MCD::OPC_Decode, 234, 16, 0, // Opcode: TLBR_MM
/* 1745 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 1763
/* 1749 */    MCD::OPC_CheckPredicate, 5, 136, 7, // Skip to: 3681
/* 1753 */    MCD::OPC_CheckField, 16, 10, 0, 130, 7, // Skip to: 3681
/* 1759 */    MCD::OPC_Decode, 236, 16, 0, // Opcode: TLBWI_MM
/* 1763 */    MCD::OPC_FilterValue, 3, 14, 0, // Skip to: 1781
/* 1767 */    MCD::OPC_CheckPredicate, 5, 118, 7, // Skip to: 3681
/* 1771 */    MCD::OPC_CheckField, 16, 10, 0, 112, 7, // Skip to: 3681
/* 1777 */    MCD::OPC_Decode, 238, 16, 0, // Opcode: TLBWR_MM
/* 1781 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 1793
/* 1785 */    MCD::OPC_CheckPredicate, 5, 100, 7, // Skip to: 3681
/* 1789 */    MCD::OPC_Decode, 149, 17, 67, // Opcode: WAIT_MM
/* 1793 */    MCD::OPC_FilterValue, 14, 14, 0, // Skip to: 1811
/* 1797 */    MCD::OPC_CheckPredicate, 5, 88, 7, // Skip to: 3681
/* 1801 */    MCD::OPC_CheckField, 16, 10, 0, 82, 7, // Skip to: 3681
/* 1807 */    MCD::OPC_Decode, 177, 5, 0, // Opcode: DERET_MM
/* 1811 */    MCD::OPC_FilterValue, 15, 74, 7, // Skip to: 3681
/* 1815 */    MCD::OPC_CheckPredicate, 5, 70, 7, // Skip to: 3681
/* 1819 */    MCD::OPC_CheckField, 16, 10, 0, 64, 7, // Skip to: 3681
/* 1825 */    MCD::OPC_Decode, 181, 6, 0, // Opcode: ERET_MM
/* 1829 */    MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 1841
/* 1833 */    MCD::OPC_CheckPredicate, 8, 52, 7, // Skip to: 3681
/* 1837 */    MCD::OPC_Decode, 212, 14, 54, // Opcode: SHRL_PH_MMR2
/* 1841 */    MCD::OPC_FilterValue, 16, 8, 0, // Skip to: 1853
/* 1845 */    MCD::OPC_CheckPredicate, 5, 40, 7, // Skip to: 3681
/* 1849 */    MCD::OPC_Decode, 227, 16, 55, // Opcode: TGEU_MM
/* 1853 */    MCD::OPC_FilterValue, 18, 51, 0, // Skip to: 1908
/* 1857 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 1860 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1872
/* 1864 */    MCD::OPC_CheckPredicate, 8, 21, 7, // Skip to: 3681
/* 1868 */    MCD::OPC_Decode, 144, 6, 59, // Opcode: DPS_W_PH_MMR2
/* 1872 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1884
/* 1876 */    MCD::OPC_CheckPredicate, 8, 9, 7, // Skip to: 3681
/* 1880 */    MCD::OPC_Decode, 142, 6, 59, // Opcode: DPSX_W_PH_MMR2
/* 1884 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1896
/* 1888 */    MCD::OPC_CheckPredicate, 7, 253, 6, // Skip to: 3681
/* 1892 */    MCD::OPC_Decode, 138, 6, 59, // Opcode: DPSU_H_QBL_MM
/* 1896 */    MCD::OPC_FilterValue, 3, 245, 6, // Skip to: 3681
/* 1900 */    MCD::OPC_CheckPredicate, 7, 241, 6, // Skip to: 3681
/* 1904 */    MCD::OPC_Decode, 140, 6, 59, // Opcode: DPSU_H_QBR_MM
/* 1908 */    MCD::OPC_FilterValue, 23, 14, 0, // Skip to: 1926
/* 1912 */    MCD::OPC_CheckPredicate, 7, 229, 6, // Skip to: 3681
/* 1916 */    MCD::OPC_CheckField, 12, 1, 0, 223, 6, // Skip to: 3681
/* 1922 */    MCD::OPC_Decode, 184, 13, 68, // Opcode: REPL_QB_MM
/* 1926 */    MCD::OPC_FilterValue, 25, 39, 0, // Skip to: 1969
/* 1930 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 1933 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1945
/* 1937 */    MCD::OPC_CheckPredicate, 7, 204, 6, // Skip to: 3681
/* 1941 */    MCD::OPC_Decode, 169, 13, 69, // Opcode: RDDSP_MM
/* 1945 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1957
/* 1949 */    MCD::OPC_CheckPredicate, 7, 192, 6, // Skip to: 3681
/* 1953 */    MCD::OPC_Decode, 192, 6, 70, // Opcode: EXTP_MM
/* 1957 */    MCD::OPC_FilterValue, 3, 184, 6, // Skip to: 3681
/* 1961 */    MCD::OPC_CheckPredicate, 7, 180, 6, // Skip to: 3681
/* 1965 */    MCD::OPC_Decode, 189, 6, 70, // Opcode: EXTPDP_MM
/* 1969 */    MCD::OPC_FilterValue, 26, 51, 0, // Skip to: 2024
/* 1973 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 1976 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1988
/* 1980 */    MCD::OPC_CheckPredicate, 7, 161, 6, // Skip to: 3681
/* 1984 */    MCD::OPC_Decode, 130, 6, 59, // Opcode: DPSQ_S_W_PH_MM
/* 1988 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2000
/* 1992 */    MCD::OPC_CheckPredicate, 7, 149, 6, // Skip to: 3681
/* 1996 */    MCD::OPC_Decode, 128, 6, 59, // Opcode: DPSQ_SA_L_W_MM
/* 2000 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2012
/* 2004 */    MCD::OPC_CheckPredicate, 8, 137, 6, // Skip to: 3681
/* 2008 */    MCD::OPC_Decode, 254, 5, 59, // Opcode: DPSQX_S_W_PH_MMR2
/* 2012 */    MCD::OPC_FilterValue, 3, 129, 6, // Skip to: 3681
/* 2016 */    MCD::OPC_CheckPredicate, 8, 125, 6, // Skip to: 3681
/* 2020 */    MCD::OPC_Decode, 252, 5, 59, // Opcode: DPSQX_SA_W_PH_MMR2
/* 2024 */    MCD::OPC_FilterValue, 29, 39, 0, // Skip to: 2067
/* 2028 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2031 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 2049
/* 2035 */    MCD::OPC_CheckPredicate, 5, 106, 6, // Skip to: 3681
/* 2039 */    MCD::OPC_CheckField, 21, 5, 0, 100, 6, // Skip to: 3681
/* 2045 */    MCD::OPC_Decode, 200, 5, 71, // Opcode: DI_MM
/* 2049 */    MCD::OPC_FilterValue, 5, 92, 6, // Skip to: 3681
/* 2053 */    MCD::OPC_CheckPredicate, 5, 88, 6, // Skip to: 3681
/* 2057 */    MCD::OPC_CheckField, 21, 5, 0, 82, 6, // Skip to: 3681
/* 2063 */    MCD::OPC_Decode, 176, 6, 71, // Opcode: EI_MM
/* 2067 */    MCD::OPC_FilterValue, 32, 8, 0, // Skip to: 2079
/* 2071 */    MCD::OPC_CheckPredicate, 5, 70, 6, // Skip to: 3681
/* 2075 */    MCD::OPC_Decode, 245, 16, 55, // Opcode: TLT_MM
/* 2079 */    MCD::OPC_FilterValue, 33, 27, 0, // Skip to: 2110
/* 2083 */    MCD::OPC_ExtractField, 12, 1,  // Inst{12} ...
/* 2086 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2098
/* 2090 */    MCD::OPC_CheckPredicate, 7, 51, 6, // Skip to: 3681
/* 2094 */    MCD::OPC_Decode, 182, 14, 64, // Opcode: SHLL_QB_MM
/* 2098 */    MCD::OPC_FilterValue, 1, 43, 6, // Skip to: 3681
/* 2102 */    MCD::OPC_CheckPredicate, 7, 39, 6, // Skip to: 3681
/* 2106 */    MCD::OPC_Decode, 214, 14, 64, // Opcode: SHRL_QB_MM
/* 2110 */    MCD::OPC_FilterValue, 34, 27, 0, // Skip to: 2141
/* 2114 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 2117 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2129
/* 2121 */    MCD::OPC_CheckPredicate, 7, 20, 6, // Skip to: 3681
/* 2125 */    MCD::OPC_Decode, 191, 6, 72, // Opcode: EXTPV_MM
/* 2129 */    MCD::OPC_FilterValue, 3, 12, 6, // Skip to: 3681
/* 2133 */    MCD::OPC_CheckPredicate, 7, 8, 6, // Skip to: 3681
/* 2137 */    MCD::OPC_Decode, 188, 6, 72, // Opcode: EXTPDPV_MM
/* 2141 */    MCD::OPC_FilterValue, 40, 8, 0, // Skip to: 2153
/* 2145 */    MCD::OPC_CheckPredicate, 5, 252, 5, // Skip to: 3681
/* 2149 */    MCD::OPC_Decode, 244, 16, 55, // Opcode: TLTU_MM
/* 2153 */    MCD::OPC_FilterValue, 41, 51, 0, // Skip to: 2208
/* 2157 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 2160 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2172
/* 2164 */    MCD::OPC_CheckPredicate, 7, 233, 5, // Skip to: 3681
/* 2168 */    MCD::OPC_Decode, 146, 10, 59, // Opcode: MAQ_S_W_PHR_MM
/* 2172 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2184
/* 2176 */    MCD::OPC_CheckPredicate, 7, 221, 5, // Skip to: 3681
/* 2180 */    MCD::OPC_Decode, 144, 10, 59, // Opcode: MAQ_S_W_PHL_MM
/* 2184 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2196
/* 2188 */    MCD::OPC_CheckPredicate, 7, 209, 5, // Skip to: 3681
/* 2192 */    MCD::OPC_Decode, 142, 10, 59, // Opcode: MAQ_SA_W_PHR_MM
/* 2196 */    MCD::OPC_FilterValue, 3, 201, 5, // Skip to: 3681
/* 2200 */    MCD::OPC_CheckPredicate, 7, 197, 5, // Skip to: 3681
/* 2204 */    MCD::OPC_Decode, 140, 10, 59, // Opcode: MAQ_SA_W_PHL_MM
/* 2208 */    MCD::OPC_FilterValue, 42, 51, 0, // Skip to: 2263
/* 2212 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 2215 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2227
/* 2219 */    MCD::OPC_CheckPredicate, 7, 178, 5, // Skip to: 3681
/* 2223 */    MCD::OPC_Decode, 133, 10, 59, // Opcode: MADD_DSP_MM
/* 2227 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2239
/* 2231 */    MCD::OPC_CheckPredicate, 7, 166, 5, // Skip to: 3681
/* 2235 */    MCD::OPC_Decode, 251, 9, 59, // Opcode: MADDU_DSP_MM
/* 2239 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2251
/* 2243 */    MCD::OPC_CheckPredicate, 7, 154, 5, // Skip to: 3681
/* 2247 */    MCD::OPC_Decode, 172, 11, 59, // Opcode: MSUB_DSP_MM
/* 2251 */    MCD::OPC_FilterValue, 3, 146, 5, // Skip to: 3681
/* 2255 */    MCD::OPC_CheckPredicate, 7, 142, 5, // Skip to: 3681
/* 2259 */    MCD::OPC_Decode, 162, 11, 59, // Opcode: MSUBU_DSP_MM
/* 2263 */    MCD::OPC_FilterValue, 44, 171, 0, // Skip to: 2438
/* 2267 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2270 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2282
/* 2274 */    MCD::OPC_CheckPredicate, 5, 123, 5, // Skip to: 3681
/* 2278 */    MCD::OPC_Decode, 133, 14, 61, // Opcode: SEB_MM
/* 2282 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 2294
/* 2286 */    MCD::OPC_CheckPredicate, 5, 111, 5, // Skip to: 3681
/* 2290 */    MCD::OPC_Decode, 137, 14, 61, // Opcode: SEH_MM
/* 2294 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2306
/* 2298 */    MCD::OPC_CheckPredicate, 5, 99, 5, // Skip to: 3681
/* 2302 */    MCD::OPC_Decode, 215, 3, 61, // Opcode: CLO_MM
/* 2306 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2318
/* 2310 */    MCD::OPC_CheckPredicate, 5, 87, 5, // Skip to: 3681
/* 2314 */    MCD::OPC_Decode, 235, 3, 61, // Opcode: CLZ_MM
/* 2318 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2330
/* 2322 */    MCD::OPC_CheckPredicate, 9, 75, 5, // Skip to: 3681
/* 2326 */    MCD::OPC_Decode, 172, 13, 73, // Opcode: RDHWR_MM
/* 2330 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 2342
/* 2334 */    MCD::OPC_CheckPredicate, 5, 63, 5, // Skip to: 3681
/* 2338 */    MCD::OPC_Decode, 154, 17, 61, // Opcode: WSBH_MM
/* 2342 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 2354
/* 2346 */    MCD::OPC_CheckPredicate, 5, 51, 5, // Skip to: 3681
/* 2350 */    MCD::OPC_Decode, 233, 11, 74, // Opcode: MULT_MM
/* 2354 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 2366
/* 2358 */    MCD::OPC_CheckPredicate, 5, 39, 5, // Skip to: 3681
/* 2362 */    MCD::OPC_Decode, 235, 11, 74, // Opcode: MULTu_MM
/* 2366 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 2378
/* 2370 */    MCD::OPC_CheckPredicate, 5, 27, 5, // Skip to: 3681
/* 2374 */    MCD::OPC_Decode, 253, 13, 74, // Opcode: SDIV_MM
/* 2378 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 2390
/* 2382 */    MCD::OPC_CheckPredicate, 5, 15, 5, // Skip to: 3681
/* 2386 */    MCD::OPC_Decode, 136, 17, 74, // Opcode: UDIV_MM
/* 2390 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 2402
/* 2394 */    MCD::OPC_CheckPredicate, 5, 3, 5, // Skip to: 3681
/* 2398 */    MCD::OPC_Decode, 134, 10, 74, // Opcode: MADD_MM
/* 2402 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 2414
/* 2406 */    MCD::OPC_CheckPredicate, 5, 247, 4, // Skip to: 3681
/* 2410 */    MCD::OPC_Decode, 252, 9, 74, // Opcode: MADDU_MM
/* 2414 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 2426
/* 2418 */    MCD::OPC_CheckPredicate, 5, 235, 4, // Skip to: 3681
/* 2422 */    MCD::OPC_Decode, 173, 11, 74, // Opcode: MSUB_MM
/* 2426 */    MCD::OPC_FilterValue, 15, 227, 4, // Skip to: 3681
/* 2430 */    MCD::OPC_CheckPredicate, 5, 223, 4, // Skip to: 3681
/* 2434 */    MCD::OPC_Decode, 163, 11, 74, // Opcode: MSUBU_MM
/* 2438 */    MCD::OPC_FilterValue, 45, 45, 0, // Skip to: 2487
/* 2442 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2445 */    MCD::OPC_FilterValue, 6, 14, 0, // Skip to: 2463
/* 2449 */    MCD::OPC_CheckPredicate, 5, 204, 4, // Skip to: 3681
/* 2453 */    MCD::OPC_CheckField, 21, 5, 0, 198, 4, // Skip to: 3681
/* 2459 */    MCD::OPC_Decode, 165, 16, 75, // Opcode: SYNC_MM
/* 2463 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 2475
/* 2467 */    MCD::OPC_CheckPredicate, 5, 186, 4, // Skip to: 3681
/* 2471 */    MCD::OPC_Decode, 168, 16, 67, // Opcode: SYSCALL_MM
/* 2475 */    MCD::OPC_FilterValue, 13, 178, 4, // Skip to: 3681
/* 2479 */    MCD::OPC_CheckPredicate, 5, 174, 4, // Skip to: 3681
/* 2483 */    MCD::OPC_Decode, 243, 13, 67, // Opcode: SDBBP_MM
/* 2487 */    MCD::OPC_FilterValue, 48, 8, 0, // Skip to: 2499
/* 2491 */    MCD::OPC_CheckPredicate, 5, 162, 4, // Skip to: 3681
/* 2495 */    MCD::OPC_Decode, 249, 16, 55, // Opcode: TNE_MM
/* 2499 */    MCD::OPC_FilterValue, 50, 27, 0, // Skip to: 2530
/* 2503 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 2506 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2518
/* 2510 */    MCD::OPC_CheckPredicate, 7, 143, 4, // Skip to: 3681
/* 2514 */    MCD::OPC_Decode, 232, 11, 76, // Opcode: MULT_DSP_MM
/* 2518 */    MCD::OPC_FilterValue, 1, 135, 4, // Skip to: 3681
/* 2522 */    MCD::OPC_CheckPredicate, 7, 131, 4, // Skip to: 3681
/* 2526 */    MCD::OPC_Decode, 230, 11, 76, // Opcode: MULTU_DSP_MM
/* 2530 */    MCD::OPC_FilterValue, 53, 75, 0, // Skip to: 2609
/* 2534 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2537 */    MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 2555
/* 2541 */    MCD::OPC_CheckPredicate, 5, 112, 4, // Skip to: 3681
/* 2545 */    MCD::OPC_CheckField, 21, 5, 0, 106, 4, // Skip to: 3681
/* 2551 */    MCD::OPC_Decode, 187, 10, 71, // Opcode: MFHI_MM
/* 2555 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 2573
/* 2559 */    MCD::OPC_CheckPredicate, 5, 94, 4, // Skip to: 3681
/* 2563 */    MCD::OPC_CheckField, 21, 5, 0, 88, 4, // Skip to: 3681
/* 2569 */    MCD::OPC_Decode, 193, 10, 71, // Opcode: MFLO_MM
/* 2573 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 2591
/* 2577 */    MCD::OPC_CheckPredicate, 5, 76, 4, // Skip to: 3681
/* 2581 */    MCD::OPC_CheckField, 21, 5, 0, 70, 4, // Skip to: 3681
/* 2587 */    MCD::OPC_Decode, 189, 11, 71, // Opcode: MTHI_MM
/* 2591 */    MCD::OPC_FilterValue, 3, 62, 4, // Skip to: 3681
/* 2595 */    MCD::OPC_CheckPredicate, 5, 58, 4, // Skip to: 3681
/* 2599 */    MCD::OPC_CheckField, 21, 5, 0, 52, 4, // Skip to: 3681
/* 2605 */    MCD::OPC_Decode, 196, 11, 71, // Opcode: MTLO_MM
/* 2609 */    MCD::OPC_FilterValue, 57, 51, 0, // Skip to: 2664
/* 2613 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 2616 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2628
/* 2620 */    MCD::OPC_CheckPredicate, 7, 33, 4, // Skip to: 3681
/* 2624 */    MCD::OPC_Decode, 208, 6, 70, // Opcode: EXTR_W_MM
/* 2628 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2640
/* 2632 */    MCD::OPC_CheckPredicate, 7, 21, 4, // Skip to: 3681
/* 2636 */    MCD::OPC_Decode, 204, 6, 70, // Opcode: EXTR_R_W_MM
/* 2640 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2652
/* 2644 */    MCD::OPC_CheckPredicate, 7, 9, 4, // Skip to: 3681
/* 2648 */    MCD::OPC_Decode, 202, 6, 70, // Opcode: EXTR_RS_W_MM
/* 2652 */    MCD::OPC_FilterValue, 3, 1, 4, // Skip to: 3681
/* 2656 */    MCD::OPC_CheckPredicate, 7, 253, 3, // Skip to: 3681
/* 2660 */    MCD::OPC_Decode, 206, 6, 70, // Opcode: EXTR_S_H_MM
/* 2664 */    MCD::OPC_FilterValue, 58, 51, 0, // Skip to: 2719
/* 2668 */    MCD::OPC_ExtractField, 12, 2,  // Inst{13-12} ...
/* 2671 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2683
/* 2675 */    MCD::OPC_CheckPredicate, 7, 234, 3, // Skip to: 3681
/* 2679 */    MCD::OPC_Decode, 200, 6, 72, // Opcode: EXTRV_W_MM
/* 2683 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2695
/* 2687 */    MCD::OPC_CheckPredicate, 7, 222, 3, // Skip to: 3681
/* 2691 */    MCD::OPC_Decode, 196, 6, 72, // Opcode: EXTRV_R_W_MM
/* 2695 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2707
/* 2699 */    MCD::OPC_CheckPredicate, 7, 210, 3, // Skip to: 3681
/* 2703 */    MCD::OPC_Decode, 194, 6, 72, // Opcode: EXTRV_RS_W_MM
/* 2707 */    MCD::OPC_FilterValue, 3, 202, 3, // Skip to: 3681
/* 2711 */    MCD::OPC_CheckPredicate, 7, 198, 3, // Skip to: 3681
/* 2715 */    MCD::OPC_Decode, 198, 6, 72, // Opcode: EXTRV_S_H_MM
/* 2719 */    MCD::OPC_FilterValue, 60, 190, 3, // Skip to: 3681
/* 2723 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2726 */    MCD::OPC_FilterValue, 0, 22, 0, // Skip to: 2752
/* 2730 */    MCD::OPC_CheckPredicate, 5, 10, 0, // Skip to: 2744
/* 2734 */    MCD::OPC_CheckField, 21, 5, 0, 4, 0, // Skip to: 2744
/* 2740 */    MCD::OPC_Decode, 222, 8, 71, // Opcode: JR_MM
/* 2744 */    MCD::OPC_CheckPredicate, 5, 165, 3, // Skip to: 3681
/* 2748 */    MCD::OPC_Decode, 204, 8, 61, // Opcode: JALR_MM
/* 2752 */    MCD::OPC_FilterValue, 4, 157, 3, // Skip to: 3681
/* 2756 */    MCD::OPC_CheckPredicate, 5, 153, 3, // Skip to: 3681
/* 2760 */    MCD::OPC_Decode, 202, 8, 61, // Opcode: JALRS_MM
/* 2764 */    MCD::OPC_FilterValue, 61, 145, 3, // Skip to: 3681
/* 2768 */    MCD::OPC_CheckPredicate, 7, 141, 3, // Skip to: 3681
/* 2772 */    MCD::OPC_CheckField, 6, 5, 0, 135, 3, // Skip to: 3681
/* 2778 */    MCD::OPC_Decode, 182, 13, 77, // Opcode: REPL_PH_MM
/* 2782 */    MCD::OPC_FilterValue, 4, 7, 0, // Skip to: 2793
/* 2786 */    MCD::OPC_CheckPredicate, 5, 123, 3, // Skip to: 3681
/* 2790 */    MCD::OPC_Decode, 100, 78, // Opcode: ADDi_MM
/* 2793 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2805
/* 2797 */    MCD::OPC_CheckPredicate, 5, 112, 3, // Skip to: 3681
/* 2801 */    MCD::OPC_Decode, 248, 8, 79, // Opcode: LBu_MM
/* 2805 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2817
/* 2809 */    MCD::OPC_CheckPredicate, 5, 100, 3, // Skip to: 3681
/* 2813 */    MCD::OPC_Decode, 229, 13, 79, // Opcode: SB_MM
/* 2817 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 2829
/* 2821 */    MCD::OPC_CheckPredicate, 5, 88, 3, // Skip to: 3681
/* 2825 */    MCD::OPC_Decode, 242, 8, 79, // Opcode: LB_MM
/* 2829 */    MCD::OPC_FilterValue, 8, 63, 0, // Skip to: 2896
/* 2833 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2836 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2848
/* 2840 */    MCD::OPC_CheckPredicate, 5, 69, 3, // Skip to: 3681
/* 2844 */    MCD::OPC_Decode, 207, 9, 80, // Opcode: LWP_MM
/* 2848 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2860
/* 2852 */    MCD::OPC_CheckPredicate, 5, 57, 3, // Skip to: 3681
/* 2856 */    MCD::OPC_Decode, 203, 9, 80, // Opcode: LWM32_MM
/* 2860 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2872
/* 2864 */    MCD::OPC_CheckPredicate, 5, 45, 3, // Skip to: 3681
/* 2868 */    MCD::OPC_Decode, 167, 3, 81, // Opcode: CACHE_MM
/* 2872 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 2884
/* 2876 */    MCD::OPC_CheckPredicate, 5, 33, 3, // Skip to: 3681
/* 2880 */    MCD::OPC_Decode, 150, 16, 80, // Opcode: SWP_MM
/* 2884 */    MCD::OPC_FilterValue, 13, 25, 3, // Skip to: 3681
/* 2888 */    MCD::OPC_CheckPredicate, 5, 21, 3, // Skip to: 3681
/* 2892 */    MCD::OPC_Decode, 148, 16, 80, // Opcode: SWM32_MM
/* 2896 */    MCD::OPC_FilterValue, 12, 7, 0, // Skip to: 2907
/* 2900 */    MCD::OPC_CheckPredicate, 5, 9, 3, // Skip to: 3681
/* 2904 */    MCD::OPC_Decode, 102, 78, // Opcode: ADDiu_MM
/* 2907 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 2919
/* 2911 */    MCD::OPC_CheckPredicate, 5, 254, 2, // Skip to: 3681
/* 2915 */    MCD::OPC_Decode, 156, 9, 79, // Opcode: LHu_MM
/* 2919 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 2931
/* 2923 */    MCD::OPC_CheckPredicate, 5, 242, 2, // Skip to: 3681
/* 2927 */    MCD::OPC_Decode, 215, 14, 79, // Opcode: SH_MM
/* 2931 */    MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 2943
/* 2935 */    MCD::OPC_CheckPredicate, 5, 230, 2, // Skip to: 3681
/* 2939 */    MCD::OPC_Decode, 151, 9, 79, // Opcode: LH_MM
/* 2943 */    MCD::OPC_FilterValue, 16, 207, 0, // Skip to: 3154
/* 2947 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 2950 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2962
/* 2954 */    MCD::OPC_CheckPredicate, 5, 211, 2, // Skip to: 3681
/* 2958 */    MCD::OPC_Decode, 204, 2, 82, // Opcode: BLTZ_MM
/* 2962 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 2974
/* 2966 */    MCD::OPC_CheckPredicate, 5, 199, 2, // Skip to: 3681
/* 2970 */    MCD::OPC_Decode, 201, 2, 82, // Opcode: BLTZAL_MM
/* 2974 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2986
/* 2978 */    MCD::OPC_CheckPredicate, 5, 187, 2, // Skip to: 3681
/* 2982 */    MCD::OPC_Decode, 134, 2, 82, // Opcode: BGEZ_MM
/* 2986 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 2998
/* 2990 */    MCD::OPC_CheckPredicate, 5, 175, 2, // Skip to: 3681
/* 2994 */    MCD::OPC_Decode, 131, 2, 82, // Opcode: BGEZAL_MM
/* 2998 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 3010
/* 3002 */    MCD::OPC_CheckPredicate, 5, 163, 2, // Skip to: 3681
/* 3006 */    MCD::OPC_Decode, 183, 2, 82, // Opcode: BLEZ_MM
/* 3010 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 3022
/* 3014 */    MCD::OPC_CheckPredicate, 5, 151, 2, // Skip to: 3681
/* 3018 */    MCD::OPC_Decode, 226, 2, 82, // Opcode: BNEZC_MM
/* 3022 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 3034
/* 3026 */    MCD::OPC_CheckPredicate, 5, 139, 2, // Skip to: 3681
/* 3030 */    MCD::OPC_Decode, 149, 2, 82, // Opcode: BGTZ_MM
/* 3034 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 3046
/* 3038 */    MCD::OPC_CheckPredicate, 5, 127, 2, // Skip to: 3681
/* 3042 */    MCD::OPC_Decode, 240, 1, 82, // Opcode: BEQZC_MM
/* 3046 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 3058
/* 3050 */    MCD::OPC_CheckPredicate, 5, 115, 2, // Skip to: 3681
/* 3054 */    MCD::OPC_Decode, 242, 16, 83, // Opcode: TLTI_MM
/* 3058 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 3070
/* 3062 */    MCD::OPC_CheckPredicate, 5, 103, 2, // Skip to: 3681
/* 3066 */    MCD::OPC_Decode, 225, 16, 83, // Opcode: TGEI_MM
/* 3070 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 3082
/* 3074 */    MCD::OPC_CheckPredicate, 5, 91, 2, // Skip to: 3681
/* 3078 */    MCD::OPC_Decode, 241, 16, 83, // Opcode: TLTIU_MM
/* 3082 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 3094
/* 3086 */    MCD::OPC_CheckPredicate, 5, 79, 2, // Skip to: 3681
/* 3090 */    MCD::OPC_Decode, 224, 16, 83, // Opcode: TGEIU_MM
/* 3094 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 3106
/* 3098 */    MCD::OPC_CheckPredicate, 5, 67, 2, // Skip to: 3681
/* 3102 */    MCD::OPC_Decode, 248, 16, 83, // Opcode: TNEI_MM
/* 3106 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 3118
/* 3110 */    MCD::OPC_CheckPredicate, 5, 55, 2, // Skip to: 3681
/* 3114 */    MCD::OPC_Decode, 183, 9, 83, // Opcode: LUi_MM
/* 3118 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 3130
/* 3122 */    MCD::OPC_CheckPredicate, 5, 43, 2, // Skip to: 3681
/* 3126 */    MCD::OPC_Decode, 219, 16, 83, // Opcode: TEQI_MM
/* 3130 */    MCD::OPC_FilterValue, 17, 8, 0, // Skip to: 3142
/* 3134 */    MCD::OPC_CheckPredicate, 5, 31, 2, // Skip to: 3681
/* 3138 */    MCD::OPC_Decode, 200, 2, 82, // Opcode: BLTZALS_MM
/* 3142 */    MCD::OPC_FilterValue, 19, 23, 2, // Skip to: 3681
/* 3146 */    MCD::OPC_CheckPredicate, 5, 19, 2, // Skip to: 3681
/* 3150 */    MCD::OPC_Decode, 130, 2, 82, // Opcode: BGEZALS_MM
/* 3154 */    MCD::OPC_FilterValue, 20, 8, 0, // Skip to: 3166
/* 3158 */    MCD::OPC_CheckPredicate, 5, 7, 2, // Skip to: 3681
/* 3162 */    MCD::OPC_Decode, 178, 12, 84, // Opcode: ORi_MM
/* 3166 */    MCD::OPC_FilterValue, 21, 48, 0, // Skip to: 3218
/* 3170 */    MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 3173 */    MCD::OPC_FilterValue, 251, 2, 27, 0, // Skip to: 3205
/* 3178 */    MCD::OPC_ExtractField, 11, 2,  // Inst{12-11} ...
/* 3181 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 3193
/* 3185 */    MCD::OPC_CheckPredicate, 5, 236, 1, // Skip to: 3681
/* 3189 */    MCD::OPC_Decode, 246, 10, 85, // Opcode: MOVF_I_MM
/* 3193 */    MCD::OPC_FilterValue, 1, 228, 1, // Skip to: 3681
/* 3197 */    MCD::OPC_CheckPredicate, 5, 224, 1, // Skip to: 3681
/* 3201 */    MCD::OPC_Decode, 138, 11, 85, // Opcode: MOVT_I_MM
/* 3205 */    MCD::OPC_FilterValue, 160, 3, 215, 1, // Skip to: 3681
/* 3210 */    MCD::OPC_CheckPredicate, 5, 211, 1, // Skip to: 3681
/* 3214 */    MCD::OPC_Decode, 237, 12, 86, // Opcode: PREFX_MM
/* 3218 */    MCD::OPC_FilterValue, 24, 49, 1, // Skip to: 3527
/* 3222 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 3225 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 3237
/* 3229 */    MCD::OPC_CheckPredicate, 5, 192, 1, // Skip to: 3681
/* 3233 */    MCD::OPC_Decode, 200, 9, 80, // Opcode: LWL_MM
/* 3237 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3249
/* 3241 */    MCD::OPC_CheckPredicate, 5, 180, 1, // Skip to: 3681
/* 3245 */    MCD::OPC_Decode, 212, 9, 80, // Opcode: LWR_MM
/* 3249 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 3261
/* 3253 */    MCD::OPC_CheckPredicate, 5, 168, 1, // Skip to: 3681
/* 3257 */    MCD::OPC_Decode, 238, 12, 81, // Opcode: PREF_MM
/* 3261 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 3273
/* 3265 */    MCD::OPC_CheckPredicate, 5, 156, 1, // Skip to: 3681
/* 3269 */    MCD::OPC_Decode, 165, 9, 80, // Opcode: LL_MM
/* 3273 */    MCD::OPC_FilterValue, 6, 99, 0, // Skip to: 3376
/* 3277 */    MCD::OPC_ExtractField, 9, 3,  // Inst{11-9} ...
/* 3280 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 3292
/* 3284 */    MCD::OPC_CheckPredicate, 5, 137, 1, // Skip to: 3681
/* 3288 */    MCD::OPC_Decode, 247, 8, 87, // Opcode: LBuE_MM
/* 3292 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3304
/* 3296 */    MCD::OPC_CheckPredicate, 5, 125, 1, // Skip to: 3681
/* 3300 */    MCD::OPC_Decode, 155, 9, 87, // Opcode: LHuE_MM
/* 3304 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 3316
/* 3308 */    MCD::OPC_CheckPredicate, 5, 113, 1, // Skip to: 3681
/* 3312 */    MCD::OPC_Decode, 199, 9, 87, // Opcode: LWLE_MM
/* 3316 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 3328
/* 3320 */    MCD::OPC_CheckPredicate, 5, 101, 1, // Skip to: 3681
/* 3324 */    MCD::OPC_Decode, 211, 9, 87, // Opcode: LWRE_MM
/* 3328 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 3340
/* 3332 */    MCD::OPC_CheckPredicate, 5, 89, 1, // Skip to: 3681
/* 3336 */    MCD::OPC_Decode, 235, 8, 87, // Opcode: LBE_MM
/* 3340 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 3352
/* 3344 */    MCD::OPC_CheckPredicate, 5, 77, 1, // Skip to: 3681
/* 3348 */    MCD::OPC_Decode, 147, 9, 87, // Opcode: LHE_MM
/* 3352 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 3364
/* 3356 */    MCD::OPC_CheckPredicate, 5, 65, 1, // Skip to: 3681
/* 3360 */    MCD::OPC_Decode, 163, 9, 87, // Opcode: LLE_MM
/* 3364 */    MCD::OPC_FilterValue, 7, 57, 1, // Skip to: 3681
/* 3368 */    MCD::OPC_CheckPredicate, 5, 53, 1, // Skip to: 3681
/* 3372 */    MCD::OPC_Decode, 193, 9, 87, // Opcode: LWE_MM
/* 3376 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 3388
/* 3380 */    MCD::OPC_CheckPredicate, 5, 41, 1, // Skip to: 3681
/* 3384 */    MCD::OPC_Decode, 145, 16, 80, // Opcode: SWL_MM
/* 3388 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 3400
/* 3392 */    MCD::OPC_CheckPredicate, 5, 29, 1, // Skip to: 3681
/* 3396 */    MCD::OPC_Decode, 155, 16, 80, // Opcode: SWR_MM
/* 3400 */    MCD::OPC_FilterValue, 10, 99, 0, // Skip to: 3503
/* 3404 */    MCD::OPC_ExtractField, 9, 3,  // Inst{11-9} ...
/* 3407 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 3419
/* 3411 */    MCD::OPC_CheckPredicate, 5, 10, 1, // Skip to: 3681
/* 3415 */    MCD::OPC_Decode, 144, 16, 87, // Opcode: SWLE_MM
/* 3419 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 3431
/* 3423 */    MCD::OPC_CheckPredicate, 5, 254, 0, // Skip to: 3681
/* 3427 */    MCD::OPC_Decode, 154, 16, 87, // Opcode: SWRE_MM
/* 3431 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 3443
/* 3435 */    MCD::OPC_CheckPredicate, 5, 242, 0, // Skip to: 3681
/* 3439 */    MCD::OPC_Decode, 235, 12, 88, // Opcode: PREFE_MM
/* 3443 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 3455
/* 3447 */    MCD::OPC_CheckPredicate, 5, 230, 0, // Skip to: 3681
/* 3451 */    MCD::OPC_Decode, 165, 3, 88, // Opcode: CACHEE_MM
/* 3455 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 3467
/* 3459 */    MCD::OPC_CheckPredicate, 5, 218, 0, // Skip to: 3681
/* 3463 */    MCD::OPC_Decode, 227, 13, 87, // Opcode: SBE_MM
/* 3467 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 3479
/* 3471 */    MCD::OPC_CheckPredicate, 5, 206, 0, // Skip to: 3681
/* 3475 */    MCD::OPC_Decode, 164, 14, 87, // Opcode: SHE_MM
/* 3479 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 3491
/* 3483 */    MCD::OPC_CheckPredicate, 5, 194, 0, // Skip to: 3681
/* 3487 */    MCD::OPC_Decode, 235, 13, 87, // Opcode: SCE_MM
/* 3491 */    MCD::OPC_FilterValue, 7, 186, 0, // Skip to: 3681
/* 3495 */    MCD::OPC_CheckPredicate, 5, 182, 0, // Skip to: 3681
/* 3499 */    MCD::OPC_Decode, 139, 16, 87, // Opcode: SWE_MM
/* 3503 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 3515
/* 3507 */    MCD::OPC_CheckPredicate, 5, 170, 0, // Skip to: 3681
/* 3511 */    MCD::OPC_Decode, 237, 13, 80, // Opcode: SC_MM
/* 3515 */    MCD::OPC_FilterValue, 14, 162, 0, // Skip to: 3681
/* 3519 */    MCD::OPC_CheckPredicate, 5, 158, 0, // Skip to: 3681
/* 3523 */    MCD::OPC_Decode, 215, 9, 80, // Opcode: LWU_MM
/* 3527 */    MCD::OPC_FilterValue, 28, 8, 0, // Skip to: 3539
/* 3531 */    MCD::OPC_CheckPredicate, 5, 146, 0, // Skip to: 3681
/* 3535 */    MCD::OPC_Decode, 170, 17, 84, // Opcode: XORi_MM
/* 3539 */    MCD::OPC_FilterValue, 29, 8, 0, // Skip to: 3551
/* 3543 */    MCD::OPC_CheckPredicate, 5, 134, 0, // Skip to: 3681
/* 3547 */    MCD::OPC_Decode, 205, 8, 89, // Opcode: JALS_MM
/* 3551 */    MCD::OPC_FilterValue, 30, 7, 0, // Skip to: 3562
/* 3555 */    MCD::OPC_CheckPredicate, 5, 122, 0, // Skip to: 3681
/* 3559 */    MCD::OPC_Decode, 33, 90, // Opcode: ADDIUPC_MM
/* 3562 */    MCD::OPC_FilterValue, 36, 8, 0, // Skip to: 3574
/* 3566 */    MCD::OPC_CheckPredicate, 5, 111, 0, // Skip to: 3681
/* 3570 */    MCD::OPC_Decode, 247, 14, 78, // Opcode: SLTi_MM
/* 3574 */    MCD::OPC_FilterValue, 37, 8, 0, // Skip to: 3586
/* 3578 */    MCD::OPC_CheckPredicate, 5, 99, 0, // Skip to: 3681
/* 3582 */    MCD::OPC_Decode, 241, 1, 91, // Opcode: BEQ_MM
/* 3586 */    MCD::OPC_FilterValue, 44, 8, 0, // Skip to: 3598
/* 3590 */    MCD::OPC_CheckPredicate, 5, 87, 0, // Skip to: 3681
/* 3594 */    MCD::OPC_Decode, 250, 14, 78, // Opcode: SLTiu_MM
/* 3598 */    MCD::OPC_FilterValue, 45, 8, 0, // Skip to: 3610
/* 3602 */    MCD::OPC_CheckPredicate, 5, 75, 0, // Skip to: 3681
/* 3606 */    MCD::OPC_Decode, 227, 2, 91, // Opcode: BNE_MM
/* 3610 */    MCD::OPC_FilterValue, 52, 7, 0, // Skip to: 3621
/* 3614 */    MCD::OPC_CheckPredicate, 5, 63, 0, // Skip to: 3681
/* 3618 */    MCD::OPC_Decode, 127, 84, // Opcode: ANDi_MM
/* 3621 */    MCD::OPC_FilterValue, 53, 8, 0, // Skip to: 3633
/* 3625 */    MCD::OPC_CheckPredicate, 5, 52, 0, // Skip to: 3681
/* 3629 */    MCD::OPC_Decode, 223, 8, 89, // Opcode: J_MM
/* 3633 */    MCD::OPC_FilterValue, 60, 8, 0, // Skip to: 3645
/* 3637 */    MCD::OPC_CheckPredicate, 5, 40, 0, // Skip to: 3681
/* 3641 */    MCD::OPC_Decode, 207, 8, 89, // Opcode: JALX_MM
/* 3645 */    MCD::OPC_FilterValue, 61, 8, 0, // Skip to: 3657
/* 3649 */    MCD::OPC_CheckPredicate, 5, 28, 0, // Skip to: 3681
/* 3653 */    MCD::OPC_Decode, 208, 8, 89, // Opcode: JAL_MM
/* 3657 */    MCD::OPC_FilterValue, 62, 8, 0, // Skip to: 3669
/* 3661 */    MCD::OPC_CheckPredicate, 5, 16, 0, // Skip to: 3681
/* 3665 */    MCD::OPC_Decode, 160, 16, 79, // Opcode: SW_MM
/* 3669 */    MCD::OPC_FilterValue, 63, 8, 0, // Skip to: 3681
/* 3673 */    MCD::OPC_CheckPredicate, 5, 4, 0, // Skip to: 3681
/* 3677 */    MCD::OPC_Decode, 221, 9, 79, // Opcode: LW_MM
/* 3681 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableMicroMipsR616[] = {
/* 0 */       MCD::OPC_ExtractField, 10, 6,  // Inst{15-10} ...
/* 3 */       MCD::OPC_FilterValue, 1, 26, 0, // Skip to: 33
/* 7 */       MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 10 */      MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 21
/* 14 */      MCD::OPC_CheckPredicate, 10, 68, 1, // Skip to: 342
/* 18 */      MCD::OPC_Decode, 69, 92, // Opcode: ADDU16_MMR6
/* 21 */      MCD::OPC_FilterValue, 1, 61, 1, // Skip to: 342
/* 25 */      MCD::OPC_CheckPredicate, 10, 57, 1, // Skip to: 342
/* 29 */      MCD::OPC_Decode, 228, 15, 92, // Opcode: SUBU16_MMR6
/* 33 */      MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 45
/* 37 */      MCD::OPC_CheckPredicate, 10, 45, 1, // Skip to: 342
/* 41 */      MCD::OPC_Decode, 238, 10, 21, // Opcode: MOVE16_MMR6
/* 45 */      MCD::OPC_FilterValue, 9, 27, 0, // Skip to: 76
/* 49 */      MCD::OPC_ExtractField, 0, 1,  // Inst{0} ...
/* 52 */      MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 64
/* 56 */      MCD::OPC_CheckPredicate, 10, 26, 1, // Skip to: 342
/* 60 */      MCD::OPC_Decode, 227, 14, 22, // Opcode: SLL16_MMR6
/* 64 */      MCD::OPC_FilterValue, 1, 18, 1, // Skip to: 342
/* 68 */      MCD::OPC_CheckPredicate, 10, 14, 1, // Skip to: 342
/* 72 */      MCD::OPC_Decode, 165, 15, 22, // Opcode: SRL16_MMR6
/* 76 */      MCD::OPC_FilterValue, 11, 7, 0, // Skip to: 87
/* 80 */      MCD::OPC_CheckPredicate, 10, 2, 1, // Skip to: 342
/* 84 */      MCD::OPC_Decode, 116, 23, // Opcode: ANDI16_MMR6
/* 87 */      MCD::OPC_FilterValue, 17, 155, 0, // Skip to: 246
/* 91 */      MCD::OPC_ExtractField, 0, 4,  // Inst{3-0} ...
/* 94 */      MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 106
/* 98 */      MCD::OPC_CheckPredicate, 10, 240, 0, // Skip to: 342
/* 102 */     MCD::OPC_Decode, 161, 12, 93, // Opcode: NOT16_MMR6
/* 106 */     MCD::OPC_FilterValue, 1, 7, 0, // Skip to: 117
/* 110 */     MCD::OPC_CheckPredicate, 10, 228, 0, // Skip to: 342
/* 114 */     MCD::OPC_Decode, 113, 94, // Opcode: AND16_MMR6
/* 117 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 129
/* 121 */     MCD::OPC_CheckPredicate, 10, 217, 0, // Skip to: 342
/* 125 */     MCD::OPC_Decode, 202, 9, 26, // Opcode: LWM16_MMR6
/* 129 */     MCD::OPC_FilterValue, 3, 27, 0, // Skip to: 160
/* 133 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 136 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 148
/* 140 */     MCD::OPC_CheckPredicate, 10, 198, 0, // Skip to: 342
/* 144 */     MCD::OPC_Decode, 218, 8, 95, // Opcode: JRC16_MMR6
/* 148 */     MCD::OPC_FilterValue, 1, 190, 0, // Skip to: 342
/* 152 */     MCD::OPC_CheckPredicate, 10, 186, 0, // Skip to: 342
/* 156 */     MCD::OPC_Decode, 219, 8, 96, // Opcode: JRCADDIUSP_MMR6
/* 160 */     MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 172
/* 164 */     MCD::OPC_CheckPredicate, 10, 174, 0, // Skip to: 342
/* 168 */     MCD::OPC_Decode, 158, 17, 94, // Opcode: XOR16_MMR6
/* 172 */     MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 184
/* 176 */     MCD::OPC_CheckPredicate, 5, 162, 0, // Skip to: 342
/* 180 */     MCD::OPC_Decode, 166, 12, 94, // Opcode: OR16_MMR6
/* 184 */     MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 196
/* 188 */     MCD::OPC_CheckPredicate, 10, 150, 0, // Skip to: 342
/* 192 */     MCD::OPC_Decode, 147, 16, 26, // Opcode: SWM16_MMR6
/* 196 */     MCD::OPC_FilterValue, 11, 142, 0, // Skip to: 342
/* 200 */     MCD::OPC_ExtractField, 4, 1,  // Inst{4} ...
/* 203 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 215
/* 207 */     MCD::OPC_CheckPredicate, 10, 131, 0, // Skip to: 342
/* 211 */     MCD::OPC_Decode, 199, 8, 95, // Opcode: JALRC16_MMR6
/* 215 */     MCD::OPC_FilterValue, 1, 123, 0, // Skip to: 342
/* 219 */     MCD::OPC_ExtractField, 5, 1,  // Inst{5} ...
/* 222 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 234
/* 226 */     MCD::OPC_CheckPredicate, 10, 112, 0, // Skip to: 342
/* 230 */     MCD::OPC_Decode, 239, 2, 97, // Opcode: BREAK16_MMR6
/* 234 */     MCD::OPC_FilterValue, 1, 104, 0, // Skip to: 342
/* 238 */     MCD::OPC_CheckPredicate, 10, 100, 0, // Skip to: 342
/* 242 */     MCD::OPC_Decode, 242, 13, 97, // Opcode: SDBBP16_MMR6
/* 246 */     MCD::OPC_FilterValue, 34, 8, 0, // Skip to: 258
/* 250 */     MCD::OPC_CheckPredicate, 10, 88, 0, // Skip to: 342
/* 254 */     MCD::OPC_Decode, 224, 13, 20, // Opcode: SB16_MMR6
/* 258 */     MCD::OPC_FilterValue, 35, 8, 0, // Skip to: 270
/* 262 */     MCD::OPC_CheckPredicate, 10, 76, 0, // Skip to: 342
/* 266 */     MCD::OPC_Decode, 239, 1, 37, // Opcode: BEQZC16_MMR6
/* 270 */     MCD::OPC_FilterValue, 42, 8, 0, // Skip to: 282
/* 274 */     MCD::OPC_CheckPredicate, 10, 64, 0, // Skip to: 342
/* 278 */     MCD::OPC_Decode, 161, 14, 20, // Opcode: SH16_MMR6
/* 282 */     MCD::OPC_FilterValue, 43, 8, 0, // Skip to: 294
/* 286 */     MCD::OPC_CheckPredicate, 10, 52, 0, // Skip to: 342
/* 290 */     MCD::OPC_Decode, 225, 2, 37, // Opcode: BNEZC16_MMR6
/* 294 */     MCD::OPC_FilterValue, 50, 8, 0, // Skip to: 306
/* 298 */     MCD::OPC_CheckPredicate, 10, 40, 0, // Skip to: 342
/* 302 */     MCD::OPC_Decode, 157, 16, 30, // Opcode: SWSP_MMR6
/* 306 */     MCD::OPC_FilterValue, 51, 8, 0, // Skip to: 318
/* 310 */     MCD::OPC_CheckPredicate, 10, 28, 0, // Skip to: 342
/* 314 */     MCD::OPC_Decode, 211, 1, 38, // Opcode: BC16_MMR6
/* 318 */     MCD::OPC_FilterValue, 58, 8, 0, // Skip to: 330
/* 322 */     MCD::OPC_CheckPredicate, 10, 16, 0, // Skip to: 342
/* 326 */     MCD::OPC_Decode, 131, 16, 20, // Opcode: SW16_MMR6
/* 330 */     MCD::OPC_FilterValue, 59, 8, 0, // Skip to: 342
/* 334 */     MCD::OPC_CheckPredicate, 10, 4, 0, // Skip to: 342
/* 338 */     MCD::OPC_Decode, 158, 9, 39, // Opcode: LI16_MMR6
/* 342 */     MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableMicroMipsR632[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 0, 52, 2, // Skip to: 571
/* 7 */       MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 10 */      MCD::OPC_FilterValue, 0, 96, 0, // Skip to: 110
/* 14 */      MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 17 */      MCD::OPC_FilterValue, 0, 47, 0, // Skip to: 68
/* 21 */      MCD::OPC_ExtractField, 11, 15,  // Inst{25-11} ...
/* 24 */      MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 36
/* 28 */      MCD::OPC_CheckPredicate, 11, 28, 0, // Skip to: 60
/* 32 */      MCD::OPC_Decode, 187, 15, 0, // Opcode: SSNOP_MMR6
/* 36 */      MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 48
/* 40 */      MCD::OPC_CheckPredicate, 11, 16, 0, // Skip to: 60
/* 44 */      MCD::OPC_Decode, 174, 6, 0, // Opcode: EHB_MMR6
/* 48 */      MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 60
/* 52 */      MCD::OPC_CheckPredicate, 11, 4, 0, // Skip to: 60
/* 56 */      MCD::OPC_Decode, 183, 12, 0, // Opcode: PAUSE_MMR6
/* 60 */      MCD::OPC_CheckPredicate, 11, 226, 9, // Skip to: 2594
/* 64 */      MCD::OPC_Decode, 240, 14, 40, // Opcode: SLL_MMR6
/* 68 */      MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 80
/* 72 */      MCD::OPC_CheckPredicate, 11, 214, 9, // Skip to: 2594
/* 76 */      MCD::OPC_Decode, 145, 14, 41, // Opcode: SELEQZ_MMR6
/* 80 */      MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 92
/* 84 */      MCD::OPC_CheckPredicate, 11, 202, 9, // Skip to: 2594
/* 88 */      MCD::OPC_Decode, 151, 14, 41, // Opcode: SELNEZ_MMR6
/* 92 */      MCD::OPC_FilterValue, 7, 194, 9, // Skip to: 2594
/* 96 */      MCD::OPC_CheckPredicate, 11, 190, 9, // Skip to: 2594
/* 100 */     MCD::OPC_CheckField, 14, 2, 0, 184, 9, // Skip to: 2594
/* 106 */     MCD::OPC_Decode, 173, 13, 98, // Opcode: RDHWR_MMR6
/* 110 */     MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 122
/* 114 */     MCD::OPC_CheckPredicate, 11, 172, 9, // Skip to: 2594
/* 118 */     MCD::OPC_Decode, 241, 2, 42, // Opcode: BREAK_MMR6
/* 122 */     MCD::OPC_FilterValue, 15, 14, 0, // Skip to: 140
/* 126 */     MCD::OPC_CheckPredicate, 11, 160, 9, // Skip to: 2594
/* 130 */     MCD::OPC_CheckField, 6, 3, 0, 154, 9, // Skip to: 2594
/* 136 */     MCD::OPC_Decode, 175, 9, 99, // Opcode: LSA_MMR6
/* 140 */     MCD::OPC_FilterValue, 16, 114, 0, // Skip to: 258
/* 144 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 147 */     MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 165
/* 151 */     MCD::OPC_CheckPredicate, 11, 135, 9, // Skip to: 2594
/* 155 */     MCD::OPC_CheckField, 16, 5, 0, 129, 9, // Skip to: 2594
/* 161 */     MCD::OPC_Decode, 236, 3, 14, // Opcode: CLZ_MMR6
/* 165 */     MCD::OPC_FilterValue, 4, 7, 0, // Skip to: 176
/* 169 */     MCD::OPC_CheckPredicate, 11, 117, 9, // Skip to: 2594
/* 173 */     MCD::OPC_Decode, 98, 41, // Opcode: ADD_MMR6
/* 176 */     MCD::OPC_FilterValue, 5, 7, 0, // Skip to: 187
/* 180 */     MCD::OPC_CheckPredicate, 11, 106, 9, // Skip to: 2594
/* 184 */     MCD::OPC_Decode, 74, 41, // Opcode: ADDU_MMR6
/* 187 */     MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 199
/* 191 */     MCD::OPC_CheckPredicate, 11, 95, 9, // Skip to: 2594
/* 195 */     MCD::OPC_Decode, 251, 15, 41, // Opcode: SUB_MMR6
/* 199 */     MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 211
/* 203 */     MCD::OPC_CheckPredicate, 11, 83, 9, // Skip to: 2594
/* 207 */     MCD::OPC_Decode, 233, 15, 41, // Opcode: SUBU_MMR6
/* 211 */     MCD::OPC_FilterValue, 9, 7, 0, // Skip to: 222
/* 215 */     MCD::OPC_CheckPredicate, 11, 71, 9, // Skip to: 2594
/* 219 */     MCD::OPC_Decode, 120, 41, // Opcode: AND_MMR6
/* 222 */     MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 234
/* 226 */     MCD::OPC_CheckPredicate, 11, 60, 9, // Skip to: 2594
/* 230 */     MCD::OPC_Decode, 171, 12, 41, // Opcode: OR_MMR6
/* 234 */     MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 246
/* 238 */     MCD::OPC_CheckPredicate, 11, 48, 9, // Skip to: 2594
/* 242 */     MCD::OPC_Decode, 155, 12, 41, // Opcode: NOR_MMR6
/* 246 */     MCD::OPC_FilterValue, 12, 40, 9, // Skip to: 2594
/* 250 */     MCD::OPC_CheckPredicate, 11, 36, 9, // Skip to: 2594
/* 254 */     MCD::OPC_Decode, 163, 17, 41, // Opcode: XOR_MMR6
/* 258 */     MCD::OPC_FilterValue, 24, 99, 0, // Skip to: 361
/* 262 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 265 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 277
/* 269 */     MCD::OPC_CheckPredicate, 11, 17, 9, // Skip to: 2594
/* 273 */     MCD::OPC_Decode, 243, 11, 41, // Opcode: MUL_MMR6
/* 277 */     MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 289
/* 281 */     MCD::OPC_CheckPredicate, 11, 5, 9, // Skip to: 2594
/* 285 */     MCD::OPC_Decode, 206, 11, 41, // Opcode: MUH_MMR6
/* 289 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 301
/* 293 */     MCD::OPC_CheckPredicate, 11, 249, 8, // Skip to: 2594
/* 297 */     MCD::OPC_Decode, 237, 11, 41, // Opcode: MULU_MMR6
/* 301 */     MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 313
/* 305 */     MCD::OPC_CheckPredicate, 11, 237, 8, // Skip to: 2594
/* 309 */     MCD::OPC_Decode, 205, 11, 41, // Opcode: MUHU_MMR6
/* 313 */     MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 325
/* 317 */     MCD::OPC_CheckPredicate, 11, 225, 8, // Skip to: 2594
/* 321 */     MCD::OPC_Decode, 191, 5, 41, // Opcode: DIV_MMR6
/* 325 */     MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 337
/* 329 */     MCD::OPC_CheckPredicate, 11, 213, 8, // Skip to: 2594
/* 333 */     MCD::OPC_Decode, 228, 10, 41, // Opcode: MOD_MMR6
/* 337 */     MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 349
/* 341 */     MCD::OPC_CheckPredicate, 11, 201, 8, // Skip to: 2594
/* 345 */     MCD::OPC_Decode, 190, 5, 41, // Opcode: DIVU_MMR6
/* 349 */     MCD::OPC_FilterValue, 7, 193, 8, // Skip to: 2594
/* 353 */     MCD::OPC_CheckPredicate, 11, 189, 8, // Skip to: 2594
/* 357 */     MCD::OPC_Decode, 227, 10, 41, // Opcode: MODU_MMR6
/* 361 */     MCD::OPC_FilterValue, 31, 13, 0, // Skip to: 378
/* 365 */     MCD::OPC_CheckPredicate, 11, 177, 8, // Skip to: 2594
/* 369 */     MCD::OPC_CheckField, 6, 3, 0, 171, 8, // Skip to: 2594
/* 375 */     MCD::OPC_Decode, 108, 100, // Opcode: ALIGN_MMR6
/* 378 */     MCD::OPC_FilterValue, 60, 164, 8, // Skip to: 2594
/* 382 */     MCD::OPC_ExtractField, 6, 10,  // Inst{15-6} ...
/* 385 */     MCD::OPC_FilterValue, 44, 8, 0, // Skip to: 397
/* 389 */     MCD::OPC_CheckPredicate, 11, 153, 8, // Skip to: 2594
/* 393 */     MCD::OPC_Decode, 168, 2, 74, // Opcode: BITSWAP_MMR6
/* 397 */     MCD::OPC_FilterValue, 172, 1, 8, 0, // Skip to: 410
/* 402 */     MCD::OPC_CheckPredicate, 11, 140, 8, // Skip to: 2594
/* 406 */     MCD::OPC_Decode, 134, 14, 61, // Opcode: SEB_MMR6
/* 410 */     MCD::OPC_FilterValue, 236, 1, 8, 0, // Skip to: 423
/* 415 */     MCD::OPC_CheckPredicate, 11, 127, 8, // Skip to: 2594
/* 419 */     MCD::OPC_Decode, 138, 14, 61, // Opcode: SEH_MMR6
/* 423 */     MCD::OPC_FilterValue, 172, 2, 8, 0, // Skip to: 436
/* 428 */     MCD::OPC_CheckPredicate, 11, 114, 8, // Skip to: 2594
/* 432 */     MCD::OPC_Decode, 216, 3, 61, // Opcode: CLO_MMR6
/* 436 */     MCD::OPC_FilterValue, 221, 2, 14, 0, // Skip to: 455
/* 441 */     MCD::OPC_CheckPredicate, 11, 101, 8, // Skip to: 2594
/* 445 */     MCD::OPC_CheckField, 21, 5, 0, 95, 8, // Skip to: 2594
/* 451 */     MCD::OPC_Decode, 177, 6, 71, // Opcode: EI_MMR6
/* 455 */     MCD::OPC_FilterValue, 173, 3, 14, 0, // Skip to: 474
/* 460 */     MCD::OPC_CheckPredicate, 11, 82, 8, // Skip to: 2594
/* 464 */     MCD::OPC_CheckField, 21, 5, 0, 76, 8, // Skip to: 2594
/* 470 */     MCD::OPC_Decode, 166, 16, 75, // Opcode: SYNC_MMR6
/* 474 */     MCD::OPC_FilterValue, 236, 3, 8, 0, // Skip to: 487
/* 479 */     MCD::OPC_CheckPredicate, 11, 63, 8, // Skip to: 2594
/* 483 */     MCD::OPC_Decode, 155, 17, 61, // Opcode: WSBH_MMR6
/* 487 */     MCD::OPC_FilterValue, 205, 4, 8, 0, // Skip to: 500
/* 492 */     MCD::OPC_CheckPredicate, 11, 50, 8, // Skip to: 2594
/* 496 */     MCD::OPC_Decode, 150, 17, 67, // Opcode: WAIT_MMR6
/* 500 */     MCD::OPC_FilterValue, 237, 6, 8, 0, // Skip to: 513
/* 505 */     MCD::OPC_CheckPredicate, 11, 37, 8, // Skip to: 2594
/* 509 */     MCD::OPC_Decode, 244, 13, 67, // Opcode: SDBBP_MMR6
/* 513 */     MCD::OPC_FilterValue, 133, 7, 8, 0, // Skip to: 526
/* 518 */     MCD::OPC_CheckPredicate, 11, 24, 8, // Skip to: 2594
/* 522 */     MCD::OPC_Decode, 174, 13, 61, // Opcode: RDPGPR_MMR6
/* 526 */     MCD::OPC_FilterValue, 197, 7, 8, 0, // Skip to: 539
/* 531 */     MCD::OPC_CheckPredicate, 11, 11, 8, // Skip to: 2594
/* 535 */     MCD::OPC_Decode, 152, 17, 61, // Opcode: WRPGPR_MMR6
/* 539 */     MCD::OPC_FilterValue, 205, 7, 2, 8, // Skip to: 2594
/* 544 */     MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 547 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 559
/* 551 */     MCD::OPC_CheckPredicate, 11, 247, 7, // Skip to: 2594
/* 555 */     MCD::OPC_Decode, 182, 6, 0, // Opcode: ERET_MMR6
/* 559 */     MCD::OPC_FilterValue, 1, 239, 7, // Skip to: 2594
/* 563 */     MCD::OPC_CheckPredicate, 11, 235, 7, // Skip to: 2594
/* 567 */     MCD::OPC_Decode, 180, 6, 0, // Opcode: ERETNC_MMR6
/* 571 */     MCD::OPC_FilterValue, 4, 22, 0, // Skip to: 597
/* 575 */     MCD::OPC_CheckPredicate, 11, 10, 0, // Skip to: 589
/* 579 */     MCD::OPC_CheckField, 16, 5, 0, 4, 0, // Skip to: 589
/* 585 */     MCD::OPC_Decode, 177, 9, 101, // Opcode: LUI_MMR6
/* 589 */     MCD::OPC_CheckPredicate, 11, 209, 7, // Skip to: 2594
/* 593 */     MCD::OPC_Decode, 172, 1, 78, // Opcode: AUI_MMR6
/* 597 */     MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 609
/* 601 */     MCD::OPC_CheckPredicate, 11, 197, 7, // Skip to: 2594
/* 605 */     MCD::OPC_Decode, 241, 8, 102, // Opcode: LBU_MMR6
/* 609 */     MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 621
/* 613 */     MCD::OPC_CheckPredicate, 11, 185, 7, // Skip to: 2594
/* 617 */     MCD::OPC_Decode, 230, 13, 79, // Opcode: SB_MMR6
/* 621 */     MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 633
/* 625 */     MCD::OPC_CheckPredicate, 11, 173, 7, // Skip to: 2594
/* 629 */     MCD::OPC_Decode, 243, 8, 102, // Opcode: LB_MMR6
/* 633 */     MCD::OPC_FilterValue, 8, 14, 0, // Skip to: 651
/* 637 */     MCD::OPC_CheckPredicate, 11, 161, 7, // Skip to: 2594
/* 641 */     MCD::OPC_CheckField, 12, 4, 6, 155, 7, // Skip to: 2594
/* 647 */     MCD::OPC_Decode, 168, 3, 81, // Opcode: CACHE_MMR6
/* 651 */     MCD::OPC_FilterValue, 12, 7, 0, // Skip to: 662
/* 655 */     MCD::OPC_CheckPredicate, 11, 143, 7, // Skip to: 2594
/* 659 */     MCD::OPC_Decode, 39, 78, // Opcode: ADDIU_MMR6
/* 662 */     MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 674
/* 666 */     MCD::OPC_CheckPredicate, 11, 132, 7, // Skip to: 2594
/* 670 */     MCD::OPC_Decode, 216, 14, 79, // Opcode: SH_MMR6
/* 674 */     MCD::OPC_FilterValue, 16, 39, 0, // Skip to: 717
/* 678 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 681 */     MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 693
/* 685 */     MCD::OPC_CheckPredicate, 11, 113, 7, // Skip to: 2594
/* 689 */     MCD::OPC_Decode, 164, 16, 103, // Opcode: SYNCI_MMR6
/* 693 */     MCD::OPC_FilterValue, 16, 8, 0, // Skip to: 705
/* 697 */     MCD::OPC_CheckPredicate, 12, 101, 7, // Skip to: 2594
/* 701 */     MCD::OPC_Decode, 164, 5, 104, // Opcode: DATI_MM64R6
/* 705 */     MCD::OPC_FilterValue, 17, 93, 7, // Skip to: 2594
/* 709 */     MCD::OPC_CheckPredicate, 12, 89, 7, // Skip to: 2594
/* 713 */     MCD::OPC_Decode, 160, 5, 104, // Opcode: DAHI_MM64R6
/* 717 */     MCD::OPC_FilterValue, 20, 8, 0, // Skip to: 729
/* 721 */     MCD::OPC_CheckPredicate, 11, 77, 7, // Skip to: 2594
/* 725 */     MCD::OPC_Decode, 169, 12, 78, // Opcode: ORI_MMR6
/* 729 */     MCD::OPC_FilterValue, 21, 32, 5, // Skip to: 2045
/* 733 */     MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 736 */     MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 748
/* 740 */     MCD::OPC_CheckPredicate, 13, 58, 7, // Skip to: 2594
/* 744 */     MCD::OPC_Decode, 216, 10, 105, // Opcode: MIN_S_MMR6
/* 748 */     MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 760
/* 752 */     MCD::OPC_CheckPredicate, 13, 46, 7, // Skip to: 2594
/* 756 */     MCD::OPC_Decode, 248, 3, 106, // Opcode: CMP_AF_S_MMR6
/* 760 */     MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 772
/* 764 */     MCD::OPC_CheckPredicate, 13, 34, 7, // Skip to: 2594
/* 768 */     MCD::OPC_Decode, 169, 10, 105, // Opcode: MAX_S_MMR6
/* 772 */     MCD::OPC_FilterValue, 21, 8, 0, // Skip to: 784
/* 776 */     MCD::OPC_CheckPredicate, 13, 22, 7, // Skip to: 2594
/* 780 */     MCD::OPC_Decode, 247, 3, 107, // Opcode: CMP_AF_D_MMR6
/* 784 */     MCD::OPC_FilterValue, 32, 14, 0, // Skip to: 802
/* 788 */     MCD::OPC_CheckPredicate, 11, 10, 7, // Skip to: 2594
/* 792 */     MCD::OPC_CheckField, 11, 5, 0, 4, 7, // Skip to: 2594
/* 798 */     MCD::OPC_Decode, 188, 13, 108, // Opcode: RINT_S_MMR6
/* 802 */     MCD::OPC_FilterValue, 35, 8, 0, // Skip to: 814
/* 806 */     MCD::OPC_CheckPredicate, 13, 248, 6, // Skip to: 2594
/* 810 */     MCD::OPC_Decode, 197, 10, 105, // Opcode: MINA_S_MMR6
/* 814 */     MCD::OPC_FilterValue, 43, 8, 0, // Skip to: 826
/* 818 */     MCD::OPC_CheckPredicate, 13, 236, 6, // Skip to: 2594
/* 822 */     MCD::OPC_Decode, 150, 10, 105, // Opcode: MAXA_S_MMR6
/* 826 */     MCD::OPC_FilterValue, 48, 8, 0, // Skip to: 838
/* 830 */     MCD::OPC_CheckPredicate, 13, 224, 6, // Skip to: 2594
/* 834 */     MCD::OPC_Decode, 228, 6, 109, // Opcode: FADD_S_MMR6
/* 838 */     MCD::OPC_FilterValue, 56, 8, 0, // Skip to: 850
/* 842 */     MCD::OPC_CheckPredicate, 11, 212, 6, // Skip to: 2594
/* 846 */     MCD::OPC_Decode, 147, 14, 105, // Opcode: SELEQZ_S_MMR6
/* 850 */     MCD::OPC_FilterValue, 69, 8, 0, // Skip to: 862
/* 854 */     MCD::OPC_CheckPredicate, 13, 200, 6, // Skip to: 2594
/* 858 */     MCD::OPC_Decode, 185, 4, 106, // Opcode: CMP_UN_S_MMR6
/* 862 */     MCD::OPC_FilterValue, 85, 8, 0, // Skip to: 874
/* 866 */     MCD::OPC_CheckPredicate, 13, 188, 6, // Skip to: 2594
/* 870 */     MCD::OPC_Decode, 183, 4, 107, // Opcode: CMP_UN_D_MMR6
/* 874 */     MCD::OPC_FilterValue, 96, 14, 0, // Skip to: 892
/* 878 */     MCD::OPC_CheckPredicate, 11, 176, 6, // Skip to: 2594
/* 882 */     MCD::OPC_CheckField, 11, 5, 0, 170, 6, // Skip to: 2594
/* 888 */     MCD::OPC_Decode, 197, 3, 108, // Opcode: CLASS_S_MMR6
/* 892 */     MCD::OPC_FilterValue, 112, 8, 0, // Skip to: 904
/* 896 */     MCD::OPC_CheckPredicate, 13, 158, 6, // Skip to: 2594
/* 900 */     MCD::OPC_Decode, 244, 7, 109, // Opcode: FSUB_S_MMR6
/* 904 */     MCD::OPC_FilterValue, 120, 8, 0, // Skip to: 916
/* 908 */     MCD::OPC_CheckPredicate, 11, 146, 6, // Skip to: 2594
/* 912 */     MCD::OPC_Decode, 140, 14, 105, // Opcode: SELENZ_S_MMR6
/* 916 */     MCD::OPC_FilterValue, 123, 27, 0, // Skip to: 947
/* 920 */     MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 923 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 935
/* 927 */     MCD::OPC_CheckPredicate, 13, 127, 6, // Skip to: 2594
/* 931 */     MCD::OPC_Decode, 193, 7, 110, // Opcode: FMOV_S_MMR6
/* 935 */     MCD::OPC_FilterValue, 4, 119, 6, // Skip to: 2594
/* 939 */     MCD::OPC_CheckPredicate, 13, 115, 6, // Skip to: 2594
/* 943 */     MCD::OPC_Decode, 190, 7, 111, // Opcode: FMOV_D_MMR6
/* 947 */     MCD::OPC_FilterValue, 133, 1, 8, 0, // Skip to: 960
/* 952 */     MCD::OPC_CheckPredicate, 13, 102, 6, // Skip to: 2594
/* 956 */     MCD::OPC_Decode, 253, 3, 106, // Opcode: CMP_EQ_S_MMR6
/* 960 */     MCD::OPC_FilterValue, 149, 1, 8, 0, // Skip to: 973
/* 965 */     MCD::OPC_CheckPredicate, 13, 89, 6, // Skip to: 2594
/* 969 */     MCD::OPC_Decode, 250, 3, 107, // Opcode: CMP_EQ_D_MMR6
/* 973 */     MCD::OPC_FilterValue, 176, 1, 8, 0, // Skip to: 986
/* 978 */     MCD::OPC_CheckPredicate, 13, 76, 6, // Skip to: 2594
/* 982 */     MCD::OPC_Decode, 203, 7, 109, // Opcode: FMUL_S_MMR6
/* 986 */     MCD::OPC_FilterValue, 184, 1, 8, 0, // Skip to: 999
/* 991 */     MCD::OPC_CheckPredicate, 11, 63, 6, // Skip to: 2594
/* 995 */     MCD::OPC_Decode, 156, 14, 112, // Opcode: SEL_S_MMR6
/* 999 */     MCD::OPC_FilterValue, 197, 1, 8, 0, // Skip to: 1012
/* 1004 */    MCD::OPC_CheckPredicate, 13, 50, 6, // Skip to: 2594
/* 1008 */    MCD::OPC_Decode, 173, 4, 106, // Opcode: CMP_UEQ_S_MMR6
/* 1012 */    MCD::OPC_FilterValue, 213, 1, 8, 0, // Skip to: 1025
/* 1017 */    MCD::OPC_CheckPredicate, 13, 37, 6, // Skip to: 2594
/* 1021 */    MCD::OPC_Decode, 171, 4, 107, // Opcode: CMP_UEQ_D_MMR6
/* 1025 */    MCD::OPC_FilterValue, 240, 1, 8, 0, // Skip to: 1038
/* 1030 */    MCD::OPC_CheckPredicate, 13, 24, 6, // Skip to: 2594
/* 1034 */    MCD::OPC_Decode, 138, 7, 109, // Opcode: FDIV_S_MMR6
/* 1038 */    MCD::OPC_FilterValue, 133, 2, 8, 0, // Skip to: 1051
/* 1043 */    MCD::OPC_CheckPredicate, 13, 11, 6, // Skip to: 2594
/* 1047 */    MCD::OPC_Decode, 137, 4, 106, // Opcode: CMP_LT_S_MMR6
/* 1051 */    MCD::OPC_FilterValue, 149, 2, 8, 0, // Skip to: 1064
/* 1056 */    MCD::OPC_CheckPredicate, 13, 254, 5, // Skip to: 2594
/* 1060 */    MCD::OPC_Decode, 134, 4, 107, // Opcode: CMP_LT_D_MMR6
/* 1064 */    MCD::OPC_FilterValue, 176, 2, 8, 0, // Skip to: 1077
/* 1069 */    MCD::OPC_CheckPredicate, 13, 241, 5, // Skip to: 2594
/* 1073 */    MCD::OPC_Decode, 224, 6, 113, // Opcode: FADD_D_MMR6
/* 1077 */    MCD::OPC_FilterValue, 187, 2, 51, 0, // Skip to: 1133
/* 1082 */    MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 1085 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1097
/* 1089 */    MCD::OPC_CheckPredicate, 13, 221, 5, // Skip to: 2594
/* 1093 */    MCD::OPC_Decode, 214, 4, 114, // Opcode: CVT_L_S_MMR6
/* 1097 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1109
/* 1101 */    MCD::OPC_CheckPredicate, 13, 209, 5, // Skip to: 2594
/* 1105 */    MCD::OPC_Decode, 230, 4, 110, // Opcode: CVT_W_S_MMR6
/* 1109 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 1121
/* 1113 */    MCD::OPC_CheckPredicate, 13, 197, 5, // Skip to: 2594
/* 1117 */    MCD::OPC_Decode, 211, 4, 115, // Opcode: CVT_L_D_MMR6
/* 1121 */    MCD::OPC_FilterValue, 9, 189, 5, // Skip to: 2594
/* 1125 */    MCD::OPC_CheckPredicate, 13, 185, 5, // Skip to: 2594
/* 1129 */    MCD::OPC_Decode, 226, 4, 116, // Opcode: CVT_W_D_MMR6
/* 1133 */    MCD::OPC_FilterValue, 197, 2, 8, 0, // Skip to: 1146
/* 1138 */    MCD::OPC_CheckPredicate, 13, 172, 5, // Skip to: 2594
/* 1142 */    MCD::OPC_Decode, 181, 4, 106, // Opcode: CMP_ULT_S_MMR6
/* 1146 */    MCD::OPC_FilterValue, 213, 2, 8, 0, // Skip to: 1159
/* 1151 */    MCD::OPC_CheckPredicate, 13, 159, 5, // Skip to: 2594
/* 1155 */    MCD::OPC_Decode, 179, 4, 107, // Opcode: CMP_ULT_D_MMR6
/* 1159 */    MCD::OPC_FilterValue, 240, 2, 8, 0, // Skip to: 1172
/* 1164 */    MCD::OPC_CheckPredicate, 13, 146, 5, // Skip to: 2594
/* 1168 */    MCD::OPC_Decode, 240, 7, 113, // Opcode: FSUB_D_MMR6
/* 1172 */    MCD::OPC_FilterValue, 133, 3, 8, 0, // Skip to: 1185
/* 1177 */    MCD::OPC_CheckPredicate, 13, 133, 5, // Skip to: 2594
/* 1181 */    MCD::OPC_Decode, 132, 4, 106, // Opcode: CMP_LE_S_MMR6
/* 1185 */    MCD::OPC_FilterValue, 149, 3, 8, 0, // Skip to: 1198
/* 1190 */    MCD::OPC_CheckPredicate, 13, 120, 5, // Skip to: 2594
/* 1194 */    MCD::OPC_Decode, 129, 4, 107, // Opcode: CMP_LE_D_MMR6
/* 1198 */    MCD::OPC_FilterValue, 176, 3, 8, 0, // Skip to: 1211
/* 1203 */    MCD::OPC_CheckPredicate, 13, 107, 5, // Skip to: 2594
/* 1207 */    MCD::OPC_Decode, 199, 7, 113, // Opcode: FMUL_D_MMR6
/* 1211 */    MCD::OPC_FilterValue, 184, 3, 8, 0, // Skip to: 1224
/* 1216 */    MCD::OPC_CheckPredicate, 13, 94, 5, // Skip to: 2594
/* 1220 */    MCD::OPC_Decode, 246, 9, 117, // Opcode: MADDF_S_MMR6
/* 1224 */    MCD::OPC_FilterValue, 197, 3, 8, 0, // Skip to: 1237
/* 1229 */    MCD::OPC_CheckPredicate, 13, 81, 5, // Skip to: 2594
/* 1233 */    MCD::OPC_Decode, 177, 4, 106, // Opcode: CMP_ULE_S_MMR6
/* 1237 */    MCD::OPC_FilterValue, 213, 3, 8, 0, // Skip to: 1250
/* 1242 */    MCD::OPC_CheckPredicate, 13, 68, 5, // Skip to: 2594
/* 1246 */    MCD::OPC_Decode, 175, 4, 107, // Opcode: CMP_ULE_D_MMR6
/* 1250 */    MCD::OPC_FilterValue, 240, 3, 8, 0, // Skip to: 1263
/* 1255 */    MCD::OPC_CheckPredicate, 13, 55, 5, // Skip to: 2594
/* 1259 */    MCD::OPC_Decode, 134, 7, 113, // Opcode: FDIV_D_MMR6
/* 1263 */    MCD::OPC_FilterValue, 248, 3, 8, 0, // Skip to: 1276
/* 1268 */    MCD::OPC_CheckPredicate, 13, 42, 5, // Skip to: 2594
/* 1272 */    MCD::OPC_Decode, 157, 11, 117, // Opcode: MSUBF_S_MMR6
/* 1276 */    MCD::OPC_FilterValue, 131, 4, 8, 0, // Skip to: 1289
/* 1281 */    MCD::OPC_CheckPredicate, 13, 29, 5, // Skip to: 2594
/* 1285 */    MCD::OPC_Decode, 211, 10, 118, // Opcode: MIN_D_MMR6
/* 1289 */    MCD::OPC_FilterValue, 133, 4, 8, 0, // Skip to: 1302
/* 1294 */    MCD::OPC_CheckPredicate, 13, 16, 5, // Skip to: 2594
/* 1298 */    MCD::OPC_Decode, 141, 4, 106, // Opcode: CMP_SAF_S_MMR6
/* 1302 */    MCD::OPC_FilterValue, 139, 4, 8, 0, // Skip to: 1315
/* 1307 */    MCD::OPC_CheckPredicate, 13, 3, 5, // Skip to: 2594
/* 1311 */    MCD::OPC_Decode, 164, 10, 118, // Opcode: MAX_D_MMR6
/* 1315 */    MCD::OPC_FilterValue, 149, 4, 8, 0, // Skip to: 1328
/* 1320 */    MCD::OPC_CheckPredicate, 13, 246, 4, // Skip to: 2594
/* 1324 */    MCD::OPC_Decode, 139, 4, 107, // Opcode: CMP_SAF_D_MMR6
/* 1328 */    MCD::OPC_FilterValue, 160, 4, 14, 0, // Skip to: 1347
/* 1333 */    MCD::OPC_CheckPredicate, 11, 233, 4, // Skip to: 2594
/* 1337 */    MCD::OPC_CheckField, 11, 5, 0, 227, 4, // Skip to: 2594
/* 1343 */    MCD::OPC_Decode, 186, 13, 119, // Opcode: RINT_D_MMR6
/* 1347 */    MCD::OPC_FilterValue, 163, 4, 8, 0, // Skip to: 1360
/* 1352 */    MCD::OPC_CheckPredicate, 13, 214, 4, // Skip to: 2594
/* 1356 */    MCD::OPC_Decode, 195, 10, 118, // Opcode: MINA_D_MMR6
/* 1360 */    MCD::OPC_FilterValue, 171, 4, 8, 0, // Skip to: 1373
/* 1365 */    MCD::OPC_CheckPredicate, 13, 201, 4, // Skip to: 2594
/* 1369 */    MCD::OPC_Decode, 148, 10, 118, // Opcode: MAXA_D_MMR6
/* 1373 */    MCD::OPC_FilterValue, 184, 4, 8, 0, // Skip to: 1386
/* 1378 */    MCD::OPC_CheckPredicate, 11, 188, 4, // Skip to: 2594
/* 1382 */    MCD::OPC_Decode, 144, 14, 118, // Opcode: SELEQZ_D_MMR6
/* 1386 */    MCD::OPC_FilterValue, 187, 4, 75, 0, // Skip to: 1466
/* 1391 */    MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 1394 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1406
/* 1398 */    MCD::OPC_CheckPredicate, 13, 168, 4, // Skip to: 2594
/* 1402 */    MCD::OPC_Decode, 209, 13, 110, // Opcode: RSQRT_S_MMR6
/* 1406 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1418
/* 1410 */    MCD::OPC_CheckPredicate, 13, 156, 4, // Skip to: 2594
/* 1414 */    MCD::OPC_Decode, 142, 15, 110, // Opcode: SQRT_S_MMR6
/* 1418 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1430
/* 1422 */    MCD::OPC_CheckPredicate, 13, 144, 4, // Skip to: 2594
/* 1426 */    MCD::OPC_Decode, 176, 13, 110, // Opcode: RECIP_S_MMR6
/* 1430 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 1442
/* 1434 */    MCD::OPC_CheckPredicate, 13, 132, 4, // Skip to: 2594
/* 1438 */    MCD::OPC_Decode, 208, 13, 116, // Opcode: RSQRT_D_MMR6
/* 1442 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 1454
/* 1446 */    MCD::OPC_CheckPredicate, 13, 120, 4, // Skip to: 2594
/* 1450 */    MCD::OPC_Decode, 141, 15, 111, // Opcode: SQRT_D_MMR6
/* 1454 */    MCD::OPC_FilterValue, 10, 112, 4, // Skip to: 2594
/* 1458 */    MCD::OPC_CheckPredicate, 13, 108, 4, // Skip to: 2594
/* 1462 */    MCD::OPC_Decode, 175, 13, 110, // Opcode: RECIP_D_MMR6
/* 1466 */    MCD::OPC_FilterValue, 197, 4, 8, 0, // Skip to: 1479
/* 1471 */    MCD::OPC_CheckPredicate, 13, 95, 4, // Skip to: 2594
/* 1475 */    MCD::OPC_Decode, 169, 4, 106, // Opcode: CMP_SUN_S_MMR6
/* 1479 */    MCD::OPC_FilterValue, 213, 4, 8, 0, // Skip to: 1492
/* 1484 */    MCD::OPC_CheckPredicate, 13, 82, 4, // Skip to: 2594
/* 1488 */    MCD::OPC_Decode, 167, 4, 107, // Opcode: CMP_SUN_D_MMR6
/* 1492 */    MCD::OPC_FilterValue, 224, 4, 14, 0, // Skip to: 1511
/* 1497 */    MCD::OPC_CheckPredicate, 11, 69, 4, // Skip to: 2594
/* 1501 */    MCD::OPC_CheckField, 11, 5, 0, 63, 4, // Skip to: 2594
/* 1507 */    MCD::OPC_Decode, 195, 3, 119, // Opcode: CLASS_D_MMR6
/* 1511 */    MCD::OPC_FilterValue, 248, 4, 8, 0, // Skip to: 1524
/* 1516 */    MCD::OPC_CheckPredicate, 11, 50, 4, // Skip to: 2594
/* 1520 */    MCD::OPC_Decode, 139, 14, 118, // Opcode: SELENZ_D_MMR6
/* 1524 */    MCD::OPC_FilterValue, 133, 5, 8, 0, // Skip to: 1537
/* 1529 */    MCD::OPC_CheckPredicate, 13, 37, 4, // Skip to: 2594
/* 1533 */    MCD::OPC_Decode, 145, 4, 106, // Opcode: CMP_SEQ_S_MMR6
/* 1537 */    MCD::OPC_FilterValue, 149, 5, 8, 0, // Skip to: 1550
/* 1542 */    MCD::OPC_CheckPredicate, 13, 24, 4, // Skip to: 2594
/* 1546 */    MCD::OPC_Decode, 143, 4, 107, // Opcode: CMP_SEQ_D_MMR6
/* 1550 */    MCD::OPC_FilterValue, 184, 5, 8, 0, // Skip to: 1563
/* 1555 */    MCD::OPC_CheckPredicate, 11, 11, 4, // Skip to: 2594
/* 1559 */    MCD::OPC_Decode, 154, 14, 120, // Opcode: SEL_D_MMR6
/* 1563 */    MCD::OPC_FilterValue, 197, 5, 8, 0, // Skip to: 1576
/* 1568 */    MCD::OPC_CheckPredicate, 13, 254, 3, // Skip to: 2594
/* 1572 */    MCD::OPC_Decode, 157, 4, 106, // Opcode: CMP_SUEQ_S_MMR6
/* 1576 */    MCD::OPC_FilterValue, 213, 5, 8, 0, // Skip to: 1589
/* 1581 */    MCD::OPC_CheckPredicate, 13, 241, 3, // Skip to: 2594
/* 1585 */    MCD::OPC_Decode, 155, 4, 107, // Opcode: CMP_SUEQ_D_MMR6
/* 1589 */    MCD::OPC_FilterValue, 133, 6, 8, 0, // Skip to: 1602
/* 1594 */    MCD::OPC_CheckPredicate, 13, 228, 3, // Skip to: 2594
/* 1598 */    MCD::OPC_Decode, 153, 4, 106, // Opcode: CMP_SLT_S_MMR6
/* 1602 */    MCD::OPC_FilterValue, 149, 6, 8, 0, // Skip to: 1615
/* 1607 */    MCD::OPC_CheckPredicate, 13, 215, 3, // Skip to: 2594
/* 1611 */    MCD::OPC_Decode, 151, 4, 107, // Opcode: CMP_SLT_D_MMR6
/* 1615 */    MCD::OPC_FilterValue, 187, 6, 195, 0, // Skip to: 1815
/* 1620 */    MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 1623 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1635
/* 1627 */    MCD::OPC_CheckPredicate, 13, 195, 3, // Skip to: 2594
/* 1631 */    MCD::OPC_Decode, 169, 7, 114, // Opcode: FLOOR_L_S_MMR6
/* 1635 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1647
/* 1639 */    MCD::OPC_CheckPredicate, 13, 183, 3, // Skip to: 2594
/* 1643 */    MCD::OPC_Decode, 176, 7, 110, // Opcode: FLOOR_W_S_MMR6
/* 1647 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1659
/* 1651 */    MCD::OPC_CheckPredicate, 13, 171, 3, // Skip to: 2594
/* 1655 */    MCD::OPC_Decode, 173, 3, 114, // Opcode: CEIL_L_S_MMR6
/* 1659 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 1671
/* 1663 */    MCD::OPC_CheckPredicate, 13, 159, 3, // Skip to: 2594
/* 1667 */    MCD::OPC_Decode, 180, 3, 110, // Opcode: CEIL_W_S_MMR6
/* 1671 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 1683
/* 1675 */    MCD::OPC_CheckPredicate, 13, 147, 3, // Skip to: 2594
/* 1679 */    MCD::OPC_Decode, 254, 16, 114, // Opcode: TRUNC_L_S_MMR6
/* 1683 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 1695
/* 1687 */    MCD::OPC_CheckPredicate, 13, 135, 3, // Skip to: 2594
/* 1691 */    MCD::OPC_Decode, 133, 17, 110, // Opcode: TRUNC_W_S_MMR6
/* 1695 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 1707
/* 1699 */    MCD::OPC_CheckPredicate, 13, 123, 3, // Skip to: 2594
/* 1703 */    MCD::OPC_Decode, 200, 13, 114, // Opcode: ROUND_L_S_MMR6
/* 1707 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 1719
/* 1711 */    MCD::OPC_CheckPredicate, 13, 111, 3, // Skip to: 2594
/* 1715 */    MCD::OPC_Decode, 207, 13, 110, // Opcode: ROUND_W_S_MMR6
/* 1719 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 1731
/* 1723 */    MCD::OPC_CheckPredicate, 13, 99, 3, // Skip to: 2594
/* 1727 */    MCD::OPC_Decode, 167, 7, 115, // Opcode: FLOOR_L_D_MMR6
/* 1731 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 1743
/* 1735 */    MCD::OPC_CheckPredicate, 13, 87, 3, // Skip to: 2594
/* 1739 */    MCD::OPC_Decode, 172, 7, 116, // Opcode: FLOOR_W_D_MMR6
/* 1743 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 1755
/* 1747 */    MCD::OPC_CheckPredicate, 13, 75, 3, // Skip to: 2594
/* 1751 */    MCD::OPC_Decode, 171, 3, 115, // Opcode: CEIL_L_D_MMR6
/* 1755 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 1767
/* 1759 */    MCD::OPC_CheckPredicate, 13, 63, 3, // Skip to: 2594
/* 1763 */    MCD::OPC_Decode, 176, 3, 116, // Opcode: CEIL_W_D_MMR6
/* 1767 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 1779
/* 1771 */    MCD::OPC_CheckPredicate, 13, 51, 3, // Skip to: 2594
/* 1775 */    MCD::OPC_Decode, 252, 16, 115, // Opcode: TRUNC_L_D_MMR6
/* 1779 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 1791
/* 1783 */    MCD::OPC_CheckPredicate, 13, 39, 3, // Skip to: 2594
/* 1787 */    MCD::OPC_Decode, 129, 17, 116, // Opcode: TRUNC_W_D_MMR6
/* 1791 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 1803
/* 1795 */    MCD::OPC_CheckPredicate, 13, 27, 3, // Skip to: 2594
/* 1799 */    MCD::OPC_Decode, 198, 13, 115, // Opcode: ROUND_L_D_MMR6
/* 1803 */    MCD::OPC_FilterValue, 15, 19, 3, // Skip to: 2594
/* 1807 */    MCD::OPC_CheckPredicate, 13, 15, 3, // Skip to: 2594
/* 1811 */    MCD::OPC_Decode, 203, 13, 115, // Opcode: ROUND_W_D_MMR6
/* 1815 */    MCD::OPC_FilterValue, 197, 6, 8, 0, // Skip to: 1828
/* 1820 */    MCD::OPC_CheckPredicate, 13, 2, 3, // Skip to: 2594
/* 1824 */    MCD::OPC_Decode, 165, 4, 106, // Opcode: CMP_SULT_S_MMR6
/* 1828 */    MCD::OPC_FilterValue, 213, 6, 8, 0, // Skip to: 1841
/* 1833 */    MCD::OPC_CheckPredicate, 13, 245, 2, // Skip to: 2594
/* 1837 */    MCD::OPC_Decode, 163, 4, 107, // Opcode: CMP_SULT_D_MMR6
/* 1841 */    MCD::OPC_FilterValue, 251, 6, 121, 0, // Skip to: 1967
/* 1846 */    MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 1849 */    MCD::OPC_FilterValue, 0, 7, 0, // Skip to: 1860
/* 1853 */    MCD::OPC_CheckPredicate, 13, 225, 2, // Skip to: 2594
/* 1857 */    MCD::OPC_Decode, 30, 110, // Opcode: ABS_S_MMR6
/* 1860 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 1872
/* 1864 */    MCD::OPC_CheckPredicate, 13, 214, 2, // Skip to: 2594
/* 1868 */    MCD::OPC_Decode, 211, 7, 110, // Opcode: FNEG_S_MMR6
/* 1872 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 1884
/* 1876 */    MCD::OPC_CheckPredicate, 13, 202, 2, // Skip to: 2594
/* 1880 */    MCD::OPC_Decode, 207, 4, 116, // Opcode: CVT_D_S_MMR6
/* 1884 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 1896
/* 1888 */    MCD::OPC_CheckPredicate, 13, 190, 2, // Skip to: 2594
/* 1892 */    MCD::OPC_Decode, 218, 4, 121, // Opcode: CVT_S_D_MMR6
/* 1896 */    MCD::OPC_FilterValue, 4, 7, 0, // Skip to: 1907
/* 1900 */    MCD::OPC_CheckPredicate, 13, 178, 2, // Skip to: 2594
/* 1904 */    MCD::OPC_Decode, 29, 111, // Opcode: ABS_D_MMR6
/* 1907 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 1919
/* 1911 */    MCD::OPC_CheckPredicate, 13, 167, 2, // Skip to: 2594
/* 1915 */    MCD::OPC_Decode, 207, 7, 111, // Opcode: FNEG_D_MMR6
/* 1919 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 1931
/* 1923 */    MCD::OPC_CheckPredicate, 13, 155, 2, // Skip to: 2594
/* 1927 */    MCD::OPC_Decode, 208, 4, 116, // Opcode: CVT_D_W_MMR6
/* 1931 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 1943
/* 1935 */    MCD::OPC_CheckPredicate, 13, 143, 2, // Skip to: 2594
/* 1939 */    MCD::OPC_Decode, 223, 4, 110, // Opcode: CVT_S_W_MMR6
/* 1943 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 1955
/* 1947 */    MCD::OPC_CheckPredicate, 14, 131, 2, // Skip to: 2594
/* 1951 */    MCD::OPC_Decode, 205, 4, 115, // Opcode: CVT_D_L_MMR6
/* 1955 */    MCD::OPC_FilterValue, 11, 123, 2, // Skip to: 2594
/* 1959 */    MCD::OPC_CheckPredicate, 14, 119, 2, // Skip to: 2594
/* 1963 */    MCD::OPC_Decode, 220, 4, 114, // Opcode: CVT_S_L_MMR6
/* 1967 */    MCD::OPC_FilterValue, 133, 7, 8, 0, // Skip to: 1980
/* 1972 */    MCD::OPC_CheckPredicate, 13, 106, 2, // Skip to: 2594
/* 1976 */    MCD::OPC_Decode, 149, 4, 106, // Opcode: CMP_SLE_S_MMR6
/* 1980 */    MCD::OPC_FilterValue, 149, 7, 8, 0, // Skip to: 1993
/* 1985 */    MCD::OPC_CheckPredicate, 13, 93, 2, // Skip to: 2594
/* 1989 */    MCD::OPC_Decode, 147, 4, 107, // Opcode: CMP_SLE_D_MMR6
/* 1993 */    MCD::OPC_FilterValue, 184, 7, 8, 0, // Skip to: 2006
/* 1998 */    MCD::OPC_CheckPredicate, 13, 80, 2, // Skip to: 2594
/* 2002 */    MCD::OPC_Decode, 244, 9, 122, // Opcode: MADDF_D_MMR6
/* 2006 */    MCD::OPC_FilterValue, 197, 7, 8, 0, // Skip to: 2019
/* 2011 */    MCD::OPC_CheckPredicate, 13, 67, 2, // Skip to: 2594
/* 2015 */    MCD::OPC_Decode, 161, 4, 106, // Opcode: CMP_SULE_S_MMR6
/* 2019 */    MCD::OPC_FilterValue, 213, 7, 8, 0, // Skip to: 2032
/* 2024 */    MCD::OPC_CheckPredicate, 13, 54, 2, // Skip to: 2594
/* 2028 */    MCD::OPC_Decode, 159, 4, 107, // Opcode: CMP_SULE_D_MMR6
/* 2032 */    MCD::OPC_FilterValue, 248, 7, 45, 2, // Skip to: 2594
/* 2037 */    MCD::OPC_CheckPredicate, 13, 41, 2, // Skip to: 2594
/* 2041 */    MCD::OPC_Decode, 155, 11, 122, // Opcode: MSUBF_D_MMR6
/* 2045 */    MCD::OPC_FilterValue, 22, 112, 0, // Skip to: 2161
/* 2049 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 2052 */    MCD::OPC_FilterValue, 20, 8, 0, // Skip to: 2064
/* 2056 */    MCD::OPC_CheckPredicate, 12, 22, 2, // Skip to: 2594
/* 2060 */    MCD::OPC_Decode, 182, 5, 123, // Opcode: DEXTU_MM64R6
/* 2064 */    MCD::OPC_FilterValue, 24, 51, 0, // Skip to: 2119
/* 2068 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 2071 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2083
/* 2075 */    MCD::OPC_CheckPredicate, 12, 3, 2, // Skip to: 2594
/* 2079 */    MCD::OPC_Decode, 175, 5, 124, // Opcode: DDIV_MM64R6
/* 2083 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2095
/* 2087 */    MCD::OPC_CheckPredicate, 12, 247, 1, // Skip to: 2594
/* 2091 */    MCD::OPC_Decode, 210, 5, 124, // Opcode: DMOD_MM64R6
/* 2095 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2107
/* 2099 */    MCD::OPC_CheckPredicate, 12, 235, 1, // Skip to: 2594
/* 2103 */    MCD::OPC_Decode, 174, 5, 124, // Opcode: DDIVU_MM64R6
/* 2107 */    MCD::OPC_FilterValue, 7, 227, 1, // Skip to: 2594
/* 2111 */    MCD::OPC_CheckPredicate, 12, 223, 1, // Skip to: 2594
/* 2115 */    MCD::OPC_Decode, 209, 5, 124, // Opcode: DMODU_MM64R6
/* 2119 */    MCD::OPC_FilterValue, 28, 14, 0, // Skip to: 2137
/* 2123 */    MCD::OPC_CheckPredicate, 12, 211, 1, // Skip to: 2594
/* 2127 */    MCD::OPC_CheckField, 6, 2, 0, 205, 1, // Skip to: 2594
/* 2133 */    MCD::OPC_Decode, 162, 5, 125, // Opcode: DALIGN_MM64R6
/* 2137 */    MCD::OPC_FilterValue, 36, 8, 0, // Skip to: 2149
/* 2141 */    MCD::OPC_CheckPredicate, 12, 193, 1, // Skip to: 2594
/* 2145 */    MCD::OPC_Decode, 180, 5, 123, // Opcode: DEXTM_MM64R6
/* 2149 */    MCD::OPC_FilterValue, 44, 185, 1, // Skip to: 2594
/* 2153 */    MCD::OPC_CheckPredicate, 12, 181, 1, // Skip to: 2594
/* 2157 */    MCD::OPC_Decode, 183, 5, 123, // Opcode: DEXT_MM64R6
/* 2161 */    MCD::OPC_FilterValue, 24, 149, 0, // Skip to: 2314
/* 2165 */    MCD::OPC_ExtractField, 12, 4,  // Inst{15-12} ...
/* 2168 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2180
/* 2172 */    MCD::OPC_CheckPredicate, 11, 162, 1, // Skip to: 2594
/* 2176 */    MCD::OPC_Decode, 239, 12, 81, // Opcode: PREF_MMR6
/* 2180 */    MCD::OPC_FilterValue, 6, 51, 0, // Skip to: 2235
/* 2184 */    MCD::OPC_ExtractField, 9, 3,  // Inst{11-9} ...
/* 2187 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2199
/* 2191 */    MCD::OPC_CheckPredicate, 11, 143, 1, // Skip to: 2594
/* 2195 */    MCD::OPC_Decode, 238, 8, 126, // Opcode: LBUE_MMR6
/* 2199 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2211
/* 2203 */    MCD::OPC_CheckPredicate, 11, 131, 1, // Skip to: 2594
/* 2207 */    MCD::OPC_Decode, 236, 8, 126, // Opcode: LBE_MMR6
/* 2211 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2223
/* 2215 */    MCD::OPC_CheckPredicate, 11, 119, 1, // Skip to: 2594
/* 2219 */    MCD::OPC_Decode, 164, 9, 87, // Opcode: LLE_MMR6
/* 2223 */    MCD::OPC_FilterValue, 7, 111, 1, // Skip to: 2594
/* 2227 */    MCD::OPC_CheckPredicate, 11, 107, 1, // Skip to: 2594
/* 2231 */    MCD::OPC_Decode, 194, 9, 87, // Opcode: LWE_MMR6
/* 2235 */    MCD::OPC_FilterValue, 10, 99, 1, // Skip to: 2594
/* 2239 */    MCD::OPC_ExtractField, 9, 3,  // Inst{11-9} ...
/* 2242 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 2254
/* 2246 */    MCD::OPC_CheckPredicate, 11, 88, 1, // Skip to: 2594
/* 2250 */    MCD::OPC_Decode, 236, 12, 88, // Opcode: PREFE_MMR6
/* 2254 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 2266
/* 2258 */    MCD::OPC_CheckPredicate, 11, 76, 1, // Skip to: 2594
/* 2262 */    MCD::OPC_Decode, 166, 3, 88, // Opcode: CACHEE_MMR6
/* 2266 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 2278
/* 2270 */    MCD::OPC_CheckPredicate, 11, 64, 1, // Skip to: 2594
/* 2274 */    MCD::OPC_Decode, 228, 13, 127, // Opcode: SBE_MMR6
/* 2278 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 2290
/* 2282 */    MCD::OPC_CheckPredicate, 11, 52, 1, // Skip to: 2594
/* 2286 */    MCD::OPC_Decode, 165, 14, 127, // Opcode: SHE_MMR6
/* 2290 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 2302
/* 2294 */    MCD::OPC_CheckPredicate, 11, 40, 1, // Skip to: 2594
/* 2298 */    MCD::OPC_Decode, 236, 13, 127, // Opcode: SCE_MMR6
/* 2302 */    MCD::OPC_FilterValue, 7, 32, 1, // Skip to: 2594
/* 2306 */    MCD::OPC_CheckPredicate, 11, 28, 1, // Skip to: 2594
/* 2310 */    MCD::OPC_Decode, 140, 16, 87, // Opcode: SWE_MMR6
/* 2314 */    MCD::OPC_FilterValue, 28, 8, 0, // Skip to: 2326
/* 2318 */    MCD::OPC_CheckPredicate, 11, 16, 1, // Skip to: 2594
/* 2322 */    MCD::OPC_Decode, 161, 17, 78, // Opcode: XORI_MMR6
/* 2326 */    MCD::OPC_FilterValue, 29, 15, 0, // Skip to: 2345
/* 2330 */    MCD::OPC_CheckPredicate, 11, 4, 1, // Skip to: 2594
/* 2334 */    MCD::OPC_CheckField, 16, 5, 0, 254, 0, // Skip to: 2594
/* 2340 */    MCD::OPC_Decode, 237, 1, 128, 1, // Opcode: BEQZALC_MMR6
/* 2345 */    MCD::OPC_FilterValue, 30, 60, 0, // Skip to: 2409
/* 2349 */    MCD::OPC_ExtractField, 19, 2,  // Inst{20-19} ...
/* 2352 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 2364
/* 2356 */    MCD::OPC_CheckPredicate, 11, 234, 0, // Skip to: 2594
/* 2360 */    MCD::OPC_Decode, 34, 129, 1, // Opcode: ADDIUPC_MMR6
/* 2364 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 2377
/* 2368 */    MCD::OPC_CheckPredicate, 11, 222, 0, // Skip to: 2594
/* 2372 */    MCD::OPC_Decode, 206, 9, 129, 1, // Opcode: LWPC_MMR6
/* 2377 */    MCD::OPC_FilterValue, 3, 213, 0, // Skip to: 2594
/* 2381 */    MCD::OPC_ExtractField, 16, 3,  // Inst{18-16} ...
/* 2384 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 2397
/* 2388 */    MCD::OPC_CheckPredicate, 11, 202, 0, // Skip to: 2594
/* 2392 */    MCD::OPC_Decode, 171, 1, 130, 1, // Opcode: AUIPC_MMR6
/* 2397 */    MCD::OPC_FilterValue, 7, 193, 0, // Skip to: 2594
/* 2401 */    MCD::OPC_CheckPredicate, 11, 189, 0, // Skip to: 2594
/* 2405 */    MCD::OPC_Decode, 110, 130, 1, // Opcode: ALUIPC_MMR6
/* 2409 */    MCD::OPC_FilterValue, 31, 15, 0, // Skip to: 2428
/* 2413 */    MCD::OPC_CheckPredicate, 11, 177, 0, // Skip to: 2594
/* 2417 */    MCD::OPC_CheckField, 16, 5, 0, 171, 0, // Skip to: 2594
/* 2423 */    MCD::OPC_Decode, 223, 2, 128, 1, // Opcode: BNEZALC_MMR6
/* 2428 */    MCD::OPC_FilterValue, 32, 14, 0, // Skip to: 2446
/* 2432 */    MCD::OPC_CheckPredicate, 11, 158, 0, // Skip to: 2594
/* 2436 */    MCD::OPC_CheckField, 21, 5, 0, 152, 0, // Skip to: 2594
/* 2442 */    MCD::OPC_Decode, 210, 8, 83, // Opcode: JIALC_MMR6
/* 2446 */    MCD::OPC_FilterValue, 37, 9, 0, // Skip to: 2459
/* 2450 */    MCD::OPC_CheckPredicate, 11, 140, 0, // Skip to: 2594
/* 2454 */    MCD::OPC_Decode, 230, 1, 131, 1, // Opcode: BC_MMR6
/* 2459 */    MCD::OPC_FilterValue, 40, 14, 0, // Skip to: 2477
/* 2463 */    MCD::OPC_CheckPredicate, 11, 127, 0, // Skip to: 2594
/* 2467 */    MCD::OPC_CheckField, 21, 5, 0, 121, 0, // Skip to: 2594
/* 2473 */    MCD::OPC_Decode, 212, 8, 83, // Opcode: JIC_MMR6
/* 2477 */    MCD::OPC_FilterValue, 45, 9, 0, // Skip to: 2490
/* 2481 */    MCD::OPC_CheckPredicate, 11, 109, 0, // Skip to: 2594
/* 2485 */    MCD::OPC_Decode, 203, 1, 131, 1, // Opcode: BALC_MMR6
/* 2490 */    MCD::OPC_FilterValue, 48, 24, 0, // Skip to: 2518
/* 2494 */    MCD::OPC_CheckPredicate, 11, 11, 0, // Skip to: 2509
/* 2498 */    MCD::OPC_CheckField, 16, 5, 0, 5, 0, // Skip to: 2509
/* 2504 */    MCD::OPC_Decode, 180, 2, 128, 1, // Opcode: BLEZALC_MMR6
/* 2509 */    MCD::OPC_CheckPredicate, 11, 81, 0, // Skip to: 2594
/* 2513 */    MCD::OPC_Decode, 128, 2, 132, 1, // Opcode: BGEZALC_MMR6
/* 2518 */    MCD::OPC_FilterValue, 52, 7, 0, // Skip to: 2529
/* 2522 */    MCD::OPC_CheckPredicate, 11, 68, 0, // Skip to: 2594
/* 2526 */    MCD::OPC_Decode, 118, 78, // Opcode: ANDI_MMR6
/* 2529 */    MCD::OPC_FilterValue, 56, 24, 0, // Skip to: 2557
/* 2533 */    MCD::OPC_CheckPredicate, 11, 11, 0, // Skip to: 2548
/* 2537 */    MCD::OPC_CheckField, 16, 5, 0, 5, 0, // Skip to: 2548
/* 2543 */    MCD::OPC_Decode, 146, 2, 128, 1, // Opcode: BGTZALC_MMR6
/* 2548 */    MCD::OPC_CheckPredicate, 11, 42, 0, // Skip to: 2594
/* 2552 */    MCD::OPC_Decode, 198, 2, 132, 1, // Opcode: BLTZALC_MMR6
/* 2557 */    MCD::OPC_FilterValue, 60, 9, 0, // Skip to: 2570
/* 2561 */    MCD::OPC_CheckPredicate, 12, 29, 0, // Skip to: 2594
/* 2565 */    MCD::OPC_Decode, 166, 5, 133, 1, // Opcode: DAUI_MM64R6
/* 2570 */    MCD::OPC_FilterValue, 62, 8, 0, // Skip to: 2582
/* 2574 */    MCD::OPC_CheckPredicate, 11, 16, 0, // Skip to: 2594
/* 2578 */    MCD::OPC_Decode, 161, 16, 79, // Opcode: SW_MMR6
/* 2582 */    MCD::OPC_FilterValue, 63, 8, 0, // Skip to: 2594
/* 2586 */    MCD::OPC_CheckPredicate, 11, 4, 0, // Skip to: 2594
/* 2590 */    MCD::OPC_Decode, 222, 9, 79, // Opcode: LW_MMR6
/* 2594 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableMips32[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 0, 203, 3, // Skip to: 978
/* 7 */       MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 10 */      MCD::OPC_FilterValue, 0, 55, 0, // Skip to: 69
/* 14 */      MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 17 */      MCD::OPC_FilterValue, 0, 207, 55, // Skip to: 14308
/* 21 */      MCD::OPC_ExtractField, 6, 15,  // Inst{20-6} ...
/* 24 */      MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 36
/* 28 */      MCD::OPC_CheckPredicate, 15, 28, 0, // Skip to: 60
/* 32 */      MCD::OPC_Decode, 185, 15, 0, // Opcode: SSNOP
/* 36 */      MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 48
/* 40 */      MCD::OPC_CheckPredicate, 15, 16, 0, // Skip to: 60
/* 44 */      MCD::OPC_Decode, 172, 6, 0, // Opcode: EHB
/* 48 */      MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 60
/* 52 */      MCD::OPC_CheckPredicate, 16, 4, 0, // Skip to: 60
/* 56 */      MCD::OPC_Decode, 181, 12, 0, // Opcode: PAUSE
/* 60 */      MCD::OPC_CheckPredicate, 1, 164, 55, // Skip to: 14308
/* 64 */      MCD::OPC_Decode, 225, 14, 134, 1, // Opcode: SLL
/* 69 */      MCD::OPC_FilterValue, 1, 41, 0, // Skip to: 114
/* 73 */      MCD::OPC_ExtractField, 16, 2,  // Inst{17-16} ...
/* 76 */      MCD::OPC_FilterValue, 0, 15, 0, // Skip to: 95
/* 80 */      MCD::OPC_CheckPredicate, 17, 144, 55, // Skip to: 14308
/* 84 */      MCD::OPC_CheckField, 6, 5, 0, 138, 55, // Skip to: 14308
/* 90 */      MCD::OPC_Decode, 244, 10, 135, 1, // Opcode: MOVF_I
/* 95 */      MCD::OPC_FilterValue, 1, 129, 55, // Skip to: 14308
/* 99 */      MCD::OPC_CheckPredicate, 17, 125, 55, // Skip to: 14308
/* 103 */     MCD::OPC_CheckField, 6, 5, 0, 119, 55, // Skip to: 14308
/* 109 */     MCD::OPC_Decode, 136, 11, 135, 1, // Opcode: MOVT_I
/* 114 */     MCD::OPC_FilterValue, 2, 29, 0, // Skip to: 147
/* 118 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 121 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 134
/* 125 */     MCD::OPC_CheckPredicate, 1, 99, 55, // Skip to: 14308
/* 129 */     MCD::OPC_Decode, 163, 15, 134, 1, // Opcode: SRL
/* 134 */     MCD::OPC_FilterValue, 1, 90, 55, // Skip to: 14308
/* 138 */     MCD::OPC_CheckPredicate, 16, 86, 55, // Skip to: 14308
/* 142 */     MCD::OPC_Decode, 193, 13, 134, 1, // Opcode: ROTR
/* 147 */     MCD::OPC_FilterValue, 3, 15, 0, // Skip to: 166
/* 151 */     MCD::OPC_CheckPredicate, 15, 73, 55, // Skip to: 14308
/* 155 */     MCD::OPC_CheckField, 21, 5, 0, 67, 55, // Skip to: 14308
/* 161 */     MCD::OPC_Decode, 143, 15, 134, 1, // Opcode: SRA
/* 166 */     MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 184
/* 170 */     MCD::OPC_CheckPredicate, 15, 54, 55, // Skip to: 14308
/* 174 */     MCD::OPC_CheckField, 6, 5, 0, 48, 55, // Skip to: 14308
/* 180 */     MCD::OPC_Decode, 234, 14, 41, // Opcode: SLLV
/* 184 */     MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 203
/* 188 */     MCD::OPC_CheckPredicate, 18, 36, 55, // Skip to: 14308
/* 192 */     MCD::OPC_CheckField, 8, 3, 0, 30, 55, // Skip to: 14308
/* 198 */     MCD::OPC_Decode, 174, 9, 136, 1, // Opcode: LSA
/* 203 */     MCD::OPC_FilterValue, 6, 27, 0, // Skip to: 234
/* 207 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 210 */     MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 222
/* 214 */     MCD::OPC_CheckPredicate, 15, 10, 55, // Skip to: 14308
/* 218 */     MCD::OPC_Decode, 178, 15, 41, // Opcode: SRLV
/* 222 */     MCD::OPC_FilterValue, 1, 2, 55, // Skip to: 14308
/* 226 */     MCD::OPC_CheckPredicate, 16, 254, 54, // Skip to: 14308
/* 230 */     MCD::OPC_Decode, 194, 13, 41, // Opcode: ROTRV
/* 234 */     MCD::OPC_FilterValue, 7, 14, 0, // Skip to: 252
/* 238 */     MCD::OPC_CheckPredicate, 15, 242, 54, // Skip to: 14308
/* 242 */     MCD::OPC_CheckField, 6, 5, 0, 236, 54, // Skip to: 14308
/* 248 */     MCD::OPC_Decode, 156, 15, 41, // Opcode: SRAV
/* 252 */     MCD::OPC_FilterValue, 8, 29, 0, // Skip to: 285
/* 256 */     MCD::OPC_ExtractField, 6, 15,  // Inst{20-6} ...
/* 259 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 272
/* 263 */     MCD::OPC_CheckPredicate, 15, 217, 54, // Skip to: 14308
/* 267 */     MCD::OPC_Decode, 213, 8, 137, 1, // Opcode: JR
/* 272 */     MCD::OPC_FilterValue, 16, 208, 54, // Skip to: 14308
/* 276 */     MCD::OPC_CheckPredicate, 19, 204, 54, // Skip to: 14308
/* 280 */     MCD::OPC_Decode, 220, 8, 137, 1, // Opcode: JR_HB
/* 285 */     MCD::OPC_FilterValue, 9, 39, 0, // Skip to: 328
/* 289 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 292 */     MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 310
/* 296 */     MCD::OPC_CheckPredicate, 1, 184, 54, // Skip to: 14308
/* 300 */     MCD::OPC_CheckField, 16, 5, 0, 178, 54, // Skip to: 14308
/* 306 */     MCD::OPC_Decode, 195, 8, 14, // Opcode: JALR
/* 310 */     MCD::OPC_FilterValue, 16, 170, 54, // Skip to: 14308
/* 314 */     MCD::OPC_CheckPredicate, 20, 166, 54, // Skip to: 14308
/* 318 */     MCD::OPC_CheckField, 16, 5, 0, 160, 54, // Skip to: 14308
/* 324 */     MCD::OPC_Decode, 203, 8, 14, // Opcode: JALR_HB
/* 328 */     MCD::OPC_FilterValue, 10, 15, 0, // Skip to: 347
/* 332 */     MCD::OPC_CheckPredicate, 21, 148, 54, // Skip to: 14308
/* 336 */     MCD::OPC_CheckField, 6, 5, 0, 142, 54, // Skip to: 14308
/* 342 */     MCD::OPC_Decode, 148, 11, 138, 1, // Opcode: MOVZ_I_I
/* 347 */     MCD::OPC_FilterValue, 11, 15, 0, // Skip to: 366
/* 351 */     MCD::OPC_CheckPredicate, 21, 129, 54, // Skip to: 14308
/* 355 */     MCD::OPC_CheckField, 6, 5, 0, 123, 54, // Skip to: 14308
/* 361 */     MCD::OPC_Decode, 128, 11, 138, 1, // Opcode: MOVN_I_I
/* 366 */     MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 379
/* 370 */     MCD::OPC_CheckPredicate, 15, 110, 54, // Skip to: 14308
/* 374 */     MCD::OPC_Decode, 167, 16, 139, 1, // Opcode: SYSCALL
/* 379 */     MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 391
/* 383 */     MCD::OPC_CheckPredicate, 1, 97, 54, // Skip to: 14308
/* 387 */     MCD::OPC_Decode, 237, 2, 42, // Opcode: BREAK
/* 391 */     MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 404
/* 395 */     MCD::OPC_CheckPredicate, 20, 85, 54, // Skip to: 14308
/* 399 */     MCD::OPC_Decode, 162, 16, 140, 1, // Opcode: SYNC
/* 404 */     MCD::OPC_FilterValue, 16, 45, 0, // Skip to: 453
/* 408 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 411 */     MCD::OPC_FilterValue, 0, 69, 54, // Skip to: 14308
/* 415 */     MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 418 */     MCD::OPC_FilterValue, 0, 62, 54, // Skip to: 14308
/* 422 */     MCD::OPC_ExtractField, 23, 3,  // Inst{25-23} ...
/* 425 */     MCD::OPC_FilterValue, 0, 55, 54, // Skip to: 14308
/* 429 */     MCD::OPC_CheckPredicate, 22, 11, 0, // Skip to: 444
/* 433 */     MCD::OPC_CheckField, 21, 2, 0, 5, 0, // Skip to: 444
/* 439 */     MCD::OPC_Decode, 182, 10, 141, 1, // Opcode: MFHI
/* 444 */     MCD::OPC_CheckPredicate, 23, 36, 54, // Skip to: 14308
/* 448 */     MCD::OPC_Decode, 185, 10, 142, 1, // Opcode: MFHI_DSP
/* 453 */     MCD::OPC_FilterValue, 17, 38, 0, // Skip to: 495
/* 457 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 460 */     MCD::OPC_FilterValue, 0, 20, 54, // Skip to: 14308
/* 464 */     MCD::OPC_ExtractField, 13, 8,  // Inst{20-13} ...
/* 467 */     MCD::OPC_FilterValue, 0, 13, 54, // Skip to: 14308
/* 471 */     MCD::OPC_CheckPredicate, 24, 11, 0, // Skip to: 486
/* 475 */     MCD::OPC_CheckField, 11, 2, 0, 5, 0, // Skip to: 486
/* 481 */     MCD::OPC_Decode, 185, 11, 137, 1, // Opcode: MTHI
/* 486 */     MCD::OPC_CheckPredicate, 23, 250, 53, // Skip to: 14308
/* 490 */     MCD::OPC_Decode, 187, 11, 143, 1, // Opcode: MTHI_DSP
/* 495 */     MCD::OPC_FilterValue, 18, 45, 0, // Skip to: 544
/* 499 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 502 */     MCD::OPC_FilterValue, 0, 234, 53, // Skip to: 14308
/* 506 */     MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 509 */     MCD::OPC_FilterValue, 0, 227, 53, // Skip to: 14308
/* 513 */     MCD::OPC_ExtractField, 23, 3,  // Inst{25-23} ...
/* 516 */     MCD::OPC_FilterValue, 0, 220, 53, // Skip to: 14308
/* 520 */     MCD::OPC_CheckPredicate, 22, 11, 0, // Skip to: 535
/* 524 */     MCD::OPC_CheckField, 21, 2, 0, 5, 0, // Skip to: 535
/* 530 */     MCD::OPC_Decode, 188, 10, 141, 1, // Opcode: MFLO
/* 535 */     MCD::OPC_CheckPredicate, 23, 201, 53, // Skip to: 14308
/* 539 */     MCD::OPC_Decode, 191, 10, 142, 1, // Opcode: MFLO_DSP
/* 544 */     MCD::OPC_FilterValue, 19, 38, 0, // Skip to: 586
/* 548 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 551 */     MCD::OPC_FilterValue, 0, 185, 53, // Skip to: 14308
/* 555 */     MCD::OPC_ExtractField, 13, 8,  // Inst{20-13} ...
/* 558 */     MCD::OPC_FilterValue, 0, 178, 53, // Skip to: 14308
/* 562 */     MCD::OPC_CheckPredicate, 24, 11, 0, // Skip to: 577
/* 566 */     MCD::OPC_CheckField, 11, 2, 0, 5, 0, // Skip to: 577
/* 572 */     MCD::OPC_Decode, 192, 11, 137, 1, // Opcode: MTLO
/* 577 */     MCD::OPC_CheckPredicate, 23, 159, 53, // Skip to: 14308
/* 581 */     MCD::OPC_Decode, 194, 11, 144, 1, // Opcode: MTLO_DSP
/* 586 */     MCD::OPC_FilterValue, 21, 15, 0, // Skip to: 605
/* 590 */     MCD::OPC_CheckPredicate, 25, 146, 53, // Skip to: 14308
/* 594 */     MCD::OPC_CheckField, 8, 3, 0, 140, 53, // Skip to: 14308
/* 600 */     MCD::OPC_Decode, 201, 5, 145, 1, // Opcode: DLSA
/* 605 */     MCD::OPC_FilterValue, 24, 37, 0, // Skip to: 646
/* 609 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 612 */     MCD::OPC_FilterValue, 0, 124, 53, // Skip to: 14308
/* 616 */     MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 619 */     MCD::OPC_FilterValue, 0, 117, 53, // Skip to: 14308
/* 623 */     MCD::OPC_CheckPredicate, 24, 10, 0, // Skip to: 637
/* 627 */     MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 637
/* 633 */     MCD::OPC_Decode, 228, 11, 61, // Opcode: MULT
/* 637 */     MCD::OPC_CheckPredicate, 23, 99, 53, // Skip to: 14308
/* 641 */     MCD::OPC_Decode, 231, 11, 146, 1, // Opcode: MULT_DSP
/* 646 */     MCD::OPC_FilterValue, 25, 37, 0, // Skip to: 687
/* 650 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 653 */     MCD::OPC_FilterValue, 0, 83, 53, // Skip to: 14308
/* 657 */     MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 660 */     MCD::OPC_FilterValue, 0, 76, 53, // Skip to: 14308
/* 664 */     MCD::OPC_CheckPredicate, 24, 10, 0, // Skip to: 678
/* 668 */     MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 678
/* 674 */     MCD::OPC_Decode, 234, 11, 61, // Opcode: MULTu
/* 678 */     MCD::OPC_CheckPredicate, 23, 58, 53, // Skip to: 14308
/* 682 */     MCD::OPC_Decode, 229, 11, 146, 1, // Opcode: MULTU_DSP
/* 687 */     MCD::OPC_FilterValue, 26, 14, 0, // Skip to: 705
/* 691 */     MCD::OPC_CheckPredicate, 24, 45, 53, // Skip to: 14308
/* 695 */     MCD::OPC_CheckField, 6, 10, 0, 39, 53, // Skip to: 14308
/* 701 */     MCD::OPC_Decode, 252, 13, 61, // Opcode: SDIV
/* 705 */     MCD::OPC_FilterValue, 27, 14, 0, // Skip to: 723
/* 709 */     MCD::OPC_CheckPredicate, 24, 27, 53, // Skip to: 14308
/* 713 */     MCD::OPC_CheckField, 6, 10, 0, 21, 53, // Skip to: 14308
/* 719 */     MCD::OPC_Decode, 135, 17, 61, // Opcode: UDIV
/* 723 */     MCD::OPC_FilterValue, 32, 13, 0, // Skip to: 740
/* 727 */     MCD::OPC_CheckPredicate, 15, 9, 53, // Skip to: 14308
/* 731 */     MCD::OPC_CheckField, 6, 5, 0, 3, 53, // Skip to: 14308
/* 737 */     MCD::OPC_Decode, 31, 47, // Opcode: ADD
/* 740 */     MCD::OPC_FilterValue, 33, 13, 0, // Skip to: 757
/* 744 */     MCD::OPC_CheckPredicate, 1, 248, 52, // Skip to: 14308
/* 748 */     MCD::OPC_CheckField, 6, 5, 0, 242, 52, // Skip to: 14308
/* 754 */     MCD::OPC_Decode, 103, 47, // Opcode: ADDu
/* 757 */     MCD::OPC_FilterValue, 34, 14, 0, // Skip to: 775
/* 761 */     MCD::OPC_CheckPredicate, 15, 231, 52, // Skip to: 14308
/* 765 */     MCD::OPC_CheckField, 6, 5, 0, 225, 52, // Skip to: 14308
/* 771 */     MCD::OPC_Decode, 196, 15, 47, // Opcode: SUB
/* 775 */     MCD::OPC_FilterValue, 35, 14, 0, // Skip to: 793
/* 779 */     MCD::OPC_CheckPredicate, 1, 213, 52, // Skip to: 14308
/* 783 */     MCD::OPC_CheckField, 6, 5, 0, 207, 52, // Skip to: 14308
/* 789 */     MCD::OPC_Decode, 252, 15, 47, // Opcode: SUBu
/* 793 */     MCD::OPC_FilterValue, 36, 13, 0, // Skip to: 810
/* 797 */     MCD::OPC_CheckPredicate, 1, 195, 52, // Skip to: 14308
/* 801 */     MCD::OPC_CheckField, 6, 5, 0, 189, 52, // Skip to: 14308
/* 807 */     MCD::OPC_Decode, 111, 47, // Opcode: AND
/* 810 */     MCD::OPC_FilterValue, 37, 14, 0, // Skip to: 828
/* 814 */     MCD::OPC_CheckPredicate, 1, 178, 52, // Skip to: 14308
/* 818 */     MCD::OPC_CheckField, 6, 5, 0, 172, 52, // Skip to: 14308
/* 824 */     MCD::OPC_Decode, 164, 12, 47, // Opcode: OR
/* 828 */     MCD::OPC_FilterValue, 38, 14, 0, // Skip to: 846
/* 832 */     MCD::OPC_CheckPredicate, 1, 160, 52, // Skip to: 14308
/* 836 */     MCD::OPC_CheckField, 6, 5, 0, 154, 52, // Skip to: 14308
/* 842 */     MCD::OPC_Decode, 156, 17, 47, // Opcode: XOR
/* 846 */     MCD::OPC_FilterValue, 39, 14, 0, // Skip to: 864
/* 850 */     MCD::OPC_CheckPredicate, 15, 142, 52, // Skip to: 14308
/* 854 */     MCD::OPC_CheckField, 6, 5, 0, 136, 52, // Skip to: 14308
/* 860 */     MCD::OPC_Decode, 150, 12, 47, // Opcode: NOR
/* 864 */     MCD::OPC_FilterValue, 42, 14, 0, // Skip to: 882
/* 868 */     MCD::OPC_CheckPredicate, 15, 124, 52, // Skip to: 14308
/* 872 */     MCD::OPC_CheckField, 6, 5, 0, 118, 52, // Skip to: 14308
/* 878 */     MCD::OPC_Decode, 242, 14, 47, // Opcode: SLT
/* 882 */     MCD::OPC_FilterValue, 43, 14, 0, // Skip to: 900
/* 886 */     MCD::OPC_CheckPredicate, 15, 106, 52, // Skip to: 14308
/* 890 */     MCD::OPC_CheckField, 6, 5, 0, 100, 52, // Skip to: 14308
/* 896 */     MCD::OPC_Decode, 251, 14, 47, // Opcode: SLTu
/* 900 */     MCD::OPC_FilterValue, 48, 9, 0, // Skip to: 913
/* 904 */     MCD::OPC_CheckPredicate, 2, 88, 52, // Skip to: 14308
/* 908 */     MCD::OPC_Decode, 221, 16, 147, 1, // Opcode: TGE
/* 913 */     MCD::OPC_FilterValue, 49, 9, 0, // Skip to: 926
/* 917 */     MCD::OPC_CheckPredicate, 2, 75, 52, // Skip to: 14308
/* 921 */     MCD::OPC_Decode, 226, 16, 147, 1, // Opcode: TGEU
/* 926 */     MCD::OPC_FilterValue, 50, 9, 0, // Skip to: 939
/* 930 */     MCD::OPC_CheckPredicate, 2, 62, 52, // Skip to: 14308
/* 934 */     MCD::OPC_Decode, 239, 16, 147, 1, // Opcode: TLT
/* 939 */     MCD::OPC_FilterValue, 51, 9, 0, // Skip to: 952
/* 943 */     MCD::OPC_CheckPredicate, 2, 49, 52, // Skip to: 14308
/* 947 */     MCD::OPC_Decode, 243, 16, 147, 1, // Opcode: TLTU
/* 952 */     MCD::OPC_FilterValue, 52, 9, 0, // Skip to: 965
/* 956 */     MCD::OPC_CheckPredicate, 2, 36, 52, // Skip to: 14308
/* 960 */     MCD::OPC_Decode, 217, 16, 147, 1, // Opcode: TEQ
/* 965 */     MCD::OPC_FilterValue, 54, 27, 52, // Skip to: 14308
/* 969 */     MCD::OPC_CheckPredicate, 2, 23, 52, // Skip to: 14308
/* 973 */     MCD::OPC_Decode, 246, 16, 147, 1, // Opcode: TNE
/* 978 */     MCD::OPC_FilterValue, 1, 211, 0, // Skip to: 1193
/* 982 */     MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 985 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 998
/* 989 */     MCD::OPC_CheckPredicate, 15, 3, 52, // Skip to: 14308
/* 993 */     MCD::OPC_Decode, 194, 2, 148, 1, // Opcode: BLTZ
/* 998 */     MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 1011
/* 1002 */    MCD::OPC_CheckPredicate, 15, 246, 51, // Skip to: 14308
/* 1006 */    MCD::OPC_Decode, 252, 1, 148, 1, // Opcode: BGEZ
/* 1011 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 1024
/* 1015 */    MCD::OPC_CheckPredicate, 26, 233, 51, // Skip to: 14308
/* 1019 */    MCD::OPC_Decode, 203, 2, 148, 1, // Opcode: BLTZL
/* 1024 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 1037
/* 1028 */    MCD::OPC_CheckPredicate, 26, 220, 51, // Skip to: 14308
/* 1032 */    MCD::OPC_Decode, 133, 2, 148, 1, // Opcode: BGEZL
/* 1037 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 1049
/* 1041 */    MCD::OPC_CheckPredicate, 26, 207, 51, // Skip to: 14308
/* 1045 */    MCD::OPC_Decode, 222, 16, 101, // Opcode: TGEI
/* 1049 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 1061
/* 1053 */    MCD::OPC_CheckPredicate, 26, 195, 51, // Skip to: 14308
/* 1057 */    MCD::OPC_Decode, 223, 16, 101, // Opcode: TGEIU
/* 1061 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 1073
/* 1065 */    MCD::OPC_CheckPredicate, 26, 183, 51, // Skip to: 14308
/* 1069 */    MCD::OPC_Decode, 240, 16, 101, // Opcode: TLTI
/* 1073 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 1085
/* 1077 */    MCD::OPC_CheckPredicate, 26, 171, 51, // Skip to: 14308
/* 1081 */    MCD::OPC_Decode, 134, 17, 101, // Opcode: TTLTIU
/* 1085 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 1097
/* 1089 */    MCD::OPC_CheckPredicate, 26, 159, 51, // Skip to: 14308
/* 1093 */    MCD::OPC_Decode, 218, 16, 101, // Opcode: TEQI
/* 1097 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 1109
/* 1101 */    MCD::OPC_CheckPredicate, 26, 147, 51, // Skip to: 14308
/* 1105 */    MCD::OPC_Decode, 247, 16, 101, // Opcode: TNEI
/* 1109 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 1122
/* 1113 */    MCD::OPC_CheckPredicate, 24, 135, 51, // Skip to: 14308
/* 1117 */    MCD::OPC_Decode, 196, 2, 148, 1, // Opcode: BLTZAL
/* 1122 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 1135
/* 1126 */    MCD::OPC_CheckPredicate, 24, 122, 51, // Skip to: 14308
/* 1130 */    MCD::OPC_Decode, 254, 1, 148, 1, // Opcode: BGEZAL
/* 1135 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 1148
/* 1139 */    MCD::OPC_CheckPredicate, 26, 109, 51, // Skip to: 14308
/* 1143 */    MCD::OPC_Decode, 199, 2, 148, 1, // Opcode: BLTZALL
/* 1148 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 1161
/* 1152 */    MCD::OPC_CheckPredicate, 26, 96, 51, // Skip to: 14308
/* 1156 */    MCD::OPC_Decode, 129, 2, 148, 1, // Opcode: BGEZALL
/* 1161 */    MCD::OPC_FilterValue, 28, 15, 0, // Skip to: 1180
/* 1165 */    MCD::OPC_CheckPredicate, 23, 83, 51, // Skip to: 14308
/* 1169 */    MCD::OPC_CheckField, 21, 5, 0, 77, 51, // Skip to: 14308
/* 1175 */    MCD::OPC_Decode, 235, 2, 149, 1, // Opcode: BPOSGE32
/* 1180 */    MCD::OPC_FilterValue, 31, 68, 51, // Skip to: 14308
/* 1184 */    MCD::OPC_CheckPredicate, 16, 64, 51, // Skip to: 14308
/* 1188 */    MCD::OPC_Decode, 163, 16, 150, 1, // Opcode: SYNCI
/* 1193 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 1206
/* 1197 */    MCD::OPC_CheckPredicate, 15, 51, 51, // Skip to: 14308
/* 1201 */    MCD::OPC_Decode, 193, 8, 151, 1, // Opcode: J
/* 1206 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 1219
/* 1210 */    MCD::OPC_CheckPredicate, 15, 38, 51, // Skip to: 14308
/* 1214 */    MCD::OPC_Decode, 194, 8, 151, 1, // Opcode: JAL
/* 1219 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 1232
/* 1223 */    MCD::OPC_CheckPredicate, 15, 25, 51, // Skip to: 14308
/* 1227 */    MCD::OPC_Decode, 231, 1, 152, 1, // Opcode: BEQ
/* 1232 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 1245
/* 1236 */    MCD::OPC_CheckPredicate, 15, 12, 51, // Skip to: 14308
/* 1240 */    MCD::OPC_Decode, 209, 2, 152, 1, // Opcode: BNE
/* 1245 */    MCD::OPC_FilterValue, 6, 15, 0, // Skip to: 1264
/* 1249 */    MCD::OPC_CheckPredicate, 15, 255, 50, // Skip to: 14308
/* 1253 */    MCD::OPC_CheckField, 16, 5, 0, 249, 50, // Skip to: 14308
/* 1259 */    MCD::OPC_Decode, 177, 2, 148, 1, // Opcode: BLEZ
/* 1264 */    MCD::OPC_FilterValue, 7, 15, 0, // Skip to: 1283
/* 1268 */    MCD::OPC_CheckPredicate, 15, 236, 50, // Skip to: 14308
/* 1272 */    MCD::OPC_CheckField, 16, 5, 0, 230, 50, // Skip to: 14308
/* 1278 */    MCD::OPC_Decode, 143, 2, 148, 1, // Opcode: BGTZ
/* 1283 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 1295
/* 1287 */    MCD::OPC_CheckPredicate, 24, 217, 50, // Skip to: 14308
/* 1291 */    MCD::OPC_Decode, 99, 153, 1, // Opcode: ADDi
/* 1295 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 1307
/* 1299 */    MCD::OPC_CheckPredicate, 1, 205, 50, // Skip to: 14308
/* 1303 */    MCD::OPC_Decode, 101, 153, 1, // Opcode: ADDiu
/* 1307 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 1320
/* 1311 */    MCD::OPC_CheckPredicate, 15, 193, 50, // Skip to: 14308
/* 1315 */    MCD::OPC_Decode, 245, 14, 153, 1, // Opcode: SLTi
/* 1320 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 1333
/* 1324 */    MCD::OPC_CheckPredicate, 15, 180, 50, // Skip to: 14308
/* 1328 */    MCD::OPC_Decode, 248, 14, 153, 1, // Opcode: SLTiu
/* 1333 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 1345
/* 1337 */    MCD::OPC_CheckPredicate, 1, 167, 50, // Skip to: 14308
/* 1341 */    MCD::OPC_Decode, 125, 154, 1, // Opcode: ANDi
/* 1345 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 1358
/* 1349 */    MCD::OPC_CheckPredicate, 15, 155, 50, // Skip to: 14308
/* 1353 */    MCD::OPC_Decode, 176, 12, 154, 1, // Opcode: ORi
/* 1358 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 1371
/* 1362 */    MCD::OPC_CheckPredicate, 15, 142, 50, // Skip to: 14308
/* 1366 */    MCD::OPC_Decode, 168, 17, 154, 1, // Opcode: XORi
/* 1371 */    MCD::OPC_FilterValue, 15, 14, 0, // Skip to: 1389
/* 1375 */    MCD::OPC_CheckPredicate, 15, 129, 50, // Skip to: 14308
/* 1379 */    MCD::OPC_CheckField, 21, 5, 0, 123, 50, // Skip to: 14308
/* 1385 */    MCD::OPC_Decode, 181, 9, 83, // Opcode: LUi
/* 1389 */    MCD::OPC_FilterValue, 16, 56, 1, // Skip to: 1705
/* 1393 */    MCD::OPC_ExtractField, 3, 8,  // Inst{10-3} ...
/* 1396 */    MCD::OPC_FilterValue, 0, 150, 0, // Skip to: 1550
/* 1400 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 1403 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 1416
/* 1407 */    MCD::OPC_CheckPredicate, 20, 97, 50, // Skip to: 14308
/* 1411 */    MCD::OPC_Decode, 175, 10, 155, 1, // Opcode: MFC0
/* 1416 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 1429
/* 1420 */    MCD::OPC_CheckPredicate, 20, 84, 50, // Skip to: 14308
/* 1424 */    MCD::OPC_Decode, 178, 11, 156, 1, // Opcode: MTC0
/* 1429 */    MCD::OPC_FilterValue, 11, 20, 0, // Skip to: 1453
/* 1433 */    MCD::OPC_CheckPredicate, 16, 71, 50, // Skip to: 14308
/* 1437 */    MCD::OPC_CheckField, 11, 5, 12, 65, 50, // Skip to: 14308
/* 1443 */    MCD::OPC_CheckField, 0, 3, 0, 59, 50, // Skip to: 14308
/* 1449 */    MCD::OPC_Decode, 184, 5, 71, // Opcode: DI
/* 1453 */    MCD::OPC_FilterValue, 16, 51, 50, // Skip to: 14308
/* 1457 */    MCD::OPC_ExtractField, 0, 3,  // Inst{2-0} ...
/* 1460 */    MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 1478
/* 1464 */    MCD::OPC_CheckPredicate, 15, 40, 50, // Skip to: 14308
/* 1468 */    MCD::OPC_CheckField, 11, 10, 0, 34, 50, // Skip to: 14308
/* 1474 */    MCD::OPC_Decode, 233, 16, 0, // Opcode: TLBR
/* 1478 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 1496
/* 1482 */    MCD::OPC_CheckPredicate, 15, 22, 50, // Skip to: 14308
/* 1486 */    MCD::OPC_CheckField, 11, 10, 0, 16, 50, // Skip to: 14308
/* 1492 */    MCD::OPC_Decode, 235, 16, 0, // Opcode: TLBWI
/* 1496 */    MCD::OPC_FilterValue, 3, 14, 0, // Skip to: 1514
/* 1500 */    MCD::OPC_CheckPredicate, 27, 4, 50, // Skip to: 14308
/* 1504 */    MCD::OPC_CheckField, 11, 10, 0, 254, 49, // Skip to: 14308
/* 1510 */    MCD::OPC_Decode, 229, 16, 0, // Opcode: TLBINV
/* 1514 */    MCD::OPC_FilterValue, 4, 14, 0, // Skip to: 1532
/* 1518 */    MCD::OPC_CheckPredicate, 27, 242, 49, // Skip to: 14308
/* 1522 */    MCD::OPC_CheckField, 11, 10, 0, 236, 49, // Skip to: 14308
/* 1528 */    MCD::OPC_Decode, 230, 16, 0, // Opcode: TLBINVF
/* 1532 */    MCD::OPC_FilterValue, 6, 228, 49, // Skip to: 14308
/* 1536 */    MCD::OPC_CheckPredicate, 15, 224, 49, // Skip to: 14308
/* 1540 */    MCD::OPC_CheckField, 11, 10, 0, 218, 49, // Skip to: 14308
/* 1546 */    MCD::OPC_Decode, 237, 16, 0, // Opcode: TLBWR
/* 1550 */    MCD::OPC_FilterValue, 1, 22, 0, // Skip to: 1576
/* 1554 */    MCD::OPC_CheckPredicate, 15, 206, 49, // Skip to: 14308
/* 1558 */    MCD::OPC_CheckField, 11, 15, 128, 128, 1, 198, 49, // Skip to: 14308
/* 1566 */    MCD::OPC_CheckField, 0, 3, 0, 192, 49, // Skip to: 14308
/* 1572 */    MCD::OPC_Decode, 231, 16, 0, // Opcode: TLBP
/* 1576 */    MCD::OPC_FilterValue, 3, 43, 0, // Skip to: 1623
/* 1580 */    MCD::OPC_ExtractField, 0, 3,  // Inst{2-0} ...
/* 1583 */    MCD::OPC_FilterValue, 0, 16, 0, // Skip to: 1603
/* 1587 */    MCD::OPC_CheckPredicate, 28, 173, 49, // Skip to: 14308
/* 1591 */    MCD::OPC_CheckField, 11, 15, 128, 128, 1, 165, 49, // Skip to: 14308
/* 1599 */    MCD::OPC_Decode, 178, 6, 0, // Opcode: ERET
/* 1603 */    MCD::OPC_FilterValue, 7, 157, 49, // Skip to: 14308
/* 1607 */    MCD::OPC_CheckPredicate, 20, 153, 49, // Skip to: 14308
/* 1611 */    MCD::OPC_CheckField, 11, 15, 128, 128, 1, 145, 49, // Skip to: 14308
/* 1619 */    MCD::OPC_Decode, 176, 5, 0, // Opcode: DERET
/* 1623 */    MCD::OPC_FilterValue, 4, 52, 0, // Skip to: 1679
/* 1627 */    MCD::OPC_ExtractField, 11, 5,  // Inst{15-11} ...
/* 1630 */    MCD::OPC_FilterValue, 0, 21, 0, // Skip to: 1655
/* 1634 */    MCD::OPC_CheckPredicate, 29, 126, 49, // Skip to: 14308
/* 1638 */    MCD::OPC_CheckField, 16, 10, 128, 4, 119, 49, // Skip to: 14308
/* 1645 */    MCD::OPC_CheckField, 0, 3, 0, 113, 49, // Skip to: 14308
/* 1651 */    MCD::OPC_Decode, 148, 17, 0, // Opcode: WAIT
/* 1655 */    MCD::OPC_FilterValue, 12, 105, 49, // Skip to: 14308
/* 1659 */    MCD::OPC_CheckPredicate, 30, 101, 49, // Skip to: 14308
/* 1663 */    MCD::OPC_CheckField, 21, 5, 11, 95, 49, // Skip to: 14308
/* 1669 */    MCD::OPC_CheckField, 0, 3, 0, 89, 49, // Skip to: 14308
/* 1675 */    MCD::OPC_Decode, 175, 6, 71, // Opcode: EI
/* 1679 */    MCD::OPC_FilterValue, 11, 81, 49, // Skip to: 14308
/* 1683 */    MCD::OPC_CheckPredicate, 31, 77, 49, // Skip to: 14308
/* 1687 */    MCD::OPC_CheckField, 11, 15, 128, 128, 1, 69, 49, // Skip to: 14308
/* 1695 */    MCD::OPC_CheckField, 0, 3, 0, 63, 49, // Skip to: 14308
/* 1701 */    MCD::OPC_Decode, 179, 6, 0, // Opcode: ERETNC
/* 1705 */    MCD::OPC_FilterValue, 17, 115, 6, // Skip to: 3360
/* 1709 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 1712 */    MCD::OPC_FilterValue, 0, 15, 0, // Skip to: 1731
/* 1716 */    MCD::OPC_CheckPredicate, 32, 44, 49, // Skip to: 14308
/* 1720 */    MCD::OPC_CheckField, 0, 11, 0, 38, 49, // Skip to: 14308
/* 1726 */    MCD::OPC_Decode, 176, 10, 157, 1, // Opcode: MFC1
/* 1731 */    MCD::OPC_FilterValue, 1, 15, 0, // Skip to: 1750
/* 1735 */    MCD::OPC_CheckPredicate, 33, 25, 49, // Skip to: 14308
/* 1739 */    MCD::OPC_CheckField, 0, 11, 0, 19, 49, // Skip to: 14308
/* 1745 */    MCD::OPC_Decode, 204, 5, 158, 1, // Opcode: DMFC1
/* 1750 */    MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 1769
/* 1754 */    MCD::OPC_CheckPredicate, 32, 6, 49, // Skip to: 14308
/* 1758 */    MCD::OPC_CheckField, 0, 11, 0, 0, 49, // Skip to: 14308
/* 1764 */    MCD::OPC_Decode, 189, 3, 159, 1, // Opcode: CFC1
/* 1769 */    MCD::OPC_FilterValue, 3, 15, 0, // Skip to: 1788
/* 1773 */    MCD::OPC_CheckPredicate, 34, 243, 48, // Skip to: 14308
/* 1777 */    MCD::OPC_CheckField, 0, 11, 0, 237, 48, // Skip to: 14308
/* 1783 */    MCD::OPC_Decode, 179, 10, 160, 1, // Opcode: MFHC1_D32
/* 1788 */    MCD::OPC_FilterValue, 4, 15, 0, // Skip to: 1807
/* 1792 */    MCD::OPC_CheckPredicate, 32, 224, 48, // Skip to: 14308
/* 1796 */    MCD::OPC_CheckField, 0, 11, 0, 218, 48, // Skip to: 14308
/* 1802 */    MCD::OPC_Decode, 179, 11, 161, 1, // Opcode: MTC1
/* 1807 */    MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 1826
/* 1811 */    MCD::OPC_CheckPredicate, 33, 205, 48, // Skip to: 14308
/* 1815 */    MCD::OPC_CheckField, 0, 11, 0, 199, 48, // Skip to: 14308
/* 1821 */    MCD::OPC_Decode, 212, 5, 162, 1, // Opcode: DMTC1
/* 1826 */    MCD::OPC_FilterValue, 6, 15, 0, // Skip to: 1845
/* 1830 */    MCD::OPC_CheckPredicate, 32, 186, 48, // Skip to: 14308
/* 1834 */    MCD::OPC_CheckField, 0, 11, 0, 180, 48, // Skip to: 14308
/* 1840 */    MCD::OPC_Decode, 196, 4, 163, 1, // Opcode: CTC1
/* 1845 */    MCD::OPC_FilterValue, 7, 15, 0, // Skip to: 1864
/* 1849 */    MCD::OPC_CheckPredicate, 34, 167, 48, // Skip to: 14308
/* 1853 */    MCD::OPC_CheckField, 0, 11, 0, 161, 48, // Skip to: 14308
/* 1859 */    MCD::OPC_Decode, 182, 11, 164, 1, // Opcode: MTHC1_D32
/* 1864 */    MCD::OPC_FilterValue, 8, 55, 0, // Skip to: 1923
/* 1868 */    MCD::OPC_ExtractField, 16, 2,  // Inst{17-16} ...
/* 1871 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 1884
/* 1875 */    MCD::OPC_CheckPredicate, 35, 141, 48, // Skip to: 14308
/* 1879 */    MCD::OPC_Decode, 213, 1, 165, 1, // Opcode: BC1F
/* 1884 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 1897
/* 1888 */    MCD::OPC_CheckPredicate, 35, 128, 48, // Skip to: 14308
/* 1892 */    MCD::OPC_Decode, 217, 1, 165, 1, // Opcode: BC1T
/* 1897 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 1910
/* 1901 */    MCD::OPC_CheckPredicate, 36, 115, 48, // Skip to: 14308
/* 1905 */    MCD::OPC_Decode, 214, 1, 165, 1, // Opcode: BC1FL
/* 1910 */    MCD::OPC_FilterValue, 3, 106, 48, // Skip to: 14308
/* 1914 */    MCD::OPC_CheckPredicate, 36, 102, 48, // Skip to: 14308
/* 1918 */    MCD::OPC_Decode, 218, 1, 165, 1, // Opcode: BC1TL
/* 1923 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 1936
/* 1927 */    MCD::OPC_CheckPredicate, 18, 89, 48, // Skip to: 14308
/* 1931 */    MCD::OPC_Decode, 132, 3, 166, 1, // Opcode: BZ_V
/* 1936 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 1949
/* 1940 */    MCD::OPC_CheckPredicate, 18, 76, 48, // Skip to: 14308
/* 1944 */    MCD::OPC_Decode, 232, 2, 166, 1, // Opcode: BNZ_V
/* 1949 */    MCD::OPC_FilterValue, 16, 115, 2, // Skip to: 2580
/* 1953 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 1956 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 1969
/* 1960 */    MCD::OPC_CheckPredicate, 32, 56, 48, // Skip to: 14308
/* 1964 */    MCD::OPC_Decode, 226, 6, 167, 1, // Opcode: FADD_S
/* 1969 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 1982
/* 1973 */    MCD::OPC_CheckPredicate, 32, 43, 48, // Skip to: 14308
/* 1977 */    MCD::OPC_Decode, 242, 7, 167, 1, // Opcode: FSUB_S
/* 1982 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 1995
/* 1986 */    MCD::OPC_CheckPredicate, 32, 30, 48, // Skip to: 14308
/* 1990 */    MCD::OPC_Decode, 201, 7, 167, 1, // Opcode: FMUL_S
/* 1995 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 2008
/* 1999 */    MCD::OPC_CheckPredicate, 32, 17, 48, // Skip to: 14308
/* 2003 */    MCD::OPC_Decode, 136, 7, 167, 1, // Opcode: FDIV_S
/* 2008 */    MCD::OPC_FilterValue, 4, 15, 0, // Skip to: 2027
/* 2012 */    MCD::OPC_CheckPredicate, 37, 4, 48, // Skip to: 14308
/* 2016 */    MCD::OPC_CheckField, 16, 5, 0, 254, 47, // Skip to: 14308
/* 2022 */    MCD::OPC_Decode, 234, 7, 168, 1, // Opcode: FSQRT_S
/* 2027 */    MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 2046
/* 2031 */    MCD::OPC_CheckPredicate, 32, 241, 47, // Skip to: 14308
/* 2035 */    MCD::OPC_CheckField, 16, 5, 0, 235, 47, // Skip to: 14308
/* 2041 */    MCD::OPC_Decode, 218, 6, 168, 1, // Opcode: FABS_S
/* 2046 */    MCD::OPC_FilterValue, 6, 15, 0, // Skip to: 2065
/* 2050 */    MCD::OPC_CheckPredicate, 32, 222, 47, // Skip to: 14308
/* 2054 */    MCD::OPC_CheckField, 16, 5, 0, 216, 47, // Skip to: 14308
/* 2060 */    MCD::OPC_Decode, 191, 7, 168, 1, // Opcode: FMOV_S
/* 2065 */    MCD::OPC_FilterValue, 7, 15, 0, // Skip to: 2084
/* 2069 */    MCD::OPC_CheckPredicate, 32, 203, 47, // Skip to: 14308
/* 2073 */    MCD::OPC_CheckField, 16, 5, 0, 197, 47, // Skip to: 14308
/* 2079 */    MCD::OPC_Decode, 209, 7, 168, 1, // Opcode: FNEG_S
/* 2084 */    MCD::OPC_FilterValue, 12, 15, 0, // Skip to: 2103
/* 2088 */    MCD::OPC_CheckPredicate, 37, 184, 47, // Skip to: 14308
/* 2092 */    MCD::OPC_CheckField, 16, 5, 0, 178, 47, // Skip to: 14308
/* 2098 */    MCD::OPC_Decode, 205, 13, 168, 1, // Opcode: ROUND_W_S
/* 2103 */    MCD::OPC_FilterValue, 13, 15, 0, // Skip to: 2122
/* 2107 */    MCD::OPC_CheckPredicate, 37, 165, 47, // Skip to: 14308
/* 2111 */    MCD::OPC_CheckField, 16, 5, 0, 159, 47, // Skip to: 14308
/* 2117 */    MCD::OPC_Decode, 131, 17, 168, 1, // Opcode: TRUNC_W_S
/* 2122 */    MCD::OPC_FilterValue, 14, 15, 0, // Skip to: 2141
/* 2126 */    MCD::OPC_CheckPredicate, 37, 146, 47, // Skip to: 14308
/* 2130 */    MCD::OPC_CheckField, 16, 5, 0, 140, 47, // Skip to: 14308
/* 2136 */    MCD::OPC_Decode, 178, 3, 168, 1, // Opcode: CEIL_W_S
/* 2141 */    MCD::OPC_FilterValue, 15, 15, 0, // Skip to: 2160
/* 2145 */    MCD::OPC_CheckPredicate, 37, 127, 47, // Skip to: 14308
/* 2149 */    MCD::OPC_CheckField, 16, 5, 0, 121, 47, // Skip to: 14308
/* 2155 */    MCD::OPC_Decode, 174, 7, 168, 1, // Opcode: FLOOR_W_S
/* 2160 */    MCD::OPC_FilterValue, 17, 29, 0, // Skip to: 2193
/* 2164 */    MCD::OPC_ExtractField, 16, 2,  // Inst{17-16} ...
/* 2167 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 2180
/* 2171 */    MCD::OPC_CheckPredicate, 17, 101, 47, // Skip to: 14308
/* 2175 */    MCD::OPC_Decode, 247, 10, 169, 1, // Opcode: MOVF_S
/* 2180 */    MCD::OPC_FilterValue, 1, 92, 47, // Skip to: 14308
/* 2184 */    MCD::OPC_CheckPredicate, 17, 88, 47, // Skip to: 14308
/* 2188 */    MCD::OPC_Decode, 139, 11, 169, 1, // Opcode: MOVT_S
/* 2193 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 2206
/* 2197 */    MCD::OPC_CheckPredicate, 17, 75, 47, // Skip to: 14308
/* 2201 */    MCD::OPC_Decode, 151, 11, 170, 1, // Opcode: MOVZ_I_S
/* 2206 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 2219
/* 2210 */    MCD::OPC_CheckPredicate, 17, 62, 47, // Skip to: 14308
/* 2214 */    MCD::OPC_Decode, 131, 11, 170, 1, // Opcode: MOVN_I_S
/* 2219 */    MCD::OPC_FilterValue, 33, 15, 0, // Skip to: 2238
/* 2223 */    MCD::OPC_CheckPredicate, 38, 49, 47, // Skip to: 14308
/* 2227 */    MCD::OPC_CheckField, 16, 5, 0, 43, 47, // Skip to: 14308
/* 2233 */    MCD::OPC_Decode, 199, 4, 171, 1, // Opcode: CVT_D32_S
/* 2238 */    MCD::OPC_FilterValue, 36, 15, 0, // Skip to: 2257
/* 2242 */    MCD::OPC_CheckPredicate, 32, 30, 47, // Skip to: 14308
/* 2246 */    MCD::OPC_CheckField, 16, 5, 0, 24, 47, // Skip to: 14308
/* 2252 */    MCD::OPC_Decode, 228, 4, 168, 1, // Opcode: CVT_W_S
/* 2257 */    MCD::OPC_FilterValue, 37, 15, 0, // Skip to: 2276
/* 2261 */    MCD::OPC_CheckPredicate, 39, 11, 47, // Skip to: 14308
/* 2265 */    MCD::OPC_CheckField, 16, 5, 0, 5, 47, // Skip to: 14308
/* 2271 */    MCD::OPC_Decode, 212, 4, 172, 1, // Opcode: CVT_L_S
/* 2276 */    MCD::OPC_FilterValue, 48, 15, 0, // Skip to: 2295
/* 2280 */    MCD::OPC_CheckPredicate, 35, 248, 46, // Skip to: 14308
/* 2284 */    MCD::OPC_CheckField, 6, 5, 0, 242, 46, // Skip to: 14308
/* 2290 */    MCD::OPC_Decode, 236, 4, 173, 1, // Opcode: C_F_S
/* 2295 */    MCD::OPC_FilterValue, 49, 15, 0, // Skip to: 2314
/* 2299 */    MCD::OPC_CheckPredicate, 35, 229, 46, // Skip to: 14308
/* 2303 */    MCD::OPC_CheckField, 6, 5, 0, 223, 46, // Skip to: 14308
/* 2309 */    MCD::OPC_Decode, 150, 5, 173, 1, // Opcode: C_UN_S
/* 2314 */    MCD::OPC_FilterValue, 50, 15, 0, // Skip to: 2333
/* 2318 */    MCD::OPC_CheckPredicate, 35, 210, 46, // Skip to: 14308
/* 2322 */    MCD::OPC_CheckField, 6, 5, 0, 204, 46, // Skip to: 14308
/* 2328 */    MCD::OPC_Decode, 233, 4, 173, 1, // Opcode: C_EQ_S
/* 2333 */    MCD::OPC_FilterValue, 51, 15, 0, // Skip to: 2352
/* 2337 */    MCD::OPC_CheckPredicate, 35, 191, 46, // Skip to: 14308
/* 2341 */    MCD::OPC_CheckField, 6, 5, 0, 185, 46, // Skip to: 14308
/* 2347 */    MCD::OPC_Decode, 141, 5, 173, 1, // Opcode: C_UEQ_S
/* 2352 */    MCD::OPC_FilterValue, 52, 15, 0, // Skip to: 2371
/* 2356 */    MCD::OPC_CheckPredicate, 35, 172, 46, // Skip to: 14308
/* 2360 */    MCD::OPC_CheckField, 6, 5, 0, 166, 46, // Skip to: 14308
/* 2366 */    MCD::OPC_Decode, 132, 5, 173, 1, // Opcode: C_OLT_S
/* 2371 */    MCD::OPC_FilterValue, 53, 15, 0, // Skip to: 2390
/* 2375 */    MCD::OPC_CheckPredicate, 35, 153, 46, // Skip to: 14308
/* 2379 */    MCD::OPC_CheckField, 6, 5, 0, 147, 46, // Skip to: 14308
/* 2385 */    MCD::OPC_Decode, 147, 5, 173, 1, // Opcode: C_ULT_S
/* 2390 */    MCD::OPC_FilterValue, 54, 15, 0, // Skip to: 2409
/* 2394 */    MCD::OPC_CheckPredicate, 35, 134, 46, // Skip to: 14308
/* 2398 */    MCD::OPC_CheckField, 6, 5, 0, 128, 46, // Skip to: 14308
/* 2404 */    MCD::OPC_Decode, 129, 5, 173, 1, // Opcode: C_OLE_S
/* 2409 */    MCD::OPC_FilterValue, 55, 15, 0, // Skip to: 2428
/* 2413 */    MCD::OPC_CheckPredicate, 35, 115, 46, // Skip to: 14308
/* 2417 */    MCD::OPC_CheckField, 6, 5, 0, 109, 46, // Skip to: 14308
/* 2423 */    MCD::OPC_Decode, 144, 5, 173, 1, // Opcode: C_ULE_S
/* 2428 */    MCD::OPC_FilterValue, 56, 15, 0, // Skip to: 2447
/* 2432 */    MCD::OPC_CheckPredicate, 35, 96, 46, // Skip to: 14308
/* 2436 */    MCD::OPC_CheckField, 6, 5, 0, 90, 46, // Skip to: 14308
/* 2442 */    MCD::OPC_Decode, 138, 5, 173, 1, // Opcode: C_SF_S
/* 2447 */    MCD::OPC_FilterValue, 57, 15, 0, // Skip to: 2466
/* 2451 */    MCD::OPC_CheckPredicate, 35, 77, 46, // Skip to: 14308
/* 2455 */    MCD::OPC_CheckField, 6, 5, 0, 71, 46, // Skip to: 14308
/* 2461 */    MCD::OPC_Decode, 248, 4, 173, 1, // Opcode: C_NGLE_S
/* 2466 */    MCD::OPC_FilterValue, 58, 15, 0, // Skip to: 2485
/* 2470 */    MCD::OPC_CheckPredicate, 35, 58, 46, // Skip to: 14308
/* 2474 */    MCD::OPC_CheckField, 6, 5, 0, 52, 46, // Skip to: 14308
/* 2480 */    MCD::OPC_Decode, 135, 5, 173, 1, // Opcode: C_SEQ_S
/* 2485 */    MCD::OPC_FilterValue, 59, 15, 0, // Skip to: 2504
/* 2489 */    MCD::OPC_CheckPredicate, 35, 39, 46, // Skip to: 14308
/* 2493 */    MCD::OPC_CheckField, 6, 5, 0, 33, 46, // Skip to: 14308
/* 2499 */    MCD::OPC_Decode, 251, 4, 173, 1, // Opcode: C_NGL_S
/* 2504 */    MCD::OPC_FilterValue, 60, 15, 0, // Skip to: 2523
/* 2508 */    MCD::OPC_CheckPredicate, 35, 20, 46, // Skip to: 14308
/* 2512 */    MCD::OPC_CheckField, 6, 5, 0, 14, 46, // Skip to: 14308
/* 2518 */    MCD::OPC_Decode, 242, 4, 173, 1, // Opcode: C_LT_S
/* 2523 */    MCD::OPC_FilterValue, 61, 15, 0, // Skip to: 2542
/* 2527 */    MCD::OPC_CheckPredicate, 35, 1, 46, // Skip to: 14308
/* 2531 */    MCD::OPC_CheckField, 6, 5, 0, 251, 45, // Skip to: 14308
/* 2537 */    MCD::OPC_Decode, 245, 4, 173, 1, // Opcode: C_NGE_S
/* 2542 */    MCD::OPC_FilterValue, 62, 15, 0, // Skip to: 2561
/* 2546 */    MCD::OPC_CheckPredicate, 35, 238, 45, // Skip to: 14308
/* 2550 */    MCD::OPC_CheckField, 6, 5, 0, 232, 45, // Skip to: 14308
/* 2556 */    MCD::OPC_Decode, 239, 4, 173, 1, // Opcode: C_LE_S
/* 2561 */    MCD::OPC_FilterValue, 63, 223, 45, // Skip to: 14308
/* 2565 */    MCD::OPC_CheckPredicate, 35, 219, 45, // Skip to: 14308
/* 2569 */    MCD::OPC_CheckField, 6, 5, 0, 213, 45, // Skip to: 14308
/* 2575 */    MCD::OPC_Decode, 254, 4, 173, 1, // Opcode: C_NGT_S
/* 2580 */    MCD::OPC_FilterValue, 17, 115, 2, // Skip to: 3211
/* 2584 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 2587 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 2600
/* 2591 */    MCD::OPC_CheckPredicate, 38, 193, 45, // Skip to: 14308
/* 2595 */    MCD::OPC_Decode, 222, 6, 174, 1, // Opcode: FADD_D32
/* 2600 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 2613
/* 2604 */    MCD::OPC_CheckPredicate, 38, 180, 45, // Skip to: 14308
/* 2608 */    MCD::OPC_Decode, 238, 7, 174, 1, // Opcode: FSUB_D32
/* 2613 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 2626
/* 2617 */    MCD::OPC_CheckPredicate, 38, 167, 45, // Skip to: 14308
/* 2621 */    MCD::OPC_Decode, 197, 7, 174, 1, // Opcode: FMUL_D32
/* 2626 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 2639
/* 2630 */    MCD::OPC_CheckPredicate, 38, 154, 45, // Skip to: 14308
/* 2634 */    MCD::OPC_Decode, 132, 7, 174, 1, // Opcode: FDIV_D32
/* 2639 */    MCD::OPC_FilterValue, 4, 15, 0, // Skip to: 2658
/* 2643 */    MCD::OPC_CheckPredicate, 40, 141, 45, // Skip to: 14308
/* 2647 */    MCD::OPC_CheckField, 16, 5, 0, 135, 45, // Skip to: 14308
/* 2653 */    MCD::OPC_Decode, 231, 7, 175, 1, // Opcode: FSQRT_D32
/* 2658 */    MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 2677
/* 2662 */    MCD::OPC_CheckPredicate, 38, 122, 45, // Skip to: 14308
/* 2666 */    MCD::OPC_CheckField, 16, 5, 0, 116, 45, // Skip to: 14308
/* 2672 */    MCD::OPC_Decode, 215, 6, 175, 1, // Opcode: FABS_D32
/* 2677 */    MCD::OPC_FilterValue, 6, 15, 0, // Skip to: 2696
/* 2681 */    MCD::OPC_CheckPredicate, 38, 103, 45, // Skip to: 14308
/* 2685 */    MCD::OPC_CheckField, 16, 5, 0, 97, 45, // Skip to: 14308
/* 2691 */    MCD::OPC_Decode, 187, 7, 175, 1, // Opcode: FMOV_D32
/* 2696 */    MCD::OPC_FilterValue, 7, 15, 0, // Skip to: 2715
/* 2700 */    MCD::OPC_CheckPredicate, 38, 84, 45, // Skip to: 14308
/* 2704 */    MCD::OPC_CheckField, 16, 5, 0, 78, 45, // Skip to: 14308
/* 2710 */    MCD::OPC_Decode, 205, 7, 175, 1, // Opcode: FNEG_D32
/* 2715 */    MCD::OPC_FilterValue, 12, 15, 0, // Skip to: 2734
/* 2719 */    MCD::OPC_CheckPredicate, 40, 65, 45, // Skip to: 14308
/* 2723 */    MCD::OPC_CheckField, 16, 5, 0, 59, 45, // Skip to: 14308
/* 2729 */    MCD::OPC_Decode, 201, 13, 176, 1, // Opcode: ROUND_W_D32
/* 2734 */    MCD::OPC_FilterValue, 13, 15, 0, // Skip to: 2753
/* 2738 */    MCD::OPC_CheckPredicate, 40, 46, 45, // Skip to: 14308
/* 2742 */    MCD::OPC_CheckField, 16, 5, 0, 40, 45, // Skip to: 14308
/* 2748 */    MCD::OPC_Decode, 255, 16, 176, 1, // Opcode: TRUNC_W_D32
/* 2753 */    MCD::OPC_FilterValue, 14, 15, 0, // Skip to: 2772
/* 2757 */    MCD::OPC_CheckPredicate, 40, 27, 45, // Skip to: 14308
/* 2761 */    MCD::OPC_CheckField, 16, 5, 0, 21, 45, // Skip to: 14308
/* 2767 */    MCD::OPC_Decode, 174, 3, 176, 1, // Opcode: CEIL_W_D32
/* 2772 */    MCD::OPC_FilterValue, 15, 15, 0, // Skip to: 2791
/* 2776 */    MCD::OPC_CheckPredicate, 40, 8, 45, // Skip to: 14308
/* 2780 */    MCD::OPC_CheckField, 16, 5, 0, 2, 45, // Skip to: 14308
/* 2786 */    MCD::OPC_Decode, 170, 7, 176, 1, // Opcode: FLOOR_W_D32
/* 2791 */    MCD::OPC_FilterValue, 17, 29, 0, // Skip to: 2824
/* 2795 */    MCD::OPC_ExtractField, 16, 2,  // Inst{17-16} ...
/* 2798 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 2811
/* 2802 */    MCD::OPC_CheckPredicate, 41, 238, 44, // Skip to: 14308
/* 2806 */    MCD::OPC_Decode, 241, 10, 177, 1, // Opcode: MOVF_D32
/* 2811 */    MCD::OPC_FilterValue, 1, 229, 44, // Skip to: 14308
/* 2815 */    MCD::OPC_CheckPredicate, 41, 225, 44, // Skip to: 14308
/* 2819 */    MCD::OPC_Decode, 133, 11, 177, 1, // Opcode: MOVT_D32
/* 2824 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 2837
/* 2828 */    MCD::OPC_CheckPredicate, 41, 212, 44, // Skip to: 14308
/* 2832 */    MCD::OPC_Decode, 145, 11, 178, 1, // Opcode: MOVZ_I_D32
/* 2837 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 2850
/* 2841 */    MCD::OPC_CheckPredicate, 41, 199, 44, // Skip to: 14308
/* 2845 */    MCD::OPC_Decode, 253, 10, 178, 1, // Opcode: MOVN_I_D32
/* 2850 */    MCD::OPC_FilterValue, 32, 15, 0, // Skip to: 2869
/* 2854 */    MCD::OPC_CheckPredicate, 38, 186, 44, // Skip to: 14308
/* 2858 */    MCD::OPC_CheckField, 16, 5, 0, 180, 44, // Skip to: 14308
/* 2864 */    MCD::OPC_Decode, 215, 4, 176, 1, // Opcode: CVT_S_D32
/* 2869 */    MCD::OPC_FilterValue, 36, 15, 0, // Skip to: 2888
/* 2873 */    MCD::OPC_CheckPredicate, 38, 167, 44, // Skip to: 14308
/* 2877 */    MCD::OPC_CheckField, 16, 5, 0, 161, 44, // Skip to: 14308
/* 2883 */    MCD::OPC_Decode, 224, 4, 176, 1, // Opcode: CVT_W_D32
/* 2888 */    MCD::OPC_FilterValue, 37, 15, 0, // Skip to: 2907
/* 2892 */    MCD::OPC_CheckPredicate, 39, 148, 44, // Skip to: 14308
/* 2896 */    MCD::OPC_CheckField, 16, 5, 0, 142, 44, // Skip to: 14308
/* 2902 */    MCD::OPC_Decode, 209, 4, 179, 1, // Opcode: CVT_L_D64
/* 2907 */    MCD::OPC_FilterValue, 48, 15, 0, // Skip to: 2926
/* 2911 */    MCD::OPC_CheckPredicate, 42, 129, 44, // Skip to: 14308
/* 2915 */    MCD::OPC_CheckField, 6, 5, 0, 123, 44, // Skip to: 14308
/* 2921 */    MCD::OPC_Decode, 234, 4, 180, 1, // Opcode: C_F_D32
/* 2926 */    MCD::OPC_FilterValue, 49, 15, 0, // Skip to: 2945
/* 2930 */    MCD::OPC_CheckPredicate, 42, 110, 44, // Skip to: 14308
/* 2934 */    MCD::OPC_CheckField, 6, 5, 0, 104, 44, // Skip to: 14308
/* 2940 */    MCD::OPC_Decode, 148, 5, 180, 1, // Opcode: C_UN_D32
/* 2945 */    MCD::OPC_FilterValue, 50, 15, 0, // Skip to: 2964
/* 2949 */    MCD::OPC_CheckPredicate, 42, 91, 44, // Skip to: 14308
/* 2953 */    MCD::OPC_CheckField, 6, 5, 0, 85, 44, // Skip to: 14308
/* 2959 */    MCD::OPC_Decode, 231, 4, 180, 1, // Opcode: C_EQ_D32
/* 2964 */    MCD::OPC_FilterValue, 51, 15, 0, // Skip to: 2983
/* 2968 */    MCD::OPC_CheckPredicate, 42, 72, 44, // Skip to: 14308
/* 2972 */    MCD::OPC_CheckField, 6, 5, 0, 66, 44, // Skip to: 14308
/* 2978 */    MCD::OPC_Decode, 139, 5, 180, 1, // Opcode: C_UEQ_D32
/* 2983 */    MCD::OPC_FilterValue, 52, 15, 0, // Skip to: 3002
/* 2987 */    MCD::OPC_CheckPredicate, 42, 53, 44, // Skip to: 14308
/* 2991 */    MCD::OPC_CheckField, 6, 5, 0, 47, 44, // Skip to: 14308
/* 2997 */    MCD::OPC_Decode, 130, 5, 180, 1, // Opcode: C_OLT_D32
/* 3002 */    MCD::OPC_FilterValue, 53, 15, 0, // Skip to: 3021
/* 3006 */    MCD::OPC_CheckPredicate, 42, 34, 44, // Skip to: 14308
/* 3010 */    MCD::OPC_CheckField, 6, 5, 0, 28, 44, // Skip to: 14308
/* 3016 */    MCD::OPC_Decode, 145, 5, 180, 1, // Opcode: C_ULT_D32
/* 3021 */    MCD::OPC_FilterValue, 54, 15, 0, // Skip to: 3040
/* 3025 */    MCD::OPC_CheckPredicate, 42, 15, 44, // Skip to: 14308
/* 3029 */    MCD::OPC_CheckField, 6, 5, 0, 9, 44, // Skip to: 14308
/* 3035 */    MCD::OPC_Decode, 255, 4, 180, 1, // Opcode: C_OLE_D32
/* 3040 */    MCD::OPC_FilterValue, 55, 15, 0, // Skip to: 3059
/* 3044 */    MCD::OPC_CheckPredicate, 42, 252, 43, // Skip to: 14308
/* 3048 */    MCD::OPC_CheckField, 6, 5, 0, 246, 43, // Skip to: 14308
/* 3054 */    MCD::OPC_Decode, 142, 5, 180, 1, // Opcode: C_ULE_D32
/* 3059 */    MCD::OPC_FilterValue, 56, 15, 0, // Skip to: 3078
/* 3063 */    MCD::OPC_CheckPredicate, 42, 233, 43, // Skip to: 14308
/* 3067 */    MCD::OPC_CheckField, 6, 5, 0, 227, 43, // Skip to: 14308
/* 3073 */    MCD::OPC_Decode, 136, 5, 180, 1, // Opcode: C_SF_D32
/* 3078 */    MCD::OPC_FilterValue, 57, 15, 0, // Skip to: 3097
/* 3082 */    MCD::OPC_CheckPredicate, 42, 214, 43, // Skip to: 14308
/* 3086 */    MCD::OPC_CheckField, 6, 5, 0, 208, 43, // Skip to: 14308
/* 3092 */    MCD::OPC_Decode, 246, 4, 180, 1, // Opcode: C_NGLE_D32
/* 3097 */    MCD::OPC_FilterValue, 58, 15, 0, // Skip to: 3116
/* 3101 */    MCD::OPC_CheckPredicate, 42, 195, 43, // Skip to: 14308
/* 3105 */    MCD::OPC_CheckField, 6, 5, 0, 189, 43, // Skip to: 14308
/* 3111 */    MCD::OPC_Decode, 133, 5, 180, 1, // Opcode: C_SEQ_D32
/* 3116 */    MCD::OPC_FilterValue, 59, 15, 0, // Skip to: 3135
/* 3120 */    MCD::OPC_CheckPredicate, 42, 176, 43, // Skip to: 14308
/* 3124 */    MCD::OPC_CheckField, 6, 5, 0, 170, 43, // Skip to: 14308
/* 3130 */    MCD::OPC_Decode, 249, 4, 180, 1, // Opcode: C_NGL_D32
/* 3135 */    MCD::OPC_FilterValue, 60, 15, 0, // Skip to: 3154
/* 3139 */    MCD::OPC_CheckPredicate, 42, 157, 43, // Skip to: 14308
/* 3143 */    MCD::OPC_CheckField, 6, 5, 0, 151, 43, // Skip to: 14308
/* 3149 */    MCD::OPC_Decode, 240, 4, 180, 1, // Opcode: C_LT_D32
/* 3154 */    MCD::OPC_FilterValue, 61, 15, 0, // Skip to: 3173
/* 3158 */    MCD::OPC_CheckPredicate, 42, 138, 43, // Skip to: 14308
/* 3162 */    MCD::OPC_CheckField, 6, 5, 0, 132, 43, // Skip to: 14308
/* 3168 */    MCD::OPC_Decode, 243, 4, 180, 1, // Opcode: C_NGE_D32
/* 3173 */    MCD::OPC_FilterValue, 62, 15, 0, // Skip to: 3192
/* 3177 */    MCD::OPC_CheckPredicate, 42, 119, 43, // Skip to: 14308
/* 3181 */    MCD::OPC_CheckField, 6, 5, 0, 113, 43, // Skip to: 14308
/* 3187 */    MCD::OPC_Decode, 237, 4, 180, 1, // Opcode: C_LE_D32
/* 3192 */    MCD::OPC_FilterValue, 63, 104, 43, // Skip to: 14308
/* 3196 */    MCD::OPC_CheckPredicate, 42, 100, 43, // Skip to: 14308
/* 3200 */    MCD::OPC_CheckField, 6, 5, 0, 94, 43, // Skip to: 14308
/* 3206 */    MCD::OPC_Decode, 252, 4, 180, 1, // Opcode: C_NGT_D32
/* 3211 */    MCD::OPC_FilterValue, 20, 41, 0, // Skip to: 3256
/* 3215 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 3218 */    MCD::OPC_FilterValue, 32, 15, 0, // Skip to: 3237
/* 3222 */    MCD::OPC_CheckPredicate, 32, 74, 43, // Skip to: 14308
/* 3226 */    MCD::OPC_CheckField, 16, 5, 0, 68, 43, // Skip to: 14308
/* 3232 */    MCD::OPC_Decode, 221, 4, 168, 1, // Opcode: CVT_S_W
/* 3237 */    MCD::OPC_FilterValue, 33, 59, 43, // Skip to: 14308
/* 3241 */    MCD::OPC_CheckPredicate, 38, 55, 43, // Skip to: 14308
/* 3245 */    MCD::OPC_CheckField, 16, 5, 0, 49, 43, // Skip to: 14308
/* 3251 */    MCD::OPC_Decode, 200, 4, 171, 1, // Opcode: CVT_D32_W
/* 3256 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 3269
/* 3260 */    MCD::OPC_CheckPredicate, 18, 36, 43, // Skip to: 14308
/* 3264 */    MCD::OPC_Decode, 129, 3, 166, 1, // Opcode: BZ_B
/* 3269 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 3282
/* 3273 */    MCD::OPC_CheckPredicate, 18, 23, 43, // Skip to: 14308
/* 3277 */    MCD::OPC_Decode, 131, 3, 181, 1, // Opcode: BZ_H
/* 3282 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 3295
/* 3286 */    MCD::OPC_CheckPredicate, 18, 10, 43, // Skip to: 14308
/* 3290 */    MCD::OPC_Decode, 133, 3, 182, 1, // Opcode: BZ_W
/* 3295 */    MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 3308
/* 3299 */    MCD::OPC_CheckPredicate, 18, 253, 42, // Skip to: 14308
/* 3303 */    MCD::OPC_Decode, 130, 3, 183, 1, // Opcode: BZ_D
/* 3308 */    MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 3321
/* 3312 */    MCD::OPC_CheckPredicate, 18, 240, 42, // Skip to: 14308
/* 3316 */    MCD::OPC_Decode, 229, 2, 166, 1, // Opcode: BNZ_B
/* 3321 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 3334
/* 3325 */    MCD::OPC_CheckPredicate, 18, 227, 42, // Skip to: 14308
/* 3329 */    MCD::OPC_Decode, 231, 2, 181, 1, // Opcode: BNZ_H
/* 3334 */    MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 3347
/* 3338 */    MCD::OPC_CheckPredicate, 18, 214, 42, // Skip to: 14308
/* 3342 */    MCD::OPC_Decode, 233, 2, 182, 1, // Opcode: BNZ_W
/* 3347 */    MCD::OPC_FilterValue, 31, 205, 42, // Skip to: 14308
/* 3351 */    MCD::OPC_CheckPredicate, 18, 201, 42, // Skip to: 14308
/* 3355 */    MCD::OPC_Decode, 230, 2, 183, 1, // Opcode: BNZ_D
/* 3360 */    MCD::OPC_FilterValue, 18, 41, 0, // Skip to: 3405
/* 3364 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 3367 */    MCD::OPC_FilterValue, 0, 15, 0, // Skip to: 3386
/* 3371 */    MCD::OPC_CheckPredicate, 15, 181, 42, // Skip to: 14308
/* 3375 */    MCD::OPC_CheckField, 3, 8, 0, 175, 42, // Skip to: 14308
/* 3381 */    MCD::OPC_Decode, 178, 10, 184, 1, // Opcode: MFC2
/* 3386 */    MCD::OPC_FilterValue, 4, 166, 42, // Skip to: 14308
/* 3390 */    MCD::OPC_CheckPredicate, 15, 162, 42, // Skip to: 14308
/* 3394 */    MCD::OPC_CheckField, 3, 8, 0, 156, 42, // Skip to: 14308
/* 3400 */    MCD::OPC_Decode, 181, 11, 185, 1, // Opcode: MTC2
/* 3405 */    MCD::OPC_FilterValue, 19, 221, 0, // Skip to: 3630
/* 3409 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 3412 */    MCD::OPC_FilterValue, 0, 15, 0, // Skip to: 3431
/* 3416 */    MCD::OPC_CheckPredicate, 43, 136, 42, // Skip to: 14308
/* 3420 */    MCD::OPC_CheckField, 11, 5, 0, 130, 42, // Skip to: 14308
/* 3426 */    MCD::OPC_Decode, 217, 9, 186, 1, // Opcode: LWXC1
/* 3431 */    MCD::OPC_FilterValue, 1, 15, 0, // Skip to: 3450
/* 3435 */    MCD::OPC_CheckPredicate, 44, 117, 42, // Skip to: 14308
/* 3439 */    MCD::OPC_CheckField, 11, 5, 0, 111, 42, // Skip to: 14308
/* 3445 */    MCD::OPC_Decode, 135, 9, 187, 1, // Opcode: LDXC1
/* 3450 */    MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 3469
/* 3454 */    MCD::OPC_CheckPredicate, 45, 98, 42, // Skip to: 14308
/* 3458 */    MCD::OPC_CheckField, 11, 5, 0, 92, 42, // Skip to: 14308
/* 3464 */    MCD::OPC_Decode, 178, 9, 187, 1, // Opcode: LUXC1
/* 3469 */    MCD::OPC_FilterValue, 8, 15, 0, // Skip to: 3488
/* 3473 */    MCD::OPC_CheckPredicate, 43, 79, 42, // Skip to: 14308
/* 3477 */    MCD::OPC_CheckField, 6, 5, 0, 73, 42, // Skip to: 14308
/* 3483 */    MCD::OPC_Decode, 158, 16, 188, 1, // Opcode: SWXC1
/* 3488 */    MCD::OPC_FilterValue, 9, 15, 0, // Skip to: 3507
/* 3492 */    MCD::OPC_CheckPredicate, 44, 60, 42, // Skip to: 14308
/* 3496 */    MCD::OPC_CheckField, 6, 5, 0, 54, 42, // Skip to: 14308
/* 3502 */    MCD::OPC_Decode, 128, 14, 189, 1, // Opcode: SDXC1
/* 3507 */    MCD::OPC_FilterValue, 13, 15, 0, // Skip to: 3526
/* 3511 */    MCD::OPC_CheckPredicate, 45, 41, 42, // Skip to: 14308
/* 3515 */    MCD::OPC_CheckField, 6, 5, 0, 35, 42, // Skip to: 14308
/* 3521 */    MCD::OPC_Decode, 254, 15, 189, 1, // Opcode: SUXC1
/* 3526 */    MCD::OPC_FilterValue, 32, 9, 0, // Skip to: 3539
/* 3530 */    MCD::OPC_CheckPredicate, 43, 22, 42, // Skip to: 14308
/* 3534 */    MCD::OPC_Decode, 137, 10, 190, 1, // Opcode: MADD_S
/* 3539 */    MCD::OPC_FilterValue, 33, 9, 0, // Skip to: 3552
/* 3543 */    MCD::OPC_CheckPredicate, 46, 9, 42, // Skip to: 14308
/* 3547 */    MCD::OPC_Decode, 129, 10, 191, 1, // Opcode: MADD_D32
/* 3552 */    MCD::OPC_FilterValue, 40, 9, 0, // Skip to: 3565
/* 3556 */    MCD::OPC_CheckPredicate, 43, 252, 41, // Skip to: 14308
/* 3560 */    MCD::OPC_Decode, 176, 11, 190, 1, // Opcode: MSUB_S
/* 3565 */    MCD::OPC_FilterValue, 41, 9, 0, // Skip to: 3578
/* 3569 */    MCD::OPC_CheckPredicate, 46, 239, 41, // Skip to: 14308
/* 3573 */    MCD::OPC_Decode, 168, 11, 191, 1, // Opcode: MSUB_D32
/* 3578 */    MCD::OPC_FilterValue, 48, 9, 0, // Skip to: 3591
/* 3582 */    MCD::OPC_CheckPredicate, 43, 226, 41, // Skip to: 14308
/* 3586 */    MCD::OPC_Decode, 142, 12, 190, 1, // Opcode: NMADD_S
/* 3591 */    MCD::OPC_FilterValue, 49, 9, 0, // Skip to: 3604
/* 3595 */    MCD::OPC_CheckPredicate, 46, 213, 41, // Skip to: 14308
/* 3599 */    MCD::OPC_Decode, 139, 12, 191, 1, // Opcode: NMADD_D32
/* 3604 */    MCD::OPC_FilterValue, 56, 9, 0, // Skip to: 3617
/* 3608 */    MCD::OPC_CheckPredicate, 43, 200, 41, // Skip to: 14308
/* 3612 */    MCD::OPC_Decode, 147, 12, 190, 1, // Opcode: NMSUB_S
/* 3617 */    MCD::OPC_FilterValue, 57, 191, 41, // Skip to: 14308
/* 3621 */    MCD::OPC_CheckPredicate, 46, 187, 41, // Skip to: 14308
/* 3625 */    MCD::OPC_Decode, 144, 12, 191, 1, // Opcode: NMSUB_D32
/* 3630 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 3643
/* 3634 */    MCD::OPC_CheckPredicate, 26, 174, 41, // Skip to: 14308
/* 3638 */    MCD::OPC_Decode, 234, 1, 152, 1, // Opcode: BEQL
/* 3643 */    MCD::OPC_FilterValue, 21, 64, 0, // Skip to: 3711
/* 3647 */    MCD::OPC_ExtractField, 0, 16,  // Inst{15-0} ...
/* 3650 */    MCD::OPC_FilterValue, 187, 20, 8, 0, // Skip to: 3663
/* 3655 */    MCD::OPC_CheckPredicate, 47, 43, 0, // Skip to: 3702
/* 3659 */    MCD::OPC_Decode, 235, 7, 110, // Opcode: FSQRT_S_MM
/* 3663 */    MCD::OPC_FilterValue, 187, 22, 8, 0, // Skip to: 3676
/* 3668 */    MCD::OPC_CheckPredicate, 47, 30, 0, // Skip to: 3702
/* 3672 */    MCD::OPC_Decode, 175, 7, 110, // Opcode: FLOOR_W_S_MM
/* 3676 */    MCD::OPC_FilterValue, 187, 54, 8, 0, // Skip to: 3689
/* 3681 */    MCD::OPC_CheckPredicate, 47, 17, 0, // Skip to: 3702
/* 3685 */    MCD::OPC_Decode, 179, 3, 110, // Opcode: CEIL_W_S_MM
/* 3689 */    MCD::OPC_FilterValue, 187, 86, 8, 0, // Skip to: 3702
/* 3694 */    MCD::OPC_CheckPredicate, 47, 4, 0, // Skip to: 3702
/* 3698 */    MCD::OPC_Decode, 132, 17, 110, // Opcode: TRUNC_W_S_MM
/* 3702 */    MCD::OPC_CheckPredicate, 26, 106, 41, // Skip to: 14308
/* 3706 */    MCD::OPC_Decode, 220, 2, 152, 1, // Opcode: BNEL
/* 3711 */    MCD::OPC_FilterValue, 22, 15, 0, // Skip to: 3730
/* 3715 */    MCD::OPC_CheckPredicate, 26, 93, 41, // Skip to: 14308
/* 3719 */    MCD::OPC_CheckField, 16, 5, 0, 87, 41, // Skip to: 14308
/* 3725 */    MCD::OPC_Decode, 182, 2, 148, 1, // Opcode: BLEZL
/* 3730 */    MCD::OPC_FilterValue, 23, 15, 0, // Skip to: 3749
/* 3734 */    MCD::OPC_CheckPredicate, 26, 74, 41, // Skip to: 14308
/* 3738 */    MCD::OPC_CheckField, 16, 5, 0, 68, 41, // Skip to: 14308
/* 3744 */    MCD::OPC_Decode, 148, 2, 148, 1, // Opcode: BGTZL
/* 3749 */    MCD::OPC_FilterValue, 28, 236, 0, // Skip to: 3989
/* 3753 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 3756 */    MCD::OPC_FilterValue, 0, 37, 0, // Skip to: 3797
/* 3760 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3763 */    MCD::OPC_FilterValue, 0, 45, 41, // Skip to: 14308
/* 3767 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 3770 */    MCD::OPC_FilterValue, 0, 38, 41, // Skip to: 14308
/* 3774 */    MCD::OPC_CheckPredicate, 19, 10, 0, // Skip to: 3788
/* 3778 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 3788
/* 3784 */    MCD::OPC_Decode, 242, 9, 61, // Opcode: MADD
/* 3788 */    MCD::OPC_CheckPredicate, 23, 20, 41, // Skip to: 14308
/* 3792 */    MCD::OPC_Decode, 132, 10, 192, 1, // Opcode: MADD_DSP
/* 3797 */    MCD::OPC_FilterValue, 1, 37, 0, // Skip to: 3838
/* 3801 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3804 */    MCD::OPC_FilterValue, 0, 4, 41, // Skip to: 14308
/* 3808 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 3811 */    MCD::OPC_FilterValue, 0, 253, 40, // Skip to: 14308
/* 3815 */    MCD::OPC_CheckPredicate, 19, 10, 0, // Skip to: 3829
/* 3819 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 3829
/* 3825 */    MCD::OPC_Decode, 249, 9, 61, // Opcode: MADDU
/* 3829 */    MCD::OPC_CheckPredicate, 23, 235, 40, // Skip to: 14308
/* 3833 */    MCD::OPC_Decode, 250, 9, 192, 1, // Opcode: MADDU_DSP
/* 3838 */    MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 3856
/* 3842 */    MCD::OPC_CheckPredicate, 19, 222, 40, // Skip to: 14308
/* 3846 */    MCD::OPC_CheckField, 6, 5, 0, 216, 40, // Skip to: 14308
/* 3852 */    MCD::OPC_Decode, 207, 11, 47, // Opcode: MUL
/* 3856 */    MCD::OPC_FilterValue, 4, 37, 0, // Skip to: 3897
/* 3860 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3863 */    MCD::OPC_FilterValue, 0, 201, 40, // Skip to: 14308
/* 3867 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 3870 */    MCD::OPC_FilterValue, 0, 194, 40, // Skip to: 14308
/* 3874 */    MCD::OPC_CheckPredicate, 19, 10, 0, // Skip to: 3888
/* 3878 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 3888
/* 3884 */    MCD::OPC_Decode, 153, 11, 61, // Opcode: MSUB
/* 3888 */    MCD::OPC_CheckPredicate, 23, 176, 40, // Skip to: 14308
/* 3892 */    MCD::OPC_Decode, 171, 11, 192, 1, // Opcode: MSUB_DSP
/* 3897 */    MCD::OPC_FilterValue, 5, 37, 0, // Skip to: 3938
/* 3901 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 3904 */    MCD::OPC_FilterValue, 0, 160, 40, // Skip to: 14308
/* 3908 */    MCD::OPC_ExtractField, 13, 3,  // Inst{15-13} ...
/* 3911 */    MCD::OPC_FilterValue, 0, 153, 40, // Skip to: 14308
/* 3915 */    MCD::OPC_CheckPredicate, 19, 10, 0, // Skip to: 3929
/* 3919 */    MCD::OPC_CheckField, 11, 2, 0, 4, 0, // Skip to: 3929
/* 3925 */    MCD::OPC_Decode, 160, 11, 61, // Opcode: MSUBU
/* 3929 */    MCD::OPC_CheckPredicate, 23, 135, 40, // Skip to: 14308
/* 3933 */    MCD::OPC_Decode, 161, 11, 192, 1, // Opcode: MSUBU_DSP
/* 3938 */    MCD::OPC_FilterValue, 32, 15, 0, // Skip to: 3957
/* 3942 */    MCD::OPC_CheckPredicate, 19, 122, 40, // Skip to: 14308
/* 3946 */    MCD::OPC_CheckField, 6, 5, 0, 116, 40, // Skip to: 14308
/* 3952 */    MCD::OPC_Decode, 234, 3, 193, 1, // Opcode: CLZ
/* 3957 */    MCD::OPC_FilterValue, 33, 15, 0, // Skip to: 3976
/* 3961 */    MCD::OPC_CheckPredicate, 19, 103, 40, // Skip to: 14308
/* 3965 */    MCD::OPC_CheckField, 6, 5, 0, 97, 40, // Skip to: 14308
/* 3971 */    MCD::OPC_Decode, 214, 3, 193, 1, // Opcode: CLO
/* 3976 */    MCD::OPC_FilterValue, 63, 88, 40, // Skip to: 14308
/* 3980 */    MCD::OPC_CheckPredicate, 19, 84, 40, // Skip to: 14308
/* 3984 */    MCD::OPC_Decode, 240, 13, 139, 1, // Opcode: SDBBP
/* 3989 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 4002
/* 3993 */    MCD::OPC_CheckPredicate, 19, 71, 40, // Skip to: 14308
/* 3997 */    MCD::OPC_Decode, 206, 8, 151, 1, // Opcode: JALX
/* 4002 */    MCD::OPC_FilterValue, 30, 82, 28, // Skip to: 11256
/* 4006 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 4009 */    MCD::OPC_FilterValue, 0, 54, 0, // Skip to: 4067
/* 4013 */    MCD::OPC_ExtractField, 24, 2,  // Inst{25-24} ...
/* 4016 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 4028
/* 4020 */    MCD::OPC_CheckPredicate, 18, 44, 40, // Skip to: 14308
/* 4024 */    MCD::OPC_Decode, 117, 194, 1, // Opcode: ANDI_B
/* 4028 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 4041
/* 4032 */    MCD::OPC_CheckPredicate, 18, 32, 40, // Skip to: 14308
/* 4036 */    MCD::OPC_Decode, 168, 12, 194, 1, // Opcode: ORI_B
/* 4041 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 4054
/* 4045 */    MCD::OPC_CheckPredicate, 18, 19, 40, // Skip to: 14308
/* 4049 */    MCD::OPC_Decode, 152, 12, 194, 1, // Opcode: NORI_B
/* 4054 */    MCD::OPC_FilterValue, 3, 10, 40, // Skip to: 14308
/* 4058 */    MCD::OPC_CheckPredicate, 18, 6, 40, // Skip to: 14308
/* 4062 */    MCD::OPC_Decode, 160, 17, 194, 1, // Opcode: XORI_B
/* 4067 */    MCD::OPC_FilterValue, 1, 42, 0, // Skip to: 4113
/* 4071 */    MCD::OPC_ExtractField, 24, 2,  // Inst{25-24} ...
/* 4074 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4087
/* 4078 */    MCD::OPC_CheckPredicate, 18, 242, 39, // Skip to: 14308
/* 4082 */    MCD::OPC_Decode, 205, 2, 195, 1, // Opcode: BMNZI_B
/* 4087 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 4100
/* 4091 */    MCD::OPC_CheckPredicate, 18, 229, 39, // Skip to: 14308
/* 4095 */    MCD::OPC_Decode, 207, 2, 195, 1, // Opcode: BMZI_B
/* 4100 */    MCD::OPC_FilterValue, 2, 220, 39, // Skip to: 14308
/* 4104 */    MCD::OPC_CheckPredicate, 18, 216, 39, // Skip to: 14308
/* 4108 */    MCD::OPC_Decode, 242, 2, 195, 1, // Opcode: BSELI_B
/* 4113 */    MCD::OPC_FilterValue, 2, 42, 0, // Skip to: 4159
/* 4117 */    MCD::OPC_ExtractField, 24, 2,  // Inst{25-24} ...
/* 4120 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4133
/* 4124 */    MCD::OPC_CheckPredicate, 18, 196, 39, // Skip to: 14308
/* 4128 */    MCD::OPC_Decode, 166, 14, 194, 1, // Opcode: SHF_B
/* 4133 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 4146
/* 4137 */    MCD::OPC_CheckPredicate, 18, 183, 39, // Skip to: 14308
/* 4141 */    MCD::OPC_Decode, 167, 14, 196, 1, // Opcode: SHF_H
/* 4146 */    MCD::OPC_FilterValue, 2, 174, 39, // Skip to: 14308
/* 4150 */    MCD::OPC_CheckPredicate, 18, 170, 39, // Skip to: 14308
/* 4154 */    MCD::OPC_Decode, 168, 14, 197, 1, // Opcode: SHF_W
/* 4159 */    MCD::OPC_FilterValue, 6, 55, 1, // Skip to: 4474
/* 4163 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 4166 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 4178
/* 4170 */    MCD::OPC_CheckPredicate, 18, 150, 39, // Skip to: 14308
/* 4174 */    MCD::OPC_Decode, 83, 198, 1, // Opcode: ADDVI_B
/* 4178 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 4190
/* 4182 */    MCD::OPC_CheckPredicate, 18, 138, 39, // Skip to: 14308
/* 4186 */    MCD::OPC_Decode, 85, 199, 1, // Opcode: ADDVI_H
/* 4190 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 4202
/* 4194 */    MCD::OPC_CheckPredicate, 18, 126, 39, // Skip to: 14308
/* 4198 */    MCD::OPC_Decode, 86, 200, 1, // Opcode: ADDVI_W
/* 4202 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 4214
/* 4206 */    MCD::OPC_CheckPredicate, 18, 114, 39, // Skip to: 14308
/* 4210 */    MCD::OPC_Decode, 84, 201, 1, // Opcode: ADDVI_D
/* 4214 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 4227
/* 4218 */    MCD::OPC_CheckPredicate, 18, 102, 39, // Skip to: 14308
/* 4222 */    MCD::OPC_Decode, 242, 15, 198, 1, // Opcode: SUBVI_B
/* 4227 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 4240
/* 4231 */    MCD::OPC_CheckPredicate, 18, 89, 39, // Skip to: 14308
/* 4235 */    MCD::OPC_Decode, 244, 15, 199, 1, // Opcode: SUBVI_H
/* 4240 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 4253
/* 4244 */    MCD::OPC_CheckPredicate, 18, 76, 39, // Skip to: 14308
/* 4248 */    MCD::OPC_Decode, 245, 15, 200, 1, // Opcode: SUBVI_W
/* 4253 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 4266
/* 4257 */    MCD::OPC_CheckPredicate, 18, 63, 39, // Skip to: 14308
/* 4261 */    MCD::OPC_Decode, 243, 15, 201, 1, // Opcode: SUBVI_D
/* 4266 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 4279
/* 4270 */    MCD::OPC_CheckPredicate, 18, 50, 39, // Skip to: 14308
/* 4274 */    MCD::OPC_Decode, 151, 10, 198, 1, // Opcode: MAXI_S_B
/* 4279 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 4292
/* 4283 */    MCD::OPC_CheckPredicate, 18, 37, 39, // Skip to: 14308
/* 4287 */    MCD::OPC_Decode, 153, 10, 199, 1, // Opcode: MAXI_S_H
/* 4292 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 4305
/* 4296 */    MCD::OPC_CheckPredicate, 18, 24, 39, // Skip to: 14308
/* 4300 */    MCD::OPC_Decode, 154, 10, 200, 1, // Opcode: MAXI_S_W
/* 4305 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 4318
/* 4309 */    MCD::OPC_CheckPredicate, 18, 11, 39, // Skip to: 14308
/* 4313 */    MCD::OPC_Decode, 152, 10, 201, 1, // Opcode: MAXI_S_D
/* 4318 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 4331
/* 4322 */    MCD::OPC_CheckPredicate, 18, 254, 38, // Skip to: 14308
/* 4326 */    MCD::OPC_Decode, 155, 10, 198, 1, // Opcode: MAXI_U_B
/* 4331 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 4344
/* 4335 */    MCD::OPC_CheckPredicate, 18, 241, 38, // Skip to: 14308
/* 4339 */    MCD::OPC_Decode, 157, 10, 199, 1, // Opcode: MAXI_U_H
/* 4344 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 4357
/* 4348 */    MCD::OPC_CheckPredicate, 18, 228, 38, // Skip to: 14308
/* 4352 */    MCD::OPC_Decode, 158, 10, 200, 1, // Opcode: MAXI_U_W
/* 4357 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 4370
/* 4361 */    MCD::OPC_CheckPredicate, 18, 215, 38, // Skip to: 14308
/* 4365 */    MCD::OPC_Decode, 156, 10, 201, 1, // Opcode: MAXI_U_D
/* 4370 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 4383
/* 4374 */    MCD::OPC_CheckPredicate, 18, 202, 38, // Skip to: 14308
/* 4378 */    MCD::OPC_Decode, 198, 10, 198, 1, // Opcode: MINI_S_B
/* 4383 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 4396
/* 4387 */    MCD::OPC_CheckPredicate, 18, 189, 38, // Skip to: 14308
/* 4391 */    MCD::OPC_Decode, 200, 10, 199, 1, // Opcode: MINI_S_H
/* 4396 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 4409
/* 4400 */    MCD::OPC_CheckPredicate, 18, 176, 38, // Skip to: 14308
/* 4404 */    MCD::OPC_Decode, 201, 10, 200, 1, // Opcode: MINI_S_W
/* 4409 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 4422
/* 4413 */    MCD::OPC_CheckPredicate, 18, 163, 38, // Skip to: 14308
/* 4417 */    MCD::OPC_Decode, 199, 10, 201, 1, // Opcode: MINI_S_D
/* 4422 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 4435
/* 4426 */    MCD::OPC_CheckPredicate, 18, 150, 38, // Skip to: 14308
/* 4430 */    MCD::OPC_Decode, 202, 10, 198, 1, // Opcode: MINI_U_B
/* 4435 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 4448
/* 4439 */    MCD::OPC_CheckPredicate, 18, 137, 38, // Skip to: 14308
/* 4443 */    MCD::OPC_Decode, 204, 10, 199, 1, // Opcode: MINI_U_H
/* 4448 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 4461
/* 4452 */    MCD::OPC_CheckPredicate, 18, 124, 38, // Skip to: 14308
/* 4456 */    MCD::OPC_Decode, 205, 10, 200, 1, // Opcode: MINI_U_W
/* 4461 */    MCD::OPC_FilterValue, 23, 115, 38, // Skip to: 14308
/* 4465 */    MCD::OPC_CheckPredicate, 18, 111, 38, // Skip to: 14308
/* 4469 */    MCD::OPC_Decode, 203, 10, 201, 1, // Opcode: MINI_U_D
/* 4474 */    MCD::OPC_FilterValue, 7, 59, 1, // Skip to: 4793
/* 4478 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 4481 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4494
/* 4485 */    MCD::OPC_CheckPredicate, 18, 91, 38, // Skip to: 14308
/* 4489 */    MCD::OPC_Decode, 181, 3, 198, 1, // Opcode: CEQI_B
/* 4494 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 4507
/* 4498 */    MCD::OPC_CheckPredicate, 18, 78, 38, // Skip to: 14308
/* 4502 */    MCD::OPC_Decode, 183, 3, 199, 1, // Opcode: CEQI_H
/* 4507 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 4520
/* 4511 */    MCD::OPC_CheckPredicate, 18, 65, 38, // Skip to: 14308
/* 4515 */    MCD::OPC_Decode, 184, 3, 200, 1, // Opcode: CEQI_W
/* 4520 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 4533
/* 4524 */    MCD::OPC_CheckPredicate, 18, 52, 38, // Skip to: 14308
/* 4528 */    MCD::OPC_Decode, 182, 3, 201, 1, // Opcode: CEQI_D
/* 4533 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 4546
/* 4537 */    MCD::OPC_CheckPredicate, 18, 39, 38, // Skip to: 14308
/* 4541 */    MCD::OPC_Decode, 218, 3, 198, 1, // Opcode: CLTI_S_B
/* 4546 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 4559
/* 4550 */    MCD::OPC_CheckPredicate, 18, 26, 38, // Skip to: 14308
/* 4554 */    MCD::OPC_Decode, 220, 3, 199, 1, // Opcode: CLTI_S_H
/* 4559 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 4572
/* 4563 */    MCD::OPC_CheckPredicate, 18, 13, 38, // Skip to: 14308
/* 4567 */    MCD::OPC_Decode, 221, 3, 200, 1, // Opcode: CLTI_S_W
/* 4572 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 4585
/* 4576 */    MCD::OPC_CheckPredicate, 18, 0, 38, // Skip to: 14308
/* 4580 */    MCD::OPC_Decode, 219, 3, 201, 1, // Opcode: CLTI_S_D
/* 4585 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 4598
/* 4589 */    MCD::OPC_CheckPredicate, 18, 243, 37, // Skip to: 14308
/* 4593 */    MCD::OPC_Decode, 222, 3, 198, 1, // Opcode: CLTI_U_B
/* 4598 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 4611
/* 4602 */    MCD::OPC_CheckPredicate, 18, 230, 37, // Skip to: 14308
/* 4606 */    MCD::OPC_Decode, 224, 3, 199, 1, // Opcode: CLTI_U_H
/* 4611 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 4624
/* 4615 */    MCD::OPC_CheckPredicate, 18, 217, 37, // Skip to: 14308
/* 4619 */    MCD::OPC_Decode, 225, 3, 200, 1, // Opcode: CLTI_U_W
/* 4624 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 4637
/* 4628 */    MCD::OPC_CheckPredicate, 18, 204, 37, // Skip to: 14308
/* 4632 */    MCD::OPC_Decode, 223, 3, 201, 1, // Opcode: CLTI_U_D
/* 4637 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 4650
/* 4641 */    MCD::OPC_CheckPredicate, 18, 191, 37, // Skip to: 14308
/* 4645 */    MCD::OPC_Decode, 198, 3, 198, 1, // Opcode: CLEI_S_B
/* 4650 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 4663
/* 4654 */    MCD::OPC_CheckPredicate, 18, 178, 37, // Skip to: 14308
/* 4658 */    MCD::OPC_Decode, 200, 3, 199, 1, // Opcode: CLEI_S_H
/* 4663 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 4676
/* 4667 */    MCD::OPC_CheckPredicate, 18, 165, 37, // Skip to: 14308
/* 4671 */    MCD::OPC_Decode, 201, 3, 200, 1, // Opcode: CLEI_S_W
/* 4676 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 4689
/* 4680 */    MCD::OPC_CheckPredicate, 18, 152, 37, // Skip to: 14308
/* 4684 */    MCD::OPC_Decode, 199, 3, 201, 1, // Opcode: CLEI_S_D
/* 4689 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 4702
/* 4693 */    MCD::OPC_CheckPredicate, 18, 139, 37, // Skip to: 14308
/* 4697 */    MCD::OPC_Decode, 202, 3, 198, 1, // Opcode: CLEI_U_B
/* 4702 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 4715
/* 4706 */    MCD::OPC_CheckPredicate, 18, 126, 37, // Skip to: 14308
/* 4710 */    MCD::OPC_Decode, 204, 3, 199, 1, // Opcode: CLEI_U_H
/* 4715 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 4728
/* 4719 */    MCD::OPC_CheckPredicate, 18, 113, 37, // Skip to: 14308
/* 4723 */    MCD::OPC_Decode, 205, 3, 200, 1, // Opcode: CLEI_U_W
/* 4728 */    MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 4741
/* 4732 */    MCD::OPC_CheckPredicate, 18, 100, 37, // Skip to: 14308
/* 4736 */    MCD::OPC_Decode, 203, 3, 201, 1, // Opcode: CLEI_U_D
/* 4741 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 4754
/* 4745 */    MCD::OPC_CheckPredicate, 18, 87, 37, // Skip to: 14308
/* 4749 */    MCD::OPC_Decode, 128, 9, 202, 1, // Opcode: LDI_B
/* 4754 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 4767
/* 4758 */    MCD::OPC_CheckPredicate, 18, 74, 37, // Skip to: 14308
/* 4762 */    MCD::OPC_Decode, 130, 9, 203, 1, // Opcode: LDI_H
/* 4767 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 4780
/* 4771 */    MCD::OPC_CheckPredicate, 18, 61, 37, // Skip to: 14308
/* 4775 */    MCD::OPC_Decode, 131, 9, 204, 1, // Opcode: LDI_W
/* 4780 */    MCD::OPC_FilterValue, 27, 52, 37, // Skip to: 14308
/* 4784 */    MCD::OPC_CheckPredicate, 18, 48, 37, // Skip to: 14308
/* 4788 */    MCD::OPC_Decode, 129, 9, 205, 1, // Opcode: LDI_D
/* 4793 */    MCD::OPC_FilterValue, 9, 67, 2, // Skip to: 5376
/* 4797 */    MCD::OPC_ExtractField, 22, 4,  // Inst{25-22} ...
/* 4800 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4813
/* 4804 */    MCD::OPC_CheckPredicate, 18, 28, 37, // Skip to: 14308
/* 4808 */    MCD::OPC_Decode, 231, 14, 206, 1, // Opcode: SLLI_D
/* 4813 */    MCD::OPC_FilterValue, 1, 55, 0, // Skip to: 4872
/* 4817 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 4820 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4833
/* 4824 */    MCD::OPC_CheckPredicate, 18, 8, 37, // Skip to: 14308
/* 4828 */    MCD::OPC_Decode, 233, 14, 200, 1, // Opcode: SLLI_W
/* 4833 */    MCD::OPC_FilterValue, 1, 255, 36, // Skip to: 14308
/* 4837 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 4840 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4853
/* 4844 */    MCD::OPC_CheckPredicate, 18, 244, 36, // Skip to: 14308
/* 4848 */    MCD::OPC_Decode, 232, 14, 207, 1, // Opcode: SLLI_H
/* 4853 */    MCD::OPC_FilterValue, 1, 235, 36, // Skip to: 14308
/* 4857 */    MCD::OPC_CheckPredicate, 18, 231, 36, // Skip to: 14308
/* 4861 */    MCD::OPC_CheckField, 19, 1, 0, 225, 36, // Skip to: 14308
/* 4867 */    MCD::OPC_Decode, 230, 14, 208, 1, // Opcode: SLLI_B
/* 4872 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 4885
/* 4876 */    MCD::OPC_CheckPredicate, 18, 212, 36, // Skip to: 14308
/* 4880 */    MCD::OPC_Decode, 145, 15, 206, 1, // Opcode: SRAI_D
/* 4885 */    MCD::OPC_FilterValue, 3, 55, 0, // Skip to: 4944
/* 4889 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 4892 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4905
/* 4896 */    MCD::OPC_CheckPredicate, 18, 192, 36, // Skip to: 14308
/* 4900 */    MCD::OPC_Decode, 147, 15, 200, 1, // Opcode: SRAI_W
/* 4905 */    MCD::OPC_FilterValue, 1, 183, 36, // Skip to: 14308
/* 4909 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 4912 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4925
/* 4916 */    MCD::OPC_CheckPredicate, 18, 172, 36, // Skip to: 14308
/* 4920 */    MCD::OPC_Decode, 146, 15, 207, 1, // Opcode: SRAI_H
/* 4925 */    MCD::OPC_FilterValue, 1, 163, 36, // Skip to: 14308
/* 4929 */    MCD::OPC_CheckPredicate, 18, 159, 36, // Skip to: 14308
/* 4933 */    MCD::OPC_CheckField, 19, 1, 0, 153, 36, // Skip to: 14308
/* 4939 */    MCD::OPC_Decode, 144, 15, 208, 1, // Opcode: SRAI_B
/* 4944 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 4957
/* 4948 */    MCD::OPC_CheckPredicate, 18, 140, 36, // Skip to: 14308
/* 4952 */    MCD::OPC_Decode, 167, 15, 206, 1, // Opcode: SRLI_D
/* 4957 */    MCD::OPC_FilterValue, 5, 55, 0, // Skip to: 5016
/* 4961 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 4964 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4977
/* 4968 */    MCD::OPC_CheckPredicate, 18, 120, 36, // Skip to: 14308
/* 4972 */    MCD::OPC_Decode, 169, 15, 200, 1, // Opcode: SRLI_W
/* 4977 */    MCD::OPC_FilterValue, 1, 111, 36, // Skip to: 14308
/* 4981 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 4984 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 4997
/* 4988 */    MCD::OPC_CheckPredicate, 18, 100, 36, // Skip to: 14308
/* 4992 */    MCD::OPC_Decode, 168, 15, 207, 1, // Opcode: SRLI_H
/* 4997 */    MCD::OPC_FilterValue, 1, 91, 36, // Skip to: 14308
/* 5001 */    MCD::OPC_CheckPredicate, 18, 87, 36, // Skip to: 14308
/* 5005 */    MCD::OPC_CheckField, 19, 1, 0, 81, 36, // Skip to: 14308
/* 5011 */    MCD::OPC_Decode, 166, 15, 208, 1, // Opcode: SRLI_B
/* 5016 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 5029
/* 5020 */    MCD::OPC_CheckPredicate, 18, 68, 36, // Skip to: 14308
/* 5024 */    MCD::OPC_Decode, 223, 1, 206, 1, // Opcode: BCLRI_D
/* 5029 */    MCD::OPC_FilterValue, 7, 55, 0, // Skip to: 5088
/* 5033 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 5036 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5049
/* 5040 */    MCD::OPC_CheckPredicate, 18, 48, 36, // Skip to: 14308
/* 5044 */    MCD::OPC_Decode, 225, 1, 200, 1, // Opcode: BCLRI_W
/* 5049 */    MCD::OPC_FilterValue, 1, 39, 36, // Skip to: 14308
/* 5053 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 5056 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5069
/* 5060 */    MCD::OPC_CheckPredicate, 18, 28, 36, // Skip to: 14308
/* 5064 */    MCD::OPC_Decode, 224, 1, 207, 1, // Opcode: BCLRI_H
/* 5069 */    MCD::OPC_FilterValue, 1, 19, 36, // Skip to: 14308
/* 5073 */    MCD::OPC_CheckPredicate, 18, 15, 36, // Skip to: 14308
/* 5077 */    MCD::OPC_CheckField, 19, 1, 0, 9, 36, // Skip to: 14308
/* 5083 */    MCD::OPC_Decode, 222, 1, 208, 1, // Opcode: BCLRI_B
/* 5088 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 5101
/* 5092 */    MCD::OPC_CheckPredicate, 18, 252, 35, // Skip to: 14308
/* 5096 */    MCD::OPC_Decode, 250, 2, 206, 1, // Opcode: BSETI_D
/* 5101 */    MCD::OPC_FilterValue, 9, 55, 0, // Skip to: 5160
/* 5105 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 5108 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5121
/* 5112 */    MCD::OPC_CheckPredicate, 18, 232, 35, // Skip to: 14308
/* 5116 */    MCD::OPC_Decode, 252, 2, 200, 1, // Opcode: BSETI_W
/* 5121 */    MCD::OPC_FilterValue, 1, 223, 35, // Skip to: 14308
/* 5125 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 5128 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5141
/* 5132 */    MCD::OPC_CheckPredicate, 18, 212, 35, // Skip to: 14308
/* 5136 */    MCD::OPC_Decode, 251, 2, 207, 1, // Opcode: BSETI_H
/* 5141 */    MCD::OPC_FilterValue, 1, 203, 35, // Skip to: 14308
/* 5145 */    MCD::OPC_CheckPredicate, 18, 199, 35, // Skip to: 14308
/* 5149 */    MCD::OPC_CheckField, 19, 1, 0, 193, 35, // Skip to: 14308
/* 5155 */    MCD::OPC_Decode, 249, 2, 208, 1, // Opcode: BSETI_B
/* 5160 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 5173
/* 5164 */    MCD::OPC_CheckPredicate, 18, 180, 35, // Skip to: 14308
/* 5168 */    MCD::OPC_Decode, 213, 2, 206, 1, // Opcode: BNEGI_D
/* 5173 */    MCD::OPC_FilterValue, 11, 55, 0, // Skip to: 5232
/* 5177 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 5180 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5193
/* 5184 */    MCD::OPC_CheckPredicate, 18, 160, 35, // Skip to: 14308
/* 5188 */    MCD::OPC_Decode, 215, 2, 200, 1, // Opcode: BNEGI_W
/* 5193 */    MCD::OPC_FilterValue, 1, 151, 35, // Skip to: 14308
/* 5197 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 5200 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5213
/* 5204 */    MCD::OPC_CheckPredicate, 18, 140, 35, // Skip to: 14308
/* 5208 */    MCD::OPC_Decode, 214, 2, 207, 1, // Opcode: BNEGI_H
/* 5213 */    MCD::OPC_FilterValue, 1, 131, 35, // Skip to: 14308
/* 5217 */    MCD::OPC_CheckPredicate, 18, 127, 35, // Skip to: 14308
/* 5221 */    MCD::OPC_CheckField, 19, 1, 0, 121, 35, // Skip to: 14308
/* 5227 */    MCD::OPC_Decode, 212, 2, 208, 1, // Opcode: BNEGI_B
/* 5232 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 5245
/* 5236 */    MCD::OPC_CheckPredicate, 18, 108, 35, // Skip to: 14308
/* 5240 */    MCD::OPC_Decode, 151, 2, 209, 1, // Opcode: BINSLI_D
/* 5245 */    MCD::OPC_FilterValue, 13, 55, 0, // Skip to: 5304
/* 5249 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 5252 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5265
/* 5256 */    MCD::OPC_CheckPredicate, 18, 88, 35, // Skip to: 14308
/* 5260 */    MCD::OPC_Decode, 153, 2, 210, 1, // Opcode: BINSLI_W
/* 5265 */    MCD::OPC_FilterValue, 1, 79, 35, // Skip to: 14308
/* 5269 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 5272 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5285
/* 5276 */    MCD::OPC_CheckPredicate, 18, 68, 35, // Skip to: 14308
/* 5280 */    MCD::OPC_Decode, 152, 2, 211, 1, // Opcode: BINSLI_H
/* 5285 */    MCD::OPC_FilterValue, 1, 59, 35, // Skip to: 14308
/* 5289 */    MCD::OPC_CheckPredicate, 18, 55, 35, // Skip to: 14308
/* 5293 */    MCD::OPC_CheckField, 19, 1, 0, 49, 35, // Skip to: 14308
/* 5299 */    MCD::OPC_Decode, 150, 2, 212, 1, // Opcode: BINSLI_B
/* 5304 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 5317
/* 5308 */    MCD::OPC_CheckPredicate, 18, 36, 35, // Skip to: 14308
/* 5312 */    MCD::OPC_Decode, 159, 2, 209, 1, // Opcode: BINSRI_D
/* 5317 */    MCD::OPC_FilterValue, 15, 27, 35, // Skip to: 14308
/* 5321 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 5324 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5337
/* 5328 */    MCD::OPC_CheckPredicate, 18, 16, 35, // Skip to: 14308
/* 5332 */    MCD::OPC_Decode, 161, 2, 210, 1, // Opcode: BINSRI_W
/* 5337 */    MCD::OPC_FilterValue, 1, 7, 35, // Skip to: 14308
/* 5341 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 5344 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5357
/* 5348 */    MCD::OPC_CheckPredicate, 18, 252, 34, // Skip to: 14308
/* 5352 */    MCD::OPC_Decode, 160, 2, 211, 1, // Opcode: BINSRI_H
/* 5357 */    MCD::OPC_FilterValue, 1, 243, 34, // Skip to: 14308
/* 5361 */    MCD::OPC_CheckPredicate, 18, 239, 34, // Skip to: 14308
/* 5365 */    MCD::OPC_CheckField, 19, 1, 0, 233, 34, // Skip to: 14308
/* 5371 */    MCD::OPC_Decode, 158, 2, 212, 1, // Opcode: BINSRI_B
/* 5376 */    MCD::OPC_FilterValue, 10, 35, 1, // Skip to: 5671
/* 5380 */    MCD::OPC_ExtractField, 22, 4,  // Inst{25-22} ...
/* 5383 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5396
/* 5387 */    MCD::OPC_CheckPredicate, 18, 213, 34, // Skip to: 14308
/* 5391 */    MCD::OPC_Decode, 215, 13, 206, 1, // Opcode: SAT_S_D
/* 5396 */    MCD::OPC_FilterValue, 1, 55, 0, // Skip to: 5455
/* 5400 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 5403 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5416
/* 5407 */    MCD::OPC_CheckPredicate, 18, 193, 34, // Skip to: 14308
/* 5411 */    MCD::OPC_Decode, 217, 13, 200, 1, // Opcode: SAT_S_W
/* 5416 */    MCD::OPC_FilterValue, 1, 184, 34, // Skip to: 14308
/* 5420 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 5423 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5436
/* 5427 */    MCD::OPC_CheckPredicate, 18, 173, 34, // Skip to: 14308
/* 5431 */    MCD::OPC_Decode, 216, 13, 207, 1, // Opcode: SAT_S_H
/* 5436 */    MCD::OPC_FilterValue, 1, 164, 34, // Skip to: 14308
/* 5440 */    MCD::OPC_CheckPredicate, 18, 160, 34, // Skip to: 14308
/* 5444 */    MCD::OPC_CheckField, 19, 1, 0, 154, 34, // Skip to: 14308
/* 5450 */    MCD::OPC_Decode, 214, 13, 208, 1, // Opcode: SAT_S_B
/* 5455 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 5468
/* 5459 */    MCD::OPC_CheckPredicate, 18, 141, 34, // Skip to: 14308
/* 5463 */    MCD::OPC_Decode, 219, 13, 206, 1, // Opcode: SAT_U_D
/* 5468 */    MCD::OPC_FilterValue, 3, 55, 0, // Skip to: 5527
/* 5472 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 5475 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5488
/* 5479 */    MCD::OPC_CheckPredicate, 18, 121, 34, // Skip to: 14308
/* 5483 */    MCD::OPC_Decode, 221, 13, 200, 1, // Opcode: SAT_U_W
/* 5488 */    MCD::OPC_FilterValue, 1, 112, 34, // Skip to: 14308
/* 5492 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 5495 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5508
/* 5499 */    MCD::OPC_CheckPredicate, 18, 101, 34, // Skip to: 14308
/* 5503 */    MCD::OPC_Decode, 220, 13, 207, 1, // Opcode: SAT_U_H
/* 5508 */    MCD::OPC_FilterValue, 1, 92, 34, // Skip to: 14308
/* 5512 */    MCD::OPC_CheckPredicate, 18, 88, 34, // Skip to: 14308
/* 5516 */    MCD::OPC_CheckField, 19, 1, 0, 82, 34, // Skip to: 14308
/* 5522 */    MCD::OPC_Decode, 218, 13, 208, 1, // Opcode: SAT_U_B
/* 5527 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 5540
/* 5531 */    MCD::OPC_CheckPredicate, 18, 69, 34, // Skip to: 14308
/* 5535 */    MCD::OPC_Decode, 149, 15, 206, 1, // Opcode: SRARI_D
/* 5540 */    MCD::OPC_FilterValue, 5, 55, 0, // Skip to: 5599
/* 5544 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 5547 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5560
/* 5551 */    MCD::OPC_CheckPredicate, 18, 49, 34, // Skip to: 14308
/* 5555 */    MCD::OPC_Decode, 151, 15, 200, 1, // Opcode: SRARI_W
/* 5560 */    MCD::OPC_FilterValue, 1, 40, 34, // Skip to: 14308
/* 5564 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 5567 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5580
/* 5571 */    MCD::OPC_CheckPredicate, 18, 29, 34, // Skip to: 14308
/* 5575 */    MCD::OPC_Decode, 150, 15, 207, 1, // Opcode: SRARI_H
/* 5580 */    MCD::OPC_FilterValue, 1, 20, 34, // Skip to: 14308
/* 5584 */    MCD::OPC_CheckPredicate, 18, 16, 34, // Skip to: 14308
/* 5588 */    MCD::OPC_CheckField, 19, 1, 0, 10, 34, // Skip to: 14308
/* 5594 */    MCD::OPC_Decode, 148, 15, 208, 1, // Opcode: SRARI_B
/* 5599 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 5612
/* 5603 */    MCD::OPC_CheckPredicate, 18, 253, 33, // Skip to: 14308
/* 5607 */    MCD::OPC_Decode, 171, 15, 206, 1, // Opcode: SRLRI_D
/* 5612 */    MCD::OPC_FilterValue, 7, 244, 33, // Skip to: 14308
/* 5616 */    MCD::OPC_ExtractField, 21, 1,  // Inst{21} ...
/* 5619 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5632
/* 5623 */    MCD::OPC_CheckPredicate, 18, 233, 33, // Skip to: 14308
/* 5627 */    MCD::OPC_Decode, 173, 15, 200, 1, // Opcode: SRLRI_W
/* 5632 */    MCD::OPC_FilterValue, 1, 224, 33, // Skip to: 14308
/* 5636 */    MCD::OPC_ExtractField, 20, 1,  // Inst{20} ...
/* 5639 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5652
/* 5643 */    MCD::OPC_CheckPredicate, 18, 213, 33, // Skip to: 14308
/* 5647 */    MCD::OPC_Decode, 172, 15, 207, 1, // Opcode: SRLRI_H
/* 5652 */    MCD::OPC_FilterValue, 1, 204, 33, // Skip to: 14308
/* 5656 */    MCD::OPC_CheckPredicate, 18, 200, 33, // Skip to: 14308
/* 5660 */    MCD::OPC_CheckField, 19, 1, 0, 194, 33, // Skip to: 14308
/* 5666 */    MCD::OPC_Decode, 170, 15, 208, 1, // Opcode: SRLRI_B
/* 5671 */    MCD::OPC_FilterValue, 13, 163, 1, // Skip to: 6094
/* 5675 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 5678 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 5691
/* 5682 */    MCD::OPC_CheckPredicate, 18, 174, 33, // Skip to: 14308
/* 5686 */    MCD::OPC_Decode, 236, 14, 213, 1, // Opcode: SLL_B
/* 5691 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 5704
/* 5695 */    MCD::OPC_CheckPredicate, 18, 161, 33, // Skip to: 14308
/* 5699 */    MCD::OPC_Decode, 238, 14, 214, 1, // Opcode: SLL_H
/* 5704 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 5717
/* 5708 */    MCD::OPC_CheckPredicate, 18, 148, 33, // Skip to: 14308
/* 5712 */    MCD::OPC_Decode, 241, 14, 215, 1, // Opcode: SLL_W
/* 5717 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 5730
/* 5721 */    MCD::OPC_CheckPredicate, 18, 135, 33, // Skip to: 14308
/* 5725 */    MCD::OPC_Decode, 237, 14, 216, 1, // Opcode: SLL_D
/* 5730 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 5743
/* 5734 */    MCD::OPC_CheckPredicate, 18, 122, 33, // Skip to: 14308
/* 5738 */    MCD::OPC_Decode, 158, 15, 213, 1, // Opcode: SRA_B
/* 5743 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 5756
/* 5747 */    MCD::OPC_CheckPredicate, 18, 109, 33, // Skip to: 14308
/* 5751 */    MCD::OPC_Decode, 160, 15, 214, 1, // Opcode: SRA_H
/* 5756 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 5769
/* 5760 */    MCD::OPC_CheckPredicate, 18, 96, 33, // Skip to: 14308
/* 5764 */    MCD::OPC_Decode, 162, 15, 215, 1, // Opcode: SRA_W
/* 5769 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 5782
/* 5773 */    MCD::OPC_CheckPredicate, 18, 83, 33, // Skip to: 14308
/* 5777 */    MCD::OPC_Decode, 159, 15, 216, 1, // Opcode: SRA_D
/* 5782 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 5795
/* 5786 */    MCD::OPC_CheckPredicate, 18, 70, 33, // Skip to: 14308
/* 5790 */    MCD::OPC_Decode, 180, 15, 213, 1, // Opcode: SRL_B
/* 5795 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 5808
/* 5799 */    MCD::OPC_CheckPredicate, 18, 57, 33, // Skip to: 14308
/* 5803 */    MCD::OPC_Decode, 182, 15, 214, 1, // Opcode: SRL_H
/* 5808 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 5821
/* 5812 */    MCD::OPC_CheckPredicate, 18, 44, 33, // Skip to: 14308
/* 5816 */    MCD::OPC_Decode, 184, 15, 215, 1, // Opcode: SRL_W
/* 5821 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 5834
/* 5825 */    MCD::OPC_CheckPredicate, 18, 31, 33, // Skip to: 14308
/* 5829 */    MCD::OPC_Decode, 181, 15, 216, 1, // Opcode: SRL_D
/* 5834 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 5847
/* 5838 */    MCD::OPC_CheckPredicate, 18, 18, 33, // Skip to: 14308
/* 5842 */    MCD::OPC_Decode, 226, 1, 213, 1, // Opcode: BCLR_B
/* 5847 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 5860
/* 5851 */    MCD::OPC_CheckPredicate, 18, 5, 33, // Skip to: 14308
/* 5855 */    MCD::OPC_Decode, 228, 1, 214, 1, // Opcode: BCLR_H
/* 5860 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 5873
/* 5864 */    MCD::OPC_CheckPredicate, 18, 248, 32, // Skip to: 14308
/* 5868 */    MCD::OPC_Decode, 229, 1, 215, 1, // Opcode: BCLR_W
/* 5873 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 5886
/* 5877 */    MCD::OPC_CheckPredicate, 18, 235, 32, // Skip to: 14308
/* 5881 */    MCD::OPC_Decode, 227, 1, 216, 1, // Opcode: BCLR_D
/* 5886 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 5899
/* 5890 */    MCD::OPC_CheckPredicate, 18, 222, 32, // Skip to: 14308
/* 5894 */    MCD::OPC_Decode, 253, 2, 213, 1, // Opcode: BSET_B
/* 5899 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 5912
/* 5903 */    MCD::OPC_CheckPredicate, 18, 209, 32, // Skip to: 14308
/* 5907 */    MCD::OPC_Decode, 255, 2, 214, 1, // Opcode: BSET_H
/* 5912 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 5925
/* 5916 */    MCD::OPC_CheckPredicate, 18, 196, 32, // Skip to: 14308
/* 5920 */    MCD::OPC_Decode, 128, 3, 215, 1, // Opcode: BSET_W
/* 5925 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 5938
/* 5929 */    MCD::OPC_CheckPredicate, 18, 183, 32, // Skip to: 14308
/* 5933 */    MCD::OPC_Decode, 254, 2, 216, 1, // Opcode: BSET_D
/* 5938 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 5951
/* 5942 */    MCD::OPC_CheckPredicate, 18, 170, 32, // Skip to: 14308
/* 5946 */    MCD::OPC_Decode, 216, 2, 213, 1, // Opcode: BNEG_B
/* 5951 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 5964
/* 5955 */    MCD::OPC_CheckPredicate, 18, 157, 32, // Skip to: 14308
/* 5959 */    MCD::OPC_Decode, 218, 2, 214, 1, // Opcode: BNEG_H
/* 5964 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 5977
/* 5968 */    MCD::OPC_CheckPredicate, 18, 144, 32, // Skip to: 14308
/* 5972 */    MCD::OPC_Decode, 219, 2, 215, 1, // Opcode: BNEG_W
/* 5977 */    MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 5990
/* 5981 */    MCD::OPC_CheckPredicate, 18, 131, 32, // Skip to: 14308
/* 5985 */    MCD::OPC_Decode, 217, 2, 216, 1, // Opcode: BNEG_D
/* 5990 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 6003
/* 5994 */    MCD::OPC_CheckPredicate, 18, 118, 32, // Skip to: 14308
/* 5998 */    MCD::OPC_Decode, 154, 2, 217, 1, // Opcode: BINSL_B
/* 6003 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 6016
/* 6007 */    MCD::OPC_CheckPredicate, 18, 105, 32, // Skip to: 14308
/* 6011 */    MCD::OPC_Decode, 156, 2, 218, 1, // Opcode: BINSL_H
/* 6016 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 6029
/* 6020 */    MCD::OPC_CheckPredicate, 18, 92, 32, // Skip to: 14308
/* 6024 */    MCD::OPC_Decode, 157, 2, 219, 1, // Opcode: BINSL_W
/* 6029 */    MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 6042
/* 6033 */    MCD::OPC_CheckPredicate, 18, 79, 32, // Skip to: 14308
/* 6037 */    MCD::OPC_Decode, 155, 2, 220, 1, // Opcode: BINSL_D
/* 6042 */    MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 6055
/* 6046 */    MCD::OPC_CheckPredicate, 18, 66, 32, // Skip to: 14308
/* 6050 */    MCD::OPC_Decode, 162, 2, 217, 1, // Opcode: BINSR_B
/* 6055 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 6068
/* 6059 */    MCD::OPC_CheckPredicate, 18, 53, 32, // Skip to: 14308
/* 6063 */    MCD::OPC_Decode, 164, 2, 218, 1, // Opcode: BINSR_H
/* 6068 */    MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 6081
/* 6072 */    MCD::OPC_CheckPredicate, 18, 40, 32, // Skip to: 14308
/* 6076 */    MCD::OPC_Decode, 165, 2, 219, 1, // Opcode: BINSR_W
/* 6081 */    MCD::OPC_FilterValue, 31, 31, 32, // Skip to: 14308
/* 6085 */    MCD::OPC_CheckPredicate, 18, 27, 32, // Skip to: 14308
/* 6089 */    MCD::OPC_Decode, 163, 2, 220, 1, // Opcode: BINSR_D
/* 6094 */    MCD::OPC_FilterValue, 14, 159, 1, // Skip to: 6513
/* 6098 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 6101 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 6113
/* 6105 */    MCD::OPC_CheckPredicate, 18, 7, 32, // Skip to: 14308
/* 6109 */    MCD::OPC_Decode, 87, 213, 1, // Opcode: ADDV_B
/* 6113 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 6125
/* 6117 */    MCD::OPC_CheckPredicate, 18, 251, 31, // Skip to: 14308
/* 6121 */    MCD::OPC_Decode, 89, 214, 1, // Opcode: ADDV_H
/* 6125 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 6137
/* 6129 */    MCD::OPC_CheckPredicate, 18, 239, 31, // Skip to: 14308
/* 6133 */    MCD::OPC_Decode, 90, 215, 1, // Opcode: ADDV_W
/* 6137 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 6149
/* 6141 */    MCD::OPC_CheckPredicate, 18, 227, 31, // Skip to: 14308
/* 6145 */    MCD::OPC_Decode, 88, 216, 1, // Opcode: ADDV_D
/* 6149 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 6162
/* 6153 */    MCD::OPC_CheckPredicate, 18, 215, 31, // Skip to: 14308
/* 6157 */    MCD::OPC_Decode, 246, 15, 213, 1, // Opcode: SUBV_B
/* 6162 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 6175
/* 6166 */    MCD::OPC_CheckPredicate, 18, 202, 31, // Skip to: 14308
/* 6170 */    MCD::OPC_Decode, 248, 15, 214, 1, // Opcode: SUBV_H
/* 6175 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 6188
/* 6179 */    MCD::OPC_CheckPredicate, 18, 189, 31, // Skip to: 14308
/* 6183 */    MCD::OPC_Decode, 249, 15, 215, 1, // Opcode: SUBV_W
/* 6188 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 6201
/* 6192 */    MCD::OPC_CheckPredicate, 18, 176, 31, // Skip to: 14308
/* 6196 */    MCD::OPC_Decode, 247, 15, 216, 1, // Opcode: SUBV_D
/* 6201 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 6214
/* 6205 */    MCD::OPC_CheckPredicate, 18, 163, 31, // Skip to: 14308
/* 6209 */    MCD::OPC_Decode, 166, 10, 213, 1, // Opcode: MAX_S_B
/* 6214 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 6227
/* 6218 */    MCD::OPC_CheckPredicate, 18, 150, 31, // Skip to: 14308
/* 6222 */    MCD::OPC_Decode, 168, 10, 214, 1, // Opcode: MAX_S_H
/* 6227 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 6240
/* 6231 */    MCD::OPC_CheckPredicate, 18, 137, 31, // Skip to: 14308
/* 6235 */    MCD::OPC_Decode, 170, 10, 215, 1, // Opcode: MAX_S_W
/* 6240 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 6253
/* 6244 */    MCD::OPC_CheckPredicate, 18, 124, 31, // Skip to: 14308
/* 6248 */    MCD::OPC_Decode, 167, 10, 216, 1, // Opcode: MAX_S_D
/* 6253 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 6266
/* 6257 */    MCD::OPC_CheckPredicate, 18, 111, 31, // Skip to: 14308
/* 6261 */    MCD::OPC_Decode, 171, 10, 213, 1, // Opcode: MAX_U_B
/* 6266 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 6279
/* 6270 */    MCD::OPC_CheckPredicate, 18, 98, 31, // Skip to: 14308
/* 6274 */    MCD::OPC_Decode, 173, 10, 214, 1, // Opcode: MAX_U_H
/* 6279 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 6292
/* 6283 */    MCD::OPC_CheckPredicate, 18, 85, 31, // Skip to: 14308
/* 6287 */    MCD::OPC_Decode, 174, 10, 215, 1, // Opcode: MAX_U_W
/* 6292 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 6305
/* 6296 */    MCD::OPC_CheckPredicate, 18, 72, 31, // Skip to: 14308
/* 6300 */    MCD::OPC_Decode, 172, 10, 216, 1, // Opcode: MAX_U_D
/* 6305 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 6318
/* 6309 */    MCD::OPC_CheckPredicate, 18, 59, 31, // Skip to: 14308
/* 6313 */    MCD::OPC_Decode, 213, 10, 213, 1, // Opcode: MIN_S_B
/* 6318 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 6331
/* 6322 */    MCD::OPC_CheckPredicate, 18, 46, 31, // Skip to: 14308
/* 6326 */    MCD::OPC_Decode, 215, 10, 214, 1, // Opcode: MIN_S_H
/* 6331 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 6344
/* 6335 */    MCD::OPC_CheckPredicate, 18, 33, 31, // Skip to: 14308
/* 6339 */    MCD::OPC_Decode, 217, 10, 215, 1, // Opcode: MIN_S_W
/* 6344 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 6357
/* 6348 */    MCD::OPC_CheckPredicate, 18, 20, 31, // Skip to: 14308
/* 6352 */    MCD::OPC_Decode, 214, 10, 216, 1, // Opcode: MIN_S_D
/* 6357 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 6370
/* 6361 */    MCD::OPC_CheckPredicate, 18, 7, 31, // Skip to: 14308
/* 6365 */    MCD::OPC_Decode, 218, 10, 213, 1, // Opcode: MIN_U_B
/* 6370 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 6383
/* 6374 */    MCD::OPC_CheckPredicate, 18, 250, 30, // Skip to: 14308
/* 6378 */    MCD::OPC_Decode, 220, 10, 214, 1, // Opcode: MIN_U_H
/* 6383 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 6396
/* 6387 */    MCD::OPC_CheckPredicate, 18, 237, 30, // Skip to: 14308
/* 6391 */    MCD::OPC_Decode, 221, 10, 215, 1, // Opcode: MIN_U_W
/* 6396 */    MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 6409
/* 6400 */    MCD::OPC_CheckPredicate, 18, 224, 30, // Skip to: 14308
/* 6404 */    MCD::OPC_Decode, 219, 10, 216, 1, // Opcode: MIN_U_D
/* 6409 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 6422
/* 6413 */    MCD::OPC_CheckPredicate, 18, 211, 30, // Skip to: 14308
/* 6417 */    MCD::OPC_Decode, 159, 10, 213, 1, // Opcode: MAX_A_B
/* 6422 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 6435
/* 6426 */    MCD::OPC_CheckPredicate, 18, 198, 30, // Skip to: 14308
/* 6430 */    MCD::OPC_Decode, 161, 10, 214, 1, // Opcode: MAX_A_H
/* 6435 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 6448
/* 6439 */    MCD::OPC_CheckPredicate, 18, 185, 30, // Skip to: 14308
/* 6443 */    MCD::OPC_Decode, 162, 10, 215, 1, // Opcode: MAX_A_W
/* 6448 */    MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 6461
/* 6452 */    MCD::OPC_CheckPredicate, 18, 172, 30, // Skip to: 14308
/* 6456 */    MCD::OPC_Decode, 160, 10, 216, 1, // Opcode: MAX_A_D
/* 6461 */    MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 6474
/* 6465 */    MCD::OPC_CheckPredicate, 18, 159, 30, // Skip to: 14308
/* 6469 */    MCD::OPC_Decode, 206, 10, 213, 1, // Opcode: MIN_A_B
/* 6474 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 6487
/* 6478 */    MCD::OPC_CheckPredicate, 18, 146, 30, // Skip to: 14308
/* 6482 */    MCD::OPC_Decode, 208, 10, 214, 1, // Opcode: MIN_A_H
/* 6487 */    MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 6500
/* 6491 */    MCD::OPC_CheckPredicate, 18, 133, 30, // Skip to: 14308
/* 6495 */    MCD::OPC_Decode, 209, 10, 215, 1, // Opcode: MIN_A_W
/* 6500 */    MCD::OPC_FilterValue, 31, 124, 30, // Skip to: 14308
/* 6504 */    MCD::OPC_CheckPredicate, 18, 120, 30, // Skip to: 14308
/* 6508 */    MCD::OPC_Decode, 207, 10, 216, 1, // Opcode: MIN_A_D
/* 6513 */    MCD::OPC_FilterValue, 15, 7, 1, // Skip to: 6780
/* 6517 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 6520 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 6533
/* 6524 */    MCD::OPC_CheckPredicate, 18, 100, 30, // Skip to: 14308
/* 6528 */    MCD::OPC_Decode, 185, 3, 213, 1, // Opcode: CEQ_B
/* 6533 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 6546
/* 6537 */    MCD::OPC_CheckPredicate, 18, 87, 30, // Skip to: 14308
/* 6541 */    MCD::OPC_Decode, 187, 3, 214, 1, // Opcode: CEQ_H
/* 6546 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 6559
/* 6550 */    MCD::OPC_CheckPredicate, 18, 74, 30, // Skip to: 14308
/* 6554 */    MCD::OPC_Decode, 188, 3, 215, 1, // Opcode: CEQ_W
/* 6559 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 6572
/* 6563 */    MCD::OPC_CheckPredicate, 18, 61, 30, // Skip to: 14308
/* 6567 */    MCD::OPC_Decode, 186, 3, 216, 1, // Opcode: CEQ_D
/* 6572 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 6585
/* 6576 */    MCD::OPC_CheckPredicate, 18, 48, 30, // Skip to: 14308
/* 6580 */    MCD::OPC_Decode, 226, 3, 213, 1, // Opcode: CLT_S_B
/* 6585 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 6598
/* 6589 */    MCD::OPC_CheckPredicate, 18, 35, 30, // Skip to: 14308
/* 6593 */    MCD::OPC_Decode, 228, 3, 214, 1, // Opcode: CLT_S_H
/* 6598 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 6611
/* 6602 */    MCD::OPC_CheckPredicate, 18, 22, 30, // Skip to: 14308
/* 6606 */    MCD::OPC_Decode, 229, 3, 215, 1, // Opcode: CLT_S_W
/* 6611 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 6624
/* 6615 */    MCD::OPC_CheckPredicate, 18, 9, 30, // Skip to: 14308
/* 6619 */    MCD::OPC_Decode, 227, 3, 216, 1, // Opcode: CLT_S_D
/* 6624 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 6637
/* 6628 */    MCD::OPC_CheckPredicate, 18, 252, 29, // Skip to: 14308
/* 6632 */    MCD::OPC_Decode, 230, 3, 213, 1, // Opcode: CLT_U_B
/* 6637 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 6650
/* 6641 */    MCD::OPC_CheckPredicate, 18, 239, 29, // Skip to: 14308
/* 6645 */    MCD::OPC_Decode, 232, 3, 214, 1, // Opcode: CLT_U_H
/* 6650 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 6663
/* 6654 */    MCD::OPC_CheckPredicate, 18, 226, 29, // Skip to: 14308
/* 6658 */    MCD::OPC_Decode, 233, 3, 215, 1, // Opcode: CLT_U_W
/* 6663 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 6676
/* 6667 */    MCD::OPC_CheckPredicate, 18, 213, 29, // Skip to: 14308
/* 6671 */    MCD::OPC_Decode, 231, 3, 216, 1, // Opcode: CLT_U_D
/* 6676 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 6689
/* 6680 */    MCD::OPC_CheckPredicate, 18, 200, 29, // Skip to: 14308
/* 6684 */    MCD::OPC_Decode, 206, 3, 213, 1, // Opcode: CLE_S_B
/* 6689 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 6702
/* 6693 */    MCD::OPC_CheckPredicate, 18, 187, 29, // Skip to: 14308
/* 6697 */    MCD::OPC_Decode, 208, 3, 214, 1, // Opcode: CLE_S_H
/* 6702 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 6715
/* 6706 */    MCD::OPC_CheckPredicate, 18, 174, 29, // Skip to: 14308
/* 6710 */    MCD::OPC_Decode, 209, 3, 215, 1, // Opcode: CLE_S_W
/* 6715 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 6728
/* 6719 */    MCD::OPC_CheckPredicate, 18, 161, 29, // Skip to: 14308
/* 6723 */    MCD::OPC_Decode, 207, 3, 216, 1, // Opcode: CLE_S_D
/* 6728 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 6741
/* 6732 */    MCD::OPC_CheckPredicate, 18, 148, 29, // Skip to: 14308
/* 6736 */    MCD::OPC_Decode, 210, 3, 213, 1, // Opcode: CLE_U_B
/* 6741 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 6754
/* 6745 */    MCD::OPC_CheckPredicate, 18, 135, 29, // Skip to: 14308
/* 6749 */    MCD::OPC_Decode, 212, 3, 214, 1, // Opcode: CLE_U_H
/* 6754 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 6767
/* 6758 */    MCD::OPC_CheckPredicate, 18, 122, 29, // Skip to: 14308
/* 6762 */    MCD::OPC_Decode, 213, 3, 215, 1, // Opcode: CLE_U_W
/* 6767 */    MCD::OPC_FilterValue, 23, 113, 29, // Skip to: 14308
/* 6771 */    MCD::OPC_CheckPredicate, 18, 109, 29, // Skip to: 14308
/* 6775 */    MCD::OPC_Decode, 211, 3, 216, 1, // Opcode: CLE_U_D
/* 6780 */    MCD::OPC_FilterValue, 16, 147, 1, // Skip to: 7187
/* 6784 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 6787 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 6799
/* 6791 */    MCD::OPC_CheckPredicate, 18, 89, 29, // Skip to: 14308
/* 6795 */    MCD::OPC_Decode, 93, 213, 1, // Opcode: ADD_A_B
/* 6799 */    MCD::OPC_FilterValue, 1, 8, 0, // Skip to: 6811
/* 6803 */    MCD::OPC_CheckPredicate, 18, 77, 29, // Skip to: 14308
/* 6807 */    MCD::OPC_Decode, 95, 214, 1, // Opcode: ADD_A_H
/* 6811 */    MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 6823
/* 6815 */    MCD::OPC_CheckPredicate, 18, 65, 29, // Skip to: 14308
/* 6819 */    MCD::OPC_Decode, 96, 215, 1, // Opcode: ADD_A_W
/* 6823 */    MCD::OPC_FilterValue, 3, 8, 0, // Skip to: 6835
/* 6827 */    MCD::OPC_CheckPredicate, 18, 53, 29, // Skip to: 14308
/* 6831 */    MCD::OPC_Decode, 94, 216, 1, // Opcode: ADD_A_D
/* 6835 */    MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 6847
/* 6839 */    MCD::OPC_CheckPredicate, 18, 41, 29, // Skip to: 14308
/* 6843 */    MCD::OPC_Decode, 56, 213, 1, // Opcode: ADDS_A_B
/* 6847 */    MCD::OPC_FilterValue, 5, 8, 0, // Skip to: 6859
/* 6851 */    MCD::OPC_CheckPredicate, 18, 29, 29, // Skip to: 14308
/* 6855 */    MCD::OPC_Decode, 58, 214, 1, // Opcode: ADDS_A_H
/* 6859 */    MCD::OPC_FilterValue, 6, 8, 0, // Skip to: 6871
/* 6863 */    MCD::OPC_CheckPredicate, 18, 17, 29, // Skip to: 14308
/* 6867 */    MCD::OPC_Decode, 59, 215, 1, // Opcode: ADDS_A_W
/* 6871 */    MCD::OPC_FilterValue, 7, 8, 0, // Skip to: 6883
/* 6875 */    MCD::OPC_CheckPredicate, 18, 5, 29, // Skip to: 14308
/* 6879 */    MCD::OPC_Decode, 57, 216, 1, // Opcode: ADDS_A_D
/* 6883 */    MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 6895
/* 6887 */    MCD::OPC_CheckPredicate, 18, 249, 28, // Skip to: 14308
/* 6891 */    MCD::OPC_Decode, 60, 213, 1, // Opcode: ADDS_S_B
/* 6895 */    MCD::OPC_FilterValue, 9, 8, 0, // Skip to: 6907
/* 6899 */    MCD::OPC_CheckPredicate, 18, 237, 28, // Skip to: 14308
/* 6903 */    MCD::OPC_Decode, 62, 214, 1, // Opcode: ADDS_S_H
/* 6907 */    MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 6919
/* 6911 */    MCD::OPC_CheckPredicate, 18, 225, 28, // Skip to: 14308
/* 6915 */    MCD::OPC_Decode, 63, 215, 1, // Opcode: ADDS_S_W
/* 6919 */    MCD::OPC_FilterValue, 11, 8, 0, // Skip to: 6931
/* 6923 */    MCD::OPC_CheckPredicate, 18, 213, 28, // Skip to: 14308
/* 6927 */    MCD::OPC_Decode, 61, 216, 1, // Opcode: ADDS_S_D
/* 6931 */    MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 6943
/* 6935 */    MCD::OPC_CheckPredicate, 18, 201, 28, // Skip to: 14308
/* 6939 */    MCD::OPC_Decode, 64, 213, 1, // Opcode: ADDS_U_B
/* 6943 */    MCD::OPC_FilterValue, 13, 8, 0, // Skip to: 6955
/* 6947 */    MCD::OPC_CheckPredicate, 18, 189, 28, // Skip to: 14308
/* 6951 */    MCD::OPC_Decode, 66, 214, 1, // Opcode: ADDS_U_H
/* 6955 */    MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 6967
/* 6959 */    MCD::OPC_CheckPredicate, 18, 177, 28, // Skip to: 14308
/* 6963 */    MCD::OPC_Decode, 67, 215, 1, // Opcode: ADDS_U_W
/* 6967 */    MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 6979
/* 6971 */    MCD::OPC_CheckPredicate, 18, 165, 28, // Skip to: 14308
/* 6975 */    MCD::OPC_Decode, 65, 216, 1, // Opcode: ADDS_U_D
/* 6979 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 6992
/* 6983 */    MCD::OPC_CheckPredicate, 18, 153, 28, // Skip to: 14308
/* 6987 */    MCD::OPC_Decode, 181, 1, 213, 1, // Opcode: AVE_S_B
/* 6992 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 7005
/* 6996 */    MCD::OPC_CheckPredicate, 18, 140, 28, // Skip to: 14308
/* 7000 */    MCD::OPC_Decode, 183, 1, 214, 1, // Opcode: AVE_S_H
/* 7005 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 7018
/* 7009 */    MCD::OPC_CheckPredicate, 18, 127, 28, // Skip to: 14308
/* 7013 */    MCD::OPC_Decode, 184, 1, 215, 1, // Opcode: AVE_S_W
/* 7018 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 7031
/* 7022 */    MCD::OPC_CheckPredicate, 18, 114, 28, // Skip to: 14308
/* 7026 */    MCD::OPC_Decode, 182, 1, 216, 1, // Opcode: AVE_S_D
/* 7031 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 7044
/* 7035 */    MCD::OPC_CheckPredicate, 18, 101, 28, // Skip to: 14308
/* 7039 */    MCD::OPC_Decode, 185, 1, 213, 1, // Opcode: AVE_U_B
/* 7044 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 7057
/* 7048 */    MCD::OPC_CheckPredicate, 18, 88, 28, // Skip to: 14308
/* 7052 */    MCD::OPC_Decode, 187, 1, 214, 1, // Opcode: AVE_U_H
/* 7057 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 7070
/* 7061 */    MCD::OPC_CheckPredicate, 18, 75, 28, // Skip to: 14308
/* 7065 */    MCD::OPC_Decode, 188, 1, 215, 1, // Opcode: AVE_U_W
/* 7070 */    MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 7083
/* 7074 */    MCD::OPC_CheckPredicate, 18, 62, 28, // Skip to: 14308
/* 7078 */    MCD::OPC_Decode, 186, 1, 216, 1, // Opcode: AVE_U_D
/* 7083 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 7096
/* 7087 */    MCD::OPC_CheckPredicate, 18, 49, 28, // Skip to: 14308
/* 7091 */    MCD::OPC_Decode, 173, 1, 213, 1, // Opcode: AVER_S_B
/* 7096 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 7109
/* 7100 */    MCD::OPC_CheckPredicate, 18, 36, 28, // Skip to: 14308
/* 7104 */    MCD::OPC_Decode, 175, 1, 214, 1, // Opcode: AVER_S_H
/* 7109 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 7122
/* 7113 */    MCD::OPC_CheckPredicate, 18, 23, 28, // Skip to: 14308
/* 7117 */    MCD::OPC_Decode, 176, 1, 215, 1, // Opcode: AVER_S_W
/* 7122 */    MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 7135
/* 7126 */    MCD::OPC_CheckPredicate, 18, 10, 28, // Skip to: 14308
/* 7130 */    MCD::OPC_Decode, 174, 1, 216, 1, // Opcode: AVER_S_D
/* 7135 */    MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 7148
/* 7139 */    MCD::OPC_CheckPredicate, 18, 253, 27, // Skip to: 14308
/* 7143 */    MCD::OPC_Decode, 177, 1, 213, 1, // Opcode: AVER_U_B
/* 7148 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 7161
/* 7152 */    MCD::OPC_CheckPredicate, 18, 240, 27, // Skip to: 14308
/* 7156 */    MCD::OPC_Decode, 179, 1, 214, 1, // Opcode: AVER_U_H
/* 7161 */    MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 7174
/* 7165 */    MCD::OPC_CheckPredicate, 18, 227, 27, // Skip to: 14308
/* 7169 */    MCD::OPC_Decode, 180, 1, 215, 1, // Opcode: AVER_U_W
/* 7174 */    MCD::OPC_FilterValue, 31, 218, 27, // Skip to: 14308
/* 7178 */    MCD::OPC_CheckPredicate, 18, 214, 27, // Skip to: 14308
/* 7182 */    MCD::OPC_Decode, 178, 1, 216, 1, // Opcode: AVER_U_D
/* 7187 */    MCD::OPC_FilterValue, 17, 59, 1, // Skip to: 7506
/* 7191 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 7194 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 7207
/* 7198 */    MCD::OPC_CheckPredicate, 18, 194, 27, // Skip to: 14308
/* 7202 */    MCD::OPC_Decode, 219, 15, 213, 1, // Opcode: SUBS_S_B
/* 7207 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 7220
/* 7211 */    MCD::OPC_CheckPredicate, 18, 181, 27, // Skip to: 14308
/* 7215 */    MCD::OPC_Decode, 221, 15, 214, 1, // Opcode: SUBS_S_H
/* 7220 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 7233
/* 7224 */    MCD::OPC_CheckPredicate, 18, 168, 27, // Skip to: 14308
/* 7228 */    MCD::OPC_Decode, 222, 15, 215, 1, // Opcode: SUBS_S_W
/* 7233 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 7246
/* 7237 */    MCD::OPC_CheckPredicate, 18, 155, 27, // Skip to: 14308
/* 7241 */    MCD::OPC_Decode, 220, 15, 216, 1, // Opcode: SUBS_S_D
/* 7246 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 7259
/* 7250 */    MCD::OPC_CheckPredicate, 18, 142, 27, // Skip to: 14308
/* 7254 */    MCD::OPC_Decode, 223, 15, 213, 1, // Opcode: SUBS_U_B
/* 7259 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 7272
/* 7263 */    MCD::OPC_CheckPredicate, 18, 129, 27, // Skip to: 14308
/* 7267 */    MCD::OPC_Decode, 225, 15, 214, 1, // Opcode: SUBS_U_H
/* 7272 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 7285
/* 7276 */    MCD::OPC_CheckPredicate, 18, 116, 27, // Skip to: 14308
/* 7280 */    MCD::OPC_Decode, 226, 15, 215, 1, // Opcode: SUBS_U_W
/* 7285 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 7298
/* 7289 */    MCD::OPC_CheckPredicate, 18, 103, 27, // Skip to: 14308
/* 7293 */    MCD::OPC_Decode, 224, 15, 216, 1, // Opcode: SUBS_U_D
/* 7298 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 7311
/* 7302 */    MCD::OPC_CheckPredicate, 18, 90, 27, // Skip to: 14308
/* 7306 */    MCD::OPC_Decode, 211, 15, 213, 1, // Opcode: SUBSUS_U_B
/* 7311 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 7324
/* 7315 */    MCD::OPC_CheckPredicate, 18, 77, 27, // Skip to: 14308
/* 7319 */    MCD::OPC_Decode, 213, 15, 214, 1, // Opcode: SUBSUS_U_H
/* 7324 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 7337
/* 7328 */    MCD::OPC_CheckPredicate, 18, 64, 27, // Skip to: 14308
/* 7332 */    MCD::OPC_Decode, 214, 15, 215, 1, // Opcode: SUBSUS_U_W
/* 7337 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 7350
/* 7341 */    MCD::OPC_CheckPredicate, 18, 51, 27, // Skip to: 14308
/* 7345 */    MCD::OPC_Decode, 212, 15, 216, 1, // Opcode: SUBSUS_U_D
/* 7350 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 7363
/* 7354 */    MCD::OPC_CheckPredicate, 18, 38, 27, // Skip to: 14308
/* 7358 */    MCD::OPC_Decode, 215, 15, 213, 1, // Opcode: SUBSUU_S_B
/* 7363 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 7376
/* 7367 */    MCD::OPC_CheckPredicate, 18, 25, 27, // Skip to: 14308
/* 7371 */    MCD::OPC_Decode, 217, 15, 214, 1, // Opcode: SUBSUU_S_H
/* 7376 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 7389
/* 7380 */    MCD::OPC_CheckPredicate, 18, 12, 27, // Skip to: 14308
/* 7384 */    MCD::OPC_Decode, 218, 15, 215, 1, // Opcode: SUBSUU_S_W
/* 7389 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 7402
/* 7393 */    MCD::OPC_CheckPredicate, 18, 255, 26, // Skip to: 14308
/* 7397 */    MCD::OPC_Decode, 216, 15, 216, 1, // Opcode: SUBSUU_S_D
/* 7402 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 7415
/* 7406 */    MCD::OPC_CheckPredicate, 18, 242, 26, // Skip to: 14308
/* 7410 */    MCD::OPC_Decode, 129, 1, 213, 1, // Opcode: ASUB_S_B
/* 7415 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 7428
/* 7419 */    MCD::OPC_CheckPredicate, 18, 229, 26, // Skip to: 14308
/* 7423 */    MCD::OPC_Decode, 131, 1, 214, 1, // Opcode: ASUB_S_H
/* 7428 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 7441
/* 7432 */    MCD::OPC_CheckPredicate, 18, 216, 26, // Skip to: 14308
/* 7436 */    MCD::OPC_Decode, 132, 1, 215, 1, // Opcode: ASUB_S_W
/* 7441 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 7454
/* 7445 */    MCD::OPC_CheckPredicate, 18, 203, 26, // Skip to: 14308
/* 7449 */    MCD::OPC_Decode, 130, 1, 216, 1, // Opcode: ASUB_S_D
/* 7454 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 7467
/* 7458 */    MCD::OPC_CheckPredicate, 18, 190, 26, // Skip to: 14308
/* 7462 */    MCD::OPC_Decode, 133, 1, 213, 1, // Opcode: ASUB_U_B
/* 7467 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 7480
/* 7471 */    MCD::OPC_CheckPredicate, 18, 177, 26, // Skip to: 14308
/* 7475 */    MCD::OPC_Decode, 135, 1, 214, 1, // Opcode: ASUB_U_H
/* 7480 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 7493
/* 7484 */    MCD::OPC_CheckPredicate, 18, 164, 26, // Skip to: 14308
/* 7488 */    MCD::OPC_Decode, 136, 1, 215, 1, // Opcode: ASUB_U_W
/* 7493 */    MCD::OPC_FilterValue, 23, 155, 26, // Skip to: 14308
/* 7497 */    MCD::OPC_CheckPredicate, 18, 151, 26, // Skip to: 14308
/* 7501 */    MCD::OPC_Decode, 134, 1, 216, 1, // Opcode: ASUB_U_D
/* 7506 */    MCD::OPC_FilterValue, 18, 111, 1, // Skip to: 7877
/* 7510 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 7513 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 7526
/* 7517 */    MCD::OPC_CheckPredicate, 18, 131, 26, // Skip to: 14308
/* 7521 */    MCD::OPC_Decode, 238, 11, 213, 1, // Opcode: MULV_B
/* 7526 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 7539
/* 7530 */    MCD::OPC_CheckPredicate, 18, 118, 26, // Skip to: 14308
/* 7534 */    MCD::OPC_Decode, 240, 11, 214, 1, // Opcode: MULV_H
/* 7539 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 7552
/* 7543 */    MCD::OPC_CheckPredicate, 18, 105, 26, // Skip to: 14308
/* 7547 */    MCD::OPC_Decode, 241, 11, 215, 1, // Opcode: MULV_W
/* 7552 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 7565
/* 7556 */    MCD::OPC_CheckPredicate, 18, 92, 26, // Skip to: 14308
/* 7560 */    MCD::OPC_Decode, 239, 11, 216, 1, // Opcode: MULV_D
/* 7565 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 7578
/* 7569 */    MCD::OPC_CheckPredicate, 18, 79, 26, // Skip to: 14308
/* 7573 */    MCD::OPC_Decode, 253, 9, 217, 1, // Opcode: MADDV_B
/* 7578 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 7591
/* 7582 */    MCD::OPC_CheckPredicate, 18, 66, 26, // Skip to: 14308
/* 7586 */    MCD::OPC_Decode, 255, 9, 218, 1, // Opcode: MADDV_H
/* 7591 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 7604
/* 7595 */    MCD::OPC_CheckPredicate, 18, 53, 26, // Skip to: 14308
/* 7599 */    MCD::OPC_Decode, 128, 10, 219, 1, // Opcode: MADDV_W
/* 7604 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 7617
/* 7608 */    MCD::OPC_CheckPredicate, 18, 40, 26, // Skip to: 14308
/* 7612 */    MCD::OPC_Decode, 254, 9, 220, 1, // Opcode: MADDV_D
/* 7617 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 7630
/* 7621 */    MCD::OPC_CheckPredicate, 18, 27, 26, // Skip to: 14308
/* 7625 */    MCD::OPC_Decode, 164, 11, 217, 1, // Opcode: MSUBV_B
/* 7630 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 7643
/* 7634 */    MCD::OPC_CheckPredicate, 18, 14, 26, // Skip to: 14308
/* 7638 */    MCD::OPC_Decode, 166, 11, 218, 1, // Opcode: MSUBV_H
/* 7643 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 7656
/* 7647 */    MCD::OPC_CheckPredicate, 18, 1, 26, // Skip to: 14308
/* 7651 */    MCD::OPC_Decode, 167, 11, 219, 1, // Opcode: MSUBV_W
/* 7656 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 7669
/* 7660 */    MCD::OPC_CheckPredicate, 18, 244, 25, // Skip to: 14308
/* 7664 */    MCD::OPC_Decode, 165, 11, 220, 1, // Opcode: MSUBV_D
/* 7669 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 7682
/* 7673 */    MCD::OPC_CheckPredicate, 18, 231, 25, // Skip to: 14308
/* 7677 */    MCD::OPC_Decode, 192, 5, 213, 1, // Opcode: DIV_S_B
/* 7682 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 7695
/* 7686 */    MCD::OPC_CheckPredicate, 18, 218, 25, // Skip to: 14308
/* 7690 */    MCD::OPC_Decode, 194, 5, 214, 1, // Opcode: DIV_S_H
/* 7695 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 7708
/* 7699 */    MCD::OPC_CheckPredicate, 18, 205, 25, // Skip to: 14308
/* 7703 */    MCD::OPC_Decode, 195, 5, 215, 1, // Opcode: DIV_S_W
/* 7708 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 7721
/* 7712 */    MCD::OPC_CheckPredicate, 18, 192, 25, // Skip to: 14308
/* 7716 */    MCD::OPC_Decode, 193, 5, 216, 1, // Opcode: DIV_S_D
/* 7721 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 7734
/* 7725 */    MCD::OPC_CheckPredicate, 18, 179, 25, // Skip to: 14308
/* 7729 */    MCD::OPC_Decode, 196, 5, 213, 1, // Opcode: DIV_U_B
/* 7734 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 7747
/* 7738 */    MCD::OPC_CheckPredicate, 18, 166, 25, // Skip to: 14308
/* 7742 */    MCD::OPC_Decode, 198, 5, 214, 1, // Opcode: DIV_U_H
/* 7747 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 7760
/* 7751 */    MCD::OPC_CheckPredicate, 18, 153, 25, // Skip to: 14308
/* 7755 */    MCD::OPC_Decode, 199, 5, 215, 1, // Opcode: DIV_U_W
/* 7760 */    MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 7773
/* 7764 */    MCD::OPC_CheckPredicate, 18, 140, 25, // Skip to: 14308
/* 7768 */    MCD::OPC_Decode, 197, 5, 216, 1, // Opcode: DIV_U_D
/* 7773 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 7786
/* 7777 */    MCD::OPC_CheckPredicate, 18, 127, 25, // Skip to: 14308
/* 7781 */    MCD::OPC_Decode, 229, 10, 213, 1, // Opcode: MOD_S_B
/* 7786 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 7799
/* 7790 */    MCD::OPC_CheckPredicate, 18, 114, 25, // Skip to: 14308
/* 7794 */    MCD::OPC_Decode, 231, 10, 214, 1, // Opcode: MOD_S_H
/* 7799 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 7812
/* 7803 */    MCD::OPC_CheckPredicate, 18, 101, 25, // Skip to: 14308
/* 7807 */    MCD::OPC_Decode, 232, 10, 215, 1, // Opcode: MOD_S_W
/* 7812 */    MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 7825
/* 7816 */    MCD::OPC_CheckPredicate, 18, 88, 25, // Skip to: 14308
/* 7820 */    MCD::OPC_Decode, 230, 10, 216, 1, // Opcode: MOD_S_D
/* 7825 */    MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 7838
/* 7829 */    MCD::OPC_CheckPredicate, 18, 75, 25, // Skip to: 14308
/* 7833 */    MCD::OPC_Decode, 233, 10, 213, 1, // Opcode: MOD_U_B
/* 7838 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 7851
/* 7842 */    MCD::OPC_CheckPredicate, 18, 62, 25, // Skip to: 14308
/* 7846 */    MCD::OPC_Decode, 235, 10, 214, 1, // Opcode: MOD_U_H
/* 7851 */    MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 7864
/* 7855 */    MCD::OPC_CheckPredicate, 18, 49, 25, // Skip to: 14308
/* 7859 */    MCD::OPC_Decode, 236, 10, 215, 1, // Opcode: MOD_U_W
/* 7864 */    MCD::OPC_FilterValue, 31, 40, 25, // Skip to: 14308
/* 7868 */    MCD::OPC_CheckPredicate, 18, 36, 25, // Skip to: 14308
/* 7872 */    MCD::OPC_Decode, 234, 10, 216, 1, // Opcode: MOD_U_D
/* 7877 */    MCD::OPC_FilterValue, 19, 237, 0, // Skip to: 8118
/* 7881 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 7884 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 7897
/* 7888 */    MCD::OPC_CheckPredicate, 18, 16, 25, // Skip to: 14308
/* 7892 */    MCD::OPC_Decode, 223, 5, 221, 1, // Opcode: DOTP_S_H
/* 7897 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 7910
/* 7901 */    MCD::OPC_CheckPredicate, 18, 3, 25, // Skip to: 14308
/* 7905 */    MCD::OPC_Decode, 224, 5, 222, 1, // Opcode: DOTP_S_W
/* 7910 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 7923
/* 7914 */    MCD::OPC_CheckPredicate, 18, 246, 24, // Skip to: 14308
/* 7918 */    MCD::OPC_Decode, 222, 5, 223, 1, // Opcode: DOTP_S_D
/* 7923 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 7936
/* 7927 */    MCD::OPC_CheckPredicate, 18, 233, 24, // Skip to: 14308
/* 7931 */    MCD::OPC_Decode, 226, 5, 221, 1, // Opcode: DOTP_U_H
/* 7936 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 7949
/* 7940 */    MCD::OPC_CheckPredicate, 18, 220, 24, // Skip to: 14308
/* 7944 */    MCD::OPC_Decode, 227, 5, 222, 1, // Opcode: DOTP_U_W
/* 7949 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 7962
/* 7953 */    MCD::OPC_CheckPredicate, 18, 207, 24, // Skip to: 14308
/* 7957 */    MCD::OPC_Decode, 225, 5, 223, 1, // Opcode: DOTP_U_D
/* 7962 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 7975
/* 7966 */    MCD::OPC_CheckPredicate, 18, 194, 24, // Skip to: 14308
/* 7970 */    MCD::OPC_Decode, 229, 5, 224, 1, // Opcode: DPADD_S_H
/* 7975 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 7988
/* 7979 */    MCD::OPC_CheckPredicate, 18, 181, 24, // Skip to: 14308
/* 7983 */    MCD::OPC_Decode, 230, 5, 225, 1, // Opcode: DPADD_S_W
/* 7988 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 8001
/* 7992 */    MCD::OPC_CheckPredicate, 18, 168, 24, // Skip to: 14308
/* 7996 */    MCD::OPC_Decode, 228, 5, 226, 1, // Opcode: DPADD_S_D
/* 8001 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 8014
/* 8005 */    MCD::OPC_CheckPredicate, 18, 155, 24, // Skip to: 14308
/* 8009 */    MCD::OPC_Decode, 232, 5, 224, 1, // Opcode: DPADD_U_H
/* 8014 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 8027
/* 8018 */    MCD::OPC_CheckPredicate, 18, 142, 24, // Skip to: 14308
/* 8022 */    MCD::OPC_Decode, 233, 5, 225, 1, // Opcode: DPADD_U_W
/* 8027 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 8040
/* 8031 */    MCD::OPC_CheckPredicate, 18, 129, 24, // Skip to: 14308
/* 8035 */    MCD::OPC_Decode, 231, 5, 226, 1, // Opcode: DPADD_U_D
/* 8040 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 8053
/* 8044 */    MCD::OPC_CheckPredicate, 18, 116, 24, // Skip to: 14308
/* 8048 */    MCD::OPC_Decode, 132, 6, 224, 1, // Opcode: DPSUB_S_H
/* 8053 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 8066
/* 8057 */    MCD::OPC_CheckPredicate, 18, 103, 24, // Skip to: 14308
/* 8061 */    MCD::OPC_Decode, 133, 6, 225, 1, // Opcode: DPSUB_S_W
/* 8066 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 8079
/* 8070 */    MCD::OPC_CheckPredicate, 18, 90, 24, // Skip to: 14308
/* 8074 */    MCD::OPC_Decode, 131, 6, 226, 1, // Opcode: DPSUB_S_D
/* 8079 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 8092
/* 8083 */    MCD::OPC_CheckPredicate, 18, 77, 24, // Skip to: 14308
/* 8087 */    MCD::OPC_Decode, 135, 6, 224, 1, // Opcode: DPSUB_U_H
/* 8092 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 8105
/* 8096 */    MCD::OPC_CheckPredicate, 18, 64, 24, // Skip to: 14308
/* 8100 */    MCD::OPC_Decode, 136, 6, 225, 1, // Opcode: DPSUB_U_W
/* 8105 */    MCD::OPC_FilterValue, 23, 55, 24, // Skip to: 14308
/* 8109 */    MCD::OPC_CheckPredicate, 18, 51, 24, // Skip to: 14308
/* 8113 */    MCD::OPC_Decode, 134, 6, 226, 1, // Opcode: DPSUB_U_D
/* 8118 */    MCD::OPC_FilterValue, 20, 163, 1, // Skip to: 8541
/* 8122 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 8125 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 8138
/* 8129 */    MCD::OPC_CheckPredicate, 18, 31, 24, // Skip to: 14308
/* 8133 */    MCD::OPC_Decode, 221, 14, 227, 1, // Opcode: SLD_B
/* 8138 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 8151
/* 8142 */    MCD::OPC_CheckPredicate, 18, 18, 24, // Skip to: 14308
/* 8146 */    MCD::OPC_Decode, 223, 14, 228, 1, // Opcode: SLD_H
/* 8151 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 8164
/* 8155 */    MCD::OPC_CheckPredicate, 18, 5, 24, // Skip to: 14308
/* 8159 */    MCD::OPC_Decode, 224, 14, 229, 1, // Opcode: SLD_W
/* 8164 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 8177
/* 8168 */    MCD::OPC_CheckPredicate, 18, 248, 23, // Skip to: 14308
/* 8172 */    MCD::OPC_Decode, 222, 14, 230, 1, // Opcode: SLD_D
/* 8177 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 8190
/* 8181 */    MCD::OPC_CheckPredicate, 18, 235, 23, // Skip to: 14308
/* 8185 */    MCD::OPC_Decode, 137, 15, 231, 1, // Opcode: SPLAT_B
/* 8190 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 8203
/* 8194 */    MCD::OPC_CheckPredicate, 18, 222, 23, // Skip to: 14308
/* 8198 */    MCD::OPC_Decode, 139, 15, 232, 1, // Opcode: SPLAT_H
/* 8203 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 8216
/* 8207 */    MCD::OPC_CheckPredicate, 18, 209, 23, // Skip to: 14308
/* 8211 */    MCD::OPC_Decode, 140, 15, 233, 1, // Opcode: SPLAT_W
/* 8216 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 8229
/* 8220 */    MCD::OPC_CheckPredicate, 18, 196, 23, // Skip to: 14308
/* 8224 */    MCD::OPC_Decode, 138, 15, 234, 1, // Opcode: SPLAT_D
/* 8229 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 8242
/* 8233 */    MCD::OPC_CheckPredicate, 18, 183, 23, // Skip to: 14308
/* 8237 */    MCD::OPC_Decode, 184, 12, 213, 1, // Opcode: PCKEV_B
/* 8242 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 8255
/* 8246 */    MCD::OPC_CheckPredicate, 18, 170, 23, // Skip to: 14308
/* 8250 */    MCD::OPC_Decode, 186, 12, 214, 1, // Opcode: PCKEV_H
/* 8255 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 8268
/* 8259 */    MCD::OPC_CheckPredicate, 18, 157, 23, // Skip to: 14308
/* 8263 */    MCD::OPC_Decode, 187, 12, 215, 1, // Opcode: PCKEV_W
/* 8268 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 8281
/* 8272 */    MCD::OPC_CheckPredicate, 18, 144, 23, // Skip to: 14308
/* 8276 */    MCD::OPC_Decode, 185, 12, 216, 1, // Opcode: PCKEV_D
/* 8281 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 8294
/* 8285 */    MCD::OPC_CheckPredicate, 18, 131, 23, // Skip to: 14308
/* 8289 */    MCD::OPC_Decode, 188, 12, 213, 1, // Opcode: PCKOD_B
/* 8294 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 8307
/* 8298 */    MCD::OPC_CheckPredicate, 18, 118, 23, // Skip to: 14308
/* 8302 */    MCD::OPC_Decode, 190, 12, 214, 1, // Opcode: PCKOD_H
/* 8307 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 8320
/* 8311 */    MCD::OPC_CheckPredicate, 18, 105, 23, // Skip to: 14308
/* 8315 */    MCD::OPC_Decode, 191, 12, 215, 1, // Opcode: PCKOD_W
/* 8320 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 8333
/* 8324 */    MCD::OPC_CheckPredicate, 18, 92, 23, // Skip to: 14308
/* 8328 */    MCD::OPC_Decode, 189, 12, 216, 1, // Opcode: PCKOD_D
/* 8333 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 8346
/* 8337 */    MCD::OPC_CheckPredicate, 18, 79, 23, // Skip to: 14308
/* 8341 */    MCD::OPC_Decode, 155, 8, 213, 1, // Opcode: ILVL_B
/* 8346 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 8359
/* 8350 */    MCD::OPC_CheckPredicate, 18, 66, 23, // Skip to: 14308
/* 8354 */    MCD::OPC_Decode, 157, 8, 214, 1, // Opcode: ILVL_H
/* 8359 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 8372
/* 8363 */    MCD::OPC_CheckPredicate, 18, 53, 23, // Skip to: 14308
/* 8367 */    MCD::OPC_Decode, 158, 8, 215, 1, // Opcode: ILVL_W
/* 8372 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 8385
/* 8376 */    MCD::OPC_CheckPredicate, 18, 40, 23, // Skip to: 14308
/* 8380 */    MCD::OPC_Decode, 156, 8, 216, 1, // Opcode: ILVL_D
/* 8385 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 8398
/* 8389 */    MCD::OPC_CheckPredicate, 18, 27, 23, // Skip to: 14308
/* 8393 */    MCD::OPC_Decode, 163, 8, 213, 1, // Opcode: ILVR_B
/* 8398 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 8411
/* 8402 */    MCD::OPC_CheckPredicate, 18, 14, 23, // Skip to: 14308
/* 8406 */    MCD::OPC_Decode, 165, 8, 214, 1, // Opcode: ILVR_H
/* 8411 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 8424
/* 8415 */    MCD::OPC_CheckPredicate, 18, 1, 23, // Skip to: 14308
/* 8419 */    MCD::OPC_Decode, 166, 8, 215, 1, // Opcode: ILVR_W
/* 8424 */    MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 8437
/* 8428 */    MCD::OPC_CheckPredicate, 18, 244, 22, // Skip to: 14308
/* 8432 */    MCD::OPC_Decode, 164, 8, 216, 1, // Opcode: ILVR_D
/* 8437 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 8450
/* 8441 */    MCD::OPC_CheckPredicate, 18, 231, 22, // Skip to: 14308
/* 8445 */    MCD::OPC_Decode, 151, 8, 213, 1, // Opcode: ILVEV_B
/* 8450 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 8463
/* 8454 */    MCD::OPC_CheckPredicate, 18, 218, 22, // Skip to: 14308
/* 8458 */    MCD::OPC_Decode, 153, 8, 214, 1, // Opcode: ILVEV_H
/* 8463 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 8476
/* 8467 */    MCD::OPC_CheckPredicate, 18, 205, 22, // Skip to: 14308
/* 8471 */    MCD::OPC_Decode, 154, 8, 215, 1, // Opcode: ILVEV_W
/* 8476 */    MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 8489
/* 8480 */    MCD::OPC_CheckPredicate, 18, 192, 22, // Skip to: 14308
/* 8484 */    MCD::OPC_Decode, 152, 8, 216, 1, // Opcode: ILVEV_D
/* 8489 */    MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 8502
/* 8493 */    MCD::OPC_CheckPredicate, 18, 179, 22, // Skip to: 14308
/* 8497 */    MCD::OPC_Decode, 159, 8, 213, 1, // Opcode: ILVOD_B
/* 8502 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 8515
/* 8506 */    MCD::OPC_CheckPredicate, 18, 166, 22, // Skip to: 14308
/* 8510 */    MCD::OPC_Decode, 161, 8, 214, 1, // Opcode: ILVOD_H
/* 8515 */    MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 8528
/* 8519 */    MCD::OPC_CheckPredicate, 18, 153, 22, // Skip to: 14308
/* 8523 */    MCD::OPC_Decode, 162, 8, 215, 1, // Opcode: ILVOD_W
/* 8528 */    MCD::OPC_FilterValue, 31, 144, 22, // Skip to: 14308
/* 8532 */    MCD::OPC_CheckPredicate, 18, 140, 22, // Skip to: 14308
/* 8536 */    MCD::OPC_Decode, 160, 8, 216, 1, // Opcode: ILVOD_D
/* 8541 */    MCD::OPC_FilterValue, 21, 59, 1, // Skip to: 8860
/* 8545 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 8548 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 8561
/* 8552 */    MCD::OPC_CheckPredicate, 18, 120, 22, // Skip to: 14308
/* 8556 */    MCD::OPC_Decode, 144, 17, 217, 1, // Opcode: VSHF_B
/* 8561 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 8574
/* 8565 */    MCD::OPC_CheckPredicate, 18, 107, 22, // Skip to: 14308
/* 8569 */    MCD::OPC_Decode, 146, 17, 218, 1, // Opcode: VSHF_H
/* 8574 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 8587
/* 8578 */    MCD::OPC_CheckPredicate, 18, 94, 22, // Skip to: 14308
/* 8582 */    MCD::OPC_Decode, 147, 17, 219, 1, // Opcode: VSHF_W
/* 8587 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 8600
/* 8591 */    MCD::OPC_CheckPredicate, 18, 81, 22, // Skip to: 14308
/* 8595 */    MCD::OPC_Decode, 145, 17, 220, 1, // Opcode: VSHF_D
/* 8600 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 8613
/* 8604 */    MCD::OPC_CheckPredicate, 18, 68, 22, // Skip to: 14308
/* 8608 */    MCD::OPC_Decode, 152, 15, 213, 1, // Opcode: SRAR_B
/* 8613 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 8626
/* 8617 */    MCD::OPC_CheckPredicate, 18, 55, 22, // Skip to: 14308
/* 8621 */    MCD::OPC_Decode, 154, 15, 214, 1, // Opcode: SRAR_H
/* 8626 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 8639
/* 8630 */    MCD::OPC_CheckPredicate, 18, 42, 22, // Skip to: 14308
/* 8634 */    MCD::OPC_Decode, 155, 15, 215, 1, // Opcode: SRAR_W
/* 8639 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 8652
/* 8643 */    MCD::OPC_CheckPredicate, 18, 29, 22, // Skip to: 14308
/* 8647 */    MCD::OPC_Decode, 153, 15, 216, 1, // Opcode: SRAR_D
/* 8652 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 8665
/* 8656 */    MCD::OPC_CheckPredicate, 18, 16, 22, // Skip to: 14308
/* 8660 */    MCD::OPC_Decode, 174, 15, 213, 1, // Opcode: SRLR_B
/* 8665 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 8678
/* 8669 */    MCD::OPC_CheckPredicate, 18, 3, 22, // Skip to: 14308
/* 8673 */    MCD::OPC_Decode, 176, 15, 214, 1, // Opcode: SRLR_H
/* 8678 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 8691
/* 8682 */    MCD::OPC_CheckPredicate, 18, 246, 21, // Skip to: 14308
/* 8686 */    MCD::OPC_Decode, 177, 15, 215, 1, // Opcode: SRLR_W
/* 8691 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 8704
/* 8695 */    MCD::OPC_CheckPredicate, 18, 233, 21, // Skip to: 14308
/* 8699 */    MCD::OPC_Decode, 175, 15, 216, 1, // Opcode: SRLR_D
/* 8704 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 8717
/* 8708 */    MCD::OPC_CheckPredicate, 18, 220, 21, // Skip to: 14308
/* 8712 */    MCD::OPC_Decode, 140, 8, 221, 1, // Opcode: HADD_S_H
/* 8717 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 8730
/* 8721 */    MCD::OPC_CheckPredicate, 18, 207, 21, // Skip to: 14308
/* 8725 */    MCD::OPC_Decode, 141, 8, 222, 1, // Opcode: HADD_S_W
/* 8730 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 8743
/* 8734 */    MCD::OPC_CheckPredicate, 18, 194, 21, // Skip to: 14308
/* 8738 */    MCD::OPC_Decode, 139, 8, 223, 1, // Opcode: HADD_S_D
/* 8743 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 8756
/* 8747 */    MCD::OPC_CheckPredicate, 18, 181, 21, // Skip to: 14308
/* 8751 */    MCD::OPC_Decode, 143, 8, 221, 1, // Opcode: HADD_U_H
/* 8756 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 8769
/* 8760 */    MCD::OPC_CheckPredicate, 18, 168, 21, // Skip to: 14308
/* 8764 */    MCD::OPC_Decode, 144, 8, 222, 1, // Opcode: HADD_U_W
/* 8769 */    MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 8782
/* 8773 */    MCD::OPC_CheckPredicate, 18, 155, 21, // Skip to: 14308
/* 8777 */    MCD::OPC_Decode, 142, 8, 223, 1, // Opcode: HADD_U_D
/* 8782 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 8795
/* 8786 */    MCD::OPC_CheckPredicate, 18, 142, 21, // Skip to: 14308
/* 8790 */    MCD::OPC_Decode, 146, 8, 221, 1, // Opcode: HSUB_S_H
/* 8795 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 8808
/* 8799 */    MCD::OPC_CheckPredicate, 18, 129, 21, // Skip to: 14308
/* 8803 */    MCD::OPC_Decode, 147, 8, 222, 1, // Opcode: HSUB_S_W
/* 8808 */    MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 8821
/* 8812 */    MCD::OPC_CheckPredicate, 18, 116, 21, // Skip to: 14308
/* 8816 */    MCD::OPC_Decode, 145, 8, 223, 1, // Opcode: HSUB_S_D
/* 8821 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 8834
/* 8825 */    MCD::OPC_CheckPredicate, 18, 103, 21, // Skip to: 14308
/* 8829 */    MCD::OPC_Decode, 149, 8, 221, 1, // Opcode: HSUB_U_H
/* 8834 */    MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 8847
/* 8838 */    MCD::OPC_CheckPredicate, 18, 90, 21, // Skip to: 14308
/* 8842 */    MCD::OPC_Decode, 150, 8, 222, 1, // Opcode: HSUB_U_W
/* 8847 */    MCD::OPC_FilterValue, 31, 81, 21, // Skip to: 14308
/* 8851 */    MCD::OPC_CheckPredicate, 18, 77, 21, // Skip to: 14308
/* 8855 */    MCD::OPC_Decode, 148, 8, 223, 1, // Opcode: HSUB_U_D
/* 8860 */    MCD::OPC_FilterValue, 25, 210, 1, // Skip to: 9330
/* 8864 */    MCD::OPC_ExtractField, 20, 6,  // Inst{25-20} ...
/* 8867 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 8880
/* 8871 */    MCD::OPC_CheckPredicate, 18, 57, 21, // Skip to: 14308
/* 8875 */    MCD::OPC_Decode, 217, 14, 235, 1, // Opcode: SLDI_B
/* 8880 */    MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 8899
/* 8884 */    MCD::OPC_CheckPredicate, 18, 44, 21, // Skip to: 14308
/* 8888 */    MCD::OPC_CheckField, 19, 1, 0, 38, 21, // Skip to: 14308
/* 8894 */    MCD::OPC_Decode, 219, 14, 236, 1, // Opcode: SLDI_H
/* 8899 */    MCD::OPC_FilterValue, 3, 54, 0, // Skip to: 8957
/* 8903 */    MCD::OPC_ExtractField, 18, 2,  // Inst{19-18} ...
/* 8906 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 8919
/* 8910 */    MCD::OPC_CheckPredicate, 18, 18, 21, // Skip to: 14308
/* 8914 */    MCD::OPC_Decode, 220, 14, 237, 1, // Opcode: SLDI_W
/* 8919 */    MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 8938
/* 8923 */    MCD::OPC_CheckPredicate, 18, 5, 21, // Skip to: 14308
/* 8927 */    MCD::OPC_CheckField, 17, 1, 0, 255, 20, // Skip to: 14308
/* 8933 */    MCD::OPC_Decode, 218, 14, 238, 1, // Opcode: SLDI_D
/* 8938 */    MCD::OPC_FilterValue, 3, 246, 20, // Skip to: 14308
/* 8942 */    MCD::OPC_CheckPredicate, 18, 242, 20, // Skip to: 14308
/* 8946 */    MCD::OPC_CheckField, 16, 2, 2, 236, 20, // Skip to: 14308
/* 8952 */    MCD::OPC_Decode, 198, 4, 239, 1, // Opcode: CTCMSA
/* 8957 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 8970
/* 8961 */    MCD::OPC_CheckPredicate, 18, 223, 20, // Skip to: 14308
/* 8965 */    MCD::OPC_Decode, 133, 15, 240, 1, // Opcode: SPLATI_B
/* 8970 */    MCD::OPC_FilterValue, 6, 15, 0, // Skip to: 8989
/* 8974 */    MCD::OPC_CheckPredicate, 18, 210, 20, // Skip to: 14308
/* 8978 */    MCD::OPC_CheckField, 19, 1, 0, 204, 20, // Skip to: 14308
/* 8984 */    MCD::OPC_Decode, 135, 15, 241, 1, // Opcode: SPLATI_H
/* 8989 */    MCD::OPC_FilterValue, 7, 54, 0, // Skip to: 9047
/* 8993 */    MCD::OPC_ExtractField, 18, 2,  // Inst{19-18} ...
/* 8996 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 9009
/* 9000 */    MCD::OPC_CheckPredicate, 18, 184, 20, // Skip to: 14308
/* 9004 */    MCD::OPC_Decode, 136, 15, 242, 1, // Opcode: SPLATI_W
/* 9009 */    MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 9028
/* 9013 */    MCD::OPC_CheckPredicate, 18, 171, 20, // Skip to: 14308
/* 9017 */    MCD::OPC_CheckField, 17, 1, 0, 165, 20, // Skip to: 14308
/* 9023 */    MCD::OPC_Decode, 134, 15, 243, 1, // Opcode: SPLATI_D
/* 9028 */    MCD::OPC_FilterValue, 3, 156, 20, // Skip to: 14308
/* 9032 */    MCD::OPC_CheckPredicate, 18, 152, 20, // Skip to: 14308
/* 9036 */    MCD::OPC_CheckField, 16, 2, 2, 146, 20, // Skip to: 14308
/* 9042 */    MCD::OPC_Decode, 191, 3, 244, 1, // Opcode: CFCMSA
/* 9047 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 9060
/* 9051 */    MCD::OPC_CheckPredicate, 18, 133, 20, // Skip to: 14308
/* 9055 */    MCD::OPC_Decode, 189, 4, 245, 1, // Opcode: COPY_S_B
/* 9060 */    MCD::OPC_FilterValue, 10, 15, 0, // Skip to: 9079
/* 9064 */    MCD::OPC_CheckPredicate, 18, 120, 20, // Skip to: 14308
/* 9068 */    MCD::OPC_CheckField, 19, 1, 0, 114, 20, // Skip to: 14308
/* 9074 */    MCD::OPC_Decode, 191, 4, 246, 1, // Opcode: COPY_S_H
/* 9079 */    MCD::OPC_FilterValue, 11, 54, 0, // Skip to: 9137
/* 9083 */    MCD::OPC_ExtractField, 18, 2,  // Inst{19-18} ...
/* 9086 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 9099
/* 9090 */    MCD::OPC_CheckPredicate, 18, 94, 20, // Skip to: 14308
/* 9094 */    MCD::OPC_Decode, 192, 4, 247, 1, // Opcode: COPY_S_W
/* 9099 */    MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 9118
/* 9103 */    MCD::OPC_CheckPredicate, 25, 81, 20, // Skip to: 14308
/* 9107 */    MCD::OPC_CheckField, 17, 1, 0, 75, 20, // Skip to: 14308
/* 9113 */    MCD::OPC_Decode, 190, 4, 248, 1, // Opcode: COPY_S_D
/* 9118 */    MCD::OPC_FilterValue, 3, 66, 20, // Skip to: 14308
/* 9122 */    MCD::OPC_CheckPredicate, 18, 62, 20, // Skip to: 14308
/* 9126 */    MCD::OPC_CheckField, 16, 2, 2, 56, 20, // Skip to: 14308
/* 9132 */    MCD::OPC_Decode, 240, 10, 249, 1, // Opcode: MOVE_V
/* 9137 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 9150
/* 9141 */    MCD::OPC_CheckPredicate, 18, 43, 20, // Skip to: 14308
/* 9145 */    MCD::OPC_Decode, 193, 4, 245, 1, // Opcode: COPY_U_B
/* 9150 */    MCD::OPC_FilterValue, 14, 15, 0, // Skip to: 9169
/* 9154 */    MCD::OPC_CheckPredicate, 18, 30, 20, // Skip to: 14308
/* 9158 */    MCD::OPC_CheckField, 19, 1, 0, 24, 20, // Skip to: 14308
/* 9164 */    MCD::OPC_Decode, 194, 4, 246, 1, // Opcode: COPY_U_H
/* 9169 */    MCD::OPC_FilterValue, 15, 15, 0, // Skip to: 9188
/* 9173 */    MCD::OPC_CheckPredicate, 25, 11, 20, // Skip to: 14308
/* 9177 */    MCD::OPC_CheckField, 18, 2, 0, 5, 20, // Skip to: 14308
/* 9183 */    MCD::OPC_Decode, 195, 4, 247, 1, // Opcode: COPY_U_W
/* 9188 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 9201
/* 9192 */    MCD::OPC_CheckPredicate, 18, 248, 19, // Skip to: 14308
/* 9196 */    MCD::OPC_Decode, 168, 8, 250, 1, // Opcode: INSERT_B
/* 9201 */    MCD::OPC_FilterValue, 18, 15, 0, // Skip to: 9220
/* 9205 */    MCD::OPC_CheckPredicate, 18, 235, 19, // Skip to: 14308
/* 9209 */    MCD::OPC_CheckField, 19, 1, 0, 229, 19, // Skip to: 14308
/* 9215 */    MCD::OPC_Decode, 180, 8, 251, 1, // Opcode: INSERT_H
/* 9220 */    MCD::OPC_FilterValue, 19, 35, 0, // Skip to: 9259
/* 9224 */    MCD::OPC_ExtractField, 18, 2,  // Inst{19-18} ...
/* 9227 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 9240
/* 9231 */    MCD::OPC_CheckPredicate, 18, 209, 19, // Skip to: 14308
/* 9235 */    MCD::OPC_Decode, 183, 8, 252, 1, // Opcode: INSERT_W
/* 9240 */    MCD::OPC_FilterValue, 2, 200, 19, // Skip to: 14308
/* 9244 */    MCD::OPC_CheckPredicate, 25, 196, 19, // Skip to: 14308
/* 9248 */    MCD::OPC_CheckField, 17, 1, 0, 190, 19, // Skip to: 14308
/* 9254 */    MCD::OPC_Decode, 171, 8, 253, 1, // Opcode: INSERT_D
/* 9259 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 9272
/* 9263 */    MCD::OPC_CheckPredicate, 18, 177, 19, // Skip to: 14308
/* 9267 */    MCD::OPC_Decode, 187, 8, 254, 1, // Opcode: INSVE_B
/* 9272 */    MCD::OPC_FilterValue, 22, 15, 0, // Skip to: 9291
/* 9276 */    MCD::OPC_CheckPredicate, 18, 164, 19, // Skip to: 14308
/* 9280 */    MCD::OPC_CheckField, 19, 1, 0, 158, 19, // Skip to: 14308
/* 9286 */    MCD::OPC_Decode, 189, 8, 254, 1, // Opcode: INSVE_H
/* 9291 */    MCD::OPC_FilterValue, 23, 149, 19, // Skip to: 14308
/* 9295 */    MCD::OPC_ExtractField, 18, 2,  // Inst{19-18} ...
/* 9298 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 9311
/* 9302 */    MCD::OPC_CheckPredicate, 18, 138, 19, // Skip to: 14308
/* 9306 */    MCD::OPC_Decode, 190, 8, 254, 1, // Opcode: INSVE_W
/* 9311 */    MCD::OPC_FilterValue, 2, 129, 19, // Skip to: 14308
/* 9315 */    MCD::OPC_CheckPredicate, 18, 125, 19, // Skip to: 14308
/* 9319 */    MCD::OPC_CheckField, 17, 1, 0, 119, 19, // Skip to: 14308
/* 9325 */    MCD::OPC_Decode, 188, 8, 254, 1, // Opcode: INSVE_D
/* 9330 */    MCD::OPC_FilterValue, 26, 163, 1, // Skip to: 9753
/* 9334 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 9337 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 9350
/* 9341 */    MCD::OPC_CheckPredicate, 18, 99, 19, // Skip to: 14308
/* 9345 */    MCD::OPC_Decode, 231, 6, 215, 1, // Opcode: FCAF_W
/* 9350 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 9363
/* 9354 */    MCD::OPC_CheckPredicate, 18, 86, 19, // Skip to: 14308
/* 9358 */    MCD::OPC_Decode, 230, 6, 216, 1, // Opcode: FCAF_D
/* 9363 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 9376
/* 9367 */    MCD::OPC_CheckPredicate, 18, 73, 19, // Skip to: 14308
/* 9371 */    MCD::OPC_Decode, 130, 7, 215, 1, // Opcode: FCUN_W
/* 9376 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 9389
/* 9380 */    MCD::OPC_CheckPredicate, 18, 60, 19, // Skip to: 14308
/* 9384 */    MCD::OPC_Decode, 129, 7, 216, 1, // Opcode: FCUN_D
/* 9389 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 9402
/* 9393 */    MCD::OPC_CheckPredicate, 18, 47, 19, // Skip to: 14308
/* 9397 */    MCD::OPC_Decode, 233, 6, 215, 1, // Opcode: FCEQ_W
/* 9402 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 9415
/* 9406 */    MCD::OPC_CheckPredicate, 18, 34, 19, // Skip to: 14308
/* 9410 */    MCD::OPC_Decode, 232, 6, 216, 1, // Opcode: FCEQ_D
/* 9415 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 9428
/* 9419 */    MCD::OPC_CheckPredicate, 18, 21, 19, // Skip to: 14308
/* 9423 */    MCD::OPC_Decode, 250, 6, 215, 1, // Opcode: FCUEQ_W
/* 9428 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 9441
/* 9432 */    MCD::OPC_CheckPredicate, 18, 8, 19, // Skip to: 14308
/* 9436 */    MCD::OPC_Decode, 249, 6, 216, 1, // Opcode: FCUEQ_D
/* 9441 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 9454
/* 9445 */    MCD::OPC_CheckPredicate, 18, 251, 18, // Skip to: 14308
/* 9449 */    MCD::OPC_Decode, 239, 6, 215, 1, // Opcode: FCLT_W
/* 9454 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 9467
/* 9458 */    MCD::OPC_CheckPredicate, 18, 238, 18, // Skip to: 14308
/* 9462 */    MCD::OPC_Decode, 238, 6, 216, 1, // Opcode: FCLT_D
/* 9467 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 9480
/* 9471 */    MCD::OPC_CheckPredicate, 18, 225, 18, // Skip to: 14308
/* 9475 */    MCD::OPC_Decode, 254, 6, 215, 1, // Opcode: FCULT_W
/* 9480 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 9493
/* 9484 */    MCD::OPC_CheckPredicate, 18, 212, 18, // Skip to: 14308
/* 9488 */    MCD::OPC_Decode, 253, 6, 216, 1, // Opcode: FCULT_D
/* 9493 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 9506
/* 9497 */    MCD::OPC_CheckPredicate, 18, 199, 18, // Skip to: 14308
/* 9501 */    MCD::OPC_Decode, 237, 6, 215, 1, // Opcode: FCLE_W
/* 9506 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 9519
/* 9510 */    MCD::OPC_CheckPredicate, 18, 186, 18, // Skip to: 14308
/* 9514 */    MCD::OPC_Decode, 236, 6, 216, 1, // Opcode: FCLE_D
/* 9519 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 9532
/* 9523 */    MCD::OPC_CheckPredicate, 18, 173, 18, // Skip to: 14308
/* 9527 */    MCD::OPC_Decode, 252, 6, 215, 1, // Opcode: FCULE_W
/* 9532 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 9545
/* 9536 */    MCD::OPC_CheckPredicate, 18, 160, 18, // Skip to: 14308
/* 9540 */    MCD::OPC_Decode, 251, 6, 216, 1, // Opcode: FCULE_D
/* 9545 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 9558
/* 9549 */    MCD::OPC_CheckPredicate, 18, 147, 18, // Skip to: 14308
/* 9553 */    MCD::OPC_Decode, 219, 7, 215, 1, // Opcode: FSAF_W
/* 9558 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 9571
/* 9562 */    MCD::OPC_CheckPredicate, 18, 134, 18, // Skip to: 14308
/* 9566 */    MCD::OPC_Decode, 218, 7, 216, 1, // Opcode: FSAF_D
/* 9571 */    MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 9584
/* 9575 */    MCD::OPC_CheckPredicate, 18, 121, 18, // Skip to: 14308
/* 9579 */    MCD::OPC_Decode, 255, 7, 215, 1, // Opcode: FSUN_W
/* 9584 */    MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 9597
/* 9588 */    MCD::OPC_CheckPredicate, 18, 108, 18, // Skip to: 14308
/* 9592 */    MCD::OPC_Decode, 254, 7, 216, 1, // Opcode: FSUN_D
/* 9597 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 9610
/* 9601 */    MCD::OPC_CheckPredicate, 18, 95, 18, // Skip to: 14308
/* 9605 */    MCD::OPC_Decode, 221, 7, 215, 1, // Opcode: FSEQ_W
/* 9610 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 9623
/* 9614 */    MCD::OPC_CheckPredicate, 18, 82, 18, // Skip to: 14308
/* 9618 */    MCD::OPC_Decode, 220, 7, 216, 1, // Opcode: FSEQ_D
/* 9623 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 9636
/* 9627 */    MCD::OPC_CheckPredicate, 18, 69, 18, // Skip to: 14308
/* 9631 */    MCD::OPC_Decode, 247, 7, 215, 1, // Opcode: FSUEQ_W
/* 9636 */    MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 9649
/* 9640 */    MCD::OPC_CheckPredicate, 18, 56, 18, // Skip to: 14308
/* 9644 */    MCD::OPC_Decode, 246, 7, 216, 1, // Opcode: FSUEQ_D
/* 9649 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 9662
/* 9653 */    MCD::OPC_CheckPredicate, 18, 43, 18, // Skip to: 14308
/* 9657 */    MCD::OPC_Decode, 225, 7, 215, 1, // Opcode: FSLT_W
/* 9662 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 9675
/* 9666 */    MCD::OPC_CheckPredicate, 18, 30, 18, // Skip to: 14308
/* 9670 */    MCD::OPC_Decode, 224, 7, 216, 1, // Opcode: FSLT_D
/* 9675 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 9688
/* 9679 */    MCD::OPC_CheckPredicate, 18, 17, 18, // Skip to: 14308
/* 9683 */    MCD::OPC_Decode, 251, 7, 215, 1, // Opcode: FSULT_W
/* 9688 */    MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 9701
/* 9692 */    MCD::OPC_CheckPredicate, 18, 4, 18, // Skip to: 14308
/* 9696 */    MCD::OPC_Decode, 250, 7, 216, 1, // Opcode: FSULT_D
/* 9701 */    MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 9714
/* 9705 */    MCD::OPC_CheckPredicate, 18, 247, 17, // Skip to: 14308
/* 9709 */    MCD::OPC_Decode, 223, 7, 215, 1, // Opcode: FSLE_W
/* 9714 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 9727
/* 9718 */    MCD::OPC_CheckPredicate, 18, 234, 17, // Skip to: 14308
/* 9722 */    MCD::OPC_Decode, 222, 7, 216, 1, // Opcode: FSLE_D
/* 9727 */    MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 9740
/* 9731 */    MCD::OPC_CheckPredicate, 18, 221, 17, // Skip to: 14308
/* 9735 */    MCD::OPC_Decode, 249, 7, 215, 1, // Opcode: FSULE_W
/* 9740 */    MCD::OPC_FilterValue, 31, 212, 17, // Skip to: 14308
/* 9744 */    MCD::OPC_CheckPredicate, 18, 208, 17, // Skip to: 14308
/* 9748 */    MCD::OPC_Decode, 248, 7, 216, 1, // Opcode: FSULE_D
/* 9753 */    MCD::OPC_FilterValue, 27, 85, 1, // Skip to: 10098
/* 9757 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 9760 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 9773
/* 9764 */    MCD::OPC_CheckPredicate, 18, 188, 17, // Skip to: 14308
/* 9768 */    MCD::OPC_Decode, 229, 6, 215, 1, // Opcode: FADD_W
/* 9773 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 9786
/* 9777 */    MCD::OPC_CheckPredicate, 18, 175, 17, // Skip to: 14308
/* 9781 */    MCD::OPC_Decode, 221, 6, 216, 1, // Opcode: FADD_D
/* 9786 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 9799
/* 9790 */    MCD::OPC_CheckPredicate, 18, 162, 17, // Skip to: 14308
/* 9794 */    MCD::OPC_Decode, 245, 7, 215, 1, // Opcode: FSUB_W
/* 9799 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 9812
/* 9803 */    MCD::OPC_CheckPredicate, 18, 149, 17, // Skip to: 14308
/* 9807 */    MCD::OPC_Decode, 237, 7, 216, 1, // Opcode: FSUB_D
/* 9812 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 9825
/* 9816 */    MCD::OPC_CheckPredicate, 18, 136, 17, // Skip to: 14308
/* 9820 */    MCD::OPC_Decode, 204, 7, 215, 1, // Opcode: FMUL_W
/* 9825 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 9838
/* 9829 */    MCD::OPC_CheckPredicate, 18, 123, 17, // Skip to: 14308
/* 9833 */    MCD::OPC_Decode, 196, 7, 216, 1, // Opcode: FMUL_D
/* 9838 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 9851
/* 9842 */    MCD::OPC_CheckPredicate, 18, 110, 17, // Skip to: 14308
/* 9846 */    MCD::OPC_Decode, 139, 7, 215, 1, // Opcode: FDIV_W
/* 9851 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 9864
/* 9855 */    MCD::OPC_CheckPredicate, 18, 97, 17, // Skip to: 14308
/* 9859 */    MCD::OPC_Decode, 131, 7, 216, 1, // Opcode: FDIV_D
/* 9864 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 9877
/* 9868 */    MCD::OPC_CheckPredicate, 18, 84, 17, // Skip to: 14308
/* 9872 */    MCD::OPC_Decode, 178, 7, 219, 1, // Opcode: FMADD_W
/* 9877 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 9890
/* 9881 */    MCD::OPC_CheckPredicate, 18, 71, 17, // Skip to: 14308
/* 9885 */    MCD::OPC_Decode, 177, 7, 220, 1, // Opcode: FMADD_D
/* 9890 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 9903
/* 9894 */    MCD::OPC_CheckPredicate, 18, 58, 17, // Skip to: 14308
/* 9898 */    MCD::OPC_Decode, 195, 7, 219, 1, // Opcode: FMSUB_W
/* 9903 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 9916
/* 9907 */    MCD::OPC_CheckPredicate, 18, 45, 17, // Skip to: 14308
/* 9911 */    MCD::OPC_Decode, 194, 7, 220, 1, // Opcode: FMSUB_D
/* 9916 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 9929
/* 9920 */    MCD::OPC_CheckPredicate, 18, 32, 17, // Skip to: 14308
/* 9924 */    MCD::OPC_Decode, 144, 7, 215, 1, // Opcode: FEXP2_W
/* 9929 */    MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 9942
/* 9933 */    MCD::OPC_CheckPredicate, 18, 19, 17, // Skip to: 14308
/* 9937 */    MCD::OPC_Decode, 142, 7, 216, 1, // Opcode: FEXP2_D
/* 9942 */    MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 9955
/* 9946 */    MCD::OPC_CheckPredicate, 18, 6, 17, // Skip to: 14308
/* 9950 */    MCD::OPC_Decode, 140, 7, 255, 1, // Opcode: FEXDO_H
/* 9955 */    MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 9968
/* 9959 */    MCD::OPC_CheckPredicate, 18, 249, 16, // Skip to: 14308
/* 9963 */    MCD::OPC_Decode, 141, 7, 128, 2, // Opcode: FEXDO_W
/* 9968 */    MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 9981
/* 9972 */    MCD::OPC_CheckPredicate, 18, 236, 16, // Skip to: 14308
/* 9976 */    MCD::OPC_Decode, 132, 8, 255, 1, // Opcode: FTQ_H
/* 9981 */    MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 9994
/* 9985 */    MCD::OPC_CheckPredicate, 18, 223, 16, // Skip to: 14308
/* 9989 */    MCD::OPC_Decode, 133, 8, 128, 2, // Opcode: FTQ_W
/* 9994 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 10007
/* 9998 */    MCD::OPC_CheckPredicate, 18, 210, 16, // Skip to: 14308
/* 10002 */   MCD::OPC_Decode, 186, 7, 215, 1, // Opcode: FMIN_W
/* 10007 */   MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 10020
/* 10011 */   MCD::OPC_CheckPredicate, 18, 197, 16, // Skip to: 14308
/* 10015 */   MCD::OPC_Decode, 185, 7, 216, 1, // Opcode: FMIN_D
/* 10020 */   MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 10033
/* 10024 */   MCD::OPC_CheckPredicate, 18, 184, 16, // Skip to: 14308
/* 10028 */   MCD::OPC_Decode, 184, 7, 215, 1, // Opcode: FMIN_A_W
/* 10033 */   MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 10046
/* 10037 */   MCD::OPC_CheckPredicate, 18, 171, 16, // Skip to: 14308
/* 10041 */   MCD::OPC_Decode, 183, 7, 216, 1, // Opcode: FMIN_A_D
/* 10046 */   MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 10059
/* 10050 */   MCD::OPC_CheckPredicate, 18, 158, 16, // Skip to: 14308
/* 10054 */   MCD::OPC_Decode, 182, 7, 215, 1, // Opcode: FMAX_W
/* 10059 */   MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 10072
/* 10063 */   MCD::OPC_CheckPredicate, 18, 145, 16, // Skip to: 14308
/* 10067 */   MCD::OPC_Decode, 181, 7, 216, 1, // Opcode: FMAX_D
/* 10072 */   MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 10085
/* 10076 */   MCD::OPC_CheckPredicate, 18, 132, 16, // Skip to: 14308
/* 10080 */   MCD::OPC_Decode, 180, 7, 215, 1, // Opcode: FMAX_A_W
/* 10085 */   MCD::OPC_FilterValue, 31, 123, 16, // Skip to: 14308
/* 10089 */   MCD::OPC_CheckPredicate, 18, 119, 16, // Skip to: 14308
/* 10093 */   MCD::OPC_Decode, 179, 7, 216, 1, // Opcode: FMAX_A_D
/* 10098 */   MCD::OPC_FilterValue, 28, 59, 1, // Skip to: 10417
/* 10102 */   MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 10105 */   MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 10118
/* 10109 */   MCD::OPC_CheckPredicate, 18, 99, 16, // Skip to: 14308
/* 10113 */   MCD::OPC_Decode, 248, 6, 215, 1, // Opcode: FCOR_W
/* 10118 */   MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 10131
/* 10122 */   MCD::OPC_CheckPredicate, 18, 86, 16, // Skip to: 14308
/* 10126 */   MCD::OPC_Decode, 247, 6, 216, 1, // Opcode: FCOR_D
/* 10131 */   MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 10144
/* 10135 */   MCD::OPC_CheckPredicate, 18, 73, 16, // Skip to: 14308
/* 10139 */   MCD::OPC_Decode, 128, 7, 215, 1, // Opcode: FCUNE_W
/* 10144 */   MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 10157
/* 10148 */   MCD::OPC_CheckPredicate, 18, 60, 16, // Skip to: 14308
/* 10152 */   MCD::OPC_Decode, 255, 6, 216, 1, // Opcode: FCUNE_D
/* 10157 */   MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 10170
/* 10161 */   MCD::OPC_CheckPredicate, 18, 47, 16, // Skip to: 14308
/* 10165 */   MCD::OPC_Decode, 246, 6, 215, 1, // Opcode: FCNE_W
/* 10170 */   MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 10183
/* 10174 */   MCD::OPC_CheckPredicate, 18, 34, 16, // Skip to: 14308
/* 10178 */   MCD::OPC_Decode, 245, 6, 216, 1, // Opcode: FCNE_D
/* 10183 */   MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 10196
/* 10187 */   MCD::OPC_CheckPredicate, 18, 21, 16, // Skip to: 14308
/* 10191 */   MCD::OPC_Decode, 246, 11, 214, 1, // Opcode: MUL_Q_H
/* 10196 */   MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 10209
/* 10200 */   MCD::OPC_CheckPredicate, 18, 8, 16, // Skip to: 14308
/* 10204 */   MCD::OPC_Decode, 247, 11, 215, 1, // Opcode: MUL_Q_W
/* 10209 */   MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 10222
/* 10213 */   MCD::OPC_CheckPredicate, 18, 251, 15, // Skip to: 14308
/* 10217 */   MCD::OPC_Decode, 135, 10, 218, 1, // Opcode: MADD_Q_H
/* 10222 */   MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 10235
/* 10226 */   MCD::OPC_CheckPredicate, 18, 238, 15, // Skip to: 14308
/* 10230 */   MCD::OPC_Decode, 136, 10, 219, 1, // Opcode: MADD_Q_W
/* 10235 */   MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 10248
/* 10239 */   MCD::OPC_CheckPredicate, 18, 225, 15, // Skip to: 14308
/* 10243 */   MCD::OPC_Decode, 174, 11, 218, 1, // Opcode: MSUB_Q_H
/* 10248 */   MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 10261
/* 10252 */   MCD::OPC_CheckPredicate, 18, 212, 15, // Skip to: 14308
/* 10256 */   MCD::OPC_Decode, 175, 11, 219, 1, // Opcode: MSUB_Q_W
/* 10261 */   MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 10274
/* 10265 */   MCD::OPC_CheckPredicate, 18, 199, 15, // Skip to: 14308
/* 10269 */   MCD::OPC_Decode, 229, 7, 215, 1, // Opcode: FSOR_W
/* 10274 */   MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 10287
/* 10278 */   MCD::OPC_CheckPredicate, 18, 186, 15, // Skip to: 14308
/* 10282 */   MCD::OPC_Decode, 228, 7, 216, 1, // Opcode: FSOR_D
/* 10287 */   MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 10300
/* 10291 */   MCD::OPC_CheckPredicate, 18, 173, 15, // Skip to: 14308
/* 10295 */   MCD::OPC_Decode, 253, 7, 215, 1, // Opcode: FSUNE_W
/* 10300 */   MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 10313
/* 10304 */   MCD::OPC_CheckPredicate, 18, 160, 15, // Skip to: 14308
/* 10308 */   MCD::OPC_Decode, 252, 7, 216, 1, // Opcode: FSUNE_D
/* 10313 */   MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 10326
/* 10317 */   MCD::OPC_CheckPredicate, 18, 147, 15, // Skip to: 14308
/* 10321 */   MCD::OPC_Decode, 227, 7, 215, 1, // Opcode: FSNE_W
/* 10326 */   MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 10339
/* 10330 */   MCD::OPC_CheckPredicate, 18, 134, 15, // Skip to: 14308
/* 10334 */   MCD::OPC_Decode, 226, 7, 216, 1, // Opcode: FSNE_D
/* 10339 */   MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 10352
/* 10343 */   MCD::OPC_CheckPredicate, 18, 121, 15, // Skip to: 14308
/* 10347 */   MCD::OPC_Decode, 224, 11, 214, 1, // Opcode: MULR_Q_H
/* 10352 */   MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 10365
/* 10356 */   MCD::OPC_CheckPredicate, 18, 108, 15, // Skip to: 14308
/* 10360 */   MCD::OPC_Decode, 225, 11, 215, 1, // Opcode: MULR_Q_W
/* 10365 */   MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 10378
/* 10369 */   MCD::OPC_CheckPredicate, 18, 95, 15, // Skip to: 14308
/* 10373 */   MCD::OPC_Decode, 247, 9, 218, 1, // Opcode: MADDR_Q_H
/* 10378 */   MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 10391
/* 10382 */   MCD::OPC_CheckPredicate, 18, 82, 15, // Skip to: 14308
/* 10386 */   MCD::OPC_Decode, 248, 9, 219, 1, // Opcode: MADDR_Q_W
/* 10391 */   MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 10404
/* 10395 */   MCD::OPC_CheckPredicate, 18, 69, 15, // Skip to: 14308
/* 10399 */   MCD::OPC_Decode, 158, 11, 218, 1, // Opcode: MSUBR_Q_H
/* 10404 */   MCD::OPC_FilterValue, 29, 60, 15, // Skip to: 14308
/* 10408 */   MCD::OPC_CheckPredicate, 18, 56, 15, // Skip to: 14308
/* 10412 */   MCD::OPC_Decode, 159, 11, 219, 1, // Opcode: MSUBR_Q_W
/* 10417 */   MCD::OPC_FilterValue, 30, 219, 2, // Skip to: 11152
/* 10421 */   MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 10424 */   MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 10436
/* 10428 */   MCD::OPC_CheckPredicate, 18, 36, 15, // Skip to: 14308
/* 10432 */   MCD::OPC_Decode, 121, 213, 1, // Opcode: AND_V
/* 10436 */   MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 10449
/* 10440 */   MCD::OPC_CheckPredicate, 18, 24, 15, // Skip to: 14308
/* 10444 */   MCD::OPC_Decode, 172, 12, 213, 1, // Opcode: OR_V
/* 10449 */   MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 10462
/* 10453 */   MCD::OPC_CheckPredicate, 18, 11, 15, // Skip to: 14308
/* 10457 */   MCD::OPC_Decode, 156, 12, 213, 1, // Opcode: NOR_V
/* 10462 */   MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 10475
/* 10466 */   MCD::OPC_CheckPredicate, 18, 254, 14, // Skip to: 14308
/* 10470 */   MCD::OPC_Decode, 164, 17, 213, 1, // Opcode: XOR_V
/* 10475 */   MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 10488
/* 10479 */   MCD::OPC_CheckPredicate, 18, 241, 14, // Skip to: 14308
/* 10483 */   MCD::OPC_Decode, 206, 2, 217, 1, // Opcode: BMNZ_V
/* 10488 */   MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 10501
/* 10492 */   MCD::OPC_CheckPredicate, 18, 228, 14, // Skip to: 14308
/* 10496 */   MCD::OPC_Decode, 208, 2, 217, 1, // Opcode: BMZ_V
/* 10501 */   MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 10514
/* 10505 */   MCD::OPC_CheckPredicate, 18, 215, 14, // Skip to: 14308
/* 10509 */   MCD::OPC_Decode, 247, 2, 217, 1, // Opcode: BSEL_V
/* 10514 */   MCD::OPC_FilterValue, 24, 211, 0, // Skip to: 10729
/* 10518 */   MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 10521 */   MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 10534
/* 10525 */   MCD::OPC_CheckPredicate, 18, 195, 14, // Skip to: 14308
/* 10529 */   MCD::OPC_Decode, 158, 7, 129, 2, // Opcode: FILL_B
/* 10534 */   MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 10547
/* 10538 */   MCD::OPC_CheckPredicate, 18, 182, 14, // Skip to: 14308
/* 10542 */   MCD::OPC_Decode, 162, 7, 130, 2, // Opcode: FILL_H
/* 10547 */   MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 10560
/* 10551 */   MCD::OPC_CheckPredicate, 18, 169, 14, // Skip to: 14308
/* 10555 */   MCD::OPC_Decode, 163, 7, 131, 2, // Opcode: FILL_W
/* 10560 */   MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 10573
/* 10564 */   MCD::OPC_CheckPredicate, 25, 156, 14, // Skip to: 14308
/* 10568 */   MCD::OPC_Decode, 159, 7, 132, 2, // Opcode: FILL_D
/* 10573 */   MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 10586
/* 10577 */   MCD::OPC_CheckPredicate, 18, 143, 14, // Skip to: 14308
/* 10581 */   MCD::OPC_Decode, 192, 12, 249, 1, // Opcode: PCNT_B
/* 10586 */   MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 10599
/* 10590 */   MCD::OPC_CheckPredicate, 18, 130, 14, // Skip to: 14308
/* 10594 */   MCD::OPC_Decode, 194, 12, 133, 2, // Opcode: PCNT_H
/* 10599 */   MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 10612
/* 10603 */   MCD::OPC_CheckPredicate, 18, 117, 14, // Skip to: 14308
/* 10607 */   MCD::OPC_Decode, 195, 12, 134, 2, // Opcode: PCNT_W
/* 10612 */   MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 10625
/* 10616 */   MCD::OPC_CheckPredicate, 18, 104, 14, // Skip to: 14308
/* 10620 */   MCD::OPC_Decode, 193, 12, 135, 2, // Opcode: PCNT_D
/* 10625 */   MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 10638
/* 10629 */   MCD::OPC_CheckPredicate, 18, 91, 14, // Skip to: 14308
/* 10633 */   MCD::OPC_Decode, 131, 12, 249, 1, // Opcode: NLOC_B
/* 10638 */   MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 10651
/* 10642 */   MCD::OPC_CheckPredicate, 18, 78, 14, // Skip to: 14308
/* 10646 */   MCD::OPC_Decode, 133, 12, 133, 2, // Opcode: NLOC_H
/* 10651 */   MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 10664
/* 10655 */   MCD::OPC_CheckPredicate, 18, 65, 14, // Skip to: 14308
/* 10659 */   MCD::OPC_Decode, 134, 12, 134, 2, // Opcode: NLOC_W
/* 10664 */   MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 10677
/* 10668 */   MCD::OPC_CheckPredicate, 18, 52, 14, // Skip to: 14308
/* 10672 */   MCD::OPC_Decode, 132, 12, 135, 2, // Opcode: NLOC_D
/* 10677 */   MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 10690
/* 10681 */   MCD::OPC_CheckPredicate, 18, 39, 14, // Skip to: 14308
/* 10685 */   MCD::OPC_Decode, 135, 12, 249, 1, // Opcode: NLZC_B
/* 10690 */   MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 10703
/* 10694 */   MCD::OPC_CheckPredicate, 18, 26, 14, // Skip to: 14308
/* 10698 */   MCD::OPC_Decode, 137, 12, 133, 2, // Opcode: NLZC_H
/* 10703 */   MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 10716
/* 10707 */   MCD::OPC_CheckPredicate, 18, 13, 14, // Skip to: 14308
/* 10711 */   MCD::OPC_Decode, 138, 12, 134, 2, // Opcode: NLZC_W
/* 10716 */   MCD::OPC_FilterValue, 15, 4, 14, // Skip to: 14308
/* 10720 */   MCD::OPC_CheckPredicate, 18, 0, 14, // Skip to: 14308
/* 10724 */   MCD::OPC_Decode, 136, 12, 135, 2, // Opcode: NLZC_D
/* 10729 */   MCD::OPC_FilterValue, 25, 247, 13, // Skip to: 14308
/* 10733 */   MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 10736 */   MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 10749
/* 10740 */   MCD::OPC_CheckPredicate, 18, 236, 13, // Skip to: 14308
/* 10744 */   MCD::OPC_Decode, 235, 6, 134, 2, // Opcode: FCLASS_W
/* 10749 */   MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 10762
/* 10753 */   MCD::OPC_CheckPredicate, 18, 223, 13, // Skip to: 14308
/* 10757 */   MCD::OPC_Decode, 234, 6, 135, 2, // Opcode: FCLASS_D
/* 10762 */   MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 10775
/* 10766 */   MCD::OPC_CheckPredicate, 18, 210, 13, // Skip to: 14308
/* 10770 */   MCD::OPC_Decode, 135, 8, 134, 2, // Opcode: FTRUNC_S_W
/* 10775 */   MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 10788
/* 10779 */   MCD::OPC_CheckPredicate, 18, 197, 13, // Skip to: 14308
/* 10783 */   MCD::OPC_Decode, 134, 8, 135, 2, // Opcode: FTRUNC_S_D
/* 10788 */   MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 10801
/* 10792 */   MCD::OPC_CheckPredicate, 18, 184, 13, // Skip to: 14308
/* 10796 */   MCD::OPC_Decode, 137, 8, 134, 2, // Opcode: FTRUNC_U_W
/* 10801 */   MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 10814
/* 10805 */   MCD::OPC_CheckPredicate, 18, 171, 13, // Skip to: 14308
/* 10809 */   MCD::OPC_Decode, 136, 8, 135, 2, // Opcode: FTRUNC_U_D
/* 10814 */   MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 10827
/* 10818 */   MCD::OPC_CheckPredicate, 18, 158, 13, // Skip to: 14308
/* 10822 */   MCD::OPC_Decode, 236, 7, 134, 2, // Opcode: FSQRT_W
/* 10827 */   MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 10840
/* 10831 */   MCD::OPC_CheckPredicate, 18, 145, 13, // Skip to: 14308
/* 10835 */   MCD::OPC_Decode, 230, 7, 135, 2, // Opcode: FSQRT_D
/* 10840 */   MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 10853
/* 10844 */   MCD::OPC_CheckPredicate, 18, 132, 13, // Skip to: 14308
/* 10848 */   MCD::OPC_Decode, 217, 7, 134, 2, // Opcode: FRSQRT_W
/* 10853 */   MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 10866
/* 10857 */   MCD::OPC_CheckPredicate, 18, 119, 13, // Skip to: 14308
/* 10861 */   MCD::OPC_Decode, 216, 7, 135, 2, // Opcode: FRSQRT_D
/* 10866 */   MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 10879
/* 10870 */   MCD::OPC_CheckPredicate, 18, 106, 13, // Skip to: 14308
/* 10874 */   MCD::OPC_Decode, 213, 7, 134, 2, // Opcode: FRCP_W
/* 10879 */   MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 10892
/* 10883 */   MCD::OPC_CheckPredicate, 18, 93, 13, // Skip to: 14308
/* 10887 */   MCD::OPC_Decode, 212, 7, 135, 2, // Opcode: FRCP_D
/* 10892 */   MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 10905
/* 10896 */   MCD::OPC_CheckPredicate, 18, 80, 13, // Skip to: 14308
/* 10900 */   MCD::OPC_Decode, 215, 7, 134, 2, // Opcode: FRINT_W
/* 10905 */   MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 10918
/* 10909 */   MCD::OPC_CheckPredicate, 18, 67, 13, // Skip to: 14308
/* 10913 */   MCD::OPC_Decode, 214, 7, 135, 2, // Opcode: FRINT_D
/* 10918 */   MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 10931
/* 10922 */   MCD::OPC_CheckPredicate, 18, 54, 13, // Skip to: 14308
/* 10926 */   MCD::OPC_Decode, 165, 7, 134, 2, // Opcode: FLOG2_W
/* 10931 */   MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 10944
/* 10935 */   MCD::OPC_CheckPredicate, 18, 41, 13, // Skip to: 14308
/* 10939 */   MCD::OPC_Decode, 164, 7, 135, 2, // Opcode: FLOG2_D
/* 10944 */   MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 10957
/* 10948 */   MCD::OPC_CheckPredicate, 18, 28, 13, // Skip to: 14308
/* 10952 */   MCD::OPC_Decode, 147, 7, 136, 2, // Opcode: FEXUPL_W
/* 10957 */   MCD::OPC_FilterValue, 17, 9, 0, // Skip to: 10970
/* 10961 */   MCD::OPC_CheckPredicate, 18, 15, 13, // Skip to: 14308
/* 10965 */   MCD::OPC_Decode, 146, 7, 137, 2, // Opcode: FEXUPL_D
/* 10970 */   MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 10983
/* 10974 */   MCD::OPC_CheckPredicate, 18, 2, 13, // Skip to: 14308
/* 10978 */   MCD::OPC_Decode, 149, 7, 136, 2, // Opcode: FEXUPR_W
/* 10983 */   MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 10996
/* 10987 */   MCD::OPC_CheckPredicate, 18, 245, 12, // Skip to: 14308
/* 10991 */   MCD::OPC_Decode, 148, 7, 137, 2, // Opcode: FEXUPR_D
/* 10996 */   MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 11009
/* 11000 */   MCD::OPC_CheckPredicate, 18, 232, 12, // Skip to: 14308
/* 11004 */   MCD::OPC_Decode, 155, 7, 136, 2, // Opcode: FFQL_W
/* 11009 */   MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 11022
/* 11013 */   MCD::OPC_CheckPredicate, 18, 219, 12, // Skip to: 14308
/* 11017 */   MCD::OPC_Decode, 154, 7, 137, 2, // Opcode: FFQL_D
/* 11022 */   MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 11035
/* 11026 */   MCD::OPC_CheckPredicate, 18, 206, 12, // Skip to: 14308
/* 11030 */   MCD::OPC_Decode, 157, 7, 136, 2, // Opcode: FFQR_W
/* 11035 */   MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 11048
/* 11039 */   MCD::OPC_CheckPredicate, 18, 193, 12, // Skip to: 14308
/* 11043 */   MCD::OPC_Decode, 156, 7, 137, 2, // Opcode: FFQR_D
/* 11048 */   MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 11061
/* 11052 */   MCD::OPC_CheckPredicate, 18, 180, 12, // Skip to: 14308
/* 11056 */   MCD::OPC_Decode, 129, 8, 134, 2, // Opcode: FTINT_S_W
/* 11061 */   MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 11074
/* 11065 */   MCD::OPC_CheckPredicate, 18, 167, 12, // Skip to: 14308
/* 11069 */   MCD::OPC_Decode, 128, 8, 135, 2, // Opcode: FTINT_S_D
/* 11074 */   MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 11087
/* 11078 */   MCD::OPC_CheckPredicate, 18, 154, 12, // Skip to: 14308
/* 11082 */   MCD::OPC_Decode, 131, 8, 134, 2, // Opcode: FTINT_U_W
/* 11087 */   MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 11100
/* 11091 */   MCD::OPC_CheckPredicate, 18, 141, 12, // Skip to: 14308
/* 11095 */   MCD::OPC_Decode, 130, 8, 135, 2, // Opcode: FTINT_U_D
/* 11100 */   MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 11113
/* 11104 */   MCD::OPC_CheckPredicate, 18, 128, 12, // Skip to: 14308
/* 11108 */   MCD::OPC_Decode, 151, 7, 134, 2, // Opcode: FFINT_S_W
/* 11113 */   MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 11126
/* 11117 */   MCD::OPC_CheckPredicate, 18, 115, 12, // Skip to: 14308
/* 11121 */   MCD::OPC_Decode, 150, 7, 135, 2, // Opcode: FFINT_S_D
/* 11126 */   MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 11139
/* 11130 */   MCD::OPC_CheckPredicate, 18, 102, 12, // Skip to: 14308
/* 11134 */   MCD::OPC_Decode, 153, 7, 134, 2, // Opcode: FFINT_U_W
/* 11139 */   MCD::OPC_FilterValue, 31, 93, 12, // Skip to: 14308
/* 11143 */   MCD::OPC_CheckPredicate, 18, 89, 12, // Skip to: 14308
/* 11147 */   MCD::OPC_Decode, 152, 7, 135, 2, // Opcode: FFINT_U_D
/* 11152 */   MCD::OPC_FilterValue, 32, 9, 0, // Skip to: 11165
/* 11156 */   MCD::OPC_CheckPredicate, 18, 76, 12, // Skip to: 14308
/* 11160 */   MCD::OPC_Decode, 137, 9, 138, 2, // Opcode: LD_B
/* 11165 */   MCD::OPC_FilterValue, 33, 9, 0, // Skip to: 11178
/* 11169 */   MCD::OPC_CheckPredicate, 18, 63, 12, // Skip to: 14308
/* 11173 */   MCD::OPC_Decode, 139, 9, 138, 2, // Opcode: LD_H
/* 11178 */   MCD::OPC_FilterValue, 34, 9, 0, // Skip to: 11191
/* 11182 */   MCD::OPC_CheckPredicate, 18, 50, 12, // Skip to: 14308
/* 11186 */   MCD::OPC_Decode, 140, 9, 138, 2, // Opcode: LD_W
/* 11191 */   MCD::OPC_FilterValue, 35, 9, 0, // Skip to: 11204
/* 11195 */   MCD::OPC_CheckPredicate, 18, 37, 12, // Skip to: 14308
/* 11199 */   MCD::OPC_Decode, 138, 9, 138, 2, // Opcode: LD_D
/* 11204 */   MCD::OPC_FilterValue, 36, 9, 0, // Skip to: 11217
/* 11208 */   MCD::OPC_CheckPredicate, 18, 24, 12, // Skip to: 14308
/* 11212 */   MCD::OPC_Decode, 192, 15, 138, 2, // Opcode: ST_B
/* 11217 */   MCD::OPC_FilterValue, 37, 9, 0, // Skip to: 11230
/* 11221 */   MCD::OPC_CheckPredicate, 18, 11, 12, // Skip to: 14308
/* 11225 */   MCD::OPC_Decode, 194, 15, 138, 2, // Opcode: ST_H
/* 11230 */   MCD::OPC_FilterValue, 38, 9, 0, // Skip to: 11243
/* 11234 */   MCD::OPC_CheckPredicate, 18, 254, 11, // Skip to: 14308
/* 11238 */   MCD::OPC_Decode, 195, 15, 138, 2, // Opcode: ST_W
/* 11243 */   MCD::OPC_FilterValue, 39, 245, 11, // Skip to: 14308
/* 11247 */   MCD::OPC_CheckPredicate, 18, 241, 11, // Skip to: 14308
/* 11251 */   MCD::OPC_Decode, 193, 15, 138, 2, // Opcode: ST_D
/* 11256 */   MCD::OPC_FilterValue, 31, 176, 10, // Skip to: 13996
/* 11260 */   MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 11263 */   MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 11276
/* 11267 */   MCD::OPC_CheckPredicate, 16, 221, 11, // Skip to: 14308
/* 11271 */   MCD::OPC_Decode, 184, 6, 139, 2, // Opcode: EXT
/* 11276 */   MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 11289
/* 11280 */   MCD::OPC_CheckPredicate, 16, 208, 11, // Skip to: 14308
/* 11284 */   MCD::OPC_Decode, 167, 8, 140, 2, // Opcode: INS
/* 11289 */   MCD::OPC_FilterValue, 10, 42, 0, // Skip to: 11335
/* 11293 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 11296 */   MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 11309
/* 11300 */   MCD::OPC_CheckPredicate, 23, 188, 11, // Skip to: 14308
/* 11304 */   MCD::OPC_Decode, 216, 9, 141, 2, // Opcode: LWX
/* 11309 */   MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 11322
/* 11313 */   MCD::OPC_CheckPredicate, 23, 175, 11, // Skip to: 14308
/* 11317 */   MCD::OPC_Decode, 149, 9, 141, 2, // Opcode: LHX
/* 11322 */   MCD::OPC_FilterValue, 6, 166, 11, // Skip to: 14308
/* 11326 */   MCD::OPC_CheckPredicate, 23, 162, 11, // Skip to: 14308
/* 11330 */   MCD::OPC_Decode, 239, 8, 141, 2, // Opcode: LBUX
/* 11335 */   MCD::OPC_FilterValue, 12, 15, 0, // Skip to: 11354
/* 11339 */   MCD::OPC_CheckPredicate, 23, 149, 11, // Skip to: 14308
/* 11343 */   MCD::OPC_CheckField, 6, 10, 0, 143, 11, // Skip to: 14308
/* 11349 */   MCD::OPC_Decode, 186, 8, 142, 2, // Opcode: INSV
/* 11354 */   MCD::OPC_FilterValue, 16, 51, 1, // Skip to: 11665
/* 11358 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 11361 */   MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 11373
/* 11365 */   MCD::OPC_CheckPredicate, 23, 123, 11, // Skip to: 14308
/* 11369 */   MCD::OPC_Decode, 77, 143, 2, // Opcode: ADDU_QB
/* 11373 */   MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 11386
/* 11377 */   MCD::OPC_CheckPredicate, 23, 111, 11, // Skip to: 14308
/* 11381 */   MCD::OPC_Decode, 236, 15, 143, 2, // Opcode: SUBU_QB
/* 11386 */   MCD::OPC_FilterValue, 4, 8, 0, // Skip to: 11398
/* 11390 */   MCD::OPC_CheckPredicate, 23, 98, 11, // Skip to: 14308
/* 11394 */   MCD::OPC_Decode, 81, 143, 2, // Opcode: ADDU_S_QB
/* 11398 */   MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 11411
/* 11402 */   MCD::OPC_CheckPredicate, 23, 86, 11, // Skip to: 14308
/* 11406 */   MCD::OPC_Decode, 240, 15, 143, 2, // Opcode: SUBU_S_QB
/* 11411 */   MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 11424
/* 11415 */   MCD::OPC_CheckPredicate, 23, 73, 11, // Skip to: 14308
/* 11419 */   MCD::OPC_Decode, 212, 11, 143, 2, // Opcode: MULEU_S_PH_QBL
/* 11424 */   MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 11437
/* 11428 */   MCD::OPC_CheckPredicate, 23, 60, 11, // Skip to: 14308
/* 11432 */   MCD::OPC_Decode, 214, 11, 143, 2, // Opcode: MULEU_S_PH_QBR
/* 11437 */   MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 11449
/* 11441 */   MCD::OPC_CheckPredicate, 48, 47, 11, // Skip to: 14308
/* 11445 */   MCD::OPC_Decode, 75, 143, 2, // Opcode: ADDU_PH
/* 11449 */   MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 11462
/* 11453 */   MCD::OPC_CheckPredicate, 48, 35, 11, // Skip to: 14308
/* 11457 */   MCD::OPC_Decode, 234, 15, 143, 2, // Opcode: SUBU_PH
/* 11462 */   MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 11474
/* 11466 */   MCD::OPC_CheckPredicate, 23, 22, 11, // Skip to: 14308
/* 11470 */   MCD::OPC_Decode, 48, 143, 2, // Opcode: ADDQ_PH
/* 11474 */   MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 11487
/* 11478 */   MCD::OPC_CheckPredicate, 23, 10, 11, // Skip to: 14308
/* 11482 */   MCD::OPC_Decode, 205, 15, 143, 2, // Opcode: SUBQ_PH
/* 11487 */   MCD::OPC_FilterValue, 12, 8, 0, // Skip to: 11499
/* 11491 */   MCD::OPC_CheckPredicate, 48, 253, 10, // Skip to: 14308
/* 11495 */   MCD::OPC_Decode, 79, 143, 2, // Opcode: ADDU_S_PH
/* 11499 */   MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 11512
/* 11503 */   MCD::OPC_CheckPredicate, 48, 241, 10, // Skip to: 14308
/* 11507 */   MCD::OPC_Decode, 238, 15, 143, 2, // Opcode: SUBU_S_PH
/* 11512 */   MCD::OPC_FilterValue, 14, 8, 0, // Skip to: 11524
/* 11516 */   MCD::OPC_CheckPredicate, 23, 228, 10, // Skip to: 14308
/* 11520 */   MCD::OPC_Decode, 50, 143, 2, // Opcode: ADDQ_S_PH
/* 11524 */   MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 11537
/* 11528 */   MCD::OPC_CheckPredicate, 23, 216, 10, // Skip to: 14308
/* 11532 */   MCD::OPC_Decode, 207, 15, 143, 2, // Opcode: SUBQ_S_PH
/* 11537 */   MCD::OPC_FilterValue, 16, 7, 0, // Skip to: 11548
/* 11541 */   MCD::OPC_CheckPredicate, 23, 203, 10, // Skip to: 14308
/* 11545 */   MCD::OPC_Decode, 54, 47, // Opcode: ADDSC
/* 11548 */   MCD::OPC_FilterValue, 17, 7, 0, // Skip to: 11559
/* 11552 */   MCD::OPC_CheckPredicate, 23, 192, 10, // Skip to: 14308
/* 11556 */   MCD::OPC_Decode, 91, 47, // Opcode: ADDWC
/* 11559 */   MCD::OPC_FilterValue, 18, 8, 0, // Skip to: 11571
/* 11563 */   MCD::OPC_CheckPredicate, 23, 181, 10, // Skip to: 14308
/* 11567 */   MCD::OPC_Decode, 225, 10, 47, // Opcode: MODSUB
/* 11571 */   MCD::OPC_FilterValue, 20, 15, 0, // Skip to: 11590
/* 11575 */   MCD::OPC_CheckPredicate, 23, 169, 10, // Skip to: 14308
/* 11579 */   MCD::OPC_CheckField, 16, 5, 0, 163, 10, // Skip to: 14308
/* 11585 */   MCD::OPC_Decode, 166, 13, 144, 2, // Opcode: RADDU_W_QB
/* 11590 */   MCD::OPC_FilterValue, 22, 7, 0, // Skip to: 11601
/* 11594 */   MCD::OPC_CheckPredicate, 23, 150, 10, // Skip to: 14308
/* 11598 */   MCD::OPC_Decode, 52, 47, // Opcode: ADDQ_S_W
/* 11601 */   MCD::OPC_FilterValue, 23, 8, 0, // Skip to: 11613
/* 11605 */   MCD::OPC_CheckPredicate, 23, 139, 10, // Skip to: 14308
/* 11609 */   MCD::OPC_Decode, 209, 15, 47, // Opcode: SUBQ_S_W
/* 11613 */   MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 11626
/* 11617 */   MCD::OPC_CheckPredicate, 23, 127, 10, // Skip to: 14308
/* 11621 */   MCD::OPC_Decode, 208, 11, 145, 2, // Opcode: MULEQ_S_W_PHL
/* 11626 */   MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 11639
/* 11630 */   MCD::OPC_CheckPredicate, 23, 114, 10, // Skip to: 14308
/* 11634 */   MCD::OPC_Decode, 210, 11, 145, 2, // Opcode: MULEQ_S_W_PHR
/* 11639 */   MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 11652
/* 11643 */   MCD::OPC_CheckPredicate, 48, 101, 10, // Skip to: 14308
/* 11647 */   MCD::OPC_Decode, 220, 11, 143, 2, // Opcode: MULQ_S_PH
/* 11652 */   MCD::OPC_FilterValue, 31, 92, 10, // Skip to: 14308
/* 11656 */   MCD::OPC_CheckPredicate, 23, 88, 10, // Skip to: 14308
/* 11660 */   MCD::OPC_Decode, 216, 11, 143, 2, // Opcode: MULQ_RS_PH
/* 11665 */   MCD::OPC_FilterValue, 17, 63, 1, // Skip to: 11988
/* 11669 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 11672 */   MCD::OPC_FilterValue, 0, 14, 0, // Skip to: 11690
/* 11676 */   MCD::OPC_CheckPredicate, 23, 68, 10, // Skip to: 14308
/* 11680 */   MCD::OPC_CheckField, 11, 5, 0, 62, 10, // Skip to: 14308
/* 11686 */   MCD::OPC_Decode, 244, 3, 60, // Opcode: CMPU_EQ_QB
/* 11690 */   MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 11708
/* 11694 */   MCD::OPC_CheckPredicate, 23, 50, 10, // Skip to: 14308
/* 11698 */   MCD::OPC_CheckField, 11, 5, 0, 44, 10, // Skip to: 14308
/* 11704 */   MCD::OPC_Decode, 246, 3, 60, // Opcode: CMPU_LT_QB
/* 11708 */   MCD::OPC_FilterValue, 2, 14, 0, // Skip to: 11726
/* 11712 */   MCD::OPC_CheckPredicate, 23, 32, 10, // Skip to: 14308
/* 11716 */   MCD::OPC_CheckField, 11, 5, 0, 26, 10, // Skip to: 14308
/* 11722 */   MCD::OPC_Decode, 245, 3, 60, // Opcode: CMPU_LE_QB
/* 11726 */   MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 11739
/* 11730 */   MCD::OPC_CheckPredicate, 23, 14, 10, // Skip to: 14308
/* 11734 */   MCD::OPC_Decode, 197, 12, 143, 2, // Opcode: PICK_QB
/* 11739 */   MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 11752
/* 11743 */   MCD::OPC_CheckPredicate, 23, 1, 10, // Skip to: 14308
/* 11747 */   MCD::OPC_Decode, 241, 3, 145, 2, // Opcode: CMPGU_EQ_QB
/* 11752 */   MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 11765
/* 11756 */   MCD::OPC_CheckPredicate, 23, 244, 9, // Skip to: 14308
/* 11760 */   MCD::OPC_Decode, 243, 3, 145, 2, // Opcode: CMPGU_LT_QB
/* 11765 */   MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 11778
/* 11769 */   MCD::OPC_CheckPredicate, 23, 231, 9, // Skip to: 14308
/* 11773 */   MCD::OPC_Decode, 242, 3, 145, 2, // Opcode: CMPGU_LE_QB
/* 11778 */   MCD::OPC_FilterValue, 8, 14, 0, // Skip to: 11796
/* 11782 */   MCD::OPC_CheckPredicate, 23, 218, 9, // Skip to: 14308
/* 11786 */   MCD::OPC_CheckField, 11, 5, 0, 212, 9, // Skip to: 14308
/* 11792 */   MCD::OPC_Decode, 251, 3, 60, // Opcode: CMP_EQ_PH
/* 11796 */   MCD::OPC_FilterValue, 9, 14, 0, // Skip to: 11814
/* 11800 */   MCD::OPC_CheckPredicate, 23, 200, 9, // Skip to: 14308
/* 11804 */   MCD::OPC_CheckField, 11, 5, 0, 194, 9, // Skip to: 14308
/* 11810 */   MCD::OPC_Decode, 135, 4, 60, // Opcode: CMP_LT_PH
/* 11814 */   MCD::OPC_FilterValue, 10, 14, 0, // Skip to: 11832
/* 11818 */   MCD::OPC_CheckPredicate, 23, 182, 9, // Skip to: 14308
/* 11822 */   MCD::OPC_CheckField, 11, 5, 0, 176, 9, // Skip to: 14308
/* 11828 */   MCD::OPC_Decode, 130, 4, 60, // Opcode: CMP_LE_PH
/* 11832 */   MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 11845
/* 11836 */   MCD::OPC_CheckPredicate, 23, 164, 9, // Skip to: 14308
/* 11840 */   MCD::OPC_Decode, 196, 12, 143, 2, // Opcode: PICK_PH
/* 11845 */   MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 11858
/* 11849 */   MCD::OPC_CheckPredicate, 23, 151, 9, // Skip to: 14308
/* 11853 */   MCD::OPC_Decode, 223, 12, 143, 2, // Opcode: PRECRQ_QB_PH
/* 11858 */   MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 11871
/* 11862 */   MCD::OPC_CheckPredicate, 48, 138, 9, // Skip to: 14308
/* 11866 */   MCD::OPC_Decode, 227, 12, 143, 2, // Opcode: PRECR_QB_PH
/* 11871 */   MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 11884
/* 11875 */   MCD::OPC_CheckPredicate, 23, 125, 9, // Skip to: 14308
/* 11879 */   MCD::OPC_Decode, 180, 12, 143, 2, // Opcode: PACKRL_PH
/* 11884 */   MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 11897
/* 11888 */   MCD::OPC_CheckPredicate, 23, 112, 9, // Skip to: 14308
/* 11892 */   MCD::OPC_Decode, 219, 12, 143, 2, // Opcode: PRECRQU_S_QB_PH
/* 11897 */   MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 11910
/* 11901 */   MCD::OPC_CheckPredicate, 23, 99, 9, // Skip to: 14308
/* 11905 */   MCD::OPC_Decode, 221, 12, 146, 2, // Opcode: PRECRQ_PH_W
/* 11910 */   MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 11923
/* 11914 */   MCD::OPC_CheckPredicate, 23, 86, 9, // Skip to: 14308
/* 11918 */   MCD::OPC_Decode, 225, 12, 146, 2, // Opcode: PRECRQ_RS_PH_W
/* 11923 */   MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 11936
/* 11927 */   MCD::OPC_CheckPredicate, 48, 73, 9, // Skip to: 14308
/* 11931 */   MCD::OPC_Decode, 238, 3, 145, 2, // Opcode: CMPGDU_EQ_QB
/* 11936 */   MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 11949
/* 11940 */   MCD::OPC_CheckPredicate, 48, 60, 9, // Skip to: 14308
/* 11944 */   MCD::OPC_Decode, 240, 3, 145, 2, // Opcode: CMPGDU_LT_QB
/* 11949 */   MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 11962
/* 11953 */   MCD::OPC_CheckPredicate, 48, 47, 9, // Skip to: 14308
/* 11957 */   MCD::OPC_Decode, 239, 3, 145, 2, // Opcode: CMPGDU_LE_QB
/* 11962 */   MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 11975
/* 11966 */   MCD::OPC_CheckPredicate, 48, 34, 9, // Skip to: 14308
/* 11970 */   MCD::OPC_Decode, 229, 12, 147, 2, // Opcode: PRECR_SRA_PH_W
/* 11975 */   MCD::OPC_FilterValue, 31, 25, 9, // Skip to: 14308
/* 11979 */   MCD::OPC_CheckPredicate, 48, 21, 9, // Skip to: 14308
/* 11983 */   MCD::OPC_Decode, 231, 12, 147, 2, // Opcode: PRECR_SRA_R_PH_W
/* 11988 */   MCD::OPC_FilterValue, 18, 72, 1, // Skip to: 12320
/* 11992 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 11995 */   MCD::OPC_FilterValue, 1, 14, 0, // Skip to: 12013
/* 11999 */   MCD::OPC_CheckPredicate, 48, 1, 9, // Skip to: 14308
/* 12003 */   MCD::OPC_CheckField, 21, 5, 0, 251, 8, // Skip to: 14308
/* 12009 */   MCD::OPC_Decode, 25, 148, 2, // Opcode: ABSQ_S_QB
/* 12013 */   MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 12025
/* 12017 */   MCD::OPC_CheckPredicate, 23, 239, 8, // Skip to: 14308
/* 12021 */   MCD::OPC_Decode, 183, 13, 77, // Opcode: REPL_QB
/* 12025 */   MCD::OPC_FilterValue, 3, 15, 0, // Skip to: 12044
/* 12029 */   MCD::OPC_CheckPredicate, 23, 227, 8, // Skip to: 14308
/* 12033 */   MCD::OPC_CheckField, 21, 5, 0, 221, 8, // Skip to: 14308
/* 12039 */   MCD::OPC_Decode, 179, 13, 149, 2, // Opcode: REPLV_QB
/* 12044 */   MCD::OPC_FilterValue, 4, 15, 0, // Skip to: 12063
/* 12048 */   MCD::OPC_CheckPredicate, 23, 208, 8, // Skip to: 14308
/* 12052 */   MCD::OPC_CheckField, 21, 5, 0, 202, 8, // Skip to: 14308
/* 12058 */   MCD::OPC_Decode, 199, 12, 148, 2, // Opcode: PRECEQU_PH_QBL
/* 12063 */   MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 12082
/* 12067 */   MCD::OPC_CheckPredicate, 23, 189, 8, // Skip to: 14308
/* 12071 */   MCD::OPC_CheckField, 21, 5, 0, 183, 8, // Skip to: 14308
/* 12077 */   MCD::OPC_Decode, 203, 12, 148, 2, // Opcode: PRECEQU_PH_QBR
/* 12082 */   MCD::OPC_FilterValue, 6, 15, 0, // Skip to: 12101
/* 12086 */   MCD::OPC_CheckPredicate, 23, 170, 8, // Skip to: 14308
/* 12090 */   MCD::OPC_CheckField, 21, 5, 0, 164, 8, // Skip to: 14308
/* 12096 */   MCD::OPC_Decode, 200, 12, 148, 2, // Opcode: PRECEQU_PH_QBLA
/* 12101 */   MCD::OPC_FilterValue, 7, 15, 0, // Skip to: 12120
/* 12105 */   MCD::OPC_CheckPredicate, 23, 151, 8, // Skip to: 14308
/* 12109 */   MCD::OPC_CheckField, 21, 5, 0, 145, 8, // Skip to: 14308
/* 12115 */   MCD::OPC_Decode, 204, 12, 148, 2, // Opcode: PRECEQU_PH_QBRA
/* 12120 */   MCD::OPC_FilterValue, 9, 14, 0, // Skip to: 12138
/* 12124 */   MCD::OPC_CheckPredicate, 23, 132, 8, // Skip to: 14308
/* 12128 */   MCD::OPC_CheckField, 21, 5, 0, 126, 8, // Skip to: 14308
/* 12134 */   MCD::OPC_Decode, 23, 148, 2, // Opcode: ABSQ_S_PH
/* 12138 */   MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 12150
/* 12142 */   MCD::OPC_CheckPredicate, 23, 114, 8, // Skip to: 14308
/* 12146 */   MCD::OPC_Decode, 181, 13, 77, // Opcode: REPL_PH
/* 12150 */   MCD::OPC_FilterValue, 11, 15, 0, // Skip to: 12169
/* 12154 */   MCD::OPC_CheckPredicate, 23, 102, 8, // Skip to: 14308
/* 12158 */   MCD::OPC_CheckField, 21, 5, 0, 96, 8, // Skip to: 14308
/* 12164 */   MCD::OPC_Decode, 177, 13, 149, 2, // Opcode: REPLV_PH
/* 12169 */   MCD::OPC_FilterValue, 12, 15, 0, // Skip to: 12188
/* 12173 */   MCD::OPC_CheckPredicate, 23, 83, 8, // Skip to: 14308
/* 12177 */   MCD::OPC_CheckField, 21, 5, 0, 77, 8, // Skip to: 14308
/* 12183 */   MCD::OPC_Decode, 207, 12, 150, 2, // Opcode: PRECEQ_W_PHL
/* 12188 */   MCD::OPC_FilterValue, 13, 15, 0, // Skip to: 12207
/* 12192 */   MCD::OPC_CheckPredicate, 23, 64, 8, // Skip to: 14308
/* 12196 */   MCD::OPC_CheckField, 21, 5, 0, 58, 8, // Skip to: 14308
/* 12202 */   MCD::OPC_Decode, 209, 12, 150, 2, // Opcode: PRECEQ_W_PHR
/* 12207 */   MCD::OPC_FilterValue, 17, 14, 0, // Skip to: 12225
/* 12211 */   MCD::OPC_CheckPredicate, 23, 45, 8, // Skip to: 14308
/* 12215 */   MCD::OPC_CheckField, 21, 5, 0, 39, 8, // Skip to: 14308
/* 12221 */   MCD::OPC_Decode, 27, 151, 2, // Opcode: ABSQ_S_W
/* 12225 */   MCD::OPC_FilterValue, 27, 15, 0, // Skip to: 12244
/* 12229 */   MCD::OPC_CheckPredicate, 23, 27, 8, // Skip to: 14308
/* 12233 */   MCD::OPC_CheckField, 21, 5, 0, 21, 8, // Skip to: 14308
/* 12239 */   MCD::OPC_Decode, 166, 2, 151, 2, // Opcode: BITREV
/* 12244 */   MCD::OPC_FilterValue, 28, 15, 0, // Skip to: 12263
/* 12248 */   MCD::OPC_CheckPredicate, 23, 8, 8, // Skip to: 14308
/* 12252 */   MCD::OPC_CheckField, 21, 5, 0, 2, 8, // Skip to: 14308
/* 12258 */   MCD::OPC_Decode, 211, 12, 148, 2, // Opcode: PRECEU_PH_QBL
/* 12263 */   MCD::OPC_FilterValue, 29, 15, 0, // Skip to: 12282
/* 12267 */   MCD::OPC_CheckPredicate, 23, 245, 7, // Skip to: 14308
/* 12271 */   MCD::OPC_CheckField, 21, 5, 0, 239, 7, // Skip to: 14308
/* 12277 */   MCD::OPC_Decode, 215, 12, 148, 2, // Opcode: PRECEU_PH_QBR
/* 12282 */   MCD::OPC_FilterValue, 30, 15, 0, // Skip to: 12301
/* 12286 */   MCD::OPC_CheckPredicate, 23, 226, 7, // Skip to: 14308
/* 12290 */   MCD::OPC_CheckField, 21, 5, 0, 220, 7, // Skip to: 14308
/* 12296 */   MCD::OPC_Decode, 212, 12, 148, 2, // Opcode: PRECEU_PH_QBLA
/* 12301 */   MCD::OPC_FilterValue, 31, 211, 7, // Skip to: 14308
/* 12305 */   MCD::OPC_CheckPredicate, 23, 207, 7, // Skip to: 14308
/* 12309 */   MCD::OPC_CheckField, 21, 5, 0, 201, 7, // Skip to: 14308
/* 12315 */   MCD::OPC_Decode, 216, 12, 148, 2, // Opcode: PRECEU_PH_QBRA
/* 12320 */   MCD::OPC_FilterValue, 19, 31, 1, // Skip to: 12611
/* 12324 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 12327 */   MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 12340
/* 12331 */   MCD::OPC_CheckPredicate, 23, 181, 7, // Skip to: 14308
/* 12335 */   MCD::OPC_Decode, 181, 14, 152, 2, // Opcode: SHLL_QB
/* 12340 */   MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 12353
/* 12344 */   MCD::OPC_CheckPredicate, 23, 168, 7, // Skip to: 14308
/* 12348 */   MCD::OPC_Decode, 213, 14, 152, 2, // Opcode: SHRL_QB
/* 12353 */   MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 12366
/* 12357 */   MCD::OPC_CheckPredicate, 23, 155, 7, // Skip to: 14308
/* 12361 */   MCD::OPC_Decode, 173, 14, 153, 2, // Opcode: SHLLV_QB
/* 12366 */   MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 12379
/* 12370 */   MCD::OPC_CheckPredicate, 23, 142, 7, // Skip to: 14308
/* 12374 */   MCD::OPC_Decode, 209, 14, 153, 2, // Opcode: SHRLV_QB
/* 12379 */   MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 12392
/* 12383 */   MCD::OPC_CheckPredicate, 48, 129, 7, // Skip to: 14308
/* 12387 */   MCD::OPC_Decode, 199, 14, 152, 2, // Opcode: SHRA_QB
/* 12392 */   MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 12405
/* 12396 */   MCD::OPC_CheckPredicate, 48, 116, 7, // Skip to: 14308
/* 12400 */   MCD::OPC_Decode, 203, 14, 152, 2, // Opcode: SHRA_R_QB
/* 12405 */   MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 12418
/* 12409 */   MCD::OPC_CheckPredicate, 48, 103, 7, // Skip to: 14308
/* 12413 */   MCD::OPC_Decode, 189, 14, 153, 2, // Opcode: SHRAV_QB
/* 12418 */   MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 12431
/* 12422 */   MCD::OPC_CheckPredicate, 48, 90, 7, // Skip to: 14308
/* 12426 */   MCD::OPC_Decode, 193, 14, 153, 2, // Opcode: SHRAV_R_QB
/* 12431 */   MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 12444
/* 12435 */   MCD::OPC_CheckPredicate, 23, 77, 7, // Skip to: 14308
/* 12439 */   MCD::OPC_Decode, 179, 14, 152, 2, // Opcode: SHLL_PH
/* 12444 */   MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 12457
/* 12448 */   MCD::OPC_CheckPredicate, 23, 64, 7, // Skip to: 14308
/* 12452 */   MCD::OPC_Decode, 197, 14, 152, 2, // Opcode: SHRA_PH
/* 12457 */   MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 12470
/* 12461 */   MCD::OPC_CheckPredicate, 23, 51, 7, // Skip to: 14308
/* 12465 */   MCD::OPC_Decode, 171, 14, 153, 2, // Opcode: SHLLV_PH
/* 12470 */   MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 12483
/* 12474 */   MCD::OPC_CheckPredicate, 23, 38, 7, // Skip to: 14308
/* 12478 */   MCD::OPC_Decode, 187, 14, 153, 2, // Opcode: SHRAV_PH
/* 12483 */   MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 12496
/* 12487 */   MCD::OPC_CheckPredicate, 23, 25, 7, // Skip to: 14308
/* 12491 */   MCD::OPC_Decode, 183, 14, 152, 2, // Opcode: SHLL_S_PH
/* 12496 */   MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 12509
/* 12500 */   MCD::OPC_CheckPredicate, 23, 12, 7, // Skip to: 14308
/* 12504 */   MCD::OPC_Decode, 201, 14, 152, 2, // Opcode: SHRA_R_PH
/* 12509 */   MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 12522
/* 12513 */   MCD::OPC_CheckPredicate, 23, 255, 6, // Skip to: 14308
/* 12517 */   MCD::OPC_Decode, 175, 14, 153, 2, // Opcode: SHLLV_S_PH
/* 12522 */   MCD::OPC_FilterValue, 15, 9, 0, // Skip to: 12535
/* 12526 */   MCD::OPC_CheckPredicate, 23, 242, 6, // Skip to: 14308
/* 12530 */   MCD::OPC_Decode, 191, 14, 153, 2, // Opcode: SHRAV_R_PH
/* 12535 */   MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 12548
/* 12539 */   MCD::OPC_CheckPredicate, 23, 229, 6, // Skip to: 14308
/* 12543 */   MCD::OPC_Decode, 185, 14, 154, 2, // Opcode: SHLL_S_W
/* 12548 */   MCD::OPC_FilterValue, 21, 9, 0, // Skip to: 12561
/* 12552 */   MCD::OPC_CheckPredicate, 23, 216, 6, // Skip to: 14308
/* 12556 */   MCD::OPC_Decode, 205, 14, 154, 2, // Opcode: SHRA_R_W
/* 12561 */   MCD::OPC_FilterValue, 22, 8, 0, // Skip to: 12573
/* 12565 */   MCD::OPC_CheckPredicate, 23, 203, 6, // Skip to: 14308
/* 12569 */   MCD::OPC_Decode, 177, 14, 41, // Opcode: SHLLV_S_W
/* 12573 */   MCD::OPC_FilterValue, 23, 8, 0, // Skip to: 12585
/* 12577 */   MCD::OPC_CheckPredicate, 23, 191, 6, // Skip to: 14308
/* 12581 */   MCD::OPC_Decode, 195, 14, 41, // Opcode: SHRAV_R_W
/* 12585 */   MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 12598
/* 12589 */   MCD::OPC_CheckPredicate, 48, 179, 6, // Skip to: 14308
/* 12593 */   MCD::OPC_Decode, 211, 14, 152, 2, // Opcode: SHRL_PH
/* 12598 */   MCD::OPC_FilterValue, 27, 170, 6, // Skip to: 14308
/* 12602 */   MCD::OPC_CheckPredicate, 48, 166, 6, // Skip to: 14308
/* 12606 */   MCD::OPC_Decode, 207, 14, 153, 2, // Opcode: SHRLV_PH
/* 12611 */   MCD::OPC_FilterValue, 24, 199, 0, // Skip to: 12814
/* 12615 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 12618 */   MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 12630
/* 12622 */   MCD::OPC_CheckPredicate, 48, 146, 6, // Skip to: 14308
/* 12626 */   MCD::OPC_Decode, 70, 143, 2, // Opcode: ADDUH_QB
/* 12630 */   MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 12643
/* 12634 */   MCD::OPC_CheckPredicate, 48, 134, 6, // Skip to: 14308
/* 12638 */   MCD::OPC_Decode, 229, 15, 143, 2, // Opcode: SUBUH_QB
/* 12643 */   MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 12655
/* 12647 */   MCD::OPC_CheckPredicate, 48, 121, 6, // Skip to: 14308
/* 12651 */   MCD::OPC_Decode, 72, 143, 2, // Opcode: ADDUH_R_QB
/* 12655 */   MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 12668
/* 12659 */   MCD::OPC_CheckPredicate, 48, 109, 6, // Skip to: 14308
/* 12663 */   MCD::OPC_Decode, 231, 15, 143, 2, // Opcode: SUBUH_R_QB
/* 12668 */   MCD::OPC_FilterValue, 8, 8, 0, // Skip to: 12680
/* 12672 */   MCD::OPC_CheckPredicate, 48, 96, 6, // Skip to: 14308
/* 12676 */   MCD::OPC_Decode, 40, 143, 2, // Opcode: ADDQH_PH
/* 12680 */   MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 12693
/* 12684 */   MCD::OPC_CheckPredicate, 48, 84, 6, // Skip to: 14308
/* 12688 */   MCD::OPC_Decode, 197, 15, 143, 2, // Opcode: SUBQH_PH
/* 12693 */   MCD::OPC_FilterValue, 10, 8, 0, // Skip to: 12705
/* 12697 */   MCD::OPC_CheckPredicate, 48, 71, 6, // Skip to: 14308
/* 12701 */   MCD::OPC_Decode, 42, 143, 2, // Opcode: ADDQH_R_PH
/* 12705 */   MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 12718
/* 12709 */   MCD::OPC_CheckPredicate, 48, 59, 6, // Skip to: 14308
/* 12713 */   MCD::OPC_Decode, 199, 15, 143, 2, // Opcode: SUBQH_R_PH
/* 12718 */   MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 12731
/* 12722 */   MCD::OPC_CheckPredicate, 48, 46, 6, // Skip to: 14308
/* 12726 */   MCD::OPC_Decode, 244, 11, 143, 2, // Opcode: MUL_PH
/* 12731 */   MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 12744
/* 12735 */   MCD::OPC_CheckPredicate, 48, 33, 6, // Skip to: 14308
/* 12739 */   MCD::OPC_Decode, 249, 11, 143, 2, // Opcode: MUL_S_PH
/* 12744 */   MCD::OPC_FilterValue, 16, 7, 0, // Skip to: 12755
/* 12748 */   MCD::OPC_CheckPredicate, 48, 20, 6, // Skip to: 14308
/* 12752 */   MCD::OPC_Decode, 46, 47, // Opcode: ADDQH_W
/* 12755 */   MCD::OPC_FilterValue, 17, 8, 0, // Skip to: 12767
/* 12759 */   MCD::OPC_CheckPredicate, 48, 9, 6, // Skip to: 14308
/* 12763 */   MCD::OPC_Decode, 203, 15, 47, // Opcode: SUBQH_W
/* 12767 */   MCD::OPC_FilterValue, 18, 7, 0, // Skip to: 12778
/* 12771 */   MCD::OPC_CheckPredicate, 48, 253, 5, // Skip to: 14308
/* 12775 */   MCD::OPC_Decode, 44, 47, // Opcode: ADDQH_R_W
/* 12778 */   MCD::OPC_FilterValue, 19, 8, 0, // Skip to: 12790
/* 12782 */   MCD::OPC_CheckPredicate, 48, 242, 5, // Skip to: 14308
/* 12786 */   MCD::OPC_Decode, 201, 15, 47, // Opcode: SUBQH_R_W
/* 12790 */   MCD::OPC_FilterValue, 22, 8, 0, // Skip to: 12802
/* 12794 */   MCD::OPC_CheckPredicate, 48, 230, 5, // Skip to: 14308
/* 12798 */   MCD::OPC_Decode, 222, 11, 47, // Opcode: MULQ_S_W
/* 12802 */   MCD::OPC_FilterValue, 23, 222, 5, // Skip to: 14308
/* 12806 */   MCD::OPC_CheckPredicate, 48, 218, 5, // Skip to: 14308
/* 12810 */   MCD::OPC_Decode, 218, 11, 47, // Opcode: MULQ_RS_W
/* 12814 */   MCD::OPC_FilterValue, 25, 15, 0, // Skip to: 12833
/* 12818 */   MCD::OPC_CheckPredicate, 49, 206, 5, // Skip to: 14308
/* 12822 */   MCD::OPC_CheckField, 6, 1, 0, 200, 5, // Skip to: 14308
/* 12828 */   MCD::OPC_Decode, 198, 9, 155, 2, // Opcode: LWLE
/* 12833 */   MCD::OPC_FilterValue, 26, 15, 0, // Skip to: 12852
/* 12837 */   MCD::OPC_CheckPredicate, 49, 187, 5, // Skip to: 14308
/* 12841 */   MCD::OPC_CheckField, 6, 1, 0, 181, 5, // Skip to: 14308
/* 12847 */   MCD::OPC_Decode, 210, 9, 155, 2, // Opcode: LWRE
/* 12852 */   MCD::OPC_FilterValue, 27, 15, 0, // Skip to: 12871
/* 12856 */   MCD::OPC_CheckPredicate, 27, 168, 5, // Skip to: 14308
/* 12860 */   MCD::OPC_CheckField, 6, 1, 0, 162, 5, // Skip to: 14308
/* 12866 */   MCD::OPC_Decode, 164, 3, 156, 2, // Opcode: CACHEE
/* 12871 */   MCD::OPC_FilterValue, 28, 15, 0, // Skip to: 12890
/* 12875 */   MCD::OPC_CheckPredicate, 27, 149, 5, // Skip to: 14308
/* 12879 */   MCD::OPC_CheckField, 6, 1, 0, 143, 5, // Skip to: 14308
/* 12885 */   MCD::OPC_Decode, 226, 13, 155, 2, // Opcode: SBE
/* 12890 */   MCD::OPC_FilterValue, 29, 15, 0, // Skip to: 12909
/* 12894 */   MCD::OPC_CheckPredicate, 27, 130, 5, // Skip to: 14308
/* 12898 */   MCD::OPC_CheckField, 6, 1, 0, 124, 5, // Skip to: 14308
/* 12904 */   MCD::OPC_Decode, 163, 14, 155, 2, // Opcode: SHE
/* 12909 */   MCD::OPC_FilterValue, 30, 15, 0, // Skip to: 12928
/* 12913 */   MCD::OPC_CheckPredicate, 50, 111, 5, // Skip to: 14308
/* 12917 */   MCD::OPC_CheckField, 6, 1, 0, 105, 5, // Skip to: 14308
/* 12923 */   MCD::OPC_Decode, 234, 13, 155, 2, // Opcode: SCE
/* 12928 */   MCD::OPC_FilterValue, 31, 15, 0, // Skip to: 12947
/* 12932 */   MCD::OPC_CheckPredicate, 50, 92, 5, // Skip to: 14308
/* 12936 */   MCD::OPC_CheckField, 6, 1, 0, 86, 5, // Skip to: 14308
/* 12942 */   MCD::OPC_Decode, 138, 16, 155, 2, // Opcode: SWE
/* 12947 */   MCD::OPC_FilterValue, 32, 60, 0, // Skip to: 13011
/* 12951 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 12954 */   MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 12973
/* 12958 */   MCD::OPC_CheckPredicate, 30, 66, 5, // Skip to: 14308
/* 12962 */   MCD::OPC_CheckField, 21, 5, 0, 60, 5, // Skip to: 14308
/* 12968 */   MCD::OPC_Decode, 153, 17, 151, 2, // Opcode: WSBH
/* 12973 */   MCD::OPC_FilterValue, 16, 15, 0, // Skip to: 12992
/* 12977 */   MCD::OPC_CheckPredicate, 16, 47, 5, // Skip to: 14308
/* 12981 */   MCD::OPC_CheckField, 21, 5, 0, 41, 5, // Skip to: 14308
/* 12987 */   MCD::OPC_Decode, 131, 14, 151, 2, // Opcode: SEB
/* 12992 */   MCD::OPC_FilterValue, 24, 32, 5, // Skip to: 14308
/* 12996 */   MCD::OPC_CheckPredicate, 16, 28, 5, // Skip to: 14308
/* 13000 */   MCD::OPC_CheckField, 21, 5, 0, 22, 5, // Skip to: 14308
/* 13006 */   MCD::OPC_Decode, 135, 14, 151, 2, // Opcode: SEH
/* 13011 */   MCD::OPC_FilterValue, 33, 15, 0, // Skip to: 13030
/* 13015 */   MCD::OPC_CheckPredicate, 49, 9, 5, // Skip to: 14308
/* 13019 */   MCD::OPC_CheckField, 6, 1, 0, 3, 5, // Skip to: 14308
/* 13025 */   MCD::OPC_Decode, 143, 16, 155, 2, // Opcode: SWLE
/* 13030 */   MCD::OPC_FilterValue, 34, 15, 0, // Skip to: 13049
/* 13034 */   MCD::OPC_CheckPredicate, 49, 246, 4, // Skip to: 14308
/* 13038 */   MCD::OPC_CheckField, 6, 1, 0, 240, 4, // Skip to: 14308
/* 13044 */   MCD::OPC_Decode, 153, 16, 155, 2, // Opcode: SWRE
/* 13049 */   MCD::OPC_FilterValue, 35, 15, 0, // Skip to: 13068
/* 13053 */   MCD::OPC_CheckPredicate, 27, 227, 4, // Skip to: 14308
/* 13057 */   MCD::OPC_CheckField, 6, 1, 0, 221, 4, // Skip to: 14308
/* 13063 */   MCD::OPC_Decode, 234, 12, 156, 2, // Opcode: PREFE
/* 13068 */   MCD::OPC_FilterValue, 40, 15, 0, // Skip to: 13087
/* 13072 */   MCD::OPC_CheckPredicate, 27, 208, 4, // Skip to: 14308
/* 13076 */   MCD::OPC_CheckField, 6, 1, 0, 202, 4, // Skip to: 14308
/* 13082 */   MCD::OPC_Decode, 246, 8, 155, 2, // Opcode: LBuE
/* 13087 */   MCD::OPC_FilterValue, 41, 15, 0, // Skip to: 13106
/* 13091 */   MCD::OPC_CheckPredicate, 27, 189, 4, // Skip to: 14308
/* 13095 */   MCD::OPC_CheckField, 6, 1, 0, 183, 4, // Skip to: 14308
/* 13101 */   MCD::OPC_Decode, 154, 9, 155, 2, // Opcode: LHuE
/* 13106 */   MCD::OPC_FilterValue, 44, 15, 0, // Skip to: 13125
/* 13110 */   MCD::OPC_CheckPredicate, 27, 170, 4, // Skip to: 14308
/* 13114 */   MCD::OPC_CheckField, 6, 1, 0, 164, 4, // Skip to: 14308
/* 13120 */   MCD::OPC_Decode, 234, 8, 155, 2, // Opcode: LBE
/* 13125 */   MCD::OPC_FilterValue, 45, 15, 0, // Skip to: 13144
/* 13129 */   MCD::OPC_CheckPredicate, 27, 151, 4, // Skip to: 14308
/* 13133 */   MCD::OPC_CheckField, 6, 1, 0, 145, 4, // Skip to: 14308
/* 13139 */   MCD::OPC_Decode, 146, 9, 155, 2, // Opcode: LHE
/* 13144 */   MCD::OPC_FilterValue, 46, 15, 0, // Skip to: 13163
/* 13148 */   MCD::OPC_CheckPredicate, 50, 132, 4, // Skip to: 14308
/* 13152 */   MCD::OPC_CheckField, 6, 1, 0, 126, 4, // Skip to: 14308
/* 13158 */   MCD::OPC_Decode, 162, 9, 155, 2, // Opcode: LLE
/* 13163 */   MCD::OPC_FilterValue, 47, 15, 0, // Skip to: 13182
/* 13167 */   MCD::OPC_CheckPredicate, 50, 113, 4, // Skip to: 14308
/* 13171 */   MCD::OPC_CheckField, 6, 1, 0, 107, 4, // Skip to: 14308
/* 13177 */   MCD::OPC_Decode, 192, 9, 155, 2, // Opcode: LWE
/* 13182 */   MCD::OPC_FilterValue, 48, 165, 1, // Skip to: 13607
/* 13186 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 13189 */   MCD::OPC_FilterValue, 0, 15, 0, // Skip to: 13208
/* 13193 */   MCD::OPC_CheckPredicate, 48, 87, 4, // Skip to: 14308
/* 13197 */   MCD::OPC_CheckField, 13, 3, 0, 81, 4, // Skip to: 14308
/* 13203 */   MCD::OPC_Decode, 248, 5, 192, 1, // Opcode: DPA_W_PH
/* 13208 */   MCD::OPC_FilterValue, 1, 15, 0, // Skip to: 13227
/* 13212 */   MCD::OPC_CheckPredicate, 48, 68, 4, // Skip to: 14308
/* 13216 */   MCD::OPC_CheckField, 13, 3, 0, 62, 4, // Skip to: 14308
/* 13222 */   MCD::OPC_Decode, 143, 6, 192, 1, // Opcode: DPS_W_PH
/* 13227 */   MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 13246
/* 13231 */   MCD::OPC_CheckPredicate, 48, 49, 4, // Skip to: 14308
/* 13235 */   MCD::OPC_CheckField, 13, 3, 0, 43, 4, // Skip to: 14308
/* 13241 */   MCD::OPC_Decode, 227, 11, 192, 1, // Opcode: MULSA_W_PH
/* 13246 */   MCD::OPC_FilterValue, 3, 15, 0, // Skip to: 13265
/* 13250 */   MCD::OPC_CheckPredicate, 23, 30, 4, // Skip to: 14308
/* 13254 */   MCD::OPC_CheckField, 13, 3, 0, 24, 4, // Skip to: 14308
/* 13260 */   MCD::OPC_Decode, 242, 5, 192, 1, // Opcode: DPAU_H_QBL
/* 13265 */   MCD::OPC_FilterValue, 4, 15, 0, // Skip to: 13284
/* 13269 */   MCD::OPC_CheckPredicate, 23, 11, 4, // Skip to: 14308
/* 13273 */   MCD::OPC_CheckField, 13, 3, 0, 5, 4, // Skip to: 14308
/* 13279 */   MCD::OPC_Decode, 240, 5, 192, 1, // Opcode: DPAQ_S_W_PH
/* 13284 */   MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 13303
/* 13288 */   MCD::OPC_CheckPredicate, 23, 248, 3, // Skip to: 14308
/* 13292 */   MCD::OPC_CheckField, 13, 3, 0, 242, 3, // Skip to: 14308
/* 13298 */   MCD::OPC_Decode, 129, 6, 192, 1, // Opcode: DPSQ_S_W_PH
/* 13303 */   MCD::OPC_FilterValue, 6, 15, 0, // Skip to: 13322
/* 13307 */   MCD::OPC_CheckPredicate, 23, 229, 3, // Skip to: 14308
/* 13311 */   MCD::OPC_CheckField, 13, 3, 0, 223, 3, // Skip to: 14308
/* 13317 */   MCD::OPC_Decode, 226, 11, 192, 1, // Opcode: MULSAQ_S_W_PH
/* 13322 */   MCD::OPC_FilterValue, 7, 15, 0, // Skip to: 13341
/* 13326 */   MCD::OPC_CheckPredicate, 23, 210, 3, // Skip to: 14308
/* 13330 */   MCD::OPC_CheckField, 13, 3, 0, 204, 3, // Skip to: 14308
/* 13336 */   MCD::OPC_Decode, 244, 5, 192, 1, // Opcode: DPAU_H_QBR
/* 13341 */   MCD::OPC_FilterValue, 8, 15, 0, // Skip to: 13360
/* 13345 */   MCD::OPC_CheckPredicate, 48, 191, 3, // Skip to: 14308
/* 13349 */   MCD::OPC_CheckField, 13, 3, 0, 185, 3, // Skip to: 14308
/* 13355 */   MCD::OPC_Decode, 246, 5, 192, 1, // Opcode: DPAX_W_PH
/* 13360 */   MCD::OPC_FilterValue, 9, 15, 0, // Skip to: 13379
/* 13364 */   MCD::OPC_CheckPredicate, 48, 172, 3, // Skip to: 14308
/* 13368 */   MCD::OPC_CheckField, 13, 3, 0, 166, 3, // Skip to: 14308
/* 13374 */   MCD::OPC_Decode, 141, 6, 192, 1, // Opcode: DPSX_W_PH
/* 13379 */   MCD::OPC_FilterValue, 11, 15, 0, // Skip to: 13398
/* 13383 */   MCD::OPC_CheckPredicate, 23, 153, 3, // Skip to: 14308
/* 13387 */   MCD::OPC_CheckField, 13, 3, 0, 147, 3, // Skip to: 14308
/* 13393 */   MCD::OPC_Decode, 137, 6, 192, 1, // Opcode: DPSU_H_QBL
/* 13398 */   MCD::OPC_FilterValue, 12, 15, 0, // Skip to: 13417
/* 13402 */   MCD::OPC_CheckPredicate, 23, 134, 3, // Skip to: 14308
/* 13406 */   MCD::OPC_CheckField, 13, 3, 0, 128, 3, // Skip to: 14308
/* 13412 */   MCD::OPC_Decode, 238, 5, 192, 1, // Opcode: DPAQ_SA_L_W
/* 13417 */   MCD::OPC_FilterValue, 13, 15, 0, // Skip to: 13436
/* 13421 */   MCD::OPC_CheckPredicate, 23, 115, 3, // Skip to: 14308
/* 13425 */   MCD::OPC_CheckField, 13, 3, 0, 109, 3, // Skip to: 14308
/* 13431 */   MCD::OPC_Decode, 255, 5, 192, 1, // Opcode: DPSQ_SA_L_W
/* 13436 */   MCD::OPC_FilterValue, 15, 15, 0, // Skip to: 13455
/* 13440 */   MCD::OPC_CheckPredicate, 23, 96, 3, // Skip to: 14308
/* 13444 */   MCD::OPC_CheckField, 13, 3, 0, 90, 3, // Skip to: 14308
/* 13450 */   MCD::OPC_Decode, 139, 6, 192, 1, // Opcode: DPSU_H_QBR
/* 13455 */   MCD::OPC_FilterValue, 16, 15, 0, // Skip to: 13474
/* 13459 */   MCD::OPC_CheckPredicate, 23, 77, 3, // Skip to: 14308
/* 13463 */   MCD::OPC_CheckField, 13, 3, 0, 71, 3, // Skip to: 14308
/* 13469 */   MCD::OPC_Decode, 139, 10, 192, 1, // Opcode: MAQ_SA_W_PHL
/* 13474 */   MCD::OPC_FilterValue, 18, 15, 0, // Skip to: 13493
/* 13478 */   MCD::OPC_CheckPredicate, 23, 58, 3, // Skip to: 14308
/* 13482 */   MCD::OPC_CheckField, 13, 3, 0, 52, 3, // Skip to: 14308
/* 13488 */   MCD::OPC_Decode, 141, 10, 192, 1, // Opcode: MAQ_SA_W_PHR
/* 13493 */   MCD::OPC_FilterValue, 20, 15, 0, // Skip to: 13512
/* 13497 */   MCD::OPC_CheckPredicate, 23, 39, 3, // Skip to: 14308
/* 13501 */   MCD::OPC_CheckField, 13, 3, 0, 33, 3, // Skip to: 14308
/* 13507 */   MCD::OPC_Decode, 143, 10, 192, 1, // Opcode: MAQ_S_W_PHL
/* 13512 */   MCD::OPC_FilterValue, 22, 15, 0, // Skip to: 13531
/* 13516 */   MCD::OPC_CheckPredicate, 23, 20, 3, // Skip to: 14308
/* 13520 */   MCD::OPC_CheckField, 13, 3, 0, 14, 3, // Skip to: 14308
/* 13526 */   MCD::OPC_Decode, 145, 10, 192, 1, // Opcode: MAQ_S_W_PHR
/* 13531 */   MCD::OPC_FilterValue, 24, 15, 0, // Skip to: 13550
/* 13535 */   MCD::OPC_CheckPredicate, 48, 1, 3, // Skip to: 14308
/* 13539 */   MCD::OPC_CheckField, 13, 3, 0, 251, 2, // Skip to: 14308
/* 13545 */   MCD::OPC_Decode, 236, 5, 192, 1, // Opcode: DPAQX_S_W_PH
/* 13550 */   MCD::OPC_FilterValue, 25, 15, 0, // Skip to: 13569
/* 13554 */   MCD::OPC_CheckPredicate, 48, 238, 2, // Skip to: 14308
/* 13558 */   MCD::OPC_CheckField, 13, 3, 0, 232, 2, // Skip to: 14308
/* 13564 */   MCD::OPC_Decode, 253, 5, 192, 1, // Opcode: DPSQX_S_W_PH
/* 13569 */   MCD::OPC_FilterValue, 26, 15, 0, // Skip to: 13588
/* 13573 */   MCD::OPC_CheckPredicate, 48, 219, 2, // Skip to: 14308
/* 13577 */   MCD::OPC_CheckField, 13, 3, 0, 213, 2, // Skip to: 14308
/* 13583 */   MCD::OPC_Decode, 234, 5, 192, 1, // Opcode: DPAQX_SA_W_PH
/* 13588 */   MCD::OPC_FilterValue, 27, 204, 2, // Skip to: 14308
/* 13592 */   MCD::OPC_CheckPredicate, 48, 200, 2, // Skip to: 14308
/* 13596 */   MCD::OPC_CheckField, 13, 3, 0, 194, 2, // Skip to: 14308
/* 13602 */   MCD::OPC_Decode, 251, 5, 192, 1, // Opcode: DPSQX_SA_W_PH
/* 13607 */   MCD::OPC_FilterValue, 49, 42, 0, // Skip to: 13653
/* 13611 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 13614 */   MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 13627
/* 13618 */   MCD::OPC_CheckPredicate, 48, 174, 2, // Skip to: 14308
/* 13622 */   MCD::OPC_Decode, 128, 1, 157, 2, // Opcode: APPEND
/* 13627 */   MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 13640
/* 13631 */   MCD::OPC_CheckPredicate, 48, 161, 2, // Skip to: 14308
/* 13635 */   MCD::OPC_Decode, 241, 12, 157, 2, // Opcode: PREPEND
/* 13640 */   MCD::OPC_FilterValue, 16, 152, 2, // Skip to: 14308
/* 13644 */   MCD::OPC_CheckPredicate, 48, 148, 2, // Skip to: 14308
/* 13648 */   MCD::OPC_Decode, 204, 1, 157, 2, // Opcode: BALIGN
/* 13653 */   MCD::OPC_FilterValue, 56, 58, 1, // Skip to: 13971
/* 13657 */   MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 13660 */   MCD::OPC_FilterValue, 0, 15, 0, // Skip to: 13679
/* 13664 */   MCD::OPC_CheckPredicate, 23, 128, 2, // Skip to: 14308
/* 13668 */   MCD::OPC_CheckField, 13, 3, 0, 122, 2, // Skip to: 14308
/* 13674 */   MCD::OPC_Decode, 207, 6, 158, 2, // Opcode: EXTR_W
/* 13679 */   MCD::OPC_FilterValue, 1, 15, 0, // Skip to: 13698
/* 13683 */   MCD::OPC_CheckPredicate, 23, 109, 2, // Skip to: 14308
/* 13687 */   MCD::OPC_CheckField, 13, 3, 0, 103, 2, // Skip to: 14308
/* 13693 */   MCD::OPC_Decode, 199, 6, 159, 2, // Opcode: EXTRV_W
/* 13698 */   MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 13717
/* 13702 */   MCD::OPC_CheckPredicate, 23, 90, 2, // Skip to: 14308
/* 13706 */   MCD::OPC_CheckField, 13, 3, 0, 84, 2, // Skip to: 14308
/* 13712 */   MCD::OPC_Decode, 185, 6, 158, 2, // Opcode: EXTP
/* 13717 */   MCD::OPC_FilterValue, 3, 15, 0, // Skip to: 13736
/* 13721 */   MCD::OPC_CheckPredicate, 23, 71, 2, // Skip to: 14308
/* 13725 */   MCD::OPC_CheckField, 13, 3, 0, 65, 2, // Skip to: 14308
/* 13731 */   MCD::OPC_Decode, 190, 6, 159, 2, // Opcode: EXTPV
/* 13736 */   MCD::OPC_FilterValue, 4, 15, 0, // Skip to: 13755
/* 13740 */   MCD::OPC_CheckPredicate, 23, 52, 2, // Skip to: 14308
/* 13744 */   MCD::OPC_CheckField, 13, 3, 0, 46, 2, // Skip to: 14308
/* 13750 */   MCD::OPC_Decode, 203, 6, 158, 2, // Opcode: EXTR_R_W
/* 13755 */   MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 13774
/* 13759 */   MCD::OPC_CheckPredicate, 23, 33, 2, // Skip to: 14308
/* 13763 */   MCD::OPC_CheckField, 13, 3, 0, 27, 2, // Skip to: 14308
/* 13769 */   MCD::OPC_Decode, 195, 6, 159, 2, // Opcode: EXTRV_R_W
/* 13774 */   MCD::OPC_FilterValue, 6, 15, 0, // Skip to: 13793
/* 13778 */   MCD::OPC_CheckPredicate, 23, 14, 2, // Skip to: 14308
/* 13782 */   MCD::OPC_CheckField, 13, 3, 0, 8, 2, // Skip to: 14308
/* 13788 */   MCD::OPC_Decode, 201, 6, 158, 2, // Opcode: EXTR_RS_W
/* 13793 */   MCD::OPC_FilterValue, 7, 15, 0, // Skip to: 13812
/* 13797 */   MCD::OPC_CheckPredicate, 23, 251, 1, // Skip to: 14308
/* 13801 */   MCD::OPC_CheckField, 13, 3, 0, 245, 1, // Skip to: 14308
/* 13807 */   MCD::OPC_Decode, 193, 6, 159, 2, // Opcode: EXTRV_RS_W
/* 13812 */   MCD::OPC_FilterValue, 10, 15, 0, // Skip to: 13831
/* 13816 */   MCD::OPC_CheckPredicate, 23, 232, 1, // Skip to: 14308
/* 13820 */   MCD::OPC_CheckField, 13, 3, 0, 226, 1, // Skip to: 14308
/* 13826 */   MCD::OPC_Decode, 186, 6, 158, 2, // Opcode: EXTPDP
/* 13831 */   MCD::OPC_FilterValue, 11, 15, 0, // Skip to: 13850
/* 13835 */   MCD::OPC_CheckPredicate, 23, 213, 1, // Skip to: 14308
/* 13839 */   MCD::OPC_CheckField, 13, 3, 0, 207, 1, // Skip to: 14308
/* 13845 */   MCD::OPC_Decode, 187, 6, 159, 2, // Opcode: EXTPDPV
/* 13850 */   MCD::OPC_FilterValue, 14, 15, 0, // Skip to: 13869
/* 13854 */   MCD::OPC_CheckPredicate, 23, 194, 1, // Skip to: 14308
/* 13858 */   MCD::OPC_CheckField, 13, 3, 0, 188, 1, // Skip to: 14308
/* 13864 */   MCD::OPC_Decode, 205, 6, 158, 2, // Opcode: EXTR_S_H
/* 13869 */   MCD::OPC_FilterValue, 15, 15, 0, // Skip to: 13888
/* 13873 */   MCD::OPC_CheckPredicate, 23, 175, 1, // Skip to: 14308
/* 13877 */   MCD::OPC_CheckField, 13, 3, 0, 169, 1, // Skip to: 14308
/* 13883 */   MCD::OPC_Decode, 197, 6, 159, 2, // Opcode: EXTRV_S_H
/* 13888 */   MCD::OPC_FilterValue, 18, 9, 0, // Skip to: 13901
/* 13892 */   MCD::OPC_CheckPredicate, 23, 156, 1, // Skip to: 14308
/* 13896 */   MCD::OPC_Decode, 168, 13, 160, 2, // Opcode: RDDSP
/* 13901 */   MCD::OPC_FilterValue, 19, 9, 0, // Skip to: 13914
/* 13905 */   MCD::OPC_CheckPredicate, 23, 143, 1, // Skip to: 14308
/* 13909 */   MCD::OPC_Decode, 151, 17, 161, 2, // Opcode: WRDSP
/* 13914 */   MCD::OPC_FilterValue, 26, 15, 0, // Skip to: 13933
/* 13918 */   MCD::OPC_CheckPredicate, 23, 130, 1, // Skip to: 14308
/* 13922 */   MCD::OPC_CheckField, 13, 7, 0, 124, 1, // Skip to: 14308
/* 13928 */   MCD::OPC_Decode, 169, 14, 162, 2, // Opcode: SHILO
/* 13933 */   MCD::OPC_FilterValue, 27, 15, 0, // Skip to: 13952
/* 13937 */   MCD::OPC_CheckPredicate, 23, 111, 1, // Skip to: 14308
/* 13941 */   MCD::OPC_CheckField, 13, 8, 0, 105, 1, // Skip to: 14308
/* 13947 */   MCD::OPC_Decode, 170, 14, 163, 2, // Opcode: SHILOV
/* 13952 */   MCD::OPC_FilterValue, 31, 96, 1, // Skip to: 14308
/* 13956 */   MCD::OPC_CheckPredicate, 23, 92, 1, // Skip to: 14308
/* 13960 */   MCD::OPC_CheckField, 13, 8, 0, 86, 1, // Skip to: 14308
/* 13966 */   MCD::OPC_Decode, 190, 11, 163, 2, // Opcode: MTHLIP
/* 13971 */   MCD::OPC_FilterValue, 59, 77, 1, // Skip to: 14308
/* 13975 */   MCD::OPC_CheckPredicate, 1, 73, 1, // Skip to: 14308
/* 13979 */   MCD::OPC_CheckField, 21, 5, 0, 67, 1, // Skip to: 14308
/* 13985 */   MCD::OPC_CheckField, 6, 5, 0, 61, 1, // Skip to: 14308
/* 13991 */   MCD::OPC_Decode, 170, 13, 164, 2, // Opcode: RDHWR
/* 13996 */   MCD::OPC_FilterValue, 32, 9, 0, // Skip to: 14009
/* 14000 */   MCD::OPC_CheckPredicate, 15, 48, 1, // Skip to: 14308
/* 14004 */   MCD::OPC_Decode, 232, 8, 165, 2, // Opcode: LB
/* 14009 */   MCD::OPC_FilterValue, 33, 9, 0, // Skip to: 14022
/* 14013 */   MCD::OPC_CheckPredicate, 15, 35, 1, // Skip to: 14308
/* 14017 */   MCD::OPC_Decode, 144, 9, 165, 2, // Opcode: LH
/* 14022 */   MCD::OPC_FilterValue, 34, 9, 0, // Skip to: 14035
/* 14026 */   MCD::OPC_CheckPredicate, 22, 22, 1, // Skip to: 14308
/* 14030 */   MCD::OPC_Decode, 196, 9, 165, 2, // Opcode: LWL
/* 14035 */   MCD::OPC_FilterValue, 35, 9, 0, // Skip to: 14048
/* 14039 */   MCD::OPC_CheckPredicate, 1, 9, 1, // Skip to: 14308
/* 14043 */   MCD::OPC_Decode, 184, 9, 165, 2, // Opcode: LW
/* 14048 */   MCD::OPC_FilterValue, 36, 9, 0, // Skip to: 14061
/* 14052 */   MCD::OPC_CheckPredicate, 15, 252, 0, // Skip to: 14308
/* 14056 */   MCD::OPC_Decode, 244, 8, 165, 2, // Opcode: LBu
/* 14061 */   MCD::OPC_FilterValue, 37, 9, 0, // Skip to: 14074
/* 14065 */   MCD::OPC_CheckPredicate, 15, 239, 0, // Skip to: 14308
/* 14069 */   MCD::OPC_Decode, 152, 9, 165, 2, // Opcode: LHu
/* 14074 */   MCD::OPC_FilterValue, 38, 9, 0, // Skip to: 14087
/* 14078 */   MCD::OPC_CheckPredicate, 22, 226, 0, // Skip to: 14308
/* 14082 */   MCD::OPC_Decode, 208, 9, 165, 2, // Opcode: LWR
/* 14087 */   MCD::OPC_FilterValue, 40, 9, 0, // Skip to: 14100
/* 14091 */   MCD::OPC_CheckPredicate, 15, 213, 0, // Skip to: 14308
/* 14095 */   MCD::OPC_Decode, 222, 13, 165, 2, // Opcode: SB
/* 14100 */   MCD::OPC_FilterValue, 41, 9, 0, // Skip to: 14113
/* 14104 */   MCD::OPC_CheckPredicate, 15, 200, 0, // Skip to: 14308
/* 14108 */   MCD::OPC_Decode, 159, 14, 165, 2, // Opcode: SH
/* 14113 */   MCD::OPC_FilterValue, 42, 9, 0, // Skip to: 14126
/* 14117 */   MCD::OPC_CheckPredicate, 22, 187, 0, // Skip to: 14308
/* 14121 */   MCD::OPC_Decode, 141, 16, 165, 2, // Opcode: SWL
/* 14126 */   MCD::OPC_FilterValue, 43, 9, 0, // Skip to: 14139
/* 14130 */   MCD::OPC_CheckPredicate, 1, 174, 0, // Skip to: 14308
/* 14134 */   MCD::OPC_Decode, 129, 16, 165, 2, // Opcode: SW
/* 14139 */   MCD::OPC_FilterValue, 46, 9, 0, // Skip to: 14152
/* 14143 */   MCD::OPC_CheckPredicate, 22, 161, 0, // Skip to: 14308
/* 14147 */   MCD::OPC_Decode, 151, 16, 165, 2, // Opcode: SWR
/* 14152 */   MCD::OPC_FilterValue, 47, 9, 0, // Skip to: 14165
/* 14156 */   MCD::OPC_CheckPredicate, 51, 148, 0, // Skip to: 14308
/* 14160 */   MCD::OPC_Decode, 163, 3, 166, 2, // Opcode: CACHE
/* 14165 */   MCD::OPC_FilterValue, 48, 9, 0, // Skip to: 14178
/* 14169 */   MCD::OPC_CheckPredicate, 52, 135, 0, // Skip to: 14308
/* 14173 */   MCD::OPC_Decode, 159, 9, 165, 2, // Opcode: LL
/* 14178 */   MCD::OPC_FilterValue, 49, 9, 0, // Skip to: 14191
/* 14182 */   MCD::OPC_CheckPredicate, 32, 122, 0, // Skip to: 14308
/* 14186 */   MCD::OPC_Decode, 187, 9, 167, 2, // Opcode: LWC1
/* 14191 */   MCD::OPC_FilterValue, 50, 9, 0, // Skip to: 14204
/* 14195 */   MCD::OPC_CheckPredicate, 53, 109, 0, // Skip to: 14308
/* 14199 */   MCD::OPC_Decode, 189, 9, 168, 2, // Opcode: LWC2
/* 14204 */   MCD::OPC_FilterValue, 51, 9, 0, // Skip to: 14217
/* 14208 */   MCD::OPC_CheckPredicate, 51, 96, 0, // Skip to: 14308
/* 14212 */   MCD::OPC_Decode, 233, 12, 166, 2, // Opcode: PREF
/* 14217 */   MCD::OPC_FilterValue, 53, 9, 0, // Skip to: 14230
/* 14221 */   MCD::OPC_CheckPredicate, 40, 83, 0, // Skip to: 14308
/* 14225 */   MCD::OPC_Decode, 250, 8, 167, 2, // Opcode: LDC1
/* 14230 */   MCD::OPC_FilterValue, 54, 9, 0, // Skip to: 14243
/* 14234 */   MCD::OPC_CheckPredicate, 54, 70, 0, // Skip to: 14308
/* 14238 */   MCD::OPC_Decode, 253, 8, 168, 2, // Opcode: LDC2
/* 14243 */   MCD::OPC_FilterValue, 56, 9, 0, // Skip to: 14256
/* 14247 */   MCD::OPC_CheckPredicate, 52, 57, 0, // Skip to: 14308
/* 14251 */   MCD::OPC_Decode, 231, 13, 165, 2, // Opcode: SC
/* 14256 */   MCD::OPC_FilterValue, 57, 9, 0, // Skip to: 14269
/* 14260 */   MCD::OPC_CheckPredicate, 32, 44, 0, // Skip to: 14308
/* 14264 */   MCD::OPC_Decode, 133, 16, 167, 2, // Opcode: SWC1
/* 14269 */   MCD::OPC_FilterValue, 58, 9, 0, // Skip to: 14282
/* 14273 */   MCD::OPC_CheckPredicate, 53, 31, 0, // Skip to: 14308
/* 14277 */   MCD::OPC_Decode, 135, 16, 168, 2, // Opcode: SWC2
/* 14282 */   MCD::OPC_FilterValue, 61, 9, 0, // Skip to: 14295
/* 14286 */   MCD::OPC_CheckPredicate, 40, 18, 0, // Skip to: 14308
/* 14290 */   MCD::OPC_Decode, 246, 13, 167, 2, // Opcode: SDC1
/* 14295 */   MCD::OPC_FilterValue, 62, 9, 0, // Skip to: 14308
/* 14299 */   MCD::OPC_CheckPredicate, 54, 5, 0, // Skip to: 14308
/* 14303 */   MCD::OPC_Decode, 249, 13, 168, 2, // Opcode: SDC2
/* 14308 */   MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableMips32r6_64r632[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 0, 197, 1, // Skip to: 460
/* 7 */       MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 10 */      MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 29
/* 14 */      MCD::OPC_CheckPredicate, 55, 40, 7, // Skip to: 1850
/* 18 */      MCD::OPC_CheckField, 8, 3, 0, 34, 7, // Skip to: 1850
/* 24 */      MCD::OPC_Decode, 176, 9, 136, 1, // Opcode: LSA_R6
/* 29 */      MCD::OPC_FilterValue, 9, 15, 0, // Skip to: 48
/* 33 */      MCD::OPC_CheckPredicate, 55, 21, 7, // Skip to: 1850
/* 37 */      MCD::OPC_CheckField, 6, 15, 16, 15, 7, // Skip to: 1850
/* 43 */      MCD::OPC_Decode, 221, 8, 137, 1, // Opcode: JR_HB_R6
/* 48 */      MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 61
/* 52 */      MCD::OPC_CheckPredicate, 56, 2, 7, // Skip to: 1850
/* 56 */      MCD::OPC_Decode, 245, 13, 139, 1, // Opcode: SDBBP_R6
/* 61 */      MCD::OPC_FilterValue, 16, 20, 0, // Skip to: 85
/* 65 */      MCD::OPC_CheckPredicate, 55, 245, 6, // Skip to: 1850
/* 69 */      MCD::OPC_CheckField, 16, 5, 0, 239, 6, // Skip to: 1850
/* 75 */      MCD::OPC_CheckField, 6, 5, 1, 233, 6, // Skip to: 1850
/* 81 */      MCD::OPC_Decode, 237, 3, 14, // Opcode: CLZ_R6
/* 85 */      MCD::OPC_FilterValue, 17, 20, 0, // Skip to: 109
/* 89 */      MCD::OPC_CheckPredicate, 55, 221, 6, // Skip to: 1850
/* 93 */      MCD::OPC_CheckField, 16, 5, 0, 215, 6, // Skip to: 1850
/* 99 */      MCD::OPC_CheckField, 6, 5, 1, 209, 6, // Skip to: 1850
/* 105 */     MCD::OPC_Decode, 217, 3, 14, // Opcode: CLO_R6
/* 109 */     MCD::OPC_FilterValue, 18, 20, 0, // Skip to: 133
/* 113 */     MCD::OPC_CheckPredicate, 57, 197, 6, // Skip to: 1850
/* 117 */     MCD::OPC_CheckField, 16, 5, 0, 191, 6, // Skip to: 1850
/* 123 */     MCD::OPC_CheckField, 6, 5, 1, 185, 6, // Skip to: 1850
/* 129 */     MCD::OPC_Decode, 171, 5, 15, // Opcode: DCLZ_R6
/* 133 */     MCD::OPC_FilterValue, 19, 20, 0, // Skip to: 157
/* 137 */     MCD::OPC_CheckPredicate, 57, 173, 6, // Skip to: 1850
/* 141 */     MCD::OPC_CheckField, 16, 5, 0, 167, 6, // Skip to: 1850
/* 147 */     MCD::OPC_CheckField, 6, 5, 1, 161, 6, // Skip to: 1850
/* 153 */     MCD::OPC_Decode, 169, 5, 15, // Opcode: DCLO_R6
/* 157 */     MCD::OPC_FilterValue, 21, 15, 0, // Skip to: 176
/* 161 */     MCD::OPC_CheckPredicate, 57, 149, 6, // Skip to: 1850
/* 165 */     MCD::OPC_CheckField, 8, 3, 0, 143, 6, // Skip to: 1850
/* 171 */     MCD::OPC_Decode, 202, 5, 145, 1, // Opcode: DLSA_R6
/* 176 */     MCD::OPC_FilterValue, 24, 27, 0, // Skip to: 207
/* 180 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 183 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 195
/* 187 */     MCD::OPC_CheckPredicate, 55, 123, 6, // Skip to: 1850
/* 191 */     MCD::OPC_Decode, 248, 11, 47, // Opcode: MUL_R6
/* 195 */     MCD::OPC_FilterValue, 3, 115, 6, // Skip to: 1850
/* 199 */     MCD::OPC_CheckPredicate, 55, 111, 6, // Skip to: 1850
/* 203 */     MCD::OPC_Decode, 203, 11, 47, // Opcode: MUH
/* 207 */     MCD::OPC_FilterValue, 25, 27, 0, // Skip to: 238
/* 211 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 214 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 226
/* 218 */     MCD::OPC_CheckPredicate, 55, 92, 6, // Skip to: 1850
/* 222 */     MCD::OPC_Decode, 236, 11, 47, // Opcode: MULU
/* 226 */     MCD::OPC_FilterValue, 3, 84, 6, // Skip to: 1850
/* 230 */     MCD::OPC_CheckPredicate, 55, 80, 6, // Skip to: 1850
/* 234 */     MCD::OPC_Decode, 204, 11, 47, // Opcode: MUHU
/* 238 */     MCD::OPC_FilterValue, 26, 27, 0, // Skip to: 269
/* 242 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 245 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 257
/* 249 */     MCD::OPC_CheckPredicate, 55, 61, 6, // Skip to: 1850
/* 253 */     MCD::OPC_Decode, 188, 5, 47, // Opcode: DIV
/* 257 */     MCD::OPC_FilterValue, 3, 53, 6, // Skip to: 1850
/* 261 */     MCD::OPC_CheckPredicate, 55, 49, 6, // Skip to: 1850
/* 265 */     MCD::OPC_Decode, 224, 10, 47, // Opcode: MOD
/* 269 */     MCD::OPC_FilterValue, 27, 27, 0, // Skip to: 300
/* 273 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 276 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 288
/* 280 */     MCD::OPC_CheckPredicate, 55, 30, 6, // Skip to: 1850
/* 284 */     MCD::OPC_Decode, 189, 5, 47, // Opcode: DIVU
/* 288 */     MCD::OPC_FilterValue, 3, 22, 6, // Skip to: 1850
/* 292 */     MCD::OPC_CheckPredicate, 55, 18, 6, // Skip to: 1850
/* 296 */     MCD::OPC_Decode, 226, 10, 47, // Opcode: MODU
/* 300 */     MCD::OPC_FilterValue, 28, 27, 0, // Skip to: 331
/* 304 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 307 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 319
/* 311 */     MCD::OPC_CheckPredicate, 57, 255, 5, // Skip to: 1850
/* 315 */     MCD::OPC_Decode, 221, 5, 12, // Opcode: DMUL_R6
/* 319 */     MCD::OPC_FilterValue, 3, 247, 5, // Skip to: 1850
/* 323 */     MCD::OPC_CheckPredicate, 57, 243, 5, // Skip to: 1850
/* 327 */     MCD::OPC_Decode, 215, 5, 12, // Opcode: DMUH
/* 331 */     MCD::OPC_FilterValue, 29, 27, 0, // Skip to: 362
/* 335 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 338 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 350
/* 342 */     MCD::OPC_CheckPredicate, 57, 224, 5, // Skip to: 1850
/* 346 */     MCD::OPC_Decode, 220, 5, 12, // Opcode: DMULU
/* 350 */     MCD::OPC_FilterValue, 3, 216, 5, // Skip to: 1850
/* 354 */     MCD::OPC_CheckPredicate, 57, 212, 5, // Skip to: 1850
/* 358 */     MCD::OPC_Decode, 216, 5, 12, // Opcode: DMUHU
/* 362 */     MCD::OPC_FilterValue, 30, 27, 0, // Skip to: 393
/* 366 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 369 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 381
/* 373 */     MCD::OPC_CheckPredicate, 57, 193, 5, // Skip to: 1850
/* 377 */     MCD::OPC_Decode, 172, 5, 12, // Opcode: DDIV
/* 381 */     MCD::OPC_FilterValue, 3, 185, 5, // Skip to: 1850
/* 385 */     MCD::OPC_CheckPredicate, 57, 181, 5, // Skip to: 1850
/* 389 */     MCD::OPC_Decode, 207, 5, 12, // Opcode: DMOD
/* 393 */     MCD::OPC_FilterValue, 31, 27, 0, // Skip to: 424
/* 397 */     MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 400 */     MCD::OPC_FilterValue, 2, 8, 0, // Skip to: 412
/* 404 */     MCD::OPC_CheckPredicate, 57, 162, 5, // Skip to: 1850
/* 408 */     MCD::OPC_Decode, 173, 5, 12, // Opcode: DDIVU
/* 412 */     MCD::OPC_FilterValue, 3, 154, 5, // Skip to: 1850
/* 416 */     MCD::OPC_CheckPredicate, 57, 150, 5, // Skip to: 1850
/* 420 */     MCD::OPC_Decode, 208, 5, 12, // Opcode: DMODU
/* 424 */     MCD::OPC_FilterValue, 53, 14, 0, // Skip to: 442
/* 428 */     MCD::OPC_CheckPredicate, 58, 138, 5, // Skip to: 1850
/* 432 */     MCD::OPC_CheckField, 6, 5, 0, 132, 5, // Skip to: 1850
/* 438 */     MCD::OPC_Decode, 141, 14, 47, // Opcode: SELEQZ
/* 442 */     MCD::OPC_FilterValue, 55, 124, 5, // Skip to: 1850
/* 446 */     MCD::OPC_CheckPredicate, 58, 120, 5, // Skip to: 1850
/* 450 */     MCD::OPC_CheckField, 6, 5, 0, 114, 5, // Skip to: 1850
/* 456 */     MCD::OPC_Decode, 148, 14, 47, // Opcode: SELNEZ
/* 460 */     MCD::OPC_FilterValue, 1, 48, 0, // Skip to: 512
/* 464 */     MCD::OPC_ExtractField, 16, 5,  // Inst{20-16} ...
/* 467 */     MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 480
/* 471 */     MCD::OPC_CheckPredicate, 59, 95, 5, // Skip to: 1850
/* 475 */     MCD::OPC_Decode, 159, 5, 169, 2, // Opcode: DAHI
/* 480 */     MCD::OPC_FilterValue, 17, 15, 0, // Skip to: 499
/* 484 */     MCD::OPC_CheckPredicate, 55, 82, 5, // Skip to: 1850
/* 488 */     MCD::OPC_CheckField, 21, 5, 0, 76, 5, // Skip to: 1850
/* 494 */     MCD::OPC_Decode, 201, 1, 149, 1, // Opcode: BAL
/* 499 */     MCD::OPC_FilterValue, 30, 67, 5, // Skip to: 1850
/* 503 */     MCD::OPC_CheckPredicate, 59, 63, 5, // Skip to: 1850
/* 507 */     MCD::OPC_Decode, 163, 5, 169, 2, // Opcode: DATI
/* 512 */     MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 525
/* 516 */     MCD::OPC_CheckPredicate, 55, 50, 5, // Skip to: 1850
/* 520 */     MCD::OPC_Decode, 255, 1, 170, 2, // Opcode: BGEZALC
/* 525 */     MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 538
/* 529 */     MCD::OPC_CheckPredicate, 55, 37, 5, // Skip to: 1850
/* 533 */     MCD::OPC_Decode, 197, 2, 171, 2, // Opcode: BLTZALC
/* 538 */     MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 551
/* 542 */     MCD::OPC_CheckPredicate, 55, 24, 5, // Skip to: 1850
/* 546 */     MCD::OPC_Decode, 233, 1, 172, 2, // Opcode: BEQC
/* 551 */     MCD::OPC_FilterValue, 15, 8, 0, // Skip to: 563
/* 555 */     MCD::OPC_CheckPredicate, 55, 11, 5, // Skip to: 1850
/* 559 */     MCD::OPC_Decode, 169, 1, 78, // Opcode: AUI
/* 563 */     MCD::OPC_FilterValue, 17, 15, 3, // Skip to: 1350
/* 567 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 570 */     MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 583
/* 574 */     MCD::OPC_CheckPredicate, 60, 248, 4, // Skip to: 1850
/* 578 */     MCD::OPC_Decode, 212, 1, 173, 2, // Opcode: BC1EQZ
/* 583 */     MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 596
/* 587 */     MCD::OPC_CheckPredicate, 60, 235, 4, // Skip to: 1850
/* 591 */     MCD::OPC_Decode, 216, 1, 173, 2, // Opcode: BC1NEZ
/* 596 */     MCD::OPC_FilterValue, 16, 158, 0, // Skip to: 758
/* 600 */     MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 603 */     MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 616
/* 607 */     MCD::OPC_CheckPredicate, 61, 215, 4, // Skip to: 1850
/* 611 */     MCD::OPC_Decode, 155, 14, 174, 2, // Opcode: SEL_S
/* 616 */     MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 629
/* 620 */     MCD::OPC_CheckPredicate, 61, 202, 4, // Skip to: 1850
/* 624 */     MCD::OPC_Decode, 146, 14, 167, 1, // Opcode: SELEQZ_S
/* 629 */     MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 642
/* 633 */     MCD::OPC_CheckPredicate, 61, 189, 4, // Skip to: 1850
/* 637 */     MCD::OPC_Decode, 152, 14, 167, 1, // Opcode: SELNEZ_S
/* 642 */     MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 655
/* 646 */     MCD::OPC_CheckPredicate, 61, 176, 4, // Skip to: 1850
/* 650 */     MCD::OPC_Decode, 245, 9, 175, 2, // Opcode: MADDF_S
/* 655 */     MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 668
/* 659 */     MCD::OPC_CheckPredicate, 61, 163, 4, // Skip to: 1850
/* 663 */     MCD::OPC_Decode, 156, 11, 175, 2, // Opcode: MSUBF_S
/* 668 */     MCD::OPC_FilterValue, 26, 15, 0, // Skip to: 687
/* 672 */     MCD::OPC_CheckPredicate, 61, 150, 4, // Skip to: 1850
/* 676 */     MCD::OPC_CheckField, 16, 5, 0, 144, 4, // Skip to: 1850
/* 682 */     MCD::OPC_Decode, 187, 13, 168, 1, // Opcode: RINT_S
/* 687 */     MCD::OPC_FilterValue, 27, 15, 0, // Skip to: 706
/* 691 */     MCD::OPC_CheckPredicate, 61, 131, 4, // Skip to: 1850
/* 695 */     MCD::OPC_CheckField, 16, 5, 0, 125, 4, // Skip to: 1850
/* 701 */     MCD::OPC_Decode, 196, 3, 168, 1, // Opcode: CLASS_S
/* 706 */     MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 719
/* 710 */     MCD::OPC_CheckPredicate, 61, 112, 4, // Skip to: 1850
/* 714 */     MCD::OPC_Decode, 212, 10, 167, 1, // Opcode: MIN_S
/* 719 */     MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 732
/* 723 */     MCD::OPC_CheckPredicate, 61, 99, 4, // Skip to: 1850
/* 727 */     MCD::OPC_Decode, 165, 10, 167, 1, // Opcode: MAX_S
/* 732 */     MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 745
/* 736 */     MCD::OPC_CheckPredicate, 61, 86, 4, // Skip to: 1850
/* 740 */     MCD::OPC_Decode, 196, 10, 167, 1, // Opcode: MINA_S
/* 745 */     MCD::OPC_FilterValue, 31, 77, 4, // Skip to: 1850
/* 749 */     MCD::OPC_CheckPredicate, 61, 73, 4, // Skip to: 1850
/* 753 */     MCD::OPC_Decode, 149, 10, 167, 1, // Opcode: MAXA_S
/* 758 */     MCD::OPC_FilterValue, 17, 158, 0, // Skip to: 920
/* 762 */     MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 765 */     MCD::OPC_FilterValue, 16, 9, 0, // Skip to: 778
/* 769 */     MCD::OPC_CheckPredicate, 61, 53, 4, // Skip to: 1850
/* 773 */     MCD::OPC_Decode, 153, 14, 176, 2, // Opcode: SEL_D
/* 778 */     MCD::OPC_FilterValue, 20, 9, 0, // Skip to: 791
/* 782 */     MCD::OPC_CheckPredicate, 61, 40, 4, // Skip to: 1850
/* 786 */     MCD::OPC_Decode, 143, 14, 177, 2, // Opcode: SELEQZ_D
/* 791 */     MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 804
/* 795 */     MCD::OPC_CheckPredicate, 61, 27, 4, // Skip to: 1850
/* 799 */     MCD::OPC_Decode, 150, 14, 177, 2, // Opcode: SELNEZ_D
/* 804 */     MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 817
/* 808 */     MCD::OPC_CheckPredicate, 61, 14, 4, // Skip to: 1850
/* 812 */     MCD::OPC_Decode, 243, 9, 178, 2, // Opcode: MADDF_D
/* 817 */     MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 830
/* 821 */     MCD::OPC_CheckPredicate, 61, 1, 4, // Skip to: 1850
/* 825 */     MCD::OPC_Decode, 154, 11, 178, 2, // Opcode: MSUBF_D
/* 830 */     MCD::OPC_FilterValue, 26, 15, 0, // Skip to: 849
/* 834 */     MCD::OPC_CheckPredicate, 61, 244, 3, // Skip to: 1850
/* 838 */     MCD::OPC_CheckField, 16, 5, 0, 238, 3, // Skip to: 1850
/* 844 */     MCD::OPC_Decode, 185, 13, 179, 1, // Opcode: RINT_D
/* 849 */     MCD::OPC_FilterValue, 27, 15, 0, // Skip to: 868
/* 853 */     MCD::OPC_CheckPredicate, 61, 225, 3, // Skip to: 1850
/* 857 */     MCD::OPC_CheckField, 16, 5, 0, 219, 3, // Skip to: 1850
/* 863 */     MCD::OPC_Decode, 194, 3, 179, 1, // Opcode: CLASS_D
/* 868 */     MCD::OPC_FilterValue, 28, 9, 0, // Skip to: 881
/* 872 */     MCD::OPC_CheckPredicate, 61, 206, 3, // Skip to: 1850
/* 876 */     MCD::OPC_Decode, 210, 10, 177, 2, // Opcode: MIN_D
/* 881 */     MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 894
/* 885 */     MCD::OPC_CheckPredicate, 61, 193, 3, // Skip to: 1850
/* 889 */     MCD::OPC_Decode, 163, 10, 177, 2, // Opcode: MAX_D
/* 894 */     MCD::OPC_FilterValue, 30, 9, 0, // Skip to: 907
/* 898 */     MCD::OPC_CheckPredicate, 61, 180, 3, // Skip to: 1850
/* 902 */     MCD::OPC_Decode, 194, 10, 177, 2, // Opcode: MINA_D
/* 907 */     MCD::OPC_FilterValue, 31, 171, 3, // Skip to: 1850
/* 911 */     MCD::OPC_CheckPredicate, 61, 167, 3, // Skip to: 1850
/* 915 */     MCD::OPC_Decode, 147, 10, 177, 2, // Opcode: MAXA_D
/* 920 */     MCD::OPC_FilterValue, 20, 211, 0, // Skip to: 1135
/* 924 */     MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 927 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 940
/* 931 */     MCD::OPC_CheckPredicate, 61, 147, 3, // Skip to: 1850
/* 935 */     MCD::OPC_Decode, 255, 3, 179, 2, // Opcode: CMP_F_S
/* 940 */     MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 953
/* 944 */     MCD::OPC_CheckPredicate, 61, 134, 3, // Skip to: 1850
/* 948 */     MCD::OPC_Decode, 184, 4, 179, 2, // Opcode: CMP_UN_S
/* 953 */     MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 966
/* 957 */     MCD::OPC_CheckPredicate, 61, 121, 3, // Skip to: 1850
/* 961 */     MCD::OPC_Decode, 252, 3, 179, 2, // Opcode: CMP_EQ_S
/* 966 */     MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 979
/* 970 */     MCD::OPC_CheckPredicate, 61, 108, 3, // Skip to: 1850
/* 974 */     MCD::OPC_Decode, 172, 4, 179, 2, // Opcode: CMP_UEQ_S
/* 979 */     MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 992
/* 983 */     MCD::OPC_CheckPredicate, 61, 95, 3, // Skip to: 1850
/* 987 */     MCD::OPC_Decode, 136, 4, 179, 2, // Opcode: CMP_LT_S
/* 992 */     MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 1005
/* 996 */     MCD::OPC_CheckPredicate, 61, 82, 3, // Skip to: 1850
/* 1000 */    MCD::OPC_Decode, 180, 4, 179, 2, // Opcode: CMP_ULT_S
/* 1005 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 1018
/* 1009 */    MCD::OPC_CheckPredicate, 61, 69, 3, // Skip to: 1850
/* 1013 */    MCD::OPC_Decode, 131, 4, 179, 2, // Opcode: CMP_LE_S
/* 1018 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 1031
/* 1022 */    MCD::OPC_CheckPredicate, 61, 56, 3, // Skip to: 1850
/* 1026 */    MCD::OPC_Decode, 176, 4, 179, 2, // Opcode: CMP_ULE_S
/* 1031 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 1044
/* 1035 */    MCD::OPC_CheckPredicate, 61, 43, 3, // Skip to: 1850
/* 1039 */    MCD::OPC_Decode, 140, 4, 179, 2, // Opcode: CMP_SAF_S
/* 1044 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 1057
/* 1048 */    MCD::OPC_CheckPredicate, 61, 30, 3, // Skip to: 1850
/* 1052 */    MCD::OPC_Decode, 168, 4, 179, 2, // Opcode: CMP_SUN_S
/* 1057 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 1070
/* 1061 */    MCD::OPC_CheckPredicate, 61, 17, 3, // Skip to: 1850
/* 1065 */    MCD::OPC_Decode, 144, 4, 179, 2, // Opcode: CMP_SEQ_S
/* 1070 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 1083
/* 1074 */    MCD::OPC_CheckPredicate, 61, 4, 3, // Skip to: 1850
/* 1078 */    MCD::OPC_Decode, 156, 4, 179, 2, // Opcode: CMP_SUEQ_S
/* 1083 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 1096
/* 1087 */    MCD::OPC_CheckPredicate, 61, 247, 2, // Skip to: 1850
/* 1091 */    MCD::OPC_Decode, 152, 4, 179, 2, // Opcode: CMP_SLT_S
/* 1096 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 1109
/* 1100 */    MCD::OPC_CheckPredicate, 61, 234, 2, // Skip to: 1850
/* 1104 */    MCD::OPC_Decode, 164, 4, 179, 2, // Opcode: CMP_SULT_S
/* 1109 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 1122
/* 1113 */    MCD::OPC_CheckPredicate, 61, 221, 2, // Skip to: 1850
/* 1117 */    MCD::OPC_Decode, 148, 4, 179, 2, // Opcode: CMP_SLE_S
/* 1122 */    MCD::OPC_FilterValue, 15, 212, 2, // Skip to: 1850
/* 1126 */    MCD::OPC_CheckPredicate, 61, 208, 2, // Skip to: 1850
/* 1130 */    MCD::OPC_Decode, 160, 4, 179, 2, // Opcode: CMP_SULE_S
/* 1135 */    MCD::OPC_FilterValue, 21, 199, 2, // Skip to: 1850
/* 1139 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 1142 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 1155
/* 1146 */    MCD::OPC_CheckPredicate, 61, 188, 2, // Skip to: 1850
/* 1150 */    MCD::OPC_Decode, 254, 3, 180, 2, // Opcode: CMP_F_D
/* 1155 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 1168
/* 1159 */    MCD::OPC_CheckPredicate, 61, 175, 2, // Skip to: 1850
/* 1163 */    MCD::OPC_Decode, 182, 4, 180, 2, // Opcode: CMP_UN_D
/* 1168 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 1181
/* 1172 */    MCD::OPC_CheckPredicate, 61, 162, 2, // Skip to: 1850
/* 1176 */    MCD::OPC_Decode, 249, 3, 180, 2, // Opcode: CMP_EQ_D
/* 1181 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 1194
/* 1185 */    MCD::OPC_CheckPredicate, 61, 149, 2, // Skip to: 1850
/* 1189 */    MCD::OPC_Decode, 170, 4, 180, 2, // Opcode: CMP_UEQ_D
/* 1194 */    MCD::OPC_FilterValue, 4, 9, 0, // Skip to: 1207
/* 1198 */    MCD::OPC_CheckPredicate, 61, 136, 2, // Skip to: 1850
/* 1202 */    MCD::OPC_Decode, 133, 4, 180, 2, // Opcode: CMP_LT_D
/* 1207 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 1220
/* 1211 */    MCD::OPC_CheckPredicate, 61, 123, 2, // Skip to: 1850
/* 1215 */    MCD::OPC_Decode, 178, 4, 180, 2, // Opcode: CMP_ULT_D
/* 1220 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 1233
/* 1224 */    MCD::OPC_CheckPredicate, 61, 110, 2, // Skip to: 1850
/* 1228 */    MCD::OPC_Decode, 128, 4, 180, 2, // Opcode: CMP_LE_D
/* 1233 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 1246
/* 1237 */    MCD::OPC_CheckPredicate, 61, 97, 2, // Skip to: 1850
/* 1241 */    MCD::OPC_Decode, 174, 4, 180, 2, // Opcode: CMP_ULE_D
/* 1246 */    MCD::OPC_FilterValue, 8, 9, 0, // Skip to: 1259
/* 1250 */    MCD::OPC_CheckPredicate, 61, 84, 2, // Skip to: 1850
/* 1254 */    MCD::OPC_Decode, 138, 4, 180, 2, // Opcode: CMP_SAF_D
/* 1259 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 1272
/* 1263 */    MCD::OPC_CheckPredicate, 61, 71, 2, // Skip to: 1850
/* 1267 */    MCD::OPC_Decode, 166, 4, 180, 2, // Opcode: CMP_SUN_D
/* 1272 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 1285
/* 1276 */    MCD::OPC_CheckPredicate, 61, 58, 2, // Skip to: 1850
/* 1280 */    MCD::OPC_Decode, 142, 4, 180, 2, // Opcode: CMP_SEQ_D
/* 1285 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 1298
/* 1289 */    MCD::OPC_CheckPredicate, 61, 45, 2, // Skip to: 1850
/* 1293 */    MCD::OPC_Decode, 154, 4, 180, 2, // Opcode: CMP_SUEQ_D
/* 1298 */    MCD::OPC_FilterValue, 12, 9, 0, // Skip to: 1311
/* 1302 */    MCD::OPC_CheckPredicate, 61, 32, 2, // Skip to: 1850
/* 1306 */    MCD::OPC_Decode, 150, 4, 180, 2, // Opcode: CMP_SLT_D
/* 1311 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 1324
/* 1315 */    MCD::OPC_CheckPredicate, 61, 19, 2, // Skip to: 1850
/* 1319 */    MCD::OPC_Decode, 162, 4, 180, 2, // Opcode: CMP_SULT_D
/* 1324 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 1337
/* 1328 */    MCD::OPC_CheckPredicate, 61, 6, 2, // Skip to: 1850
/* 1332 */    MCD::OPC_Decode, 146, 4, 180, 2, // Opcode: CMP_SLE_D
/* 1337 */    MCD::OPC_FilterValue, 15, 253, 1, // Skip to: 1850
/* 1341 */    MCD::OPC_CheckPredicate, 61, 249, 1, // Skip to: 1850
/* 1345 */    MCD::OPC_Decode, 158, 4, 180, 2, // Opcode: CMP_SULE_D
/* 1350 */    MCD::OPC_FilterValue, 18, 81, 0, // Skip to: 1435
/* 1354 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 1357 */    MCD::OPC_FilterValue, 9, 9, 0, // Skip to: 1370
/* 1361 */    MCD::OPC_CheckPredicate, 55, 229, 1, // Skip to: 1850
/* 1365 */    MCD::OPC_Decode, 220, 1, 181, 2, // Opcode: BC2EQZ
/* 1370 */    MCD::OPC_FilterValue, 10, 9, 0, // Skip to: 1383
/* 1374 */    MCD::OPC_CheckPredicate, 55, 216, 1, // Skip to: 1850
/* 1378 */    MCD::OPC_Decode, 190, 9, 182, 2, // Opcode: LWC2_R6
/* 1383 */    MCD::OPC_FilterValue, 11, 9, 0, // Skip to: 1396
/* 1387 */    MCD::OPC_CheckPredicate, 55, 203, 1, // Skip to: 1850
/* 1391 */    MCD::OPC_Decode, 136, 16, 182, 2, // Opcode: SWC2_R6
/* 1396 */    MCD::OPC_FilterValue, 13, 9, 0, // Skip to: 1409
/* 1400 */    MCD::OPC_CheckPredicate, 55, 190, 1, // Skip to: 1850
/* 1404 */    MCD::OPC_Decode, 221, 1, 181, 2, // Opcode: BC2NEZ
/* 1409 */    MCD::OPC_FilterValue, 14, 9, 0, // Skip to: 1422
/* 1413 */    MCD::OPC_CheckPredicate, 55, 177, 1, // Skip to: 1850
/* 1417 */    MCD::OPC_Decode, 254, 8, 182, 2, // Opcode: LDC2_R6
/* 1422 */    MCD::OPC_FilterValue, 15, 168, 1, // Skip to: 1850
/* 1426 */    MCD::OPC_CheckPredicate, 55, 164, 1, // Skip to: 1850
/* 1430 */    MCD::OPC_Decode, 250, 13, 182, 2, // Opcode: SDC2_R6
/* 1435 */    MCD::OPC_FilterValue, 22, 9, 0, // Skip to: 1448
/* 1439 */    MCD::OPC_CheckPredicate, 55, 151, 1, // Skip to: 1850
/* 1443 */    MCD::OPC_Decode, 132, 2, 183, 2, // Opcode: BGEZC
/* 1448 */    MCD::OPC_FilterValue, 23, 9, 0, // Skip to: 1461
/* 1452 */    MCD::OPC_CheckPredicate, 55, 138, 1, // Skip to: 1850
/* 1456 */    MCD::OPC_Decode, 202, 2, 184, 2, // Opcode: BLTZC
/* 1461 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 1474
/* 1465 */    MCD::OPC_CheckPredicate, 55, 125, 1, // Skip to: 1850
/* 1469 */    MCD::OPC_Decode, 211, 2, 185, 2, // Opcode: BNEC
/* 1474 */    MCD::OPC_FilterValue, 29, 9, 0, // Skip to: 1487
/* 1478 */    MCD::OPC_CheckPredicate, 59, 112, 1, // Skip to: 1850
/* 1482 */    MCD::OPC_Decode, 165, 5, 133, 1, // Opcode: DAUI
/* 1487 */    MCD::OPC_FilterValue, 31, 182, 0, // Skip to: 1673
/* 1491 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 1494 */    MCD::OPC_FilterValue, 32, 40, 0, // Skip to: 1538
/* 1498 */    MCD::OPC_ExtractField, 8, 3,  // Inst{10-8} ...
/* 1501 */    MCD::OPC_FilterValue, 0, 21, 0, // Skip to: 1526
/* 1505 */    MCD::OPC_CheckPredicate, 55, 85, 1, // Skip to: 1850
/* 1509 */    MCD::OPC_CheckField, 21, 5, 0, 79, 1, // Skip to: 1850
/* 1515 */    MCD::OPC_CheckField, 6, 2, 0, 73, 1, // Skip to: 1850
/* 1521 */    MCD::OPC_Decode, 167, 2, 151, 2, // Opcode: BITSWAP
/* 1526 */    MCD::OPC_FilterValue, 2, 64, 1, // Skip to: 1850
/* 1530 */    MCD::OPC_CheckPredicate, 55, 60, 1, // Skip to: 1850
/* 1534 */    MCD::OPC_Decode, 107, 186, 2, // Opcode: ALIGN
/* 1538 */    MCD::OPC_FilterValue, 36, 41, 0, // Skip to: 1583
/* 1542 */    MCD::OPC_ExtractField, 9, 2,  // Inst{10-9} ...
/* 1545 */    MCD::OPC_FilterValue, 0, 21, 0, // Skip to: 1570
/* 1549 */    MCD::OPC_CheckPredicate, 57, 41, 1, // Skip to: 1850
/* 1553 */    MCD::OPC_CheckField, 21, 5, 0, 35, 1, // Skip to: 1850
/* 1559 */    MCD::OPC_CheckField, 6, 3, 0, 29, 1, // Skip to: 1850
/* 1565 */    MCD::OPC_Decode, 167, 5, 187, 2, // Opcode: DBITSWAP
/* 1570 */    MCD::OPC_FilterValue, 1, 20, 1, // Skip to: 1850
/* 1574 */    MCD::OPC_CheckPredicate, 59, 16, 1, // Skip to: 1850
/* 1578 */    MCD::OPC_Decode, 161, 5, 188, 2, // Opcode: DALIGN
/* 1583 */    MCD::OPC_FilterValue, 37, 15, 0, // Skip to: 1602
/* 1587 */    MCD::OPC_CheckPredicate, 55, 3, 1, // Skip to: 1850
/* 1591 */    MCD::OPC_CheckField, 6, 1, 0, 253, 0, // Skip to: 1850
/* 1597 */    MCD::OPC_Decode, 169, 3, 156, 2, // Opcode: CACHE_R6
/* 1602 */    MCD::OPC_FilterValue, 38, 9, 0, // Skip to: 1615
/* 1606 */    MCD::OPC_CheckPredicate, 55, 240, 0, // Skip to: 1850
/* 1610 */    MCD::OPC_Decode, 238, 13, 189, 2, // Opcode: SC_R6
/* 1615 */    MCD::OPC_FilterValue, 39, 9, 0, // Skip to: 1628
/* 1619 */    MCD::OPC_CheckPredicate, 55, 227, 0, // Skip to: 1850
/* 1623 */    MCD::OPC_Decode, 233, 13, 189, 2, // Opcode: SCD_R6
/* 1628 */    MCD::OPC_FilterValue, 53, 15, 0, // Skip to: 1647
/* 1632 */    MCD::OPC_CheckPredicate, 55, 214, 0, // Skip to: 1850
/* 1636 */    MCD::OPC_CheckField, 6, 1, 0, 208, 0, // Skip to: 1850
/* 1642 */    MCD::OPC_Decode, 240, 12, 156, 2, // Opcode: PREF_R6
/* 1647 */    MCD::OPC_FilterValue, 54, 9, 0, // Skip to: 1660
/* 1651 */    MCD::OPC_CheckPredicate, 55, 195, 0, // Skip to: 1850
/* 1655 */    MCD::OPC_Decode, 166, 9, 189, 2, // Opcode: LL_R6
/* 1660 */    MCD::OPC_FilterValue, 55, 186, 0, // Skip to: 1850
/* 1664 */    MCD::OPC_CheckPredicate, 55, 182, 0, // Skip to: 1850
/* 1668 */    MCD::OPC_Decode, 161, 9, 189, 2, // Opcode: LLD_R6
/* 1673 */    MCD::OPC_FilterValue, 50, 9, 0, // Skip to: 1686
/* 1677 */    MCD::OPC_CheckPredicate, 55, 169, 0, // Skip to: 1850
/* 1681 */    MCD::OPC_Decode, 210, 1, 190, 2, // Opcode: BC
/* 1686 */    MCD::OPC_FilterValue, 54, 23, 0, // Skip to: 1713
/* 1690 */    MCD::OPC_CheckPredicate, 55, 10, 0, // Skip to: 1704
/* 1694 */    MCD::OPC_CheckField, 21, 5, 0, 4, 0, // Skip to: 1704
/* 1700 */    MCD::OPC_Decode, 211, 8, 83, // Opcode: JIC
/* 1704 */    MCD::OPC_CheckPredicate, 55, 142, 0, // Skip to: 1850
/* 1708 */    MCD::OPC_Decode, 238, 1, 191, 2, // Opcode: BEQZC
/* 1713 */    MCD::OPC_FilterValue, 58, 9, 0, // Skip to: 1726
/* 1717 */    MCD::OPC_CheckPredicate, 55, 129, 0, // Skip to: 1850
/* 1721 */    MCD::OPC_Decode, 202, 1, 190, 2, // Opcode: BALC
/* 1726 */    MCD::OPC_FilterValue, 59, 93, 0, // Skip to: 1823
/* 1730 */    MCD::OPC_ExtractField, 19, 2,  // Inst{20-19} ...
/* 1733 */    MCD::OPC_FilterValue, 0, 8, 0, // Skip to: 1745
/* 1737 */    MCD::OPC_CheckPredicate, 55, 109, 0, // Skip to: 1850
/* 1741 */    MCD::OPC_Decode, 32, 129, 1, // Opcode: ADDIUPC
/* 1745 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 1758
/* 1749 */    MCD::OPC_CheckPredicate, 55, 97, 0, // Skip to: 1850
/* 1753 */    MCD::OPC_Decode, 205, 9, 129, 1, // Opcode: LWPC
/* 1758 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 1771
/* 1762 */    MCD::OPC_CheckPredicate, 55, 84, 0, // Skip to: 1850
/* 1766 */    MCD::OPC_Decode, 214, 9, 129, 1, // Opcode: LWUPC
/* 1771 */    MCD::OPC_FilterValue, 3, 75, 0, // Skip to: 1850
/* 1775 */    MCD::OPC_ExtractField, 18, 1,  // Inst{18} ...
/* 1778 */    MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 1791
/* 1782 */    MCD::OPC_CheckPredicate, 57, 64, 0, // Skip to: 1850
/* 1786 */    MCD::OPC_Decode, 133, 9, 192, 2, // Opcode: LDPC
/* 1791 */    MCD::OPC_FilterValue, 1, 55, 0, // Skip to: 1850
/* 1795 */    MCD::OPC_ExtractField, 16, 2,  // Inst{17-16} ...
/* 1798 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 1811
/* 1802 */    MCD::OPC_CheckPredicate, 55, 44, 0, // Skip to: 1850
/* 1806 */    MCD::OPC_Decode, 170, 1, 130, 1, // Opcode: AUIPC
/* 1811 */    MCD::OPC_FilterValue, 3, 35, 0, // Skip to: 1850
/* 1815 */    MCD::OPC_CheckPredicate, 55, 31, 0, // Skip to: 1850
/* 1819 */    MCD::OPC_Decode, 109, 130, 1, // Opcode: ALUIPC
/* 1823 */    MCD::OPC_FilterValue, 62, 23, 0, // Skip to: 1850
/* 1827 */    MCD::OPC_CheckPredicate, 55, 10, 0, // Skip to: 1841
/* 1831 */    MCD::OPC_CheckField, 21, 5, 0, 4, 0, // Skip to: 1841
/* 1837 */    MCD::OPC_Decode, 209, 8, 83, // Opcode: JIALC
/* 1841 */    MCD::OPC_CheckPredicate, 55, 5, 0, // Skip to: 1850
/* 1845 */    MCD::OPC_Decode, 224, 2, 191, 2, // Opcode: BNEZC
/* 1850 */    MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableMips32r6_64r6_Ambiguous32[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 6, 24, 0, // Skip to: 31
/* 7 */       MCD::OPC_CheckPredicate, 55, 11, 0, // Skip to: 22
/* 11 */      MCD::OPC_CheckField, 21, 5, 0, 5, 0, // Skip to: 22
/* 17 */      MCD::OPC_Decode, 179, 2, 170, 2, // Opcode: BLEZALC
/* 22 */      MCD::OPC_CheckPredicate, 55, 145, 0, // Skip to: 171
/* 26 */      MCD::OPC_Decode, 248, 1, 170, 2, // Opcode: BGEUC
/* 31 */      MCD::OPC_FilterValue, 7, 24, 0, // Skip to: 59
/* 35 */      MCD::OPC_CheckPredicate, 55, 11, 0, // Skip to: 50
/* 39 */      MCD::OPC_CheckField, 21, 5, 0, 5, 0, // Skip to: 50
/* 45 */      MCD::OPC_Decode, 145, 2, 171, 2, // Opcode: BGTZALC
/* 50 */      MCD::OPC_CheckPredicate, 55, 117, 0, // Skip to: 171
/* 54 */      MCD::OPC_Decode, 190, 2, 171, 2, // Opcode: BLTUC
/* 59 */      MCD::OPC_FilterValue, 8, 24, 0, // Skip to: 87
/* 63 */      MCD::OPC_CheckPredicate, 55, 11, 0, // Skip to: 78
/* 67 */      MCD::OPC_CheckField, 21, 5, 0, 5, 0, // Skip to: 78
/* 73 */      MCD::OPC_Decode, 236, 1, 185, 2, // Opcode: BEQZALC
/* 78 */      MCD::OPC_CheckPredicate, 55, 89, 0, // Skip to: 171
/* 82 */      MCD::OPC_Decode, 234, 2, 172, 2, // Opcode: BOVC
/* 87 */      MCD::OPC_FilterValue, 22, 24, 0, // Skip to: 115
/* 91 */      MCD::OPC_CheckPredicate, 55, 11, 0, // Skip to: 106
/* 95 */      MCD::OPC_CheckField, 21, 5, 0, 5, 0, // Skip to: 106
/* 101 */     MCD::OPC_Decode, 181, 2, 183, 2, // Opcode: BLEZC
/* 106 */     MCD::OPC_CheckPredicate, 55, 61, 0, // Skip to: 171
/* 110 */     MCD::OPC_Decode, 243, 1, 183, 2, // Opcode: BGEC
/* 115 */     MCD::OPC_FilterValue, 23, 24, 0, // Skip to: 143
/* 119 */     MCD::OPC_CheckPredicate, 55, 11, 0, // Skip to: 134
/* 123 */     MCD::OPC_CheckField, 21, 5, 0, 5, 0, // Skip to: 134
/* 129 */     MCD::OPC_Decode, 147, 2, 184, 2, // Opcode: BGTZC
/* 134 */     MCD::OPC_CheckPredicate, 55, 33, 0, // Skip to: 171
/* 138 */     MCD::OPC_Decode, 185, 2, 184, 2, // Opcode: BLTC
/* 143 */     MCD::OPC_FilterValue, 24, 24, 0, // Skip to: 171
/* 147 */     MCD::OPC_CheckPredicate, 55, 11, 0, // Skip to: 162
/* 151 */     MCD::OPC_CheckField, 21, 5, 0, 5, 0, // Skip to: 162
/* 157 */     MCD::OPC_Decode, 222, 2, 185, 2, // Opcode: BNEZALC
/* 162 */     MCD::OPC_CheckPredicate, 55, 5, 0, // Skip to: 171
/* 166 */     MCD::OPC_Decode, 228, 2, 185, 2, // Opcode: BNVC
/* 171 */     MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableMips32r6_64r6_GP6432[] = {
/* 0 */       MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 3 */       MCD::OPC_FilterValue, 53, 14, 0, // Skip to: 21
/* 7 */       MCD::OPC_CheckPredicate, 62, 28, 0, // Skip to: 39
/* 11 */      MCD::OPC_CheckField, 26, 6, 0, 22, 0, // Skip to: 39
/* 17 */      MCD::OPC_Decode, 142, 14, 12, // Opcode: SELEQZ64
/* 21 */      MCD::OPC_FilterValue, 55, 14, 0, // Skip to: 39
/* 25 */      MCD::OPC_CheckPredicate, 62, 10, 0, // Skip to: 39
/* 29 */      MCD::OPC_CheckField, 26, 6, 0, 4, 0, // Skip to: 39
/* 35 */      MCD::OPC_Decode, 149, 14, 12, // Opcode: SELNEZ64
/* 39 */      MCD::OPC_Fail,
  0
};

static const uint8_t DecoderTableMips6432[] = {
/* 0 */       MCD::OPC_ExtractField, 26, 6,  // Inst{31-26} ...
/* 3 */       MCD::OPC_FilterValue, 0, 108, 1, // Skip to: 371
/* 7 */       MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 10 */      MCD::OPC_FilterValue, 20, 15, 0, // Skip to: 29
/* 14 */      MCD::OPC_CheckPredicate, 63, 127, 7, // Skip to: 1937
/* 18 */      MCD::OPC_CheckField, 6, 5, 0, 121, 7, // Skip to: 1937
/* 24 */      MCD::OPC_Decode, 159, 6, 193, 2, // Opcode: DSLLV
/* 29 */      MCD::OPC_FilterValue, 22, 29, 0, // Skip to: 62
/* 33 */      MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 36 */      MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 49
/* 40 */      MCD::OPC_CheckPredicate, 63, 101, 7, // Skip to: 1937
/* 44 */      MCD::OPC_Decode, 165, 6, 193, 2, // Opcode: DSRLV
/* 49 */      MCD::OPC_FilterValue, 1, 92, 7, // Skip to: 1937
/* 53 */      MCD::OPC_CheckPredicate, 64, 88, 7, // Skip to: 1937
/* 57 */      MCD::OPC_Decode, 151, 6, 193, 2, // Opcode: DROTRV
/* 62 */      MCD::OPC_FilterValue, 23, 15, 0, // Skip to: 81
/* 66 */      MCD::OPC_CheckPredicate, 63, 75, 7, // Skip to: 1937
/* 70 */      MCD::OPC_CheckField, 6, 5, 0, 69, 7, // Skip to: 1937
/* 76 */      MCD::OPC_Decode, 162, 6, 193, 2, // Opcode: DSRAV
/* 81 */      MCD::OPC_FilterValue, 28, 15, 0, // Skip to: 100
/* 85 */      MCD::OPC_CheckPredicate, 65, 56, 7, // Skip to: 1937
/* 89 */      MCD::OPC_CheckField, 6, 10, 0, 50, 7, // Skip to: 1937
/* 95 */      MCD::OPC_Decode, 218, 5, 194, 2, // Opcode: DMULT
/* 100 */     MCD::OPC_FilterValue, 29, 15, 0, // Skip to: 119
/* 104 */     MCD::OPC_CheckPredicate, 65, 37, 7, // Skip to: 1937
/* 108 */     MCD::OPC_CheckField, 6, 10, 0, 31, 7, // Skip to: 1937
/* 114 */     MCD::OPC_Decode, 219, 5, 194, 2, // Opcode: DMULTu
/* 119 */     MCD::OPC_FilterValue, 30, 15, 0, // Skip to: 138
/* 123 */     MCD::OPC_CheckPredicate, 65, 18, 7, // Skip to: 1937
/* 127 */     MCD::OPC_CheckField, 6, 10, 0, 12, 7, // Skip to: 1937
/* 133 */     MCD::OPC_Decode, 153, 6, 194, 2, // Opcode: DSDIV
/* 138 */     MCD::OPC_FilterValue, 31, 15, 0, // Skip to: 157
/* 142 */     MCD::OPC_CheckPredicate, 65, 255, 6, // Skip to: 1937
/* 146 */     MCD::OPC_CheckField, 6, 10, 0, 249, 6, // Skip to: 1937
/* 152 */     MCD::OPC_Decode, 168, 6, 194, 2, // Opcode: DUDIV
/* 157 */     MCD::OPC_FilterValue, 44, 14, 0, // Skip to: 175
/* 161 */     MCD::OPC_CheckPredicate, 63, 236, 6, // Skip to: 1937
/* 165 */     MCD::OPC_CheckField, 6, 5, 0, 230, 6, // Skip to: 1937
/* 171 */     MCD::OPC_Decode, 155, 5, 12, // Opcode: DADD
/* 175 */     MCD::OPC_FilterValue, 45, 14, 0, // Skip to: 193
/* 179 */     MCD::OPC_CheckPredicate, 63, 218, 6, // Skip to: 1937
/* 183 */     MCD::OPC_CheckField, 6, 5, 0, 212, 6, // Skip to: 1937
/* 189 */     MCD::OPC_Decode, 158, 5, 12, // Opcode: DADDu
/* 193 */     MCD::OPC_FilterValue, 46, 14, 0, // Skip to: 211
/* 197 */     MCD::OPC_CheckPredicate, 63, 200, 6, // Skip to: 1937
/* 201 */     MCD::OPC_CheckField, 6, 5, 0, 194, 6, // Skip to: 1937
/* 207 */     MCD::OPC_Decode, 166, 6, 12, // Opcode: DSUB
/* 211 */     MCD::OPC_FilterValue, 47, 14, 0, // Skip to: 229
/* 215 */     MCD::OPC_CheckPredicate, 63, 182, 6, // Skip to: 1937
/* 219 */     MCD::OPC_CheckField, 6, 5, 0, 176, 6, // Skip to: 1937
/* 225 */     MCD::OPC_Decode, 167, 6, 12, // Opcode: DSUBu
/* 229 */     MCD::OPC_FilterValue, 56, 15, 0, // Skip to: 248
/* 233 */     MCD::OPC_CheckPredicate, 63, 164, 6, // Skip to: 1937
/* 237 */     MCD::OPC_CheckField, 21, 5, 0, 158, 6, // Skip to: 1937
/* 243 */     MCD::OPC_Decode, 156, 6, 195, 2, // Opcode: DSLL
/* 248 */     MCD::OPC_FilterValue, 58, 29, 0, // Skip to: 281
/* 252 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 255 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 268
/* 259 */     MCD::OPC_CheckPredicate, 63, 138, 6, // Skip to: 1937
/* 263 */     MCD::OPC_Decode, 163, 6, 195, 2, // Opcode: DSRL
/* 268 */     MCD::OPC_FilterValue, 1, 129, 6, // Skip to: 1937
/* 272 */     MCD::OPC_CheckPredicate, 64, 125, 6, // Skip to: 1937
/* 276 */     MCD::OPC_Decode, 149, 6, 195, 2, // Opcode: DROTR
/* 281 */     MCD::OPC_FilterValue, 59, 15, 0, // Skip to: 300
/* 285 */     MCD::OPC_CheckPredicate, 63, 112, 6, // Skip to: 1937
/* 289 */     MCD::OPC_CheckField, 21, 5, 0, 106, 6, // Skip to: 1937
/* 295 */     MCD::OPC_Decode, 160, 6, 195, 2, // Opcode: DSRA
/* 300 */     MCD::OPC_FilterValue, 60, 15, 0, // Skip to: 319
/* 304 */     MCD::OPC_CheckPredicate, 63, 93, 6, // Skip to: 1937
/* 308 */     MCD::OPC_CheckField, 21, 5, 0, 87, 6, // Skip to: 1937
/* 314 */     MCD::OPC_Decode, 157, 6, 195, 2, // Opcode: DSLL32
/* 319 */     MCD::OPC_FilterValue, 62, 29, 0, // Skip to: 352
/* 323 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 326 */     MCD::OPC_FilterValue, 0, 9, 0, // Skip to: 339
/* 330 */     MCD::OPC_CheckPredicate, 63, 67, 6, // Skip to: 1937
/* 334 */     MCD::OPC_Decode, 164, 6, 195, 2, // Opcode: DSRL32
/* 339 */     MCD::OPC_FilterValue, 1, 58, 6, // Skip to: 1937
/* 343 */     MCD::OPC_CheckPredicate, 64, 54, 6, // Skip to: 1937
/* 347 */     MCD::OPC_Decode, 150, 6, 195, 2, // Opcode: DROTR32
/* 352 */     MCD::OPC_FilterValue, 63, 45, 6, // Skip to: 1937
/* 356 */     MCD::OPC_CheckPredicate, 63, 41, 6, // Skip to: 1937
/* 360 */     MCD::OPC_CheckField, 21, 5, 0, 35, 6, // Skip to: 1937
/* 366 */     MCD::OPC_Decode, 161, 6, 195, 2, // Opcode: DSRA32
/* 371 */     MCD::OPC_FilterValue, 16, 41, 0, // Skip to: 416
/* 375 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 378 */     MCD::OPC_FilterValue, 1, 15, 0, // Skip to: 397
/* 382 */     MCD::OPC_CheckPredicate, 66, 15, 6, // Skip to: 1937
/* 386 */     MCD::OPC_CheckField, 3, 8, 0, 9, 6, // Skip to: 1937
/* 392 */     MCD::OPC_Decode, 203, 5, 196, 2, // Opcode: DMFC0
/* 397 */     MCD::OPC_FilterValue, 5, 0, 6, // Skip to: 1937
/* 401 */     MCD::OPC_CheckPredicate, 66, 252, 5, // Skip to: 1937
/* 405 */     MCD::OPC_CheckField, 3, 8, 0, 246, 5, // Skip to: 1937
/* 411 */     MCD::OPC_Decode, 211, 5, 197, 2, // Opcode: DMTC0
/* 416 */     MCD::OPC_FilterValue, 17, 237, 3, // Skip to: 1425
/* 420 */     MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 423 */     MCD::OPC_FilterValue, 0, 54, 0, // Skip to: 481
/* 427 */     MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 430 */     MCD::OPC_FilterValue, 3, 15, 0, // Skip to: 449
/* 434 */     MCD::OPC_CheckPredicate, 67, 219, 5, // Skip to: 1937
/* 438 */     MCD::OPC_CheckField, 6, 5, 0, 213, 5, // Skip to: 1937
/* 444 */     MCD::OPC_Decode, 180, 10, 198, 2, // Opcode: MFHC1_D64
/* 449 */     MCD::OPC_FilterValue, 7, 15, 0, // Skip to: 468
/* 453 */     MCD::OPC_CheckPredicate, 67, 200, 5, // Skip to: 1937
/* 457 */     MCD::OPC_CheckField, 6, 5, 0, 194, 5, // Skip to: 1937
/* 463 */     MCD::OPC_Decode, 183, 11, 199, 2, // Opcode: MTHC1_D64
/* 468 */     MCD::OPC_FilterValue, 17, 185, 5, // Skip to: 1937
/* 472 */     MCD::OPC_CheckPredicate, 68, 181, 5, // Skip to: 1937
/* 476 */     MCD::OPC_Decode, 223, 6, 177, 2, // Opcode: FADD_D64
/* 481 */     MCD::OPC_FilterValue, 1, 15, 0, // Skip to: 500
/* 485 */     MCD::OPC_CheckPredicate, 68, 168, 5, // Skip to: 1937
/* 489 */     MCD::OPC_CheckField, 21, 5, 17, 162, 5, // Skip to: 1937
/* 495 */     MCD::OPC_Decode, 239, 7, 177, 2, // Opcode: FSUB_D64
/* 500 */     MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 519
/* 504 */     MCD::OPC_CheckPredicate, 68, 149, 5, // Skip to: 1937
/* 508 */     MCD::OPC_CheckField, 21, 5, 17, 143, 5, // Skip to: 1937
/* 514 */     MCD::OPC_Decode, 198, 7, 177, 2, // Opcode: FMUL_D64
/* 519 */     MCD::OPC_FilterValue, 3, 15, 0, // Skip to: 538
/* 523 */     MCD::OPC_CheckPredicate, 68, 130, 5, // Skip to: 1937
/* 527 */     MCD::OPC_CheckField, 21, 5, 17, 124, 5, // Skip to: 1937
/* 533 */     MCD::OPC_Decode, 133, 7, 177, 2, // Opcode: FDIV_D64
/* 538 */     MCD::OPC_FilterValue, 4, 16, 0, // Skip to: 558
/* 542 */     MCD::OPC_CheckPredicate, 69, 111, 5, // Skip to: 1937
/* 546 */     MCD::OPC_CheckField, 16, 10, 160, 4, 104, 5, // Skip to: 1937
/* 553 */     MCD::OPC_Decode, 232, 7, 179, 1, // Opcode: FSQRT_D64
/* 558 */     MCD::OPC_FilterValue, 5, 16, 0, // Skip to: 578
/* 562 */     MCD::OPC_CheckPredicate, 68, 91, 5, // Skip to: 1937
/* 566 */     MCD::OPC_CheckField, 16, 10, 160, 4, 84, 5, // Skip to: 1937
/* 573 */     MCD::OPC_Decode, 216, 6, 179, 1, // Opcode: FABS_D64
/* 578 */     MCD::OPC_FilterValue, 6, 16, 0, // Skip to: 598
/* 582 */     MCD::OPC_CheckPredicate, 68, 71, 5, // Skip to: 1937
/* 586 */     MCD::OPC_CheckField, 16, 10, 160, 4, 64, 5, // Skip to: 1937
/* 593 */     MCD::OPC_Decode, 189, 7, 179, 1, // Opcode: FMOV_D64
/* 598 */     MCD::OPC_FilterValue, 7, 16, 0, // Skip to: 618
/* 602 */     MCD::OPC_CheckPredicate, 68, 51, 5, // Skip to: 1937
/* 606 */     MCD::OPC_CheckField, 16, 10, 160, 4, 44, 5, // Skip to: 1937
/* 613 */     MCD::OPC_Decode, 206, 7, 179, 1, // Opcode: FNEG_D64
/* 618 */     MCD::OPC_FilterValue, 8, 31, 0, // Skip to: 653
/* 622 */     MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 625 */     MCD::OPC_FilterValue, 128, 4, 9, 0, // Skip to: 639
/* 630 */     MCD::OPC_CheckPredicate, 70, 23, 5, // Skip to: 1937
/* 634 */     MCD::OPC_Decode, 199, 13, 172, 1, // Opcode: ROUND_L_S
/* 639 */     MCD::OPC_FilterValue, 160, 4, 13, 5, // Skip to: 1937
/* 644 */     MCD::OPC_CheckPredicate, 70, 9, 5, // Skip to: 1937
/* 648 */     MCD::OPC_Decode, 197, 13, 179, 1, // Opcode: ROUND_L_D64
/* 653 */     MCD::OPC_FilterValue, 9, 31, 0, // Skip to: 688
/* 657 */     MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 660 */     MCD::OPC_FilterValue, 128, 4, 9, 0, // Skip to: 674
/* 665 */     MCD::OPC_CheckPredicate, 70, 244, 4, // Skip to: 1937
/* 669 */     MCD::OPC_Decode, 253, 16, 172, 1, // Opcode: TRUNC_L_S
/* 674 */     MCD::OPC_FilterValue, 160, 4, 234, 4, // Skip to: 1937
/* 679 */     MCD::OPC_CheckPredicate, 70, 230, 4, // Skip to: 1937
/* 683 */     MCD::OPC_Decode, 251, 16, 179, 1, // Opcode: TRUNC_L_D64
/* 688 */     MCD::OPC_FilterValue, 10, 31, 0, // Skip to: 723
/* 692 */     MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 695 */     MCD::OPC_FilterValue, 128, 4, 9, 0, // Skip to: 709
/* 700 */     MCD::OPC_CheckPredicate, 70, 209, 4, // Skip to: 1937
/* 704 */     MCD::OPC_Decode, 172, 3, 172, 1, // Opcode: CEIL_L_S
/* 709 */     MCD::OPC_FilterValue, 160, 4, 199, 4, // Skip to: 1937
/* 714 */     MCD::OPC_CheckPredicate, 70, 195, 4, // Skip to: 1937
/* 718 */     MCD::OPC_Decode, 170, 3, 179, 1, // Opcode: CEIL_L_D64
/* 723 */     MCD::OPC_FilterValue, 11, 31, 0, // Skip to: 758
/* 727 */     MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 730 */     MCD::OPC_FilterValue, 128, 4, 9, 0, // Skip to: 744
/* 735 */     MCD::OPC_CheckPredicate, 70, 174, 4, // Skip to: 1937
/* 739 */     MCD::OPC_Decode, 168, 7, 172, 1, // Opcode: FLOOR_L_S
/* 744 */     MCD::OPC_FilterValue, 160, 4, 164, 4, // Skip to: 1937
/* 749 */     MCD::OPC_CheckPredicate, 70, 160, 4, // Skip to: 1937
/* 753 */     MCD::OPC_Decode, 166, 7, 179, 1, // Opcode: FLOOR_L_D64
/* 758 */     MCD::OPC_FilterValue, 12, 16, 0, // Skip to: 778
/* 762 */     MCD::OPC_CheckPredicate, 69, 147, 4, // Skip to: 1937
/* 766 */     MCD::OPC_CheckField, 16, 10, 160, 4, 140, 4, // Skip to: 1937
/* 773 */     MCD::OPC_Decode, 202, 13, 200, 2, // Opcode: ROUND_W_D64
/* 778 */     MCD::OPC_FilterValue, 13, 16, 0, // Skip to: 798
/* 782 */     MCD::OPC_CheckPredicate, 69, 127, 4, // Skip to: 1937
/* 786 */     MCD::OPC_CheckField, 16, 10, 160, 4, 120, 4, // Skip to: 1937
/* 793 */     MCD::OPC_Decode, 128, 17, 200, 2, // Opcode: TRUNC_W_D64
/* 798 */     MCD::OPC_FilterValue, 14, 16, 0, // Skip to: 818
/* 802 */     MCD::OPC_CheckPredicate, 69, 107, 4, // Skip to: 1937
/* 806 */     MCD::OPC_CheckField, 16, 10, 160, 4, 100, 4, // Skip to: 1937
/* 813 */     MCD::OPC_Decode, 175, 3, 200, 2, // Opcode: CEIL_W_D64
/* 818 */     MCD::OPC_FilterValue, 15, 16, 0, // Skip to: 838
/* 822 */     MCD::OPC_CheckPredicate, 69, 87, 4, // Skip to: 1937
/* 826 */     MCD::OPC_CheckField, 16, 10, 160, 4, 80, 4, // Skip to: 1937
/* 833 */     MCD::OPC_Decode, 171, 7, 200, 2, // Opcode: FLOOR_W_D64
/* 838 */     MCD::OPC_FilterValue, 17, 41, 0, // Skip to: 883
/* 842 */     MCD::OPC_ExtractField, 16, 2,  // Inst{17-16} ...
/* 845 */     MCD::OPC_FilterValue, 0, 15, 0, // Skip to: 864
/* 849 */     MCD::OPC_CheckPredicate, 71, 60, 4, // Skip to: 1937
/* 853 */     MCD::OPC_CheckField, 21, 5, 17, 54, 4, // Skip to: 1937
/* 859 */     MCD::OPC_Decode, 243, 10, 201, 2, // Opcode: MOVF_D64
/* 864 */     MCD::OPC_FilterValue, 1, 45, 4, // Skip to: 1937
/* 868 */     MCD::OPC_CheckPredicate, 71, 41, 4, // Skip to: 1937
/* 872 */     MCD::OPC_CheckField, 21, 5, 17, 35, 4, // Skip to: 1937
/* 878 */     MCD::OPC_Decode, 135, 11, 201, 2, // Opcode: MOVT_D64
/* 883 */     MCD::OPC_FilterValue, 18, 15, 0, // Skip to: 902
/* 887 */     MCD::OPC_CheckPredicate, 71, 22, 4, // Skip to: 1937
/* 891 */     MCD::OPC_CheckField, 21, 5, 17, 16, 4, // Skip to: 1937
/* 897 */     MCD::OPC_Decode, 147, 11, 202, 2, // Opcode: MOVZ_I_D64
/* 902 */     MCD::OPC_FilterValue, 19, 15, 0, // Skip to: 921
/* 906 */     MCD::OPC_CheckPredicate, 71, 3, 4, // Skip to: 1937
/* 910 */     MCD::OPC_CheckField, 21, 5, 17, 253, 3, // Skip to: 1937
/* 916 */     MCD::OPC_Decode, 255, 10, 202, 2, // Opcode: MOVN_I_D64
/* 921 */     MCD::OPC_FilterValue, 32, 31, 0, // Skip to: 956
/* 925 */     MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 928 */     MCD::OPC_FilterValue, 160, 4, 9, 0, // Skip to: 942
/* 933 */     MCD::OPC_CheckPredicate, 68, 232, 3, // Skip to: 1937
/* 937 */     MCD::OPC_Decode, 217, 4, 200, 2, // Opcode: CVT_S_D64
/* 942 */     MCD::OPC_FilterValue, 160, 5, 222, 3, // Skip to: 1937
/* 947 */     MCD::OPC_CheckPredicate, 70, 218, 3, // Skip to: 1937
/* 951 */     MCD::OPC_Decode, 219, 4, 200, 2, // Opcode: CVT_S_L
/* 956 */     MCD::OPC_FilterValue, 33, 45, 0, // Skip to: 1005
/* 960 */     MCD::OPC_ExtractField, 16, 10,  // Inst{25-16} ...
/* 963 */     MCD::OPC_FilterValue, 128, 4, 9, 0, // Skip to: 977
/* 968 */     MCD::OPC_CheckPredicate, 68, 197, 3, // Skip to: 1937
/* 972 */     MCD::OPC_Decode, 203, 4, 172, 1, // Opcode: CVT_D64_S
/* 977 */     MCD::OPC_FilterValue, 128, 5, 9, 0, // Skip to: 991
/* 982 */     MCD::OPC_CheckPredicate, 68, 183, 3, // Skip to: 1937
/* 986 */     MCD::OPC_Decode, 204, 4, 172, 1, // Opcode: CVT_D64_W
/* 991 */     MCD::OPC_FilterValue, 160, 5, 173, 3, // Skip to: 1937
/* 996 */     MCD::OPC_CheckPredicate, 68, 169, 3, // Skip to: 1937
/* 1000 */    MCD::OPC_Decode, 202, 4, 179, 1, // Opcode: CVT_D64_L
/* 1005 */    MCD::OPC_FilterValue, 36, 16, 0, // Skip to: 1025
/* 1009 */    MCD::OPC_CheckPredicate, 68, 156, 3, // Skip to: 1937
/* 1013 */    MCD::OPC_CheckField, 16, 10, 160, 4, 149, 3, // Skip to: 1937
/* 1020 */    MCD::OPC_Decode, 225, 4, 200, 2, // Opcode: CVT_W_D64
/* 1025 */    MCD::OPC_FilterValue, 48, 21, 0, // Skip to: 1050
/* 1029 */    MCD::OPC_CheckPredicate, 72, 136, 3, // Skip to: 1937
/* 1033 */    MCD::OPC_CheckField, 21, 5, 17, 130, 3, // Skip to: 1937
/* 1039 */    MCD::OPC_CheckField, 6, 5, 0, 124, 3, // Skip to: 1937
/* 1045 */    MCD::OPC_Decode, 235, 4, 203, 2, // Opcode: C_F_D64
/* 1050 */    MCD::OPC_FilterValue, 49, 21, 0, // Skip to: 1075
/* 1054 */    MCD::OPC_CheckPredicate, 72, 111, 3, // Skip to: 1937
/* 1058 */    MCD::OPC_CheckField, 21, 5, 17, 105, 3, // Skip to: 1937
/* 1064 */    MCD::OPC_CheckField, 6, 5, 0, 99, 3, // Skip to: 1937
/* 1070 */    MCD::OPC_Decode, 149, 5, 203, 2, // Opcode: C_UN_D64
/* 1075 */    MCD::OPC_FilterValue, 50, 21, 0, // Skip to: 1100
/* 1079 */    MCD::OPC_CheckPredicate, 72, 86, 3, // Skip to: 1937
/* 1083 */    MCD::OPC_CheckField, 21, 5, 17, 80, 3, // Skip to: 1937
/* 1089 */    MCD::OPC_CheckField, 6, 5, 0, 74, 3, // Skip to: 1937
/* 1095 */    MCD::OPC_Decode, 232, 4, 203, 2, // Opcode: C_EQ_D64
/* 1100 */    MCD::OPC_FilterValue, 51, 21, 0, // Skip to: 1125
/* 1104 */    MCD::OPC_CheckPredicate, 72, 61, 3, // Skip to: 1937
/* 1108 */    MCD::OPC_CheckField, 21, 5, 17, 55, 3, // Skip to: 1937
/* 1114 */    MCD::OPC_CheckField, 6, 5, 0, 49, 3, // Skip to: 1937
/* 1120 */    MCD::OPC_Decode, 140, 5, 203, 2, // Opcode: C_UEQ_D64
/* 1125 */    MCD::OPC_FilterValue, 52, 21, 0, // Skip to: 1150
/* 1129 */    MCD::OPC_CheckPredicate, 72, 36, 3, // Skip to: 1937
/* 1133 */    MCD::OPC_CheckField, 21, 5, 17, 30, 3, // Skip to: 1937
/* 1139 */    MCD::OPC_CheckField, 6, 5, 0, 24, 3, // Skip to: 1937
/* 1145 */    MCD::OPC_Decode, 131, 5, 203, 2, // Opcode: C_OLT_D64
/* 1150 */    MCD::OPC_FilterValue, 53, 21, 0, // Skip to: 1175
/* 1154 */    MCD::OPC_CheckPredicate, 72, 11, 3, // Skip to: 1937
/* 1158 */    MCD::OPC_CheckField, 21, 5, 17, 5, 3, // Skip to: 1937
/* 1164 */    MCD::OPC_CheckField, 6, 5, 0, 255, 2, // Skip to: 1937
/* 1170 */    MCD::OPC_Decode, 146, 5, 203, 2, // Opcode: C_ULT_D64
/* 1175 */    MCD::OPC_FilterValue, 54, 21, 0, // Skip to: 1200
/* 1179 */    MCD::OPC_CheckPredicate, 72, 242, 2, // Skip to: 1937
/* 1183 */    MCD::OPC_CheckField, 21, 5, 17, 236, 2, // Skip to: 1937
/* 1189 */    MCD::OPC_CheckField, 6, 5, 0, 230, 2, // Skip to: 1937
/* 1195 */    MCD::OPC_Decode, 128, 5, 203, 2, // Opcode: C_OLE_D64
/* 1200 */    MCD::OPC_FilterValue, 55, 21, 0, // Skip to: 1225
/* 1204 */    MCD::OPC_CheckPredicate, 72, 217, 2, // Skip to: 1937
/* 1208 */    MCD::OPC_CheckField, 21, 5, 17, 211, 2, // Skip to: 1937
/* 1214 */    MCD::OPC_CheckField, 6, 5, 0, 205, 2, // Skip to: 1937
/* 1220 */    MCD::OPC_Decode, 143, 5, 203, 2, // Opcode: C_ULE_D64
/* 1225 */    MCD::OPC_FilterValue, 56, 21, 0, // Skip to: 1250
/* 1229 */    MCD::OPC_CheckPredicate, 72, 192, 2, // Skip to: 1937
/* 1233 */    MCD::OPC_CheckField, 21, 5, 17, 186, 2, // Skip to: 1937
/* 1239 */    MCD::OPC_CheckField, 6, 5, 0, 180, 2, // Skip to: 1937
/* 1245 */    MCD::OPC_Decode, 137, 5, 203, 2, // Opcode: C_SF_D64
/* 1250 */    MCD::OPC_FilterValue, 57, 21, 0, // Skip to: 1275
/* 1254 */    MCD::OPC_CheckPredicate, 72, 167, 2, // Skip to: 1937
/* 1258 */    MCD::OPC_CheckField, 21, 5, 17, 161, 2, // Skip to: 1937
/* 1264 */    MCD::OPC_CheckField, 6, 5, 0, 155, 2, // Skip to: 1937
/* 1270 */    MCD::OPC_Decode, 247, 4, 203, 2, // Opcode: C_NGLE_D64
/* 1275 */    MCD::OPC_FilterValue, 58, 21, 0, // Skip to: 1300
/* 1279 */    MCD::OPC_CheckPredicate, 72, 142, 2, // Skip to: 1937
/* 1283 */    MCD::OPC_CheckField, 21, 5, 17, 136, 2, // Skip to: 1937
/* 1289 */    MCD::OPC_CheckField, 6, 5, 0, 130, 2, // Skip to: 1937
/* 1295 */    MCD::OPC_Decode, 134, 5, 203, 2, // Opcode: C_SEQ_D64
/* 1300 */    MCD::OPC_FilterValue, 59, 21, 0, // Skip to: 1325
/* 1304 */    MCD::OPC_CheckPredicate, 72, 117, 2, // Skip to: 1937
/* 1308 */    MCD::OPC_CheckField, 21, 5, 17, 111, 2, // Skip to: 1937
/* 1314 */    MCD::OPC_CheckField, 6, 5, 0, 105, 2, // Skip to: 1937
/* 1320 */    MCD::OPC_Decode, 250, 4, 203, 2, // Opcode: C_NGL_D64
/* 1325 */    MCD::OPC_FilterValue, 60, 21, 0, // Skip to: 1350
/* 1329 */    MCD::OPC_CheckPredicate, 72, 92, 2, // Skip to: 1937
/* 1333 */    MCD::OPC_CheckField, 21, 5, 17, 86, 2, // Skip to: 1937
/* 1339 */    MCD::OPC_CheckField, 6, 5, 0, 80, 2, // Skip to: 1937
/* 1345 */    MCD::OPC_Decode, 241, 4, 203, 2, // Opcode: C_LT_D64
/* 1350 */    MCD::OPC_FilterValue, 61, 21, 0, // Skip to: 1375
/* 1354 */    MCD::OPC_CheckPredicate, 72, 67, 2, // Skip to: 1937
/* 1358 */    MCD::OPC_CheckField, 21, 5, 17, 61, 2, // Skip to: 1937
/* 1364 */    MCD::OPC_CheckField, 6, 5, 0, 55, 2, // Skip to: 1937
/* 1370 */    MCD::OPC_Decode, 244, 4, 203, 2, // Opcode: C_NGE_D64
/* 1375 */    MCD::OPC_FilterValue, 62, 21, 0, // Skip to: 1400
/* 1379 */    MCD::OPC_CheckPredicate, 72, 42, 2, // Skip to: 1937
/* 1383 */    MCD::OPC_CheckField, 21, 5, 17, 36, 2, // Skip to: 1937
/* 1389 */    MCD::OPC_CheckField, 6, 5, 0, 30, 2, // Skip to: 1937
/* 1395 */    MCD::OPC_Decode, 238, 4, 203, 2, // Opcode: C_LE_D64
/* 1400 */    MCD::OPC_FilterValue, 63, 21, 2, // Skip to: 1937
/* 1404 */    MCD::OPC_CheckPredicate, 72, 17, 2, // Skip to: 1937
/* 1408 */    MCD::OPC_CheckField, 21, 5, 17, 11, 2, // Skip to: 1937
/* 1414 */    MCD::OPC_CheckField, 6, 5, 0, 5, 2, // Skip to: 1937
/* 1420 */    MCD::OPC_Decode, 253, 4, 203, 2, // Opcode: C_NGT_D64
/* 1425 */    MCD::OPC_FilterValue, 18, 41, 0, // Skip to: 1470
/* 1429 */    MCD::OPC_ExtractField, 21, 5,  // Inst{25-21} ...
/* 1432 */    MCD::OPC_FilterValue, 1, 15, 0, // Skip to: 1451
/* 1436 */    MCD::OPC_CheckPredicate, 66, 241, 1, // Skip to: 1937
/* 1440 */    MCD::OPC_CheckField, 3, 8, 0, 235, 1, // Skip to: 1937
/* 1446 */    MCD::OPC_Decode, 205, 5, 204, 2, // Opcode: DMFC2
/* 1451 */    MCD::OPC_FilterValue, 5, 226, 1, // Skip to: 1937
/* 1455 */    MCD::OPC_CheckPredicate, 66, 222, 1, // Skip to: 1937
/* 1459 */    MCD::OPC_CheckField, 3, 8, 0, 216, 1, // Skip to: 1937
/* 1465 */    MCD::OPC_Decode, 213, 5, 205, 2, // Opcode: DMTC2
/* 1470 */    MCD::OPC_FilterValue, 19, 131, 0, // Skip to: 1605
/* 1474 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 1477 */    MCD::OPC_FilterValue, 1, 15, 0, // Skip to: 1496
/* 1481 */    MCD::OPC_CheckPredicate, 73, 196, 1, // Skip to: 1937
/* 1485 */    MCD::OPC_CheckField, 11, 5, 0, 190, 1, // Skip to: 1937
/* 1491 */    MCD::OPC_Decode, 136, 9, 206, 2, // Opcode: LDXC164
/* 1496 */    MCD::OPC_FilterValue, 5, 15, 0, // Skip to: 1515
/* 1500 */    MCD::OPC_CheckPredicate, 74, 177, 1, // Skip to: 1937
/* 1504 */    MCD::OPC_CheckField, 11, 5, 0, 171, 1, // Skip to: 1937
/* 1510 */    MCD::OPC_Decode, 179, 9, 206, 2, // Opcode: LUXC164
/* 1515 */    MCD::OPC_FilterValue, 9, 15, 0, // Skip to: 1534
/* 1519 */    MCD::OPC_CheckPredicate, 73, 158, 1, // Skip to: 1937
/* 1523 */    MCD::OPC_CheckField, 6, 5, 0, 152, 1, // Skip to: 1937
/* 1529 */    MCD::OPC_Decode, 129, 14, 207, 2, // Opcode: SDXC164
/* 1534 */    MCD::OPC_FilterValue, 13, 15, 0, // Skip to: 1553
/* 1538 */    MCD::OPC_CheckPredicate, 74, 139, 1, // Skip to: 1937
/* 1542 */    MCD::OPC_CheckField, 6, 5, 0, 133, 1, // Skip to: 1937
/* 1548 */    MCD::OPC_Decode, 255, 15, 207, 2, // Opcode: SUXC164
/* 1553 */    MCD::OPC_FilterValue, 33, 9, 0, // Skip to: 1566
/* 1557 */    MCD::OPC_CheckPredicate, 73, 120, 1, // Skip to: 1937
/* 1561 */    MCD::OPC_Decode, 131, 10, 208, 2, // Opcode: MADD_D64
/* 1566 */    MCD::OPC_FilterValue, 41, 9, 0, // Skip to: 1579
/* 1570 */    MCD::OPC_CheckPredicate, 73, 107, 1, // Skip to: 1937
/* 1574 */    MCD::OPC_Decode, 170, 11, 208, 2, // Opcode: MSUB_D64
/* 1579 */    MCD::OPC_FilterValue, 49, 9, 0, // Skip to: 1592
/* 1583 */    MCD::OPC_CheckPredicate, 73, 94, 1, // Skip to: 1937
/* 1587 */    MCD::OPC_Decode, 141, 12, 208, 2, // Opcode: NMADD_D64
/* 1592 */    MCD::OPC_FilterValue, 57, 85, 1, // Skip to: 1937
/* 1596 */    MCD::OPC_CheckPredicate, 73, 81, 1, // Skip to: 1937
/* 1600 */    MCD::OPC_Decode, 146, 12, 208, 2, // Opcode: NMSUB_D64
/* 1605 */    MCD::OPC_FilterValue, 24, 9, 0, // Skip to: 1618
/* 1609 */    MCD::OPC_CheckPredicate, 65, 68, 1, // Skip to: 1937
/* 1613 */    MCD::OPC_Decode, 156, 5, 209, 2, // Opcode: DADDi
/* 1618 */    MCD::OPC_FilterValue, 25, 9, 0, // Skip to: 1631
/* 1622 */    MCD::OPC_CheckPredicate, 63, 55, 1, // Skip to: 1937
/* 1626 */    MCD::OPC_Decode, 157, 5, 209, 2, // Opcode: DADDiu
/* 1631 */    MCD::OPC_FilterValue, 26, 9, 0, // Skip to: 1644
/* 1635 */    MCD::OPC_CheckPredicate, 65, 42, 1, // Skip to: 1937
/* 1639 */    MCD::OPC_Decode, 132, 9, 165, 2, // Opcode: LDL
/* 1644 */    MCD::OPC_FilterValue, 27, 9, 0, // Skip to: 1657
/* 1648 */    MCD::OPC_CheckPredicate, 65, 29, 1, // Skip to: 1937
/* 1652 */    MCD::OPC_Decode, 134, 9, 165, 2, // Opcode: LDR
/* 1657 */    MCD::OPC_FilterValue, 28, 29, 0, // Skip to: 1690
/* 1661 */    MCD::OPC_ExtractField, 0, 11,  // Inst{10-0} ...
/* 1664 */    MCD::OPC_FilterValue, 36, 9, 0, // Skip to: 1677
/* 1668 */    MCD::OPC_CheckPredicate, 75, 9, 1, // Skip to: 1937
/* 1672 */    MCD::OPC_Decode, 170, 5, 210, 2, // Opcode: DCLZ
/* 1677 */    MCD::OPC_FilterValue, 37, 0, 1, // Skip to: 1937
/* 1681 */    MCD::OPC_CheckPredicate, 75, 252, 0, // Skip to: 1937
/* 1685 */    MCD::OPC_Decode, 168, 5, 210, 2, // Opcode: DCLO
/* 1690 */    MCD::OPC_FilterValue, 31, 126, 0, // Skip to: 1820
/* 1694 */    MCD::OPC_ExtractField, 0, 6,  // Inst{5-0} ...
/* 1697 */    MCD::OPC_FilterValue, 1, 9, 0, // Skip to: 1710
/* 1701 */    MCD::OPC_CheckPredicate, 30, 232, 0, // Skip to: 1937
/* 1705 */    MCD::OPC_Decode, 179, 5, 211, 2, // Opcode: DEXTM
/* 1710 */    MCD::OPC_FilterValue, 2, 9, 0, // Skip to: 1723
/* 1714 */    MCD::OPC_CheckPredicate, 30, 219, 0, // Skip to: 1937
/* 1718 */    MCD::OPC_Decode, 181, 5, 211, 2, // Opcode: DEXTU
/* 1723 */    MCD::OPC_FilterValue, 3, 9, 0, // Skip to: 1736
/* 1727 */    MCD::OPC_CheckPredicate, 30, 206, 0, // Skip to: 1937
/* 1731 */    MCD::OPC_Decode, 178, 5, 211, 2, // Opcode: DEXT
/* 1736 */    MCD::OPC_FilterValue, 5, 9, 0, // Skip to: 1749
/* 1740 */    MCD::OPC_CheckPredicate, 16, 193, 0, // Skip to: 1937
/* 1744 */    MCD::OPC_Decode, 186, 5, 212, 2, // Opcode: DINSM
/* 1749 */    MCD::OPC_FilterValue, 6, 9, 0, // Skip to: 1762
/* 1753 */    MCD::OPC_CheckPredicate, 16, 180, 0, // Skip to: 1937
/* 1757 */    MCD::OPC_Decode, 187, 5, 212, 2, // Opcode: DINSU
/* 1762 */    MCD::OPC_FilterValue, 7, 9, 0, // Skip to: 1775
/* 1766 */    MCD::OPC_CheckPredicate, 16, 167, 0, // Skip to: 1937
/* 1770 */    MCD::OPC_Decode, 185, 5, 212, 2, // Opcode: DINS
/* 1775 */    MCD::OPC_FilterValue, 36, 158, 0, // Skip to: 1937
/* 1779 */    MCD::OPC_ExtractField, 6, 5,  // Inst{10-6} ...
/* 1782 */    MCD::OPC_FilterValue, 2, 15, 0, // Skip to: 1801
/* 1786 */    MCD::OPC_CheckPredicate, 64, 147, 0, // Skip to: 1937
/* 1790 */    MCD::OPC_CheckField, 21, 5, 0, 141, 0, // Skip to: 1937
/* 1796 */    MCD::OPC_Decode, 152, 6, 187, 2, // Opcode: DSBH
/* 1801 */    MCD::OPC_FilterValue, 5, 132, 0, // Skip to: 1937
/* 1805 */    MCD::OPC_CheckPredicate, 64, 128, 0, // Skip to: 1937
/* 1809 */    MCD::OPC_CheckField, 21, 5, 0, 122, 0, // Skip to: 1937
/* 1815 */    MCD::OPC_Decode, 155, 6, 187, 2, // Opcode: DSHD
/* 1820 */    MCD::OPC_FilterValue, 39, 9, 0, // Skip to: 1833
/* 1824 */    MCD::OPC_CheckPredicate, 63, 109, 0, // Skip to: 1937
/* 1828 */    MCD::OPC_Decode, 223, 9, 165, 2, // Opcode: LWu
/* 1833 */    MCD::OPC_FilterValue, 44, 9, 0, // Skip to: 1846
/* 1837 */    MCD::OPC_CheckPredicate, 65, 96, 0, // Skip to: 1937
/* 1841 */    MCD::OPC_Decode, 254, 13, 165, 2, // Opcode: SDL
/* 1846 */    MCD::OPC_FilterValue, 45, 9, 0, // Skip to: 1859
/* 1850 */    MCD::OPC_CheckPredicate, 65, 83, 0, // Skip to: 1937
/* 1854 */    MCD::OPC_Decode, 255, 13, 165, 2, // Opcode: SDR
/* 1859 */    MCD::OPC_FilterValue, 52, 9, 0, // Skip to: 1872
/* 1863 */    MCD::OPC_CheckPredicate, 65, 70, 0, // Skip to: 1937
/* 1867 */    MCD::OPC_Decode, 160, 9, 165, 2, // Opcode: LLD
/* 1872 */    MCD::OPC_FilterValue, 53, 9, 0, // Skip to: 1885
/* 1876 */    MCD::OPC_CheckPredicate, 69, 57, 0, // Skip to: 1937
/* 1880 */    MCD::OPC_Decode, 251, 8, 167, 2, // Opcode: LDC164
/* 1885 */    MCD::OPC_FilterValue, 55, 9, 0, // Skip to: 1898
/* 1889 */    MCD::OPC_CheckPredicate, 63, 44, 0, // Skip to: 1937
/* 1893 */    MCD::OPC_Decode, 249, 8, 165, 2, // Opcode: LD
/* 1898 */    MCD::OPC_FilterValue, 60, 9, 0, // Skip to: 1911
/* 1902 */    MCD::OPC_CheckPredicate, 65, 31, 0, // Skip to: 1937
/* 1906 */    MCD::OPC_Decode, 232, 13, 165, 2, // Opcode: SCD
/* 1911 */    MCD::OPC_FilterValue, 61, 9, 0, // Skip to: 1924
/* 1915 */    MCD::OPC_CheckPredicate, 69, 18, 0, // Skip to: 1937
/* 1919 */    MCD::OPC_Decode, 247, 13, 167, 2, // Opcode: SDC164
/* 1924 */    MCD::OPC_FilterValue, 63, 9, 0, // Skip to: 1937
/* 1928 */    MCD::OPC_CheckPredicate, 63, 5, 0, // Skip to: 1937
/* 1932 */    MCD::OPC_Decode, 239, 13, 165, 2, // Opcode: SD
/* 1937 */    MCD::OPC_Fail,
  0
};

static bool checkDecoderPredicate(unsigned Idx, const FeatureBitset& Bits) {
  switch (Idx) {
  default: llvm_unreachable("Invalid index!");
  case 0:
    return (Bits[Mips::FeatureMips16]);
  case 1:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureMicroMips]);
  case 2:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips2] && !Bits[Mips::FeatureMicroMips]);
  case 3:
    return (Bits[Mips::FeatureCnMips]);
  case 4:
    return (Bits[Mips::FeatureMicroMips] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6]);
  case 5:
    return (Bits[Mips::FeatureMicroMips]);
  case 6:
    return (Bits[Mips::FeatureMicroMips] && !Bits[Mips::FeatureMips32r6]);
  case 7:
    return (Bits[Mips::FeatureDSP] && Bits[Mips::FeatureMicroMips]);
  case 8:
    return (Bits[Mips::FeatureDSPR2] && Bits[Mips::FeatureMicroMips]);
  case 9:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMicroMips] && !Bits[Mips::FeatureMips32r6]);
  case 10:
    return (Bits[Mips::FeatureMicroMips] && Bits[Mips::FeatureMips32r6]);
  case 11:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMicroMips] && Bits[Mips::FeatureMips32r6]);
  case 12:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMicroMips] && Bits[Mips::FeatureMips64r6]);
  case 13:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMicroMips] && Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureSoftFloat]);
  case 14:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMicroMips] && Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureSoftFloat]);
  case 15:
    return (!Bits[Mips::FeatureMips16]);
  case 16:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips32r2]);
  case 17:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips4_32] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 18:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMSA]);
  case 19:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips32] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6]);
  case 20:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips32]);
  case 21:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips4_32] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6]);
  case 22:
    return (!Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureMicroMips]);
  case 23:
    return (Bits[Mips::FeatureDSP]);
  case 24:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6]);
  case 25:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMSA] && Bits[Mips::FeatureMips64]);
  case 26:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6]);
  case 27:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureEVA] && Bits[Mips::FeatureMips32r2]);
  case 28:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips3_32] && !Bits[Mips::FeatureMicroMips]);
  case 29:
    return (!Bits[Mips::FeatureMicroMips]);
  case 30:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips32r2] && !Bits[Mips::FeatureMicroMips]);
  case 31:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips32r5] && !Bits[Mips::FeatureMicroMips]);
  case 32:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureSoftFloat]);
  case 33:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips3] && !Bits[Mips::FeatureSoftFloat]);
  case 34:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips32r2] && !Bits[Mips::FeatureSoftFloat]);
  case 35:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 36:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 37:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips2] && !Bits[Mips::FeatureSoftFloat]);
  case 38:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureFP64Bit] && !Bits[Mips::FeatureSoftFloat]);
  case 39:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips3_32r2] && !Bits[Mips::FeatureSoftFloat] && !Bits[Mips::FeatureMicroMips]);
  case 40:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips2] && !Bits[Mips::FeatureSoftFloat]);
  case 41:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips4_32] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 42:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureFP64Bit] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 43:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips4_32r2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 44:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips4_32r2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat] && !Bits[Mips::FeatureMicroMips]);
  case 45:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips5_32r2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 46:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips4_32r2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 47:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureSoftFloat] && Bits[Mips::FeatureMicroMips]);
  case 48:
    return (Bits[Mips::FeatureDSPR2]);
  case 49:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && Bits[Mips::FeatureEVA] && Bits[Mips::FeatureMips32r2] && !Bits[Mips::FeatureMicroMips]);
  case 50:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureEVA] && Bits[Mips::FeatureMips32r2] && !Bits[Mips::FeatureMicroMips]);
  case 51:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips3_32] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6]);
  case 52:
    return (Bits[Mips::FeatureMips2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureMicroMips]);
  case 53:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureMicroMips]);
  case 54:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureMicroMips]);
  case 55:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips32r6]);
  case 56:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMicroMips]);
  case 57:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips64r6]);
  case 58:
    return (!Bits[Mips::FeatureMips16] && !Bits[Mips::FeatureGP64Bit] && Bits[Mips::FeatureMips32r6]);
  case 59:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureMicroMips]);
  case 60:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureSoftFloat]);
  case 61:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureSoftFloat] && !Bits[Mips::FeatureMicroMips]);
  case 62:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureGP64Bit] && Bits[Mips::FeatureMips32r6]);
  case 63:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips3]);
  case 64:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips64r2]);
  case 65:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips3] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6]);
  case 66:
    return (Bits[Mips::FeatureMips64]);
  case 67:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips32r2] && !Bits[Mips::FeatureSoftFloat]);
  case 68:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureFP64Bit] && !Bits[Mips::FeatureSoftFloat]);
  case 69:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips2] && !Bits[Mips::FeatureSoftFloat]);
  case 70:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureFP64Bit] && !Bits[Mips::FeatureSoftFloat] && !Bits[Mips::FeatureMicroMips]);
  case 71:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips4_32] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 72:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureFP64Bit] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 73:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips4_32r2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 74:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureFP64Bit] && Bits[Mips::FeatureMips5_32r2] && !Bits[Mips::FeatureMips32r6] && !Bits[Mips::FeatureMips64r6] && !Bits[Mips::FeatureSoftFloat]);
  case 75:
    return (!Bits[Mips::FeatureMips16] && Bits[Mips::FeatureMips64] && !Bits[Mips::FeatureMips64r6]);
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
    return S;
  case 1:
    tmp = fieldFromInstruction(insn, 8, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 2:
    tmp = fieldFromInstruction(insn, 8, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 8, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 3:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 3, 2) << 3;
    tmp |= fieldFromInstruction(insn, 5, 3) << 0;
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 4:
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 5:
    tmp = fieldFromInstruction(insn, 2, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 8, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 5, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 6:
    tmp = fieldFromInstruction(insn, 8, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 5, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 7:
    tmp = fieldFromInstruction(insn, 8, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 8, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 5, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 8:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 0, 5) << 0;
    tmp |= fieldFromInstruction(insn, 16, 5) << 11;
    tmp |= fieldFromInstruction(insn, 21, 6) << 5;
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 9:
    tmp = fieldFromInstruction(insn, 5, 3);
    if (DecodeCPU16RegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 10:
    if (DecodeFMem3(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 11:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 12:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 13:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 14:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 15:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 16:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 17:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 18:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 19:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 1, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 4, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 20:
    if (DecodeMemMMImm4(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 21:
    tmp = fieldFromInstruction(insn, 5, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 22:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 4, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 1, 3);
    if (DecodePOOL16BEncodedField(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 23:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 4, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 4);
    if (DecodeANDI16Imm(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 24:
    tmp = fieldFromInstruction(insn, 3, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 25:
    tmp = fieldFromInstruction(insn, 3, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 3, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 26:
    if (DecodeMemMMReglistImm4Lsl2(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 27:
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 28:
    tmp = fieldFromInstruction(insn, 0, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 29:
    tmp = fieldFromInstruction(insn, 0, 5);
    if (DecodeUImm5lsl2(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 30:
    if (DecodeMemMMSPImm5Lsl2(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 31:
    tmp = fieldFromInstruction(insn, 5, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 5, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 1, 4);
    if (DecodeSimm4(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 32:
    tmp = fieldFromInstruction(insn, 1, 9);
    if (DecodeSimm9SP(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 33:
    if (DecodeMemMMGPImm7Lsl2(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 34:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 4, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 1, 3);
    if (DecodeAddiur2Simm7(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 35:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 1, 6);
    if (DecodeUImm6Lsl2(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 36:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeMovePRegPair(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 1, 3);
    if (DecodeGPRMM16MovePRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 4, 3);
    if (DecodeGPRMM16MovePRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 37:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 7);
    if (DecodeBranchTarget7MM(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 38:
    tmp = fieldFromInstruction(insn, 0, 10);
    if (DecodeBranchTarget10MM(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 39:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 7);
    if (DecodeLiSimm7(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 40:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 41:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 42:
    tmp = fieldFromInstruction(insn, 16, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 6, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 43:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeInsSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 44:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 45:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 46:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 47:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 48:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 49:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 50:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 51:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 52:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeExtSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 53:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 54:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 55:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 12, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 56:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 57:
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeHI32DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 58:
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeLO32DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 59:
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 60:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 61:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 62:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 63:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 64:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 13, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 65:
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 66:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 67:
    tmp = fieldFromInstruction(insn, 16, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 68:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 13, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 69:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 7);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 70:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 71:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 72:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 73:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeHWRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 74:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 75:
    tmp = fieldFromInstruction(insn, 16, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 76:
    tmp = fieldFromInstruction(insn, 14, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 77:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 78:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 79:
    if (DecodeMemMMImm16(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 80:
    if (DecodeMemMMImm12(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 81:
    if (DecodeCacheOpMM(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 82:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTargetMM(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 83:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 84:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 85:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 13, 3);
    if (DecodeFCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 86:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 87:
    if (DecodeMemMMImm9(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 88:
    if (DecodePrefeOpMM(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 89:
    if (DecodeJumpTargetMM(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 90:
    tmp = fieldFromInstruction(insn, 23, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 23);
    if (DecodeSimm23Lsl2(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 91:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTargetMM(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 92:
    tmp = fieldFromInstruction(insn, 1, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 4, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 93:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 4, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 94:
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 4, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 7, 3);
    if (DecodeGPRMM16RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 95:
    tmp = fieldFromInstruction(insn, 5, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 96:
    tmp = fieldFromInstruction(insn, 5, 5);
    if (DecodeUImm5lsl2(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 97:
    tmp = fieldFromInstruction(insn, 6, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 98:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeHWRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 99:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 9, 2);
    if (DecodeUImmWithOffset<2, 1>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 100:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 9, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 101:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 102:
    if (DecodeLoadByte15(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 103:
    if (DecodeSynciR6(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 104:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 105:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 106:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGRCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 107:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGRCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 108:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 109:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 110:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 111:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 112:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGRCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 113:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 114:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 115:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 116:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 117:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 118:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 119:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 120:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGRCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 121:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 122:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 123:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeExtSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 124:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 125:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 8, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 126:
    if (DecodeLoadByte9(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 127:
    if (DecodeStoreEvaOpMM(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 128:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTargetMM(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 129:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 19);
    if (DecodeSimm19Lsl2(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 130:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 131:
    tmp = fieldFromInstruction(insn, 0, 26);
    if (DecodeBranchTarget26MM(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 132:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    tmp |= fieldFromInstruction(insn, 21, 5) << 0;
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTargetMM(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 133:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 134:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 135:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 18, 3);
    if (DecodeFCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 136:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 2);
    if (DecodeUImmWithOffset<2, 1>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 137:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 138:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 139:
    tmp = fieldFromInstruction(insn, 6, 20);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 140:
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 141:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 142:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 143:
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeHI32DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 144:
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeLO32DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 145:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 2);
    if (DecodeUImmWithOffset<2, 1>(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 146:
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 147:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 148:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 149:
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 150:
    if (DecodeSyncI(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 151:
    if (DecodeJumpTarget(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 152:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 153:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 154:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 155:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCOP0RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 156:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCOP0RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 157:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 158:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 159:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCCRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 160:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 161:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 162:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 163:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCCRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 164:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 165:
    tmp = fieldFromInstruction(insn, 18, 3);
    if (DecodeFCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 166:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 167:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 168:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 169:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 18, 3);
    if (DecodeFCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 170:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 171:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 172:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 173:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 174:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 175:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 176:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 177:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 18, 3);
    if (DecodeFCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 178:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 179:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 180:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 181:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 182:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 183:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 184:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCOP2RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 185:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCOP2RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 186:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 187:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 188:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 189:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 190:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 191:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeAFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 192:
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 193:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 194:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 195:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 196:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 197:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 8);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 198:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 199:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 200:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 201:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 202:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 203:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 204:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 205:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 206:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 207:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 208:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 209:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 6);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 210:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 211:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 212:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 213:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 214:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 215:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 216:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 217:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 218:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 219:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 220:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 221:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 222:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 223:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 224:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 225:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 226:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 227:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 228:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 229:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 230:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 231:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 232:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 233:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 234:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 235:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 236:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 237:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 238:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 239:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSACtrlRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 240:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 241:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 242:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 243:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 244:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSACtrlRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 245:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 246:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 247:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 248:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 249:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 250:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 4);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 251:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 252:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 253:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 1);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 254:
    if (DecodeINSVE_DF(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 255:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 256:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 257:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128BRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 258:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 259:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 260:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 261:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 262:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 263:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 264:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128HRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 265:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeMSA128DRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeMSA128WRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 266:
    if (DecodeMSA128Mem(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 267:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeExtSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 268:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeInsSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 269:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 270:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 271:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 272:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 273:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 274:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 275:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 276:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 277:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 278:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 279:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 280:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 281:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeDSPRRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 282:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 283:
    if (DecodeMemEVA(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 284:
    if (DecodeCacheeOp_CacheOpR6(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 285:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 286:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 287:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 288:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 289:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 10);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 290:
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 20, 6);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 291:
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 2);
    if (DecodeACC64DSPRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 292:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeHWRegsRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 293:
    if (DecodeMem(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 294:
    if (DecodeCacheOp(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 295:
    if (DecodeFMem(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 296:
    if (DecodeFMem2(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 297:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 298:
    if (DecodeBlezGroupBranch(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 299:
    if (DecodeBgtzGroupBranch(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 300:
    if (DecodeAddiGroupBranch(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 301:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 302:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGRCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 303:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 304:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGRCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 305:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 306:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 307:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGRCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 308:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGRCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 309:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeCOP2RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeBranchTarget(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 310:
    if (DecodeFMemCop2R6(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 311:
    if (DecodeBlezlGroupBranch(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 312:
    if (DecodeBgtzlGroupBranch(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 313:
    if (DecodeDaddiGroupBranch(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 314:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 2);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 315:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 316:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 317:
    if (DecodeSpecial3LlSc(MI, insn, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 318:
    tmp = fieldFromInstruction(insn, 0, 26);
    if (DecodeBranchTarget26(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 319:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 21);
    if (DecodeBranchTarget21(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 320:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 18);
    if (DecodeSimm18Lsl3(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 321:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 322:
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 323:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 324:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCOP0RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 325:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCOP0RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 326:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 327:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 328:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 329:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 18, 3);
    if (DecodeFCCRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 330:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR32RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 331:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 332:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCOP2RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 333:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeCOP2RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 3);
    MI.addOperand(MCOperand::createImm(tmp));
    return S;
  case 334:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 335:
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodePtrRegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 336:
    tmp = fieldFromInstruction(insn, 6, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeFGR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 337:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 0, 16);
    if (DecodeSimm16(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 338:
    tmp = 0;
    tmp |= fieldFromInstruction(insn, 11, 5) << 0;
    tmp |= fieldFromInstruction(insn, 16, 5) << 0;
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 339:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeExtSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    return S;
  case 340:
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 21, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 6, 5);
    MI.addOperand(MCOperand::createImm(tmp));
    tmp = fieldFromInstruction(insn, 11, 5);
    if (DecodeInsSize(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
    tmp = fieldFromInstruction(insn, 16, 5);
    if (DecodeGPR64RegisterClass(MI, tmp, Address, Decoder) == MCDisassembler::Fail) { return MCDisassembler::Fail; }
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
