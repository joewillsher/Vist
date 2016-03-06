; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

define void @main() {
entry:
  %a = alloca { %Int.st, %Int.st }
  store { %Int.st, %Int.st } { %Int.st { i64 1 }, %Int.st { i64 1 } }, { %Int.st, %Int.st }* %a
  %b = alloca %Int.st
  store %Int.st { i64 1 }, %Int.st* %b
  call void @print_Int(%Int.st { i64 1 }), !stdlib.call.optim !0
  call void @print_Int(%Int.st { i64 22 }), !stdlib.call.optim !0
  ret void
}

declare void @print_Int(%Int.st)

!0 = !{!"stdlib.call.optim"}
