; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

; Function Attrs: nounwind
define void @main() #0 {
entry:
  tail call void @"_$print_i64"(i64 12)
  tail call void @"_$print_i64"(i64 10)
  tail call void @"_$print_i64"(i64 3)
  tail call void @"_$print_i64"(i64 13)
  tail call void @"_$print_i64"(i64 3)
  tail call void @"_$print_i64"(i64 10)
  tail call void @"_$print_b"(i1 false)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define { { i64 }, { i64 } } @_StackOf2_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue { i64 } %"$0", 0
  %"$1.fca.0.extract" = extractvalue { i64 } %"$1", 0
  %StackOf21.fca.0.0.insert = insertvalue { { i64 }, { i64 } } undef, i64 %"$0.fca.0.extract", 0, 0
  %StackOf21.fca.1.0.insert = insertvalue { { i64 }, { i64 } } %StackOf21.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret { { i64 }, { i64 } } %StackOf21.fca.1.0.insert
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_i64"(i64) #2

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_b"(i1 zeroext) #2

attributes #0 = { nounwind }
attributes #1 = { alwaysinline nounwind readnone }
attributes #2 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
