; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  %Int = alloca { i64 }
  store { i64 } %0, { i64 }* %Int
  %a = load { i64 }* %Int
  %1 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  %2 = call { i64 } @_Int_i64(i64 100), !stdlib.call.optim !0
  %"*.res" = call { i64 } @"_*_S.i64_S.i64"({ i64 } %1, { i64 } %2), !stdlib.call.optim !0
  %"<.res" = call { i1 } @"_<_S.i64_S.i64"({ i64 } %a, { i64 } %"*.res"), !stdlib.call.optim !0
  %value = extractvalue { i1 } %"<.res", 0
  br i1 %value, label %then.0, label %cont.stmt

cont.stmt:                                        ; preds = %entry, %then.0
  ret void

then.0:                                           ; preds = %entry
  %3 = call { i64 } @_Int_i64(i64 100), !stdlib.call.optim !0
  call void @_print_S.i64({ i64 } %3), !stdlib.call.optim !0
  br label %cont.stmt
}

declare { i64 } @_Int_i64(i64)

declare { i64 } @"_*_S.i64_S.i64"({ i64 }, { i64 })

declare { i1 } @"_<_S.i64_S.i64"({ i64 }, { i64 })

declare void @_print_S.i64({ i64 })

!0 = !{!"stdlib.call.optim"}
