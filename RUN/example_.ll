; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Foo.ex = type { [2 x i32], [1 x i8*], i8* }
%Bar.st = type { %Int.st, %Int.st, %Bool.st }
%Bool.st = type { i1 }

define %Int.st @unbox_Foo(%Foo.ex %box) {
entry:
  %0 = alloca %Foo.ex
  store %Foo.ex %box, %Foo.ex* %0
  %metadata_ptr = getelementptr inbounds %Foo.ex* %0, i32 0, i32 0
  %metadata_base_ptr = bitcast [2 x i32]* %metadata_ptr to i32*
  %1 = getelementptr i32* %metadata_base_ptr, i32 0
  %2 = load i32* %1
  %element_pointer = getelementptr inbounds %Foo.ex* %0, i32 0, i32 2
  %opaque_instance_pointer = load i8** %element_pointer
  %3 = getelementptr i8* %opaque_instance_pointer, i32 %2
  %ptr = bitcast i8* %3 to %Int.st*
  %4 = load %Int.st* %ptr
  ret %Int.st %4
}

declare %Int.st @Foo.aye_()

define %Int.st @Bar.aye_(%Bar.st* %self) {
entry:
  %c = getelementptr inbounds %Bar.st* %self, i32 0, i32 2
  %0 = load %Bool.st* %c
  %1 = extractvalue %Bool.st %0, 0
  br i1 %1, label %if.0, label %fail.0

if.0:                                             ; preds = %entry
  %a = getelementptr inbounds %Bar.st* %self, i32 0, i32 1
  %2 = load %Int.st* %a
  ret %Int.st %2

fail.0:                                           ; preds = %entry
  br label %else.1

else.1:                                           ; preds = %fail.0
  %b = getelementptr inbounds %Bar.st* %self, i32 0, i32 0
  %3 = load %Int.st* %b
  ret %Int.st %3
}

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

define void @main() {
entry:
  %0 = call %Bar.st @Bar_Int_Int_Bool(%Int.st { i64 1 }, %Int.st { i64 2 }, %Bool.st zeroinitializer)
  %b = alloca %Bar.st
  store %Bar.st %0, %Bar.st* %b
  %1 = alloca %Bar.st
  store %Bar.st %0, %Bar.st* %1
  %2 = alloca %Bar.st
  %3 = alloca %Foo.ex
  %nilprop_metadata = getelementptr inbounds %Foo.ex* %3, i32 0, i32 0
  %nilmethod_metadata = getelementptr inbounds %Foo.ex* %3, i32 0, i32 1
  %nilopaque = getelementptr inbounds %Foo.ex* %3, i32 0, i32 2
  %metadata = alloca [2 x i32]
  %4 = bitcast [2 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %4, i32 0
  store i32 8, i32* %el.0
  %el.1 = getelementptr i32* %4, i32 1
  store i32 16, i32* %el.1
  %5 = load [2 x i32]* %metadata
  store [2 x i32] %5, [2 x i32]* %nilprop_metadata
  %witness_table = alloca [1 x i8*]
  %6 = bitcast [1 x i8*]* %witness_table to i8**
  %el.01 = getelementptr i8** %6, i32 0
  store i8* bitcast (%Int.st (%Bar.st*)* @Bar.aye_ to i8*), i8** %el.01
  %7 = load [1 x i8*]* %witness_table
  store [1 x i8*] %7, [1 x i8*]* %nilmethod_metadata
  %8 = load %Bar.st* %1
  store %Bar.st %8, %Bar.st* %2
  %9 = bitcast %Bar.st* %2 to i8*
  store i8* %9, i8** %nilopaque
  %10 = load %Foo.ex* %3
  %11 = call %Int.st @unbox_Foo(%Foo.ex %10)
  %a = alloca %Int.st
  store %Int.st %11, %Int.st* %a
  call void @print_Int(%Int.st %11), !stdlib.call.optim !0
  %12 = alloca %Bar.st
  store %Bar.st %0, %Bar.st* %12
  %13 = alloca %Bar.st
  %14 = alloca %Foo.ex
  %nilprop_metadata2 = getelementptr inbounds %Foo.ex* %14, i32 0, i32 0
  %nilmethod_metadata3 = getelementptr inbounds %Foo.ex* %14, i32 0, i32 1
  %nilopaque4 = getelementptr inbounds %Foo.ex* %14, i32 0, i32 2
  %metadata5 = alloca [2 x i32]
  %15 = bitcast [2 x i32]* %metadata5 to i32*
  %el.06 = getelementptr i32* %15, i32 0
  store i32 8, i32* %el.06
  %el.17 = getelementptr i32* %15, i32 1
  store i32 16, i32* %el.17
  %16 = load [2 x i32]* %metadata5
  store [2 x i32] %16, [2 x i32]* %nilprop_metadata2
  %witness_table8 = alloca [1 x i8*]
  %17 = bitcast [1 x i8*]* %witness_table8 to i8**
  %el.09 = getelementptr i8** %17, i32 0
  store i8* bitcast (%Int.st (%Bar.st*)* @Bar.aye_ to i8*), i8** %el.09
  %18 = load [1 x i8*]* %witness_table8
  store [1 x i8*] %18, [1 x i8*]* %nilmethod_metadata3
  %19 = load %Bar.st* %12
  store %Bar.st %19, %Bar.st* %13
  %20 = bitcast %Bar.st* %13 to i8*
  store i8* %20, i8** %nilopaque4
  %21 = load %Foo.ex* %14
  %22 = call %Int.st @callAye_Foo(%Foo.ex %21)
  call void @print_Int(%Int.st %22), !stdlib.call.optim !0
  ret void
}

declare void @print_Int(%Int.st)

define %Int.st @callAye_Foo(%Foo.ex %box) {
entry:
  %0 = alloca %Foo.ex
  store %Foo.ex %box, %Foo.ex* %0
  %witness.witness_table_ptr = getelementptr inbounds %Foo.ex* %0, i32 0, i32 1
  %witness.witness_table_base_ptr = bitcast [1 x i8*]* %witness.witness_table_ptr to i8**
  %1 = getelementptr i8** %witness.witness_table_base_ptr, i32 0
  %2 = load i8** %1
  %"%witness" = bitcast i8* %2 to %Int.st (i8*)*
  %3 = getelementptr inbounds %Foo.ex* %0, i32 0, i32 2
  %unboxed = load i8** %3
  %4 = call %Int.st %"%witness"(i8* %unboxed)
  ret %Int.st %4
}

!0 = !{!"stdlib.call.optim"}
