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
  %sum.res = call { i64 } @_StackOf2.sum_({ { i64 }, { i64 } }* %stack)
  call void @_print_S.i64({ i64 } %sum.res), !stdlib.call.optim !0
  %stack2 = load { { i64 }, { i64 } }* %stack
  %2 = call { i64 } @_Int_i64(i64 3), !stdlib.call.optim !0
  call void @_StackOf2.push_S.i64({ { i64 }, { i64 } }* %stack, { i64 } %2)
  %stack.bottom.ptr = getelementptr inbounds { { i64 }, { i64 } }* %stack, i32 0, i32 0
  %stack.bottom = load { i64 }* %stack.bottom.ptr
  call void @_print_S.i64({ i64 } %stack.bottom), !stdlib.call.optim !0
  %stack.top.ptr = getelementptr inbounds { { i64 }, { i64 } }* %stack, i32 0, i32 1
  %stack.top = load { i64 }* %stack.top.ptr
  call void @_print_S.i64({ i64 } %stack.top), !stdlib.call.optim !0
  %stack3 = load { { i64 }, { i64 } }* %stack
  %sum.res4 = call { i64 } @_StackOf2.sum_({ { i64 }, { i64 } }* %stack)
  call void @_print_S.i64({ i64 } %sum.res4), !stdlib.call.optim !0
  %stack5 = load { { i64 }, { i64 } }* %stack
  %pop.res = call { i64 } @_StackOf2.pop_({ { i64 }, { i64 } }* %stack)
  call void @_print_S.i64({ i64 } %pop.res), !stdlib.call.optim !0
  %stack6 = load { { i64 }, { i64 } }* %stack
  %pop.res7 = call { i64 } @_StackOf2.pop_({ { i64 }, { i64 } }* %stack)
  call void @_print_S.i64({ i64 } %pop.res7), !stdlib.call.optim !0
  %3 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  %4 = call { i64 } @_Int_i64(i64 4), !stdlib.call.optim !0
  %StackOf2_res8 = call { { i64 }, { i64 } } @_StackOf2_S.i64_S.i64({ i64 } %3, { i64 } %4)
  store { { i64 }, { i64 } } %StackOf2_res8, { { i64 }, { i64 } }* %stack
  %stack.bottom.ptr9 = getelementptr inbounds { { i64 }, { i64 } }* %stack, i32 0, i32 0
  %stack.bottom10 = load { i64 }* %stack.bottom.ptr9
  %stack.top.ptr11 = getelementptr inbounds { { i64 }, { i64 } }* %stack, i32 0, i32 1
  %stack.top12 = load { i64 }* %stack.top.ptr11
  %"==.res" = call { i1 } @"_==_S.i64_S.i64"({ i64 } %stack.bottom10, { i64 } %stack.top12), !stdlib.call.optim !0
  call void @_print_S.b({ i1 } %"==.res"), !stdlib.call.optim !0
  ret void
}

; Function Attrs: alwaysinline
define { { i64 }, { i64 } } @_StackOf2_S.i64_S.i64({ i64 } %"$0", { i64 } %"$1") #0 {
entry:
  %StackOf2 = alloca { { i64 }, { i64 } }
  %StackOf2.bottom.ptr = getelementptr inbounds { { i64 }, { i64 } }* %StackOf2, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %StackOf2.bottom.ptr
  %StackOf2.top.ptr = getelementptr inbounds { { i64 }, { i64 } }* %StackOf2, i32 0, i32 1
  store { i64 } %"$1", { i64 }* %StackOf2.top.ptr
  %StackOf21 = load { { i64 }, { i64 } }* %StackOf2
  ret { { i64 }, { i64 } } %StackOf21
}

define internal { i64 } @_StackOf2.sum_({ { i64 }, { i64 } }* %self) {
entry:
  %self.bottom.ptr = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 0
  %self.bottom = load { i64 }* %self.bottom.ptr
  %self.top.ptr = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 1
  %self.top = load { i64 }* %self.top.ptr
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %self.bottom, { i64 } %self.top), !stdlib.call.optim !0
  ret { i64 } %"+.res"
}

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

define internal { i64 } @_StackOf2.pop_({ { i64 }, { i64 } }* %self) {
entry:
  %self.top.ptr = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 1
  %self.top = load { i64 }* %self.top.ptr
  %v = alloca { i64 }
  store { i64 } %self.top, { i64 }* %v
  %self.bottom.ptr = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 0
  %self.bottom = load { i64 }* %self.bottom.ptr
  %self.top.ptr1 = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 1
  store { i64 } %self.bottom, { i64 }* %self.top.ptr1
  %v2 = load { i64 }* %v
  ret { i64 } %v2
}

define internal void @_StackOf2.push_S.i64({ { i64 }, { i64 } }* %self, { i64 } %val) {
entry:
  %self.top.ptr = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 1
  %self.top = load { i64 }* %self.top.ptr
  %self.bottom.ptr = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 0
  store { i64 } %self.top, { i64 }* %self.bottom.ptr
  %self.top.ptr1 = getelementptr inbounds { { i64 }, { i64 } }* %self, i32 0, i32 1
  store { i64 } %val, { i64 }* %self.top.ptr1
  ret void
}

declare { i64 } @_Int_i64(i64)

declare void @_print_S.i64({ i64 })

declare { i1 } @"_==_S.i64_S.i64"({ i64 }, { i64 })

declare void @_print_S.b({ i1 })

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
