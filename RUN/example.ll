; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  tail call void @"_$print_i64"(i64 300)
  %factorial_res = tail call fastcc i64 @_factorial_S.i64({ i64 } { i64 10 })
  %add_res.i = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %factorial_res, i64 10) #4
  %add_res.fca.1.extract.i = extractvalue { i64, i1 } %add_res.i, 1
  br i1 %add_res.fca.1.extract.i, label %"inlined._+_S.i64_S.i64.then.0.i.i", label %_add_S.i64_S.i64.exit

"inlined._+_S.i64_S.i64.then.0.i.i":              ; preds = %entry
  tail call void @llvm.trap() #4
  unreachable

_add_S.i64_S.i64.exit:                            ; preds = %entry
  %add_res.fca.0.extract.i = extractvalue { i64, i1 } %add_res.i, 0
  tail call void @"_$print_i64"(i64 %add_res.fca.0.extract.i)
  tail call void @"_$print_i64"(i64 10)
  ret void
}

define internal fastcc i64 @_factorial_S.i64({ i64 } %a) {
entry:
  %value2 = extractvalue { i64 } %a, 0
  %cmp_lte_res = icmp slt i64 %value2, 2
  %0 = tail call { i64 } @_Int_i64(i64 1)
  %oldret1 = extractvalue { i64 } %0, 0
  br i1 %cmp_lte_res, label %then.0, label %else.1

then.0:                                           ; preds = %entry
  ret i64 %oldret1

else.1:                                           ; preds = %entry
  %sub_res = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value2, i64 %oldret1)
  %sub_res.fca.1.extract = extractvalue { i64, i1 } %sub_res, 1
  br i1 %sub_res.fca.1.extract, label %inlined._-_S.i64_S.i64.then.0.i, label %inlined._-_S.i64_S.i64._condFail_b.exit

inlined._-_S.i64_S.i64.then.0.i:                  ; preds = %else.1
  tail call void @llvm.trap() #4
  unreachable

inlined._-_S.i64_S.i64._condFail_b.exit:          ; preds = %else.1
  %sub_res.fca.0.extract = extractvalue { i64, i1 } %sub_res, 0
  %.fca.0.insert10 = insertvalue { i64 } undef, i64 %sub_res.fca.0.extract, 0
  %factorial_res = tail call fastcc i64 @_factorial_S.i64({ i64 } %.fca.0.insert10)
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %value2, i64 %factorial_res)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %"inlined._*_S.i64_S.i64.then.0.i", label %"inlined._*_S.i64_S.i64._condFail_b.exit"

"inlined._*_S.i64_S.i64.then.0.i":                ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit
  tail call void @llvm.trap() #4
  unreachable

"inlined._*_S.i64_S.i64._condFail_b.exit":        ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  ret i64 %mul_res.fca.0.extract
}

declare { i64 } @_Int_i64(i64)

; Function Attrs: alwaysinline nounwind readnone
define { { i64 }, { i64 } } @_Baz_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") #0 {
entry:
  %"$0.fca.0.extract" = extractvalue { i64 } %"$0", 0
  %"$1.fca.0.extract" = extractvalue { i64 } %"$1", 0
  %.fca.0.0.insert = insertvalue { { i64 }, { i64 } } undef, i64 %"$0.fca.0.extract", 0, 0
  %.fca.1.0.insert = insertvalue { { i64 }, { i64 } } %.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  ret { { i64 }, { i64 } } %.fca.1.0.insert
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #1

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #2

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_i64"(i64) #3

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #1

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #1

attributes #0 = { alwaysinline nounwind readnone }
attributes #1 = { nounwind readnone }
attributes #2 = { noreturn nounwind }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }
