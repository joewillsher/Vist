; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bar.ty = type { %Eq.ty }
%Eq.ty = type { [1 x i32], i8* }
%Foo.ty = type { %Int.ty }
%Int.ty = type { i64 }

define void @main() {
entry:
  %Bar.i = alloca %Bar.ty
  %Foo.i = alloca %Foo.ty
  %0 = call %Int.ty @_Int_i64(i64 1), !stdlib.call.optim !0
  %Foo.t.ptr.i = getelementptr inbounds %Foo.ty* %Foo.i, i32 0, i32 0
  store %Int.ty %0, %Int.ty* %Foo.t.ptr.i
  %Foo1.i = load %Foo.ty* %Foo.i
  %1 = alloca %Eq.ty
  %.metadata = getelementptr inbounds %Eq.ty* %1, i32 0, i32 0
  %.opaque = getelementptr inbounds %Eq.ty* %1, i32 0, i32 1
  %2 = alloca %Foo.ty
  %metadata = alloca [1 x i32]
  %3 = getelementptr inbounds [1 x i32]* %metadata, i32 0, i32 0
  store i32 0, i32* %3
  %4 = load [1 x i32]* %metadata
  store [1 x i32] %4, [1 x i32]* %.metadata
  store %Foo.ty %Foo1.i, %Foo.ty* %2
  %5 = bitcast i8** %.opaque to %Foo.ty**
  store %Foo.ty* %2, %Foo.ty** %5
  %6 = load %Eq.ty* %1
  %Bar.foo.ptr.i = getelementptr inbounds %Bar.ty* %Bar.i, i32 0, i32 0
  store %Eq.ty %6, %Eq.ty* %Bar.foo.ptr.i
  %Bar3.i = load %Bar.ty* %Bar.i
  %b = alloca %Bar.ty
  store %Bar.ty %Bar3.i, %Bar.ty* %b
  %b.foo.ptr2 = getelementptr inbounds %Bar.ty* %b, i32 0, i32 0
  %b.foo3 = load %Eq.ty* %b.foo.ptr2
  %foo = alloca %Eq.ty
  store %Eq.ty %b.foo3, %Eq.ty* %foo
  %metadata_base_ptr = getelementptr inbounds %Eq.ty* %foo, i32 0, i32 0, i32 0
  %7 = load i32* %metadata_base_ptr
  %foo.element_pointer = getelementptr inbounds %Eq.ty* %foo, i32 0, i32 1
  %foo.opaque_instance_pointer = load i8** %foo.element_pointer
  %8 = getelementptr i8* %foo.opaque_instance_pointer, i32 %7
  %t.ptr = bitcast i8* %8 to %Int.ty*
  %t = load %Int.ty* %t.ptr
  call void @_print_Int(%Int.ty %t), !stdlib.call.optim !0
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
  %Bar = alloca %Bar.ty
  %Bar.foo.ptr = getelementptr inbounds %Bar.ty* %Bar, i32 0, i32 0
  store %Eq.ty %"$0", %Eq.ty* %Bar.foo.ptr
  %Bar3 = load %Bar.ty* %Bar
  ret %Bar.ty %Bar3
}

declare %Int.ty @_Int_i64(i64)

declare void @_print_Int(%Int.ty)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
