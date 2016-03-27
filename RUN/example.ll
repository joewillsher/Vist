; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

; Function Attrs: nounwind
define void @main() #0 {
entry:
  tail call void @vist-Uprint_i64(i64 1)
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @vist-Uprint_i64(i64) #1

attributes #0 = { nounwind }
attributes #1 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
