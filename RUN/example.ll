; ModuleID = 'example_.ll'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.11.0"

@.str = private unnamed_addr constant [6 x i8] c"%llu\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

; Function Attrs: ssp uwtable
define void @print(i64 %i) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %i)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: ssp uwtable
define void @printd(double %d) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), double %d)
  ret void
}

; Function Attrs: ssp
define i64 @main() #2 {
entry:
  %backedge.overflow = icmp eq i64 100000000, -1
  %overflow.check.anchor = add i64 0, 0
  br i1 %backedge.overflow, label %scalar.ph, label %overflow.checked

overflow.checked:                                 ; preds = %entry
  br i1 false, label %middle.block, label %vector.ph

vector.ph:                                        ; preds = %overflow.checked
  br label %vector.body

vector.body:                                      ; preds = %vector.body, %vector.ph
  %index = phi i64 [ 0, %vector.ph ], [ %index.next, %vector.body ]
  %vec.phi = phi i64 [ 0, %vector.ph ], [ %predphi, %vector.body ]
  %vec.phi1 = phi i64 [ 0, %vector.ph ], [ %predphi3, %vector.body ]
  %induction = add i64 %index, 0
  %induction2 = add i64 %index, 1
  %0 = add i64 %induction, 1
  %1 = add i64 %induction2, 1
  %2 = urem i64 %induction, 3
  %3 = urem i64 %induction2, 3
  %4 = urem i64 %induction, 5
  %5 = urem i64 %induction2, 5
  %6 = icmp eq i64 %2, %4
  %7 = icmp eq i64 %3, %5
  %8 = add i64 %induction, %vec.phi
  %9 = add i64 %induction2, %vec.phi1
  %10 = or i1 false, %6
  %11 = or i1 false, %7
  %12 = select i1 %10, i64 %8, i64 %8
  %13 = select i1 %11, i64 %9, i64 %9
  %14 = xor i1 %6, true
  %15 = xor i1 %7, true
  %predphi = select i1 %14, i64 %vec.phi, i64 %12
  %predphi3 = select i1 %15, i64 %vec.phi1, i64 %13
  %16 = icmp slt i64 %0, 100000001
  %17 = icmp slt i64 %1, 100000001
  %index.next = add i64 %index, 2
  %18 = icmp eq i64 %index.next, 100000000
  br i1 %18, label %middle.block, label %vector.body, !llvm.loop !2

middle.block:                                     ; preds = %vector.body, %overflow.checked
  %resume.val = phi i64 [ 0, %overflow.checked ], [ 100000000, %vector.body ]
  %trunc.resume.val = phi i64 [ 0, %overflow.checked ], [ 100000000, %vector.body ]
  %rdx.vec.exit.phi = phi i64 [ 0, %overflow.checked ], [ %predphi, %vector.body ]
  %rdx.vec.exit.phi4 = phi i64 [ 0, %overflow.checked ], [ %predphi3, %vector.body ]
  %bin.rdx = add i64 %rdx.vec.exit.phi4, %rdx.vec.exit.phi
  %cmp.n = icmp eq i64 100000001, %resume.val
  br i1 %cmp.n, label %afterloop, label %scalar.ph

scalar.ph:                                        ; preds = %middle.block, %entry
  %bc.resume.val = phi i64 [ %resume.val, %middle.block ], [ 0, %entry ]
  %bc.trunc.resume.val = phi i64 [ %trunc.resume.val, %middle.block ], [ 0, %entry ]
  %bc.merge.rdx = phi i64 [ 0, %entry ], [ %bin.rdx, %middle.block ]
  br label %loop

loop:                                             ; preds = %cont, %scalar.ph
  %tot.0 = phi i64 [ %bc.merge.rdx, %scalar.ph ], [ %tot.1, %cont ]
  %i = phi i64 [ %bc.trunc.resume.val, %scalar.ph ], [ %nexti, %cont ]
  %nexti = add i64 %i, 1
  %rem_res = urem i64 %i, 3
  %rem_res1 = urem i64 %i, 5
  %cmp_eq_res = icmp eq i64 %rem_res, %rem_res1
  br i1 %cmp_eq_res, label %then0, label %cont

afterloop:                                        ; preds = %middle.block, %cont
  %tot.1.lcssa = phi i64 [ %tot.1, %cont ], [ %bin.rdx, %middle.block ]
  %19 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([6 x i8]* @.str, i64 0, i64 0), i64 %tot.1.lcssa)
  ret i64 0

cont:                                             ; preds = %then0, %loop
  %tot.1 = phi i64 [ %20, %then0 ], [ %tot.0, %loop ]
  %looptest = icmp slt i64 %nexti, 100000001
  br i1 %looptest, label %loop, label %afterloop, !llvm.loop !5

then0:                                            ; preds = %loop
  %20 = add i64 %i, %tot.0
  br label %cont
}

attributes #0 = { ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="core2" "target-features"="+ssse3,+cx16,+sse,+sse2,+sse3" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { ssp }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1}

!0 = !{!"Apple LLVM version 7.0.2 (clang-700.1.81)"}
!1 = !{i32 1, !"PIC Level", i32 2}
!2 = distinct !{!2, !3, !4}
!3 = !{!"llvm.loop.vectorize.width", i32 1}
!4 = !{!"llvm.loop.interleave.count", i32 1}
!5 = distinct !{!5, !3, !4}
