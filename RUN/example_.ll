; ModuleID = 'example'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.refcounted = type { %Foo*, i32 }
%Foo = type { %Int }
%Int = type { i64 }

define %Foo.refcounted @fooer_tI(%Int %"$0") {
entry:
  %0 = call %Foo.refcounted @fooFactory_tI(%Int { i64 2 })
  %1 = alloca %Foo.refcounted
  store %Foo.refcounted %0, %Foo.refcounted* %1
  %2 = load %Foo.refcounted* %1
  %f = alloca %Foo.refcounted
  store %Foo.refcounted %2, %Foo.refcounted* %f
  %3 = alloca %Foo.refcounted
  store %Foo.refcounted %2, %Foo.refcounted* %3
  %4 = bitcast %Foo.refcounted* %3 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %4)
  %5 = bitcast %Foo.refcounted* %3 to { i8*, i32 }*
  call void @vist_releaseUnownedObject({ i8*, i32 }* %5)
  %6 = load %Foo.refcounted* %3
  ret %Foo.refcounted %6
}

define %Foo.refcounted @Foo_tI(%Int %"$0") {
entry:
  %storage = call { i8*, i32 }* @vist_allocObject(i32 8)
  %0 = bitcast { i8*, i32 }* %storage to %Foo.refcounted*
  %1 = bitcast %Foo.refcounted* %0 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %1)
  %2 = getelementptr inbounds %Foo.refcounted* %0, i32 0, i32 0
  %3 = load %Foo** %2
  %a = getelementptr inbounds %Foo* %3, i32 0, i32 0
  store %Int %"$0", %Int* %a
  %4 = bitcast %Foo.refcounted* %0 to { i8*, i32 }*
  call void @vist_releaseUnownedObject({ i8*, i32 }* %4)
  %5 = load %Foo.refcounted* %0
  ret %Foo.refcounted %5
}

declare void @print_tI(%Int)

define %Foo.refcounted @fooFactory_tI(%Int %"$0") {
entry:
  %0 = call %Foo.refcounted @Foo_tI(%Int %"$0")
  %1 = alloca %Foo.refcounted
  store %Foo.refcounted %0, %Foo.refcounted* %1
  %2 = load %Foo.refcounted* %1
  ret %Foo.refcounted %2
}

define void @main() {
entry:
  %0 = call %Foo.refcounted @fooer_tI(%Int { i64 4 })
  %1 = alloca %Foo.refcounted
  store %Foo.refcounted %0, %Foo.refcounted* %1
  %2 = load %Foo.refcounted* %1
  %a = alloca %Foo.refcounted
  store %Foo.refcounted %2, %Foo.refcounted* %a
  %3 = alloca %Foo.refcounted
  store %Foo.refcounted %2, %Foo.refcounted* %3
  %4 = bitcast %Foo.refcounted* %3 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %4)
  %5 = getelementptr inbounds %Foo.refcounted* %3, i32 0, i32 0
  %6 = load %Foo** %5
  %7 = load %Foo* %6
  %8 = extractvalue %Foo %7, 0
  call void @print_tI(%Int %8), !stdlib.call.optim !0
  %9 = bitcast %Foo.refcounted* %3 to { i8*, i32 }*
  call void @vist_releaseObject({ i8*, i32 }* %9)
  ret void
}

declare void @vist_retainObject({ i8*, i32 }*)

declare void @vist_releaseUnownedObject({ i8*, i32 }*)

declare { i8*, i32 }* @vist_allocObject(i32)

declare void @vist_releaseObject({ i8*, i32 }*)

!0 = !{!"stdlib.call.optim"}
