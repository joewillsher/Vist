; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Range.st = type { { i64 }, { i64 } }
%Int.st = type { i64 }

define void @main() {
entry:
  %0 = call %Range.st @..._Int_Int(%Int.st { i64 1 }, %Int.st { i64 10 }), !stdlib.call.optim !0
  %1 = extractvalue %Range.st %0, 0
  %2 = extractvalue { i64 } %1, 0
  %3 = extractvalue %Range.st %0, 1
  br label %loop
  ret void

loop:                                             ; preds = %entry
}

declare %Range.st @..._Int_Int(%Int.st, %Int.st)

!0 = !{!"stdlib.call.optim"}
