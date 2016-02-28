; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.st = type { %Foo.T.gen }
%Foo.T.gen = type { [0 x i32], i8* }

define void @main() {
entry:
  ret void
}

; Function Attrs: alwaysinline
define %Foo.st @Foo_T(%Foo.T.gen %"$0") #0 {
entry:
  %Foo = alloca %Foo.st
  %Foo.a.ptr = getelementptr inbounds %Foo.st* %Foo, i32 0, i32 0
  store %Foo.T.gen %"$0", %Foo.T.gen* %Foo.a.ptr
  %Foo1 = load %Foo.st* %Foo
  ret %Foo.st %Foo1
}

attributes #0 = { alwaysinline }
