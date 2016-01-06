; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str3 = private unnamed_addr constant [6 x i8] c"true\0A\00", align 1
@.str4 = private unnamed_addr constant [7 x i8] c"false\0A\00", align 1

; Function Attrs: noinline ssp uwtable
define void @_print_i64(i64 %i) #0 {
  %1 = alloca i64, align 8
  store i64 %i, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %2)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline ssp uwtable
define void @_print_i32(i32 %i) #0 {
  %1 = alloca i32, align 4
  store i32 %i, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %2)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @_print_FP64(double %d) #0 {
  %1 = alloca double, align 8
  store double %d, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %2)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @_print_FP32(float %d) #0 {
  %1 = alloca float, align 4
  store float %d, float* %1, align 4
  %2 = load float* %1, align 4
  %3 = fpext float %2 to double
  %4 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), double %3)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @_print_b(i1 zeroext %b) #0 {
  %1 = alloca i8, align 1
  %2 = zext i1 %b to i8
  store i8 %2, i8* %1, align 1
  %3 = load i8* %1, align 1
  %4 = trunc i8 %3 to i1
  br i1 %4, label %5, label %7

; <label>:5                                       ; preds = %0
  %6 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str3, i32 0, i32 0))
  br label %9

; <label>:7                                       ; preds = %0
  %8 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([7 x i8]* @.str4, i32 0, i32 0))
  br label %9

; <label>:9                                       ; preds = %7, %5
  ret void
}

define i64 @main() {
entry:
  %Bool = call { i1 } @_Bool_b(i1 true)
  %0 = alloca { i1 }
  store { i1 } %Bool, { i1 }* %0
  %Double = call { double } @_Double_FP64(double 3.000000e+00)
  %1 = alloca { double }
  store { double } %Double, { double }* %1
  %Int = call { i64 } @_Int_i64(i64 3)
  %2 = alloca { i64 }
  store { i64 } %Int, { i64 }* %2
  %a = load { i64 }* %2
  %Int1 = call { i64 } @_Int_S.i64({ i64 } %a)
  %3 = alloca { i64 }
  store { i64 } %Int1, { i64 }* %3
  %a2 = load { i64 }* %2
  %b = load { i64 }* %3
  %add = call { i64 } @_add_S.i64S.i64({ i64 } %a2, { i64 } %b)
  %4 = alloca { i64 }
  store { i64 } %add, { i64 }* %4
  %c = load { i64 }* %4
  call void @_print_S.i64({ i64 } %c)
  %bo = load { i1 }* %0
  call void @_print_S.b({ i1 } %bo)
  %xx = load { double }* %1
  call void @_print_S.FP64({ double } %xx)
  ret i64 0
}

; Function Attrs: alwaysinline
define { i64 } @_Int_S.i64({ i64 } %o) #2 {
entry:
  %ptro = alloca { i64 }
  store { i64 } %o, { i64 }* %ptro
  %0 = alloca { i64 }
  %value_ptr = getelementptr inbounds { i64 }* %ptro, i32 0, i32 0
  %value = load i64* %value_ptr
  %value_ptr1 = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %value, i64* %value_ptr1
  %1 = load { i64 }* %0
  ret { i64 } %1
}

; Function Attrs: alwaysinline
define { i64 } @_Int_i64(i64 %v) #2 {
entry:
  %0 = alloca { i64 }
  %value_ptr = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %v, i64* %value_ptr
  %1 = load { i64 }* %0
  ret { i64 } %1
}

; Function Attrs: alwaysinline
define { i1 } @_Bool_S.b({ i1 } %o) #2 {
entry:
  %ptro = alloca { i1 }
  store { i1 } %o, { i1 }* %ptro
  %0 = alloca { i1 }
  %value_ptr = getelementptr inbounds { i1 }* %ptro, i32 0, i32 0
  %value = load i1* %value_ptr
  %value_ptr1 = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %value, i1* %value_ptr1
  %1 = load { i1 }* %0
  ret { i1 } %1
}

; Function Attrs: alwaysinline
define { i1 } @_Bool_b(i1 %v) #2 {
entry:
  %0 = alloca { i1 }
  %value_ptr = getelementptr inbounds { i1 }* %0, i32 0, i32 0
  store i1 %v, i1* %value_ptr
  %1 = load { i1 }* %0
  ret { i1 } %1
}

; Function Attrs: alwaysinline
define { double } @_Double_S.FP64({ double } %o) #2 {
entry:
  %ptro = alloca { double }
  store { double } %o, { double }* %ptro
  %0 = alloca { double }
  %value_ptr = getelementptr inbounds { double }* %ptro, i32 0, i32 0
  %value = load double* %value_ptr
  %value_ptr1 = getelementptr inbounds { double }* %0, i32 0, i32 0
  store double %value, double* %value_ptr1
  %1 = load { double }* %0
  ret { double } %1
}

; Function Attrs: alwaysinline
define { double } @_Double_FP64(double %v) #2 {
entry:
  %0 = alloca { double }
  %value_ptr = getelementptr inbounds { double }* %0, i32 0, i32 0
  store double %v, double* %value_ptr
  %1 = load { double }* %0
  ret { double } %1
}

define void @_print_S.i64({ i64 } %a) {
entry:
  %ptra = alloca { i64 }
  store { i64 } %a, { i64 }* %ptra
  %value_ptr = getelementptr inbounds { i64 }* %ptra, i32 0, i32 0
  %value = load i64* %value_ptr
  call void @_print_i64(i64 %value)
  ret void
}

define void @_print_S.b({ i1 } %a) {
entry:
  %ptra = alloca { i1 }
  store { i1 } %a, { i1 }* %ptra
  %value_ptr = getelementptr inbounds { i1 }* %ptra, i32 0, i32 0
  %value = load i1* %value_ptr
  call void @_print_b(i1 %value)
  ret void
}

define void @_print_S.FP64({ double } %a) {
entry:
  %ptra = alloca { double }
  store { double } %a, { double }* %ptra
  %value_ptr = getelementptr inbounds { double }* %ptra, i32 0, i32 0
  %value = load double* %value_ptr
  call void @_print_FP64(double %value)
  ret void
}

define { i64 } @_add_S.i64S.i64({ i64 } %a, { i64 } %b) {
entry:
  %ptra = alloca { i64 }
  store { i64 } %a, { i64 }* %ptra
  %ptrb = alloca { i64 }
  store { i64 } %b, { i64 }* %ptrb
  %value_ptr = getelementptr inbounds { i64 }* %ptra, i32 0, i32 0
  %value = load i64* %value_ptr
  %value_ptr1 = getelementptr inbounds { i64 }* %ptrb, i32 0, i32 0
  %value2 = load i64* %value_ptr1
  %add_res = add i64 %value, %value2
  %Int = call { i64 } @_Int_i64(i64 %add_res)
  ret { i64 } %Int
}

define { double } @_add_S.FP64S.FP64({ double } %a, { double } %b) {
entry:
  %ptra = alloca { double }
  store { double } %a, { double }* %ptra
  %ptrb = alloca { double }
  store { double } %b, { double }* %ptrb
  %value_ptr = getelementptr inbounds { double }* %ptra, i32 0, i32 0
  %value = load double* %value_ptr
  %value_ptr1 = getelementptr inbounds { double }* %ptrb, i32 0, i32 0
  %value2 = load double* %value_ptr1
  %add_res = fadd double %value, %value2
  %Double = call { double } @_Double_FP64(double %add_res)
  ret { double } %Double
}

attributes #0 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
