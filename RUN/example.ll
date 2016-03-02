; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = tail call { i64 } @-P_Int_Int({ i64 } { i64 2 }, { i64 } { i64 1 })
  tail call void @print_Int({ i64 } { i64 4 })
  ret void
}

declare { i64 } @-P_Int_Int({ i64 }, { i64 })

declare void @print_Int({ i64 })
