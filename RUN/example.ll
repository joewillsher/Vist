; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

; Function Attrs: nounwind
define i64 @main() #0 {
entry:
  %fact_res = tail call { i64 } @_fact_S.i64({ i64 } { i64 8 })
  %value.i = extractvalue { i64 } %fact_res, 0
  %add_res.i = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %value.i, i64 5) #0
  %add_res.fca.1.extract.i = extractvalue { i64, i1 } %add_res.i, 1
  br i1 %add_res.fca.1.extract.i, label %"inlined._+_S.i64_S.i64.then.0.i.i", label %_foo_S.i64_S.i64.exit

"inlined._+_S.i64_S.i64.then.0.i.i":              ; preds = %entry
  tail call void @llvm.trap() #0
  unreachable

_foo_S.i64_S.i64.exit:                            ; preds = %entry
  %add_res.fca.0.extract.i = extractvalue { i64, i1 } %add_res.i, 0
  tail call void @"_$print_i64"(i64 %add_res.fca.0.extract.i)
  ret i64 0
}

; Function Attrs: nounwind
define { i64 } @_foo_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") #0 {
entry:
  %value = extractvalue { i64 } %"$0", 0
  %value1 = extractvalue { i64 } %"$1", 0
  %add_res = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %value, i64 %value1)
  %add_res.fca.1.extract = extractvalue { i64, i1 } %add_res, 1
  br i1 %add_res.fca.1.extract, label %"inlined._+_S.i64_S.i64.then.0.i", label %"inlined._+_S.i64_S.i64._condFail_b.exit"

"inlined._+_S.i64_S.i64.then.0.i":                ; preds = %entry
  tail call void @llvm.trap() #0
  unreachable

"inlined._+_S.i64_S.i64._condFail_b.exit":        ; preds = %entry
  %add_res.fca.0.extract = extractvalue { i64, i1 } %add_res, 0
  %.fca.0.insert.i = insertvalue { i64 } undef, i64 %add_res.fca.0.extract, 0
  ret { i64 } %.fca.0.insert.i
}

; Function Attrs: nounwind
define { i64 } @_fact_S.i64({ i64 } %a) #0 {
entry:
  %value2 = extractvalue { i64 } %a, 0
  %cmp_lte_res = icmp slt i64 %value2, 2
  br i1 %cmp_lte_res, label %then.0, label %else.1

then.0:                                           ; preds = %entry
  ret { i64 } { i64 1 }

else.1:                                           ; preds = %entry
  %sub_res = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value2, i64 1)
  %sub_res.fca.1.extract = extractvalue { i64, i1 } %sub_res, 1
  br i1 %sub_res.fca.1.extract, label %inlined._-_S.i64_S.i64.then.0.i, label %inlined._-_S.i64_S.i64._condFail_b.exit

inlined._-_S.i64_S.i64.then.0.i:                  ; preds = %else.1
  tail call void @llvm.trap() #0
  unreachable

inlined._-_S.i64_S.i64._condFail_b.exit:          ; preds = %else.1
  %sub_res.fca.0.extract = extractvalue { i64, i1 } %sub_res, 0
  %.fca.0.insert.i14 = insertvalue { i64 } undef, i64 %sub_res.fca.0.extract, 0
  %fact_res = tail call { i64 } @_fact_S.i64({ i64 } %.fca.0.insert.i14)
  %value118 = extractvalue { i64 } %fact_res, 0
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %value2, i64 %value118)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %"inlined._*_S.i64_S.i64.then.0.i", label %"inlined._*_S.i64_S.i64._condFail_b.exit"

"inlined._*_S.i64_S.i64.then.0.i":                ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit
  tail call void @llvm.trap() #0
  unreachable

"inlined._*_S.i64_S.i64._condFail_b.exit":        ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  %.fca.0.insert.i20 = insertvalue { i64 } undef, i64 %mul_res.fca.0.extract, 0
  ret { i64 } %.fca.0.insert.i20
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_i64"(i64) #1

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #2

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #3

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #2

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #2

attributes #0 = { nounwind }
attributes #1 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readnone }
attributes #3 = { noreturn nounwind }
