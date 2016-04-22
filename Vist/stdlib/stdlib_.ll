; ModuleID = 'stdlib'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%struct.__sFILE = type { i8*, i32, i32, i16, i16, %struct.__sbuf, i32, i8*, i32 (i8*)*, i32 (i8*, i8*, i32)*, i64 (i8*, i64, i32)*, i32 (i8*, i8*, i32)*, %struct.__sbuf, %struct.__sFILEX*, i32, [3 x i8], [1 x i8], %struct.__sbuf, i32, i64 }
%struct.__sFILEX = type opaque
%struct.__sbuf = type { i8*, i32 }
%String = type { i8*, %Int, %Int }
%Int = type { i64 }
%Double = type { double }
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
@_ZL11yieldTarget = internal global [37 x i32] zeroinitializer, align 16
@.str6 = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str7 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str8 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str9 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str10 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1
@str.globl = unnamed_addr global %String zeroinitializer

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
  %puts.i = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0)) #10
  %object1.i = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 0
  %2 = load i8** %object1.i, align 8, !tbaa !2
  tail call void @free(i8* %2) #10
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
  %puts.i = tail call i32 @puts(i8* getelementptr inbounds ([9 x i8]* @str, i64 0, i64 0)) #10
  %object1.i = getelementptr inbounds %struct.__sbuf* %object, i64 0, i32 0
  %2 = load i8** %object1.i, align 8, !tbaa !2
  tail call void @free(i8* %2) #10
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

; Function Attrs: alwaysinline noreturn ssp uwtable
define void @vist_yieldUnwind() #3 {
entry:
  tail call void @longjmp(i32* getelementptr inbounds ([37 x i32]* @_ZL11yieldTarget, i64 0, i64 0), i32 1) #15
  unreachable
}

; Function Attrs: noreturn
declare void @longjmp(i32*, i32) #4

; Function Attrs: alwaysinline ssp uwtable
define zeroext i1 @vist_setYieldTarget() #5 {
entry:
  %call = call i32 @setjmp(i32* getelementptr inbounds ([37 x i32]* @_ZL11yieldTarget, i64 0, i64 0)) #16
  %tobool = icmp ne i32 %call, 0
  ret i1 %tobool
}

; Function Attrs: returns_twice
declare i32 @setjmp(i32*) #6

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_ti64(i64 %i) #7 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str6, i64 0, i64 0), i64 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_ti32(i32 %i) #7 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str7, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf64(double %d) #7 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str8, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf32(float %d) #7 {
entry:
  %conv = fpext float %d to double
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str8, i64 0, i64 0), double %conv)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tb(i1 zeroext %b) #7 {
entry:
  %cond = select i1 %b, i8* getelementptr inbounds ([6 x i8]* @.str9, i64 0, i64 0), i8* getelementptr inbounds ([7 x i8]* @.str10, i64 0, i64 0)
  %call = tail call i32 (i8*, ...)* @printf(i8* %cond)
  ret void
}

; Function Attrs: alwaysinline ssp uwtable
define void @vist-Ucshim-Uwrite_topi64(i8* %str, i64 %size) #5 {
entry:
  %0 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !9
  %call = tail call i64 @"\01_fwrite"(i8* %str, i64 %size, i64 1, %struct.__sFILE* %0)
  ret void
}

declare i64 @"\01_fwrite"(i8*, i64, i64, %struct.__sFILE*) #8

; Function Attrs: noinline ssp uwtable
define void @vist-Ucshim-Uputchar_ti8(i8 signext %c) #9 {
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

declare i32 @__swbuf(i32, %struct.__sFILE*) #8

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #10

; Function Attrs: alwaysinline
define %Double @Double_tD(%Double %val) #11 {
entry:
  %self = alloca %Double
  %value = getelementptr inbounds %Double* %self, i32 0, i32 0
  %0 = extractvalue %Double %val, 0
  store double %0, double* %value
  %1 = load %Double* %self
  ret %Double %1
}

; Function Attrs: alwaysinline
define %Int @-T-O_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = or i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Int @Int_ti64(i64 %"$0") #11 {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  store i64 %"$0", i64* %value
  %0 = load %Int* %self
  ret %Int %0
}

; Function Attrs: alwaysinline
define %Int @-D_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = sdiv i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Double @-P_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fadd double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define %String @String_topi64b(i8* %ptr, i64 %count, i1 %isUTF8Encoded) #11 {
entry:
  %self = alloca %String
  %base = getelementptr inbounds %String* %self, i32 0, i32 0
  %length = getelementptr inbounds %String* %self, i32 0, i32 1
  %_capacityAndEncoding = getelementptr inbounds %String* %self, i32 0, i32 2
  %0 = trunc i64 %count to i32
  %mallocsize = mul i32 %0, ptrtoint (i8* getelementptr (i8* null, i32 1) to i32)
  %1 = tail call i8* bitcast (i8* (i64)* @malloc to i8* (i32)*)(i32 %mallocsize)
  store i8* %1, i8** %base
  %2 = load i8** %base
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %2, i8* %ptr, i64 %count, i32 1, i1 false)
  %3 = call %Int @Int_ti64(i64 %count)
  %c = alloca %Int
  store %Int %3, %Int* %c
  %4 = call %Int @-M_tII(%Int %3, %Int { i64 1 })
  store %Int %4, %Int* %length
  %5 = call %Int @-L-L_tII(%Int %3, %Int { i64 1 })
  store %Int %5, %Int* %_capacityAndEncoding
  %6 = call %Bool @Bool_tb(i1 %isUTF8Encoded)
  %7 = extractvalue %Bool %6, 0
  br i1 %7, label %if.0, label %exit

if.0:                                             ; preds = %entry
  %8 = load %Int* %_capacityAndEncoding
  %9 = call %Int @-T-O_tII(%Int %8, %Int { i64 1 })
  store %Int %9, %Int* %_capacityAndEncoding
  br label %exit

exit:                                             ; preds = %if.0, %entry
  %10 = load %String* %self
  ret %String %10
}

; Function Attrs: alwaysinline
define %Bool @-L-E_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sle i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-O-O_tBB(%Bool %a, %Bool %b) #11 {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = and i1 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-G_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ogt double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Double @Double_tf64(double %"$0") #11 {
entry:
  %self = alloca %Double
  %value = getelementptr inbounds %Double* %self, i32 0, i32 0
  store double %"$0", double* %value
  %0 = load %Double* %self
  ret %Double %0
}

; Function Attrs: alwaysinline
define %Bool @-G_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sgt i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define void @print_tI(%Int %a) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  call void @vist-Uprint_ti64(i64 %0)
  ret void
}

define void @generate_mRPtI(%Range %self, void (%Int)* %loop_thunk) {
entry:
  %start = extractvalue %Range %self, 0
  %0 = alloca %Int
  store %Int %start, %Int* %0
  br label %cond

cond:                                             ; preds = %loop, %entry
  %1 = load %Int* %0
  %end = extractvalue %Range %self, 1
  %2 = call %Bool @-L_tII(%Int %1, %Int %end)
  %cond1 = extractvalue %Bool %2, 0
  br i1 %cond1, label %loop, label %loop.exit

loop:                                             ; preds = %cond
  %3 = load %Int* %0
  call void %loop_thunk(%Int %3)
  %4 = load %Int* %0
  %5 = call %Int @-P_tII(%Int %4, %Int { i64 1 })
  store %Int %5, %Int* %0
  br label %cond

loop.exit:                                        ; preds = %cond
  ret void
}

; Function Attrs: alwaysinline
define %Int @-C_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = srem i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Int @-T-N_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = and i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Range @-D-D-D_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = call %Range @Range_tII(%Int %a, %Int %b)
  ret %Range %0
}

; Function Attrs: alwaysinline
define %Bool @Bool_tB(%Bool %val) #11 {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  %0 = extractvalue %Bool %val, 0
  store i1 %0, i1* %value
  %1 = load %Bool* %self
  ret %Bool %1
}

; Function Attrs: alwaysinline noreturn
define void @fatalError_t() #12 {
entry:
  call void @llvm.trap()
  ret void
}

; Function Attrs: alwaysinline
define %Int32 @Int32_tI32(%Int32 %val) #11 {
entry:
  %self = alloca %Int32
  %value = getelementptr inbounds %Int32* %self, i32 0, i32 0
  %0 = extractvalue %Int32 %val, 0
  store i32 %0, i32* %value
  %1 = load %Int32* %self
  ret %Int32 %1
}

; Function Attrs: alwaysinline
define %Int32 @Int32_ti32(i32 %"$0") #11 {
entry:
  %self = alloca %Int32
  %value = getelementptr inbounds %Int32* %self, i32 0, i32 0
  store i32 %"$0", i32* %value
  %0 = load %Int32* %self
  ret %Int32 %0
}

; Function Attrs: alwaysinline
define i8* @-P_topI(i8* %pointer, %Int %offset) #11 {
entry:
  %0 = extractvalue %Int %offset, 0
  %1 = getelementptr i8* %pointer, i64 %0
  ret i8* %1
}

; Function Attrs: alwaysinline
define %Bool @-L_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp olt double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-E-E_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp eq i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-G-E_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp oge double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Range @Range_tII(%Int %"$0", %Int %"$1") #11 {
entry:
  %self = alloca %Range
  %start = getelementptr inbounds %Range* %self, i32 0, i32 0
  %end = getelementptr inbounds %Range* %self, i32 0, i32 1
  store %Int %"$0", %Int* %start
  store %Int %"$1", %Int* %end
  %0 = load %Range* %self
  ret %Range %0
}

; Function Attrs: alwaysinline
define void @print_tString.loop_thunk(%Int %i) #11 {
entry:
  %0 = load %String* @str.globl
  %1 = call i8* @codeUnitAtIndex_mStringI(%String %0, %Int %i)
  %2 = load i8* %1
  call void @vist-Ucshim-Uputchar_ti8(i8 %2)
  ret void
}

; Function Attrs: alwaysinline
define void @print_tI32(%Int32 %a) #11 {
entry:
  %0 = extractvalue %Int32 %a, 0
  call void @vist-Uprint_ti32(i32 %0)
  ret void
}

; Function Attrs: alwaysinline
define %Double @-C_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = frem double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define %Int @-P_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"+.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int @Int_ti64(i64 %4)
  ret %Int %5

"+.trap":                                         ; preds = %entry
  call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline
define %Int @-L-L_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = shl i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Bool @-G-E_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sge i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Int @-G-G_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = ashr i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define %Int @bufferCapacity_mString(%String %self) {
entry:
  %_capacityAndEncoding = extractvalue %String %self, 2
  %0 = call %Int @-G-G_tII(%Int %_capacityAndEncoding, %Int { i64 1 })
  ret %Int %0
}

; Function Attrs: alwaysinline
define %Bool @-L-E_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ole double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @Bool_tb(i1 %"$0") #11 {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  store i1 %"$0", i1* %value
  %0 = load %Bool* %self
  ret %Bool %0
}

; Function Attrs: alwaysinline
define %Bool @Bool_t() #11 {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  %b = alloca %Bool
  store %Bool zeroinitializer, %Bool* %b
  store i1 false, i1* %value
  %0 = load %Bool* %self
  ret %Bool %0
}

; Function Attrs: alwaysinline
define %Bool @-E-E_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp oeq double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-L_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp slt i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %String @String_topII(i8* %"$0", %Int %"$1", %Int %"$2") #11 {
entry:
  %self = alloca %String
  %base = getelementptr inbounds %String* %self, i32 0, i32 0
  %length = getelementptr inbounds %String* %self, i32 0, i32 1
  %_capacityAndEncoding = getelementptr inbounds %String* %self, i32 0, i32 2
  store i8* %"$0", i8** %base
  store %Int %"$1", %Int* %length
  store %Int %"$2", %Int* %_capacityAndEncoding
  %0 = load %String* %self
  ret %String %0
}

; Function Attrs: alwaysinline
define void @print_tString(%String %str) #11 {
entry:
  %0 = call %Bool @isUTF8Encoded_mString(%String %str)
  %1 = extractvalue %Bool %0, 0
  br i1 %1, label %if.0, label %fail.0

if.0:                                             ; preds = %entry
  %2 = extractvalue %String %str, 0
  %3 = extractvalue %String %str, 1
  %4 = extractvalue %Int %3, 0
  call void @vist-Ucshim-Uwrite_topi64(i8* %2, i64 %4)
  ret void

fail.0:                                           ; preds = %entry
  br label %else.1

else.1:                                           ; preds = %fail.0
  store %String %str, %String* @str.globl
  %5 = call %Int @bufferCapacity_mString(%String %str)
  %6 = call %Range @-D-D-L_tII(%Int zeroinitializer, %Int %5)
  call void @generate_mRPtI(%Range %6, void (%Int)* @print_tString.loop_thunk)
  ret void
}

; Function Attrs: alwaysinline
define %Range @Range_tR(%Range %val) #11 {
entry:
  %self = alloca %Range
  %start = getelementptr inbounds %Range* %self, i32 0, i32 0
  %end = getelementptr inbounds %Range* %self, i32 0, i32 1
  %0 = extractvalue %Range %val, 0
  store %Int %0, %Int* %start
  %1 = extractvalue %Range %val, 1
  store %Int %1, %Int* %end
  %2 = load %Range* %self
  ret %Range %2
}

; Function Attrs: alwaysinline
define %Double @-M_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fadd double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define void @print_tD(%Double %a) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  call void @vist-Uprint_tf64(double %0)
  ret void
}

; Function Attrs: alwaysinline
define %Bool @-N-N_tBB(%Bool %a, %Bool %b) #11 {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = and i1 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Int @-T-R_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = xor i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Double @-A_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fmul double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define %Bool @-B-E_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp ne i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

define i8* @codeUnitAtIndex_mStringI(%String %self, %Int %index) {
entry:
  %base = extractvalue %String %self, 0
  %0 = call i8* @-P_topI(i8* %base, %Int %index)
  ret i8* %0
}

define %Bool @isUTF8Encoded_mString(%String %self) {
entry:
  %_capacityAndEncoding = extractvalue %String %self, 2
  %0 = call %Int @-T-N_tII(%Int %_capacityAndEncoding, %Int { i64 1 })
  %1 = call %Bool @-E-E_tII(%Int %0, %Int { i64 1 })
  ret %Bool %1
}

; Function Attrs: alwaysinline
define %Int @-M_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %-.trap, label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int @Int_ti64(i64 %4)
  ret %Int %5

-.trap:                                           ; preds = %entry
  call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline
define %Int @-A_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"*.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int @Int_ti64(i64 %4)
  ret %Int %5

"*.trap":                                         ; preds = %entry
  call void @llvm.trap()
  unreachable
}

; Function Attrs: alwaysinline
define %Int @Int_t() #11 {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  %v = alloca %Int
  store %Int zeroinitializer, %Int* %v
  store i64 0, i64* %value
  %0 = load %Int* %self
  ret %Int %0
}

; Function Attrs: alwaysinline
define %Bool @-B-E_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp one double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Int @Int_tI(%Int %val) #11 {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  %0 = extractvalue %Int %val, 0
  store i64 %0, i64* %value
  %1 = load %Int* %self
  ret %Int %1
}

; Function Attrs: alwaysinline
define void @print_tB(%Bool %a) #11 {
entry:
  %0 = extractvalue %Bool %a, 0
  call void @vist-Uprint_tb(i1 %0)
  ret void
}

; Function Attrs: alwaysinline
define %Range @-D-D-L_tII(%Int %a, %Int %b) #11 {
entry:
  %0 = call %Int @-M_tII(%Int %b, %Int { i64 1 })
  %1 = call %Range @Range_tII(%Int %a, %Int %0)
  ret %Range %1
}

; Function Attrs: alwaysinline
define %Double @-D_tDD(%Double %a, %Double %b) #11 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fdiv double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define %Bool @-Uexpect_tBB(%Bool %val, %Bool %assume) #11 {
entry:
  %0 = extractvalue %Bool %val, 0
  %1 = extractvalue %Bool %assume, 0
  %2 = call i1 @llvm.expect.i1(i1 %0, i1 %1)
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #10

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #13

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #14

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #14

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #14

; Function Attrs: nounwind readnone
declare i1 @llvm.expect.i1(i1, i1) #14

attributes #0 = { alwaysinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline nounwind readonly ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { alwaysinline noreturn ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noreturn "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { alwaysinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { returns_twice "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #8 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #9 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #10 = { nounwind }
attributes #11 = { alwaysinline }
attributes #12 = { alwaysinline noreturn }
attributes #13 = { noreturn nounwind }
attributes #14 = { nounwind readnone }
attributes #15 = { noreturn }
attributes #16 = { returns_twice }

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
