; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

define void @main() {
entry:
  %0 = call %Int.st @factorial_Int(%Int.st { i64 4 })
  call void @print_Int(%Int.st %0), !stdlib.call.optim !0
  ret void
}

define %Int.st @factorial_Int(%Int.st) {
entry:
}

declare void @print_Int(%Int.st)

!0 = !{!"stdlib.call.optim"}
