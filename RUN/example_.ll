; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

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

define i64 @main() {
entry:
  %Int = call { i64 } @_Int_i64_RS.i64(i64 3)
  %0 = alloca { i64 }
  store { i64 } %Int, { i64 }* %0
  %value_ptr = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  %value = load i64* %value_ptr
  call void @_print_i64(i64 %value)
  %a = load { i64 }* %0
  %Int1 = call { i64 } @_Int_S.i64_RS.i64({ i64 } %a)
  %1 = alloca { i64 }
  store { i64 } %Int1, { i64 }* %1
  %value_ptr2 = getelementptr inbounds { i64 }* %1, i32 0, i32 0
  %value3 = load i64* %value_ptr2
  call void @_print_i64(i64 %value3)
  ret i64 0
}

; Function Attrs: alwaysinline
define { i64 } @_Int_S.i64_RS.i64({ i64 } %o) #2 {
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
define { i64 } @_Int_i64_RS.i64(i64 %v) #2 {
entry:
  %0 = alloca { i64 }
  %value_ptr = getelementptr inbounds { i64 }* %0, i32 0, i32 0
  store i64 %v, i64* %value_ptr
  %1 = load { i64 }* %0
  ret { i64 } %1
}

attributes #0 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
