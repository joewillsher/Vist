; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

; Function Attrs: nounwind
define void @main() #0 {
entry:
  tail call void @-Uprint_i64(i64 2)
  ret void
}

; Function Attrs: nounwind
define %Int.st @foo_Int(%Int.st) #0 {
entry:
  %a.value = extractvalue %Int.st %0, 0
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %a.value, i64 2)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %inlined.-A_Int_Int.then.0.i, label %inlined.-A_Int_Int.condFail_b.exit

inlined.-A_Int_Int.then.0.i:                      ; preds = %entry
  tail call void @llvm.trap() #0
  unreachable

inlined.-A_Int_Int.condFail_b.exit:               ; preds = %entry
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  %Int1.i.fca.0.insert = insertvalue %Int.st undef, i64 %mul_res.fca.0.extract, 0
  ret %Int.st %Int1.i.fca.0.insert
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @-Uprint_i64(i64) #1

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #2

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #3

attributes #0 = { nounwind }
attributes #1 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readnone }
attributes #3 = { noreturn nounwind }
