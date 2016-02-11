; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.ty = type { i64 }
%Bar.ty = type { %Int.ty }
%Eq.ex.ty = type { [1 x i32], i8* }

define void @main() {
entry:
  %0 = call %Int.ty @_Int_i64(i64 1), !stdlib.call.optim !0
  %Bar_res = call %Bar.ty @_Bar_Int(%Int.ty %0)
  %bar = alloca %Bar.ty
  store %Bar.ty %Bar_res, %Bar.ty* %bar
  %bar1 = load %Bar.ty* %bar
  %1 = call %Int.ty @_Int_i64(i64 2), !stdlib.call.optim !0
  %2 = alloca %Eq.ex.ty
  %.metadata = getelementptr inbounds %Eq.ex.ty* %2, i32 0, i32 0
  %.opaque = getelementptr inbounds %Eq.ex.ty* %2, i32 0, i32 1
  %3 = alloca %Bar.ty
  %4 = alloca [1 x i32], i32 0
  %5 = load [1 x i32]* %4
  store [1 x i32] %5, [1 x i32]* %.metadata
  store %Bar.ty %bar1, %Bar.ty* %3
  %6 = bitcast %Bar.ty* %3 to i8*
  store i8* %6, i8** %.opaque
  %7 = load %Eq.ex.ty* %2
  %foo_res = call %Int.ty @_foo_Eq_Int(%Eq.ex.ty %7, %Int.ty %1)
  %foo = alloca %Int.ty
  store %Int.ty %foo_res, %Int.ty* %foo
  %foo2 = load %Int.ty* %foo
  call void @_print_Int(%Int.ty %foo2), !stdlib.call.optim !0
  ret void
}

define %Int.ty @_foo_Eq_Int(%Eq.ex.ty %a, %Int.ty %b) {
entry:
  %a1 = alloca %Eq.ex.ty
  store %Eq.ex.ty %a, %Eq.ex.ty* %a1
  %a.metadata_ptr = getelementptr inbounds %Eq.ex.ty* %a1, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %a.metadata_ptr to i32*
  %metadata_arr_el_ptr = getelementptr i32* %metadata_base_ptr, i32 0
  %self_index = load i32* %metadata_arr_el_ptr
  %a.element_pointer = getelementptr inbounds %Eq.ex.ty* %a1, i32 0, i32 1
  %a.opaque_instance_pointer = load i8** %a.element_pointer
  %member_pointer = getelementptr i8* %a.opaque_instance_pointer, i32 %self_index
  %a.ptr = bitcast i8* %member_pointer to %Int.ty*
  %a2 = load %Int.ty* %a.ptr
  %"+.res" = call %Int.ty @"_+_Int_Int"(%Int.ty %a2, %Int.ty %b), !stdlib.call.optim !0
  ret %Int.ty %"+.res"
}

declare %Int.ty @"_+_Int_Int"(%Int.ty, %Int.ty)

; Function Attrs: alwaysinline
define %Bar.ty @_Bar_Int(%Int.ty %"$0") #0 {
entry:
  %Bar = alloca %Bar.ty
  %Bar.a.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 0
  store %Int.ty %"$0", %Int.ty* %Bar.a.ptr
  %Bar1 = load %Bar.ty* %Bar
  ret %Bar.ty %Bar1
}

declare %Int.ty @_Int_i64(i64)

declare void @_print_Int(%Int.ty)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
