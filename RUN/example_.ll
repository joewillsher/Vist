; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 20), !stdlib.call.optim !0
  %fact_res = call { i64 } @_fact_S.i64({ i64 } %0)
  call void @_print_S.i64({ i64 } %fact_res), !stdlib.call.optim !0
  %1 = call { i64 } @_Int_i64(i64 4), !stdlib.call.optim !0
  %2 = alloca { i64 }
  store { i64 } %1, { i64 }* %2
  %a = load { i64 }* %2
  %3 = call { i64 } @_Int_i64(i64 6), !stdlib.call.optim !0
  %"*.res" = call { i64 } @"_*_S.i64_S.i64"({ i64 } %a, { i64 } %3), !stdlib.call.optim !0
  %4 = alloca { i64 }
  store { i64 } %"*.res", { i64 }* %4
  %b = load { i64 }* %4
  call void @_print_S.i64({ i64 } %b), !stdlib.call.optim !0
  ret void
}

define internal { i64 } @_fact_S.i64({ i64 } %a) {
entry:
  %0 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %"<=.res" = call { i1 } @"_<=_S.i64_S.i64"({ i64 } %a, { i64 } %0), !stdlib.call.optim !0
  %value = extractvalue { i1 } %"<=.res", 0
  br i1 %value, label %then.0, label %cont.0

cont.0:                                           ; preds = %entry
  br label %else.1

then.0:                                           ; preds = %entry
  %1 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  ret { i64 } %1

else.1:                                           ; preds = %cont.0
  %2 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %-.res = call { i64 } @_-_S.i64_S.i64({ i64 } %a, { i64 } %2), !stdlib.call.optim !0
  %fact_res = call { i64 } @_fact_S.i64({ i64 } %-.res)
  %"*.res" = call { i64 } @"_*_S.i64_S.i64"({ i64 } %a, { i64 } %fact_res), !stdlib.call.optim !0
  ret { i64 } %"*.res"
}

declare { i64 } @_Int_i64(i64)

declare { i1 } @"_<=_S.i64_S.i64"({ i64 }, { i64 })

declare { i64 } @_-_S.i64_S.i64({ i64 }, { i64 })

declare { i64 } @"_*_S.i64_S.i64"({ i64 }, { i64 })

declare void @_print_S.i64({ i64 })

!0 = !{!"stdlib.call.optim"}
