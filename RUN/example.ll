; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Gen = type { %Int }
%Int = type { i64 }

; Function Attrs: nounwind readnone
define %Gen @Gen_tI(%Int %"$0") #0 {
entry:
  %"$0.fca.0.extract" = extractvalue %Int %"$0", 0
  %.fca.0.0.insert = insertvalue %Gen undef, i64 %"$0.fca.0.extract", 0, 0
  ret %Gen %.fca.0.0.insert
}

define void @generate_mGenPtI(%Gen* nocapture readonly %self, void (%Int)* nocapture %loop_thunk) {
entry:
  %num = getelementptr inbounds %Gen* %self, i64 0, i32 0
  %0 = load %Int* %num, align 8
  tail call void %loop_thunk(%Int %0)
  ret void
}

define void @loop_thunk(%Int %a) {
entry:
  tail call void @print_tI(%Int %a), !stdlib.call.optim !0
  ret void
}

define void @main() {
entry:
  tail call void @print_tI(%Int { i64 1 }), !stdlib.call.optim !0
  ret void
}

declare void @print_tI(%Int)

attributes #0 = { nounwind readnone }

!0 = !{!"stdlib.call.optim"}
