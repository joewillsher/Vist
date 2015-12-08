/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Intrinsic Function Source Fragment                                         *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

// VisualStudio defines setjmp as _setjmp
#if defined(_MSC_VER) && defined(setjmp) && \
                         !defined(setjmp_undefined_for_msvc)
#  pragma push_macro("setjmp")
#  undef setjmp
#  define setjmp_undefined_for_msvc
#endif

// Enum values for Intrinsics.h
#ifdef GET_INTRINSIC_ENUM_VALUES
    AMDGPU_abs,                                // llvm.AMDGPU.abs
    AMDGPU_arl,                                // llvm.AMDGPU.arl
    AMDGPU_barrier_global,                     // llvm.AMDGPU.barrier.global
    AMDGPU_barrier_local,                      // llvm.AMDGPU.barrier.local
    AMDGPU_bfe_i32,                            // llvm.AMDGPU.bfe.i32
    AMDGPU_bfe_u32,                            // llvm.AMDGPU.bfe.u32
    AMDGPU_bfi,                                // llvm.AMDGPU.bfi
    AMDGPU_bfm,                                // llvm.AMDGPU.bfm
    AMDGPU_brev,                               // llvm.AMDGPU.brev
    AMDGPU_clamp,                              // llvm.AMDGPU.clamp
    AMDGPU_cndlt,                              // llvm.AMDGPU.cndlt
    AMDGPU_cube,                               // llvm.AMDGPU.cube
    AMDGPU_cvt_f32_ubyte0,                     // llvm.AMDGPU.cvt.f32.ubyte0
    AMDGPU_cvt_f32_ubyte1,                     // llvm.AMDGPU.cvt.f32.ubyte1
    AMDGPU_cvt_f32_ubyte2,                     // llvm.AMDGPU.cvt.f32.ubyte2
    AMDGPU_cvt_f32_ubyte3,                     // llvm.AMDGPU.cvt.f32.ubyte3
    AMDGPU_ddx,                                // llvm.AMDGPU.ddx
    AMDGPU_ddy,                                // llvm.AMDGPU.ddy
    AMDGPU_div,                                // llvm.AMDGPU.div
    AMDGPU_dp4,                                // llvm.AMDGPU.dp4
    AMDGPU_flbit_i32,                          // llvm.AMDGPU.flbit.i32
    AMDGPU_fract,                              // llvm.AMDGPU.fract
    AMDGPU_imad24,                             // llvm.AMDGPU.imad24
    AMDGPU_imax,                               // llvm.AMDGPU.imax
    AMDGPU_imin,                               // llvm.AMDGPU.imin
    AMDGPU_imul24,                             // llvm.AMDGPU.imul24
    AMDGPU_kill,                               // llvm.AMDGPU.kill
    AMDGPU_kilp,                               // llvm.AMDGPU.kilp
    AMDGPU_legacy_rsq,                         // llvm.AMDGPU.legacy.rsq
    AMDGPU_lrp,                                // llvm.AMDGPU.lrp
    AMDGPU_mul,                                // llvm.AMDGPU.mul
    AMDGPU_mullit,                             // llvm.AMDGPU.mullit
    AMDGPU_pow,                                // llvm.AMDGPU.pow
    AMDGPU_seq,                                // llvm.AMDGPU.seq
    AMDGPU_sge,                                // llvm.AMDGPU.sge
    AMDGPU_sgt,                                // llvm.AMDGPU.sgt
    AMDGPU_sle,                                // llvm.AMDGPU.sle
    AMDGPU_sne,                                // llvm.AMDGPU.sne
    AMDGPU_store_output,                       // llvm.AMDGPU.store.output
    AMDGPU_swizzle,                            // llvm.AMDGPU.swizzle
    AMDGPU_tex,                                // llvm.AMDGPU.tex
    AMDGPU_trunc,                              // llvm.AMDGPU.trunc
    AMDGPU_txb,                                // llvm.AMDGPU.txb
    AMDGPU_txd,                                // llvm.AMDGPU.txd
    AMDGPU_txf,                                // llvm.AMDGPU.txf
    AMDGPU_txl,                                // llvm.AMDGPU.txl
    AMDGPU_txq,                                // llvm.AMDGPU.txq
    AMDGPU_umad24,                             // llvm.AMDGPU.umad24
    AMDGPU_umax,                               // llvm.AMDGPU.umax
    AMDGPU_umin,                               // llvm.AMDGPU.umin
    AMDGPU_umul24,                             // llvm.AMDGPU.umul24
    AMDIL_abs,                                 // llvm.AMDIL.abs
    AMDIL_clamp,                               // llvm.AMDIL.clamp
    AMDIL_exp,                                 // llvm.AMDIL.exp
    AMDIL_fraction,                            // llvm.AMDIL.fraction
    AMDIL_round_nearest,                       // llvm.AMDIL.round.nearest
    R600_ddx,                                  // llvm.R600.ddx
    R600_ddy,                                  // llvm.R600.ddy
    R600_interp_const,                         // llvm.R600.interp.const
    R600_interp_input,                         // llvm.R600.interp.input
    R600_interp_xy,                            // llvm.R600.interp.xy
    R600_interp_zw,                            // llvm.R600.interp.zw
    R600_ldptr,                                // llvm.R600.ldptr
    R600_load_input,                           // llvm.R600.load.input
    R600_load_texbuf,                          // llvm.R600.load.texbuf
    R600_store_dummy,                          // llvm.R600.store.dummy
    R600_store_pixel_depth,                    // llvm.R600.store.pixel.depth
    R600_store_pixel_stencil,                  // llvm.R600.store.pixel.stencil
    R600_store_stream_output,                  // llvm.R600.store.stream.output
    R600_store_swizzle,                        // llvm.R600.store.swizzle
    R600_tex,                                  // llvm.R600.tex
    R600_texc,                                 // llvm.R600.texc
    R600_txb,                                  // llvm.R600.txb
    R600_txbc,                                 // llvm.R600.txbc
    R600_txf,                                  // llvm.R600.txf
    R600_txl,                                  // llvm.R600.txl
    R600_txlc,                                 // llvm.R600.txlc
    R600_txq,                                  // llvm.R600.txq
    SI_break,                                  // llvm.SI.break
    SI_buffer_load_dword,                      // llvm.SI.buffer.load.dword
    SI_else,                                   // llvm.SI.else
    SI_else_break,                             // llvm.SI.else.break
    SI_end_cf,                                 // llvm.SI.end.cf
    SI_export,                                 // llvm.SI.export
    SI_fs_constant,                            // llvm.SI.fs.constant
    SI_fs_interp,                              // llvm.SI.fs.interp
    SI_gather4,                                // llvm.SI.gather4
    SI_gather4_b,                              // llvm.SI.gather4.b
    SI_gather4_b_cl,                           // llvm.SI.gather4.b.cl
    SI_gather4_b_cl_o,                         // llvm.SI.gather4.b.cl.o
    SI_gather4_b_o,                            // llvm.SI.gather4.b.o
    SI_gather4_c,                              // llvm.SI.gather4.c
    SI_gather4_c_b,                            // llvm.SI.gather4.c.b
    SI_gather4_c_b_cl,                         // llvm.SI.gather4.c.b.cl
    SI_gather4_c_b_cl_o,                       // llvm.SI.gather4.c.b.cl.o
    SI_gather4_c_b_o,                          // llvm.SI.gather4.c.b.o
    SI_gather4_c_cl,                           // llvm.SI.gather4.c.cl
    SI_gather4_c_cl_o,                         // llvm.SI.gather4.c.cl.o
    SI_gather4_c_l,                            // llvm.SI.gather4.c.l
    SI_gather4_c_l_o,                          // llvm.SI.gather4.c.l.o
    SI_gather4_c_lz,                           // llvm.SI.gather4.c.lz
    SI_gather4_c_lz_o,                         // llvm.SI.gather4.c.lz.o
    SI_gather4_c_o,                            // llvm.SI.gather4.c.o
    SI_gather4_cl,                             // llvm.SI.gather4.cl
    SI_gather4_cl_o,                           // llvm.SI.gather4.cl.o
    SI_gather4_l,                              // llvm.SI.gather4.l
    SI_gather4_l_o,                            // llvm.SI.gather4.l.o
    SI_gather4_lz,                             // llvm.SI.gather4.lz
    SI_gather4_lz_o,                           // llvm.SI.gather4.lz.o
    SI_gather4_o,                              // llvm.SI.gather4.o
    SI_getlod,                                 // llvm.SI.getlod
    SI_getresinfo,                             // llvm.SI.getresinfo
    SI_if,                                     // llvm.SI.if
    SI_if_break,                               // llvm.SI.if.break
    SI_image_load,                             // llvm.SI.image.load
    SI_image_load_mip,                         // llvm.SI.image.load.mip
    SI_image_sample,                           // llvm.SI.image.sample
    SI_image_sample_b,                         // llvm.SI.image.sample.b
    SI_image_sample_b_cl,                      // llvm.SI.image.sample.b.cl
    SI_image_sample_b_cl_o,                    // llvm.SI.image.sample.b.cl.o
    SI_image_sample_b_o,                       // llvm.SI.image.sample.b.o
    SI_image_sample_c,                         // llvm.SI.image.sample.c
    SI_image_sample_c_b,                       // llvm.SI.image.sample.c.b
    SI_image_sample_c_b_cl,                    // llvm.SI.image.sample.c.b.cl
    SI_image_sample_c_b_cl_o,                  // llvm.SI.image.sample.c.b.cl.o
    SI_image_sample_c_b_o,                     // llvm.SI.image.sample.c.b.o
    SI_image_sample_c_cd,                      // llvm.SI.image.sample.c.cd
    SI_image_sample_c_cd_cl,                   // llvm.SI.image.sample.c.cd.cl
    SI_image_sample_c_cd_cl_o,                 // llvm.SI.image.sample.c.cd.cl.o
    SI_image_sample_c_cd_o,                    // llvm.SI.image.sample.c.cd.o
    SI_image_sample_c_cl,                      // llvm.SI.image.sample.c.cl
    SI_image_sample_c_cl_o,                    // llvm.SI.image.sample.c.cl.o
    SI_image_sample_c_d,                       // llvm.SI.image.sample.c.d
    SI_image_sample_c_d_cl,                    // llvm.SI.image.sample.c.d.cl
    SI_image_sample_c_d_cl_o,                  // llvm.SI.image.sample.c.d.cl.o
    SI_image_sample_c_d_o,                     // llvm.SI.image.sample.c.d.o
    SI_image_sample_c_l,                       // llvm.SI.image.sample.c.l
    SI_image_sample_c_l_o,                     // llvm.SI.image.sample.c.l.o
    SI_image_sample_c_lz,                      // llvm.SI.image.sample.c.lz
    SI_image_sample_c_lz_o,                    // llvm.SI.image.sample.c.lz.o
    SI_image_sample_c_o,                       // llvm.SI.image.sample.c.o
    SI_image_sample_cd,                        // llvm.SI.image.sample.cd
    SI_image_sample_cd_cl,                     // llvm.SI.image.sample.cd.cl
    SI_image_sample_cd_cl_o,                   // llvm.SI.image.sample.cd.cl.o
    SI_image_sample_cd_o,                      // llvm.SI.image.sample.cd.o
    SI_image_sample_cl,                        // llvm.SI.image.sample.cl
    SI_image_sample_cl_o,                      // llvm.SI.image.sample.cl.o
    SI_image_sample_d,                         // llvm.SI.image.sample.d
    SI_image_sample_d_cl,                      // llvm.SI.image.sample.d.cl
    SI_image_sample_d_cl_o,                    // llvm.SI.image.sample.d.cl.o
    SI_image_sample_d_o,                       // llvm.SI.image.sample.d.o
    SI_image_sample_l,                         // llvm.SI.image.sample.l
    SI_image_sample_l_o,                       // llvm.SI.image.sample.l.o
    SI_image_sample_lz,                        // llvm.SI.image.sample.lz
    SI_image_sample_lz_o,                      // llvm.SI.image.sample.lz.o
    SI_image_sample_o,                         // llvm.SI.image.sample.o
    SI_imageload,                              // llvm.SI.imageload
    SI_load_const,                             // llvm.SI.load.const
    SI_loop,                                   // llvm.SI.loop
    SI_packf16,                                // llvm.SI.packf16
    SI_resinfo,                                // llvm.SI.resinfo
    SI_sample,                                 // llvm.SI.sample
    SI_sampleb,                                // llvm.SI.sampleb
    SI_sampled,                                // llvm.SI.sampled
    SI_samplel,                                // llvm.SI.samplel
    SI_sendmsg,                                // llvm.SI.sendmsg
    SI_tbuffer_store,                          // llvm.SI.tbuffer.store
    SI_tid,                                    // llvm.SI.tid
    SI_vs_load_input,                          // llvm.SI.vs.load.input
    TGSI_lit_z                                 // llvm.TGSI.lit.z
#endif

// Intrinsic ID to name table
#ifdef GET_INTRINSIC_NAME_TABLE
  // Note that entry #0 is the invalid intrinsic!
  "llvm.AMDGPU.abs",
  "llvm.AMDGPU.arl",
  "llvm.AMDGPU.barrier.global",
  "llvm.AMDGPU.barrier.local",
  "llvm.AMDGPU.bfe.i32",
  "llvm.AMDGPU.bfe.u32",
  "llvm.AMDGPU.bfi",
  "llvm.AMDGPU.bfm",
  "llvm.AMDGPU.brev",
  "llvm.AMDGPU.clamp",
  "llvm.AMDGPU.cndlt",
  "llvm.AMDGPU.cube",
  "llvm.AMDGPU.cvt.f32.ubyte0",
  "llvm.AMDGPU.cvt.f32.ubyte1",
  "llvm.AMDGPU.cvt.f32.ubyte2",
  "llvm.AMDGPU.cvt.f32.ubyte3",
  "llvm.AMDGPU.ddx",
  "llvm.AMDGPU.ddy",
  "llvm.AMDGPU.div",
  "llvm.AMDGPU.dp4",
  "llvm.AMDGPU.flbit.i32",
  "llvm.AMDGPU.fract",
  "llvm.AMDGPU.imad24",
  "llvm.AMDGPU.imax",
  "llvm.AMDGPU.imin",
  "llvm.AMDGPU.imul24",
  "llvm.AMDGPU.kill",
  "llvm.AMDGPU.kilp",
  "llvm.AMDGPU.legacy.rsq",
  "llvm.AMDGPU.lrp",
  "llvm.AMDGPU.mul",
  "llvm.AMDGPU.mullit",
  "llvm.AMDGPU.pow",
  "llvm.AMDGPU.seq",
  "llvm.AMDGPU.sge",
  "llvm.AMDGPU.sgt",
  "llvm.AMDGPU.sle",
  "llvm.AMDGPU.sne",
  "llvm.AMDGPU.store.output",
  "llvm.AMDGPU.swizzle",
  "llvm.AMDGPU.tex",
  "llvm.AMDGPU.trunc",
  "llvm.AMDGPU.txb",
  "llvm.AMDGPU.txd",
  "llvm.AMDGPU.txf",
  "llvm.AMDGPU.txl",
  "llvm.AMDGPU.txq",
  "llvm.AMDGPU.umad24",
  "llvm.AMDGPU.umax",
  "llvm.AMDGPU.umin",
  "llvm.AMDGPU.umul24",
  "llvm.AMDIL.abs",
  "llvm.AMDIL.clamp",
  "llvm.AMDIL.exp",
  "llvm.AMDIL.fraction",
  "llvm.AMDIL.round.nearest",
  "llvm.R600.ddx",
  "llvm.R600.ddy",
  "llvm.R600.interp.const",
  "llvm.R600.interp.input",
  "llvm.R600.interp.xy",
  "llvm.R600.interp.zw",
  "llvm.R600.ldptr",
  "llvm.R600.load.input",
  "llvm.R600.load.texbuf",
  "llvm.R600.store.dummy",
  "llvm.R600.store.pixel.depth",
  "llvm.R600.store.pixel.stencil",
  "llvm.R600.store.stream.output",
  "llvm.R600.store.swizzle",
  "llvm.R600.tex",
  "llvm.R600.texc",
  "llvm.R600.txb",
  "llvm.R600.txbc",
  "llvm.R600.txf",
  "llvm.R600.txl",
  "llvm.R600.txlc",
  "llvm.R600.txq",
  "llvm.SI.break",
  "llvm.SI.buffer.load.dword",
  "llvm.SI.else",
  "llvm.SI.else.break",
  "llvm.SI.end.cf",
  "llvm.SI.export",
  "llvm.SI.fs.constant",
  "llvm.SI.fs.interp",
  "llvm.SI.gather4",
  "llvm.SI.gather4.b",
  "llvm.SI.gather4.b.cl",
  "llvm.SI.gather4.b.cl.o",
  "llvm.SI.gather4.b.o",
  "llvm.SI.gather4.c",
  "llvm.SI.gather4.c.b",
  "llvm.SI.gather4.c.b.cl",
  "llvm.SI.gather4.c.b.cl.o",
  "llvm.SI.gather4.c.b.o",
  "llvm.SI.gather4.c.cl",
  "llvm.SI.gather4.c.cl.o",
  "llvm.SI.gather4.c.l",
  "llvm.SI.gather4.c.l.o",
  "llvm.SI.gather4.c.lz",
  "llvm.SI.gather4.c.lz.o",
  "llvm.SI.gather4.c.o",
  "llvm.SI.gather4.cl",
  "llvm.SI.gather4.cl.o",
  "llvm.SI.gather4.l",
  "llvm.SI.gather4.l.o",
  "llvm.SI.gather4.lz",
  "llvm.SI.gather4.lz.o",
  "llvm.SI.gather4.o",
  "llvm.SI.getlod",
  "llvm.SI.getresinfo",
  "llvm.SI.if",
  "llvm.SI.if.break",
  "llvm.SI.image.load",
  "llvm.SI.image.load.mip",
  "llvm.SI.image.sample",
  "llvm.SI.image.sample.b",
  "llvm.SI.image.sample.b.cl",
  "llvm.SI.image.sample.b.cl.o",
  "llvm.SI.image.sample.b.o",
  "llvm.SI.image.sample.c",
  "llvm.SI.image.sample.c.b",
  "llvm.SI.image.sample.c.b.cl",
  "llvm.SI.image.sample.c.b.cl.o",
  "llvm.SI.image.sample.c.b.o",
  "llvm.SI.image.sample.c.cd",
  "llvm.SI.image.sample.c.cd.cl",
  "llvm.SI.image.sample.c.cd.cl.o",
  "llvm.SI.image.sample.c.cd.o",
  "llvm.SI.image.sample.c.cl",
  "llvm.SI.image.sample.c.cl.o",
  "llvm.SI.image.sample.c.d",
  "llvm.SI.image.sample.c.d.cl",
  "llvm.SI.image.sample.c.d.cl.o",
  "llvm.SI.image.sample.c.d.o",
  "llvm.SI.image.sample.c.l",
  "llvm.SI.image.sample.c.l.o",
  "llvm.SI.image.sample.c.lz",
  "llvm.SI.image.sample.c.lz.o",
  "llvm.SI.image.sample.c.o",
  "llvm.SI.image.sample.cd",
  "llvm.SI.image.sample.cd.cl",
  "llvm.SI.image.sample.cd.cl.o",
  "llvm.SI.image.sample.cd.o",
  "llvm.SI.image.sample.cl",
  "llvm.SI.image.sample.cl.o",
  "llvm.SI.image.sample.d",
  "llvm.SI.image.sample.d.cl",
  "llvm.SI.image.sample.d.cl.o",
  "llvm.SI.image.sample.d.o",
  "llvm.SI.image.sample.l",
  "llvm.SI.image.sample.l.o",
  "llvm.SI.image.sample.lz",
  "llvm.SI.image.sample.lz.o",
  "llvm.SI.image.sample.o",
  "llvm.SI.imageload",
  "llvm.SI.load.const",
  "llvm.SI.loop",
  "llvm.SI.packf16",
  "llvm.SI.resinfo",
  "llvm.SI.sample",
  "llvm.SI.sampleb",
  "llvm.SI.sampled",
  "llvm.SI.samplel",
  "llvm.SI.sendmsg",
  "llvm.SI.tbuffer.store",
  "llvm.SI.tid",
  "llvm.SI.vs.load.input",
  "llvm.TGSI.lit.z",
#endif

// Intrinsic ID to overload bitset
#ifdef GET_INTRINSIC_OVERLOAD_TABLE
static const uint8_t OTable[] = {
  0,
  0 | (1<<2),
  0 | (1<<6),
  0,
  0,
  0,
  0 | (1<<4) | (1<<5) | (1<<6) | (1<<7),
  0 | (1<<0),
  0,
  0,
  0 | (1<<0) | (1<<7),
  0 | (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7),
  0 | (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7),
  0 | (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7),
  0 | (1<<0) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7),
  0 | (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7),
  0 | (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7),
  0 | (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7),
  0 | (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7),
  0 | (1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6),
  0 | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<7),
  0 | (1<<1)
};

return (OTable[id/8] & (1 << (id%8))) != 0;
#endif

// Function name -> enum value recognizer code.
#ifdef GET_FUNCTION_RECOGNIZER
  StringRef NameR(Name+6, Len-6);   // Skip over 'llvm.'
  switch (Name[5]) {                  // Dispatch on first letter.
  default: break;
  case 'A':
    if (NameR.startswith("MDIL.round.nearest.")) return AMDGPUIntrinsic::AMDIL_round_nearest;
    if (NameR.startswith("MDIL.fraction.")) return AMDGPUIntrinsic::AMDIL_fraction;
    if (NameR.startswith("MDIL.exp.")) return AMDGPUIntrinsic::AMDIL_exp;
    if (NameR.startswith("MDIL.clamp.")) return AMDGPUIntrinsic::AMDIL_clamp;
    if (NameR.startswith("MDIL.abs.")) return AMDGPUIntrinsic::AMDIL_abs;
    if (NameR.startswith("MDGPU.fract.")) return AMDGPUIntrinsic::AMDGPU_fract;
    if (NameR.startswith("MDGPU.clamp.")) return AMDGPUIntrinsic::AMDGPU_clamp;
    switch (NameR.size()) {
    default: break;
    case 9:	 // 22 strings to match.
      if (memcmp(NameR.data()+0, "MDGPU.", 6))
        break;
      switch (NameR[6]) {
      default: break;
      case 'a':	 // 2 strings to match.
        switch (NameR[7]) {
        default: break;
        case 'b':	 // 1 string to match.
          if (NameR[8] != 's')
            break;
          return AMDGPUIntrinsic::AMDGPU_abs;	 // "MDGPU.abs"
        case 'r':	 // 1 string to match.
          if (NameR[8] != 'l')
            break;
          return AMDGPUIntrinsic::AMDGPU_arl;	 // "MDGPU.arl"
        }
        break;
      case 'b':	 // 2 strings to match.
        if (NameR[7] != 'f')
          break;
        switch (NameR[8]) {
        default: break;
        case 'i':	 // 1 string to match.
          return AMDGPUIntrinsic::AMDGPU_bfi;	 // "MDGPU.bfi"
        case 'm':	 // 1 string to match.
          return AMDGPUIntrinsic::AMDGPU_bfm;	 // "MDGPU.bfm"
        }
        break;
      case 'd':	 // 4 strings to match.
        switch (NameR[7]) {
        default: break;
        case 'd':	 // 2 strings to match.
          switch (NameR[8]) {
          default: break;
          case 'x':	 // 1 string to match.
            return AMDGPUIntrinsic::AMDGPU_ddx;	 // "MDGPU.ddx"
          case 'y':	 // 1 string to match.
            return AMDGPUIntrinsic::AMDGPU_ddy;	 // "MDGPU.ddy"
          }
          break;
        case 'i':	 // 1 string to match.
          if (NameR[8] != 'v')
            break;
          return AMDGPUIntrinsic::AMDGPU_div;	 // "MDGPU.div"
        case 'p':	 // 1 string to match.
          if (NameR[8] != '4')
            break;
          return AMDGPUIntrinsic::AMDGPU_dp4;	 // "MDGPU.dp4"
        }
        break;
      case 'l':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "rp", 2))
          break;
        return AMDGPUIntrinsic::AMDGPU_lrp;	 // "MDGPU.lrp"
      case 'm':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "ul", 2))
          break;
        return AMDGPUIntrinsic::AMDGPU_mul;	 // "MDGPU.mul"
      case 'p':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "ow", 2))
          break;
        return AMDGPUIntrinsic::AMDGPU_pow;	 // "MDGPU.pow"
      case 's':	 // 5 strings to match.
        switch (NameR[7]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (NameR[8] != 'q')
            break;
          return AMDGPUIntrinsic::AMDGPU_seq;	 // "MDGPU.seq"
        case 'g':	 // 2 strings to match.
          switch (NameR[8]) {
          default: break;
          case 'e':	 // 1 string to match.
            return AMDGPUIntrinsic::AMDGPU_sge;	 // "MDGPU.sge"
          case 't':	 // 1 string to match.
            return AMDGPUIntrinsic::AMDGPU_sgt;	 // "MDGPU.sgt"
          }
          break;
        case 'l':	 // 1 string to match.
          if (NameR[8] != 'e')
            break;
          return AMDGPUIntrinsic::AMDGPU_sle;	 // "MDGPU.sle"
        case 'n':	 // 1 string to match.
          if (NameR[8] != 'e')
            break;
          return AMDGPUIntrinsic::AMDGPU_sne;	 // "MDGPU.sne"
        }
        break;
      case 't':	 // 6 strings to match.
        switch (NameR[7]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (NameR[8] != 'x')
            break;
          return AMDGPUIntrinsic::AMDGPU_tex;	 // "MDGPU.tex"
        case 'x':	 // 5 strings to match.
          switch (NameR[8]) {
          default: break;
          case 'b':	 // 1 string to match.
            return AMDGPUIntrinsic::AMDGPU_txb;	 // "MDGPU.txb"
          case 'd':	 // 1 string to match.
            return AMDGPUIntrinsic::AMDGPU_txd;	 // "MDGPU.txd"
          case 'f':	 // 1 string to match.
            return AMDGPUIntrinsic::AMDGPU_txf;	 // "MDGPU.txf"
          case 'l':	 // 1 string to match.
            return AMDGPUIntrinsic::AMDGPU_txl;	 // "MDGPU.txl"
          case 'q':	 // 1 string to match.
            return AMDGPUIntrinsic::AMDGPU_txq;	 // "MDGPU.txq"
          }
          break;
        }
        break;
      }
      break;
    case 10:	 // 8 strings to match.
      if (memcmp(NameR.data()+0, "MDGPU.", 6))
        break;
      switch (NameR[6]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "rev", 3))
          break;
        return AMDGPUIntrinsic::AMDGPU_brev;	 // "MDGPU.brev"
      case 'c':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "ube", 3))
          break;
        return AMDGPUIntrinsic::AMDGPU_cube;	 // "MDGPU.cube"
      case 'i':	 // 2 strings to match.
        if (NameR[7] != 'm')
          break;
        switch (NameR[8]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (NameR[9] != 'x')
            break;
          return AMDGPUIntrinsic::AMDGPU_imax;	 // "MDGPU.imax"
        case 'i':	 // 1 string to match.
          if (NameR[9] != 'n')
            break;
          return AMDGPUIntrinsic::AMDGPU_imin;	 // "MDGPU.imin"
        }
        break;
      case 'k':	 // 2 strings to match.
        if (memcmp(NameR.data()+7, "il", 2))
          break;
        switch (NameR[9]) {
        default: break;
        case 'l':	 // 1 string to match.
          return AMDGPUIntrinsic::AMDGPU_kill;	 // "MDGPU.kill"
        case 'p':	 // 1 string to match.
          return AMDGPUIntrinsic::AMDGPU_kilp;	 // "MDGPU.kilp"
        }
        break;
      case 'u':	 // 2 strings to match.
        if (NameR[7] != 'm')
          break;
        switch (NameR[8]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (NameR[9] != 'x')
            break;
          return AMDGPUIntrinsic::AMDGPU_umax;	 // "MDGPU.umax"
        case 'i':	 // 1 string to match.
          if (NameR[9] != 'n')
            break;
          return AMDGPUIntrinsic::AMDGPU_umin;	 // "MDGPU.umin"
        }
        break;
      }
      break;
    case 11:	 // 2 strings to match.
      if (memcmp(NameR.data()+0, "MDGPU.", 6))
        break;
      switch (NameR[6]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "ndlt", 4))
          break;
        return AMDGPUIntrinsic::AMDGPU_cndlt;	 // "MDGPU.cndlt"
      case 't':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "runc", 4))
          break;
        return AMDGPUIntrinsic::AMDGPU_trunc;	 // "MDGPU.trunc"
      }
      break;
    case 12:	 // 5 strings to match.
      if (memcmp(NameR.data()+0, "MDGPU.", 6))
        break;
      switch (NameR[6]) {
      default: break;
      case 'i':	 // 2 strings to match.
        if (NameR[7] != 'm')
          break;
        switch (NameR[8]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(NameR.data()+9, "d24", 3))
            break;
          return AMDGPUIntrinsic::AMDGPU_imad24;	 // "MDGPU.imad24"
        case 'u':	 // 1 string to match.
          if (memcmp(NameR.data()+9, "l24", 3))
            break;
          return AMDGPUIntrinsic::AMDGPU_imul24;	 // "MDGPU.imul24"
        }
        break;
      case 'm':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "ullit", 5))
          break;
        return AMDGPUIntrinsic::AMDGPU_mullit;	 // "MDGPU.mullit"
      case 'u':	 // 2 strings to match.
        if (NameR[7] != 'm')
          break;
        switch (NameR[8]) {
        default: break;
        case 'a':	 // 1 string to match.
          if (memcmp(NameR.data()+9, "d24", 3))
            break;
          return AMDGPUIntrinsic::AMDGPU_umad24;	 // "MDGPU.umad24"
        case 'u':	 // 1 string to match.
          if (memcmp(NameR.data()+9, "l24", 3))
            break;
          return AMDGPUIntrinsic::AMDGPU_umul24;	 // "MDGPU.umul24"
        }
        break;
      }
      break;
    case 13:	 // 3 strings to match.
      if (memcmp(NameR.data()+0, "MDGPU.", 6))
        break;
      switch (NameR[6]) {
      default: break;
      case 'b':	 // 2 strings to match.
        if (memcmp(NameR.data()+7, "fe.", 3))
          break;
        switch (NameR[10]) {
        default: break;
        case 'i':	 // 1 string to match.
          if (memcmp(NameR.data()+11, "32", 2))
            break;
          return AMDGPUIntrinsic::AMDGPU_bfe_i32;	 // "MDGPU.bfe.i32"
        case 'u':	 // 1 string to match.
          if (memcmp(NameR.data()+11, "32", 2))
            break;
          return AMDGPUIntrinsic::AMDGPU_bfe_u32;	 // "MDGPU.bfe.u32"
        }
        break;
      case 's':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "wizzle", 6))
          break;
        return AMDGPUIntrinsic::AMDGPU_swizzle;	 // "MDGPU.swizzle"
      }
      break;
    case 15:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "MDGPU.flbit.i32", 15))
        break;
      return AMDGPUIntrinsic::AMDGPU_flbit_i32;	 // "MDGPU.flbit.i32"
    case 16:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "MDGPU.legacy.rsq", 16))
        break;
      return AMDGPUIntrinsic::AMDGPU_legacy_rsq;	 // "MDGPU.legacy.rsq"
    case 18:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "MDGPU.store.output", 18))
        break;
      return AMDGPUIntrinsic::AMDGPU_store_output;	 // "MDGPU.store.output"
    case 19:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "MDGPU.barrier.local", 19))
        break;
      return AMDGPUIntrinsic::AMDGPU_barrier_local;	 // "MDGPU.barrier.local"
    case 20:	 // 5 strings to match.
      if (memcmp(NameR.data()+0, "MDGPU.", 6))
        break;
      switch (NameR[6]) {
      default: break;
      case 'b':	 // 1 string to match.
        if (memcmp(NameR.data()+7, "arrier.global", 13))
          break;
        return AMDGPUIntrinsic::AMDGPU_barrier_global;	 // "MDGPU.barrier.global"
      case 'c':	 // 4 strings to match.
        if (memcmp(NameR.data()+7, "vt.f32.ubyte", 12))
          break;
        switch (NameR[19]) {
        default: break;
        case '0':	 // 1 string to match.
          return AMDGPUIntrinsic::AMDGPU_cvt_f32_ubyte0;	 // "MDGPU.cvt.f32.ubyte0"
        case '1':	 // 1 string to match.
          return AMDGPUIntrinsic::AMDGPU_cvt_f32_ubyte1;	 // "MDGPU.cvt.f32.ubyte1"
        case '2':	 // 1 string to match.
          return AMDGPUIntrinsic::AMDGPU_cvt_f32_ubyte2;	 // "MDGPU.cvt.f32.ubyte2"
        case '3':	 // 1 string to match.
          return AMDGPUIntrinsic::AMDGPU_cvt_f32_ubyte3;	 // "MDGPU.cvt.f32.ubyte3"
        }
        break;
      }
      break;
    }
    break;  // end of 'A' case.
  case 'R':
    switch (NameR.size()) {
    default: break;
    case 7:	 // 7 strings to match.
      if (memcmp(NameR.data()+0, "600.", 4))
        break;
      switch (NameR[4]) {
      default: break;
      case 'd':	 // 2 strings to match.
        if (NameR[5] != 'd')
          break;
        switch (NameR[6]) {
        default: break;
        case 'x':	 // 1 string to match.
          return AMDGPUIntrinsic::R600_ddx;	 // "600.ddx"
        case 'y':	 // 1 string to match.
          return AMDGPUIntrinsic::R600_ddy;	 // "600.ddy"
        }
        break;
      case 't':	 // 5 strings to match.
        switch (NameR[5]) {
        default: break;
        case 'e':	 // 1 string to match.
          if (NameR[6] != 'x')
            break;
          return AMDGPUIntrinsic::R600_tex;	 // "600.tex"
        case 'x':	 // 4 strings to match.
          switch (NameR[6]) {
          default: break;
          case 'b':	 // 1 string to match.
            return AMDGPUIntrinsic::R600_txb;	 // "600.txb"
          case 'f':	 // 1 string to match.
            return AMDGPUIntrinsic::R600_txf;	 // "600.txf"
          case 'l':	 // 1 string to match.
            return AMDGPUIntrinsic::R600_txl;	 // "600.txl"
          case 'q':	 // 1 string to match.
            return AMDGPUIntrinsic::R600_txq;	 // "600.txq"
          }
          break;
        }
        break;
      }
      break;
    case 8:	 // 3 strings to match.
      if (memcmp(NameR.data()+0, "600.t", 5))
        break;
      switch (NameR[5]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(NameR.data()+6, "xc", 2))
          break;
        return AMDGPUIntrinsic::R600_texc;	 // "600.texc"
      case 'x':	 // 2 strings to match.
        switch (NameR[6]) {
        default: break;
        case 'b':	 // 1 string to match.
          if (NameR[7] != 'c')
            break;
          return AMDGPUIntrinsic::R600_txbc;	 // "600.txbc"
        case 'l':	 // 1 string to match.
          if (NameR[7] != 'c')
            break;
          return AMDGPUIntrinsic::R600_txlc;	 // "600.txlc"
        }
        break;
      }
      break;
    case 9:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "600.ldptr", 9))
        break;
      return AMDGPUIntrinsic::R600_ldptr;	 // "600.ldptr"
    case 13:	 // 2 strings to match.
      if (memcmp(NameR.data()+0, "600.interp.", 11))
        break;
      switch (NameR[11]) {
      default: break;
      case 'x':	 // 1 string to match.
        if (NameR[12] != 'y')
          break;
        return AMDGPUIntrinsic::R600_interp_xy;	 // "600.interp.xy"
      case 'z':	 // 1 string to match.
        if (NameR[12] != 'w')
          break;
        return AMDGPUIntrinsic::R600_interp_zw;	 // "600.interp.zw"
      }
      break;
    case 14:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "600.load.input", 14))
        break;
      return AMDGPUIntrinsic::R600_load_input;	 // "600.load.input"
    case 15:	 // 2 strings to match.
      if (memcmp(NameR.data()+0, "600.", 4))
        break;
      switch (NameR[4]) {
      default: break;
      case 'l':	 // 1 string to match.
        if (memcmp(NameR.data()+5, "oad.texbuf", 10))
          break;
        return AMDGPUIntrinsic::R600_load_texbuf;	 // "600.load.texbuf"
      case 's':	 // 1 string to match.
        if (memcmp(NameR.data()+5, "tore.dummy", 10))
          break;
        return AMDGPUIntrinsic::R600_store_dummy;	 // "600.store.dummy"
      }
      break;
    case 16:	 // 2 strings to match.
      if (memcmp(NameR.data()+0, "600.interp.", 11))
        break;
      switch (NameR[11]) {
      default: break;
      case 'c':	 // 1 string to match.
        if (memcmp(NameR.data()+12, "onst", 4))
          break;
        return AMDGPUIntrinsic::R600_interp_const;	 // "600.interp.const"
      case 'i':	 // 1 string to match.
        if (memcmp(NameR.data()+12, "nput", 4))
          break;
        return AMDGPUIntrinsic::R600_interp_input;	 // "600.interp.input"
      }
      break;
    case 17:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "600.store.swizzle", 17))
        break;
      return AMDGPUIntrinsic::R600_store_swizzle;	 // "600.store.swizzle"
    case 21:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "600.store.pixel.depth", 21))
        break;
      return AMDGPUIntrinsic::R600_store_pixel_depth;	 // "600.store.pixel.depth"
    case 23:	 // 2 strings to match.
      if (memcmp(NameR.data()+0, "600.store.", 10))
        break;
      switch (NameR[10]) {
      default: break;
      case 'p':	 // 1 string to match.
        if (memcmp(NameR.data()+11, "ixel.stencil", 12))
          break;
        return AMDGPUIntrinsic::R600_store_pixel_stencil;	 // "600.store.pixel.stencil"
      case 's':	 // 1 string to match.
        if (memcmp(NameR.data()+11, "tream.output", 12))
          break;
        return AMDGPUIntrinsic::R600_store_stream_output;	 // "600.store.stream.output"
      }
      break;
    }
    break;  // end of 'R' case.
  case 'S':
    if (NameR.startswith("I.vs.load.input.")) return AMDGPUIntrinsic::SI_vs_load_input;
    if (NameR.startswith("I.tbuffer.store.")) return AMDGPUIntrinsic::SI_tbuffer_store;
    if (NameR.startswith("I.samplel.")) return AMDGPUIntrinsic::SI_samplel;
    if (NameR.startswith("I.sampled.")) return AMDGPUIntrinsic::SI_sampled;
    if (NameR.startswith("I.sampleb.")) return AMDGPUIntrinsic::SI_sampleb;
    if (NameR.startswith("I.sample.")) return AMDGPUIntrinsic::SI_sample;
    if (NameR.startswith("I.load.const.")) return AMDGPUIntrinsic::SI_load_const;
    if (NameR.startswith("I.imageload.")) return AMDGPUIntrinsic::SI_imageload;
    if (NameR.startswith("I.image.sample.o.")) return AMDGPUIntrinsic::SI_image_sample_o;
    if (NameR.startswith("I.image.sample.lz.o.")) return AMDGPUIntrinsic::SI_image_sample_lz_o;
    if (NameR.startswith("I.image.sample.lz.")) return AMDGPUIntrinsic::SI_image_sample_lz;
    if (NameR.startswith("I.image.sample.l.o.")) return AMDGPUIntrinsic::SI_image_sample_l_o;
    if (NameR.startswith("I.image.sample.l.")) return AMDGPUIntrinsic::SI_image_sample_l;
    if (NameR.startswith("I.image.sample.d.o.")) return AMDGPUIntrinsic::SI_image_sample_d_o;
    if (NameR.startswith("I.image.sample.d.cl.o.")) return AMDGPUIntrinsic::SI_image_sample_d_cl_o;
    if (NameR.startswith("I.image.sample.d.cl.")) return AMDGPUIntrinsic::SI_image_sample_d_cl;
    if (NameR.startswith("I.image.sample.d.")) return AMDGPUIntrinsic::SI_image_sample_d;
    if (NameR.startswith("I.image.sample.cl.o.")) return AMDGPUIntrinsic::SI_image_sample_cl_o;
    if (NameR.startswith("I.image.sample.cl.")) return AMDGPUIntrinsic::SI_image_sample_cl;
    if (NameR.startswith("I.image.sample.cd.o.")) return AMDGPUIntrinsic::SI_image_sample_cd_o;
    if (NameR.startswith("I.image.sample.cd.cl.o.")) return AMDGPUIntrinsic::SI_image_sample_cd_cl_o;
    if (NameR.startswith("I.image.sample.cd.cl.")) return AMDGPUIntrinsic::SI_image_sample_cd_cl;
    if (NameR.startswith("I.image.sample.cd.")) return AMDGPUIntrinsic::SI_image_sample_cd;
    if (NameR.startswith("I.image.sample.c.o.")) return AMDGPUIntrinsic::SI_image_sample_c_o;
    if (NameR.startswith("I.image.sample.c.lz.o.")) return AMDGPUIntrinsic::SI_image_sample_c_lz_o;
    if (NameR.startswith("I.image.sample.c.lz.")) return AMDGPUIntrinsic::SI_image_sample_c_lz;
    if (NameR.startswith("I.image.sample.c.l.o.")) return AMDGPUIntrinsic::SI_image_sample_c_l_o;
    if (NameR.startswith("I.image.sample.c.l.")) return AMDGPUIntrinsic::SI_image_sample_c_l;
    if (NameR.startswith("I.image.sample.c.d.o.")) return AMDGPUIntrinsic::SI_image_sample_c_d_o;
    if (NameR.startswith("I.image.sample.c.d.cl.o.")) return AMDGPUIntrinsic::SI_image_sample_c_d_cl_o;
    if (NameR.startswith("I.image.sample.c.d.cl.")) return AMDGPUIntrinsic::SI_image_sample_c_d_cl;
    if (NameR.startswith("I.image.sample.c.d.")) return AMDGPUIntrinsic::SI_image_sample_c_d;
    if (NameR.startswith("I.image.sample.c.cl.o.")) return AMDGPUIntrinsic::SI_image_sample_c_cl_o;
    if (NameR.startswith("I.image.sample.c.cl.")) return AMDGPUIntrinsic::SI_image_sample_c_cl;
    if (NameR.startswith("I.image.sample.c.cd.o.")) return AMDGPUIntrinsic::SI_image_sample_c_cd_o;
    if (NameR.startswith("I.image.sample.c.cd.cl.o.")) return AMDGPUIntrinsic::SI_image_sample_c_cd_cl_o;
    if (NameR.startswith("I.image.sample.c.cd.cl.")) return AMDGPUIntrinsic::SI_image_sample_c_cd_cl;
    if (NameR.startswith("I.image.sample.c.cd.")) return AMDGPUIntrinsic::SI_image_sample_c_cd;
    if (NameR.startswith("I.image.sample.c.b.o.")) return AMDGPUIntrinsic::SI_image_sample_c_b_o;
    if (NameR.startswith("I.image.sample.c.b.cl.o.")) return AMDGPUIntrinsic::SI_image_sample_c_b_cl_o;
    if (NameR.startswith("I.image.sample.c.b.cl.")) return AMDGPUIntrinsic::SI_image_sample_c_b_cl;
    if (NameR.startswith("I.image.sample.c.b.")) return AMDGPUIntrinsic::SI_image_sample_c_b;
    if (NameR.startswith("I.image.sample.c.")) return AMDGPUIntrinsic::SI_image_sample_c;
    if (NameR.startswith("I.image.sample.b.o.")) return AMDGPUIntrinsic::SI_image_sample_b_o;
    if (NameR.startswith("I.image.sample.b.cl.o.")) return AMDGPUIntrinsic::SI_image_sample_b_cl_o;
    if (NameR.startswith("I.image.sample.b.cl.")) return AMDGPUIntrinsic::SI_image_sample_b_cl;
    if (NameR.startswith("I.image.sample.b.")) return AMDGPUIntrinsic::SI_image_sample_b;
    if (NameR.startswith("I.image.sample.")) return AMDGPUIntrinsic::SI_image_sample;
    if (NameR.startswith("I.image.load.mip.")) return AMDGPUIntrinsic::SI_image_load_mip;
    if (NameR.startswith("I.image.load.")) return AMDGPUIntrinsic::SI_image_load;
    if (NameR.startswith("I.getresinfo.")) return AMDGPUIntrinsic::SI_getresinfo;
    if (NameR.startswith("I.getlod.")) return AMDGPUIntrinsic::SI_getlod;
    if (NameR.startswith("I.gather4.o.")) return AMDGPUIntrinsic::SI_gather4_o;
    if (NameR.startswith("I.gather4.lz.o.")) return AMDGPUIntrinsic::SI_gather4_lz_o;
    if (NameR.startswith("I.gather4.lz.")) return AMDGPUIntrinsic::SI_gather4_lz;
    if (NameR.startswith("I.gather4.l.o.")) return AMDGPUIntrinsic::SI_gather4_l_o;
    if (NameR.startswith("I.gather4.l.")) return AMDGPUIntrinsic::SI_gather4_l;
    if (NameR.startswith("I.gather4.cl.o.")) return AMDGPUIntrinsic::SI_gather4_cl_o;
    if (NameR.startswith("I.gather4.cl.")) return AMDGPUIntrinsic::SI_gather4_cl;
    if (NameR.startswith("I.gather4.c.o.")) return AMDGPUIntrinsic::SI_gather4_c_o;
    if (NameR.startswith("I.gather4.c.lz.o.")) return AMDGPUIntrinsic::SI_gather4_c_lz_o;
    if (NameR.startswith("I.gather4.c.lz.")) return AMDGPUIntrinsic::SI_gather4_c_lz;
    if (NameR.startswith("I.gather4.c.l.o.")) return AMDGPUIntrinsic::SI_gather4_c_l_o;
    if (NameR.startswith("I.gather4.c.l.")) return AMDGPUIntrinsic::SI_gather4_c_l;
    if (NameR.startswith("I.gather4.c.cl.o.")) return AMDGPUIntrinsic::SI_gather4_c_cl_o;
    if (NameR.startswith("I.gather4.c.cl.")) return AMDGPUIntrinsic::SI_gather4_c_cl;
    if (NameR.startswith("I.gather4.c.b.o.")) return AMDGPUIntrinsic::SI_gather4_c_b_o;
    if (NameR.startswith("I.gather4.c.b.cl.o.")) return AMDGPUIntrinsic::SI_gather4_c_b_cl_o;
    if (NameR.startswith("I.gather4.c.b.cl.")) return AMDGPUIntrinsic::SI_gather4_c_b_cl;
    if (NameR.startswith("I.gather4.c.b.")) return AMDGPUIntrinsic::SI_gather4_c_b;
    if (NameR.startswith("I.gather4.c.")) return AMDGPUIntrinsic::SI_gather4_c;
    if (NameR.startswith("I.gather4.b.o.")) return AMDGPUIntrinsic::SI_gather4_b_o;
    if (NameR.startswith("I.gather4.b.cl.o.")) return AMDGPUIntrinsic::SI_gather4_b_cl_o;
    if (NameR.startswith("I.gather4.b.cl.")) return AMDGPUIntrinsic::SI_gather4_b_cl;
    if (NameR.startswith("I.gather4.b.")) return AMDGPUIntrinsic::SI_gather4_b;
    if (NameR.startswith("I.gather4.")) return AMDGPUIntrinsic::SI_gather4;
    if (NameR.startswith("I.buffer.load.dword.")) return AMDGPUIntrinsic::SI_buffer_load_dword;
    switch (NameR.size()) {
    default: break;
    case 4:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "I.if", 4))
        break;
      return AMDGPUIntrinsic::SI_if;	 // "I.if"
    case 5:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "I.tid", 5))
        break;
      return AMDGPUIntrinsic::SI_tid;	 // "I.tid"
    case 6:	 // 2 strings to match.
      if (memcmp(NameR.data()+0, "I.", 2))
        break;
      switch (NameR[2]) {
      default: break;
      case 'e':	 // 1 string to match.
        if (memcmp(NameR.data()+3, "lse", 3))
          break;
        return AMDGPUIntrinsic::SI_else;	 // "I.else"
      case 'l':	 // 1 string to match.
        if (memcmp(NameR.data()+3, "oop", 3))
          break;
        return AMDGPUIntrinsic::SI_loop;	 // "I.loop"
      }
      break;
    case 7:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "I.break", 7))
        break;
      return AMDGPUIntrinsic::SI_break;	 // "I.break"
    case 8:	 // 2 strings to match.
      if (memcmp(NameR.data()+0, "I.e", 3))
        break;
      switch (NameR[3]) {
      default: break;
      case 'n':	 // 1 string to match.
        if (memcmp(NameR.data()+4, "d.cf", 4))
          break;
        return AMDGPUIntrinsic::SI_end_cf;	 // "I.end.cf"
      case 'x':	 // 1 string to match.
        if (memcmp(NameR.data()+4, "port", 4))
          break;
        return AMDGPUIntrinsic::SI_export;	 // "I.export"
      }
      break;
    case 9:	 // 3 strings to match.
      if (memcmp(NameR.data()+0, "I.", 2))
        break;
      switch (NameR[2]) {
      default: break;
      case 'p':	 // 1 string to match.
        if (memcmp(NameR.data()+3, "ackf16", 6))
          break;
        return AMDGPUIntrinsic::SI_packf16;	 // "I.packf16"
      case 'r':	 // 1 string to match.
        if (memcmp(NameR.data()+3, "esinfo", 6))
          break;
        return AMDGPUIntrinsic::SI_resinfo;	 // "I.resinfo"
      case 's':	 // 1 string to match.
        if (memcmp(NameR.data()+3, "endmsg", 6))
          break;
        return AMDGPUIntrinsic::SI_sendmsg;	 // "I.sendmsg"
      }
      break;
    case 10:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "I.if.break", 10))
        break;
      return AMDGPUIntrinsic::SI_if_break;	 // "I.if.break"
    case 11:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "I.fs.interp", 11))
        break;
      return AMDGPUIntrinsic::SI_fs_interp;	 // "I.fs.interp"
    case 12:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "I.else.break", 12))
        break;
      return AMDGPUIntrinsic::SI_else_break;	 // "I.else.break"
    case 13:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "I.fs.constant", 13))
        break;
      return AMDGPUIntrinsic::SI_fs_constant;	 // "I.fs.constant"
    }
    break;  // end of 'S' case.
  case 'T':
    switch (NameR.size()) {
    default: break;
    case 9:	 // 1 string to match.
      if (memcmp(NameR.data()+0, "GSI.lit.z", 9))
        break;
      return AMDGPUIntrinsic::TGSI_lit_z;	 // "GSI.lit.z"
    }
    break;  // end of 'T' case.
  }
#endif

// Global intrinsic function declaration type table.
#ifdef GET_INTRINSIC_GENERATOR_GLOBAL
static const unsigned IIT_Table[] = {
  0x44, 0x74, 0x0, 0x0, 0x4444, 0x4444, 0x4444, 
  0x444, 0x44, 0x2F2F2F2F, 0x7777, 0x7A7A, 0x47, 0x47, 0x47, 
  0x47, 0x4447A7A, 0x4447A7A, 0x777, 0x7A7A7, 0x44, 0x2F2F, 0x4444, 
  0x444, 0x444, 0x444, 0x70, 0x0, 0x77, 0x7777, 0x777, 
  0x7777A, 0x777, 0x777, 0x777, 0x777, 0x777, 0x777, 0x470, 
  0x47A7A, 0x4447A7A, 0x77, 0x4447A7A, (1U<<31) | 102, (1U<<31) | 91, 0x4447A7A, 0x4447A7A, 
  0x4444, 0x444, 0x444, 0x444, 0x1F1F, 0x2F2F2F2F, 0x2F2F, 0x2F2F, 
  0x2F2F, (1U<<31) | 31, (1U<<31) | 31, 0x47A, 0x447, 0x77479, 0x77479, (1U<<31) | 17, 
  0x47, 0x447A, 0x40, 0x70, 0x70, 0x4447A0, 0x447A0, (1U<<31) | 31, 
  (1U<<31) | 31, (1U<<31) | 31, (1U<<31) | 31, (1U<<31) | 17, (1U<<31) | 31, (1U<<31) | 31, (1U<<31) | 17, 0x55, 
  (1U<<31) | 77, (1U<<31) | 143, 0x555, 0x50, (1U<<31) | 124, 0x4447, 0x494447, (1U<<31) | 45, 
  (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, 
  (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, 
  (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, 
  (1U<<31) | 62, (1U<<31) | 135, 0x515, (1U<<31) | 62, (1U<<31) | 62, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, 
  (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, 
  (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, 
  (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, 
  (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, 
  (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, (1U<<31) | 45, 0x42D3F4A, 0x41F7, (1U<<31) | 139, 
  0x774, 0x42D44A, (1U<<31) | 114, (1U<<31) | 114, (1U<<31) | 114, (1U<<31) | 114, 0x440, (1U<<31) | 0, 
  0x4, 0x431F7A, 0x7777, 0
};

static const unsigned char IIT_LongEncodingTable[] = {
  /* 0 */ 0, 15, 1, 15, 9, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,
  /* 17 */ 10, 4, 10, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,
  /* 31 */ 10, 7, 10, 7, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,
  /* 45 */ 10, 7, 15, 1, 11, 4, 10, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,
  /* 62 */ 10, 7, 15, 1, 11, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0,
  /* 77 */ 15, 1, 15, 9, 15, 17, 4, 4, 4, 4, 4, 4, 4, 0,
  /* 91 */ 10, 7, 10, 7, 4, 4, 4, 4, 4, 4, 0,
  /* 102 */ 10, 7, 10, 7, 10, 7, 10, 7, 4, 4, 4, 0,
  /* 114 */ 10, 7, 15, 3, 13, 2, 15, 9, 4, 0,
  /* 124 */ 0, 4, 4, 4, 4, 4, 7, 7, 7, 7, 0,
  /* 135 */ 5, 1, 20, 0,
  /* 139 */ 0, 5, 20, 0,
  /* 143 */ 5, 5, 20, 0,
  255
};

#endif

// Add parameter attributes that are not common to all intrinsics.
#ifdef GET_INTRINSIC_ATTRIBUTES
static AttributeSet getAttributes(LLVMContext &C, AMDGPUIntrinsic::ID id) {
  static const uint8_t IntrinsicsToAttributesMap[] = {
    1, // llvm.AMDGPU.abs
    1, // llvm.AMDGPU.arl
    2, // llvm.AMDGPU.barrier.global
    2, // llvm.AMDGPU.barrier.local
    1, // llvm.AMDGPU.bfe.i32
    1, // llvm.AMDGPU.bfe.u32
    1, // llvm.AMDGPU.bfi
    1, // llvm.AMDGPU.bfm
    1, // llvm.AMDGPU.brev
    1, // llvm.AMDGPU.clamp
    1, // llvm.AMDGPU.cndlt
    1, // llvm.AMDGPU.cube
    1, // llvm.AMDGPU.cvt.f32.ubyte0
    1, // llvm.AMDGPU.cvt.f32.ubyte1
    1, // llvm.AMDGPU.cvt.f32.ubyte2
    1, // llvm.AMDGPU.cvt.f32.ubyte3
    1, // llvm.AMDGPU.ddx
    1, // llvm.AMDGPU.ddy
    1, // llvm.AMDGPU.div
    1, // llvm.AMDGPU.dp4
    1, // llvm.AMDGPU.flbit.i32
    1, // llvm.AMDGPU.fract
    1, // llvm.AMDGPU.imad24
    1, // llvm.AMDGPU.imax
    1, // llvm.AMDGPU.imin
    1, // llvm.AMDGPU.imul24
    2, // llvm.AMDGPU.kill
    2, // llvm.AMDGPU.kilp
    1, // llvm.AMDGPU.legacy.rsq
    1, // llvm.AMDGPU.lrp
    1, // llvm.AMDGPU.mul
    1, // llvm.AMDGPU.mullit
    1, // llvm.AMDGPU.pow
    1, // llvm.AMDGPU.seq
    1, // llvm.AMDGPU.sge
    1, // llvm.AMDGPU.sgt
    1, // llvm.AMDGPU.sle
    1, // llvm.AMDGPU.sne
    2, // llvm.AMDGPU.store.output
    1, // llvm.AMDGPU.swizzle
    1, // llvm.AMDGPU.tex
    1, // llvm.AMDGPU.trunc
    1, // llvm.AMDGPU.txb
    1, // llvm.AMDGPU.txd
    1, // llvm.AMDGPU.txf
    1, // llvm.AMDGPU.txl
    1, // llvm.AMDGPU.txq
    1, // llvm.AMDGPU.umad24
    1, // llvm.AMDGPU.umax
    1, // llvm.AMDGPU.umin
    1, // llvm.AMDGPU.umul24
    1, // llvm.AMDIL.abs
    1, // llvm.AMDIL.clamp
    1, // llvm.AMDIL.exp
    1, // llvm.AMDIL.fraction
    1, // llvm.AMDIL.round.nearest
    1, // llvm.R600.ddx
    1, // llvm.R600.ddy
    1, // llvm.R600.interp.const
    1, // llvm.R600.interp.input
    1, // llvm.R600.interp.xy
    1, // llvm.R600.interp.zw
    1, // llvm.R600.ldptr
    1, // llvm.R600.load.input
    1, // llvm.R600.load.texbuf
    2, // llvm.R600.store.dummy
    2, // llvm.R600.store.pixel.depth
    2, // llvm.R600.store.pixel.stencil
    2, // llvm.R600.store.stream.output
    2, // llvm.R600.store.swizzle
    1, // llvm.R600.tex
    1, // llvm.R600.texc
    1, // llvm.R600.txb
    1, // llvm.R600.txbc
    1, // llvm.R600.txf
    1, // llvm.R600.txl
    1, // llvm.R600.txlc
    1, // llvm.R600.txq
    2, // llvm.SI.break
    3, // llvm.SI.buffer.load.dword
    2, // llvm.SI.else
    2, // llvm.SI.else.break
    2, // llvm.SI.end.cf
    2, // llvm.SI.export
    1, // llvm.SI.fs.constant
    1, // llvm.SI.fs.interp
    1, // llvm.SI.gather4
    1, // llvm.SI.gather4.b
    1, // llvm.SI.gather4.b.cl
    1, // llvm.SI.gather4.b.cl.o
    1, // llvm.SI.gather4.b.o
    1, // llvm.SI.gather4.c
    1, // llvm.SI.gather4.c.b
    1, // llvm.SI.gather4.c.b.cl
    1, // llvm.SI.gather4.c.b.cl.o
    1, // llvm.SI.gather4.c.b.o
    1, // llvm.SI.gather4.c.cl
    1, // llvm.SI.gather4.c.cl.o
    1, // llvm.SI.gather4.c.l
    1, // llvm.SI.gather4.c.l.o
    1, // llvm.SI.gather4.c.lz
    1, // llvm.SI.gather4.c.lz.o
    1, // llvm.SI.gather4.c.o
    1, // llvm.SI.gather4.cl
    1, // llvm.SI.gather4.cl.o
    1, // llvm.SI.gather4.l
    1, // llvm.SI.gather4.l.o
    1, // llvm.SI.gather4.lz
    1, // llvm.SI.gather4.lz.o
    1, // llvm.SI.gather4.o
    1, // llvm.SI.getlod
    1, // llvm.SI.getresinfo
    2, // llvm.SI.if
    2, // llvm.SI.if.break
    1, // llvm.SI.image.load
    1, // llvm.SI.image.load.mip
    1, // llvm.SI.image.sample
    1, // llvm.SI.image.sample.b
    1, // llvm.SI.image.sample.b.cl
    1, // llvm.SI.image.sample.b.cl.o
    1, // llvm.SI.image.sample.b.o
    1, // llvm.SI.image.sample.c
    1, // llvm.SI.image.sample.c.b
    1, // llvm.SI.image.sample.c.b.cl
    1, // llvm.SI.image.sample.c.b.cl.o
    1, // llvm.SI.image.sample.c.b.o
    1, // llvm.SI.image.sample.c.cd
    1, // llvm.SI.image.sample.c.cd.cl
    1, // llvm.SI.image.sample.c.cd.cl.o
    1, // llvm.SI.image.sample.c.cd.o
    1, // llvm.SI.image.sample.c.cl
    1, // llvm.SI.image.sample.c.cl.o
    1, // llvm.SI.image.sample.c.d
    1, // llvm.SI.image.sample.c.d.cl
    1, // llvm.SI.image.sample.c.d.cl.o
    1, // llvm.SI.image.sample.c.d.o
    1, // llvm.SI.image.sample.c.l
    1, // llvm.SI.image.sample.c.l.o
    1, // llvm.SI.image.sample.c.lz
    1, // llvm.SI.image.sample.c.lz.o
    1, // llvm.SI.image.sample.c.o
    1, // llvm.SI.image.sample.cd
    1, // llvm.SI.image.sample.cd.cl
    1, // llvm.SI.image.sample.cd.cl.o
    1, // llvm.SI.image.sample.cd.o
    1, // llvm.SI.image.sample.cl
    1, // llvm.SI.image.sample.cl.o
    1, // llvm.SI.image.sample.d
    1, // llvm.SI.image.sample.d.cl
    1, // llvm.SI.image.sample.d.cl.o
    1, // llvm.SI.image.sample.d.o
    1, // llvm.SI.image.sample.l
    1, // llvm.SI.image.sample.l.o
    1, // llvm.SI.image.sample.lz
    1, // llvm.SI.image.sample.lz.o
    1, // llvm.SI.image.sample.o
    1, // llvm.SI.imageload
    1, // llvm.SI.load.const
    2, // llvm.SI.loop
    1, // llvm.SI.packf16
    1, // llvm.SI.resinfo
    1, // llvm.SI.sample
    1, // llvm.SI.sampleb
    1, // llvm.SI.sampled
    1, // llvm.SI.samplel
    1, // llvm.SI.sendmsg
    2, // llvm.SI.tbuffer.store
    1, // llvm.SI.tid
    1, // llvm.SI.vs.load.input
    1, // llvm.TGSI.lit.z
  };

  AttributeSet AS[1];
  unsigned NumAttrs = 0;
  if (id != 0) {
    switch(IntrinsicsToAttributesMap[id - Intrinsic::num_intrinsics]) {
    default: llvm_unreachable("Invalid attribute number");
    case 2: {
      const Attribute::AttrKind Atts[] = {Attribute::NoUnwind};
      AS[0] = AttributeSet::get(C, AttributeSet::FunctionIndex, Atts);
      NumAttrs = 1;
      break;
      }
    case 3: {
      const Attribute::AttrKind Atts[] = {Attribute::NoUnwind,Attribute::ReadOnly,Attribute::ArgMemOnly};
      AS[0] = AttributeSet::get(C, AttributeSet::FunctionIndex, Atts);
      NumAttrs = 1;
      break;
      }
    case 1: {
      const Attribute::AttrKind Atts[] = {Attribute::NoUnwind,Attribute::ReadNone};
      AS[0] = AttributeSet::get(C, AttributeSet::FunctionIndex, Atts);
      NumAttrs = 1;
      break;
      }
    }
  }
  return AttributeSet::get(C, makeArrayRef(AS, NumAttrs));
}
#endif // GET_INTRINSIC_ATTRIBUTES

// Get the LLVM intrinsic that corresponds to a GCC builtin.
// This is used by the C front-end.  The GCC builtin name is passed
// in as BuiltinName, and a target prefix (e.g. 'ppc') is passed
// in as TargetPrefix.  The result is assigned to 'IntrinsicID'.
#ifdef GET_LLVM_INTRINSIC_FOR_GCC_BUILTIN
static AMDGPUIntrinsic::ID getIntrinsicForGCCBuiltin(const char *TargetPrefixStr, const char *BuiltinNameStr) {
  StringRef BuiltinName(BuiltinNameStr);
  StringRef TargetPrefix(TargetPrefixStr);

  return (AMDGPUIntrinsic::ID)Intrinsic::not_intrinsic;
}
#endif

// Get the LLVM intrinsic that corresponds to a MS builtin.
// This is used by the C front-end.  The MS builtin name is passed
// in as a BuiltinName, and a target prefix (e.g. 'arm') is passed
// in as a TargetPrefix.  The result is assigned to 'IntrinsicID'.
#ifdef GET_LLVM_INTRINSIC_FOR_MS_BUILTIN
static AMDGPUIntrinsic::ID getIntrinsicForMSBuiltin(const char *TP, const char *BN) {
  StringRef BuiltinName(BN);
  StringRef TargetPrefix(TP);

  return (AMDGPUIntrinsic::ID)Intrinsic::not_intrinsic;
}
#endif

#if defined(_MSC_VER) && defined(setjmp_undefined_for_msvc)
// let's return it to _setjmp state
#  pragma pop_macro("setjmp")
#  undef setjmp_undefined_for_msvc
#endif

