; ModuleID = 'example'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Range = type { %Int, %Int }
%Int = type { i64 }
%Bool = type { i1 }

declare %Range @-D-D-D_tII(%Int, %Int)

declare %Bool @-E-E_tII(%Int, %Int)

declare void @print_tI(%Int)

declare void @generate_mRPtI(%Range, void (%Int)*)

; Function Attrs: alwaysinline
define void @main.loop_thunk(%Int %i) #0 {
entry:
  %0 = call %Int @-C_tII(%Int %i, %Int { i64 3 }), !stdlib.call.optim !0
  %1 = call %Bool @-E-E_tII(%Int %0, %Int zeroinitializer), !stdlib.call.optim !0
  %2 = extractvalue %Bool %1, 0
  br i1 %2, label %if.0, label %fail.0

if.0:                                             ; preds = %entry
  %3 = call %Int @-A_tII(%Int %i, %Int { i64 3 }), !stdlib.call.optim !0
  call void @print_tI(%Int %3), !stdlib.call.optim !0
  br label %exit

fail.0:                                           ; preds = %entry
  %4 = call %Int @-C_tII(%Int %i, %Int { i64 1000 }), !stdlib.call.optim !0
  %5 = call %Bool @-E-E_tII(%Int %4, %Int zeroinitializer), !stdlib.call.optim !0
  %6 = extractvalue %Bool %5, 0
  br i1 %6, label %if.1, label %fail.1

if.1:                                             ; preds = %fail.0
  call void @print_tI(%Int { i64 1000000 }), !stdlib.call.optim !0
  br label %exit

fail.1:                                           ; preds = %fail.0
  br label %else.2

else.2:                                           ; preds = %fail.1
  call void @print_tI(%Int %i), !stdlib.call.optim !0
  br label %exit

exit:                                             ; preds = %else.2, %if.1, %if.0
  ret void
}

declare %Int @-C_tII(%Int, %Int)

define void @main() {
entry:
  %0 = call %Range @-D-D-D_tII(%Int zeroinitializer, %Int { i64 5000 }), !stdlib.call.optim !0
  call void @generate_mRPtI(%Range %0, void (%Int)* @main.loop_thunk)
  ret void
}

declare %Int @-A_tII(%Int, %Int)

attributes #0 = { alwaysinline }

!0 = !{!"stdlib.call.optim"}
