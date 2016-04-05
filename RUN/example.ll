; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.refcounted = type { %Foo*, i32 }
%Foo = type { %Int }
%Int = type { i64 }
%String = type { i8*, i64 }

@0 = private unnamed_addr constant [6 x i8] c"memes\00"

define %Foo.refcounted @Foo_tI(%Int %q) {
entry:
  %storage = tail call { i8*, i32 }* @vist_allocObject(i32 8)
  %0 = bitcast { i8*, i32 }* %storage to %Foo.refcounted*
  tail call void @vist_retainObject({ i8*, i32 }* %storage)
  %1 = bitcast { i8*, i32 }* %storage to %Foo**
  %2 = load %Foo** %1, align 8
  %a = getelementptr inbounds %Foo* %2, i64 0, i32 0
  store %Int %q, %Int* %a, align 8
  tail call void @vist_releaseUnownedObject({ i8*, i32 }* %storage)
  %3 = load %Foo.refcounted* %0, align 8
  ret %Foo.refcounted %3
}

declare void @print_tI(%Int)

declare %String @String_topi64(i8*, i64)

declare void @print_tString(%String)

define void @main() {
entry:
  %storage.i.i = tail call { i8*, i32 }* @vist_allocObject(i32 8)
  %0 = bitcast { i8*, i32 }* %storage.i.i to %Foo.refcounted*
  tail call void @vist_retainObject({ i8*, i32 }* %storage.i.i)
  %1 = bitcast { i8*, i32 }* %storage.i.i to %Foo**
  %2 = load %Foo** %1, align 8
  %a.i.i = getelementptr inbounds %Foo* %2, i64 0, i32 0
  store %Int { i64 1 }, %Int* %a.i.i, align 8
  tail call void @vist_releaseUnownedObject({ i8*, i32 }* %storage.i.i)
  %3 = load %Foo.refcounted* %0, align 8
  %.fca.0.extract15 = extractvalue %Foo.refcounted %3, 0
  %.fca.1.extract17 = extractvalue %Foo.refcounted %3, 1
  %4 = alloca %Foo.refcounted, align 8
  %.fca.0.gep6 = getelementptr inbounds %Foo.refcounted* %4, i64 0, i32 0
  store %Foo* %.fca.0.extract15, %Foo** %.fca.0.gep6, align 8
  %.fca.1.gep8 = getelementptr inbounds %Foo.refcounted* %4, i64 0, i32 1
  store i32 %.fca.1.extract17, i32* %.fca.1.gep8, align 8
  %5 = bitcast %Foo.refcounted* %4 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %5)
  %6 = load %Foo** %.fca.0.gep6, align 8
  %7 = getelementptr inbounds %Foo* %6, i64 0, i32 0
  %8 = load %Int* %7, align 8
  call void @print_tI(%Int %8), !stdlib.call.optim !0
  %.fca.0.load = load %Foo** %.fca.0.gep6, align 8
  %.fca.1.load = load i32* %.fca.1.gep8, align 8
  %9 = alloca %Foo.refcounted, align 8
  %.fca.0.gep = getelementptr inbounds %Foo.refcounted* %9, i64 0, i32 0
  store %Foo* %.fca.0.load, %Foo** %.fca.0.gep, align 8
  %.fca.1.gep = getelementptr inbounds %Foo.refcounted* %9, i64 0, i32 1
  store i32 %.fca.1.load, i32* %.fca.1.gep, align 8
  %10 = bitcast %Foo.refcounted* %9 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %10)
  %11 = call %String @String_topi64(i8* getelementptr inbounds ([6 x i8]* @0, i64 0, i64 0), i64 6), !stdlib.call.optim !0
  call void @print_tString(%String %11), !stdlib.call.optim !0
  call void @vist_releaseObject({ i8*, i32 }* %5)
  call void @vist_releaseObject({ i8*, i32 }* %10)
  ret void
}

define %Foo.refcounted @fooGen_tI(%Int %"$0") {
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

declare { i8*, i32 }* @vist_allocObject(i32)

declare void @vist_retainObject({ i8*, i32 }*)

declare void @vist_releaseUnownedObject({ i8*, i32 }*)

declare void @vist_releaseObject({ i8*, i32 }*)

!0 = !{!"stdlib.call.optim"}
