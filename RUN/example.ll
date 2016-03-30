; ModuleID = 'example.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

%Int.st = type { i64 }

; Function Attrs: nounwind
define %Int.st @fib_Int(%Int.st %a) #0 {
entry:
  %0 = extractvalue %Int.st %a, 0
  %1 = icmp slt i64 %0, 2
  br i1 %1, label %if.01, label %else.1

if.01:                                            ; preds = %entry
  ret %Int.st { i64 1 }

else.1:                                           ; preds = %entry
  %2 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 1)
  %3 = extractvalue { i64, i1 } %2, 1
  br i1 %3, label %inlined.-M_Int_Int.-.trap, label %inlined.-M_Int_Int.entry.cont

inlined.-M_Int_Int.entry.cont:                    ; preds = %else.1
  %4 = extractvalue { i64, i1 } %2, 0
  %.fca.0.insert5 = insertvalue %Int.st undef, i64 %4, 0
  %5 = tail call %Int.st @fib_Int(%Int.st %.fca.0.insert5)
  %6 = tail call { i64, i1 } @llvm.ssub.with.overflow.i64(i64 %0, i64 2)
  %7 = extractvalue { i64, i1 } %6, 1
  br i1 %7, label %inlined.-M_Int_Int.-.trap10, label %inlined.-M_Int_Int.entry.cont7

inlined.-M_Int_Int.entry.cont7:                   ; preds = %inlined.-M_Int_Int.entry.cont
  %8 = extractvalue { i64, i1 } %6, 0
  %.fca.0.insert9 = insertvalue %Int.st undef, i64 %8, 0
  %9 = tail call %Int.st @fib_Int(%Int.st %.fca.0.insert9)
  %10 = extractvalue %Int.st %5, 0
  %11 = extractvalue %Int.st %9, 0
  %12 = tail call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %10, i64 %11)
  %13 = extractvalue { i64, i1 } %12, 1
  br i1 %13, label %"inlined.-P_Int_Int.+.trap", label %inlined.-P_Int_Int.entry.cont

inlined.-P_Int_Int.entry.cont:                    ; preds = %inlined.-M_Int_Int.entry.cont7
  %14 = extractvalue { i64, i1 } %12, 0
  %.fca.0.insert12 = insertvalue %Int.st undef, i64 %14, 0
  ret %Int.st %.fca.0.insert12

"inlined.-P_Int_Int.+.trap":                      ; preds = %inlined.-M_Int_Int.entry.cont7
  tail call void @llvm.trap()
  unreachable

inlined.-M_Int_Int.-.trap10:                      ; preds = %inlined.-M_Int_Int.entry.cont
  tail call void @llvm.trap()
  unreachable

inlined.-M_Int_Int.-.trap:                        ; preds = %else.1
  tail call void @llvm.trap()
  unreachable
}

; Function Attrs: nounwind
define void @main() #0 {
entry:
  br label %loop

loop:                                             ; preds = %loop, %entry
  %loop.count = phi i64 [ 0, %entry ], [ %count.it, %loop ]
  %0 = insertvalue %Int.st undef, i64 %loop.count, 0
  %1 = tail call %Int.st @fib_Int(%Int.st %0)
  %2 = extractvalue %Int.st %1, 0
  tail call void @vist-Uprint_i64(i64 %2)
  %count.it = add nuw nsw i64 %loop.count, 1
  %exitcond = icmp eq i64 %count.it, 37
  br i1 %exitcond, label %loop.exit, label %loop

loop.exit:                                        ; preds = %loop
  ret void
}

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.ssub.with.overflow.i64(i64, i64) #1

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #2

; Function Attrs: nounwind readnone
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #1

; Function Attrs: noinline nounwind ssp uwtable
declare void @vist-Uprint_i64(i64) #3

attributes #0 = { nounwind }
attributes #1 = { nounwind readnone }
attributes #2 = { noreturn nounwind }
attributes #3 = { noinline nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
