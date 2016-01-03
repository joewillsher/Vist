; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: noinline ssp uwtable
define void @print(i64 %i) #0 {
  %1 = alloca i64, align 8
  store i64 %i, i64* %1, align 8
  %2 = load i64* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i64 %2)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline ssp uwtable
define void @printd(double %d) #0 {
  %1 = alloca double, align 8
  store double %d, double* %1, align 8
  %2 = load double* %1, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), double %2)
  ret void
}

define i64 @main() {
entry:
  %Meme = call { i64, i64 } @Meme(i64 2, i64 3)
  %0 = alloca { i64, i64 }
  store { i64, i64 } %Meme, { i64, i64 }* %0
  %ptr = getelementptr inbounds { i64, i64 }* %0, i32 0, i32 0
  %element = load i64* %ptr
  call void @print(i64 %element)
  %ptr1 = getelementptr inbounds { i64, i64 }* %0, i32 0, i32 1
  %element2 = load i64* %ptr1
  call void @print(i64 %element2)
  ret i64 0
}

define { i64, i64 } @Meme(i64 %x, i64 %y) {
entry:
  %0 = alloca { i64, i64 }
  %ptr = getelementptr inbounds { i64, i64 }* %0, i32 0, i32 0
  store i64 %x, i64* %ptr
  %ptr1 = getelementptr inbounds { i64, i64 }* %0, i32 0, i32 1
  store i64 %y, i64* %ptr1
  %1 = load { i64, i64 }* %0
  ret { i64, i64 } %1
}

attributes #0 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
