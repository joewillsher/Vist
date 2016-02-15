; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.ty = type { i64 }
%Foo.ty = type { %Int.ty }
%Eq.ty = type { [1 x i32], i8* }
%Bar.ty = type { %Eq.ty }

define void @main() {
entry:
  %0 = call %Int.ty @_Int_i64(i64 1), !stdlib.call.optim !0
  %Foo_res = call %Foo.ty @_Foo_Int(%Int.ty %0)
  %f = alloca %Foo.ty
  store %Foo.ty %Foo_res, %Foo.ty* %f
  %f1 = load %Foo.ty* %f
  %1 = alloca %Eq.ty
  %.metadata = getelementptr inbounds %Eq.ty* %1, i32 0, i32 0
  %.opaque = getelementptr inbounds %Eq.ty* %1, i32 0, i32 1
  %2 = alloca %Foo.ty
  %metadata = alloca [1 x i32]
  %3 = bitcast [1 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %3, i32 0
  store i32 0, i32* %el.0
  %4 = load [1 x i32]* %metadata
  store [1 x i32] %4, [1 x i32]* %.metadata
  store %Foo.ty %f1, %Foo.ty* %2
  %5 = bitcast %Foo.ty* %2 to i8*
  store i8* %5, i8** %.opaque
  %6 = load %Eq.ty* %1
  %Bar_res = call %Bar.ty @_Bar_Eq(%Eq.ty %6)
  %b = alloca %Bar.ty
  store %Bar.ty %Bar_res, %Bar.ty* %b
  %b.foo.ptr = getelementptr inbounds %Bar.ty* %b, i32 0, i32 0
  %b.foo = load %Eq.ty* %b.foo.ptr
  %b.foo.ptr2 = getelementptr inbounds %Bar.ty* %b, i32 0, i32 0
  %b.foo3 = load %Eq.ty* %b.foo.ptr2
  %foo = alloca %Eq.ty
  store %Eq.ty %b.foo3, %Eq.ty* %foo
  store %Eq.ty %b.foo3, %Eq.ty* %foo
  %foo.metadata_ptr = getelementptr inbounds %Eq.ty* %foo, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %foo.metadata_ptr to i32*
  %7 = getelementptr i32* %metadata_base_ptr, i32 0
  %8 = load i32* %7
  %foo.element_pointer = getelementptr inbounds %Eq.ty* %foo, i32 0, i32 1
  %foo.opaque_instance_pointer = load i8** %foo.element_pointer
  %9 = getelementptr i8* %foo.opaque_instance_pointer, i32 %8
  %t.ptr = bitcast i8* %9 to %Int.ty*
  %t = load %Int.ty* %t.ptr
  %u = alloca %Int.ty
  store %Int.ty %t, %Int.ty* %u
  %u4 = load %Int.ty* %u
  call void @_print_Int(%Int.ty %u4), !stdlib.call.optim !0
  ret void
}

; Function Attrs: alwaysinline
define %Foo.ty @_Foo_Int(%Int.ty %"$0") #0 {
entry:
  %Foo = alloca %Foo.ty
  %Foo.t.ptr = getelementptr inbounds %Foo.ty* %Foo, i32 0, i32 0
  store %Int.ty %"$0", %Int.ty* %Foo.t.ptr
  %Foo1 = load %Foo.ty* %Foo
  ret %Foo.ty %Foo1
}

; Function Attrs: alwaysinline
define %Bar.ty @_Bar_Eq(%Eq.ty %"$0") #0 {
entry:
  %"$01" = alloca %Eq.ty
  store %Eq.ty %"$0", %Eq.ty* %"$01"
  %Bar = alloca %Bar.ty
  %"$02" = load %Eq.ty* %"$01"
  %Bar.foo.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 0
  store %Eq.ty %"$02", %Eq.ty* %Bar.foo.ptr
  %Bar3 = load %Bar.ty* %Bar
  ret %Bar.ty %Bar3
}

declare %Int.ty @_Int_i64(i64)

declare void @_print_Int(%Int.ty)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
