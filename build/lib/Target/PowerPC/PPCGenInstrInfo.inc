/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Instruction Enum Values                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_INSTRINFO_ENUM
#undef GET_INSTRINFO_ENUM
namespace llvm {

namespace PPC {
  enum {
    PHI	= 0,
    INLINEASM	= 1,
    CFI_INSTRUCTION	= 2,
    EH_LABEL	= 3,
    GC_LABEL	= 4,
    KILL	= 5,
    EXTRACT_SUBREG	= 6,
    INSERT_SUBREG	= 7,
    IMPLICIT_DEF	= 8,
    SUBREG_TO_REG	= 9,
    COPY_TO_REGCLASS	= 10,
    DBG_VALUE	= 11,
    REG_SEQUENCE	= 12,
    COPY	= 13,
    BUNDLE	= 14,
    LIFETIME_START	= 15,
    LIFETIME_END	= 16,
    STACKMAP	= 17,
    PATCHPOINT	= 18,
    LOAD_STACK_GUARD	= 19,
    STATEPOINT	= 20,
    LOCAL_ESCAPE	= 21,
    FAULTING_LOAD_OP	= 22,
    ADD4	= 23,
    ADD4TLS	= 24,
    ADD4o	= 25,
    ADD8	= 26,
    ADD8TLS	= 27,
    ADD8TLS_	= 28,
    ADD8o	= 29,
    ADDC	= 30,
    ADDC8	= 31,
    ADDC8o	= 32,
    ADDCo	= 33,
    ADDE	= 34,
    ADDE8	= 35,
    ADDE8o	= 36,
    ADDEo	= 37,
    ADDI	= 38,
    ADDI8	= 39,
    ADDIC	= 40,
    ADDIC8	= 41,
    ADDICo	= 42,
    ADDIS	= 43,
    ADDIS8	= 44,
    ADDISdtprelHA	= 45,
    ADDISdtprelHA32	= 46,
    ADDISgotTprelHA	= 47,
    ADDIStlsgdHA	= 48,
    ADDIStlsldHA	= 49,
    ADDIStocHA	= 50,
    ADDIdtprelL	= 51,
    ADDIdtprelL32	= 52,
    ADDItlsgdL	= 53,
    ADDItlsgdL32	= 54,
    ADDItlsgdLADDR	= 55,
    ADDItlsgdLADDR32	= 56,
    ADDItlsldL	= 57,
    ADDItlsldL32	= 58,
    ADDItlsldLADDR	= 59,
    ADDItlsldLADDR32	= 60,
    ADDItocL	= 61,
    ADDME	= 62,
    ADDME8	= 63,
    ADDME8o	= 64,
    ADDMEo	= 65,
    ADDZE	= 66,
    ADDZE8	= 67,
    ADDZE8o	= 68,
    ADDZEo	= 69,
    ADJCALLSTACKDOWN	= 70,
    ADJCALLSTACKUP	= 71,
    AND	= 72,
    AND8	= 73,
    AND8o	= 74,
    ANDC	= 75,
    ANDC8	= 76,
    ANDC8o	= 77,
    ANDCo	= 78,
    ANDISo	= 79,
    ANDISo8	= 80,
    ANDIo	= 81,
    ANDIo8	= 82,
    ANDIo_1_EQ_BIT	= 83,
    ANDIo_1_EQ_BIT8	= 84,
    ANDIo_1_GT_BIT	= 85,
    ANDIo_1_GT_BIT8	= 86,
    ANDo	= 87,
    ATOMIC_CMP_SWAP_I16	= 88,
    ATOMIC_CMP_SWAP_I32	= 89,
    ATOMIC_CMP_SWAP_I64	= 90,
    ATOMIC_CMP_SWAP_I8	= 91,
    ATOMIC_LOAD_ADD_I16	= 92,
    ATOMIC_LOAD_ADD_I32	= 93,
    ATOMIC_LOAD_ADD_I64	= 94,
    ATOMIC_LOAD_ADD_I8	= 95,
    ATOMIC_LOAD_AND_I16	= 96,
    ATOMIC_LOAD_AND_I32	= 97,
    ATOMIC_LOAD_AND_I64	= 98,
    ATOMIC_LOAD_AND_I8	= 99,
    ATOMIC_LOAD_NAND_I16	= 100,
    ATOMIC_LOAD_NAND_I32	= 101,
    ATOMIC_LOAD_NAND_I64	= 102,
    ATOMIC_LOAD_NAND_I8	= 103,
    ATOMIC_LOAD_OR_I16	= 104,
    ATOMIC_LOAD_OR_I32	= 105,
    ATOMIC_LOAD_OR_I64	= 106,
    ATOMIC_LOAD_OR_I8	= 107,
    ATOMIC_LOAD_SUB_I16	= 108,
    ATOMIC_LOAD_SUB_I32	= 109,
    ATOMIC_LOAD_SUB_I64	= 110,
    ATOMIC_LOAD_SUB_I8	= 111,
    ATOMIC_LOAD_XOR_I16	= 112,
    ATOMIC_LOAD_XOR_I32	= 113,
    ATOMIC_LOAD_XOR_I64	= 114,
    ATOMIC_LOAD_XOR_I8	= 115,
    ATOMIC_SWAP_I16	= 116,
    ATOMIC_SWAP_I32	= 117,
    ATOMIC_SWAP_I64	= 118,
    ATOMIC_SWAP_I8	= 119,
    ATTN	= 120,
    B	= 121,
    BA	= 122,
    BC	= 123,
    BCC	= 124,
    BCCA	= 125,
    BCCCTR	= 126,
    BCCCTR8	= 127,
    BCCCTRL	= 128,
    BCCCTRL8	= 129,
    BCCL	= 130,
    BCCLA	= 131,
    BCCLR	= 132,
    BCCLRL	= 133,
    BCCTR	= 134,
    BCCTR8	= 135,
    BCCTR8n	= 136,
    BCCTRL	= 137,
    BCCTRL8	= 138,
    BCCTRL8n	= 139,
    BCCTRLn	= 140,
    BCCTRn	= 141,
    BCL	= 142,
    BCLR	= 143,
    BCLRL	= 144,
    BCLRLn	= 145,
    BCLRn	= 146,
    BCLalways	= 147,
    BCLn	= 148,
    BCTR	= 149,
    BCTR8	= 150,
    BCTRL	= 151,
    BCTRL8	= 152,
    BCTRL8_LDinto_toc	= 153,
    BCn	= 154,
    BDNZ	= 155,
    BDNZ8	= 156,
    BDNZA	= 157,
    BDNZAm	= 158,
    BDNZAp	= 159,
    BDNZL	= 160,
    BDNZLA	= 161,
    BDNZLAm	= 162,
    BDNZLAp	= 163,
    BDNZLR	= 164,
    BDNZLR8	= 165,
    BDNZLRL	= 166,
    BDNZLRLm	= 167,
    BDNZLRLp	= 168,
    BDNZLRm	= 169,
    BDNZLRp	= 170,
    BDNZLm	= 171,
    BDNZLp	= 172,
    BDNZm	= 173,
    BDNZp	= 174,
    BDZ	= 175,
    BDZ8	= 176,
    BDZA	= 177,
    BDZAm	= 178,
    BDZAp	= 179,
    BDZL	= 180,
    BDZLA	= 181,
    BDZLAm	= 182,
    BDZLAp	= 183,
    BDZLR	= 184,
    BDZLR8	= 185,
    BDZLRL	= 186,
    BDZLRLm	= 187,
    BDZLRLp	= 188,
    BDZLRm	= 189,
    BDZLRp	= 190,
    BDZLm	= 191,
    BDZLp	= 192,
    BDZm	= 193,
    BDZp	= 194,
    BL	= 195,
    BL8	= 196,
    BL8_NOP	= 197,
    BL8_NOP_TLS	= 198,
    BL8_TLS	= 199,
    BL8_TLS_	= 200,
    BLA	= 201,
    BLA8	= 202,
    BLA8_NOP	= 203,
    BLR	= 204,
    BLR8	= 205,
    BLRL	= 206,
    BL_TLS	= 207,
    BPERMD	= 208,
    BRINC	= 209,
    CLRBHRB	= 210,
    CLRLSLDI	= 211,
    CLRLSLDIo	= 212,
    CLRLSLWI	= 213,
    CLRLSLWIo	= 214,
    CLRRDI	= 215,
    CLRRDIo	= 216,
    CLRRWI	= 217,
    CLRRWIo	= 218,
    CMPB	= 219,
    CMPB8	= 220,
    CMPD	= 221,
    CMPDI	= 222,
    CMPLD	= 223,
    CMPLDI	= 224,
    CMPLW	= 225,
    CMPLWI	= 226,
    CMPW	= 227,
    CMPWI	= 228,
    CNTLZD	= 229,
    CNTLZDo	= 230,
    CNTLZW	= 231,
    CNTLZW8	= 232,
    CNTLZW8o	= 233,
    CNTLZWo	= 234,
    CR6SET	= 235,
    CR6UNSET	= 236,
    CRAND	= 237,
    CRANDC	= 238,
    CREQV	= 239,
    CRNAND	= 240,
    CRNOR	= 241,
    CROR	= 242,
    CRORC	= 243,
    CRSET	= 244,
    CRUNSET	= 245,
    CRXOR	= 246,
    DCBA	= 247,
    DCBF	= 248,
    DCBI	= 249,
    DCBST	= 250,
    DCBT	= 251,
    DCBTCT	= 252,
    DCBTDS	= 253,
    DCBTST	= 254,
    DCBTSTCT	= 255,
    DCBTSTDS	= 256,
    DCBTSTT	= 257,
    DCBTSTx	= 258,
    DCBTT	= 259,
    DCBTx	= 260,
    DCBZ	= 261,
    DCBZL	= 262,
    DCCCI	= 263,
    DIVD	= 264,
    DIVDE	= 265,
    DIVDEU	= 266,
    DIVDEUo	= 267,
    DIVDEo	= 268,
    DIVDU	= 269,
    DIVDUo	= 270,
    DIVDo	= 271,
    DIVW	= 272,
    DIVWE	= 273,
    DIVWEU	= 274,
    DIVWEUo	= 275,
    DIVWEo	= 276,
    DIVWU	= 277,
    DIVWUo	= 278,
    DIVWo	= 279,
    DSS	= 280,
    DSSALL	= 281,
    DST	= 282,
    DST64	= 283,
    DSTST	= 284,
    DSTST64	= 285,
    DSTSTT	= 286,
    DSTSTT64	= 287,
    DSTT	= 288,
    DSTT64	= 289,
    DYNALLOC	= 290,
    DYNALLOC8	= 291,
    DYNAREAOFFSET	= 292,
    DYNAREAOFFSET8	= 293,
    EH_SjLj_LongJmp32	= 294,
    EH_SjLj_LongJmp64	= 295,
    EH_SjLj_SetJmp32	= 296,
    EH_SjLj_SetJmp64	= 297,
    EH_SjLj_Setup	= 298,
    EQV	= 299,
    EQV8	= 300,
    EQV8o	= 301,
    EQVo	= 302,
    EVABS	= 303,
    EVADDIW	= 304,
    EVADDSMIAAW	= 305,
    EVADDSSIAAW	= 306,
    EVADDUMIAAW	= 307,
    EVADDUSIAAW	= 308,
    EVADDW	= 309,
    EVAND	= 310,
    EVANDC	= 311,
    EVCMPEQ	= 312,
    EVCMPGTS	= 313,
    EVCMPGTU	= 314,
    EVCMPLTS	= 315,
    EVCMPLTU	= 316,
    EVCNTLSW	= 317,
    EVCNTLZW	= 318,
    EVDIVWS	= 319,
    EVDIVWU	= 320,
    EVEQV	= 321,
    EVEXTSB	= 322,
    EVEXTSH	= 323,
    EVLDD	= 324,
    EVLDDX	= 325,
    EVLDH	= 326,
    EVLDHX	= 327,
    EVLDW	= 328,
    EVLDWX	= 329,
    EVLHHESPLAT	= 330,
    EVLHHESPLATX	= 331,
    EVLHHOSSPLAT	= 332,
    EVLHHOSSPLATX	= 333,
    EVLHHOUSPLAT	= 334,
    EVLHHOUSPLATX	= 335,
    EVLWHE	= 336,
    EVLWHEX	= 337,
    EVLWHOS	= 338,
    EVLWHOSX	= 339,
    EVLWHOU	= 340,
    EVLWHOUX	= 341,
    EVLWHSPLAT	= 342,
    EVLWHSPLATX	= 343,
    EVLWWSPLAT	= 344,
    EVLWWSPLATX	= 345,
    EVMERGEHI	= 346,
    EVMERGEHILO	= 347,
    EVMERGELO	= 348,
    EVMERGELOHI	= 349,
    EVMHEGSMFAA	= 350,
    EVMHEGSMFAN	= 351,
    EVMHEGSMIAA	= 352,
    EVMHEGSMIAN	= 353,
    EVMHEGUMIAA	= 354,
    EVMHEGUMIAN	= 355,
    EVMHESMF	= 356,
    EVMHESMFA	= 357,
    EVMHESMFAAW	= 358,
    EVMHESMFANW	= 359,
    EVMHESMI	= 360,
    EVMHESMIA	= 361,
    EVMHESMIAAW	= 362,
    EVMHESMIANW	= 363,
    EVMHESSF	= 364,
    EVMHESSFA	= 365,
    EVMHESSFAAW	= 366,
    EVMHESSFANW	= 367,
    EVMHESSIAAW	= 368,
    EVMHESSIANW	= 369,
    EVMHEUMI	= 370,
    EVMHEUMIA	= 371,
    EVMHEUMIAAW	= 372,
    EVMHEUMIANW	= 373,
    EVMHEUSIAAW	= 374,
    EVMHEUSIANW	= 375,
    EVMHOGSMFAA	= 376,
    EVMHOGSMFAN	= 377,
    EVMHOGSMIAA	= 378,
    EVMHOGSMIAN	= 379,
    EVMHOGUMIAA	= 380,
    EVMHOGUMIAN	= 381,
    EVMHOSMF	= 382,
    EVMHOSMFA	= 383,
    EVMHOSMFAAW	= 384,
    EVMHOSMFANW	= 385,
    EVMHOSMI	= 386,
    EVMHOSMIA	= 387,
    EVMHOSMIAAW	= 388,
    EVMHOSMIANW	= 389,
    EVMHOSSF	= 390,
    EVMHOSSFA	= 391,
    EVMHOSSFAAW	= 392,
    EVMHOSSFANW	= 393,
    EVMHOSSIAAW	= 394,
    EVMHOSSIANW	= 395,
    EVMHOUMI	= 396,
    EVMHOUMIA	= 397,
    EVMHOUMIAAW	= 398,
    EVMHOUMIANW	= 399,
    EVMHOUSIAAW	= 400,
    EVMHOUSIANW	= 401,
    EVMRA	= 402,
    EVMWHSMF	= 403,
    EVMWHSMFA	= 404,
    EVMWHSMI	= 405,
    EVMWHSMIA	= 406,
    EVMWHSSF	= 407,
    EVMWHSSFA	= 408,
    EVMWHUMI	= 409,
    EVMWHUMIA	= 410,
    EVMWLSMIAAW	= 411,
    EVMWLSMIANW	= 412,
    EVMWLSSIAAW	= 413,
    EVMWLSSIANW	= 414,
    EVMWLUMI	= 415,
    EVMWLUMIA	= 416,
    EVMWLUMIAAW	= 417,
    EVMWLUMIANW	= 418,
    EVMWLUSIAAW	= 419,
    EVMWLUSIANW	= 420,
    EVMWSMF	= 421,
    EVMWSMFA	= 422,
    EVMWSMFAA	= 423,
    EVMWSMFAN	= 424,
    EVMWSMI	= 425,
    EVMWSMIA	= 426,
    EVMWSMIAA	= 427,
    EVMWSMIAN	= 428,
    EVMWSSF	= 429,
    EVMWSSFA	= 430,
    EVMWSSFAA	= 431,
    EVMWSSFAN	= 432,
    EVMWUMI	= 433,
    EVMWUMIA	= 434,
    EVMWUMIAA	= 435,
    EVMWUMIAN	= 436,
    EVNAND	= 437,
    EVNEG	= 438,
    EVNOR	= 439,
    EVOR	= 440,
    EVORC	= 441,
    EVRLW	= 442,
    EVRLWI	= 443,
    EVRNDW	= 444,
    EVSLW	= 445,
    EVSLWI	= 446,
    EVSPLATFI	= 447,
    EVSPLATI	= 448,
    EVSRWIS	= 449,
    EVSRWIU	= 450,
    EVSRWS	= 451,
    EVSRWU	= 452,
    EVSTDD	= 453,
    EVSTDDX	= 454,
    EVSTDH	= 455,
    EVSTDHX	= 456,
    EVSTDW	= 457,
    EVSTDWX	= 458,
    EVSTWHE	= 459,
    EVSTWHEX	= 460,
    EVSTWHO	= 461,
    EVSTWHOX	= 462,
    EVSTWWE	= 463,
    EVSTWWEX	= 464,
    EVSTWWO	= 465,
    EVSTWWOX	= 466,
    EVSUBFSMIAAW	= 467,
    EVSUBFSSIAAW	= 468,
    EVSUBFUMIAAW	= 469,
    EVSUBFUSIAAW	= 470,
    EVSUBFW	= 471,
    EVSUBIFW	= 472,
    EVXOR	= 473,
    EXTLDI	= 474,
    EXTLDIo	= 475,
    EXTLWI	= 476,
    EXTLWIo	= 477,
    EXTRDI	= 478,
    EXTRDIo	= 479,
    EXTRWI	= 480,
    EXTRWIo	= 481,
    EXTSB	= 482,
    EXTSB8	= 483,
    EXTSB8_32_64	= 484,
    EXTSB8o	= 485,
    EXTSBo	= 486,
    EXTSH	= 487,
    EXTSH8	= 488,
    EXTSH8_32_64	= 489,
    EXTSH8o	= 490,
    EXTSHo	= 491,
    EXTSW	= 492,
    EXTSW_32_64	= 493,
    EXTSW_32_64o	= 494,
    EXTSWo	= 495,
    EnforceIEIO	= 496,
    FABSD	= 497,
    FABSDo	= 498,
    FABSS	= 499,
    FABSSo	= 500,
    FADD	= 501,
    FADDS	= 502,
    FADDSo	= 503,
    FADDo	= 504,
    FADDrtz	= 505,
    FCFID	= 506,
    FCFIDS	= 507,
    FCFIDSo	= 508,
    FCFIDU	= 509,
    FCFIDUS	= 510,
    FCFIDUSo	= 511,
    FCFIDUo	= 512,
    FCFIDo	= 513,
    FCMPUD	= 514,
    FCMPUS	= 515,
    FCPSGND	= 516,
    FCPSGNDo	= 517,
    FCPSGNS	= 518,
    FCPSGNSo	= 519,
    FCTID	= 520,
    FCTIDUZ	= 521,
    FCTIDUZo	= 522,
    FCTIDZ	= 523,
    FCTIDZo	= 524,
    FCTIDo	= 525,
    FCTIW	= 526,
    FCTIWUZ	= 527,
    FCTIWUZo	= 528,
    FCTIWZ	= 529,
    FCTIWZo	= 530,
    FCTIWo	= 531,
    FDIV	= 532,
    FDIVS	= 533,
    FDIVSo	= 534,
    FDIVo	= 535,
    FMADD	= 536,
    FMADDS	= 537,
    FMADDSo	= 538,
    FMADDo	= 539,
    FMR	= 540,
    FMRo	= 541,
    FMSUB	= 542,
    FMSUBS	= 543,
    FMSUBSo	= 544,
    FMSUBo	= 545,
    FMUL	= 546,
    FMULS	= 547,
    FMULSo	= 548,
    FMULo	= 549,
    FNABSD	= 550,
    FNABSDo	= 551,
    FNABSS	= 552,
    FNABSSo	= 553,
    FNEGD	= 554,
    FNEGDo	= 555,
    FNEGS	= 556,
    FNEGSo	= 557,
    FNMADD	= 558,
    FNMADDS	= 559,
    FNMADDSo	= 560,
    FNMADDo	= 561,
    FNMSUB	= 562,
    FNMSUBS	= 563,
    FNMSUBSo	= 564,
    FNMSUBo	= 565,
    FRE	= 566,
    FRES	= 567,
    FRESo	= 568,
    FREo	= 569,
    FRIMD	= 570,
    FRIMDo	= 571,
    FRIMS	= 572,
    FRIMSo	= 573,
    FRIND	= 574,
    FRINDo	= 575,
    FRINS	= 576,
    FRINSo	= 577,
    FRIPD	= 578,
    FRIPDo	= 579,
    FRIPS	= 580,
    FRIPSo	= 581,
    FRIZD	= 582,
    FRIZDo	= 583,
    FRIZS	= 584,
    FRIZSo	= 585,
    FRSP	= 586,
    FRSPo	= 587,
    FRSQRTE	= 588,
    FRSQRTES	= 589,
    FRSQRTESo	= 590,
    FRSQRTEo	= 591,
    FSELD	= 592,
    FSELDo	= 593,
    FSELS	= 594,
    FSELSo	= 595,
    FSQRT	= 596,
    FSQRTS	= 597,
    FSQRTSo	= 598,
    FSQRTo	= 599,
    FSUB	= 600,
    FSUBS	= 601,
    FSUBSo	= 602,
    FSUBo	= 603,
    GETtlsADDR	= 604,
    GETtlsADDR32	= 605,
    GETtlsldADDR	= 606,
    GETtlsldADDR32	= 607,
    ICBI	= 608,
    ICBT	= 609,
    ICCCI	= 610,
    INSLWI	= 611,
    INSLWIo	= 612,
    INSRDI	= 613,
    INSRDIo	= 614,
    INSRWI	= 615,
    INSRWIo	= 616,
    ISEL	= 617,
    ISEL8	= 618,
    ISYNC	= 619,
    LA	= 620,
    LAx	= 621,
    LBARX	= 622,
    LBARXL	= 623,
    LBZ	= 624,
    LBZ8	= 625,
    LBZCIX	= 626,
    LBZU	= 627,
    LBZU8	= 628,
    LBZUX	= 629,
    LBZUX8	= 630,
    LBZX	= 631,
    LBZX8	= 632,
    LD	= 633,
    LDARX	= 634,
    LDARXL	= 635,
    LDBRX	= 636,
    LDCIX	= 637,
    LDU	= 638,
    LDUX	= 639,
    LDX	= 640,
    LDgotTprelL	= 641,
    LDgotTprelL32	= 642,
    LDtoc	= 643,
    LDtocBA	= 644,
    LDtocCPT	= 645,
    LDtocJTI	= 646,
    LDtocL	= 647,
    LFD	= 648,
    LFDU	= 649,
    LFDUX	= 650,
    LFDX	= 651,
    LFIWAX	= 652,
    LFIWZX	= 653,
    LFS	= 654,
    LFSU	= 655,
    LFSUX	= 656,
    LFSX	= 657,
    LHA	= 658,
    LHA8	= 659,
    LHARX	= 660,
    LHARXL	= 661,
    LHAU	= 662,
    LHAU8	= 663,
    LHAUX	= 664,
    LHAUX8	= 665,
    LHAX	= 666,
    LHAX8	= 667,
    LHBRX	= 668,
    LHBRX8	= 669,
    LHZ	= 670,
    LHZ8	= 671,
    LHZCIX	= 672,
    LHZU	= 673,
    LHZU8	= 674,
    LHZUX	= 675,
    LHZUX8	= 676,
    LHZX	= 677,
    LHZX8	= 678,
    LI	= 679,
    LI8	= 680,
    LIS	= 681,
    LIS8	= 682,
    LMW	= 683,
    LSWI	= 684,
    LVEBX	= 685,
    LVEHX	= 686,
    LVEWX	= 687,
    LVSL	= 688,
    LVSR	= 689,
    LVX	= 690,
    LVXL	= 691,
    LWA	= 692,
    LWARX	= 693,
    LWARXL	= 694,
    LWAUX	= 695,
    LWAX	= 696,
    LWAX_32	= 697,
    LWA_32	= 698,
    LWBRX	= 699,
    LWBRX8	= 700,
    LWZ	= 701,
    LWZ8	= 702,
    LWZCIX	= 703,
    LWZU	= 704,
    LWZU8	= 705,
    LWZUX	= 706,
    LWZUX8	= 707,
    LWZX	= 708,
    LWZX8	= 709,
    LWZtoc	= 710,
    LXSDX	= 711,
    LXSIWAX	= 712,
    LXSIWZX	= 713,
    LXSSPX	= 714,
    LXVD2X	= 715,
    LXVDSX	= 716,
    LXVW4X	= 717,
    MBAR	= 718,
    MCRF	= 719,
    MCRFS	= 720,
    MFBHRBE	= 721,
    MFCR	= 722,
    MFCR8	= 723,
    MFCTR	= 724,
    MFCTR8	= 725,
    MFDCR	= 726,
    MFFS	= 727,
    MFFSo	= 728,
    MFLR	= 729,
    MFLR8	= 730,
    MFMSR	= 731,
    MFOCRF	= 732,
    MFOCRF8	= 733,
    MFSPR	= 734,
    MFSPR8	= 735,
    MFSR	= 736,
    MFSRIN	= 737,
    MFTB	= 738,
    MFTB8	= 739,
    MFVRSAVE	= 740,
    MFVRSAVEv	= 741,
    MFVSCR	= 742,
    MFVSRD	= 743,
    MFVSRWZ	= 744,
    MSYNC	= 745,
    MTCRF	= 746,
    MTCRF8	= 747,
    MTCTR	= 748,
    MTCTR8	= 749,
    MTCTR8loop	= 750,
    MTCTRloop	= 751,
    MTDCR	= 752,
    MTFSB0	= 753,
    MTFSB1	= 754,
    MTFSF	= 755,
    MTFSFI	= 756,
    MTFSFIo	= 757,
    MTFSFb	= 758,
    MTFSFo	= 759,
    MTLR	= 760,
    MTLR8	= 761,
    MTMSR	= 762,
    MTMSRD	= 763,
    MTOCRF	= 764,
    MTOCRF8	= 765,
    MTSPR	= 766,
    MTSPR8	= 767,
    MTSR	= 768,
    MTSRIN	= 769,
    MTVRSAVE	= 770,
    MTVRSAVEv	= 771,
    MTVSCR	= 772,
    MTVSRD	= 773,
    MTVSRWA	= 774,
    MTVSRWZ	= 775,
    MULHD	= 776,
    MULHDU	= 777,
    MULHDUo	= 778,
    MULHDo	= 779,
    MULHW	= 780,
    MULHWU	= 781,
    MULHWUo	= 782,
    MULHWo	= 783,
    MULLD	= 784,
    MULLDo	= 785,
    MULLI	= 786,
    MULLI8	= 787,
    MULLW	= 788,
    MULLWo	= 789,
    MoveGOTtoLR	= 790,
    MovePCtoLR	= 791,
    MovePCtoLR8	= 792,
    NAND	= 793,
    NAND8	= 794,
    NAND8o	= 795,
    NANDo	= 796,
    NEG	= 797,
    NEG8	= 798,
    NEG8o	= 799,
    NEGo	= 800,
    NOP	= 801,
    NOP_GT_PWR6	= 802,
    NOP_GT_PWR7	= 803,
    NOR	= 804,
    NOR8	= 805,
    NOR8o	= 806,
    NORo	= 807,
    OR	= 808,
    OR8	= 809,
    OR8o	= 810,
    ORC	= 811,
    ORC8	= 812,
    ORC8o	= 813,
    ORCo	= 814,
    ORI	= 815,
    ORI8	= 816,
    ORIS	= 817,
    ORIS8	= 818,
    ORo	= 819,
    POPCNTD	= 820,
    POPCNTW	= 821,
    PPC32GOT	= 822,
    PPC32PICGOT	= 823,
    QVALIGNI	= 824,
    QVALIGNIb	= 825,
    QVALIGNIs	= 826,
    QVESPLATI	= 827,
    QVESPLATIb	= 828,
    QVESPLATIs	= 829,
    QVFABS	= 830,
    QVFABSs	= 831,
    QVFADD	= 832,
    QVFADDS	= 833,
    QVFADDSs	= 834,
    QVFCFID	= 835,
    QVFCFIDS	= 836,
    QVFCFIDU	= 837,
    QVFCFIDUS	= 838,
    QVFCFIDb	= 839,
    QVFCMPEQ	= 840,
    QVFCMPEQb	= 841,
    QVFCMPEQbs	= 842,
    QVFCMPGT	= 843,
    QVFCMPGTb	= 844,
    QVFCMPGTbs	= 845,
    QVFCMPLT	= 846,
    QVFCMPLTb	= 847,
    QVFCMPLTbs	= 848,
    QVFCPSGN	= 849,
    QVFCPSGNs	= 850,
    QVFCTID	= 851,
    QVFCTIDU	= 852,
    QVFCTIDUZ	= 853,
    QVFCTIDZ	= 854,
    QVFCTIDb	= 855,
    QVFCTIW	= 856,
    QVFCTIWU	= 857,
    QVFCTIWUZ	= 858,
    QVFCTIWZ	= 859,
    QVFLOGICAL	= 860,
    QVFLOGICALb	= 861,
    QVFLOGICALs	= 862,
    QVFMADD	= 863,
    QVFMADDS	= 864,
    QVFMADDSs	= 865,
    QVFMR	= 866,
    QVFMRb	= 867,
    QVFMRs	= 868,
    QVFMSUB	= 869,
    QVFMSUBS	= 870,
    QVFMSUBSs	= 871,
    QVFMUL	= 872,
    QVFMULS	= 873,
    QVFMULSs	= 874,
    QVFNABS	= 875,
    QVFNABSs	= 876,
    QVFNEG	= 877,
    QVFNEGs	= 878,
    QVFNMADD	= 879,
    QVFNMADDS	= 880,
    QVFNMADDSs	= 881,
    QVFNMSUB	= 882,
    QVFNMSUBS	= 883,
    QVFNMSUBSs	= 884,
    QVFPERM	= 885,
    QVFPERMs	= 886,
    QVFRE	= 887,
    QVFRES	= 888,
    QVFRESs	= 889,
    QVFRIM	= 890,
    QVFRIMs	= 891,
    QVFRIN	= 892,
    QVFRINs	= 893,
    QVFRIP	= 894,
    QVFRIPs	= 895,
    QVFRIZ	= 896,
    QVFRIZs	= 897,
    QVFRSP	= 898,
    QVFRSPs	= 899,
    QVFRSQRTE	= 900,
    QVFRSQRTES	= 901,
    QVFRSQRTESs	= 902,
    QVFSEL	= 903,
    QVFSELb	= 904,
    QVFSELbb	= 905,
    QVFSELbs	= 906,
    QVFSUB	= 907,
    QVFSUBS	= 908,
    QVFSUBSs	= 909,
    QVFTSTNAN	= 910,
    QVFTSTNANb	= 911,
    QVFTSTNANbs	= 912,
    QVFXMADD	= 913,
    QVFXMADDS	= 914,
    QVFXMUL	= 915,
    QVFXMULS	= 916,
    QVFXXCPNMADD	= 917,
    QVFXXCPNMADDS	= 918,
    QVFXXMADD	= 919,
    QVFXXMADDS	= 920,
    QVFXXNPMADD	= 921,
    QVFXXNPMADDS	= 922,
    QVGPCI	= 923,
    QVLFCDUX	= 924,
    QVLFCDUXA	= 925,
    QVLFCDX	= 926,
    QVLFCDXA	= 927,
    QVLFCSUX	= 928,
    QVLFCSUXA	= 929,
    QVLFCSX	= 930,
    QVLFCSXA	= 931,
    QVLFCSXs	= 932,
    QVLFDUX	= 933,
    QVLFDUXA	= 934,
    QVLFDX	= 935,
    QVLFDXA	= 936,
    QVLFDXb	= 937,
    QVLFIWAX	= 938,
    QVLFIWAXA	= 939,
    QVLFIWZX	= 940,
    QVLFIWZXA	= 941,
    QVLFSUX	= 942,
    QVLFSUXA	= 943,
    QVLFSX	= 944,
    QVLFSXA	= 945,
    QVLFSXb	= 946,
    QVLFSXs	= 947,
    QVLPCLDX	= 948,
    QVLPCLSX	= 949,
    QVLPCLSXint	= 950,
    QVLPCRDX	= 951,
    QVLPCRSX	= 952,
    QVSTFCDUX	= 953,
    QVSTFCDUXA	= 954,
    QVSTFCDUXI	= 955,
    QVSTFCDUXIA	= 956,
    QVSTFCDX	= 957,
    QVSTFCDXA	= 958,
    QVSTFCDXI	= 959,
    QVSTFCDXIA	= 960,
    QVSTFCSUX	= 961,
    QVSTFCSUXA	= 962,
    QVSTFCSUXI	= 963,
    QVSTFCSUXIA	= 964,
    QVSTFCSX	= 965,
    QVSTFCSXA	= 966,
    QVSTFCSXI	= 967,
    QVSTFCSXIA	= 968,
    QVSTFCSXs	= 969,
    QVSTFDUX	= 970,
    QVSTFDUXA	= 971,
    QVSTFDUXI	= 972,
    QVSTFDUXIA	= 973,
    QVSTFDX	= 974,
    QVSTFDXA	= 975,
    QVSTFDXI	= 976,
    QVSTFDXIA	= 977,
    QVSTFDXb	= 978,
    QVSTFIWX	= 979,
    QVSTFIWXA	= 980,
    QVSTFSUX	= 981,
    QVSTFSUXA	= 982,
    QVSTFSUXI	= 983,
    QVSTFSUXIA	= 984,
    QVSTFSUXs	= 985,
    QVSTFSX	= 986,
    QVSTFSXA	= 987,
    QVSTFSXI	= 988,
    QVSTFSXIA	= 989,
    QVSTFSXs	= 990,
    RESTORE_CR	= 991,
    RESTORE_CRBIT	= 992,
    RESTORE_VRSAVE	= 993,
    RFCI	= 994,
    RFDI	= 995,
    RFEBB	= 996,
    RFI	= 997,
    RFID	= 998,
    RFMCI	= 999,
    RLDCL	= 1000,
    RLDCLo	= 1001,
    RLDCR	= 1002,
    RLDCRo	= 1003,
    RLDIC	= 1004,
    RLDICL	= 1005,
    RLDICL_32_64	= 1006,
    RLDICLo	= 1007,
    RLDICR	= 1008,
    RLDICRo	= 1009,
    RLDICo	= 1010,
    RLDIMI	= 1011,
    RLDIMIo	= 1012,
    RLWIMI	= 1013,
    RLWIMI8	= 1014,
    RLWIMI8o	= 1015,
    RLWIMIbm	= 1016,
    RLWIMIo	= 1017,
    RLWIMIobm	= 1018,
    RLWINM	= 1019,
    RLWINM8	= 1020,
    RLWINM8o	= 1021,
    RLWINMbm	= 1022,
    RLWINMo	= 1023,
    RLWINMobm	= 1024,
    RLWNM	= 1025,
    RLWNM8	= 1026,
    RLWNM8o	= 1027,
    RLWNMbm	= 1028,
    RLWNMo	= 1029,
    RLWNMobm	= 1030,
    ROTRDI	= 1031,
    ROTRDIo	= 1032,
    ROTRWI	= 1033,
    ROTRWIo	= 1034,
    ReadTB	= 1035,
    SC	= 1036,
    SELECT_CC_F4	= 1037,
    SELECT_CC_F8	= 1038,
    SELECT_CC_I4	= 1039,
    SELECT_CC_I8	= 1040,
    SELECT_CC_QBRC	= 1041,
    SELECT_CC_QFRC	= 1042,
    SELECT_CC_QSRC	= 1043,
    SELECT_CC_VRRC	= 1044,
    SELECT_CC_VSFRC	= 1045,
    SELECT_CC_VSRC	= 1046,
    SELECT_CC_VSSRC	= 1047,
    SELECT_F4	= 1048,
    SELECT_F8	= 1049,
    SELECT_I4	= 1050,
    SELECT_I8	= 1051,
    SELECT_QBRC	= 1052,
    SELECT_QFRC	= 1053,
    SELECT_QSRC	= 1054,
    SELECT_VRRC	= 1055,
    SELECT_VSFRC	= 1056,
    SELECT_VSRC	= 1057,
    SELECT_VSSRC	= 1058,
    SLBIA	= 1059,
    SLBIE	= 1060,
    SLBMFEE	= 1061,
    SLBMTE	= 1062,
    SLD	= 1063,
    SLDI	= 1064,
    SLDIo	= 1065,
    SLDo	= 1066,
    SLW	= 1067,
    SLW8	= 1068,
    SLW8o	= 1069,
    SLWI	= 1070,
    SLWIo	= 1071,
    SLWo	= 1072,
    SPILL_CR	= 1073,
    SPILL_CRBIT	= 1074,
    SPILL_VRSAVE	= 1075,
    SRAD	= 1076,
    SRADI	= 1077,
    SRADIo	= 1078,
    SRADo	= 1079,
    SRAW	= 1080,
    SRAWI	= 1081,
    SRAWIo	= 1082,
    SRAWo	= 1083,
    SRD	= 1084,
    SRDI	= 1085,
    SRDIo	= 1086,
    SRDo	= 1087,
    SRW	= 1088,
    SRW8	= 1089,
    SRW8o	= 1090,
    SRWI	= 1091,
    SRWIo	= 1092,
    SRWo	= 1093,
    STB	= 1094,
    STB8	= 1095,
    STBCIX	= 1096,
    STBCX	= 1097,
    STBU	= 1098,
    STBU8	= 1099,
    STBUX	= 1100,
    STBUX8	= 1101,
    STBX	= 1102,
    STBX8	= 1103,
    STD	= 1104,
    STDBRX	= 1105,
    STDCIX	= 1106,
    STDCX	= 1107,
    STDU	= 1108,
    STDUX	= 1109,
    STDX	= 1110,
    STFD	= 1111,
    STFDU	= 1112,
    STFDUX	= 1113,
    STFDX	= 1114,
    STFIWX	= 1115,
    STFS	= 1116,
    STFSU	= 1117,
    STFSUX	= 1118,
    STFSX	= 1119,
    STH	= 1120,
    STH8	= 1121,
    STHBRX	= 1122,
    STHCIX	= 1123,
    STHCX	= 1124,
    STHU	= 1125,
    STHU8	= 1126,
    STHUX	= 1127,
    STHUX8	= 1128,
    STHX	= 1129,
    STHX8	= 1130,
    STMW	= 1131,
    STSWI	= 1132,
    STVEBX	= 1133,
    STVEHX	= 1134,
    STVEWX	= 1135,
    STVX	= 1136,
    STVXL	= 1137,
    STW	= 1138,
    STW8	= 1139,
    STWBRX	= 1140,
    STWCIX	= 1141,
    STWCX	= 1142,
    STWU	= 1143,
    STWU8	= 1144,
    STWUX	= 1145,
    STWUX8	= 1146,
    STWX	= 1147,
    STWX8	= 1148,
    STXSDX	= 1149,
    STXSIWX	= 1150,
    STXSSPX	= 1151,
    STXVD2X	= 1152,
    STXVW4X	= 1153,
    SUBF	= 1154,
    SUBF8	= 1155,
    SUBF8o	= 1156,
    SUBFC	= 1157,
    SUBFC8	= 1158,
    SUBFC8o	= 1159,
    SUBFCo	= 1160,
    SUBFE	= 1161,
    SUBFE8	= 1162,
    SUBFE8o	= 1163,
    SUBFEo	= 1164,
    SUBFIC	= 1165,
    SUBFIC8	= 1166,
    SUBFME	= 1167,
    SUBFME8	= 1168,
    SUBFME8o	= 1169,
    SUBFMEo	= 1170,
    SUBFZE	= 1171,
    SUBFZE8	= 1172,
    SUBFZE8o	= 1173,
    SUBFZEo	= 1174,
    SUBFo	= 1175,
    SUBI	= 1176,
    SUBIC	= 1177,
    SUBICo	= 1178,
    SUBIS	= 1179,
    SYNC	= 1180,
    TABORT	= 1181,
    TABORTDC	= 1182,
    TABORTDCI	= 1183,
    TABORTWC	= 1184,
    TABORTWCI	= 1185,
    TAILB	= 1186,
    TAILB8	= 1187,
    TAILBA	= 1188,
    TAILBA8	= 1189,
    TAILBCTR	= 1190,
    TAILBCTR8	= 1191,
    TBEGIN	= 1192,
    TCHECK	= 1193,
    TCHECK_RET	= 1194,
    TCRETURNai	= 1195,
    TCRETURNai8	= 1196,
    TCRETURNdi	= 1197,
    TCRETURNdi8	= 1198,
    TCRETURNri	= 1199,
    TCRETURNri8	= 1200,
    TD	= 1201,
    TDI	= 1202,
    TEND	= 1203,
    TLBIA	= 1204,
    TLBIE	= 1205,
    TLBIEL	= 1206,
    TLBIVAX	= 1207,
    TLBLD	= 1208,
    TLBLI	= 1209,
    TLBRE	= 1210,
    TLBRE2	= 1211,
    TLBSX	= 1212,
    TLBSX2	= 1213,
    TLBSX2D	= 1214,
    TLBSYNC	= 1215,
    TLBWE	= 1216,
    TLBWE2	= 1217,
    TRAP	= 1218,
    TRECHKPT	= 1219,
    TRECLAIM	= 1220,
    TSR	= 1221,
    TW	= 1222,
    TWI	= 1223,
    UPDATE_VRSAVE	= 1224,
    UpdateGBR	= 1225,
    VADDCUQ	= 1226,
    VADDCUW	= 1227,
    VADDECUQ	= 1228,
    VADDEUQM	= 1229,
    VADDFP	= 1230,
    VADDSBS	= 1231,
    VADDSHS	= 1232,
    VADDSWS	= 1233,
    VADDUBM	= 1234,
    VADDUBS	= 1235,
    VADDUDM	= 1236,
    VADDUHM	= 1237,
    VADDUHS	= 1238,
    VADDUQM	= 1239,
    VADDUWM	= 1240,
    VADDUWS	= 1241,
    VAND	= 1242,
    VANDC	= 1243,
    VAVGSB	= 1244,
    VAVGSH	= 1245,
    VAVGSW	= 1246,
    VAVGUB	= 1247,
    VAVGUH	= 1248,
    VAVGUW	= 1249,
    VBPERMQ	= 1250,
    VCFSX	= 1251,
    VCFSX_0	= 1252,
    VCFUX	= 1253,
    VCFUX_0	= 1254,
    VCIPHER	= 1255,
    VCIPHERLAST	= 1256,
    VCLZB	= 1257,
    VCLZD	= 1258,
    VCLZH	= 1259,
    VCLZW	= 1260,
    VCMPBFP	= 1261,
    VCMPBFPo	= 1262,
    VCMPEQFP	= 1263,
    VCMPEQFPo	= 1264,
    VCMPEQUB	= 1265,
    VCMPEQUBo	= 1266,
    VCMPEQUD	= 1267,
    VCMPEQUDo	= 1268,
    VCMPEQUH	= 1269,
    VCMPEQUHo	= 1270,
    VCMPEQUW	= 1271,
    VCMPEQUWo	= 1272,
    VCMPGEFP	= 1273,
    VCMPGEFPo	= 1274,
    VCMPGTFP	= 1275,
    VCMPGTFPo	= 1276,
    VCMPGTSB	= 1277,
    VCMPGTSBo	= 1278,
    VCMPGTSD	= 1279,
    VCMPGTSDo	= 1280,
    VCMPGTSH	= 1281,
    VCMPGTSHo	= 1282,
    VCMPGTSW	= 1283,
    VCMPGTSWo	= 1284,
    VCMPGTUB	= 1285,
    VCMPGTUBo	= 1286,
    VCMPGTUD	= 1287,
    VCMPGTUDo	= 1288,
    VCMPGTUH	= 1289,
    VCMPGTUHo	= 1290,
    VCMPGTUW	= 1291,
    VCMPGTUWo	= 1292,
    VCTSXS	= 1293,
    VCTSXS_0	= 1294,
    VCTUXS	= 1295,
    VCTUXS_0	= 1296,
    VEQV	= 1297,
    VEXPTEFP	= 1298,
    VGBBD	= 1299,
    VLOGEFP	= 1300,
    VMADDFP	= 1301,
    VMAXFP	= 1302,
    VMAXSB	= 1303,
    VMAXSD	= 1304,
    VMAXSH	= 1305,
    VMAXSW	= 1306,
    VMAXUB	= 1307,
    VMAXUD	= 1308,
    VMAXUH	= 1309,
    VMAXUW	= 1310,
    VMHADDSHS	= 1311,
    VMHRADDSHS	= 1312,
    VMINFP	= 1313,
    VMINSB	= 1314,
    VMINSD	= 1315,
    VMINSH	= 1316,
    VMINSW	= 1317,
    VMINUB	= 1318,
    VMINUD	= 1319,
    VMINUH	= 1320,
    VMINUW	= 1321,
    VMLADDUHM	= 1322,
    VMRGEW	= 1323,
    VMRGHB	= 1324,
    VMRGHH	= 1325,
    VMRGHW	= 1326,
    VMRGLB	= 1327,
    VMRGLH	= 1328,
    VMRGLW	= 1329,
    VMRGOW	= 1330,
    VMSUMMBM	= 1331,
    VMSUMSHM	= 1332,
    VMSUMSHS	= 1333,
    VMSUMUBM	= 1334,
    VMSUMUHM	= 1335,
    VMSUMUHS	= 1336,
    VMULESB	= 1337,
    VMULESH	= 1338,
    VMULESW	= 1339,
    VMULEUB	= 1340,
    VMULEUH	= 1341,
    VMULEUW	= 1342,
    VMULOSB	= 1343,
    VMULOSH	= 1344,
    VMULOSW	= 1345,
    VMULOUB	= 1346,
    VMULOUH	= 1347,
    VMULOUW	= 1348,
    VMULUWM	= 1349,
    VNAND	= 1350,
    VNCIPHER	= 1351,
    VNCIPHERLAST	= 1352,
    VNMSUBFP	= 1353,
    VNOR	= 1354,
    VOR	= 1355,
    VORC	= 1356,
    VPERM	= 1357,
    VPERMXOR	= 1358,
    VPKPX	= 1359,
    VPKSDSS	= 1360,
    VPKSDUS	= 1361,
    VPKSHSS	= 1362,
    VPKSHUS	= 1363,
    VPKSWSS	= 1364,
    VPKSWUS	= 1365,
    VPKUDUM	= 1366,
    VPKUDUS	= 1367,
    VPKUHUM	= 1368,
    VPKUHUS	= 1369,
    VPKUWUM	= 1370,
    VPKUWUS	= 1371,
    VPMSUMB	= 1372,
    VPMSUMD	= 1373,
    VPMSUMH	= 1374,
    VPMSUMW	= 1375,
    VPOPCNTB	= 1376,
    VPOPCNTD	= 1377,
    VPOPCNTH	= 1378,
    VPOPCNTW	= 1379,
    VREFP	= 1380,
    VRFIM	= 1381,
    VRFIN	= 1382,
    VRFIP	= 1383,
    VRFIZ	= 1384,
    VRLB	= 1385,
    VRLD	= 1386,
    VRLH	= 1387,
    VRLW	= 1388,
    VRSQRTEFP	= 1389,
    VSBOX	= 1390,
    VSEL	= 1391,
    VSHASIGMAD	= 1392,
    VSHASIGMAW	= 1393,
    VSL	= 1394,
    VSLB	= 1395,
    VSLD	= 1396,
    VSLDOI	= 1397,
    VSLH	= 1398,
    VSLO	= 1399,
    VSLW	= 1400,
    VSPLTB	= 1401,
    VSPLTH	= 1402,
    VSPLTISB	= 1403,
    VSPLTISH	= 1404,
    VSPLTISW	= 1405,
    VSPLTW	= 1406,
    VSR	= 1407,
    VSRAB	= 1408,
    VSRAD	= 1409,
    VSRAH	= 1410,
    VSRAW	= 1411,
    VSRB	= 1412,
    VSRD	= 1413,
    VSRH	= 1414,
    VSRO	= 1415,
    VSRW	= 1416,
    VSUBCUQ	= 1417,
    VSUBCUW	= 1418,
    VSUBECUQ	= 1419,
    VSUBEUQM	= 1420,
    VSUBFP	= 1421,
    VSUBSBS	= 1422,
    VSUBSHS	= 1423,
    VSUBSWS	= 1424,
    VSUBUBM	= 1425,
    VSUBUBS	= 1426,
    VSUBUDM	= 1427,
    VSUBUHM	= 1428,
    VSUBUHS	= 1429,
    VSUBUQM	= 1430,
    VSUBUWM	= 1431,
    VSUBUWS	= 1432,
    VSUM2SWS	= 1433,
    VSUM4SBS	= 1434,
    VSUM4SHS	= 1435,
    VSUM4UBS	= 1436,
    VSUMSWS	= 1437,
    VUPKHPX	= 1438,
    VUPKHSB	= 1439,
    VUPKHSH	= 1440,
    VUPKHSW	= 1441,
    VUPKLPX	= 1442,
    VUPKLSB	= 1443,
    VUPKLSH	= 1444,
    VUPKLSW	= 1445,
    VXOR	= 1446,
    V_SET0	= 1447,
    V_SET0B	= 1448,
    V_SET0H	= 1449,
    V_SETALLONES	= 1450,
    V_SETALLONESB	= 1451,
    V_SETALLONESH	= 1452,
    WAIT	= 1453,
    WRTEE	= 1454,
    WRTEEI	= 1455,
    XOR	= 1456,
    XOR8	= 1457,
    XOR8o	= 1458,
    XORI	= 1459,
    XORI8	= 1460,
    XORIS	= 1461,
    XORIS8	= 1462,
    XORo	= 1463,
    XSABSDP	= 1464,
    XSADDDP	= 1465,
    XSADDSP	= 1466,
    XSCMPODP	= 1467,
    XSCMPUDP	= 1468,
    XSCPSGNDP	= 1469,
    XSCVDPSP	= 1470,
    XSCVDPSPN	= 1471,
    XSCVDPSXDS	= 1472,
    XSCVDPSXWS	= 1473,
    XSCVDPUXDS	= 1474,
    XSCVDPUXWS	= 1475,
    XSCVSPDP	= 1476,
    XSCVSPDPN	= 1477,
    XSCVSXDDP	= 1478,
    XSCVSXDSP	= 1479,
    XSCVUXDDP	= 1480,
    XSCVUXDSP	= 1481,
    XSDIVDP	= 1482,
    XSDIVSP	= 1483,
    XSMADDADP	= 1484,
    XSMADDASP	= 1485,
    XSMADDMDP	= 1486,
    XSMADDMSP	= 1487,
    XSMAXDP	= 1488,
    XSMINDP	= 1489,
    XSMSUBADP	= 1490,
    XSMSUBASP	= 1491,
    XSMSUBMDP	= 1492,
    XSMSUBMSP	= 1493,
    XSMULDP	= 1494,
    XSMULSP	= 1495,
    XSNABSDP	= 1496,
    XSNEGDP	= 1497,
    XSNMADDADP	= 1498,
    XSNMADDASP	= 1499,
    XSNMADDMDP	= 1500,
    XSNMADDMSP	= 1501,
    XSNMSUBADP	= 1502,
    XSNMSUBASP	= 1503,
    XSNMSUBMDP	= 1504,
    XSNMSUBMSP	= 1505,
    XSRDPI	= 1506,
    XSRDPIC	= 1507,
    XSRDPIM	= 1508,
    XSRDPIP	= 1509,
    XSRDPIZ	= 1510,
    XSREDP	= 1511,
    XSRESP	= 1512,
    XSRSQRTEDP	= 1513,
    XSRSQRTESP	= 1514,
    XSSQRTDP	= 1515,
    XSSQRTSP	= 1516,
    XSSUBDP	= 1517,
    XSSUBSP	= 1518,
    XSTDIVDP	= 1519,
    XSTSQRTDP	= 1520,
    XVABSDP	= 1521,
    XVABSSP	= 1522,
    XVADDDP	= 1523,
    XVADDSP	= 1524,
    XVCMPEQDP	= 1525,
    XVCMPEQDPo	= 1526,
    XVCMPEQSP	= 1527,
    XVCMPEQSPo	= 1528,
    XVCMPGEDP	= 1529,
    XVCMPGEDPo	= 1530,
    XVCMPGESP	= 1531,
    XVCMPGESPo	= 1532,
    XVCMPGTDP	= 1533,
    XVCMPGTDPo	= 1534,
    XVCMPGTSP	= 1535,
    XVCMPGTSPo	= 1536,
    XVCPSGNDP	= 1537,
    XVCPSGNSP	= 1538,
    XVCVDPSP	= 1539,
    XVCVDPSXDS	= 1540,
    XVCVDPSXWS	= 1541,
    XVCVDPUXDS	= 1542,
    XVCVDPUXWS	= 1543,
    XVCVSPDP	= 1544,
    XVCVSPSXDS	= 1545,
    XVCVSPSXWS	= 1546,
    XVCVSPUXDS	= 1547,
    XVCVSPUXWS	= 1548,
    XVCVSXDDP	= 1549,
    XVCVSXDSP	= 1550,
    XVCVSXWDP	= 1551,
    XVCVSXWSP	= 1552,
    XVCVUXDDP	= 1553,
    XVCVUXDSP	= 1554,
    XVCVUXWDP	= 1555,
    XVCVUXWSP	= 1556,
    XVDIVDP	= 1557,
    XVDIVSP	= 1558,
    XVMADDADP	= 1559,
    XVMADDASP	= 1560,
    XVMADDMDP	= 1561,
    XVMADDMSP	= 1562,
    XVMAXDP	= 1563,
    XVMAXSP	= 1564,
    XVMINDP	= 1565,
    XVMINSP	= 1566,
    XVMSUBADP	= 1567,
    XVMSUBASP	= 1568,
    XVMSUBMDP	= 1569,
    XVMSUBMSP	= 1570,
    XVMULDP	= 1571,
    XVMULSP	= 1572,
    XVNABSDP	= 1573,
    XVNABSSP	= 1574,
    XVNEGDP	= 1575,
    XVNEGSP	= 1576,
    XVNMADDADP	= 1577,
    XVNMADDASP	= 1578,
    XVNMADDMDP	= 1579,
    XVNMADDMSP	= 1580,
    XVNMSUBADP	= 1581,
    XVNMSUBASP	= 1582,
    XVNMSUBMDP	= 1583,
    XVNMSUBMSP	= 1584,
    XVRDPI	= 1585,
    XVRDPIC	= 1586,
    XVRDPIM	= 1587,
    XVRDPIP	= 1588,
    XVRDPIZ	= 1589,
    XVREDP	= 1590,
    XVRESP	= 1591,
    XVRSPI	= 1592,
    XVRSPIC	= 1593,
    XVRSPIM	= 1594,
    XVRSPIP	= 1595,
    XVRSPIZ	= 1596,
    XVRSQRTEDP	= 1597,
    XVRSQRTESP	= 1598,
    XVSQRTDP	= 1599,
    XVSQRTSP	= 1600,
    XVSUBDP	= 1601,
    XVSUBSP	= 1602,
    XVTDIVDP	= 1603,
    XVTDIVSP	= 1604,
    XVTSQRTDP	= 1605,
    XVTSQRTSP	= 1606,
    XXLAND	= 1607,
    XXLANDC	= 1608,
    XXLEQV	= 1609,
    XXLNAND	= 1610,
    XXLNOR	= 1611,
    XXLOR	= 1612,
    XXLORC	= 1613,
    XXLORf	= 1614,
    XXLXOR	= 1615,
    XXMRGHW	= 1616,
    XXMRGLW	= 1617,
    XXPERMDI	= 1618,
    XXSEL	= 1619,
    XXSLDWI	= 1620,
    XXSPLTW	= 1621,
    gBC	= 1622,
    gBCA	= 1623,
    gBCCTR	= 1624,
    gBCCTRL	= 1625,
    gBCL	= 1626,
    gBCLA	= 1627,
    gBCLR	= 1628,
    gBCLRL	= 1629,
    INSTRUCTION_LIST_END = 1630
  };

namespace Sched {
  enum {
    NoInstrModel	= 0,
    IIC_IntSimple	= 1,
    IIC_IntGeneral	= 2,
    IIC_BrB	= 3,
    IIC_VecFP	= 4,
    IIC_IntCompare	= 5,
    IIC_BrCR	= 6,
    IIC_LdStDCBF	= 7,
    IIC_LdStLoad	= 8,
    IIC_IntDivD	= 9,
    IIC_IntDivW	= 10,
    IIC_FPGeneral	= 11,
    IIC_FPAddSub	= 12,
    IIC_FPCompare	= 13,
    IIC_FPDivD	= 14,
    IIC_FPDivS	= 15,
    IIC_FPFused	= 16,
    IIC_FPSqrtD	= 17,
    IIC_FPSqrtS	= 18,
    IIC_LdStICBI	= 19,
    IIC_IntISEL	= 20,
    IIC_SprISYNC	= 21,
    IIC_LdStLWARX	= 22,
    IIC_LdStLoadUpd	= 23,
    IIC_LdStLoadUpdX	= 24,
    IIC_LdStLD	= 25,
    IIC_LdStLDARX	= 26,
    IIC_LdStLDU	= 27,
    IIC_LdStLDUX	= 28,
    IIC_LdStLFD	= 29,
    IIC_LdStLFDU	= 30,
    IIC_LdStLFDUX	= 31,
    IIC_LdStLHA	= 32,
    IIC_LdStLHAU	= 33,
    IIC_LdStLHAUX	= 34,
    IIC_LdStLMW	= 35,
    IIC_LdStLWA	= 36,
    IIC_BrMCR	= 37,
    IIC_SprMFCR	= 38,
    IIC_SprMFSPR	= 39,
    IIC_IntMFFS	= 40,
    IIC_SprMFMSR	= 41,
    IIC_SprMFCRF	= 42,
    IIC_SprMFSR	= 43,
    IIC_SprMFTB	= 44,
    IIC_LdStStore	= 45,
    IIC_VecGeneral	= 46,
    IIC_LdStSync	= 47,
    IIC_BrMCRX	= 48,
    IIC_SprMTSPR	= 49,
    IIC_IntMTFSB0	= 50,
    IIC_SprMTMSR	= 51,
    IIC_SprMTMSRD	= 52,
    IIC_SprMTSR	= 53,
    IIC_IntMulHW	= 54,
    IIC_IntMulHWU	= 55,
    IIC_IntMulHD	= 56,
    IIC_IntMulLI	= 57,
    IIC_VecPerm	= 58,
    IIC_LdStSTFD	= 59,
    IIC_LdStSTFDU	= 60,
    IIC_SprRFI	= 61,
    IIC_IntRFID	= 62,
    IIC_IntRotateD	= 63,
    IIC_IntRotateDI	= 64,
    IIC_IntRotate	= 65,
    IIC_SprSLBIA	= 66,
    IIC_SprSLBIE	= 67,
    IIC_SprSLBMFEE	= 68,
    IIC_SprSLBMTE	= 69,
    IIC_IntShift	= 70,
    IIC_LdStSTWCX	= 71,
    IIC_LdStStoreUpd	= 72,
    IIC_LdStSTD	= 73,
    IIC_LdStSTDCX	= 74,
    IIC_LdStSTDU	= 75,
    IIC_LdStSTDUX	= 76,
    IIC_IntTrapD	= 77,
    IIC_SprTLBIA	= 78,
    IIC_SprTLBIE	= 79,
    IIC_SprTLBIEL	= 80,
    IIC_SprTLBSYNC	= 81,
    IIC_IntTrapW	= 82,
    IIC_VecFPCompare	= 83,
    SCHED_LIST_END = 84
  };
} // end Sched namespace
} // end PPC namespace
} // end llvm namespace 
#endif // GET_INSTRINFO_ENUM

/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Target Instruction Descriptors                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/


#ifdef GET_INSTRINFO_MC_DESC
#undef GET_INSTRINFO_MC_DESC
namespace llvm {

static const uint16_t ImplicitList1[] = { PPC::CR0, 0 };
static const uint16_t ImplicitList2[] = { PPC::CARRY, 0 };
static const uint16_t ImplicitList3[] = { PPC::CARRY, PPC::CR0, 0 };
static const uint16_t ImplicitList4[] = { PPC::X0, PPC::X3, PPC::X4, PPC::X5, PPC::X6, PPC::X7, PPC::X8, PPC::X9, PPC::X10, PPC::X11, PPC::X12, PPC::LR8, PPC::CTR8, PPC::CR0, PPC::CR1, PPC::CR5, PPC::CR6, PPC::CR7, 0 };
static const uint16_t ImplicitList5[] = { PPC::R0, PPC::R3, PPC::R4, PPC::R5, PPC::R6, PPC::R7, PPC::R8, PPC::R9, PPC::R10, PPC::R11, PPC::R12, PPC::LR, PPC::CTR, PPC::CR0, PPC::CR1, PPC::CR5, PPC::CR6, PPC::CR7, 0 };
static const uint16_t ImplicitList6[] = { PPC::R1, 0 };
static const uint16_t ImplicitList7[] = { PPC::CTR, 0 };
static const uint16_t ImplicitList8[] = { PPC::CTR8, 0 };
static const uint16_t ImplicitList9[] = { PPC::CTR, PPC::RM, 0 };
static const uint16_t ImplicitList10[] = { PPC::LR, 0 };
static const uint16_t ImplicitList11[] = { PPC::CTR8, PPC::RM, 0 };
static const uint16_t ImplicitList12[] = { PPC::LR8, 0 };
static const uint16_t ImplicitList13[] = { PPC::RM, 0 };
static const uint16_t ImplicitList14[] = { PPC::LR, PPC::RM, 0 };
static const uint16_t ImplicitList15[] = { PPC::LR8, PPC::X2, 0 };
static const uint16_t ImplicitList16[] = { PPC::CTR, PPC::LR, PPC::RM, 0 };
static const uint16_t ImplicitList17[] = { PPC::CTR8, PPC::LR8, PPC::RM, 0 };
static const uint16_t ImplicitList18[] = { PPC::LR8, PPC::RM, 0 };
static const uint16_t ImplicitList19[] = { PPC::CR1EQ, 0 };
static const uint16_t ImplicitList20[] = { PPC::X1, 0 };
static const uint16_t ImplicitList21[] = { PPC::CR1, 0 };
static const uint16_t ImplicitList22[] = { PPC::X0, PPC::X4, PPC::X5, PPC::X6, PPC::X7, PPC::X8, PPC::X9, PPC::X10, PPC::X11, PPC::X12, PPC::LR8, PPC::CTR8, PPC::CR0, PPC::CR1, PPC::CR5, PPC::CR6, PPC::CR7, 0 };
static const uint16_t ImplicitList23[] = { PPC::R0, PPC::R4, PPC::R5, PPC::R6, PPC::R7, PPC::R8, PPC::R9, PPC::R10, PPC::R11, PPC::R12, PPC::LR, PPC::CTR, PPC::CR0, PPC::CR1, PPC::CR5, PPC::CR6, PPC::CR7, 0 };
static const uint16_t ImplicitList24[] = { PPC::CR6, 0 };
static const uint16_t ImplicitList25[] = { PPC::LR, PPC::CTR, 0 };

static const MCOperandInfo OperandInfo2[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo3[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo4[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo5[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo6[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo7[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo8[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo9[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo10[] = { { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo11[] = { { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo12[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo13[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo14[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo15[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo16[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRC_NOR0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo17[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RC_NOX0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo18[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RC_NOX0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo19[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRC_NOR0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo20[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo21[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo22[] = { { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo23[] = { { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo24[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo25[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo26[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo27[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo28[] = { { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo29[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo30[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo31[] = { { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo32[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo33[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo34[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo35[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo36[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo37[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo38[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo39[] = { { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo40[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo41[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo42[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo43[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo44[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo45[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo46[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo47[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo48[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo49[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo50[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo51[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo52[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo53[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo54[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo55[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo56[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo57[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo58[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo59[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo60[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo61[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo62[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo63[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRC_NOR0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo64[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RC_NOX0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo65[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo66[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo67[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo68[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo69[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo70[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo71[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo72[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RC_NOX0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo73[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRC_NOR0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo74[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo75[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo76[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo77[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo78[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo79[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo80[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo81[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo82[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo83[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo84[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo85[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo86[] = { { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo87[] = { { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo88[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo89[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo90[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo91[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo92[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo93[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo94[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo95[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRSAVERCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo96[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo97[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo98[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo99[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo100[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo101[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo102[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo103[] = { { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo104[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo105[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo106[] = { { PPC::VRSAVERCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo107[] = { { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo108[] = { { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo109[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo110[] = { { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo111[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo112[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo113[] = { { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo114[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo115[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo116[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo117[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo118[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo119[] = { { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo120[] = { { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo121[] = { { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo122[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo123[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo124[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo125[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo126[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo127[] = { { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo128[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo129[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo130[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo131[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo132[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo133[] = { { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo134[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((1 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo135[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo136[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo137[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo138[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo139[] = { { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo140[] = { { PPC::VRSAVERCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo141[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo142[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo143[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo144[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo145[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo146[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo147[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo148[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo149[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo150[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo151[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo152[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo153[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRC_NOR0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRC_NOR0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo154[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RC_NOX0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RC_NOX0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo155[] = { { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo156[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo157[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo158[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo159[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo160[] = { { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo161[] = { { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo162[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRC_NOR0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRC_NOR0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo163[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RC_NOX0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RC_NOX0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo164[] = { { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QBRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo165[] = { { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo166[] = { { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::QSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo167[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo168[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo169[] = { { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo170[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo171[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo172[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo173[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo174[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo175[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::F8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo176[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, };
static const MCOperandInfo OperandInfo177[] = { { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, { PPC::F4RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { 1, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { 0, 0|(1<<MCOI::LookupPtrRegClass), MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo178[] = { { PPC::CRRC0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo179[] = { { PPC::CRRC0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo180[] = { { PPC::CRRC0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo181[] = { { PPC::CRRC0RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo182[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo183[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo184[] = { { PPC::CTRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo185[] = { { PPC::CTRRC8RegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo186[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo187[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::G8RCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo188[] = { { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };
static const MCOperandInfo OperandInfo189[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo190[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::GPRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo191[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo192[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo193[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo194[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo195[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo196[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo197[] = { { PPC::VRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo198[] = { { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo199[] = { { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo200[] = { { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo201[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo202[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo203[] = { { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo204[] = { { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo205[] = { { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo206[] = { { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo207[] = { { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo208[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSFRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo209[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo210[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo211[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, ((0 << 16) | (1 << MCOI::TIED_TO)) }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo212[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo213[] = { { PPC::CRRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo214[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo215[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, };
static const MCOperandInfo OperandInfo216[] = { { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { PPC::VSRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo217[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, };
static const MCOperandInfo OperandInfo218[] = { { -1, 0, MCOI::OPERAND_UNKNOWN, 0 }, { PPC::CRBITRCRegClassID, 0, MCOI::OPERAND_REGISTER, 0 }, { -1, 0, MCOI::OPERAND_IMMEDIATE, 0 }, };

extern const MCInstrDesc PPCInsts[] = {
  { 0,	0,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #0 = PHI
  { 1,	0,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #1 = INLINEASM
  { 2,	1,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::NotDuplicable)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo2, -1 ,nullptr },  // Inst #2 = CFI_INSTRUCTION
  { 3,	1,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::NotDuplicable)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo2, -1 ,nullptr },  // Inst #3 = EH_LABEL
  { 4,	1,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::NotDuplicable)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo2, -1 ,nullptr },  // Inst #4 = GC_LABEL
  { 5,	0,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #5 = KILL
  { 6,	3,	1,	0,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL, nullptr, nullptr, OperandInfo3, -1 ,nullptr },  // Inst #6 = EXTRACT_SUBREG
  { 7,	4,	1,	0,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL, nullptr, nullptr, OperandInfo4, -1 ,nullptr },  // Inst #7 = INSERT_SUBREG
  { 8,	1,	1,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove), 0x0ULL, nullptr, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #8 = IMPLICIT_DEF
  { 9,	4,	1,	0,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL, nullptr, nullptr, OperandInfo6, -1 ,nullptr },  // Inst #9 = SUBREG_TO_REG
  { 10,	3,	1,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::CheapAsAMove), 0x0ULL, nullptr, nullptr, OperandInfo3, -1 ,nullptr },  // Inst #10 = COPY_TO_REGCLASS
  { 11,	0,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #11 = DBG_VALUE
  { 12,	2,	1,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::CheapAsAMove), 0x0ULL, nullptr, nullptr, OperandInfo7, -1 ,nullptr },  // Inst #12 = REG_SEQUENCE
  { 13,	2,	1,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::CheapAsAMove), 0x0ULL, nullptr, nullptr, OperandInfo7, -1 ,nullptr },  // Inst #13 = COPY
  { 14,	0,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #14 = BUNDLE
  { 15,	1,	0,	0,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL, nullptr, nullptr, OperandInfo2, -1 ,nullptr },  // Inst #15 = LIFETIME_START
  { 16,	1,	0,	0,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL, nullptr, nullptr, OperandInfo2, -1 ,nullptr },  // Inst #16 = LIFETIME_END
  { 17,	2,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo8, -1 ,nullptr },  // Inst #17 = STACKMAP
  { 18,	6,	1,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo9, -1 ,nullptr },  // Inst #18 = PATCHPOINT
  { 19,	1,	1,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::Rematerializable), 0x0ULL, nullptr, nullptr, OperandInfo10, -1 ,nullptr },  // Inst #19 = LOAD_STACK_GUARD
  { 20,	0,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::Call)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #20 = STATEPOINT
  { 21,	2,	0,	0,	0,	0|(1ULL<<MCID::Pseudo), 0x0ULL, nullptr, nullptr, OperandInfo11, -1 ,nullptr },  // Inst #21 = LOCAL_ESCAPE
  { 22,	1,	1,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::Variadic)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #22 = FAULTING_LOAD_OP
  { 23,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #23 = ADD4
  { 24,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #24 = ADD4TLS
  { 25,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #25 = ADD4o
  { 26,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #26 = ADD8
  { 27,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #27 = ADD8TLS
  { 28,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #28 = ADD8TLS_
  { 29,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #29 = ADD8o
  { 30,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0xcULL, nullptr, ImplicitList2, OperandInfo12, -1 ,nullptr },  // Inst #30 = ADDC
  { 31,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0xcULL, nullptr, ImplicitList2, OperandInfo14, -1 ,nullptr },  // Inst #31 = ADDC8
  { 32,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0xcULL, nullptr, ImplicitList3, OperandInfo14, -1 ,nullptr },  // Inst #32 = ADDC8o
  { 33,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0xcULL, nullptr, ImplicitList3, OperandInfo12, -1 ,nullptr },  // Inst #33 = ADDCo
  { 34,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo12, -1 ,nullptr },  // Inst #34 = ADDE
  { 35,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo14, -1 ,nullptr },  // Inst #35 = ADDE8
  { 36,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo14, -1 ,nullptr },  // Inst #36 = ADDE8o
  { 37,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo12, -1 ,nullptr },  // Inst #37 = ADDEo
  { 38,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo16, -1 ,nullptr },  // Inst #38 = ADDI
  { 39,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #39 = ADDI8
  { 40,	3,	1,	4,	2,	0, 0xcULL, nullptr, ImplicitList2, OperandInfo13, -1 ,nullptr },  // Inst #40 = ADDIC
  { 41,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList2, OperandInfo15, -1 ,nullptr },  // Inst #41 = ADDIC8
  { 42,	3,	1,	4,	2,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x8ULL, nullptr, ImplicitList3, OperandInfo13, -1 ,nullptr },  // Inst #42 = ADDICo
  { 43,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo16, -1 ,nullptr },  // Inst #43 = ADDIS
  { 44,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #44 = ADDIS8
  { 45,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #45 = ADDISdtprelHA
  { 46,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo16, -1 ,nullptr },  // Inst #46 = ADDISdtprelHA32
  { 47,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #47 = ADDISgotTprelHA
  { 48,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #48 = ADDIStlsgdHA
  { 49,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #49 = ADDIStlsldHA
  { 50,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #50 = ADDIStocHA
  { 51,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #51 = ADDIdtprelL
  { 52,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo16, -1 ,nullptr },  // Inst #52 = ADDIdtprelL32
  { 53,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #53 = ADDItlsgdL
  { 54,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo16, -1 ,nullptr },  // Inst #54 = ADDItlsgdL32
  { 55,	4,	1,	4,	0,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL, nullptr, ImplicitList4, OperandInfo18, -1 ,nullptr },  // Inst #55 = ADDItlsgdLADDR
  { 56,	4,	1,	4,	0,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL, nullptr, ImplicitList5, OperandInfo19, -1 ,nullptr },  // Inst #56 = ADDItlsgdLADDR32
  { 57,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #57 = ADDItlsldL
  { 58,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo16, -1 ,nullptr },  // Inst #58 = ADDItlsldL32
  { 59,	4,	1,	4,	0,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL, nullptr, ImplicitList4, OperandInfo18, -1 ,nullptr },  // Inst #59 = ADDItlsldLADDR
  { 60,	4,	1,	4,	0,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL, nullptr, ImplicitList5, OperandInfo19, -1 ,nullptr },  // Inst #60 = ADDItlsldLADDR32
  { 61,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo17, -1 ,nullptr },  // Inst #61 = ADDItocL
  { 62,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo20, -1 ,nullptr },  // Inst #62 = ADDME
  { 63,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo21, -1 ,nullptr },  // Inst #63 = ADDME8
  { 64,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo21, -1 ,nullptr },  // Inst #64 = ADDME8o
  { 65,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo20, -1 ,nullptr },  // Inst #65 = ADDMEo
  { 66,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo20, -1 ,nullptr },  // Inst #66 = ADDZE
  { 67,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo21, -1 ,nullptr },  // Inst #67 = ADDZE8
  { 68,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo21, -1 ,nullptr },  // Inst #68 = ADDZE8o
  { 69,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo20, -1 ,nullptr },  // Inst #69 = ADDZEo
  { 70,	1,	0,	4,	0,	0, 0x0ULL, ImplicitList6, ImplicitList6, OperandInfo5, -1 ,nullptr },  // Inst #70 = ADJCALLSTACKDOWN
  { 71,	2,	0,	4,	0,	0, 0x0ULL, ImplicitList6, ImplicitList6, OperandInfo7, -1 ,nullptr },  // Inst #71 = ADJCALLSTACKUP
  { 72,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #72 = AND
  { 73,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #73 = AND8
  { 74,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #74 = AND8o
  { 75,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #75 = ANDC
  { 76,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #76 = ANDC8
  { 77,	3,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #77 = ANDC8o
  { 78,	3,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #78 = ANDCo
  { 79,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo13, -1 ,nullptr },  // Inst #79 = ANDISo
  { 80,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo15, -1 ,nullptr },  // Inst #80 = ANDISo8
  { 81,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo13, -1 ,nullptr },  // Inst #81 = ANDIo
  { 82,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo15, -1 ,nullptr },  // Inst #82 = ANDIo8
  { 83,	2,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, nullptr, OperandInfo22, -1 ,nullptr },  // Inst #83 = ANDIo_1_EQ_BIT
  { 84,	2,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, nullptr, OperandInfo23, -1 ,nullptr },  // Inst #84 = ANDIo_1_EQ_BIT8
  { 85,	2,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, nullptr, OperandInfo22, -1 ,nullptr },  // Inst #85 = ANDIo_1_GT_BIT
  { 86,	2,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, nullptr, OperandInfo23, -1 ,nullptr },  // Inst #86 = ANDIo_1_GT_BIT8
  { 87,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #87 = ANDo
  { 88,	5,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo24, -1 ,nullptr },  // Inst #88 = ATOMIC_CMP_SWAP_I16
  { 89,	5,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo24, -1 ,nullptr },  // Inst #89 = ATOMIC_CMP_SWAP_I32
  { 90,	5,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo25, -1 ,nullptr },  // Inst #90 = ATOMIC_CMP_SWAP_I64
  { 91,	5,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo24, -1 ,nullptr },  // Inst #91 = ATOMIC_CMP_SWAP_I8
  { 92,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #92 = ATOMIC_LOAD_ADD_I16
  { 93,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #93 = ATOMIC_LOAD_ADD_I32
  { 94,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo27, -1 ,nullptr },  // Inst #94 = ATOMIC_LOAD_ADD_I64
  { 95,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #95 = ATOMIC_LOAD_ADD_I8
  { 96,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #96 = ATOMIC_LOAD_AND_I16
  { 97,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #97 = ATOMIC_LOAD_AND_I32
  { 98,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo27, -1 ,nullptr },  // Inst #98 = ATOMIC_LOAD_AND_I64
  { 99,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #99 = ATOMIC_LOAD_AND_I8
  { 100,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #100 = ATOMIC_LOAD_NAND_I16
  { 101,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #101 = ATOMIC_LOAD_NAND_I32
  { 102,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo27, -1 ,nullptr },  // Inst #102 = ATOMIC_LOAD_NAND_I64
  { 103,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #103 = ATOMIC_LOAD_NAND_I8
  { 104,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #104 = ATOMIC_LOAD_OR_I16
  { 105,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #105 = ATOMIC_LOAD_OR_I32
  { 106,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo27, -1 ,nullptr },  // Inst #106 = ATOMIC_LOAD_OR_I64
  { 107,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #107 = ATOMIC_LOAD_OR_I8
  { 108,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #108 = ATOMIC_LOAD_SUB_I16
  { 109,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #109 = ATOMIC_LOAD_SUB_I32
  { 110,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo27, -1 ,nullptr },  // Inst #110 = ATOMIC_LOAD_SUB_I64
  { 111,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #111 = ATOMIC_LOAD_SUB_I8
  { 112,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #112 = ATOMIC_LOAD_XOR_I16
  { 113,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #113 = ATOMIC_LOAD_XOR_I32
  { 114,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo27, -1 ,nullptr },  // Inst #114 = ATOMIC_LOAD_XOR_I64
  { 115,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #115 = ATOMIC_LOAD_XOR_I8
  { 116,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #116 = ATOMIC_SWAP_I16
  { 117,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #117 = ATOMIC_SWAP_I32
  { 118,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo27, -1 ,nullptr },  // Inst #118 = ATOMIC_SWAP_I64
  { 119,	4,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, nullptr, ImplicitList1, OperandInfo26, -1 ,nullptr },  // Inst #119 = ATOMIC_SWAP_I8
  { 120,	0,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #120 = ATTN
  { 121,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator), 0x38ULL, nullptr, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #121 = B
  { 122,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, nullptr, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #122 = BA
  { 123,	2,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator), 0x38ULL, nullptr, nullptr, OperandInfo28, -1 ,nullptr },  // Inst #123 = BC
  { 124,	3,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, nullptr, nullptr, OperandInfo29, -1 ,nullptr },  // Inst #124 = BCC
  { 125,	3,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, nullptr, nullptr, OperandInfo29, -1 ,nullptr },  // Inst #125 = BCCA
  { 126,	2,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, nullptr, OperandInfo30, -1 ,nullptr },  // Inst #126 = BCCCTR
  { 127,	2,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList8, nullptr, OperandInfo30, -1 ,nullptr },  // Inst #127 = BCCCTR8
  { 128,	2,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList10, OperandInfo30, -1 ,nullptr },  // Inst #128 = BCCCTRL
  { 129,	2,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList11, ImplicitList12, OperandInfo30, -1 ,nullptr },  // Inst #129 = BCCCTRL8
  { 130,	3,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, ImplicitList10, OperandInfo29, -1 ,nullptr },  // Inst #130 = BCCL
  { 131,	3,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, ImplicitList10, OperandInfo29, -1 ,nullptr },  // Inst #131 = BCCLA
  { 132,	2,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList14, nullptr, OperandInfo30, -1 ,nullptr },  // Inst #132 = BCCLR
  { 133,	2,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList14, ImplicitList10, OperandInfo30, -1 ,nullptr },  // Inst #133 = BCCLRL
  { 134,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, nullptr, OperandInfo31, -1 ,nullptr },  // Inst #134 = BCCTR
  { 135,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList8, nullptr, OperandInfo31, -1 ,nullptr },  // Inst #135 = BCCTR8
  { 136,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList8, nullptr, OperandInfo31, -1 ,nullptr },  // Inst #136 = BCCTR8n
  { 137,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList10, OperandInfo31, -1 ,nullptr },  // Inst #137 = BCCTRL
  { 138,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList11, ImplicitList12, OperandInfo31, -1 ,nullptr },  // Inst #138 = BCCTRL8
  { 139,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList11, ImplicitList12, OperandInfo31, -1 ,nullptr },  // Inst #139 = BCCTRL8n
  { 140,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList10, OperandInfo31, -1 ,nullptr },  // Inst #140 = BCCTRLn
  { 141,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, nullptr, OperandInfo31, -1 ,nullptr },  // Inst #141 = BCCTRn
  { 142,	2,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, ImplicitList10, OperandInfo28, -1 ,nullptr },  // Inst #142 = BCL
  { 143,	1,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList14, nullptr, OperandInfo31, -1 ,nullptr },  // Inst #143 = BCLR
  { 144,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList14, ImplicitList10, OperandInfo31, -1 ,nullptr },  // Inst #144 = BCLRL
  { 145,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList14, ImplicitList10, OperandInfo31, -1 ,nullptr },  // Inst #145 = BCLRLn
  { 146,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, nullptr, nullptr, OperandInfo31, -1 ,nullptr },  // Inst #146 = BCLRn
  { 147,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, ImplicitList10, OperandInfo5, -1 ,nullptr },  // Inst #147 = BCLalways
  { 148,	2,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, ImplicitList10, OperandInfo28, -1 ,nullptr },  // Inst #148 = BCLn
  { 149,	0,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, nullptr, nullptr, -1 ,nullptr },  // Inst #149 = BCTR
  { 150,	0,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList8, nullptr, nullptr, -1 ,nullptr },  // Inst #150 = BCTR8
  { 151,	0,	0,	4,	3,	0|(1ULL<<MCID::Call), 0x38ULL, ImplicitList9, ImplicitList10, nullptr, -1 ,nullptr },  // Inst #151 = BCTRL
  { 152,	0,	0,	4,	3,	0|(1ULL<<MCID::Call), 0x38ULL, ImplicitList11, ImplicitList12, nullptr, -1 ,nullptr },  // Inst #152 = BCTRL8
  { 153,	2,	0,	8,	3,	0|(1ULL<<MCID::Call), 0x38ULL, ImplicitList11, ImplicitList15, OperandInfo32, -1 ,nullptr },  // Inst #153 = BCTRL8_LDinto_toc
  { 154,	2,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator), 0x38ULL, nullptr, nullptr, OperandInfo28, -1 ,nullptr },  // Inst #154 = BCn
  { 155,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #155 = BDNZ
  { 156,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList8, ImplicitList8, OperandInfo5, -1 ,nullptr },  // Inst #156 = BDNZ8
  { 157,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #157 = BDNZA
  { 158,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #158 = BDNZAm
  { 159,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #159 = BDNZAp
  { 160,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #160 = BDNZL
  { 161,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #161 = BDNZLA
  { 162,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #162 = BDNZLAm
  { 163,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #163 = BDNZLAp
  { 164,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #164 = BDNZLR
  { 165,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList17, ImplicitList8, nullptr, -1 ,nullptr },  // Inst #165 = BDNZLR8
  { 166,	0,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #166 = BDNZLRL
  { 167,	0,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #167 = BDNZLRLm
  { 168,	0,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #168 = BDNZLRLp
  { 169,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #169 = BDNZLRm
  { 170,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #170 = BDNZLRp
  { 171,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #171 = BDNZLm
  { 172,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #172 = BDNZLp
  { 173,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #173 = BDNZm
  { 174,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #174 = BDNZp
  { 175,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #175 = BDZ
  { 176,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList8, ImplicitList8, OperandInfo5, -1 ,nullptr },  // Inst #176 = BDZ8
  { 177,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #177 = BDZA
  { 178,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #178 = BDZAm
  { 179,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #179 = BDZAp
  { 180,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #180 = BDZL
  { 181,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #181 = BDZLA
  { 182,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #182 = BDZLAm
  { 183,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #183 = BDZLAp
  { 184,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #184 = BDZLR
  { 185,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList17, ImplicitList8, nullptr, -1 ,nullptr },  // Inst #185 = BDZLR8
  { 186,	0,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #186 = BDZLRL
  { 187,	0,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #187 = BDZLRLm
  { 188,	0,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #188 = BDZLRLp
  { 189,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #189 = BDZLRm
  { 190,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, nullptr, -1 ,nullptr },  // Inst #190 = BDZLRp
  { 191,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #191 = BDZLm
  { 192,	1,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #192 = BDZLp
  { 193,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #193 = BDZm
  { 194,	1,	0,	4,	3,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList7, ImplicitList7, OperandInfo5, -1 ,nullptr },  // Inst #194 = BDZp
  { 195,	1,	0,	4,	3,	0|(1ULL<<MCID::Call), 0x38ULL, ImplicitList13, ImplicitList10, OperandInfo5, -1 ,nullptr },  // Inst #195 = BL
  { 196,	1,	0,	4,	3,	0|(1ULL<<MCID::Call), 0x38ULL, ImplicitList13, ImplicitList12, OperandInfo5, -1 ,nullptr },  // Inst #196 = BL8
  { 197,	1,	0,	8,	3,	0|(1ULL<<MCID::Call), 0x38ULL, ImplicitList13, ImplicitList12, OperandInfo5, -1 ,nullptr },  // Inst #197 = BL8_NOP
  { 198,	2,	0,	8,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, ImplicitList12, OperandInfo7, -1 ,nullptr },  // Inst #198 = BL8_NOP_TLS
  { 199,	2,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, ImplicitList12, OperandInfo7, -1 ,nullptr },  // Inst #199 = BL8_TLS
  { 200,	2,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, ImplicitList12, OperandInfo7, -1 ,nullptr },  // Inst #200 = BL8_TLS_
  { 201,	1,	0,	4,	3,	0|(1ULL<<MCID::Call), 0x38ULL, ImplicitList13, ImplicitList10, OperandInfo5, -1 ,nullptr },  // Inst #201 = BLA
  { 202,	1,	0,	4,	3,	0|(1ULL<<MCID::Call), 0x38ULL, ImplicitList13, ImplicitList12, OperandInfo5, -1 ,nullptr },  // Inst #202 = BLA8
  { 203,	1,	0,	8,	3,	0|(1ULL<<MCID::Call), 0x38ULL, ImplicitList13, ImplicitList12, OperandInfo5, -1 ,nullptr },  // Inst #203 = BLA8_NOP
  { 204,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator), 0x38ULL, ImplicitList14, nullptr, nullptr, -1 ,nullptr },  // Inst #204 = BLR
  { 205,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator), 0x38ULL, ImplicitList18, nullptr, nullptr, -1 ,nullptr },  // Inst #205 = BLR8
  { 206,	0,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList14, ImplicitList10, nullptr, -1 ,nullptr },  // Inst #206 = BLRL
  { 207,	2,	0,	4,	3,	0|(1ULL<<MCID::Call)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, ImplicitList10, OperandInfo7, -1 ,nullptr },  // Inst #207 = BL_TLS
  { 208,	3,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #208 = BPERMD
  { 209,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #209 = BRINC
  { 210,	0,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #210 = CLRBHRB
  { 211,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #211 = CLRLSLDI
  { 212,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #212 = CLRLSLDIo
  { 213,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #213 = CLRLSLWI
  { 214,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #214 = CLRLSLWIo
  { 215,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #215 = CLRRDI
  { 216,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #216 = CLRRDIo
  { 217,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #217 = CLRRWI
  { 218,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #218 = CLRRWIo
  { 219,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #219 = CMPB
  { 220,	3,	1,	4,	2,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #220 = CMPB8
  { 221,	3,	1,	4,	5,	0|(1ULL<<MCID::Compare), 0x8ULL, nullptr, nullptr, OperandInfo35, -1 ,nullptr },  // Inst #221 = CMPD
  { 222,	3,	1,	4,	5,	0|(1ULL<<MCID::Compare), 0x8ULL, nullptr, nullptr, OperandInfo36, -1 ,nullptr },  // Inst #222 = CMPDI
  { 223,	3,	1,	4,	5,	0|(1ULL<<MCID::Compare), 0x8ULL, nullptr, nullptr, OperandInfo35, -1 ,nullptr },  // Inst #223 = CMPLD
  { 224,	3,	1,	4,	5,	0|(1ULL<<MCID::Compare), 0x8ULL, nullptr, nullptr, OperandInfo36, -1 ,nullptr },  // Inst #224 = CMPLDI
  { 225,	3,	1,	4,	5,	0|(1ULL<<MCID::Compare), 0x8ULL, nullptr, nullptr, OperandInfo37, -1 ,nullptr },  // Inst #225 = CMPLW
  { 226,	3,	1,	4,	5,	0|(1ULL<<MCID::Compare), 0x8ULL, nullptr, nullptr, OperandInfo38, -1 ,nullptr },  // Inst #226 = CMPLWI
  { 227,	3,	1,	4,	5,	0|(1ULL<<MCID::Compare), 0x8ULL, nullptr, nullptr, OperandInfo37, -1 ,nullptr },  // Inst #227 = CMPW
  { 228,	3,	1,	4,	5,	0|(1ULL<<MCID::Compare), 0x8ULL, nullptr, nullptr, OperandInfo38, -1 ,nullptr },  // Inst #228 = CMPWI
  { 229,	2,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo21, -1 ,nullptr },  // Inst #229 = CNTLZD
  { 230,	2,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo21, -1 ,nullptr },  // Inst #230 = CNTLZDo
  { 231,	2,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #231 = CNTLZW
  { 232,	2,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo21, -1 ,nullptr },  // Inst #232 = CNTLZW8
  { 233,	2,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo21, -1 ,nullptr },  // Inst #233 = CNTLZW8o
  { 234,	2,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo20, -1 ,nullptr },  // Inst #234 = CNTLZWo
  { 235,	0,	0,	4,	6,	0, 0x0ULL, nullptr, ImplicitList19, nullptr, -1 ,nullptr },  // Inst #235 = CR6SET
  { 236,	0,	0,	4,	6,	0, 0x0ULL, nullptr, ImplicitList19, nullptr, -1 ,nullptr },  // Inst #236 = CR6UNSET
  { 237,	3,	1,	4,	6,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo39, -1 ,nullptr },  // Inst #237 = CRAND
  { 238,	3,	1,	4,	6,	0, 0x0ULL, nullptr, nullptr, OperandInfo39, -1 ,nullptr },  // Inst #238 = CRANDC
  { 239,	3,	1,	4,	6,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo39, -1 ,nullptr },  // Inst #239 = CREQV
  { 240,	3,	1,	4,	6,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo39, -1 ,nullptr },  // Inst #240 = CRNAND
  { 241,	3,	1,	4,	6,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo39, -1 ,nullptr },  // Inst #241 = CRNOR
  { 242,	3,	1,	4,	6,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo39, -1 ,nullptr },  // Inst #242 = CROR
  { 243,	3,	1,	4,	6,	0, 0x0ULL, nullptr, nullptr, OperandInfo39, -1 ,nullptr },  // Inst #243 = CRORC
  { 244,	1,	1,	4,	6,	0, 0x0ULL, nullptr, nullptr, OperandInfo31, -1 ,nullptr },  // Inst #244 = CRSET
  { 245,	1,	1,	4,	6,	0, 0x0ULL, nullptr, nullptr, OperandInfo31, -1 ,nullptr },  // Inst #245 = CRUNSET
  { 246,	3,	1,	4,	6,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo39, -1 ,nullptr },  // Inst #246 = CRXOR
  { 247,	2,	0,	4,	7,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #247 = DCBA
  { 248,	2,	0,	4,	7,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #248 = DCBF
  { 249,	2,	0,	4,	7,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #249 = DCBI
  { 250,	2,	0,	4,	7,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #250 = DCBST
  { 251,	3,	0,	4,	7,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x2ULL, nullptr, nullptr, OperandInfo41, -1 ,nullptr },  // Inst #251 = DCBT
  { 252,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo42, -1 ,nullptr },  // Inst #252 = DCBTCT
  { 253,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo42, -1 ,nullptr },  // Inst #253 = DCBTDS
  { 254,	3,	0,	4,	7,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x2ULL, nullptr, nullptr, OperandInfo41, -1 ,nullptr },  // Inst #254 = DCBTST
  { 255,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo42, -1 ,nullptr },  // Inst #255 = DCBTSTCT
  { 256,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo42, -1 ,nullptr },  // Inst #256 = DCBTSTDS
  { 257,	2,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #257 = DCBTSTT
  { 258,	2,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #258 = DCBTSTx
  { 259,	2,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #259 = DCBTT
  { 260,	2,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #260 = DCBTx
  { 261,	2,	0,	4,	7,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #261 = DCBZ
  { 262,	2,	0,	4,	7,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #262 = DCBZL
  { 263,	2,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #263 = DCCCI
  { 264,	3,	1,	4,	9,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #264 = DIVD
  { 265,	3,	1,	4,	9,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #265 = DIVDE
  { 266,	3,	1,	4,	9,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #266 = DIVDEU
  { 267,	3,	1,	4,	9,	0, 0xdULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #267 = DIVDEUo
  { 268,	3,	1,	4,	9,	0, 0xdULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #268 = DIVDEo
  { 269,	3,	1,	4,	9,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #269 = DIVDU
  { 270,	3,	1,	4,	9,	0, 0xdULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #270 = DIVDUo
  { 271,	3,	1,	4,	9,	0, 0xdULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #271 = DIVDo
  { 272,	3,	1,	4,	10,	0, 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #272 = DIVW
  { 273,	3,	1,	4,	10,	0, 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #273 = DIVWE
  { 274,	3,	1,	4,	10,	0, 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #274 = DIVWEU
  { 275,	3,	1,	4,	10,	0, 0xdULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #275 = DIVWEUo
  { 276,	3,	1,	4,	10,	0, 0xdULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #276 = DIVWEo
  { 277,	3,	1,	4,	10,	0, 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #277 = DIVWU
  { 278,	3,	1,	4,	10,	0, 0xdULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #278 = DIVWUo
  { 279,	3,	1,	4,	10,	0, 0xdULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #279 = DIVWo
  { 280,	1,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo5, PPC::DeprecatedDST ,nullptr },  // Inst #280 = DSS
  { 281,	0,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, PPC::DeprecatedDST ,nullptr },  // Inst #281 = DSSALL
  { 282,	3,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo43, PPC::DeprecatedDST ,nullptr },  // Inst #282 = DST
  { 283,	3,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo44, PPC::DeprecatedDST ,nullptr },  // Inst #283 = DST64
  { 284,	3,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo43, PPC::DeprecatedDST ,nullptr },  // Inst #284 = DSTST
  { 285,	3,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo44, PPC::DeprecatedDST ,nullptr },  // Inst #285 = DSTST64
  { 286,	3,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo43, PPC::DeprecatedDST ,nullptr },  // Inst #286 = DSTSTT
  { 287,	3,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo44, PPC::DeprecatedDST ,nullptr },  // Inst #287 = DSTSTT64
  { 288,	3,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo43, PPC::DeprecatedDST ,nullptr },  // Inst #288 = DSTT
  { 289,	3,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo44, PPC::DeprecatedDST ,nullptr },  // Inst #289 = DSTT64
  { 290,	4,	1,	4,	0,	0, 0x0ULL, ImplicitList6, ImplicitList6, OperandInfo45, -1 ,nullptr },  // Inst #290 = DYNALLOC
  { 291,	4,	1,	4,	0,	0, 0x0ULL, ImplicitList20, ImplicitList20, OperandInfo46, -1 ,nullptr },  // Inst #291 = DYNALLOC8
  { 292,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo47, -1 ,nullptr },  // Inst #292 = DYNAREAOFFSET
  { 293,	3,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo47, -1 ,nullptr },  // Inst #293 = DYNAREAOFFSET8
  { 294,	1,	0,	4,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo10, -1 ,nullptr },  // Inst #294 = EH_SjLj_LongJmp32
  { 295,	1,	0,	4,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo10, -1 ,nullptr },  // Inst #295 = EH_SjLj_LongJmp64
  { 296,	2,	1,	4,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, ImplicitList7, OperandInfo48, -1 ,nullptr },  // Inst #296 = EH_SjLj_SetJmp32
  { 297,	2,	1,	4,	0,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, ImplicitList8, OperandInfo48, -1 ,nullptr },  // Inst #297 = EH_SjLj_SetJmp64
  { 298,	1,	0,	4,	0,	0|(1ULL<<MCID::Branch)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #298 = EH_SjLj_Setup
  { 299,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #299 = EQV
  { 300,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #300 = EQV8
  { 301,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #301 = EQV8o
  { 302,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #302 = EQVo
  { 303,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #303 = EVABS
  { 304,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #304 = EVADDIW
  { 305,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #305 = EVADDSMIAAW
  { 306,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #306 = EVADDSSIAAW
  { 307,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #307 = EVADDUMIAAW
  { 308,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #308 = EVADDUSIAAW
  { 309,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #309 = EVADDW
  { 310,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #310 = EVAND
  { 311,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #311 = EVANDC
  { 312,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo37, -1 ,nullptr },  // Inst #312 = EVCMPEQ
  { 313,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo37, -1 ,nullptr },  // Inst #313 = EVCMPGTS
  { 314,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo37, -1 ,nullptr },  // Inst #314 = EVCMPGTU
  { 315,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo37, -1 ,nullptr },  // Inst #315 = EVCMPLTS
  { 316,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo37, -1 ,nullptr },  // Inst #316 = EVCMPLTU
  { 317,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #317 = EVCNTLSW
  { 318,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #318 = EVCNTLZW
  { 319,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #319 = EVDIVWS
  { 320,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #320 = EVDIVWU
  { 321,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #321 = EVEQV
  { 322,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #322 = EVEXTSB
  { 323,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #323 = EVEXTSH
  { 324,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #324 = EVLDD
  { 325,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #325 = EVLDDX
  { 326,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #326 = EVLDH
  { 327,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #327 = EVLDHX
  { 328,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #328 = EVLDW
  { 329,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #329 = EVLDWX
  { 330,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #330 = EVLHHESPLAT
  { 331,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #331 = EVLHHESPLATX
  { 332,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #332 = EVLHHOSSPLAT
  { 333,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #333 = EVLHHOSSPLATX
  { 334,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #334 = EVLHHOUSPLAT
  { 335,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #335 = EVLHHOUSPLATX
  { 336,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #336 = EVLWHE
  { 337,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #337 = EVLWHEX
  { 338,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #338 = EVLWHOS
  { 339,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #339 = EVLWHOSX
  { 340,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #340 = EVLWHOU
  { 341,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #341 = EVLWHOUX
  { 342,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #342 = EVLWHSPLAT
  { 343,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #343 = EVLWHSPLATX
  { 344,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #344 = EVLWWSPLAT
  { 345,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #345 = EVLWWSPLATX
  { 346,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #346 = EVMERGEHI
  { 347,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #347 = EVMERGEHILO
  { 348,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #348 = EVMERGELO
  { 349,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #349 = EVMERGELOHI
  { 350,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #350 = EVMHEGSMFAA
  { 351,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #351 = EVMHEGSMFAN
  { 352,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #352 = EVMHEGSMIAA
  { 353,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #353 = EVMHEGSMIAN
  { 354,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #354 = EVMHEGUMIAA
  { 355,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #355 = EVMHEGUMIAN
  { 356,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #356 = EVMHESMF
  { 357,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #357 = EVMHESMFA
  { 358,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #358 = EVMHESMFAAW
  { 359,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #359 = EVMHESMFANW
  { 360,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #360 = EVMHESMI
  { 361,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #361 = EVMHESMIA
  { 362,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #362 = EVMHESMIAAW
  { 363,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #363 = EVMHESMIANW
  { 364,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #364 = EVMHESSF
  { 365,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #365 = EVMHESSFA
  { 366,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #366 = EVMHESSFAAW
  { 367,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #367 = EVMHESSFANW
  { 368,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #368 = EVMHESSIAAW
  { 369,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #369 = EVMHESSIANW
  { 370,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #370 = EVMHEUMI
  { 371,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #371 = EVMHEUMIA
  { 372,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #372 = EVMHEUMIAAW
  { 373,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #373 = EVMHEUMIANW
  { 374,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #374 = EVMHEUSIAAW
  { 375,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #375 = EVMHEUSIANW
  { 376,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #376 = EVMHOGSMFAA
  { 377,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #377 = EVMHOGSMFAN
  { 378,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #378 = EVMHOGSMIAA
  { 379,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #379 = EVMHOGSMIAN
  { 380,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #380 = EVMHOGUMIAA
  { 381,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #381 = EVMHOGUMIAN
  { 382,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #382 = EVMHOSMF
  { 383,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #383 = EVMHOSMFA
  { 384,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #384 = EVMHOSMFAAW
  { 385,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #385 = EVMHOSMFANW
  { 386,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #386 = EVMHOSMI
  { 387,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #387 = EVMHOSMIA
  { 388,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #388 = EVMHOSMIAAW
  { 389,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #389 = EVMHOSMIANW
  { 390,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #390 = EVMHOSSF
  { 391,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #391 = EVMHOSSFA
  { 392,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #392 = EVMHOSSFAAW
  { 393,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #393 = EVMHOSSFANW
  { 394,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #394 = EVMHOSSIAAW
  { 395,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #395 = EVMHOSSIANW
  { 396,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #396 = EVMHOUMI
  { 397,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #397 = EVMHOUMIA
  { 398,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #398 = EVMHOUMIAAW
  { 399,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #399 = EVMHOUMIANW
  { 400,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #400 = EVMHOUSIAAW
  { 401,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #401 = EVMHOUSIANW
  { 402,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #402 = EVMRA
  { 403,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #403 = EVMWHSMF
  { 404,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #404 = EVMWHSMFA
  { 405,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #405 = EVMWHSMI
  { 406,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #406 = EVMWHSMIA
  { 407,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #407 = EVMWHSSF
  { 408,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #408 = EVMWHSSFA
  { 409,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #409 = EVMWHUMI
  { 410,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #410 = EVMWHUMIA
  { 411,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #411 = EVMWLSMIAAW
  { 412,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #412 = EVMWLSMIANW
  { 413,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #413 = EVMWLSSIAAW
  { 414,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #414 = EVMWLSSIANW
  { 415,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #415 = EVMWLUMI
  { 416,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #416 = EVMWLUMIA
  { 417,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #417 = EVMWLUMIAAW
  { 418,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #418 = EVMWLUMIANW
  { 419,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #419 = EVMWLUSIAAW
  { 420,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #420 = EVMWLUSIANW
  { 421,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #421 = EVMWSMF
  { 422,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #422 = EVMWSMFA
  { 423,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #423 = EVMWSMFAA
  { 424,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #424 = EVMWSMFAN
  { 425,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #425 = EVMWSMI
  { 426,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #426 = EVMWSMIA
  { 427,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #427 = EVMWSMIAA
  { 428,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #428 = EVMWSMIAN
  { 429,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #429 = EVMWSSF
  { 430,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #430 = EVMWSSFA
  { 431,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #431 = EVMWSSFAA
  { 432,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #432 = EVMWSSFAN
  { 433,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #433 = EVMWUMI
  { 434,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #434 = EVMWUMIA
  { 435,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #435 = EVMWUMIAA
  { 436,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #436 = EVMWUMIAN
  { 437,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #437 = EVNAND
  { 438,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #438 = EVNEG
  { 439,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #439 = EVNOR
  { 440,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #440 = EVOR
  { 441,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #441 = EVORC
  { 442,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #442 = EVRLW
  { 443,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #443 = EVRLWI
  { 444,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #444 = EVRNDW
  { 445,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #445 = EVSLW
  { 446,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #446 = EVSLWI
  { 447,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo50, -1 ,nullptr },  // Inst #447 = EVSPLATFI
  { 448,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo50, -1 ,nullptr },  // Inst #448 = EVSPLATI
  { 449,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #449 = EVSRWIS
  { 450,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #450 = EVSRWIU
  { 451,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #451 = EVSRWS
  { 452,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #452 = EVSRWU
  { 453,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #453 = EVSTDD
  { 454,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #454 = EVSTDDX
  { 455,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #455 = EVSTDH
  { 456,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #456 = EVSTDHX
  { 457,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #457 = EVSTDW
  { 458,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #458 = EVSTDWX
  { 459,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #459 = EVSTWHE
  { 460,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #460 = EVSTWHEX
  { 461,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #461 = EVSTWHO
  { 462,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #462 = EVSTWHOX
  { 463,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #463 = EVSTWWE
  { 464,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #464 = EVSTWWEX
  { 465,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #465 = EVSTWWO
  { 466,	3,	0,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #466 = EVSTWWOX
  { 467,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #467 = EVSUBFSMIAAW
  { 468,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #468 = EVSUBFSSIAAW
  { 469,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #469 = EVSUBFUMIAAW
  { 470,	2,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #470 = EVSUBFUSIAAW
  { 471,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #471 = EVSUBFW
  { 472,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo51, -1 ,nullptr },  // Inst #472 = EVSUBIFW
  { 473,	3,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #473 = EVXOR
  { 474,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #474 = EXTLDI
  { 475,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #475 = EXTLDIo
  { 476,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #476 = EXTLWI
  { 477,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #477 = EXTLWIo
  { 478,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #478 = EXTRDI
  { 479,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #479 = EXTRDIo
  { 480,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #480 = EXTRWI
  { 481,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #481 = EXTRWIo
  { 482,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #482 = EXTSB
  { 483,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo21, -1 ,nullptr },  // Inst #483 = EXTSB8
  { 484,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo52, -1 ,nullptr },  // Inst #484 = EXTSB8_32_64
  { 485,	2,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo21, -1 ,nullptr },  // Inst #485 = EXTSB8o
  { 486,	2,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo20, -1 ,nullptr },  // Inst #486 = EXTSBo
  { 487,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #487 = EXTSH
  { 488,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo21, -1 ,nullptr },  // Inst #488 = EXTSH8
  { 489,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo52, -1 ,nullptr },  // Inst #489 = EXTSH8_32_64
  { 490,	2,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo21, -1 ,nullptr },  // Inst #490 = EXTSH8o
  { 491,	2,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo20, -1 ,nullptr },  // Inst #491 = EXTSHo
  { 492,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo21, -1 ,nullptr },  // Inst #492 = EXTSW
  { 493,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo52, -1 ,nullptr },  // Inst #493 = EXTSW_32_64
  { 494,	2,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo52, -1 ,nullptr },  // Inst #494 = EXTSW_32_64o
  { 495,	2,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo21, -1 ,nullptr },  // Inst #495 = EXTSWo
  { 496,	0,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #496 = EnforceIEIO
  { 497,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #497 = FABSD
  { 498,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #498 = FABSDo
  { 499,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #499 = FABSS
  { 500,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #500 = FABSSo
  { 501,	3,	1,	4,	12,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo55, -1 ,nullptr },  // Inst #501 = FADD
  { 502,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo56, -1 ,nullptr },  // Inst #502 = FADDS
  { 503,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo56, -1 ,nullptr },  // Inst #503 = FADDSo
  { 504,	3,	1,	4,	12,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo55, -1 ,nullptr },  // Inst #504 = FADDo
  { 505,	3,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList13, nullptr, OperandInfo55, -1 ,nullptr },  // Inst #505 = FADDrtz
  { 506,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #506 = FCFID
  { 507,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo57, -1 ,nullptr },  // Inst #507 = FCFIDS
  { 508,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo57, -1 ,nullptr },  // Inst #508 = FCFIDSo
  { 509,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #509 = FCFIDU
  { 510,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo57, -1 ,nullptr },  // Inst #510 = FCFIDUS
  { 511,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo57, -1 ,nullptr },  // Inst #511 = FCFIDUSo
  { 512,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #512 = FCFIDUo
  { 513,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #513 = FCFIDo
  { 514,	3,	1,	4,	13,	0|(1ULL<<MCID::Compare), 0x18ULL, nullptr, nullptr, OperandInfo58, -1 ,nullptr },  // Inst #514 = FCMPUD
  { 515,	3,	1,	4,	13,	0|(1ULL<<MCID::Compare), 0x18ULL, nullptr, nullptr, OperandInfo59, -1 ,nullptr },  // Inst #515 = FCMPUS
  { 516,	3,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo55, -1 ,nullptr },  // Inst #516 = FCPSGND
  { 517,	3,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo55, -1 ,nullptr },  // Inst #517 = FCPSGNDo
  { 518,	3,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo56, -1 ,nullptr },  // Inst #518 = FCPSGNS
  { 519,	3,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo56, -1 ,nullptr },  // Inst #519 = FCPSGNSo
  { 520,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #520 = FCTID
  { 521,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #521 = FCTIDUZ
  { 522,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #522 = FCTIDUZo
  { 523,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #523 = FCTIDZ
  { 524,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #524 = FCTIDZo
  { 525,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #525 = FCTIDo
  { 526,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #526 = FCTIW
  { 527,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #527 = FCTIWUZ
  { 528,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #528 = FCTIWUZo
  { 529,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #529 = FCTIWZ
  { 530,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #530 = FCTIWZo
  { 531,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #531 = FCTIWo
  { 532,	3,	1,	4,	14,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo55, -1 ,nullptr },  // Inst #532 = FDIV
  { 533,	3,	1,	4,	15,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo56, -1 ,nullptr },  // Inst #533 = FDIVS
  { 534,	3,	1,	4,	15,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo56, -1 ,nullptr },  // Inst #534 = FDIVSo
  { 535,	3,	1,	4,	14,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo55, -1 ,nullptr },  // Inst #535 = FDIVo
  { 536,	4,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo60, -1 ,nullptr },  // Inst #536 = FMADD
  { 537,	4,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo61, -1 ,nullptr },  // Inst #537 = FMADDS
  { 538,	4,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo61, -1 ,nullptr },  // Inst #538 = FMADDSo
  { 539,	4,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo60, -1 ,nullptr },  // Inst #539 = FMADDo
  { 540,	2,	1,	4,	11,	0, 0x0ULL, nullptr, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #540 = FMR
  { 541,	2,	1,	4,	11,	0, 0x0ULL, nullptr, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #541 = FMRo
  { 542,	4,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo60, -1 ,nullptr },  // Inst #542 = FMSUB
  { 543,	4,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo61, -1 ,nullptr },  // Inst #543 = FMSUBS
  { 544,	4,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo61, -1 ,nullptr },  // Inst #544 = FMSUBSo
  { 545,	4,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo60, -1 ,nullptr },  // Inst #545 = FMSUBo
  { 546,	3,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo55, -1 ,nullptr },  // Inst #546 = FMUL
  { 547,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo56, -1 ,nullptr },  // Inst #547 = FMULS
  { 548,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo56, -1 ,nullptr },  // Inst #548 = FMULSo
  { 549,	3,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo55, -1 ,nullptr },  // Inst #549 = FMULo
  { 550,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #550 = FNABSD
  { 551,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #551 = FNABSDo
  { 552,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #552 = FNABSS
  { 553,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #553 = FNABSSo
  { 554,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #554 = FNEGD
  { 555,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #555 = FNEGDo
  { 556,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #556 = FNEGS
  { 557,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #557 = FNEGSo
  { 558,	4,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo60, -1 ,nullptr },  // Inst #558 = FNMADD
  { 559,	4,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo61, -1 ,nullptr },  // Inst #559 = FNMADDS
  { 560,	4,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo61, -1 ,nullptr },  // Inst #560 = FNMADDSo
  { 561,	4,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo60, -1 ,nullptr },  // Inst #561 = FNMADDo
  { 562,	4,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo60, -1 ,nullptr },  // Inst #562 = FNMSUB
  { 563,	4,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, nullptr, OperandInfo61, -1 ,nullptr },  // Inst #563 = FNMSUBS
  { 564,	4,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo61, -1 ,nullptr },  // Inst #564 = FNMSUBSo
  { 565,	4,	1,	4,	16,	0|(1ULL<<MCID::Commutable), 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo60, -1 ,nullptr },  // Inst #565 = FNMSUBo
  { 566,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #566 = FRE
  { 567,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #567 = FRES
  { 568,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #568 = FRESo
  { 569,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #569 = FREo
  { 570,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #570 = FRIMD
  { 571,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #571 = FRIMDo
  { 572,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #572 = FRIMS
  { 573,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #573 = FRIMSo
  { 574,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #574 = FRIND
  { 575,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #575 = FRINDo
  { 576,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #576 = FRINS
  { 577,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #577 = FRINSo
  { 578,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #578 = FRIPD
  { 579,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #579 = FRIPDo
  { 580,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #580 = FRIPS
  { 581,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #581 = FRIPSo
  { 582,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #582 = FRIZD
  { 583,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #583 = FRIZDo
  { 584,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #584 = FRIZS
  { 585,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #585 = FRIZSo
  { 586,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo57, -1 ,nullptr },  // Inst #586 = FRSP
  { 587,	2,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo57, -1 ,nullptr },  // Inst #587 = FRSPo
  { 588,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #588 = FRSQRTE
  { 589,	2,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #589 = FRSQRTES
  { 590,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #590 = FRSQRTESo
  { 591,	2,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #591 = FRSQRTEo
  { 592,	4,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo60, -1 ,nullptr },  // Inst #592 = FSELD
  { 593,	4,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo60, -1 ,nullptr },  // Inst #593 = FSELDo
  { 594,	4,	1,	4,	11,	0, 0x18ULL, nullptr, nullptr, OperandInfo62, -1 ,nullptr },  // Inst #594 = FSELS
  { 595,	4,	1,	4,	11,	0, 0x18ULL, nullptr, ImplicitList21, OperandInfo62, -1 ,nullptr },  // Inst #595 = FSELSo
  { 596,	2,	1,	4,	17,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo53, -1 ,nullptr },  // Inst #596 = FSQRT
  { 597,	2,	1,	4,	18,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo54, -1 ,nullptr },  // Inst #597 = FSQRTS
  { 598,	2,	1,	4,	18,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo54, -1 ,nullptr },  // Inst #598 = FSQRTSo
  { 599,	2,	1,	4,	17,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo53, -1 ,nullptr },  // Inst #599 = FSQRTo
  { 600,	3,	1,	4,	12,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo55, -1 ,nullptr },  // Inst #600 = FSUB
  { 601,	3,	1,	4,	11,	0, 0x18ULL, ImplicitList13, nullptr, OperandInfo56, -1 ,nullptr },  // Inst #601 = FSUBS
  { 602,	3,	1,	4,	11,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo56, -1 ,nullptr },  // Inst #602 = FSUBSo
  { 603,	3,	1,	4,	12,	0, 0x18ULL, ImplicitList13, ImplicitList21, OperandInfo55, -1 ,nullptr },  // Inst #603 = FSUBo
  { 604,	3,	1,	4,	0,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL, nullptr, ImplicitList22, OperandInfo15, -1 ,nullptr },  // Inst #604 = GETtlsADDR
  { 605,	3,	1,	4,	0,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL, nullptr, ImplicitList23, OperandInfo13, -1 ,nullptr },  // Inst #605 = GETtlsADDR32
  { 606,	3,	1,	4,	0,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL, nullptr, ImplicitList22, OperandInfo15, -1 ,nullptr },  // Inst #606 = GETtlsldADDR
  { 607,	3,	1,	4,	0,	0|(1ULL<<MCID::ExtraSrcRegAllocReq)|(1ULL<<MCID::ExtraDefRegAllocReq), 0x0ULL, nullptr, ImplicitList23, OperandInfo13, -1 ,nullptr },  // Inst #607 = GETtlsldADDR32
  { 608,	2,	0,	4,	19,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo40, -1 ,nullptr },  // Inst #608 = ICBI
  { 609,	3,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL, nullptr, nullptr, OperandInfo41, -1 ,nullptr },  // Inst #609 = ICBT
  { 610,	2,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #610 = ICCCI
  { 611,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #611 = INSLWI
  { 612,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #612 = INSLWIo
  { 613,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #613 = INSRDI
  { 614,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #614 = INSRDIo
  { 615,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #615 = INSRWI
  { 616,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo34, -1 ,nullptr },  // Inst #616 = INSRWIo
  { 617,	4,	1,	4,	20,	0|(1ULL<<MCID::Select), 0x8ULL, nullptr, nullptr, OperandInfo63, -1 ,nullptr },  // Inst #617 = ISEL
  { 618,	4,	1,	4,	20,	0|(1ULL<<MCID::Select), 0x8ULL, nullptr, nullptr, OperandInfo64, -1 ,nullptr },  // Inst #618 = ISEL8
  { 619,	0,	0,	4,	21,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #619 = ISYNC
  { 620,	3,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo16, -1 ,nullptr },  // Inst #620 = LA
  { 621,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #621 = LAx
  { 622,	3,	1,	4,	22,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #622 = LBARX
  { 623,	3,	1,	4,	22,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #623 = LBARXL
  { 624,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #624 = LBZ
  { 625,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #625 = LBZ8
  { 626,	3,	1,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #626 = LBZCIX
  { 627,	4,	2,	4,	23,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo67, -1 ,nullptr },  // Inst #627 = LBZU
  { 628,	4,	2,	4,	23,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo68, -1 ,nullptr },  // Inst #628 = LBZU8
  { 629,	4,	2,	4,	24,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo69, -1 ,nullptr },  // Inst #629 = LBZUX
  { 630,	4,	2,	4,	24,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo70, -1 ,nullptr },  // Inst #630 = LBZUX8
  { 631,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #631 = LBZX
  { 632,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #632 = LBZX8
  { 633,	3,	1,	4,	25,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #633 = LD
  { 634,	3,	1,	4,	26,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #634 = LDARX
  { 635,	3,	1,	4,	26,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #635 = LDARXL
  { 636,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #636 = LDBRX
  { 637,	3,	1,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #637 = LDCIX
  { 638,	4,	2,	4,	27,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo68, -1 ,nullptr },  // Inst #638 = LDU
  { 639,	4,	2,	4,	28,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo70, -1 ,nullptr },  // Inst #639 = LDUX
  { 640,	3,	1,	4,	25,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #640 = LDX
  { 641,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo72, -1 ,nullptr },  // Inst #641 = LDgotTprelL
  { 642,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo73, -1 ,nullptr },  // Inst #642 = LDgotTprelL32
  { 643,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo74, -1 ,nullptr },  // Inst #643 = LDtoc
  { 644,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo74, -1 ,nullptr },  // Inst #644 = LDtocBA
  { 645,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo74, -1 ,nullptr },  // Inst #645 = LDtocCPT
  { 646,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo74, -1 ,nullptr },  // Inst #646 = LDtocJTI
  { 647,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo72, -1 ,nullptr },  // Inst #647 = LDtocL
  { 648,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo75, -1 ,nullptr },  // Inst #648 = LFD
  { 649,	4,	2,	4,	30,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo76, -1 ,nullptr },  // Inst #649 = LFDU
  { 650,	4,	2,	4,	31,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo77, -1 ,nullptr },  // Inst #650 = LFDUX
  { 651,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo78, -1 ,nullptr },  // Inst #651 = LFDX
  { 652,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo78, -1 ,nullptr },  // Inst #652 = LFIWAX
  { 653,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo78, -1 ,nullptr },  // Inst #653 = LFIWZX
  { 654,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo79, -1 ,nullptr },  // Inst #654 = LFS
  { 655,	4,	2,	4,	30,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo80, -1 ,nullptr },  // Inst #655 = LFSU
  { 656,	4,	2,	4,	31,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo81, -1 ,nullptr },  // Inst #656 = LFSUX
  { 657,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo82, -1 ,nullptr },  // Inst #657 = LFSX
  { 658,	3,	1,	4,	32,	0|(1ULL<<MCID::MayLoad), 0x14ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #658 = LHA
  { 659,	3,	1,	4,	32,	0|(1ULL<<MCID::MayLoad), 0x14ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #659 = LHA8
  { 660,	3,	1,	4,	22,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #660 = LHARX
  { 661,	3,	1,	4,	22,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #661 = LHARXL
  { 662,	4,	2,	4,	33,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo67, -1 ,nullptr },  // Inst #662 = LHAU
  { 663,	4,	2,	4,	33,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo68, -1 ,nullptr },  // Inst #663 = LHAU8
  { 664,	4,	2,	4,	34,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo69, -1 ,nullptr },  // Inst #664 = LHAUX
  { 665,	4,	2,	4,	34,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo70, -1 ,nullptr },  // Inst #665 = LHAUX8
  { 666,	3,	1,	4,	32,	0|(1ULL<<MCID::MayLoad), 0x14ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #666 = LHAX
  { 667,	3,	1,	4,	32,	0|(1ULL<<MCID::MayLoad), 0x14ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #667 = LHAX8
  { 668,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #668 = LHBRX
  { 669,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #669 = LHBRX8
  { 670,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #670 = LHZ
  { 671,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #671 = LHZ8
  { 672,	3,	1,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #672 = LHZCIX
  { 673,	4,	2,	4,	23,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo67, -1 ,nullptr },  // Inst #673 = LHZU
  { 674,	4,	2,	4,	23,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo68, -1 ,nullptr },  // Inst #674 = LHZU8
  { 675,	4,	2,	4,	24,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo69, -1 ,nullptr },  // Inst #675 = LHZUX
  { 676,	4,	2,	4,	24,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo70, -1 ,nullptr },  // Inst #676 = LHZUX8
  { 677,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #677 = LHZX
  { 678,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #678 = LHZX8
  { 679,	2,	1,	4,	1,	0|(1ULL<<MCID::MoveImm)|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove), 0x8ULL, nullptr, nullptr, OperandInfo83, -1 ,nullptr },  // Inst #679 = LI
  { 680,	2,	1,	4,	1,	0|(1ULL<<MCID::MoveImm)|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove), 0x8ULL, nullptr, nullptr, OperandInfo84, -1 ,nullptr },  // Inst #680 = LI8
  { 681,	2,	1,	4,	1,	0|(1ULL<<MCID::MoveImm)|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove), 0x8ULL, nullptr, nullptr, OperandInfo83, -1 ,nullptr },  // Inst #681 = LIS
  { 682,	2,	1,	4,	1,	0|(1ULL<<MCID::MoveImm)|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove), 0x8ULL, nullptr, nullptr, OperandInfo84, -1 ,nullptr },  // Inst #682 = LIS8
  { 683,	3,	1,	4,	35,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #683 = LMW
  { 684,	3,	1,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #684 = LSWI
  { 685,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #685 = LVEBX
  { 686,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #686 = LVEHX
  { 687,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #687 = LVEWX
  { 688,	3,	1,	4,	8,	0, 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #688 = LVSL
  { 689,	3,	1,	4,	8,	0, 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #689 = LVSR
  { 690,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #690 = LVX
  { 691,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #691 = LVXL
  { 692,	3,	1,	4,	36,	0|(1ULL<<MCID::MayLoad), 0x14ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #692 = LWA
  { 693,	3,	1,	4,	22,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #693 = LWARX
  { 694,	3,	1,	4,	22,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #694 = LWARXL
  { 695,	4,	2,	4,	34,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo70, -1 ,nullptr },  // Inst #695 = LWAUX
  { 696,	3,	1,	4,	32,	0|(1ULL<<MCID::MayLoad), 0x14ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #696 = LWAX
  { 697,	3,	1,	4,	32,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects), 0x14ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #697 = LWAX_32
  { 698,	3,	1,	4,	36,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects), 0x14ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #698 = LWA_32
  { 699,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #699 = LWBRX
  { 700,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #700 = LWBRX8
  { 701,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #701 = LWZ
  { 702,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #702 = LWZ8
  { 703,	3,	1,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #703 = LWZCIX
  { 704,	4,	2,	4,	23,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo67, -1 ,nullptr },  // Inst #704 = LWZU
  { 705,	4,	2,	4,	23,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo68, -1 ,nullptr },  // Inst #705 = LWZU8
  { 706,	4,	2,	4,	24,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo69, -1 ,nullptr },  // Inst #706 = LWZUX
  { 707,	4,	2,	4,	24,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo70, -1 ,nullptr },  // Inst #707 = LWZUX8
  { 708,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #708 = LWZX
  { 709,	3,	1,	4,	8,	0|(1ULL<<MCID::MayLoad), 0x10ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #709 = LWZX8
  { 710,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo51, -1 ,nullptr },  // Inst #710 = LWZtoc
  { 711,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo86, -1 ,nullptr },  // Inst #711 = LXSDX
  { 712,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo86, -1 ,nullptr },  // Inst #712 = LXSIWAX
  { 713,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo86, -1 ,nullptr },  // Inst #713 = LXSIWZX
  { 714,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo87, -1 ,nullptr },  // Inst #714 = LXSSPX
  { 715,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo88, -1 ,nullptr },  // Inst #715 = LXVD2X
  { 716,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo88, -1 ,nullptr },  // Inst #716 = LXVDSX
  { 717,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo88, -1 ,nullptr },  // Inst #717 = LXVW4X
  { 718,	1,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #718 = MBAR
  { 719,	2,	1,	4,	37,	0, 0x21ULL, nullptr, nullptr, OperandInfo89, -1 ,nullptr },  // Inst #719 = MCRF
  { 720,	2,	1,	4,	37,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo89, -1 ,nullptr },  // Inst #720 = MCRFS
  { 721,	3,	1,	4,	3,	0, 0x1ULL, nullptr, nullptr, OperandInfo90, -1 ,nullptr },  // Inst #721 = MFBHRBE
  { 722,	1,	1,	4,	38,	0, 0x20ULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #722 = MFCR
  { 723,	1,	1,	4,	38,	0, 0x20ULL, nullptr, nullptr, OperandInfo92, -1 ,nullptr },  // Inst #723 = MFCR8
  { 724,	1,	1,	4,	39,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, ImplicitList7, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #724 = MFCTR
  { 725,	1,	1,	4,	39,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, ImplicitList8, nullptr, OperandInfo92, -1 ,nullptr },  // Inst #725 = MFCTR8
  { 726,	2,	1,	4,	39,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo50, -1 ,nullptr },  // Inst #726 = MFDCR
  { 727,	1,	1,	4,	40,	0, 0x1aULL, ImplicitList13, nullptr, OperandInfo93, -1 ,nullptr },  // Inst #727 = MFFS
  { 728,	1,	1,	4,	40,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, ImplicitList13, ImplicitList21, OperandInfo93, -1 ,nullptr },  // Inst #728 = MFFSo
  { 729,	1,	1,	4,	39,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, ImplicitList10, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #729 = MFLR
  { 730,	1,	1,	4,	39,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, ImplicitList12, nullptr, OperandInfo92, -1 ,nullptr },  // Inst #730 = MFLR8
  { 731,	1,	1,	4,	41,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #731 = MFMSR
  { 732,	2,	1,	4,	42,	0|(1ULL<<MCID::ExtraSrcRegAllocReq), 0x21ULL, nullptr, nullptr, OperandInfo83, -1 ,nullptr },  // Inst #732 = MFOCRF
  { 733,	2,	1,	4,	42,	0|(1ULL<<MCID::ExtraSrcRegAllocReq), 0x21ULL, nullptr, nullptr, OperandInfo84, -1 ,nullptr },  // Inst #733 = MFOCRF8
  { 734,	2,	1,	4,	39,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo50, -1 ,nullptr },  // Inst #734 = MFSPR
  { 735,	2,	1,	4,	39,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo94, -1 ,nullptr },  // Inst #735 = MFSPR8
  { 736,	2,	1,	4,	43,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo83, -1 ,nullptr },  // Inst #736 = MFSR
  { 737,	2,	1,	4,	43,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #737 = MFSRIN
  { 738,	2,	1,	4,	44,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo50, -1 ,nullptr },  // Inst #738 = MFTB
  { 739,	1,	1,	4,	44,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, nullptr, nullptr, OperandInfo92, -1 ,nullptr },  // Inst #739 = MFTB8
  { 740,	1,	1,	4,	2,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #740 = MFVRSAVE
  { 741,	2,	1,	4,	2,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, nullptr, nullptr, OperandInfo95, -1 ,nullptr },  // Inst #741 = MFVRSAVEv
  { 742,	1,	1,	4,	45,	0|(1ULL<<MCID::MayLoad), 0x0ULL, nullptr, nullptr, OperandInfo96, -1 ,nullptr },  // Inst #742 = MFVSCR
  { 743,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo97, -1 ,nullptr },  // Inst #743 = MFVSRD
  { 744,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo98, -1 ,nullptr },  // Inst #744 = MFVSRWZ
  { 745,	0,	0,	4,	47,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #745 = MSYNC
  { 746,	2,	0,	4,	48,	0, 0x20ULL, nullptr, nullptr, OperandInfo99, -1 ,nullptr },  // Inst #746 = MTCRF
  { 747,	2,	0,	4,	48,	0, 0x20ULL, nullptr, nullptr, OperandInfo100, -1 ,nullptr },  // Inst #747 = MTCRF8
  { 748,	1,	0,	4,	49,	0, 0x9ULL, nullptr, ImplicitList7, OperandInfo91, -1 ,nullptr },  // Inst #748 = MTCTR
  { 749,	1,	0,	4,	49,	0, 0x9ULL, nullptr, ImplicitList8, OperandInfo92, -1 ,nullptr },  // Inst #749 = MTCTR8
  { 750,	1,	0,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, nullptr, ImplicitList8, OperandInfo92, -1 ,nullptr },  // Inst #750 = MTCTR8loop
  { 751,	1,	0,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, nullptr, ImplicitList7, OperandInfo91, -1 ,nullptr },  // Inst #751 = MTCTRloop
  { 752,	2,	0,	4,	49,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo50, -1 ,nullptr },  // Inst #752 = MTDCR
  { 753,	1,	0,	4,	50,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x1aULL, ImplicitList13, ImplicitList13, OperandInfo5, -1 ,nullptr },  // Inst #753 = MTFSB0
  { 754,	1,	0,	4,	50,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x1aULL, ImplicitList13, ImplicitList13, OperandInfo5, -1 ,nullptr },  // Inst #754 = MTFSB1
  { 755,	4,	0,	4,	40,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo101, -1 ,nullptr },  // Inst #755 = MTFSF
  { 756,	3,	1,	4,	40,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo102, -1 ,nullptr },  // Inst #756 = MTFSFI
  { 757,	3,	1,	4,	40,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo102, -1 ,nullptr },  // Inst #757 = MTFSFIo
  { 758,	2,	0,	4,	50,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x1aULL, ImplicitList13, ImplicitList13, OperandInfo103, -1 ,nullptr },  // Inst #758 = MTFSFb
  { 759,	4,	0,	4,	40,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo101, -1 ,nullptr },  // Inst #759 = MTFSFo
  { 760,	1,	0,	4,	49,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, nullptr, ImplicitList10, OperandInfo91, -1 ,nullptr },  // Inst #760 = MTLR
  { 761,	1,	0,	4,	49,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x9ULL, nullptr, ImplicitList12, OperandInfo92, -1 ,nullptr },  // Inst #761 = MTLR8
  { 762,	2,	0,	4,	51,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo50, -1 ,nullptr },  // Inst #762 = MTMSR
  { 763,	2,	0,	4,	52,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo50, -1 ,nullptr },  // Inst #763 = MTMSRD
  { 764,	2,	1,	4,	48,	0, 0x21ULL, nullptr, nullptr, OperandInfo104, -1 ,nullptr },  // Inst #764 = MTOCRF
  { 765,	2,	1,	4,	48,	0, 0x21ULL, nullptr, nullptr, OperandInfo105, -1 ,nullptr },  // Inst #765 = MTOCRF8
  { 766,	2,	0,	4,	49,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo99, -1 ,nullptr },  // Inst #766 = MTSPR
  { 767,	2,	0,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo100, -1 ,nullptr },  // Inst #767 = MTSPR8
  { 768,	2,	0,	4,	53,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo83, -1 ,nullptr },  // Inst #768 = MTSR
  { 769,	2,	0,	4,	53,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #769 = MTSRIN
  { 770,	1,	0,	4,	2,	0|(1ULL<<MCID::UnmodeledSideEffects), 0xaULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #770 = MTVRSAVE
  { 771,	2,	1,	4,	2,	0|(1ULL<<MCID::UnmodeledSideEffects), 0xaULL, nullptr, nullptr, OperandInfo106, -1 ,nullptr },  // Inst #771 = MTVRSAVEv
  { 772,	1,	0,	4,	8,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo96, -1 ,nullptr },  // Inst #772 = MTVSCR
  { 773,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo107, -1 ,nullptr },  // Inst #773 = MTVSRD
  { 774,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo108, -1 ,nullptr },  // Inst #774 = MTVSRWA
  { 775,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo108, -1 ,nullptr },  // Inst #775 = MTVSRWZ
  { 776,	3,	1,	4,	54,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #776 = MULHD
  { 777,	3,	1,	4,	55,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #777 = MULHDU
  { 778,	3,	1,	4,	55,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #778 = MULHDUo
  { 779,	3,	1,	4,	54,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #779 = MULHDo
  { 780,	3,	1,	4,	54,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #780 = MULHW
  { 781,	3,	1,	4,	55,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #781 = MULHWU
  { 782,	3,	1,	4,	55,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #782 = MULHWUo
  { 783,	3,	1,	4,	54,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #783 = MULHWo
  { 784,	3,	1,	4,	56,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #784 = MULLD
  { 785,	3,	1,	4,	56,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #785 = MULLDo
  { 786,	3,	1,	4,	57,	0, 0x8ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #786 = MULLI
  { 787,	3,	1,	4,	57,	0, 0x8ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #787 = MULLI8
  { 788,	3,	1,	4,	54,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #788 = MULLW
  { 789,	3,	1,	4,	54,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #789 = MULLWo
  { 790,	0,	0,	4,	0,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, nullptr, ImplicitList10, nullptr, -1 ,nullptr },  // Inst #790 = MoveGOTtoLR
  { 791,	0,	0,	4,	0,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, nullptr, ImplicitList10, nullptr, -1 ,nullptr },  // Inst #791 = MovePCtoLR
  { 792,	0,	0,	4,	0,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, nullptr, ImplicitList12, nullptr, -1 ,nullptr },  // Inst #792 = MovePCtoLR8
  { 793,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #793 = NAND
  { 794,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #794 = NAND8
  { 795,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #795 = NAND8o
  { 796,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #796 = NANDo
  { 797,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #797 = NEG
  { 798,	2,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo21, -1 ,nullptr },  // Inst #798 = NEG8
  { 799,	2,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo21, -1 ,nullptr },  // Inst #799 = NEG8o
  { 800,	2,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo20, -1 ,nullptr },  // Inst #800 = NEGo
  { 801,	0,	0,	4,	1,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x8ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #801 = NOP
  { 802,	0,	0,	4,	1,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x8ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #802 = NOP_GT_PWR6
  { 803,	0,	0,	4,	1,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x8ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #803 = NOP_GT_PWR7
  { 804,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #804 = NOR
  { 805,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #805 = NOR8
  { 806,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #806 = NOR8o
  { 807,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #807 = NORo
  { 808,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #808 = OR
  { 809,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #809 = OR8
  { 810,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #810 = OR8o
  { 811,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #811 = ORC
  { 812,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #812 = ORC8
  { 813,	3,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #813 = ORC8o
  { 814,	3,	1,	4,	1,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #814 = ORCo
  { 815,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #815 = ORI
  { 816,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #816 = ORI8
  { 817,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #817 = ORIS
  { 818,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #818 = ORIS8
  { 819,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #819 = ORo
  { 820,	2,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo21, -1 ,nullptr },  // Inst #820 = POPCNTD
  { 821,	2,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #821 = POPCNTW
  { 822,	1,	1,	4,	0,	0, 0x0ULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #822 = PPC32GOT
  { 823,	2,	2,	4,	0,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #823 = PPC32PICGOT
  { 824,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo109, -1 ,nullptr },  // Inst #824 = QVALIGNI
  { 825,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo110, -1 ,nullptr },  // Inst #825 = QVALIGNIb
  { 826,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo111, -1 ,nullptr },  // Inst #826 = QVALIGNIs
  { 827,	3,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo112, -1 ,nullptr },  // Inst #827 = QVESPLATI
  { 828,	3,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo113, -1 ,nullptr },  // Inst #828 = QVESPLATIb
  { 829,	3,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo114, -1 ,nullptr },  // Inst #829 = QVESPLATIs
  { 830,	2,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #830 = QVFABS
  { 831,	2,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #831 = QVFABSs
  { 832,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #832 = QVFADD
  { 833,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #833 = QVFADDS
  { 834,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo118, -1 ,nullptr },  // Inst #834 = QVFADDSs
  { 835,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #835 = QVFCFID
  { 836,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #836 = QVFCFIDS
  { 837,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #837 = QVFCFIDU
  { 838,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #838 = QVFCFIDUS
  { 839,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo119, -1 ,nullptr },  // Inst #839 = QVFCFIDb
  { 840,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #840 = QVFCMPEQ
  { 841,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo120, -1 ,nullptr },  // Inst #841 = QVFCMPEQb
  { 842,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo121, -1 ,nullptr },  // Inst #842 = QVFCMPEQbs
  { 843,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #843 = QVFCMPGT
  { 844,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo120, -1 ,nullptr },  // Inst #844 = QVFCMPGTb
  { 845,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo121, -1 ,nullptr },  // Inst #845 = QVFCMPGTbs
  { 846,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #846 = QVFCMPLT
  { 847,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo120, -1 ,nullptr },  // Inst #847 = QVFCMPLTb
  { 848,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo121, -1 ,nullptr },  // Inst #848 = QVFCMPLTbs
  { 849,	3,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #849 = QVFCPSGN
  { 850,	3,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo118, -1 ,nullptr },  // Inst #850 = QVFCPSGNs
  { 851,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #851 = QVFCTID
  { 852,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #852 = QVFCTIDU
  { 853,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #853 = QVFCTIDUZ
  { 854,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #854 = QVFCTIDZ
  { 855,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo119, -1 ,nullptr },  // Inst #855 = QVFCTIDb
  { 856,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #856 = QVFCTIW
  { 857,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #857 = QVFCTIWU
  { 858,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #858 = QVFCTIWUZ
  { 859,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #859 = QVFCTIWZ
  { 860,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo109, -1 ,nullptr },  // Inst #860 = QVFLOGICAL
  { 861,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo110, -1 ,nullptr },  // Inst #861 = QVFLOGICALb
  { 862,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo110, -1 ,nullptr },  // Inst #862 = QVFLOGICALs
  { 863,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #863 = QVFMADD
  { 864,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #864 = QVFMADDS
  { 865,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo123, -1 ,nullptr },  // Inst #865 = QVFMADDSs
  { 866,	2,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #866 = QVFMR
  { 867,	2,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo119, -1 ,nullptr },  // Inst #867 = QVFMRb
  { 868,	2,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #868 = QVFMRs
  { 869,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #869 = QVFMSUB
  { 870,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #870 = QVFMSUBS
  { 871,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo123, -1 ,nullptr },  // Inst #871 = QVFMSUBSs
  { 872,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #872 = QVFMUL
  { 873,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #873 = QVFMULS
  { 874,	3,	1,	4,	11,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo118, -1 ,nullptr },  // Inst #874 = QVFMULSs
  { 875,	2,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #875 = QVFNABS
  { 876,	2,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #876 = QVFNABSs
  { 877,	2,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #877 = QVFNEG
  { 878,	2,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #878 = QVFNEGs
  { 879,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #879 = QVFNMADD
  { 880,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #880 = QVFNMADDS
  { 881,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo123, -1 ,nullptr },  // Inst #881 = QVFNMADDSs
  { 882,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #882 = QVFNMSUB
  { 883,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #883 = QVFNMSUBS
  { 884,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo123, -1 ,nullptr },  // Inst #884 = QVFNMSUBSs
  { 885,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #885 = QVFPERM
  { 886,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo124, -1 ,nullptr },  // Inst #886 = QVFPERMs
  { 887,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #887 = QVFRE
  { 888,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #888 = QVFRES
  { 889,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #889 = QVFRESs
  { 890,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #890 = QVFRIM
  { 891,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #891 = QVFRIMs
  { 892,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #892 = QVFRIN
  { 893,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #893 = QVFRINs
  { 894,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #894 = QVFRIP
  { 895,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #895 = QVFRIPs
  { 896,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #896 = QVFRIZ
  { 897,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #897 = QVFRIZs
  { 898,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #898 = QVFRSP
  { 899,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo125, -1 ,nullptr },  // Inst #899 = QVFRSPs
  { 900,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #900 = QVFRSQRTE
  { 901,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo115, -1 ,nullptr },  // Inst #901 = QVFRSQRTES
  { 902,	2,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo116, -1 ,nullptr },  // Inst #902 = QVFRSQRTESs
  { 903,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #903 = QVFSEL
  { 904,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo126, -1 ,nullptr },  // Inst #904 = QVFSELb
  { 905,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo127, -1 ,nullptr },  // Inst #905 = QVFSELbb
  { 906,	4,	1,	4,	58,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo128, -1 ,nullptr },  // Inst #906 = QVFSELbs
  { 907,	3,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #907 = QVFSUB
  { 908,	3,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #908 = QVFSUBS
  { 909,	3,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo118, -1 ,nullptr },  // Inst #909 = QVFSUBSs
  { 910,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #910 = QVFTSTNAN
  { 911,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo120, -1 ,nullptr },  // Inst #911 = QVFTSTNANb
  { 912,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo121, -1 ,nullptr },  // Inst #912 = QVFTSTNANbs
  { 913,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #913 = QVFXMADD
  { 914,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #914 = QVFXMADDS
  { 915,	3,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #915 = QVFXMUL
  { 916,	3,	1,	4,	11,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo117, -1 ,nullptr },  // Inst #916 = QVFXMULS
  { 917,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #917 = QVFXXCPNMADD
  { 918,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #918 = QVFXXCPNMADDS
  { 919,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #919 = QVFXXMADD
  { 920,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #920 = QVFXXMADDS
  { 921,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #921 = QVFXXNPMADD
  { 922,	4,	1,	4,	16,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo122, -1 ,nullptr },  // Inst #922 = QVFXXNPMADDS
  { 923,	2,	1,	4,	58,	0|(1ULL<<MCID::Rematerializable)|(1ULL<<MCID::CheapAsAMove), 0x0ULL, ImplicitList13, nullptr, OperandInfo129, -1 ,nullptr },  // Inst #923 = QVGPCI
  { 924,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #924 = QVLFCDUX
  { 925,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #925 = QVLFCDUXA
  { 926,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #926 = QVLFCDX
  { 927,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #927 = QVLFCDXA
  { 928,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #928 = QVLFCSUX
  { 929,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #929 = QVLFCSUXA
  { 930,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #930 = QVLFCSX
  { 931,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #931 = QVLFCSXA
  { 932,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo131, -1 ,nullptr },  // Inst #932 = QVLFCSXs
  { 933,	4,	2,	4,	30,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo132, -1 ,nullptr },  // Inst #933 = QVLFDUX
  { 934,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #934 = QVLFDUXA
  { 935,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #935 = QVLFDX
  { 936,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #936 = QVLFDXA
  { 937,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo133, -1 ,nullptr },  // Inst #937 = QVLFDXb
  { 938,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #938 = QVLFIWAX
  { 939,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #939 = QVLFIWAXA
  { 940,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #940 = QVLFIWZX
  { 941,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #941 = QVLFIWZXA
  { 942,	4,	2,	4,	30,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo134, -1 ,nullptr },  // Inst #942 = QVLFSUX
  { 943,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #943 = QVLFSUXA
  { 944,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #944 = QVLFSX
  { 945,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #945 = QVLFSXA
  { 946,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo133, -1 ,nullptr },  // Inst #946 = QVLFSXb
  { 947,	3,	1,	4,	29,	0|(1ULL<<MCID::MayLoad), 0x0ULL, ImplicitList13, nullptr, OperandInfo131, -1 ,nullptr },  // Inst #947 = QVLFSXs
  { 948,	3,	1,	4,	29,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #948 = QVLPCLDX
  { 949,	3,	1,	4,	29,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #949 = QVLPCLSX
  { 950,	2,	1,	4,	29,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo135, -1 ,nullptr },  // Inst #950 = QVLPCLSXint
  { 951,	3,	1,	4,	29,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #951 = QVLPCRDX
  { 952,	3,	1,	4,	29,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #952 = QVLPCRSX
  { 953,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #953 = QVSTFCDUX
  { 954,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #954 = QVSTFCDUXA
  { 955,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #955 = QVSTFCDUXI
  { 956,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #956 = QVSTFCDUXIA
  { 957,	3,	0,	4,	59,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #957 = QVSTFCDX
  { 958,	3,	0,	4,	59,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #958 = QVSTFCDXA
  { 959,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #959 = QVSTFCDXI
  { 960,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #960 = QVSTFCDXIA
  { 961,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #961 = QVSTFCSUX
  { 962,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #962 = QVSTFCSUXA
  { 963,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #963 = QVSTFCSUXI
  { 964,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #964 = QVSTFCSUXIA
  { 965,	3,	0,	4,	59,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #965 = QVSTFCSX
  { 966,	3,	0,	4,	59,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #966 = QVSTFCSXA
  { 967,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #967 = QVSTFCSXI
  { 968,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #968 = QVSTFCSXIA
  { 969,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo131, -1 ,nullptr },  // Inst #969 = QVSTFCSXs
  { 970,	4,	1,	4,	60,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo136, -1 ,nullptr },  // Inst #970 = QVSTFDUX
  { 971,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #971 = QVSTFDUXA
  { 972,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #972 = QVSTFDUXI
  { 973,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #973 = QVSTFDUXIA
  { 974,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #974 = QVSTFDX
  { 975,	3,	0,	4,	59,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #975 = QVSTFDXA
  { 976,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #976 = QVSTFDXI
  { 977,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #977 = QVSTFDXIA
  { 978,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo133, -1 ,nullptr },  // Inst #978 = QVSTFDXb
  { 979,	3,	0,	4,	59,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #979 = QVSTFIWX
  { 980,	3,	0,	4,	59,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #980 = QVSTFIWXA
  { 981,	4,	1,	4,	60,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo137, -1 ,nullptr },  // Inst #981 = QVSTFSUX
  { 982,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #982 = QVSTFSUXA
  { 983,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #983 = QVSTFSUXI
  { 984,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #984 = QVSTFSUXIA
  { 985,	4,	1,	4,	60,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo136, -1 ,nullptr },  // Inst #985 = QVSTFSUXs
  { 986,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #986 = QVSTFSX
  { 987,	3,	0,	4,	59,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #987 = QVSTFSXA
  { 988,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #988 = QVSTFSXI
  { 989,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo130, -1 ,nullptr },  // Inst #989 = QVSTFSXIA
  { 990,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo131, -1 ,nullptr },  // Inst #990 = QVSTFSXs
  { 991,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo138, -1 ,nullptr },  // Inst #991 = RESTORE_CR
  { 992,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo139, -1 ,nullptr },  // Inst #992 = RESTORE_CRBIT
  { 993,	3,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo140, -1 ,nullptr },  // Inst #993 = RESTORE_VRSAVE
  { 994,	0,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #994 = RFCI
  { 995,	0,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #995 = RFDI
  { 996,	1,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #996 = RFEBB
  { 997,	0,	0,	4,	61,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #997 = RFI
  { 998,	0,	0,	4,	62,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #998 = RFID
  { 999,	0,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #999 = RFMCI
  { 1000,	4,	1,	4,	63,	0, 0x8ULL, nullptr, nullptr, OperandInfo141, -1 ,nullptr },  // Inst #1000 = RLDCL
  { 1001,	4,	1,	4,	63,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo141, -1 ,nullptr },  // Inst #1001 = RLDCLo
  { 1002,	4,	1,	4,	63,	0, 0x8ULL, nullptr, nullptr, OperandInfo141, -1 ,nullptr },  // Inst #1002 = RLDCR
  { 1003,	4,	1,	4,	63,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo141, -1 ,nullptr },  // Inst #1003 = RLDCRo
  { 1004,	4,	1,	4,	64,	0, 0x8ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #1004 = RLDIC
  { 1005,	4,	1,	4,	64,	0, 0x8ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #1005 = RLDICL
  { 1006,	4,	1,	4,	64,	0, 0x8ULL, nullptr, nullptr, OperandInfo142, -1 ,nullptr },  // Inst #1006 = RLDICL_32_64
  { 1007,	4,	1,	4,	64,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo33, -1 ,nullptr },  // Inst #1007 = RLDICLo
  { 1008,	4,	1,	4,	64,	0, 0x8ULL, nullptr, nullptr, OperandInfo33, -1 ,nullptr },  // Inst #1008 = RLDICR
  { 1009,	4,	1,	4,	64,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo33, -1 ,nullptr },  // Inst #1009 = RLDICRo
  { 1010,	4,	1,	4,	64,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo33, -1 ,nullptr },  // Inst #1010 = RLDICo
  { 1011,	5,	1,	4,	64,	0, 0x8ULL, nullptr, nullptr, OperandInfo143, -1 ,nullptr },  // Inst #1011 = RLDIMI
  { 1012,	5,	1,	4,	64,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo143, -1 ,nullptr },  // Inst #1012 = RLDIMIo
  { 1013,	6,	1,	4,	65,	0|(1ULL<<MCID::Commutable), 0xcULL, nullptr, nullptr, OperandInfo144, -1 ,nullptr },  // Inst #1013 = RLWIMI
  { 1014,	6,	1,	4,	65,	0, 0xcULL, nullptr, nullptr, OperandInfo145, -1 ,nullptr },  // Inst #1014 = RLWIMI8
  { 1015,	6,	1,	4,	65,	0, 0xcULL, nullptr, ImplicitList1, OperandInfo145, -1 ,nullptr },  // Inst #1015 = RLWIMI8o
  { 1016,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo146, -1 ,nullptr },  // Inst #1016 = RLWIMIbm
  { 1017,	6,	1,	4,	65,	0|(1ULL<<MCID::Commutable), 0xcULL, nullptr, ImplicitList1, OperandInfo144, -1 ,nullptr },  // Inst #1017 = RLWIMIo
  { 1018,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo146, -1 ,nullptr },  // Inst #1018 = RLWIMIobm
  { 1019,	5,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo147, -1 ,nullptr },  // Inst #1019 = RLWINM
  { 1020,	5,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo148, -1 ,nullptr },  // Inst #1020 = RLWINM8
  { 1021,	5,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo148, -1 ,nullptr },  // Inst #1021 = RLWINM8o
  { 1022,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo146, -1 ,nullptr },  // Inst #1022 = RLWINMbm
  { 1023,	5,	1,	4,	2,	0, 0xcULL, nullptr, ImplicitList1, OperandInfo147, -1 ,nullptr },  // Inst #1023 = RLWINMo
  { 1024,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo146, -1 ,nullptr },  // Inst #1024 = RLWINMobm
  { 1025,	5,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo149, -1 ,nullptr },  // Inst #1025 = RLWNM
  { 1026,	5,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo150, -1 ,nullptr },  // Inst #1026 = RLWNM8
  { 1027,	5,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo150, -1 ,nullptr },  // Inst #1027 = RLWNM8o
  { 1028,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo146, -1 ,nullptr },  // Inst #1028 = RLWNMbm
  { 1029,	5,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo149, -1 ,nullptr },  // Inst #1029 = RLWNMo
  { 1030,	4,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo146, -1 ,nullptr },  // Inst #1030 = RLWNMobm
  { 1031,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #1031 = ROTRDI
  { 1032,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #1032 = ROTRDIo
  { 1033,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1033 = ROTRWI
  { 1034,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1034 = ROTRWIo
  { 1035,	2,	2,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #1035 = ReadTB
  { 1036,	1,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, nullptr, nullptr, OperandInfo2, -1 ,nullptr },  // Inst #1036 = SC
  { 1037,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo151, -1 ,nullptr },  // Inst #1037 = SELECT_CC_F4
  { 1038,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo152, -1 ,nullptr },  // Inst #1038 = SELECT_CC_F8
  { 1039,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo153, -1 ,nullptr },  // Inst #1039 = SELECT_CC_I4
  { 1040,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo154, -1 ,nullptr },  // Inst #1040 = SELECT_CC_I8
  { 1041,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList13, nullptr, OperandInfo155, -1 ,nullptr },  // Inst #1041 = SELECT_CC_QBRC
  { 1042,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList13, nullptr, OperandInfo156, -1 ,nullptr },  // Inst #1042 = SELECT_CC_QFRC
  { 1043,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList13, nullptr, OperandInfo157, -1 ,nullptr },  // Inst #1043 = SELECT_CC_QSRC
  { 1044,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo158, -1 ,nullptr },  // Inst #1044 = SELECT_CC_VRRC
  { 1045,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo152, -1 ,nullptr },  // Inst #1045 = SELECT_CC_VSFRC
  { 1046,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo159, -1 ,nullptr },  // Inst #1046 = SELECT_CC_VSRC
  { 1047,	5,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x2ULL, nullptr, nullptr, OperandInfo151, -1 ,nullptr },  // Inst #1047 = SELECT_CC_VSSRC
  { 1048,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x2ULL, nullptr, nullptr, OperandInfo160, -1 ,nullptr },  // Inst #1048 = SELECT_F4
  { 1049,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x2ULL, nullptr, nullptr, OperandInfo161, -1 ,nullptr },  // Inst #1049 = SELECT_F8
  { 1050,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x2ULL, nullptr, nullptr, OperandInfo162, -1 ,nullptr },  // Inst #1050 = SELECT_I4
  { 1051,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x2ULL, nullptr, nullptr, OperandInfo163, -1 ,nullptr },  // Inst #1051 = SELECT_I8
  { 1052,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList13, nullptr, OperandInfo164, -1 ,nullptr },  // Inst #1052 = SELECT_QBRC
  { 1053,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList13, nullptr, OperandInfo165, -1 ,nullptr },  // Inst #1053 = SELECT_QFRC
  { 1054,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x0ULL, ImplicitList13, nullptr, OperandInfo166, -1 ,nullptr },  // Inst #1054 = SELECT_QSRC
  { 1055,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x2ULL, nullptr, nullptr, OperandInfo167, -1 ,nullptr },  // Inst #1055 = SELECT_VRRC
  { 1056,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x2ULL, nullptr, nullptr, OperandInfo161, -1 ,nullptr },  // Inst #1056 = SELECT_VSFRC
  { 1057,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x2ULL, nullptr, nullptr, OperandInfo168, -1 ,nullptr },  // Inst #1057 = SELECT_VSRC
  { 1058,	4,	1,	4,	0,	0|(1ULL<<MCID::UsesCustomInserter), 0x2ULL, nullptr, nullptr, OperandInfo160, -1 ,nullptr },  // Inst #1058 = SELECT_VSSRC
  { 1059,	0,	0,	4,	66,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #1059 = SLBIA
  { 1060,	1,	0,	4,	67,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #1060 = SLBIE
  { 1061,	2,	1,	4,	68,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #1061 = SLBMFEE
  { 1062,	2,	0,	4,	69,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #1062 = SLBMTE
  { 1063,	3,	1,	4,	63,	0, 0x8ULL, nullptr, nullptr, OperandInfo169, -1 ,nullptr },  // Inst #1063 = SLD
  { 1064,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #1064 = SLDI
  { 1065,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #1065 = SLDIo
  { 1066,	3,	1,	4,	63,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo169, -1 ,nullptr },  // Inst #1066 = SLDo
  { 1067,	3,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1067 = SLW
  { 1068,	3,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #1068 = SLW8
  { 1069,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #1069 = SLW8o
  { 1070,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1070 = SLWI
  { 1071,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1071 = SLWIo
  { 1072,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #1072 = SLWo
  { 1073,	3,	0,	4,	0,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo138, -1 ,nullptr },  // Inst #1073 = SPILL_CR
  { 1074,	3,	0,	4,	0,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo139, -1 ,nullptr },  // Inst #1074 = SPILL_CRBIT
  { 1075,	3,	0,	4,	0,	0|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo140, -1 ,nullptr },  // Inst #1075 = SPILL_VRSAVE
  { 1076,	3,	1,	4,	63,	0, 0x8ULL, nullptr, ImplicitList2, OperandInfo169, -1 ,nullptr },  // Inst #1076 = SRAD
  { 1077,	3,	1,	4,	64,	0, 0x8ULL, nullptr, ImplicitList2, OperandInfo15, -1 ,nullptr },  // Inst #1077 = SRADI
  { 1078,	3,	1,	4,	64,	0, 0x8ULL, nullptr, ImplicitList3, OperandInfo15, -1 ,nullptr },  // Inst #1078 = SRADIo
  { 1079,	3,	1,	4,	63,	0, 0x8ULL, nullptr, ImplicitList3, OperandInfo169, -1 ,nullptr },  // Inst #1079 = SRADo
  { 1080,	3,	1,	4,	70,	0, 0x8ULL, nullptr, ImplicitList2, OperandInfo12, -1 ,nullptr },  // Inst #1080 = SRAW
  { 1081,	3,	1,	4,	70,	0, 0x8ULL, nullptr, ImplicitList2, OperandInfo13, -1 ,nullptr },  // Inst #1081 = SRAWI
  { 1082,	3,	1,	4,	70,	0, 0x8ULL, nullptr, ImplicitList3, OperandInfo13, -1 ,nullptr },  // Inst #1082 = SRAWIo
  { 1083,	3,	1,	4,	70,	0, 0x8ULL, nullptr, ImplicitList3, OperandInfo12, -1 ,nullptr },  // Inst #1083 = SRAWo
  { 1084,	3,	1,	4,	63,	0, 0x8ULL, nullptr, nullptr, OperandInfo169, -1 ,nullptr },  // Inst #1084 = SRD
  { 1085,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #1085 = SRDI
  { 1086,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #1086 = SRDIo
  { 1087,	3,	1,	4,	63,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo169, -1 ,nullptr },  // Inst #1087 = SRDo
  { 1088,	3,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1088 = SRW
  { 1089,	3,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #1089 = SRW8
  { 1090,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #1090 = SRW8o
  { 1091,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1091 = SRWI
  { 1092,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1092 = SRWIo
  { 1093,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #1093 = SRWo
  { 1094,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #1094 = STB
  { 1095,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #1095 = STB8
  { 1096,	3,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1096 = STBCIX
  { 1097,	3,	0,	4,	71,	0|(1ULL<<MCID::MayStore), 0x0ULL, nullptr, ImplicitList1, OperandInfo65, -1 ,nullptr },  // Inst #1097 = STBCX
  { 1098,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo170, -1 ,nullptr },  // Inst #1098 = STBU
  { 1099,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo171, -1 ,nullptr },  // Inst #1099 = STBU8
  { 1100,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo172, -1 ,nullptr },  // Inst #1100 = STBUX
  { 1101,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo173, -1 ,nullptr },  // Inst #1101 = STBUX8
  { 1102,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #1102 = STBX
  { 1103,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #1103 = STBX8
  { 1104,	3,	0,	4,	73,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #1104 = STD
  { 1105,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #1105 = STDBRX
  { 1106,	3,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1106 = STDCIX
  { 1107,	3,	0,	4,	74,	0|(1ULL<<MCID::MayStore), 0x0ULL, nullptr, ImplicitList1, OperandInfo71, -1 ,nullptr },  // Inst #1107 = STDCX
  { 1108,	4,	1,	4,	75,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo171, -1 ,nullptr },  // Inst #1108 = STDU
  { 1109,	4,	1,	4,	76,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo173, -1 ,nullptr },  // Inst #1109 = STDUX
  { 1110,	3,	0,	4,	73,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #1110 = STDX
  { 1111,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo75, -1 ,nullptr },  // Inst #1111 = STFD
  { 1112,	4,	1,	4,	60,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo174, -1 ,nullptr },  // Inst #1112 = STFDU
  { 1113,	4,	1,	4,	60,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo175, -1 ,nullptr },  // Inst #1113 = STFDUX
  { 1114,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo78, -1 ,nullptr },  // Inst #1114 = STFDX
  { 1115,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo78, -1 ,nullptr },  // Inst #1115 = STFIWX
  { 1116,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo79, -1 ,nullptr },  // Inst #1116 = STFS
  { 1117,	4,	1,	4,	60,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo176, -1 ,nullptr },  // Inst #1117 = STFSU
  { 1118,	4,	1,	4,	60,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo177, -1 ,nullptr },  // Inst #1118 = STFSUX
  { 1119,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo82, -1 ,nullptr },  // Inst #1119 = STFSX
  { 1120,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #1120 = STH
  { 1121,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #1121 = STH8
  { 1122,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #1122 = STHBRX
  { 1123,	3,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1123 = STHCIX
  { 1124,	3,	0,	4,	71,	0|(1ULL<<MCID::MayStore), 0x0ULL, nullptr, ImplicitList1, OperandInfo65, -1 ,nullptr },  // Inst #1124 = STHCX
  { 1125,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo170, -1 ,nullptr },  // Inst #1125 = STHU
  { 1126,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo171, -1 ,nullptr },  // Inst #1126 = STHU8
  { 1127,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo172, -1 ,nullptr },  // Inst #1127 = STHUX
  { 1128,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo173, -1 ,nullptr },  // Inst #1128 = STHUX8
  { 1129,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #1129 = STHX
  { 1130,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #1130 = STHX8
  { 1131,	3,	0,	4,	35,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #1131 = STMW
  { 1132,	3,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1132 = STSWI
  { 1133,	3,	0,	4,	45,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #1133 = STVEBX
  { 1134,	3,	0,	4,	45,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #1134 = STVEHX
  { 1135,	3,	0,	4,	45,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #1135 = STVEWX
  { 1136,	3,	0,	4,	45,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #1136 = STVX
  { 1137,	3,	0,	4,	45,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo85, -1 ,nullptr },  // Inst #1137 = STVXL
  { 1138,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo49, -1 ,nullptr },  // Inst #1138 = STW
  { 1139,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo66, -1 ,nullptr },  // Inst #1139 = STW8
  { 1140,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #1140 = STWBRX
  { 1141,	3,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1141 = STWCIX
  { 1142,	3,	0,	4,	71,	0|(1ULL<<MCID::MayStore), 0x0ULL, nullptr, ImplicitList1, OperandInfo65, -1 ,nullptr },  // Inst #1142 = STWCX
  { 1143,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo170, -1 ,nullptr },  // Inst #1143 = STWU
  { 1144,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x10ULL, nullptr, nullptr, OperandInfo171, -1 ,nullptr },  // Inst #1144 = STWU8
  { 1145,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo172, -1 ,nullptr },  // Inst #1145 = STWUX
  { 1146,	4,	1,	4,	72,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo173, -1 ,nullptr },  // Inst #1146 = STWUX8
  { 1147,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo65, -1 ,nullptr },  // Inst #1147 = STWX
  { 1148,	3,	0,	4,	45,	0|(1ULL<<MCID::MayStore), 0x14ULL, nullptr, nullptr, OperandInfo71, -1 ,nullptr },  // Inst #1148 = STWX8
  { 1149,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo86, -1 ,nullptr },  // Inst #1149 = STXSDX
  { 1150,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, nullptr, nullptr, OperandInfo86, -1 ,nullptr },  // Inst #1150 = STXSIWX
  { 1151,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, nullptr, nullptr, OperandInfo87, -1 ,nullptr },  // Inst #1151 = STXSSPX
  { 1152,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo88, -1 ,nullptr },  // Inst #1152 = STXVD2X
  { 1153,	3,	0,	4,	59,	0|(1ULL<<MCID::MayStore), 0x0ULL, ImplicitList13, nullptr, OperandInfo88, -1 ,nullptr },  // Inst #1153 = STXVW4X
  { 1154,	3,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1154 = SUBF
  { 1155,	3,	1,	4,	2,	0, 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #1155 = SUBF8
  { 1156,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #1156 = SUBF8o
  { 1157,	3,	1,	4,	2,	0, 0xcULL, nullptr, ImplicitList2, OperandInfo12, -1 ,nullptr },  // Inst #1157 = SUBFC
  { 1158,	3,	1,	4,	2,	0, 0xcULL, nullptr, ImplicitList2, OperandInfo14, -1 ,nullptr },  // Inst #1158 = SUBFC8
  { 1159,	3,	1,	4,	2,	0, 0xcULL, nullptr, ImplicitList2, OperandInfo14, -1 ,nullptr },  // Inst #1159 = SUBFC8o
  { 1160,	3,	1,	4,	2,	0, 0xcULL, nullptr, ImplicitList3, OperandInfo12, -1 ,nullptr },  // Inst #1160 = SUBFCo
  { 1161,	3,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo12, -1 ,nullptr },  // Inst #1161 = SUBFE
  { 1162,	3,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo14, -1 ,nullptr },  // Inst #1162 = SUBFE8
  { 1163,	3,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo14, -1 ,nullptr },  // Inst #1163 = SUBFE8o
  { 1164,	3,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo12, -1 ,nullptr },  // Inst #1164 = SUBFEo
  { 1165,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList2, OperandInfo13, -1 ,nullptr },  // Inst #1165 = SUBFIC
  { 1166,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList2, OperandInfo15, -1 ,nullptr },  // Inst #1166 = SUBFIC8
  { 1167,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo20, -1 ,nullptr },  // Inst #1167 = SUBFME
  { 1168,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo21, -1 ,nullptr },  // Inst #1168 = SUBFME8
  { 1169,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo21, -1 ,nullptr },  // Inst #1169 = SUBFME8o
  { 1170,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo20, -1 ,nullptr },  // Inst #1170 = SUBFMEo
  { 1171,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo20, -1 ,nullptr },  // Inst #1171 = SUBFZE
  { 1172,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList2, OperandInfo21, -1 ,nullptr },  // Inst #1172 = SUBFZE8
  { 1173,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo21, -1 ,nullptr },  // Inst #1173 = SUBFZE8o
  { 1174,	2,	1,	4,	2,	0, 0x8ULL, ImplicitList2, ImplicitList3, OperandInfo20, -1 ,nullptr },  // Inst #1174 = SUBFZEo
  { 1175,	3,	1,	4,	2,	0, 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #1175 = SUBFo
  { 1176,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1176 = SUBI
  { 1177,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1177 = SUBIC
  { 1178,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1178 = SUBICo
  { 1179,	3,	0,	0,	0,	0|(1ULL<<MCID::Pseudo)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1179 = SUBIS
  { 1180,	1,	0,	4,	47,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo2, -1 ,nullptr },  // Inst #1180 = SYNC
  { 1181,	2,	1,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo178, -1 ,nullptr },  // Inst #1181 = TABORT
  { 1182,	4,	1,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo179, -1 ,nullptr },  // Inst #1182 = TABORTDC
  { 1183,	4,	1,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo180, -1 ,nullptr },  // Inst #1183 = TABORTDCI
  { 1184,	4,	1,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo179, -1 ,nullptr },  // Inst #1184 = TABORTWC
  { 1185,	4,	1,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo180, -1 ,nullptr },  // Inst #1185 = TABORTWCI
  { 1186,	1,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #1186 = TAILB
  { 1187,	1,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #1187 = TAILB8
  { 1188,	1,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #1188 = TAILBA
  { 1189,	1,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList13, nullptr, OperandInfo5, -1 ,nullptr },  // Inst #1189 = TAILBA8
  { 1190,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, nullptr, nullptr, -1 ,nullptr },  // Inst #1190 = TAILBCTR
  { 1191,	0,	0,	4,	3,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Branch)|(1ULL<<MCID::IndirectBranch)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList11, nullptr, nullptr, -1 ,nullptr },  // Inst #1191 = TAILBCTR8
  { 1192,	2,	1,	4,	49,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo181, -1 ,nullptr },  // Inst #1192 = TBEGIN
  { 1193,	1,	0,	4,	49,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo182, -1 ,nullptr },  // Inst #1193 = TCHECK
  { 1194,	1,	1,	4,	0,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UsesCustomInserter)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo182, -1 ,nullptr },  // Inst #1194 = TCHECK_RET
  { 1195,	2,	0,	4,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator), 0x0ULL, ImplicitList13, nullptr, OperandInfo183, -1 ,nullptr },  // Inst #1195 = TCRETURNai
  { 1196,	2,	0,	4,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator), 0x0ULL, ImplicitList13, nullptr, OperandInfo183, -1 ,nullptr },  // Inst #1196 = TCRETURNai8
  { 1197,	2,	0,	4,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator), 0x0ULL, ImplicitList13, nullptr, OperandInfo183, -1 ,nullptr },  // Inst #1197 = TCRETURNdi
  { 1198,	2,	0,	4,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator), 0x0ULL, ImplicitList13, nullptr, OperandInfo183, -1 ,nullptr },  // Inst #1198 = TCRETURNdi8
  { 1199,	2,	0,	4,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator), 0x0ULL, ImplicitList13, nullptr, OperandInfo184, -1 ,nullptr },  // Inst #1199 = TCRETURNri
  { 1200,	2,	0,	4,	0,	0|(1ULL<<MCID::Return)|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Call)|(1ULL<<MCID::Terminator), 0x0ULL, ImplicitList13, nullptr, OperandInfo185, -1 ,nullptr },  // Inst #1200 = TCRETURNri8
  { 1201,	3,	0,	4,	77,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo186, -1 ,nullptr },  // Inst #1201 = TD
  { 1202,	3,	0,	4,	77,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo187, -1 ,nullptr },  // Inst #1202 = TDI
  { 1203,	2,	1,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo181, -1 ,nullptr },  // Inst #1203 = TEND
  { 1204,	0,	0,	4,	78,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #1204 = TLBIA
  { 1205,	2,	0,	4,	79,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #1205 = TLBIE
  { 1206,	1,	0,	4,	80,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #1206 = TLBIEL
  { 1207,	2,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #1207 = TLBIVAX
  { 1208,	1,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #1208 = TLBLD
  { 1209,	1,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #1209 = TLBLI
  { 1210,	0,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #1210 = TLBRE
  { 1211,	3,	1,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo188, -1 ,nullptr },  // Inst #1211 = TLBRE2
  { 1212,	2,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #1212 = TLBSX
  { 1213,	3,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1213 = TLBSX2
  { 1214,	3,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1214 = TLBSX2D
  { 1215,	0,	0,	4,	81,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #1215 = TLBSYNC
  { 1216,	0,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #1216 = TLBWE
  { 1217,	3,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo188, -1 ,nullptr },  // Inst #1217 = TLBWE2
  { 1218,	0,	0,	4,	8,	0|(1ULL<<MCID::Barrier)|(1ULL<<MCID::Terminator)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, nullptr, -1 ,nullptr },  // Inst #1218 = TRAP
  { 1219,	1,	1,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo182, -1 ,nullptr },  // Inst #1219 = TRECHKPT
  { 1220,	2,	1,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo189, -1 ,nullptr },  // Inst #1220 = TRECLAIM
  { 1221,	2,	1,	4,	49,	0|(1ULL<<MCID::MayLoad)|(1ULL<<MCID::MayStore)|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo181, -1 ,nullptr },  // Inst #1221 = TSR
  { 1222,	3,	0,	4,	82,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo43, -1 ,nullptr },  // Inst #1222 = TW
  { 1223,	3,	0,	4,	82,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo190, -1 ,nullptr },  // Inst #1223 = TWI
  { 1224,	2,	1,	4,	0,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo20, -1 ,nullptr },  // Inst #1224 = UPDATE_VRSAVE
  { 1225,	3,	2,	4,	0,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1225 = UpdateGBR
  { 1226,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1226 = VADDCUQ
  { 1227,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1227 = VADDCUW
  { 1228,	4,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1228 = VADDECUQ
  { 1229,	4,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1229 = VADDEUQM
  { 1230,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1230 = VADDFP
  { 1231,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1231 = VADDSBS
  { 1232,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1232 = VADDSHS
  { 1233,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1233 = VADDSWS
  { 1234,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1234 = VADDUBM
  { 1235,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1235 = VADDUBS
  { 1236,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1236 = VADDUDM
  { 1237,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1237 = VADDUHM
  { 1238,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1238 = VADDUHS
  { 1239,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1239 = VADDUQM
  { 1240,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1240 = VADDUWM
  { 1241,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1241 = VADDUWS
  { 1242,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1242 = VAND
  { 1243,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1243 = VANDC
  { 1244,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1244 = VAVGSB
  { 1245,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1245 = VAVGSH
  { 1246,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1246 = VAVGSW
  { 1247,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1247 = VAVGUB
  { 1248,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1248 = VAVGUH
  { 1249,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1249 = VAVGUW
  { 1250,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1250 = VBPERMQ
  { 1251,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo193, -1 ,nullptr },  // Inst #1251 = VCFSX
  { 1252,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1252 = VCFSX_0
  { 1253,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo193, -1 ,nullptr },  // Inst #1253 = VCFUX
  { 1254,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1254 = VCFUX_0
  { 1255,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1255 = VCIPHER
  { 1256,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1256 = VCIPHERLAST
  { 1257,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1257 = VCLZB
  { 1258,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1258 = VCLZD
  { 1259,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1259 = VCLZH
  { 1260,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1260 = VCLZW
  { 1261,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1261 = VCMPBFP
  { 1262,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1262 = VCMPBFPo
  { 1263,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1263 = VCMPEQFP
  { 1264,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1264 = VCMPEQFPo
  { 1265,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1265 = VCMPEQUB
  { 1266,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1266 = VCMPEQUBo
  { 1267,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1267 = VCMPEQUD
  { 1268,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1268 = VCMPEQUDo
  { 1269,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1269 = VCMPEQUH
  { 1270,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1270 = VCMPEQUHo
  { 1271,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1271 = VCMPEQUW
  { 1272,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1272 = VCMPEQUWo
  { 1273,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1273 = VCMPGEFP
  { 1274,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1274 = VCMPGEFPo
  { 1275,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1275 = VCMPGTFP
  { 1276,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1276 = VCMPGTFPo
  { 1277,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1277 = VCMPGTSB
  { 1278,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1278 = VCMPGTSBo
  { 1279,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1279 = VCMPGTSD
  { 1280,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1280 = VCMPGTSDo
  { 1281,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1281 = VCMPGTSH
  { 1282,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1282 = VCMPGTSHo
  { 1283,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1283 = VCMPGTSW
  { 1284,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1284 = VCMPGTSWo
  { 1285,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1285 = VCMPGTUB
  { 1286,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1286 = VCMPGTUBo
  { 1287,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1287 = VCMPGTUD
  { 1288,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1288 = VCMPGTUDo
  { 1289,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1289 = VCMPGTUH
  { 1290,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1290 = VCMPGTUHo
  { 1291,	3,	1,	4,	83,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1291 = VCMPGTUW
  { 1292,	3,	1,	4,	83,	0, 0x28ULL, nullptr, ImplicitList24, OperandInfo191, -1 ,nullptr },  // Inst #1292 = VCMPGTUWo
  { 1293,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo193, -1 ,nullptr },  // Inst #1293 = VCTSXS
  { 1294,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1294 = VCTSXS_0
  { 1295,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo193, -1 ,nullptr },  // Inst #1295 = VCTUXS
  { 1296,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1296 = VCTUXS_0
  { 1297,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1297 = VEQV
  { 1298,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1298 = VEXPTEFP
  { 1299,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1299 = VGBBD
  { 1300,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1300 = VLOGEFP
  { 1301,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1301 = VMADDFP
  { 1302,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1302 = VMAXFP
  { 1303,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1303 = VMAXSB
  { 1304,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1304 = VMAXSD
  { 1305,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1305 = VMAXSH
  { 1306,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1306 = VMAXSW
  { 1307,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1307 = VMAXUB
  { 1308,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1308 = VMAXUD
  { 1309,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1309 = VMAXUH
  { 1310,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1310 = VMAXUW
  { 1311,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1311 = VMHADDSHS
  { 1312,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1312 = VMHRADDSHS
  { 1313,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1313 = VMINFP
  { 1314,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1314 = VMINSB
  { 1315,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1315 = VMINSD
  { 1316,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1316 = VMINSH
  { 1317,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1317 = VMINSW
  { 1318,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1318 = VMINUB
  { 1319,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1319 = VMINUD
  { 1320,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1320 = VMINUH
  { 1321,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1321 = VMINUW
  { 1322,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1322 = VMLADDUHM
  { 1323,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1323 = VMRGEW
  { 1324,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1324 = VMRGHB
  { 1325,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1325 = VMRGHH
  { 1326,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1326 = VMRGHW
  { 1327,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1327 = VMRGLB
  { 1328,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1328 = VMRGLH
  { 1329,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1329 = VMRGLW
  { 1330,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1330 = VMRGOW
  { 1331,	4,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1331 = VMSUMMBM
  { 1332,	4,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1332 = VMSUMSHM
  { 1333,	4,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1333 = VMSUMSHS
  { 1334,	4,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1334 = VMSUMUBM
  { 1335,	4,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1335 = VMSUMUHM
  { 1336,	4,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1336 = VMSUMUHS
  { 1337,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1337 = VMULESB
  { 1338,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1338 = VMULESH
  { 1339,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1339 = VMULESW
  { 1340,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1340 = VMULEUB
  { 1341,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1341 = VMULEUH
  { 1342,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1342 = VMULEUW
  { 1343,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1343 = VMULOSB
  { 1344,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1344 = VMULOSH
  { 1345,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1345 = VMULOSW
  { 1346,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1346 = VMULOUB
  { 1347,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1347 = VMULOUH
  { 1348,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1348 = VMULOUW
  { 1349,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1349 = VMULUWM
  { 1350,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1350 = VNAND
  { 1351,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1351 = VNCIPHER
  { 1352,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1352 = VNCIPHERLAST
  { 1353,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1353 = VNMSUBFP
  { 1354,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1354 = VNOR
  { 1355,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1355 = VOR
  { 1356,	3,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1356 = VORC
  { 1357,	4,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1357 = VPERM
  { 1358,	4,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1358 = VPERMXOR
  { 1359,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1359 = VPKPX
  { 1360,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1360 = VPKSDSS
  { 1361,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1361 = VPKSDUS
  { 1362,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1362 = VPKSHSS
  { 1363,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1363 = VPKSHUS
  { 1364,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1364 = VPKSWSS
  { 1365,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1365 = VPKSWUS
  { 1366,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1366 = VPKUDUM
  { 1367,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1367 = VPKUDUS
  { 1368,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1368 = VPKUHUM
  { 1369,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1369 = VPKUHUS
  { 1370,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1370 = VPKUWUM
  { 1371,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1371 = VPKUWUS
  { 1372,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1372 = VPMSUMB
  { 1373,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1373 = VPMSUMD
  { 1374,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1374 = VPMSUMH
  { 1375,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1375 = VPMSUMW
  { 1376,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1376 = VPOPCNTB
  { 1377,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1377 = VPOPCNTD
  { 1378,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1378 = VPOPCNTH
  { 1379,	2,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1379 = VPOPCNTW
  { 1380,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1380 = VREFP
  { 1381,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1381 = VRFIM
  { 1382,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1382 = VRFIN
  { 1383,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1383 = VRFIP
  { 1384,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1384 = VRFIZ
  { 1385,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1385 = VRLB
  { 1386,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1386 = VRLD
  { 1387,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1387 = VRLH
  { 1388,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1388 = VRLW
  { 1389,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1389 = VRSQRTEFP
  { 1390,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1390 = VSBOX
  { 1391,	4,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1391 = VSEL
  { 1392,	4,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo195, -1 ,nullptr },  // Inst #1392 = VSHASIGMAD
  { 1393,	4,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo195, -1 ,nullptr },  // Inst #1393 = VSHASIGMAW
  { 1394,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1394 = VSL
  { 1395,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1395 = VSLB
  { 1396,	3,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1396 = VSLD
  { 1397,	4,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo196, -1 ,nullptr },  // Inst #1397 = VSLDOI
  { 1398,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1398 = VSLH
  { 1399,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1399 = VSLO
  { 1400,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1400 = VSLW
  { 1401,	3,	1,	4,	58,	0, 0x28ULL, nullptr, nullptr, OperandInfo193, -1 ,nullptr },  // Inst #1401 = VSPLTB
  { 1402,	3,	1,	4,	58,	0, 0x28ULL, nullptr, nullptr, OperandInfo193, -1 ,nullptr },  // Inst #1402 = VSPLTH
  { 1403,	2,	1,	4,	58,	0, 0x28ULL, nullptr, nullptr, OperandInfo197, -1 ,nullptr },  // Inst #1403 = VSPLTISB
  { 1404,	2,	1,	4,	58,	0, 0x28ULL, nullptr, nullptr, OperandInfo197, -1 ,nullptr },  // Inst #1404 = VSPLTISH
  { 1405,	2,	1,	4,	58,	0, 0x28ULL, nullptr, nullptr, OperandInfo197, -1 ,nullptr },  // Inst #1405 = VSPLTISW
  { 1406,	3,	1,	4,	58,	0, 0x28ULL, nullptr, nullptr, OperandInfo193, -1 ,nullptr },  // Inst #1406 = VSPLTW
  { 1407,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1407 = VSR
  { 1408,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1408 = VSRAB
  { 1409,	3,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1409 = VSRAD
  { 1410,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1410 = VSRAH
  { 1411,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1411 = VSRAW
  { 1412,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1412 = VSRB
  { 1413,	3,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1413 = VSRD
  { 1414,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1414 = VSRH
  { 1415,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1415 = VSRO
  { 1416,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1416 = VSRW
  { 1417,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1417 = VSUBCUQ
  { 1418,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1418 = VSUBCUW
  { 1419,	4,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1419 = VSUBECUQ
  { 1420,	4,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo192, -1 ,nullptr },  // Inst #1420 = VSUBEUQM
  { 1421,	3,	1,	4,	46,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1421 = VSUBFP
  { 1422,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1422 = VSUBSBS
  { 1423,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1423 = VSUBSHS
  { 1424,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1424 = VSUBSWS
  { 1425,	3,	1,	4,	46,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1425 = VSUBUBM
  { 1426,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1426 = VSUBUBS
  { 1427,	3,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1427 = VSUBUDM
  { 1428,	3,	1,	4,	46,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1428 = VSUBUHM
  { 1429,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1429 = VSUBUHS
  { 1430,	3,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1430 = VSUBUQM
  { 1431,	3,	1,	4,	46,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1431 = VSUBUWM
  { 1432,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1432 = VSUBUWS
  { 1433,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1433 = VSUM2SWS
  { 1434,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1434 = VSUM4SBS
  { 1435,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1435 = VSUM4SHS
  { 1436,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1436 = VSUM4UBS
  { 1437,	3,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1437 = VSUMSWS
  { 1438,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1438 = VUPKHPX
  { 1439,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1439 = VUPKHSB
  { 1440,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1440 = VUPKHSH
  { 1441,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1441 = VUPKHSW
  { 1442,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1442 = VUPKLPX
  { 1443,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1443 = VUPKLSB
  { 1444,	2,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1444 = VUPKLSH
  { 1445,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo194, -1 ,nullptr },  // Inst #1445 = VUPKLSW
  { 1446,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x28ULL, nullptr, nullptr, OperandInfo191, -1 ,nullptr },  // Inst #1446 = VXOR
  { 1447,	1,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo96, -1 ,nullptr },  // Inst #1447 = V_SET0
  { 1448,	1,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo96, -1 ,nullptr },  // Inst #1448 = V_SET0B
  { 1449,	1,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo96, -1 ,nullptr },  // Inst #1449 = V_SET0H
  { 1450,	1,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo96, -1 ,nullptr },  // Inst #1450 = V_SETALLONES
  { 1451,	1,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo96, -1 ,nullptr },  // Inst #1451 = V_SETALLONESB
  { 1452,	1,	1,	4,	4,	0, 0x28ULL, nullptr, nullptr, OperandInfo96, -1 ,nullptr },  // Inst #1452 = V_SETALLONESH
  { 1453,	1,	0,	4,	8,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo2, -1 ,nullptr },  // Inst #1453 = WAIT
  { 1454,	1,	0,	4,	51,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo91, -1 ,nullptr },  // Inst #1454 = WRTEE
  { 1455,	1,	0,	4,	51,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo2, -1 ,nullptr },  // Inst #1455 = WRTEEI
  { 1456,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo12, -1 ,nullptr },  // Inst #1456 = XOR
  { 1457,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, nullptr, OperandInfo14, -1 ,nullptr },  // Inst #1457 = XOR8
  { 1458,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo14, -1 ,nullptr },  // Inst #1458 = XOR8o
  { 1459,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1459 = XORI
  { 1460,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #1460 = XORI8
  { 1461,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo13, -1 ,nullptr },  // Inst #1461 = XORIS
  { 1462,	3,	1,	4,	1,	0, 0x8ULL, nullptr, nullptr, OperandInfo15, -1 ,nullptr },  // Inst #1462 = XORIS8
  { 1463,	3,	1,	4,	1,	0|(1ULL<<MCID::Commutable), 0x8ULL, nullptr, ImplicitList1, OperandInfo12, -1 ,nullptr },  // Inst #1463 = XORo
  { 1464,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1464 = XSABSDP
  { 1465,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo199, -1 ,nullptr },  // Inst #1465 = XSADDDP
  { 1466,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo200, -1 ,nullptr },  // Inst #1466 = XSADDSP
  { 1467,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo201, -1 ,nullptr },  // Inst #1467 = XSCMPODP
  { 1468,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo201, -1 ,nullptr },  // Inst #1468 = XSCMPUDP
  { 1469,	3,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo199, -1 ,nullptr },  // Inst #1469 = XSCPSGNDP
  { 1470,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1470 = XSCVDPSP
  { 1471,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo202, -1 ,nullptr },  // Inst #1471 = XSCVDPSPN
  { 1472,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1472 = XSCVDPSXDS
  { 1473,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1473 = XSCVDPSXWS
  { 1474,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1474 = XSCVDPUXDS
  { 1475,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1475 = XSCVDPUXWS
  { 1476,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1476 = XSCVSPDP
  { 1477,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo203, -1 ,nullptr },  // Inst #1477 = XSCVSPDPN
  { 1478,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1478 = XSCVSXDDP
  { 1479,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo204, -1 ,nullptr },  // Inst #1479 = XSCVSXDSP
  { 1480,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1480 = XSCVUXDDP
  { 1481,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo204, -1 ,nullptr },  // Inst #1481 = XSCVUXDSP
  { 1482,	3,	1,	4,	14,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo199, -1 ,nullptr },  // Inst #1482 = XSDIVDP
  { 1483,	3,	1,	4,	15,	0, 0x0ULL, nullptr, nullptr, OperandInfo200, -1 ,nullptr },  // Inst #1483 = XSDIVSP
  { 1484,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo205, -1 ,nullptr },  // Inst #1484 = XSMADDADP
  { 1485,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo206, -1 ,nullptr },  // Inst #1485 = XSMADDASP
  { 1486,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo205, -1 ,nullptr },  // Inst #1486 = XSMADDMDP
  { 1487,	4,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo206, -1 ,nullptr },  // Inst #1487 = XSMADDMSP
  { 1488,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo199, -1 ,nullptr },  // Inst #1488 = XSMAXDP
  { 1489,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo199, -1 ,nullptr },  // Inst #1489 = XSMINDP
  { 1490,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo205, -1 ,nullptr },  // Inst #1490 = XSMSUBADP
  { 1491,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo206, -1 ,nullptr },  // Inst #1491 = XSMSUBASP
  { 1492,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo205, -1 ,nullptr },  // Inst #1492 = XSMSUBMDP
  { 1493,	4,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo206, -1 ,nullptr },  // Inst #1493 = XSMSUBMSP
  { 1494,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo199, -1 ,nullptr },  // Inst #1494 = XSMULDP
  { 1495,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo200, -1 ,nullptr },  // Inst #1495 = XSMULSP
  { 1496,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1496 = XSNABSDP
  { 1497,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1497 = XSNEGDP
  { 1498,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo205, -1 ,nullptr },  // Inst #1498 = XSNMADDADP
  { 1499,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo206, -1 ,nullptr },  // Inst #1499 = XSNMADDASP
  { 1500,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo205, -1 ,nullptr },  // Inst #1500 = XSNMADDMDP
  { 1501,	4,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo206, -1 ,nullptr },  // Inst #1501 = XSNMADDMSP
  { 1502,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo205, -1 ,nullptr },  // Inst #1502 = XSNMSUBADP
  { 1503,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo206, -1 ,nullptr },  // Inst #1503 = XSNMSUBASP
  { 1504,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo205, -1 ,nullptr },  // Inst #1504 = XSNMSUBMDP
  { 1505,	4,	1,	4,	4,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x0ULL, nullptr, nullptr, OperandInfo206, -1 ,nullptr },  // Inst #1505 = XSNMSUBMSP
  { 1506,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1506 = XSRDPI
  { 1507,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1507 = XSRDPIC
  { 1508,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1508 = XSRDPIM
  { 1509,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1509 = XSRDPIP
  { 1510,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1510 = XSRDPIZ
  { 1511,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1511 = XSREDP
  { 1512,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo207, -1 ,nullptr },  // Inst #1512 = XSRESP
  { 1513,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1513 = XSRSQRTEDP
  { 1514,	2,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo207, -1 ,nullptr },  // Inst #1514 = XSRSQRTESP
  { 1515,	2,	1,	4,	17,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo198, -1 ,nullptr },  // Inst #1515 = XSSQRTDP
  { 1516,	2,	1,	4,	18,	0, 0x0ULL, nullptr, nullptr, OperandInfo207, -1 ,nullptr },  // Inst #1516 = XSSQRTSP
  { 1517,	3,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo199, -1 ,nullptr },  // Inst #1517 = XSSUBDP
  { 1518,	3,	1,	4,	4,	0, 0x0ULL, nullptr, nullptr, OperandInfo200, -1 ,nullptr },  // Inst #1518 = XSSUBSP
  { 1519,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo201, -1 ,nullptr },  // Inst #1519 = XSTDIVDP
  { 1520,	2,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo208, -1 ,nullptr },  // Inst #1520 = XSTSQRTDP
  { 1521,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1521 = XVABSDP
  { 1522,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1522 = XVABSSP
  { 1523,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1523 = XVADDDP
  { 1524,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1524 = XVADDSP
  { 1525,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1525 = XVCMPEQDP
  { 1526,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, ImplicitList24, OperandInfo210, -1 ,nullptr },  // Inst #1526 = XVCMPEQDPo
  { 1527,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1527 = XVCMPEQSP
  { 1528,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, ImplicitList24, OperandInfo210, -1 ,nullptr },  // Inst #1528 = XVCMPEQSPo
  { 1529,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1529 = XVCMPGEDP
  { 1530,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, ImplicitList24, OperandInfo210, -1 ,nullptr },  // Inst #1530 = XVCMPGEDPo
  { 1531,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1531 = XVCMPGESP
  { 1532,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, ImplicitList24, OperandInfo210, -1 ,nullptr },  // Inst #1532 = XVCMPGESPo
  { 1533,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1533 = XVCMPGTDP
  { 1534,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, ImplicitList24, OperandInfo210, -1 ,nullptr },  // Inst #1534 = XVCMPGTDPo
  { 1535,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1535 = XVCMPGTSP
  { 1536,	3,	1,	4,	83,	0, 0x0ULL, ImplicitList13, ImplicitList24, OperandInfo210, -1 ,nullptr },  // Inst #1536 = XVCMPGTSPo
  { 1537,	3,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1537 = XVCPSGNDP
  { 1538,	3,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1538 = XVCPSGNSP
  { 1539,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1539 = XVCVDPSP
  { 1540,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1540 = XVCVDPSXDS
  { 1541,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1541 = XVCVDPSXWS
  { 1542,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1542 = XVCVDPUXDS
  { 1543,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1543 = XVCVDPUXWS
  { 1544,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1544 = XVCVSPDP
  { 1545,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1545 = XVCVSPSXDS
  { 1546,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1546 = XVCVSPSXWS
  { 1547,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1547 = XVCVSPUXDS
  { 1548,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1548 = XVCVSPUXWS
  { 1549,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1549 = XVCVSXDDP
  { 1550,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1550 = XVCVSXDSP
  { 1551,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1551 = XVCVSXWDP
  { 1552,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1552 = XVCVSXWSP
  { 1553,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1553 = XVCVUXDDP
  { 1554,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1554 = XVCVUXDSP
  { 1555,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1555 = XVCVUXWDP
  { 1556,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1556 = XVCVUXWSP
  { 1557,	3,	1,	4,	14,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1557 = XVDIVDP
  { 1558,	3,	1,	4,	15,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1558 = XVDIVSP
  { 1559,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1559 = XVMADDADP
  { 1560,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1560 = XVMADDASP
  { 1561,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1561 = XVMADDMDP
  { 1562,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1562 = XVMADDMSP
  { 1563,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1563 = XVMAXDP
  { 1564,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1564 = XVMAXSP
  { 1565,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1565 = XVMINDP
  { 1566,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1566 = XVMINSP
  { 1567,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1567 = XVMSUBADP
  { 1568,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1568 = XVMSUBASP
  { 1569,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1569 = XVMSUBMDP
  { 1570,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1570 = XVMSUBMSP
  { 1571,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1571 = XVMULDP
  { 1572,	3,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1572 = XVMULSP
  { 1573,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1573 = XVNABSDP
  { 1574,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1574 = XVNABSSP
  { 1575,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1575 = XVNEGDP
  { 1576,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1576 = XVNEGSP
  { 1577,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1577 = XVNMADDADP
  { 1578,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1578 = XVNMADDASP
  { 1579,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1579 = XVNMADDMDP
  { 1580,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1580 = XVNMADDMSP
  { 1581,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1581 = XVNMSUBADP
  { 1582,	4,	1,	4,	4,	0|(1ULL<<MCID::Commutable), 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1582 = XVNMSUBASP
  { 1583,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1583 = XVNMSUBMDP
  { 1584,	4,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo211, -1 ,nullptr },  // Inst #1584 = XVNMSUBMSP
  { 1585,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1585 = XVRDPI
  { 1586,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1586 = XVRDPIC
  { 1587,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1587 = XVRDPIM
  { 1588,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1588 = XVRDPIP
  { 1589,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1589 = XVRDPIZ
  { 1590,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1590 = XVREDP
  { 1591,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1591 = XVRESP
  { 1592,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1592 = XVRSPI
  { 1593,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1593 = XVRSPIC
  { 1594,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1594 = XVRSPIM
  { 1595,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1595 = XVRSPIP
  { 1596,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1596 = XVRSPIZ
  { 1597,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1597 = XVRSQRTEDP
  { 1598,	2,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1598 = XVRSQRTESP
  { 1599,	2,	1,	4,	17,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1599 = XVSQRTDP
  { 1600,	2,	1,	4,	18,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo209, -1 ,nullptr },  // Inst #1600 = XVSQRTSP
  { 1601,	3,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1601 = XVSUBDP
  { 1602,	3,	1,	4,	4,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1602 = XVSUBSP
  { 1603,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo212, -1 ,nullptr },  // Inst #1603 = XVTDIVDP
  { 1604,	3,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo212, -1 ,nullptr },  // Inst #1604 = XVTDIVSP
  { 1605,	2,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo213, -1 ,nullptr },  // Inst #1605 = XVTSQRTDP
  { 1606,	2,	1,	4,	13,	0, 0x0ULL, ImplicitList13, nullptr, OperandInfo213, -1 ,nullptr },  // Inst #1606 = XVTSQRTSP
  { 1607,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1607 = XXLAND
  { 1608,	3,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1608 = XXLANDC
  { 1609,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1609 = XXLEQV
  { 1610,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1610 = XXLNAND
  { 1611,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1611 = XXLNOR
  { 1612,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1612 = XXLOR
  { 1613,	3,	1,	4,	46,	0, 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1613 = XXLORC
  { 1614,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo199, -1 ,nullptr },  // Inst #1614 = XXLORf
  { 1615,	3,	1,	4,	46,	0|(1ULL<<MCID::Commutable), 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1615 = XXLXOR
  { 1616,	3,	1,	4,	58,	0, 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1616 = XXMRGHW
  { 1617,	3,	1,	4,	58,	0, 0x0ULL, nullptr, nullptr, OperandInfo210, -1 ,nullptr },  // Inst #1617 = XXMRGLW
  { 1618,	4,	1,	4,	58,	0, 0x0ULL, nullptr, nullptr, OperandInfo214, -1 ,nullptr },  // Inst #1618 = XXPERMDI
  { 1619,	4,	1,	4,	58,	0, 0x0ULL, nullptr, nullptr, OperandInfo215, -1 ,nullptr },  // Inst #1619 = XXSEL
  { 1620,	4,	1,	4,	58,	0, 0x0ULL, nullptr, nullptr, OperandInfo214, -1 ,nullptr },  // Inst #1620 = XXSLDWI
  { 1621,	3,	1,	4,	58,	0, 0x0ULL, nullptr, nullptr, OperandInfo216, -1 ,nullptr },  // Inst #1621 = XXSPLTW
  { 1622,	3,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo217, -1 ,nullptr },  // Inst #1622 = gBC
  { 1623,	3,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList7, OperandInfo217, -1 ,nullptr },  // Inst #1623 = gBCA
  { 1624,	3,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, OperandInfo218, -1 ,nullptr },  // Inst #1624 = gBCCTR
  { 1625,	3,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList25, OperandInfo218, -1 ,nullptr },  // Inst #1625 = gBCCTRL
  { 1626,	3,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList25, OperandInfo217, -1 ,nullptr },  // Inst #1626 = gBCL
  { 1627,	3,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList9, ImplicitList25, OperandInfo217, -1 ,nullptr },  // Inst #1627 = gBCLA
  { 1628,	3,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList7, OperandInfo218, -1 ,nullptr },  // Inst #1628 = gBCLR
  { 1629,	3,	0,	4,	3,	0|(1ULL<<MCID::UnmodeledSideEffects), 0x38ULL, ImplicitList16, ImplicitList25, OperandInfo218, -1 ,nullptr },  // Inst #1629 = gBCLRL
};

extern const char PPCInstrNameData[] = {
  /* 0 */ 'M', 'T', 'F', 'S', 'B', '0', 0,
  /* 7 */ 'V', '_', 'S', 'E', 'T', '0', 0,
  /* 14 */ 'V', 'C', 'T', 'S', 'X', 'S', '_', '0', 0,
  /* 23 */ 'V', 'C', 'T', 'U', 'X', 'S', '_', '0', 0,
  /* 32 */ 'V', 'C', 'F', 'S', 'X', '_', '0', 0,
  /* 40 */ 'V', 'C', 'F', 'U', 'X', '_', '0', 0,
  /* 48 */ 'M', 'T', 'F', 'S', 'B', '1', 0,
  /* 55 */ 'A', 'D', 'D', 'I', 'S', 'd', 't', 'p', 'r', 'e', 'l', 'H', 'A', '3', '2', 0,
  /* 71 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '3', '2', 0,
  /* 91 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '3', '2', 0,
  /* 111 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '3', '2', 0,
  /* 132 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '3', '2', 0,
  /* 152 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '3', '2', 0,
  /* 168 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '3', '2', 0,
  /* 188 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '3', '2', 0,
  /* 208 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '3', '2', 0,
  /* 227 */ 'A', 'D', 'D', 'I', 't', 'l', 's', 'g', 'd', 'L', '3', '2', 0,
  /* 240 */ 'A', 'D', 'D', 'I', 't', 'l', 's', 'l', 'd', 'L', '3', '2', 0,
  /* 253 */ 'L', 'D', 'g', 'o', 't', 'T', 'p', 'r', 'e', 'l', 'L', '3', '2', 0,
  /* 267 */ 'A', 'D', 'D', 'I', 'd', 't', 'p', 'r', 'e', 'l', 'L', '3', '2', 0,
  /* 281 */ 'A', 'D', 'D', 'I', 't', 'l', 's', 'g', 'd', 'L', 'A', 'D', 'D', 'R', '3', '2', 0,
  /* 298 */ 'A', 'D', 'D', 'I', 't', 'l', 's', 'l', 'd', 'L', 'A', 'D', 'D', 'R', '3', '2', 0,
  /* 315 */ 'G', 'E', 'T', 't', 'l', 's', 'l', 'd', 'A', 'D', 'D', 'R', '3', '2', 0,
  /* 330 */ 'G', 'E', 'T', 't', 'l', 's', 'A', 'D', 'D', 'R', '3', '2', 0,
  /* 343 */ 'L', 'W', 'A', '_', '3', '2', 0,
  /* 350 */ 'L', 'W', 'A', 'X', '_', '3', '2', 0,
  /* 358 */ 'E', 'H', '_', 'S', 'j', 'L', 'j', '_', 'L', 'o', 'n', 'g', 'J', 'm', 'p', '3', '2', 0,
  /* 376 */ 'E', 'H', '_', 'S', 'j', 'L', 'j', '_', 'S', 'e', 't', 'J', 'm', 'p', '3', '2', 0,
  /* 393 */ 'T', 'L', 'B', 'R', 'E', '2', 0,
  /* 400 */ 'T', 'L', 'B', 'W', 'E', '2', 0,
  /* 407 */ 'T', 'L', 'B', 'S', 'X', '2', 0,
  /* 414 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '6', '4', 0,
  /* 434 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '6', '4', 0,
  /* 454 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '6', '4', 0,
  /* 475 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '6', '4', 0,
  /* 495 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '6', '4', 0,
  /* 511 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '6', '4', 0,
  /* 531 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '6', '4', 0,
  /* 551 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '6', '4', 0,
  /* 570 */ 'D', 'S', 'T', '6', '4', 0,
  /* 576 */ 'D', 'S', 'T', 'S', 'T', '6', '4', 0,
  /* 584 */ 'D', 'S', 'T', 'T', '6', '4', 0,
  /* 591 */ 'D', 'S', 'T', 'S', 'T', 'T', '6', '4', 0,
  /* 600 */ 'E', 'X', 'T', 'S', 'B', '8', '_', '3', '2', '_', '6', '4', 0,
  /* 613 */ 'E', 'X', 'T', 'S', 'H', '8', '_', '3', '2', '_', '6', '4', 0,
  /* 626 */ 'R', 'L', 'D', 'I', 'C', 'L', '_', '3', '2', '_', '6', '4', 0,
  /* 639 */ 'E', 'X', 'T', 'S', 'W', '_', '3', '2', '_', '6', '4', 0,
  /* 651 */ 'E', 'H', '_', 'S', 'j', 'L', 'j', '_', 'L', 'o', 'n', 'g', 'J', 'm', 'p', '6', '4', 0,
  /* 669 */ 'E', 'H', '_', 'S', 'j', 'L', 'j', '_', 'S', 'e', 't', 'J', 'm', 'p', '6', '4', 0,
  /* 686 */ 'A', 'D', 'D', '4', 0,
  /* 691 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'F', '4', 0,
  /* 704 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'F', '4', 0,
  /* 714 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'I', '4', 0,
  /* 727 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'I', '4', 0,
  /* 737 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '1', '6', 0,
  /* 757 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '1', '6', 0,
  /* 777 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '1', '6', 0,
  /* 798 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '1', '6', 0,
  /* 818 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '1', '6', 0,
  /* 834 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '1', '6', 0,
  /* 854 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '1', '6', 0,
  /* 874 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '1', '6', 0,
  /* 893 */ 'N', 'O', 'P', '_', 'G', 'T', '_', 'P', 'W', 'R', '6', 0,
  /* 905 */ 'N', 'O', 'P', '_', 'G', 'T', '_', 'P', 'W', 'R', '7', 0,
  /* 917 */ 'T', 'A', 'I', 'L', 'B', 'A', '8', 0,
  /* 925 */ 'L', 'H', 'A', '8', 0,
  /* 930 */ 'B', 'L', 'A', '8', 0,
  /* 935 */ 'T', 'A', 'I', 'L', 'B', '8', 0,
  /* 942 */ 'C', 'M', 'P', 'B', '8', 0,
  /* 948 */ 'E', 'X', 'T', 'S', 'B', '8', 0,
  /* 955 */ 'M', 'F', 'T', 'B', '8', 0,
  /* 961 */ 'S', 'T', 'B', '8', 0,
  /* 966 */ 'A', 'D', 'D', 'C', '8', 0,
  /* 972 */ 'A', 'N', 'D', 'C', '8', 0,
  /* 978 */ 'S', 'U', 'B', 'F', 'C', '8', 0,
  /* 985 */ 'A', 'D', 'D', 'I', 'C', '8', 0,
  /* 992 */ 'S', 'U', 'B', 'F', 'I', 'C', '8', 0,
  /* 1000 */ 'D', 'Y', 'N', 'A', 'L', 'L', 'O', 'C', '8', 0,
  /* 1010 */ 'O', 'R', 'C', '8', 0,
  /* 1015 */ 'A', 'D', 'D', '8', 0,
  /* 1020 */ 'N', 'A', 'N', 'D', '8', 0,
  /* 1026 */ 'A', 'D', 'D', 'E', '8', 0,
  /* 1032 */ 'S', 'U', 'B', 'F', 'E', '8', 0,
  /* 1039 */ 'A', 'D', 'D', 'M', 'E', '8', 0,
  /* 1046 */ 'S', 'U', 'B', 'F', 'M', 'E', '8', 0,
  /* 1054 */ 'A', 'D', 'D', 'Z', 'E', '8', 0,
  /* 1061 */ 'S', 'U', 'B', 'F', 'Z', 'E', '8', 0,
  /* 1069 */ 'S', 'U', 'B', 'F', '8', 0,
  /* 1075 */ 'M', 'F', 'O', 'C', 'R', 'F', '8', 0,
  /* 1083 */ 'M', 'T', 'O', 'C', 'R', 'F', '8', 0,
  /* 1091 */ 'M', 'T', 'C', 'R', 'F', '8', 0,
  /* 1098 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'F', '8', 0,
  /* 1111 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'F', '8', 0,
  /* 1121 */ 'N', 'E', 'G', '8', 0,
  /* 1126 */ 'E', 'X', 'T', 'S', 'H', '8', 0,
  /* 1133 */ 'S', 'T', 'H', '8', 0,
  /* 1138 */ 'A', 'D', 'D', 'I', '8', 0,
  /* 1144 */ 'M', 'U', 'L', 'L', 'I', '8', 0,
  /* 1151 */ 'R', 'L', 'W', 'I', 'M', 'I', '8', 0,
  /* 1159 */ 'X', 'O', 'R', 'I', '8', 0,
  /* 1165 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'S', 'U', 'B', '_', 'I', '8', 0,
  /* 1184 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'I', '8', 0,
  /* 1197 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'D', 'D', '_', 'I', '8', 0,
  /* 1216 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'N', 'A', 'N', 'D', '_', 'I', '8', 0,
  /* 1236 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'A', 'N', 'D', '_', 'I', '8', 0,
  /* 1255 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'S', 'W', 'A', 'P', '_', 'I', '8', 0,
  /* 1270 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'C', 'M', 'P', '_', 'S', 'W', 'A', 'P', '_', 'I', '8', 0,
  /* 1289 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'X', 'O', 'R', '_', 'I', '8', 0,
  /* 1308 */ 'A', 'T', 'O', 'M', 'I', 'C', '_', 'L', 'O', 'A', 'D', '_', 'O', 'R', '_', 'I', '8', 0,
  /* 1326 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'I', '8', 0,
  /* 1336 */ 'B', 'L', '8', 0,
  /* 1340 */ 'I', 'S', 'E', 'L', '8', 0,
  /* 1346 */ 'B', 'C', 'T', 'R', 'L', '8', 0,
  /* 1353 */ 'B', 'C', 'C', 'T', 'R', 'L', '8', 0,
  /* 1361 */ 'B', 'C', 'C', 'C', 'T', 'R', 'L', '8', 0,
  /* 1370 */ 'R', 'L', 'W', 'I', 'N', 'M', '8', 0,
  /* 1378 */ 'R', 'L', 'W', 'N', 'M', '8', 0,
  /* 1385 */ 'M', 'F', 'C', 'R', '8', 0,
  /* 1391 */ 'B', 'L', 'R', '8', 0,
  /* 1396 */ 'M', 'F', 'L', 'R', '8', 0,
  /* 1402 */ 'M', 'T', 'L', 'R', '8', 0,
  /* 1408 */ 'B', 'D', 'Z', 'L', 'R', '8', 0,
  /* 1415 */ 'B', 'D', 'N', 'Z', 'L', 'R', '8', 0,
  /* 1423 */ 'M', 'o', 'v', 'e', 'P', 'C', 't', 'o', 'L', 'R', '8', 0,
  /* 1435 */ 'N', 'O', 'R', '8', 0,
  /* 1440 */ 'X', 'O', 'R', '8', 0,
  /* 1445 */ 'M', 'F', 'S', 'P', 'R', '8', 0,
  /* 1452 */ 'M', 'T', 'S', 'P', 'R', '8', 0,
  /* 1459 */ 'T', 'A', 'I', 'L', 'B', 'C', 'T', 'R', '8', 0,
  /* 1469 */ 'B', 'C', 'C', 'T', 'R', '8', 0,
  /* 1476 */ 'B', 'C', 'C', 'C', 'T', 'R', '8', 0,
  /* 1484 */ 'M', 'F', 'C', 'T', 'R', '8', 0,
  /* 1491 */ 'M', 'T', 'C', 'T', 'R', '8', 0,
  /* 1498 */ 'A', 'D', 'D', 'I', 'S', '8', 0,
  /* 1505 */ 'L', 'I', 'S', '8', 0,
  /* 1510 */ 'X', 'O', 'R', 'I', 'S', '8', 0,
  /* 1517 */ 'D', 'Y', 'N', 'A', 'R', 'E', 'A', 'O', 'F', 'F', 'S', 'E', 'T', '8', 0,
  /* 1532 */ 'A', 'N', 'D', 'I', 'o', '_', '1', '_', 'E', 'Q', '_', 'B', 'I', 'T', '8', 0,
  /* 1548 */ 'A', 'N', 'D', 'I', 'o', '_', '1', '_', 'G', 'T', '_', 'B', 'I', 'T', '8', 0,
  /* 1564 */ 'L', 'H', 'A', 'U', '8', 0,
  /* 1570 */ 'S', 'T', 'B', 'U', '8', 0,
  /* 1576 */ 'S', 'T', 'H', 'U', '8', 0,
  /* 1582 */ 'S', 'T', 'W', 'U', '8', 0,
  /* 1588 */ 'L', 'B', 'Z', 'U', '8', 0,
  /* 1594 */ 'L', 'H', 'Z', 'U', '8', 0,
  /* 1600 */ 'L', 'W', 'Z', 'U', '8', 0,
  /* 1606 */ 'E', 'Q', 'V', '8', 0,
  /* 1611 */ 'S', 'L', 'W', '8', 0,
  /* 1616 */ 'S', 'R', 'W', '8', 0,
  /* 1621 */ 'S', 'T', 'W', '8', 0,
  /* 1626 */ 'C', 'N', 'T', 'L', 'Z', 'W', '8', 0,
  /* 1634 */ 'L', 'H', 'A', 'X', '8', 0,
  /* 1640 */ 'S', 'T', 'B', 'X', '8', 0,
  /* 1646 */ 'S', 'T', 'H', 'X', '8', 0,
  /* 1652 */ 'L', 'H', 'B', 'R', 'X', '8', 0,
  /* 1659 */ 'L', 'W', 'B', 'R', 'X', '8', 0,
  /* 1666 */ 'L', 'H', 'A', 'U', 'X', '8', 0,
  /* 1673 */ 'S', 'T', 'B', 'U', 'X', '8', 0,
  /* 1680 */ 'S', 'T', 'H', 'U', 'X', '8', 0,
  /* 1687 */ 'S', 'T', 'W', 'U', 'X', '8', 0,
  /* 1694 */ 'L', 'B', 'Z', 'U', 'X', '8', 0,
  /* 1701 */ 'L', 'H', 'Z', 'U', 'X', '8', 0,
  /* 1708 */ 'L', 'W', 'Z', 'U', 'X', '8', 0,
  /* 1715 */ 'S', 'T', 'W', 'X', '8', 0,
  /* 1721 */ 'L', 'B', 'Z', 'X', '8', 0,
  /* 1727 */ 'L', 'H', 'Z', 'X', '8', 0,
  /* 1733 */ 'L', 'W', 'Z', 'X', '8', 0,
  /* 1739 */ 'L', 'B', 'Z', '8', 0,
  /* 1744 */ 'B', 'D', 'Z', '8', 0,
  /* 1749 */ 'L', 'H', 'Z', '8', 0,
  /* 1754 */ 'B', 'D', 'N', 'Z', '8', 0,
  /* 1760 */ 'L', 'W', 'Z', '8', 0,
  /* 1765 */ 'T', 'C', 'R', 'E', 'T', 'U', 'R', 'N', 'a', 'i', '8', 0,
  /* 1777 */ 'T', 'C', 'R', 'E', 'T', 'U', 'R', 'N', 'd', 'i', '8', 0,
  /* 1789 */ 'T', 'C', 'R', 'E', 'T', 'U', 'R', 'N', 'r', 'i', '8', 0,
  /* 1801 */ 'A', 'N', 'D', 'I', 'o', '8', 0,
  /* 1808 */ 'A', 'N', 'D', 'I', 'S', 'o', '8', 0,
  /* 1816 */ 'E', 'V', 'M', 'H', 'E', 'G', 'S', 'M', 'F', 'A', 'A', 0,
  /* 1828 */ 'E', 'V', 'M', 'H', 'O', 'G', 'S', 'M', 'F', 'A', 'A', 0,
  /* 1840 */ 'E', 'V', 'M', 'W', 'S', 'M', 'F', 'A', 'A', 0,
  /* 1850 */ 'E', 'V', 'M', 'W', 'S', 'S', 'F', 'A', 'A', 0,
  /* 1860 */ 'E', 'V', 'M', 'H', 'E', 'G', 'S', 'M', 'I', 'A', 'A', 0,
  /* 1872 */ 'E', 'V', 'M', 'H', 'O', 'G', 'S', 'M', 'I', 'A', 'A', 0,
  /* 1884 */ 'E', 'V', 'M', 'W', 'S', 'M', 'I', 'A', 'A', 0,
  /* 1894 */ 'E', 'V', 'M', 'H', 'E', 'G', 'U', 'M', 'I', 'A', 'A', 0,
  /* 1906 */ 'E', 'V', 'M', 'H', 'O', 'G', 'U', 'M', 'I', 'A', 'A', 0,
  /* 1918 */ 'E', 'V', 'M', 'W', 'U', 'M', 'I', 'A', 'A', 0,
  /* 1928 */ 'D', 'C', 'B', 'A', 0,
  /* 1933 */ 'T', 'A', 'I', 'L', 'B', 'A', 0,
  /* 1940 */ 'L', 'D', 't', 'o', 'c', 'B', 'A', 0,
  /* 1948 */ 'g', 'B', 'C', 'A', 0,
  /* 1953 */ 'B', 'C', 'C', 'A', 0,
  /* 1958 */ 'E', 'V', 'M', 'H', 'E', 'S', 'M', 'F', 'A', 0,
  /* 1968 */ 'E', 'V', 'M', 'W', 'H', 'S', 'M', 'F', 'A', 0,
  /* 1978 */ 'E', 'V', 'M', 'H', 'O', 'S', 'M', 'F', 'A', 0,
  /* 1988 */ 'E', 'V', 'M', 'W', 'S', 'M', 'F', 'A', 0,
  /* 1997 */ 'E', 'V', 'M', 'H', 'E', 'S', 'S', 'F', 'A', 0,
  /* 2007 */ 'E', 'V', 'M', 'W', 'H', 'S', 'S', 'F', 'A', 0,
  /* 2017 */ 'E', 'V', 'M', 'H', 'O', 'S', 'S', 'F', 'A', 0,
  /* 2027 */ 'E', 'V', 'M', 'W', 'S', 'S', 'F', 'A', 0,
  /* 2036 */ 'L', 'H', 'A', 0,
  /* 2040 */ 'A', 'D', 'D', 'I', 'S', 't', 'o', 'c', 'H', 'A', 0,
  /* 2051 */ 'A', 'D', 'D', 'I', 'S', 't', 'l', 's', 'g', 'd', 'H', 'A', 0,
  /* 2064 */ 'A', 'D', 'D', 'I', 'S', 't', 'l', 's', 'l', 'd', 'H', 'A', 0,
  /* 2077 */ 'A', 'D', 'D', 'I', 'S', 'g', 'o', 't', 'T', 'p', 'r', 'e', 'l', 'H', 'A', 0,
  /* 2093 */ 'A', 'D', 'D', 'I', 'S', 'd', 't', 'p', 'r', 'e', 'l', 'H', 'A', 0,
  /* 2107 */ 'S', 'L', 'B', 'I', 'A', 0,
  /* 2113 */ 'T', 'L', 'B', 'I', 'A', 0,
  /* 2119 */ 'E', 'V', 'M', 'H', 'E', 'S', 'M', 'I', 'A', 0,
  /* 2129 */ 'E', 'V', 'M', 'W', 'H', 'S', 'M', 'I', 'A', 0,
  /* 2139 */ 'E', 'V', 'M', 'H', 'O', 'S', 'M', 'I', 'A', 0,
  /* 2149 */ 'E', 'V', 'M', 'W', 'S', 'M', 'I', 'A', 0,
  /* 2158 */ 'E', 'V', 'M', 'H', 'E', 'U', 'M', 'I', 'A', 0,
  /* 2168 */ 'E', 'V', 'M', 'W', 'H', 'U', 'M', 'I', 'A', 0,
  /* 2178 */ 'E', 'V', 'M', 'W', 'L', 'U', 'M', 'I', 'A', 0,
  /* 2188 */ 'E', 'V', 'M', 'H', 'O', 'U', 'M', 'I', 'A', 0,
  /* 2198 */ 'E', 'V', 'M', 'W', 'U', 'M', 'I', 'A', 0,
  /* 2207 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'D', 'X', 'I', 'A', 0,
  /* 2218 */ 'Q', 'V', 'S', 'T', 'F', 'D', 'X', 'I', 'A', 0,
  /* 2228 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'S', 'X', 'I', 'A', 0,
  /* 2239 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'X', 'I', 'A', 0,
  /* 2249 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'D', 'U', 'X', 'I', 'A', 0,
  /* 2261 */ 'Q', 'V', 'S', 'T', 'F', 'D', 'U', 'X', 'I', 'A', 0,
  /* 2272 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'S', 'U', 'X', 'I', 'A', 0,
  /* 2284 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'U', 'X', 'I', 'A', 0,
  /* 2295 */ 'B', 'L', 'A', 0,
  /* 2299 */ 'g', 'B', 'C', 'L', 'A', 0,
  /* 2305 */ 'B', 'C', 'C', 'L', 'A', 0,
  /* 2311 */ 'B', 'D', 'Z', 'L', 'A', 0,
  /* 2317 */ 'B', 'D', 'N', 'Z', 'L', 'A', 0,
  /* 2324 */ 'E', 'V', 'M', 'R', 'A', 0,
  /* 2330 */ 'L', 'W', 'A', 0,
  /* 2334 */ 'M', 'T', 'V', 'S', 'R', 'W', 'A', 0,
  /* 2342 */ 'Q', 'V', 'L', 'F', 'I', 'W', 'A', 'X', 'A', 0,
  /* 2352 */ 'Q', 'V', 'L', 'F', 'C', 'D', 'X', 'A', 0,
  /* 2361 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'D', 'X', 'A', 0,
  /* 2371 */ 'Q', 'V', 'L', 'F', 'D', 'X', 'A', 0,
  /* 2379 */ 'Q', 'V', 'S', 'T', 'F', 'D', 'X', 'A', 0,
  /* 2388 */ 'Q', 'V', 'L', 'F', 'C', 'S', 'X', 'A', 0,
  /* 2397 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'S', 'X', 'A', 0,
  /* 2407 */ 'Q', 'V', 'L', 'F', 'S', 'X', 'A', 0,
  /* 2415 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'X', 'A', 0,
  /* 2424 */ 'Q', 'V', 'L', 'F', 'C', 'D', 'U', 'X', 'A', 0,
  /* 2434 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'D', 'U', 'X', 'A', 0,
  /* 2445 */ 'Q', 'V', 'L', 'F', 'D', 'U', 'X', 'A', 0,
  /* 2454 */ 'Q', 'V', 'S', 'T', 'F', 'D', 'U', 'X', 'A', 0,
  /* 2464 */ 'Q', 'V', 'L', 'F', 'C', 'S', 'U', 'X', 'A', 0,
  /* 2474 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'S', 'U', 'X', 'A', 0,
  /* 2485 */ 'Q', 'V', 'L', 'F', 'S', 'U', 'X', 'A', 0,
  /* 2494 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'U', 'X', 'A', 0,
  /* 2504 */ 'Q', 'V', 'S', 'T', 'F', 'I', 'W', 'X', 'A', 0,
  /* 2514 */ 'Q', 'V', 'L', 'F', 'I', 'W', 'Z', 'X', 'A', 0,
  /* 2524 */ 'B', 'D', 'Z', 'A', 0,
  /* 2529 */ 'B', 'D', 'N', 'Z', 'A', 0,
  /* 2535 */ 'V', '_', 'S', 'E', 'T', '0', 'B', 0,
  /* 2543 */ 'V', 'S', 'R', 'A', 'B', 0,
  /* 2549 */ 'R', 'F', 'E', 'B', 'B', 0,
  /* 2555 */ 'V', 'M', 'R', 'G', 'H', 'B', 0,
  /* 2562 */ 'V', 'M', 'R', 'G', 'L', 'B', 0,
  /* 2569 */ 'T', 'A', 'I', 'L', 'B', 0,
  /* 2575 */ 'V', 'R', 'L', 'B', 0,
  /* 2580 */ 'V', 'S', 'L', 'B', 0,
  /* 2585 */ 'V', 'P', 'M', 'S', 'U', 'M', 'B', 0,
  /* 2593 */ 'C', 'M', 'P', 'B', 0,
  /* 2598 */ 'C', 'L', 'R', 'B', 'H', 'R', 'B', 0,
  /* 2606 */ 'V', 'S', 'R', 'B', 0,
  /* 2611 */ 'V', 'M', 'U', 'L', 'E', 'S', 'B', 0,
  /* 2619 */ 'V', '_', 'S', 'E', 'T', 'A', 'L', 'L', 'O', 'N', 'E', 'S', 'B', 0,
  /* 2633 */ 'V', 'A', 'V', 'G', 'S', 'B', 0,
  /* 2640 */ 'V', 'U', 'P', 'K', 'H', 'S', 'B', 0,
  /* 2648 */ 'V', 'S', 'P', 'L', 'T', 'I', 'S', 'B', 0,
  /* 2657 */ 'V', 'U', 'P', 'K', 'L', 'S', 'B', 0,
  /* 2665 */ 'V', 'M', 'I', 'N', 'S', 'B', 0,
  /* 2672 */ 'V', 'M', 'U', 'L', 'O', 'S', 'B', 0,
  /* 2680 */ 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'B', 0,
  /* 2689 */ 'E', 'V', 'E', 'X', 'T', 'S', 'B', 0,
  /* 2697 */ 'V', 'M', 'A', 'X', 'S', 'B', 0,
  /* 2704 */ 'M', 'F', 'T', 'B', 0,
  /* 2709 */ 'V', 'S', 'P', 'L', 'T', 'B', 0,
  /* 2716 */ 'V', 'P', 'O', 'P', 'C', 'N', 'T', 'B', 0,
  /* 2725 */ 'S', 'T', 'B', 0,
  /* 2729 */ 'R', 'e', 'a', 'd', 'T', 'B', 0,
  /* 2736 */ 'V', 'M', 'U', 'L', 'E', 'U', 'B', 0,
  /* 2744 */ 'V', 'A', 'V', 'G', 'U', 'B', 0,
  /* 2751 */ 'V', 'M', 'I', 'N', 'U', 'B', 0,
  /* 2758 */ 'V', 'M', 'U', 'L', 'O', 'U', 'B', 0,
  /* 2766 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'U', 'B', 0,
  /* 2775 */ 'Q', 'V', 'F', 'S', 'U', 'B', 0,
  /* 2782 */ 'Q', 'V', 'F', 'M', 'S', 'U', 'B', 0,
  /* 2790 */ 'Q', 'V', 'F', 'N', 'M', 'S', 'U', 'B', 0,
  /* 2799 */ 'V', 'C', 'M', 'P', 'G', 'T', 'U', 'B', 0,
  /* 2808 */ 'V', 'M', 'A', 'X', 'U', 'B', 0,
  /* 2815 */ 'V', 'C', 'L', 'Z', 'B', 0,
  /* 2821 */ 'g', 'B', 'C', 0,
  /* 2825 */ 'B', 'C', 'C', 0,
  /* 2829 */ 'A', 'D', 'D', 'C', 0,
  /* 2834 */ 'X', 'X', 'L', 'A', 'N', 'D', 'C', 0,
  /* 2842 */ 'C', 'R', 'A', 'N', 'D', 'C', 0,
  /* 2849 */ 'E', 'V', 'A', 'N', 'D', 'C', 0,
  /* 2856 */ 'T', 'A', 'B', 'O', 'R', 'T', 'D', 'C', 0,
  /* 2865 */ 'S', 'U', 'B', 'F', 'C', 0,
  /* 2871 */ 'S', 'U', 'B', 'I', 'C', 0,
  /* 2877 */ 'A', 'D', 'D', 'I', 'C', 0,
  /* 2883 */ 'R', 'L', 'D', 'I', 'C', 0,
  /* 2889 */ 'S', 'U', 'B', 'F', 'I', 'C', 0,
  /* 2896 */ 'X', 'S', 'R', 'D', 'P', 'I', 'C', 0,
  /* 2904 */ 'X', 'V', 'R', 'D', 'P', 'I', 'C', 0,
  /* 2912 */ 'X', 'V', 'R', 'S', 'P', 'I', 'C', 0,
  /* 2920 */ 'B', 'R', 'I', 'N', 'C', 0,
  /* 2926 */ 'T', 'L', 'B', 'S', 'Y', 'N', 'C', 0,
  /* 2934 */ 'I', 'S', 'Y', 'N', 'C', 0,
  /* 2940 */ 'M', 'S', 'Y', 'N', 'C', 0,
  /* 2946 */ 'D', 'Y', 'N', 'A', 'L', 'L', 'O', 'C', 0,
  /* 2955 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'Q', 'B', 'R', 'C', 0,
  /* 2970 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'Q', 'B', 'R', 'C', 0,
  /* 2982 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'Q', 'F', 'R', 'C', 0,
  /* 2997 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'Q', 'F', 'R', 'C', 0,
  /* 3009 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'V', 'S', 'F', 'R', 'C', 0,
  /* 3025 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'V', 'S', 'F', 'R', 'C', 0,
  /* 3038 */ 'X', 'X', 'L', 'O', 'R', 'C', 0,
  /* 3045 */ 'C', 'R', 'O', 'R', 'C', 0,
  /* 3051 */ 'E', 'V', 'O', 'R', 'C', 0,
  /* 3057 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'V', 'R', 'R', 'C', 0,
  /* 3072 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'V', 'R', 'R', 'C', 0,
  /* 3084 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'Q', 'S', 'R', 'C', 0,
  /* 3099 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'Q', 'S', 'R', 'C', 0,
  /* 3111 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'V', 'S', 'S', 'R', 'C', 0,
  /* 3127 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'V', 'S', 'S', 'R', 'C', 0,
  /* 3140 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'C', 'C', '_', 'V', 'S', 'R', 'C', 0,
  /* 3155 */ 'S', 'E', 'L', 'E', 'C', 'T', '_', 'V', 'S', 'R', 'C', 0,
  /* 3167 */ 'S', 'C', 0,
  /* 3170 */ 'T', 'A', 'B', 'O', 'R', 'T', 'W', 'C', 0,
  /* 3179 */ 'T', 'L', 'B', 'S', 'X', '2', 'D', 0,
  /* 3187 */ 'V', 'S', 'H', 'A', 'S', 'I', 'G', 'M', 'A', 'D', 0,
  /* 3198 */ 'V', 'S', 'R', 'A', 'D', 0,
  /* 3204 */ 'V', 'G', 'B', 'B', 'D', 0,
  /* 3210 */ 'Q', 'V', 'F', 'A', 'D', 'D', 0,
  /* 3217 */ 'Q', 'V', 'F', 'M', 'A', 'D', 'D', 0,
  /* 3225 */ 'Q', 'V', 'F', 'N', 'M', 'A', 'D', 'D', 0,
  /* 3234 */ 'Q', 'V', 'F', 'X', 'X', 'C', 'P', 'N', 'M', 'A', 'D', 'D', 0,
  /* 3247 */ 'Q', 'V', 'F', 'X', 'X', 'N', 'P', 'M', 'A', 'D', 'D', 0,
  /* 3259 */ 'Q', 'V', 'F', 'X', 'M', 'A', 'D', 'D', 0,
  /* 3268 */ 'Q', 'V', 'F', 'X', 'X', 'M', 'A', 'D', 'D', 0,
  /* 3278 */ 'E', 'V', 'L', 'D', 'D', 0,
  /* 3284 */ 'E', 'V', 'S', 'T', 'D', 'D', 0,
  /* 3291 */ 'L', 'F', 'D', 0,
  /* 3295 */ 'S', 'T', 'F', 'D', 0,
  /* 3300 */ 'F', 'N', 'E', 'G', 'D', 0,
  /* 3306 */ 'M', 'U', 'L', 'H', 'D', 0,
  /* 3312 */ 'Q', 'V', 'F', 'C', 'F', 'I', 'D', 0,
  /* 3320 */ 'R', 'F', 'I', 'D', 0,
  /* 3325 */ 'Q', 'V', 'F', 'C', 'T', 'I', 'D', 0,
  /* 3333 */ 'T', 'L', 'B', 'L', 'D', 0,
  /* 3339 */ 'F', 'S', 'E', 'L', 'D', 0,
  /* 3345 */ 'M', 'U', 'L', 'L', 'D', 0,
  /* 3351 */ 'C', 'M', 'P', 'L', 'D', 0,
  /* 3357 */ 'V', 'R', 'L', 'D', 0,
  /* 3362 */ 'V', 'S', 'L', 'D', 0,
  /* 3367 */ 'F', 'R', 'I', 'M', 'D', 0,
  /* 3373 */ 'B', 'P', 'E', 'R', 'M', 'D', 0,
  /* 3380 */ 'V', 'P', 'M', 'S', 'U', 'M', 'D', 0,
  /* 3388 */ 'X', 'X', 'L', 'A', 'N', 'D', 0,
  /* 3395 */ 'X', 'X', 'L', 'N', 'A', 'N', 'D', 0,
  /* 3403 */ 'C', 'R', 'N', 'A', 'N', 'D', 0,
  /* 3410 */ 'E', 'V', 'N', 'A', 'N', 'D', 0,
  /* 3417 */ 'C', 'R', 'A', 'N', 'D', 0,
  /* 3423 */ 'E', 'V', 'A', 'N', 'D', 0,
  /* 3429 */ 'T', 'E', 'N', 'D', 0,
  /* 3434 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'E', 'N', 'D', 0,
  /* 3447 */ 'F', 'C', 'P', 'S', 'G', 'N', 'D', 0,
  /* 3455 */ 'F', 'R', 'I', 'N', 'D', 0,
  /* 3461 */ 'F', 'R', 'I', 'P', 'D', 0,
  /* 3467 */ 'C', 'M', 'P', 'D', 0,
  /* 3472 */ 'L', 'O', 'A', 'D', '_', 'S', 'T', 'A', 'C', 'K', '_', 'G', 'U', 'A', 'R', 'D', 0,
  /* 3489 */ 'M', 'T', 'M', 'S', 'R', 'D', 0,
  /* 3496 */ 'M', 'F', 'V', 'S', 'R', 'D', 0,
  /* 3503 */ 'M', 'T', 'V', 'S', 'R', 'D', 0,
  /* 3510 */ 'F', 'A', 'B', 'S', 'D', 0,
  /* 3516 */ 'F', 'N', 'A', 'B', 'S', 'D', 0,
  /* 3523 */ 'V', 'M', 'I', 'N', 'S', 'D', 0,
  /* 3530 */ 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'D', 0,
  /* 3539 */ 'V', 'M', 'A', 'X', 'S', 'D', 0,
  /* 3546 */ 'V', 'P', 'O', 'P', 'C', 'N', 'T', 'D', 0,
  /* 3555 */ 'S', 'T', 'D', 0,
  /* 3559 */ 'V', 'M', 'I', 'N', 'U', 'D', 0,
  /* 3566 */ 'F', 'C', 'M', 'P', 'U', 'D', 0,
  /* 3573 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'U', 'D', 0,
  /* 3582 */ 'V', 'C', 'M', 'P', 'G', 'T', 'U', 'D', 0,
  /* 3591 */ 'V', 'M', 'A', 'X', 'U', 'D', 0,
  /* 3598 */ 'D', 'I', 'V', 'D', 0,
  /* 3603 */ 'F', 'R', 'I', 'Z', 'D', 0,
  /* 3609 */ 'V', 'C', 'L', 'Z', 'D', 0,
  /* 3615 */ 'C', 'N', 'T', 'L', 'Z', 'D', 0,
  /* 3622 */ 'M', 'F', 'B', 'H', 'R', 'B', 'E', 0,
  /* 3630 */ 'R', 'E', 'G', '_', 'S', 'E', 'Q', 'U', 'E', 'N', 'C', 'E', 0,
  /* 3643 */ 'A', 'D', 'D', 'E', 0,
  /* 3648 */ 'D', 'I', 'V', 'D', 'E', 0,
  /* 3654 */ 'S', 'L', 'B', 'M', 'F', 'E', 'E', 0,
  /* 3662 */ 'W', 'R', 'T', 'E', 'E', 0,
  /* 3668 */ 'S', 'U', 'B', 'F', 'E', 0,
  /* 3674 */ 'E', 'V', 'L', 'W', 'H', 'E', 0,
  /* 3681 */ 'E', 'V', 'S', 'T', 'W', 'H', 'E', 0,
  /* 3689 */ 'S', 'L', 'B', 'I', 'E', 0,
  /* 3695 */ 'T', 'L', 'B', 'I', 'E', 0,
  /* 3701 */ 'B', 'U', 'N', 'D', 'L', 'E', 0,
  /* 3708 */ 'A', 'D', 'D', 'M', 'E', 0,
  /* 3714 */ 'S', 'U', 'B', 'F', 'M', 'E', 0,
  /* 3721 */ 'L', 'O', 'C', 'A', 'L', '_', 'E', 'S', 'C', 'A', 'P', 'E', 0,
  /* 3734 */ 'T', 'L', 'B', 'R', 'E', 0,
  /* 3740 */ 'Q', 'V', 'F', 'R', 'E', 0,
  /* 3746 */ 'S', 'L', 'B', 'M', 'T', 'E', 0,
  /* 3753 */ 'Q', 'V', 'F', 'R', 'S', 'Q', 'R', 'T', 'E', 0,
  /* 3763 */ 'D', 'B', 'G', '_', 'V', 'A', 'L', 'U', 'E', 0,
  /* 3773 */ 'M', 'F', 'V', 'R', 'S', 'A', 'V', 'E', 0,
  /* 3782 */ 'M', 'T', 'V', 'R', 'S', 'A', 'V', 'E', 0,
  /* 3791 */ 'R', 'E', 'S', 'T', 'O', 'R', 'E', '_', 'V', 'R', 'S', 'A', 'V', 'E', 0,
  /* 3806 */ 'U', 'P', 'D', 'A', 'T', 'E', '_', 'V', 'R', 'S', 'A', 'V', 'E', 0,
  /* 3820 */ 'S', 'P', 'I', 'L', 'L', '_', 'V', 'R', 'S', 'A', 'V', 'E', 0,
  /* 3833 */ 'T', 'L', 'B', 'W', 'E', 0,
  /* 3839 */ 'D', 'I', 'V', 'W', 'E', 0,
  /* 3845 */ 'E', 'V', 'S', 'T', 'W', 'W', 'E', 0,
  /* 3853 */ 'A', 'D', 'D', 'Z', 'E', 0,
  /* 3859 */ 'S', 'U', 'B', 'F', 'Z', 'E', 0,
  /* 3866 */ 'D', 'C', 'B', 'F', 0,
  /* 3871 */ 'S', 'U', 'B', 'F', 0,
  /* 3876 */ 'I', 'M', 'P', 'L', 'I', 'C', 'I', 'T', '_', 'D', 'E', 'F', 0,
  /* 3889 */ 'E', 'V', 'M', 'H', 'E', 'S', 'M', 'F', 0,
  /* 3898 */ 'E', 'V', 'M', 'W', 'H', 'S', 'M', 'F', 0,
  /* 3907 */ 'E', 'V', 'M', 'H', 'O', 'S', 'M', 'F', 0,
  /* 3916 */ 'E', 'V', 'M', 'W', 'S', 'M', 'F', 0,
  /* 3924 */ 'M', 'C', 'R', 'F', 0,
  /* 3929 */ 'M', 'F', 'O', 'C', 'R', 'F', 0,
  /* 3936 */ 'M', 'T', 'O', 'C', 'R', 'F', 0,
  /* 3943 */ 'M', 'T', 'C', 'R', 'F', 0,
  /* 3949 */ 'M', 'T', 'F', 'S', 'F', 0,
  /* 3955 */ 'E', 'V', 'M', 'H', 'E', 'S', 'S', 'F', 0,
  /* 3964 */ 'E', 'V', 'M', 'W', 'H', 'S', 'S', 'F', 0,
  /* 3973 */ 'E', 'V', 'M', 'H', 'O', 'S', 'S', 'F', 0,
  /* 3982 */ 'E', 'V', 'M', 'W', 'S', 'S', 'F', 0,
  /* 3990 */ 'Q', 'V', 'F', 'N', 'E', 'G', 0,
  /* 3997 */ 'E', 'V', 'N', 'E', 'G', 0,
  /* 4003 */ 'E', 'X', 'T', 'R', 'A', 'C', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 4018 */ 'I', 'N', 'S', 'E', 'R', 'T', '_', 'S', 'U', 'B', 'R', 'E', 'G', 0,
  /* 4032 */ 'S', 'U', 'B', 'R', 'E', 'G', '_', 'T', 'O', '_', 'R', 'E', 'G', 0,
  /* 4046 */ 'V', '_', 'S', 'E', 'T', '0', 'H', 0,
  /* 4054 */ 'V', 'S', 'R', 'A', 'H', 0,
  /* 4060 */ 'E', 'V', 'L', 'D', 'H', 0,
  /* 4066 */ 'E', 'V', 'S', 'T', 'D', 'H', 0,
  /* 4073 */ 'V', 'M', 'R', 'G', 'H', 'H', 0,
  /* 4080 */ 'V', 'M', 'R', 'G', 'L', 'H', 0,
  /* 4087 */ 'V', 'R', 'L', 'H', 0,
  /* 4092 */ 'V', 'S', 'L', 'H', 0,
  /* 4097 */ 'V', 'P', 'M', 'S', 'U', 'M', 'H', 0,
  /* 4105 */ 'V', 'S', 'R', 'H', 0,
  /* 4110 */ 'V', 'M', 'U', 'L', 'E', 'S', 'H', 0,
  /* 4118 */ 'V', '_', 'S', 'E', 'T', 'A', 'L', 'L', 'O', 'N', 'E', 'S', 'H', 0,
  /* 4132 */ 'V', 'A', 'V', 'G', 'S', 'H', 0,
  /* 4139 */ 'V', 'U', 'P', 'K', 'H', 'S', 'H', 0,
  /* 4147 */ 'V', 'S', 'P', 'L', 'T', 'I', 'S', 'H', 0,
  /* 4156 */ 'V', 'U', 'P', 'K', 'L', 'S', 'H', 0,
  /* 4164 */ 'V', 'M', 'I', 'N', 'S', 'H', 0,
  /* 4171 */ 'V', 'M', 'U', 'L', 'O', 'S', 'H', 0,
  /* 4179 */ 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'H', 0,
  /* 4188 */ 'E', 'V', 'E', 'X', 'T', 'S', 'H', 0,
  /* 4196 */ 'V', 'M', 'A', 'X', 'S', 'H', 0,
  /* 4203 */ 'V', 'S', 'P', 'L', 'T', 'H', 0,
  /* 4210 */ 'V', 'P', 'O', 'P', 'C', 'N', 'T', 'H', 0,
  /* 4219 */ 'S', 'T', 'H', 0,
  /* 4223 */ 'V', 'M', 'U', 'L', 'E', 'U', 'H', 0,
  /* 4231 */ 'V', 'A', 'V', 'G', 'U', 'H', 0,
  /* 4238 */ 'V', 'M', 'I', 'N', 'U', 'H', 0,
  /* 4245 */ 'V', 'M', 'U', 'L', 'O', 'U', 'H', 0,
  /* 4253 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'U', 'H', 0,
  /* 4262 */ 'V', 'C', 'M', 'P', 'G', 'T', 'U', 'H', 0,
  /* 4271 */ 'V', 'M', 'A', 'X', 'U', 'H', 0,
  /* 4278 */ 'V', 'C', 'L', 'Z', 'H', 0,
  /* 4284 */ 'D', 'C', 'B', 'I', 0,
  /* 4289 */ 'I', 'C', 'B', 'I', 0,
  /* 4294 */ 'S', 'U', 'B', 'I', 0,
  /* 4299 */ 'D', 'C', 'C', 'C', 'I', 0,
  /* 4305 */ 'I', 'C', 'C', 'C', 'I', 0,
  /* 4311 */ 'T', 'A', 'B', 'O', 'R', 'T', 'D', 'C', 'I', 0,
  /* 4321 */ 'R', 'F', 'C', 'I', 0,
  /* 4326 */ 'R', 'F', 'M', 'C', 'I', 0,
  /* 4332 */ 'Q', 'V', 'G', 'P', 'C', 'I', 0,
  /* 4339 */ 'T', 'A', 'B', 'O', 'R', 'T', 'W', 'C', 'I', 0,
  /* 4349 */ 'S', 'R', 'A', 'D', 'I', 0,
  /* 4355 */ 'A', 'D', 'D', 'I', 0,
  /* 4360 */ 'R', 'F', 'D', 'I', 0,
  /* 4365 */ 'C', 'M', 'P', 'L', 'D', 'I', 0,
  /* 4372 */ 'C', 'L', 'R', 'L', 'S', 'L', 'D', 'I', 0,
  /* 4381 */ 'E', 'X', 'T', 'L', 'D', 'I', 0,
  /* 4388 */ 'X', 'X', 'P', 'E', 'R', 'M', 'D', 'I', 0,
  /* 4397 */ 'C', 'M', 'P', 'D', 'I', 0,
  /* 4403 */ 'C', 'L', 'R', 'R', 'D', 'I', 0,
  /* 4410 */ 'I', 'N', 'S', 'R', 'D', 'I', 0,
  /* 4417 */ 'R', 'O', 'T', 'R', 'D', 'I', 0,
  /* 4424 */ 'E', 'X', 'T', 'R', 'D', 'I', 0,
  /* 4431 */ 'T', 'D', 'I', 0,
  /* 4435 */ 'W', 'R', 'T', 'E', 'E', 'I', 0,
  /* 4442 */ 'R', 'F', 'I', 0,
  /* 4446 */ 'M', 'T', 'F', 'S', 'F', 'I', 0,
  /* 4453 */ 'E', 'V', 'S', 'P', 'L', 'A', 'T', 'F', 'I', 0,
  /* 4463 */ 'E', 'V', 'M', 'E', 'R', 'G', 'E', 'H', 'I', 0,
  /* 4473 */ 'E', 'V', 'M', 'E', 'R', 'G', 'E', 'L', 'O', 'H', 'I', 0,
  /* 4485 */ 'P', 'H', 'I', 0,
  /* 4489 */ 'T', 'L', 'B', 'L', 'I', 0,
  /* 4495 */ 'M', 'U', 'L', 'L', 'I', 0,
  /* 4501 */ 'R', 'L', 'D', 'I', 'M', 'I', 0,
  /* 4508 */ 'R', 'L', 'W', 'I', 'M', 'I', 0,
  /* 4515 */ 'E', 'V', 'M', 'H', 'E', 'S', 'M', 'I', 0,
  /* 4524 */ 'E', 'V', 'M', 'W', 'H', 'S', 'M', 'I', 0,
  /* 4533 */ 'E', 'V', 'M', 'H', 'O', 'S', 'M', 'I', 0,
  /* 4542 */ 'E', 'V', 'M', 'W', 'S', 'M', 'I', 0,
  /* 4550 */ 'E', 'V', 'M', 'H', 'E', 'U', 'M', 'I', 0,
  /* 4559 */ 'E', 'V', 'M', 'W', 'H', 'U', 'M', 'I', 0,
  /* 4568 */ 'E', 'V', 'M', 'W', 'L', 'U', 'M', 'I', 0,
  /* 4577 */ 'E', 'V', 'M', 'H', 'O', 'U', 'M', 'I', 0,
  /* 4586 */ 'E', 'V', 'M', 'W', 'U', 'M', 'I', 0,
  /* 4594 */ 'Q', 'V', 'A', 'L', 'I', 'G', 'N', 'I', 0,
  /* 4603 */ 'V', 'S', 'L', 'D', 'O', 'I', 0,
  /* 4610 */ 'X', 'S', 'R', 'D', 'P', 'I', 0,
  /* 4617 */ 'X', 'V', 'R', 'D', 'P', 'I', 0,
  /* 4624 */ 'X', 'V', 'R', 'S', 'P', 'I', 0,
  /* 4631 */ 'X', 'O', 'R', 'I', 0,
  /* 4636 */ 'Q', 'V', 'E', 'S', 'P', 'L', 'A', 'T', 'I', 0,
  /* 4646 */ 'E', 'V', 'S', 'P', 'L', 'A', 'T', 'I', 0,
  /* 4655 */ 'L', 'D', 't', 'o', 'c', 'J', 'T', 'I', 0,
  /* 4664 */ 'S', 'R', 'A', 'W', 'I', 0,
  /* 4670 */ 'X', 'X', 'S', 'L', 'D', 'W', 'I', 0,
  /* 4678 */ 'C', 'M', 'P', 'L', 'W', 'I', 0,
  /* 4685 */ 'E', 'V', 'R', 'L', 'W', 'I', 0,
  /* 4692 */ 'C', 'L', 'R', 'L', 'S', 'L', 'W', 'I', 0,
  /* 4701 */ 'I', 'N', 'S', 'L', 'W', 'I', 0,
  /* 4708 */ 'E', 'V', 'S', 'L', 'W', 'I', 0,
  /* 4715 */ 'E', 'X', 'T', 'L', 'W', 'I', 0,
  /* 4722 */ 'C', 'M', 'P', 'W', 'I', 0,
  /* 4728 */ 'C', 'L', 'R', 'R', 'W', 'I', 0,
  /* 4735 */ 'I', 'N', 'S', 'R', 'W', 'I', 0,
  /* 4742 */ 'R', 'O', 'T', 'R', 'W', 'I', 0,
  /* 4749 */ 'E', 'X', 'T', 'R', 'W', 'I', 0,
  /* 4756 */ 'L', 'S', 'W', 'I', 0,
  /* 4761 */ 'S', 'T', 'S', 'W', 'I', 0,
  /* 4767 */ 'T', 'W', 'I', 0,
  /* 4771 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'D', 'X', 'I', 0,
  /* 4781 */ 'Q', 'V', 'S', 'T', 'F', 'D', 'X', 'I', 0,
  /* 4790 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'S', 'X', 'I', 0,
  /* 4800 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'X', 'I', 0,
  /* 4809 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'D', 'U', 'X', 'I', 0,
  /* 4820 */ 'Q', 'V', 'S', 'T', 'F', 'D', 'U', 'X', 'I', 0,
  /* 4830 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'S', 'U', 'X', 'I', 0,
  /* 4841 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'U', 'X', 'I', 0,
  /* 4851 */ 'T', 'C', 'H', 'E', 'C', 'K', 0,
  /* 4858 */ 'Q', 'V', 'F', 'L', 'O', 'G', 'I', 'C', 'A', 'L', 0,
  /* 4869 */ 'B', 'L', 0,
  /* 4872 */ 'g', 'B', 'C', 'L', 0,
  /* 4877 */ 'B', 'C', 'C', 'L', 0,
  /* 4882 */ 'R', 'L', 'D', 'C', 'L', 0,
  /* 4888 */ 'R', 'L', 'D', 'I', 'C', 'L', 0,
  /* 4895 */ 'G', 'C', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 4904 */ 'E', 'H', '_', 'L', 'A', 'B', 'E', 'L', 0,
  /* 4913 */ 'T', 'L', 'B', 'I', 'E', 'L', 0,
  /* 4920 */ 'Q', 'V', 'F', 'S', 'E', 'L', 0,
  /* 4927 */ 'I', 'S', 'E', 'L', 0,
  /* 4932 */ 'V', 'S', 'E', 'L', 0,
  /* 4937 */ 'X', 'X', 'S', 'E', 'L', 0,
  /* 4943 */ 'D', 'S', 'S', 'A', 'L', 'L', 0,
  /* 4950 */ 'K', 'I', 'L', 'L', 0,
  /* 4955 */ 'B', 'L', 'R', 'L', 0,
  /* 4960 */ 'g', 'B', 'C', 'L', 'R', 'L', 0,
  /* 4967 */ 'B', 'C', 'C', 'L', 'R', 'L', 0,
  /* 4974 */ 'B', 'D', 'Z', 'L', 'R', 'L', 0,
  /* 4981 */ 'B', 'D', 'N', 'Z', 'L', 'R', 'L', 0,
  /* 4989 */ 'B', 'C', 'T', 'R', 'L', 0,
  /* 4995 */ 'g', 'B', 'C', 'C', 'T', 'R', 'L', 0,
  /* 5003 */ 'B', 'C', 'C', 'C', 'T', 'R', 'L', 0,
  /* 5011 */ 'L', 'V', 'S', 'L', 0,
  /* 5016 */ 'Q', 'V', 'F', 'M', 'U', 'L', 0,
  /* 5023 */ 'Q', 'V', 'F', 'X', 'M', 'U', 'L', 0,
  /* 5031 */ 'L', 'B', 'A', 'R', 'X', 'L', 0,
  /* 5038 */ 'L', 'D', 'A', 'R', 'X', 'L', 0,
  /* 5045 */ 'L', 'H', 'A', 'R', 'X', 'L', 0,
  /* 5052 */ 'L', 'W', 'A', 'R', 'X', 'L', 0,
  /* 5059 */ 'L', 'V', 'X', 'L', 0,
  /* 5064 */ 'S', 'T', 'V', 'X', 'L', 0,
  /* 5070 */ 'D', 'C', 'B', 'Z', 'L', 0,
  /* 5076 */ 'B', 'D', 'Z', 'L', 0,
  /* 5081 */ 'B', 'D', 'N', 'Z', 'L', 0,
  /* 5087 */ 'L', 'D', 't', 'o', 'c', 'L', 0,
  /* 5094 */ 'A', 'D', 'D', 'I', 't', 'o', 'c', 'L', 0,
  /* 5103 */ 'A', 'D', 'D', 'I', 't', 'l', 's', 'g', 'd', 'L', 0,
  /* 5114 */ 'A', 'D', 'D', 'I', 't', 'l', 's', 'l', 'd', 'L', 0,
  /* 5125 */ 'L', 'D', 'g', 'o', 't', 'T', 'p', 'r', 'e', 'l', 'L', 0,
  /* 5137 */ 'A', 'D', 'D', 'I', 'd', 't', 'p', 'r', 'e', 'l', 'L', 0,
  /* 5149 */ 'V', 'M', 'S', 'U', 'M', 'M', 'B', 'M', 0,
  /* 5158 */ 'V', 'S', 'U', 'B', 'U', 'B', 'M', 0,
  /* 5166 */ 'V', 'A', 'D', 'D', 'U', 'B', 'M', 0,
  /* 5174 */ 'V', 'M', 'S', 'U', 'M', 'U', 'B', 'M', 0,
  /* 5183 */ 'V', 'S', 'U', 'B', 'U', 'D', 'M', 0,
  /* 5191 */ 'V', 'A', 'D', 'D', 'U', 'D', 'M', 0,
  /* 5199 */ 'V', 'M', 'S', 'U', 'M', 'S', 'H', 'M', 0,
  /* 5208 */ 'V', 'S', 'U', 'B', 'U', 'H', 'M', 0,
  /* 5216 */ 'V', 'M', 'L', 'A', 'D', 'D', 'U', 'H', 'M', 0,
  /* 5226 */ 'V', 'A', 'D', 'D', 'U', 'H', 'M', 0,
  /* 5234 */ 'V', 'M', 'S', 'U', 'M', 'U', 'H', 'M', 0,
  /* 5243 */ 'T', 'R', 'E', 'C', 'L', 'A', 'I', 'M', 0,
  /* 5252 */ 'V', 'R', 'F', 'I', 'M', 0,
  /* 5258 */ 'X', 'S', 'R', 'D', 'P', 'I', 'M', 0,
  /* 5266 */ 'X', 'V', 'R', 'D', 'P', 'I', 'M', 0,
  /* 5274 */ 'X', 'V', 'R', 'S', 'P', 'I', 'M', 0,
  /* 5282 */ 'Q', 'V', 'F', 'R', 'I', 'M', 0,
  /* 5289 */ 'R', 'L', 'W', 'I', 'N', 'M', 0,
  /* 5296 */ 'R', 'L', 'W', 'N', 'M', 0,
  /* 5302 */ 'V', 'S', 'U', 'B', 'U', 'Q', 'M', 0,
  /* 5310 */ 'V', 'A', 'D', 'D', 'U', 'Q', 'M', 0,
  /* 5318 */ 'V', 'S', 'U', 'B', 'E', 'U', 'Q', 'M', 0,
  /* 5327 */ 'V', 'A', 'D', 'D', 'E', 'U', 'Q', 'M', 0,
  /* 5336 */ 'Q', 'V', 'F', 'P', 'E', 'R', 'M', 0,
  /* 5344 */ 'V', 'P', 'E', 'R', 'M', 0,
  /* 5350 */ 'I', 'N', 'L', 'I', 'N', 'E', 'A', 'S', 'M', 0,
  /* 5360 */ 'V', 'P', 'K', 'U', 'D', 'U', 'M', 0,
  /* 5368 */ 'V', 'P', 'K', 'U', 'H', 'U', 'M', 0,
  /* 5376 */ 'V', 'P', 'K', 'U', 'W', 'U', 'M', 0,
  /* 5384 */ 'V', 'S', 'U', 'B', 'U', 'W', 'M', 0,
  /* 5392 */ 'V', 'A', 'D', 'D', 'U', 'W', 'M', 0,
  /* 5400 */ 'V', 'M', 'U', 'L', 'U', 'W', 'M', 0,
  /* 5408 */ 'E', 'V', 'M', 'H', 'E', 'G', 'S', 'M', 'F', 'A', 'N', 0,
  /* 5420 */ 'E', 'V', 'M', 'H', 'O', 'G', 'S', 'M', 'F', 'A', 'N', 0,
  /* 5432 */ 'E', 'V', 'M', 'W', 'S', 'M', 'F', 'A', 'N', 0,
  /* 5442 */ 'E', 'V', 'M', 'W', 'S', 'S', 'F', 'A', 'N', 0,
  /* 5452 */ 'E', 'V', 'M', 'H', 'E', 'G', 'S', 'M', 'I', 'A', 'N', 0,
  /* 5464 */ 'E', 'V', 'M', 'H', 'O', 'G', 'S', 'M', 'I', 'A', 'N', 0,
  /* 5476 */ 'E', 'V', 'M', 'W', 'S', 'M', 'I', 'A', 'N', 0,
  /* 5486 */ 'E', 'V', 'M', 'H', 'E', 'G', 'U', 'M', 'I', 'A', 'N', 0,
  /* 5498 */ 'E', 'V', 'M', 'H', 'O', 'G', 'U', 'M', 'I', 'A', 'N', 0,
  /* 5510 */ 'E', 'V', 'M', 'W', 'U', 'M', 'I', 'A', 'N', 0,
  /* 5520 */ 'Q', 'V', 'F', 'T', 'S', 'T', 'N', 'A', 'N', 0,
  /* 5530 */ 'Q', 'V', 'F', 'C', 'P', 'S', 'G', 'N', 0,
  /* 5539 */ 'V', 'R', 'F', 'I', 'N', 0,
  /* 5545 */ 'T', 'B', 'E', 'G', 'I', 'N', 0,
  /* 5552 */ 'Q', 'V', 'F', 'R', 'I', 'N', 0,
  /* 5559 */ 'M', 'F', 'S', 'R', 'I', 'N', 0,
  /* 5566 */ 'M', 'T', 'S', 'R', 'I', 'N', 0,
  /* 5573 */ 'C', 'F', 'I', '_', 'I', 'N', 'S', 'T', 'R', 'U', 'C', 'T', 'I', 'O', 'N', 0,
  /* 5589 */ 'X', 'S', 'C', 'V', 'S', 'P', 'D', 'P', 'N', 0,
  /* 5599 */ 'X', 'S', 'C', 'V', 'D', 'P', 'S', 'P', 'N', 0,
  /* 5609 */ 'A', 'T', 'T', 'N', 0,
  /* 5614 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'D', 'O', 'W', 'N', 0,
  /* 5631 */ 'E', 'V', 'S', 'T', 'W', 'H', 'O', 0,
  /* 5639 */ 'E', 'n', 'f', 'o', 'r', 'c', 'e', 'I', 'E', 'I', 'O', 0,
  /* 5651 */ 'E', 'V', 'M', 'E', 'R', 'G', 'E', 'L', 'O', 0,
  /* 5661 */ 'E', 'V', 'M', 'E', 'R', 'G', 'E', 'H', 'I', 'L', 'O', 0,
  /* 5673 */ 'V', 'S', 'L', 'O', 0,
  /* 5678 */ 'V', 'S', 'R', 'O', 0,
  /* 5683 */ 'E', 'V', 'S', 'T', 'W', 'W', 'O', 0,
  /* 5691 */ 'S', 'T', 'A', 'C', 'K', 'M', 'A', 'P', 0,
  /* 5700 */ 'T', 'R', 'A', 'P', 0,
  /* 5705 */ 'X', 'S', 'N', 'M', 'S', 'U', 'B', 'A', 'D', 'P', 0,
  /* 5716 */ 'X', 'V', 'N', 'M', 'S', 'U', 'B', 'A', 'D', 'P', 0,
  /* 5727 */ 'X', 'S', 'M', 'S', 'U', 'B', 'A', 'D', 'P', 0,
  /* 5737 */ 'X', 'V', 'M', 'S', 'U', 'B', 'A', 'D', 'P', 0,
  /* 5747 */ 'X', 'S', 'N', 'M', 'A', 'D', 'D', 'A', 'D', 'P', 0,
  /* 5758 */ 'X', 'V', 'N', 'M', 'A', 'D', 'D', 'A', 'D', 'P', 0,
  /* 5769 */ 'X', 'S', 'M', 'A', 'D', 'D', 'A', 'D', 'P', 0,
  /* 5779 */ 'X', 'V', 'M', 'A', 'D', 'D', 'A', 'D', 'P', 0,
  /* 5789 */ 'X', 'S', 'S', 'U', 'B', 'D', 'P', 0,
  /* 5797 */ 'X', 'V', 'S', 'U', 'B', 'D', 'P', 0,
  /* 5805 */ 'X', 'S', 'A', 'D', 'D', 'D', 'P', 0,
  /* 5813 */ 'X', 'V', 'A', 'D', 'D', 'D', 'P', 0,
  /* 5821 */ 'X', 'S', 'C', 'V', 'S', 'X', 'D', 'D', 'P', 0,
  /* 5831 */ 'X', 'V', 'C', 'V', 'S', 'X', 'D', 'D', 'P', 0,
  /* 5841 */ 'X', 'S', 'C', 'V', 'U', 'X', 'D', 'D', 'P', 0,
  /* 5851 */ 'X', 'V', 'C', 'V', 'U', 'X', 'D', 'D', 'P', 0,
  /* 5861 */ 'X', 'V', 'C', 'M', 'P', 'G', 'E', 'D', 'P', 0,
  /* 5871 */ 'X', 'S', 'R', 'E', 'D', 'P', 0,
  /* 5878 */ 'X', 'V', 'R', 'E', 'D', 'P', 0,
  /* 5885 */ 'X', 'S', 'R', 'S', 'Q', 'R', 'T', 'E', 'D', 'P', 0,
  /* 5896 */ 'X', 'V', 'R', 'S', 'Q', 'R', 'T', 'E', 'D', 'P', 0,
  /* 5907 */ 'X', 'S', 'N', 'E', 'G', 'D', 'P', 0,
  /* 5915 */ 'X', 'V', 'N', 'E', 'G', 'D', 'P', 0,
  /* 5923 */ 'X', 'S', 'M', 'U', 'L', 'D', 'P', 0,
  /* 5931 */ 'X', 'V', 'M', 'U', 'L', 'D', 'P', 0,
  /* 5939 */ 'X', 'S', 'N', 'M', 'S', 'U', 'B', 'M', 'D', 'P', 0,
  /* 5950 */ 'X', 'V', 'N', 'M', 'S', 'U', 'B', 'M', 'D', 'P', 0,
  /* 5961 */ 'X', 'S', 'M', 'S', 'U', 'B', 'M', 'D', 'P', 0,
  /* 5971 */ 'X', 'V', 'M', 'S', 'U', 'B', 'M', 'D', 'P', 0,
  /* 5981 */ 'X', 'S', 'N', 'M', 'A', 'D', 'D', 'M', 'D', 'P', 0,
  /* 5992 */ 'X', 'V', 'N', 'M', 'A', 'D', 'D', 'M', 'D', 'P', 0,
  /* 6003 */ 'X', 'S', 'M', 'A', 'D', 'D', 'M', 'D', 'P', 0,
  /* 6013 */ 'X', 'V', 'M', 'A', 'D', 'D', 'M', 'D', 'P', 0,
  /* 6023 */ 'X', 'S', 'C', 'P', 'S', 'G', 'N', 'D', 'P', 0,
  /* 6033 */ 'X', 'V', 'C', 'P', 'S', 'G', 'N', 'D', 'P', 0,
  /* 6043 */ 'X', 'S', 'M', 'I', 'N', 'D', 'P', 0,
  /* 6051 */ 'X', 'V', 'M', 'I', 'N', 'D', 'P', 0,
  /* 6059 */ 'X', 'S', 'C', 'M', 'P', 'O', 'D', 'P', 0,
  /* 6068 */ 'X', 'S', 'C', 'V', 'S', 'P', 'D', 'P', 0,
  /* 6077 */ 'X', 'V', 'C', 'V', 'S', 'P', 'D', 'P', 0,
  /* 6086 */ 'X', 'V', 'C', 'M', 'P', 'E', 'Q', 'D', 'P', 0,
  /* 6096 */ 'X', 'S', 'N', 'A', 'B', 'S', 'D', 'P', 0,
  /* 6105 */ 'X', 'V', 'N', 'A', 'B', 'S', 'D', 'P', 0,
  /* 6114 */ 'X', 'S', 'A', 'B', 'S', 'D', 'P', 0,
  /* 6122 */ 'X', 'V', 'A', 'B', 'S', 'D', 'P', 0,
  /* 6130 */ 'X', 'V', 'C', 'M', 'P', 'G', 'T', 'D', 'P', 0,
  /* 6140 */ 'X', 'S', 'S', 'Q', 'R', 'T', 'D', 'P', 0,
  /* 6149 */ 'X', 'S', 'T', 'S', 'Q', 'R', 'T', 'D', 'P', 0,
  /* 6159 */ 'X', 'V', 'T', 'S', 'Q', 'R', 'T', 'D', 'P', 0,
  /* 6169 */ 'X', 'V', 'S', 'Q', 'R', 'T', 'D', 'P', 0,
  /* 6178 */ 'X', 'S', 'C', 'M', 'P', 'U', 'D', 'P', 0,
  /* 6187 */ 'X', 'S', 'D', 'I', 'V', 'D', 'P', 0,
  /* 6195 */ 'X', 'S', 'T', 'D', 'I', 'V', 'D', 'P', 0,
  /* 6204 */ 'X', 'V', 'T', 'D', 'I', 'V', 'D', 'P', 0,
  /* 6213 */ 'X', 'V', 'D', 'I', 'V', 'D', 'P', 0,
  /* 6221 */ 'X', 'V', 'C', 'V', 'S', 'X', 'W', 'D', 'P', 0,
  /* 6231 */ 'X', 'V', 'C', 'V', 'U', 'X', 'W', 'D', 'P', 0,
  /* 6241 */ 'X', 'S', 'M', 'A', 'X', 'D', 'P', 0,
  /* 6249 */ 'X', 'V', 'M', 'A', 'X', 'D', 'P', 0,
  /* 6257 */ 'V', 'C', 'M', 'P', 'B', 'F', 'P', 0,
  /* 6265 */ 'V', 'N', 'M', 'S', 'U', 'B', 'F', 'P', 0,
  /* 6274 */ 'V', 'S', 'U', 'B', 'F', 'P', 0,
  /* 6281 */ 'V', 'M', 'A', 'D', 'D', 'F', 'P', 0,
  /* 6289 */ 'V', 'A', 'D', 'D', 'F', 'P', 0,
  /* 6296 */ 'V', 'L', 'O', 'G', 'E', 'F', 'P', 0,
  /* 6304 */ 'V', 'C', 'M', 'P', 'G', 'E', 'F', 'P', 0,
  /* 6313 */ 'V', 'R', 'E', 'F', 'P', 0,
  /* 6319 */ 'V', 'E', 'X', 'P', 'T', 'E', 'F', 'P', 0,
  /* 6328 */ 'V', 'R', 'S', 'Q', 'R', 'T', 'E', 'F', 'P', 0,
  /* 6338 */ 'V', 'M', 'I', 'N', 'F', 'P', 0,
  /* 6345 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'F', 'P', 0,
  /* 6354 */ 'V', 'C', 'M', 'P', 'G', 'T', 'F', 'P', 0,
  /* 6363 */ 'V', 'M', 'A', 'X', 'F', 'P', 0,
  /* 6370 */ 'V', 'R', 'F', 'I', 'P', 0,
  /* 6376 */ 'X', 'S', 'R', 'D', 'P', 'I', 'P', 0,
  /* 6384 */ 'X', 'V', 'R', 'D', 'P', 'I', 'P', 0,
  /* 6392 */ 'X', 'V', 'R', 'S', 'P', 'I', 'P', 0,
  /* 6400 */ 'Q', 'V', 'F', 'R', 'I', 'P', 0,
  /* 6407 */ 'B', 'L', 'A', '8', '_', 'N', 'O', 'P', 0,
  /* 6416 */ 'B', 'L', '8', '_', 'N', 'O', 'P', 0,
  /* 6424 */ 'F', 'A', 'U', 'L', 'T', 'I', 'N', 'G', '_', 'L', 'O', 'A', 'D', '_', 'O', 'P', 0,
  /* 6441 */ 'X', 'S', 'N', 'M', 'S', 'U', 'B', 'A', 'S', 'P', 0,
  /* 6452 */ 'X', 'V', 'N', 'M', 'S', 'U', 'B', 'A', 'S', 'P', 0,
  /* 6463 */ 'X', 'S', 'M', 'S', 'U', 'B', 'A', 'S', 'P', 0,
  /* 6473 */ 'X', 'V', 'M', 'S', 'U', 'B', 'A', 'S', 'P', 0,
  /* 6483 */ 'X', 'S', 'N', 'M', 'A', 'D', 'D', 'A', 'S', 'P', 0,
  /* 6494 */ 'X', 'V', 'N', 'M', 'A', 'D', 'D', 'A', 'S', 'P', 0,
  /* 6505 */ 'X', 'S', 'M', 'A', 'D', 'D', 'A', 'S', 'P', 0,
  /* 6515 */ 'X', 'V', 'M', 'A', 'D', 'D', 'A', 'S', 'P', 0,
  /* 6525 */ 'X', 'S', 'S', 'U', 'B', 'S', 'P', 0,
  /* 6533 */ 'X', 'V', 'S', 'U', 'B', 'S', 'P', 0,
  /* 6541 */ 'X', 'S', 'A', 'D', 'D', 'S', 'P', 0,
  /* 6549 */ 'X', 'V', 'A', 'D', 'D', 'S', 'P', 0,
  /* 6557 */ 'X', 'S', 'C', 'V', 'S', 'X', 'D', 'S', 'P', 0,
  /* 6567 */ 'X', 'V', 'C', 'V', 'S', 'X', 'D', 'S', 'P', 0,
  /* 6577 */ 'X', 'S', 'C', 'V', 'U', 'X', 'D', 'S', 'P', 0,
  /* 6587 */ 'X', 'V', 'C', 'V', 'U', 'X', 'D', 'S', 'P', 0,
  /* 6597 */ 'X', 'V', 'C', 'M', 'P', 'G', 'E', 'S', 'P', 0,
  /* 6607 */ 'X', 'S', 'R', 'E', 'S', 'P', 0,
  /* 6614 */ 'X', 'V', 'R', 'E', 'S', 'P', 0,
  /* 6621 */ 'X', 'S', 'R', 'S', 'Q', 'R', 'T', 'E', 'S', 'P', 0,
  /* 6632 */ 'X', 'V', 'R', 'S', 'Q', 'R', 'T', 'E', 'S', 'P', 0,
  /* 6643 */ 'X', 'V', 'N', 'E', 'G', 'S', 'P', 0,
  /* 6651 */ 'X', 'S', 'M', 'U', 'L', 'S', 'P', 0,
  /* 6659 */ 'X', 'V', 'M', 'U', 'L', 'S', 'P', 0,
  /* 6667 */ 'X', 'S', 'N', 'M', 'S', 'U', 'B', 'M', 'S', 'P', 0,
  /* 6678 */ 'X', 'V', 'N', 'M', 'S', 'U', 'B', 'M', 'S', 'P', 0,
  /* 6689 */ 'X', 'S', 'M', 'S', 'U', 'B', 'M', 'S', 'P', 0,
  /* 6699 */ 'X', 'V', 'M', 'S', 'U', 'B', 'M', 'S', 'P', 0,
  /* 6709 */ 'X', 'S', 'N', 'M', 'A', 'D', 'D', 'M', 'S', 'P', 0,
  /* 6720 */ 'X', 'V', 'N', 'M', 'A', 'D', 'D', 'M', 'S', 'P', 0,
  /* 6731 */ 'X', 'S', 'M', 'A', 'D', 'D', 'M', 'S', 'P', 0,
  /* 6741 */ 'X', 'V', 'M', 'A', 'D', 'D', 'M', 'S', 'P', 0,
  /* 6751 */ 'X', 'V', 'C', 'P', 'S', 'G', 'N', 'S', 'P', 0,
  /* 6761 */ 'X', 'V', 'M', 'I', 'N', 'S', 'P', 0,
  /* 6769 */ 'X', 'S', 'C', 'V', 'D', 'P', 'S', 'P', 0,
  /* 6778 */ 'X', 'V', 'C', 'V', 'D', 'P', 'S', 'P', 0,
  /* 6787 */ 'X', 'V', 'C', 'M', 'P', 'E', 'Q', 'S', 'P', 0,
  /* 6797 */ 'Q', 'V', 'F', 'R', 'S', 'P', 0,
  /* 6804 */ 'X', 'V', 'N', 'A', 'B', 'S', 'S', 'P', 0,
  /* 6813 */ 'X', 'V', 'A', 'B', 'S', 'S', 'P', 0,
  /* 6821 */ 'X', 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'P', 0,
  /* 6831 */ 'X', 'S', 'S', 'Q', 'R', 'T', 'S', 'P', 0,
  /* 6840 */ 'X', 'V', 'T', 'S', 'Q', 'R', 'T', 'S', 'P', 0,
  /* 6850 */ 'X', 'V', 'S', 'Q', 'R', 'T', 'S', 'P', 0,
  /* 6859 */ 'X', 'S', 'D', 'I', 'V', 'S', 'P', 0,
  /* 6867 */ 'X', 'V', 'T', 'D', 'I', 'V', 'S', 'P', 0,
  /* 6876 */ 'X', 'V', 'D', 'I', 'V', 'S', 'P', 0,
  /* 6884 */ 'X', 'V', 'C', 'V', 'S', 'X', 'W', 'S', 'P', 0,
  /* 6894 */ 'X', 'V', 'C', 'V', 'U', 'X', 'W', 'S', 'P', 0,
  /* 6904 */ 'X', 'V', 'M', 'A', 'X', 'S', 'P', 0,
  /* 6912 */ 'A', 'D', 'J', 'C', 'A', 'L', 'L', 'S', 'T', 'A', 'C', 'K', 'U', 'P', 0,
  /* 6927 */ 'Q', 'V', 'F', 'C', 'M', 'P', 'E', 'Q', 0,
  /* 6936 */ 'E', 'V', 'C', 'M', 'P', 'E', 'Q', 0,
  /* 6944 */ 'V', 'B', 'P', 'E', 'R', 'M', 'Q', 0,
  /* 6952 */ 'V', 'S', 'U', 'B', 'C', 'U', 'Q', 0,
  /* 6960 */ 'V', 'A', 'D', 'D', 'C', 'U', 'Q', 0,
  /* 6968 */ 'V', 'S', 'U', 'B', 'E', 'C', 'U', 'Q', 0,
  /* 6977 */ 'V', 'A', 'D', 'D', 'E', 'C', 'U', 'Q', 0,
  /* 6986 */ 'M', 'B', 'A', 'R', 0,
  /* 6991 */ 'U', 'p', 'd', 'a', 't', 'e', 'G', 'B', 'R', 0,
  /* 7001 */ 'M', 'F', 'D', 'C', 'R', 0,
  /* 7007 */ 'R', 'L', 'D', 'C', 'R', 0,
  /* 7013 */ 'M', 'T', 'D', 'C', 'R', 0,
  /* 7019 */ 'M', 'F', 'C', 'R', 0,
  /* 7024 */ 'R', 'L', 'D', 'I', 'C', 'R', 0,
  /* 7031 */ 'M', 'F', 'V', 'S', 'C', 'R', 0,
  /* 7038 */ 'M', 'T', 'V', 'S', 'C', 'R', 0,
  /* 7045 */ 'R', 'E', 'S', 'T', 'O', 'R', 'E', '_', 'C', 'R', 0,
  /* 7056 */ 'S', 'P', 'I', 'L', 'L', '_', 'C', 'R', 0,
  /* 7065 */ 'A', 'D', 'D', 'I', 't', 'l', 's', 'g', 'd', 'L', 'A', 'D', 'D', 'R', 0,
  /* 7080 */ 'A', 'D', 'D', 'I', 't', 'l', 's', 'l', 'd', 'L', 'A', 'D', 'D', 'R', 0,
  /* 7095 */ 'G', 'E', 'T', 't', 'l', 's', 'l', 'd', 'A', 'D', 'D', 'R', 0,
  /* 7108 */ 'G', 'E', 'T', 't', 'l', 's', 'A', 'D', 'D', 'R', 0,
  /* 7119 */ 'V', 'N', 'C', 'I', 'P', 'H', 'E', 'R', 0,
  /* 7128 */ 'V', 'C', 'I', 'P', 'H', 'E', 'R', 0,
  /* 7136 */ 'B', 'L', 'R', 0,
  /* 7140 */ 'g', 'B', 'C', 'L', 'R', 0,
  /* 7146 */ 'B', 'C', 'C', 'L', 'R', 0,
  /* 7152 */ 'M', 'F', 'L', 'R', 0,
  /* 7157 */ 'M', 'T', 'L', 'R', 0,
  /* 7162 */ 'B', 'D', 'Z', 'L', 'R', 0,
  /* 7168 */ 'B', 'D', 'N', 'Z', 'L', 'R', 0,
  /* 7175 */ 'M', 'o', 'v', 'e', 'P', 'C', 't', 'o', 'L', 'R', 0,
  /* 7186 */ 'M', 'o', 'v', 'e', 'G', 'O', 'T', 't', 'o', 'L', 'R', 0,
  /* 7198 */ 'Q', 'V', 'F', 'M', 'R', 0,
  /* 7204 */ 'X', 'X', 'L', 'O', 'R', 0,
  /* 7210 */ 'X', 'X', 'L', 'N', 'O', 'R', 0,
  /* 7217 */ 'C', 'R', 'N', 'O', 'R', 0,
  /* 7223 */ 'E', 'V', 'N', 'O', 'R', 0,
  /* 7229 */ 'C', 'R', 'O', 'R', 0,
  /* 7234 */ 'E', 'V', 'O', 'R', 0,
  /* 7239 */ 'X', 'X', 'L', 'X', 'O', 'R', 0,
  /* 7246 */ 'V', 'P', 'E', 'R', 'M', 'X', 'O', 'R', 0,
  /* 7255 */ 'C', 'R', 'X', 'O', 'R', 0,
  /* 7261 */ 'E', 'V', 'X', 'O', 'R', 0,
  /* 7267 */ 'M', 'F', 'S', 'P', 'R', 0,
  /* 7273 */ 'M', 'T', 'S', 'P', 'R', 0,
  /* 7279 */ 'M', 'F', 'S', 'R', 0,
  /* 7284 */ 'M', 'F', 'M', 'S', 'R', 0,
  /* 7290 */ 'M', 'T', 'M', 'S', 'R', 0,
  /* 7296 */ 'M', 'T', 'S', 'R', 0,
  /* 7301 */ 'L', 'V', 'S', 'R', 0,
  /* 7306 */ 'T', 'A', 'I', 'L', 'B', 'C', 'T', 'R', 0,
  /* 7315 */ 'g', 'B', 'C', 'C', 'T', 'R', 0,
  /* 7322 */ 'B', 'C', 'C', 'C', 'T', 'R', 0,
  /* 7329 */ 'M', 'F', 'C', 'T', 'R', 0,
  /* 7335 */ 'M', 'T', 'C', 'T', 'R', 0,
  /* 7341 */ 'Q', 'V', 'F', 'A', 'B', 'S', 0,
  /* 7348 */ 'Q', 'V', 'F', 'N', 'A', 'B', 'S', 0,
  /* 7356 */ 'E', 'V', 'A', 'B', 'S', 0,
  /* 7362 */ 'V', 'S', 'U', 'M', '4', 'S', 'B', 'S', 0,
  /* 7371 */ 'V', 'S', 'U', 'B', 'S', 'B', 'S', 0,
  /* 7379 */ 'V', 'A', 'D', 'D', 'S', 'B', 'S', 0,
  /* 7387 */ 'V', 'S', 'U', 'M', '4', 'U', 'B', 'S', 0,
  /* 7396 */ 'V', 'S', 'U', 'B', 'U', 'B', 'S', 0,
  /* 7404 */ 'V', 'A', 'D', 'D', 'U', 'B', 'S', 0,
  /* 7412 */ 'Q', 'V', 'F', 'S', 'U', 'B', 'S', 0,
  /* 7420 */ 'Q', 'V', 'F', 'M', 'S', 'U', 'B', 'S', 0,
  /* 7429 */ 'Q', 'V', 'F', 'N', 'M', 'S', 'U', 'B', 'S', 0,
  /* 7439 */ 'Q', 'V', 'F', 'A', 'D', 'D', 'S', 0,
  /* 7447 */ 'Q', 'V', 'F', 'M', 'A', 'D', 'D', 'S', 0,
  /* 7456 */ 'Q', 'V', 'F', 'N', 'M', 'A', 'D', 'D', 'S', 0,
  /* 7466 */ 'Q', 'V', 'F', 'X', 'X', 'C', 'P', 'N', 'M', 'A', 'D', 'D', 'S', 0,
  /* 7480 */ 'Q', 'V', 'F', 'X', 'X', 'N', 'P', 'M', 'A', 'D', 'D', 'S', 0,
  /* 7493 */ 'Q', 'V', 'F', 'X', 'M', 'A', 'D', 'D', 'S', 0,
  /* 7503 */ 'Q', 'V', 'F', 'X', 'X', 'M', 'A', 'D', 'D', 'S', 0,
  /* 7514 */ 'Q', 'V', 'F', 'C', 'F', 'I', 'D', 'S', 0,
  /* 7523 */ 'D', 'C', 'B', 'T', 'D', 'S', 0,
  /* 7530 */ 'D', 'C', 'B', 'T', 'S', 'T', 'D', 'S', 0,
  /* 7539 */ 'X', 'S', 'C', 'V', 'D', 'P', 'S', 'X', 'D', 'S', 0,
  /* 7550 */ 'X', 'V', 'C', 'V', 'D', 'P', 'S', 'X', 'D', 'S', 0,
  /* 7561 */ 'X', 'V', 'C', 'V', 'S', 'P', 'S', 'X', 'D', 'S', 0,
  /* 7572 */ 'X', 'S', 'C', 'V', 'D', 'P', 'U', 'X', 'D', 'S', 0,
  /* 7583 */ 'X', 'V', 'C', 'V', 'D', 'P', 'U', 'X', 'D', 'S', 0,
  /* 7594 */ 'X', 'V', 'C', 'V', 'S', 'P', 'U', 'X', 'D', 'S', 0,
  /* 7605 */ 'V', '_', 'S', 'E', 'T', 'A', 'L', 'L', 'O', 'N', 'E', 'S', 0,
  /* 7618 */ 'Q', 'V', 'F', 'R', 'E', 'S', 0,
  /* 7625 */ 'Q', 'V', 'F', 'R', 'S', 'Q', 'R', 'T', 'E', 'S', 0,
  /* 7636 */ 'M', 'F', 'F', 'S', 0,
  /* 7641 */ 'L', 'F', 'S', 0,
  /* 7645 */ 'M', 'C', 'R', 'F', 'S', 0,
  /* 7651 */ 'S', 'T', 'F', 'S', 0,
  /* 7656 */ 'F', 'N', 'E', 'G', 'S', 0,
  /* 7662 */ 'V', 'S', 'U', 'M', '4', 'S', 'H', 'S', 0,
  /* 7671 */ 'V', 'S', 'U', 'B', 'S', 'H', 'S', 0,
  /* 7679 */ 'V', 'M', 'H', 'A', 'D', 'D', 'S', 'H', 'S', 0,
  /* 7689 */ 'V', 'M', 'H', 'R', 'A', 'D', 'D', 'S', 'H', 'S', 0,
  /* 7700 */ 'V', 'A', 'D', 'D', 'S', 'H', 'S', 0,
  /* 7708 */ 'V', 'M', 'S', 'U', 'M', 'S', 'H', 'S', 0,
  /* 7717 */ 'V', 'S', 'U', 'B', 'U', 'H', 'S', 0,
  /* 7725 */ 'V', 'A', 'D', 'D', 'U', 'H', 'S', 0,
  /* 7733 */ 'V', 'M', 'S', 'U', 'M', 'U', 'H', 'S', 0,
  /* 7742 */ 'S', 'U', 'B', 'I', 'S', 0,
  /* 7748 */ 'A', 'D', 'D', 'I', 'S', 0,
  /* 7754 */ 'L', 'I', 'S', 0,
  /* 7758 */ 'X', 'O', 'R', 'I', 'S', 0,
  /* 7764 */ 'E', 'V', 'S', 'R', 'W', 'I', 'S', 0,
  /* 7772 */ 'F', 'S', 'E', 'L', 'S', 0,
  /* 7778 */ 'A', 'D', 'D', '4', 'T', 'L', 'S', 0,
  /* 7786 */ 'A', 'D', 'D', '8', 'T', 'L', 'S', 0,
  /* 7794 */ 'B', 'L', '8', '_', 'T', 'L', 'S', 0,
  /* 7802 */ 'B', 'L', '_', 'T', 'L', 'S', 0,
  /* 7809 */ 'B', 'L', '8', '_', 'N', 'O', 'P', '_', 'T', 'L', 'S', 0,
  /* 7821 */ 'Q', 'V', 'F', 'M', 'U', 'L', 'S', 0,
  /* 7829 */ 'Q', 'V', 'F', 'X', 'M', 'U', 'L', 'S', 0,
  /* 7838 */ 'F', 'R', 'I', 'M', 'S', 0,
  /* 7844 */ 'F', 'C', 'P', 'S', 'G', 'N', 'S', 0,
  /* 7852 */ 'F', 'R', 'I', 'N', 'S', 0,
  /* 7858 */ 'E', 'V', 'L', 'W', 'H', 'O', 'S', 0,
  /* 7866 */ 'F', 'R', 'I', 'P', 'S', 0,
  /* 7872 */ 'C', 'O', 'P', 'Y', '_', 'T', 'O', '_', 'R', 'E', 'G', 'C', 'L', 'A', 'S', 'S', 0,
  /* 7889 */ 'F', 'A', 'B', 'S', 'S', 0,
  /* 7895 */ 'F', 'N', 'A', 'B', 'S', 'S', 0,
  /* 7902 */ 'V', 'P', 'K', 'S', 'D', 'S', 'S', 0,
  /* 7910 */ 'V', 'P', 'K', 'S', 'H', 'S', 'S', 0,
  /* 7918 */ 'V', 'P', 'K', 'S', 'W', 'S', 'S', 0,
  /* 7926 */ 'E', 'V', 'C', 'M', 'P', 'G', 'T', 'S', 0,
  /* 7935 */ 'E', 'V', 'C', 'M', 'P', 'L', 'T', 'S', 0,
  /* 7944 */ 'F', 'S', 'Q', 'R', 'T', 'S', 0,
  /* 7951 */ 'Q', 'V', 'F', 'C', 'F', 'I', 'D', 'U', 'S', 0,
  /* 7961 */ 'V', 'P', 'K', 'S', 'D', 'U', 'S', 0,
  /* 7969 */ 'V', 'P', 'K', 'U', 'D', 'U', 'S', 0,
  /* 7977 */ 'V', 'P', 'K', 'S', 'H', 'U', 'S', 0,
  /* 7985 */ 'V', 'P', 'K', 'U', 'H', 'U', 'S', 0,
  /* 7993 */ 'F', 'C', 'M', 'P', 'U', 'S', 0,
  /* 8000 */ 'V', 'P', 'K', 'S', 'W', 'U', 'S', 0,
  /* 8008 */ 'V', 'P', 'K', 'U', 'W', 'U', 'S', 0,
  /* 8016 */ 'F', 'D', 'I', 'V', 'S', 0,
  /* 8022 */ 'E', 'V', 'S', 'R', 'W', 'S', 0,
  /* 8029 */ 'V', 'S', 'U', 'M', '2', 'S', 'W', 'S', 0,
  /* 8038 */ 'V', 'S', 'U', 'B', 'S', 'W', 'S', 0,
  /* 8046 */ 'V', 'A', 'D', 'D', 'S', 'W', 'S', 0,
  /* 8054 */ 'V', 'S', 'U', 'M', 'S', 'W', 'S', 0,
  /* 8062 */ 'V', 'S', 'U', 'B', 'U', 'W', 'S', 0,
  /* 8070 */ 'V', 'A', 'D', 'D', 'U', 'W', 'S', 0,
  /* 8078 */ 'E', 'V', 'D', 'I', 'V', 'W', 'S', 0,
  /* 8086 */ 'X', 'S', 'C', 'V', 'D', 'P', 'S', 'X', 'W', 'S', 0,
  /* 8097 */ 'X', 'V', 'C', 'V', 'D', 'P', 'S', 'X', 'W', 'S', 0,
  /* 8108 */ 'X', 'V', 'C', 'V', 'S', 'P', 'S', 'X', 'W', 'S', 0,
  /* 8119 */ 'X', 'S', 'C', 'V', 'D', 'P', 'U', 'X', 'W', 'S', 0,
  /* 8130 */ 'X', 'V', 'C', 'V', 'D', 'P', 'U', 'X', 'W', 'S', 0,
  /* 8141 */ 'X', 'V', 'C', 'V', 'S', 'P', 'U', 'X', 'W', 'S', 0,
  /* 8152 */ 'V', 'C', 'T', 'S', 'X', 'S', 0,
  /* 8159 */ 'V', 'C', 'T', 'U', 'X', 'S', 0,
  /* 8166 */ 'F', 'R', 'I', 'Z', 'S', 0,
  /* 8172 */ 'E', 'V', 'L', 'H', 'H', 'E', 'S', 'P', 'L', 'A', 'T', 0,
  /* 8184 */ 'E', 'V', 'L', 'W', 'H', 'S', 'P', 'L', 'A', 'T', 0,
  /* 8195 */ 'E', 'V', 'L', 'H', 'H', 'O', 'S', 'S', 'P', 'L', 'A', 'T', 0,
  /* 8208 */ 'E', 'V', 'L', 'H', 'H', 'O', 'U', 'S', 'P', 'L', 'A', 'T', 0,
  /* 8221 */ 'E', 'V', 'L', 'W', 'W', 'S', 'P', 'L', 'A', 'T', 0,
  /* 8232 */ 'D', 'C', 'B', 'T', 0,
  /* 8237 */ 'I', 'C', 'B', 'T', 0,
  /* 8242 */ 'D', 'C', 'B', 'T', 'C', 'T', 0,
  /* 8249 */ 'D', 'C', 'B', 'T', 'S', 'T', 'C', 'T', 0,
  /* 8258 */ 'T', 'C', 'H', 'E', 'C', 'K', '_', 'R', 'E', 'T', 0,
  /* 8269 */ 'C', 'R', '6', 'S', 'E', 'T', 0,
  /* 8276 */ 'D', 'Y', 'N', 'A', 'R', 'E', 'A', 'O', 'F', 'F', 'S', 'E', 'T', 0,
  /* 8290 */ 'C', 'R', '6', 'U', 'N', 'S', 'E', 'T', 0,
  /* 8299 */ 'C', 'R', 'U', 'N', 'S', 'E', 'T', 0,
  /* 8307 */ 'C', 'R', 'S', 'E', 'T', 0,
  /* 8313 */ 'Q', 'V', 'F', 'C', 'M', 'P', 'G', 'T', 0,
  /* 8322 */ 'W', 'A', 'I', 'T', 0,
  /* 8327 */ 'R', 'E', 'S', 'T', 'O', 'R', 'E', '_', 'C', 'R', 'B', 'I', 'T', 0,
  /* 8341 */ 'S', 'P', 'I', 'L', 'L', '_', 'C', 'R', 'B', 'I', 'T', 0,
  /* 8353 */ 'A', 'N', 'D', 'I', 'o', '_', '1', '_', 'E', 'Q', '_', 'B', 'I', 'T', 0,
  /* 8368 */ 'A', 'N', 'D', 'I', 'o', '_', '1', '_', 'G', 'T', '_', 'B', 'I', 'T', 0,
  /* 8383 */ 'Q', 'V', 'F', 'C', 'M', 'P', 'L', 'T', 0,
  /* 8392 */ 'S', 'T', 'A', 'T', 'E', 'P', 'O', 'I', 'N', 'T', 0,
  /* 8403 */ 'P', 'A', 'T', 'C', 'H', 'P', 'O', 'I', 'N', 'T', 0,
  /* 8414 */ 'P', 'P', 'C', '3', '2', 'G', 'O', 'T', 0,
  /* 8423 */ 'P', 'P', 'C', '3', '2', 'P', 'I', 'C', 'G', 'O', 'T', 0,
  /* 8435 */ 'L', 'D', 't', 'o', 'c', 'C', 'P', 'T', 0,
  /* 8444 */ 'T', 'R', 'E', 'C', 'H', 'K', 'P', 'T', 0,
  /* 8453 */ 'L', 'I', 'F', 'E', 'T', 'I', 'M', 'E', '_', 'S', 'T', 'A', 'R', 'T', 0,
  /* 8468 */ 'T', 'A', 'B', 'O', 'R', 'T', 0,
  /* 8475 */ 'F', 'S', 'Q', 'R', 'T', 0,
  /* 8481 */ 'V', 'N', 'C', 'I', 'P', 'H', 'E', 'R', 'L', 'A', 'S', 'T', 0,
  /* 8494 */ 'V', 'C', 'I', 'P', 'H', 'E', 'R', 'L', 'A', 'S', 'T', 0,
  /* 8506 */ 'D', 'C', 'B', 'S', 'T', 0,
  /* 8512 */ 'D', 'S', 'T', 0,
  /* 8516 */ 'D', 'C', 'B', 'T', 'S', 'T', 0,
  /* 8523 */ 'D', 'S', 'T', 'S', 'T', 0,
  /* 8529 */ 'D', 'C', 'B', 'T', 'T', 0,
  /* 8535 */ 'D', 'S', 'T', 'T', 0,
  /* 8540 */ 'D', 'C', 'B', 'T', 'S', 'T', 'T', 0,
  /* 8548 */ 'D', 'S', 'T', 'S', 'T', 'T', 0,
  /* 8555 */ 'L', 'H', 'A', 'U', 0,
  /* 8560 */ 'S', 'T', 'B', 'U', 0,
  /* 8565 */ 'L', 'F', 'D', 'U', 0,
  /* 8570 */ 'S', 'T', 'F', 'D', 'U', 0,
  /* 8576 */ 'M', 'U', 'L', 'H', 'D', 'U', 0,
  /* 8583 */ 'Q', 'V', 'F', 'C', 'F', 'I', 'D', 'U', 0,
  /* 8592 */ 'Q', 'V', 'F', 'C', 'T', 'I', 'D', 'U', 0,
  /* 8601 */ 'L', 'D', 'U', 0,
  /* 8605 */ 'S', 'T', 'D', 'U', 0,
  /* 8610 */ 'D', 'I', 'V', 'D', 'U', 0,
  /* 8616 */ 'D', 'I', 'V', 'D', 'E', 'U', 0,
  /* 8623 */ 'D', 'I', 'V', 'W', 'E', 'U', 0,
  /* 8630 */ 'S', 'T', 'H', 'U', 0,
  /* 8635 */ 'E', 'V', 'S', 'R', 'W', 'I', 'U', 0,
  /* 8643 */ 'E', 'V', 'L', 'W', 'H', 'O', 'U', 0,
  /* 8651 */ 'L', 'F', 'S', 'U', 0,
  /* 8656 */ 'S', 'T', 'F', 'S', 'U', 0,
  /* 8662 */ 'E', 'V', 'C', 'M', 'P', 'G', 'T', 'U', 0,
  /* 8671 */ 'E', 'V', 'C', 'M', 'P', 'L', 'T', 'U', 0,
  /* 8680 */ 'M', 'U', 'L', 'H', 'W', 'U', 0,
  /* 8687 */ 'Q', 'V', 'F', 'C', 'T', 'I', 'W', 'U', 0,
  /* 8696 */ 'E', 'V', 'S', 'R', 'W', 'U', 0,
  /* 8703 */ 'S', 'T', 'W', 'U', 0,
  /* 8708 */ 'E', 'V', 'D', 'I', 'V', 'W', 'U', 0,
  /* 8716 */ 'L', 'B', 'Z', 'U', 0,
  /* 8721 */ 'L', 'H', 'Z', 'U', 0,
  /* 8726 */ 'L', 'W', 'Z', 'U', 0,
  /* 8731 */ 'F', 'D', 'I', 'V', 0,
  /* 8736 */ 'X', 'X', 'L', 'E', 'Q', 'V', 0,
  /* 8743 */ 'C', 'R', 'E', 'Q', 'V', 0,
  /* 8749 */ 'E', 'V', 'E', 'Q', 'V', 0,
  /* 8755 */ 'E', 'V', 'M', 'H', 'E', 'S', 'M', 'F', 'A', 'A', 'W', 0,
  /* 8767 */ 'E', 'V', 'M', 'H', 'O', 'S', 'M', 'F', 'A', 'A', 'W', 0,
  /* 8779 */ 'E', 'V', 'M', 'H', 'E', 'S', 'S', 'F', 'A', 'A', 'W', 0,
  /* 8791 */ 'E', 'V', 'M', 'H', 'O', 'S', 'S', 'F', 'A', 'A', 'W', 0,
  /* 8803 */ 'E', 'V', 'A', 'D', 'D', 'S', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8815 */ 'E', 'V', 'M', 'H', 'E', 'S', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8827 */ 'E', 'V', 'S', 'U', 'B', 'F', 'S', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8840 */ 'E', 'V', 'M', 'W', 'L', 'S', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8852 */ 'E', 'V', 'M', 'H', 'O', 'S', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8864 */ 'E', 'V', 'A', 'D', 'D', 'U', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8876 */ 'E', 'V', 'M', 'H', 'E', 'U', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8888 */ 'E', 'V', 'S', 'U', 'B', 'F', 'U', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8901 */ 'E', 'V', 'M', 'W', 'L', 'U', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8913 */ 'E', 'V', 'M', 'H', 'O', 'U', 'M', 'I', 'A', 'A', 'W', 0,
  /* 8925 */ 'E', 'V', 'A', 'D', 'D', 'S', 'S', 'I', 'A', 'A', 'W', 0,
  /* 8937 */ 'E', 'V', 'M', 'H', 'E', 'S', 'S', 'I', 'A', 'A', 'W', 0,
  /* 8949 */ 'E', 'V', 'S', 'U', 'B', 'F', 'S', 'S', 'I', 'A', 'A', 'W', 0,
  /* 8962 */ 'E', 'V', 'M', 'W', 'L', 'S', 'S', 'I', 'A', 'A', 'W', 0,
  /* 8974 */ 'E', 'V', 'M', 'H', 'O', 'S', 'S', 'I', 'A', 'A', 'W', 0,
  /* 8986 */ 'E', 'V', 'A', 'D', 'D', 'U', 'S', 'I', 'A', 'A', 'W', 0,
  /* 8998 */ 'E', 'V', 'M', 'H', 'E', 'U', 'S', 'I', 'A', 'A', 'W', 0,
  /* 9010 */ 'E', 'V', 'S', 'U', 'B', 'F', 'U', 'S', 'I', 'A', 'A', 'W', 0,
  /* 9023 */ 'E', 'V', 'M', 'W', 'L', 'U', 'S', 'I', 'A', 'A', 'W', 0,
  /* 9035 */ 'E', 'V', 'M', 'H', 'O', 'U', 'S', 'I', 'A', 'A', 'W', 0,
  /* 9047 */ 'V', 'S', 'H', 'A', 'S', 'I', 'G', 'M', 'A', 'W', 0,
  /* 9058 */ 'V', 'S', 'R', 'A', 'W', 0,
  /* 9064 */ 'E', 'V', 'A', 'D', 'D', 'W', 0,
  /* 9071 */ 'E', 'V', 'L', 'D', 'W', 0,
  /* 9077 */ 'E', 'V', 'R', 'N', 'D', 'W', 0,
  /* 9084 */ 'E', 'V', 'S', 'T', 'D', 'W', 0,
  /* 9091 */ 'V', 'M', 'R', 'G', 'E', 'W', 0,
  /* 9098 */ 'E', 'V', 'S', 'U', 'B', 'F', 'W', 0,
  /* 9106 */ 'E', 'V', 'S', 'U', 'B', 'I', 'F', 'W', 0,
  /* 9115 */ 'V', 'M', 'R', 'G', 'H', 'W', 0,
  /* 9122 */ 'X', 'X', 'M', 'R', 'G', 'H', 'W', 0,
  /* 9130 */ 'M', 'U', 'L', 'H', 'W', 0,
  /* 9136 */ 'E', 'V', 'A', 'D', 'D', 'I', 'W', 0,
  /* 9144 */ 'Q', 'V', 'F', 'C', 'T', 'I', 'W', 0,
  /* 9152 */ 'V', 'M', 'R', 'G', 'L', 'W', 0,
  /* 9159 */ 'X', 'X', 'M', 'R', 'G', 'L', 'W', 0,
  /* 9167 */ 'M', 'U', 'L', 'L', 'W', 0,
  /* 9173 */ 'C', 'M', 'P', 'L', 'W', 0,
  /* 9179 */ 'E', 'V', 'R', 'L', 'W', 0,
  /* 9185 */ 'E', 'V', 'S', 'L', 'W', 0,
  /* 9191 */ 'L', 'M', 'W', 0,
  /* 9195 */ 'S', 'T', 'M', 'W', 0,
  /* 9200 */ 'V', 'P', 'M', 'S', 'U', 'M', 'W', 0,
  /* 9208 */ 'E', 'V', 'M', 'H', 'E', 'S', 'M', 'F', 'A', 'N', 'W', 0,
  /* 9220 */ 'E', 'V', 'M', 'H', 'O', 'S', 'M', 'F', 'A', 'N', 'W', 0,
  /* 9232 */ 'E', 'V', 'M', 'H', 'E', 'S', 'S', 'F', 'A', 'N', 'W', 0,
  /* 9244 */ 'E', 'V', 'M', 'H', 'O', 'S', 'S', 'F', 'A', 'N', 'W', 0,
  /* 9256 */ 'E', 'V', 'M', 'H', 'E', 'S', 'M', 'I', 'A', 'N', 'W', 0,
  /* 9268 */ 'E', 'V', 'M', 'W', 'L', 'S', 'M', 'I', 'A', 'N', 'W', 0,
  /* 9280 */ 'E', 'V', 'M', 'H', 'O', 'S', 'M', 'I', 'A', 'N', 'W', 0,
  /* 9292 */ 'E', 'V', 'M', 'H', 'E', 'U', 'M', 'I', 'A', 'N', 'W', 0,
  /* 9304 */ 'E', 'V', 'M', 'W', 'L', 'U', 'M', 'I', 'A', 'N', 'W', 0,
  /* 9316 */ 'E', 'V', 'M', 'H', 'O', 'U', 'M', 'I', 'A', 'N', 'W', 0,
  /* 9328 */ 'E', 'V', 'M', 'H', 'E', 'S', 'S', 'I', 'A', 'N', 'W', 0,
  /* 9340 */ 'E', 'V', 'M', 'W', 'L', 'S', 'S', 'I', 'A', 'N', 'W', 0,
  /* 9352 */ 'E', 'V', 'M', 'H', 'O', 'S', 'S', 'I', 'A', 'N', 'W', 0,
  /* 9364 */ 'E', 'V', 'M', 'H', 'E', 'U', 'S', 'I', 'A', 'N', 'W', 0,
  /* 9376 */ 'E', 'V', 'M', 'W', 'L', 'U', 'S', 'I', 'A', 'N', 'W', 0,
  /* 9388 */ 'E', 'V', 'M', 'H', 'O', 'U', 'S', 'I', 'A', 'N', 'W', 0,
  /* 9400 */ 'V', 'M', 'R', 'G', 'O', 'W', 0,
  /* 9407 */ 'C', 'M', 'P', 'W', 0,
  /* 9412 */ 'V', 'S', 'R', 'W', 0,
  /* 9417 */ 'V', 'M', 'U', 'L', 'E', 'S', 'W', 0,
  /* 9425 */ 'V', 'A', 'V', 'G', 'S', 'W', 0,
  /* 9432 */ 'V', 'U', 'P', 'K', 'H', 'S', 'W', 0,
  /* 9440 */ 'V', 'S', 'P', 'L', 'T', 'I', 'S', 'W', 0,
  /* 9449 */ 'V', 'U', 'P', 'K', 'L', 'S', 'W', 0,
  /* 9457 */ 'E', 'V', 'C', 'N', 'T', 'L', 'S', 'W', 0,
  /* 9466 */ 'V', 'M', 'I', 'N', 'S', 'W', 0,
  /* 9473 */ 'V', 'M', 'U', 'L', 'O', 'S', 'W', 0,
  /* 9481 */ 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'W', 0,
  /* 9490 */ 'E', 'X', 'T', 'S', 'W', 0,
  /* 9496 */ 'V', 'M', 'A', 'X', 'S', 'W', 0,
  /* 9503 */ 'V', 'S', 'P', 'L', 'T', 'W', 0,
  /* 9510 */ 'X', 'X', 'S', 'P', 'L', 'T', 'W', 0,
  /* 9518 */ 'V', 'P', 'O', 'P', 'C', 'N', 'T', 'W', 0,
  /* 9527 */ 'S', 'T', 'W', 0,
  /* 9531 */ 'V', 'S', 'U', 'B', 'C', 'U', 'W', 0,
  /* 9539 */ 'V', 'A', 'D', 'D', 'C', 'U', 'W', 0,
  /* 9547 */ 'V', 'M', 'U', 'L', 'E', 'U', 'W', 0,
  /* 9555 */ 'V', 'A', 'V', 'G', 'U', 'W', 0,
  /* 9562 */ 'V', 'M', 'I', 'N', 'U', 'W', 0,
  /* 9569 */ 'V', 'M', 'U', 'L', 'O', 'U', 'W', 0,
  /* 9577 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'U', 'W', 0,
  /* 9586 */ 'V', 'C', 'M', 'P', 'G', 'T', 'U', 'W', 0,
  /* 9595 */ 'V', 'M', 'A', 'X', 'U', 'W', 0,
  /* 9602 */ 'D', 'I', 'V', 'W', 0,
  /* 9607 */ 'V', 'C', 'L', 'Z', 'W', 0,
  /* 9613 */ 'E', 'V', 'C', 'N', 'T', 'L', 'Z', 'W', 0,
  /* 9622 */ 'L', 'X', 'V', 'D', '2', 'X', 0,
  /* 9629 */ 'S', 'T', 'X', 'V', 'D', '2', 'X', 0,
  /* 9637 */ 'L', 'X', 'V', 'W', '4', 'X', 0,
  /* 9644 */ 'S', 'T', 'X', 'V', 'W', '4', 'X', 0,
  /* 9652 */ 'L', 'H', 'A', 'X', 0,
  /* 9657 */ 'T', 'L', 'B', 'I', 'V', 'A', 'X', 0,
  /* 9665 */ 'Q', 'V', 'L', 'F', 'I', 'W', 'A', 'X', 0,
  /* 9674 */ 'L', 'X', 'S', 'I', 'W', 'A', 'X', 0,
  /* 9682 */ 'L', 'W', 'A', 'X', 0,
  /* 9687 */ 'L', 'V', 'E', 'B', 'X', 0,
  /* 9693 */ 'S', 'T', 'V', 'E', 'B', 'X', 0,
  /* 9700 */ 'S', 'T', 'B', 'X', 0,
  /* 9705 */ 'S', 'T', 'B', 'C', 'X', 0,
  /* 9711 */ 'S', 'T', 'D', 'C', 'X', 0,
  /* 9717 */ 'S', 'T', 'H', 'C', 'X', 0,
  /* 9723 */ 'S', 'T', 'W', 'C', 'X', 0,
  /* 9729 */ 'Q', 'V', 'L', 'F', 'C', 'D', 'X', 0,
  /* 9737 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'D', 'X', 0,
  /* 9746 */ 'E', 'V', 'L', 'D', 'D', 'X', 0,
  /* 9753 */ 'E', 'V', 'S', 'T', 'D', 'D', 'X', 0,
  /* 9761 */ 'Q', 'V', 'L', 'F', 'D', 'X', 0,
  /* 9768 */ 'Q', 'V', 'S', 'T', 'F', 'D', 'X', 0,
  /* 9776 */ 'Q', 'V', 'L', 'P', 'C', 'L', 'D', 'X', 0,
  /* 9785 */ 'Q', 'V', 'L', 'P', 'C', 'R', 'D', 'X', 0,
  /* 9794 */ 'L', 'X', 'S', 'D', 'X', 0,
  /* 9800 */ 'S', 'T', 'X', 'S', 'D', 'X', 0,
  /* 9807 */ 'S', 'T', 'D', 'X', 0,
  /* 9812 */ 'E', 'V', 'L', 'W', 'H', 'E', 'X', 0,
  /* 9820 */ 'E', 'V', 'S', 'T', 'W', 'H', 'E', 'X', 0,
  /* 9829 */ 'E', 'V', 'S', 'T', 'W', 'W', 'E', 'X', 0,
  /* 9838 */ 'E', 'V', 'L', 'D', 'H', 'X', 0,
  /* 9845 */ 'E', 'V', 'S', 'T', 'D', 'H', 'X', 0,
  /* 9853 */ 'L', 'V', 'E', 'H', 'X', 0,
  /* 9859 */ 'S', 'T', 'V', 'E', 'H', 'X', 0,
  /* 9866 */ 'S', 'T', 'H', 'X', 0,
  /* 9871 */ 'S', 'T', 'B', 'C', 'I', 'X', 0,
  /* 9878 */ 'L', 'D', 'C', 'I', 'X', 0,
  /* 9884 */ 'S', 'T', 'D', 'C', 'I', 'X', 0,
  /* 9891 */ 'S', 'T', 'H', 'C', 'I', 'X', 0,
  /* 9898 */ 'S', 'T', 'W', 'C', 'I', 'X', 0,
  /* 9905 */ 'L', 'B', 'Z', 'C', 'I', 'X', 0,
  /* 9912 */ 'L', 'H', 'Z', 'C', 'I', 'X', 0,
  /* 9919 */ 'L', 'W', 'Z', 'C', 'I', 'X', 0,
  /* 9926 */ 'V', 'S', 'B', 'O', 'X', 0,
  /* 9932 */ 'E', 'V', 'S', 'T', 'W', 'H', 'O', 'X', 0,
  /* 9941 */ 'E', 'V', 'S', 'T', 'W', 'W', 'O', 'X', 0,
  /* 9950 */ 'V', 'U', 'P', 'K', 'H', 'P', 'X', 0,
  /* 9958 */ 'V', 'P', 'K', 'P', 'X', 0,
  /* 9964 */ 'V', 'U', 'P', 'K', 'L', 'P', 'X', 0,
  /* 9972 */ 'L', 'X', 'S', 'S', 'P', 'X', 0,
  /* 9979 */ 'S', 'T', 'X', 'S', 'S', 'P', 'X', 0,
  /* 9987 */ 'L', 'B', 'A', 'R', 'X', 0,
  /* 9993 */ 'L', 'D', 'A', 'R', 'X', 0,
  /* 9999 */ 'L', 'H', 'A', 'R', 'X', 0,
  /* 10005 */ 'L', 'W', 'A', 'R', 'X', 0,
  /* 10011 */ 'L', 'D', 'B', 'R', 'X', 0,
  /* 10017 */ 'S', 'T', 'D', 'B', 'R', 'X', 0,
  /* 10024 */ 'L', 'H', 'B', 'R', 'X', 0,
  /* 10030 */ 'S', 'T', 'H', 'B', 'R', 'X', 0,
  /* 10037 */ 'L', 'W', 'B', 'R', 'X', 0,
  /* 10043 */ 'S', 'T', 'W', 'B', 'R', 'X', 0,
  /* 10050 */ 'T', 'L', 'B', 'S', 'X', 0,
  /* 10056 */ 'Q', 'V', 'L', 'F', 'C', 'S', 'X', 0,
  /* 10064 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'S', 'X', 0,
  /* 10073 */ 'L', 'X', 'V', 'D', 'S', 'X', 0,
  /* 10080 */ 'V', 'C', 'F', 'S', 'X', 0,
  /* 10086 */ 'Q', 'V', 'L', 'F', 'S', 'X', 0,
  /* 10093 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'X', 0,
  /* 10101 */ 'Q', 'V', 'L', 'P', 'C', 'L', 'S', 'X', 0,
  /* 10110 */ 'E', 'V', 'L', 'W', 'H', 'O', 'S', 'X', 0,
  /* 10119 */ 'Q', 'V', 'L', 'P', 'C', 'R', 'S', 'X', 0,
  /* 10128 */ 'E', 'V', 'L', 'H', 'H', 'E', 'S', 'P', 'L', 'A', 'T', 'X', 0,
  /* 10141 */ 'E', 'V', 'L', 'W', 'H', 'S', 'P', 'L', 'A', 'T', 'X', 0,
  /* 10153 */ 'E', 'V', 'L', 'H', 'H', 'O', 'S', 'S', 'P', 'L', 'A', 'T', 'X', 0,
  /* 10167 */ 'E', 'V', 'L', 'H', 'H', 'O', 'U', 'S', 'P', 'L', 'A', 'T', 'X', 0,
  /* 10181 */ 'E', 'V', 'L', 'W', 'W', 'S', 'P', 'L', 'A', 'T', 'X', 0,
  /* 10193 */ 'L', 'H', 'A', 'U', 'X', 0,
  /* 10199 */ 'L', 'W', 'A', 'U', 'X', 0,
  /* 10205 */ 'S', 'T', 'B', 'U', 'X', 0,
  /* 10211 */ 'Q', 'V', 'L', 'F', 'C', 'D', 'U', 'X', 0,
  /* 10220 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'D', 'U', 'X', 0,
  /* 10230 */ 'Q', 'V', 'L', 'F', 'D', 'U', 'X', 0,
  /* 10238 */ 'Q', 'V', 'S', 'T', 'F', 'D', 'U', 'X', 0,
  /* 10247 */ 'L', 'D', 'U', 'X', 0,
  /* 10252 */ 'S', 'T', 'D', 'U', 'X', 0,
  /* 10258 */ 'V', 'C', 'F', 'U', 'X', 0,
  /* 10264 */ 'S', 'T', 'H', 'U', 'X', 0,
  /* 10270 */ 'E', 'V', 'L', 'W', 'H', 'O', 'U', 'X', 0,
  /* 10279 */ 'Q', 'V', 'L', 'F', 'C', 'S', 'U', 'X', 0,
  /* 10288 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'S', 'U', 'X', 0,
  /* 10298 */ 'Q', 'V', 'L', 'F', 'S', 'U', 'X', 0,
  /* 10306 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'U', 'X', 0,
  /* 10315 */ 'S', 'T', 'W', 'U', 'X', 0,
  /* 10321 */ 'L', 'B', 'Z', 'U', 'X', 0,
  /* 10327 */ 'L', 'H', 'Z', 'U', 'X', 0,
  /* 10333 */ 'L', 'W', 'Z', 'U', 'X', 0,
  /* 10339 */ 'L', 'V', 'X', 0,
  /* 10343 */ 'S', 'T', 'V', 'X', 0,
  /* 10348 */ 'E', 'V', 'L', 'D', 'W', 'X', 0,
  /* 10355 */ 'E', 'V', 'S', 'T', 'D', 'W', 'X', 0,
  /* 10363 */ 'L', 'V', 'E', 'W', 'X', 0,
  /* 10369 */ 'S', 'T', 'V', 'E', 'W', 'X', 0,
  /* 10376 */ 'Q', 'V', 'S', 'T', 'F', 'I', 'W', 'X', 0,
  /* 10385 */ 'S', 'T', 'X', 'S', 'I', 'W', 'X', 0,
  /* 10393 */ 'S', 'T', 'W', 'X', 0,
  /* 10398 */ 'L', 'B', 'Z', 'X', 0,
  /* 10403 */ 'L', 'H', 'Z', 'X', 0,
  /* 10408 */ 'Q', 'V', 'L', 'F', 'I', 'W', 'Z', 'X', 0,
  /* 10417 */ 'L', 'X', 'S', 'I', 'W', 'Z', 'X', 0,
  /* 10425 */ 'L', 'W', 'Z', 'X', 0,
  /* 10430 */ 'C', 'O', 'P', 'Y', 0,
  /* 10435 */ 'D', 'C', 'B', 'Z', 0,
  /* 10440 */ 'L', 'B', 'Z', 0,
  /* 10444 */ 'B', 'D', 'Z', 0,
  /* 10448 */ 'Q', 'V', 'F', 'C', 'T', 'I', 'D', 'Z', 0,
  /* 10457 */ 'L', 'H', 'Z', 0,
  /* 10461 */ 'V', 'R', 'F', 'I', 'Z', 0,
  /* 10467 */ 'X', 'S', 'R', 'D', 'P', 'I', 'Z', 0,
  /* 10475 */ 'X', 'V', 'R', 'D', 'P', 'I', 'Z', 0,
  /* 10483 */ 'X', 'V', 'R', 'S', 'P', 'I', 'Z', 0,
  /* 10491 */ 'Q', 'V', 'F', 'R', 'I', 'Z', 0,
  /* 10498 */ 'B', 'D', 'N', 'Z', 0,
  /* 10503 */ 'Q', 'V', 'F', 'C', 'T', 'I', 'D', 'U', 'Z', 0,
  /* 10513 */ 'Q', 'V', 'F', 'C', 'T', 'I', 'W', 'U', 'Z', 0,
  /* 10523 */ 'Q', 'V', 'F', 'C', 'T', 'I', 'W', 'Z', 0,
  /* 10532 */ 'L', 'W', 'Z', 0,
  /* 10536 */ 'M', 'F', 'V', 'S', 'R', 'W', 'Z', 0,
  /* 10544 */ 'M', 'T', 'V', 'S', 'R', 'W', 'Z', 0,
  /* 10552 */ 'A', 'D', 'D', '8', 'T', 'L', 'S', '_', 0,
  /* 10561 */ 'B', 'L', '8', '_', 'T', 'L', 'S', '_', 0,
  /* 10570 */ 'Q', 'V', 'F', 'C', 'F', 'I', 'D', 'b', 0,
  /* 10579 */ 'Q', 'V', 'F', 'C', 'T', 'I', 'D', 'b', 0,
  /* 10588 */ 'M', 'T', 'F', 'S', 'F', 'b', 0,
  /* 10595 */ 'Q', 'V', 'A', 'L', 'I', 'G', 'N', 'I', 'b', 0,
  /* 10605 */ 'Q', 'V', 'E', 'S', 'P', 'L', 'A', 'T', 'I', 'b', 0,
  /* 10616 */ 'Q', 'V', 'F', 'L', 'O', 'G', 'I', 'C', 'A', 'L', 'b', 0,
  /* 10628 */ 'Q', 'V', 'F', 'S', 'E', 'L', 'b', 0,
  /* 10636 */ 'Q', 'V', 'F', 'T', 'S', 'T', 'N', 'A', 'N', 'b', 0,
  /* 10647 */ 'Q', 'V', 'F', 'C', 'M', 'P', 'E', 'Q', 'b', 0,
  /* 10657 */ 'Q', 'V', 'F', 'M', 'R', 'b', 0,
  /* 10664 */ 'Q', 'V', 'F', 'C', 'M', 'P', 'G', 'T', 'b', 0,
  /* 10674 */ 'Q', 'V', 'F', 'C', 'M', 'P', 'L', 'T', 'b', 0,
  /* 10684 */ 'Q', 'V', 'L', 'F', 'D', 'X', 'b', 0,
  /* 10692 */ 'Q', 'V', 'S', 'T', 'F', 'D', 'X', 'b', 0,
  /* 10701 */ 'Q', 'V', 'L', 'F', 'S', 'X', 'b', 0,
  /* 10709 */ 'Q', 'V', 'F', 'S', 'E', 'L', 'b', 'b', 0,
  /* 10718 */ 'L', 'D', 't', 'o', 'c', 0,
  /* 10724 */ 'L', 'W', 'Z', 't', 'o', 'c', 0,
  /* 10731 */ 'B', 'C', 'T', 'R', 'L', '8', '_', 'L', 'D', 'i', 'n', 't', 'o', '_', 't', 'o', 'c', 0,
  /* 10749 */ 'X', 'X', 'L', 'O', 'R', 'f', 0,
  /* 10756 */ 'T', 'C', 'R', 'E', 'T', 'U', 'R', 'N', 'a', 'i', 0,
  /* 10767 */ 'T', 'C', 'R', 'E', 'T', 'U', 'R', 'N', 'd', 'i', 0,
  /* 10778 */ 'T', 'C', 'R', 'E', 'T', 'U', 'R', 'N', 'r', 'i', 0,
  /* 10789 */ 'B', 'D', 'Z', 'L', 'A', 'm', 0,
  /* 10796 */ 'B', 'D', 'N', 'Z', 'L', 'A', 'm', 0,
  /* 10804 */ 'B', 'D', 'Z', 'A', 'm', 0,
  /* 10810 */ 'B', 'D', 'N', 'Z', 'A', 'm', 0,
  /* 10817 */ 'B', 'D', 'Z', 'L', 'R', 'L', 'm', 0,
  /* 10825 */ 'B', 'D', 'N', 'Z', 'L', 'R', 'L', 'm', 0,
  /* 10834 */ 'B', 'D', 'Z', 'L', 'm', 0,
  /* 10840 */ 'B', 'D', 'N', 'Z', 'L', 'm', 0,
  /* 10847 */ 'B', 'D', 'Z', 'L', 'R', 'm', 0,
  /* 10854 */ 'B', 'D', 'N', 'Z', 'L', 'R', 'm', 0,
  /* 10862 */ 'B', 'D', 'Z', 'm', 0,
  /* 10867 */ 'B', 'D', 'N', 'Z', 'm', 0,
  /* 10873 */ 'R', 'L', 'W', 'I', 'M', 'I', 'b', 'm', 0,
  /* 10882 */ 'R', 'L', 'W', 'I', 'N', 'M', 'b', 'm', 0,
  /* 10891 */ 'R', 'L', 'W', 'N', 'M', 'b', 'm', 0,
  /* 10899 */ 'R', 'L', 'W', 'I', 'M', 'I', 'o', 'b', 'm', 0,
  /* 10909 */ 'R', 'L', 'W', 'I', 'N', 'M', 'o', 'b', 'm', 0,
  /* 10919 */ 'R', 'L', 'W', 'N', 'M', 'o', 'b', 'm', 0,
  /* 10928 */ 'B', 'C', 'C', 'T', 'R', 'L', '8', 'n', 0,
  /* 10937 */ 'B', 'C', 'C', 'T', 'R', '8', 'n', 0,
  /* 10945 */ 'B', 'C', 'n', 0,
  /* 10949 */ 'B', 'C', 'L', 'n', 0,
  /* 10954 */ 'B', 'C', 'L', 'R', 'L', 'n', 0,
  /* 10961 */ 'B', 'C', 'C', 'T', 'R', 'L', 'n', 0,
  /* 10969 */ 'B', 'C', 'L', 'R', 'n', 0,
  /* 10975 */ 'B', 'C', 'C', 'T', 'R', 'n', 0,
  /* 10982 */ 'E', 'X', 'T', 'S', 'W', '_', '3', '2', '_', '6', '4', 'o', 0,
  /* 10995 */ 'A', 'D', 'D', '4', 'o', 0,
  /* 11001 */ 'E', 'X', 'T', 'S', 'B', '8', 'o', 0,
  /* 11009 */ 'A', 'D', 'D', 'C', '8', 'o', 0,
  /* 11016 */ 'A', 'N', 'D', 'C', '8', 'o', 0,
  /* 11023 */ 'S', 'U', 'B', 'F', 'C', '8', 'o', 0,
  /* 11031 */ 'O', 'R', 'C', '8', 'o', 0,
  /* 11037 */ 'A', 'D', 'D', '8', 'o', 0,
  /* 11043 */ 'N', 'A', 'N', 'D', '8', 'o', 0,
  /* 11050 */ 'A', 'D', 'D', 'E', '8', 'o', 0,
  /* 11057 */ 'S', 'U', 'B', 'F', 'E', '8', 'o', 0,
  /* 11065 */ 'A', 'D', 'D', 'M', 'E', '8', 'o', 0,
  /* 11073 */ 'S', 'U', 'B', 'F', 'M', 'E', '8', 'o', 0,
  /* 11082 */ 'A', 'D', 'D', 'Z', 'E', '8', 'o', 0,
  /* 11090 */ 'S', 'U', 'B', 'F', 'Z', 'E', '8', 'o', 0,
  /* 11099 */ 'S', 'U', 'B', 'F', '8', 'o', 0,
  /* 11106 */ 'N', 'E', 'G', '8', 'o', 0,
  /* 11112 */ 'E', 'X', 'T', 'S', 'H', '8', 'o', 0,
  /* 11120 */ 'R', 'L', 'W', 'I', 'M', 'I', '8', 'o', 0,
  /* 11129 */ 'R', 'L', 'W', 'I', 'N', 'M', '8', 'o', 0,
  /* 11138 */ 'R', 'L', 'W', 'N', 'M', '8', 'o', 0,
  /* 11146 */ 'N', 'O', 'R', '8', 'o', 0,
  /* 11152 */ 'X', 'O', 'R', '8', 'o', 0,
  /* 11158 */ 'E', 'Q', 'V', '8', 'o', 0,
  /* 11164 */ 'S', 'L', 'W', '8', 'o', 0,
  /* 11170 */ 'S', 'R', 'W', '8', 'o', 0,
  /* 11176 */ 'C', 'N', 'T', 'L', 'Z', 'W', '8', 'o', 0,
  /* 11185 */ 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'B', 'o', 0,
  /* 11195 */ 'E', 'X', 'T', 'S', 'B', 'o', 0,
  /* 11202 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'U', 'B', 'o', 0,
  /* 11212 */ 'F', 'S', 'U', 'B', 'o', 0,
  /* 11218 */ 'F', 'M', 'S', 'U', 'B', 'o', 0,
  /* 11225 */ 'F', 'N', 'M', 'S', 'U', 'B', 'o', 0,
  /* 11233 */ 'V', 'C', 'M', 'P', 'G', 'T', 'U', 'B', 'o', 0,
  /* 11243 */ 'A', 'D', 'D', 'C', 'o', 0,
  /* 11249 */ 'A', 'N', 'D', 'C', 'o', 0,
  /* 11255 */ 'S', 'U', 'B', 'F', 'C', 'o', 0,
  /* 11262 */ 'S', 'U', 'B', 'I', 'C', 'o', 0,
  /* 11269 */ 'A', 'D', 'D', 'I', 'C', 'o', 0,
  /* 11276 */ 'R', 'L', 'D', 'I', 'C', 'o', 0,
  /* 11283 */ 'O', 'R', 'C', 'o', 0,
  /* 11288 */ 'S', 'R', 'A', 'D', 'o', 0,
  /* 11294 */ 'F', 'A', 'D', 'D', 'o', 0,
  /* 11300 */ 'F', 'M', 'A', 'D', 'D', 'o', 0,
  /* 11307 */ 'F', 'N', 'M', 'A', 'D', 'D', 'o', 0,
  /* 11315 */ 'F', 'N', 'E', 'G', 'D', 'o', 0,
  /* 11322 */ 'M', 'U', 'L', 'H', 'D', 'o', 0,
  /* 11329 */ 'F', 'C', 'F', 'I', 'D', 'o', 0,
  /* 11336 */ 'F', 'C', 'T', 'I', 'D', 'o', 0,
  /* 11343 */ 'F', 'S', 'E', 'L', 'D', 'o', 0,
  /* 11350 */ 'M', 'U', 'L', 'L', 'D', 'o', 0,
  /* 11357 */ 'S', 'L', 'D', 'o', 0,
  /* 11362 */ 'F', 'R', 'I', 'M', 'D', 'o', 0,
  /* 11369 */ 'N', 'A', 'N', 'D', 'o', 0,
  /* 11375 */ 'F', 'C', 'P', 'S', 'G', 'N', 'D', 'o', 0,
  /* 11384 */ 'F', 'R', 'I', 'N', 'D', 'o', 0,
  /* 11391 */ 'F', 'R', 'I', 'P', 'D', 'o', 0,
  /* 11398 */ 'S', 'R', 'D', 'o', 0,
  /* 11403 */ 'F', 'A', 'B', 'S', 'D', 'o', 0,
  /* 11410 */ 'F', 'N', 'A', 'B', 'S', 'D', 'o', 0,
  /* 11418 */ 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'D', 'o', 0,
  /* 11428 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'U', 'D', 'o', 0,
  /* 11438 */ 'V', 'C', 'M', 'P', 'G', 'T', 'U', 'D', 'o', 0,
  /* 11448 */ 'D', 'I', 'V', 'D', 'o', 0,
  /* 11454 */ 'F', 'R', 'I', 'Z', 'D', 'o', 0,
  /* 11461 */ 'C', 'N', 'T', 'L', 'Z', 'D', 'o', 0,
  /* 11469 */ 'A', 'D', 'D', 'E', 'o', 0,
  /* 11475 */ 'D', 'I', 'V', 'D', 'E', 'o', 0,
  /* 11482 */ 'S', 'U', 'B', 'F', 'E', 'o', 0,
  /* 11489 */ 'A', 'D', 'D', 'M', 'E', 'o', 0,
  /* 11496 */ 'S', 'U', 'B', 'F', 'M', 'E', 'o', 0,
  /* 11504 */ 'F', 'R', 'E', 'o', 0,
  /* 11509 */ 'F', 'R', 'S', 'Q', 'R', 'T', 'E', 'o', 0,
  /* 11518 */ 'D', 'I', 'V', 'W', 'E', 'o', 0,
  /* 11525 */ 'A', 'D', 'D', 'Z', 'E', 'o', 0,
  /* 11532 */ 'S', 'U', 'B', 'F', 'Z', 'E', 'o', 0,
  /* 11540 */ 'S', 'U', 'B', 'F', 'o', 0,
  /* 11546 */ 'M', 'T', 'F', 'S', 'F', 'o', 0,
  /* 11553 */ 'N', 'E', 'G', 'o', 0,
  /* 11558 */ 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'H', 'o', 0,
  /* 11568 */ 'E', 'X', 'T', 'S', 'H', 'o', 0,
  /* 11575 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'U', 'H', 'o', 0,
  /* 11585 */ 'V', 'C', 'M', 'P', 'G', 'T', 'U', 'H', 'o', 0,
  /* 11595 */ 'S', 'R', 'A', 'D', 'I', 'o', 0,
  /* 11602 */ 'C', 'L', 'R', 'L', 'S', 'L', 'D', 'I', 'o', 0,
  /* 11612 */ 'E', 'X', 'T', 'L', 'D', 'I', 'o', 0,
  /* 11620 */ 'A', 'N', 'D', 'I', 'o', 0,
  /* 11626 */ 'C', 'L', 'R', 'R', 'D', 'I', 'o', 0,
  /* 11634 */ 'I', 'N', 'S', 'R', 'D', 'I', 'o', 0,
  /* 11642 */ 'R', 'O', 'T', 'R', 'D', 'I', 'o', 0,
  /* 11650 */ 'E', 'X', 'T', 'R', 'D', 'I', 'o', 0,
  /* 11658 */ 'M', 'T', 'F', 'S', 'F', 'I', 'o', 0,
  /* 11666 */ 'R', 'L', 'D', 'I', 'M', 'I', 'o', 0,
  /* 11674 */ 'R', 'L', 'W', 'I', 'M', 'I', 'o', 0,
  /* 11682 */ 'S', 'R', 'A', 'W', 'I', 'o', 0,
  /* 11689 */ 'C', 'L', 'R', 'L', 'S', 'L', 'W', 'I', 'o', 0,
  /* 11699 */ 'I', 'N', 'S', 'L', 'W', 'I', 'o', 0,
  /* 11707 */ 'E', 'X', 'T', 'L', 'W', 'I', 'o', 0,
  /* 11715 */ 'C', 'L', 'R', 'R', 'W', 'I', 'o', 0,
  /* 11723 */ 'I', 'N', 'S', 'R', 'W', 'I', 'o', 0,
  /* 11731 */ 'R', 'O', 'T', 'R', 'W', 'I', 'o', 0,
  /* 11739 */ 'E', 'X', 'T', 'R', 'W', 'I', 'o', 0,
  /* 11747 */ 'R', 'L', 'D', 'C', 'L', 'o', 0,
  /* 11754 */ 'R', 'L', 'D', 'I', 'C', 'L', 'o', 0,
  /* 11762 */ 'F', 'M', 'U', 'L', 'o', 0,
  /* 11768 */ 'R', 'L', 'W', 'I', 'N', 'M', 'o', 0,
  /* 11776 */ 'R', 'L', 'W', 'N', 'M', 'o', 0,
  /* 11783 */ 'X', 'V', 'C', 'M', 'P', 'G', 'E', 'D', 'P', 'o', 0,
  /* 11794 */ 'X', 'V', 'C', 'M', 'P', 'E', 'Q', 'D', 'P', 'o', 0,
  /* 11805 */ 'X', 'V', 'C', 'M', 'P', 'G', 'T', 'D', 'P', 'o', 0,
  /* 11816 */ 'V', 'C', 'M', 'P', 'B', 'F', 'P', 'o', 0,
  /* 11825 */ 'V', 'C', 'M', 'P', 'G', 'E', 'F', 'P', 'o', 0,
  /* 11835 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'F', 'P', 'o', 0,
  /* 11845 */ 'V', 'C', 'M', 'P', 'G', 'T', 'F', 'P', 'o', 0,
  /* 11855 */ 'X', 'V', 'C', 'M', 'P', 'G', 'E', 'S', 'P', 'o', 0,
  /* 11866 */ 'X', 'V', 'C', 'M', 'P', 'E', 'Q', 'S', 'P', 'o', 0,
  /* 11877 */ 'F', 'R', 'S', 'P', 'o', 0,
  /* 11883 */ 'X', 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'P', 'o', 0,
  /* 11894 */ 'R', 'L', 'D', 'C', 'R', 'o', 0,
  /* 11901 */ 'R', 'L', 'D', 'I', 'C', 'R', 'o', 0,
  /* 11909 */ 'F', 'M', 'R', 'o', 0,
  /* 11914 */ 'N', 'O', 'R', 'o', 0,
  /* 11919 */ 'X', 'O', 'R', 'o', 0,
  /* 11924 */ 'F', 'S', 'U', 'B', 'S', 'o', 0,
  /* 11931 */ 'F', 'M', 'S', 'U', 'B', 'S', 'o', 0,
  /* 11939 */ 'F', 'N', 'M', 'S', 'U', 'B', 'S', 'o', 0,
  /* 11948 */ 'F', 'A', 'D', 'D', 'S', 'o', 0,
  /* 11955 */ 'F', 'M', 'A', 'D', 'D', 'S', 'o', 0,
  /* 11963 */ 'F', 'N', 'M', 'A', 'D', 'D', 'S', 'o', 0,
  /* 11972 */ 'F', 'C', 'F', 'I', 'D', 'S', 'o', 0,
  /* 11980 */ 'F', 'R', 'E', 'S', 'o', 0,
  /* 11986 */ 'F', 'R', 'S', 'Q', 'R', 'T', 'E', 'S', 'o', 0,
  /* 11996 */ 'M', 'F', 'F', 'S', 'o', 0,
  /* 12002 */ 'F', 'N', 'E', 'G', 'S', 'o', 0,
  /* 12009 */ 'A', 'N', 'D', 'I', 'S', 'o', 0,
  /* 12016 */ 'F', 'S', 'E', 'L', 'S', 'o', 0,
  /* 12023 */ 'F', 'M', 'U', 'L', 'S', 'o', 0,
  /* 12030 */ 'F', 'R', 'I', 'M', 'S', 'o', 0,
  /* 12037 */ 'F', 'C', 'P', 'S', 'G', 'N', 'S', 'o', 0,
  /* 12046 */ 'F', 'R', 'I', 'N', 'S', 'o', 0,
  /* 12053 */ 'F', 'R', 'I', 'P', 'S', 'o', 0,
  /* 12060 */ 'F', 'A', 'B', 'S', 'S', 'o', 0,
  /* 12067 */ 'F', 'N', 'A', 'B', 'S', 'S', 'o', 0,
  /* 12075 */ 'F', 'S', 'Q', 'R', 'T', 'S', 'o', 0,
  /* 12083 */ 'F', 'C', 'F', 'I', 'D', 'U', 'S', 'o', 0,
  /* 12092 */ 'F', 'D', 'I', 'V', 'S', 'o', 0,
  /* 12099 */ 'F', 'R', 'I', 'Z', 'S', 'o', 0,
  /* 12106 */ 'F', 'S', 'Q', 'R', 'T', 'o', 0,
  /* 12113 */ 'M', 'U', 'L', 'H', 'D', 'U', 'o', 0,
  /* 12121 */ 'F', 'C', 'F', 'I', 'D', 'U', 'o', 0,
  /* 12129 */ 'D', 'I', 'V', 'D', 'U', 'o', 0,
  /* 12136 */ 'D', 'I', 'V', 'D', 'E', 'U', 'o', 0,
  /* 12144 */ 'D', 'I', 'V', 'W', 'E', 'U', 'o', 0,
  /* 12152 */ 'M', 'U', 'L', 'H', 'W', 'U', 'o', 0,
  /* 12160 */ 'D', 'I', 'V', 'W', 'U', 'o', 0,
  /* 12167 */ 'F', 'D', 'I', 'V', 'o', 0,
  /* 12173 */ 'E', 'Q', 'V', 'o', 0,
  /* 12178 */ 'S', 'R', 'A', 'W', 'o', 0,
  /* 12184 */ 'M', 'U', 'L', 'H', 'W', 'o', 0,
  /* 12191 */ 'F', 'C', 'T', 'I', 'W', 'o', 0,
  /* 12198 */ 'M', 'U', 'L', 'L', 'W', 'o', 0,
  /* 12205 */ 'S', 'L', 'W', 'o', 0,
  /* 12210 */ 'S', 'R', 'W', 'o', 0,
  /* 12215 */ 'V', 'C', 'M', 'P', 'G', 'T', 'S', 'W', 'o', 0,
  /* 12225 */ 'E', 'X', 'T', 'S', 'W', 'o', 0,
  /* 12232 */ 'V', 'C', 'M', 'P', 'E', 'Q', 'U', 'W', 'o', 0,
  /* 12242 */ 'V', 'C', 'M', 'P', 'G', 'T', 'U', 'W', 'o', 0,
  /* 12252 */ 'D', 'I', 'V', 'W', 'o', 0,
  /* 12258 */ 'C', 'N', 'T', 'L', 'Z', 'W', 'o', 0,
  /* 12266 */ 'F', 'C', 'T', 'I', 'D', 'Z', 'o', 0,
  /* 12274 */ 'F', 'C', 'T', 'I', 'D', 'U', 'Z', 'o', 0,
  /* 12283 */ 'F', 'C', 'T', 'I', 'W', 'U', 'Z', 'o', 0,
  /* 12292 */ 'F', 'C', 'T', 'I', 'W', 'Z', 'o', 0,
  /* 12300 */ 'B', 'D', 'Z', 'L', 'A', 'p', 0,
  /* 12307 */ 'B', 'D', 'N', 'Z', 'L', 'A', 'p', 0,
  /* 12315 */ 'B', 'D', 'Z', 'A', 'p', 0,
  /* 12321 */ 'B', 'D', 'N', 'Z', 'A', 'p', 0,
  /* 12328 */ 'B', 'D', 'Z', 'L', 'R', 'L', 'p', 0,
  /* 12336 */ 'B', 'D', 'N', 'Z', 'L', 'R', 'L', 'p', 0,
  /* 12345 */ 'B', 'D', 'Z', 'L', 'p', 0,
  /* 12351 */ 'B', 'D', 'N', 'Z', 'L', 'p', 0,
  /* 12358 */ 'B', 'D', 'Z', 'L', 'R', 'p', 0,
  /* 12365 */ 'B', 'D', 'N', 'Z', 'L', 'R', 'p', 0,
  /* 12373 */ 'B', 'D', 'Z', 'p', 0,
  /* 12378 */ 'B', 'D', 'N', 'Z', 'p', 0,
  /* 12384 */ 'M', 'T', 'C', 'T', 'R', '8', 'l', 'o', 'o', 'p', 0,
  /* 12395 */ 'M', 'T', 'C', 'T', 'R', 'l', 'o', 'o', 'p', 0,
  /* 12405 */ 'E', 'H', '_', 'S', 'j', 'L', 'j', '_', 'S', 'e', 't', 'u', 'p', 0,
  /* 12419 */ 'Q', 'V', 'F', 'N', 'E', 'G', 's', 0,
  /* 12427 */ 'Q', 'V', 'A', 'L', 'I', 'G', 'N', 'I', 's', 0,
  /* 12437 */ 'Q', 'V', 'E', 'S', 'P', 'L', 'A', 'T', 'I', 's', 0,
  /* 12448 */ 'Q', 'V', 'F', 'L', 'O', 'G', 'I', 'C', 'A', 'L', 's', 0,
  /* 12460 */ 'Q', 'V', 'F', 'R', 'I', 'M', 's', 0,
  /* 12468 */ 'Q', 'V', 'F', 'P', 'E', 'R', 'M', 's', 0,
  /* 12477 */ 'Q', 'V', 'F', 'C', 'P', 'S', 'G', 'N', 's', 0,
  /* 12487 */ 'Q', 'V', 'F', 'R', 'I', 'N', 's', 0,
  /* 12495 */ 'Q', 'V', 'F', 'R', 'I', 'P', 's', 0,
  /* 12503 */ 'Q', 'V', 'F', 'R', 'S', 'P', 's', 0,
  /* 12511 */ 'Q', 'V', 'F', 'M', 'R', 's', 0,
  /* 12518 */ 'Q', 'V', 'F', 'A', 'B', 'S', 's', 0,
  /* 12526 */ 'Q', 'V', 'F', 'N', 'A', 'B', 'S', 's', 0,
  /* 12535 */ 'Q', 'V', 'F', 'S', 'U', 'B', 'S', 's', 0,
  /* 12544 */ 'Q', 'V', 'F', 'M', 'S', 'U', 'B', 'S', 's', 0,
  /* 12554 */ 'Q', 'V', 'F', 'N', 'M', 'S', 'U', 'B', 'S', 's', 0,
  /* 12565 */ 'Q', 'V', 'F', 'A', 'D', 'D', 'S', 's', 0,
  /* 12574 */ 'Q', 'V', 'F', 'M', 'A', 'D', 'D', 'S', 's', 0,
  /* 12584 */ 'Q', 'V', 'F', 'N', 'M', 'A', 'D', 'D', 'S', 's', 0,
  /* 12595 */ 'Q', 'V', 'F', 'R', 'E', 'S', 's', 0,
  /* 12603 */ 'Q', 'V', 'F', 'R', 'S', 'Q', 'R', 'T', 'E', 'S', 's', 0,
  /* 12615 */ 'Q', 'V', 'F', 'M', 'U', 'L', 'S', 's', 0,
  /* 12624 */ 'Q', 'V', 'L', 'F', 'C', 'S', 'X', 's', 0,
  /* 12633 */ 'Q', 'V', 'S', 'T', 'F', 'C', 'S', 'X', 's', 0,
  /* 12643 */ 'Q', 'V', 'L', 'F', 'S', 'X', 's', 0,
  /* 12651 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'X', 's', 0,
  /* 12660 */ 'Q', 'V', 'S', 'T', 'F', 'S', 'U', 'X', 's', 0,
  /* 12670 */ 'Q', 'V', 'F', 'R', 'I', 'Z', 's', 0,
  /* 12678 */ 'Q', 'V', 'F', 'S', 'E', 'L', 'b', 's', 0,
  /* 12687 */ 'Q', 'V', 'F', 'T', 'S', 'T', 'N', 'A', 'N', 'b', 's', 0,
  /* 12699 */ 'Q', 'V', 'F', 'C', 'M', 'P', 'E', 'Q', 'b', 's', 0,
  /* 12710 */ 'Q', 'V', 'F', 'C', 'M', 'P', 'G', 'T', 'b', 's', 0,
  /* 12721 */ 'Q', 'V', 'F', 'C', 'M', 'P', 'L', 'T', 'b', 's', 0,
  /* 12732 */ 'B', 'C', 'L', 'a', 'l', 'w', 'a', 'y', 's', 0,
  /* 12742 */ 'Q', 'V', 'L', 'P', 'C', 'L', 'S', 'X', 'i', 'n', 't', 0,
  /* 12754 */ 'M', 'F', 'V', 'R', 'S', 'A', 'V', 'E', 'v', 0,
  /* 12764 */ 'M', 'T', 'V', 'R', 'S', 'A', 'V', 'E', 'v', 0,
  /* 12774 */ 'L', 'A', 'x', 0,
  /* 12778 */ 'D', 'C', 'B', 'T', 'x', 0,
  /* 12784 */ 'D', 'C', 'B', 'T', 'S', 'T', 'x', 0,
  /* 12792 */ 'F', 'A', 'D', 'D', 'r', 't', 'z', 0,
};

extern const unsigned PPCInstrNameIndices[] = {
    4485U, 5350U, 5573U, 4904U, 4895U, 4950U, 4003U, 4018U, 
    3876U, 4032U, 7872U, 3763U, 3630U, 10430U, 3701U, 8453U, 
    3434U, 5691U, 8403U, 3472U, 8392U, 3721U, 6424U, 686U, 
    7778U, 10995U, 1015U, 7786U, 10552U, 11037U, 2829U, 966U, 
    11009U, 11243U, 3643U, 1026U, 11050U, 11469U, 4355U, 1138U, 
    2877U, 985U, 11269U, 7748U, 1498U, 2093U, 55U, 2077U, 
    2051U, 2064U, 2040U, 5137U, 267U, 5103U, 227U, 7065U, 
    281U, 5114U, 240U, 7080U, 298U, 5094U, 3708U, 1039U, 
    11065U, 11489U, 3853U, 1054U, 11082U, 11525U, 5614U, 6912U, 
    3391U, 1021U, 11044U, 2837U, 972U, 11016U, 11249U, 12009U, 
    1808U, 11620U, 1801U, 8353U, 1532U, 8368U, 1548U, 11370U, 
    834U, 168U, 511U, 1270U, 757U, 91U, 434U, 1197U, 
    798U, 132U, 475U, 1236U, 777U, 111U, 454U, 1216U, 
    874U, 208U, 551U, 1308U, 737U, 71U, 414U, 1165U, 
    854U, 188U, 531U, 1289U, 818U, 152U, 495U, 1255U, 
    5609U, 2541U, 1930U, 2822U, 2825U, 1953U, 7322U, 1476U, 
    5003U, 1361U, 4877U, 2305U, 7146U, 4967U, 7316U, 1469U, 
    10937U, 4996U, 1353U, 10928U, 10961U, 10975U, 4873U, 7141U, 
    4961U, 10954U, 10969U, 12732U, 10949U, 7310U, 1463U, 4989U, 
    1346U, 10731U, 10945U, 10498U, 1754U, 2529U, 10810U, 12321U, 
    5081U, 2317U, 10796U, 12307U, 7168U, 1415U, 4981U, 10825U, 
    12336U, 10854U, 12365U, 10840U, 12351U, 10867U, 12378U, 10444U, 
    1744U, 2524U, 10804U, 12315U, 5076U, 2311U, 10789U, 12300U, 
    7162U, 1408U, 4974U, 10817U, 12328U, 10847U, 12358U, 10834U, 
    12345U, 10862U, 12373U, 4869U, 1336U, 6416U, 7809U, 7794U, 
    10561U, 2295U, 930U, 6407U, 7136U, 1391U, 4955U, 7802U, 
    3373U, 2920U, 2598U, 4372U, 11602U, 4692U, 11689U, 4403U, 
    11626U, 4728U, 11715U, 2593U, 942U, 3467U, 4397U, 3351U, 
    4365U, 9173U, 4678U, 9407U, 4722U, 3615U, 11461U, 9615U, 
    1626U, 11176U, 12258U, 8269U, 8290U, 3417U, 2842U, 8743U, 
    3403U, 7217U, 7229U, 3045U, 8307U, 8299U, 7255U, 1928U, 
    3866U, 4284U, 8506U, 8232U, 8242U, 7523U, 8516U, 8249U, 
    7530U, 8540U, 12784U, 8529U, 12778U, 10435U, 5070U, 4299U, 
    3598U, 3648U, 8616U, 12136U, 11475U, 8610U, 12129U, 11448U, 
    9602U, 3839U, 8623U, 12144U, 11518U, 8710U, 12160U, 12252U, 
    7906U, 4943U, 8512U, 570U, 8523U, 576U, 8548U, 591U, 
    8535U, 584U, 2946U, 1000U, 8276U, 1517U, 358U, 651U, 
    376U, 669U, 12405U, 8739U, 1606U, 11158U, 12173U, 7356U, 
    9136U, 8803U, 8925U, 8864U, 8986U, 9064U, 3423U, 2849U, 
    6936U, 7926U, 8662U, 7935U, 8671U, 9457U, 9613U, 8078U, 
    8708U, 8749U, 2689U, 4188U, 3278U, 9746U, 4060U, 9838U, 
    9071U, 10348U, 8172U, 10128U, 8195U, 10153U, 8208U, 10167U, 
    3674U, 9812U, 7858U, 10110U, 8643U, 10270U, 8184U, 10141U, 
    8221U, 10181U, 4463U, 5661U, 5651U, 4473U, 1816U, 5408U, 
    1860U, 5452U, 1894U, 5486U, 3889U, 1958U, 8755U, 9208U, 
    4515U, 2119U, 8815U, 9256U, 3955U, 1997U, 8779U, 9232U, 
    8937U, 9328U, 4550U, 2158U, 8876U, 9292U, 8998U, 9364U, 
    1828U, 5420U, 1872U, 5464U, 1906U, 5498U, 3907U, 1978U, 
    8767U, 9220U, 4533U, 2139U, 8852U, 9280U, 3973U, 2017U, 
    8791U, 9244U, 8974U, 9352U, 4577U, 2188U, 8913U, 9316U, 
    9035U, 9388U, 2324U, 3898U, 1968U, 4524U, 2129U, 3964U, 
    2007U, 4559U, 2168U, 8840U, 9268U, 8962U, 9340U, 4568U, 
    2178U, 8901U, 9304U, 9023U, 9376U, 3916U, 1988U, 1840U, 
    5432U, 4542U, 2149U, 1884U, 5476U, 3982U, 2027U, 1850U, 
    5442U, 4586U, 2198U, 1918U, 5510U, 3410U, 3997U, 7223U, 
    7234U, 3051U, 9179U, 4685U, 9077U, 9185U, 4708U, 4453U, 
    4646U, 7764U, 8635U, 8022U, 8696U, 3284U, 9753U, 4066U, 
    9845U, 9084U, 10355U, 3681U, 9820U, 5631U, 9932U, 3845U, 
    9829U, 5683U, 9941U, 8827U, 8949U, 8888U, 9010U, 9098U, 
    9106U, 7261U, 4381U, 11612U, 4715U, 11707U, 4424U, 11650U, 
    4749U, 11739U, 2691U, 948U, 600U, 11001U, 11195U, 4190U, 
    1126U, 613U, 11112U, 11568U, 9490U, 639U, 10982U, 12225U, 
    5639U, 3510U, 11403U, 7889U, 12060U, 3212U, 7441U, 11948U, 
    11294U, 12792U, 3314U, 7516U, 11972U, 8585U, 7953U, 12083U, 
    12121U, 11329U, 3566U, 7993U, 3447U, 11375U, 7844U, 12037U, 
    3327U, 10505U, 12274U, 10450U, 12266U, 11336U, 9146U, 10515U, 
    12283U, 10525U, 12292U, 12191U, 8731U, 8016U, 12092U, 12167U, 
    3219U, 7449U, 11955U, 11300U, 7200U, 11909U, 2784U, 7422U, 
    11931U, 11218U, 5018U, 7823U, 12023U, 11762U, 3516U, 11410U, 
    7895U, 12067U, 3300U, 11315U, 7656U, 12002U, 3227U, 7458U, 
    11963U, 11307U, 2792U, 7431U, 11939U, 11225U, 3742U, 7620U, 
    11980U, 11504U, 3367U, 11362U, 7838U, 12030U, 3455U, 11384U, 
    7852U, 12046U, 3461U, 11391U, 7866U, 12053U, 3603U, 11454U, 
    8166U, 12099U, 6799U, 11877U, 3755U, 7627U, 11986U, 11509U, 
    3339U, 11343U, 7772U, 12016U, 8475U, 7944U, 12075U, 12106U, 
    2777U, 7414U, 11924U, 11212U, 7108U, 330U, 7095U, 315U, 
    4289U, 8237U, 4305U, 4701U, 11699U, 4410U, 11634U, 4735U, 
    11723U, 4927U, 1340U, 2934U, 2296U, 12774U, 9987U, 5031U, 
    10440U, 1739U, 9905U, 8716U, 1588U, 10321U, 1694U, 10398U, 
    1721U, 3336U, 9993U, 5038U, 10011U, 9878U, 8601U, 10247U, 
    9781U, 5125U, 253U, 10718U, 1940U, 8435U, 4655U, 5087U, 
    3291U, 8565U, 10232U, 9763U, 9667U, 10410U, 7641U, 8651U, 
    10300U, 10088U, 2036U, 925U, 9999U, 5045U, 8555U, 1564U, 
    10193U, 1666U, 9652U, 1634U, 10024U, 1652U, 10457U, 1749U, 
    9912U, 8721U, 1594U, 10327U, 1701U, 10403U, 1727U, 4492U, 
    1147U, 7754U, 1505U, 9191U, 4756U, 9687U, 9853U, 10363U, 
    5011U, 7301U, 10339U, 5059U, 2330U, 10005U, 5052U, 10199U, 
    9682U, 350U, 343U, 10037U, 1659U, 10532U, 1760U, 9919U, 
    8726U, 1600U, 10333U, 1708U, 10425U, 1733U, 10724U, 9794U, 
    9674U, 10417U, 9972U, 9622U, 10073U, 9637U, 6986U, 3924U, 
    7645U, 3622U, 7019U, 1385U, 7329U, 1484U, 7001U, 7636U, 
    11996U, 7152U, 1396U, 7284U, 3929U, 1075U, 7267U, 1445U, 
    7279U, 5559U, 2704U, 955U, 3773U, 12754U, 7031U, 3496U, 
    10536U, 2940U, 3943U, 1091U, 7335U, 1491U, 12384U, 12395U, 
    7013U, 0U, 48U, 3949U, 4446U, 11658U, 10588U, 11546U, 
    7157U, 1402U, 7290U, 3489U, 3936U, 1083U, 7273U, 1452U, 
    7296U, 5566U, 3782U, 12764U, 7038U, 3503U, 2334U, 10544U, 
    3306U, 8576U, 12113U, 11322U, 9130U, 8680U, 12152U, 12184U, 
    3345U, 11350U, 4495U, 1144U, 9167U, 12198U, 7186U, 7175U, 
    1423U, 3398U, 1020U, 11043U, 11369U, 3993U, 1121U, 11106U, 
    11553U, 6412U, 893U, 905U, 7213U, 1435U, 11146U, 11914U, 
    7207U, 1436U, 11147U, 3041U, 1010U, 11031U, 11283U, 4632U, 
    1160U, 7759U, 1511U, 11915U, 3547U, 9519U, 8414U, 8423U, 
    4594U, 10595U, 12427U, 4636U, 10605U, 12437U, 7341U, 12518U, 
    3210U, 7439U, 12565U, 3312U, 7514U, 8583U, 7951U, 10570U, 
    6927U, 10647U, 12699U, 8313U, 10664U, 12710U, 8383U, 10674U, 
    12721U, 5530U, 12477U, 3325U, 8592U, 10503U, 10448U, 10579U, 
    9144U, 8687U, 10513U, 10523U, 4858U, 10616U, 12448U, 3217U, 
    7447U, 12574U, 7198U, 10657U, 12511U, 2782U, 7420U, 12544U, 
    5016U, 7821U, 12615U, 7348U, 12526U, 3990U, 12419U, 3225U, 
    7456U, 12584U, 2790U, 7429U, 12554U, 5336U, 12468U, 3740U, 
    7618U, 12595U, 5282U, 12460U, 5552U, 12487U, 6400U, 12495U, 
    10491U, 12670U, 6797U, 12503U, 3753U, 7625U, 12603U, 4920U, 
    10628U, 10709U, 12678U, 2775U, 7412U, 12535U, 5520U, 10636U, 
    12687U, 3259U, 7493U, 5023U, 7829U, 3234U, 7466U, 3268U, 
    7503U, 3247U, 7480U, 4332U, 10211U, 2424U, 9729U, 2352U, 
    10279U, 2464U, 10056U, 2388U, 12624U, 10230U, 2445U, 9761U, 
    2371U, 10684U, 9665U, 2342U, 10408U, 2514U, 10298U, 2485U, 
    10086U, 2407U, 10701U, 12643U, 9776U, 10101U, 12742U, 9785U, 
    10119U, 10220U, 2434U, 4809U, 2249U, 9737U, 2361U, 4771U, 
    2207U, 10288U, 2474U, 4830U, 2272U, 10064U, 2397U, 4790U, 
    2228U, 12633U, 10238U, 2454U, 4820U, 2261U, 9768U, 2379U, 
    4781U, 2218U, 10692U, 10376U, 2504U, 10306U, 2494U, 4841U, 
    2284U, 12660U, 10093U, 2415U, 4800U, 2239U, 12651U, 7045U, 
    8327U, 3791U, 4321U, 4360U, 2549U, 4442U, 3320U, 4326U, 
    4882U, 11747U, 7007U, 11894U, 2883U, 4888U, 626U, 11754U, 
    7024U, 11901U, 11276U, 4501U, 11666U, 4508U, 1151U, 11120U, 
    10873U, 11674U, 10899U, 5289U, 1370U, 11129U, 10882U, 11768U, 
    10909U, 5296U, 1378U, 11138U, 10891U, 11776U, 10919U, 4417U, 
    11642U, 4742U, 11731U, 2729U, 3167U, 691U, 1098U, 714U, 
    1184U, 2955U, 2982U, 3084U, 3057U, 3009U, 3140U, 3111U, 
    704U, 1111U, 727U, 1326U, 2970U, 2997U, 3099U, 3072U, 
    3025U, 3155U, 3127U, 2107U, 3689U, 3654U, 3746U, 3363U, 
    4376U, 11606U, 11357U, 9187U, 1611U, 11164U, 4696U, 11693U, 
    12205U, 7056U, 8341U, 3820U, 3199U, 4349U, 11595U, 11288U, 
    9059U, 4664U, 11682U, 12178U, 3492U, 4412U, 11636U, 11398U, 
    9413U, 1616U, 11170U, 4737U, 11725U, 12210U, 2725U, 961U, 
    9871U, 9705U, 8560U, 1570U, 10205U, 1673U, 9700U, 1640U, 
    3555U, 10017U, 9884U, 9711U, 8605U, 10252U, 9807U, 3295U, 
    8570U, 10240U, 9770U, 10378U, 7651U, 8656U, 10308U, 10095U, 
    4219U, 1133U, 10030U, 9891U, 9717U, 8630U, 1576U, 10264U, 
    1680U, 9866U, 1646U, 9195U, 4761U, 9693U, 9859U, 10369U, 
    10343U, 5064U, 9527U, 1621U, 10043U, 9898U, 9723U, 8703U, 
    1582U, 10315U, 1687U, 10393U, 1715U, 9800U, 10385U, 9979U, 
    9629U, 9644U, 3871U, 1069U, 11099U, 2865U, 978U, 11023U, 
    11255U, 3668U, 1032U, 11057U, 11482U, 2889U, 992U, 3714U, 
    1046U, 11073U, 11496U, 3859U, 1061U, 11090U, 11532U, 11540U, 
    4294U, 2871U, 11262U, 7742U, 2929U, 8468U, 2856U, 4311U, 
    3170U, 4339U, 2569U, 935U, 1933U, 917U, 7306U, 1459U, 
    5545U, 4851U, 8258U, 10756U, 1765U, 10767U, 1777U, 10778U, 
    1789U, 3552U, 4431U, 3429U, 2113U, 3695U, 4913U, 9657U, 
    3333U, 4489U, 3734U, 393U, 10050U, 407U, 3179U, 2926U, 
    3833U, 400U, 5700U, 8444U, 5243U, 7297U, 9507U, 4767U, 
    3806U, 6991U, 6960U, 9539U, 6977U, 5327U, 6289U, 7379U, 
    7700U, 8046U, 5166U, 7404U, 5191U, 5226U, 7725U, 5310U, 
    5392U, 8070U, 3424U, 2850U, 2633U, 4132U, 9425U, 2744U, 
    4231U, 9555U, 6944U, 10080U, 32U, 10258U, 40U, 7128U, 
    8494U, 2815U, 3609U, 4278U, 9607U, 6257U, 11816U, 6345U, 
    11835U, 2766U, 11202U, 3573U, 11428U, 4253U, 11575U, 9577U, 
    12232U, 6304U, 11825U, 6354U, 11845U, 2680U, 11185U, 3530U, 
    11418U, 4179U, 11558U, 9481U, 12215U, 2799U, 11233U, 3582U, 
    11438U, 4262U, 11585U, 9586U, 12242U, 8152U, 14U, 8159U, 
    23U, 8750U, 6319U, 3204U, 6296U, 6281U, 6363U, 2697U, 
    3539U, 4196U, 9496U, 2808U, 3591U, 4271U, 9595U, 7679U, 
    7689U, 6338U, 2665U, 3523U, 4164U, 9466U, 2751U, 3559U, 
    4238U, 9562U, 5216U, 9091U, 2555U, 4073U, 9115U, 2562U, 
    4080U, 9152U, 9400U, 5149U, 5199U, 7708U, 5174U, 5234U, 
    7733U, 2611U, 4110U, 9417U, 2736U, 4223U, 9547U, 2672U, 
    4171U, 9473U, 2758U, 4245U, 9569U, 5400U, 3411U, 7119U, 
    8481U, 6265U, 7224U, 7235U, 3052U, 5344U, 7246U, 9958U, 
    7902U, 7961U, 7910U, 7977U, 7918U, 8000U, 5360U, 7969U, 
    5368U, 7985U, 5376U, 8008U, 2585U, 3380U, 4097U, 9200U, 
    2716U, 3546U, 4210U, 9518U, 6313U, 5252U, 5539U, 6370U, 
    10461U, 2575U, 3357U, 4087U, 9180U, 6328U, 9926U, 4932U, 
    3187U, 9047U, 5012U, 2580U, 3362U, 4603U, 4092U, 5673U, 
    9186U, 2709U, 4203U, 2648U, 4147U, 9440U, 9503U, 7302U, 
    2543U, 3198U, 4054U, 9058U, 2606U, 3498U, 4105U, 5678U, 
    9412U, 6952U, 9531U, 6968U, 5318U, 6274U, 7371U, 7671U, 
    8038U, 5158U, 7396U, 5183U, 5208U, 7717U, 5302U, 5384U, 
    8062U, 8029U, 7362U, 7662U, 7387U, 8054U, 9950U, 2640U, 
    4139U, 9432U, 9964U, 2657U, 4156U, 9449U, 7262U, 7U, 
    2535U, 4046U, 7605U, 2619U, 4118U, 8322U, 3662U, 4435U, 
    7242U, 1440U, 11152U, 4631U, 1159U, 7758U, 1510U, 11919U, 
    6114U, 5805U, 6541U, 6059U, 6178U, 6023U, 6769U, 5599U, 
    7539U, 8086U, 7572U, 8119U, 6068U, 5589U, 5821U, 6557U, 
    5841U, 6577U, 6187U, 6859U, 5769U, 6505U, 6003U, 6731U, 
    6241U, 6043U, 5727U, 6463U, 5961U, 6689U, 5923U, 6651U, 
    6096U, 5907U, 5747U, 6483U, 5981U, 6709U, 5705U, 6441U, 
    5939U, 6667U, 4610U, 2896U, 5258U, 6376U, 10467U, 5871U, 
    6607U, 5885U, 6621U, 6140U, 6831U, 5789U, 6525U, 6195U, 
    6149U, 6122U, 6813U, 5813U, 6549U, 6086U, 11794U, 6787U, 
    11866U, 5861U, 11783U, 6597U, 11855U, 6130U, 11805U, 6821U, 
    11883U, 6033U, 6751U, 6778U, 7550U, 8097U, 7583U, 8130U, 
    6077U, 7561U, 8108U, 7594U, 8141U, 5831U, 6567U, 6221U, 
    6884U, 5851U, 6587U, 6231U, 6894U, 6213U, 6876U, 5779U, 
    6515U, 6013U, 6741U, 6249U, 6904U, 6051U, 6761U, 5737U, 
    6473U, 5971U, 6699U, 5931U, 6659U, 6105U, 6804U, 5915U, 
    6643U, 5758U, 6494U, 5992U, 6720U, 5716U, 6452U, 5950U, 
    6678U, 4617U, 2904U, 5266U, 6384U, 10475U, 5878U, 6614U, 
    4624U, 2912U, 5274U, 6392U, 10483U, 5896U, 6632U, 6169U, 
    6850U, 5797U, 6533U, 6204U, 6867U, 6159U, 6840U, 3388U, 
    2834U, 8736U, 3395U, 7210U, 7204U, 3038U, 10749U, 7239U, 
    9122U, 9159U, 4388U, 4937U, 4670U, 9510U, 2821U, 1948U, 
    7315U, 4995U, 4872U, 2299U, 7140U, 4960U, 
};

static inline void InitPPCMCInstrInfo(MCInstrInfo *II) {
  II->InitMCInstrInfo(PPCInsts, PPCInstrNameIndices, PPCInstrNameData, 1630);
}

} // end llvm namespace 
#endif // GET_INSTRINFO_MC_DESC


#ifdef GET_INSTRINFO_HEADER
#undef GET_INSTRINFO_HEADER
namespace llvm {
struct PPCGenInstrInfo : public TargetInstrInfo {
  explicit PPCGenInstrInfo(int CFSetupOpcode = -1, int CFDestroyOpcode = -1, int CatchRetOpcode = -1);
  ~PPCGenInstrInfo() override {}
};
} // end llvm namespace 
#endif // GET_INSTRINFO_HEADER


#ifdef GET_INSTRINFO_CTOR_DTOR
#undef GET_INSTRINFO_CTOR_DTOR
namespace llvm {
extern const MCInstrDesc PPCInsts[];
extern const unsigned PPCInstrNameIndices[];
extern const char PPCInstrNameData[];
PPCGenInstrInfo::PPCGenInstrInfo(int CFSetupOpcode, int CFDestroyOpcode, int CatchRetOpcode)
  : TargetInstrInfo(CFSetupOpcode, CFDestroyOpcode, CatchRetOpcode) {
  InitMCInstrInfo(PPCInsts, PPCInstrNameIndices, PPCInstrNameData, 1630);
}
} // end llvm namespace 
#endif // GET_INSTRINFO_CTOR_DTOR

#ifdef GET_INSTRINFO_OPERAND_ENUM
#undef GET_INSTRINFO_OPERAND_ENUM
namespace llvm {
namespace PPC {
namespace OpName { 
enum {
OPERAND_LAST
};
} // end namespace OpName
} // end namespace PPC
} // end namespace llvm
#endif //GET_INSTRINFO_OPERAND_ENUM
#ifdef GET_INSTRINFO_NAMED_OPS
#undef GET_INSTRINFO_NAMED_OPS
namespace llvm {
namespace PPC {
LLVM_READONLY
int16_t getNamedOperandIdx(uint16_t Opcode, uint16_t NamedIdx) {
  return -1;
}
} // end namespace PPC
} // end namespace llvm
#endif //GET_INSTRINFO_NAMED_OPS

#ifdef GET_INSTRINFO_OPERAND_TYPES_ENUM
#undef GET_INSTRINFO_OPERAND_TYPES_ENUM
namespace llvm {
namespace PPC {
namespace OpTypes { 
enum OperandType {
  abscalltarget = 0,
  abscondbrtarget = 1,
  absdirectbrtarget = 2,
  calltarget = 3,
  condbrtarget = 4,
  crbitm = 5,
  directbrtarget = 6,
  dispRI = 7,
  dispRIX = 8,
  dispSPE2 = 9,
  dispSPE4 = 10,
  dispSPE8 = 11,
  f32imm = 12,
  f64imm = 13,
  i16imm = 14,
  i1imm = 15,
  i32imm = 16,
  i64imm = 17,
  i8imm = 18,
  imm32SExt16 = 19,
  imm64SExt16 = 20,
  imm64ZExt32 = 21,
  memr = 22,
  memri = 23,
  memrix = 24,
  memrr = 25,
  pred = 26,
  ptr_rc_idx = 27,
  ptr_rc_nor0 = 28,
  s16imm = 29,
  s16imm64 = 30,
  s17imm = 31,
  s17imm64 = 32,
  s5imm = 33,
  spe2dis = 34,
  spe4dis = 35,
  spe8dis = 36,
  tlscall = 37,
  tlscall32 = 38,
  tlsgd = 39,
  tlsgd32 = 40,
  tlsreg = 41,
  tlsreg32 = 42,
  tocentry = 43,
  tocentry32 = 44,
  u10imm = 45,
  u12imm = 46,
  u16imm = 47,
  u16imm64 = 48,
  u1imm = 49,
  u2imm = 50,
  u3imm = 51,
  u4imm = 52,
  u5imm = 53,
  u6imm = 54,
  OPERAND_TYPE_LIST_END
};
} // end namespace OpTypes
} // end namespace PPC
} // end namespace llvm
#endif // GET_INSTRINFO_OPERAND_TYPES_ENUM
#ifdef GET_INSTRMAP_INFO
#undef GET_INSTRMAP_INFO
namespace llvm {

namespace PPC {

enum IsVSXFMAAlt {
	IsVSXFMAAlt_1
};

enum RC {
	RC_0,
	RC_1
};

// getAltVSXFMAOpcode
LLVM_READONLY
int getAltVSXFMAOpcode(uint16_t Opcode) {
static const uint16_t getAltVSXFMAOpcodeTable[][2] = {
  { PPC::XSMADDADP, PPC::XSMADDMDP },
  { PPC::XSMADDASP, PPC::XSMADDMSP },
  { PPC::XSMSUBADP, PPC::XSMSUBMDP },
  { PPC::XSMSUBASP, PPC::XSMSUBMSP },
  { PPC::XSNMADDADP, PPC::XSNMADDMDP },
  { PPC::XSNMADDASP, PPC::XSNMADDMSP },
  { PPC::XSNMSUBADP, PPC::XSNMSUBMDP },
  { PPC::XSNMSUBASP, PPC::XSNMSUBMSP },
  { PPC::XVMADDADP, PPC::XVMADDMDP },
  { PPC::XVMADDASP, PPC::XVMADDMSP },
  { PPC::XVMSUBADP, PPC::XVMSUBMDP },
  { PPC::XVMSUBASP, PPC::XVMSUBMSP },
  { PPC::XVNMADDADP, PPC::XVNMADDMDP },
  { PPC::XVNMADDASP, PPC::XVNMADDMSP },
  { PPC::XVNMSUBADP, PPC::XVNMSUBMDP },
  { PPC::XVNMSUBASP, PPC::XVNMSUBMSP },
}; // End of getAltVSXFMAOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 16;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getAltVSXFMAOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getAltVSXFMAOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getAltVSXFMAOpcodeTable[mid][1];
}

// getNonRecordFormOpcode
LLVM_READONLY
int getNonRecordFormOpcode(uint16_t Opcode) {
static const uint16_t getNonRecordFormOpcodeTable[][2] = {
  { PPC::ADD4o, PPC::ADD4 },
  { PPC::ADD8o, PPC::ADD8 },
  { PPC::ADDC8o, PPC::ADDC8 },
  { PPC::ADDCo, PPC::ADDC },
  { PPC::ADDE8o, PPC::ADDE8 },
  { PPC::ADDEo, PPC::ADDE },
  { PPC::ADDICo, PPC::ADDIC },
  { PPC::ADDME8o, PPC::ADDME8 },
  { PPC::ADDMEo, PPC::ADDME },
  { PPC::ADDZE8o, PPC::ADDZE8 },
  { PPC::ADDZEo, PPC::ADDZE },
  { PPC::AND8o, PPC::AND8 },
  { PPC::ANDC8o, PPC::ANDC8 },
  { PPC::ANDCo, PPC::ANDC },
  { PPC::ANDo, PPC::AND },
  { PPC::CNTLZDo, PPC::CNTLZD },
  { PPC::CNTLZW8o, PPC::CNTLZW8 },
  { PPC::CNTLZWo, PPC::CNTLZW },
  { PPC::DIVDUo, PPC::DIVDU },
  { PPC::DIVDo, PPC::DIVD },
  { PPC::DIVWUo, PPC::DIVWU },
  { PPC::DIVWo, PPC::DIVW },
  { PPC::EQV8o, PPC::EQV8 },
  { PPC::EQVo, PPC::EQV },
  { PPC::EXTSB8o, PPC::EXTSB8 },
  { PPC::EXTSBo, PPC::EXTSB },
  { PPC::EXTSH8o, PPC::EXTSH8 },
  { PPC::EXTSHo, PPC::EXTSH },
  { PPC::EXTSW_32_64o, PPC::EXTSW_32_64 },
  { PPC::EXTSWo, PPC::EXTSW },
  { PPC::FABSDo, PPC::FABSD },
  { PPC::FABSSo, PPC::FABSS },
  { PPC::FADDSo, PPC::FADDS },
  { PPC::FADDo, PPC::FADD },
  { PPC::FCFIDSo, PPC::FCFIDS },
  { PPC::FCFIDUSo, PPC::FCFIDUS },
  { PPC::FCFIDUo, PPC::FCFIDU },
  { PPC::FCFIDo, PPC::FCFID },
  { PPC::FCPSGNDo, PPC::FCPSGND },
  { PPC::FCPSGNSo, PPC::FCPSGNS },
  { PPC::FCTIDUZo, PPC::FCTIDUZ },
  { PPC::FCTIDZo, PPC::FCTIDZ },
  { PPC::FCTIDo, PPC::FCTID },
  { PPC::FCTIWUZo, PPC::FCTIWUZ },
  { PPC::FCTIWZo, PPC::FCTIWZ },
  { PPC::FCTIWo, PPC::FCTIW },
  { PPC::FDIVSo, PPC::FDIVS },
  { PPC::FDIVo, PPC::FDIV },
  { PPC::FMADDSo, PPC::FMADDS },
  { PPC::FMADDo, PPC::FMADD },
  { PPC::FMRo, PPC::FMR },
  { PPC::FMSUBSo, PPC::FMSUBS },
  { PPC::FMSUBo, PPC::FMSUB },
  { PPC::FMULSo, PPC::FMULS },
  { PPC::FMULo, PPC::FMUL },
  { PPC::FNABSDo, PPC::FNABSD },
  { PPC::FNABSSo, PPC::FNABSS },
  { PPC::FNEGDo, PPC::FNEGD },
  { PPC::FNEGSo, PPC::FNEGS },
  { PPC::FNMADDSo, PPC::FNMADDS },
  { PPC::FNMADDo, PPC::FNMADD },
  { PPC::FNMSUBSo, PPC::FNMSUBS },
  { PPC::FNMSUBo, PPC::FNMSUB },
  { PPC::FRESo, PPC::FRES },
  { PPC::FREo, PPC::FRE },
  { PPC::FRIMDo, PPC::FRIMD },
  { PPC::FRIMSo, PPC::FRIMS },
  { PPC::FRINDo, PPC::FRIND },
  { PPC::FRINSo, PPC::FRINS },
  { PPC::FRIPDo, PPC::FRIPD },
  { PPC::FRIPSo, PPC::FRIPS },
  { PPC::FRIZDo, PPC::FRIZD },
  { PPC::FRIZSo, PPC::FRIZS },
  { PPC::FRSPo, PPC::FRSP },
  { PPC::FRSQRTESo, PPC::FRSQRTES },
  { PPC::FRSQRTEo, PPC::FRSQRTE },
  { PPC::FSELDo, PPC::FSELD },
  { PPC::FSELSo, PPC::FSELS },
  { PPC::FSQRTSo, PPC::FSQRTS },
  { PPC::FSQRTo, PPC::FSQRT },
  { PPC::FSUBSo, PPC::FSUBS },
  { PPC::FSUBo, PPC::FSUB },
  { PPC::MULHDUo, PPC::MULHDU },
  { PPC::MULHDo, PPC::MULHD },
  { PPC::MULHWUo, PPC::MULHWU },
  { PPC::MULHWo, PPC::MULHW },
  { PPC::MULLDo, PPC::MULLD },
  { PPC::MULLWo, PPC::MULLW },
  { PPC::NAND8o, PPC::NAND8 },
  { PPC::NANDo, PPC::NAND },
  { PPC::NEG8o, PPC::NEG8 },
  { PPC::NEGo, PPC::NEG },
  { PPC::NOR8o, PPC::NOR8 },
  { PPC::NORo, PPC::NOR },
  { PPC::OR8o, PPC::OR8 },
  { PPC::ORC8o, PPC::ORC8 },
  { PPC::ORCo, PPC::ORC },
  { PPC::ORo, PPC::OR },
  { PPC::RLDCLo, PPC::RLDCL },
  { PPC::RLDCRo, PPC::RLDCR },
  { PPC::RLDICLo, PPC::RLDICL },
  { PPC::RLDICRo, PPC::RLDICR },
  { PPC::RLDICo, PPC::RLDIC },
  { PPC::RLDIMIo, PPC::RLDIMI },
  { PPC::RLWIMI8o, PPC::RLWIMI8 },
  { PPC::RLWIMIo, PPC::RLWIMI },
  { PPC::RLWINM8o, PPC::RLWINM8 },
  { PPC::RLWINMo, PPC::RLWINM },
  { PPC::RLWNM8o, PPC::RLWNM8 },
  { PPC::RLWNMo, PPC::RLWNM },
  { PPC::SLDo, PPC::SLD },
  { PPC::SLW8o, PPC::SLW8 },
  { PPC::SLWo, PPC::SLW },
  { PPC::SRADIo, PPC::SRADI },
  { PPC::SRADo, PPC::SRAD },
  { PPC::SRAWIo, PPC::SRAWI },
  { PPC::SRAWo, PPC::SRAW },
  { PPC::SRDo, PPC::SRD },
  { PPC::SRW8o, PPC::SRW8 },
  { PPC::SRWo, PPC::SRW },
  { PPC::SUBF8o, PPC::SUBF8 },
  { PPC::SUBFC8o, PPC::SUBFC8 },
  { PPC::SUBFCo, PPC::SUBFC },
  { PPC::SUBFE8o, PPC::SUBFE8 },
  { PPC::SUBFEo, PPC::SUBFE },
  { PPC::SUBFME8o, PPC::SUBFME8 },
  { PPC::SUBFMEo, PPC::SUBFME },
  { PPC::SUBFZE8o, PPC::SUBFZE8 },
  { PPC::SUBFZEo, PPC::SUBFZE },
  { PPC::SUBFo, PPC::SUBF },
  { PPC::XOR8o, PPC::XOR8 },
  { PPC::XORo, PPC::XOR },
}; // End of getNonRecordFormOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 132;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getNonRecordFormOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getNonRecordFormOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getNonRecordFormOpcodeTable[mid][1];
}

// getRecordFormOpcode
LLVM_READONLY
int getRecordFormOpcode(uint16_t Opcode) {
static const uint16_t getRecordFormOpcodeTable[][2] = {
  { PPC::ADD4, PPC::ADD4o },
  { PPC::ADD8, PPC::ADD8o },
  { PPC::ADDC, PPC::ADDCo },
  { PPC::ADDC8, PPC::ADDC8o },
  { PPC::ADDE, PPC::ADDEo },
  { PPC::ADDE8, PPC::ADDE8o },
  { PPC::ADDIC, PPC::ADDICo },
  { PPC::ADDME, PPC::ADDMEo },
  { PPC::ADDME8, PPC::ADDME8o },
  { PPC::ADDZE, PPC::ADDZEo },
  { PPC::ADDZE8, PPC::ADDZE8o },
  { PPC::AND, PPC::ANDo },
  { PPC::AND8, PPC::AND8o },
  { PPC::ANDC, PPC::ANDCo },
  { PPC::ANDC8, PPC::ANDC8o },
  { PPC::CNTLZD, PPC::CNTLZDo },
  { PPC::CNTLZW, PPC::CNTLZWo },
  { PPC::CNTLZW8, PPC::CNTLZW8o },
  { PPC::DIVD, PPC::DIVDo },
  { PPC::DIVDU, PPC::DIVDUo },
  { PPC::DIVW, PPC::DIVWo },
  { PPC::DIVWU, PPC::DIVWUo },
  { PPC::EQV, PPC::EQVo },
  { PPC::EQV8, PPC::EQV8o },
  { PPC::EXTSB, PPC::EXTSBo },
  { PPC::EXTSB8, PPC::EXTSB8o },
  { PPC::EXTSH, PPC::EXTSHo },
  { PPC::EXTSH8, PPC::EXTSH8o },
  { PPC::EXTSW, PPC::EXTSWo },
  { PPC::EXTSW_32_64, PPC::EXTSW_32_64o },
  { PPC::FABSD, PPC::FABSDo },
  { PPC::FABSS, PPC::FABSSo },
  { PPC::FADD, PPC::FADDo },
  { PPC::FADDS, PPC::FADDSo },
  { PPC::FCFID, PPC::FCFIDo },
  { PPC::FCFIDS, PPC::FCFIDSo },
  { PPC::FCFIDU, PPC::FCFIDUo },
  { PPC::FCFIDUS, PPC::FCFIDUSo },
  { PPC::FCPSGND, PPC::FCPSGNDo },
  { PPC::FCPSGNS, PPC::FCPSGNSo },
  { PPC::FCTID, PPC::FCTIDo },
  { PPC::FCTIDUZ, PPC::FCTIDUZo },
  { PPC::FCTIDZ, PPC::FCTIDZo },
  { PPC::FCTIW, PPC::FCTIWo },
  { PPC::FCTIWUZ, PPC::FCTIWUZo },
  { PPC::FCTIWZ, PPC::FCTIWZo },
  { PPC::FDIV, PPC::FDIVo },
  { PPC::FDIVS, PPC::FDIVSo },
  { PPC::FMADD, PPC::FMADDo },
  { PPC::FMADDS, PPC::FMADDSo },
  { PPC::FMR, PPC::FMRo },
  { PPC::FMSUB, PPC::FMSUBo },
  { PPC::FMSUBS, PPC::FMSUBSo },
  { PPC::FMUL, PPC::FMULo },
  { PPC::FMULS, PPC::FMULSo },
  { PPC::FNABSD, PPC::FNABSDo },
  { PPC::FNABSS, PPC::FNABSSo },
  { PPC::FNEGD, PPC::FNEGDo },
  { PPC::FNEGS, PPC::FNEGSo },
  { PPC::FNMADD, PPC::FNMADDo },
  { PPC::FNMADDS, PPC::FNMADDSo },
  { PPC::FNMSUB, PPC::FNMSUBo },
  { PPC::FNMSUBS, PPC::FNMSUBSo },
  { PPC::FRE, PPC::FREo },
  { PPC::FRES, PPC::FRESo },
  { PPC::FRIMD, PPC::FRIMDo },
  { PPC::FRIMS, PPC::FRIMSo },
  { PPC::FRIND, PPC::FRINDo },
  { PPC::FRINS, PPC::FRINSo },
  { PPC::FRIPD, PPC::FRIPDo },
  { PPC::FRIPS, PPC::FRIPSo },
  { PPC::FRIZD, PPC::FRIZDo },
  { PPC::FRIZS, PPC::FRIZSo },
  { PPC::FRSP, PPC::FRSPo },
  { PPC::FRSQRTE, PPC::FRSQRTEo },
  { PPC::FRSQRTES, PPC::FRSQRTESo },
  { PPC::FSELD, PPC::FSELDo },
  { PPC::FSELS, PPC::FSELSo },
  { PPC::FSQRT, PPC::FSQRTo },
  { PPC::FSQRTS, PPC::FSQRTSo },
  { PPC::FSUB, PPC::FSUBo },
  { PPC::FSUBS, PPC::FSUBSo },
  { PPC::MULHD, PPC::MULHDo },
  { PPC::MULHDU, PPC::MULHDUo },
  { PPC::MULHW, PPC::MULHWo },
  { PPC::MULHWU, PPC::MULHWUo },
  { PPC::MULLD, PPC::MULLDo },
  { PPC::MULLW, PPC::MULLWo },
  { PPC::NAND, PPC::NANDo },
  { PPC::NAND8, PPC::NAND8o },
  { PPC::NEG, PPC::NEGo },
  { PPC::NEG8, PPC::NEG8o },
  { PPC::NOR, PPC::NORo },
  { PPC::NOR8, PPC::NOR8o },
  { PPC::OR, PPC::ORo },
  { PPC::OR8, PPC::OR8o },
  { PPC::ORC, PPC::ORCo },
  { PPC::ORC8, PPC::ORC8o },
  { PPC::RLDCL, PPC::RLDCLo },
  { PPC::RLDCR, PPC::RLDCRo },
  { PPC::RLDIC, PPC::RLDICo },
  { PPC::RLDICL, PPC::RLDICLo },
  { PPC::RLDICR, PPC::RLDICRo },
  { PPC::RLDIMI, PPC::RLDIMIo },
  { PPC::RLWIMI, PPC::RLWIMIo },
  { PPC::RLWIMI8, PPC::RLWIMI8o },
  { PPC::RLWINM, PPC::RLWINMo },
  { PPC::RLWINM8, PPC::RLWINM8o },
  { PPC::RLWNM, PPC::RLWNMo },
  { PPC::RLWNM8, PPC::RLWNM8o },
  { PPC::SLD, PPC::SLDo },
  { PPC::SLW, PPC::SLWo },
  { PPC::SLW8, PPC::SLW8o },
  { PPC::SRAD, PPC::SRADo },
  { PPC::SRADI, PPC::SRADIo },
  { PPC::SRAW, PPC::SRAWo },
  { PPC::SRAWI, PPC::SRAWIo },
  { PPC::SRD, PPC::SRDo },
  { PPC::SRW, PPC::SRWo },
  { PPC::SRW8, PPC::SRW8o },
  { PPC::SUBF, PPC::SUBFo },
  { PPC::SUBF8, PPC::SUBF8o },
  { PPC::SUBFC, PPC::SUBFCo },
  { PPC::SUBFC8, PPC::SUBFC8o },
  { PPC::SUBFE, PPC::SUBFEo },
  { PPC::SUBFE8, PPC::SUBFE8o },
  { PPC::SUBFME, PPC::SUBFMEo },
  { PPC::SUBFME8, PPC::SUBFME8o },
  { PPC::SUBFZE, PPC::SUBFZEo },
  { PPC::SUBFZE8, PPC::SUBFZE8o },
  { PPC::XOR, PPC::XORo },
  { PPC::XOR8, PPC::XOR8o },
}; // End of getRecordFormOpcodeTable

  unsigned mid;
  unsigned start = 0;
  unsigned end = 132;
  while (start < end) {
    mid = start + (end - start)/2;
    if (Opcode == getRecordFormOpcodeTable[mid][0]) {
      break;
    }
    if (Opcode < getRecordFormOpcodeTable[mid][0])
      end = mid;
    else
      start = mid + 1;
  }
  if (start == end)
    return -1; // Instruction doesn't exist in this table.

  return getRecordFormOpcodeTable[mid][1];
}

} // End PPC namespace
} // End llvm namespace
#endif // GET_INSTRMAP_INFO

