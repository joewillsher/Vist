; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define i64 @main() {
entry:
  %0 = insertvalue { i64 } undef, i64 3, 0
  %1 = insertvalue { i64 } undef, i64 4, 0
  %2 = extractvalue { i64 } %0, 0
  %3 = extractvalue { i64 } %1, 0
  %4 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %2, i64 %3)
  %5 = extractvalue { i64, i1 } %4, 1
  br i1 %5, label %"inlined._+_S.i64_S.i64.then.0.i", label %"inlined._+_S.i64_S.i64._condFail_b.exit"

"inlined._+_S.i64_S.i64.then.0.i":                ; preds = %entry, %entry
  tail call void @llvm.trap() #3
  unreachable

"inlined._+_S.i64_S.i64._condFail_b.exit":        ; preds = %entry, %entry
  %6 = extractvalue { i64, i1 } %4, 0
  %7 = insertvalue { i64 } undef, i64 %6, 0
  %8 = extractvalue { i64 } %7, 0
  tail call void @"_$print_i64"(i64 %8)
  ret i64 0
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #0

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #1

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_i64"(i64) #2

attributes #0 = { nounwind readnone }
attributes #1 = { noreturn nounwind }
attributes #2 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }
