; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Foo.st = type { %Int.st }
%TestC.ex = type { [1 x i32], i8* }
%Bar.st = type { %TestC.ex }

define void @main() {
entry:
  %0 = call %Int.st @_Int_i64(i64 1), !stdlib.call.optim !0
  %Foo_res = call %Foo.st @_Foo_Int(%Int.st %0)
  %1 = alloca %TestC.ex
  %.metadata = getelementptr inbounds %TestC.ex* %1, i32 0, i32 0
  %.opaque = getelementptr inbounds %TestC.ex* %1, i32 0, i32 1
  %2 = alloca %Foo.st
  %metadata = alloca [1 x i32]
  %3 = bitcast [1 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %3, i32 0
  store i32 0, i32* %el.0
  %4 = load [1 x i32]* %metadata
  store [1 x i32] %4, [1 x i32]* %.metadata
  store %Foo.st %Foo_res, %Foo.st* %2
  %5 = bitcast %Foo.st* %2 to i8*
  store i8* %5, i8** %.opaque
  %6 = load %TestC.ex* %1
  %Bar_res = call %Bar.st @_Bar_TestC(%TestC.ex %6)
  %b = alloca %Bar.st
  store %Bar.st %Bar_res, %Bar.st* %b
  %b.foo.ptr = getelementptr inbounds %Bar.st* %b, i32 0, i32 0
  %b.foo = load %TestC.ex* %b.foo.ptr
  %7 = alloca %TestC.ex
  store %TestC.ex %b.foo, %TestC.ex* %7
  store %TestC.ex %b.foo, %TestC.ex* %7
  %.metadata_ptr = getelementptr inbounds %TestC.ex* %7, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %.metadata_ptr to i32*
  %8 = getelementptr i32* %metadata_base_ptr, i32 0
  %9 = load i32* %8
  %.element_pointer = getelementptr inbounds %TestC.ex* %7, i32 0, i32 1
  %.opaque_instance_pointer = load i8** %.element_pointer
  %10 = getelementptr i8* %.opaque_instance_pointer, i32 %9
  %t.ptr = bitcast i8* %10 to %Int.st*
  %t = load %Int.st* %t.ptr
  %u = alloca %Int.st
  store %Int.st %t, %Int.st* %u
  %u1 = load %Int.st* %u
  call void @_print_Int(%Int.st %u1), !stdlib.call.optim !0
  ret void
}

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
define %Bar.st @_Bar_TestC(%TestC.ex %"$0") #0 {
entry:
  %"$01" = alloca %TestC.ex
  store %TestC.ex %"$0", %TestC.ex* %"$01"
  %Bar = alloca %Bar.st
  %"$02" = load %TestC.ex* %"$01"
  %Bar.foo.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 0
  store %TestC.ex %"$02", %TestC.ex* %Bar.foo.ptr
  %Bar3 = load %Bar.st* %Bar
  ret %Bar.st %Bar3
}

declare %Int.st @_Int_i64(i64)

declare void @_print_Int(%Int.st)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
