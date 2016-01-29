; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define i64 @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 8), !stdlib.call.optim !0
  %fact_res = call { i64 } @_fact_S.i64({ i64 } %0)
  %1 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %2 = call { i64 } @_Int_i64(i64 4), !stdlib.call.optim !0
  %foo_res = call { i64 } @_foo_S.i64_S.i64({ i64 } %1, { i64 } %2)
  %foo_res1 = call { i64 } @_foo_S.i64_S.i64({ i64 } %fact_res, { i64 } %foo_res)
  call void @_print_S.i64({ i64 } %foo_res1), !stdlib.call.optim !0
  ret i64 0
}

define { i64 } @_foo_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") {
entry:
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %"$0", { i64 } %"$1"), !stdlib.call.optim !0
  ret { i64 } %"+.res"
}

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

define { i64 } @_fact_S.i64({ i64 } %a) {
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
