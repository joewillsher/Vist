; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Eq.ex = type { [2 x i32], [1 x i8*], i8* }
%Int = type { i64 }
%Bar = type { %Bool, %Int, %Int }
%Bool = type { i1 }
%Baz = type { %Int, %Int }

define %Int @foo_tEqInt(%Eq.ex %a, %Int %b) {
entry:
  %0 = alloca %Eq.ex
  store %Eq.ex %a, %Eq.ex* %0
  %witness.witness_table_ptr = getelementptr inbounds %Eq.ex* %0, i32 0, i32 1
  %witness.witness_table_base_ptr = bitcast [1 x i8*]* %witness.witness_table_ptr to i8**
  %1 = getelementptr i8** %witness.witness_table_base_ptr, i32 0
  %2 = load i8** %1
  %witness = bitcast i8* %2 to %Int (i8*)*
  %3 = getelementptr inbounds %Eq.ex* %0, i32 0, i32 2
  %unboxed = load i8** %3
  %4 = call %Int %witness(i8* %unboxed)
  %5 = call %Int @-P_tIntInt(%Int %4, %Int %b), !stdlib.call.optim !0
  ret %Int %5
}

define %Int @foo2_tEqInt(%Eq.ex %a, %Int %b) {
entry:
  %0 = alloca %Eq.ex
  store %Eq.ex %a, %Eq.ex* %0
  %metadata_ptr = getelementptr inbounds %Eq.ex* %0, i32 0, i32 0
  %metadata_base_ptr = bitcast [2 x i32]* %metadata_ptr to i32*
  %1 = getelementptr i32* %metadata_base_ptr, i32 0
  %2 = load i32* %1
  %element_pointer = getelementptr inbounds %Eq.ex* %0, i32 0, i32 2
  %opaque_instance_pointer = load i8** %element_pointer
  %3 = getelementptr i8* %opaque_instance_pointer, i32 %2
  %ptr = bitcast i8* %3 to %Int*
  %4 = load %Int* %ptr
  %5 = alloca %Eq.ex
  store %Eq.ex %a, %Eq.ex* %5
  %metadata_ptr1 = getelementptr inbounds %Eq.ex* %5, i32 0, i32 0
  %metadata_base_ptr2 = bitcast [2 x i32]* %metadata_ptr1 to i32*
  %6 = getelementptr i32* %metadata_base_ptr2, i32 1
  %7 = load i32* %6
  %element_pointer3 = getelementptr inbounds %Eq.ex* %5, i32 0, i32 2
  %opaque_instance_pointer4 = load i8** %element_pointer3
  %8 = getelementptr i8* %opaque_instance_pointer4, i32 %7
  %ptr5 = bitcast i8* %8 to %Int*
  %9 = load %Int* %ptr5
  %10 = call %Int @-A_tIntInt(%Int %9, %Int { i64 2 }), !stdlib.call.optim !0
  %11 = call %Int @-P_tIntInt(%Int %10, %Int %b), !stdlib.call.optim !0
  %12 = call %Int @-P_tIntInt(%Int %4, %Int %11), !stdlib.call.optim !0
  ret %Int %12
}

define %Bar @Bar_tBoolIntInt(%Bool %"$0", %Int %"$1", %Int %"$2") {
entry:
  %self = alloca %Bar
  %x = getelementptr inbounds %Bar* %self, i32 0, i32 0
  %b = getelementptr inbounds %Bar* %self, i32 0, i32 1
  %a = getelementptr inbounds %Bar* %self, i32 0, i32 2
  store %Bool %"$0", %Bool* %x
  store %Int %"$1", %Int* %b
  store %Int %"$2", %Int* %a
  %0 = load %Bar* %self
  ret %Bar %0
}

declare %Int @sum_t()

define %Baz @Baz_tIntInt(%Int %"$0", %Int %"$1") {
entry:
  %self = alloca %Baz
  %a = getelementptr inbounds %Baz* %self, i32 0, i32 0
  %b = getelementptr inbounds %Baz* %self, i32 0, i32 1
  store %Int %"$0", %Int* %a
  store %Int %"$1", %Int* %b
  %0 = load %Baz* %self
  ret %Baz %0
}

declare void @print_tInt(%Int)

define %Int @sum_mBar(%Bar* %self) {
entry:
  %a = getelementptr inbounds %Bar* %self, i32 0, i32 2
  %0 = load %Int* %a
  %b = getelementptr inbounds %Bar* %self, i32 0, i32 1
  %1 = load %Int* %b
  %2 = call %Int @-P_tIntInt(%Int %0, %Int %1), !stdlib.call.optim !0
  ret %Int %2
}

declare %Int @-P_tIntInt(%Int, %Int)

declare %Int @sum(%Bar*)

define void @main() {
entry:
  %0 = call %Bar @Bar_tBoolIntInt(%Bool { i1 true }, %Int { i64 11 }, %Int { i64 4 })
  %bar = alloca %Bar
  store %Bar %0, %Bar* %bar
  %1 = call %Baz @Baz_tIntInt(%Int { i64 2 }, %Int { i64 3 })
  %baz = alloca %Baz
  store %Baz %1, %Baz* %baz
  %2 = alloca %Bar
  store %Bar %0, %Bar* %2
  %3 = alloca %Bar
  %4 = alloca %Eq.ex
  %nilprop_metadata = getelementptr inbounds %Eq.ex* %4, i32 0, i32 0
  %nilmethod_metadata = getelementptr inbounds %Eq.ex* %4, i32 0, i32 1
  %nilopaque = getelementptr inbounds %Eq.ex* %4, i32 0, i32 2
  %metadata = alloca [2 x i32]
  %5 = bitcast [2 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %5, i32 0
  store i32 16, i32* %el.0
  %el.1 = getelementptr i32* %5, i32 1
  store i32 8, i32* %el.1
  %6 = load [2 x i32]* %metadata
  store [2 x i32] %6, [2 x i32]* %nilprop_metadata
  %witness_table = alloca [1 x i8*]
  %7 = bitcast [1 x i8*]* %witness_table to i8**
  %el.01 = getelementptr i8** %7, i32 0
  store i8* bitcast (%Int (%Bar*)* @sum_mBar to i8*), i8** %el.01
  %8 = load [1 x i8*]* %witness_table
  store [1 x i8*] %8, [1 x i8*]* %nilmethod_metadata
  %9 = load %Bar* %2
  store %Bar %9, %Bar* %3
  %10 = bitcast %Bar* %3 to i8*
  store i8* %10, i8** %nilopaque
  %11 = load %Eq.ex* %4
  %12 = call %Int @foo_tEqInt(%Eq.ex %11, %Int { i64 2 })
  call void @print_tInt(%Int %12), !stdlib.call.optim !0
  %13 = alloca %Bar
  store %Bar %0, %Bar* %13
  %14 = alloca %Bar
  %15 = alloca %Eq.ex
  %nilprop_metadata2 = getelementptr inbounds %Eq.ex* %15, i32 0, i32 0
  %nilmethod_metadata3 = getelementptr inbounds %Eq.ex* %15, i32 0, i32 1
  %nilopaque4 = getelementptr inbounds %Eq.ex* %15, i32 0, i32 2
  %metadata5 = alloca [2 x i32]
  %16 = bitcast [2 x i32]* %metadata5 to i32*
  %el.06 = getelementptr i32* %16, i32 0
  store i32 16, i32* %el.06
  %el.17 = getelementptr i32* %16, i32 1
  store i32 8, i32* %el.17
  %17 = load [2 x i32]* %metadata5
  store [2 x i32] %17, [2 x i32]* %nilprop_metadata2
  %witness_table8 = alloca [1 x i8*]
  %18 = bitcast [1 x i8*]* %witness_table8 to i8**
  %el.09 = getelementptr i8** %18, i32 0
  store i8* bitcast (%Int (%Bar*)* @sum_mBar to i8*), i8** %el.09
  %19 = load [1 x i8*]* %witness_table8
  store [1 x i8*] %19, [1 x i8*]* %nilmethod_metadata3
  %20 = load %Bar* %13
  store %Bar %20, %Bar* %14
  %21 = bitcast %Bar* %14 to i8*
  store i8* %21, i8** %nilopaque4
  %22 = load %Eq.ex* %15
  %23 = call %Int @foo2_tEqInt(%Eq.ex %22, %Int { i64 2 })
  call void @print_tInt(%Int %23), !stdlib.call.optim !0
  %24 = alloca %Baz
  store %Baz %1, %Baz* %24
  %25 = alloca %Baz
  %26 = alloca %Eq.ex
  %nilprop_metadata10 = getelementptr inbounds %Eq.ex* %26, i32 0, i32 0
  %nilmethod_metadata11 = getelementptr inbounds %Eq.ex* %26, i32 0, i32 1
  %nilopaque12 = getelementptr inbounds %Eq.ex* %26, i32 0, i32 2
  %metadata13 = alloca [2 x i32]
  %27 = bitcast [2 x i32]* %metadata13 to i32*
  %el.014 = getelementptr i32* %27, i32 0
  store i32 0, i32* %el.014
  %el.115 = getelementptr i32* %27, i32 1
  store i32 8, i32* %el.115
  %28 = load [2 x i32]* %metadata13
  store [2 x i32] %28, [2 x i32]* %nilprop_metadata10
  %witness_table16 = alloca [1 x i8*]
  %29 = bitcast [1 x i8*]* %witness_table16 to i8**
  %el.017 = getelementptr i8** %29, i32 0
  store i8* bitcast (%Int (%Baz*)* @sum_mBaz to i8*), i8** %el.017
  %30 = load [1 x i8*]* %witness_table16
  store [1 x i8*] %30, [1 x i8*]* %nilmethod_metadata11
  %31 = load %Baz* %24
  store %Baz %31, %Baz* %25
  %32 = bitcast %Baz* %25 to i8*
  store i8* %32, i8** %nilopaque12
  %33 = load %Eq.ex* %26
  %34 = call %Int @foo_tEqInt(%Eq.ex %33, %Int { i64 2 })
  call void @print_tInt(%Int %34), !stdlib.call.optim !0
  ret void
}

define %Int @sum_mBaz(%Baz* %self) {
entry:
  ret %Int { i64 1 }
}

declare %Int @-A_tIntInt(%Int, %Int)

!0 = !{!"stdlib.call.optim"}
