; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

define void @main() {
entry:
  br i1 true, label %if.0, label %exit

if.0:                                             ; preds = %entry
  call void @print_Int(%Int.st { i64 3 }), !stdlib.call.optim !0
  br label %exit

exit:                                             ; preds = %if.0, %entry
  %0 = call %Int.st @foo_Int(%Int.st { i64 1 })
  call void @print_Int(%Int.st %0), !stdlib.call.optim !0
  ret void
}

declare void @print_Int(%Int.st)

define %Int.st @foo_Int(%Int.st) {
entry:
  ret %Int.st %0
}

!0 = !{!"stdlib.call.optim"}
