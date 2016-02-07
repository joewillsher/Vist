; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  %1 = call { i64 } @_Int_i64(i64 10), !stdlib.call.optim !0
  %StackOf2_res = call { { i64 }, { i64 } } @_StackOf2_S.i64_S.i64({ i64 } %0, { i64 } %1)
  %stack = alloca { { i64 }, { i64 } }
  store { { i64 }, { i64 } } %StackOf2_res, { { i64 }, { i64 } }* %stack
  %stack1 = load { { i64 }, { i64 } }* %stack
  %pop.res = call { i64 } @_StackOf2.pop_({ { i64 }, { i64 } }* %stack)
  call void @_print_S.i64({ i64 } %pop.res), !stdlib.call.optim !0
  %stack.b.ptr = getelementptr inbounds { { i64 }, { i64 } }* %stack, i32 0, i32 1
  %stack.b = load { i64 }* %stack.b.ptr
  call void @_print_S.i64({ i64 } %stack.b), !stdlib.call.optim !0
  %stack2 = load { { i64 }, { i64 } }* %stack
  %sum.res = call { i64 } @_StackOf2.sum_({ { i64 }, { i64 } }* %stack)
  call void @_print_S.i64({ i64 } %sum.res), !stdlib.call.optim !0
  ret void
}

; Function Attrs: alwaysinline
define { { i64 }, { i64 } } @_StackOf2_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") #0 {
entry:
  %StackOf2 = alloca { { i64 }, { i64 } }
  %StackOf2.a.ptr = getelementptr inbounds { { i64 }, { i64 } }* %StackOf2, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %StackOf2.a.ptr
  %StackOf2.b.ptr = getelementptr inbounds { { i64 }, { i64 } }* %StackOf2, i32 0, i32 1
  store { i64 } %"$1", { i64 }* %StackOf2.b.ptr
  %StackOf21 = load { { i64 }, { i64 } }* %StackOf2
  ret { { i64 }, { i64 } } %StackOf21
}

define internal { i64 } @_StackOf2.sum_({ { i64 }, { i64 } }* %self) {
entry:
  %self.a.ptr = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 0
  %self.a = load { i64 }* %self.a.ptr
  %self.b.ptr = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 1
  %self.b = load { i64 }* %self.b.ptr
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %self.a, { i64 } %self.b), !stdlib.call.optim !0
  ret { i64 } %"+.res"
}

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

define internal { i64 } @_StackOf2.pop_({ { i64 }, { i64 } }* %self) {
entry:
  %self.b.ptr = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 1
  %self.b = load { i64 }* %self.b.ptr
  %v = alloca { i64 }
  store { i64 } %self.b, { i64 }* %v
  %0 = call { i64 } @_Int_i64(i64 0), !stdlib.call.optim !0
  %self.b.ptr1 = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 1
  store { i64 } %0, { i64 }* %self.b.ptr1
  %v2 = load { i64 }* %v
  ret { i64 } %v2
}

declare { i64 } @_Int_i64(i64)

declare void @_print_S.i64({ i64 })

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
