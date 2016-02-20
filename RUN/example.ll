; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.st = type { %Int.st }
%Int.st = type { i64 }
%TestC.ex = type { [1 x i32], i8* }
%Baz.st = type { %TestC.ex }
%Baq.st = type { %Int.st }
%Prot.ex = type { [1 x i32], i8* }
%A.st = type { %I.st }
%I.st = type { %Int.st }
%X.ex = type { [1 x i32], i8* }
%B.st = type { %X.ex }
%Bar.st = type { %Bool.st, %Int.st, %Int.st }
%Bool.st = type { i1 }

; Function Attrs: nounwind
define void @main() #0 {
foo_Eq_Int.exit:
  tail call void @-Uprint_i64(i64 17)
  %0 = alloca %Foo.st, align 8
  %1 = alloca %TestC.ex, align 8
  %.metadata3 = getelementptr inbounds %TestC.ex* %1, i64 0, i32 0
  %.opaque4 = getelementptr inbounds %TestC.ex* %1, i64 0, i32 1
  %metadata5 = alloca [1 x i32], align 4
  %2 = getelementptr inbounds [1 x i32]* %metadata5, i64 0, i64 0
  store i32 0, i32* %2, align 4
  %3 = load [1 x i32]* %metadata5, align 4
  store [1 x i32] %3, [1 x i32]* %.metadata3, align 8
  store %Foo.st { %Int.st { i64 1 } }, %Foo.st* %0, align 8
  %4 = bitcast i8** %.opaque4 to %Foo.st**
  store %Foo.st* %0, %Foo.st** %4, align 8
  %5 = load %TestC.ex* %1, align 8
  %.fca.0.0.extract32 = extractvalue %TestC.ex %5, 0, 0
  %.fca.1.extract33 = extractvalue %TestC.ex %5, 1
  %Baz2.i.fca.0.0.0.insert = insertvalue %Baz.st undef, i32 %.fca.0.0.extract32, 0, 0, 0
  %Baz2.i.fca.0.1.insert = insertvalue %Baz.st %Baz2.i.fca.0.0.0.insert, i8* %.fca.1.extract33, 0, 1
  %b = alloca %Baz.st, align 8
  store %Baz.st %Baz2.i.fca.0.1.insert, %Baz.st* %b, align 8
  %metadata_base_ptr = getelementptr inbounds %Baz.st* %b, i64 0, i32 0, i32 0, i64 0
  %6 = load i32* %metadata_base_ptr, align 8
  %.element_pointer = getelementptr inbounds %Baz.st* %b, i64 0, i32 0, i32 1
  %.opaque_instance_pointer = load i8** %.element_pointer, align 8
  %7 = sext i32 %6 to i64
  %8 = getelementptr i8* %.opaque_instance_pointer, i64 %7
  %9 = bitcast i8* %8 to i64*
  %10 = load i64* %9, align 8
  tail call void @-Uprint_i64(i64 %10)
  %11 = alloca %Baq.st, align 8
  %12 = alloca %Prot.ex, align 8
  %.metadata10 = getelementptr inbounds %Prot.ex* %12, i64 0, i32 0
  %.opaque11 = getelementptr inbounds %Prot.ex* %12, i64 0, i32 1
  %metadata12 = alloca [1 x i32], align 4
  %13 = getelementptr inbounds [1 x i32]* %metadata12, i64 0, i64 0
  store i32 0, i32* %13, align 4
  %14 = load [1 x i32]* %metadata12, align 4
  store [1 x i32] %14, [1 x i32]* %.metadata10, align 8
  store %Baq.st { %Int.st { i64 12 } }, %Baq.st* %11, align 8
  %15 = bitcast i8** %.opaque11 to %Baq.st**
  store %Baq.st* %11, %Baq.st** %15, align 8
  %16 = load %Prot.ex* %12, align 8
  %.fca.0.0.extract22 = extractvalue %Prot.ex %16, 0, 0
  %.fca.1.extract23 = extractvalue %Prot.ex %16, 1
  %17 = sext i32 %.fca.0.0.extract22 to i64
  %18 = getelementptr i8* %.fca.1.extract23, i64 %17
  %19 = bitcast i8* %18 to i64*
  %20 = load i64* %19, align 8
  call void @-Uprint_i64(i64 %20) #0
  %21 = load i64* %19, align 8
  call void @-Uprint_i64(i64 %21) #0
  %22 = load i64* %19, align 8
  call void @-Uprint_i64(i64 %22) #0
  %23 = load i64* %19, align 8
  call void @-Uprint_i64(i64 %23) #0
  %24 = alloca %A.st, align 8
  %25 = alloca %X.ex, align 8
  %.metadata14 = getelementptr inbounds %X.ex* %25, i64 0, i32 0
  %.opaque15 = getelementptr inbounds %X.ex* %25, i64 0, i32 1
  %metadata16 = alloca [1 x i32], align 4
  %26 = getelementptr inbounds [1 x i32]* %metadata16, i64 0, i64 0
  store i32 0, i32* %26, align 4
  %27 = load [1 x i32]* %metadata16, align 4
  store [1 x i32] %27, [1 x i32]* %.metadata14, align 8
  store %A.st { %I.st { %Int.st { i64 1 } } }, %A.st* %24, align 8
  %28 = bitcast i8** %.opaque15 to %A.st**
  store %A.st* %24, %A.st** %28, align 8
  %29 = load %X.ex* %25, align 8
  %.fca.0.0.extract = extractvalue %X.ex %29, 0, 0
  %.fca.1.extract = extractvalue %X.ex %29, 1
  %B2.i.fca.0.0.0.insert = insertvalue %B.st undef, i32 %.fca.0.0.extract, 0, 0, 0
  %B2.i.fca.0.1.insert = insertvalue %B.st %B2.i.fca.0.0.0.insert, i8* %.fca.1.extract, 0, 1
  %u = alloca %B.st, align 8
  store %B.st %B2.i.fca.0.1.insert, %B.st* %u, align 8
  %metadata_base_ptr20 = getelementptr inbounds %B.st* %u, i64 0, i32 0, i32 0, i64 0
  %30 = load i32* %metadata_base_ptr20, align 8
  %.element_pointer21 = getelementptr inbounds %B.st* %u, i64 0, i32 0, i32 1
  %.opaque_instance_pointer22 = load i8** %.element_pointer21, align 8
  %31 = sext i32 %30 to i64
  %32 = getelementptr i8* %.opaque_instance_pointer22, i64 %31
  %.v.ptr = bitcast i8* %32 to %Int.st*
  store %Int.st { i64 2 }, %Int.st* %.v.ptr, align 8
  %33 = bitcast i8* %32 to i64*
  %34 = load i64* %33, align 8
  tail call void @-Uprint_i64(i64 %34)
  %u43 = load %B.st* %u, align 8
  %35 = alloca { %Int.st, %B.st }, align 8
  %.0.ptr = getelementptr inbounds { %Int.st, %B.st }* %35, i64 0, i32 0
  store %Int.st { i64 1 }, %Int.st* %.0.ptr, align 8
  %.1.ptr = getelementptr inbounds { %Int.st, %B.st }* %35, i64 0, i32 1
  store %B.st %u43, %B.st* %.1.ptr, align 8
  %36 = load { %Int.st, %B.st }* %35, align 8
  %37 = alloca { { %Int.st, %B.st }, %Int.st }, align 8
  %.0.ptr44 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %37, i64 0, i32 0
  store { %Int.st, %B.st } %36, { %Int.st, %B.st }* %.0.ptr44, align 8
  %.1.ptr45 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %37, i64 0, i32 1
  store %Int.st { i64 2 }, %Int.st* %.1.ptr45, align 8
  %38 = load { { %Int.st, %B.st }, %Int.st }* %37, align 8
  %x = alloca { { %Int.st, %B.st }, %Int.st }, align 8
  store { { %Int.st, %B.st }, %Int.st } %38, { { %Int.st, %B.st }, %Int.st }* %x, align 8
  %39 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i64 0, i32 1, i32 0
  %40 = load i64* %39, align 8
  tail call void @-Uprint_i64(i64 %40)
  %41 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i64 0, i32 0, i32 0, i32 0
  %42 = load i64* %41, align 8
  tail call void @-Uprint_i64(i64 %42)
  %metadata_base_ptr55 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i64 0, i32 0, i32 1, i32 0, i32 0, i64 0
  %43 = load i32* %metadata_base_ptr55, align 8
  %.element_pointer56 = getelementptr inbounds { { %Int.st, %B.st }, %Int.st }* %x, i64 0, i32 0, i32 1, i32 0, i32 1
  %.opaque_instance_pointer57 = load i8** %.element_pointer56, align 8
  %44 = sext i32 %43 to i64
  %45 = getelementptr i8* %.opaque_instance_pointer57, i64 %44
  %46 = bitcast i8* %45 to i64*
  %47 = load i64* %46, align 8
  tail call void @-Uprint_i64(i64 %47)
  %.v.ptr87 = bitcast i8* %45 to %Int.st*
  store %Int.st { i64 11 }, %Int.st* %.v.ptr87, align 8
  %48 = load i64* %46, align 8
  tail call void @-Uprint_i64(i64 %48)
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define %Bar.st @Bar_Bool_Int_Int(%Bool.st %"$0", %Int.st %"$1", %Int.st %"$2") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue %Bool.st %"$0", 0
  %"$1.fca.0.extract" = extractvalue %Int.st %"$1", 0
  %"$2.fca.0.extract" = extractvalue %Int.st %"$2", 0
  %Bar1.fca.0.0.insert = insertvalue %Bar.st undef, i1 %"$0.fca.0.extract", 0, 0
  %Bar1.fca.1.0.insert = insertvalue %Bar.st %Bar1.fca.0.0.insert, i64 %"$1.fca.0.extract", 1, 0
  %Bar1.fca.2.0.insert = insertvalue %Bar.st %Bar1.fca.1.0.insert, i64 %"$2.fca.0.extract", 2, 0
  ret %Bar.st %Bar1.fca.2.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Foo.st @Foo_Int(%Int.st %"$0") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %Foo1.fca.0.0.insert = insertvalue %Foo.st undef, i64 %"$0.fca.0.extract", 0, 0
  ret %Foo.st %Foo1.fca.0.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Baz.st @Baz_TestC(%TestC.ex %"$0") #1 {
entry:
  %"$0.fca.0.0.extract" = extractvalue %TestC.ex %"$0", 0, 0
  %"$0.fca.1.extract" = extractvalue %TestC.ex %"$0", 1
  %Baz2.fca.0.0.0.insert = insertvalue %Baz.st undef, i32 %"$0.fca.0.0.extract", 0, 0, 0
  %Baz2.fca.0.1.insert = insertvalue %Baz.st %Baz2.fca.0.0.0.insert, i8* %"$0.fca.1.extract", 0, 1
  ret %Baz.st %Baz2.fca.0.1.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %Baq.st @Baq_Int(%Int.st %"$0") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %Baq1.fca.0.0.insert = insertvalue %Baq.st undef, i64 %"$0.fca.0.extract", 0, 0
  ret %Baq.st %Baq1.fca.0.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %I.st @I_Int(%Int.st %"$0") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int.st %"$0", 0
  %I1.fca.0.0.insert = insertvalue %I.st undef, i64 %"$0.fca.0.extract", 0, 0
  ret %I.st %I1.fca.0.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %A.st @A_I(%I.st %"$0") #1 {
entry:
  %"$0.fca.0.0.extract" = extractvalue %I.st %"$0", 0, 0
  %A1.fca.0.0.0.insert = insertvalue %A.st undef, i64 %"$0.fca.0.0.extract", 0, 0, 0
  ret %A.st %A1.fca.0.0.0.insert
}

; Function Attrs: alwaysinline nounwind readnone
define %B.st @B_X(%X.ex %"$0") #1 {
entry:
  %"$0.fca.0.0.extract" = extractvalue %X.ex %"$0", 0, 0
  %"$0.fca.1.extract" = extractvalue %X.ex %"$0", 1
  %B2.fca.0.0.0.insert = insertvalue %B.st undef, i32 %"$0.fca.0.0.extract", 0, 0, 0
  %B2.fca.0.1.insert = insertvalue %B.st %B2.fca.0.0.0.insert, i8* %"$0.fca.1.extract", 0, 1
  ret %B.st %B2.fca.0.1.insert
}

; Function Attrs: noinline nounwind ssp uwtable
declare void @-Uprint_i64(i64) #2

attributes #0 = { nounwind }
attributes #1 = { alwaysinline nounwind readnone }
attributes #2 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
