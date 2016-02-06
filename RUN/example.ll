; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = tail call { i64 } @_Int_i64(i64 1)
  %oldret1.i = extractvalue { i64 } %0, 0
  tail call void @"_$print_i64"(i64 %oldret1.i)
  %1 = tail call { i64 } @_Int_i64(i64 1)
  %oldret1.i1 = extractvalue { i64 } %1, 0
  tail call void @"_$print_i64"(i64 %oldret1.i1)
  %fib_res.2 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 2 })
  tail call void @"_$print_i64"(i64 %fib_res.2)
  %fib_res.3 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 3 })
  tail call void @"_$print_i64"(i64 %fib_res.3)
  %fib_res.4 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 4 })
  tail call void @"_$print_i64"(i64 %fib_res.4)
  %fib_res.5 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 5 })
  tail call void @"_$print_i64"(i64 %fib_res.5)
  %fib_res.6 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 6 })
  tail call void @"_$print_i64"(i64 %fib_res.6)
  %fib_res.7 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 7 })
  tail call void @"_$print_i64"(i64 %fib_res.7)
  %fib_res.8 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 8 })
  tail call void @"_$print_i64"(i64 %fib_res.8)
  %fib_res.9 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 9 })
  tail call void @"_$print_i64"(i64 %fib_res.9)
  %fib_res.10 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 10 })
  tail call void @"_$print_i64"(i64 %fib_res.10)
  %fib_res.11 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 11 })
  tail call void @"_$print_i64"(i64 %fib_res.11)
  %fib_res.12 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 12 })
  tail call void @"_$print_i64"(i64 %fib_res.12)
  %fib_res.13 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 13 })
  tail call void @"_$print_i64"(i64 %fib_res.13)
  %fib_res.14 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 14 })
  tail call void @"_$print_i64"(i64 %fib_res.14)
  %fib_res.15 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 15 })
  tail call void @"_$print_i64"(i64 %fib_res.15)
  %fib_res.16 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 16 })
  tail call void @"_$print_i64"(i64 %fib_res.16)
  %fib_res.17 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 17 })
  tail call void @"_$print_i64"(i64 %fib_res.17)
  %fib_res.18 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 18 })
  tail call void @"_$print_i64"(i64 %fib_res.18)
  %fib_res.19 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 19 })
  tail call void @"_$print_i64"(i64 %fib_res.19)
  %fib_res.20 = tail call fastcc i64 @_fib_S.i64({ i64 } { i64 20 })
  tail call void @"_$print_i64"(i64 %fib_res.20)
  ret void
}

define internal fastcc i64 @_fib_S.i64({ i64 } %a) {
entry:
  %value7 = extractvalue { i64 } %a, 0
  %cmp_lt_res = icmp slt i64 %value7, 0
  br i1 %cmp_lt_res, label %then.0, label %cont.stmt

cont.stmt:                                        ; preds = %entry
  %cmp_lte_res = icmp slt i64 %value7, 2
  %0 = tail call { i64 } @_Int_i64(i64 1)
  %oldret1 = extractvalue { i64 } %0, 0
  br i1 %cmp_lte_res, label %then.02, label %else.1

then.0:                                           ; preds = %entry
  tail call void @llvm.trap()
  unreachable

then.02:                                          ; preds = %cont.stmt
  ret i64 %oldret1

else.1:                                           ; preds = %cont.stmt
  %sub_res = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value7, i64 %oldret1)
  %sub_res.fca.1.extract = extractvalue { i64, i1 } %sub_res, 1
  br i1 %sub_res.fca.1.extract, label %inlined._-_S.i64_S.i64.then.0.i, label %inlined._-_S.i64_S.i64._condFail_b.exit

inlined._-_S.i64_S.i64.then.0.i:                  ; preds = %else.1
  tail call void @llvm.trap() #3
  unreachable

inlined._-_S.i64_S.i64._condFail_b.exit:          ; preds = %else.1
  %sub_res.fca.0.extract = extractvalue { i64, i1 } %sub_res, 0
  %.fca.0.insert24 = insertvalue { i64 } undef, i64 %sub_res.fca.0.extract, 0
  %fib_res = tail call fastcc i64 @_fib_S.i64({ i64 } %.fca.0.insert24)
  %sub_res34 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %value7, i64 2)
  %sub_res.fca.1.extract36 = extractvalue { i64, i1 } %sub_res34, 1
  br i1 %sub_res.fca.1.extract36, label %inlined._-_S.i64_S.i64.then.0.i37, label %inlined._-_S.i64_S.i64._condFail_b.exit38

inlined._-_S.i64_S.i64.then.0.i37:                ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit
  tail call void @llvm.trap() #3
  unreachable

inlined._-_S.i64_S.i64._condFail_b.exit38:        ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit
  %sub_res.fca.0.extract40 = extractvalue { i64, i1 } %sub_res34, 0
  %.fca.0.insert42 = insertvalue { i64 } undef, i64 %sub_res.fca.0.extract40, 0
  %fib_res5 = tail call fastcc i64 @_fib_S.i64({ i64 } %.fca.0.insert42)
  %add_res = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %fib_res, i64 %fib_res5)
  %add_res.fca.1.extract = extractvalue { i64, i1 } %add_res, 1
  br i1 %add_res.fca.1.extract, label %"inlined._+_S.i64_S.i64.then.0.i", label %"inlined._+_S.i64_S.i64._condFail_b.exit"

"inlined._+_S.i64_S.i64.then.0.i":                ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit38
  tail call void @llvm.trap() #3
  unreachable

"inlined._+_S.i64_S.i64._condFail_b.exit":        ; preds = %inlined._-_S.i64_S.i64._condFail_b.exit38
  %add_res.fca.0.extract = extractvalue { i64, i1 } %add_res, 0
  ret i64 %add_res.fca.0.extract
}

declare { i64 } @_Int_i64(i64)

; Function Attrs: noinline nounwind ssp uwtable
declare void @"_$print_i64"(i64) #0

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #1

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #2

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #2

attributes #0 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noreturn nounwind }
attributes #2 = { nounwind readnone }
attributes #3 = { nounwind }
