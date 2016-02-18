; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%I.st = type { %Int.st }
%A.st = type { %I.st }
%X.ex = type { [1 x i32], i8* }
%B.st = type { %X.ex }

define void @main() {
entry:
  %0 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %I_res = call %I.st @I_Int(%Int.st %0)
  %A_res = call %A.st @A_I(%I.st %I_res)
  %1 = alloca %A.st
  %2 = alloca %X.ex
  %.metadata = getelementptr inbounds %X.ex* %2, i32 0, i32 0
  %.opaque = getelementptr inbounds %X.ex* %2, i32 0, i32 1
  %metadata = alloca [1 x i32]
  %3 = bitcast [1 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %3, i32 0
  store i32 0, i32* %el.0
  %4 = load [1 x i32]* %metadata
  store [1 x i32] %4, [1 x i32]* %.metadata
  store %A.st %A_res, %A.st* %1
  %5 = bitcast %A.st* %1 to i8*
  store i8* %5, i8** %.opaque
  %6 = load %X.ex* %2
  %B_res = call %B.st @B_X(%X.ex %6)
  %u = alloca %B.st
  store %B.st %B_res, %B.st* %u
  %u.a.ptr = getelementptr inbounds %B.st* %u, i32 0, i32 0
  %u.a.ptr1 = getelementptr inbounds %B.st* %u, i32 0, i32 0
  %u.a = load %X.ex* %u.a.ptr1
  %.metadata_ptr = getelementptr inbounds %X.ex* %u.a.ptr, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %.metadata_ptr to i32*
  %7 = getelementptr i32* %metadata_base_ptr, i32 0
  %8 = load i32* %7
  %.element_pointer = getelementptr inbounds %X.ex* %u.a.ptr, i32 0, i32 1
  %.opaque_instance_pointer = load i8** %.element_pointer
  %9 = getelementptr i8* %.opaque_instance_pointer, i32 %8
  %i.ptr = bitcast i8* %9 to %I.st*
  %.metadata_ptr2 = getelementptr inbounds %X.ex* %u.a.ptr, i32 0, i32 0
  %metadata_base_ptr3 = bitcast [1 x i32]* %.metadata_ptr2 to i32*
  %10 = getelementptr i32* %metadata_base_ptr3, i32 0
  %11 = load i32* %10
  %.element_pointer4 = getelementptr inbounds %X.ex* %u.a.ptr, i32 0, i32 1
  %.opaque_instance_pointer5 = load i8** %.element_pointer4
  %12 = getelementptr i8* %.opaque_instance_pointer5, i32 %11
  %i.ptr6 = bitcast i8* %12 to %I.st*
  %i = load %I.st* %i.ptr6
  store %I.st %i, %I.st* %i.ptr
  %13 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %.v.ptr = getelementptr inbounds %I.st* %i.ptr, i32 0, i32 0
  store %Int.st %13, %Int.st* %.v.ptr
  %u.a.ptr7 = getelementptr inbounds %B.st* %u, i32 0, i32 0
  %u.a.ptr8 = getelementptr inbounds %B.st* %u, i32 0, i32 0
  %u.a9 = load %X.ex* %u.a.ptr8
  %.metadata_ptr10 = getelementptr inbounds %X.ex* %u.a.ptr7, i32 0, i32 0
  %metadata_base_ptr11 = bitcast [1 x i32]* %.metadata_ptr10 to i32*
  %14 = getelementptr i32* %metadata_base_ptr11, i32 0
  %15 = load i32* %14
  %.element_pointer12 = getelementptr inbounds %X.ex* %u.a.ptr7, i32 0, i32 1
  %.opaque_instance_pointer13 = load i8** %.element_pointer12
  %16 = getelementptr i8* %.opaque_instance_pointer13, i32 %15
  %i.ptr14 = bitcast i8* %16 to %I.st*
  %.metadata_ptr15 = getelementptr inbounds %X.ex* %u.a.ptr7, i32 0, i32 0
  %metadata_base_ptr16 = bitcast [1 x i32]* %.metadata_ptr15 to i32*
  %17 = getelementptr i32* %metadata_base_ptr16, i32 0
  %18 = load i32* %17
  %.element_pointer17 = getelementptr inbounds %X.ex* %u.a.ptr7, i32 0, i32 1
  %.opaque_instance_pointer18 = load i8** %.element_pointer17
  %19 = getelementptr i8* %.opaque_instance_pointer18, i32 %18
  %i.ptr19 = bitcast i8* %19 to %I.st*
  %i20 = load %I.st* %i.ptr19
  store %I.st %i20, %I.st* %i.ptr14
  %.v.ptr21 = getelementptr inbounds %I.st* %i.ptr14, i32 0, i32 0
  %.v = load %Int.st* %.v.ptr21
  call void @print_Int(%Int.st %.v), !stdlib.call.optim !0
  ret void
}

; Function Attrs: alwaysinline
define %I.st @I_Int(%Int.st %"$0") #0 {
entry:
  %I = alloca %I.st
  %I.v.ptr = getelementptr inbounds %I.st* %I, i32 0, i32 0
  store %Int.st %"$0", %Int.st* %I.v.ptr
  %I1 = load %I.st* %I
  ret %I.st %I1
}

; Function Attrs: alwaysinline
define %A.st @A_I(%I.st %"$0") #0 {
entry:
  %A = alloca %A.st
  %A.i.ptr = getelementptr inbounds %A.st* %A, i32 0, i32 0
  store %I.st %"$0", %I.st* %A.i.ptr
  %A1 = load %A.st* %A
  ret %A.st %A1
}

; Function Attrs: alwaysinline
define %B.st @B_X(%X.ex %"$0") #0 {
entry:
  %param0 = alloca %X.ex
  store %X.ex %"$0", %X.ex* %param0
  %B = alloca %B.st
  %param01 = load %X.ex* %param0
  %B.a.ptr = getelementptr inbounds %B.st* %B, i32 0, i32 0
  store %X.ex %param01, %X.ex* %B.a.ptr
  %B2 = load %B.st* %B
  ret %B.st %B2
}

declare %Int.st @Int_i64(i64)

declare void @print_Int(%Int.st)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
