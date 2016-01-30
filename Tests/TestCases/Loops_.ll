; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 0), !stdlib.call.optim !0
  %1 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  %....res = call { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 } %0, { i64 } %1), !stdlib.call.optim !0
  %start = extractvalue { { i64 }, { i64 } } %....res, 0
  %start.value = extractvalue { i64 } %start, 0
  %end = extractvalue { { i64 }, { i64 } } %....res, 1
  %end.value = extractvalue { i64 } %end, 0
  br label %loop.header

loop.header:                                      ; preds = %loop.latch, %entry
  %loop.count.i = phi i64 [ %start.value, %entry ], [ %next.i, %loop.latch ]
  %next.i = add i64 1, %loop.count.i
  %i = call { i64 } @_Int_i64(i64 %loop.count.i), !stdlib.call.optim !0
  br label %loop.body

loop.body:                                        ; preds = %loop.header
  call void @_print_S.i64({ i64 } %i), !stdlib.call.optim !0
  br label %loop.latch

loop.latch:                                       ; preds = %loop.body
  %loop.repeat.test = icmp sle i64 %next.i, %end.value
  br i1 %loop.repeat.test, label %loop.header, label %loop.exit

loop.exit:                                        ; preds = %loop.latch
  ret void
}

declare { i64 } @_Int_i64(i64)

declare { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 }, { i64 })

declare void @_print_S.i64({ i64 })

!0 = !{!"stdlib.call.optim"}
