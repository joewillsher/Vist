; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Foo.st = type { %Int.st }
%Eq.ex = type { [1 x i32], i8* }
%Bar.st = type { %Eq.ex }

define void @main() {
entry:
  %0 = call %Int.st @_Int_i64(i64 3), !stdlib.call.optim !0
  %a = alloca %Int.st
  store %Int.st %0, %Int.st* %a
  %a1 = load %Int.st* %a
  call void @_print_Int(%Int.st %a1), !stdlib.call.optim !0
  %1 = call %Int.st @_Int_i64(i64 1), !stdlib.call.optim !0
  %Foo_res = call %Foo.st @_Foo_Int(%Int.st %1)
  %f = alloca %Foo.st
  store %Foo.st %Foo_res, %Foo.st* %f
  %f2 = load %Foo.st* %f
  %2 = alloca %Eq.ex
  %.metadata = getelementptr inbounds %Eq.ex* %2, i32 0, i32 0
  %.opaque = getelementptr inbounds %Eq.ex* %2, i32 0, i32 1
  %3 = alloca %Foo.st
  %metadata = alloca [1 x i32]
  %4 = bitcast [1 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %4, i32 0
  store i32 0, i32* %el.0
  %5 = load [1 x i32]* %metadata
  store [1 x i32] %5, [1 x i32]* %.metadata
  store %Foo.st %f2, %Foo.st* %3
  %6 = bitcast %Foo.st* %3 to i8*
  store i8* %6, i8** %.opaque
  %7 = load %Eq.ex* %2
  %Bar_res = call %Bar.st @_Bar_Eq(%Eq.ex %7)
  %b = alloca %Bar.st
  store %Bar.st %Bar_res, %Bar.st* %b
  %b.foo.ptr = getelementptr inbounds %Bar.st* %b, i32 0, i32 0
  %b.foo = load %Eq.ex* %b.foo.ptr
  %8 = alloca %Eq.ex
  store %Eq.ex %b.foo, %Eq.ex* %8
  store %Eq.ex %b.foo, %Eq.ex* %8
  %.metadata_ptr = getelementptr inbounds %Eq.ex* %8, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %.metadata_ptr to i32*
  %9 = getelementptr i32* %metadata_base_ptr, i32 0
  %10 = load i32* %9
  %.element_pointer = getelementptr inbounds %Eq.ex* %8, i32 0, i32 1
  %.opaque_instance_pointer = load i8** %.element_pointer
  %11 = getelementptr i8* %.opaque_instance_pointer, i32 %10
  %t.ptr = bitcast i8* %11 to %Int.st*
  %t = load %Int.st* %t.ptr
  %u = alloca %Int.st
  store %Int.st %t, %Int.st* %u
  %u3 = load %Int.st* %u
  call void @_print_Int(%Int.st %u3), !stdlib.call.optim !0
  %12 = call %Int.st @_Int_i64(i64 4), !stdlib.call.optim !0
  %Foo_res4 = call %Foo.st @_Foo_Int(%Int.st %12)
  %13 = alloca %Eq.ex
  %.metadata5 = getelementptr inbounds %Eq.ex* %13, i32 0, i32 0
  %.opaque6 = getelementptr inbounds %Eq.ex* %13, i32 0, i32 1
  %14 = alloca %Foo.st
  %metadata7 = alloca [1 x i32]
  %15 = bitcast [1 x i32]* %metadata7 to i32*
  %el.08 = getelementptr i32* %15, i32 0
  store i32 0, i32* %el.08
  %16 = load [1 x i32]* %metadata7
  store [1 x i32] %16, [1 x i32]* %.metadata5
  store %Foo.st %Foo_res4, %Foo.st* %14
  %17 = bitcast %Foo.st* %14 to i8*
  store i8* %17, i8** %.opaque6
  %18 = load %Eq.ex* %13
  %Bar_res9 = call %Bar.st @_Bar_Eq(%Eq.ex %18)
  %19 = call %Int.st @_Int_i64(i64 1), !stdlib.call.optim !0
  %20 = alloca { %Bar.st, %Int.st }
  %.0.ptr = getelementptr inbounds { %Bar.st, %Int.st }* %20, i32 0, i32 0
  store %Bar.st %Bar_res9, %Bar.st* %.0.ptr
  %.1.ptr = getelementptr inbounds { %Bar.st, %Int.st }* %20, i32 0, i32 1
  store %Int.st %19, %Int.st* %.1.ptr
  %21 = load { %Bar.st, %Int.st }* %20
  %w = alloca { %Bar.st, %Int.st }
  store { %Bar.st, %Int.st } %21, { %Bar.st, %Int.st }* %w
  %w.0.ptr = getelementptr inbounds { %Bar.st, %Int.st }* %w, i32 0, i32 0
  %w.0 = load %Bar.st* %w.0.ptr
  %22 = alloca %Bar.st
  store %Bar.st %w.0, %Bar.st* %22
  %.foo.ptr = getelementptr inbounds %Bar.st* %22, i32 0, i32 0
  %.foo = load %Eq.ex* %.foo.ptr
  %23 = alloca %Eq.ex
  store %Eq.ex %.foo, %Eq.ex* %23
  store %Eq.ex %.foo, %Eq.ex* %23
  %.metadata_ptr10 = getelementptr inbounds %Eq.ex* %23, i32 0, i32 0
  %metadata_base_ptr11 = bitcast [1 x i32]* %.metadata_ptr10 to i32*
  %24 = getelementptr i32* %metadata_base_ptr11, i32 0
  %25 = load i32* %24
  %.element_pointer12 = getelementptr inbounds %Eq.ex* %23, i32 0, i32 1
  %.opaque_instance_pointer13 = load i8** %.element_pointer12
  %26 = getelementptr i8* %.opaque_instance_pointer13, i32 %25
  %t.ptr14 = bitcast i8* %26 to %Int.st*
  %t15 = load %Int.st* %t.ptr14
  %xx = alloca %Int.st
  store %Int.st %t15, %Int.st* %xx
  %xx16 = load %Int.st* %xx
  call void @_print_Int(%Int.st %xx16), !stdlib.call.optim !0
  ret void
}

declare %Int.st @_Int_i64(i64)

declare void @_print_Int(%Int.st)

; Function Attrs: alwaysinline
define %Foo.st @_Foo_Int(%Int.st %"$0") #0 {
entry:
  %Foo = alloca %Foo.st
  %Foo.t.ptr = getelementptr inbounds %Foo.st* %Foo, i32 0, i32 0
  store %Int.st %"$0", %Int.st* %Foo.t.ptr
  %Foo1 = load %Foo.st* %Foo
  ret %Foo.st %Foo1
}

; Function Attrs: alwaysinline
define %Bar.st @_Bar_Eq(%Eq.ex %"$0") #0 {
entry:
  %"$01" = alloca %Eq.ex
  store %Eq.ex %"$0", %Eq.ex* %"$01"
  %Bar = alloca %Bar.st
  %"$02" = load %Eq.ex* %"$01"
  %Bar.foo.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 0
  store %Eq.ex %"$02", %Eq.ex* %Bar.foo.ptr
  %Bar3 = load %Bar.st* %Bar
  ret %Bar.st %Bar3
}

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
