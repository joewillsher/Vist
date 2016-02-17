; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Range.st = type { %Int.st, %Int.st }

define void @main() {
entry:
  %0 = call %Int.st @_Int_i64(i64 0), !stdlib.call.optim !0
  %1 = call %Int.st @_Int_i64(i64 3), !stdlib.call.optim !0
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
  call void @_print_Int(%Int.st %i), !stdlib.call.optim !0
  br label %loop.latch

loop.latch:                                       ; preds = %loop.body
  %loop.repeat.test = icmp sle i64 %next.i, %end.value
  br i1 %loop.repeat.test, label %loop.header, label %loop.exit

loop.exit:                                        ; preds = %loop.latch
  %2 = call %Int.st @_Int_i64(i64 1), !stdlib.call.optim !0
  %x = alloca %Int.st
  store %Int.st %2, %Int.st* %x
  %3 = call %Int.st @_Int_i64(i64 2), !stdlib.call.optim !0
  %4 = call %Int.st @_Int_i64(i64 5), !stdlib.call.optim !0
  %"..<.res" = call %Range.st @"_..<_Int_Int"(%Int.st %3, %Int.st %4), !stdlib.call.optim !0
  %start5 = extractvalue %Range.st %"..<.res", 0
  %start.value6 = extractvalue %Int.st %start5, 0
  %end7 = extractvalue %Range.st %"..<.res", 1
  %end.value8 = extractvalue %Int.st %end7, 0
  br label %loop.header1

loop.header1:                                     ; preds = %loop.latch3, %loop.exit
  %loop.count.i9 = phi i64 [ %start.value6, %loop.exit ], [ %next.i10, %loop.latch3 ]
  %next.i10 = add i64 1, %loop.count.i9
  %i11 = call %Int.st @_Int_i64(i64 %loop.count.i9), !stdlib.call.optim !0
  br label %loop.body2

loop.body2:                                       ; preds = %loop.header1
  %x12 = load %Int.st* %x
  %"*.res" = call %Int.st @"_*_Int_Int"(%Int.st %i11, %Int.st %x12), !stdlib.call.optim !0
  call void @_print_Int(%Int.st %"*.res"), !stdlib.call.optim !0
  %x13 = load %Int.st* %x
  %5 = call %Int.st @_Int_i64(i64 1), !stdlib.call.optim !0
  %"+.res" = call %Int.st @"_+_Int_Int"(%Int.st %x13, %Int.st %5), !stdlib.call.optim !0
  store %Int.st %"+.res", %Int.st* %x
  br label %loop.latch3

loop.latch3:                                      ; preds = %loop.body2
  %loop.repeat.test14 = icmp sle i64 %next.i10, %end.value8
  br i1 %loop.repeat.test14, label %loop.header1, label %loop.exit4

loop.exit4:                                       ; preds = %loop.latch3
  ret void
}

declare %Int.st @_Int_i64(i64)

declare %Range.st @_..._Int_Int(%Int.st, %Int.st)

declare void @_print_Int(%Int.st)

declare %Range.st @"_..<_Int_Int"(%Int.st, %Int.st)

declare %Int.st @"_*_Int_Int"(%Int.st, %Int.st)

declare %Int.st @"_+_Int_Int"(%Int.st, %Int.st)

!0 = !{!"stdlib.call.optim"}
