; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }
%Bool.st = type { i1 }

define void @main() {
entry:
  %0 = alloca { %Int.st, { %Int.st, %Int.st, %Bool.st } }
  store { %Int.st, { %Int.st, %Int.st, %Bool.st } } { %Int.st { i64 1 }, { %Int.st, %Int.st, %Bool.st } { %Int.st { i64 1 }, %Int.st { i64 1 }, %Bool.st zeroinitializer } }, { %Int.st, { %Int.st, %Int.st, %Bool.st } }* %0
  %1 = getelementptr inbounds { %Int.st, { %Int.st, %Int.st, %Bool.st } }* %0, i32 0, i32 1
  %2 = getelementptr inbounds { %Int.st, %Int.st, %Bool.st }* %1, i32 0, i32 2
  store %Bool.st { i1 true }, %Bool.st* %2
  %3 = load { %Int.st, { %Int.st, %Int.st, %Bool.st } }* %0
  %4 = extractvalue { %Int.st, { %Int.st, %Int.st, %Bool.st } } %3, 1
  %5 = extractvalue { %Int.st, %Int.st, %Bool.st } %4, 2
  call void @print_Bool(%Bool.st %5), !stdlib.call.optim !0
  ret void
}

declare void @print_Bool(%Bool.st)

!0 = !{!"stdlib.call.optim"}
