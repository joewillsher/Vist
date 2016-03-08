; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

; Function Attrs: nounwind
define void @main() #0 {
entry:
  tail call void @-Uprint_i64(i64 3)
  tail call void @-Uprint_i64(i64 1)
  ret void
}

; Function Attrs: nounwind readnone
define %Int.st @foo_Int(%Int.st) #1 {
entry:
  ret %Int.st %0
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @-Uprint_i64(i64) #2

attributes #0 = { nounwind }
attributes #1 = { nounwind readnone }
attributes #2 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
