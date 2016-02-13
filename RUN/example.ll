; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bar.ty = type { %Bool.ty, %Int.ty, %Int.ty }
%Bool.ty = type { i1 }
%Int.ty = type { i64 }
%Eq.ex.ty = type { [2 x i32], i8* }

define void @main() {
entry:
  %Bar.i = alloca %Bar.ty
  %0 = call %Bool.ty @_Bool_b(i1 true), !stdlib.call.optim !0
  %1 = call %Int.ty @_Int_i64(i64 11), !stdlib.call.optim !0
  %2 = call %Int.ty @_Int_i64(i64 4), !stdlib.call.optim !0
  %Bar.x.ptr.i = getelementptr inbounds %Bar.ty* %Bar.i, i32 0, i32 0
  store %Bool.ty %0, %Bool.ty* %Bar.x.ptr.i
  %Bar.b.ptr.i = getelementptr inbounds %Bar.ty* %Bar.i, i32 0, i32 1
  store %Int.ty %1, %Int.ty* %Bar.b.ptr.i
  %Bar.a.ptr.i = getelementptr inbounds %Bar.ty* %Bar.i, i32 0, i32 2
  store %Int.ty %2, %Int.ty* %Bar.a.ptr.i
  %Bar1.i = load %Bar.ty* %Bar.i
  %3 = call %Int.ty @_Int_i64(i64 2), !stdlib.call.optim !0
  %4 = alloca %Eq.ex.ty
  %.metadata = getelementptr inbounds %Eq.ex.ty* %4, i32 0, i32 0
  %.opaque = getelementptr inbounds %Eq.ex.ty* %4, i32 0, i32 1
  %5 = alloca %Bar.ty
  %metadata = alloca [2 x i32]
  %6 = getelementptr inbounds [2 x i32]* %metadata, i32 0, i32 0
  store i32 16, i32* %6
  %el.1 = getelementptr [2 x i32]* %metadata, i32 0, i32 1
  store i32 8, i32* %el.1
  %7 = load [2 x i32]* %metadata
  store [2 x i32] %7, [2 x i32]* %.metadata
  store %Bar.ty %Bar1.i, %Bar.ty* %5
  %8 = bitcast i8** %.opaque to %Bar.ty**
  store %Bar.ty* %5, %Bar.ty** %8
  %9 = load %Eq.ex.ty* %4
  %foo_res = call %Int.ty @_foo_Eq_Int(%Eq.ex.ty %9, %Int.ty %3)
  call void @_print_Int(%Int.ty %foo_res), !stdlib.call.optim !0
  ret void
}

define internal %Int.ty @_foo_Eq_Int(%Eq.ex.ty %a, %Int.ty %b) {
entry:
  %a1 = alloca %Eq.ex.ty
  store %Eq.ex.ty %a, %Eq.ex.ty* %a1
  %0 = getelementptr %Eq.ex.ty* %a1, i32 0, i32 0, i32 1
  %1 = load i32* %0
  %a.element_pointer = getelementptr inbounds %Eq.ex.ty* %a1, i32 0, i32 1
  %a.opaque_instance_pointer = load i8** %a.element_pointer
  %2 = getelementptr i8* %a.opaque_instance_pointer, i32 %1
  %b.ptr = bitcast i8* %2 to %Int.ty*
  %b2 = load %Int.ty* %b.ptr
  %metadata_base_ptr4 = getelementptr inbounds %Eq.ex.ty* %a1, i32 0, i32 0, i32 0
  %3 = load i32* %metadata_base_ptr4
  %a.element_pointer5 = getelementptr inbounds %Eq.ex.ty* %a1, i32 0, i32 1
  %a.opaque_instance_pointer6 = load i8** %a.element_pointer5
  %4 = getelementptr i8* %a.opaque_instance_pointer6, i32 %3
  %a.ptr = bitcast i8* %4 to %Int.ty*
  %a7 = load %Int.ty* %a.ptr
  %"+.res" = call %Int.ty @"_+_Int_Int"(%Int.ty %b, %Int.ty %a7), !stdlib.call.optim !0
  %"+.res8" = call %Int.ty @"_+_Int_Int"(%Int.ty %b2, %Int.ty %"+.res"), !stdlib.call.optim !0
  ret %Int.ty %"+.res8"
}

declare %Int.ty @"_+_Int_Int"(%Int.ty, %Int.ty)

; Function Attrs: alwaysinline
define %Bar.ty @_Bar_Bool_Int_Int(%Bool.ty %"$0", %Int.ty %"$1", %Int.ty %"$2") #0 {
entry:
  %Bar = alloca %Bar.ty
  %Bar.x.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 0
  store %Bool.ty %"$0", %Bool.ty* %Bar.x.ptr
  %Bar.b.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 1
  store %Int.ty %"$1", %Int.ty* %Bar.b.ptr
  %Bar.a.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 2
  store %Int.ty %"$2", %Int.ty* %Bar.a.ptr
  %Bar1 = load %Bar.ty* %Bar
  ret %Bar.ty %Bar1
}

declare %Bool.ty @_Bool_b(i1)

declare %Int.ty @_Int_i64(i64)

declare void @_print_Int(%Int.ty)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
