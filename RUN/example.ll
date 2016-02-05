; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

; Function Attrs: nounwind
define void @main() #0 {
entry:
  br label %loop.header

loop.header:                                      ; preds = %cont.stmt, %entry
  %loop.count.i = phi i64 [ 0, %entry ], [ %next.i, %cont.stmt ]
  %next.i = add nuw nsw i64 %loop.count.i, 1
  %rem_res = urem i64 %loop.count.i, 3
  %cmp_eq_res = icmp eq i64 %rem_res, 0
  br i1 %cmp_eq_res, label %then.0, label %cont.0

loop.exit:                                        ; preds = %cont.stmt
  ret void

cont.stmt:                                        ; preds = %else.2, %then.1, %"inlined._*_S.i64_S.i64._condFail_b.exit"
  %loop.repeat.test = icmp slt i64 %next.i, 1001
  br i1 %loop.repeat.test, label %loop.header, label %loop.exit

cont.0:                                           ; preds = %loop.header
  %rem_res35 = urem i64 %loop.count.i, 1000
  %cmp_eq_res47 = icmp eq i64 %rem_res35, 0
  br i1 %cmp_eq_res47, label %then.1, label %else.2

then.0:                                           ; preds = %loop.header
  %mul_res = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %loop.count.i, i64 3)
  %mul_res.fca.1.extract = extractvalue { i64, i1 } %mul_res, 1
  br i1 %mul_res.fca.1.extract, label %"inlined._*_S.i64_S.i64.then.0.i", label %"inlined._*_S.i64_S.i64._condFail_b.exit"

"inlined._*_S.i64_S.i64.then.0.i":                ; preds = %then.0
  tail call void @llvm.trap() #0
  unreachable

"inlined._*_S.i64_S.i64._condFail_b.exit":        ; preds = %then.0
  %mul_res.fca.0.extract = extractvalue { i64, i1 } %mul_res, 0
  tail call void @"_$print_i64"(i64 %mul_res.fca.0.extract)
  br label %cont.stmt

then.1:                                           ; preds = %cont.0
  tail call void @"_$print_i64"(i64 1000000)
  br label %cont.stmt

else.2:                                           ; preds = %cont.0
  tail call void @"_$print_i64"(i64 %loop.count.i)
  br label %cont.stmt
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #1

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #2

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_i64"(i64) #3

attributes #0 = { nounwind }
attributes #1 = { nounwind readnone }
attributes #2 = { noreturn nounwind }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
