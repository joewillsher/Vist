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
  %7 = alloca %Eq.ty
  store %Eq.ty %b.foo3, %Eq.ty* %7
  store %Eq.ty %b.foo3, %Eq.ty* %7
  %.metadata_ptr = getelementptr inbounds %Eq.ty* %7, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %.metadata_ptr to i32*
  %8 = getelementptr i32* %metadata_base_ptr, i32 0
  %9 = load i32* %8
  %.element_pointer = getelementptr inbounds %Eq.ty* %7, i32 0, i32 1
  %.opaque_instance_pointer = load i8** %.element_pointer
  %10 = getelementptr i8* %.opaque_instance_pointer, i32 %9
  %t.ptr = bitcast i8* %10 to %Int.ty*
  %t = load %Int.ty* %t.ptr
  %u = alloca %Int.ty
  store %Int.ty %t, %Int.ty* %u
  %u4 = load %Int.ty* %u
  call void @_print_Int(%Int.ty %u4), !stdlib.call.optim !0
  %b5 = load %Bar.ty* %b
  %11 = call %Int.ty @_Int_i64(i64 1), !stdlib.call.optim !0
  %12 = alloca { %Bar.ty, %Int.ty }
  %.0.ptr = getelementptr inbounds { %Bar.ty, %Int.ty }* %12, i32 0, i32 0
  store %Bar.ty %b5, %Bar.ty* %.0.ptr
  %.1.ptr = getelementptr inbounds { %Bar.ty, %Int.ty }* %12, i32 0, i32 1
  store %Int.ty %11, %Int.ty* %.1.ptr
  %13 = load { %Bar.ty, %Int.ty }* %12
  %w = alloca { %Bar.ty, %Int.ty }
  store { %Bar.ty, %Int.ty } %13, { %Bar.ty, %Int.ty }* %w
  %w.0.ptr = getelementptr inbounds { %Bar.ty, %Int.ty }* %w, i32 0, i32 0
  %w.0 = load %Bar.ty* %w.0.ptr
  %w.0.ptr6 = getelementptr inbounds { %Bar.ty, %Int.ty }* %w, i32 0, i32 0
  %w.07 = load %Bar.ty* %w.0.ptr6
  %14 = alloca %Bar.ty
  store %Bar.ty %w.07, %Bar.ty* %14
  %.foo.ptr = getelementptr inbounds %Bar.ty* %14, i32 0, i32 0
  %.foo = load %Eq.ty* %.foo.ptr
  %xx = alloca %Eq.ty
  store %Eq.ty %.foo, %Eq.ty* %xx
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
