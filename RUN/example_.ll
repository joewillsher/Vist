; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

define void @main() {
entry:
  %0 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 1, i64 1)
  %1 = extractvalue { i64, i1 } %0, 0
  call void @-Uprint_i64(i64 %1)
  ret void
}

declare void @-Uprint_i64(i64)

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #0

attributes #0 = { nounwind readnone }
