; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

define void @main() {
entry:
  %0 = call %Int.st @factorial_Int(%Int.st { i64 1 })
  call void @print_Int(%Int.st %0), !stdlib.call.optim !0
  %1 = call %Int.st @factorial_Int(%Int.st { i64 10 })
  call void @print_Int(%Int.st %1), !stdlib.call.optim !0
  %2 = call %Int.st @-P_Int_Int(%Int.st { i64 1 }, %Int.st { i64 3 }), !stdlib.call.optim !0
  %3 = call %Int.st @factorial_Int(%Int.st %2)
  call void @print_Int(%Int.st %3), !stdlib.call.optim !0
  %4 = call { %Int.st, %Int.st } @dupe_Int(%Int.st { i64 2 })
  %dupe = alloca { %Int.st, %Int.st }
  store { %Int.st, %Int.st } %4, { %Int.st, %Int.st }* %dupe
  %5 = extractvalue { %Int.st, %Int.st } %4, 0
  %6 = extractvalue { %Int.st, %Int.st } %4, 1
  %7 = call %Int.st @-P_Int_Int(%Int.st %5, %Int.st %6), !stdlib.call.optim !0
  %8 = call %Int.st @factorial_Int(%Int.st %7)
  %w = alloca %Int.st
  store %Int.st %8, %Int.st* %w
  call void @print_Int(%Int.st %8), !stdlib.call.optim !0
  %9 = call %Int.st @factorial_Int(%Int.st { i64 3 })
  %10 = call %Int.st @factorial_Int(%Int.st %9)
  call void @print_Int(%Int.st %10), !stdlib.call.optim !0
  call void @void_()
  %11 = call %Int.st @two_()
  call void @print_Int(%Int.st %11), !stdlib.call.optim !0
  ret void
}

define { %Int.st, %Int.st } @dupe_Int(%Int.st) {
entry:
  %1 = insertvalue { %Int.st, %Int.st } undef, %Int.st %0, 0
  %2 = insertvalue { %Int.st, %Int.st } %1, %Int.st %0, 1
  ret { %Int.st, %Int.st } %2
}

define %Int.st @factorial_Int(%Int.st) {
entry:
}

declare void @print_Int(%Int.st)

declare %Int.st @-P_Int_Int(%Int.st, %Int.st)

define void @void_() {
entry:
  call void @print_Int(%Int.st { i64 41 }), !stdlib.call.optim !0
}

define %Int.st @two_() {
entry:
  ret %Int.st { i64 2 }
}

!0 = !{!"stdlib.call.optim"}
