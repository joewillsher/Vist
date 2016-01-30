; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 2), !stdlib.call.optim !0
  %Foo_res = call { { i64 } } @_Foo_S.i64({ i64 } %0)
  %1 = alloca { { i64 } }
  store { { i64 } } %Foo_res, { { i64 } }* %1
  ret void
}

; Function Attrs: alwaysinline
define { { i64 } } @_Foo_S.i64({ i64 } %w) #0 {
entry:
  %0 = alloca { { i64 } }
  %a_ptr = getelementptr inbounds { { i64 } }* %0, i32 0, i32 0
  store { i64 } %w, { i64 }* %a_ptr
  %a_ptr1 = getelementptr inbounds { { i64 } }* %0, i32 0, i32 0
  %a = load { i64 }* %a_ptr1
  call void @_print_S.i64({ i64 } %a), !stdlib.call.optim !0
  %1 = load { { i64 } }* %0
  ret { { i64 } } %1
}

declare void @_print_S.i64({ i64 })

; Function Attrs: alwaysinline
define { { i64 } } @_Foo_S.i641({ i64 } %"$0") #0 {
entry:
  %0 = alloca { { i64 } }
  %a_ptr = getelementptr inbounds { { i64 } }* %0, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %a_ptr
  %1 = load { { i64 } }* %0
  ret { { i64 } } %1
}

declare { i64 } @_Int_i64(i64)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
