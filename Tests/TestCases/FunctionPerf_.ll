; ModuleID = 'vist_module'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Bool = type { i1 }
%Int = type { i64 }
%Range = type { %Int, %Int }

declare %Bool @-L_tIntInt(%Int, %Int)

declare %Int @-M_tIntInt(%Int, %Int)

declare void @print_tInt(%Int)

declare void @fatalError_t()

define %Int @fib_tInt(%Int %a) {
entry:
  %0 = call %Bool @-L_tIntInt(%Int %a, %Int zeroinitializer), !stdlib.call.optim !0
  %1 = extractvalue %Bool %0, 0
  br i1 %1, label %if.0, label %exit

if.0:                                             ; preds = %entry
  call void @fatalError_t(), !stdlib.call.optim !0
  br label %exit

exit:                                             ; preds = %if.0, %entry
  %2 = call %Bool @-L-E_tIntInt(%Int %a, %Int { i64 1 }), !stdlib.call.optim !0
  %3 = extractvalue %Bool %2, 0
  br i1 %3, label %if.01, label %fail.0

if.01:                                            ; preds = %exit
  ret %Int { i64 1 }

fail.0:                                           ; preds = %exit
  br label %else.1

else.1:                                           ; preds = %fail.0
  %4 = call %Int @-M_tIntInt(%Int %a, %Int { i64 1 }), !stdlib.call.optim !0
  %5 = call %Int @fib_tInt(%Int %4)
  %6 = call %Int @-M_tIntInt(%Int %a, %Int { i64 2 }), !stdlib.call.optim !0
  %7 = call %Int @fib_tInt(%Int %6)
  %8 = call %Int @-P_tIntInt(%Int %5, %Int %7), !stdlib.call.optim !0
  ret %Int %8
}

declare %Bool @-L-E_tIntInt(%Int, %Int)

declare %Int @-P_tIntInt(%Int, %Int)

declare %Range @-D-D-D_tIntInt(%Int, %Int)

define void @main() {
entry:
  %0 = call %Range @-D-D-D_tIntInt(%Int zeroinitializer, %Int { i64 36 }), !stdlib.call.optim !0
  %1 = extractvalue %Range %0, 0
  %2 = extractvalue %Range %0, 1
  %3 = extractvalue %Int %1, 0
  %4 = extractvalue %Int %2, 0
  br label %loop

loop:                                             ; preds = %loop, %entry
  %loop.count = phi i64 [ %3, %entry ], [ %count.it, %loop ]
  %i = insertvalue %Int undef, i64 %loop.count, 0
  %5 = call %Int @fib_tInt(%Int %i)
  call void @print_tInt(%Int %5), !stdlib.call.optim !0
  %count.it = add i64 %loop.count, 1
  %6 = icmp sle i64 %count.it, %4
  br i1 %6, label %loop, label %loop.exit

loop.exit:                                        ; preds = %loop
  ret void
}

!0 = !{!"stdlib.call.optim"}
