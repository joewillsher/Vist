; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

declare void @vist-Uprint_i64(i64)

define void @main() {
entry:
  %a = alloca %Int.st
  store %Int.st { i64 1 }, %Int.st* %a
  call void @vist-Uprint_i64(i64 1)
  call void @vist-Uprint_i64(i64 1)
  ret void
}

define void @foo_() {
entry:
  call void @vist-Uprint_i64(i64 1)
  ret void
}
