; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Range = type { %Int, %Int }
%Int = type { i64 }

declare void @generate_mRPtI(%Range, void (%Int)*)

; Function Attrs: alwaysinline nounwind
define void @main.loop_thunk(%Int %i) #0 {
entry:
  %0 = extractvalue %Int %i, 0
  %1 = srem i64 %0, 3
  %2 = icmp eq i64 %1, 0
  br i1 %2, label %if.0, label %fail.0

if.0:                                             ; preds = %entry
  %3 = tail call { i64, i1 } @llvm.smul.with.overflow.i64(i64 %0, i64 3)
  %4 = extractvalue { i64, i1 } %3, 1
  br i1 %4, label %"i.-A_tII.*.trap", label %i.-A_tII.entry.cont

i.-A_tII.entry.cont:                              ; preds = %if.0
  %5 = extractvalue { i64, i1 } %3, 0
  tail call void @vist-Uprint_ti64(i64 %5)
  br label %exit

"i.-A_tII.*.trap":                                ; preds = %if.0
  tail call void @llvm.trap()
  unreachable

fail.0:                                           ; preds = %entry
  %6 = srem i64 %0, 1000
  %7 = icmp eq i64 %6, 0
  br i1 %7, label %if.1, label %else.2

if.1:                                             ; preds = %fail.0
  tail call void @vist-Uprint_ti64(i64 1000000)
  br label %exit

else.2:                                           ; preds = %fail.0
  tail call void @vist-Uprint_ti64(i64 %0)
  br label %exit

exit:                                             ; preds = %else.2, %if.1, %i.-A_tII.entry.cont
  ret void
}

define void @main() {
entry:
  tail call void @generate_mRPtI(%Range { %Int zeroinitializer, %Int { i64 5000 } }, void (%Int)* @main.loop_thunk)
  ret void
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.smul.with.overflow.i64(i64, i64) #1

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #2

; Function Attrs: noinline nounwind ssp uwtable
declare void @vist-Uprint_ti64(i64) #3

attributes #0 = { alwaysinline nounwind }
attributes #1 = { nounwind readnone }
attributes #2 = { noreturn nounwind }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
