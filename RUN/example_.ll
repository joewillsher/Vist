; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%RefcountedObject = type { i8*, i32 }
%Foo.refcounted = type { %Foo*, i32 }
%Foo = type { %Int }
%Int = type { i64 }

declare void @vist_releaseUnretainedObject(%RefcountedObject*)

define %Foo.refcounted @Foo_tInt(%Int %q) {
entry:
  %refcounted = call %RefcountedObject* @vist_allocObject(i32 8)
  %storage = bitcast %RefcountedObject* %refcounted to %Foo.refcounted*
  %0 = bitcast %Foo.refcounted* %storage to %RefcountedObject*
  call void @vist_retainObject(%RefcountedObject* %0)
  %1 = getelementptr inbounds %Foo.refcounted* %storage, i32 0, i32 0
  %storage.instance = load %Foo** %1
  %a = getelementptr inbounds %Foo* %storage.instance, i32 0, i32 0
  store %Int %q, %Int* %a
  %2 = bitcast %Foo.refcounted* %storage to %RefcountedObject*
  call void @vist_releaseUnretainedObject(%RefcountedObject* %2)
  %3 = load %Foo.refcounted* %storage
  ret %Foo.refcounted %3
}

declare %RefcountedObject* @vist_allocObject(i32)

declare void @print_tInt(%Int)

declare void @vist_releaseObject(%RefcountedObject*)

declare void @vist_retainObject(%RefcountedObject*)

define %Foo.refcounted @fooGen_tInt(%Int %"$0") {
entry:
  %0 = call %Foo.refcounted @Foo_tInt(%Int %"$0")
  %1 = alloca %Foo.refcounted
  store %Foo.refcounted %0, %Foo.refcounted* %1
  %2 = load %Foo.refcounted* %1
  ret %Foo.refcounted %2
}

define void @main() {
entry:
  %0 = call %Foo.refcounted @fooGen_tInt(%Int { i64 1 })
  %1 = alloca %Foo.refcounted
  store %Foo.refcounted %0, %Foo.refcounted* %1
  %2 = load %Foo.refcounted* %1
  %a = alloca %Foo.refcounted
  store %Foo.refcounted %2, %Foo.refcounted* %a
  %3 = alloca %Foo.refcounted
  store %Foo.refcounted %2, %Foo.refcounted* %3
  %4 = bitcast %Foo.refcounted* %3 to %RefcountedObject*
  call void @vist_retainObject(%RefcountedObject* %4)
  %5 = getelementptr inbounds %Foo.refcounted* %3, i32 0, i32 0
  %6 = load %Foo** %5
  %7 = load %Foo* %6
  %8 = extractvalue %Foo %7, 0
  call void @print_tInt(%Int %8), !stdlib.call.optim !0
  %9 = load %Foo.refcounted* %3
  %c = alloca %Foo.refcounted
  store %Foo.refcounted %9, %Foo.refcounted* %c
  %10 = alloca %Foo.refcounted
  store %Foo.refcounted %9, %Foo.refcounted* %10
  %11 = bitcast %Foo.refcounted* %10 to %RefcountedObject*
  call void @vist_retainObject(%RefcountedObject* %11)
  %12 = bitcast %Foo.refcounted* %3 to %RefcountedObject*
  call void @vist_releaseObject(%RefcountedObject* %12)
  %13 = bitcast %Foo.refcounted* %10 to %RefcountedObject*
  call void @vist_releaseObject(%RefcountedObject* %13)
  ret void
}

!0 = !{!"stdlib.call.optim"}
