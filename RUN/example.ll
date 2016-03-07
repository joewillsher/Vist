; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  tail call void @-Uprint_i64(i64 2)
  ret void
}

declare void @-Uprint_i64(i64)
