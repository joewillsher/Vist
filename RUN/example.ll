; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.refcounted = type { %Foo*, i32 }
%Foo = type { %Int }
%Int = type { i64 }

define %Foo.refcounted @fooer_tI(%Int %"$0") {
entry:
  %storage.i.i = tail call { i8*, i32 }* @vist_allocObject(i32 8)
  %0 = bitcast { i8*, i32 }* %storage.i.i to %Foo.refcounted*
  tail call void @vist_retainObject({ i8*, i32 }* %storage.i.i)
  %1 = bitcast { i8*, i32 }* %storage.i.i to %Foo**
  %2 = load %Foo** %1, align 8
  %a.i.i = getelementptr inbounds %Foo* %2, i64 0, i32 0
  store %Int { i64 2 }, %Int* %a.i.i, align 8
  tail call void @vist_releaseUnownedObject({ i8*, i32 }* %storage.i.i)
  %3 = load %Foo.refcounted* %0, align 8
  %.fca.0.extract7 = extractvalue %Foo.refcounted %3, 0
  %.fca.1.extract9 = extractvalue %Foo.refcounted %3, 1
  %4 = alloca %Foo.refcounted, align 8
  %.fca.0.gep = getelementptr inbounds %Foo.refcounted* %4, i64 0, i32 0
  store %Foo* %.fca.0.extract7, %Foo** %.fca.0.gep, align 8
  %.fca.1.gep = getelementptr inbounds %Foo.refcounted* %4, i64 0, i32 1
  store i32 %.fca.1.extract9, i32* %.fca.1.gep, align 8
  %5 = bitcast %Foo.refcounted* %4 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %5)
  call void @vist_releaseUnownedObject({ i8*, i32 }* %5)
  %.fca.0.load = load %Foo** %.fca.0.gep, align 8
  %.fca.0.insert = insertvalue %Foo.refcounted undef, %Foo* %.fca.0.load, 0
  %.fca.1.load = load i32* %.fca.1.gep, align 8
  %.fca.1.insert = insertvalue %Foo.refcounted %.fca.0.insert, i32 %.fca.1.load, 1
  ret %Foo.refcounted %.fca.1.insert
}

define %Foo.refcounted @Foo_tI(%Int %"$0") {
entry:
  %storage = tail call { i8*, i32 }* @vist_allocObject(i32 8)
  %0 = bitcast { i8*, i32 }* %storage to %Foo.refcounted*
  tail call void @vist_retainObject({ i8*, i32 }* %storage)
  %1 = bitcast { i8*, i32 }* %storage to %Foo**
  %2 = load %Foo** %1, align 8
  %a = getelementptr inbounds %Foo* %2, i64 0, i32 0
  store %Int %"$0", %Int* %a, align 8
  tail call void @vist_releaseUnownedObject({ i8*, i32 }* %storage)
  %3 = load %Foo.refcounted* %0, align 8
  ret %Foo.refcounted %3
}

declare void @print_tI(%Int)

define %Foo.refcounted @fooFactory_tI(%Int %"$0") {
entry:
  %storage.i = tail call { i8*, i32 }* @vist_allocObject(i32 8)
  %0 = bitcast { i8*, i32 }* %storage.i to %Foo.refcounted*
  tail call void @vist_retainObject({ i8*, i32 }* %storage.i)
  %1 = bitcast { i8*, i32 }* %storage.i to %Foo**
  %2 = load %Foo** %1, align 8
  %a.i = getelementptr inbounds %Foo* %2, i64 0, i32 0
  store %Int %"$0", %Int* %a.i, align 8
  tail call void @vist_releaseUnownedObject({ i8*, i32 }* %storage.i)
  %3 = load %Foo.refcounted* %0, align 8
  ret %Foo.refcounted %3
}

define void @main() {
entry:
  %0 = alloca %Foo.refcounted, align 8
  %1 = bitcast %Foo.refcounted* %0 to i8*
  call void @llvm.lifetime.start(i64 16, i8* %1)
  %storage.i.i.i = tail call { i8*, i32 }* @vist_allocObject(i32 8)
  %2 = bitcast { i8*, i32 }* %storage.i.i.i to %Foo.refcounted*
  tail call void @vist_retainObject({ i8*, i32 }* %storage.i.i.i)
  %3 = bitcast { i8*, i32 }* %storage.i.i.i to %Foo**
  %4 = load %Foo** %3, align 8
  %a.i.i.i = getelementptr inbounds %Foo* %4, i64 0, i32 0
  store %Int { i64 2 }, %Int* %a.i.i.i, align 8
  tail call void @vist_releaseUnownedObject({ i8*, i32 }* %storage.i.i.i)
  %5 = load %Foo.refcounted* %2, align 8
  %.fca.0.extract7.i = extractvalue %Foo.refcounted %5, 0
  %.fca.1.extract9.i = extractvalue %Foo.refcounted %5, 1
  %.fca.0.gep.i = getelementptr inbounds %Foo.refcounted* %0, i64 0, i32 0
  store %Foo* %.fca.0.extract7.i, %Foo** %.fca.0.gep.i, align 8
  %.fca.1.gep.i = getelementptr inbounds %Foo.refcounted* %0, i64 0, i32 1
  store i32 %.fca.1.extract9.i, i32* %.fca.1.gep.i, align 8
  %6 = bitcast %Foo.refcounted* %0 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %6)
  call void @vist_releaseUnownedObject({ i8*, i32 }* %6)
  %.fca.0.load.i = load %Foo** %.fca.0.gep.i, align 8
  %.fca.1.load.i = load i32* %.fca.1.gep.i, align 8
  call void @llvm.lifetime.end(i64 16, i8* %1)
  %7 = alloca %Foo.refcounted, align 8
  %.fca.0.gep = getelementptr inbounds %Foo.refcounted* %7, i64 0, i32 0
  store %Foo* %.fca.0.load.i, %Foo** %.fca.0.gep, align 8
  %.fca.1.gep = getelementptr inbounds %Foo.refcounted* %7, i64 0, i32 1
  store i32 %.fca.1.load.i, i32* %.fca.1.gep, align 8
  %8 = bitcast %Foo.refcounted* %7 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %8)
  %9 = load %Foo** %.fca.0.gep, align 8
  %10 = getelementptr inbounds %Foo* %9, i64 0, i32 0
  %11 = load %Int* %10, align 8
  call void @print_tI(%Int %11), !stdlib.call.optim !0
  call void @vist_releaseObject({ i8*, i32 }* %8)
  ret void
}

declare void @vist_retainObject({ i8*, i32 }*)

declare void @vist_releaseUnownedObject({ i8*, i32 }*)

declare { i8*, i32 }* @vist_allocObject(i32)

declare void @vist_releaseObject({ i8*, i32 }*)

; Function Attrs: nounwind
declare void @llvm.lifetime.start(i64, i8* nocapture) #0

; Function Attrs: nounwind
declare void @llvm.lifetime.end(i64, i8* nocapture) #0

attributes #0 = { nounwind }

!0 = !{!"stdlib.call.optim"}
