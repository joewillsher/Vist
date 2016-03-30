; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Bool.st = type { i1 }
%Range.st = type { %Int.st, %Int.st }

define %Int.st @fib_Int(%Int.st %a) {
entry:
  %0 = call %Bool.st @-L_Int_Int(%Int.st %a, %Int.st zeroinitializer), !stdlib.call.optim !0
  %1 = extractvalue %Bool.st %0, 0
  br i1 %1, label %if.0, label %exit

if.0:                                             ; preds = %entry
  call void @fatalError_(), !stdlib.call.optim !0
  br label %exit

exit:                                             ; preds = %if.0, %entry
  %2 = call %Bool.st @-L-E_Int_Int(%Int.st %a, %Int.st { i64 1 }), !stdlib.call.optim !0
  %3 = extractvalue %Bool.st %2, 0
  br i1 %3, label %if.01, label %fail.0

if.01:                                            ; preds = %exit
  ret %Int.st { i64 1 }

fail.0:                                           ; preds = %exit
  br label %else.1

else.1:                                           ; preds = %fail.0
  %4 = call %Int.st @-M_Int_Int(%Int.st %a, %Int.st { i64 1 }), !stdlib.call.optim !0
  %5 = call %Int.st @fib_Int(%Int.st %4)
  %6 = call %Int.st @-M_Int_Int(%Int.st %a, %Int.st { i64 2 }), !stdlib.call.optim !0
  %7 = call %Int.st @fib_Int(%Int.st %6)
  %8 = call %Int.st @-P_Int_Int(%Int.st %5, %Int.st %7), !stdlib.call.optim !0
  ret %Int.st %8
}

declare %Bool.st @-L-E_Int_Int(%Int.st, %Int.st)

declare %Bool.st @-L_Int_Int(%Int.st, %Int.st)

declare %Int.st @-P_Int_Int(%Int.st, %Int.st)

declare void @fatalError_()

declare %Int.st @-M_Int_Int(%Int.st, %Int.st)

define void @main() {
entry:
  %0 = call %Range.st @..._Int_Int(%Int.st zeroinitializer, %Int.st { i64 36 }), !stdlib.call.optim !0
  %1 = extractvalue %Range.st %0, 0
  %2 = extractvalue %Range.st %0, 1
  %3 = extractvalue %Int.st %1, 0
  %4 = extractvalue %Int.st %2, 0
  br label %loop

loop:                                             ; preds = %loop, %entry
  %loop.count = phi i64 [ %3, %entry ], [ %count.it, %loop ]
  %5 = insertvalue %Int.st undef, i64 %loop.count, 0
  %6 = call %Int.st @fib_Int(%Int.st %5)
  call void @print_Int(%Int.st %6), !stdlib.call.optim !0
  %count.it = add i64 %loop.count, 1
  %7 = icmp sle i64 %count.it, %4
  br i1 %7, label %loop, label %loop.exit

loop.exit:                                        ; preds = %loop
  ret void
}

declare %Range.st @..._Int_Int(%Int.st, %Int.st)

declare void @print_Int(%Int.st)

!0 = !{!"stdlib.call.optim"}
