; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %factorial_res = call { i64 } @_factorial_S.i64({ i64 } %0)
  call void @_print_S.i64({ i64 } %factorial_res), !stdlib.call.optim !0
  %1 = call { i64 } @_Int_i64(i64 10), !stdlib.call.optim !0
  %factorial_res1 = call { i64 } @_factorial_S.i64({ i64 } %1)
  call void @_print_S.i64({ i64 } %factorial_res1), !stdlib.call.optim !0
  %2 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %3 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %2, { i64 } %3), !stdlib.call.optim !0
  %factorial_res2 = call { i64 } @_factorial_S.i64({ i64 } %"+.res")
  call void @_print_S.i64({ i64 } %factorial_res2), !stdlib.call.optim !0
  %4 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  %dupe_res = call { { i64 }, { i64 } } @_dupe_S.i64({ i64 } %4)
  %tuple = alloca { { i64 }, { i64 } }
  store { { i64 }, { i64 } } %dupe_res, { { i64 }, { i64 } }* %tuple
  %"0_ptr" = getelementptr inbounds { { i64 }, { i64 } }* %tuple, i32 0, i32 0
  %"0" = load { i64 }* %"0_ptr"
  %"1_ptr" = getelementptr inbounds { { i64 }, { i64 } }* %tuple, i32 0, i32 1
  %"1" = load { i64 }* %"1_ptr"
  %"+.res3" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %"0", { i64 } %"1"), !stdlib.call.optim !0
  %factorial_res4 = call { i64 } @_factorial_S.i64({ i64 } %"+.res3")
  %Int = alloca { i64 }
  store { i64 } %factorial_res4, { i64 }* %Int
  %w = load { i64 }* %Int
  call void @_print_S.i64({ i64 } %w), !stdlib.call.optim !0
  %5 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  %factorial_res5 = call { i64 } @_factorial_S.i64({ i64 } %5)
  %factorial_res6 = call { i64 } @_factorial_S.i64({ i64 } %factorial_res5)
  call void @_print_S.i64({ i64 } %factorial_res6), !stdlib.call.optim !0
  call void @_void_()
  %two_res = call { i64 } @_two_()
  call void @_print_S.i64({ i64 } %two_res), !stdlib.call.optim !0
  ret void
}

define internal { { i64 }, { i64 } } @_dupe_S.i64({ i64 } %a) {
entry:
  %tuple = alloca { { i64 }, { i64 } }
  %"0_ptr" = getelementptr inbounds { { i64 }, { i64 } }* %tuple, i32 0, i32 0
  store { i64 } %a, { i64 }* %"0_ptr"
  %"1_ptr" = getelementptr inbounds { { i64 }, { i64 } }* %tuple, i32 0, i32 1
  store { i64 } %a, { i64 }* %"1_ptr"
  %0 = load { { i64 }, { i64 } }* %tuple
  ret { { i64 }, { i64 } } %0
}

define internal { i64 } @_factorial_S.i64({ i64 } %a) {
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
  %factorial_res = call { i64 } @_factorial_S.i64({ i64 } %-.res)
  %"*.res" = call { i64 } @"_*_S.i64_S.i64"({ i64 } %a, { i64 } %factorial_res), !stdlib.call.optim !0
  ret { i64 } %"*.res"
}

declare { i64 } @_Int_i64(i64)

declare { i1 } @"_<=_S.i64_S.i64"({ i64 }, { i64 })

declare { i64 } @_-_S.i64_S.i64({ i64 }, { i64 })

declare { i64 } @"_*_S.i64_S.i64"({ i64 }, { i64 })

declare void @_print_S.i64({ i64 })

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

define internal void @_void_() {
entry:
  %0 = call { i64 } @_Int_i64(i64 41), !stdlib.call.optim !0
  call void @_print_S.i64({ i64 } %0), !stdlib.call.optim !0
  ret void
}

define internal { i64 } @_two_() {
entry:
  %0 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  ret { i64 } %0
}

!0 = !{!"stdlib.call.optim"}
