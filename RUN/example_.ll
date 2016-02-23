; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bool.st = type { i1 }
%Int.st = type { i64 }
%Bar.st = type { %Bool.st, %Int.st, %Int.st }
%Baz.st = type { %Int.st, %Int.st }
%Eq.ex = type { [2 x i32], [1 x i8*], i8* }

define void @main() {
entry:
  %0 = call %Bool.st @Bool_b(i1 true), !stdlib.call.optim !0
  %1 = call %Int.st @Int_i64(i64 11), !stdlib.call.optim !0
  %2 = call %Int.st @Int_i64(i64 4), !stdlib.call.optim !0
  %Bar_res = call %Bar.st @Bar_Bool_Int_Int(%Bool.st %0, %Int.st %1, %Int.st %2)
  %bar = alloca %Bar.st
  store %Bar.st %Bar_res, %Bar.st* %bar
  %3 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %4 = call %Int.st @Int_i64(i64 3), !stdlib.call.optim !0
  %Baz_res = call %Baz.st @Baz_Int_Int(%Int.st %3, %Int.st %4)
  %baz = alloca %Baz.st
  store %Baz.st %Baz_res, %Baz.st* %baz
  %bar1 = load %Bar.st* %bar
  %5 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %6 = alloca %Bar.st
  %7 = alloca %Eq.ex
  %.prop_metadata = getelementptr inbounds %Eq.ex* %7, i32 0, i32 0
  %.method_metadata = getelementptr inbounds %Eq.ex* %7, i32 0, i32 1
  %.opaque = getelementptr inbounds %Eq.ex* %7, i32 0, i32 2
  %metadata = alloca [2 x i32]
  %8 = bitcast [2 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %8, i32 0
  store i32 16, i32* %el.0
  %el.1 = getelementptr i32* %8, i32 1
  store i32 8, i32* %el.1
  %9 = load [2 x i32]* %metadata
  store [2 x i32] %9, [2 x i32]* %.prop_metadata
  %metadata2 = alloca [1 x i8*]
  %10 = bitcast [1 x i8*]* %metadata2 to i8**
  %el.03 = getelementptr i8** %10, i32 0
  store i8* bitcast (%Int.st (%Bar.st*)* @Bar.sum_ to i8*), i8** %el.03
  %11 = load [1 x i8*]* %metadata2
  store [1 x i8*] %11, [1 x i8*]* %.method_metadata
  store %Bar.st %bar1, %Bar.st* %6
  %12 = bitcast %Bar.st* %6 to i8*
  store i8* %12, i8** %.opaque
  %13 = load %Eq.ex* %7
  %foo_res = call %Int.st @foo_Eq_Int(%Eq.ex %13, %Int.st %5)
  call void @print_Int(%Int.st %foo_res), !stdlib.call.optim !0
  %bar4 = load %Bar.st* %bar
  %14 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %15 = alloca %Bar.st
  %16 = alloca %Eq.ex
  %.prop_metadata5 = getelementptr inbounds %Eq.ex* %16, i32 0, i32 0
  %.method_metadata6 = getelementptr inbounds %Eq.ex* %16, i32 0, i32 1
  %.opaque7 = getelementptr inbounds %Eq.ex* %16, i32 0, i32 2
  %metadata8 = alloca [2 x i32]
  %17 = bitcast [2 x i32]* %metadata8 to i32*
  %el.09 = getelementptr i32* %17, i32 0
  store i32 16, i32* %el.09
  %el.110 = getelementptr i32* %17, i32 1
  store i32 8, i32* %el.110
  %18 = load [2 x i32]* %metadata8
  store [2 x i32] %18, [2 x i32]* %.prop_metadata5
  %metadata11 = alloca [1 x i8*]
  %19 = bitcast [1 x i8*]* %metadata11 to i8**
  %el.012 = getelementptr i8** %19, i32 0
  store i8* bitcast (%Int.st (%Bar.st*)* @Bar.sum_ to i8*), i8** %el.012
  %20 = load [1 x i8*]* %metadata11
  store [1 x i8*] %20, [1 x i8*]* %.method_metadata6
  store %Bar.st %bar4, %Bar.st* %15
  %21 = bitcast %Bar.st* %15 to i8*
  store i8* %21, i8** %.opaque7
  %22 = load %Eq.ex* %16
  %foo2_res = call %Int.st @foo2_Eq_Int(%Eq.ex %22, %Int.st %14)
  call void @print_Int(%Int.st %foo2_res), !stdlib.call.optim !0
  %baz13 = load %Baz.st* %baz
  %23 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %24 = alloca %Baz.st
  %25 = alloca %Eq.ex
  %.prop_metadata14 = getelementptr inbounds %Eq.ex* %25, i32 0, i32 0
  %.method_metadata15 = getelementptr inbounds %Eq.ex* %25, i32 0, i32 1
  %.opaque16 = getelementptr inbounds %Eq.ex* %25, i32 0, i32 2
  %metadata17 = alloca [2 x i32]
  %26 = bitcast [2 x i32]* %metadata17 to i32*
  %el.018 = getelementptr i32* %26, i32 0
  store i32 0, i32* %el.018
  %el.119 = getelementptr i32* %26, i32 1
  store i32 8, i32* %el.119
  %27 = load [2 x i32]* %metadata17
  store [2 x i32] %27, [2 x i32]* %.prop_metadata14
  %metadata20 = alloca [1 x i8*]
  %28 = bitcast [1 x i8*]* %metadata20 to i8**
  %el.021 = getelementptr i8** %28, i32 0
  store i8* bitcast (%Int.st (%Baz.st*)* @Baz.sum_ to i8*), i8** %el.021
  %29 = load [1 x i8*]* %metadata20
  store [1 x i8*] %29, [1 x i8*]* %.method_metadata15
  store %Baz.st %baz13, %Baz.st* %24
  %30 = bitcast %Baz.st* %24 to i8*
  store i8* %30, i8** %.opaque16
  %31 = load %Eq.ex* %25
  %foo_res22 = call %Int.st @foo_Eq_Int(%Eq.ex %31, %Int.st %23)
  call void @print_Int(%Int.st %foo_res22), !stdlib.call.optim !0
  %32 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %33 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %"<<.res" = call %Int.st @-L-L_Int_Int(%Int.st %32, %Int.st %33), !stdlib.call.optim !0
  call void @print_Int(%Int.st %"<<.res"), !stdlib.call.optim !0
  %34 = call %Int.st @Int_i64(i64 8), !stdlib.call.optim !0
  %35 = call %Int.st @Int_i64(i64 3), !stdlib.call.optim !0
  %">>.res" = call %Int.st @-G-G_Int_Int(%Int.st %34, %Int.st %35), !stdlib.call.optim !0
  call void @print_Int(%Int.st %">>.res"), !stdlib.call.optim !0
  %36 = call %Int.st @Int_i64(i64 6), !stdlib.call.optim !0
  %37 = call %Int.st @Int_i64(i64 5), !stdlib.call.optim !0
  %"~&.res" = call %Int.st @-T-N_Int_Int(%Int.st %36, %Int.st %37), !stdlib.call.optim !0
  call void @print_Int(%Int.st %"~&.res"), !stdlib.call.optim !0
  %38 = call %Int.st @Int_i64(i64 5), !stdlib.call.optim !0
  %39 = call %Int.st @Int_i64(i64 3), !stdlib.call.optim !0
  %"~|.res" = call %Int.st @-T-O_Int_Int(%Int.st %38, %Int.st %39), !stdlib.call.optim !0
  call void @print_Int(%Int.st %"~|.res"), !stdlib.call.optim !0
  %40 = call %Int.st @Int_i64(i64 5), !stdlib.call.optim !0
  %41 = call %Int.st @Int_i64(i64 3), !stdlib.call.optim !0
  %"~^.res" = call %Int.st @-T-R_Int_Int(%Int.st %40, %Int.st %41), !stdlib.call.optim !0
  call void @print_Int(%Int.st %"~^.res"), !stdlib.call.optim !0
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

; Function Attrs: alwaysinline
define %Baz.st @Baz_Int_Int(%Int.st %"$0", %Int.st %"$1") #0 {
entry:
  %Baz = alloca %Baz.st
  %Baz.a.ptr = getelementptr inbounds %Baz.st* %Baz, i32 0, i32 0
  store %Int.st %"$0", %Int.st* %Baz.a.ptr
  %Baz.b.ptr = getelementptr inbounds %Baz.st* %Baz, i32 0, i32 1
  store %Int.st %"$1", %Int.st* %Baz.b.ptr
  %Baz1 = load %Baz.st* %Baz
  ret %Baz.st %Baz1
}

define internal %Int.st @Baz.sum_(%Baz.st* %self) {
entry:
  %0 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  ret %Int.st %0
}

declare %Int.st @Int_i64(i64)

define internal %Int.st @foo_Eq_Int(%Eq.ex %a, %Int.st %b) {
entry:
  %a1 = alloca %Eq.ex
  store %Eq.ex %a, %Eq.ex* %a1
  %a2 = load %Eq.ex* %a1
  %a.vtable_ptr = getelementptr inbounds %Eq.ex* %a1, i32 0, i32 1
  %a.vtable_base_ptr = bitcast [1 x i8*]* %a.vtable_ptr to i8**
  %0 = getelementptr i8** %a.vtable_base_ptr, i32 0
  %1 = load i8** %0
  %sum = bitcast i8* %1 to %Int.st (i8*)*
  %a.element_pointer = getelementptr inbounds %Eq.ex* %a1, i32 0, i32 2
  %a.opaque_instance_pointer = load i8** %a.element_pointer
  %sum.res = call %Int.st %sum(i8* %a.opaque_instance_pointer)
  %"+.res" = call %Int.st @-P_Int_Int(%Int.st %sum.res, %Int.st %b), !stdlib.call.optim !0
  ret %Int.st %"+.res"
}

define internal %Int.st @foo2_Eq_Int(%Eq.ex %a, %Int.st %b) {
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
  %3 = getelementptr i32* %metadata_base_ptr, i32 1
  %4 = load i32* %3
  %5 = getelementptr i8* %a.opaque_instance_pointer, i32 %4
  %b.ptr = bitcast i8* %5 to %Int.st*
  %b3 = load %Int.st* %b.ptr
  %6 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %"*.res" = call %Int.st @-A_Int_Int(%Int.st %b3, %Int.st %6), !stdlib.call.optim !0
  %"+.res" = call %Int.st @-P_Int_Int(%Int.st %"*.res", %Int.st %b), !stdlib.call.optim !0
  %"+.res4" = call %Int.st @-P_Int_Int(%Int.st %a2, %Int.st %"+.res"), !stdlib.call.optim !0
  ret %Int.st %"+.res4"
}

declare %Int.st @-A_Int_Int(%Int.st, %Int.st)

declare %Bool.st @Bool_b(i1)

declare void @print_Int(%Int.st)

declare %Int.st @-L-L_Int_Int(%Int.st, %Int.st)

declare %Int.st @-G-G_Int_Int(%Int.st, %Int.st)

declare %Int.st @-T-N_Int_Int(%Int.st, %Int.st)

declare %Int.st @-T-O_Int_Int(%Int.st, %Int.st)

declare %Int.st @-T-R_Int_Int(%Int.st, %Int.st)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
