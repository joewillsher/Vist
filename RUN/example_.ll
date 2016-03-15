; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bool.st = type { i1 }
%Int.st = type { i64 }

define void @main() {
entry:
  %0 = call %Bool.st @-L_Int_Int(%Int.st { i64 1 }, %Int.st { i64 2 }), !stdlib.call.optim !0
  %1 = extractvalue %Bool.st %0, 0
  br i1 %1, label %if.0, label %exit

if.0:                                             ; preds = %entry
  call void @print_Int(%Int.st { i64 1100 }), !stdlib.call.optim !0
  br label %exit

exit:                                             ; preds = %if.0, %entry
  ret void
}

declare %Bool.st @-L_Int_Int(%Int.st, %Int.st)

declare void @print_Int(%Int.st)

!0 = !{!"stdlib.call.optim"}
