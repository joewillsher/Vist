; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Bar.st = type { %Int.st }
%Foo.ex = type { [1 x i32], i8* }

define void @main() {
entry:
  %0 = call %Int.st @Int_i64(i64 12), !stdlib.call.optim !0
  %Bar_res = call %Bar.st @Bar_Int(%Int.st %0)
  %1 = alloca %Bar.st
  %2 = alloca %Foo.ex
  %.metadata = getelementptr inbounds %Foo.ex* %2, i32 0, i32 0
  %.opaque = getelementptr inbounds %Foo.ex* %2, i32 0, i32 1
  %metadata = alloca [1 x i32]
  %3 = bitcast [1 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %3, i32 0
  store i32 0, i32* %el.0
  %4 = load [1 x i32]* %metadata
  store [1 x i32] %4, [1 x i32]* %.metadata
  store %Bar.st %Bar_res, %Bar.st* %1
  %5 = bitcast %Bar.st* %1 to i8*
  store i8* %5, i8** %.opaque
  %6 = load %Foo.ex* %2
  call void @fn_Foo(%Foo.ex %6)
  ret void
}

; Function Attrs: alwaysinline
define %Bar.st @Bar_Int(%Int.st %"$0") #0 {
entry:
  %Bar = alloca %Bar.st
  %Bar.v.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 0
  store %Int.st %"$0", %Int.st* %Bar.v.ptr
  %Bar1 = load %Bar.st* %Bar
  ret %Bar.st %Bar1
}

define internal void @fn_Foo(%Foo.ex %f) {
entry:
  %f1 = alloca %Foo.ex
  store %Foo.ex %f, %Foo.ex* %f1
  %f.metadata_ptr = getelementptr inbounds %Foo.ex* %f1, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %f.metadata_ptr to i32*
  %0 = getelementptr i32* %metadata_base_ptr, i32 0
  %1 = load i32* %0
  %f.element_pointer = getelementptr inbounds %Foo.ex* %f1, i32 0, i32 1
  %f.opaque_instance_pointer = load i8** %f.element_pointer
  %2 = getelementptr i8* %f.opaque_instance_pointer, i32 %1
  %v.ptr = bitcast i8* %2 to %Int.st*
  %v = load %Int.st* %v.ptr
  call void @print_Int(%Int.st %v), !stdlib.call.optim !0
  %v2 = load %Int.st* %v.ptr
  call void @print_Int(%Int.st %v2), !stdlib.call.optim !0
  %v3 = load %Int.st* %v.ptr
  call void @print_Int(%Int.st %v3), !stdlib.call.optim !0
  %v4 = load %Int.st* %v.ptr
  call void @print_Int(%Int.st %v4), !stdlib.call.optim !0
  ret void
}

declare void @print_Int(%Int.st)

declare %Int.st @Int_i64(i64)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
