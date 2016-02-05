; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %1 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %0, { i64 } %1), !stdlib.call.optim !0
  call void @_print_S.i64({ i64 } %"+.res"), !stdlib.call.optim !0
  %2 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  %3 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  %"*.res" = call { i64 } @"_*_S.i64_S.i64"({ i64 } %2, { i64 } %3), !stdlib.call.optim !0
  call void @_print_S.i64({ i64 } %"*.res"), !stdlib.call.optim !0
  %4 = call { i64 } @_Int_i64(i64 4), !stdlib.call.optim !0
  %5 = call { i64 } @_Int_i64(i64 5), !stdlib.call.optim !0
  %"*.res1" = call { i64 } @"_*_S.i64_S.i64"({ i64 } %4, { i64 } %5), !stdlib.call.optim !0
  %6 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  %-.res = call { i64 } @_-_S.i64_S.i64({ i64 } %"*.res1", { i64 } %6), !stdlib.call.optim !0
  call void @_print_S.i64({ i64 } %-.res), !stdlib.call.optim !0
  %7 = call { i64 } @_Int_i64(i64 13), !stdlib.call.optim !0
  %8 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  %"%.res" = call { i64 } @"_%_S.i64_S.i64"({ i64 } %7, { i64 } %8), !stdlib.call.optim !0
  call void @_print_S.i64({ i64 } %"%.res"), !stdlib.call.optim !0
  ret void
}

declare { i64 } @_Int_i64(i64)

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

declare void @_print_S.i64({ i64 })

declare { i64 } @"_*_S.i64_S.i64"({ i64 }, { i64 })

declare { i64 } @_-_S.i64_S.i64({ i64 }, { i64 })

declare { i64 } @"_%_S.i64_S.i64"({ i64 }, { i64 })

!0 = !{!"stdlib.call.optim"}
