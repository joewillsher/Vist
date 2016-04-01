; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Bool.st = type { i1 }

declare %Int.st @-A_Int_Int(%Int.st, %Int.st)

declare void @print_Bool(%Bool.st)

declare %Bool.st @-G_Int_Int(%Int.st, %Int.st)

declare %Bool.st @-L_Int_Int(%Int.st, %Int.st)

declare void @print_Int(%Int.st)

define void @main() {
entry:
  %a = alloca %Int.st
  store %Int.st { i64 3 }, %Int.st* %a
  %0 = call %Int.st @-A_Int_Int(%Int.st { i64 2 }, %Int.st { i64 100 }), !stdlib.call.optim !0
  %1 = call %Bool.st @-L_Int_Int(%Int.st { i64 3 }, %Int.st %0), !stdlib.call.optim !0
  %2 = extractvalue %Bool.st %1, 0
  br i1 %2, label %if.0, label %exit

if.0:                                             ; preds = %entry
  call void @print_Int(%Int.st { i64 100 }), !stdlib.call.optim !0
  br label %exit

exit:                                             ; preds = %if.0, %entry
  %3 = call %Bool.st @-G_Int_Int(%Int.st { i64 3 }, %Int.st { i64 4 }), !stdlib.call.optim !0
  %4 = extractvalue %Bool.st %3, 0
  br i1 %4, label %if.01, label %fail.0

if.01:                                            ; preds = %exit
  call void @print_Int(%Int.st { i64 1 }), !stdlib.call.optim !0
  br label %exit2

fail.0:                                           ; preds = %exit
  %5 = call %Bool.st @-E-E_Int_Int(%Int.st { i64 3 }, %Int.st { i64 3 }), !stdlib.call.optim !0
  %6 = extractvalue %Bool.st %5, 0
  br i1 %6, label %if.1, label %exit2

if.1:                                             ; preds = %fail.0
  call void @print_Int(%Int.st { i64 11 }), !stdlib.call.optim !0
  br label %exit2

exit2:                                            ; preds = %if.1, %fail.0, %if.01
  br i1 false, label %if.03, label %fail.04

if.03:                                            ; preds = %exit2
  call void @print_Int(%Int.st { i64 1 }), !stdlib.call.optim !0
  br label %exit6

fail.04:                                          ; preds = %exit2
  br i1 false, label %if.15, label %fail.1

if.15:                                            ; preds = %fail.04
  call void @print_Bool(%Bool.st zeroinitializer), !stdlib.call.optim !0
  br label %exit6

fail.1:                                           ; preds = %fail.04
  br label %else.2

else.2:                                           ; preds = %fail.1
  call void @print_Int(%Int.st { i64 20 }), !stdlib.call.optim !0
  br label %exit6

exit6:                                            ; preds = %else.2, %if.15, %if.03
  ret void
}

declare %Bool.st @-E-E_Int_Int(%Int.st, %Int.st)

!0 = !{!"stdlib.call.optim"}
