; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bool.st = type { i1 }
%Int.st = type { i64 }
%Bar.st = type { %Bool.st, %Int.st, %Int.st }
%Eq.ex = type { [2 x i32], [1 x i8*], i8* }

define void @main() {
entry:
  %0 = call %Bool.st @Bool_b(i1 true), !stdlib.call.optim !0
  %1 = call %Int.st @Int_i64(i64 11), !stdlib.call.optim !0
  %2 = call %Int.st @Int_i64(i64 4), !stdlib.call.optim !0
  %Bar_res = call %Bar.st @Bar_Bool_Int_Int(%Bool.st %0, %Int.st %1, %Int.st %2)
  %bar = alloca %Bar.st
  store %Bar.st %Bar_res, %Bar.st* %bar
  %bar1 = load %Bar.st* %bar
  %3 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %4 = alloca %Bar.st
  %5 = alloca %Eq.ex
  %.prop_metadata = getelementptr inbounds %Eq.ex* %5, i32 0, i32 0
  %.method_metadata = getelementptr inbounds %Eq.ex* %5, i32 0, i32 1
  %.opaque = getelementptr inbounds %Eq.ex* %5, i32 0, i32 2
  %metadata = alloca [2 x i32]
  %6 = bitcast [2 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %6, i32 0
  store i32 16, i32* %el.0
  %el.1 = getelementptr i32* %6, i32 1
  store i32 8, i32* %el.1
  %7 = load [2 x i32]* %metadata
  store [2 x i32] %7, [2 x i32]* %.prop_metadata
  %metadata2 = alloca [1 x i8*]
  %8 = bitcast [1 x i8*]* %metadata2 to i8**
  %el.03 = getelementptr i8** %8, i32 0
  store i8* bitcast (%Int.st ()* @Bar.Eq.sum-U_ to i8*), i8** %el.03
  %9 = load [1 x i8*]* %metadata2
  store [1 x i8*] %9, [1 x i8*]* %.method_metadata
  store %Bar.st %bar1, %Bar.st* %4
  %10 = bitcast %Bar.st* %4 to i8*
  store i8* %10, i8** %.opaque
  %11 = load %Eq.ex* %5
  %foo_res = call %Int.st @foo_Eq_Int(%Eq.ex %11, %Int.st %3)
  %foo = alloca %Int.st
  store %Int.st %foo_res, %Int.st* %foo
  %foo4 = load %Int.st* %foo
  call void @print_Int(%Int.st %foo4), !stdlib.call.optim !0
  ret void
}

; Function Attrs: alwaysinline
define %Bar.st @Bar_Bool_Int_Int(%Bool.st %"$0", %Int.st %"$1", %Int.st %"$2") #0 {
entry:
  %Bar = alloca %Bar.st
  %Bar.x.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 0
  store %Bool.st %"$0", %Bool.st* %Bar.x.ptr
  %Bar.b.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 1
  store %Int.st %"$1", %Int.st* %Bar.b.ptr
  %Bar.a.ptr = getelementptr inbounds %Bar.st* %Bar, i32 0, i32 2
  store %Int.st %"$2", %Int.st* %Bar.a.ptr
  %Bar1 = load %Bar.st* %Bar
  ret %Bar.st %Bar1
}

define internal %Int.st @Bar.sum_(%Bar.st* %self) {
entry:
  %self.a.ptr = getelementptr inbounds %Bar.st* %self, i32 0, i32 2
  %self.a = load %Int.st* %self.a.ptr
  %self.b.ptr = getelementptr inbounds %Bar.st* %self, i32 0, i32 1
  %self.b = load %Int.st* %self.b.ptr
  %"+.res" = call %Int.st @-P_Int_Int(%Int.st %self.a, %Int.st %self.b), !stdlib.call.optim !0
  ret %Int.st %"+.res"
}

declare %Int.st @-P_Int_Int(%Int.st, %Int.st)

define internal %Int.st @foo_Eq_Int(%Eq.ex %a, %Int.st %b) {
entry:
  %a1 = alloca %Eq.ex
  store %Eq.ex %a, %Eq.ex* %a1
  %a.metadata_ptr = getelementptr inbounds %Eq.ex* %a1, i32 0, i32 0
  %metadata_base_ptr = bitcast [2 x i32]* %a.metadata_ptr to i32*
  %0 = getelementptr i32* %metadata_base_ptr, i32 0
  %1 = load i32* %0
  %a.element_pointer = getelementptr inbounds %Eq.ex* %a1, i32 0, i32 2
  %a.opaque_instance_pointer = load i8** %a.element_pointer
  %2 = getelementptr i8* %a.opaque_instance_pointer, i32 %1
  %a.ptr = bitcast i8* %2 to %Int.st*
  %a2 = load %Int.st* %a.ptr
  %"+.res" = call %Int.st @-P_Int_Int(%Int.st %a2, %Int.st %b), !stdlib.call.optim !0
  ret %Int.st %"+.res"
}

declare %Bool.st @Bool_b(i1)

declare %Int.st @Int_i64(i64)

declare %Int.st @Bar.Eq.sum-U_()

declare void @print_Int(%Int.st)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
