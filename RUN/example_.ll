; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bool.st = type { i1 }
%Int.st = type { i64 }

define void @main() {
entry:
  br i1 true, label %if.0, label %fail.0

exit:                                             ; preds = %if.1, %fail.0
  call void @print_Bool(%Bool.st zeroinitializer), !stdlib.call.optim !0
  ret void

if.0:                                             ; preds = %entry
  call void @print_Int(%Int.st { i64 1 }), !stdlib.call.optim !0
  br label %fail.0

fail.0:                                           ; preds = %if.0, %entry
  br i1 true, label %if.1, label %exit

if.1:                                             ; preds = %fail.0
  call void @print_Int(%Int.st { i64 2 }), !stdlib.call.optim !0
  br label %exit
}

declare void @print_Int(%Int.st)

declare void @print_Bool(%Bool.st)

!0 = !{!"stdlib.call.optim"}
