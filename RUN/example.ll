; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

; Function Attrs: nounwind
define void @main() #0 {
entry:
  br label %loop

loop:                                             ; preds = %loop, %entry
  %loop.count = phi i64 [ 0, %entry ], [ %count.it, %loop ]
  tail call void @-Uprint_i64(i64 %loop.count)
  %count.it = add nuw nsw i64 %loop.count, 1
  %exitcond = icmp eq i64 %count.it, 101
  br i1 %exitcond, label %loop.exit, label %loop

loop.exit:                                        ; preds = %loop
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @-Uprint_i64(i64) #1

attributes #0 = { nounwind }
attributes #1 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
