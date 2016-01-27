; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define i64 @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  %1 = alloca { i64 }
  store { i64 } %0, { i64 }* %1
  %a = load { i64 }* %1
  call void @_print_S.i64({ i64 } %a), !stdlib.call.optim !0
  ret i64 0
}

declare { i64 } @_Int_i64(i64)

declare void @_print_S.i64({ i64 })

!0 = !{!"stdlib.call.optim"}
