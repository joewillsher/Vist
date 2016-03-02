; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

define void @main() {
entry:
  %0 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %a = alloca %Int.st
  store %Int.st %0, %Int.st* %a
  ret void
}

declare %Int.st @Int_i64(i64)

!0 = !{!"stdlib.call.optim"}
