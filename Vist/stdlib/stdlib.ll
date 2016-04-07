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
@.str = private unnamed_addr constant [17 x i8] c">alloc %i bytes\0A\00", align 1
@str = private unnamed_addr constant [9 x i8] c">dealloc\00"
@.str2 = private unnamed_addr constant [13 x i8] c">release %i\0A\00", align 1
@.str3 = private unnamed_addr constant [12 x i8] c">retain %i\0A\00", align 1
@.str4 = private unnamed_addr constant [21 x i8] c">release-unowned %i\0A\00", align 1
@.str5 = private unnamed_addr constant [21 x i8] c">dealloc-unowned %i\0A\00", align 1
@.str6 = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str7 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str8 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str9 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str10 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @_Z17incrementRefCountP16RefcountedObject(%struct.__sbuf* %object) #0 {
entry:
  %refCount = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 1
  %0 = atomicrmw add i32* %refCount, i32 1 monotonic
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @_Z17decrementRefCountP16RefcountedObject(%struct.__sbuf* %object) #0 {
entry:
  %refCount = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 1
  %0 = atomicrmw sub i32* %refCount, i32 1 monotonic
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define noalias %struct.__sbuf* @vist_allocObject(i32 %size) #0 {
entry:
  %conv = zext i32 %size to i64
  %call = tail call i8* @malloc(i64 %conv)
  %call1 = tail call i8* @malloc(i64 16)
  %0 = bitcast i8* %call1 to %struct.__sbuf*
  %object2 = bitcast i8* %call1 to i8**
  store i8* %call, i8** %object2, align 8, !tbaa !2
  %refCount = getelementptr inbounds i8* %call1, i64 8
  %1 = bitcast i8* %refCount to i32*
  store i32 0, i32* %1, align 4, !tbaa !8
  %call3 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @.str, i64 0, i64 0), i32 %size)
  ret %struct.__sbuf* %0
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_deallocObject(%struct.__sbuf* nocapture readonly %object) #0 {
entry:
  %puts = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0))
  %object1 = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 0
  %0 = load i8** %object1, align 8, !tbaa !2
  tail call void @free(i8* %0)
  ret void
}

; Function Attrs: nounwind
declare void @free(i8* nocapture) #1

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_releaseObject(%struct.__sbuf* %object) #0 {
entry:
  %refCount = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4, !tbaa !8
  %sub = add i32 %0, -1
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([13 x i8]* @.str2, i64 0, i64 0), i32 %sub)
  %1 = load i32* %refCount, align 4, !tbaa !8
  %cmp = icmp eq i32 %1, 1
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %puts.i = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0)) #7
  %object1.i = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 0
  %2 = load i8** %object1.i, align 8, !tbaa !2
  tail call void @free(i8* %2) #7
  br label %if.end

if.else:                                          ; preds = %entry
  %3 = atomicrmw sub i32* %refCount, i32 1 monotonic
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_retainObject(%struct.__sbuf* %object) #0 {
entry:
  %refCount.i = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 1
  %0 = atomicrmw add i32* %refCount.i, i32 1 monotonic
  %1 = load i32* %refCount.i, align 4, !tbaa !8
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([12 x i8]* @.str3, i64 0, i64 0), i32 %1)
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_releaseUnownedObject(%struct.__sbuf* %object) #0 {
entry:
  %refCount.i = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 1
  %0 = atomicrmw sub i32* %refCount.i, i32 1 monotonic
  %1 = load i32* %refCount.i, align 4, !tbaa !8
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @.str4, i64 0, i64 0), i32 %1)
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist_deallocUnownedObject(%struct.__sbuf* nocapture readonly %object) #0 {
entry:
  %refCount = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4, !tbaa !8
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([21 x i8]* @.str5, i64 0, i64 0), i32 %0)
  %1 = load i32* %refCount, align 4, !tbaa !8
  %cmp = icmp eq i32 %1, 0
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %puts.i = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0)) #7
  %object1.i = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 0
  %2 = load i8** %object1.i, align 8, !tbaa !2
  tail call void @free(i8* %2) #7
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  ret void
}

; Function Attrs: alwaysinline nounwind readonly ssp uwtable
define i32 @vist_getObjectRefcount(%struct.__sbuf* nocapture readonly %object) #2 {
entry:
  %refCount = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4, !tbaa !8
  ret i32 %0
}

; Function Attrs: alwaysinline nounwind readonly ssp uwtable
define zeroext i1 @vist_objectHasUniqueReference(%struct.__sbuf* nocapture readonly %object) #2 {
entry:
  %refCount = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 1
  %0 = load i32* %refCount, align 4, !tbaa !8
  %cmp = icmp eq i32 %0, 1
  ret i1 %cmp
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_ti64(i64 %i) #3 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str6, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_ti32(i32 %i) #3 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str7, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf64(double %d) #3 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str8, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf32(float %d) #3 {
entry:
  %conv = fpext float %d to double
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str8, i64 0, i64 0), double %conv)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tb(i1 zeroext %b) #3 {
entry:
  %cond = select i1 %b, i8* getelementptr inbounds ([6 x i8]* @.str9, i64 0, i64 0), i8* getelementptr inbounds ([7 x i8]* @.str10, i64 0, i64 0)
  %call = tail call i32 (i8*, ...)* @printf(i8* %cond)
  ret void
}

; Function Attrs: alwaysinline ssp uwtable
define void @vist-Ucshim-Uwrite_topi64(i8* %str, i64 %size) #4 {
entry:
  %0 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !9
  %call = tail call i64 @"\01_fwrite"(i8* %str, i64 %size, i64 1, %struct.__sFILE* %0)
  ret void
}

declare i64 @"\01_fwrite"(i8*, i64, i64, %struct.__sFILE*) #5

; Function Attrs: noinline ssp uwtable
define void @vist-Ucshim-Uputchar_ti8(i8 signext %c) #6 {
entry:
  %conv = sext i8 %c to i32
  %0 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !9
  %_w.i = getelementptr inbounds %struct.__sFILE* %0, i64 0, i32 2
  %1 = load i32* %_w.i, align 4, !tbaa !10
  %dec.i = add nsw i32 %1, -1
  store i32 %dec.i, i32* %_w.i, align 4, !tbaa !10
  %cmp.i = icmp sgt i32 %1, 0
  br i1 %cmp.i, label %if.then.i, label %lor.lhs.false.i

lor.lhs.false.i:                                  ; preds = %entry
  %_lbfsize.i = getelementptr inbounds %struct.__sFILE* %0, i64 0, i32 6
  %2 = load i32* %_lbfsize.i, align 4, !tbaa !15
  %cmp2.i = icmp sle i32 %1, %2
  %sext.mask.i = and i32 %conv, 255
  %cmp4.i = icmp eq i32 %sext.mask.i, 10
  %or.cond.i = or i1 %cmp4.i, %cmp2.i
  br i1 %or.cond.i, label %if.else.i, label %if.then.i

if.then.i:                                        ; preds = %lor.lhs.false.i, %entry
  %_p6.i = getelementptr inbounds %struct.__sFILE* %0, i64 0, i32 0
  %3 = load i8** %_p6.i, align 8, !tbaa !16
  %incdec.ptr.i = getelementptr inbounds i8* %3, i64 1
  store i8* %incdec.ptr.i, i8** %_p6.i, align 8, !tbaa !16
  store i8 %c, i8* %3, align 1, !tbaa !17
  br label %_Z7__sputciP7__sFILE.exit

if.else.i:                                        ; preds = %lor.lhs.false.i
  %call.i = tail call i32 @__swbuf(i32 %conv, %struct.__sFILE* %0)
  br label %_Z7__sputciP7__sFILE.exit

_Z7__sputciP7__sFILE.exit:                        ; preds = %if.else.i, %if.then.i
  ret void
}

declare i32 @__swbuf(i32, %struct.__sFILE*) #5

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #7

; Function Attrs: nounwind readnone
define %Double @Double_tD(%Double %val) #8 {
entry:
  ret %Double %val
}

; Function Attrs: nounwind readnone
define %Int @-T-O_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = or i64 %1, %0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Int @Int_ti64(i64 %"$0") #8 {
entry:
  %.fca.0.insert = insertvalue %Int undef, i64 %"$0", 0
  ret %Int %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Int @-D_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = sdiv i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Double @-P_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fadd double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

define %String @String_topi64b(i8* nocapture readonly %ptr, i64 %count, i1 %isUTF8Encoded) {
entry:
  %0 = trunc i64 %count to i32
  %1 = tail call i8* bitcast (i8* (i64)* @malloc to i8* (i32)*)(i32 %0)
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %1, i8* %ptr, i64 %count, i32 1, i1 false)
  %2 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %count, i64 1) #7
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %-.trap.i, label %-M_tII.exit

-.trap.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
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

; Function Attrs: nounwind readnone
define %Bool @-L-E_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sle i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Bool @-O-O_tBB(%Bool %a, %Bool %b) #8 {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = and i1 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Bool @-G_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ogt double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Double @Double_tf64(double %"$0") #8 {
entry:
  %.fca.0.insert = insertvalue %Double undef, double %"$0", 0
  ret %Double %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool @-G_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sgt i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind
define void @print_tI(%Int %a) #7 {
entry:
  %0 = extractvalue %Int %a, 0
  tail call void @vist-Uprint_ti64(i64 %0)
  ret void
}

; Function Attrs: nounwind readnone
define %Int @-C_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = srem i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Int @-T-N_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = and i64 %1, %0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Range @-D-D-D_tII(%Int %a, %Int %b) #8 {
entry:
  %"$0.fca.0.extract.i" = extractvalue %Int %a, 0
  %"$1.fca.0.extract.i" = extractvalue %Int %b, 0
  %.fca.0.0.insert.i = insertvalue %Range undef, i64 %"$0.fca.0.extract.i", 0, 0
  %.fca.1.0.insert.i = insertvalue %Range %.fca.0.0.insert.i, i64 %"$1.fca.0.extract.i", 1, 0
  ret %Range %.fca.1.0.insert.i
}

; Function Attrs: nounwind readnone
define %Bool @Bool_tB(%Bool %val) #8 {
entry:
  ret %Bool %val
}

; Function Attrs: noreturn nounwind
define void @fatalError_t() #9 {
entry:
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: nounwind readnone
define %Int32 @Int32_tI32(%Int32 %val) #8 {
entry:
  ret %Int32 %val
}

; Function Attrs: nounwind readnone
define %Int32 @Int32_ti32(i32 %"$0") #8 {
entry:
  %.fca.0.insert = insertvalue %Int32 undef, i32 %"$0", 0
  ret %Int32 %.fca.0.insert
}

; Function Attrs: nounwind readnone
define i8* @-P_topI(i8* readnone %pointer, %Int %offset) #8 {
entry:
  %0 = extractvalue %Int %offset, 0
  %1 = getelementptr i8* %pointer, i64 %0
  ret i8* %1
}

; Function Attrs: nounwind readnone
define %Bool @-L_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp olt double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Range @Range_tII(%Int %"$0", %Int %"$1") #8 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int %"$1", 0
  %.fca.0.0.insert = insertvalue %Range undef, i64 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue %Range %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret %Range %.fca.1.0.insert
}

; Function Attrs: nounwind readnone
define %Bool @-E-E_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp eq i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Bool @-G-E_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp oge double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind
define void @print_tI32(%Int32 %a) #7 {
entry:
  %0 = extractvalue %Int32 %a, 0
  tail call void @vist-Uprint_ti32(i32 %0)
  ret void
}

; Function Attrs: nounwind readnone
define %Double @-C_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = frem double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

; Function Attrs: nounwind
define %Int @-P_tII(%Int %a, %Int %b) #7 {
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

; Function Attrs: nounwind readnone
define %Int @-L-L_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = shl i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Bool @-G-E_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sge i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Int @-G-G_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = ashr i64 %0, %1
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readonly
define %Int @bufferCapacity_mString(%String* nocapture readonly %self) #10 {
entry:
  %0 = getelementptr inbounds %String* %self, i64 0, i32 2, i32 0
  %1 = load i64* %0, align 8
  %2 = ashr i64 %1, 1
  %.fca.0.insert.i.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i.i
}

; Function Attrs: nounwind readnone
define %Bool @-L-E_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ole double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Bool @Bool_tb(i1 %"$0") #8 {
entry:
  %.fca.0.insert = insertvalue %Bool undef, i1 %"$0", 0
  ret %Bool %.fca.0.insert
}

; Function Attrs: nounwind readnone
define %Bool @Bool_t() #8 {
entry:
  ret %Bool zeroinitializer
}

; Function Attrs: nounwind readnone
define %Bool @-E-E_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp oeq double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Bool @-L_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp slt i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %String @String_topII(i8* %"$0", %Int %"$1", %Int %"$2") #8 {
entry:
  %"$1.fca.0.extract" = extractvalue %Int %"$1", 0
  %"$2.fca.0.extract" = extractvalue %Int %"$2", 0
  %.fca.0.insert = insertvalue %String undef, i8* %"$0", 0
  %.fca.1.0.insert = insertvalue %String %.fca.0.insert, i64 %"$1.fca.0.extract", 1, 0
  %.fca.2.0.insert = insertvalue %String %.fca.1.0.insert, i64 %"$2.fca.0.extract", 2, 0
  ret %String %.fca.2.0.insert
}

; Function Attrs: ssp
define void @print_tString(%String %str) #11 {
entry:
  %str.fca.2.0.extract = extractvalue %String %str, 2, 0
  %0 = and i64 %str.fca.2.0.extract, 1
  %1 = icmp eq i64 %0, 0
  br i1 %1, label %else.1, label %if.0

if.0:                                             ; preds = %entry
  %str.fca.0.extract = extractvalue %String %str, 0
  %2 = extractvalue %String %str, 1
  %3 = extractvalue %Int %2, 0
  %4 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !9
  %call.i = tail call i64 @"\01_fwrite"(i8* %str.fca.0.extract, i64 %3, i64 1, %struct.__sFILE* %4)
  ret void

else.1:                                           ; preds = %entry
  %5 = alloca %String, align 8
  store %String %str, %String* %5, align 8
  %6 = getelementptr inbounds %String* %5, i64 0, i32 2, i32 0
  %7 = load i64* %6, align 8
  %8 = ashr i64 %7, 1
  %9 = add nsw i64 %8, -1
  br label %loop

loop:                                             ; preds = %loop, %else.1
  %loop.count = phi i64 [ 0, %else.1 ], [ %count.it, %loop ]
  %10 = alloca %String, align 8
  store %String %str, %String* %10, align 8
  %base.i = getelementptr inbounds %String* %10, i64 0, i32 0
  %11 = load i8** %base.i, align 8
  %12 = getelementptr i8* %11, i64 %loop.count
  %13 = load i8* %12, align 1
  tail call void @vist-Ucshim-Uputchar_ti8(i8 %13)
  %count.it = add nuw nsw i64 %loop.count, 1
  %14 = icmp slt i64 %loop.count, %9
  br i1 %14, label %loop, label %loop.exit

loop.exit:                                        ; preds = %loop
  ret void
}

; Function Attrs: nounwind readnone
define %Range @Range_tR(%Range %val) #8 {
entry:
  %0 = extractvalue %Range %val, 0
  %.fca.0.extract = extractvalue %Int %0, 0
  %1 = extractvalue %Range %val, 1
  %.fca.0.extract1 = extractvalue %Int %1, 0
  %.fca.0.0.insert = insertvalue %Range undef, i64 %.fca.0.extract, 0, 0
  %.fca.1.0.insert = insertvalue %Range %.fca.0.0.insert, i64 %.fca.0.extract1, 1, 0
  ret %Range %.fca.1.0.insert
}

; Function Attrs: nounwind readnone
define %Double @-M_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fadd double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

; Function Attrs: nounwind
define void @print_tD(%Double %a) #7 {
entry:
  %0 = extractvalue %Double %a, 0
  tail call void @vist-Uprint_tf64(double %0)
  ret void
}

; Function Attrs: nounwind readnone
define %Bool @-N-N_tBB(%Bool %a, %Bool %b) #8 {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = and i1 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Int @-T-R_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = xor i64 %1, %0
  %.fca.0.insert.i = insertvalue %Int undef, i64 %2, 0
  ret %Int %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Double @-A_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fmul double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Bool @-B-E_tII(%Int %a, %Int %b) #8 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp ne i64 %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readonly
define i8* @codeUnitAtIndex_mStringI(%String* nocapture readonly %self, %Int %index) #10 {
entry:
  %base = getelementptr inbounds %String* %self, i64 0, i32 0
  %0 = load i8** %base, align 8
  %1 = extractvalue %Int %index, 0
  %2 = getelementptr i8* %0, i64 %1
  ret i8* %2
}

; Function Attrs: nounwind readonly
define %Bool @isUTF8Encoded_mString(%String* nocapture readonly %self) #10 {
entry:
  %0 = getelementptr inbounds %String* %self, i64 0, i32 2, i32 0
  %1 = load i64* %0, align 8
  %2 = and i64 %1, 1
  %3 = icmp ne i64 %2, 0
  %.fca.0.insert.i.i1 = insertvalue %Bool undef, i1 %3, 0
  ret %Bool %.fca.0.insert.i.i1
}

; Function Attrs: nounwind
define %Int @-M_tII(%Int %a, %Int %b) #7 {
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

; Function Attrs: nounwind
define %Int @-A_tII(%Int %a, %Int %b) #7 {
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

; Function Attrs: nounwind readnone
define %Int @Int_t() #8 {
entry:
  ret %Int zeroinitializer
}

; Function Attrs: nounwind readnone
define %Bool @-B-E_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp one double %0, %1
  %.fca.0.insert.i = insertvalue %Bool undef, i1 %2, 0
  ret %Bool %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Int @Int_tI(%Int %val) #8 {
entry:
  ret %Int %val
}

; Function Attrs: nounwind
define void @print_tB(%Bool %a) #7 {
entry:
  %0 = extractvalue %Bool %a, 0
  tail call void @vist-Uprint_tb(i1 %0)
  ret void
}

; Function Attrs: nounwind
define %Range @-D-D-L_tII(%Int %a, %Int %b) #7 {
entry:
  %0 = extractvalue %Int %b, 0
  %1 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 1) #7
  %2 = extractvalue { i64, i1 } %1, 1
  br i1 %2, label %-.trap.i, label %-M_tII.exit

-.trap.i:                                         ; preds = %entry
  tail call void @llvm.trap() #7
  unreachable

-M_tII.exit:                                      ; preds = %entry
  %3 = extractvalue { i64, i1 } %1, 0
  %"$0.fca.0.extract.i" = extractvalue %Int %a, 0
  %.fca.0.0.insert.i = insertvalue %Range undef, i64 %"$0.fca.0.extract.i", 0, 0
  %.fca.1.0.insert.i = insertvalue %Range %.fca.0.0.insert.i, i64 %3, 1, 0
  ret %Range %.fca.1.0.insert.i
}

; Function Attrs: nounwind readnone
define %Double @-D_tDD(%Double %a, %Double %b) #8 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fdiv double %0, %1
  %.fca.0.insert.i = insertvalue %Double undef, double %2, 0
  ret %Double %.fca.0.insert.i
}

; Function Attrs: nounwind readnone
define %Bool @-Uexpect_tBB(%Bool %val, %Bool %assume) #8 {
entry:
  ret %Bool %val
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #7

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #9

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #8

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #8

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #8

attributes #0 = { alwaysinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline nounwind readonly ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { alwaysinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { nounwind }
attributes #8 = { nounwind readnone }
attributes #9 = { noreturn nounwind }
attributes #10 = { nounwind readonly }
attributes #11 = { ssp }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
!1 = !{i32 1, !"PIC Level", i32 2}
!2 = !{!3, !4, i64 0}
!3 = !{!"_ZTS16RefcountedObject", !4, i64 0, !7, i64 8}
!4 = !{!"any pointer", !5, i64 0}
!5 = !{!"omnipotent char", !6, i64 0}
!6 = !{!"Simple C/C++ TBAA"}
!7 = !{!"int", !5, i64 0}
!8 = !{!3, !7, i64 8}
!9 = !{!4, !4, i64 0}
!10 = !{!11, !7, i64 12}
!11 = !{!"_ZTS7__sFILE", !4, i64 0, !7, i64 8, !7, i64 12, !12, i64 16, !12, i64 18, !13, i64 24, !7, i64 40, !4, i64 48, !4, i64 56, !4, i64 64, !4, i64 72, !4, i64 80, !13, i64 88, !4, i64 104, !7, i64 112, !5, i64 116, !5, i64 119, !13, i64 120, !7, i64 136, !14, i64 144}
!12 = !{!"short", !5, i64 0}
!13 = !{!"_ZTS6__sbuf", !4, i64 0, !7, i64 8}
!14 = !{!"long long", !5, i64 0}
!15 = !{!11, !7, i64 40}
!16 = !{!11, !4, i64 0}
!17 = !{!5, !5, i64 0}
