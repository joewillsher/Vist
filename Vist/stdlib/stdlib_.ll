; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Range.st = type { %Int.st, %Int.st }
%Int.st = type { i64 }
%Bool.st = type { i1 }
%Double.st = type { double }
%Int32.st = type { i32 }

@.str = private unnamed_addr constant [6 x i8] c"%lli\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_i64(i64 %i) #0 {
entry:
  %i.addr = alloca i64, align 8
  store i64 %i, i64* %i.addr, align 8
  %0 = load i64* %i.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %0)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_i32(i32 %i) #0 {
entry:
  %i.addr = alloca i32, align 4
  store i32 %i, i32* %i.addr, align 4
  %0 = load i32* %i.addr, align 4
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %0)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_f64(double %d) #0 {
entry:
  %d.addr = alloca double, align 8
  store double %d, double* %d.addr, align 8
  %0 = load double* %d.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %0)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_f32(float %d) #0 {
entry:
  %d.addr = alloca float, align 4
  store float %d, float* %d.addr, align 4
  %0 = load float* %d.addr, align 4
  %conv = fpext float %0 to double
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %conv)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @vist-Uprint_b(i1 zeroext %b) #0 {
entry:
  %b.addr = alloca i8, align 1
  %frombool = zext i1 %b to i8
  store i8 %frombool, i8* %b.addr, align 1
  %0 = load i8* %b.addr, align 1
  %tobool = trunc i8 %0 to i1
  %cond = select i1 %tobool, i8* getelementptr inbounds ([6 x i8]* @.str3, i32 0, i32 0), i8* getelementptr inbounds ([7 x i8]* @.str4, i32 0, i32 0)
  %call = call i32 (i8*, ...)* @printf(i8* %cond)
  ret void
}

define %Range.st @..-L_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = call %Int.st @-M_Int_Int(%Int.st %b, %Int.st { i64 1 })
  %1 = call %Range.st @Range_Int_Int(%Int.st %a, %Int.st %0)
  ret %Range.st %1
}

define %Bool.st @-L-E_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp sle i64 %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Int.st @-P_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"+.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int.st @Int_i64(i64 %4)
  ret %Int.st %5

"+.trap":                                         ; preds = %entry
  call void @llvm.trap()
  unreachable
}

define %Int.st @-T-N_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = and i64 %0, %1
  %3 = call %Int.st @Int_i64(i64 %2)
  ret %Int.st %3
}

define %Bool.st @-G-E_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp sge i64 %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Int.st @-A_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %"*.trap", label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int.st @Int_i64(i64 %4)
  ret %Int.st %5

"*.trap":                                         ; preds = %entry
  call void @llvm.trap()
  unreachable
}

define %Bool.st @-L_Double_Double(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp olt double %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Bool.st @-G_Double_Double(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp ogt double %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Bool.st @"!-E_Double_Double"(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp one double %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Int.st @-L-L_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = shl i64 %0, %1
  %3 = call %Int.st @Int_i64(i64 %2)
  ret %Int.st %3
}

declare void @vist-Uprint_f641(double)

define %Bool.st @-G_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp sgt i64 %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Bool.st @-L_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp slt i64 %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Double.st @-D_Double_Double(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fdiv double %0, %1
  %3 = call %Double.st @Double_f64(double %2)
  ret %Double.st %3
}

define %Int.st @-M_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 %1)
  %v = alloca { i64, i1 }
  store { i64, i1 } %2, { i64, i1 }* %v
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %-.trap, label %entry.cont

entry.cont:                                       ; preds = %entry
  %4 = extractvalue { i64, i1 } %2, 0
  %5 = call %Int.st @Int_i64(i64 %4)
  ret %Int.st %5

-.trap:                                           ; preds = %entry
  call void @llvm.trap()
  unreachable
}

define %Int.st @"%_Int_Int"(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = srem i64 %0, %1
  %3 = call %Int.st @Int_i64(i64 %2)
  ret %Int.st %3
}

declare void @vist-Uprint_b2(i1)

define %Bool.st @-E-E_Double_Double(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp oeq double %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define void @print_Double(%Double.st %a) {
entry:
  %0 = extractvalue %Double.st %a, 0
  call void @vist-Uprint_f64(double %0)
  ret void
}

define %Double.st @-M_Double_Double(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fadd double %0, %1
  %3 = call %Double.st @Double_f64(double %2)
  ret %Double.st %3
}

define void @assert_Bool(%Bool.st %"$0") {
entry:
  %0 = call %Bool.st @-Uexpect_Bool_Bool(%Bool.st %"$0", %Bool.st { i1 true })
  %1 = extractvalue %Bool.st %0, 0
  br i1 %1, label %if.0, label %fail.0

if.0:                                             ; preds = %entry
  br label %exit

fail.0:                                           ; preds = %entry
  br label %else.1

else.1:                                           ; preds = %fail.0
  br label %exit

exit:                                             ; preds = %else.1, %if.0
  ret void
}

define %Bool.st @-Uexpect_Bool_Bool(%Bool.st %val, %Bool.st %assume) {
entry:
  %0 = extractvalue %Bool.st %val, 0
  %1 = extractvalue %Bool.st %assume, 0
  %2 = call i1 @llvm.expect.i1(i1 %0, i1 %1)
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

declare void @vist-Uprint_i323(i32)

define %Bool.st @Bool_() {
entry:
  %self = alloca %Bool.st
  %value = getelementptr inbounds %Bool.st* %self, i32 0, i32 0
  %b = alloca %Bool.st
  store %Bool.st zeroinitializer, %Bool.st* %b
  store i1 false, i1* %value
  %0 = load %Bool.st* %self
  ret %Bool.st %0
}

define void @print_Bool(%Bool.st %a) {
entry:
  %0 = extractvalue %Bool.st %a, 0
  call void @vist-Uprint_b(i1 %0)
  ret void
}

define %Int.st @-T-R_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = xor i64 %0, %1
  %3 = call %Int.st @Int_i64(i64 %2)
  ret %Int.st %3
}

define %Int.st @-T-O_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = or i64 %0, %1
  %3 = call %Int.st @Int_i64(i64 %2)
  ret %Int.st %3
}

define %Bool.st @Bool_b(i1 %"$0") {
entry:
  %self = alloca %Bool.st
  %value = getelementptr inbounds %Bool.st* %self, i32 0, i32 0
  store i1 %"$0", i1* %value
  %0 = load %Bool.st* %self
  ret %Bool.st %0
}

define %Bool.st @-G-E_Double_Double(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp oge double %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Double.st @-A_Double_Double(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fmul double %0, %1
  %3 = call %Double.st @Double_f64(double %2)
  ret %Double.st %3
}

define %Int.st @Int_i64(i64 %"$0") {
entry:
  %self = alloca %Int.st
  %value = getelementptr inbounds %Int.st* %self, i32 0, i32 0
  store i64 %"$0", i64* %value
  %0 = load %Int.st* %self
  ret %Int.st %0
}

define %Bool.st @"!-E_Int_Int"(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp ne i64 %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Int32.st @Int32_i32(i32 %"$0") {
entry:
  %self = alloca %Int32.st
  %value = getelementptr inbounds %Int32.st* %self, i32 0, i32 0
  store i32 %"$0", i32* %value
  %0 = load %Int32.st* %self
  ret %Int32.st %0
}

define %Int.st @Int_() {
entry:
  %self = alloca %Int.st
  %value = getelementptr inbounds %Int.st* %self, i32 0, i32 0
  %v = alloca %Int.st
  store %Int.st zeroinitializer, %Int.st* %v
  store i64 0, i64* %value
  %0 = load %Int.st* %self
  ret %Int.st %0
}

define void @fatalError_() {
entry:
  ret void
}

define void @print_Int(%Int.st %a) {
entry:
  %0 = extractvalue %Int.st %a, 0
  call void @vist-Uprint_i64(i64 %0)
  ret void
}

define %Bool.st @-N-N_Bool_Bool(%Bool.st %a, %Bool.st %b) {
entry:
  %0 = extractvalue %Bool.st %a, 0
  %1 = extractvalue %Bool.st %b, 0
  %2 = and i1 %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Int.st @-G-G_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = ashr i64 %0, %1
  %3 = call %Int.st @Int_i64(i64 %2)
  ret %Int.st %3
}

define %Bool.st @-L-E_Double_Double(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fcmp ole double %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define void @print_Int32(%Int32.st %a) {
entry:
  %0 = extractvalue %Int32.st %a, 0
  call void @vist-Uprint_i32(i32 %0)
  ret void
}

define %Range.st @Range_Int_Int(%Int.st %"$0", %Int.st %"$1") {
entry:
  %self = alloca %Range.st
  %start = getelementptr inbounds %Range.st* %self, i32 0, i32 0
  %end = getelementptr inbounds %Range.st* %self, i32 0, i32 1
  store %Int.st %"$0", %Int.st* %start
  store %Int.st %"$1", %Int.st* %end
  %0 = load %Range.st* %self
  ret %Range.st %0
}

define %Range.st @..._Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = call %Range.st @Range_Int_Int(%Int.st %a, %Int.st %b)
  ret %Range.st %0
}

define %Bool.st @-O-O_Bool_Bool(%Bool.st %a, %Bool.st %b) {
entry:
  %0 = extractvalue %Bool.st %a, 0
  %1 = extractvalue %Bool.st %b, 0
  %2 = and i1 %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

define %Int.st @-D_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = call %Bool.st @"!-E_Int_Int"(%Int.st %b, %Int.st zeroinitializer)
  call void @assert_Bool(%Bool.st %0)
  %1 = extractvalue %Int.st %a, 0
  %2 = extractvalue %Int.st %b, 0
  %3 = sdiv i64 %1, %2
  %4 = call %Int.st @Int_i64(i64 %3)
  ret %Int.st %4
}

define %Double.st @-P_Double_Double(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = fadd double %0, %1
  %3 = call %Double.st @Double_f64(double %2)
  ret %Double.st %3
}

define %Double.st @Double_f64(double %"$0") {
entry:
  %self = alloca %Double.st
  %value = getelementptr inbounds %Double.st* %self, i32 0, i32 0
  store double %"$0", double* %value
  %0 = load %Double.st* %self
  ret %Double.st %0
}

define %Double.st @"%_Double_Double"(%Double.st %a, %Double.st %b) {
entry:
  %0 = extractvalue %Double.st %a, 0
  %1 = extractvalue %Double.st %b, 0
  %2 = frem double %0, %1
  %3 = call %Double.st @Double_f64(double %2)
  ret %Double.st %3
}

declare void @vist-Uprint_i644(i64)

define %Bool.st @-E-E_Int_Int(%Int.st %a, %Int.st %b) {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = extractvalue %Int.st %b, 0
  %2 = icmp eq i64 %0, %1
  %3 = call %Bool.st @Bool_b(i1 %2)
  ret %Bool.st %3
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #2

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #3

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #2

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #2

; Function Attrs: nounwind readnone
declare i1 @llvm.expect.i1(i1, i1) #2

attributes #0 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readnone }
attributes #3 = { noreturn nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"clang version 3.6.2 (tags/RELEASE_362/final)"}
!1 = !{i32 1, !"PIC Level", i32 2}
