; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int = type { i64 }

define void @main() {
entry:
  call void @print_tInt(%Int { i64 1 }), !stdlib.call.optim !0
  ret void
}

declare void @print_tInt(%Int)

!0 = !{!"stdlib.call.optim"}
