; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.refcounted = type { %Foo*, i32 }
%Foo = type { %Int }
%Int = type { i64 }

define %Foo.refcounted @Foo_tInt(%Int %q) {
entry:
  %storage = call { i8*, i32 }* @vist_allocObject(i32 8)
  %0 = bitcast { i8*, i32 }* %storage to %Foo.refcounted*
  call void @vist_retainObject({ i8*, i32 }* %storage)
  %1 = getelementptr inbounds %Foo.refcounted* %0, i32 0, i32 0
  %2 = load %Foo** %1
  %a = getelementptr inbounds %Foo* %2, i32 0, i32 0
  store %Int %q, %Int* %a
  call void @vist_releaseUnretainedObject({ i8*, i32 }* %storage)
  %3 = load %Foo.refcounted* %0
  ret %Foo.refcounted %3
}

define %Foo.refcounted @fooGen_tInt(%Int %"$0") {
entry:
  %0 = call %Foo.refcounted @Foo_tInt(%Int %"$0")
  ret %Foo.refcounted %0
}

define void @main() {
entry:
  %0 = call %Foo.refcounted @fooGen_tInt(%Int { i64 1 })
  %1 = alloca %Foo.refcounted
  store %Foo.refcounted %0, %Foo.refcounted* %1
  %2 = bitcast %Foo.refcounted* %1 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %2)
  %3 = getelementptr inbounds %Foo.refcounted* %1, i32 0, i32 0
  %4 = load %Foo** %3
  %5 = getelementptr inbounds %Foo* %4, i32 0, i32 0
  %6 = load %Int* %5
  call void @print_tInt(%Int %6), !stdlib.call.optim !0
  %7 = load %Foo.refcounted* %1
  %8 = alloca %Foo.refcounted
  store %Foo.refcounted %7, %Foo.refcounted* %8
  %9 = bitcast %Foo.refcounted* %8 to { i8*, i32 }*
  call void @vist_retainObject({ i8*, i32 }* %9)
  %10 = bitcast %Foo.refcounted* %1 to { i8*, i32 }*
  call void @vist_releaseObject({ i8*, i32 }* %10)
  %11 = bitcast %Foo.refcounted* %8 to { i8*, i32 }*
  call void @vist_releaseObject({ i8*, i32 }* %11)
  ret void
}

declare void @print_tInt(%Int)

declare { i8*, i32 }* @vist_allocObject(i32)

declare void @vist_retainObject({ i8*, i32 }*)

declare void @vist_releaseUnretainedObject({ i8*, i32 }*)

declare void @vist_releaseObject({ i8*, i32 }*)

!0 = !{!"stdlib.call.optim"}
