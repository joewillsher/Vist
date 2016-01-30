; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %fact_res = tail call { i64 } @_fact_S.i64({ i64 } { i64 20 })
  %value = extractvalue { i64 } %fact_res, 0
  tail call void @"_$print_i64"(i64 %value)
  tail call void @"_$print_i64"(i64 24)
  tail call void @"_$print_b"(i1 false)
  ret void
}

define { i64 } @_fact_S.i64({ i64 } %a) {
entry:
  %value2 = extractvalue { i64 } %a, 0
  %cmp_lte_res = icmp slt i64 %value2, 2
  %0 = tail call { i64 } @_Int_i64(i64 1)
  br i1 %cmp_lte_res, label %then.0, label %else.1

then.0:                                           ; preds = %entry
  ret { i64 } %0

else.1:                                           ; preds = %entry
  %value16 = extractvalue { i64 } %0, 0
  %sub_res = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value2, i64 %value16)
  %sub_res.fca.1.extract = extractvalue { i64, i1 } %sub_res, 1
  br i1 %sub_res.fca.1.extract, label %inlined._-_S.i64_S.i64.then.0.i, label %inlined._-_S.i64_S.i64._condFail_b.exit

inlined._-_S.i64_S.i64.then.0.i:                  ; preds = %else.1
  tail call void @llvm.trap() #3
  unreachable

inlined._-_S.i64_S.i64._condFail_b.exit:          ; preds = %else.1
  %sub_res.fca.0.extract = extractvalue { i64, i1 } %sub_res, 0
  %.fca.0.insert.i8 = insertvalue { i64 } undef, i64 %sub_res.fca.0.extract, 0
  %fact_res = tail call { i64 } @_fact_S.i64({ i64 } %.fca.0.insert.i8)
  %value112 = extractvalue { i64 } %fact_res, 0
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %value2, i64 %value112)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %"inlined._*_S.i64_S.i64.then.0.i", label %"inlined._*_S.i64_S.i64._condFail_b.exit"

"inlined._*_S.i64_S.i64.then.0.i":                ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit
  tail call void @llvm.trap() #3
  unreachable

"inlined._*_S.i64_S.i64._condFail_b.exit":        ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  %.fca.0.insert.i14 = insertvalue { i64 } undef, i64 %mul_res.fca.0.extract, 0
  ret { i64 } %.fca.0.insert.i14
}

declare { i64 } @_Int_i64(i64)

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_i64"(i64) #0

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #1

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #2

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_b"(i1 zeroext) #0

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #1

attributes #0 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone }
attributes #2 = { noreturn nounwind }
attributes #3 = { nounwind }
