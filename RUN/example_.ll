; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.ty = type { i64 }
%Bar.ty = type { %Int.ty, %Int.ty }
%Eq.ex.ty = type { [2 x i32], i8* }

define void @main() {
entry:
  %0 = call %Int.ty @_Int_i64(i64 11), !stdlib.call.optim !0
  %1 = call %Int.ty @_Int_i64(i64 4), !stdlib.call.optim !0
  %Bar_res = call %Bar.ty @_Bar_Int_Int(%Int.ty %0, %Int.ty %1)
  %bar = alloca %Bar.ty
  store %Bar.ty %Bar_res, %Bar.ty* %bar
  %bar1 = load %Bar.ty* %bar
  %2 = call %Int.ty @_Int_i64(i64 2), !stdlib.call.optim !0
  %3 = alloca %Eq.ex.ty
  %.metadata = getelementptr inbounds %Eq.ex.ty* %3, i32 0, i32 0
  %.opaque = getelementptr inbounds %Eq.ex.ty* %3, i32 0, i32 1
  %4 = alloca %Bar.ty
  %metadata = alloca [2 x i32]
  %5 = bitcast [2 x i32]* %metadata to i32*
  %el.0 = getelementptr [2 x i32]* %metadata, i32 0
  %el.ptr.0 = bitcast [2 x i32]* %el.0 to i32*
  store i32 8, i32* %el.ptr.0
  %el.1 = getelementptr [2 x i32]* %metadata, i32 1
  %el.ptr.1 = bitcast [2 x i32]* %el.1 to i32*
  store i32 0, i32* %el.ptr.1
  %6 = load [2 x i32]* %metadata
  store [2 x i32] %6, [2 x i32]* %.metadata
  store %Bar.ty %bar1, %Bar.ty* %4
  %7 = bitcast %Bar.ty* %4 to i8*
  store i8* %7, i8** %.opaque
  %8 = load %Eq.ex.ty* %3
  %foo_res = call %Int.ty @_foo_Eq_Int(%Eq.ex.ty %8, %Int.ty %2)
  %foo = alloca %Int.ty
  store %Int.ty %foo_res, %Int.ty* %foo
  %foo2 = load %Int.ty* %foo
  call void @_print_Int(%Int.ty %foo2), !stdlib.call.optim !0
  ret void
}

define internal %Int.ty @_foo_Eq_Int(%Eq.ex.ty %a, %Int.ty %b) {
entry:
  %a1 = alloca %Eq.ex.ty
  store %Eq.ex.ty %a, %Eq.ex.ty* %a1
  %a.metadata_ptr = getelementptr inbounds %Eq.ex.ty* %a1, i32 0, i32 0
  %metadata_base_ptr = bitcast [2 x i32]* %a.metadata_ptr to i32*
  %0 = getelementptr i32* %metadata_base_ptr, i32 0
  %1 = load i32* %0
  %a.element_pointer = getelementptr inbounds %Eq.ex.ty* %a1, i32 0, i32 1
  %a.opaque_instance_pointer = load i8** %a.element_pointer
  %2 = getelementptr i8* %a.opaque_instance_pointer, i32 %1
  %a.ptr = bitcast i8* %2 to %Int.ty*
  %a2 = load %Int.ty* %a.ptr
  %a.metadata_ptr3 = getelementptr inbounds %Eq.ex.ty* %a1, i32 0, i32 0
  %metadata_base_ptr4 = bitcast [2 x i32]* %a.metadata_ptr3 to i32*
  %3 = getelementptr i32* %metadata_base_ptr4, i32 1
  %4 = load i32* %3
  %a.element_pointer5 = getelementptr inbounds %Eq.ex.ty* %a1, i32 0, i32 1
  %a.opaque_instance_pointer6 = load i8** %a.element_pointer5
  %5 = getelementptr i8* %a.opaque_instance_pointer6, i32 %4
  %b.ptr = bitcast i8* %5 to %Int.ty*
  %b7 = load %Int.ty* %b.ptr
  %"+.res" = call %Int.ty @"_+_Int_Int"(%Int.ty %b, %Int.ty %b7), !stdlib.call.optim !0
  %"+.res8" = call %Int.ty @"_+_Int_Int"(%Int.ty %a2, %Int.ty %"+.res"), !stdlib.call.optim !0
  ret %Int.ty %"+.res8"
}

declare %Int.ty @"_+_Int_Int"(%Int.ty, %Int.ty)

; Function Attrs: alwaysinline
define %Bar.ty @_Bar_Int_Int(%Int.ty %"$0", %Int.ty %"$1") #0 {
entry:
  %Bar = alloca %Bar.ty
  %Bar.b.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 0
  store %Int.ty %"$0", %Int.ty* %Bar.b.ptr
  %Bar.a.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 1
  store %Int.ty %"$1", %Int.ty* %Bar.a.ptr
  %Bar1 = load %Bar.ty* %Bar
  ret %Bar.ty %Bar1
}

declare %Int.ty @_Int_i64(i64)

declare void @_print_Int(%Int.ty)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
