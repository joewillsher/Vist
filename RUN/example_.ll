; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 0), !stdlib.call.optim !0
  %1 = call { i64 } @_Int_i64(i64 20), !stdlib.call.optim !0
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
  %fib_res = call { i64 } @_fib_S.i64({ i64 } %i)
  call void @_print_S.i64({ i64 } %fib_res), !stdlib.call.optim !0
  br label %loop.latch

loop.latch:                                       ; preds = %loop.body
  %loop.repeat.test = icmp sle i64 %next.i, %end.value
  br i1 %loop.repeat.test, label %loop.header, label %loop.exit

loop.exit:                                        ; preds = %loop.latch
  ret void
}

define internal { i64 } @_fib_S.i64({ i64 } %a) {
entry:
  %0 = call { i64 } @_Int_i64(i64 0), !stdlib.call.optim !0
  %"<.res" = call { i1 } @"_<_S.i64_S.i64"({ i64 } %a, { i64 } %0), !stdlib.call.optim !0
  %value = extractvalue { i1 } %"<.res", 0
  br i1 %value, label %then.0, label %cont.stmt

cont.stmt:                                        ; preds = %entry, %then.0
  %1 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %"<=.res" = call { i1 } @"_<=_S.i64_S.i64"({ i64 } %a, { i64 } %1), !stdlib.call.optim !0
  %value3 = extractvalue { i1 } %"<=.res", 0
  br i1 %value3, label %then.02, label %cont.0

then.0:                                           ; preds = %entry
  call void @_fatalError_(), !stdlib.call.optim !0
  br label %cont.stmt

cont.0:                                           ; preds = %cont.stmt
  br label %else.1

then.02:                                          ; preds = %cont.stmt
  %2 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  ret { i64 } %2

else.1:                                           ; preds = %cont.0
  %3 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %-.res = call { i64 } @_-_S.i64_S.i64({ i64 } %a, { i64 } %3), !stdlib.call.optim !0
  %fib_res = call { i64 } @_fib_S.i64({ i64 } %-.res)
  %4 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  %-.res4 = call { i64 } @_-_S.i64_S.i64({ i64 } %a, { i64 } %4), !stdlib.call.optim !0
  %fib_res5 = call { i64 } @_fib_S.i64({ i64 } %-.res4)
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %fib_res, { i64 } %fib_res5), !stdlib.call.optim !0
  ret { i64 } %"+.res"
}

declare { i64 } @_Int_i64(i64)

declare { i1 } @"_<_S.i64_S.i64"({ i64 }, { i64 })

declare void @_fatalError_()

declare { i1 } @"_<=_S.i64_S.i64"({ i64 }, { i64 })

declare { i64 } @_-_S.i64_S.i64({ i64 }, { i64 })

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

declare { { i64 }, { i64 } } @_..._S.i64_S.i64({ i64 }, { i64 })

declare void @_print_S.i64({ i64 })

!0 = !{!"stdlib.call.optim"}
