; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Foo.st = type { %Int.st }
%TestC.ex = type { [1 x i32], i8* }
%Bar.st = type { %TestC.ex }

define void @main() {
entry:
  %0 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %Foo_res = call %Foo.st @Foo_Int(%Int.st %0)
  %f = alloca %Foo.st
  store %Foo.st %Foo_res, %Foo.st* %f
  %1 = call %Int.st @Int_i64(i64 3), !stdlib.call.optim !0
  %f.t.ptr = getelementptr inbounds %Foo.st* %f, i32 0, i32 0
  store %Int.st %1, %Int.st* %f.t.ptr
  %f1 = load %Foo.st* %f
  %2 = alloca %TestC.ex
  %.metadata = getelementptr inbounds %TestC.ex* %2, i32 0, i32 0
  %.opaque = getelementptr inbounds %TestC.ex* %2, i32 0, i32 1
  %3 = alloca %Foo.st
  %metadata = alloca [1 x i32]
  %4 = bitcast [1 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %4, i32 0
  store i32 0, i32* %el.0
  %5 = load [1 x i32]* %metadata
  store [1 x i32] %5, [1 x i32]* %.metadata
  store %Foo.st %f1, %Foo.st* %3
  %6 = bitcast %Foo.st* %3 to i8*
  store i8* %6, i8** %.opaque
  %7 = load %TestC.ex* %2
  %Bar_res = call %Bar.st @Bar_TestC(%TestC.ex %7)
  %b = alloca %Bar.st
  store %Bar.st %Bar_res, %Bar.st* %b
  %b.foo.ptr = getelementptr inbounds %Bar.st* %b, i32 0, i32 0
  %b.foo = load %TestC.ex* %b.foo.ptr
  %8 = alloca %TestC.ex
  store %TestC.ex %b.foo, %TestC.ex* %8
  store %TestC.ex %b.foo, %TestC.ex* %8
  %.metadata_ptr = getelementptr inbounds %TestC.ex* %8, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %.metadata_ptr to i32*
  %9 = getelementptr i32* %metadata_base_ptr, i32 0
  %10 = load i32* %9
  %.element_pointer = getelementptr inbounds %TestC.ex* %8, i32 0, i32 1
  %.opaque_instance_pointer = load i8** %.element_pointer
  %11 = getelementptr i8* %.opaque_instance_pointer, i32 %10
  %t.ptr = bitcast i8* %11 to %Int.st*
  %t = load %Int.st* %t.ptr
  %u = alloca %Int.st
  store %Int.st %t, %Int.st* %u
  %u2 = load %Int.st* %u
  call void @print_Int(%Int.st %u2), !stdlib.call.optim !0
  ret void
}

; Function Attrs: alwaysinline
define %Foo.st @Foo_Int(%Int.st %"$0") #0 {
entry:
  %Foo = alloca %Foo.st
  %Foo.t.ptr = getelementptr inbounds %Foo.st* %Foo, i32 0, i32 0
  store %Int.st %"$0", %Int.st* %Foo.t.ptr
  %Foo1 = load %Foo.st* %Foo
  ret %Foo.st %Foo1
}

; Function Attrs: alwaysinline
define %Bar.st @Bar_TestC(%TestC.ex %"$0") #0 {
entry:
  %param0 = alloca %TestC.ex
  store %TestC.ex %"$0", %TestC.ex* %param0
  %Bar = alloca %Bar.st
  %param01 = load %TestC.ex* %param0
  %Bar.foo.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 0
  store %TestC.ex %param01, %TestC.ex* %Bar.foo.ptr
  %Bar2 = load %Bar.st* %Bar
  ret %Bar.st %Bar2
}

declare %Int.st @Int_i64(i64)

declare void @print_Int(%Int.st)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
