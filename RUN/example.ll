; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

; Function Attrs: nounwind readnone
define void @main() #0 {
entry:
  ret void
}

; Function Attrs: alwaysinline nounwind readnone
define { { i64 } } @_Bar_S.i64({ i64 } %"$0") #1 {
entry:
  %"$0.fca.0.extract" = extractvalue { i64 } %"$0", 0
  %Bar1.fca.0.0.insert = insertvalue { { i64 } } undef, i64 %"$0.fca.0.extract", 0, 0
  ret { { i64 } } %Bar1.fca.0.0.insert
}

attributes #0 = { nounwind readnone }
attributes #1 = { alwaysinline nounwind readnone }
