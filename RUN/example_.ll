; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

define void @main() {
entry:
  br label %cond

cond:                                             ; preds = %loop, %entry
  br i1 false, label %loop, label %loop.exit

loop:                                             ; preds = %cond
  call void @print_Int(%Int.st { i64 1 }), !stdlib.call.optim !0
  br label %cond

loop.exit:                                        ; preds = %cond
  ret void
}

declare void @print_Int(%Int.st)

!0 = !{!"stdlib.call.optim"}
