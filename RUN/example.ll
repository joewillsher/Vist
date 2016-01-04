; ModuleID = 'example_.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: noinline ssp uwtable
define void @_print__Int64(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline ssp uwtable
define void @_print__FP64(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), double %d)
  ret void
}

define i64 @main() {
entry:
  %0 = alloca { i64, i64 }, align 8
  %1 = bitcast { i64, i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 16, i8* %1)
  %a_ptr.i = getelementptr inbounds { i64, i64 }* %0, i64 0, i32 0
  store i64 2, i64* %a_ptr.i, align 8
  %b_ptr.i = getelementptr inbounds { i64, i64 }* %0, i64 0, i32 1
  store i64 3, i64* %b_ptr.i, align 8
  %2 = load { i64, i64 }* %0, align 8
  %3 = bitcast { i64, i64 }* %0 to i8*
  call void @llvm.lifetime.end(i64 16, i8* %3)
  %4 = alloca { i64, i64 }, align 8
  store { i64, i64 } %2, { i64, i64 }* %4, align 8
  %5 = alloca { i64, i64 }, align 8
  store { i64, i64 } %2, { i64, i64 }* %5, align 8
  %a_ptr = getelementptr inbounds { i64, i64 }* %4, i64 0, i32 0
  store i64 1, i64* %a_ptr, align 8
  tail call void @_print__Int64(i64 1)
  %a_ptr2 = getelementptr inbounds { i64, i64 }* %5, i64 0, i32 0
  %a3 = load i64* %a_ptr2, align 8
  tail call void @_print__Int64(i64 %a3)
  %b_ptr = getelementptr inbounds { i64, i64 }* %4, i64 0, i32 1
  %b = load i64* %b_ptr, align 8
  tail call void @_print__Int64(i64 %b)
  tail call void @_print__Int64(i64 22)
  tail call void @_print__FP64(double 2.200000e+01)
  ret i64 0
}

; Function Attrs: alwaysinline
define { i64, i64 } @_Meme__Int64_Int64_R__SInt64.Int64(i64 %x, i64 %y) #2 {
entry:
  %0 = alloca { i64, i64 }, align 8
  %a_ptr = getelementptr inbounds { i64, i64 }* %0, i64 0, i32 0
  store i64 %x, i64* %a_ptr, align 8
  %b_ptr = getelementptr inbounds { i64, i64 }* %0, i64 0, i32 1
  store i64 %y, i64* %b_ptr, align 8
  %1 = load { i64, i64 }* %0, align 8
  ret { i64, i64 } %1
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
