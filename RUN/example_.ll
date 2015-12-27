; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: ssp uwtable
define void @print(i64 %i) #0 {
  %1 = alloca i64, align 8
  store i64 %i, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %2)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: ssp uwtable
define void @printd(double %d) #0 {
  %1 = alloca double, align 8
  store double %d, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), double %2)
  ret void
}

define i64 @main() {
entry:
  %a = alloca i64
  store i64 3, i64* %a
  %a1 = load i64* %a
  %add_res = add i64 1, %a1
  %b = alloca i64
  store i64 %add_res, i64* %b
  %0 = call i64 @foo(i64 1)
  %c = alloca i64
  store i64 %0, i64* %c
  %arr = alloca [2 x i64]
  %base = bitcast [2 x i64]* %arr to i64*
  %el0 = getelementptr i64* %base, i64 0
  store i64 1, i64* %el0
  %el1 = getelementptr i64* %base, i64 1
  store i64 2, i64* %el1
  %d = alloca i64*
  store i64* %base, i64** %d
  %ptr = getelementptr i64* %base, i64 1
  %element = load i64* %ptr
  %add_res2 = add i64 %element, 21
  call void @print(i64 %add_res2)
  %c3 = load i64* %c
  %b4 = load i64* %b
  %add_res5 = add i64 %c3, %b4
  call void @print(i64 %add_res5)
  ret i64 0
}

define i64 @foo(i64 %"$0") {
entry:
  %add_res = add i64 %"$0", 11
  ret i64 %add_res
}

attributes #0 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
