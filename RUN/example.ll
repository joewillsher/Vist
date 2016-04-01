; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@0 = private unnamed_addr constant [5 x i8] c"meme\00"

; Function Attrs: nounwind
define void @main() #0 {
entry:
  %0 = tail call i8* @malloc(i32 5)
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %0, i8* getelementptr inbounds ([5 x i8]* @0, i64 0, i64 0), i64 5, i32 1, i1 false)
  tail call void @vist-Uprint_top(i8* %0)
  ret void
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i32) #0

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #0

; Function Attrs: noinline nounwind ssp uwtable
declare void @vist-Uprint_top(i8* nocapture readonly) #1

attributes #0 = { nounwind }
attributes #1 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
