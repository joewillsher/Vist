; ModuleID = 'stdlib'
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
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i) #6
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_ti32(i32 %i) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), i32 %i) #6
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf64(double %d) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d) #6
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tf32(float %d) #0 {
entry:
  %conv = fpext float %d to double
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %conv) #6
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @vist-Uprint_tb(i1 zeroext %b) #0 {
entry:
  %cond = select i1 %b, i8* getelementptr inbounds ([6 x i8]* @.str3, i64 0, i64 0), i8* getelementptr inbounds ([7 x i8]* @.str4, i64 0, i64 0)
  %call = tail call i32 (i8*, ...)* @printf(i8* %cond) #6
  ret void
}

; Function Attrs: alwaysinline nounwind ssp uwtable
define void @vist-Ucshim-Uwrite_topi64(i8* %str, i64 %size) #2 {
entry:
  %0 = load %struct.__sFILE** @__stdoutp, align 8, !tbaa !2
  %call = tail call i64 @"\01_fwrite"(i8* %str, i64 %size, i64 1, %struct.__sFILE* %0) #6
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
  %call.i = tail call i32 @__swbuf(i32 %conv, %struct.__sFILE* %0) #6
  br label %__sputc.exit

__sputc.exit:                                     ; preds = %if.else.i, %if.then.i
  ret void
}

declare i32 @__swbuf(i32, %struct.__sFILE*) #3

; Function Attrs: alwaysinline
define %Double @Double_tD(%Double %val) #4 {
entry:
  %self = alloca %Double
  %value = getelementptr inbounds %Double* %self, i32 0, i32 0
  %0 = extractvalue %Double %val, 0
  store double %0, double* %value
  %1 = load %Double* %self
  ret %Double %1
}

; Function Attrs: alwaysinline
define %Int @-T-O_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = or i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Int @Int_ti64(i64 %"$0") #4 {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  store i64 %"$0", i64* %value
  %0 = load %Int* %self
  ret %Int %0
}

; Function Attrs: alwaysinline
define %Int @-D_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = sdiv i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Double @-P_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fadd double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define %String @String_topi64b(i8* %ptr, i64 %count, i1 %isUTF8Encoded) #4 {
entry:
  %self = alloca %String
  %base = getelementptr inbounds %String* %self, i32 0, i32 0
  %length = getelementptr inbounds %String* %self, i32 0, i32 1
  %_capacityAndEncoding = getelementptr inbounds %String* %self, i32 0, i32 2
  %0 = trunc i64 %count to i32
  %mallocsize = mul i32 %0, ptrtoint (i8* getelementptr (i8* null, i32 1) to i32)
  %1 = tail call i8* @malloc(i32 %mallocsize)
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
define %Bool @-L-E_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sle i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-O-O_tBB(%Bool %a, %Bool %b) #4 {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = or i1 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-G_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ogt double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Double @Double_tf64(double %"$0") #4 {
entry:
  %self = alloca %Double
  %value = getelementptr inbounds %Double* %self, i32 0, i32 0
  store double %"$0", double* %value
  %0 = load %Double* %self
  ret %Double %0
}

; Function Attrs: alwaysinline
define %Bool @-G_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sgt i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define void @print_tI(%Int %a) #4 {
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
define %Int @-C_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = srem i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Int @-T-N_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = and i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Range @-D-D-D_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = call %Range @Range_tII(%Int %a, %Int %b)
  ret %Range %0
}

; Function Attrs: alwaysinline
define %Bool @Bool_tB(%Bool %val) #4 {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  %0 = extractvalue %Bool %val, 0
  store i1 %0, i1* %value
  %1 = load %Bool* %self
  ret %Bool %1
}

; Function Attrs: alwaysinline noreturn
define void @fatalError_t() #5 {
entry:
  call void @llvm.trap()
  ret void
}

; Function Attrs: alwaysinline
define %Int32 @Int32_tI32(%Int32 %val) #4 {
entry:
  %self = alloca %Int32
  %value = getelementptr inbounds %Int32* %self, i32 0, i32 0
  %0 = extractvalue %Int32 %val, 0
  store i32 %0, i32* %value
  %1 = load %Int32* %self
  ret %Int32 %1
}

; Function Attrs: alwaysinline
define %Int32 @Int32_ti32(i32 %"$0") #4 {
entry:
  %self = alloca %Int32
  %value = getelementptr inbounds %Int32* %self, i32 0, i32 0
  store i32 %"$0", i32* %value
  %0 = load %Int32* %self
  ret %Int32 %0
}

; Function Attrs: alwaysinline
define i8* @-P_topI(i8* %pointer, %Int %offset) #4 {
entry:
  %0 = extractvalue %Int %offset, 0
  %1 = getelementptr i8* %pointer, i64 %0
  ret i8* %1
}

; Function Attrs: alwaysinline
define %Bool @-L_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp olt double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-E-E_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp eq i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-G-E_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ole double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Range @Range_tII(%Int %"$0", %Int %"$1") #4 {
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
define void @print_tString.loop_thunk(i8 %c) #4 {
entry:
  call void @vist-Ucshim-Uputchar_ti8(i8 %c)
  ret void
}

; Function Attrs: alwaysinline
define void @print_tI32(%Int32 %a) #4 {
entry:
  %0 = extractvalue %Int32 %a, 0
  call void @vist-Uprint_ti32(i32 %0)
  ret void
}

; Function Attrs: alwaysinline
define %Double @-C_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = frem double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define %Int @-P_tII(%Int %a, %Int %b) #4 {
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
define %Int @-L-L_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = shl i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

; Function Attrs: alwaysinline
define %Bool @-G-E_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp sge i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Int @-G-G_tII(%Int %a, %Int %b) #4 {
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
define %Bool @-L-E_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp ole double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @Bool_tb(i1 %"$0") #4 {
entry:
  %self = alloca %Bool
  %value = getelementptr inbounds %Bool* %self, i32 0, i32 0
  store i1 %"$0", i1* %value
  %0 = load %Bool* %self
  ret %Bool %0
}

; Function Attrs: alwaysinline
define %Bool @Bool_t() #4 {
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
define %Bool @-E-E_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp oeq double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Bool @-L_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = icmp slt i64 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %String @String_topII(i8* %"$0", %Int %"$1", %Int %"$2") #4 {
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
define void @print_tString(%String %str) #4 {
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
  call void @generate_mStringPti8(%String %str, void (i8)* @print_tString.loop_thunk)
  ret void
}

; Function Attrs: alwaysinline
define %Range @Range_tR(%Range %val) #4 {
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
define %Double @-M_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fsub double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define void @print_tD(%Double %a) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  call void @vist-Uprint_tf64(double %0)
  ret void
}

; Function Attrs: alwaysinline
define %Bool @-N-N_tBB(%Bool %a, %Bool %b) #4 {
entry:
  %0 = extractvalue %Bool %a, 0
  %1 = extractvalue %Bool %b, 0
  %2 = and i1 %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Int @-T-R_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = extractvalue %Int %a, 0
  %1 = extractvalue %Int %b, 0
  %2 = xor i64 %0, %1
  %3 = call %Int @Int_ti64(i64 %2)
  ret %Int %3
}

define void @generate_mStringPti8(%String %self, void (i8)* %loop_thunk) {
entry:
  %0 = alloca %Int
  store %Int zeroinitializer, %Int* %0
  br label %cond

cond:                                             ; preds = %loop, %entry
  %1 = load %Int* %0
  %2 = call %Int @bufferCapacity_mString(%String %self)
  %3 = call %Bool @-L_tII(%Int %1, %Int %2)
  %cond1 = extractvalue %Bool %3, 0
  br i1 %cond1, label %loop, label %loop.exit

loop:                                             ; preds = %cond
  %4 = load %Int* %0
  %5 = call i8* @codeUnitAtIndex_mStringI(%String %self, %Int %4)
  %6 = load i8* %5
  call void %loop_thunk(i8 %6)
  %7 = load %Int* %0
  %8 = call %Int @-P_tII(%Int %7, %Int { i64 1 })
  store %Int %8, %Int* %0
  br label %cond

loop.exit:                                        ; preds = %cond
  ret void
}

; Function Attrs: alwaysinline
define %Double @-A_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fmul double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define %Bool @-B-E_tII(%Int %a, %Int %b) #4 {
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
define %Int @-M_tII(%Int %a, %Int %b) #4 {
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
define %Int @-A_tII(%Int %a, %Int %b) #4 {
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
define %Int @Int_t() #4 {
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
define %Bool @-B-E_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fcmp one double %0, %1
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

; Function Attrs: alwaysinline
define %Int @Int_tI(%Int %val) #4 {
entry:
  %self = alloca %Int
  %value = getelementptr inbounds %Int* %self, i32 0, i32 0
  %0 = extractvalue %Int %val, 0
  store i64 %0, i64* %value
  %1 = load %Int* %self
  ret %Int %1
}

; Function Attrs: alwaysinline
define void @print_tB(%Bool %a) #4 {
entry:
  %0 = extractvalue %Bool %a, 0
  call void @vist-Uprint_tb(i1 %0)
  ret void
}

; Function Attrs: alwaysinline
define %Range @-D-D-L_tII(%Int %a, %Int %b) #4 {
entry:
  %0 = call %Int @-M_tII(%Int %b, %Int { i64 1 })
  %1 = call %Range @Range_tII(%Int %a, %Int %0)
  ret %Range %1
}

; Function Attrs: alwaysinline
define %Double @-D_tDD(%Double %a, %Double %b) #4 {
entry:
  %0 = extractvalue %Double %a, 0
  %1 = extractvalue %Double %b, 0
  %2 = fdiv double %0, %1
  %3 = call %Double @Double_tf64(double %2)
  ret %Double %3
}

; Function Attrs: alwaysinline
define %Bool @-Uexpect_tBB(%Bool %val, %Bool %assume) #4 {
entry:
  %0 = extractvalue %Bool %val, 0
  %1 = extractvalue %Bool %assume, 0
  %2 = call i1 @llvm.expect.i1(i1 %0, i1 %1)
  %3 = call %Bool @Bool_tb(i1 %2)
  ret %Bool %3
}

declare noalias i8* @malloc(i32)

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #6

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #7

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #8

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #8

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #8

; Function Attrs: nounwind readnone
declare i1 @llvm.expect.i1(i1, i1) #8

attributes #0 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { alwaysinline }
attributes #5 = { alwaysinline noreturn }
attributes #6 = { nounwind }
attributes #7 = { noreturn nounwind }
attributes #8 = { nounwind readnone }

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
