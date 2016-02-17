; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Range.st = type { %Int.st, %Int.st }
%Bool.st = type { i1 }

define void @main() {
entry:
  %0 = call %Int.st @_Int_i64(i64 0), !stdlib.call.optim !0
  %1 = call %Int.st @_Int_i64(i64 36), !stdlib.call.optim !0
  %....res = call %Range.st @_..._Int_Int(%Int.st %0, %Int.st %1), !stdlib.call.optim !0
  %start = extractvalue %Range.st %....res, 0
  %start.value = extractvalue %Int.st %start, 0
  %end = extractvalue %Range.st %....res, 1
  %end.value = extractvalue %Int.st %end, 0
  br label %loop.header

loop.header:                                      ; preds = %loop.latch, %entry
  %loop.count.i = phi i64 [ %start.value, %entry ], [ %next.i, %loop.latch ]
  %next.i = add i64 1, %loop.count.i
  %i = call %Int.st @_Int_i64(i64 %loop.count.i), !stdlib.call.optim !0
  br label %loop.body

loop.body:                                        ; preds = %loop.header
  %fib_res = call %Int.st @_fib_Int(%Int.st %i)
  call void @_print_Int(%Int.st %fib_res), !stdlib.call.optim !0
  br label %loop.latch

loop.latch:                                       ; preds = %loop.body
  %loop.repeat.test = icmp sle i64 %next.i, %end.value
  br i1 %loop.repeat.test, label %loop.header, label %loop.exit

loop.exit:                                        ; preds = %loop.latch
  ret void
}

define internal %Int.st @_fib_Int(%Int.st %a) {
entry:
  %0 = call %Int.st @_Int_i64(i64 0), !stdlib.call.optim !0
  %"<.res" = call %Bool.st @"_<_Int_Int"(%Int.st %a, %Int.st %0), !stdlib.call.optim !0
  %1 = extractvalue %Bool.st %"<.res", 0
  br i1 %1, label %then.0, label %cont.stmt

cont.stmt:                                        ; preds = %entry, %then.0
  %2 = call %Int.st @_Int_i64(i64 1), !stdlib.call.optim !0
  %"<=.res" = call %Bool.st @"_<=_Int_Int"(%Int.st %a, %Int.st %2), !stdlib.call.optim !0
  %3 = extractvalue %Bool.st %"<=.res", 0
  br i1 %3, label %then.02, label %cont.0

then.0:                                           ; preds = %entry
  call void @_fatalError_(), !stdlib.call.optim !0
  br label %cont.stmt

cont.0:                                           ; preds = %cont.stmt
  br label %else.1

then.02:                                          ; preds = %cont.stmt
  %4 = call %Int.st @_Int_i64(i64 1), !stdlib.call.optim !0
  ret %Int.st %4

else.1:                                           ; preds = %cont.0
  %5 = call %Int.st @_Int_i64(i64 1), !stdlib.call.optim !0
  %-.res = call %Int.st @_-_Int_Int(%Int.st %a, %Int.st %5), !stdlib.call.optim !0
  %fib_res = call %Int.st @_fib_Int(%Int.st %-.res)
  %6 = call %Int.st @_Int_i64(i64 2), !stdlib.call.optim !0
  %-.res3 = call %Int.st @_-_Int_Int(%Int.st %a, %Int.st %6), !stdlib.call.optim !0
  %fib_res4 = call %Int.st @_fib_Int(%Int.st %-.res3)
  %"+.res" = call %Int.st @"_+_Int_Int"(%Int.st %fib_res, %Int.st %fib_res4), !stdlib.call.optim !0
  ret %Int.st %"+.res"
}

declare %Int.st @_Int_i64(i64)

declare %Bool.st @"_<_Int_Int"(%Int.st, %Int.st)

declare void @_fatalError_()

declare %Bool.st @"_<=_Int_Int"(%Int.st, %Int.st)

declare %Int.st @_-_Int_Int(%Int.st, %Int.st)

declare %Int.st @"_+_Int_Int"(%Int.st, %Int.st)

declare %Range.st @_..._Int_Int(%Int.st, %Int.st)

declare void @_print_Int(%Int.st)

!0 = !{!"stdlib.call.optim"}
