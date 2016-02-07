; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  %1 = call { i64 } @_Int_i64(i64 10), !stdlib.call.optim !0
  %StackOf2_res = call { { i64 }, { i64 } } @_StackOf2_S.i64_S.i64({ i64 } %0, { i64 } %1)
  %StackOf2 = alloca { { i64 }, { i64 } }
  store { { i64 }, { i64 } } %StackOf2_res, { { i64 }, { i64 } }* %StackOf2
  %stack = load { { i64 }, { i64 } }* %StackOf2
  %sum.res = call { i64 } @_StackOf2.sum_({ { i64 }, { i64 } } %stack)
  call void @_print_S.i64({ i64 } %sum.res), !stdlib.call.optim !0
  %2 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  %stack1 = load { { i64 }, { i64 } }* %StackOf2
  %push_res = call { { i64 }, { i64 } } @_push_S.i64_S.S.i64.S.i64({ i64 } %2, { { i64 }, { i64 } } %stack1)
  store { { i64 }, { i64 } } %push_res, { { i64 }, { i64 } }* %StackOf2
  %stack2 = load { { i64 }, { i64 } }* %StackOf2
  %pop.res = call { i64 } @_StackOf2.pop_({ { i64 }, { i64 } } %stack2)
  call void @_print_S.i64({ i64 } %pop.res), !stdlib.call.optim !0
  %empty_res = call { { i64 }, { i64 } } @_empty_()
  store { { i64 }, { i64 } } %empty_res, { { i64 }, { i64 } }* %StackOf2
  %a_ptr = getelementptr inbounds { { i64 }, { i64 } }* %StackOf2, i32 0, i32 0
  %a = load { i64 }* %a_ptr
  %b_ptr = getelementptr inbounds { { i64 }, { i64 } }* %StackOf2, i32 0, i32 1
  %b = load { i64 }* %b_ptr
  %"==.res" = call { i1 } @"_==_S.i64_S.i64"({ i64 } %a, { i64 } %b), !stdlib.call.optim !0
  call void @_print_S.b({ i1 } %"==.res"), !stdlib.call.optim !0
  ret void
}

; Function Attrs: alwaysinline
define { { i64 }, { i64 } } @_StackOf2_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") #0 {
entry:
  %StackOf2 = alloca { { i64 }, { i64 } }
  %a_ptr = getelementptr inbounds { { i64 }, { i64 } }* %StackOf2, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %a_ptr
  %b_ptr = getelementptr inbounds { { i64 }, { i64 } }* %StackOf2, i32 0, i32 1
  store { i64 } %"$1", { i64 }* %b_ptr
  %0 = load { { i64 }, { i64 } }* %StackOf2
  ret { { i64 }, { i64 } } %0
}

define internal { i64 } @_StackOf2.sum_({ { i64 }, { i64 } } %self) {
entry:
  %a = extractvalue { { i64 }, { i64 } } %self, 0
  %b = extractvalue { { i64 }, { i64 } } %self, 1
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %a, { i64 } %b), !stdlib.call.optim !0
  ret { i64 } %"+.res"
}

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

define internal { i64 } @_StackOf2.pop_({ { i64 }, { i64 } } %self) {
entry:
  %b = extractvalue { { i64 }, { i64 } } %self, 1
  ret { i64 } %b
}

define internal { { i64 }, { i64 } } @_push_S.i64_S.S.i64.S.i64({ i64 } %val, { { i64 }, { i64 } } %stack) {
entry:
  %b = extractvalue { { i64 }, { i64 } } %stack, 1
  %StackOf2_res = call { { i64 }, { i64 } } @_StackOf2_S.i64_S.i64({ i64 } %b, { i64 } %val)
  ret { { i64 }, { i64 } } %StackOf2_res
}

define internal { { i64 }, { i64 } } @_empty_() {
entry:
  %0 = call { i64 } @_Int_i64(i64 0), !stdlib.call.optim !0
  %1 = call { i64 } @_Int_i64(i64 0), !stdlib.call.optim !0
  %StackOf2_res = call { { i64 }, { i64 } } @_StackOf2_S.i64_S.i64({ i64 } %0, { i64 } %1)
  ret { { i64 }, { i64 } } %StackOf2_res
}

declare { i64 } @_Int_i64(i64)

declare void @_print_S.i64({ i64 })

declare { i1 } @"_==_S.i64_S.i64"({ i64 }, { i64 })

declare void @_print_S.b({ i1 })

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
