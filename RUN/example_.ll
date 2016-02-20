; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Bar.st = type { %Int.st, %Int.st }
%Eq.ex = type { [2 x i32], i8* }

define void @main() {
entry:
  %0 = call %Int.st @Int_i64(i64 11), !stdlib.call.optim !0
  %1 = call %Int.st @Int_i64(i64 4), !stdlib.call.optim !0
  %Bar_res = call %Bar.st @Bar_Int_Int(%Int.st %0, %Int.st %1)
  %bar = alloca %Bar.st
  store %Bar.st %Bar_res, %Bar.st* %bar
  %bar1 = load %Bar.st* %bar
  %2 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %3 = alloca %Bar.st
  %4 = alloca %Eq.ex
  %.metadata = getelementptr inbounds %Eq.ex* %4, i32 0, i32 0
  %.opaque = getelementptr inbounds %Eq.ex* %4, i32 0, i32 1
  %metadata = alloca [2 x i32]
  %5 = bitcast [2 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %5, i32 0
  store i32 8, i32* %el.0
  %el.1 = getelementptr i32* %5, i32 1
  store i32 0, i32* %el.1
  %6 = load [2 x i32]* %metadata
  store [2 x i32] %6, [2 x i32]* %.metadata
  store %Bar.st %bar1, %Bar.st* %3
  %7 = bitcast %Bar.st* %3 to i8*
  store i8* %7, i8** %.opaque
  %8 = load %Eq.ex* %4
  %foo_res = call %Int.st @foo_Eq_Int(%Eq.ex %8, %Int.st %2)
  %foo = alloca %Int.st
  store %Int.st %foo_res, %Int.st* %foo
  %foo2 = load %Int.st* %foo
  call void @print_Int(%Int.st %foo2), !stdlib.call.optim !0
  ret void
}

define internal %Int.st @foo_Eq_Int(%Eq.ex %a, %Int.st %b) {
entry:
  %a1 = alloca %Eq.ex
  store %Eq.ex %a, %Eq.ex* %a1
  %a.metadata_ptr = getelementptr inbounds %Eq.ex* %a1, i32 0, i32 0
  %metadata_base_ptr = bitcast [2 x i32]* %a.metadata_ptr to i32*
  %0 = getelementptr i32* %metadata_base_ptr, i32 1
  %1 = load i32* %0
  %a.element_pointer = getelementptr inbounds %Eq.ex* %a1, i32 0, i32 1
  %a.opaque_instance_pointer = load i8** %a.element_pointer
  %2 = getelementptr i8* %a.opaque_instance_pointer, i32 %1
  %b.ptr = bitcast i8* %2 to %Int.st*
  %b2 = load %Int.st* %b.ptr
  %a.metadata_ptr3 = getelementptr inbounds %Eq.ex* %a1, i32 0, i32 0
  %metadata_base_ptr4 = bitcast [2 x i32]* %a.metadata_ptr3 to i32*
  %3 = getelementptr i32* %metadata_base_ptr4, i32 0
  %4 = load i32* %3
  %a.element_pointer5 = getelementptr inbounds %Eq.ex* %a1, i32 0, i32 1
  %a.opaque_instance_pointer6 = load i8** %a.element_pointer5
  %5 = getelementptr i8* %a.opaque_instance_pointer6, i32 %4
  %a.ptr = bitcast i8* %5 to %Int.st*
  %a7 = load %Int.st* %a.ptr
  %"+.res" = call %Int.st @-P_Int_Int(%Int.st %b, %Int.st %a7), !stdlib.call.optim !0
  %"+.res8" = call %Int.st @-P_Int_Int(%Int.st %b2, %Int.st %"+.res"), !stdlib.call.optim !0
  ret %Int.st %"+.res8"
}

declare %Int.st @-P_Int_Int(%Int.st, %Int.st)

; Function Attrs: alwaysinline
define %Bar.st @Bar_Int_Int(%Int.st %"$0", %Int.st %"$1") #0 {
entry:
  %Bar = alloca %Bar.st
  %Bar.b.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 0
  store %Int.st %"$0", %Int.st* %Bar.b.ptr
  %Bar.a.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 1
  store %Int.st %"$1", %Int.st* %Bar.a.ptr
  %Bar1 = load %Bar.st* %Bar
  ret %Bar.st %Bar1
}

define internal %Int.st @Bar.function_Int(%Bar.st* %self, %Int.st %x) {
entry:
  %self.a.ptr = getelementptr inbounds %Bar.st* %self, i32 0, i32 1
  %self.a = load %Int.st* %self.a.ptr
  %self.b.ptr = getelementptr inbounds %Bar.st* %self, i32 0, i32 0
  %self.b = load %Int.st* %self.b.ptr
  %"+.res" = call %Int.st @-P_Int_Int(%Int.st %self.a, %Int.st %self.b), !stdlib.call.optim !0
  %"+.res1" = call %Int.st @-P_Int_Int(%Int.st %x, %Int.st %"+.res"), !stdlib.call.optim !0
  ret %Int.st %"+.res1"
}

declare %Int.st @Int_i64(i64)

declare void @print_Int(%Int.st)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
