; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %Int = alloca { i64 }
  store { i64 } %0, { i64 }* %Int
  %w = load { i64 }* %Int
  call void @_print_S.i64({ i64 } %w), !stdlib.call.optim !0
  ret void
}

declare { i64 } @_Int_i64(i64)

declare void @_print_S.i64({ i64 })

!0 = !{!"stdlib.call.optim"}
