; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Foo.st = type { %Int.st }
%Int.st = type { i64 }

define %Foo.st @Foo_Int(%Int.st %"$0") {
entry:
  %self = alloca %Foo.st
  %a = getelementptr inbounds %Foo.st* %self, i32 0, i32 0
  store %Int.st %"$0", %Int.st* %a
  %0 = load %Foo.st* %self
  ret %Foo.st %0
}

define %Int.st @Foo.foo_Int(%Foo.st* %self, %Int.st %u) {
entry:
  %a = getelementptr inbounds %Foo.st* %self, i32 0, i32 0
  %0 = load %Int.st* %a
  %1 = call %Int.st @-A_Int_Int(%Int.st %u, %Int.st %0), !stdlib.call.optim !0
  ret %Int.st %1
}

define void @main() {
entry:
  %0 = call %Foo.st @Foo_Int(%Int.st { i64 3 })
  %foo = alloca %Foo.st
  store %Foo.st %0, %Foo.st* %foo
  %1 = alloca %Foo.st
  store %Foo.st %0, %Foo.st* %1
  %2 = call %Int.st @Foo.foo_Int(%Foo.st* %1, %Int.st { i64 2 })
  call void @print_Int(%Int.st %2), !stdlib.call.optim !0
  ret void
}

declare %Int.st @-A_Int_Int(%Int.st, %Int.st)

declare void @print_Int(%Int.st)

!0 = !{!"stdlib.call.optim"}
