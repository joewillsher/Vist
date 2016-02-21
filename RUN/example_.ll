; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

define void @main() {
entry:
  %0 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %1 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %2 = alloca { %Int.st, %Int.st }
  %.0.ptr = getelementptr inbounds { %Int.st, %Int.st }* %2, i32 0, i32 0
  store %Int.st %0, %Int.st* %.0.ptr
  %.1.ptr = getelementptr inbounds { %Int.st, %Int.st }* %2, i32 0, i32 1
  store %Int.st %1, %Int.st* %.1.ptr
  %3 = load { %Int.st, %Int.st }* %2
  %t = alloca { %Int.st, %Int.st }
  store { %Int.st, %Int.st } %3, { %Int.st, %Int.st }* %t
  ret void
}

declare %Int.st @Int_i64(i64)

!0 = !{!"stdlib.call.optim"}
