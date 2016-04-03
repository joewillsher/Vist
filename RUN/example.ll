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
  call void @vist_retainObject(%RefcountedObject* %refcounted)
  %0 = getelementptr inbounds %Foo.refcounted* %storage, i32 0, i32 0
  %storage.instance = load %Foo** %0
  %a = getelementptr inbounds %Foo* %storage.instance, i32 0, i32 0
  store %Int %q, %Int* %a
  call void @vist_releaseUnretainedObject(%RefcountedObject* %refcounted)
  %1 = load %Foo.refcounted* %storage
  ret %Foo.refcounted %1
}

declare %RefcountedObject* @vist_allocObject(i32)

declare void @print_tInt(%Int)

declare void @vist_releaseObject(%RefcountedObject*)

declare void @vist_retainObject(%RefcountedObject*)

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
  %2 = bitcast %Foo.refcounted* %1 to %RefcountedObject*
  call void @vist_retainObject(%RefcountedObject* %2)
  %3 = getelementptr inbounds %Foo.refcounted* %1, i32 0, i32 0
  %4 = load %Foo** %3
  %5 = getelementptr inbounds %Foo* %4, i32 0, i32 0
  %6 = load %Int* %5
  call void @print_tInt(%Int %6), !stdlib.call.optim !0
  %7 = load %Foo.refcounted* %1
  %8 = alloca %Foo.refcounted
  store %Foo.refcounted %7, %Foo.refcounted* %8
  %9 = bitcast %Foo.refcounted* %8 to %RefcountedObject*
  call void @vist_retainObject(%RefcountedObject* %9)
  %10 = bitcast %Foo.refcounted* %1 to %RefcountedObject*
  call void @vist_releaseObject(%RefcountedObject* %10)
  %11 = bitcast %Foo.refcounted* %8 to %RefcountedObject*
  call void @vist_releaseObject(%RefcountedObject* %11)
  ret void
}

!0 = !{!"stdlib.call.optim"}
