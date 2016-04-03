; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%RefcountedObject = type { i8*, i32 }
%Foo.refcounted = type { %Foo*, i32 }
%Foo = type { %Int }
%Int = type { i64 }
%String = type { i8*, i64 }

@0 = private unnamed_addr constant [9 x i8] c"init end\00"
@1 = private unnamed_addr constant [2 x i8] c"a\00"
@2 = private unnamed_addr constant [4 x i8] c"end\00"

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
  %1 = call %String @String_topi64(i8* getelementptr inbounds ([9 x i8]* @0, i32 0, i32 0), i64 9), !stdlib.call.optim !0
  call void @print_tString(%String %1), !stdlib.call.optim !0
  call void @vist_releaseUnretainedObject(%RefcountedObject* %refcounted)
  %2 = load %Foo.refcounted* %storage
  ret %Foo.refcounted %2
}

declare %String @String_topi64(i8*, i64)

declare %RefcountedObject* @vist_allocObject(i32)

declare void @print_tString(%String)

declare void @vist_releaseObject(%RefcountedObject*)

declare void @vist_retainObject(%RefcountedObject*)

define void @main() {
entry:
  %0 = call %Foo.refcounted @Foo_tInt(%Int { i64 1 })
  %1 = alloca %Foo.refcounted
  store %Foo.refcounted %0, %Foo.refcounted* %1
  %2 = bitcast %Foo.refcounted* %1 to %RefcountedObject*
  call void @vist_retainObject(%RefcountedObject* %2)
  %3 = call %String @String_topi64(i8* getelementptr inbounds ([2 x i8]* @1, i32 0, i32 0), i64 2), !stdlib.call.optim !0
  call void @print_tString(%String %3), !stdlib.call.optim !0
  %4 = bitcast %Foo.refcounted* %1 to %RefcountedObject*
  call void @vist_retainObject(%RefcountedObject* %4)
  %5 = call %String @String_topi64(i8* getelementptr inbounds ([4 x i8]* @2, i32 0, i32 0), i64 4), !stdlib.call.optim !0
  call void @print_tString(%String %5), !stdlib.call.optim !0
  %6 = bitcast %Foo.refcounted* %1 to %RefcountedObject*
  call void @vist_releaseObject(%RefcountedObject* %6)
  %7 = bitcast %Foo.refcounted* %1 to %RefcountedObject*
  call void @vist_releaseObject(%RefcountedObject* %7)
  ret void
}

!0 = !{!"stdlib.call.optim"}
