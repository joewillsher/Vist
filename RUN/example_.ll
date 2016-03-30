; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Range.st = type { %Int.st, %Int.st }
%Int.st = type { i64 }

define void @main() {
entry:
  %0 = call %Range.st @..._Int_Int(%Int.st zeroinitializer, %Int.st { i64 1 }), !stdlib.call.optim !0
  %1 = extractvalue %Range.st %0, 0
  %2 = extractvalue %Range.st %0, 1
  %3 = extractvalue %Int.st %1, 0
  %4 = extractvalue %Int.st %2, 0
  br label %loop

loop:                                             ; preds = %loop, %entry
  %loop.count = phi i64 [ %3, %entry ], [ %count.it, %loop ]
  call void @print_Int(%Int.st { i64 1 }), !stdlib.call.optim !0
  %count.it = add i64 %loop.count, 1
  %5 = icmp sle i64 %count.it, %4
  br i1 %5, label %loop, label %loop.exit

loop.exit:                                        ; preds = %loop
  ret void
}

declare %Range.st @..._Int_Int(%Int.st, %Int.st)

declare void @print_Int(%Int.st)

!0 = !{!"stdlib.call.optim"}
