; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.refcounted = type { %Foo*, i32 }
%Foo = type { %Int }
%Int = type { i64 }
%RefcountedObject = type { i8*, i32 }

define %Foo.refcounted @Foo_tInt(%Int %"$0") {
entry:
  %refcounted = call %RefcountedObject @vist_allocObject(i32 8)
  %0 = alloca %RefcountedObject
  store %RefcountedObject %refcounted, %RefcountedObject* %0
  %storage = bitcast %RefcountedObject* %0 to %Foo.refcounted*
  %1 = getelementptr inbounds %Foo.refcounted* %storage, i32 0, i32 0
  %storage.instance = load %Foo** %1
  %a = getelementptr inbounds %Foo* %storage.instance, i32 0, i32 0
  store %Int %"$0", %Int* %a
  %2 = load %Foo.refcounted* %storage
  ret %Foo.refcounted %2
}

declare %RefcountedObject @vist_allocObject(i32)

define void @main() {
entry:
  %0 = call %Foo.refcounted @Foo_tInt(%Int { i64 1 })
  %1 = alloca %Foo.refcounted
  store %Foo.refcounted %0, %Foo.refcounted* %1
  %2 = getelementptr inbounds %Foo.refcounted* %1, i32 0, i32 0
  %3 = load %Foo** %2
  %4 = load %Foo* %3
  %5 = extractvalue %Foo %4, 0
  call void @print_tInt(%Int %5), !stdlib.call.optim !0
  %6 = getelementptr inbounds %Foo.refcounted* %1, i32 0, i32 0
  %7 = load %Foo** %6
  %8 = getelementptr inbounds %Foo* %7, i32 0, i32 0
  store %Int { i64 2 }, %Int* %8
  %9 = getelementptr inbounds %Foo.refcounted* %1, i32 0, i32 0
  %10 = load %Foo** %9
  %11 = load %Foo* %10
  %12 = extractvalue %Foo %11, 0
  call void @print_tInt(%Int %12), !stdlib.call.optim !0
  %13 = getelementptr inbounds %Foo.refcounted* %1, i32 0, i32 0
  %14 = load %Foo** %13
  %15 = load %Foo* %14
  %16 = extractvalue %Foo %15, 0
  call void @print_tInt(%Int %16), !stdlib.call.optim !0
  ret void
}

declare void @print_tInt(%Int)

!0 = !{!"stdlib.call.optim"}
