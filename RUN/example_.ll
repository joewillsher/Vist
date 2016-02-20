; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bool.st = type { i1 }
%Int.st = type { i64 }
%Bar.st = type { %Bool.st, %Int.st, %Int.st }
%Eq.ex = type { [2 x i32], i8* }
%Foo.st = type { %Int.st }
%TestC.ex = type { [1 x i32], i8* }
%Baz.st = type { %TestC.ex }
%Baq.st = type { %Int.st }
%Prot.ex = type { [1 x i32], i8* }
%I.st = type { %Int.st }
%A.st = type { %I.st }
%X.ex = type { [1 x i32], i8* }
%B.st = type { %X.ex }

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
  %.metadata = getelementptr inbounds %Eq.ex* %5, i32 0, i32 0
  %.opaque = getelementptr inbounds %Eq.ex* %5, i32 0, i32 1
  %metadata = alloca [2 x i32]
  %6 = bitcast [2 x i32]* %metadata to i32*
  %el.0 = getelementptr i32* %6, i32 0
  store i32 16, i32* %el.0
  %el.1 = getelementptr i32* %6, i32 1
  store i32 8, i32* %el.1
  %7 = load [2 x i32]* %metadata
  store [2 x i32] %7, [2 x i32]* %.metadata
  store %Bar.st %bar1, %Bar.st* %4
  %8 = bitcast %Bar.st* %4 to i8*
  store i8* %8, i8** %.opaque
  %9 = load %Eq.ex* %5
  %foo_res = call %Int.st @foo_Eq_Int(%Eq.ex %9, %Int.st %3)
  %foo = alloca %Int.st
  store %Int.st %foo_res, %Int.st* %foo
  %foo2 = load %Int.st* %foo
  call void @print_Int(%Int.st %foo2), !stdlib.call.optim !0
  %10 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %Foo_res = call %Foo.st @Foo_Int(%Int.st %10)
  %11 = alloca %Foo.st
  %12 = alloca %TestC.ex
  %.metadata3 = getelementptr inbounds %TestC.ex* %12, i32 0, i32 0
  %.opaque4 = getelementptr inbounds %TestC.ex* %12, i32 0, i32 1
  %metadata5 = alloca [1 x i32]
  %13 = bitcast [1 x i32]* %metadata5 to i32*
  %el.06 = getelementptr i32* %13, i32 0
  store i32 0, i32* %el.06
  %14 = load [1 x i32]* %metadata5
  store [1 x i32] %14, [1 x i32]* %.metadata3
  store %Foo.st %Foo_res, %Foo.st* %11
  %15 = bitcast %Foo.st* %11 to i8*
  store i8* %15, i8** %.opaque4
  %16 = load %TestC.ex* %12
  %Baz_res = call %Baz.st @Baz_TestC(%TestC.ex %16)
  %b = alloca %Baz.st
  store %Baz.st %Baz_res, %Baz.st* %b
  %b.foo.ptr = getelementptr inbounds %Baz.st* %b, i32 0, i32 0
  %b.foo.ptr7 = getelementptr inbounds %Baz.st* %b, i32 0, i32 0
  %b.foo = load %TestC.ex* %b.foo.ptr7
  %.metadata_ptr = getelementptr inbounds %TestC.ex* %b.foo.ptr, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %.metadata_ptr to i32*
  %17 = getelementptr i32* %metadata_base_ptr, i32 0
  %18 = load i32* %17
  %.element_pointer = getelementptr inbounds %TestC.ex* %b.foo.ptr, i32 0, i32 1
  %.opaque_instance_pointer = load i8** %.element_pointer
  %19 = getelementptr i8* %.opaque_instance_pointer, i32 %18
  %t.ptr = bitcast i8* %19 to %Int.st*
  %t = load %Int.st* %t.ptr
  %w = alloca %Int.st
  store %Int.st %t, %Int.st* %w
  %w8 = load %Int.st* %w
  call void @print_Int(%Int.st %w8), !stdlib.call.optim !0
  %20 = call %Int.st @Int_i64(i64 12), !stdlib.call.optim !0
  %Baq_res = call %Baq.st @Baq_Int(%Int.st %20)
  %uu = alloca %Baq.st
  store %Baq.st %Baq_res, %Baq.st* %uu
  %uu9 = load %Baq.st* %uu
  %21 = alloca %Baq.st
  %22 = alloca %Prot.ex
  %.metadata10 = getelementptr inbounds %Prot.ex* %22, i32 0, i32 0
  %.opaque11 = getelementptr inbounds %Prot.ex* %22, i32 0, i32 1
  %metadata12 = alloca [1 x i32]
  %23 = bitcast [1 x i32]* %metadata12 to i32*
  %el.013 = getelementptr i32* %23, i32 0
  store i32 0, i32* %el.013
  %24 = load [1 x i32]* %metadata12
  store [1 x i32] %24, [1 x i32]* %.metadata10
  store %Baq.st %uu9, %Baq.st* %21
  %25 = bitcast %Baq.st* %21 to i8*
  store i8* %25, i8** %.opaque11
  %26 = load %Prot.ex* %22
  call void @fn_Prot(%Prot.ex %26)
  %27 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %I_res = call %I.st @I_Int(%Int.st %27)
  %A_res = call %A.st @A_I(%I.st %I_res)
  %28 = alloca %A.st
  %29 = alloca %X.ex
  %.metadata14 = getelementptr inbounds %X.ex* %29, i32 0, i32 0
  %.opaque15 = getelementptr inbounds %X.ex* %29, i32 0, i32 1
  %metadata16 = alloca [1 x i32]
  %30 = bitcast [1 x i32]* %metadata16 to i32*
  %el.017 = getelementptr i32* %30, i32 0
  store i32 0, i32* %el.017
  %31 = load [1 x i32]* %metadata16
  store [1 x i32] %31, [1 x i32]* %.metadata14
  store %A.st %A_res, %A.st* %28
  %32 = bitcast %A.st* %28 to i8*
  store i8* %32, i8** %.opaque15
  %33 = load %X.ex* %29
  %B_res = call %B.st @B_X(%X.ex %33)
  %u = alloca %B.st
  store %B.st %B_res, %B.st* %u
  %u.a.ptr = getelementptr inbounds %B.st* %u, i32 0, i32 0
  %u.a.ptr18 = getelementptr inbounds %B.st* %u, i32 0, i32 0
  %u.a = load %X.ex* %u.a.ptr18
  %.metadata_ptr19 = getelementptr inbounds %X.ex* %u.a.ptr, i32 0, i32 0
  %metadata_base_ptr20 = bitcast [1 x i32]* %.metadata_ptr19 to i32*
  %34 = getelementptr i32* %metadata_base_ptr20, i32 0
  %35 = load i32* %34
  %.element_pointer21 = getelementptr inbounds %X.ex* %u.a.ptr, i32 0, i32 1
  %.opaque_instance_pointer22 = load i8** %.element_pointer21
  %36 = getelementptr i8* %.opaque_instance_pointer22, i32 %35
  %i.ptr = bitcast i8* %36 to %I.st*
  %.metadata_ptr23 = getelementptr inbounds %X.ex* %u.a.ptr, i32 0, i32 0
  %metadata_base_ptr24 = bitcast [1 x i32]* %.metadata_ptr23 to i32*
  %37 = getelementptr i32* %metadata_base_ptr24, i32 0
  %38 = load i32* %37
  %.element_pointer25 = getelementptr inbounds %X.ex* %u.a.ptr, i32 0, i32 1
  %.opaque_instance_pointer26 = load i8** %.element_pointer25
  %39 = getelementptr i8* %.opaque_instance_pointer26, i32 %38
  %i.ptr27 = bitcast i8* %39 to %I.st*
  %i = load %I.st* %i.ptr27
  store %I.st %i, %I.st* %i.ptr
  %40 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %.v.ptr = getelementptr inbounds %I.st* %i.ptr, i32 0, i32 0
  store %Int.st %40, %Int.st* %.v.ptr
  %u.a.ptr28 = getelementptr inbounds %B.st* %u, i32 0, i32 0
  %u.a.ptr29 = getelementptr inbounds %B.st* %u, i32 0, i32 0
  %u.a30 = load %X.ex* %u.a.ptr29
  %.metadata_ptr31 = getelementptr inbounds %X.ex* %u.a.ptr28, i32 0, i32 0
  %metadata_base_ptr32 = bitcast [1 x i32]* %.metadata_ptr31 to i32*
  %41 = getelementptr i32* %metadata_base_ptr32, i32 0
  %42 = load i32* %41
  %.element_pointer33 = getelementptr inbounds %X.ex* %u.a.ptr28, i32 0, i32 1
  %.opaque_instance_pointer34 = load i8** %.element_pointer33
  %43 = getelementptr i8* %.opaque_instance_pointer34, i32 %42
  %i.ptr35 = bitcast i8* %43 to %I.st*
  %.metadata_ptr36 = getelementptr inbounds %X.ex* %u.a.ptr28, i32 0, i32 0
  %metadata_base_ptr37 = bitcast [1 x i32]* %.metadata_ptr36 to i32*
  %44 = getelementptr i32* %metadata_base_ptr37, i32 0
  %45 = load i32* %44
  %.element_pointer38 = getelementptr inbounds %X.ex* %u.a.ptr28, i32 0, i32 1
  %.opaque_instance_pointer39 = load i8** %.element_pointer38
  %46 = getelementptr i8* %.opaque_instance_pointer39, i32 %45
  %i.ptr40 = bitcast i8* %46 to %I.st*
  %i41 = load %I.st* %i.ptr40
  store %I.st %i41, %I.st* %i.ptr35
  %.v.ptr42 = getelementptr inbounds %I.st* %i.ptr35, i32 0, i32 0
  %.v = load %Int.st* %.v.ptr42
  call void @print_Int(%Int.st %.v), !stdlib.call.optim !0
  %47 = call %Int.st @Int_i64(i64 1), !stdlib.call.optim !0
  %u43 = load %B.st* %u
  %48 = alloca { %Int.st, %B.st }
  %.0.ptr = getelementptr inbounds { %Int.st, %B.st }* %48, i32 0, i32 0
  store %Int.st %47, %Int.st* %.0.ptr
  %.1.ptr = getelementptr inbounds { %Int.st, %B.st }* %48, i32 0, i32 1
  store %B.st %u43, %B.st* %.1.ptr
  %49 = load { %Int.st, %B.st }* %48
  %50 = call %Int.st @Int_i64(i64 2), !stdlib.call.optim !0
  %51 = alloca { { %Int.st, %B.st }, %Int.st }
  %.0.ptr44 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %51, i32 0, i32 0
  store { %Int.st, %B.st } %49, { %Int.st, %B.st }* %.0.ptr44
  %.1.ptr45 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %51, i32 0, i32 1
  store %Int.st %50, %Int.st* %.1.ptr45
  %52 = load { { %Int.st, %B.st }, %Int.st }* %51
  %x = alloca { { %Int.st, %B.st }, %Int.st }
  store { { %Int.st, %B.st }, %Int.st } %52, { { %Int.st, %B.st }, %Int.st }* %x
  %x.1.ptr = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i32 0, i32 1
  %x.1 = load %Int.st* %x.1.ptr
  call void @print_Int(%Int.st %x.1), !stdlib.call.optim !0
  %x.0.ptr = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i32 0, i32 0
  %x.0.ptr46 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i32 0, i32 0
  %x.0 = load { %Int.st, %B.st }* %x.0.ptr46
  store { %Int.st, %B.st } %x.0, { %Int.st, %B.st }* %x.0.ptr
  %.0.ptr47 = getelementptr inbounds { %Int.st, %B.st }* %x.0.ptr, i32 0, i32 0
  %.0 = load %Int.st* %.0.ptr47
  call void @print_Int(%Int.st %.0), !stdlib.call.optim !0
  %x.0.ptr48 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i32 0, i32 0
  %x.0.ptr49 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i32 0, i32 0
  %x.050 = load { %Int.st, %B.st }* %x.0.ptr49
  store { %Int.st, %B.st } %x.050, { %Int.st, %B.st }* %x.0.ptr48
  %.1.ptr51 = getelementptr inbounds { %Int.st, %B.st }* %x.0.ptr48, i32 0, i32 1
  %.1.ptr52 = getelementptr inbounds { %Int.st, %B.st }* %x.0.ptr48, i32 0, i32 1
  %.1 = load %B.st* %.1.ptr52
  store %B.st %.1, %B.st* %.1.ptr51
  %.a.ptr = getelementptr inbounds %B.st* %.1.ptr51, i32 0, i32 0
  %.a.ptr53 = getelementptr inbounds %B.st* %.1.ptr51, i32 0, i32 0
  %.a = load %X.ex* %.a.ptr53
  %.metadata_ptr54 = getelementptr inbounds %X.ex* %.a.ptr, i32 0, i32 0
  %metadata_base_ptr55 = bitcast [1 x i32]* %.metadata_ptr54 to i32*
  %53 = getelementptr i32* %metadata_base_ptr55, i32 0
  %54 = load i32* %53
  %.element_pointer56 = getelementptr inbounds %X.ex* %.a.ptr, i32 0, i32 1
  %.opaque_instance_pointer57 = load i8** %.element_pointer56
  %55 = getelementptr i8* %.opaque_instance_pointer57, i32 %54
  %i.ptr58 = bitcast i8* %55 to %I.st*
  %.metadata_ptr59 = getelementptr inbounds %X.ex* %.a.ptr, i32 0, i32 0
  %metadata_base_ptr60 = bitcast [1 x i32]* %.metadata_ptr59 to i32*
  %56 = getelementptr i32* %metadata_base_ptr60, i32 0
  %57 = load i32* %56
  %.element_pointer61 = getelementptr inbounds %X.ex* %.a.ptr, i32 0, i32 1
  %.opaque_instance_pointer62 = load i8** %.element_pointer61
  %58 = getelementptr i8* %.opaque_instance_pointer62, i32 %57
  %i.ptr63 = bitcast i8* %58 to %I.st*
  %i64 = load %I.st* %i.ptr63
  store %I.st %i64, %I.st* %i.ptr58
  %.v.ptr65 = getelementptr inbounds %I.st* %i.ptr58, i32 0, i32 0
  %.v66 = load %Int.st* %.v.ptr65
  call void @print_Int(%Int.st %.v66), !stdlib.call.optim !0
  %x.0.ptr67 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i32 0, i32 0
  %x.0.ptr68 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i32 0, i32 0
  %x.069 = load { %Int.st, %B.st }* %x.0.ptr68
  store { %Int.st, %B.st } %x.069, { %Int.st, %B.st }* %x.0.ptr67
  %.1.ptr70 = getelementptr inbounds { %Int.st, %B.st }* %x.0.ptr67, i32 0, i32 1
  %.1.ptr71 = getelementptr inbounds { %Int.st, %B.st }* %x.0.ptr67, i32 0, i32 1
  %.172 = load %B.st* %.1.ptr71
  store %B.st %.172, %B.st* %.1.ptr70
  %.a.ptr73 = getelementptr inbounds %B.st* %.1.ptr70, i32 0, i32 0
  %.a.ptr74 = getelementptr inbounds %B.st* %.1.ptr70, i32 0, i32 0
  %.a75 = load %X.ex* %.a.ptr74
  %.metadata_ptr76 = getelementptr inbounds %X.ex* %.a.ptr73, i32 0, i32 0
  %metadata_base_ptr77 = bitcast [1 x i32]* %.metadata_ptr76 to i32*
  %59 = getelementptr i32* %metadata_base_ptr77, i32 0
  %60 = load i32* %59
  %.element_pointer78 = getelementptr inbounds %X.ex* %.a.ptr73, i32 0, i32 1
  %.opaque_instance_pointer79 = load i8** %.element_pointer78
  %61 = getelementptr i8* %.opaque_instance_pointer79, i32 %60
  %i.ptr80 = bitcast i8* %61 to %I.st*
  %.metadata_ptr81 = getelementptr inbounds %X.ex* %.a.ptr73, i32 0, i32 0
  %metadata_base_ptr82 = bitcast [1 x i32]* %.metadata_ptr81 to i32*
  %62 = getelementptr i32* %metadata_base_ptr82, i32 0
  %63 = load i32* %62
  %.element_pointer83 = getelementptr inbounds %X.ex* %.a.ptr73, i32 0, i32 1
  %.opaque_instance_pointer84 = load i8** %.element_pointer83
  %64 = getelementptr i8* %.opaque_instance_pointer84, i32 %63
  %i.ptr85 = bitcast i8* %64 to %I.st*
  %i86 = load %I.st* %i.ptr85
  store %I.st %i86, %I.st* %i.ptr80
  %65 = call %Int.st @Int_i64(i64 11), !stdlib.call.optim !0
  %.v.ptr87 = getelementptr inbounds %I.st* %i.ptr80, i32 0, i32 0
  store %Int.st %65, %Int.st* %.v.ptr87
  %x.0.ptr88 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i32 0, i32 0
  %x.0.ptr89 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i32 0, i32 0
  %x.090 = load { %Int.st, %B.st }* %x.0.ptr89
  store { %Int.st, %B.st } %x.090, { %Int.st, %B.st }* %x.0.ptr88
  %.1.ptr91 = getelementptr inbounds { %Int.st, %B.st }* %x.0.ptr88, i32 0, i32 1
  %.1.ptr92 = getelementptr inbounds { %Int.st, %B.st }* %x.0.ptr88, i32 0, i32 1
  %.193 = load %B.st* %.1.ptr92
  store %B.st %.193, %B.st* %.1.ptr91
  %.a.ptr94 = getelementptr inbounds %B.st* %.1.ptr91, i32 0, i32 0
  %.a.ptr95 = getelementptr inbounds %B.st* %.1.ptr91, i32 0, i32 0
  %.a96 = load %X.ex* %.a.ptr95
  %.metadata_ptr97 = getelementptr inbounds %X.ex* %.a.ptr94, i32 0, i32 0
  %metadata_base_ptr98 = bitcast [1 x i32]* %.metadata_ptr97 to i32*
  %66 = getelementptr i32* %metadata_base_ptr98, i32 0
  %67 = load i32* %66
  %.element_pointer99 = getelementptr inbounds %X.ex* %.a.ptr94, i32 0, i32 1
  %.opaque_instance_pointer100 = load i8** %.element_pointer99
  %68 = getelementptr i8* %.opaque_instance_pointer100, i32 %67
  %i.ptr101 = bitcast i8* %68 to %I.st*
  %.metadata_ptr102 = getelementptr inbounds %X.ex* %.a.ptr94, i32 0, i32 0
  %metadata_base_ptr103 = bitcast [1 x i32]* %.metadata_ptr102 to i32*
  %69 = getelementptr i32* %metadata_base_ptr103, i32 0
  %70 = load i32* %69
  %.element_pointer104 = getelementptr inbounds %X.ex* %.a.ptr94, i32 0, i32 1
  %.opaque_instance_pointer105 = load i8** %.element_pointer104
  %71 = getelementptr i8* %.opaque_instance_pointer105, i32 %70
  %i.ptr106 = bitcast i8* %71 to %I.st*
  %i107 = load %I.st* %i.ptr106
  store %I.st %i107, %I.st* %i.ptr101
  %.v.ptr108 = getelementptr inbounds %I.st* %i.ptr101, i32 0, i32 0
  %.v109 = load %Int.st* %.v.ptr108
  call void @print_Int(%Int.st %.v109), !stdlib.call.optim !0
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

declare %Bool.st @Bool_b(i1)

declare %Int.st @Int_i64(i64)

declare void @print_Int(%Int.st)

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
define %Baz.st @Baz_TestC(%TestC.ex %"$0") #0 {
entry:
  %param0 = alloca %TestC.ex
  store %TestC.ex %"$0", %TestC.ex* %param0
  %Baz = alloca %Baz.st
  %param01 = load %TestC.ex* %param0
  %Baz.foo.ptr = getelementptr inbounds %Baz.st* %Baz, i32 0, i32 0
  store %TestC.ex %param01, %TestC.ex* %Baz.foo.ptr
  %Baz2 = load %Baz.st* %Baz
  ret %Baz.st %Baz2
}

; Function Attrs: alwaysinline
define %Baq.st @Baq_Int(%Int.st %"$0") #0 {
entry:
  %Baq = alloca %Baq.st
  %Baq.v.ptr = getelementptr inbounds %Baq.st* %Baq, i32 0, i32 0
  store %Int.st %"$0", %Int.st* %Baq.v.ptr
  %Baq1 = load %Baq.st* %Baq
  ret %Baq.st %Baq1
}

define internal void @fn_Prot(%Prot.ex %f) {
entry:
  %f1 = alloca %Prot.ex
  store %Prot.ex %f, %Prot.ex* %f1
  %f.metadata_ptr = getelementptr inbounds %Prot.ex* %f1, i32 0, i32 0
  %metadata_base_ptr = bitcast [1 x i32]* %f.metadata_ptr to i32*
  %0 = getelementptr i32* %metadata_base_ptr, i32 0
  %1 = load i32* %0
  %f.element_pointer = getelementptr inbounds %Prot.ex* %f1, i32 0, i32 1
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

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
