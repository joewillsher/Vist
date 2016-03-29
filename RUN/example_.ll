; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bool.st = type { i1 }
%Bar.st = type { %Int.st, %Int.st, %Bool.st }
%Int.st = type { i64 }
%Foo.ex = type { [2 x i32], [0 x i8*], i8* }

declare void @print_Bool(%Bool.st)

define %Bar.st @Bar_Int_Int_Bool(%Int.st %"$0", %Int.st %"$1", %Bool.st %"$2") {
entry:
  %self = alloca %Bar.st
  %b = getelementptr inbounds %Bar.st* %self, i32 0, i32 0
  %a = getelementptr inbounds %Bar.st* %self, i32 0, i32 1
  %c = getelementptr inbounds %Bar.st* %self, i32 0, i32 2
  store %Int.st %"$0", %Int.st* %b
  store %Int.st %"$1", %Int.st* %a
  store %Bool.st %"$2", %Bool.st* %c
  %0 = load %Bar.st* %self
  ret %Bar.st %0
}

define %Bool.st @unbox2_Foo(%Foo.ex %box) {
entry:
  %0 = alloca %Foo.ex
  store %Foo.ex %box, %Foo.ex* %0
  %nil.metadata_ptr = getelementptr inbounds %Foo.ex* %0, i32 0, i32 0
  %metadata_base_ptr = bitcast [2 x i32]* %nil.metadata_ptr to i32*
  %1 = getelementptr i32* %metadata_base_ptr, i32 1
  %2 = load i32* %1
  %nil.element_pointer = getelementptr inbounds %Foo.ex* %0, i32 0, i32 2
  %nil.opaque_instance_pointer = load i8** %nil.element_pointer
  %3 = getelementptr i8* %nil.opaque_instance_pointer, i32 %2
  %nil.ptr = bitcast i8* %3 to %Bool.st*
  %4 = load %Bool.st* %nil.ptr
  ret %Bool.st %4
}

define void @main() {
entry:
  %0 = call %Bar.st @Bar_Int_Int_Bool(%Int.st { i64 1 }, %Int.st { i64 2 }, %Bool.st zeroinitializer)
  %b = alloca %Bar.st
  store %Bar.st %0, %Bar.st* %b
  %1 = alloca %Bar.st
  store %Bar.st %0, %Bar.st* %1
  %2 = alloca %Bar.st
  %3 = alloca %Foo.ex
  %nil.prop_metadata = getelementptr inbounds %Foo.ex* %3, i32 0, i32 0
  %nil.method_metadata = getelementptr inbounds %Foo.ex* %3, i32 0, i32 1
  %nil.opaque = getelementptr inbounds %Foo.ex* %3, i32 0, i32 2
  %metadata = alloca [2 x i32]
  %4 = bitcast [2 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %4, i32 0
  store i32 8, i32* %el.0
  %el.1 = getelementptr i32* %4, i32 1
  store i32 16, i32* %el.1
  %5 = load [2 x i32]* %metadata
  store [2 x i32] %5, [2 x i32]* %nil.prop_metadata
  %6 = load %Bar.st* %1
  store %Bar.st %6, %Bar.st* %2
  %7 = bitcast %Bar.st* %2 to i8*
  store i8* %7, i8** %nil.opaque
  %8 = load %Foo.ex* %3
  %9 = call %Int.st @unbox_Foo(%Foo.ex %8)
  %a = alloca %Int.st
  store %Int.st %9, %Int.st* %a
  call void @print_Int(%Int.st %9), !stdlib.call.optim !0
  %10 = alloca %Bar.st
  store %Bar.st %0, %Bar.st* %10
  %11 = alloca %Bar.st
  %12 = alloca %Foo.ex
  %nil.prop_metadata1 = getelementptr inbounds %Foo.ex* %12, i32 0, i32 0
  %nil.method_metadata2 = getelementptr inbounds %Foo.ex* %12, i32 0, i32 1
  %nil.opaque3 = getelementptr inbounds %Foo.ex* %12, i32 0, i32 2
  %metadata4 = alloca [2 x i32]
  %13 = bitcast [2 x i32]* %metadata4 to i32*
  %el.05 = getelementptr i32* %13, i32 0
  store i32 8, i32* %el.05
  %el.16 = getelementptr i32* %13, i32 1
  store i32 16, i32* %el.16
  %14 = load [2 x i32]* %metadata4
  store [2 x i32] %14, [2 x i32]* %nil.prop_metadata1
  %15 = load %Bar.st* %10
  store %Bar.st %15, %Bar.st* %11
  %16 = bitcast %Bar.st* %11 to i8*
  store i8* %16, i8** %nil.opaque3
  %17 = load %Foo.ex* %12
  %18 = call %Bool.st @unbox2_Foo(%Foo.ex %17)
  call void @print_Bool(%Bool.st %18), !stdlib.call.optim !0
  ret void
}

declare void @print_Int(%Int.st)

define %Int.st @unbox_Foo(%Foo.ex %box) {
entry:
  %0 = alloca %Foo.ex
  store %Foo.ex %box, %Foo.ex* %0
  %nil.metadata_ptr = getelementptr inbounds %Foo.ex* %0, i32 0, i32 0
  %metadata_base_ptr = bitcast [2 x i32]* %nil.metadata_ptr to i32*
  %1 = getelementptr i32* %metadata_base_ptr, i32 0
  %2 = load i32* %1
  %nil.element_pointer = getelementptr inbounds %Foo.ex* %0, i32 0, i32 2
  %nil.opaque_instance_pointer = load i8** %nil.element_pointer
  %3 = getelementptr i8* %nil.opaque_instance_pointer, i32 %2
  %nil.ptr = bitcast i8* %3 to %Int.st*
  %4 = load %Int.st* %nil.ptr
  ret %Int.st %4
}

!0 = !{!"stdlib.call.optim"}
