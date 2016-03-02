; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

; Function Attrs: nounwind readnone
define void @main() #0 {
entry:
  ret void
}

attributes #0 = { nounwind readnone }
