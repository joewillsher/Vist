; ModuleID = 'example_.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%i\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: noinline ssp uwtable
define void @_print_i64(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline ssp uwtable
define void @_print_i32(i32 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), i32 %i)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @_print_FP64(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: noinline ssp uwtable
define void @_print_FP32(float %d) #0 {
  %1 = fpext float %d to double
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), double %1)
  ret void
}

define i64 @main() {
entry:
  %ptro.i = alloca { i64 }, align 8
  %0 = alloca { i64 }, align 8
  %1 = alloca { i64 }, align 8
  %2 = bitcast { i64 }* %1 to i8*
  call void @llvm.lifetime.start(i64 8, i8* %2)
  %value_ptr.i = getelementptr inbounds { i64 }* %1, i64 0, i32 0
  store i64 3, i64* %value_ptr.i, align 8
  %3 = load { i64 }* %1, align 8
  %4 = bitcast { i64 }* %1 to i8*
  call void @llvm.lifetime.end(i64 8, i8* %4)
  %5 = alloca { i64 }, align 8
  store { i64 } %3, { i64 }* %5, align 8
  %value_ptr = getelementptr inbounds { i64 }* %5, i64 0, i32 0
  %value = load i64* %value_ptr, align 8
  tail call void @_print_i64(i64 %value)
  %a = load { i64 }* %5, align 8
  %6 = bitcast { i64 }* %ptro.i to i8*
  call void @llvm.lifetime.start(i64 8, i8* %6)
  %7 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 8, i8* %7)
  store { i64 } %a, { i64 }* %ptro.i, align 8
  %value_ptr.i1 = getelementptr inbounds { i64 }* %ptro.i, i64 0, i32 0
  %value.i = load i64* %value_ptr.i1, align 8
  %value_ptr1.i = getelementptr inbounds { i64 }* %0, i64 0, i32 0
  store i64 %value.i, i64* %value_ptr1.i, align 8
  %8 = load { i64 }* %0, align 8
  %9 = bitcast { i64 }* %ptro.i to i8*
  call void @llvm.lifetime.end(i64 8, i8* %9)
  %10 = bitcast { i64 }* %0 to i8*
  call void @llvm.lifetime.end(i64 8, i8* %10)
  %11 = alloca { i64 }, align 8
  store { i64 } %8, { i64 }* %11, align 8
  %value_ptr2 = getelementptr inbounds { i64 }* %11, i64 0, i32 0
  %value3 = load i64* %value_ptr2, align 8
  tail call void @_print_i64(i64 %value3)
  ret i64 0
}

; Function Attrs: alwaysinline
define { i64 } @_Int_S.i64_RS.i64({ i64 } %o) #2 {
entry:
  %ptro = alloca { i64 }, align 8
  store { i64 } %o, { i64 }* %ptro, align 8
  %0 = alloca { i64 }, align 8
  %value_ptr = getelementptr inbounds { i64 }* %ptro, i64 0, i32 0
  %value = load i64* %value_ptr, align 8
  %value_ptr1 = getelementptr inbounds { i64 }* %0, i64 0, i32 0
  store i64 %value, i64* %value_ptr1, align 8
  %1 = load { i64 }* %0, align 8
  ret { i64 } %1
}

; Function Attrs: alwaysinline
define { i64 } @_Int_i64_RS.i64(i64 %v) #2 {
entry:
  %0 = alloca { i64 }, align 8
  %value_ptr = getelementptr inbounds { i64 }* %0, i64 0, i32 0
  store i64 %v, i64* %value_ptr, align 8
  %1 = load { i64 }* %0, align 8
  ret { i64 } %1
}

; Function Attrs: nounwind
declare void @llvm.lifetime.start(i64, i8* nocapture) #3

; Function Attrs: nounwind
declare void @llvm.lifetime.end(i64, i8* nocapture) #3

attributes #0 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { alwaysinline }
attributes #3 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
