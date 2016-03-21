; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.st = type { %Int.st }
%Int.st = type { i64 }

define void @main() {
entry:
  %0 = call %Foo.st @Foo_Int(%Int.st { i64 1 })
  %a = alloca %Foo.st
  store %Foo.st %0, %Foo.st* %a
  %1 = extractvalue %Foo.st %0, 0
  call void @print_Int(%Int.st %1), !stdlib.call.optim !0
  ret void
}

define %Foo.st @Foo_Int(%Int.st) {
entry:
  %self = alloca %Foo.st
  %a = getelementptr inbounds %Foo.st* %self, i32 0, i32 0
  store %Int.st %0, %Int.st* %a
  %1 = load %Foo.st* %self
  ret %Foo.st %1
}

declare void @print_Int(%Int.st)

!0 = !{!"stdlib.call.optim"}
