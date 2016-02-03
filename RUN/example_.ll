; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %StackOf2_res = call { { i64 } } @_StackOf2_S.i64({ i64 } %0)
  %StackOf2 = alloca { { i64 } }
  store { { i64 } } %StackOf2_res, { { i64 } }* %StackOf2
  %a = load { { i64 } }* %StackOf2
  %sum.res = call { i64 } @_StackOf2.sum_({ { i64 } } %a)
  %Int = alloca { i64 }
  store { i64 } %sum.res, { i64 }* %Int
  %q = load { i64 }* %Int
  call void @_print_S.i64({ i64 } %q), !stdlib.call.optim !0
  ret void
}

; Function Attrs: alwaysinline
define { { i64 } } @_StackOf2_S.i64({ i64 } %"$0") #0 {
entry:
  %StackOf2 = alloca { { i64 } }
  %a_ptr = getelementptr inbounds { { i64 } }* %StackOf2, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %a_ptr
  %0 = load { { i64 } }* %StackOf2
  ret { { i64 } } %0
}

define internal { i64 } @_StackOf2.sum_({ { i64 } } %self) {
entry:
  %a = extractvalue { { i64 } } %self, 0
  ret { i64 } %a
}

declare { i64 } @_Int_i64(i64)

declare void @_print_S.i64({ i64 })

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
