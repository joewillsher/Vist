; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

define void @main() {
entry:
  call void @void_()
  %0 = call %Int.st @two_()
  call void @print_Int(%Int.st %0), !stdlib.call.optim !0
  ret void
}

define void @void_() {
entry:
  call void @print_Int(%Int.st { i64 41 }), !stdlib.call.optim !0
  ret void
}

declare void @print_Int(%Int.st)

define %Int.st @two_() {
entry:
  ret %Int.st { i64 2 }
}

!0 = !{!"stdlib.call.optim"}
