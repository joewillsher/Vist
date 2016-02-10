; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64 } @_Int_i64(i64 1), !stdlib.call.optim !0
  %Bar_res = call { { i64 } } @_Bar_S.i64({ i64 } %0)
  %bar = alloca { { i64 } }
  store { { i64 } } %Bar_res, { { i64 } }* %bar
  ret void
}

define internal { i64 } @_foo_Eq_S.i64({ [1 x i32], i8* } %a, { i64 } %b) {
entry:
  %a1 = alloca { [1 x i32], i8* }
  store { [1 x i32], i8* } %a, { [1 x i32], i8* }* %a1
  %a.metadata_ptr = getelementptr inbounds { [1 x i32], i8* }* %a1, i32 0, i32 0
  %metadata_arr_el_ptr = getelementptr [1 x i32]* %a.metadata_ptr, i32 0
  %self_index = load [1 x i32]* %metadata_arr_el_ptr
  %a.element_pointer = getelementptr inbounds { [1 x i32], i8* }* %a1, i32 0, i32 1
  %a.opaque_instance_pointer = load i8** %a.element_pointer
  %member_pointer = getelementptr i8* %a.opaque_instance_pointer, [1 x i32] %self_index
  %a.ptr = bitcast i8* %member_pointer to { i64 }*
  %a2 = load { i64 }* %a.ptr
  %"+.res" = call { i64 } @"_+_S.i64_S.i64"({ i64 } %a2, { i64 } %b), !stdlib.call.optim !0
  ret { i64 } %"+.res"
}

declare { i64 } @"_+_S.i64_S.i64"({ i64 }, { i64 })

; Function Attrs: alwaysinline
define { { i64 } } @_Bar_S.i64({ i64 } %"$0") #0 {
entry:
  %Bar = alloca { { i64 } }
  %Bar.a.ptr = getelementptr inbounds { { i64 } }* %Bar, i32 0, i32 0
  store { i64 } %"$0", { i64 }* %Bar.a.ptr
  %Bar1 = load { { i64 } }* %Bar
  ret { { i64 } } %Bar1
}

declare { i64 } @_Int_i64(i64)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
