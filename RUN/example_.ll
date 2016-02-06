; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %Bar_res = call { { i64 } } @_Bar_S.i64({ i64 } %0)
  %Foo_res = call { { { i64 } } } @_Foo_S.S.i64({ { i64 } } %Bar_res)
  %Foo = alloca { { { i64 } } }
  store { { { i64 } } } %Foo_res, { { { i64 } } }* %Foo
  %bar_ptr = getelementptr inbounds { { { i64 } } }* %Foo, i32 0, i32 0
  %bar = load { { i64 } }* %bar_ptr
  %bar.a = extractvalue { { i64 } } %bar, 0
  call void @_print_S.i64({ i64 } %bar.a), !stdlib.call.optim !0
  ret void
}

; Function Attrs: alwaysinline
define { { i64 } } @_Bar_S.i64({ i64 } %"$0") #0 {
entry:
  %Bar = alloca { { i64 } }
  %a_ptr = getelementptr inbounds { { i64 } }* %Bar, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %a_ptr
  %0 = load { { i64 } }* %Bar
  ret { { i64 } } %0
}

; Function Attrs: alwaysinline
define { { { i64 } } } @_Foo_S.S.i64({ { i64 } } %"$0") #0 {
entry:
  %Foo = alloca { { { i64 } } }
  %bar_ptr = getelementptr inbounds { { { i64 } } }* %Foo, i32 0, i32 0
  store { { i64 } } %"$0", { { i64 } }* %bar_ptr
  %0 = load { { { i64 } } }* %Foo
  ret { { { i64 } } } %0
}

declare { i64 } @_Int_i64(i64)

declare void @_print_S.i64({ i64 })

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
