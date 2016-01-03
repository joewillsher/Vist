; ModuleID = 'example_.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: noinline ssp uwtable
define void @print(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: noinline ssp uwtable
define void @printd(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), double %d)
  ret void
}

define i64 @main() {
entry:
  %0 = alloca { i64, i64 }, align 8
  %1 = bitcast { i64, i64 }* %0 to i8*
  call void @llvm.lifetime.start(i64 16, i8* %1)
  %aptr.i = getelementptr inbounds { i64, i64 }* %0, i64 0, i32 0
  store i64 2, i64* %aptr.i, align 8
  %bptr.i = getelementptr inbounds { i64, i64 }* %0, i64 0, i32 1
  store i64 3, i64* %bptr.i, align 8
  %2 = load { i64, i64 }* %0, align 8
  %3 = bitcast { i64, i64 }* %0 to i8*
  call void @llvm.lifetime.end(i64 16, i8* %3)
  %4 = alloca { i64, i64 }, align 8
  store { i64, i64 } %2, { i64, i64 }* %4, align 8
  %aptr = getelementptr inbounds { i64, i64 }* %4, i64 0, i32 0
  store i64 1, i64* %aptr, align 8
  tail call void @print(i64 1)
  %bptr = getelementptr inbounds { i64, i64 }* %4, i64 0, i32 1
  %belement = load i64* %bptr, align 8
  tail call void @print(i64 %belement)
  ret i64 0
}

define { i64, i64 } @Meme(i64 %x, i64 %y) {
entry:
  %0 = alloca { i64, i64 }, align 8
  %aptr = getelementptr inbounds { i64, i64 }* %0, i64 0, i32 0
  store i64 %x, i64* %aptr, align 8
  %bptr = getelementptr inbounds { i64, i64 }* %0, i64 0, i32 1
  store i64 %y, i64* %bptr, align 8
  %1 = load { i64, i64 }* %0, align 8
  ret { i64, i64 } %1
}

; Function Attrs: nounwind
declare void @llvm.lifetime.start(i64, i8* nocapture) #2

; Function Attrs: nounwind
declare void @llvm.lifetime.end(i64, i8* nocapture) #2

attributes #0 = { noinline ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
