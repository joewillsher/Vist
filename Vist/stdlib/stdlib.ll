; ModuleID = 'stdlib.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }
%Double = type { double }
%Int = type { i64 }
%String = type { i8*, %Int, %Int }
%Bool = type { i1 }
%Range = type { %Int, %Int }
%Int32 = type { i32 }

@__stdoutp = external global %struct.__sFILE*
@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_ti64(i64 %i) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i) #9
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_ti32(i32 %i) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), i32 %i) #9
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf64(double %d) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d) #9
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf32(float %d) #0 {
entry:
  %conv = fpext float %d to double
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %conv) #9
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tb(i1 zeroext %b) #0 {
entry:
  %cond = select i1 %b, i8* getelementptr inbounds ([6 x i8]* @.str3, i64 0, i64 0), i8* getelementptr inbounds ([7 x i8]* @.str4, i64 0, i64 0)
  %call = tail call i32 (i8*, ...)* @printf(i8* %cond) #9
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist-Ucshim-Uwrite_topi64(i8* %str, i64 %size) #2 {
entry:
  %0 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !2
  %call = tail call i64 @"\01_fwrite"(i8* %str, i64 %size, i64 1, %struct.__sFILE* %0) #9
  ret void
}

declare i64 @"\01_fwrite"(i8*, i64, i64, %struct.__sFILE*) #3

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Ucshim-Uputchar_ti8(i8 signext %c) #0 {
entry:
  %conv = sext i8 %c to i32
  %0 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !2
  %_w.i = getelementptr inbounds %struct.__sFILE* %0, i64 0, i32 2
  %1 = load i32* %_w.i, align 4, !tbaa !6
  %dec.i = add nsw i32 %1, -1
  store i32 %dec.i, i32* %_w.i, align 4, !tbaa !6
  %cmp.i = icmp sgt i32 %1, 0
  br i1 %cmp.i, label %if.then.i, label %lor.lhs.false.i

lor.lhs.false.i:                                  ; preds = %entry
  %_lbfsize.i = getelementptr inbounds %struct.__sFILE* %0, i64 0, i32 6
  %2 = load i32* %_lbfsize.i, align 4, !tbaa !12
  %cmp2.i = icmp sle i32 %1, %2
  %sext.mask.i = and i32 %conv, 255
  %cmp4.i = icmp eq i32 %sext.mask.i, 10
  %or.cond.i = or i1 %cmp4.i, %cmp2.i
  br i1 %or.cond.i, label %if.else.i, label %if.then.i

if.then.i:                                        ; preds = %lor.lhs.false.i, %entry
  %_p7.i = getelementptr inbounds %struct.__sFILE* %0, i64 0, i32 0
  %3 = load i8** %_p7.i, align 8, !tbaa !13
  %incdec.ptr.i = getelementptr inbounds i8* %3, i64 1
  store i8* %incdec.ptr.i, i8** %_p7.i, align 8, !tbaa !13
  store i8 %c, i8* %3, align 1, !tbaa !14
  br label %__sputc.exit

if.else.i:                                        ; preds = %lor.lhs.false.i
  %call.i = tail call i32 @__swbuf(i32 %conv, %struct.__sFILE* %0) #9
  br label %__sputc.exit

__sputc.exit:                                     ; preds = %if.else.i, %if.then.i
  ret void
}

declare i32 @__swbuf(i32, %struct.__sFILE*) #3

; Function Attrs: alwaysinline nounwind readnone
define %Double @Double_tD(%Double %val) #4 {
entry:
  ret %Double %val
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @-T-O_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = or i64 %1, %0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @Int_ti64(i64 %"$0") #4 {
entry:
  %.fca.0.insert = insertvalue %Int undef, i64 %"$0", 0
  ret %Int %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @-D_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = sdiv i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Double @-P_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fadd double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind
define %String @String_topi64b(i8* nocapture readonly %ptr, i64 %count, i1 %isUTF8Encoded) #5 {
entry:
  %0 = trunc i64 %count to i32
  %1 = tail call i8* @malloc(i32 %0)
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %1, i8* %ptr, i64 %count, i32 1, i1 false)
  %2 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %count, i64 1) #9
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %-.trap.i, label %-M_tII.exit

-.trap.i:                                         ; preds = %entry
  tail call void @llvm.trap() #9
  unreachable

-M_tII.exit:                                      ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = shl i64 %count, 1
  %6 = zext i1 %isUTF8Encoded to i64
  %. = or i64 %5, %6
  %.fca.0.insert9 = insertvalue %String undef, i8* %1, 0
  %.fca.1.0.insert = insertvalue %String %.fca.0.insert9, i64 %4, 1, 0
  %.fca.2.0.insert = insertvalue %String %.fca.1.0.insert, i64 %., 2, 0
  ret %String %.fca.2.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-L-E_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sle i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-O-O_tBB(%Bool %a, %Bool %b) #4 {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = or i1 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-G_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ogt double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Double @Double_tf64(double %"$0") #4 {
entry:
  %.fca.0.insert = insertvalue %Double undef, double %"$0", 0
  ret %Double %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-G_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sgt i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind
define void @print_tI(%Int %a) #5 {
entry:
  %0 = extractvalue %Int %a, 0
  tail call void @vist-Uprint_ti64(i64 %0)
  ret void
}

define void @generate_mRPtI(%Range %self, void (%Int)* nocapture %loop_thunk) {
entry:
  %start = extractvalue %Range %self, 0
  %start.fca.0.extract11 = extractvalue %Int %start, 0
  %end = extractvalue %Range %self, 1
  %0 = extractvalue %Int %end, 0
  %1 = icmp slt i64 %start.fca.0.extract11, %0
  br i1 %1, label %loop.preheader, label %loop.exit

loop.preheader:                                   ; preds = %entry
  br label %loop

loop:                                             ; preds = %loop.preheader, %-P_tII.exit
  %start.fca.0.extract13 = phi i64 [ %4, %-P_tII.exit ], [ %start.fca.0.extract11, %loop.preheader ]
  %start.sink12 = phi %Int [ %.fca.0.insert.i.i10, %-P_tII.exit ], [ %start, %loop.preheader ]
  tail call void %loop_thunk(%Int %start.sink12)
  %2 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %start.fca.0.extract13, i64 1) #9
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"+.trap.i", label %-P_tII.exit

"+.trap.i":                                       ; preds = %loop
  tail call void @llvm.trap() #9
  unreachable

-P_tII.exit:                                      ; preds = %loop
  %4 = extractvalue { i64, i1 } %2, 0
  %.fca.0.insert.i.i10 = insertvalue %Int undef, i64 %4, 0
  %5 = icmp slt i64 %4, %0
  br i1 %5, label %loop, label %loop.exit.loopexit

loop.exit.loopexit:                               ; preds = %-P_tII.exit
  br label %loop.exit

loop.exit:                                        ; preds = %loop.exit.loopexit, %entry
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @-C_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = srem i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @-T-N_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = and i64 %1, %0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Range @-D-D-D_tII(%Int %a, %Int %b) #4 {
entry:
  %"$0.fca.0.extract.i" = extractvalue %Int %a, 0
  %"$1.fca.0.extract.i" = extractvalue %Int %b, 0
  %.fca.0.0.insert.i = insertvalue %Range undef, i64 %"$0.fca.0.extract.i", 0, 0
  %.fca.1.0.insert.i = insertvalue %Range %.fca.0.0.insert.i, i64 %"$1.fca.0.extract.i", 1, 0
  ret %Range %.fca.1.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @Bool_tB(%Bool %val) #4 {
entry:
  ret %Bool %val
}

; Function Attrs: alwaysinline noreturn nounwind
define void @fatalError_t() #6 {
entry:
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline nounwind readnone
define %Int32 @Int32_tI32(%Int32 %val) #4 {
entry:
  ret %Int32 %val
}

; Function Attrs: alwaysinline nounwind readnone
define %Int32 @Int32_ti32(i32 %"$0") #4 {
entry:
  %.fca.0.insert = insertvalue %Int32 undef, i32 %"$0", 0
  ret %Int32 %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define i8* @-P_topI(i8* readnone %pointer, %Int %offset) #4 {
entry:
  %0 = extractvalue %Int %offset, 0
  %1 = getelementptr i8* %pointer, i64 %0
  ret i8* %1
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-L_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp olt double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-E-E_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp eq i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-G-E_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ole double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Range @Range_tII(%Int %"$0", %Int %"$1") #4 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int %"$1", 0
  %.fca.0.0.insert = insertvalue %Range undef, i64 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue %Range %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret %Range %.fca.1.0.insert
}

; Function Attrs: alwaysinline nounwind
define void @print_tString.loop_thunk(i8 %c) #5 {
entry:
  tail call void @vist-Ucshim-Uputchar_ti8(i8 %c)
  ret void
}

; Function Attrs: alwaysinline nounwind
define void @print_tI32(%Int32 %a) #5 {
entry:
  %0 = extractvalue %Int32 %a, 0
  tail call void @vist-Uprint_ti32(i32 %0)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Double @-C_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = frem double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind
define %Int @-P_tII(%Int %a, %Int %b) #5 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %0, i64 %1)
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"+.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %4, 0
  ret %Int %.fca.0.insert.i

"+.trap":                                         ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @-L-L_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = shl i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-G-E_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sge i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @-G-G_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = ashr i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Int @bufferCapacity_mString(%String %self) #7 {
entry:
  %_capacityAndEncoding = extractvalue %String %self, 2
  %0 = extractvalue %Int %_capacityAndEncoding, 0
  %1 = ashr i64 %0, 1
  %.fca.0.insert.i.i = insertvalue %Int undef, i64 %1, 0
  ret %Int %.fca.0.insert.i.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-L-E_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ole double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @Bool_tb(i1 %"$0") #4 {
entry:
  %.fca.0.insert = insertvalue %Bool undef, i1 %"$0", 0
  ret %Bool %.fca.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @Bool_t() #4 {
entry:
  ret %Bool zeroinitializer
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-E-E_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp oeq double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-L_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp slt i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %String @String_topII(i8* %"$0", %Int %"$1", %Int %"$2") #4 {
entry:
  %"$1.fca.0.extract" = extractvalue %Int %"$1", 0
  %"$2.fca.0.extract" = extractvalue %Int %"$2", 0
  %.fca.0.insert = insertvalue %String undef, i8* %"$0", 0
  %.fca.1.0.insert = insertvalue %String %.fca.0.insert, i64 %"$1.fca.0.extract", 1, 0
  %.fca.2.0.insert = insertvalue %String %.fca.1.0.insert, i64 %"$2.fca.0.extract", 2, 0
  ret %String %.fca.2.0.insert
}

; Function Attrs: alwaysinline ssp
define void @print_tString(%String %str) #8 {
entry:
  %_capacityAndEncoding.i = extractvalue %String %str, 2
  %0 = extractvalue %Int %_capacityAndEncoding.i, 0
  %1 = and i64 %0, 1
  %2 = icmp eq i64 %1, 0
  br i1 %2, label %else.1, label %if.0

if.0:                                             ; preds = %entry
  %3 = extractvalue %String %str, 0
  %4 = extractvalue %String %str, 1
  %5 = extractvalue %Int %4, 0
  %6 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !2
  %call.i = tail call i64 @"\01_fwrite"(i8* %3, i64 %5, i64 1, %struct.__sFILE* %6) #9
  ret void

else.1:                                           ; preds = %entry
  %7 = ashr i64 %0, 1
  %8 = icmp sgt i64 %7, 0
  br i1 %8, label %loop.lr.ph.i, label %generate_mStringPti8.exit

loop.lr.ph.i:                                     ; preds = %else.1
  %base.i.i = extractvalue %String %str, 0
  br label %loop.i

loop.i:                                           ; preds = %-P_tII.exit.i, %loop.lr.ph.i
  %.sroa.0.012.i = phi i64 [ 0, %loop.lr.ph.i ], [ %13, %-P_tII.exit.i ]
  %9 = getelementptr i8* %base.i.i, i64 %.sroa.0.012.i
  %10 = load i8* %9, align 1
  tail call void @vist-Ucshim-Uputchar_ti8(i8 %10) #9
  %11 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %.sroa.0.012.i, i64 1) #9
  %12 = extractvalue { i64, i1 } %11, 1
  br i1 %12, label %"+.trap.i.i", label %-P_tII.exit.i

"+.trap.i.i":                                     ; preds = %loop.i
  tail call void @llvm.trap() #9
  unreachable

-P_tII.exit.i:                                    ; preds = %loop.i
  %13 = extractvalue { i64, i1 } %11, 0
  %14 = icmp slt i64 %13, %7
  br i1 %14, label %loop.i, label %generate_mStringPti8.exit.loopexit

generate_mStringPti8.exit.loopexit:               ; preds = %-P_tII.exit.i
  br label %generate_mStringPti8.exit

generate_mStringPti8.exit:                        ; preds = %generate_mStringPti8.exit.loopexit, %else.1
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Range @Range_tR(%Range %val) #4 {
entry:
  %0 = extractvalue %Range %val, 0
  %.fca.0.extract = extractvalue %Int %0, 0
  %1 = extractvalue %Range %val, 1
  %.fca.0.extract1 = extractvalue %Int %1, 0
  %.fca.0.0.insert = insertvalue %Range undef, i64 %.fca.0.extract, 0, 0
  %.fca.1.0.insert = insertvalue %Range %.fca.0.0.insert, i64 %.fca.0.extract1, 1, 0
  ret %Range %.fca.1.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Double @-M_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fsub double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind
define void @print_tD(%Double %a) #5 {
entry:
  %0 = extractvalue %Double %a, 0
  tail call void @vist-Uprint_tf64(double %0)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-N-N_tBB(%Bool %a, %Bool %b) #4 {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = and i1 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @-T-R_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = xor i64 %1, %0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

define void @generate_mStringPti8(%String %self, void (i8)* nocapture %loop_thunk) {
entry:
  %_capacityAndEncoding.i = extractvalue %String %self, 2
  %0 = extractvalue %Int %_capacityAndEncoding.i, 0
  %1 = ashr i64 %0, 1
  %2 = icmp sgt i64 %1, 0
  br i1 %2, label %loop.lr.ph, label %loop.exit

loop.lr.ph:                                       ; preds = %entry
  %base.i = extractvalue %String %self, 0
  br label %loop

loop:                                             ; preds = %loop.lr.ph, %-P_tII.exit
  %.sroa.0.012 = phi i64 [ 0, %loop.lr.ph ], [ %7, %-P_tII.exit ]
  %3 = getelementptr i8* %base.i, i64 %.sroa.0.012
  %4 = load i8* %3, align 1
  tail call void %loop_thunk(i8 %4)
  %5 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %.sroa.0.012, i64 1) #9
  %6 = extractvalue { i64, i1 } %5, 1
  br i1 %6, label %"+.trap.i", label %-P_tII.exit

"+.trap.i":                                       ; preds = %loop
  tail call void @llvm.trap() #9
  unreachable

-P_tII.exit:                                      ; preds = %loop
  %7 = extractvalue { i64, i1 } %5, 0
  %8 = icmp slt i64 %7, %1
  br i1 %8, label %loop, label %loop.exit.loopexit

loop.exit.loopexit:                               ; preds = %-P_tII.exit
  br label %loop.exit

loop.exit:                                        ; preds = %loop.exit.loopexit, %entry
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Double @-A_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fmul double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-B-E_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp ne i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define i8* @codeUnitAtIndex_mStringI(%String %self, %Int %index) #7 {
entry:
  %base = extractvalue %String %self, 0
  %0 = extractvalue %Int %index, 0
  %1 = getelementptr i8* %base, i64 %0
  ret i8* %1
}

; Function Attrs: nounwind readnone
define %Bool @isUTF8Encoded_mString(%String %self) #7 {
entry:
  %_capacityAndEncoding = extractvalue %String %self, 2
  %0 = extractvalue %Int %_capacityAndEncoding, 0
  %1 = and i64 %0, 1
  %2 = icmp ne i64 %1, 0
  %.fca.0.insert.i.i1 = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i.i1
}

; Function Attrs: alwaysinline nounwind
define %Int @-M_tII(%Int %a, %Int %b) #5 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 %1)
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %-.trap, label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %4, 0
  ret %Int %.fca.0.insert.i

-.trap:                                           ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline nounwind
define %Int @-A_tII(%Int %a, %Int %b) #5 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %0, i64 %1)
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"*.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %4, 0
  ret %Int %.fca.0.insert.i

"*.trap":                                         ; preds = %entry
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @Int_t() #4 {
entry:
  ret %Int zeroinitializer
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-B-E_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp one double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Int @Int_tI(%Int %val) #4 {
entry:
  ret %Int %val
}

; Function Attrs: alwaysinline nounwind
define void @print_tB(%Bool %a) #5 {
entry:
  %0 = extractvalue %Bool %a, 0
  tail call void @vist-Uprint_tb(i1 %0)
  ret void
}

; Function Attrs: alwaysinline nounwind
define %Range @-D-D-L_tII(%Int %a, %Int %b) #5 {
entry:
  %0 = extractvalue %Int %b, 0
  %1 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 1) #9
  %2 = extractvalue { i64, i1 } %1, 1
  br i1 %2, label %-.trap.i, label %-M_tII.exit

-.trap.i:                                         ; preds = %entry
  tail call void @llvm.trap() #9
  unreachable

-M_tII.exit:                                      ; preds = %entry
  %3 = extractvalue { i64, i1 } %1, 0
  %"$0.fca.0.extract.i" = extractvalue %Int %a, 0
  %.fca.0.0.insert.i = insertvalue %Range undef, i64 %"$0.fca.0.extract.i", 0, 0
  %.fca.1.0.insert.i = insertvalue %Range %.fca.0.0.insert.i, i64 %3, 1, 0
  ret %Range %.fca.1.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Double @-D_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fdiv double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

; Function Attrs: alwaysinline nounwind readnone
define %Bool @-Uexpect_tBB(%Bool %val, %Bool %assume) #4 {
entry:
  ret %Bool %val
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i32) #9

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #9

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #10

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #7

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #7

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #7

attributes #0 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { alwaysinline nounwind readnone }
attributes #5 = { alwaysinline nounwind }
attributes #6 = { alwaysinline noreturn nounwind }
attributes #7 = { nounwind readnone }
attributes #8 = { alwaysinline ssp }
attributes #9 = { nounwind }
attributes #10 = { noreturn nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
!1 = !{i32 1, !"PIC Level", i32 2}
!2 = !{!3, !3, i64 0}
!3 = !{!"any pointer", !4, i64 0}
!4 = !{!"omnipotent char", !5, i64 0}
!5 = !{!"Simple C/C++ TBAA"}
!6 = !{!7, !8, i64 12}
!7 = !{!"__sFILE", !3, i64 0, !8, i64 8, !8, i64 12, !9, i64 16, !9, i64 18, !10, i64 24, !8, i64 40, !3, i64 48, !3, i64 56, !3, i64 64, !3, i64 72, !3, i64 80, !10, i64 88, !3, i64 104, !8, i64 112, !4, i64 116, !4, i64 119, !10, i64 120, !8, i64 136, !11, i64 144}
!8 = !{!"int", !4, i64 0}
!9 = !{!"short", !4, i64 0}
!10 = !{!"__sbuf", !3, i64 0, !8, i64 8}
!11 = !{!"long long", !4, i64 0}
!12 = !{!7, !8, i64 40}
!13 = !{!7, !3, i64 0}
!14 = !{!4, !4, i64 0}
